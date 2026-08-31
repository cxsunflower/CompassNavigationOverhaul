#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""以带次数断言的字面替换生成中文 MCM 配置，并保留原 JSON 格式与换行。"""

import pathlib
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
# 英文 config.json 与中文母本放在同一 MCM 资源目录。
MCM_CONFIG = ROOT / "assets" / "main" / "MCM" / "Config" / "Compass Navigation Overhaul VR"
SRC = MCM_CONFIG / "config.json"
DST = MCM_CONFIG / "config.zh-CN.json"

# modName 必须匹配 ESP 主干；结构字段、占位符和度数符号均不得翻译。
RULES: "list[tuple[str, str, int]]" = []

# 页名
RULES += [
    ('"pageDisplayName": "Compass",', '"pageDisplayName": "罗盘",', 1),
    ('"pageDisplayName": "Quest List",', '"pageDisplayName": "任务列表",', 1),
    ('"pageDisplayName": "Debug",', '"pageDisplayName": "调试",', 1),
]

# 分组标题；保留上游用于排版的尾部空格。
RULES += [
    ('"text": "Markers ",', '"text": "标记 ",', 1),
    ('"text": "Control ",', '"text": "控制 ",', 1),
    ('"text": "Markers Extra Info",', '"text": "标记附加信息",', 1),
    ('"text": "Display ",', '"text": "显示 ",', 1),
]

# 罗盘页
RULES += [
    ('"text": "Undiscovered Locations",', '"text": "未发现的地点",', 1),
    ('"help": "Select how undiscovered map markers are displayed.\\nDefault: Hidden",',
     '"help": "选择未发现的地图标记如何显示。\\n默认：隐藏",', 1),
    ('"options": [ "Hidden", "\\"?\\" Marker", "Normal Marker" ],',
     '"options": [ "隐藏", "「?」图标", "原本图标" ],', 1),

    ('"text": "Show Enemies",', '"text": "显示敌人",', 1),
    ('"help": "Default: Enabled",', '"help": "默认：开启",', 1),

    ('"text": "Show through Portals",', '"text": "透过传送门显示",', 1),
    ('"help": "Shows location and enemies through portals, for example cities, from the outside.\\nDefault: Enabled",',
     '"help": "在外面时，透过传送门（例如城市入口）显示里面的地点与敌人。\\n默认：开启",', 1),

    ('"text": "Start Cone of Vision",', '"text": "视锥起始角度",', 1),
    ('"help": "Angle to the compass center to start showing marker details.\\nDefault: 10º",',
     '"help": "标记与罗盘中心的夹角小于该值时，开始显示标记详情。\\n默认：10º",', 1),

    ('"text": "Stop Cone of Vision",', '"text": "视锥保持角度",', 1),
    ('"help": "Angle to the compass center to stop showing marker details once shown.\\nDefault: 35º",',
     '"help": "标记详情已经显示后，夹角超过该值才停止显示。\\n默认：35º",', 1),

    ('"text": "Cone of Vision Delay",', '"text": "视锥延迟",', 1),
    ('"help": "Delay to show the centered marker details.\\nDefault: 0.1 s",',
     '"help": "标记进入罗盘中心后，延迟多久显示详情。\\n默认：0.1 秒",', 1),
    ('"formatString": "{2} s",', '"formatString": "{2} 秒",', 1),

    ('"text": "Show Undiscovered Location Info",', '"text": "显示未发现地点的信息",', 1),
    ('"help": "Hide/show distance and name for undiscovered location markers.\\nDefault: Disabled",',
     '"help": "是否为未发现的地点标记显示名称与距离。\\n默认：关闭",', 1),

    ('"text": "Show Enemy Names",', '"text": "显示敌人名称",', 1),
    ('"help": "Show enemy name under the compass enemy marker when not in direct combat.\\nDefault: Enabled",',
     '"help": "不在直接战斗中时，在罗盘的敌人标记下方显示敌人名称。\\n默认：开启",', 1),
]

RULES += [
    ('"text": "Units",', '"text": "距离单位",', 1),
    ('"help": "Use metric or imperial units.\\nDefault: Metric",',
     '"help": "距离使用公制还是英制单位。\\n默认：公制",', 1),
    ('"options": [ "Imperial", "Metric" ],', '"options": [ "英制", "公制" ],', 1),

    ('"text": "Quest Info Displayed",', '"text": "任务信息显示内容",', 1),
    ('"help": "Changes the text under the compass quest marker to show the location or the objective.\\nDefault: Objective",',
     '"help": "罗盘任务标记下方的文字显示地点还是任务目标。\\n默认：任务目标",', 1),
    ('"options": [ "Location", "Objective" ],', '"options": [ "地点", "任务目标" ],', 1),

    ('"text": "Show Additional Objectives Count",', '"text": "显示其余目标数量",', 1),
    ('"help": "Adds the number of objectives to the text under the compass quest marker.\\nDefault: Enabled",',
     '"help": "在罗盘任务标记下方的文字后面追加目标数量，形如 (+2)。\\n默认：开启",', 1),
]

# 任务列表页
RULES += [
    ('"text": "X Offset",', '"text": "横向偏移",', 1),
    ('"help": "Horizontal offset of the quest list. Wide-screen users might want to set this negative or greater than 1 (in screen width proportion).\\nDefault: 0.01",',
     '"help": "任务列表的横向偏移，单位是屏幕宽度的比例。宽屏用户可能需要设成负数或大于 1。\\n默认：0.01",', 1),

    ('"text": "Y Offset",', '"text": "纵向偏移",', 1),
    ('"help": "Vertical offset of the quest list.\\nDefault: 0.15",',
     '"help": "任务列表的纵向偏移，单位是屏幕高度的比例。\\n默认：0.15",', 1),

    ('"text": "Max Height",', '"text": "最大高度",', 1),
    ('"help": "Maximum height of the quest list.\\nDefault: 0.67",',
     '"help": "任务列表的最大高度，单位是屏幕高度的比例。\\n默认：0.67",', 1),

    ('"text": "Show in Exteriors",', '"text": "室外显示",', 1),
    ('"help": "Show the quest list in exteriors.\\nDefault: Enabled",',
     '"help": "在室外显示任务列表。\\n默认：开启",', 1),

    ('"text": "Show in Interiors",', '"text": "室内显示",', 1),
    ('"help": "Show the quest list in interiors.\\nDefault: Enabled",',
     '"help": "在室内显示任务列表。\\n默认：开启",', 1),
]

RULES += [
    ('"text": "Hide In Combat",', '"text": "战斗中隐藏",', 1),
    ('"help": "Hide when the weapon is drawn.\\nDefault: Disabled",',
     '"help": "拔出武器时隐藏任务列表。\\n默认：关闭",', 1),
]

# 调试页；保留英文级别名以便与日志对照。
RULES += [
    ('"text": "Log Level",', '"text": "日志级别",', 1),
    ('"help": "Sets the level of detail in the log.\\nDefault: Info",',
     '"help": "设置日志的详细程度，级别越低记录越多。\\n默认：Info",', 1),
    ('"options": [ "Trace", "Debug", "Info", "Warning", "Error", "Critical Error" ],',
     '"options": [ "Trace 追踪", "Debug 调试", "Info 信息", "Warning 警告", "Error 错误", "Critical 严重错误" ],', 1),
]


def main() -> int:
    if not SRC.is_file():
        print(f"[错误] 找不到英文母本：{SRC}", file=sys.stderr)
        return 2
    # newline="" 保证 CRLF 原样读入、原样写出，不被 Python 的通用换行改写。
    # 用显式 open 而不是 Path.read_text(newline=...)：后者要到 3.13 才支持这个参数。
    with open(SRC, "r", encoding="utf-8", newline="") as fp:
        text = fp.read()
    if text.startswith("﻿"):
        print(f"[错误] 源文件带 BOM，与既有约定不符：{SRC}", file=sys.stderr)
        return 1

    for old, new, expect in RULES:
        got = text.count(old)
        if got != expect:
            print(f"[错误] 期望出现 {expect} 次，实际 {got} 次：{old}", file=sys.stderr)
            return 1
        text = text.replace(old, new)

    # 粗查残留文案；结构级校验由 verify_mcm_config_zhcn.py 完成。
    for leftover in ("Default:", "pageDisplayName\": \"Compass\"", "Show ", "Delay to show"):
        if leftover in text:
            print(f"[错误] 仍有未翻译的英文残留：{leftover!r}", file=sys.stderr)
            return 1

    DST.parent.mkdir(parents=True, exist_ok=True)
    # UTF-8 无 BOM，与英文原版一致；MCM Helper 用 nlohmann/json 按 UTF-8 解析
    with open(DST, "w", encoding="utf-8", newline="") as fp:
        fp.write(text)
    print(f"[完成] 已生成 {DST}")
    print(f"        {len(RULES)} 条替换全部命中，{len(text.encode('utf-8'))} 字节")

    return 0


if __name__ == "__main__":
    sys.exit(main())
