/* ==== 0x18009a2c0  FUN_18009a2c0  (20 bytes) ==== */

undefined4 FUN_18009a2c0(longlong param_1)

{
  if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x68) & 0x800) != 0) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 4);
}


/* ==== 0x1800485e0  settings__OnSettingChanged  (1684 bytes) ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void settings__OnSettingChanged(longlong param_1)

{
  int iVar1;
  undefined1 *puVar2;
  longlong lVar3;
  longlong lVar4;
  
  puVar2 = FUN_1800a4310(param_1);
  lVar3 = -1;
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0xf) {
    iVar1 = memcmp(puVar2,"uLogLevel:Debug",0xf);
    if (iVar1 == 0) {
      DAT_1801cf5f0 = FUN_1800a4400(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x17) {
    iVar1 = memcmp(puVar2,"bUseMetricUnits:Display",0x17);
    if (iVar1 == 0) {
      DAT_1801d9560 = FUN_1800a42d0(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x24) {
    iVar1 = memcmp(puVar2,"uUndiscoveredLocationMarkers:Display",0x24);
    if (iVar1 == 0) {
      DAT_1801cf5d4 = FUN_1800a4400(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x25) {
    iVar1 = memcmp(puVar2,"bShowUndiscoveredLocationInfo:Display",0x25);
    if (iVar1 == 0) {
      DAT_1801d9520 = FUN_1800a42d0(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x19) {
    iVar1 = memcmp(puVar2,"bShowEnemyMarkers:Display",0x19);
    if (iVar1 == 0) {
      DAT_1801cf5e1 = FUN_1800a42d0(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x21) {
    iVar1 = memcmp(puVar2,"bShowEnemyNameUnderMarker:Display",0x21);
    if (iVar1 == 0) {
      DAT_1801cf5d2 = FUN_1800a42d0(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x1e) {
    iVar1 = memcmp(puVar2,"bShowObjectiveAsTarget:Display",0x1e);
    if (iVar1 == 0) {
      DAT_1801cf5d1 = FUN_1800a42d0(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x21) {
    iVar1 = memcmp(puVar2,"bShowOtherObjectivesCount:Display",0x21);
    if (iVar1 == 0) {
      DAT_1801cf5d0 = FUN_1800a42d0(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x1c) {
    iVar1 = memcmp(puVar2,"bShowInteriorMarkers:Display",0x1c);
    if (iVar1 == 0) {
      DAT_1801cf5e0 = FUN_1800a42d0(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x21) {
    iVar1 = memcmp(puVar2,"fAngleToShowMarkerDetails:Display",0x21);
    if (iVar1 == 0) {
      DAT_1801cf5dc = FUN_1800a4300(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x26) {
    iVar1 = memcmp(puVar2,"fAngleToKeepMarkerDetailsShown:Display",0x26);
    if (iVar1 == 0) {
      DAT_1801cf5d8 = FUN_1800a4300(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x1c) {
    iVar1 = memcmp(puVar2,"fFocusingDelayToShow:Display",0x1c);
    if (iVar1 == 0) {
      _DAT_1801cf5cc = FUN_1800a4300(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x14) {
    iVar1 = memcmp(puVar2,"fPositionX:QuestList",0x14);
    if (iVar1 == 0) {
      DAT_1801cf5ec = FUN_1800a4300(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x14) {
    iVar1 = memcmp(puVar2,"fPositionY:QuestList",0x14);
    if (iVar1 == 0) {
      DAT_1801cf5e8 = FUN_1800a4300(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x14) {
    iVar1 = memcmp(puVar2,"fMaxHeight:QuestList",0x14);
    if (iVar1 == 0) {
      DAT_1801cf5e4 = FUN_1800a4300(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x1a) {
    iVar1 = memcmp(puVar2,"bShowInExteriors:QuestList",0x1a);
    if (iVar1 == 0) {
      DAT_1801cf5c9 = FUN_1800a42d0(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x1a) {
    iVar1 = memcmp(puVar2,"bShowInInteriors:QuestList",0x1a);
    if (iVar1 == 0) {
      DAT_1801cf5c8 = FUN_1800a42d0(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x1d) {
    iVar1 = memcmp(puVar2,"fWalkingDelayToShow:QuestList",0x1d);
    if (iVar1 == 0) {
      DAT_1801d951c = FUN_1800a4300(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x1d) {
    iVar1 = memcmp(puVar2,"fJoggingDelayToShow:QuestList",0x1d);
    if (iVar1 == 0) {
      DAT_1801cf5c4 = FUN_1800a4300(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (puVar2[lVar4] != '\0');
  if (lVar4 == 0x1f) {
    iVar1 = memcmp(puVar2,"fSprintingDelayToShow:QuestList",0x1f);
    if (iVar1 == 0) {
      DAT_1801cf5c0 = FUN_1800a4300(param_1);
      return;
    }
  }
  puVar2 = FUN_1800a4310(param_1);
  do {
    lVar3 = lVar3 + 1;
  } while (puVar2[lVar3] != '\0');
  if (lVar3 == 0x17) {
    iVar1 = memcmp(puVar2,"bHideInCombat:QuestList",0x17);
    if (iVar1 == 0) {
      DAT_1801d9519 = FUN_1800a42d0(param_1);
    }
  }
  return;
}


/* ==== 0x18003f420  MCMPlusPlusMessageListener  (1011 bytes) ==== */

void MCMPlusPlusMessageListener(undefined8 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  logger *plVar4;
  undefined1 *puVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 uStackX_8;
  char *pcStack_58;
  undefined8 uStack_50;
  char *pcStack_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char *pcStack_38;
  char *pcStack_28;
  undefined8 uStack_20;
  char *pcStack_18;
  
  if (param_1 == (undefined8 *)0x0) {
    return;
  }
  lVar8 = -1;
  lVar9 = -1;
  iVar3 = 0;
  do {
    lVar9 = lVar9 + 1;
  } while (*(char *)((longlong)*param_1 + lVar9) != '\0');
  if (lVar9 != 0xb) {
    return;
  }
  iVar2 = memcmp((void *)*param_1,"MCMPlusPlus",0xb);
  if (iVar2 != 0) {
    return;
  }
  plVar6 = (longlong *)param_1[2];
  if (plVar6 == (longlong *)0x0) {
    return;
  }
  iVar2 = *(int *)(param_1 + 1);
  uVar1 = uStackX_8._4_4_;
  if (iVar2 == 0) {
    if (*(int *)((longlong)param_1 + 0xc) != 8) goto LAB_18003f707;
    lVar8 = *plVar6;
    uStackX_8 = (undefined1 *)((ulonglong)uStackX_8._4_4_ << 0x20);
    plVar6 = (longlong *)(lVar8 + 0x118);
    if (((*(longlong *)(lVar8 + 0x120) != 0) || (*plVar6 != 0)) && (plVar6 != (longlong *)0x0)) {
      do {
        plVar6 = (longlong *)plVar6[1];
        iVar3 = iVar3 + 1;
      } while (plVar6 != (longlong *)0x0);
      uStackX_8 = (undefined1 *)CONCAT44(uVar1,iVar3);
    }
    plVar4 = spdlog::default_logger_raw();
    uStack_40 = 0xd1;
    uStack_3c = uStack_20._4_4_;
    pcStack_58 = "Default settings initialized ({})";
    uStack_50 = 0x21;
LAB_18003f785:
    pcStack_38 = 
    "void __cdecl MCMPlusPlusMessageListener(struct SKSE::MessagingInterface::Message *)";
    pcStack_48 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
    ;
    uStack_20 = CONCAT44(uStack_3c,uStack_40);
    pcStack_28 = 
    "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
    ;
    pcStack_18 = 
    "void __cdecl MCMPlusPlusMessageListener(struct SKSE::MessagingInterface::Message *)";
    FUN_180041cd0(&plVar4->_padding_,(ulonglong *)&pcStack_28,lVar9,(ulonglong *)&pcStack_58,
                  (undefined4 *)&uStackX_8);
    FUN_180048c80(lVar8);
  }
  else {
    if (iVar2 != 1) {
      if (iVar2 != 2) {
        return;
      }
      if (*(int *)((longlong)param_1 + 0xc) != 8) {
        return;
      }
      lVar9 = *plVar6;
      uStackX_8 = FUN_1800a4310(lVar9);
      plVar4 = spdlog::default_logger_raw();
      uStack_40 = 0xf9;
      pcStack_48 = 
      "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
      ;
      uStack_3c = uStack_20._4_4_;
      uStack_20 = CONCAT44(uStack_20._4_4_,0xf9);
      uStack_50 = 0x13;
      pcStack_38 = 
      "void __cdecl MCMPlusPlusMessageListener(struct SKSE::MessagingInterface::Message *)";
      pcStack_58 = "Setting changed: {}";
      pcStack_28 = 
      "C:\\Users\\Alejandro\\Desarrollo\\C++\\Visual Studio\\SSE\\MyPlugins\\CompassNavigationOverhaul\\source\\MessageListeners.cpp"
      ;
      pcStack_18 = 
      "void __cdecl MCMPlusPlusMessageListener(struct SKSE::MessagingInterface::Message *)";
      FUN_180041aa0(&plVar4->_padding_,(ulonglong *)&pcStack_28,1,(ulonglong *)&pcStack_58,
                    &uStackX_8);
      settings__OnSettingChanged(lVar9);
      puVar5 = FUN_1800a4310(lVar9);
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while (puVar5[lVar10] != '\0');
      if ((lVar10 == 0xf) && (iVar3 = memcmp(puVar5,"uLogLevel:Debug",0xf), iVar3 == 0)) {
        SKSE::log::set_level(DAT_1801cf5f0,DAT_1801cf5f0);
        return;
      }
      puVar5 = FUN_1800a4310(lVar9);
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while (puVar5[lVar10] != '\0');
      if ((lVar10 == 0x17) && (iVar3 = memcmp(puVar5,"bUseMetricUnits:Display",0x17), iVar3 == 0)) {
        if (DAT_1801d9530 == (undefined8 *)0x0) {
          return;
        }
        CNO::Compass::CNO__Compass__CNO__Compass__SetUnits(DAT_1801d9530);
        return;
      }
      puVar5 = FUN_1800a4310(lVar9);
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while (puVar5[lVar10] != '\0');
      if ((lVar10 == 0x14) && (iVar3 = memcmp(puVar5,"fPositionX:QuestList",0x14), iVar3 == 0)) {
LAB_18003f633:
        if (DAT_1801d9528 == (undefined8 *)0x0) {
          return;
        }
        FUN_18003da80(DAT_1801d9528);
        return;
      }
      puVar5 = FUN_1800a4310(lVar9);
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while (puVar5[lVar10] != '\0');
      if ((lVar10 == 0x14) && (iVar3 = memcmp(puVar5,"fPositionY:QuestList",0x14), iVar3 == 0))
      goto LAB_18003f633;
      puVar5 = FUN_1800a4310(lVar9);
      do {
        lVar8 = lVar8 + 1;
      } while (puVar5[lVar8] != '\0');
      if (lVar8 != 0x14) {
        return;
      }
      iVar3 = memcmp(puVar5,"fMaxHeight:QuestList",0x14);
      if (iVar3 != 0) {
        return;
      }
      puVar7 = DAT_1801d9528;
      if (DAT_1801d9528 == (undefined8 *)0x0) {
        return;
      }
      goto LAB_18003f7f1;
    }
LAB_18003f707:
    if ((iVar2 == 1) && (*(int *)((longlong)param_1 + 0xc) == 8)) {
      lVar8 = *plVar6;
      uStackX_8 = (undefined1 *)((ulonglong)uStackX_8._4_4_ << 0x20);
      plVar6 = (longlong *)(lVar8 + 0x118);
      if (((*(longlong *)(lVar8 + 0x120) != 0) || (*plVar6 != 0)) && (plVar6 != (longlong *)0x0)) {
        do {
          plVar6 = (longlong *)plVar6[1];
          iVar3 = iVar3 + 1;
        } while (plVar6 != (longlong *)0x0);
        uStackX_8 = (undefined1 *)CONCAT44(uVar1,iVar3);
      }
      plVar4 = spdlog::default_logger_raw();
      uStack_40 = 0xdf;
      uStack_3c = uStack_20._4_4_;
      pcStack_58 = "Settings initialized ({})";
      uStack_50 = 0x19;
      goto LAB_18003f785;
    }
  }
  SKSE::log::set_level(DAT_1801cf5f0,DAT_1801cf5f0);
  if (DAT_1801d9530 != (undefined8 *)0x0) {
    CNO::Compass::CNO__Compass__CNO__Compass__SetUnits(DAT_1801d9530);
  }
  puVar7 = DAT_1801d9528;
  if (DAT_1801d9528 == (undefined8 *)0x0) {
    return;
  }
  FUN_18003da80(DAT_1801d9528);
LAB_18003f7f1:
  IUI::GFxObject::IUI__GFxObject__IUI__GFxObject__Invoke_float___float___float___(puVar7);
  return;
}


