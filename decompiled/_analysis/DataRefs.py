# DataRefs.py
# -*- coding: utf-8 -*-
# 列出若干数据地址的所有引用（读/写）及所属函数，用于定位全局变量的赋值点。
# @category CNO
# 用法: -postScript DataRefs.py <dataAddr1> [...]
args = getScriptArgs()
af = currentProgram.getAddressFactory()
fm = currentProgram.getFunctionManager()
rm = currentProgram.getReferenceManager()
for s in args:
    a = af.getAddress(s)
    print("==== %s" % s)
    for r in rm.getReferencesTo(a):
        fa = r.getFromAddress()
        f = fm.getFunctionContaining(fa)
        print("   %s  %-14s  in %s" % (fa, r.getReferenceType(), f.getName() if f else "?"))
