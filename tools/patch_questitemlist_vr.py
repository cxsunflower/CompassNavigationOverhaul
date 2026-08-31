#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""中和 QuestItemList.swf 对 HUDMenu.HudElements 的引用，使其可用于 VR_HMD_info。

仅原地替换 AddToHudElements 与 onEnterFrame 的函数体，保持字节码长度和跳转偏移；
HUDMenu 原文件不变。输出由 tools/verify_questitemlist_vr.py 独立校验。
"""
import sys
import zlib
import struct
import hashlib

# 期望输入：2.9.9 原版 HUDMenu QuestItemList.swf
EXPECTED_INPUT_MD5 = "f2e7f1c71658bcc8a005261891392aeb"
# 期望输出：本工程已实测铺进两棵树的补丁版
EXPECTED_OUTPUT_MD5 = "db74017bec983b94d0ff41098b98fa7c"

# 固定长度是补丁安全边界，上游结构变化时必须失败。
TARGETS = {
    "AddToHudElements": 32,
    "onEnterFrame": 124,
}
NEUTRAL_HEAD = bytes([0x96, 0x01, 0x00, 0x03, 0x3e])  # Push undefined; Return
PAD = 0x17  # Pop


def rdstr(d, q):
    e = d.index(b"\x00", q)
    return d[q:e].decode("latin1"), e + 1


def find_doaction(body):
    """定位主时间轴那条 DoAction(code 12) 的 payload 区间 [off, off+len)。"""
    nbits = body[0] >> 3
    rect_bytes = (5 + nbits * 4 + 7) // 8
    p = rect_bytes + 4  # + frameRate(2) + frameCount(2)
    while p < len(body):
        rh = struct.unpack_from("<H", body, p)[0]
        p += 2
        code = rh >> 6
        ln = rh & 0x3F
        if ln == 0x3F:
            ln = struct.unpack_from("<I", body, p)[0]
            p += 4
        if code == 12:
            return p, ln
        p += ln
    raise RuntimeError("找不到主 DoAction (tag code 12)")


def enumerate_functions(body, off, length):
    """
    走 DoAction 字节码，返回每个 DefineFunction2 的
    (name, code_body_start, codelen, preceding_push_c_indices)。
    同时解出常量池，供按 HudElements 常量索引识别 onEnterFrame。
    """
    end = off + length
    p = off
    cpool = []
    funcs = []
    last_push_cidx = []  # 最近一次 Push 里引用到的常量索引（供匿名函数打标签用，暂未使用）
    while p < end:
        code = body[p]
        p += 1
        if code == 0:
            break
        if code < 0x80:
            continue
        ln = struct.unpack_from("<H", body, p)[0]
        p += 2
        pl = body[p : p + ln]
        if code == 0x88:  # ConstantPool
            cnt = struct.unpack_from("<H", pl, 0)[0]
            q = 2
            cp = []
            for _ in range(cnt):
                s, q = rdstr(pl, q)
                cp.append(s)
            cpool = cp
        elif code == 0x8E:  # DefineFunction2
            q = 0
            fname, q = rdstr(pl, q)
            npar = struct.unpack_from("<H", pl, q)[0]
            q += 2
            q += 1  # regcount
            q += 2  # flags
            for _ in range(npar):
                q += 1  # reg
                _, q = rdstr(pl, q)
            clen = struct.unpack_from("<H", pl, q)[0]
            q += 2
            code_start = p + ln  # 函数体紧跟在 DefineFunction2 payload 之后
            funcs.append([fname, code_start, clen])
        p += ln
    return cpool, funcs


def neutralize(body, code_start, codelen):
    if codelen < len(NEUTRAL_HEAD):
        raise RuntimeError("函数体太短，无法中和：codelen=%d" % codelen)
    patch = bytearray(body[code_start : code_start + codelen])
    patch[: len(NEUTRAL_HEAD)] = NEUTRAL_HEAD
    for i in range(len(NEUTRAL_HEAD), codelen):
        patch[i] = PAD
    body[code_start : code_start + codelen] = patch


def body_refs_hudelements(body, cpool, code_start, codelen):
    """判定一段函数体是否引用了 HudElements 常量（用来认出匿名 onEnterFrame）。"""
    try:
        idx = cpool.index("HudElements")
    except ValueError:
        return False
    seg = body[code_start : code_start + codelen]
    # Push 常量 8/9 型：0x96 ... 08 <idx> 或 09 <idx16>
    return bytes([0x08, idx]) in seg or bytes([0x09]) + struct.pack("<H", idx) in seg


def main():
    if len(sys.argv) != 3:
        print(__doc__)
        sys.exit(2)
    src, dst = sys.argv[1], sys.argv[2]

    raw = open(src, "rb").read()
    got_in = hashlib.md5(raw).hexdigest()
    if got_in != EXPECTED_INPUT_MD5:
        print(f"[警告] 输入 md5={got_in}，与期望 {EXPECTED_INPUT_MD5} 不符 —— "
              f"若上游换了 SWF，请人工复核补丁点后再更新本脚本的断言。")

    assert raw[:3] == b"CWS", "只支持 zlib 压缩的 CWS SWF"
    ver = raw[3]
    declared_total = struct.unpack_from("<I", raw, 4)[0]
    body = bytearray(zlib.decompress(raw[8:]))
    assert 8 + len(body) == declared_total, "解压后总长与文件头不符"

    off, length = find_doaction(body)
    cpool, funcs = enumerate_functions(body, off, length)

    patched_names = []
    remaining = dict(TARGETS)
    for fname, cs, clen in funcs:
        if fname in remaining:
            expect = remaining.pop(fname)
            if clen != expect:
                raise RuntimeError(f"{fname} codelen={clen}，期望 {expect} —— 上游结构变了，停止")
            if not body_refs_hudelements(body, cpool, cs, clen):
                raise RuntimeError(f"{fname} 未引用 HudElements —— 认错了函数，停止")
            neutralize(body, cs, clen)
            patched_names.append(f"{fname}(codelen={clen})")
    if remaining:
        raise RuntimeError(f"没找到这些目标函数：{list(remaining)} —— 上游可能改名/改结构，停止")

    # 重压：长度未变，declared_total 不变
    assert 8 + len(body) == declared_total, "补丁改变了 body 长度（不应发生）"
    comp = zlib.compress(bytes(body), 9)
    out = b"CWS" + bytes([ver]) + struct.pack("<I", declared_total) + comp

    # roundtrip 自检
    assert zlib.decompress(out[8:]) == bytes(body), "zlib roundtrip 失败"

    open(dst, "wb").write(out)
    got_out = hashlib.md5(out).hexdigest()
    print("已中和：", ", ".join(patched_names))
    print(f"输出 {dst}")
    print(f"  body 长度 {len(body)}（未变），压缩后 {len(out)} 字节，md5 {got_out}")
    if got_out == EXPECTED_OUTPUT_MD5:
        print(f"  == 与已铺入两棵树的补丁版逐字节一致（{EXPECTED_OUTPUT_MD5}）")
    else:
        print(f"  [注意] 与期望 {EXPECTED_OUTPUT_MD5} 不一致（zlib 实现/等级差异也可能导致，"
              f"以 verify_questitemlist_vr.py 的语义校验为准）")


if __name__ == "__main__":
    main()
