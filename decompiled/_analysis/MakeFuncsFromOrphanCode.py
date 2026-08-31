# MakeFuncsFromOrphanCode.py
# -*- coding: utf-8 -*-
# 第二遍补建：处理「已经反汇编但不属于任何函数」的孤立指令块。
# 上一遍 disassemble() 会顺着流程把整段代码都变成指令，但平面 API createFunction
# 有时返回 None，导致这些指令没有归属函数。这里逐块扫描并用 CreateFunctionCmd 建函数。
# @category CNO
# 用法: -postScript MakeFuncsFromOrphanCode.py <ranges.json>
import json

from ghidra.app.cmd.function import CreateFunctionCmd
from ghidra.util.task import ConsoleTaskMonitor

args = getScriptArgs()
ranges = json.load(open(args[0], "r"))

af = currentProgram.getAddressFactory()
fm = currentProgram.getFunctionManager()
listing = currentProgram.getListing()
monitor2 = ConsoleTaskMonitor()


def toAddr2(v):
    return af.getAddress("%x" % v)


created = 0
for lo, hi in ranges:
    cur = lo
    guard = 0
    while cur < hi and guard < 60000:
        guard += 1
        a = toAddr2(cur)
        f = fm.getFunctionContaining(a)
        if f is not None:
            cur = int(f.getBody().getMaxAddress().getOffset()) + 1
            continue
        inst = listing.getInstructionAt(a)
        if inst is None:
            cur += 1
            continue
        cmd = CreateFunctionCmd(a)
        cmd.applyTo(currentProgram, monitor2)
        nf = fm.getFunctionAt(a)
        if nf is not None:
            created += 1
            cur = int(nf.getBody().getMaxAddress().getOffset()) + 1
        else:
            cur = int(inst.getMaxAddress().getOffset()) + 1

print("[MakeFuncsFromOrphanCode] created=%d" % created)
