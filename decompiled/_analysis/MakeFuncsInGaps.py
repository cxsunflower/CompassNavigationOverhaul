# MakeFuncsInGaps.py
# -*- coding: utf-8 -*-
# 在 .text 的「未反汇编空洞」里补建函数。
# CNO 有相当一部分代码只通过函数指针 / 虚表被引用（例如 InfinityUIMessageListener、
# MCMPlusPlusMessageListener、各种 lambda），Ghidra 的自动分析找不到入口，
# 于是这些字节根本没被反汇编。这里按「跳过对齐填充 -> 反汇编 -> 建函数」补齐。
# @category CNO
# 用法: -postScript MakeFuncsInGaps.py <ranges.json>
import json

from ghidra.app.cmd.function import CreateFunctionCmd
from ghidra.util.task import ConsoleTaskMonitor
from ghidra.program.model.symbol import SourceType

monitor2 = ConsoleTaskMonitor()

args = getScriptArgs()
ranges = json.load(open(args[0], "r"))

af = currentProgram.getAddressFactory()
fm = currentProgram.getFunctionManager()
listing = currentProgram.getListing()
mem = currentProgram.getMemory()

PAD = set([0xCC, 0x00, 0x90])


def toAddr2(v):
    return af.getAddress("%x" % v)


created = 0
disasmed = 0
for lo, hi in ranges:
    cur = lo
    guard = 0
    while cur < hi and guard < 20000:
        guard += 1
        a = toAddr2(cur)
        # 已经属于某个函数体 / 已有指令 / 已定义数据 -> 跳过
        f = fm.getFunctionContaining(a)
        if f is not None:
            cur = int(f.getBody().getMaxAddress().getOffset()) + 1
            continue
        inst = listing.getInstructionContaining(a)
        if inst is not None:
            cur = int(inst.getMaxAddress().getOffset()) + 1
            continue
        if listing.getDataContaining(a) is not None and listing.getDataAt(a) is not None \
                and listing.getDataAt(a).isDefined():
            cur += max(1, listing.getDataAt(a).getLength())
            continue
        try:
            b = mem.getByte(a) & 0xFF
        except:
            cur += 1
            continue
        if b in PAD:
            cur += 1
            continue
        # 尝试反汇编 + 建函数
        try:
            disassemble(a)
            disasmed += 1
        except:
            cur += 1
            continue
        try:
            nf = createFunction(a, None)
            if nf is None:
                # 平面 API 有时会拒绝（例如流程尚未收敛），改用命令对象强制建函数
                cmd = CreateFunctionCmd(a)
                cmd.applyTo(currentProgram, monitor2)
                nf = fm.getFunctionAt(a)
            if nf is not None:
                created += 1
                cur = int(nf.getBody().getMaxAddress().getOffset()) + 1
                continue
        except:
            pass
        inst = listing.getInstructionAt(a)
        cur = (int(inst.getMaxAddress().getOffset()) + 1) if inst is not None else cur + 1

print("[MakeFuncsInGaps] disassembled=%d created=%d" % (disasmed, created))
