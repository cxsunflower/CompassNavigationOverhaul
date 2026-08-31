
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InfinityUIMessageListener(undefined8 *param_1)

{
  char cVar1;
  int iVar2;
  longlong *plVar3;
  undefined1 (*pauVar4) [32];
  undefined1 (*pauVar5) [32];
  ulonglong *puVar6;
  undefined1 *puVar7;
  logger *plVar8;
  undefined4 *puVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  undefined *puVar12;
  undefined8 *puVar13;
  undefined8 uVar14;
  undefined8 *puVar15;
  size_t sVar16;
  longlong lVar17;
  longlong lVar18;
  undefined8 uVar19;
  longlong lVar20;
  DataDescUnion *pDVar21;
  undefined4 uVar22;
  undefined1 auStackY_118 [32];
  char *pcStack_d8;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  char *pcStack_c8;
  DataDescUnion DStack_b8;
  undefined8 uStack_b0;
  char *pcStack_a8;
  float fStack_98;
  undefined4 auStack_94 [3];
  DataDescUnion DStack_88;
  undefined8 uStack_80;
  DataDescUnion DStack_78;
  undefined **ppuStack_70;
  char *pcStack_68;
  undefined8 uStack_60;
  char *pcStack_58;
  _Bxty _Stack_48;
  longlong lStack_38;
  ulonglong uStack_30;
  ulonglong uStack_28;
  
  if (param_1 == (undefined8 *)0x0) {
    return;
  }
  uStack_28 = __security_cookie ^ (ulonglong)auStackY_118;
  fStack_98 = 0.0;
  sVar16 = 0xffffffffffffffff;
  lVar17 = -1;
  do {
    lVar17 = lVar17 + 1;
  } while (*(char *)((longlong)*param_1 + lVar17) != '\0');
  if (((lVar17 != 10) || (iVar2 = memcmp((void *)*param_1,"InfinityUI",10), iVar2 != 0)) ||
     (param_1[2] == 0)) goto switchD_18003e61c_default;
  plVar3 = (longlong *)(**(code **)(**(longlong **)(param_1[2] + 8) + 8))();
  pauVar4 = (undefined1 (*) [32])(**(code **)(*plVar3 + 0x60))(plVar3);
  uVar10 = 0xffffffffffffffff;
  do {
    uVar10 = uVar10 + 1;
  } while ((*pauVar4)[uVar10] != '\0');
  if (((uVar10 < 7) ||
      (pauVar5 = (undefined1 (*) [32])
                 `anonymous_namespace'::
                 __std_search_impl<_anonymous_namespace_::_Find_traits_1,unsigned_char>
                           (pauVar4,(undefined1 (*) [32])(*pauVar4 + uVar10),
                            (undefined1 (*) [16])"HUDMenu",7), puVar15 = DAT_1801d9528,
      pauVar5 == (undefined1 (*) [32])(*pauVar4 + uVar10))) ||
     ((longlong)pauVar5 - (longlong)pauVar4 == -1)) goto switchD_18003e61c_default;
  ppuStack_70 = GFxMemberLogger<1>::vftable;
  switch(*(undefined4 *)(param_1 + 1)) {
  case 0:
    plVar8 = spdlog::default_logger_raw();
    DStack_b8 = (DataDescUnion)0x180190600;
    uStack_b0._0_4_ = 0x56;
    uVar22 = (undefined4)uStack_b0;
    uStack_b0 = CONCAT44(uStack_60._4_4_,0x56);
    pcStack_a8 = 
    "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
    DStack_88.data = (DataDesc *)0x180190888;
    uStack_80 = 0x1b;
    pDVar21 = &DStack_88;
    iVar2 = 2;
    goto LAB_18003f0ab;
  case 1:
    if ((*(int *)((longlong)param_1 + 0xc) != 0x18) || (lVar17 = param_1[2], lVar17 == 0))
    goto switchD_18003e61c_default;
    puVar6 = FUN_180045b20(*(undefined8 *)(lVar17 + 0x10),(ulonglong *)&DStack_78);
    puVar7 = FUN_1800a3e10(puVar6);
    _Stack_48._Ptr = (char *)0x0;
    _Stack_48._8_8_ = 0;
    lStack_38 = 0;
    uStack_30 = 0;
    do {
      sVar16 = sVar16 + 1;
    } while (puVar7[sVar16] != '\0');
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Construct<1,char_const_*>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&_Stack_48,puVar7,
               sVar16);
    RE::GString::~GString((GString *)&DStack_78.heapType);
    uVar10 = uStack_30;
    uVar14 = _Stack_48._Ptr;
    uVar11 = (char *)&_Stack_48;
    if (0xf < uStack_30) {
      uVar11 = _Stack_48._Ptr;
    }
    if ((lStack_38 == 0x3c) &&
       (iVar2 = memcmp("_level0.HUDMovieBaseInstance.CompassShoutMeterHolder.Compass",uVar11,0x3c),
       iVar2 == 0)) {
      puVar15 = *(undefined8 **)(lVar17 + 0x10);
      FUN_180045700(&pcStack_d8);
      RE::GFxValue::operator=(&pcStack_d8,puVar15);
      if (DAT_1801d9530 == (undefined8 *)0x0) {
        if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8)
                     + 0x14) < DAT_1801d96e8) &&
           (_Init_thread_header(&DAT_1801d96e8), DAT_1801d96e8 == -1)) {
          RE::GFxValue::GFxValue(&DAT_1801d96f0,&pcStack_d8);
          atexit((_func_5014 *)&LAB_180162120);
          _Init_thread_footer(&DAT_1801d96e8);
        }
        DAT_1801d9530 = (undefined8 *)&DAT_1801d96f0;
      }
      RE::GFxValue::~GFxValue(&pcStack_d8);
      puVar15 = DAT_1801d9530;
      plVar8 = spdlog::default_logger_raw();
      DStack_b8 = (DataDescUnion)0x180190600;
      uStack_b0 = CONCAT44(uStack_60._4_4_,0x62);
      pcStack_a8 = 
      "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
      DStack_88.data = (DataDesc *)0x1801908a8;
      uStack_80 = 0x11;
      pcStack_68 = 
      "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
      ;
      uStack_60 = uStack_b0;
      pcStack_58 = 
      "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
      uVar19 = 1;
      spdlog::logger::hooks__compat__MapMarkerFramework__Install
                ((logger *)plVar8,&pcStack_68,1,(ulonglong *)&DStack_88);
      FUN_180040080(&ppuStack_70,puVar15);
      FUN_18003d3a0(puVar15,&fStack_98);
      puVar6 = FUN_180045b20(puVar15,(ulonglong *)&DStack_88);
      DStack_78.data = (DataDesc *)FUN_1800a3e10(puVar6);
      plVar8 = spdlog::default_logger_raw();
      pcStack_d8 = 
      "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
      ;
      uStack_d0 = 0x66;
      uStack_cc = uStack_60._4_4_;
      pcStack_c8 = 
      "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
      DStack_b8 = (DataDescUnion)0x1801908c0;
      uStack_b0 = 0x11;
      uStack_60 = CONCAT44(uStack_60._4_4_,0x66);
      pcStack_68 = 
      "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
      ;
      pcStack_58 = 
      "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
      FUN_180042140(&plVar8->_padding_,(ulonglong *)&pcStack_68,uVar19,(ulonglong *)&DStack_b8,
                    &DStack_78,&fStack_98,auStack_94);
      RE::GString::~GString((GString *)&DStack_88.heapType);
      uVar14 = _Stack_48._Ptr;
      uVar10 = uStack_30;
    }
    if (uVar10 < 0x10) goto switchD_18003e61c_default;
    uVar11 = uVar14;
    if ((0xfff < uVar10 + 1) &&
       (uVar11 = (char *)*(longlong *)((longlong)uVar14 + -8),
       (char *)0x1f < uVar14 + (-8 - (longlong)uVar11))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    break;
  case 2:
    if ((*(int *)((longlong)param_1 + 0xc) != 0x28) || (lVar17 = param_1[2], lVar17 == 0))
    goto switchD_18003e61c_default;
    puVar6 = FUN_180045b20(*(undefined8 *)(lVar17 + 0x10),(ulonglong *)&DStack_88);
    puVar7 = FUN_1800a3e10(puVar6);
    _Stack_48._Ptr = (char *)0x0;
    _Stack_48._8_8_ = 0;
    lStack_38 = 0;
    uStack_30 = 0;
    do {
      sVar16 = sVar16 + 1;
    } while (puVar7[sVar16] != '\0');
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Construct<1,char_const_*>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&_Stack_48,puVar7,
               sVar16);
    RE::GString::~GString((GString *)&DStack_88.heapType);
    uVar10 = uStack_30;
    lVar20 = lStack_38;
    uVar14 = (char *)&_Stack_48;
    if (0xf < uStack_30) {
      uVar14 = _Stack_48._Ptr;
    }
    if ((lStack_38 == 0x3c) &&
       (lVar18 = lStack_38,
       iVar2 = memcmp("_level0.HUDMovieBaseInstance.CompassShoutMeterHolder.Compass",uVar14,0x3c),
       puVar15 = DAT_1801d9530, iVar2 == 0)) {
      if (DAT_1801d9530 == (undefined8 *)0x0) {
        plVar8 = spdlog::default_logger_raw();
        pcStack_d8 = 
        "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
        ;
        uStack_d0 = 0x7f;
        uStack_cc = uStack_60._4_4_;
        pcStack_c8 = 
        "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
        DStack_b8 = (DataDescUnion)0x1801908f0;
        uStack_b0 = 0x2d;
        uStack_60 = CONCAT44(uStack_60._4_4_,0x7f);
        pcStack_68 = 
        "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
        ;
        pcStack_58 = 
        "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
        spdlog::logger::log_<std::basic_string_view<char,std::char_traits<char>_>_const_&>
                  (&plVar8->_padding_,(ulonglong *)&pcStack_68,lVar18,(ulonglong *)&DStack_b8);
        uVar10 = uStack_30;
      }
      else {
        puVar13 = *(undefined8 **)(lVar17 + 0x10);
        FUN_180045700(&pcStack_d8);
        RE::GFxValue::operator=(&pcStack_d8,puVar13);
        cVar1 = FUN_180045f60(&pcStack_d8,"Compass");
        if (cVar1 != '\0') {
          RE::GFxValue::operator=(puVar15,&pcStack_d8);
          FUN_180045700(&DStack_b8);
          fStack_98 = 2.24208e-44;
          __builtin_array_init_helper_eh<RE::GFxValue>(&pcStack_68);
          cVar1 = RE::GFxValue::Invoke(puVar15,"Compass",&DStack_b8);
          if (cVar1 == '\0') {
            _eh_vector_destructor_iterator_(&pcStack_68,0x18,1,RE::GFxValue::~GFxValue);
          }
          else {
            _eh_vector_destructor_iterator_(&pcStack_68,0x18,1,RE::GFxValue::~GFxValue);
          }
          RE::GFxValue::~GFxValue(&DStack_b8);
        }
        RE::GFxValue::~GFxValue(&pcStack_d8);
        plVar8 = spdlog::default_logger_raw();
        pcStack_d8 = 
        "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
        ;
        uStack_d0 = 0x77;
        uStack_cc = uStack_60._4_4_;
        pcStack_c8 = 
        "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
        DStack_b8 = (DataDescUnion)0x1801908d8;
        uStack_b0 = 0x10;
        uStack_60._0_4_ = 0x77;
        pcStack_68 = 
        "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
        ;
        pcStack_58 = 
        "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
        uVar19 = 1;
        spdlog::logger::hooks__compat__MapMarkerFramework__Install
                  ((logger *)plVar8,&pcStack_68,1,(ulonglong *)&DStack_b8);
        FUN_180040080(&ppuStack_70,puVar15);
        FUN_18003d3a0(puVar15,&fStack_98);
        puVar6 = FUN_180045b20(puVar15,(ulonglong *)&DStack_78);
        DStack_88.data = (DataDesc *)FUN_1800a3e10(puVar6);
        plVar8 = spdlog::default_logger_raw();
        pcStack_d8 = 
        "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
        ;
        uStack_d0 = 0x7b;
        uStack_cc = uStack_60._4_4_;
        pcStack_c8 = 
        "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
        DStack_b8 = (DataDescUnion)0x1801908c0;
        uStack_b0 = 0x11;
        uStack_60 = CONCAT44(uStack_60._4_4_,0x7b);
        pcStack_68 = 
        "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
        ;
        pcStack_58 = 
        "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
        FUN_180042140(&plVar8->_padding_,(ulonglong *)&pcStack_68,uVar19,(ulonglong *)&DStack_b8,
                      &DStack_88,&fStack_98,auStack_94);
LAB_18003ece1:
        RE::GString::~GString((GString *)&DStack_78.heapType);
        uVar10 = uStack_30;
      }
    }
    else {
      uVar14 = (char *)&_Stack_48;
      if (0xf < uVar10) {
        uVar14 = _Stack_48._Ptr;
      }
      if ((lVar20 == 0x2a) &&
         (iVar2 = memcmp("_level0.HUDMovieBaseInstance.QuestItemList",uVar14,0x2a), iVar2 == 0)) {
        puVar15 = *(undefined8 **)(lVar17 + 0x10);
        FUN_180045700(&pcStack_d8);
        RE::GFxValue::operator=(&pcStack_d8,puVar15);
        if (DAT_1801d9528 == (undefined8 *)0x0) {
          if ((*(int *)(*(longlong *)
                         ((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 0x14) <
               DAT_1801d9708) && (_Init_thread_header(&DAT_1801d9708), DAT_1801d9708 == -1)) {
            RE::GFxValue::GFxValue(&DAT_1801d9710,&pcStack_d8);
            DAT_1801d9730 = 0;
            cVar1 = FUN_180045f60((undefined8 *)&DAT_1801d9710,"QuestItemList");
            if (cVar1 != '\0') {
              FUN_180045700(&DStack_b8);
              fStack_98 = 4.48416e-44;
              __builtin_array_init_helper_eh<RE::GFxValue>(&pcStack_68);
              cVar1 = RE::GFxValue::Invoke((undefined8 *)&DAT_1801d9710,"QuestItemList",&DStack_b8);
              if (cVar1 == '\0') {
                lVar20 = 1;
                _eh_vector_destructor_iterator_(&pcStack_68,0x18,1,RE::GFxValue::~GFxValue);
              }
              else {
                lVar20 = 1;
                _eh_vector_destructor_iterator_(&pcStack_68,0x18,1,RE::GFxValue::~GFxValue);
              }
              RE::GFxValue::~GFxValue(&DStack_b8);
              puVar9 = (undefined4 *)FUN_18003d3a0((undefined8 *)&DAT_1801d9710,(float *)&DStack_78)
              ;
              _DAT_1801d9728 = *puVar9;
              _DAT_1801d972c = puVar9[1];
            }
            atexit((_func_5014 *)&LAB_180162130);
            _Init_thread_footer(&DAT_1801d9708);
          }
          DAT_1801d9528 = (undefined8 *)&DAT_1801d9710;
        }
        RE::GFxValue::~GFxValue(&pcStack_d8);
        puVar15 = DAT_1801d9528;
        FUN_180040080(&ppuStack_70,DAT_1801d9528);
        FUN_18003d3a0(puVar15,&fStack_98);
        puVar6 = FUN_180045b20(puVar15,(ulonglong *)&DStack_78);
        DStack_88.data = (DataDesc *)FUN_1800a3e10(puVar6);
        plVar8 = spdlog::default_logger_raw();
        pcStack_d8 = 
        "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
        ;
        uStack_d0 = 0x8a;
        uStack_cc = uStack_60._4_4_;
        pcStack_c8 = 
        "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
        DStack_b8 = (DataDescUnion)0x1801908c0;
        uStack_b0 = 0x11;
        uStack_60 = CONCAT44(uStack_60._4_4_,0x8a);
        pcStack_68 = 
        "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
        ;
        pcStack_58 = 
        "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
        FUN_180042140(&plVar8->_padding_,(ulonglong *)&pcStack_68,lVar20,(ulonglong *)&DStack_b8,
                      &DStack_88,&fStack_98,auStack_94);
        goto LAB_18003ece1;
      }
    }
    if (uVar10 < 0x10) goto switchD_18003e61c_default;
    uVar11 = _Stack_48._Ptr;
    if ((0xfff < uVar10 + 1) &&
       (uVar11 = (char *)*(_Bxty **)(_Stack_48._Ptr + -8),
       (char *)0x1f < _Stack_48._Ptr + (-8 - (longlong)*(_Bxty **)(_Stack_48._Ptr + -8)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    break;
  case 3:
    if ((*(int *)((longlong)param_1 + 0xc) != 0x18) || (param_1[2] == 0))
    goto switchD_18003e61c_default;
    puVar6 = FUN_180045b20(*(undefined8 *)(param_1[2] + 0x10),(ulonglong *)&DStack_88);
    puVar7 = FUN_1800a3e10(puVar6);
    _Stack_48._Ptr = (char *)0x0;
    _Stack_48._8_8_ = 0;
    lStack_38 = 0;
    uStack_30 = 0;
    do {
      sVar16 = sVar16 + 1;
    } while (puVar7[sVar16] != '\0');
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Construct<1,char_const_*>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&_Stack_48,puVar7,
               sVar16);
    RE::GString::~GString((GString *)&DStack_88.heapType);
    uVar10 = uStack_30;
    uVar14 = _Stack_48._Ptr;
    uVar11 = (char *)&_Stack_48;
    if (0xf < uStack_30) {
      uVar11 = _Stack_48._Ptr;
    }
    if (lStack_38 == 0x3c) {
      uVar19 = 0x3c;
      iVar2 = memcmp("_level0.HUDMovieBaseInstance.CompassShoutMeterHolder.Compass",uVar11,0x3c);
      if (iVar2 == 0) {
        plVar8 = spdlog::default_logger_raw();
        pcStack_d8 = 
        "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
        ;
        uStack_d0 = 0x95;
        uStack_cc = uStack_60._4_4_;
        pcStack_c8 = 
        "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
        DStack_b8 = (DataDescUnion)0x180190920;
        uStack_b0 = 0x19;
        uStack_60 = CONCAT44(uStack_60._4_4_,0x95);
        pcStack_68 = 
        "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
        ;
        pcStack_58 = 
        "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
        spdlog::logger::log_<std::basic_string_view<char,std::char_traits<char>_>_const_&>
                  (&plVar8->_padding_,(ulonglong *)&pcStack_68,uVar19,(ulonglong *)&DStack_b8);
        uVar14 = _Stack_48._Ptr;
        uVar10 = uStack_30;
      }
    }
    if (uVar10 < 0x10) goto switchD_18003e61c_default;
    uVar11 = uVar14;
    if ((0xfff < uVar10 + 1) &&
       (uVar11 = (char *)*(_Bxty **)((longlong)uVar14 + -8),
       (char *)0x1f < uVar14 + (-8 - (longlong)*(_Bxty **)((longlong)uVar14 + -8)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    break;
  case 4:
    if ((*(int *)((longlong)param_1 + 0xc) == 0x18) && (lVar17 = param_1[2], lVar17 != 0)) {
      FUN_180045700(&pcStack_68);
      cVar1 = (**(code **)(**(longlong **)(lVar17 + 8) + 0x88))
                        (*(longlong **)(lVar17 + 8),&pcStack_68,"_level0.Test");
      if (cVar1 != '\0') {
        FUN_180045700(&DStack_b8);
        RE::GFxValue::operator=(&DStack_b8,&pcStack_68);
        if (DAT_1801d9558 == (undefined *)0x0) {
          if ((*(int *)(*(longlong *)
                         ((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 0x14) <
               DAT_1801d9738) && (_Init_thread_header(&DAT_1801d9738), DAT_1801d9738 == -1)) {
            RE::GFxValue::GFxValue(&DAT_1801d9740,&DStack_b8);
            DStack_88.data = (DataDesc *)&DAT_1801d9758;
            FUN_180045700(&pcStack_d8);
            fStack_98 = 2.8026e-45;
            FUN_180045f80((undefined8 *)&DAT_1801d9740,"TextField0",&pcStack_d8);
            puVar12 = &DAT_1801d9758;
            FUN_180045700((undefined8 *)&DAT_1801d9758);
            RE::GFxValue::operator=(puVar12,&pcStack_d8);
            RE::GFxValue::~GFxValue(&pcStack_d8);
            DStack_88.data = (DataDesc *)&DAT_1801d9770;
            FUN_180045700(&pcStack_d8);
            fStack_98 = 5.60519e-45;
            FUN_180045f80((undefined8 *)&DAT_1801d9740,"TextField1",&pcStack_d8);
            puVar12 = &DAT_1801d9770;
            FUN_180045700((undefined8 *)&DAT_1801d9770);
            RE::GFxValue::operator=(puVar12,&pcStack_d8);
            RE::GFxValue::~GFxValue(&pcStack_d8);
            DStack_88.data = (DataDesc *)&DAT_1801d9788;
            FUN_180045700(&pcStack_d8);
            fStack_98 = 1.12104e-44;
            FUN_180045f80((undefined8 *)&DAT_1801d9740,"TextField2",&pcStack_d8);
            puVar12 = &DAT_1801d9788;
            FUN_180045700((undefined8 *)&DAT_1801d9788);
            RE::GFxValue::operator=(puVar12,&pcStack_d8);
            RE::GFxValue::~GFxValue(&pcStack_d8);
            atexit(`Test::InitSingleton'::__l5::_dynamic_atexit_destructor_for__singletonInstance__)
            ;
            _Init_thread_footer(&DAT_1801d9738);
          }
          DAT_1801d9558 = &DAT_1801d9740;
        }
        RE::GFxValue::~GFxValue(&DStack_b8);
      }
      RE::GFxValue::~GFxValue(&pcStack_68);
    }
    plVar8 = spdlog::default_logger_raw();
    uStack_d0 = 0xa2;
    uStack_cc = uStack_60._4_4_;
    DStack_b8 = (DataDescUnion)0x180190940;
    uStack_b0 = 0x1c;
    iVar2 = 2;
    goto LAB_18003f092;
  case 5:
    if ((*(int *)((longlong)param_1 + 0xc) != 0x10) || (param_1[2] == 0))
    goto switchD_18003e61c_default;
    if (DAT_1801d9528 != (undefined8 *)0x0) {
      FUN_180045700(&pcStack_d8);
      fStack_98 = 1.4013e-45;
      __builtin_array_init_helper_eh<RE::GFxValue>(&pcStack_68);
      cVar1 = RE::GFxValue::Invoke(puVar15,"AddToHudElements",&pcStack_d8);
      if (cVar1 == '\0') {
        _eh_vector_destructor_iterator_(&pcStack_68,0x18,1,RE::GFxValue::~GFxValue);
      }
      else {
        _eh_vector_destructor_iterator_(&pcStack_68,0x18,1,RE::GFxValue::~GFxValue);
      }
      RE::GFxValue::~GFxValue(&pcStack_d8);
      plVar8 = spdlog::default_logger_raw();
      pcStack_d8 = 
      "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
      ;
      uStack_d0 = 0xab;
      uStack_cc = uStack_60._4_4_;
      pcStack_c8 = 
      "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
      DStack_b8 = (DataDescUnion)0x180190960;
      uStack_b0 = 0x23;
      uStack_60 = CONCAT44(uStack_60._4_4_,0xab);
      pcStack_68 = 
      "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
      ;
      pcStack_58 = 
      "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
      spdlog::logger::hooks__compat__MapMarkerFramework__Install
                ((logger *)plVar8,&pcStack_68,1,(ulonglong *)&DStack_b8);
    }
    plVar8 = spdlog::default_logger_raw();
    uStack_d0 = 0xae;
    uStack_cc = uStack_60._4_4_;
    DStack_b8 = (DataDescUnion)0x180190988;
    uStack_b0 = 0x22;
    iVar2 = 1;
LAB_18003f092:
    pcStack_c8 = 
    "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
    pcStack_d8 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
    ;
    pDVar21 = &DStack_b8;
    uVar22 = uStack_d0;
    uStack_60._4_4_ = uStack_cc;
LAB_18003f0ab:
    pcStack_68 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
    ;
    uStack_60 = CONCAT44(uStack_60._4_4_,uVar22);
    pcStack_58 = 
    "void __cdecl InfinityUIMessageListener(struct SKSE::MessagingInterface::Message *)";
    spdlog::logger::hooks__compat__MapMarkerFramework__Install
              ((logger *)plVar8,&pcStack_68,iVar2,(ulonglong *)pDVar21);
  default:
    goto switchD_18003e61c_default;
  }
  free(uVar11);
switchD_18003e61c_default:
  __security_check_cookie(uStack_28 ^ (ulonglong)auStackY_118);
  return;
}

