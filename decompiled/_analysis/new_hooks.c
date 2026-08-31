/* ==== 0x18003b130  FUN_18003b130  (75 bytes) ==== */

void FUN_18003b130(longlong param_1,undefined4 param_2)

{
  longlong lStackX_8;
  undefined4 auStackX_10 [2];
  undefined8 auStackX_18 [2];
  
  lStackX_8 = param_1;
  auStackX_10[0] = param_2;
  if (DAT_1801d9538 != '\0') {
    FUN_18009a2c0(*(longlong *)(param_1 + 0x48));
  }
  auStackX_18[0] = FUN_18003c000(DAT_1801d9550);
  FUN_18003b990(auStackX_18,&lStackX_8,auStackX_10);
  return;
}


/* ==== 0x18003b180  FUN_18003b180  (99 bytes) ==== */

void FUN_18003b180(longlong param_1,undefined4 param_2)

{
  int iVar1;
  longlong lStackX_8;
  undefined4 auStackX_10 [2];
  undefined8 auStackX_18 [2];
  
  lStackX_8 = param_1;
  auStackX_10[0] = param_2;
  if ((DAT_1801d9538 != '\0') &&
     ((iVar1 = *(int *)(*(longlong *)(param_1 + 0x40) + 0x14), iVar1 == 0x8afcc ||
      (iVar1 - 0x8afcdU < 2)))) {
    FUN_18009a2c0(*(longlong *)(param_1 + 0x48));
  }
  auStackX_18[0] = FUN_18003c010(DAT_1801d9548);
  FUN_18003b9c0(auStackX_18,&lStackX_8,auStackX_10);
  return;
}


/* ==== 0x18003b1f0  FUN_18003b1f0  (46 bytes) ==== */

void FUN_18003b1f0(undefined8 param_1)

{
  undefined8 local_res8;
  undefined8 local_res10 [3];
  
  local_res8 = param_1;
  local_res10[0] = FUN_18003bff0(DAT_1801d9540);
  FUN_18003b9f0(local_res10,&local_res8);
  return;
}


/* ==== 0x18003b230  FUN_18003b230  (61 bytes) ==== */

void FUN_18003b230(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined8 param_5)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = param_1;
  local_res8[0] = FUN_18003c030(DAT_1801d9578);
  FUN_18003b920(local_res8,param_2,param_3,param_4,param_5);
  return;
}


