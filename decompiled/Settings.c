/* ============================================================
 * Settings.c  ——  CompassNavigationOverhaul 2.9.9 反编译产物
 * 由 Ghidra 11.3.2 反编译器从 SKSE/Plugins/CompassNavigationOverhaul.dll 导出。
 * 函数名来自 2.2.0-VR 版 PDB 的跨版本符号映射；FUN_xxxxxxxx 表示尚未对上真名。
 * 共 1 个函数。这是「2.9.9 行为的唯一事实来源」，不可直接编译。
 * ============================================================ */

/* ---- 0x1800485e0  settings::OnSettingChanged  (1684 bytes) ---- */

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


