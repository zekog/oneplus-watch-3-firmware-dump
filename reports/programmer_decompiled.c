// ===========================================================
// Function: FUN_04100004 at 04100004
// ===========================================================

undefined8 FUN_04100004(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0410063c;
  if (param_3 * 0x10000 != 1) {
    uVar1 = 0;
  }
  return CONCAT44(param_3 << 0x10,uVar1);
}



// ===========================================================
// Function: FUN_04100008 at 04100008
// ===========================================================

undefined8 FUN_04100008(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0410063c;
  if (param_3 * 0x10000 != 1) {
    uVar1 = 0;
  }
  return CONCAT44(param_3 << 0x10,uVar1);
}



// ===========================================================
// Function: FUN_0410000c at 0410000c
// ===========================================================

undefined8 FUN_0410000c(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0410063c;
  if (param_3 * 0x10000 != 1) {
    uVar1 = 0;
  }
  return CONCAT44(param_3 << 0x10,uVar1);
}



// ===========================================================
// Function: FUN_04100010 at 04100010
// ===========================================================

undefined4 FUN_04100010(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0410063c;
  if (param_3 * 0x10000 != 1) {
    uVar1 = 0;
  }
  return uVar1;
}



// ===========================================================
// Function: FUN_04100014 at 04100014
// ===========================================================

undefined4 FUN_04100014(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0410063c;
  if (param_3 * 0x10000 != 1) {
    uVar1 = 0;
  }
  return uVar1;
}



// ===========================================================
// Function: FUN_04100018 at 04100018
// ===========================================================

undefined4 FUN_04100018(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0410063c;
  if (param_3 * 0x10000 != 1) {
    uVar1 = 0;
  }
  return uVar1;
}



// ===========================================================
// Function: FUN_0410001c at 0410001c
// ===========================================================

undefined4 FUN_0410001c(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0410063c;
  if (param_3 * 0x10000 != 1) {
    uVar1 = 0;
  }
  return uVar1;
}



// ===========================================================
// Function: FUN_04100684 at 04100684
// ===========================================================

void FUN_04100684(undefined4 param_1,undefined4 param_2)

{
  *DAT_0410068c = param_2;
  return;
}



// ===========================================================
// Function: FUN_04100690 at 04100690
// ===========================================================

void FUN_04100690(void)

{
  return;
}



// ===========================================================
// Function: FUN_0410072c at 0410072c
// ===========================================================

void FUN_0410072c(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_lr;
  
  puVar2 = DAT_041007a8;
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_041007a8 = 0x4100742;
    puVar2[1] = unaff_lr;
    FUN_0410c858(1,2);
    *(undefined4 *)(DAT_041007ac + param_1 * 4) = 0;
    *(undefined4 *)(DAT_041007b0 + param_1 * 4) = 0;
    *(undefined4 *)(DAT_041007b4 + param_1 * 4) = 0;
    *(undefined4 *)(DAT_041007b8 + param_1 * 4) = 0;
    *(undefined1 *)(DAT_041007bc + param_1) = 0;
    if (iVar4 == 0) {
      *puVar2 = 0xffffffff;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(iVar4);
    }
    return;
  }
  FUN_0410c858(1,2);
  iVar4 = DAT_041007ac;
  *(undefined4 *)(DAT_041007b0 + param_1 * 4) = 0;
  iVar3 = DAT_041007b8;
  *(undefined4 *)(iVar4 + param_1 * 4) = 0;
  *(undefined4 *)(iVar3 + param_1 * 4) = 0;
  iVar4 = DAT_041007bc;
  *(undefined4 *)(DAT_041007b4 + param_1 * 4) = 0;
  *(undefined1 *)(iVar4 + param_1) = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x40);
  }
  return;
}



// ===========================================================
// Function: FUN_04100804 at 04100804
// ===========================================================

undefined4 FUN_04100804(undefined4 param_1,uint param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  char *pcVar2;
  uint *puVar3;
  int *piVar4;
  uint *puVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  char cVar10;
  code *pcVar11;
  int *piVar12;
  
  piVar4 = DAT_041008fc;
  puVar3 = DAT_041008f8;
  pcVar2 = DAT_041008f4;
  if (*DAT_041008f4 != '\x01') {
    return 1;
  }
  *DAT_041008f8 = *DAT_041008f8 + param_2;
  puVar5 = DAT_04100900;
  pcVar11 = (code *)*piVar4;
  if (pcVar11 == (code *)0x0) {
    if (param_3 == 0) {
      cVar10 = '\x02';
    }
    else {
      cVar10 = '\x03';
    }
    *pcVar2 = cVar10;
    return 1;
  }
  uVar7 = *DAT_04100900;
  piVar12 = DAT_0410090c;
  if (((*puVar3 < uVar7) && ((param_2 & 0x3f) != 0)) || (param_3 != 0)) {
LAB_04100834:
    uVar7 = *puVar3;
    iVar8 = *piVar12;
    *puVar5 = 0;
    pcVar6 = DAT_04100904;
    *piVar4 = 0;
    *puVar3 = 0;
    *piVar12 = 0;
    uVar9 = 1;
    if (pcVar11 == pcVar6) {
      cVar10 = '\x03';
      goto LAB_041008be;
    }
  }
  else {
    cVar10 = *DAT_04100908;
    if ((cVar10 == '\0') && (uVar7 <= *puVar3)) {
      bVar1 = true;
    }
    else {
      if (*puVar3 < uVar7) {
        uVar7 = uVar7 - *puVar3;
        if (0xffbf < uVar7) {
          uVar7 = 0xffc0;
        }
      }
      else {
        uVar7 = 0;
        *DAT_04100908 = '\0';
      }
      piVar12 = DAT_0410090c;
      iVar8 = FUN_0410d9e8(2,*puVar3 + *DAT_0410090c,uVar7,1,param_4);
      if (iVar8 != 0) {
        pcVar11 = (code *)*piVar4;
        goto LAB_04100834;
      }
      uVar7 = *puVar5;
      bVar1 = cVar10 == '\0';
    }
    if (*puVar3 < uVar7) {
      return 1;
    }
    if (!bVar1) {
      return 1;
    }
    uVar9 = 0;
    pcVar11 = (code *)*piVar4;
    uVar7 = *puVar3;
    *puVar5 = 0;
    pcVar6 = DAT_04100904;
    *puVar3 = 0;
    piVar12 = DAT_0410090c;
    *piVar4 = 0;
    iVar8 = *piVar12;
    *piVar12 = 0;
    if (pcVar11 == pcVar6) {
      cVar10 = '\x02';
LAB_041008be:
      *pcVar2 = cVar10;
      pcVar11 = DAT_04100904;
      goto LAB_04100854;
    }
  }
  *pcVar2 = '\0';
LAB_04100854:
  (*pcVar11)(iVar8,uVar7,uVar9);
  return 1;
}



// ===========================================================
// Function: FUN_04100c9c at 04100c9c
// ===========================================================

void FUN_04100c9c(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_lr;
  
  puVar2 = DAT_04100d24;
  iVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar3 = getBasePriority();
  }
  if (iVar3 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04100d24 = 0x4100cb2;
    puVar2[1] = unaff_lr;
    FUN_0410c858(0,2);
    *(undefined4 *)(DAT_04100d28 + param_1 * 4) = 0;
    *(undefined4 *)(DAT_04100d2c + param_1 * 4) = 0;
    *(undefined4 *)(DAT_04100d30 + param_1 * 4) = 0;
    *(undefined4 *)(DAT_04100d34 + param_1 * 4) = 0;
    *(undefined4 *)(DAT_04100d38 + param_1 * 4) = 0;
    *(undefined1 *)(DAT_04100d3c + param_1) = 0;
    if (iVar3 == 0) {
      *puVar2 = 0xffffffff;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(iVar3);
    }
    return;
  }
  FUN_0410c858(0,2);
  iVar3 = DAT_04100d2c;
  *(undefined4 *)(DAT_04100d28 + param_1 * 4) = 0;
  *(undefined4 *)(iVar3 + param_1 * 4) = 0;
  iVar3 = DAT_04100d34;
  *(undefined4 *)(DAT_04100d30 + param_1 * 4) = 0;
  *(undefined4 *)(iVar3 + param_1 * 4) = 0;
  iVar3 = DAT_04100d3c;
  *(undefined4 *)(DAT_04100d38 + param_1 * 4) = 0;
  *(undefined1 *)(iVar3 + param_1) = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x40);
  }
  return;
}



// ===========================================================
// Function: FUN_04100d40 at 04100d40
// ===========================================================

undefined4 FUN_04100d40(undefined4 param_1,uint param_2,int param_3)

{
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  uint *puVar4;
  undefined4 *puVar5;
  code *pcVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  char cVar11;
  code *pcVar12;
  
  piVar3 = DAT_04100e24;
  puVar2 = DAT_04100e20;
  pcVar1 = DAT_04100e1c;
  if (*DAT_04100e1c != '\x01') {
    return 1;
  }
  *DAT_04100e20 = *DAT_04100e20 + param_2;
  piVar7 = DAT_04100e38;
  puVar5 = DAT_04100e30;
  puVar4 = DAT_04100e2c;
  pcVar12 = (code *)*piVar3;
  if (pcVar12 == (code *)0x0) {
    if (param_3 == 0) {
      cVar11 = '\x02';
    }
    else {
      cVar11 = '\x03';
    }
    *pcVar1 = cVar11;
    return 1;
  }
  if (*DAT_04100e28 == '\0') {
    uVar9 = *DAT_04100e2c;
    if (((*puVar2 < uVar9) && ((param_2 & 3) != 0)) || (param_3 != 0)) goto LAB_04100d6c;
    if (*puVar2 < uVar9) {
      if (uVar9 - *puVar2 < 0xffc0) {
        uVar9 = (uVar9 - *puVar2) + 0x3f & 0xffffffc0;
        if (uVar9 == 0) goto LAB_04100df0;
      }
      else {
        uVar9 = 0xffc0;
      }
      iVar8 = FUN_0410d8f4(2,*puVar2 + *DAT_04100e38,uVar9);
      if (iVar8 == 0) {
        return 1;
      }
      pcVar12 = (code *)*piVar3;
      goto LAB_04100d6c;
    }
LAB_04100df0:
    uVar10 = 0;
    *piVar3 = 0;
    pcVar6 = DAT_04100e34;
    *puVar4 = 0;
    piVar3 = DAT_04100e38;
    *puVar5 = 0;
    iVar8 = *piVar3;
    uVar9 = *puVar2;
    *piVar3 = 0;
    *puVar2 = 0;
    if (pcVar12 != pcVar6) goto LAB_04100d8c;
    cVar11 = '\x02';
  }
  else {
    if (param_3 == 0) goto LAB_04100df0;
LAB_04100d6c:
    puVar5 = DAT_04100e30;
    iVar8 = *piVar7;
    *piVar3 = 0;
    pcVar6 = DAT_04100e34;
    *puVar5 = 0;
    uVar9 = *puVar2;
    *puVar4 = 0;
    *puVar2 = 0;
    *piVar7 = 0;
    uVar10 = 1;
    if (pcVar12 != pcVar6) {
LAB_04100d8c:
      *pcVar1 = '\0';
      goto LAB_04100d90;
    }
    cVar11 = '\x03';
  }
  *pcVar1 = cVar11;
  pcVar12 = DAT_04100e34;
LAB_04100d90:
  (*pcVar12)(iVar8,uVar9,uVar10);
  return 1;
}



// ===========================================================
// Function: FUN_04100e3c at 04100e3c
// ===========================================================

undefined4 FUN_04100e3c(int param_1,undefined4 param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = DAT_04100eec + param_1;
  iVar3 = FUN_04107124(iVar5);
  iVar1 = DAT_04100ef4;
  if (iVar3 == 0) {
    *(undefined1 *)(DAT_04100ef0 + param_1) = 1;
    uVar4 = DAT_04100efc;
    *(undefined4 *)(DAT_04100ef8 + param_1 * 4) = param_2;
    pcVar2 = DAT_04100f04;
    *(undefined1 *)(DAT_04100f00 + param_1) = 0;
    *(undefined1 *)(DAT_04100f08 + param_1) = 0;
    *(undefined1 *)(DAT_04100f0c + param_1) = 0;
    *(undefined1 *)(DAT_04100f10 + param_1) = 0;
    *(undefined1 *)(DAT_04100f14 + param_1) = 0;
    *(undefined1 *)(DAT_04100f18 + param_1) = 0;
    FUN_0410ef70(iVar1 + param_1 * 0x10,uVar4,8);
    *(undefined4 *)(DAT_04100f1c + param_1 * 4) = 0;
    *(undefined4 *)(DAT_04100f20 + param_1 * 4) = 0;
    *(undefined4 *)(DAT_04100f24 + param_1 * 4) = 0;
    *(undefined4 *)(DAT_04100f28 + param_1 * 4) = 0;
    *(undefined4 *)(DAT_04100f2c + param_1 * 4) = 0;
    *(undefined4 *)(DAT_04100f30 + param_1 * 4) = 0;
    *(undefined4 *)(DAT_04100f34 + param_1 * 4) = 0;
    *(undefined4 *)(DAT_04100f38 + param_1 * 4) = 0;
    *(undefined4 *)(DAT_04100f3c + param_1 * 4) = 0;
    uVar4 = 0;
    if (*pcVar2 == '\0') {
      uVar4 = FUN_0410d804(DAT_04100f40,1,0,0);
    }
    pcVar2[param_1] = '\x01';
    FUN_0410714c(iVar5);
  }
  else {
    uVar4 = 0xfffffff7;
  }
  return uVar4;
}



// ===========================================================
// Function: FUN_04100f44 at 04100f44
// ===========================================================

void FUN_04100f44(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = DAT_04100fbc;
  if (param_2 < 2) {
    *(undefined1 *)(DAT_04100fb8 + param_1) = 0;
    *(undefined1 *)(iVar1 + param_1) = 0;
    if (param_2 != 0) {
      return;
    }
    bVar3 = true;
  }
  else {
    bVar3 = false;
    if ((param_2 & 0xfd) != 0) {
      bVar3 = false;
      iVar1 = DAT_04100fa8;
      iVar2 = DAT_04100fb0;
      goto joined_r0x04100f6e;
    }
  }
  *(undefined1 *)(DAT_04100fa0 + param_1) = 0;
  *(undefined1 *)(DAT_04100fa4 + param_1) = 0;
  iVar1 = DAT_04100fa8;
  iVar2 = DAT_04100fb0;
joined_r0x04100f6e:
  if ((param_2 != 3) && (!bVar3)) {
    DAT_04100fb0 = iVar2;
    DAT_04100fa8 = iVar1;
    return;
  }
  DAT_04100fa8 = iVar1;
  DAT_04100fb0 = iVar2;
  *(undefined1 *)(DAT_04100fac + param_1) = 0;
  *(undefined1 *)(iVar1 + param_1) = 0;
  FUN_0410ef70(iVar2 + param_1 * 0x10,DAT_04100fb4,8);
  return;
}



// ===========================================================
// Function: FUN_04100fc0 at 04100fc0
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_04100fc0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = DAT_04100ff8 + param_1;
  iVar2 = FUN_04107124(iVar4);
  iVar1 = _LAB_04101004;
  if (iVar2 == 0) {
    if (*(char *)(_DAT_04100ffc + param_1) == '\0') {
      *(undefined4 *)(_LAB_04101000 + param_1 * 4) = 0;
      *(undefined4 *)(iVar1 + param_1 * 4) = 0;
    }
    FUN_0410714c(iVar4);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xfffffff7;
  }
  return uVar3;
}



// ===========================================================
// Function: FUN_04101008 at 04101008
// ===========================================================

void FUN_04101008(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_04101044 + param_1;
  *(undefined1 *)(DAT_04101048 + param_1) = 1;
  iVar1 = FUN_04107124(iVar2);
  if (iVar1 != 0) {
    return;
  }
  if (*(char *)(DAT_0410104c + param_1) != '\x01') {
    FUN_0410714c(iVar2);
    return;
  }
  FUN_04100c9c(param_1);
  FUN_0410714c(iVar2);
  return;
}



// ===========================================================
// Function: FUN_04101050 at 04101050
// ===========================================================

undefined4 FUN_04101050(int param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 local_38;
  
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  iVar1 = DAT_041011b0;
  if (*(char *)(DAT_041011b0 + param_1) == '\0') {
    if ((param_2 == 0) || (param_3 == 0)) {
      local_38 = 0xfffffff5;
    }
    else {
      iVar9 = DAT_041011b4 + param_1;
      iVar5 = FUN_04107124(iVar9);
      iVar4 = DAT_041011d0;
      iVar3 = DAT_041011cc;
      iVar2 = DAT_041011b8;
      if (iVar5 == 0) {
        if (*(char *)(DAT_041011b8 + param_1) == '\0') {
          iVar10 = DAT_041011bc + param_1 * 0x40;
          iVar5 = 0;
          do {
            uVar7 = *(uint *)(iVar3 + param_1 * 4);
            while (uVar7 < *(uint *)(iVar4 + param_1 * 4)) {
              uVar8 = *(int *)(iVar4 + param_1 * 4) - uVar7;
              iVar6 = param_2 + iVar5;
              if (param_3 <= uVar8) {
                uVar8 = param_3;
              }
              iVar5 = iVar5 + uVar8;
              FUN_0410ef70(iVar6,uVar7 + iVar10);
              uVar7 = *(int *)(iVar3 + param_1 * 4) + uVar8;
              param_3 = param_3 - uVar8;
              *(uint *)(iVar3 + param_1 * 4) = uVar7;
              if (param_3 == 0) {
                local_38 = 0;
                goto joined_r0x04101192;
              }
            }
            *(undefined4 *)(DAT_041011c0 + param_1 * 4) = 0;
            iVar6 = DAT_041011c4;
            *(undefined4 *)(iVar4 + param_1 * 4) = 0;
            *(undefined4 *)(iVar6 + param_1 * 4) = 0;
            iVar6 = DAT_041011c8;
            *(undefined4 *)(iVar3 + param_1 * 4) = 0;
            *(undefined4 *)(iVar6 + param_1 * 4) = 0;
            *(undefined1 *)(iVar2 + param_1) = 1;
            iVar6 = FUN_0410d8f4(2,iVar10,0x40);
            if (iVar6 != 0) {
              local_38 = 0xffffffff;
              goto joined_r0x04101192;
            }
            do {
              if ((*(char *)(iVar2 + param_1) != '\x01') || (*(char *)(iVar1 + param_1) != '\0'))
              break;
              iVar6 = FUN_04106ed0();
            } while (iVar6 != 0);
            if (*(char *)(iVar1 + param_1) != '\0') {
              FUN_0410c858(0,2);
              local_38 = 0xfffffff2;
              goto joined_r0x04101192;
            }
          } while (*(char *)(iVar2 + param_1) == '\x02');
          local_38 = 0xfffffffe;
joined_r0x04101192:
          if (param_4 != (int *)0x0) {
            *param_4 = iVar5;
          }
          *(undefined1 *)(iVar2 + param_1) = 0;
        }
        else {
          local_38 = 0xfffffffd;
        }
        FUN_0410714c(iVar9);
      }
      else {
        local_38 = 0xfffffff7;
      }
    }
  }
  else {
    local_38 = 0xfffffff2;
  }
  return local_38;
}



// ===========================================================
// Function: FUN_041011d4 at 041011d4
// ===========================================================

undefined4
FUN_041011d4(int param_1,uint param_2,uint param_3,uint param_4,undefined4 *param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  iVar2 = DAT_041013a8;
  if (*(char *)(DAT_041013a8 + param_1) == '\0') {
    param_3 = param_3 & 0xffffffc0;
    if ((param_2 == 0) || (param_3 < param_4)) {
      uVar10 = 0xfffffff5;
    }
    else if ((param_2 & 3) == 0) {
      iVar9 = DAT_04101388 + param_1;
      iVar6 = FUN_04107124(iVar9);
      iVar5 = DAT_041013b0;
      iVar4 = DAT_041013ac;
      iVar1 = DAT_0410138c;
      if (iVar6 == 0) {
        if (*(char *)(DAT_0410138c + param_1) != '\0') {
          FUN_0410714c(iVar9);
          return 0xfffffffd;
        }
        *(undefined4 *)(DAT_04101390 + param_1 * 4) = 0;
        *(undefined4 *)(iVar4 + param_1 * 4) = 0;
        *(uint *)(iVar5 + param_1 * 4) = param_2;
        iVar7 = DAT_04101398;
        iVar6 = DAT_04101394;
        if (param_4 == 0) {
          *(uint *)(DAT_04101394 + param_1 * 4) = param_3;
          *(undefined1 *)(iVar7 + param_1) = 1;
        }
        else {
          *(uint *)(DAT_04101394 + param_1 * 4) = param_4;
          *(undefined1 *)(DAT_04101398 + param_1) = 0;
          param_3 = param_4;
        }
        if (param_1 == 0) {
          iVar7 = DAT_0410139c;
          if (param_6 != 0) {
            iVar7 = param_6;
          }
          *DAT_041013a0 = iVar7;
        }
        *(undefined4 *)(DAT_041013a4 + param_1 * 4) = 0;
        if (param_3 < 0xffc0) {
          uVar8 = param_3 + 0x3f & 0xffffffc0;
        }
        else {
          uVar8 = 0xffc0;
        }
        *(undefined1 *)(iVar1 + param_1) = 1;
        iVar7 = FUN_0410d8f4(2,param_2,uVar8);
        if (iVar7 == 0) {
          uVar10 = 0;
          if (param_6 != 0) {
            FUN_0410714c(iVar9);
            if (*(char *)(iVar2 + param_1) == '\0') {
              return 0;
            }
            FUN_04100c9c(param_1);
            return 0xfffffff2;
          }
          do {
            if ((*(char *)(iVar1 + param_1) != '\x01') || (*(char *)(iVar2 + param_1) != '\0'))
            break;
            iVar7 = FUN_04106ed0();
          } while (iVar7 != 0);
          if (*(char *)(iVar2 + param_1) == '\0') {
            if (*(char *)(iVar1 + param_1) != '\x02') {
              uVar10 = 0xfffffffe;
            }
          }
          else {
            uVar10 = 0xfffffff2;
            FUN_0410c858(0,2);
          }
        }
        else {
          uVar10 = 0xffffffff;
        }
        piVar3 = DAT_041013a0;
        if (param_5 == (undefined4 *)0x0) {
          *(undefined4 *)(iVar4 + param_1 * 4) = 0;
          iVar2 = DAT_04101390;
          *(undefined4 *)(iVar5 + param_1 * 4) = 0;
          *(undefined4 *)(iVar2 + param_1 * 4) = 0;
          *(undefined1 *)(iVar1 + param_1) = 0;
          *(undefined4 *)(iVar6 + param_1 * 4) = 0;
          DAT_041013a0[param_1] = 0;
          FUN_0410714c(iVar9);
          return uVar10;
        }
        *param_5 = *(undefined4 *)(DAT_041013a4 + param_1 * 4);
        iVar2 = DAT_04101390;
        piVar3[param_1] = 0;
        *(undefined4 *)(iVar2 + param_1 * 4) = 0;
        *(undefined4 *)(iVar4 + param_1 * 4) = 0;
        *(undefined4 *)(iVar6 + param_1 * 4) = 0;
        *(undefined4 *)(iVar5 + param_1 * 4) = 0;
        *(undefined1 *)(iVar1 + param_1) = 0;
        FUN_0410714c(iVar9);
      }
      else {
        uVar10 = 0xfffffff7;
      }
    }
    else {
      uVar10 = 0xfffffff4;
    }
  }
  else {
    uVar10 = 0xfffffff2;
  }
  return uVar10;
}



// ===========================================================
// Function: FUN_041013fc at 041013fc
// ===========================================================

undefined4 FUN_041013fc(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  iVar1 = DAT_04101590;
  if (*(char *)(DAT_0410158c + param_1) == '\0') {
    uVar7 = 0xfffffff6;
  }
  else if (*(char *)(DAT_04101590 + param_1) == '\0') {
    if ((param_2 == 0) && (param_3 != 0)) {
      uVar7 = 0xfffffff5;
    }
    else {
      iVar5 = DAT_04101594 + param_1;
      iVar4 = FUN_04107124(iVar5);
      iVar3 = DAT_041015a0;
      iVar2 = DAT_04101598;
      if (iVar4 == 0) {
        if (*(char *)(DAT_04101598 + param_1) == '\0') {
          iVar8 = DAT_0410159c + param_1 * 0x40;
          *(bool *)(DAT_041015a4 + param_1) = param_3 != 0 && (param_3 & 0x3f) == 0;
          iVar4 = DAT_041015a8;
          *(undefined4 *)(iVar3 + param_1 * 4) = 0;
          *(undefined4 *)(iVar4 + param_1 * 4) = 0;
          *(undefined4 *)(DAT_041015ac + param_1 * 4) = 0;
          *(undefined4 *)(DAT_041015b0 + param_1 * 4) = 0;
LAB_04101472:
          if (param_3 <= *(uint *)(iVar3 + param_1 * 4)) goto LAB_04101506;
LAB_0410147a:
          uVar6 = param_3 - *(int *)(iVar3 + param_1 * 4);
          *(undefined1 *)(iVar2 + param_1) = 1;
          if (uVar6 < 0x41) {
            if (uVar6 == 0) goto LAB_041014a2;
          }
          else {
            uVar6 = 0x40;
          }
          FUN_0410ef70(iVar8,*(int *)(iVar3 + param_1 * 4) + param_2,uVar6);
LAB_041014a2:
          do {
            iVar9 = *(int *)(iVar3 + param_1 * 4);
            iVar4 = FUN_0410d9e8(2,iVar8,uVar6,1);
            if (iVar4 != 0) {
              uVar7 = 0xffffffff;
LAB_04101542:
              *(undefined4 *)(DAT_041015a8 + param_1 * 4) = 0;
              iVar1 = DAT_041015ac;
              *(undefined4 *)(iVar3 + param_1 * 4) = 0;
              *(undefined4 *)(iVar1 + param_1 * 4) = 0;
              iVar1 = DAT_041015b0;
              *(undefined1 *)(iVar2 + param_1) = 0;
              *(undefined4 *)(iVar1 + param_1 * 4) = 0;
              goto LAB_0410152a;
            }
            do {
              if ((*(char *)(iVar2 + param_1) != '\x01') || (*(char *)(iVar1 + param_1) != '\0'))
              break;
              iVar4 = FUN_04106ed0();
            } while (iVar4 != 0);
            if (*(char *)(iVar1 + param_1) != '\0') {
              uVar7 = 0xfffffff2;
              FUN_0410c858(1,2);
              goto LAB_04101542;
            }
            if ((*(char *)(iVar2 + param_1) != '\x02') ||
               ((*(uint *)(iVar3 + param_1 * 4) < param_3 &&
                ((*(int *)(iVar3 + param_1 * 4) - iVar9 & 0x3fU) != 0)))) {
              uVar7 = 0xfffffffe;
              goto LAB_04101542;
            }
            if (*(uint *)(iVar3 + param_1 * 4) < param_3) goto LAB_04101472;
            uVar7 = 0;
            if (*(char *)(DAT_041015a4 + param_1) == '\0') goto LAB_04101542;
            *(undefined1 *)(DAT_041015a4 + param_1) = 0;
            if (*(uint *)(iVar3 + param_1 * 4) < param_3) goto LAB_0410147a;
LAB_04101506:
            uVar6 = 0;
            *(undefined1 *)(iVar2 + param_1) = 1;
          } while( true );
        }
        uVar7 = 0xfffffffd;
LAB_0410152a:
        FUN_0410714c(iVar5);
      }
      else {
        uVar7 = 0xfffffff7;
      }
    }
  }
  else {
    uVar7 = 0xfffffff2;
  }
  return uVar7;
}



// ===========================================================
// Function: FUN_041015b4 at 041015b4
// ===========================================================

/* WARNING: Removing unreachable block (ram,0x04100b24) */

undefined4 FUN_041015b4(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  undefined4 unaff_lr;
  
  iVar10 = DAT_041015c0;
  *(undefined1 *)(DAT_041015c0 + param_1) = 1;
  puVar4 = DAT_04100c10;
  if (*(char *)(DAT_04100c0c + param_1) == '\0') {
    return 0xfffffff6;
  }
  iVar7 = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    iVar7 = getBasePriority();
  }
  if (iVar7 != 0x40) {
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      setBasePriority(0x40);
    }
    *DAT_04100c10 = 0x4100b16;
    puVar4[1] = unaff_lr;
  }
  iVar11 = DAT_04100c14;
  *(ushort *)(DAT_04100c14 + param_1 * 2) = *(ushort *)(DAT_04100c14 + param_1 * 2) | 4;
  if (iVar7 == 0) {
    *DAT_04100c10 = 0xffffffff;
  }
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    setBasePriority(iVar7);
  }
  iVar8 = DAT_04100c18 + param_1;
  iVar6 = FUN_04107124(iVar8);
  iVar5 = DAT_04100c28;
  iVar7 = DAT_04100c20;
  if (iVar6 != 0) {
    return 0xfffffff7;
  }
  if (*(char *)(DAT_04100c28 + param_1) != '\0') {
    uVar9 = 0xfffffffd;
    goto LAB_04100ba0;
  }
  uVar2 = *(undefined2 *)(iVar11 + param_1 * 2);
  iVar11 = DAT_04100c1c + param_1 * 0x10;
  *(undefined2 *)(DAT_04100c20 + param_1 * 2) = uVar2;
  FUN_0410ef70(iVar11 + 8,iVar7 + param_1 * 2,2,uVar2,iVar10);
  puVar4 = DAT_04100c10;
  iVar10 = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    iVar10 = getBasePriority();
  }
  if (iVar10 == 0x40) {
    if (*(char *)(DAT_04100c24 + param_1) == '\0') {
      *(undefined1 *)(iVar5 + param_1) = 1;
      iVar7 = FUN_0410d9e8(1,iVar11,10);
      if (iVar7 != 0) goto LAB_04100bda;
      uVar9 = 0;
    }
    else {
      uVar9 = 0xfffffff2;
    }
  }
  else {
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      setBasePriority(0x40);
    }
    cVar1 = *(char *)(DAT_04100c24 + param_1);
    *DAT_04100c10 = 0x4100b84;
    puVar4[1] = unaff_lr;
    if (cVar1 == '\0') {
      *(undefined1 *)(iVar5 + param_1) = 1;
      iVar7 = FUN_0410d9e8(1,iVar11,10);
      uVar9 = 0;
      if (iVar7 != 0) {
LAB_04100bda:
        uVar9 = 0xffffffff;
        *(undefined1 *)(iVar5 + param_1) = 0;
      }
    }
    else {
      uVar9 = 0xfffffff2;
    }
    if (iVar10 == 0) {
      *DAT_04100c10 = 0xffffffff;
    }
  }
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    setBasePriority(iVar10);
  }
LAB_04100ba0:
  FUN_0410714c(iVar8);
  return uVar9;
}



// ===========================================================
// Function: FUN_041015c4 at 041015c4
// ===========================================================

void FUN_041015c4(void)

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 in_r3;
  
  FUN_04107a34(0x7000,0xcafe);
  FUN_04107a34(0x7000,0x5fee);
  FUN_0410ad60(9,extraout_r1,extraout_r2,in_r3);
  return;
}



// ===========================================================
// Function: FUN_041015e8 at 041015e8
// ===========================================================

void FUN_041015e8(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  ushort uVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 unaff_lr;
  ushort local_1c;
  ushort local_1a [3];
  
  puVar2 = DAT_04101860;
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04101860 = 0x4101600;
    puVar2[1] = unaff_lr;
  }
  if (param_1 == 0) {
    FUN_04109118(0x4041,DAT_04101868,DAT_04101874);
    pbVar5 = DAT_0410186c;
    FUN_04107a34(0,0xcafe);
    FUN_04107a34(0,0x5fee);
    FUN_0410ad60(9);
    FUN_04107a34(0x7000,0xcafe);
    FUN_04107a34(0x7000,0x5fee);
    FUN_0410ad60(9);
    if (*pbVar5 == 6) goto LAB_04101778;
    if (*pbVar5 == 2) goto LAB_041017c2;
LAB_0410174e:
    FUN_041078bc(0xc,&local_1c);
    if (*pbVar5 == 0) {
      uVar3 = 0x100;
    }
    else {
      uVar3 = 0x400;
    }
    local_1c = uVar3 | local_1c;
    FUN_04107a34(0xc);
  }
  else {
    FUN_04109118(0x4041,DAT_04101868,DAT_04101864);
    pbVar5 = DAT_0410186c;
    FUN_04107a34(0,0xcafe);
    FUN_04107a34(0,0x5fee);
    FUN_0410ad60(9);
    FUN_04107a34(0x7000,0xcafe);
    FUN_04107a34(0x7000,0x5fee);
    FUN_0410ad60(9);
    if (*pbVar5 == 6) {
      FUN_041078bc(6,&local_1c);
      local_1c = local_1c | 0x40;
      FUN_04107a34(6);
      FUN_041078bc(0x21,&local_1c);
      local_1c = local_1c | 0x1c0;
      FUN_04107a34(0x21);
LAB_04101778:
      if (*DAT_04101878 == '\0') {
        FUN_041078bc(0x4e,&local_1c);
        local_1c = local_1c & 0xff80 | 0x15;
        FUN_04107a34(0x4e);
      }
      FUN_0410ad60(0x10);
      if (*pbVar5 == 2) goto LAB_041017c2;
joined_r0x04101792:
      if (param_1 == 0) goto LAB_0410174e;
      if (*pbVar5 == 2) {
        FUN_041078bc(0x11,local_1a);
        local_1a[0] = local_1a[0] & 0xfffe;
        FUN_04107a34(0x11);
      }
    }
    else if (*pbVar5 == 2) {
LAB_041017c2:
      FUN_041078bc(0x61,local_1a);
      local_1a[0] = local_1a[0] & 0xc01f | 0xe0;
      FUN_04107a34(0x61);
      goto joined_r0x04101792;
    }
    FUN_041078bc(5,&local_1c);
    local_1c = local_1c | 0x100;
    FUN_04107a34(5);
    FUN_041078bc(0x44,&local_1c);
    if ((*pbVar5 == 0) || (*pbVar5 == 3)) {
      uVar3 = 0xbfff;
    }
    else {
      uVar3 = 0xff7f;
    }
    local_1c = uVar3 & local_1c;
    FUN_04107a34(0x44);
    FUN_041078bc(0x4f,&local_1c);
    if ((*pbVar5 - 1 < 2) && (*DAT_0410187c != '\0')) {
      local_1c = local_1c | 0x40;
    }
    else {
      local_1c = local_1c | 1;
    }
    iVar4 = 100;
    do {
      FUN_04107a34(0x4f,local_1c);
      FUN_0410ad60(0x50);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_0410ad60(800);
    FUN_04109118(0x4040,DAT_04101870);
    FUN_0410ad60(0x50);
  }
  do {
    FUN_0410aae8();
    FUN_0410ad60(800);
  } while( true );
}



// ===========================================================
// Function: FUN_04101880 at 04101880
// ===========================================================

uint FUN_04101880(void)

{
  ushort uVar1;
  int iVar2;
  ushort local_a [3];
  
  FUN_041078bc(0,local_a);
  if (local_a[0] >> 4 == 0x183) {
    *DAT_04101960 = 0;
  }
  else {
    uVar1 = local_a[0] >> 4;
    if (uVar1 == 0x185) {
      *DAT_04101960 = 1;
    }
    else if (uVar1 == 0x186) {
      *DAT_04101960 = 2;
    }
    else if (uVar1 == 0x188) {
      *DAT_04101960 = 3;
    }
    else if (uVar1 == 0x189) {
      *DAT_04101960 = 4;
    }
    else if (uVar1 == 0x18a) {
      *DAT_04101960 = 5;
    }
    else if (uVar1 == 399) {
      FUN_041078bc(1,local_a);
      if (local_a[0] == 0x650) {
        *DAT_04101960 = 6;
      }
      FUN_041078bc(2,local_a);
      *DAT_04101964 = (byte)local_a[0] & 0xf;
      goto LAB_04101908;
    }
  }
  *DAT_04101964 = (byte)local_a[0] & 0xf;
LAB_04101908:
  iVar2 = FUN_04108994();
  if (iVar2 != 0) {
    return iVar2 + 1;
  }
  FUN_041071ac(0x15,local_a);
  return (uint)((local_a[0] & 3) == 1);
}



// ===========================================================
// Function: FUN_04101968 at 04101968
// ===========================================================

void FUN_04101968(void)

{
  byte *pbVar1;
  char *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  ushort local_12;
  
  pcVar2 = DAT_04101e2c;
  pbVar1 = DAT_04101d40;
  uVar4 = (uint)*DAT_04101d40;
  if (uVar4 - 1 < 2) {
    if (*DAT_04101e2c != '\0') {
      FUN_041078bc(0x102,&local_12);
      local_12 = local_12 & 0xfdff;
      FUN_04107a34(0x102);
      uVar4 = (uint)*pbVar1;
    }
    uVar3 = 0x777;
    local_12 = 0x777;
    if ((uVar4 == 1) && (*pcVar2 == '\0')) {
      uVar3 = 0x8777;
      local_12 = 0x8777;
    }
    FUN_04107a34(0x6c,uVar3);
  }
  FUN_041078bc(0x2c56,&local_12);
  uVar3 = DAT_04101d44;
  local_12 = local_12 & 0xff9f | 0x10;
  FUN_04107a34(0x2c56);
  FUN_041078bc(0x2c44,&local_12);
  local_12 = local_12 & 0xfffd | 4;
  FUN_04107a34(0x2c44);
  FUN_041078bc(0x2c47,&local_12);
  local_12 = local_12 & 0xf806 | 0x800;
  FUN_04107a34(0x2c47);
  FUN_04107a34(0x2c49,0x1400);
  FUN_04107a34(0x2c48,0);
  FUN_041078bc(0x2c57,&local_12);
  local_12 = local_12 & 0xff84 | 0x181e;
  FUN_04107a34(0x2c57);
  FUN_041078bc(0x2c43,&local_12);
  local_12 = 0x303;
  FUN_04107a34(0x2c43);
  FUN_041078bc(0x2c50,&local_12);
  local_12 = local_12 & 0xe000 | 500;
  FUN_04107a34(0x2c50);
  FUN_041078bc(0x2c4e,&local_12);
  local_12 = local_12 | 1;
  FUN_04107a34(0x2c4e);
  FUN_0410ad60(0xa0);
  FUN_041078bc(0x2c4e,&local_12);
  local_12 = local_12 | 2;
  FUN_04107a34(0x2c4e);
  FUN_0410ad60(0xa0);
  FUN_041078bc(0x2c4e,&local_12);
  local_12 = local_12 & 0xfffc;
  FUN_04107a34(0x2c4e);
  FUN_041078bc(0x2c63,&local_12);
  local_12 = local_12 & 0xff9f | 0x10;
  FUN_04107a34(0x2c63);
  FUN_041078bc(0x2c69,&local_12);
  local_12 = local_12 & 0xfffd;
  FUN_04107a34(0x2c69);
  FUN_041078bc(0x2c69,&local_12);
  local_12 = local_12 | 4;
  FUN_04107a34(0x2c69);
  FUN_041078bc(0x2c60,&local_12);
  local_12 = local_12 & 0xf7ff;
  FUN_04107a34(0x2c60);
  FUN_041078bc(0x2c64,&local_12);
  local_12 = local_12 & 0xff87 | 0x20;
  FUN_04107a34(0x2c64);
  FUN_041078bc(0x2c68,&local_12);
  local_12 = 0;
  FUN_04107a34(0x2c68);
  FUN_041078bc(0x2c76,&local_12);
  local_12 = local_12 | 3;
  FUN_04107a34(0x2c76);
  FUN_041078bc(0x2c6d,&local_12);
  local_12 = local_12 | 0x800;
  FUN_04107a34(0x2c6d);
  FUN_04107a34(0x2c6f,0x20c4);
  FUN_04107a34(0x2c6e,0x9ba5);
  FUN_041078bc(0x2c70,&local_12);
  local_12 = local_12 & 0xfffe;
  FUN_04107a34(0x2c70);
  FUN_04107a34(0x2c75,0x19a);
  FUN_041078bc(0x2c73,&local_12);
  local_12 = local_12 | 0x100;
  FUN_04107a34(0x2c73);
  FUN_0410ad60(0xa0);
  FUN_041078bc(0x2c73,&local_12);
  local_12 = local_12 | 0x200;
  FUN_04107a34(0x2c73);
  FUN_0410ad60(0xa0);
  FUN_041078bc(0x2c73,&local_12);
  local_12 = local_12 & 0xfcff;
  FUN_04107a34(0x2c73);
  FUN_041078bc(0x2c2d,&local_12);
  local_12 = local_12 & 0xbfff;
  FUN_04107a34(0x2c2d);
  FUN_041078bc(0x2c0f,&local_12);
  local_12 = local_12 & 0xff00 | 0x11;
  FUN_04107a34(0x2c0f);
  FUN_041078bc(0x2c16,&local_12);
  local_12 = local_12 & 0xc1ff | 0x800;
  FUN_04107a34(0x2c16);
  FUN_041078bc(0x2c1b,&local_12);
  local_12 = local_12 & 0xffe0 | 7;
  FUN_04107a34(0x2c1b);
  FUN_041078bc(0x2c18,&local_12);
  local_12 = local_12 & 0xc7f | 0x4000;
  FUN_04107a34(0x2c18);
  FUN_041078bc(0x2c2b,&local_12);
  local_12 = local_12 & (ushort)uVar3 | 0x444;
  FUN_04107a34(0x2c2b);
  FUN_041078bc(0x2c2a,&local_12);
  local_12 = local_12 & 0xfe00;
  FUN_04107a34(0x2c2a);
  FUN_041078bc(0x2c15,&local_12);
  local_12 = local_12 & 0xfff | 0x4000;
  FUN_04107a34(0x2c15);
  FUN_041078bc(0x2c28,&local_12);
  local_12 = local_12 & (ushort)uVar3 | 0x444;
  FUN_04107a34(0x2c28);
  FUN_041078bc(0x2c0c,&local_12);
  local_12 = local_12 & 0xffe7;
  FUN_04107a34(0x2c0c);
  return;
}



// ===========================================================
// Function: FUN_04101e30 at 04101e30
// ===========================================================

uint FUN_04101e30(void)

{
  undefined2 local_c;
  
  local_c = 0;
  FUN_041071ac(0,&local_c);
  return (local_c._1_1_ & 0xf) >> 3;
}



// ===========================================================
// Function: FUN_04101e58 at 04101e58
// ===========================================================

void FUN_04101e58(void)

{
  return;
}



// ===========================================================
// Function: FUN_04101e5c at 04101e5c
// ===========================================================

void FUN_04101e5c(void)

{
  char *pcVar1;
  undefined4 uVar2;
  ushort local_a;
  
  pcVar1 = DAT_04101ea8;
  if ((*DAT_04101ea8 == '\0') || (*DAT_04101ea8 == '\x03')) {
    uVar2 = 0x6b;
  }
  else {
    uVar2 = 0x10c;
  }
  FUN_041078bc(uVar2,&local_a);
  local_a = local_a & 0xfe7f;
  if ((*pcVar1 != '\0') && (*pcVar1 != '\x03')) {
    FUN_04107a34(0x10c);
    return;
  }
  FUN_04107a34(0x6b);
  return;
}



// ===========================================================
// Function: FUN_04101eac at 04101eac
// ===========================================================

void FUN_04101eac(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined2 uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort local_22;
  ushort local_20;
  ushort local_1e;
  ushort local_1c;
  ushort local_1a;
  
  pbVar2 = DAT_041021b4;
  if (param_1 != 0) {
    return;
  }
  if (*DAT_041021b4 - 4 < 3) {
    FUN_041078bc(0x2c,&local_22);
    local_22 = local_22 & 0xfdff;
    FUN_04107a34(0x2c);
    if (*pbVar2 == 4) {
      FUN_041078bc(0x4d,&local_22);
      uVar11 = (local_22 & 7) + 1;
      if ((local_22 & 7) != 7) {
        do {
          uVar10 = uVar11 & 7;
          uVar11 = uVar11 + 1;
          local_22 = local_22 & 0xfff8 | uVar10;
          FUN_04107a34(0x4d);
        } while (uVar11 != 8);
        FUN_0410ad74(200);
      }
    }
  }
  uVar5 = FUN_0410aa28();
  if ((int)(uVar5 << 0x1f) < 0) {
    *DAT_041021b8 = 2;
LAB_04101ef8:
    uVar11 = local_20;
    uVar10 = local_1e;
    uVar3 = local_1c;
    uVar4 = local_1a;
    if (*pbVar2 - 4 < 3) {
      FUN_041078bc(0x197,&local_1a);
      if (-1 < (int)((uint)local_1a << 0x14)) {
        *DAT_041021c4 = 1;
      }
      local_1a = local_1a | 0x800;
      FUN_04107a34(0x197);
      uVar11 = local_20;
      uVar10 = local_1e;
      uVar3 = local_1c;
      uVar4 = local_1a;
    }
  }
  else {
    if ((uVar5 & 2) != 0) {
      *DAT_041021b8 = 4;
      goto LAB_04101ef8;
    }
    uVar5 = (uint)*pbVar2;
    if (uVar5 - 4 < 3) {
      FUN_041078bc(0x1be,&local_1a);
      uVar5 = (local_1a & 0x3f) >> 3;
      if ((local_1a & 0x38) == 0) {
        uVar5 = local_1a & 7;
        if (uVar5 == 1) {
          *DAT_04102434 = 1;
        }
        else if (uVar5 == 2) {
          *DAT_04102434 = 0x20;
        }
        else if (uVar5 == 3) {
          *DAT_04102434 = 8;
        }
        else if (uVar5 == 4) {
          *DAT_04102434 = 0x10;
        }
        else {
LAB_04101ff6:
          if (*DAT_041021b8 == 0) goto LAB_04101ef8;
        }
      }
      else if (uVar5 == 1) {
        *DAT_04102434 = 0x40;
      }
      else if (uVar5 == 2) {
        *DAT_04102434 = 0x100;
      }
      else if (uVar5 == 3) {
        *DAT_04102434 = 0x200;
      }
      else {
        if (uVar5 != 4) goto LAB_04101ff6;
        *DAT_04102434 = 0x80;
      }
      local_1a = 0xc0;
      FUN_04107a34(0x1be);
      FUN_0410ad74(0x1e);
      FUN_04107a34(0x1be,local_1a);
      goto LAB_04101ef8;
    }
    if (uVar5 == 3) {
      FUN_041078bc(0x78,&local_1a);
      uVar11 = local_1a & 7;
      if ((local_1a & 7) == 0) {
        FUN_041078bc(0x50,&local_1a);
        uVar11 = local_1a & 7;
        if (uVar11 == 1) {
          *DAT_04102434 = 1;
        }
        else if (uVar11 == 2) {
          *DAT_04102434 = 0x20;
        }
        else if (uVar11 == 3) {
          *DAT_04102434 = 8;
        }
        else if (uVar11 == 4) {
          *DAT_04102434 = 0x10;
        }
      }
      else if (uVar11 == 1) {
        *DAT_04102434 = 0x40;
      }
      else if (uVar11 == 2) {
        *DAT_04102434 = 0x200;
      }
      else if (uVar11 == 3) {
        *DAT_04102434 = 0x80;
      }
      else if (uVar11 == 4) {
        *DAT_04102434 = 0x800;
      }
      else if (uVar11 == 5) {
        *DAT_04102434 = 0x400;
      }
      goto LAB_04101ef8;
    }
    uVar11 = 0;
    local_20 = 0;
    local_1e = 0;
    local_1c = 0;
    local_1a = 0;
    uVar10 = uVar11;
    uVar3 = uVar11;
    uVar4 = uVar11;
    if (uVar5 == 2) {
      FUN_041078bc(0x11,&local_20);
      if ((*pbVar2 == 0) || (*pbVar2 == 3)) {
        uVar8 = 0x6b;
      }
      else {
        uVar8 = 0x10c;
      }
      FUN_041078bc(uVar8,&local_1e);
      FUN_041078bc(0x52,&local_1c);
      FUN_041078bc(0x5e,&local_1a);
      uVar5 = (uint)local_20;
      if ((int)(uVar5 << 0x1c) < 0) {
        *DAT_04102434 = 0x100;
      }
      else if ((int)(uVar5 << 0x1f) < 0) {
        if ((local_1e & 0x180) == 0) {
          *DAT_04102434 = 0x80;
        }
        else {
          *DAT_04102434 = 0x40;
        }
      }
      else if ((int)((uint)local_1c << 0x12) < 0) {
        *DAT_04102434 = 0x20;
      }
      else {
        if ((local_1a & 4) == 0) {
          uVar9 = 1;
        }
        else {
          uVar9 = 8;
        }
        *DAT_04102434 = uVar9;
      }
      uVar11 = local_20;
      uVar10 = local_1e;
      uVar3 = local_1c;
      uVar4 = local_1a;
      if (*pbVar2 == 2) {
        local_20 = local_20 & 0xfff3 | 1;
        *DAT_04102438 = (byte)((uVar5 << 0x1d) >> 0x1f);
        FUN_04107a34(0x11);
        uVar11 = local_20;
        uVar10 = local_1e;
        uVar3 = local_1c;
        uVar4 = local_1a;
      }
    }
  }
  local_1a = uVar4;
  local_1c = uVar3;
  local_1e = uVar10;
  local_20 = uVar11;
  FUN_04107a34(0,0xcafe);
  FUN_04107a34(0,0x5fee);
  FUN_0410ad60(9);
  uVar5 = (uint)*pbVar2;
  if (uVar5 - 4 < 3) {
    FUN_041078bc(0x69,&local_22);
    uVar11 = (ushort)DAT_041021bc;
    local_22 = local_22 & uVar11;
    FUN_04107a34(0x69);
    FUN_041078bc(0x84,&local_22);
    local_22 = local_22 & uVar11;
    FUN_04107a34(0x84);
    if (*pbVar2 == 6) {
      FUN_041078bc(6,&local_22);
      local_22 = local_22 | 0x40;
      FUN_04107a34(6);
      FUN_041078bc(0x21,&local_22);
      local_22 = local_22 | 0x1c0;
      FUN_04107a34(0x21);
      if (*DAT_041021c0 == '\0') {
        FUN_041078bc(0x4e,&local_22);
        local_22 = local_22 & 0xff80 | 0x15;
        FUN_04107a34(0x4e);
      }
      FUN_0410ad60(0x10);
      uVar5 = (uint)*pbVar2;
      goto LAB_0410206c;
    }
    if (*pbVar2 == 2) goto LAB_041021c8;
  }
  else {
LAB_0410206c:
    if (uVar5 == 2) {
LAB_041021c8:
      FUN_04107a34(0x12a,0xff);
      FUN_04107a34(0x12f,0xff);
      FUN_04107a34(0x132,0xff);
      FUN_04107a34(0x136,0xff);
      FUN_04107a34(0x139,0xff);
      FUN_04107a34(0x13d,0xff);
      FUN_04107a34(0x140,0xff);
      FUN_04107a34(0x144,0xff0);
      FUN_04107a34(0x129,0);
    }
    else {
      if (uVar5 != 6) goto LAB_04101f8c;
      FUN_04107a34(0xb6,0);
      FUN_04107a34(0xb9,0);
    }
    if (*pbVar2 == 6) {
      FUN_041078bc(0x61,&local_22);
      local_22 = local_22 & 0xff9f;
      FUN_04107a34(0x61);
      FUN_04101e5c();
      FUN_041015c4();
      bVar1 = *pbVar2;
      goto joined_r0x041020b8;
    }
  }
LAB_04101f8c:
  FUN_04101e5c();
  FUN_041015c4();
  bVar1 = *pbVar2;
joined_r0x041020b8:
  if ((bVar1 != 0) && (bVar1 != 3)) {
    FUN_04101968();
    return;
  }
  uVar11 = 0;
  FUN_041080b0();
  while( true ) {
    local_1a = 0x1100;
    iVar6 = FUN_04107a34(0x3f,0x1100);
    if (iVar6 != 0) break;
    local_1a = uVar11 | 0x828;
    iVar6 = FUN_04107a34(0x40);
    if ((iVar6 != 0) || (iVar6 = FUN_041078bc(0x4f,&local_1a), iVar6 != 0)) break;
    local_1a = local_1a & 0xfff | 0xa000;
    iVar6 = FUN_04107a34(0x4f);
    if (iVar6 != 0) break;
    FUN_0410ad60(9);
    iVar6 = FUN_0410ad54();
    do {
      iVar7 = FUN_041078bc(0x4f,&local_1a);
      if ((iVar7 != 0) || (iVar7 = FUN_0410ad54(), 800 < (uint)(iVar7 - iVar6)))
      goto code_r0x04102108;
    } while ((local_1a & 0xc0) != 0x40);
    local_1a = 0x1000;
    iVar6 = FUN_04107a34(0x3f);
    if (iVar6 != 0) break;
    uVar11 = uVar11 + 0x2000;
    if (uVar11 == 0xc000) {
      FUN_041080c0();
      FUN_04101968();
      return;
    }
  }
code_r0x04102108:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ===========================================================
// Function: FUN_04102444 at 04102444
// ===========================================================

undefined4 FUN_04102444(undefined4 param_1,int param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  ushort local_22 [3];
  
  uVar2 = FUN_041026f8();
  uVar2 = uVar2 & 0x30;
  if (param_2 == 0) {
    if (uVar2 == 0) {
      uVar4 = 1;
    }
    else {
      uVar4 = 2;
    }
    local_22[0] = (ushort)param_3;
    FUN_04102d50(param_1,1,1,local_22,uVar4);
    return 0;
  }
  uVar1 = FUN_04102660(param_1);
  if (param_2 - 3U < 2) {
    uVar3 = FUN_04102728(param_1);
    uVar1 = (uVar1 ^ (uVar1 ^ (ushort)param_3) & (ushort)uVar3) & 0xff;
    local_22[0] = uVar1;
    if (uVar2 != 0) {
      uVar2 = FUN_041026ac(param_1);
      uVar2 = (uVar2 ^ (uVar2 ^ param_3 >> 8) & uVar3 >> 8) & 0xff;
      goto LAB_041024c6;
    }
  }
  else {
    local_22[0] = uVar1;
    if (uVar2 != 0) {
      uVar2 = FUN_041026ac(param_1);
      if (param_2 == 1) {
        if (param_3 == 0) {
          uVar2 = uVar2 & 0xfd;
        }
        else {
          uVar2 = uVar2 & 0xff | 2;
        }
LAB_041024c6:
        local_22[0] = uVar1 | (ushort)(uVar2 << 8);
        FUN_04102d50(param_1,1 < param_2 - 2U,1,local_22,2);
        return 0;
      }
      uVar3 = FUN_04102710(param_1);
      if (-1 < (int)(uVar3 << 0x1f)) {
        return 2;
      }
      uVar3 = (uVar3 & 0xffff) >> 8 & 0xc;
      if (uVar3 == 0) {
        if ((param_3 & 0xfffffff8) == 0) {
          uVar2 = uVar2 & 199 | (param_3 & 0x1f) << 3;
          goto LAB_041024c6;
        }
      }
      else if (uVar3 == 4) {
        if (param_3 == 1) {
          uVar2 = uVar2 & 0xff | 4;
          goto LAB_041024c6;
        }
      }
      else if (uVar3 == 8) {
        if ((param_3 & 0xfffffff0) == 0) {
          uVar2 = uVar2 & 0xc3 | (param_3 & 0x3f) << 2;
          goto LAB_041024c6;
        }
      }
      else {
        if (uVar3 != 0xc) {
          return 4;
        }
        if ((param_3 & 0xfffffffc) == 0) {
          uVar2 = uVar2 & 0xcf | (param_3 & 0xf) << 4;
          goto LAB_041024c6;
        }
      }
      return 3;
    }
  }
  FUN_04102d50(param_1,1 < param_2 - 2U,1,local_22,1);
  return 0;
}



// ===========================================================
// Function: FUN_041025a0 at 041025a0
// ===========================================================

void FUN_041025a0(int param_1)

{
  char cVar1;
  
  if (*(int *)(DAT_041025c0 + param_1 * 4) << 0x1f < 0) {
    cVar1 = *(char *)(DAT_041025c4 + param_1);
  }
  else {
    cVar1 = *(char *)(DAT_041025c8 + param_1);
  }
  if (cVar1 == '\0') {
    return;
  }
  FUN_0410df94();
  return;
}



// ===========================================================
// Function: FUN_041025cc at 041025cc
// ===========================================================

void FUN_041025cc(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 == 0) {
    FUN_0410dc50();
    FUN_0410dc24(param_1,*(undefined1 *)
                          (*(int *)(DAT_04102658 + (uint)*(byte *)(DAT_04102654 + param_1) * 4) + 6)
                );
    iVar2 = *(int *)(DAT_0410265c + param_1 * 4);
    if (iVar2 << 0x1a < 0) {
      uVar3 = 0xeb;
    }
    else {
      if (-1 < iVar2 << 0x1c) goto LAB_041025ea;
      uVar3 = 0xbb;
    }
    if (param_1 == 0) {
      uVar1 = 4;
    }
    else {
      uVar1 = 2;
    }
    FUN_0410df34(param_1);
    FUN_0410dd88(param_1,uVar1);
    FUN_0410ddac(param_1,uVar3,0);
    FUN_0410df34(param_1);
    FUN_0410ded4(param_1);
    return;
  }
  FUN_0410dc78();
  FUN_0410dc24(param_1,*(undefined1 *)
                        (*(int *)(DAT_04102658 + (uint)*(byte *)(DAT_04102654 + param_1) * 4) + 5));
LAB_041025ea:
  FUN_0410ded4(param_1);
  return;
}



// ===========================================================
// Function: FUN_04102660 at 04102660
// ===========================================================

undefined1 FUN_04102660(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = DAT_041026a8;
  FUN_0410df04();
  if (*(char *)(iVar1 + param_1) != '\0') {
    FUN_0410e2a4(param_1,0);
  }
  FUN_0410de1c(param_1,5,0,1,param_4);
  FUN_0410de94(param_1,1);
  uVar2 = FUN_0410dd78(param_1);
  if (*(char *)(iVar1 + param_1) == '\0') {
    return uVar2;
  }
  FUN_0410e2a4(param_1,1);
  return uVar2;
}



// ===========================================================
// Function: FUN_041026ac at 041026ac
// ===========================================================

undefined1 FUN_041026ac(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = DAT_041026f4;
  FUN_0410df04();
  if (*(char *)(iVar1 + param_1) != '\0') {
    FUN_0410e2a4(param_1,0);
  }
  FUN_0410de1c(param_1,0x35,0,1,param_4);
  FUN_0410de94(param_1,1);
  uVar2 = FUN_0410dd78(param_1);
  if (*(char *)(iVar1 + param_1) == '\0') {
    return uVar2;
  }
  FUN_0410e2a4(param_1,1);
  return uVar2;
}



// ===========================================================
// Function: FUN_041026f8 at 041026f8
// ===========================================================

undefined4 FUN_041026f8(int param_1)

{
  return *(undefined4 *)
          (*(int *)(DAT_0410270c + (uint)*(byte *)(DAT_04102708 + param_1) * 4) + 0x14);
}



// ===========================================================
// Function: FUN_04102710 at 04102710
// ===========================================================

undefined2 FUN_04102710(int param_1)

{
  return *(undefined2 *)(*(int *)(DAT_04102724 + (uint)*(byte *)(DAT_04102720 + param_1) * 4) + 10);
}



// ===========================================================
// Function: FUN_04102728 at 04102728
// ===========================================================

undefined2 FUN_04102728(int param_1)

{
  return *(undefined2 *)(*(int *)(DAT_0410273c + (uint)*(byte *)(DAT_04102738 + param_1) * 4) + 8);
}



// ===========================================================
// Function: FUN_04102740 at 04102740
// ===========================================================

void FUN_04102740(int param_1,int param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  
  if (param_1 == 0) {
    bVar1 = param_2 != 0;
    *(bool *)DAT_04102774 = bVar1;
    FUN_0410e2a4(0,bVar1);
    *(bool *)DAT_04102778 = param_4 != 0 && bVar1;
    FUN_0410e280(0);
    return;
  }
  return;
}



// ===========================================================
// Function: FUN_0410277c at 0410277c
// ===========================================================

void FUN_0410277c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_0410df04();
  FUN_0410ddac(param_1,0xab,0);
  FUN_0410ad74(0x28);
  FUN_0410e06c(param_1,0);
  FUN_0410e110(param_1,0xeb);
  FUN_0410e210(param_1,0);
  FUN_0410e038(param_1,0);
  FUN_0410e004(param_1,0);
  FUN_0410dc50(param_1);
  FUN_0410ded4(param_1);
  FUN_0410df04(param_1);
  FUN_0410dca0(param_1,DAT_04102838,4);
  FUN_0410dddc(param_1,0xff,4);
  FUN_0410de70(param_1);
  FUN_0410df34(param_1);
  FUN_0410dddc(param_1,0x66,0);
  FUN_0410dddc(param_1,0x99,0);
  FUN_0410ad74(200);
  FUN_0410dddc(param_1,0xe9,0);
  FUN_0410de70(param_1);
  iVar1 = DAT_04102840;
  *(undefined1 *)(DAT_0410283c + param_1) = 0;
  iVar2 = DAT_04102848;
  *(undefined1 *)(DAT_04102844 + param_1) = 0;
  *(undefined1 *)(iVar1 + param_1) = 0;
  iVar3 = DAT_04102850;
  iVar1 = DAT_0410284c;
  *(undefined1 *)(iVar2 + param_1) = 0;
  *(undefined4 *)(iVar3 + param_1 * 4) = 0;
  *(undefined1 *)(iVar1 + param_1) = 0;
  return;
}



// ===========================================================
// Function: FUN_04102854 at 04102854
// ===========================================================

undefined4 FUN_04102854(int param_1,int *param_2)

{
  int iVar1;
  
  if (*(char *)(DAT_04102884 + param_1) == '\0') {
    iVar1 = 1;
  }
  else {
    iVar1 = 2;
  }
  if (param_2 == (int *)0x0) {
    return 0;
  }
  *param_2 = iVar1 * *(int *)(*(int *)(DAT_04102888 + (uint)*(byte *)(DAT_0410288c + param_1) * 4) +
                             0xc);
  return 0;
}



// ===========================================================
// Function: FUN_04102890 at 04102890
// ===========================================================

undefined4 FUN_04102890(int param_1,int *param_2)

{
  int iVar1;
  
  if (*(char *)(DAT_041028a8 + param_1) == '\0') {
    iVar1 = 1;
  }
  else {
    iVar1 = 2;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = iVar1 << 8;
  }
  return 0;
}



// ===========================================================
// Function: FUN_041028ac at 041028ac
// ===========================================================

undefined4 FUN_041028ac(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  uint uVar8;
  
  iVar3 = DAT_04102a4c;
  iVar2 = DAT_04102a48;
  iVar1 = DAT_04102a44;
  uVar6 = *(uint *)(*(int *)(DAT_04102a48 + (uint)*(byte *)(DAT_04102a44 + param_1) * 4) + 0x14);
  param_2 = param_2 & uVar6;
  if ((int)(param_2 << 0x1a) < 0) {
    uVar4 = 0x20;
joined_r0x041028e4:
    if ((int)(param_2 << 0xd) < 0) {
      uVar8 = 0x40000;
      goto LAB_041028ea;
    }
  }
  else {
    if ((int)(param_2 << 0x1b) < 0) {
      uVar4 = 0x10;
      goto joined_r0x041028e4;
    }
    if ((int)(param_2 << 0x1c) < 0) {
      uVar4 = 8;
    }
    else if ((int)(param_2 << 0x1d) < 0) {
      uVar4 = 4;
    }
    else if ((int)(param_2 << 0x1e) < 0) {
      uVar4 = 2;
    }
    else {
      uVar4 = param_2 & 1;
      if (uVar4 == 0) {
        return 1;
      }
    }
    if ((int)(param_2 << 0xd) < 0) {
      return 1;
    }
  }
  if ((int)(param_2 << 0xe) < 0) {
    uVar8 = 0x20000;
  }
  else {
    if (-1 < (int)(param_2 << 0xf)) {
      return 1;
    }
    uVar8 = 0x10000;
  }
LAB_041028ea:
  uVar5 = 0;
  if ((param_2 & 0x28) != 0) {
    uVar5 = param_2 & 0x1000;
  }
  uVar5 = uVar8 | uVar4 | uVar5;
  if (*(uint *)(DAT_04102a4c + param_1 * 4) != uVar5) {
    if (((uVar6 & 0x28) != 0) && ((int)(uVar6 << 0x13) < 0)) {
      FUN_041025cc(param_1,0);
    }
    FUN_0410e038(param_1,0);
    FUN_0410e004(param_1,0);
    if ((int)(uVar4 << 0x1a) < 0) {
      pcVar7 = *(code **)(*(int *)(iVar2 + (uint)*(byte *)(iVar1 + param_1) * 4) + 0x18);
      if (pcVar7 != (code *)0x0) {
        (*pcVar7)(param_1,1);
      }
      FUN_0410e038(param_1,1);
      FUN_0410ded4(param_1);
      if (*(int *)(*(int *)(iVar2 + (uint)*(byte *)(iVar1 + param_1) * 4) + 0x14) << 2 < 0) {
        FUN_0410e244(param_1,8);
      }
    }
    else if ((int)(uVar4 << 0x1b) < 0) {
      pcVar7 = *(code **)(*(int *)(iVar2 + (uint)*(byte *)(iVar1 + param_1) * 4) + 0x18);
      if (pcVar7 != (code *)0x0) {
        (*pcVar7)(param_1,1);
      }
      FUN_0410e0f4(param_1,0x6b);
      FUN_0410ded4(param_1);
    }
    else if ((int)(uVar4 << 0x1c) < 0) {
      FUN_0410e004(param_1,1);
      FUN_0410ded4(param_1);
    }
    else if ((int)(uVar4 << 0x1d) < 0) {
      FUN_0410e0f4(param_1,0x3b);
      FUN_0410ded4(param_1);
    }
    else if ((int)(uVar4 << 0x1e) < 0) {
      FUN_0410e0f4(param_1,0xb);
      FUN_0410ded4(param_1);
    }
    else if ((int)(uVar4 << 0x1f) < 0) {
      FUN_0410e0f4(param_1,3);
      FUN_0410ded4(param_1);
    }
    FUN_0410e314(param_1,0);
    if ((int)(uVar5 << 0x13) < 0) {
      FUN_0410dc78(param_1);
      FUN_0410dc24(param_1,*(undefined1 *)
                            (*(int *)(iVar2 + (uint)*(byte *)(iVar1 + param_1) * 4) + 5));
      FUN_0410ded4(param_1);
    }
    *(uint *)(iVar3 + param_1 * 4) = uVar5;
  }
  FUN_0410de70(param_1);
  FUN_041025a0(param_1);
  return 0;
}



// ===========================================================
// Function: FUN_04102a50 at 04102a50
// ===========================================================

undefined4 FUN_04102a50(int param_1)

{
  FUN_0410ded4();
  if ((*(char *)(DAT_04102a98 + param_1) != '\0') && (*(char *)(DAT_04102a9c + param_1) == '\0')) {
    FUN_0410e280(param_1,1);
  }
  if (*(char *)(DAT_04102aa0 + param_1) != '\0') {
    FUN_0410df94(param_1);
  }
  if (-1 < *(int *)(DAT_04102aa4 + param_1 * 4) << 0x13) {
    return 0;
  }
  FUN_041025cc(param_1,0);
  return 0;
}



// ===========================================================
// Function: FUN_04102aa8 at 04102aa8
// ===========================================================

void FUN_04102aa8(undefined4 param_1)

{
  FUN_04102a50(param_1,0);
  return;
}



// ===========================================================
// Function: FUN_04102ab0 at 04102ab0
// ===========================================================

undefined4 FUN_04102ab0(int param_1)

{
  FUN_0410ded4();
  if (*(int *)(DAT_04102b08 + param_1 * 4) << 0x13 < 0) {
    FUN_0410dc78(param_1);
    FUN_0410dc24(param_1,*(undefined1 *)
                          (*(int *)(DAT_04102b18 + (uint)*(byte *)(DAT_04102b14 + param_1) * 4) + 5)
                );
    FUN_0410ded4(param_1);
  }
  FUN_0410de70(param_1);
  FUN_041025a0(param_1);
  if (*(char *)(DAT_04102b0c + param_1) != '\0') {
    if (*(char *)(DAT_04102b10 + param_1) == '\0') {
      FUN_0410e280(param_1);
      return 0;
    }
  }
  return 0;
}



// ===========================================================
// Function: FUN_04102b1c at 04102b1c
// ===========================================================

void FUN_04102b1c(undefined4 param_1)

{
  FUN_04102ab0(param_1,0);
  return;
}



// ===========================================================
// Function: FUN_04102b24 at 04102b24
// ===========================================================

undefined4 FUN_04102b24(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  
  iVar1 = DAT_04102b88;
  FUN_0410df04();
  if (*(char *)(iVar1 + param_1) != '\0') {
    FUN_0410e2a4(param_1,0);
  }
  FUN_0410de1c(param_1,param_2,0,param_4);
  FUN_0410de94(param_1,param_4 & 0xff);
  if (param_4 != 0) {
    puVar3 = (undefined1 *)(param_3 + -1);
    do {
      uVar2 = FUN_0410dd78(param_1);
      puVar3 = puVar3 + 1;
      *puVar3 = uVar2;
    } while (puVar3 != (undefined1 *)(param_4 + param_3 + -1));
  }
  if (*(char *)(iVar1 + param_1) == '\0') {
    return 0;
  }
  FUN_0410e2a4(param_1,1);
  return 0;
}



// ===========================================================
// Function: FUN_04102b8c at 04102b8c
// ===========================================================

undefined4
FUN_04102b8c(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  
  iVar1 = DAT_04102c0c;
  FUN_0410df04();
  if (*(char *)(iVar1 + param_1) != '\0') {
    FUN_0410e2a4(param_1,0);
  }
  if ((param_3 == 0) || (param_4 == 0)) {
    param_4 = 0;
  }
  else {
    FUN_0410dca0(param_1,param_3,param_4);
  }
  FUN_0410de1c(param_1,param_2,param_4,param_6);
  if (param_6 != 0) {
    puVar3 = (undefined1 *)(param_5 + -1);
    do {
      FUN_0410deb8(param_1);
      uVar2 = FUN_0410dd78(param_1);
      puVar3 = puVar3 + 1;
      *puVar3 = uVar2;
    } while (puVar3 != (undefined1 *)(param_6 + param_5 + -1));
  }
  if (*(char *)(iVar1 + param_1) == '\0') {
    return 0;
  }
  FUN_0410e2a4(param_1,1);
  return 0;
}



// ===========================================================
// Function: FUN_04102c10 at 04102c10
// ===========================================================

undefined4
FUN_04102c10(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte local_24 [4];
  
  param_7 = param_7 * 2;
  FUN_0410df04();
  if ((param_3 == 0) || (param_4 == 0)) {
    param_4 = 0;
  }
  else {
    FUN_0410dca0(param_1,param_3,param_4);
  }
  FUN_0410de1c(param_1,param_2,param_4,param_7);
  if (param_7 != 0) {
    iVar2 = 0;
    iVar3 = 1;
    FUN_0410deb8(param_1);
    iVar4 = 0;
    local_24[0] = FUN_0410dd78(param_1);
    while (iVar2 = iVar2 + 1, iVar2 != param_7) {
      while( true ) {
        FUN_0410deb8(param_1);
        bVar1 = FUN_0410dd78(param_1);
        local_24[iVar3] = bVar1;
        if (iVar3 != 0) break;
        iVar2 = iVar2 + 1;
        iVar3 = 1;
        if (iVar2 == param_7) {
          return 0;
        }
      }
      iVar3 = 0;
      *(byte *)(param_5 + iVar4) = local_24[1] & 0xf | local_24[0] << 4;
      *(byte *)(param_6 + iVar4) = local_24[1] >> 4 | (local_24[0] >> 4) << 4;
      iVar4 = iVar4 + 1;
      local_24[0] = local_24[0] >> 4;
      local_24[1] = local_24[1] >> 4;
    }
  }
  return 0;
}



// ===========================================================
// Function: FUN_04102cc4 at 04102cc4
// ===========================================================

undefined4 FUN_04102cc4(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte local_1a;
  byte local_19 [5];
  
  iVar1 = DAT_04102d4c;
  do {
    if (*(char *)(iVar1 + param_1) == '\0') {
      FUN_0410df04();
      if (*(char *)(iVar1 + param_1) != '\0') {
        FUN_0410e2a4(param_1,0);
      }
      FUN_0410de1c(param_1,5,0,1);
      FUN_0410de94(param_1,1);
      uVar3 = FUN_0410dd78(param_1);
      uVar4 = uVar3 & 0xff;
      if (*(char *)(iVar1 + param_1) != '\0') {
        FUN_0410e2a4(param_1,1);
        uVar4 = uVar3;
      }
    }
    else {
      FUN_04102c10(param_1,5,0,0,&local_1a,local_19,1);
      uVar4 = (uint)(local_1a | local_19[0]);
    }
  } while (((int)(uVar4 << 0x1f) < 0) && (iVar2 = FUN_04106ed0(), iVar2 != 0));
  return 0;
}



// ===========================================================
// Function: FUN_04102d50 at 04102d50
// ===========================================================

undefined4
FUN_04102d50(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  if (param_2 == 0) {
    FUN_0410ddac(param_1,6,0,param_4,param_4);
  }
  else {
    FUN_0410dddc(param_1,0x50,0);
  }
  FUN_0410df64(param_1);
  FUN_0410dca0(param_1,param_4,param_5);
  FUN_0410dddc(param_1,param_3,param_5);
  FUN_04102cc4(param_1,0);
  return 0;
}



// ===========================================================
// Function: FUN_04102d94 at 04102d94
// ===========================================================

undefined4 FUN_04102d94(undefined4 param_1,undefined4 param_2,uint param_3)

{
  FUN_04102a50(param_1,0);
  if (2 < param_3) {
    param_3 = 3;
  }
  FUN_04102b24(param_1,0x9f,param_2,param_3);
  FUN_04102ab0(param_1,0);
  return 0;
}



// ===========================================================
// Function: FUN_04102dcc at 04102dcc
// ===========================================================

undefined4 FUN_04102dcc(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  FUN_04102a50(param_1,0);
  if (2 < param_4) {
    param_4 = 3;
  }
  FUN_04102c10(param_1,0x9f,0,0,param_2,param_3,param_4);
  FUN_04102ab0(param_1,0);
  return 0;
}



// ===========================================================
// Function: FUN_04102e0c at 04102e0c
// ===========================================================

void FUN_04102e0c(int param_1,undefined1 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = **(char **)(DAT_04102e5c + (uint)*(byte *)(DAT_04102e58 + param_1) * 4);
  if (cVar1 == '\v') {
    *param_4 = 0x10;
    *param_3 = 0x19400;
    *param_2 = 0x5a;
    return;
  }
  if (cVar1 == ' ') {
LAB_04102e32:
    uVar2 = 8;
  }
  else {
    if (cVar1 != '^') {
      if (cVar1 == -0x11) goto LAB_04102e32;
      if (cVar1 != -0x7b) {
        uVar2 = 0x12;
        goto LAB_04102e34;
      }
    }
    uVar2 = 0x10;
  }
LAB_04102e34:
  *param_4 = uVar2;
  *param_3 = 0;
  *param_2 = 0x4b;
  return;
}



// ===========================================================
// Function: FUN_04102e60 at 04102e60
// ===========================================================

undefined4 FUN_04102e60(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined1 local_19;
  undefined1 auStack_18 [4];
  uint local_14;
  
  FUN_04102e0c(param_1,&local_19,auStack_18,&local_14);
  if (local_14 <= param_3) {
    param_3 = local_14;
  }
  FUN_04102a50(param_1,0);
  FUN_04102b8c(param_1,local_19,auStack_18,4,param_2,param_3);
  FUN_04102ab0(param_1,0);
  return 0;
}



// ===========================================================
// Function: FUN_04102ea8 at 04102ea8
// ===========================================================

undefined4 FUN_04102ea8(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined1 local_21;
  undefined1 auStack_20 [4];
  uint local_1c [2];
  
  FUN_04102e0c(param_1,&local_21,auStack_20,local_1c);
  if (local_1c[0] <= param_4) {
    param_4 = local_1c[0];
  }
  FUN_04102a50(param_1,0);
  FUN_04102c10(param_1,local_21,auStack_20,4,param_2,param_3,param_4);
  FUN_04102ab0(param_1,0);
  return 0;
}



// ===========================================================
// Function: FUN_04102ef4 at 04102ef4
// ===========================================================

void FUN_04102ef4(undefined4 param_1)

{
  FUN_0410df64();
  FUN_0410dddc(param_1,0xb7,0);
  FUN_0410de70(param_1);
  FUN_0410e06c(param_1,1);
  return;
}



// ===========================================================
// Function: FUN_04102f18 at 04102f18
// ===========================================================

void FUN_04102f18(undefined4 param_1)

{
  FUN_0410df64();
  FUN_0410dddc(param_1,0xe9,0);
  FUN_0410de70(param_1);
  FUN_0410e06c(param_1,0);
  return;
}



// ===========================================================
// Function: FUN_04102f3c at 04102f3c
// ===========================================================

void FUN_04102f3c(int param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  *(char *)(DAT_04102f74 + param_1) = (char)param_2;
  iVar2 = FUN_0410dfc4();
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      uVar4 = 4;
      iVar2 = DAT_04102f7c;
    }
    else {
      uVar4 = 0xb;
      iVar2 = DAT_04102f78;
    }
    if (param_2 < uVar4) {
      FUN_0410dfd8(param_1,*(undefined1 *)(iVar2 + param_2));
      bVar1 = *(byte *)(iVar2 + param_2);
      iVar2 = *(int *)(DAT_0410e310 + param_1 * 4);
      do {
        if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) break;
        iVar3 = FUN_04106ed0();
      } while (iVar3 != 0);
      *(uint *)(iVar2 + 0x204) = (bVar1 & 0xf) << 1 | *(uint *)(iVar2 + 0x204) & 0xffffffe1;
      return;
    }
  }
  return;
}



// ===========================================================
// Function: FUN_04102f80 at 04102f80
// ===========================================================

undefined4 FUN_04102f80(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char acStack_2c [3];
  char acStack_29 [5];
  
  if (2 < param_2) {
    return 1;
  }
  iVar2 = FUN_0410dfc4();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  uVar8 = 0;
  if (iVar2 == 1) {
    uVar3 = 4;
  }
  else {
    uVar3 = 0xb;
  }
  uVar7 = 0;
  uVar6 = 0;
  do {
    FUN_0410ded4(param_1);
    FUN_04102f3c(param_1,uVar6);
    if (param_2 != 0) {
      return 0xfffffffd;
    }
    pcVar9 = *(char **)(DAT_041030d0 + (uint)*(byte *)(DAT_041030cc + param_1) * 4);
    FUN_0410df04(param_1);
    if (*(char *)(DAT_041030d4 + param_1) != '\0') {
      FUN_0410e2a4(param_1,0);
    }
    FUN_0410de1c(param_1,0x9f,0,3);
    FUN_0410de94(param_1,3);
    pcVar4 = acStack_2c;
    do {
      cVar1 = FUN_0410dd78(param_1);
      pcVar5 = pcVar4 + 1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar5;
    } while (pcVar5 != acStack_29);
    if (*(char *)(DAT_041030d4 + param_1) != '\0') {
      FUN_0410e2a4(param_1,1);
    }
    if (((acStack_2c[0] == *pcVar9) && (acStack_2c[1] == pcVar9[1])) && (acStack_2c[2] == pcVar9[2])
       ) {
      if (uVar7 == 0) {
        uVar8 = uVar6;
      }
      uVar7 = uVar7 + 1;
    }
    else if (uVar7 != 0) goto LAB_0410307a;
    uVar6 = uVar6 + 1;
  } while (uVar3 != uVar6);
  if (uVar7 == 0) {
    return 1;
  }
LAB_0410307a:
  if (uVar7 == 2) {
    if (iVar2 == 1) {
      uVar3 = 1;
      if (uVar8 < 2) goto LAB_04103084;
    }
    else {
      if (iVar2 == 2) {
        if (*(char *)(DAT_041030d8 + param_1) == '\0') {
          uVar3 = 3;
        }
        else {
          uVar3 = 4;
        }
      }
      else {
        uVar3 = 5;
      }
      if ((uVar8 <= uVar3) && (uVar3 < uVar8 + 2)) goto LAB_04103084;
    }
    uVar3 = uVar8 + 1;
  }
  else {
    uVar3 = uVar8 + (uVar7 >> 1);
  }
LAB_04103084:
  FUN_04102f3c(param_1,uVar3);
  return 0;
}



// ===========================================================
// Function: FUN_04102f88 at 04102f88
// ===========================================================

undefined4 FUN_04102f88(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char local_2c [3];
  char acStack_29 [5];
  
  iVar2 = FUN_0410dfc4();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  uVar8 = 0;
  if (iVar2 == 1) {
    uVar3 = 4;
  }
  else {
    uVar3 = 0xb;
  }
  uVar7 = 0;
  uVar6 = 0;
  do {
    FUN_0410ded4(param_1);
    FUN_04102f3c(param_1,uVar6);
    if (param_2 != 0) {
      return 0xfffffffd;
    }
    pcVar9 = *(char **)(DAT_041030d0 + (uint)*(byte *)(DAT_041030cc + param_1) * 4);
    FUN_0410df04(param_1);
    if (*(char *)(DAT_041030d4 + param_1) != '\0') {
      FUN_0410e2a4(param_1,0);
    }
    FUN_0410de1c(param_1,0x9f,0,3);
    FUN_0410de94(param_1,3);
    pcVar4 = local_2c;
    do {
      cVar1 = FUN_0410dd78(param_1);
      pcVar5 = pcVar4 + 1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar5;
    } while (pcVar5 != acStack_29);
    if (*(char *)(DAT_041030d4 + param_1) != '\0') {
      FUN_0410e2a4(param_1,1);
    }
    if (((local_2c[0] == *pcVar9) && (local_2c[1] == pcVar9[1])) && (local_2c[2] == pcVar9[2])) {
      if (uVar7 == 0) {
        uVar8 = uVar6;
      }
      uVar7 = uVar7 + 1;
    }
    else if (uVar7 != 0) goto LAB_0410307a;
    uVar6 = uVar6 + 1;
  } while (uVar3 != uVar6);
  if (uVar7 == 0) {
    return 1;
  }
LAB_0410307a:
  if (uVar7 == 2) {
    if (iVar2 == 1) {
      uVar3 = 1;
      if (uVar8 < 2) goto LAB_04103084;
    }
    else {
      if (iVar2 == 2) {
        if (*(char *)(DAT_041030d8 + param_1) == '\0') {
          uVar3 = 3;
        }
        else {
          uVar3 = 4;
        }
      }
      else {
        uVar3 = 5;
      }
      if ((uVar8 <= uVar3) && (uVar3 < uVar8 + 2)) goto LAB_04103084;
    }
    uVar3 = uVar8 + 1;
  }
  else {
    uVar3 = uVar8 + (uVar7 >> 1);
  }
LAB_04103084:
  FUN_04102f3c(param_1,uVar3);
  return 0;
}



// ===========================================================
// Function: FUN_041030dc at 041030dc
// ===========================================================

undefined4 FUN_041030dc(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = 1;
    if (param_2 != 1) {
      if (param_2 == 2) {
        if (*(char *)(DAT_04103120 + param_1) == '\0') {
          uVar1 = 3;
        }
        else {
          uVar1 = 4;
        }
      }
      else {
        uVar1 = 4;
      }
    }
    FUN_0410dfd8(param_1,uVar1);
    FUN_0410e34c(param_1,0xffffffff);
    FUN_0410ad74(2);
    return 0;
  }
  return 0xffffffff;
}



// ===========================================================
// Function: FUN_04103124 at 04103124
// ===========================================================

undefined4 FUN_04103124(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  iVar3 = DAT_0410323c;
  iVar2 = DAT_0410322c;
  uVar1 = DAT_04103228;
  uVar4 = *param_2;
  uVar7 = DAT_04103238;
  uVar8 = DAT_04103234;
  if (uVar4 != DAT_04103214) {
    uVar7 = uVar4;
    uVar8 = uVar4 - 1;
  }
  iVar5 = *(int *)(DAT_0410321c + (uint)*(byte *)(DAT_04103218 + param_1) * 4);
  uVar4 = *(uint *)(iVar5 + 0x10);
  if (uVar4 == 0) {
    uVar4 = DAT_04103220;
  }
  uVar6 = (uint)*(byte *)(iVar5 + 3);
  uVar10 = param_2[1];
  if (uVar7 <= param_2[1]) {
    uVar10 = uVar7;
  }
  if (uVar4 <= uVar10) {
    uVar10 = uVar4;
  }
  uVar11 = (uVar6 & 7) * uVar4 + uVar4 >> 3;
  uVar7 = ((uVar6 & 0x3f) >> 3) * uVar4 + uVar4 >> 3;
  if (uVar10 <= uVar11) {
    uVar11 = uVar10;
  }
  if (uVar10 <= uVar7) {
    uVar7 = uVar10;
  }
  uVar6 = (uVar10 + uVar8) / uVar10;
  uVar4 = uVar6;
  if (0xfe < uVar6) {
    uVar4 = 0xff;
  }
  *(char *)(DAT_04103224 + param_1) = (char)uVar4;
  uVar4 = (uVar11 + uVar8) / uVar11;
  if (0xfe < uVar4) {
    uVar4 = 0xff;
  }
  uVar9 = (uVar7 + uVar8) / uVar7;
  *(char *)(iVar3 + param_1) = (char)uVar4;
  if (0xfe < uVar9) {
    uVar9 = 0xff;
  }
  *(char *)(iVar2 + param_1) = (char)uVar9;
  if ((uVar1 < uVar10) && (uVar6 == 2)) {
    *(undefined1 *)(DAT_04103230 + param_1) = 1;
  }
  else {
    *(undefined1 *)(DAT_04103230 + param_1) = 0;
    if (CARRY4(uVar10,uVar8)) {
      return 1;
    }
  }
  if ((!CARRY4(uVar7,uVar8)) && (!CARRY4(uVar11,uVar8))) {
    FUN_041030dc(param_1);
    FUN_0410df94(param_1,*(undefined1 *)(iVar2 + param_1));
    return 0;
  }
  return 1;
}



// ===========================================================
// Function: FUN_04103240 at 04103240
// ===========================================================

undefined4 FUN_04103240(int param_1,char *param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = DAT_04103288;
  *(undefined1 *)(DAT_04103288 + param_1) = 0x28;
  if (param_3 == 3) {
    iVar3 = 0;
    pcVar2 = DAT_04103290;
    puVar4 = DAT_0410328c;
    while( true ) {
      if (((*pcVar2 == *param_2) && (param_2[1] == pcVar2[1])) && (param_2[2] == pcVar2[2])) {
        *(char *)(iVar1 + param_1) = (char)iVar3;
        return 1;
      }
      iVar3 = iVar3 + 1;
      if (iVar3 == 0x28) break;
      puVar4 = puVar4 + 1;
      pcVar2 = (char *)*puVar4;
    }
  }
  return 0;
}



// ===========================================================
// Function: FUN_04103294 at 04103294
// ===========================================================

undefined4 FUN_04103294(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  code *pcVar5;
  undefined4 uVar6;
  
  iVar2 = DAT_041033bc;
  iVar4 = DAT_041033b4;
  if (param_3 == 1) {
    uVar6 = 0x20;
  }
  else if (param_3 == 2) {
    uVar6 = 0x52;
  }
  else if (param_3 == 3) {
    uVar6 = 0xd8;
  }
  else {
    if (param_3 != 4) {
      return 0xf;
    }
    uVar6 = 0x60;
  }
  iVar1 = *(int *)(DAT_041033b4 + (uint)*(byte *)(DAT_041033bc + param_1) * 4);
  if (*(int *)(iVar1 + 0x14) << 0xc < 0) {
    uVar3 = *(uint *)(DAT_041033b8 + param_1 * 4);
    if ((uVar3 & 0x20) == 0) {
      if ((int)(uVar3 << 0x1b) < 0) {
        if (*(code **)(iVar1 + 0x18) != (code *)0x0) {
          (**(code **)(iVar1 + 0x18))(param_1,1);
        }
        FUN_0410e0f4(param_1,3);
        FUN_0410ded4(param_1);
      }
    }
    else {
      pcVar5 = *(code **)(iVar1 + 0x18);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)(param_1,1,0,pcVar5,param_4);
      }
      FUN_0410e038(param_1,0);
      FUN_0410ded4(param_1);
    }
  }
  FUN_0410ddac(param_1,6,0);
  FUN_0410e08c(param_1,param_2);
  FUN_0410ddac(param_1,uVar6,param_2);
  FUN_0410ded4(param_1);
  uVar6 = FUN_04102cc4(param_1,param_4);
  iVar4 = *(int *)(iVar4 + (uint)*(byte *)(iVar2 + param_1) * 4);
  if (*(int *)(iVar4 + 0x14) << 0xc < 0) {
    iVar2 = *(int *)(DAT_041033b8 + param_1 * 4);
    if (iVar2 << 0x1a < 0) {
      if (*(code **)(iVar4 + 0x18) != (code *)0x0) {
        (**(code **)(iVar4 + 0x18))(param_1,1);
      }
      FUN_0410e038(param_1,1);
      FUN_0410ded4(param_1);
    }
    else if (iVar2 << 0x1b < 0) {
      if (*(code **)(iVar4 + 0x18) != (code *)0x0) {
        (**(code **)(iVar4 + 0x18))(param_1,1);
      }
      FUN_0410e0f4(param_1,0x6b);
      FUN_0410ded4(param_1);
    }
  }
  FUN_0410de70(param_1);
  return uVar6;
}



// ===========================================================
// Function: FUN_041033c0 at 041033c0
// ===========================================================

undefined4 FUN_041033c0(int param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*(char *)(DAT_0410346c + param_1) == '\0') {
    uVar2 = 0x100;
  }
  else {
    uVar2 = 0x200;
  }
  if (uVar2 < param_4) {
    return 2;
  }
  uVar2 = *(uint *)(DAT_04103470 + param_1 * 4);
  if ((int)(uVar2 << 0xd) < 0) {
    uVar3 = 0x32;
  }
  else if ((uVar2 & 0x20000) == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = 0xa2;
  }
  FUN_0410df64(param_1);
  uVar2 = FUN_0410dcfc(param_1,param_3,param_4);
  FUN_0410ddac(param_1,6,0);
  FUN_0410e08c(param_1,param_2);
  FUN_0410ddac(param_1,uVar3,param_2);
  while (uVar1 = uVar2, uVar1 != 0) {
    param_3 = param_3 + (param_4 - uVar1);
    uVar2 = FUN_0410dd44(param_1,param_3,uVar1);
    param_4 = uVar1;
  }
  FUN_0410ded4(param_1);
  uVar3 = FUN_04102cc4(param_1,param_5);
  FUN_0410de70(param_1);
  return uVar3;
}



// ===========================================================
// Function: FUN_04103474 at 04103474
// ===========================================================

undefined4 FUN_04103474(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(int *)(DAT_0410349c + (uint)*(byte *)(DAT_04103498 + param_1) * 4) + 0x18);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_1,4,param_2,pcVar1,param_4);
    return 0;
  }
  return 0xffffffff;
}



// ===========================================================
// Function: FUN_041034a0 at 041034a0
// ===========================================================

undefined4 FUN_041034a0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  
  iVar3 = DAT_04103500;
  iVar2 = DAT_041034fc;
  iVar1 = DAT_041034f8;
  pcVar5 = *(code **)(*(int *)(DAT_041034f8 + (uint)*(byte *)(DAT_04103500 + param_1) * 4) + 0x18);
  if (pcVar5 == (code *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    if (*(char *)(DAT_041034fc + param_1) != '\0') {
      FUN_0410e2a4(param_1,0);
      pcVar5 = *(code **)(*(int *)(iVar1 + (uint)*(byte *)(iVar3 + param_1) * 4) + 0x18);
    }
    (*pcVar5)(param_1,2,param_2);
    uVar4 = 0;
    if (*(char *)(iVar2 + param_1) != '\0') {
      FUN_0410e2a4(param_1,1);
      return 0;
    }
  }
  return uVar4;
}



// ===========================================================
// Function: FUN_04103504 at 04103504
// ===========================================================

undefined4 FUN_04103504(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_04103550;
  if (*(char *)(DAT_04103550 + param_1) != '\0') {
    FUN_0410e2a4(param_1,0);
  }
  FUN_0410ddac(param_1,6,0);
  FUN_0410ddac(param_1,0x44,param_2);
  uVar2 = FUN_04102cc4(param_1,0);
  FUN_0410de70(param_1);
  if (*(char *)(iVar1 + param_1) == '\0') {
    return uVar2;
  }
  FUN_0410e2a4(param_1,1);
  return uVar2;
}



// ===========================================================
// Function: FUN_04103554 at 04103554
// ===========================================================

undefined4 FUN_04103554(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = DAT_041035e4;
  if (*(char *)(DAT_041035e4 + param_1) != '\0') {
    FUN_0410e2a4(param_1,0,param_3,*(char *)(DAT_041035e4 + param_1),param_4);
  }
  FUN_0410df64(param_1);
  iVar3 = FUN_0410dcfc(param_1,param_3,param_4);
  FUN_0410ddac(param_1,6,0);
  FUN_0410ddac(param_1,0x42,param_2);
  while (iVar1 = iVar3, iVar1 != 0) {
    param_3 = param_3 + (param_4 - iVar1);
    iVar3 = FUN_0410dd44(param_1,param_3,iVar1);
    param_4 = iVar1;
  }
  FUN_0410ded4(param_1);
  uVar4 = FUN_04102cc4(param_1,0);
  FUN_0410de70(param_1);
  if (*(char *)(iVar2 + param_1) == '\0') {
    return uVar4;
  }
  FUN_0410e2a4(param_1,1);
  return uVar4;
}



// ===========================================================
// Function: FUN_041035e8 at 041035e8
// ===========================================================

undefined4 FUN_041035e8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(DAT_04103634 + param_1 * 4);
  iVar1 = FUN_041028ac(param_1,0x10001);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410363c);
  }
  FUN_0410ded4(param_1);
  FUN_0410df34(param_1);
  FUN_0410ded4(param_1);
  FUN_0410e0f4(param_1,0x48);
  if (*(char *)(DAT_04103638 + param_1) == '\0') {
    return uVar2;
  }
  FUN_0410e2a4(param_1,0);
  return uVar2;
}



// ===========================================================
// Function: FUN_04103640 at 04103640
// ===========================================================

void FUN_04103640(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (*(char *)(DAT_04103680 + param_1) != '\0') {
    FUN_0410e2a4(param_1,1,param_3,*(char *)(DAT_04103680 + param_1),param_4);
  }
  FUN_0410ded4(param_1);
  FUN_0410df34(param_1);
  FUN_0410ded4(param_1);
  FUN_0410e0f4(param_1,3);
  iVar1 = FUN_041028ac(param_1,param_2);
  if (iVar1 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_04103684);
}



// ===========================================================
// Function: FUN_041037e8 at 041037e8
// ===========================================================

void FUN_041037e8(void)

{
                    /* WARNING: Could not recover jumptable at 0x041037ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_041037f0 + 4))();
  return;
}



// ===========================================================
// Function: FUN_041037f4 at 041037f4
// ===========================================================

void FUN_041037f4(void)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined1 *puVar11;
  char *pcVar12;
  int iVar13;
  undefined4 unaff_lr;
  
  puVar2 = DAT_04103940;
  iVar13 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar13 = getBasePriority();
  }
  if (iVar13 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04103940 = 0x410380e;
    puVar2[1] = unaff_lr;
  }
  uVar10 = DAT_04103954;
  iVar8 = DAT_04103944;
  if (*(int *)(DAT_04103944 + 0x130) != 0) {
    uVar6 = FUN_0410ae28();
    puVar11 = *(undefined1 **)(iVar8 + 0x130);
    uVar9 = *(uint *)(puVar11 + 8);
    if (uVar6 + 1 < uVar9) {
      uVar6 = thunk_FUN_0410ae28();
      puVar11 = *(undefined1 **)(iVar8 + 0x130);
      uVar9 = *(uint *)(puVar11 + 8);
      if (uVar6 + 1 < uVar9) {
        iVar8 = *DAT_04103948;
        *DAT_04103948 = iVar8 + 1;
        FUN_04109118(0x44,DAT_0410394c,uVar9,uVar6,1,iVar8 + 1);
        goto LAB_041038e0;
      }
    }
    *puVar11 = 3;
    uVar7 = uVar6;
    if (uVar9 < uVar6) {
      uVar7 = uVar6 - uVar9;
    }
    if (uVar6 <= uVar9) {
      uVar7 = 0;
    }
    puVar5 = *(undefined1 **)(*(int *)(iVar8 + 0x130) + 4);
    while (puVar3 = puVar5, puVar3 != (undefined1 *)0x0) {
      if (uVar7 < *(uint *)(puVar3 + 8)) {
        *(undefined4 *)(puVar11 + 4) = 0;
        uVar10 = *(undefined4 *)(iVar8 + 0x130);
        *(undefined1 **)(iVar8 + 0x130) = puVar3;
        *(undefined4 *)(iVar8 + 0x134) = uVar10;
        *(uint *)(puVar3 + 8) = *(int *)(puVar3 + 8) - uVar7;
        FUN_0410ad9c();
        pcVar12 = *(char **)(iVar8 + 0x134);
        puVar2 = DAT_04103940;
        goto joined_r0x0410387a;
      }
      uVar7 = uVar7 - *(uint *)(puVar3 + 8);
      *puVar3 = 3;
      puVar5 = *(undefined1 **)(puVar3 + 4);
      puVar11 = puVar3;
    }
    *(undefined4 *)(puVar11 + 4) = 0;
    pcVar12 = *(char **)(iVar8 + 0x130);
    *(undefined4 *)(iVar8 + 0x130) = 0;
    *(char **)(iVar8 + 0x134) = pcVar12;
    puVar2 = DAT_04103940;
joined_r0x0410387a:
    puVar4 = DAT_04103940;
    DAT_04103940 = puVar2;
    if (pcVar12 != (char *)0x0) {
      do {
        *(undefined4 *)(iVar8 + 0x134) = *(undefined4 *)(pcVar12 + 4);
        *pcVar12 = '\x04';
        pcVar12[4] = '\0';
        pcVar12[5] = '\0';
        pcVar12[6] = '\0';
        pcVar12[7] = '\0';
        if (*(int *)(pcVar12 + 0xc) != 0) {
          if (iVar13 == 0) {
            *puVar4 = 0xffffffff;
          }
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(iVar13);
          }
          (**(code **)(pcVar12 + 0xc))(*(undefined4 *)(pcVar12 + 0x10));
          iVar13 = 0;
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            iVar13 = getBasePriority();
          }
          if (iVar13 != 0x40) {
            bVar1 = (bool)isCurrentModePrivileged();
            if (bVar1) {
              setBasePriority(0x40);
            }
            *puVar4 = 0x41038b2;
            puVar4[1] = unaff_lr;
          }
          if (*pcVar12 != '\x04') goto code_r0x041038ba;
        }
        *pcVar12 = '\x01';
        pcVar12 = *(char **)(iVar8 + 0x134);
        if (pcVar12 == (char *)0x0) break;
      } while( true );
    }
    goto LAB_041038e0;
  }
  *DAT_04103950 = *DAT_04103950 + 1;
  FUN_04109118(0x41,uVar10);
LAB_041038e0:
  if (iVar13 == 0) {
    *DAT_04103940 = 0xffffffff;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar13);
  }
  return;
code_r0x041038ba:
  pcVar12 = *(char **)(iVar8 + 0x134);
  puVar2 = DAT_04103940;
  DAT_04103940 = puVar4;
  goto joined_r0x0410387a;
}



// ===========================================================
// Function: FUN_04103958 at 04103958
// ===========================================================

undefined4
FUN_04103958(char *param_1,int param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 unaff_lr;
  
  puVar3 = DAT_04103a38;
  iVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar8 = getBasePriority();
  }
  if (iVar8 == 0x40) {
    if ((*param_1 != '\x04') && (*param_1 != '\x01')) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(0x40);
      }
      return 3;
    }
  }
  else {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04103a38 = 0x4103970;
    puVar3[1] = unaff_lr;
    if ((*param_1 != '\x01') && (*param_1 != '\x04')) {
      uVar4 = 3;
      goto LAB_04103980;
    }
  }
  *param_1 = '\x02';
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 0xc) = param_3;
    *(undefined4 *)(param_1 + 0x10) = param_4;
  }
  iVar2 = DAT_04103a40;
  if (param_5 == 0) {
    param_5 = 1;
  }
  if (*(int *)(DAT_04103a40 + 0x130) == 0) {
    param_1[4] = '\0';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
    *(char **)(iVar2 + 0x130) = param_1;
    FUN_0410ad9c(param_5);
  }
  else {
    uVar5 = FUN_0410ae1c();
    iVar7 = *(int *)(iVar2 + 0x130);
    uVar6 = *(uint *)(iVar7 + 8);
    if (uVar6 == 0) {
      uVar6 = 1;
    }
    if (uVar6 < uVar5) {
                    /* WARNING: Subroutine does not return */
      FUN_04109484(DAT_04103a3c,uVar5);
    }
    if (param_5 < uVar5) {
      *(uint *)(iVar7 + 8) = uVar5 - param_5;
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar2 + 0x130);
      *(char **)(iVar2 + 0x130) = param_1;
      FUN_0410adf4();
      FUN_0410ad9c(param_5);
    }
    else {
      param_5 = param_5 - uVar5;
      for (iVar2 = *(int *)(iVar7 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
        uVar5 = *(uint *)(iVar2 + 8);
        if (param_5 <= uVar5) {
          *(uint *)(iVar2 + 8) = uVar5 - param_5;
          break;
        }
        param_5 = param_5 - uVar5;
        iVar7 = iVar2;
      }
      *(char **)(iVar7 + 4) = param_1;
      *(int *)(param_1 + 4) = iVar2;
    }
  }
  uVar4 = 0;
  *(uint *)(param_1 + 8) = param_5;
LAB_04103980:
  if (iVar8 == 0) {
    *DAT_04103a38 = 0xffffffff;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar8);
  }
  return uVar4;
}



// ===========================================================
// Function: FUN_04103a90 at 04103a90
// ===========================================================

void FUN_04103a90(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 unaff_lr;
  
  puVar3 = DAT_04103b04;
  iVar2 = DAT_04103b00;
  iVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar5 = getBasePriority();
  }
  if (iVar5 == 0x40) {
    pcVar4 = *(char **)(DAT_04103b00 + 300);
    if (pcVar4 == (char *)0x0) goto LAB_04103af2;
    *(undefined4 *)(DAT_04103b00 + 300) = *(undefined4 *)(pcVar4 + 4);
  }
  else {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04103b04 = 0x4103aa6;
    puVar3[1] = unaff_lr;
    pcVar4 = *(char **)(iVar2 + 300);
    if (pcVar4 == (char *)0x0) {
      if (iVar5 == 0) {
        *puVar3 = 0xffffffff;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(0);
        }
        return;
      }
LAB_04103af2:
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(iVar5);
      }
      return;
    }
    *(undefined4 *)(iVar2 + 300) = *(undefined4 *)(pcVar4 + 4);
    if (iVar5 == 0) {
      *puVar3 = 0xffffffff;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar5);
  }
  if (*pcVar4 == '\0') {
    pcVar4[4] = '\0';
    pcVar4[5] = '\0';
    pcVar4[6] = '\0';
    pcVar4[7] = '\0';
    *(undefined4 *)(pcVar4 + 0xc) = param_1;
    *(undefined4 *)(pcVar4 + 0x10) = param_2;
    *pcVar4 = '\x01';
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_04103b08,*pcVar4);
}



// ===========================================================
// Function: FUN_04103b0c at 04103b0c
// ===========================================================

undefined4 FUN_04103b0c(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((param_1 <= DAT_04103b3c + 0x118) && (param_1 >= DAT_04103b3c)) {
    uVar1 = FUN_04103958(param_1,0,0,param_1 < DAT_04103b3c,param_2);
    return uVar1;
  }
  return 2;
}



// ===========================================================
// Function: FUN_04103b40 at 04103b40
// ===========================================================

char FUN_04103b40(char *param_1)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  char cVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  int iVar13;
  uint uVar14;
  undefined4 unaff_lr;
  
  puVar3 = DAT_04103cb0;
  pcVar11 = DAT_04103cac;
  if ((DAT_04103cac + 0x118 < param_1) || (param_1 < DAT_04103cac)) {
    return '\x02';
  }
  iVar13 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    iVar13 = getBasePriority();
  }
  cVar5 = '\0';
  if (iVar13 == 0x40) {
    cVar4 = *param_1;
    if (*param_1 == '\x01') goto LAB_04103b8e;
LAB_04103b76:
    cVar5 = cVar4;
    if (cVar5 == '\x02') {
      pcVar8 = *(char **)(pcVar11 + 0x130);
      if (pcVar8 == param_1) {
        uVar6 = FUN_0410ae1c();
        uVar9 = *(uint *)(*(int *)(pcVar11 + 0x130) + 8);
        if (uVar9 == 0) {
          uVar9 = 1;
        }
        if (uVar9 < uVar6) {
                    /* WARNING: Subroutine does not return */
          FUN_04109484(DAT_04103cc0,uVar6);
        }
        FUN_0410adf4();
        iVar10 = *(int *)(*(int *)(pcVar11 + 0x130) + 4);
        if (iVar10 != 0) {
          if (uVar6 == 0) {
            uVar6 = FUN_0410ae28();
            uVar9 = *(uint *)(*(int *)(pcVar11 + 0x130) + 8);
            if (uVar6 + 1 < uVar9) {
                    /* WARNING: Subroutine does not return */
              FUN_04109484(DAT_04103cbc,uVar6);
            }
            uVar14 = 0;
            iVar7 = iVar10;
            if (uVar9 < uVar6) {
              uVar14 = uVar6 - uVar9;
            }
            do {
              uVar6 = *(uint *)(iVar7 + 8);
              if (uVar14 < uVar6) {
                *(uint *)(iVar7 + 8) = uVar6 - uVar14;
                break;
              }
              *(undefined4 *)(iVar7 + 8) = 0;
              uVar14 = uVar14 - uVar6;
              piVar1 = (int *)(iVar7 + 4);
              iVar7 = *piVar1;
            } while (*piVar1 != 0);
            iVar7 = *(int *)(iVar10 + 8);
          }
          else {
            iVar7 = *(int *)(iVar10 + 8) + uVar6;
            *(int *)(iVar10 + 8) = iVar7;
          }
          FUN_0410ad9c(iVar7);
        }
        *(int *)(pcVar11 + 0x130) = iVar10;
      }
      else {
        if (pcVar8 == (char *)0x0) {
LAB_04103c08:
                    /* WARNING: Subroutine does not return */
          FUN_04109484(DAT_04103cb4,param_1);
        }
        pcVar11 = *(char **)(pcVar8 + 4);
        if ((param_1 == pcVar11) || (pcVar11 == (char *)0x0)) {
LAB_04103c04:
          if (param_1 != pcVar11) goto LAB_04103c08;
        }
        else {
          do {
            pcVar8 = pcVar11;
            pcVar12 = *(char **)(pcVar8 + 4);
            pcVar11 = (char *)0x0;
            if (pcVar12 == (char *)0x0) goto LAB_04103c04;
            pcVar11 = pcVar12;
          } while (param_1 != pcVar12);
        }
        iVar10 = *(int *)(param_1 + 4);
        *(int *)(pcVar8 + 4) = iVar10;
        if (iVar10 != 0) {
          *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) + *(int *)(param_1 + 8);
        }
      }
    }
    else {
      if (cVar5 != '\x03') {
        if (cVar5 != '\x04') {
          cVar5 = '\x03';
        }
        goto LAB_04103b84;
      }
      pcVar8 = *(char **)(pcVar11 + 0x134);
      if (pcVar8 == param_1) {
        *(undefined4 *)(pcVar11 + 0x134) = *(undefined4 *)(param_1 + 4);
      }
      else {
        if (pcVar8 == (char *)0x0) {
LAB_04103c16:
                    /* WARNING: Subroutine does not return */
          FUN_04109484(DAT_04103cb8,param_1);
        }
        pcVar11 = *(char **)(pcVar8 + 4);
        if ((pcVar11 == (char *)0x0) || (param_1 == pcVar11)) {
LAB_04103c12:
          if (param_1 != pcVar11) goto LAB_04103c16;
        }
        else {
          do {
            pcVar8 = pcVar11;
            pcVar12 = *(char **)(pcVar8 + 4);
            pcVar11 = (char *)0x0;
            if (pcVar12 == (char *)0x0) goto LAB_04103c12;
            pcVar11 = pcVar12;
          } while (param_1 != pcVar12);
        }
        *(undefined4 *)(pcVar8 + 4) = *(undefined4 *)(param_1 + 4);
      }
    }
    cVar5 = '\0';
    *param_1 = '\x01';
    param_1[4] = '\0';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
  }
  else {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(0x40);
    }
    *DAT_04103cb0 = 0x4103b6c;
    puVar3[1] = unaff_lr;
    cVar4 = *param_1;
    if (*param_1 != '\x01') goto LAB_04103b76;
  }
LAB_04103b84:
  if (iVar13 == 0) {
    *DAT_04103cb0 = 0xffffffff;
  }
LAB_04103b8e:
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(iVar13);
  }
  return cVar5;
}



// ===========================================================
// Function: FUN_04103cc4 at 04103cc4
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void FUN_04103cc4(undefined4 param_1)

{
  *DAT_04103cec = param_1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: FUN_04103cf8 at 04103cf8
// ===========================================================

void FUN_04103cf8(undefined1 param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined1 uVar4;
  byte bVar5;
  
  iVar1 = DAT_04103d4c;
  if (*DAT_04103d48 == '\x01') {
    uVar4 = 0x62;
  }
  else if (*DAT_04103d48 == '\x02') {
    uVar4 = 0x68;
  }
  else {
    uVar4 = 8;
  }
  *(undefined1 *)(DAT_04103d4c + 1) = uVar4;
  *(undefined1 *)(iVar1 + 2) = param_3;
  pcVar3 = (char *)(iVar1 + -1);
  *(undefined1 *)(iVar1 + 4) = param_1;
  *(undefined1 *)(iVar1 + 3) = 3;
  bVar5 = 0;
  *(char *)(iVar1 + 5) = (char)param_2;
  *(char *)(iVar1 + 6) = (char)((uint)param_2 >> 8);
  iVar2 = DAT_04103d4c;
  do {
    pcVar3 = pcVar3 + 1;
    bVar5 = bVar5 + *pcVar3;
  } while (pcVar3 != (char *)(iVar1 + 6));
  *(byte *)(iVar1 + 7) = ~bVar5;
  FUN_041061f0(iVar2,8);
  return;
}



// ===========================================================
// Function: FUN_04103d50 at 04103d50
// ===========================================================

undefined4 FUN_04103d50(uint *param_1)

{
  uint uVar1;
  
  if ((*DAT_04103db0 & 0xfd) != 1) {
    return 1;
  }
  uVar1 = *DAT_04103db4 + 1;
  if (uVar1 < 2) {
    if (DAT_04103db8[uVar1] == '\x02') goto LAB_04103d94;
    if (*DAT_04103db4 == 0) {
      uVar1 = 0;
      if (*DAT_04103db8 != '\x02') {
        return 1;
      }
      goto LAB_04103d94;
    }
  }
  else if (*DAT_04103db8 == '\x02') {
    *param_1 = 0;
    return 0;
  }
  if (DAT_04103db8[1] != '\x02') {
    return 1;
  }
  uVar1 = 1;
LAB_04103d94:
  *param_1 = uVar1;
  return 0;
}



// ===========================================================
// Function: FUN_04103dbc at 04103dbc
// ===========================================================

undefined4 FUN_04103dbc(uint param_1)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  
  if (param_1 < 2) {
    uVar3 = FUN_0410ad54();
    FUN_04109118(0x43,DAT_04103f60,uVar3 >> 4,DAT_04103f5c,param_1);
    iVar2 = DAT_04103f94;
    pcVar1 = DAT_04103f90;
    iVar6 = DAT_04103f8c;
    iVar7 = DAT_04103f8c + param_1 * 0x20040;
    uVar3 = (uint)*(byte *)(iVar7 + 6) << 0x10 | (uint)*(byte *)(iVar7 + 5) << 8 |
            (uint)*(byte *)(iVar7 + 4) | (uint)*(byte *)(iVar7 + 7) << 0x18;
    iVar9 = *DAT_04103f68 * (uint)*(ushort *)(iVar7 + 0xc) + *DAT_04103f64;
    FUN_04109118(0x43,DAT_04103f6c,(uint)*(ushort *)(iVar7 + 0xc),iVar9,uVar3);
    iVar7 = DAT_04103f98;
    if (*pcVar1 != '\0') {
      *(undefined1 *)(iVar2 + param_1) = 0xff;
      *(undefined1 *)(iVar7 + param_1) = 3;
    }
    if (*DAT_04103f70 == '\x03') {
      FUN_0410ef70(iVar9,iVar6 + param_1 * 0x20040 + 0x10,uVar3);
LAB_04103ec8:
      *(undefined1 *)(iVar2 + param_1) = 0x60;
      *(undefined1 *)(iVar7 + param_1) = 3;
      return 0;
    }
    iVar4 = FUN_041067a8(iVar9,uVar3);
    if (iVar4 != 0) {
      FUN_04109118(0x43,DAT_04103f80,iVar9,uVar3,iVar4);
      *(undefined1 *)(iVar2 + param_1) = 0x67;
      *(undefined1 *)(iVar7 + param_1) = 3;
      return 0;
    }
    uVar5 = FUN_0410ad54();
    FUN_04109118(0x41,DAT_04103f74,uVar5 >> 4);
    if (*pcVar1 != '\0') {
      *(undefined1 *)(iVar2 + param_1) = 0xff;
      *(undefined1 *)(iVar7 + param_1) = 3;
    }
    iVar4 = iVar6 + param_1 * 0x20040 + 0x10;
    iVar6 = FUN_04106844(iVar9,iVar4,uVar3);
    if (iVar6 == 0) {
      uVar5 = FUN_0410ad54();
      FUN_04109118(0x41,DAT_04103f78,uVar5 >> 4);
      if (*pcVar1 != '\0') {
        *(undefined1 *)(iVar2 + param_1) = 0xff;
        *(undefined1 *)(iVar7 + param_1) = 3;
      }
      iVar6 = FUN_041068bc(iVar9,iVar4,uVar3);
      if (iVar6 == 0) {
        uVar3 = FUN_0410ad54();
        FUN_04109118(0x41,DAT_04103f7c,uVar3 >> 4);
        goto LAB_04103ec8;
      }
      FUN_04109118(0x40,DAT_04103f88);
      uVar8 = 0;
      *(undefined1 *)(iVar2 + param_1) = 0x69;
      *(undefined1 *)(iVar7 + param_1) = 3;
    }
    else {
      FUN_04109118(0x43,DAT_04103f84,iVar9,uVar3,iVar6);
      *(undefined1 *)(iVar2 + param_1) = 0x68;
      *(undefined1 *)(iVar7 + param_1) = 3;
      uVar8 = 0;
    }
  }
  else {
    uVar8 = 1;
  }
  return uVar8;
}



// ===========================================================
// Function: FUN_04103f9c at 04103f9c
// ===========================================================

undefined4 FUN_04103f9c(void)

{
  char *pcVar1;
  undefined4 in_r3;
  uint uVar2;
  int iVar3;
  
  pcVar1 = DAT_04104000;
  uVar2 = *DAT_04103ffc + 1;
  if (uVar2 < 2) {
    if (DAT_04104000[uVar2] == '\x03') goto LAB_04103fbc;
    if (*DAT_04103ffc == 0) {
      if (*DAT_04104000 != '\x03') {
        return 1;
      }
      uVar2 = 0;
      goto LAB_04103fbc;
    }
  }
  else if (*DAT_04104000 == '\x03') {
    uVar2 = 0;
    goto LAB_04103fbc;
  }
  if (DAT_04104000[1] != '\x03') {
    return 1;
  }
  uVar2 = 1;
LAB_04103fbc:
  iVar3 = DAT_04104004 + uVar2 * 0x20040;
  FUN_04103cf8(*(undefined1 *)(DAT_04104008 + uVar2),*(undefined2 *)(iVar3 + 0xc),
               *(undefined1 *)(iVar3 + 2),DAT_04104008,in_r3);
  pcVar1[uVar2] = '\0';
  return 0;
}



// ===========================================================
// Function: FUN_0410400c at 0410400c
// ===========================================================

bool FUN_0410400c(void)

{
  return DAT_0410401c[1] != '\0' || *DAT_0410401c != '\0';
}



// ===========================================================
// Function: FUN_04104020 at 04104020
// ===========================================================

bool FUN_04104020(void)

{
  if (*DAT_0410403c != '\x02') {
    return DAT_0410403c[1] == '\x02';
  }
  return true;
}



// ===========================================================
// Function: FUN_04104040 at 04104040
// ===========================================================

void FUN_04104040(int param_1)

{
  *(bool *)DAT_0410404c = param_1 != 0;
  return;
}



// ===========================================================
// Function: FUN_04104064 at 04104064
// ===========================================================

bool FUN_04104064(void)

{
  return *DAT_04104074 == '\x04';
}



// ===========================================================
// Function: FUN_04104078 at 04104078
// ===========================================================

void FUN_04104078(undefined4 param_1,uint param_2)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  byte bVar7;
  uint uVar8;
  char *pcVar6;
  
  pcVar4 = DAT_041040dc;
  pcVar3 = DAT_041040d8;
  if (0x14 < param_2) {
    param_2 = 0x15;
  }
  DAT_041040d8[1] = '\x10';
  cVar1 = *pcVar4;
  pcVar3[2] = cVar1;
  pcVar3[3] = (char)param_2;
  *pcVar4 = cVar1 + '\x01';
  FUN_0410ef70(pcVar3 + 4,param_1,param_2);
  pcVar4 = DAT_041040d8;
  bVar2 = pcVar3[3];
  uVar8 = bVar2 + 4 & 0xff;
  if (uVar8 == 0) {
    bVar7 = 0xff;
  }
  else {
    bVar7 = 0;
    pcVar6 = pcVar3;
    do {
      pcVar5 = pcVar6 + 1;
      bVar7 = bVar7 + *pcVar6;
      pcVar6 = pcVar5;
    } while (pcVar5 != pcVar3 + uVar8);
    bVar7 = ~bVar7;
  }
  pcVar3[param_2 + 4] = bVar7;
  FUN_041061f0(pcVar4,bVar2 + 5);
  return;
}



// ===========================================================
// Function: FUN_041040e0 at 041040e0
// ===========================================================

undefined4 FUN_041040e0(undefined4 param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar7;
  byte bVar8;
  uint uVar9;
  char *pcVar6;
  
  pcVar3 = DAT_0410414c;
  if (param_2 + 1U < 0x17) {
    cVar1 = *(char *)(DAT_04104148 + 2);
    pcVar4 = DAT_0410414c + 4;
    DAT_0410414c[1] = *(char *)(DAT_04104148 + 1);
    pcVar3[3] = (char)param_2;
    pcVar3[2] = cVar1;
    FUN_0410ef70(pcVar4,param_1,param_2);
    pcVar4 = DAT_0410414c;
    bVar2 = pcVar3[3];
    uVar9 = bVar2 + 4 & 0xff;
    if (uVar9 == 0) {
      bVar8 = 0xff;
    }
    else {
      bVar8 = 0;
      pcVar6 = pcVar3;
      do {
        pcVar5 = pcVar6 + 1;
        bVar8 = bVar8 + *pcVar6;
        pcVar6 = pcVar5;
      } while (pcVar5 != pcVar3 + uVar9);
      bVar8 = ~bVar8;
    }
    pcVar3[param_2 + 4] = bVar8;
    uVar7 = FUN_041061f0(pcVar4,bVar2 + 5);
    return uVar7;
  }
  FUN_04109118(0x41,DAT_04104150,param_2);
  return 0xffffffff;
}



// ===========================================================
// Function: FUN_04104154 at 04104154
// ===========================================================

undefined4 FUN_04104154(int param_1,uint param_2,uint param_3)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  uint uVar8;
  undefined4 uStack_2c;
  undefined4 local_28 [4];
  undefined1 auStack_18 [4];
  
  uVar4 = DAT_04104240;
  if ((param_1 != 1) && (uVar4 = DAT_04104238, param_1 != 0x4465)) {
    return 0xff;
  }
  uVar8 = param_3;
  FUN_04109118(0x43,DAT_0410423c,uVar4,param_2,param_3);
  iVar3 = FUN_041061e8();
  if (iVar3 == 0) {
    FUN_04109118(0x41,DAT_04104244,uVar4);
    uVar4 = 9;
  }
  else if (param_3 < 0x11) {
    if (param_1 == 1) {
      if (((param_2 | param_3) & 3) == 0) {
        if (param_3 >> 2 != 0) {
          puVar6 = &uStack_2c;
          iVar3 = param_2 - (int)puVar6;
          uVar8 = 0;
          do {
            uVar8 = uVar8 + 1;
            puVar2 = (undefined4 *)(iVar3 + (int)puVar6);
            puVar6 = puVar6 + 1;
            *puVar6 = *puVar2;
          } while (param_3 >> 2 != uVar8);
        }
      }
      else if ((int)((param_2 | param_3) << 0x1f) < 0) {
        FUN_0410ef70(local_28,param_2,param_3);
      }
      else if (param_3 >> 1 != 0) {
        puVar7 = (undefined2 *)((int)&uStack_2c + 2);
        puVar5 = puVar7 + (param_3 >> 1);
        do {
          puVar1 = (undefined2 *)((int)puVar7 + (0x12 - (int)auStack_18) + param_2);
          puVar7 = puVar7 + 1;
          *puVar7 = *puVar1;
        } while (puVar7 != puVar5);
      }
    }
    else {
      iVar3 = FUN_04106b3c(param_2,local_28,param_3);
      if (iVar3 != 0) {
        FUN_04109118(0x42,DAT_0410424c,uVar4,iVar3,uVar8);
        return 7;
      }
    }
    uStack_2c._3_1_ = 0;
    FUN_041040e0((int)&uStack_2c + 3,param_3 + 1);
    uVar4 = 0;
  }
  else {
    FUN_04109118(0x42,DAT_04104248,uVar4,param_3,uVar8);
    uVar4 = 8;
  }
  return uVar4;
}



// ===========================================================
// Function: programmer_main at 04104250
// ===========================================================

void programmer_main(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  char *pcVar6;
  char *pcVar7;
  byte *pbVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  uint *puVar11;
  uint *puVar12;
  char cVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  undefined4 uVar18;
  byte bVar19;
  char *pcVar20;
  char *pcVar21;
  undefined4 uVar22;
  bool bVar23;
  char *pcVar24;
  int iVar25;
  undefined4 uVar26;
  undefined1 uVar27;
  uint uVar28;
  int *piVar29;
  uint *puVar30;
  undefined4 uVar31;
  char cVar32;
  undefined4 uVar33;
  uint uVar34;
  uint *puVar35;
  uint uVar36;
  char *local_60;
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_51;
  uint local_50;
  uint local_4c;
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  char *local_38;
  uint uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  pcVar7 = DAT_0410459c;
  pcVar6 = DAT_0410454c;
  local_60 = DAT_0410454c;
  uVar14 = FUN_0410ad54();
  pbVar9 = DAT_041045a4;
  pbVar8 = DAT_041045a0;
  FUN_04109118(0x42,DAT_04104554,uVar14 >> 4,DAT_04104550);
  FUN_04105e78();
  FUN_0410611c();
  while( true ) {
    FUN_04106168();
    *pbVar8 = 0;
    *pbVar9 = 0;
    FUN_0410ef64(pcVar7,0,4);
    *DAT_04104558 = 0;
    *DAT_0410455c = 1;
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_04104554,uVar14 >> 4,DAT_04104560);
    pcVar20 = DAT_04104564;
    bVar19 = 0;
    local_60[1] = '`';
    cVar13 = *pcVar20;
    local_60[2] = cVar13;
    *pcVar20 = cVar13 + '\x01';
    local_60[3] = '\x06';
    *(undefined4 *)(local_60 + 4) = DAT_04104568;
    local_60[8] = '\x03';
    pcVar20 = DAT_0410454c;
    local_60[9] = '\0';
    local_60 = DAT_0410454c;
    pcVar21 = DAT_0410454c;
    do {
      pcVar24 = pcVar21 + 1;
      bVar19 = bVar19 + *pcVar21;
      pcVar21 = pcVar24;
    } while (pcVar24 != pcVar6 + 10);
    DAT_0410454c[10] = ~bVar19;
    iVar15 = FUN_041061f0(pcVar20,0xb);
    if (iVar15 == 0) break;
    FUN_04109118(0x40,DAT_04104848);
LAB_04104622:
    bVar19 = *pbVar8;
joined_r0x04104516:
    if (((bVar19 & 0xfd) == 1) && (iVar15 = FUN_04106b1c(), iVar15 != 0)) {
      FUN_04109118(0x40,DAT_04104594);
      iVar15 = FUN_041064b8();
    }
    else {
      iVar15 = FUN_041064b8();
    }
    if (iVar15 != 0) {
      return;
    }
    FUN_04109118(0x40,DAT_04104840);
  }
  bVar19 = *pbVar9;
  uVar14 = 4;
  pcVar20 = pcVar7;
LAB_041042fe:
  local_50 = 0;
  if (bVar19 == 2) goto LAB_041044de;
  if (*pbVar8 == 0 && bVar19 == 0) {
    FUN_041061c0(1);
    FUN_041061b4();
    goto LAB_04104322;
  }
LAB_04104316:
  local_50 = 0;
  FUN_041061c0(0);
  FUN_041061b4();
LAB_04104322:
  iVar15 = FUN_041062d0(pcVar20,0,uVar14,&local_50);
  uVar16 = local_44;
joined_r0x04104330:
  local_44 = uVar16;
  if (iVar15 != 0) {
    FUN_04109118(0x43,DAT_04104590,iVar15,uVar14,local_50);
    bVar19 = *pbVar8;
    goto joined_r0x04104516;
  }
  if (local_50 != uVar14) {
    FUN_04109118(0x42,DAT_04104860,uVar14);
    goto LAB_04104622;
  }
  uVar34 = (uint)*pbVar9;
  local_44._1_3_ = (uint3)(uVar16 >> 8);
  if (uVar34 == 0) goto LAB_041045a8;
  if (1 < uVar34 - 1) {
    FUN_04109118(0x41,DAT_04104598,uVar34);
    bVar19 = *pbVar9;
    goto LAB_041042fe;
  }
  if (uVar34 != 1) {
    bVar19 = pcVar7[1];
    if (bVar19 == 9) {
      uVar14 = FUN_0410ad54();
      FUN_04109118(0x42,DAT_04104850,uVar14 >> 4,DAT_0410484c);
      iVar15 = FUN_041037e8(0,*DAT_04104858,*DAT_04104854);
      if (iVar15 == *DAT_0410485c) {
        local_44 = CONCAT31(local_44._1_3_,0x80);
      }
      else {
        FUN_04109118(0x40,DAT_04104864);
        local_44 = CONCAT31(local_44._1_3_,0x81);
      }
      FUN_041040e0(&local_44,1);
      *pbVar8 = 0;
      goto LAB_041046fc;
    }
    if (bVar19 < 10) {
      if (bVar19 == 7) goto LAB_0410436c;
    }
    else if ((bVar19 == 0x61) || (bVar19 == 0x67)) {
LAB_0410436c:
      if (*pbVar8 == 1) {
        cVar13 = 'b';
        uVar18 = DAT_04104868;
      }
      else if (*pbVar8 == 2) {
        cVar13 = 'h';
        uVar18 = DAT_04104570;
      }
      else {
        cVar13 = '\b';
        uVar18 = DAT_0410456c;
      }
      uVar14 = FUN_0410ad54();
      iVar15 = DAT_04104574;
      FUN_04109118(0x42,DAT_04104554,uVar14 >> 4,uVar18);
      uVar22 = DAT_04104578;
      iVar25 = *DAT_04104558;
      pcVar20 = (char *)(iVar15 + iVar25 * 0x20040);
      cVar32 = *(char *)(iVar15 + iVar25 * 0x20040);
      if (cVar32 == -0x42) {
        if (cVar13 == pcVar20[1]) {
          if (pcVar20[3] == '\v') {
            cVar32 = '\0';
            pcVar21 = pcVar20 + 0xf;
            cVar13 = -0x42;
            while (cVar32 = cVar32 + cVar13, pcVar21 != pcVar20) {
              pcVar20 = pcVar20 + 1;
              cVar13 = *pcVar20;
            }
            if (cVar32 == -1) {
              iVar15 = DAT_04104574 + iVar25 * 0x20040;
              bVar3 = *(byte *)(iVar15 + 10);
              bVar1 = *(byte *)(iVar15 + 9);
              uVar34 = (uint)*(byte *)(iVar15 + 6) << 0x10 | (uint)*(byte *)(iVar15 + 5) << 8 |
                       (uint)*(byte *)(iVar15 + 4) | (uint)*(byte *)(iVar15 + 7) << 0x18;
              uVar5 = *(ushort *)(iVar15 + 0xc);
              bVar4 = *(byte *)(iVar15 + 8);
              bVar2 = *(byte *)(iVar15 + 0xb);
              *DAT_0410457c = (uint)uVar5;
              uVar16 = (uint)bVar3 << 0x10 | (uint)bVar1 << 8 | (uint)bVar4 | (uint)bVar2 << 0x18;
              uVar14 = uVar34;
              FUN_04109118(0x44,uVar22,uVar18,(uint)uVar5,uVar34,iVar25);
              puVar35 = DAT_0410486c;
              puVar30 = DAT_04104580;
              if ((bVar19 == 0x61) || (bVar19 == 7)) {
                uVar14 = *DAT_0410486c;
                uVar28 = *DAT_04104870;
                if (uVar14 <= uVar28) {
                  FUN_04109118(0x43,DAT_041051a4,uVar18,uVar28,uVar14,iVar25);
                  FUN_04103cf8(0x66,*DAT_041051a8,DAT_041051ac[*DAT_04105188 * 0x20040 + 2]);
                  goto LAB_041046fc;
                }
                if (uVar14 == uVar28 + 1) {
                  uVar14 = *DAT_04104884;
                }
                else {
                  uVar14 = *DAT_04104874;
                }
                if (uVar34 == uVar14) {
                  uVar14 = FUN_041037e8(0,DAT_0410487c + *DAT_04104880 * 0x20040 + 0x10,uVar34);
                  if (uVar16 != uVar14) goto LAB_04104474;
                  uVar14 = *DAT_04104870;
                  uVar16 = *DAT_04104880;
                  *(undefined1 *)(DAT_04104888 + uVar16) = 2;
                  iVar15 = 0xff;
                  if (uVar14 + 1 != *puVar35) {
LAB_041048aa:
                    puVar30 = DAT_04104b08;
                    uVar14 = uVar16 + 1;
                    if (uVar14 < 2) {
                      if (DAT_04104b04[uVar14] == '\0') goto LAB_041048c6;
                      if (uVar16 != 0) goto LAB_04104892;
                      uVar14 = 0;
                      if (*DAT_04104b04 == '\0') goto LAB_041048c6;
LAB_0410489c:
                      iVar17 = FUN_04106ae8();
                      if (iVar17 != 0) {
                        FUN_04109118(0x41,DAT_041051e0,uVar18);
                        goto LAB_0410460a;
                      }
                      uVar16 = *DAT_04104b08;
                      goto LAB_041048aa;
                    }
                    uVar14 = 0;
                    if (*DAT_04104b04 == '\0') goto LAB_041048c6;
LAB_04104892:
                    if (DAT_04104b04[1] != '\0') goto LAB_0410489c;
                    uVar14 = 1;
LAB_041048c6:
                    DAT_04104b04[uVar14] = '\x01';
                    *puVar30 = uVar14;
                    uVar14 = FUN_0410ad54();
                    FUN_04109118(0x43,DAT_04104b0c,uVar14 >> 4,uVar18,*puVar30,iVar25);
                    pcVar20 = (char *)(DAT_04104b14 + *puVar30 * 0x20040);
                    piVar29 = DAT_04104b1c;
                    if (*DAT_04104b10 + 2U != *puVar35) {
                      piVar29 = DAT_04104b20;
                    }
                    uVar14 = *piVar29 + 0x10;
                    *DAT_04104b18 = DAT_04104b24;
                    goto LAB_0410490a;
                  }
                  iVar25 = FUN_04106afc();
                  if (iVar25 == 0) {
                    *pbVar8 = 0;
                    goto LAB_041046fc;
                  }
                  FUN_04109118(0x41,DAT_041058dc,uVar18);
                  goto LAB_0410460a;
                }
                FUN_04109118(0x43,DAT_04104878,uVar18,uVar28,uVar34,iVar25);
              }
              else {
                if (uVar34 == *DAT_04104580) {
                  uVar34 = FUN_041037e8(0,DAT_04104574 + *DAT_04104558 * 0x20040 + 0x10,uVar34);
                  puVar10 = DAT_04104e58;
                  if (uVar16 == uVar34) {
                    uVar16 = FUN_0410ad54();
                    FUN_04109118(0x42,DAT_04104e64,uVar16 >> 4,uVar18,uVar14,iVar25);
                    iVar15 = FUN_04106b78(*puVar10,*puVar30);
                    if (iVar15 == 0) {
                      uVar14 = FUN_0410ad54();
                      FUN_04109118(0x42,DAT_04104e68,uVar14 >> 4,uVar18);
                      iVar15 = FUN_04106be8(*puVar10,DAT_04104e6c,*puVar30);
                      if (iVar15 == 0) {
                        uVar14 = FUN_0410ad54();
                        FUN_04109118(0x42,DAT_04104e70,uVar14 >> 4,uVar18);
                        iVar15 = FUN_04106c24(*puVar10,*puVar30 + DAT_04104e6c);
                        if (iVar15 == 0) {
                          uVar14 = FUN_0410ad54();
                          FUN_04109118(0x42,DAT_04104e74,uVar14 >> 4,uVar18);
                          FUN_04103cf8(0x60,0,*(undefined1 *)(DAT_04104e78 + 2));
                          *pbVar8 = 0;
                        }
                        else {
                          uVar14 = FUN_0410ad54();
                          FUN_04109118(0x42,DAT_041058cc,uVar14 >> 4,DAT_041058c8);
                          FUN_04103cf8(0x69,0,*(undefined1 *)(DAT_041058d0 + 2));
                        }
                      }
                      else {
                        uVar14 = FUN_0410ad54();
                        FUN_04109118(0x42,DAT_041051c8,uVar14 >> 4,DAT_041051e4);
                        FUN_04103cf8(0x68,0,DAT_041051ac[2]);
                      }
                    }
                    else {
                      uVar14 = FUN_0410ad54();
                      FUN_04109118(0x42,DAT_041051c8,uVar14 >> 4,DAT_041051c4);
                      FUN_04103cf8(0x67,0,DAT_041051ac[2]);
                    }
                  }
                  else {
LAB_04104474:
                    FUN_04109118(0x41,DAT_04104584,uVar18);
                    FUN_04103cf8(0x65,(short)*DAT_0410457c,
                                 *(undefined1 *)(DAT_04104574 + *DAT_04104558 * 0x20040 + 2));
                  }
                  goto LAB_041046fc;
                }
                FUN_04109118(0x42,DAT_04105198,uVar18,uVar34,uVar14,iVar25);
              }
              FUN_04103cf8(100,(short)*DAT_04104870,
                           *(undefined1 *)(DAT_0410487c + *DAT_04104880 * 0x20040 + 2));
              goto LAB_041046fc;
            }
            FUN_04109118(0x41,DAT_0410519c,uVar18);
            uVar18 = 2;
          }
          else {
            FUN_04109118(0x42,DAT_04104b34,uVar18);
            uVar18 = 1;
          }
        }
        else {
          FUN_04109118(0x42,DAT_04104b38,uVar18);
          uVar18 = 0xf;
        }
      }
      else {
        FUN_04109118(0x41,DAT_04104b30,cVar32);
        uVar18 = 5;
      }
      FUN_04103cf8(uVar18,0,*(undefined1 *)(DAT_04104b14 + *DAT_04104b08 * 0x20040 + 2));
      goto LAB_041046fc;
    }
    uVar27 = 2;
LAB_041044a6:
    local_40 = pcVar7;
    local_44 = CONCAT31(local_44._1_3_,uVar27);
    local_3c = 0;
    iVar15 = FUN_0410613c(&local_44);
    if (iVar15 == 0) {
      if (local_3c != 0) {
        *DAT_04104588 = local_30;
        *DAT_0410458c = local_2c;
        uVar14 = uStack_34;
        pcVar20 = local_38;
        goto LAB_041044d4;
      }
      goto LAB_041046fc;
    }
    goto LAB_0410460a;
  }
  local_53 = 0;
  uVar14 = (byte)pcVar7[3] + 5 & 0xff;
  if (uVar14 == 0) {
LAB_04104928:
    iVar15 = 2;
    FUN_04109118(0x40,DAT_04104b2c);
    goto LAB_0410460a;
  }
  cVar13 = '\0';
  pcVar20 = DAT_04104844;
  do {
    pcVar21 = pcVar20 + 1;
    cVar13 = cVar13 + *pcVar20;
    pcVar20 = pcVar21;
  } while (pcVar21 != pcVar7 + uVar14);
  if (cVar13 != -1) goto LAB_04104928;
  uVar14 = (uint)(byte)pcVar7[1];
  if (9 < uVar14) {
    if (6 < (uVar14 - 0x61 & 0xff)) {
switchD_0410467c_caseD_4:
      uVar27 = 1;
      goto LAB_041044a6;
    }
    switch(uVar14 - 0x61) {
    case 0:
    case 6:
      if (uVar14 != 0x61) goto switchD_0410467c_caseD_7;
      uVar16 = FUN_0410ad54();
      puVar30 = DAT_04105178;
      FUN_04109118(0x42,DAT_04105174,uVar16 >> 4,DAT_041051b0);
      puVar35 = DAT_04105180;
      puVar10 = DAT_0410517c;
      uVar16 = *(uint *)(pcVar7 + 0xc);
      *DAT_04105180 = uVar16;
      uVar18 = DAT_04105184;
      uVar22 = *(undefined4 *)(pcVar7 + 4);
      uVar34 = *(uint *)(pcVar7 + 8);
      *puVar10 = uVar22;
      *puVar30 = uVar34;
      FUN_04109118(0x43,uVar18,uVar22,uVar34,uVar16);
      bVar23 = true;
LAB_04104f8a:
      puVar12 = DAT_041051b8;
      puVar11 = DAT_041051b4;
      uVar34 = *puVar35;
      if (((uVar34 & 0x3d000) == 0) ||
         (uVar28 = uVar34 - (uVar34 >> 1 & 0x55555555),
         uVar28 = (uVar28 & 0x33333333) + (uVar28 >> 2 & 0x33333333),
         (uVar28 + (uVar28 >> 4) & 0xf0f0f0f) * 0x1010101 >> 0x18 != 1)) {
        iVar15 = 0x61;
        FUN_04109118(0x42,DAT_041051d4,uVar34,0x3d000,uVar16);
      }
      else {
        uVar28 = *puVar30 / uVar34;
        uVar36 = *puVar30 - uVar34 * uVar28;
        *DAT_041051b4 = uVar28;
        *puVar12 = uVar36;
        if (uVar36 == 0) {
          *puVar12 = uVar34;
        }
        else {
          uVar28 = uVar28 + 1;
          *puVar11 = uVar28;
        }
        if (uVar28 < 0x10000) {
          FUN_041040e0(&local_53,1);
          puVar12 = DAT_041051b8;
          uVar16 = *puVar30;
          if (uVar16 != 0) {
            *DAT_04105188 = 0;
            *DAT_0410518c = 1;
            if (bVar23) {
              *pbVar8 = 1;
            }
            else {
              if (uVar14 == 0x67) goto LAB_04104eda;
              *pbVar8 = 3;
            }
            if (*puVar11 == 1) {
              uVar16 = *puVar12;
            }
            else {
              uVar16 = *puVar35;
            }
            *DAT_04105194 = DAT_041051bc;
            goto LAB_04105026;
          }
          goto LAB_0410508e;
        }
        iVar15 = 0x62;
        FUN_04109118(0x41,DAT_04105c88,uVar28,puVar12,uVar16);
      }
      goto LAB_0410460a;
    default:
      goto switchD_0410467c_caseD_4;
    case 4:
      goto switchD_041046a6_caseD_4;
    case 5:
      uVar14 = FUN_0410ad54();
      FUN_04109118(0x42,DAT_04104b40,uVar14 >> 4,DAT_04104b3c);
      uVar18 = *(undefined4 *)(pcVar7 + 4);
      iVar15 = FUN_041065d0(uVar18,&local_4c,&local_48);
      if (iVar15 == 0) {
        FUN_04109118(0x43,DAT_04104b44,uVar18,local_4c,local_48);
        local_44 = local_44 & 0xffffff00;
        FUN_0410ef70((int)&local_44 + 1,&local_4c,4);
        FUN_0410ef70((int)&local_40 + 1,&local_48,4);
        FUN_041040e0(&local_44,9);
        goto LAB_041046fc;
      }
      iVar15 = 7;
      goto LAB_0410460a;
    }
  }
  switch(uVar14) {
  case 0:
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_04104e28,uVar14 >> 4,DAT_04104e24);
    cVar13 = pcVar7[4];
    local_44 = local_44 & 0xffffff00;
    if (((byte)(cVar13 + 0x1fU) < 2) || (cVar13 == -0x2f)) {
      if (pcVar7[3] != '\x05') goto LAB_04104f0e;
    }
    else if (pcVar7[3] != '\x01') {
LAB_04104f0e:
      iVar15 = 8;
      FUN_04109118(0x42,DAT_041051a0);
      goto LAB_0410460a;
    }
    switch(cVar13) {
    case -0x2f:
      FUN_04109118(0x41,DAT_04105520,DAT_04105530);
      FUN_0410ef70(&local_48,DAT_04105528,4);
      FUN_041065bc(local_48);
      FUN_041040e0(&local_44,1);
      break;
    default:
      iVar15 = 6;
      FUN_04109118(0x41,DAT_041051f4,cVar13);
      goto LAB_0410460a;
    case -0x1f:
      FUN_04109118(0x41,DAT_04105520,DAT_04105524);
      FUN_0410ef70(&local_48,DAT_04105528,4);
      thunk_FUN_0410aa44(local_48);
      FUN_041040e0(&local_44,1);
      break;
    case -0x1e:
      FUN_04109118(0x41,DAT_04105520,DAT_0410552c);
      FUN_0410ef70(&local_48,DAT_04105528,4);
      thunk_FUN_0410aa94(local_48);
      FUN_041040e0(&local_44,1);
      break;
    case -0x1d:
      FUN_04109118(0x41,DAT_04105520,DAT_04105534);
      local_48 = thunk_FUN_0410aa34();
      FUN_0410ef70((int)&local_44 + 1,&local_48,4);
      FUN_041040e0(&local_44,5);
      break;
    case -0xf:
      FUN_04109118(0x41,DAT_04105520,DAT_04105538);
      FUN_041040e0(&local_44,1);
      FUN_0410657c();
      break;
    case -0xe:
      FUN_04109118(0x41,DAT_04105520,DAT_0410553c);
      FUN_041040e0(&local_44,1);
      FUN_0410658c();
      break;
    case -0xd:
      FUN_04109118(0x41,DAT_04105520,DAT_0410551c);
      FUN_041040e0(&local_44,1);
      FUN_0410659c();
    }
    goto LAB_041046fc;
  case 1:
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_04104e28,uVar14 >> 4,DAT_04104e48);
    iVar15 = FUN_04104154(1,*(undefined4 *)(pcVar7 + 4),pcVar7[8]);
joined_r0x041057ac:
    if (iVar15 != 0) goto LAB_0410460a;
    goto LAB_041046fc;
  case 2:
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_04104e28,uVar14 >> 4,DAT_04104e2c);
    uVar34 = *(uint *)(pcVar7 + 4);
    uVar16 = (byte)pcVar7[3] - 4;
    uVar14 = uVar16;
    FUN_04109118(0x43,DAT_04104e34,DAT_04104e30,uVar34,uVar16);
    iVar15 = FUN_041061ec();
    if (iVar15 == 0) {
      iVar15 = 9;
      FUN_04109118(0x41,DAT_041051dc,DAT_041051e8);
      goto LAB_0410460a;
    }
    if (0x10 < uVar16) {
      iVar15 = 8;
      FUN_04109118(0x42,DAT_041058d8,DAT_041058d4,uVar16,uVar14);
      goto LAB_0410460a;
    }
    if (((uVar16 | uVar34) & 3) == 0) {
      if (uVar16 >> 2 != 0) {
        uVar14 = 0;
        pcVar20 = DAT_041051cc;
        do {
          uVar14 = uVar14 + 1;
          *(uint *)(pcVar20 + (uVar34 - (int)pcVar7)) =
               (uint)(byte)pcVar20[10] << 0x10 | (uint)(byte)pcVar20[9] << 8 |
               (uint)(byte)pcVar20[8] | (uint)(byte)pcVar20[0xb] << 0x18;
          pcVar20 = pcVar20 + 4;
        } while (uVar16 >> 2 != uVar14);
      }
    }
    else if ((int)((uVar16 | uVar34) << 0x1f) < 0) {
      FUN_0410ef70(uVar34,DAT_04104e38,uVar16);
    }
    else if (uVar16 >> 1 != 0) {
      pcVar20 = DAT_041051cc;
      do {
        *(undefined2 *)(pcVar20 + (uVar34 - (int)pcVar7)) = *(undefined2 *)(pcVar20 + 8);
        pcVar20 = pcVar20 + 2;
      } while (pcVar20 != pcVar7 + (uVar16 >> 1) * 2);
    }
    local_44 = 0;
    FUN_041040e0(&local_44,1);
LAB_041046fc:
    uVar14 = 4;
    *pbVar9 = 0;
    FUN_0410ef64(pcVar7,0,4);
    bVar19 = *pbVar9;
    pcVar20 = pcVar7;
    break;
  case 3:
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_04104e28,uVar14 >> 4,DAT_04104e3c);
    iVar15 = *(int *)(pcVar7 + 4);
    uVar14 = *(uint *)(pcVar7 + 8);
    FUN_04109118(0x43,DAT_04104e34,DAT_04104e40,iVar15,uVar14);
    iVar25 = FUN_041061e8();
    if (iVar25 != 0) {
      local_44 = local_44 & 0xffffff00;
      FUN_041040e0(&local_44,1);
      if (uVar14 != 0) {
        do {
          uVar16 = uVar14;
          if (0xfff < uVar14) {
            uVar16 = 0x1000;
          }
          uVar14 = uVar14 - uVar16;
          iVar25 = FUN_041061f0(iVar15);
        } while ((iVar25 == 0) && (iVar15 = iVar15 + uVar16, uVar14 != 0));
        if (iVar25 != 0) {
          FUN_04109118(0x42,DAT_04104e44,DAT_04104e40,iVar25);
        }
      }
      goto LAB_041046fc;
    }
    iVar15 = 9;
    FUN_04109118(0x41,DAT_041051dc,DAT_041051d8);
    goto LAB_0410460a;
  default:
    goto switchD_0410467c_caseD_4;
  case 7:
switchD_0410467c_caseD_7:
    if (uVar14 == 0x67) {
      uVar16 = FUN_0410ad54();
      puVar30 = DAT_04105178;
      FUN_04109118(0x42,DAT_04105174,uVar16 >> 4,DAT_04105170);
      uVar16 = *(uint *)(pcVar7 + 0xc);
      uVar18 = *(undefined4 *)(pcVar7 + 4);
      uVar34 = *(uint *)(pcVar7 + 8);
      *DAT_0410517c = uVar18;
      puVar35 = DAT_04105180;
      *puVar30 = uVar34;
      *puVar35 = uVar16;
      FUN_04109118(0x43,DAT_04105184,uVar18,uVar34,uVar16);
    }
    else {
      uVar16 = FUN_0410ad54();
      puVar30 = DAT_04104e50;
      FUN_04109118(0x42,DAT_04104e28,uVar16 >> 4,DAT_04104e4c);
      puVar10 = DAT_04104e58;
      puVar35 = DAT_04104e54;
      uVar16 = *(uint *)(pcVar7 + 0xc);
      *DAT_04104e54 = uVar16;
      uVar18 = DAT_04104e5c;
      uVar22 = *(undefined4 *)(pcVar7 + 4);
      uVar34 = *(uint *)(pcVar7 + 8);
      *puVar10 = uVar22;
      *puVar30 = uVar34;
      FUN_04109118(0x43,uVar18,uVar22,uVar34,uVar16);
      if (uVar14 == 7) {
        bVar23 = false;
        goto LAB_04104f8a;
      }
    }
    if (*puVar30 < 0x1001) {
      FUN_041040e0(&local_53,1);
      uVar16 = *puVar30;
      if (uVar16 != 0) {
        *DAT_04105188 = 0;
        *DAT_0410518c = 1;
        if (uVar14 == 0x67) {
LAB_04104eda:
          *pbVar8 = 2;
        }
        else {
          *pbVar8 = 3;
        }
        *DAT_04105194 = DAT_04105190;
LAB_04105026:
        pcVar20 = DAT_041051ac;
        uVar14 = uVar16 + 0x10;
        iVar15 = FUN_041061c0(0);
        iVar25 = FUN_041061c0(2);
        *DAT_041051c0 = iVar25 * (uVar16 + 0x100f >> 0xc) + iVar15;
        goto LAB_041044d4;
      }
LAB_0410508e:
      FUN_04109118(0x40,DAT_041051d0);
      goto LAB_041046fc;
    }
    iVar15 = 100;
    FUN_04109118(0x41,DAT_04105c38,0x1000,*puVar30,uVar16);
    goto LAB_0410460a;
  case 9:
    uVar14 = FUN_0410ad54();
    puVar30 = DAT_04104b50;
    FUN_04109118(0x42,DAT_04104b40,uVar14 >> 4,DAT_04104b4c);
    puVar10 = DAT_04104b54;
    uVar22 = *(undefined4 *)(pcVar7 + 0xc);
    *DAT_04104b58 = uVar22;
    uVar18 = DAT_04104b5c;
    uVar26 = *(undefined4 *)(pcVar7 + 4);
    uVar14 = *(uint *)(pcVar7 + 8);
    *puVar30 = uVar14;
    *puVar10 = uVar26;
    FUN_04109118(0x43,uVar18,uVar26,uVar14,uVar22);
    FUN_041040e0(&local_53,1);
    uVar14 = *puVar30;
    if (uVar14 == 0) {
      FUN_04109118(0x40,DAT_04104b60);
      goto LAB_041046fc;
    }
    pcVar20 = (char *)*puVar10;
    *DAT_04105194 = uVar14;
    *pbVar8 = 4;
LAB_0410490a:
    iVar15 = FUN_041061c0(0);
    iVar25 = FUN_041061c0(2);
    *DAT_04104b28 = iVar25 * (uVar14 + 0xfff >> 0xc) + iVar15;
LAB_041044d4:
    *pbVar9 = 2;
LAB_041044de:
    local_50 = 0;
    FUN_041061b4(*DAT_0410458c);
    iVar15 = FUN_041062d0(pcVar20,*DAT_04104588,uVar14,&local_50);
    uVar16 = local_44;
    goto joined_r0x04104330;
  }
  goto LAB_041042fe;
LAB_041045a8:
  if (3 < uVar14 - 1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_04105c4c);
  }
  if (*pcVar7 != -0x42) goto code_r0x041045ba;
  uVar14 = (uint)(byte)pcVar7[3];
  if (0x15 < uVar14) goto LAB_04104608;
  uVar34 = (uint)(byte)pcVar7[1];
  if (uVar34 < 10) {
    switch(uVar34) {
    case 0:
      if ((uVar14 & 0xfb) != 1) {
        iVar15 = 1;
        goto LAB_0410460a;
      }
      break;
    case 1:
      if (uVar14 == 5) {
        uVar14 = 6;
        goto LAB_04104d5e;
      }
      goto LAB_04104608;
    case 2:
      if (0xf < uVar14 - 5) goto LAB_04104608;
      break;
    case 3:
      if (uVar14 != 8) goto LAB_04104608;
      uVar14 = 9;
      goto LAB_04104d5e;
    default:
      goto switchD_0410472e_caseD_4;
    case 7:
    case 9:
switchD_0410472e_caseD_7:
      if (uVar14 != 0xc) goto LAB_04104608;
      uVar14 = 0xd;
      goto LAB_04104d5e;
    case 8:
switchD_0410472e_caseD_8:
      iVar15 = 99;
      goto LAB_0410460a;
    }
switchD_0410476c_caseD_4:
    uVar14 = uVar14 + 1 & 0xff;
  }
  else {
    if ((uVar34 - 0x61 & 0xff) < 8) {
      switch(uVar34 - 0x61) {
      case 0:
      case 6:
        goto switchD_0410472e_caseD_7;
      case 1:
      case 7:
        goto switchD_0410472e_caseD_8;
      case 4:
        goto switchD_0410476c_caseD_4;
      case 5:
        if (uVar14 == 4) {
          uVar14 = 5;
          goto LAB_04104d5e;
        }
        goto LAB_04104608;
      }
    }
switchD_0410472e_caseD_4:
    local_40 = pcVar7;
    local_44 = (uint)local_44._1_3_ << 8;
    iVar15 = FUN_0410613c(&local_44);
    if (iVar15 == 0xf) {
      FUN_04109118(0x41,DAT_04105518,pcVar7[1]);
      goto LAB_0410460a;
    }
    if (iVar15 != 0) goto LAB_0410460a;
    uVar16 = local_44;
    if (0x15 < (byte)pcVar7[3]) {
LAB_04104608:
      local_44 = uVar16;
      iVar15 = 1;
LAB_0410460a:
      FUN_0410655c();
      local_44 = CONCAT31(local_44._1_3_,(char)iVar15);
      FUN_041040e0(&local_44,1);
      FUN_04109118(0x40,DAT_0410483c);
      goto LAB_04104622;
    }
    uVar14 = (uint)(byte)(pcVar7[3] + 1);
  }
LAB_04104d5e:
  pcVar20 = DAT_04104e60;
  *pbVar9 = 1;
  goto LAB_04104316;
code_r0x041045ba:
  if (uVar14 != 1) {
    uVar16 = 1;
    pcVar20 = DAT_04104838;
    do {
      if (*pcVar20 == -0x42) {
        iVar15 = uVar14 - uVar16;
        FUN_0410ef7c(pcVar7,pcVar20,iVar15);
        bVar19 = *pbVar9;
        goto LAB_041045e4;
      }
      uVar16 = uVar16 + 1;
      pcVar20 = pcVar20 + 1;
    } while (uVar14 != uVar16);
  }
  iVar15 = 0;
  bVar19 = 0;
  uVar16 = uVar14;
LAB_041045e4:
  pcVar20 = pcVar7 + iVar15;
  uVar14 = (4 - uVar14) + uVar16;
  goto LAB_041042fe;
switchD_041046a6_caseD_4:
  uVar14 = FUN_0410ad54();
  FUN_04109118(0x42,DAT_04104b40,uVar14 >> 4,DAT_04104b48);
  cVar13 = pcVar7[4];
  uVar14 = (uint)(byte)pcVar7[3];
  local_52 = 0;
  iVar25 = uVar14 - 1;
  iVar15 = 1;
  switch(cVar13) {
  case '\x11':
    uVar16 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_0410588c,uVar16 >> 4,DAT_041058b0);
    if ((uVar14 & 0xfd) == 1) {
      if (iVar25 == 0) {
        cVar13 = -1;
        cVar32 = -1;
      }
      else if (iVar25 == 2) {
        cVar13 = pcVar7[5];
        cVar32 = pcVar7[6];
      }
      else {
        uVar18 = *(undefined4 *)(pcVar7 + 5);
        if (iVar25 == 4) goto LAB_041056be;
        cVar32 = '\0';
        cVar13 = '\0';
      }
      FUN_04106630(cVar13,cVar32,(int)&local_44 + 1,3);
      uVar14 = local_44 >> 0x10 & 0xff;
      uVar16 = local_44 >> 8 & 0xff;
      FUN_04109118(0x45,DAT_041058e4,cVar13,cVar32,uVar16,uVar14,local_44 >> 0x18);
    }
    else {
      if (iVar25 != 4) {
        uVar18 = 1;
        FUN_04109118(0x42,DAT_04105c40,DAT_04105c3c,iVar25);
        break;
      }
      uVar18 = *(undefined4 *)(pcVar7 + 5);
LAB_041056be:
      FUN_04106648(uVar18,(int)&local_44 + 1,3);
      uVar14 = local_44 >> 0x18;
      uVar16 = local_44 >> 0x10 & 0xff;
      FUN_04109118(0x44,DAT_041058b4,uVar18,local_44._1_1_,uVar16,uVar14);
    }
    uVar34 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_041058ac,uVar34 >> 4,DAT_041058b0,uVar16,uVar14);
    local_44 = local_44 & 0xffffff00;
    FUN_041040e0(&local_44,4);
    goto LAB_0410542c;
  case '\x12':
    uVar16 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_0410588c,uVar16 >> 4,DAT_041058a0);
    if ((uVar14 & 0xfd) == 1) {
      if (iVar25 == 0) {
        cVar13 = -1;
        cVar32 = -1;
      }
      else if (iVar25 == 2) {
        cVar13 = pcVar7[5];
        cVar32 = pcVar7[6];
      }
      else {
        uVar18 = *(undefined4 *)(pcVar7 + 5);
        if (iVar25 == 4) goto LAB_04105652;
        cVar32 = '\0';
        cVar13 = '\0';
      }
      FUN_04106680(cVar13,cVar32,(int)&local_44 + 1,0x10);
      FUN_04109118(0x42,DAT_041058e0,cVar13,cVar32);
    }
    else {
      if (iVar25 != 4) {
        uVar18 = 1;
        FUN_04109118(0x42,DAT_04105c40,DAT_04105c94,iVar25);
        break;
      }
      uVar18 = *(undefined4 *)(pcVar7 + 5);
LAB_04105652:
      FUN_041066b8(uVar18,(int)&local_44 + 1,0x10);
      FUN_04109118(0x41,DAT_041058a4,uVar18);
    }
    FUN_04109318(0,DAT_041058a8,1,0x10,(int)&local_44 + 1);
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_041058ac,uVar14 >> 4,DAT_041058a0);
    local_44 = local_44 & 0xffffff00;
    FUN_041040e0(&local_44,0x11);
    goto LAB_0410542c;
  case '\x13':
    uVar16 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_0410588c,uVar16 >> 4,DAT_041058b8);
    if ((uVar14 & 0xfd) == 1) {
      if (iVar25 == 0) {
        cVar13 = -1;
        cVar32 = -1;
      }
      else if (iVar25 == 2) {
        cVar13 = pcVar7[5];
        cVar32 = pcVar7[6];
      }
      else {
        uVar18 = *(undefined4 *)(pcVar7 + 5);
        if (iVar25 == 4) goto LAB_0410572a;
        cVar32 = '\0';
        cVar13 = '\0';
      }
      FUN_041066f0(cVar13,cVar32,&local_48);
      FUN_04109118(0x43,DAT_04105c34,cVar13,cVar32,local_48);
    }
    else {
      if (iVar25 != 4) {
        uVar18 = 1;
        FUN_04109118(0x42,DAT_04105c40,DAT_04105c84,iVar25);
        break;
      }
      uVar18 = *(undefined4 *)(pcVar7 + 5);
LAB_0410572a:
      FUN_04106728(uVar18,&local_48);
      FUN_04109118(0x42,DAT_041058bc,uVar18,local_48);
    }
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_041058ac,uVar14 >> 4,DAT_041058b8);
    local_44 = (local_48 & 0xff) << 8;
    local_44 = CONCAT13((char)(local_48 >> 0x10),
                        CONCAT12((char)(local_48 >> 8),(undefined2)local_44));
    local_40 = (char *)CONCAT31(local_40._1_3_,(char)(local_48 >> 0x18));
    FUN_041040e0(&local_44,5);
    goto LAB_0410542c;
  case '\x14':
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_04105544,uVar14 >> 4,DAT_04105570);
    if (iVar25 != 0) {
      uVar18 = 1;
      FUN_04109118(0x42,DAT_04105c40,DAT_04105c58,iVar25);
      break;
    }
    FUN_04106768(&local_51,&local_4c,&local_48);
    FUN_04109118(0x43,DAT_04105574,local_51,local_4c & 0xff,local_48 & 0xff);
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_04105568,uVar14 >> 4,DAT_04105570);
    local_44 = (uint)CONCAT12((undefined1)local_48,CONCAT11((undefined1)local_4c,local_51)) << 8;
    FUN_041040e0(&local_44,4);
    goto LAB_0410542c;
  default:
    uVar18 = 0x6a;
    iVar15 = 0x6a;
    FUN_04109118(0x41,DAT_041051ec);
    break;
  case '!':
  case 'A':
  case 'C':
    if (cVar13 == '!') {
      uVar14 = FUN_0410ad54();
      FUN_04109118(0x42,DAT_04105c64,uVar14 >> 4,DAT_04105c80);
      uVar22 = DAT_04105c80;
      if (iVar25 != 8) goto LAB_04105990;
      uVar18 = *(undefined4 *)(pcVar7 + 5);
      local_48 = *(uint *)(pcVar7 + 9);
      FUN_04109118(0x42,DAT_04105c7c,uVar18);
      uVar22 = DAT_04105c80;
      iVar15 = FUN_041067a8(uVar18,local_48);
    }
    else if (cVar13 == 'A') {
      uVar14 = FUN_0410ad54();
      FUN_04109118(0x42,DAT_04105c64,uVar14 >> 4,DAT_04105c78);
      uVar22 = DAT_04105c78;
      if (iVar25 != 8) goto LAB_04105990;
      uVar18 = *(undefined4 *)(pcVar7 + 5);
      local_48 = *(uint *)(pcVar7 + 9);
      FUN_04109118(0x42,DAT_04105c7c,uVar18);
      uVar22 = DAT_04105c78;
      iVar15 = FUN_04106b78(uVar18,local_48);
    }
    else {
      uVar14 = FUN_0410ad54();
      FUN_04109118(0x42,DAT_04105544,uVar14 >> 4,DAT_04105558);
      uVar22 = DAT_04105c48;
      if (iVar25 != 8) goto LAB_04105990;
      uVar18 = *(undefined4 *)(pcVar7 + 5);
      local_48 = *(uint *)(pcVar7 + 9);
      FUN_04109118(0x42,DAT_0410555c,uVar18);
      uVar22 = DAT_04105558;
      iVar15 = FUN_04106bb0(uVar18,local_48);
    }
    if (iVar15 != 0) {
      uVar18 = 0x67;
      uVar14 = FUN_0410ad54();
      iVar15 = 0x67;
      FUN_04109118(0x42,DAT_04105c90,uVar14 >> 4,uVar22);
      break;
    }
    uVar14 = FUN_0410ad54();
    uVar14 = uVar14 >> 4;
LAB_04105502:
    FUN_04109118(0x42,DAT_04105568,uVar14,uVar22);
    FUN_041040e0(&local_52,1);
LAB_0410542c:
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_0410556c,uVar14 >> 4,0);
    goto LAB_041046fc;
  case '\"':
  case 'B':
    if (cVar13 == '\"') {
      uVar16 = FUN_0410ad54();
      FUN_04109118(0x42,DAT_04105c64,uVar16 >> 4,DAT_04105c60);
      uVar22 = DAT_04105c60;
      if (0xf < uVar14 - 6) goto LAB_04105990;
      uVar18 = *(undefined4 *)(pcVar7 + 5);
      iVar25 = uVar14 - 5;
      FUN_04109118(0x42,DAT_04105c68,uVar18,iVar25);
      iVar15 = FUN_04106844(uVar18,DAT_04105c6c,iVar25);
      uVar22 = DAT_04105c60;
      if (iVar15 != 0) goto LAB_04105ba4;
      uVar14 = FUN_0410ad54();
      FUN_04109118(0x42,DAT_04105c70,uVar14 >> 4,DAT_04105c60);
      iVar15 = FUN_041068bc(uVar18,DAT_04105c6c,iVar25);
      uVar22 = DAT_04105c60;
LAB_04105352:
      if (iVar15 == 0) {
        uVar14 = FUN_0410ad54();
        uVar14 = uVar14 >> 4;
        goto LAB_04105502;
      }
      uVar18 = 0x69;
      iVar15 = 0x69;
      FUN_04109118(0x41,DAT_04105c98,uVar22);
    }
    else {
      uVar16 = FUN_0410ad54();
      FUN_04109118(0x42,DAT_04105544,uVar16 >> 4,DAT_04105540);
      uVar22 = DAT_04105c5c;
      if (uVar14 - 6 < 0x10) {
        uVar18 = *(undefined4 *)(pcVar7 + 5);
        iVar25 = uVar14 - 5;
        FUN_04109118(0x42,DAT_04105548,uVar18,iVar25);
        iVar15 = FUN_04106be8(uVar18,DAT_0410554c,iVar25);
        uVar22 = DAT_04105c5c;
        if (iVar15 == 0) {
          uVar14 = FUN_0410ad54();
          FUN_04109118(0x42,DAT_04105550,uVar14 >> 4,DAT_04105540);
          iVar15 = FUN_04106c24(uVar18,DAT_04105554,DAT_0410554c,iVar25);
          uVar22 = DAT_04105540;
          goto LAB_04105352;
        }
LAB_04105ba4:
        uVar18 = 0x68;
        uVar14 = FUN_0410ad54();
        iVar15 = 0x68;
        FUN_04109118(0x42,DAT_04105c90,uVar14 >> 4,uVar22);
      }
      else {
LAB_04105990:
        uVar18 = 1;
        FUN_04109118(0x42,DAT_04105c40,uVar22,iVar25);
      }
    }
    break;
  case '1':
    uVar16 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_0410588c,uVar16 >> 4,DAT_04105888);
    if ((uVar14 & 0xfd) == 1) {
      if (iVar25 == 0) {
LAB_04105b70:
        cVar13 = '\0';
        cVar32 = cVar13;
      }
      else {
        if (iVar25 != 2) {
          uVar18 = *(undefined4 *)(pcVar7 + 5);
          if (iVar25 == 4) goto LAB_041055a2;
          goto LAB_04105b70;
        }
        cVar13 = pcVar7[5];
        cVar32 = pcVar7[6];
      }
      iVar15 = FUN_04106808(cVar13,cVar32);
    }
    else {
      if (iVar25 != 4) {
        uVar18 = 1;
        FUN_04109118(0x42,DAT_04105c40,DAT_04105c44,iVar25);
        break;
      }
      uVar18 = *(undefined4 *)(pcVar7 + 5);
LAB_041055a2:
      iVar15 = FUN_0410681c(uVar18);
    }
    if (iVar15 == 0) {
      uVar14 = FUN_0410ad54();
      uVar14 = uVar14 >> 4;
      uVar22 = DAT_04105888;
      goto LAB_04105502;
    }
    uVar18 = 0x67;
    uVar14 = FUN_0410ad54();
    iVar15 = 0x67;
    FUN_04109118(0x42,DAT_04105c90,uVar14 >> 4,DAT_04105c44);
    break;
  case 'D':
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_0410588c,uVar14 >> 4,DAT_04105894);
    if (iVar25 == 5) {
      uVar18 = *(undefined4 *)(pcVar7 + 5);
      local_48 = (uint)(byte)pcVar7[9];
      FUN_04109118(0x42,DAT_041058c0,uVar18);
      iVar15 = FUN_04104154(0x4465,uVar18,local_48);
      uVar14 = FUN_0410ad54();
      FUN_04109118(0x42,DAT_041058c4,uVar14 >> 4,iVar15);
      goto joined_r0x041057ac;
    }
    uVar18 = 1;
    FUN_04109118(0x42,DAT_04105898,DAT_04105894,iVar25);
    break;
  case 'Q':
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_0410588c,uVar14 >> 4,DAT_0410589c);
    if (iVar25 == 0xd) {
      uVar18 = *(undefined4 *)(pcVar7 + 9);
      uVar31 = *(undefined4 *)(pcVar7 + 5);
      uVar33 = *(undefined4 *)(pcVar7 + 0xd);
      uVar16 = (uint)(byte)pcVar7[0x11];
      uVar22 = uVar18;
      uVar26 = uVar33;
      uVar14 = uVar16;
      FUN_04109118(0x45,DAT_04105c2c,uVar31,uVar18,uVar18,uVar33,uVar16);
      iVar15 = FUN_041069bc(uVar31,uVar18,uVar33,uVar16);
      if (iVar15 == 0) {
        uVar14 = FUN_0410ad54();
        uVar14 = uVar14 >> 4;
        uVar22 = DAT_04105c30;
        goto LAB_04105502;
      }
      iVar15 = 0xff;
      uVar16 = FUN_0410ad54();
      uVar18 = 0xff;
      FUN_04109118(0x42,DAT_04105d00,uVar16 >> 4,DAT_04105d04,uVar22,uVar26,uVar14);
    }
    else {
      uVar18 = 1;
      FUN_04109118(0x42,DAT_04105898,DAT_0410589c,iVar25);
    }
    break;
  case 'R':
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_0410588c,uVar14 >> 4,DAT_04105890);
    if (iVar25 == 0) {
      iVar15 = FUN_04106a1c();
      if (iVar15 == 0) {
        uVar14 = FUN_0410ad54();
        uVar14 = uVar14 >> 4;
        uVar22 = DAT_04105890;
        goto LAB_04105502;
      }
      iVar15 = 0xff;
      uVar14 = FUN_0410ad54();
      uVar18 = 0xff;
      FUN_04109118(0x42,DAT_04105d00,uVar14 >> 4,DAT_04105cfc);
    }
    else {
      uVar18 = 1;
      FUN_04109118(0x42,DAT_04105c40,DAT_04105c8c,iVar25);
    }
    break;
  case 'a':
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_04105544,uVar14 >> 4,DAT_04105578);
    if (iVar25 == 3) {
      cVar13 = pcVar7[5];
      cVar32 = pcVar7[6];
      uVar16 = (uint)(byte)pcVar7[7];
      uVar14 = uVar16;
      FUN_04109118(0x43,DAT_04105c54,cVar13,cVar32,uVar16);
      iVar15 = FUN_04106a38(cVar13,cVar32,uVar16);
    }
    else {
      if (iVar25 != 6) {
        uVar18 = 1;
        FUN_04109118(0x42,DAT_04105c40,DAT_04105c74,iVar25);
        break;
      }
      uVar18 = *(undefined4 *)(pcVar7 + 5);
      cVar13 = pcVar7[9];
      uVar16 = (uint)(byte)pcVar7[10];
      uVar14 = uVar16;
      FUN_04109118(0x43,DAT_04105564,uVar18,cVar13,uVar16);
      iVar15 = FUN_04106a4c(uVar18,cVar13,uVar16);
    }
    if (iVar15 == 0) {
      uVar14 = FUN_0410ad54();
      uVar14 = uVar14 >> 4;
      uVar22 = DAT_04105578;
      goto LAB_04105502;
    }
    iVar15 = 0xff;
    uVar16 = FUN_0410ad54();
    uVar18 = 0xff;
    FUN_04109118(0x42,DAT_04105c90,uVar16 >> 4,DAT_04105c74,uVar14);
    break;
  case 'b':
    uVar14 = FUN_0410ad54();
    FUN_04109118(0x42,DAT_04105544,uVar14 >> 4,DAT_04105560);
    if (iVar25 == 1) {
      cVar13 = pcVar7[5];
      iVar15 = FUN_04106a7c(cVar13,&local_4c,&local_48);
      if (iVar15 == 0) {
        uVar14 = local_48 & 0xff;
        FUN_04109118(0x43,DAT_04105c54,cVar13,local_4c & 0xff,uVar14);
        goto LAB_041053fe;
      }
LAB_04105bd4:
      uVar14 = FUN_0410ad54();
      uVar18 = 0xff;
      FUN_04109118(0x42,DAT_04105c90,uVar14 >> 4,DAT_04105c50);
      iVar15 = 0xff;
    }
    else {
      if (iVar25 == 4) {
        uVar18 = *(undefined4 *)(pcVar7 + 5);
        iVar15 = FUN_04106aa8(uVar18,&local_4c,&local_48);
        if (iVar15 != 0) goto LAB_04105bd4;
        uVar14 = local_48 & 0xff;
        FUN_04109118(0x43,DAT_04105564,uVar18,local_4c & 0xff,uVar14);
LAB_041053fe:
        uVar16 = FUN_0410ad54();
        FUN_04109118(0x42,DAT_04105568,uVar16 >> 4,DAT_04105560,uVar14);
        local_44 = (uint)CONCAT12((char)(local_44 >> 0x18),
                                  CONCAT11((undefined1)local_48,(undefined1)local_4c)) << 8;
        FUN_041040e0(&local_44,3);
        goto LAB_0410542c;
      }
      uVar18 = 1;
      iVar15 = 1;
      FUN_04109118(0x42,DAT_04105c40,DAT_04105c50,iVar25);
    }
  }
  uVar14 = FUN_0410ad54();
  FUN_04109118(0x42,DAT_041051f0,uVar14 >> 4,uVar18);
  goto LAB_0410460a;
}



// ===========================================================
// Function: FUN_04105d7c at 04105d7c
// ===========================================================

void FUN_04105d7c(void)

{
  int iVar1;
  undefined4 local_c [2];
  
  do {
    iVar1 = FUN_04103d50(local_c);
    while (iVar1 == 0) {
      FUN_04103dbc(local_c[0]);
      iVar1 = FUN_04103d50(local_c);
    }
    FUN_04106ed0();
  } while( true );
}



// ===========================================================
// Function: FUN_04105da0 at 04105da0
// ===========================================================

void FUN_04105da0(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (uint)param_1 & 0xffffffe0;
  FUN_04109118(0x8042,DAT_04105e30,3,param_1);
  uVar2 = DAT_04105e38;
  uVar1 = DAT_04105e34;
  uVar3 = uVar4 ^ 0x1000;
  FUN_0410db38(1,uVar4,0x20);
  FUN_0410db38(1,uVar3,0x20);
  FUN_04109118(uVar2,uVar1,*param_1,*(undefined1 *)((uint)param_1 ^ 0x1000));
  FUN_0410db38(1,uVar4,0x20);
  FUN_0410db38(1,uVar3,0x20);
  FUN_04109118(uVar2,uVar1,*param_1,*(undefined1 *)((uint)param_1 ^ 0x1000));
  FUN_0410db38(1,uVar4,0x20);
  FUN_0410db38(1,uVar3,0x20);
  FUN_04109118(DAT_04105e3c,uVar1,*param_1,param_4);
  return;
}



// ===========================================================
// Function: FUN_04105e78 at 04105e78
// ===========================================================

void FUN_04105e78(void)

{
  byte bVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int *piVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  undefined1 local_60;
  undefined1 local_5f;
  undefined1 local_5e;
  undefined1 local_5c;
  undefined1 local_5b;
  undefined1 local_5a;
  byte local_58;
  undefined1 local_57;
  undefined1 local_56;
  undefined1 auStack_55 [5];
  undefined1 auStack_50 [20];
  undefined1 auStack_3c [24];
  
  uVar8 = FUN_0410aa34();
  bVar13 = (uVar8 & 0x200) == 0;
  *DAT_041060b0 = !bVar13;
  piVar6 = DAT_041060ec;
  pcVar5 = DAT_041060e8;
  pcVar3 = DAT_041060b4;
  if (bVar13) {
    if (*DAT_041060e8 == '\0') {
      if (*DAT_041060ec == 0) {
        iVar9 = FUN_04103a90(DAT_04106104);
        *piVar6 = iVar9;
      }
      piVar6 = DAT_041060f0;
      if (*DAT_041060f0 == 0) {
        iVar9 = FUN_04103a90(DAT_04106100);
        *piVar6 = iVar9;
      }
      FUN_04100e3c(0,DAT_041060f4);
      *pcVar5 = '\x01';
    }
  }
  else if (*DAT_041060b4 == '\0') {
    FUN_0410b8a0(0,DAT_041060f8);
    FUN_0410bae4(0,DAT_041060fc,0);
    FUN_0410ba98(0,0x200);
    *pcVar3 = '\x01';
  }
  iVar9 = FUN_04106e64(0,0,DAT_041060b8,1,0);
  if (iVar9 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410610c,iVar9);
  }
  FUN_0410ef64(DAT_041060bc,0xcc,0x810);
  iVar9 = FUN_04106e64(1,DAT_041060bc + 0x800,DAT_041060bc,2,DAT_041060c0);
  if (iVar9 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_04106108,iVar9);
  }
  uVar10 = FUN_0410a800();
  uVar2 = DAT_04106118;
  pbVar7 = DAT_04106114;
  iVar9 = -1;
  uVar8 = 0;
  do {
    uVar12 = uVar8 & 0xff;
    iVar11 = FUN_0410a62c(uVar12,uVar10);
    if (uVar8 == 0) {
      FUN_04109f78(0,&local_60,&local_5c,3);
      FUN_04109118(0x47,DAT_041060dc,0,local_60,local_5f,local_5e,local_5c,local_5b,local_5a);
      if (iVar11 != 0) goto LAB_0410600a;
      FUN_0410a004(0,auStack_50,auStack_3c,0x12);
      FUN_04109118(0x41,DAT_041060e0,0);
      FUN_04109318(0,uVar2,1,0x12,auStack_50);
      FUN_04109118(0x41,DAT_041060e4,0);
      FUN_04109318(0,uVar2,1,0x12,auStack_3c);
    }
    else {
      FUN_04109f44(uVar12,&local_60,3);
      FUN_04109118(0x44,DAT_041060c4,uVar8,local_60,local_5f,local_5e);
      if (iVar11 == 0) {
        FUN_04109fbc(uVar12,auStack_50,0x12);
        FUN_04109118(0x41,DAT_041060c8,uVar8);
        FUN_04109318(0,uVar2,1,0x12,auStack_50);
      }
      else {
LAB_0410600a:
        local_58 = *pbVar7;
        local_57 = (undefined1)uVar8;
        local_56 = (undefined1)iVar11;
        FUN_0410ef70(auStack_55,&local_60,3);
        FUN_04104078(&local_58,6);
        if (*DAT_041060b0 == '\x01') {
          FUN_0410ad60(0x10);
        }
      }
    }
    FUN_0410a644(uVar12);
    FUN_0410a640(uVar12);
    *(bool *)(DAT_041060cc + uVar8) = iVar11 == 0;
    uVar8 = uVar8 + 1;
    bVar1 = *pbVar7;
    if (bVar1 == uVar12) {
      iVar9 = iVar11;
    }
    if (uVar8 == 3) {
      *DAT_041060d0 = bVar1;
      puVar4 = DAT_041060d4;
      uVar2 = DAT_04104060;
      if (iVar9 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_04109484(DAT_04106110,iVar9);
      }
      *DAT_041060d8 = DAT_0410405c;
      *puVar4 = uVar2;
      return;
    }
  } while( true );
}



// ===========================================================
// Function: FUN_0410611c at 0410611c
// ===========================================================

void FUN_0410611c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = DAT_04106138;
  for (puVar2 = DAT_04106134; puVar2 < puVar1; puVar2 = puVar2 + 1) {
    (*(code *)*puVar2)();
  }
  return;
}



// ===========================================================
// Function: FUN_0410613c at 0410613c
// ===========================================================

int FUN_0410613c(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = DAT_04106164;
  puVar3 = DAT_04106160;
  if (DAT_04106164 <= DAT_04106160) {
    return 0xf;
  }
  do {
    puVar4 = puVar3 + 1;
    iVar2 = (*(code *)*puVar3)(param_1);
    if (iVar2 != 0xf) {
      return iVar2;
    }
    puVar3 = puVar4;
  } while (puVar4 < puVar1);
  return 0xf;
}



// ===========================================================
// Function: FUN_04106168 at 04106168
// ===========================================================

void FUN_04106168(void)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 in_r3;
  
  puVar3 = DAT_041061a4;
  pcVar2 = DAT_041061a0;
  cVar1 = *DAT_041061a0;
  *DAT_041061a4 = 0;
  if (cVar1 == '\0') {
    FUN_04100fc0(0);
    FUN_04100f44(0,0);
  }
  else {
    FUN_0410ba3c(0,0,pcVar2,puVar3,in_r3);
    *DAT_041061b0 = 0;
  }
  puVar4 = DAT_041061ac;
  *DAT_041061a8 = 8000;
  *puVar4 = 8000;
  return;
}



// ===========================================================
// Function: FUN_041061b4 at 041061b4
// ===========================================================

void FUN_041061b4(undefined4 param_1)

{
  *DAT_041061bc = param_1;
  return;
}



// ===========================================================
// Function: FUN_041061c0 at 041061c0
// ===========================================================

undefined4 FUN_041061c0(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      return 0xffffffff;
    }
    if (1 < param_1 - 2U) {
      uVar1 = DAT_041061e4;
      if (param_1 != 4) {
        uVar1 = 0;
      }
      return uVar1;
    }
  }
  return 8000;
}



// ===========================================================
// Function: FUN_041061e8 at 041061e8
// ===========================================================

undefined4 FUN_041061e8(void)

{
  return 1;
}



// ===========================================================
// Function: FUN_041061ec at 041061ec
// ===========================================================

undefined4 FUN_041061ec(void)

{
  return 1;
}



// ===========================================================
// Function: FUN_041061f0 at 041061f0
// ===========================================================

uint FUN_041061f0(int param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 extraout_r3;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  
  puVar3 = DAT_041062cc;
  pcVar1 = DAT_041062c0;
  if (*DAT_041062c0 == '\0') {
    if (*DAT_041062c4 != '\0') {
      iVar4 = FUN_0410ad54();
      puVar2 = DAT_041062c8;
      if (param_2 == (undefined1 *)0x0) {
        puVar9 = (undefined1 *)0x0;
      }
      else {
        puVar8 = (undefined1 *)(param_1 + -1);
LAB_04106240:
        do {
          if (((*pcVar1 == '\0') && (iVar5 = FUN_0410b97c(0), iVar5 == 0)) &&
             ((*puVar2 == 0xffffffff || (iVar5 = FUN_0410ad54(), (uint)(iVar5 - iVar4) < *puVar2))))
          {
            iVar5 = FUN_04106ed0();
            if (iVar5 != 0) goto LAB_04106240;
          }
          if (*pcVar1 != '\0') {
            return 1;
          }
          iVar5 = FUN_0410b97c(0);
          if (iVar5 == 0) {
            return 1;
          }
          puVar9 = puVar8 + (2 - param_1);
          puVar8 = puVar8 + 1;
          FUN_0410b9a8(0,*puVar8);
        } while (puVar8 != param_2 + param_1 + -1);
      }
      return (uint)(param_2 != puVar9);
    }
    uVar7 = 0;
    if (*DAT_041062c8 != 0xffffffff) {
      FUN_04103b0c(*DAT_041062cc);
      uVar7 = extraout_r3;
    }
    uVar6 = FUN_041013fc(0,param_1,param_2,uVar7,param_4);
    FUN_04103b40(*puVar3);
  }
  else {
    uVar6 = 0xffffffff;
  }
  return uVar6;
}



// ===========================================================
// Function: FUN_041062d0 at 041062d0
// ===========================================================

int FUN_041062d0(undefined4 param_1,int param_2,undefined4 param_3,uint *param_4)

{
  uint *puVar1;
  char *pcVar2;
  undefined4 *puVar3;
  uint *puVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  uint local_24;
  
  puVar3 = DAT_041064a8;
  pcVar2 = DAT_041064a4;
  if (*DAT_041064a4 == '\0') {
    if (*DAT_04106488 == '\0') {
      if (param_2 == 0) {
        if (*DAT_0410648c != 0xffffffff) {
          FUN_04103b0c(*DAT_041064a8);
        }
        iVar6 = FUN_04101050(0,param_1,param_3,param_4);
        FUN_04103b40(*puVar3);
        return iVar6;
      }
      if (*DAT_0410648c != 0xffffffff) {
        FUN_04103b0c(*DAT_041064a8);
      }
      iVar6 = FUN_041011d4(0,param_1,param_2,param_3,&local_24,0);
      FUN_04103b40(*puVar3);
      if (param_4 != (uint *)0x0) {
        *param_4 = local_24;
      }
    }
    else {
      if (param_4 != (uint *)0x0) {
        *param_4 = 0;
      }
      puVar4 = DAT_041064ac;
      if (*DAT_04106490 != '\0') {
        *DAT_04106490 = '\0';
        if (DAT_04106494 < *puVar4) {
          uVar9 = 0xf;
        }
        else {
          uVar9 = 0xb;
        }
        FUN_04108a3c(0,uVar9);
        iVar6 = FUN_0410ad54();
        do {
          iVar7 = FUN_0410b8a8(0,*puVar4);
          if (iVar7 == 0) break;
          iVar7 = FUN_0410ad54();
        } while ((uint)(iVar7 - iVar6) < 0xa0);
      }
      puVar4 = DAT_041064b4;
      pcVar5 = DAT_041064b0;
      if (*DAT_041064b0 == '\0') {
        *DAT_041064b0 = '\x01';
        *puVar4 = 0;
        iVar6 = FUN_04104064();
        if (iVar6 == 0) {
          local_24 = 0x21;
          uVar9 = DAT_041064a0;
        }
        else {
          local_24 = *DAT_04106498 >> 4;
          uVar9 = *DAT_0410649c;
        }
        iVar6 = FUN_0410bb1c(0,param_1,param_3,uVar9,&local_24);
        puVar1 = DAT_0410648c;
        if (iVar6 == 0) {
          FUN_0410ba98(0,0x780);
          iVar7 = FUN_0410ad54();
          do {
            if (((*pcVar5 != '\x01') || (*pcVar2 != '\0')) ||
               ((*puVar1 != 0xffffffff && (iVar8 = FUN_0410ad54(), *puVar1 <= (uint)(iVar8 - iVar7))
                ))) break;
            iVar8 = FUN_04106ed0();
          } while (iVar8 != 0);
          if (*pcVar2 == '\0') {
            if (*pcVar5 == '\x01') {
              iVar6 = -0xf;
            }
            else if (*pcVar5 != '\x02') {
              iVar6 = -2;
            }
          }
          else {
            iVar6 = -0xe;
          }
        }
        FUN_0410ba98(0,0x200);
        if (*pcVar5 != '\x02') {
          FUN_0410bb48(0);
        }
        if (param_4 != (uint *)0x0) {
          *param_4 = *puVar4;
        }
        *pcVar5 = '\0';
        return iVar6;
      }
      iVar6 = -3;
    }
  }
  else {
    iVar6 = -1;
  }
  return iVar6;
}



// ===========================================================
// Function: FUN_041064b8 at 041064b8
// ===========================================================

undefined4 FUN_041064b8(void)

{
  char *pcVar1;
  int iVar2;
  
  FUN_0410ad60(800);
  pcVar1 = DAT_04106550;
  if (*DAT_0410654c == '\0') {
    if (*DAT_04106550 != '\0') {
      FUN_04109118(0x40,DAT_04106554);
      if (*pcVar1 != '\0') {
        FUN_0410ba3c(0,0);
      }
      FUN_0410ad60(0x10);
      iVar2 = FUN_0410b97c(0);
      if (iVar2 != 0) {
        FUN_0410b9a8(0);
        FUN_0410ad60(0x20);
      }
      FUN_0410b9e4(0);
      FUN_0410ad60(0x20);
      FUN_0410ba10(0);
      FUN_0410ad60(0x640);
      return 0;
    }
    FUN_04109118(0x40,DAT_04106554);
    iVar2 = FUN_041015b4(0);
    if (iVar2 != 0) {
      FUN_04109118(0x41,DAT_04106558,iVar2);
    }
  }
  FUN_0410ad60(0x640);
  return 0;
}



// ===========================================================
// Function: FUN_0410655c at 0410655c
// ===========================================================

undefined4 FUN_0410655c(void)

{
  undefined4 uVar1;
  
  if (*DAT_04106578 == '\0') {
    uVar1 = FUN_04100fc0();
    return uVar1;
  }
  FUN_0410ba3c(0);
  return 0;
}



// ===========================================================
// Function: FUN_0410657c at 0410657c
// ===========================================================

void FUN_0410657c(void)

{
  FUN_0410ad60(0xa0);
  FUN_0410aae8();
  return;
}



// ===========================================================
// Function: FUN_0410658c at 0410658c
// ===========================================================

void FUN_0410658c(void)

{
  FUN_0410ad60(0xa0);
  FUN_041015e8(1);
  return;
}



// ===========================================================
// Function: FUN_0410659c at 0410659c
// ===========================================================

void FUN_0410659c(void)

{
  FUN_0410aa44(0x8000);
  FUN_0410aae8();
  return;
}



// ===========================================================
// Function: thunk_FUN_0410aa44 at 041065b0
// ===========================================================

void thunk_FUN_0410aa44(uint param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_lr;
  
  iVar3 = DAT_0410aa90;
  puVar2 = DAT_0410aa8c;
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_0410aa8c = 0x410aa58;
    puVar2[1] = unaff_lr;
    *(uint *)(iVar3 + 0x38) = (param_1 | *(uint *)(iVar3 + 0x38)) & 0xfffffff0;
    if (iVar4 == 0) {
      *puVar2 = 0xffffffff;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(iVar4);
    }
    return;
  }
  *(uint *)(DAT_0410aa90 + 0x38) = (param_1 | *(uint *)(DAT_0410aa90 + 0x38)) & 0xfffffff0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x40);
  }
  return;
}



// ===========================================================
// Function: thunk_FUN_0410aa94 at 041065b4
// ===========================================================

void thunk_FUN_0410aa94(uint param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_lr;
  
  iVar3 = DAT_0410aae4;
  puVar2 = DAT_0410aae0;
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_0410aae0 = 0x410aaa8;
    puVar2[1] = unaff_lr;
    *(uint *)(iVar3 + 0x38) = *(uint *)(iVar3 + 0x38) & ~param_1 & 0xfffffff0;
    if (iVar4 == 0) {
      *puVar2 = 0xffffffff;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(iVar4);
    }
    return;
  }
  *(uint *)(DAT_0410aae4 + 0x38) = *(uint *)(DAT_0410aae4 + 0x38) & ~param_1 & 0xfffffff0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x40);
  }
  return;
}



// ===========================================================
// Function: thunk_FUN_0410aa34 at 041065b8
// ===========================================================

uint thunk_FUN_0410aa34(void)

{
  return *(uint *)(DAT_0410aa40 + 0x38) & 0xfffffff0;
}



// ===========================================================
// Function: FUN_041065bc at 041065bc
// ===========================================================

void FUN_041065bc(undefined4 param_1)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_041065cc;
  *DAT_041065c8 = param_1;
  *puVar1 = 1;
  return;
}



// ===========================================================
// Function: FUN_041065d0 at 041065d0
// ===========================================================

int FUN_041065d0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_1c [2];
  
  uVar2 = FUN_0410a9c0();
  puVar1 = DAT_0410662c;
  if ((2 < uVar2) || (*(char *)(DAT_04106628 + uVar2) == '\0')) {
    return 0x12;
  }
  *DAT_0410662c = (char)uVar2;
  if (param_2 != (undefined4 *)0x0) {
    iVar3 = FUN_04109e9c(uVar2,param_1,0,&local_20);
    if (iVar3 != 0) {
      return iVar3;
    }
    *param_2 = local_20;
  }
  if (param_3 == (undefined4 *)0x0) {
    return 0;
  }
  FUN_04109e34(*puVar1,0,0,local_1c,0);
  *param_3 = local_1c[0];
  return 0;
}



// ===========================================================
// Function: FUN_04106630 at 04106630
// ===========================================================

void FUN_04106630(uint param_1,undefined4 param_2,undefined4 param_3,byte *param_4)

{
  byte *pbVar1;
  
  pbVar1 = param_4;
  if (2 < param_1) {
    param_1 = (uint)*DAT_04106644;
    pbVar1 = DAT_04106644;
  }
  FUN_04109f44(param_1,param_3,param_4,pbVar1,param_4);
  return;
}



// ===========================================================
// Function: FUN_04106648 at 04106648
// ===========================================================

undefined4 FUN_04106648(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_0410a9c0();
  if ((uVar1 < 3) && (*(char *)(DAT_04106678 + uVar1) != '\0')) {
    *DAT_0410667c = (char)uVar1;
    uVar2 = FUN_04109f44(uVar1,param_2,param_3);
    return uVar2;
  }
  FUN_0410ef64(param_2,0xff,param_3);
  return 0x12;
}



// ===========================================================
// Function: FUN_04106680 at 04106680
// ===========================================================

undefined4 FUN_04106680(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (2 < param_1) {
    param_1 = (uint)*DAT_041066b0;
  }
  if (*(char *)(DAT_041066b4 + param_1) != '\0') {
    uVar1 = FUN_04109fbc(param_1,param_3);
    return uVar1;
  }
  FUN_0410ef64(param_3,0xff,param_4);
  return 0;
}



// ===========================================================
// Function: FUN_041066b8 at 041066b8
// ===========================================================

undefined4 FUN_041066b8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_0410a9c0();
  if ((uVar1 < 3) && (*(char *)(DAT_041066e8 + uVar1) != '\0')) {
    *DAT_041066ec = (char)uVar1;
    uVar2 = FUN_04109fbc(uVar1,param_2,param_3);
    return uVar2;
  }
  FUN_0410ef64(param_2,0xff,param_3);
  return 0x12;
}



// ===========================================================
// Function: FUN_041066f0 at 041066f0
// ===========================================================

undefined4 FUN_041066f0(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 local_c;
  
  if (2 < param_1) {
    param_1 = (uint)*DAT_04106720;
  }
  if (*(char *)(DAT_04106724 + param_1) == '\0') {
    *param_3 = 0;
    return 0;
  }
  uVar1 = FUN_04109e34(param_1,&local_c,0,0,0);
  *param_3 = local_c;
  return uVar1;
}



// ===========================================================
// Function: FUN_04106728 at 04106728
// ===========================================================

undefined4 FUN_04106728(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  uVar1 = FUN_0410a9c0();
  if ((uVar1 < 3) && (*(char *)(DAT_04106760 + uVar1) != '\0')) {
    *DAT_04106764 = (char)uVar1;
    uVar2 = FUN_04109e34(uVar1,&local_c,0,0,0);
    *param_2 = local_c;
    return uVar2;
  }
  *param_2 = 0;
  return 0x12;
}



// ===========================================================
// Function: FUN_04106768 at 04106768
// ===========================================================

undefined4 FUN_04106768(undefined1 *param_1,undefined1 *param_2,byte *param_3)

{
  undefined1 uVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  
  uVar1 = *DAT_041067a0;
  *param_1 = 3;
  *param_2 = uVar1;
  pcVar3 = DAT_041067a4;
  uVar4 = 0;
  *param_3 = 0;
  do {
    uVar2 = uVar4 & 0xff;
    uVar4 = uVar4 + 1;
    if (*pcVar3 != '\0') {
      *param_3 = *param_3 | (byte)(1 << uVar2);
    }
    pcVar3 = pcVar3 + 1;
  } while (uVar4 != 3);
  return 0;
}



// ===========================================================
// Function: FUN_041067a8 at 041067a8
// ===========================================================

int FUN_041067a8(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = FUN_0410a9c0();
  puVar1 = DAT_04106800;
  if ((2 < uVar2) || (*(char *)(DAT_041067fc + uVar2) == '\0')) {
    return 0x12;
  }
  *DAT_04106800 = (char)uVar2;
  iVar3 = FUN_0410a684(uVar2,param_1,param_2);
  if ((iVar3 == 0) && (*DAT_04106804 != '\0')) {
    FUN_0410a998(*puVar1,0);
    iVar3 = FUN_0410a684(*puVar1,param_1,param_2);
    FUN_0410a970(*puVar1,0);
    return iVar3;
  }
  return iVar3;
}



// ===========================================================
// Function: FUN_04106808 at 04106808
// ===========================================================

void FUN_04106808(uint param_1)

{
  if (2 < param_1) {
    param_1 = (uint)*DAT_04106818;
  }
  FUN_0410a648(param_1);
  return;
}



// ===========================================================
// Function: FUN_0410681c at 0410681c
// ===========================================================

undefined4 FUN_0410681c(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_0410a9c0();
  if ((uVar1 < 3) && (*(char *)(DAT_0410683c + uVar1) != '\0')) {
    *DAT_04106840 = (char)uVar1;
    uVar2 = FUN_0410a648();
    return uVar2;
  }
  return 0x12;
}



// ===========================================================
// Function: FUN_04106844 at 04106844
// ===========================================================

int FUN_04106844(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = FUN_0410a9c0();
  puVar1 = DAT_041068b8;
  if ((2 < uVar2) || (*(char *)(DAT_041068b0 + uVar2) == '\0')) {
    return 0x12;
  }
  *DAT_041068b8 = (char)uVar2;
  iVar3 = FUN_0410a7f0(uVar2,param_1,param_2,param_3);
  if ((iVar3 == 0) && (*DAT_041068b4 != '\0')) {
    FUN_0410a998(*puVar1,0);
    iVar3 = FUN_0410a7f0(*puVar1,param_1,param_2,param_3);
    FUN_0410a970(*puVar1,0);
    return iVar3;
  }
  return iVar3;
}



// ===========================================================
// Function: FUN_041068bc at 041068bc
// ===========================================================

int FUN_041068bc(uint param_1,byte *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  puVar1 = DAT_041069b8;
  if (param_3 == 0) {
    if (*DAT_041069b0 == '\0') {
      return 0;
    }
    FUN_0410a998(*DAT_041069b8,0);
    uVar3 = (param_1 & 0x1f) + 0x1f;
    FUN_0410db38(1,param_1 & 0xffffffe0);
  }
  else {
    iVar5 = param_1 - (int)param_2;
    pbVar7 = param_2;
    do {
      uVar4 = (uint)pbVar7[iVar5];
      pbVar8 = pbVar7 + 1;
      uVar6 = (uint)*pbVar7;
      uVar2 = DAT_041069ac;
      if (uVar4 != uVar6) goto LAB_041068f6;
      pbVar7 = pbVar8;
    } while (param_2 + param_3 != pbVar8);
    if (*DAT_041069b0 == '\0') {
      return 0;
    }
    FUN_0410a998(*DAT_041069b8,0);
    uVar3 = param_3 + 0x1f + (param_1 & 0x1f);
    FUN_0410db38(1,param_1 & 0xffffffe0);
    pbVar7 = param_2;
    do {
      uVar4 = (uint)pbVar7[iVar5];
      pbVar8 = pbVar7 + 1;
      uVar6 = (uint)*pbVar7;
      uVar2 = DAT_041069b4;
      if (uVar4 != uVar6) {
LAB_041068f6:
        FUN_04109118(0x44,uVar2,uVar4,pbVar7 + iVar5,uVar6,pbVar7);
        FUN_04105da0(pbVar7 + iVar5);
        return uVar4 - uVar6;
      }
      pbVar7 = pbVar8;
    } while (param_2 + param_3 != pbVar8);
  }
  FUN_0410a970(*puVar1,0);
  FUN_0410db38(1,param_1 & 0xffffffe0,uVar3 & 0xffffffe0);
  return 0;
}



// ===========================================================
// Function: FUN_041069bc at 041069bc
// ===========================================================

int FUN_041069bc(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = FUN_0410a9c0();
  puVar2 = DAT_04106a18;
  puVar1 = DAT_04106a14;
  if ((2 < uVar3) || (*(char *)(DAT_04106a10 + uVar3) == '\0')) {
    return 0x12;
  }
  *DAT_04106a14 = (char)uVar3;
  *puVar2 = 0;
  iVar4 = FUN_0410a8b8(uVar3,0,param_1,param_2,param_3);
  if ((iVar4 == 0) && (iVar4 = FUN_0410a970(*puVar1,0), iVar4 == 0)) {
    *puVar2 = param_4 != 0;
    return 0;
  }
  return iVar4;
}



// ===========================================================
// Function: FUN_04106a1c at 04106a1c
// ===========================================================

void FUN_04106a1c(void)

{
  undefined1 uVar1;
  
  uVar1 = *DAT_04106a30;
  *DAT_04106a34 = 0;
  FUN_0410a998(uVar1);
  return;
}



// ===========================================================
// Function: FUN_04106a38 at 04106a38
// ===========================================================

void FUN_04106a38(uint param_1)

{
  if (2 < param_1) {
    param_1 = (uint)*DAT_04106a48;
  }
  FUN_0410a808(param_1);
  return;
}



// ===========================================================
// Function: FUN_04106a4c at 04106a4c
// ===========================================================

undefined4 FUN_04106a4c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_0410a9c0();
  if ((uVar1 < 3) && (*(char *)(DAT_04106a74 + uVar1) != '\0')) {
    *DAT_04106a78 = (char)uVar1;
    uVar2 = FUN_0410a808(uVar1,param_2,param_3);
    return uVar2;
  }
  return 0x12;
}



// ===========================================================
// Function: FUN_04106a7c at 04106a7c
// ===========================================================

void FUN_04106a7c(uint param_1,undefined1 *param_2,undefined1 *param_3)

{
  undefined1 local_18 [4];
  undefined1 local_14 [8];
  
  if (2 < param_1) {
    param_1 = (uint)*DAT_04106aa4;
  }
  FUN_0410a878(param_1,local_18,local_14);
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = local_18[0];
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = local_14[0];
  }
  return;
}



// ===========================================================
// Function: FUN_04106aa8 at 04106aa8
// ===========================================================

undefined4 FUN_04106aa8(undefined4 param_1,undefined1 *param_2,undefined1 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 local_18 [4];
  undefined1 local_14 [8];
  
  uVar1 = FUN_0410a9c0();
  if ((uVar1 < 3) && (*(char *)(DAT_04106ae0 + uVar1) != '\0')) {
    *DAT_04106ae4 = (char)uVar1;
    uVar2 = FUN_0410a878(uVar1,local_18,local_14);
    if (param_2 != (undefined1 *)0x0) {
      *param_2 = local_18[0];
    }
    if (param_3 != (undefined1 *)0x0) {
      *param_3 = local_14[0];
      return uVar2;
    }
  }
  else {
    uVar2 = 0x12;
  }
  return uVar2;
}



// ===========================================================
// Function: FUN_04106ae8 at 04106ae8
// ===========================================================

void FUN_04106ae8(void)

{
  int iVar1;
  
  while (iVar1 = FUN_04103f9c(), iVar1 != 0) {
    FUN_04106ed0();
  }
  return;
}



// ===========================================================
// Function: FUN_04106afc at 04106afc
// ===========================================================

void FUN_04106afc(void)

{
  int iVar1;
  
  iVar1 = FUN_0410400c();
  while (iVar1 != 0) {
    do {
      iVar1 = FUN_04103f9c();
    } while (iVar1 == 0);
    FUN_04106ed0();
    iVar1 = FUN_0410400c();
  }
  return;
}



// ===========================================================
// Function: FUN_04106b1c at 04106b1c
// ===========================================================

undefined4 FUN_04106b1c(void)

{
  int iVar1;
  
  FUN_04104040(1);
  while (iVar1 = FUN_04104020(), iVar1 != 0) {
    FUN_04106ed0();
  }
  FUN_04104040();
  return 0;
}



// ===========================================================
// Function: FUN_04106b3c at 04106b3c
// ===========================================================

undefined4 FUN_04106b3c(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (0x2ffffff < param_1) {
    return 0xffffffff;
  }
  if (*(char *)(DAT_04106b70 + (param_1 >> 0x18)) != '\0') {
    *DAT_04106b74 = (char)(param_1 >> 0x18);
    uVar1 = FUN_0410a474(param_1 >> 0x18,param_1 & 0xffffff,param_2,param_3);
    return uVar1;
  }
  return 1;
}



// ===========================================================
// Function: FUN_04106b78 at 04106b78
// ===========================================================

undefined4 FUN_04106b78(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (0x2ffffff < param_1) {
    return 0xffffffff;
  }
  if (*(char *)(DAT_04106ba8 + (param_1 >> 0x18)) != '\0') {
    *DAT_04106bac = (char)(param_1 >> 0x18);
    uVar1 = FUN_0410a168(param_1 >> 0x18,param_1 & 0xffffff,param_2);
    return uVar1;
  }
  return 1;
}



// ===========================================================
// Function: FUN_04106bb0 at 04106bb0
// ===========================================================

undefined4 FUN_04106bb0(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (0x2ffffff < param_1) {
    return 0xffffffff;
  }
  if (*(char *)(DAT_04106be0 + (param_1 >> 0x18)) != '\0') {
    *DAT_04106be4 = (char)(param_1 >> 0x18);
    uVar1 = FUN_0410a0c4(param_1 >> 0x18,param_1 & 0xffffff,param_2);
    return uVar1;
  }
  return 1;
}



// ===========================================================
// Function: FUN_04106be8 at 04106be8
// ===========================================================

undefined4 FUN_04106be8(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (0x2ffffff < param_1) {
    return 0xffffffff;
  }
  if (*(char *)(DAT_04106c1c + (param_1 >> 0x18)) != '\0') {
    *DAT_04106c20 = (char)(param_1 >> 0x18);
    uVar1 = FUN_0410a2b0(param_1 >> 0x18,param_1 & 0xffffff,param_2,param_3);
    return uVar1;
  }
  return 1;
}



// ===========================================================
// Function: FUN_04106c24 at 04106c24
// ===========================================================

int FUN_04106c24(uint param_1,byte *param_2,byte *param_3,int param_4)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  
  if (0x2ffffff < param_1) {
    return -1;
  }
  if (*(char *)(DAT_04106cac + (param_1 >> 0x18)) == '\0') {
    iVar1 = 1;
  }
  else {
    *DAT_04106cb0 = (char)(param_1 >> 0x18);
    iVar1 = FUN_0410a474(param_1 >> 0x18,param_1 & 0xffffff,param_2);
    if (iVar1 == 0) {
      iVar1 = 0;
      if (param_4 != 0) {
        pbVar2 = param_2;
        pbVar3 = param_3;
        do {
          uVar6 = (uint)*pbVar2;
          pbVar4 = pbVar3 + 1;
          uVar5 = (uint)*pbVar3;
          if (uVar6 != uVar5) {
            FUN_04109118(0x44,DAT_04106cb4,uVar6,pbVar2 + ((param_1 & 0xffffff) - (int)param_2),
                         uVar5,pbVar3);
            return uVar6 - uVar5;
          }
          pbVar2 = pbVar2 + 1;
          pbVar3 = pbVar4;
        } while (param_3 + param_4 != pbVar4);
      }
    }
    else {
      FUN_04109118(0x41,DAT_04106cb8,iVar1);
      iVar1 = 1;
    }
  }
  return iVar1;
}



// ===========================================================
// Function: _start at 04106d24
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void _start(void)

{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(DAT_04106ddc);
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: FUN_04106e64 at 04106e64
// ===========================================================

undefined4 FUN_04106e64(uint param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_04106ec0;
  if (1 < param_1) {
    return 1;
  }
  if ((param_2 & 7) == 0) {
    if (*(char *)(DAT_04106ec0 + param_1) == '\0') {
      if (param_4 == 1) {
        if (*DAT_04106ecc != 2) {
          return 4;
        }
        *DAT_04106ecc = param_1;
      }
      if (param_2 == 0) {
        *(undefined4 *)(DAT_04106ec4 + param_1 * 4) = 0;
      }
      else {
        *(uint *)(DAT_04106ec4 + param_1 * 4) = param_2 - 0x28;
        *(undefined4 *)(param_2 - 4) = param_5;
      }
      iVar2 = DAT_04106ec8;
      *(char *)(iVar1 + param_1) = (char)param_4;
      uVar3 = 0;
      *(undefined4 *)(iVar2 + param_1 * 4) = param_3;
    }
    else {
      uVar3 = 3;
    }
    return uVar3;
  }
  return 2;
}



// ===========================================================
// Function: FUN_04106ed0 at 04106ed0
// ===========================================================

undefined4 FUN_04106ed0(void)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_lr;
  
  puVar2 = DAT_04106e5c;
  if (*DAT_04106ee4 == 2) {
    return 1;
  }
  uVar4 = *DAT_04106e58;
  iVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar5 = getBasePriority();
  }
  uVar6 = uVar4;
  if (iVar5 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    uVar6 = *DAT_04106e58;
    *DAT_04106e5c = 0x4106e18;
    puVar2[1] = unaff_lr;
  }
  iVar3 = DAT_04106e60;
  *(undefined1 *)(DAT_04106e60 + uVar6) = 2;
  do {
    uVar4 = uVar4 + 1;
    if (1 < uVar4) {
      uVar4 = 0;
    }
  } while (*(char *)(iVar3 + uVar4) != '\x02');
  *(undefined1 *)(iVar3 + uVar4) = 1;
  if (uVar4 != uVar6) {
    FUN_04103cc4(uVar4);
  }
  if (iVar5 == 0) {
    *DAT_04106e5c = 0xffffffff;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar5);
  }
  return 1;
}



// ===========================================================
// Function: FUN_04107124 at 04107124
// ===========================================================

undefined4 FUN_04107124(char *param_1)

{
  bool bVar1;
  
  do {
    ExclusiveAccess(param_1);
    if (*param_1 != '\0') {
      ClearExclusiveLocal();
      return 0xffffffff;
    }
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = '\x01';
  DataMemoryBarrier(0x1f);
  return 0;
}



// ===========================================================
// Function: FUN_0410714c at 0410714c
// ===========================================================

void FUN_0410714c(undefined1 *param_1)

{
  *param_1 = 0;
  DataMemoryBarrier(0x1f);
  return;
}



// ===========================================================
// Function: FUN_041071ac at 041071ac
// ===========================================================

void FUN_041071ac(uint param_1,ushort *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_041071f4;
  DAT_041071f4[1] = 0x40000;
  puVar1[1] = 0x60000;
  puVar1[1] = param_1 | 0x60000;
  FUN_0410ad74(3);
  puVar1[1] = param_1 | 0x70000;
  puVar1[1] = param_1 | 0x60000;
  FUN_0410ad74(2);
  *param_2 = (ushort)*puVar1 | (ushort)((uint)*puVar1 >> 0x10);
  puVar1[1] = 0x40000;
  puVar1[1] = 0;
  return;
}



// ===========================================================
// Function: FUN_04107478 at 04107478
// ===========================================================

uint FUN_04107478(uint param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    uVar1 = param_1 & 0xfbffffff;
    if (uVar1 < 0x200000) {
      return uVar1 + 0x21800000 | param_1 & 0x4000000;
    }
    if (uVar1 + 0xe0000000 < 0x400000) {
      param_1 = uVar1 + 0x1000000 | param_1 & 0x4000000;
    }
  }
  return param_1;
}



// ===========================================================
// Function: FUN_041074a4 at 041074a4
// ===========================================================

uint FUN_041074a4(uint param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    uVar1 = param_1 & 0xfbffffff;
    if (uVar1 + 0xde800000 < 0x200000) {
      return param_1 & 0x4000000 | uVar1 + 0xde800000;
    }
    if (uVar1 + 0xdf000000 < 0x400000) {
      param_1 = uVar1 - 0x1000000 | param_1 & 0x4000000;
    }
  }
  return param_1;
}



// ===========================================================
// Function: FUN_041074d0 at 041074d0
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_041074d0(uint param_1)

{
  if (0xc9 < param_1) {
    return 1;
  }
  if (param_1 < 0x1f) {
    _DAT_40000000 = 1 << (param_1 & 0xff);
  }
  else {
    if (param_1 < 0x3d) {
      _DAT_40000008 = 1 << (param_1 - 0x1f & 0xff);
      DataSynchronizationBarrier(0xf);
      goto joined_r0x04107238;
    }
    if (param_1 < 0x5d) {
      _DAT_40000010 = 1 << (param_1 - 0x3d & 0xff);
    }
    else if (param_1 < 0x78) {
      _DAT_40000160 = 1 << (param_1 - 0x5d & 0xff);
    }
    else if (param_1 < 0x85) {
      _DAT_40000244 = 1 << (param_1 - 0x78 & 0xff);
    }
    else {
      if (0xa4 < param_1) {
        if (param_1 < 0xba) {
          *(int *)(DAT_041072c0 + 0x40) = 1 << (param_1 - 0xa5 & 0xff);
        }
        else {
          *(int *)(DAT_041072c0 + 0x180) = 1 << (param_1 - 0xba & 0xff);
        }
        DataSynchronizationBarrier(0xf);
        return 0;
      }
      _DAT_40000178 = 1 << (param_1 - 0x85 & 0xff);
    }
  }
  DataSynchronizationBarrier(0xf);
joined_r0x04107238:
  if (param_1 != 0x52) {
    return 0;
  }
  FUN_04108054();
  return 0;
}



// ===========================================================
// Function: FUN_041074dc at 041074dc
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_041074dc(uint param_1)

{
  if (0xc9 < param_1) {
    return 1;
  }
  if (param_1 < 0x1f) {
    _DAT_40000004 = 1 << (param_1 & 0xff);
    return 0;
  }
  if (param_1 < 0x3d) {
    _DAT_4000000c = 1 << (param_1 - 0x1f & 0xff);
    return 0;
  }
  if (param_1 < 0x5d) {
    _DAT_40000014 = 1 << (param_1 - 0x3d & 0xff);
    return 0;
  }
  if (param_1 < 0x78) {
    _DAT_40000164 = 1 << (param_1 - 0x5d & 0xff);
    return 0;
  }
  if (param_1 < 0x85) {
    _DAT_40000248 = 1 << (param_1 - 0x78 & 0xff);
    return 0;
  }
  if (param_1 < 0xa5) {
    _DAT_4000017c = 1 << (param_1 - 0x85 & 0xff);
    return 0;
  }
  if (param_1 < 0xba) {
    *(int *)(DAT_041075a4 + 0x44) = 1 << (param_1 - 0xa5 & 0xff);
    return 0;
  }
  *(int *)(DAT_041075a4 + 0x184) = 1 << (param_1 - 0xba & 0xff);
  return 0;
}



// ===========================================================
// Function: FUN_041075a8 at 041075a8
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_041075a8(uint param_1)

{
  uint uVar1;
  
  if (0xc9 < param_1) {
    return false;
  }
  if (param_1 < 0x1f) {
    uVar1 = 1 << (param_1 & 0xff) & _DAT_40000004;
  }
  else {
    if (param_1 < 0x3d) {
      return (1 << (param_1 - 0x1f & 0xff) & _DAT_4000000c) != 0;
    }
    if (param_1 < 0x5d) {
      return (1 << (param_1 - 0x3d & 0xff) & _DAT_40000014) != 0;
    }
    if (param_1 < 0x78) {
      uVar1 = 1 << (param_1 - 0x5d & 0xff) & _DAT_40000164;
    }
    else if (param_1 < 0x85) {
      uVar1 = 1 << (param_1 - 0x78 & 0xff) & _DAT_40000248;
    }
    else if (param_1 < 0xa5) {
      uVar1 = 1 << (param_1 - 0x85 & 0xff) & _DAT_4000017c;
    }
    else if (param_1 < 0xba) {
      uVar1 = 1 << (param_1 - 0xa5 & 0xff) & *(uint *)(DAT_04107384 + 0x44);
    }
    else {
      uVar1 = 1 << (param_1 - 0xba & 0xff) & *(uint *)(DAT_04107384 + 0x184);
    }
  }
  return uVar1 != 0;
}



// ===========================================================
// Function: FUN_041075b4 at 041075b4
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_041075b4(uint param_1)

{
  if (0xda < param_1) {
    return 1;
  }
  if (param_1 < 0x1f) {
    _DAT_40000034 = 1 << (param_1 & 0xff);
    return 0;
  }
  if (param_1 < 0x3d) {
    _DAT_4000003c = 1 << (param_1 - 0x1f & 0xff);
    return 0;
  }
  if (param_1 < 0x5d) {
    _DAT_40000044 = 1 << (param_1 - 0x3d & 0xff);
    return 0;
  }
  if (param_1 < 0x78) {
    _DAT_40000170 = 1 << (param_1 - 0x5d & 0xff);
    return 0;
  }
  if (param_1 < 0x85) {
    _DAT_40000254 = 1 << (param_1 - 0x78 & 0xff);
    return 0;
  }
  if (param_1 < 0xa5) {
    _DAT_40000188 = 1 << (param_1 - 0x85 & 0xff);
    return 0;
  }
  if (param_1 < 0xba) {
    *(int *)(DAT_041076c0 + 0x10) = 1 << (param_1 - 0xa5 & 0xff);
    return 0;
  }
  if (param_1 < 0xca) {
    *(int *)(DAT_041076c0 + 400) = 1 << (param_1 - 0xba & 0xff);
    return 0;
  }
  if (param_1 < 0xd9) {
    if (param_1 == 0xd8) {
      *(undefined4 *)(DAT_041076c0 + 0x84) = 1;
      FUN_041089e4();
    }
    *(int *)(DAT_041076c0 + 200) = 1 << (param_1 - 0xca & 0xff);
    return 0;
  }
  if (param_1 != 0xd9) {
    _DAT_50000044 = 2;
    return 0;
  }
  _DAT_50000034 = 0x10;
  return 0;
}



// ===========================================================
// Function: FUN_041076c4 at 041076c4
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_041076c4(uint param_1)

{
  if (0xda < param_1) {
    return 1;
  }
  if (param_1 < 0x1f) {
    _DAT_40000038 = 1 << (param_1 & 0xff);
  }
  else if (param_1 < 0x3d) {
    _DAT_40000040 = 1 << (param_1 - 0x1f & 0xff);
  }
  else if (param_1 < 0x5d) {
    _DAT_40000048 = 1 << (param_1 - 0x3d & 0xff);
  }
  else if (param_1 < 0x78) {
    _DAT_40000174 = 1 << (param_1 - 0x5d & 0xff);
  }
  else if (param_1 < 0x85) {
    _DAT_40000258 = 1 << (param_1 - 0x78 & 0xff);
  }
  else {
    if (0xa4 < param_1) {
      if (param_1 < 0xba) {
        *(int *)(DAT_04107474 + 0x14) = 1 << (param_1 - 0xa5 & 0xff);
      }
      else if (param_1 < 0xca) {
        *(int *)(DAT_04107474 + 0x194) = 1 << (param_1 - 0xba & 0xff);
      }
      else {
        if (0xd8 < param_1) {
          if (param_1 == 0xd9) {
            _DAT_50000038 = 0x10;
          }
          else {
            _DAT_50000048 = 2;
          }
          DataSynchronizationBarrier(0xf);
          return 0;
        }
        *(int *)(DAT_04107474 + 0xcc) = 1 << (param_1 - 0xca & 0xff);
      }
      DataSynchronizationBarrier(0xf);
      return 0;
    }
    _DAT_4000018c = 1 << (param_1 - 0x85 & 0xff);
  }
  DataSynchronizationBarrier(0xf);
  return 0;
}



// ===========================================================
// Function: FUN_041076d4 at 041076d4
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_041076d4(void)

{
  _DAT_4000005c = _DAT_4000005c & 0xff9fffff | 0x1e0000;
  return 0;
}



// ===========================================================
// Function: FUN_0410774c at 0410774c
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0410774c(void)

{
  _DAT_40000060 = 0x4000;
  FUN_0410ad74(0x32);
  _DAT_40000060 = 0x2000;
  return;
}



// ===========================================================
// Function: FUN_04107768 at 04107768
// ===========================================================

void FUN_04107768(void)

{
  return;
}



// ===========================================================
// Function: thunk_FUN_0410ae28 at 0410776c
// ===========================================================

int thunk_FUN_0410ae28(void)

{
  return *(int *)(DAT_0410ae34 + 0x50) - *(int *)(DAT_0410ae38 + 4);
}



// ===========================================================
// Function: thunk_FUN_0410777c at 04107770
// ===========================================================

void thunk_FUN_0410777c(void)

{
  int iVar1;
  
  iVar1 = DAT_04107790;
  *(undefined4 *)(DAT_04107790 + 0x50) = 0x66666666;
  *(undefined4 *)(iVar1 + 0x54) = 0x66666666;
  *(undefined4 *)(iVar1 + 0x58) = 0x66666666;
  *(undefined4 *)(iVar1 + 0x5c) = 0x66666666;
  *(undefined4 *)(iVar1 + 0x60) = 0x66666666;
  *(undefined4 *)(iVar1 + 0x78) = 0x66666666;
  return;
}



// ===========================================================
// Function: FUN_0410777c at 0410777c
// ===========================================================

void FUN_0410777c(void)

{
  int iVar1;
  
  iVar1 = DAT_04107790;
  *(undefined4 *)(DAT_04107790 + 0x50) = 0x66666666;
  *(undefined4 *)(iVar1 + 0x54) = 0x66666666;
  *(undefined4 *)(iVar1 + 0x58) = 0x66666666;
  *(undefined4 *)(iVar1 + 0x5c) = 0x66666666;
  *(undefined4 *)(iVar1 + 0x60) = 0x66666666;
  *(undefined4 *)(iVar1 + 0x78) = 0x66666666;
  return;
}



// ===========================================================
// Function: FUN_04107868 at 04107868
// ===========================================================

void FUN_04107868(int param_1,uint param_2,uint param_3)

{
  uint local_c [2];
  
  if (((param_1 == 0) || (param_1 == 3)) && (*DAT_041078b4 == '\0')) {
    local_c[0] = (param_2 & 0xff) << 0x10 | param_3;
    FUN_0410c1d4(DAT_041078b8,local_c);
    return;
  }
  local_c[0] = (param_3 | param_2 << 0x10) << 2;
  FUN_0410c194(local_c);
  return;
}



// ===========================================================
// Function: FUN_041078bc at 041078bc
// ===========================================================

int FUN_041078bc(uint param_1,undefined2 *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  char *pcVar4;
  int iVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 unaff_lr;
  bool bVar12;
  bool bVar13;
  uint local_30;
  uint local_2c [2];
  
  pcVar4 = DAT_04107a30;
  puVar2 = DAT_04107a20;
  uVar9 = param_1 >> 0xc;
  bVar12 = uVar9 != 0;
  bVar13 = uVar9 != 3;
  if ((bVar13 && bVar12) || (*DAT_04107a30 != '\0')) {
    uVar10 = (param_1 & 0xfff) >> 10;
    uVar8 = param_1 & 0x3ff;
  }
  else {
    uVar10 = (param_1 & 0xfff) >> 8;
    uVar8 = param_1 & 0xff;
    if ((param_1 >> 8 & 0xc) != 0) {
      return -1;
    }
  }
  iVar11 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar11 = getBasePriority();
  }
  if (iVar11 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04107a20 = 0x4107900;
    puVar2[1] = unaff_lr;
  }
  if (uVar9 == 2) {
    do {
      iVar5 = FUN_0410ef24(2);
      if (iVar5 != 0) break;
      iVar5 = FUN_0410ef24(2);
    } while (iVar5 == 0);
  }
  pbVar3 = DAT_04107a24;
  if (*pcVar4 == '\0') {
    uVar7 = (uint)*DAT_04107a24;
    if (bVar13 && bVar12) {
      if ((uVar7 == 0) || (uVar7 == 3)) {
        FUN_0410c180();
        uVar7 = (uint)*pbVar3;
      }
    }
    else if ((uVar7 != 0) && (uVar7 != 3)) {
      FUN_0410c170(DAT_04107a28);
      *pbVar3 = 0;
      uVar7 = 0;
    }
  }
  else {
    uVar7 = (uint)*DAT_04107a24;
  }
  if (uVar7 != uVar9) {
    FUN_0410c148(uVar9);
    *pbVar3 = (byte)uVar9;
  }
  if (uVar10 != 0) {
    FUN_04107868(uVar9,0,*(undefined2 *)(DAT_04107a2c + uVar10 * 2));
  }
  local_30 = 0;
  if ((bVar13 && bVar12) || (*pcVar4 != '\0')) {
    local_2c[0] = uVar8 << 0x12 | 0x10000000;
    iVar5 = FUN_0410c1b0(local_2c,&local_30,4);
    uVar6 = (undefined2)((local_30 & 0x3ffff) >> 2);
  }
  else {
    local_2c[0] = (uVar8 & 0xff) << 0x10 | 0x1000000;
    iVar5 = FUN_0410c1f4(DAT_04107a28,local_2c,&local_30,4);
    uVar6 = (undefined2)local_30;
  }
  if (iVar5 == 0) {
    *param_2 = uVar6;
  }
  if (uVar10 != 0) {
    FUN_04107868(uVar9,0,0xa000);
  }
  if (uVar9 == 2) {
    FUN_0410ef3c(2);
  }
  if (iVar11 == 0) {
    *DAT_04107a20 = 0xffffffff;
  }
  bVar12 = (bool)isCurrentModePrivileged();
  if (bVar12) {
    setBasePriority(iVar11);
  }
  return iVar5;
}



// ===========================================================
// Function: FUN_04107a34 at 04107a34
// ===========================================================

undefined4 FUN_04107a34(uint param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 unaff_lr;
  
  pcVar4 = DAT_04107b64;
  puVar2 = DAT_04107b54;
  uVar9 = param_1 >> 0xc;
  if ((uVar9 != 3 && uVar9 != 0) || (*DAT_04107b64 != '\0')) {
    uVar10 = (param_1 & 0xfff) >> 10;
    uVar8 = param_1 & 0x3ff;
  }
  else {
    uVar10 = (param_1 & 0xfff) >> 8;
    uVar8 = param_1 & 0xff;
    if ((param_1 >> 8 & 0xc) != 0) {
      return 0xffffffff;
    }
  }
  iVar11 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar11 = getBasePriority();
  }
  if (iVar11 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04107b54 = 0x4107a78;
    puVar2[1] = unaff_lr;
  }
  if (uVar9 == 2) {
    do {
      iVar6 = FUN_0410ef24(2);
      if (iVar6 != 0) break;
      iVar6 = FUN_0410ef24(2);
    } while (iVar6 == 0);
  }
  pbVar3 = DAT_04107b58;
  if (*pcVar4 == '\0') {
    if (uVar9 != 3 && uVar9 != 0) {
      uVar7 = (uint)*DAT_04107b58;
      if ((uVar7 == 0) || (uVar7 == 3)) {
        FUN_0410c180();
        uVar7 = (uint)*pbVar3;
      }
    }
    else {
      uVar7 = (uint)*DAT_04107b58;
      if ((uVar7 != 0) && (uVar7 != 3)) {
        FUN_0410c170(DAT_04107b5c);
        *pbVar3 = 0;
        uVar7 = 0;
      }
    }
  }
  else {
    uVar7 = (uint)*DAT_04107b58;
  }
  if (uVar9 != uVar7) {
    FUN_0410c148(uVar9);
    *pbVar3 = (byte)uVar9;
  }
  if (uVar10 == 0) {
    uVar5 = FUN_04107868(uVar9,uVar8,param_2);
  }
  else {
    FUN_04107868(uVar9,0,*(undefined2 *)(DAT_04107b60 + uVar10 * 2));
    uVar5 = FUN_04107868(uVar9,uVar8,param_2);
    FUN_04107868(uVar9,0,0xa000);
  }
  if (uVar9 == 2) {
    FUN_0410ef3c(2);
  }
  if (iVar11 == 0) {
    *DAT_04107b54 = 0xffffffff;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar11);
  }
  return uVar5;
}



// ===========================================================
// Function: FUN_04107b68 at 04107b68
// ===========================================================

int FUN_04107b68(void)

{
  undefined1 *puVar1;
  char *pcVar2;
  int iVar3;
  ushort local_1e;
  undefined1 auStack_1c [6];
  undefined2 local_16;
  undefined1 local_14;
  
  FUN_0410ef70(auStack_1c,DAT_04107c0c,0xc);
  iVar3 = FUN_0410c120(auStack_1c);
  puVar1 = DAT_04107c10;
  if (iVar3 == 0) {
    *DAT_04107c10 = 7;
    FUN_0410c148();
    iVar3 = FUN_041078bc(0x7000,&local_1e);
    if (iVar3 == 0) {
      if (local_1e >> 4 == 0x170) {
        *puVar1 = 0;
        FUN_0410c148();
        pcVar2 = DAT_04107c14;
        *DAT_04107c14 = '\x01';
        iVar3 = FUN_041078bc(0,&local_1e);
        if (iVar3 == 0) {
          local_1e = local_1e >> 4;
          if (local_1e != 399) {
            *pcVar2 = '\0';
          }
          *puVar1 = 7;
          FUN_0410c148();
          if (*pcVar2 == '\0') {
            local_16 = 0x1900;
            local_14 = 0x19;
            FUN_0410be44(auStack_1c,DAT_04107c18);
          }
        }
      }
      else {
        iVar3 = -1;
      }
    }
  }
  return iVar3;
}



// ===========================================================
// Function: FUN_04107c1c at 04107c1c
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_04107c1c(int param_1,uint param_2)

{
  ushort uVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_lr;
  
  puVar3 = DAT_04107ccc;
  if (param_1 == 0) {
    uVar6 = 0x10;
    uVar5 = 1;
  }
  else if (param_1 == 1) {
    uVar6 = 0x20;
    uVar5 = 2;
  }
  else {
    uVar6 = 0x40;
    uVar5 = 4;
  }
  iVar7 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    iVar7 = getBasePriority();
  }
  if (iVar7 != 0x40) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(0x40);
    }
    *DAT_04107ccc = 0x4107c48;
    puVar3[1] = unaff_lr;
  }
  iVar4 = DAT_04107cd0;
  uVar1 = *(ushort *)(DAT_04107cd0 + param_1 * 2);
  if ((uVar1 == 0) || (param_2 == 0xf)) {
    _DAT_400000e4 = uVar5;
    FUN_0410ad74(0x14);
    if (param_2 != 0xf) {
      *(ushort *)(iVar4 + param_1 * 2) =
           (ushort)(1 << (param_2 & 0xff)) | *(ushort *)(iVar4 + param_1 * 2);
    }
  }
  else {
    *(ushort *)(DAT_04107cd0 + param_1 * 2) = (ushort)(1 << (param_2 & 0xff)) | uVar1;
  }
  if (iVar7 == 0) {
    *DAT_04107ccc = 0xffffffff;
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(iVar7);
  }
  iVar7 = FUN_0410ad54();
  do {
    if ((_DAT_400000e4 & uVar6) != 0) {
      _DAT_400000e4 = uVar6;
      return 0;
    }
    iVar4 = FUN_0410ad54();
  } while ((uint)(iVar4 - iVar7) < 5);
  _DAT_400000e4 = uVar6;
  return 0;
}



// ===========================================================
// Function: FUN_04107cd4 at 04107cd4
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_04107cd4(int param_1,uint param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 unaff_lr;
  
  puVar2 = DAT_04107d38;
  if (param_1 == 0) {
    uVar5 = 1;
  }
  else if (param_1 == 1) {
    uVar5 = 2;
  }
  else {
    uVar5 = 4;
  }
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04107d38 = 0x4107cf6;
    puVar2[1] = unaff_lr;
  }
  if ((param_2 == 0xf) ||
     (uVar3 = (uint)*(ushort *)(DAT_04107d3c + param_1 * 2) & ~(1 << (param_2 & 0xff)),
     *(short *)(DAT_04107d3c + param_1 * 2) = (short)uVar3, uVar3 == 0)) {
    _DAT_400000e8 = uVar5;
  }
  if (iVar4 == 0) {
    *DAT_04107d38 = 0xffffffff;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar4);
  }
  return 0;
}



// ===========================================================
// Function: FUN_04107d40 at 04107d40
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_04107d40(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 unaff_lr;
  
  puVar2 = DAT_04107dac;
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04107dac = 0x4107d54;
    puVar2[1] = unaff_lr;
  }
  if (param_1 == 0) {
    _DAT_40000070 = DAT_04107db0 & _DAT_40000070;
    uVar3 = 0;
  }
  else if (param_1 == 1) {
    uVar3 = 0;
    _DAT_40000070 = DAT_04107db0 & _DAT_40000070 | 4;
  }
  else if (param_1 == 2) {
    uVar3 = 0;
    _DAT_40000070 = DAT_04107db4 | DAT_04107db0 & _DAT_40000070;
  }
  else {
    uVar3 = 1;
  }
  if (iVar4 == 0) {
    *DAT_04107dac = 0xffffffff;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar4);
  }
  return uVar3;
}



// ===========================================================
// Function: FUN_04107db8 at 04107db8
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_04107db8(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 unaff_lr;
  
  puVar2 = DAT_04107e24;
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04107e24 = 0x4107dcc;
    puVar2[1] = unaff_lr;
  }
  if (param_1 == 0) {
    _DAT_40000070 = DAT_04107e28 & _DAT_40000070;
    uVar3 = 0;
  }
  else if (param_1 == 1) {
    uVar3 = 0;
    _DAT_40000070 = DAT_04107e28 & _DAT_40000070 | 0x80;
  }
  else if (param_1 == 2) {
    uVar3 = 0;
    _DAT_40000070 = DAT_04107e2c | DAT_04107e28 & _DAT_40000070;
  }
  else {
    uVar3 = 1;
  }
  if (iVar4 == 0) {
    *DAT_04107e24 = 0xffffffff;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar4);
  }
  return uVar3;
}



// ===========================================================
// Function: FUN_04107e30 at 04107e30
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_04107e30(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 unaff_lr;
  
  puVar2 = DAT_04107e9c;
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04107e9c = 0x4107e44;
    puVar2[1] = unaff_lr;
  }
  if (param_1 == 0) {
    _DAT_40000070 = _DAT_40000070 & 0xb1ffffff;
    uVar3 = 0;
  }
  else if (param_1 == 1) {
    uVar3 = 0;
    _DAT_40000070 = _DAT_40000070 & 0xb1ffffff | 0x2000000;
  }
  else if (param_1 == 2) {
    uVar3 = 0;
    _DAT_40000070 = _DAT_40000070 & 0xb1ffffff | 0x42000000;
  }
  else {
    uVar3 = 1;
  }
  if (iVar4 == 0) {
    *DAT_04107e9c = 0xffffffff;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar4);
  }
  return uVar3;
}



// ===========================================================
// Function: FUN_04108054 at 04108054
// ===========================================================

void FUN_04108054(void)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 unaff_lr;
  
  puVar3 = DAT_041080ac;
  iVar2 = DAT_041080a8;
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 == 0x40) {
    *(uint *)(DAT_041080a8 + 0x154) = *(uint *)(DAT_041080a8 + 0x154) | 0x800000;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
  }
  else {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_041080ac = 0x4108068;
    puVar3[1] = unaff_lr;
    *(uint *)(iVar2 + 0x154) = *(uint *)(iVar2 + 0x154) | 0x800000;
    if (iVar4 == 0) {
      *puVar3 = 0xffffffff;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(iVar4);
    }
  }
  iVar2 = DAT_04107860;
  *(uint *)(DAT_04107860 + 0x1c) = DAT_04107864 | *(uint *)(DAT_04107860 + 0x1c) & 0xff000000;
  *(uint *)(iVar2 + 0x68) = *(uint *)(iVar2 + 0x68) & 0xffc0ffff;
  *(uint *)(iVar2 + 0x70) = *(uint *)(iVar2 + 0x70) & 0xffc0ffff;
  return;
}



// ===========================================================
// Function: FUN_041080b0 at 041080b0
// ===========================================================

void FUN_041080b0(void)

{
  *(undefined4 *)(DAT_041080bc + 4) = 0x200;
  return;
}



// ===========================================================
// Function: FUN_041080c0 at 041080c0
// ===========================================================

void FUN_041080c0(void)

{
  *(undefined4 *)(DAT_041080cc + 8) = 0x200;
  return;
}



// ===========================================================
// Function: FUN_041080d0 at 041080d0
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_041080d0(uint param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_lr;
  
  puVar3 = DAT_041082bc;
  if (0x13 < param_1) {
    return 1;
  }
  switch(param_1) {
  case 0:
    uVar6 = 0x600000;
    bVar2 = false;
    iVar5 = -1;
    _DAT_40000060 = 0x200;
    _DAT_40000064 = DAT_041082c8;
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
    _DAT_40000064 = DAT_041082b8;
    if (param_1 == 4) {
      uVar6 = 0;
      iVar5 = -1;
      _DAT_40000060 = 0x300;
      bVar2 = false;
    }
    else if (param_1 == 5) {
      uVar6 = 0x200000;
      bVar2 = false;
      iVar5 = -1;
      _DAT_40000060 = 0x300;
    }
    else {
      iVar5 = -1;
      bVar2 = false;
      if (param_1 == 6) {
        uVar6 = 0x400000;
      }
      else {
        uVar6 = 0x600000;
      }
      _DAT_40000060 = 0x300;
    }
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
    _DAT_40000064 = DAT_041082c0;
    if (param_1 == 8) {
      uVar6 = 0;
      iVar5 = -1;
      _DAT_40000060 = 0x700;
      bVar2 = false;
    }
    else if (param_1 == 9) {
      uVar6 = 0x200000;
      bVar2 = false;
      iVar5 = -1;
      _DAT_40000060 = 0x700;
    }
    else {
      iVar5 = -1;
      bVar2 = false;
      if (param_1 == 10) {
        uVar6 = 0x400000;
      }
      else {
        uVar6 = 0x600000;
      }
      _DAT_40000060 = 0x700;
    }
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    _DAT_40000064 = DAT_041082c4;
    if (param_1 == 0xc) {
      uVar6 = 0;
      bVar2 = true;
      _DAT_40000060 = 0xb20;
      iVar5 = 0;
    }
    else if (param_1 == 0xd) {
      uVar6 = 0x200000;
      bVar2 = true;
      iVar5 = 0;
      _DAT_40000060 = 0xb20;
    }
    else {
      iVar5 = 0;
      bVar2 = true;
      if (param_1 == 0xe) {
        uVar6 = 0x400000;
      }
      else {
        uVar6 = 0x600000;
      }
      _DAT_40000060 = 0xb20;
    }
    break;
  default:
    _DAT_40000064 = DAT_041082cc;
    if (param_1 == 0x10) {
      uVar6 = 0;
      bVar2 = true;
      iVar5 = -1;
      _DAT_40000060 = 0x1b00;
    }
    else if (param_1 == 0x11) {
      uVar6 = 0x200000;
      bVar2 = true;
      iVar5 = -1;
      _DAT_40000060 = 0x1b00;
    }
    else {
      iVar5 = -1;
      bVar2 = true;
      if (param_1 == 0x12) {
        uVar6 = 0x400000;
      }
      else {
        uVar6 = 0x600000;
      }
      _DAT_40000060 = 0x1b00;
    }
  }
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 == 0x40) {
    _DAT_40000070 = _DAT_40000070 & 0xff9fffff | uVar6;
    if (iVar5 != 0) goto LAB_0410815e;
LAB_04108144:
    _DAT_400000a8 = _DAT_400000a8 & 0xfffffffc;
  }
  else {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_041082bc = 0x410812c;
    puVar3[1] = unaff_lr;
    _DAT_40000070 = _DAT_40000070 & 0xff9fffff | uVar6;
    if (iVar5 == 0) goto LAB_04108144;
  }
  if (iVar4 == 0) {
    *DAT_041082bc = 0xffffffff;
  }
LAB_0410815e:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar4);
  }
  if (!bVar2) {
    _DAT_40000064 = 0x20;
    return 0;
  }
  return 0;
}



// ===========================================================
// Function: FUN_041082d0 at 041082d0
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_041082d0(void)

{
  undefined4 uVar1;
  
  if ((int)(_DAT_40000060 << 6) < 0) {
    return 0x13;
  }
  if ((int)(_DAT_40000060 << 0x14) < 0) {
    if ((int)(_DAT_40000060 << 0x13) < 0) {
      return 0x13;
    }
    if ((_DAT_400000a8 & 3) != 0) {
      if ((_DAT_400000a8 & 3) == 1) {
        uVar1 = 0xd;
      }
      else {
        uVar1 = 0xb;
      }
      return uVar1;
    }
  }
  else if ((_DAT_40000060 & 0x600) != 0x400) {
    if ((_DAT_40000060 & 0x600) != 0x600) {
      if ((_DAT_40000060 & 0x100) == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 7;
      }
      return uVar1;
    }
    return 0xb;
  }
  return 0xf;
}



// ===========================================================
// Function: FUN_04108320 at 04108320
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_04108320(uint param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 unaff_lr;
  
  iVar8 = DAT_04108480;
  if (0x13 < param_1) {
    return 1;
  }
  if (param_1 < 3) {
    uVar9 = 0x60000000;
LAB_04108332:
    uVar7 = *(uint *)(DAT_04108480 + 0x184) & 0x2000;
    if (uVar7 == 0) {
      iVar8 = *(int *)(DAT_04108480 + 0x4c);
      iVar4 = 0;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        iVar4 = getBasePriority();
      }
      bVar2 = false;
      iVar6 = DAT_04108480;
      puVar3 = DAT_04108484;
      goto joined_r0x041083f2;
    }
    bVar2 = false;
LAB_04108342:
    _DAT_40000004 = 0x40000;
    _DAT_4000017c = 0x8200000;
    *(undefined4 *)(DAT_04108480 + 0x184) = 0x2000;
    DataSynchronizationBarrier(0xf);
    iVar8 = *(int *)(iVar8 + 0x4c);
    if (bVar2) goto LAB_0410836a;
  }
  else {
    if (param_1 == 3) {
      uVar9 = 0x20000000;
      goto LAB_04108332;
    }
    if (param_1 < 8) {
      uVar9 = 0;
      goto LAB_04108332;
    }
    if (param_1 < 0xc) {
      uVar9 = 0x1000000;
      goto LAB_04108332;
    }
    uVar7 = *(uint *)(DAT_04108480 + 0x184) & 0x2000;
    if (uVar7 != 0) {
      bVar2 = true;
      uVar9 = 0x800000;
      goto LAB_04108342;
    }
    bVar2 = true;
    uVar9 = 0x800000;
    iVar8 = *(int *)(DAT_04108480 + 0x4c);
LAB_0410836a:
    puVar3 = DAT_04108484;
    iVar4 = DAT_04108480;
    if (-1 < iVar8 << 8) {
      iVar6 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        iVar6 = getBasePriority();
      }
      if (iVar6 == 0x40) {
        *(uint *)(DAT_04108480 + 0x4c) = *(uint *)(DAT_04108480 + 0x4c) | 0x400000;
      }
      else {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(0x40);
        }
        *DAT_04108484 = 0x4108430;
        puVar3[1] = unaff_lr;
        *(uint *)(iVar4 + 0x4c) = *(uint *)(iVar4 + 0x4c) | 0x400000;
        if (iVar6 == 0) {
          *puVar3 = 0xffffffff;
        }
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(iVar6);
      }
      FUN_04107c1c(1,0xb);
    }
  }
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  iVar6 = DAT_04108480;
  puVar3 = DAT_04108484;
  if (bVar1) {
    iVar4 = getBasePriority();
  }
joined_r0x041083f2:
  DAT_04108480 = iVar6;
  DAT_04108484 = puVar3;
  if (iVar4 == 0x40) {
    *(uint *)(iVar6 + 0x4c) = *(uint *)(iVar6 + 0x4c) & 0x987fffff | uVar9;
  }
  else {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *puVar3 = 0x4108380;
    puVar3[1] = unaff_lr;
    *(uint *)(iVar6 + 0x4c) = *(uint *)(iVar6 + 0x4c) & 0x987fffff | uVar9;
    if (iVar4 == 0) {
      *puVar3 = 0xffffffff;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar4);
  }
  uVar5 = *(undefined4 *)(DAT_04108480 + 0x4c);
  DataSynchronizationBarrier(0xf);
  if (uVar7 != 0) {
    uVar5 = 0x40000000;
    *(undefined4 *)(DAT_04108480 + 0x180) = 0x2000;
    _DAT_40000000 = 0x40000;
    _DAT_40000178 = 0x8200000;
  }
  DataSynchronizationBarrier(0xf);
  if ((!bVar2) && (iVar8 << 8 < 0)) {
    FUN_04107cd4(1,0xb,uVar5);
    return 0;
  }
  return 0;
}



// ===========================================================
// Function: FUN_04108488 at 04108488
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_04108488(uint param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_lr;
  
  uVar3 = _DAT_40000014;
  puVar2 = DAT_041085d8;
  if (0x13 < param_1) {
    return 1;
  }
  if (param_1 < 8) {
    _DAT_40000064 = DAT_041085d0;
    if ((_DAT_40000014 & 2) == 0) {
      _DAT_40000060 = 0;
      goto LAB_041084f6;
    }
    DataSynchronizationBarrier(0xf);
    _DAT_40000060 = 0;
LAB_041084b0:
    _DAT_40000014 = 2;
    _DAT_40000004 = 0x40;
  }
  else {
    if (param_1 < 0xc) {
      _DAT_40000064 = DAT_041085d4;
      if (-1 < (int)(_DAT_40000014 << 0x1e)) {
        _DAT_40000060 = 4;
        goto LAB_041084f6;
      }
      DataSynchronizationBarrier(0xf);
      _DAT_40000060 = 4;
      goto LAB_041084b0;
    }
    if (param_1 < 0xe) {
      if ((_DAT_40000014 & 2) == 0) {
        uVar4 = 0x40;
        goto LAB_04108522;
      }
      DataSynchronizationBarrier(0xf);
      iVar5 = 1;
LAB_0410857e:
      _DAT_40000014 = 2;
      _DAT_40000004 = 0x40;
      uVar4 = iVar5 << 6;
      iVar5 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        iVar5 = getBasePriority();
      }
      if (iVar5 != 0x40) goto LAB_0410852a;
LAB_04108588:
      _DAT_400000a8 = _DAT_400000a8 & 0xffffff3f | uVar4;
    }
    else {
      if (0xf < param_1) {
        _DAT_40000064 = DAT_041085e0;
        if (-1 < (int)(_DAT_40000014 << 0x1e)) {
          _DAT_40000060 = 0x18;
          goto LAB_041084f6;
        }
        DataSynchronizationBarrier(0xf);
        _DAT_40000060 = 0x18;
        goto LAB_041084b0;
      }
      if ((_DAT_40000014 & 2) != 0) {
        DataSynchronizationBarrier(0xf);
        iVar5 = 0;
        goto LAB_0410857e;
      }
      uVar4 = 0;
LAB_04108522:
      iVar5 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        iVar5 = getBasePriority();
      }
      if (iVar5 == 0x40) goto LAB_04108588;
LAB_0410852a:
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(0x40);
      }
      *DAT_041085d8 = 0x4108534;
      puVar2[1] = unaff_lr;
      _DAT_400000a8 = _DAT_400000a8 & 0xffffff3f | uVar4;
      if (iVar5 == 0) {
        *puVar2 = 0xffffffff;
      }
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(iVar5);
    }
    _DAT_40000060 = 9;
    _DAT_40000064 = DAT_041085dc;
    if ((uVar3 & 2) == 0) goto LAB_041084f6;
  }
  _DAT_40000000 = 0x40;
  _DAT_40000010 = 2;
LAB_041084f6:
  DataSynchronizationBarrier(0xf);
  return 0;
}



// ===========================================================
// Function: FUN_041085e4 at 041085e4
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_041085e4(uint param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_lr;
  
  uVar3 = _DAT_40000014;
  puVar2 = DAT_04108758;
  if (0x13 < param_1) {
    return 1;
  }
  if (param_1 < 8) {
    _DAT_40000064 = DAT_04108750;
    if ((_DAT_40000014 & 0x200000) == 0) {
      _DAT_40000060 = 0;
      goto LAB_0410865c;
    }
    DataSynchronizationBarrier(0xf);
    _DAT_40000060 = 0;
LAB_04108610:
    _DAT_40000014 = 0x200000;
    _DAT_40000004 = 0x20000000;
  }
  else {
    if (param_1 < 0xc) {
      _DAT_40000064 = DAT_04108754;
      if (-1 < (int)(_DAT_40000014 << 10)) {
        _DAT_40000060 = 0x200000;
        goto LAB_0410865c;
      }
      _DAT_40000060 = 0x200000;
      DataSynchronizationBarrier(0xf);
      goto LAB_04108610;
    }
    if (param_1 < 0xe) {
      if ((_DAT_40000014 & 0x200000) == 0) {
        uVar4 = 0x2000;
        goto LAB_0410868e;
      }
      DataSynchronizationBarrier(0xf);
      iVar5 = 1;
LAB_041086f4:
      _DAT_40000014 = 0x200000;
      _DAT_40000004 = 0x20000000;
      uVar4 = iVar5 << 0xd;
      iVar5 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        iVar5 = getBasePriority();
      }
      if (iVar5 != 0x40) goto LAB_04108696;
LAB_041086fe:
      _DAT_4000013c = _DAT_4000013c & 0xffff9fff | uVar4;
    }
    else {
      if (0xf < param_1) {
        _DAT_40000064 = DAT_0410875c;
        if (-1 < (int)(_DAT_40000014 << 10)) {
          _DAT_40000060 = 0xc00000;
          goto LAB_0410865c;
        }
        DataSynchronizationBarrier(0xf);
        _DAT_40000060 = 0xc00000;
        goto LAB_04108610;
      }
      if ((_DAT_40000014 & 0x200000) != 0) {
        DataSynchronizationBarrier(0xf);
        iVar5 = 0;
        goto LAB_041086f4;
      }
      uVar4 = 0;
LAB_0410868e:
      iVar5 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        iVar5 = getBasePriority();
      }
      if (iVar5 == 0x40) goto LAB_041086fe;
LAB_04108696:
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(0x40);
      }
      *DAT_04108758 = 0x41086a0;
      puVar2[1] = unaff_lr;
      _DAT_4000013c = _DAT_4000013c & 0xffff9fff | uVar4;
      if (iVar5 == 0) {
        *puVar2 = 0xffffffff;
      }
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(iVar5);
    }
    _DAT_40000060 = 0x480000;
    _DAT_40000064 = 0x8800000;
    if ((uVar3 & 0x200000) == 0) goto LAB_0410865c;
  }
  _DAT_40000000 = 0x20000000;
  _DAT_40000010 = 0x200000;
LAB_0410865c:
  DataSynchronizationBarrier(0xf);
  return 0;
}



// ===========================================================
// Function: FUN_04108760 at 04108760
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_04108760(uint param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_lr;
  
  uVar3 = _DAT_50000014;
  puVar2 = DAT_041088ac;
  if (0x13 < param_1) {
    return 1;
  }
  if (param_1 < 8) {
    _DAT_50000064 = DAT_041088a4;
    if ((_DAT_50000014 & 2) == 0) {
      _DAT_50000060 = 0;
      goto LAB_041087ce;
    }
    DataSynchronizationBarrier(0xf);
    _DAT_50000060 = 0;
LAB_04108788:
    _DAT_50000014 = 2;
    _DAT_50000004 = 0x10;
  }
  else {
    if (param_1 < 0xc) {
      _DAT_50000064 = DAT_041088a8;
      if (-1 < (int)(_DAT_50000014 << 0x1e)) {
        _DAT_50000060 = 4;
        goto LAB_041087ce;
      }
      DataSynchronizationBarrier(0xf);
      _DAT_50000060 = 4;
      goto LAB_04108788;
    }
    if (param_1 < 0xe) {
      if ((_DAT_50000014 & 2) == 0) {
        uVar4 = 4;
        goto LAB_041087fa;
      }
      DataSynchronizationBarrier(0xf);
      iVar5 = 1;
LAB_04108856:
      _DAT_50000014 = 2;
      _DAT_50000004 = 0x10;
      uVar4 = iVar5 << 2;
      iVar5 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        iVar5 = getBasePriority();
      }
      if (iVar5 != 0x40) goto LAB_04108802;
LAB_04108860:
      _DAT_50000068 = _DAT_50000068 & 0xfffffff3 | uVar4;
    }
    else {
      if (0xf < param_1) {
        _DAT_50000064 = DAT_041088b4;
        if (-1 < (int)(_DAT_50000014 << 0x1e)) {
          _DAT_50000060 = 0x18;
          goto LAB_041087ce;
        }
        DataSynchronizationBarrier(0xf);
        _DAT_50000060 = 0x18;
        goto LAB_04108788;
      }
      if ((_DAT_50000014 & 2) != 0) {
        DataSynchronizationBarrier(0xf);
        iVar5 = 0;
        goto LAB_04108856;
      }
      uVar4 = 0;
LAB_041087fa:
      iVar5 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        iVar5 = getBasePriority();
      }
      if (iVar5 == 0x40) goto LAB_04108860;
LAB_04108802:
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(0x40);
      }
      *DAT_041088ac = 0x410880c;
      puVar2[1] = unaff_lr;
      _DAT_50000068 = _DAT_50000068 & 0xfffffff3 | uVar4;
      if (iVar5 == 0) {
        *puVar2 = 0xffffffff;
      }
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(iVar5);
    }
    _DAT_50000060 = 9;
    _DAT_50000064 = DAT_041088b0;
    if ((uVar3 & 2) == 0) goto LAB_041087ce;
  }
  _DAT_50000000 = 0x10;
  _DAT_50000010 = 2;
LAB_041087ce:
  DataSynchronizationBarrier(0xf);
  return 0;
}



// ===========================================================
// Function: FUN_041088b8 at 041088b8
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_041088b8(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_lr;
  
  puVar2 = DAT_04108920;
  uVar3 = 0;
  if (param_1 != 0) {
    if (param_1 == 1) {
      uVar3 = 0x8000;
    }
    else {
      uVar3 = 0x18000;
    }
  }
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 == 0x40) {
    _DAT_4000013c = uVar3 | _DAT_4000013c & 0xfffe7fff;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    return 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x40);
  }
  *DAT_04108920 = 0x41088da;
  puVar2[1] = unaff_lr;
  _DAT_4000013c = uVar3 | _DAT_4000013c & 0xfffe7fff;
  if (iVar4 == 0) {
    *puVar2 = 0xffffffff;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar4);
  }
  return 0;
}



// ===========================================================
// Function: FUN_04108924 at 04108924
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_04108924(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_lr;
  
  puVar2 = DAT_0410898c;
  uVar3 = 0;
  if (param_1 != 0) {
    if (param_1 == 1) {
      uVar3 = 0x20000;
    }
    else {
      uVar3 = 0x60000;
    }
  }
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 == 0x40) {
    _DAT_4000013c = uVar3 | _DAT_4000013c & 0xfff9ffff;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    return 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x40);
  }
  *DAT_0410898c = 0x4108946;
  puVar2[1] = unaff_lr;
  _DAT_4000013c = uVar3 | _DAT_4000013c & 0xfff9ffff;
  if (iVar4 == 0) {
    *puVar2 = 0xffffffff;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar4);
  }
  return 0;
}



// ===========================================================
// Function: FUN_04108990 at 04108990
// ===========================================================

undefined4 FUN_04108990(void)

{
  return 0;
}



// ===========================================================
// Function: FUN_04108994 at 04108994
// ===========================================================

uint FUN_04108994(void)

{
  return *DAT_0410899c >> 0x10;
}



// ===========================================================
// Function: FUN_041089cc at 041089cc
// ===========================================================

void FUN_041089cc(byte param_1)

{
  *(uint *)(DAT_041089e0 + 0xf8) = *(uint *)(DAT_041089e0 + 0xf8) & 0xffffff00 | (uint)param_1;
  return;
}



// ===========================================================
// Function: FUN_041089e4 at 041089e4
// ===========================================================

void FUN_041089e4(void)

{
  int iVar1;
  
  iVar1 = DAT_04108a34;
  *(undefined4 *)(DAT_04108a34 + 0x88) = 0xffff;
  *(undefined4 *)(iVar1 + 0x90) = 0xffff;
  *(undefined4 *)(iVar1 + 0xb0) = 0xffff;
  *(undefined4 *)(iVar1 + 0xe8) = 0xffff;
  *(undefined4 *)(iVar1 + 0x24) = 0xffff;
  *(undefined4 *)(iVar1 + 0x2c) = 0xffff;
  *(undefined4 *)(iVar1 + 0x16c) = 0xffff;
  *(undefined4 *)(iVar1 + 0xd4) = 0xffff;
  *(undefined4 *)(iVar1 + 0x144) = 0xffff;
  *(undefined4 *)(iVar1 + 0x9c) = 0xff0000;
  iVar1 = DAT_04108a38;
  DataSynchronizationBarrier(0xf);
  *(undefined4 *)(DAT_04108a38 + 0x168) = 0;
  *(undefined4 *)(iVar1 + 0x16c) = 0;
  *(undefined4 *)(iVar1 + 0x174) = 0;
  DataSynchronizationBarrier(0xf);
  return;
}



// ===========================================================
// Function: FUN_04108a3c at 04108a3c
// ===========================================================

undefined4 FUN_04108a3c(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 unaff_lr;
  
  puVar2 = DAT_04108b38;
  if (0x11 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_04108b4c,param_1,param_1,param_4,param_4);
  }
  if (0x13 < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_04108b50);
  }
  iVar10 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar10 = getBasePriority();
  }
  if (iVar10 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04108b38 = 0x4108a5c;
    puVar2[1] = unaff_lr;
  }
  pbVar3 = DAT_04108b3c;
  if (*DAT_04108b3c < 0x12) {
    uVar5 = (uint)DAT_04108b40[*DAT_04108b3c];
  }
  else {
    uVar5 = FUN_041082d0();
  }
  pbVar6 = DAT_04108b40;
  DAT_04108b40[param_1] = (byte)param_2;
  pbVar4 = DAT_04108b44;
  bVar7 = (byte)param_1;
  if (param_2 == uVar5) {
    *pbVar3 = bVar7;
  }
  else if (param_2 < uVar5) {
    if (*pbVar3 == param_1) {
      param_2 = (uint)*pbVar6;
      uVar9 = 0;
      uVar8 = 1;
      pbVar6 = DAT_04108b48;
      do {
        if (param_2 < *pbVar6) {
          uVar9 = uVar8 & 0xff;
          param_2 = (uint)*pbVar6;
        }
        uVar8 = uVar8 + 1;
        pbVar6 = pbVar6 + 1;
      } while (uVar8 != 0x12);
      *pbVar3 = (byte)uVar9;
      if (param_2 == uVar5) goto LAB_04108a7e;
    }
    else {
      if (*pbVar3 != 0x12) goto LAB_04108a7e;
      *pbVar3 = bVar7;
    }
    if (param_2 == 0) {
      param_2 = 7;
    }
    uVar8 = (uint)*DAT_04108b44;
    if (param_2 < uVar8) {
      param_2 = uVar8;
    }
    if (uVar5 == 0) {
      uVar5 = 7;
    }
    param_2 = param_2 & 0xff;
    if (uVar5 < uVar8) {
      uVar5 = uVar8;
    }
    if ((uVar5 & 0xff) != param_2) {
      FUN_041080d0(param_2);
      FUN_04101e58(param_2);
    }
  }
  else {
    *pbVar3 = bVar7;
    bVar7 = *pbVar4;
    uVar8 = (uint)bVar7;
    if (param_2 == 0) {
      param_2 = 7;
    }
    if (param_2 < uVar8) {
      param_2 = uVar8;
    }
    if (uVar5 == 0) {
      uVar5 = 7;
    }
    param_2 = param_2 & 0xff;
    if (uVar8 < uVar5) {
      bVar7 = (byte)uVar5;
    }
    if (bVar7 != param_2) {
      FUN_04101e58(param_2);
      FUN_041080d0(param_2);
    }
  }
LAB_04108a7e:
  if (iVar10 == 0) {
    *DAT_04108b38 = 0xffffffff;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar10);
  }
  return 0;
}



// ===========================================================
// Function: FUN_04108b54 at 04108b54
// ===========================================================

void FUN_04108b54(void)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_lr;
  
  iVar3 = DAT_04108bbc;
  puVar2 = DAT_04108bb8;
  if (*DAT_04108bb4 != 0) {
    iVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar5 = getBasePriority();
    }
    if (iVar5 != 0x40) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(0x40);
      }
      *DAT_04108bb8 = 0x4108b6e;
      uVar4 = DAT_04108bc0;
      puVar2[1] = unaff_lr;
      *(undefined4 *)(iVar3 + 0xc00) = uVar4;
      *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xfffffffe;
      *(undefined4 *)(iVar3 + 0xc00) = 1;
      if (iVar5 == 0) {
        *puVar2 = 0xffffffff;
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(iVar5);
      }
      return;
    }
    *(undefined4 *)(DAT_04108bbc + 0xc00) = DAT_04108bc0;
    *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xfffffffe;
    *(undefined4 *)(iVar3 + 0xc00) = 1;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
  }
  return;
}



// ===========================================================
// Function: FUN_04108bc4 at 04108bc4
// ===========================================================

void FUN_04108bc4(void)

{
  bool bVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 in_r3;
  uint uVar8;
  int iVar9;
  ushort uVar10;
  uint uVar11;
  int iVar12;
  ushort uVar13;
  undefined4 unaff_lr;
  
  puVar3 = DAT_04108ce0;
  puVar2 = DAT_04108cdc;
  iVar12 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar12 = getBasePriority();
  }
  if (iVar12 == 0x40) {
    if ((char)DAT_04108ce0[3] != '\0') {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(0x40);
      }
      return;
    }
  }
  else {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04108cdc = 0x4108bda;
    uVar10 = puVar3[3];
    puVar2[1] = unaff_lr;
    if ((char)uVar10 != '\0') goto LAB_04108c8a;
  }
  iVar9 = DAT_04108cf0;
  iVar5 = DAT_04108ce8;
  uVar10 = *puVar3;
  uVar7 = (uint)uVar10;
  uVar11 = (uint)puVar3[1];
  if (uVar7 == uVar11) goto LAB_04108c8a;
  if (uVar11 < uVar7) {
    uVar8 = uVar7 - uVar11;
    if (0xfff < uVar8) {
LAB_04108c2c:
      uVar8 = uVar8 - 0xfff;
      uVar10 = 0xfff;
      *(uint *)(DAT_04108ce8 + 0xc) = DAT_04108ce4 + uVar11;
      if (0xffe < uVar8) {
        uVar8 = 0xfff;
      }
      uVar13 = (ushort)uVar8;
      *(undefined2 *)(iVar5 + 2) = 0xfff;
      FUN_0410e484(iVar9 + -0x10,iVar5,iVar9,0,in_r3);
      iVar9 = DAT_04108ce4;
      if (uVar11 == 0) {
        iVar9 = DAT_04108cf4;
        uVar10 = 0xfff;
      }
      goto LAB_04108c5e;
    }
    *(uint *)(DAT_04108ce8 + 0xc) = DAT_04108ce4 + uVar11;
LAB_04108c0a:
    uVar4 = DAT_04108cec;
    iVar9 = DAT_04108ce8;
    uVar10 = (ushort)uVar8;
    uVar13 = 0;
    *(ushort *)(iVar5 + 2) = uVar10;
    FUN_0410e484(uVar4,iVar9,0,1,in_r3);
  }
  else {
    uVar8 = 0x1000 - uVar11;
    if (0xfff < uVar8) goto LAB_04108c2c;
    *(uint *)(DAT_04108ce8 + 0xc) = DAT_04108ce4 + uVar11;
    iVar9 = DAT_04108cf0;
    uVar13 = 0xfff;
    if (uVar7 < 0x1000) {
      uVar13 = uVar10;
    }
    if (uVar7 == 0) goto LAB_04108c0a;
    uVar10 = (ushort)uVar8;
    iVar6 = DAT_04108cf0 + -0x10;
    *(ushort *)(iVar5 + 2) = uVar10;
    FUN_0410e484(iVar6,iVar5,iVar9,0,in_r3);
    iVar9 = DAT_04108ce4;
LAB_04108c5e:
    *(int *)(iVar5 + 0xc) = iVar9;
    iVar6 = DAT_04108cf0;
    iVar9 = DAT_04108ce8;
    *(ushort *)(iVar5 + 2) = uVar13;
    FUN_0410e484(iVar6,iVar9,0,1,in_r3);
  }
  uVar4 = DAT_04108cec;
  iVar5 = DAT_04108ce8;
  puVar3[5] = uVar10;
  puVar3[6] = uVar13;
  iVar5 = FUN_0410ea14(uVar4,iVar5);
  if (iVar5 == 0) {
    *(undefined1 *)(puVar3 + 3) = 1;
  }
LAB_04108c8a:
  if (iVar12 == 0) {
    *DAT_04108cdc = 0xffffffff;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar12);
  }
  return;
}



// ===========================================================
// Function: FUN_04108d84 at 04108d84
// ===========================================================

undefined1 FUN_04108d84(void)

{
  char cVar1;
  bool bVar2;
  short *psVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 unaff_lr;
  
  puVar4 = DAT_04108e4c;
  psVar3 = DAT_04108e48;
  iVar11 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    iVar11 = getBasePriority();
  }
  if (iVar11 == 0x40) {
    if (*(char *)((int)DAT_04108e48 + 9) != '\0') {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(0x40);
      }
      return 0;
    }
    iVar8 = FUN_0410ad54();
    if (*psVar3 == psVar3[1]) {
      uVar7 = 0;
      goto LAB_04108db2;
    }
LAB_04108dcc:
    iVar9 = FUN_0410ad54();
    pbVar6 = DAT_04108e54;
    puVar5 = DAT_04108e50;
    uVar10 = iVar9 - iVar8;
    while (uVar10 < 32000) {
      do {
        iVar9 = FUN_0410ed78(*puVar5);
      } while (iVar9 != 0);
      iVar9 = FUN_0410ed24(*puVar5);
      if (((iVar9 != 0) && (*(char *)((int)psVar3 + 9) == '\0')) && (*pbVar6 - 2 < 3)) {
        FUN_04108bc4();
      }
      if (*psVar3 == psVar3[1]) goto LAB_04108da6;
      iVar9 = FUN_0410ad54();
      uVar10 = iVar9 - iVar8;
    }
    uVar7 = 1;
  }
  else {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(0x40);
    }
    cVar1 = *(char *)((int)DAT_04108e48 + 9);
    *DAT_04108e4c = 0x4108d9a;
    puVar4[1] = unaff_lr;
    if ((cVar1 == '\0') && (iVar8 = FUN_0410ad54(), psVar3[1] != *psVar3)) goto LAB_04108dcc;
LAB_04108da6:
    uVar7 = 0;
  }
  if (iVar11 == 0) {
    *DAT_04108e4c = 0xffffffff;
  }
LAB_04108db2:
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(iVar11);
  }
  return uVar7;
}



// ===========================================================
// Function: FUN_04108e58 at 04108e58
// ===========================================================

uint FUN_04108e58(int param_1,uint param_2)

{
  bool bVar1;
  char cVar2;
  ushort uVar3;
  ushort *puVar4;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  undefined4 unaff_lr;
  char acStack_34 [16];
  
  puVar5 = DAT_04109044;
  puVar4 = DAT_04109040;
  iVar13 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar13 = getBasePriority();
  }
  if (iVar13 == 0x40) {
    if (*(char *)((int)DAT_04109040 + 7) != '\0') goto LAB_04108f52;
  }
  else {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04109044 = 0x4108e74;
    puVar5[1] = unaff_lr;
    if (*(char *)((int)puVar4 + 7) != '\0') {
      if (iVar13 == 0) {
        *puVar5 = 0xffffffff;
        bVar1 = (bool)isCurrentModePrivileged();
        if (!bVar1) {
          return param_2;
        }
        setBasePriority(0);
        return param_2;
      }
      goto LAB_04108f52;
    }
  }
  uVar8 = (uint)puVar4[2];
  *(undefined1 *)((int)puVar4 + 7) = 1;
  iVar6 = DAT_04109050;
  uVar12 = (uint)*puVar4;
  uVar10 = (uint)puVar4[1];
  if (uVar12 < uVar10) {
    iVar11 = uVar10 - 1;
  }
  else {
    iVar11 = uVar10 + 0xfff;
  }
  if (uVar8 == 0) {
    uVar8 = uVar12;
    iVar14 = DAT_04109048;
    if (param_2 <= iVar11 - uVar12) goto LAB_04108ee8;
  }
  else {
    if (param_2 + 0xd <= iVar11 - uVar12) {
      pcVar9 = acStack_34;
      do {
        pcVar7 = pcVar9;
        uVar10 = (uint)((ulonglong)DAT_04109054 * (ulonglong)uVar8 >> 0x23);
        cVar2 = (char)uVar8 + (char)uVar10 * -10 + '0';
        *pcVar7 = cVar2;
        bVar1 = 9 < uVar8;
        pcVar9 = pcVar7 + 1;
        uVar8 = uVar10;
      } while (bVar1);
      *(char *)(DAT_04109050 + 6) = cVar2;
      iVar11 = 1;
      pcVar9 = (char *)(iVar6 + 7);
      do {
        if (pcVar7 <= acStack_34) {
          iVar11 = iVar11 + 6;
          goto LAB_04108fc0;
        }
        iVar11 = iVar11 + 1;
        pcVar7 = pcVar7 + -1;
        *pcVar9 = *pcVar7;
        pcVar9 = pcVar9 + 1;
      } while (iVar11 != 5);
      iVar11 = 0xb;
LAB_04108fc0:
      iVar14 = DAT_04109048;
      uVar3 = (short)iVar11 + 1;
      uVar10 = (uint)uVar3;
      uVar8 = 0x1000 - uVar12 & 0xffff;
      *(undefined1 *)(iVar6 + iVar11) = 10;
      if (uVar10 <= uVar8) {
        uVar8 = uVar10;
      }
      FUN_0410ef70(iVar14 + uVar12,DAT_04109050);
      if (uVar8 < uVar10) {
        FUN_0410ef70(iVar14,iVar6 + uVar8,uVar3 - uVar8);
      }
      uVar8 = uVar3 + uVar12;
      puVar4[2] = 0;
      if (0xfff < uVar8) {
        uVar8 = uVar8 - 0x1000;
      }
      uVar12 = uVar8 & 0xffff;
LAB_04108ee8:
      uVar10 = 0x1000 - uVar12 & 0xffff;
      if (uVar10 < param_2) {
        FUN_0410ef70(iVar14 + uVar8,param_1,uVar10);
LAB_04108f00:
        FUN_0410ef70(DAT_04109048,param_1 + uVar10,param_2 - uVar10);
      }
      else {
        uVar10 = param_2 & 0xffff;
        FUN_0410ef70(iVar14 + uVar8,param_1,uVar10);
        if (uVar10 < param_2) goto LAB_04108f00;
      }
      uVar8 = uVar8 + param_2;
      if (0xfff < uVar8) {
        uVar8 = uVar8 - 0x1000;
        *(undefined1 *)(puVar4 + 4) = 1;
      }
      *puVar4 = (ushort)uVar8;
      if (*(char *)((int)puVar4 + 9) == '\0') {
        if (*DAT_0410904c - 2 < 3) {
          FUN_04108bc4();
        }
        *(undefined1 *)((int)puVar4 + 7) = 0;
      }
      else {
        *(undefined1 *)((int)puVar4 + 7) = 0;
      }
      if (iVar13 == 0) {
        *DAT_04109044 = 0xffffffff;
        bVar1 = (bool)isCurrentModePrivileged();
        if (!bVar1) {
          return param_2;
        }
        setBasePriority(0);
        return param_2;
      }
LAB_04108f52:
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(iVar13);
      }
      return param_2;
    }
    if (uVar8 == 0xffff) {
      *(undefined1 *)((int)puVar4 + 7) = 0;
      goto joined_r0x04108f62;
    }
  }
  puVar4[2] = puVar4[2] + 1;
  *(undefined1 *)((int)puVar4 + 7) = 0;
joined_r0x04108f62:
  if (iVar13 == 0) {
    *DAT_04109044 = 0xffffffff;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0);
    }
    return 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (!bVar1) {
    return 0;
  }
  setBasePriority(iVar13);
  return 0;
}



// ===========================================================
// Function: FUN_04109058 at 04109058
// ===========================================================

undefined4 FUN_04109058(uint param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  ushort uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 unaff_lr;
  undefined1 auStack_94 [132];
  
  puVar3 = DAT_04109114;
  puVar2 = DAT_04109110;
  uVar5 = (param_1 & 0x7f) >> 4;
  if (*DAT_04109108 < uVar5) {
    return 0;
  }
  if ((uVar5 != 0) &&
     ((1 << ((param_1 & 0xfff) >> 7) & *(uint *)(DAT_0410910c + ((param_1 & 0x3fff) >> 0xc) * 4)) ==
      0)) {
    return 0;
  }
  iVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar8 = getBasePriority();
  }
  if (iVar8 == 0x40) {
    uVar5 = *DAT_04109114 + 1;
    if (9999 < uVar5) {
      *DAT_04109114 = 0;
      goto LAB_041090b6;
    }
LAB_041090a8:
    uVar4 = (ushort)uVar5;
  }
  else {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_04109110 = 0x4109096;
    puVar2[1] = unaff_lr;
    uVar5 = *puVar3 + 1;
    if (uVar5 < 10000) goto LAB_041090a8;
    uVar4 = 0;
  }
  *puVar3 = uVar4;
  if (iVar8 == 0) {
    *DAT_04109110 = 0xffffffff;
  }
LAB_041090b6:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar8);
  }
  uVar5 = FUN_0410ef50(auStack_94,0x82,param_2,param_3);
  if (0x80 < (int)uVar5) {
    uVar5 = 0x81;
  }
  uVar5 = uVar5 & ~((int)uVar5 >> 0x1f);
  uVar7 = uVar5;
  if (-1 < (int)(param_1 << 0x10)) {
    uVar7 = uVar5 + 1;
    auStack_94[uVar5] = 10;
  }
  uVar6 = FUN_04108e58(auStack_94,uVar7);
  return uVar6;
}



// ===========================================================
// Function: FUN_04109118 at 04109118
// ===========================================================

undefined4 FUN_04109118(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  undefined4 uVar2;
  
  pbVar1 = DAT_04109178;
  if (*DAT_04109174 == '\0') {
    uVar2 = 0;
  }
  else if (param_1 << 0x11 < 0) {
    if (*DAT_04109178 - 2 < 3) {
      FUN_04108d84();
    }
    uVar2 = FUN_04109058(param_1,param_2);
    if (*pbVar1 - 2 < 3) {
      FUN_04108d84();
    }
  }
  else {
    uVar2 = FUN_04109058(param_1,param_2);
  }
  return uVar2;
}



// ===========================================================
// Function: FUN_04109194 at 04109194
// ===========================================================

uint FUN_04109194(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = FUN_0410ef50(param_1,param_2,param_3);
  if (-1 < (int)uVar1) {
    if (param_2 <= uVar1) {
      if (param_2 == 0) {
        param_2 = 1;
      }
      uVar1 = param_2 - 1;
    }
    return uVar1;
  }
  return 0;
}



// ===========================================================
// Function: FUN_041091d0 at 041091d0
// ===========================================================

undefined4 FUN_041091d0(uint param_1,undefined4 param_2,int param_3,undefined1 *param_4,int param_5)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined2 *puVar8;
  undefined1 auStack_124 [256];
  
  uVar5 = (param_1 & 0x7f) >> 4;
  if (*DAT_0410930c < uVar5) {
    return 0;
  }
  if ((uVar5 != 0) &&
     ((1 << ((param_1 & 0xfff) >> 7) & *(uint *)(DAT_04109310 + ((param_1 & 0x3fff) >> 0xc) * 4)) ==
      0)) {
    return 0;
  }
  if (param_3 == 2) {
    if (param_4 == (undefined1 *)0x0) goto LAB_04109302;
    puVar4 = (undefined1 *)0x0;
    puVar8 = (undefined2 *)(param_5 + -2);
    puVar6 = (undefined1 *)0x0;
    do {
      puVar4 = puVar4 + 1;
      puVar8 = puVar8 + 1;
      iVar2 = FUN_04109194(auStack_124 + (int)puVar6,0xfa - (int)puVar6,param_2,*puVar8);
      puVar6 = puVar6 + iVar2;
      if (param_4 <= puVar4) break;
    } while (puVar6 < (undefined1 *)0xfa);
  }
  else if (param_3 == 4) {
    if (param_4 == (undefined1 *)0x0) goto LAB_04109302;
    puVar4 = (undefined1 *)0x0;
    puVar7 = (undefined4 *)(param_5 + -4);
    puVar6 = (undefined1 *)0x0;
    do {
      puVar4 = puVar4 + 1;
      puVar7 = puVar7 + 1;
      iVar2 = FUN_04109194(auStack_124 + (int)puVar6,0xfa - (int)puVar6,param_2,*puVar7);
      puVar6 = puVar6 + iVar2;
      if (param_4 <= puVar4) break;
    } while (puVar6 < (undefined1 *)0xfa);
  }
  else {
    if (param_4 == (undefined1 *)0x0) {
LAB_04109302:
      puVar4 = (undefined1 *)0x1;
      goto LAB_04109248;
    }
    puVar6 = (undefined1 *)0x0;
    puVar4 = (undefined1 *)(param_5 + -1);
    do {
      iVar2 = FUN_04109194(auStack_124 + (int)puVar6,0xfa - (int)puVar6,param_2,puVar4[1]);
      puVar6 = puVar6 + iVar2;
      if (param_4 <= puVar4 + (2 - param_5)) break;
      puVar4 = puVar4 + 1;
    } while (puVar6 < (undefined1 *)0xfa);
  }
  puVar4 = puVar6 + 1;
  param_4 = puVar6;
  if ((undefined1 *)0xfa < puVar4) {
    puVar4 = (undefined1 *)0xfa;
    param_4 = (undefined1 *)0xf9;
  }
LAB_04109248:
  pbVar1 = DAT_04109314;
  auStack_124[(int)param_4] = 10;
  if ((param_1 & 0x4000) == 0) {
    uVar3 = FUN_04108e58(auStack_124);
  }
  else {
    if (*DAT_04109314 - 2 < 3) {
      FUN_04108d84();
    }
    uVar3 = FUN_04108e58(auStack_124,puVar4);
    if (*pbVar1 - 2 < 3) {
      FUN_04108d84();
    }
  }
  return uVar3;
}



// ===========================================================
// Function: FUN_04109318 at 04109318
// ===========================================================

undefined4 FUN_04109318(void)

{
  undefined4 uVar1;
  
  if (*DAT_04109330 != '\0') {
    uVar1 = FUN_041091d0();
    return uVar1;
  }
  return 0;
}



// ===========================================================
// Function: FUN_04109484 at 04109484
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void FUN_04109484(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 in_r12;
  undefined4 unaff_lr;
  undefined4 auStack_68 [20];
  
  puVar7 = DAT_041094c4;
  puVar4 = DAT_041094c4 + 1;
  *DAT_041094c4 = param_1;
  *puVar4 = param_2;
  puVar7[2] = param_3;
  puVar7[3] = param_4;
  puVar7[4] = unaff_r4;
  puVar7[5] = unaff_r5;
  puVar7[6] = unaff_r6;
  puVar7[7] = unaff_r7;
  puVar7[8] = unaff_r8;
  puVar7[9] = unaff_r9;
  puVar7[10] = unaff_r10;
  puVar7[0xb] = unaff_r11;
  puVar7[0xc] = in_r12;
  puVar7[0xd] = register0x00000054;
  puVar7[0xe] = unaff_lr;
  isThreadModePrivileged();
  cVar2 = isUsingMainStack();
  if (cVar2 == '\x01') {
    puVar5 = (undefined1 *)getProcessStackPointer();
    puVar3 = (undefined1 *)register0x00000054;
  }
  else {
    puVar3 = (undefined1 *)getMainStackPointer();
    puVar5 = (undefined1 *)register0x00000054;
  }
  puVar7[0xf] = puVar3;
  puVar7[0x10] = puVar5;
  *(undefined1 *)(DAT_04109458 + (uint)((*(uint *)(DAT_04109454 + 0x4c) & 3) != 0)) = 1;
  puVar7 = DAT_0410945c;
  iVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar6 = isIRQinterruptsEnabled();
  }
  if (-1 < iVar6 << 0x1f) {
    disableIRQinterrupts();
    *DAT_0410945c = 0x410935c;
    puVar7[1] = unaff_lr;
  }
  FUN_04108b54(0);
  puVar4 = auStack_68;
  puVar7 = DAT_04109460;
  do {
    puVar7 = puVar7 + 1;
    *puVar4 = *puVar7;
    puVar4 = puVar4 + 1;
  } while (puVar7 != DAT_04109460 + 0xf);
  isThreadModePrivileged();
  isUsingMainStack();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: FUN_041097f4 at 041097f4
// ===========================================================

undefined1 FUN_041097f4(uint param_1,int param_2,uint param_3,int param_4,undefined1 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  short sVar6;
  undefined1 *puVar7;
  uint uVar8;
  int iVar9;
  undefined1 uVar10;
  int iVar11;
  undefined1 *puVar12;
  bool bVar13;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_04109e2c);
  }
  if ((param_3 != 0) && (DAT_04109b80[param_1 * 0x3c] == '\0')) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_04109b94);
  }
  if (param_2 == 0) {
    return 0x13;
  }
  if (param_5 == (undefined1 *)0x0 && (*(uint *)(param_2 + 0xc) & 1) == 0) {
    return 0x14;
  }
  FUN_0410ef70(&local_38,param_2,0x10);
  FUN_0410ded4(param_1);
  puVar7 = DAT_04109b80;
  uVar8 = param_1;
  if (param_3 == 0) {
    FUN_0410e338(param_1);
    FUN_0410e09c(param_1,0);
    FUN_0410e0d8(param_1,8);
    FUN_0410e0bc(param_1,8);
    puVar7 = DAT_04109e28;
    if (param_1 == 0) {
LAB_041099d6:
      puVar7 = DAT_04109b80;
      *DAT_04109b80 = 0;
      *(undefined4 *)(puVar7 + 0x34) = 0;
      puVar7[0x38] = 0x12;
      uVar8 = 0;
    }
    else {
      DAT_04109e28[param_1 * 0x3c] = 0;
      puVar7[param_1 * 0x3c + 0x38] = 0x12;
    }
    iVar2 = DAT_04109ba0;
    *(undefined1 *)(DAT_04109ba0 + param_1) = 0;
    if (param_1 == 0) {
      bVar13 = (int)(local_2c << 0x1c) < 0;
      if (bVar13) {
        local_2c = local_2c & 0xffffffef;
        FUN_04102740(0,1,0);
      }
      else {
        FUN_04102740(0,0,0,0);
      }
      param_3 = (uint)bVar13;
      FUN_0410e134(0);
      FUN_0410e26c(0);
      FUN_04108488(7);
      FUN_0410df94(0,8);
      FUN_041030dc(0,8);
      if (param_3 == 0) {
        bVar13 = true;
        FUN_04102740(0,1,0);
        FUN_0410277c(0);
        FUN_04102dcc(0,DAT_04109e20 + -3,DAT_04109e20,3);
        FUN_04102ea8(0,DAT_04109e24 + -0x12,DAT_04109e24,0x12);
        puVar12 = DAT_04109e30;
        FUN_04102740(0,0,0,0);
        iVar9 = 0;
        goto LAB_04109ae6;
      }
      iVar9 = 0;
      FUN_0410277c(0);
      bVar13 = true;
      FUN_04102dcc(0,DAT_04109b98 + -3,DAT_04109b98,3);
      iVar11 = DAT_04109b9c + -0x18;
      FUN_04102ea8(0,DAT_04109b9c + -0x12,DAT_04109b9c,0x12);
      iVar11 = FUN_04103240(0,iVar11,3);
      if (iVar11 != 0) goto LAB_04109af4;
LAB_04109a70:
      uVar10 = 3;
      iVar9 = uVar8 << 4;
      iVar2 = 3;
      FUN_0410de70(param_1);
    }
    else {
      FUN_04102740(param_1,0,0,0);
      FUN_0410e134(param_1,0);
      FUN_0410e26c(param_1);
      if (param_1 == 1) {
        FUN_04108760(7);
      }
      else {
        FUN_041085e4(7);
      }
      param_3 = 0;
      iVar9 = param_1 * 0x3c;
      FUN_0410df94(param_1,8);
      FUN_041030dc(param_1,8);
      puVar12 = puVar7 + iVar9 + 2;
      FUN_0410277c(param_1);
      bVar13 = false;
      FUN_04102d94(param_1,puVar12,3);
      FUN_04102e60(param_1,puVar7 + iVar9 + 8,0x12);
LAB_04109ae6:
      iVar11 = FUN_04103240(param_1,puVar12,3);
      if (iVar11 == 0) goto LAB_04109a70;
LAB_04109af4:
      FUN_04102854(param_1,puVar7 + iVar9 + 0x2c);
      uVar3 = FUN_04102710(param_1);
      if (-1 < (int)(uVar3 << 0x1f)) {
LAB_04109c50:
        if (bVar13) {
          uVar3 = 0x2000000;
        }
        else {
          uVar3 = 0x1000000;
        }
        if (uVar3 < *(uint *)(puVar7 + param_1 * 0x3c + 0x2c)) {
          uVar3 = 0;
          FUN_04102ef4(param_1);
        }
        else {
          uVar3 = 0;
        }
        goto LAB_0410986a;
      }
      uVar5 = uVar3 & 6;
      if (uVar5 == 0) {
        iVar9 = 0x1000;
LAB_04109ccc:
        if (param_1 == 1) {
          iVar11 = 0x28000000;
        }
        else if (param_1 == 2) {
          iVar11 = 0x34000000;
        }
        else {
          iVar11 = 0x30000000;
        }
        *(int *)(DAT_04109e1c + param_1 * 4) = iVar11 + iVar9;
        uVar5 = uVar3 & 0x18;
        if (uVar5 == 0) {
          sVar4 = 0x400;
          *(undefined2 *)(DAT_04109e0c + param_1 * 2) = 0x400;
LAB_04109cf6:
          if ((int)(uVar3 << 0x1a) < 0) {
LAB_04109bde:
            *(undefined2 *)(DAT_04109e10 + param_1 * 2) = 0x100;
            goto LAB_04109be8;
          }
LAB_04109cfc:
          *(undefined2 *)(DAT_04109e10 + param_1 * 2) = 0x1000;
        }
        else {
          if (uVar5 == 8) {
            sVar4 = 0x200;
            *(undefined2 *)(DAT_04109e0c + param_1 * 2) = 0x200;
            goto LAB_04109cf6;
          }
          if (uVar5 != 0x10) {
            if (uVar5 != 0x18) goto LAB_04109be8;
            sVar4 = 0x1000;
            *(undefined2 *)(DAT_04109e0c + param_1 * 2) = 0x1000;
            if (-1 < (int)(uVar3 << 0x1a)) goto LAB_04109cfc;
            goto LAB_04109bde;
          }
          sVar4 = 0x100;
          *(undefined2 *)(DAT_04109e0c + param_1 * 2) = 0x100;
          if (-1 < (int)(uVar3 << 0x1a)) goto LAB_04109cfc;
          *(undefined2 *)(DAT_04109e10 + param_1 * 2) = 0x100;
        }
        uVar5 = uVar3 & 0xc0;
        if (uVar5 == 0) {
          sVar6 = 3;
        }
        else if (uVar5 == 0x40) {
          sVar6 = 4;
        }
        else if (uVar5 == 0x80) {
          sVar6 = 2;
        }
        else {
          if (uVar5 != 0xc0) goto LAB_04109be8;
          sVar6 = 1;
        }
        if ((uVar3 & 0x300) == 0) {
          *(undefined2 *)(DAT_04109e14 + param_1 * 2) = 0x100;
        }
        else {
          if ((uVar3 & 0x3ff) >> 8 != 1) goto LAB_04109be8;
          *(undefined2 *)(DAT_04109e14 + param_1 * 2) = 0x400;
        }
        *(short *)(DAT_04109e18 + param_1 * 2) = sVar6 * sVar4;
        *(undefined1 *)(iVar2 + param_1) = 1;
        goto LAB_04109c50;
      }
      if (uVar5 == 2) {
        iVar9 = 0;
        goto LAB_04109ccc;
      }
      if (uVar5 == 4) {
        iVar9 = 0x2000;
        goto LAB_04109ccc;
      }
LAB_04109be8:
      uVar10 = 8;
      iVar9 = uVar8 << 4;
      iVar2 = 8;
      FUN_0410de70(param_1);
    }
LAB_04109bf8:
    if (param_1 == 1) {
      FUN_04108760(7);
    }
    else if (param_1 == 2) {
      FUN_041085e4();
    }
    else {
      FUN_04108488();
    }
    FUN_0410df94(param_1,8);
    FUN_041030dc(param_1,8);
  }
  else {
    uVar3 = param_3;
    if (param_1 == 0) {
      if (((int)(local_2c << 0x1c) < 0) && (-1 < *(int *)(DAT_04109b80 + 0x34) << 0x1c))
      goto LAB_041099d6;
      if (param_4 != 1) {
        local_2c = local_2c & 0xfffffffc;
      }
      *DAT_04109b80 = 0;
      *(undefined4 *)(puVar7 + 0x34) = 0;
      puVar7[0x38] = 0x12;
      if ((local_2c & 8) == 0) {
        FUN_04102740(0,0,0,0);
        uVar8 = 0;
        param_3 = 0;
        goto LAB_0410986a;
      }
      uVar5 = 0;
      local_2c = local_2c & 0xffffffef;
      uVar8 = 0;
      FUN_04102740(0,1);
      if (DAT_04109b84 < local_38) goto LAB_041098ea;
LAB_04109872:
      if (local_38 <= DAT_04109b88) {
        if (DAT_04109b8c < local_38) {
          uVar1 = 0xd;
        }
        else if (DAT_04109b90 < local_38) {
          uVar1 = 0xb;
        }
        else {
          uVar1 = 7;
        }
        goto LAB_041098ec;
      }
      uVar1 = 0xf;
      if (param_1 == 1) goto LAB_04109b30;
LAB_041098f2:
      if (param_1 == 2) {
        FUN_041085e4();
      }
      else {
        FUN_04108488();
      }
      iVar2 = FUN_04103124(param_1,&local_38);
      uVar8 = uVar5;
    }
    else {
      if (param_4 != 1) {
        local_2c = local_2c & 0xfffffffc;
      }
      DAT_04109b80[param_1 * 0x3c] = 0;
      puVar7[param_1 * 0x3c + 0x38] = 0x12;
      param_3 = 0;
      FUN_04102740(param_1,0,0);
LAB_0410986a:
      uVar5 = uVar8;
      if (local_38 <= DAT_04109b84) goto LAB_04109872;
LAB_041098ea:
      uVar1 = 0x13;
      uVar5 = uVar8;
LAB_041098ec:
      if (param_1 != 1) goto LAB_041098f2;
LAB_04109b30:
      FUN_04108760(uVar1);
      iVar2 = FUN_04103124(param_1,&local_38);
      uVar8 = uVar5;
    }
    if (iVar2 != 0) {
      uVar10 = 4;
      FUN_0410de70(param_1);
      iVar9 = uVar8 << 4;
      iVar2 = 4;
      goto LAB_04109bf8;
    }
    if ((int)(local_2c << 0x1f) < 0) {
      if (uVar3 == 0) {
        iVar2 = FUN_04102f80(param_1,0);
        if (iVar2 == 0) goto LAB_0410992a;
      }
      else {
        FUN_04102aa8(param_1);
        iVar2 = FUN_04102f80(param_1,0);
        if (iVar2 == 0) {
          FUN_04102b1c(param_1);
          goto LAB_04109932;
        }
      }
      uVar10 = 5;
      iVar9 = uVar8 << 4;
      iVar2 = 5;
      FUN_0410de70(param_1);
      goto LAB_04109bf8;
    }
    FUN_04102f3c(param_1,*param_5);
    if (uVar3 == 0) {
LAB_0410992a:
      FUN_04103474(param_1,0);
    }
LAB_04109932:
    if (DAT_04109b88 < local_34) {
      local_30 = local_30 | 0x2000;
    }
    iVar2 = FUN_041028ac(param_1,local_30);
    if (iVar2 != 0) {
      uVar10 = 9;
      iVar9 = uVar8 << 4;
      iVar2 = 9;
      FUN_0410de70(param_1);
      goto LAB_04109bf8;
    }
    iVar9 = uVar8 * 0x10;
    FUN_04102890(param_1,puVar7 + uVar8 * 0x3c + 0x30);
    if (((int)(local_2c << 0x1e) < 0) && (iVar2 = FUN_04102f80(param_1,1), iVar2 != 0)) {
      uVar10 = 6;
      iVar2 = 6;
      FUN_0410de70(param_1);
      goto LAB_04109bf8;
    }
    puVar7[uVar8 * 0x3c] = 1;
    if (param_1 != 0) {
      uVar10 = 0;
      FUN_0410de70(param_1);
      goto LAB_0410999c;
    }
    *(uint *)(puVar7 + 0x34) = local_2c;
    FUN_0410de70(0);
    iVar2 = 0;
    uVar10 = 0;
  }
  if ((param_1 == 0) && ((int)(param_3 << 0x1f) < 0)) {
    FUN_04102740(0,iVar2 == 0,0);
  }
LAB_0410999c:
  puVar7[(iVar9 - uVar8) * 4 + 0x38] = uVar10;
  return uVar10;
}



// ===========================================================
// Function: FUN_04109e34 at 04109e34
// ===========================================================

undefined4
FUN_04109e34(uint param_1,undefined4 *param_2,int *param_3,int *param_4,undefined4 *param_5)

{
  int iVar1;
  
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_04109e98);
  }
  if (param_1 == 0) {
    if ((*(uint *)(DAT_04109e94 + 0x34) & 8) == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = 2;
    }
  }
  else {
    iVar1 = 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(DAT_04109e94 + param_1 * 0x3c + 0x2c);
  }
  if (param_3 != (int *)0x0) {
    *param_3 = iVar1 << 0xf;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = iVar1 << 0xc;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = *(undefined4 *)(DAT_04109e94 + param_1 * 0x3c + 0x30);
  }
  return 0;
}



// ===========================================================
// Function: FUN_04109e9c at 04109e9c
// ===========================================================

undefined4 FUN_04109e9c(uint param_1,uint param_2,int *param_3,int *param_4)

{
  uint *puVar1;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar2;
  
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_04109f40);
  }
  if (*(char *)(DAT_04109f34 + param_1 * 0x3c) != '\0') {
    iVar4 = *(int *)(param_1 * 0x3c + DAT_04109f34 + 0x2c);
    if (iVar4 != 0) {
      if (param_1 == 0) {
        if ((*(uint *)(DAT_04109f34 + 0x34) & 8) == 0) {
          uVar5 = 0x1000;
          uVar6 = 0x8000;
        }
        else {
          uVar5 = 0x2000;
          uVar6 = 0x10000;
        }
      }
      else {
        uVar5 = 0x1000;
        uVar6 = 0x8000;
      }
      puVar1 = (uint *)(DAT_04109f38 + param_1 * 0x10);
      do {
        puVar2 = puVar1 + 1;
        uVar3 = *puVar1;
        if ((uVar3 <= param_2) && (param_2 < iVar4 + uVar3)) {
          if (param_3 != (int *)0x0) {
            *param_3 = uVar6 * ((param_2 - uVar3) / uVar6) + uVar3;
          }
          if (param_4 != (int *)0x0) {
            *param_4 = uVar5 * ((param_2 - uVar3) / uVar5) + uVar3;
            return 0;
          }
          return 0;
        }
        puVar1 = puVar2;
      } while ((uint *)(DAT_04109f38 + 0x10 + param_1 * 0x10) != puVar2);
    }
    return 0xb;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_04109f3c);
}



// ===========================================================
// Function: FUN_04109f44 at 04109f44
// ===========================================================

undefined4 FUN_04109f44(uint param_1,int param_2,uint param_3)

{
  if (param_1 < 3) {
    if (param_2 != 0) {
      if (2 < param_3) {
        param_3 = 3;
      }
      FUN_0410ef70(param_2,DAT_04109f70 + param_1 * 0x3c + 2,param_3);
    }
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_04109f74);
}



// ===========================================================
// Function: FUN_04109f78 at 04109f78
// ===========================================================

undefined4 FUN_04109f78(int param_1,int param_2,int param_3,uint param_4)

{
  if (param_1 != 0) {
    return 10;
  }
  if (2 < param_4) {
    param_4 = 3;
  }
  if (param_2 != 0) {
    FUN_0410ef70(param_2,DAT_04109fb4,param_4);
  }
  if (param_3 != 0) {
    FUN_0410ef70(param_3,DAT_04109fb8,param_4);
    return 0;
  }
  return 0;
}



// ===========================================================
// Function: FUN_04109fbc at 04109fbc
// ===========================================================

undefined4 FUN_04109fbc(uint param_1,int param_2,uint param_3)

{
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_04109ffc);
  }
  if (*(char *)(DAT_04109ff8 + param_1 * 0x3c) != '\0') {
    if (param_2 != 0) {
      if (0x11 < param_3) {
        param_3 = 0x12;
      }
      FUN_0410ef70(param_2,DAT_04109ff8 + param_1 * 0x3c + 8,param_3);
      return 0;
    }
    return 0x15;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410a000);
}



// ===========================================================
// Function: FUN_0410a004 at 0410a004
// ===========================================================

undefined4 FUN_0410a004(int param_1,int param_2,int param_3,uint param_4)

{
  if (param_1 != 0) {
    return 10;
  }
  if (*DAT_0410a04c != '\0') {
    if (0x11 < param_4) {
      param_4 = 0x12;
    }
    if (param_2 != 0) {
      FUN_0410ef70(param_2,DAT_0410a04c + 8,param_4);
    }
    if (param_3 != 0) {
      FUN_0410ef70(param_3,DAT_0410a050,param_4);
    }
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410a054);
}



// ===========================================================
// Function: FUN_0410a058 at 0410a058
// ===========================================================

undefined4 FUN_0410a058(int param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(char *)(DAT_0410a0b8 + param_1) == '\0') {
    return 10;
  }
  uVar1 = *param_2;
  uVar4 = (uint)*(ushort *)(DAT_0410a0bc + param_1 * 2);
  if (uVar4 <= uVar1) {
    return 0xb;
  }
  uVar2 = *param_3;
  if (uVar4 - uVar1 < uVar2) {
    return 0xc;
  }
  uVar5 = (uint)*(ushort *)(DAT_0410a0c0 + param_1 * 2);
  uVar4 = uVar5 - 1;
  uVar3 = uVar1 & uVar4;
  if (uVar3 != 0) {
    *param_2 = uVar1 - uVar3;
    uVar2 = *param_3 + uVar3;
    *param_3 = uVar2;
  }
  uVar4 = uVar4 & uVar2;
  if (uVar4 != 0) {
    *param_3 = (uVar2 + uVar5) - uVar4;
    return 0;
  }
  return 0;
}



// ===========================================================
// Function: FUN_0410a0c4 at 0410a0c4
// ===========================================================

uint FUN_0410a0c4(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_20;
  uint uStack_1c;
  
  local_20 = param_3;
  uStack_1c = param_2;
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410a160);
  }
  if (*(char *)(DAT_0410a158 + param_1 * 0x3c) == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410a164);
  }
  uVar1 = FUN_0410a058(param_1,&uStack_1c,&local_20);
  if (uVar1 == 0) {
    if (local_20 != 0) {
      uVar7 = (uint)*(ushort *)(DAT_0410a15c + param_1 * 2);
      iVar2 = 1;
      uVar3 = 0;
      uVar1 = 0;
      uVar4 = uVar7;
      uVar5 = uStack_1c;
      uVar6 = local_20;
      do {
        if ((uVar3 <= uVar5) && (uVar5 < uVar4)) {
          uVar1 = uVar1 | 1 << (iVar2 - 1U & 0xff);
          if (uVar6 <= uVar4 - uVar5) goto LAB_0410a128;
          uVar6 = (uVar6 + uVar5) - uVar4;
          uVar5 = uVar4;
        }
        uVar3 = uVar3 + uVar7;
        uVar4 = uVar4 + uVar7;
        iVar2 = iVar2 + 1;
      } while( true );
    }
    uVar1 = 0;
LAB_0410a128:
    FUN_04102aa8(param_1);
    uVar1 = FUN_041034a0(param_1,uVar1);
    FUN_04102b1c(param_1);
    uVar1 = uVar1 & 0xff;
  }
  return uVar1;
}



// ===========================================================
// Function: FUN_0410a168 at 0410a168
// ===========================================================

uint FUN_0410a168(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  uint local_30;
  uint local_2c [2];
  
  iVar1 = DAT_0410a2ac;
  local_30 = param_3;
  local_2c[0] = param_2;
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410a2a8);
  }
  iVar4 = DAT_0410a2ac + param_1 * 0x3c;
  if (*(char *)(DAT_0410a2ac + param_1 * 0x3c) == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410a2a4);
  }
  uVar2 = FUN_0410a058(param_1,local_2c,&local_30);
  uVar7 = local_2c[0];
  uVar3 = local_30;
  if (uVar2 != 0) {
    return uVar2;
  }
  iVar6 = *(int *)(DAT_0410a298 + param_1 * 4);
  FUN_04102aa8(param_1);
  if (param_1 == 0) {
    uVar2 = 0x2000000;
  }
  else {
    uVar2 = 0x1000000;
  }
  if (uVar2 < *(uint *)(iVar4 + 0x2c)) {
    FUN_04102f18(param_1);
    if (uVar3 != 0) goto LAB_0410a1ce;
  }
  else {
    if (uVar3 == 0) goto LAB_0410a232;
LAB_0410a1ce:
    uVar10 = (uint)*(ushort *)(DAT_0410a29c + param_1 * 2);
    iVar4 = DAT_0410a2a0;
    uVar5 = 0;
    uVar8 = uVar3;
    do {
      while (uVar7 < uVar5) {
        uVar5 = uVar5 + uVar10;
        uVar3 = 0;
        bVar11 = false;
        if (uVar8 != 0) {
          bVar11 = true;
        }
LAB_0410a1e8:
        iVar6 = iVar6 + (uint)*(ushort *)(iVar4 + param_1 * 2);
        if (!bVar11) goto LAB_0410a216;
      }
      uVar9 = uVar10 + uVar5;
      if (uVar7 < uVar9) {
        uVar3 = FUN_04103504(param_1,(uVar7 + iVar6) - uVar5);
        bVar11 = uVar8 <= uVar9 - uVar7;
        if (bVar11) {
          uVar8 = 0;
        }
        else {
          uVar8 = (uVar8 + uVar7) - uVar9;
        }
        bVar11 = !bVar11 && uVar3 == 0;
        uVar10 = (uint)*(ushort *)(DAT_0410a29c + param_1 * 2);
        uVar5 = uVar5 + uVar10;
        iVar4 = DAT_0410a2a0;
        uVar7 = uVar9;
        goto LAB_0410a1e8;
      }
      uVar3 = 0;
      iVar6 = iVar6 + (uint)*(ushort *)(iVar4 + param_1 * 2);
      uVar5 = uVar9;
    } while (uVar8 != 0);
  }
LAB_0410a216:
  if (uVar2 < *(uint *)(iVar1 + param_1 * 0x3c + 0x2c)) {
    FUN_04102ef4(param_1);
  }
LAB_0410a232:
  FUN_04102b1c(param_1);
  return uVar3;
}



// ===========================================================
// Function: FUN_0410a2b0 at 0410a2b0
// ===========================================================

uint FUN_0410a2b0(uint param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410a470);
  }
  iVar5 = DAT_0410a450 + param_1 * 0x3c;
  if (*(char *)(DAT_0410a450 + param_1 * 0x3c) == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410a46c);
  }
  if (*(char *)(DAT_0410a454 + param_1) == '\0') {
    return 10;
  }
  uVar3 = (uint)*(ushort *)(DAT_0410a458 + param_1 * 2);
  if (uVar3 <= param_2) {
    return 0xb;
  }
  if (uVar3 - param_2 < param_4) {
    return 0xc;
  }
  iVar8 = *(int *)(DAT_0410a45c + param_1 * 4);
  FUN_04102aa8();
  if (param_1 == 0) {
    uVar3 = 0x2000000;
  }
  else {
    uVar3 = 0x1000000;
  }
  if (uVar3 < *(uint *)(iVar5 + 0x2c)) {
    FUN_04102f18(param_1);
    if (param_4 != 0) goto LAB_0410a320;
  }
  else {
    if (param_4 == 0) goto LAB_0410a382;
LAB_0410a320:
    uVar1 = (uint)*(ushort *)(DAT_0410a460 + param_1 * 2);
    uVar7 = 0;
    uVar4 = param_4;
    do {
      while (uVar7 <= param_2) {
        uVar6 = uVar1 + uVar7;
        if (param_2 < uVar6) {
          if (uVar6 < uVar4 + param_2) {
            uVar1 = uVar6 - param_2;
            uVar9 = uVar4 + (param_2 - uVar6);
            bVar10 = uVar9 != 0;
          }
          else {
            param_4 = 0;
            if (uVar4 == 0) goto LAB_0410a36a;
            uVar9 = 0;
            bVar10 = false;
            uVar1 = uVar4;
          }
          do {
            uVar2 = param_2 - uVar7;
            uVar4 = (uint)*(ushort *)(DAT_0410a468 + param_1 * 2);
            uVar6 = uVar4 - (uVar4 - 1 & uVar2);
            if (uVar1 <= uVar4) {
              uVar4 = uVar1;
            }
            if (uVar4 <= uVar6) {
              uVar6 = uVar4;
            }
            param_2 = param_2 + uVar6;
            param_4 = FUN_04103554(param_1,uVar2 + iVar8,param_3,uVar6);
            param_3 = param_3 + uVar6;
          } while ((uVar1 - uVar6 != 0) && (uVar1 = uVar1 - uVar6, param_4 == 0));
          bVar10 = (bool)(param_4 == 0 & bVar10);
          uVar1 = (uint)*(ushort *)(DAT_0410a460 + param_1 * 2);
          uVar6 = uVar7 + uVar1;
        }
        else {
          param_4 = 0;
          bVar10 = false;
          uVar9 = uVar4;
          if (uVar4 != 0) {
            bVar10 = true;
          }
        }
        iVar8 = iVar8 + (uint)*(ushort *)(DAT_0410a464 + param_1 * 2);
        uVar7 = uVar6;
        uVar4 = uVar9;
        if (!bVar10) goto LAB_0410a36a;
      }
      param_4 = 0;
      iVar8 = iVar8 + (uint)*(ushort *)(DAT_0410a464 + param_1 * 2);
      uVar7 = uVar7 + uVar1;
    } while (uVar4 != 0);
  }
LAB_0410a36a:
  if (uVar3 < *(uint *)(DAT_0410a450 + param_1 * 0x3c + 0x2c)) {
    FUN_04102ef4(param_1);
  }
LAB_0410a382:
  FUN_04102b1c(param_1);
  return param_4;
}



// ===========================================================
// Function: FUN_0410a474 at 0410a474
// ===========================================================

undefined4 FUN_0410a474(uint param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 unaff_lr;
  undefined4 local_34;
  
  puVar8 = DAT_0410a618;
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410a620);
  }
  if (*(char *)(DAT_0410a608 + param_1 * 0x3c) == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410a61c);
  }
  if (*(char *)(DAT_0410a60c + param_1) == '\0') {
    return 10;
  }
  uVar5 = (uint)*(ushort *)(DAT_0410a610 + param_1 * 2);
  if (uVar5 <= param_2) {
    return 0xb;
  }
  if (uVar5 - param_2 < param_4) {
    return 0xc;
  }
  iVar10 = *(int *)(DAT_0410a614 + param_1 * 4);
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = isIRQinterruptsEnabled();
  }
  if ((uVar5 & 1) == 0) {
    disableIRQinterrupts();
    *DAT_0410a618 = 0x410a4d0;
    puVar8[1] = unaff_lr;
    FUN_04102aa8();
    local_34 = FUN_041035e8(param_1);
    FUN_0410e258(param_1,8);
    FUN_0410ded4(param_1);
    if (param_4 == 0) {
      FUN_0410ded4(param_1);
      FUN_0410e258(param_1,0);
      FUN_04103640(param_1,local_34);
      FUN_04102b1c(param_1);
      goto LAB_0410a576;
    }
  }
  else {
    FUN_04102aa8();
    local_34 = FUN_041035e8(param_1);
    FUN_0410e258(param_1,8);
    FUN_0410ded4(param_1);
    if (param_4 == 0) {
      FUN_0410ded4(param_1);
      FUN_0410e258(param_1,0);
      FUN_04103640(param_1,local_34);
      FUN_04102b1c(param_1);
      return 0;
    }
  }
  iVar3 = DAT_0410a628;
  iVar2 = DAT_0410a624;
  uVar7 = 0;
  uVar4 = (uint)*(ushort *)(DAT_0410a624 + param_1 * 2);
  do {
    for (; (param_2 < uVar7 || (uVar6 = uVar4 + uVar7, uVar6 <= param_2)); uVar7 = uVar7 + uVar4) {
      iVar10 = iVar10 + (uint)*(ushort *)(iVar3 + param_1 * 2);
    }
    uVar11 = param_4 + param_2;
    if (uVar6 < uVar11) {
      uVar9 = param_4 + (param_2 - uVar6);
      uVar11 = uVar6;
      param_4 = uVar6 - param_2;
    }
    else {
      uVar9 = 0;
    }
    FUN_0410ef70(param_3,(param_2 + iVar10) - uVar7,param_4);
    uVar4 = (uint)*(ushort *)(iVar2 + param_1 * 2);
    uVar7 = uVar7 + uVar4;
    iVar10 = iVar10 + (uint)*(ushort *)(iVar3 + param_1 * 2);
    param_3 = param_3 + param_4;
    param_4 = uVar9;
    param_2 = uVar11;
  } while (uVar9 != 0);
  FUN_0410ded4(param_1);
  FUN_0410e258(param_1,0);
  FUN_04103640(param_1,local_34);
  FUN_04102b1c(param_1);
  puVar8 = DAT_0410a618;
  if ((uVar5 & 1) != 0) {
    return 0;
  }
LAB_0410a576:
  *puVar8 = 0xffffffff;
  enableIRQinterrupts();
  return 0;
}



// ===========================================================
// Function: FUN_0410a62c at 0410a62c
// ===========================================================

void FUN_0410a62c(void)

{
  FUN_041097f4();
  return;
}



// ===========================================================
// Function: FUN_0410a640 at 0410a640
// ===========================================================

void FUN_0410a640(void)

{
  return;
}



// ===========================================================
// Function: FUN_0410a644 at 0410a644
// ===========================================================

void FUN_0410a644(void)

{
  return;
}



// ===========================================================
// Function: FUN_0410a648 at 0410a648
// ===========================================================

/* WARNING: Removing unreachable block (ram,0x0410970c) */

int FUN_0410a648(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410a67c);
  }
  if (*(char *)(DAT_0410a678 + param_1 * 0x3c) == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410a680);
  }
  uVar3 = *(uint *)(DAT_0410a678 + param_1 * 0x3c + 0x2c);
  uVar8 = *(uint *)(DAT_041097f0 + param_1 * 0x3c + 0x2c);
  if (param_1 == 0) {
    if ((*(uint *)(DAT_041097f0 + 0x34) & 8) == 0) {
      uVar6 = 0x1000;
      uVar7 = 0x8000;
    }
    else {
      uVar6 = 0x2000;
      uVar7 = 0x10000;
    }
  }
  else {
    uVar6 = 0x1000;
    uVar7 = 0x8000;
  }
  if (uVar8 < uVar3) {
    return 0xc;
  }
  uVar5 = 0;
  uVar4 = uVar6 - 1 & uVar3;
  if (uVar4 != 0) {
    uVar3 = (uVar3 + uVar6) - uVar4;
  }
  uVar1 = FUN_04102a50(param_1,0);
  if (uVar3 < uVar8) {
    if (uVar3 != 0) {
      do {
        if (uVar3 < uVar7) {
          iVar2 = FUN_04103294(param_1,uVar5,1,0);
          if (uVar3 <= uVar6) goto LAB_041097b0;
LAB_04109746:
          uVar3 = uVar3 - uVar6;
          uVar8 = uVar6;
          if (iVar2 != 0 || uVar3 == 0) goto LAB_041097b0;
        }
        else {
          if ((uVar7 - 1 & uVar5) != 0) {
            iVar2 = FUN_04103294(param_1,uVar5,1,0);
            goto LAB_04109746;
          }
          iVar2 = FUN_04103294(param_1,uVar5,2,0);
          uVar3 = uVar3 - uVar7;
          uVar8 = uVar7;
          if (iVar2 != 0 || uVar3 == 0) goto LAB_041097b0;
        }
        uVar5 = uVar5 + uVar8;
      } while( true );
    }
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_04103294(param_1,0,4,0);
  }
LAB_041097b0:
  FUN_04102ab0(param_1,0,uVar1);
  return iVar2;
}



// ===========================================================
// Function: FUN_0410a684 at 0410a684
// ===========================================================

int FUN_0410a684(uint param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410a6b0);
  }
  if (*(char *)(DAT_0410a6ac + param_1 * 0x3c) == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410a6b4);
  }
  uVar6 = *(uint *)(DAT_041097f0 + param_1 * 0x3c + 0x2c);
  if (param_1 == 0) {
    if ((*(uint *)(DAT_041097f0 + 0x34) & 8) == 0) {
      uVar4 = 0x1000;
      uVar5 = 0x8000;
    }
    else {
      uVar4 = 0x2000;
      uVar5 = 0x10000;
    }
  }
  else {
    uVar4 = 0x1000;
    uVar5 = 0x8000;
  }
  param_2 = uVar6 - 1 & param_2;
  if (uVar6 - param_2 < param_3) {
    return 0xc;
  }
  uVar3 = uVar4 - 1 & param_2;
  if (uVar3 != 0) {
    param_2 = param_2 - uVar3;
    param_3 = param_3 + uVar3;
  }
  uVar3 = uVar4 - 1 & param_3;
  if (uVar3 != 0) {
    param_3 = (param_3 + uVar4) - uVar3;
  }
  uVar1 = FUN_04102a50(param_1,0);
  if ((param_2 == 0) && (uVar6 <= param_3)) {
    iVar2 = FUN_04103294(param_1,0,4,0);
  }
  else {
    if (param_3 != 0) {
      do {
        if (param_3 < uVar5) {
          iVar2 = FUN_04103294(param_1,param_2,1,0);
          if (param_3 <= uVar4) goto LAB_041097b0;
LAB_04109746:
          param_3 = param_3 - uVar4;
          uVar6 = uVar4;
          if (iVar2 != 0 || param_3 == 0) goto LAB_041097b0;
        }
        else {
          if ((uVar5 - 1 & param_2) != 0) {
            iVar2 = FUN_04103294(param_1,param_2,1,0);
            goto LAB_04109746;
          }
          iVar2 = FUN_04103294(param_1,param_2,2,0);
          param_3 = param_3 - uVar5;
          uVar6 = uVar5;
          if (iVar2 != 0 || param_3 == 0) goto LAB_041097b0;
        }
        param_2 = param_2 + uVar6;
      } while( true );
    }
    iVar2 = 0;
  }
LAB_041097b0:
  FUN_04102ab0(param_1,0,uVar1);
  return iVar2;
}



// ===========================================================
// Function: FUN_0410a6b8 at 0410a6b8
// ===========================================================

uint FUN_0410a6b8(uint param_1,uint param_2,int param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  iVar1 = DAT_0410a7ec;
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410a7e4);
  }
  iVar5 = DAT_0410a7ec + param_1 * 0x3c;
  if (*(char *)(DAT_0410a7ec + param_1 * 0x3c) == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410a7e8);
  }
  if (param_3 == 0) {
    return 0x15;
  }
  iVar4 = *(int *)(iVar5 + 0x2c);
  param_2 = iVar4 - 1U & param_2;
  if (iVar4 - param_2 < param_4) {
    return 0xc;
  }
  uVar8 = *(uint *)(iVar5 + 0x30);
  if (param_1 == 0) {
    if (*(int *)(DAT_0410a7ec + 0x34) << 0x1c < 0) {
      if ((int)(param_2 << 0x1f) < 0) {
        return 0xb;
      }
      if ((int)(param_4 << 0x1f) < 0) {
        return 0xc;
      }
    }
    uVar2 = FUN_04102a50(0,param_5);
    if (*(int *)(iVar1 + 0x34) << 0x1c < 0) {
      FUN_0410e280(0);
    }
    if (param_4 != 0) goto LAB_0410a722;
  }
  else {
    uVar2 = FUN_04102a50(param_1,param_5);
    if (param_4 == 0) goto LAB_0410a768;
LAB_0410a722:
    uVar7 = param_4;
    do {
      uVar6 = uVar8 - (uVar8 - 1 & param_2);
      uVar3 = uVar8;
      if (uVar7 <= uVar8) {
        uVar3 = uVar7;
      }
      if (uVar3 <= uVar6) {
        uVar6 = uVar3;
      }
      param_4 = FUN_041033c0(param_1,param_2,param_3,uVar6,param_5);
      uVar7 = uVar7 - uVar6;
    } while ((uVar7 != 0) && (param_2 = param_2 + uVar6, param_3 = param_3 + uVar6, param_4 == 0));
    if (param_1 != 0) goto LAB_0410a768;
  }
  if (*(int *)(iVar1 + 0x34) << 0x1c < 0) {
    FUN_0410e280(0,1);
  }
LAB_0410a768:
  FUN_04102ab0(param_1,param_5,uVar2);
  return param_4;
}



// ===========================================================
// Function: FUN_0410a7f0 at 0410a7f0
// ===========================================================

void FUN_0410a7f0(void)

{
  FUN_0410a6b8();
  return;
}



// ===========================================================
// Function: FUN_0410a800 at 0410a800
// ===========================================================

undefined4 FUN_0410a800(void)

{
  return DAT_0410a804;
}



// ===========================================================
// Function: FUN_0410a808 at 0410a808
// ===========================================================

undefined4 FUN_0410a808(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 auStack_20 [12];
  uint local_14;
  
  if (param_1 != 0) {
    return 10;
  }
  if (param_2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 8;
  }
  if ((*(uint *)(DAT_0410a870 + 0x34) & 0x18) != uVar3) {
    FUN_0410ef70(auStack_20,DAT_0410a874,0x10);
    local_14 = local_14 & 0xffffffe1 | uVar3;
    FUN_0410ad60(4);
    iVar1 = FUN_0410def0(0);
    if (iVar1 != 0) {
      FUN_0410ad60(4);
    }
    uVar2 = FUN_041097f4(0,auStack_20,0,1,0);
    return uVar2;
  }
  return 0;
}



// ===========================================================
// Function: FUN_0410a878 at 0410a878
// ===========================================================

undefined4 FUN_0410a878(int param_1,uint *param_2,undefined4 *param_3)

{
  uint uVar1;
  
  if (*(char *)(DAT_0410a8b4 + param_1 * 0x3c) == '\0') {
    return 0x12;
  }
  if (param_1 == 0) {
    uVar1 = (*(uint *)(DAT_0410a8b4 + 0x34) & 0xf) >> 3;
  }
  else {
    uVar1 = 0;
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar1;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    return 0;
  }
  return 0;
}



// ===========================================================
// Function: FUN_0410a8b8 at 0410a8b8
// ===========================================================

undefined4 FUN_0410a8b8(int param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(char *)(DAT_0410a968 + param_1 * 0x3c) == '\0') {
    return 0x12;
  }
  if (param_4 == 0) {
    return 0xc;
  }
  if (param_5 != 0) {
    if (param_1 == 0) {
      uVar4 = 0xffff;
    }
    else {
      uVar4 = 0x7fff;
    }
    if (3 < param_2) {
      return 0xd;
    }
    param_3 = param_3 & 0x3ffffff;
    iVar2 = param_3 + param_5;
    uVar3 = param_4 + 0xfffU & DAT_0410a96c;
    if ((int)param_5 < 1) {
      param_5 = -param_5;
      if (param_3 < param_5) {
        return 0xe;
      }
    }
    else if (*(uint *)(DAT_0410a968 + param_1 * 0x3c + 0x2c) < uVar3 + iVar2) {
      return 0xb;
    }
    if ((uVar4 & param_5) == 0) {
      FUN_0410ded4(param_1);
      iVar2 = FUN_0410e150(param_1,param_2,param_3,uVar3,iVar2);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 10;
      }
      return uVar1;
    }
  }
  return 0xe;
}



// ===========================================================
// Function: FUN_0410a970 at 0410a970
// ===========================================================

undefined4 FUN_0410a970(undefined4 param_1,undefined4 param_2)

{
  FUN_0410ded4();
  FUN_0410e1d0(param_1,param_2);
  FUN_0410ded4(param_1);
  FUN_0410df04(param_1);
  return 0;
}



// ===========================================================
// Function: FUN_0410a998 at 0410a998
// ===========================================================

undefined4 FUN_0410a998(undefined4 param_1,undefined4 param_2)

{
  FUN_0410ded4();
  FUN_0410e1f0(param_1,param_2);
  FUN_0410ded4(param_1);
  FUN_0410df04(param_1);
  return 0;
}



// ===========================================================
// Function: FUN_0410a9c0 at 0410a9c0
// ===========================================================

uint FUN_0410a9c0(uint param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  
  uVar3 = 0x10000000;
  uVar6 = 0;
  puVar4 = DAT_0410aa24;
  iVar5 = DAT_0410aa20;
  do {
    iVar1 = *(int *)(iVar5 + 0x2c);
    puVar2 = puVar4 + -3;
    if (iVar1 == 0) {
      iVar1 = 0x4000000;
    }
    while( true ) {
      if ((uVar3 <= param_1) && (param_1 < iVar1 + uVar3)) {
        return uVar6 & 0xff;
      }
      if (puVar2 == puVar4) break;
      uVar3 = *puVar2;
      puVar2 = puVar2 + 1;
    }
    uVar6 = uVar6 + 1;
    iVar5 = iVar5 + 0x3c;
    if (uVar6 == 3) {
      return 3;
    }
    uVar3 = *puVar4;
    puVar4 = puVar4 + 4;
  } while( true );
}



// ===========================================================
// Function: FUN_0410aa28 at 0410aa28
// ===========================================================

undefined1 FUN_0410aa28(void)

{
  return *DAT_0410aa30;
}



// ===========================================================
// Function: FUN_0410aa34 at 0410aa34
// ===========================================================

uint FUN_0410aa34(void)

{
  return *(uint *)(DAT_0410aa40 + 0x38) & 0xfffffff0;
}



// ===========================================================
// Function: FUN_0410aa44 at 0410aa44
// ===========================================================

void FUN_0410aa44(uint param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_lr;
  
  iVar3 = DAT_0410aa90;
  puVar2 = DAT_0410aa8c;
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_0410aa8c = 0x410aa58;
    puVar2[1] = unaff_lr;
    *(uint *)(iVar3 + 0x38) = (param_1 | *(uint *)(iVar3 + 0x38)) & 0xfffffff0;
    if (iVar4 == 0) {
      *puVar2 = 0xffffffff;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(iVar4);
    }
    return;
  }
  *(uint *)(DAT_0410aa90 + 0x38) = (param_1 | *(uint *)(DAT_0410aa90 + 0x38)) & 0xfffffff0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x40);
  }
  return;
}



// ===========================================================
// Function: FUN_0410aa94 at 0410aa94
// ===========================================================

void FUN_0410aa94(uint param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_lr;
  
  iVar3 = DAT_0410aae4;
  puVar2 = DAT_0410aae0;
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_0410aae0 = 0x410aaa8;
    puVar2[1] = unaff_lr;
    *(uint *)(iVar3 + 0x38) = *(uint *)(iVar3 + 0x38) & ~param_1 & 0xfffffff0;
    if (iVar4 == 0) {
      *puVar2 = 0xffffffff;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(iVar4);
    }
    return;
  }
  *(uint *)(DAT_0410aae4 + 0x38) = *(uint *)(DAT_0410aae4 + 0x38) & ~param_1 & 0xfffffff0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x40);
  }
  return;
}



// ===========================================================
// Function: FUN_0410aae8 at 0410aae8
// ===========================================================

void FUN_0410aae8(void)

{
  FUN_041075b4(0xd8);
  return;
}



// ===========================================================
// Function: FUN_0410ab00 at 0410ab00
// ===========================================================

undefined4 FUN_0410ab00(undefined4 param_1)

{
  FUN_041088b8();
  FUN_04108990(param_1);
  FUN_04108924(param_1);
  return 0;
}



// ===========================================================
// Function: FUN_0410ab18 at 0410ab18
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0410ab18(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_r4;
  undefined4 unaff_lr;
  
  thunk_FUN_0410777c();
  FUN_0410ad44();
  FUN_04108488(7);
  FUN_04108760(7);
  FUN_041085e4(7);
  FUN_04108320(7);
  if (param_1 == 0) {
    FUN_041080d0(7);
    iVar3 = FUN_04107b68();
  }
  else {
    iVar3 = FUN_04107b68();
  }
  if (iVar3 == 0) {
    FUN_0410e368();
    FUN_04101eac(param_1);
    FUN_0410774c();
    FUN_04107768();
    puVar2 = DAT_0410804c;
    DAT_0410804c[0x32] = 0x1200;
    puVar2[1] = 0x80;
    puVar2[0x28] = 0x11000;
    puVar2[0x33] = 0x100;
    _DAT_50000060 = 0x2000;
    FUN_0410ab00(1,0x2000,&DAT_50000000,*puVar2,unaff_r4,unaff_lr);
    puVar2 = DAT_04108050;
    iVar3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar3 = getBasePriority();
    }
    if (iVar3 == 0x40) {
      _DAT_40000070 = _DAT_40000070 & 0xffffcfff | 0x1000;
    }
    else {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(0x40);
      }
      *DAT_04108050 = 0x4107fe8;
      puVar2[1] = unaff_lr;
      _DAT_40000070 = _DAT_40000070 & 0xffffcfff | 0x1000;
      if (iVar3 == 0) {
        *puVar2 = 0xffffffff;
      }
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(iVar3);
    }
    FUN_04107c1c(1,0);
    puVar2 = DAT_0410804c;
    _DAT_50000060 = 0x20000;
    DAT_0410804c[7] = DAT_0410804c[7] & 0xffffe0ff | 0x200;
    puVar2[1] = 0x200;
    puVar2[0x55] = puVar2[0x55] | 0x20000;
    return;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ===========================================================
// Function: FUN_0410ad44 at 0410ad44
// ===========================================================

void FUN_0410ad44(void)

{
  FUN_041076d4();
  return;
}



// ===========================================================
// Function: FUN_0410ad54 at 0410ad54
// ===========================================================

undefined4 FUN_0410ad54(void)

{
  return *(undefined4 *)(DAT_0410ad5c + 0x50);
}



// ===========================================================
// Function: FUN_0410ad60 at 0410ad60
// ===========================================================

void FUN_0410ad60(uint param_1)

{
  do {
  } while ((uint)(*(int *)(DAT_0410ad70 + 0x50) - *(int *)(DAT_0410ad70 + 0x50)) < param_1);
  return;
}



// ===========================================================
// Function: FUN_0410ad74 at 0410ad74
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0410ad74(int param_1)

{
  do {
  } while (param_1 * 6 != 0);
  return;
}



// ===========================================================
// Function: FUN_0410ad9c at 0410ad9c
// ===========================================================

void FUN_0410ad9c(uint param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar2 = DAT_0410adec;
  iVar4 = DAT_0410ade4;
  *(undefined4 *)(DAT_0410ade8 + 4) = *(undefined4 *)(DAT_0410ade4 + 0x50);
  iVar3 = DAT_0410adf0;
  iVar1 = DAT_0410ade4;
  iVar5 = *piVar2;
  if ((uint)(*(int *)(iVar4 + 0x50) - iVar5) < 2) {
    do {
    } while ((uint)(*(int *)(iVar4 + 0x50) - *(int *)(iVar4 + 0x50)) <
             (uint)((iVar5 + 2) - *(int *)(iVar4 + 0x50)));
  }
  if (param_1 < 2) {
    iVar4 = 1;
  }
  else {
    iVar4 = param_1 - 1;
  }
  *(int *)(DAT_0410adf0 + 0x20) = iVar4;
  *piVar2 = *(int *)(iVar1 + 0x50);
  *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) | 0x80;
  return;
}



// ===========================================================
// Function: FUN_0410adf4 at 0410adf4
// ===========================================================

void FUN_0410adf4(void)

{
  int iVar1;
  
  iVar1 = DAT_0410ae14;
  *(uint *)(DAT_0410ae14 + 0x28) = *(uint *)(DAT_0410ae14 + 0x28) & 0xffffff7f;
  *(undefined4 *)(iVar1 + 0x2c) = 1;
  DataSynchronizationBarrier(0xf);
  *(undefined4 *)(DAT_0410ae18 + 0x184) = 0x8000000;
  return;
}



// ===========================================================
// Function: FUN_0410ae1c at 0410ae1c
// ===========================================================

undefined4 FUN_0410ae1c(void)

{
  return *(undefined4 *)(DAT_0410ae24 + 0x24);
}



// ===========================================================
// Function: FUN_0410ae28 at 0410ae28
// ===========================================================

int FUN_0410ae28(void)

{
  return *(int *)(DAT_0410ae34 + 0x50) - *(int *)(DAT_0410ae38 + 4);
}



// ===========================================================
// Function: FUN_0410aebc at 0410aebc
// ===========================================================

void FUN_0410aebc(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_0410af24;
  if (DAT_0410af20 < param_2) {
    iVar1 = DAT_0410af28;
  }
  if (param_1 == 0) {
    FUN_04107d40(DAT_0410af20 < param_2);
  }
  else if (param_1 == 1) {
    FUN_04107db8();
  }
  else if (param_1 == 2) {
    FUN_04107e30();
  }
  uVar3 = (iVar1 + (param_2 >> 1)) / param_2;
  uVar2 = uVar3 >> 6;
  if (uVar2 - 1 < 0xfffe) {
    iVar1 = *(int *)(DAT_0410af2c + param_1 * 0xc);
    *(uint *)(iVar1 + 0x24) = uVar2;
    *(uint *)(iVar1 + 0x28) = uVar3 & 0x3f;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410af30,param_2);
}



// ===========================================================
// Function: FUN_0410af34 at 0410af34
// ===========================================================

undefined4
FUN_0410af34(uint param_1,int *param_2,uint param_3,undefined1 *param_4,uint *param_5,
            undefined4 *param_6,byte param_7,uint param_8)

{
  undefined1 uVar1;
  bool bVar2;
  short sVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int *piVar15;
  undefined4 unaff_lr;
  undefined1 *local_80;
  short local_78;
  undefined1 *local_68;
  undefined1 auStack_54 [16];
  undefined1 local_44;
  byte local_43;
  short local_42;
  undefined4 local_40;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar14 = (uint)param_7;
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410b39c,param_1);
  }
  if (*(char *)(DAT_0410b1f4 + param_1 * 0xc + 4) == 'x') {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410b3a4,param_1);
  }
  iVar11 = *(int *)(DAT_0410b1f4 + param_1 * 0xc);
  if (-1 < *(int *)(iVar11 + 0x48) << 0x1f) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410b3a0,param_1);
  }
  if (param_3 == 0) {
    return 0xffffffff;
  }
  if (0xffe < param_8 - 1) {
    return 0xfffffffe;
  }
  iVar12 = *param_2;
  uVar8 = param_2[1];
  if (iVar12 == 0) {
    return 0xfffffffd;
  }
  if (uVar8 == 0) {
    return 0xfffffffc;
  }
  if (uVar14 == 0) {
    uVar9 = ((param_8 + uVar8) - 1) / param_8;
joined_r0x0410affc:
    if ((param_5 != (uint *)0x0) && (param_4 == (undefined1 *)0x0)) {
      if (uVar9 == 1) {
        uVar9 = 0;
      }
      goto LAB_0410afe0;
    }
  }
  else {
    if (uVar14 == 1) {
      uVar9 = (((param_8 - 1) + (uVar8 >> 1)) / param_8) * 2;
      param_8 = uVar8 / uVar9;
      if (uVar8 != uVar9 * param_8) {
        return 0xfffffffb;
      }
      if (uVar8 < uVar9) {
        return 0xfffffffa;
      }
    }
    else {
      uVar9 = ((param_8 + uVar8) - 1) / param_8;
      if (uVar14 != 2) {
        uVar9 = param_3 * uVar9;
        goto joined_r0x0410affc;
      }
      if (uVar9 == 1) {
        uVar9 = 2;
      }
      param_8 = (uVar9 + (uVar8 - 1)) / uVar9;
      if (CARRY4(uVar9,uVar8 - 1)) {
        return 0xfffffff9;
      }
    }
    if ((param_5 != (uint *)0x0) && (param_4 == (undefined1 *)0x0)) {
LAB_0410afe0:
      *param_5 = uVar9;
      return 0;
    }
  }
  if (uVar9 < 2) {
    local_80 = auStack_54;
    if (param_5 != (uint *)0x0) {
      uVar10 = 0;
      goto LAB_0410b018;
    }
  }
  else {
    if ((param_5 == (uint *)0x0) || (param_4 == (undefined1 *)0x0)) {
      return 0xfffffff5;
    }
    uVar10 = uVar9;
    local_80 = param_4;
    if (*param_5 < uVar9) {
      return 0xfffffff4;
    }
LAB_0410b018:
    *param_5 = uVar10;
  }
  if (*(char *)(DAT_0410b1f8 + param_1) != -1) {
    return 1;
  }
  uVar1 = *(undefined1 *)(DAT_0410b1f4 + param_1 * 0xc + 7);
  FUN_0410ef64(&local_44,0,0x1c);
  local_43 = local_43 & 0xf;
  local_3a = 0;
  local_38 = 0;
  local_30 = DAT_0410b1fc;
  local_78 = (short)uVar8;
  local_42 = local_78;
  local_40 = 0x4000000;
  local_3c = 2;
  local_3b = uVar1;
  local_34 = iVar12;
  if (param_6 == (undefined4 *)0x0) {
    if (*(int *)(iVar11 + 0x38) << 0x19 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_04109484(DAT_0410b208,DAT_0410b204);
    }
  }
  else {
    local_2c = DAT_0410b200;
  }
  if (uVar9 == 1) {
    iVar11 = FUN_0410e484(local_80,&local_44,0,1);
    puVar4 = DAT_0410b384;
  }
  else {
    sVar3 = (short)param_8;
    if (uVar14 == 3) {
      iVar11 = 0;
      uVar10 = param_2[1];
      local_68 = (undefined1 *)0x0;
      uVar14 = 0;
      do {
        piVar15 = param_2 + uVar14 * 3;
        if ((*(char *)((int)piVar15 + 9) == '\0') || (local_68 != (undefined1 *)0x0)) {
          puVar7 = local_80 + iVar11 * 0x10;
        }
        else {
          puVar7 = local_80 + iVar11 * 0x10;
          local_68 = puVar7;
        }
        if (param_8 < uVar10) {
          local_42 = sVar3;
          iVar12 = FUN_0410e484(puVar7,&local_44,local_80 + (iVar11 + 1) * 0x10,0);
          if (iVar12 != 0) {
            return 2;
          }
          uVar10 = uVar10 - param_8;
          local_34 = local_34 + param_8;
          uVar13 = uVar14;
        }
        else {
          local_42 = (short)uVar10;
          iVar12 = FUN_0410e484(puVar7,&local_44,local_80 + (iVar11 + 1) * 0x10,(char)piVar15[2]);
          if (iVar12 != 0) {
            return 2;
          }
          uVar13 = uVar14 + 1;
          if (param_3 <= uVar13) {
            return 2;
          }
          piVar15 = param_2 + uVar14 * 3 + 3;
          local_34 = param_2[uVar14 * 3 + 3];
          uVar10 = piVar15[1];
        }
        iVar11 = iVar11 + 1;
        uVar14 = uVar13;
      } while (uVar9 - 1 != iVar11);
      local_42 = (short)uVar10;
      iVar11 = FUN_0410e484(local_80 + (uVar9 - 1) * 0x10,&local_44,local_68,(char)piVar15[2]);
      puVar4 = DAT_0410b384;
    }
    else {
      iVar11 = 0;
      puVar7 = local_80;
      do {
        if (uVar14 == 1) {
          iVar12 = iVar11 - ((uVar9 >> 1) - 1);
        }
        else {
          iVar12 = uVar14 - 2;
        }
        local_42 = sVar3;
        iVar12 = FUN_0410e484(puVar7,&local_44,puVar7 + 0x10,iVar12 == 0);
        if (iVar12 != 0) {
          return 2;
        }
        iVar11 = iVar11 + 1;
        local_34 = local_34 + param_8;
        puVar7 = puVar7 + 0x10;
      } while (iVar11 != uVar9 - 1);
      local_42 = local_78 - (short)iVar11 * sVar3;
      puVar7 = local_80;
      if (1 < uVar14 - 1) {
        puVar7 = (undefined1 *)0x0;
      }
      iVar11 = FUN_0410e484(local_80 + iVar11 * 0x10,&local_44,puVar7,1);
      puVar4 = DAT_0410b384;
    }
  }
  if (iVar11 != 0) {
    DAT_0410b384 = puVar4;
    return 2;
  }
  iVar11 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    iVar11 = getBasePriority();
  }
  DAT_0410b384 = puVar4;
  if (iVar11 == 0x40) {
    if (*(char *)(DAT_0410b388 + param_1) != -1) goto LAB_0410b262;
    iVar12 = FUN_0410eb00(uVar1,0);
    local_44 = (undefined1)iVar12;
    if (iVar12 == 0xff) goto LAB_0410b286;
  }
  else {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(0x40);
    }
    *puVar4 = 0x410b24c;
    puVar4[1] = unaff_lr;
    if (*(char *)(DAT_0410b388 + param_1) != -1) {
      if (iVar11 == 0) {
        *puVar4 = 0xffffffff;
      }
LAB_0410b262:
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(iVar11);
      }
      return 3;
    }
    iVar12 = FUN_0410eb00(uVar1,0);
    local_44 = (undefined1)iVar12;
    if (iVar12 == 0xff) {
      if (iVar11 == 0) {
        *puVar4 = 0xffffffff;
      }
LAB_0410b286:
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(iVar11);
      }
      return 4;
    }
  }
  *(char *)(DAT_0410b388 + param_1) = (char)iVar12;
  *(byte *)(DAT_0410b38c + param_1) = param_7;
  *(uint *)(DAT_0410b390 + param_1 * 4) = uVar8;
  if (param_6 != (undefined4 *)0x0) {
    *(undefined4 *)(DAT_0410b394 + param_1 * 4) = *param_6;
  }
  *(undefined4 *)(*(int *)(DAT_0410b398 + param_1 * 0xc) + 0x44) = 0x40;
  iVar5 = FUN_0410ea14(local_80,&local_44);
  iVar12 = DAT_0410b388;
  if (iVar5 == 0) {
    uVar6 = 0;
  }
  else {
    FUN_0410ec68(*(undefined1 *)(DAT_0410b388 + param_1));
    uVar6 = 5;
    *(undefined1 *)(iVar12 + param_1) = 0xff;
  }
  if (iVar11 == 0) {
    *DAT_0410b384 = 0xffffffff;
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(iVar11);
  }
  return uVar6;
}



// ===========================================================
// Function: FUN_0410b3a8 at 0410b3a8
// ===========================================================

void FUN_0410b3a8(uint param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 unaff_lr;
  
  puVar2 = DAT_0410b474;
  iVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar6 = getBasePriority();
  }
  if (iVar6 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_0410b474 = 0x410b3c2;
    puVar2[1] = unaff_lr;
  }
  if (*DAT_0410b478 == param_1) {
    iVar8 = 0;
LAB_0410b45a:
    if (*(char *)(DAT_0410b484 + iVar8) == '\0') {
      DAT_0410b478[iVar8] = 0xff;
    }
  }
  else {
    if (DAT_0410b478[1] == param_1) {
      iVar8 = 1;
      goto LAB_0410b45a;
    }
    if (DAT_0410b478[2] == param_1) {
      iVar8 = 2;
      goto LAB_0410b45a;
    }
    iVar8 = 3;
  }
  if (iVar6 == 0) {
    *DAT_0410b474 = 0xffffffff;
  }
  iVar3 = DAT_0410b484;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar6);
  }
  if (iVar8 == 3) {
    return;
  }
  cVar5 = *(char *)(DAT_0410b484 + iVar8);
  if (cVar5 == '\0') {
    uVar7 = FUN_0410edbc(param_1);
    FUN_0410ec68(param_1);
    UNRECOVERED_JUMPTABLE = *(code **)(DAT_0410b47c + iVar8 * 4);
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      return;
    }
    cVar5 = *(char *)(iVar3 + iVar8);
    if (cVar5 == '\0') {
      uVar4 = *(uint *)(DAT_0410b480 + iVar8 * 4);
      if (uVar7 < uVar4) {
        uVar7 = uVar4 - uVar7;
      }
      else {
        uVar7 = 0;
      }
      goto LAB_0410b406;
    }
  }
  else {
    UNRECOVERED_JUMPTABLE = *(code **)(DAT_0410b47c + iVar8 * 4);
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      return;
    }
    uVar7 = 0;
  }
  if (cVar5 == '\x01') {
    uVar7 = *(uint *)(DAT_0410b480 + iVar8 * 4) >> 1;
  }
LAB_0410b406:
                    /* WARNING: Could not recover jumptable at 0x0410b412. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar7,param_3,0);
  return;
}



// ===========================================================
// Function: FUN_0410b488 at 0410b488
// ===========================================================

undefined4 FUN_0410b488(uint param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 unaff_lr;
  
  iVar7 = DAT_0410b570;
  if (param_1 < 3) {
    uVar6 = (uint)*(char *)(DAT_0410b570 + param_1 * 0xc + 4);
    if ((-1 < (int)uVar6) && (uVar6 != 0x78)) {
      *(int *)(DAT_0410b574 + ((uVar6 >> 5) + 0x20) * 4) = 1 << (uVar6 & 0x1f);
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
    }
    puVar4 = DAT_0410b57c;
    if (*DAT_0410b578 != '\0') {
      iVar8 = 0;
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        iVar8 = getBasePriority();
      }
      if (iVar8 != 0x40) {
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          setBasePriority(0x40);
        }
        *DAT_0410b57c = 0x410b4de;
        puVar4[1] = unaff_lr;
      }
      iVar5 = DAT_0410b584;
      if (*(char *)(DAT_0410b584 + param_1) != -1) {
        FUN_0410ea1c();
        FUN_0410ec68(*(undefined1 *)(iVar5 + param_1));
        *(undefined1 *)(iVar5 + param_1) = 0xff;
      }
      iVar5 = DAT_0410b588;
      if (*(char *)(DAT_0410b588 + param_1) != -1) {
        FUN_0410ea1c();
        FUN_0410ec68(*(undefined1 *)(iVar5 + param_1));
        *(undefined1 *)(iVar5 + param_1) = 0xff;
      }
      if (iVar8 == 0) {
        *DAT_0410b57c = 0xffffffff;
      }
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        setBasePriority(iVar8);
      }
    }
    iVar8 = *(int *)(iVar7 + param_1 * 0xc);
    iVar7 = iVar7 + param_1 * 0xc;
    uVar1 = *(undefined1 *)(iVar7 + 6);
    *(uint *)(iVar8 + 0x30) = *(uint *)(iVar8 + 0x30) & 0xfffffffe;
    *(uint *)(iVar8 + 0x2c) = *(uint *)(iVar8 + 0x2c) & 0xffffffef;
    FUN_041075b4(uVar1);
    uVar2 = *(undefined1 *)(iVar7 + 5);
    FUN_041075b4(uVar2);
    FUN_041074dc(uVar1);
    FUN_041074dc(uVar2);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410b580,param_1);
}



// ===========================================================
// Function: FUN_0410b58c at 0410b58c
// ===========================================================

uint FUN_0410b58c(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0410b5c8;
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410b5cc,param_1);
  }
  if ((*(byte *)(DAT_0410b5c8 + param_1 * 0xc + 6) < 0xdb) && (iVar2 = FUN_041075a8(), iVar2 != 1))
  {
    return 0;
  }
  return *(uint *)(*(int *)(iVar1 + param_1 * 0xc) + 0x30) & 1;
}



// ===========================================================
// Function: FUN_0410b8a0 at 0410b8a0
// ===========================================================

/* WARNING: Removing unreachable block (ram,0x0410b62c) */
/* WARNING: Removing unreachable block (ram,0x0410b82a) */
/* WARNING: Removing unreachable block (ram,0x0410b63c) */
/* WARNING: Removing unreachable block (ram,0x0410b7e8) */
/* WARNING: Removing unreachable block (ram,0x0410b646) */
/* WARNING: Removing unreachable block (ram,0x0410b84c) */
/* WARNING: Removing unreachable block (ram,0x0410b67c) */
/* WARNING: Removing unreachable block (ram,0x0410b7a0) */
/* WARNING: Removing unreachable block (ram,0x0410b7d0) */
/* WARNING: Removing unreachable block (ram,0x0410b7d8) */
/* WARNING: Removing unreachable block (ram,0x0410b7e0) */
/* WARNING: Removing unreachable block (ram,0x0410b834) */
/* WARNING: Removing unreachable block (ram,0x0410b7a6) */
/* WARNING: Removing unreachable block (ram,0x0410b824) */
/* WARNING: Removing unreachable block (ram,0x0410b7aa) */
/* WARNING: Removing unreachable block (ram,0x0410b83c) */
/* WARNING: Removing unreachable block (ram,0x0410b7ae) */
/* WARNING: Removing unreachable block (ram,0x0410b854) */
/* WARNING: Removing unreachable block (ram,0x0410b7b4) */
/* WARNING: Removing unreachable block (ram,0x0410b81c) */
/* WARNING: Removing unreachable block (ram,0x0410b7bc) */
/* WARNING: Removing unreachable block (ram,0x0410b7c4) */
/* WARNING: Removing unreachable block (ram,0x0410b7cc) */
/* WARNING: Recovered jumptable eliminated as dead code */
/* WARNING: Removing unreachable block (ram,0x0410b77a) */

undefined4 FUN_0410b8a0(uint param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  undefined2 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410b888,param_1);
  }
  if (*DAT_0410b864 == '\0') {
    *DAT_0410b864 = '\x01';
    puVar3 = DAT_0410b86c;
    *DAT_0410b86c = 0xffff;
    *(undefined1 *)(puVar3 + 1) = 0xff;
    puVar3 = DAT_0410b870;
    *DAT_0410b870 = 0xffff;
    *(undefined1 *)(puVar3 + 1) = 0xff;
  }
  iVar5 = DAT_0410b868;
  if (param_2 == 0) {
    uVar9 = *(uint *)(*(int *)(DAT_0410b868 + param_1 * 0xc) + 0x2c) | 0x10;
    param_2 = DAT_0410b880;
switchD_0000b60c_caseD_0:
    uVar6 = 0x301;
  }
  else {
    uVar9 = *(uint *)(*(int *)(DAT_0410b868 + param_1 * 0xc) + 0x2c) | 0x10;
    switch(*(undefined1 *)(param_2 + 3)) {
    case 0:
      goto switchD_0000b60c_caseD_0;
    case 1:
      uVar6 = 0x4301;
      break;
    case 2:
      uVar6 = 0x8301;
      break;
    case 3:
      uVar6 = 0xc301;
      break;
    default:
                    /* WARNING: Subroutine does not return */
      FUN_04109484(DAT_0410b894,*(undefined1 *)(param_2 + 3));
    }
  }
  uVar4 = (uint)*(byte *)(param_2 + 0xc);
  uVar8 = uVar4 & 1;
  if ((*(byte *)(param_2 + 0xc) & 1) != 0) {
    uVar9 = uVar9 | 0x8000;
    uVar8 = 1;
  }
  bVar2 = *(byte *)(param_2 + 5);
  bVar1 = *(byte *)(param_2 + 4);
  if ((int)(uVar4 << 0x1e) < 0) {
    uVar8 = uVar8 | 2;
  }
  if ((int)(uVar4 << 0x1d) < 0) {
    uVar8 = uVar8 | 4;
  }
  iVar7 = *(int *)(DAT_0410b868 + param_1 * 0xc);
  *(uint *)(iVar7 + 0x30) = *(uint *)(iVar7 + 0x30) & 0xfffffffe;
  *(uint *)(iVar7 + 0x2c) = *(uint *)(iVar7 + 0x2c) & 0xffffffef;
  do {
  } while ((*(uint *)(iVar7 + 0x18) & 8) != 0);
  *(undefined4 *)(iVar7 + 4) = 1;
  *(undefined4 *)(iVar7 + 0x38) = 0;
  *(undefined4 *)(iVar7 + 0x44) = 0xffffffff;
  *(undefined4 *)(iVar7 + 0x54) = 3;
  uVar4 = (uint)*(char *)(iVar5 + param_1 * 0xc + 4);
  *(uint *)(iVar7 + 0x48) = uVar8;
  *(undefined4 *)(iVar7 + 0x30) = uVar6;
  *(uint *)(iVar7 + 0x2c) = uVar9;
  *(uint *)(iVar7 + 0x34) = (bVar1 & 7) << 3 | bVar2 & 7;
  iVar5 = DAT_0410b874;
  if (uVar4 != 0x78) {
    *(undefined4 *)(*(int *)(DAT_0410b874 + 8) + (uVar4 + 0x10) * 4) = DAT_0410b878;
    iVar7 = DAT_0410b87c;
    DataSynchronizationBarrier(0xf);
    if ((int)uVar4 < 0) {
      *(undefined1 *)((uVar4 & 0xf) + iVar5 + 0x14) = 0xa0;
      return 0;
    }
    iVar5 = 1 << (uVar4 & 0x1f);
    *(undefined1 *)(DAT_0410b87c + uVar4 + 0x300) = 0xa0;
    *(int *)(iVar7 + (uVar4 >> 5) * 4 + 0x180) = iVar5;
    *(int *)(iVar7 + (uVar4 >> 5) * 4) = iVar5;
  }
  return 0;
}



// ===========================================================
// Function: FUN_0410b8a8 at 0410b8a8
// ===========================================================

undefined4 FUN_0410b8a8(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0410b910;
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410b914,param_1,param_3,param_4,param_4);
  }
  if (((0xda < *(byte *)(DAT_0410b910 + param_1 * 0xc + 6)) || (iVar1 = FUN_041075a8(), iVar1 == 1))
     && (iVar2 = *(int *)(iVar2 + param_1 * 0xc), *(int *)(iVar2 + 0x30) << 0x1f < 0)) {
    if ((*(uint *)(iVar2 + 0x18) & 8) == 0) {
      *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) & 0xfffffffe;
      FUN_0410aebc(param_1,param_2);
      *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)(iVar2 + 0x2c);
      *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) | 1;
      return 0;
    }
    return 2;
  }
  return 1;
}



// ===========================================================
// Function: FUN_0410b97c at 0410b97c
// ===========================================================

uint FUN_0410b97c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 < 3) {
    return ((*(uint *)(*(int *)(DAT_0410b9a0 + param_1 * 0xc) + 0x18) ^ 0x20) & 0x3f) >> 5;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410b9a4,param_1,param_3,param_4,param_4);
}



// ===========================================================
// Function: FUN_0410b9a8 at 0410b9a8
// ===========================================================

void FUN_0410b9a8(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410b9dc,param_1,param_3,param_1,param_4);
  }
  puVar1 = *(undefined4 **)(DAT_0410b9d8 + param_1 * 0xc);
  if ((puVar1[0x12] & 2) == 0) {
    *puVar1 = param_2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410b9e0,param_1,puVar1,param_1,param_4);
}



// ===========================================================
// Function: FUN_0410b9e4 at 0410b9e4
// ===========================================================

void FUN_0410b9e4(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 < 3) {
    iVar1 = *(int *)(DAT_0410ba08 + param_1 * 0xc);
    *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) | 1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410ba0c,param_1,param_3,param_4,param_4);
}



// ===========================================================
// Function: FUN_0410ba10 at 0410ba10
// ===========================================================

void FUN_0410ba10(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 < 3) {
    iVar1 = *(int *)(DAT_0410ba34 + param_1 * 0xc);
    *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) & 0xfffffffe;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410ba38,param_1,param_3,param_4,param_4);
}



// ===========================================================
// Function: FUN_0410ba3c at 0410ba3c
// ===========================================================

void FUN_0410ba3c(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 < 3) {
    iVar1 = FUN_0410b58c();
    if (iVar1 != 0) {
      iVar1 = *(int *)(DAT_0410ba90 + param_1 * 0xc);
      if (param_2 == 0) {
        param_2 = 2;
      }
      *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) & 0xfffffffe;
      FUN_0410ad60(param_2);
      *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) & 0xffffffef;
      *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) | 0x10;
      *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) | 1;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410ba94,param_1,param_3,param_4,param_4);
}



// ===========================================================
// Function: FUN_0410ba98 at 0410ba98
// ===========================================================

int FUN_0410ba98(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410bae0,param_1);
  }
  iVar1 = *(int *)(DAT_0410bad0 + param_1 * 0xc);
  iVar2 = *(int *)(iVar1 + 0x38);
  if (((-1 < iVar2 << 0x19) && (param_2 << 0x19 < 0)) && (*(char *)(DAT_0410bad4 + param_1) != -1))
  {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410badc,DAT_0410bad8);
  }
  *(int *)(iVar1 + 0x38) = param_2;
  return iVar2;
}



// ===========================================================
// Function: FUN_0410bae4 at 0410bae4
// ===========================================================

void FUN_0410bae4(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_0410bb0c;
  if (param_1 < 3) {
    *(undefined4 *)(DAT_0410bb08 + param_1 * 4) = param_2;
    uVar3 = DAT_0410bb14;
    iVar2 = DAT_0410bb10;
    *(undefined4 *)(iVar1 + param_1 * 4) = param_3;
    *(undefined4 *)(iVar2 + param_1 * 4) = uVar3;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410bb18,param_1);
}



// ===========================================================
// Function: FUN_0410bb1c at 0410bb1c
// ===========================================================

void FUN_0410bb1c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_c;
  
  local_c = 0;
  local_14 = param_2;
  local_10 = param_3;
  FUN_0410af34(param_1,&local_14,1,param_4,param_5,0,0,0xfff);
  return;
}



// ===========================================================
// Function: FUN_0410bb48 at 0410bb48
// ===========================================================

undefined4 FUN_0410bb48(uint param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char cVar6;
  undefined4 unaff_lr;
  
  puVar2 = DAT_0410bbb4;
  if (2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410bbbc,param_1);
  }
  iVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar5 = getBasePriority();
  }
  if (iVar5 == 0x40) {
    cVar6 = *(char *)(DAT_0410bbb8 + param_1);
    *(undefined1 *)(DAT_0410bbb8 + param_1) = 0xff;
  }
  else {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_0410bbb4 = 0x410bb60;
    iVar3 = DAT_0410bbb8;
    puVar2[1] = unaff_lr;
    cVar6 = *(char *)(iVar3 + param_1);
    *(undefined1 *)(iVar3 + param_1) = 0xff;
    if (iVar5 == 0) {
      *puVar2 = 0xffffffff;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar5);
  }
  if (cVar6 != -1) {
    FUN_0410ea68(cVar6);
    uVar4 = FUN_0410edbc(cVar6);
    FUN_0410ec68(cVar6);
    return uVar4;
  }
  return 0;
}



// ===========================================================
// Function: FUN_0410bbc8 at 0410bbc8
// ===========================================================

void FUN_0410bbc8(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar3;
  
  if ((*(char *)(DAT_0410bc04 + param_1) != -1) && (*(char *)(DAT_0410bc08 + param_1) == '\0')) {
    uVar2 = FUN_0410bb48();
    uVar3 = *(uint *)(DAT_0410bc10 + param_1 * 4);
    if (uVar2 < uVar3) {
      iVar1 = uVar3 - uVar2;
      goto LAB_0410bbde;
    }
  }
  iVar1 = 0;
LAB_0410bbde:
  UNRECOVERED_JUMPTABLE = *(code **)(DAT_0410bc0c + param_1 * 4);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0410bbee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(iVar1,0,param_2);
    return;
  }
  return;
}



// ===========================================================
// Function: FUN_0410bc14 at 0410bc14
// ===========================================================

void FUN_0410bc14(int param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = param_2 + 1;
  if (param_3 == 0) {
    bVar1 = *(byte *)(param_2 + 3);
    puVar2 = param_2;
  }
  else {
    bVar1 = *(byte *)((int)param_2 + 0xd);
  }
  puVar3 = *(undefined4 **)(DAT_0410bc38 + param_1 * 4);
  *puVar3 = *puVar2;
  puVar3[0x22] = (uint)bVar1;
  return;
}



// ===========================================================
// Function: FUN_0410bc3c at 0410bc3c
// ===========================================================

/* WARNING: Removing unreachable block (ram,0x04107ede) */
/* WARNING: Removing unreachable block (ram,0x04107efe) */
/* WARNING: Removing unreachable block (ram,0x04107ee2) */
/* WARNING: Removing unreachable block (ram,0x04107f84) */
/* WARNING: Removing unreachable block (ram,0x04107f64) */
/* WARNING: Removing unreachable block (ram,0x04107f68) */
/* WARNING: Removing unreachable block (ram,0x0410772c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0410bc3c(void)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 unaff_lr;
  undefined8 uVar10;
  
  uVar10 = FUN_0410bc14();
  iVar7 = (int)((ulonglong)uVar10 >> 0x20);
  iVar8 = (int)uVar10;
  iVar9 = *(int *)(DAT_0410bca4 + iVar8 * 4);
  *(uint *)(iVar9 + 4) = (uint)*(ushort *)(iVar7 + 8);
  *(uint *)(iVar9 + 0x10) = (uint)*(byte *)(iVar7 + 10);
  *(uint *)(iVar9 + 0x24) = (uint)*(byte *)(iVar7 + 0xb);
  if (*(char *)(iVar7 + 0xf) == '\0') {
    *(undefined4 *)(iVar9 + 0x2c) = 0;
  }
  else {
    *(uint *)(iVar9 + 0x28) = (uint)*(byte *)(iVar7 + 0xe);
    *(uint *)(iVar9 + 0x2c) = *(byte *)(iVar7 + 0xf) | 0x40000;
  }
  cVar1 = *(char *)(iVar7 + 0x10);
  if (*(char *)(DAT_0410bca8 + iVar8) == cVar1) {
    return iVar8;
  }
  *(char *)(DAT_0410bca8 + iVar8) = cVar1;
  puVar6 = DAT_04107f9c;
  puVar5 = DAT_04107f18;
  puVar4 = DAT_04107748;
  bVar3 = cVar1 == '\x02';
  if (iVar8 == 0) {
    iVar8 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      iVar8 = getBasePriority();
    }
    if (iVar8 != 0x40) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(0x40);
      }
      *DAT_04107748 = 0x4107700;
      puVar4[1] = unaff_lr;
    }
    if (bVar3) {
      _DAT_400000a8 = _DAT_400000a8 & 0xbbffffff | 0x4000000;
    }
    else {
      _DAT_400000a8 = _DAT_400000a8 & 0xbbffffff;
    }
    if (iVar8 == 0) {
      *DAT_04107748 = 0xffffffff;
    }
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      setBasePriority(iVar8);
    }
    return 0;
  }
  if (iVar8 == 1) {
    iVar8 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      iVar8 = getBasePriority();
    }
    if (iVar8 != 0x40) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(0x40);
      }
      *DAT_04107f18 = 0x4107eb4;
      puVar5[1] = unaff_lr;
    }
    if (bVar3) {
      _DAT_400000a8 = DAT_04107f1c & _DAT_400000a8 | 0x40000;
    }
    else {
      _DAT_400000a8 = DAT_04107f1c & _DAT_400000a8;
    }
    if (iVar8 == 0) {
      *DAT_04107f18 = 0xffffffff;
    }
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      setBasePriority(iVar8);
    }
    return 0;
  }
  iVar8 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    iVar8 = getBasePriority();
  }
  if (iVar8 != 0x40) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(0x40);
    }
    *DAT_04107f9c = 0x4107f38;
    puVar6[1] = unaff_lr;
  }
  if (bVar3) {
    _DAT_400000a8 = _DAT_400000a8 & 0xdc7fffff | 0x800000;
  }
  else {
    _DAT_400000a8 = _DAT_400000a8 & 0xdc7fffff;
  }
  if (iVar8 == 0) {
    *DAT_04107f9c = 0xffffffff;
  }
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    setBasePriority(iVar8);
  }
  return 0;
}



// ===========================================================
// Function: FUN_0410bcac at 0410bcac
// ===========================================================

undefined4 FUN_0410bcac(int param_1,uint param_2,uint param_3,int param_4,int param_5,uint param_6)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  if ((param_3 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410bdac,param_1);
  }
  uVar3 = ((param_2 & 0x1fffff) >> 0x10) + 1;
  if (uVar3 < 9) {
    if (param_6 == 0) {
      return 0xffffffff;
    }
    iVar6 = 1;
  }
  else {
    if (uVar3 < 0x11) {
      iVar6 = 2;
    }
    else {
      iVar6 = 4;
    }
    if ((param_6 == 0) || ((iVar6 - 1U & param_6) != 0)) {
      return 0xffffffff;
    }
  }
  iVar4 = *(int *)(DAT_0410bda8 + param_1 * 4);
  if ((*(uint *)(iVar4 + 0xc) & 0x10) != 0) {
    return 0xfffffff5;
  }
  do {
  } while (*(int *)(iVar4 + 0xc) << 0x1d < 0);
  *(undefined4 *)(iVar4 + 0x20) = 0xffffffff;
  if (param_6 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
    uVar2 = 0;
    uVar5 = 0;
    do {
      if (-1 < *(int *)(iVar4 + 4) << 0x1e) break;
      if (((uVar5 < param_6) && (uVar5 < uVar2 + 0x20)) && (*(int *)(iVar4 + 0xc) << 0x1e < 0)) {
        if (param_4 == 0) {
          uVar3 = 0xffffffff;
        }
        else if (iVar6 == 1) {
          uVar3 = (uint)*(byte *)(param_4 + uVar5);
        }
        else if (iVar6 == 2) {
          uVar3 = (uint)(ushort)*(uint *)(param_4 + uVar5);
        }
        else {
          uVar3 = *(uint *)(param_4 + uVar5);
        }
        uVar5 = uVar5 + iVar6;
        *(uint *)(iVar4 + 8) = uVar3;
      }
      if ((uVar2 < param_6) && (*(int *)(iVar4 + 0xc) << 0x1d < 0)) {
        uVar1 = *(undefined4 *)(iVar4 + 8);
        if (iVar6 == 1) {
          *(char *)(param_5 + uVar2) = (char)uVar1;
        }
        else if (iVar6 == 2) {
          *(short *)(param_5 + uVar2) = (short)uVar1;
        }
        else {
          *(undefined4 *)(param_5 + uVar2) = uVar1;
        }
        uVar2 = uVar2 + iVar6;
      }
      uVar3 = uVar5;
      if (uVar2 <= uVar5) {
        uVar3 = uVar2;
      }
    } while (uVar3 < param_6);
  }
  if (uVar3 < param_6) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  do {
    if (-1 < *(int *)(iVar4 + 4) << 0x1e) {
      return uVar1;
    }
  } while (*(int *)(iVar4 + 0xc) << 0x1b < 0);
  return uVar1;
}



// ===========================================================
// Function: FUN_0410bdb0 at 0410bdb0
// ===========================================================

undefined4 FUN_0410bdb0(int param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (param_3 << 0x1e < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410be40,param_1);
  }
  uVar3 = ((param_2 & 0x1fffff) >> 0x10) + 1;
  if (uVar3 < 9) {
    if (param_5 == 0) {
      return 0xffffffff;
    }
    iVar5 = 1;
  }
  else {
    if (uVar3 < 0x11) {
      iVar5 = 2;
    }
    else {
      iVar5 = 4;
    }
    if (param_5 == 0) {
      return 0xffffffff;
    }
    if ((iVar5 - 1U & param_5) != 0) {
      return 0xffffffff;
    }
  }
  iVar4 = *(int *)(DAT_0410be3c + param_1 * 4);
  uVar3 = 0;
  while ((uVar3 < param_5 && (*(int *)(iVar4 + 4) << 0x1e < 0))) {
    if (*(int *)(iVar4 + 0xc) << 0x1e < 0) {
      if (iVar5 == 1) {
        uVar2 = (uint)*(byte *)(param_4 + uVar3);
      }
      else if (iVar5 == 2) {
        uVar2 = (uint)(ushort)*(uint *)(param_4 + uVar3);
      }
      else {
        uVar2 = *(uint *)(param_4 + uVar3);
      }
      uVar3 = uVar3 + iVar5;
      *(uint *)(iVar4 + 8) = uVar2;
    }
  }
  if (uVar3 < param_5) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  do {
    if (-1 < *(int *)(iVar4 + 4) << 0x1e) {
      return uVar1;
    }
  } while (*(int *)(iVar4 + 0xc) << 0x1b < 0);
  return uVar1;
}



// ===========================================================
// Function: FUN_0410be44 at 0410be44
// ===========================================================

undefined4 FUN_0410be44(uint *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  longlong lVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  
  uVar5 = DAT_0410c050;
  if ((int)((uint)(byte)param_1[1] << 0x1d) < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410c07c);
  }
  uVar8 = *param_1 * 2;
  bVar12 = DAT_0410c050 <= uVar8;
  bVar11 = uVar8 - DAT_0410c050 != 0;
  if (bVar12 && bVar11) {
    uVar7 = 2;
    uVar8 = DAT_0410c050;
  }
  else {
    uVar7 = 1;
    uVar8 = DAT_0410c054;
  }
  *(undefined1 *)(param_2 + 4) = uVar7;
  uVar9 = *param_1;
  uVar10 = DAT_0410c058;
  if (!bVar12 || !bVar11) {
    uVar10 = uVar5;
  }
  if (uVar8 < uVar9) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410c070,uVar9,uVar8,uVar8,param_4);
  }
  lVar2 = (ulonglong)DAT_0410c05c * (ulonglong)(uVar10 >> 9);
  uVar5 = (uint)((ulonglong)lVar2 >> 0x20);
  if (uVar9 < uVar5) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410c084,uVar9,uVar5,(int)lVar2,param_4);
  }
  uVar5 = (uint)*(byte *)((int)param_1 + 7);
  uVar8 = uVar5 - 4;
  if (0x1c < uVar8) {
LAB_0410c006:
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410c064,uVar5,uVar5,uVar8,param_4);
  }
  uVar8 = (uint)(byte)param_1[2];
  if (0x1c < uVar8 - 4) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410c074,uVar8,uVar5,uVar8,param_4);
  }
  if ((param_1[1] & 0x40) == 0) {
    uVar5 = (uint)*(byte *)((int)param_1 + 9);
    if (0x20 < uVar5) goto LAB_0410c00e;
  }
  else {
    if (uVar5 == 0x20) goto LAB_0410c006;
    uVar5 = (uint)*(byte *)((int)param_1 + 9);
    if ((uVar8 == 0x20) || (0x1f < uVar5)) {
                    /* WARNING: Subroutine does not return */
      FUN_04109484(DAT_0410c060,uVar8,uVar5,uVar8,param_4);
    }
  }
  if ((uVar8 < uVar5) || (uVar5 == 0)) {
    bVar3 = *(byte *)((int)param_1 + 6);
    if (3 < bVar3) {
                    /* WARNING: Subroutine does not return */
      FUN_04109484(DAT_0410c06c,bVar3,uVar5,bVar3,param_4);
    }
    uVar9 = ((uVar9 - 1) + uVar10) / uVar9;
    uVar5 = uVar9 + 0xff >> 8;
    if (uVar5 == 1) {
      uVar8 = 2;
    }
    else {
      uVar8 = uVar9 + 0xff >> 8 & 0xffff;
      if ((int)(uVar5 << 0x1f) < 0) {
        uVar8 = uVar8 + 1 & 0xffff;
      }
      if (0xfd < uVar8) {
        uVar8 = 0xfe;
      }
    }
    uVar6 = ((uVar9 - 1) + uVar8) / uVar8 & 0xffff;
    uVar5 = 0;
    uVar10 = uVar8;
    if (uVar6 != 0) {
      uVar5 = uVar6 - 1 & 0xffff;
      if (0xfe < uVar5) {
        uVar5 = 0xff;
      }
      uVar9 = uVar5 + 1 & 0xffff;
      uVar10 = uVar9 * uVar8;
    }
    uVar10 = uVar10 - 1;
    *(char *)((int)param_2 + 0xe) = (char)uVar10;
    if (uVar10 != (uVar10 & 0xff)) {
                    /* WARNING: Subroutine does not return */
      FUN_04109484(DAT_0410c078,uVar10,uVar9,uVar5,param_4);
    }
    bVar3 = *(byte *)((int)param_1 + 10);
    if (uVar10 < bVar3) {
                    /* WARNING: Subroutine does not return */
      FUN_04109484(DAT_0410c080,(uint)bVar3,uVar10,uVar5,param_4);
    }
    *(byte *)((int)param_2 + 0xf) = bVar3;
    uVar6 = ((byte)param_1[1] & 1) << 7 | ((byte)param_1[1] & 2) << 5;
    uVar5 = uVar5 << 8;
    *param_2 = uVar6 | uVar5 | (*(byte *)((int)param_1 + 7) - 1) * 0x10000 & 0x1f0000;
    uVar10 = param_1[1];
    uVar9 = (uint)(byte)uVar10;
    bVar3 = *(byte *)((int)param_1 + 5);
    bVar1 = *(byte *)((int)param_1 + 6);
    *(char *)((int)param_2 + 10) = (char)uVar8;
    uVar4 = (byte)uVar10 & 4 | (bVar3 & 3) << 0xc | (ushort)((uVar9 & 4) << 3) |
            (ushort)((uVar9 & 0x20) << 6) | (bVar1 & 0xf) << 7;
    if (-1 < (int)(uVar9 << 0x18)) {
      uVar4 = uVar4 | 2;
    }
    *(ushort *)(param_2 + 2) = uVar4;
    *(byte *)((int)param_2 + 0xb) = (byte)(((uint)(byte)param_1[1] << 0x1b) >> 0x1e);
    bVar3 = ((byte)param_1[1] & 0x40) << 1;
    *(byte *)(param_2 + 3) = bVar3;
    if (*(byte *)((int)param_1 + 9) != 0) {
      param_2[1] = uVar6 | uVar5 & 0xffe0ffff |
                   (*(byte *)((int)param_1 + 9) - 1) * 0x10000 & 0x1f0000;
      *(byte *)((int)param_2 + 0xd) = bVar3 | (char)param_1[2] - 1U & 0x1f | 0x60;
      return 0;
    }
    uVar8 = param_1[2];
    *(byte *)((int)param_2 + 0xd) = bVar3;
    param_2[1] = uVar6 | uVar5 & 0xffe0ffff | ((byte)uVar8 - 1) * 0x10000 & 0x1f0000;
    return 0;
  }
LAB_0410c00e:
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410c068,uVar5,uVar5,uVar8,param_4);
}



// ===========================================================
// Function: FUN_0410c120 at 0410c120
// ===========================================================

int FUN_0410c120(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char *pcVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int iVar7;
  
  uVar6 = DAT_0410c140;
  if ((*(char *)(param_1 + 7) == *(char *)(param_1 + 8)) && (*(char *)(param_1 + 9) == '\0')) {
    iVar7 = FUN_0410be44(param_1,DAT_0410c140,DAT_0410c140,param_4);
    puVar4 = DAT_0410c110;
    pcVar3 = DAT_0410c10c;
    if (iVar7 == 0) {
      if (*DAT_0410c10c == '\0') {
        *DAT_0410c110 = 0xffff;
        *(undefined1 *)(puVar4 + 1) = 0xff;
        puVar4 = DAT_0410c114;
        *DAT_0410c114 = 0xffff;
        *(undefined1 *)(puVar4 + 1) = 0xff;
        *pcVar3 = '\x01';
      }
      puVar5 = DAT_0410c11c;
      if (*DAT_0410c118 == 0) {
        uVar2 = *DAT_0410c11c;
        *DAT_0410c118 = (byte)(1 << *(sbyte *)(param_1 + 6));
        FUN_041074d0(uVar2);
        uVar1 = puVar5[1];
        FUN_041074d0(uVar1);
        FUN_041076c4(uVar2);
        FUN_041076c4(uVar1);
      }
      else {
        *DAT_0410c118 = (byte)(1 << *(sbyte *)(param_1 + 6)) | *DAT_0410c118;
      }
      FUN_0410bc3c(0,uVar6,0);
    }
    return iVar7;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410c144);
}



// ===========================================================
// Function: FUN_0410c148 at 0410c148
// ===========================================================

void FUN_0410c148(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 < 0xf) {
    *(uint *)(DAT_0410c168 + 4) = *(uint *)(DAT_0410c168 + 4) & 0xfffff87f | param_1 << 7;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410c16c,param_1,param_3,param_4,param_4);
}



// ===========================================================
// Function: FUN_0410c170 at 0410c170
// ===========================================================

undefined4 FUN_0410c170(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0410bc3c(0,param_1,0,param_4,param_4);
  return 0;
}



// ===========================================================
// Function: FUN_0410c180 at 0410c180
// ===========================================================

undefined4 FUN_0410c180(void)

{
  undefined4 in_r3;
  
  FUN_0410bc3c(0,DAT_0410c190,0,in_r3,in_r3);
  return 0;
}



// ===========================================================
// Function: FUN_0410c194 at 0410c194
// ===========================================================

void FUN_0410c194(undefined4 param_1,undefined4 param_2)

{
  FUN_0410bdb0(0,*DAT_0410c1ac,*(undefined1 *)((int)DAT_0410c1ac + 0xb),param_1,param_2);
  return;
}



// ===========================================================
// Function: FUN_0410c1b0 at 0410c1b0
// ===========================================================

void FUN_0410c1b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0410bcac(0,*(undefined4 *)(DAT_0410c1d0 + 4),*(undefined1 *)(DAT_0410c1d0 + 0xb),param_1,
               param_2,param_3);
  return;
}



// ===========================================================
// Function: FUN_0410c1d4 at 0410c1d4
// ===========================================================

void FUN_0410c1d4(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0410bdb0(0,*param_1,*(undefined1 *)((int)param_1 + 0xb),param_2,param_3);
  return;
}



// ===========================================================
// Function: FUN_0410c1f4 at 0410c1f4
// ===========================================================

void FUN_0410c1f4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0410bcac(0,*(undefined4 *)(param_1 + 4),*(undefined1 *)(param_1 + 0xb),param_2,param_3,param_4
              );
  return;
}



// ===========================================================
// Function: FUN_0410c218 at 0410c218
// ===========================================================

void FUN_0410c218(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 < 0x41) {
    if ((param_1 != 0) && (param_2 != 0)) {
      FUN_0410ef70(DAT_0410c268,param_1,param_2,param_4,param_4);
    }
    uVar2 = DAT_0410c268;
    iVar1 = DAT_0410c264;
    DataMemoryBarrier(0x1f);
    *(uint *)(DAT_0410c264 + 0x910) = param_2 | 0x80000;
    uVar2 = FUN_04107478(uVar2);
    *(undefined4 *)(iVar1 + 0x914) = uVar2;
    *(undefined4 *)(iVar1 + 0x908) = *(undefined4 *)(iVar1 + 0x908);
    *(uint *)(iVar1 + 0x900) = *(uint *)(iVar1 + 0x900) | 0x84000000;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410c26c);
}



// ===========================================================
// Function: FUN_0410c270 at 0410c270
// ===========================================================

void FUN_0410c270(int param_1)

{
  char cVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = DAT_0410c2a8 + (param_1 + -1) * 0xc;
  cVar1 = *(char *)(iVar2 + 8);
  FUN_0410ef64(iVar2,0,0xc);
  if ((cVar1 != '\0') &&
     (UNRECOVERED_JUMPTABLE = *(code **)(DAT_0410c2ac + param_1 * 4 + 0x20),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0410c2a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(0,0,1);
    return;
  }
  return;
}



// ===========================================================
// Function: FUN_0410c2b0 at 0410c2b0
// ===========================================================

void FUN_0410c2b0(int param_1)

{
  char cVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = DAT_0410c2e8 + (param_1 + -1) * 0xc;
  cVar1 = *(char *)(iVar2 + 0xb);
  FUN_0410ef64(iVar2,0,0xc);
  if ((cVar1 != '\0') &&
     (UNRECOVERED_JUMPTABLE = *(code **)(DAT_0410c2ec + param_1 * 4 + 0x38),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0410c2e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(0,0,1);
    return;
  }
  return;
}



// ===========================================================
// Function: FUN_0410c2f0 at 0410c2f0
// ===========================================================

void FUN_0410c2f0(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    uVar4 = *(uint *)(DAT_0410c3d0 + 0x900);
    if ((uVar4 & 0x80008000) == 0) {
      return;
    }
    piVar1 = (int *)(DAT_0410c3d0 + 0x908);
    puVar2 = DAT_0410c3d4;
    if ((uVar4 & DAT_0410c3c8) == 0x20000) goto LAB_0410c316;
LAB_0410c370:
    *piVar1 = 0x40;
    *puVar2 = DAT_0410c3cc | param_2 | *puVar2;
    if (-1 < (int)uVar4) goto LAB_0410c32c;
    if (-1 < (int)(uVar4 << 0xe)) {
      do {
      } while (-1 < *piVar1 << 0x19);
      *piVar1 = 0x40;
    }
    if (param_3 != 0) {
      *puVar2 = *puVar2 & ~param_3;
    }
    *piVar1 = 2;
    *puVar2 = *puVar2 | 0x40000000;
    do {
    } while (-1 < *piVar1 << 0x1e);
LAB_0410c330:
    iVar3 = DAT_0410c3d0;
    *(uint *)(DAT_0410c3d0 + 0x10) = param_1 << 6 | 0x20;
    do {
    } while (*(int *)(iVar3 + 0x10) << 0x1a < 0);
    if (-1 < (int)(uVar4 << 0x10)) {
      *puVar2 = *puVar2 & 0xffff7fff;
    }
  }
  else {
    iVar3 = (param_1 + -1) * 0x20;
    puVar2 = (uint *)(DAT_0410c3c4 + (param_1 + -1) * 0x20);
    uVar4 = *(uint *)(iVar3 + DAT_0410c3c4);
    if ((uVar4 & 0x80008000) == 0) goto LAB_0410c3aa;
    piVar1 = (int *)(DAT_0410c3c4 + iVar3 + 8);
    if ((uVar4 & DAT_0410c3c8) != 0x20000) goto LAB_0410c370;
LAB_0410c316:
    if ((param_2 != 0x8000000) || (param_3 != 0)) {
      *piVar1 = 0x40;
      *puVar2 = DAT_0410c3cc | *puVar2 | param_2;
LAB_0410c32c:
      if (param_3 != 0) {
        *puVar2 = *puVar2 & ~param_3;
      }
      goto LAB_0410c330;
    }
  }
  if (param_1 == 0) {
    return;
  }
LAB_0410c3aa:
  FUN_0410c2b0();
  return;
}



// ===========================================================
// Function: FUN_0410c3d8 at 0410c3d8
// ===========================================================

void FUN_0410c3d8(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar5 = DAT_0410c528;
  *(uint *)(DAT_0410c528 + 0x804) = *(uint *)(DAT_0410c528 + 0x804) | 0x200;
  iVar1 = FUN_0410ad54();
  do {
    if (*(int *)(iVar5 + 0x14) << 0x18 < 0) break;
    iVar3 = FUN_0410ad54();
  } while ((uint)(iVar3 - iVar1) < 4);
  iVar1 = DAT_0410c530;
  iVar5 = DAT_0410c528;
  if (*(int *)(DAT_0410c528 + 0x14) << 0x18 < 0) {
    return;
  }
  if (-1 < *(int *)(DAT_0410c528 + 0xb00)) {
    uVar7 = *(undefined4 *)(DAT_0410c528 + 0xb10);
    uVar6 = *(undefined4 *)(DAT_0410c528 + 0xb14);
    *(undefined4 *)(DAT_0410c528 + 0xb10) = DAT_0410c52c;
    uVar2 = FUN_04107478(iVar1);
    *(undefined4 *)(iVar5 + 0xb14) = uVar2;
    *(uint *)(iVar5 + 0xb00) = *(uint *)(iVar5 + 0xb00) | 0x88000000;
    iVar1 = FUN_0410ad54();
    do {
      if (*(int *)(iVar5 + 0x14) << 0x18 < 0) break;
      iVar3 = FUN_0410ad54();
    } while ((uint)(iVar3 - iVar1) < 4);
    uVar2 = DAT_0410c538;
    iVar5 = DAT_0410c528;
    if (*(int *)(DAT_0410c528 + 0xb00) < 0) {
      if ((*(uint *)(DAT_0410c528 + 0xb08) & 9) != 0) goto LAB_0410c4da;
      if (*DAT_0410c534 - 3 < 2) {
        DataMemoryBarrier(0x1f);
        *(undefined4 *)(DAT_0410c528 + 0xb10) = DAT_0410c52c;
        uVar2 = FUN_04107478(uVar2);
        *(undefined4 *)(iVar5 + 0xb14) = uVar2;
        *(undefined4 *)(iVar5 + 0xb08) = *(undefined4 *)(iVar5 + 0xb08);
        *(uint *)(iVar5 + 0xb00) = *(uint *)(iVar5 + 0xb00) | 0x80000000;
        *(uint *)(iVar5 + 0xb00) = *(uint *)(iVar5 + 0xb00) | 0x4000000;
      }
      else {
        DataMemoryBarrier(0x1f);
        *(undefined4 *)(DAT_0410c528 + 0xb10) = DAT_0410c52c;
        uVar2 = FUN_04107478(uVar2);
        *(undefined4 *)(iVar5 + 0xb14) = uVar2;
        *(undefined4 *)(iVar5 + 0xb08) = *(undefined4 *)(iVar5 + 0xb08);
        *(uint *)(iVar5 + 0xb00) = *(uint *)(iVar5 + 0xb00) | 0x80000000;
        *(uint *)(iVar5 + 0xb00) = *(uint *)(iVar5 + 0xb00) | 0x8000000;
      }
    }
    else {
      uVar4 = *(uint *)(DAT_0410c528 + 0xb10) & 0x7f;
      if (uVar4 == 0x40) {
LAB_0410c4da:
        *(undefined4 *)(DAT_0410c528 + 0xb10) = uVar7;
        *(undefined4 *)(iVar5 + 0xb14) = uVar6;
        iVar5 = *(int *)(iVar5 + 0x14);
        goto joined_r0x0410c4e8;
      }
      if (-1 < (int)(*(uint *)(DAT_0410c528 + 0xb10) << 0x19)) {
        FUN_0410ef70(DAT_0410c530 + -0x40,DAT_0410c530,0x40 - uVar4);
        DataMemoryBarrier(0x1f);
        *(int *)(iVar5 + 0xb14) = *(int *)(iVar5 + 0xb14) + -0x40;
      }
    }
  }
  iVar5 = *(int *)(DAT_0410c528 + 0x14);
joined_r0x0410c4e8:
  if (iVar5 << 0x18 < 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410c53c);
}



// ===========================================================
// Function: FUN_0410c540 at 0410c540
// ===========================================================

void FUN_0410c540(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    uVar4 = *(uint *)(DAT_0410c610 + 0xb00);
    puVar1 = DAT_0410c618;
    piVar2 = DAT_0410c614;
    if ((uVar4 & 0x80008000) == 0) {
      return;
    }
  }
  else {
    iVar3 = (param_1 + -1) * 0x20;
    uVar4 = *(uint *)(iVar3 + DAT_0410c604);
    if ((uVar4 & 0x80008000) == 0) goto LAB_0410c5de;
    puVar1 = (uint *)(DAT_0410c604 + (param_1 + -1) * 0x20);
    piVar2 = (int *)(iVar3 + 8 + DAT_0410c604);
  }
  if ((((uVar4 & DAT_0410c608) != 0x20000) || (param_2 != 0x8000000)) || (param_3 != 0)) {
    FUN_0410c3d8();
    param_2 = param_2 | *puVar1;
    *puVar1 = DAT_0410c60c | param_2;
    if (param_3 != 0) {
      *puVar1 = *puVar1 & ~param_3;
    }
    if (param_1 != 0) {
      if ((int)uVar4 < 0) {
        *piVar2 = 2;
        *puVar1 = *puVar1 | 0x40000000;
        do {
        } while (-1 < *piVar2 << 0x1e);
      }
      if ((uVar4 & 0x8000) == 0) {
        *puVar1 = *puVar1 & 0xffff7fff;
      }
    }
    param_3 = DAT_0410c610;
    *(uint *)(DAT_0410c610 + 0x804) = *(uint *)(DAT_0410c610 + 0x804) | 0x400;
  }
  if (param_1 == 0) {
    return;
  }
LAB_0410c5de:
  FUN_0410c270(param_1,param_2,param_3,param_4);
  return;
}



// ===========================================================
// Function: FUN_0410c61c at 0410c61c
// ===========================================================

undefined4 FUN_0410c61c(int param_1,uint param_2,uint param_3,uint param_4,ushort param_5)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = (uint)param_5;
  if (param_1 == 0) {
    if (param_2 < 7) {
      iVar6 = DAT_0410c754 + param_2 * 0x20;
      if ((*(uint *)(iVar6 + 0xb00) & 0x80008000) != 0) {
        FUN_0410c540(param_2,0x8000000,0);
      }
      iVar4 = DAT_0410c754;
      *(uint *)(iVar6 + 0xb00) = DAT_0410c758 | param_4 & 0x7ff | (param_3 & 3) << 0x12;
      *(uint *)(iVar6 + 0xb00) = *(uint *)(iVar6 + 0xb00) & 0xffdfffff;
      *(uint *)(iVar4 + 0x81c) = 0x10000 << (param_2 & 0xff) | *(uint *)(iVar4 + 0x81c);
      return 0;
    }
    return 2;
  }
  if (5 < param_2) {
    return 3;
  }
  iVar6 = DAT_0410c754 + param_2 * 0x20;
  if ((*(uint *)(iVar6 + 0x900) & 0x80008000) != 0) {
    FUN_0410c2f0(param_2,0x8000000,0,*(uint *)(iVar6 + 0x900),param_4);
  }
  *(uint *)(iVar6 + 0x900) =
       DAT_0410c758 | (param_3 & 3) << 0x12 | param_4 & 0x7ff | param_2 << 0x16;
  puVar2 = DAT_0410c75c;
  if ((param_2 - 1 & 0xff) < 5) {
    if (uVar5 == 0) {
      uVar5 = ((int)(param_4 + 3) >> 2 & 0x1fffU) << 3;
    }
    if (uVar5 < param_4) {
                    /* WARNING: Subroutine does not return */
      FUN_04109484(DAT_0410c764,uVar5,param_4);
    }
    uVar1 = *DAT_0410c75c;
    uVar3 = (uint)uVar1;
    iVar4 = (int)(uVar5 + 3) >> 2;
    if (*(uint *)(DAT_0410c754 + 0x5c) >> 0x10 < uVar3 + iVar4) {
                    /* WARNING: Subroutine does not return */
      FUN_04109484(DAT_0410c760,uVar3,iVar4,*(uint *)(DAT_0410c754 + 0x5c) >> 0x10);
    }
    *(uint *)(DAT_0410c754 + (param_2 + 0x3f) * 4 + 4) = uVar3 | iVar4 << 0x10;
    *puVar2 = uVar1 + (short)((uVar5 + 3) * 0x4000 >> 0x10);
  }
  iVar4 = DAT_0410c754;
  *(uint *)(iVar6 + 0x900) = *(uint *)(iVar6 + 0x900) & 0xffdfffff;
  *(uint *)(iVar4 + 0x81c) = 1 << (param_2 & 0xff) | *(uint *)(iVar4 + 0x81c);
  return 0;
}



// ===========================================================
// Function: FUN_0410c768 at 0410c768
// ===========================================================

uint FUN_0410c768(int param_1,uint param_2)

{
  uint *puVar1;
  
  if (((param_1 == 0) && (6 < param_2)) || ((param_1 == 1 && (5 < param_2)))) {
    return 0;
  }
  if (param_2 == 0) {
    puVar1 = DAT_0410c7b0;
    if (param_1 != 0) {
      puVar1 = DAT_0410c7ac;
    }
    return (*puVar1 & 0x3fffff) >> 0x15;
  }
  if (param_1 == 0) {
    return (DAT_0410c7b0[param_2 * 8] & 0x3fffff) >> 0x15;
  }
  return (DAT_0410c7ac[param_2 * 8] & 0x3fffff) >> 0x15;
}



// ===========================================================
// Function: FUN_0410c7b4 at 0410c7b4
// ===========================================================

void FUN_0410c7b4(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_2 != 0) {
    if (param_1 == 0) {
      uVar3 = *(uint *)(DAT_0410c854 + (param_2 + 0x58) * 0x20);
    }
    else {
      uVar3 = *(uint *)(DAT_0410c854 + (param_2 + 0x48) * 0x20);
    }
    if (((uVar3 & 0xfffff) >> 0x12) - 2 < 2) {
      iVar1 = FUN_0410c768(param_1,param_2);
      if (iVar1 == 0) {
        if (param_1 == 0) {
          iVar1 = DAT_0410c854 + param_2 * 0x20;
          *(uint *)(iVar1 + 0xb00) = *(uint *)(iVar1 + 0xb00) | 0x10000000;
          return;
        }
        iVar1 = DAT_0410c854 + param_2 * 0x20;
        *(uint *)(iVar1 + 0x900) = *(uint *)(iVar1 + 0x900) | 0x10000000;
        return;
      }
      uVar2 = 0x18000000;
      goto joined_r0x0410c804;
    }
  }
  iVar1 = FUN_0410c768(param_1,param_2);
  if (iVar1 == 0) {
    return;
  }
  uVar2 = 0x8000000;
joined_r0x0410c804:
  if (param_1 == 0) {
    if (param_2 < 7) {
      FUN_0410c540(param_2,uVar2,0x200000,param_4);
      return;
    }
  }
  else if (param_2 < 6) {
    FUN_0410c2f0(param_2,uVar2,0x200000,param_4);
    return;
  }
  return;
}



// ===========================================================
// Function: FUN_0410c858 at 0410c858
// ===========================================================

void FUN_0410c858(int param_1,uint param_2)

{
  if (param_1 == 0) {
    if (param_2 < 7) {
      FUN_0410c540(param_2,0x8000000,0);
      return;
    }
  }
  else if (param_2 < 6) {
    FUN_0410c2f0(param_2,0x8000000,0);
    return;
  }
  return;
}



// ===========================================================
// Function: FUN_0410c880 at 0410c880
// ===========================================================

void FUN_0410c880(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0410c8c0;
  *(uint *)(DAT_0410c8c0 + 0x804) = *(uint *)(DAT_0410c8c0 + 0x804) | 0x80;
  iVar2 = DAT_0410c8c0;
  do {
  } while (-1 < *(int *)(iVar1 + 0x14) << 0x19);
  do {
  } while (-1 < *(int *)(DAT_0410c8c0 + 0x10));
  *(uint *)(DAT_0410c8c0 + 0x10) = (param_1 & 0x1f) << 6 | 0x20;
  do {
  } while (*(int *)(iVar2 + 0x10) << 0x1a < 0);
  *(uint *)(iVar2 + 0x804) = *(uint *)(iVar2 + 0x804) | 0x100;
  return;
}



// ===========================================================
// Function: FUN_0410c8c4 at 0410c8c4
// ===========================================================

void FUN_0410c8c4(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  char cVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  char *pcVar6;
  undefined1 *puVar7;
  uint *puVar8;
  ushort *puVar9;
  undefined2 *puVar10;
  int iVar11;
  ushort uVar12;
  undefined4 uVar13;
  uint *puVar14;
  uint uVar15;
  byte *pbVar16;
  char *pcVar17;
  undefined4 uVar18;
  ushort uVar19;
  uint uVar20;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  uint uVar21;
  uint *puVar22;
  int iVar23;
  code *pcVar24;
  uint uVar25;
  byte bVar26;
  int iVar27;
  uint uVar28;
  uint *puVar29;
  ushort *puVar30;
  undefined4 *puVar31;
  uint uVar32;
  uint uVar33;
  uint *puVar34;
  undefined4 *puVar35;
  byte *pbVar36;
  uint uVar37;
  int iVar38;
  undefined4 local_30;
  
  iVar5 = DAT_0410cbac;
  uVar21 = *(uint *)(DAT_0410cbac + 0x14);
  *(uint *)(DAT_0410cbac + 0x14) = uVar21;
  pcVar6 = DAT_0410ce84;
  uVar21 = *(uint *)(iVar5 + 0x18) & uVar21;
  if ((int)(uVar21 << 0x13) < 0) {
    if (*DAT_0410ce84 != '\0') {
      FUN_04108a3c(3,0xb);
    }
    iVar5 = DAT_0410ce8c;
    *DAT_0410ce88 = 2;
    puVar7 = DAT_0410ce90;
    *pcVar6 = '\0';
    uVar32 = 1;
    *puVar7 = 0;
    *(uint *)(iVar5 + 0xe00) = *(uint *)(iVar5 + 0xe00) & 0xfffffffe;
    *(uint *)(iVar5 + 0x804) = *(uint *)(iVar5 + 0x804) & 0xfffffffe;
    do {
      uVar37 = uVar32 & 0xff;
      uVar32 = uVar32 + 1;
      FUN_0410c270(uVar37);
      iVar5 = DAT_0410ce8c;
    } while (uVar32 != 7);
    FUN_0410c2b0(1);
    FUN_0410c2b0(2);
    FUN_0410c2b0(3);
    FUN_0410c2b0(4);
    FUN_0410c2b0(5);
    uVar32 = DAT_0410ce94;
    FUN_0410c3d8();
    iVar23 = 1;
    puVar29 = DAT_0410ce98;
    do {
      if (iVar23 == 1) {
        if ((*(uint *)(iVar5 + 0xb00) & 0x80008000) != 0) {
          *(uint *)(iVar5 + 0xb00) = *(uint *)(iVar5 + 0xb00) | uVar32;
        }
      }
      else {
        uVar37 = *puVar29;
        if ((uVar37 & 0x80008000) != 0) {
          *puVar29 = *puVar29 | uVar32;
          if ((int)uVar37 < 0) {
            puVar29[2] = 2;
            *puVar29 = *puVar29 | 0x40000000;
            do {
            } while (-1 < (int)(puVar29[2] << 0x1e));
          }
          if (-1 < (int)(uVar37 << 0x10)) {
            *puVar29 = *puVar29 & 0xffff7fff;
          }
        }
        iVar27 = DAT_0410ce8c;
        if (iVar23 == 7) goto LAB_0410cc9c;
      }
      iVar23 = iVar23 + 1;
      puVar29 = puVar29 + 8;
    } while( true );
  }
  uVar32 = uVar21 & 0x40000;
  uVar37 = uVar21 & DAT_0410cbe4;
  iVar5 = DAT_0410cbac;
  puVar35 = DAT_0410cbb0;
  iVar23 = DAT_0410cbd4;
  if (-1 < (int)(uVar21 << 0x12)) goto joined_r0x0410cb68;
LAB_0410cb22:
  uVar18 = DAT_0410cbd8;
  iVar5 = DAT_0410cbac;
  uVar13 = *(undefined4 *)(DAT_0410cbac + 0x808);
  *(undefined4 *)(DAT_0410cbac + 0x900) = DAT_0410cbd8;
  *(undefined4 *)(iVar5 + 0xb00) = uVar18;
  iVar23 = DAT_0410cbe0;
  DataMemoryBarrier(0x1f);
  *(undefined4 *)(iVar5 + 0xb10) = DAT_0410cbdc;
  uVar18 = FUN_04107478(iVar23,param_2,uVar13);
  *(undefined4 *)(iVar5 + 0xb14) = uVar18;
  *(undefined4 *)(iVar5 + 0xb08) = *(undefined4 *)(iVar5 + 0xb08);
  *(uint *)(iVar5 + 0xb00) = *(uint *)(iVar5 + 0xb00) | 0x80000000;
  *(uint *)(iVar5 + 0xb00) = *(uint *)(iVar5 + 0xb00) | 0x8000000;
  iVar5 = DAT_0410cbac;
  puVar35 = DAT_0410cbb0;
  iVar23 = DAT_0410cbd4;
joined_r0x0410cb68:
  DAT_0410cbac = iVar5;
  DAT_0410cbb0 = puVar35;
  DAT_0410cbd4 = iVar23;
  if (uVar32 != 0) {
    uVar33 = 0;
    uVar21 = *(uint *)(iVar5 + 0x818);
    uVar32 = *(uint *)(iVar5 + 0x81c);
    do {
      if ((1 << (uVar33 & 0xff) & uVar21 & uVar32) == 0) {
LAB_0410c924:
        if ((uVar33 & 0xff) == 5) break;
      }
      else {
        if (uVar33 != 0) {
          iVar27 = iVar5 + (uVar33 - 1) * 0x20;
          uVar20 = *(uint *)(iVar27 + 0x928);
          *(uint *)(iVar27 + 0x928) = uVar20;
          if (((*(uint *)(iVar5 + 0x810) & uVar20 & 9) == 0) ||
             (*(char *)((int)puVar35 + 0xb) == '\0')) goto LAB_0410c924;
          uVar28 = (*(uint *)(iVar27 + 0x930) & 0x1fffffff) >> 0x13;
          if (uVar28 == 0) {
            iVar38 = puVar35[1];
            if ((~uVar20 & 1) != 0) {
              local_30 = *puVar35;
              FUN_0410ef64(puVar35,0,0xc);
              goto LAB_0410ce60;
            }
            if (*(char *)((int)puVar35 + 10) != '\0') {
              *(undefined1 *)((int)puVar35 + 10) = 0;
              uVar18 = DAT_0410cea0;
              if ((*(uint *)(iVar27 + 0x920) & 0x40000) == 0) {
                uVar18 = 0x80000;
              }
              *(undefined4 *)(iVar27 + 0x930) = uVar18;
              *(uint *)(iVar27 + 0x920) = *(uint *)(iVar27 + 0x920) | 0x84000000;
              goto LAB_0410c924;
            }
            local_30 = *puVar35;
            FUN_0410ef64(puVar35,0,0xc);
            uVar18 = 0;
          }
          else {
            if (*(ushort *)(puVar35 + 2) < uVar28) {
                    /* WARNING: Subroutine does not return */
              FUN_04109484(DAT_0410d7fc);
            }
            local_30 = *puVar35;
            iVar38 = (*(uint *)(iVar5 + (uVar33 + 0x48) * 0x20) & 0x7ff) *
                     (*(ushort *)(puVar35 + 2) - uVar28);
            FUN_0410ef64(puVar35,0,0xc);
LAB_0410ce60:
            FUN_0410c2f0(uVar33 & 0xff,0x8000000,0);
            uVar18 = 1;
          }
          pcVar24 = *(code **)(iVar23 + uVar33 * 4 + 0x38);
          if (pcVar24 != (code *)0x0) {
            (*pcVar24)(local_30,iVar38,uVar18);
          }
          goto LAB_0410c924;
        }
        uVar20 = *(uint *)(iVar5 + 0x908);
        *(uint *)(iVar5 + 0x908) = uVar20;
        pbVar36 = DAT_0410cbb4;
        uVar28 = *(uint *)(iVar5 + 0x810) & uVar20;
        if ((uVar28 & 0x18) == 0) {
          if ((int)(uVar28 << 0x1f) < 0) {
            bVar26 = *DAT_0410cbb4;
            if (bVar26 == 2) {
                    /* WARNING: Subroutine does not return */
              FUN_04109484(DAT_0410d500);
            }
            if ((int)(uVar20 << 0x1f) < 0) {
              if (bVar26 == 4) {
                if ((*(uint *)(iVar5 + 0x910) & 0x180000) != 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_04109484(DAT_0410d7e4);
                }
                uVar20 = (uint)*(ushort *)(DAT_0410cbb4 + 8);
                uVar28 = (uint)*(ushort *)(DAT_0410cbb4 + 10);
                if (uVar20 < uVar28) {
                    /* WARNING: Subroutine does not return */
                  FUN_04109484(DAT_0410d7e0);
                }
                uVar15 = uVar20 - uVar28 & 0xffff;
                if (uVar15 == 0) {
                  *DAT_0410cbb4 = 5;
                }
                else {
                  if ((uVar15 == 0x40) && (uVar20 < *(ushort *)(DAT_0410cbb4 + 0x12))) {
                    bVar4 = true;
                  }
                  else {
                    bVar4 = false;
                    if (0x3f < uVar15) {
                      uVar15 = 0x40;
                    }
                  }
                  uVar25 = uVar28 + uVar15 & 0xffff;
                  *(short *)(DAT_0410cbb4 + 10) = (short)(uVar28 + uVar15);
                  uVar18 = DAT_0410d7d0;
                  if (uVar20 < uVar25) {
                    /* WARNING: Subroutine does not return */
                    FUN_04109484(DAT_0410d7dc);
                  }
                  uVar20 = uVar20 - uVar25 & 0xffff;
                  if (uVar20 < 0x41) {
                    if (uVar20 == 0) {
                      if (bVar4) {
                        DataMemoryBarrier(0x1f);
                        *(undefined4 *)(iVar5 + 0x910) = 0x80000;
                        uVar18 = FUN_04107478(uVar18);
                        *(undefined4 *)(iVar5 + 0x914) = uVar18;
                        *(undefined4 *)(iVar5 + 0x908) = *(undefined4 *)(iVar5 + 0x908);
                        *(uint *)(iVar5 + 0x900) = *(uint *)(iVar5 + 0x900) | 0x84000000;
                      }
                      else {
                        *pbVar36 = 5;
                        *(uint *)(iVar5 + 0x810) = *(uint *)(iVar5 + 0x810) | 0x10;
                      }
                      goto LAB_0410c928;
                    }
                  }
                  else {
                    uVar20 = 0x40;
                  }
                  FUN_0410c218(*(int *)(pbVar36 + 4) + uVar25,uVar20);
                }
              }
              else if (bVar26 == 6) {
                *DAT_0410cbb4 = 0;
                pbVar36 = DAT_0410d508;
                *(uint *)(iVar5 + 0x814) = *(uint *)(iVar5 + 0x814) & 0xffffffef;
                *(uint *)(iVar5 + 0x810) = *(uint *)(iVar5 + 0x810) & 0xffffffef;
                uVar20 = (uint)*pbVar36;
                if (uVar20 != 0) {
                  *(uint *)(iVar5 + 0x804) =
                       (uVar20 & 7) << 4 | *(uint *)(iVar5 + 0x804) & 0xffffff8f;
                  *pbVar36 = 0;
                }
              }
              else {
                FUN_04109118(0xc2,DAT_0410cbb8,bVar26,*(undefined4 *)(iVar5 + 0x910));
              }
            }
          }
        }
        else {
          *(uint *)(iVar5 + 0x810) = *(uint *)(iVar5 + 0x810) & 0xffffffef;
          FUN_0410c2f0(0,0x200000,0);
        }
      }
LAB_0410c928:
      uVar33 = uVar33 + 1;
      puVar35 = puVar35 + 3;
    } while( true );
  }
  iVar5 = DAT_0410cbe0;
  uVar18 = DAT_0410cbdc;
  if ((uVar37 & 0x80000) != 0) {
    uVar37 = *(uint *)(DAT_0410cbac + 0x818);
    uVar21 = *(uint *)(DAT_0410cbac + 0x81c);
    puVar35 = DAT_0410cbbc;
    for (uVar32 = 0; iVar23 = DAT_0410cbac, (0x10000 << (uVar32 & 0xff) & uVar37 & uVar21) != 0;
        uVar32 = uVar32 + 1) {
      if (uVar32 != 0) {
        iVar27 = DAT_0410cbac + (uVar32 - 1) * 0x20;
        uVar33 = *(uint *)(iVar27 + 0xb28);
        *(uint *)(iVar27 + 0xb28) = uVar33;
        if (((int)((*(uint *)(iVar23 + 0x814) & uVar33) << 0x1f) < 0) &&
           (*(char *)(puVar35 + 2) != '\0')) {
          uVar13 = *puVar35;
          uVar20 = puVar35[1];
          uVar33 = *(uint *)(iVar27 + 0xb30) & 0x7ffff;
          if (uVar20 < uVar33) {
                    /* WARNING: Subroutine does not return */
            FUN_04109484(DAT_0410d800,uVar33,uVar20);
          }
          FUN_0410ef64(puVar35,0,0xc);
          pcVar24 = *(code **)(DAT_0410cbd4 + uVar32 * 4 + 0x20);
          if (pcVar24 != (code *)0x0) {
            (*pcVar24)(uVar13,uVar20 - uVar33,0);
          }
        }
        break;
      }
      uVar33 = *(uint *)(DAT_0410cbac + 0xb08);
      *(uint *)(DAT_0410cbac + 0xb08) = uVar33;
      iVar11 = DAT_0410d7c4;
      iVar38 = DAT_0410d4f4;
      pbVar36 = DAT_0410cbb4;
      iVar27 = DAT_0410cbac;
      uVar20 = *(uint *)(iVar23 + 0x814) & uVar33;
      if ((uVar20 & 0x38) == 0x10) {
        *(uint *)(iVar23 + 0x814) = *(uint *)(iVar23 + 0x814) & 0xffffffef;
        if ((*(uint *)(iVar23 + 0xb00) & 0x80008000) != 0) {
          FUN_0410c3d8();
          *(uint *)(iVar23 + 0xb00) = DAT_0410cea4 | *(uint *)(iVar23 + 0xb00);
          *(uint *)(iVar23 + 0x804) = *(uint *)(iVar23 + 0x804) | 0x400;
        }
        if ((uVar20 & 1) == 0) goto LAB_0410c9c6;
        DataMemoryBarrier(0x1f);
        iVar23 = DAT_0410ce8c;
LAB_0410cdcc:
        *(undefined4 *)(iVar23 + 0xb10) = uVar18;
        goto LAB_0410cdd2;
      }
      if ((uVar20 & 0x29) == 0) goto LAB_0410c9c6;
      if (((uVar33 & 0x21) == 0x21) && ((DAT_0410d184 & *(uint *)(iVar23 + 0xb10)) == DAT_0410d188))
      {
        uVar33 = uVar33 & 0xfffffffe;
        DataMemoryBarrier(0x1f);
        *(undefined4 *)(iVar23 + 0xb10) = uVar18;
        uVar13 = FUN_04107478(iVar5);
        *(undefined4 *)(iVar23 + 0xb14) = uVar13;
        *(undefined4 *)(iVar23 + 0xb08) = *(undefined4 *)(iVar23 + 0xb08);
        *(uint *)(iVar23 + 0xb00) = *(uint *)(iVar23 + 0xb00) | 0x80000000;
        *(uint *)(iVar23 + 0xb00) = *(uint *)(iVar23 + 0xb00) | 0x8000000;
LAB_0410cef2:
        iVar23 = DAT_0410d4f4;
        pbVar36 = DAT_0410d18c;
        if ((uVar33 & 8) == 0) {
          if (*DAT_0410d18c == 2) goto LAB_0410cf06;
LAB_0410cfda:
          if ((uVar33 & 0x20) != 0) {
            if (*pbVar36 == 6) {
LAB_0410d412:
              iVar23 = DAT_0410d4f4;
              *(uint *)(DAT_0410d4f4 + 0x814) = *(uint *)(DAT_0410d4f4 + 0x814) & 0xffffffef;
              uVar13 = DAT_0410d4ec;
              DataMemoryBarrier(0x1f);
              *(undefined4 *)(iVar23 + 0x910) = 0x80000;
              uVar13 = FUN_04107478(uVar13);
              *(undefined4 *)(iVar23 + 0x914) = uVar13;
              *(undefined4 *)(iVar23 + 0x908) = *(undefined4 *)(iVar23 + 0x908);
              *(uint *)(iVar23 + 0x900) = *(uint *)(iVar23 + 0x900) | 0x84000000;
            }
            else {
              FUN_04109118(0xc1,DAT_0410d198);
              FUN_0410c2f0(0,0x200000);
            }
          }
        }
        else {
          if (*DAT_0410d18c == 1) goto LAB_0410cf02;
          FUN_04109118(0xc1,DAT_0410d504);
          if ((-1 < *(int *)(iVar23 + 0xb00)) && (-1 < *(int *)(iVar23 + 0xb08) << 0x1f)) {
            DataMemoryBarrier(0x1f);
            goto LAB_0410cdcc;
          }
        }
        goto LAB_0410c9c6;
      }
      if ((uVar33 & 1) == 0) goto LAB_0410cef2;
      bVar26 = *DAT_0410cbb4;
      if ((uVar33 & 8) == 0) {
        if ((uVar33 & 0x8000) != 0) {
          if (bVar26 != 0) {
            FUN_04109118(0xc1,DAT_0410d7c0);
            iVar23 = DAT_0410d7c4;
            *pbVar36 = 0;
            *(uint *)(iVar23 + 0x814) = *(uint *)(iVar23 + 0x814) & 0xffffffef;
            *(uint *)(iVar23 + 0x810) = *(uint *)(iVar23 + 0x810) & 0xffffffef;
            FUN_0410c2f0(0,0x8000000,0);
          }
          *pbVar36 = 1;
          goto LAB_0410c9c6;
        }
        if (bVar26 != 2) {
          if (bVar26 != 3) {
            if (bVar26 == 5) {
              *DAT_0410cbb4 = 0;
              *(uint *)(iVar38 + 0x814) = *(uint *)(iVar38 + 0x814) & 0xffffffef;
              *(uint *)(iVar38 + 0x810) = *(uint *)(iVar38 + 0x810) & 0xffffffef;
            }
            else {
              FUN_04109118(0xc2,DAT_0410cbc0,bVar26,*(undefined4 *)(DAT_0410cbac + 0xb10));
              iVar38 = iVar27;
            }
            DataMemoryBarrier(0x1f);
            *(undefined4 *)(iVar38 + 0xb10) = uVar18;
            uVar13 = FUN_04107478(iVar5);
            *(undefined4 *)(iVar38 + 0xb14) = uVar13;
            *(undefined4 *)(iVar38 + 0xb08) = *(undefined4 *)(iVar38 + 0xb08);
            *(uint *)(iVar38 + 0xb00) = *(uint *)(iVar38 + 0xb00) | 0x80000000;
            *(uint *)(iVar38 + 0xb00) = *(uint *)(iVar38 + 0xb00) | 0x8000000;
            goto LAB_0410cfda;
          }
          uVar20 = *(uint *)(DAT_0410d7c4 + 0xb10) & 0x7f;
          if (0x40 < uVar20) {
                    /* WARNING: Subroutine does not return */
            FUN_04109484(DAT_0410d7ec);
          }
          uVar15 = (uint)*(ushort *)(DAT_0410cbb4 + 10);
          uVar20 = 0x40 - uVar20;
          uVar25 = (uint)*(ushort *)(DAT_0410cbb4 + 8);
          uVar28 = uVar25 - uVar15 & 0xffff;
          if ((int)uVar20 <= (int)uVar28) {
            uVar28 = uVar20;
          }
          if ((int)uVar25 < (int)(uVar28 + uVar15)) {
                    /* WARNING: Subroutine does not return */
            FUN_04109484(DAT_0410d7e8,uVar25,uVar15,uVar28);
          }
          FUN_0410ef70(uVar15 + *(int *)(DAT_0410cbb4 + 4),iVar5);
          uVar20 = (uVar28 & 0xffff) + (uint)*(ushort *)(pbVar36 + 10);
          *(short *)(pbVar36 + 10) = (short)uVar20;
          if ((uint)*(ushort *)(pbVar36 + 8) != (uVar20 & 0xffff)) {
            DataMemoryBarrier(0x1f);
            *(undefined4 *)(iVar11 + 0xb10) = uVar18;
            uVar13 = FUN_04107478(iVar5);
            *(undefined4 *)(iVar11 + 0xb14) = uVar13;
            *(undefined4 *)(iVar11 + 0xb08) = *(undefined4 *)(iVar11 + 0xb08);
            *(uint *)(iVar11 + 0xb00) = *(uint *)(iVar11 + 0xb00) | 0x80000000;
            *(uint *)(iVar11 + 0xb00) = *(uint *)(iVar11 + 0xb00) | 0x4000000;
            goto LAB_0410cfda;
          }
          DataMemoryBarrier(0x1f);
          *(undefined4 *)(iVar11 + 0xb10) = uVar18;
          uVar13 = FUN_04107478(iVar5);
          *(undefined4 *)(iVar11 + 0xb14) = uVar13;
          *(undefined4 *)(iVar11 + 0xb08) = *(undefined4 *)(iVar11 + 0xb08);
          *(uint *)(iVar11 + 0xb00) = *(uint *)(iVar11 + 0xb00) | 0x80000000;
          pcVar24 = *(code **)(DAT_0410d4e8 + 0x10);
          *(uint *)(iVar11 + 0xb00) = *(uint *)(iVar11 + 0xb00) | 0x8000000;
          if (pcVar24 != (code *)0x0) {
            (*pcVar24)(pbVar36);
          }
          iVar23 = DAT_0410d4f4;
          *pbVar36 = 6;
          *(uint *)(iVar23 + 0x814) = *(uint *)(iVar23 + 0x814) | 0x10;
          if ((uVar33 & 0x20) == 0) goto LAB_0410c9c6;
          goto LAB_0410d412;
        }
      }
      else {
        if (bVar26 != 0) {
          FUN_04109118(0xc1,DAT_0410d19c);
          iVar23 = DAT_0410d190;
          *pbVar36 = 0;
          *(uint *)(iVar23 + 0x814) = *(uint *)(iVar23 + 0x814) & 0xffffffef;
          *(uint *)(iVar23 + 0x810) = *(uint *)(iVar23 + 0x810) & 0xffffffef;
          FUN_0410c2f0(0,0x8000000);
        }
LAB_0410cf02:
        *pbVar36 = 2;
      }
LAB_0410cf06:
      iVar23 = DAT_0410d190;
      *(uint *)(DAT_0410d190 + 0x814) = *(uint *)(DAT_0410d190 + 0x814) & 0xffffffef;
      *(uint *)(iVar23 + 0x810) = *(uint *)(iVar23 + 0x810) & 0xffffffef;
      uVar33 = *(uint *)(iVar23 + 0xb10) & 0x7f;
      if (uVar33 != 0x38) {
        if (uVar33 == 0x30) {
          iVar23 = 8;
          goto LAB_0410cf3c;
        }
        if (uVar33 == 0x28) {
          iVar23 = 0x10;
          goto LAB_0410cf3c;
        }
        FUN_04109118(0xc1,DAT_0410d7bc);
        goto LAB_0410d046;
      }
      iVar23 = 0;
LAB_0410cf3c:
      bVar26 = *(byte *)(iVar5 + iVar23);
      iVar23 = iVar23 + iVar5;
      pbVar36[4] = 0;
      pbVar36[5] = 0;
      pbVar36[6] = 0;
      pbVar36[7] = 0;
      pbVar36[8] = 0;
      pbVar36[9] = 0;
      pbVar36[10] = 0;
      pbVar36[0xb] = 0;
      pbVar36[0xc] = bVar26 & 0x80 | (byte)(((int)(uint)bVar26 >> 5 & 3U) << 5) | bVar26 & 0x1f;
      *pbVar36 = 2;
      pbVar36[0xd] = *(byte *)(iVar23 + 1);
      *(undefined2 *)(pbVar36 + 0xe) = *(undefined2 *)(iVar23 + 2);
      *(undefined2 *)(pbVar36 + 0x10) = *(undefined2 *)(iVar23 + 4);
      sVar1 = *(short *)(iVar23 + 6);
      *(short *)(pbVar36 + 0x12) = sVar1;
      if ((sVar1 == 0) && ((char)pbVar36[0xc] < '\0')) {
        FUN_04109118(0xc0,DAT_0410d7c8);
        goto LAB_0410d046;
      }
      if (((code *)DAT_0410d194[3] != (code *)0x0) &&
         (iVar23 = (*(code *)DAT_0410d194[3])(DAT_0410d18c), iVar23 != 0)) goto LAB_0410d16a;
      puVar30 = DAT_0410d7d8;
      puVar10 = DAT_0410d4f8;
      pcVar6 = DAT_0410d1b4;
      puVar9 = DAT_0410d1ac;
      puVar31 = DAT_0410d194;
      cVar2 = *DAT_0410d1b4;
      if ((pbVar36[0xc] & 0x60) != 0) goto switchD_0410cfaa_caseD_2;
      switch(pbVar36[0xd]) {
      case 0:
        if ((*DAT_0410d1b4 != '\x04') && (*(short *)(pbVar36 + 0x10) != 0)) break;
        bVar26 = pbVar36[0xc] & 0x1f;
        if (bVar26 == 1) {
          *DAT_0410d7d8 = 0;
        }
        else if (bVar26 == 2) {
          iVar23 = FUN_0410c768((*(ushort *)(pbVar36 + 0x10) & 0xff) >> 7,
                                *(ushort *)(pbVar36 + 0x10) & 0xf);
          puVar30 = DAT_0410d7d8;
          if (iVar23 == 0) {
            *DAT_0410d7d8 = 0;
          }
          else {
            *DAT_0410d7d8 = 1;
          }
        }
        else {
          if ((pbVar36[0xc] & 0x1f) != 0) break;
          *DAT_0410d1ac = (ushort)*DAT_0410d1a8;
          puVar30 = puVar9;
        }
        *(ushort **)(pbVar36 + 4) = puVar30;
        pbVar36[8] = 2;
        pbVar36[9] = 0;
        *pbVar36 = 4;
        goto LAB_0410d0ce;
      case 1:
        if ((*DAT_0410d1b4 == '\x04') || (*(short *)(pbVar36 + 0x10) == 0)) {
          if (((pbVar36[0xc] & 0x1f) != 2) || (*(short *)(pbVar36 + 0xe) != 0)) goto LAB_0410d118;
          FUN_0410c7b4((*(ushort *)(pbVar36 + 0x10) & 0xff) >> 7,*(ushort *)(pbVar36 + 0x10) & 0xf);
          pcVar24 = *(code **)(DAT_0410d4e8 + 0x20);
          if (pcVar24 != (code *)0x0) {
            bVar26 = pbVar36[0x10];
            uVar13 = 6;
LAB_0410d1f0:
            (*pcVar24)(uVar13,bVar26);
          }
          goto LAB_0410d1f2;
        }
        break;
      case 3:
        if ((*DAT_0410d1b4 != '\x04') && (*(short *)(pbVar36 + 0x10) != 0)) break;
        if ((pbVar36[0xc] & 0x1f) != 0) {
          if (((pbVar36[0xc] & 0x1f) == 2) && (*(short *)(pbVar36 + 0xe) == 0)) {
            uVar12 = *(ushort *)(pbVar36 + 0x10) & 0xf;
            if ((*(ushort *)(pbVar36 + 0x10) & 0x80) == 0) {
              if (uVar12 < 7) {
                FUN_0410c540(uVar12,0x200000);
                puVar31 = DAT_0410d7f0;
              }
            }
            else if (uVar12 < 6) {
              FUN_0410c2f0(uVar12,0x200000,0);
              puVar31 = DAT_0410d7f0;
            }
            pcVar24 = (code *)puVar31[8];
            if (pcVar24 != (code *)0x0) {
              bVar26 = pbVar36[0x10];
              uVar13 = 5;
              goto LAB_0410d1f0;
            }
            goto LAB_0410d1f2;
          }
LAB_0410d118:
          *pbVar36 = 6;
          if (cVar2 != '\x04') goto LAB_0410d046;
          goto LAB_0410d122;
        }
        if (*(short *)(pbVar36 + 0xe) != 2) goto LAB_0410d118;
        *DAT_0410d7d4 = (char)((ushort)*(undefined2 *)(pbVar36 + 0x10) >> 8);
LAB_0410d1f2:
        *pbVar36 = 6;
        if ((cVar2 != '\x04') || (*pcVar6 == '\x04')) goto LAB_0410d1fe;
        goto LAB_0410d282;
      case 5:
        uVar12 = *(ushort *)(pbVar36 + 0xe);
        *(uint *)(DAT_0410d4f4 + 0x800) =
             (uVar12 & 0x7f) << 4 | *(uint *)(DAT_0410d4f4 + 0x800) & 0xfffff80f;
        *pbVar36 = 6;
        if (uVar12 == 0) {
          *pcVar6 = '\x02';
        }
        else {
LAB_0410d650:
          *pcVar6 = '\x03';
        }
LAB_0410d316:
        if (cVar2 == '\x04') goto LAB_0410d278;
        goto LAB_0410d1fe;
      case 6:
        uVar12 = *(ushort *)(pbVar36 + 0xe);
        switch(uVar12 >> 8) {
        case 1:
          pcVar17 = (char *)(*(code *)*DAT_0410d194)(1);
          if (((pcVar17 != (char *)0x0) && (*pcVar17 == '\x12')) && (pcVar17[1] == '\x01')) {
            pbVar36[8] = 0x12;
            pbVar36[9] = 0;
            *(char **)(pbVar36 + 4) = pcVar17;
            goto LAB_0410d290;
          }
          break;
        case 2:
          pcVar17 = (char *)(*(code *)DAT_0410d194[1])();
          pbVar16 = DAT_0410d7cc;
          if (((pcVar17 != (char *)0x0) && (*pcVar17 == '\t')) && (pcVar17[1] == '\x02')) {
            *(undefined2 *)(pbVar36 + 8) = *(undefined2 *)(pcVar17 + 2);
            *(char **)(pbVar36 + 4) = pcVar17;
            bVar26 = *pbVar16;
            if ((pcVar17[7] & 0x40U) == 0) {
              bVar26 = bVar26 & 0xfe;
            }
            else {
              bVar26 = bVar26 | 1;
            }
            *pbVar16 = bVar26;
            goto LAB_0410d290;
          }
          break;
        case 3:
          pbVar16 = (byte *)(*(code *)DAT_0410d194[2])((char)uVar12);
          *(byte **)(pbVar36 + 4) = pbVar16;
          if (pbVar16 != (byte *)0x0) {
            *(ushort *)(pbVar36 + 8) = (ushort)*pbVar16;
            goto LAB_0410d290;
          }
          break;
        case 4:
        case 5:
        case 6:
        case 0xf:
          break;
        default:
          FUN_04109118(0xc1,DAT_0410d1a0,uVar12 >> 8);
        }
        break;
      case 8:
        *(byte **)(pbVar36 + 4) = DAT_0410d4f0;
        pbVar36[8] = 1;
        pbVar36[9] = 0;
LAB_0410d290:
        *pbVar36 = 4;
        goto LAB_0410d0ce;
      case 9:
        bVar26 = pbVar36[0xe];
        cVar3 = *DAT_0410d1b4;
        *DAT_0410d4f0 = bVar26;
        if ((*pcVar6 == '\x03') || (*pcVar6 == '\x04')) {
          *pbVar36 = 6;
          if (bVar26 == 0) goto LAB_0410d650;
          pcVar24 = (code *)puVar31[5];
          *pcVar6 = '\x04';
          if ((pcVar24 == (code *)0x0) || (iVar23 = (*pcVar24)(), iVar23 == 0)) {
            *pcVar6 = cVar3;
            break;
          }
          if (cVar2 != '\x04') goto LAB_0410d16a;
          goto LAB_0410d278;
        }
        break;
      case 10:
        if (*DAT_0410d1b4 != '\x04') break;
        *pbVar36 = 4;
        *(undefined2 *)(pbVar36 + 0x10) = *puVar10;
        *(undefined1 **)(pbVar36 + 4) = DAT_0410d4fc;
        pbVar36[8] = 1;
        pbVar36[9] = 0;
LAB_0410d0ce:
        if (cVar2 == '\x04') {
LAB_0410d278:
          if (*pcVar6 != '\x04') {
LAB_0410d282:
            bVar4 = true;
            goto LAB_0410d12e;
          }
          goto LAB_0410d16a;
        }
        goto LAB_0410d0d6;
      case 0xb:
        if (((code *)DAT_0410d194[6] != (code *)0x0) &&
           (iVar23 = (*(code *)DAT_0410d194[6])
                               (*(undefined2 *)(pbVar36 + 0x10),*(undefined2 *)(pbVar36 + 0xe)),
           iVar23 != 0)) {
          *DAT_0410d4f8 = *(undefined2 *)(pbVar36 + 0x10);
          *DAT_0410d4fc = (char)*(undefined2 *)(pbVar36 + 0xe);
          *pbVar36 = 6;
          goto LAB_0410d316;
        }
      }
switchD_0410cfaa_caseD_2:
      if (cVar2 == '\x04') {
LAB_0410d122:
        if (*pcVar6 == '\x04') goto LAB_0410d046;
        bVar4 = false;
LAB_0410d12e:
        uVar33 = 1;
        do {
          uVar20 = uVar33 & 0xff;
          uVar33 = uVar33 + 1;
          FUN_0410c270(uVar20);
        } while (uVar33 != 7);
        FUN_0410c2b0(1);
        FUN_0410c2b0(2);
        FUN_0410c2b0(3);
        FUN_0410c2b0(4);
        FUN_0410c2b0(5);
        if (!bVar4) goto LAB_0410d046;
LAB_0410d16a:
        bVar26 = *pbVar36;
        if (bVar26 != 3) {
          if (bVar26 == 4) {
LAB_0410d0d6:
            uVar12 = *(ushort *)(pbVar36 + 0x12);
            uVar19 = *(ushort *)(pbVar36 + 8);
            if (uVar12 < *(ushort *)(pbVar36 + 8)) {
              *(ushort *)(pbVar36 + 8) = uVar12;
              uVar19 = uVar12;
            }
            if (0x3f < uVar19) {
              uVar19 = 0x40;
            }
            FUN_0410c218(*(undefined4 *)(pbVar36 + 4),uVar19);
          }
          else {
            if (bVar26 != 6) {
              FUN_04109118(0xc1,DAT_0410d1b0);
              goto LAB_0410d046;
            }
LAB_0410d1fe:
            iVar23 = DAT_0410d4f4;
            uVar13 = DAT_0410d4ec;
            DataMemoryBarrier(0x1f);
            *(undefined4 *)(DAT_0410d4f4 + 0x910) = 0x80000;
            uVar13 = FUN_04107478(uVar13);
            *(undefined4 *)(iVar23 + 0x914) = uVar13;
            *(undefined4 *)(iVar23 + 0x908) = *(undefined4 *)(iVar23 + 0x908);
            *(uint *)(iVar23 + 0x900) = *(uint *)(iVar23 + 0x900) | 0x84000000;
          }
          goto LAB_0410d080;
        }
        if (*(int *)(pbVar36 + 4) == 0) {
          *(int *)(pbVar36 + 4) = iVar5;
        }
LAB_0410d384:
        iVar23 = DAT_0410d4f4;
        DataMemoryBarrier(0x1f);
        *(undefined4 *)(DAT_0410d4f4 + 0xb10) = uVar18;
        uVar13 = FUN_04107478(iVar5);
        *(undefined4 *)(iVar23 + 0xb14) = uVar13;
        *(undefined4 *)(iVar23 + 0xb08) = *(undefined4 *)(iVar23 + 0xb08);
        *(uint *)(iVar23 + 0xb00) = *(uint *)(iVar23 + 0xb00) | 0x80000000;
        *(uint *)(iVar23 + 0xb00) = *(uint *)(iVar23 + 0xb00) | 0x4000000;
      }
      else {
LAB_0410d046:
        iVar23 = DAT_0410d190;
        *pbVar36 = 0;
        if ((*(uint *)(iVar23 + 0xb00) & 0x80008000) != 0) {
          FUN_0410c3d8();
          *(uint *)(iVar23 + 0xb00) = DAT_0410d1a4 | *(uint *)(iVar23 + 0xb00);
          *(uint *)(iVar23 + 0x804) = *(uint *)(iVar23 + 0x804) | 0x400;
        }
        FUN_0410c2f0(0,0x200000);
LAB_0410d080:
        iVar23 = DAT_0410d190;
        if (*pbVar36 - 3 < 2) goto LAB_0410d384;
        DataMemoryBarrier(0x1f);
        *(undefined4 *)(DAT_0410d190 + 0xb10) = uVar18;
LAB_0410cdd2:
        uVar13 = FUN_04107478(iVar5);
        *(undefined4 *)(iVar23 + 0xb14) = uVar13;
        *(undefined4 *)(iVar23 + 0xb08) = *(undefined4 *)(iVar23 + 0xb08);
        *(uint *)(iVar23 + 0xb00) = *(uint *)(iVar23 + 0xb00) | 0x80000000;
        *(uint *)(iVar23 + 0xb00) = *(uint *)(iVar23 + 0xb00) | 0x8000000;
      }
LAB_0410c9c6:
      puVar35 = puVar35 + 3;
    }
    if ((uVar32 & 0xff) != 6) goto LAB_0410c9c6;
  }
  return;
LAB_0410cc9c:
  *(uint *)(DAT_0410ce8c + 0x804) = *(uint *)(DAT_0410ce8c + 0x804) | 0x400;
  *(uint *)(iVar27 + 0x804) = *(uint *)(iVar27 + 0x804) | 0x80;
  puVar8 = DAT_0410cea8;
  puVar29 = DAT_0410ce9c;
  uVar32 = DAT_0410ce94;
  iVar5 = DAT_0410ce8c;
  do {
  } while (-1 < *(int *)(iVar27 + 0x14) << 0x19);
  iVar23 = 1;
  puVar22 = DAT_0410ce9c;
  do {
    if (iVar23 == 1) {
      uVar37 = *(uint *)(iVar5 + 0x900);
      puVar14 = puVar8;
      puVar34 = puVar29;
      if ((uVar37 & 0x80008000) != 0) {
LAB_0410cce4:
        *puVar14 = 0x40;
        *puVar34 = *puVar34 | uVar32;
        if ((int)uVar37 < 0) {
          if (-1 < (int)(uVar37 << 0xe)) {
            do {
            } while (-1 < (int)(*puVar14 << 0x19));
            *puVar14 = 0x40;
          }
          *puVar14 = 2;
          *puVar34 = *puVar34 | 0x40000000;
          do {
          } while (-1 < (int)(*puVar14 << 0x1e));
        }
        if (-1 < (int)(uVar37 << 0x10)) {
          *puVar34 = *puVar34 & 0xffff7fff;
        }
        goto LAB_0410ccfe;
      }
    }
    else {
      uVar37 = *puVar22;
      if ((uVar37 & 0x80008000) != 0) {
        puVar14 = puVar22 + 2;
        puVar34 = puVar22;
        goto LAB_0410cce4;
      }
LAB_0410ccfe:
      iVar27 = DAT_0410cbac;
      if (iVar23 == 6) break;
    }
    iVar23 = iVar23 + 1;
    puVar22 = puVar22 + 8;
  } while( true );
  *(undefined4 *)(DAT_0410cbac + 0x10) = 0x430;
  do {
  } while ((*(uint *)(iVar27 + 0x10) & 0x30) != 0);
  *(uint *)(iVar27 + 0x804) = *(uint *)(iVar27 + 0x804) | 0x100;
  *(undefined4 *)(iVar27 + 0x81c) = 0x10001;
  *(undefined4 *)(iVar27 + 0x814) = 0x29;
  *(undefined4 *)(iVar27 + 0x810) = 9;
  *(uint *)(iVar27 + 0x18) = *(uint *)(iVar27 + 0x18) | 0xc0000;
  uVar18 = DAT_0410cbc4;
  if (*(int *)(iVar27 + 0x48) << 0xc < 0) {
    uVar32 = *(uint *)(iVar27 + 0x5c) & 0xffff;
    if (uVar32 != 0x400) {
                    /* WARNING: Subroutine does not return */
      FUN_04109484(DAT_0410d7f8,uVar32,0x400);
    }
    if (*(uint *)(iVar27 + 0x5c) >> 0x10 < 0x5c) {
                    /* WARNING: Subroutine does not return */
      FUN_04109484(DAT_0410d7f4,0x3b,0x21);
    }
    *(undefined4 *)(iVar27 + 0x24) = 0x3b;
    *(undefined4 *)(iVar27 + 0x28) = uVar18;
    *DAT_0410cbc8 = 0x5c;
    FUN_0410c880(0x10);
  }
  uVar18 = DAT_0410cbcc;
  pbVar36 = DAT_0410cbb4;
  iVar5 = DAT_0410cbac;
  uVar32 = *(uint *)(DAT_0410cbac + 0x800);
  pbVar36[4] = 0;
  pbVar36[5] = 0;
  pbVar36[6] = 0;
  pbVar36[7] = 0;
  pbVar36[8] = 0;
  pbVar36[9] = 0;
  pbVar36[10] = 0;
  pbVar36[0xb] = 0;
  *(uint *)(iVar5 + 0x800) = uVar32 & 0xfffff80f;
  *pbVar36 = 0;
  FUN_0410ef64(uVar18,0,0x48);
  FUN_0410ef64(DAT_0410cbd0,0,0x3c);
  param_2 = extraout_r1;
  if (*(code **)(DAT_0410cbd4 + 0x20) != (code *)0x0) {
    (**(code **)(DAT_0410cbd4 + 0x20))(0,0);
    param_2 = extraout_r1_00;
  }
  uVar37 = uVar21 & 0x2000;
  uVar32 = 0;
  if (uVar37 == 0) {
    return;
  }
  goto LAB_0410cb22;
}



// ===========================================================
// Function: FUN_0410d804 at 0410d804
// ===========================================================

undefined4 FUN_0410d804(int *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if ((((*param_1 != 0) && (param_1[1] != 0)) && (param_1[2] != 0)) && (param_1[5] != 0)) {
    FUN_04108a3c(3,0xb,param_3,param_1[5],param_4);
    FUN_0410ef70(DAT_0410d8b0,param_1,0x50);
    *DAT_0410d8b4 = 4;
    puVar1 = DAT_0410d8bc;
    *DAT_0410d8b8 = param_2;
    puVar2 = DAT_0410d8c0;
    *puVar1 = (char)param_3;
    *puVar2 = (short)param_4;
    uVar6 = DAT_0410d8cc;
    iVar3 = DAT_0410d8c4;
    DataMemoryBarrier(0x1f);
    *(undefined4 *)(DAT_0410d8c4 + 0xb10) = DAT_0410d8c8;
    uVar6 = FUN_04107478(uVar6);
    *(undefined4 *)(iVar3 + 0xb14) = uVar6;
    iVar4 = DAT_0410d8d0;
    *(undefined4 *)(iVar3 + 0xb08) = *(undefined4 *)(iVar3 + 0xb08);
    uVar6 = DAT_0410d8d4;
    *(uint *)(iVar3 + 0xb00) = *(uint *)(iVar3 + 0xb00) | 0x80000000;
    *(uint *)(iVar3 + 0xb00) = *(uint *)(iVar3 + 0xb00) | 0x8000000;
    *(undefined4 *)(*(int *)(iVar4 + 8) + 0x84) = uVar6;
    puVar5 = DAT_0410d8d8;
    DataSynchronizationBarrier(0xf);
    *(undefined1 *)((int)DAT_0410d8d8 + 0x311) = 0xa0;
    puVar5[0x60] = 0x20000;
    *puVar5 = 0x20000;
    return 0;
  }
  return 2;
}



// ===========================================================
// Function: FUN_0410d8dc at 0410d8dc
// ===========================================================

undefined4 FUN_0410d8dc(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = FUN_0410c61c();
    return uVar1;
  }
  return 1;
}



// ===========================================================
// Function: FUN_0410d8f4 at 0410d8f4
// ===========================================================

undefined4 FUN_0410d8f4(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  iVar1 = DAT_0410d9e0;
  if (*DAT_0410d9dc != '\x04') {
    return 1;
  }
  uVar3 = 4;
  uVar8 = param_1 - 1;
  if (5 < (uVar8 & 0xff)) {
    return 2;
  }
  if ((param_2 & 3) == 0) {
    iVar6 = DAT_0410d9e0 + uVar8 * 0xc;
    if (*(int *)(DAT_0410d9e0 + uVar8 * 0xc) == 0) {
      iVar5 = DAT_0410d9e4 + param_1 * 0x20;
      if (*(int *)(iVar5 + 0xb00) << 0x10 < 0) {
        uVar4 = (*(uint *)(iVar5 + 0xb00) & 0x7ff) + 3;
        uVar2 = uVar4 & 0xfffc;
        if (param_3 < (uVar4 & 0xfffffffc)) {
          uVar3 = 6;
        }
        else if (param_3 < 0x80000) {
          uVar4 = param_3 / uVar2;
          if (uVar4 < 0x400) {
            if (param_3 == uVar4 * uVar2) {
              iVar7 = DAT_0410d9e4 + uVar8 * 0x20;
              *(uint *)(iVar7 + 0xb30) = param_3 | uVar4 << 0x13;
              uVar3 = FUN_04107478(param_2);
              *(undefined4 *)(iVar7 + 0xb34) = uVar3;
              *(undefined4 *)(iVar7 + 0xb28) = *(undefined4 *)(iVar7 + 0xb28);
              *(uint *)(iVar1 + uVar8 * 0xc) = param_2;
              *(uint *)(iVar6 + 4) = param_3;
              *(undefined1 *)(iVar6 + 8) = 1;
              DataMemoryBarrier(0x1f);
              *(uint *)(iVar5 + 0xb00) = *(uint *)(iVar5 + 0xb00) | 0x84000000;
              uVar3 = 0;
            }
            else {
              uVar3 = 9;
            }
          }
          else {
            uVar3 = 8;
          }
        }
        else {
          uVar3 = 7;
        }
      }
      else {
        uVar3 = 5;
      }
    }
  }
  else {
    uVar3 = 3;
  }
  return uVar3;
}



// ===========================================================
// Function: FUN_0410d9e8 at 0410d9e8
// ===========================================================

undefined4 FUN_0410d9e8(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined2 uVar8;
  uint uVar9;
  bool bVar10;
  uint uVar11;
  
  iVar4 = DAT_0410db34;
  iVar1 = DAT_0410db2c;
  if (*DAT_0410db28 == '\x04') {
    uVar6 = param_1 - 1;
    if (4 < (uVar6 & 0xff)) {
      return 2;
    }
    if ((param_2 & 3) == 0) {
      if (*(int *)(DAT_0410db2c + uVar6 * 0xc) != 0) {
        return 4;
      }
      iVar7 = DAT_0410db30 + param_1 * 0x20;
      if (*(int *)(iVar7 + 0x900) << 0x10 < 0) {
        if (param_3 < 0x80000) {
          uVar2 = *(uint *)(iVar7 + 0x900) & 0x7ff;
          if (uVar2 < param_3) {
            uVar9 = ((param_3 - 1) + uVar2) / uVar2;
            if (0x3ff < uVar9) {
              return 8;
            }
            uVar11 = uVar9 << 0x13;
            uVar8 = (undefined2)uVar9;
          }
          else {
            uVar8 = 1;
            uVar11 = 0x80000;
          }
          bVar10 = SUB41((*(uint *)(iVar7 + 0x900) << 0xd) >> 0x1f,0);
          if ((*(uint *)(iVar7 + 0x900) & 0x40000) == 0) {
            if (param_4 == 0) {
              bVar10 = param_3 == uVar2 * (param_3 / uVar2);
            }
            *(bool *)(DAT_0410db2c + uVar6 * 0xc + 10) = bVar10;
            *(uint *)(DAT_0410db34 + uVar6 * 0x20) = uVar11 | param_3;
          }
          else {
            *(undefined1 *)(DAT_0410db2c + uVar6 * 0xc + 10) = 0;
            *(uint *)(iVar4 + uVar6 * 0x20) = uVar11 | param_3 | 0x20000000;
          }
          uVar3 = FUN_04107478(param_2);
          iVar5 = DAT_0410db30 + uVar6 * 0x20;
          *(undefined4 *)(iVar5 + 0x934) = uVar3;
          iVar4 = iVar1 + uVar6 * 0xc;
          *(undefined4 *)(iVar5 + 0x928) = *(undefined4 *)(iVar5 + 0x928);
          *(uint *)(iVar1 + uVar6 * 0xc) = param_2;
          *(uint *)(iVar4 + 4) = param_3;
          *(undefined2 *)(iVar4 + 8) = uVar8;
          *(undefined1 *)(iVar4 + 0xb) = 1;
          DataMemoryBarrier(0x1f);
          *(uint *)(iVar7 + 0x900) = *(uint *)(iVar7 + 0x900) | 0x84000000;
          return 0;
        }
        uVar3 = 7;
      }
      else {
        uVar3 = 5;
      }
    }
    else {
      uVar3 = 3;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



// ===========================================================
// Function: FUN_0410db38 at 0410db38
// ===========================================================

undefined4 FUN_0410db38(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = DAT_0410dc18;
  if (param_3 != 0) {
    if (param_1 != 0) {
      if ((param_2 & 0x1f) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_04109484(DAT_0410dc20);
      }
      if ((param_3 & 0x1f) == 0) {
        if (0xffe0 < param_3) {
          *(undefined4 *)(DAT_0410dc18 + 0x84) = 0;
          DataSynchronizationBarrier(0xf);
          uVar5 = ((*(uint *)(iVar2 + 0x80) & 0xfffffff) >> 0xd) << 5;
          do {
            uVar4 = (*(uint *)(iVar2 + 0x80) & 0x1fff) >> 3;
            do {
              uVar1 = uVar4 << 0x1e;
              uVar4 = uVar4 - 1;
              *(uint *)(iVar2 + 0x274) = uVar5 & 0x3fe0 | uVar1;
            } while (uVar4 != 0xffffffff);
            uVar5 = uVar5 - 0x20;
          } while (uVar5 != 0xffffffe0);
          DataSynchronizationBarrier(0xf);
          InstructionSynchronizationBarrier(0xf);
          return 0;
        }
        DataSynchronizationBarrier(0xf);
        iVar3 = param_3 + param_2;
        do {
          *(uint *)(iVar2 + 0x25c) = param_2;
          param_2 = param_2 + 0x20;
        } while (0 < (int)(iVar3 - param_2));
        DataSynchronizationBarrier(0xf);
        InstructionSynchronizationBarrier(0xf);
        return 0;
      }
                    /* WARNING: Subroutine does not return */
      FUN_04109484(DAT_0410dc1c,param_3);
    }
    if (0x7fe0 < param_3) {
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
      *(undefined4 *)(DAT_0410dc18 + 0x250) = 0;
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
      return 0;
    }
    DataSynchronizationBarrier(0xf);
    iVar3 = param_3 + (param_2 & 0x1f) + param_2;
    do {
      *(uint *)(iVar2 + 600) = param_2;
      param_2 = param_2 + 0x20;
    } while (0 < (int)(iVar3 - param_2));
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  return 0;
}



// ===========================================================
// Function: FUN_0410dc24 at 0410dc24
// ===========================================================

undefined4 FUN_0410dc24(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410dc4c + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) & 0xfffff00f | param_2 << 4;
  return 0;
}



// ===========================================================
// Function: FUN_0410dc50 at 0410dc50
// ===========================================================

undefined4 FUN_0410dc50(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410dc74 + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) & 0xfdffffff;
  return 0;
}



// ===========================================================
// Function: FUN_0410dc78 at 0410dc78
// ===========================================================

undefined4 FUN_0410dc78(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410dc9c + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) | 0x2000000;
  return 0;
}



// ===========================================================
// Function: FUN_0410dca0 at 0410dca0
// ===========================================================

void FUN_0410dca0(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(DAT_0410dcf0 + param_1 * 4);
  *(uint *)(iVar3 + 4) = DAT_0410dcf4 & param_3 << 0xc | DAT_0410dcf8 & *(uint *)(iVar3 + 4);
  do {
    iVar2 = param_3;
    if (((*(uint *)(iVar3 + 0xc) & 0x3e00) != 0) && (param_3 != 0)) {
      puVar1 = param_2;
      while( true ) {
        iVar2 = iVar2 + -1;
        *(undefined1 *)(iVar3 + 8) = *puVar1;
        if (puVar1 + 1 == param_2 + ((*(uint *)(iVar3 + 0xc) & 0x3fff) >> 9)) break;
        puVar1 = puVar1 + 1;
        if (iVar2 == 0) {
          return;
        }
      }
    }
  } while (iVar2 != 0);
  return;
}



// ===========================================================
// Function: FUN_0410dcfc at 0410dcfc
// ===========================================================

int FUN_0410dcfc(int param_1,undefined1 *param_2,int param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(DAT_0410dd38 + param_1 * 4);
  *(uint *)(iVar4 + 4) = DAT_0410dd3c & param_3 << 0xc | DAT_0410dd40 & *(uint *)(iVar4 + 4);
  uVar1 = (*(uint *)(iVar4 + 0xc) & 0x3fff) >> 9;
  if ((param_3 != 0) && (uVar1 != 0)) {
    puVar2 = param_2;
    iVar3 = param_3;
    do {
      iVar3 = iVar3 + -1;
      *(undefined1 *)(iVar4 + 8) = *puVar2;
      if (puVar2 + 1 == param_2 + uVar1) {
        return iVar3;
      }
      param_3 = 0;
      puVar2 = puVar2 + 1;
    } while (iVar3 != 0);
  }
  return param_3;
}



// ===========================================================
// Function: FUN_0410dd44 at 0410dd44
// ===========================================================

int FUN_0410dd44(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(DAT_0410dd74 + param_1 * 4);
  uVar3 = *(uint *)(iVar4 + 0xc);
  if (((uVar3 & 0x3e00) != 0) && (param_3 != 0)) {
    puVar1 = param_2;
    iVar2 = param_3;
    do {
      iVar2 = iVar2 + -1;
      *(undefined1 *)(iVar4 + 8) = *puVar1;
      if (puVar1 + 1 == param_2 + ((uVar3 & 0x3fff) >> 9)) {
        return iVar2;
      }
      param_3 = 0;
      puVar1 = puVar1 + 1;
    } while (iVar2 != 0);
  }
  return param_3;
}



// ===========================================================
// Function: FUN_0410dd78 at 0410dd78
// ===========================================================

undefined4 FUN_0410dd78(int param_1)

{
  return *(undefined4 *)(*(int *)(DAT_0410dd84 + param_1 * 4) + 0x10);
}



// ===========================================================
// Function: FUN_0410dd88 at 0410dd88
// ===========================================================

void FUN_0410dd88(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410dda0 + param_1 * 4);
  *(uint *)(iVar1 + 4) = DAT_0410dda4 & param_2 << 0xc | DAT_0410dda8 & *(uint *)(iVar1 + 4);
  return;
}



// ===========================================================
// Function: FUN_0410ddac at 0410ddac
// ===========================================================

void FUN_0410ddac(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(DAT_0410ddd8 + param_1 * 4);
  do {
    if (-1 < (int)(puVar2[3] << 0x1f)) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  puVar2[1] = puVar2[1] & 0xfffffffe;
  *puVar2 = param_2 | param_3 << 8;
  return;
}



// ===========================================================
// Function: FUN_0410dddc at 0410dddc
// ===========================================================

void FUN_0410dddc(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(DAT_0410de10 + param_1 * 4);
  do {
    if (-1 < (int)(puVar2[3] << 0x1f)) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  puVar2[1] = DAT_0410de14 & param_3 << 0xc | DAT_0410de18 & puVar2[1] | 1;
  *puVar2 = param_2;
  return;
}



// ===========================================================
// Function: FUN_0410de1c at 0410de1c
// ===========================================================

void FUN_0410de1c(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(DAT_0410de60 + param_1 * 4);
  do {
    if (-1 < (int)(puVar3[3] << 0x1f)) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  uVar2 = DAT_0410de6c & param_4 << 0xd;
  puVar3[1] = DAT_0410de68 & param_3 << 0xc | DAT_0410de64 & puVar3[1] | 1;
  *puVar3 = uVar2 | param_2 | 0x100;
  return;
}



// ===========================================================
// Function: FUN_0410de70 at 0410de70
// ===========================================================

void FUN_0410de70(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410de90 + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) & 0xfffffffe;
  return;
}



// ===========================================================
// Function: FUN_0410de94 at 0410de94
// ===========================================================

void FUN_0410de94(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410deb4 + param_1 * 4);
  do {
    if (param_2 <= (*(uint *)(iVar2 + 0xc) & 0x1ff) >> 4) {
      return;
    }
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  return;
}



// ===========================================================
// Function: FUN_0410deb8 at 0410deb8
// ===========================================================

void FUN_0410deb8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410ded0 + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1c) {
      return;
    }
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  return;
}



// ===========================================================
// Function: FUN_0410ded4 at 0410ded4
// ===========================================================

void FUN_0410ded4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410deec + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) {
      return;
    }
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  return;
}



// ===========================================================
// Function: FUN_0410def0 at 0410def0
// ===========================================================

uint FUN_0410def0(int param_1)

{
  return *(uint *)(*(int *)(DAT_0410df00 + param_1 * 4) + 0xc) & 1;
}



// ===========================================================
// Function: FUN_0410df04 at 0410df04
// ===========================================================

void FUN_0410df04(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410df30 + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  *(undefined4 *)(iVar2 + 0x18) = 3;
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) {
      return;
    }
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  return;
}



// ===========================================================
// Function: FUN_0410df34 at 0410df34
// ===========================================================

void FUN_0410df34(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410df60 + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  *(undefined4 *)(iVar2 + 0x18) = 1;
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) {
      return;
    }
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  return;
}



// ===========================================================
// Function: FUN_0410df64 at 0410df64
// ===========================================================

void FUN_0410df64(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410df90 + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  *(undefined4 *)(iVar2 + 0x18) = 2;
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) {
      return;
    }
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  return;
}



// ===========================================================
// Function: FUN_0410df94 at 0410df94
// ===========================================================

void FUN_0410df94(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410dfc0 + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  *(uint *)(iVar2 + 0x14) = (param_2 & 0xff) << 0x10 | *(uint *)(iVar2 + 0x14) & 0xff00ffff;
  return;
}



// ===========================================================
// Function: FUN_0410dfc4 at 0410dfc4
// ===========================================================

uint FUN_0410dfc4(int param_1)

{
  return (*(uint *)(*(int *)(DAT_0410dfd4 + param_1 * 4) + 0x14) & 0xffffff) >> 0x10;
}



// ===========================================================
// Function: FUN_0410dfd8 at 0410dfd8
// ===========================================================

void FUN_0410dfd8(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410e000 + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  *(uint *)(iVar2 + 0x14) = (param_2 & 0xf) << 0xc | *(uint *)(iVar2 + 0x14) & 0xffff0fff;
  return;
}



// ===========================================================
// Function: FUN_0410e004 at 0410e004
// ===========================================================

void FUN_0410e004(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410e034 + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  if (param_2 != 0) {
    *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x20;
    return;
  }
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xffffffdf;
  return;
}



// ===========================================================
// Function: FUN_0410e038 at 0410e038
// ===========================================================

void FUN_0410e038(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410e068 + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  if (param_2 != 0) {
    *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x10;
    return;
  }
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xffffffef;
  return;
}



// ===========================================================
// Function: FUN_0410e06c at 0410e06c
// ===========================================================

void FUN_0410e06c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410e088 + param_1 * 4);
  if (param_2 != 0) {
    *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | 8;
    return;
  }
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xfffffff7;
  return;
}



// ===========================================================
// Function: FUN_0410e08c at 0410e08c
// ===========================================================

void FUN_0410e08c(int param_1,uint param_2)

{
  *(uint *)(*(int *)(DAT_0410e098 + param_1 * 4) + 0x30) = param_2 >> 0x18;
  return;
}



// ===========================================================
// Function: FUN_0410e09c at 0410e09c
// ===========================================================

void FUN_0410e09c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410e0b8 + param_1 * 4);
  if (param_2 != 0) {
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 1;
    return;
  }
  *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffe;
  return;
}



// ===========================================================
// Function: FUN_0410e0bc at 0410e0bc
// ===========================================================

void FUN_0410e0bc(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410e0d4 + param_1 * 4);
  *(uint *)(iVar1 + 0x1c) = (param_2 & 0x1f) << 4 | *(uint *)(iVar1 + 0x1c) & 0xfffffe0f;
  return;
}



// ===========================================================
// Function: FUN_0410e0d8 at 0410e0d8
// ===========================================================

void FUN_0410e0d8(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410e0f0 + param_1 * 4);
  *(uint *)(iVar1 + 0x1c) = (param_2 & 0x1f) << 9 | *(uint *)(iVar1 + 0x1c) & 0xffffc1ff;
  return;
}



// ===========================================================
// Function: FUN_0410e0f4 at 0410e0f4
// ===========================================================

void FUN_0410e0f4(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410e10c + param_1 * 4);
  *(uint *)(iVar1 + 0x20) = (param_2 & 0xff) << 0x10 | *(uint *)(iVar1 + 0x20) & 0xff00ffff;
  return;
}



// ===========================================================
// Function: FUN_0410e110 at 0410e110
// ===========================================================

void FUN_0410e110(int param_1,byte param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410e130 + param_1 * 4);
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xffffff00 | (uint)param_2;
  *(uint *)(iVar1 + 0x38) = *(uint *)(iVar1 + 0x38) & 0xffffff | (uint)param_2 << 0x18;
  return;
}



// ===========================================================
// Function: FUN_0410e134 at 0410e134
// ===========================================================

void FUN_0410e134(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410e14c + param_1 * 4);
  *(uint *)(iVar1 + 0x34) = (param_2 & 0xf) << 0x12 | *(uint *)(iVar1 + 0x34) & 0xffc3ffff;
  return;
}



// ===========================================================
// Function: FUN_0410e150 at 0410e150
// ===========================================================

undefined4 FUN_0410e150(int param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  if (3 < param_2) {
    return 1;
  }
  iVar2 = *(int *)(DAT_0410e1cc + param_1 * 4);
  if (param_4 == 0) {
    *(uint *)(iVar2 + 0xb0) = *(uint *)(iVar2 + 0xb0) & ~(2 << (param_2 & 0xff));
    uVar1 = 0;
  }
  else if ((param_3 & 0xfff) == 0) {
    if ((param_5 & 0xfff) == 0) {
      if (param_4 < 0x1000) {
        uVar1 = 4;
      }
      else {
        if ((param_4 & 0xfff) == 0) {
          *(uint *)(iVar2 + 0x70 + param_2 * 4) = param_3;
          *(uint *)(iVar2 + 0x80 + param_2 * 4) = (param_4 - 1) + param_3;
          *(uint *)(iVar2 + 0x90 + param_2 * 4) = param_5;
          return 0;
        }
        uVar1 = 5;
      }
    }
    else {
      uVar1 = 3;
    }
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}



// ===========================================================
// Function: FUN_0410e1d0 at 0410e1d0
// ===========================================================

void FUN_0410e1d0(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410e1ec + param_1 * 4);
  *(uint *)(iVar1 + 0xb0) = 2 << (param_2 & 0xff) | *(uint *)(iVar1 + 0xb0) | 1;
  return;
}



// ===========================================================
// Function: FUN_0410e1f0 at 0410e1f0
// ===========================================================

void FUN_0410e1f0(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410e20c + param_1 * 4);
  *(uint *)(iVar1 + 0xb0) = *(uint *)(iVar1 + 0xb0) & ~(2 << (param_2 & 0xff));
  return;
}



// ===========================================================
// Function: FUN_0410e210 at 0410e210
// ===========================================================

void FUN_0410e210(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410e240 + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  if (param_2 != 0) {
    *(uint *)(iVar2 + 0x40) = *(uint *)(iVar2 + 0x40) | 0xc;
    return;
  }
  *(uint *)(iVar2 + 0x40) = *(uint *)(iVar2 + 0x40) & 0xfffffff3;
  return;
}



// ===========================================================
// Function: FUN_0410e244 at 0410e244
// ===========================================================

void FUN_0410e244(int param_1,uint param_2)

{
  *(uint *)(*(int *)(DAT_0410e254 + param_1 * 4) + 0x108) = param_2 & 0x1f;
  return;
}



// ===========================================================
// Function: FUN_0410e258 at 0410e258
// ===========================================================

void FUN_0410e258(int param_1,uint param_2)

{
  *(uint *)(*(int *)(DAT_0410e268 + param_1 * 4) + 0x150) = param_2 & 0x1f;
  return;
}



// ===========================================================
// Function: FUN_0410e26c at 0410e26c
// ===========================================================

void FUN_0410e26c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410e27c + param_1 * 4);
  *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) | 2;
  return;
}



// ===========================================================
// Function: FUN_0410e280 at 0410e280
// ===========================================================

void FUN_0410e280(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410e2a0 + param_1 * 4);
  if (param_2 != 0) {
    *(uint *)(iVar1 + 0x204) = *(uint *)(iVar1 + 0x204) | 0x200000;
    return;
  }
  *(uint *)(iVar1 + 0x204) = *(uint *)(iVar1 + 0x204) & 0xffdfffff;
  return;
}



// ===========================================================
// Function: FUN_0410e2a4 at 0410e2a4
// ===========================================================

void FUN_0410e2a4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_0410e2dc + param_1 * 4);
  do {
    if (-1 < *(int *)(iVar2 + 0xc) << 0x1f) break;
    iVar1 = FUN_04106ed0();
  } while (iVar1 != 0);
  if (param_2 != 0) {
    *(uint *)(iVar2 + 0x204) = *(uint *)(iVar2 + 0x204) | 0x80000;
    return;
  }
  *(uint *)(iVar2 + 0x204) = *(uint *)(iVar2 + 0x204) & 0xfff7ffff;
  return;
}



// ===========================================================
// Function: FUN_0410e314 at 0410e314
// ===========================================================

void FUN_0410e314(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410e334 + param_1 * 4);
  if (param_2 != 0) {
    *(uint *)(iVar1 + 0x204) = *(uint *)(iVar1 + 0x204) | 0x2000000;
    return;
  }
  *(uint *)(iVar1 + 0x204) = *(uint *)(iVar1 + 0x204) & 0xfdffffff;
  return;
}



// ===========================================================
// Function: FUN_0410e338 at 0410e338
// ===========================================================

void FUN_0410e338(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410e348 + param_1 * 4);
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0x1fffffff;
  return;
}



// ===========================================================
// Function: FUN_0410e34c at 0410e34c
// ===========================================================

void FUN_0410e34c(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0410e364 + param_1 * 4);
  *(uint *)(iVar1 + 0x380) = param_2 & 0xf | *(uint *)(iVar1 + 0x380);
  return;
}



// ===========================================================
// Function: FUN_0410e368 at 0410e368
// ===========================================================

void FUN_0410e368(void)

{
  undefined1 uVar1;
  
  uVar1 = FUN_04101880();
  *DAT_0410e37c = uVar1;
  FUN_041089cc(uVar1);
  return;
}



// ===========================================================
// Function: FUN_0410e38c at 0410e38c
// ===========================================================

void FUN_0410e38c(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar4 = *(int *)(DAT_0410e404 + param_1 * 4);
  uVar3 = 1 << (param_2 & 0xff);
  if (((*(uint *)(iVar4 + 4) | *(uint *)(iVar4 + 0xc)) & uVar3 & 0xff) != 0) {
    if ((*(uint *)(iVar4 + 4) & uVar3 & 0xff) != 0) {
      *(uint *)(iVar4 + 8) = uVar3 & 0xff;
    }
    uVar5 = *(uint *)(iVar4 + 0xc) & uVar3 & 0xff;
    if (uVar5 != 0) {
      *(uint *)(iVar4 + 0x10) = uVar3 & 0xff;
    }
    iVar1 = DAT_0410e408;
    iVar6 = param_2 + param_1 * 8;
    if (*(int *)(DAT_0410e408 + iVar6 * 4) != 0) {
      iVar4 = iVar4 + param_2 * 0x20;
      uVar3 = *(uint *)(iVar4 + 0x10c);
      uVar2 = FUN_041074a4(*(undefined4 *)(iVar4 + 0x108));
                    /* WARNING: Could not recover jumptable at 0x0410e3fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar1 + iVar6 * 4))
                ((param_2 | param_1 << 4) & 0xff,uVar3 & 0xfff,uVar5 != 0,uVar2);
      return;
    }
  }
  return;
}



// ===========================================================
// Function: FUN_0410e484 at 0410e484
// ===========================================================

undefined4 FUN_0410e484(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int *piVar16;
  char *pcVar17;
  
  uVar6 = *(ushort *)(param_2 + 2);
  if (0xfff < uVar6) {
    return 2;
  }
  bVar1 = *(byte *)(param_2 + 8);
  uVar13 = (uint)bVar1;
  uVar14 = uVar13 & 0xf;
  switch(uVar14) {
  case 0:
    uVar9 = 0xc000000;
    break;
  case 1:
  case 5:
    uVar9 = 0x4000000;
    break;
  case 2:
  case 6:
    uVar9 = 0x8000000;
    break;
  case 3:
  case 4:
  case 7:
    uVar9 = 0;
    break;
  default:
    return 3;
  }
  if ((int)(uVar13 << 0x1b) < 0) {
    uVar9 = uVar9 | 0x4000000;
  }
  if ((int)(uVar13 << 0x1a) < 0) {
    uVar9 = uVar9 | 0x8000000;
  }
  if ((int)(uVar13 << 0x19) < 0) {
    uVar9 = uVar9 & 0xfbffffff;
  }
  if ((int)(uVar13 << 0x18) < 0) {
    uVar9 = uVar9 & 0xf7ffffff;
  }
  uVar13 = *(byte *)(param_2 + 1) & 0xf;
  if ((*(byte *)(param_2 + 1) & 0xf) != 0) {
    if (uVar13 == 2) {
      uVar13 = 0x30000000;
    }
    else if (uVar13 == 3) {
      uVar13 = 0x10000000;
    }
    else if (uVar13 == 4) {
      uVar13 = 0x20000000;
    }
    else {
      uVar13 = 0;
    }
  }
  bVar2 = *(byte *)(param_2 + 7);
  bVar3 = *(byte *)(param_2 + 6);
  bVar4 = *(byte *)(param_2 + 4);
  bVar5 = *(byte *)(param_2 + 5);
  if (param_4 == 0) {
    uVar10 = 0;
  }
  else {
    uVar10 = 0x80000000;
  }
  if (((bVar1 & 0xe) == 0) || (uVar14 == 5)) {
    uVar12 = FUN_04107478(*(undefined4 *)(param_2 + 0xc));
    *param_1 = uVar12;
  }
  else {
    iVar8 = 0x10;
    iVar15 = 0;
    piVar16 = DAT_0410e670;
    while( true ) {
      if (iVar8 != 0) {
        iVar7 = piVar16[1];
        pcVar11 = (char *)(iVar7 + -1);
        do {
          pcVar17 = pcVar11 + (1 - iVar7);
          pcVar11 = pcVar11 + 1;
          if (*pcVar11 == *(char *)(param_2 + 9)) {
            uVar12 = *(undefined4 *)
                      (*(int *)(DAT_0410e66c + iVar15 * 8 + 4) + ((uint)pcVar17 & 0xff) * 4);
            goto LAB_0410e5a4;
          }
        } while (pcVar11 != (char *)(iVar8 + -1 + iVar7));
      }
      iVar15 = iVar15 + 1;
      if (iVar15 == 3) break;
      piVar16 = piVar16 + 2;
      iVar8 = *piVar16;
    }
    uVar12 = 0;
LAB_0410e5a4:
    *param_1 = uVar12;
  }
  if (((bVar1 & 0xd) == 0) || (uVar14 == 6)) {
    uVar12 = FUN_04107478(*(undefined4 *)(param_2 + 0x10));
    param_1[1] = uVar12;
  }
  else {
    iVar8 = 0x10;
    iVar15 = 0;
    piVar16 = DAT_0410e670;
    while( true ) {
      if (iVar8 != 0) {
        iVar7 = piVar16[1];
        pcVar11 = (char *)(iVar7 + -1);
        do {
          pcVar17 = pcVar11 + (1 - iVar7);
          pcVar11 = pcVar11 + 1;
          if (*pcVar11 == *(char *)(param_2 + 10)) {
            uVar12 = *(undefined4 *)
                      (*(int *)(DAT_0410e66c + iVar15 * 8 + 4) + ((uint)pcVar17 & 0xff) * 4);
            goto LAB_0410e5f4;
          }
        } while (pcVar11 != (char *)(iVar8 + -1 + iVar7));
      }
      iVar15 = iVar15 + 1;
      if (iVar15 == 3) break;
      piVar16 = piVar16 + 2;
      iVar8 = *piVar16;
    }
    uVar12 = 0;
LAB_0410e5f4:
    param_1[1] = uVar12;
  }
  uVar12 = FUN_04107478(param_3);
  param_1[2] = uVar12;
  param_1[3] = uVar9 | (bVar3 & 7) << 0xc | (bVar2 & 7) << 0xf | (uint)uVar6 | (bVar4 & 7) << 0x12 |
                       (bVar5 & 7) << 0x15 | uVar13 | uVar10;
  return 0;
}



// ===========================================================
// Function: FUN_0410ea14 at 0410ea14
// ===========================================================

/* WARNING: Removing unreachable block (ram,0x0410e704) */
/* WARNING: Removing unreachable block (ram,0x0410e98a) */
/* WARNING: Removing unreachable block (ram,0x0410e712) */
/* WARNING: Removing unreachable block (ram,0x0410e990) */
/* WARNING: Removing unreachable block (ram,0x0410e71c) */
/* WARNING: Removing unreachable block (ram,0x0410e9ac) */
/* WARNING: Removing unreachable block (ram,0x0410e72a) */
/* WARNING: Removing unreachable block (ram,0x0410e9be) */
/* WARNING: Removing unreachable block (ram,0x0410e734) */
/* WARNING: Removing unreachable block (ram,0x0410e846) */
/* WARNING: Removing unreachable block (ram,0x0410e9b8) */
/* WARNING: Removing unreachable block (ram,0x0410e854) */
/* WARNING: Removing unreachable block (ram,0x0410e9c4) */
/* WARNING: Removing unreachable block (ram,0x0410e860) */
/* WARNING: Removing unreachable block (ram,0x0410e9ca) */
/* WARNING: Removing unreachable block (ram,0x0410e86e) */
/* WARNING: Removing unreachable block (ram,0x0410e9d0) */
/* WARNING: Removing unreachable block (ram,0x0410e87a) */

uint FUN_0410ea14(undefined4 *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  code *pcVar10;
  int iVar11;
  uint uVar12;
  byte *pbVar13;
  uint uVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  undefined4 unaff_lr;
  int *local_34;
  
  iVar4 = DAT_0410e9ec;
  bVar1 = *param_2;
  uVar17 = (uint)bVar1;
  uVar12 = (uint)(bVar1 >> 4);
  if (0x2f < uVar17) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410ea0c,uVar12);
  }
  uVar16 = uVar17 & 0xf;
  if ((bVar1 & 8) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410ea10,uVar12,uVar16);
  }
  bVar1 = param_2[8];
  uVar8 = bVar1 & 0xf;
  if (((bVar1 & 0xe) != 0) && (uVar8 != 5)) {
    local_34 = DAT_0410e9f0;
    iVar11 = 0x10;
    uVar14 = uVar17 & 8;
    do {
      if (iVar11 != 0) {
        iVar7 = local_34[1];
        pbVar9 = (byte *)(iVar7 + -1);
        do {
          pbVar13 = pbVar9 + (1 - iVar7);
          pbVar9 = pbVar9 + 1;
          if (*pbVar9 == param_2[9]) {
            local_34 = (int *)((uint)pbVar13 & 0xff);
            if ((uVar14 & 0xff) != uVar12) {
                    /* WARNING: Subroutine does not return */
              FUN_04109484(DAT_0410e9f4,uVar17,param_2[9]);
            }
            goto LAB_0410e6b6;
          }
        } while (pbVar9 != (byte *)(iVar11 + -1 + iVar7));
      }
      uVar14 = uVar14 + 1;
      if (uVar14 == 3) {
                    /* WARNING: Subroutine does not return */
        FUN_04109484(DAT_0410e9fc);
      }
      local_34 = local_34 + 2;
      iVar11 = *local_34;
    } while( true );
  }
  local_34 = (int *)0x0;
LAB_0410e6b6:
  if (((bVar1 & 0xd) != 0) && (uVar8 != 6)) {
    iVar11 = 0x10;
    uVar8 = 0;
    piVar15 = DAT_0410e9f0;
    do {
      if (iVar11 != 0) {
        iVar7 = piVar15[1];
        pbVar9 = (byte *)(iVar7 + -1);
        do {
          pbVar13 = pbVar9 + (1 - iVar7);
          pbVar9 = pbVar9 + 1;
          if (*pbVar9 == param_2[10]) {
            uVar14 = (uint)pbVar13 & 0xff;
            if (uVar12 != (uVar8 & 0xff)) {
                    /* WARNING: Subroutine does not return */
              FUN_04109484(DAT_0410e9f8,uVar17,param_2[10]);
            }
            goto LAB_0410e6d0;
          }
        } while ((byte *)(iVar11 + -1 + iVar7) != pbVar9);
      }
      uVar8 = uVar8 + 1;
      if (uVar8 == 3) {
                    /* WARNING: Subroutine does not return */
        FUN_04109484(DAT_0410ea08);
      }
      piVar15 = piVar15 + 2;
      iVar11 = *piVar15;
    } while( true );
  }
  uVar14 = 0;
LAB_0410e6d0:
  if (*(char *)(DAT_0410e9e8 + uVar12 * 8 + uVar16) == '\0') {
    return 4;
  }
  iVar11 = *(int *)(DAT_0410e9ec + uVar12 * 4);
  if ((*(uint *)(iVar11 + 0x1c) & 1 << uVar16 & 0xff) != 0) {
    return 5;
  }
  iVar7 = iVar11 + uVar16 * 0x20;
  *(uint *)(iVar7 + 0x210) = *(uint *)(iVar7 + 0x210) & 0xfffffffe;
  iVar7 = iVar11 + uVar16 * 0x20;
  *(uint *)(iVar7 + 0x210) = *(uint *)(iVar7 + 0x210) & 0xfffffffd;
  uVar8 = 0;
  if (*(int *)(param_2 + 0x14) != 0) {
    *(int *)(DAT_0410ea00 + (uVar12 * 8 + uVar16) * 4) = *(int *)(param_2 + 0x14);
    uVar8 = 0xc000;
  }
  uVar6 = 1 << uVar16 & 0xff;
  iVar18 = iVar11 + uVar16 * 0x20;
  bVar2 = param_2[1];
  *(uint *)(iVar11 + 8) = uVar6;
  *(uint *)(iVar11 + 0x10) = uVar6;
  iVar7 = iVar11 + uVar16 * 0x20;
  uVar6 = 0;
  if ((bVar2 & 0xf0) != 0) {
    uVar6 = 0x80000;
  }
  *(undefined4 *)(iVar18 + 0x100) = *param_1;
  *(undefined4 *)(iVar18 + 0x104) = param_1[1];
  *(undefined4 *)(iVar7 + 0x108) = param_1[2];
  *(undefined4 *)(iVar7 + 0x10c) = param_1[3];
  *(uint *)(iVar7 + 0x110) =
       uVar8 | ((uint)local_34 & 0x1f) << 1 | (bVar1 & 7) << 0xb | (uVar14 & 0x1f) << 6 | uVar6;
  puVar5 = DAT_0410ea04;
  iVar18 = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    iVar18 = getBasePriority();
  }
  if (iVar18 == 0x40) {
    pcVar10 = *(code **)(param_2 + 0x18);
    if (pcVar10 == (code *)0x0) {
      *(uint *)(iVar7 + 0x110) = *(uint *)(iVar7 + 0x110) | 1;
      goto LAB_0410e958;
    }
LAB_0410e936:
    (*pcVar10)(*param_2);
  }
  else {
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      setBasePriority(0x40);
    }
    iVar11 = *(int *)(iVar4 + uVar12 * 4);
    *DAT_0410ea04 = 0x410e926;
    puVar5[1] = unaff_lr;
    pcVar10 = *(code **)(param_2 + 0x18);
    if (pcVar10 != (code *)0x0) goto LAB_0410e936;
  }
  iVar11 = iVar11 + uVar16 * 0x20;
  *(uint *)(iVar11 + 0x110) = *(uint *)(iVar11 + 0x110) | 1;
  if (iVar18 == 0) {
    *DAT_0410ea04 = 0xffffffff;
  }
LAB_0410e958:
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    setBasePriority(iVar18);
  }
  return uVar17 & 8;
}



// ===========================================================
// Function: FUN_0410ea1c at 0410ea1c
// ===========================================================

void FUN_0410ea1c(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (0x2f < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410ea60);
  }
  if (-1 < (int)(param_1 << 0x1c)) {
    iVar1 = *(int *)(DAT_0410ea5c + (param_1 >> 4) * 4);
    iVar2 = iVar1 + (param_1 & 0xf) * 0x20;
    uVar3 = 1 << (param_1 & 0xf) & 0xff;
    *(uint *)(iVar2 + 0x110) = *(uint *)(iVar2 + 0x110) & 0xfffffffe;
    *(uint *)(iVar1 + 8) = uVar3;
    *(uint *)(iVar1 + 0x10) = uVar3;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410ea64);
}



// ===========================================================
// Function: FUN_0410ea68 at 0410ea68
// ===========================================================

void FUN_0410ea68(uint param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if (0x2f < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410eaf8);
  }
  if ((int)(param_1 << 0x1c) < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410eafc);
  }
  iVar5 = *(int *)(DAT_0410eaf0 + (param_1 >> 4) * 4) + (param_1 & 0xf) * 0x20;
  *(uint *)(iVar5 + 0x110) = *(uint *)(iVar5 + 0x110) | 0x40000;
  puVar2 = DAT_0410eaf4;
  if (*(int *)(iVar5 + 0x110) << 0xe < 0) {
    uVar4 = 2;
    do {
      if (uVar4 - 1 < 4) {
        FUN_0410ad74(10);
        if (-1 < *(int *)(iVar5 + 0x110) << 0xe) break;
      }
      else {
        if ((code *)*puVar2 == (code *)0x0) {
LAB_0410eadc:
          FUN_0410ad60(0x10);
        }
        else {
          uVar3 = 0;
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            uVar3 = getCurrentExceptionNumber();
            uVar3 = uVar3 & 0x1f;
          }
          if (uVar3 != 0) goto LAB_0410eadc;
          (*(code *)*puVar2)(1);
        }
        if ((-1 < *(int *)(iVar5 + 0x110) << 0xe) || (uVar4 == 10)) break;
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while( true );
  }
  FUN_0410ea1c(param_1);
  return;
}



// ===========================================================
// Function: FUN_0410eb00 at 0410eb00
// ===========================================================

uint FUN_0410eb00(uint param_1,uint param_2,uint param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 unaff_lr;
  int iVar12;
  
  puVar2 = DAT_0410ec48;
  if (2 < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410ec60);
  }
  if (param_1 == 0) {
    return 0xff;
  }
  pbVar4 = (byte *)(param_1 - 1);
  if ((byte *)0x2 < pbVar4) {
    uVar8 = 0;
    iVar9 = 0x10;
    piVar7 = DAT_0410ec50;
    do {
      if (iVar9 != 0) {
        pbVar4 = (byte *)(piVar7[1] + -1);
        do {
          pbVar4 = pbVar4 + 1;
          param_3 = (uint)*pbVar4;
          if (param_3 == param_1) {
            uVar11 = (uint)*(byte *)(DAT_0410ec54 + uVar8);
            uVar5 = (uint)*(byte *)(DAT_0410ec58 + uVar8);
            uVar3 = uVar11 + uVar5;
            goto LAB_0410eb2a;
          }
        } while ((byte *)(iVar9 + -1 + piVar7[1]) != pbVar4);
      }
      uVar8 = uVar8 + 1;
      if (uVar8 == 3) {
                    /* WARNING: Subroutine does not return */
        FUN_04109484(DAT_0410ec5c,param_1,param_3,pbVar4,param_4);
      }
      piVar7 = piVar7 + 2;
      iVar9 = *piVar7;
    } while( true );
  }
  if (param_1 == 2) {
    uVar3 = 6;
    uVar8 = 1;
    uVar11 = 6;
    uVar5 = 0;
  }
  else if (param_1 == 3) {
    uVar3 = 6;
    uVar5 = 0;
    uVar8 = 2;
    uVar11 = uVar3;
  }
  else {
    uVar3 = 6;
    uVar5 = 0;
    uVar8 = 0;
    uVar11 = 6;
  }
LAB_0410eb2a:
  iVar9 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar9 = getBasePriority();
  }
  if (iVar9 == 0x40) {
    if (uVar3 <= uVar5) {
      uVar8 = 0xff;
      goto LAB_0410eb94;
    }
LAB_0410eb46:
    iVar6 = uVar11 + uVar5;
    iVar12 = DAT_0410ec4c + uVar8 * 8;
    do {
      uVar11 = uVar5;
      if (((param_2 != 0) && (uVar11 = (iVar6 + -1) - uVar5 & 0xff, param_2 == 2)) &&
         (uVar11 + 2 < uVar3)) break;
      if (*(char *)(iVar12 + uVar11) == '\0') {
        iVar10 = *(int *)(DAT_0410ec64 + uVar8 * 4);
        if ((*(uint *)(iVar10 + 0x1c) & 1 << uVar11 & 0xff) == 0) {
          *(undefined1 *)(iVar12 + uVar11) = 1;
          uVar8 = uVar11 & 0xf | (uVar8 & 0xf) << 4;
          *(uint *)(iVar10 + 0x30) = (1 << uVar11 & 0xffU) << 0xc | *(uint *)(iVar10 + 0x30);
          goto LAB_0410eb86;
        }
      }
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < uVar3);
  }
  else {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *DAT_0410ec48 = 0x410eb3e;
    puVar2[1] = unaff_lr;
    if (uVar5 < uVar3) goto LAB_0410eb46;
  }
  uVar8 = 0xff;
LAB_0410eb86:
  if (iVar9 == 0) {
    *DAT_0410ec48 = 0xffffffff;
  }
LAB_0410eb94:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar9);
  }
  return uVar8;
}



// ===========================================================
// Function: FUN_0410ec68 at 0410ec68
// ===========================================================

void FUN_0410ec68(uint param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_lr;
  
  uVar7 = param_1 >> 4;
  if (0x2f < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410ed20,uVar7);
  }
  uVar6 = param_1 & 0xf;
  if ((param_1 & 8) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410ed1c,uVar7,uVar6);
  }
  iVar5 = DAT_0410ed0c + uVar7 * 8;
  if (*(char *)(iVar5 + uVar6) == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410ed18,uVar7,uVar6);
  }
  FUN_0410ea1c();
  iVar2 = DAT_0410ed10;
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = getBasePriority();
  }
  if (iVar4 != 0x40) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x40);
    }
    *(undefined1 *)(iVar5 + uVar6) = 0;
    iVar5 = *(int *)(iVar2 + uVar7 * 4);
    *(uint *)(iVar5 + 0x30) = *(uint *)(iVar5 + 0x30) & ~(0x1000 << uVar6 & 0xff000U);
    puVar3 = DAT_0410ed14;
    *DAT_0410ed14 = 0x410eca0;
    puVar3[1] = unaff_lr;
    if (iVar4 == 0) {
      *puVar3 = 0xffffffff;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(iVar4);
    }
    return;
  }
  *(undefined1 *)(iVar5 + uVar6) = 0;
  iVar5 = *(int *)(iVar2 + uVar7 * 4);
  *(uint *)(iVar5 + 0x30) = *(uint *)(iVar5 + 0x30) & ~(0x1000 << uVar6 & 0xff000U);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x40);
  }
  return;
}



// ===========================================================
// Function: FUN_0410ed24 at 0410ed24
// ===========================================================

undefined4 FUN_0410ed24(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 >> 4;
  if (0x2f < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410ed74,uVar1);
  }
  if ((param_1 & 8) == 0) {
    if ((1 << (param_1 & 0xf) & **(uint **)(DAT_0410ed6c + uVar1 * 4) & 0xff) != 0) {
      FUN_0410e38c(uVar1);
      return 0;
    }
    return 0xe;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410ed70,uVar1,param_1 & 0xf);
}



// ===========================================================
// Function: FUN_0410ed78 at 0410ed78
// ===========================================================

bool FUN_0410ed78(uint param_1)

{
  if (0x2f < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410edb4);
  }
  if (-1 < (int)(param_1 << 0x1c)) {
    return (1 << (param_1 & 0xf) & *(uint *)(*(int *)(DAT_0410edb0 + (param_1 >> 4) * 4) + 0x1c) &
           0xff) != 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410edb8);
}



// ===========================================================
// Function: FUN_0410edbc at 0410edbc
// ===========================================================

uint FUN_0410edbc(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (0x2f < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_04109484(DAT_0410ee14);
  }
  uVar3 = param_1 & 0xf;
  if (-1 < (int)(param_1 << 0x1c)) {
    iVar2 = *(int *)(DAT_0410ee10 + (param_1 >> 4) * 4) + uVar3 * 0x20;
    uVar3 = *(uint *)(iVar2 + 0x10c);
    iVar1 = FUN_041074a4(*(undefined4 *)(iVar2 + 0x108));
    uVar3 = uVar3 & 0xfff;
    iVar2 = iVar1;
    do {
      if (iVar2 == 0) {
        return uVar3;
      }
      uVar3 = uVar3 + (*(uint *)(iVar2 + 0xc) & 0xfff);
      iVar2 = FUN_041074a4(*(undefined4 *)(iVar2 + 8));
    } while (iVar1 != iVar2);
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  FUN_04109484(DAT_0410ee18,param_1 >> 4,uVar3,uVar3,param_4);
}



// ===========================================================
// Function: FUN_0410ef24 at 0410ef24
// ===========================================================

undefined4 FUN_0410ef24(uint param_1)

{
  if (param_1 < 0x10) {
    return *(undefined4 *)(DAT_0410ef38 + (param_1 + 0x40) * 4);
  }
  return 0;
}



// ===========================================================
// Function: FUN_0410ef3c at 0410ef3c
// ===========================================================

void FUN_0410ef3c(uint param_1)

{
  if (param_1 < 0x10) {
    *(undefined4 *)(DAT_0410ef4c + (param_1 + 0x40) * 4) = 1;
  }
  return;
}



// ===========================================================
// Function: FUN_0410ef50 at 0410ef50
// ===========================================================

void FUN_0410ef50(void)

{
                    /* WARNING: Could not recover jumptable at 0x0410ef5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_0410ef60 + 0x60))();
  return;
}



// ===========================================================
// Function: FUN_0410ef64 at 0410ef64
// ===========================================================

void FUN_0410ef64(void)

{
                    /* WARNING: Could not recover jumptable at 0x0410ef68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_0410ef6c + 0x30))();
  return;
}



// ===========================================================
// Function: FUN_0410ef70 at 0410ef70
// ===========================================================

void FUN_0410ef70(void)

{
                    /* WARNING: Could not recover jumptable at 0x0410ef74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_0410ef78 + 0x34))();
  return;
}



// ===========================================================
// Function: FUN_0410ef7c at 0410ef7c
// ===========================================================

void FUN_0410ef7c(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  
  if ((param_3 == 0) || (param_1 == param_2)) {
    return;
  }
  if (param_1 < param_2) {
    if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
      uVar6 = param_3 >> 2;
      uVar4 = param_3 & 3;
      uVar7 = param_3;
    }
    else {
      if (((((uint)param_1 ^ (uint)param_2) & 3) == 0) && (3 < param_3)) {
        uVar7 = ((uint)param_2 | 0xfffffffc) + param_3;
        param_3 = 4 - ((uint)param_2 & 3);
        uVar6 = uVar7 >> 2;
        uVar4 = uVar7 & 3;
      }
      else {
        uVar4 = 0;
        uVar6 = 0;
        uVar7 = 0;
      }
      puVar2 = (undefined1 *)((int)param_1 + -1);
      puVar5 = (undefined4 *)((int)param_2 + param_3);
      puVar1 = param_2;
      do {
        param_2 = (undefined4 *)((int)puVar1 + 1);
        puVar2 = puVar2 + 1;
        *puVar2 = *(undefined1 *)puVar1;
        puVar1 = param_2;
      } while (param_2 != puVar5);
      param_1 = (undefined4 *)(param_3 + (int)param_1);
    }
    if (3 < uVar7) {
      puVar1 = param_2 + -1;
      uVar7 = uVar6;
      puVar5 = param_1;
      do {
        puVar1 = puVar1 + 1;
        uVar7 = uVar7 - 1;
        *puVar5 = *puVar1;
        puVar5 = puVar5 + 1;
      } while (uVar7 != 0);
      param_2 = param_2 + uVar6;
      param_1 = param_1 + uVar6;
    }
    if (uVar4 != 0) {
      puVar2 = (undefined1 *)((int)param_1 + -1);
      puVar1 = param_2;
      do {
        puVar5 = (undefined4 *)((int)puVar1 + 1);
        puVar2 = puVar2 + 1;
        *puVar2 = *(undefined1 *)puVar1;
        puVar1 = puVar5;
      } while (puVar5 != (undefined4 *)(uVar4 + (int)param_2));
    }
  }
  else {
    param_1 = (undefined4 *)((int)param_1 + param_3);
    param_2 = (undefined4 *)((int)param_2 + param_3);
    if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
      uVar6 = param_3 >> 2;
      uVar4 = param_3 & 3;
      uVar7 = param_3;
    }
    else {
      if (((((uint)param_1 ^ (uint)param_2) & 3) == 0) && (4 < param_3)) {
        uVar3 = (uint)param_2 & 3;
        uVar7 = param_3 - uVar3;
        uVar6 = uVar7 >> 2;
        uVar4 = uVar7 & 3;
      }
      else {
        uVar4 = 0;
        uVar6 = 0;
        uVar7 = 0;
        uVar3 = param_3;
      }
      puVar5 = (undefined4 *)((int)param_2 - uVar3);
      puVar1 = param_1;
      do {
        param_2 = (undefined4 *)((int)param_2 + -1);
        puVar1 = (undefined4 *)((int)puVar1 + -1);
        *(undefined1 *)puVar1 = *(undefined1 *)param_2;
      } while (param_2 != puVar5);
      param_1 = (undefined4 *)((int)param_1 - uVar3);
    }
    puVar1 = param_2;
    uVar3 = uVar6;
    puVar5 = param_1;
    if (3 < uVar7) {
      do {
        uVar3 = uVar3 - 1;
        puVar5[-1] = puVar1[-1];
        puVar1 = puVar1 + -1;
        puVar5 = puVar5 + -1;
      } while (uVar3 != 0);
      param_2 = param_2 + -uVar6;
      param_1 = param_1 + -uVar6;
    }
    if (uVar4 != 0) {
      puVar1 = (undefined4 *)((int)param_1 - uVar4);
      do {
        param_2 = (undefined4 *)((int)param_2 + -1);
        param_1 = (undefined4 *)((int)param_1 + -1);
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
      } while (param_1 != puVar1);
      return;
    }
  }
  return;
}



// ===========================================================
// Function: FUN_0410f0a4 at 0410f0a4
// ===========================================================

int FUN_0410f0a4(byte *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  
  if (param_3 != 0) {
    pbVar2 = param_1;
    do {
      pbVar1 = pbVar2 + 1;
      if ((uint)*pbVar2 != (uint)*param_2) {
        return (uint)*pbVar2 - (uint)*param_2;
      }
      pbVar2 = pbVar1;
      param_2 = param_2 + 1;
    } while (pbVar1 != param_1 + param_3);
  }
  return 0;
}



