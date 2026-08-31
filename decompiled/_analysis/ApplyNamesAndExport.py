# ApplyNamesAndExport.py
# -*- coding: utf-8 -*-
# 1) 读入 name_map.json（启发式跨版本映射）与 manual_anchors.json（人工核对锚点），
#    把真名写回 2.9.9 程序的函数符号，便于交叉引用时阅读；
# 2) 对 export_list.json 中列出的函数逐个反编译，按模块分组写出 .c 文件。
# 输出文件里的函数标题一律使用「带命名空间的真名」，与 2.2.0-VR 版 PDB 中的符号一致。
# @category CNO
# 用法: -postScript ApplyNamesAndExport.py <name_map.json> <manual.json> <export_list.json> <outDir>
import json
import os
import re

from ghidra.app.decompiler import DecompInterface, DecompileOptions
from ghidra.util.task import ConsoleTaskMonitor
from ghidra.program.model.symbol import SourceType

args = getScriptArgs()
nameMapPath, manualPath, listPath, outDir = args[0], args[1], args[2], args[3]


def readJson(p):
    fh = open(p, "r")
    try:
        return json.load(fh)
    finally:
        fh.close()


# 人工锚点优先级高于启发式匹配结果
merged = {}
merged.update(readJson(nameMapPath))
merged.update(readJson(manualPath))
exportList = readJson(listPath)

fm = currentProgram.getFunctionManager()
af = currentProgram.getAddressFactory()

# ---------------- 第一步：写回符号名 ----------------
applied = 0
for ep, qname in merged.items():
    f = fm.getFunctionAt(af.getAddress(ep))
    if f is None:
        continue
    flat = re.sub(r"[^A-Za-z0-9_]", "_", qname.replace("::", "__"))
    try:
        f.setName(flat, SourceType.USER_DEFINED)
        applied += 1
    except:
        pass
print("[ApplyNames] applied %d / %d" % (applied, len(merged)))

# ---------------- 第二步：反编译导出 ----------------
ifc = DecompInterface()
opts = DecompileOptions()
opts.grabFromProgram(currentProgram)
ifc.setOptions(opts)
ifc.openProgram(currentProgram)
monitor = ConsoleTaskMonitor()

# 模块归类：按真名的命名空间前缀决定落到哪个文件
MODULES = [
    ("HUDMarkerManager", re.compile(r"^CNO::HUDMarkerManager")),
    ("Compass", re.compile(r"^CNO::Compass")),
    ("QuestItemList", re.compile(r"^QuestItemList")),
    ("Hooks", re.compile(r"^hooks::")),
    ("Settings", re.compile(r"^settings::|^utils::(Setting|MakeSetting|INISettingCollection)")),
    ("MessageListeners", re.compile(r"MessageListener")),
    ("main", re.compile(r"^SKSEPlugin_")),
    ("NND", re.compile(r"^NND::")),
    ("IUI", re.compile(r"^IUI::")),
    ("utils", re.compile(r"^utils::")),
    ("RE", re.compile(r"^RE::")),
]

buckets = {}


def unflatten(n):
    """把历史遗留的扁平符号名（CNO__Compass__Marker__Marker）还原成带 :: 的形式，
    并折叠重复前缀（CNO::Compass::CNO::Compass::X -> CNO::Compass::X）。"""
    last = n.split("::")[-1]
    if "__" not in last:
        return n
    parts = [x for x in last.split("__") if x != ""]
    # 折叠形如 A B A B C 的重复前缀
    for k in range(1, len(parts) // 2 + 1):
        if parts[:k] == parts[k:2 * k]:
            parts = parts[k:]
            break
    return "::".join(parts)


def bucketOf(name):
    for mod, pat in MODULES:
        if pat.search(name):
            return mod
    return "_unresolved"


if not os.path.exists(outDir):
    os.makedirs(outDir)

ok = 0
fail = 0
for ep in exportList:
    f = fm.getFunctionAt(af.getAddress(ep))
    if f is None:
        continue
    res = ifc.decompileFunction(f, 600, monitor)  # 大函数在 180 秒会超时并产出空体，提到 600 秒
    if res is None or not res.decompileCompleted():
        fail += 1
        continue
    src = res.getDecompiledFunction().getC()
    qn = merged.get(ep)
    if qn is None:
        # 没有人工/启发式映射：用程序里的符号名，并还原历史遗留的扁平命名
        qn = unflatten(f.getName())
        mark = u"" if qn.startswith("FUN_") else u"   [名称未经人工确认]"
    else:
        mark = u""
    buckets.setdefault(bucketOf(qn), []).append(
        (ep, qn, int(f.getBody().getNumAddresses()), src, mark))
    ok += 1

for mod, items in buckets.items():
    items.sort(key=lambda t: t[0])
    fh = open(os.path.join(outDir, mod + ".c"), "w")
    fh.write("/* ============================================================\n")
    fh.write(" * %s.c  ——  CompassNavigationOverhaul 2.9.9 反编译产物\n" % mod)
    fh.write(" * 由 Ghidra 11.3.2 反编译器从 SKSE/Plugins/CompassNavigationOverhaul.dll 导出。\n")
    fh.write(" * 函数名来自 2.2.0-VR 版 PDB 的跨版本符号映射；FUN_xxxxxxxx 表示尚未对上真名。\n")
    fh.write(" * 共 %d 个函数。这是「2.9.9 行为的唯一事实来源」，不可直接编译。\n" % len(items))
    fh.write(" * ============================================================ */\n\n")
    for ep, name, size, src, mark in items:
        # Jython 2 里中文标注是 unicode，写入前统一编成 UTF-8 字节，避免 ascii 编解码错
        fh.write((u"/* ---- 0x%s  %s  (%d bytes)%s ---- */\n"
                  % (ep, name, size, mark)).encode("utf-8"))
        fh.write(src)
        fh.write("\n")
    fh.close()
    print("[Export] %-20s %4d funcs" % (mod, len(items)))

idx = open(os.path.join(outDir, "index.tsv"), "w")
idx.write("module\tentry\tname\tsize\tname_status\n")
for mod, items in sorted(buckets.items()):
    for ep, name, size, src, mark in items:
        # confirmed = 人工/启发式映射命中；unconfirmed = 只有程序里残留的符号名；
        # raw = 仍是 Ghidra 自动生成的 FUN_xxxxxxxx，尚未对上真名
        if name.startswith("FUN_"):
            st = "raw"
        elif mark == "":
            st = "confirmed"
        else:
            st = "unconfirmed"
        idx.write("%s\t%s\t%s\t%d\t%s\n" % (mod, ep, name, size, st))
idx.close()

print("[Export] done ok=%d fail=%d -> %s" % (ok, fail, outDir))
