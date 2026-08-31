# DecompOne.py
# -*- coding: utf-8 -*-
# 反编译单个函数并把结果写到文件，同时打印反编译器的报错信息，用于排查空输出。
# @category CNO
# 用法: -postScript DecompOne.py <addr> <outFile>
from ghidra.app.decompiler import DecompInterface, DecompileOptions
from ghidra.util.task import ConsoleTaskMonitor

args = getScriptArgs()
a = currentProgram.getAddressFactory().getAddress(args[0])
outFile = args[1]

fm = currentProgram.getFunctionManager()
f = fm.getFunctionAt(a)
print("func=%s size=%s" % (f, f.getBody().getNumAddresses() if f else -1))

ifc = DecompInterface()
opts = DecompileOptions()
opts.grabFromProgram(currentProgram)
ifc.setOptions(opts)
ifc.setSimplificationStyle("decompile")
ifc.openProgram(currentProgram)
res = ifc.decompileFunction(f, 600, ConsoleTaskMonitor())
print("completed=%s msg=%s" % (res.decompileCompleted(), res.getErrorMessage()))
dec = res.getDecompiledFunction()
c = dec.getC() if dec is not None else None
print("clen=%s" % (len(c) if c else None))
fh = open(outFile, "w")
fh.write(c if c else "/* 反编译器未产生输出 */\n")
fh.close()
