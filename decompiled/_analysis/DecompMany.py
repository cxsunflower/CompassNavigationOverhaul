# DecompMany.py
# -*- coding: utf-8 -*-
# 批量反编译指定地址列表，统一写入一个文件（超时 600 秒，避免大函数产出空体）。
# @category CNO
# 用法: -postScript DecompMany.py <outFile> <addr1> [addr2 ...]
from ghidra.app.decompiler import DecompInterface, DecompileOptions
from ghidra.util.task import ConsoleTaskMonitor

args = getScriptArgs()
outFile = args[0]
addrs = args[1:]

fm = currentProgram.getFunctionManager()
af = currentProgram.getAddressFactory()

ifc = DecompInterface()
opts = DecompileOptions()
opts.grabFromProgram(currentProgram)
ifc.setOptions(opts)
ifc.setSimplificationStyle("decompile")
ifc.openProgram(currentProgram)
mon = ConsoleTaskMonitor()

fh = open(outFile, "w")
for s in addrs:
    a = af.getAddress(s)
    f = fm.getFunctionAt(a)
    if f is None:
        fh.write("/* %s: 无函数 */\n" % s)
        continue
    res = ifc.decompileFunction(f, 600, mon)
    c = None
    if res is not None and res.decompileCompleted():
        d = res.getDecompiledFunction()
        c = d.getC() if d is not None else None
    fh.write("/* ==== 0x%s  %s  (%d bytes) ==== */\n" %
             (s, f.getName(), f.getBody().getNumAddresses()))
    fh.write(c if c else "/* 反编译器未产生输出 */\n")
    fh.write("\n")
    print("%s len=%s" % (s, len(c) if c else 0))
fh.close()
