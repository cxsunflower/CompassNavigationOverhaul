/* ============================================================
 * utils.c  ——  CompassNavigationOverhaul 2.9.9 反编译产物
 * 由 Ghidra 11.3.2 反编译器从 SKSE/Plugins/CompassNavigationOverhaul.dll 导出。
 * 函数名来自 2.2.0-VR 版 PDB 的跨版本符号映射；FUN_xxxxxxxx 表示尚未对上真名。
 * 共 2 个函数。这是「2.9.9 行为的唯一事实来源」，不可直接编译。
 * ============================================================ */

/* ---- 0x1800549f0  utils::write_vfunc_impl  (11 bytes) ---- */

void utils__write_vfunc_impl(LPVOID param_1,void *param_2)

{
  REL::safe_write(param_1,param_2,8);
  return;
}


/* ---- 0x18009a2c0  utils::GetMagicEffectArea  (20 bytes) ---- */

undefined4 utils__GetMagicEffectArea(longlong param_1)

{
  if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x68) & 0x800) != 0) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 4);
}


