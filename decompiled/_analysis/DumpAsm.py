# DumpAsm.py
# -*- coding: utf-8 -*-
# 打印若干地址处函数的反汇编，用于快速看清 unrestricted_cast 之类的小函数返回什么。
# @category CNO
args = getScriptArgs()
fm = currentProgram.getFunctionManager()
af = currentProgram.getAddressFactory()
listing = currentProgram.getListing()
for s in args:
    a = af.getAddress(s)
    f = fm.getFunctionAt(a)
    print("==== %s  %s" % (s, f.getName() if f else "?"))
    body = f.getBody() if f else None
    it = listing.getInstructions(body, True) if body else []
    for ins in it:
        print("   %s  %s" % (ins.getAddress(), ins))
