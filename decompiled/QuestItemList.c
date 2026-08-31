/* ============================================================
 * QuestItemList.c  ——  CompassNavigationOverhaul 2.9.9 反编译产物
 * 由 Ghidra 11.3.2 反编译器从 SKSE/Plugins/CompassNavigationOverhaul.dll 导出。
 * 函数名来自 2.2.0-VR 版 PDB 的跨版本符号映射；FUN_xxxxxxxx 表示尚未对上真名。
 * 共 9 个函数。这是「2.9.9 行为的唯一事实来源」，不可直接编译。
 * ============================================================ */

/* ---- 0x1800024c0  QuestItemList::CanBeDisplayed  (93 bytes) ---- */

bool __thiscall
QuestItemList::QuestItemList__CanBeDisplayed(QuestItemList *this,longlong param_1,char param_2)

{
  byte bVar1;
  
  if (((param_2 == '\0') || (DAT_1801d9519 == '\0')) && (param_1 != 0)) {
    bVar1 = FUN_180064390(param_1);
    if ((bVar1 != 0) && (DAT_1801cf5c8 != '\0')) {
      return true;
    }
    bVar1 = RE::TESObjectCELL::IsExteriorCell((TESObjectCELL *)param_1);
    if (bVar1 != 0) {
      return DAT_1801cf5c9 != '\0';
    }
  }
  return false;
}


/* ---- 0x180002530  QuestItemList::AddQuest  (577 bytes) ---- */

void __thiscall QuestItemList::QuestItemList__AddQuest(QuestItemList *this,longlong param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  char cVar3;
  ulong64 uVar4;
  char *pcVar5;
  longlong *plVar6;
  uint uVar7;
  BSStringT<char,4294967295,RE::DynamicMemoryManagementPol> *pBVar8;
  undefined8 *puVar9;
  undefined1 auStack_168 [32];
  undefined8 local_148;
  undefined4 local_138;
  BSStringT<char,4294967295,RE::DynamicMemoryManagementPol> local_130;
  undefined8 local_120;
  pmf_0c849555 local_118;
  QuestItemList *local_110;
  undefined8 local_108 [3];
  undefined8 local_f0 [3];
  ulonglong local_d8;
  double local_d0;
  undefined1 local_c8 [24];
  undefined1 local_b0 [24];
  undefined1 local_98 [24];
  undefined1 local_80 [24];
  undefined1 local_68 [32];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_168;
  local_138 = 0;
  pBVar8 = (BSStringT<char,4294967295,RE::DynamicMemoryManagementPol> *)**(undefined8 **)this;
  local_110 = this;
  FUN_180045700(local_f0);
  (**(code **)(pBVar8->_data + 0x70))(pBVar8,local_f0);
  puVar9 = *(undefined8 **)(param_1 + 0x38);
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  if (puVar9 != puVar1) {
    local_d8 = 0x5abd;
    local_d0 = 1.17014507561041e-319;
    do {
      uVar7 = (uint)pBVar8;
      uVar2 = *puVar9;
      uVar4 = FUN_18000f860(&local_d8);
      local_130._data = (char *)0x0;
      local_130._size = 0;
      local_130._capacity = 0;
      local_130._pad0C = 0;
      RE::BSStringT<char,4294967295,RE::DynamicMemoryManagementPol>::set_cstr(&local_130,"",uVar7);
      local_138 = 1;
      local_120 = uVar2;
      local_118 = SKSE::stl::
                  unrestricted_cast<void_(__cdecl_RE::BGSInstancedQuestObjective::*)(RE::BSStringT<char,4294967295,RE::DynamicMemoryManagementPol>_&)const_,unsigned___int64>
                            (uVar4);
      pBVar8 = &local_130;
      REL::
      invoke<void_(__cdecl_RE::BGSInstancedQuestObjective::*)(RE::BSStringT<char,4294967295,RE::DynamicMemoryManagementPol>_&)const_,RE::BGSInstancedQuestObjective_const_*,RE::BSStringT<char,4294967295,RE::DynamicMemoryManagementPol>_&>
                (&local_118,&local_120,pBVar8);
      pcVar5 = "";
      if (local_130._data != (char *)0x0) {
        pcVar5 = local_130._data;
      }
      RE::GFxValue::GFxValue(local_108,pcVar5);
      RE::GFxValue::SetDisplayInfo(local_f0,(DisplayInfo *)local_108);
      RE::GFxValue::~GFxValue(local_108);
      local_138 = 0;
      RE::free(local_130._data);
      local_130._data = (char *)0x0;
      puVar9 = puVar9 + 1;
      this = local_110;
    } while (puVar9 != puVar1);
  }
  plVar6 = (longlong *)(param_1 + 0x10);
  if (0xf < *(ulonglong *)(param_1 + 0x28)) {
    plVar6 = (longlong *)*plVar6;
  }
  FUN_180045700(local_108);
  local_138 = 2;
  RE::GFxValue::GFxValue(local_c8,(double)*(int *)(param_1 + 8));
  RE::GFxValue::GFxValue(local_b0,(char *)plVar6);
  RE::GFxValue::GFxValue(local_98,*(bool *)(param_1 + 0x30));
  RE::GFxValue::GFxValue(local_80,local_f0);
  RE::GFxValue::GFxValue(local_68,(double)*(int *)(param_1 + 0x50));
  local_148 = 5;
  cVar3 = RE::GFxValue::Invoke((undefined8 *)this,"AddQuest",local_108);
  if (cVar3 == '\0') {
    _eh_vector_destructor_iterator_(local_c8,0x18,5,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(local_c8,0x18,5,RE::GFxValue::~GFxValue);
  }
  RE::GFxValue::~GFxValue(local_108);
  RE::GFxValue::~GFxValue(local_f0);
  __security_check_cookie(local_48 ^ (ulonglong)auStack_168);
  return;
}


/* ---- 0x180002780  QuestItemList::SetQuestSide  (196 bytes) ---- */

void __thiscall QuestItemList::QuestItemList__SetQuestSide(QuestItemList *this,undefined8 *param_1)

{
  char cVar1;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_48;
  undefined8 local_40 [3];
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = 0;
  if (0xf < (ulonglong)param_1[3]) {
    param_1 = (undefined8 *)*param_1;
  }
  FUN_180045700(local_40);
  local_48 = 1;
  RE::GFxValue::GFxValue(local_28,(char *)param_1);
  local_58 = 1;
  cVar1 = RE::GFxValue::Invoke((undefined8 *)this,"SetQuestSide",local_40);
  if (cVar1 == '\0') {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  RE::GFxValue::~GFxValue(local_40);
  __security_check_cookie(local_10 ^ (ulonglong)auStack_78);
  return;
}


/* ---- 0x180002850  QuestItemList::Update  (187 bytes) ---- */

void __thiscall QuestItemList::QuestItemList__Update(QuestItemList *this)

{
  char cVar1;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_48;
  undefined8 local_40 [3];
  undefined8 local_28 [3];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = 0;
  FUN_180045700(local_40);
  local_48 = 1;
  __builtin_array_init_helper_eh<RE::GFxValue>(local_28);
  local_58 = 0;
  cVar1 = RE::GFxValue::Invoke((undefined8 *)this,"Update",local_40);
  if (cVar1 == '\0') {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  RE::GFxValue::~GFxValue(local_40);
  __security_check_cookie(local_10 ^ (ulonglong)auStack_78);
  return;
}


/* ---- 0x180002910  QuestItemList::ShowAllQuests  (187 bytes) ---- */

void __thiscall QuestItemList::QuestItemList__ShowAllQuests(QuestItemList *this)

{
  char cVar1;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_48;
  undefined8 local_40 [3];
  undefined8 local_28 [3];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = 0;
  FUN_180045700(local_40);
  local_48 = 1;
  __builtin_array_init_helper_eh<RE::GFxValue>(local_28);
  local_58 = 0;
  cVar1 = RE::GFxValue::Invoke((undefined8 *)this,"ShowAllQuests",local_40);
  if (cVar1 == '\0') {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  RE::GFxValue::~GFxValue(local_40);
  __security_check_cookie(local_10 ^ (ulonglong)auStack_78);
  return;
}


/* ---- 0x1800029d0  QuestItemList::RemoveAllQuests  (187 bytes) ---- */

void __thiscall QuestItemList::QuestItemList__RemoveAllQuests(QuestItemList *this)

{
  char cVar1;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_48;
  undefined8 local_40 [3];
  undefined8 local_28 [3];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = 0;
  FUN_180045700(local_40);
  local_48 = 1;
  __builtin_array_init_helper_eh<RE::GFxValue>(local_28);
  local_58 = 0;
  cVar1 = RE::GFxValue::Invoke((undefined8 *)this,"RemoveAllQuests",local_40);
  if (cVar1 == '\0') {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  RE::GFxValue::~GFxValue(local_40);
  __security_check_cookie(local_10 ^ (ulonglong)auStack_78);
  return;
}


/* ---- 0x18003d8f0  QuestItemList::InitSingleton  (387 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void QuestItemList__InitSingleton(undefined8 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  float local_48 [2];
  undefined8 local_40 [3];
  undefined8 local_28 [3];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_48[0] = 0.0;
  if (DAT_1801d9528 == (undefined *)0x0) {
    if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
                0x14) < DAT_1801d9708) {
      _Init_thread_header(&DAT_1801d9708);
      if (DAT_1801d9708 == -1) {
        RE::GFxValue::GFxValue(&DAT_1801d9710,param_1);
        DAT_1801d9730 = 0;
        cVar1 = FUN_180045f60((undefined8 *)&DAT_1801d9710,"QuestItemList");
        if (cVar1 != '\0') {
          FUN_180045700(local_40);
          local_48[0] = 1.4013e-45;
          __builtin_array_init_helper_eh<RE::GFxValue>(local_28);
          local_58 = 0;
          cVar1 = RE::GFxValue::Invoke((undefined8 *)&DAT_1801d9710,"QuestItemList",local_40);
          if (cVar1 == '\0') {
            _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
          }
          else {
            _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
          }
          RE::GFxValue::~GFxValue(local_40);
          puVar2 = (undefined4 *)FUN_18003d3a0((undefined8 *)&DAT_1801d9710,local_48);
          _DAT_1801d9728 = *puVar2;
          _DAT_1801d972c = puVar2[1];
        }
        atexit((_func_5014 *)&LAB_180162130);
        _Init_thread_footer(&DAT_1801d9708);
      }
    }
    DAT_1801d9528 = &DAT_1801d9710;
  }
  __security_check_cookie(local_10 ^ (ulonglong)auStack_78);
  return;
}


/* ---- 0x18003dc40  QuestItemList::AddToHudElements  (187 bytes) ---- */

void __thiscall QuestItemList::QuestItemList__AddToHudElements(QuestItemList *this)

{
  char cVar1;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_48;
  undefined8 local_40 [3];
  undefined8 local_28 [3];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = 0;
  FUN_180045700(local_40);
  local_48 = 1;
  __builtin_array_init_helper_eh<RE::GFxValue>(local_28);
  local_58 = 0;
  cVar1 = RE::GFxValue::Invoke((undefined8 *)this,"AddToHudElements",local_40);
  if (cVar1 == '\0') {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  RE::GFxValue::~GFxValue(local_40);
  __security_check_cookie(local_10 ^ (ulonglong)auStack_78);
  return;
}


/* ---- 0x18003dd00  QuestItemList::InitSingleton  (279 bytes)   [名称未经人工确认] ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void QuestItemList__InitSingleton(undefined8 param_1,undefined8 *param_2)

{
  char cVar1;
  undefined8 *puVar2;
  undefined1 auStack_88 [32];
  undefined8 uStack_68;
  float afStack_58 [2];
  undefined *puStack_50;
  undefined8 auStack_48 [3];
  undefined8 auStack_30 [3];
  ulonglong uStack_18;
  
  uStack_18 = __security_cookie ^ (ulonglong)auStack_88;
  afStack_58[0] = 0.0;
  puStack_50 = &DAT_1801d9710;
  RE::GFxValue::GFxValue(&DAT_1801d9710,param_2);
  DAT_1801d9730 = 0;
  cVar1 = FUN_180045f60((undefined8 *)&DAT_1801d9710,"QuestItemList");
  if (cVar1 != '\0') {
    FUN_180045700(auStack_48);
    afStack_58[0] = 1.4013e-45;
    __builtin_array_init_helper_eh<RE::GFxValue>(auStack_30);
    uStack_68 = 0;
    cVar1 = RE::GFxValue::Invoke((undefined8 *)&DAT_1801d9710,"QuestItemList",auStack_48);
    if (cVar1 == '\0') {
      _eh_vector_destructor_iterator_(auStack_30,0x18,1,RE::GFxValue::~GFxValue);
    }
    else {
      _eh_vector_destructor_iterator_(auStack_30,0x18,1,RE::GFxValue::~GFxValue);
    }
    RE::GFxValue::~GFxValue(auStack_48);
    puVar2 = (undefined8 *)FUN_18003d3a0((undefined8 *)&DAT_1801d9710,afStack_58);
    _DAT_1801d9728 = *puVar2;
  }
  __security_check_cookie(uStack_18 ^ (ulonglong)auStack_88);
  return;
}


