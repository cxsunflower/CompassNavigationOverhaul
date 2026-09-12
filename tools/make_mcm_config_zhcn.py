#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""以带次数断言的字面替换生成中文 MCM 配置，并保留原 JSON 格式与换行。"""

import pathlib
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
# 主包与中文覆盖包各自保持游戏安装路径。
MCM_CONFIG = ROOT / "assets" / "main" / "MCM" / "Config" / "Compass Navigation Overhaul VR"
SRC = MCM_CONFIG / "config.json"
DST = ROOT / "assets/localization/zh-CN/MCM/Config/Compass Navigation Overhaul VR/config.json"

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
    ('"help": "Horizontal offset from the compass text anchor, in HUD coordinates. Positive moves right; negative moves left. Still follows the compass.\\nDefault: 0",', '"help": "相对罗盘文字锚点的横向偏移，单位为界面坐标。正值向右，负值向左；仍跟随罗盘。\\n默认：0",', 1),

    ('"text": "Show in Exteriors",', '"text": "室外显示",', 1),
    ('"help": "Show the quest list in exteriors.\\nDefault: Enabled",',
     '"help": "在室外显示任务列表。\\n默认：开启",', 1),

    ('"text": "Show in Interiors",', '"text": "室内显示",', 1),
    ('"help": "Show the quest list in interiors.\\nDefault: Enabled",',
     '"help": "在室内显示任务列表。\\n默认：开启",', 1),
]

RULES += [
    ('"text": "Hide With Weapon Drawn",', '"text": "拔出武器时隐藏",', 1),
    ('"help": "Hide while the game reports that your weapon is drawn, whether or not you are in combat.\\nDefault: Disabled",',
     '"help": "按游戏报告的武器拔出状态隐藏任务列表，与是否处于战斗无关。\\n默认：关闭",', 1),
]

# 调试页；保留英文级别名以便与日志对照。
RULES += [
    ('"text": "Log Level",', '"text": "日志级别",', 1),
    ('"help": "Trace and Debug enable all HUD diagnostic outlines, short status text and detailed logs. Info and higher disable the HUD diagnostics. Boundary calibration remains separate.\\nDefault: Info",',
     '"help": "Trace 和 Debug 开启全部 HUD 诊断边框、简短状态和详细日志；Info 及以上关闭普通 HUD 诊断。边界校准仍独立控制。\\n默认：Info",', 1),
    ('"options": [ "Trace", "Debug", "Info", "Warning", "Error", "Critical Error" ],',
     '"options": [ "Trace 追踪", "Debug 调试", "Info 信息", "Warning 警告", "Error 错误", "Critical 严重错误" ],', 1),
]

# 罗盘注视门控（任务列表页末尾）。
RULES += [
    ('"text": "Compass Gaze ",', '"text": "罗盘注视 ",', 1),

    ('"text": "Require Looking at Compass",', '"text": "需要注视罗盘",', 1),
    ('"help": "Only show the quest list while your 3D gaze rests on the compass. A focused quest marker is still required.\\nDefault: Enabled",',
     '"help": "只有 3D 视线落在罗盘上时才显示任务列表，之前仍需要先聚焦任务标记。\\n默认：开启",', 1),

    ('"text": "Require Compass Visible",', '"text": "需要罗盘可见",', 1),
    ('"help": "Hide the quest list while the compass itself is hidden (e.g. Palm Compass VR with the palm down).\\nDefault: Enabled",',
     '"help": "罗盘本身隐藏时不显示任务列表（例如手掌放下后手掌罗盘隐藏的状态）。\\n默认：开启",', 1),

    ('"text": "Gaze Detection Mode",', '"text": "注视检测模式",', 1),
    ('"help": "How gaze is measured. Higher modes fall back automatically when their 3D node is missing.\\nDefault: Compass Node",',
     '"help": "注视的测量方式。高档模式在 3D 节点缺失时会自动降级。\\n默认：罗盘节点",', 1),
    ('"options": [ "Pitch Fallback", "Right Hand", "Compass Node" ],',
     '"options": [ "俯角兜底", "右手", "罗盘节点" ],', 1),

    ('"text": "Gaze Angle to Show",', '"text": "注视显示角度",', 1),
    ('"help": "3D gaze angle to the compass or hand point that starts showing the list (modes 1-2).\\nDefault: 15º",',
     '"help": "视线与罗盘/手部位置的 3D 夹角小于该值时开始显示（模式 1-2）。\\n默认：15º",', 1),

    ('"text": "Gaze Angle to Keep",', '"text": "注视保持角度",', 1),
    ('"help": "Once shown, the list hides only after this angle is exceeded (modes 1-2).\\nDefault: 25º",',
     '"help": "已经显示后，夹角超过该值才隐藏（模式 1-2）。\\n默认：25º",', 1),

    ('"text": "Max Gaze Distance",', '"text": "注视最大距离",', 1),
    ('"help": "Gaze points farther than this are ignored. In game units, about 70 per meter.\\nDefault: 90",',
     '"help": "超过该距离的注视点会被忽略。单位是游戏单位（约 70 单位=1 米）。\\n默认：90",', 1),

    ('"text": "Pitch Angle to Show",', '"text": "俯角显示角度",', 1),
    ('"help": "How far down you must look to show the list in Pitch mode (mode 0).\\nDefault: 18º",',
     '"help": "俯角模式下，低头超过该角度才显示任务列表。\\n默认：18º",', 1),

    ('"text": "Pitch Angle to Keep",', '"text": "俯角保持角度",', 1),
    ('"help": "Once shown in Pitch mode, the list hides only after you look up past this angle.\\nDefault: 10º",',
     '"help": "俯角模式下已经显示后，抬头超过该角度才隐藏。\\n默认：10º",', 1),

    ('"text": "Compass on Palm",', '"text": "罗盘在手掌上",', 1),
    ('"help": "Enable for Palm Compass VR: look DOWN at your palm. Disable if the compass floats above eye level: look UP instead.\\nDefault: Enabled",',
     '"help": "手掌罗盘用户请开启：低头看手掌。关闭则适用于罗盘在视线上方的情况：抬头看。\\n默认：开启",', 1),
]

# 罗盘文字分开缩放 + 列表面板缩放。
RULES += [
    ('"text": "Quest/Location Name Size",', '"text": "任务/地点名称大小",', 1),
    ('"help": "Text size of the quest/location name under the compass marker, in percent.\\nDefault: 100%",',
     '"help": "罗盘标记下方任务/地点名称的文字大小，百分比。\\n默认：100%",', 1),

    ('"text": "Distance Size",', '"text": "距离大小",', 1),
    ('"help": "Size of the distance readout and above/below indicator, in percent.\\nDefault: 100%",',
     '"help": "距离读数和海拔向上/向下图标的大小，百分比。\\n默认：100%",', 1),

    ('"text": "Panel Size",', '"text": "面板大小",', 1),
    ('"help": "Overall size of the quest list panel, in percent. Entries, text and icons scale together.\\nDefault: 100%",',
     '"help": "任务列表面板的整体大小，百分比。条目、文字与图标一起缩放。\\n默认：100%",', 1),
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
