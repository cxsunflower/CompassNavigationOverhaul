/* ==== 0x18003ab80  FUN_18003ab80  (383 bytes) ==== */

undefined8
FUN_18003ab80(undefined8 param_1,undefined8 param_2,longlong param_3,undefined4 *param_4,int param_5
             ,longlong *param_6)

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
          puVar7 = CNO::HUDMarkerManager::CNO__HUDMarkerManager__CNO__HUDMarkerManager__GetSingleton
                             ();
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


/* ==== 0x18003ad60  hooks__UpdateLocations  (488 bytes) ==== */

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
      this_01 = (HUDMarkerManager *)
                CNO::HUDMarkerManager::CNO__HUDMarkerManager__CNO__HUDMarkerManager__GetSingleton();
      CNO::HUDMarkerManager::CNO__HUDMarkerManager__CNO__HUDMarkerManager__ProcessLocationMarker
                (this_01,(longlong)plVar5,this,param_5);
      return CONCAT71((int7)((ulonglong)extraout_RAX_00 >> 8),1);
    }
  }
  return (ulonglong)plVar6 & 0xffffffffffffff00;
}


/* ==== 0x18003af50  FUN_18003af50  (188 bytes) ==== */

undefined8
FUN_18003af50(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4,
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
      puVar3 = CNO::HUDMarkerManager::CNO__HUDMarkerManager__CNO__HUDMarkerManager__GetSingleton();
      plVar4 = (longlong *)RE::TESForm::As<RE::Actor,void>(this);
      CNO__HUDMarkerManager__ProcessEnemyMarker((longlong)puVar3,plVar4,param_5);
      return 1;
    }
  }
  return 0;
}


/* ==== 0x18003b010  FUN_18003b010  (164 bytes) ==== */

undefined8
FUN_18003b010(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4,
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
    puVar4 = CNO::HUDMarkerManager::CNO__HUDMarkerManager__CNO__HUDMarkerManager__GetSingleton();
    CNO__HUDMarkerManager__ProcessPlayerSetMarker((longlong)puVar4,plVar1,param_5);
    return 1;
  }
  return 0;
}


/* ==== 0x18004ee70  FUN_18004ee70  (1328 bytes) ==== */

undefined8 * FUN_18004ee70(undefined8 *param_1,longlong param_2)

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


