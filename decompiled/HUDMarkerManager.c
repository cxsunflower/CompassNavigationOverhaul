/* ============================================================
 * HUDMarkerManager.c  ——  CompassNavigationOverhaul 2.9.9 反编译产物
 * 由 Ghidra 11.3.2 反编译器从 SKSE/Plugins/CompassNavigationOverhaul.dll 导出。
 * 函数名来自 2.2.0-VR 版 PDB 的跨版本符号映射；FUN_xxxxxxxx 表示尚未对上真名。
 * 共 12 个函数。这是「2.9.9 行为的唯一事实来源」，不可直接编译。
 * ============================================================ */

/* ---- 0x180002ac0  CNO::HUDMarkerManager::ProcessQuestMarker  (2120 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void CNO__HUDMarkerManager__ProcessQuestMarker
               (longlong param_1,longlong param_2,longlong *param_3,undefined4 param_4,
               longlong *param_5,int param_6)

{
  vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_> *this;
  int iVar1;
  byte bVar2;
  undefined1 (*pauVar3) [32];
  code *pcVar4;
  ulong64 uVar5;
  Actor *pAVar6;
  char *pcVar7;
  BSPointerHandle<RE::TESObjectREFR,RE::BSUntypedPointerHandle<21,5>_> *this_00;
  undefined1 *puVar8;
  TESWorldSpace *this_01;
  Marker *pMVar9;
  longlong lVar10;
  int *piVar11;
  ulonglong uVar12;
  longlong *plVar13;
  void *pvVar14;
  undefined1 (*pauVar15) [32];
  ulonglong uVar16;
  __uint64 _Var17;
  Marker *pMVar18;
  Marker *pMVar19;
  undefined8 _Memory;
  char *******_Memory_00;
  Marker *pMVar20;
  uint uVar21;
  size_t sVar22;
  uint uVar23;
  size_t sVar24;
  Marker *pMVar25;
  TESForm *pTVar26;
  float fVar27;
  undefined1 auStackY_1b8 [32];
  TESForm *local_188 [2];
  BSStringT<char,4294967295,RE::DynamicMemoryManagementPol> local_178;
  undefined4 local_168;
  longlong local_160;
  ulonglong local_158;
  pmf_0c849555 local_150 [2];
  longlong *local_140;
  longlong *local_138 [2];
  BSStringT<char,4294967295,RE::DynamicMemoryManagementPol> local_128;
  undefined8 local_118;
  ulonglong uStack_110;
  char ******local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  ulonglong local_f0;
  _Bxty local_e8;
  ulonglong local_d8;
  Marker *pMStack_d0;
  Marker *local_c8;
  TESForm *local_b8;
  uint local_b0;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_a8;
  undefined1 local_88;
  void *local_80;
  undefined8 local_78;
  longlong lStack_70;
  undefined4 local_68;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_188[0] = (TESForm *)param_5;
  local_158 = local_158 & 0xffffffff00000000;
  local_168 = param_4;
  local_160 = param_2;
  local_140 = param_3;
  local_138[0] = param_3;
  uVar12 = CNO__HUDMarkerManager__GetAngleBetween
                     (param_1,*(longlong *)(param_1 + 0xd8),(longlong)param_5);
  uVar23 = (uint)param_5;
  fVar27 = (float)uVar12;
  if ((((*(longlong **)(param_1 + 0x40) == (longlong *)0x0) ||
       (local_188[0] != (TESForm *)**(longlong **)(param_1 + 0x40))) ||
      (*(float *)(param_1 + 0x14) <= fVar27)) && (*(float *)(param_1 + 0x10) <= fVar27))
  goto LAB_1800032d1;
  uStack_100 = 0;
  local_f8._0_2_ = 0;
  local_f8._2_2_ = 0;
  local_f8._4_4_ = 0;
  local_f0 = 0xf;
  local_108 = (char ******)0x0;
  sVar22 = 0xffffffffffffffff;
  if (DAT_1801cf5d1 == '\0') {
    pTVar26 = local_188[0];
    if (local_188[0][0x1a] == (TESForm)0x3d) {
      lVar10 = RE::TESForm::As<RE::TESObjectREFR,void>(local_188[0]);
      if (lVar10 != 0) {
        this_00 = (BSPointerHandle<RE::TESObjectREFR,RE::BSUntypedPointerHandle<21,5>_> *)
                  FUN_180083170(lVar10 + 0x70,(undefined4 *)local_150);
        local_128._data = (char *)0x0;
        local_158 = CONCAT44(local_158._4_4_,2);
        RE::BSPointerHandle<RE::TESObjectREFR,RE::BSUntypedPointerHandle<21,5>_>::get_smartptr
                  (this_00,(NiPointer<RE::TESObjectREFR> *)&local_128);
        local_150[0] = (pmf_0c849555)((ulonglong)(uint)local_150[0]._4_4_ << 0x20);
        if ((Marker *)local_128._data != (Marker *)0x0) {
          pTVar26 = (TESForm *)
                    (((Marker *)((longlong)local_128._data + 0x40))->description)._Mypair._Myval2.
                    _Bx._Ptr;
          if (pTVar26 == (TESForm *)0x0) {
            this_01 = RE::TESObjectREFR::GetWorldspace(local_128._data);
            if (this_01 == (TESWorldSpace *)0x0) goto LAB_180002d1a;
            puVar8 = RE::TESForm::GetName((TESForm *)this_01);
            sVar24 = 0xffffffffffffffff;
            do {
              sVar24 = sVar24 + 1;
            } while (puVar8[sVar24] != '\0');
          }
          else {
            puVar8 = RE::TESForm::GetName(pTVar26);
            sVar24 = 0xffffffffffffffff;
            do {
              sVar24 = sVar24 + 1;
            } while (puVar8[sVar24] != '\0');
          }
          FUN_18001bf20((longlong *)&local_108,puVar8,sVar24);
          uVar23 = (uint)sVar24;
        }
LAB_180002d1a:
        pTVar26 = local_188[0];
        if ((Marker *)local_128._data != (Marker *)0x0) {
          RE::BSHandleRefObject::DecRefCount
                    ((BSHandleRefObject *)((longlong)local_128._data + 0x20));
          pTVar26 = local_188[0];
        }
      }
    }
    else if ((local_188[0][0x1a] == (TESForm)0x3e) &&
            (pAVar6 = (Actor *)RE::TESForm::As<RE::Actor,void>(local_188[0]), pAVar6 != (Actor *)0x0
            )) {
      pcVar7 = NND::NPCNameProvider::NND__NPCNameProvider__GetName
                         ((NPCNameProvider *)&DAT_1801d94c8,pAVar6);
      sVar24 = 0xffffffffffffffff;
      do {
        sVar24 = sVar24 + 1;
      } while (pcVar7[sVar24] != '\0');
      FUN_18001bf20((longlong *)&local_108,pcVar7,sVar24);
      uVar23 = (uint)sVar24;
      pTVar26 = local_188[0];
    }
  }
  else {
    local_128._data = (char *)0x5abd;
    local_128._size = 0x5c84;
    local_128._capacity = 0;
    local_128._pad0C = 0;
    uVar5 = FUN_18000f860((ulonglong *)&local_128);
    local_178._data = (char *)0x0;
    local_178._size = 0;
    local_178._capacity = 0;
    local_178._pad0C = 0;
    RE::BSStringT<char,4294967295,RE::DynamicMemoryManagementPol>::set_cstr(&local_178,"",uVar23);
    local_158 = CONCAT44(local_158._4_4_,1);
    local_128._data = (char *)param_3;
    local_150[0] = SKSE::stl::
                   unrestricted_cast<void_(__cdecl_RE::BGSInstancedQuestObjective::*)(RE::BSStringT<char,4294967295,RE::DynamicMemoryManagementPol>_&)const_,unsigned___int64>
                             (uVar5);
    REL::
    invoke<void_(__cdecl_RE::BGSInstancedQuestObjective::*)(RE::BSStringT<char,4294967295,RE::DynamicMemoryManagementPol>_&)const_,RE::BGSInstancedQuestObjective_const_*,RE::BSStringT<char,4294967295,RE::DynamicMemoryManagementPol>_&>
              (local_150,&local_128._data,&local_178);
    pcVar7 = "";
    if (local_178._data != (char *)0x0) {
      pcVar7 = local_178._data;
    }
    sVar24 = 0xffffffffffffffff;
    do {
      sVar24 = sVar24 + 1;
    } while (pcVar7[sVar24] != '\0');
    FUN_18001bf20((longlong *)&local_108,pcVar7,sVar24);
    uVar23 = (uint)sVar24;
    RE::free(local_178._data);
    pTVar26 = local_188[0];
  }
  this = (vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_> *)(param_1 + 0x20);
  uVar21 = *(int *)(*(longlong *)(param_1 + 200) + 0x14bc) - 1;
  local_150[0]._0_4_ = uVar21;
  pMVar19 = *(Marker **)(param_1 + 0x28);
  if (pMVar19 == *(Marker **)(param_1 + 0x30)) {
    lVar10 = (longlong)pMVar19 - *(longlong *)this >> 6;
    uVar12 = 0x3ffffffffffffff;
    if (lVar10 == 0x3ffffffffffffff) {
LAB_180003306:
      FUN_18000b170();
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    local_158 = lVar10 + 1;
    uVar16 = (longlong)*(Marker **)(param_1 + 0x30) - *(longlong *)this >> 6;
    if (0x3ffffffffffffff - (uVar16 >> 1) < uVar16) {
      pMVar9 = (Marker *)
               std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>
                         (0xffffffffffffffc0);
      pTVar26 = local_188[0];
    }
    else {
      uVar16 = (uVar16 >> 1) + uVar16;
      uVar12 = local_158;
      if (local_158 <= uVar16) {
        uVar12 = uVar16;
      }
      if (0x3ffffffffffffff < uVar12) {
        FUN_180039810();
        goto LAB_180003306;
      }
      _Var17 = uVar12 << 6;
      if (_Var17 == 0) {
        pMVar9 = (Marker *)0x0;
      }
      else if (_Var17 < 0x1000) {
        pMVar9 = (Marker *)operator_new(_Var17);
        pTVar26 = local_188[0];
      }
      else {
        pMVar9 = (Marker *)
                 std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>(_Var17);
        pTVar26 = local_188[0];
      }
    }
    local_128._data = (char *)(pMVar9 + lVar10 + 1);
    local_178._data = (char *)&local_108;
    if (0xf < local_f0) {
      local_178._data = (char *)local_108;
    }
    local_178._size = (ushort)local_f8;
    local_178._capacity = local_f8._2_2_;
    local_178._pad0C = local_f8._4_4_;
    local_e8._Ptr = (char *)this;
    local_e8._8_8_ = pMVar9;
    local_d8 = uVar12;
    pMStack_d0 = (Marker *)local_128._data;
    local_c8 = (Marker *)local_128._data;
    CNO::Compass::Marker::CNO__Compass__Marker__Marker
              (pMVar9 + lVar10,(longlong *)pTVar26,fVar27,local_150[0]._0_4_,param_6,
               &local_178._data);
    pMVar20 = *(Marker **)(param_1 + 0x28);
    pMVar18 = *(Marker **)this;
    pMVar25 = pMVar9;
    if (pMVar19 != pMVar20) {
      std::_Uninitialized_move<CNO::Compass::Marker_*,std::allocator<CNO::Compass::Marker>_>
                ((undefined4 *)*(Marker **)this,(undefined4 *)pMVar19,&pMVar9->ref);
      pMVar20 = *(Marker **)(param_1 + 0x28);
      pMVar18 = pMVar19;
      pMVar25 = (Marker *)local_128._data;
    }
    std::_Uninitialized_move<CNO::Compass::Marker_*,std::allocator<CNO::Compass::Marker>_>
              ((undefined4 *)pMVar18,(undefined4 *)pMVar20,&pMVar25->ref);
    uVar16 = local_158;
    std::vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_>::_Change_array
              (this,(longlong)pMVar9,local_158,uVar12);
    uVar23 = (uint)uVar16;
  }
  else {
    local_178._data = (char *)&local_108;
    if (0xf < local_f0) {
      local_178._data = (char *)local_108;
    }
    local_178._size = (ushort)local_f8;
    local_178._capacity = local_f8._2_2_;
    local_178._pad0C = local_f8._4_4_;
    CNO::Compass::Marker::CNO__Compass__Marker__Marker
              (pMVar19,(longlong *)pTVar26,fVar27,uVar21,param_6,&local_178._data);
    *(longlong *)(param_1 + 0x28) = *(longlong *)(param_1 + 0x28) + 0x40;
  }
  bVar2 = *(byte *)(local_160 + 0xdf);
  local_178._data = (char *)0x7eda3;
  local_178._size = 0x3266;
  local_178._capacity = 6;
  local_178._pad0C = 0;
  lVar10 = FUN_18000f860((ulonglong *)&local_178);
  piVar11 = (int *)FUN_180007680(lVar10);
  iVar1 = *piVar11;
  if (bVar2 == 6) {
    uVar12 = FUN_18000b9c0(local_188);
    uVar12 = uVar12 & *(ulonglong *)(param_1 + 0xb8);
    lVar10 = *(longlong *)(*(longlong *)(param_1 + 0xa0) + 8 + uVar12 * 0x10);
    if (lVar10 == *(longlong *)(param_1 + 0x90)) {
LAB_180002f6b:
      local_118 = 0xe;
      uStack_110 = 0xf;
      local_128._data = (char *)0x4c4c454353494d24;
      local_128._size = 0x4e41;
      local_128._capacity = 0x4f45;
      local_128._pad0C = 0x5355;
      local_b8 = local_188[0];
      local_b0 = (uint)bVar2;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(&local_a8,&local_128._data);
      local_80 = (void *)0x0;
      local_78 = 0;
      lStack_70 = 0;
      local_68 = local_168;
      local_88 = param_6 == iVar1;
      plVar13 = FUN_180006c70((float *)(param_1 + 0x88),&local_178._data,(longlong *)local_188);
      QuestItem::operator=((QuestItem *)(*plVar13 + 0x18),&local_b8);
      if (local_80 != (void *)0x0) {
        pvVar14 = local_80;
        if ((0xfff < (lStack_70 - (longlong)local_80 & 0xfffffffffffffff8U)) &&
           (pvVar14 = *(void **)((longlong)local_80 + -8),
           0x1f < (ulonglong)((longlong)local_80 + (-8 - (longlong)pvVar14)))) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        free(pvVar14);
        local_80 = (void *)0x0;
        local_78 = 0;
        lStack_70 = 0;
      }
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
                (&local_a8);
      if (0xf < uStack_110) {
        pMVar19 = (Marker *)local_128._data;
        if ((0xfff < uStack_110 + 1) &&
           (pMVar19 = (Marker *)
                      (((Marker *)((longlong)local_128._data + -0x40))->description)._Mypair._Myval2
                      ._Myres,
           0x1f < (ulonglong)((longlong)local_128._data + (-8 - (longlong)pMVar19)))) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        free(pMVar19);
      }
    }
    else {
      pTVar26 = *(TESForm **)(lVar10 + 0x10);
      while (local_188[0] != pTVar26) {
        if (lVar10 == *(longlong *)(*(longlong *)(param_1 + 0xa0) + uVar12 * 0x10))
        goto LAB_180002f6b;
        lVar10 = *(longlong *)(lVar10 + 8);
        pTVar26 = *(TESForm **)(lVar10 + 0x10);
      }
    }
    plVar13 = FUN_180006c70((float *)(param_1 + 0x88),&local_178._data,(longlong *)local_188);
    lVar10 = *plVar13;
  }
  else {
    pvVar14 = (void *)(**(code **)(*(longlong *)(local_160 + 0x28) + 0x28))();
    local_128._data = (char *)0x0;
    local_128._size = 0;
    local_128._capacity = 0;
    local_128._pad0C = 0;
    RE::BSStringT<char,4294967295,RE::DynamicMemoryManagementPol>::set_cstr
              (&local_128,pvVar14,uVar23);
    FUN_1800480b0(&local_128,local_160,*(undefined4 *)(local_160 + 0x50));
    pcVar7 = "";
    if (local_128._data != (char *)0x0) {
      pcVar7 = local_128._data;
    }
    local_e8._Ptr = (char *)0x0;
    local_e8._8_8_ = (Marker *)0x0;
    local_d8 = 0;
    pMStack_d0 = (Marker *)0x0;
    do {
      sVar22 = sVar22 + 1;
    } while (pcVar7[sVar22] != '\0');
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Construct<1,char_const_*>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&local_e8,pcVar7,
               sVar22);
    local_b8 = local_188[0];
    local_b0 = (uint)bVar2;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(&local_a8,&local_e8._Ptr);
    local_80 = (void *)0x0;
    local_78 = 0;
    lStack_70 = 0;
    local_68 = local_168;
    local_88 = param_6 == iVar1;
    plVar13 = std::
              _Hash<std::_Umap_traits<RE::TESObjectREFR_*,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>,std::_Uhash_compare<RE::TESObjectREFR_*,std::hash<RE::TESObjectREFR_*>,std::equal_to<RE::TESObjectREFR_*>_>,std::allocator<std::pair<RE::TESObjectREFR_*_const,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>_>_>,0>_>
              ::_Try_emplace<RE::TESObjectREFR_*_const_&>
                        ((_Hash<std::_Umap_traits<RE::TESObjectREFR_*,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>,std::_Uhash_compare<RE::TESObjectREFR_*,std::hash<RE::TESObjectREFR_*>,std::equal_to<RE::TESObjectREFR_*>_>,std::allocator<std::pair<RE::TESObjectREFR_*_const,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>_>_>,0>_>
                          *)(param_1 + 0x48),&local_178._data,(longlong *)local_188);
    plVar13 = FUN_1800072f0((float *)(*plVar13 + 0x18),local_150,&local_160);
    QuestItem::operator=((QuestItem *)(*plVar13 + 0x18),&local_b8);
    FUN_180007d20((longlong *)&local_80);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
              (&local_a8);
    if ((Marker *)0xf < pMStack_d0) {
      _Memory = local_e8._Ptr;
      if (((undefined1 *)0xfff < (undefined1 *)((longlong)&pMStack_d0->ref + 1)) &&
         (_Memory = (char *)*(undefined8 *)(local_e8._Ptr + -8),
         (vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_> *)0x1f <
         (vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_> *)
         (local_e8._Ptr + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      free(_Memory);
    }
    plVar13 = std::
              _Hash<std::_Umap_traits<RE::TESObjectREFR_*,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>,std::_Uhash_compare<RE::TESObjectREFR_*,std::hash<RE::TESObjectREFR_*>,std::equal_to<RE::TESObjectREFR_*>_>,std::allocator<std::pair<RE::TESObjectREFR_*_const,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>_>_>,0>_>
              ::_Try_emplace<RE::TESObjectREFR_*_const_&>
                        ((_Hash<std::_Umap_traits<RE::TESObjectREFR_*,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>,std::_Uhash_compare<RE::TESObjectREFR_*,std::hash<RE::TESObjectREFR_*>,std::equal_to<RE::TESObjectREFR_*>_>,std::allocator<std::pair<RE::TESObjectREFR_*_const,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>_>_>,0>_>
                          *)(param_1 + 0x48),&local_178._data,(longlong *)local_188);
    plVar13 = FUN_1800072f0((float *)(*plVar13 + 0x18),local_150,&local_160);
    lVar10 = *plVar13;
    RE::free(local_128._data);
    local_128._data = (char *)0x0;
  }
  plVar13 = local_140;
  pauVar3 = *(undefined1 (**) [32])(lVar10 + 0x50);
  pauVar15 = `anonymous_namespace'::
             __std_find_trivial_impl<_anonymous_namespace_::_Find_traits_8,unsigned___int64>
                       (pauVar3,(undefined1 (*) [32])
                                (*pauVar3 +
                                (*(longlong *)(lVar10 + 0x58) - (longlong)pauVar3 >> 3) * 8),
                        (ulonglong)local_140);
  pauVar3 = *(undefined1 (**) [32])(lVar10 + 0x58);
  if (pauVar15 == pauVar3) {
    if (pauVar3 == *(undefined1 (**) [32])(lVar10 + 0x60)) {
      FUN_180008d30((longlong *)(lVar10 + 0x50),pauVar3,local_138);
    }
    else {
      *(longlong **)*pauVar3 = plVar13;
      *(longlong *)(lVar10 + 0x58) = *(longlong *)(lVar10 + 0x58) + 8;
    }
  }
  if (0xf < local_f0) {
    _Memory_00 = (char *******)local_108;
    if ((0xfff < local_f0 + 1) &&
       (_Memory_00 = (char *******)local_108[-1],
       0x1f < (ulonglong)((longlong)local_108 + (-8 - (longlong)_Memory_00)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(_Memory_00);
  }
LAB_1800032d1:
  __security_check_cookie(local_58 ^ (ulonglong)auStackY_1b8);
  return;
}


/* ---- 0x180003430  CNO::HUDMarkerManager::ProcessLocationMarker  (356 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void __thiscall
CNO::HUDMarkerManager::CNO__HUDMarkerManager__ProcessLocationMarker
          (HUDMarkerManager *this,longlong param_1,longlong *param_2,uint param_3)

{
  Marker *this_00;
  byte bVar1;
  float fVar2;
  ulonglong uVar3;
  uint local_res8 [2];
  float local_res10 [2];
  longlong *local_res18;
  uint local_res20 [2];
  longlong local_48;
  longlong local_40;
  
  local_res18 = param_2;
  local_res20[0] = param_3;
  uVar3 = CNO__HUDMarkerManager__GetAngleBetween(this,*(longlong *)(this + 0xd8),(longlong)param_2);
  fVar2 = (float)uVar3;
  bVar1 = *(byte *)(*(longlong **)(param_1 + 0x10) + 2) & 1;
  local_res10[0] = fVar2;
  if ((bVar1 != 0) || (DAT_1801d9520 != '\0')) {
    if (((*(longlong **)(this + 0x40) != (longlong *)0x0) &&
        ((param_2 == (longlong *)**(longlong **)(this + 0x40) && (fVar2 < *(float *)(this + 0x14))))
        ) || (fVar2 < *(float *)(this + 0x10))) {
      local_48 = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x28))();
      local_40 = -1;
      do {
        local_40 = local_40 + 1;
      } while (*(char *)(local_48 + local_40) != '\0');
      this_00 = *(Marker **)(this + 0x28);
      local_res8[0] = *(int *)(*(longlong *)(this + 200) + 0x14bc) - 1;
      if (this_00 == *(Marker **)(this + 0x30)) {
        FUN_180008320((longlong *)(this + 0x20),(undefined4 *)this_00,&local_res18,local_res10,
                      local_res8,local_res20,&local_48);
      }
      else {
        Compass::Marker::CNO__Compass__Marker__Marker
                  (this_00,param_2,fVar2,local_res8[0],param_3,&local_48);
        *(longlong *)(this + 0x28) = *(longlong *)(this + 0x28) + 0x40;
      }
    }
    if (bVar1 != 0) {
      return;
    }
  }
  if (DAT_1801cf5d4 == 1) {
    RE::GFxValue::SetNumber
              ((void *)((ulonglong)(*(int *)(*(longlong *)(this + 200) + 0x14bc) - 1) * 0x60 +
                       *(longlong *)(this + 200) + 0x30),0.0);
  }
  return;
}


/* ---- 0x1800035a0  CNO::HUDMarkerManager::ProcessEnemyMarker  (720 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void CNO__HUDMarkerManager__ProcessEnemyMarker(longlong param_1,longlong *param_2,uint param_3)

{
  vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_> *this;
  ulonglong uVar1;
  Marker *pMVar2;
  Marker *this_00;
  code *pcVar3;
  char *pcVar4;
  Marker *pMVar5;
  ulonglong uVar6;
  __uint64 _Var7;
  Marker *pMVar8;
  undefined8 _Memory;
  uint uVar9;
  Marker *pMVar10;
  ulonglong uVar11;
  size_t sVar12;
  Marker *pMVar13;
  longlong lVar14;
  float fVar15;
  undefined1 auStackY_e8 [32];
  _Bxty *local_b0;
  undefined8 local_a8;
  vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_> *local_a0;
  Marker *local_98;
  ulonglong local_90;
  Marker *local_88;
  Marker *local_80;
  _Bxty local_78;
  undefined8 local_68;
  ulonglong local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar11 = CNO__HUDMarkerManager__GetAngleBetween
                     (param_1,*(longlong *)(param_1 + 0xd8),(longlong)param_2);
  fVar15 = (float)uVar11;
  if ((((*(longlong **)(param_1 + 0x40) != (longlong *)0x0) &&
       (param_2 == (longlong *)**(longlong **)(param_1 + 0x40))) &&
      (fVar15 < *(float *)(param_1 + 0x14))) || (fVar15 < *(float *)(param_1 + 0x10))) {
    if (DAT_1801cf5d2 == '\0') {
      pcVar4 = "";
    }
    else {
      pcVar4 = NND::NPCNameProvider::NND__NPCNameProvider__GetName
                         ((NPCNameProvider *)&DAT_1801d94c8,(Actor *)param_2);
    }
    local_78._Ptr = (char *)0x0;
    local_78._8_8_ = 0;
    local_68 = 0;
    local_60 = 0;
    sVar12 = 0xffffffffffffffff;
    do {
      sVar12 = sVar12 + 1;
    } while (pcVar4[sVar12] != '\0');
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Construct<1,char_const_*>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&local_78,pcVar4,
               sVar12);
    this = (vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_> *)(param_1 + 0x20);
    uVar9 = *(int *)(*(longlong *)(param_1 + 200) + 0x14bc) - 1;
    this_00 = *(Marker **)(param_1 + 0x28);
    if (this_00 == *(Marker **)(param_1 + 0x30)) {
      lVar14 = (longlong)this_00 - *(longlong *)this >> 6;
      uVar11 = 0x3ffffffffffffff;
      if (lVar14 == 0x3ffffffffffffff) {
LAB_18000386b:
        FUN_18000b170();
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      uVar1 = lVar14 + 1;
      uVar6 = (longlong)*(Marker **)(param_1 + 0x30) - *(longlong *)this >> 6;
      if (0x3ffffffffffffff - (uVar6 >> 1) < uVar6) {
        pMVar5 = (Marker *)
                 std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>
                           (0xffffffffffffffc0);
      }
      else {
        uVar6 = (uVar6 >> 1) + uVar6;
        uVar11 = uVar1;
        if (uVar1 <= uVar6) {
          uVar11 = uVar6;
        }
        if (0x3ffffffffffffff < uVar11) {
          FUN_180039810();
          goto LAB_18000386b;
        }
        _Var7 = uVar11 << 6;
        if (_Var7 == 0) {
          pMVar5 = (Marker *)0x0;
        }
        else if (_Var7 < 0x1000) {
          pMVar5 = (Marker *)operator_new(_Var7);
        }
        else {
          pMVar5 = (Marker *)
                   std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>(_Var7);
        }
      }
      pMVar2 = pMVar5 + lVar14 + 1;
      local_b0 = &local_78;
      if (0xf < local_60) {
        local_b0 = (_Bxty *)local_78._Ptr;
      }
      local_a8 = local_68;
      local_a0 = this;
      local_98 = pMVar5;
      local_90 = uVar11;
      local_88 = pMVar2;
      local_80 = pMVar2;
      CNO::Compass::Marker::CNO__Compass__Marker__Marker
                (pMVar5 + lVar14,param_2,fVar15,uVar9,param_3,&local_b0);
      pMVar10 = *(Marker **)(param_1 + 0x28);
      pMVar8 = *(Marker **)this;
      pMVar13 = pMVar5;
      if (this_00 != pMVar10) {
        std::_Uninitialized_move<CNO::Compass::Marker_*,std::allocator<CNO::Compass::Marker>_>
                  ((undefined4 *)*(Marker **)this,(undefined4 *)this_00,&pMVar5->ref);
        pMVar10 = *(Marker **)(param_1 + 0x28);
        pMVar8 = this_00;
        pMVar13 = pMVar2;
      }
      std::_Uninitialized_move<CNO::Compass::Marker_*,std::allocator<CNO::Compass::Marker>_>
                ((undefined4 *)pMVar8,(undefined4 *)pMVar10,&pMVar13->ref);
      std::vector<CNO::Compass::Marker,std::allocator<CNO::Compass::Marker>_>::_Change_array
                (this,(longlong)pMVar5,uVar1,uVar11);
    }
    else {
      local_b0 = &local_78;
      if (0xf < local_60) {
        local_b0 = (_Bxty *)local_78._Ptr;
      }
      local_a8 = local_68;
      CNO::Compass::Marker::CNO__Compass__Marker__Marker
                (this_00,param_2,fVar15,uVar9,param_3,&local_b0);
      *(longlong *)(param_1 + 0x28) = *(longlong *)(param_1 + 0x28) + 0x40;
    }
    if (0xf < local_60) {
      _Memory = local_78._Ptr;
                    /* WARNING: Load size is inaccurate */
      if ((0xfff < local_60 + 1) &&
         (_Memory = local_78._Ptr[-8], (char *)0x1f < local_78._Ptr + (-8 - (longlong)_Memory))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      free(_Memory);
    }
  }
  __security_check_cookie(local_58 ^ (ulonglong)auStackY_e8);
  return;
}


/* ---- 0x180003880  CNO::HUDMarkerManager::ProcessPlayerSetMarker  (567 bytes) ---- */

/* WARNING: Enum "SpellType": Some values do not have unique names */

void CNO__HUDMarkerManager__ProcessPlayerSetMarker(longlong param_1,longlong *param_2,uint param_3)

{
  Marker *this;
  undefined8 *puVar1;
  PlayerCharacter *pPVar2;
  void *this_00;
  TESWorldSpace *pTVar3;
  TESWorldSpace *pTVar4;
  float *pfVar5;
  undefined8 uVar6;
  float fVar7;
  ulonglong uVar8;
  uint local_res8 [2];
  longlong *local_res10;
  uint local_res18 [2];
  float local_res20 [2];
  undefined8 local_68;
  float local_60 [2];
  undefined8 local_58;
  float local_50;
  float local_48;
  float local_44;
  float local_40;
  undefined1 *local_38;
  undefined8 local_30;
  
  local_res10 = param_2;
  local_res18[0] = param_3;
  uVar8 = CNO__HUDMarkerManager__GetAngleBetween
                    (param_1,*(longlong *)(param_1 + 0xd8),(longlong)param_2);
  local_res20[0] = (float)uVar8;
  if ((((*(longlong **)(param_1 + 0x40) != (longlong *)0x0) &&
       (param_2 == (longlong *)**(longlong **)(param_1 + 0x40))) &&
      (local_res20[0] < *(float *)(param_1 + 0x14))) ||
     (local_res20[0] < *(float *)(param_1 + 0x10))) {
    this = *(Marker **)(param_1 + 0x28);
    local_res8[0] = *(int *)(*(longlong *)(param_1 + 200) + 0x14bc) - 1;
    if (this == *(Marker **)(param_1 + 0x30)) {
      puVar1 = FUN_180008730((longlong *)(param_1 + 0x20),(undefined4 *)this,&local_res10,
                             local_res20,local_res8,local_res18);
    }
    else {
      local_30 = 0;
      local_38 = &s_;
      CNO::Compass::Marker::CNO__Compass__Marker__Marker
                (this,param_2,local_res20[0],local_res8[0],param_3,&local_38);
      puVar1 = *(undefined8 **)(param_1 + 0x28);
      *(undefined8 **)(param_1 + 0x28) = puVar1 + 8;
    }
    pPVar2 = RE::PlayerCharacter::GetSingleton();
    this_00 = (void *)(**(code **)(*(longlong *)pPVar2 + 0x158))(pPVar2);
    pTVar3 = RE::TESObjectREFR::GetWorldspace(this_00);
    pTVar4 = RE::TESObjectREFR::GetWorldspace(param_2);
    if (pTVar3 == pTVar4) {
      pPVar2 = RE::PlayerCharacter::GetSingleton();
      local_50 = *(float *)&pPVar2->field_0x5c;
      local_58 = *(undefined8 *)&pPVar2->field_0x54;
      pTVar3 = RE::TESObjectREFR::GetWorldspace(pPVar2);
      if (pTVar3 != (TESWorldSpace *)0x0) {
        local_48 = (pTVar3->worldMapOffsetData).mapOffsetX;
        local_44 = (pTVar3->worldMapOffsetData).mapOffsetY;
        local_40 = (pTVar3->worldMapOffsetData).mapOffsetZ;
        pfVar5 = RE::NiPoint3::operator*
                           ((NiPoint3 *)&local_48,(float *)&local_38,
                            (pTVar3->worldMapOffsetData).mapScale);
        RE::NiPoint3::operator+=((NiPoint3 *)&local_58,pfVar5);
      }
      local_68 = *(undefined8 *)((longlong)param_2 + 0x54);
      local_60[0] = *(float *)((longlong)param_2 + 0x5c);
      pTVar3 = RE::TESObjectREFR::GetWorldspace(param_2);
      if (pTVar3 != (TESWorldSpace *)0x0) {
        local_48 = (pTVar3->worldMapOffsetData).mapOffsetX;
        local_44 = (pTVar3->worldMapOffsetData).mapOffsetY;
        local_40 = (pTVar3->worldMapOffsetData).mapOffsetZ;
        pfVar5 = RE::NiPoint3::operator*
                           ((NiPoint3 *)&local_48,(float *)&local_38,
                            (pTVar3->worldMapOffsetData).mapScale);
        RE::NiPoint3::operator+=((NiPoint3 *)&local_68,pfVar5);
      }
      uVar6 = FUN_1800878a0();
      FUN_180087640(uVar6,&local_68,local_60);
      fVar7 = RE::NiPoint3::GetDistance((NiPoint3 *)&local_58,(float *)&local_68);
      *(float *)((longlong)puVar1 + 0xc) = fVar7;
      *(float *)(puVar1 + 2) = local_60[0] - local_50;
    }
  }
  return;
}


/* ---- 0x180003ac0  CNO::HUDMarkerManager::SetMarkersExtraInfo  (3180 bytes) ---- */

void CNO__HUDMarkerManager__SetMarkersExtraInfo(undefined8 *param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 ***_Size;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  byte bVar8;
  uint uVar9;
  undefined8 uVar10;
  longlong *plVar11;
  ulonglong uVar12;
  longlong *plVar13;
  undefined8 ****ppppuVar14;
  undefined *puVar15;
  longlong lVar16;
  char *pcVar17;
  undefined8 uVar18;
  int iVar19;
  TESObjectCELL *this;
  undefined8 ****ppppuVar20;
  undefined8 *puVar21;
  undefined8 ***pppuVar22;
  int iVar23;
  float extraout_XMM0_Da;
  float fVar24;
  float fVar25;
  float fVar26;
  undefined1 auStackY_178 [32];
  undefined8 local_140;
  undefined8 ***local_130;
  undefined8 **ppuStack_128;
  undefined8 **local_120;
  undefined8 **ppuStack_118;
  undefined8 ***local_110;
  longlong lStack_108;
  ulonglong local_100;
  ulonglong uStack_f8;
  _Bxty local_f0;
  ulonglong local_d8;
  _Bxty local_d0;
  longlong local_c0;
  ulonglong local_b8;
  undefined1 local_a8 [24];
  undefined1 local_90 [24];
  undefined1 local_78 [24];
  undefined1 local_60 [24];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_178;
  iVar23 = 0;
  local_140 = (longlong *)((ulonglong)local_140 & 0xffffffff00000000);
  bVar6 = CNO::HUDMarkerManager::CNO__HUDMarkerManager__UpdateFocusedMarker
                    ((HUDMarkerManager *)param_1);
  if (bVar6) {
    puVar21 = (undefined8 *)*param_1;
    FUN_180045700(&local_f0._Ptr);
    local_140 = (longlong *)CONCAT44(local_140._4_4_,8);
    __builtin_array_init_helper_eh<RE::GFxValue>(&local_130);
    cVar7 = RE::GFxValue::Invoke(puVar21,"UnfocusMarker",&local_f0);
    if (cVar7 == '\0') {
      _eh_vector_destructor_iterator_(&local_130,0x18,1,RE::GFxValue::~GFxValue);
    }
    else {
      _eh_vector_destructor_iterator_(&local_130,0x18,1,RE::GFxValue::~GFxValue);
    }
    RE::GFxValue::~GFxValue(&local_f0);
    *(undefined4 *)((longlong)param_1 + 0x1c) = 0;
  }
  else if (param_1[8] != 0) {
    *(float *)((longlong)param_1 + 0x1c) =
         *(float *)(param_1[0x1c] + 0x18) + *(float *)((longlong)param_1 + 0x1c);
  }
  plVar13 = param_1 + 8;
  bVar5 = false;
  bVar4 = false;
  local_140 = plVar13;
  if (*plVar13 != 0) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&local_d0,
               (undefined8 *)(*plVar13 + 0x20));
    iVar23 = 0;
    if ((DAT_1801cf5d1 != '\0') && (DAT_1801cf5d0 != '\0')) {
      plVar11 = (longlong *)*plVar13;
      uVar10 = FUN_180005c70((longlong)(param_1 + 9),plVar11);
      iVar19 = 0;
      if ((char)uVar10 != '\0') {
        bVar5 = true;
        bVar4 = true;
        plVar11 = std::
                  _Hash<std::_Umap_traits<RE::TESObjectREFR_*,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>,std::_Uhash_compare<RE::TESObjectREFR_*,std::hash<RE::TESObjectREFR_*>,std::equal_to<RE::TESObjectREFR_*>_>,std::allocator<std::pair<RE::TESObjectREFR_*_const,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>_>_>,0>_>
                  ::_Try_emplace<RE::TESObjectREFR_*_const_&>
                            ((_Hash<std::_Umap_traits<RE::TESObjectREFR_*,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>,std::_Uhash_compare<RE::TESObjectREFR_*,std::hash<RE::TESObjectREFR_*>,std::equal_to<RE::TESObjectREFR_*>_>,std::allocator<std::pair<RE::TESObjectREFR_*_const,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>_>_>,0>_>
                              *)(param_1 + 9),&local_f0._Ptr,plVar11);
        iVar19 = 0;
        for (puVar21 = (undefined8 *)**(undefined8 **)(*plVar11 + 0x20);
            puVar21 != *(undefined8 **)(*plVar11 + 0x20); puVar21 = (undefined8 *)*puVar21) {
          iVar19 = iVar19 + (int)((longlong)(puVar21[0xb] - puVar21[10]) >> 3);
        }
      }
      plVar11 = (longlong *)*plVar13;
      uVar12 = FUN_18000b9c0(plVar11);
      lVar1 = *(longlong *)(param_1[0x14] + 8 + (uVar12 & param_1[0x17]) * 0x10);
      if (lVar1 != param_1[0x12]) {
        lVar16 = *(longlong *)(lVar1 + 0x10);
        while (*plVar11 != lVar16) {
          if (lVar1 == *(longlong *)(param_1[0x14] + (uVar12 & param_1[0x17]) * 0x10))
          goto LAB_180003cdb;
          lVar1 = *(longlong *)(lVar1 + 8);
          lVar16 = *(longlong *)(lVar1 + 0x10);
        }
        bVar5 = true;
        bVar4 = true;
        plVar11 = FUN_180006c70((float *)(param_1 + 0x11),&local_f0._Ptr,plVar11);
        iVar19 = iVar19 + (int)(*(longlong *)(*plVar11 + 0x58) - *(longlong *)(*plVar11 + 0x50) >> 3
                               );
      }
LAB_180003cdb:
      iVar23 = 0;
      if (1 < iVar19) {
        std::_Integral_to_string<char,int>(&local_f0._Ptr,iVar19 - 1);
        plVar13 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::insert
                            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                             &local_f0,0,&DAT_18018abfc,3);
        local_110 = (undefined8 ***)*plVar13;
        lStack_108 = plVar13[1];
        uVar12 = plVar13[2];
        uStack_f8 = plVar13[3];
        *(undefined1 *)plVar13 = 0;
        plVar13[2] = 0;
        plVar13[3] = 0xf;
        if (uStack_f8 == uVar12) {
          local_100 = uVar12;
          ppppuVar14 = (undefined8 ****)
                       FUN_18000ed80(&local_110,1,(ulonglong)bVar6,&DAT_18018abf8,1);
        }
        else {
          local_100 = uVar12 + 1;
          ppppuVar14 = &local_110;
          if (0xf < uStack_f8) {
            ppppuVar14 = (undefined8 ****)local_110;
          }
          *(undefined2 *)((longlong)ppppuVar14 + uVar12) = 0x29;
          ppppuVar14 = &local_110;
        }
        ppppuVar20 = (undefined8 ****)*ppppuVar14;
        ppuStack_128 = ppppuVar14[1];
        _Size = ppppuVar14[2];
        pppuVar22 = ppppuVar14[3];
        *(undefined1 *)ppppuVar14 = 0;
        ppppuVar14[2] = (undefined8 ***)0x0;
        ppppuVar14[3] = (undefined8 ***)0xf;
        lVar1 = local_c0;
        iVar23 = 0x700;
        ppppuVar14 = &local_130;
        if ((undefined8 ***)0xf < pppuVar22) {
          ppppuVar14 = ppppuVar20;
        }
        local_130 = ppppuVar20;
        local_120 = _Size;
        ppuStack_118 = pppuVar22;
        if ((undefined8 ***)(local_b8 - local_c0) < _Size) {
          FUN_18000ed80(&local_d0._Ptr,(ulonglong)_Size,(ulonglong)bVar6,ppppuVar14,(size_t)_Size);
          ppppuVar20 = (undefined8 ****)local_130;
          pppuVar22 = (undefined8 ***)ppuStack_118;
        }
        else {
          uVar18 = (char *)&local_d0;
          if (0xf < local_b8) {
            uVar18 = local_d0._Ptr;
          }
          pcVar17 = uVar18 + local_c0;
          local_c0 = local_c0 + (longlong)_Size;
          memmove(pcVar17,ppppuVar14,(size_t)_Size);
          *(uVar18 + (longlong)_Size + lVar1) = '\0';
        }
        if ((undefined8 ***)0xf < pppuVar22) {
          ppppuVar14 = ppppuVar20;
          if ((0xfff < (longlong)pppuVar22 + 1U) &&
             (ppppuVar14 = (undefined8 ****)ppppuVar20[-1],
             0x1f < (ulonglong)((longlong)ppppuVar20 + (-8 - (longlong)ppppuVar14)))) {
                    /* WARNING: Subroutine does not return */
            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          free(ppppuVar14);
        }
        if (0xf < uStack_f8) {
          ppppuVar14 = (undefined8 ****)local_110;
          if ((0xfff < uStack_f8 + 1) &&
             (ppppuVar14 = (undefined8 ****)local_110[-1],
             0x1f < (ulonglong)((longlong)local_110 + (-8 - (longlong)ppppuVar14)))) {
                    /* WARNING: Subroutine does not return */
            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          free(ppppuVar14);
        }
        local_100 = 0;
        uStack_f8 = 0xf;
        local_110 = (undefined8 ***)((ulonglong)local_110 & 0xffffffffffffff00);
        plVar13 = local_140;
        bVar5 = bVar4;
        if (0xf < local_d8) {
          uVar18 = local_f0._Ptr;
                    /* WARNING: Load size is inaccurate */
          if ((0xfff < local_d8 + 1) &&
             (uVar18 = local_f0._Ptr[-8], (char *)0x1f < local_f0._Ptr + (-8 - (longlong)uVar18))) {
                    /* WARNING: Subroutine does not return */
            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          free(uVar18);
          plVar13 = local_140;
        }
      }
    }
    puVar21 = (undefined8 *)*param_1;
    uVar12 = (ulonglong)*(uint *)(*plVar13 + 0x14);
    fVar26 = *(float *)(*plVar13 + 0x10);
    uVar18 = (char *)&local_d0;
    if (0xf < local_b8) {
      uVar18 = local_d0._Ptr;
    }
    FUN_180045700(&local_130);
    local_140 = (longlong *)(CONCAT44(local_140._4_4_,iVar23) | 4);
    RE::GFxValue::GFxValue(local_a8,uVar18);
    RE::GFxValue::GFxValue(local_90,(double)extraout_XMM0_Da);
    RE::GFxValue::GFxValue(local_78,(double)fVar26);
    RE::GFxValue::GFxValue(local_60,(double)(longlong)uVar12);
    cVar7 = RE::GFxValue::Invoke(puVar21,"SetFocusedMarkerInfo",&local_130);
    if (cVar7 == '\0') {
      _eh_vector_destructor_iterator_(local_a8,0x18,4,RE::GFxValue::~GFxValue);
    }
    else {
      _eh_vector_destructor_iterator_(local_a8,0x18,4,RE::GFxValue::~GFxValue);
    }
    RE::GFxValue::~GFxValue(&local_130);
    if (bVar6) {
      puVar21 = (undefined8 *)*param_1;
      FUN_180045700(&local_f0._Ptr);
      local_140 = (longlong *)(CONCAT44(local_140._4_4_,iVar23) | 0x20);
      __builtin_array_init_helper_eh<RE::GFxValue>(&local_130);
      cVar7 = RE::GFxValue::Invoke(puVar21,"FocusMarker",&local_f0);
      if (cVar7 == '\0') {
        _eh_vector_destructor_iterator_(&local_130,0x18,1,RE::GFxValue::~GFxValue);
      }
      else {
        _eh_vector_destructor_iterator_(&local_130,0x18,1,RE::GFxValue::~GFxValue);
      }
      RE::GFxValue::~GFxValue(&local_f0);
    }
    puVar21 = (undefined8 *)*param_1;
    FUN_180045700(&local_f0._Ptr);
    local_140 = (longlong *)(CONCAT44(local_140._4_4_,iVar23) | 2);
    __builtin_array_init_helper_eh<RE::GFxValue>(&local_130);
    cVar7 = RE::GFxValue::Invoke(puVar21,"UpdateFocusedMarker",&local_f0);
    if (cVar7 == '\0') {
      _eh_vector_destructor_iterator_(&local_130,0x18,1,RE::GFxValue::~GFxValue);
    }
    else {
      _eh_vector_destructor_iterator_(&local_130,0x18,1,RE::GFxValue::~GFxValue);
    }
    RE::GFxValue::~GFxValue(&local_f0);
    if (0xf < local_b8) {
      uVar18 = local_d0._Ptr;
                    /* WARNING: Load size is inaccurate */
      if ((0xfff < local_b8 + 1) &&
         (uVar18 = local_d0._Ptr[-8], (char *)0x1f < local_d0._Ptr + (-8 - (longlong)uVar18))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      free(uVar18);
    }
  }
  uVar12 = 0;
  lVar1 = param_1[0x1a];
  local_f0._Ptr = (char *)0x27500060001;
  puVar15 = REL::Module::get();
  local_140 = (longlong *)*(ulonglong *)(puVar15 + 0x108);
  do {
    if (*(ushort *)((longlong)&local_140 + uVar12) != *(ushort *)((longlong)&local_f0 + uVar12)) {
      cVar7 = '\x01';
      if (*(ushort *)((longlong)&local_140 + uVar12) < *(ushort *)((longlong)&local_f0 + uVar12)) {
        cVar7 = -1;
      }
      goto LAB_1800041fa;
    }
    uVar12 = uVar12 + 2;
  } while (uVar12 < 8);
  cVar7 = '\0';
LAB_1800041fa:
  lVar16 = 0xb8;
  if (cVar7 != -1) {
    lVar16 = 0xc0;
  }
  local_f0._Ptr = (char *)(lVar16 + lVar1);
  uVar9 = *(uint *)((longlong)local_f0._Ptr + 0xc) >> 5 & 7;
  if (((uVar9 == 3) || (uVar9 == 4)) || (uVar9 == 5)) {
    this = *(TESObjectCELL **)(param_1[0x1a] + 0x60);
    if (DAT_1801d9519 == '\0') goto LAB_18000424b;
LAB_180004288:
    bVar4 = false;
LAB_18000428b:
    puVar21 = (undefined8 *)param_1[1];
    FUN_180045700(&local_110);
    local_140 = (longlong *)(CONCAT44(local_140._4_4_,iVar23) | 1);
    __builtin_array_init_helper_eh<RE::GFxValue>(&local_130);
    cVar7 = RE::GFxValue::Invoke(puVar21,"RemoveAllQuests",&local_110);
    if (cVar7 == '\0') {
      _eh_vector_destructor_iterator_(&local_130,0x18,1,RE::GFxValue::~GFxValue);
    }
    else {
      _eh_vector_destructor_iterator_(&local_130,0x18,1,RE::GFxValue::~GFxValue);
    }
    RE::GFxValue::~GFxValue(&local_110);
    if (!bVar4) goto LAB_1800046bc;
  }
  else {
    this = *(TESObjectCELL **)(param_1[0x1a] + 0x60);
LAB_18000424b:
    if ((this == (TESObjectCELL *)0x0) ||
       (((bVar8 = FUN_180064390((longlong)this), bVar8 == 0 || (DAT_1801cf5c8 == '\0')) &&
        ((bVar8 = RE::TESObjectCELL::IsExteriorCell(this), bVar8 == 0 || (DAT_1801cf5c9 == '\0')))))
       ) goto LAB_180004288;
    bVar4 = true;
    if (bVar6) goto LAB_18000428b;
  }
  if (bVar5) {
    if (bVar6) {
      plVar13 = (longlong *)*plVar13;
      uVar10 = FUN_180005c70((longlong)(param_1 + 9),plVar13);
      if ((char)uVar10 != '\0') {
        plVar13 = std::
                  _Hash<std::_Umap_traits<RE::TESObjectREFR_*,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>,std::_Uhash_compare<RE::TESObjectREFR_*,std::hash<RE::TESObjectREFR_*>,std::equal_to<RE::TESObjectREFR_*>_>,std::allocator<std::pair<RE::TESObjectREFR_*_const,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>_>_>,0>_>
                  ::_Try_emplace<RE::TESObjectREFR_*_const_&>
                            ((_Hash<std::_Umap_traits<RE::TESObjectREFR_*,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>,std::_Uhash_compare<RE::TESObjectREFR_*,std::hash<RE::TESObjectREFR_*>,std::equal_to<RE::TESObjectREFR_*>_>,std::allocator<std::pair<RE::TESObjectREFR_*_const,std::unordered_map<RE::TESQuest_*,QuestItem,std::hash<RE::TESQuest_*>,std::equal_to<RE::TESQuest_*>,std::allocator<std::pair<RE::TESQuest_*_const,QuestItem>_>_>_>_>,0>_>
                              *)(param_1 + 9),&local_140,plVar13);
        puVar21 = *(undefined8 **)(*plVar13 + 0x20);
        for (puVar2 = (undefined8 *)*puVar21; puVar2 != puVar21; puVar2 = (undefined8 *)*puVar2) {
          QuestItemList::QuestItemList__AddQuest((QuestItemList *)param_1[1],(longlong)(puVar2 + 3))
          ;
          puVar3 = (undefined8 *)param_1[1];
          pcVar17 = (char *)CNO::HUDMarkerManager::CNO__HUDMarkerManager__GetSideInQuest
                                      ((HUDMarkerManager *)param_1,&local_d0._Ptr,
                                       *(int *)(puVar2 + 4));
          if (0xf < *(ulonglong *)(pcVar17 + 0x18)) {
            pcVar17 = *(char **)pcVar17;
          }
          FUN_180045700(&local_110);
          local_140 = (longlong *)(CONCAT44(local_140._4_4_,iVar23) | 0x10);
          RE::GFxValue::GFxValue(&local_130,pcVar17);
          cVar7 = RE::GFxValue::Invoke(puVar3,"SetQuestSide",&local_110);
          if (cVar7 == '\0') {
            _eh_vector_destructor_iterator_(&local_130,0x18,1,RE::GFxValue::~GFxValue);
          }
          else {
            _eh_vector_destructor_iterator_(&local_130,0x18,1,RE::GFxValue::~GFxValue);
          }
          RE::GFxValue::~GFxValue(&local_110);
          if (0xf < local_b8) {
            uVar18 = local_d0._Ptr;
                    /* WARNING: Load size is inaccurate */
            if ((0xfff < local_b8 + 1) &&
               (uVar18 = local_d0._Ptr[-8], (char *)0x1f < local_d0._Ptr + (-8 - (longlong)uVar18)))
            {
                    /* WARNING: Subroutine does not return */
              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
            }
            free(uVar18);
          }
          (**(code **)(*(longlong *)**(undefined8 **)param_1[1] + 0x128))
                    ((longlong *)**(undefined8 **)param_1[1],0,2);
        }
      }
      plVar13 = (longlong *)param_1[8];
      uVar12 = FUN_18000b9c0(plVar13);
      lVar1 = *(longlong *)(param_1[0x14] + 8 + (uVar12 & param_1[0x17]) * 0x10);
      if (lVar1 != param_1[0x12]) {
        lVar16 = *(longlong *)(lVar1 + 0x10);
        while (*plVar13 != lVar16) {
          if (lVar1 == *(longlong *)(param_1[0x14] + (uVar12 & param_1[0x17]) * 0x10))
          goto LAB_18000451f;
          lVar1 = *(longlong *)(lVar1 + 8);
          lVar16 = *(longlong *)(lVar1 + 0x10);
        }
        plVar13 = FUN_180006c70((float *)(param_1 + 0x11),&local_140,plVar13);
        QuestItemList::QuestItemList__AddQuest((QuestItemList *)param_1[1],*plVar13 + 0x18);
        (**(code **)(*(longlong *)**(undefined8 **)param_1[1] + 0x128))
                  ((longlong *)**(undefined8 **)param_1[1],0,2);
      }
    }
LAB_18000451f:
    *(undefined1 *)(param_1[1] + 0x20) = 0;
    fVar24 = (float)(**(code **)(*(longlong *)local_f0._Ptr + 0x28))();
    fVar25 = (float)(**(code **)(*(longlong *)param_1[0x1a] + 0x770))();
    fVar26 = DAT_1801d951c;
    if ((fVar25 <= fVar24) &&
       (fVar25 = (float)(**(code **)(*(longlong *)param_1[0x1a] + 0x760))(), fVar26 = DAT_1801cf5c0,
       fVar24 < fVar25)) {
      fVar26 = DAT_1801cf5c4;
    }
    if (fVar26 < *(float *)((longlong)param_1 + 0x1c)) {
      puVar21 = (undefined8 *)param_1[1];
      FUN_180045700(&local_130);
      local_140 = (longlong *)(CONCAT44(local_140._4_4_,iVar23) | 0x80);
      __builtin_array_init_helper_eh<RE::GFxValue>(&local_110);
      cVar7 = RE::GFxValue::Invoke(puVar21,"ShowAllQuests",&local_130);
      if (cVar7 == '\0') {
        _eh_vector_destructor_iterator_(&local_110,0x18,1,RE::GFxValue::~GFxValue);
      }
      else {
        _eh_vector_destructor_iterator_(&local_110,0x18,1,RE::GFxValue::~GFxValue);
      }
      RE::GFxValue::~GFxValue(&local_130);
      puVar21 = (undefined8 *)param_1[1];
      FUN_180045700(&local_130);
      local_140 = (longlong *)(CONCAT44(local_140._4_4_,iVar23) | 0x40);
      __builtin_array_init_helper_eh<RE::GFxValue>(&local_110);
      cVar7 = RE::GFxValue::Invoke(puVar21,"Update",&local_130);
      if (cVar7 == '\0') {
        _eh_vector_destructor_iterator_(&local_110,0x18,1,RE::GFxValue::~GFxValue);
      }
      else {
        _eh_vector_destructor_iterator_(&local_110,0x18,1,RE::GFxValue::~GFxValue);
      }
      RE::GFxValue::~GFxValue(&local_130);
    }
  }
LAB_1800046bc:
  lVar1 = param_1[5];
  lVar16 = param_1[4];
  if (lVar16 != lVar1) {
    do {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(lVar16 + 0x20))
      ;
      lVar16 = lVar16 + 0x40;
    } while (lVar16 != lVar1);
    param_1[5] = param_1[4];
  }
  FUN_180005cd0((longlong)(param_1 + 9));
  FUN_180005a20((longlong)(param_1 + 0x11));
  __security_check_cookie(local_48 ^ (ulonglong)auStackY_178);
  return;
}


/* ---- 0x180004740  CNO::HUDMarkerManager::GetMostCenteredMarker  (278 bytes) ---- */

undefined8 *
CNO::HUDMarkerManager::CNO__HUDMarkerManager__GetMostCenteredMarker
          (longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  void *_Memory;
  int iVar2;
  float fVar3;
  undefined8 *puVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  
  iVar7 = 0;
  *param_2 = 0;
  fVar8 = 3.4028235e+38;
  iVar6 = -1;
  lVar1 = *(longlong *)(param_1 + 0x20);
  if (*(longlong *)(param_1 + 0x28) - lVar1 >> 6 != 0) {
    lVar5 = lVar1;
    do {
      iVar2 = iVar7;
      fVar3 = *(float *)(lVar5 + 8);
      if (fVar8 <= *(float *)(lVar5 + 8)) {
        iVar2 = iVar6;
        fVar3 = fVar8;
      }
      fVar8 = fVar3;
      iVar6 = iVar2;
      iVar7 = iVar7 + 1;
      lVar5 = lVar5 + 0x40;
    } while ((ulonglong)(longlong)iVar7 < (ulonglong)(*(longlong *)(param_1 + 0x28) - lVar1 >> 6));
    if (-1 < iVar6) {
      lVar5 = (longlong)iVar6 * 0x40;
      puVar4 = (undefined8 *)operator_new(0x40);
      *puVar4 = *(undefined8 *)(lVar5 + lVar1);
      *(undefined4 *)(puVar4 + 1) = *(undefined4 *)(lVar5 + 8 + lVar1);
      *(undefined4 *)((longlong)puVar4 + 0xc) = *(undefined4 *)(lVar5 + 0xc + lVar1);
      *(undefined4 *)(puVar4 + 2) = *(undefined4 *)(lVar5 + 0x10 + lVar1);
      *(undefined4 *)((longlong)puVar4 + 0x14) = *(undefined4 *)(lVar5 + 0x14 + lVar1);
      *(undefined4 *)(puVar4 + 3) = *(undefined4 *)(lVar5 + 0x18 + lVar1);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(puVar4 + 4),
                 (undefined8 *)(lVar1 + 0x20 + lVar5));
      _Memory = (void *)*param_2;
      *param_2 = puVar4;
      if (_Memory != (void *)0x0) {
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                   ((longlong)_Memory + 0x20));
        free(_Memory);
      }
    }
  }
  return param_2;
}


/* ---- 0x180004860  CNO::HUDMarkerManager::UpdateFocusedMarker  (390 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __thiscall
CNO::HUDMarkerManager::CNO__HUDMarkerManager__UpdateFocusedMarker(HUDMarkerManager *this)

{
  HUDMarkerManager *pHVar1;
  longlong *plVar2;
  longlong *plVar3;
  bool bVar4;
  longlong *local_res8;
  
  CNO__HUDMarkerManager__GetMostCenteredMarker((longlong)this,&local_res8);
  plVar3 = local_res8;
  plVar2 = *(longlong **)(this + 0x38);
  if ((local_res8 == (longlong *)0x0) || (plVar2 == (longlong *)0x0)) {
    if ((local_res8 != (longlong *)0x0) || (plVar2 != (longlong *)0x0)) goto LAB_1800048bb;
  }
  else if (*local_res8 != *plVar2) {
LAB_1800048bb:
    *(undefined4 *)(this + 0x18) = 0;
  }
  if ((plVar2 != (longlong *)0x0) || (local_res8 != (longlong *)0x0)) {
    local_res8 = (longlong *)0x0;
    *(longlong **)(this + 0x38) = plVar3;
    if (plVar2 != (longlong *)0x0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(plVar2 + 4));
      free(plVar2);
    }
  }
  plVar2 = *(longlong **)(this + 0x38);
  pHVar1 = this + 0x40;
  plVar3 = *(longlong **)pHVar1;
  if (plVar2 == (longlong *)0x0) {
    if (plVar3 != (longlong *)0x0) {
      *(longlong *)pHVar1 = 0;
LAB_1800049c3:
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(plVar3 + 4));
      free(plVar3);
LAB_1800049de:
      bVar4 = true;
      goto LAB_180004955;
    }
  }
  else {
    if (plVar3 != (longlong *)0x0) {
      if (*plVar2 == *plVar3) {
        *(undefined8 *)(this + 0x38) = 0;
        *(longlong **)pHVar1 = plVar2;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(plVar3 + 4));
        free(plVar3);
        goto LAB_180004952;
      }
      if (plVar2 == (longlong *)0x0) {
        *(longlong *)pHVar1 = 0;
        if (plVar3 != (longlong *)0x0) goto LAB_1800049c3;
        goto LAB_1800049de;
      }
    }
    if (_DAT_1801cf5cc < *(float *)(this + 0x18)) {
      FUN_1800053f0((undefined8 *)pHVar1,(undefined8 *)(this + 0x38));
      bVar4 = true;
      goto LAB_180004955;
    }
    *(float *)(this + 0x18) =
         *(float *)(this + 0x18) + *(float *)(*(longlong *)(this + 0xe0) + 0x18);
  }
LAB_180004952:
  bVar4 = false;
LAB_180004955:
  plVar2 = local_res8;
  if (local_res8 != (longlong *)0x0) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(local_res8 + 4));
    free(plVar2);
  }
  return bVar4;
}


/* ---- 0x180004a20  CNO::HUDMarkerManager::GetAngleBetween  (407 bytes) ---- */

ulonglong CNO__HUDMarkerManager__GetAngleBetween
                    (undefined8 param_1,longlong param_2,longlong param_3)

{
  PlayerCharacter *pPVar1;
  undefined *puVar2;
  longlong lVar3;
  float fVar4;
  float fVar5;
  undefined4 extraout_XMM0_Db;
  undefined4 extraout_XMM0_Db_00;
  undefined4 extraout_XMM0_Db_01;
  undefined4 extraout_XMM0_Db_02;
  undefined4 extraout_XMM0_Db_03;
  ulonglong uVar6;
  undefined4 uVar7;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_58;
  undefined4 local_50;
  
  pPVar1 = RE::PlayerCharacter::GetSingleton();
  local_58 = *(undefined8 *)&pPVar1->field_0x54;
  local_50 = *(undefined4 *)&pPVar1->field_0x5c;
  local_68 = *(undefined8 *)(param_3 + 0x54);
  local_60 = *(undefined4 *)(param_3 + 0x5c);
  REL::Module::get();
  puVar2 = REL::Module::get();
  if ((puVar2[0x118] == '\x01') || (lVar3 = 0x170, puVar2[0x118] != '\x04')) {
    lVar3 = 0x154;
  }
  fVar5 = *(float *)(lVar3 + param_2);
  if (*(TESObjectCELL **)&pPVar1->field_0x60 != (TESObjectCELL *)0x0) {
    RE::TESObjectCELL::GetNorthRotation(*(TESObjectCELL **)&pPVar1->field_0x60);
  }
  fVar4 = RE::NiPoint3::GetHorizontalAngleTo((NiPoint3 *)&local_58,(float *)&local_68);
  if (6.2831855 < fVar5) {
    fVar5 = fmodf(fVar5,6.2831855);
  }
  else if (fVar5 < 0.0) {
    fVar5 = fmodf(fVar5,6.2831855);
    fVar5 = fVar5 + 6.2831855;
  }
  if (6.2831855 < fVar4) {
    fVar4 = fmodf(fVar4,6.2831855);
    uVar7 = extraout_XMM0_Db_01;
  }
  else {
    uVar7 = extraout_XMM0_Db;
    if (fVar4 < 0.0) {
      fVar4 = fmodf(fVar4,6.2831855);
      fVar4 = fVar4 + 6.2831855;
      uVar7 = extraout_XMM0_Db_00;
    }
  }
  fVar4 = fVar4 - fVar5;
  if (6.2831855 < fVar4) {
    fVar4 = fmodf(fVar4,6.2831855);
    uVar7 = extraout_XMM0_Db_03;
  }
  else if (fVar4 < 0.0) {
    fVar4 = fmodf(fVar4,6.2831855);
    fVar4 = fVar4 + 6.2831855;
    uVar7 = extraout_XMM0_Db_02;
  }
  fVar5 = (fVar4 * 180.0) / 3.1415927;
  if (fVar5 <= 180.0) {
    uVar6 = CONCAT44(uVar7,fVar5);
  }
  else {
    uVar6 = (ulonglong)(uint)(360.0 - fVar5);
  }
  return uVar6;
}


/* ---- 0x180004da0  CNO::HUDMarkerManager::GetSideInQuest  (465 bytes) ---- */

undefined8 * __thiscall
CNO::HUDMarkerManager::CNO__HUDMarkerManager__GetSideInQuest
          (HUDMarkerManager *this,undefined8 *__return_storage_ptr__,int param_2)

{
  bool bVar1;
  char cVar2;
  undefined8 uVar3;
  char *local_18;
  undefined8 local_10;
  
  if (param_2 == 9) {
    uVar3 = FUN_180004bc0((longlong)this,*(undefined8 *)(this + 0xf8));
    if ((char)uVar3 == '\0') {
      uVar3 = FUN_180004bc0((longlong)this,*(undefined8 *)(this + 0xf0));
      if ((char)uVar3 == '\0') {
        cVar2 = FUN_180004ce0((longlong)this,*(undefined8 *)(this + 0xe8));
        if (cVar2 == '\0') {
          *__return_storage_ptr__ = 0;
          __return_storage_ptr__[1] = 0;
          __return_storage_ptr__[2] = 0xe;
          __return_storage_ptr__[3] = 0xf;
          *__return_storage_ptr__ = 0x6c61697265706d49;
          *(undefined4 *)(__return_storage_ptr__ + 1) = 0x6967654c;
          *(undefined2 *)((longlong)__return_storage_ptr__ + 0xc) = 0x6e6f;
          *(undefined1 *)((longlong)__return_storage_ptr__ + 0xe) = 0;
          return __return_storage_ptr__;
        }
      }
    }
    *__return_storage_ptr__ = 0;
    __return_storage_ptr__[1] = 0;
    __return_storage_ptr__[2] = 0xb;
    __return_storage_ptr__[3] = 0xf;
    *__return_storage_ptr__ = 0x6f6c436d726f7453;
    *(undefined2 *)(__return_storage_ptr__ + 1) = 0x6b61;
    *(undefined1 *)((longlong)__return_storage_ptr__ + 10) = 0x73;
    *(undefined1 *)((longlong)__return_storage_ptr__ + 0xb) = 0;
    return __return_storage_ptr__;
  }
  if (param_2 != 10) {
    *__return_storage_ptr__ = 0;
    __return_storage_ptr__[1] = 0;
    __return_storage_ptr__[2] = 0;
    __return_storage_ptr__[3] = 0xf;
    *(undefined1 *)__return_storage_ptr__ = 0;
    return __return_storage_ptr__;
  }
  local_18 = "Vampire";
  local_10 = 7;
  bVar1 = RE::Actor::HasKeywordString(*(Actor **)(this + 0xd0),&local_18);
  if (!bVar1) {
    uVar3 = FUN_180004bc0((longlong)this,*(undefined8 *)(this + 0x108));
    if ((char)uVar3 == '\0') {
      cVar2 = FUN_180004ce0((longlong)this,*(undefined8 *)(this + 0x100));
      if (cVar2 == '\0') {
        *__return_storage_ptr__ = 0;
        __return_storage_ptr__[1] = 0;
        __return_storage_ptr__[2] = 9;
        __return_storage_ptr__[3] = 0xf;
        *__return_storage_ptr__ = 0x726175676e776144;
        *(undefined1 *)(__return_storage_ptr__ + 1) = 100;
        *(undefined1 *)((longlong)__return_storage_ptr__ + 9) = 0;
        return __return_storage_ptr__;
      }
    }
  }
  *__return_storage_ptr__ = 0;
  __return_storage_ptr__[1] = 0;
  __return_storage_ptr__[2] = 8;
  __return_storage_ptr__[3] = 0xf;
  *__return_storage_ptr__ = 0x73657269706d6156;
  *(undefined1 *)(__return_storage_ptr__ + 1) = 0;
  return __return_storage_ptr__;
}


/* ---- 0x18003a6e0  CNO::HUDMarkerManager::GetSingleton  (114 bytes) ---- */

undefined * __cdecl CNO::HUDMarkerManager::CNO__HUDMarkerManager__GetSingleton(void)

{
  undefined4 *puVar1;
  
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 0x14
              ) < DAT_1801d95b8) {
    puVar1 = &DAT_1801d95b8;
    _Init_thread_header(&DAT_1801d95b8);
    if (DAT_1801d95b8 == -1) {
      CNO__HUDMarkerManager__HUDMarkerManager(puVar1);
      atexit(`CNO::HUDMarkerManager::GetSingleton'::__l2::
             _dynamic_atexit_destructor_for__singleton__);
      _Init_thread_footer(&DAT_1801d95b8);
      return &DAT_1801d95c0;
    }
  }
  return &DAT_1801d95c0;
}


/* ---- 0x18003a760  CNO::HUDMarkerManager::HUDMarkerManager  (773 bytes) ---- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * CNO__HUDMarkerManager__HUDMarkerManager(void *param_1)

{
  undefined8 *puVar1;
  TESForm *pTVar2;
  undefined8 uVar3;
  longlong lVar4;
  void *local_res8;
  undefined *local_res10;
  undefined *local_res18;
  ulonglong local_28 [2];
  
  local_res10 = &DAT_1801d95c0;
  _DAT_1801d95c0 = DAT_1801d9530;
  _DAT_1801d95c8 = DAT_1801d9528;
  _DAT_1801d95d0 = DAT_1801cf5dc;
  _DAT_1801d95d4 = DAT_1801cf5d8;
  _DAT_1801d95d8 = 0;
  _DAT_1801d95e0 = 0;
  uRam00000001801d95e8 = 0;
  _DAT_1801d95f0 = 0;
  DAT_1801d95f8 = 0;
  DAT_1801d9600 = 0;
  local_res18 = &DAT_1801d9608;
  _DAT_1801d9608 = 0;
  _DAT_1801d9610 = (void *)0x0;
  _DAT_1801d9618 = 0;
  local_res8 = param_1;
  _DAT_1801d9610 = operator_new(0x58);
  *(void **)_DAT_1801d9610 = _DAT_1801d9610;
  *(void **)((longlong)_DAT_1801d9610 + 8) = _DAT_1801d9610;
  DAT_1801d9620 = (undefined8 *)0x0;
  _DAT_1801d9628 = (undefined8 *)0x0;
  DAT_1801d9630 = (undefined8 *)0x0;
  _DAT_1801d9638 = 7;
  _DAT_1801d9640 = 8;
  _DAT_1801d9608 = 0x3f800000;
  uVar3 = 0x80;
  local_res8 = _DAT_1801d9610;
  puVar1 = (undefined8 *)operator_new(0x80);
  lVar4 = (longlong)DAT_1801d9630 - (longlong)DAT_1801d9620 >> 3;
  if (lVar4 != 0) {
    FUN_180009aa0(uVar3,DAT_1801d9620,lVar4);
  }
  _DAT_1801d9628 = puVar1 + 0x10;
  DAT_1801d9620 = puVar1;
  DAT_1801d9630 = _DAT_1801d9628;
  FUN_18000a710(puVar1,_DAT_1801d9628,&local_res8);
  local_res18 = &DAT_1801d9648;
  _DAT_1801d9648 = 0;
  _DAT_1801d9650 = (void *)0x0;
  _DAT_1801d9658 = 0;
  _DAT_1801d9650 = operator_new(0x70);
  *(void **)_DAT_1801d9650 = _DAT_1801d9650;
  *(void **)((longlong)_DAT_1801d9650 + 8) = _DAT_1801d9650;
  DAT_1801d9660 = (undefined8 *)0x0;
  _DAT_1801d9668 = (undefined8 *)0x0;
  DAT_1801d9670 = (undefined8 *)0x0;
  _DAT_1801d9678 = 7;
  _DAT_1801d9680 = 8;
  _DAT_1801d9648 = 0x3f800000;
  uVar3 = 0x80;
  local_res8 = _DAT_1801d9650;
  puVar1 = (undefined8 *)operator_new(0x80);
  lVar4 = (longlong)DAT_1801d9670 - (longlong)DAT_1801d9660 >> 3;
  if (lVar4 != 0) {
    FUN_1800096c0(uVar3,DAT_1801d9660,lVar4);
  }
  _DAT_1801d9668 = puVar1 + 0x10;
  DAT_1801d9660 = puVar1;
  DAT_1801d9670 = _DAT_1801d9668;
  FUN_18000a6e0(puVar1,_DAT_1801d9668,&local_res8);
  local_28[0] = 0x7edbb;
  local_28[1] = 0x6328a;
  lVar4 = FUN_18000f860(local_28);
  _DAT_1801d9688 = FUN_18003ba30(lVar4);
  _DAT_1801d9690 = RE::PlayerCharacter::GetSingleton();
  _DAT_1801d9698 = FUN_1800992f0();
  local_28[0] = 0x7fd89;
  local_28[1] = 0x64254;
  lVar4 = FUN_18000f860(local_28);
  _DAT_1801d96a0 = FUN_18003d260(lVar4);
  pTVar2 = (TESForm *)RE::TESForm::LookupByID(0x2bf9a);
  _DAT_1801d96a8 = RE::TESForm::As<RE::TESFaction,void>(pTVar2);
  pTVar2 = (TESForm *)RE::TESForm::LookupByID(0x28849);
  _DAT_1801d96b0 = RE::TESForm::As<RE::TESFaction,void>(pTVar2);
  pTVar2 = (TESForm *)RE::TESForm::LookupByID(0x2bf9b);
  _DAT_1801d96b8 = RE::TESForm::As<RE::TESFaction,void>(pTVar2);
  pTVar2 = (TESForm *)RE::TESForm::LookupByID(0x2014217);
  _DAT_1801d96c0 = RE::TESForm::As<RE::TESFaction,void>(pTVar2);
  pTVar2 = (TESForm *)RE::TESForm::LookupByID(0x2003376);
  _DAT_1801d96c8 = RE::TESForm::As<RE::TESFaction,void>(pTVar2);
  return &DAT_1801d95c0;
}


/* ---- 0x18003aa70  CNO::HUDMarkerManager::~HUDMarkerManager  (136 bytes) ---- */

void __thiscall
CNO::HUDMarkerManager::CNO__HUDMarkerManager___HUDMarkerManager(HUDMarkerManager *this)

{
  void *pvVar1;
  
  FUN_18003b340((longlong *)(this + 0xa0));
  FUN_18003b3b0((longlong *)(this + 0x90));
  FUN_18003b510((longlong *)(this + 0x60));
  FUN_18003b580((longlong *)(this + 0x50));
  pvVar1 = *(void **)(this + 0x40);
  if (pvVar1 != (void *)0x0) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
               ((longlong)pvVar1 + 0x20));
    free(pvVar1);
  }
  pvVar1 = *(void **)(this + 0x38);
  if (pvVar1 != (void *)0x0) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
               ((longlong)pvVar1 + 0x20));
    free(pvVar1);
  }
  FUN_18003b6e0((longlong *)(this + 0x20));
  return;
}


