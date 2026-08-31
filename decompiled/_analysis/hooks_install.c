
void FUN_18004e7e0(void)

{
  LPVOID pvVar1;
  void *pvVar2;
  undefined8 uVar3;
  longlong lVar4;
  Trampoline *pTVar5;
  char cVar6;
  undefined *puVar7;
  undefined8 *puVar8;
  void *_Src;
  ulonglong uVar9;
  void *pvVar10;
  code *pcVar11;
  longlong lVar12;
  ulonglong uVar13;
  LPVOID pvVar14;
  undefined *local_res8;
  longlong local_c68;
  LPVOID local_c60;
  code *local_c58;
  void *local_c50;
  void *local_c48;
  undefined8 uStack_c40;
  undefined8 local_c38;
  LPVOID local_c30;
  code *local_c28;
  void *local_c20;
  void *local_c18;
  undefined8 uStack_c10;
  longlong local_c08;
  LPVOID local_c00;
  void *local_bf8;
  void *local_bf0;
  void *pvStack_be8;
  void *local_be0;
  undefined8 local_bd8;
  LPVOID local_bd0;
  code *local_bc8;
  undefined8 local_bc0;
  undefined8 uStack_bb8;
  undefined8 local_bb0;
  undefined8 local_ba8;
  LPVOID local_ba0;
  code *local_b98;
  undefined8 local_b90;
  undefined8 uStack_b88;
  undefined8 local_b80;
  undefined8 local_b78;
  LPVOID local_b70;
  code *local_b68;
  undefined8 local_b60;
  undefined8 uStack_b58;
  undefined8 local_b50;
  CodeArray local_b48 [80];
  LabelManager local_af8 [2768];
  
  lVar12 = DAT_1801d9568;
  puVar7 = REL::Module::get();
  uVar13 = 0;
  if (puVar7[0x118] == '\x01') {
    uVar9 = 0x180;
  }
  else {
    uVar9 = uVar13;
    if (puVar7[0x118] == '\x02') {
      uVar9 = 0x114;
    }
  }
  pvVar1 = (LPVOID)(uVar9 + lVar12);
  puVar8 = FUN_18004ee70((undefined8 *)local_b48,(longlong)pvVar1);
  uVar9 = puVar8[8];
  local_c08 = uVar9 + 0xe;
  local_bf8 = (void *)0x0;
  pvVar2 = (void *)puVar8[7];
  local_bf0 = (void *)0x0;
  pvStack_be8 = (void *)0x0;
  local_be0 = (void *)0x0;
  local_c00 = pvVar1;
  if (uVar9 == 0) {
    _Src = (void *)0x0;
  }
  else {
    if (0x7fffffffffffffff < uVar9) {
      FUN_180058af0();
      pcVar11 = (code *)swi(3);
      (*pcVar11)();
      return;
    }
    if (uVar9 < 0x1000) {
      _Src = operator_new(uVar9);
    }
    else {
      _Src = std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>(uVar9);
    }
    local_bf0 = _Src;
    local_be0 = (void *)(uVar9 + (longlong)_Src);
    FUN_180058610(pvVar2,uVar9 + (longlong)pvVar2,_Src);
    pvStack_be8 = (void *)(uVar9 + (longlong)_Src);
  }
  pvVar2 = pvStack_be8;
  Xbyak::LabelManager::~LabelManager(local_af8);
  Xbyak::CodeArray::~CodeArray(local_b48);
  lVar12 = DAT_1801d9570;
  puVar7 = REL::Module::get();
  lVar4 = DAT_1801d9570;
  if (puVar7[0x118] == '\x01') {
    uVar9 = 0x13c;
  }
  else {
    uVar9 = uVar13;
    if (puVar7[0x118] == '\x02') {
      uVar9 = 0x139;
    }
  }
  local_c68 = 0xe;
  local_c60 = (LPVOID)(uVar9 + lVar12);
  local_c58 = hooks::hooks__hooks__AllowedToShowMapMarker;
  local_c50 = (void *)0x0;
  local_c48 = (void *)0x0;
  uStack_c40 = 0;
  puVar7 = REL::Module::get();
  lVar12 = DAT_1801d9570;
  if (puVar7[0x118] == '\x01') {
    uVar9 = 0x24b;
  }
  else {
    uVar9 = uVar13;
    if (puVar7[0x118] == '\x02') {
      uVar9 = 0x21c;
    }
  }
  local_c38 = 0xe;
  local_c30 = (LPVOID)(uVar9 + lVar4);
  local_c28 = hooks::hooks__hooks__AllowedToShowMapMarker;
  local_c20 = (void *)0x0;
  local_c18 = (void *)0x0;
  uStack_c10 = 0;
  puVar7 = REL::Module::get();
  if (puVar7[0x118] == '\x01') {
    uVar9 = 0x473;
  }
  else {
    uVar9 = uVar13;
    if (puVar7[0x118] == '\x02') {
      uVar9 = 0x450;
    }
  }
  local_bd8 = 0xe;
  local_bd0 = (LPVOID)(uVar9 + lVar12);
  local_bc8 = hooks__UpdateLocations;
  local_bc0 = 0;
  uStack_bb8 = 0;
  local_bb0 = 0;
  puVar7 = REL::Module::get();
  lVar12 = DAT_1801d9580;
  local_res8 = *(undefined **)(puVar7 + 0x108);
  uVar9 = uVar13;
  do {
    if (*(ushort *)((longlong)&local_res8 + uVar9) != *(ushort *)((longlong)&DAT_180191830 + uVar9))
    {
      cVar6 = '\x01';
      if (*(ushort *)((longlong)&local_res8 + uVar9) < *(ushort *)((longlong)&DAT_180191830 + uVar9)
         ) {
        cVar6 = -1;
      }
      goto LAB_18004ea2c;
    }
    uVar9 = uVar9 + 2;
  } while (uVar9 < 8);
  cVar6 = '\0';
LAB_18004ea2c:
  puVar7 = REL::Module::get();
  uVar9 = ((longlong)cVar6 >> 0x3f & 0xffffffffffffff60U) + 0x1735;
  if ((puVar7[0x118] != '\x01') && (uVar9 = uVar13, puVar7[0x118] == '\x02')) {
    uVar9 = 0x15ab;
  }
  local_ba8 = 0xe;
  local_ba0 = (LPVOID)(lVar12 + uVar9);
  local_b98 = FUN_18003af50;
  local_b90 = 0;
  uStack_b88 = 0;
  local_b80 = 0;
  puVar7 = REL::Module::get();
  if (puVar7[0x118] == '\x01') {
    pvVar14 = (LPVOID)(DAT_1801d9598 + 0xae);
  }
  else {
    pvVar14 = (LPVOID)(DAT_1801d9590 + 0x8d);
  }
  local_b78 = 0xe;
  local_b68 = FUN_18003b010;
  local_b60 = 0;
  uStack_b58 = 0;
  local_b50 = 0;
  local_b70 = pvVar14;
  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
               0x14) < DAT_1801d97d8) && (_Init_thread_header(&DAT_1801d97d8), DAT_1801d97d8 == -1))
  {
    lVar12 = local_c68 + local_c08;
    DAT_1801d97e0 = (Trampoline *)SKSE::GetTrampoline();
    DAT_1801d97e8 = 0;
    FUN_1800a1b30(lVar12 + 0x2a,'\x01');
    atexit(FUN_180162180);
    _Init_thread_footer(&DAT_1801d97d8);
  }
  pTVar5 = DAT_1801d97e0;
  pvVar10 = (void *)0x0;
  if (_Src != pvVar2) {
    pvVar10 = (void *)FUN_1800a6720((longlong)DAT_1801d97e0,(longlong)pvVar2 - (longlong)_Src);
    SKSE::Trampoline::log_stats(pTVar5);
    memcpy(pvVar10,_Src,(longlong)pvVar2 - (longlong)_Src);
    local_bf8 = pvVar10;
  }
  hooks__Trampoline__write_call_6_((longlong *)DAT_1801d97e0,pvVar1,(ulonglong)pvVar10,0xe9);
  pTVar5 = DAT_1801d97e0;
  if ((local_c58 == (code *)0x0) && (local_c50 != local_c48)) {
    pcVar11 = (code *)FUN_1800a6720((longlong)DAT_1801d97e0,
                                    (longlong)local_c48 - (longlong)local_c50);
    SKSE::Trampoline::log_stats(pTVar5);
    memcpy(pcVar11,local_c50,(longlong)local_c48 - (longlong)local_c50);
    local_c58 = pcVar11;
  }
  hooks__Trampoline__write_call_6_((longlong *)DAT_1801d97e0,local_c60,(ulonglong)local_c58,0xe8);
  pTVar5 = DAT_1801d97e0;
  if ((local_c28 == (code *)0x0) && (local_c20 != local_c18)) {
    pcVar11 = (code *)FUN_1800a6720((longlong)DAT_1801d97e0,
                                    (longlong)local_c18 - (longlong)local_c20);
    SKSE::Trampoline::log_stats(pTVar5);
    memcpy(pcVar11,local_c20,(longlong)local_c18 - (longlong)local_c20);
    local_c28 = pcVar11;
  }
  hooks__Trampoline__write_call_6_((longlong *)DAT_1801d97e0,local_c30,(ulonglong)local_c28,0xe8);
  hooks__Trampoline__write_call_6_((longlong *)DAT_1801d97e0,local_bd0,0x18003ad60,0xe8);
  hooks__Trampoline__write_call_6_((longlong *)DAT_1801d97e0,local_ba0,0x18003af50,0xe8);
  hooks__Trampoline__write_call_6_((longlong *)DAT_1801d97e0,pvVar14,0x18003b010,0xe8);
  local_res8 = SKSE::stl::unrestricted_cast<unsigned___int64,void_(__cdecl*)(RE::Compass_*)>();
  FUN_1800549f0((LPVOID)(DAT_1801d9588 + 8),&local_res8);
  local_res8 = FUN_180052540();
  uVar3 = *(undefined8 *)(DAT_1801d95a8 + 0x20);
  FUN_1800549f0((undefined8 *)(DAT_1801d95a8 + 0x20),&local_res8);
  DAT_1801d9550 = uVar3;
  local_res8 = FUN_180052550();
  uVar3 = *(undefined8 *)(DAT_1801d95a0 + 0x20);
  FUN_1800549f0((undefined8 *)(DAT_1801d95a0 + 0x20),&local_res8);
  DAT_1801d9548 = uVar3;
  local_res8 = FUN_180052560();
  uVar3 = *(undefined8 *)(DAT_1801d95b0 + 0x1f0);
  FUN_1800549f0((undefined8 *)(DAT_1801d95b0 + 0x1f0),&local_res8);
  DAT_1801d9540 = uVar3;
  _eh_vector_destructor_iterator_(&local_c68,0x30,2,FUN_18004f7d0);
  if (_Src != (void *)0x0) {
    pvVar10 = _Src;
    if ((0xfff < (ulonglong)((longlong)pvVar2 - (longlong)_Src)) &&
       (pvVar10 = *(void **)((longlong)_Src + -8),
       0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar10)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    free(pvVar10);
  }
  return;
}

