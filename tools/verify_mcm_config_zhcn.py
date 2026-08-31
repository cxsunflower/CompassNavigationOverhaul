#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
独立校验简体中文版 config.json 与英文原版是否结构一致、翻译是否漏项。

**故意不复用 make_mcm_config_zhcn.py 的任何代码**：那个脚本是「字面替换」，
这个脚本走的是「解析成对象再逐字段比对」，两条完全不同的路径。生成器写错了
（漏译、把结构字段一起换掉、把 {N} 占位符译没了），这里才抓得住。

校验项：
  A. 编码与行尾：UTF-8 无 BOM、CRLF、与英文版行数相同
  B. JSON 合法，且键集合、嵌套形状逐层一致
  C. 不该动的字段逐字节相同：modName / displayName / customContent.source /
     每个 id / type / sourceType / min / max / step / position / cursorFillMode
  D. 18 个 id 齐全且无重复
  E. formatString 里的 {N} 占位符序列完全一致
  F. 该翻译的字段（pageDisplayName、header 的 text、控件的 text 与 help、
     stepper 的 options、formatString 的单位）确实变了、且含中日韩字符；
     英文原文里没有字母的（例如 "{2}"）允许保持原样
  G. 没有漏译的英文单词残留（只放行刻意保留的日志级别名）
  H. build/package 暂存区存在时，主包配置必须等于英文母本，汉化包配置必须等于中文母本

用法：
    python3 tools/verify_mcm_config_zhcn.py
退出码 0 = 全部通过。
"""

import json
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
# 语言母本是唯一事实来源；若构建暂存区存在，再校验其中的副本。
CFG_REL = pathlib.Path("MCM") / "Config" / "Compass Navigation Overhaul VR" / "config.json"
MCM_ASSET_DIR = ROOT / "assets" / "main" / CFG_REL.parent
EN = MCM_ASSET_DIR / "config.json"
ZH = MCM_ASSET_DIR / "config.zh-CN.json"
STAGE = ROOT / "build" / "package"
PKG = STAGE / "main" / CFG_REL
PKG_ZH = STAGE / "chs" / CFG_REL

# 刻意保留英文的词：日志级别名要和 CompassNavigationOverhaul.log 里的字样对得上
ALLOWED_ASCII_WORDS = {"Trace", "Debug", "Info", "Warning", "Error", "Critical"}

# 不允许翻译、必须逐字节相同的键
FROZEN_KEYS = {
    "modName", "displayName", "source", "id", "type", "sourceType",
    "min", "max", "step", "position", "cursorFillMode",
}
# 必须翻译（或至少「英文原文里没有字母」）的键
PROSE_KEYS = {"pageDisplayName", "text", "help"}

WORD = re.compile(r"[A-Za-z]{3,}")
PLACEHOLDER = re.compile(r"\{\d+\}")


def has_cjk(s: str) -> bool:
    """含中日韩表意文字、中文标点或全角符号，就算已经翻译过了。

    用码位区间判断而不是写正则字符类，免得源文件本身的编码出岔子：
    0x3000-0x303F 中文标点（、。「」），0x4E00-0x9FFF 汉字，0xFF00-0xFFEF 全角。
    """
    return any(
        0x3000 <= ord(c) <= 0x303F or 0x4E00 <= ord(c) <= 0x9FFF or 0xFF00 <= ord(c) <= 0xFFEF
        for c in s
    )

errors: "list[str]" = []
checked = {"frozen": 0, "prose": 0, "options": 0, "format": 0}

def fail(msg: str) -> None:
    errors.append(msg)


def load(path: pathlib.Path, label: str) -> str:
    """A 项：编码与行尾。返回原始文本（保留 CRLF）。"""
    raw = path.read_bytes()
    if raw.startswith(b"\xef\xbb\xbf"):
        fail(f"{label}: 带 UTF-8 BOM，MCM Helper 的 JSON 解析器不一定吃得下")
    try:
        text = raw.decode("utf-8")
    except UnicodeDecodeError as exc:
        fail(f"{label}: 不是合法 UTF-8（{exc}）")
        return ""
    crlf = raw.count(b"\r\n")
    lone_lf = raw.count(b"\n") - crlf
    if lone_lf:
        fail(f"{label}: 有 {lone_lf} 处裸 LF，与英文原版的 CRLF 不一致")
    return text


def walk(en, zh, path: str) -> None:
    """B/C/F 项：逐层比对形状，并按键名分流到「冻结」与「文案」两套规则。"""
    if type(en) is not type(zh):
        fail(f"{path}: 类型不同（英 {type(en).__name__} / 中 {type(zh).__name__}）")
        return
    if isinstance(en, dict):
        if en.keys() != zh.keys():
            only_en = sorted(en.keys() - zh.keys())
            only_zh = sorted(zh.keys() - en.keys())
            fail(f"{path}: 键集合不同（英独有 {only_en} / 中独有 {only_zh}）")
            return
        for key in en:
            child = f"{path}.{key}"
            if key in FROZEN_KEYS:
                checked["frozen"] += 1
                if en[key] != zh[key]:
                    fail(f"{child}: 不该翻译的字段被改了（{en[key]!r} → {zh[key]!r}）")
            elif key in PROSE_KEYS and isinstance(en[key], str):
                check_prose(en[key], zh[key], child)
            elif key == "options":
                check_options(en[key], zh[key], child)
            elif key == "formatString":
                check_format(en[key], zh[key], child)
            else:
                walk(en[key], zh[key], child)
    elif isinstance(en, list):
        if len(en) != len(zh):
            fail(f"{path}: 元素个数不同（英 {len(en)} / 中 {len(zh)}）")
            return
        for i, (a, b) in enumerate(zip(en, zh)):
            walk(a, b, f"{path}[{i}]")
    elif en != zh:
        fail(f"{path}: 值不同（{en!r} → {zh!r}）")


def check_prose(en: str, zh: str, path: str) -> None:
    """F/G 项：该译的必须译了，且不留漏译的英文单词。"""
    checked["prose"] += 1
    if not WORD.search(en):
        # 英文原文里根本没有单词（纯符号/数字），保持原样才是对的
        if en != zh:
            fail(f"{path}: 原文没有可译内容却被改动了（{en!r} → {zh!r}）")
        return
    if en == zh:
        fail(f"{path}: 漏译，仍是英文原文（{en!r}）")
        return
    if not has_cjk(zh):
        fail(f"{path}: 译文里没有一个中文字符（{zh!r}）")
    leftovers = [w for w in WORD.findall(zh) if w not in ALLOWED_ASCII_WORDS]
    if leftovers:
        fail(f"{path}: 译文里残留英文单词 {leftovers}（{zh!r}）")
    # 换行符是 SkyUI 分行用的，数量必须一致，否则 help 气泡排版会变
    if en.count("\n") != zh.count("\n"):
        fail(f"{path}: 换行数不同（英 {en.count(chr(10))} / 中 {zh.count(chr(10))}）")


def check_options(en, zh, path: str) -> None:
    """stepper 的选项：个数必须一致，逐项都要译。"""
    checked["options"] += 1
    if not isinstance(en, list) or not isinstance(zh, list):
        fail(f"{path}: options 不是数组")
        return
    if len(en) != len(zh):
        fail(f"{path}: 选项个数不同（英 {len(en)} / 中 {len(zh)}）—— 会和底层取值错位")
        return
    for i, (a, b) in enumerate(zip(en, zh)):
        check_prose(a, b, f"{path}[{i}]")


def check_format(en: str, zh: str, path: str) -> None:
    """E 项：{N} 占位符序列必须一字不差，单位词可以译。"""
    checked["format"] += 1
    if PLACEHOLDER.findall(en) != PLACEHOLDER.findall(zh):
        fail(f"{path}: 占位符序列变了（{en!r} → {zh!r}）—— 滑块会显示不出数值")
    if WORD.search(en) and not has_cjk(zh):
        fail(f"{path}: 单位没译（{en!r}）")


def check_ids(en: dict, zh: dict) -> None:
    """D 项：18 个 id 齐全、无重复、两边一致。"""
    def collect(doc: dict) -> "list[str]":
        out = []
        for page in doc.get("pages", []):
            for item in page.get("content", []):
                if "id" in item:
                    out.append(item["id"])
        return out

    en_ids, zh_ids = collect(en), collect(zh)
    if en_ids != zh_ids:
        fail(f"id 序列不同：英 {en_ids} / 中 {zh_ids}")
    if len(set(zh_ids)) != len(zh_ids):
        dup = sorted({i for i in zh_ids if zh_ids.count(i) > 1})
        fail(f"id 有重复：{dup}")
    if len(zh_ids) != 18:
        fail(f"id 个数是 {len(zh_ids)}，应为 18（对应 Settings.h 里的 18 个键）")


def check_packaged() -> str:
    """H 项：暂存区存在时，其中的副本必须逐字节等于对应母本。

    主包固定英文、汉化包固定中文（汉化包是覆盖式 mod，装在主包之后才生效）。
    最容易出的岔子是「改了母本忘了重新打包」「copy 了一半」「copy 完又手改了一行」，
    以及把中文 copy 进主包导致汉化包变成同语言覆盖。用字节比较而不是解析比较，
    是因为这里要抓的正是「内容看起来对但不完全一样」这种情况。
    返回给末尾摘要用的一行说明。
    """
    if not STAGE.exists():
        return "暂存区尚未生成，已跳过"

    notes = []
    for label, path, master, master_name in (
        ("主包", PKG, EN, "assets/main/MCM/Config/Compass Navigation Overhaul VR/config.json"),
        ("汉化包", PKG_ZH, ZH, "assets/main/MCM/Config/Compass Navigation Overhaul VR/config.zh-CN.json"),
    ):
        if not path.is_file():
            fail(f"{label}里没有 config.json：{path} —— 打包会缺菜单描述文件")
            notes.append(f"{label} 缺失")
            continue
        if path.read_bytes() == master.read_bytes():
            notes.append(f"{label} = {master_name}")
            continue
        other = ZH if master is EN else EN
        hint = (
            "装的其实是另一种语言的母本 —— build.bat 会无条件 copy 回来，重新打包即可"
            if path.read_bytes() == other.read_bytes()
            else "要么复制不完整，要么暂存文件被修改；文案应修改 MCM 资源目录里的母本"
        )
        fail(f"{label}那份 config.json 与 {master_name} 不逐字节相同：{path}\n        {hint}")
        notes.append(f"{label} 对不上 {master_name}")
    return "；".join(notes)


def main() -> int:
    for path in (EN, ZH):
        if not path.is_file():
            print(f"[错误] 找不到 {path}", file=sys.stderr)
            return 2

    en_text = load(EN, "英文版")
    zh_text = load(ZH, "中文版")
    if not en_text or not zh_text:
        for e in errors:
            print(f"[失败] {e}", file=sys.stderr)
        return 1

    packaged = check_packaged()

    en_lines, zh_lines = en_text.count("\n"), zh_text.count("\n")
    if en_lines != zh_lines:
        fail(f"行数不同（英 {en_lines + 1} / 中 {zh_lines + 1}）—— 生成器动了结构")

    try:
        en_doc = json.loads(en_text)
    except json.JSONDecodeError as exc:
        fail(f"英文版不是合法 JSON：{exc}")
        en_doc = None
    try:
        zh_doc = json.loads(zh_text)
    except json.JSONDecodeError as exc:
        fail(f"中文版不是合法 JSON：{exc}")
        zh_doc = None

    if en_doc is not None and zh_doc is not None:
        walk(en_doc, zh_doc, "$")
        check_ids(en_doc, zh_doc)
        # modName 和 displayName 不参与翻译。
        if zh_doc.get("displayName") != "Compass Navigation Overhaul VR":
            fail(f'displayName 必须保持 "Compass Navigation Overhaul VR"，实际是 {zh_doc.get("displayName")!r}')
        if zh_doc.get("modName") != "Compass Navigation Overhaul VR":
            fail(f'modName 必须等于 esp 文件名主干，实际是 {zh_doc.get("modName")!r}')

    if errors:
        for e in errors:
            print(f"[失败] {e}", file=sys.stderr)
        print(f"\n共 {len(errors)} 处问题。", file=sys.stderr)
        return 1

    print("[通过] 中文版 config.json 与英文原版结构完全一致，翻译无漏项。")
    print(f"       冻结字段 {checked['frozen']} 处逐字节相同")
    print(f"       文案字段 {checked['prose']} 处（含 options 逐项）已译且无英文残留")
    print(f"       {checked['options']} 个 stepper 选项数组、{checked['format']} 个 formatString 占位符一致")
    print(f"       18 个 id、type、sourceType、min/max/step 一律未改动")
    print(f"       构建暂存副本：{packaged}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
