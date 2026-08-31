/* ============================================================
 * Hooks.c  ——  CompassNavigationOverhaul 2.9.9 反编译产物
 * 由 Ghidra 11.3.2 反编译器从 SKSE/Plugins/CompassNavigationOverhaul.dll 导出。
 * 函数名来自 2.2.0-VR 版 PDB 的跨版本符号映射；FUN_xxxxxxxx 表示尚未对上真名。
 * 共 23 个函数。这是「2.9.9 行为的唯一事实来源」，不可直接编译。
 * ============================================================ */

/* ---- 0x180001060  hooks::dynamic_initializer::AddMarker  (38 bytes) ---- */

void hooks__dynamic_initializer__AddMarker(void)

{
  ulonglong local_18 [3];
  
  local_18[0] = 0xc6a3;
  local_18[1] = 0xca10;
  DAT_1801d9578 = FUN_18000f860(local_18);
  return;
}


/* ---- 0x1800010c0  hooks::dynamic_initializer::VTABLE_Compass  (200 bytes) ---- */

void hooks__dynamic_initializer__VTABLE_Compass(void)

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


/* ---- 0x1800011f0  hooks::dynamic_initializer::VTABLE_ScriptEffect  (200 bytes) ---- */

void hooks__dynamic_initializer__VTABLE_ScriptEffect(void)

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


/* ---- 0x1800012c0  hooks::dynamic_initializer::VTABLE_DetectLifeEffect  (200 bytes) ---- */

void hooks__dynamic_initializer__VTABLE_DetectLifeEffect(void)

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


/* ---- 0x180001390  hooks::dynamic_initializer::VTABLE_ShaderReferenceEffect  (200 bytes) ---- */

void hooks__dynamic_initializer__VTABLE_ShaderReferenceEffect(void)

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


/* ---- 0x18003ab80  hooks::UpdateQuests  (383 bytes) ---- */

undefined8
hooks__UpdateQuests(undefined8 param_1,undefined8 param_2,longlong param_3,undefined4 *param_4,
                   int param_5,longlong *param_6)

{
  ushort uVar1;
  longlong *plVar2;
  longlong lVar3;
  char cVar4;
  undefined8 *puVar5;
  PlayerCharacter *pPVar6;
  undefined *puVar7;
  longlong lVar8;
  longlong *plVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong *plVar12;
  uint uVar13;
  longlong lStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 auStack_30 [2];
  
  lStack_48 = param_3;
  uStack_40 = param_1;
  auStack_30[0] = param_2;
  uStack_38 = FUN_18003c030(DAT_1801d9578);
  cVar4 = FUN_18003b920(&uStack_38,&uStack_40,auStack_30,&lStack_48,param_4);
  if (cVar4 == '\0') {
    return 0;
  }
  puVar5 = RE::TESObjectREFR::LookupByHandle(&lStack_48,*param_4);
  plVar2 = (longlong *)*puVar5;
  if (lStack_48 != 0) {
    RE::BSHandleRefObject::DecRefCount((BSHandleRefObject *)(lStack_48 + 0x20));
    lStack_48 = 0;
  }
  pPVar6 = RE::PlayerCharacter::GetSingleton();
  uStack_40 = 0x27500060001;
  puVar7 = REL::Module::get();
  uStack_38 = *(undefined8 *)(puVar7 + 0x108);
  uVar11 = 0;
  do {
    uVar1 = *(ushort *)((longlong)auStack_30 + (uVar11 - 8));
    if (uVar1 != *(ushort *)((longlong)&uStack_40 + uVar11)) {
      cVar4 = '\x01';
      if (uVar1 < *(ushort *)((longlong)&uStack_40 + uVar11)) {
        cVar4 = -1;
      }
      goto LAB_18003ac5a;
    }
    uVar11 = uVar11 + 2;
  } while (uVar11 < 8);
  cVar4 = '\0';
LAB_18003ac5a:
  lVar8 = 0x580;
  if (cVar4 != -1) {
    lVar8 = 0x588;
  }
  uVar13 = *(int *)(&pPVar6->field_0x10 + lVar8) - 1;
  if ((int)uVar13 < 0) {
    return 1;
  }
  do {
    plVar12 = (longlong *)((ulonglong)uVar13 * 0x10 + *(longlong *)(&pPVar6->field_0x0 + lVar8));
    lVar3 = *plVar12;
    uVar10 = 0;
    if (*(uint *)(lVar3 + 0x18) != 0) {
      plVar9 = *(longlong **)(lVar3 + 0x10);
      do {
        if (*param_6 == *plVar9) {
          lVar8 = *(longlong *)(lVar3 + 8);
          puVar7 = CNO::HUDMarkerManager::CNO__HUDMarkerManager__GetSingleton();
          CNO__HUDMarkerManager__ProcessQuestMarker
                    ((longlong)puVar7,lVar8,plVar12,uVar13,plVar2,param_5);
          return 1;
        }
        uVar10 = uVar10 + 1;
        plVar9 = plVar9 + 1;
      } while (uVar10 < *(uint *)(lVar3 + 0x18));
    }
    uVar13 = uVar13 - 1;
  } while (-1 < (int)uVar13);
  return 1;
}


/* ---- 0x18003ad00  hooks::AllowedToShowMapMarker  (81 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

longlong __cdecl hooks::hooks__AllowedToShowMapMarker(longlong *param_1)

{
  TESWorldSpace *pTVar1;
  PlayerCharacter *this;
  TESWorldSpace *pTVar2;
  
  pTVar1 = RE::TESObjectREFR::GetWorldspace(param_1);
  if (DAT_1801cf5e0 != '\0') {
    this = RE::PlayerCharacter::GetSingleton();
    pTVar2 = RE::TESObjectREFR::GetWorldspace(this);
    if ((((pTVar2 != (TESWorldSpace *)0x0) && (pTVar1 != (TESWorldSpace *)0x0)) &&
        (pTVar2 != pTVar1)) &&
       ((pTVar2->parentWorld == (TESWorldSpace *)0x0 && (pTVar1->parentWorld == pTVar2)))) {
      pTVar1 = pTVar2;
    }
  }
  return (longlong)pTVar1;
}


/* ---- 0x18003ad60  hooks::UpdateLocations  (488 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

ulonglong hooks__UpdateLocations
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4,
                    uint param_5)

{
  longlong *this;
  undefined8 *puVar1;
  PlayerCharacter *this_00;
  TESWorldSpace *pTVar2;
  float *pfVar3;
  longlong lVar4;
  longlong *extraout_RAX;
  longlong *plVar5;
  longlong *plVar6;
  HUDMarkerManager *this_01;
  undefined8 extraout_RAX_00;
  float fVar7;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_res18;
  longlong local_68;
  undefined8 local_60;
  float local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined4 local_38;
  float local_28 [4];
  
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  puVar1 = RE::TESObjectREFR::LookupByHandle(&local_68,*param_4);
  this = (longlong *)*puVar1;
  if (local_68 != 0) {
    RE::BSHandleRefObject::DecRefCount((BSHandleRefObject *)(local_68 + 0x20));
    local_68 = 0;
  }
  this_00 = RE::PlayerCharacter::GetSingleton();
  local_50 = *(undefined8 *)((longlong)this + 0x54);
  local_48 = *(undefined4 *)((longlong)this + 0x5c);
  pTVar2 = RE::TESObjectREFR::GetWorldspace(this);
  if (pTVar2 != (TESWorldSpace *)0x0) {
    local_60._0_4_ = (pTVar2->worldMapOffsetData).mapOffsetX;
    local_60._4_4_ = (pTVar2->worldMapOffsetData).mapOffsetY;
    local_58 = (pTVar2->worldMapOffsetData).mapOffsetZ;
    pfVar3 = RE::NiPoint3::operator*
                       ((NiPoint3 *)&local_60,(float *)&local_40,
                        (pTVar2->worldMapOffsetData).mapScale);
    RE::NiPoint3::operator+=((NiPoint3 *)&local_50,pfVar3);
  }
  local_40 = *(undefined8 *)&this_00->field_0x54;
  local_38 = *(undefined4 *)&this_00->field_0x5c;
  pTVar2 = RE::TESObjectREFR::GetWorldspace(this_00);
  if (pTVar2 != (TESWorldSpace *)0x0) {
    local_60._0_4_ = (pTVar2->worldMapOffsetData).mapOffsetX;
    local_60._4_4_ = (pTVar2->worldMapOffsetData).mapOffsetY;
    local_58 = (pTVar2->worldMapOffsetData).mapOffsetZ;
    pfVar3 = RE::NiPoint3::operator*
                       ((NiPoint3 *)&local_60,local_28,(pTVar2->worldMapOffsetData).mapScale);
    RE::NiPoint3::operator+=((NiPoint3 *)&local_40,pfVar3);
  }
  local_28[0] = 7.2813e-40;
  local_28[1] = 0.0;
  local_28[2] = 5.69143e-40;
  local_28[3] = 0.0;
  lVar4 = FUN_18000f860((ulonglong *)local_28);
  lVar4 = FUN_18003ba30(lVar4);
  fVar7 = RE::NiPoint3::GetSquaredDistance((NiPoint3 *)&local_40,(float *)&local_50);
  plVar6 = extraout_RAX;
  if ((fVar7 < *(float *)(lVar4 + 0x14b8)) &&
     ((plVar5 = RE::ExtraDataList::GetByTypeImpl((ExtraDataList *)(this + 0xe),0x2c),
      DAT_1801cf5d4 != 0 || (plVar6 = plVar5, (*(byte *)(plVar5[2] + 0x10) & 1) != 0)))) {
    local_60 = FUN_18003c030(DAT_1801d9578);
    plVar6 = (longlong *)FUN_18003b920(&local_60,&local_res8,&local_res10,&local_res18,param_4);
    if ((char)plVar6 != '\0') {
      this_01 = (HUDMarkerManager *)CNO::HUDMarkerManager::CNO__HUDMarkerManager__GetSingleton();
      CNO::HUDMarkerManager::CNO__HUDMarkerManager__ProcessLocationMarker
                (this_01,(longlong)plVar5,this,param_5);
      return CONCAT71((int7)((ulonglong)extraout_RAX_00 >> 8),1);
    }
  }
  return (ulonglong)plVar6 & 0xffffffffffffff00;
}


/* ---- 0x18003af50  hooks::UpdateEnemies  (188 bytes) ---- */

undefined8
hooks__UpdateEnemies
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4,
          undefined4 param_5)

{
  TESForm *this;
  char cVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  longlong *plVar4;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined8 auStackX_18 [2];
  longlong alStack_18 [2];
  
  if (DAT_1801cf5e1 != '\0') {
    uStackX_8 = param_1;
    uStackX_10 = param_2;
    auStackX_18[0] = param_3;
    alStack_18[0] = FUN_18003c030(DAT_1801d9578);
    cVar1 = FUN_18003b920(alStack_18,&uStackX_8,&uStackX_10,auStackX_18,param_4);
    if (cVar1 != '\0') {
      puVar2 = RE::TESObjectREFR::LookupByHandle(alStack_18,*param_4);
      this = (TESForm *)*puVar2;
      if (alStack_18[0] != 0) {
        RE::BSHandleRefObject::DecRefCount((BSHandleRefObject *)(alStack_18[0] + 0x20));
        alStack_18[0] = 0;
      }
      puVar3 = CNO::HUDMarkerManager::CNO__HUDMarkerManager__GetSingleton();
      plVar4 = (longlong *)RE::TESForm::As<RE::Actor,void>(this);
      CNO__HUDMarkerManager__ProcessEnemyMarker((longlong)puVar3,plVar4,param_5);
      return 1;
    }
  }
  return 0;
}


/* ---- 0x18003b010  hooks::UpdatePlayerSetMarker  (164 bytes) ---- */

undefined8
hooks__UpdatePlayerSetMarker
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4,
          undefined4 param_5)

{
  longlong *plVar1;
  char cVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined8 auStackX_18 [2];
  longlong alStack_18 [2];
  
  uStackX_8 = param_1;
  uStackX_10 = param_2;
  auStackX_18[0] = param_3;
  alStack_18[0] = FUN_18003c030(DAT_1801d9578);
  cVar2 = FUN_18003b920(alStack_18,&uStackX_8,&uStackX_10,auStackX_18,param_4);
  if (cVar2 != '\0') {
    puVar3 = RE::TESObjectREFR::LookupByHandle(alStack_18,*param_4);
    plVar1 = (longlong *)*puVar3;
    if (alStack_18[0] != 0) {
      RE::BSHandleRefObject::DecRefCount((BSHandleRefObject *)(alStack_18[0] + 0x20));
      alStack_18[0] = 0;
    }
    puVar4 = CNO::HUDMarkerManager::CNO__HUDMarkerManager__GetSingleton();
    CNO__HUDMarkerManager__ProcessPlayerSetMarker((longlong)puVar4,plVar1,param_5);
    return 1;
  }
  return 0;
}


/* ---- 0x18003b0c0  hooks::UpdateCompass  (58 bytes) ---- */

void __cdecl hooks::hooks__UpdateCompass(Compass *param_1)

{
  undefined8 *puVar1;
  Compass *local_res8;
  undefined8 local_res10 [3];
  
  local_res8 = param_1;
  local_res10[0] = FUN_18003c020(DAT_1801d9598);
  FUN_18003b970(local_res10,&local_res8);
  puVar1 = (undefined8 *)CNO::HUDMarkerManager::CNO__HUDMarkerManager__GetSingleton();
  CNO__HUDMarkerManager__SetMarkersExtraInfo(puVar1);
  return;
}


/* ---- 0x18003b130  hooks::DetectLifeEffectUpdate  (75 bytes) ---- */

void hooks__DetectLifeEffectUpdate(longlong param_1,undefined4 param_2)

{
  longlong lStackX_8;
  undefined4 auStackX_10 [2];
  undefined8 auStackX_18 [2];
  
  lStackX_8 = param_1;
  auStackX_10[0] = param_2;
  if (DAT_1801d9538 != '\0') {
    utils__GetMagicEffectArea(*(longlong *)(param_1 + 0x48));
  }
  auStackX_18[0] = FUN_18003c000(DAT_1801d9550);
  FUN_18003b990(auStackX_18,&lStackX_8,auStackX_10);
  return;
}


/* ---- 0x18003b180  hooks::ScriptEffectUpdate  (99 bytes) ---- */

void hooks__ScriptEffectUpdate(longlong param_1,undefined4 param_2)

{
  int iVar1;
  longlong lStackX_8;
  undefined4 auStackX_10 [2];
  undefined8 auStackX_18 [2];
  
  lStackX_8 = param_1;
  auStackX_10[0] = param_2;
  if ((DAT_1801d9538 != '\0') &&
     ((iVar1 = *(int *)(*(longlong *)(param_1 + 0x40) + 0x14), iVar1 == 0x8afcc ||
      (iVar1 - 0x8afcdU < 2)))) {
    utils__GetMagicEffectArea(*(longlong *)(param_1 + 0x48));
  }
  auStackX_18[0] = FUN_18003c010(DAT_1801d9548);
  FUN_18003b9c0(auStackX_18,&lStackX_8,auStackX_10);
  return;
}


/* ---- 0x18003b1f0  hooks::ShaderReferenceEffectDetach  (46 bytes) ---- */

void hooks__ShaderReferenceEffectDetach(undefined8 param_1)

{
  undefined8 local_res8;
  undefined8 local_res10 [3];
  
  local_res8 = param_1;
  local_res10[0] = FUN_18003bff0(DAT_1801d9540);
  FUN_18003b9f0(local_res10,&local_res8);
  return;
}


/* ---- 0x18003b230  hooks::AddMarker  (61 bytes) ---- */

void hooks__AddMarker(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4
                     ,undefined8 param_5)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = param_1;
  local_res8[0] = FUN_18003c030(DAT_1801d9578);
  FUN_18003b920(local_res8,param_2,param_3,param_4,param_5);
  return;
}


/* ---- 0x180041890  hooks::compat::MapMarkerFramework::Install  (499 bytes)   [名称未经人工确认] ---- */

void __thiscall
spdlog::logger::hooks__compat__MapMarkerFramework__Install
          (logger *this,undefined8 *param_1,int param_2,ulonglong *param_3)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  undefined1 *_Memory;
  undefined1 auStackY_278 [32];
  undefined1 *local_248;
  undefined8 *local_240;
  logger *local_238;
  undefined8 *local_228;
  ulonglong local_218;
  ulonglong uStack_210;
  logger *local_208;
  undefined8 local_200;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  log_msg local_1c8;
  undefined **local_168;
  undefined1 *local_160;
  undefined8 local_158;
  ulonglong local_150;
  undefined1 local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_278;
  local_238 = this;
  local_228 = param_1;
  piVar3 = std::_Atomic_address_as<int,std::_Atomic_padded<int>_>
                     ((_Atomic_padded<int> *)(this + 0x40));
  iVar1 = *piVar3;
  bVar2 = details::backtracer::enabled((backtracer *)(this + 0x88));
  if ((iVar1 <= param_2) || (bVar2)) {
    local_158 = 0;
    local_168 = fmt::v10::basic_memory_buffer<char,250,class_std::allocator<char>_>::vftable;
    local_160 = local_148;
    local_150 = 0xfa;
    local_248 = (undefined1 *)0x0;
    local_240 = &local_1e8;
    local_218 = *param_3;
    uStack_210 = param_3[1];
    fmt::v10::vformat_to<fmt::v10::appender,0>
              (&local_208,&local_168,&local_218,(ulonglong *)&local_248);
    local_208 = this + 8;
    if (0xf < *(ulonglong *)(this + 0x20)) {
      local_208 = *(logger **)(this + 8);
    }
    local_248 = local_160;
    local_240 = (undefined8 *)local_158;
    local_200 = *(undefined8 *)(this + 0x18);
    local_1e8 = *param_1;
    uStack_1e0 = param_1[1];
    local_1d8 = param_1[2];
    details::log_msg::log_msg(&local_1c8,&local_1e8,(undefined4 *)&local_208,param_2,&local_248);
    log_it_(this,(undefined8 *)&local_1c8,iVar1 <= param_2,bVar2);
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
  __security_check_cookie(local_48 ^ (ulonglong)auStackY_278);
  return;
}


/* ---- 0x18004e7e0  hooks::Install  (1584 bytes) ---- */

void hooks__Install(void)

{
  LPVOID pvVar1;
  void *pvVar2;
  undefined8 uVar3;
  longlong lVar4;
  Trampoline *pTVar5;
  char cVar6;
  undefined *puVar7;
  undefined8 *puVar8;
  void *_Src;
  ulonglong uVar9;
  void *pvVar10;
  code *pcVar11;
  longlong lVar12;
  ulonglong uVar13;
  LPVOID pvVar14;
  undefined *local_res8;
  longlong local_c68;
  LPVOID local_c60;
  code *local_c58;
  void *local_c50;
  void *local_c48;
  undefined8 uStack_c40;
  undefined8 local_c38;
  LPVOID local_c30;
  code *local_c28;
  void *local_c20;
  void *local_c18;
  undefined8 uStack_c10;
  longlong local_c08;
  LPVOID local_c00;
  void *local_bf8;
  void *local_bf0;
  void *pvStack_be8;
  void *local_be0;
  undefined8 local_bd8;
  LPVOID local_bd0;
  code *local_bc8;
  undefined8 local_bc0;
  undefined8 uStack_bb8;
  undefined8 local_bb0;
  undefined8 local_ba8;
  LPVOID local_ba0;
  code *local_b98;
  undefined8 local_b90;
  undefined8 uStack_b88;
  undefined8 local_b80;
  undefined8 local_b78;
  LPVOID local_b70;
  code *local_b68;
  undefined8 local_b60;
  undefined8 uStack_b58;
  undefined8 local_b50;
  CodeArray local_b48 [80];
  LabelManager local_af8 [2768];
  
  lVar12 = DAT_1801d9568;
  puVar7 = REL::Module::get();
  uVar13 = 0;
  if (puVar7[0x118] == '\x01') {
    uVar9 = 0x180;
  }
  else {
    uVar9 = uVar13;
    if (puVar7[0x118] == '\x02') {
      uVar9 = 0x114;
    }
  }
  pvVar1 = (LPVOID)(uVar9 + lVar12);
  puVar8 = hooks__Install__UpdateQuestsHook__HookCodeGenerator__HookCodeGenerator
                     ((undefined8 *)local_b48,(longlong)pvVar1);
  uVar9 = puVar8[8];
  local_c08 = uVar9 + 0xe;
  local_bf8 = (void *)0x0;
  pvVar2 = (void *)puVar8[7];
  local_bf0 = (void *)0x0;
  pvStack_be8 = (void *)0x0;
  local_be0 = (void *)0x0;
  local_c00 = pvVar1;
  if (uVar9 == 0) {
    _Src = (void *)0x0;
  }
  else {
    if (0x7fffffffffffffff < uVar9) {
      FUN_180058af0();
      pcVar11 = (code *)swi(3);
      (*pcVar11)();
      return;
    }
    if (uVar9 < 0x1000) {
      _Src = operator_new(uVar9);
    }
    else {
      _Src = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>(uVar9);
    }
    local_bf0 = _Src;
    local_be0 = (void *)(uVar9 + (longlong)_Src);
    FUN_180058610(pvVar2,uVar9 + (longlong)pvVar2,_Src);
    pvStack_be8 = (void *)(uVar9 + (longlong)_Src);
  }
  pvVar2 = pvStack_be8;
  Xbyak::LabelManager::~LabelManager(local_af8);
  Xbyak::CodeArray::~CodeArray(local_b48);
  lVar12 = DAT_1801d9570;
  puVar7 = REL::Module::get();
  lVar4 = DAT_1801d9570;
  if (puVar7[0x118] == '\x01') {
    uVar9 = 0x13c;
  }
  else {
    uVar9 = uVar13;
    if (puVar7[0x118] == '\x02') {
      uVar9 = 0x139;
    }
  }
  local_c68 = 0xe;
  local_c60 = (LPVOID)(uVar9 + lVar12);
  local_c58 = hooks::hooks__AllowedToShowMapMarker;
  local_c50 = (void *)0x0;
  local_c48 = (void *)0x0;
  uStack_c40 = 0;
  puVar7 = REL::Module::get();
  lVar12 = DAT_1801d9570;
  if (puVar7[0x118] == '\x01') {
    uVar9 = 0x24b;
  }
  else {
    uVar9 = uVar13;
    if (puVar7[0x118] == '\x02') {
      uVar9 = 0x21c;
    }
  }
  local_c38 = 0xe;
  local_c30 = (LPVOID)(uVar9 + lVar4);
  local_c28 = hooks::hooks__AllowedToShowMapMarker;
  local_c20 = (void *)0x0;
  local_c18 = (void *)0x0;
  uStack_c10 = 0;
  puVar7 = REL::Module::get();
  if (puVar7[0x118] == '\x01') {
    uVar9 = 0x473;
  }
  else {
    uVar9 = uVar13;
    if (puVar7[0x118] == '\x02') {
      uVar9 = 0x450;
    }
  }
  local_bd8 = 0xe;
  local_bd0 = (LPVOID)(uVar9 + lVar12);
  local_bc8 = hooks__UpdateLocations;
  local_bc0 = 0;
  uStack_bb8 = 0;
  local_bb0 = 0;
  puVar7 = REL::Module::get();
  lVar12 = DAT_1801d9580;
  local_res8 = *(undefined **)(puVar7 + 0x108);
  uVar9 = uVar13;
  do {
    if (*(ushort *)((longlong)&local_res8 + uVar9) != *(ushort *)((longlong)&DAT_180191830 + uVar9))
    {
      cVar6 = '\x01';
      if (*(ushort *)((longlong)&local_res8 + uVar9) < *(ushort *)((longlong)&DAT_180191830 + uVar9)
         ) {
        cVar6 = -1;
      }
      goto LAB_18004ea2c;
    }
    uVar9 = uVar9 + 2;
  } while (uVar9 < 8);
  cVar6 = '\0';
LAB_18004ea2c:
  puVar7 = REL::Module::get();
  uVar9 = ((longlong)cVar6 >> 0x3f & 0xffffffffffffff60U) + 0x1735;
  if ((puVar7[0x118] != '\x01') && (uVar9 = uVar13, puVar7[0x118] == '\x02')) {
    uVar9 = 0x15ab;
  }
  local_ba8 = 0xe;
  local_ba0 = (LPVOID)(lVar12 + uVar9);
  local_b98 = hooks__UpdateEnemies;
  local_b90 = 0;
  uStack_b88 = 0;
  local_b80 = 0;
  puVar7 = REL::Module::get();
  if (puVar7[0x118] == '\x01') {
    pvVar14 = (LPVOID)(DAT_1801d9598 + 0xae);
  }
  else {
    pvVar14 = (LPVOID)(DAT_1801d9590 + 0x8d);
  }
  local_b78 = 0xe;
  local_b68 = hooks__UpdatePlayerSetMarker;
  local_b60 = 0;
  uStack_b58 = 0;
  local_b50 = 0;
  local_b70 = pvVar14;
  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
               0x14) < DAT_1801d97d8) && (_Init_thread_header(&DAT_1801d97d8), DAT_1801d97d8 == -1))
  {
    lVar12 = local_c68 + local_c08;
    DAT_1801d97e0 = (Trampoline *)SKSE::GetTrampoline();
    DAT_1801d97e8 = 0;
    SKSE__AllocTrampoline(lVar12 + 0x2a,'\x01');
    atexit(FUN_180162180);
    _Init_thread_footer(&DAT_1801d97d8);
  }
  pTVar5 = DAT_1801d97e0;
  pvVar10 = (void *)0x0;
  if (_Src != pvVar2) {
    pvVar10 = (void *)FUN_1800a6720((longlong)DAT_1801d97e0,(longlong)pvVar2 - (longlong)_Src);
    SKSE::Trampoline::log_stats(pTVar5);
    memcpy(pvVar10,_Src,(longlong)pvVar2 - (longlong)_Src);
    local_bf8 = pvVar10;
  }
  hooks__Trampoline__write_call_6_((longlong *)DAT_1801d97e0,pvVar1,(ulonglong)pvVar10,0xe9);
  pTVar5 = DAT_1801d97e0;
  if ((local_c58 == (code *)0x0) && (local_c50 != local_c48)) {
    pcVar11 = (code *)FUN_1800a6720((longlong)DAT_1801d97e0,
                                    (longlong)local_c48 - (longlong)local_c50);
    SKSE::Trampoline::log_stats(pTVar5);
    memcpy(pcVar11,local_c50,(longlong)local_c48 - (longlong)local_c50);
    local_c58 = pcVar11;
  }
  hooks__Trampoline__write_call_6_((longlong *)DAT_1801d97e0,local_c60,(ulonglong)local_c58,0xe8);
  pTVar5 = DAT_1801d97e0;
  if ((local_c28 == (code *)0x0) && (local_c20 != local_c18)) {
    pcVar11 = (code *)FUN_1800a6720((longlong)DAT_1801d97e0,
                                    (longlong)local_c18 - (longlong)local_c20);
    SKSE::Trampoline::log_stats(pTVar5);
    memcpy(pcVar11,local_c20,(longlong)local_c18 - (longlong)local_c20);
    local_c28 = pcVar11;
  }
  hooks__Trampoline__write_call_6_((longlong *)DAT_1801d97e0,local_c30,(ulonglong)local_c28,0xe8);
  hooks__Trampoline__write_call_6_((longlong *)DAT_1801d97e0,local_bd0,0x18003ad60,0xe8);
  hooks__Trampoline__write_call_6_((longlong *)DAT_1801d97e0,local_ba0,0x18003af50,0xe8);
  hooks__Trampoline__write_call_6_((longlong *)DAT_1801d97e0,pvVar14,0x18003b010,0xe8);
  local_res8 = SKSE::stl::unrestricted_cast<unsigned___int64,void_(__cdecl*)(RE::Compass_*)>();
  utils__write_vfunc_impl((LPVOID)(DAT_1801d9588 + 8),&local_res8);
  local_res8 = hooks__get_DetectLifeEffectUpdate_thunk();
  uVar3 = *(undefined8 *)(DAT_1801d95a8 + 0x20);
  utils__write_vfunc_impl((undefined8 *)(DAT_1801d95a8 + 0x20),&local_res8);
  DAT_1801d9550 = uVar3;
  local_res8 = hooks__get_ScriptEffectUpdate_thunk();
  uVar3 = *(undefined8 *)(DAT_1801d95a0 + 0x20);
  utils__write_vfunc_impl((undefined8 *)(DAT_1801d95a0 + 0x20),&local_res8);
  DAT_1801d9548 = uVar3;
  local_res8 = hooks__get_ShaderReferenceEffectDetach_thunk();
  uVar3 = *(undefined8 *)(DAT_1801d95b0 + 0x1f0);
  utils__write_vfunc_impl((undefined8 *)(DAT_1801d95b0 + 0x1f0),&local_res8);
  DAT_1801d9540 = uVar3;
  _eh_vector_destructor_iterator_(&local_c68,0x30,2,FUN_18004f7d0);
  if (_Src != (void *)0x0) {
    pvVar10 = _Src;
    if ((0xfff < (ulonglong)((longlong)pvVar2 - (longlong)_Src)) &&
       (pvVar10 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar10)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(pvVar10);
  }
  return;
}


/* ---- 0x18004ee70  hooks::Install::UpdateQuestsHook::HookCodeGenerator::HookCodeGenerator  (1328 bytes) ---- */

undefined8 *
hooks__Install__UpdateQuestsHook__HookCodeGenerator__HookCodeGenerator
          (undefined8 *param_1,longlong param_2)

{
  LabelManager *this;
  ulonglong uVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  char cVar4;
  uint uVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  LabelManager **local_res18;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint uStack_bc;
  uint uStack_b8;
  uint uStack_b4;
  ulonglong local_b0;
  undefined8 uStack_a8;
  LabelManager **local_a0;
  undefined4 local_98;
  undefined1 local_94;
  LabelManager *local_90;
  int local_88;
  LabelManager *local_80;
  int local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  uint uStack_5c;
  undefined8 uStack_58;
  uint local_50;
  uint uStack_4c;
  undefined8 uStack_48;
  ulonglong local_40;
  undefined8 uStack_38;
  
  Xbyak::CodeGenerator::CodeGenerator(param_1);
  *param_1 = `void___cdecl_hooks::Install(void)'::__l2::UpdateQuestsHook::HookCodeGenerator::vftable
  ;
  local_80 = (LabelManager *)0x0;
  local_78 = 0;
  local_90 = (LabelManager *)0x0;
  local_88 = 0;
  local_70 = local_70 & 0xffffffc080000000;
  uVar8 = 0;
  uStack_68 = uStack_68 & 0xffffffc080000000;
  local_60 = 1;
  uStack_58 = 0;
  uVar7 = *(uint *)(param_1 + 0x9d) >> 6;
  uVar5 = *(uint *)(param_1 + 0x9d) >> 0x10;
  if ((((uVar7 & 2) == 0) || ((uVar5 & 0x60) == 0)) && ((uVar7 & 0x270) == 0)) {
    local_c0 = local_c0 & 0x80000000;
    uStack_bc = uStack_bc & 0xffffffc0;
    Xbyak::Error::Error((Error *)&local_c8,6);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_c8,(ThrowInfo *)&_TI2_AVError_Xbyak__);
  }
  uVar1 = param_1[0x9d];
  uVar3 = uVar1;
  if (0x7f < (uVar5 & 0x3fff)) {
    uVar8 = (uint)uVar1;
    uVar3 = local_70;
    uStack_68 = uVar1;
  }
  local_70 = uVar3;
  local_50 = (uint)local_70;
  uStack_4c = local_70._4_4_;
  local_40 = CONCAT44(uStack_5c,1);
  uStack_b8 = (uint)uStack_68;
  uStack_b4 = uStack_68._4_4_;
  uStack_48 = uStack_68;
  if ((uVar8 & 0x3fff0000) == 0) {
    uVar1 = CONCAT44(uStack_bc,local_c0) & 0xffffffc080000000;
    local_40 = (ulonglong)uStack_5c << 0x20;
    uStack_48._0_4_ = (uint)uVar1;
    uStack_48._4_4_ = (uint)(uVar1 >> 0x20);
    uStack_b8 = (uint)uStack_48;
    uStack_b4 = uStack_48._4_4_;
    uVar8 = local_c0 & 0x80000000;
    uStack_48 = uVar1;
  }
  uStack_a8 = 0x28;
  local_c8 = (*(uint *)(param_1 + 0x76) & 0x3fff) << 0x10 | local_c8 & 0x80000040 | 0x40;
  local_c4 = local_c4 & 0xffffffc0;
  local_c0 = (uint)local_70;
  uStack_bc = local_70._4_4_;
  local_b0 = local_40;
  local_a0 = (LabelManager **)0x0;
  local_98 = 0;
  local_94 = *(undefined1 *)((longlong)param_1 + 0x3b4);
  uVar5 = (uint)local_70 >> 0x10 & 0x3fff;
  uStack_38 = uStack_a8;
  if (0x7f < uVar5) {
    Xbyak::Error::Error((Error *)&local_c8,6);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_c8,(ThrowInfo *)&_TI2_AVError_Xbyak__);
  }
  uVar7 = uVar8 >> 0x10 & 0x3fff;
  if ((uVar7 != 0) && (uVar7 < 0x41)) {
    if (((byte)uVar8 & 0x1f) == 4) {
      Xbyak::Error::Error((Error *)&local_c8,4);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_c8,(ThrowInfo *)&_TI2_AVError_Xbyak__);
    }
    if ((uVar5 != 0) && (uVar5 != uVar7)) {
      Xbyak::Error::Error((Error *)&local_c8,6);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_c8,(ThrowInfo *)&_TI2_AVError_Xbyak__);
    }
  }
  puVar9 = (uint *)(param_1 + 0x9c);
  Xbyak::CodeGenerator::mov((CodeGenerator *)param_1,&local_c8,puVar9);
  if ((param_1[0x15e] != 0) || (*(char *)(param_1 + 0x15f) != '\0')) {
    Xbyak::Error::Error((Error *)&local_c8,1);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_c8,(ThrowInfo *)&_TI2_AVError_Xbyak__);
  }
  local_c8 = (*(uint *)(param_1 + 0x76) & 0x3fff) << 0x10 | local_c8 & 0x80000040 | 0x40;
  local_c4 = local_c4 & 0xffffffc0;
  local_c0 = local_c0 & 0x80000000;
  uStack_bc = uStack_bc & 0xffffffc0;
  uStack_b8 = uStack_b8 & 0x80000000;
  uStack_b4 = uStack_b4 & 0xffffffc0;
  local_b0 = local_b0 & 0xffffffff00000000;
  uStack_a8 = param_1[0x15d];
  local_a0 = &local_80;
  local_98 = 2;
  local_94 = *(undefined1 *)((longlong)param_1 + 0x3b4);
  Xbyak::CodeGenerator::opR_ModM((longlong)param_1,&local_c8,puVar9,2);
  if ((param_1[0x15e] != 0) || (*(char *)(param_1 + 0x15f) != '\0')) {
    Xbyak::Error::Error((Error *)&local_c8,1);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_c8,(ThrowInfo *)&_TI2_AVError_Xbyak__);
  }
  local_c8 = (*(uint *)(param_1 + 0x76) & 0x3fff) << 0x10 | local_c8 & 0x80000040 | 0x40;
  local_c4 = local_c4 & 0xffffffc0;
  local_c0 = local_c0 & 0x80000000;
  uStack_bc = uStack_bc & 0xffffffc0;
  uStack_b8 = uStack_b8 & 0x80000000;
  uStack_b4 = uStack_b4 & 0xffffffc0;
  local_b0 = local_b0 & 0xffffffff00000000;
  uStack_a8 = param_1[0x15d];
  local_a0 = &local_90;
  local_98 = 2;
  local_94 = *(undefined1 *)((longlong)param_1 + 0x3b4);
  Xbyak::CodeGenerator::opR_ModM((longlong)param_1,&local_c8,puVar9,4);
  this = (LabelManager *)(param_1 + 10);
  uVar1 = *(ulonglong *)(*(longlong *)this + 0x40);
  if (local_78 == 0) {
    local_78 = *(int *)(param_1 + 0xd);
    *(int *)(param_1 + 0xd) = local_78 + 1;
  }
  local_res18 = (LabelManager **)CONCAT44(local_res18._4_4_,local_78);
  Xbyak::LabelManager::
  define_inner<std::unordered_map<int,Xbyak::LabelManager::ClabelVal,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int_const_,Xbyak::LabelManager::ClabelVal>_>_>,std::unordered_multimap<int,Xbyak::JmpLabel_const_,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int_const_,Xbyak::JmpLabel_const_>_>_>,int>
            (this,(float *)(param_1 + 0xe),(longlong)(param_1 + 0x16),
             (_Conditionally_enabled_hash<unsigned_long,1> *)&local_res18,uVar1);
  local_res18 = &local_80;
  local_80 = this;
  std::
  _Hash<std::_Uset_traits<Xbyak::Label_*,std::_Uhash_compare<Xbyak::Label_*,std::hash<Xbyak::Label_*>,std::equal_to<Xbyak::Label_*>_>,std::allocator<Xbyak::Label_*>,0>_>
  ::emplace<Xbyak::Label_*>
            ((_Hash<std::_Uset_traits<Xbyak::Label_*,std::_Uhash_compare<Xbyak::Label_*,std::hash<Xbyak::Label_*>,std::equal_to<Xbyak::Label_*>_>,std::allocator<Xbyak::Label_*>,0>_>
              *)(param_1 + 0x1e),&local_70,(longlong *)&local_res18);
  Xbyak::CodeArray::dq((CodeArray *)param_1,0x18003ab80);
  uVar1 = *(ulonglong *)(*(longlong *)this + 0x40);
  if (local_88 == 0) {
    local_88 = *(int *)(param_1 + 0xd);
    *(int *)(param_1 + 0xd) = local_88 + 1;
  }
  local_res18 = (LabelManager **)CONCAT44(local_res18._4_4_,local_88);
  Xbyak::LabelManager::
  define_inner<std::unordered_map<int,Xbyak::LabelManager::ClabelVal,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int_const_,Xbyak::LabelManager::ClabelVal>_>_>,std::unordered_multimap<int,Xbyak::JmpLabel_const_,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int_const_,Xbyak::JmpLabel_const_>_>_>,int>
            (this,(float *)(param_1 + 0xe),(longlong)(param_1 + 0x16),
             (_Conditionally_enabled_hash<unsigned_long,1> *)&local_res18,uVar1);
  local_res18 = &local_90;
  local_90 = this;
  std::
  _Hash<std::_Uset_traits<Xbyak::Label_*,std::_Uhash_compare<Xbyak::Label_*,std::hash<Xbyak::Label_*>,std::equal_to<Xbyak::Label_*>_>,std::allocator<Xbyak::Label_*>,0>_>
  ::emplace<Xbyak::Label_*>
            ((_Hash<std::_Uset_traits<Xbyak::Label_*,std::_Uhash_compare<Xbyak::Label_*,std::hash<Xbyak::Label_*>,std::equal_to<Xbyak::Label_*>_>,std::allocator<Xbyak::Label_*>,0>_>
              *)(param_1 + 0x1e),&local_70,(longlong *)&local_res18);
  Xbyak::CodeArray::dq((CodeArray *)param_1,param_2 + 5);
  for (puVar2 = *(undefined8 **)param_1[0xb]; puVar2 != (undefined8 *)param_1[0xb];
      puVar2 = (undefined8 *)*puVar2) {
    if (puVar2[0xc] != 0) goto LAB_18004f36a;
  }
  if (param_1[0x18] == 0) {
    if (*(int *)(param_1 + 3) == 3) {
      Xbyak::CodeArray::calcJmpAddress((CodeArray *)param_1);
      cVar4 = (**(code **)(*(longlong *)param_1[5] + 0x18))();
      if ((cVar4 != '\0') &&
         (BVar6 = VirtualProtect((LPVOID)param_1[7],param_1[6],0x40,(PDWORD)&local_res18),
         BVar6 == 0)) {
        Xbyak::Error::Error((Error *)&local_c8,0xe);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_c8,(ThrowInfo *)&_TI2_AVError_Xbyak__);
      }
    }
    if ((local_88 != 0) && (local_90 != (LabelManager *)0x0)) {
      Xbyak::LabelManager::decRefCount(local_90,local_88,(longlong)&local_90);
    }
    if ((local_78 != 0) && (local_80 != (LabelManager *)0x0)) {
      Xbyak::LabelManager::decRefCount(local_80,local_78,(longlong)&local_80);
    }
    return param_1;
  }
LAB_18004f36a:
  Xbyak::Error::Error((Error *)&local_c8,0xb);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_c8,(ThrowInfo *)&_TI2_AVError_Xbyak__);
}


/* ---- 0x180052540  hooks::get_DetectLifeEffectUpdate_thunk  (8 bytes) ---- */

undefined1 * hooks__get_DetectLifeEffectUpdate_thunk(void)

{
  return hooks__DetectLifeEffectUpdate;
}


/* ---- 0x180052550  hooks::get_ScriptEffectUpdate_thunk  (8 bytes) ---- */

undefined1 * hooks__get_ScriptEffectUpdate_thunk(void)

{
  return hooks__ScriptEffectUpdate;
}


/* ---- 0x180052560  hooks::get_ShaderReferenceEffectDetach_thunk  (8 bytes) ---- */

undefined * hooks__get_ShaderReferenceEffectDetach_thunk(void)

{
  return hooks__ShaderReferenceEffectDetach;
}


/* ---- 0x1800a6cd0  hooks::Trampoline::write_call<6>  (341 bytes) ---- */

void hooks__Trampoline__write_call_6_
               (longlong *param_1,LPVOID param_2,ulonglong param_3,undefined1 param_4)

{
  char cVar1;
  longlong *plVar2;
  ulonglong uVar3;
  longlong *plVar4;
  undefined2 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined1 local_res8;
  int local_res9;
  undefined2 *local_res10;
  ulonglong local_res18 [2];
  longlong local_68;
  longlong lStack_60;
  undefined8 local_58 [2];
  undefined4 local_48;
  undefined4 local_44;
  char *local_40;
  char *local_38;
  
  plVar6 = (longlong *)*param_1;
  plVar4 = (longlong *)plVar6[1];
  cVar1 = *(char *)((longlong)plVar4 + 0x19);
  plVar2 = plVar6;
  while (cVar1 == '\0') {
    plVar7 = plVar4;
    if ((ulonglong)plVar4[4] < param_3) {
      plVar4 = plVar4 + 2;
      plVar7 = plVar2;
    }
    plVar4 = (longlong *)*plVar4;
    plVar2 = plVar7;
    cVar1 = *(char *)((longlong)plVar4 + 0x19);
  }
  local_res18[0] = param_3;
  if (((*(char *)((longlong)plVar2 + 0x19) == '\0') && ((ulonglong)plVar2[4] <= param_3)) &&
     (plVar2 != plVar6)) {
    puVar5 = (undefined2 *)plVar2[5];
  }
  else {
    puVar5 = (undefined2 *)FUN_1800a6720((longlong)param_1,0xe);
    SKSE::Trampoline::log_stats((Trampoline *)param_1);
    local_res10 = puVar5;
    FUN_1800a4e00(param_1,&local_68,local_res18,(longlong *)&local_res10);
  }
  uVar3 = local_res18[0];
  local_res9 = (int)((longlong)puVar5 - (longlong)param_2) + -5;
  if (((longlong)puVar5 - (longlong)param_2) + 0x7ffffffbU < 0x100000000) {
    local_res8 = param_4;
    REL::safe_write(param_2,&local_res8,5);
    *puVar5 = 0x25ff;
    *(undefined4 *)(puVar5 + 1) = 0;
    *(ulonglong *)(puVar5 + 3) = uVar3;
    return;
  }
  local_48 = 0xa8;
  local_40 = 
  "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\Trampoline.cpp"
  ;
  local_44 = 9;
  local_38 = 
  "void __cdecl SKSE::Trampoline::write_5branch(unsigned __int64,unsigned __int64,unsigned char)";
  plVar6 = FUN_1800355c0(local_58,"displacement is out of range",0x1c);
  local_68 = *plVar6;
  lStack_60 = plVar6[1];
                    /* WARNING: Subroutine does not return */
  SKSE::stl::report_and_fail(&local_68,(longlong *)&local_48);
}


/* ---- 0x1800a6e30  hooks::Trampoline::write_call<6>  (349 bytes) ---- */

void hooks__Trampoline__write_call_6_
               (longlong param_1,LPVOID param_2,ulonglong param_3,undefined1 param_4)

{
  char cVar1;
  longlong *plVar2;
  ulonglong uVar3;
  longlong *plVar4;
  ulonglong *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined1 local_res8;
  undefined1 local_res9;
  int local_resa;
  ulonglong *local_res10;
  ulonglong local_res18;
  longlong local_68;
  longlong lStack_60;
  undefined8 local_58 [2];
  undefined4 local_48;
  undefined4 local_44;
  char *local_40;
  char *local_38;
  
  plVar6 = *(longlong **)(param_1 + 0x10);
  plVar4 = (longlong *)plVar6[1];
  cVar1 = *(char *)((longlong)plVar4 + 0x19);
  plVar2 = plVar6;
  while (cVar1 == '\0') {
    plVar7 = plVar4;
    if ((ulonglong)plVar4[4] < param_3) {
      plVar4 = plVar4 + 2;
      plVar7 = plVar2;
    }
    plVar4 = (longlong *)*plVar4;
    plVar2 = plVar7;
    cVar1 = *(char *)((longlong)plVar4 + 0x19);
  }
  local_res18 = param_3;
  if (((*(char *)((longlong)plVar2 + 0x19) == '\0') && ((ulonglong)plVar2[4] <= param_3)) &&
     (plVar2 != plVar6)) {
    puVar5 = (ulonglong *)plVar2[5];
  }
  else {
    puVar5 = (ulonglong *)FUN_1800a6720(param_1,8);
    SKSE::Trampoline::log_stats((Trampoline *)param_1);
    local_res10 = puVar5;
    FUN_1800a4e00((longlong *)(param_1 + 0x10),&local_68,&local_res18,(longlong *)&local_res10);
  }
  uVar3 = local_res18;
  local_resa = (int)((longlong)puVar5 - (longlong)param_2) + -6;
  if (((longlong)puVar5 - (longlong)param_2) + 0x7ffffffaU < 0x100000000) {
    local_res8 = 0xff;
    local_res9 = param_4;
    REL::safe_write(param_2,&local_res8,6);
    *puVar5 = uVar3;
    return;
  }
  local_48 = 0xd2;
  local_40 = 
  "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\__vcpkg_installed_shared\\se-only\\vcpkg\\blds\\commonlibsse-ng\\src\\0191814092-0efc0941a6.clean\\src\\SKSE\\Trampoline.cpp"
  ;
  local_44 = 9;
  local_38 = 
  "void __cdecl SKSE::Trampoline::write_6branch(unsigned __int64,unsigned __int64,unsigned char)";
  plVar6 = FUN_1800355c0(local_58,"displacement is out of range",0x1c);
  local_68 = *plVar6;
  lStack_60 = plVar6[1];
                    /* WARNING: Subroutine does not return */
  SKSE::stl::report_and_fail(&local_68,(longlong *)&local_48);
}


