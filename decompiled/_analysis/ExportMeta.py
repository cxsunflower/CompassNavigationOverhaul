# ExportMeta.py - dump function metadata of the current program to JSON
# @category CNO
# Usage (headless): -postScript ExportMeta.py <output.json>
import json

from ghidra.program.model.symbol import RefType

args = getScriptArgs()
outPath = args[0]

fm = currentProgram.getFunctionManager()
listing = currentProgram.getListing()
refMgr = currentProgram.getReferenceManager()

# ---- collect defined strings once: address -> value -----------------------
strings = {}
di = listing.getDefinedData(True)
while di.hasNext():
    d = di.next()
    try:
        if d.hasStringValue():
            v = d.getValue()
            if v is not None:
                strings[d.getAddress().toString()] = unicode(v)[:400]
    except:
        pass

funcs = []
it = fm.getFunctions(True)
while it.hasNext():
    f = it.next()
    entry = f.getEntryPoint()
    body = f.getBody()

    srefs = []
    callees = set()
    # walk references originating inside the function body
    aiter = body.getAddresses(True)
    while aiter.hasNext():
        a = aiter.next()
        for r in refMgr.getReferencesFrom(a):
            to = r.getToAddress()
            key = to.toString()
            if key in strings:
                srefs.append(strings[key])
            rt = r.getReferenceType()
            if rt.isCall():
                cf = fm.getFunctionAt(to)
                if cf is not None:
                    callees.add(cf.getEntryPoint().toString())

    callers = set()
    for cf in f.getCallingFunctions(None):
        callers.add(cf.getEntryPoint().toString())

    # de-dup while keeping order
    seen = set()
    uniq = []
    for s in srefs:
        if s not in seen:
            seen.add(s)
            uniq.append(s)

    try:
        qname = f.getSymbol().getName(True)
    except:
        qname = f.getName()

    funcs.append({
        "ep": entry.toString(),
        "name": f.getName(),
        "qname": qname,
        "sig": f.getSignature().getPrototypeString(True),
        "size": int(body.getNumAddresses()),
        "thunk": bool(f.isThunk()),
        "extern": bool(f.isExternal()),
        "strings": uniq,
        "callees": sorted(list(callees)),
        "callers": sorted(list(callers)),
    })

data = {
    "program": currentProgram.getName(),
    "imagebase": currentProgram.getImageBase().toString(),
    "count": len(funcs),
    "functions": funcs,
}

fh = open(outPath, "w")
json.dump(data, fh)
fh.close()
print("[ExportMeta] wrote %d functions to %s" % (len(funcs), outPath))
