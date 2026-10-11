// ===========================================================
// Function: __on_dlclose at 000166d4
// ===========================================================

void __on_dlclose(void)

{
  __ThumbV7PILongThunk___cxa_finalize(DAT_000166dc + 0x166da);
  return;
}



// ===========================================================
// Function: __emutls_unregister_key at 000166e0
// ===========================================================

void __emutls_unregister_key(void)

{
  return;
}



// ===========================================================
// Function: __on_dlclose_late at 000166e2
// ===========================================================

void __on_dlclose_late(void)

{
  return;
}



// ===========================================================
// Function: findDownloadBinByName at 000166e8
// ===========================================================

undefined4 findDownloadBinByName(char *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  snprintf(param_1,0xffffffff,param_2,DAT_00016724 + 0x16704,param_3,param_4);
  iVar1 = access(param_1,0);
  if (iVar1 != -1) {
    printf((char *)(DAT_00016728 + 0x1671a),param_1);
    uVar2 = 0;
  }
  return uVar2;
}



// ===========================================================
// Function: snprintf at 0001672c
// ===========================================================

/* snprintf(char*, unsigned int pass_object_size1, char const*, ...) */

void snprintf(char *param_1,uint param_2,char *param_3,...)

{
  int iVar1;
  undefined4 in_r3;
  
  iVar1 = **(int **)(DAT_00016764 + 0x16738);
  __vsnprintf_chk(param_1,param_3,0,param_2,in_r3,&stack0x00000000,&stack0x00000000);
  if (**(int **)(DAT_00016768 + 0x16756) != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// ===========================================================
// Function: findDownloadBinByHeaderAndTail at 0001676c
// ===========================================================

undefined4
findDownloadBinByHeaderAndTail
          (char *param_1,char *param_2,char *param_3,char *param_4,char *param_5)

{
  DIR *__dirp;
  dirent *pdVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  size_t __n;
  undefined4 uVar5;
  char *__s;
  
  printf((char *)(DAT_0001684c + 0x16786),param_4,param_5);
  __dirp = opendir(param_3);
  if (__dirp == (DIR *)0x0) {
    uVar5 = 0xffffffff;
  }
  else {
    do {
      do {
        do {
          do {
            do {
              pdVar1 = readdir(__dirp);
              if (pdVar1 == (dirent *)0x0) {
                uVar5 = 0xffffffff;
                goto LAB_00016836;
              }
            } while (pdVar1->d_name[7] != '\b');
            __s = pdVar1->d_name + 8;
            sVar2 = strlen(__s);
            sVar3 = strlen(param_4);
          } while (sVar2 < sVar3);
          sVar2 = strlen(param_4);
          iVar4 = strncmp(__s,param_4,sVar2);
        } while (iVar4 != 0);
        sVar2 = strlen(__s);
        sVar3 = strlen(param_5);
      } while (sVar2 < sVar3);
      sVar2 = strlen(__s);
      sVar3 = strlen(param_5);
      __n = strlen(param_5);
      iVar4 = strncmp(__s + (sVar2 - sVar3),param_5,__n);
    } while (iVar4 != 0);
    snprintf(param_1,0xffffffff,param_2,DAT_00016850 + 0x1681a,param_3,__s);
    uVar5 = 0;
    (param_2 + (int)param_1)[-1] = '\0';
    printf((char *)(DAT_00016854 + 0x1682e),param_1);
LAB_00016836:
    closedir(__dirp);
  }
  return uVar5;
}



// ===========================================================
// Function: direntPathListInit at 00016858
// ===========================================================

void direntPathListInit(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  
  iVar3 = 0;
  piVar6 = *(int **)(DAT_000168c8 + 0x16868);
  iVar1 = *piVar6;
  iVar4 = *(int *)(DAT_000168cc + 0x16874);
  iVar2 = DAT_000168d0 + 0x1687a;
  iVar5 = DAT_000168d8 + 0x16884;
  pcVar7 = *(char **)(DAT_000168d4 + 0x16882);
  do {
    if (iVar1 == *(int *)(iVar4 + iVar3)) {
      iVar1 = iVar4 + iVar3 + 4;
      snprintf(param_1,0xffffffff,(char *)0x96,iVar2,iVar1);
      snprintf(pcVar7,0x10,(char *)0x10,iVar5,iVar1);
      iVar1 = *piVar6;
    }
    iVar3 = iVar3 + 0x14;
  } while (iVar3 != 0x50);
  __ThumbV7PILongThunk_printf((char *)(DAT_000168dc + 0x168c0),param_1);
  return;
}



// ===========================================================
// Function: FindDownloadBin at 000168e0
// ===========================================================

void FindDownloadBin(undefined1 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_170;
  undefined1 local_16c;
  char local_168 [4];
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined1 auStack_148 [304];
  int local_18;
  
  local_18 = **(int **)(DAT_000169e8 + 0x168f6);
  __aeabi_memcpy8(auStack_148,(void *)(DAT_000169ec + 0x16902),300);
  uStack_164 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_160 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_15c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_168[0] = '\0';
  local_168[1] = '\0';
  local_168[2] = '\0';
  local_168[3] = '\0';
  local_158 = 0;
  local_16c = 0;
  local_170 = 0x6e69622e;
  uStack_154 = uStack_164;
  uStack_150 = uStack_160;
  uStack_14c = uStack_15c;
  direntPathListInit(auStack_148);
  if (0xf < param_3) {
    if (param_3 == 0x10) {
      iVar2 = DAT_00016a0c + 0x169a2;
    }
    else if (param_3 == 0x11) {
      iVar2 = DAT_00016a10 + 0x169aa;
    }
    else {
      if (param_3 != 0x80) goto switchD_00016930_default;
      iVar2 = DAT_000169f0 + 0x16956;
    }
    goto LAB_000169a8;
  }
  switch(param_3) {
  case 0:
    iVar2 = DAT_00016a14 + 0x16942;
    goto LAB_000169a8;
  case 1:
    iVar2 = DAT_000169f4 + 0x1695c;
    break;
  case 2:
    iVar2 = DAT_00016a08 + 0x16964;
LAB_000169a8:
    iVar2 = findDownloadBinByName(param_1,param_2,auStack_148,iVar2);
    goto LAB_000169b0;
  case 3:
    iVar2 = DAT_00016a00 + 0x1696a;
    break;
  case 4:
    iVar2 = DAT_00016a04 + 0x16970;
    break;
  default:
switchD_00016930_default:
    puts((char *)(DAT_00016a18 + 0x169e4));
    goto LAB_000169b2;
  }
  snprintf(local_168,0x20,(char *)0x20,DAT_000169fc + 0x16986,
           *(undefined4 *)(DAT_000169f8 + 0x1697c),iVar2);
  iVar2 = findDownloadBinByHeaderAndTail(param_1,param_2,auStack_148,local_168,&local_170);
LAB_000169b0:
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
LAB_000169b2:
    printf((char *)(DAT_00016a1c + 0x169ba),param_3);
    *param_1 = 0;
    uVar1 = 0xffffffff;
  }
  if (**(int **)(DAT_00016a20 + 0x169d0) == local_18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}



// ===========================================================
// Function: dlImg at 00016a24
// ===========================================================

void dlImg(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *__s;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined1 auStack_e0 [204];
  int local_14;
  
  local_14 = **(int **)(DAT_00016aec + 0x16a32);
  local_e8 = 0;
  local_e4 = 0;
  printf((char *)(DAT_00016af0 + 0x16a42),param_1);
  __aeabi_memclr8(auStack_e0,200);
  iVar1 = FindDownloadBin(auStack_e0,200,param_1);
  if (iVar1 < 0) {
    printf((char *)(DAT_00016af4 + 0x16ab2),param_1);
  }
  else {
    printf((char *)(DAT_00016af8 + 0x16a68),auStack_e0);
    iVar1 = get_res_size(auStack_e0,&local_e8);
    if (iVar1 < 0) {
      __s = (char *)(DAT_00016afc + 0x16abc);
    }
    else {
      iVar1 = send_dl_request((int)(char)param_1,local_e8);
      if (iVar1 < 0) {
        __s = (char *)(DAT_00016b00 + 0x16ac2);
      }
      else {
        iVar1 = update_res_file(auStack_e0,param_1 & 0xff,&local_e4);
        if (iVar1 < 0) {
          __s = (char *)(DAT_00016b04 + 0x16ac8);
        }
        else {
          iVar1 = verity_res_file(param_1 & 0xff,local_e4);
          if (-1 < iVar1) {
            uVar2 = 0;
            goto LAB_00016ad4;
          }
          __s = (char *)(DAT_00016b08 + 0x16ace);
        }
      }
    }
    puts(__s);
  }
  uVar2 = 0xffffffff;
LAB_00016ad4:
  if (**(int **)(DAT_00016b0c + 0x16adc) != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: get_prj_number at 00016b10
// ===========================================================

void get_prj_number(void)

{
  int iVar1;
  char acStack_68 [92];
  int local_c;
  
  local_c = **(int **)(DAT_00016b68 + 0x16b1e);
  __aeabi_memclr8(acStack_68,0x5c);
  property_get(DAT_00016b6c + 0x16b32,acStack_68,DAT_00016b70 + 0x16b34);
  iVar1 = atoi(acStack_68);
  printf((char *)(DAT_00016b74 + 0x16b46),iVar1);
  **(int **)(DAT_00016b78 + 0x16b4e) = iVar1;
  if (**(int **)(DAT_00016b7c + 0x16b58) != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_c);
  }
  return;
}



// ===========================================================
// Function: get_boot1_ota at 00016b80
// ===========================================================

bool get_boot1_ota(void)

{
  int iVar1;
  
  iVar1 = property_get_bool(DAT_00016b94 + 0x16b8a,0);
  return iVar1 != 0;
}



// ===========================================================
// Function: deinit at 00016b98
// ===========================================================

void deinit(void)

{
  setUpgradeGpio(0);
  setMcuRstGpio();
  deinitGpio();
  __ThumbV7PILongThunk_pthread_mutex_destroy((pthread_mutex_t *)(DAT_00016bb4 + 0x16bae));
  return;
}



// ===========================================================
// Function: get_mcu_ver at 00016bb8
// ===========================================================

void get_mcu_ver(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  void *__dest;
  undefined4 local_238;
  undefined4 uStack_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  undefined4 local_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined1 auStack_218 [512];
  int local_18;
  
  local_18 = **(int **)(DAT_00016c8c + 0x16bc6);
  iVar1 = send_dcc_spi_msg(0,0);
  if (iVar1 < 1) {
    printf((char *)(DAT_00016c90 + 0x16bdc),iVar1);
  }
  iVar3 = *(int *)(DAT_00016c94 + 0x16be4);
  iVar1 = rcv_dcc_msg_response(iVar3);
  if (iVar1 < 1) {
    printf((char *)(DAT_00016c98 + 0x16bf8),iVar1);
  }
  __aeabi_memclr8(auStack_218,0x200);
  uStack_234 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_230 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_22c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_238 = 0;
  local_228 = 0;
  uStack_224 = uStack_234;
  uStack_220 = uStack_230;
  uStack_21c = uStack_22c;
  pb_istream_from_buffer(&local_238,iVar3 + 4,iVar1 + -4);
  iVar1 = pb_decode(&local_238,*(undefined4 *)(DAT_00016c9c + 0x16c28),auStack_218);
  if (iVar1 == 0) {
    puts((char *)(DAT_00016ca0 + 0x16c6c));
    uVar2 = 0xffffffff;
  }
  else {
    __dest = *(void **)(DAT_00016ca4 + 0x16c3c);
    __aeabi_memcpy8(__dest,auStack_218,0x162);
    printf((char *)(DAT_00016ca8 + 0x16c60),(int)__dest + 0x22,(int)__dest + 0x42,
           (int)__dest + 0x122,(int)__dest + 0x82,(int)__dest + 0xa2);
    uVar2 = 0;
  }
  if (**(int **)(DAT_00016cac + 0x16c7a) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: read_config_txt at 00016cb0
// ===========================================================

void read_config_txt(void)

{
  int iVar1;
  FILE *__stream;
  char *__format;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  char *__format_00;
  char local_128 [4];
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  char acStack_e8 [200];
  int local_20;
  
  local_20 = **(int **)(DAT_00016dac + 0x16cc0);
  __aeabi_memclr8(acStack_e8,200);
  puVar5 = (undefined4 *)(DAT_00016db0 + 0x16cd2);
  snprintf(acStack_e8,200,(char *)0xc8,DAT_00016db8 + 0x16ce4,*puVar5,DAT_00016db4 + 0x16cd8);
  iVar1 = access(acStack_e8,0);
  if (iVar1 < 0) {
    printf((char *)(DAT_00016dd0 + 0x16d84),*puVar5);
  }
  else {
    uStack_124 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_120 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_11c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    local_128[0] = '\0';
    local_128[1] = '\0';
    local_128[2] = '\0';
    local_128[3] = '\0';
    local_118 = 0;
    local_108 = 0;
    local_f8 = 0;
    uStack_114 = uStack_124;
    uStack_110 = uStack_120;
    uStack_10c = uStack_11c;
    uStack_104 = uStack_124;
    uStack_100 = uStack_120;
    uStack_fc = uStack_11c;
    uStack_f4 = uStack_124;
    uStack_f0 = uStack_120;
    uStack_ec = uStack_11c;
    __stream = fopen(acStack_e8,(char *)(DAT_00016dbc + 0x16d10));
    if (__stream != (FILE *)0x0) {
      iVar6 = 1;
      __format = (char *)(DAT_00016dc8 + 0x16d26);
      iVar1 = DAT_00016dc0 + 0x16d28;
      __format_00 = (char *)(DAT_00016dc4 + 0x16d2a);
      do {
        pcVar2 = fgets(local_128,0x40,__stream);
        if (pcVar2 != (char *)0x0) {
          sscanf(local_128,__format,iVar1);
        }
        printf(__format_00,iVar6,iVar1);
        iVar6 = iVar6 + 1;
        iVar1 = iVar1 + 0x28;
      } while (iVar6 != 8);
      fclose(__stream);
      iVar1 = 0;
      iVar6 = DAT_00016dcc + 0x16d62;
      do {
        iVar4 = 0;
        do {
          if (*(char *)(iVar6 + iVar4) == ':') {
            *(undefined1 *)(iVar6 + iVar4) = 0x5f;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 != 0x23);
        iVar1 = iVar1 + 1;
        iVar6 = iVar6 + 0x28;
      } while (iVar1 != 7);
      uVar3 = 0;
      goto LAB_00016d94;
    }
    puts((char *)(DAT_00016dd4 + 0x16d8e));
  }
  uVar3 = 0xffffffff;
LAB_00016d94:
  if (**(int **)(DAT_00016dd8 + 0x16d9c) != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



// ===========================================================
// Function: thread_exit_handler at 00016ddc
// ===========================================================

void thread_exit_handler(void)

{
  puts((char *)(DAT_00016dec + 0x16de4));
                    /* WARNING: Subroutine does not return */
  pthread_exit((void *)0x0);
}



// ===========================================================
// Function: timeout_handler at 00016df0
// ===========================================================

void timeout_handler(void)

{
  **(undefined4 **)(DAT_00016e18 + 0x16dfa) = 1;
  pthread_kill(**(pthread_t **)(DAT_00016e1c + 0x16e04),10);
  __ThumbV7PILongThunk_puts((char *)(DAT_00016e20 + 0x16e10));
  return;
}



// ===========================================================
// Function: recovery_dl_bootloader at 00016e24
// ===========================================================

void recovery_dl_bootloader(void)

{
  int iVar1;
  char *__format;
  _union_1051 local_1b8;
  sigset_t sStack_1b4;
  undefined1 auStack_e0 [204];
  int local_14;
  
  local_14 = **(int **)(DAT_00016f0c + 0x16e32);
  __aeabi_memclr8(auStack_e0,200);
  __aeabi_memclr8(sStack_1b4.__val + 3,200);
  sStack_1b4.__val[0] = *(ulong *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  sStack_1b4.__val[1] = *(ulong *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  sStack_1b4.__val[2] = *(ulong *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_1b8.sa_handler = (__sighandler_t)0x0;
  sigemptyset(&sStack_1b4);
  sStack_1b4.__val[1] = 0;
  local_1b8 = *(_union_1051 *)(DAT_00016f10 + 0x16e64);
  sigaction(10,(sigaction *)&local_1b8,(sigaction *)0x0);
  signal(0xe,*(__sighandler_t *)(DAT_00016f14 + 0x16e72));
  alarm(0xf);
  iVar1 = FindDownloadBin(auStack_e0,200,0);
  if (iVar1 < 0) {
    iVar1 = 0;
    __format = (char *)(DAT_00016f18 + 0x16edc);
  }
  else {
    iVar1 = uart_init();
    if (-1 < iVar1) {
      iVar1 = FindDownloadBin(sStack_1b4.__val + 3,200,0x80);
      if (iVar1 < 0) {
        puts((char *)(DAT_00016f20 + 0x16f08));
      }
      else {
        iVar1 = download_programmer(sStack_1b4.__val + 3);
        if ((0 < iVar1) && (iVar1 = download_bootloader_bin(auStack_e0), 0 < iVar1)) {
          close_uart();
          alarm(0);
          **(undefined4 **)(DAT_00016f24 + 0x16ed0) = 1;
        }
      }
      goto LAB_00016eea;
    }
    __format = (char *)(DAT_00016f1c + 0x16ee4);
  }
  printf(__format,iVar1);
LAB_00016eea:
  if (**(int **)(DAT_00016f28 + 0x16ef2) == local_14) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_14);
}



// ===========================================================
// Function: recoveryDownload at 00016f2c
// ===========================================================

void recoveryDownload(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  __start_routine *__start_routine;
  char *pcVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  pthread_t *__newthread;
  pthread_mutex_t *__mutex;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int *piVar19;
  bool bVar20;
  void *local_2c;
  int local_28;
  
  local_28 = **(int **)(DAT_000171dc + 0x16f3a);
  local_2c = (void *)0x0;
  uVar17 = 0;
  do {
    uVar2 = get_mcu_ver();
    if (uVar2 < 0x80000000) break;
    bVar20 = uVar17 < 5;
    uVar17 = uVar17 + 1;
  } while (bVar20);
  piVar12 = (int *)(DAT_000171e0 + 0x16f5a);
  if ((int)uVar2 < 0) {
    puts((char *)(DAT_000171ec + 0x16ffc));
    iVar4 = *piVar12;
    iVar3 = 0;
    do {
      iVar9 = iVar3 * 8;
      iVar3 = iVar3 + 1;
      *(undefined4 *)(iVar4 + iVar9 + 4) = 1;
    } while (iVar3 != 5);
  }
  else {
    iVar15 = *piVar12;
    iVar14 = 0;
    iVar13 = DAT_000171e4 + 0x16f68;
    iVar3 = DAT_000171e4 + 0x17008;
    iVar16 = DAT_000171e4 + 0x16fb8;
    iVar18 = DAT_000171e4 + 0x16f90;
    iVar4 = *(int *)(DAT_000171e8 + 0x16f7a);
    iVar9 = DAT_000171e4 + 0x17030;
    iVar10 = DAT_000171e4 + 0x16fe0;
    do {
      iVar5 = *(int *)(iVar15 + iVar14 * 8);
      switch(iVar5) {
      case 1:
        iVar6 = iVar4 + 0x22;
        iVar11 = iVar13;
        break;
      case 2:
        iVar6 = iVar4 + 0x62;
        iVar11 = iVar10;
        break;
      case 3:
        iVar6 = iVar4 + 0x42;
        iVar11 = iVar16;
        break;
      case 4:
        iVar6 = iVar4 + 0x122;
        iVar11 = iVar18;
        break;
      default:
        iVar6 = iVar4 + 0xa2;
        iVar11 = iVar3;
        if ((iVar5 == 0x10) || (iVar6 = iVar4 + 0x82, iVar11 = iVar9, iVar5 == 0x11)) break;
        goto LAB_00016fe8;
      }
      iVar5 = compare_version(iVar6,iVar11);
      if (iVar5 != 0) {
LAB_00016fe8:
        *(undefined4 *)(iVar15 + iVar14 * 8 + 4) = 1;
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 != 5);
  }
  iVar4 = 0;
  iVar3 = *piVar12;
  *(undefined4 *)(iVar3 + 0x24) = 0;
  printf((char *)(DAT_000171f0 + 0x1702a),*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar3 + 0xc),
         *(undefined4 *)(iVar3 + 0x14),*(undefined4 *)(iVar3 + 0x1c),0);
  bVar1 = true;
  bVar20 = false;
  do {
    if (bVar20) {
      bVar20 = true;
    }
    else {
      bVar20 = *(int *)(iVar3 + iVar4 * 8 + 4) == -1;
    }
    if (bVar1) {
      bVar1 = *(int *)(iVar3 + iVar4 * 8 + 4) == 0;
    }
    else {
      bVar1 = false;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 5);
  if (bVar20) {
    pcVar7 = (char *)(DAT_000171f4 + 0x17068);
  }
  else {
    if (bVar1) {
      pcVar7 = (char *)(DAT_000171f8 + 0x17078);
LAB_000171b0:
      puts(pcVar7);
      goto LAB_000171b6;
    }
    local_2c = (void *)setUpgradeGpio(1);
    if (-1 < (int)local_2c) {
      uVar17 = 0;
      iVar4 = property_get_bool(DAT_00017200 + 0x17092,0);
      if (iVar4 != 0) {
        local_2c = (void *)0x0;
        piVar12 = *(int **)(DAT_00017204 + 0x170a4);
        piVar19 = *(int **)(DAT_00017208 + 0x170aa);
        __newthread = *(pthread_t **)(DAT_0001720c + 0x170b2);
        __start_routine = *(__start_routine **)(DAT_00017210 + 0x170b8);
        pcVar7 = (char *)(DAT_00017214 + 0x170c0);
        pcVar8 = (char *)(DAT_00017218 + 0x170c6);
        uVar2 = 0;
        do {
          uVar17 = uVar2;
          *piVar12 = 0;
          *piVar19 = 0;
          iVar4 = pthread_create(__newthread,(pthread_attr_t *)0x0,__start_routine,(void *)0x0);
          if (iVar4 != 0) {
            puts(pcVar8);
          }
          pthread_join(*__newthread,&local_2c);
          if ((*piVar12 != 0) && (*piVar19 == 0)) goto LAB_00017130;
          uVar2 = uVar17 + 1;
          printf(pcVar7,local_2c,uVar2);
        } while ((uVar17 < 4) && ((int)local_2c < 1));
        if (3 < uVar17) {
          printf((char *)(DAT_00017234 + 0x1711e),local_2c,uVar2);
          goto LAB_000171b6;
        }
        uVar17 = 0;
      }
LAB_00017130:
      pcVar7 = (char *)(DAT_00017220 + 0x1713a);
      __mutex = (pthread_mutex_t *)(DAT_0001721c + 0x1713c);
      pcVar8 = (char *)(DAT_00017224 + 0x1713e);
LAB_0001713e:
      local_2c = (void *)setMcuRstGpio();
      if ((int)local_2c < 0) {
        pcVar7 = (char *)(DAT_00017228 + 0x171d6);
      }
      else {
        local_2c = (void *)handshake();
        if (-1 < (int)local_2c) {
          iVar4 = 0;
          do {
            if (*(int *)(iVar3 + iVar4 * 8 + 4) != 0) {
              pthread_mutex_lock(__mutex);
              local_2c = (void *)dlImg(*(undefined4 *)(iVar3 + iVar4 * 8));
              if ((int)local_2c < 0) goto LAB_00017180;
              pthread_mutex_unlock(__mutex);
            }
            iVar4 = iVar4 + 1;
            if (iVar4 == 5) {
              pcVar7 = (char *)(DAT_0001722c + 0x171b2);
              goto LAB_000171b0;
            }
          } while( true );
        }
        pcVar7 = (char *)((int)&DAT_000171dc + DAT_00017238);
      }
      goto LAB_00017066;
    }
    pcVar7 = (char *)(DAT_000171fc + 0x17128);
  }
LAB_00017066:
  puts(pcVar7);
LAB_000171b6:
  if (**(int **)(DAT_00017230 + 0x171be) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_28);
LAB_00017180:
  printf(pcVar7,*(undefined4 *)(iVar3 + iVar4 * 8),0xffffffff);
  pthread_mutex_unlock(__mutex);
  uVar17 = uVar17 + 1;
  printf(pcVar8,uVar17);
  if (uVar17 == 6) goto LAB_000171b6;
  goto LAB_0001713e;
}



// ===========================================================
// Function: try_update_mcu_package at 0001723c
// ===========================================================

void try_update_mcu_package(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char acStack_220 [512];
  int local_20;
  
  local_20 = **(int **)(DAT_00017314 + 0x17254);
  __aeabi_memclr8(acStack_220,0x200);
  puts((char *)(DAT_00017318 + 0x17264));
  get_prj_number();
  iVar3 = 0;
  piVar5 = *(int **)(DAT_0001731c + 0x17272);
  iVar1 = *piVar5;
  iVar4 = DAT_00017324 + 0x1727e;
  iVar2 = *(int *)(DAT_00017320 + 0x1727c);
  do {
    if (iVar1 == *(int *)(iVar2 + iVar3)) {
      snprintf(acStack_220,0x200,(char *)0x200,iVar4,param_1,iVar2 + iVar3 + 4);
      iVar1 = *piVar5;
    }
    iVar3 = iVar3 + 0x14;
  } while (iVar3 != 0x50);
  *(char **)(DAT_00017328 + 0x172aa) = acStack_220;
  iVar1 = read_config_txt();
  if (iVar1 != 0) goto LAB_000172f8;
  iVar1 = pthread_mutex_init((pthread_mutex_t *)(DAT_0001732c + 0x172be),(pthread_mutexattr_t *)0x0)
  ;
  if (iVar1 == 0) {
    iVar1 = recoveryDownload();
    if (iVar1 < 0) goto LAB_000172ca;
  }
  else {
    puts((char *)(DAT_00017330 + 0x172c8));
LAB_000172ca:
    puts((char *)(DAT_00017334 + 0x172d0));
  }
  setUpgradeGpio(0);
  setMcuRstGpio();
  deinitGpio();
  pthread_mutex_destroy((pthread_mutex_t *)(DAT_00017338 + 0x172f6));
LAB_000172f8:
  if (**(int **)(DAT_0001733c + 0x17300) == local_20) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_20);
}



// ===========================================================
// Function: compare_version at 00017340
// ===========================================================

void compare_version(char *param_1,char *param_2)

{
  size_t sVar1;
  size_t sVar2;
  undefined4 uVar3;
  size_t sVar4;
  int iVar5;
  bool bVar6;
  char local_98 [4];
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  char local_58 [4];
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int local_14;
  
  local_14 = **(int **)(DAT_00017420 + 0x1734e);
  sVar1 = strlen(param_2);
  uStack_94 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_90 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_8c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_58[0] = '\0';
  local_58[1] = '\0';
  local_58[2] = '\0';
  local_58[3] = '\0';
  local_48 = 0;
  local_38 = 0;
  local_28 = 0;
  local_98[0] = '\0';
  local_98[1] = '\0';
  local_98[2] = '\0';
  local_98[3] = '\0';
  local_88 = 0;
  local_78 = 0;
  local_68 = 0;
  uStack_84 = uStack_94;
  uStack_80 = uStack_90;
  uStack_7c = uStack_8c;
  uStack_74 = uStack_94;
  uStack_70 = uStack_90;
  uStack_6c = uStack_8c;
  uStack_64 = uStack_94;
  uStack_60 = uStack_90;
  uStack_5c = uStack_8c;
  uStack_54 = uStack_94;
  uStack_50 = uStack_90;
  uStack_4c = uStack_8c;
  uStack_44 = uStack_94;
  uStack_40 = uStack_90;
  uStack_3c = uStack_8c;
  uStack_34 = uStack_94;
  uStack_30 = uStack_90;
  uStack_2c = uStack_8c;
  uStack_24 = uStack_94;
  uStack_20 = uStack_90;
  uStack_1c = uStack_8c;
  sVar2 = strcspn(param_2,(char *)(DAT_00017424 + 0x1738a));
  bVar6 = sVar1 == sVar2;
  sVar4 = sVar1 - sVar2;
  if ((int)sVar1 > (int)sVar2) {
    bVar6 = sVar2 == 0;
    sVar4 = sVar2;
  }
  if (bVar6 || (int)sVar4 < 0 != ((int)sVar1 <= (int)sVar2 && SBORROW4(sVar1,sVar2))) {
    puts((char *)(DAT_00017428 + 0x1739a));
    uVar3 = 0xffffffff;
  }
  else {
    __strncpy_chk(local_58,param_2 + sVar2 + 1,sVar1 - sVar2,0x40);
    sVar4 = strlen(param_1);
    __strncpy_chk(local_98,param_1,sVar4,0x40);
    printf((char *)(DAT_0001742c + 0x173ce),local_58);
    printf((char *)(DAT_00017430 + 0x173d8),local_98);
    iVar5 = strcmp(local_58,local_98);
    if ((iVar5 < 1) && (iVar5 = memcmp(local_98,(void *)(DAT_00017434 + 0x173f0),7), iVar5 != 0)) {
      puts((char *)(DAT_0001743c + 0x173fa));
      uVar3 = 0;
    }
    else {
      puts((char *)(DAT_00017438 + 0x17406));
      uVar3 = 1;
    }
  }
  if (**(int **)(DAT_00017440 + 0x17412) != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



// ===========================================================
// Function: spi_transfer_msg at 00017444
// ===========================================================

void spi_transfer_msg(undefined4 param_1,undefined4 param_2,void *param_3,size_t *param_4)

{
  int iVar1;
  size_t __n;
  undefined4 uVar2;
  byte local_fe28;
  byte local_fe27;
  int local_24;
  
  local_24 = **(int **)(DAT_00017530 + 0x17466);
  __aeabi_memclr8(&local_fe28,0xfe00);
  __memcpy_chk(&local_fe28,param_1,param_2,0xfe00);
  printf((char *)(DAT_00017534 + 0x17490),param_2,(uint)local_fe28,(uint)local_fe27);
  iVar1 = send_spi_msg(&local_fe28,param_2);
  if (iVar1 < 0) {
    puts((char *)(DAT_00017538 + 0x174fc));
  }
  else {
    if (((local_fe27 & 0xfe) == 0x10) && ((local_fe28 & 0xef) == 0x24)) {
      sleep(0x14);
    }
    __aeabi_memset8(&local_fe28,0xfe00,0xff);
    __n = rcv_msg_response(&local_fe28);
    printf((char *)(DAT_0001753c + 0x174dc),__n);
    if (-1 < (int)__n) {
      __aeabi_memcpy8(param_3,&local_fe28,__n);
      uVar2 = 0;
      *param_4 = __n;
      goto LAB_0001750e;
    }
    printf((char *)(DAT_00017540 + 0x17508),__n);
  }
  uVar2 = 0xffffffff;
LAB_0001750e:
  if (**(int **)(DAT_00017544 + 0x1751c) != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: handshake at 00017548
// ===========================================================

void handshake(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_12;
  undefined1 auStack_10 [4];
  int local_c;
  
  local_c = **(int **)(DAT_000175bc + 0x17556);
  local_12 = 0x1000;
  iVar1 = spi_transfer_msg(&local_12,2,&local_12,auStack_10);
  if (iVar1 < 0) {
    puts((char *)(DAT_000175c0 + 0x17592));
  }
  else {
    if ((char)local_12 == '\x01' && local_12._1_1_ == '\0') {
      puts((char *)(DAT_000175c8 + 0x175a0));
      uVar2 = 0;
      goto LAB_000175a4;
    }
    printf((char *)(DAT_000175c4 + 0x17588));
  }
  uVar2 = 0xffffffff;
LAB_000175a4:
  if (**(int **)(DAT_000175cc + 0x175ac) != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: get_res_ver at 000175d0
// ===========================================================

void get_res_ver(char param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_3e;
  char cStack_3d;
  undefined1 auStack_3c [4];
  byte local_38;
  char cStack_37;
  byte bStack_36;
  int iStack_35;
  int iStack_31;
  int iStack_2d;
  uint uStack_29;
  undefined1 uStack_25;
  int iStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined3 uStack_18;
  int local_14;
  
  iStack_24 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_20 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_1c = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_14 = **(int **)(DAT_00017680 + 0x175ea);
  _local_3e = CONCAT11(param_1,0x10);
  local_38 = 0;
  cStack_37 = '\0';
  bStack_36 = 0;
  iStack_35 = iStack_24 << 8;
  iStack_31._1_3_ = (undefined3)uStack_20;
  iStack_31 = CONCAT31(iStack_31._1_3_,(char)((uint)iStack_24 >> 0x18));
  iStack_2d._1_3_ = (undefined3)uStack_1c;
  iStack_2d = CONCAT31(iStack_2d._1_3_,(char)((uint)uStack_20 >> 0x18));
  uStack_29 = uStack_1c >> 0x18;
  uStack_25 = 0;
  uStack_1c = uStack_1c & 0xffffff;
  uStack_18 = 0;
  iVar1 = spi_transfer_msg(&local_3e,2,&local_38,auStack_3c);
  if (iVar1 < 0) {
    puts((char *)(DAT_00017684 + 0x17654));
  }
  else {
    if ((local_38 == 0x11) && (cStack_37 == param_1 && bStack_36 == 0)) {
      puts((char *)(DAT_0001768c + 0x17636));
      *param_2 = iStack_35;
      param_2[1] = iStack_31;
      param_2[2] = iStack_2d;
      param_2[3] = uStack_29;
      uVar2 = 0;
      *(ulonglong *)(param_2 + 4) = CONCAT35((undefined3)uStack_20,CONCAT41(iStack_24,uStack_25));
      *(ulonglong *)(param_2 + 6) = CONCAT35(uStack_18,CONCAT41(uStack_1c,uStack_20._3_1_));
      goto LAB_00017668;
    }
    printf((char *)(DAT_00017688 + 0x17662),(uint)local_38,(uint)bStack_36);
  }
  uVar2 = 0xffffffff;
LAB_00017668:
  if (**(int **)(DAT_00017690 + 0x17670) != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: download_hw_info at 00017694
// ===========================================================

void download_hw_info(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_1c;
  undefined1 local_19;
  undefined2 local_18;
  undefined2 local_16;
  undefined4 local_14;
  undefined1 auStack_10 [4];
  int local_c;
  
  local_c = **(int **)(DAT_00017720 + 0x176a2);
  local_19 = 0x12;
  local_14 = 0;
  local_1c = 0;
  local_18 = param_1;
  local_16 = param_2;
  local_14 = crc32(&local_18,4);
  iVar1 = spi_transfer_msg(&local_19,9,&local_1c,auStack_10);
  if (iVar1 < 0) {
    puts((char *)(DAT_00017724 + 0x176f8));
  }
  else {
    if ((char)local_1c == '\x13' && local_1c._1_1_ == '\0') {
      puts((char *)(DAT_0001772c + 0x17706));
      uVar2 = 0;
      goto LAB_0001770a;
    }
    printf((char *)(DAT_00017728 + 0x176ee));
  }
  uVar2 = 0xffffffff;
LAB_0001770a:
  if (**(int **)(DAT_00017730 + 0x17712) != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: get_res_size at 00017734
// ===========================================================

void get_res_size(char *param_1,__blksize_t *param_2)

{
  int iVar1;
  undefined4 uVar2;
  stat sStack_80;
  int local_14;
  
  local_14 = **(int **)(DAT_00017794 + 0x17746);
  __aeabi_memclr8(&sStack_80,0x68);
  iVar1 = stat(param_1,&sStack_80);
  if (iVar1 < 0) {
    printf((char *)(DAT_00017798 + 0x17778),param_1);
    uVar2 = 0xffffffff;
  }
  else {
    printf((char *)(DAT_0001779c + 0x17766),sStack_80.st_blksize);
    uVar2 = 0;
    *param_2 = sStack_80.st_blksize;
  }
  if (**(int **)(DAT_000177a0 + 0x17786) != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: send_dl_request at 000177a4
// ===========================================================

void send_dl_request(byte param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  byte local_24;
  byte local_23;
  byte local_22;
  uint local_21;
  undefined1 local_1a;
  byte local_19;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 auStack_10 [4];
  int local_c;
  
  local_c = **(int **)(DAT_00017850 + 0x177b4);
  local_14 = 0xfc00;
  local_1a = 0x20;
  local_24 = 0;
  local_23 = 0;
  local_22 = 0;
  local_21 = 0;
  local_19 = param_1;
  local_18 = param_2;
  iVar1 = spi_transfer_msg(&local_1a,10,&local_24,auStack_10);
  if (iVar1 < 0) {
    puts((char *)(DAT_00017854 + 0x17824));
  }
  else {
    if ((local_24 == 0x21) && ((uint)local_23 == (uint)param_1 && local_22 == 0)) {
      uVar3 = local_21;
      if (0xfbff < local_21) {
        uVar3 = 0xfc00;
      }
      **(uint **)(DAT_0001785c + 0x17810) = uVar3;
      printf((char *)(DAT_00017860 + 0x17818));
      uVar2 = 0;
      goto LAB_00017838;
    }
    printf((char *)(DAT_00017858 + 0x17832),(uint)local_24,(uint)local_23,(uint)local_22);
  }
  uVar2 = 0xffffffff;
LAB_00017838:
  if (**(int **)(DAT_00017864 + 0x17840) != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: map_res_file at 00017868
// ===========================================================

void map_res_file(char *param_1,size_t *param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  char *__format;
  int *piVar4;
  stat sStack_88;
  int local_1c;
  
  local_1c = **(int **)(DAT_00017928 + 0x1787c);
  __aeabi_memclr8(&sStack_88,0x68);
  iVar1 = stat(param_1,&sStack_88);
  if (iVar1 < 0) {
    __format = (char *)(DAT_0001792c + 0x178ee);
  }
  else {
    printf((char *)(DAT_00017930 + 0x1789c),sStack_88.st_blksize);
    iVar1 = __open_2(param_1,0);
    piVar4 = *(int **)(DAT_00017934 + 0x178b6);
    *piVar4 = iVar1;
    if (iVar1 < 0) {
      __format = (char *)(DAT_00017938 + 0x178f4);
    }
    else {
      printf((char *)(DAT_0001793c + 0x178c2),param_1);
      pvVar2 = mmap((void *)0x0,sStack_88.st_blksize,1,2,*piVar4,0);
      **(undefined4 **)(DAT_00017940 + 0x178dc) = pvVar2;
      if (pvVar2 != (void *)0xffffffff) {
        uVar3 = 0;
        *param_2 = sStack_88.st_blksize;
        goto LAB_0001790e;
      }
      piVar4 = (int *)__errno();
      param_1 = strerror(*piVar4);
      __format = (char *)(DAT_00017944 + 0x17908);
    }
  }
  printf(__format,param_1);
  uVar3 = 0xffffffff;
LAB_0001790e:
  if (**(int **)(DAT_00017948 + 0x17916) == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}



// ===========================================================
// Function: update_res_file at 0001794c
// ===========================================================

void update_res_file(undefined4 param_1,byte param_2,undefined4 *param_3)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *__s;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *__format;
  uint uVar9;
  int *piVar10;
  ushort uVar11;
  bool bVar12;
  uint local_fc3c;
  byte local_fc38;
  undefined1 auStack_fc34 [4];
  uint local_fc30;
  undefined1 local_fc2c;
  byte local_fc2b;
  ushort local_fc2a;
  undefined1 auStack_fc28 [64512];
  int local_28;
  
  local_28 = **(int **)(DAT_00017a7c + 0x1796c);
  local_fc30 = 0;
  __aeabi_memclr8(auStack_fc28,0xfc00);
  local_fc38 = 0;
  local_fc3c = 0;
  local_fc2c = 0x22;
  local_fc2b = param_2;
  map_res_file(param_1,&local_fc30);
  uVar1 = local_fc30;
  if (local_fc30 != 0) {
    uVar9 = 0;
    uVar11 = 0;
    piVar2 = *(int **)(DAT_00017a80 + 0x179ae);
    __format = (char *)(DAT_00017a88 + 0x179ba);
    piVar10 = *(int **)(DAT_00017a84 + 0x179b8);
    pcVar3 = (char *)(DAT_00017a8c + 0x179c2);
    pcVar4 = (char *)(DAT_00017a90 + 0x179c8);
    do {
      iVar7 = *piVar2;
      if (uVar1 <= iVar7 + uVar9) {
        iVar7 = uVar1 - uVar9;
      }
      iVar8 = *piVar10 + uVar9;
      local_fc2a = uVar11;
      __memcpy_chk(auStack_fc28,iVar8,iVar7,0xfc00);
      uVar5 = crc32_with_initvalue(iVar8,iVar7,*param_3);
      *param_3 = uVar5;
      printf(__format,(uint)uVar11,iVar7,uVar5);
      iVar8 = spi_transfer_msg(&local_fc2c,iVar7 + 4,&local_fc3c,auStack_fc34);
      __s = pcVar3;
      if ((iVar8 < 0) || (__s = pcVar4, (char)local_fc3c != '#')) {
LAB_00017a50:
        puts(__s);
        break;
      }
      uVar6 = local_fc3c >> 8 & 0xff;
      bVar12 = uVar6 != local_fc2b;
      if (!bVar12) {
        uVar6 = (uint)local_fc38;
      }
      __s = (char *)(DAT_00017a94 + 0x17a34);
      if (bVar12 || uVar6 != 0) goto LAB_00017a50;
      uVar9 = uVar9 + iVar7;
      uVar11 = uVar11 + 1;
    } while (uVar9 < uVar1);
  }
  if (**(int **)(DAT_00017a98 + 0x17a66) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_28);
}



// ===========================================================
// Function: verity_res_file at 00017a9c
// ===========================================================

void verity_res_file(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_1a;
  byte local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined4 local_14;
  undefined1 auStack_10 [4];
  int local_c;
  
  local_c = **(int **)(DAT_00017b2c + 0x17aae);
  local_16 = (undefined1)param_1;
  local_15 = 1;
  local_17 = 0x24;
  local_18 = 0;
  local_1a = 0;
  local_14 = param_2;
  iVar1 = spi_transfer_msg(&local_17,7,&local_1a,auStack_10);
  if (iVar1 < 0) {
    puts((char *)(DAT_00017b30 + 0x17b00));
  }
  else {
    if (((byte)local_1a == 0x25) && (local_1a._1_1_ == param_1 && local_18 == 0)) {
      uVar2 = 0;
      goto LAB_00017b14;
    }
    printf((char *)(DAT_00017b34 + 0x17b0e),(uint)(byte)local_1a,(uint)local_1a._1_1_,(uint)local_18
          );
  }
  uVar2 = 0xffffffff;
LAB_00017b14:
  if (**(int **)(DAT_00017b38 + 0x17b1c) != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: send_rb_request at 00017b3c
// ===========================================================

void send_rb_request(byte param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  byte local_38;
  byte bStack_37;
  byte bStack_36;
  uint uStack_35;
  undefined4 local_31;
  undefined1 local_26;
  byte local_25;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 auStack_18 [4];
  int local_14;
  
  local_14 = **(int **)(DAT_00017bf4 + 0x17b4c);
  local_24 = 0xfc00;
  local_26 = 0x30;
  local_38 = 0;
  bStack_37 = 0;
  bStack_36 = 0;
  uStack_35 = 0;
  local_31 = 0;
  local_25 = param_1;
  local_20 = param_2;
  local_1c = param_3;
  iVar1 = spi_transfer_msg(&local_26,0xe,&local_38,auStack_18);
  if (iVar1 < 0) {
    puts((char *)(DAT_00017bf8 + 0x17bca));
  }
  else {
    if ((local_38 == 0x31) && ((uint)bStack_37 == (uint)param_1 && bStack_36 == 0)) {
      uVar2 = uStack_35;
      if (0xfbff < uStack_35) {
        uVar2 = 0xfc00;
      }
      puVar4 = *(uint **)(DAT_00017c00 + 0x17bb2);
      *puVar4 = uVar2;
      *param_4 = local_31;
      printf((char *)(DAT_00017c04 + 0x17bbe),*puVar4);
      uVar3 = 0;
      goto LAB_00017bde;
    }
    printf((char *)(DAT_00017bfc + 0x17bd8),(uint)local_38,(uint)bStack_37,(uint)bStack_36);
  }
  uVar3 = 0xffffffff;
LAB_00017bde:
  if (**(int **)(DAT_00017c08 + 0x17be6) != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



// ===========================================================
// Function: rb_res_data at 00017c0c
// ===========================================================

void rb_res_data(byte param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  char *__format;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_fc38;
  uint local_fc34;
  byte local_fc30;
  byte local_fc2f;
  byte local_fc2c;
  undefined1 auStack_fc2a [64514];
  int local_28;
  
  local_28 = **(int **)(DAT_00017d2c + 0x17c26);
  local_fc34 = 0;
  if (param_2 < 1) {
    printf((char *)(DAT_00017d48 + 0x17ce6),param_2);
LAB_00017ce8:
    uVar3 = 0xffffffff;
  }
  else {
    iVar6 = 0;
    uVar5 = 0;
    puVar1 = *(uint **)(DAT_00017d30 + 0x17c4a);
    do {
      local_fc38 = 0x32;
      __aeabi_memclr8(&local_fc30,0xfc06);
      local_fc38 = CONCAT22((short)uVar5,CONCAT11(param_1,(undefined1)local_fc38));
      uVar7 = *puVar1;
      iVar2 = spi_transfer_msg(&local_fc38,4,&local_fc30,&local_fc34);
      if (param_2 <= (int)(uVar7 + iVar6)) {
        uVar7 = param_2 - iVar6;
      }
      if (iVar2 < 0) {
        puts((char *)(DAT_00017d34 + 0x17d14));
        goto LAB_00017ce8;
      }
      if (local_fc34 < uVar7 + 6) {
        __format = (char *)(DAT_00017d38 + 0x17d1e);
        uVar4 = local_fc34;
LAB_00017cd8:
        printf(__format,uVar4,uVar7,uVar5);
        goto LAB_00017ce8;
      }
      if ((local_fc30 != 0x33 || (uint)local_fc2f != (uint)param_1) || (local_fc2c != 0)) {
        __format = (char *)(DAT_00017d3c + 0x17cda);
        uVar4 = (uint)local_fc30;
        uVar7 = (uint)local_fc2f;
        uVar5 = (uint)local_fc2c;
        goto LAB_00017cd8;
      }
      uVar3 = crc32_with_initvalue(auStack_fc2a,uVar7,*param_4);
      *param_4 = uVar3;
      uVar4 = __write_chk(param_3,auStack_fc2a,uVar7,0xfc00);
      if ((int)uVar4 < (int)uVar7) {
        __format = (char *)(DAT_00017d40 + 0x17d26);
        goto LAB_00017cd8;
      }
      iVar6 = iVar6 + uVar7;
      uVar5 = uVar5 + 1;
    } while (iVar6 < param_2);
    uVar3 = 0;
  }
  if (**(int **)(DAT_00017d44 + 0x17cfa) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



// ===========================================================
// Function: verify_rb_data at 00017d4c
// ===========================================================

void verify_rb_data(byte param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_1a;
  byte local_18;
  undefined1 local_17;
  byte local_16;
  undefined1 local_15;
  undefined4 local_14;
  undefined1 auStack_10 [4];
  int local_c;
  
  local_c = **(int **)(DAT_00017ddc + 0x17d5e);
  local_15 = 1;
  local_17 = 0x34;
  local_18 = 0;
  local_1a = 0;
  local_16 = param_1;
  local_14 = param_2;
  iVar1 = spi_transfer_msg(&local_17,7,&local_1a,auStack_10);
  if (iVar1 < 0) {
    puts((char *)(DAT_00017de0 + 0x17db2));
  }
  else {
    if (((byte)local_1a == 0x35) && ((uint)local_1a._1_1_ == (uint)param_1 && local_18 == 0)) {
      uVar2 = 0;
      goto LAB_00017dc6;
    }
    printf((char *)(DAT_00017de4 + 0x17dc0),(uint)(byte)local_1a,(uint)local_1a._1_1_,(uint)local_18
          );
  }
  uVar2 = 0xffffffff;
LAB_00017dc6:
  if (**(int **)(DAT_00017de8 + 0x17dce) != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: send_wipe_data at 00017dec
// ===========================================================

void send_wipe_data(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_16;
  byte local_14;
  undefined2 local_12;
  undefined1 auStack_10 [4];
  int local_c;
  
  local_c = **(int **)(DAT_00017e78 + 0x17dfe);
  local_12 = 0x150;
  local_14 = 0;
  local_16 = 0;
  iVar1 = spi_transfer_msg(&local_12,2,&local_16,auStack_10);
  if (iVar1 < 0) {
    puts((char *)(DAT_00017e7c + 0x17e4c));
  }
  else {
    if (((byte)local_16 == 0x51) && (local_16._1_1_ == 1 && local_14 == 0)) {
      puts((char *)(DAT_00017e84 + 0x17e40));
      uVar2 = 0;
      goto LAB_00017e60;
    }
    printf((char *)(DAT_00017e80 + 0x17e5a),(uint)(byte)local_16,(uint)local_16._1_1_,(uint)local_14
          );
  }
  uVar2 = 0xffffffff;
LAB_00017e60:
  if (**(int **)(DAT_00017e88 + 0x17e68) != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: send_agingtest_request at 00017e8c
// ===========================================================

void send_agingtest_request(byte param_1)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  undefined2 local_16;
  byte local_14;
  undefined1 local_12;
  byte bStack_11;
  undefined1 auStack_10 [4];
  int local_c;
  
  local_c = **(int **)(DAT_00017f1c + 0x17ea0);
  _local_12 = CONCAT11(param_1,0x40);
  local_14 = 0;
  local_16 = 0;
  iVar1 = spi_transfer_msg(&local_12,2,&local_16,auStack_10);
  if (iVar1 < 0) {
    puts((char *)(DAT_00017f20 + 0x17eee));
  }
  else {
    uVar2 = (uint)(byte)local_16;
    bVar3 = uVar2 == 0x41;
    if (bVar3) {
      uVar2 = (uint)param_1;
    }
    if (bVar3 && local_16._1_1_ == uVar2) {
      printf((char *)(DAT_00017f28 + 0x17f00),(uint)local_14);
    }
    else {
      printf((char *)(DAT_00017f24 + 0x17ee4),0x40,(uint)local_16._1_1_,(uint)local_14);
    }
  }
  if (**(int **)(DAT_00017f2c + 0x17f0c) == local_c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_c);
}



// ===========================================================
// Function: download_programmer at 00017f30
// ===========================================================

void download_programmer(undefined4 param_1)

{
  int iVar1;
  char *__s;
  int local_10;
  int local_c;
  
  local_c = **(int **)(DAT_00017f88 + 0x17f3a);
  local_10 = 0;
  map_res_file(param_1,&local_10);
  if (local_10 == 0) {
    __s = (char *)(DAT_00017f8c + 0x17f6e);
  }
  else {
    iVar1 = uart_run_programmer(**(undefined4 **)(DAT_00017f90 + 0x17f52));
    if (0 < iVar1) goto LAB_00017f70;
    __s = (char *)(DAT_00017f94 + 0x17f64);
  }
  puts(__s);
LAB_00017f70:
  if (**(int **)(DAT_00017f98 + 0x17f78) != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_c);
  }
  return;
}



// ===========================================================
// Function: download_bootloader_bin at 00017f9c
// ===========================================================

void download_bootloader_bin(undefined4 param_1)

{
  int iVar1;
  char *__s;
  int local_10;
  int local_c;
  
  local_c = **(int **)(DAT_00017ff4 + 0x17fa6);
  local_10 = 0;
  map_res_file(param_1,&local_10);
  if (local_10 == 0) {
    __s = (char *)(DAT_00017ff8 + 0x17fda);
  }
  else {
    iVar1 = uart_burn_boot(**(undefined4 **)(DAT_00017ffc + 0x17fbe));
    if (0 < iVar1) goto LAB_00017fdc;
    __s = (char *)(DAT_00018000 + 0x17fd0);
  }
  puts(__s);
LAB_00017fdc:
  if (**(int **)(DAT_00018004 + 0x17fe4) != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_c);
  }
  return;
}



// ===========================================================
// Function: dcc_fd_open at 00018008
// ===========================================================

void dcc_fd_open(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 5;
  puVar3 = (undefined1 *)(DAT_0001803c + 0x18016);
  *puVar3 = 0;
  iVar2 = DAT_00018040 + 0x1801e;
  piVar5 = (int *)(DAT_00018044 + 0x18020);
  do {
    iVar1 = __open_2(iVar2,0x802);
    *piVar5 = iVar1;
    if (-1 < iVar1) {
      *puVar3 = 1;
      return;
    }
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}



// ===========================================================
// Function: send_dcc_spi_msg at 00018048
// ===========================================================

void send_dcc_spi_msg(undefined4 param_1,undefined4 param_2)

{
  ssize_t sVar1;
  int iVar2;
  char *__format;
  int *piVar3;
  undefined1 *local_81c;
  undefined2 local_818;
  undefined1 auStack_816 [2046];
  int local_18;
  
  local_18 = **(int **)(DAT_000180ec + 0x18058);
  if (*(char *)(DAT_000180f0 + 0x18064) == '\0') {
    dcc_fd_open();
  }
  piVar3 = (int *)(DAT_000180f4 + 0x18070);
  if (*piVar3 < 0) {
    puts((char *)(DAT_000180f8 + 0x180cc));
  }
  else {
    printf((char *)(DAT_000180fc + 0x18080),param_1,param_2);
    __aeabi_memclr8(auStack_816,0x7fe);
    iVar2 = 0x5db;
    local_818 = 0x608;
    local_81c = &DAT_00020174;
    __format = (char *)(DAT_00018100 + 0x180aa);
    do {
      sVar1 = write(*piVar3,&local_81c,6);
      if (sVar1 != -1) goto LAB_000180d2;
      printf(__format,iVar2);
      iVar2 = iVar2 + -1;
    } while (iVar2 != -1);
  }
  sVar1 = -1;
LAB_000180d2:
  if (**(int **)(DAT_00018104 + 0x180dc) == local_18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(sVar1);
}



// ===========================================================
// Function: rcv_dcc_msg_response at 00018108
// ===========================================================

ssize_t rcv_dcc_msg_response(char *param_1)

{
  char cVar1;
  ssize_t sVar2;
  int *piVar3;
  int iVar4;
  bool bVar5;
  
  if (*(char *)(DAT_00018164 + 0x18114) == '\0') {
    dcc_fd_open();
  }
  piVar3 = (int *)(DAT_00018168 + 0x18120);
  if (*piVar3 < 0) {
    sVar2 = -1;
  }
  else {
    iVar4 = -0x5dc;
    do {
      sVar2 = read(*piVar3,param_1,0x804);
      if (3 < sVar2) {
        cVar1 = *param_1;
        bVar5 = cVar1 == 'j';
        if (bVar5) {
          cVar1 = param_1[1];
        }
        if (bVar5 && cVar1 == '\x01') {
          return sVar2;
        }
      }
      usleep(10000);
      bVar5 = iVar4 != -1;
      iVar4 = iVar4 + 1;
    } while (bVar5);
  }
  return sVar2;
}



// ===========================================================
// Function: fd_open at 0001816c
// ===========================================================

void fd_open(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 5;
  puVar3 = (undefined1 *)(DAT_000181a0 + 0x1817a);
  *puVar3 = 0;
  iVar2 = DAT_000181a4 + 0x18182;
  piVar5 = (int *)(DAT_000181a8 + 0x18184);
  do {
    iVar1 = __open_2(iVar2,0x802);
    *piVar5 = iVar1;
    if (-1 < iVar1) {
      *puVar3 = 1;
      return;
    }
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}



// ===========================================================
// Function: send_spi_msg at 000181ac
// ===========================================================

void send_spi_msg(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  char *__format;
  undefined1 auStack_fe28 [65028];
  int local_24;
  
  local_24 = **(int **)(DAT_00018254 + 0x181c4);
  if (*(char *)(DAT_00018258 + 0x181d0) == '\0') {
    fd_open();
  }
  piVar2 = (int *)(DAT_0001825c + 0x181dc);
  if (*piVar2 < 0) {
    puts((char *)(DAT_00018260 + 0x1822c));
  }
  else {
    __aeabi_memclr8(auStack_fe28,0xfe00);
    __memcpy_chk(auStack_fe28,param_1,param_2,0xfe00);
    iVar3 = 0x5db;
    __format = (char *)(DAT_00018264 + 0x18206);
    do {
      iVar1 = __write_chk(*piVar2,auStack_fe28,param_2,0xfe00);
      if (iVar1 != -1) goto LAB_00018232;
      printf(__format,iVar3);
      iVar3 = iVar3 + -1;
    } while (iVar3 != -1);
  }
  iVar1 = -1;
LAB_00018232:
  if (**(int **)(DAT_00018268 + 0x18240) == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar1);
}



// ===========================================================
// Function: rcv_msg_response at 0001826c
// ===========================================================

ssize_t rcv_msg_response(void *param_1)

{
  ssize_t sVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  
  if (*(char *)(DAT_000182bc + 0x18278) == '\0') {
    fd_open();
  }
  piVar2 = (int *)(DAT_000182c0 + 0x18284);
  if (*piVar2 < 0) {
    sVar1 = -1;
  }
  else {
    iVar3 = -0x5dc;
    do {
      sVar1 = read(*piVar2,param_1,0xfe00);
      if (0 < sVar1) {
        return sVar1;
      }
      usleep(10000);
      bVar4 = iVar3 != -1;
      iVar3 = iVar3 + 1;
    } while (bVar4);
  }
  return sVar1;
}



// ===========================================================
// Function: sync_mcu_reset_cmd_with_spi_driver at 000182c4
// ===========================================================

void sync_mcu_reset_cmd_with_spi_driver(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *__s;
  char *pcVar5;
  char *pcVar6;
  char *__format;
  int iVar7;
  __off_t _Var8;
  ssize_t sVar9;
  char *pcVar10;
  int *piVar11;
  char *pcVar12;
  undefined4 uVar13;
  uint uVar14;
  uint local_44;
  byte local_2a;
  undefined1 local_29;
  int local_28;
  
  local_28 = **(int **)(DAT_0001844c + 0x182d4);
  local_29 = 0;
  iVar1 = strcmp(param_2,(char *)(DAT_00018450 + 0x182e6));
  if (iVar1 == 0) {
    local_29 = 0x30;
    local_44 = 0x30;
  }
  else {
    iVar1 = strcmp(param_2,(char *)(DAT_00018454 + 0x182f2));
    if (iVar1 == 0) {
      local_29 = 0x31;
      local_44 = 0x31;
    }
    else {
      local_44 = 0;
    }
  }
  iVar1 = 3;
  pcVar2 = (char *)(DAT_00018458 + 0x18320);
  pcVar3 = (char *)(DAT_0001845c + 0x18326);
  pcVar4 = (char *)(DAT_00018460 + 0x1832c);
  __s = (char *)(DAT_00018464 + 0x18332);
  pcVar5 = (char *)(DAT_00018468 + 0x18338);
  pcVar6 = (char *)(DAT_0001846c + 0x1833e);
  __format = (char *)(DAT_00018470 + 0x18344);
  do {
    local_2a = 0x38;
    iVar7 = access(param_1,0);
    if (iVar7 == -1) {
      piVar11 = (int *)__errno();
      pcVar12 = strerror(*piVar11);
      pcVar10 = pcVar2;
LAB_000183da:
      printf(pcVar10,param_1,pcVar12);
    }
    else {
      iVar7 = __open_2(param_1,2);
      if (iVar7 < 0) {
        piVar11 = (int *)__errno();
        pcVar12 = strerror(*piVar11);
        pcVar10 = pcVar3;
        goto LAB_000183da;
      }
      _Var8 = lseek(iVar7,0,0);
      pcVar10 = pcVar4;
      if ((_Var8 < 0) || (sVar9 = write(iVar7,&local_29,1), pcVar10 = pcVar5, sVar9 < 0)) {
LAB_000183ec:
        piVar11 = (int *)__errno();
        pcVar12 = strerror(*piVar11);
        printf(pcVar10,param_1,pcVar12);
      }
      else {
        sleep(1);
        _Var8 = lseek(iVar7,0,0);
        pcVar10 = pcVar4;
        if ((_Var8 < 0) || (sVar9 = read(iVar7,&local_2a,1), pcVar10 = pcVar6, sVar9 < 0))
        goto LAB_000183ec;
        uVar14 = (uint)local_2a;
        printf(__format,local_44,uVar14);
        if (local_44 == uVar14) {
          close(iVar7);
          puts((char *)(DAT_00018478 + 0x18446));
          uVar13 = 0;
          goto LAB_00018422;
        }
      }
      close(iVar7);
      puts(__s);
    }
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) {
      printf((char *)(DAT_00018474 + 0x1841c),local_44,(uint)local_2a);
      uVar13 = 0xffffffff;
LAB_00018422:
      if (**(int **)(DAT_0001847c + 0x1842a) == local_28) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(uVar13);
    }
  } while( true );
}



// ===========================================================
// Function: deinitGpio at 00018480
// ===========================================================

undefined4 deinitGpio(void)

{
  gpio_write_drirection(0x40,1);
  return 0;
}



// ===========================================================
// Function: gpio_write_drirection at 00018490
// ===========================================================

void gpio_write_drirection(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  undefined4 local_1d4;
  undefined1 auStack_1d0 [80];
  undefined4 local_180;
  undefined1 auStack_17c [252];
  undefined4 local_80;
  undefined4 local_1c;
  int local_18;
  int local_14;
  
  local_14 = **(int **)(DAT_00018580 + 0x184a2);
  __aeabi_memclr8(auStack_17c,0x168);
  iVar4 = DAT_00018588 + 0x184ba;
  printf((char *)(DAT_00018584 + 0x184bc),param_1,param_2,iVar4);
  iVar4 = __open_2(iVar4,0);
  if (iVar4 < 0) {
    piVar2 = (int *)__errno();
    pcVar3 = strerror(*piVar2);
    printf((char *)(DAT_0001858c + 0x18548),DAT_00018590 + 0x1854a,pcVar3);
  }
  else {
    local_1c = 1;
    local_80 = 2;
    local_180 = param_1;
    iVar1 = ioctl(iVar4,0xc16cb403,&local_180);
    close(iVar4);
    if (iVar1 == -1) {
      piVar2 = (int *)__errno();
      pcVar3 = strerror(*piVar2);
      printf((char *)(DAT_00018594 + 0x18560),pcVar3);
    }
    else {
      __aeabi_memclr8(auStack_1d0,0x50);
      local_1d4 = param_2;
      iVar4 = ioctl(local_18,0xc054b40a,&local_1d4);
      if (iVar4 == -1) {
        piVar2 = (int *)__errno();
        pcVar3 = strerror(*piVar2);
        printf((char *)(DAT_00018598 + 0x1852a),pcVar3);
      }
      close(local_18);
    }
  }
  if (**(int **)(DAT_0001859c + 0x1856e) == local_14) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_14);
}



// ===========================================================
// Function: setUpgradeGpio at 000185a0
// ===========================================================

uint setUpgradeGpio(uint param_1)

{
  uint uVar1;
  
  uVar1 = gpio_write_drirection(9,2);
  if ((int)uVar1 < 0) {
    puts((char *)(DAT_000185dc + 0x185d6));
  }
  else {
    uVar1 = gpio_write(9,param_1 & 0xff);
    if (0x7fffffff < uVar1) {
      printf((char *)(DAT_000185e0 + 0x185ca),param_1);
    }
  }
  return uVar1;
}



// ===========================================================
// Function: gpio_write at 000185e4
// ===========================================================

void gpio_write(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  undefined1 local_1c4;
  undefined4 local_1c3;
  undefined4 uStack_1bf;
  undefined4 uStack_1bb;
  uint uStack_1b7;
  undefined4 local_1b3;
  undefined4 uStack_1af;
  undefined4 uStack_1ab;
  uint uStack_1a7;
  undefined4 local_1a3;
  undefined4 uStack_19f;
  undefined4 uStack_19b;
  uint uStack_197;
  undefined3 uStack_193;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  uint uStack_188;
  undefined4 local_184;
  undefined1 auStack_180 [252];
  undefined4 local_84;
  undefined4 local_20;
  int local_1c;
  int local_18;
  
  local_18 = **(int **)(DAT_000186e8 + 0x185f6);
  __aeabi_memclr8(auStack_180,0x168);
  uStack_1bf = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_1bb = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_1b7 = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_1c3 = 0;
  local_1b3 = 0;
  local_1a3 = 0;
  uStack_197 = uStack_1b7 & 0xffffff;
  uStack_193 = 0;
  iVar4 = DAT_000186ec + 0x1862a;
  uStack_1af = uStack_1bf;
  uStack_1ab = uStack_1bb;
  uStack_1a7 = uStack_1b7;
  uStack_19f = uStack_1bf;
  uStack_19b = uStack_1bb;
  uStack_190 = uStack_1bf;
  uStack_18c = uStack_1bb;
  uStack_188 = uStack_1b7;
  printf((char *)(DAT_000186f0 + 0x18630),param_2,param_1,2,iVar4);
  iVar4 = __open_2(iVar4,0);
  if (iVar4 < 0) {
    piVar2 = (int *)__errno();
    pcVar3 = strerror(*piVar2);
    printf((char *)(DAT_000186f4 + 0x186b0),DAT_000186f8 + 0x186b2,pcVar3);
  }
  else {
    local_84 = 2;
    local_20 = 1;
    local_184 = param_1;
    iVar1 = ioctl(iVar4,0xc16cb403,&local_184);
    close(iVar4);
    if (iVar1 == -1) {
      piVar2 = (int *)__errno();
      pcVar3 = strerror(*piVar2);
      printf((char *)(DAT_000186fc + 0x186c8),pcVar3);
    }
    else {
      local_1c4 = (undefined1)param_2;
      iVar4 = ioctl(local_1c,0xc040b409,&local_1c4);
      if (iVar4 == -1) {
        piVar2 = (int *)__errno();
        pcVar3 = strerror(*piVar2);
        printf((char *)(DAT_00018700 + 0x18692),pcVar3);
      }
      close(local_1c);
    }
  }
  if (**(int **)(DAT_00018704 + 0x186d6) == local_18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_18);
}



// ===========================================================
// Function: setMcuRstGpio at 00018708
// ===========================================================

int setMcuRstGpio(void)

{
  int iVar1;
  char *__s;
  
  iVar1 = gpio_write_drirection(0x40,2);
  if (iVar1 < 0) {
    __s = (char *)(DAT_00018760 + 0x1874c);
  }
  else {
    iVar1 = gpio_write(0x40,1);
    if (iVar1 < 0) {
      __s = (char *)(DAT_00018764 + 0x18754);
    }
    else {
      sleep(1);
      iVar1 = gpio_write(0x40,0);
      if (-1 < iVar1) {
        sleep(5);
        return iVar1;
      }
      __s = (char *)(DAT_00018768 + 0x1875a);
    }
  }
  puts(__s);
  return iVar1;
}



// ===========================================================
// Function: setMcuRstGpio_Uart at 0001876c
// ===========================================================

uint setMcuRstGpio_Uart(void)

{
  uint uVar1;
  char *__s;
  
  uVar1 = gpio_write_drirection(0x40,2);
  if ((int)uVar1 < 0) {
    __s = (char *)(DAT_000187b8 + 0x187aa);
  }
  else {
    uVar1 = gpio_write(0x40,1);
    if ((int)uVar1 < 0) {
      __s = (char *)(DAT_000187bc + 0x187b2);
    }
    else {
      sleep(1);
      uVar1 = gpio_write(0x40,0);
      if (uVar1 < 0x80000000) {
        return uVar1;
      }
      __s = (char *)(DAT_000187c0 + 0x187a2);
    }
  }
  puts(__s);
  return uVar1;
}



// ===========================================================
// Function: crc32 at 000187c4
// ===========================================================

uint crc32(byte *param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 != 0) {
    uVar1 = 0xffffffff;
    do {
      param_2 = param_2 + -1;
      uVar1 = *(uint *)(*(int *)(DAT_000187f0 + 0x187d0) + ((*param_1 ^ uVar1) & 0xff) * 4) ^
              uVar1 >> 8;
      param_1 = param_1 + 1;
    } while (param_2 != 0);
    return ~uVar1;
  }
  return 0;
}



// ===========================================================
// Function: crc32_with_initvalue at 000187f4
// ===========================================================

uint crc32_with_initvalue(byte *param_1,int param_2,uint param_3)

{
  if (param_2 != 0) {
    param_3 = ~param_3;
    do {
      param_2 = param_2 + -1;
      param_3 = *(uint *)(*(int *)(DAT_0001881c + 0x187fe) + ((*param_1 ^ param_3) & 0xff) * 4) ^
                param_3 >> 8;
      param_1 = param_1 + 1;
    } while (param_2 != 0);
    param_3 = ~param_3;
  }
  return param_3;
}



// ===========================================================
// Function: writeMcuVersionToOppoReserve1 at 00018820
// ===========================================================

void writeMcuVersionToOppoReserve1(char *param_1)

{
  int __fd;
  __off_t _Var1;
  size_t sVar2;
  ssize_t sVar3;
  int *piVar4;
  char *pcVar5;
  char *__format;
  undefined1 auStack_218 [516];
  int local_14;
  
  local_14 = **(int **)(DAT_0001890c + 0x18830);
  __fd = __open_2(DAT_00018910 + 0x1883a,2);
  __aeabi_memclr8(auStack_218,0x200);
  if (__fd < 0) {
    piVar4 = (int *)__errno();
    pcVar5 = strerror(*piVar4);
    if (**(int **)(DAT_00018920 + 0x18888) == local_14) {
      __ThumbV7PILongThunk_printf((char *)(DAT_00018924 + 0x18894),pcVar5);
      return;
    }
    goto LAB_00018906;
  }
  _Var1 = lseek(__fd,0x465c00,0);
  if (_Var1 < 0) {
    piVar4 = (int *)__errno();
    pcVar5 = strerror(*piVar4);
    __format = (char *)(DAT_00018914 + 0x188b0);
LAB_000188e8:
    printf(__format,pcVar5);
  }
  else {
    sVar2 = strlen(param_1);
    if (sVar2 < 0x201) {
      sVar2 = strlen(param_1);
    }
    else {
      sVar2 = 0x200;
    }
    __memcpy_chk(auStack_218,param_1,sVar2,0x200);
    sVar3 = write(__fd,auStack_218,0x200);
    if (sVar3 != 0x200) {
      piVar4 = (int *)__errno();
      pcVar5 = strerror(*piVar4);
      __format = (char *)(DAT_00018918 + 0x188ea);
      goto LAB_000188e8;
    }
  }
  close(__fd);
  if (**(int **)(DAT_0001891c + 0x188fa) == local_14) {
    return;
  }
LAB_00018906:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// ===========================================================
// Function: readMcuVersionFromOppoReserve1 at 00018928
// ===========================================================

void readMcuVersionFromOppoReserve1(void *param_1,size_t param_2,char *param_3)

{
  int __fd;
  __off_t _Var1;
  ssize_t sVar2;
  uint uVar3;
  int *piVar4;
  char *pcVar5;
  char *__format;
  size_t sVar6;
  char local_218 [512];
  int local_18;
  
  local_18 = **(int **)(DAT_00018a44 + 0x1893c);
  __fd = __open_2(DAT_00018a48 + 0x18946,2);
  __aeabi_memclr8(local_218,0x200);
  if (__fd < 0) {
    piVar4 = (int *)__errno();
    pcVar5 = strerror(*piVar4);
    if (**(int **)(DAT_00018a5c + 0x189c2) == local_18) {
      __ThumbV7PILongThunk_printf((char *)(DAT_00018a60 + 0x189ce),pcVar5);
      return;
    }
    goto LAB_00018a3e;
  }
  _Var1 = lseek(__fd,0x465c00,0);
  if (_Var1 < 0) {
    piVar4 = (int *)__errno();
    pcVar5 = strerror(*piVar4);
    __format = (char *)(DAT_00018a4c + 0x189ea);
LAB_000189fa:
    printf(__format,pcVar5);
  }
  else {
    sVar2 = read(__fd,local_218,0x200);
    if (sVar2 != 0x200) {
      piVar4 = (int *)__errno();
      pcVar5 = strerror(*piVar4);
      __format = (char *)(DAT_00018a50 + 0x189fc);
      goto LAB_000189fa;
    }
    __aeabi_memclr8(param_1,param_2);
    if (local_218[0] == '\0') {
      puts((char *)(DAT_00018a58 + 0x18a06));
      sVar6 = strlen(param_3);
      if (sVar6 <= param_2) {
        param_2 = strlen(param_3);
      }
    }
    else {
      uVar3 = __strlen_chk(local_218,0x200);
      param_3 = local_218;
      if (uVar3 <= param_2) {
        param_2 = __strlen_chk(local_218,0x200);
        param_3 = local_218;
      }
    }
    __aeabi_memcpy8(param_1,param_3,param_2);
  }
  close(__fd);
  if (**(int **)(DAT_00018a54 + 0x18a32) == local_18) {
    return;
  }
LAB_00018a3e:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// ===========================================================
// Function: pb_field_iter_begin at 00018a64
// ===========================================================

void pb_field_iter_begin(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = 0;
  param_1[1] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  param_1[2] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  param_1[3] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  param_1[9] = 0;
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[4] = 0;
  param_1[5] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  param_1[6] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  param_1[7] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  param_1[8] = 0;
  load_descriptor_values();
  return;
}



// ===========================================================
// Function: load_descriptor_values at 00018a86
// ===========================================================

bool load_descriptor_values(undefined4 *param_1)

{
  ushort uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  undefined4 *puVar11;
  ushort uVar12;
  
  piVar9 = (int *)*param_1;
  uVar1 = *(ushort *)(piVar9 + 4);
  if (uVar1 <= *(ushort *)(param_1 + 2)) goto LAB_00018b6e;
  uVar6 = (uint)*(ushort *)((int)param_1 + 10);
  uVar2 = *(uint *)(*piVar9 + uVar6 * 4);
  *(char *)((int)param_1 + 0x16) = (char)(uVar2 >> 8);
  uVar10 = uVar2 & 3;
  uVar5 = (ushort)(uVar2 >> 0x10);
  if (uVar10 == 2) {
    iVar7 = *piVar9 + uVar6 * 4;
LAB_00018afc:
    uVar6 = *(uint *)(iVar7 + 4);
    uVar10 = *(uint *)(iVar7 + 8);
    uVar12 = (ushort)*(undefined4 *)(iVar7 + 0xc);
    *(ushort *)(param_1 + 5) = uVar5;
    uVar5 = (ushort)(uVar6 >> 2) & 0xffc0 | (ushort)(uVar2 >> 2) & 0x3f;
LAB_00018b08:
    *(ushort *)(param_1 + 4) = uVar5;
  }
  else {
    if (uVar10 != 1) {
      if (uVar10 != 0) {
        iVar7 = *piVar9 + uVar6 * 4;
        uVar5 = (ushort)*(undefined4 *)(iVar7 + 0x10);
        goto LAB_00018afc;
      }
      uVar12 = uVar5 >> 0xc;
      uVar10 = (uVar2 & 0xffffff) >> 0x10;
      uVar6 = (uVar2 & 0xfffffff) >> 0x18;
      *(undefined2 *)(param_1 + 5) = 1;
      uVar5 = (ushort)((uVar2 << 0x18) >> 0x1a);
      goto LAB_00018b08;
    }
    uVar6 = *(uint *)(*piVar9 + uVar6 * 4 + 4);
    *(ushort *)(param_1 + 5) = (ushort)((uVar2 << 4) >> 0x14);
    uVar12 = (ushort)((uVar6 << 4) >> 0x14);
    uVar10 = uVar6 & 0xffff;
    *(ushort *)(param_1 + 4) = (ushort)(uVar6 >> 0x16) & 0xffc0 | (ushort)(uVar2 >> 2) & 0x3f;
    uVar6 = uVar2 >> 0x1c;
  }
  *(ushort *)((int)param_1 + 0x12) = uVar12;
  uVar8 = (uVar2 & 0xffff) >> 8;
  if (param_1[1] == 0) {
    param_1[8] = 0;
    param_1[6] = 0;
  }
  else {
    puVar11 = (undefined4 *)(uVar10 + param_1[1]);
    param_1[6] = puVar11;
    if ((uVar6 & 0xff) == 0) {
      if (((uVar2 & 0x3000) == 0x2000) && ((uVar8 & 0xc0 | 0x80) == 0x80)) {
        puVar3 = param_1 + 5;
      }
      else {
        puVar3 = (undefined4 *)0x0;
      }
    }
    else {
      puVar3 = (undefined4 *)((int)puVar11 - (int)(char)uVar6);
    }
    param_1[8] = puVar3;
    if ((uVar8 & 0xc0) == 0x80) {
      param_1[7] = *puVar11;
    }
    else {
      param_1[7] = puVar11;
    }
  }
  if ((uVar8 & 0xe) == 8) {
    uVar4 = *(undefined4 *)(piVar9[1] + (uint)*(ushort *)((int)param_1 + 0xe) * 4);
  }
  else {
    uVar4 = 0;
  }
  param_1[9] = uVar4;
LAB_00018b6e:
  return *(ushort *)(param_1 + 2) < uVar1;
}



// ===========================================================
// Function: pb_field_iter_begin_extension at 00018b78
// ===========================================================

void pb_field_iter_begin_extension(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = param_2 + 1;
  puVar2 = *(undefined4 **)(*param_2 + 8);
  if ((*(uint *)*puVar2 & 0xc000) != 0x8000) {
    piVar1 = (int *)*piVar1;
  }
  *param_1 = 0;
  param_1[1] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  param_1[2] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  param_1[3] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  param_1[9] = 0;
  *param_1 = puVar2;
  param_1[1] = piVar1;
  param_1[4] = 0;
  param_1[5] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  param_1[6] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  param_1[7] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  param_1[8] = 0;
  load_descriptor_values();
  param_1[8] = param_2 + 3;
  return;
}



// ===========================================================
// Function: pb_field_iter_next at 00018bb6
// ===========================================================

bool pb_field_iter_next(int param_1)

{
  advance_iterator();
  load_descriptor_values(param_1);
  return *(short *)(param_1 + 8) != 0;
}



// ===========================================================
// Function: advance_iterator at 00018bce
// ===========================================================

void advance_iterator(int *param_1)

{
  uint uVar1;
  ushort uVar2;
  short sVar3;
  
  uVar2 = (short)param_1[2] + 1;
  *(ushort *)(param_1 + 2) = uVar2;
  if (uVar2 < *(ushort *)((int *)*param_1 + 4)) {
    sVar3 = (short)param_1[3];
    uVar1 = *(uint *)(*(int *)*param_1 + (uint)*(ushort *)((int)param_1 + 10) * 4);
    if ((uVar1 & 0x3000) == 0) {
      sVar3 = sVar3 + 1;
    }
    *(short *)(param_1 + 3) = sVar3;
    sVar3 = *(short *)((int)param_1 + 0xe);
    if ((uVar1 & 0xe00) == 0x800) {
      sVar3 = sVar3 + 1;
    }
    *(short *)((int)param_1 + 0xe) = sVar3;
    *(ushort *)((int)param_1 + 10) = (short)(1 << (uVar1 & 3)) + *(ushort *)((int)param_1 + 10);
    return;
  }
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}



// ===========================================================
// Function: pb_field_iter_find at 00018c1c
// ===========================================================

undefined4 pb_field_iter_find(int *param_1,uint param_2)

{
  int iVar1;
  
  if (*(ushort *)(param_1 + 4) == param_2) {
    return 1;
  }
  if (param_2 <= *(ushort *)(*param_1 + 0x14)) {
    iVar1 = param_1[2];
    if (param_2 < *(ushort *)(param_1 + 4)) {
      *(undefined2 *)(param_1 + 2) = *(undefined2 *)(*param_1 + 0x10);
    }
    do {
      advance_iterator(param_1);
      if (((((param_2 ^ *(uint *)(*(int *)*param_1 + (uint)*(ushort *)((int)param_1 + 10) * 4) >> 2)
            & 0x3f) == 0) && (load_descriptor_values(param_1), *(ushort *)(param_1 + 4) == param_2))
         && ((*(byte *)((int)param_1 + 0x16) & 0xf) != 10)) {
        return 1;
      }
    } while ((short)param_1[2] != (short)iVar1);
    load_descriptor_values(param_1);
  }
  return 0;
}



// ===========================================================
// Function: pb_field_iter_find_extension at 00018c7c
// ===========================================================

undefined4 pb_field_iter_find_extension(undefined4 *param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  if ((*(byte *)((int)param_1 + 0x16) & 0xf) == 10) {
    return 1;
  }
  sVar1 = *(short *)(param_1 + 2);
  do {
    advance_iterator(param_1);
    if ((*(uint *)(*(int *)*param_1 + (uint)*(ushort *)((int)param_1 + 10) * 4) & 0xf00) == 0xa00) {
      uVar2 = load_descriptor_values(param_1);
      return uVar2;
    }
  } while (*(short *)(param_1 + 2) != sVar1);
  load_descriptor_values(param_1);
  return 0;
}



// ===========================================================
// Function: pb_field_iter_begin_const at 00018cc4
// ===========================================================

void pb_field_iter_begin_const(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = 0;
  param_1[1] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  param_1[2] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  param_1[3] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  param_1[9] = 0;
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[4] = 0;
  param_1[5] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  param_1[6] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  param_1[7] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  param_1[8] = 0;
  load_descriptor_values();
  return;
}



// ===========================================================
// Function: pb_field_iter_begin_extension_const at 00018ce6
// ===========================================================

void pb_field_iter_begin_extension_const(void)

{
  pb_field_iter_begin_extension();
  return;
}



// ===========================================================
// Function: pb_default_field_callback at 00018cea
// ===========================================================

undefined4 pb_default_field_callback(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((*(short *)(param_3 + 0x12) == 8) &&
      (piVar2 = *(int **)(param_3 + 0x1c), piVar2 != (int *)0x0)) &&
     (((param_1 != 0 &&
       (UNRECOVERED_JUMPTABLE = (code *)*piVar2, UNRECOVERED_JUMPTABLE != (code *)0x0)) ||
      ((param_2 != 0 &&
       (UNRECOVERED_JUMPTABLE = (code *)*piVar2, param_1 = param_2,
       UNRECOVERED_JUMPTABLE != (code *)0x0)))))) {
                    /* WARNING: Could not recover jumptable at 0x00018d18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(param_1,param_3,piVar2 + 1);
    return uVar1;
  }
  return 1;
}



// ===========================================================
// Function: pb_read at 00018d20
// ===========================================================

void pb_read(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int local_14;
  
  local_14 = **(int **)(DAT_00018db8 + 0x18d2c);
  if (param_3 == 0) {
LAB_00018d54:
    uVar2 = 1;
  }
  else {
    if ((param_2 == 0) && (*param_1 != DAT_00018dbc + 0x18d60)) {
      uStack_24 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uStack_20 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uStack_1c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      local_28 = 0;
      for (; 0x10 < param_3; param_3 = param_3 - 0x10) {
        iVar3 = pb_read(param_1,&local_28,0x10);
        if (iVar3 == 0) goto LAB_00018d9e;
      }
      uVar2 = pb_read(param_1,&local_28,param_3);
      goto LAB_00018da0;
    }
    if ((uint)param_1[2] < param_3) {
      iVar1 = param_1[3];
      iVar3 = DAT_00018dc0 + 0x18d44;
    }
    else {
      iVar3 = (*(code *)*param_1)(param_1,param_2,param_3);
      if (iVar3 != 0) {
        param_1[2] = param_1[2] - param_3;
        goto LAB_00018d54;
      }
      iVar1 = param_1[3];
      iVar3 = DAT_00018dc4 + 0x18d98;
    }
    if (iVar1 != 0) {
      iVar3 = iVar1;
    }
    param_1[3] = iVar3;
LAB_00018d9e:
    uVar2 = 0;
  }
LAB_00018da0:
  if (**(int **)(DAT_00018dc8 + 0x18da8) != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: buf_read at 00018dcc
// ===========================================================

undefined4 buf_read(int param_1,void *param_2,size_t param_3)

{
  void *__src;
  
  __src = *(void **)(param_1 + 4);
  *(size_t *)(param_1 + 4) = (int)__src + param_3;
  if (param_2 != (void *)0x0) {
    __aeabi_memcpy8(param_2,__src,param_3);
  }
  return 1;
}



// ===========================================================
// Function: pb_istream_from_buffer at 00018de8
// ===========================================================

void pb_istream_from_buffer(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = DAT_00018e04;
  param_1[2] = param_3;
  param_1[3] = 0;
  *param_1 = iVar1 + 0x18dfa;
  param_1[1] = param_2;
  param_1[4] = 0;
  param_1[5] = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  param_1[6] = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  param_1[7] = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  return;
}



// ===========================================================
// Function: pb_decode_varint32 at 00018e08
// ===========================================================

void pb_decode_varint32(undefined4 param_1,undefined4 param_2)

{
  pb_decode_varint32_eof(param_1,param_2,0);
  return;
}



// ===========================================================
// Function: pb_decode_varint32_eof at 00018e10
// ===========================================================

void pb_decode_varint32_eof(int param_1,uint *param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint extraout_r2;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  byte local_1d;
  int local_1c;
  
  local_1c = **(int **)(DAT_00018f00 + 0x18e26);
  local_1d = 0;
  iVar1 = pb_readbyte(param_1,&local_1d);
  if (iVar1 == 0) {
    uVar2 = 0;
    if ((param_3 != (undefined1 *)0x0) && (*(int *)(param_1 + 8) == 0)) {
      *param_3 = 1;
LAB_00018e58:
      uVar2 = 0;
    }
  }
  else {
    uVar7 = (uint)local_1d;
    if ((char)local_1d < '\0') {
      uVar7 = uVar7 & 0x7f;
      uVar6 = 7;
      do {
        iVar1 = pb_readbyte(param_1,&local_1d);
        if (iVar1 == 0) goto LAB_00018e58;
        uVar6 = uVar6 & 0xff;
        if (uVar6 < 0x20) {
          uVar3 = (uint)local_1d;
          if (uVar6 == 0x1c) {
            bVar8 = (local_1d & 0x70) != 0;
            uVar4 = extraout_r2;
            if (bVar8) {
              uVar4 = uVar3 & 0x78;
            }
            if (bVar8 && uVar4 != 0x78) goto LAB_00018eee;
            uVar7 = uVar7 | uVar3 << 0x1c;
          }
          else {
            uVar7 = uVar7 | (uVar3 & 0x7f) << uVar6;
          }
        }
        else {
          if ((local_1d & 0x7f) == 0) {
            bVar8 = true;
          }
          else {
            bVar5 = 1;
            if (uVar6 < 0x3f) {
              bVar5 = 0xff;
            }
            bVar8 = (int)uVar7 < 0 && bVar5 == local_1d;
          }
          if ((0x3f < uVar6) || (!bVar8)) {
LAB_00018eee:
            iVar1 = DAT_00018f04 + 0x18ef6;
            if (*(int *)(param_1 + 0xc) != 0) {
              iVar1 = *(int *)(param_1 + 0xc);
            }
            *(int *)(param_1 + 0xc) = iVar1;
            goto LAB_00018e58;
          }
        }
        uVar6 = uVar6 + 7;
      } while ((char)local_1d < '\0');
    }
    uVar2 = 1;
    *param_2 = uVar7;
  }
  if (**(int **)(DAT_00018f08 + 0x18e62) != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: pb_decode_varint at 00018f0c
// ===========================================================

void pb_decode_varint(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte local_21;
  int local_20;
  
  uVar6 = 0;
  uVar8 = 0;
  uVar5 = 0;
  local_20 = **(int **)(DAT_00018fa4 + 0x18f26);
  local_21 = 0;
  do {
    iVar1 = pb_readbyte(param_1,&local_21);
    if (iVar1 == 0) {
LAB_00018f8a:
      uVar2 = 0;
      goto LAB_00018f8c;
    }
    uVar6 = uVar6 & 0xff;
    if (0x3e < uVar6 && 1 < local_21) {
      iVar1 = DAT_00018fa8 + 0x18f84;
      if (*(int *)(param_1 + 0xc) != 0) {
        iVar1 = *(int *)(param_1 + 0xc);
      }
      *(int *)(param_1 + 0xc) = iVar1;
      goto LAB_00018f8a;
    }
    uVar4 = local_21 & 0x7f;
    uVar3 = uVar6 - 0x20;
    uVar7 = uVar4 >> (0x20 - uVar6 & 0xff);
    if (-1 < (int)uVar3) {
      uVar7 = uVar4 << (uVar3 & 0xff);
    }
    uVar4 = uVar4 << uVar6;
    uVar5 = uVar5 | uVar7;
    uVar6 = uVar6 + 7;
    if (-1 < (int)uVar3) {
      uVar4 = 0;
    }
    uVar8 = uVar8 | uVar4;
  } while ((char)local_21 < '\0');
  uVar2 = 1;
  *param_2 = uVar8;
  param_2[1] = uVar5;
LAB_00018f8c:
  if (**(int **)(DAT_00018fac + 0x18f94) != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: pb_readbyte at 00018fb0
// ===========================================================

undefined4 pb_readbyte(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1[2] == 0) {
    iVar2 = param_1[3];
    iVar1 = DAT_00018fe8 + 0x18fd4;
  }
  else {
    iVar1 = (*(code *)*param_1)(param_1,param_2,1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + -1;
      return 1;
    }
    iVar2 = param_1[3];
    iVar1 = DAT_00018fec + 0x18fdc;
  }
  if (iVar2 != 0) {
    iVar1 = iVar2;
  }
  param_1[3] = iVar1;
  return 0;
}



// ===========================================================
// Function: pb_decode_tag at 00018ff0
// ===========================================================

void pb_decode_tag(undefined4 param_1,uint *param_2,uint *param_3,undefined1 *param_4)

{
  int iVar1;
  uint local_18;
  int local_14;
  
  local_14 = **(int **)(DAT_00019038 + 0x18ffe);
  *param_4 = 0;
  *param_2 = 0;
  *param_3 = 0;
  local_18 = 0;
  iVar1 = pb_decode_varint32_eof(param_1,&local_18,param_4);
  if (iVar1 != 0) {
    *param_3 = local_18 >> 3;
    *param_2 = local_18 & 7;
  }
  if (**(int **)(DAT_0001903c + 0x1902a) != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// ===========================================================
// Function: pb_skip_field at 00019040
// ===========================================================

void pb_skip_field(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  char local_19;
  undefined4 local_18;
  int local_14;
  
  local_14 = **(int **)(DAT_000190fc + 0x1904e);
  switch(param_2) {
  case 0:
    local_19 = '\0';
    do {
      iVar1 = pb_read(param_1,&local_19,1);
      if (iVar1 == 0) break;
    } while (local_19 < '\0');
    break;
  case 1:
    if (**(int **)(DAT_00019100 + 0x19088) == local_14) {
      uVar2 = 8;
LAB_000190f0:
      __ThumbV7PILongThunk_pb_read(param_1,0,uVar2);
      return;
    }
    goto LAB_000190d8;
  case 2:
    local_18 = 0;
    iVar1 = pb_decode_varint32_eof(param_1,&local_18,0);
    if (iVar1 != 0) {
      pb_read(param_1,0,local_18);
    }
    break;
  default:
    iVar1 = DAT_00019108 + 0x190be;
    if (*(int *)(param_1 + 0xc) != 0) {
      iVar1 = *(int *)(param_1 + 0xc);
    }
    *(int *)(param_1 + 0xc) = iVar1;
    break;
  case 5:
    if (**(int **)(DAT_00019104 + 0x190e4) == local_14) {
      uVar2 = 4;
      goto LAB_000190f0;
    }
    goto LAB_000190d8;
  }
  if (**(int **)(DAT_0001910c + 0x190cc) == local_14) {
    return;
  }
LAB_000190d8:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_14);
}



// ===========================================================
// Function: pb_make_string_substream at 00019110
// ===========================================================

void pb_make_string_substream(undefined8 *param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint local_18;
  int local_14;
  
  local_14 = **(int **)(DAT_00019184 + 0x19124);
  local_18 = 0;
  iVar1 = pb_decode_varint32_eof(param_1,&local_18,0);
  if (iVar1 != 0) {
    uVar2 = param_1[1];
    uVar3 = param_1[2];
    uVar4 = param_1[3];
    *param_2 = *param_1;
    param_2[1] = uVar2;
    param_2[2] = uVar3;
    param_2[3] = uVar4;
    if (*(uint *)(param_2 + 1) < local_18) {
      iVar1 = DAT_00019188 + 0x19158;
      if (*(int *)((int)param_1 + 0xc) != 0) {
        iVar1 = *(int *)((int)param_1 + 0xc);
      }
      *(int *)((int)param_1 + 0xc) = iVar1;
    }
    else {
      *(uint *)(param_2 + 1) = local_18;
      *(uint *)(param_1 + 1) = *(int *)(param_1 + 1) - local_18;
    }
  }
  if (**(int **)(DAT_0001918c + 0x19172) != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}



// ===========================================================
// Function: pb_close_string_substream at 00019190
// ===========================================================

undefined4 pb_close_string_substream(int param_1,int param_2)

{
  int iVar1;
  
  if ((*(int *)(param_2 + 8) != 0) && (iVar1 = pb_read(param_2,0), iVar1 == 0)) {
    return 0;
  }
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  return 1;
}



// ===========================================================
// Function: pb_decode_ex at 000191b4
// ===========================================================

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void pb_decode_ex(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  undefined4 uVar13;
  uint uStack_b0;
  uint uStack_a8;
  char cStack_a1;
  int iStack_a0;
  uint uStack_9c;
  uint uStack_98;
  undefined4 *puStack_94;
  uint uStack_90;
  undefined4 uStack_8c;
  uint uStack_88;
  undefined4 *puStack_84;
  ushort *puStack_80;
  undefined4 uStack_7c;
  ushort uStack_72;
  uint uStack_70;
  int iStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint uStack_60;
  int iStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint auStack_48 [4];
  undefined4 local_38;
  undefined4 uStack_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  
  iVar1 = **(int **)(DAT_0001924c + 0x191c6);
  if ((int)(param_4 << 0x1e) < 0) {
    uStack_34 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    local_30 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    local_2c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    local_38 = 0;
    local_28 = 0;
    uStack_24 = uStack_34;
    iStack_20 = local_30;
    uStack_1c = local_2c;
    iVar5 = pb_make_string_substream(param_1);
    if ((iVar5 != 0) &&
       ((pb_decode_inner(&local_38,param_2,param_3,param_4), local_30 == 0 ||
        (iVar5 = pb_read(&local_38,0), iVar5 != 0)))) {
      *(undefined4 *)(param_1 + 4) = uStack_34;
      *(undefined4 *)(param_1 + 0xc) = local_2c;
    }
    iVar5 = **(int **)(DAT_00019254 + 0x1923a);
    if (iVar5 == iVar1) {
      return;
    }
LAB_00019246:
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1,iVar5);
  }
  iVar5 = **(int **)(DAT_00019250 + 0x191d6);
  if (iVar5 != iVar1) goto LAB_00019246;
  uStack_9c = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_98 = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  puStack_94 = *(undefined4 **)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  auStack_48[3] = **(int **)(DAT_000194ec + 0x19276);
  iStack_a0 = 0;
  uStack_90 = 0;
  uStack_72 = 0;
  auStack_48[0] = 0;
  auStack_48[1] = 0;
  uStack_7c = 0;
  puStack_80 = (ushort *)0x0;
  uStack_8c = uStack_9c;
  uStack_88 = uStack_98;
  puStack_84 = puStack_94;
  iVar1 = pb_field_iter_begin(&iStack_a0,param_2,param_3);
  if ((((param_4 & 1) == 0) && (iVar1 != 0)) &&
     (iVar1 = pb_message_set_to_defaults(&iStack_a0), iVar1 == 0)) {
    iVar5 = *(int *)(param_1 + 0xc);
    iVar1 = DAT_000194f0 + 0x1943e;
LAB_000194c2:
    if (iVar5 != 0) {
      iVar1 = iVar5;
    }
    *(int *)(param_1 + 0xc) = iVar1;
LAB_000194ca:
    uVar4 = 0;
  }
  else {
    if (*(int *)(param_1 + 8) != 0) {
      uVar3 = 0;
      iVar1 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uVar13 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      uVar10 = 0;
      puVar9 = (undefined4 *)0x0;
      uStack_b0 = 0;
      uStack_a8 = 0xffff;
      do {
        cStack_a1 = '\0';
        uStack_70 = 0;
        iVar5 = pb_decode_varint32_eof(param_1,&uStack_70,&cStack_a1);
        if (iVar5 == 0) {
          if (cStack_a1 == '\0') goto LAB_000194ca;
          break;
        }
        uVar7 = uStack_70 >> 3;
        if (uVar7 == 0) {
          if (-1 < (int)(param_4 << 0x1d)) {
            iVar5 = *(int *)(param_1 + 0xc);
            iVar1 = DAT_000194f4 + 0x19454;
            goto LAB_000194c2;
          }
          break;
        }
        uVar11 = uStack_70 & 7;
        iVar5 = pb_field_iter_find(&iStack_a0,uVar7);
        if ((iVar5 == 0) || ((uStack_8c._2_1_ & 0xf) == 10)) {
          if (uVar10 == 0) {
            iVar5 = pb_field_iter_find_extension(&iStack_a0);
            if (iVar5 == 0) {
              uVar10 = 0;
            }
            else {
              uVar10 = uStack_90 & 0xffff;
              puVar9 = (undefined4 *)*puStack_84;
            }
            if (puVar9 == (undefined4 *)0x0) {
              uVar10 = 0xffffffff;
            }
          }
          if ((uVar7 < uVar10) || (puVar9 == (undefined4 *)0x0)) {
LAB_000193e6:
            iVar5 = pb_skip_field(param_1,uVar11);
            goto LAB_00019426;
          }
          iVar5 = *(int *)(param_1 + 8);
          puVar8 = puVar9;
          do {
            iVar2 = *(int *)(param_1 + 8);
            if (iVar5 != iVar2) goto LAB_000193e0;
            if (*(code **)*puVar8 == (code *)0x0) {
              uStack_4c = 0;
              uStack_50 = 0;
              uStack_70 = uVar3;
              iStack_6c = iVar1;
              uStack_68 = uVar4;
              uStack_64 = uVar13;
              uStack_60 = uVar3;
              iStack_5c = iVar1;
              uStack_58 = uVar4;
              uStack_54 = uVar13;
              iVar2 = pb_field_iter_begin_extension(&uStack_70,puVar8);
              if (iVar2 == 0) {
                iVar5 = *(int *)(param_1 + 0xc);
                iVar1 = DAT_000194f8 + 0x194c4;
                goto LAB_000194c2;
              }
              if ((uVar7 == (uStack_60 & 0xffff)) && (iStack_6c != 0)) {
                *(undefined1 *)(puVar8 + 3) = 1;
                iVar2 = decode_field(param_1,uVar11,&uStack_70);
                goto LAB_000193d4;
              }
            }
            else {
              iVar2 = (**(code **)*puVar8)(param_1,puVar8,uVar7,uVar11);
LAB_000193d4:
              if (iVar2 == 0) goto LAB_000194ca;
            }
            puVar8 = (undefined4 *)puVar8[2];
          } while (puVar8 != (undefined4 *)0x0);
          iVar2 = *(int *)(param_1 + 8);
LAB_000193e0:
          if (iVar5 == iVar2) goto LAB_000193e6;
        }
        else {
          if (((uStack_8c._2_1_ & 0x30) == 0x20) && (puStack_80 == (ushort *)&uStack_8c)) {
            if (uStack_a8 != (uStack_98 & 0xffff)) {
              if ((uStack_a8 != 0xffff) && (uStack_72 != uStack_b0)) goto LAB_000194b4;
              uStack_b0 = uStack_8c & 0xffff;
              uStack_72 = 0;
              uStack_a8 = uStack_98 & 0xffff;
            }
            puStack_80 = &uStack_72;
          }
          if (((uStack_8c & 0x300000) == 0) && (((uint)puStack_94 & 0xffff) < 0x40)) {
            uVar7 = (uint)puStack_94 >> 5 & 0x7ff;
            auStack_48[uVar7] = 1 << ((uint)puStack_94 & 0x1f) | auStack_48[uVar7];
          }
          iVar5 = decode_field(param_1,uVar11,&iStack_a0);
LAB_00019426:
          if (iVar5 == 0) goto LAB_000194ca;
        }
      } while (*(int *)(param_1 + 8) != 0);
      uVar3 = 0xffff;
      bVar12 = uStack_a8 != 0xffff;
      if (bVar12) {
        uVar3 = (uint)uStack_72;
        uStack_a8 = uStack_b0;
      }
      if (bVar12 && uVar3 != uStack_a8) {
LAB_000194b4:
        iVar5 = *(int *)(param_1 + 0xc);
        iVar1 = DAT_000194fc + 0x194bc;
        goto LAB_000194c2;
      }
    }
    uVar3 = (uint)*(ushort *)(iStack_a0 + 0x12);
    if (uVar3 != 0) {
      if (0x3f < uVar3) {
        uVar3 = 0x40;
      }
      if (0x1f < uVar3) {
        uVar10 = 0;
        puVar6 = auStack_48;
        do {
          if (*puVar6 != 0xffffffff) goto LAB_000194ac;
          uVar10 = uVar10 + 1;
          puVar6 = puVar6 + 1;
        } while (uVar10 < uVar3 >> 5);
      }
      if (((uVar3 & 0x1f) != 0) &&
         (auStack_48[uVar3 >> 5] != 0xffffffffU >> (0x20 - (uVar3 & 0x1f) & 0xff))) {
LAB_000194ac:
        iVar5 = *(int *)(param_1 + 0xc);
        iVar1 = DAT_00019500 + 0x194b4;
        goto LAB_000194c2;
      }
    }
    uVar4 = 1;
  }
  if (**(int **)(DAT_00019504 + 0x194d4) == auStack_48[3]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar4);
}



// ===========================================================
// Function: pb_decode_inner at 00019258
// ===========================================================

void pb_decode_inner(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  undefined4 uVar13;
  uint local_b0;
  uint local_a8;
  char local_a1;
  int local_a0;
  uint uStack_9c;
  uint local_98;
  undefined4 *local_94;
  uint local_90;
  undefined4 uStack_8c;
  uint uStack_88;
  undefined4 *local_84;
  ushort *local_80;
  undefined4 local_7c;
  ushort local_72;
  uint local_70;
  int iStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint local_60;
  int iStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48 [9];
  
  uStack_9c = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  local_98 = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  local_94 = *(undefined4 **)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_48[3] = **(int **)(DAT_000194ec + 0x19276);
  local_a0 = 0;
  local_90 = 0;
  local_72 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_7c = 0;
  local_80 = (ushort *)0x0;
  uStack_8c = uStack_9c;
  uStack_88 = local_98;
  local_84 = local_94;
  iVar1 = pb_field_iter_begin(&local_a0);
  if ((((param_4 & 1) == 0) && (iVar1 != 0)) &&
     (iVar1 = pb_message_set_to_defaults(&local_a0), iVar1 == 0)) {
    iVar2 = *(int *)(param_1 + 0xc);
    iVar1 = DAT_000194f0 + 0x1943e;
LAB_000194c2:
    if (iVar2 != 0) {
      iVar1 = iVar2;
    }
    *(int *)(param_1 + 0xc) = iVar1;
LAB_000194ca:
    uVar5 = 0;
  }
  else {
    if (*(int *)(param_1 + 8) != 0) {
      uVar4 = 0;
      iVar1 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uVar13 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      uVar10 = 0;
      puVar9 = (undefined4 *)0x0;
      local_b0 = 0;
      local_a8 = 0xffff;
      do {
        local_a1 = '\0';
        local_70 = 0;
        iVar2 = pb_decode_varint32_eof(param_1,&local_70,&local_a1);
        if (iVar2 == 0) {
          if (local_a1 == '\0') goto LAB_000194ca;
          break;
        }
        uVar7 = local_70 >> 3;
        if (uVar7 == 0) {
          if (-1 < (int)(param_4 << 0x1d)) {
            iVar2 = *(int *)(param_1 + 0xc);
            iVar1 = DAT_000194f4 + 0x19454;
            goto LAB_000194c2;
          }
          break;
        }
        uVar11 = local_70 & 7;
        iVar2 = pb_field_iter_find(&local_a0,uVar7);
        if ((iVar2 == 0) || ((uStack_8c._2_1_ & 0xf) == 10)) {
          if (uVar10 == 0) {
            iVar2 = pb_field_iter_find_extension(&local_a0);
            if (iVar2 == 0) {
              uVar10 = 0;
            }
            else {
              uVar10 = local_90 & 0xffff;
              puVar9 = (undefined4 *)*local_84;
            }
            if (puVar9 == (undefined4 *)0x0) {
              uVar10 = 0xffffffff;
            }
          }
          if ((uVar7 < uVar10) || (puVar9 == (undefined4 *)0x0)) {
LAB_000193e6:
            iVar2 = pb_skip_field(param_1,uVar11);
            goto LAB_00019426;
          }
          iVar2 = *(int *)(param_1 + 8);
          puVar8 = puVar9;
          do {
            iVar3 = *(int *)(param_1 + 8);
            if (iVar2 != iVar3) goto LAB_000193e0;
            if (*(code **)*puVar8 == (code *)0x0) {
              local_4c = 0;
              local_50 = 0;
              local_70 = uVar4;
              iStack_6c = iVar1;
              uStack_68 = uVar5;
              uStack_64 = uVar13;
              local_60 = uVar4;
              iStack_5c = iVar1;
              uStack_58 = uVar5;
              uStack_54 = uVar13;
              iVar3 = pb_field_iter_begin_extension(&local_70,puVar8);
              if (iVar3 == 0) {
                iVar2 = *(int *)(param_1 + 0xc);
                iVar1 = DAT_000194f8 + 0x194c4;
                goto LAB_000194c2;
              }
              if ((uVar7 == (local_60 & 0xffff)) && (iStack_6c != 0)) {
                *(undefined1 *)(puVar8 + 3) = 1;
                iVar3 = decode_field(param_1,uVar11,&local_70);
                goto LAB_000193d4;
              }
            }
            else {
              iVar3 = (**(code **)*puVar8)(param_1,puVar8,uVar7,uVar11);
LAB_000193d4:
              if (iVar3 == 0) goto LAB_000194ca;
            }
            puVar8 = (undefined4 *)puVar8[2];
          } while (puVar8 != (undefined4 *)0x0);
          iVar3 = *(int *)(param_1 + 8);
LAB_000193e0:
          if (iVar2 == iVar3) goto LAB_000193e6;
        }
        else {
          if (((uStack_8c._2_1_ & 0x30) == 0x20) && (local_80 == (ushort *)&uStack_8c)) {
            if (local_a8 != (local_98 & 0xffff)) {
              if ((local_a8 != 0xffff) && (local_72 != local_b0)) goto LAB_000194b4;
              local_b0 = uStack_8c & 0xffff;
              local_72 = 0;
              local_a8 = local_98 & 0xffff;
            }
            local_80 = &local_72;
          }
          if (((uStack_8c & 0x300000) == 0) && (((uint)local_94 & 0xffff) < 0x40)) {
            uVar7 = (uint)local_94 >> 5 & 0x7ff;
            local_48[uVar7] = 1 << ((uint)local_94 & 0x1f) | local_48[uVar7];
          }
          iVar2 = decode_field(param_1,uVar11,&local_a0);
LAB_00019426:
          if (iVar2 == 0) goto LAB_000194ca;
        }
      } while (*(int *)(param_1 + 8) != 0);
      uVar4 = 0xffff;
      bVar12 = local_a8 != 0xffff;
      if (bVar12) {
        uVar4 = (uint)local_72;
        local_a8 = local_b0;
      }
      if (bVar12 && uVar4 != local_a8) {
LAB_000194b4:
        iVar2 = *(int *)(param_1 + 0xc);
        iVar1 = DAT_000194fc + 0x194bc;
        goto LAB_000194c2;
      }
    }
    uVar4 = (uint)*(ushort *)(local_a0 + 0x12);
    if (uVar4 != 0) {
      if (0x3f < uVar4) {
        uVar4 = 0x40;
      }
      if (0x1f < uVar4) {
        uVar10 = 0;
        puVar6 = local_48;
        do {
          if (*puVar6 != 0xffffffff) goto LAB_000194ac;
          uVar10 = uVar10 + 1;
          puVar6 = puVar6 + 1;
        } while (uVar10 < uVar4 >> 5);
      }
      if (((uVar4 & 0x1f) != 0) &&
         (local_48[uVar4 >> 5] != 0xffffffffU >> (0x20 - (uVar4 & 0x1f) & 0xff))) {
LAB_000194ac:
        iVar2 = *(int *)(param_1 + 0xc);
        iVar1 = DAT_00019500 + 0x194b4;
        goto LAB_000194c2;
      }
    }
    uVar5 = 1;
  }
  if (**(int **)(DAT_00019504 + 0x194d4) == local_48[3]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar5);
}



// ===========================================================
// Function: pb_decode at 00019508
// ===========================================================

void pb_decode(void)

{
  pb_decode_inner();
  return;
}



// ===========================================================
// Function: pb_decode_bool at 00019510
// ===========================================================

void pb_decode_bool(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_c = **(int **)(DAT_00019550 + 0x1951e);
  local_10 = 0;
  iVar1 = pb_decode_varint32_eof(param_1,&local_10,0);
  if (iVar1 != 0) {
    *(bool *)param_2 = local_10 != 0;
  }
  if (**(int **)(DAT_00019554 + 0x19540) != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// ===========================================================
// Function: pb_decode_svarint at 00019558
// ===========================================================

void pb_decode_svarint(undefined4 param_1,uint *param_2)

{
  int iVar1;
  uint local_20;
  uint uStack_1c;
  int local_14;
  
  local_14 = **(int **)(DAT_000195ac + 0x19566);
  local_20 = 0;
  uStack_1c = 0;
  iVar1 = pb_decode_varint(param_1,&local_20);
  if (iVar1 != 0) {
    *param_2 = -(local_20 & 1) ^ ((uint)((uStack_1c & 1) != 0) << 0x1f | local_20 >> 1);
    param_2[1] = uStack_1c >> 1 ^ -(uint)((local_20 & 1) != 0);
  }
  if (**(int **)(DAT_000195b0 + 0x1959e) != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// ===========================================================
// Function: pb_decode_fixed32 at 000195b4
// ===========================================================

void pb_decode_fixed32(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_10;
  int local_c;
  
  local_c = **(int **)(DAT_000195ec + 0x195c2);
  local_10 = 0;
  iVar1 = pb_read(param_1,&local_10,4);
  if (iVar1 != 0) {
    *param_2 = local_10;
  }
  if (**(int **)(DAT_000195f0 + 0x195de) != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// ===========================================================
// Function: pb_decode_fixed64 at 000195f4
// ===========================================================

void pb_decode_fixed64(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  int local_c;
  
  local_c = **(int **)(DAT_00019634 + 0x19602);
  local_18 = 0;
  uStack_14 = 0;
  iVar1 = pb_read(param_1,&local_18,8);
  if (iVar1 != 0) {
    *param_2 = local_18;
    param_2[1] = uStack_14;
  }
  if (**(int **)(DAT_00019638 + 0x19624) != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// ===========================================================
// Function: pb_message_set_to_defaults at 0001963c
// ===========================================================

void pb_message_set_to_defaults(int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined1 local_89;
  int local_88;
  int iStack_84;
  undefined4 uStack_80;
  undefined4 local_7c;
  undefined4 local_78;
  int iStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  uint local_68;
  int iStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint local_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_3c;
  
  uVar8 = 0;
  iVar9 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar10 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_3c = **(int **)(DAT_000197e4 + 0x19656);
  local_89 = 0;
  local_88 = 0;
  local_78 = 0;
  iStack_84 = *(int *)(*param_1 + 8);
  iStack_74 = iVar9;
  uStack_70 = uVar4;
  uStack_6c = uVar10;
  if (iStack_84 == 0) {
    uVar6 = 0;
    uVar7 = 0;
    iStack_84 = iVar9;
    uStack_80 = uVar4;
    local_7c = uVar10;
  }
  else {
    local_7c = 0;
    local_78 = 0;
    uStack_80 = 0xffffffff;
    local_89 = 0;
    local_68 = 0;
    local_88 = DAT_000197e8 + 0x19692;
    iVar2 = pb_decode_varint32_eof(&local_88,&local_68,&local_89);
    if (iVar2 == 0) {
LAB_000197c0:
      uVar4 = 0;
      goto LAB_000197c2;
    }
    uVar6 = local_68 & 7;
    uVar7 = local_68 >> 3;
  }
  do {
    bVar1 = *(byte *)((int)param_1 + 0x16);
    if ((bVar1 & 0xf) == 10) {
      for (iVar2 = *(int *)param_1[7]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
        local_44 = 0;
        local_48 = 0;
        local_68 = uVar8;
        iStack_64 = iVar9;
        uStack_60 = uVar4;
        uStack_5c = uVar10;
        local_58 = uVar8;
        iStack_54 = iVar9;
        uStack_50 = uVar4;
        uStack_4c = uVar10;
        iVar3 = pb_field_iter_begin_extension(&local_68,iVar2);
        if (iVar3 != 0) {
          *(undefined1 *)(iVar2 + 0xc) = 0;
          iVar3 = pb_message_set_to_defaults(&local_68);
          if (iVar3 == 0) goto LAB_000197c0;
        }
      }
    }
    else if ((bVar1 & 0xc0) == 0x80) {
      *(undefined4 *)param_1[6] = 0;
      if ((bVar1 & 0x30 | 0x10) == 0x30) {
LAB_00019764:
        *(undefined2 *)param_1[8] = 0;
      }
    }
    else if ((bVar1 & 0xc0) == 0) {
      bVar5 = bVar1 & 0x30;
      if (bVar5 == 0x30 || bVar5 == 0x20) goto LAB_00019764;
      if ((bVar5 == 0x10) && ((undefined1 *)param_1[8] != (undefined1 *)0x0)) {
        *(undefined1 *)param_1[8] = 0;
        bVar1 = *(byte *)((int)param_1 + 0x16);
      }
      if (((bVar1 & 0xe) == 8) &&
         (((iVar2 = param_1[9], *(int *)(iVar2 + 8) != 0 || (*(int *)(iVar2 + 0xc) != 0)) ||
          (**(int **)(iVar2 + 4) != 0)))) {
        local_44 = 0;
        local_48 = 0;
        local_68 = uVar8;
        iStack_64 = iVar9;
        uStack_60 = uVar4;
        uStack_5c = uVar10;
        local_58 = uVar8;
        iStack_54 = iVar9;
        uStack_50 = uVar4;
        uStack_4c = uVar10;
        iVar2 = pb_field_iter_begin(&local_68,iVar2,param_1[7]);
        if ((iVar2 != 0) && (iVar2 = pb_message_set_to_defaults(&local_68), iVar2 == 0))
        goto LAB_000197c0;
      }
      else {
        __aeabi_memclr8(param_1[7],*(undefined2 *)((int)param_1 + 0x12));
      }
    }
    if (uVar7 == 0) {
      uVar7 = 0;
    }
    else if (uVar7 == *(ushort *)(param_1 + 4)) {
      iVar2 = decode_field(&local_88,uVar6,param_1);
      if (iVar2 == 0) goto LAB_000197c0;
      local_89 = 0;
      local_68 = 0;
      iVar2 = pb_decode_varint32_eof(&local_88,&local_68,&local_89);
      if (iVar2 == 0) goto LAB_000197c0;
      uVar6 = local_68 & 7;
      uVar7 = local_68 >> 3;
      if ((undefined1 *)param_1[8] != (undefined1 *)0x0) {
        *(undefined1 *)param_1[8] = 0;
      }
    }
    iVar2 = pb_field_iter_next(param_1);
  } while (iVar2 != 0);
  uVar4 = 1;
LAB_000197c2:
  if (**(int **)(DAT_000197ec + 0x197ca) != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



// ===========================================================
// Function: decode_field at 000197f0
// ===========================================================

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void decode_field(int param_1,int param_2,int *param_3)

{
  ushort uVar1;
  char cVar2;
  bool bVar3;
  byte bVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  undefined *puVar8;
  undefined2 *puVar9;
  short sVar10;
  undefined4 uVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  char *pcVar15;
  ushort *puVar16;
  int local_50;
  undefined4 *puStack_4c;
  uint local_48;
  int local_44;
  uint local_40;
  undefined4 *puStack_3c;
  uint uStack_38;
  uint uStack_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined2 local_20;
  undefined4 uStack_1c;
  int local_18;
  
  local_18 = **(int **)(DAT_00019ab4 + 0x197fe);
  bVar4 = *(byte *)((int)param_3 + 0x16);
  if ((bVar4 & 0xc0) == 0x80) {
    iVar5 = *(int *)(param_1 + 0xc);
    iVar7 = DAT_00019ac4 + 0x19838;
LAB_0001989a:
    if (iVar5 != 0) {
      iVar7 = iVar5;
    }
    *(int *)(param_1 + 0xc) = iVar7;
LAB_000198a4:
    if (**(int **)(DAT_00019ae0 + 0x198ac) == local_18) {
      return;
    }
LAB_00019a2e:
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_18);
  }
  if ((bVar4 & 0xc0) == 0x40) {
    if (*(int *)(*param_3 + 0xc) == 0) {
      if (**(int **)(DAT_00019ac8 + 0x198c2) == local_18) {
        pb_skip_field(param_1,param_2);
        return;
      }
      goto LAB_00019a2e;
    }
    if (param_2 == 2) {
      puStack_4c = *(undefined4 **)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      local_48 = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      local_44 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      local_50 = 0;
      local_40 = 0;
      puStack_3c = puStack_4c;
      uStack_38 = local_48;
      uStack_34 = local_44;
      iVar7 = pb_make_string_substream(param_1);
      if (iVar7 != 0) {
        do {
          uVar14 = local_48;
          iVar7 = (**(code **)(*param_3 + 0xc))(&local_50,0,param_3);
          if (iVar7 == 0) {
            iVar7 = DAT_00019acc + 0x19a3a;
            if (local_44 != 0) {
              iVar7 = local_44;
            }
            iVar5 = *(int *)(param_1 + 0xc);
            goto LAB_0001989a;
          }
        } while ((local_48 != 0) && (local_48 < uVar14));
        if ((local_48 == 0) || (iVar7 = pb_read(&local_50,0), iVar7 != 0)) {
          *(undefined4 **)(param_1 + 4) = puStack_4c;
          *(int *)(param_1 + 0xc) = local_44;
        }
      }
      goto LAB_000198a4;
    }
    local_28 = 0;
    uStack_24 = 0;
    local_20 = 0;
    if (param_2 == 5) {
      uVar14 = 4;
      uVar11 = 4;
LAB_00019a54:
      iVar7 = pb_read(param_1,&local_28,uVar11);
      if (iVar7 == 0) goto LAB_000198a4;
    }
    else {
      if (param_2 == 1) {
        uVar14 = 8;
        uVar11 = 8;
        goto LAB_00019a54;
      }
      if (param_2 != 0) {
        iVar5 = *(int *)(param_1 + 0xc);
        iVar7 = DAT_00019ad8 + 0x19a92;
        goto LAB_0001989a;
      }
      uVar14 = 0;
      pcVar15 = (char *)&local_28;
      do {
        if (uVar14 == 10) {
          iVar5 = *(int *)(param_1 + 0xc);
          iVar7 = DAT_00019ad0 + 0x19a9a;
          goto LAB_0001989a;
        }
        iVar7 = pb_read(param_1,pcVar15,1);
        if (iVar7 == 0) goto LAB_000198a4;
        cVar2 = *pcVar15;
        uVar14 = uVar14 + 1;
        pcVar15 = pcVar15 + 1;
      } while (cVar2 < '\0');
    }
    puStack_3c = *(undefined4 **)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_38 = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_34 = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    local_40 = 0;
    local_44 = 0;
    puStack_4c = &local_28;
    local_50 = DAT_00019ad4 + 0x19a7e;
    local_48 = uVar14;
    (**(code **)(*param_3 + 0xc))(&local_50,0,param_3);
    goto LAB_000198a4;
  }
  if ((bVar4 & 0xc0) != 0) {
    iVar5 = *(int *)(param_1 + 0xc);
    iVar7 = DAT_00019adc + 0x1989c;
    goto LAB_0001989a;
  }
  switch(bVar4 & 0x3f) {
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    if ((undefined1 *)param_3[8] != (undefined1 *)0x0) {
      *(undefined1 *)param_3[8] = 1;
    }
    break;
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
    if ((param_2 == 2) && ((bVar4 & 0xe) < 6)) {
      puVar16 = (ushort *)param_3[8];
      puStack_4c = *(undefined4 **)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      local_48 = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      local_44 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      local_50 = 0;
      local_40 = 0;
      param_3[7] = (uint)*puVar16 * (uint)*(ushort *)((int)param_3 + 0x12) + param_3[6];
      puStack_3c = puStack_4c;
      uStack_38 = local_48;
      uStack_34 = local_44;
      iVar7 = pb_make_string_substream(param_1);
      if (iVar7 != 0) {
        while (local_48 != 0) {
          if (*(ushort *)(param_3 + 5) <= *puVar16) goto LAB_00019aa6;
          iVar7 = decode_basic_field(&local_50,0xff,param_3);
          if (iVar7 == 0) {
            if (local_48 != 0) goto LAB_00019aa6;
            break;
          }
          *puVar16 = *puVar16 + 1;
          param_3[7] = (uint)*(ushort *)((int)param_3 + 0x12) + param_3[7];
        }
        pb_close_string_substream(param_1,&local_50);
      }
      goto LAB_000198a4;
    }
    puVar16 = (ushort *)param_3[8];
    param_3[7] = (uint)*puVar16 * (uint)*(ushort *)((int)param_3 + 0x12) + param_3[6];
    uVar1 = *puVar16;
    *puVar16 = uVar1 + 1;
    if (*(ushort *)(param_3 + 5) <= uVar1) {
LAB_00019aa6:
      iVar5 = *(int *)(param_1 + 0xc);
      iVar7 = DAT_00019abc + 0x19aae;
      goto LAB_0001989a;
    }
    break;
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
    if (((bVar4 & 0xe) == 8) && (*(short *)param_3[8] != (short)param_3[4])) {
      __aeabi_memclr8(param_3[7],*(undefined2 *)((int)param_3 + 0x12));
      iVar7 = param_3[9];
      if ((*(int *)(iVar7 + 8) != 0) ||
         ((*(int *)(iVar7 + 0xc) != 0 || (**(int **)(iVar7 + 4) != 0)))) {
        puStack_4c = *(undefined4 **)((undefined1  [16])0x0 + (undefined1  [16])0x4);
        local_48 = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
        local_44 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
        local_2c = 0;
        local_50 = 0;
        local_40 = 0;
        local_30 = 0;
        puStack_3c = puStack_4c;
        uStack_38 = local_48;
        uStack_34 = local_44;
        iVar7 = pb_field_iter_begin(&local_50,iVar7,param_3[7]);
        if ((iVar7 != 0) && (iVar7 = pb_message_set_to_defaults(&local_50), iVar7 == 0)) {
          iVar5 = *(int *)(param_1 + 0xc);
          iVar7 = DAT_00019ac0 + 0x19aa2;
          goto LAB_0001989a;
        }
      }
    }
    *(short *)param_3[8] = (short)param_3[4];
    decode_basic_field(param_1,param_2,param_3);
    goto LAB_000198a4;
  }
  if (**(int **)(DAT_00019ab8 + 0x19a16) != local_18) goto LAB_00019a2e;
  local_18 = **(int **)(DAT_00019e5c + 0x19af2);
  bVar4 = *(byte *)((int)param_3 + 0x16) & 0xf;
  switch(bVar4) {
  case 0:
    if ((param_2 == 0) || (param_2 == 0xff)) {
      iVar5 = param_3[7];
      uStack_38 = 0;
      iVar7 = pb_decode_varint32_eof(param_1,&uStack_38,0);
      if (iVar7 != 0) {
        *(bool *)iVar5 = uStack_38 != 0;
      }
      goto LAB_00019cdc;
    }
    goto LAB_00019ccc;
  case 1:
  case 2:
  case 3:
    if ((param_2 != 0) && (param_2 != 0xff)) goto LAB_00019ccc;
    if (bVar4 == 2) {
      uStack_38 = 0;
      uStack_34 = 0;
      iVar7 = pb_decode_varint(param_1,&uStack_38);
      if (iVar7 == 0) goto LAB_00019cdc;
      switch(*(undefined2 *)((int)param_3 + 0x12)) {
      case 1:
        *(char *)param_3[7] = (char)uStack_38;
        uVar14 = uStack_38 & 0xff;
        break;
      case 2:
        *(short *)param_3[7] = (short)uStack_38;
        uVar14 = uStack_38 & 0xffff;
        break;
      default:
        goto switchD_00019b40_caseD_3;
      case 4:
        *(uint *)param_3[7] = uStack_38;
        uVar12 = 0;
        uVar14 = uStack_38;
        goto LAB_00019e2c;
      case 8:
        puVar13 = (uint *)param_3[7];
        *puVar13 = uStack_38;
        puVar13[1] = uStack_34;
        goto LAB_00019cdc;
      }
      uVar12 = 0;
    }
    else {
      local_40 = 0;
      puStack_3c = (undefined4 *)0x0;
      if (bVar4 != 3) {
        iVar7 = pb_decode_varint(param_1,&local_40);
        if (iVar7 == 0) goto LAB_00019cdc;
        sVar10 = *(short *)((int)param_3 + 0x12);
        uStack_38 = local_40;
        uStack_34 = (uint)puStack_3c;
        if (sVar10 != 8) {
          uStack_34 = (int)local_40 >> 0x1f;
          goto LAB_00019dac;
        }
switchD_00019db2_caseD_8:
        puVar13 = (uint *)param_3[7];
        *puVar13 = uStack_38;
        puVar13[1] = uStack_34;
        goto LAB_00019cdc;
      }
      uStack_38 = 0;
      uStack_34 = 0;
      iVar7 = pb_decode_varint(param_1,&uStack_38);
      if (iVar7 == 0) goto LAB_00019cdc;
      uVar14 = uStack_38 & 1;
      uStack_38 = -uVar14 ^ ((uint)((uStack_34 & 1) != 0) << 0x1f | uStack_38 >> 1);
      uStack_34 = uStack_34 >> 1 ^ -(uint)(uVar14 != 0);
      sVar10 = *(short *)((int)param_3 + 0x12);
LAB_00019dac:
      switch(sVar10) {
      case 1:
        uVar14 = (uint)(char)uStack_38;
        *(char *)param_3[7] = (char)uStack_38;
        break;
      case 2:
        uVar14 = (uint)(short)uStack_38;
        *(short *)param_3[7] = (short)uStack_38;
        break;
      default:
switchD_00019b40_caseD_3:
        puVar6 = *(undefined **)(param_1 + 0xc);
        puVar8 = (undefined *)(DAT_00019e64 + 0x19dd6);
        goto LAB_00019cd2;
      case 4:
        *(uint *)param_3[7] = uStack_38;
        uVar12 = (int)uStack_38 >> 0x1f;
        uVar14 = uStack_38;
        goto LAB_00019e2c;
      case 8:
        goto switchD_00019db2_caseD_8;
      }
      uVar12 = (int)uVar14 >> 0x1f;
    }
LAB_00019e2c:
    if (uStack_38 == uVar14 && uStack_34 == uVar12) goto LAB_00019cdc;
    puVar6 = *(undefined **)(param_1 + 0xc);
    puVar8 = (undefined *)(DAT_00019e68 + 0x19e40);
    break;
  case 4:
    if (param_2 == 5 || param_2 == 0xff) {
      puVar13 = (uint *)param_3[7];
      uStack_38 = 0;
      iVar7 = pb_read(param_1,&uStack_38,4);
      if (iVar7 != 0) {
        *puVar13 = uStack_38;
      }
      goto LAB_00019cdc;
    }
    goto LAB_00019ccc;
  case 5:
    if (param_2 == 1 || param_2 == 0xff) {
      puVar13 = (uint *)param_3[7];
      uStack_38 = 0;
      uStack_34 = 0;
      iVar7 = pb_read(param_1,&uStack_38,8);
      if (iVar7 != 0) {
        *puVar13 = uStack_38;
        puVar13[1] = uStack_34;
      }
      goto LAB_00019cdc;
    }
LAB_00019ccc:
    puVar6 = *(undefined **)(param_1 + 0xc);
    puVar8 = (undefined *)(DAT_00019e60 + 0x19cd4);
    break;
  case 6:
    if (param_2 != 2) goto LAB_00019ccc;
    uStack_38 = 0;
    iVar7 = pb_decode_varint32_eof(param_1,&uStack_38,0);
    if (iVar7 == 0) goto LAB_00019cdc;
    if (uStack_38 < 0x10000) {
      if ((*(byte *)((int)param_3 + 0x16) & 0xc0) == 0x80) {
LAB_00019c98:
        puVar6 = *(undefined **)(param_1 + 0xc);
        puVar8 = (undefined *)(DAT_00019e70 + 0x19ca0);
        break;
      }
      if (uStack_38 + 2 <= (uint)*(ushort *)((int)param_3 + 0x12)) {
        puVar9 = (undefined2 *)param_3[7] + 1;
        *(undefined2 *)param_3[7] = (short)uStack_38;
LAB_00019e10:
        pb_read(param_1,puVar9);
        goto LAB_00019cdc;
      }
    }
LAB_00019cc4:
    puVar6 = *(undefined **)(param_1 + 0xc);
    puVar8 = (undefined *)(DAT_00019e6c + 0x19ccc);
    break;
  case 7:
    if (param_2 != 2) goto LAB_00019ccc;
    puVar9 = (undefined2 *)param_3[7];
    uStack_38 = 0;
    iVar7 = pb_decode_varint32_eof(param_1,&uStack_38,0);
    if (iVar7 == 0) goto LAB_00019cdc;
    if (uStack_38 == 0xffffffff) {
      puVar6 = *(undefined **)(param_1 + 0xc);
      puVar8 = (undefined *)(DAT_00019e74 + 0x19e04);
    }
    else {
      if ((*(byte *)((int)param_3 + 0x16) & 0xc0) == 0x80) goto LAB_00019c98;
      if (uStack_38 < *(ushort *)((int)param_3 + 0x12)) {
        *(undefined1 *)((int)puVar9 + uStack_38) = 0;
        goto LAB_00019e10;
      }
      puVar6 = *(undefined **)(param_1 + 0xc);
      puVar8 = &UNK_00019e5a + DAT_00019e78;
    }
    break;
  case 8:
  case 9:
    if (param_2 != 2) goto LAB_00019ccc;
    uStack_34 = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    local_30 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    local_2c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    uStack_1c = local_2c;
    iVar7 = pb_make_string_substream(param_1);
    if (iVar7 == 0) goto LAB_00019cdc;
    if (param_3[9] != 0) {
      if ((((*(byte *)((int)param_3 + 0x16) & 0xf) == 9) && (iVar7 = param_3[8], iVar7 != 0)) &&
         (*(code **)(iVar7 + -8) != (code *)0x0)) {
        iVar7 = (**(code **)(iVar7 + -8))(&uStack_38,param_3,iVar7 + -4);
        bVar3 = local_30 == 0;
      }
      else {
        bVar3 = false;
        iVar7 = 1;
      }
      if ((!bVar3) && (iVar7 != 0)) {
        pb_decode_inner(&uStack_38,param_3[9],param_3[7],
                        *(byte *)((int)param_3 + 0x16) < 0x40 &&
                        (*(byte *)((int)param_3 + 0x16) & 0x30) != 0x20);
      }
      if ((local_30 == 0) || (iVar7 = pb_read(&uStack_38,0), iVar7 != 0)) {
        *(uint *)(param_1 + 4) = uStack_34;
        *(undefined4 *)(param_1 + 0xc) = local_2c;
      }
      goto LAB_00019cdc;
    }
    puVar6 = *(undefined **)(param_1 + 0xc);
    puVar8 = (undefined *)(DAT_00019e7c + 0x19d9c);
    break;
  default:
    puVar6 = *(undefined **)(param_1 + 0xc);
    puVar8 = (undefined *)(DAT_00019e84 + 0x19ca8);
    break;
  case 0xb:
    if (param_2 != 2) goto LAB_00019ccc;
    uStack_38 = 0;
    iVar7 = pb_decode_varint32_eof(param_1,&uStack_38,0);
    if (iVar7 == 0) goto LAB_00019cdc;
    if (0xffff < uStack_38) goto LAB_00019cc4;
    if (uStack_38 == 0) {
      __aeabi_memclr8(param_3[7],*(undefined2 *)((int)param_3 + 0x12));
      goto LAB_00019cdc;
    }
    if (uStack_38 == *(ushort *)((int)param_3 + 0x12)) {
      puVar9 = (undefined2 *)param_3[7];
      goto LAB_00019e10;
    }
    puVar6 = *(undefined **)(param_1 + 0xc);
    puVar8 = (undefined *)(DAT_00019e80 + 0x19e52);
  }
LAB_00019cd2:
  if (puVar6 != (undefined *)0x0) {
    puVar8 = puVar6;
  }
  *(undefined **)(param_1 + 0xc) = puVar8;
LAB_00019cdc:
  if (**(int **)(DAT_00019e88 + 0x19ce4) == local_18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_18);
}



// ===========================================================
// Function: decode_basic_field at 00019ae4
// ===========================================================

void decode_basic_field(int param_1,int param_2,int param_3)

{
  bool bVar1;
  byte bVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  uint uVar7;
  undefined2 *puVar8;
  short sVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  uint *puVar13;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint uStack_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  int local_18;
  
  local_18 = **(int **)(DAT_00019e5c + 0x19af2);
  bVar2 = *(byte *)(param_3 + 0x16) & 0xf;
  switch(bVar2) {
  case 0:
    if ((param_2 == 0) || (param_2 == 0xff)) {
      uVar12 = *(undefined4 *)(param_3 + 0x1c);
      local_38 = 0;
      iVar4 = pb_decode_varint32_eof(param_1,&local_38,0);
      if (iVar4 != 0) {
        *(bool *)uVar12 = local_38 != 0;
      }
      goto LAB_00019cdc;
    }
    goto LAB_00019ccc;
  case 1:
  case 2:
  case 3:
    if ((param_2 != 0) && (param_2 != 0xff)) goto LAB_00019ccc;
    if (bVar2 == 2) {
      local_38 = 0;
      uStack_34 = 0;
      iVar4 = pb_decode_varint(param_1,&local_38);
      if (iVar4 == 0) goto LAB_00019cdc;
      uVar5 = local_38;
      uVar7 = uStack_34;
      switch(*(undefined2 *)(param_3 + 0x12)) {
      case 1:
        **(undefined1 **)(param_3 + 0x1c) = (char)local_38;
        uVar11 = local_38 & 0xff;
        break;
      case 2:
        **(undefined2 **)(param_3 + 0x1c) = (short)local_38;
        uVar11 = local_38 & 0xffff;
        break;
      default:
        goto switchD_00019b40_caseD_3;
      case 4:
        **(uint **)(param_3 + 0x1c) = local_38;
        uVar10 = 0;
        uVar11 = local_38;
        goto LAB_00019e2c;
      case 8:
        puVar13 = *(uint **)(param_3 + 0x1c);
        *puVar13 = local_38;
        puVar13[1] = uStack_34;
        goto LAB_00019cdc;
      }
      uVar10 = 0;
    }
    else {
      local_40 = 0;
      local_3c = 0;
      if (bVar2 != 3) {
        iVar4 = pb_decode_varint(param_1,&local_40);
        if (iVar4 == 0) goto LAB_00019cdc;
        sVar9 = *(short *)(param_3 + 0x12);
        uVar5 = local_40;
        uVar7 = local_3c;
        if (sVar9 != 8) {
          uVar7 = (int)local_40 >> 0x1f;
          goto LAB_00019dac;
        }
switchD_00019db2_caseD_8:
        puVar13 = *(uint **)(param_3 + 0x1c);
        *puVar13 = uVar5;
        puVar13[1] = uVar7;
        goto LAB_00019cdc;
      }
      local_38 = 0;
      uStack_34 = 0;
      iVar4 = pb_decode_varint(param_1,&local_38);
      if (iVar4 == 0) goto LAB_00019cdc;
      uVar7 = uStack_34 >> 1 ^ -(uint)((local_38 & 1) != 0);
      sVar9 = *(short *)(param_3 + 0x12);
      uVar5 = -(local_38 & 1) ^ ((uint)((uStack_34 & 1) != 0) << 0x1f | local_38 >> 1);
LAB_00019dac:
      switch(sVar9) {
      case 1:
        uVar11 = (uint)(char)uVar5;
        **(char **)(param_3 + 0x1c) = (char)uVar5;
        break;
      case 2:
        uVar11 = (uint)(short)uVar5;
        **(short **)(param_3 + 0x1c) = (short)uVar5;
        break;
      default:
switchD_00019b40_caseD_3:
        puVar3 = *(undefined **)(param_1 + 0xc);
        puVar6 = (undefined *)(DAT_00019e64 + 0x19dd6);
        goto LAB_00019cd2;
      case 4:
        **(uint **)(param_3 + 0x1c) = uVar5;
        uVar10 = (int)uVar5 >> 0x1f;
        uVar11 = uVar5;
        goto LAB_00019e2c;
      case 8:
        goto switchD_00019db2_caseD_8;
      }
      uVar10 = (int)uVar11 >> 0x1f;
    }
LAB_00019e2c:
    if (uVar5 == uVar11 && uVar7 == uVar10) goto LAB_00019cdc;
    puVar3 = *(undefined **)(param_1 + 0xc);
    puVar6 = (undefined *)(DAT_00019e68 + 0x19e40);
    break;
  case 4:
    if (param_2 == 5 || param_2 == 0xff) {
      puVar13 = *(uint **)(param_3 + 0x1c);
      local_38 = 0;
      iVar4 = pb_read(param_1,&local_38,4);
      if (iVar4 != 0) {
        *puVar13 = local_38;
      }
      goto LAB_00019cdc;
    }
    goto LAB_00019ccc;
  case 5:
    if (param_2 == 1 || param_2 == 0xff) {
      puVar13 = *(uint **)(param_3 + 0x1c);
      local_38 = 0;
      uStack_34 = 0;
      iVar4 = pb_read(param_1,&local_38,8);
      if (iVar4 != 0) {
        *puVar13 = local_38;
        puVar13[1] = uStack_34;
      }
      goto LAB_00019cdc;
    }
LAB_00019ccc:
    puVar3 = *(undefined **)(param_1 + 0xc);
    puVar6 = (undefined *)(DAT_00019e60 + 0x19cd4);
    break;
  case 6:
    if (param_2 != 2) goto LAB_00019ccc;
    local_38 = 0;
    iVar4 = pb_decode_varint32_eof(param_1,&local_38,0);
    if (iVar4 == 0) goto LAB_00019cdc;
    if (local_38 < 0x10000) {
      if ((*(byte *)(param_3 + 0x16) & 0xc0) == 0x80) {
LAB_00019c98:
        puVar3 = *(undefined **)(param_1 + 0xc);
        puVar6 = (undefined *)(DAT_00019e70 + 0x19ca0);
        break;
      }
      if (local_38 + 2 <= (uint)*(ushort *)(param_3 + 0x12)) {
        puVar8 = *(undefined2 **)(param_3 + 0x1c) + 1;
        **(undefined2 **)(param_3 + 0x1c) = (short)local_38;
LAB_00019e10:
        pb_read(param_1,puVar8);
        goto LAB_00019cdc;
      }
    }
LAB_00019cc4:
    puVar3 = *(undefined **)(param_1 + 0xc);
    puVar6 = (undefined *)(DAT_00019e6c + 0x19ccc);
    break;
  case 7:
    if (param_2 != 2) goto LAB_00019ccc;
    puVar8 = *(undefined2 **)(param_3 + 0x1c);
    local_38 = 0;
    iVar4 = pb_decode_varint32_eof(param_1,&local_38,0);
    if (iVar4 == 0) goto LAB_00019cdc;
    if (local_38 == 0xffffffff) {
      puVar3 = *(undefined **)(param_1 + 0xc);
      puVar6 = (undefined *)(DAT_00019e74 + 0x19e04);
    }
    else {
      if ((*(byte *)(param_3 + 0x16) & 0xc0) == 0x80) goto LAB_00019c98;
      if (local_38 < *(ushort *)(param_3 + 0x12)) {
        *(undefined1 *)((int)puVar8 + local_38) = 0;
        goto LAB_00019e10;
      }
      puVar3 = *(undefined **)(param_1 + 0xc);
      puVar6 = &UNK_00019e5a + DAT_00019e78;
    }
    break;
  case 8:
  case 9:
    if (param_2 != 2) goto LAB_00019ccc;
    uStack_34 = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    local_30 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    local_2c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    local_38 = 0;
    local_28 = 0;
    uStack_24 = uStack_34;
    iStack_20 = local_30;
    uStack_1c = local_2c;
    iVar4 = pb_make_string_substream(param_1);
    if (iVar4 == 0) goto LAB_00019cdc;
    if (*(int *)(param_3 + 0x24) != 0) {
      if ((((*(byte *)(param_3 + 0x16) & 0xf) == 9) &&
          (iVar4 = *(int *)(param_3 + 0x20), iVar4 != 0)) && (*(code **)(iVar4 + -8) != (code *)0x0)
         ) {
        iVar4 = (**(code **)(iVar4 + -8))(&local_38,param_3,iVar4 + -4);
        bVar1 = local_30 == 0;
      }
      else {
        bVar1 = false;
        iVar4 = 1;
      }
      if ((!bVar1) && (iVar4 != 0)) {
        pb_decode_inner(&local_38,*(undefined4 *)(param_3 + 0x24),*(undefined4 *)(param_3 + 0x1c),
                        *(byte *)(param_3 + 0x16) < 0x40 &&
                        (*(byte *)(param_3 + 0x16) & 0x30) != 0x20);
      }
      if ((local_30 == 0) || (iVar4 = pb_read(&local_38,0), iVar4 != 0)) {
        *(uint *)(param_1 + 4) = uStack_34;
        *(undefined4 *)(param_1 + 0xc) = local_2c;
      }
      goto LAB_00019cdc;
    }
    puVar3 = *(undefined **)(param_1 + 0xc);
    puVar6 = (undefined *)(DAT_00019e7c + 0x19d9c);
    break;
  default:
    puVar3 = *(undefined **)(param_1 + 0xc);
    puVar6 = (undefined *)(DAT_00019e84 + 0x19ca8);
    break;
  case 0xb:
    if (param_2 != 2) goto LAB_00019ccc;
    local_38 = 0;
    iVar4 = pb_decode_varint32_eof(param_1,&local_38,0);
    if (iVar4 == 0) goto LAB_00019cdc;
    if (0xffff < local_38) goto LAB_00019cc4;
    if (local_38 == 0) {
      __aeabi_memclr8(*(undefined4 *)(param_3 + 0x1c),*(undefined2 *)(param_3 + 0x12));
      goto LAB_00019cdc;
    }
    if (local_38 == *(ushort *)(param_3 + 0x12)) {
      puVar8 = *(undefined2 **)(param_3 + 0x1c);
      goto LAB_00019e10;
    }
    puVar3 = *(undefined **)(param_1 + 0xc);
    puVar6 = (undefined *)(DAT_00019e80 + 0x19e52);
  }
LAB_00019cd2:
  if (puVar3 != (undefined *)0x0) {
    puVar6 = puVar3;
  }
  *(undefined **)(param_1 + 0xc) = puVar6;
LAB_00019cdc:
  if (**(int **)(DAT_00019e88 + 0x19ce4) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_18);
  }
  return;
}



// ===========================================================
// Function: pb_ostream_from_buffer at 00019e8c
// ===========================================================

void pb_ostream_from_buffer(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = DAT_00019ea0;
  param_1[2] = param_3;
  param_1[3] = 0;
  param_1[4] = 0;
  *param_1 = iVar1 + 0x19e9c;
  param_1[1] = param_2;
  return;
}



// ===========================================================
// Function: buf_write at 00019ea4
// ===========================================================

undefined4 buf_write(int param_1,void *param_2,size_t param_3)

{
  void *__dest;
  
  __dest = *(void **)(param_1 + 4);
  *(size_t *)(param_1 + 4) = (int)__dest + param_3;
  __aeabi_memcpy8(__dest,param_2,param_3);
  return 1;
}



// ===========================================================
// Function: pb_write at 00019ebc
// ===========================================================

undefined4 pb_write(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  if ((param_3 != 0) && ((code *)*param_1 != (code *)0x0)) {
    if ((CARRY4(param_1[3],param_3)) || ((uint)param_1[2] < param_1[3] + param_3)) {
      iVar1 = param_1[4];
      iVar2 = DAT_00019f00 + 0x19edc;
    }
    else {
      iVar2 = (*(code *)*param_1)(param_1,param_2,param_3);
      if (iVar2 != 0) goto LAB_00019eee;
      iVar1 = param_1[4];
      iVar2 = (int)&DAT_00019f00 + DAT_00019f04;
    }
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
    param_1[4] = iVar2;
    return 0;
  }
LAB_00019eee:
  param_1[3] = param_1[3] + param_3;
  return 1;
}



// ===========================================================
// Function: pb_encode at 00019f08
// ===========================================================

void pb_encode(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 *puStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 *puStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 *puStack_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_2c;
  
  uVar2 = 0;
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  puVar6 = *(undefined4 **)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_2c = **(int **)(DAT_00019fc8 + 0x19f20);
  local_5c = 0;
  local_80 = 0;
  local_70 = 0;
  local_60 = 0;
  uStack_7c = uVar4;
  uStack_78 = uVar5;
  puStack_74 = puVar6;
  uStack_6c = uVar4;
  uStack_68 = uVar5;
  local_64 = puVar6;
  iVar1 = pb_field_iter_begin_const();
  if (iVar1 != 0) {
    do {
      if ((uStack_6c._2_1_ & 0xf) == 10) {
        for (piVar3 = (int *)*local_64; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
          if (*(code **)(*piVar3 + 4) == (code *)0x0) {
            local_34 = 0;
            local_38 = 0;
            local_58 = uVar2;
            uStack_54 = uVar4;
            uStack_50 = uVar5;
            puStack_4c = puVar6;
            local_48 = uVar2;
            uStack_44 = uVar4;
            uStack_40 = uVar5;
            puStack_3c = puVar6;
            iVar1 = pb_field_iter_begin_extension_const(&local_58,piVar3);
            if (iVar1 == 0) {
              iVar1 = DAT_00019fcc + 0x19fa4;
              if (*(int *)(param_1 + 0x10) != 0) {
                iVar1 = *(int *)(param_1 + 0x10);
              }
              *(int *)(param_1 + 0x10) = iVar1;
              goto LAB_00019faa;
            }
            iVar1 = encode_field(param_1,&local_58);
          }
          else {
            iVar1 = (**(code **)(*piVar3 + 4))(param_1,piVar3);
          }
          if (iVar1 == 0) goto LAB_00019faa;
        }
      }
      else {
        iVar1 = encode_field(param_1,&local_80);
        if (iVar1 == 0) {
LAB_00019faa:
          uVar2 = 0;
          goto LAB_00019fac;
        }
      }
      iVar1 = pb_field_iter_next(&local_80);
    } while (iVar1 != 0);
  }
  uVar2 = 1;
LAB_00019fac:
  if (**(int **)(DAT_00019fd0 + 0x19fb4) != local_2c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: encode_field at 00019fd4
// ===========================================================

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint * encode_field(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  ushort *puVar5;
  byte bVar6;
  uint uVar7;
  uint *puVar8;
  ushort *puVar9;
  undefined4 *puVar10;
  uint *puVar11;
  int *piVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  undefined8 uVar16;
  uint local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int local_2c;
  int local_28;
  int local_24;
  
  local_24 = **(int **)(DAT_0001a1f8 + 0x19fe4);
  bVar6 = *(byte *)((int)param_2 + 0x16) & 0x30;
  if (bVar6 != 0x10) {
    if ((bVar6 != 0x30) || (*(short *)param_2[8] == (short)param_2[4])) goto LAB_0001a018;
LAB_0001a046:
    puVar11 = (uint *)0x1;
LAB_0001a0ca:
    if (**(int **)(DAT_0001a210 + 0x1a0d2) == local_24) {
      return puVar11;
    }
LAB_0001a0e0:
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_24);
  }
  if ((char *)param_2[8] == (char *)0x0) {
    if ((0x3f < *(byte *)((int)param_2 + 0x16)) ||
       (iVar2 = pb_check_proto3_default_value(param_2), iVar2 == 0)) goto LAB_0001a018;
    goto LAB_0001a046;
  }
  if (*(char *)param_2[8] == '\0') goto LAB_0001a046;
LAB_0001a018:
  piVar12 = (int *)param_2[7];
  uVar1 = (uint)*(byte *)((int)param_2 + 0x16);
  if (piVar12 == (int *)0x0) {
    if ((*(byte *)((int)param_2 + 0x16) & 0x30) != 0) goto LAB_0001a046;
    iVar3 = param_1[4];
    iVar2 = DAT_0001a1fc + 0x1a0c0;
LAB_0001a0be:
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
    param_1[4] = iVar2;
LAB_0001a0c8:
    puVar11 = (uint *)0x0;
    goto LAB_0001a0ca;
  }
  uVar7 = uVar1 & 0xc0;
  if (uVar7 == 0x40) {
    if ((*(code **)(*param_2 + 0xc) == (code *)0x0) ||
       (iVar2 = (**(code **)(*param_2 + 0xc))(0,param_1,param_2), iVar2 != 0)) goto LAB_0001a046;
    iVar3 = param_1[4];
    iVar2 = DAT_0001a200 + 0x1a040;
    goto LAB_0001a0be;
  }
  if ((uVar1 & 0x30) == 0x20) {
    uVar13 = (uint)*(ushort *)param_2[8];
    if (uVar13 == 0) goto LAB_0001a046;
    bVar15 = 0x7f < uVar7;
    bVar14 = uVar7 != 0x80;
    if (bVar14) {
      uVar7 = (uint)*(ushort *)(param_2 + 5);
      bVar15 = uVar7 <= uVar13;
    }
    if (bVar15 && (bVar14 && uVar13 != uVar7)) {
      iVar3 = param_1[4];
      iVar2 = DAT_0001a204 + 0x1a152;
      goto LAB_0001a0be;
    }
    if ((uVar1 & 0xe) < 6) {
      puVar11 = (uint *)0x0;
      uVar16 = pb_encode_varint(param_1,uVar7,(uint)*(ushort *)(param_2 + 4) * 8 + 2,0);
      iVar2 = (int)((ulonglong)uVar16 >> 0x20);
      if ((int)uVar16 != 0) {
        bVar6 = *(byte *)((int)param_2 + 0x16) & 0xf;
        if (bVar6 == 5) {
          iVar3 = uVar13 << 3;
        }
        else if (bVar6 == 4) {
          iVar3 = uVar13 << 2;
        }
        else {
          iVar3 = param_2[7];
          uStack_34 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
          uStack_30 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
          local_2c = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
          uVar1 = 0;
          local_38 = 0;
          local_28 = 0;
          do {
            iVar2 = pb_enc_varint(&local_38,param_2);
            if (iVar2 == 0) {
              iVar2 = DAT_0001a208 + 0x1a1e0;
              if (local_28 != 0) {
                iVar2 = local_28;
              }
              iVar3 = param_1[4];
              goto LAB_0001a0be;
            }
            iVar2 = param_2[7];
            uVar1 = uVar1 + 1;
            param_2[7] = (uint)*(ushort *)((int)param_2 + 0x12) + iVar2;
          } while (uVar1 < uVar13);
          param_2[7] = iVar3;
          iVar3 = local_2c;
        }
        puVar11 = (uint *)0x0;
        iVar2 = pb_encode_varint(param_1,iVar2,iVar3,0);
        if (iVar2 != 0) {
          if (*param_1 == 0) {
            puVar11 = (uint *)pb_write(param_1,0,iVar3);
          }
          else {
            uVar1 = 0;
            puVar11 = (uint *)0x1;
            do {
              if ((*(byte *)((int)param_2 + 0x16) & 0xe) == 4) {
                iVar2 = pb_enc_fixed(param_1,param_2);
              }
              else {
                iVar2 = pb_enc_varint(param_1,param_2);
              }
              if (iVar2 == 0) goto LAB_0001a0c8;
              uVar1 = uVar1 + 1;
              param_2[7] = (uint)*(ushort *)((int)param_2 + 0x12) + param_2[7];
            } while (uVar1 < uVar13);
          }
        }
      }
    }
    else {
      uVar1 = 0;
      do {
        if ((*(byte *)((int)param_2 + 0x16) & 0xce) == 0x86) {
          iVar2 = *piVar12;
          param_2[7] = iVar2;
          if (iVar2 == 0) {
            iVar2 = pb_encode_tag_for_field(param_1,param_2);
            if (iVar2 == 0) {
              param_2[7] = (int)piVar12;
              goto LAB_0001a0c8;
            }
            puVar11 = (uint *)0x0;
            local_38 = local_38 & 0xffffff00;
            iVar2 = pb_write(param_1,&local_38,1);
            param_2[7] = (int)piVar12;
            if (iVar2 == 0) break;
          }
          else {
            iVar2 = encode_basic_field(param_1,param_2);
            param_2[7] = (int)piVar12;
            if (iVar2 == 0) goto LAB_0001a0c8;
          }
        }
        else {
          iVar2 = encode_basic_field(param_1,param_2);
          if (iVar2 == 0) goto LAB_0001a0c8;
          piVar12 = (int *)param_2[7];
        }
        uVar1 = uVar1 + 1;
        puVar11 = (uint *)0x1;
        piVar12 = (int *)((int)piVar12 + (uint)*(ushort *)((int)param_2 + 0x12));
        param_2[7] = (int)piVar12;
      } while (uVar1 < uVar13);
    }
    goto LAB_0001a0ca;
  }
  if (**(int **)(DAT_0001a20c + 0x1a09e) != local_24) goto LAB_0001a0e0;
  puVar11 = (uint *)**(undefined4 **)(DAT_0001a7fc + 0x1a63c);
  if (param_2[7] == 0) {
    puVar4 = (uint *)0x1;
  }
  else {
    iVar2 = pb_encode_tag_for_field(param_1);
    if (iVar2 != 0) {
      bVar6 = *(byte *)((int)param_2 + 0x16);
      puVar4 = puVar11;
      switch(bVar6 & 0xf) {
      case 0:
        uVar1 = (uint)(*(char *)param_2[7] != '\0');
        puVar8 = (uint *)**(undefined4 **)(DAT_0001a800 + 0x1a704);
        if (puVar8 != puVar11) goto LAB_0001a7f6;
        uVar7 = 0;
        goto code_r0x0001c7f4;
      case 1:
      case 2:
      case 3:
        if ((uint *)**(undefined4 **)(DAT_0001a804 + 0x1a676) != puVar11) goto LAB_0001a7f6;
        bVar6 = *(byte *)((int)param_2 + 0x16) & 0xf;
        if (bVar6 == 2) {
          switch(*(undefined2 *)((int)param_2 + 0x12)) {
          case 1:
            puVar11 = (uint *)param_2[7];
            uVar1 = (uint)(byte)*puVar11;
            break;
          case 2:
            puVar11 = (uint *)param_2[7];
            uVar1 = (uint)(ushort)*puVar11;
            break;
          default:
            goto switchD_0001a844_caseD_3;
          case 4:
            puVar11 = (uint *)param_2[7];
            uVar1 = *puVar11;
            break;
          case 8:
            puVar10 = (undefined4 *)param_2[7];
            puVar11 = (uint *)__ThumbV7PILongThunk_pb_encode_varint
                                        (param_1,puVar10,*puVar10,puVar10[1]);
            return puVar11;
          }
          puVar11 = (uint *)__ThumbV7PILongThunk_pb_encode_varint(param_1,puVar11,uVar1,0);
          return puVar11;
        }
        switch(*(undefined2 *)((int)param_2 + 0x12)) {
        case 1:
          puVar8 = (uint *)param_2[7];
          uVar1 = (uint)(char)*puVar8;
          break;
        case 2:
          puVar8 = (uint *)param_2[7];
          uVar1 = (uint)(short)(ushort)*puVar8;
          break;
        default:
switchD_0001a844_caseD_3:
          iVar2 = DAT_0001a8d0 + 0x1a876;
          if (param_1[4] != 0) {
            iVar2 = param_1[4];
          }
          param_1[4] = iVar2;
          return (uint *)0x0;
        case 4:
          puVar8 = (uint *)param_2[7];
          uVar1 = *puVar8;
          break;
        case 8:
          puVar8 = (uint *)param_2[7];
          uVar1 = *puVar8;
          uVar7 = puVar8[1];
          goto LAB_0001a8b0;
        }
        uVar7 = (int)uVar1 >> 0x1f;
LAB_0001a8b0:
        if (bVar6 == 3) {
          uVar13 = uVar7 << 1 | uVar1 >> 0x1f;
          puVar11 = (uint *)__ThumbV7PILongThunk_pb_encode_varint
                                      (param_1,uVar13,uVar1 << 1 ^ (int)uVar7 >> 0x1f,
                                       uVar13 ^ (int)uVar7 >> 0x1f);
          return puVar11;
        }
code_r0x0001c7f4:
        puVar11 = (uint *)pb_encode_varint(param_1,puVar8,uVar1,uVar7);
        return puVar11;
      case 4:
      case 5:
        if ((uint *)**(undefined4 **)(DAT_0001a808 + 0x1a69a) == puVar11) {
          if (*(short *)((int)param_2 + 0x12) == 8) {
            puVar11 = (uint *)__ThumbV7PILongThunk_pb_write(param_1,param_2[7],8);
            return puVar11;
          }
          if (*(short *)((int)param_2 + 0x12) != 4) {
            iVar2 = DAT_0001a900 + 0x1a8f6;
            if (param_1[4] != 0) {
              iVar2 = param_1[4];
            }
            param_1[4] = iVar2;
            return (uint *)0x0;
          }
          puVar11 = (uint *)__ThumbV7PILongThunk_pb_write(param_1,param_2[7],4);
          return puVar11;
        }
        goto LAB_0001a7f6;
      case 6:
        puVar4 = (uint *)param_2[7];
        if (puVar4 == (uint *)0x0) {
          puVar4 = (uint *)pb_write(param_1,&stack0xffffffeb,1);
          goto LAB_0001a768;
        }
        uVar1 = (uint)(ushort)*puVar4;
        if ((0x3f < bVar6) || (uVar1 <= *(ushort *)((int)param_2 + 0x12) - 2)) {
          if ((uint *)**(undefined4 **)(DAT_0001a810 + 0x1a79e) != puVar11) goto LAB_0001a7f6;
          puVar9 = (ushort *)((int)puVar4 + 2);
          goto LAB_0001a7ea;
        }
        iVar3 = param_1[4];
        iVar2 = DAT_0001a80c + 0x1a738;
        break;
      case 7:
        puVar9 = (ushort *)param_2[7];
        if ((bVar6 & 0xc0) == 0x80) {
          if (puVar9 != (ushort *)0x0) {
            uVar7 = 0xffffffff;
LAB_0001a786:
            puVar5 = (ushort *)((int)puVar9 + uVar7);
            uVar1 = 0;
            do {
              if (*(char *)((int)puVar9 + uVar1) == '\0') goto LAB_0001a7dc;
              uVar1 = uVar1 + 1;
            } while (uVar7 != uVar1);
            goto LAB_0001a7d0;
          }
LAB_0001a7bc:
          uVar1 = 0;
          goto LAB_0001a7dc;
        }
        if (*(ushort *)((int)param_2 + 0x12) == 0) {
          iVar3 = param_1[4];
          iVar2 = DAT_0001a814 + 0x1a7cc;
        }
        else {
          if (puVar9 == (ushort *)0x0) goto LAB_0001a7bc;
          uVar7 = *(ushort *)((int)param_2 + 0x12) - 1;
          if (uVar7 != 0) goto LAB_0001a786;
          uVar7 = 0;
          puVar5 = puVar9;
LAB_0001a7d0:
          uVar1 = uVar7;
          if ((char)*puVar5 == '\0') goto LAB_0001a7dc;
          iVar3 = param_1[4];
          iVar2 = DAT_0001a81c + 0x1a7dc;
        }
        break;
      case 8:
      case 9:
        iVar2 = param_2[9];
        if (iVar2 != 0) {
          if ((((bVar6 & 0xf) == 9) && (iVar3 = param_2[8], iVar3 != 0)) &&
             (*(code **)(iVar3 + -8) != (code *)0x0)) {
            iVar2 = (**(code **)(iVar3 + -8))(param_1,param_2,iVar3 + -4);
            if (iVar2 == 0) goto LAB_0001a766;
            iVar2 = param_2[9];
          }
          if ((uint *)**(undefined4 **)(DAT_0001a824 + 0x1a6de) == puVar11) {
            puVar11 = (uint *)pb_encode_submessage(param_1,iVar2,param_2[7]);
            return puVar11;
          }
          goto LAB_0001a7f6;
        }
        iVar3 = param_1[4];
        iVar2 = DAT_0001a820 + 0x1a760;
        break;
      default:
        iVar3 = param_1[4];
        iVar2 = DAT_0001a828 + 0x1a752;
        break;
      case 0xb:
        puVar9 = (ushort *)param_2[7];
        uVar1 = (uint)*(ushort *)((int)param_2 + 0x12);
LAB_0001a7dc:
        if ((uint *)**(undefined4 **)(DAT_0001a818 + 0x1a7e4) == puVar11) {
LAB_0001a7ea:
          puVar11 = (uint *)__ThumbV7PILongThunk_pb_encode_string(param_1,puVar9,uVar1);
          return puVar11;
        }
        goto LAB_0001a7f6;
      }
      if (iVar3 != 0) {
        iVar2 = iVar3;
      }
      param_1[4] = iVar2;
    }
LAB_0001a766:
    puVar4 = (uint *)0x0;
  }
LAB_0001a768:
  if ((uint *)**(undefined4 **)(DAT_0001a82c + 0x1a770) == puVar11) {
    return puVar4;
  }
LAB_0001a7f6:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(puVar4);
}



// ===========================================================
// Function: pb_encode_ex at 0001a214
// ===========================================================

void pb_encode_ex(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined1 local_15;
  int local_14;
  
  local_14 = **(int **)(DAT_0001a298 + 0x1a220);
  if (param_4 << 0x1e < 0) {
    if (**(int **)(DAT_0001a29c + 0x1a252) == local_14) {
      pb_encode_submessage(param_1);
      return;
    }
  }
  else if (param_4 << 0x1d < 0) {
    local_15 = 0;
    iVar1 = pb_encode(param_1);
    if (iVar1 != 0) {
      pb_write(param_1,&local_15,1);
    }
    if (**(int **)(DAT_0001a2a0 + 0x1a28a) == local_14) {
      return;
    }
  }
  else if (**(int **)(DAT_0001a2a4 + 0x1a234) == local_14) {
    pb_encode();
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_14);
}



// ===========================================================
// Function: pb_encode_submessage at 0001a2a8
// ===========================================================

void pb_encode_submessage(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  int local_30;
  int iStack_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  iStack_2c = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  local_28 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  local_24 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_1c = **(int **)(DAT_0001a36c + 0x1a2c0);
  local_30 = 0;
  local_20 = 0;
  uVar3 = pb_encode(&local_30,param_2,param_3);
  iVar2 = local_24;
  if ((int)uVar3 == 0) {
    param_1[4] = local_20;
  }
  else {
    iVar1 = pb_encode_varint(param_1,(int)((ulonglong)uVar3 >> 0x20),local_24,0);
    if (iVar1 != 0) {
      if (*param_1 == 0) {
        pb_write(param_1,0,iVar2);
      }
      else {
        if ((uint)param_1[2] < (uint)(param_1[3] + iVar2)) {
          iVar1 = DAT_0001a370 + 0x1a300;
          iVar2 = param_1[4];
        }
        else {
          local_20 = 0;
          local_28 = iVar2;
          local_24 = 0;
          iStack_2c = param_1[1];
          local_30 = *param_1;
          pb_encode(&local_30,param_2,param_3);
          param_1[1] = iStack_2c;
          param_1[4] = local_20;
          param_1[3] = param_1[3] + local_24;
          if (local_24 == iVar2) goto LAB_0001a306;
          iVar1 = DAT_0001a374 + 0x1a362;
          iVar2 = local_20;
        }
        if (iVar2 != 0) {
          iVar1 = iVar2;
        }
        param_1[4] = iVar1;
      }
    }
  }
LAB_0001a306:
  if (**(int **)(DAT_0001a378 + 0x1a30e) == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_1c);
}



// ===========================================================
// Function: pb_get_encoded_size at 0001a37c
// ===========================================================

void pb_get_encoded_size(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  iVar2 = **(int **)(DAT_0001a3bc + 0x1a38e);
  iVar3 = pb_encode();
  if (iVar3 != 0) {
    *param_1 = uVar1;
  }
  if (**(int **)(DAT_0001a3c0 + 0x1a3ae) != iVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// ===========================================================
// Function: pb_encode_varint at 0001a3c4
// ===========================================================

void pb_encode_varint(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  byte local_19;
  byte local_18 [12];
  int local_c;
  
  iVar5 = 0;
  local_c = **(int **)(DAT_0001a46c + 0x1a3d2);
  if (-param_4 < (uint)(param_3 < 0x80)) {
    local_19 = (byte)param_3;
    pbVar2 = &local_19;
    iVar3 = 1;
    goto LAB_0001a450;
  }
  pbVar2 = local_18;
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  local_18[8] = 0;
  local_18[9] = 0;
  do {
    bVar6 = (byte)param_3;
    if ((param_4 == 0) && (param_3 < 0x80)) {
      bVar6 = bVar6 & 0x7f;
      goto LAB_0001a448;
    }
    param_3 = param_3 >> 7;
    pbVar2[iVar5] = bVar6 | 0x80;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 4);
  bVar6 = (byte)(param_3 & 0x7f);
  if (param_4 == 0) {
LAB_0001a444:
    iVar5 = 4;
  }
  else {
    uVar4 = param_4 >> 3;
    uVar7 = param_3 & 0x7f | (param_4 & 7) << 4;
    bVar6 = (byte)uVar7;
    if (uVar4 == 0) goto LAB_0001a444;
    iVar5 = 4;
    do {
      bVar1 = (byte)uVar7;
      uVar7 = uVar4 & 0x7f;
      bVar6 = (byte)uVar7;
      pbVar2[iVar5] = bVar1 | 0x80;
      uVar4 = uVar4 >> 7;
      iVar5 = iVar5 + 1;
    } while (uVar4 != 0);
  }
LAB_0001a448:
  iVar3 = iVar5 + 1;
  pbVar2[iVar5] = bVar6;
LAB_0001a450:
  pb_write(param_1,pbVar2,iVar3);
  if (**(int **)(DAT_0001a470 + 0x1a45c) == local_c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// ===========================================================
// Function: pb_encode_svarint at 0001a474
// ===========================================================

void pb_encode_svarint(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = param_4 << 1 | param_3 >> 0x1f;
  __ThumbV7PILongThunk_pb_encode_varint
            (param_1,uVar1,param_3 << 1 ^ param_4 >> 0x1f,uVar1 ^ param_4 >> 0x1f);
  return;
}



// ===========================================================
// Function: pb_encode_fixed32 at 0001a48a
// ===========================================================

void pb_encode_fixed32(undefined4 param_1,undefined4 param_2)

{
  __ThumbV7PILongThunk_pb_write(param_1,param_2,4);
  return;
}



// ===========================================================
// Function: pb_encode_fixed64 at 0001a490
// ===========================================================

void pb_encode_fixed64(undefined4 param_1,undefined4 param_2)

{
  __ThumbV7PILongThunk_pb_write(param_1,param_2,8);
  return;
}



// ===========================================================
// Function: pb_encode_tag at 0001a496
// ===========================================================

void pb_encode_tag(undefined4 param_1,uint param_2,uint param_3)

{
  param_2 = param_2 | param_3 << 3;
  __ThumbV7PILongThunk_pb_encode_varint(param_1,param_2,param_2,param_3 >> 0x1d);
  return;
}



// ===========================================================
// Function: pb_encode_tag_for_field at 0001a4a4
// ===========================================================

undefined4 pb_encode_tag_for_field(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(byte *)(param_2 + 0x16) & 0xf;
  if ((uVar2 < 0xc) && ((0xbffU >> uVar2 & 1) != 0)) {
    uVar1 = __ThumbV7PILongThunk_pb_encode_varint
                      (param_1,(uint)*(ushort *)(param_2 + 0x10),
                       *(uint *)(DAT_0001a4e4 + 0x1a4d2 + uVar2 * 4) |
                       (uint)*(ushort *)(param_2 + 0x10) << 3,0);
    return uVar1;
  }
  iVar3 = DAT_0001a4e0 + 0x1a4c0;
  if (*(int *)(param_1 + 0x10) != 0) {
    iVar3 = *(int *)(param_1 + 0x10);
  }
  *(int *)(param_1 + 0x10) = iVar3;
  return 0;
}



// ===========================================================
// Function: pb_encode_string at 0001a4e8
// ===========================================================

undefined4 pb_encode_string(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = pb_encode_varint();
  if (iVar1 != 0) {
    uVar2 = __ThumbV7PILongThunk_pb_write(param_1,param_2,param_3);
    return uVar2;
  }
  return 0;
}



// ===========================================================
// Function: pb_check_proto3_default_value at 0001a50c
// ===========================================================

void pb_check_proto3_default_value(int *param_1)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_14;
  
  local_14 = **(int **)(DAT_0001a624 + 0x1a516);
  bVar1 = *(byte *)((int)param_1 + 0x16);
  if ((((bVar1 & 0xc0) != 0x80) && ((bVar1 & 0xc0) != 0x40)) && ((bVar1 & 0xc0) == 0)) {
    switch(bVar1 & 0x3f) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
      break;
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x1f:
      if ((param_1[8] == 0) && (*(int *)(*param_1 + 8) == 0)) {
        if ((bVar1 & 0xf) < 6) {
          uVar4 = (uint)*(ushort *)((int)param_1 + 0x12);
          if (uVar4 != 0) {
            pcVar2 = (char *)param_1[7];
            do {
              uVar4 = uVar4 - 1;
              if (*pcVar2 != '\0') break;
              pcVar2 = pcVar2 + 1;
            } while (uVar4 != 0);
          }
        }
        else {
          switch(bVar1 & 0xf) {
          case 6:
            break;
          case 7:
            break;
          case 8:
          case 9:
            uStack_3c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
            uStack_38 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
            uStack_34 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
            local_1c = 0;
            local_40 = 0;
            local_30 = 0;
            local_20 = 0;
            uStack_2c = uStack_3c;
            uStack_28 = uStack_38;
            uStack_24 = uStack_34;
            iVar3 = pb_field_iter_begin(&local_40,param_1[9],param_1[7]);
            while ((iVar3 != 0 && (iVar3 = pb_check_proto3_default_value(&local_40), iVar3 != 0))) {
              iVar3 = pb_field_iter_next(&local_40);
            }
            break;
          case 10:
            break;
          case 0xb:
          }
        }
      }
      break;
    default:
    }
  }
  if (**(int **)(DAT_0001a62c + 0x1a574) != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}



// ===========================================================
// Function: encode_basic_field at 0001a630
// ===========================================================

uint * encode_basic_field(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  ushort *puVar4;
  uint *puVar5;
  ushort *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte bVar11;
  undefined1 local_15;
  uint *local_14;
  
  local_14 = (uint *)**(undefined4 **)(DAT_0001a7fc + 0x1a63c);
  if (*(int *)(param_2 + 0x1c) == 0) {
    puVar3 = (uint *)0x1;
  }
  else {
    iVar1 = pb_encode_tag_for_field(param_1);
    if (iVar1 != 0) {
      bVar11 = *(byte *)(param_2 + 0x16);
      puVar3 = local_14;
      switch(bVar11 & 0xf) {
      case 0:
        uVar10 = (uint)(**(char **)(param_2 + 0x1c) != '\0');
        puVar5 = (uint *)**(undefined4 **)(DAT_0001a800 + 0x1a704);
        if (puVar5 != local_14) goto LAB_0001a7f6;
        uVar9 = 0;
        goto code_r0x0001c7f4;
      case 1:
      case 2:
      case 3:
        if ((uint *)**(undefined4 **)(DAT_0001a804 + 0x1a676) != local_14) goto LAB_0001a7f6;
        bVar11 = *(byte *)(param_2 + 0x16) & 0xf;
        if (bVar11 == 2) {
          switch(*(undefined2 *)(param_2 + 0x12)) {
          case 1:
            puVar3 = *(uint **)(param_2 + 0x1c);
            uVar10 = (uint)(byte)*puVar3;
            break;
          case 2:
            puVar3 = *(uint **)(param_2 + 0x1c);
            uVar10 = (uint)(ushort)*puVar3;
            break;
          default:
            goto switchD_0001a844_caseD_3;
          case 4:
            puVar3 = *(uint **)(param_2 + 0x1c);
            uVar10 = *puVar3;
            break;
          case 8:
            puVar7 = *(undefined4 **)(param_2 + 0x1c);
            puVar3 = (uint *)__ThumbV7PILongThunk_pb_encode_varint(param_1,puVar7,*puVar7,puVar7[1])
            ;
            return puVar3;
          }
          puVar3 = (uint *)__ThumbV7PILongThunk_pb_encode_varint(param_1,puVar3,uVar10,0);
          return puVar3;
        }
        switch(*(undefined2 *)(param_2 + 0x12)) {
        case 1:
          puVar5 = *(uint **)(param_2 + 0x1c);
          uVar10 = (uint)(char)*puVar5;
          break;
        case 2:
          puVar5 = *(uint **)(param_2 + 0x1c);
          uVar10 = (uint)(short)(ushort)*puVar5;
          break;
        default:
switchD_0001a844_caseD_3:
          iVar1 = DAT_0001a8d0 + 0x1a876;
          if (*(int *)(param_1 + 0x10) != 0) {
            iVar1 = *(int *)(param_1 + 0x10);
          }
          *(int *)(param_1 + 0x10) = iVar1;
          return (uint *)0x0;
        case 4:
          puVar5 = *(uint **)(param_2 + 0x1c);
          uVar10 = *puVar5;
          break;
        case 8:
          puVar5 = *(uint **)(param_2 + 0x1c);
          uVar10 = *puVar5;
          uVar9 = puVar5[1];
          goto LAB_0001a8b0;
        }
        uVar9 = (int)uVar10 >> 0x1f;
LAB_0001a8b0:
        if (bVar11 == 3) {
          uVar8 = uVar9 << 1 | uVar10 >> 0x1f;
          puVar3 = (uint *)__ThumbV7PILongThunk_pb_encode_varint
                                     (param_1,uVar8,uVar10 << 1 ^ (int)uVar9 >> 0x1f,
                                      uVar8 ^ (int)uVar9 >> 0x1f);
          return puVar3;
        }
code_r0x0001c7f4:
        puVar3 = (uint *)pb_encode_varint(param_1,puVar5,uVar10,uVar9);
        return puVar3;
      case 4:
      case 5:
        if ((uint *)**(undefined4 **)(DAT_0001a808 + 0x1a69a) == local_14) {
          if (*(short *)(param_2 + 0x12) == 8) {
            puVar3 = (uint *)__ThumbV7PILongThunk_pb_write
                                       (param_1,*(undefined4 *)(param_2 + 0x1c),8);
            return puVar3;
          }
          if (*(short *)(param_2 + 0x12) != 4) {
            iVar1 = DAT_0001a900 + 0x1a8f6;
            if (*(int *)(param_1 + 0x10) != 0) {
              iVar1 = *(int *)(param_1 + 0x10);
            }
            *(int *)(param_1 + 0x10) = iVar1;
            return (uint *)0x0;
          }
          puVar3 = (uint *)__ThumbV7PILongThunk_pb_write(param_1,*(undefined4 *)(param_2 + 0x1c),4);
          return puVar3;
        }
        goto LAB_0001a7f6;
      case 6:
        puVar3 = *(uint **)(param_2 + 0x1c);
        if (puVar3 == (uint *)0x0) {
          local_15 = 0;
          puVar3 = (uint *)pb_write(param_1,&local_15,1);
          goto LAB_0001a768;
        }
        uVar10 = (uint)(ushort)*puVar3;
        if ((0x3f < bVar11) || (uVar10 <= *(ushort *)(param_2 + 0x12) - 2)) {
          if ((uint *)**(undefined4 **)(DAT_0001a810 + 0x1a79e) != local_14) goto LAB_0001a7f6;
          puVar6 = (ushort *)((int)puVar3 + 2);
          goto LAB_0001a7ea;
        }
        iVar2 = *(int *)(param_1 + 0x10);
        iVar1 = DAT_0001a80c + 0x1a738;
        break;
      case 7:
        puVar6 = *(ushort **)(param_2 + 0x1c);
        if ((bVar11 & 0xc0) == 0x80) {
          if (puVar6 != (ushort *)0x0) {
            uVar9 = 0xffffffff;
LAB_0001a786:
            puVar4 = (ushort *)((int)puVar6 + uVar9);
            uVar10 = 0;
            do {
              if (*(char *)((int)puVar6 + uVar10) == '\0') goto LAB_0001a7dc;
              uVar10 = uVar10 + 1;
            } while (uVar9 != uVar10);
            goto LAB_0001a7d0;
          }
LAB_0001a7bc:
          uVar10 = 0;
          goto LAB_0001a7dc;
        }
        if (*(ushort *)(param_2 + 0x12) == 0) {
          iVar2 = *(int *)(param_1 + 0x10);
          iVar1 = DAT_0001a814 + 0x1a7cc;
        }
        else {
          if (puVar6 == (ushort *)0x0) goto LAB_0001a7bc;
          uVar9 = *(ushort *)(param_2 + 0x12) - 1;
          if (uVar9 != 0) goto LAB_0001a786;
          uVar9 = 0;
          puVar4 = puVar6;
LAB_0001a7d0:
          uVar10 = uVar9;
          if ((char)*puVar4 == '\0') goto LAB_0001a7dc;
          iVar2 = *(int *)(param_1 + 0x10);
          iVar1 = DAT_0001a81c + 0x1a7dc;
        }
        break;
      case 8:
      case 9:
        iVar1 = *(int *)(param_2 + 0x24);
        if (iVar1 != 0) {
          if ((((bVar11 & 0xf) == 9) && (iVar2 = *(int *)(param_2 + 0x20), iVar2 != 0)) &&
             (*(code **)(iVar2 + -8) != (code *)0x0)) {
            iVar1 = (**(code **)(iVar2 + -8))(param_1,param_2,iVar2 + -4);
            if (iVar1 == 0) goto LAB_0001a766;
            iVar1 = *(int *)(param_2 + 0x24);
          }
          puVar3 = local_14;
          if ((uint *)**(undefined4 **)(DAT_0001a824 + 0x1a6de) == local_14) {
            puVar3 = (uint *)pb_encode_submessage(param_1,iVar1,*(undefined4 *)(param_2 + 0x1c));
            return puVar3;
          }
          goto LAB_0001a7f6;
        }
        iVar2 = *(int *)(param_1 + 0x10);
        iVar1 = DAT_0001a820 + 0x1a760;
        break;
      default:
        iVar2 = *(int *)(param_1 + 0x10);
        iVar1 = DAT_0001a828 + 0x1a752;
        break;
      case 0xb:
        puVar6 = *(ushort **)(param_2 + 0x1c);
        uVar10 = (uint)*(ushort *)(param_2 + 0x12);
LAB_0001a7dc:
        if ((uint *)**(undefined4 **)(DAT_0001a818 + 0x1a7e4) == local_14) {
LAB_0001a7ea:
          puVar3 = (uint *)__ThumbV7PILongThunk_pb_encode_string(param_1,puVar6,uVar10);
          return puVar3;
        }
        goto LAB_0001a7f6;
      }
      if (iVar2 != 0) {
        iVar1 = iVar2;
      }
      *(int *)(param_1 + 0x10) = iVar1;
    }
LAB_0001a766:
    puVar3 = (uint *)0x0;
  }
LAB_0001a768:
  if ((uint *)**(undefined4 **)(DAT_0001a82c + 0x1a770) == local_14) {
    return puVar3;
  }
LAB_0001a7f6:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(puVar3);
}



// ===========================================================
// Function: pb_enc_varint at 0001a830
// ===========================================================

undefined4 pb_enc_varint(int param_1,int param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  
  bVar8 = *(byte *)(param_2 + 0x16) & 0xf;
  if (bVar8 == 2) {
    switch(*(undefined2 *)(param_2 + 0x12)) {
    case 1:
      puVar2 = *(uint **)(param_2 + 0x1c);
      uVar6 = (uint)(byte)*puVar2;
      break;
    case 2:
      puVar2 = *(uint **)(param_2 + 0x1c);
      uVar6 = (uint)(ushort)*puVar2;
      break;
    default:
      goto switchD_0001a844_caseD_3;
    case 4:
      puVar2 = *(uint **)(param_2 + 0x1c);
      uVar6 = *puVar2;
      break;
    case 8:
      puVar3 = *(undefined4 **)(param_2 + 0x1c);
      uVar1 = __ThumbV7PILongThunk_pb_encode_varint(param_1,puVar3,*puVar3,puVar3[1]);
      return uVar1;
    }
    uVar1 = __ThumbV7PILongThunk_pb_encode_varint(param_1,puVar2,uVar6,0);
    return uVar1;
  }
  switch(*(undefined2 *)(param_2 + 0x12)) {
  case 1:
    uVar6 = (uint)**(char **)(param_2 + 0x1c);
    break;
  case 2:
    uVar6 = (uint)**(short **)(param_2 + 0x1c);
    break;
  default:
switchD_0001a844_caseD_3:
    iVar5 = DAT_0001a8d0 + 0x1a876;
    if (*(int *)(param_1 + 0x10) != 0) {
      iVar5 = *(int *)(param_1 + 0x10);
    }
    *(int *)(param_1 + 0x10) = iVar5;
    return 0;
  case 4:
    uVar6 = **(uint **)(param_2 + 0x1c);
    break;
  case 8:
    uVar6 = **(uint **)(param_2 + 0x1c);
    uVar7 = (*(uint **)(param_2 + 0x1c))[1];
    goto LAB_0001a8b0;
  }
  uVar7 = (int)uVar6 >> 0x1f;
LAB_0001a8b0:
  if (bVar8 == 3) {
    uVar4 = uVar7 << 1 | uVar6 >> 0x1f;
    uVar1 = __ThumbV7PILongThunk_pb_encode_varint
                      (param_1,uVar4,uVar6 << 1 ^ (int)uVar7 >> 0x1f,uVar4 ^ (int)uVar7 >> 0x1f);
    return uVar1;
  }
  uVar1 = pb_encode_varint();
  return uVar1;
}



// ===========================================================
// Function: pb_enc_fixed at 0001a8d4
// ===========================================================

undefined4 pb_enc_fixed(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_2 + 0x12) == 8) {
    uVar1 = __ThumbV7PILongThunk_pb_write(param_1,*(undefined4 *)(param_2 + 0x1c),8);
    return uVar1;
  }
  if (*(short *)(param_2 + 0x12) == 4) {
    uVar1 = __ThumbV7PILongThunk_pb_write(param_1,*(undefined4 *)(param_2 + 0x1c),4);
    return uVar1;
  }
  iVar2 = DAT_0001a900 + 0x1a8f6;
  if (*(int *)(param_1 + 0x10) != 0) {
    iVar2 = *(int *)(param_1 + 0x10);
  }
  *(int *)(param_1 + 0x10) = iVar2;
  return 0;
}



// ===========================================================
// Function: get_crc_table at 0001a904
// ===========================================================

undefined * get_crc_table(void)

{
  return &UNK_0001a90a + DAT_0001a90c;
}



// ===========================================================
// Function: uart_crc32 at 0001a910
// ===========================================================

uint uart_crc32(uint param_1,byte *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 != (byte *)0x0) {
    param_1 = ~param_1;
    iVar1 = DAT_0001a9d8 + 0x1a920;
    for (; 7 < param_3; param_3 = param_3 - 8) {
      uVar2 = *(uint *)(iVar1 + ((*param_2 ^ param_1) & 0xff) * 4) ^ param_1 >> 8;
      uVar2 = *(uint *)(iVar1 + ((param_2[1] ^ uVar2) & 0xff) * 4) ^ uVar2 >> 8;
      uVar2 = *(uint *)(iVar1 + ((param_2[2] ^ uVar2) & 0xff) * 4) ^ uVar2 >> 8;
      uVar2 = *(uint *)(iVar1 + ((param_2[3] ^ uVar2) & 0xff) * 4) ^ uVar2 >> 8;
      uVar2 = *(uint *)(iVar1 + ((param_2[4] ^ uVar2) & 0xff) * 4) ^ uVar2 >> 8;
      uVar2 = *(uint *)(iVar1 + ((param_2[5] ^ uVar2) & 0xff) * 4) ^ uVar2 >> 8;
      uVar2 = *(uint *)(iVar1 + ((param_2[6] ^ uVar2) & 0xff) * 4) ^ uVar2 >> 8;
      param_1 = *(uint *)(iVar1 + ((param_2[7] ^ uVar2) & 0xff) * 4) ^ uVar2 >> 8;
      param_2 = param_2 + 8;
    }
    for (; param_3 != 0; param_3 = param_3 - 1) {
      param_1 = *(uint *)(iVar1 + ((*param_2 ^ param_1) & 0xff) * 4) ^ param_1 >> 8;
      param_2 = param_2 + 1;
    }
    return ~param_1;
  }
  return 0;
}



// ===========================================================
// Function: print_receive_data at 0001a9dc
// ===========================================================

undefined4 print_receive_data(byte *param_1,int param_2)

{
  char *__format;
  int iVar1;
  
  if (0 < param_2) {
    __format = (char *)(DAT_0001aa08 + 0x1a9f0);
    iVar1 = DAT_0001aa0c + 0x1a9f2;
    do {
      printf(__format,iVar1,(uint)*param_1);
      param_2 = param_2 + -1;
      param_1 = param_1 + 1;
    } while (param_2 != 0);
  }
  return 0;
}



// ===========================================================
// Function: recv_data at 0001aa10
// ===========================================================

int recv_data(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = 0;
  puVar5 = *(undefined4 **)(DAT_0001aa8c + 0x1aa20);
  while( true ) {
    iVar1 = __read_chk(*puVar5,param_1 + iVar4,param_2,0xffffffff);
    if (iVar1 < 0) {
      piVar2 = (int *)__errno();
      pcVar3 = strerror(*piVar2);
      printf((char *)(DAT_0001aa90 + 0x1aa56),DAT_0001aa94 + 0x1aa58,param_2,pcVar3);
      return -1;
    }
    if (iVar1 == 0) break;
    if (param_2 <= iVar1) {
      return 0;
    }
    iVar4 = iVar4 + iVar1;
    param_2 = param_2 - iVar1;
  }
  piVar2 = (int *)__errno();
  pcVar3 = strerror(*piVar2);
  printf((char *)(DAT_0001aa98 + 0x1aa7c),DAT_0001aa9c + 0x1aa7e,pcVar3,-param_2,0);
  return -param_2;
}



// ===========================================================
// Function: handle_sync_msg at 0001aaa0
// ===========================================================

undefined4 handle_sync_msg(void)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  
  cVar1 = *(char *)(DAT_0001ab68 + 0x1aaac);
  if (cVar1 == 'U') {
    puts((char *)(DAT_0001ab78 + 0x1aace));
    *(undefined4 *)(DAT_0001ab7c + 0x1aad8) = 1;
    *(undefined1 *)(DAT_0001ab80 + 0x1aade) = 1;
  }
  else {
    if (cVar1 == '\0') {
      puts((char *)(DAT_0001ab6c + 0x1aab4));
      *(undefined4 *)(DAT_0001ab70 + 0x1aabe) = 1;
      *(undefined1 *)(DAT_0001ab74 + 0x1aac6) = 0;
      return 0;
    }
    piVar4 = (int *)(DAT_0001ab84 + 0x1aae8);
    iVar2 = *piVar4;
    if (iVar2 == 1) {
      cVar3 = '\x02';
      if (*(char *)(DAT_0001ab88 + 0x1aaf4) != '\0') {
        cVar3 = 'W';
      }
      if (cVar1 != cVar3) {
LAB_0001ab24:
        puts((char *)(DAT_0001aba8 + 0x1ab2a));
        return 5;
      }
      if (*(char *)(DAT_0001ab68 + 0x1aaaa) != *(char *)(DAT_0001ab8c + 0x1ab06)) {
        puts((char *)(DAT_0001ab90 + 0x1ab4c));
        return 0xe2;
      }
      puts((char *)(DAT_0001ab94 + 0x1ab10));
    }
    else {
      if (cVar1 == '\x02' && iVar2 == 0) {
        puts((char *)(DAT_0001ab98 + 0x1ab36));
        *(undefined1 *)(DAT_0001ab9c + 0x1ab40) = 0;
        *piVar4 = 2;
        return 0;
      }
      if (cVar1 != 'W' || iVar2 != 0) goto LAB_0001ab24;
      puts((char *)(DAT_0001aba0 + 0x1ab58));
      *(undefined1 *)(DAT_0001aba4 + 0x1ab62) = 1;
    }
    *piVar4 = 2;
  }
  return 0;
}



// ===========================================================
// Function: check_sum at 0001abac
// ===========================================================

char check_sum(char *param_1,int param_2)

{
  char cVar1;
  
  cVar1 = '\0';
  for (; param_2 != 0; param_2 = param_2 + -1) {
    cVar1 = cVar1 + *param_1;
    param_1 = param_1 + 1;
  }
  return cVar1;
}



// ===========================================================
// Function: init_parse_state at 0001abc0
// ===========================================================

void init_parse_state(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(DAT_0001abd8 + 0x1abca);
  *puVar1 = 0;
  *(undefined1 *)(DAT_0001abdc + 0x1abd0) = 0;
  *param_1 = puVar1;
  *param_2 = 4;
  return;
}



// ===========================================================
// Function: burn_seq_valid at 0001abe0
// ===========================================================

bool burn_seq_valid(uint param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = 0;
  bVar2 = true;
  do {
    while (*(int *)(DAT_0001ac2c + 0x1abf0 + iVar3 * 4) != 1) {
      bVar1 = !bVar2;
      iVar3 = 1;
      bVar2 = false;
      if (bVar1) {
        return false;
      }
    }
    uVar4 = (uint)*(ushort *)(DAT_0001ac30 + 0x1abf2 + iVar3 * 2);
    iVar3 = 1;
    bVar1 = (bool)(uVar4 != param_1 & bVar2);
    bVar2 = false;
  } while (bVar1);
  return uVar4 == param_1;
}



// ===========================================================
// Function: check_msg_hdr at 0001ac34
// ===========================================================

undefined4 check_msg_hdr(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(DAT_0001af5c + 0x1ac3f);
  if (uVar2 - 0x50 < 0x17) {
                    /* WARNING: Could not recover jumptable at 0x0001ac4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(&switchD_0001ac4a::switchdataD_0001ac4e +
                      (&switchD_0001ac4a::switchdataD_0001ac4e)[uVar2 - 0x50]))();
    return uVar1;
  }
  if (uVar2 < 4) {
                    /* WARNING: Could not recover jumptable at 0x0001ac8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(&switchD_0001ac8e::switchdataD_0001ac92 +
                      (uint)(&switchD_0001ac8e::switchdataD_0001ac92)[uVar2] * 2))();
    return uVar1;
  }
  puts((char *)(DAT_0001af60 + 0x1ac48));
  return 0xf;
}



// ===========================================================
// Function: handle_data at 0001b0d0
// ===========================================================

int handle_data(void)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  
  uVar1 = (uint)(byte)(*(char *)(DAT_0001b14c + 0x1b0db) + 5);
  if (uVar1 != 0) {
    cVar3 = '\0';
    pcVar4 = (char *)(DAT_0001b150 + 0x1b0e6);
    do {
      uVar1 = uVar1 - 1;
      cVar3 = cVar3 + *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (uVar1 != 0);
    if (cVar3 == -1) {
      uVar1 = *(byte *)(DAT_0001b150 + 0x1b0e7) - 0x50;
      if (uVar1 < 0x17) {
        if ((1 << (uVar1 & 0xff) & 0x7f003eU) != 0) {
          return 0;
        }
        if (uVar1 == 0) {
          uVar1 = *(uint *)(DAT_0001b15c + 0x1b122);
          iVar2 = handle_sync_msg(0);
          if (iVar2 == 0) {
            iVar2 = 3;
            if (uVar1 < 2) {
              iVar2 = 0;
            }
            return iVar2;
          }
          return iVar2;
        }
      }
      if (*(byte *)(DAT_0001b150 + 0x1b0e7) < 4) {
        return 0;
      }
      puts((char *)(DAT_0001b158 + 0x1b146));
      return 0xf;
    }
  }
  puts((char *)(DAT_0001b154 + 0x1b0fc));
  return 2;
}



// ===========================================================
// Function: parse_packet at 0001b160
// ===========================================================

undefined4 parse_packet(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  
  iVar1 = DAT_0001b1e4;
  pcVar3 = (char *)(DAT_0001b1e0 + 0x1b16e);
  if (*pcVar3 == '\0') {
    pcVar4 = (char *)(DAT_0001b1e4 + 0x1b182);
    if (*pcVar4 == -0x42) {
      iVar2 = check_msg_hdr();
      if (iVar2 != 0) {
        return 1;
      }
      *pcVar3 = '\x01';
      *param_1 = iVar1 + 0x1b186;
      iVar1 = *(byte *)(iVar1 + 0x1b185) + 1;
    }
    else {
      iVar2 = *param_2;
      iVar5 = 1;
      iVar1 = iVar5;
      if (1 < iVar2) {
        do {
          if (pcVar4[iVar5] == -0x42) {
            __memmove_chk(pcVar4,pcVar4 + iVar5,iVar2 - iVar5,0x1a);
            iVar1 = iVar5;
            break;
          }
          iVar5 = iVar5 + 1;
          iVar1 = iVar2;
        } while (iVar2 != iVar5);
      }
      *param_1 = (int)(pcVar4 + (iVar2 - iVar1));
      iVar1 = (iVar1 - iVar2) + 4;
    }
  }
  else {
    iVar1 = handle_data();
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = 0;
    *param_1 = 0;
  }
  *param_2 = iVar1;
  return 0;
}



// ===========================================================
// Function: recv_reply at 0001b1e8
// ===========================================================

void recv_reply(void *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_28;
  undefined4 *local_24;
  int local_20;
  
  *(undefined1 *)(DAT_0001b274 + 0x1b200) = 0;
  iVar1 = DAT_0001b278;
  local_24 = (undefined4 *)(DAT_0001b278 + 0x1b206);
  *local_24 = 0;
  local_20 = **(int **)(DAT_0001b27c + 0x1b20e);
  local_28 = 4;
  do {
    iVar2 = recv_data(local_24);
    if ((iVar2 == 1) || (iVar2 = parse_packet(&local_24,&local_28), iVar2 != 0)) {
      uVar3 = 1;
      goto LAB_0001b25a;
    }
  } while ((local_24 != (undefined4 *)0x0) || (local_28 != 0));
  *param_3 = (uint)*(byte *)(iVar1 + 0x1b209);
  if (param_2 < *(byte *)(iVar1 + 0x1b209)) {
    puts((char *)(DAT_0001b280 + 0x1b246));
    uVar3 = 0xe3;
  }
  else {
    __aeabi_memcpy8(param_1,(void *)(iVar1 + 0x1b20a),(uint)*(byte *)(iVar1 + 0x1b209));
    uVar3 = 0;
  }
LAB_0001b25a:
  if (**(int **)(DAT_0001b284 + 0x1b262) != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



// ===========================================================
// Function: send_data at 0001b288
// ===========================================================

int send_data(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if (param_2 != 0) {
    iVar4 = 0;
    puVar5 = *(undefined4 **)(DAT_0001b2ec + 0x1b29a);
    do {
      iVar1 = __write_chk(*puVar5,param_1 + iVar4,param_2,0xffffffff);
      if (iVar1 == -1) {
        piVar2 = (int *)__errno();
        if (*piVar2 != 0xb) {
          pcVar3 = strerror(*piVar2);
          printf((char *)(DAT_0001b2f8 + 0x1b2e2),DAT_0001b2fc + 0x1b2e4,pcVar3);
          return param_2;
        }
      }
      else {
        if (iVar1 == 0) {
          printf((char *)(DAT_0001b2f0 + 0x1b2ce),DAT_0001b2f4 + 0x1b2d0);
          return param_2;
        }
        param_2 = param_2 - iVar1;
        iVar4 = iVar4 + iVar1;
      }
    } while (param_2 != 0);
  }
  return 0;
}



// ===========================================================
// Function: send_sync_reply at 0001b300
// ===========================================================

undefined4 send_sync_reply(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  byte bVar6;
  undefined1 uVar7;
  int iVar8;
  
  if (*(int *)(DAT_0001b368 + 0x1b308) == 1) {
    cVar5 = *(char *)(DAT_0001b36c + 0x1b314);
  }
  else {
    cVar5 = *(char *)(DAT_0001b370 + 0x1b31a);
    *(char *)(DAT_0001b370 + 0x1b31a) = cVar5 + '\x01';
  }
  iVar2 = DAT_0001b374;
  uVar7 = 1;
  iVar3 = DAT_0001b374 + 0x1b328;
  *(undefined1 *)(DAT_0001b374 + 0x1b32b) = 1;
  *(char *)(iVar2 + 0x1b32a) = cVar5;
  *(undefined1 *)(iVar2 + 0x1b329) = 0x50;
  *(char *)(DAT_0001b378 + 0x1b332) = cVar5;
  if (*(char *)(DAT_0001b37c + 0x1b338) != '\0') {
    uVar7 = 0x56;
  }
  *(undefined1 *)(iVar2 + 0x1b32c) = uVar7;
  bVar6 = 0;
  iVar8 = 0;
  do {
    pcVar1 = (char *)(iVar3 + iVar8);
    iVar8 = iVar8 + 1;
    bVar6 = bVar6 + *pcVar1;
  } while (iVar8 != 5);
  *(byte *)(iVar2 + 0x1b32d) = ~bVar6;
  uVar4 = send_data(iVar3,6);
  printf((char *)(DAT_0001b380 + 0x1b362),uVar4);
  return uVar4;
}



// ===========================================================
// Function: uart_upgrade at 0001b384
// ===========================================================

void uart_upgrade(void)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  char *__s;
  char *pcVar5;
  char *__s_00;
  int *piVar6;
  char *__s_01;
  undefined1 auStack_30 [4];
  undefined2 local_2c;
  undefined1 local_2a;
  int local_28;
  
  local_28 = **(int **)(DAT_0001b458 + 0x1b390);
  local_2a = 0;
  local_2c = 0;
  puts((char *)(DAT_0001b45c + 0x1b3a4));
  iVar1 = recv_reply(&local_2c,3,auStack_30);
  if (iVar1 == 0) {
    piVar6 = (int *)(DAT_0001b464 + 0x1b3be);
    if (*piVar6 == 1) {
      puts((char *)(DAT_0001b46c + 0x1b3c8));
      iVar1 = send_sync_reply();
      if (iVar1 == 0) {
        pcVar3 = (char *)(DAT_0001b474 + 0x1b40e);
        pcVar4 = (char *)(DAT_0001b478 + 0x1b41a);
        __s_01 = (char *)(DAT_0001b47c + 0x1b41c);
        __s_00 = (char *)(DAT_0001b480 + 0x1b41e);
        pcVar5 = (char *)(DAT_0001b484 + 0x1b420);
        do {
          iVar1 = recv_reply(&local_2c,3,auStack_30);
          __s = pcVar3;
          if (iVar1 != 0) break;
          iVar1 = *piVar6;
          if (iVar1 != 1) {
            __s = pcVar4;
            if (iVar1 == 2) {
              uVar2 = 1;
              goto LAB_0001b3ea;
            }
            break;
          }
          puts(__s_01);
          puts(__s_00);
          iVar1 = send_sync_reply();
          __s = pcVar5;
        } while (iVar1 == 0);
      }
      else {
        __s = (char *)(DAT_0001b470 + 0x1b3d6);
      }
    }
    else {
      __s = (char *)(DAT_0001b468 + 0x1b3dc);
    }
  }
  else {
    __s = (char *)(DAT_0001b460 + 0x1b3b8);
  }
  puts(__s);
  puts((char *)(DAT_0001b488 + 0x1b3e6));
  uVar2 = 0;
LAB_0001b3ea:
  if (**(int **)(DAT_0001b48c + 0x1b3f2) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}



// ===========================================================
// Function: construct_packet at 0001b490
// ===========================================================

undefined4 construct_packet(undefined4 param_1,uint param_2,undefined1 param_3,undefined1 param_4)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = DAT_0001b4e0;
  if (0x16 < param_2) {
    puts((char *)(DAT_0001b4dc + 0x1b49e));
    return 0xffffffff;
  }
  *(char *)(DAT_0001b4e0 + 0x1b4b1) = (char)param_2;
  *(undefined1 *)(iVar2 + 0x1b4b0) = param_4;
  *(undefined1 *)(iVar2 + 0x1b4af) = param_3;
  if (param_2 != 0) {
    __memcpy_chk(iVar2 + 0x1b4b2,param_1,param_2,0x16);
  }
  iVar2 = param_2 + 4;
  bVar1 = 0;
  pcVar3 = (char *)(DAT_0001b4e4 + 0x1b4c8);
  do {
    iVar2 = iVar2 + -1;
    bVar1 = bVar1 + *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (iVar2 != 0);
  ((char *)(DAT_0001b4e4 + 0x1b4c8))[param_2 + 4] = ~bVar1;
  return 0;
}



// ===========================================================
// Function: get_program_crc at 0001b4e8
// ===========================================================

void get_program_crc(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_128 [260];
  int local_24;
  
  local_24 = **(int **)(DAT_0001b580 + 0x1b4fe);
  __aeabi_memclr8(auStack_128,0x100);
  uVar2 = param_2 >> 8;
  if (uVar2 == 0) {
    uVar3 = 0;
    iVar1 = 0x61c;
  }
  else {
    iVar1 = 0x61c;
    uVar3 = 0;
    do {
      __aeabi_memcpy8(auStack_128,(void *)(param_1 + iVar1),0x100);
      uVar3 = uart_crc32(uVar3,auStack_128,0x100);
      uVar2 = uVar2 - 1;
      iVar1 = iVar1 + 0x100;
    } while (uVar2 != 0);
  }
  __memcpy_chk(auStack_128,param_1 + iVar1,param_2 & 0xff,0x100);
  uVar3 = uart_crc32(uVar3,auStack_128,param_2 & 0xff);
  *param_3 = uVar3;
  if (**(int **)(DAT_0001b584 + 0x1b56e) == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// ===========================================================
// Function: prepare_code_msg at 0001b588
// ===========================================================

void prepare_code_msg(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_1c;
  undefined2 local_18;
  undefined1 local_16;
  int local_14;
  
  iVar1 = DAT_0001b644;
  local_14 = **(int **)(DAT_0001b63c + 0x1b596);
  local_16 = 0;
  local_18 = 0;
  if (param_2 < 0x421) {
    puts((char *)(DAT_0001b640 + 0x1b5ae));
    uVar2 = 1;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + param_2 + -4);
    puVar5 = (undefined4 *)(DAT_0001b644 + 0x1b5c4);
    *puVar5 = 0;
    *(undefined4 *)(iVar1 + 0x1b5c8) = 0;
    *(uint *)(DAT_0001b648 + 0x1b5cc) = param_2 - 0x618;
    local_1c = 0;
    *(undefined4 *)(DAT_0001b64c + 0x1b5d6) = uVar2;
    iVar4 = param_2 - 0x620;
    get_program_crc(param_1,iVar4,&local_1c);
    *(undefined4 *)(DAT_0001b650 + 0x1b5ec) = local_1c;
    iVar3 = construct_packet(&local_18,3,0x54,0xa2);
    if (iVar3 == 0) {
      *(undefined4 *)(DAT_0001b654 + 0x1b606) = 0x61c;
      *(ushort *)(DAT_0001b658 + 0x1b60e) = (ushort)iVar4 & 0xff;
      *(short *)(DAT_0001b65c + 0x1b616) = (short)((uint)iVar4 >> 8);
      uVar2 = *(undefined4 *)(DAT_0001b660 + 0x1b620);
      *puVar5 = *(undefined4 *)(DAT_0001b660 + 0x1b61c);
      *(undefined4 *)(iVar1 + 0x1b5c8) = uVar2;
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  if (**(int **)(DAT_0001b664 + 0x1b62c) != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



// ===========================================================
// Function: send_packet at 0001b668
// ===========================================================

undefined4 send_packet(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = construct_packet();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  uVar2 = __ThumbV7PILongThunk_send_data
                    (DAT_0001b688 + 0x1b67c,*(byte *)(DAT_0001b688 + 0x1b67f) + 5);
  return uVar2;
}



// ===========================================================
// Function: run_programmer at 0001b68c
// ===========================================================

void run_programmer(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  ushort uVar3;
  int iVar4;
  undefined2 *puVar5;
  ushort *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  void *__dest;
  int iVar9;
  int *piVar10;
  char *pcVar11;
  undefined1 auStack_38 [7];
  char local_31;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  
  puVar7 = (undefined4 *)(DAT_0001b820 + 0x1b6a0);
  *puVar7 = 5;
  pcVar11 = (char *)(DAT_0001b824 + 0x1b6a6);
  *pcVar11 = *pcVar11 + '\x01';
  local_24 = **(int **)(DAT_0001b828 + 0x1b6b0);
  local_31 = '\0';
  local_30 = *(undefined4 *)(DAT_0001b82c + 0x1b6c0);
  local_2c = *(int *)(DAT_0001b830 + 0x1b6c8) + -8;
  local_28 = *(undefined4 *)(DAT_0001b834 + 0x1b6d2);
  iVar4 = send_packet(&local_30,0xc,0x53);
  if (iVar4 == 0) {
    iVar4 = recv_reply(&local_31,1,auStack_38);
    if (iVar4 == 0) {
      if (local_31 != '\0') {
        pcVar11 = (char *)(DAT_0001b840 + 0x1b722);
LAB_0001b720:
        puts(pcVar11);
        goto LAB_0001b6fc;
      }
      puts((char *)(DAT_0001b844 + 0x1b72e));
      *puVar7 = 6;
      send_data(DAT_0001b848 + 0x1b73e,8);
      piVar10 = (int *)(DAT_0001b84c + 0x1b746);
      iVar4 = *piVar10;
      puVar6 = (ushort *)(DAT_0001b850 + 0x1b74c);
      if (*puVar6 != 0) {
        uVar8 = 0;
        __dest = (void *)(DAT_0001b854 + 0x1b758);
        do {
          __aeabi_memcpy8(__dest,(void *)(param_1 + iVar4),0x100);
          send_data(__dest,0x100);
          uVar3 = *puVar6;
          uVar8 = uVar8 + 1;
          iVar4 = *piVar10 + 0x100;
          *piVar10 = iVar4;
        } while (uVar8 < uVar3);
      }
      puVar5 = (undefined2 *)(DAT_0001b858 + 0x1b792);
      uVar2 = *puVar5;
      iVar9 = DAT_0001b85c + 0x1b79a;
      __memcpy_chk(iVar9,param_1 + iVar4,uVar2,0x100);
      iVar4 = send_data(iVar9,uVar2);
      *piVar10 = 0;
      *puVar6 = 0;
      *puVar5 = 0;
      if (iVar4 == 0) {
        puts((char *)(DAT_0001b864 + 0x1b7c4));
        iVar4 = recv_reply(&local_31,1,auStack_38);
        if (iVar4 == 0) {
          if (local_31 == ' ') {
            puts((char *)(DAT_0001b870 + 0x1b7ea));
            cVar1 = *pcVar11;
            *puVar7 = 7;
            *pcVar11 = cVar1 + '\x01';
            iVar4 = send_packet(0,0,0x55);
            if (iVar4 != 0) {
              puts((char *)(DAT_0001b874 + 0x1b812));
            }
            goto LAB_0001b6fc;
          }
          pcVar11 = &UNK_0001b81e + DAT_0001b86c;
          goto LAB_0001b720;
        }
        pcVar11 = (char *)(DAT_0001b868 + 0x1b7dc);
      }
      else {
        pcVar11 = (char *)(DAT_0001b860 + 0x1b7be);
      }
    }
    else {
      pcVar11 = (char *)(DAT_0001b83c + 0x1b6fa);
    }
  }
  else {
    pcVar11 = (char *)(DAT_0001b838 + 0x1b6e4);
  }
  puts(pcVar11);
LAB_0001b6fc:
  if (**(int **)(DAT_0001b878 + 0x1b704) == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_24);
}



// ===========================================================
// Function: get_flash_crc at 0001b87c
// ===========================================================

void get_flash_crc(int param_1,uint param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 auStack_128 [260];
  int local_24;
  
  local_24 = **(int **)(DAT_0001b908 + 0x1b894);
  __aeabi_memclr8(auStack_128,0x100);
  uVar1 = 0;
  for (uVar2 = param_2 >> 8; uVar2 != 0; uVar2 = uVar2 - 1) {
    __aeabi_memcpy8(auStack_128,(void *)(param_1 + param_3),0x100);
    uVar1 = uart_crc32(uVar1,auStack_128,0x100);
    param_3 = param_3 + 0x100;
  }
  __memcpy_chk(auStack_128,param_1 + param_3,param_2 & 0xff,0x100);
  uVar1 = uart_crc32(uVar1,auStack_128,param_2 & 0xff);
  *param_4 = uVar1;
  if (**(int **)(DAT_0001b90c + 0x1b8f8) != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// ===========================================================
// Function: prepare_burn_data_msg at 0001b910
// ===========================================================

void prepare_burn_data_msg(int param_1,uint param_2)

{
  char *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  uint uVar13;
  undefined4 local_2c;
  int local_28;
  
  local_28 = **(int **)(DAT_0001ba34 + 0x1b920);
  puts((char *)(DAT_0001ba38 + 0x1b92a));
  puVar11 = (uint *)(DAT_0001ba3c + 0x1b936);
  *puVar11 = param_2;
  printf((char *)(DAT_0001ba40 + 0x1b93c),param_2,param_2);
  uVar2 = *puVar11;
  if (uVar2 < 4) {
    puts((char *)(DAT_0001ba44 + 0x1b94a));
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + uVar2 + -4);
    *puVar11 = uVar2 - 4;
    puVar8 = (uint *)(DAT_0001ba48 + 0x1b966);
    *puVar8 = uVar2 + 0x7ffb >> 0xf;
    *(undefined4 *)(DAT_0001ba4c + 0x1b96c) = uVar3;
    printf((char *)(DAT_0001ba50 + 0x1b972));
    if (*puVar8 >> 0x10 == 0) {
      if (*puVar8 != 0) {
        iVar10 = 0;
        uVar13 = 0;
        local_2c = 0;
        iVar7 = DAT_0001ba54 + 0x1b9a4;
        uVar2 = 0;
        iVar9 = iVar7;
        do {
          iVar12 = 0x8000;
          if (*puVar11 < uVar2 + 0x8000) {
            iVar12 = *puVar11 - uVar2;
          }
          get_flash_crc(param_1,iVar12,iVar10,&local_2c);
          iVar6 = 0;
          *(undefined2 *)(iVar7 + uVar13 * 0x10) = 0x62be;
          iVar4 = iVar7 + uVar13 * 0x10;
          *(undefined1 *)(iVar4 + 3) = 0xb;
          *(int *)(iVar4 + 4) = iVar12;
          *(short *)(iVar4 + 0xc) = (short)uVar13;
          *(char *)(iVar4 + 2) = (char)uVar13 + -0x3f;
          *(undefined1 *)(iVar4 + 0xe) = 0;
          *(undefined4 *)(iVar4 + 8) = local_2c;
          bVar5 = 0;
          do {
            pcVar1 = (char *)(iVar9 + iVar6);
            iVar6 = iVar6 + 1;
            bVar5 = bVar5 + *pcVar1;
          } while (iVar6 != 0xf);
          uVar13 = uVar13 + 1;
          iVar10 = iVar10 + iVar12;
          iVar9 = iVar9 + 0x10;
          *(byte *)(iVar4 + 0xf) = ~bVar5;
          uVar2 = uVar2 + 0x8000;
        } while (uVar13 < *puVar8);
      }
      puts((char *)(DAT_0001ba58 + 0x1ba16));
      uVar3 = 0;
      goto LAB_0001ba1a;
    }
    puts((char *)(DAT_0001ba60 + 0x1b984));
    *puVar8 = 0;
  }
  uVar3 = 1;
LAB_0001ba1a:
  if (**(int **)(DAT_0001ba5c + 0x1ba22) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



// ===========================================================
// Function: burn_cmd_erase_chip at 0001ba64
// ===========================================================

void burn_cmd_erase_chip(void)

{
  int iVar1;
  char *__s;
  undefined1 auStack_14 [7];
  char local_d;
  int local_c;
  
  *(undefined4 *)(DAT_0001baf8 + 0x1ba70) = 0x11;
  local_c = **(int **)(DAT_0001bafc + 0x1ba76);
  puts((char *)(DAT_0001bb00 + 0x1ba80));
  *(char *)(DAT_0001bb04 + 0x1ba8a) = *(char *)(DAT_0001bb04 + 0x1ba8a) + '\x01';
  local_d = '1';
  iVar1 = send_packet(&local_d,1,0x65);
  if (iVar1 == 0) {
    puts((char *)(DAT_0001bb0c + 0x1baae));
    iVar1 = recv_reply(&local_d,1,auStack_14);
    if (iVar1 == 0) {
      if (local_d != '\0') {
        puts((char *)(DAT_0001bb14 + 0x1baec));
      }
      goto LAB_0001bac8;
    }
    __s = (char *)(DAT_0001bb10 + 0x1bac6);
  }
  else {
    __s = (char *)(DAT_0001bb08 + 0x1baa8);
  }
  puts(__s);
LAB_0001bac8:
  if (**(int **)(DAT_0001bb18 + 0x1bad0) == local_c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_c);
}



// ===========================================================
// Function: burn_cmd_burn_data at 0001bb1c
// ===========================================================

void burn_cmd_burn_data(undefined4 param_1,undefined4 param_2,uint param_3)

{
  char *pcVar1;
  int iVar2;
  undefined1 auStack_34 [7];
  char local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int local_18;
  
  local_18 = **(int **)(DAT_0001bbd8 + 0x1bb2c);
  puts((char *)(DAT_0001bbdc + 0x1bb36));
  if (param_3 < 0x11) {
    uStack_24 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_20 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_1c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    *(undefined4 *)(DAT_0001bbe4 + 0x1bb5e) = 0x11;
    local_2d = '\"';
    local_28 = 0;
    local_2c = param_1;
    __memcpy_chk(&local_28,param_2,param_3,0x10);
    *(char *)(DAT_0001bbe8 + 0x1bb78) = *(char *)(DAT_0001bbe8 + 0x1bb78) + '\x01';
    iVar2 = send_packet(&local_2d,param_3 + 5,0x65);
    if (iVar2 == 0) {
      puts((char *)(DAT_0001bbf0 + 0x1bb94));
      iVar2 = recv_reply(&local_2d,1,auStack_34);
      if (iVar2 == 0) {
        if (local_2d == '\0') goto LAB_0001bbae;
        pcVar1 = (char *)(DAT_0001bbf8 + 0x1bbd2);
        goto LAB_0001bb40;
      }
      pcVar1 = (char *)(DAT_0001bbf4 + 0x1bbac);
    }
    else {
      pcVar1 = (char *)(DAT_0001bbec + 0x1bb8e);
    }
    puts(pcVar1);
  }
  else {
    pcVar1 = (char *)(DAT_0001bbe0 + 0x1bb42);
LAB_0001bb40:
    puts(pcVar1);
  }
LAB_0001bbae:
  if (**(int **)(DAT_0001bbfc + 0x1bbb6) == local_18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_18);
}



// ===========================================================
// Function: burn_cmd_burn_set_chip at 0001bc00
// ===========================================================

void burn_cmd_burn_set_chip(void)

{
  int iVar1;
  char *__s;
  undefined1 auStack_28 [7];
  undefined2 local_21;
  undefined1 local_1f;
  undefined4 local_1e;
  undefined4 uStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined2 local_e;
  int local_c;
  
  uStack_1a = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_16 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_12 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_c = **(int **)(DAT_0001bca8 + 0x1bc14);
  local_1e = 0;
  local_e = 0;
  puts((char *)(DAT_0001bcac + 0x1bc26));
  *(undefined4 *)(DAT_0001bcb0 + 0x1bc32) = 0x11;
  *(char *)(DAT_0001bcb4 + 0x1bc38) = *(char *)(DAT_0001bcb4 + 0x1bc38) + '\x01';
  local_1f = 1;
  local_21 = 0x61;
  iVar1 = send_packet(&local_21,4,0x65);
  if (iVar1 == 0) {
    puts((char *)(DAT_0001bcbc + 0x1bc60));
    iVar1 = recv_reply(&local_21,1,auStack_28);
    if (iVar1 == 0) {
      if ((char)local_21 != '\0') {
        puts((char *)(DAT_0001bcc4 + 0x1bc9e));
      }
      goto LAB_0001bc7a;
    }
    __s = (char *)(DAT_0001bcc0 + 0x1bc78);
  }
  else {
    __s = (char *)(DAT_0001bcb8 + 0x1bc5a);
  }
  puts(__s);
LAB_0001bc7a:
  if (**(int **)(DAT_0001bcc8 + 0x1bc82) == local_c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_c);
}



// ===========================================================
// Function: init_burn_index at 0001bccc
// ===========================================================

void init_burn_index(void)

{
  int iVar1;
  
  iVar1 = DAT_0001bcec;
  *(undefined4 *)(DAT_0001bcec + 0x1bcd4) = 0;
  *(undefined4 *)(iVar1 + 0x1bcd8) = 0;
  *(undefined4 *)(DAT_0001bcf0 + 0x1bce0) = 0x1000100;
  *(undefined4 *)(DAT_0001bcf4 + 0x1bcea) = 0xffffffff;
  return;
}



// ===========================================================
// Function: get_next_burn_index at 0001bcf8
// ===========================================================

int get_next_burn_index(void)

{
  int *piVar1;
  
  if (*(int *)(DAT_0001bd1c + 0x1bcfe) == 0) {
    piVar1 = (int *)(DAT_0001bd20 + 0x1bd10);
  }
  else {
    if (*(int *)(DAT_0001bd1c + 0x1bd02) != 0) {
      return -1;
    }
    piVar1 = (int *)(DAT_0001bd24 + 0x1bd16);
  }
  return *piVar1 + 1;
}



// ===========================================================
// Function: burn_index_empty at 0001bd28
// ===========================================================

bool burn_index_empty(void)

{
  return *(int *)(DAT_0001bd38 + 0x1bd2e) == 0;
}



// ===========================================================
// Function: add_burn_index at 0001bd3c
// ===========================================================

undefined4 add_burn_index(int param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  iVar2 = DAT_0001bd9c;
  piVar3 = (int *)(DAT_0001bd94 + 0x1bd44);
  if (*piVar3 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(DAT_0001bd98 + 0x1bd4a);
    bVar6 = SBORROW4(param_1,iVar4);
    iVar1 = param_1 - iVar4;
    iVar5 = iVar4;
    if (iVar4 < param_1) {
      iVar5 = iVar4 + 2;
      bVar6 = SBORROW4(iVar5,param_1);
      iVar1 = iVar5 - param_1;
    }
    if (param_1 == iVar5 || iVar1 < 0 != bVar6) {
      return 1;
    }
    iVar4 = param_1 - iVar4;
    if ((piVar3[iVar4] | 2U) != 2) {
      return 1;
    }
  }
  ((int *)(DAT_0001bd98 + 0x1bd4a))[iVar4] = param_1;
  *(undefined2 *)(iVar2 + 0x1bd76 + iVar4 * 2) = param_2;
  *(undefined2 *)(DAT_0001bda0 + 0x1bd7e + iVar4 * 2) = param_3;
  piVar3[iVar4] = 1;
  *(int *)(DAT_0001bda4 + 0x1bd8e) = param_1;
  return 0;
}



// ===========================================================
// Function: set_burn_status at 0001bda8
// ===========================================================

undefined4 set_burn_status(uint param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  undefined2 *puVar7;
  
  iVar3 = DAT_0001be1c;
  iVar2 = DAT_0001be18;
  iVar4 = 0;
  bVar6 = true;
  piVar5 = (int *)(DAT_0001be18 + 0x1bdb8);
  puVar7 = (undefined2 *)(DAT_0001be1c + 0x1bdba);
  while ((piVar5[iVar4] == 0 || ((ushort)puVar7[iVar4] != param_1))) {
    bVar1 = !bVar6;
    bVar6 = false;
    iVar4 = 1;
    if (bVar1) {
      return 1;
    }
  }
  piVar5[iVar4] = param_2;
  if (param_2 == 3 && bVar6 == true) {
    iVar4 = *(int *)(iVar2 + 0x1bdbc);
    if ((iVar4 == 0) || (iVar4 == 3)) {
      *piVar5 = 0;
    }
    else {
      *piVar5 = iVar4;
      *(undefined4 *)(DAT_0001be20 + 0x1be02) = *(undefined4 *)(DAT_0001be20 + 0x1be06);
      *puVar7 = *(undefined2 *)(iVar3 + 0x1bdbc);
      *(undefined2 *)(DAT_0001be24 + 0x1be0e) = *(undefined2 *)(DAT_0001be24 + 0x1be10);
    }
    *(undefined4 *)(iVar2 + 0x1bdbc) = 0;
    return 0;
  }
  return 0;
}



// ===========================================================
// Function: burn_data at 0001be28
// ===========================================================

void burn_data(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  byte bVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  bool bVar18;
  int local_130;
  byte local_12c;
  ushort uStack_12b;
  undefined1 auStack_128 [256];
  int local_28;
  
  local_28 = **(int **)(DAT_0001c054 + 0x1be3a);
  __aeabi_memclr8(auStack_128,0x100);
  iVar2 = DAT_0001c058;
  iVar15 = 0;
  piVar10 = (int *)(DAT_0001c058 + 0x1be52);
  *piVar10 = 0;
  *(undefined4 *)(iVar2 + 0x1be56) = 0;
  *(undefined4 *)(DAT_0001c05c + 0x1be5a) = 0x1000100;
  piVar13 = (int *)(DAT_0001c060 + 0x1be66);
  *piVar13 = -1;
  _local_12c = 0;
  local_130 = 0;
  *(undefined4 *)(DAT_0001c064 + 0x1be78) = 0xe;
  puts((char *)(DAT_0001c068 + 0x1be7e));
  iVar16 = 0;
  piVar11 = (int *)(DAT_0001c06c + 0x1be98);
  iVar3 = DAT_0001c070 + 0x1be9a;
  do {
    while (iVar4 = *piVar10, piVar7 = piVar13, iVar4 != 0) {
      if (*(int *)(iVar2 + 0x1be56) == 0) {
        piVar7 = (int *)(DAT_0001c074 + 0x1bea8);
        break;
      }
LAB_0001bebe:
      iVar15 = recv_reply(&local_12c,3,&local_130);
      if (iVar15 != 0) {
        pcVar5 = (char *)(DAT_0001c084 + 0x1bffc);
        uVar9 = DAT_0001c088 + 0x1bffe;
        goto LAB_0001c026;
      }
      if (local_130 != 3) {
        uVar9 = (uint)local_12c;
        pcVar5 = (char *)(DAT_0001c098 + 0x1c00a);
        iVar15 = DAT_0001c09c + 0x1c00c;
        goto LAB_0001c00a;
      }
      uVar9 = (uint)uStack_12b;
      if (local_12c != 0x60) {
        printf((char *)(DAT_0001c090 + 0x1c01a),DAT_0001c094 + 0x1c01c,uVar9);
        goto LAB_0001c02a;
      }
      iVar4 = set_burn_status(uVar9,3);
      iVar15 = 0;
      if (iVar4 != 0) {
        pcVar5 = (char *)(DAT_0001c08c + 0x1c026);
LAB_0001c026:
        printf(pcVar5,uVar9);
LAB_0001c02a:
        uVar6 = 1;
LAB_0001c02c:
        if (**(int **)(DAT_0001c0a0 + 0x1c034) == local_28) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(uVar6);
      }
    }
    uVar9 = *piVar7 + 1;
    if (*piVar7 == -2) goto LAB_0001bebe;
    if (*piVar11 <= (int)uVar9) {
      if (iVar4 != 0) goto LAB_0001bebe;
      uVar6 = 0;
      goto LAB_0001c02c;
    }
    if (iVar15 != 0) {
      usleep(800000);
    }
    iVar12 = iVar3 + uVar9 * 0x10;
    iVar4 = send_data(iVar12,0x10);
    uVar17 = (uint)*(byte *)(iVar12 + 4);
    uVar1 = *(undefined2 *)(iVar12 + 0xc);
    uVar8 = (uint)*(byte *)(iVar12 + 5) << 8 | (uint)*(byte *)(iVar12 + 6) << 0x10 |
            (uint)*(byte *)(iVar12 + 7) << 0x18;
    if (uVar8 + uVar17 == 0x1000) {
      uVar8 = 0;
      do {
        __aeabi_memcpy8(auStack_128,(void *)(param_1 + iVar16),0x100);
        send_data(auStack_128,0x100);
        bVar18 = uVar8 < 0xf;
        iVar16 = iVar16 + 0x100;
        uVar8 = uVar8 + 1;
      } while (bVar18);
    }
    else {
      if (uVar8 != 0) {
        bVar14 = 0;
        do {
          __aeabi_memcpy8(auStack_128,(void *)(param_1 + iVar16),0x100);
          send_data(auStack_128,0x100);
          bVar14 = bVar14 + 1;
          iVar16 = iVar16 + 0x100;
        } while ((uint)bVar14 < uVar8 >> 8);
      }
      __memcpy_chk(auStack_128,param_1 + iVar16,uVar17,0x100);
      send_data(auStack_128,uVar17);
    }
    if (iVar4 != 0) {
      pcVar5 = (char *)(DAT_0001c078 + 0x1c052);
      iVar15 = (int)&DAT_0001c054 + DAT_0001c07c;
LAB_0001c00a:
      printf(pcVar5,iVar15,uVar9);
      goto LAB_0001c02a;
    }
    iVar4 = add_burn_index(uVar9,uVar1,*(undefined1 *)(iVar12 + 2));
    iVar15 = iVar15 + 1;
    if (iVar4 != 0) {
      pcVar5 = (char *)(DAT_0001c080 + 0x1bff4);
      goto LAB_0001c026;
    }
  } while( true );
}



// ===========================================================
// Function: burn_cmd_erase_usrdata_sector at 0001c0a4
// ===========================================================

void burn_cmd_erase_usrdata_sector(undefined4 param_1,undefined4 param_2,uint param_3)

{
  char *pcVar1;
  int iVar2;
  undefined1 auStack_30 [7];
  char local_29;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int local_14;
  
  local_14 = **(int **)(DAT_0001c14c + 0x1c0b2);
  if (param_3 < 0x11) {
    uStack_20 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_1c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_18 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    local_29 = '!';
    *(undefined4 *)(DAT_0001c154 + 0x1c0dc) = 0x11;
    local_24 = 0;
    local_28 = param_1;
    __memcpy_chk(&local_24,param_2,param_3,0x10);
    *(char *)(DAT_0001c158 + 0x1c0f4) = *(char *)(DAT_0001c158 + 0x1c0f4) + '\x01';
    iVar2 = send_packet(&local_29,param_3 + 5,0x65);
    if (iVar2 == 0) {
      iVar2 = recv_reply(&local_29,1,auStack_30);
      if (iVar2 == 0) {
        if (local_29 == '\0') goto LAB_0001c122;
        pcVar1 = (char *)(DAT_0001c164 + 0x1c146);
        goto LAB_0001c0bc;
      }
      pcVar1 = (char *)(DAT_0001c160 + 0x1c120);
    }
    else {
      pcVar1 = (char *)(DAT_0001c15c + 0x1c10a);
    }
    puts(pcVar1);
  }
  else {
    pcVar1 = (char *)(DAT_0001c150 + 0x1c0be);
LAB_0001c0bc:
    puts(pcVar1);
  }
LAB_0001c122:
  if (**(int **)(DAT_0001c168 + 0x1c12a) == local_14) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_14);
}



// ===========================================================
// Function: burn_cmd_burn_name at 0001c16c
// ===========================================================

void burn_cmd_burn_name(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  char *__s;
  undefined1 auStack_30 [7];
  char local_29;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int local_14;
  
  uStack_20 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_1c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_18 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_14 = **(int **)(DAT_0001c1fc + 0x1c182);
  local_29 = '\"';
  local_24 = 0;
  local_28 = param_1;
  __memcpy_chk(&local_24,param_2,param_3,0x10);
  *(char *)(DAT_0001c200 + 0x1c1a4) = *(char *)(DAT_0001c200 + 0x1c1a4) + '\x01';
  iVar1 = send_packet(&local_29,param_3 + 5,0x65);
  if (iVar1 == 0) {
    iVar1 = recv_reply(&local_29,1,auStack_30);
    if (iVar1 == 0) {
      if (local_29 == '\0') goto LAB_0001c1e0;
      __s = (char *)(DAT_0001c20c + 0x1c1de);
    }
    else {
      __s = (char *)(DAT_0001c208 + 0x1c1d0);
    }
  }
  else {
    __s = (char *)(DAT_0001c204 + 0x1c1ba);
  }
  puts(__s);
LAB_0001c1e0:
  if (**(int **)(DAT_0001c210 + 0x1c1e8) == local_14) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_14);
}



// ===========================================================
// Function: burn_cmd_erase_sector at 0001c214
// ===========================================================

void burn_cmd_erase_sector(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char *__s;
  undefined1 auStack_24 [7];
  char local_1d;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  local_14 = **(int **)(DAT_0001c2b0 + 0x1c222);
  puts((char *)(DAT_0001c2b4 + 0x1c22c));
  *(undefined4 *)(DAT_0001c2b8 + 0x1c238) = 0x11;
  *(char *)(DAT_0001c2bc + 0x1c242) = *(char *)(DAT_0001c2bc + 0x1c242) + '\x01';
  local_1d = '!';
  local_1c = param_1;
  local_18 = param_2;
  iVar1 = send_packet(&local_1d,9,0x65);
  if (iVar1 == 0) {
    puts((char *)(DAT_0001c2c4 + 0x1c266));
    iVar1 = recv_reply(&local_1d,1,auStack_24);
    if (iVar1 == 0) {
      if (local_1d != '\0') {
        puts((char *)(DAT_0001c2cc + 0x1c2a4));
      }
      goto LAB_0001c280;
    }
    __s = (char *)(DAT_0001c2c8 + 0x1c27e);
  }
  else {
    __s = (char *)(DAT_0001c2c0 + 0x1c260);
  }
  puts(__s);
LAB_0001c280:
  if (**(int **)(DAT_0001c2d0 + 0x1c288) == local_14) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_14);
}



// ===========================================================
// Function: burn_flash at 0001c2d4
// ===========================================================

void burn_flash(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint *puVar6;
  undefined4 local_34;
  undefined1 auStack_30 [7];
  char local_29;
  uint local_28;
  int local_24;
  undefined4 local_20;
  int local_18;
  
  puVar5 = (undefined4 *)(DAT_0001c414 + 0x1c2e2);
  *puVar5 = 0xc;
  local_18 = **(int **)(DAT_0001c418 + 0x1c2e8);
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_29 = '\0';
  puts((char *)(DAT_0001c41c + 0x1c2fe));
  iVar2 = recv_reply(&local_28,6,auStack_30);
  if (iVar2 == 0) {
    uVar1 = local_28 >> 0x10;
    printf((char *)(DAT_0001c424 + 0x1c32c),local_28 & 0xffff,local_24 << 0x10 | uVar1);
    if ((int)(uVar1 << 0x10) < 0) {
      puts((char *)(DAT_0001c42c + 0x1c344));
      *puVar5 = 0xd;
      puVar6 = (uint *)(DAT_0001c430 + 0x1c354);
      piVar4 = (int *)(DAT_0001c434 + 0x1c35c);
      printf((char *)(DAT_0001c438 + 0x1c364),DAT_0001c43c + 0x1c366,*puVar6,*piVar4,0x8000);
      local_20 = 0x8000;
      *(char *)(DAT_0001c440 + 0x1c372) = *(char *)(DAT_0001c440 + 0x1c372) + '\x01';
      local_28 = *puVar6;
      local_24 = *piVar4;
      iVar2 = send_packet(&local_28,0xc,0x61);
      if (iVar2 != 0) {
        printf((char *)(DAT_0001c444 + 0x1c392),DAT_0001c448 + 0x1c394);
        goto LAB_0001c396;
      }
      iVar2 = recv_reply(&local_29,1,auStack_30);
      if (iVar2 != 0) {
        pcVar3 = (char *)(DAT_0001c44c + 0x1c3c4);
        goto LAB_0001c312;
      }
      if (local_29 != '\0') {
        printf((char *)(DAT_0001c450 + 0x1c3d2),DAT_0001c454 + 0x1c3d4);
        goto LAB_0001c396;
      }
      iVar2 = burn_data(param_1);
      if (iVar2 == 0) {
        local_34 = 0xbe57ec1c;
        iVar2 = burn_cmd_burn_data(*puVar6,&local_34,4);
        if (iVar2 == 0) {
          iVar2 = sys_cmd_boot_cmd();
          if (iVar2 == 0) goto LAB_0001c396;
          pcVar3 = (char *)(DAT_0001c45c + 0x1c40e);
        }
        else {
          pcVar3 = (char *)(DAT_0001c458 + 0x1c402);
        }
      }
      else {
        pcVar3 = (char *)(DAT_0001c464 + 0x1c3e6);
      }
    }
    else {
      pcVar3 = (char *)(DAT_0001c428 + 0x1c338);
    }
    puts(pcVar3);
  }
  else {
    pcVar3 = (char *)(DAT_0001c420 + 0x1c314);
LAB_0001c312:
    puts(pcVar3);
  }
LAB_0001c396:
  if (**(int **)(DAT_0001c460 + 0x1c39e) == local_18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_18);
}



// ===========================================================
// Function: sys_cmd_boot_cmd at 0001c468
// ===========================================================

void sys_cmd_boot_cmd(void)

{
  int iVar1;
  char *__format;
  undefined1 auStack_14 [7];
  char local_d;
  int local_c;
  
  *(undefined4 *)(DAT_0001c4f4 + 0x1c476) = 8;
  *(char *)(DAT_0001c4f8 + 0x1c47c) = *(char *)(DAT_0001c4f8 + 0x1c47c) + '\x01';
  local_c = **(int **)(DAT_0001c4fc + 0x1c488);
  local_d = -0xf;
  iVar1 = send_packet(&local_d,1,0);
  if (iVar1 == 0) {
    iVar1 = recv_reply(&local_d,1,auStack_14);
    if (iVar1 == 0) {
      if (local_d != '\0') {
        printf((char *)(DAT_0001c50c + 0x1c4e6),DAT_0001c510 + 0x1c4e8);
      }
      goto LAB_0001c4c0;
    }
    __format = (char *)(DAT_0001c508 + 0x1c4ba);
  }
  else {
    __format = (char *)(DAT_0001c500 + 0x1c4a4);
  }
  printf(__format,DAT_0001c504 + 0x1c4be);
LAB_0001c4c0:
  if (**(int **)(DAT_0001c514 + 0x1c4c8) == local_c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_c);
}



// ===========================================================
// Function: uart_run_programmer at 0001c518
// ===========================================================

undefined4 uart_run_programmer(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  char *__s;
  char *pcVar3;
  int iVar4;
  char *__format;
  
  iVar4 = 0;
  pcVar1 = (char *)(DAT_0001c578 + 0x1c52e);
  pcVar3 = (char *)(DAT_0001c574 + 0x1c530);
  __format = (char *)(DAT_0001c57c + 0x1c532);
  while ((iVar2 = prepare_code_msg(param_1,param_2), __s = pcVar3, iVar2 != 0 ||
         (iVar2 = run_programmer(param_1), __s = pcVar1, iVar2 != 0))) {
    puts(__s);
    if (iVar4 == -1) {
      puts((char *)(DAT_0001c580 + 0x1c566));
      return 0;
    }
    printf(__format,iVar4);
    iVar4 = iVar4 + -1;
  }
  return 1;
}



// ===========================================================
// Function: uart_burn_boot at 0001c584
// ===========================================================

undefined4 uart_burn_boot(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  char *__s;
  char *pcVar2;
  int iVar3;
  char *__s_00;
  char *__format;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  
  iVar6 = 0;
  pcVar1 = (char *)(DAT_0001c5f4 + 0x1c598);
  pcVar5 = (char *)(DAT_0001c5f0 + 0x1c59a);
  __s = (char *)(DAT_0001c5f8 + 0x1c5a0);
  pcVar2 = (char *)(DAT_0001c5fc + 0x1c5a8);
  __format = (char *)(DAT_0001c600 + 0x1c5aa);
  while ((iVar3 = prepare_burn_data_msg(param_1,param_2), __s_00 = pcVar5, iVar3 != 0 ||
         (iVar3 = burn_flash(param_1), __s_00 = pcVar1, iVar3 != 0))) {
    puts(__s_00);
    if (iVar6 == -1) {
      uVar4 = 0;
      __s = pcVar2;
LAB_0001c5e2:
      puts(__s);
      return uVar4;
    }
    printf(__format,iVar6);
    iVar6 = iVar6 + -1;
  }
  uVar4 = 1;
  goto LAB_0001c5e2;
}



// ===========================================================
// Function: open_port at 0001c604
// ===========================================================

void open_port(undefined4 param_1,speed_t param_2)

{
  int __fd;
  tcflag_t local_38;
  tcflag_t tStack_34;
  uint local_30;
  tcflag_t tStack_2c;
  undefined4 local_28;
  tcflag_t tStack_24;
  uint uStack_20;
  tcflag_t tStack_1c;
  cc_t local_18 [4];
  int local_14;
  
  local_14 = **(int **)(DAT_0001c6b0 + 0x1c610);
  __fd = __open_2(param_1,2);
  if (__fd != -1) {
    tStack_34 = *(tcflag_t *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    local_30 = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    tStack_2c = *(tcflag_t *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    local_38 = 0;
    local_28._0_1_ = '\0';
    local_28._1_1_ = '\0';
    local_28._2_1_ = '\0';
    local_28._3_1_ = '\0';
    local_18[0] = '\0';
    local_18[1] = '\0';
    local_18[2] = '\0';
    local_18[3] = '\0';
    tStack_24 = tStack_34;
    uStack_20 = local_30;
    tStack_1c = tStack_2c;
    tcflush(__fd,2);
    tcgetattr(__fd,(termios *)&local_38);
    cfmakeraw((termios *)&local_38);
    local_30 = local_30 & 0x7fffffff;
    tcsetattr(__fd,0,(termios *)&local_38);
    tcflush(__fd,2);
    tcsetattr(__fd,0,(termios *)&local_38);
    tcflush(__fd,2);
    tcflush(__fd,2);
    cfsetospeed((termios *)&local_38,param_2);
    cfsetispeed((termios *)&local_38,param_2);
    tcsetattr(__fd,0,(termios *)&local_38);
  }
  if (**(int **)(DAT_0001c6b4 + 0x1c6a0) != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}



// ===========================================================
// Function: uart_init at 0001c6b8
// ===========================================================

void uart_init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_14;
  undefined2 local_10;
  int local_c;
  
  local_c = **(int **)(DAT_0001c738 + 0x1c6c6);
  iVar1 = open_port(DAT_0001c73c + 0x1c6d0,0x1007);
  **(int **)(DAT_0001c740 + 0x1c6dc) = iVar1;
  if (iVar1 < 0) {
    puts((char *)(DAT_0001c744 + 0x1c718));
  }
  else {
    local_10 = 0;
    local_14 = 0;
    puts((char *)(DAT_0001c748 + 0x1c6ee));
    setMcuRstGpio_Uart();
    uVar2 = uart_upgrade();
    printf((char *)(DAT_0001c74c + 0x1c706),uVar2,1,&local_14);
    puts((char *)(DAT_0001c750 + 0x1c70e));
  }
  if (**(int **)(DAT_0001c754 + 0x1c726) != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_c);
  }
  return;
}



// ===========================================================
// Function: close_uart at 0001c758
// ===========================================================

void close_uart(void)

{
  __ThumbV7PILongThunk_close(**(int **)(DAT_0001c764 + 0x1c75e));
  return;
}



// ===========================================================
// Function: __aeabi_memcpy8 at 0001c768
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * __aeabi_memcpy8(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_0001e494)(__dest);
  return pvVar1;
}



// ===========================================================
// Function: __aeabi_memset8 at 0001c76c
// ===========================================================

void __aeabi_memset8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)PTR_memset_0001e498)(param_1,param_3,param_2);
  return;
}



// ===========================================================
// Function: __aeabi_memclr8 at 0001c77c
// ===========================================================

void __aeabi_memclr8(undefined4 param_1,undefined4 param_2)

{
  (*(code *)PTR_memset_0001e498)(param_1,0,param_2);
  return;
}



// ===========================================================
// Function: __ThumbV7PILongThunk___cxa_finalize at 0001c788
// ===========================================================

void __ThumbV7PILongThunk___cxa_finalize(void)

{
  __cxa_finalize();
  return;
}



// ===========================================================
// Function: __ThumbV7PILongThunk_printf at 0001c794
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __ThumbV7PILongThunk_printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



// ===========================================================
// Function: __ThumbV7PILongThunk_pthread_mutex_destroy at 0001c7a0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __ThumbV7PILongThunk_pthread_mutex_destroy(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_destroy(__mutex);
  return iVar1;
}



// ===========================================================
// Function: __ThumbV7PILongThunk_puts at 0001c7ac
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __ThumbV7PILongThunk_puts(char *__s)

{
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



// ===========================================================
// Function: __ThumbV7PILongThunk_pb_field_iter_begin_extension at 0001c7b8
// ===========================================================

void __ThumbV7PILongThunk_pb_field_iter_begin_extension(void)

{
  pb_field_iter_begin_extension();
  return;
}



// ===========================================================
// Function: __ThumbV7PILongThunk_pb_read at 0001c7c4
// ===========================================================

void __ThumbV7PILongThunk_pb_read(void)

{
  pb_read();
  return;
}



// ===========================================================
// Function: __ThumbV7PILongThunk_pb_skip_field at 0001c7d0
// ===========================================================

void __ThumbV7PILongThunk_pb_skip_field(void)

{
  pb_skip_field();
  return;
}



// ===========================================================
// Function: __ThumbV7PILongThunk_pb_encode at 0001c7dc
// ===========================================================

void __ThumbV7PILongThunk_pb_encode(void)

{
  pb_encode();
  return;
}



// ===========================================================
// Function: __ThumbV7PILongThunk_pb_encode_submessage at 0001c7e8
// ===========================================================

void __ThumbV7PILongThunk_pb_encode_submessage(void)

{
  pb_encode_submessage();
  return;
}



// ===========================================================
// Function: __ThumbV7PILongThunk_pb_encode_varint at 0001c7f4
// ===========================================================

void __ThumbV7PILongThunk_pb_encode_varint(void)

{
  pb_encode_varint();
  return;
}



// ===========================================================
// Function: __ThumbV7PILongThunk_pb_write at 0001c800
// ===========================================================

void __ThumbV7PILongThunk_pb_write(void)

{
  pb_write();
  return;
}



// ===========================================================
// Function: __ThumbV7PILongThunk_pb_encode_string at 0001c80c
// ===========================================================

void __ThumbV7PILongThunk_pb_encode_string(void)

{
  pb_encode_string();
  return;
}



// ===========================================================
// Function: __ThumbV7PILongThunk_send_data at 0001c818
// ===========================================================

void __ThumbV7PILongThunk_send_data(void)

{
  send_data();
  return;
}



// ===========================================================
// Function: __ThumbV7PILongThunk_close at 0001c824
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __ThumbV7PILongThunk_close(int __fd)

{
  int iVar1;
  
  iVar1 = close(__fd);
  return iVar1;
}



// ===========================================================
// Function: __cxa_finalize at 0001c850
// ===========================================================

void __cxa_finalize(void)

{
  (*(code *)PTR___cxa_finalize_0001e27c)();
  return;
}



// ===========================================================
// Function: findDownloadBinByName at 0001c860
// ===========================================================

void findDownloadBinByName(void)

{
  (*(code *)PTR_findDownloadBinByName_0001e280)();
  return;
}



// ===========================================================
// Function: access at 0001c870
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int access(char *__name,int __type)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_access_0001e284)(__name);
  return iVar1;
}



// ===========================================================
// Function: printf at 0001c880
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_0001e288)(__format);
  return iVar1;
}



// ===========================================================
// Function: __vsnprintf_chk at 0001c890
// ===========================================================

void __vsnprintf_chk(void)

{
  (*(code *)PTR___vsnprintf_chk_0001e28c)();
  return;
}



// ===========================================================
// Function: __stack_chk_fail at 0001c8a0
// ===========================================================

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_0001e290)();
  return;
}



// ===========================================================
// Function: findDownloadBinByHeaderAndTail at 0001c8b0
// ===========================================================

void findDownloadBinByHeaderAndTail(void)

{
  (*(code *)PTR_findDownloadBinByHeaderAndTail_0001e294)();
  return;
}



// ===========================================================
// Function: opendir at 0001c8c0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DIR * opendir(char *__name)

{
  DIR *pDVar1;
  
  pDVar1 = (DIR *)(*(code *)PTR_opendir_0001e298)(__name);
  return pDVar1;
}



// ===========================================================
// Function: readdir at 0001c8d0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

dirent * readdir(DIR *__dirp)

{
  dirent *pdVar1;
  
  pdVar1 = (dirent *)(*(code *)PTR_readdir_0001e29c)(__dirp);
  return pdVar1;
}



// ===========================================================
// Function: strlen at 0001c8e0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_0001e2a0)(__s);
  return sVar1;
}



// ===========================================================
// Function: strncmp at 0001c8f0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strncmp_0001e2a4)(__s1);
  return iVar1;
}



// ===========================================================
// Function: closedir at 0001c900
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int closedir(DIR *__dirp)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_closedir_0001e2a8)(__dirp);
  return iVar1;
}



// ===========================================================
// Function: direntPathListInit at 0001c910
// ===========================================================

void direntPathListInit(void)

{
  (*(code *)PTR_direntPathListInit_0001e2ac)();
  return;
}



// ===========================================================
// Function: FindDownloadBin at 0001c920
// ===========================================================

void FindDownloadBin(void)

{
  (*(code *)PTR_FindDownloadBin_0001e2b0)();
  return;
}



// ===========================================================
// Function: puts at 0001c930
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_puts_0001e2b4)(__s);
  return iVar1;
}



// ===========================================================
// Function: dlImg at 0001c940
// ===========================================================

void dlImg(void)

{
  (*(code *)PTR_dlImg_0001e2b8)();
  return;
}



// ===========================================================
// Function: get_res_size at 0001c950
// ===========================================================

void get_res_size(void)

{
  (*(code *)PTR_get_res_size_0001e2bc)();
  return;
}



// ===========================================================
// Function: send_dl_request at 0001c960
// ===========================================================

void send_dl_request(void)

{
  (*(code *)PTR_send_dl_request_0001e2c0)();
  return;
}



// ===========================================================
// Function: update_res_file at 0001c970
// ===========================================================

void update_res_file(void)

{
  (*(code *)PTR_update_res_file_0001e2c4)();
  return;
}



// ===========================================================
// Function: verity_res_file at 0001c980
// ===========================================================

void verity_res_file(void)

{
  (*(code *)PTR_verity_res_file_0001e2c8)();
  return;
}



// ===========================================================
// Function: get_prj_number at 0001c990
// ===========================================================

void get_prj_number(void)

{
  (*(code *)PTR_get_prj_number_0001e2cc)();
  return;
}



// ===========================================================
// Function: property_get at 0001c9a0
// ===========================================================

void property_get(void)

{
  (*(code *)PTR_property_get_0001e2d0)();
  return;
}



// ===========================================================
// Function: atoi at 0001c9b0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int atoi(char *__nptr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_atoi_0001e2d4)(__nptr);
  return iVar1;
}



// ===========================================================
// Function: property_get_bool at 0001c9c0
// ===========================================================

void property_get_bool(void)

{
  (*(code *)PTR_property_get_bool_0001e2d8)();
  return;
}



// ===========================================================
// Function: setUpgradeGpio at 0001c9d0
// ===========================================================

void setUpgradeGpio(void)

{
  (*(code *)PTR_setUpgradeGpio_0001e2dc)();
  return;
}



// ===========================================================
// Function: setMcuRstGpio at 0001c9e0
// ===========================================================

void setMcuRstGpio(void)

{
  (*(code *)PTR_setMcuRstGpio_0001e2e0)();
  return;
}



// ===========================================================
// Function: deinitGpio at 0001c9f0
// ===========================================================

void deinitGpio(void)

{
  (*(code *)PTR_deinitGpio_0001e2e4)();
  return;
}



// ===========================================================
// Function: pthread_mutex_destroy at 0001ca00
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_destroy(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_destroy_0001e2e8)(__mutex);
  return iVar1;
}



// ===========================================================
// Function: get_mcu_ver at 0001ca10
// ===========================================================

void get_mcu_ver(void)

{
  (*(code *)PTR_get_mcu_ver_0001e2ec)();
  return;
}



// ===========================================================
// Function: send_dcc_spi_msg at 0001ca20
// ===========================================================

void send_dcc_spi_msg(void)

{
  (*(code *)PTR_send_dcc_spi_msg_0001e2f0)();
  return;
}



// ===========================================================
// Function: rcv_dcc_msg_response at 0001ca30
// ===========================================================

void rcv_dcc_msg_response(void)

{
  (*(code *)PTR_rcv_dcc_msg_response_0001e2f4)();
  return;
}



// ===========================================================
// Function: pb_istream_from_buffer at 0001ca40
// ===========================================================

void pb_istream_from_buffer(void)

{
  (*(code *)PTR_pb_istream_from_buffer_0001e2f8)();
  return;
}



// ===========================================================
// Function: pb_decode at 0001ca50
// ===========================================================

void pb_decode(void)

{
  (*(code *)PTR_pb_decode_0001e2fc)();
  return;
}



// ===========================================================
// Function: read_config_txt at 0001ca60
// ===========================================================

void read_config_txt(void)

{
  (*(code *)PTR_read_config_txt_0001e300)();
  return;
}



// ===========================================================
// Function: fopen at 0001ca70
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = (FILE *)(*(code *)PTR_fopen_0001e304)(__filename);
  return pFVar1;
}



// ===========================================================
// Function: fgets at 0001ca80
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_fgets_0001e308)(__s);
  return pcVar1;
}



// ===========================================================
// Function: sscanf at 0001ca90
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sscanf_0001e30c)(__s);
  return iVar1;
}



// ===========================================================
// Function: fclose at 0001caa0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fclose_0001e310)(__stream);
  return iVar1;
}



// ===========================================================
// Function: pthread_exit at 0001cab0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void pthread_exit(void *__retval)

{
  (*(code *)PTR_pthread_exit_0001e314)(__retval);
  return;
}



// ===========================================================
// Function: pthread_kill at 0001cac0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_kill(pthread_t __threadid,int __signo)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_kill_0001e318)(__threadid);
  return iVar1;
}



// ===========================================================
// Function: sigemptyset at 0001cad0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sigemptyset(sigset_t *__set)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sigemptyset_0001e31c)(__set);
  return iVar1;
}



// ===========================================================
// Function: sigaction at 0001cae0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sigaction(int __sig,sigaction *__act,sigaction *__oact)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sigaction_0001e320)(__sig);
  return iVar1;
}



// ===========================================================
// Function: signal at 0001caf0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__sighandler_t signal(int __sig,__sighandler_t __handler)

{
  __sighandler_t p_Var1;
  
  p_Var1 = (__sighandler_t)(*(code *)PTR_signal_0001e324)(__sig);
  return p_Var1;
}



// ===========================================================
// Function: alarm at 0001cb00
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint alarm(uint __seconds)

{
  uint uVar1;
  
  uVar1 = (*(code *)PTR_alarm_0001e328)(__seconds);
  return uVar1;
}



// ===========================================================
// Function: uart_init at 0001cb10
// ===========================================================

void uart_init(void)

{
  (*(code *)PTR_uart_init_0001e32c)();
  return;
}



// ===========================================================
// Function: download_programmer at 0001cb20
// ===========================================================

void download_programmer(void)

{
  (*(code *)PTR_download_programmer_0001e330)();
  return;
}



// ===========================================================
// Function: download_bootloader_bin at 0001cb30
// ===========================================================

void download_bootloader_bin(void)

{
  (*(code *)PTR_download_bootloader_bin_0001e334)();
  return;
}



// ===========================================================
// Function: close_uart at 0001cb40
// ===========================================================

void close_uart(void)

{
  (*(code *)PTR_close_uart_0001e338)();
  return;
}



// ===========================================================
// Function: recoveryDownload at 0001cb50
// ===========================================================

void recoveryDownload(void)

{
  (*(code *)PTR_recoveryDownload_0001e33c)();
  return;
}



// ===========================================================
// Function: pthread_create at 0001cb60
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_create_0001e340)(__newthread);
  return iVar1;
}



// ===========================================================
// Function: pthread_join at 0001cb70
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_join(pthread_t __th,void **__thread_return)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_join_0001e344)(__th);
  return iVar1;
}



// ===========================================================
// Function: handshake at 0001cb80
// ===========================================================

void handshake(void)

{
  (*(code *)PTR_handshake_0001e348)();
  return;
}



// ===========================================================
// Function: pthread_mutex_lock at 0001cb90
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_lock_0001e34c)(__mutex);
  return iVar1;
}



// ===========================================================
// Function: pthread_mutex_unlock at 0001cba0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_unlock_0001e350)(__mutex);
  return iVar1;
}



// ===========================================================
// Function: pthread_mutex_init at 0001cbb0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_init(pthread_mutex_t *__mutex,pthread_mutexattr_t *__mutexattr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_init_0001e354)(__mutex);
  return iVar1;
}



// ===========================================================
// Function: strcspn at 0001cbc0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strcspn(char *__s,char *__reject)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strcspn_0001e358)(__s);
  return sVar1;
}



// ===========================================================
// Function: __strncpy_chk at 0001cbd0
// ===========================================================

void __strncpy_chk(void)

{
  (*(code *)PTR___strncpy_chk_0001e35c)();
  return;
}



// ===========================================================
// Function: strcmp at 0001cbe0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_0001e360)(__s1);
  return iVar1;
}



// ===========================================================
// Function: memcmp at 0001cbf0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int memcmp(void *__s1,void *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_memcmp_0001e364)(__s1);
  return iVar1;
}



// ===========================================================
// Function: spi_transfer_msg at 0001cc00
// ===========================================================

void spi_transfer_msg(void)

{
  (*(code *)PTR_spi_transfer_msg_0001e368)();
  return;
}



// ===========================================================
// Function: __memcpy_chk at 0001cc10
// ===========================================================

void __memcpy_chk(void)

{
  (*(code *)PTR___memcpy_chk_0001e36c)();
  return;
}



// ===========================================================
// Function: send_spi_msg at 0001cc20
// ===========================================================

void send_spi_msg(void)

{
  (*(code *)PTR_send_spi_msg_0001e370)();
  return;
}



// ===========================================================
// Function: sleep at 0001cc30
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint sleep(uint __seconds)

{
  uint uVar1;
  
  uVar1 = (*(code *)PTR_sleep_0001e374)(__seconds);
  return uVar1;
}



// ===========================================================
// Function: rcv_msg_response at 0001cc40
// ===========================================================

void rcv_msg_response(void)

{
  (*(code *)PTR_rcv_msg_response_0001e378)();
  return;
}



// ===========================================================
// Function: crc32 at 0001cc50
// ===========================================================

void crc32(void)

{
  (*(code *)PTR_crc32_0001e37c)();
  return;
}



// ===========================================================
// Function: stat at 0001cc60
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int stat(char *__file,stat *__buf)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_stat_0001e380)(__file);
  return iVar1;
}



// ===========================================================
// Function: map_res_file at 0001cc70
// ===========================================================

void map_res_file(void)

{
  (*(code *)PTR_map_res_file_0001e384)();
  return;
}



// ===========================================================
// Function: __open_2 at 0001cc80
// ===========================================================

void __open_2(void)

{
  (*(code *)PTR___open_2_0001e388)();
  return;
}



// ===========================================================
// Function: mmap at 0001cc90
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * mmap(void *__addr,size_t __len,int __prot,int __flags,int __fd,__off_t __offset)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_mmap_0001e38c)(__addr);
  return pvVar1;
}



// ===========================================================
// Function: __errno at 0001cca0
// ===========================================================

void __errno(void)

{
  (*(code *)PTR___errno_0001e390)();
  return;
}



// ===========================================================
// Function: strerror at 0001ccb0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strerror(int __errnum)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strerror_0001e394)(__errnum);
  return pcVar1;
}



// ===========================================================
// Function: crc32_with_initvalue at 0001ccc0
// ===========================================================

void crc32_with_initvalue(void)

{
  (*(code *)PTR_crc32_with_initvalue_0001e398)();
  return;
}



// ===========================================================
// Function: __write_chk at 0001ccd0
// ===========================================================

void __write_chk(void)

{
  (*(code *)PTR___write_chk_0001e39c)();
  return;
}



// ===========================================================
// Function: uart_run_programmer at 0001cce0
// ===========================================================

void uart_run_programmer(void)

{
  (*(code *)PTR_uart_run_programmer_0001e3a0)();
  return;
}



// ===========================================================
// Function: uart_burn_boot at 0001ccf0
// ===========================================================

void uart_burn_boot(void)

{
  (*(code *)PTR_uart_burn_boot_0001e3a4)();
  return;
}



// ===========================================================
// Function: dcc_fd_open at 0001cd00
// ===========================================================

void dcc_fd_open(void)

{
  (*(code *)PTR_dcc_fd_open_0001e3a8)();
  return;
}



// ===========================================================
// Function: write at 0001cd10
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_write_0001e3ac)(__fd);
  return sVar1;
}



// ===========================================================
// Function: read at 0001cd20
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_read_0001e3b0)(__fd);
  return sVar1;
}



// ===========================================================
// Function: usleep at 0001cd30
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int usleep(__useconds_t __useconds)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_usleep_0001e3b4)(__useconds);
  return iVar1;
}



// ===========================================================
// Function: fd_open at 0001cd40
// ===========================================================

void fd_open(void)

{
  (*(code *)PTR_fd_open_0001e3b8)();
  return;
}



// ===========================================================
// Function: lseek at 0001cd50
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__off_t lseek(int __fd,__off_t __offset,int __whence)

{
  __off_t _Var1;
  
  _Var1 = (*(code *)PTR_lseek_0001e3bc)(__fd);
  return _Var1;
}



// ===========================================================
// Function: close at 0001cd60
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_close_0001e3c0)(__fd);
  return iVar1;
}



// ===========================================================
// Function: ioctl at 0001cd70
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ioctl_0001e3c4)(__fd);
  return iVar1;
}



// ===========================================================
// Function: setMcuRstGpio_Uart at 0001cd80
// ===========================================================

void setMcuRstGpio_Uart(void)

{
  (*(code *)PTR_setMcuRstGpio_Uart_0001e3c8)();
  return;
}



// ===========================================================
// Function: __strlen_chk at 0001cd90
// ===========================================================

void __strlen_chk(void)

{
  (*(code *)PTR___strlen_chk_0001e3cc)();
  return;
}



// ===========================================================
// Function: pb_field_iter_begin at 0001cda0
// ===========================================================

void pb_field_iter_begin(void)

{
  (*(code *)PTR_pb_field_iter_begin_0001e3d0)();
  return;
}



// ===========================================================
// Function: pb_field_iter_begin_extension at 0001cdb0
// ===========================================================

void pb_field_iter_begin_extension(void)

{
  (*(code *)PTR_pb_field_iter_begin_extension_0001e3d4)();
  return;
}



// ===========================================================
// Function: pb_field_iter_next at 0001cdc0
// ===========================================================

void pb_field_iter_next(void)

{
  (*(code *)PTR_pb_field_iter_next_0001e3d8)();
  return;
}



// ===========================================================
// Function: pb_field_iter_find at 0001cdd0
// ===========================================================

void pb_field_iter_find(void)

{
  (*(code *)PTR_pb_field_iter_find_0001e3dc)();
  return;
}



// ===========================================================
// Function: pb_field_iter_find_extension at 0001cde0
// ===========================================================

void pb_field_iter_find_extension(void)

{
  (*(code *)PTR_pb_field_iter_find_extension_0001e3e0)();
  return;
}



// ===========================================================
// Function: pb_field_iter_begin_const at 0001cdf0
// ===========================================================

void pb_field_iter_begin_const(void)

{
  (*(code *)PTR_pb_field_iter_begin_const_0001e3e4)();
  return;
}



// ===========================================================
// Function: pb_field_iter_begin_extension_const at 0001ce00
// ===========================================================

void pb_field_iter_begin_extension_const(void)

{
  (*(code *)PTR_pb_field_iter_begin_extension_const_0001e3e8)();
  return;
}



// ===========================================================
// Function: pb_read at 0001ce10
// ===========================================================

void pb_read(void)

{
  (*(code *)PTR_pb_read_0001e3ec)();
  return;
}



// ===========================================================
// Function: pb_decode_varint at 0001ce20
// ===========================================================

void pb_decode_varint(void)

{
  (*(code *)PTR_pb_decode_varint_0001e3f0)();
  return;
}



// ===========================================================
// Function: pb_skip_field at 0001ce30
// ===========================================================

void pb_skip_field(void)

{
  (*(code *)PTR_pb_skip_field_0001e3f4)();
  return;
}



// ===========================================================
// Function: pb_make_string_substream at 0001ce40
// ===========================================================

void pb_make_string_substream(void)

{
  (*(code *)PTR_pb_make_string_substream_0001e3f8)();
  return;
}



// ===========================================================
// Function: pb_close_string_substream at 0001ce50
// ===========================================================

void pb_close_string_substream(void)

{
  (*(code *)PTR_pb_close_string_substream_0001e3fc)();
  return;
}



// ===========================================================
// Function: pb_write at 0001ce60
// ===========================================================

void pb_write(void)

{
  (*(code *)PTR_pb_write_0001e400)();
  return;
}



// ===========================================================
// Function: pb_encode at 0001ce70
// ===========================================================

void pb_encode(void)

{
  (*(code *)PTR_pb_encode_0001e404)();
  return;
}



// ===========================================================
// Function: pb_encode_varint at 0001ce80
// ===========================================================

void pb_encode_varint(void)

{
  (*(code *)PTR_pb_encode_varint_0001e408)();
  return;
}



// ===========================================================
// Function: pb_encode_tag_for_field at 0001ce90
// ===========================================================

void pb_encode_tag_for_field(void)

{
  (*(code *)PTR_pb_encode_tag_for_field_0001e40c)();
  return;
}



// ===========================================================
// Function: pb_encode_submessage at 0001cea0
// ===========================================================

void pb_encode_submessage(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001cea8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_pb_encode_submessage_0001e410)();
  return;
}



// ===========================================================
// Function: pb_encode_string at 0001ceb0
// ===========================================================

void pb_encode_string(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001ceb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_pb_encode_string_0001e414)();
  return;
}



// ===========================================================
// Function: uart_crc32 at 0001cec0
// ===========================================================

void uart_crc32(void)

{
  (*(code *)PTR_uart_crc32_0001e418)();
  return;
}



// ===========================================================
// Function: recv_data at 0001ced0
// ===========================================================

void recv_data(void)

{
  (*(code *)PTR_recv_data_0001e41c)();
  return;
}



// ===========================================================
// Function: __read_chk at 0001cee0
// ===========================================================

void __read_chk(void)

{
  (*(code *)PTR___read_chk_0001e420)();
  return;
}



// ===========================================================
// Function: handle_sync_msg at 0001cef0
// ===========================================================

void handle_sync_msg(void)

{
  (*(code *)PTR_handle_sync_msg_0001e424)();
  return;
}



// ===========================================================
// Function: check_msg_hdr at 0001cf00
// ===========================================================

void check_msg_hdr(void)

{
  (*(code *)PTR_check_msg_hdr_0001e428)();
  return;
}



// ===========================================================
// Function: handle_data at 0001cf10
// ===========================================================

void handle_data(void)

{
  (*(code *)PTR_handle_data_0001e42c)();
  return;
}



// ===========================================================
// Function: parse_packet at 0001cf20
// ===========================================================

void parse_packet(void)

{
  (*(code *)PTR_parse_packet_0001e430)();
  return;
}



// ===========================================================
// Function: __memmove_chk at 0001cf30
// ===========================================================

void __memmove_chk(void)

{
  (*(code *)PTR___memmove_chk_0001e434)();
  return;
}



// ===========================================================
// Function: recv_reply at 0001cf40
// ===========================================================

void recv_reply(void)

{
  (*(code *)PTR_recv_reply_0001e438)();
  return;
}



// ===========================================================
// Function: send_data at 0001cf50
// ===========================================================

void send_data(void)

{
  (*(code *)PTR_send_data_0001e43c)();
  return;
}



// ===========================================================
// Function: send_sync_reply at 0001cf60
// ===========================================================

void send_sync_reply(void)

{
  (*(code *)PTR_send_sync_reply_0001e440)();
  return;
}



// ===========================================================
// Function: uart_upgrade at 0001cf70
// ===========================================================

void uart_upgrade(void)

{
  (*(code *)PTR_uart_upgrade_0001e444)();
  return;
}



// ===========================================================
// Function: construct_packet at 0001cf80
// ===========================================================

void construct_packet(void)

{
  (*(code *)PTR_construct_packet_0001e448)();
  return;
}



// ===========================================================
// Function: get_program_crc at 0001cf90
// ===========================================================

void get_program_crc(void)

{
  (*(code *)PTR_get_program_crc_0001e44c)();
  return;
}



// ===========================================================
// Function: prepare_code_msg at 0001cfa0
// ===========================================================

void prepare_code_msg(void)

{
  (*(code *)PTR_prepare_code_msg_0001e450)();
  return;
}



// ===========================================================
// Function: send_packet at 0001cfb0
// ===========================================================

void send_packet(void)

{
  (*(code *)PTR_send_packet_0001e454)();
  return;
}



// ===========================================================
// Function: run_programmer at 0001cfc0
// ===========================================================

void run_programmer(void)

{
  (*(code *)PTR_run_programmer_0001e458)();
  return;
}



// ===========================================================
// Function: get_flash_crc at 0001cfd0
// ===========================================================

void get_flash_crc(void)

{
  (*(code *)PTR_get_flash_crc_0001e45c)();
  return;
}



// ===========================================================
// Function: prepare_burn_data_msg at 0001cfe0
// ===========================================================

void prepare_burn_data_msg(void)

{
  (*(code *)PTR_prepare_burn_data_msg_0001e460)();
  return;
}



// ===========================================================
// Function: burn_cmd_burn_data at 0001cff0
// ===========================================================

void burn_cmd_burn_data(void)

{
  (*(code *)PTR_burn_cmd_burn_data_0001e464)();
  return;
}



// ===========================================================
// Function: add_burn_index at 0001d000
// ===========================================================

void add_burn_index(void)

{
  (*(code *)PTR_add_burn_index_0001e468)();
  return;
}



// ===========================================================
// Function: set_burn_status at 0001d010
// ===========================================================

void set_burn_status(void)

{
  (*(code *)PTR_set_burn_status_0001e46c)();
  return;
}



// ===========================================================
// Function: burn_data at 0001d020
// ===========================================================

void burn_data(void)

{
  (*(code *)PTR_burn_data_0001e470)();
  return;
}



// ===========================================================
// Function: burn_flash at 0001d030
// ===========================================================

void burn_flash(void)

{
  (*(code *)PTR_burn_flash_0001e474)();
  return;
}



// ===========================================================
// Function: open_port at 0001d040
// ===========================================================

void open_port(void)

{
  (*(code *)PTR_open_port_0001e478)();
  return;
}



// ===========================================================
// Function: tcflush at 0001d050
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int tcflush(int __fd,int __queue_selector)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_tcflush_0001e47c)(__fd);
  return iVar1;
}



// ===========================================================
// Function: tcgetattr at 0001d060
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int tcgetattr(int __fd,termios *__termios_p)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_tcgetattr_0001e480)(__fd);
  return iVar1;
}



// ===========================================================
// Function: cfmakeraw at 0001d070
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void cfmakeraw(termios *__termios_p)

{
  (*(code *)PTR_cfmakeraw_0001e484)(__termios_p);
  return;
}



// ===========================================================
// Function: tcsetattr at 0001d080
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int tcsetattr(int __fd,int __optional_actions,termios *__termios_p)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_tcsetattr_0001e488)(__fd);
  return iVar1;
}



// ===========================================================
// Function: cfsetospeed at 0001d090
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int cfsetospeed(termios *__termios_p,speed_t __speed)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_cfsetospeed_0001e48c)(__termios_p);
  return iVar1;
}



// ===========================================================
// Function: cfsetispeed at 0001d0a0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int cfsetispeed(termios *__termios_p,speed_t __speed)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_cfsetispeed_0001e490)(__termios_p);
  return iVar1;
}



// ===========================================================
// Function: memcpy at 0001d0b0
// ===========================================================

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_0001e494)(__dest);
  return pvVar1;
}



// ===========================================================
// Function: __cxa_finalize at 00023000
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: access at 00023004
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int access(char *__name,int __type)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: printf at 00023008
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __vsnprintf_chk at 0002300c
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __vsnprintf_chk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __stack_chk_fail at 00023010
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: opendir at 00023018
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DIR * opendir(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: readdir at 0002301c
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

dirent * readdir(DIR *__dirp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: strlen at 00023020
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: strncmp at 00023024
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: closedir at 00023028
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int closedir(DIR *__dirp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: puts at 0002302c
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: property_get at 00023030
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void property_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: atoi at 00023034
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int atoi(char *__nptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: property_get_bool at 00023038
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void property_get_bool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: pthread_mutex_destroy at 0002303c
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_destroy(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: fopen at 00023040
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: fgets at 00023044
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: sscanf at 00023048
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: fclose at 0002304c
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: pthread_exit at 00023050
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void pthread_exit(void *__retval)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: pthread_kill at 00023054
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_kill(pthread_t __threadid,int __signo)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: sigemptyset at 00023058
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sigemptyset(sigset_t *__set)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: sigaction at 0002305c
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sigaction(int __sig,sigaction *__act,sigaction *__oact)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: signal at 00023060
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__sighandler_t signal(int __sig,__sighandler_t __handler)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: alarm at 00023064
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint alarm(uint __seconds)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: pthread_create at 00023068
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: pthread_join at 0002306c
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_join(pthread_t __th,void **__thread_return)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: pthread_mutex_lock at 00023070
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: pthread_mutex_unlock at 00023074
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: pthread_mutex_init at 00023078
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_init(pthread_mutex_t *__mutex,pthread_mutexattr_t *__mutexattr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: strcspn at 0002307c
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strcspn(char *__s,char *__reject)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __strncpy_chk at 00023080
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __strncpy_chk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: strcmp at 00023084
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: memcmp at 00023088
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int memcmp(void *__s1,void *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __memcpy_chk at 0002308c
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_chk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: sleep at 00023090
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint sleep(uint __seconds)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: stat at 00023094
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int stat(char *__file,stat *__buf)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __open_2 at 00023098
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __open_2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: mmap at 0002309c
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * mmap(void *__addr,size_t __len,int __prot,int __flags,int __fd,__off_t __offset)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __errno at 000230a0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __errno(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: strerror at 000230a4
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strerror(int __errnum)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __write_chk at 000230a8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __write_chk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: write at 000230ac
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: read at 000230b0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: usleep at 000230b4
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int usleep(__useconds_t __useconds)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: lseek at 000230b8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__off_t lseek(int __fd,__off_t __offset,int __whence)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: close at 000230bc
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: ioctl at 000230c0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __strlen_chk at 000230c4
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __strlen_chk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __read_chk at 000230c8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __read_chk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __memmove_chk at 000230cc
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __memmove_chk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: tcflush at 000230d0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int tcflush(int __fd,int __queue_selector)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: tcgetattr at 000230d4
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int tcgetattr(int __fd,termios *__termios_p)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: cfmakeraw at 000230d8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void cfmakeraw(termios *__termios_p)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: tcsetattr at 000230dc
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int tcsetattr(int __fd,int __optional_actions,termios *__termios_p)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: cfsetospeed at 000230e0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int cfsetospeed(termios *__termios_p,speed_t __speed)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: cfsetispeed at 000230e4
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int cfsetispeed(termios *__termios_p,speed_t __speed)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: memcpy at 000230e8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: memset at 000230ec
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



