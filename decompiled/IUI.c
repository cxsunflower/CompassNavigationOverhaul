/* ============================================================
 * IUI.c  ——  CompassNavigationOverhaul 2.9.9 反编译产物
 * 由 Ghidra 11.3.2 反编译器从 SKSE/Plugins/CompassNavigationOverhaul.dll 导出。
 * 函数名来自 2.2.0-VR 版 PDB 的跨版本符号映射；FUN_xxxxxxxx 表示尚未对上真名。
 * 共 6 个函数。这是「2.9.9 行为的唯一事实来源」，不可直接编译。
 * ============================================================ */

/* ---- 0x1800050b0  IUI::GFxObject::Invoke<char_const_*>  (188 bytes) ---- */

GFxValue * __thiscall
IUI::GFxObject::IUI__GFxObject__Invoke_char_const___
          (GFxObject *this,undefined8 *__return_storage_ptr__,undefined8 *param_2,
          undefined8 *param_3)

{
  char cVar1;
  GFxValue *extraout_RAX;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined4 local_38;
  undefined8 *local_30;
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = 0;
  local_30 = __return_storage_ptr__;
  FUN_180045700(__return_storage_ptr__);
  local_38 = 1;
  RE::GFxValue::GFxValue(local_28,(char *)*param_3);
  local_48 = 1;
  cVar1 = RE::GFxValue::Invoke((undefined8 *)this,*param_2,__return_storage_ptr__);
  if (cVar1 == '\0') {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  __security_check_cookie(local_10 ^ (ulonglong)auStack_68);
  return extraout_RAX;
}


/* ---- 0x1800064c0  IUI::GFxObject::Invoke<char_const_*_&>  (120 bytes) ---- */

bool __thiscall
IUI::GFxObject::IUI__GFxObject__Invoke_char_const_____
          (GFxObject *this,undefined8 *param_1,GFxValue *param_2,undefined8 *param_3)

{
  undefined1 extraout_AL;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  RE::GFxValue::GFxValue(local_28,(char *)*param_3);
  local_38 = 1;
  RE::GFxValue::Invoke((undefined8 *)this,*param_1,param_2);
  _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  __security_check_cookie(local_10 ^ (ulonglong)auStack_58);
  return (bool)extraout_AL;
}


/* ---- 0x18003db70  IUI::GFxObject::Invoke<float_&,float_&,float_&>  (197 bytes) ---- */

void IUI::GFxObject::IUI__GFxObject__Invoke_float___float___float___(undefined8 *param_1)

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
  RE::GFxValue::GFxValue(local_28,(double)DAT_1801cf5e4);
  local_58 = 1;
  cVar1 = RE::GFxValue::Invoke(param_1,"SetMaxHeight",local_40);
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


/* ---- 0x18003f980  IUI::GFxObject::Invoke<bool_&>  (189 bytes) ---- */

GFxValue * __thiscall
IUI::GFxObject::IUI__GFxObject__Invoke_bool___
          (GFxObject *this,undefined8 *__return_storage_ptr__,undefined8 *param_2,
          undefined1 *param_3)

{
  char cVar1;
  GFxValue *extraout_RAX;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined4 local_38;
  undefined8 *local_30;
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = 0;
  local_30 = __return_storage_ptr__;
  FUN_180045700(__return_storage_ptr__);
  local_38 = 1;
  RE::GFxValue::GFxValue(local_28,(bool)*param_3);
  local_48 = 1;
  cVar1 = RE::GFxValue::Invoke((undefined8 *)this,*param_2,__return_storage_ptr__);
  if (cVar1 == '\0') {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  __security_check_cookie(local_10 ^ (ulonglong)auStack_68);
  return extraout_RAX;
}


/* ---- 0x18003fa40  IUI::GFxObject::Invoke<float_&,float_&,float_&>  (193 bytes) ---- */

void IUI::GFxObject::IUI__GFxObject__Invoke_float___float___float___
               (undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,float *param_4)

{
  char cVar1;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined4 local_38;
  undefined8 *local_30;
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = 0;
  local_30 = param_2;
  FUN_180045700(param_2);
  local_38 = 1;
  RE::GFxValue::GFxValue(local_28,(double)*param_4);
  local_48 = 1;
  cVar1 = RE::GFxValue::Invoke(param_1,*param_3,param_2);
  if (cVar1 == '\0') {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  else {
    _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  }
  __security_check_cookie(local_10 ^ (ulonglong)auStack_68);
  return;
}


/* ---- 0x180040450  IUI::GFxObject::Invoke<bool_&>  (121 bytes) ---- */

bool __thiscall
IUI::GFxObject::IUI__GFxObject__Invoke_bool___
          (GFxObject *this,undefined8 *param_1,GFxValue *param_2,undefined1 *param_3)

{
  undefined1 extraout_AL;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  RE::GFxValue::GFxValue(local_28,(bool)*param_3);
  local_38 = 1;
  RE::GFxValue::Invoke((undefined8 *)this,*param_1,param_2);
  _eh_vector_destructor_iterator_(local_28,0x18,1,RE::GFxValue::~GFxValue);
  __security_check_cookie(local_10 ^ (ulonglong)auStack_58);
  return (bool)extraout_AL;
}


