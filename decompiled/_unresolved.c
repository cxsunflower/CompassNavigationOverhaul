/* ============================================================
 * _unresolved.c  ——  CompassNavigationOverhaul 2.9.9 反编译产物
 * 由 Ghidra 11.3.2 反编译器从 SKSE/Plugins/CompassNavigationOverhaul.dll 导出。
 * 函数名来自 2.2.0-VR 版 PDB 的跨版本符号映射；FUN_xxxxxxxx 表示尚未对上真名。
 * 共 1054 个函数。这是「2.9.9 行为的唯一事实来源」，不可直接编译。
 * ============================================================ */

/* ---- 0x180001000  FUN_180001000  (38 bytes) ---- */

void FUN_180001000(void)

{
  ulonglong auStack_18 [3];
  
  auStack_18[0] = 0xc68a;
  auStack_18[1] = 0xc9eb;
  DAT_1801d9568 = FUN_18000f860(auStack_18);
  return;
}


/* ---- 0x180001030  FUN_180001030  (38 bytes) ---- */

void FUN_180001030(void)

{
  ulonglong local_18 [3];
  
  local_18[0] = 0xc6b6;
  local_18[1] = 0xca20;
  DAT_1801d9570 = FUN_18000f860(local_18);
  return;
}


/* ---- 0x180001090  FUN_180001090  (38 bytes) ---- */

void FUN_180001090(void)

{
  ulonglong local_18 [3];
  
  local_18[0] = 0xc61e;
  local_18[1] = 0xc99c;
  DAT_1801d9580 = FUN_18000f860(local_18);
  return;
}


/* ---- 0x180001190  FUN_180001190  (38 bytes) ---- */

void FUN_180001190(void)

{
  ulonglong local_18 [3];
  
  local_18[0] = 0xc657;
  local_18[1] = 0xc9d6;
  DAT_1801d9590 = FUN_18000f860(local_18);
  return;
}


/* ---- 0x1800011c0  FUN_1800011c0  (38 bytes) ---- */

void FUN_1800011c0(void)

{
  ulonglong local_18 [3];
  
  local_18[0] = 0xc655;
  local_18[1] = 0xc9d4;
  DAT_1801d9598 = FUN_18000f860(local_18);
  return;
}


/* ---- 0x180001460  FUN_180001460  (12 bytes) ---- */

void FUN_180001460(void)

{
  atexit(`dynamic_atexit_destructor_for_'REL::Module::_instance__);
  return;
}


/* ---- 0x180001470  FUN_180001470  (12 bytes) ---- */

void FUN_180001470(void)

{
  atexit(FUN_1801621b0);
  return;
}


/* ---- 0x18000147c  FUN_18000147c  (12 bytes) ---- */

void FUN_18000147c(void)

{
  atexit(FUN_18016255c);
  return;
}


/* ---- 0x180001490  FUN_180001490  (8 bytes) ---- */

void FUN_180001490(void *param_1,void *param_2,longlong param_3)

{
                    /* WARNING: Could not recover jumptable at 0x000180155396. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  memcpy(param_1,param_2,param_3 * 2);
  return;
}


/* ---- 0x180001510  FUN_180001510  (7 bytes) ---- */

undefined8 * FUN_180001510(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001520  FUN_180001520  (211 bytes) ---- */

void FUN_180001520(longlong param_1,undefined8 param_2,_Locinfo *param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  _Cvtvec *p_Var3;
  ushort *puVar4;
  void *pvVar5;
  undefined8 *puVar6;
  undefined1 auStack_68 [32];
  _Cvtvec local_48;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  p_Var3 = std::_Locinfo::_Getcvt(param_3,&local_48);
  uVar2 = *(undefined8 *)&p_Var3->_Isclocale;
  *(undefined8 *)(param_1 + 0x2c) = *(undefined8 *)p_Var3;
  *(undefined8 *)(param_1 + 0x34) = uVar2;
  uVar2 = *(undefined8 *)(p_Var3->_Isleadbyte + 0xc);
  *(undefined8 *)(param_1 + 0x3c) = *(undefined8 *)(p_Var3->_Isleadbyte + 4);
  *(undefined8 *)(param_1 + 0x44) = uVar2;
  *(undefined8 *)(param_1 + 0x4c) = *(undefined8 *)(p_Var3->_Isleadbyte + 0x14);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(p_Var3->_Isleadbyte + 0x1c);
  puVar4 = std::_Locinfo::_W_Getdays(param_3);
  pvVar5 = std::_Maklocwcs(puVar4);
  *(void **)(param_1 + 0x10) = pvVar5;
  puVar4 = std::_Locinfo::_W_Getmonths(param_3);
  pvVar5 = std::_Maklocwcs(puVar4);
  *(void **)(param_1 + 0x18) = pvVar5;
  puVar6 = (undefined8 *)calloc(0xd,2);
  if (puVar6 == (undefined8 *)0x0) {
    std::_Xbad_alloc();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  *puVar6 = 0x3a004d0041003a;
  puVar6[1] = 0x50003a006d0061;
  puVar6[2] = 0x6d0070003a004d;
  *(undefined2 *)(puVar6 + 3) = 0;
  *(undefined8 **)(param_1 + 0x20) = puVar6;
  __security_check_cookie(local_18 ^ (ulonglong)auStack_68);
  return;
}


/* ---- 0x180001600  FUN_180001600  (211 bytes) ---- */

void FUN_180001600(longlong param_1,undefined8 param_2,_Locinfo *param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  _Cvtvec *p_Var3;
  ushort *puVar4;
  void *pvVar5;
  undefined8 *puVar6;
  undefined1 auStack_68 [32];
  _Cvtvec local_48;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  p_Var3 = std::_Locinfo::_Getcvt(param_3,&local_48);
  uVar2 = *(undefined8 *)&p_Var3->_Isclocale;
  *(undefined8 *)(param_1 + 0x2c) = *(undefined8 *)p_Var3;
  *(undefined8 *)(param_1 + 0x34) = uVar2;
  uVar2 = *(undefined8 *)(p_Var3->_Isleadbyte + 0xc);
  *(undefined8 *)(param_1 + 0x3c) = *(undefined8 *)(p_Var3->_Isleadbyte + 4);
  *(undefined8 *)(param_1 + 0x44) = uVar2;
  *(undefined8 *)(param_1 + 0x4c) = *(undefined8 *)(p_Var3->_Isleadbyte + 0x14);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(p_Var3->_Isleadbyte + 0x1c);
  puVar4 = std::_Locinfo::_W_Getdays(param_3);
  pvVar5 = std::_Maklocwcs(puVar4);
  *(void **)(param_1 + 0x10) = pvVar5;
  puVar4 = std::_Locinfo::_W_Getmonths(param_3);
  pvVar5 = std::_Maklocwcs(puVar4);
  *(void **)(param_1 + 0x18) = pvVar5;
  puVar6 = (undefined8 *)calloc(0xd,2);
  if (puVar6 == (undefined8 *)0x0) {
    std::_Xbad_alloc();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  *puVar6 = 0x3a004d0041003a;
  puVar6[1] = 0x50003a006d0061;
  puVar6[2] = 0x6d0070003a004d;
  *(undefined2 *)(puVar6 + 3) = 0;
  *(undefined8 **)(param_1 + 0x20) = puVar6;
  __security_check_cookie(local_18 ^ (ulonglong)auStack_68);
  return;
}


/* ---- 0x1800016e0  FUN_1800016e0  (7 bytes) ---- */

undefined8 * FUN_1800016e0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800016f0  FUN_1800016f0  (7 bytes) ---- */

undefined8 * FUN_1800016f0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001700  FUN_180001700  (7 bytes) ---- */

undefined8 * FUN_180001700(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001710  FUN_180001710  (7 bytes) ---- */

undefined8 * FUN_180001710(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001720  FUN_180001720  (7 bytes) ---- */

undefined8 * FUN_180001720(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001730  FUN_180001730  (7 bytes) ---- */

undefined8 * FUN_180001730(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001740  FUN_180001740  (7 bytes) ---- */

undefined8 * FUN_180001740(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001750  FUN_180001750  (7 bytes) ---- */

undefined8 * FUN_180001750(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001760  FUN_180001760  (7 bytes) ---- */

undefined8 * FUN_180001760(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001770  FUN_180001770  (7 bytes) ---- */

undefined8 * FUN_180001770(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001780  FUN_180001780  (7 bytes) ---- */

undefined8 * FUN_180001780(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001790  FUN_180001790  (7 bytes) ---- */

undefined8 * FUN_180001790(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800017a0  FUN_1800017a0  (7 bytes) ---- */

undefined8 * FUN_1800017a0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800017b0  FUN_1800017b0  (7 bytes) ---- */

undefined8 * FUN_1800017b0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800017c0  FUN_1800017c0  (7 bytes) ---- */

undefined8 * FUN_1800017c0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800017d0  FUN_1800017d0  (7 bytes) ---- */

undefined8 * FUN_1800017d0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800017e0  FUN_1800017e0  (7 bytes) ---- */

undefined8 * FUN_1800017e0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800017f0  FUN_1800017f0  (7 bytes) ---- */

undefined8 * FUN_1800017f0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001800  FUN_180001800  (7 bytes) ---- */

undefined8 * FUN_180001800(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001810  FUN_180001810  (72 bytes) ---- */

void FUN_180001810(longlong param_1,longlong param_2,longlong param_3,code *param_4)

{
  if (param_3 != 0) {
    do {
      (*param_4)(param_1);
      param_1 = param_1 + param_2;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


/* ---- 0x180001860  FUN_180001860  (7 bytes) ---- */

undefined8 * FUN_180001860(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001870  FUN_180001870  (7 bytes) ---- */

undefined8 * FUN_180001870(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001880  FUN_180001880  (7 bytes) ---- */

undefined8 * FUN_180001880(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001890  FUN_180001890  (7 bytes) ---- */

undefined8 * FUN_180001890(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800018a0  FUN_1800018a0  (7 bytes) ---- */

undefined8 * FUN_1800018a0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800018b0  FUN_1800018b0  (7 bytes) ---- */

undefined8 * FUN_1800018b0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800018c0  FUN_1800018c0  (7 bytes) ---- */

undefined8 * FUN_1800018c0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800018d0  FUN_1800018d0  (7 bytes) ---- */

undefined8 * FUN_1800018d0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800018e0  FUN_1800018e0  (7 bytes) ---- */

undefined8 * FUN_1800018e0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800018f0  FUN_1800018f0  (7 bytes) ---- */

undefined8 * FUN_1800018f0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001900  FUN_180001900  (7 bytes) ---- */

undefined8 * FUN_180001900(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001910  FUN_180001910  (7 bytes) ---- */

undefined8 * FUN_180001910(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001920  FUN_180001920  (7 bytes) ---- */

undefined8 * FUN_180001920(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001930  FUN_180001930  (7 bytes) ---- */

undefined8 * FUN_180001930(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001940  FUN_180001940  (7 bytes) ---- */

undefined8 * FUN_180001940(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001950  FUN_180001950  (7 bytes) ---- */

undefined8 * FUN_180001950(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001960  FUN_180001960  (7 bytes) ---- */

undefined8 * FUN_180001960(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001970  FUN_180001970  (7 bytes) ---- */

undefined8 * FUN_180001970(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001980  FUN_180001980  (7 bytes) ---- */

undefined8 * FUN_180001980(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180001990  FUN_180001990  (7 bytes) ---- */

undefined8 * FUN_180001990(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800019a0  FUN_1800019a0  (7 bytes) ---- */

undefined8 * FUN_1800019a0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800019f0  FUN_1800019f0  (44 bytes) ---- */

void FUN_1800019f0(void)

{
  longlong lVar1;
  ulonglong local_18 [3];
  
  local_18[0] = 0x7eda3;
  local_18[1] = 0x63266;
  lVar1 = FUN_18000f860(local_18);
  FUN_180007680(lVar1);
  return;
}


/* ---- 0x180001a20  GFxArray  (44 bytes)   [名称未经人工确认] ---- */

undefined8 * __thiscall GFxArray::GFxArray(GFxArray *this,longlong *param_1)

{
  GFxArray *pGVar1;
  longlong *plVar2;
  
  pGVar1 = this;
  plVar2 = param_1;
  FUN_180045700((undefined8 *)this);
  (**(code **)(*param_1 + 0x70))(plVar2,pGVar1);
  return (undefined8 *)this;
}


/* ---- 0x180001a60  FUN_180001a60  (7 bytes) ---- */

undefined8 FUN_180001a60(undefined8 *param_1)

{
  return *(undefined8 *)*param_1;
}


/* ---- 0x180001a70  CropAngleRange  (89 bytes)   [名称未经人工确认] ---- */

void __cdecl util::CropAngleRange(float *param_1)

{
  float fVar1;
  
  fVar1 = *param_1;
  if (6.2831855 < fVar1) {
    fVar1 = fmodf(fVar1,6.2831855);
    *param_1 = fVar1;
  }
  else if (fVar1 < 0.0) {
    fVar1 = fmodf(fVar1,6.2831855);
    *param_1 = fVar1 + 6.2831855;
    return;
  }
  return;
}


/* ---- 0x180001ad0  FUN_180001ad0  (17 bytes) ---- */

float FUN_180001ad0(float param_1)

{
  return (param_1 * 180.0) / 3.1415927;
}


/* ---- 0x180001af0  FUN_180001af0  (358 bytes) ---- */

float FUN_180001af0(longlong param_1,longlong param_2)

{
  PlayerCharacter *pPVar1;
  undefined *puVar2;
  longlong lVar3;
  float fVar4;
  float fVar5;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_58;
  undefined4 local_50;
  
  pPVar1 = RE::PlayerCharacter::GetSingleton();
  local_58 = *(undefined8 *)&pPVar1->field_0x54;
  local_50 = *(undefined4 *)&pPVar1->field_0x5c;
  local_68 = *(undefined8 *)(param_2 + 0x54);
  local_60 = *(undefined4 *)(param_2 + 0x5c);
  REL::Module::get();
  puVar2 = REL::Module::get();
  if ((puVar2[0x118] == '\x01') || (lVar3 = 0x170, puVar2[0x118] != '\x04')) {
    lVar3 = 0x154;
  }
  fVar5 = *(float *)(lVar3 + param_1);
  if (*(TESObjectCELL **)&pPVar1->field_0x60 != (TESObjectCELL *)0x0) {
    RE::TESObjectCELL::GetNorthRotation(*(TESObjectCELL **)&pPVar1->field_0x60);
  }
  fVar4 = RE::NiPoint3::GetHorizontalAngleTo((NiPoint3 *)&local_58,(float *)&local_68);
  if (6.2831855 < fVar5) {
    fVar5 = fmodf(fVar5,6.2831855);
  }
  else if (fVar5 < 0.0) {
    fVar5 = fmodf(fVar5,6.2831855);
    fVar5 = fVar5 + 6.2831855;
  }
  if (6.2831855 < fVar4) {
    fVar4 = fmodf(fVar4,6.2831855);
  }
  else if (fVar4 < 0.0) {
    fVar4 = fmodf(fVar4,6.2831855);
    fVar4 = fVar4 + 6.2831855;
  }
  fVar4 = fVar4 - fVar5;
  if (6.2831855 < fVar4) {
    fVar4 = fmodf(fVar4,6.2831855);
  }
  else if (fVar4 < 0.0) {
    fVar4 = fmodf(fVar4,6.2831855);
    fVar4 = fVar4 + 6.2831855;
  }
  return fVar4;
}


/* ---- 0x180001c60  GetRealPosition  (122 bytes)   [名称未经人工确认] ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

float * __cdecl util::GetRealPosition(float *__return_storage_ptr__,longlong *param_2)

{
  TESWorldSpace *pTVar1;
  float *pfVar2;
  float local_28;
  float local_24;
  float local_20;
  float local_18 [4];
  
  *(undefined8 *)__return_storage_ptr__ = *(undefined8 *)((longlong)param_2 + 0x54);
  __return_storage_ptr__[2] = *(float *)((longlong)param_2 + 0x5c);
  pTVar1 = RE::TESObjectREFR::GetWorldspace(param_2);
  if (pTVar1 != (TESWorldSpace *)0x0) {
    local_28 = (pTVar1->worldMapOffsetData).mapOffsetX;
    local_24 = (pTVar1->worldMapOffsetData).mapOffsetY;
    local_20 = (pTVar1->worldMapOffsetData).mapOffsetZ;
    pfVar2 = RE::NiPoint3::operator*
                       ((NiPoint3 *)&local_28,local_18,(pTVar1->worldMapOffsetData).mapScale);
    RE::NiPoint3::operator+=((NiPoint3 *)__return_storage_ptr__,pfVar2);
  }
  return __return_storage_ptr__;
}


/* ---- 0x180001ce0  GetDistanceBetween  (245 bytes)   [名称未经人工确认] ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

float __cdecl util::GetDistanceBetween(longlong *param_1,longlong *param_2)

{
  TESWorldSpace *pTVar1;
  float *pfVar2;
  float fVar3;
  float local_48;
  float local_44;
  float local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined8 local_28;
  undefined4 local_20;
  float local_18 [4];
  
  local_28 = *(undefined8 *)((longlong)param_1 + 0x54);
  local_20 = *(undefined4 *)((longlong)param_1 + 0x5c);
  pTVar1 = RE::TESObjectREFR::GetWorldspace(param_1);
  if (pTVar1 != (TESWorldSpace *)0x0) {
    local_48 = (pTVar1->worldMapOffsetData).mapOffsetX;
    local_44 = (pTVar1->worldMapOffsetData).mapOffsetY;
    local_40 = (pTVar1->worldMapOffsetData).mapOffsetZ;
    pfVar2 = RE::NiPoint3::operator*
                       ((NiPoint3 *)&local_48,(float *)&local_38,
                        (pTVar1->worldMapOffsetData).mapScale);
    RE::NiPoint3::operator+=((NiPoint3 *)&local_28,pfVar2);
  }
  local_38 = *(undefined8 *)((longlong)param_2 + 0x54);
  local_30 = *(undefined4 *)((longlong)param_2 + 0x5c);
  pTVar1 = RE::TESObjectREFR::GetWorldspace(param_2);
  if (pTVar1 != (TESWorldSpace *)0x0) {
    local_48 = (pTVar1->worldMapOffsetData).mapOffsetX;
    local_44 = (pTVar1->worldMapOffsetData).mapOffsetY;
    local_40 = (pTVar1->worldMapOffsetData).mapOffsetZ;
    pfVar2 = RE::NiPoint3::operator*
                       ((NiPoint3 *)&local_48,local_18,(pTVar1->worldMapOffsetData).mapScale);
    RE::NiPoint3::operator+=((NiPoint3 *)&local_38,pfVar2);
  }
  fVar3 = RE::NiPoint3::GetDistance((NiPoint3 *)&local_28,(float *)&local_38);
  return fVar3;
}


/* ---- 0x180001de0  GetHeightDifferenceBetween  (242 bytes)   [名称未经人工确认] ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

float __cdecl util::GetHeightDifferenceBetween(longlong *param_1,longlong *param_2)

{
  TESWorldSpace *pTVar1;
  float *pfVar2;
  float local_48;
  float local_44;
  float local_40;
  undefined8 local_38;
  float local_30;
  undefined8 local_28;
  float local_20;
  float local_18 [4];
  
  local_28 = *(undefined8 *)((longlong)param_1 + 0x54);
  local_20 = *(float *)((longlong)param_1 + 0x5c);
  pTVar1 = RE::TESObjectREFR::GetWorldspace(param_1);
  if (pTVar1 != (TESWorldSpace *)0x0) {
    local_48 = (pTVar1->worldMapOffsetData).mapOffsetX;
    local_44 = (pTVar1->worldMapOffsetData).mapOffsetY;
    local_40 = (pTVar1->worldMapOffsetData).mapOffsetZ;
    pfVar2 = RE::NiPoint3::operator*
                       ((NiPoint3 *)&local_48,(float *)&local_38,
                        (pTVar1->worldMapOffsetData).mapScale);
    RE::NiPoint3::operator+=((NiPoint3 *)&local_28,pfVar2);
  }
  local_38 = *(undefined8 *)((longlong)param_2 + 0x54);
  local_30 = *(float *)((longlong)param_2 + 0x5c);
  pTVar1 = RE::TESObjectREFR::GetWorldspace(param_2);
  if (pTVar1 != (TESWorldSpace *)0x0) {
    local_48 = (pTVar1->worldMapOffsetData).mapOffsetX;
    local_44 = (pTVar1->worldMapOffsetData).mapOffsetY;
    local_40 = (pTVar1->worldMapOffsetData).mapOffsetZ;
    pfVar2 = RE::NiPoint3::operator*
                       ((NiPoint3 *)&local_48,local_18,(pTVar1->worldMapOffsetData).mapScale);
    RE::NiPoint3::operator+=((NiPoint3 *)&local_38,pfVar2);
  }
  return local_30 - local_20;
}


/* ---- 0x180002470  QuestItem  (66 bytes)   [名称未经人工确认] ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

undefined8 * __thiscall
QuestItem::QuestItem
          (QuestItem *this,TESObjectREFR *param_1,Type param_2,undefined8 *param_3,bool param_4,
          int param_5)

{
  *(TESObjectREFR **)this = param_1;
  *(Type *)(this + 8) = param_2;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(this + 0x10),
             param_3);
  this[0x30] = (QuestItem)param_4;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(int *)(this + 0x50) = param_5;
  return (undefined8 *)this;
}


/* ---- 0x180002520  FUN_180002520  (5 bytes) ---- */

void FUN_180002520(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x20) = 0;
  return;
}


/* ---- 0x180002a90  FUN_180002a90  (20 bytes) ---- */

longlong FUN_180002a90(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  uint7 uVar2;
  
  plVar1 = *(longlong **)(param_1 + 0x40);
  uVar2 = (uint7)((ulonglong)plVar1 >> 8);
  if ((plVar1 != (longlong *)0x0) && (param_2 == *plVar1)) {
    return CONCAT71(uVar2,1);
  }
  return (ulonglong)uVar2 << 8;
}


/* ---- 0x180002ab0  FUN_180002ab0  (8 bytes) ---- */

undefined * FUN_180002ab0(void)

{
  return &DAT_1801d94c8;
}


/* ---- 0x180003310  FUN_180003310  (10 bytes) ---- */

undefined8 * FUN_180003310(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


/* ---- 0x180003320  ~QuestItem  (32 bytes)   [名称未经人工确认] ---- */

void __thiscall QuestItem::~QuestItem(QuestItem *this)

{
  FUN_180007d20((longlong *)(this + 0x38));
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(this + 0x10));
  return;
}


/* ---- 0x180003340  operator=  (239 bytes)   [名称未经人工确认] ---- */

undefined8 * __thiscall QuestItem::operator=(QuestItem *this,undefined8 *param_1)

{
  QuestItem *pQVar1;
  QuestItem *pQVar2;
  void *pvVar3;
  void *_Memory;
  
  *(undefined8 *)this = *param_1;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(this + 0x10),
             param_1 + 2);
  pQVar1 = (QuestItem *)(param_1 + 7);
  pQVar2 = this + 0x38;
  this[0x30] = *(QuestItem *)(param_1 + 6);
  if (pQVar2 != pQVar1) {
    pvVar3 = *(void **)pQVar2;
    if (pvVar3 != (void *)0x0) {
      _Memory = pvVar3;
      if ((0xfff < (*(longlong *)(this + 0x48) - (longlong)pvVar3 & 0xfffffffffffffff8U)) &&
         (_Memory = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      free(_Memory);
      *(longlong *)pQVar2 = 0;
      *(undefined8 *)(this + 0x40) = 0;
      *(undefined8 *)(this + 0x48) = 0;
    }
    *(longlong *)pQVar2 = *(longlong *)pQVar1;
    *(undefined8 *)(this + 0x40) = param_1[8];
    *(undefined8 *)(this + 0x48) = param_1[9];
    *(longlong *)pQVar1 = 0;
    param_1[8] = 0;
    param_1[9] = 0;
  }
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 10);
  return (undefined8 *)this;
}


/* ---- 0x1800049f0  FUN_1800049f0  (36 bytes) ---- */

undefined8 FUN_1800049f0(undefined8 param_1,longlong *param_2,longlong *param_3)

{
  undefined7 uVar1;
  
  param_3 = (longlong *)*param_3;
  uVar1 = (undefined7)((ulonglong)param_3 >> 8);
  if ((longlong *)*param_2 == (longlong *)0x0) {
    return CONCAT71(uVar1,param_3 != (longlong *)0x0);
  }
  if (param_3 != (longlong *)0x0) {
    return CONCAT71((int7)((ulonglong)*param_3 >> 8),*(longlong *)*param_2 != *param_3);
  }
  return CONCAT71(uVar1,1);
}


/* ---- 0x180004bc0  FUN_180004bc0  (122 bytes) ---- */

undefined8 FUN_180004bc0(longlong param_1,undefined8 param_2)

{
  char cVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined7 extraout_var;
  undefined **local_48;
  undefined8 local_40;
  undefined ***local_10;
  
  uVar3 = (**(code **)(**(longlong **)(param_1 + 0xd0) + 0x7c8))();
  if ((char)uVar3 != '\0') {
    return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  local_10 = (undefined ***)0x0;
  cVar1 = FUN_1800088e0();
  if (cVar1 != '\0') {
    local_48 = std::
               _Func_impl_no_alloc<class_`private:_bool___cdecl_CNO::HUDMarkerManager::IsPlayerAllyOfFaction(class_RE::TESFaction_const*___ptr64)const___ptr64'::`2'::<lambda_1>,bool,class_RE::TESFaction*___ptr64,signed_char>
               ::vftable;
    local_10 = &local_48;
    local_40 = param_2;
  }
  bVar2 = RE::Actor::VisitFactions(*(Actor **)(param_1 + 0xd0),(longlong *)&local_48);
  return CONCAT71(extraout_var,bVar2);
}


/* ---- 0x180004c40  FUN_180004c40  (94 bytes) ---- */

ulonglong FUN_180004c40(longlong *param_1,longlong param_2,char param_3)

{
  ulonglong in_RAX;
  longlong *plVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  
  uVar3 = *param_1;
  if ((param_2 == uVar3) && ('\0' < param_3)) {
LAB_180004c97:
    return CONCAT71((int7)(in_RAX >> 8),1);
  }
  plVar1 = (longlong *)(param_2 + 0x38);
  if ((*(longlong *)(param_2 + 0x40) != 0) || (*plVar1 != 0)) {
    for (; plVar1 != (longlong *)0x0; plVar1 = (longlong *)plVar1[1]) {
      puVar2 = (undefined8 *)*plVar1;
      in_RAX = RE::TESForm::As<RE::TESFaction,void>((TESForm *)*puVar2);
      if ((in_RAX == uVar3) && (1 < *(int *)((longlong)puVar2 + 0xc))) goto LAB_180004c97;
    }
  }
  return in_RAX & 0xffffffffffffff00;
}


/* ---- 0x180004ca0  FUN_180004ca0  (10 bytes) ---- */

undefined8 * FUN_180004ca0(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


/* ---- 0x180004cb0  FUN_180004cb0  (44 bytes) ---- */

void FUN_180004cb0(longlong *param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)param_1[7];
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x20))(plVar1,plVar1 != param_1);
    param_1[7] = 0;
  }
  return;
}


/* ---- 0x180004ce0  FUN_180004ce0  (71 bytes) ---- */

void FUN_180004ce0(longlong param_1,undefined8 param_2)

{
  char cVar1;
  undefined **local_48;
  undefined8 local_40;
  undefined ***local_10;
  
  local_10 = (undefined ***)0x0;
  cVar1 = FUN_180008910();
  if (cVar1 != '\0') {
    local_48 = std::
               _Func_impl_no_alloc<class_`private:_bool___cdecl_CNO::HUDMarkerManager::IsPlayerOpponentOfFaction(class_RE::TESFaction_const*___ptr64)const___ptr64'::`2'::<lambda_1>,bool,class_RE::TESFaction*___ptr64,signed_char>
               ::vftable;
    local_10 = &local_48;
    local_40 = param_2;
  }
  RE::Actor::VisitFactions(*(Actor **)(param_1 + 0xd0),(longlong *)&local_48);
  return;
}


/* ---- 0x180004d30  FUN_180004d30  (94 bytes) ---- */

ulonglong FUN_180004d30(longlong *param_1,longlong param_2,char param_3)

{
  ulonglong in_RAX;
  longlong *plVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  
  uVar3 = *param_1;
  if ((param_2 == uVar3) && (param_3 < '\0')) {
LAB_180004d87:
    return CONCAT71((int7)(in_RAX >> 8),1);
  }
  plVar1 = (longlong *)(param_2 + 0x38);
  if ((*(longlong *)(param_2 + 0x40) != 0) || (*plVar1 != 0)) {
    for (; plVar1 != (longlong *)0x0; plVar1 = (longlong *)plVar1[1]) {
      puVar2 = (undefined8 *)*plVar1;
      in_RAX = RE::TESForm::As<RE::TESFaction,void>((TESForm *)*puVar2);
      if ((in_RAX == uVar3) && (*(int *)((longlong)puVar2 + 0xc) == 1)) goto LAB_180004d87;
    }
  }
  return in_RAX & 0xffffffffffffff00;
}


/* ---- 0x180004d90  FUN_180004d90  (10 bytes) ---- */

undefined8 * FUN_180004d90(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


/* ---- 0x180004ff0  FUN_180004ff0  (187 bytes) ---- */

void FUN_180004ff0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  char cVar1;
  undefined1 auStack_78 [32];
  undefined8 uStack_58;
  undefined4 uStack_48;
  undefined8 *puStack_40;
  undefined8 auStack_38 [3];
  ulonglong uStack_20;
  
  uStack_20 = __security_cookie ^ (ulonglong)auStack_78;
  uStack_48 = 0;
  puStack_40 = param_2;
  FUN_180045700(param_2);
  uStack_48 = 1;
  __builtin_array_init_helper_eh<RE::GFxValue>(auStack_38);
  uStack_58 = 0;
  cVar1 = RE::GFxValue::Invoke(param_1,*param_3,param_2);
  if (cVar1 == '\0') {
    _eh_vector_destructor_iterator_(auStack_38,0x18,1,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(auStack_38,0x18,1,RE::GFxValue::~GFxValue);
  }
  __security_check_cookie(uStack_20 ^ (ulonglong)auStack_78);
  return;
}


/* ---- 0x180005170  FUN_180005170  (282 bytes) ---- */

void FUN_180005170(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  float *param_5,float *param_6,uint *param_7)

{
  char cVar1;
  undefined1 auStack_b8 [32];
  undefined8 uStack_98;
  undefined4 uStack_88;
  undefined8 *puStack_80;
  undefined1 auStack_78 [24];
  undefined1 auStack_60 [24];
  undefined1 auStack_48 [24];
  undefined1 auStack_30 [24];
  ulonglong uStack_18;
  
  uStack_18 = __security_cookie ^ (ulonglong)auStack_b8;
  uStack_88 = 0;
  puStack_80 = param_2;
  FUN_180045700(param_2);
  uStack_88 = 1;
  RE::GFxValue::GFxValue(auStack_78,(char *)*param_4);
  RE::GFxValue::GFxValue(auStack_60,(double)*param_5);
  RE::GFxValue::GFxValue(auStack_48,(double)*param_6);
  RE::GFxValue::GFxValue(auStack_30,(double)*param_7);
  uStack_98 = 4;
  cVar1 = RE::GFxValue::Invoke(param_1,*param_3,param_2);
  if (cVar1 == '\0') {
    _eh_vector_destructor_iterator_(auStack_78,0x18,4,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(auStack_78,0x18,4,RE::GFxValue::~GFxValue);
  }
  __security_check_cookie(uStack_18 ^ (ulonglong)auStack_b8);
  return;
}


/* ---- 0x180005290  FUN_180005290  (308 bytes) ---- */

void FUN_180005290(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,int *param_4,
                  undefined8 *param_5,undefined8 param_6,undefined8 *param_7,int *param_8)

{
  char cVar1;
  undefined1 auStack_e8 [32];
  undefined8 uStack_c8;
  undefined4 uStack_b8;
  undefined8 *puStack_b0;
  undefined1 auStack_a8 [24];
  undefined1 auStack_90 [24];
  undefined1 auStack_78 [24];
  undefined1 auStack_60 [24];
  undefined1 auStack_48 [32];
  ulonglong uStack_28;
  
  uStack_28 = __security_cookie ^ (ulonglong)auStack_e8;
  uStack_b8 = 0;
  puStack_b0 = param_2;
  FUN_180045700(param_2);
  uStack_b8 = 1;
  RE::GFxValue::GFxValue(auStack_a8,(double)*param_4);
  RE::GFxValue::GFxValue(auStack_90,(char *)*param_5);
  RE::GFxValue::GFxValue(auStack_78,*(bool *)param_6);
  RE::GFxValue::GFxValue(auStack_60,param_7);
  RE::GFxValue::GFxValue(auStack_48,(double)*param_8);
  uStack_c8 = 5;
  cVar1 = RE::GFxValue::Invoke(param_1,*param_3,param_2);
  if (cVar1 == '\0') {
    _eh_vector_destructor_iterator_(auStack_a8,0x18,5,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(auStack_a8,0x18,5,RE::GFxValue::~GFxValue);
  }
  __security_check_cookie(uStack_28 ^ (ulonglong)auStack_e8);
  return;
}


/* ---- 0x1800053d0  FUN_1800053d0  (17 bytes) ---- */

undefined8 * FUN_1800053d0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = *param_2;
  *param_2 = 0;
  *param_1 = uVar1;
  return param_1;
}


/* ---- 0x1800053f0  FUN_1800053f0  (70 bytes) ---- */

undefined8 * FUN_1800053f0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  void *_Memory;
  
  uVar1 = *param_2;
  *param_2 = 0;
  _Memory = (void *)*param_1;
  *param_1 = uVar1;
  if (_Memory != (void *)0x0) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
               ((longlong)_Memory + 0x20));
    free(_Memory);
  }
  return param_1;
}


/* ---- 0x180005450  FUN_180005450  (8 bytes) ---- */

undefined * FUN_180005450(void)

{
  return &DAT_1801d94c8;
}


/* ---- 0x180005480  FUN_180005480  (161 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void FUN_180005480(longlong *param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4,
                  undefined4 *param_5,undefined8 *param_6)

{
  Marker *this;
  undefined8 *local_18;
  undefined8 local_10;
  
  this = (Marker *)param_1[1];
  if (this != (Marker *)param_1[2]) {
    local_18 = param_6;
    if (0xf < (ulonglong)param_6[3]) {
      local_18 = (undefined8 *)*param_6;
    }
    local_10 = param_6[2];
    CNO::Compass::Marker::CNO__Compass__Marker__Marker
              (this,(longlong *)*param_2,(float)*param_3,*param_4,*param_5,&local_18);
    param_1[1] = param_1[1] + 0x40;
    return;
  }
  FUN_1800080d0(param_1,(undefined4 *)this,param_2,param_3,param_4,param_5,param_6);
  return;
}


/* ---- 0x180005530  FUN_180005530  (4 bytes) ---- */

undefined8 FUN_180005530(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180005540  FUN_180005540  (50 bytes) ---- */

undefined8 * FUN_180005540(undefined8 *param_1,undefined8 *param_2,ulonglong *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined1 (*pauVar3) [32];
  
  lVar1 = param_2[1];
  pauVar3 = (undefined1 (*) [32])*param_2;
  uVar2 = *param_3;
  *param_1 = pauVar3;
  pauVar3 = `anonymous_namespace'::
            __std_find_trivial_impl<_anonymous_namespace_::_Find_traits_8,unsigned___int64>
                      (pauVar3,(undefined1 (*) [32])
                               (*pauVar3 + (lVar1 - (longlong)pauVar3 >> 3) * 8),uVar2);
  *param_1 = pauVar3;
  return param_1;
}


/* ---- 0x180005580  FUN_180005580  (4 bytes) ---- */

undefined8 FUN_180005580(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180005590  FUN_180005590  (4 bytes) ---- */

undefined8 FUN_180005590(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x1800055a0  FUN_1800055a0  (5 bytes) ---- */

undefined8 FUN_1800055a0(longlong param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


/* ---- 0x1800055b0  FUN_1800055b0  (4 bytes) ---- */

undefined1 FUN_1800055b0(undefined1 *param_1)

{
  return *param_1;
}


/* ---- 0x1800055c0  FUN_1800055c0  (6 bytes) ---- */

byte FUN_1800055c0(byte *param_1)

{
  return *param_1 & 1;
}


/* ---- 0x1800055d0  FUN_1800055d0  (122 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void FUN_1800055d0(longlong *param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4,
                  undefined4 *param_5,undefined8 *param_6)

{
  Marker *this;
  
  this = (Marker *)param_1[1];
  if (this != (Marker *)param_1[2]) {
    CNO::Compass::Marker::CNO__Compass__Marker__Marker
              (this,(longlong *)*param_2,(float)*param_3,*param_4,*param_5,param_6);
    param_1[1] = param_1[1] + 0x40;
    return;
  }
  FUN_180008320(param_1,(undefined4 *)this,param_2,param_3,param_4,param_5,param_6);
  return;
}


/* ---- 0x180005650  FUN_180005650  (161 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void FUN_180005650(longlong *param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4,
                  undefined4 *param_5,undefined8 *param_6)

{
  Marker *this;
  undefined8 *local_18;
  undefined8 local_10;
  
  this = (Marker *)param_1[1];
  if (this != (Marker *)param_1[2]) {
    local_18 = param_6;
    if (0xf < (ulonglong)param_6[3]) {
      local_18 = (undefined8 *)*param_6;
    }
    local_10 = param_6[2];
    CNO::Compass::Marker::CNO__Compass__Marker__Marker
              (this,(longlong *)*param_2,(float)*param_3,*param_4,*param_5,&local_18);
    param_1[1] = param_1[1] + 0x40;
    return;
  }
  FUN_180008520(param_1,(undefined4 *)this,param_2,param_3,param_4,param_5,param_6);
  return;
}


/* ---- 0x180005700  FUN_180005700  (142 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void FUN_180005700(longlong *param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4,
                  undefined4 *param_5)

{
  Marker *this;
  undefined1 *local_18;
  undefined8 local_10;
  
  this = (Marker *)param_1[1];
  if (this != (Marker *)param_1[2]) {
    local_18 = &s_;
    local_10 = 0;
    CNO::Compass::Marker::CNO__Compass__Marker__Marker
              (this,(longlong *)*param_2,(float)*param_3,*param_4,*param_5,&local_18);
    param_1[1] = param_1[1] + 0x40;
    return;
  }
  FUN_180008730(param_1,(undefined4 *)this,param_2,param_3,param_4,param_5);
  return;
}


/* ---- 0x180005790  FUN_180005790  (4 bytes) ---- */

undefined8 FUN_180005790(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800057a0  FUN_1800057a0  (5 bytes) ---- */

longlong FUN_1800057a0(longlong param_1)

{
  return param_1 + 8;
}


/* ---- 0x180005820  FUN_180005820  (11 bytes) ---- */

undefined8 * FUN_180005820(undefined8 *param_1)

{
  *param_1 = 0;
  return param_1;
}


/* ---- 0x1800058b0  FUN_1800058b0  (4 bytes) ---- */

undefined8 FUN_1800058b0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800058c0  FUN_1800058c0  (50 bytes) ---- */

undefined8 * FUN_1800058c0(undefined8 *param_1,undefined8 *param_2)

{
  char cVar1;
  
  param_1[7] = 0;
  cVar1 = FUN_1800088e0();
  if (cVar1 != '\0') {
    *param_1 = std::
               _Func_impl_no_alloc<class_`private:_bool___cdecl_CNO::HUDMarkerManager::IsPlayerAllyOfFaction(class_RE::TESFaction_const*___ptr64)const___ptr64'::`2'::<lambda_1>,bool,class_RE::TESFaction*___ptr64,signed_char>
               ::vftable;
    param_1[1] = *param_2;
    param_1[7] = param_1;
  }
  return param_1;
}


/* ---- 0x180005900  FUN_180005900  (50 bytes) ---- */

undefined8 * FUN_180005900(undefined8 *param_1,undefined8 *param_2)

{
  char cVar1;
  
  param_1[7] = 0;
  cVar1 = FUN_180008910();
  if (cVar1 != '\0') {
    *param_1 = std::
               _Func_impl_no_alloc<class_`private:_bool___cdecl_CNO::HUDMarkerManager::IsPlayerOpponentOfFaction(class_RE::TESFaction_const*___ptr64)const___ptr64'::`2'::<lambda_1>,bool,class_RE::TESFaction*___ptr64,signed_char>
               ::vftable;
    param_1[1] = *param_2;
    param_1[7] = param_1;
  }
  return param_1;
}


/* ---- 0x180005940  FUN_180005940  (44 bytes) ---- */

void FUN_180005940(longlong *param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)param_1[7];
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x20))(plVar1,plVar1 != param_1);
    param_1[7] = 0;
  }
  return;
}


/* ---- 0x180005970  FUN_180005970  (10 bytes) ---- */

undefined8 FUN_180005970(longlong *param_1,longlong *param_2)

{
  return CONCAT71((int7)((ulonglong)*param_2 >> 8),*param_1 == *param_2);
}


/* ---- 0x180005980  FUN_180005980  (13 bytes) ---- */

undefined8 * FUN_180005980(undefined8 *param_1)

{
  *param_1 = *(undefined8 *)*param_1;
  return param_1;
}


/* ---- 0x180005990  FUN_180005990  (8 bytes) ---- */

longlong FUN_180005990(longlong *param_1)

{
  return *param_1 + 0x10;
}


/* ---- 0x1800059a0  FUN_1800059a0  (11 bytes) ---- */

undefined8 * FUN_1800059a0(longlong param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(param_1 + 8);
  return param_2;
}


/* ---- 0x1800059b0  FUN_1800059b0  (14 bytes) ---- */

undefined8 * FUN_1800059b0(longlong param_1,undefined8 *param_2)

{
  *param_2 = **(undefined8 **)(param_1 + 8);
  return param_2;
}


/* ---- 0x1800059c0  FUN_1800059c0  (94 bytes) ---- */

undefined8 FUN_1800059c0(longlong param_1,longlong *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong *plVar3;
  
  uVar1 = FUN_18000b9c0(param_2);
  plVar3 = (longlong *)
           (*(longlong *)(param_1 + 0x18) + (uVar1 & *(ulonglong *)(param_1 + 0x30)) * 0x10);
  lVar2 = plVar3[1];
  if (lVar2 != *(longlong *)(param_1 + 8)) {
    if (*param_2 == *(longlong *)(lVar2 + 0x10)) goto LAB_180005a13;
    while (lVar2 != *plVar3) {
      lVar2 = *(longlong *)(lVar2 + 8);
      if (*param_2 == *(longlong *)(lVar2 + 0x10)) {
        return CONCAT71((int7)((ulonglong)lVar2 >> 8),lVar2 != 0);
      }
    }
  }
  lVar2 = 0;
LAB_180005a13:
  return CONCAT71((int7)((ulonglong)lVar2 >> 8),lVar2 != 0);
}


/* ---- 0x180005a20  FUN_180005a20  (559 bytes) ---- */

void FUN_180005a20(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined8 *_Memory;
  ulonglong uVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *local_res8;
  longlong local_res10;
  longlong *local_res18;
  longlong local_res20;
  
  if (*(ulonglong *)(param_1 + 0x10) != 0) {
    plVar1 = *(longlong **)(param_1 + 8);
    if (*(ulonglong *)(param_1 + 0x10) < *(ulonglong *)(param_1 + 0x38) >> 3) {
      plVar2 = (longlong *)*plVar1;
      if (plVar2 != plVar1) {
        local_res8 = (longlong *)plVar2[1];
        lVar7 = *(longlong *)(param_1 + 0x18);
        local_res20 = lVar7;
        uVar4 = FUN_18000b9c0(plVar2 + 2);
        uVar4 = uVar4 & *(ulonglong *)(param_1 + 0x30);
        plVar8 = (longlong *)(lVar7 + uVar4 * 0x10);
        local_res10 = *(longlong *)(lVar7 + uVar4 * 0x10);
        local_res18 = (longlong *)plVar8[1];
        plVar5 = plVar2;
        do {
          plVar6 = (longlong *)*plVar5;
          FUN_180007d20(plVar5 + 10);
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(plVar5 + 5)
                    );
          free(plVar5);
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -1;
          if (plVar5 == local_res18) {
            plVar5 = local_res8;
            if ((longlong *)local_res10 == plVar2) {
              *plVar8 = (longlong)plVar1;
              plVar5 = plVar1;
            }
            plVar8[1] = (longlong)plVar5;
            while (plVar6 != plVar1) {
              uVar4 = FUN_18000b9c0(plVar6 + 2);
              plVar8 = (longlong *)(local_res20 + (uVar4 & *(ulonglong *)(param_1 + 0x30)) * 0x10);
              plVar2 = (longlong *)plVar8[1];
              plVar5 = plVar6;
              while( true ) {
                plVar6 = (longlong *)*plVar5;
                FUN_180007d20(plVar5 + 10);
                std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                _Tidy_deallocate((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                                 (plVar5 + 5));
                free(plVar5);
                *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -1;
                if (plVar5 == plVar2) break;
                plVar5 = plVar6;
                if (plVar6 == plVar1) goto LAB_180005b05;
              }
              *plVar8 = (longlong)plVar1;
              plVar8[1] = (longlong)plVar1;
            }
            goto LAB_180005b09;
          }
          plVar5 = plVar6;
        } while (plVar6 != plVar1);
        if ((longlong *)local_res10 == plVar2) {
LAB_180005b05:
          *plVar8 = (longlong)plVar6;
        }
LAB_180005b09:
        *local_res8 = (longlong)plVar6;
        plVar6[1] = (longlong)local_res8;
        return;
      }
    }
    else {
      *(undefined8 *)plVar1[1] = 0;
      _Memory = (undefined8 *)*plVar1;
      while (_Memory != (undefined8 *)0x0) {
        puVar3 = (undefined8 *)*_Memory;
        FUN_180007d20(_Memory + 10);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(_Memory + 5))
        ;
        free(_Memory);
        _Memory = puVar3;
      }
      *(undefined8 *)*(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_1 + 8);
      *(longlong *)(*(longlong *)(param_1 + 8) + 8) = *(longlong *)(param_1 + 8);
      *(undefined8 *)(param_1 + 0x10) = 0;
      local_res8 = *(longlong **)(param_1 + 8);
      FUN_180006be0(*(undefined8 **)(param_1 + 0x18),*(undefined8 **)(param_1 + 0x20),&local_res8);
    }
  }
  return;
}


/* ---- 0x180005c50  FUN_180005c50  (29 bytes) ---- */

longlong FUN_180005c50(float *param_1,longlong *param_2)

{
  longlong *plVar1;
  undefined8 auStack_18 [3];
  
  plVar1 = FUN_180006c70(param_1,auStack_18,param_2);
  return *plVar1 + 0x18;
}


/* ---- 0x180005c70  FUN_180005c70  (94 bytes) ---- */

undefined8 FUN_180005c70(longlong param_1,longlong *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong *plVar3;
  
  uVar1 = FUN_18000b9c0(param_2);
  plVar3 = (longlong *)
           (*(longlong *)(param_1 + 0x18) + (uVar1 & *(ulonglong *)(param_1 + 0x30)) * 0x10);
  lVar2 = plVar3[1];
  if (lVar2 != *(longlong *)(param_1 + 8)) {
    if (*param_2 == *(longlong *)(lVar2 + 0x10)) goto LAB_180005cc3;
    while (lVar2 != *plVar3) {
      lVar2 = *(longlong *)(lVar2 + 8);
      if (*param_2 == *(longlong *)(lVar2 + 0x10)) {
        return CONCAT71((int7)((ulonglong)lVar2 >> 8),lVar2 != 0);
      }
    }
  }
  lVar2 = 0;
LAB_180005cc3:
  return CONCAT71((int7)((ulonglong)lVar2 >> 8),lVar2 != 0);
}


/* ---- 0x180005cd0  FUN_180005cd0  (559 bytes) ---- */

void FUN_180005cd0(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined8 *_Memory;
  ulonglong uVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *local_res8;
  longlong local_res10;
  longlong *local_res18;
  longlong local_res20;
  
  if (*(ulonglong *)(param_1 + 0x10) != 0) {
    plVar1 = *(longlong **)(param_1 + 8);
    if (*(ulonglong *)(param_1 + 0x10) < *(ulonglong *)(param_1 + 0x38) >> 3) {
      plVar2 = (longlong *)*plVar1;
      if (plVar2 != plVar1) {
        local_res8 = (longlong *)plVar2[1];
        lVar7 = *(longlong *)(param_1 + 0x18);
        local_res20 = lVar7;
        uVar4 = FUN_18000b9c0(plVar2 + 2);
        uVar4 = uVar4 & *(ulonglong *)(param_1 + 0x30);
        plVar8 = (longlong *)(lVar7 + uVar4 * 0x10);
        local_res10 = *(longlong *)(lVar7 + uVar4 * 0x10);
        local_res18 = (longlong *)plVar8[1];
        plVar5 = plVar2;
        do {
          plVar6 = (longlong *)*plVar5;
          FUN_18000c620(plVar5 + 6);
          FUN_18000c770(plVar5 + 4);
          free(plVar5);
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -1;
          if (plVar5 == local_res18) {
            plVar5 = local_res8;
            if ((longlong *)local_res10 == plVar2) {
              *plVar8 = (longlong)plVar1;
              plVar5 = plVar1;
            }
            plVar8[1] = (longlong)plVar5;
            while (plVar6 != plVar1) {
              uVar4 = FUN_18000b9c0(plVar6 + 2);
              plVar8 = (longlong *)(local_res20 + (uVar4 & *(ulonglong *)(param_1 + 0x30)) * 0x10);
              plVar2 = (longlong *)plVar8[1];
              plVar5 = plVar6;
              while( true ) {
                plVar6 = (longlong *)*plVar5;
                FUN_18000c620(plVar5 + 6);
                FUN_18000c770(plVar5 + 4);
                free(plVar5);
                *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -1;
                if (plVar5 == plVar2) break;
                plVar5 = plVar6;
                if (plVar6 == plVar1) goto LAB_180005db5;
              }
              *plVar8 = (longlong)plVar1;
              plVar8[1] = (longlong)plVar1;
            }
            goto LAB_180005db9;
          }
          plVar5 = plVar6;
        } while (plVar6 != plVar1);
        if ((longlong *)local_res10 == plVar2) {
LAB_180005db5:
          *plVar8 = (longlong)plVar6;
        }
LAB_180005db9:
        *local_res8 = (longlong)plVar6;
        plVar6[1] = (longlong)local_res8;
        return;
      }
    }
    else {
      *(undefined8 *)plVar1[1] = 0;
      _Memory = (undefined8 *)*plVar1;
      while (_Memory != (undefined8 *)0x0) {
        puVar3 = (undefined8 *)*_Memory;
        FUN_18000c620(_Memory + 6);
        FUN_18000c770(_Memory + 4);
        free(_Memory);
        _Memory = puVar3;
      }
      *(undefined8 *)*(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_1 + 8);
      *(longlong *)(*(longlong *)(param_1 + 8) + 8) = *(longlong *)(param_1 + 8);
      *(undefined8 *)(param_1 + 0x10) = 0;
      local_res8 = *(longlong **)(param_1 + 8);
      FUN_180006fb0(*(undefined8 **)(param_1 + 0x18),*(undefined8 **)(param_1 + 0x20),&local_res8);
    }
  }
  return;
}


/* ---- 0x180005f00  FUN_180005f00  (29 bytes) ---- */

longlong FUN_180005f00(_Hash<std::_Umap_traits<RE::TESObjectREFR_*,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>,std::_Uhash_compare<RE::TESObjectREFR_*,std::hash<RE::TESObjectREFR_*>,std::equal_to<RE::TESObjectREFR_*>_>,std::allocator<std::pair<RE::TESObjectREFR_*_const,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>_>_>,0>_>
                       *param_1,longlong *param_2)

{
  longlong *plVar1;
  undefined8 auStack_18 [3];
  
  plVar1 = std::
           _Hash<std::_Umap_traits<RE::TESObjectREFR_*,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>,std::_Uhash_compare<RE::TESObjectREFR_*,std::hash<RE::TESObjectREFR_*>,std::equal_to<RE::TESObjectREFR_*>_>,std::allocator<std::pair<RE::TESObjectREFR_*_const,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>_>_>,0>_>
           ::_Try_emplace<RE::TESObjectREFR_*_const_&>(param_1,auStack_18,param_2);
  return *plVar1 + 0x18;
}


/* ---- 0x180005f40  FUN_180005f40  (11 bytes) ---- */

longlong FUN_180005f40(longlong *param_1,longlong param_2)

{
  return param_2 * 0x40 + *param_1;
}


/* ---- 0x180005f50  FUN_180005f50  (12 bytes) ---- */

longlong FUN_180005f50(longlong *param_1)

{
  return param_1[1] - *param_1 >> 6;
}


/* ---- 0x180005fb0  FUN_180005fb0  (8 bytes) ---- */

bool FUN_180005fb0(longlong *param_1)

{
  return *param_1 != 0;
}


/* ---- 0x180005fc0  FUN_180005fc0  (4 bytes) ---- */

undefined8 FUN_180005fc0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180005fd0  FUN_180005fd0  (47 bytes) ---- */

void FUN_180005fd0(undefined8 *param_1)

{
  void *_Memory;
  
  _Memory = (void *)*param_1;
  if (_Memory != (void *)0x0) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
               ((longlong)_Memory + 0x20));
    free(_Memory);
    return;
  }
  return;
}


/* ---- 0x180006000  FUN_180006000  (64 bytes) ---- */

undefined8 * FUN_180006000(undefined8 *param_1)

{
  void *_Memory;
  
  _Memory = (void *)*param_1;
  *param_1 = 0;
  if (_Memory != (void *)0x0) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
               ((longlong)_Memory + 0x20));
    free(_Memory);
  }
  return param_1;
}


/* ---- 0x180006040  FUN_180006040  (10 bytes) ---- */

undefined8 FUN_180006040(longlong *param_1,longlong *param_2)

{
  return CONCAT71((int7)((ulonglong)*param_2 >> 8),*param_1 == *param_2);
}


/* ---- 0x180006050  FUN_180006050  (12 bytes) ---- */

longlong FUN_180006050(longlong *param_1)

{
  return param_1[1] - *param_1 >> 3;
}


/* ---- 0x180006060  FUN_180006060  (5 bytes) ---- */

undefined8 FUN_180006060(longlong param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


/* ---- 0x180006070  FUN_180006070  (4 bytes) ---- */

undefined8 FUN_180006070(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180006080  FUN_180006080  (11 bytes) ---- */

undefined8 * FUN_180006080(longlong param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(param_1 + 8);
  return param_2;
}


/* ---- 0x180006090  FUN_180006090  (7 bytes) ---- */

undefined8 * FUN_180006090(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800060a0  FUN_1800060a0  (10 bytes) ---- */

undefined8 * FUN_1800060a0(undefined8 *param_1,undefined8 *param_2)

{
  *param_2 = *param_1;
  return param_2;
}


/* ---- 0x1800060b0  FUN_1800060b0  (30 bytes) ---- */

/* WARNING: Enum "DIALOGUE_TYPE": Some values do not have unique names */

void * FUN_1800060b0(longlong *param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  void *pvVar2;
  undefined8 *puVar3;
  longlong lVar4;
  code *pcVar5;
  longlong lVar6;
  void *pvVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  void *_Memory;
  undefined8 *puVar10;
  longlong lVar11;
  ulonglong uVar12;
  void *pvVar13;
  
  puVar3 = (undefined8 *)param_1[1];
  if (puVar3 != (undefined8 *)param_1[2]) {
    pvVar7 = (void *)*param_2;
    *puVar3 = pvVar7;
    param_1[1] = param_1[1] + 8;
    return pvVar7;
  }
  lVar4 = *param_1;
  lVar11 = (longlong)puVar3 - lVar4 >> 3;
  lVar6 = param_1[1] - lVar4 >> 3;
  if (lVar6 != 0x1fffffffffffffff) {
    uVar8 = param_1[2] - lVar4 >> 3;
    uVar1 = lVar6 + 1;
    if (0x1fffffffffffffff - (uVar8 >> 1) < uVar8) {
      uVar12 = 0xfffffffffffffff8;
      pvVar7 = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>
                         (0xfffffffffffffff8);
    }
    else {
      uVar8 = (uVar8 >> 1) + uVar8;
      uVar12 = uVar1;
      if (uVar1 <= uVar8) {
        uVar12 = uVar8;
      }
      if (0x1fffffffffffffff < uVar12) {
        FUN_180039810();
        pcVar5 = (code *)swi(3);
        pvVar7 = (void *)(*pcVar5)();
        return pvVar7;
      }
      uVar12 = uVar12 * 8;
      if (uVar12 == 0) {
        pvVar7 = (void *)0x0;
      }
      else if (uVar12 < 0x1000) {
        pvVar7 = operator_new(uVar12);
      }
      else {
        pvVar7 = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>(uVar12);
      }
    }
    *(undefined8 *)((longlong)pvVar7 + lVar11 * 8) = *param_2;
    puVar10 = (undefined8 *)param_1[1];
    pvVar2 = (void *)((longlong)pvVar7 + lVar11 * 8);
    puVar9 = (undefined8 *)*param_1;
    pvVar13 = pvVar7;
    if (puVar3 != puVar10) {
      std::_Copy_memmove<RE::BGSInstancedQuestObjective_*_*,RE::BGSInstancedQuestObjective_*_*>
                ((undefined8 *)*param_1,(longlong)puVar3,pvVar7);
      puVar10 = (undefined8 *)param_1[1];
      pvVar13 = (void *)((longlong)pvVar2 + 8);
      puVar9 = puVar3;
    }
    std::_Copy_memmove<RE::BGSInstancedQuestObjective_*_*,RE::BGSInstancedQuestObjective_*_*>
              (puVar9,(longlong)puVar10,pvVar13);
    pvVar13 = (void *)*param_1;
    if (pvVar13 != (void *)0x0) {
      _Memory = pvVar13;
      if ((0xfff < (param_1[2] - (longlong)pvVar13 & 0xfffffffffffffff8U)) &&
         (_Memory = *(void **)((longlong)pvVar13 + -8),
         0x1f < (ulonglong)((longlong)pvVar13 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      free(_Memory);
    }
    *param_1 = (longlong)pvVar7;
    param_1[1] = (longlong)((longlong)pvVar7 + uVar1 * 8);
    param_1[2] = uVar12 + (longlong)pvVar7;
    return pvVar2;
  }
  FUN_18000b330();
  pcVar5 = (code *)swi(3);
  pvVar7 = (void *)(*pcVar5)();
  return pvVar7;
}


/* ---- 0x180006190  FUN_180006190  (17 bytes) ---- */

undefined8 * FUN_180006190(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}


/* ---- 0x1800061b0  FUN_1800061b0  (8 bytes) ---- */

undefined8 FUN_1800061b0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x1800061c0  FUN_1800061c0  (29 bytes) ---- */

longlong * FUN_1800061c0(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x1800061e0  FUN_1800061e0  (14 bytes) ---- */

longlong * FUN_1800061e0(longlong *param_1)

{
  *param_1 = *(longlong *)(*param_1 + 8);
  return param_1;
}


/* ---- 0x1800061f0  FUN_1800061f0  (10 bytes) ---- */

undefined8 FUN_1800061f0(longlong *param_1,longlong *param_2)

{
  return CONCAT71((int7)((ulonglong)*param_2 >> 8),*param_1 != *param_2);
}


/* ---- 0x180006200  FUN_180006200  (4 bytes) ---- */

undefined8 FUN_180006200(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180006210  FUN_180006210  (8 bytes) ---- */

void FUN_180006210(undefined8 *param_1)

{
  *param_1 = 0;
  return;
}


/* ---- 0x180006220  FUN_180006220  (11 bytes) ---- */

undefined8 * FUN_180006220(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = 0;
  return param_2;
}


/* ---- 0x180006230  FUN_180006230  (27 bytes) ---- */

undefined8 * FUN_180006230(longlong *param_1,undefined8 *param_2)

{
  if ((param_1[1] == 0) && (*param_1 == 0)) {
    *param_2 = 0;
    return param_2;
  }
  *param_2 = param_1;
  return param_2;
}


/* ---- 0x180006250  FUN_180006250  (18 bytes) ---- */

char * FUN_180006250(longlong *param_1)

{
  char *pcVar1;
  
  pcVar1 = "";
  if ((char *)*param_1 != (char *)0x0) {
    pcVar1 = (char *)*param_1;
  }
  return pcVar1;
}


/* ---- 0x180006290  FUN_180006290  (4 bytes) ---- */

undefined8 FUN_180006290(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x1800062a0  FUN_1800062a0  (8 bytes) ---- */

bool FUN_1800062a0(longlong *param_1)

{
  return *param_1 != 0;
}


/* ---- 0x1800062b0  FUN_1800062b0  (39 bytes) ---- */

void FUN_1800062b0(longlong *param_1)

{
  if (*param_1 != 0) {
    RE::BSHandleRefObject::DecRefCount((BSHandleRefObject *)(*param_1 + 0x20));
    *param_1 = 0;
  }
  return;
}


/* ---- 0x1800062e0  FUN_1800062e0  (44 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

undefined8 *
FUN_1800062e0(BSPointerHandle<RE::TESObjectREFR,RE::BSUntypedPointerHandle<21,5>_> *param_1,
             undefined8 *param_2)

{
  *param_2 = 0;
  RE::BSPointerHandle<RE::TESObjectREFR,RE::BSUntypedPointerHandle<21,5>_>::get_smartptr
            (param_1,(NiPointer<RE::TESObjectREFR> *)param_2);
  return param_2;
}


/* ---- 0x180006310  FUN_180006310  (31 bytes) ---- */

longlong * FUN_180006310(longlong *param_1,void *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  void *pvVar3;
  void *_Dst;
  ulonglong uVar4;
  void *_Memory;
  longlong *_Dst_00;
  ulonglong uVar5;
  size_t _Size;
  
  _Size = 0xffffffffffffffff;
  do {
    _Size = _Size + 1;
  } while (*(char *)((longlong)param_2 + _Size) != '\0');
  uVar2 = param_1[3];
  if (uVar2 < _Size) {
    uVar5 = 0x7fffffffffffffff;
    if (0x7fffffffffffffff < _Size) {
                    /* WARNING: Subroutine does not return */
      std::_Xlen_string();
    }
    uVar4 = _Size | 0xf;
    if (uVar4 < 0x8000000000000000) {
      if (0x7fffffffffffffff - (uVar2 >> 1) < uVar2) {
        _Dst = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>
                         (0x8000000000000000);
      }
      else {
        uVar1 = uVar2 + (uVar2 >> 1);
        uVar5 = uVar4;
        if (uVar4 < uVar1) {
          uVar5 = uVar1;
        }
        uVar4 = uVar5 + 1;
        if (uVar4 == 0) {
          _Dst = (void *)0x0;
        }
        else if (uVar4 < 0x1000) {
          _Dst = operator_new(uVar4);
        }
        else {
          _Dst = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>(uVar4);
        }
      }
    }
    else {
      _Dst = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>
                       (0x8000000000000000);
    }
    param_1[2] = _Size;
    param_1[3] = uVar5;
    memcpy(_Dst,param_2,_Size);
    *(undefined1 *)((longlong)_Dst + _Size) = 0;
    if (0xf < uVar2) {
      pvVar3 = (void *)*param_1;
      _Memory = pvVar3;
      if ((0xfff < uVar2 + 1) &&
         (_Memory = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      free(_Memory);
    }
    *param_1 = (longlong)_Dst;
  }
  else {
    _Dst_00 = param_1;
    if (0xf < uVar2) {
      _Dst_00 = (longlong *)*param_1;
    }
    param_1[2] = _Size;
    memmove(_Dst_00,param_2,_Size);
    *(undefined1 *)((longlong)_Dst_00 + _Size) = 0;
  }
  return param_1;
}


/* ---- 0x180006330  FUN_180006330  (33 bytes) ---- */

void FUN_180006330(void *param_1)

{
  _eh_vector_destructor_iterator_(param_1,0x18,1,RE::GFxValue::~GFxValue);
  return;
}


/* ---- 0x1800063b0  FUN_1800063b0  (11 bytes) ---- */

undefined8 * FUN_1800063b0(undefined8 *param_1)

{
  *param_1 = 0;
  return param_1;
}


/* ---- 0x180006440  FUN_180006440  (125 bytes) ---- */

void FUN_180006440(undefined8 *param_1,undefined8 *param_2,undefined8 param_3)

{
  undefined1 auStack_68 [32];
  undefined8 uStack_48;
  undefined8 auStack_38 [3];
  ulonglong uStack_20;
  
  uStack_20 = __security_cookie ^ (ulonglong)auStack_68;
  __builtin_array_init_helper_eh<RE::GFxValue>(auStack_38);
  uStack_48 = 0;
  RE::GFxValue::Invoke(param_1,*param_2,param_3);
  _eh_vector_destructor_iterator_(auStack_38,0x18,1,RE::GFxValue::~GFxValue);
  __security_check_cookie(uStack_20 ^ (ulonglong)auStack_68);
  return;
}


/* ---- 0x180006590  FUN_180006590  (211 bytes) ---- */

void FUN_180006590(undefined8 *param_1,undefined8 *param_2,undefined8 param_3,undefined8 *param_4,
                  float *param_5,float *param_6,uint *param_7)

{
  undefined1 auStack_a8 [32];
  undefined8 uStack_88;
  undefined1 auStack_78 [24];
  undefined1 auStack_60 [24];
  undefined1 auStack_48 [24];
  undefined1 auStack_30 [24];
  ulonglong uStack_18;
  
  uStack_18 = __security_cookie ^ (ulonglong)auStack_a8;
  RE::GFxValue::GFxValue(auStack_78,(char *)*param_4);
  RE::GFxValue::GFxValue(auStack_60,(double)*param_5);
  RE::GFxValue::GFxValue(auStack_48,(double)*param_6);
  RE::GFxValue::GFxValue(auStack_30,(double)*param_7);
  uStack_88 = 4;
  RE::GFxValue::Invoke(param_1,*param_2,param_3);
  _eh_vector_destructor_iterator_(auStack_78,0x18,4,RE::GFxValue::~GFxValue);
  __security_check_cookie(uStack_18 ^ (ulonglong)auStack_a8);
  return;
}


/* ---- 0x1800067b0  FUN_1800067b0  (161 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void FUN_1800067b0(longlong *param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4,
                  undefined4 *param_5,undefined8 *param_6)

{
  Marker *this;
  undefined8 *local_18;
  undefined8 local_10;
  
  this = (Marker *)param_1[1];
  if (this != (Marker *)param_1[2]) {
    local_18 = param_6;
    if (0xf < (ulonglong)param_6[3]) {
      local_18 = (undefined8 *)*param_6;
    }
    local_10 = param_6[2];
    CNO::Compass::Marker::CNO__Compass__Marker__Marker
              (this,(longlong *)*param_2,(float)*param_3,*param_4,*param_5,&local_18);
    param_1[1] = param_1[1] + 0x40;
    return;
  }
  FUN_1800080d0(param_1,(undefined4 *)this,param_2,param_3,param_4,param_5,param_6);
  return;
}


/* ---- 0x1800068d0  FUN_1800068d0  (122 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void FUN_1800068d0(longlong *param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4,
                  undefined4 *param_5,undefined8 *param_6)

{
  Marker *this;
  
  this = (Marker *)param_1[1];
  if (this != (Marker *)param_1[2]) {
    CNO::Compass::Marker::CNO__Compass__Marker__Marker
              (this,(longlong *)*param_2,(float)*param_3,*param_4,*param_5,param_6);
    param_1[1] = param_1[1] + 0x40;
    return;
  }
  FUN_180008320(param_1,(undefined4 *)this,param_2,param_3,param_4,param_5,param_6);
  return;
}


/* ---- 0x180006960  FUN_180006960  (161 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void FUN_180006960(longlong *param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4,
                  undefined4 *param_5,undefined8 *param_6)

{
  Marker *this;
  undefined8 *local_18;
  undefined8 local_10;
  
  this = (Marker *)param_1[1];
  if (this != (Marker *)param_1[2]) {
    local_18 = param_6;
    if (0xf < (ulonglong)param_6[3]) {
      local_18 = (undefined8 *)*param_6;
    }
    local_10 = param_6[2];
    CNO::Compass::Marker::CNO__Compass__Marker__Marker
              (this,(longlong *)*param_2,(float)*param_3,*param_4,*param_5,&local_18);
    param_1[1] = param_1[1] + 0x40;
    return;
  }
  FUN_180008520(param_1,(undefined4 *)this,param_2,param_3,param_4,param_5,param_6);
  return;
}


/* ---- 0x180006a20  FUN_180006a20  (142 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void FUN_180006a20(longlong *param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4,
                  undefined4 *param_5)

{
  Marker *this;
  undefined1 *local_18;
  undefined8 local_10;
  
  this = (Marker *)param_1[1];
  if (this != (Marker *)param_1[2]) {
    local_18 = &s_;
    local_10 = 0;
    CNO::Compass::Marker::CNO__Compass__Marker__Marker
              (this,(longlong *)*param_2,(float)*param_3,*param_4,*param_5,&local_18);
    param_1[1] = param_1[1] + 0x40;
    return;
  }
  FUN_180008730(param_1,(undefined4 *)this,param_2,param_3,param_4,param_5);
  return;
}


/* ---- 0x180006c70  FUN_180006c70  (696 bytes) ---- */

undefined8 * FUN_180006c70(float *param_1,undefined8 *param_2,longlong *param_3)

{
  longlong *plVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  code *pcVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong *plVar10;
  float fVar11;
  
  uVar5 = FUN_18000b9c0(param_3);
  plVar1 = *(longlong **)
            (*(longlong *)(param_1 + 6) + 8 + (uVar5 & *(ulonglong *)(param_1 + 0xc)) * 0x10);
  plVar10 = *(longlong **)(param_1 + 2);
  if (plVar1 != plVar10) {
    lVar7 = plVar1[2];
    while (*param_3 != lVar7) {
      plVar10 = plVar1;
      if (plVar1 == *(longlong **)
                     (*(longlong *)(param_1 + 6) + (uVar5 & *(ulonglong *)(param_1 + 0xc)) * 0x10))
      goto LAB_180006cff;
      plVar1 = (longlong *)plVar1[1];
      lVar7 = plVar1[2];
    }
    plVar10 = (longlong *)*plVar1;
    if (plVar1 != (longlong *)0x0) {
      *param_2 = plVar1;
      *(undefined1 *)(param_2 + 1) = 0;
      return param_2;
    }
  }
LAB_180006cff:
  if (*(longlong *)(param_1 + 4) == 0x249249249249249) {
    std::_Xlength_error("unordered_map/set too long");
    pcVar4 = (code *)swi(3);
    puVar6 = (undefined8 *)(*pcVar4)();
    return puVar6;
  }
  puVar6 = (undefined8 *)operator_new(0x70);
  puVar6[2] = *param_3;
  puVar6[3] = 0;
  puVar6[4] = 0;
  puVar6[9] = 0;
  puVar6[0xd] = 0;
  puVar6[5] = 0;
  puVar6[6] = 0;
  puVar6[7] = 0;
  puVar6[8] = 0xf;
  *(undefined1 *)(puVar6 + 5) = 0;
  puVar6[10] = 0;
  puVar6[0xb] = 0;
  puVar6[0xc] = 0;
  uVar2 = *(ulonglong *)(param_1 + 0xe);
  fVar11 = (float)(*(longlong *)(param_1 + 4) + 1);
  if (*param_1 < fVar11 / (float)uVar2) {
    fVar11 = ceilf(fVar11 / *param_1);
    lVar7 = 0;
    if ((9.223372e+18 <= fVar11) && (fVar11 = fVar11 - 9.223372e+18, fVar11 < 9.223372e+18)) {
      lVar7 = -0x8000000000000000;
    }
    uVar8 = 8;
    if (8 < (ulonglong)((longlong)fVar11 + lVar7)) {
      uVar8 = (longlong)fVar11 + lVar7;
    }
    uVar9 = uVar2;
    if ((uVar2 < uVar8) && ((0x1ff < uVar2 || (uVar9 = uVar2 * 8, uVar2 * 8 < uVar8)))) {
      uVar9 = uVar8;
    }
    FUN_18000ab90((longlong)param_1,uVar9);
    plVar1 = *(longlong **)
              (*(longlong *)(param_1 + 6) + 8 + (*(ulonglong *)(param_1 + 0xc) & uVar5) * 0x10);
    plVar10 = *(longlong **)(param_1 + 2);
    if (plVar1 != plVar10) {
      lVar7 = plVar1[2];
      plVar10 = plVar1;
      while (puVar6[2] != lVar7) {
        if (plVar10 ==
            *(longlong **)
             (*(longlong *)(param_1 + 6) + (*(ulonglong *)(param_1 + 0xc) & uVar5) * 0x10))
        goto LAB_180006eb6;
        plVar10 = (longlong *)plVar10[1];
        lVar7 = plVar10[2];
      }
      plVar10 = (longlong *)*plVar10;
    }
  }
LAB_180006eb6:
  puVar3 = (undefined8 *)plVar10[1];
  *(longlong *)(param_1 + 4) = *(longlong *)(param_1 + 4) + 1;
  *puVar6 = plVar10;
  puVar6[1] = puVar3;
  *puVar3 = puVar6;
  plVar10[1] = (longlong)puVar6;
  uVar5 = *(ulonglong *)(param_1 + 0xc) & uVar5;
  lVar7 = *(longlong *)(param_1 + 6);
  plVar1 = *(longlong **)(lVar7 + uVar5 * 0x10);
  if (plVar1 == *(longlong **)(param_1 + 2)) {
    *(undefined8 **)(lVar7 + uVar5 * 0x10) = puVar6;
  }
  else {
    if (plVar1 == plVar10) {
      *(undefined8 **)(lVar7 + uVar5 * 0x10) = puVar6;
      goto LAB_180006f00;
    }
    if (*(undefined8 **)(lVar7 + 8 + uVar5 * 0x10) != puVar3) goto LAB_180006f00;
  }
  *(undefined8 **)(lVar7 + 8 + uVar5 * 0x10) = puVar6;
LAB_180006f00:
  *param_2 = puVar6;
  *(undefined1 *)(param_2 + 1) = 1;
  return param_2;
}


/* ---- 0x1800072f0  FUN_1800072f0  (696 bytes) ---- */

undefined8 * FUN_1800072f0(float *param_1,undefined8 *param_2,longlong *param_3)

{
  longlong *plVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  code *pcVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong *plVar10;
  float fVar11;
  
  uVar5 = FUN_18000c5e0(param_3);
  plVar1 = *(longlong **)
            (*(longlong *)(param_1 + 6) + 8 + (uVar5 & *(ulonglong *)(param_1 + 0xc)) * 0x10);
  plVar10 = *(longlong **)(param_1 + 2);
  if (plVar1 != plVar10) {
    lVar7 = plVar1[2];
    while (*param_3 != lVar7) {
      plVar10 = plVar1;
      if (plVar1 == *(longlong **)
                     (*(longlong *)(param_1 + 6) + (uVar5 & *(ulonglong *)(param_1 + 0xc)) * 0x10))
      goto LAB_18000737f;
      plVar1 = (longlong *)plVar1[1];
      lVar7 = plVar1[2];
    }
    plVar10 = (longlong *)*plVar1;
    if (plVar1 != (longlong *)0x0) {
      *param_2 = plVar1;
      *(undefined1 *)(param_2 + 1) = 0;
      return param_2;
    }
  }
LAB_18000737f:
  if (*(longlong *)(param_1 + 4) == 0x249249249249249) {
    std::_Xlength_error("unordered_map/set too long");
    pcVar4 = (code *)swi(3);
    puVar6 = (undefined8 *)(*pcVar4)();
    return puVar6;
  }
  puVar6 = (undefined8 *)operator_new(0x70);
  puVar6[2] = *param_3;
  puVar6[3] = 0;
  puVar6[4] = 0;
  puVar6[9] = 0;
  puVar6[0xd] = 0;
  puVar6[5] = 0;
  puVar6[6] = 0;
  puVar6[7] = 0;
  puVar6[8] = 0xf;
  *(undefined1 *)(puVar6 + 5) = 0;
  puVar6[10] = 0;
  puVar6[0xb] = 0;
  puVar6[0xc] = 0;
  uVar2 = *(ulonglong *)(param_1 + 0xe);
  fVar11 = (float)(*(longlong *)(param_1 + 4) + 1);
  if (*param_1 < fVar11 / (float)uVar2) {
    fVar11 = ceilf(fVar11 / *param_1);
    lVar7 = 0;
    if ((9.223372e+18 <= fVar11) && (fVar11 = fVar11 - 9.223372e+18, fVar11 < 9.223372e+18)) {
      lVar7 = -0x8000000000000000;
    }
    uVar8 = 8;
    if (8 < (ulonglong)((longlong)fVar11 + lVar7)) {
      uVar8 = (longlong)fVar11 + lVar7;
    }
    uVar9 = uVar2;
    if ((uVar2 < uVar8) && ((0x1ff < uVar2 || (uVar9 = uVar2 * 8, uVar2 * 8 < uVar8)))) {
      uVar9 = uVar8;
    }
    FUN_18000a8b0((longlong)param_1,uVar9);
    plVar1 = *(longlong **)
              (*(longlong *)(param_1 + 6) + 8 + (*(ulonglong *)(param_1 + 0xc) & uVar5) * 0x10);
    plVar10 = *(longlong **)(param_1 + 2);
    if (plVar1 != plVar10) {
      lVar7 = plVar1[2];
      plVar10 = plVar1;
      while (puVar6[2] != lVar7) {
        if (plVar10 ==
            *(longlong **)
             (*(longlong *)(param_1 + 6) + (*(ulonglong *)(param_1 + 0xc) & uVar5) * 0x10))
        goto LAB_180007536;
        plVar10 = (longlong *)plVar10[1];
        lVar7 = plVar10[2];
      }
      plVar10 = (longlong *)*plVar10;
    }
  }
LAB_180007536:
  puVar3 = (undefined8 *)plVar10[1];
  *(longlong *)(param_1 + 4) = *(longlong *)(param_1 + 4) + 1;
  *puVar6 = plVar10;
  puVar6[1] = puVar3;
  *puVar3 = puVar6;
  plVar10[1] = (longlong)puVar6;
  uVar5 = *(ulonglong *)(param_1 + 0xc) & uVar5;
  lVar7 = *(longlong *)(param_1 + 6);
  plVar1 = *(longlong **)(lVar7 + uVar5 * 0x10);
  if (plVar1 == *(longlong **)(param_1 + 2)) {
    *(undefined8 **)(lVar7 + uVar5 * 0x10) = puVar6;
  }
  else {
    if (plVar1 == plVar10) {
      *(undefined8 **)(lVar7 + uVar5 * 0x10) = puVar6;
      goto LAB_180007580;
    }
    if (*(undefined8 **)(lVar7 + 8 + uVar5 * 0x10) != puVar3) goto LAB_180007580;
  }
  *(undefined8 **)(lVar7 + 8 + uVar5 * 0x10) = puVar6;
LAB_180007580:
  *param_2 = puVar6;
  *(undefined1 *)(param_2 + 1) = 1;
  return param_2;
}


/* ---- 0x180007680  FUN_180007680  (4 bytes) ---- */

undefined8 FUN_180007680(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180007d20  FUN_180007d20  (108 bytes) ---- */

void FUN_180007d20(longlong *param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = (void *)*param_1;
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (param_1[2] - (longlong)pvVar1 & 0xfffffffffffffff8U)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


/* ---- 0x180008060  FUN_180008060  (103 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void FUN_180008060(longlong param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4,
                  undefined4 *param_5,undefined8 *param_6)

{
  undefined8 *local_18;
  undefined8 local_10;
  
  local_18 = param_6;
  if (0xf < (ulonglong)param_6[3]) {
    local_18 = (undefined8 *)*param_6;
  }
  local_10 = param_6[2];
  CNO::Compass::Marker::CNO__Compass__Marker__Marker
            (*(Marker **)(param_1 + 8),(longlong *)*param_2,(float)*param_3,*param_4,*param_5,
             &local_18);
  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 0x40;
  return;
}


/* ---- 0x1800080d0  FUN_1800080d0  (425 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

undefined8 *
FUN_1800080d0(longlong *param_1,undefined4 *param_2,undefined8 *param_3,undefined4 *param_4,
             undefined4 *param_5,undefined4 *param_6,undefined8 *param_7)

{
  ulonglong uVar1;
  Marker *pMVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  Marker *pMVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  __uint64 _Var9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  Marker *pMVar13;
  Marker *this;
  undefined8 *local_68;
  undefined8 local_60;
  longlong *local_58;
  Marker *local_50;
  ulonglong local_48;
  Marker *local_40;
  Marker *local_38;
  
  lVar3 = *param_1;
  lVar5 = param_1[1] - lVar3 >> 6;
  uVar12 = 0x3ffffffffffffff;
  if (lVar5 == 0x3ffffffffffffff) {
    FUN_18000b170();
    pcVar4 = (code *)swi(3);
    puVar7 = (undefined8 *)(*pcVar4)();
    return puVar7;
  }
  uVar1 = lVar5 + 1;
  uVar8 = param_1[2] - lVar3 >> 6;
  if (0x3ffffffffffffff - (uVar8 >> 1) < uVar8) {
    pMVar6 = (Marker *)
             std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>
                       (0xffffffffffffffc0);
  }
  else {
    uVar8 = (uVar8 >> 1) + uVar8;
    uVar12 = uVar1;
    if (uVar1 <= uVar8) {
      uVar12 = uVar8;
    }
    if (0x3ffffffffffffff < uVar12) {
      FUN_180039810();
      pcVar4 = (code *)swi(3);
      puVar7 = (undefined8 *)(*pcVar4)();
      return puVar7;
    }
    _Var9 = uVar12 << 6;
    if (_Var9 == 0) {
      pMVar6 = (Marker *)0x0;
    }
    else if (_Var9 < 0x1000) {
      pMVar6 = (Marker *)operator_new(_Var9);
    }
    else {
      pMVar6 = (Marker *)
               std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>(_Var9);
    }
  }
  this = (Marker *)((longlong)&pMVar6->ref + ((longlong)param_2 - lVar3 & 0xffffffffffffffc0U));
  pMVar2 = this + 1;
  local_68 = param_7;
  if (0xf < (ulonglong)param_7[3]) {
    local_68 = (undefined8 *)*param_7;
  }
  local_60 = param_7[2];
  local_58 = param_1;
  local_50 = pMVar6;
  local_48 = uVar12;
  local_40 = pMVar2;
  local_38 = pMVar2;
  CNO::Compass::Marker::CNO__Compass__Marker__Marker
            (this,(longlong *)*param_3,(float)*param_4,*param_5,*param_6,&local_68);
  puVar11 = (undefined4 *)param_1[1];
  puVar10 = (undefined4 *)*param_1;
  pMVar13 = pMVar6;
  if (param_2 != puVar11) {
    std::_Uninitialized_move<CNO::Compass::Marker_*,std::allocator<CNO::Compass::Marker>_>
              ((undefined4 *)*param_1,param_2,&pMVar6->ref);
    puVar11 = (undefined4 *)param_1[1];
    puVar10 = param_2;
    pMVar13 = pMVar2;
  }
  std::_Uninitialized_move<CNO::Compass::Marker_*,std::allocator<CNO::Compass::Marker>_>
            (puVar10,puVar11,&pMVar13->ref);
  std::vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_>::_Change_array
            ((vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_> *)param_1,
             (longlong)pMVar6,uVar1,uVar12);
  return &this->ref;
}


/* ---- 0x180008320  FUN_180008320  (393 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

undefined8 *
FUN_180008320(longlong *param_1,undefined4 *param_2,undefined8 *param_3,undefined4 *param_4,
             undefined4 *param_5,undefined4 *param_6,undefined8 *param_7)

{
  ulonglong uVar1;
  longlong lVar2;
  code *pcVar3;
  longlong lVar4;
  Marker *pMVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  __uint64 _Var8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  ulonglong uVar11;
  Marker *pMVar12;
  Marker *this;
  
  lVar2 = *param_1;
  lVar4 = param_1[1] - lVar2 >> 6;
  uVar11 = 0x3ffffffffffffff;
  if (lVar4 == 0x3ffffffffffffff) {
    FUN_18000b170();
    pcVar3 = (code *)swi(3);
    puVar6 = (undefined8 *)(*pcVar3)();
    return puVar6;
  }
  uVar1 = lVar4 + 1;
  uVar7 = param_1[2] - lVar2 >> 6;
  if (0x3ffffffffffffff - (uVar7 >> 1) < uVar7) {
    pMVar5 = (Marker *)
             std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>
                       (0xffffffffffffffc0);
  }
  else {
    uVar7 = (uVar7 >> 1) + uVar7;
    uVar11 = uVar1;
    if (uVar1 <= uVar7) {
      uVar11 = uVar7;
    }
    if (0x3ffffffffffffff < uVar11) {
      FUN_180039810();
      pcVar3 = (code *)swi(3);
      puVar6 = (undefined8 *)(*pcVar3)();
      return puVar6;
    }
    _Var8 = uVar11 << 6;
    if (_Var8 == 0) {
      pMVar5 = (Marker *)0x0;
    }
    else if (_Var8 < 0x1000) {
      pMVar5 = (Marker *)operator_new(_Var8);
    }
    else {
      pMVar5 = (Marker *)
               std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>(_Var8);
    }
  }
  this = (Marker *)((longlong)&pMVar5->ref + ((longlong)param_2 - lVar2 & 0xffffffffffffffc0U));
  CNO::Compass::Marker::CNO__Compass__Marker__Marker
            (this,(longlong *)*param_3,(float)*param_4,*param_5,*param_6,param_7);
  puVar10 = (undefined4 *)param_1[1];
  puVar9 = (undefined4 *)*param_1;
  pMVar12 = pMVar5;
  if (param_2 != puVar10) {
    std::_Uninitialized_move<CNO::Compass::Marker_*,std::allocator<CNO::Compass::Marker>_>
              ((undefined4 *)*param_1,param_2,&pMVar5->ref);
    puVar10 = (undefined4 *)param_1[1];
    puVar9 = param_2;
    pMVar12 = this + 1;
  }
  std::_Uninitialized_move<CNO::Compass::Marker_*,std::allocator<CNO::Compass::Marker>_>
            (puVar9,puVar10,&pMVar12->ref);
  std::vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_>::_Change_array
            ((vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_> *)param_1,
             (longlong)pMVar5,uVar1,uVar11);
  return &this->ref;
}


/* ---- 0x1800084b0  FUN_1800084b0  (103 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void FUN_1800084b0(longlong param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4,
                  undefined4 *param_5,undefined8 *param_6)

{
  undefined8 *local_18;
  undefined8 local_10;
  
  local_18 = param_6;
  if (0xf < (ulonglong)param_6[3]) {
    local_18 = (undefined8 *)*param_6;
  }
  local_10 = param_6[2];
  CNO::Compass::Marker::CNO__Compass__Marker__Marker
            (*(Marker **)(param_1 + 8),(longlong *)*param_2,(float)*param_3,*param_4,*param_5,
             &local_18);
  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 0x40;
  return;
}


/* ---- 0x180008520  FUN_180008520  (425 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

undefined8 *
FUN_180008520(longlong *param_1,undefined4 *param_2,undefined8 *param_3,undefined4 *param_4,
             undefined4 *param_5,undefined4 *param_6,undefined8 *param_7)

{
  ulonglong uVar1;
  Marker *pMVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  Marker *pMVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  __uint64 _Var9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  Marker *pMVar13;
  Marker *this;
  undefined8 *local_68;
  undefined8 local_60;
  longlong *local_58;
  Marker *local_50;
  ulonglong local_48;
  Marker *local_40;
  Marker *local_38;
  
  lVar3 = *param_1;
  lVar5 = param_1[1] - lVar3 >> 6;
  uVar12 = 0x3ffffffffffffff;
  if (lVar5 == 0x3ffffffffffffff) {
    FUN_18000b170();
    pcVar4 = (code *)swi(3);
    puVar7 = (undefined8 *)(*pcVar4)();
    return puVar7;
  }
  uVar1 = lVar5 + 1;
  uVar8 = param_1[2] - lVar3 >> 6;
  if (0x3ffffffffffffff - (uVar8 >> 1) < uVar8) {
    pMVar6 = (Marker *)
             std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>
                       (0xffffffffffffffc0);
  }
  else {
    uVar8 = (uVar8 >> 1) + uVar8;
    uVar12 = uVar1;
    if (uVar1 <= uVar8) {
      uVar12 = uVar8;
    }
    if (0x3ffffffffffffff < uVar12) {
      FUN_180039810();
      pcVar4 = (code *)swi(3);
      puVar7 = (undefined8 *)(*pcVar4)();
      return puVar7;
    }
    _Var9 = uVar12 << 6;
    if (_Var9 == 0) {
      pMVar6 = (Marker *)0x0;
    }
    else if (_Var9 < 0x1000) {
      pMVar6 = (Marker *)operator_new(_Var9);
    }
    else {
      pMVar6 = (Marker *)
               std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>(_Var9);
    }
  }
  this = (Marker *)((longlong)&pMVar6->ref + ((longlong)param_2 - lVar3 & 0xffffffffffffffc0U));
  pMVar2 = this + 1;
  local_68 = param_7;
  if (0xf < (ulonglong)param_7[3]) {
    local_68 = (undefined8 *)*param_7;
  }
  local_60 = param_7[2];
  local_58 = param_1;
  local_50 = pMVar6;
  local_48 = uVar12;
  local_40 = pMVar2;
  local_38 = pMVar2;
  CNO::Compass::Marker::CNO__Compass__Marker__Marker
            (this,(longlong *)*param_3,(float)*param_4,*param_5,*param_6,&local_68);
  puVar11 = (undefined4 *)param_1[1];
  puVar10 = (undefined4 *)*param_1;
  pMVar13 = pMVar6;
  if (param_2 != puVar11) {
    std::_Uninitialized_move<CNO::Compass::Marker_*,std::allocator<CNO::Compass::Marker>_>
              ((undefined4 *)*param_1,param_2,&pMVar6->ref);
    puVar11 = (undefined4 *)param_1[1];
    puVar10 = param_2;
    pMVar13 = pMVar2;
  }
  std::_Uninitialized_move<CNO::Compass::Marker_*,std::allocator<CNO::Compass::Marker>_>
            (puVar10,puVar11,&pMVar13->ref);
  std::vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_>::_Change_array
            ((vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_> *)param_1,
             (longlong)pMVar6,uVar1,uVar12);
  return &this->ref;
}


/* ---- 0x180008730  FUN_180008730  (411 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

undefined8 *
FUN_180008730(longlong *param_1,undefined4 *param_2,undefined8 *param_3,undefined4 *param_4,
             undefined4 *param_5,undefined4 *param_6)

{
  ulonglong uVar1;
  Marker *pMVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  Marker *pMVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  __uint64 _Var9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  Marker *pMVar13;
  Marker *this;
  undefined1 *local_68;
  undefined8 local_60;
  longlong *local_58;
  Marker *local_50;
  ulonglong local_48;
  Marker *local_40;
  Marker *local_38;
  
  lVar3 = *param_1;
  lVar5 = param_1[1] - lVar3 >> 6;
  uVar12 = 0x3ffffffffffffff;
  if (lVar5 == 0x3ffffffffffffff) {
    FUN_18000b170();
    pcVar4 = (code *)swi(3);
    puVar7 = (undefined8 *)(*pcVar4)();
    return puVar7;
  }
  uVar1 = lVar5 + 1;
  uVar8 = param_1[2] - lVar3 >> 6;
  if (0x3ffffffffffffff - (uVar8 >> 1) < uVar8) {
    pMVar6 = (Marker *)
             std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>
                       (0xffffffffffffffc0);
  }
  else {
    uVar8 = (uVar8 >> 1) + uVar8;
    uVar12 = uVar1;
    if (uVar1 <= uVar8) {
      uVar12 = uVar8;
    }
    if (0x3ffffffffffffff < uVar12) {
      FUN_180039810();
      pcVar4 = (code *)swi(3);
      puVar7 = (undefined8 *)(*pcVar4)();
      return puVar7;
    }
    _Var9 = uVar12 << 6;
    if (_Var9 == 0) {
      pMVar6 = (Marker *)0x0;
    }
    else if (_Var9 < 0x1000) {
      pMVar6 = (Marker *)operator_new(_Var9);
    }
    else {
      pMVar6 = (Marker *)
               std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>(_Var9);
    }
  }
  this = (Marker *)((longlong)&pMVar6->ref + ((longlong)param_2 - lVar3 & 0xffffffffffffffc0U));
  pMVar2 = this + 1;
  local_68 = &s_;
  local_60 = 0;
  local_58 = param_1;
  local_50 = pMVar6;
  local_48 = uVar12;
  local_40 = pMVar2;
  local_38 = pMVar2;
  CNO::Compass::Marker::CNO__Compass__Marker__Marker
            (this,(longlong *)*param_3,(float)*param_4,*param_5,*param_6,&local_68);
  puVar11 = (undefined4 *)param_1[1];
  puVar10 = (undefined4 *)*param_1;
  pMVar13 = pMVar6;
  if (param_2 != puVar11) {
    std::_Uninitialized_move<CNO::Compass::Marker_*,std::allocator<CNO::Compass::Marker>_>
              ((undefined4 *)*param_1,param_2,&pMVar6->ref);
    puVar11 = (undefined4 *)param_1[1];
    puVar10 = param_2;
    pMVar13 = pMVar2;
  }
  std::_Uninitialized_move<CNO::Compass::Marker_*,std::allocator<CNO::Compass::Marker>_>
            (puVar10,puVar11,&pMVar13->ref);
  std::vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_>::_Change_array
            ((vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_> *)param_1,
             (longlong)pMVar6,uVar1,uVar12);
  return &this->ref;
}


/* ---- 0x180008d30  FUN_180008d30  (400 bytes) ---- */

/* WARNING: Enum "DIALOGUE_TYPE": Some values do not have unique names */

void * FUN_180008d30(longlong *param_1,void *param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  void *pvVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  void *pvVar6;
  ulonglong uVar7;
  void *pvVar8;
  void *pvVar9;
  longlong lVar10;
  ulonglong uVar11;
  void *pvVar12;
  
  lVar3 = *param_1;
  lVar10 = (longlong)param_2 - lVar3 >> 3;
  lVar5 = param_1[1] - lVar3 >> 3;
  if (lVar5 == 0x1fffffffffffffff) {
    FUN_18000b330();
    pcVar4 = (code *)swi(3);
    pvVar6 = (void *)(*pcVar4)();
    return pvVar6;
  }
  uVar7 = param_1[2] - lVar3 >> 3;
  uVar1 = lVar5 + 1;
  if (0x1fffffffffffffff - (uVar7 >> 1) < uVar7) {
    uVar11 = 0xfffffffffffffff8;
    pvVar6 = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>
                       (0xfffffffffffffff8);
  }
  else {
    uVar7 = (uVar7 >> 1) + uVar7;
    uVar11 = uVar1;
    if (uVar1 <= uVar7) {
      uVar11 = uVar7;
    }
    if (0x1fffffffffffffff < uVar11) {
      FUN_180039810();
      pcVar4 = (code *)swi(3);
      pvVar6 = (void *)(*pcVar4)();
      return pvVar6;
    }
    uVar11 = uVar11 * 8;
    if (uVar11 == 0) {
      pvVar6 = (void *)0x0;
    }
    else if (uVar11 < 0x1000) {
      pvVar6 = operator_new(uVar11);
    }
    else {
      pvVar6 = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>(uVar11);
    }
  }
  *(undefined8 *)((longlong)pvVar6 + lVar10 * 8) = *param_3;
  pvVar9 = (void *)param_1[1];
  pvVar2 = (void *)((longlong)pvVar6 + lVar10 * 8);
  pvVar8 = (void *)*param_1;
  pvVar12 = pvVar6;
  if (param_2 != pvVar9) {
    std::_Copy_memmove<RE::BGSInstancedQuestObjective_*_*,RE::BGSInstancedQuestObjective_*_*>
              ((void *)*param_1,(longlong)param_2,pvVar6);
    pvVar9 = (void *)param_1[1];
    pvVar12 = (void *)((longlong)pvVar2 + 8);
    pvVar8 = param_2;
  }
  std::_Copy_memmove<RE::BGSInstancedQuestObjective_*_*,RE::BGSInstancedQuestObjective_*_*>
            (pvVar8,(longlong)pvVar9,pvVar12);
  pvVar12 = (void *)*param_1;
  if (pvVar12 != (void *)0x0) {
    pvVar9 = pvVar12;
    if ((0xfff < (param_1[2] - (longlong)pvVar12 & 0xfffffffffffffff8U)) &&
       (pvVar9 = *(void **)((longlong)pvVar12 + -8),
       0x1f < (ulonglong)((longlong)pvVar12 + (-8 - (longlong)pvVar9)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(pvVar9);
  }
  *param_1 = (longlong)pvVar6;
  param_1[1] = (longlong)((longlong)pvVar6 + uVar1 * 8);
  param_1[2] = uVar11 + (longlong)pvVar6;
  return pvVar2;
}


/* ---- 0x1800096c0  FUN_1800096c0  (85 bytes) ---- */

void FUN_1800096c0(undefined8 param_1,void *param_2,longlong param_3)

{
  void *_Memory;
  
  _Memory = param_2;
  if ((0xfff < (ulonglong)(param_3 * 8)) &&
     (_Memory = *(void **)((longlong)param_2 + -8),
     0x1f < (ulonglong)((longlong)param_2 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  free(_Memory);
  return;
}


/* ---- 0x180009aa0  FUN_180009aa0  (85 bytes) ---- */

void FUN_180009aa0(undefined8 param_1,void *param_2,longlong param_3)

{
  void *_Memory;
  
  _Memory = param_2;
  if ((0xfff < (ulonglong)(param_3 * 8)) &&
     (_Memory = *(void **)((longlong)param_2 + -8),
     0x1f < (ulonglong)((longlong)param_2 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  free(_Memory);
  return;
}


/* ---- 0x180009e80  FUN_180009e80  (95 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void FUN_180009e80(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4,
                  undefined4 *param_5,undefined4 *param_6,undefined8 *param_7)

{
  undefined8 *local_18;
  undefined8 local_10;
  
  local_18 = param_7;
  if (0xf < (ulonglong)param_7[3]) {
    local_18 = (undefined8 *)*param_7;
  }
  local_10 = param_7[2];
  CNO::Compass::Marker::CNO__Compass__Marker__Marker
            ((Marker *)param_2,(longlong *)*param_3,(float)*param_4,*param_5,*param_6,&local_18);
  return;
}


/* ---- 0x18000a040  FUN_18000a040  (95 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void FUN_18000a040(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4,
                  undefined4 *param_5,undefined4 *param_6,undefined8 *param_7)

{
  undefined8 *local_18;
  undefined8 local_10;
  
  local_18 = param_7;
  if (0xf < (ulonglong)param_7[3]) {
    local_18 = (undefined8 *)*param_7;
  }
  local_10 = param_7[2];
  CNO::Compass::Marker::CNO__Compass__Marker__Marker
            ((Marker *)param_2,(longlong *)*param_3,(float)*param_4,*param_5,*param_6,&local_18);
  return;
}


/* ---- 0x18000a6e0  FUN_18000a6e0  (32 bytes) ---- */

void FUN_18000a6e0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      param_1 = param_1 + 1;
    } while (param_1 != param_2);
  }
  return;
}


/* ---- 0x18000a710  FUN_18000a710  (32 bytes) ---- */

void FUN_18000a710(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      param_1 = param_1 + 1;
    } while (param_1 != param_2);
  }
  return;
}


/* ---- 0x18000b170  FUN_18000b170  (18 bytes) ---- */

void FUN_18000b170(void)

{
  code *pcVar1;
  
  std::_Xlength_error("vector too long");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* ---- 0x18000b450  FUN_18000b450  (84 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void FUN_18000b450(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4,
                  undefined4 *param_5,undefined8 *param_6)

{
  undefined8 *local_18;
  undefined8 local_10;
  
  local_18 = param_6;
  if (0xf < (ulonglong)param_6[3]) {
    local_18 = (undefined8 *)*param_6;
  }
  local_10 = param_6[2];
  CNO::Compass::Marker::CNO__Compass__Marker__Marker
            ((Marker *)param_1,(longlong *)*param_2,(float)*param_3,*param_4,*param_5,&local_18);
  return;
}


/* ---- 0x18000b550  FUN_18000b550  (84 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void FUN_18000b550(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4,
                  undefined4 *param_5,undefined8 *param_6)

{
  undefined8 *local_18;
  undefined8 local_10;
  
  local_18 = param_6;
  if (0xf < (ulonglong)param_6[3]) {
    local_18 = (undefined8 *)*param_6;
  }
  local_10 = param_6[2];
  CNO::Compass::Marker::CNO__Compass__Marker__Marker
            ((Marker *)param_1,(longlong *)*param_2,(float)*param_3,*param_4,*param_5,&local_18);
  return;
}


/* ---- 0x18000b9c0  FUN_18000b9c0  (8 bytes) ---- */

void FUN_18000b9c0(undefined8 param_1)

{
  FUN_18000c480(param_1,(byte *)param_1);
  return;
}


/* ---- 0x18000ed80  FUN_18000ed80  (386 bytes) ---- */

undefined8 *
FUN_18000ed80(undefined8 *param_1,ulonglong param_2,undefined8 param_3,void *param_4,size_t param_5)

{
  ulonglong uVar1;
  size_t _Size;
  ulonglong uVar2;
  void *_Src;
  void *_Dst;
  ulonglong uVar3;
  ulonglong uVar4;
  void *pvVar5;
  
  _Size = param_1[2];
  uVar4 = 0x7fffffffffffffff;
  if (0x7fffffffffffffff - _Size < param_2) {
                    /* WARNING: Subroutine does not return */
    std::_Xlen_string();
  }
  uVar3 = _Size + param_2 | 0xf;
  uVar2 = param_1[3];
  if (uVar3 < 0x8000000000000000) {
    if (0x7fffffffffffffff - (uVar2 >> 1) < uVar2) {
      _Dst = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>
                       (0x8000000000000000);
    }
    else {
      uVar1 = uVar2 + (uVar2 >> 1);
      uVar4 = uVar3;
      if (uVar3 < uVar1) {
        uVar4 = uVar1;
      }
      uVar3 = uVar4 + 1;
      if (uVar3 == 0) {
        _Dst = (void *)0x0;
      }
      else if (uVar3 < 0x1000) {
        _Dst = operator_new(uVar3);
      }
      else {
        _Dst = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>(uVar3);
      }
    }
  }
  else {
    _Dst = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>(0x8000000000000000)
    ;
  }
  param_1[2] = _Size + param_2;
  pvVar5 = (void *)(_Size + (longlong)_Dst);
  param_1[3] = uVar4;
  if (uVar2 < 0x10) {
    memcpy(_Dst,param_1,_Size);
    memcpy(pvVar5,param_4,param_5);
    *(undefined1 *)(param_5 + (longlong)pvVar5) = 0;
  }
  else {
    _Src = (void *)*param_1;
    memcpy(_Dst,_Src,_Size);
    memcpy(pvVar5,param_4,param_5);
    *(undefined1 *)(param_5 + (longlong)pvVar5) = 0;
    pvVar5 = _Src;
    if ((0xfff < uVar2 + 1) &&
       (pvVar5 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar5)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(pvVar5);
  }
  *param_1 = _Dst;
  return param_1;
}


/* ---- 0x18000f090  FUN_18000f090  (450 bytes) ---- */

void FUN_18000f090(ushort *param_1,longlong *param_2,undefined8 *param_3)

{
  ushort *puVar1;
  ulonglong uVar2;
  void *_Src;
  longlong lVar3;
  code *pcVar4;
  longlong *plVar5;
  undefined8 ****ppppuVar6;
  ulonglong uVar7;
  undefined1 auStackY_a8 [32];
  byte local_78;
  undefined8 ***local_60 [2];
  size_t local_50;
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0xf;
  *(undefined1 *)param_2 = 0;
  puVar1 = param_1 + 4;
  if (param_1 != puVar1) {
    do {
      std::_Integral_to_string<char,int>(local_60,(uint)*param_1);
      ppppuVar6 = local_60;
      if (0xf < local_48) {
        ppppuVar6 = (undefined8 ****)local_60[0];
      }
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::append
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)param_2,
                 ppppuVar6,local_50);
      if (0xf < local_48) {
        ppppuVar6 = (undefined8 ****)local_60[0];
        if ((0xfff < local_48 + 1) &&
           (ppppuVar6 = (undefined8 ****)local_60[0][-1],
           0x1f < (ulonglong)((longlong)local_60[0] + (-8 - (longlong)ppppuVar6)))) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        free(ppppuVar6);
      }
      uVar2 = param_3[1];
      _Src = (void *)*param_3;
      lVar3 = param_2[2];
      if ((ulonglong)(param_2[3] - lVar3) < uVar2) {
        FUN_18000ed80(param_2,uVar2,(ulonglong)local_78,_Src,uVar2);
      }
      else {
        param_2[2] = lVar3 + uVar2;
        plVar5 = param_2;
        if (0xf < (ulonglong)param_2[3]) {
          plVar5 = (longlong *)*param_2;
        }
        memmove((void *)((longlong)plVar5 + lVar3),_Src,uVar2);
        *(undefined1 *)((longlong)plVar5 + lVar3 + uVar2) = 0;
      }
      param_1 = param_1 + 1;
    } while (param_1 != puVar1);
  }
  uVar2 = param_3[1];
  uVar7 = param_2[2] - uVar2;
  if ((ulonglong)param_2[2] < uVar7) {
    FUN_180037f00();
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  plVar5 = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    plVar5 = (longlong *)*param_2;
  }
  *(undefined1 *)((longlong)plVar5 + uVar7) = ((undefined1 *)((longlong)plVar5 + uVar7))[uVar2];
  param_2[2] = uVar7;
  __security_check_cookie(local_40 ^ (ulonglong)auStackY_a8);
  return;
}


/* ---- 0x18000f860  FUN_18000f860  (205 bytes) ---- */

longlong FUN_18000f860(ulonglong *param_1)

{
  longlong lVar1;
  undefined *puVar2;
  IDDatabase *pIVar3;
  ulong64 uVar4;
  ulonglong *puVar5;
  ulonglong uVar6;
  
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    uVar6 = param_1[1];
  }
  else {
    if (puVar2[0x118] != '\x02') {
      return 0;
    }
    uVar6 = *param_1;
  }
  puVar5 = param_1 + 1;
  if (uVar6 != 0) {
    pIVar3 = (IDDatabase *)REL::IDDatabase::get();
    uVar4 = REL::IDDatabase::id2offset(pIVar3,uVar6);
    if (uVar4 != 0) {
      puVar2 = REL::Module::get();
      lVar1 = *(longlong *)(puVar2 + 0x110);
      puVar2 = REL::Module::get();
      if (((puVar2[0x118] == '\x01') || (puVar5 = param_1, puVar2[0x118] == '\x02')) &&
         (uVar6 = *puVar5, uVar6 != 0)) {
        pIVar3 = (IDDatabase *)REL::IDDatabase::get();
        uVar4 = REL::IDDatabase::id2offset(pIVar3,uVar6);
        return uVar4 + lVar1;
      }
      return lVar1;
    }
  }
  return 0;
}


/* ---- 0x18001bf20  FUN_18001bf20  (347 bytes) ---- */

longlong * FUN_18001bf20(longlong *param_1,void *param_2,size_t param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  void *pvVar3;
  void *_Dst;
  ulonglong uVar4;
  void *_Memory;
  longlong *_Dst_00;
  ulonglong uVar5;
  
  uVar2 = param_1[3];
  if (uVar2 < param_3) {
    uVar5 = 0x7fffffffffffffff;
    if (0x7fffffffffffffff < param_3) {
                    /* WARNING: Subroutine does not return */
      std::_Xlen_string();
    }
    uVar4 = param_3 | 0xf;
    if (uVar4 < 0x8000000000000000) {
      if (0x7fffffffffffffff - (uVar2 >> 1) < uVar2) {
        _Dst = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>
                         (0x8000000000000000);
      }
      else {
        uVar1 = uVar2 + (uVar2 >> 1);
        uVar5 = uVar4;
        if (uVar4 < uVar1) {
          uVar5 = uVar1;
        }
        uVar4 = uVar5 + 1;
        if (uVar4 == 0) {
          _Dst = (void *)0x0;
        }
        else if (uVar4 < 0x1000) {
          _Dst = operator_new(uVar4);
        }
        else {
          _Dst = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>(uVar4);
        }
      }
    }
    else {
      _Dst = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>
                       (0x8000000000000000);
    }
    param_1[2] = param_3;
    param_1[3] = uVar5;
    memcpy(_Dst,param_2,param_3);
    *(undefined1 *)((longlong)_Dst + param_3) = 0;
    if (0xf < uVar2) {
      pvVar3 = (void *)*param_1;
      _Memory = pvVar3;
      if ((0xfff < uVar2 + 1) &&
         (_Memory = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      free(_Memory);
    }
    *param_1 = (longlong)_Dst;
  }
  else {
    _Dst_00 = param_1;
    if (0xf < uVar2) {
      _Dst_00 = (longlong *)*param_1;
    }
    param_1[2] = param_3;
    memmove(_Dst_00,param_2,param_3);
    *(undefined1 *)((longlong)_Dst_00 + param_3) = 0;
  }
  return param_1;
}


/* ---- 0x1800355c0  FUN_1800355c0  (11 bytes) ---- */

undefined8 * FUN_1800355c0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return param_1;
}


/* ---- 0x180039810  FUN_180039810  (31 bytes) ---- */

void FUN_180039810(void)

{
  bad_array_new_length local_28 [40];
  
  std::bad_array_new_length::bad_array_new_length(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_1801ca4a8);
}


/* ---- 0x18003a500  FUN_18003a500  (21 bytes) ---- */

undefined1 FUN_18003a500(void)

{
  undefined *puVar1;
  
  puVar1 = REL::Module::get();
  return puVar1[0x118];
}


/* ---- 0x18003a520  FUN_18003a520  (112 bytes) ---- */

undefined8 FUN_18003a520(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  
  REL::Module::get();
  puVar1 = REL::Module::get();
  if (puVar1[0x118] == '\x01') {
    return param_2;
  }
  if (puVar1[0x118] != '\x04') {
    return param_1;
  }
  return param_3;
}


/* ---- 0x18003a590  FUN_18003a590  (36 bytes) ---- */

longlong FUN_18003a590(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = FUN_18003a520(0x13c,0x13c,0x158);
  return lVar1 + param_1;
}


/* ---- 0x18003a5c0  FUN_18003a5c0  (56 bytes) ---- */

longlong FUN_18003a5c0(longlong param_1)

{
  undefined *puVar1;
  longlong lVar2;
  
  REL::Module::get();
  puVar1 = REL::Module::get();
  if ((puVar1[0x118] == '\x01') || (lVar2 = 0x158, puVar1[0x118] != '\x04')) {
    lVar2 = 0x13c;
  }
  return lVar2 + param_1;
}


/* ---- 0x18003a600  FUN_18003a600  (19 bytes) ---- */

undefined8 * FUN_18003a600(longlong param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x5c);
  *param_2 = *(undefined8 *)(param_1 + 0x54);
  *(undefined4 *)(param_2 + 1) = uVar1;
  return param_2;
}


/* ---- 0x18003a620  FUN_18003a620  (17 bytes) ---- */

void FUN_18003a620(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (*(char *)(param_1 + lVar1) != '\0');
  return;
}


/* ---- 0x18003a640  FUN_18003a640  (33 bytes) ---- */

longlong * FUN_18003a640(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  
  *param_1 = param_2;
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (*(char *)(param_2 + lVar1) != '\0');
  param_1[1] = lVar1;
  return param_1;
}


/* ---- 0x18003a670  FUN_18003a670  (4 bytes) ---- */

undefined8 FUN_18003a670(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003a680  FUN_18003a680  (11 bytes) ---- */

undefined8 * FUN_18003a680(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return param_1;
}


/* ---- 0x18003a690  FUN_18003a690  (44 bytes) ---- */

void FUN_18003a690(void)

{
  longlong lVar1;
  ulonglong local_18 [3];
  
  local_18[0] = 0x7edbb;
  local_18[1] = 0x6328a;
  lVar1 = FUN_18000f860(local_18);
  FUN_18003ba30(lVar1);
  return;
}


/* ---- 0x18003a6c0  FUN_18003a6c0  (8 bytes) ---- */

undefined8 FUN_18003a6c0(void)

{
  return DAT_1801d9530;
}


/* ---- 0x18003a6d0  FUN_18003a6d0  (8 bytes) ---- */

undefined8 FUN_18003a6d0(void)

{
  return DAT_1801d9528;
}


/* ---- 0x18003ab20  FUN_18003ab20  (32 bytes) ---- */

void FUN_18003ab20(longlong param_1)

{
  FUN_18003b510((longlong *)(param_1 + 0x18));
  FUN_18003b580((longlong *)(param_1 + 8));
  return;
}


/* ---- 0x18003ab40  FUN_18003ab40  (32 bytes) ---- */

void FUN_18003ab40(longlong param_1)

{
  FUN_18003b340((longlong *)(param_1 + 0x18));
  FUN_18003b3b0((longlong *)(param_1 + 8));
  return;
}


/* ---- 0x18003ab60  FUN_18003ab60  (32 bytes) ---- */

void FUN_18003ab60(longlong param_1)

{
  FUN_18003b340((longlong *)(param_1 + 0x18));
  FUN_18003b3b0((longlong *)(param_1 + 8));
  return;
}


/* ---- 0x18003b100  FUN_18003b100  (41 bytes) ---- */

undefined8 FUN_18003b100(longlong param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x10) + 400);
  while( true ) {
    if (puVar1 == (undefined8 *)0x0) {
      return 0;
    }
    if (*(short *)(puVar1 + 3) == 0x2e) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return CONCAT71((int7)((ulonglong)puVar1 >> 8),1);
}


/* ---- 0x18003b220  FUN_18003b220  (11 bytes) ---- */

undefined8 * FUN_18003b220(undefined8 *param_1)

{
  *param_1 = 0;
  return param_1;
}


/* ---- 0x18003b270  FUN_18003b270  (10 bytes) ---- */

longlong * FUN_18003b270(ExtraDataList *param_1)

{
  bool bVar1;
  int iVar2;
  BSReadWriteLock *pBVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  BSReadLockGuard aBStackX_18 [16];
  
  pBVar3 = (BSReadWriteLock *)RE::ExtraDataList::GetLock(param_1);
  RE::BSReadLockGuard::BSReadLockGuard(aBStackX_18,pBVar3);
  bVar1 = RE::ExtraDataList::HasType(param_1,0x2c);
  if (bVar1) {
    puVar4 = (undefined8 *)FUN_180082b20((longlong)param_1);
    for (plVar5 = (longlong *)*puVar4; plVar5 != (longlong *)0x0; plVar5 = (longlong *)plVar5[1]) {
      iVar2 = (**(code **)(*plVar5 + 8))(plVar5);
      if (iVar2 == 0x2c) goto LAB_180082a68;
    }
  }
  plVar5 = (longlong *)0x0;
LAB_180082a68:
  RE::BSReadLockGuard::~BSReadLockGuard(aBStackX_18);
  return plVar5;
}


/* ---- 0x18003b280  FUN_18003b280  (41 bytes) ---- */

void FUN_18003b280(undefined8 param_1,undefined8 *param_2)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = param_1;
  local_res8[0] = FUN_18003c020(DAT_1801d9598);
  FUN_18003b970(local_res8,param_2);
  return;
}


/* ---- 0x18003b2b0  FUN_18003b2b0  (41 bytes) ---- */

void FUN_18003b2b0(undefined8 param_1,undefined8 *param_2,undefined4 *param_3)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = param_1;
  local_res8[0] = FUN_18003c000(DAT_1801d9550);
  FUN_18003b990(local_res8,param_2,param_3);
  return;
}


/* ---- 0x18003b2e0  FUN_18003b2e0  (41 bytes) ---- */

void FUN_18003b2e0(undefined8 param_1,undefined8 *param_2,undefined4 *param_3)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = param_1;
  local_res8[0] = FUN_18003c010(DAT_1801d9548);
  FUN_18003b9c0(local_res8,param_2,param_3);
  return;
}


/* ---- 0x18003b310  FUN_18003b310  (41 bytes) ---- */

void FUN_18003b310(undefined8 param_1,undefined8 *param_2)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = param_1;
  local_res8[0] = FUN_18003bff0(DAT_1801d9540);
  FUN_18003b9f0(local_res8,param_2);
  return;
}


/* ---- 0x18003b340  FUN_18003b340  (108 bytes) ---- */

void FUN_18003b340(longlong *param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = (void *)*param_1;
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (param_1[2] - (longlong)pvVar1 & 0xfffffffffffffff8U)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


/* ---- 0x18003b3b0  FUN_18003b3b0  (118 bytes) ---- */

void FUN_18003b3b0(longlong *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)*param_1;
  *(undefined8 *)puVar1[1] = 0;
  puVar1 = (undefined8 *)*puVar1;
  while (puVar1 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)*puVar1;
    FUN_180007d20(puVar1 + 10);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(puVar1 + 5));
    free(puVar1);
    puVar1 = puVar2;
  }
  free((void *)*param_1);
  return;
}


/* ---- 0x18003b430  FUN_18003b430  (210 bytes) ---- */

/* WARNING: Removing unreachable block (ram,0x00018003b4e2) */
/* WARNING: Removing unreachable block (ram,0x00018003b4ef) */
/* WARNING: Removing unreachable block (ram,0x00018003b4f1) */

undefined4 * FUN_18003b430(undefined4 *param_1)

{
  undefined8 *puVar1;
  void *pvVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 local_res10;
  
  *param_1 = 0;
  *(undefined8 *)(param_1 + 2) = 0;
  *(undefined8 *)(param_1 + 4) = 0;
  pvVar2 = operator_new(0x70);
  *(void **)pvVar2 = pvVar2;
  *(void **)((longlong)pvVar2 + 8) = pvVar2;
  *(void **)(param_1 + 2) = pvVar2;
  *(undefined8 *)(param_1 + 6) = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 10) = 0;
  *(undefined8 *)(param_1 + 0xc) = 7;
  *(undefined8 *)(param_1 + 0xe) = 8;
  *param_1 = 0x3f800000;
  local_res10 = *(undefined8 *)(param_1 + 2);
  uVar4 = 0x80;
  puVar3 = (undefined8 *)operator_new(0x80);
  lVar5 = *(longlong *)(param_1 + 10) - (longlong)*(void **)(param_1 + 6) >> 3;
  if (lVar5 != 0) {
    FUN_1800096c0(uVar4,*(void **)(param_1 + 6),lVar5);
  }
  *(undefined8 **)(param_1 + 6) = puVar3;
  puVar1 = puVar3 + 0x10;
  *(undefined8 **)(param_1 + 8) = puVar1;
  *(undefined8 **)(param_1 + 10) = puVar1;
  FUN_18000a6e0(puVar3,puVar1,&local_res10);
  return param_1;
}


/* ---- 0x18003b510  FUN_18003b510  (108 bytes) ---- */

void FUN_18003b510(longlong *param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = (void *)*param_1;
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (param_1[2] - (longlong)pvVar1 & 0xfffffffffffffff8U)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


/* ---- 0x18003b580  FUN_18003b580  (118 bytes) ---- */

void FUN_18003b580(longlong *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)*param_1;
  *(undefined8 *)puVar1[1] = 0;
  puVar1 = (undefined8 *)*puVar1;
  while (puVar1 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)*puVar1;
    FUN_18000c620(puVar1 + 6);
    FUN_18000c770(puVar1 + 4);
    free(puVar1);
    puVar1 = puVar2;
  }
  free((void *)*param_1);
  return;
}


/* ---- 0x18003b600  FUN_18003b600  (210 bytes) ---- */

/* WARNING: Removing unreachable block (ram,0x00018003b6b2) */
/* WARNING: Removing unreachable block (ram,0x00018003b6bf) */
/* WARNING: Removing unreachable block (ram,0x00018003b6c1) */

undefined4 * FUN_18003b600(undefined4 *param_1)

{
  undefined8 *puVar1;
  void *pvVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 local_res10;
  
  *param_1 = 0;
  *(undefined8 *)(param_1 + 2) = 0;
  *(undefined8 *)(param_1 + 4) = 0;
  pvVar2 = operator_new(0x58);
  *(void **)pvVar2 = pvVar2;
  *(void **)((longlong)pvVar2 + 8) = pvVar2;
  *(void **)(param_1 + 2) = pvVar2;
  *(undefined8 *)(param_1 + 6) = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 10) = 0;
  *(undefined8 *)(param_1 + 0xc) = 7;
  *(undefined8 *)(param_1 + 0xe) = 8;
  *param_1 = 0x3f800000;
  local_res10 = *(undefined8 *)(param_1 + 2);
  uVar4 = 0x80;
  puVar3 = (undefined8 *)operator_new(0x80);
  lVar5 = *(longlong *)(param_1 + 10) - (longlong)*(void **)(param_1 + 6) >> 3;
  if (lVar5 != 0) {
    FUN_180009aa0(uVar4,*(void **)(param_1 + 6),lVar5);
  }
  *(undefined8 **)(param_1 + 6) = puVar3;
  puVar1 = puVar3 + 0x10;
  *(undefined8 **)(param_1 + 8) = puVar1;
  *(undefined8 **)(param_1 + 10) = puVar1;
  FUN_18000a710(puVar3,puVar1,&local_res10);
  return param_1;
}


/* ---- 0x18003b6e0  FUN_18003b6e0  (157 bytes) ---- */

void FUN_18003b6e0(longlong *param_1)

{
  longlong lVar1;
  void *pvVar2;
  void *_Memory;
  longlong lVar3;
  
  lVar3 = *param_1;
  if (lVar3 != 0) {
    lVar1 = param_1[1];
    for (; lVar3 != lVar1; lVar3 = lVar3 + 0x40) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(lVar3 + 0x20));
    }
    pvVar2 = (void *)*param_1;
    _Memory = pvVar2;
    if ((0xfff < (param_1[2] - (longlong)pvVar2 & 0xffffffffffffffc0U)) &&
       (_Memory = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


/* ---- 0x18003b780  FUN_18003b780  (17 bytes) ---- */

undefined8 * FUN_18003b780(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}


/* ---- 0x18003b7a0  FUN_18003b7a0  (31 bytes) ---- */

undefined8 * FUN_18003b7a0(undefined8 param_1,ulonglong *param_2)

{
  DAT_1801d9598 = FUN_18000f860(param_2);
  return &DAT_1801d9598;
}


/* ---- 0x18003b7c0  FUN_18003b7c0  (31 bytes) ---- */

undefined8 * FUN_18003b7c0(undefined8 param_1,ulonglong *param_2)

{
  DAT_1801d9590 = FUN_18000f860(param_2);
  return &DAT_1801d9590;
}


/* ---- 0x18003b7e0  FUN_18003b7e0  (31 bytes) ---- */

undefined8 * FUN_18003b7e0(undefined8 param_1,ulonglong *param_2)

{
  DAT_1801d9580 = FUN_18000f860(param_2);
  return &DAT_1801d9580;
}


/* ---- 0x18003b800  FUN_18003b800  (31 bytes) ---- */

undefined8 * FUN_18003b800(undefined8 param_1,ulonglong *param_2)

{
  DAT_1801d9578 = FUN_18000f860(param_2);
  return &DAT_1801d9578;
}


/* ---- 0x18003b820  FUN_18003b820  (31 bytes) ---- */

undefined8 * FUN_18003b820(undefined8 param_1,ulonglong *param_2)

{
  DAT_1801d9570 = FUN_18000f860(param_2);
  return &DAT_1801d9570;
}


/* ---- 0x18003b840  FUN_18003b840  (31 bytes) ---- */

undefined8 * FUN_18003b840(undefined8 param_1,ulonglong *param_2)

{
  DAT_1801d9568 = FUN_18000f860(param_2);
  return &DAT_1801d9568;
}


/* ---- 0x18003b860  FUN_18003b860  (8 bytes) ---- */

undefined8 FUN_18003b860(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003b870  FUN_18003b870  (29 bytes) ---- */

longlong * FUN_18003b870(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x18003b890  FUN_18003b890  (29 bytes) ---- */

longlong * FUN_18003b890(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18003c390(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x18003b8b0  FUN_18003b8b0  (4 bytes) ---- */

undefined4 FUN_18003b8b0(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}


/* ---- 0x18003b8c0  FUN_18003b8c0  (10 bytes) ---- */

longlong FUN_18003b8c0(longlong *param_1,uint param_2)

{
  return (ulonglong)param_2 * 0x10 + *param_1;
}


/* ---- 0x18003b8d0  FUN_18003b8d0  (8 bytes) ---- */

bool FUN_18003b8d0(short param_1)

{
  return param_1 == 0x2e;
}


/* ---- 0x18003b8e0  FUN_18003b8e0  (4 bytes) ---- */

undefined8 FUN_18003b8e0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003b8f0  FUN_18003b8f0  (4 bytes) ---- */

undefined8 FUN_18003b8f0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003b900  FUN_18003b900  (4 bytes) ---- */

undefined8 FUN_18003b900(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003b910  FUN_18003b910  (4 bytes) ---- */

undefined8 FUN_18003b910(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003b920  FUN_18003b920  (52 bytes) ---- */

void FUN_18003b920(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined8 param_5)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b951. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3,*param_4,param_5);
  return;
}


/* ---- 0x18003b960  FUN_18003b960  (4 bytes) ---- */

undefined8 FUN_18003b960(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003b970  FUN_18003b970  (9 bytes) ---- */

void FUN_18003b970(undefined8 *param_1,undefined8 *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018003b976. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2);
  return;
}


/* ---- 0x18003b980  FUN_18003b980  (4 bytes) ---- */

undefined8 FUN_18003b980(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003b990  FUN_18003b990  (27 bytes) ---- */

void FUN_18003b990(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_18003bf50(*param_1);
                    /* WARNING: Could not recover jumptable at 0x00018003b9a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*param_2,*param_3);
  return;
}


/* ---- 0x18003b9b0  FUN_18003b9b0  (4 bytes) ---- */

undefined8 FUN_18003b9b0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003b9c0  FUN_18003b9c0  (27 bytes) ---- */

void FUN_18003b9c0(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_18003bf70(*param_1);
                    /* WARNING: Could not recover jumptable at 0x00018003b9d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*param_2,*param_3);
  return;
}


/* ---- 0x18003b9e0  FUN_18003b9e0  (4 bytes) ---- */

undefined8 FUN_18003b9e0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003b9f0  FUN_18003b9f0  (22 bytes) ---- */

void FUN_18003b9f0(undefined8 *param_1,undefined8 *param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_18003bf90(*param_1);
                    /* WARNING: Could not recover jumptable at 0x00018003ba03. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*param_2);
  return;
}


/* ---- 0x18003ba10  FUN_18003ba10  (17 bytes) ---- */

undefined8 * FUN_18003ba10(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}


/* ---- 0x18003ba30  FUN_18003ba30  (4 bytes) ---- */

undefined8 FUN_18003ba30(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003ba40  FUN_18003ba40  (108 bytes) ---- */

void FUN_18003ba40(longlong *param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = (void *)*param_1;
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (param_1[2] - (longlong)pvVar1 & 0xfffffffffffffff8U)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


/* ---- 0x18003bab0  FUN_18003bab0  (118 bytes) ---- */

void FUN_18003bab0(longlong *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)*param_1;
  *(undefined8 *)puVar1[1] = 0;
  puVar1 = (undefined8 *)*puVar1;
  while (puVar1 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)*puVar1;
    FUN_180007d20(puVar1 + 10);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(puVar1 + 5));
    free(puVar1);
    puVar1 = puVar2;
  }
  free((void *)*param_1);
  return;
}


/* ---- 0x18003bb30  FUN_18003bb30  (217 bytes) ---- */

/* WARNING: Removing unreachable block (ram,0x00018003bbe9) */
/* WARNING: Removing unreachable block (ram,0x00018003bbf6) */
/* WARNING: Removing unreachable block (ram,0x00018003bbf8) */

undefined4 * FUN_18003bb30(undefined4 *param_1,undefined4 *param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  void *pvVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 local_res18 [2];
  
  *param_1 = *param_2;
  *(undefined8 *)(param_1 + 2) = 0;
  *(undefined8 *)(param_1 + 4) = 0;
  local_res18[0] = param_3;
  pvVar2 = operator_new(0x70);
  *(void **)pvVar2 = pvVar2;
  *(void **)((longlong)pvVar2 + 8) = pvVar2;
  *(void **)(param_1 + 2) = pvVar2;
  *(undefined8 *)(param_1 + 6) = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 10) = 0;
  *(undefined8 *)(param_1 + 0xc) = 7;
  *(undefined8 *)(param_1 + 0xe) = 8;
  *param_1 = 0x3f800000;
  local_res18[0] = *(undefined8 *)(param_1 + 2);
  uVar4 = 0x80;
  puVar3 = (undefined8 *)operator_new(0x80);
  lVar5 = *(longlong *)(param_1 + 10) - (longlong)*(void **)(param_1 + 6) >> 3;
  if (lVar5 != 0) {
    FUN_1800096c0(uVar4,*(void **)(param_1 + 6),lVar5);
  }
  *(undefined8 **)(param_1 + 6) = puVar3;
  puVar1 = puVar3 + 0x10;
  *(undefined8 **)(param_1 + 8) = puVar1;
  *(undefined8 **)(param_1 + 10) = puVar1;
  FUN_18000a6e0(puVar3,puVar1,local_res18);
  return param_1;
}


/* ---- 0x18003bc10  FUN_18003bc10  (4 bytes) ---- */

undefined8 FUN_18003bc10(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003bc20  FUN_18003bc20  (108 bytes) ---- */

void FUN_18003bc20(longlong *param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = (void *)*param_1;
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (param_1[2] - (longlong)pvVar1 & 0xfffffffffffffff8U)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


/* ---- 0x18003bc90  FUN_18003bc90  (118 bytes) ---- */

void FUN_18003bc90(longlong *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)*param_1;
  *(undefined8 *)puVar1[1] = 0;
  puVar1 = (undefined8 *)*puVar1;
  while (puVar1 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)*puVar1;
    FUN_18000c620(puVar1 + 6);
    FUN_18000c770(puVar1 + 4);
    free(puVar1);
    puVar1 = puVar2;
  }
  free((void *)*param_1);
  return;
}


/* ---- 0x18003bd10  FUN_18003bd10  (217 bytes) ---- */

/* WARNING: Removing unreachable block (ram,0x00018003bdc9) */
/* WARNING: Removing unreachable block (ram,0x00018003bdd6) */
/* WARNING: Removing unreachable block (ram,0x00018003bdd8) */

undefined4 * FUN_18003bd10(undefined4 *param_1,undefined4 *param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  void *pvVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 local_res18 [2];
  
  *param_1 = *param_2;
  *(undefined8 *)(param_1 + 2) = 0;
  *(undefined8 *)(param_1 + 4) = 0;
  local_res18[0] = param_3;
  pvVar2 = operator_new(0x58);
  *(void **)pvVar2 = pvVar2;
  *(void **)((longlong)pvVar2 + 8) = pvVar2;
  *(void **)(param_1 + 2) = pvVar2;
  *(undefined8 *)(param_1 + 6) = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 10) = 0;
  *(undefined8 *)(param_1 + 0xc) = 7;
  *(undefined8 *)(param_1 + 0xe) = 8;
  *param_1 = 0x3f800000;
  local_res18[0] = *(undefined8 *)(param_1 + 2);
  uVar4 = 0x80;
  puVar3 = (undefined8 *)operator_new(0x80);
  lVar5 = *(longlong *)(param_1 + 10) - (longlong)*(void **)(param_1 + 6) >> 3;
  if (lVar5 != 0) {
    FUN_180009aa0(uVar4,*(void **)(param_1 + 6),lVar5);
  }
  *(undefined8 **)(param_1 + 6) = puVar3;
  puVar1 = puVar3 + 0x10;
  *(undefined8 **)(param_1 + 8) = puVar1;
  *(undefined8 **)(param_1 + 10) = puVar1;
  FUN_18000a710(puVar3,puVar1,local_res18);
  return param_1;
}


/* ---- 0x18003bdf0  FUN_18003bdf0  (10 bytes) ---- */

undefined4 * FUN_18003bdf0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}


/* ---- 0x18003be00  FUN_18003be00  (4 bytes) ---- */

undefined8 FUN_18003be00(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003be10  FUN_18003be10  (157 bytes) ---- */

void FUN_18003be10(longlong *param_1)

{
  longlong lVar1;
  void *pvVar2;
  void *_Memory;
  longlong lVar3;
  
  lVar3 = *param_1;
  if (lVar3 != 0) {
    lVar1 = param_1[1];
    for (; lVar3 != lVar1; lVar3 = lVar3 + 0x40) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(lVar3 + 0x20));
    }
    pvVar2 = (void *)*param_1;
    _Memory = pvVar2;
    if ((0xfff < (param_1[2] - (longlong)pvVar2 & 0xffffffffffffffc0U)) &&
       (_Memory = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


/* ---- 0x18003beb0  FUN_18003beb0  (12 bytes) ---- */

undefined8 FUN_18003beb0(void)

{
  return DAT_1801d9540;
}


/* ---- 0x18003bec0  FUN_18003bec0  (12 bytes) ---- */

undefined8 FUN_18003bec0(void)

{
  return DAT_1801d9550;
}


/* ---- 0x18003bed0  FUN_18003bed0  (12 bytes) ---- */

undefined8 FUN_18003bed0(void)

{
  return DAT_1801d9548;
}


/* ---- 0x18003bee0  FUN_18003bee0  (12 bytes) ---- */

undefined8 FUN_18003bee0(void)

{
  return DAT_1801d9598;
}


/* ---- 0x18003bef0  FUN_18003bef0  (12 bytes) ---- */

undefined8 FUN_18003bef0(void)

{
  return DAT_1801d9578;
}


/* ---- 0x18003bf00  FUN_18003bf00  (4 bytes) ---- */

undefined8 FUN_18003bf00(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003bf10  FUN_18003bf10  (4 bytes) ---- */

undefined2 FUN_18003bf10(undefined2 *param_1)

{
  return *param_1;
}


/* ---- 0x18003bf20  FUN_18003bf20  (4 bytes) ---- */

undefined8 FUN_18003bf20(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003bf30  FUN_18003bf30  (4 bytes) ---- */

undefined8 FUN_18003bf30(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003bf40  FUN_18003bf40  (4 bytes) ---- */

undefined8 FUN_18003bf40(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003bf50  FUN_18003bf50  (4 bytes) ---- */

undefined8 FUN_18003bf50(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003bf60  FUN_18003bf60  (4 bytes) ---- */

undefined8 FUN_18003bf60(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003bf70  FUN_18003bf70  (4 bytes) ---- */

undefined8 FUN_18003bf70(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003bf80  FUN_18003bf80  (4 bytes) ---- */

undefined8 FUN_18003bf80(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003bf90  FUN_18003bf90  (4 bytes) ---- */

undefined8 FUN_18003bf90(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003bfa0  FUN_18003bfa0  (17 bytes) ---- */

undefined8 * FUN_18003bfa0(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}


/* ---- 0x18003bfc0  FUN_18003bfc0  (17 bytes) ---- */

undefined8 * FUN_18003bfc0(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}


/* ---- 0x18003bfe0  FUN_18003bfe0  (9 bytes) ---- */

undefined4 *
FUN_18003bfe0(undefined4 *param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  *param_1 = *param_4;
  return param_1;
}


/* ---- 0x18003bff0  FUN_18003bff0  (4 bytes) ---- */

undefined8 FUN_18003bff0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c000  FUN_18003c000  (4 bytes) ---- */

undefined8 FUN_18003c000(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c010  FUN_18003c010  (4 bytes) ---- */

undefined8 FUN_18003c010(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c020  FUN_18003c020  (4 bytes) ---- */

undefined8 FUN_18003c020(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c030  FUN_18003c030  (4 bytes) ---- */

undefined8 FUN_18003c030(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c040  FUN_18003c040  (47 bytes) ---- */

undefined8 * FUN_18003c040(undefined8 *param_1)

{
  void *pvVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  pvVar1 = operator_new(0x70);
  *(void **)pvVar1 = pvVar1;
  *(void **)((longlong)pvVar1 + 8) = pvVar1;
  *param_1 = pvVar1;
  return param_1;
}


/* ---- 0x18003c070  FUN_18003c070  (4 bytes) ---- */

undefined8 FUN_18003c070(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c080  FUN_18003c080  (8 bytes) ---- */

undefined4 * FUN_18003c080(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


/* ---- 0x18003c0c0  FUN_18003c0c0  (4 bytes) ---- */

undefined8 FUN_18003c0c0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c0d0  FUN_18003c0d0  (8 bytes) ---- */

undefined4 * FUN_18003c0d0(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


/* ---- 0x18003c0e0  FUN_18003c0e0  (17 bytes) ---- */

undefined8 * FUN_18003c0e0(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}


/* ---- 0x18003c100  FUN_18003c100  (4 bytes) ---- */

undefined8 FUN_18003c100(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c110  FUN_18003c110  (9 bytes) ---- */

undefined4 * FUN_18003c110(undefined4 *param_1,undefined8 param_2,undefined4 *param_3)

{
  *param_1 = *param_3;
  return param_1;
}


/* ---- 0x18003c120  FUN_18003c120  (4 bytes) ---- */

undefined8 FUN_18003c120(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c130  FUN_18003c130  (17 bytes) ---- */

undefined8 * FUN_18003c130(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}


/* ---- 0x18003c150  FUN_18003c150  (4 bytes) ---- */

undefined8 FUN_18003c150(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c160  FUN_18003c160  (17 bytes) ---- */

undefined8 * FUN_18003c160(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}


/* ---- 0x18003c180  FUN_18003c180  (13 bytes) ---- */

undefined8 * FUN_18003c180(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}


/* ---- 0x18003c190  FUN_18003c190  (13 bytes) ---- */

undefined8 * FUN_18003c190(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}


/* ---- 0x18003c1a0  FUN_18003c1a0  (35 bytes) ---- */

void FUN_18003c1a0(undefined8 *param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x70);
  *(void **)pvVar1 = pvVar1;
  *(void **)((longlong)pvVar1 + 8) = pvVar1;
  *param_1 = pvVar1;
  return;
}


/* ---- 0x18003c200  FUN_18003c200  (4 bytes) ---- */

undefined8 FUN_18003c200(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c210  FUN_18003c210  (4 bytes) ---- */

undefined8 FUN_18003c210(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c220  FUN_18003c220  (4 bytes) ---- */

undefined8 FUN_18003c220(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c230  FUN_18003c230  (4 bytes) ---- */

undefined8 FUN_18003c230(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c240  FUN_18003c240  (4 bytes) ---- */

undefined8 FUN_18003c240(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c250  FUN_18003c250  (7 bytes) ---- */

void FUN_18003c250(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


/* ---- 0x18003c260  FUN_18003c260  (7 bytes) ---- */

void FUN_18003c260(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


/* ---- 0x18003c270  FUN_18003c270  (17 bytes) ---- */

undefined8 * FUN_18003c270(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}


/* ---- 0x18003c290  FUN_18003c290  (13 bytes) ---- */

undefined8 * FUN_18003c290(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}


/* ---- 0x18003c2a0  FUN_18003c2a0  (17 bytes) ---- */

undefined8 * FUN_18003c2a0(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}


/* ---- 0x18003c2c0  FUN_18003c2c0  (13 bytes) ---- */

undefined8 * FUN_18003c2c0(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}


/* ---- 0x18003c2d0  FUN_18003c2d0  (10 bytes) ---- */

undefined8 * FUN_18003c2d0(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


/* ---- 0x18003c2e0  FUN_18003c2e0  (10 bytes) ---- */

undefined8 * FUN_18003c2e0(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


/* ---- 0x18003c2f0  FUN_18003c2f0  (4 bytes) ---- */

undefined8 FUN_18003c2f0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003c310  FUN_18003c310  (21 bytes) ---- */

undefined8 FUN_18003c310(void)

{
  undefined *puVar1;
  
  puVar1 = REL::Module::get();
  return *(undefined8 *)(puVar1 + 0x110);
}


/* ---- 0x18003c330  FUN_18003c330  (95 bytes) ---- */

ulong64 FUN_18003c330(ulonglong *param_1)

{
  undefined *puVar1;
  IDDatabase *pIVar2;
  ulong64 uVar3;
  
  puVar1 = REL::Module::get();
  if (puVar1[0x118] == '\x01') {
    if (param_1[1] != 0) {
      pIVar2 = (IDDatabase *)REL::IDDatabase::get();
      uVar3 = REL::IDDatabase::id2offset(pIVar2,param_1[1]);
      return uVar3;
    }
  }
  else if ((puVar1[0x118] == '\x02') && (*param_1 != 0)) {
    pIVar2 = (IDDatabase *)REL::IDDatabase::get();
    uVar3 = REL::IDDatabase::id2offset(pIVar2,*param_1);
    return uVar3;
  }
  return 0;
}


/* ---- 0x18003c390  FUN_18003c390  (127 bytes) ---- */

longlong FUN_18003c390(ulonglong *param_1)

{
  longlong lVar1;
  undefined *puVar2;
  IDDatabase *this;
  ulong64 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    if (param_1[1] == 0) {
      return 0;
    }
    this = (IDDatabase *)REL::IDDatabase::get();
    uVar5 = param_1[1];
  }
  else {
    if (puVar2[0x118] != '\x02') {
      return 0;
    }
    if (*param_1 == 0) {
      return 0;
    }
    this = (IDDatabase *)REL::IDDatabase::get();
    uVar5 = *param_1;
  }
  uVar3 = REL::IDDatabase::id2offset(this,uVar5);
  if (uVar3 == 0) {
    return 0;
  }
  puVar2 = REL::Module::get();
  lVar1 = *(longlong *)(puVar2 + 0x110);
  lVar4 = FUN_18003c330(param_1);
  return lVar4 + lVar1;
}


/* ---- 0x18003c410  FUN_18003c410  (4 bytes) ---- */

undefined4 FUN_18003c410(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}


/* ---- 0x18003c420  FUN_18003c420  (113 bytes) ---- */

longlong FUN_18003c420(undefined8 param_1,longlong param_2,longlong param_3,longlong param_4)

{
  char cVar1;
  undefined *puVar2;
  ulonglong uVar3;
  undefined8 local_res8;
  undefined8 local_res10;
  
  local_res8 = param_1;
  puVar2 = REL::Module::get();
  uVar3 = 0;
  local_res10 = *(undefined8 *)(puVar2 + 0x108);
  do {
    if (*(ushort *)((longlong)&local_res10 + uVar3) != *(ushort *)((longlong)&local_res8 + uVar3)) {
      cVar1 = '\x01';
      if (*(ushort *)((longlong)&local_res10 + uVar3) < *(ushort *)((longlong)&local_res8 + uVar3))
      {
        cVar1 = -1;
      }
      goto LAB_18003c477;
    }
    uVar3 = uVar3 + 2;
  } while (uVar3 < 8);
  cVar1 = '\0';
LAB_18003c477:
  if (cVar1 == -1) {
    param_4 = param_3;
  }
  return param_2 + param_4;
}


/* ---- 0x18003c4a0  FUN_18003c4a0  (112 bytes) ---- */

longlong FUN_18003c4a0(longlong param_1)

{
  ushort uVar1;
  undefined *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  char cVar5;
  undefined8 local_res8;
  ushort local_res10 [12];
  
  local_res10[0] = 1;
  local_res10[1] = 6;
  local_res10[2] = 0x275;
  local_res10[3] = 0;
  puVar2 = REL::Module::get();
  local_res8 = *(undefined8 *)(puVar2 + 0x108);
  uVar3 = 0;
  do {
    uVar1 = *(ushort *)((longlong)local_res10 + (uVar3 - 8));
    if (uVar1 != *(ushort *)((longlong)local_res10 + uVar3)) {
      cVar5 = '\x01';
      if (uVar1 < *(ushort *)((longlong)local_res10 + uVar3)) {
        cVar5 = -1;
      }
      goto LAB_18003c4f7;
    }
    uVar3 = uVar3 + 2;
  } while (uVar3 < 8);
  cVar5 = '\0';
LAB_18003c4f7:
  lVar4 = 0x3d8;
  if (cVar5 != -1) {
    lVar4 = 0x3e0;
  }
  return lVar4 + param_1;
}


/* ---- 0x18003c510  FUN_18003c510  (26 bytes) ---- */

longlong FUN_18003c510(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = FUN_18003a520(param_2,param_2,param_3);
  return lVar1 + param_1;
}


/* ---- 0x18003c530  FUN_18003c530  (55 bytes) ---- */

longlong FUN_18003c530(longlong param_1)

{
  undefined *puVar1;
  longlong lVar2;
  
  REL::Module::get();
  puVar1 = REL::Module::get();
  if ((puVar1[0x118] == '\x01') || (puVar1[0x118] != '\x04')) {
    lVar2 = 0;
  }
  else {
    lVar2 = 0x3d8;
  }
  return lVar2 + param_1;
}


/* ---- 0x18003c580  FUN_18003c580  (29 bytes) ---- */

longlong * FUN_18003c580(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x18003c5a0  FUN_18003c5a0  (29 bytes) ---- */

longlong * FUN_18003c5a0(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x18003c5c0  FUN_18003c5c0  (4 bytes) ---- */

undefined8 FUN_18003c5c0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c5d0  FUN_18003c5d0  (4 bytes) ---- */

undefined8 FUN_18003c5d0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c5e0  FUN_18003c5e0  (17 bytes) ---- */

undefined8 * FUN_18003c5e0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  *param_1 = *param_2;
  param_1[1] = *param_3;
  return param_1;
}


/* ---- 0x18003c600  FUN_18003c600  (4 bytes) ---- */

undefined8 FUN_18003c600(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c610  FUN_18003c610  (7 bytes) ---- */

undefined8 * FUN_18003c610(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x18003c620  FUN_18003c620  (7 bytes) ---- */

undefined8 * FUN_18003c620(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x18003c630  FUN_18003c630  (4 bytes) ---- */

undefined8 FUN_18003c630(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c640  FUN_18003c640  (8 bytes) ---- */

undefined8 FUN_18003c640(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003c650  FUN_18003c650  (8 bytes) ---- */

undefined8 FUN_18003c650(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003c660  FUN_18003c660  (4 bytes) ---- */

undefined8 FUN_18003c660(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c670  FUN_18003c670  (8 bytes) ---- */

undefined8 FUN_18003c670(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003c680  FUN_18003c680  (8 bytes) ---- */

undefined8 FUN_18003c680(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003c690  FUN_18003c690  (259 bytes) ---- */

undefined8 * FUN_18003c690(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  int *piVar3;
  ulonglong local_18 [2];
  
  piVar3 = (int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
                  0x14);
  if (*piVar3 < DAT_1801d96e4) {
    _Init_thread_header(&DAT_1801d96e4);
    if (DAT_1801d96e4 == -1) {
      local_18[0] = 0x7d92f;
      local_18[1] = 0x61c7b;
      DAT_1801d96d8 = FUN_18000f860(local_18);
      _Init_thread_footer(&DAT_1801d96e4);
    }
  }
  if (*piVar3 < DAT_1801d96e0) {
    _Init_thread_header(&DAT_1801d96e0);
    if (DAT_1801d96e0 == -1) {
      local_18[0] = 0x7d938;
      local_18[1] = 0x61c85;
      DAT_1801d96d0 = FUN_18000f860(local_18);
      _Init_thread_footer(&DAT_1801d96e0);
    }
  }
  puVar1 = (undefined8 *)FUN_18003c660(DAT_1801d96d8);
  *param_1 = *puVar1;
  uVar2 = FUN_18003c630(DAT_1801d96d0);
  param_1[1] = uVar2;
  return param_1;
}


/* ---- 0x18003c7a0  FUN_18003c7a0  (4 bytes) ---- */

undefined8 FUN_18003c7a0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c7b0  FUN_18003c7b0  (5 bytes) ---- */

longlong FUN_18003c7b0(longlong param_1)

{
  return param_1 + 8;
}


/* ---- 0x18003c7c0  FUN_18003c7c0  (4 bytes) ---- */

undefined8 FUN_18003c7c0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003c7d0  FUN_18003c7d0  (7 bytes) ---- */

int FUN_18003c7d0(longlong param_1)

{
  return *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10);
}


/* ---- 0x18003c7e0  FUN_18003c7e0  (10 bytes) ---- */

undefined4 FUN_18003c7e0(longlong param_1)

{
  return CONCAT31((int3)((uint)*(int *)(param_1 + 0x10) >> 8),
                  *(int *)(param_1 + 0xc) == *(int *)(param_1 + 0x10));
}


/* ---- 0x18003c7f0  FUN_18003c7f0  (4 bytes) ---- */

undefined8 FUN_18003c7f0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003c800  FUN_18003c800  (8 bytes) ---- */

longlong FUN_18003c800(longlong *param_1)

{
  return param_1[1] + *param_1;
}


/* ---- 0x18003c810  FUN_18003c810  (5 bytes) ---- */

longlong FUN_18003c810(longlong param_1,longlong param_2)

{
  return param_1 + param_2 * 4;
}


/* ---- 0x18003c8e0  FUN_18003c8e0  (11 bytes) ---- */

undefined8 * FUN_18003c8e0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return param_1;
}


/* ---- 0x18003c8f0  FUN_18003c8f0  (4 bytes) ---- */

undefined8 FUN_18003c8f0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c900  FUN_18003c900  (4 bytes) ---- */

undefined8 FUN_18003c900(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003c910  FUN_18003c910  (11 bytes) ---- */

undefined8 * FUN_18003c910(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return param_1;
}


/* ---- 0x18003c920  FUN_18003c920  (4 bytes) ---- */

undefined8 FUN_18003c920(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003c930  FUN_18003c930  (170 bytes) ---- */

void FUN_18003c930(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 auStackX_10 [4];
  undefined1 auStackX_14 [20];
  undefined8 auStack_408 [129];
  
  lVar7 = 8;
  puVar5 = auStack_408;
  puVar6 = (undefined8 *)&DAT_180191b30;
  do {
    uVar1 = puVar6[1];
    uVar2 = puVar6[2];
    uVar3 = puVar6[3];
    *puVar5 = *puVar6;
    puVar5[1] = uVar1;
    uVar1 = puVar6[4];
    uVar4 = puVar6[5];
    puVar5[2] = uVar2;
    puVar5[3] = uVar3;
    uVar2 = puVar6[6];
    uVar3 = puVar6[7];
    puVar5[4] = uVar1;
    puVar5[5] = uVar4;
    uVar1 = puVar6[8];
    uVar4 = puVar6[9];
    puVar5[6] = uVar2;
    puVar5[7] = uVar3;
    uVar2 = puVar6[10];
    uVar3 = puVar6[0xb];
    puVar5[8] = uVar1;
    puVar5[9] = uVar4;
    uVar1 = puVar6[0xc];
    uVar4 = puVar6[0xd];
    puVar5[10] = uVar2;
    puVar5[0xb] = uVar3;
    uVar2 = puVar6[0xe];
    uVar3 = puVar6[0xf];
    puVar5[0xc] = uVar1;
    puVar5[0xd] = uVar4;
    puVar5[0xe] = uVar2;
    puVar5[0xf] = uVar3;
    lVar7 = lVar7 + -1;
    puVar5 = puVar5 + 0x10;
    puVar6 = puVar6 + 0x10;
  } while (lVar7 != 0);
  puVar8 = auStackX_10;
  do {
    puVar8 = puVar8 + 1;
  } while (puVar8 != auStackX_14);
  return;
}


/* ---- 0x18003c9e0  FUN_18003c9e0  (168 bytes) ---- */

void FUN_18003c9e0(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 auStack_418 [4];
  undefined1 auStack_414 [12];
  undefined8 auStack_408 [129];
  
  puVar8 = auStack_418;
  lVar7 = 8;
  puVar5 = auStack_408;
  puVar6 = (undefined8 *)&DAT_180191b30;
  do {
    uVar1 = puVar6[1];
    uVar2 = puVar6[2];
    uVar3 = puVar6[3];
    *puVar5 = *puVar6;
    puVar5[1] = uVar1;
    uVar1 = puVar6[4];
    uVar4 = puVar6[5];
    puVar5[2] = uVar2;
    puVar5[3] = uVar3;
    uVar2 = puVar6[6];
    uVar3 = puVar6[7];
    puVar5[4] = uVar1;
    puVar5[5] = uVar4;
    uVar1 = puVar6[8];
    uVar4 = puVar6[9];
    puVar5[6] = uVar2;
    puVar5[7] = uVar3;
    uVar2 = puVar6[10];
    uVar3 = puVar6[0xb];
    puVar5[8] = uVar1;
    puVar5[9] = uVar4;
    uVar1 = puVar6[0xc];
    uVar4 = puVar6[0xd];
    puVar5[10] = uVar2;
    puVar5[0xb] = uVar3;
    uVar2 = puVar6[0xe];
    uVar3 = puVar6[0xf];
    puVar5[0xc] = uVar1;
    puVar5[0xd] = uVar4;
    puVar5[0xe] = uVar2;
    puVar5[0xf] = uVar3;
    lVar7 = lVar7 + -1;
    puVar5 = puVar5 + 0x10;
    puVar6 = puVar6 + 0x10;
  } while (lVar7 != 0);
  do {
    puVar8 = puVar8 + 1;
  } while (puVar8 != auStack_414);
  return;
}


/* ---- 0x18003ca90  FUN_18003ca90  (191 bytes) ---- */

longlong FUN_18003ca90(longlong param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  uint *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  byte *pbVar10;
  undefined4 uStack_418;
  byte abStack_414 [12];
  uint auStack_408 [258];
  
  pbVar10 = (byte *)&uStack_418;
  uStack_418 = *param_2;
  lVar9 = 8;
  puVar7 = auStack_408;
  puVar8 = (undefined8 *)&DAT_180191b30;
  do {
    uVar2 = puVar8[1];
    uVar3 = puVar8[2];
    uVar4 = puVar8[3];
    *(undefined8 *)puVar7 = *puVar8;
    *(undefined8 *)(puVar7 + 2) = uVar2;
    uVar2 = puVar8[4];
    uVar5 = puVar8[5];
    *(undefined8 *)(puVar7 + 4) = uVar3;
    *(undefined8 *)(puVar7 + 6) = uVar4;
    uVar3 = puVar8[6];
    uVar4 = puVar8[7];
    *(undefined8 *)(puVar7 + 8) = uVar2;
    *(undefined8 *)(puVar7 + 10) = uVar5;
    uVar2 = puVar8[8];
    uVar5 = puVar8[9];
    *(undefined8 *)(puVar7 + 0xc) = uVar3;
    *(undefined8 *)(puVar7 + 0xe) = uVar4;
    uVar3 = puVar8[10];
    uVar4 = puVar8[0xb];
    *(undefined8 *)(puVar7 + 0x10) = uVar2;
    *(undefined8 *)(puVar7 + 0x12) = uVar5;
    uVar2 = puVar8[0xc];
    uVar5 = puVar8[0xd];
    *(undefined8 *)(puVar7 + 0x14) = uVar3;
    *(undefined8 *)(puVar7 + 0x16) = uVar4;
    uVar3 = puVar8[0xe];
    uVar4 = puVar8[0xf];
    *(undefined8 *)(puVar7 + 0x18) = uVar2;
    *(undefined8 *)(puVar7 + 0x1a) = uVar5;
    *(undefined8 *)(puVar7 + 0x1c) = uVar3;
    *(undefined8 *)(puVar7 + 0x1e) = uVar4;
    lVar9 = lVar9 + -1;
    puVar7 = puVar7 + 0x20;
    puVar8 = puVar8 + 0x10;
  } while (lVar9 != 0);
  uVar6 = 0;
  do {
    bVar1 = *pbVar10;
    pbVar10 = pbVar10 + 1;
    uVar6 = uVar6 >> 8 ^ auStack_408[((ulonglong)bVar1 ^ (ulonglong)uVar6) & 0xff];
  } while (pbVar10 != abStack_414);
  return *(longlong *)(param_1 + 0x28) + (ulonglong)(*(int *)(param_1 + 0xc) - 1U & uVar6) * 0x18;
}


/* ---- 0x18003cb50  FUN_18003cb50  (9 bytes) ---- */

undefined4 FUN_18003cb50(undefined8 param_1,int *param_2,int *param_3)

{
  return CONCAT31((int3)((uint)*param_3 >> 8),*param_2 == *param_3);
}


/* ---- 0x18003cb60  FUN_18003cb60  (9 bytes) ---- */

undefined4 FUN_18003cb60(undefined8 param_1,int *param_2,int *param_3)

{
  return CONCAT31((int3)((uint)*param_3 >> 8),*param_2 == *param_3);
}


/* ---- 0x18003cb70  FUN_18003cb70  (4 bytes) ---- */

undefined8 FUN_18003cb70(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003cb80  FUN_18003cb80  (4 bytes) ---- */

undefined8 FUN_18003cb80(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003cb90  FUN_18003cb90  (71 bytes) ---- */

longlong * FUN_18003cb90(longlong param_1,longlong *param_2,longlong param_3)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  
  uVar2 = *(uint *)(param_1 + 0xc);
  *param_2 = param_3;
  lVar1 = *(longlong *)(param_1 + 0x28) + (ulonglong)uVar2 * 0x18;
  param_2[1] = lVar1;
  if (((param_3 != 0) && (lVar1 != 0)) && (param_3 != lVar1)) {
    lVar3 = *(longlong *)(param_3 + 0x10);
    while (lVar3 == 0) {
      lVar4 = param_3 + 0x18;
      *param_2 = lVar4;
      if (lVar4 == lVar1) {
        return param_2;
      }
      lVar3 = *(longlong *)(param_3 + 0x28);
      param_3 = lVar4;
    }
  }
  return param_2;
}


/* ---- 0x18003cbe0  FUN_18003cbe0  (351 bytes) ---- */

longlong * FUN_18003cbe0(longlong param_1,longlong *param_2,int *param_3)

{
  longlong *plVar1;
  int *piVar2;
  byte bVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint *puVar9;
  int *piVar10;
  undefined8 *puVar12;
  ulonglong uVar13;
  uint uVar14;
  longlong lVar15;
  ulonglong uVar16;
  byte *pbVar17;
  int iStack_418;
  byte abStack_414 [12];
  uint auStack_408 [256];
  int *piVar11;
  
  pbVar17 = (byte *)&iStack_418;
  uVar4 = *(uint *)(param_1 + 0xc);
  uVar16 = (ulonglong)uVar4;
  if (uVar4 == *(uint *)(param_1 + 0x10)) {
    lVar15 = *(longlong *)(param_1 + 0x28) + uVar16 * 0x18;
    *param_2 = lVar15;
    param_2[1] = lVar15;
    return param_2;
  }
  iStack_418 = *param_3;
  lVar15 = 8;
  puVar9 = auStack_408;
  puVar12 = (undefined8 *)&DAT_180191b30;
  do {
    uVar5 = puVar12[1];
    uVar6 = puVar12[2];
    uVar7 = puVar12[3];
    *(undefined8 *)puVar9 = *puVar12;
    *(undefined8 *)(puVar9 + 2) = uVar5;
    uVar5 = puVar12[4];
    uVar8 = puVar12[5];
    *(undefined8 *)(puVar9 + 4) = uVar6;
    *(undefined8 *)(puVar9 + 6) = uVar7;
    uVar6 = puVar12[6];
    uVar7 = puVar12[7];
    *(undefined8 *)(puVar9 + 8) = uVar5;
    *(undefined8 *)(puVar9 + 10) = uVar8;
    uVar5 = puVar12[8];
    uVar8 = puVar12[9];
    *(undefined8 *)(puVar9 + 0xc) = uVar6;
    *(undefined8 *)(puVar9 + 0xe) = uVar7;
    uVar6 = puVar12[10];
    uVar7 = puVar12[0xb];
    *(undefined8 *)(puVar9 + 0x10) = uVar5;
    *(undefined8 *)(puVar9 + 0x12) = uVar8;
    uVar5 = puVar12[0xc];
    uVar8 = puVar12[0xd];
    *(undefined8 *)(puVar9 + 0x14) = uVar6;
    *(undefined8 *)(puVar9 + 0x16) = uVar7;
    uVar6 = puVar12[0xe];
    uVar7 = puVar12[0xf];
    *(undefined8 *)(puVar9 + 0x18) = uVar5;
    *(undefined8 *)(puVar9 + 0x1a) = uVar8;
    *(undefined8 *)(puVar9 + 0x1c) = uVar6;
    *(undefined8 *)(puVar9 + 0x1e) = uVar7;
    lVar15 = lVar15 + -1;
    puVar9 = puVar9 + 0x20;
    puVar12 = puVar12 + 0x10;
  } while (lVar15 != 0);
  uVar13 = 0;
  do {
    bVar3 = *pbVar17;
    pbVar17 = pbVar17 + 1;
    uVar14 = (uint)uVar13 >> 8 ^ auStack_408[(bVar3 ^ uVar13) & 0xff];
    uVar13 = (ulonglong)uVar14;
  } while (pbVar17 != abStack_414);
  lVar15 = *(longlong *)(param_1 + 0x28);
  uVar13 = (ulonglong)(uVar4 - 1 & uVar14);
  piVar10 = (int *)(lVar15 + uVar13 * 0x18);
  if (*(longlong *)(lVar15 + 0x10 + uVar13 * 0x18) != 0) {
    do {
      if (*piVar10 == iStack_418) {
        *param_2 = (longlong)piVar10;
        piVar2 = (int *)(lVar15 + uVar16 * 0x18);
        param_2[1] = (longlong)piVar2;
        if (piVar2 == (int *)0x0) {
          return param_2;
        }
        if (piVar10 == piVar2) {
          return param_2;
        }
        if (*(longlong *)(piVar10 + 4) != 0) {
          return param_2;
        }
        do {
          piVar11 = piVar10 + 6;
          *param_2 = (longlong)piVar11;
          if (piVar11 == piVar2) {
            return param_2;
          }
          plVar1 = (longlong *)(piVar10 + 10);
          piVar10 = piVar11;
        } while (*plVar1 == 0);
        return param_2;
      }
      piVar10 = *(int **)(piVar10 + 4);
    } while (piVar10 != *(int **)(param_1 + 0x18));
  }
  lVar15 = lVar15 + uVar16 * 0x18;
  *param_2 = lVar15;
  param_2[1] = lVar15;
  return param_2;
}


/* ---- 0x18003cd40  FUN_18003cd40  (351 bytes) ---- */

longlong * FUN_18003cd40(longlong param_1,longlong *param_2,int *param_3)

{
  longlong *plVar1;
  int *piVar2;
  byte bVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint *puVar9;
  int *piVar10;
  undefined8 *puVar12;
  ulonglong uVar13;
  uint uVar14;
  longlong lVar15;
  ulonglong uVar16;
  byte *pbVar17;
  int iStack_418;
  byte abStack_414 [12];
  uint auStack_408 [256];
  int *piVar11;
  
  pbVar17 = (byte *)&iStack_418;
  uVar4 = *(uint *)(param_1 + 0xc);
  uVar16 = (ulonglong)uVar4;
  if (uVar4 == *(uint *)(param_1 + 0x10)) {
    lVar15 = *(longlong *)(param_1 + 0x28) + uVar16 * 0x18;
    *param_2 = lVar15;
    param_2[1] = lVar15;
    return param_2;
  }
  iStack_418 = *param_3;
  lVar15 = 8;
  puVar9 = auStack_408;
  puVar12 = (undefined8 *)&DAT_180191b30;
  do {
    uVar5 = puVar12[1];
    uVar6 = puVar12[2];
    uVar7 = puVar12[3];
    *(undefined8 *)puVar9 = *puVar12;
    *(undefined8 *)(puVar9 + 2) = uVar5;
    uVar5 = puVar12[4];
    uVar8 = puVar12[5];
    *(undefined8 *)(puVar9 + 4) = uVar6;
    *(undefined8 *)(puVar9 + 6) = uVar7;
    uVar6 = puVar12[6];
    uVar7 = puVar12[7];
    *(undefined8 *)(puVar9 + 8) = uVar5;
    *(undefined8 *)(puVar9 + 10) = uVar8;
    uVar5 = puVar12[8];
    uVar8 = puVar12[9];
    *(undefined8 *)(puVar9 + 0xc) = uVar6;
    *(undefined8 *)(puVar9 + 0xe) = uVar7;
    uVar6 = puVar12[10];
    uVar7 = puVar12[0xb];
    *(undefined8 *)(puVar9 + 0x10) = uVar5;
    *(undefined8 *)(puVar9 + 0x12) = uVar8;
    uVar5 = puVar12[0xc];
    uVar8 = puVar12[0xd];
    *(undefined8 *)(puVar9 + 0x14) = uVar6;
    *(undefined8 *)(puVar9 + 0x16) = uVar7;
    uVar6 = puVar12[0xe];
    uVar7 = puVar12[0xf];
    *(undefined8 *)(puVar9 + 0x18) = uVar5;
    *(undefined8 *)(puVar9 + 0x1a) = uVar8;
    *(undefined8 *)(puVar9 + 0x1c) = uVar6;
    *(undefined8 *)(puVar9 + 0x1e) = uVar7;
    lVar15 = lVar15 + -1;
    puVar9 = puVar9 + 0x20;
    puVar12 = puVar12 + 0x10;
  } while (lVar15 != 0);
  uVar13 = 0;
  do {
    bVar3 = *pbVar17;
    pbVar17 = pbVar17 + 1;
    uVar14 = (uint)uVar13 >> 8 ^ auStack_408[(uVar13 ^ bVar3) & 0xff];
    uVar13 = (ulonglong)uVar14;
  } while (pbVar17 != abStack_414);
  lVar15 = *(longlong *)(param_1 + 0x28);
  uVar13 = (ulonglong)(uVar4 - 1 & uVar14);
  piVar10 = (int *)(lVar15 + uVar13 * 0x18);
  if (*(longlong *)(lVar15 + 0x10 + uVar13 * 0x18) != 0) {
    do {
      if (*piVar10 == iStack_418) {
        *param_2 = (longlong)piVar10;
        piVar2 = (int *)(lVar15 + uVar16 * 0x18);
        param_2[1] = (longlong)piVar2;
        if (piVar2 == (int *)0x0) {
          return param_2;
        }
        if (piVar10 == piVar2) {
          return param_2;
        }
        if (*(longlong *)(piVar10 + 4) != 0) {
          return param_2;
        }
        do {
          piVar11 = piVar10 + 6;
          *param_2 = (longlong)piVar11;
          if (piVar11 == piVar2) {
            return param_2;
          }
          plVar1 = (longlong *)(piVar10 + 10);
          piVar10 = piVar11;
        } while (*plVar1 == 0);
        return param_2;
      }
      piVar10 = *(int **)(piVar10 + 4);
    } while (piVar10 != *(int **)(param_1 + 0x18));
  }
  lVar15 = lVar15 + uVar16 * 0x18;
  *param_2 = lVar15;
  param_2[1] = lVar15;
  return param_2;
}


/* ---- 0x18003cea0  FUN_18003cea0  (10 bytes) ---- */

undefined8 FUN_18003cea0(longlong *param_1,longlong *param_2)

{
  return CONCAT71((int7)((ulonglong)*param_2 >> 8),*param_1 == *param_2);
}


/* ---- 0x18003ceb0  FUN_18003ceb0  (28 bytes) ---- */

ulonglong FUN_18003ceb0(ulonglong *param_1)

{
  ulonglong in_RAX;
  
  if (((*param_1 != 0) && (in_RAX = param_1[1], in_RAX != 0)) && (*param_1 != in_RAX)) {
    return CONCAT71((int7)(in_RAX >> 8),1);
  }
  return in_RAX & 0xffffffffffffff00;
}


/* ---- 0x18003ced0  FUN_18003ced0  (9 bytes) ---- */

bool FUN_18003ced0(longlong param_1)

{
  return *(longlong *)(param_1 + 0x10) != 0;
}


/* ---- 0x18003cee0  FUN_18003cee0  (39 bytes) ---- */

void FUN_18003cee0(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  do {
    lVar1 = *param_1;
    lVar2 = lVar1 + 0x18;
    *param_1 = lVar2;
    if (lVar2 == param_1[1]) {
      return;
    }
  } while (*(longlong *)(lVar1 + 0x28) == 0);
  return;
}


/* ---- 0x18003cf10  FUN_18003cf10  (55 bytes) ---- */

longlong * FUN_18003cf10(longlong *param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  if (((param_2 != 0) && (param_3 != 0)) && (param_2 != param_3)) {
    lVar1 = *(longlong *)(param_2 + 0x10);
    while (lVar1 == 0) {
      lVar2 = param_2 + 0x18;
      *param_1 = lVar2;
      if (lVar2 == param_3) {
        return param_1;
      }
      lVar1 = *(longlong *)(param_2 + 0x28);
      param_2 = lVar2;
    }
  }
  return param_1;
}


/* ---- 0x18003cf50  FUN_18003cf50  (5 bytes) ---- */

undefined8 FUN_18003cf50(longlong param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


/* ---- 0x18003cf60  FUN_18003cf60  (5 bytes) ---- */

undefined8 FUN_18003cf60(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x28);
}


/* ---- 0x18003cf70  FUN_18003cf70  (26 bytes) ---- */

longlong * FUN_18003cf70(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x28) + (ulonglong)*(uint *)(param_1 + 0xc) * 0x18;
  *param_2 = lVar1;
  param_2[1] = lVar1;
  return param_2;
}


/* ---- 0x18003cf90  FUN_18003cf90  (26 bytes) ---- */

longlong * FUN_18003cf90(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x28) + (ulonglong)*(uint *)(param_1 + 0xc) * 0x18;
  *param_2 = lVar1;
  param_2[1] = lVar1;
  return param_2;
}


/* ---- 0x18003cfb0  FUN_18003cfb0  (4 bytes) ---- */

undefined8 FUN_18003cfb0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003cfc0  FUN_18003cfc0  (4 bytes) ---- */

undefined8 FUN_18003cfc0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003d240  FUN_18003d240  (29 bytes) ---- */

longlong * FUN_18003d240(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x18003d260  FUN_18003d260  (4 bytes) ---- */

undefined8 FUN_18003d260(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18003d270  FUN_18003d270  (8 bytes) ---- */

undefined8 FUN_18003d270(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003d280  FUN_18003d280  (8 bytes) ---- */

undefined8 FUN_18003d280(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003d290  FUN_18003d290  (44 bytes) ---- */

void FUN_18003d290(void)

{
  longlong lVar1;
  ulonglong local_18 [3];
  
  local_18[0] = 0x7fd89;
  local_18[1] = 0x64254;
  lVar1 = FUN_18000f860(local_18);
  FUN_18003d260(lVar1);
  return;
}


/* ---- 0x18003d2c0  FUN_18003d2c0  (8 bytes) ---- */

longlong FUN_18003d2c0(longlong param_1,longlong param_2)

{
  return param_1 + param_2 * 0x10;
}


/* ---- 0x18003d2d0  FUN_18003d2d0  (34 bytes) ---- */

undefined8 * FUN_18003d2d0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 *this;
  
  this = param_1;
  FUN_180045700(param_1);
  RE::GFxValue::operator=(this,param_2);
  return param_1;
}


/* ---- 0x18003d300  FUN_18003d300  (66 bytes) ---- */

undefined8 * FUN_18003d300(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  
  puVar1 = param_2;
  FUN_180045700(param_2);
  FUN_180045f80(param_1,*param_3,puVar1);
  return param_2;
}


/* ---- 0x18003d350  FUN_18003d350  (8 bytes) ---- */

void FUN_18003d350(undefined8 *param_1,undefined8 *param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = *param_2;
  RE::GFxValue::IsDisplayObject(param_1);
  FUN_180044ee0(*param_1,param_1[2],uVar1,param_3);
  return;
}


/* ---- 0x18003d370  FUN_18003d370  (34 bytes) ---- */

undefined8 * FUN_18003d370(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 *this;
  
  this = param_1;
  FUN_180045700(param_1);
  RE::GFxValue::operator=(this,param_2);
  return param_1;
}


/* ---- 0x18003d3a0  FUN_18003d3a0  (554 bytes) ---- */

void FUN_18003d3a0(undefined8 *param_1,float *param_2)

{
  longlong *plVar1;
  char cVar2;
  double dVar3;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  undefined4 local_a8;
  undefined8 local_a0 [3];
  undefined1 local_88 [24];
  undefined1 local_70 [24];
  undefined8 local_58 [3];
  undefined8 local_40 [3];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_d8;
  local_a8 = 0;
  plVar1 = *(longlong **)*param_1;
  FUN_180045700(local_a0);
  __builtin_array_init_helper_eh<RE::GFxValue>(local_40);
  local_b8 = (ulonglong)local_b8._4_4_ << 0x20;
  (**(code **)(*plVar1 + 0x68))(plVar1,local_a0,0,0);
  _eh_vector_destructor_iterator_(local_40,0x18,1,RE::GFxValue::~GFxValue);
  RE::GFxValue::GFxValue(local_70,0.0);
  FUN_180045fb0(local_a0,&DAT_180190480,local_70);
  RE::GFxValue::GFxValue(local_88,0.0);
  FUN_180045fb0(local_a0,&DAT_180190484,local_88);
  FUN_180045700(local_40);
  local_a8 = 1;
  RE::GFxValue::GFxValue(local_58,local_a0);
  local_b8 = 1;
  cVar2 = RE::GFxValue::Invoke(param_1,"localToGlobal",local_40);
  if (cVar2 == '\0') {
    _eh_vector_destructor_iterator_(local_58,0x18,1,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(local_58,0x18,1,RE::GFxValue::~GFxValue);
  }
  RE::GFxValue::~GFxValue(local_40);
  FUN_180045700(local_58);
  local_a8 = 2;
  FUN_180045f80(local_a0,&DAT_180190480,local_58);
  RE::GFxValue::operator=(local_70,local_58);
  RE::GFxValue::~GFxValue(local_58);
  FUN_180045700(local_58);
  local_a8 = 4;
  FUN_180045f80(local_a0,&DAT_180190484,local_58);
  RE::GFxValue::operator=(local_88,local_58);
  RE::GFxValue::~GFxValue(local_58);
  dVar3 = RE::GFxValue::GetNumber(local_70);
  *param_2 = (float)dVar3;
  dVar3 = RE::GFxValue::GetNumber(local_88);
  param_2[1] = (float)dVar3;
  RE::GFxValue::~GFxValue(local_88);
  RE::GFxValue::~GFxValue(local_70);
  RE::GFxValue::~GFxValue(local_a0);
  __security_check_cookie(local_28 ^ (ulonglong)auStack_d8);
  return;
}


/* ---- 0x18003d870  FUN_18003d870  (23 bytes) ---- */

undefined8 * FUN_18003d870(undefined8 *param_1,undefined8 *param_2)

{
  RE::GFxValue::operator=(param_1,param_2);
  return param_1;
}


/* ---- 0x18003d890  FUN_18003d890  (23 bytes) ---- */

undefined8 * FUN_18003d890(undefined8 *param_1,undefined8 *param_2)

{
  RE::GFxValue::operator=(param_1,param_2);
  return param_1;
}


/* ---- 0x18003d8b0  FUN_18003d8b0  (23 bytes) ---- */

undefined8 * FUN_18003d8b0(undefined8 *param_1,undefined8 *param_2)

{
  RE::GFxValue::GFxValue(param_1,param_2);
  return param_1;
}


/* ---- 0x18003d8d0  FUN_18003d8d0  (23 bytes) ---- */

undefined8 * FUN_18003d8d0(undefined8 *param_1,undefined8 *param_2)

{
  RE::GFxValue::GFxValue(param_1,param_2);
  return param_1;
}


/* ---- 0x18003da80  FUN_18003da80  (227 bytes) ---- */

void FUN_18003da80(undefined8 *param_1)

{
  float fVar1;
  longlong *plVar2;
  float fVar3;
  float fVar4;
  undefined1 auStack_148 [32];
  DisplayInfo local_128;
  ulonglong local_38;
  
  fVar4 = DAT_1801cf5ec;
  fVar1 = DAT_1801cf5e8;
  local_38 = __security_cookie ^ (ulonglong)auStack_148;
  FUN_180044430(&local_128._x);
  FUN_180046180(param_1,&local_128);
  plVar2 = (longlong *)(**(code **)(**(longlong **)*param_1 + 8))();
  fVar3 = (float)(**(code **)(*plVar2 + 0x30))(plVar2);
  RE::GFxValue::DisplayInfo::SetX(&local_128,(double)(fVar3 * fVar4 - *(float *)(param_1 + 3)));
  fVar4 = (float)(**(code **)(*plVar2 + 0x38))(plVar2);
  RE::GFxValue::DisplayInfo::SetY
            (&local_128,(double)(fVar4 * fVar1 - *(float *)((longlong)param_1 + 0x1c)));
  FUN_180046190(param_1,&local_128);
  __security_check_cookie(local_38 ^ (ulonglong)auStack_148);
  return;
}


/* ---- 0x18003de30  FUN_18003de30  (408 bytes) ---- */

void FUN_18003de30(undefined8 *param_1)

{
  undefined *puVar1;
  undefined8 local_28 [4];
  
  if (DAT_1801d9558 == (undefined *)0x0) {
    if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
                0x14) < DAT_1801d9738) {
      _Init_thread_header(&DAT_1801d9738);
      if (DAT_1801d9738 == -1) {
        RE::GFxValue::GFxValue(&DAT_1801d9740,param_1);
        FUN_180045700(local_28);
        FUN_180045f80((undefined8 *)&DAT_1801d9740,"TextField0",local_28);
        puVar1 = &DAT_1801d9758;
        FUN_180045700((undefined8 *)&DAT_1801d9758);
        RE::GFxValue::operator=(puVar1,local_28);
        RE::GFxValue::~GFxValue(local_28);
        FUN_180045700(local_28);
        FUN_180045f80((undefined8 *)&DAT_1801d9740,"TextField1",local_28);
        puVar1 = &DAT_1801d9770;
        FUN_180045700((undefined8 *)&DAT_1801d9770);
        RE::GFxValue::operator=(puVar1,local_28);
        RE::GFxValue::~GFxValue(local_28);
        FUN_180045700(local_28);
        FUN_180045f80((undefined8 *)&DAT_1801d9740,"TextField2",local_28);
        puVar1 = &DAT_1801d9788;
        FUN_180045700((undefined8 *)&DAT_1801d9788);
        RE::GFxValue::operator=(puVar1,local_28);
        RE::GFxValue::~GFxValue(local_28);
        atexit(`Test::InitSingleton'::__l5::_dynamic_atexit_destructor_for__singletonInstance__);
        _Init_thread_footer(&DAT_1801d9738);
        DAT_1801d9558 = &DAT_1801d9740;
        return;
      }
    }
    DAT_1801d9558 = &DAT_1801d9740;
  }
  return;
}


/* ---- 0x18003dfd0  FUN_18003dfd0  (299 bytes) ---- */

undefined * FUN_18003dfd0(undefined8 param_1,undefined8 *param_2)

{
  undefined *puVar1;
  undefined8 local_28 [4];
  
  RE::GFxValue::GFxValue(&DAT_1801d9740,param_2);
  FUN_180045700(local_28);
  FUN_180045f80((undefined8 *)&DAT_1801d9740,"TextField0",local_28);
  puVar1 = &DAT_1801d9758;
  FUN_180045700((undefined8 *)&DAT_1801d9758);
  RE::GFxValue::operator=(puVar1,local_28);
  RE::GFxValue::~GFxValue(local_28);
  FUN_180045700(local_28);
  FUN_180045f80((undefined8 *)&DAT_1801d9740,"TextField1",local_28);
  puVar1 = &DAT_1801d9770;
  FUN_180045700((undefined8 *)&DAT_1801d9770);
  RE::GFxValue::operator=(puVar1,local_28);
  RE::GFxValue::~GFxValue(local_28);
  FUN_180045700(local_28);
  FUN_180045f80((undefined8 *)&DAT_1801d9740,"TextField2",local_28);
  puVar1 = &DAT_1801d9788;
  FUN_180045700((undefined8 *)&DAT_1801d9788);
  RE::GFxValue::operator=(puVar1,local_28);
  RE::GFxValue::~GFxValue(local_28);
  return &DAT_1801d9740;
}


/* ---- 0x18003e100  ~Test  (49 bytes)   [名称未经人工确认] ---- */

void __thiscall Test::~Test(Test *this)

{
  RE::GFxValue::~GFxValue(this + 0x48);
  RE::GFxValue::~GFxValue(this + 0x30);
  RE::GFxValue::~GFxValue(this + 0x18);
  RE::GFxValue::~GFxValue(this);
  return;
}


/* ---- 0x18003e200  FUN_18003e200  (95 bytes) ---- */

void FUN_18003e200(void)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 local_18;
  longlong *local_10;
  
  puVar5 = spdlog::default_logger(&local_18);
  FUN_1800fac20((longlong *)*puVar5);
  if (local_10 != (longlong *)0x0) {
    LOCK();
    plVar1 = local_10 + 1;
    lVar4 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar4 == 1) {
      (**(code **)*local_10)(local_10);
      LOCK();
      piVar2 = (int *)((longlong)local_10 + 0xc);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(*local_10 + 8))(local_10);
      }
    }
  }
  return;
}


/* ---- 0x18003e260  FUN_18003e260  (101 bytes) ---- */

char * FUN_18003e260(undefined4 param_1)

{
  switch(param_1) {
  case 1:
    return "Null";
  case 2:
    return "Boolean";
  case 3:
    return "Number";
  case 4:
    return "String";
  case 5:
    return "StringW";
  case 6:
    return "Object";
  case 7:
    return "Array";
  case 8:
    return "DisplayObject";
  default:
    return "Undefined";
  }
}


/* ---- 0x18003f370  FUN_18003f370  (14 bytes) ---- */

undefined8 * FUN_18003f370(undefined8 *param_1)

{
  *param_1 = GFxMemberLogger<1>::vftable;
  return param_1;
}


/* ---- 0x18003f380  FUN_18003f380  (14 bytes) ---- */

undefined8 * FUN_18003f380(undefined8 *param_1)

{
  *param_1 = RE::GFxValue::ObjectInterface::ObjVisitor::vftable;
  return param_1;
}


/* ---- 0x18003f3a0  FUN_18003f3a0  (52 bytes) ---- */

undefined8 * FUN_18003f3a0(undefined8 *param_1,uint param_2)

{
  FUN_180044cd0(param_1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* ---- 0x18003f3e0  FUN_18003f3e0  (52 bytes) ---- */

undefined8 * FUN_18003f3e0(undefined8 *param_1,uint param_2)

{
  FUN_180044cd0(param_1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* ---- 0x18003f820  FUN_18003f820  (139 bytes) ---- */

void FUN_18003f820(undefined8 *param_1,longlong *param_2)

{
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined8 *local_38;
  undefined8 local_30 [3];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = param_1;
  FUN_180045700(param_1);
  __builtin_array_init_helper_eh<RE::GFxValue>(local_30);
  local_48 = 0;
  (**(code **)(*param_2 + 0x68))(param_2,param_1,0,0);
  _eh_vector_destructor_iterator_(local_30,0x18,1,RE::GFxValue::~GFxValue);
  __security_check_cookie(local_18 ^ (ulonglong)auStack_68);
  return;
}


/* ---- 0x18003f8b0  FUN_18003f8b0  (192 bytes) ---- */

void FUN_18003f8b0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  char cVar1;
  undefined1 auStack_78 [32];
  undefined8 uStack_58;
  undefined4 uStack_48;
  undefined8 *puStack_40;
  undefined1 auStack_38 [24];
  ulonglong uStack_20;
  
  uStack_20 = __security_cookie ^ (ulonglong)auStack_78;
  uStack_48 = 0;
  puStack_40 = param_2;
  FUN_180045700(param_2);
  uStack_48 = 1;
  RE::GFxValue::GFxValue(auStack_38,param_4);
  uStack_58 = 1;
  cVar1 = RE::GFxValue::Invoke(param_1,*param_3,param_2);
  if (cVar1 == '\0') {
    _eh_vector_destructor_iterator_(auStack_38,0x18,1,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(auStack_38,0x18,1,RE::GFxValue::~GFxValue);
  }
  __security_check_cookie(uStack_20 ^ (ulonglong)auStack_78);
  return;
}


/* ---- 0x18003fb10  FUN_18003fb10  (4 bytes) ---- */

undefined8 FUN_18003fb10(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18003fb20  FUN_18003fb20  (53 bytes) ---- */

longlong * FUN_18003fb20(longlong *param_1,undefined8 *param_2)

{
  ulonglong local_28 [3];
  undefined8 uStack_10;
  
  local_28[2] = *param_2;
  uStack_10 = param_2[1];
  local_28[0] = 0;
  local_28[1] = 0;
  FUN_180038710(param_1,(longlong *)(local_28 + 2),local_28);
  return param_1;
}


/* ---- 0x18003fb70  FUN_18003fb70  (5 bytes) ---- */

undefined8 FUN_18003fb70(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x10);
}


/* ---- 0x18003fb80  FUN_18003fb80  (20 bytes) ---- */

undefined8 FUN_18003fb80(longlong param_1)

{
  if ((*(int *)(param_1 + 8) == 1) && (*(int *)(param_1 + 0xc) == 0x18)) {
    return *(undefined8 *)(param_1 + 0x10);
  }
  return 0;
}


/* ---- 0x18003fba0  FUN_18003fba0  (20 bytes) ---- */

undefined8 FUN_18003fba0(longlong param_1)

{
  if ((*(int *)(param_1 + 8) == 2) && (*(int *)(param_1 + 0xc) == 0x28)) {
    return *(undefined8 *)(param_1 + 0x10);
  }
  return 0;
}


/* ---- 0x18003fbc0  FUN_18003fbc0  (20 bytes) ---- */

undefined8 FUN_18003fbc0(longlong param_1)

{
  if ((*(int *)(param_1 + 8) == 3) && (*(int *)(param_1 + 0xc) == 0x18)) {
    return *(undefined8 *)(param_1 + 0x10);
  }
  return 0;
}


/* ---- 0x18003fbe0  FUN_18003fbe0  (20 bytes) ---- */

undefined8 FUN_18003fbe0(longlong param_1)

{
  if ((*(int *)(param_1 + 8) == 4) && (*(int *)(param_1 + 0xc) == 0x18)) {
    return *(undefined8 *)(param_1 + 0x10);
  }
  return 0;
}


/* ---- 0x18003fc00  FUN_18003fc00  (20 bytes) ---- */

undefined8 FUN_18003fc00(longlong param_1)

{
  if ((*(int *)(param_1 + 8) == 5) && (*(int *)(param_1 + 0xc) == 0x10)) {
    return *(undefined8 *)(param_1 + 0x10);
  }
  return 0;
}


/* ---- 0x18003fc20  FUN_18003fc20  (5 bytes) ---- */

undefined8 FUN_18003fc20(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x10);
}


/* ---- 0x18003fc30  FUN_18003fc30  (20 bytes) ---- */

undefined8 FUN_18003fc30(longlong param_1)

{
  if ((*(int *)(param_1 + 8) == 0) && (*(int *)(param_1 + 0xc) == 8)) {
    return *(undefined8 *)(param_1 + 0x10);
  }
  return 0;
}


/* ---- 0x18003fc50  FUN_18003fc50  (20 bytes) ---- */

undefined8 FUN_18003fc50(longlong param_1)

{
  if ((*(int *)(param_1 + 8) == 1) && (*(int *)(param_1 + 0xc) == 8)) {
    return *(undefined8 *)(param_1 + 0x10);
  }
  return 0;
}


/* ---- 0x18003fc70  FUN_18003fc70  (20 bytes) ---- */

undefined8 FUN_18003fc70(longlong param_1)

{
  if ((*(int *)(param_1 + 8) == 2) && (*(int *)(param_1 + 0xc) == 8)) {
    return *(undefined8 *)(param_1 + 0x10);
  }
  return 0;
}


/* ---- 0x18003fc90  FUN_18003fc90  (163 bytes) ---- */

undefined8
FUN_18003fc90(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined4 *param_4)

{
  logger *plVar1;
  ulonglong local_58;
  ulonglong uStack_50;
  ulonglong local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  ulonglong local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  plVar1 = spdlog::default_logger_raw();
  local_48 = *(ulonglong *)(param_4 + 2);
  local_58 = *param_2;
  uStack_50 = param_2[1];
  local_38 = *(undefined8 *)(param_4 + 4);
  uStack_40 = *param_4;
  uStack_3c = uStack_20._4_4_;
  uStack_20 = CONCAT44(uStack_20._4_4_,uStack_40);
  local_28 = local_48;
  local_18 = local_38;
  FUN_180041aa0(&plVar1->_padding_,&local_28,1,&local_58,param_3);
  return param_1;
}


/* ---- 0x18003fe70  FUN_18003fe70  (187 bytes) ---- */

undefined8
FUN_18003fe70(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined4 *param_4,
             undefined4 *param_5,undefined4 *param_6)

{
  logger *plVar1;
  undefined8 *puVar2;
  ulonglong local_58;
  ulonglong uStack_50;
  ulonglong local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  ulonglong local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  puVar2 = param_3;
  plVar1 = spdlog::default_logger_raw();
  local_58 = *param_2;
  uStack_50 = param_2[1];
  local_48 = *(ulonglong *)(param_6 + 2);
  uStack_40 = *param_6;
  local_38 = *(undefined8 *)(param_6 + 4);
  uStack_3c = uStack_20._4_4_;
  uStack_20 = CONCAT44(uStack_20._4_4_,uStack_40);
  local_28 = local_48;
  local_18 = local_38;
  FUN_180042140(&plVar1->_padding_,&local_28,puVar2,&local_58,param_3,param_4,param_5);
  return param_1;
}


/* ---- 0x18003ffc0  FUN_18003ffc0  (189 bytes) ---- */

void FUN_18003ffc0(undefined8 param_1,longlong *param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong *local_res10 [2];
  char *local_res20;
  char *local_18;
  undefined8 local_10;
  
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (*(char *)((longlong)param_2 + lVar4) != '\0');
  local_res10[0] = param_2;
  if (lVar4 == 0xb) {
    lVar4 = *param_2 + -0x6576655279616c50;
    if ((lVar4 == 0) && (lVar4 = (ulonglong)*(ushort *)(param_2 + 1) - 0x7372, lVar4 == 0)) {
      lVar4 = (ulonglong)*(byte *)((longlong)param_2 + 10) - 0x65;
    }
    if (lVar4 == 0) {
      return;
    }
    iVar1 = memcmp(param_2,"PlayForward",0xb);
    if (iVar1 == 0) {
      return;
    }
  }
  uVar2 = RE::GFxValue::GetType((void *)param_3);
  uVar3 = (ulonglong)uVar2;
  local_res20 = FUN_18003e260(uVar2);
  local_10 = 0xb;
  local_18 = "\tvar {}: {}";
  FUN_180040700(uVar3,(ulonglong *)&local_18,local_res10,&local_res20);
  return;
}


/* ---- 0x180040080  FUN_180040080  (302 bytes) ---- */

void FUN_180040080(undefined8 param_1,undefined8 *param_2)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong *puVar6;
  longlong lVar7;
  undefined8 *puVar8;
  char *local_res18;
  undefined1 *local_res20;
  GString local_28 [2];
  char *local_18;
  longlong *local_10;
  
  uVar5 = RE::GFxValue::GetType(param_2);
  local_res18 = FUN_18003e260(uVar5);
  puVar6 = FUN_180045b20(param_2,(ulonglong *)local_28);
  local_res20 = FUN_1800a3e10(puVar6);
  local_18 = "{}: {}";
  local_10 = (longlong *)0x6;
  FUN_1800407b0(puVar6,(ulonglong *)&local_18,&local_res20,&local_res18);
  RE::GString::~GString(local_28);
  puVar8 = param_2;
  lVar7 = RE::GFxValue::IsObject(param_2);
  if ((char)lVar7 != '\0') {
    local_18 = "{}";
    local_10 = (longlong *)0x2;
    FUN_180040850(puVar8,(ulonglong *)&local_18,&DAT_180190b0c);
    FUN_180046030(param_2,param_1);
    local_18 = "{}";
    local_10 = (longlong *)0x2;
    FUN_180040850(param_2,(ulonglong *)&local_18,&DAT_180190b10);
  }
  puVar8 = spdlog::default_logger(&local_18);
  FUN_1800fac20((longlong *)*puVar8);
  plVar4 = local_10;
  if (local_10 != (longlong *)0x0) {
    LOCK();
    plVar1 = local_10 + 1;
    lVar7 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar7 == 1) {
      (**(code **)*local_10)(local_10);
      LOCK();
      piVar2 = (int *)((longlong)plVar4 + 0xc);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(*plVar4 + 8))(plVar4);
      }
    }
  }
  return;
}


/* ---- 0x1800401b0  FUN_1800401b0  (141 bytes) ---- */

undefined8 FUN_1800401b0(undefined8 param_1,ulonglong *param_2,undefined4 *param_3)

{
  logger *this;
  ulonglong uStack_58;
  ulonglong uStack_50;
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 uStack_38;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  this = spdlog::default_logger_raw();
  uStack_48 = *(undefined8 *)(param_3 + 2);
  uStack_38 = *(undefined8 *)(param_3 + 4);
  uStack_58 = *param_2;
  uStack_50 = param_2[1];
  uStack_40 = *param_3;
  uStack_3c = uStack_20._4_4_;
  uStack_20 = CONCAT44(uStack_20._4_4_,uStack_40);
  uStack_28 = uStack_48;
  uStack_18 = uStack_38;
  spdlog::logger::hooks__compat__MapMarkerFramework__Install((logger *)this,&uStack_28,2,&uStack_58)
  ;
  return param_1;
}


/* ---- 0x180040240  FUN_180040240  (14 bytes) ---- */

longlong * FUN_180040240(longlong *param_1)

{
  *param_1 = *(longlong *)(*param_1 + 8);
  return param_1;
}


/* ---- 0x180040250  FUN_180040250  (10 bytes) ---- */

undefined8 FUN_180040250(longlong *param_1,longlong *param_2)

{
  return CONCAT71((int7)((ulonglong)*param_2 >> 8),*param_1 != *param_2);
}


/* ---- 0x180040260  FUN_180040260  (4 bytes) ---- */

undefined8 FUN_180040260(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180040270  FUN_180040270  (8 bytes) ---- */

void FUN_180040270(undefined8 *param_1)

{
  *param_1 = 0;
  return;
}


/* ---- 0x180040280  FUN_180040280  (11 bytes) ---- */

undefined8 * FUN_180040280(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = 0;
  return param_2;
}


/* ---- 0x180040290  FUN_180040290  (27 bytes) ---- */

undefined8 * FUN_180040290(longlong *param_1,undefined8 *param_2)

{
  if ((param_1[1] == 0) && (*param_1 == 0)) {
    *param_2 = 0;
    return param_2;
  }
  *param_2 = param_1;
  return param_2;
}


/* ---- 0x1800402b0  FUN_1800402b0  (75 bytes) ---- */

void FUN_1800402b0(longlong param_1)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  
  plVar4 = *(longlong **)(param_1 + 8);
  if (plVar4 != (longlong *)0x0) {
    LOCK();
    plVar1 = plVar4 + 1;
    lVar5 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar5 == 1) {
      (**(code **)*plVar4)(plVar4);
      LOCK();
      piVar2 = (int *)((longlong)plVar4 + 0xc);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(*plVar4 + 8))(plVar4);
      }
    }
  }
  return;
}


/* ---- 0x180040300  FUN_180040300  (84 bytes) ---- */

longlong FUN_180040300(undefined8 *param_1)

{
  ulonglong uVar1;
  undefined1 (*pauVar2) [32];
  undefined1 (*pauVar3) [32];
  
  uVar1 = param_1[1];
  pauVar2 = (undefined1 (*) [32])*param_1;
  if (6 < uVar1) {
    pauVar3 = (undefined1 (*) [32])
              `anonymous_namespace'::
              __std_search_impl<_anonymous_namespace_::_Find_traits_1,unsigned_char>
                        (pauVar2,(undefined1 (*) [32])(*pauVar2 + uVar1),
                         (undefined1 (*) [16])"HUDMenu",7);
    if (pauVar3 != (undefined1 (*) [32])(*pauVar2 + uVar1)) {
      return (longlong)pauVar3 - (longlong)pauVar2;
    }
  }
  return -1;
}


/* ---- 0x1800403c0  FUN_1800403c0  (130 bytes) ---- */

void FUN_1800403c0(undefined8 *param_1,undefined8 *param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined1 auStack_68 [32];
  undefined8 uStack_48;
  undefined1 auStack_38 [24];
  ulonglong uStack_20;
  
  uStack_20 = __security_cookie ^ (ulonglong)auStack_68;
  RE::GFxValue::GFxValue(auStack_38,param_4);
  uStack_48 = 1;
  RE::GFxValue::Invoke(param_1,*param_2,param_3);
  _eh_vector_destructor_iterator_(auStack_38,0x18,1,RE::GFxValue::~GFxValue);
  __security_check_cookie(uStack_20 ^ (ulonglong)auStack_68);
  return;
}


/* ---- 0x1800404d0  FUN_1800404d0  (122 bytes) ---- */

void FUN_1800404d0(undefined8 *param_1,undefined8 *param_2,undefined8 param_3,float *param_4)

{
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  RE::GFxValue::GFxValue(local_28,(double)*param_4);
  local_38 = 1;
  RE::GFxValue::Invoke(param_1,*param_2,param_3);
  _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  __security_check_cookie(local_10 ^ (ulonglong)auStack_58);
  return;
}


/* ---- 0x180040550  FUN_180040550  (113 bytes) ---- */

void FUN_180040550(ulonglong *param_1,int param_2,ulonglong *param_3,undefined8 *param_4)

{
  logger *plVar1;
  ulonglong local_38;
  ulonglong uStack_30;
  ulonglong local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  plVar1 = spdlog::default_logger_raw();
  local_38 = *param_3;
  uStack_30 = param_3[1];
  local_28 = *param_1;
  uStack_20 = param_1[1];
  local_18 = param_1[2];
  FUN_180041aa0(&plVar1->_padding_,&local_28,param_2,&local_38,param_4);
  return;
}


/* ---- 0x180040630  FUN_180040630  (78 bytes) ---- */

void FUN_180040630(ulonglong *param_1,undefined8 param_2,ulonglong *param_3)

{
  logger *plVar1;
  ulonglong *puVar2;
  ulonglong uStack_38;
  ulonglong uStack_30;
  ulonglong uStack_28;
  ulonglong uStack_20;
  ulonglong uStack_18;
  
  puVar2 = param_3;
  plVar1 = spdlog::default_logger_raw();
  uStack_38 = *param_3;
  uStack_30 = param_3[1];
  uStack_28 = *param_1;
  uStack_20 = param_1[1];
  uStack_18 = param_1[2];
  spdlog::logger::log_<std::basic_string_view<char,std::char_traits<char>_>_const_&>
            (&plVar1->_padding_,&uStack_28,puVar2,&uStack_38);
  return;
}


/* ---- 0x180040680  FUN_180040680  (124 bytes) ---- */

void FUN_180040680(ulonglong *param_1,undefined8 param_2,ulonglong *param_3,undefined8 *param_4,
                  undefined4 *param_5,undefined4 *param_6)

{
  logger *plVar1;
  ulonglong *puVar2;
  ulonglong uStack_38;
  ulonglong uStack_30;
  ulonglong uStack_28;
  ulonglong uStack_20;
  ulonglong uStack_18;
  
  puVar2 = param_3;
  plVar1 = spdlog::default_logger_raw();
  uStack_38 = *param_3;
  uStack_30 = param_3[1];
  uStack_28 = *param_1;
  uStack_20 = param_1[1];
  uStack_18 = param_1[2];
  FUN_180042140(&plVar1->_padding_,&uStack_28,puVar2,&uStack_38,param_4,param_5,param_6);
  return;
}


/* ---- 0x180040700  FUN_180040700  (162 bytes) ---- */

void FUN_180040700(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong local_68;
  ulonglong uStack_60;
  char *local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  char *local_48;
  char *local_38;
  undefined8 uStack_30;
  char *local_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  uStack_50 = 0x30;
  local_58 = 
  "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\include\\utils/Logger.h"
  ;
  uStack_4c = uStack_30._4_4_;
  uStack_30 = CONCAT44(uStack_30._4_4_,0x30);
  local_48 = 
  "void __cdecl SKSE::log::at_level<const char*&,const char*>(enum spdlog::level::level_enum,class fmt::v10::basic_format_string<char,char const * &,char const *>,const char *&,const char *&&)"
  ;
  local_28 = 
  "void __cdecl SKSE::log::at_level<const char*&,const char*>(enum spdlog::level::level_enum,class fmt::v10::basic_format_string<char,char const * &,char const *>,const char *&,const char *&&)"
  ;
  local_38 = 
  "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\include\\utils/Logger.h"
  ;
  local_68 = uVar1;
  uStack_60 = uVar2;
  FUN_180042da0(&plVar3->_padding_,(ulonglong *)&local_38,1,&local_68,param_3,param_4);
  return;
}


/* ---- 0x1800407b0  FUN_1800407b0  (158 bytes) ---- */

void FUN_1800407b0(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined8 *param_4)

{
  logger *plVar1;
  ulonglong local_58;
  ulonglong uStack_50;
  char *local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char *local_38;
  char *local_28;
  undefined8 uStack_20;
  char *local_18;
  
  plVar1 = spdlog::default_logger_raw();
  local_58 = *param_2;
  uStack_50 = param_2[1];
  local_48 = 
  "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\include\\utils/Logger.h"
  ;
  uStack_3c = uStack_20._4_4_;
  local_38 = 
  "void __cdecl SKSE::log::at_level<const char*,const char*>(enum spdlog::level::level_enum,class fmt::v10::basic_format_string<char,char const *,char const *>,const char *&&,const char *&&)"
  ;
  uStack_40 = 0x30;
  uStack_20 = CONCAT44(uStack_20._4_4_,0x30);
  local_18 = 
  "void __cdecl SKSE::log::at_level<const char*,const char*>(enum spdlog::level::level_enum,class fmt::v10::basic_format_string<char,char const *,char const *>,const char *&&,const char *&&)"
  ;
  local_28 = 
  "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\include\\utils/Logger.h"
  ;
  FUN_180042b50(&plVar1->_padding_,(ulonglong *)&local_28,1,&local_58,param_3,param_4);
  return;
}


/* ---- 0x180040850  FUN_180040850  (141 bytes) ---- */

void FUN_180040850(undefined8 param_1,ulonglong *param_2,undefined8 param_3)

{
  logger *plVar1;
  ulonglong local_58;
  ulonglong uStack_50;
  char *local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char *local_38;
  char *local_28;
  undefined8 uStack_20;
  char *local_18;
  
  plVar1 = spdlog::default_logger_raw();
  local_58 = *param_2;
  uStack_50 = param_2[1];
  local_48 = 
  "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\include\\utils/Logger.h"
  ;
  uStack_3c = uStack_20._4_4_;
  local_38 = 
  "void __cdecl SKSE::log::at_level<const char(&)[2]>(enum spdlog::level::level_enum,class fmt::v10::basic_format_string<char,char const (&)[2]>,const char (&)[2])"
  ;
  uStack_40 = 0x30;
  uStack_20 = CONCAT44(uStack_20._4_4_,0x30);
  local_18 = 
  "void __cdecl SKSE::log::at_level<const char(&)[2]>(enum spdlog::level::level_enum,class fmt::v10::basic_format_string<char,char const (&)[2]>,const char (&)[2])"
  ;
  local_28 = 
  "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\include\\utils/Logger.h"
  ;
  FUN_180042920(&plVar1->_padding_,(ulonglong *)&local_28,1,&local_58,param_3);
  return;
}


/* ---- 0x180040950  FUN_180040950  (10 bytes) ---- */

undefined8 * FUN_180040950(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_1[1];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  return param_2;
}


/* ---- 0x180040960  FUN_180040960  (10 bytes) ---- */

undefined8 FUN_180040960(longlong *param_1,longlong *param_2)

{
  return CONCAT71((int7)((ulonglong)*param_2 >> 8),*param_1 == *param_2);
}


/* ---- 0x180040970  FUN_180040970  (7 bytes) ---- */

undefined8 * FUN_180040970(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180040980  FUN_180040980  (17 bytes) ---- */

undefined8 * FUN_180040980(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  *param_2 = 0;
  return param_1;
}


/* ---- 0x1800409a0  FUN_1800409a0  (4 bytes) ---- */

undefined8 FUN_1800409a0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800409b0  FUN_1800409b0  (19 bytes) ---- */

undefined1 FUN_1800409b0(longlong *param_1)

{
  if ((param_1[1] == 0) && (*param_1 == 0)) {
    return 1;
  }
  return 0;
}


/* ---- 0x1800409d0  FUN_1800409d0  (75 bytes) ---- */

void FUN_1800409d0(longlong param_1)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  
  plVar4 = *(longlong **)(param_1 + 8);
  if (plVar4 != (longlong *)0x0) {
    LOCK();
    plVar1 = plVar4 + 1;
    lVar5 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar5 == 1) {
      (**(code **)*plVar4)(plVar4);
      LOCK();
      piVar2 = (int *)((longlong)plVar4 + 0xc);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(*plVar4 + 8))(plVar4);
      }
    }
  }
  return;
}


/* ---- 0x180040a20  FUN_180040a20  (4 bytes) ---- */

undefined8 FUN_180040a20(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180040a30  FUN_180040a30  (13 bytes) ---- */

undefined8 * FUN_180040a30(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}


/* ---- 0x180040a80  FUN_180040a80  (4 bytes) ---- */

undefined8 FUN_180040a80(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180040a90  FUN_180040a90  (65 bytes) ---- */

void FUN_180040a90(longlong *param_1,ulonglong *param_2,int param_3,ulonglong *param_4,
                  undefined8 *param_5)

{
  ulonglong local_38;
  ulonglong uStack_30;
  ulonglong local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  local_38 = *param_4;
  uStack_30 = param_4[1];
  local_28 = *param_2;
  uStack_20 = param_2[1];
  local_18 = param_2[2];
  FUN_180041aa0(param_1,&local_28,param_3,&local_38,param_5);
  return;
}


/* ---- 0x180040b70  FUN_180040b70  (92 bytes) ---- */

void FUN_180040b70(longlong *param_1,ulonglong *param_2,undefined8 param_3,ulonglong *param_4,
                  undefined8 *param_5,undefined4 *param_6,undefined4 *param_7)

{
  ulonglong local_38;
  ulonglong uStack_30;
  ulonglong local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  local_38 = *param_4;
  uStack_30 = param_4[1];
  local_28 = *param_2;
  uStack_20 = param_2[1];
  local_18 = param_2[2];
  FUN_180042140(param_1,&local_28,param_3,&local_38,param_5,param_6,param_7);
  return;
}


/* ---- 0x180040bd0  FUN_180040bd0  (4 bytes) ---- */

undefined8 FUN_180040bd0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180040be0  FUN_180040be0  (4 bytes) ---- */

undefined8 FUN_180040be0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180040c00  FUN_180040c00  (4 bytes) ---- */

undefined8 FUN_180040c00(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180040c10  FUN_180040c10  (4 bytes) ---- */

undefined8 FUN_180040c10(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180040c20  FUN_180040c20  (161 bytes) ---- */

undefined8
FUN_180040c20(undefined8 param_1,ulonglong *param_2,undefined8 param_3,undefined4 *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong local_68;
  ulonglong uStack_60;
  ulonglong local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  local_58 = *(ulonglong *)(param_4 + 2);
  uStack_50 = *param_4;
  uStack_4c = uStack_30._4_4_;
  local_48 = *(undefined8 *)(param_4 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  local_68 = uVar1;
  uStack_60 = uVar2;
  local_38 = local_58;
  local_28 = local_48;
  FUN_180042920(&plVar3->_padding_,&local_38,5,&local_68,param_3);
  return param_1;
}


/* ---- 0x180040cd0  FUN_180040cd0  (161 bytes) ---- */

undefined8
FUN_180040cd0(undefined8 param_1,ulonglong *param_2,undefined8 param_3,undefined4 *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong local_68;
  ulonglong uStack_60;
  ulonglong local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  local_58 = *(ulonglong *)(param_4 + 2);
  uStack_50 = *param_4;
  uStack_4c = uStack_30._4_4_;
  local_48 = *(undefined8 *)(param_4 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  local_68 = uVar1;
  uStack_60 = uVar2;
  local_38 = local_58;
  local_28 = local_48;
  FUN_180042920(&plVar3->_padding_,&local_38,4,&local_68,param_3);
  return param_1;
}


/* ---- 0x180040d80  FUN_180040d80  (161 bytes) ---- */

undefined8
FUN_180040d80(undefined8 param_1,ulonglong *param_2,undefined8 param_3,undefined4 *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong local_68;
  ulonglong uStack_60;
  ulonglong local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  local_58 = *(ulonglong *)(param_4 + 2);
  uStack_50 = *param_4;
  uStack_4c = uStack_30._4_4_;
  local_48 = *(undefined8 *)(param_4 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  local_68 = uVar1;
  uStack_60 = uVar2;
  local_38 = local_58;
  local_28 = local_48;
  FUN_180042920(&plVar3->_padding_,&local_38,3,&local_68,param_3);
  return param_1;
}


/* ---- 0x180040e30  FUN_180040e30  (161 bytes) ---- */

undefined8
FUN_180040e30(undefined8 param_1,ulonglong *param_2,undefined8 param_3,undefined4 *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong local_68;
  ulonglong uStack_60;
  ulonglong local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  local_58 = *(ulonglong *)(param_4 + 2);
  uStack_50 = *param_4;
  uStack_4c = uStack_30._4_4_;
  local_48 = *(undefined8 *)(param_4 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  local_68 = uVar1;
  uStack_60 = uVar2;
  local_38 = local_58;
  local_28 = local_48;
  FUN_180042920(&plVar3->_padding_,&local_38,2,&local_68,param_3);
  return param_1;
}


/* ---- 0x180040ee0  FUN_180040ee0  (161 bytes) ---- */

undefined8
FUN_180040ee0(undefined8 param_1,ulonglong *param_2,undefined8 param_3,undefined4 *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong local_68;
  ulonglong uStack_60;
  ulonglong local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  local_58 = *(ulonglong *)(param_4 + 2);
  uStack_50 = *param_4;
  uStack_4c = uStack_30._4_4_;
  local_48 = *(undefined8 *)(param_4 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  local_68 = uVar1;
  uStack_60 = uVar2;
  local_38 = local_58;
  local_28 = local_48;
  FUN_180042920(&plVar3->_padding_,&local_38,1,&local_68,param_3);
  return param_1;
}


/* ---- 0x180040f90  FUN_180040f90  (158 bytes) ---- */

undefined8
FUN_180040f90(undefined8 param_1,ulonglong *param_2,undefined8 param_3,undefined4 *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong local_68;
  ulonglong uStack_60;
  ulonglong local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  local_58 = *(ulonglong *)(param_4 + 2);
  uStack_50 = *param_4;
  uStack_4c = uStack_30._4_4_;
  local_48 = *(undefined8 *)(param_4 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  local_68 = uVar1;
  uStack_60 = uVar2;
  local_38 = local_58;
  local_28 = local_48;
  FUN_180042920(&plVar3->_padding_,&local_38,0,&local_68,param_3);
  return param_1;
}


/* ---- 0x180041030  FUN_180041030  (175 bytes) ---- */

undefined8
FUN_180041030(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined4 *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong uStack_68;
  ulonglong uStack_60;
  ulonglong uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  ulonglong uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  uStack_58 = *(ulonglong *)(param_5 + 2);
  uStack_50 = *param_5;
  uStack_4c = uStack_30._4_4_;
  uStack_48 = *(undefined8 *)(param_5 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  uStack_68 = uVar1;
  uStack_60 = uVar2;
  uStack_38 = uStack_58;
  uStack_28 = uStack_48;
  FUN_180042b50(&plVar3->_padding_,&uStack_38,5,&uStack_68,param_3,param_4);
  return param_1;
}


/* ---- 0x1800410e0  FUN_1800410e0  (175 bytes) ---- */

undefined8
FUN_1800410e0(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined4 *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong uStack_68;
  ulonglong uStack_60;
  ulonglong uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  ulonglong uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  uStack_58 = *(ulonglong *)(param_5 + 2);
  uStack_50 = *param_5;
  uStack_4c = uStack_30._4_4_;
  uStack_48 = *(undefined8 *)(param_5 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  uStack_68 = uVar1;
  uStack_60 = uVar2;
  uStack_38 = uStack_58;
  uStack_28 = uStack_48;
  FUN_180042b50(&plVar3->_padding_,&uStack_38,4,&uStack_68,param_3,param_4);
  return param_1;
}


/* ---- 0x180041190  FUN_180041190  (175 bytes) ---- */

undefined8
FUN_180041190(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined4 *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong uStack_68;
  ulonglong uStack_60;
  ulonglong uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  ulonglong uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  uStack_58 = *(ulonglong *)(param_5 + 2);
  uStack_50 = *param_5;
  uStack_4c = uStack_30._4_4_;
  uStack_48 = *(undefined8 *)(param_5 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  uStack_68 = uVar1;
  uStack_60 = uVar2;
  uStack_38 = uStack_58;
  uStack_28 = uStack_48;
  FUN_180042b50(&plVar3->_padding_,&uStack_38,3,&uStack_68,param_3,param_4);
  return param_1;
}


/* ---- 0x180041240  FUN_180041240  (175 bytes) ---- */

undefined8
FUN_180041240(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined4 *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong uStack_68;
  ulonglong uStack_60;
  ulonglong uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  ulonglong uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  uStack_58 = *(ulonglong *)(param_5 + 2);
  uStack_50 = *param_5;
  uStack_4c = uStack_30._4_4_;
  uStack_48 = *(undefined8 *)(param_5 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  uStack_68 = uVar1;
  uStack_60 = uVar2;
  uStack_38 = uStack_58;
  uStack_28 = uStack_48;
  FUN_180042b50(&plVar3->_padding_,&uStack_38,2,&uStack_68,param_3,param_4);
  return param_1;
}


/* ---- 0x1800412f0  FUN_1800412f0  (175 bytes) ---- */

undefined8
FUN_1800412f0(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined4 *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong uStack_68;
  ulonglong uStack_60;
  ulonglong uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  ulonglong uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  uStack_58 = *(ulonglong *)(param_5 + 2);
  uStack_50 = *param_5;
  uStack_4c = uStack_30._4_4_;
  uStack_48 = *(undefined8 *)(param_5 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  uStack_68 = uVar1;
  uStack_60 = uVar2;
  uStack_38 = uStack_58;
  uStack_28 = uStack_48;
  FUN_180042b50(&plVar3->_padding_,&uStack_38,1,&uStack_68,param_3,param_4);
  return param_1;
}


/* ---- 0x1800413a0  FUN_1800413a0  (172 bytes) ---- */

undefined8
FUN_1800413a0(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined4 *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong uStack_68;
  ulonglong uStack_60;
  ulonglong uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  ulonglong uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  uStack_58 = *(ulonglong *)(param_5 + 2);
  uStack_50 = *param_5;
  uStack_4c = uStack_30._4_4_;
  uStack_48 = *(undefined8 *)(param_5 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  uStack_68 = uVar1;
  uStack_60 = uVar2;
  uStack_38 = uStack_58;
  uStack_28 = uStack_48;
  FUN_180042b50(&plVar3->_padding_,&uStack_38,0,&uStack_68,param_3,param_4);
  return param_1;
}


/* ---- 0x180041450  FUN_180041450  (175 bytes) ---- */

undefined8
FUN_180041450(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined4 *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong local_68;
  ulonglong uStack_60;
  ulonglong local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  local_58 = *(ulonglong *)(param_5 + 2);
  uStack_50 = *param_5;
  uStack_4c = uStack_30._4_4_;
  local_48 = *(undefined8 *)(param_5 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  local_68 = uVar1;
  uStack_60 = uVar2;
  local_38 = local_58;
  local_28 = local_48;
  FUN_180042da0(&plVar3->_padding_,&local_38,5,&local_68,param_3,param_4);
  return param_1;
}


/* ---- 0x180041500  FUN_180041500  (175 bytes) ---- */

undefined8
FUN_180041500(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined4 *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong uStack_68;
  ulonglong uStack_60;
  ulonglong uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  ulonglong uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  uStack_58 = *(ulonglong *)(param_5 + 2);
  uStack_50 = *param_5;
  uStack_4c = uStack_30._4_4_;
  uStack_48 = *(undefined8 *)(param_5 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  uStack_68 = uVar1;
  uStack_60 = uVar2;
  uStack_38 = uStack_58;
  uStack_28 = uStack_48;
  FUN_180042da0(&plVar3->_padding_,&uStack_38,4,&uStack_68,param_3,param_4);
  return param_1;
}


/* ---- 0x1800415b0  FUN_1800415b0  (175 bytes) ---- */

undefined8
FUN_1800415b0(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined4 *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong uStack_68;
  ulonglong uStack_60;
  ulonglong uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  ulonglong uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  uStack_58 = *(ulonglong *)(param_5 + 2);
  uStack_50 = *param_5;
  uStack_4c = uStack_30._4_4_;
  uStack_48 = *(undefined8 *)(param_5 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  uStack_68 = uVar1;
  uStack_60 = uVar2;
  uStack_38 = uStack_58;
  uStack_28 = uStack_48;
  FUN_180042da0(&plVar3->_padding_,&uStack_38,3,&uStack_68,param_3,param_4);
  return param_1;
}


/* ---- 0x180041660  FUN_180041660  (175 bytes) ---- */

undefined8
FUN_180041660(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined4 *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong uStack_68;
  ulonglong uStack_60;
  ulonglong uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  ulonglong uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  uStack_58 = *(ulonglong *)(param_5 + 2);
  uStack_50 = *param_5;
  uStack_4c = uStack_30._4_4_;
  uStack_48 = *(undefined8 *)(param_5 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  uStack_68 = uVar1;
  uStack_60 = uVar2;
  uStack_38 = uStack_58;
  uStack_28 = uStack_48;
  FUN_180042da0(&plVar3->_padding_,&uStack_38,2,&uStack_68,param_3,param_4);
  return param_1;
}


/* ---- 0x180041710  FUN_180041710  (175 bytes) ---- */

undefined8
FUN_180041710(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined4 *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong uStack_68;
  ulonglong uStack_60;
  ulonglong uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  ulonglong uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  uStack_58 = *(ulonglong *)(param_5 + 2);
  uStack_50 = *param_5;
  uStack_4c = uStack_30._4_4_;
  uStack_48 = *(undefined8 *)(param_5 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  uStack_68 = uVar1;
  uStack_60 = uVar2;
  uStack_38 = uStack_58;
  uStack_28 = uStack_48;
  FUN_180042da0(&plVar3->_padding_,&uStack_38,1,&uStack_68,param_3,param_4);
  return param_1;
}


/* ---- 0x1800417c0  FUN_1800417c0  (172 bytes) ---- */

undefined8
FUN_1800417c0(undefined8 param_1,ulonglong *param_2,undefined8 *param_3,undefined8 *param_4,
             undefined4 *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  logger *plVar3;
  ulonglong uStack_68;
  ulonglong uStack_60;
  ulonglong uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  ulonglong uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  plVar3 = spdlog::default_logger_raw();
  uStack_58 = *(ulonglong *)(param_5 + 2);
  uStack_50 = *param_5;
  uStack_4c = uStack_30._4_4_;
  uStack_48 = *(undefined8 *)(param_5 + 4);
  uStack_30 = CONCAT44(uStack_30._4_4_,uStack_50);
  uStack_68 = uVar1;
  uStack_60 = uVar2;
  uStack_38 = uStack_58;
  uStack_28 = uStack_48;
  FUN_180042da0(&plVar3->_padding_,&uStack_38,0,&uStack_68,param_3,param_4);
  return param_1;
}


/* ---- 0x180041870  FUN_180041870  (15 bytes) ---- */

void FUN_180041870(void *param_1,size_t param_2,char *param_3)

{
                    /* WARNING: Could not recover jumptable at 0x0001801553ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  memchr(param_1,(int)*param_3,param_2);
  return;
}


/* ---- 0x180041880  FUN_180041880  (10 bytes) ---- */

undefined8 * FUN_180041880(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  return param_1;
}


/* ---- 0x180041a90  FUN_180041a90  (10 bytes) ---- */

undefined8 * FUN_180041a90(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  return param_1;
}


/* ---- 0x180041aa0  FUN_180041aa0  (538 bytes) ---- */

void FUN_180041aa0(longlong *param_1,ulonglong *param_2,int param_3,ulonglong *param_4,
                  undefined8 *param_5)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  undefined1 *_Memory;
  undefined1 auStackY_288 [32];
  undefined1 *local_258;
  undefined8 *puStack_250;
  longlong *local_248;
  ulonglong *local_238;
  ulonglong local_218;
  ulonglong uStack_210;
  ulonglong local_208;
  longlong *local_1f8;
  longlong local_1f0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  log_msg local_1c8;
  undefined **local_168;
  undefined1 *local_160;
  undefined8 local_158;
  ulonglong local_150;
  undefined1 local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_288;
  local_248 = param_1;
  local_238 = param_2;
  piVar3 = std::_Atomic_address_as<int,std::_Atomic_padded<int>_>
                     ((_Atomic_padded<int> *)(param_1 + 8));
  iVar1 = *piVar3;
  bVar2 = spdlog::details::backtracer::enabled((backtracer *)(param_1 + 0x11));
  if ((iVar1 <= param_3) || (bVar2)) {
    local_158 = 0;
    local_168 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
    local_160 = local_148;
    local_150 = 0xfa;
    local_1d8 = *param_5;
    uStack_1d0 = puStack_250;
    local_258 = (undefined1 *)0xc;
    puStack_250 = &local_1d8;
    local_218 = *param_4;
    uStack_210 = param_4[1];
    fmt::v10::vformat_to<fmt::v10::appender,0>
              (&local_1f8,&local_168,&local_218,(ulonglong *)&local_258);
    local_1f8 = param_1 + 1;
    if (0xf < (ulonglong)param_1[4]) {
      local_1f8 = (longlong *)param_1[1];
    }
    local_258 = local_160;
    puStack_250 = (undefined8 *)local_158;
    local_1f0 = param_1[3];
    local_218 = *param_2;
    uStack_210 = param_2[1];
    local_208 = param_2[2];
    spdlog::details::log_msg::log_msg
              (&local_1c8,&local_218,(undefined4 *)&local_1f8,param_3,&local_258);
    spdlog::logger::log_it_((logger *)param_1,(undefined8 *)&local_1c8,iVar1 <= param_3,bVar2);
    local_168 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
    if (local_160 != local_148) {
      _Memory = local_160;
      if ((0xfff < local_150) &&
         (_Memory = *(undefined1 **)(local_160 + -8),
         (undefined1 *)0x1f < local_160 + (-8 - (longlong)_Memory))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      free(_Memory);
    }
  }
  __security_check_cookie(local_48 ^ (ulonglong)auStackY_288);
  return;
}


/* ---- 0x180041cc0  FUN_180041cc0  (10 bytes) ---- */

undefined8 * FUN_180041cc0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  return param_1;
}


/* ---- 0x180041cd0  FUN_180041cd0  (543 bytes) ---- */

void FUN_180041cd0(longlong *param_1,ulonglong *param_2,undefined8 param_3,ulonglong *param_4,
                  undefined4 *param_5)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  undefined1 *_Memory;
  undefined1 auStackY_278 [32];
  undefined1 *local_248;
  undefined1 **ppuStack_240;
  longlong *local_238;
  ulonglong *local_228;
  ulonglong local_208;
  ulonglong uStack_200;
  ulonglong local_1f8;
  longlong *local_1e8;
  longlong local_1e0;
  undefined1 *local_1c8;
  undefined8 uStack_1c0;
  log_msg local_1b8;
  undefined **local_158;
  undefined1 *local_150;
  undefined8 local_148;
  ulonglong local_140;
  undefined1 local_138 [256];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_278;
  local_238 = param_1;
  local_228 = param_2;
  piVar3 = std::_Atomic_address_as<int,std::_Atomic_padded<int>_>
                     ((_Atomic_padded<int> *)(param_1 + 8));
  iVar1 = *piVar3;
  bVar2 = spdlog::details::backtracer::enabled((backtracer *)(param_1 + 0x11));
  if ((iVar1 < 2) || (bVar2)) {
    local_148 = 0;
    local_158 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
    local_150 = local_138;
    local_140 = 0xfa;
    local_248 = (undefined1 *)CONCAT44(local_248._4_4_,*param_5);
    local_1c8 = local_248;
    uStack_1c0 = ppuStack_240;
    local_248 = (undefined1 *)0x1;
    ppuStack_240 = &local_1c8;
    local_208 = *param_4;
    uStack_200 = param_4[1];
    fmt::v10::vformat_to<fmt::v10::appender,0>
              (&local_1e8,&local_158,&local_208,(ulonglong *)&local_248);
    local_1e8 = param_1 + 1;
    if (0xf < (ulonglong)param_1[4]) {
      local_1e8 = (longlong *)param_1[1];
    }
    local_248 = local_150;
    ppuStack_240 = (undefined1 **)local_148;
    local_1e0 = param_1[3];
    local_208 = *param_2;
    uStack_200 = param_2[1];
    local_1f8 = param_2[2];
    spdlog::details::log_msg::log_msg
              (&local_1b8,&local_208,(undefined4 *)&local_1e8,debug,&local_248);
    spdlog::logger::log_it_((logger *)param_1,(undefined8 *)&local_1b8,iVar1 < 2,bVar2);
    local_158 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
    if (local_150 != local_138) {
      _Memory = local_150;
      if ((0xfff < local_140) &&
         (_Memory = *(undefined1 **)(local_150 + -8),
         (undefined1 *)0x1f < local_150 + (-8 - (longlong)_Memory))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      free(_Memory);
    }
  }
  __security_check_cookie(local_38 ^ (ulonglong)auStackY_278);
  return;
}


/* ---- 0x180041ef0  FUN_180041ef0  (10 bytes) ---- */

undefined8 * FUN_180041ef0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  return param_1;
}


/* ---- 0x180042130  FUN_180042130  (10 bytes) ---- */

undefined8 * FUN_180042130(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  return param_1;
}


/* ---- 0x180042140  FUN_180042140  (621 bytes) ---- */

void FUN_180042140(longlong *param_1,ulonglong *param_2,undefined8 param_3,ulonglong *param_4,
                  undefined8 *param_5,undefined4 *param_6,undefined4 *param_7)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  undefined1 *_Memory;
  undefined1 auStackY_298 [32];
  undefined8 local_268;
  undefined8 uStack_260;
  longlong *local_258;
  ulonglong *local_248;
  log_msg local_228;
  ulonglong local_1c8;
  ulonglong uStack_1c0;
  ulonglong local_1b8;
  undefined8 local_1a8;
  ulonglong *local_1a0;
  undefined4 local_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 local_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  longlong *local_178;
  longlong local_170;
  undefined **local_158;
  undefined1 *local_150;
  undefined8 local_148;
  ulonglong local_140;
  undefined1 local_138 [256];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_298;
  local_258 = param_1;
  local_248 = param_2;
  piVar3 = std::_Atomic_address_as<int,std::_Atomic_padded<int>_>
                     ((_Atomic_padded<int> *)(param_1 + 8));
  iVar1 = *piVar3;
  bVar2 = spdlog::details::backtracer::enabled((backtracer *)(param_1 + 0x11));
  if ((iVar1 < 2) || (bVar2)) {
    local_148 = 0;
    local_158 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
    local_150 = local_138;
    local_140 = 0xfa;
    local_198 = *param_6;
    local_188 = *param_7;
    local_1a8 = *param_5;
    local_1a0 = local_248;
    uStack_194 = local_268._4_4_;
    uStack_190 = (undefined4)uStack_260;
    uStack_18c = uStack_260._4_4_;
    uStack_184 = local_268._4_4_;
    uStack_180 = (undefined4)uStack_260;
    uStack_17c = uStack_260._4_4_;
    local_268 = (undefined1 *)0x99c;
    uStack_260 = &local_1a8;
    local_1c8 = *param_4;
    uStack_1c0 = param_4[1];
    fmt::v10::vformat_to<fmt::v10::appender,0>(&local_178,&local_158,&local_1c8,&local_268);
    local_178 = param_1 + 1;
    if (0xf < (ulonglong)param_1[4]) {
      local_178 = (longlong *)param_1[1];
    }
    local_268 = local_150;
    uStack_260 = (undefined8 *)local_148;
    local_170 = param_1[3];
    local_1c8 = *param_2;
    uStack_1c0 = param_2[1];
    local_1b8 = param_2[2];
    spdlog::details::log_msg::log_msg
              (&local_228,&local_1c8,(undefined4 *)&local_178,debug,&local_268);
    spdlog::logger::log_it_((logger *)param_1,(undefined8 *)&local_228,iVar1 < 2,bVar2);
    local_158 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
    if (local_150 != local_138) {
      _Memory = local_150;
      if ((0xfff < local_140) &&
         (_Memory = *(undefined1 **)(local_150 + -8),
         (undefined1 *)0x1f < local_150 + (-8 - (longlong)_Memory))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      free(_Memory);
    }
  }
  __security_check_cookie(local_38 ^ (ulonglong)auStackY_298);
  return;
}


/* ---- 0x1800423b0  FUN_1800423b0  (114 bytes) ---- */

void FUN_1800423b0(ulonglong *param_1,int param_2,ulonglong *param_3,undefined8 param_4)

{
  logger *plVar1;
  ulonglong uStack_38;
  ulonglong uStack_30;
  ulonglong uStack_28;
  ulonglong uStack_20;
  ulonglong uStack_18;
  
  plVar1 = spdlog::default_logger_raw();
  uStack_38 = *param_3;
  uStack_30 = param_3[1];
  uStack_28 = *param_1;
  uStack_20 = param_1[1];
  uStack_18 = param_1[2];
  FUN_180042920(&plVar1->_padding_,&uStack_28,param_2,&uStack_38,param_4);
  return;
}


/* ---- 0x180042430  FUN_180042430  (127 bytes) ---- */

void FUN_180042430(ulonglong *param_1,int param_2,ulonglong *param_3,undefined8 *param_4,
                  undefined8 *param_5)

{
  logger *plVar1;
  ulonglong local_38;
  ulonglong uStack_30;
  ulonglong local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  plVar1 = spdlog::default_logger_raw();
  local_38 = *param_3;
  uStack_30 = param_3[1];
  local_28 = *param_1;
  uStack_20 = param_1[1];
  local_18 = param_1[2];
  FUN_180042b50(&plVar1->_padding_,&local_28,param_2,&local_38,param_4,param_5);
  return;
}


/* ---- 0x1800424b0  FUN_1800424b0  (127 bytes) ---- */

void FUN_1800424b0(ulonglong *param_1,int param_2,ulonglong *param_3,undefined8 *param_4,
                  undefined8 *param_5)

{
  logger *plVar1;
  ulonglong uStack_38;
  ulonglong uStack_30;
  ulonglong uStack_28;
  ulonglong uStack_20;
  ulonglong uStack_18;
  
  plVar1 = spdlog::default_logger_raw();
  uStack_38 = *param_3;
  uStack_30 = param_3[1];
  uStack_28 = *param_1;
  uStack_20 = param_1[1];
  uStack_18 = param_1[2];
  FUN_180042da0(&plVar1->_padding_,&uStack_28,param_2,&uStack_38,param_4,param_5);
  return;
}


/* ---- 0x180042530  FUN_180042530  (4 bytes) ---- */

undefined8 FUN_180042530(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180042540  FUN_180042540  (15 bytes) ---- */

undefined8 * FUN_180042540(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 0;
  param_1[1] = param_2;
  return param_1;
}


/* ---- 0x180042550  FUN_180042550  (161 bytes) ---- */

void FUN_180042550(undefined ***param_1,longlong *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined4 *param_5)

{
  undefined1 auStack_98 [32];
  undefined8 uStack_78;
  undefined8 *puStack_70;
  longlong lStack_58;
  longlong lStack_50;
  undefined8 auStack_48 [2];
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  ulonglong uStack_18;
  
  uStack_18 = __security_cookie ^ (ulonglong)auStack_98;
  auStack_48[0] = *param_3;
  uStack_78._4_4_ = (undefined4)((ulonglong)param_1 >> 0x20);
  uStack_78._0_4_ = *param_5;
  auStack_48[1] = uStack_78;
  uStack_38 = *param_4;
  puStack_70 = auStack_48;
  uStack_30 = uStack_78;
  uStack_28 = uStack_78;
  uStack_78 = 0x1cc;
  lStack_58 = *param_2;
  lStack_50 = param_2[1];
  fmt::v10::vformat(param_1,&lStack_58,(undefined1 (*) [16])&uStack_78);
  __security_check_cookie(uStack_18 ^ (ulonglong)auStack_98);
  return;
}


/* ---- 0x180042600  FUN_180042600  (24 bytes) ---- */

undefined8 * FUN_180042600(undefined8 *param_1,undefined4 *param_2)

{
  undefined4 uStack_14;
  undefined8 uStack_10;
  
  *param_1 = CONCAT44(uStack_14,*param_2);
  param_1[1] = uStack_10;
  return param_1;
}


/* ---- 0x180042620  FUN_180042620  (15 bytes) ---- */

undefined8 * FUN_180042620(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 1;
  param_1[1] = param_2;
  return param_1;
}


/* ---- 0x180042630  FUN_180042630  (39 bytes) ---- */

undefined8 * FUN_180042630(undefined8 *param_1)

{
  *param_1 = "_level0.HUDMovieBaseInstance.CompassShoutMeterHolder.Compass";
  param_1[1] = 0x3c;
  return param_1;
}


/* ---- 0x180042660  FUN_180042660  (15 bytes) ---- */

undefined8 * FUN_180042660(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 0xd;
  param_1[1] = param_2;
  return param_1;
}


/* ---- 0x180042670  FUN_180042670  (64 bytes) ---- */

undefined8 *
FUN_180042670(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uVar1 = *param_3;
  uVar2 = *param_4;
  uStack_14 = (undefined4)((ulonglong)*param_2 >> 0x20);
  *param_1 = *param_2;
  param_1[1] = CONCAT44(uStack_c,uStack_10);
  *(undefined4 *)(param_1 + 2) = uVar1;
  *(undefined4 *)((longlong)param_1 + 0x14) = uStack_14;
  *(undefined4 *)(param_1 + 3) = uStack_10;
  *(undefined4 *)((longlong)param_1 + 0x1c) = uStack_c;
  *(undefined4 *)(param_1 + 4) = uVar2;
  *(undefined4 *)((longlong)param_1 + 0x24) = uStack_14;
  *(undefined4 *)(param_1 + 5) = uStack_10;
  *(undefined4 *)((longlong)param_1 + 0x2c) = uStack_c;
  return param_1;
}


/* ---- 0x1800426b0  FUN_1800426b0  (15 bytes) ---- */

undefined8 * FUN_1800426b0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 0x99c;
  param_1[1] = param_2;
  return param_1;
}


/* ---- 0x1800426c0  FUN_1800426c0  (66 bytes) ---- */

void FUN_1800426c0(longlong *param_1,ulonglong *param_2,int param_3,ulonglong *param_4,
                  undefined8 param_5)

{
  ulonglong uStack_38;
  ulonglong uStack_30;
  ulonglong uStack_28;
  ulonglong uStack_20;
  ulonglong uStack_18;
  
  uStack_38 = *param_4;
  uStack_30 = param_4[1];
  uStack_28 = *param_2;
  uStack_20 = param_2[1];
  uStack_18 = param_2[2];
  FUN_180042920(param_1,&uStack_28,param_3,&uStack_38,param_5);
  return;
}


/* ---- 0x180042710  FUN_180042710  (79 bytes) ---- */

void FUN_180042710(longlong *param_1,ulonglong *param_2,int param_3,ulonglong *param_4,
                  undefined8 *param_5,undefined8 *param_6)

{
  ulonglong local_38;
  ulonglong uStack_30;
  ulonglong local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  local_38 = *param_4;
  uStack_30 = param_4[1];
  local_28 = *param_2;
  uStack_20 = param_2[1];
  local_18 = param_2[2];
  FUN_180042b50(param_1,&local_28,param_3,&local_38,param_5,param_6);
  return;
}


/* ---- 0x180042760  FUN_180042760  (79 bytes) ---- */

void FUN_180042760(longlong *param_1,ulonglong *param_2,int param_3,ulonglong *param_4,
                  undefined8 *param_5,undefined8 *param_6)

{
  ulonglong uStack_38;
  ulonglong uStack_30;
  ulonglong uStack_28;
  ulonglong uStack_20;
  ulonglong uStack_18;
  
  uStack_38 = *param_4;
  uStack_30 = param_4[1];
  uStack_28 = *param_2;
  uStack_20 = param_2[1];
  uStack_18 = param_2[2];
  FUN_180042da0(param_1,&uStack_28,param_3,&uStack_38,param_5,param_6);
  return;
}


/* ---- 0x1800427b0  FUN_1800427b0  (10 bytes) ---- */

undefined8 * FUN_1800427b0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_1[1];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  return param_2;
}


/* ---- 0x1800427c0  FUN_1800427c0  (10 bytes) ---- */

undefined8 * FUN_1800427c0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_1[1];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  return param_2;
}


/* ---- 0x1800427d0  FUN_1800427d0  (10 bytes) ---- */

undefined8 * FUN_1800427d0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_1[1];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  return param_2;
}


/* ---- 0x1800427e0  FUN_1800427e0  (10 bytes) ---- */

undefined8 * FUN_1800427e0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_1[1];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  return param_2;
}


/* ---- 0x1800427f0  FUN_1800427f0  (38 bytes) ---- */

undefined8 * FUN_1800427f0(undefined8 *param_1)

{
  param_1[2] = 0;
  *param_1 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
  param_1[1] = param_1 + 4;
  param_1[3] = 0xfa;
  return param_1;
}


/* ---- 0x180042820  FUN_180042820  (4 bytes) ---- */

undefined8 FUN_180042820(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180042830  FUN_180042830  (59 bytes) ---- */

undefined8 *
FUN_180042830(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uStack_30;
  undefined8 uStack_20;
  undefined4 uStack_14;
  undefined8 uStack_10;
  
  uVar2 = *param_3;
  uVar1 = *param_4;
  *param_1 = *param_2;
  param_1[1] = uStack_30;
  param_1[2] = uVar2;
  param_1[3] = uStack_20;
  param_1[4] = CONCAT44(uStack_14,uVar1);
  param_1[5] = uStack_10;
  return param_1;
}


/* ---- 0x180042870  FUN_180042870  (15 bytes) ---- */

undefined8 * FUN_180042870(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 0x1cc;
  param_1[1] = param_2;
  return param_1;
}


/* ---- 0x180042880  FUN_180042880  (24 bytes) ---- */

undefined8 * FUN_180042880(undefined8 *param_1,undefined4 *param_2)

{
  undefined4 uStack_14;
  undefined8 uStack_10;
  
  *param_1 = CONCAT44(uStack_14,*param_2);
  param_1[1] = uStack_10;
  return param_1;
}


/* ---- 0x1800428a0  FUN_1800428a0  (39 bytes) ---- */

undefined8 * FUN_1800428a0(undefined8 *param_1)

{
  *param_1 = "_level0.HUDMovieBaseInstance.CompassShoutMeterHolder.Compass";
  param_1[1] = 0x3c;
  return param_1;
}


/* ---- 0x1800428d0  FUN_1800428d0  (64 bytes) ---- */

undefined8 *
FUN_1800428d0(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uVar1 = *param_3;
  uVar2 = *param_4;
  uStack_14 = (undefined4)((ulonglong)*param_2 >> 0x20);
  *param_1 = *param_2;
  param_1[1] = CONCAT44(uStack_c,uStack_10);
  *(undefined4 *)(param_1 + 2) = uVar1;
  *(undefined4 *)((longlong)param_1 + 0x14) = uStack_14;
  *(undefined4 *)(param_1 + 3) = uStack_10;
  *(undefined4 *)((longlong)param_1 + 0x1c) = uStack_c;
  *(undefined4 *)(param_1 + 4) = uVar2;
  *(undefined4 *)((longlong)param_1 + 0x24) = uStack_14;
  *(undefined4 *)(param_1 + 5) = uStack_10;
  *(undefined4 *)((longlong)param_1 + 0x2c) = uStack_c;
  return param_1;
}


/* ---- 0x180042910  FUN_180042910  (10 bytes) ---- */

undefined8 * FUN_180042910(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  return param_1;
}


/* ---- 0x180042920  FUN_180042920  (536 bytes) ---- */

void FUN_180042920(longlong *param_1,ulonglong *param_2,int param_3,ulonglong *param_4,
                  undefined8 param_5)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  undefined1 *_Memory;
  undefined1 auStackY_288 [32];
  undefined1 *local_258;
  undefined8 *puStack_250;
  longlong *local_248;
  ulonglong *local_238;
  ulonglong local_218;
  ulonglong uStack_210;
  ulonglong local_208;
  longlong *local_1f8;
  longlong local_1f0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  log_msg local_1c8;
  undefined **local_168;
  undefined1 *local_160;
  undefined8 local_158;
  ulonglong local_150;
  undefined1 local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_288;
  local_248 = param_1;
  local_238 = param_2;
  piVar3 = std::_Atomic_address_as<int,std::_Atomic_padded<int>_>
                     ((_Atomic_padded<int> *)(param_1 + 8));
  iVar1 = *piVar3;
  bVar2 = spdlog::details::backtracer::enabled((backtracer *)(param_1 + 0x11));
  if ((iVar1 <= param_3) || (bVar2)) {
    local_158 = 0;
    local_168 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
    local_160 = local_148;
    local_150 = 0xfa;
    local_1d8 = param_5;
    uStack_1d0 = puStack_250;
    local_258 = (undefined1 *)0xc;
    puStack_250 = &local_1d8;
    local_218 = *param_4;
    uStack_210 = param_4[1];
    fmt::v10::vformat_to<fmt::v10::appender,0>
              (&local_1f8,&local_168,&local_218,(ulonglong *)&local_258);
    local_1f8 = param_1 + 1;
    if (0xf < (ulonglong)param_1[4]) {
      local_1f8 = (longlong *)param_1[1];
    }
    local_258 = local_160;
    puStack_250 = (undefined8 *)local_158;
    local_1f0 = param_1[3];
    local_218 = *param_2;
    uStack_210 = param_2[1];
    local_208 = param_2[2];
    spdlog::details::log_msg::log_msg
              (&local_1c8,&local_218,(undefined4 *)&local_1f8,param_3,&local_258);
    spdlog::logger::log_it_((logger *)param_1,(undefined8 *)&local_1c8,iVar1 <= param_3,bVar2);
    local_168 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
    if (local_160 != local_148) {
      _Memory = local_160;
      if ((0xfff < local_150) &&
         (_Memory = *(undefined1 **)(local_160 + -8),
         (undefined1 *)0x1f < local_160 + (-8 - (longlong)_Memory))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      free(_Memory);
    }
  }
  __security_check_cookie(local_48 ^ (ulonglong)auStackY_288);
  return;
}


/* ---- 0x180042b40  FUN_180042b40  (10 bytes) ---- */

undefined8 * FUN_180042b40(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  return param_1;
}


/* ---- 0x180042b50  FUN_180042b50  (574 bytes) ---- */

void FUN_180042b50(longlong *param_1,ulonglong *param_2,int param_3,ulonglong *param_4,
                  undefined8 *param_5,undefined8 *param_6)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  undefined1 *_Memory;
  undefined1 auStackY_288 [32];
  undefined1 *local_258;
  undefined8 *local_250;
  ulonglong *local_248;
  longlong *local_238;
  longlong *local_228;
  longlong local_220;
  ulonglong local_208;
  ulonglong uStack_200;
  ulonglong local_1f8;
  undefined8 local_1e8;
  ulonglong *local_1e0;
  undefined8 local_1d8;
  ulonglong *local_1d0;
  log_msg local_1c8;
  undefined **local_168;
  undefined1 *local_160;
  undefined8 local_158;
  ulonglong local_150;
  undefined1 local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_288;
  local_248 = param_2;
  local_238 = param_1;
  piVar3 = std::_Atomic_address_as<int,std::_Atomic_padded<int>_>
                     ((_Atomic_padded<int> *)(param_1 + 8));
  iVar1 = *piVar3;
  bVar2 = spdlog::details::backtracer::enabled((backtracer *)(param_1 + 0x11));
  if ((iVar1 <= param_3) || (bVar2)) {
    local_158 = 0;
    local_168 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
    local_160 = local_148;
    local_150 = 0xfa;
    local_1e8 = *param_5;
    local_1e0 = local_248;
    local_1d8 = *param_6;
    local_1d0 = local_248;
    local_258 = (undefined1 *)0xcc;
    local_250 = &local_1e8;
    local_208 = *param_4;
    uStack_200 = param_4[1];
    fmt::v10::vformat_to<fmt::v10::appender,0>
              (&local_228,&local_168,&local_208,(ulonglong *)&local_258);
    local_228 = param_1 + 1;
    if (0xf < (ulonglong)param_1[4]) {
      local_228 = (longlong *)param_1[1];
    }
    local_258 = local_160;
    local_250 = (undefined8 *)local_158;
    local_220 = param_1[3];
    local_208 = *param_2;
    uStack_200 = param_2[1];
    local_1f8 = param_2[2];
    spdlog::details::log_msg::log_msg
              (&local_1c8,&local_208,(undefined4 *)&local_228,param_3,&local_258);
    spdlog::logger::log_it_((logger *)param_1,(undefined8 *)&local_1c8,iVar1 <= param_3,bVar2);
    local_168 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
    if (local_160 != local_148) {
      _Memory = local_160;
      if ((0xfff < local_150) &&
         (_Memory = *(undefined1 **)(local_160 + -8),
         (undefined1 *)0x1f < local_160 + (-8 - (longlong)_Memory))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      free(_Memory);
    }
  }
  __security_check_cookie(local_48 ^ (ulonglong)auStackY_288);
  return;
}


/* ---- 0x180042d90  FUN_180042d90  (10 bytes) ---- */

undefined8 * FUN_180042d90(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  return param_1;
}


/* ---- 0x180042da0  FUN_180042da0  (574 bytes) ---- */

void FUN_180042da0(longlong *param_1,ulonglong *param_2,int param_3,ulonglong *param_4,
                  undefined8 *param_5,undefined8 *param_6)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  undefined1 *_Memory;
  undefined1 auStackY_288 [32];
  undefined1 *local_258;
  undefined8 *local_250;
  ulonglong *local_248;
  longlong *local_238;
  longlong *local_228;
  longlong local_220;
  ulonglong local_208;
  ulonglong uStack_200;
  ulonglong local_1f8;
  undefined8 local_1e8;
  ulonglong *local_1e0;
  undefined8 local_1d8;
  ulonglong *local_1d0;
  log_msg local_1c8;
  undefined **local_168;
  undefined1 *local_160;
  undefined8 local_158;
  ulonglong local_150;
  undefined1 local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_288;
  local_248 = param_2;
  local_238 = param_1;
  piVar3 = std::_Atomic_address_as<int,std::_Atomic_padded<int>_>
                     ((_Atomic_padded<int> *)(param_1 + 8));
  iVar1 = *piVar3;
  bVar2 = spdlog::details::backtracer::enabled((backtracer *)(param_1 + 0x11));
  if ((iVar1 <= param_3) || (bVar2)) {
    local_158 = 0;
    local_168 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
    local_160 = local_148;
    local_150 = 0xfa;
    local_1e8 = *param_5;
    local_1e0 = local_248;
    local_1d8 = *param_6;
    local_1d0 = local_248;
    local_258 = (undefined1 *)0xcc;
    local_250 = &local_1e8;
    local_208 = *param_4;
    uStack_200 = param_4[1];
    fmt::v10::vformat_to<fmt::v10::appender,0>
              (&local_228,&local_168,&local_208,(ulonglong *)&local_258);
    local_228 = param_1 + 1;
    if (0xf < (ulonglong)param_1[4]) {
      local_228 = (longlong *)param_1[1];
    }
    local_258 = local_160;
    local_250 = (undefined8 *)local_158;
    local_220 = param_1[3];
    local_208 = *param_2;
    uStack_200 = param_2[1];
    local_1f8 = param_2[2];
    spdlog::details::log_msg::log_msg
              (&local_1c8,&local_208,(undefined4 *)&local_228,param_3,&local_258);
    spdlog::logger::log_it_((logger *)param_1,(undefined8 *)&local_1c8,iVar1 <= param_3,bVar2);
    local_168 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
    if (local_160 != local_148) {
      _Memory = local_160;
      if ((0xfff < local_150) &&
         (_Memory = *(undefined1 **)(local_160 + -8),
         (undefined1 *)0x1f < local_160 + (-8 - (longlong)_Memory))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      free(_Memory);
    }
  }
  __security_check_cookie(local_48 ^ (ulonglong)auStackY_288);
  return;
}


/* ---- 0x180042fe0  FUN_180042fe0  (43 bytes) ---- */

longlong FUN_180042fe0(void *param_1,size_t param_2,char param_3)

{
  memset(param_1,(int)param_3,param_2);
  return (longlong)param_1 + param_2;
}


/* ---- 0x180043010  FUN_180043010  (10 bytes) ---- */

undefined8 * FUN_180043010(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_1[1];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  return param_2;
}


/* ---- 0x180043020  FUN_180043020  (4 bytes) ---- */

undefined8 FUN_180043020(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180043030  FUN_180043030  (153 bytes) ---- */

byte * FUN_180043030(byte *param_1,ulonglong param_2,byte *param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong _Size;
  
  uVar1 = 0;
  if (param_2 != 0) {
    if (0xf < param_2) {
      if ((param_3 < param_1) || (param_1 + (param_2 - 1) < param_3)) {
        _Size = param_2 & 0xfffffffffffffff0;
        do {
          uVar1 = uVar1 + 0x10;
        } while (uVar1 < _Size);
        memset(param_1,(uint)*param_3,_Size);
        param_1 = param_1 + _Size;
        if (param_2 <= uVar1) {
          return param_1;
        }
      }
    }
    lVar2 = param_2 - uVar1;
    do {
      *param_1 = *param_3;
      param_1 = param_1 + 1;
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
  }
  return param_1;
}


/* ---- 0x1800430d0  FUN_1800430d0  (4 bytes) ---- */

undefined8 FUN_1800430d0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800430f0  FUN_1800430f0  (59 bytes) ---- */

undefined8 *
FUN_1800430f0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uStack_30;
  undefined8 uStack_20;
  undefined4 uStack_14;
  undefined8 uStack_10;
  
  uVar2 = *param_3;
  uVar1 = *param_4;
  *param_1 = *param_2;
  param_1[1] = uStack_30;
  param_1[2] = uVar2;
  param_1[3] = uStack_20;
  param_1[4] = CONCAT44(uStack_14,uVar1);
  param_1[5] = uStack_10;
  return param_1;
}


/* ---- 0x180043130  FUN_180043130  (8 bytes) ---- */

undefined4 * FUN_180043130(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


/* ---- 0x180043150  FUN_180043150  (22 bytes) ---- */

undefined8 * FUN_180043150(undefined8 *param_1)

{
  *param_1 = "_level0.HUDMovieBaseInstance.CompassShoutMeterHolder.Compass";
  param_1[1] = 0x3c;
  return param_1;
}


/* ---- 0x180043180  FUN_180043180  (8 bytes) ---- */

undefined4 * FUN_180043180(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


/* ---- 0x1800431a0  FUN_1800431a0  (23 bytes) ---- */

undefined8 * FUN_1800431a0(undefined8 *param_1,undefined8 param_2)

{
  undefined8 uStack_10;
  
  *param_1 = param_2;
  param_1[1] = uStack_10;
  return param_1;
}


/* ---- 0x1800431c0  FUN_1800431c0  (15 bytes) ---- */

undefined8 * FUN_1800431c0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 0xc;
  param_1[1] = param_2;
  return param_1;
}


/* ---- 0x1800431d0  FUN_1800431d0  (43 bytes) ---- */

undefined8 * FUN_1800431d0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 uStack_20;
  undefined8 uStack_10;
  
  uVar1 = *param_3;
  *param_1 = *param_2;
  param_1[1] = uStack_20;
  param_1[2] = uVar1;
  param_1[3] = uStack_10;
  return param_1;
}


/* ---- 0x180043200  FUN_180043200  (15 bytes) ---- */

undefined8 * FUN_180043200(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 0xcc;
  param_1[1] = param_2;
  return param_1;
}


/* ---- 0x180043210  FUN_180043210  (4 bytes) ---- */

undefined8 FUN_180043210(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180043230  FUN_180043230  (10 bytes) ---- */

undefined8 * FUN_180043230(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_1[1];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  return param_2;
}


/* ---- 0x180043240  FUN_180043240  (10 bytes) ---- */

undefined8 * FUN_180043240(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_1[1];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  return param_2;
}


/* ---- 0x180043250  FUN_180043250  (10 bytes) ---- */

undefined8 * FUN_180043250(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_1[1];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  return param_2;
}


/* ---- 0x180043260  FUN_180043260  (18 bytes) ---- */

undefined8 * FUN_180043260(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = *param_3;
  param_2[1] = param_3[1];
  *param_2 = uVar1;
  return param_2;
}


/* ---- 0x1800432a0  FUN_1800432a0  (23 bytes) ---- */

undefined8 * FUN_1800432a0(undefined8 *param_1,undefined8 param_2)

{
  undefined8 uStack_10;
  
  *param_1 = param_2;
  param_1[1] = uStack_10;
  return param_1;
}


/* ---- 0x1800432c0  FUN_1800432c0  (43 bytes) ---- */

undefined8 * FUN_1800432c0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 uStack_20;
  undefined8 uStack_10;
  
  uVar1 = *param_3;
  *param_1 = *param_2;
  param_1[1] = uStack_20;
  param_1[2] = uVar1;
  param_1[3] = uStack_10;
  return param_1;
}


/* ---- 0x1800432f0  FUN_1800432f0  (4 bytes) ---- */

undefined8 FUN_1800432f0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180043310  FUN_180043310  (18 bytes) ---- */

undefined8 * FUN_180043310(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  return param_1;
}


/* ---- 0x180043330  FUN_180043330  (6 bytes) ---- */

undefined4 * FUN_180043330(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180043340  FUN_180043340  (4 bytes) ---- */

undefined8 FUN_180043340(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180043350  FUN_180043350  (18 bytes) ---- */

undefined8 * FUN_180043350(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = *param_2;
  param_1[1] = param_2[1];
  *param_1 = uVar1;
  return param_1;
}


/* ---- 0x180043370  FUN_180043370  (7 bytes) ---- */

undefined8 * FUN_180043370(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180043390  FUN_180043390  (18 bytes) ---- */

undefined8 * FUN_180043390(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  uVar1 = param_3[1];
  param_1[2] = *param_3;
  param_1[3] = uVar1;
  return param_1;
}


/* ---- 0x1800433d0  FUN_1800433d0  (4 bytes) ---- */

undefined8 FUN_1800433d0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800433e0  FUN_1800433e0  (4 bytes) ---- */

undefined4 FUN_1800433e0(undefined8 param_1,undefined4 param_2)

{
  return param_2;
}


/* ---- 0x1800433f0  FUN_1800433f0  (8 bytes) ---- */

undefined4 * FUN_1800433f0(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180043410  FUN_180043410  (26 bytes) ---- */

undefined8 *
FUN_180043410(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  uVar1 = param_3[1];
  param_1[2] = *param_3;
  param_1[3] = uVar1;
  uVar1 = param_4[1];
  param_1[4] = *param_4;
  param_1[5] = uVar1;
  return param_1;
}


/* ---- 0x180043430  FUN_180043430  (4 bytes) ---- */

undefined8 FUN_180043430(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180043440  FUN_180043440  (10 bytes) ---- */

undefined8 * FUN_180043440(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  return param_1;
}


/* ---- 0x180043450  FUN_180043450  (7 bytes) ---- */

undefined8 * FUN_180043450(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180043460  FUN_180043460  (4 bytes) ---- */

undefined8 FUN_180043460(undefined8 param_1,undefined8 param_2)

{
  return param_2;
}


/* ---- 0x180043470  FUN_180043470  (10 bytes) ---- */

undefined8 * FUN_180043470(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


/* ---- 0x1800434a0  FUN_1800434a0  (26 bytes) ---- */

undefined8 * FUN_1800434a0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uStack_10;
  
  *param_1 = *param_2;
  param_1[1] = uStack_10;
  return param_1;
}


/* ---- 0x1800434c0  FUN_1800434c0  (26 bytes) ---- */

undefined8 * FUN_1800434c0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uStack_10;
  
  *param_1 = *param_2;
  param_1[1] = uStack_10;
  return param_1;
}


/* ---- 0x1800434e0  FUN_1800434e0  (11 bytes) ---- */

undefined8 * FUN_1800434e0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return param_1;
}


/* ---- 0x1800434f0  FUN_1800434f0  (4 bytes) ---- */

undefined8 FUN_1800434f0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180043500  FUN_180043500  (15 bytes) ---- */

undefined8 * FUN_180043500(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 0xc;
  param_1[1] = param_2;
  return param_1;
}


/* ---- 0x180043510  FUN_180043510  (10 bytes) ---- */

undefined8 * FUN_180043510(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_1[1];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  return param_2;
}


/* ---- 0x180043520  FUN_180043520  (4 bytes) ---- */

undefined8 FUN_180043520(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180043530  FUN_180043530  (7 bytes) ---- */

undefined8 * FUN_180043530(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180043540  FUN_180043540  (7 bytes) ---- */

undefined8 * FUN_180043540(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180043550  FUN_180043550  (4 bytes) ---- */

undefined8 FUN_180043550(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180043560  FUN_180043560  (26 bytes) ---- */

undefined8 *
FUN_180043560(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  param_1[1] = param_2;
  *param_1 = fmt::v10::detail::buffer<char>::vftable;
  param_1[2] = param_3;
  param_1[3] = param_4;
  return param_1;
}


/* ---- 0x180043580  FUN_180043580  (42 bytes) ---- */

undefined8 * FUN_180043580(undefined8 *param_1,undefined8 param_2)

{
  param_1[2] = 0;
  param_1[1] = param_1 + 5;
  *param_1 = fmt::v10::detail::
             iterator_buffer<class_fmt::v10::appender,char,struct_fmt::v10::detail::buffer_traits>::
             vftable;
  param_1[3] = 0x100;
  param_1[4] = param_2;
  return param_1;
}


/* ---- 0x1800435b0  FUN_1800435b0  (42 bytes) ---- */

undefined8 * FUN_1800435b0(undefined8 *param_1,undefined8 param_2)

{
  param_1[2] = 0;
  param_1[1] = param_1 + 5;
  *param_1 = fmt::v10::detail::
             iterator_buffer<class_fmt::v10::appender,char,struct_fmt::v10::detail::buffer_traits>::
             vftable;
  param_1[3] = 0x100;
  param_1[4] = param_2;
  return param_1;
}


/* ---- 0x1800435f0  FUN_1800435f0  (25 bytes) ---- */

void FUN_1800435f0(iterator_buffer<fmt::v10::appender,char,fmt::v10::detail::buffer_traits> *param_1
                  )

{
  *(undefined ***)param_1 =
       fmt::v10::detail::
       iterator_buffer<class_fmt::v10::appender,char,struct_fmt::v10::detail::buffer_traits>::
       vftable;
  fmt::v10::detail::iterator_buffer<fmt::v10::appender,char,fmt::v10::detail::buffer_traits>::flush
            (param_1);
  return;
}


/* ---- 0x180043610  FUN_180043610  (11 bytes) ---- */

undefined8 * FUN_180043610(undefined8 *param_1)

{
  *param_1 = 0;
  return param_1;
}


/* ---- 0x180043620  FUN_180043620  (9 bytes) ---- */

void FUN_180043620(longlong param_1)

{
  *(undefined8 *)(param_1 + 0x10) = 0;
  return;
}


/* ---- 0x180043630  FUN_180043630  (13 bytes) ---- */

void FUN_180043630(undefined8 *param_1,ulonglong param_2)

{
  if ((ulonglong)param_1[3] < param_2) {
                    /* WARNING: Could not recover jumptable at 0x000180043639. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)*param_1)();
    return;
  }
  return;
}


/* ---- 0x180043680  FUN_180043680  (82 bytes) ---- */

longlong * FUN_180043680(longlong *param_1,undefined1 *param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)*param_1;
  if ((ulonglong)puVar1[3] < puVar1[2] + 1) {
    (**(code **)*puVar1)(puVar1);
  }
  *(undefined1 *)(puVar1[1] + puVar1[2]) = *param_2;
  puVar1[2] = puVar1[2] + 1;
  return param_1;
}


/* ---- 0x1800436e0  FUN_1800436e0  (4 bytes) ---- */

undefined8 FUN_1800436e0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800436f0  FUN_1800436f0  (10 bytes) ---- */

undefined8 * FUN_1800436f0(undefined8 *param_1,undefined8 *param_2)

{
  *param_2 = *param_1;
  return param_2;
}


/* ---- 0x180043790  FUN_180043790  (4 bytes) ---- */

undefined8 FUN_180043790(undefined8 param_1,undefined8 param_2)

{
  return param_2;
}


/* ---- 0x1800439b0  FUN_1800439b0  (29 bytes) ---- */

void * FUN_1800439b0(undefined8 param_1,ulonglong param_2)

{
  code *pcVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  
  if (param_2 == 0) {
    return (void *)0x0;
  }
  if (0xfff < param_2) {
    if (param_2 + 0x27 <= param_2) {
      FUN_180039810();
      pcVar1 = (code *)swi(3);
      pvVar4 = (void *)(*pcVar1)();
      return pvVar4;
    }
    pvVar4 = operator_new(param_2 + 0x27);
    if (pvVar4 != (void *)0x0) {
      pvVar3 = (void *)((longlong)pvVar4 + 0x27U & 0xffffffffffffffe0);
      *(void **)((longlong)pvVar3 - 8) = pvVar4;
      return pvVar3;
    }
                    /* WARNING: Subroutine does not return */
    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  do {
    pvVar4 = malloc(param_2);
    if (pvVar4 != (void *)0x0) {
      return pvVar4;
    }
    iVar2 = _callnewh(param_2);
  } while (iVar2 != 0);
  if (param_2 == 0xffffffffffffffff) {
    FUN_180154eb0();
    pcVar1 = (code *)swi(3);
    pvVar4 = (void *)(*pcVar1)();
    return pvVar4;
  }
  FUN_180154e90();
  pcVar1 = (code *)swi(3);
  pvVar4 = (void *)(*pcVar1)();
  return pvVar4;
}


/* ---- 0x1800439e0  FUN_1800439e0  (4 bytes) ---- */

undefined8 FUN_1800439e0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x1800439f0  FUN_1800439f0  (4 bytes) ---- */

undefined8 FUN_1800439f0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180043a00  FUN_180043a00  (14 bytes) ---- */

void * FUN_180043a00(void *param_1,size_t param_2,void *param_3)

{
  char *pcVar1;
  
  if (param_2 == 0) {
    return param_3;
  }
  pcVar1 = std::_Copy_memmove_n<char_*,char_*>(param_1,param_2,param_3);
  return pcVar1;
}


/* ---- 0x180043a10  FUN_180043a10  (5 bytes) ---- */

undefined8 FUN_180043a10(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x10);
}


/* ---- 0x180043a20  FUN_180043a20  (9 bytes) ---- */

void FUN_180043a20(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  *(undefined8 *)(param_1 + 8) = param_2;
  *(undefined8 *)(param_1 + 0x18) = param_3;
  return;
}


/* ---- 0x180043b10  FUN_180043b10  (5 bytes) ---- */

undefined8 FUN_180043b10(longlong param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


/* ---- 0x180043b20  FUN_180043b20  (5 bytes) ---- */

undefined8 FUN_180043b20(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x18);
}


/* ---- 0x180043b30  FUN_180043b30  (96 bytes) ---- */

void FUN_180043b30(longlong param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = *(void **)(param_1 + 8);
  if (pvVar1 == (void *)(param_1 + 0x20)) {
    return;
  }
  _Memory = pvVar1;
  if ((0xfff < *(ulonglong *)(param_1 + 0x18)) &&
     (_Memory = *(void **)((longlong)pvVar1 + -8),
     0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  free(_Memory);
  return;
}


/* ---- 0x180043ba0  FUN_180043ba0  (106 bytes) ---- */

void FUN_180043ba0(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 *_Memory;
  
  *param_1 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
  puVar1 = (undefined8 *)param_1[1];
  if (puVar1 == param_1 + 4) {
    return;
  }
  _Memory = puVar1;
  if ((0xfff < (ulonglong)param_1[3]) &&
     (_Memory = (undefined8 *)puVar1[-1],
     0x1f < (ulonglong)((longlong)puVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  free(_Memory);
  return;
}


/* ---- 0x180043c10  FUN_180043c10  (23 bytes) ---- */

void FUN_180043c10(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)((longlong)param_1 + 0xc);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
                    /* WARNING: Could not recover jumptable at 0x000180043c22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 8))();
    return;
  }
  return;
}


/* ---- 0x180043c80  FUN_180043c80  (4 bytes) ---- */

undefined8 FUN_180043c80(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180043c90  FUN_180043c90  (54 bytes) ---- */

bool FUN_180043c90(undefined8 *param_1,undefined8 *param_2)

{
  size_t _Size;
  int iVar1;
  
  _Size = param_1[1];
  if (_Size != param_2[1]) {
    return false;
  }
  if (_Size == 0) {
    return true;
  }
  iVar1 = memcmp((void *)*param_1,(void *)*param_2,_Size);
  return iVar1 == 0;
}


/* ---- 0x180043d40  FUN_180043d40  (4 bytes) ---- */

undefined1 FUN_180043d40(undefined1 param_1)

{
  return param_1;
}


/* ---- 0x180043d50  FUN_180043d50  (11 bytes) ---- */

undefined8 * FUN_180043d50(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return param_1;
}


/* ---- 0x180043d70  FUN_180043d70  (5 bytes) ---- */

undefined8 FUN_180043d70(longlong param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


/* ---- 0x180043d80  FUN_180043d80  (4 bytes) ---- */

undefined8 FUN_180043d80(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180044100  FUN_180044100  (66 bytes) ---- */

void FUN_180044100(logger *param_1,ulonglong *param_2,level_enum param_3,ulonglong *param_4,
                  undefined8 *param_5)

{
  ulonglong uStack_38;
  ulonglong uStack_30;
  ulonglong uStack_28;
  ulonglong uStack_20;
  ulonglong uStack_18;
  
  uStack_38 = *param_4;
  uStack_30 = param_4[1];
  uStack_28 = *param_2;
  uStack_20 = param_2[1];
  uStack_18 = param_2[2];
  spdlog::logger::log_<unsigned___int64>(param_1,&uStack_28,param_3,&uStack_38,param_5);
  return;
}


/* ---- 0x180044150  FUN_180044150  (10 bytes) ---- */

undefined8 * FUN_180044150(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  return param_1;
}


/* ---- 0x180044390  FUN_180044390  (26 bytes) ---- */

undefined8 * FUN_180044390(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uStack_10;
  
  *param_1 = *param_2;
  param_1[1] = uStack_10;
  return param_1;
}


/* ---- 0x1800443b0  FUN_1800443b0  (15 bytes) ---- */

undefined8 * FUN_1800443b0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 4;
  param_1[1] = param_2;
  return param_1;
}


/* ---- 0x1800443c0  FUN_1800443c0  (10 bytes) ---- */

undefined8 * FUN_1800443c0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_1[1];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  return param_2;
}


/* ---- 0x1800443d0  FUN_1800443d0  (26 bytes) ---- */

undefined8 * FUN_1800443d0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uStack_10;
  
  *param_1 = *param_2;
  param_1[1] = uStack_10;
  return param_1;
}


/* ---- 0x1800443f0  FUN_1800443f0  (10 bytes) ---- */

undefined8 * FUN_1800443f0(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


/* ---- 0x180044410  FUN_180044410  (4 bytes) ---- */

undefined8 FUN_180044410(undefined8 param_1,undefined8 param_2)

{
  return param_2;
}


/* ---- 0x180044420  FUN_180044420  (7 bytes) ---- */

undefined8 * FUN_180044420(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180044430  FUN_180044430  (116 bytes) ---- */

undefined8 * FUN_180044430(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  return param_1;
}


/* ---- 0x1800444b0  FUN_1800444b0  (22 bytes) ---- */

undefined8 * FUN_1800444b0(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  return param_1;
}


/* ---- 0x1800444d0  FUN_1800444d0  (122 bytes) ---- */

undefined8 * FUN_1800444d0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  *param_1 = param_2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[1] = param_3;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 3;
  return param_1;
}


/* ---- 0x180044550  FUN_180044550  (121 bytes) ---- */

undefined8 * FUN_180044550(undefined8 *param_1,undefined8 param_2)

{
  param_1[2] = param_2;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 4;
  return param_1;
}


/* ---- 0x1800445d0  FUN_1800445d0  (133 bytes) ---- */

undefined8 * FUN_1800445d0(undefined8 *param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 6) = param_2;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined1 *)((longlong)param_1 + 0x31) = 0;
  *(undefined2 *)((longlong)param_1 + 0x32) = 0;
  *(undefined4 *)((longlong)param_1 + 0x34) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0x40;
  return param_1;
}


/* ---- 0x180044660  FUN_180044660  (10 bytes) ---- */

void FUN_180044660(longlong param_1)

{
  *(undefined2 *)(param_1 + 0xe0) = 0;
  return;
}


/* ---- 0x180044670  FUN_180044670  (6 bytes) ---- */

undefined8 FUN_180044670(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x28);
}


/* ---- 0x180044680  FUN_180044680  (6 bytes) ---- */

undefined8 FUN_180044680(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x58);
}


/* ---- 0x180044690  FUN_180044690  (6 bytes) ---- */

undefined8 FUN_180044690(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x10);
}


/* ---- 0x1800446a0  FUN_1800446a0  (5 bytes) ---- */

undefined1 FUN_1800446a0(longlong param_1)

{
  return *(undefined1 *)(param_1 + 0x30);
}


/* ---- 0x180044710  FUN_180044710  (5 bytes) ---- */

undefined8 FUN_180044710(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180044720  FUN_180044720  (6 bytes) ---- */

undefined8 FUN_180044720(longlong param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


/* ---- 0x180044730  FUN_180044730  (6 bytes) ---- */

undefined8 FUN_180044730(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x38);
}


/* ---- 0x180044740  FUN_180044740  (6 bytes) ---- */

undefined8 FUN_180044740(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x40);
}


/* ---- 0x180044750  FUN_180044750  (6 bytes) ---- */

undefined8 FUN_180044750(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x48);
}


/* ---- 0x180044760  FUN_180044760  (6 bytes) ---- */

undefined8 FUN_180044760(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x18);
}


/* ---- 0x180044770  FUN_180044770  (6 bytes) ---- */

undefined8 FUN_180044770(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x20);
}


/* ---- 0x180044780  FUN_180044780  (6 bytes) ---- */

undefined8 FUN_180044780(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x50);
}


/* ---- 0x1800447b0  FUN_1800447b0  (434 bytes) ---- */

void FUN_1800447b0(undefined8 *param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                  undefined1 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
                  undefined8 param_13,undefined8 param_14,undefined4 *param_15,undefined4 *param_16)

{
  *param_1 = param_3;
  param_1[1] = param_4;
  *(undefined2 *)(param_1 + 0x1c) = param_2;
  param_1[2] = param_5;
  param_1[4] = param_7;
  param_1[3] = param_6;
  param_1[7] = param_10;
  param_1[5] = param_8;
  param_1[9] = param_12;
  param_1[8] = param_11;
  *(undefined1 *)(param_1 + 6) = param_9;
  param_1[0xb] = param_14;
  param_1[10] = param_13;
  *(undefined4 *)(param_1 + 0xc) = *param_15;
  *(undefined4 *)((longlong)param_1 + 100) = param_15[1];
  *(undefined4 *)(param_1 + 0xd) = param_15[2];
  *(undefined4 *)((longlong)param_1 + 0x6c) = param_15[3];
  *(undefined4 *)(param_1 + 0xe) = param_15[4];
  *(undefined4 *)((longlong)param_1 + 0x74) = param_15[5];
  *(undefined4 *)(param_1 + 0xf) = param_15[6];
  *(undefined4 *)((longlong)param_1 + 0x7c) = param_15[7];
  *(undefined4 *)(param_1 + 0x10) = param_15[8];
  *(undefined4 *)((longlong)param_1 + 0x84) = param_15[9];
  *(undefined4 *)(param_1 + 0x11) = param_15[10];
  *(undefined4 *)((longlong)param_1 + 0x8c) = param_15[0xb];
  *(undefined4 *)(param_1 + 0x12) = param_15[0xc];
  *(undefined4 *)((longlong)param_1 + 0x94) = param_15[0xd];
  *(undefined4 *)(param_1 + 0x13) = param_15[0xe];
  *(undefined4 *)((longlong)param_1 + 0x9c) = param_15[0xf];
  *(undefined4 *)(param_1 + 0x14) = *param_16;
  *(undefined4 *)((longlong)param_1 + 0xa4) = param_16[1];
  *(undefined4 *)(param_1 + 0x15) = param_16[2];
  *(undefined4 *)((longlong)param_1 + 0xac) = param_16[3];
  *(undefined4 *)(param_1 + 0x16) = param_16[4];
  *(undefined4 *)((longlong)param_1 + 0xb4) = param_16[5];
  *(undefined4 *)(param_1 + 0x17) = param_16[6];
  *(undefined4 *)((longlong)param_1 + 0xbc) = param_16[7];
  *(undefined4 *)(param_1 + 0x18) = param_16[8];
  *(undefined4 *)((longlong)param_1 + 0xc4) = param_16[9];
  *(undefined4 *)(param_1 + 0x19) = param_16[10];
  *(undefined4 *)((longlong)param_1 + 0xcc) = param_16[0xb];
  *(undefined4 *)(param_1 + 0x1a) = param_16[0xc];
  *(undefined4 *)((longlong)param_1 + 0xd4) = param_16[0xd];
  *(undefined4 *)(param_1 + 0x1b) = param_16[0xe];
  *(undefined4 *)((longlong)param_1 + 0xdc) = param_16[0xf];
  return;
}


/* ---- 0x180044970  FUN_180044970  (12 bytes) ---- */

void FUN_180044970(longlong param_1,undefined1 param_2)

{
  *(ushort *)(param_1 + 0xe0) = *(ushort *)(param_1 + 0xe0) | 0x40;
  *(undefined1 *)(param_1 + 0x30) = param_2;
  return;
}


/* ---- 0x180044980  FUN_180044980  (186 bytes) ---- */

void FUN_180044980(longlong param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *(ushort *)(param_1 + 0xe0) = *(ushort *)(param_1 + 0xe0) | 0x1000;
    *(undefined4 *)(param_1 + 0xa0) = *param_2;
    *(undefined4 *)(param_1 + 0xa4) = param_2[1];
    *(undefined4 *)(param_1 + 0xa8) = param_2[2];
    *(undefined4 *)(param_1 + 0xac) = param_2[3];
    *(undefined4 *)(param_1 + 0xb0) = param_2[4];
    *(undefined4 *)(param_1 + 0xb4) = param_2[5];
    *(undefined4 *)(param_1 + 0xb8) = param_2[6];
    *(undefined4 *)(param_1 + 0xbc) = param_2[7];
    *(undefined4 *)(param_1 + 0xc0) = param_2[8];
    *(undefined4 *)(param_1 + 0xc4) = param_2[9];
    *(undefined4 *)(param_1 + 200) = param_2[10];
    *(undefined4 *)(param_1 + 0xcc) = param_2[0xb];
    *(undefined4 *)(param_1 + 0xd0) = param_2[0xc];
    *(undefined4 *)(param_1 + 0xd4) = param_2[0xd];
    *(undefined4 *)(param_1 + 0xd8) = param_2[0xe];
    *(undefined4 *)(param_1 + 0xdc) = param_2[0xf];
    return;
  }
  *(ushort *)(param_1 + 0xe0) = *(ushort *)(param_1 + 0xe0) & 0xefff;
  return;
}


/* ---- 0x180044cd0  FUN_180044cd0  (11 bytes) ---- */

void FUN_180044cd0(undefined8 *param_1)

{
  *param_1 = RE::GFxValue::ObjectInterface::ObjVisitor::vftable;
  return;
}


/* ---- 0x180044ce0  FUN_180044ce0  (11 bytes) ---- */

void FUN_180044ce0(undefined8 *param_1)

{
  *param_1 = RE::GFxValue::ObjectInterface::ArrVisitor::vftable;
  return;
}


/* ---- 0x180044cf0  FUN_180044cf0  (52 bytes) ---- */

undefined8 * FUN_180044cf0(undefined8 *param_1,uint param_2)

{
  FUN_180044ce0(param_1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* ---- 0x180044d30  FUN_180044d30  (7 bytes) ---- */

undefined8 * FUN_180044d30(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180044d40  FUN_180044d40  (84 bytes) ---- */

void FUN_180044d40(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  ulonglong local_18 [3];
  
  local_18[0] = 0x13974;
  local_18[1] = 0x1415d;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  lVar1 = FUN_18000f860(local_18);
  local_res20 = FUN_180047690(lVar1);
  FUN_180046ba0(&local_res20,&local_res8,&local_res10,&local_res18);
  return;
}


/* ---- 0x180044da0  FUN_180044da0  (84 bytes) ---- */

void FUN_180044da0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  ulonglong local_18 [3];
  
  local_18[0] = 0x13975;
  local_18[1] = 0x1415e;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  lVar1 = FUN_18000f860(local_18);
  local_res20 = FUN_180047690(lVar1);
  FUN_180046ba0(&local_res20,&local_res8,&local_res10,&local_res18);
  return;
}


/* ---- 0x180044e00  FUN_180044e00  (99 bytes) ---- */

void FUN_180044e00(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined1 local_res20 [8];
  ulonglong local_18 [3];
  
  local_18[0] = 0x13967;
  local_18[1] = 0x1414e;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20[0] = param_4;
  lVar1 = FUN_18000f860(local_18);
  local_18[0] = FUN_180047680(lVar1);
  FUN_180046be0(local_18,&local_res8,&local_res10,&local_res18,local_res20);
  return;
}


/* ---- 0x180044e70  FUN_180044e70  (109 bytes) ---- */

void FUN_180044e70(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  ulonglong local_18 [3];
  
  local_18[0] = 0x1395e;
  local_18[1] = 0x14145;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  lVar1 = FUN_18000f860(local_18);
  local_18[0] = FUN_180047670(lVar1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,char_const_*,RE::GFxValue_*,bool)const_,RE::GFxValue::ObjectInterface_const_*,void_*_&,char_const_*_&,RE::GFxValue_*_&,bool_&>
            (local_18,&local_res8,&local_res10,&local_res18,&local_res20);
  return;
}


/* ---- 0x180044ee0  FUN_180044ee0  (104 bytes) ---- */

void FUN_180044ee0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  ulonglong local_18 [2];
  
  local_18[0] = 0x1398c;
  local_18[1] = 0x14174;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18[0] = param_3;
  lVar1 = FUN_18000f860(local_18);
  local_18[0] = FUN_180047660(lVar1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,char_const_*,RE::GFxValue_const_&,bool),RE::GFxValue::ObjectInterface_*,void_*_&,char_const_*_&,RE::GFxValue_const_&,bool_&>
            (local_18,&local_res8,&local_res10,local_res18,param_4);
  return;
}


/* ---- 0x180044f50  FUN_180044f50  (138 bytes) ---- */

void FUN_180044f50(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  ulonglong local_18 [3];
  
  local_18[0] = 0x13969;
  local_18[1] = 0x14150;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  lVar1 = FUN_18000f860(local_18);
  local_18[0] = FUN_180047650(lVar1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,RE::GFxValue_*,char_const_*,RE::GFxValue_const_*,unsigned___int64,bool),RE::GFxValue::ObjectInterface_*,void_*_&,RE::GFxValue_*_&,char_const_*_&,RE::GFxValue_const_*_&,unsigned___int64_&,bool_&>
            (local_18,&local_res8,&local_res10,&local_res18,&local_res20,
             (undefined8 *)&stack0x00000028,(undefined8 *)&stack0x00000030,&stack0x00000038);
  return;
}


/* ---- 0x180044fe0  FUN_180044fe0  (99 bytes) ---- */

void FUN_180044fe0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4)

{
  longlong lVar1;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined8 uStackX_18;
  undefined1 auStackX_20 [8];
  ulonglong auStack_18 [3];
  
  auStack_18[0] = 0x1394f;
  auStack_18[1] = 0x14136;
  uStackX_8 = param_1;
  uStackX_10 = param_2;
  uStackX_18 = param_3;
  auStackX_20[0] = param_4;
  lVar1 = FUN_18000f860(auStack_18);
  auStack_18[0] = FUN_180047640(lVar1);
  FUN_180046d50(auStack_18,&uStackX_8,&uStackX_10,&uStackX_18,auStackX_20);
  return;
}


/* ---- 0x180045050  FUN_180045050  (101 bytes) ---- */

void FUN_180045050(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined1 local_res20 [8];
  ulonglong local_18 [3];
  
  local_18[0] = 0x13997;
  local_18[1] = 0x1417e;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20[0] = param_4;
  lVar1 = FUN_18000f860(local_18);
  local_18[0] = FUN_180047630(lVar1);
  FUN_180046da0(local_18,&local_res8,&local_res10,&local_res18,local_res20);
  return;
}


/* ---- 0x1800450c0  FUN_1800450c0  (74 bytes) ---- */

void FUN_1800450c0(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  ulonglong local_18 [3];
  
  local_18[0] = 0x13956;
  local_18[1] = 0x1413d;
  local_res8 = param_1;
  local_res10 = param_2;
  lVar1 = FUN_18000f860(local_18);
  local_res18[0] = FUN_180047620(lVar1);
  FUN_180046de0(local_res18,&local_res8,&local_res10);
  return;
}


/* ---- 0x180045240  FUN_180045240  (111 bytes) ---- */

void FUN_180045240(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined4 local_res20 [2];
  ulonglong local_18 [3];
  
  local_18[0] = 0x13996;
  local_18[1] = 0x1417d;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20[0] = param_4;
  lVar1 = FUN_18000f860(local_18);
  local_18[0] = FUN_1800475e0(lVar1);
  REL::
  invoke<void_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,RE::GFxValue::ObjectInterface::ArrVisitor_*,unsigned_int,RE::GFxValue_const_&)const_,RE::GFxValue::ObjectInterface_const_*,void_*_&,RE::GFxValue::ObjectInterface::ArrVisitor_*_&,unsigned_int_&,RE::GFxValue_const_&>
            (local_18,&local_res8,&local_res10,&local_res18,local_res20);
  return;
}


/* ---- 0x1800452b0  FUN_1800452b0  (82 bytes) ---- */

void FUN_1800452b0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10 [2];
  undefined8 local_res20;
  ulonglong local_18 [2];
  
  local_18[0] = 0x13978;
  local_18[1] = 0x14161;
  local_res8 = param_1;
  local_res10[0] = param_2;
  lVar1 = FUN_18000f860(local_18);
  local_res20 = FUN_1800475d0(lVar1);
  FUN_180046ee0(&local_res20,&local_res8,local_res10,param_3);
  return;
}


/* ---- 0x180045380  FUN_180045380  (84 bytes) ---- */

void FUN_180045380(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  ulonglong local_18 [3];
  
  local_18[0] = 0x13958;
  local_18[1] = 0x1413f;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  lVar1 = FUN_18000f860(local_18);
  local_res20 = FUN_1800475b0(lVar1);
  FUN_180046f50(&local_res20,&local_res8,&local_res10,&local_res18);
  return;
}


/* ---- 0x1800453e0  FUN_1800453e0  (82 bytes) ---- */

void FUN_1800453e0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10 [2];
  undefined8 local_res20;
  ulonglong local_18 [2];
  
  local_18[0] = 0x13987;
  local_18[1] = 0x1416f;
  local_res8 = param_1;
  local_res10[0] = param_2;
  lVar1 = FUN_18000f860(local_18);
  local_res20 = FUN_1800475a0(lVar1);
  FUN_180046f90(&local_res20,&local_res8,local_res10,param_3);
  return;
}


/* ---- 0x180045520  FUN_180045520  (138 bytes) ---- */

void FUN_180045520(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  ulonglong local_18 [3];
  
  local_18[0] = 0x13945;
  local_18[1] = 0x1412b;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  lVar1 = FUN_18000f860(local_18);
  local_18[0] = FUN_180047580(lVar1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,RE::GFxValue_*,char_const_*,char_const_*,int,RE::GFxValue_const_*),RE::GFxValue::ObjectInterface_*,void_*_&,RE::GFxValue_*_&,char_const_*_&,char_const_*_&,int_&,RE::GFxValue_const_*_&>
            (local_18,&local_res8,&local_res10,&local_res18,&local_res20,
             (undefined8 *)&stack0x00000028,(undefined4 *)&stack0x00000030,
             (undefined8 *)&stack0x00000038);
  return;
}


/* ---- 0x180045620  FUN_180045620  (101 bytes) ---- */

void FUN_180045620(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined1 param_4)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined4 local_res18 [2];
  undefined1 local_res20 [8];
  ulonglong local_18 [3];
  
  local_18[0] = 0x13965;
  local_18[1] = 0x1414c;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18[0] = param_3;
  local_res20[0] = param_4;
  lVar1 = FUN_18000f860(local_18);
  local_18[0] = FUN_180047570(lVar1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,unsigned_int,bool),RE::GFxValue::ObjectInterface_*,void_*_&,unsigned_int_&,bool_&>
            (local_18,&local_res8,&local_res10,local_res18,local_res20);
  return;
}


/* ---- 0x180045690  FUN_180045690  (10 bytes) ---- */

undefined8 FUN_180045690(longlong *param_1,longlong *param_2)

{
  return CONCAT71((int7)((ulonglong)*param_2 >> 8),*param_1 == *param_2);
}


/* ---- 0x1800456a0  FUN_1800456a0  (88 bytes) ---- */

void FUN_1800456a0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10 [2];
  undefined8 local_res20;
  ulonglong local_18 [2];
  
  local_18[0] = 0x13993;
  local_18[1] = 0x1417a;
  local_res8 = param_1;
  local_res10[0] = param_2;
  lVar1 = FUN_18000f860(local_18);
  local_res20 = FUN_180047560(lVar1);
  FUN_1800470d0(&local_res20,&local_res8,local_res10,param_3);
  return;
}


/* ---- 0x180045700  FUN_180045700  (17 bytes) ---- */

undefined8 * FUN_180045700(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}


/* ---- 0x180045720  FUN_180045720  (19 bytes) ---- */

undefined8 * FUN_180045720(undefined8 *param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 1) = param_2;
  *param_1 = 0;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  param_1[2] = 0;
  return param_1;
}


/* ---- 0x1800457d0  FUN_1800457d0  (24 bytes) ---- */

undefined8 * FUN_1800457d0(undefined8 *param_1,undefined8 *param_2)

{
  param_1[1] = 4;
  *param_1 = 0;
  param_1[2] = *param_2;
  return param_1;
}


/* ---- 0x1800457f0  FUN_1800457f0  (21 bytes) ---- */

undefined8 * FUN_1800457f0(undefined8 *param_1,undefined8 param_2)

{
  param_1[1] = 5;
  *param_1 = 0;
  param_1[2] = param_2;
  return param_1;
}


/* ---- 0x180045810  FUN_180045810  (24 bytes) ---- */

undefined8 * FUN_180045810(undefined8 *param_1,undefined8 *param_2)

{
  param_1[1] = 5;
  *param_1 = 0;
  param_1[2] = *param_2;
  return param_1;
}


/* ---- 0x1800458e0  FUN_1800458e0  (23 bytes) ---- */

undefined8 * FUN_1800458e0(undefined8 *param_1,double param_2)

{
  RE::GFxValue::SetNumber(param_1,param_2);
  return param_1;
}


/* ---- 0x180045920  FUN_180045920  (23 bytes) ---- */

undefined8 * FUN_180045920(undefined8 *param_1,char *param_2)

{
  RE::GFxValue::SetString(param_1,param_2);
  return param_1;
}


/* ---- 0x180045940  FUN_180045940  (36 bytes) ---- */

undefined8 * FUN_180045940(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = *param_2;
  uStack_10 = param_2[1];
  FUN_180045ed0(param_1,&local_18);
  return param_1;
}


/* ---- 0x180045970  FUN_180045970  (23 bytes) ---- */

undefined8 * FUN_180045970(undefined8 *param_1,wchar_t *param_2)

{
  RE::GFxValue::SetStringW(param_1,param_2);
  return param_1;
}


/* ---- 0x180045990  FUN_180045990  (36 bytes) ---- */

undefined8 * FUN_180045990(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = *param_2;
  uStack_10 = param_2[1];
  FUN_180045f10(param_1,&local_18);
  return param_1;
}


/* ---- 0x180045b20  FUN_180045b20  (224 bytes) ---- */

ulonglong * FUN_180045b20(undefined8 param_1,ulonglong *param_2)

{
  longlong lVar1;
  undefined *puVar2;
  IDDatabase *pIVar3;
  ulong64 uVar4;
  ulong64 uVar5;
  ulonglong uVar6;
  ulonglong *local_res8;
  ulonglong *local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar5 = 0;
  local_res10 = param_2;
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    uVar6 = 0x14179;
  }
  else {
    if (puVar2[0x118] != '\x02') goto LAB_180045bb9;
    uVar6 = 0x13992;
  }
  pIVar3 = (IDDatabase *)REL::IDDatabase::get();
  uVar4 = REL::IDDatabase::id2offset(pIVar3,uVar6);
  if (uVar4 == 0) goto LAB_180045bb9;
  puVar2 = REL::Module::get();
  lVar1 = *(longlong *)(puVar2 + 0x110);
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    pIVar3 = (IDDatabase *)REL::IDDatabase::get();
    uVar6 = 0x14179;
LAB_180045bab:
    uVar5 = REL::IDDatabase::id2offset(pIVar3,uVar6);
  }
  else if (puVar2[0x118] == '\x02') {
    pIVar3 = (IDDatabase *)REL::IDDatabase::get();
    uVar6 = 0x13992;
    goto LAB_180045bab;
  }
  uVar5 = uVar5 + lVar1;
LAB_180045bb9:
  RE::GString::GString((GString *)param_2);
  local_res8 = param_2;
  local_res18 = param_1;
  local_res20 = FUN_180047550(uVar5);
  FUN_180047120(&local_res20,&local_res18,&local_res8);
  return param_2;
}


/* ---- 0x180045d50  FUN_180045d50  (5 bytes) ---- */

undefined1 FUN_180045d50(longlong param_1)

{
  return *(undefined1 *)(param_1 + 0x10);
}


/* ---- 0x180045e00  FUN_180045e00  (25 bytes) ---- */

undefined8 * FUN_180045e00(longlong param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  
  uVar1 = RE::GFxValue::IsManagedValue((void *)param_1);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  if ((char)uVar1 != '\0') {
    puVar2 = (undefined8 *)*puVar2;
  }
  return puVar2;
}


/* ---- 0x180045e20  FUN_180045e20  (7 bytes) ---- */

void FUN_180045e20(void *param_1)

{
  uint uVar1;
  void *this;
  
  this = param_1;
  uVar1 = RE::GFxValue::IsManagedValue(param_1);
  if ((char)uVar1 != '\0') {
    RE::GFxValue::ReleaseManagedValue(this);
    *(undefined4 *)((longlong)param_1 + 8) = 0;
    return;
  }
  *(undefined4 *)((longlong)this + 8) = 0;
  return;
}


/* ---- 0x180045ed0  FUN_180045ed0  (8 bytes) ---- */

void FUN_180045ed0(undefined8 *param_1,undefined8 *param_2)

{
  RE::GFxValue::SetString(param_1,(char *)*param_2);
  return;
}


/* ---- 0x180045f10  FUN_180045f10  (8 bytes) ---- */

void FUN_180045f10(undefined8 *param_1,undefined8 *param_2)

{
  RE::GFxValue::SetStringW(param_1,(wchar_t *)*param_2);
  return;
}


/* ---- 0x180045f20  FUN_180045f20  (10 bytes) ---- */

void FUN_180045f20(void *param_1)

{
  uint uVar1;
  void *this;
  
  this = param_1;
  uVar1 = RE::GFxValue::IsManagedValue(param_1);
  if ((char)uVar1 != '\0') {
    RE::GFxValue::ReleaseManagedValue(this);
    *(undefined4 *)((longlong)param_1 + 8) = 0x82;
    return;
  }
  *(undefined4 *)((longlong)this + 8) = 0x82;
  return;
}


/* ---- 0x180045f30  FUN_180045f30  (10 bytes) ---- */

void FUN_180045f30(void *param_1)

{
  uint uVar1;
  void *this;
  
  this = param_1;
  uVar1 = RE::GFxValue::IsManagedValue(param_1);
  if ((char)uVar1 != '\0') {
    RE::GFxValue::ReleaseManagedValue(this);
    *(undefined4 *)((longlong)param_1 + 8) = 0x83;
    return;
  }
  *(undefined4 *)((longlong)this + 8) = 0x83;
  return;
}


/* ---- 0x180045f40  FUN_180045f40  (10 bytes) ---- */

void FUN_180045f40(void *param_1)

{
  uint uVar1;
  void *this;
  
  this = param_1;
  uVar1 = RE::GFxValue::IsManagedValue(param_1);
  if ((char)uVar1 != '\0') {
    RE::GFxValue::ReleaseManagedValue(this);
    *(undefined4 *)((longlong)param_1 + 8) = 0x84;
    return;
  }
  *(undefined4 *)((longlong)this + 8) = 0x84;
  return;
}


/* ---- 0x180045f50  FUN_180045f50  (10 bytes) ---- */

void FUN_180045f50(void *param_1)

{
  uint uVar1;
  void *this;
  
  this = param_1;
  uVar1 = RE::GFxValue::IsManagedValue(param_1);
  if ((char)uVar1 != '\0') {
    RE::GFxValue::ReleaseManagedValue(this);
    *(undefined4 *)((longlong)param_1 + 8) = 0x85;
    return;
  }
  *(undefined4 *)((longlong)this + 8) = 0x85;
  return;
}


/* ---- 0x180045f60  FUN_180045f60  (32 bytes) ---- */

void FUN_180045f60(undefined8 *param_1,undefined8 param_2)

{
  bool bVar1;
  
  bVar1 = RE::GFxValue::IsDisplayObject(param_1);
  FUN_180044e00(*param_1,param_1[2],param_2,bVar1);
  return;
}


/* ---- 0x180045f80  FUN_180045f80  (36 bytes) ---- */

void FUN_180045f80(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  RE::GFxValue::IsDisplayObject(param_1);
  FUN_180044e70(*param_1,param_1[2],param_2,param_3);
  return;
}


/* ---- 0x180045fb0  FUN_180045fb0  (36 bytes) ---- */

void FUN_180045fb0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  RE::GFxValue::IsDisplayObject(param_1);
  FUN_180044ee0(*param_1,param_1[2],param_2,param_3);
  return;
}


/* ---- 0x180046030  FUN_180046030  (32 bytes) ---- */

void FUN_180046030(undefined8 *param_1,undefined8 param_2)

{
  bool bVar1;
  
  bVar1 = RE::GFxValue::IsDisplayObject(param_1);
  FUN_180045050(*param_1,param_1[2],param_2,bVar1);
  return;
}


/* ---- 0x180046080  FUN_180046080  (99 bytes) ---- */

void FUN_180046080(undefined8 *param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined4 auStackX_18 [2];
  undefined8 uStackX_20;
  ulonglong auStack_18 [3];
  
  uStackX_10 = param_1[2];
  uStackX_8 = *param_1;
  auStack_18[0] = 0x13985;
  auStack_18[1] = 0x1416d;
  auStackX_18[0] = param_2;
  lVar1 = FUN_18000f860(auStack_18);
  uStackX_20 = FUN_180047610(lVar1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,unsigned_int),RE::GFxValue::ObjectInterface_*,void_*_&,unsigned_int_&>
            (&uStackX_20,&uStackX_8,&uStackX_10,auStackX_18);
  return;
}


/* ---- 0x180046090  FUN_180046090  (117 bytes) ---- */

void FUN_180046090(undefined8 *param_1,undefined4 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined4 auStackX_18 [2];
  undefined8 uStackX_20;
  ulonglong auStack_18 [3];
  
  uStackX_10 = param_1[2];
  uStackX_8 = *param_1;
  auStack_18[0] = 0x1395a;
  auStack_18[1] = 0x14141;
  auStackX_18[0] = param_2;
  uStackX_20 = param_3;
  lVar1 = FUN_18000f860(auStack_18);
  auStack_18[0] = FUN_180047600(lVar1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,unsigned_int,RE::GFxValue_*)const_,RE::GFxValue::ObjectInterface_const_*,void_*_&,unsigned_int_&,RE::GFxValue_*_&>
            (auStack_18,&uStackX_8,&uStackX_10,auStackX_18,&uStackX_20);
  return;
}


/* ---- 0x1800460b0  FUN_1800460b0  (112 bytes) ---- */

void FUN_1800460b0(undefined8 *param_1,undefined4 param_2,GFxValue *param_3)

{
  longlong lVar1;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined4 auStackX_18 [4];
  ulonglong auStack_18 [2];
  
  uStackX_10 = param_1[2];
  uStackX_8 = *param_1;
  auStack_18[0] = 0x13989;
  auStack_18[1] = 0x14171;
  auStackX_18[0] = param_2;
  lVar1 = FUN_18000f860(auStack_18);
  auStack_18[0] = FUN_1800475f0(lVar1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,unsigned_int,RE::GFxValue_const_&),RE::GFxValue::ObjectInterface_*,void_*_&,unsigned_int_&,RE::GFxValue_const_&>
            (auStack_18,&uStackX_8,&uStackX_10,auStackX_18,param_3);
  return;
}


/* ---- 0x180046140  FUN_180046140  (117 bytes) ---- */

void FUN_180046140(undefined8 *param_1,undefined4 param_2,undefined4 param_3)

{
  longlong lVar1;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined4 auStackX_18 [2];
  undefined4 auStackX_20 [2];
  ulonglong auStack_18 [3];
  
  uStackX_10 = param_1[2];
  uStackX_8 = *param_1;
  auStack_18[0] = 0x1397c;
  auStack_18[1] = 0x14168;
  auStackX_18[0] = param_2;
  auStackX_20[0] = param_3;
  lVar1 = FUN_18000f860(auStack_18);
  auStack_18[0] = FUN_1800475c0(lVar1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,unsigned_int,int),RE::GFxValue::ObjectInterface_*,void_*_&,unsigned_int_&,int_&>
            (auStack_18,&uStackX_8,&uStackX_10,auStackX_18,auStackX_20);
  return;
}


/* ---- 0x180046160  FUN_180046160  (11 bytes) ---- */

void FUN_180046160(undefined8 *param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined4 auStackX_18 [2];
  undefined4 auStackX_20 [2];
  ulonglong auStack_18 [3];
  
  uStackX_10 = param_1[2];
  uStackX_8 = *param_1;
  auStackX_20[0] = 1;
  auStack_18[0] = 0x1397c;
  auStack_18[1] = 0x14168;
  auStackX_18[0] = param_2;
  lVar1 = FUN_18000f860(auStack_18);
  auStack_18[0] = FUN_1800475c0(lVar1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,unsigned_int,int),RE::GFxValue::ObjectInterface_*,void_*_&,unsigned_int_&,int_&>
            (auStack_18,&uStackX_8,&uStackX_10,auStackX_18,auStackX_20);
  return;
}


/* ---- 0x180046170  FUN_180046170  (13 bytes) ---- */

void FUN_180046170(undefined8 *param_1)

{
  longlong lVar1;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined4 auStackX_18 [2];
  undefined4 auStackX_20 [2];
  ulonglong auStack_18 [3];
  
  uStackX_10 = param_1[2];
  uStackX_8 = *param_1;
  auStackX_20[0] = 0xffffffff;
  auStackX_18[0] = 0;
  auStack_18[0] = 0x1397c;
  auStack_18[1] = 0x14168;
  lVar1 = FUN_18000f860(auStack_18);
  auStack_18[0] = FUN_1800475c0(lVar1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,unsigned_int,int),RE::GFxValue::ObjectInterface_*,void_*_&,unsigned_int_&,int_&>
            (auStack_18,&uStackX_8,&uStackX_10,auStackX_18,auStackX_20);
  return;
}


/* ---- 0x180046180  FUN_180046180  (15 bytes) ---- */

void FUN_180046180(undefined8 *param_1,undefined8 param_2)

{
  FUN_180045380(*param_1,param_1[2],param_2);
  return;
}


/* ---- 0x180046190  FUN_180046190  (15 bytes) ---- */

void FUN_180046190(undefined8 *param_1,undefined8 param_2)

{
  FUN_1800453e0(*param_1,param_1[2],param_2);
  return;
}


/* ---- 0x1800461a0  FUN_1800461a0  (117 bytes) ---- */

void FUN_1800461a0(undefined8 *param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined8 uStackX_18;
  undefined1 auStackX_20 [8];
  ulonglong auStack_18 [3];
  
  uStackX_10 = param_1[2];
  uStackX_8 = *param_1;
  auStackX_20[0] = 0;
  auStack_18[0] = 0x1398e;
  auStack_18[1] = 0x14175;
  uStackX_18 = param_2;
  lVar1 = FUN_18000f860(auStack_18);
  auStack_18[0] = FUN_180047640(lVar1);
  FUN_180046d50(auStack_18,&uStackX_8,&uStackX_10,&uStackX_18,auStackX_20);
  return;
}


/* ---- 0x1800461c0  FUN_1800461c0  (18 bytes) ---- */

void FUN_1800461c0(undefined8 *param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined8 uStackX_18;
  undefined1 auStackX_20 [8];
  ulonglong auStack_18 [3];
  
  uStackX_10 = param_1[2];
  uStackX_8 = *param_1;
  auStackX_20[0] = 1;
  auStack_18[0] = 0x1398e;
  auStack_18[1] = 0x14175;
  uStackX_18 = param_2;
  lVar1 = FUN_18000f860(auStack_18);
  auStack_18[0] = FUN_180047640(lVar1);
  FUN_180046d50(auStack_18,&uStackX_8,&uStackX_10,&uStackX_18,auStackX_20);
  return;
}


/* ---- 0x180046200  FUN_180046200  (50 bytes) ---- */

void FUN_180046200(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_180045520(*param_1,param_1[2],param_2,param_3);
  return;
}


/* ---- 0x180046240  FUN_180046240  (117 bytes) ---- */

void FUN_180046240(undefined8 *param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined8 uStackX_18;
  undefined1 auStackX_20 [8];
  ulonglong auStack_18 [3];
  
  uStackX_10 = param_1[2];
  uStackX_8 = *param_1;
  auStackX_20[0] = 0;
  auStack_18[0] = 0x13966;
  auStack_18[1] = 0x1414d;
  uStackX_18 = param_2;
  lVar1 = FUN_18000f860(auStack_18);
  auStack_18[0] = FUN_180047640(lVar1);
  FUN_180046d50(auStack_18,&uStackX_8,&uStackX_10,&uStackX_18,auStackX_20);
  return;
}


/* ---- 0x180046260  FUN_180046260  (18 bytes) ---- */

void FUN_180046260(undefined8 *param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined8 uStackX_18;
  undefined1 auStackX_20 [8];
  ulonglong auStack_18 [3];
  
  uStackX_10 = param_1[2];
  uStackX_8 = *param_1;
  auStackX_20[0] = 1;
  auStack_18[0] = 0x13966;
  auStack_18[1] = 0x1414d;
  uStackX_18 = param_2;
  lVar1 = FUN_18000f860(auStack_18);
  auStack_18[0] = FUN_180047640(lVar1);
  FUN_180046d50(auStack_18,&uStackX_8,&uStackX_10,&uStackX_18,auStackX_20);
  return;
}


/* ---- 0x180046280  FUN_180046280  (18 bytes) ---- */

void FUN_180046280(undefined8 *param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined4 auStackX_18 [2];
  undefined1 auStackX_20 [8];
  ulonglong auStack_18 [3];
  
  uStackX_10 = param_1[2];
  uStackX_8 = *param_1;
  auStackX_20[0] = 0;
  auStack_18[0] = 0x13965;
  auStack_18[1] = 0x1414c;
  auStackX_18[0] = param_2;
  lVar1 = FUN_18000f860(auStack_18);
  auStack_18[0] = FUN_180047570(lVar1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,unsigned_int,bool),RE::GFxValue::ObjectInterface_*,void_*_&,unsigned_int_&,bool_&>
            (auStack_18,&uStackX_8,&uStackX_10,auStackX_18,auStackX_20);
  return;
}


/* ---- 0x1800462a0  FUN_1800462a0  (18 bytes) ---- */

void FUN_1800462a0(undefined8 *param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined4 auStackX_18 [2];
  undefined1 auStackX_20 [8];
  ulonglong auStack_18 [3];
  
  uStackX_10 = param_1[2];
  uStackX_8 = *param_1;
  auStackX_20[0] = 1;
  auStack_18[0] = 0x13965;
  auStack_18[1] = 0x1414c;
  auStackX_18[0] = param_2;
  lVar1 = FUN_18000f860(auStack_18);
  auStack_18[0] = FUN_180047570(lVar1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,unsigned_int,bool),RE::GFxValue::ObjectInterface_*,void_*_&,unsigned_int_&,bool_&>
            (auStack_18,&uStackX_8,&uStackX_10,auStackX_18,auStackX_20);
  return;
}


/* ---- 0x180046360  FUN_180046360  (7 bytes) ---- */

undefined2 * FUN_180046360(undefined2 *param_1,undefined2 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180046370  FUN_180046370  (9 bytes) ---- */

undefined2 * FUN_180046370(undefined2 *param_1)

{
  *param_1 = 3;
  return param_1;
}


/* ---- 0x180046380  FUN_180046380  (17 bytes) ---- */

undefined2 FUN_180046380(ushort *param_1,ushort param_2)

{
  return CONCAT11((char)((*param_1 & param_2) >> 8),(*param_1 & param_2) == param_2);
}


/* ---- 0x1800463a0  FUN_1800463a0  (7 bytes) ---- */

ushort * FUN_1800463a0(ushort *param_1,ushort param_2)

{
  *param_1 = *param_1 | param_2;
  return param_1;
}


/* ---- 0x1800463b0  FUN_1800463b0  (8 bytes) ---- */

ushort * FUN_1800463b0(ushort *param_1)

{
  *param_1 = *param_1 | 0x7f;
  return param_1;
}


/* ---- 0x1800463c0  FUN_1800463c0  (12 bytes) ---- */

ushort * FUN_1800463c0(ushort *param_1)

{
  *param_1 = *param_1 | 0x7ff;
  return param_1;
}


/* ---- 0x1800463d0  FUN_1800463d0  (12 bytes) ---- */

ushort * FUN_1800463d0(ushort *param_1,ushort param_2,ushort param_3)

{
  *param_1 = *param_1 | param_3 | param_2;
  return param_1;
}


/* ---- 0x1800463e0  FUN_1800463e0  (10 bytes) ---- */

ushort * FUN_1800463e0(ushort *param_1,ushort param_2)

{
  *param_1 = *param_1 & ~param_2;
  return param_1;
}


/* ---- 0x1800463f0  FUN_1800463f0  (32 bytes) ---- */

void FUN_1800463f0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = FUN_180047690(*param_1);
  FUN_180046ba0(local_res8,param_2,param_3,param_4);
  return;
}


/* ---- 0x180046410  FUN_180046410  (42 bytes) ---- */

void FUN_180046410(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined1 *param_5)

{
  undefined8 auStackX_8 [4];
  
  auStackX_8[0] = FUN_180047680(*param_1);
  FUN_180046be0(auStackX_8,param_2,param_3,param_4,param_5);
  return;
}


/* ---- 0x180046510  FUN_180046510  (42 bytes) ---- */

void FUN_180046510(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined1 *param_5)

{
  undefined8 auStackX_8 [4];
  
  auStackX_8[0] = FUN_180047640(*param_1);
  FUN_180046d50(auStackX_8,param_2,param_3,param_4,param_5);
  return;
}


/* ---- 0x180046570  FUN_180046570  (32 bytes) ---- */

void FUN_180046570(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = FUN_180047620(*param_1);
  FUN_180046de0(local_res8,param_2,param_3);
  return;
}


/* ---- 0x180046590  FUN_180046590  (32 bytes) ---- */

void FUN_180046590(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4)

{
  undefined8 auStackX_8 [4];
  
  auStackX_8[0] = FUN_180047610(*param_1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,unsigned_int),RE::GFxValue::ObjectInterface_*,void_*_&,unsigned_int_&>
            (auStackX_8,param_2,param_3,param_4);
  return;
}


/* ---- 0x1800465b0  FUN_1800465b0  (42 bytes) ---- */

void FUN_1800465b0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4,
                  undefined8 *param_5)

{
  undefined8 auStackX_8 [4];
  
  auStackX_8[0] = FUN_180047600(*param_1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,unsigned_int,RE::GFxValue_*)const_,RE::GFxValue::ObjectInterface_const_*,void_*_&,unsigned_int_&,RE::GFxValue_*_&>
            (auStackX_8,param_2,param_3,param_4,param_5);
  return;
}


/* ---- 0x180046650  FUN_180046650  (32 bytes) ---- */

void FUN_180046650(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = FUN_1800475d0(*param_1);
  FUN_180046ee0(local_res8,param_2,param_3,param_4);
  return;
}


/* ---- 0x180046670  FUN_180046670  (42 bytes) ---- */

void FUN_180046670(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4,
                  undefined4 *param_5)

{
  undefined8 auStackX_8 [4];
  
  auStackX_8[0] = FUN_1800475c0(*param_1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,unsigned_int,int),RE::GFxValue::ObjectInterface_*,void_*_&,unsigned_int_&,int_&>
            (auStackX_8,param_2,param_3,param_4,param_5);
  return;
}


/* ---- 0x1800466a0  FUN_1800466a0  (32 bytes) ---- */

void FUN_1800466a0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = FUN_1800475b0(*param_1);
  FUN_180046f50(local_res8,param_2,param_3,param_4);
  return;
}


/* ---- 0x1800466c0  FUN_1800466c0  (32 bytes) ---- */

void FUN_1800466c0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4)

{
  undefined8 auStackX_8 [4];
  
  auStackX_8[0] = FUN_1800475a0(*param_1);
  FUN_180046f90(auStackX_8,param_2,param_3,param_4);
  return;
}


/* ---- 0x1800466e0  FUN_1800466e0  (52 bytes) ---- */

void FUN_1800466e0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined8 *param_5)

{
  undefined8 auStackX_8 [4];
  
  auStackX_8[0] = FUN_180047590(*param_1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,RE::GFxValue_*,char_const_*,int),RE::GFxValue::ObjectInterface_*,void_*_&,RE::GFxValue_*_&,char_const_*_&,int_&>
            (auStackX_8,param_2,param_3,param_4,param_5);
  return;
}


/* ---- 0x180046770  FUN_180046770  (42 bytes) ---- */

void FUN_180046770(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4,
                  undefined1 *param_5)

{
  undefined8 auStackX_8 [4];
  
  auStackX_8[0] = FUN_180047570(*param_1);
  REL::
  invoke<bool_(__cdecl_RE::GFxValue::ObjectInterface::*)(void_*,unsigned_int,bool),RE::GFxValue::ObjectInterface_*,void_*_&,unsigned_int_&,bool_&>
            (auStackX_8,param_2,param_3,param_4,param_5);
  return;
}


/* ---- 0x1800467a0  FUN_1800467a0  (32 bytes) ---- */

void FUN_1800467a0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = FUN_180047560(*param_1);
  FUN_1800470d0(local_res8,param_2,param_3,param_4);
  return;
}


/* ---- 0x1800467c0  FUN_1800467c0  (6 bytes) ---- */

undefined4 * FUN_1800467c0(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800467d0  FUN_1800467d0  (4 bytes) ---- */

undefined8 FUN_1800467d0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800467e0  FUN_1800467e0  (4 bytes) ---- */

undefined8 FUN_1800467e0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800467f0  FUN_1800467f0  (4 bytes) ---- */

undefined8 FUN_1800467f0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180046800  FUN_180046800  (4 bytes) ---- */

undefined8 FUN_180046800(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180046810  FUN_180046810  (32 bytes) ---- */

void FUN_180046810(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = FUN_180047550(*param_1);
  FUN_180047120(local_res8,param_2,param_3);
  return;
}


/* ---- 0x180046830  FUN_180046830  (25 bytes) ---- */

void * FUN_180046830(void *param_1)

{
  RE::GFxValue::GFxValue(param_1,-1.0);
  return param_1;
}


/* ---- 0x180046850  FUN_180046850  (8 bytes) ---- */

uint FUN_180046850(uint *param_1)

{
  return *param_1 >> 6 & 0xffffff01;
}


/* ---- 0x180046860  FUN_180046860  (29 bytes) ---- */

longlong * FUN_180046860(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18003c390(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046880  FUN_180046880  (29 bytes) ---- */

longlong * FUN_180046880(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x1800468a0  FUN_1800468a0  (29 bytes) ---- */

longlong * FUN_1800468a0(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x1800468c0  FUN_1800468c0  (29 bytes) ---- */

longlong * FUN_1800468c0(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x1800468e0  FUN_1800468e0  (29 bytes) ---- */

longlong * FUN_1800468e0(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046900  FUN_180046900  (29 bytes) ---- */

longlong * FUN_180046900(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046920  FUN_180046920  (29 bytes) ---- */

longlong * FUN_180046920(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046940  FUN_180046940  (29 bytes) ---- */

longlong * FUN_180046940(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046960  FUN_180046960  (29 bytes) ---- */

longlong * FUN_180046960(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046980  FUN_180046980  (29 bytes) ---- */

longlong * FUN_180046980(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x1800469a0  FUN_1800469a0  (29 bytes) ---- */

longlong * FUN_1800469a0(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x1800469c0  FUN_1800469c0  (29 bytes) ---- */

longlong * FUN_1800469c0(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x1800469e0  FUN_1800469e0  (29 bytes) ---- */

longlong * FUN_1800469e0(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046a00  FUN_180046a00  (29 bytes) ---- */

longlong * FUN_180046a00(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046a20  FUN_180046a20  (29 bytes) ---- */

longlong * FUN_180046a20(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046a40  FUN_180046a40  (29 bytes) ---- */

longlong * FUN_180046a40(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046a60  FUN_180046a60  (29 bytes) ---- */

longlong * FUN_180046a60(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046a80  FUN_180046a80  (29 bytes) ---- */

longlong * FUN_180046a80(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046aa0  FUN_180046aa0  (29 bytes) ---- */

longlong * FUN_180046aa0(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046ac0  FUN_180046ac0  (29 bytes) ---- */

longlong * FUN_180046ac0(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046ae0  FUN_180046ae0  (29 bytes) ---- */

longlong * FUN_180046ae0(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180046b00  FUN_180046b00  (9 bytes) ---- */

uint * FUN_180046b00(uint *param_1,uint param_2,uint param_3)

{
  *param_1 = param_2 & param_3;
  return param_1;
}


/* ---- 0x180046b10  FUN_180046b10  (6 bytes) ---- */

bool FUN_180046b10(int param_1,int param_2)

{
  return param_1 == param_2;
}


/* ---- 0x180046b30  FUN_180046b30  (6 bytes) ---- */

undefined4 * FUN_180046b30(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180046b40  FUN_180046b40  (7 bytes) ---- */

undefined2 * FUN_180046b40(undefined2 *param_1,undefined2 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180046b50  FUN_180046b50  (7 bytes) ---- */

undefined2 * FUN_180046b50(undefined2 *param_1,undefined2 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180046b60  FUN_180046b60  (9 bytes) ---- */

undefined2 * FUN_180046b60(undefined2 *param_1)

{
  *param_1 = 3;
  return param_1;
}


/* ---- 0x180046b70  FUN_180046b70  (6 bytes) ---- */

undefined4 * FUN_180046b70(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180046b80  FUN_180046b80  (4 bytes) ---- */

undefined8 FUN_180046b80(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180046b90  FUN_180046b90  (4 bytes) ---- */

undefined8 FUN_180046b90(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180046ba0  FUN_180046ba0  (34 bytes) ---- */

void FUN_180046ba0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_1800472c0(*param_1);
                    /* WARNING: Could not recover jumptable at 0x000180046bbf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*param_2,*param_3,*param_4);
  return;
}


/* ---- 0x180046bd0  FUN_180046bd0  (4 bytes) ---- */

undefined8 FUN_180046bd0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180046be0  FUN_180046be0  (49 bytes) ---- */

void FUN_180046be0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined1 *param_5)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_1800472e0(*param_1);
                    /* WARNING: Could not recover jumptable at 0x000180046c0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*param_2,*param_3,*param_4,*param_5);
  return;
}


/* ---- 0x180046c70  FUN_180046c70  (4 bytes) ---- */

undefined8 FUN_180046c70(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180046cd0  FUN_180046cd0  (4 bytes) ---- */

undefined8 FUN_180046cd0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180046d50  FUN_180046d50  (49 bytes) ---- */

void FUN_180046d50(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined1 *param_5)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_180047360(*param_1);
                    /* WARNING: Could not recover jumptable at 0x000180046d7e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*param_2,*param_3,*param_4,*param_5);
  return;
}


/* ---- 0x180046d90  FUN_180046d90  (4 bytes) ---- */

undefined8 FUN_180046d90(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180046da0  FUN_180046da0  (49 bytes) ---- */

void FUN_180046da0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined1 *param_5)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_180047380(*param_1);
                    /* WARNING: Could not recover jumptable at 0x000180046dce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*param_2,*param_3,*param_4,*param_5);
  return;
}


/* ---- 0x180046de0  FUN_180046de0  (28 bytes) ---- */

void FUN_180046de0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_1800473a0(*param_1);
                    /* WARNING: Could not recover jumptable at 0x000180046df9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*param_2,*param_3);
  return;
}


/* ---- 0x180046e90  FUN_180046e90  (4 bytes) ---- */

undefined8 FUN_180046e90(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180046ee0  FUN_180046ee0  (34 bytes) ---- */

void FUN_180046ee0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_180047440(*param_1);
                    /* WARNING: Could not recover jumptable at 0x000180046eff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*param_2,*param_3,param_4);
  return;
}


/* ---- 0x180046f40  FUN_180046f40  (4 bytes) ---- */

undefined8 FUN_180046f40(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180046f50  FUN_180046f50  (34 bytes) ---- */

void FUN_180046f50(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_180047480(*param_1);
                    /* WARNING: Could not recover jumptable at 0x000180046f6f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*param_2,*param_3,*param_4);
  return;
}


/* ---- 0x180046f80  FUN_180046f80  (4 bytes) ---- */

undefined8 FUN_180046f80(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180046f90  FUN_180046f90  (34 bytes) ---- */

void FUN_180046f90(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_1800474a0(*param_1);
                    /* WARNING: Could not recover jumptable at 0x000180046faf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*param_2,*param_3,param_4);
  return;
}


/* ---- 0x1800470c0  FUN_1800470c0  (4 bytes) ---- */

undefined8 FUN_1800470c0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800470d0  FUN_1800470d0  (34 bytes) ---- */

void FUN_1800470d0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_180047520(*param_1);
                    /* WARNING: Could not recover jumptable at 0x0001800470ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*param_2,*param_3,param_4);
  return;
}


/* ---- 0x180047100  FUN_180047100  (4 bytes) ---- */

undefined8 FUN_180047100(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047110  FUN_180047110  (4 bytes) ---- */

undefined8 FUN_180047110(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047120  FUN_180047120  (28 bytes) ---- */

void FUN_180047120(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_180047540(*param_1);
                    /* WARNING: Could not recover jumptable at 0x000180047139. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*param_2,*param_3);
  return;
}


/* ---- 0x180047140  FUN_180047140  (8 bytes) ---- */

undefined8 FUN_180047140(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180047150  FUN_180047150  (8 bytes) ---- */

undefined8 FUN_180047150(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180047160  FUN_180047160  (8 bytes) ---- */

undefined8 FUN_180047160(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180047170  FUN_180047170  (8 bytes) ---- */

undefined8 FUN_180047170(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180047180  FUN_180047180  (8 bytes) ---- */

undefined8 FUN_180047180(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180047190  FUN_180047190  (8 bytes) ---- */

undefined8 FUN_180047190(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x1800471a0  FUN_1800471a0  (8 bytes) ---- */

undefined8 FUN_1800471a0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x1800471b0  FUN_1800471b0  (8 bytes) ---- */

undefined8 FUN_1800471b0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x1800471c0  FUN_1800471c0  (8 bytes) ---- */

undefined8 FUN_1800471c0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x1800471d0  FUN_1800471d0  (8 bytes) ---- */

undefined8 FUN_1800471d0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x1800471e0  FUN_1800471e0  (8 bytes) ---- */

undefined8 FUN_1800471e0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x1800471f0  FUN_1800471f0  (8 bytes) ---- */

undefined8 FUN_1800471f0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180047200  FUN_180047200  (8 bytes) ---- */

undefined8 FUN_180047200(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180047210  FUN_180047210  (8 bytes) ---- */

undefined8 FUN_180047210(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180047220  FUN_180047220  (8 bytes) ---- */

undefined8 FUN_180047220(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180047230  FUN_180047230  (8 bytes) ---- */

undefined8 FUN_180047230(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180047240  FUN_180047240  (8 bytes) ---- */

undefined8 FUN_180047240(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180047250  FUN_180047250  (8 bytes) ---- */

undefined8 FUN_180047250(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180047260  FUN_180047260  (8 bytes) ---- */

undefined8 FUN_180047260(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180047270  FUN_180047270  (8 bytes) ---- */

undefined8 FUN_180047270(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180047280  FUN_180047280  (8 bytes) ---- */

undefined8 FUN_180047280(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x1800472b0  FUN_1800472b0  (4 bytes) ---- */

undefined8 FUN_1800472b0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800472c0  FUN_1800472c0  (4 bytes) ---- */

undefined8 FUN_1800472c0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800472d0  FUN_1800472d0  (4 bytes) ---- */

undefined8 FUN_1800472d0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800472e0  FUN_1800472e0  (4 bytes) ---- */

undefined8 FUN_1800472e0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800472f0  FUN_1800472f0  (4 bytes) ---- */

undefined8 FUN_1800472f0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047300  FUN_180047300  (4 bytes) ---- */

undefined8 FUN_180047300(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047310  FUN_180047310  (4 bytes) ---- */

undefined8 FUN_180047310(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047320  FUN_180047320  (4 bytes) ---- */

undefined8 FUN_180047320(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047330  FUN_180047330  (4 bytes) ---- */

undefined8 FUN_180047330(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047340  FUN_180047340  (4 bytes) ---- */

undefined8 FUN_180047340(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047350  FUN_180047350  (4 bytes) ---- */

undefined8 FUN_180047350(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047360  FUN_180047360  (4 bytes) ---- */

undefined8 FUN_180047360(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047370  FUN_180047370  (4 bytes) ---- */

undefined8 FUN_180047370(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047380  FUN_180047380  (4 bytes) ---- */

undefined8 FUN_180047380(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047390  FUN_180047390  (4 bytes) ---- */

undefined8 FUN_180047390(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800473a0  FUN_1800473a0  (4 bytes) ---- */

undefined8 FUN_1800473a0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800473b0  FUN_1800473b0  (4 bytes) ---- */

undefined8 FUN_1800473b0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800473c0  FUN_1800473c0  (4 bytes) ---- */

undefined8 FUN_1800473c0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800473d0  FUN_1800473d0  (4 bytes) ---- */

undefined8 FUN_1800473d0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800473e0  FUN_1800473e0  (4 bytes) ---- */

undefined8 FUN_1800473e0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800473f0  FUN_1800473f0  (4 bytes) ---- */

undefined8 FUN_1800473f0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047400  FUN_180047400  (4 bytes) ---- */

undefined8 FUN_180047400(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047410  FUN_180047410  (4 bytes) ---- */

undefined8 FUN_180047410(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047420  FUN_180047420  (4 bytes) ---- */

undefined8 FUN_180047420(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047430  FUN_180047430  (4 bytes) ---- */

undefined8 FUN_180047430(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047440  FUN_180047440  (4 bytes) ---- */

undefined8 FUN_180047440(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047450  FUN_180047450  (4 bytes) ---- */

undefined8 FUN_180047450(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047460  FUN_180047460  (4 bytes) ---- */

undefined8 FUN_180047460(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047470  FUN_180047470  (4 bytes) ---- */

undefined8 FUN_180047470(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047480  FUN_180047480  (4 bytes) ---- */

undefined8 FUN_180047480(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047490  FUN_180047490  (4 bytes) ---- */

undefined8 FUN_180047490(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800474a0  FUN_1800474a0  (4 bytes) ---- */

undefined8 FUN_1800474a0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800474b0  FUN_1800474b0  (4 bytes) ---- */

undefined8 FUN_1800474b0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800474c0  FUN_1800474c0  (4 bytes) ---- */

undefined8 FUN_1800474c0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800474d0  FUN_1800474d0  (4 bytes) ---- */

undefined8 FUN_1800474d0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800474e0  FUN_1800474e0  (4 bytes) ---- */

undefined8 FUN_1800474e0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800474f0  FUN_1800474f0  (4 bytes) ---- */

undefined8 FUN_1800474f0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047500  FUN_180047500  (4 bytes) ---- */

undefined8 FUN_180047500(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047510  FUN_180047510  (4 bytes) ---- */

undefined8 FUN_180047510(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047520  FUN_180047520  (4 bytes) ---- */

undefined8 FUN_180047520(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047530  FUN_180047530  (4 bytes) ---- */

undefined8 FUN_180047530(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047540  FUN_180047540  (4 bytes) ---- */

undefined8 FUN_180047540(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047550  FUN_180047550  (4 bytes) ---- */

undefined8 FUN_180047550(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047560  FUN_180047560  (4 bytes) ---- */

undefined8 FUN_180047560(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047570  FUN_180047570  (4 bytes) ---- */

undefined8 FUN_180047570(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047580  FUN_180047580  (4 bytes) ---- */

undefined8 FUN_180047580(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047590  FUN_180047590  (4 bytes) ---- */

undefined8 FUN_180047590(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800475a0  FUN_1800475a0  (4 bytes) ---- */

undefined8 FUN_1800475a0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800475b0  FUN_1800475b0  (4 bytes) ---- */

undefined8 FUN_1800475b0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800475c0  FUN_1800475c0  (4 bytes) ---- */

undefined8 FUN_1800475c0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800475d0  FUN_1800475d0  (4 bytes) ---- */

undefined8 FUN_1800475d0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800475e0  FUN_1800475e0  (4 bytes) ---- */

undefined8 FUN_1800475e0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800475f0  FUN_1800475f0  (4 bytes) ---- */

undefined8 FUN_1800475f0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047600  FUN_180047600  (4 bytes) ---- */

undefined8 FUN_180047600(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047610  FUN_180047610  (4 bytes) ---- */

undefined8 FUN_180047610(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047620  FUN_180047620  (4 bytes) ---- */

undefined8 FUN_180047620(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047630  FUN_180047630  (4 bytes) ---- */

undefined8 FUN_180047630(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047640  FUN_180047640  (4 bytes) ---- */

undefined8 FUN_180047640(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047650  FUN_180047650  (4 bytes) ---- */

undefined8 FUN_180047650(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047660  FUN_180047660  (4 bytes) ---- */

undefined8 FUN_180047660(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047670  FUN_180047670  (4 bytes) ---- */

undefined8 FUN_180047670(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047680  FUN_180047680  (4 bytes) ---- */

undefined8 FUN_180047680(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047690  FUN_180047690  (4 bytes) ---- */

undefined8 FUN_180047690(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800476a0  FUN_1800476a0  (19 bytes) ---- */

undefined8 * FUN_1800476a0(undefined8 *param_1)

{
  *param_1 = 0x13992;
  param_1[1] = 0x14179;
  return param_1;
}


/* ---- 0x1800476c0  FUN_1800476c0  (4 bytes) ---- */

undefined8 FUN_1800476c0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800476d0  FUN_1800476d0  (11 bytes) ---- */

undefined8 * FUN_1800476d0(undefined8 *param_1)

{
  *param_1 = 0;
  return param_1;
}


/* ---- 0x1800476e0  FUN_1800476e0  (98 bytes) ---- */

undefined4 * FUN_1800476e0(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
  param_1[8] = param_2[8];
  param_1[9] = param_2[9];
  param_1[10] = param_2[10];
  param_1[0xb] = param_2[0xb];
  param_1[0xc] = param_2[0xc];
  param_1[0xd] = param_2[0xd];
  param_1[0xe] = param_2[0xe];
  param_1[0xf] = param_2[0xf];
  return param_1;
}


/* ---- 0x180047750  FUN_180047750  (5 bytes) ---- */

longlong FUN_180047750(longlong param_1,longlong param_2)

{
  return param_1 + param_2 * 4;
}


/* ---- 0x180047760  FUN_180047760  (5 bytes) ---- */

longlong FUN_180047760(longlong param_1,longlong param_2)

{
  return param_1 + param_2 * 4;
}


/* ---- 0x1800477b0  FUN_1800477b0  (49 bytes) ---- */

float * FUN_1800477b0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = param_3[1];
  fVar2 = param_1[1];
  *param_2 = *param_3 + *param_1;
  fVar3 = param_3[2];
  fVar4 = param_1[2];
  param_2[1] = fVar1 + fVar2;
  param_2[2] = fVar3 + fVar4;
  return param_2;
}


/* ---- 0x1800477f0  FUN_1800477f0  (49 bytes) ---- */

float * FUN_1800477f0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = param_1[1];
  fVar2 = param_3[1];
  *param_2 = *param_1 - *param_3;
  fVar3 = param_1[2];
  fVar4 = param_3[2];
  param_2[1] = fVar1 - fVar2;
  param_2[2] = fVar3 - fVar4;
  return param_2;
}


/* ---- 0x180047830  FUN_180047830  (37 bytes) ---- */

float FUN_180047830(float *param_1,float *param_2)

{
  return param_2[1] * param_1[1] + *param_2 * *param_1 + param_2[2] * param_1[2];
}


/* ---- 0x1800478b0  FUN_1800478b0  (49 bytes) ---- */

uint * FUN_1800478b0(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1[2];
  *param_2 = *param_1 ^ 0x80000000;
  uVar2 = param_1[1];
  param_2[2] = uVar1 ^ 0x80000000;
  param_2[1] = uVar2 ^ 0x80000000;
  return param_2;
}


/* ---- 0x180047920  FUN_180047920  (46 bytes) ---- */

float * FUN_180047920(float *param_1,float *param_2)

{
  *param_1 = *param_1 - *param_2;
  param_1[1] = param_1[1] - param_2[1];
  param_1[2] = param_1[2] - param_2[2];
  return param_1;
}


/* ---- 0x180047950  FUN_180047950  (46 bytes) ---- */

float * FUN_180047950(float *param_1,float *param_2)

{
  *param_1 = *param_2 * *param_1;
  param_1[1] = param_2[1] * param_1[1];
  param_1[2] = param_2[2] * param_1[2];
  return param_1;
}


/* ---- 0x180047980  FUN_180047980  (46 bytes) ---- */

float * FUN_180047980(float *param_1,float *param_2)

{
  *param_1 = *param_1 / *param_2;
  param_1[1] = param_1[1] / param_2[1];
  param_1[2] = param_1[2] / param_2[2];
  return param_1;
}


/* ---- 0x180047a60  FUN_180047a60  (37 bytes) ---- */

float FUN_180047a60(float *param_1,float *param_2)

{
  return param_2[1] * param_1[1] + *param_2 * *param_1 + param_2[2] * param_1[2];
}


/* ---- 0x180047b40  FUN_180047b40  (35 bytes) ---- */

float FUN_180047b40(float *param_1)

{
  return param_1[1] * param_1[1] + *param_1 * *param_1 + param_1[2] * param_1[2];
}


/* ---- 0x180047c70  FUN_180047c70  (4 bytes) ---- */

undefined8 FUN_180047c70(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047c80  FUN_180047c80  (4 bytes) ---- */

undefined8 FUN_180047c80(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180047c90  FUN_180047c90  (8 bytes) ---- */

bool FUN_180047c90(longlong *param_1)

{
  return *param_1 != 0;
}


/* ---- 0x180047d10  FUN_180047d10  (154 bytes) ---- */

longlong * FUN_180047d10(longlong param_1,longlong *param_2,uint param_3)

{
  longlong lVar1;
  ulonglong *puVar2;
  longlong local_res8;
  longlong *local_res10;
  ulonglong local_28;
  ulonglong uStack_20;
  
  local_28 = 0x5fe5;
  uStack_20 = 0x61f6;
  local_res10 = param_2;
  lVar1 = FUN_18000f860(&local_28);
  *param_2 = 0;
  param_2[1] = 0;
  RE::BSStringT<char,4294967295,RE::DynamicMemoryManagementPol>::set_cstr
            ((BSStringT<char,4294967295,RE::DynamicMemoryManagementPol> *)param_2,"",param_3);
  local_res8 = param_1;
  puVar2 = FUN_1800485c0(&local_28,lVar1);
  local_28 = *puVar2;
  uStack_20 = puVar2[1];
  REL::
  invoke<void_(__cdecl_RE::TESQuest::*)(RE::BSStringT<char,4294967295,RE::DynamicMemoryManagementPol>_&,unsigned_int)const_,RE::TESQuest_const_*,RE::BSStringT<char,4294967295,RE::DynamicMemoryManagementPol>_&,unsigned_int_const_&>
            (&local_28,&local_res8,
             (BSStringT<char,4294967295,RE::DynamicMemoryManagementPol> *)param_2,
             (undefined4 *)(param_1 + 0x50));
  return param_2;
}


/* ---- 0x180047e20  FUN_180047e20  (8 bytes) ---- */

undefined2 FUN_180047e20(longlong param_1)

{
  return *(undefined2 *)(param_1 + 0x228);
}


/* ---- 0x180047e30  FUN_180047e30  (14 bytes) ---- */

byte FUN_180047e30(longlong param_1)

{
  return (byte)((ushort)*(undefined2 *)(param_1 + 0xdc) >> 0xb) & 1;
}


/* ---- 0x180047e40  FUN_180047e40  (12 bytes) ---- */

byte FUN_180047e40(longlong param_1)

{
  return *(byte *)(param_1 + 0xdc) >> 1 & 1;
}


/* ---- 0x180047ed0  FUN_180047ed0  (11 bytes) ---- */

bool FUN_180047ed0(longlong param_1)

{
  return (*(byte *)(param_1 + 0xdc) & 0x81) == 0;
}


/* ---- 0x180047ee0  FUN_180047ee0  (41 bytes) ---- */

/* WARNING: Enum "DIALOGUE_TYPE": Some values do not have unique names */

longlong FUN_180047ee0(longlong param_1)

{
  byte bVar1;
  uint7 extraout_var;
  uint7 uVar2;
  
  bVar1 = RE::TESQuest::IsEnabled((TESQuest *)param_1);
  uVar2 = extraout_var;
  if ((bVar1 == 0) && (uVar2 = 0xff, *(short *)(param_1 + 0xdc) == -1)) {
    return 0xff01;
  }
  return (ulonglong)uVar2 << 8;
}


/* ---- 0x180047f10  FUN_180047f10  (78 bytes) ---- */

void FUN_180047f10(undefined8 param_1)

{
  ulong64 uVar1;
  ulonglong *puVar2;
  undefined8 local_res8 [4];
  ulonglong local_18;
  ulonglong uStack_10;
  
  local_18 = 0x5fa6;
  uStack_10 = 0x61b6;
  uVar1 = FUN_18000f860(&local_18);
  local_res8[0] = param_1;
  puVar2 = SKSE::stl::unrestricted_cast<void_(__cdecl_RE::TESQuest::*)(void),unsigned___int64>
                     (&local_18,uVar1);
  local_18 = *puVar2;
  uStack_10 = puVar2[1];
  REL::invoke<void_(__cdecl_RE::TESQuest::*)(void),RE::TESQuest_*>(&local_18,local_res8);
  return;
}


/* ---- 0x180047f60  FUN_180047f60  (91 bytes) ---- */

/* WARNING: Enum "DIALOGUE_TYPE": Some values do not have unique names */

void FUN_180047f60(TESQuest *param_1)

{
  byte bVar1;
  byte bVar2;
  longlong lVar3;
  TESQuest *this;
  
  FUN_180047f10(param_1);
  this = param_1;
  bVar1 = RE::TESQuest::IsEnabled(param_1);
  bVar2 = RE::TESQuest::StartsEnabled(this);
  if (bVar1 != bVar2) {
    lVar3 = FUN_1800a4760();
    if (lVar3 != 0) {
      if (bVar1 != 0) {
        FUN_1800a4690(lVar3,param_1);
        return;
      }
      FUN_1800a45c0(lVar3,param_1);
    }
  }
  return;
}


/* ---- 0x1800480b0  FUN_1800480b0  (90 bytes) ---- */

void FUN_1800480b0(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  longlong lVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined4 local_res18 [2];
  undefined8 local_res20;
  ulonglong local_18 [3];
  
  local_18[0] = 0x5b85;
  local_18[1] = 0x5d59;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18[0] = param_3;
  lVar1 = FUN_18000f860(local_18);
  local_res20 = FUN_180048590(lVar1);
  FUN_180048400(&local_res20,&local_res8,&local_res10,local_res18);
  return;
}


/* ---- 0x180048140  FUN_180048140  (46 bytes) ---- */

void FUN_180048140(undefined8 *param_1,undefined8 *param_2,
                  BSStringT<char,4294967295,RE::DynamicMemoryManagementPol> *param_3,
                  undefined4 *param_4)

{
  undefined8 *puVar1;
  undefined8 uStack_18;
  undefined8 uStack_10;
  
  puVar1 = FUN_1800485c0(&uStack_18,*param_1);
  uStack_18 = *puVar1;
  uStack_10 = puVar1[1];
  REL::
  invoke<void_(__cdecl_RE::TESQuest::*)(RE::BSStringT<char,4294967295,RE::DynamicMemoryManagementPol>_&,unsigned_int)const_,RE::TESQuest_const_*,RE::BSStringT<char,4294967295,RE::DynamicMemoryManagementPol>_&,unsigned_int_const_&>
            (&uStack_18,param_2,param_3,param_4);
  return;
}


/* ---- 0x180048170  FUN_180048170  (46 bytes) ---- */

void FUN_180048170(undefined8 *param_1,undefined8 *param_2,bool *param_3,undefined1 *param_4)

{
  undefined8 *puVar1;
  undefined8 uStack_18;
  undefined8 uStack_10;
  
  puVar1 = FUN_1800485b0(&uStack_18,*param_1);
  uStack_18 = *puVar1;
  uStack_10 = puVar1[1];
  REL::invoke<bool_(__cdecl_RE::TESQuest::*)(bool_&,bool),RE::TESQuest_*,bool_&,bool_&>
            (&uStack_18,param_2,param_3,param_4);
  return;
}


/* ---- 0x1800481a0  FUN_1800481a0  (17 bytes) ---- */

undefined2 FUN_1800481a0(ushort *param_1,ushort param_2)

{
  return CONCAT11((char)((*param_1 & param_2) >> 8),(*param_1 & param_2) == param_2);
}


/* ---- 0x1800481c0  FUN_1800481c0  (7 bytes) ---- */

bool FUN_1800481c0(byte *param_1)

{
  return (*param_1 & 0x81) == 0;
}


/* ---- 0x180048200  FUN_180048200  (8 bytes) ---- */

ushort * FUN_180048200(ushort *param_1)

{
  *param_1 = *param_1 | 1;
  return param_1;
}


/* ---- 0x180048210  FUN_180048210  (12 bytes) ---- */

ushort * FUN_180048210(ushort *param_1)

{
  *param_1 = *param_1 & 0xfffe;
  return param_1;
}


/* ---- 0x180048240  FUN_180048240  (29 bytes) ---- */

longlong * FUN_180048240(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180048260  FUN_180048260  (29 bytes) ---- */

longlong * FUN_180048260(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x180048280  FUN_180048280  (29 bytes) ---- */

longlong * FUN_180048280(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x1800482a0  FUN_1800482a0  (29 bytes) ---- */

longlong * FUN_1800482a0(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x1800482c0  FUN_1800482c0  (29 bytes) ---- */

longlong * FUN_1800482c0(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_18000f860(param_2);
  *param_1 = lVar1;
  return param_1;
}


/* ---- 0x1800482e0  FUN_1800482e0  (8 bytes) ---- */

bool FUN_1800482e0(longlong *param_1)

{
  return *param_1 != 0;
}


/* ---- 0x1800482f0  FUN_1800482f0  (12 bytes) ---- */

undefined8 FUN_1800482f0(short param_1)

{
  return CONCAT71(0xff,param_1 == -1);
}


/* ---- 0x180048300  FUN_180048300  (4 bytes) ---- */

undefined8 FUN_180048300(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180048310  FUN_180048310  (4 bytes) ---- */

undefined8 FUN_180048310(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180048350  FUN_180048350  (4 bytes) ---- */

undefined8 FUN_180048350(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800483e0  FUN_1800483e0  (4 bytes) ---- */

undefined8 FUN_1800483e0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800483f0  FUN_1800483f0  (4 bytes) ---- */

undefined8 FUN_1800483f0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180048400  FUN_180048400  (21 bytes) ---- */

void FUN_180048400(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4)

{
                    /* WARNING: Could not recover jumptable at 0x000180048412. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3,*param_4);
  return;
}


/* ---- 0x180048420  FUN_180048420  (8 bytes) ---- */

undefined8 FUN_180048420(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x1800484f0  FUN_1800484f0  (4 bytes) ---- */

undefined2 FUN_1800484f0(undefined2 *param_1)

{
  return *param_1;
}


/* ---- 0x180048500  FUN_180048500  (4 bytes) ---- */

undefined8 FUN_180048500(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180048510  FUN_180048510  (4 bytes) ---- */

undefined8 FUN_180048510(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180048520  FUN_180048520  (4 bytes) ---- */

undefined8 FUN_180048520(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180048530  FUN_180048530  (4 bytes) ---- */

undefined8 FUN_180048530(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180048540  FUN_180048540  (4 bytes) ---- */

undefined8 FUN_180048540(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180048550  FUN_180048550  (4 bytes) ---- */

undefined8 FUN_180048550(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180048560  FUN_180048560  (4 bytes) ---- */

undefined8 FUN_180048560(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180048570  FUN_180048570  (4 bytes) ---- */

undefined8 FUN_180048570(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x180048580  FUN_180048580  (4 bytes) ---- */

undefined8 FUN_180048580(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180048590  FUN_180048590  (4 bytes) ---- */

undefined8 FUN_180048590(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800485b0  FUN_1800485b0  (7 bytes) ---- */

undefined8 * FUN_1800485b0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800485c0  FUN_1800485c0  (7 bytes) ---- */

undefined8 * FUN_1800485c0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x1800485d0  FUN_1800485d0  (7 bytes) ---- */

undefined8 * FUN_1800485d0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180048c80  FUN_180048c80  (76 bytes) ---- */

void FUN_180048c80(longlong param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)(param_1 + 0x118);
  if ((*(longlong *)(param_1 + 0x120) == 0) && (*plVar1 == 0)) {
    plVar1 = (longlong *)0x0;
  }
  for (; plVar1 != (longlong *)0x0; plVar1 = (longlong *)plVar1[1]) {
    settings__OnSettingChanged(*plVar1);
  }
  return;
}


/* ---- 0x180048cd0  FUN_180048cd0  (28 bytes) ---- */

char * FUN_180048cd0(int param_1)

{
  if (param_1 < 0x30) {
    return (&PTR_s_none_1801918d0)[param_1];
  }
  return "unknown err";
}


/* ---- 0x180048d40  FUN_180048d40  (67 bytes) ---- */

undefined8 * FUN_180048d40(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* ---- 0x180048d90  FUN_180048d90  (21 bytes) ---- */

void FUN_180048d90(undefined8 *param_1)

{
  *param_1 = std::exception::vftable;
                    /* WARNING: Could not recover jumptable at 0x000180048d9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __std_exception_destroy(param_1 + 1);
  return;
}


/* ---- 0x180048dd0  FUN_180048dd0  (24 bytes) ---- */

LPSYSTEM_INFO FUN_180048dd0(LPSYSTEM_INFO param_1)

{
  GetSystemInfo(param_1);
  return param_1;
}


/* ---- 0x180048e60  FUN_180048e60  (12 bytes) ---- */

undefined4 FUN_180048e60(int param_1)

{
  return CONCAT31((int3)(param_1 - 0x80U >> 8),0xfffffeff < param_1 - 0x80U);
}


/* ---- 0x180048e70  FUN_180048e70  (24 bytes) ---- */

undefined8 FUN_180048e70(longlong param_1)

{
  return CONCAT71(0xfffffffeffffff,0xfffffffeffffffff < param_1 - 0x80000000U);
}


/* ---- 0x180048f30  FUN_180048f30  (14 bytes) ---- */

undefined8 * FUN_180048f30(undefined8 *param_1)

{
  *param_1 = Xbyak::Allocator::vftable;
  return param_1;
}


/* ---- 0x180048fd0  FUN_180048fd0  (11 bytes) ---- */

void FUN_180048fd0(undefined8 *param_1)

{
  *param_1 = Xbyak::Allocator::vftable;
  return;
}


/* ---- 0x180048ff0  FUN_180048ff0  (43 bytes) ---- */

undefined8 * FUN_180048ff0(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = Xbyak::Allocator::vftable;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* ---- 0x180049020  FUN_180049020  (14 bytes) ---- */

uint * FUN_180049020(uint *param_1)

{
  *param_1 = *param_1 & 0x80000000;
  param_1[1] = param_1[1] & 0xffffffc0;
  return param_1;
}


/* ---- 0x180049030  FUN_180049030  (83 bytes) ---- */

uint * FUN_180049030(uint *param_1,byte param_2,int param_3,uint param_4,byte param_5)

{
  uint uVar1;
  
  param_1[1] = param_1[1] & 0xffffffc0;
  uVar1 = ((uint)param_5 * -0x20 | (uint)param_2) & 0x3f ^ *param_1 & 0xffffffc0;
  *param_1 = ((param_4 & 0x3fff) << 0x10 ^ ((param_3 << 6 ^ uVar1) & 0xffc0 ^ uVar1) & 0xc000ffff) &
             0xbfffffff;
  return param_1;
}


/* ---- 0x180049090  FUN_180049090  (11 bytes) ---- */

uint FUN_180049090(uint *param_1)

{
  return *param_1 >> 6 & 0x3ff;
}


/* ---- 0x1800490a0  FUN_1800490a0  (6 bytes) ---- */

uint FUN_1800490a0(uint *param_1)

{
  return *param_1 & 0x1f;
}


/* ---- 0x1800490b0  FUN_1800490b0  (28 bytes) ---- */

ulonglong FUN_1800490b0(uint *param_1,uint param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar1 = *param_1;
  uVar2 = (ulonglong)uVar1;
  if (((char)uVar1 < '\0') &&
     ((param_2 == 0 ||
      (param_2 = uVar1 >> 0x10 & param_2, uVar2 = (ulonglong)param_2, (param_2 & 0x3fff) != 0)))) {
    return CONCAT71((int7)(uVar2 >> 8),1);
  }
  return uVar2 & 0xffffffffffffff00;
}


/* ---- 0x1800490d0  FUN_1800490d0  (28 bytes) ---- */

ulonglong FUN_1800490d0(uint *param_1,uint param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar1 = *param_1;
  uVar2 = (ulonglong)uVar1;
  if (((uVar1 & 0x40) != 0) &&
     ((param_2 == 0 ||
      (param_2 = uVar1 >> 0x10 & param_2, uVar2 = (ulonglong)param_2, (param_2 & 0x3fff) != 0)))) {
    return CONCAT71((int7)(uVar2 >> 8),1);
  }
  return uVar2 & 0xffffffffffffff00;
}


/* ---- 0x1800490f0  FUN_1800490f0  (8 bytes) ---- */

uint FUN_1800490f0(uint *param_1)

{
  return *param_1 >> 5 & 0xffffff01;
}


/* ---- 0x180049100  FUN_180049100  (8 bytes) ---- */

uint FUN_180049100(uint *param_1)

{
  return *param_1 >> 3 & 0xffffff01;
}


/* ---- 0x180049110  FUN_180049110  (45 bytes) ---- */

longlong FUN_180049110(uint *param_1,uint param_2,uint param_3)

{
  uint7 uVar1;
  
  param_2 = *param_1 >> 6 & param_2;
  uVar1 = (uint7)(uint3)(param_2 >> 8);
  if (((param_2 & 0x3ff) != 0) && ((param_3 == 0 || ((*param_1 >> 0x10 & param_3 & 0x3fff) != 0))))
  {
    return CONCAT71(uVar1,1);
  }
  return (ulonglong)uVar1 << 8;
}


/* ---- 0x180049140  FUN_180049140  (15 bytes) ---- */

undefined4 FUN_180049140(longlong param_1,uint param_2)

{
  param_2 = *(ushort *)(param_1 + 2) & param_2;
  return CONCAT31((int3)(param_2 >> 8),(param_2 & 0x3fff) != 0);
}


/* ---- 0x180049150  FUN_180049150  (10 bytes) ---- */

ushort FUN_180049150(longlong param_1)

{
  return *(ushort *)(param_1 + 2) & 0x3fff;
}


/* ---- 0x180049330  FUN_180049330  (14 bytes) ---- */

uint * FUN_180049330(uint *param_1)

{
  *param_1 = *param_1 & 0x80000000;
  param_1[1] = param_1[1] & 0xffffffc0;
  return param_1;
}


/* ---- 0x180049340  FUN_180049340  (83 bytes) ---- */

uint * FUN_180049340(uint *param_1,byte param_2,int param_3,uint param_4,byte param_5)

{
  uint uVar1;
  
  param_1[1] = param_1[1] & 0xffffffc0;
  uVar1 = ((uint)param_5 * -0x20 | (uint)param_2) & 0x3f ^ *param_1 & 0xffffffc0;
  *param_1 = ((param_4 & 0x3fff) << 0x10 ^ ((param_3 << 6 ^ uVar1) & 0xffc0 ^ uVar1) & 0xc000ffff) &
             0xbfffffff;
  return param_1;
}


/* ---- 0x1800493d0  FUN_1800493d0  (25 bytes) ---- */

undefined8 FUN_1800493d0(uint *param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((*param_1 & 0x400080) == 0x400080) {
    uVar1 = 8;
  }
  return uVar1;
}


/* ---- 0x1800493f0  FUN_1800493f0  (7 bytes) ---- */

uint FUN_1800493f0(uint *param_1)

{
  return CONCAT31((uint3)(*param_1 >> 9),(char)(*param_1 >> 1)) & 0xffffff04;
}


/* ---- 0x180049400  FUN_180049400  (8 bytes) ---- */

uint FUN_180049400(uint *param_1)

{
  return *param_1 >> 2 & 0xffffff02;
}


/* ---- 0x180049410  FUN_180049410  (8 bytes) ---- */

uint FUN_180049410(uint *param_1)

{
  return *param_1 >> 3 & 0xffffff01;
}


/* ---- 0x180049480  FUN_180049480  (4 bytes) ---- */

undefined8 FUN_180049480(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180049490  FUN_180049490  (49 bytes) ---- */

uint * FUN_180049490(uint *param_1,byte param_2,uint param_3)

{
  param_1[1] = param_1[1] & 0xffffffc0;
  *param_1 = ((param_3 & 0xff) * -0x20 | (uint)param_2) & 0x3f ^ *param_1 & 0x80080080 | 0x80080;
  return param_1;
}


/* ---- 0x1800494d0  FUN_1800494d0  (41 bytes) ---- */

uint * FUN_1800494d0(uint *param_1,byte param_2)

{
  param_1[1] = param_1[1] & 0xffffffc0;
  *param_1 = (param_2 & 0x3f ^ *param_1 & 0xffffffc0) & 0x801000bf | 0x100080;
  return param_1;
}


/* ---- 0x180049500  FUN_180049500  (68 bytes) ---- */

uint * FUN_180049500(uint *param_1,byte param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  param_1[1] = param_1[1] & 0xffffffc0;
  uVar1 = ((uint)param_2 ^ *param_1) & 0x3f ^ *param_1;
  *param_1 = ((param_4 & 0x3fff) << 0x10 ^ ((param_3 << 6 ^ uVar1) & 0xffc0 ^ uVar1) & 0xc000ffff) &
             0xbfffffff;
  return param_1;
}


/* ---- 0x180049550  FUN_180049550  (6 bytes) ---- */

undefined4 * FUN_180049550(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180049560  FUN_180049560  (4 bytes) ---- */

undefined8 FUN_180049560(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x180049570  FUN_180049570  (68 bytes) ---- */

uint * FUN_180049570(uint *param_1,byte param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  param_1[1] = param_1[1] & 0xffffffc0;
  uVar1 = ((uint)param_2 ^ *param_1) & 0x3f ^ *param_1;
  *param_1 = ((param_4 & 0x3fff) << 0x10 ^ ((param_3 << 6 ^ uVar1) & 0xffc0 ^ uVar1) & 0xc000ffff) &
             0xbfffffff;
  return param_1;
}


/* ---- 0x180049670  FUN_180049670  (41 bytes) ---- */

uint * FUN_180049670(uint *param_1,byte param_2)

{
  param_1[1] = param_1[1] & 0xffffffc0;
  *param_1 = (param_2 & 0x3f ^ *param_1 & 0xffffffc0) & 0x8040203f | 0x402000;
  return param_1;
}


/* ---- 0x1800496a0  FUN_1800496a0  (41 bytes) ---- */

uint * FUN_1800496a0(uint *param_1,byte param_2)

{
  param_1[1] = param_1[1] & 0xffffffc0;
  *param_1 = (param_2 & 0x3f ^ *param_1 & 0xffffffc0) & 0x8080403f | 0x804000;
  return param_1;
}


/* ---- 0x1800496d0  FUN_1800496d0  (41 bytes) ---- */

uint * FUN_1800496d0(uint *param_1,byte param_2)

{
  param_1[1] = param_1[1] & 0xffffffc0;
  *param_1 = (param_2 & 0x3f ^ *param_1 & 0xffffffc0) & 0x8020023f | 0x200200;
  return param_1;
}


/* ---- 0x180049700  FUN_180049700  (65 bytes) ---- */

uint * FUN_180049700(uint *param_1,byte param_2,uint param_3)

{
  param_1[1] = param_1[1] & 0xffffffc0;
  *param_1 = ((param_3 & 0x3fff) << 0x10 ^
             ((param_2 & 0x3f ^ *param_1 & 0xffffffc0) & 0xc00000bf | 0x80)) & 0xbfffffff;
  return param_1;
}


/* ---- 0x180049750  FUN_180049750  (41 bytes) ---- */

uint * FUN_180049750(uint *param_1,byte param_2)

{
  param_1[1] = param_1[1] & 0xffffffc0;
  *param_1 = (param_2 & 0x3f ^ *param_1 & 0xffffffc0) & 0x802000bf | 0x200080;
  return param_1;
}


/* ---- 0x180049780  FUN_180049780  (41 bytes) ---- */

uint * FUN_180049780(uint *param_1,byte param_2)

{
  param_1[1] = param_1[1] & 0xffffffc0;
  *param_1 = (param_2 & 0x3f ^ *param_1 & 0xffffffc0) & 0x804000bf | 0x400080;
  return param_1;
}


/* ---- 0x1800497b0  FUN_1800497b0  (15 bytes) ---- */

undefined8 * FUN_1800497b0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  *(undefined1 *)(param_1 + 2) = 0;
  return param_1;
}


/* ---- 0x1800497c0  FUN_1800497c0  (71 bytes) ---- */

undefined8 * FUN_1800497c0(undefined8 *param_1,undefined8 *param_2,undefined8 param_3)

{
  Error aEStack_28 [40];
  
  if ((param_2[1] == 0) && (*(char *)(param_2 + 2) == '\0')) {
    *param_1 = *param_2;
    param_1[1] = param_3;
    *(undefined1 *)(param_1 + 2) = 0;
    return param_1;
  }
  Xbyak::Error::Error(aEStack_28,1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(aEStack_28,(ThrowInfo *)&_TI2_AVError_Xbyak__);
}


/* ---- 0x180049810  FUN_180049810  (6 bytes) ---- */

undefined4 * FUN_180049810(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return param_1;
}


/* ---- 0x180049820  FUN_180049820  (36 bytes) ---- */

uint * FUN_180049820(uint *param_1,undefined8 param_2)

{
  *param_1 = *param_1 & 0x80000000;
  param_1[1] = param_1[1] & 0xffffffc0;
  param_1[2] = param_1[2] & 0x80000000;
  param_1[3] = param_1[3] & 0xffffffc0;
  param_1[4] = 0;
  *(undefined8 *)(param_1 + 6) = param_2;
  return param_1;
}


/* ---- 0x180049990  FUN_180049990  (11 bytes) ---- */

bool FUN_180049990(longlong param_1)

{
  return (*(uint *)(param_1 + 8) & 0x3800000) != 0;
}


/* ---- 0x1800499a0  FUN_1800499a0  (55 bytes) ---- */

undefined8 * FUN_1800499a0(uint *param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar1 = param_1[2];
  uVar2 = *(undefined8 *)(param_1 + 2);
  uVar3 = *(undefined8 *)(param_1 + 4);
  uVar4 = *(undefined8 *)(param_1 + 6);
  *param_2 = *(undefined8 *)param_1;
  param_2[1] = uVar2;
  param_2[2] = uVar3;
  param_2[3] = uVar4;
  if ((((uVar1 & 0x600000) != 0) && ((*param_1 & 0x3fff0000) == 0)) && (param_1[4] == 2)) {
    *param_2 = *(undefined8 *)(param_1 + 2);
    *(undefined4 *)(param_2 + 2) = 1;
  }
  return param_2;
}


/* ---- 0x1800499e0  FUN_1800499e0  (4 bytes) ---- */

undefined8 FUN_1800499e0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x1800499f0  FUN_1800499f0  (5 bytes) ---- */

longlong FUN_1800499f0(longlong param_1)

{
  return param_1 + 8;
}


/* ---- 0x180049a00  FUN_180049a00  (4 bytes) ---- */

undefined4 FUN_180049a00(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}


/* ---- 0x180049a10  FUN_180049a10  (5 bytes) ---- */

undefined8 FUN_180049a10(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x18);
}


/* ---- 0x180049a20  FUN_180049a20  (31 bytes) ---- */

byte FUN_180049a20(uint *param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = (byte)(param_1[2] >> 2) & 2 | (byte)(*param_1 >> 3) & 1;
  bVar1 = bVar2 | 0x40;
  if (bVar2 == 0) {
    bVar1 = 0;
  }
  return bVar1;
}


/* ---- 0x180049a40  FUN_180049a40  (234 bytes) ---- */

uint * FUN_180049a40(uint *param_1,undefined8 *param_2,uint *param_3)

{
  undefined8 uVar1;
  ulonglong uVar2;
  Error aEStack_28 [40];
  
  if (((*(uint *)(param_2 + 1) & 0x3fff0000) != 0) && ((param_3[2] & 0x3fff0000) != 0)) {
    Xbyak::Error::Error(aEStack_28,1);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(aEStack_28,(ThrowInfo *)&_TI2_AVError_Xbyak__);
  }
  uVar1 = param_2[1];
  *(undefined8 *)param_1 = *param_2;
  *(undefined8 *)(param_1 + 2) = uVar1;
  uVar1 = param_2[3];
  *(undefined8 *)(param_1 + 4) = param_2[2];
  *(undefined8 *)(param_1 + 6) = uVar1;
  uVar2 = (ulonglong)param_1[2];
  if ((param_1[2] & 0x3fff0000) == 0) {
    uVar2 = *(ulonglong *)(param_3 + 2);
    *(ulonglong *)(param_1 + 2) = uVar2;
    param_1[4] = param_3[4];
  }
  if ((*param_3 & 0x3fff0000) != 0) {
    if ((*param_1 & 0x3fff0000) != 0) {
      if ((uVar2 & 0x3fff0000) == 0) {
        uVar1 = *(undefined8 *)param_3;
        *(undefined8 *)(param_1 + 2) = uVar1;
        if (((byte)uVar1 & 0x1f) == 4) {
          *(undefined8 *)(param_1 + 2) = *(undefined8 *)param_1;
          *(undefined8 *)param_1 = uVar1;
        }
        param_1[4] = 1;
        *(longlong *)(param_1 + 6) = *(longlong *)(param_1 + 6) + *(longlong *)(param_3 + 6);
        return param_1;
      }
      Xbyak::Error::Error(aEStack_28,1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(aEStack_28,(ThrowInfo *)&_TI2_AVError_Xbyak__);
    }
    *(undefined8 *)param_1 = *(undefined8 *)param_3;
  }
  *(longlong *)(param_1 + 6) = *(longlong *)(param_1 + 6) + *(longlong *)(param_3 + 6);
  return param_1;
}


/* ---- 0x180049b30  FUN_180049b30  (19 bytes) ---- */

longlong FUN_180049b30(longlong param_1)

{
  int iVar1;
  uint7 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  uVar2 = (uint7)(uint3)((uint)iVar1 >> 8);
  if ((iVar1 != 2) && (iVar1 != 3)) {
    return (ulonglong)uVar2 << 8;
  }
  return CONCAT71(uVar2,1);
}


/* ---- 0x180049b50  FUN_180049b50  (22 bytes) ---- */

undefined8 *
FUN_180049b50(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
             undefined4 param_5)

{
  *(undefined4 *)((longlong)param_1 + 0x14) = param_5;
  *param_1 = param_2;
  param_1[1] = param_3;
  *(undefined4 *)(param_1 + 2) = param_4;
  return param_1;
}


/* ---- 0x180049be0  FUN_180049be0  (11 bytes) ---- */

void FUN_180049be0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180049be7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(longlong **)(param_1 + 0x28) + 0x18))();
  return;
}


/* ---- 0x18004a160  FUN_18004a160  (43 bytes) ---- */

bool FUN_18004a160(longlong param_1,undefined1 param_2)

{
  BOOL BVar1;
  undefined1 auStackX_10 [24];
  
  auStackX_10[0] = param_2;
  BVar1 = VirtualProtect(*(LPVOID *)(param_1 + 0x38),*(SIZE_T *)(param_1 + 0x30),4,
                         (PDWORD)auStackX_10);
  return BVar1 != 0;
}


/* ---- 0x18004a3e0  FUN_18004a3e0  (5 bytes) ---- */

undefined8 FUN_18004a3e0(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x38);
}


/* ---- 0x18004a3f0  FUN_18004a3f0  (9 bytes) ---- */

longlong FUN_18004a3f0(longlong param_1)

{
  return *(longlong *)(param_1 + 0x40) + *(longlong *)(param_1 + 0x38);
}


/* ---- 0x18004a400  FUN_18004a400  (5 bytes) ---- */

undefined8 FUN_18004a400(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x40);
}


/* ---- 0x18004a660  FUN_18004a660  (8 bytes) ---- */

bool FUN_18004a660(longlong param_1)

{
  return *(int *)(param_1 + 0x18) == 3;
}


/* ---- 0x18004a6e0  FUN_18004a6e0  (52 bytes) ---- */

undefined8 * FUN_18004a6e0(undefined8 *param_1,uint param_2)

{
  Xbyak::CodeArray::~CodeArray((CodeArray *)param_1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* ---- 0x18004a810  FUN_18004a810  (104 bytes) ---- */

uint * FUN_18004a810(uint *param_1,uint param_2,undefined1 param_3,undefined8 *param_4)

{
  char cVar1;
  undefined8 uVar2;
  
  param_1[1] = param_1[1] & 0xffffffc0;
  *param_1 = ((param_2 & 0x3fff) << 0x10 ^ (*param_1 & 0xc0000040 | 0x40)) & 0xbfffffff;
  uVar2 = *param_4;
  param_1[2] = param_1[2] & 0x80000000;
  param_1[3] = param_1[3] & 0xffffffc0;
  param_1[4] = param_1[4] & 0x80000000;
  param_1[5] = param_1[5] & 0xffffffc0;
  param_1[6] = 0;
  *(undefined8 *)(param_1 + 8) = uVar2;
  *(undefined8 *)(param_1 + 10) = param_4[1];
  cVar1 = *(char *)(param_4 + 2);
  *(undefined1 *)(param_1 + 0xd) = param_3;
  param_1[0xc] = (cVar1 != '\0') + 2;
  return param_1;
}


/* ---- 0x18004a8e0  FUN_18004a8e0  (4 bytes) ---- */

undefined4 FUN_18004a8e0(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0x30);
}


/* ---- 0x18004a8f0  FUN_18004a8f0  (36 bytes) ---- */

longlong FUN_18004a8f0(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 8) & 0x3fff0000;
  if ((uVar1 != 0x200000) && (uVar1 = *(uint *)(param_1 + 0x10) & 0x3fff0000, uVar1 != 0x200000)) {
    return (ulonglong)(uint3)(uVar1 >> 8) << 8;
  }
  return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
}


/* ---- 0x18004a920  FUN_18004a920  (5 bytes) ---- */

undefined8 FUN_18004a920(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x20);
}


/* ---- 0x18004a9a0  FUN_18004a9a0  (8 bytes) ---- */

bool FUN_18004a9a0(longlong param_1)

{
  return *(int *)(param_1 + 0x30) == 1;
}


/* ---- 0x18004a9b0  FUN_18004a9b0  (5 bytes) ---- */

undefined8 FUN_18004a9b0(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x28);
}


/* ---- 0x18004a9c0  FUN_18004a9c0  (11 bytes) ---- */

bool FUN_18004a9c0(longlong param_1)

{
  return (*(uint *)(param_1 + 0x10) & 0x3800000) != 0;
}


/* ---- 0x18004a9d0  FUN_18004a9d0  (4 bytes) ---- */

undefined8 FUN_18004a9d0(undefined8 param_1)

{
  return param_1;
}


/* ---- 0x18004a9e0  FUN_18004a9e0  (10 bytes) ---- */

undefined4 * FUN_18004a9e0(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 1) = param_3;
  return param_1;
}


/* ---- 0x18004aaf0  FUN_18004aaf0  (112 bytes) ---- */

uint * FUN_18004aaf0(uint *param_1,uint *param_2,undefined8 *param_3)

{
  char cVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  
  uVar2 = *param_1;
  uVar4 = param_1[1];
  param_2[1] = param_2[1] & 0xffffffc0;
  *param_2 = ((uVar2 & 0x3fff) << 0x10 ^ (*param_2 & 0xc0000040 | 0x40)) & 0xbfffffff;
  uVar3 = *param_3;
  param_2[2] = param_2[2] & 0x80000000;
  param_2[3] = param_2[3] & 0xffffffc0;
  param_2[4] = param_2[4] & 0x80000000;
  param_2[5] = param_2[5] & 0xffffffc0;
  param_2[6] = 0;
  *(undefined8 *)(param_2 + 8) = uVar3;
  *(undefined8 *)(param_2 + 10) = param_3[1];
  cVar1 = *(char *)(param_3 + 2);
  *(char *)(param_2 + 0xd) = (char)uVar4;
  param_2[0xc] = (cVar1 != '\0') + 2;
  return param_2;
}


/* ---- 0x18004ab60  FUN_18004ab60  (24 bytes) ---- */

undefined8 *
FUN_18004ab60(undefined8 *param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
             undefined8 param_5)

{
  param_1[2] = param_5;
  *param_1 = param_2;
  *(undefined4 *)(param_1 + 1) = param_3;
  *(undefined4 *)((longlong)param_1 + 0xc) = param_4;
  return param_1;
}


/* ---- 0x18004ab80  FUN_18004ab80  (12 bytes) ---- */

undefined8 * FUN_18004ab80(undefined8 *param_1)

{
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  return param_1;
}


/* ---- 0x18004ab90  FUN_18004ab90  (9 bytes) ---- */

void FUN_18004ab90(undefined8 *param_1)

{
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  return;
}


/* ---- 0x18004aba0  FUN_18004aba0  (14 bytes) ---- */

undefined8 * FUN_18004aba0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  *(undefined4 *)(param_1 + 1) = 1;
  return param_1;
}


/* ---- 0x18004abb0  FUN_18004abb0  (26 bytes) ---- */

int FUN_18004abb0(longlong param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 8);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x18);
    *(int *)(param_1 + 0x18) = iVar1 + 1;
    *(int *)(param_2 + 8) = iVar1;
  }
  return iVar1;
}


/* ---- 0x18004ada0  FUN_18004ada0  (56 bytes) ---- */

void FUN_18004ada0(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  ulong64 uVar7;
  ulonglong uVar8;
  longlong *plVar9;
  longlong *_Memory;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong lStackX_8;
  longlong lStackX_10;
  
  puVar1 = *(undefined8 **)(param_1 + 0xa8);
  for (puVar2 = (undefined8 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined8 *)*puVar2) {
    puVar3 = (undefined8 *)puVar2[2];
    *puVar3 = 0;
    *(undefined4 *)(puVar3 + 1) = 0;
  }
  if (*(ulonglong *)(param_1 + 0xb0) != 0) {
    plVar4 = *(longlong **)(param_1 + 0xa8);
    if (*(ulonglong *)(param_1 + 0xb0) < *(ulonglong *)(param_1 + 0xd8) >> 3) {
      plVar5 = (longlong *)*plVar4;
      if (plVar5 != plVar4) {
        lVar11 = *(longlong *)(param_1 + 0xb8);
        plVar6 = (longlong *)plVar5[1];
        lStackX_10 = lVar11;
        uVar7 = std::_Hash_representation<Xbyak::Label_*>((Label **)(plVar5 + 2));
        uVar8 = uVar7 & *(ulonglong *)(param_1 + 0xd0);
        plVar9 = *(longlong **)(lVar11 + 8 + uVar8 * 0x10);
        plVar12 = (longlong *)(lVar11 + uVar8 * 0x10);
        lStackX_8 = *(longlong *)(lVar11 + uVar8 * 0x10);
        _Memory = plVar5;
        do {
          plVar10 = (longlong *)*_Memory;
          free(_Memory);
          lVar11 = lStackX_10;
          *(longlong *)(param_1 + 0xb0) = *(longlong *)(param_1 + 0xb0) + -1;
          if (_Memory == plVar9) {
            plVar9 = plVar6;
            if ((longlong *)lStackX_8 == plVar5) {
              *plVar12 = (longlong)plVar4;
              plVar9 = plVar4;
            }
            plVar12[1] = (longlong)plVar9;
            while (plVar10 != plVar4) {
              uVar7 = std::_Hash_representation<Xbyak::Label_*>((Label **)(plVar10 + 2));
              plVar12 = (longlong *)((uVar7 & *(ulonglong *)(param_1 + 0xd0)) * 0x10 + lVar11);
              plVar5 = (longlong *)plVar12[1];
              plVar9 = plVar10;
              while( true ) {
                plVar10 = (longlong *)*plVar9;
                free(plVar9);
                *(longlong *)(param_1 + 0xb0) = *(longlong *)(param_1 + 0xb0) + -1;
                if (plVar9 == plVar5) break;
                plVar9 = plVar10;
                if (plVar10 == plVar4) goto LAB_180050e68;
              }
              *plVar12 = (longlong)plVar4;
              plVar12[1] = (longlong)plVar4;
            }
            goto LAB_180050e6b;
          }
          _Memory = plVar10;
        } while (plVar10 != plVar4);
        if ((longlong *)lStackX_8 == plVar5) {
LAB_180050e68:
          *plVar12 = (longlong)plVar10;
        }
LAB_180050e6b:
        *plVar6 = (longlong)plVar10;
        plVar10[1] = (longlong)plVar6;
        return;
      }
    }
    else {
      *(undefined8 *)plVar4[1] = 0;
      puVar1 = (undefined8 *)*plVar4;
      while (puVar1 != (undefined8 *)0x0) {
        puVar2 = (undefined8 *)*puVar1;
        free(puVar1);
        puVar1 = puVar2;
      }
      *(undefined8 *)*(undefined8 *)(param_1 + 0xa8) = *(undefined8 *)(param_1 + 0xa8);
      *(longlong *)(*(longlong *)(param_1 + 0xa8) + 8) = *(longlong *)(param_1 + 0xa8);
      *(undefined8 *)(param_1 + 0xb0) = 0;
      lStackX_8 = *(longlong *)(param_1 + 0xa8);
      FUN_180052900(*(undefined8 **)(param_1 + 0xb8),*(undefined8 **)(param_1 + 0xc0),&lStackX_8);
    }
  }
  return;
}


/* ---- 0x18004b420  FUN_18004b420  (4 bytes) ---- */

void FUN_18004b420(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


/* ---- 0x18004b540  FUN_18004b540  (56 bytes) ---- */

void FUN_18004b540(longlong param_1,longlong param_2,undefined8 *param_3)

{
  undefined8 auStackX_8 [4];
  undefined4 auStack_28 [2];
  undefined8 uStack_20;
  undefined8 uStack_18;
  undefined8 uStack_10;
  
  uStack_20 = *param_3;
  uStack_18 = param_3[1];
  auStack_28[0] = *(undefined4 *)(param_2 + 8);
  uStack_10 = param_3[2];
  std::
  _Hash<std::_Umap_traits<int,Xbyak::JmpLabel_const_,std::_Uhash_compare<int,std::hash<int>,std::equal_to<int>_>,std::allocator<std::pair<int_const_,Xbyak::JmpLabel_const_>_>,1>_>
  ::emplace<std::pair<int_const_,Xbyak::JmpLabel_const_>_>
            ((float *)(param_1 + 0x60),auStackX_8,(undefined8 *)auStack_28);
  return;
}


/* ---- 0x18004b580  FUN_18004b580  (37 bytes) ---- */

ulonglong FUN_18004b580(longlong param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)**(undefined8 **)(param_1 + 8);
  while( true ) {
    if (puVar1 == *(undefined8 **)(param_1 + 8)) {
      return (ulonglong)puVar1 & 0xffffffffffffff00;
    }
    if (puVar1[0xc] != 0) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return CONCAT71((int7)((ulonglong)puVar1 >> 8),1);
}


/* ---- 0x18004b5b0  FUN_18004b5b0  (9 bytes) ---- */

bool FUN_18004b5b0(longlong param_1)

{
  return *(longlong *)(param_1 + 0x70) != 0;
}


/* ---- 0x18004b5c0  FUN_18004b5c0  (93 bytes) ---- */

void FUN_18004b5c0(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  FUN_180051340((longlong *)(param_1 + 0x18));
  puVar1 = *(undefined8 **)(param_1 + 8);
  *(undefined8 *)puVar1[1] = 0;
  puVar1 = (undefined8 *)*puVar1;
  while (puVar1 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)*puVar1;
    free(puVar1);
    puVar1 = puVar2;
  }
  free(*(void **)(param_1 + 8));
  return;
}


/* ---- 0x18004b620  FUN_18004b620  (93 bytes) ---- */

void FUN_18004b620(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  FUN_180051340((longlong *)(param_1 + 0x18));
  puVar1 = *(undefined8 **)(param_1 + 8);
  *(undefined8 *)puVar1[1] = 0;
  puVar1 = (undefined8 *)*puVar1;
  while (puVar1 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)*puVar1;
    free(puVar1);
    puVar1 = puVar2;
  }
  free(*(void **)(param_1 + 8));
  return;
}


/* ---- 0x18004b680  FUN_18004b680  (93 bytes) ---- */

void FUN_18004b680(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  FUN_180051080((longlong *)(param_1 + 0x18));
  puVar1 = *(undefined8 **)(param_1 + 8);
  *(undefined8 *)puVar1[1] = 0;
  puVar1 = (undefined8 *)*puVar1;
  while (puVar1 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)*puVar1;
    free(puVar1);
    puVar1 = puVar2;
  }
  free(*(void **)(param_1 + 8));
  return;
}


/* ---- 0x18004b6e0  FUN_18004b6e0  (93 bytes) ---- */

void FUN_18004b6e0(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  FUN_180051080((longlong *)(param_1 + 0x18));
  puVar1 = *(undefined8 **)(param_1 + 8);
  *(undefined8 *)puVar1[1] = 0;
  puVar1 = (undefined8 *)*puVar1;
  while (puVar1 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)*puVar1;
    free(puVar1);
    puVar1 = puVar2;
  }
  free(*(void **)(param_1 + 8));
  return;
}


/* ---- 0x18004b740  FUN_18004b740  (93 bytes) ---- */

void FUN_18004b740(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  FUN_180050cb0((longlong *)(param_1 + 0x18));
  puVar1 = *(undefined8 **)(param_1 + 8);
  *(undefined8 *)puVar1[1] = 0;
  puVar1 = (undefined8 *)*puVar1;
  while (puVar1 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)*puVar1;
    free(puVar1);
    puVar1 = puVar2;
  }
  free(*(void **)(param_1 + 8));
  return;
}


/* ---- 0x18004b7a0  FUN_18004b7a0  (93 bytes) ---- */

void FUN_18004b7a0(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  FUN_180050cb0((longlong *)(param_1 + 0x18));
  puVar1 = *(undefined8 **)(param_1 + 8);
  *(undefined8 *)puVar1[1] = 0;
  puVar1 = (undefined8 *)*puVar1;
  while (puVar1 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)*puVar1;
    free(puVar1);
    puVar1 = puVar2;
  }
  free(*(void **)(param_1 + 8));
  return;
}


/* ---- 0x18004b9a0  FUN_18004b9a0  (50 bytes) ---- */

void FUN_18004b9a0(longlong param_1)

{
  FUN_180051c50((longlong *)(param_1 + 0x58));
  FUN_180051cc0((longlong *)(param_1 + 0x48));
  FUN_180051d30((longlong *)(param_1 + 0x18));
  FUN_180051da0((longlong *)(param_1 + 8));
  return;
}


/* ---- 0x18004b9e0  FUN_18004b9e0  (32 bytes) ---- */

void FUN_18004b9e0(longlong param_1)

{
  FUN_180051d30((longlong *)(param_1 + 0x18));
  FUN_180051da0((longlong *)(param_1 + 8));
  return;
}


/* ---- 0x18004ba00  FUN_18004ba00  (32 bytes) ---- */

void FUN_18004ba00(longlong param_1)

{
  FUN_180051d30((longlong *)(param_1 + 0x18));
  FUN_180051da0((longlong *)(param_1 + 8));
  return;
}


/* ---- 0x18004ba20  FUN_18004ba20  (32 bytes) ---- */

void FUN_18004ba20(longlong param_1)

{
  FUN_180051c50((longlong *)(param_1 + 0x18));
  FUN_180051cc0((longlong *)(param_1 + 8));
  return;
}


/* ---- 0x18004ba40  FUN_18004ba40  (32 bytes) ---- */

void FUN_18004ba40(longlong param_1)

{
  FUN_180051c50((longlong *)(param_1 + 0x18));
  FUN_180051cc0((longlong *)(param_1 + 8));
  return;
}


/* ---- 0x18004ba70  FUN_18004ba70  (27 bytes) ---- */

void FUN_18004ba70(Label *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  longlong *plVar4;
  longlong *plVar5;
  Label *pLVar6;
  longlong lVar7;
  longlong *plVar8;
  LabelManager *pLVar9;
  ulong64 uVar10;
  longlong *plVar11;
  longlong *plVar12;
  int aiStackX_10 [2];
  Label *pLStackX_18;
  
  iVar3 = param_1->id;
  if ((iVar3 == 0) || (pLVar9 = param_1->mgr, pLVar9 == (LabelManager *)0x0)) {
    return;
  }
  aiStackX_10[0] = iVar3;
  pLStackX_18 = param_1;
  uVar10 = std::_Hash_representation<Xbyak::Label_*>(&pLStackX_18);
  plVar4 = *(longlong **)&(pLVar9->labelPtrList_).field_0x8;
  plVar12 = (longlong *)
            (*(longlong *)&(pLVar9->labelPtrList_).field_0x18 +
            (uVar10 & *(ulonglong *)&(pLVar9->labelPtrList_).field_0x30) * 0x10);
  plVar5 = (longlong *)plVar12[1];
  if (plVar5 == plVar4) {
LAB_18004ac41:
    plVar11 = (longlong *)0x0;
  }
  else {
    pLVar6 = (Label *)plVar5[2];
    plVar11 = plVar5;
    while (param_1 != pLVar6) {
      if (plVar11 == (longlong *)*plVar12) goto LAB_18004ac41;
      plVar11 = (longlong *)plVar11[1];
      pLVar6 = (Label *)plVar11[2];
    }
  }
  if (plVar11 != (longlong *)0x0) {
    if (plVar5 == plVar11) {
      if ((longlong *)*plVar12 == plVar11) {
        *plVar12 = (longlong)plVar4;
        plVar12[1] = (longlong)plVar4;
      }
      else {
        plVar12[1] = plVar11[1];
      }
    }
    else if ((longlong *)*plVar12 == plVar11) {
      *plVar12 = *plVar11;
    }
    lVar7 = *plVar11;
    puVar1 = &(pLVar9->labelPtrList_).field_0x10;
    *(longlong *)puVar1 = *(longlong *)puVar1 + -1;
    *(longlong *)plVar11[1] = lVar7;
    *(longlong *)(lVar7 + 8) = plVar11[1];
    free(plVar11);
  }
  uVar10 = std::_Hash_representation<int>
                     ((_Conditionally_enabled_hash<unsigned_long,1> *)aiStackX_10);
  plVar4 = *(longlong **)&(pLVar9->clabelDefList_).field_0x8;
  plVar12 = (longlong *)
            (*(longlong *)&(pLVar9->clabelDefList_).field_0x18 +
            (uVar10 & *(ulonglong *)&(pLVar9->clabelDefList_).field_0x30) * 0x10);
  plVar5 = (longlong *)plVar12[1];
  if (plVar5 == plVar4) {
LAB_18004ace0:
    plVar11 = (longlong *)0x0;
  }
  else {
    iVar2 = (int)plVar5[2];
    plVar11 = plVar5;
    while (iVar3 != iVar2) {
      if (plVar11 == (longlong *)*plVar12) goto LAB_18004ace0;
      plVar11 = (longlong *)plVar11[1];
      iVar2 = (int)plVar11[2];
    }
  }
  if (plVar11 == (longlong *)0x0) {
    plVar11 = plVar4;
  }
  if (plVar11 != plVar4) {
    if ((int)plVar11[4] == 1) {
      plVar11 = (longlong *)0x0;
      if (plVar5 != plVar4) {
        iVar2 = (int)plVar5[2];
        plVar8 = plVar5;
        while ((plVar11 = plVar8, iVar3 != iVar2 &&
               (plVar11 = (longlong *)0x0, plVar8 != (longlong *)*plVar12))) {
          plVar8 = (longlong *)plVar8[1];
          iVar2 = (int)plVar8[2];
        }
      }
      if (plVar11 != (longlong *)0x0) {
        if (plVar5 == plVar11) {
          if ((longlong *)*plVar12 == plVar11) {
            *plVar12 = (longlong)plVar4;
            plVar12[1] = (longlong)plVar4;
          }
          else {
            plVar12[1] = plVar11[1];
          }
        }
        else if ((longlong *)*plVar12 == plVar11) {
          *plVar12 = *plVar11;
        }
        lVar7 = *plVar11;
        puVar1 = &(pLVar9->clabelDefList_).field_0x10;
        *(longlong *)puVar1 = *(longlong *)puVar1 + -1;
        *(longlong *)plVar11[1] = lVar7;
        *(longlong *)(lVar7 + 8) = plVar11[1];
        free(plVar11);
        return;
      }
    }
    else {
      *(int *)(plVar11 + 4) = (int)plVar11[4] + -1;
    }
  }
  return;
}


/* ---- 0x18004c4d0  FUN_18004c4d0  (115 bytes) ---- */

void FUN_18004c4d0(longlong param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  int iVar2;
  undefined8 *puStackX_8;
  undefined8 auStack_18 [2];
  
  iVar2 = *(int *)(param_2 + 1);
  uVar1 = *(ulonglong *)(*(longlong *)(param_1 + 0x50) + 0x40);
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0x68);
    *(int *)(param_1 + 0x68) = iVar2 + 1;
    *(int *)(param_2 + 1) = iVar2;
  }
  puStackX_8 = (undefined8 *)CONCAT44(puStackX_8._4_4_,iVar2);
  Xbyak::LabelManager::
  define_inner<std::unordered_map<int,Xbyak::LabelManager::ClabelVal,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int_const_,Xbyak::LabelManager::ClabelVal>_>_>,std::unordered_multimap<int,Xbyak::JmpLabel_const_,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int_const_,Xbyak::JmpLabel_const_>_>_>,int>
            ((LabelManager *)(param_1 + 0x50),(float *)(param_1 + 0x70),param_1 + 0xb0,
             (_Conditionally_enabled_hash<unsigned_long,1> *)&puStackX_8,uVar1);
  *param_2 = (LabelManager *)(param_1 + 0x50);
  puStackX_8 = param_2;
  std::
  _Hash<std::_Uset_traits<Xbyak::Label_*,std::_Uhash_compare<Xbyak::Label_*,std::hash<Xbyak::Label_*>,std::equal_to<Xbyak::Label_*>_>,std::allocator<Xbyak::Label_*>,0>_>
  ::emplace<Xbyak::Label_*>
            ((_Hash<std::_Uset_traits<Xbyak::Label_*,std::_Uhash_compare<Xbyak::Label_*,std::hash<Xbyak::Label_*>,std::equal_to<Xbyak::Label_*>_>,std::allocator<Xbyak::Label_*>,0>_>
              *)(param_1 + 0xf0),auStack_18,(longlong *)&puStackX_8);
  return;
}


/* ---- 0x18004e3a0  FUN_18004e3a0  (47 bytes) ---- */

ulonglong FUN_18004e3a0(longlong param_1)

{
  undefined8 *puVar1;
  
  for (puVar1 = (undefined8 *)**(undefined8 **)(param_1 + 0x58);
      puVar1 != *(undefined8 **)(param_1 + 0x58); puVar1 = (undefined8 *)*puVar1) {
    if (puVar1[0xc] != 0) goto LAB_18004e3cc;
  }
  if (*(longlong *)(param_1 + 0xc0) == 0) {
    return (ulonglong)puVar1 & 0xffffffffffffff00;
  }
LAB_18004e3cc:
  return CONCAT71((int7)((ulonglong)puVar1 >> 8),1);
}


/* ---- 0x18004e3d0  FUN_18004e3d0  (173 bytes) ---- */

void FUN_18004e3d0(CodeArray *param_1,DWORD param_2)

{
  undefined8 *puVar1;
  char cVar2;
  BOOL BVar3;
  DWORD aDStackX_10 [6];
  Error aEStack_28 [32];
  
  for (puVar1 = (undefined8 *)**(undefined8 **)(param_1 + 0x58); aDStackX_10[0] = param_2,
      puVar1 != *(undefined8 **)(param_1 + 0x58); puVar1 = (undefined8 *)*puVar1) {
    if (puVar1[0xc] != 0) goto LAB_18004e43d;
  }
  if (*(longlong *)(param_1 + 0xc0) == 0) {
    if (*(int *)(param_1 + 0x18) == 3) {
      Xbyak::CodeArray::calcJmpAddress(param_1);
      cVar2 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x18))();
      if ((cVar2 != '\0') &&
         (BVar3 = VirtualProtect(*(LPVOID *)(param_1 + 0x38),*(SIZE_T *)(param_1 + 0x30),0x40,
                                 aDStackX_10), BVar3 == 0)) {
        Xbyak::Error::Error(aEStack_28,0xe);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(aEStack_28,(ThrowInfo *)&_TI2_AVError_Xbyak__);
      }
    }
    return;
  }
LAB_18004e43d:
  Xbyak::Error::Error(aEStack_28,0xb);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(aEStack_28,(ThrowInfo *)&_TI2_AVError_Xbyak__);
}


/* ---- 0x18004e480  FUN_18004e480  (64 bytes) ---- */

undefined8 * FUN_18004e480(undefined8 *param_1,uint param_2)

{
  Xbyak::LabelManager::~LabelManager((LabelManager *)(param_1 + 10));
  Xbyak::CodeArray::~CodeArray((CodeArray *)param_1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* ---- 0x18004e4c0  FUN_18004e4c0  (31 bytes) ---- */

void FUN_18004e4c0(CodeArray *param_1)

{
  Xbyak::LabelManager::~LabelManager((LabelManager *)(param_1 + 0x50));
  Xbyak::CodeArray::~CodeArray(param_1);
  return;
}


/* ---- 0x18004e4e0  FUN_18004e4e0  (22 bytes) ---- */

undefined8 * FUN_18004e4e0(undefined8 param_1,undefined8 param_2)

{
  DAT_1801d97e0 = param_2;
  DAT_1801d97e8 = 0;
  return &DAT_1801d97e0;
}


/* ---- 0x18004e500  FUN_18004e500  (334 bytes) ---- */

void FUN_18004e500(undefined8 *param_1)

{
  char cVar1;
  longlong *this;
  longlong *plVar2;
  longlong *plVar3;
  longlong local_res8;
  longlong local_res10;
  
  if ((*(char *)(param_1 + 1) != '\0') && (this = (longlong *)*param_1, this != (longlong *)0x0)) {
    if ((this[0x10] != 0) && (plVar2 = (longlong *)this[0xf], plVar2 != (longlong *)0x0)) {
      local_res8 = this[0x11];
      local_res10 = this[0x10];
      (**(code **)(*plVar2 + 0x10))(plVar2,&local_res10,&local_res8);
    }
    std::
    _Tree<std::_Tmap_traits<unsigned___int64,enum_std::byte_*,std::less<unsigned___int64>,std::allocator<std::pair<unsigned___int64_const_,enum_std::byte_*>_>,0>_>
    ::clear(this);
    std::
    _Tree<std::_Tmap_traits<unsigned___int64,enum_std::byte_*,std::less<unsigned___int64>,std::allocator<std::pair<unsigned___int64_const_,enum_std::byte_*>_>,0>_>
    ::clear(this + 2);
    this[0x10] = 0;
    this[0x11] = 0;
    this[0x12] = 0;
    plVar2 = (longlong *)this[0xf];
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0x20))(plVar2,plVar2 != this + 8);
      this[0xf] = 0;
    }
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(this + 4));
    cVar1 = *(char *)((longlong)*(longlong **)(this[2] + 8) + 0x19);
    plVar2 = *(longlong **)(this[2] + 8);
    while (cVar1 == '\0') {
      FUN_18005cb70(this + 2,this + 2,(longlong *)plVar2[2]);
      plVar3 = (longlong *)*plVar2;
      free(plVar2);
      plVar2 = plVar3;
      cVar1 = *(char *)((longlong)plVar3 + 0x19);
    }
    free((void *)this[2]);
    cVar1 = *(char *)((longlong)*(longlong **)(*this + 8) + 0x19);
    plVar2 = *(longlong **)(*this + 8);
    while (cVar1 == '\0') {
      FUN_18005cb70(this,this,(longlong *)plVar2[2]);
      plVar3 = (longlong *)*plVar2;
      free(plVar2);
      plVar2 = plVar3;
      cVar1 = *(char *)((longlong)plVar3 + 0x19);
    }
    free((void *)*this);
    free(this);
  }
  return;
}


/* ---- 0x18004e650  FUN_18004e650  (320 bytes) ---- */

longlong * FUN_18004e650(longlong *param_1)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lStackX_8;
  longlong alStackX_18 [2];
  
  if ((param_1[0x10] != 0) && (plVar2 = (longlong *)param_1[0xf], plVar2 != (longlong *)0x0)) {
    lStackX_8 = param_1[0x11];
    alStackX_18[0] = param_1[0x10];
    (**(code **)(*plVar2 + 0x10))(plVar2,alStackX_18,&lStackX_8);
  }
  std::
  _Tree<std::_Tmap_traits<unsigned___int64,enum_std::byte_*,std::less<unsigned___int64>,std::allocator<std::pair<unsigned___int64_const_,enum_std::byte_*>_>,0>_>
  ::clear(param_1);
  std::
  _Tree<std::_Tmap_traits<unsigned___int64,enum_std::byte_*,std::less<unsigned___int64>,std::allocator<std::pair<unsigned___int64_const_,enum_std::byte_*>_>,0>_>
  ::clear(param_1 + 2);
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  plVar2 = (longlong *)param_1[0xf];
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2,plVar2 != param_1 + 8);
    param_1[0xf] = 0;
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 4));
  cVar1 = *(char *)((longlong)*(longlong **)(param_1[2] + 8) + 0x19);
  plVar2 = *(longlong **)(param_1[2] + 8);
  while (cVar1 == '\0') {
    FUN_18005cb70(param_1 + 2,param_1 + 2,(longlong *)plVar2[2]);
    plVar3 = (longlong *)*plVar2;
    free(plVar2);
    plVar2 = plVar3;
    cVar1 = *(char *)((longlong)plVar3 + 0x19);
  }
  free((void *)param_1[2]);
  cVar1 = *(char *)((longlong)*(longlong **)(*param_1 + 8) + 0x19);
  plVar2 = *(longlong **)(*param_1 + 8);
  while (cVar1 == '\0') {
    FUN_18005cb70(param_1,param_1,(longlong *)plVar2[2]);
    plVar3 = (longlong *)*plVar2;
    free(plVar2);
    plVar2 = plVar3;
    cVar1 = *(char *)((longlong)plVar3 + 0x19);
  }
  free((void *)*param_1);
  free(param_1);
  return param_1;
}


/* ---- 0x18004e790  FUN_18004e790  (74 bytes) ---- */

undefined8 * FUN_18004e790(undefined8 param_1,ulonglong param_2)

{
  DAT_1801d97e0 = SKSE::GetTrampoline();
  DAT_1801d97e8 = 0;
  SKSE__AllocTrampoline(param_2,'\x01');
  return &DAT_1801d97e0;
}


/* ---- 0x18004ee20  FUN_18004ee20  (74 bytes) ---- */

longlong FUN_18004ee20(void)

{
  longlong lVar1;
  undefined *puVar2;
  
  lVar1 = DAT_1801d9568;
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    return lVar1 + 0x180;
  }
  if (puVar2[0x118] != '\x02') {
    return lVar1;
  }
  return lVar1 + 0x114;
}


/* ---- 0x18004f490  FUN_18004f490  (74 bytes) ---- */

longlong FUN_18004f490(void)

{
  longlong lVar1;
  undefined *puVar2;
  
  lVar1 = DAT_1801d9570;
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    return lVar1 + 0x13c;
  }
  if (puVar2[0x118] != '\x02') {
    return lVar1;
  }
  return lVar1 + 0x139;
}


/* ---- 0x18004f4e0  FUN_18004f4e0  (74 bytes) ---- */

longlong FUN_18004f4e0(void)

{
  longlong lVar1;
  undefined *puVar2;
  
  lVar1 = DAT_1801d9570;
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    return lVar1 + 0x24b;
  }
  if (puVar2[0x118] != '\x02') {
    return lVar1;
  }
  return lVar1 + 0x21c;
}


/* ---- 0x18004f530  FUN_18004f530  (40 bytes) ---- */

undefined8 * FUN_18004f530(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 0xe;
  param_1[2] = hooks::hooks__AllowedToShowMapMarker;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[1] = param_2;
  return param_1;
}


/* ---- 0x18004f560  FUN_18004f560  (74 bytes) ---- */

longlong FUN_18004f560(void)

{
  longlong lVar1;
  undefined *puVar2;
  
  lVar1 = DAT_1801d9570;
  puVar2 = REL::Module::get();
  if (puVar2[0x118] == '\x01') {
    return lVar1 + 0x473;
  }
  if (puVar2[0x118] != '\x02') {
    return lVar1;
  }
  return lVar1 + 0x450;
}


/* ---- 0x18004f5b0  FUN_18004f5b0  (40 bytes) ---- */

undefined8 * FUN_18004f5b0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 0xe;
  param_1[2] = hooks__UpdateLocations;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[1] = param_2;
  return param_1;
}


/* ---- 0x18004f5e0  FUN_18004f5e0  (204 bytes) ---- */

longlong FUN_18004f5e0(void)

{
  longlong lVar1;
  char cVar2;
  undefined *puVar3;
  ulonglong uVar4;
  undefined8 local_res8;
  
  puVar3 = REL::Module::get();
  lVar1 = DAT_1801d9580;
  local_res8 = *(undefined8 *)(puVar3 + 0x108);
  uVar4 = 0;
  do {
    if (*(ushort *)((longlong)&local_res8 + uVar4) != *(ushort *)((longlong)&DAT_180191830 + uVar4))
    {
      cVar2 = '\x01';
      if (*(ushort *)((longlong)&local_res8 + uVar4) < *(ushort *)((longlong)&DAT_180191830 + uVar4)
         ) {
        cVar2 = -1;
      }
      goto LAB_18004f639;
    }
    uVar4 = uVar4 + 2;
  } while (uVar4 < 8);
  cVar2 = '\0';
LAB_18004f639:
  puVar3 = REL::Module::get();
  if (puVar3[0x118] == '\x01') {
    return lVar1 + ((longlong)cVar2 >> 0x3f & 0xffffffffffffff60U) + 0x1735;
  }
  if (puVar3[0x118] != '\x02') {
    return lVar1;
  }
  return lVar1 + 0x15ab;
}


/* ---- 0x18004f6b0  FUN_18004f6b0  (40 bytes) ---- */

undefined8 * FUN_18004f6b0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 0xe;
  param_1[2] = hooks__UpdateEnemies;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[1] = param_2;
  return param_1;
}


/* ---- 0x18004f6e0  FUN_18004f6e0  (55 bytes) ---- */

longlong FUN_18004f6e0(void)

{
  undefined *puVar1;
  
  puVar1 = REL::Module::get();
  if (puVar1[0x118] == '\x01') {
    return DAT_1801d9598 + 0xae;
  }
  return DAT_1801d9590 + 0x8d;
}


/* ---- 0x18004f720  FUN_18004f720  (40 bytes) ---- */

undefined8 * FUN_18004f720(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 0xe;
  param_1[2] = hooks__UpdatePlayerSetMarker;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[1] = param_2;
  return param_1;
}


/* ---- 0x18004f750  FUN_18004f750  (64 bytes) ---- */

undefined8 * FUN_18004f750(undefined8 *param_1,uint param_2)

{
  Xbyak::LabelManager::~LabelManager((LabelManager *)(param_1 + 10));
  Xbyak::CodeArray::~CodeArray((CodeArray *)param_1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}


/* ---- 0x18004f790  FUN_18004f790  (31 bytes) ---- */

void FUN_18004f790(CodeArray *param_1)

{
  Xbyak::LabelManager::~LabelManager((LabelManager *)(param_1 + 0x50));
  Xbyak::CodeArray::~CodeArray(param_1);
  return;
}


/* ---- 0x18004f7b0  FUN_18004f7b0  (9 bytes) ---- */

void FUN_18004f7b0(longlong param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = *(void **)(param_1 + 0x18);
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (ulonglong)(*(longlong *)(param_1 + 0x28) - (longlong)pvVar1)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
    *(longlong *)(param_1 + 0x18) = 0;
    *(undefined8 *)(param_1 + 0x20) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  return;
}


/* ---- 0x18004f7c0  FUN_18004f7c0  (9 bytes) ---- */

void FUN_18004f7c0(longlong param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = *(void **)(param_1 + 0x18);
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (ulonglong)(*(longlong *)(param_1 + 0x28) - (longlong)pvVar1)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
    *(longlong *)(param_1 + 0x18) = 0;
    *(undefined8 *)(param_1 + 0x20) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  return;
}


/* ---- 0x18004f7d0  FUN_18004f7d0  (9 bytes) ---- */

void FUN_18004f7d0(longlong param_1)

{
  FUN_1800532f0((longlong *)(param_1 + 0x18));
  return;
}


/* ---- 0x18004f7e0  FUN_18004f7e0  (9 bytes) ---- */

void FUN_18004f7e0(longlong param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = *(void **)(param_1 + 0x18);
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (ulonglong)(*(longlong *)(param_1 + 0x28) - (longlong)pvVar1)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
    *(longlong *)(param_1 + 0x18) = 0;
    *(undefined8 *)(param_1 + 0x20) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  return;
}


/* ---- 0x18004f7f0  FUN_18004f7f0  (9 bytes) ---- */

void FUN_18004f7f0(longlong param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = *(void **)(param_1 + 0x18);
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (ulonglong)(*(longlong *)(param_1 + 0x28) - (longlong)pvVar1)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
    *(longlong *)(param_1 + 0x18) = 0;
    *(undefined8 *)(param_1 + 0x20) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  return;
}


/* ---- 0x18004f800  FUN_18004f800  (9 bytes) ---- */

void FUN_18004f800(longlong param_1)

{
  void *pvVar1;
  void *_Memory;
  
  pvVar1 = *(void **)(param_1 + 0x18);
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (ulonglong)(*(longlong *)(param_1 + 0x28) - (longlong)pvVar1)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
    *(longlong *)(param_1 + 0x18) = 0;
    *(undefined8 *)(param_1 + 0x20) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  return;
}


/* ---- 0x18004fd40  FUN_18004fd40  (11 bytes) ---- */

void FUN_18004fd40(longlong *param_1)

{
  void *pvVar1;
  void *_Memory;
  
  if ((char)param_1[4] == '\0') {
    return;
  }
  if (7 < (ulonglong)param_1[3]) {
    pvVar1 = (void *)*param_1;
    _Memory = pvVar1;
    if ((0xfff < param_1[3] * 2 + 2U) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
  }
  param_1[3] = 7;
  param_1[2] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}


/* ---- 0x18004fd50  FUN_18004fd50  (11 bytes) ---- */

void FUN_18004fd50(longlong *param_1)

{
  void *pvVar1;
  void *_Memory;
  
  if ((char)param_1[4] == '\0') {
    return;
  }
  if (7 < (ulonglong)param_1[3]) {
    pvVar1 = (void *)*param_1;
    _Memory = pvVar1;
    if ((0xfff < param_1[3] * 2 + 2U) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
  }
  param_1[3] = 7;
  param_1[2] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}


/* ---- 0x18004fd60  FUN_18004fd60  (11 bytes) ---- */

void FUN_18004fd60(longlong *param_1)

{
  void *pvVar1;
  void *_Memory;
  
  if ((char)param_1[4] == '\0') {
    return;
  }
  if (7 < (ulonglong)param_1[3]) {
    pvVar1 = (void *)*param_1;
    _Memory = pvVar1;
    if ((0xfff < param_1[3] * 2 + 2U) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
  }
  param_1[3] = 7;
  param_1[2] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}


/* ---- 0x18004fd70  FUN_18004fd70  (11 bytes) ---- */

void FUN_18004fd70(longlong *param_1)

{
  void *pvVar1;
  void *_Memory;
  
  if ((char)param_1[4] == '\0') {
    return;
  }
  if (7 < (ulonglong)param_1[3]) {
    pvVar1 = (void *)*param_1;
    _Memory = pvVar1;
    if ((0xfff < param_1[3] * 2 + 2U) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
  }
  param_1[3] = 7;
  param_1[2] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}


/* ---- 0x18004fd80  FUN_18004fd80  (11 bytes) ---- */

void FUN_18004fd80(longlong *param_1)

{
  void *pvVar1;
  void *_Memory;
  
  if ((char)param_1[4] == '\0') {
    return;
  }
  if (7 < (ulonglong)param_1[3]) {
    pvVar1 = (void *)*param_1;
    _Memory = pvVar1;
    if ((0xfff < param_1[3] * 2 + 2U) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
  }
  param_1[3] = 7;
  param_1[2] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}


/* ---- 0x18004fd90  FUN_18004fd90  (11 bytes) ---- */

void FUN_18004fd90(longlong *param_1)

{
  void *pvVar1;
  void *_Memory;
  
  if ((char)param_1[4] == '\0') {
    return;
  }
  if (7 < (ulonglong)param_1[3]) {
    pvVar1 = (void *)*param_1;
    _Memory = pvVar1;
    if ((0xfff < param_1[3] * 2 + 2U) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory);
  }
  param_1[3] = 7;
  param_1[2] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}


/* ---- 0x180050740  FUN_180050740  (141 bytes) ---- */

longlong FUN_180050740(undefined8 param_1,longlong param_2)

{
  int iVar1;
  LPVOID pvVar2;
  Trampoline *this;
  void *_Dst;
  
  this = DAT_1801d97e0;
  _Dst = *(void **)(param_2 + 0x10);
  if (_Dst == (void *)0x0) {
    if (*(longlong *)(param_2 + 0x18) != *(longlong *)(param_2 + 0x20)) {
      _Dst = (void *)FUN_1800a6720((longlong)DAT_1801d97e0,
                                   *(longlong *)(param_2 + 0x20) - *(longlong *)(param_2 + 0x18));
      SKSE::Trampoline::log_stats(this);
      memcpy(_Dst,*(void **)(param_2 + 0x18),
             *(longlong *)(param_2 + 0x20) - (longlong)*(void **)(param_2 + 0x18));
      *(void **)(param_2 + 0x10) = _Dst;
    }
  }
  pvVar2 = *(LPVOID *)(param_2 + 8);
  iVar1 = *(int *)((longlong)pvVar2 + 1);
  hooks__Trampoline__write_call_6_((longlong *)DAT_1801d97e0,pvVar2,(ulonglong)_Dst,0xe9);
  return (longlong)pvVar2 + (longlong)iVar1 + 5;
}


/* ---- 0x1800507d0  FUN_1800507d0  (141 bytes) ---- */

longlong FUN_1800507d0(undefined8 param_1,longlong param_2)

{
  int iVar1;
  LPVOID pvVar2;
  Trampoline *this;
  void *_Dst;
  
  this = DAT_1801d97e0;
  _Dst = *(void **)(param_2 + 0x10);
  if (_Dst == (void *)0x0) {
    if (*(longlong *)(param_2 + 0x18) != *(longlong *)(param_2 + 0x20)) {
      _Dst = (void *)FUN_1800a6720((longlong)DAT_1801d97e0,
                                   *(longlong *)(param_2 + 0x20) - *(longlong *)(param_2 + 0x18));
      SKSE::Trampoline::log_stats(this);
      memcpy(_Dst,*(void **)(param_2 + 0x18),
             *(longlong *)(param_2 + 0x20) - (longlong)*(void **)(param_2 + 0x18));
      *(void **)(param_2 + 0x10) = _Dst;
    }
  }
  pvVar2 = *(LPVOID *)(param_2 + 8);
  iVar1 = *(int *)((longlong)pvVar2 + 1);
  hooks__Trampoline__write_call_6_((longlong *)DAT_1801d97e0,pvVar2,(ulonglong)_Dst,0xe8);
  return (longlong)pvVar2 + (longlong)iVar1 + 5;
}


/* ---- 0x1800524c0  FUN_1800524c0  (31 bytes) ---- */

longlong FUN_1800524c0(longlong *param_1,LPVOID param_2,ulonglong param_3)

{
  int iVar1;
  
  iVar1 = *(int *)((longlong)param_2 + 1);
  hooks__Trampoline__write_call_6_(param_1,param_2,param_3,0xe9);
  return (longlong)param_2 + (longlong)iVar1 + 5;
}


/* ---- 0x1800524e0  FUN_1800524e0  (31 bytes) ---- */

longlong FUN_1800524e0(longlong *param_1,LPVOID param_2,ulonglong param_3)

{
  int iVar1;
  
  iVar1 = *(int *)((longlong)param_2 + 1);
  hooks__Trampoline__write_call_6_(param_1,param_2,param_3,0xe8);
  return (longlong)param_2 + (longlong)iVar1 + 5;
}


/* ---- 0x1800549d0  FUN_1800549d0  (28 bytes) ---- */

longlong FUN_1800549d0(longlong *param_1,LPVOID param_2,ulonglong param_3,undefined1 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)((longlong)param_2 + 1);
  hooks__Trampoline__write_call_6_(param_1,param_2,param_3,param_4);
  return (longlong)param_2 + (longlong)iVar1 + 5;
}


/* ---- 0x18005e100  FUN_18005e100  (135 bytes) ---- */

undefined8 * FUN_18005e100(undefined8 *param_1,longlong param_2)

{
  undefined8 uVar1;
  
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::_System_error::vftable;
  uVar1 = *(undefined8 *)(param_2 + 0x20);
  param_1[3] = *(undefined8 *)(param_2 + 0x18);
  param_1[4] = uVar1;
  *param_1 = std::filesystem::filesystem_error::vftable;
  std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::
  basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>
            ((basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_> *)
             (param_1 + 5),(undefined8 *)(param_2 + 0x28));
  std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::
  basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>
            ((basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_> *)
             (param_1 + 9),(undefined8 *)(param_2 + 0x48));
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0xd),
             (undefined8 *)(param_2 + 0x68));
  return param_1;
}


/* ---- 0x18005e3a0  FUN_18005e3a0  (43 bytes) ---- */

uint FUN_18005e3a0(undefined2 *param_1)

{
  return ((uint)CONCAT21(*param_1,(char)param_1[1]) << 0xc | (ushort)param_1[2] & 0xfff) << 4 |
         (ushort)param_1[3] & 0xf;
}


/* ---- 0x18005e3d0  FUN_18005e3d0  (4 bytes) ---- */

undefined8 FUN_18005e3d0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18005e3e0  FUN_18005e3e0  (4 bytes) ---- */

undefined8 FUN_18005e3e0(undefined8 *param_1)

{
  return *param_1;
}


/* ---- 0x18005e3f0  FUN_18005e3f0  (16 bytes) ---- */

void FUN_18005e3f0(undefined8 *param_1,undefined8 *param_2,undefined1 *param_3)

{
                    /* WARNING: Could not recover jumptable at 0x00018005e3fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3);
  return;
}


/* ---- 0x18005e400  FUN_18005e400  (9 bytes) ---- */

void FUN_18005e400(undefined8 *param_1,undefined8 *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00018005e406. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2);
  return;
}


/* ---- 0x18005e410  FUN_18005e410  (15 bytes) ---- */

void FUN_18005e410(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3)

{
                    /* WARNING: Could not recover jumptable at 0x00018005e41c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3);
  return;
}


/* ---- 0x18005e420  FUN_18005e420  (15 bytes) ---- */

void FUN_18005e420(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
                    /* WARNING: Could not recover jumptable at 0x00018005e42c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3);
  return;
}


/* ---- 0x18005e430  FUN_18005e430  (32 bytes) ---- */

void FUN_18005e430(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined8 param_5)

{
                    /* WARNING: Could not recover jumptable at 0x00018005e44d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3,*param_4,param_5);
  return;
}


/* ---- 0x18005e450  FUN_18005e450  (15 bytes) ---- */

void FUN_18005e450(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
                    /* WARNING: Could not recover jumptable at 0x00018005e45c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3);
  return;
}


/* ---- 0x18005e460  FUN_18005e460  (55 bytes) ---- */

void FUN_18005e460(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined8 *param_5)

{
                    /* WARNING: Could not recover jumptable at 0x00018005e494. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3,*param_4,*param_5);
  return;
}


/* ---- 0x18005e4a0  FUN_18005e4a0  (55 bytes) ---- */

void FUN_18005e4a0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined8 *param_5)

{
                    /* WARNING: Could not recover jumptable at 0x00018005e4d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3,*param_4,*param_5);
  return;
}


/* ---- 0x18005e520  FUN_18005e520  (21 bytes) ---- */

void FUN_18005e520(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
                    /* WARNING: Could not recover jumptable at 0x00018005e532. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3,*param_4);
  return;
}


/* ---- 0x18005e540  FUN_18005e540  (20 bytes) ---- */

void FUN_18005e540(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4)

{
                    /* WARNING: Could not recover jumptable at 0x00018005e551. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3,*param_4);
  return;
}


/* ---- 0x18005e560  FUN_18005e560  (15 bytes) ---- */

void FUN_18005e560(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3)

{
                    /* WARNING: Could not recover jumptable at 0x00018005e56c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3);
  return;
}


/* ---- 0x18005e570  FUN_18005e570  (15 bytes) ---- */

void FUN_18005e570(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3)

{
                    /* WARNING: Could not recover jumptable at 0x00018005e57c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3);
  return;
}


/* ---- 0x18005e580  FUN_18005e580  (16 bytes) ---- */

void FUN_18005e580(undefined8 *param_1,undefined8 *param_2,undefined1 *param_3)

{
                    /* WARNING: Could not recover jumptable at 0x00018005e58d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3);
  return;
}


/* ---- 0x18005e590  FUN_18005e590  (23 bytes) ---- */

void FUN_18005e590(undefined8 *param_1,undefined8 *param_2,undefined1 *param_3,undefined1 *param_4)

{
                    /* WARNING: Could not recover jumptable at 0x00018005e5a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(*param_2,*param_3,*param_4);
  return;
}


/* ---- 0x18005e5b0  FUN_18005e5b0  (26 bytes) ---- */

longlong FUN_18005e5b0(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = FUN_18003a520(param_2,param_2,param_3);
  return lVar1 + param_1;
}


/* ---- 0x18005e5d0  FUN_18005e5d0  (26 bytes) ---- */

longlong FUN_18005e5d0(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = FUN_18003a520(param_2,param_2,param_3);
  return lVar1 + param_1;
}


/* ---- 0x18005e5f0  FUN_18005e5f0  (113 bytes) ---- */

longlong FUN_18005e5f0(undefined8 param_1,longlong param_2,longlong param_3,longlong param_4)

{
  char cVar1;
  undefined *puVar2;
  ulonglong uVar3;
  undefined8 local_res8;
  undefined8 local_res10;
  
  local_res8 = param_1;
  puVar2 = REL::Module::get();
  uVar3 = 0;
  local_res10 = *(undefined8 *)(puVar2 + 0x108);
  do {
    if (*(ushort *)((longlong)&local_res10 + uVar3) != *(ushort *)((longlong)&local_res8 + uVar3)) {
      cVar1 = '\x01';
      if (*(ushort *)((longlong)&local_res10 + uVar3) < *(ushort *)((longlong)&local_res8 + uVar3))
      {
        cVar1 = -1;
      }
      goto LAB_18005e647;
    }
    uVar3 = uVar3 + 2;
  } while (uVar3 < 8);
  cVar1 = '\0';
LAB_18005e647:
  if (cVar1 == -1) {
    param_4 = param_3;
  }
  return param_2 + param_4;
}


/* ---- 0x180064390  FUN_180064390  (7 bytes) ---- */

byte FUN_180064390(longlong param_1)

{
  return *(byte *)(param_1 + 0x40) & 1;
}


/* ---- 0x18006bb80  FUN_18006bb80  (141 bytes) ---- */

void FUN_18006bb80(undefined8 param_1)

{
  ulonglong local_28 [4];
  
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 0x14
              ) < DAT_1801d7b48) {
    _Init_thread_header(&DAT_1801d7b48);
    if (DAT_1801d7b48 == -1) {
      local_28[0] = 0x4b9a;
      local_28[1] = 0x4d45;
      local_28[2] = 0x4b9a;
      DAT_1801d7b40 = (code *)FUN_18000f860(local_28);
      _Init_thread_footer(&DAT_1801d7b48);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00018006bbbb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_1801d7b40)(param_1);
  return;
}


/* ---- 0x180083170  FUN_180083170  (61 bytes) ---- */

undefined4 * FUN_180083170(longlong param_1,undefined4 *param_2)

{
  longlong *plVar1;
  
  plVar1 = RE::ExtraDataList::GetByTypeImpl((ExtraDataList *)param_1,0x2b);
  if ((plVar1 != (longlong *)0x0) && ((undefined4 *)plVar1[2] != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)plVar1[2];
    return param_2;
  }
  *param_2 = 0;
  return param_2;
}


/* ---- 0x180087640  FUN_180087640  (173 bytes) ---- */

void FUN_180087640(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ulonglong local_28 [4];
  
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 0x14
              ) < DAT_1801d7dd0) {
    _Init_thread_header(&DAT_1801d7dd0);
    if (DAT_1801d7dd0 == -1) {
      local_28[0] = 0x338e;
      local_28[1] = 0x3420;
      local_28[2] = 0x338e;
      DAT_1801d7dc8 = (code *)FUN_18000f860(local_28);
      _Init_thread_footer(&DAT_1801d7dd0);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00018008769b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_1801d7dc8)(param_1,param_2,param_3);
  return;
}


/* ---- 0x1800878a0  FUN_1800878a0  (146 bytes) ---- */

undefined8 FUN_1800878a0(void)

{
  ulonglong local_28 [5];
  
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 0x14
              ) < DAT_1801d7da0) {
    _Init_thread_header(&DAT_1801d7da0);
    if (DAT_1801d7da0 == -1) {
      local_28[0] = 0x7e33b;
      local_28[1] = 0x627fa;
      local_28[2] = 0x7e33b;
      DAT_1801d7d98 = (undefined8 *)FUN_18000f860(local_28);
      _Init_thread_footer(&DAT_1801d7da0);
      return *DAT_1801d7d98;
    }
  }
  return *DAT_1801d7d98;
}


/* ---- 0x1800992f0  FUN_1800992f0  (146 bytes) ---- */

undefined8 FUN_1800992f0(void)

{
  ulonglong local_28 [5];
  
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 0x14
              ) < DAT_1801d8330) {
    _Init_thread_header(&DAT_1801d8330);
    if (DAT_1801d8330 == -1) {
      local_28[0] = 0x7da52;
      local_28[1] = 0x61da2;
      local_28[2] = 0x7da52;
      DAT_1801d8328 = (undefined8 *)FUN_18000f860(local_28);
      _Init_thread_footer(&DAT_1801d8330);
      return *DAT_1801d8328;
    }
  }
  return *DAT_1801d8328;
}


/* ---- 0x18009bd60  FUN_18009bd60  (157 bytes) ---- */

undefined4 * FUN_18009bd60(longlong param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  logger *this;
  char *local_58;
  undefined8 local_50;
  char *local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char *local_38;
  char *local_28;
  undefined8 uStack_20;
  char *local_18;
  
  puVar2 = (undefined4 *)FUN_18009b1b0(param_1,param_2);
  if ((puVar2 != (undefined4 *)0x0) && (uVar1 = FUN_18009b780(puVar2), 2 < uVar1)) {
    this = spdlog::default_logger_raw();
    uStack_40 = 0x47;
    local_48 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_3c = uStack_20._4_4_;
    uStack_20 = CONCAT44(uStack_20._4_4_,0x47);
    local_50 = 0x23;
    local_38 = 
    "class SKSE::MessagingInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::MessagingInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    local_58 = "interface definition is out of date";
    local_28 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    local_18 = 
    "class SKSE::MessagingInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::MessagingInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)this,&local_28,3,(ulonglong *)&local_58);
  }
  return puVar2;
}


/* ---- 0x18009be00  FUN_18009be00  (157 bytes) ---- */

undefined4 * FUN_18009be00(longlong param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  logger *this;
  char *local_58;
  undefined8 local_50;
  char *local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char *local_38;
  char *local_28;
  undefined8 uStack_20;
  char *local_18;
  
  puVar2 = (undefined4 *)FUN_18009b1b0(param_1,param_2);
  if ((puVar2 != (undefined4 *)0x0) && (uVar1 = FUN_18009b790(puVar2), 1 < uVar1)) {
    this = spdlog::default_logger_raw();
    uStack_40 = 0x47;
    local_48 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_3c = uStack_20._4_4_;
    uStack_20 = CONCAT44(uStack_20._4_4_,0x47);
    local_50 = 0x23;
    local_38 = 
    "class SKSE::ObjectInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::ObjectInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    local_58 = "interface definition is out of date";
    local_28 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    local_18 = 
    "class SKSE::ObjectInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::ObjectInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)this,&local_28,3,(ulonglong *)&local_58);
  }
  return puVar2;
}


/* ---- 0x18009bea0  FUN_18009bea0  (157 bytes) ---- */

undefined4 * FUN_18009bea0(longlong param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  logger *this;
  char *local_58;
  undefined8 local_50;
  char *local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char *local_38;
  char *local_28;
  undefined8 uStack_20;
  char *local_18;
  
  puVar2 = (undefined4 *)FUN_18009b1b0(param_1,param_2);
  if ((puVar2 != (undefined4 *)0x0) && (uVar1 = FUN_18009b7a0(puVar2), 1 < uVar1)) {
    this = spdlog::default_logger_raw();
    uStack_40 = 0x47;
    local_48 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_3c = uStack_20._4_4_;
    uStack_20 = CONCAT44(uStack_20._4_4_,0x47);
    local_50 = 0x23;
    local_38 = 
    "class SKSE::PapyrusInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::PapyrusInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    local_58 = "interface definition is out of date";
    local_28 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    local_18 = 
    "class SKSE::PapyrusInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::PapyrusInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)this,&local_28,3,(ulonglong *)&local_58);
  }
  return puVar2;
}


/* ---- 0x18009bf40  FUN_18009bf40  (157 bytes) ---- */

undefined4 * FUN_18009bf40(longlong param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  logger *this;
  char *local_58;
  undefined8 local_50;
  char *local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char *local_38;
  char *local_28;
  undefined8 uStack_20;
  char *local_18;
  
  puVar2 = (undefined4 *)FUN_18009b1b0(param_1,param_2);
  if ((puVar2 != (undefined4 *)0x0) && (uVar1 = FUN_18009b7b0(puVar2), 2 < uVar1)) {
    this = spdlog::default_logger_raw();
    uStack_40 = 0x47;
    local_48 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_3c = uStack_20._4_4_;
    uStack_20 = CONCAT44(uStack_20._4_4_,0x47);
    local_50 = 0x23;
    local_38 = 
    "class SKSE::ScaleformInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::ScaleformInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    local_58 = "interface definition is out of date";
    local_28 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    local_18 = 
    "class SKSE::ScaleformInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::ScaleformInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)this,&local_28,3,(ulonglong *)&local_58);
  }
  return puVar2;
}


/* ---- 0x18009bfe0  FUN_18009bfe0  (157 bytes) ---- */

undefined4 * FUN_18009bfe0(longlong param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  logger *this;
  char *local_58;
  undefined8 local_50;
  char *local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char *local_38;
  char *local_28;
  undefined8 uStack_20;
  char *local_18;
  
  puVar2 = (undefined4 *)FUN_18009b1b0(param_1,param_2);
  if ((puVar2 != (undefined4 *)0x0) && (uVar1 = FUN_18009b7c0(puVar2), 4 < uVar1)) {
    this = spdlog::default_logger_raw();
    uStack_40 = 0x47;
    local_48 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_3c = uStack_20._4_4_;
    uStack_20 = CONCAT44(uStack_20._4_4_,0x47);
    local_50 = 0x23;
    local_38 = 
    "class SKSE::SerializationInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::SerializationInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    local_58 = "interface definition is out of date";
    local_28 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    local_18 = 
    "class SKSE::SerializationInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::SerializationInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)this,&local_28,3,(ulonglong *)&local_58);
  }
  return puVar2;
}


/* ---- 0x18009c080  FUN_18009c080  (157 bytes) ---- */

undefined4 * FUN_18009c080(longlong param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  logger *this;
  char *local_58;
  undefined8 local_50;
  char *local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char *local_38;
  char *local_28;
  undefined8 uStack_20;
  char *local_18;
  
  puVar2 = (undefined4 *)FUN_18009b1b0(param_1,param_2);
  if ((puVar2 != (undefined4 *)0x0) && (uVar1 = FUN_18009b7d0(puVar2), 2 < uVar1)) {
    this = spdlog::default_logger_raw();
    uStack_40 = 0x47;
    local_48 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_3c = uStack_20._4_4_;
    uStack_20 = CONCAT44(uStack_20._4_4_,0x47);
    local_50 = 0x23;
    local_38 = 
    "class SKSE::TaskInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::TaskInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    local_58 = "interface definition is out of date";
    local_28 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    local_18 = 
    "class SKSE::TaskInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::TaskInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)this,&local_28,3,(ulonglong *)&local_58);
  }
  return puVar2;
}


/* ---- 0x18009c120  FUN_18009c120  (157 bytes) ---- */

undefined4 * FUN_18009c120(longlong param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  logger *this;
  char *local_58;
  undefined8 local_50;
  char *local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char *local_38;
  char *local_28;
  undefined8 uStack_20;
  char *local_18;
  
  puVar2 = (undefined4 *)FUN_18009b1b0(param_1,param_2);
  if ((puVar2 != (undefined4 *)0x0) && (uVar1 = FUN_18009b7e0(puVar2), 1 < uVar1)) {
    this = spdlog::default_logger_raw();
    uStack_40 = 0x47;
    local_48 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_3c = uStack_20._4_4_;
    uStack_20 = CONCAT44(uStack_20._4_4_,0x47);
    local_50 = 0x23;
    local_38 = 
    "class SKSE::TrampolineInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::TrampolineInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    local_58 = "interface definition is out of date";
    local_28 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    local_18 = 
    "class SKSE::TrampolineInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::TrampolineInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)this,&local_28,3,(ulonglong *)&local_58);
  }
  return puVar2;
}


/* ---- 0x1800a1b30  SKSE::AllocTrampoline  (134 bytes) ---- */

void SKSE__AllocTrampoline(ulonglong param_1,char param_2)

{
  longlong *plVar1;
  undefined *puVar2;
  void *pvVar3;
  longlong local_48 [7];
  undefined8 local_10;
  
  plVar1 = SKSE::GetTrampoline();
  puVar2 = SKSE::detail::APIStorage::get();
  if ((*(longlong *)(puVar2 + 0x50) != 0) && (param_2 != '\0')) {
    pvVar3 = (void *)FUN_18009ae30(*(longlong *)(puVar2 + 0x50),param_1);
    if (pvVar3 != (void *)0x0) {
      local_10 = 0;
      FUN_1800a3320(plVar1,pvVar3,param_1,local_48);
      return;
    }
  }
  FUN_1800a64a0(plVar1,param_1,0);
  return;
}


/* ---- 0x1800a1c70  FUN_1800a1c70  (18 bytes) ---- */

undefined8 FUN_1800a1c70(void)

{
  undefined *puVar1;
  
  puVar1 = SKSE::detail::APIStorage::get();
  return *(undefined8 *)(puVar1 + 0x58);
}


/* ---- 0x1800a1ee0  FUN_1800a1ee0  (1842 bytes) ---- */

void FUN_1800a1ee0(longlong param_1,char param_2)

{
  vector<std::function<void___cdecl(void)>,std::allocator<std::function<void___cdecl(void)>_>_>
  *this;
  function<void___cdecl(void)> *pfVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  size_t sVar8;
  undefined *puVar9;
  undefined8 *puVar10;
  logger *plVar11;
  undefined4 *puVar12;
  undefined8 uVar13;
  void *pvVar14;
  function<void___cdecl(void)> *pfVar15;
  ulonglong uVar16;
  function<void___cdecl(void)> *pfVar17;
  undefined1 auStackY_c8 [32];
  char *local_98;
  undefined8 uStack_90;
  char *local_88;
  char *local_78;
  undefined8 uStack_70;
  char *local_68;
  undefined8 uStack_60;
  char *local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (param_1 == 0) {
    local_98 = (char *)0x900000050;
    uStack_90 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    local_88 = "void __cdecl SKSE::Init(const class SKSE::LoadInterface *,const bool) noexcept";
    puVar6 = FUN_1800355c0(&local_48,"interface is null",0x11);
    local_78 = (char *)*puVar6;
    uStack_70 = puVar6[1];
                    /* WARNING: Subroutine does not return */
    SKSE::stl::report_and_fail((longlong *)&local_78,(longlong *)&local_98);
  }
  REL::Module::get();
  REL::IDDatabase::get();
  puVar6 = (undefined8 *)SKSE::detail::APIStorage::get();
  iVar3 = _Mtx_lock(puVar6 + 0x15);
  if (iVar3 != 0) {
    std::_Throw_Cpp_error(5);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(int *)((longlong)puVar6 + 0xf4) == 0x7fffffff) {
    *(undefined4 *)((longlong)puVar6 + 0xf4) = 0x7ffffffe;
    std::_Throw_Cpp_error(6);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  lVar7 = FUN_18009b170();
  if (lVar7 != 0) {
    sVar8 = strlen((char *)(lVar7 + 8));
    *puVar6 = (char *)(lVar7 + 8);
    puVar6[1] = sVar8;
    sVar8 = strlen((char *)(lVar7 + 0x108));
    puVar6[2] = (char *)(lVar7 + 0x108);
    puVar6[3] = sVar8;
    uVar5 = *(uint *)(lVar7 + 4);
    local_38 = CONCAT26((short)uVar5,
                        CONCAT24((short)(uVar5 >> 4),
                                 CONCAT22((short)(uVar5 >> 0x10),(ushort)(byte)(uVar5 >> 0x18)))) &
               0xf0fff00ffffff;
    puVar6[4] = local_38;
  }
  if (param_2 != '\0') {
    FUN_1800ad130();
    puVar9 = SKSE::detail::APIStorage::get();
    local_38 = *(ulonglong *)(puVar9 + 0x20);
    puVar10 = (undefined8 *)SKSE::detail::APIStorage::get();
    local_48 = *puVar10;
    uStack_40 = puVar10[1];
    plVar11 = spdlog::default_logger_raw();
    local_98 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_90 = (char *)CONCAT44(uStack_60._4_4_,99);
    local_88 = "void __cdecl SKSE::Init(const class SKSE::LoadInterface *,const bool) noexcept";
    local_78 = "{} v{}";
    uStack_70 = 6;
    local_68 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_60 = uStack_90;
    local_58 = "void __cdecl SKSE::Init(const class SKSE::LoadInterface *,const bool) noexcept";
    FUN_18009e7d0(&plVar11->_padding_,&local_68,2,&local_78,&local_48,&local_38);
  }
  if (*(char *)(puVar6 + 0x22) != '\0') goto LAB_1800a2569;
  uVar4 = FUN_18009b0a0(param_1);
  *(undefined4 *)(puVar6 + 5) = uVar4;
  uVar4 = FUN_18009b140(param_1);
  *(undefined4 *)((longlong)puVar6 + 0x2c) = uVar4;
  puVar12 = (undefined4 *)FUN_18009b1b0(param_1,1);
  if ((puVar12 != (undefined4 *)0x0) && (uVar5 = FUN_18009b7b0(puVar12), 2 < uVar5)) {
    plVar11 = spdlog::default_logger_raw();
    local_98 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_90 = (char *)CONCAT44(uStack_60._4_4_,0x47);
    local_88 = 
    "class SKSE::ScaleformInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::ScaleformInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    local_78 = "interface definition is out of date";
    uStack_70 = 0x23;
    local_68 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_60 = uStack_90;
    local_58 = 
    "class SKSE::ScaleformInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::ScaleformInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)plVar11,&local_68,3,(ulonglong *)&local_78);
  }
  puVar6[6] = puVar12;
  puVar12 = (undefined4 *)FUN_18009b1b0(param_1,2);
  if ((puVar12 != (undefined4 *)0x0) && (uVar5 = FUN_18009b7a0(puVar12), 1 < uVar5)) {
    plVar11 = spdlog::default_logger_raw();
    local_98 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_90 = (char *)CONCAT44(uStack_60._4_4_,0x47);
    local_88 = 
    "class SKSE::PapyrusInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::PapyrusInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    local_78 = "interface definition is out of date";
    uStack_70 = 0x23;
    local_68 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_60 = uStack_90;
    local_58 = 
    "class SKSE::PapyrusInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::PapyrusInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)plVar11,&local_68,3,(ulonglong *)&local_78);
  }
  puVar6[7] = puVar12;
  puVar12 = (undefined4 *)FUN_18009b1b0(param_1,3);
  if ((puVar12 != (undefined4 *)0x0) && (uVar5 = FUN_18009b7c0(puVar12), 4 < uVar5)) {
    plVar11 = spdlog::default_logger_raw();
    local_98 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_90 = (char *)CONCAT44(uStack_60._4_4_,0x47);
    local_88 = 
    "class SKSE::SerializationInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::SerializationInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    local_78 = "interface definition is out of date";
    uStack_70 = 0x23;
    local_68 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_60 = uStack_90;
    local_58 = 
    "class SKSE::SerializationInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::SerializationInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)plVar11,&local_68,3,(ulonglong *)&local_78);
  }
  puVar6[8] = puVar12;
  puVar12 = (undefined4 *)FUN_18009b1b0(param_1,4);
  if ((puVar12 != (undefined4 *)0x0) && (uVar5 = FUN_18009b7d0(puVar12), 2 < uVar5)) {
    plVar11 = spdlog::default_logger_raw();
    local_98 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_90 = (char *)CONCAT44(uStack_60._4_4_,0x47);
    local_88 = 
    "class SKSE::TaskInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::TaskInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    local_78 = "interface definition is out of date";
    uStack_70 = 0x23;
    local_68 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_60 = uStack_90;
    local_58 = 
    "class SKSE::TaskInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::TaskInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)plVar11,&local_68,3,(ulonglong *)&local_78);
  }
  puVar6[9] = puVar12;
  puVar12 = (undefined4 *)FUN_18009b1b0(param_1,7);
  if ((puVar12 != (undefined4 *)0x0) && (uVar5 = FUN_18009b7e0(puVar12), 1 < uVar5)) {
    plVar11 = spdlog::default_logger_raw();
    local_98 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_90 = (char *)CONCAT44(uStack_60._4_4_,0x47);
    local_88 = 
    "class SKSE::TrampolineInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::TrampolineInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    local_78 = "interface definition is out of date";
    uStack_70 = 0x23;
    local_68 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_60 = uStack_90;
    local_58 = 
    "class SKSE::TrampolineInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::TrampolineInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)plVar11,&local_68,3,(ulonglong *)&local_78);
  }
  puVar6[10] = puVar12;
  puVar12 = (undefined4 *)FUN_18009b1b0(param_1,5);
  if ((puVar12 == (undefined4 *)0x0) || (uVar5 = FUN_18009b780(puVar12), uVar5 < 3)) {
    puVar6[0xb] = puVar12;
    if (puVar12 != (undefined4 *)0x0) goto LAB_1800a237b;
  }
  else {
    plVar11 = spdlog::default_logger_raw();
    local_98 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_90 = (char *)CONCAT44(uStack_60._4_4_,0x47);
    local_88 = 
    "class SKSE::MessagingInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::MessagingInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    local_78 = "interface definition is out of date";
    uStack_70 = 0x23;
    local_68 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_60 = uStack_90;
    local_58 = 
    "class SKSE::MessagingInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::MessagingInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)plVar11,&local_68,3,(ulonglong *)&local_78);
    puVar6[0xb] = puVar12;
LAB_1800a237b:
    uVar13 = FUN_18009b050((longlong)puVar12,0);
    puVar6[0xc] = uVar13;
    uVar13 = FUN_18009b050(puVar6[0xb],1);
    puVar6[0xd] = uVar13;
    uVar13 = FUN_18009b050(puVar6[0xb],2);
    puVar6[0xe] = uVar13;
    uVar13 = FUN_18009b050(puVar6[0xb],3);
    puVar6[0xf] = uVar13;
    uVar13 = FUN_18009b050(puVar6[0xb],4);
    puVar6[0x10] = uVar13;
  }
  puVar12 = (undefined4 *)FUN_18009b1b0(param_1,6);
  if ((puVar12 == (undefined4 *)0x0) || (uVar5 = FUN_18009b790(puVar12), uVar5 < 2)) {
    puVar6[0x11] = puVar12;
    if (puVar12 != (undefined4 *)0x0) goto LAB_1800a2460;
  }
  else {
    plVar11 = spdlog::default_logger_raw();
    local_98 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_90 = (char *)CONCAT44(uStack_60._4_4_,0x47);
    local_88 = 
    "class SKSE::ObjectInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::ObjectInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    local_78 = "interface definition is out of date";
    uStack_70 = 0x23;
    local_68 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\API.cpp"
    ;
    uStack_60 = uStack_90;
    local_58 = 
    "class SKSE::ObjectInterface *__cdecl SKSE::detail::QueryInterface<class SKSE::ObjectInterface>(const class SKSE::LoadInterface *,unsigned int)"
    ;
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)plVar11,&local_68,3,(ulonglong *)&local_78);
    puVar6[0x11] = puVar12;
LAB_1800a2460:
    uVar13 = FUN_18009b040((longlong)puVar12);
    puVar6[0x12] = uVar13;
    uVar13 = FUN_18009b080((longlong)puVar12);
    puVar6[0x13] = uVar13;
    uVar13 = FUN_18009b090((longlong)puVar12);
    puVar6[0x14] = uVar13;
  }
  *(undefined1 *)(puVar6 + 0x22) = 1;
  this = (vector<std::function<void___cdecl(void)>,std::allocator<std::function<void___cdecl(void)>_>_>
          *)(puVar6 + 0x1f);
  pfVar17 = (function<void___cdecl(void)> *)puVar6[0x20];
  for (pfVar15 = (this->_Mypair)._Myval2._Myfirst; pfVar15 != pfVar17; pfVar15 = pfVar15 + 1) {
    if (*(longlong **)&pfVar15->field_0x38 == (longlong *)0x0) {
      std::_Xbad_function_call();
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    (**(code **)(**(longlong **)&pfVar15->field_0x38 + 0x10))();
  }
  pfVar15 = (function<void___cdecl(void)> *)puVar6[0x20];
  pfVar17 = (this->_Mypair)._Myval2._Myfirst;
  if (pfVar17 != pfVar15) {
    do {
      pfVar1 = *(function<void___cdecl(void)> **)&pfVar17->field_0x38;
      if (pfVar1 != (function<void___cdecl(void)> *)0x0) {
        (**(code **)(*(longlong *)pfVar1 + 0x20))(pfVar1,pfVar1 != pfVar17);
        *(undefined8 *)&pfVar17->field_0x38 = 0;
      }
      pfVar17 = pfVar17 + 1;
    } while (pfVar17 != pfVar15);
    pfVar15 = (this->_Mypair)._Myval2._Myfirst;
    puVar6[0x20] = pfVar15;
  }
  if (pfVar15 != (function<void___cdecl(void)> *)puVar6[0x21]) {
    pfVar17 = (this->_Mypair)._Myval2._Myfirst;
    if (pfVar17 == pfVar15) {
      std::
      vector<std::function<void___cdecl(void)>,std::allocator<std::function<void___cdecl(void)>_>_>
      ::_Tidy(this);
    }
    else {
      uVar16 = (longlong)pfVar15 - (longlong)pfVar17 >> 6;
      if (0x3ffffffffffffff < uVar16) {
        FUN_180039810();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      pvVar14 = std::_Allocate<16,std::_Default_allocate_traits>(uVar16 << 6);
      std::
      _Uninitialized_move<std::function<void___cdecl(void)>_*,std::allocator<std::function<void___cdecl(void)>_>_>
                ((undefined8 *)(this->_Mypair)._Myval2._Myfirst,(undefined8 *)puVar6[0x20],
                 (longlong)pvVar14);
      std::
      vector<std::function<void___cdecl(void)>,std::allocator<std::function<void___cdecl(void)>_>_>
      ::_Change_array(this,(longlong)pvVar14,uVar16,uVar16);
    }
  }
LAB_1800a2569:
  _Mtx_unlock(puVar6 + 0x15);
  __security_check_cookie(local_30 ^ (ulonglong)auStackY_c8);
  return;
}


/* ---- 0x1800a3e10  FUN_1800a3e10  (22 bytes) ---- */

undefined1 * FUN_1800a3e10(ulonglong *param_1)

{
  if ((*param_1 & 0xfffffffffffffffc) != 0) {
    return (undefined1 *)((*param_1 & 0xfffffffffffffffc) + 0xc);
  }
  return &s_;
}


/* ---- 0x1800a42d0  FUN_1800a42d0  (5 bytes) ---- */

undefined1 FUN_1800a42d0(longlong param_1)

{
  return *(undefined1 *)(param_1 + 8);
}


/* ---- 0x1800a4300  FUN_1800a4300  (6 bytes) ---- */

undefined4 FUN_1800a4300(longlong param_1)

{
  return *(undefined4 *)(param_1 + 8);
}


/* ---- 0x1800a4310  FUN_1800a4310  (19 bytes) ---- */

undefined1 * FUN_1800a4310(longlong param_1)

{
  undefined1 *puVar1;
  
  puVar1 = &s_;
  if (*(undefined1 **)(param_1 + 0x10) != (undefined1 *)0x0) {
    puVar1 = *(undefined1 **)(param_1 + 0x10);
  }
  return puVar1;
}


/* ---- 0x1800a4400  FUN_1800a4400  (4 bytes) ---- */

undefined4 FUN_1800a4400(longlong param_1)

{
  return *(undefined4 *)(param_1 + 8);
}


/* ---- 0x1800a4e00  FUN_1800a4e00  (299 bytes) ---- */

undefined8 *
FUN_1800a4e00(longlong *param_1,undefined8 *param_2,ulonglong *param_3,longlong *param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined1 uVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *local_48;
  undefined8 uStack_40;
  longlong *local_38;
  uint uStack_30;
  undefined4 uStack_2c;
  
  plVar1 = (longlong *)*param_1;
  local_38 = (longlong *)plVar1[1];
  uStack_30 = 0;
  plVar5 = plVar1;
  if (*(char *)((longlong)local_38 + 0x19) == '\0') {
    plVar2 = local_38;
    plVar6 = plVar1;
    do {
      local_38 = plVar2;
      plVar4 = local_38;
      plVar5 = local_38;
      if ((ulonglong)local_38[4] < *param_3) {
        plVar4 = local_38 + 2;
        plVar5 = plVar6;
      }
      uStack_30 = (uint)(*param_3 <= (ulonglong)local_38[4]);
      plVar2 = (longlong *)*plVar4;
      plVar6 = plVar5;
    } while (*(char *)(*plVar4 + 0x19) == '\0');
  }
  if ((*(char *)((longlong)plVar5 + 0x19) == '\0') && ((ulonglong)plVar5[4] <= *param_3)) {
    uVar3 = 0;
  }
  else {
    if (param_1[1] == 0x555555555555555) {
                    /* WARNING: Subroutine does not return */
      std::_Throw_tree_length_error();
    }
    uStack_40 = 0;
    local_48 = param_1;
    plVar5 = (longlong *)operator_new(0x30);
    plVar5[4] = *param_3;
    plVar5[5] = *param_4;
    *plVar5 = (longlong)plVar1;
    plVar5[1] = (longlong)plVar1;
    plVar5[2] = (longlong)plVar1;
    *(undefined2 *)(plVar5 + 3) = 0;
    uStack_40 = CONCAT44(uStack_2c,uStack_30);
    local_48 = local_38;
    plVar5 = FUN_1800a60b0(param_1,(longlong *)&local_48,plVar5);
    uVar3 = 1;
  }
  *param_2 = plVar5;
  *(undefined1 *)(param_2 + 1) = uVar3;
  return param_2;
}


/* ---- 0x1800a6720  FUN_1800a6720  (139 bytes) ---- */

longlong FUN_1800a6720(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong local_48;
  longlong lStack_40;
  undefined8 local_38 [2];
  undefined4 local_28;
  undefined4 local_24;
  char *local_20;
  char *local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x90);
  if (param_2 <= (ulonglong)(*(longlong *)(param_1 + 0x88) - lVar1)) {
    *(ulonglong *)(param_1 + 0x90) = lVar1 + param_2;
    return *(longlong *)(param_1 + 0x80) + lVar1;
  }
  local_28 = 0x75;
  local_20 = 
  "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\Trampoline.cpp"
  ;
  local_24 = 9;
  local_18 = "void *__cdecl SKSE::Trampoline::do_allocate(unsigned __int64)";
  plVar2 = FUN_1800355c0(local_38,"Failed to handle allocation request",0x23);
  local_48 = *plVar2;
  lStack_40 = plVar2[1];
                    /* WARNING: Subroutine does not return */
  SKSE::stl::report_and_fail(&local_48,(longlong *)&local_28);
}


/* ---- 0x1800ad7a0  FUN_1800ad7a0  (772 bytes) ---- */

void FUN_1800ad7a0(ulonglong *param_1)

{
  wchar_t *pv;
  bool bVar1;
  int iVar2;
  size_t sVar3;
  undefined *puVar4;
  logger *this;
  char **ppcVar5;
  uint uVar6;
  char *_Str;
  undefined1 auStack_f8 [32];
  char *local_d8;
  size_t local_d0;
  uint local_c8;
  wchar_t *local_c0;
  code *local_b8;
  wchar_t *local_b0;
  char *local_a8 [2];
  char *local_98;
  ulonglong local_88;
  ulonglong uStack_80;
  ulonglong local_78;
  ulonglong uStack_70;
  char *local_68;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  char *local_58;
  char *local_48 [4];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_f8;
  local_c8 = 0;
  local_c0 = (wchar_t *)0x0;
  iVar2 = FUN_180061920(&FOLDERID_Documents.Data1);
  pv = local_c0;
  local_b8 = CoTaskMemFree;
  local_b0 = local_c0;
  if ((local_c0 == (wchar_t *)0x0) || (iVar2 != 0)) {
    this = spdlog::default_logger_raw();
    local_68 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\Logger.cpp"
    ;
    uStack_60 = 0x4d;
    uStack_5c = local_a8[1]._4_4_;
    local_58 = 
    "class std::optional<class std::filesystem::path> __cdecl SKSE::log::log_directory(void)";
    local_d8 = "failed to get known folder path";
    local_d0 = 0x1f;
    local_a8[1]._0_4_ = 0x4d;
    local_a8[0] = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\Logger.cpp"
    ;
    local_98 = 
    "class std::optional<class std::filesystem::path> __cdecl SKSE::log::log_directory(void)";
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)this,local_a8,4,(ulonglong *)&local_d8);
    *(undefined1 *)(param_1 + 4) = 0;
  }
  else {
    sVar3 = wcslen(local_c0);
    local_88 = 0;
    uStack_80 = 0;
    local_78 = 0;
    uStack_70 = 0;
    std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::
    _Construct<1,wchar_t_const_*>
              ((basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_> *)&local_88
               ,pv,sVar3);
    local_d8 = "My Games";
    local_d0 = 8;
    std::filesystem::_Convert_stringoid_to_wide<std::filesystem::_Normal_conversion>
              ((LPWSTR)local_a8,&local_d8);
    std::filesystem::path::operator/=((path *)&local_88,(undefined1 (*) [32])local_a8);
    FUN_180024060((longlong *)local_a8);
    puVar4 = REL::Module::get();
    if (puVar4[0x118] == '\x04') {
      local_d8 = "Skyrim VR";
      local_d0 = 9;
      std::filesystem::_Convert_stringoid_to_wide<std::filesystem::_Normal_conversion>
                ((LPWSTR)local_a8,&local_d8);
      std::filesystem::path::operator/=((path *)&local_88,(undefined1 (*) [32])local_a8);
      ppcVar5 = local_a8;
    }
    else {
      local_d8 = "steam_api64.dll";
      local_d0 = 0xf;
      std::filesystem::_Convert_stringoid_to_wide<std::filesystem::_Normal_conversion>
                ((LPWSTR)local_48,&local_d8);
      uVar6 = 0x9c;
      local_c8 = 0x9c;
      bVar1 = std::filesystem::exists((LPCWSTR)local_48);
      if (bVar1) {
        local_d8 = "openvr_api.dll";
        local_d0 = 0xe;
        std::filesystem::_Convert_stringoid_to_wide<std::filesystem::_Normal_conversion>
                  ((LPWSTR)&local_68,&local_d8);
        uVar6 = 0x29e;
        local_c8 = 0x29e;
        bVar1 = std::filesystem::exists((LPCWSTR)&local_68);
        _Str = "Skyrim Special Edition";
        if (bVar1) {
          _Str = "Skyrim VR";
        }
      }
      else {
        _Str = "Skyrim Special Edition GOG";
      }
      local_d0 = strlen(_Str);
      local_d8 = _Str;
      std::filesystem::_Convert_stringoid_to_wide<std::filesystem::_Normal_conversion>
                ((LPWSTR)local_a8,&local_d8);
      local_c8 = uVar6 | 0x100;
      std::filesystem::path::operator/=((path *)&local_88,(undefined1 (*) [32])local_a8);
      FUN_180024060((longlong *)local_a8);
      if ((uVar6 & 2) != 0) {
        FUN_180024060((longlong *)&local_68);
      }
      ppcVar5 = local_48;
    }
    FUN_180024060((longlong *)ppcVar5);
    local_d8 = "SKSE";
    local_d0 = 4;
    std::filesystem::_Convert_stringoid_to_wide<std::filesystem::_Normal_conversion>
              ((LPWSTR)local_48,&local_d8);
    std::filesystem::path::operator/=((path *)&local_88,(undefined1 (*) [32])local_48);
    FUN_180024060((longlong *)local_48);
    *param_1 = local_88;
    param_1[1] = uStack_80;
    param_1[2] = local_78;
    param_1[3] = uStack_70;
    *(undefined1 *)(param_1 + 4) = 1;
    local_78 = 0;
    uStack_70 = 7;
    local_88 = local_88 & 0xffffffffffff0000;
  }
  if (pv != (wchar_t *)0x0) {
    CoTaskMemFree(pv);
  }
  __security_check_cookie(local_28 ^ (ulonglong)auStack_f8);
  return;
}


/* ---- 0x1800cc3a0  FUN_1800cc3a0  (227 bytes) ---- */

void FUN_1800cc3a0(undefined8 param_1,longlong param_2,byte param_3,byte param_4)

{
  longlong lVar1;
  logger *this;
  char *local_58;
  undefined8 local_50;
  char *local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char *local_38;
  char *local_28;
  undefined8 uStack_20;
  char *local_18;
  
  if (param_2 == 0) {
    this = spdlog::default_logger_raw();
    uStack_40 = 0xe6;
    local_48 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\RE\\T\\TESFaction.cpp"
    ;
    uStack_3c = uStack_20._4_4_;
    uStack_20 = CONCAT44(uStack_20._4_4_,0xe6);
    local_50 = 0x23;
    local_38 = "void __cdecl RE::TESFaction::SetAlly(class RE::TESFaction *,bool,bool)";
    local_58 = "Cannot be an ally of a NONE faction";
    local_28 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\RE\\T\\TESFaction.cpp"
    ;
    local_18 = "void __cdecl RE::TESFaction::SetAlly(class RE::TESFaction *,bool,bool)";
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)this,&local_28,1,(ulonglong *)&local_58);
  }
  else {
    FUN_1800cc600(param_1,param_2,param_3 + 2);
    FUN_1800cc600(param_2,param_1,param_4 + 2);
    lVar1 = FUN_1800cedd0();
    if (lVar1 != 0) {
      FUN_1800ce790(lVar1);
      return;
    }
  }
  return;
}


/* ---- 0x1800cc510  FUN_1800cc510  (230 bytes) ---- */

void FUN_1800cc510(undefined8 param_1,longlong param_2,byte param_3,byte param_4)

{
  longlong lVar1;
  logger *this;
  char *local_58;
  undefined8 local_50;
  char *local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char *local_38;
  char *local_28;
  undefined8 uStack_20;
  char *local_18;
  
  if (param_2 == 0) {
    this = spdlog::default_logger_raw();
    uStack_40 = 0x104;
    local_48 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\RE\\T\\TESFaction.cpp"
    ;
    uStack_3c = uStack_20._4_4_;
    uStack_20 = CONCAT44(uStack_20._4_4_,0x104);
    local_50 = 0x23;
    local_38 = "void __cdecl RE::TESFaction::SetEnemy(class RE::TESFaction *,bool,bool)";
    local_58 = "Cannot be an ally of a NONE faction";
    local_28 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\RE\\T\\TESFaction.cpp"
    ;
    local_18 = "void __cdecl RE::TESFaction::SetEnemy(class RE::TESFaction *,bool,bool)";
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)this,&local_28,1,(ulonglong *)&local_58);
  }
  else {
    FUN_1800cc600(param_1,param_2,param_3 ^ 1);
    FUN_1800cc600(param_2,param_1,param_4 ^ 1);
    lVar1 = FUN_1800cedd0();
    if (lVar1 != 0) {
      FUN_1800ce790(lVar1);
      return;
    }
  }
  return;
}


/* ---- 0x180154130  atexit  (23 bytes)   [名称未经人工确认] ---- */

/* Library Function - Single Match
    atexit
   
   Library: Visual Studio 2019 Release */

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}


