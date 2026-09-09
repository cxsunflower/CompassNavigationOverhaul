#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
独立校验 VR_HMD_info 版 QuestItemList.swf 确实是「路子 1」中和版，且只动了该动的两处。

与 patch_questitemlist_vr.py **不共用任何代码**：这里从两个 SWF 各自解出 body，
逐函数比对，断言——
  1) 补丁版是合法 CWS，解压后 body 长度 == 原版（长度保持）；
  2) 恰好 AddToHudElements、onEnterFrame 两个函数体被中和成
     `Push undefined; Return; Pop…` 的形状，且不再含 HudElements 常量引用的活代码；
  3) 除这两段函数体之外，body 的其余每一个字节都与原版逐字节相同
     （即 Compass/Update/ShowAllQuests/SetMaxHeight/AddQuest 等一概没动，常量池没动）。

用法：
    python3 tools/verify_questitemlist_vr.py \
        assets/source/questlist/QuestItemList.HUDMenu-original.swf \
        build/QuestItemList.VR-patched.swf
退出码 0 = 通过。
"""
import sys
import zlib
import struct

NEUTRAL_TARGETS = {"AddToHudElements", "onEnterFrame"}


def load_body(path):
    raw = open(path, "rb").read()
    if raw[:3] != b"CWS":
        raise SystemExit(f"{path}: 不是 zlib 压缩的 CWS SWF")
    total = struct.unpack_from("<I", raw, 4)[0]
    body = zlib.decompress(raw[8:])
    if 8 + len(body) != total:
        raise SystemExit(f"{path}: 解压后总长 {8+len(body)} != 文件头声明 {total}")
    return body


def parse_functions(body):
    """返回 {name: (code_start, codelen)}（仅主 DoAction 内的 DefineFunction/2），及 body 长度。"""
    def rdstr(d, q):
        e = d.index(b"\x00", q)
        return d[q:e].decode("latin1"), e + 1

    nbits = body[0] >> 3
    rect_bytes = (5 + nbits * 4 + 7) // 8
    p = rect_bytes + 4
    doaction = None
    while p < len(body):
        rh = struct.unpack_from("<H", body, p)[0]
        p += 2
        code = rh >> 6
        ln = rh & 0x3F
        if ln == 0x3F:
            ln = struct.unpack_from("<I", body, p)[0]
            p += 4
        if code == 12 and doaction is None:
            doaction = (p, ln)
        p += ln
    if not doaction:
        raise SystemExit("找不到主 DoAction")

    off, length = doaction
    end = off + length
    p = off
    funcs = {}
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
        if code in (0x8E, 0x9B):
            q = 0
            fname, q = rdstr(pl, q)
            if code == 0x8E:
                npar = struct.unpack_from("<H", pl, q)[0]
                q += 2
                q += 1
                q += 2
                for _ in range(npar):
                    q += 1
                    _, q = rdstr(pl, q)
            else:
                npar = struct.unpack_from("<H", pl, q)[0]
                q += 2
                for _ in range(npar):
                    _, q = rdstr(pl, q)
            clen = struct.unpack_from("<H", pl, q)[0]
            q += 2
            funcs[fname] = (p + ln, clen)
        p += ln
    return funcs


def main():
    if len(sys.argv) != 3:
        print(__doc__)
        sys.exit(2)
    orig_body = load_body(sys.argv[1])
    patched_body = load_body(sys.argv[2])

    ok = True

    def check(cond, msg):
        nonlocal ok
        print(("  [OK] " if cond else "  [FAIL] ") + msg)
        if not cond:
            ok = False

    print("A) 长度保持")
    check(len(orig_body) == len(patched_body),
          f"body 长度相同：{len(orig_body)} == {len(patched_body)}")

    of = parse_functions(orig_body)
    pf = parse_functions(patched_body)
    check(set(of) == set(pf), "函数集合一致（没有增删函数、常量池未错位）")

    print("B) 两个目标函数已中和")
    for name in NEUTRAL_TARGETS:
        if name not in pf:
            check(False, f"{name} 存在")
            continue
        cs, clen = pf[name]
        seg = patched_body[cs : cs + clen]
        head_ok = seg[:5] == bytes([0x96, 0x01, 0x00, 0x03, 0x3E])  # Push undef; Return
        pad_ok = all(b == 0x17 for b in seg[5:])  # 其余全是 Pop
        # 中和后不应还有 HudElements 常量的活引用（0x88 常量池在函数体外，这里只看 body 段）
        check(head_ok, f"{name}: 以 [Push undefined; Return] 开头")
        check(pad_ok, f"{name}: 其余 {clen-5} 字节均为 Pop 填充（不可达）")

    print("C) 其余字节逐字节未动")
    # 把两个中和段之外的所有字节抠出来比对
    holes = sorted(pf[n] for n in NEUTRAL_TARGETS if n in pf)
    mask = bytearray(orig_body)
    mask_p = bytearray(patched_body)
    for cs, clen in holes:
        # 用相同占位覆盖两侧的中和区，剩下的必须完全相等
        for i in range(cs, cs + clen):
            mask[i] = 0
            mask_p[i] = 0
    check(bytes(mask) == bytes(mask_p),
          "除两个中和段外，body 其余字节与原版逐字节相同")

    # 额外：确认没被中和的关键函数体确实原样保留
    print("D) 关键未动函数逐字节等同原版")
    for name in ("Update", "ShowAllQuests", "RemoveAllQuests", "SetMaxHeight", "AddQuest", "QuestItemList"):
        if name in of and name in pf:
            (ocs, ocl), (pcs, pcl) = of[name], pf[name]
            same = (ocl == pcl and orig_body[ocs:ocs+ocl] == patched_body[pcs:pcs+pcl])
            check(same, f"{name} 未改动")

    print()
    if ok:
        print("== 全部通过：这是一份只中和了 AddToHudElements+onEnterFrame 的合法补丁版 ==")
        sys.exit(0)
    else:
        print("== 有断言失败，见上 ==")
        sys.exit(1)


if __name__ == "__main__":
    main()
