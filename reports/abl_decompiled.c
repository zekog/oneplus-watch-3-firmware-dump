// ===========================================================
// Function at 0x2b35c: FUN_0002b35c
// ===========================================================

/* WARNING: Removing unreachable block (ram,0x0002b434) */
/* WARNING: Removing unreachable block (ram,0x0002b43c) */
/* WARNING: Removing unreachable block (ram,0x0002b450) */
/* WARNING: Removing unreachable block (ram,0x0002b45c) */
/* WARNING: Removing unreachable block (ram,0x0002b468) */
/* WARNING: Removing unreachable block (ram,0x0002b474) */
/* WARNING: Removing unreachable block (ram,0x0002b47c) */
/* WARNING: Removing unreachable block (ram,0x0002b488) */
/* WARNING: Removing unreachable block (ram,0x0002b494) */
/* WARNING: Removing unreachable block (ram,0x0002b554) */
/* WARNING: Removing unreachable block (ram,0x0002b4a4) */
/* WARNING: Removing unreachable block (ram,0x0002b4b8) */
/* WARNING: Removing unreachable block (ram,0x0002b4c0) */
/* WARNING: Removing unreachable block (ram,0x0002b4cc) */
/* WARNING: Removing unreachable block (ram,0x0002b55c) */
/* WARNING: Removing unreachable block (ram,0x0002b4e4) */
/* WARNING: Removing unreachable block (ram,0x0002b4f8) */
/* WARNING: Removing unreachable block (ram,0x0002b500) */

void FUN_0002b35c(void)

{
  undefined1 in_ZR;
  char cVar1;
  int iVar2;
  char *pcVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  pcVar3 = (char *)FUN_0002bb00();
  if (*pcVar3 == '\0') {
    iVar2 = FUN_0000c908();
    in_ZR = iVar2 == 2;
    if ((!(bool)in_ZR) || (lVar4 = FUN_0002bb1c(), lVar4 == 0)) {
      FUN_0002bb14();
      lVar4 = FUN_0002ba40();
      if (lVar4 == 0) {
        cVar1 = FUN_0002bab0();
        in_ZR = cVar1 == '\0';
        if (!(bool)in_ZR) {
          cVar1 = FUN_00006c64();
          if ((cVar1 == '\0') && (cVar1 = FUN_0002ba04(), cVar1 != '\0')) {
            FUN_0000ab00();
            FUN_0002b9f0();
          }
          uVar5 = FUN_0002ba04();
          in_ZR = (uVar5 & 0xff) == 0;
          if (!(bool)in_ZR) {
            FUN_0002ba8c(uVar5,"Error in loading Data from misc partition\n");
          }
        }
      }
      else {
        cVar1 = FUN_00001bcc();
        in_ZR = cVar1 == '\0';
        if (!(bool)in_ZR) {
          cVar1 = FUN_00006c64();
          if ((cVar1 == '\0') && (cVar1 = FUN_0002ba04(), cVar1 != '\0')) {
            FUN_0000ab00();
            FUN_0002b9f0();
          }
          cVar1 = FUN_0002ba04();
          in_ZR = cVar1 == '\0';
          if (!(bool)in_ZR) {
            FUN_0002ba9c();
          }
        }
      }
    }
  }
  FUN_0002ba1c();
  if (!(bool)in_ZR) {
                    /* WARNING: Subroutine does not return */
    FUN_0000147c();
  }
  FUN_0002baf0();
  return;
}


// ===========================================================
// Function at 0x5780c: FUN_0005780c
// ===========================================================

void FUN_0005780c(void)

{
  undefined1 in_ZR;
  char cVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  lVar2 = FUN_00058848(0x70000);
  if (lVar2 == 0) {
    cVar1 = FUN_00001bcc();
    in_ZR = cVar1 == '\0';
    if (!(bool)in_ZR) {
      cVar1 = FUN_00006c64();
      if ((cVar1 == '\0') && (cVar1 = FUN_00058400(), cVar1 != '\0')) {
        FUN_0000ab00();
        FUN_000583cc();
      }
      uVar3 = FUN_00058400();
      in_ZR = (uVar3 & 0xff) == 0;
      if (!(bool)in_ZR) {
        FUN_0005847c(uVar3,"rebooting the device to fastbootd\n");
      }
    }
    FUN_00058440();
    FUN_00058930();
  }
  FUN_00058388();
  if (!(bool)in_ZR) {
                    /* WARNING: Subroutine does not return */
    FUN_0000147c();
  }
  FUN_000585d4();
  return;
}


// ===========================================================
// Function at 0x57774: func_57774
// ===========================================================

void func_57774(void)

{
  undefined1 in_ZR;
  char cVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  lVar2 = FUN_00058848(0x70000);
  if (lVar2 == 0) {
    cVar1 = FUN_00001bcc();
    in_ZR = cVar1 == '\0';
    if (!(bool)in_ZR) {
      cVar1 = FUN_00006c64();
      if ((cVar1 == '\0') && (cVar1 = FUN_00058400(), cVar1 != '\0')) {
        FUN_0000ab00();
        FUN_000583cc();
      }
      uVar3 = FUN_00058400();
      in_ZR = (uVar3 & 0xff) == 0;
      if (!(bool)in_ZR) {
        FUN_0005847c(uVar3,"rebooting the device to recovery\n");
      }
    }
    FUN_00058440();
    FUN_00058930();
  }
  FUN_00058388();
  if (!(bool)in_ZR) {
                    /* WARNING: Subroutine does not return */
    FUN_0000147c();
  }
  FUN_000585d4();
  return;
}


