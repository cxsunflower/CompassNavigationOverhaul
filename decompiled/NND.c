/* ============================================================
 * NND.c  ——  CompassNavigationOverhaul 2.9.9 反编译产物
 * 由 Ghidra 11.3.2 反编译器从 SKSE/Plugins/CompassNavigationOverhaul.dll 导出。
 * 函数名来自 2.2.0-VR 版 PDB 的跨版本符号映射；FUN_xxxxxxxx 表示尚未对上真名。
 * 共 3 个函数。这是「2.9.9 行为的唯一事实来源」，不可直接编译。
 * ============================================================ */

/* ---- 0x180043d90  NND::API::RequestPluginAPI  (52 bytes) ---- */

void NND__API__RequestPluginAPI(void)

{
  HMODULE hModule;
  FARPROC UNRECOVERED_JUMPTABLE;
  
  hModule = GetModuleHandleW((LPCWSTR)"NPCsNamesDistributor.dll");
  UNRECOVERED_JUMPTABLE = GetProcAddress(hModule,"RequestPluginAPI");
  if (UNRECOVERED_JUMPTABLE != (FARPROC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000180043dbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(0);
    return;
  }
  return;
}


/* ---- 0x180043dd0  NND::NPCNameProvider::GetName  (65 bytes) ---- */

char * __thiscall
NND::NPCNameProvider::NND__NPCNameProvider__GetName(NPCNameProvider *this,Actor *param_1)

{
  undefined8 *puVar1;
  char *pcVar2;
  char *local_18;
  longlong local_10;
  
  puVar1 = *(undefined8 **)this;
  if (puVar1 != (undefined8 *)0x0) {
    (**(code **)*puVar1)(puVar1,&local_18,param_1,7);
    if (local_10 != 0) {
      return local_18;
    }
  }
  pcVar2 = (char *)FUN_18006bb80(param_1);
  return pcVar2;
}


/* ---- 0x180043e20  NND::NPCNameProvider::RequestAPI  (329 bytes) ---- */

void NND__NPCNameProvider__RequestAPI(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  HMODULE hModule;
  FARPROC pFVar1;
  logger *plVar2;
  INT_PTR local_res8;
  char *local_58;
  undefined8 local_50;
  char *local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char *local_38;
  char *local_28;
  undefined8 uStack_20;
  char *local_18;
  
  if (*param_1 == 0) {
    hModule = GetModuleHandleW((LPCWSTR)"NPCsNamesDistributor.dll");
    pFVar1 = GetProcAddress(hModule,"RequestPluginAPI");
    if (pFVar1 == (FARPROC)0x0) {
      *param_1 = 0;
    }
    else {
      local_res8 = (*pFVar1)(0);
      *param_1 = local_res8;
      if (local_res8 != 0) {
        plVar2 = spdlog::default_logger_raw();
        uStack_40 = 0x17;
        local_48 = 
        "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\NND\\NPCNameProvider.cpp"
        ;
        uStack_3c = uStack_20._4_4_;
        uStack_20 = CONCAT44(uStack_20._4_4_,0x17);
        local_38 = "void __cdecl NND::NPCNameProvider::RequestAPI(void)";
        local_58 = "Obtained NND API - {0:x}";
        local_50 = 0x18;
        local_28 = 
        "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\NND\\NPCNameProvider.cpp"
        ;
        local_18 = "void __cdecl NND::NPCNameProvider::RequestAPI(void)";
        spdlog::logger::log_<unsigned___int64>
                  ((logger *)plVar2,(ulonglong *)&local_28,(level_enum)param_3,
                   (ulonglong *)&local_58,&local_res8);
        return;
      }
    }
    plVar2 = spdlog::default_logger_raw();
    uStack_40 = 0x19;
    local_48 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\NND\\NPCNameProvider.cpp"
    ;
    uStack_3c = uStack_20._4_4_;
    uStack_20 = CONCAT44(uStack_20._4_4_,0x19);
    local_50 = 0x18;
    local_38 = "void __cdecl NND::NPCNameProvider::RequestAPI(void)";
    local_58 = "Failed to obtain NND API";
    local_28 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\NND\\NPCNameProvider.cpp"
    ;
    local_18 = "void __cdecl NND::NPCNameProvider::RequestAPI(void)";
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)plVar2,&local_28,3,(ulonglong *)&local_58);
  }
  return;
}


