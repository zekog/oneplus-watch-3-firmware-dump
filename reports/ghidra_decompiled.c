// ===========================================================
// Function: sbl1_dload_entry at 0c282738
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sbl1_dload_entry(undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  undefined8 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  uVar1 = DAT_0c29bbb0 + 1;
  bVar2 = DAT_0c29bbb0 == 0;
  DAT_0c29bbb0 = uVar1;
  if (bVar2) {
    FUN_0c2622d0(&DAT_0c285fd8,&PTR_LAB_0c28e5e0);
  }
  if (1 < DAT_0c29bbb0) {
    FUN_0c2562b4("EDL: sbl1_dload_entry: dload_entry_count > 1");
    FUN_0c260df8();
  }
  FUN_0c261208(&DAT_0c285fd8,&DAT_0c29bb28);
  iVar4 = FUN_0c251fe0(*(undefined8 *)(DAT_0c285fd8 + 0x40),&PTR_LAB_0c29baf0);
  uVar3 = _UNK_0c2b2078;
  uVar6 = _DAT_0c2b2070;
  if (iVar4 == 0) {
    uVar6 = FUN_0c282940();
    FUN_0c282934(uVar6,0xfa,param_3 & 0xffff | 0x1000000);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  DAT_0c29bb00 = 0x10000;
  DAT_0c29bb20 = 0x60000000000000;
  PTR_LAB_0c29baf8 = (undefined *)&DAT_45e97000;
  PTR_LAB_0c29baf0 = (undefined *)&DAT_45e97000;
  uRam000000000c29bb18 = _UNK_0c2b2078;
  _DAT_0c29bb10 = _DAT_0c2b2070;
  iVar4 = FUN_0c251fe0(*(undefined8 *)(DAT_0c285fd8 + 0x40),&PTR_LAB_0c29baf0);
  if (iVar4 == 0) {
    uVar6 = FUN_0c282940();
    FUN_0c282934(uVar6,0x10c,param_3 & 0xffff | 0x1000000);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  DAT_0c29bb20 = 0x60000000000000;
  DAT_0c29bb00 = 0x1000000;
  DAT_0c29bb08 = 2;
  PTR_LAB_0c29baf8 = (undefined *)0x5c000000;
  PTR_LAB_0c29baf0 = (undefined *)0x5c000000;
  uRam000000000c29bb18 = uVar3;
  _DAT_0c29bb10 = uVar6;
  iVar4 = FUN_0c251fe0(*(undefined8 *)(DAT_0c285fd8 + 0x40),&PTR_LAB_0c29baf0);
  if (iVar4 != 0) {
    FUN_0c24eb48();
    FUN_0c2562b4("External heap deinit, Start");
    FUN_0c250478();
    iVar4 = thunk_FUN_0c25bec4();
    if (iVar4 != 0) {
      (*(code *)PTR_FUN_0c289e00)("sbl1_target.c",0x125,0x46000090);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    FUN_0c282950();
    FUN_0c2562b4("External heap init, Start");
    uVar6 = FUN_0c250478();
    uVar5 = FUN_0c250484();
    iVar4 = thunk_FUN_0c25be40(uVar6,uVar5,1);
    if (iVar4 != 0) {
      FUN_0c282934(&DAT_0c289000,FUN_0c2b2000,300,0x46000089);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    FUN_0c282950();
    FUN_0c2b50b8();
    (*(code *)0x45e35000)();
    return;
  }
  uVar6 = FUN_0c282940();
  FUN_0c282934(uVar6,0x11f,param_3 & 0xffff | 0x1000000);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ===========================================================
// Function: qusb_pmi_charger_detect_forced_edl at 0c2834c0
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qusb_pmi_charger_detect_forced_edl(void)

{
  bool bVar1;
  byte *pbVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  char local_1a4 [4];
  undefined8 local_1a0;
  undefined8 local_198;
  undefined1 auStack_190 [28];
  uint local_174;
  byte local_170;
  byte abStack_16e [310];
  long local_38;
  
  uVar10 = 0x61945374;
  local_38 = DAT_0c11c000;
  local_1a0 = CONCAT44(CONCAT22(CONCAT11(DAT_0c29c25f,DAT_0c29c25e),
                                CONCAT11(DAT_0c29c25d,DAT_0c29c25c)),
                       CONCAT22(CONCAT11(DAT_0c29c25b,DAT_0c29c25a),
                                CONCAT11(DAT_0c29c259,DAT_0c29c258)));
  local_198 = CONCAT44(CONCAT22(CONCAT11(DAT_0c29c267,DAT_0c29c266),
                                CONCAT11(DAT_0c29c265,DAT_0c29c264)),
                       CONCAT22(CONCAT11(DAT_0c29c263,DAT_0c29c262),
                                CONCAT11(DAT_0c29c261,DAT_0c29c260)));
  if (_DAT_0c125150 == 0x61945374) {
    FUN_0c2593a8(s_usb__ser_str_cookie_pid_0c29c143,0xc1250cc);
  }
  else {
    lVar6 = FUN_0c2bb4e8(2,1,&local_1a0);
    if (lVar6 == 0) {
LAB_0c2835e8:
      lVar6 = FUN_0c2bb4e8(1,1,&local_1a0);
      if (lVar6 == 0) {
        FUN_0c259314(s_emmc_parti_unavail_0c29c17d,0);
        lVar6 = FUN_0c2bb4e8(1,0,&local_1a0);
        if (lVar6 != 0) goto LAB_0c283620;
        pcVar8 = s_sdc_parti_unavail_0c29c190;
LAB_0c28364c:
        FUN_0c259314(pcVar8,0);
LAB_0c283654:
        local_174 = FUN_0c283378();
      }
      else {
LAB_0c283620:
        iVar4 = FUN_0c2bb78c(lVar6,auStack_190);
        if (iVar4 != 0) {
          pcVar8 = s_emmc_sdc_info_fail_0c29c1a2;
          goto LAB_0c28364c;
        }
        if (local_174 == 0) goto LAB_0c283654;
      }
      bVar1 = false;
    }
    else {
      iVar4 = FUN_0c2bb78c(lVar6,auStack_190);
      if (iVar4 != 0) {
        local_170 = 0;
        pcVar8 = s_ufs_info_fail_0c29c15b;
LAB_0c2835e4:
        FUN_0c259314(pcVar8,local_170);
        goto LAB_0c2835e8;
      }
      if (local_170 < 3) {
        pcVar8 = s_ufs_ser_strlen_<__2_0c29c169;
        goto LAB_0c2835e4;
      }
      uVar5 = local_170 + 0xfffe & 0xffff;
      if (uVar5 == 0) {
        local_174 = 0xffffffff;
      }
      else {
        uVar9 = 0xffffffff;
        pbVar2 = abStack_16e;
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
          uVar9 = *(uint *)(&DAT_0c29c268 + (ulong)(uVar9 & 0xff ^ (uint)*pbVar2) * 4) ^ uVar9 >> 8;
          pbVar2 = pbVar2 + 1;
        }
        if (uVar9 == 0xffffffff) goto LAB_0c2835e8;
        local_174 = ~uVar9;
      }
      bVar1 = true;
    }
    uVar5 = FUN_0c257bd8(0xc1250cc,0x80,&DAT_0c29c1b5,local_174);
    if (uVar5 < 0x80) {
      pcVar8 = s_usb__Serial_0c29c1da;
      if (bVar1) {
        pcVar8 = s_usb__UFS_Serial_0c29c1ca;
      }
      FUN_0c2593a8(pcVar8,0xc1250cc);
      _DAT_0c125150 = 0x61945374;
    }
    else {
      FUN_0c259314(s_ser_str_conv_fail_0c29c1b8,0);
    }
  }
  iVar4 = FUN_0c283034();
  if (iVar4 != 1) {
    local_1a4[0] = '\0';
    local_1a0 = CONCAT44(local_1a0._4_4_,7);
    iVar4 = FUN_0c26310c(0,auStack_190);
    if (iVar4 == 0) {
      iVar4 = -99;
      do {
        uVar5 = FUN_0c2bff14(local_1a4);
        if (uVar5 != 0) {
          pcVar8 = s_fedl__vbus_det_err_0c29c1fd;
          uVar10 = uVar5;
LAB_0c283814:
          FUN_0c259314(pcVar8,0);
          uVar7 = 0xdd;
          uVar5 = uVar10;
          goto LAB_0c283828;
        }
        if (local_1a4[0] == '\0') {
          FUN_0c259314(s_fedl__vbus_low_0c29c210,0);
          uVar7 = 0xdf;
          uVar5 = (uint)(local_1a4[0] == '\0');
          goto LAB_0c283828;
        }
        uVar5 = FUN_0c2bff64(&local_1a0);
        if (uVar5 != 0) {
          pcVar8 = s_fedl__chgr_type_det_err_0c29c21f;
          uVar10 = uVar5;
          goto LAB_0c283814;
        }
        if ((int)local_1a0 != 7) goto LAB_0c28373c;
        FUN_0c283074(5);
        iVar4 = iVar4 + 1;
      } while (iVar4 != 0);
LAB_0c28373c:
      uVar7 = FUN_0c283414((int)local_1a0);
      uVar7 = FUN_0c2593a8(s_usb__chgr_0c29c237,uVar7);
      iVar4 = (int)local_1a0;
      if ((int)local_1a0 == 7) {
        FUN_0c259314(s_fedl__chgr_det_timeout_0c29c241,0);
        uVar7 = 0xdd;
        uVar5 = 0;
LAB_0c283828:
        uVar7 = FUN_0c2593c0(uVar7,0,uVar5);
        goto LAB_0c28382c;
      }
    }
    else {
      uVar7 = FUN_0c259314(s_fedl__pmi_not_detected_0c29c1e6,0);
LAB_0c28382c:
      iVar4 = (int)local_1a0;
    }
    if ((iVar4 != 2) && ((uVar7 = 0, iVar4 != 0 || (DAT_0c29c038 == '\0')))) goto LAB_0c283898;
    FUN_0c2839fc(uVar7);
    FUN_0c254c00();
    FUN_0c283338(1);
    cVar3 = FUN_0c282fdc();
    if (cVar3 == '\0') {
      FUN_0c254d04();
      FUN_0c2830e0(0);
      FUN_0c254c00();
      FUN_0c283150();
      thunk_FUN_0c252374(10);
      cVar3 = FUN_0c283158();
      if (cVar3 != '\0') {
        if (iVar4 == 2) {
          FUN_0c283290(200);
          FUN_0c259314(s_usb_dp_toggled_for_cdp_0c29c0ee,200);
        }
        else {
          cVar3 = FUN_0c2831cc();
          if (cVar3 != '\0') {
            FUN_0c259314(s_enter_forced_EDL_0c29c105,0);
            thunk_FUN_0c252374(5000);
            uVar7 = 1;
            goto LAB_0c283898;
          }
        }
      }
    }
    else {
      FUN_0c2839e8();
      for (; iVar4 != 10; iVar4 = iVar4 + 1) {
        FUN_0c2839dc();
        FUN_0c283074(uVar10);
      }
      FUN_0c254d04();
      FUN_0c254cc8(1);
    }
  }
  uVar7 = 0;
LAB_0c283898:
  if (DAT_0c11c000 != local_38) {
                    /* WARNING: Subroutine does not return */
    FUN_0c119000(uVar7);
  }
  return;
}



// ===========================================================
// Function: sbl1_enter_forced_edl_target at 0c260df8
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sbl1_enter_forced_edl_target(void)

{
  FUN_0c256494();
  _DAT_003d3000 = _DAT_003d3000 & 0xfffffff0 | 1;
  FUN_0c25df84(1);
  return;
}



// ===========================================================
// Function: boot_delay_microseconds at 0c283024
// ===========================================================

void boot_delay_microseconds(uint param_1)

{
  if (DAT_0c287ea0 != (int *)0x0) {
    do {
    } while ((uint)(*DAT_0c287ea0 - *DAT_0c287ea0) <
             (uint)(((ulong)DAT_0c287e98 * (ulong)param_1) / 1000000));
  }
  return;
}



