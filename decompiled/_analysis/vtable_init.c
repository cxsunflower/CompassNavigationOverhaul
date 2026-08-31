/* ==== 0x1800010c0  FUN_1800010c0  (200 bytes) ==== */

void FUN_1800010c0(void)

{
  longlong lVar1;
  undefined *puVar2;
  IDDatabase *pIVar3;
  ulong64 uVar4;
  ulonglong uVar5;
  
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    uVar5 = 0x34954;
  }
  else {
    if (puVar2[0x118] != '\x02') {
      DAT_1801d9588 = 0;
      return;
    }
    uVar5 = 0x41a19;
  }
  pIVar3 = (IDDatabase *)REL::IDDatabase::get();
  uVar4 = REL::IDDatabase::id2offset(pIVar3,uVar5);
  if (uVar4 == 0) {
    DAT_1801d9588 = 0;
    return;
  }
  puVar2 = REL::Module::get();
  lVar1 = *(longlong *)(puVar2 + 0x110);
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    pIVar3 = (IDDatabase *)REL::IDDatabase::get();
    uVar4 = REL::IDDatabase::id2offset(pIVar3,0x34954);
    DAT_1801d9588 = uVar4 + lVar1;
    return;
  }
  if (puVar2[0x118] == '\x02') {
    pIVar3 = (IDDatabase *)REL::IDDatabase::get();
    uVar4 = REL::IDDatabase::id2offset(pIVar3,0x41a19);
    DAT_1801d9588 = uVar4 + lVar1;
    return;
  }
  DAT_1801d9588 = lVar1;
  return;
}


/* ==== 0x1800011f0  FUN_1800011f0  (200 bytes) ==== */

void FUN_1800011f0(void)

{
  longlong lVar1;
  undefined *puVar2;
  IDDatabase *pIVar3;
  ulong64 uVar4;
  ulonglong uVar5;
  
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    uVar5 = 0x324cf;
  }
  else {
    if (puVar2[0x118] != '\x02') {
      DAT_1801d95a0 = 0;
      return;
    }
    uVar5 = 0x3ef7f;
  }
  pIVar3 = (IDDatabase *)REL::IDDatabase::get();
  uVar4 = REL::IDDatabase::id2offset(pIVar3,uVar5);
  if (uVar4 == 0) {
    DAT_1801d95a0 = 0;
    return;
  }
  puVar2 = REL::Module::get();
  lVar1 = *(longlong *)(puVar2 + 0x110);
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    pIVar3 = (IDDatabase *)REL::IDDatabase::get();
    uVar4 = REL::IDDatabase::id2offset(pIVar3,0x324cf);
    DAT_1801d95a0 = uVar4 + lVar1;
    return;
  }
  if (puVar2[0x118] == '\x02') {
    pIVar3 = (IDDatabase *)REL::IDDatabase::get();
    uVar4 = REL::IDDatabase::id2offset(pIVar3,0x3ef7f);
    DAT_1801d95a0 = uVar4 + lVar1;
    return;
  }
  DAT_1801d95a0 = lVar1;
  return;
}


/* ==== 0x1800012c0  FUN_1800012c0  (200 bytes) ==== */

void FUN_1800012c0(void)

{
  longlong lVar1;
  undefined *puVar2;
  IDDatabase *pIVar3;
  ulong64 uVar4;
  ulonglong uVar5;
  
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    uVar5 = 0x32427;
  }
  else {
    if (puVar2[0x118] != '\x02') {
      DAT_1801d95a8 = 0;
      return;
    }
    uVar5 = 0x3ee7d;
  }
  pIVar3 = (IDDatabase *)REL::IDDatabase::get();
  uVar4 = REL::IDDatabase::id2offset(pIVar3,uVar5);
  if (uVar4 == 0) {
    DAT_1801d95a8 = 0;
    return;
  }
  puVar2 = REL::Module::get();
  lVar1 = *(longlong *)(puVar2 + 0x110);
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    pIVar3 = (IDDatabase *)REL::IDDatabase::get();
    uVar4 = REL::IDDatabase::id2offset(pIVar3,0x32427);
    DAT_1801d95a8 = uVar4 + lVar1;
    return;
  }
  if (puVar2[0x118] == '\x02') {
    pIVar3 = (IDDatabase *)REL::IDDatabase::get();
    uVar4 = REL::IDDatabase::id2offset(pIVar3,0x3ee7d);
    DAT_1801d95a8 = uVar4 + lVar1;
    return;
  }
  DAT_1801d95a8 = lVar1;
  return;
}


/* ==== 0x180001390  FUN_180001390  (200 bytes) ==== */

void FUN_180001390(void)

{
  longlong lVar1;
  undefined *puVar2;
  IDDatabase *pIVar3;
  ulong64 uVar4;
  ulonglong uVar5;
  
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    uVar5 = 0x324eb;
  }
  else {
    if (puVar2[0x118] != '\x02') {
      DAT_1801d95b0 = 0;
      return;
    }
    uVar5 = 0x3efb0;
  }
  pIVar3 = (IDDatabase *)REL::IDDatabase::get();
  uVar4 = REL::IDDatabase::id2offset(pIVar3,uVar5);
  if (uVar4 == 0) {
    DAT_1801d95b0 = 0;
    return;
  }
  puVar2 = REL::Module::get();
  lVar1 = *(longlong *)(puVar2 + 0x110);
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    pIVar3 = (IDDatabase *)REL::IDDatabase::get();
    uVar4 = REL::IDDatabase::id2offset(pIVar3,0x324eb);
    DAT_1801d95b0 = uVar4 + lVar1;
    return;
  }
  if (puVar2[0x118] == '\x02') {
    pIVar3 = (IDDatabase *)REL::IDDatabase::get();
    uVar4 = REL::IDDatabase::id2offset(pIVar3,0x3efb0);
    DAT_1801d95b0 = uVar4 + lVar1;
    return;
  }
  DAT_1801d95b0 = lVar1;
  return;
}


/* ==== 0x180001060  FUN_180001060  (38 bytes) ==== */

void FUN_180001060(void)

{
  ulonglong local_18 [3];
  
  local_18[0] = 0xc6a3;
  local_18[1] = 0xca10;
  DAT_1801d9578 = FUN_18000f860(local_18);
  return;
}


