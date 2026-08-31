/* ============================================================
 * Compass.c  ——  CompassNavigationOverhaul 2.9.9 反编译产物
 * 由 Ghidra 11.3.2 反编译器从 SKSE/Plugins/CompassNavigationOverhaul.dll 导出。
 * 函数名来自 2.2.0-VR 版 PDB 的跨版本符号映射；FUN_xxxxxxxx 表示尚未对上真名。
 * 共 10 个函数。这是「2.9.9 行为的唯一事实来源」，不可直接编译。
 * ============================================================ */

/* ---- 0x180001ee0  CNO::Compass::Marker::Marker  (564 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

undefined8 * __thiscall
CNO::Compass::Marker::CNO__Compass__Marker__Marker
          (Marker *this,longlong *param_1,float param_2,uint param_3,uint param_4,
          undefined8 *param_5)

{
  TESObjectREFR *this_00;
  PlayerCharacter *pPVar1;
  TESWorldSpace *pTVar2;
  float *pfVar3;
  float fVar4;
  undefined8 local_48;
  float local_40;
  undefined8 local_38;
  float local_30;
  undefined8 local_28;
  float local_20;
  float local_18 [4];
  
  this->angleToPlayerCamera = param_2;
  this->ref = (TESObjectREFR *)param_1;
  pPVar1 = RE::PlayerCharacter::GetSingleton();
  local_28 = *(undefined8 *)&pPVar1->field_0x54;
  local_20 = *(float *)&pPVar1->field_0x5c;
  pTVar2 = RE::TESObjectREFR::GetWorldspace(pPVar1);
  if (pTVar2 != (TESWorldSpace *)0x0) {
    local_48._0_4_ = (pTVar2->worldMapOffsetData).mapOffsetX;
    local_48._4_4_ = (pTVar2->worldMapOffsetData).mapOffsetY;
    local_40 = (pTVar2->worldMapOffsetData).mapOffsetZ;
    pfVar3 = RE::NiPoint3::operator*
                       ((NiPoint3 *)&local_48,(float *)&local_38,
                        (pTVar2->worldMapOffsetData).mapScale);
    RE::NiPoint3::operator+=((NiPoint3 *)&local_28,pfVar3);
  }
  local_38 = *(undefined8 *)((longlong)param_1 + 0x54);
  local_30 = *(float *)((longlong)param_1 + 0x5c);
  pTVar2 = RE::TESObjectREFR::GetWorldspace(param_1);
  if (pTVar2 != (TESWorldSpace *)0x0) {
    local_48._0_4_ = (pTVar2->worldMapOffsetData).mapOffsetX;
    local_48._4_4_ = (pTVar2->worldMapOffsetData).mapOffsetY;
    local_40 = (pTVar2->worldMapOffsetData).mapOffsetZ;
    pfVar3 = RE::NiPoint3::operator*
                       ((NiPoint3 *)&local_48,local_18,(pTVar2->worldMapOffsetData).mapScale);
    RE::NiPoint3::operator+=((NiPoint3 *)&local_38,pfVar3);
  }
  fVar4 = RE::NiPoint3::GetDistance((NiPoint3 *)&local_28,(float *)&local_38);
  this_00 = this->ref;
  this->distanceToPlayer = fVar4;
  pPVar1 = RE::PlayerCharacter::GetSingleton();
  local_40 = *(float *)&pPVar1->field_0x5c;
  local_48 = *(undefined8 *)&pPVar1->field_0x54;
  pTVar2 = RE::TESObjectREFR::GetWorldspace(pPVar1);
  if (pTVar2 != (TESWorldSpace *)0x0) {
    local_28._0_4_ = (pTVar2->worldMapOffsetData).mapOffsetX;
    local_28._4_4_ = (pTVar2->worldMapOffsetData).mapOffsetY;
    local_20 = (pTVar2->worldMapOffsetData).mapOffsetZ;
    pfVar3 = RE::NiPoint3::operator*
                       ((NiPoint3 *)&local_28,local_18,(pTVar2->worldMapOffsetData).mapScale);
    RE::NiPoint3::operator+=((NiPoint3 *)&local_48,pfVar3);
  }
  local_38._0_4_ = (this_00->data).location.x;
  local_38._4_4_ = (this_00->data).location.y;
  local_30 = (this_00->data).location.z;
  pTVar2 = RE::TESObjectREFR::GetWorldspace(this_00);
  if (pTVar2 != (TESWorldSpace *)0x0) {
    local_28._0_4_ = (pTVar2->worldMapOffsetData).mapOffsetX;
    local_28._4_4_ = (pTVar2->worldMapOffsetData).mapOffsetY;
    local_20 = (pTVar2->worldMapOffsetData).mapOffsetZ;
    pfVar3 = RE::NiPoint3::operator*
                       ((NiPoint3 *)&local_28,local_18,(pTVar2->worldMapOffsetData).mapScale);
    RE::NiPoint3::operator+=((NiPoint3 *)&local_38,pfVar3);
  }
  this->icon = param_4;
  this->index = param_3;
  this->heightDifference = local_30 - local_40;
  (this->description)._Mypair._Myval2._Bx._Ptr = (char *)0x0;
  *(undefined8 *)((longlong)&(this->description)._Mypair._Myval2._Bx + 8) = 0;
  (this->description)._Mypair._Myval2._Mysize = 0;
  (this->description)._Mypair._Myval2._Myres = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Construct<1,char_const_*>
            (&this->description,(void *)*param_5,param_5[1]);
  return &this->ref;
}


/* ---- 0x180002120  CNO::Compass::SetFocusedMarkerInfo  (266 bytes) ---- */

void CNO__Compass__SetFocusedMarkerInfo
               (undefined8 *param_1,undefined8 *param_2,float param_3,float param_4,uint param_5)

{
  char cVar1;
  char *pcVar2;
  undefined1 auStack_c8 [32];
  undefined8 uStack_a8;
  undefined4 uStack_98;
  undefined8 auStack_90 [3];
  undefined1 auStack_78 [24];
  undefined1 auStack_60 [24];
  undefined1 auStack_48 [24];
  undefined1 auStack_30 [24];
  ulonglong uStack_18;
  
  uStack_18 = __security_cookie ^ (ulonglong)auStack_c8;
  uStack_98 = 0;
  pcVar2 = (char *)*param_2;
  FUN_180045700(auStack_90);
  uStack_98 = 1;
  RE::GFxValue::GFxValue(auStack_78,pcVar2);
  RE::GFxValue::GFxValue(auStack_60,(double)param_3);
  RE::GFxValue::GFxValue(auStack_48,(double)param_4);
  RE::GFxValue::GFxValue(auStack_30,(double)param_5);
  uStack_a8 = 4;
  cVar1 = RE::GFxValue::Invoke(param_1,"SetFocusedMarkerInfo",auStack_90);
  if (cVar1 == '\0') {
    _eh_vector_destructor_iterator_(auStack_78,0x18,4,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(auStack_78,0x18,4,RE::GFxValue::~GFxValue);
  }
  RE::GFxValue::~GFxValue(auStack_90);
  __security_check_cookie(uStack_18 ^ (ulonglong)auStack_c8);
  return;
}


/* ---- 0x180002230  CNO::Compass::FocusMarker  (187 bytes) ---- */

void __thiscall CNO::Compass::CNO__Compass__FocusMarker(Compass *this)

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
  cVar1 = RE::GFxValue::Invoke((undefined8 *)this,"FocusMarker",local_40);
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


/* ---- 0x1800022f0  CNO::Compass::UnfocusMarker  (187 bytes) ---- */

void __thiscall CNO::Compass::CNO__Compass__UnfocusMarker(Compass *this)

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
  cVar1 = RE::GFxValue::Invoke((undefined8 *)this,"UnfocusMarker",local_40);
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


/* ---- 0x1800023b0  CNO::Compass::UpdateFocusedMarker  (187 bytes) ---- */

void __thiscall CNO::Compass::CNO__Compass__UpdateFocusedMarker(Compass *this)

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
  cVar1 = RE::GFxValue::Invoke((undefined8 *)this,"UpdateFocusedMarker",local_40);
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


/* ---- 0x180006360  CNO::Compass::Marker::Marker  (67 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

undefined8 * __thiscall
CNO::Compass::Marker::CNO__Compass__Marker__Marker(Marker *this,undefined8 *param_1)

{
  this->ref = (TESObjectREFR *)*param_1;
  this->angleToPlayerCamera = *(float *)(param_1 + 1);
  this->distanceToPlayer = *(float *)((longlong)param_1 + 0xc);
  this->heightDifference = *(float *)(param_1 + 2);
  this->index = *(uint *)((longlong)param_1 + 0x14);
  this->icon = *(uint *)(param_1 + 3);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(&this->description,param_1 + 4);
  return &this->ref;
}


/* ---- 0x18003d5e0  CNO::Compass::InitSingleton  (158 bytes)   [名称未经人工确认] ---- */

void __cdecl CNO::Compass::CNO__Compass__CNO__Compass__InitSingleton(undefined8 *param_1)

{
  if (DAT_1801d9530 == (undefined *)0x0) {
    if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
                0x14) < DAT_1801d96e8) {
      _Init_thread_header(&DAT_1801d96e8);
      if (DAT_1801d96e8 == -1) {
        RE::GFxValue::GFxValue(&DAT_1801d96f0,param_1);
        atexit((_func_5014 *)&LAB_180162120);
        _Init_thread_footer(&DAT_1801d96e8);
        DAT_1801d9530 = &DAT_1801d96f0;
        return;
      }
    }
    DAT_1801d9530 = &DAT_1801d96f0;
  }
  return;
}


/* ---- 0x18003d680  CNO::Compass::InitSingleton  (237 bytes) ---- */

void CNO__Compass__InitSingleton(undefined8 *param_1,undefined8 *param_2)

{
  char cVar1;
  undefined1 auStack_78 [32];
  undefined8 uStack_58;
  undefined4 uStack_48;
  undefined8 auStack_40 [3];
  undefined8 auStack_28 [3];
  ulonglong uStack_10;
  
  uStack_10 = __security_cookie ^ (ulonglong)auStack_78;
  uStack_48 = 0;
  cVar1 = FUN_180045f60(param_2,"Compass");
  if (cVar1 != '\0') {
    RE::GFxValue::operator=(param_1,param_2);
    FUN_180045700(auStack_40);
    uStack_48 = 1;
    __builtin_array_init_helper_eh<RE::GFxValue>(auStack_28);
    uStack_58 = 0;
    cVar1 = RE::GFxValue::Invoke(param_1,"Compass",auStack_40);
    if (cVar1 == '\0') {
      _eh_vector_destructor_iterator_(auStack_28,0x18,1,RE::GFxValue::~GFxValue);
    }
    else {
      _eh_vector_destructor_iterator_(auStack_28,0x18,1,RE::GFxValue::~GFxValue);
    }
    RE::GFxValue::~GFxValue(auStack_40);
  }
  __security_check_cookie(uStack_10 ^ (ulonglong)auStack_78);
  return;
}


/* ---- 0x18003d770  CNO::Compass::SetUnits  (193 bytes) ---- */

void CNO::Compass::CNO__Compass__SetUnits(undefined8 *param_1)

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
  FUN_180045700(local_40);
  local_48 = 1;
  RE::GFxValue::GFxValue(local_28,(bool)DAT_1801d9560);
  local_58 = 1;
  cVar1 = RE::GFxValue::Invoke(param_1,"SetUnits",local_40);
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


/* ---- 0x18003d840  CNO::Compass::Compass  (30 bytes) ---- */

undefined * __thiscall CNO::Compass::CNO__Compass__Compass(Compass *this,undefined8 *param_1)

{
  RE::GFxValue::GFxValue(&DAT_1801d96f0,param_1);
  return &DAT_1801d96f0;
}


