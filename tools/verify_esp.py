# -*- coding: utf-8 -*-
"""
独立解析器：把一个 esp/esm/esl 全量拆开并检查自洽性。

写它的目的不是「通用 xEdit」，而是**不复用生成器的任何代码**去验证
make_mcm_esp.py 的产物：长度字段、GRUP 边界、formID 的 mod index、VMAD 内部长度
如果有一处算错，这里就会报出来。同时可以拿它去 dump 参照 esp 做结构对比。

用法：
    python3 verify_esp.py <文件> [<参照文件>]
"""

import struct
import sys
from pathlib import Path

PROBLEMS: list[str] = []


def problem(msg: str) -> None:
    PROBLEMS.append(msg)
    print(f"  [问题] {msg}")


def parse_fields(data: bytes, ctx: str) -> list[tuple[str, bytes]]:
    """把记录数据段切成子字段，顺便检查「刚好切完」。"""
    out = []
    i = 0
    while i < len(data):
        if i + 6 > len(data):
            problem(f"{ctx}: 尾部残留 {len(data) - i} 字节，不足一个子字段头")
            break
        tag = data[i:i + 4].decode("latin-1")
        size = struct.unpack_from("<H", data, i + 4)[0]
        if i + 6 + size > len(data):
            problem(f"{ctx}: 子字段 {tag} 声明 {size} 字节但只剩 {len(data) - i - 6}")
            break
        out.append((tag, data[i + 6:i + 6 + size]))
        i += 6 + size
    return out


def describe_vmad(fd: bytes, ctx: str) -> str:
    ver, fmt, cnt = struct.unpack_from("<hhh", fd, 0)
    if ver != 5 or fmt != 2:
        problem(f"{ctx}: VMAD version/objFormat = {ver}/{fmt}，SSE/VR 应为 5/2")
    pos = 6
    names = []
    for _ in range(cnt):
        n = struct.unpack_from("<H", fd, pos)[0]
        name = fd[pos + 2:pos + 2 + n].decode("latin-1")
        status = fd[pos + 2 + n]
        nprops = struct.unpack_from("<H", fd, pos + 3 + n)[0]
        names.append(f"{name}(status={status},props={nprops})")
        if nprops:
            problem(f"{ctx}: VMAD 有 {nprops} 个属性，本解析器只支持 0 属性的最简形态")
        pos += 5 + n
    if pos != len(fd):
        problem(f"{ctx}: VMAD 解析完停在 {pos}，但字段长 {len(fd)}（多出的通常是 fragment）")
    return f"v{ver} fmt{fmt} scripts={cnt} " + ", ".join(names)


def walk(b: bytes, off: int, end: int, n_masters: int, depth: int = 0) -> int:
    """返回该区间内的「记录 + GRUP」个数，用于核对 HEDR.numRecords。"""
    count = 0
    pad = "  " * (depth + 1)
    while off < end:
        tag = b[off:off + 4].decode("latin-1")
        size = struct.unpack_from("<I", b, off + 4)[0]
        if tag == "GRUP":
            label = b[off + 8:off + 12].decode("latin-1")
            gtype = struct.unpack_from("<I", b, off + 12)[0]
            print(f"{pad}GRUP {label!r} type={gtype} size={size}（含 24 字节头）")
            if off + size > end:
                problem(f"GRUP {label} 越界：{off}+{size} > {end}")
                return count
            count += 1 + walk(b, off + 24, off + size, n_masters, depth + 1)
            off += size
        else:
            flags = struct.unpack_from("<I", b, off + 8)[0]
            form_id = struct.unpack_from("<I", b, off + 12)[0]
            form_ver = struct.unpack_from("<H", b, off + 20)[0]
            print(f"{pad}{tag} formID={form_id:08X} flags={flags:08X} "
                  f"dataSize={size} formVersion={form_ver}")
            if flags & 0x00040000:
                problem(f"{tag} 被标记为压缩，本解析器不解压")
            mod_index = form_id >> 24
            if mod_index != n_masters:
                problem(f"{tag} formID 的 mod index = 0x{mod_index:02X}，"
                        f"但 master 数是 {n_masters}，自身记录应当是 0x{n_masters:02X}")
            if form_ver != 44:
                problem(f"{tag} formVersion = {form_ver}，SSE/VR 应为 44")
            for ftag, fd in parse_fields(b[off + 24:off + 24 + size], f"{tag}.{form_id:08X}"):
                if ftag == "EDID":
                    print(f"{pad}   EDID = {fd[:-1].decode('latin-1')!r}")
                    if fd[-1] != 0:
                        problem(f"{tag}: EDID 没有 NUL 结尾")
                elif ftag == "VMAD":
                    print(f"{pad}   VMAD = {describe_vmad(fd, tag)}")
                elif ftag == "DNAM" and tag == "QUST" and len(fd) == 12:
                    qflags, prio, unused, unk, qtype = struct.unpack("<HBbii", fd)
                    print(f"{pad}   DNAM flags=0x{qflags:04X}"
                          f"（StartGameEnabled={'是' if qflags & 1 else '否'}）"
                          f" prio={prio} unused={unused} unk={unk} type={qtype}")
                    if not qflags & 1:
                        problem("QUST 没有置 Start Game Enabled(0x0001)，MCM 页面不会注册")
                else:
                    print(f"{pad}   {ftag} len={len(fd)}")
            off += 24 + size
            count += 1
    return count


def inspect(path: Path) -> None:
    b = path.read_bytes()
    print(f"=== {path.name}（{len(b)} 字节）===")
    if b[:4] != b"TES4":
        problem("开头不是 TES4")
        return
    tes4_size = struct.unpack_from("<I", b, 4)[0]
    tes4_flags = struct.unpack_from("<I", b, 8)[0]
    print(f"  TES4 dataSize={tes4_size} flags={tes4_flags:08X}"
          f"（ESM={'是' if tes4_flags & 0x01 else '否'}，"
          f"ESL={'是' if tes4_flags & 0x200 else '否'}）")

    masters = []
    for ftag, fd in parse_fields(b[24:24 + tes4_size], "TES4"):
        if ftag == "HEDR":
            ver, num_records, next_id = struct.unpack("<fiI", fd)
            print(f"  HEDR version={ver:.2f} numRecords={num_records} nextObjectID=0x{next_id:06X}")
        elif ftag == "MAST":
            masters.append(fd[:-1].decode("latin-1"))
        elif ftag == "DATA":
            pass
        else:
            print(f"  {ftag} = {fd[:60]!r}")
    print(f"  masters = {masters}")

    actual = walk(b, 24 + tes4_size, len(b), len(masters))
    print(f"  实际记录+GRUP 数 = {actual}")
    if actual != num_records:
        problem(f"HEDR.numRecords={num_records} 与实际 {actual} 不符")


def main() -> int:
    for arg in sys.argv[1:]:
        inspect(Path(arg))
        print()
    if PROBLEMS:
        print(f"共 {len(PROBLEMS)} 个问题")
        return 1
    print("全部检查通过")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
