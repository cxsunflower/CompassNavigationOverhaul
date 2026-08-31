# CreateAt.py
# -*- coding: utf-8 -*-
# 在指定地址强制建立函数（先反汇编，再用 CreateFunctionCmd 建函数），并打印诊断信息。
# @category CNO
# 用法: -postScript CreateAt.py <addr1> [addr2 ...]
from ghidra.app.cmd.function import CreateFunctionCmd
from ghidra.util.task import ConsoleTaskMonitor

args = getScriptArgs()
af = currentProgram.getAddressFactory()
fm = currentProgram.getFunctionManager()
listing = currentProgram.getListing()
monitor = ConsoleTaskMonitor()

for s in args:
    a = af.getAddress(s)
    print("---- %s" % s)
    print("   containingFunc=%s" % fm.getFunctionContaining(a))
    print("   instAt=%s" % listing.getInstructionAt(a))
    print("   dataAt=%s" % listing.getDataAt(a))
    try:
        disassemble(a)
    except Exception, e:
        print("   disassemble failed: %s" % e)
    print("   instAt(after)=%s" % listing.getInstructionAt(a))
    cmd = CreateFunctionCmd(a)
    okc = cmd.applyTo(currentProgram, monitor)
    print("   CreateFunctionCmd ok=%s status=%s" % (okc, cmd.getStatusMsg()))
    f = fm.getFunctionAt(a)
    if f is not None:
        print("   -> %s size=%d" % (f.getName(), f.getBody().getNumAddresses()))
