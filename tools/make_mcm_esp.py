# -*- coding: utf-8 -*-
"""生成包含 Start-Game-Enabled Quest 和 MCM_ConfigBase 的最小 MCM ESP。

插件文件名必须与 MCM Config 目录和 config.json 的 modName 完全一致。
"""

import struct
import sys
from pathlib import Path

# 插件参数
PLUGIN_NAME = "Compass Navigation Overhaul VR.esp"  # 必须与 MCM/Config/<modName>/ 的目录名对应
QUEST_EDID = "CNO_MCMConfigQuest"
SCRIPT_NAME = "MCM_ConfigBase"                  # MCM Helper 自带，直接挂即可
AUTHOR = "alexsylex (VR port)"
MASTERS = ["Skyrim.esm"]                        # 只依赖主文件；索引 0x00
QUEST_OBJECT_ID = 0x000800                      # 与 Palm Compass 参照物一致，避开 0x000-0x7FF 保留区
HEDR_VERSION = 1.71                             # SSE/VR 的 esp 版本号
FORM_VERSION = 44                               # SSE/VR 记录格式版本

# QUST DNAM 的 flags 位（UESP）：0x0001 Start Game Enabled、0x0100 Run Once。
# 参照物 Palm Compass 只置了 0x0001，SkyUI 用 0x0111；取前者，最小可用。
QUEST_FLAGS = 0x0001
QUEST_PRIORITY = 0
QUEST_TYPE = 0                                  # 0 = None（不进任务日志）


def zstring(s: str) -> bytes:
    """记录里的字符串一律是 latin-1 + NUL 结尾。"""
    return s.encode("latin-1") + b"\x00"


def field(tag: str, data: bytes) -> bytes:
    """子字段 = 4 字节标签 + uint16 长度 + 数据。"""
    assert len(tag) == 4
    assert len(data) <= 0xFFFF, f"{tag} 超过 uint16 长度上限"
    return tag.encode("ascii") + struct.pack("<H", len(data)) + data


def record(tag: str, data: bytes, form_id: int, flags: int = 0) -> bytes:
    """记录头 24 字节：标签、数据长度、flags、formID、vcInfo1、formVersion、vcInfo2。
    注意 dataSize **不含** 这 24 字节头（GRUP 才含）。"""
    assert len(tag) == 4
    head = struct.pack(
        "<4sIIIIHH",
        tag.encode("ascii"),
        len(data),
        flags,
        form_id,
        0,               # vcInfo1（上次修改信息，置 0）
        FORM_VERSION,
        0,               # vcInfo2
    )
    return head + data


def group(label: str, data: bytes, group_type: int = 0) -> bytes:
    """顶层 GRUP：size **包含** 自身 24 字节头，这一点与 record 相反，是最容易写错的地方。"""
    assert len(label) == 4
    head = struct.pack(
        "<4sI4sIHHI",
        b"GRUP",
        24 + len(data),
        label.encode("ascii"),
        group_type,
        0,   # timestamp
        0,   # vcInfo
        0,   # unknown
    )
    return head + data


def build_vmad(script_name: str) -> bytes:
    """QUST 的 VMAD（脚本挂载）。0 个属性的最简形态。
    布局（version=5 / objFormat=2）：
      int16 version=5, int16 objFormat=2, int16 scriptCount,
      每条脚本：uint16 名字长度 + 名字（无 NUL）+ uint8 status + uint16 属性个数
    QUST 的 VMAD 还有 fragment 部分，但脚本数>0、无 fragment 时可以整块省略
    —— 参照物 PalmCompassVR MCM.esp 正是这么写的（VMAD 总长 28 字节）。"""
    name = script_name.encode("latin-1")
    return (
        struct.pack("<hhh", 5, 2, 1)
        + struct.pack("<H", len(name))
        + name
        + struct.pack("<B", 0)   # status：0 = 本地脚本
        + struct.pack("<H", 0)   # 属性个数：0，所以后面什么都没有
    )


def build_quest(form_id: int) -> bytes:
    data = b"".join([
        field("EDID", zstring(QUEST_EDID)),
        field("VMAD", build_vmad(SCRIPT_NAME)),
        field("DNAM", struct.pack(
            "<HBbii",
            QUEST_FLAGS,
            QUEST_PRIORITY,
            -1,          # unused，参照物写的是 0xFF
            0,           # unknown（CK 一直写 0）
            QUEST_TYPE,
        )),
        field("NEXT", b""),               # 阶段/目标列表的分隔符，空 quest 也要有
        field("ANAM", struct.pack("<I", 0)),  # 下一个 alias id；没有 alias 就是 0
    ])
    return record("QUST", data, form_id)


def build_plugin() -> bytes:
    quest_grup = group("QUST", build_quest(mod_index_form_id(QUEST_OBJECT_ID)))

    # HEDR 的 numRecords 统计「TES4 之后的记录数」，GRUP 也算一个。
    # 参照物：1 条 QUST + 1 个 GRUP → 2。
    hedr = struct.pack("<fiI", HEDR_VERSION, 2, QUEST_OBJECT_ID + 1)

    tes4_data = [field("HEDR", hedr), field("CNAM", zstring(AUTHOR))]
    for master in MASTERS:
        tes4_data.append(field("MAST", zstring(master)))
        tes4_data.append(field("DATA", struct.pack("<Q", 0)))

    return record("TES4", b"".join(tes4_data), 0) + quest_grup


def mod_index_form_id(object_id: int) -> int:
    """自身记录的 formID 高字节 = master 数量（指向「本插件」这一格）。
    只挂 Skyrim.esm 时是 0x01；参照物挂了两个 master 所以是 0x02。"""
    return (len(MASTERS) << 24) | object_id


def main() -> int:
    out_dir = Path(sys.argv[1]) if len(sys.argv) > 1 else Path(".")
    out_dir.mkdir(parents=True, exist_ok=True)
    out_path = out_dir / PLUGIN_NAME

    blob = build_plugin()
    out_path.write_bytes(blob)

    print(f"已写出 {out_path}（{len(blob)} 字节）")
    print(f"  QUST formID = 0x{mod_index_form_id(QUEST_OBJECT_ID):08X}"
          f"，EDID = {QUEST_EDID}，脚本 = {SCRIPT_NAME}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
