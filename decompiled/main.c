/* ============================================================
 * main.c  ——  CompassNavigationOverhaul 2.9.9 反编译产物
 * 由 Ghidra 11.3.2 反编译器从 SKSE/Plugins/CompassNavigationOverhaul.dll 导出。
 * 函数名来自 2.2.0-VR 版 PDB 的跨版本符号映射；FUN_xxxxxxxx 表示尚未对上真名。
 * 共 2 个函数。这是「2.9.9 行为的唯一事实来源」，不可直接编译。
 * ============================================================ */

/* ---- 0x18004fe40  SKSEPlugin_Load  (638 bytes) ---- */

bool __cdecl SKSEPlugin_Load(longlong param_1)

{
  String<256> *pSVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  undefined1 extraout_AL;
  char *pcVar5;
  PluginDeclaration *pPVar6;
  undefined8 *puVar7;
  logger *plVar8;
  MessagingInterface *this;
  ulonglong uVar9;
  void *_Memory;
  longlong lVar10;
  level_enum lVar11;
  undefined1 auStackY_e8 [32];
  undefined1 local_b8 [16];
  undefined8 local_a8;
  longlong local_a0;
  String<256> *local_98;
  longlong local_90;
  char *local_88;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  char *local_78;
  char *local_68;
  undefined8 uStack_60;
  char *local_58;
  void *local_48 [3];
  ulonglong local_30;
  ulonglong local_28;
  String<256> **ppSVar12;
  
                    /* 0x4fe40  1  SKSEPlugin_Load
                       0x5df10  1  SKSEPlugin_Load */
  local_28 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_b8[0] = 0;
  cVar3 = std::_Atomic_reinterpret_as<char,bool>(local_b8);
  pcVar5 = std::_Atomic_address_as<char,std::_Atomic_padded<bool>_>
                     ((_Atomic_padded<bool> *)&REL::Module::_initialized);
  LOCK();
  *pcVar5 = cVar3;
  UNLOCK();
  REL::Module::clear((Module *)&REL::Module::_instance);
  pPVar6 = SKSE::PluginDeclaration::GetSingleton();
  lVar10 = -1;
  local_a0 = -1;
  pSVar1 = &(pPVar6->_data).Name;
  do {
    local_a0 = local_a0 + 1;
  } while (pSVar1->_buffer[local_a0] != '\0');
  local_a8 = pSVar1->_buffer;
  bVar4 = SKSE::log::init(&local_a8);
  if (bVar4) {
    uVar2 = (pPVar6->_data).Version._packed;
    ppSVar12 = &local_98;
    local_90 = 1;
    local_a8._0_4_ = CONCAT22((short)(uVar2 >> 0x10),(ushort)(byte)(uVar2 >> 0x18)) & 0xffffff;
    local_a8._0_6_ = (uint6)(uint)local_a8;
    local_a8 = (char *)(CONCAT26((short)uVar2,(uint6)local_a8) & 0xfffffffffffff);
    local_a8 = (char *)(CONCAT26(local_a8._6_2_,CONCAT24((short)(uVar2 >> 4),(uint)local_a8)) &
                       0xffff0fffffffffff);
    local_98 = (String<256> *)&DAT_180191828;
    puVar7 = (undefined8 *)FUN_18000f090((ushort *)&local_a8,(longlong *)local_48,ppSVar12);
    lVar11 = (level_enum)ppSVar12;
    do {
      lVar10 = lVar10 + 1;
    } while (pSVar1->_buffer[lVar10] != '\0');
    local_98 = pSVar1;
    local_90 = lVar10;
    plVar8 = spdlog::default_logger_raw();
    uStack_7c = uStack_60._4_4_;
    local_88 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\main.cpp"
    ;
    local_a8 = "Loading {} {}...";
    uStack_80 = 0x18;
    uStack_60 = CONCAT44(uStack_60._4_4_,0x18);
    local_78 = "bool __cdecl SKSEPlugin_Load(const class SKSE::LoadInterface *)";
    local_a0 = 0x10;
    local_68 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\main.cpp"
    ;
    local_58 = "bool __cdecl SKSEPlugin_Load(const class SKSE::LoadInterface *)";
    spdlog::logger::log_<std::basic_string_view<char,std::char_traits<char>_>,REL::Version>
              ((logger *)plVar8,(ulonglong *)&local_68,lVar11,&local_a8,&local_98,puVar7);
    if (0xf < local_30) {
      _Memory = local_48[0];
      if ((0xfff < local_30 + 1) &&
         (_Memory = *(void **)((longlong)local_48[0] + -8),
         0x1f < (ulonglong)((longlong)local_48[0] + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      free(_Memory);
    }
    FUN_1800a1ee0(param_1,'\0');
    SKSE::log::set_level(DAT_1801cf5f0,DAT_1801cf5f0);
    this = (MessagingInterface *)FUN_1800a1c70();
    uVar9 = SKSE::MessagingInterface::RegisterListener(this,"SKSE",SKSEMessageListener);
    if ((char)uVar9 != '\0') {
      hooks__Install();
      SKSE::log::set_level(info,info);
      plVar8 = spdlog::default_logger_raw();
      uStack_7c = uStack_60._4_4_;
      local_88 = 
      "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\main.cpp"
      ;
      local_98 = (String<256> *)0x180191800;
      uStack_80 = 0x26;
      uStack_60 = CONCAT44(uStack_60._4_4_,0x26);
      local_78 = "bool __cdecl SKSEPlugin_Load(const class SKSE::LoadInterface *)";
      local_68 = 
      "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\main.cpp"
      ;
      local_90 = 0x13;
      local_58 = "bool __cdecl SKSEPlugin_Load(const class SKSE::LoadInterface *)";
      spdlog::logger::hooks__compat__MapMarkerFramework__Install
                ((logger *)plVar8,&local_68,2,(ulonglong *)&local_98);
    }
  }
  __security_check_cookie(local_28 ^ (ulonglong)auStackY_e8);
  return (bool)extraout_AL;
}


/* ---- 0x18005e350  SKSEPlugin_Query  (76 bytes) ---- */

bool __cdecl SKSEPlugin_Query(QueryInterface *param_1,undefined4 *param_2)

{
                    /* 0x5e350  2  SKSEPlugin_Query
                       0x71560  2  SKSEPlugin_Query */
  *param_2 = 1;
  *(char **)(param_2 + 2) = s_CompassNavigationOverhaul_1801cf608;
  param_2[4] = ((DAT_1801cf604 >> 0x10 & 0xff | (DAT_1801cf604 >> 0x18) << 8) << 0xc |
               DAT_1801cf604 >> 4 & 0xfff) << 4 | DAT_1801cf604 & 0xf;
  return true;
}


