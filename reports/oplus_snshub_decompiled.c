// ===========================================================
// Function: __cfi_check at 00101000
// ===========================================================

void __cfi_check(long param_1,code *param_2,undefined8 param_3)

{
  code *pcVar1;
  
  if (param_1 < -0x3557318fb8d07b71) {
    if (param_1 < -0x57be845bca9148ef) {
      if (param_1 == -0x66d421a09845f9f8) {
        pcVar1 = oplus_snshub_show_disable_uevent_cfi_jt;
      }
      else if (param_1 == -0x600447d24276fedf) {
        pcVar1 = oplus_snshub_wakeup_data_uevent_cfi_jt;
      }
      else {
        if (param_1 != -0x5bbe2f46531c8194) goto LAB_00101280;
        pcVar1 = oplus_snshub_set_disable_uevent_cfi_jt;
      }
    }
    else {
      if (param_1 < -0x550b9e52359ac614) {
        if (param_1 == -0x57be845bca9148ef) {
          if (((ulong)(param_2 + -0x102600) >> 2 | (long)param_2 << 0x3e) < 3) {
            return;
          }
          goto LAB_00101280;
        }
        if (param_1 != -0x57b8686b7c98a638) goto LAB_00101280;
        pcVar1 = oplus_snshub_reset_notifier_unregister_cfi_jt;
        goto LAB_00101254;
      }
      if (param_1 == -0x550b9e52359ac614) {
        pcVar1 = mcu_states_dump_cfi_jt;
      }
      else {
        if (param_1 != -0x3987c0e26ee29729) goto LAB_00101280;
        pcVar1 = mcu_dump_int_irq_fn_cfi_jt;
      }
    }
  }
  else if (param_1 < 0x6e9810b85546f85e) {
    if (0x1e3d0ffe3d0499e8 < param_1) {
      if (param_1 == 0x1e3d0ffe3d0499e9) {
        pcVar1 = oplus_snshub_store_disable_uevent_cfi_jt;
      }
      else {
        if (param_1 != 0x5b83a3fd302a5421) goto LAB_00101280;
        pcVar1 = oplus_snshub_reset_cfi_jt;
      }
      if (((ulong)((long)param_2 - (long)pcVar1) >> 2 | (long)param_2 << 0x3e) < 4) {
        return;
      }
      goto LAB_00101280;
    }
    if (param_1 == -0x3557318fb8d07b71) {
      pcVar1 = oplus_snshub_probe_cfi_jt;
LAB_00101254:
      if (((ulong)((long)param_2 - (long)pcVar1) >> 2 | (long)param_2 << 0x3e) < 2) {
        return;
      }
      goto LAB_00101280;
    }
    if (param_1 != 0x2b3a43e29242445) goto LAB_00101280;
    pcVar1 = init_module_cfi_jt;
  }
  else if (param_1 < 0x7a686d6e7b0c291a) {
    if (param_1 == 0x6e9810b85546f85e) {
      pcVar1 = oplus_snshub_get_disable_uevent_cfi_jt;
    }
    else {
      if (param_1 != 0x741b966c574d47b1) goto LAB_00101280;
      pcVar1 = is_mcureseting_cfi_jt;
    }
  }
  else {
    if (param_1 != 0x7a686d6e7b0c291a) {
      if (param_1 != 0x7e04a0fb7ad8bcd5) goto LAB_00101280;
      pcVar1 = wait_mcureseting_cfi_jt;
      goto LAB_00101254;
    }
    pcVar1 = oplus_snshub_states_uevent_cfi_jt;
  }
  if (param_2 == pcVar1) {
    return;
  }
LAB_00101280:
  __cfi_check_fail(param_3);
  return;
}



// ===========================================================
// Function: __cfi_check_fail at 001012e8
// ===========================================================

void __cfi_check_fail(undefined1 *param_1,undefined8 param_2)

{
  code *pcVar1;
  
  if (param_1 != (undefined1 *)0x0) {
    switch(*param_1) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      __ubsan_handle_cfi_check_fail_abort(param_1,param_2,0);
      break;
    default:
      return;
    }
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5502,0x101334);
  (*pcVar1)();
}



// ===========================================================
// Function: wait_mcureseting at 00101334
// ===========================================================

void wait_mcureseting(void)

{
  int iVar1;
  
  if (g_snshub == 0) {
    _printk(&DAT_001005b9);
  }
  else {
    iVar1 = *(int *)(g_snshub + 0x270);
    while (iVar1 != 0) {
      msleep(0x14);
      iVar1 = *(int *)(g_snshub + 0x270);
    }
  }
  return;
}



// ===========================================================
// Function: oplus_snshub_wakeup_data_uevent at 0010138c
// ===========================================================

void oplus_snshub_wakeup_data_uevent(long param_1)

{
  long lVar1;
  char *local_48;
  long lStack_40;
  char *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x648);
  if (param_1 == 0) {
    _printk(&DAT_0010087e);
  }
  else {
    _printk(&DAT_001005f4);
    local_48 = "MCU_UEVENT";
    local_38 = "WAKEUP_UEVENT=update";
    uStack_30 = 0;
    lStack_40 = param_1;
    if (g_snshub == (undefined8 *)0x0) {
      _printk(&DAT_001005b9);
    }
    else {
      _printk(&DAT_001007fd,param_1,"WAKEUP_UEVENT=update");
      kobject_uevent_env(*g_snshub,2,&local_48);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x648) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// ===========================================================
// Function: oplus_snshub_states_uevent at 0010145c
// ===========================================================

void oplus_snshub_states_uevent(uint param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  char *local_48;
  long lStack_40;
  undefined *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x648);
  if ((int)param_1 < 4) {
    if (param_2 == 0) {
      _printk(&DAT_0010087e);
    }
    else if (g_snshub == (undefined8 *)0x0) {
      _printk(&DAT_001005b9);
    }
    else {
      if (param_1 == 2) {
        if (*(int *)(g_snshub + 0x26) != 0) {
          if (((oplus_snshub_states_uevent_print_cnt < 10) ||
              ((oplus_snshub_states_uevent_print_cnt & 0xffffff0f) == 0)) ||
             ((oplus_snshub_states_uevent_print_cnt & 0xff) == 0)) {
            _printk(&DAT_0010066e,"MCU_STATES=crash");
          }
          oplus_snshub_states_uevent_print_cnt = oplus_snshub_states_uevent_print_cnt + 1;
          goto LAB_001014d0;
        }
      }
      else {
        oplus_snshub_states_uevent_print_cnt = 0;
        if (3 < param_1) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101528);
          (*pcVar2)();
        }
      }
      oplus_snshub_states_uevent_print_cnt = 0;
      local_38 = (&PTR_s_MCU_STATES_first_00100b28)[param_1];
      local_48 = "MCU_UEVENT";
      uStack_30 = 0;
      lStack_40 = param_2;
      _printk(&DAT_001007fd);
      kobject_uevent_env(*g_snshub,2,&local_48);
    }
  }
  else {
    _printk(&DAT_00100859,(ulong)param_1,4);
  }
LAB_001014d0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x648) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// ===========================================================
// Function: oplus_snshub_set_disable_uevent at 001015ac
// ===========================================================

void oplus_snshub_set_disable_uevent(int param_1)

{
  mutex_lock(g_snshub + 0x138);
  *(uint *)(g_snshub + 0x130) = (uint)(param_1 != 0);
  _printk(&DAT_0010041d);
  mutex_unlock(g_snshub + 0x138);
  return;
}



// ===========================================================
// Function: oplus_snshub_reset_notifier_unregister at 00101608
// ===========================================================

undefined8 oplus_snshub_reset_notifier_unregister(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = g_snshub;
  if (param_1 != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  }
  if (lVar1 == 0) {
    _printk(&DAT_00100577);
    uVar2 = 0;
  }
  else {
    uVar2 = blocking_notifier_chain_unregister(lVar1 + 0x40);
  }
  return uVar2;
}



// ===========================================================
// Function: oplus_snshub_reset_notifier_register at 00101660
// ===========================================================

undefined8 oplus_snshub_reset_notifier_register(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = g_snshub;
  if (param_1 != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  }
  if (lVar1 == 0) {
    _printk(&DAT_00100577);
    uVar2 = 0;
  }
  else {
    uVar2 = blocking_notifier_chain_register(lVar1 + 0x40);
  }
  return uVar2;
}



// ===========================================================
// Function: oplus_snshub_reset at 001016b8
// ===========================================================

void oplus_snshub_reset(long param_1)

{
  __oplus_snshub_reset(*(undefined8 *)(*(long *)(param_1 + 0x60) + 0x98),param_1);
  return;
}



// ===========================================================
// Function: __oplus_snshub_reset at 001016e0
// ===========================================================

void __oplus_snshub_reset(long param_1,undefined8 param_2)

{
  long lVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  uint *puVar6;
  
  lVar1 = param_1 + 0x10;
  iVar4 = mutex_trylock(lVar1);
  if (iVar4 == 0) {
    mutex_lock(lVar1);
  }
  else {
    *(undefined4 *)(g_snshub + 0x270) = 1;
    blocking_notifier_call_chain(param_1 + 0x40,0,param_2);
    puVar6 = *(uint **)(param_1 + 8);
    if (puVar6[8] < 0x200) {
      uVar3 = puVar6[9];
      uVar5 = gpio_to_desc();
      gpiod_direction_output_raw(uVar5,(char)uVar3);
      puVar6 = *(uint **)(param_1 + 8);
    }
    if (*puVar6 < 0x200) {
      uVar3 = puVar6[1];
      uVar5 = gpio_to_desc();
      if ((char)uVar3 == '\x01') {
        gpiod_direction_input();
      }
      else {
        gpiod_direction_output_raw(uVar5,1);
      }
    }
    _printk(&DAT_001008e8,reset_time);
    msleep(reset_time * 10);
    if (**(uint **)(param_1 + 8) < 0x200) {
      uVar3 = (*(uint **)(param_1 + 8))[1];
      uVar5 = gpio_to_desc();
      if ((char)uVar3 == '\0') {
        gpiod_direction_input();
      }
      else {
        gpiod_direction_output_raw(uVar5,1);
      }
    }
    if (*(uint *)(*(long *)(param_1 + 8) + 0x20) < 0x200) {
      bVar2 = *(byte *)(*(long *)(param_1 + 8) + 0x24);
      uVar5 = gpio_to_desc();
      gpiod_direction_output_raw(uVar5,bVar2 ^ 1);
    }
    msleep(reset_time * 0x32);
    _printk(&DAT_00100758,reset_time);
    blocking_notifier_call_chain(param_1 + 0x40,1,param_2);
    *(undefined4 *)(g_snshub + 0x270) = 0;
  }
  mutex_unlock(lVar1);
  return;
}



// ===========================================================
// Function: oplus_snshub_power_off_once at 00101864
// ===========================================================

void oplus_snshub_power_off_once(long param_1)

{
  long lVar1;
  byte bVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  uint *puVar7;
  long lVar8;
  long lVar9;
  
  lVar9 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  lVar1 = lVar9 + 0x88;
  iVar5 = mutex_trylock(lVar1);
  if (iVar5 == 0) {
    mutex_lock(lVar1);
  }
  else {
    blocking_notifier_call_chain(lVar9 + 0xb8,0,param_1);
    *(undefined4 *)(g_snshub + 0x270) = 1;
    puVar7 = *(uint **)(lVar9 + 8);
    if (puVar7[8] < 0x200) {
      uVar4 = puVar7[9];
      uVar6 = gpio_to_desc();
      gpiod_direction_output_raw(uVar6,(char)uVar4);
      puVar7 = *(uint **)(lVar9 + 8);
    }
    if (*puVar7 < 0x200) {
      uVar4 = puVar7[1];
      uVar6 = gpio_to_desc();
      if ((char)uVar4 == '\x01') {
        gpiod_direction_input();
      }
      else {
        gpiod_direction_output_raw(uVar6,1);
      }
    }
    msleep(10);
    lVar8 = *(long *)(lVar9 + 8);
    if (*(uint *)(lVar8 + 8) < 0x200) {
      bVar2 = *(byte *)(lVar8 + 0xc);
      uVar6 = gpio_to_desc();
      gpiod_direction_output_raw(uVar6,bVar2 ^ 1);
      lVar8 = *(long *)(lVar9 + 8);
    }
    if (*(uint *)(lVar8 + 0x10) < 0x200) {
      bVar2 = *(byte *)(lVar8 + 0x14);
      uVar6 = gpio_to_desc();
      gpiod_direction_output_raw(uVar6,bVar2 ^ 1);
    }
    msleep(200);
    lVar8 = *(long *)(lVar9 + 8);
    if (*(uint *)(lVar8 + 8) < 0x200) {
      uVar3 = *(undefined1 *)(lVar8 + 0xc);
      uVar6 = gpio_to_desc();
      gpiod_direction_output_raw(uVar6,uVar3);
      lVar8 = *(long *)(lVar9 + 8);
    }
    if (*(uint *)(lVar8 + 0x10) < 0x200) {
      uVar3 = *(undefined1 *)(lVar8 + 0x14);
      uVar6 = gpio_to_desc();
      gpiod_direction_output_raw(uVar6,uVar3);
    }
    msleep(10);
    if (**(uint **)(lVar9 + 8) < 0x200) {
      uVar4 = (*(uint **)(lVar9 + 8))[1];
      uVar6 = gpio_to_desc();
      if ((char)uVar4 == '\0') {
        gpiod_direction_input();
      }
      else {
        gpiod_direction_output_raw(uVar6,1);
      }
    }
    if (*(uint *)(*(long *)(lVar9 + 8) + 0x20) < 0x200) {
      bVar2 = *(byte *)(*(long *)(lVar9 + 8) + 0x24);
      uVar6 = gpio_to_desc();
      gpiod_direction_output_raw(uVar6,bVar2 ^ 1);
    }
    msleep(0x32);
    blocking_notifier_call_chain(lVar9 + 0xb8,1,param_1);
    *(undefined4 *)(g_snshub + 0x270) = 0;
  }
  mutex_unlock(lVar1);
  return;
}



// ===========================================================
// Function: oplus_snshub_hw_gpio_in at 00101a48
// ===========================================================

undefined8 oplus_snshub_hw_gpio_in(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (**(uint **)(lVar2 + 8) < 0x200) {
    gpio_to_desc();
    gpiod_direction_input();
    gpio_to_desc(**(undefined4 **)(lVar2 + 8));
    uVar1 = gpiod_get_raw_value();
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// ===========================================================
// Function: oplus_snshub_get_disable_uevent at 00101aa0
// ===========================================================

undefined4 oplus_snshub_get_disable_uevent(void)

{
  return *(undefined4 *)(g_snshub + 0x130);
}



// ===========================================================
// Function: oplus_snshub_deassert_reset at 00101ab0
// ===========================================================

void oplus_snshub_deassert_reset(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (**(uint **)(lVar3 + 8) < 0x200) {
    uVar1 = (*(uint **)(lVar3 + 8))[1];
    uVar2 = gpio_to_desc();
    if ((char)uVar1 == '\0') {
      gpiod_direction_input();
    }
    else {
      gpiod_direction_output_raw(uVar2,1);
    }
  }
  msleep(0x32);
  blocking_notifier_call_chain(lVar3 + 0x40,1,param_1);
  mutex_unlock(lVar3 + 0x10);
  return;
}



// ===========================================================
// Function: oplus_snshub_assert_reset at 00101b30
// ===========================================================

void oplus_snshub_assert_reset(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  mutex_lock(lVar3 + 0x10);
  blocking_notifier_call_chain(lVar3 + 0x40,0,param_1);
  if (**(uint **)(lVar3 + 8) < 0x200) {
    uVar1 = (*(uint **)(lVar3 + 8))[1];
    uVar2 = gpio_to_desc();
    if ((char)uVar1 == '\x01') {
      gpiod_direction_input();
    }
    else {
      gpiod_direction_output_raw(uVar2,1);
    }
  }
  msleep(10);
  return;
}



// ===========================================================
// Function: is_mcureseting at 00101bac
// ===========================================================

bool is_mcureseting(void)

{
  bool bVar1;
  
  if (g_snshub == 0) {
    _printk(&DAT_001005b9);
    bVar1 = false;
  }
  else {
    bVar1 = *(int *)(g_snshub + 0x270) != 0;
  }
  return bVar1;
}



// ===========================================================
// Function: oplus_snshub_probe at 00101bf0
// ===========================================================

int oplus_snshub_probe(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  ulong uVar5;
  ulong uVar6;
  char *pcVar7;
  long lVar8;
  int *piVar9;
  undefined4 local_4c;
  long local_48;
  
  lVar8 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_48 = *(long *)(lVar8 + 0x648);
  piVar9 = *(int **)(param_1 + 0xa0);
  _dev_err(lVar1,"oplus_snshub_probe()\n");
  if (piVar9 == (int *)0x0) {
    local_4c = 0;
    piVar9 = (int *)devm_kmalloc(lVar1,0x30,0xdc0);
    if (piVar9 != (int *)0x0) {
      iVar2 = of_get_named_gpio_flags(*(undefined8 *)(param_1 + 0x300),"reset-gpio",0,&local_4c);
      if (iVar2 < 0) {
        _dev_err(lVar1,"Unable to read reset gpio\n");
      }
      uVar3 = *(undefined8 *)(param_1 + 0x300);
      *piVar9 = iVar2;
      *(byte *)(piVar9 + 1) = (byte)local_4c & 1;
      iVar2 = of_get_named_gpio_flags(uVar3,"power-gpio",0,&local_4c);
      if (iVar2 < 0) {
        _dev_err(lVar1,"Unable to read power gpio\n");
      }
      uVar3 = *(undefined8 *)(param_1 + 0x300);
      piVar9[2] = iVar2;
      *(byte *)(piVar9 + 3) = (byte)local_4c & 1;
      iVar2 = of_get_named_gpio_flags(uVar3,"buck-enable-gpio",0,&local_4c);
      if (iVar2 < 0) {
        _dev_err(lVar1,"Unable to read buck enable gpio\n");
      }
      uVar3 = *(undefined8 *)(param_1 + 0x300);
      piVar9[4] = iVar2;
      *(byte *)(piVar9 + 5) = (byte)local_4c & 1;
      iVar2 = of_get_named_gpio_flags(uVar3,"ap-state-gpio",0,&local_4c);
      if (iVar2 < 0) {
        _dev_err(lVar1,"Unable to read ap state gpio \n");
      }
      uVar3 = *(undefined8 *)(param_1 + 0x300);
      piVar9[8] = iVar2;
      *(byte *)(piVar9 + 9) = (byte)local_4c & 1;
      iVar2 = of_get_named_gpio_flags(uVar3,"dead-gpio",0,&local_4c);
      if (-1 < iVar2) {
        piVar9[10] = iVar2;
        *(byte *)(piVar9 + 0xb) = (byte)local_4c & 1;
        goto LAB_00101d40;
      }
      _dev_err(lVar1,"Unable to read mcu dead gpio\n");
    }
  }
  else {
LAB_00101d40:
    plVar4 = (long *)devm_kmalloc(lVar1,0x278,0xdc0);
    if (plVar4 != (long *)0x0) {
      *plVar4 = lVar1;
      plVar4[1] = (long)piVar9;
      __init_rwsem(plVar4 + 8,"&(&snshub->rst_nh)->rwsem",&oplus_snshub_probe___key_28);
      plVar4[0x10] = 0;
      __mutex_init(plVar4 + 2,"&snshub->reset_lock",&oplus_snshub_probe___key_28);
      __init_rwsem(plVar4 + 0x17,"&(&snshub->power_nh)->rwsem",&oplus_snshub_probe___key_28);
      plVar4[0x1f] = 0;
      __mutex_init(plVar4 + 0x11,"&snshub->power_lock",&oplus_snshub_probe___key_28);
      __mutex_init(plVar4 + 0x20,"&snshub->dump_lock",&oplus_snshub_probe___key_28);
      __mutex_init(plVar4 + 0x27,"&snshub->disable_uevent_lock",&oplus_snshub_probe___key_28);
      *(undefined4 *)(plVar4 + 0x4e) = 0;
      uVar5 = devm_pinctrl_get(lVar1);
      if ((uVar5 < 0xfffffffffffff001) &&
         ((uVar6 = pinctrl_lookup_state(uVar5,"default"), 0xfffffffffffff000 < uVar6 ||
          (iVar2 = pinctrl_select_state(uVar5,uVar6), iVar2 < 0)))) {
        devm_pinctrl_put(uVar5);
      }
      iVar2 = mfd_add_devices(lVar1,0,&oplus_snshub_devs,2,0,0,0);
      if (iVar2 == 0) {
        iVar2 = sysfs_create_group(lVar1,&oplus_snshub_attr_group);
        if (iVar2 == 0) {
          plVar4[0x4d] = 0;
          plVar4[0x4c] = 0;
          plVar4[0x4b] = 0;
          plVar4[0x4a] = 0;
          plVar4[0x49] = 0;
          plVar4[0x48] = 0;
          plVar4[0x47] = 0;
          plVar4[0x46] = 0;
          plVar4[0x45] = 0;
          plVar4[0x44] = 0;
          plVar4[0x43] = 0;
          plVar4[0x42] = 0;
          plVar4[0x41] = 0;
          plVar4[0x3f] = 0;
          plVar4[0x40] = 0;
          plVar4[0x3d] = 0;
          plVar4[0x3e] = 0;
          plVar4[0x3b] = 0;
          plVar4[0x3c] = 0;
          plVar4[0x39] = 0;
          plVar4[0x3a] = 0;
          plVar4[0x37] = 0;
          plVar4[0x38] = 0;
          plVar4[0x35] = 0;
          plVar4[0x36] = 0;
          plVar4[0x34] = (long)"mcu_dump_wakesrc";
          wakeup_source_add(plVar4 + 0x34);
          plVar4[0x2e] = 0xfffffffe0;
          plVar4[0x2f] = (long)(plVar4 + 0x2f);
          plVar4[0x30] = (long)(plVar4 + 0x2f);
          plVar4[0x31] = (long)mcu_states_dump_cfi_jt;
          gpio_to_desc(piVar9[10]);
          iVar2 = gpiod_to_irq();
          *(int *)(plVar4 + 0x2d) = iVar2;
          if (iVar2 < 0) {
            _dev_err(lVar1,"gpio(%d) gpio_to_irq failed: %d\n",piVar9[10]);
            iVar2 = -0x16;
          }
          else {
            lVar8 = ((long *)*plVar4)[0xe];
            if (lVar8 == 0) {
              lVar8 = *(long *)*plVar4;
            }
            iVar2 = request_threaded_irq(iVar2,mcu_dump_int_irq_fn_cfi_jt,0,0x2001,lVar8);
            if (iVar2 < 0) {
              _dev_err(lVar1,"Error, could not request irq\n");
              iVar2 = -0x16;
            }
            else {
              iVar2 = irq_set_irq_wake((int)plVar4[0x2d],1);
              if (iVar2 == 0) {
                _dev_info(param_1 + 0x10,"dump: direction(in), gpio(%d), irq(%d)",piVar9[10],
                          (int)plVar4[0x2d]);
                *(long **)(param_1 + 0xa8) = plVar4;
                g_snshub = plVar4;
                _dev_info(param_1 + 0x10,"Oplus SensorHub register successful\n");
                iVar2 = 0;
              }
              else {
                _dev_err(lVar1,"Error, enable_irq_wake(%d)\n",(int)plVar4[0x2d]);
                iVar2 = -0x16;
              }
            }
          }
          goto LAB_00101d58;
        }
        mfd_remove_devices(lVar1);
        pcVar7 = "Failed to create attribute group: %d\n";
      }
      else {
        pcVar7 = "add mfd devices failed: %d\n";
      }
      _dev_err(lVar1,pcVar7,iVar2);
      goto LAB_00101d58;
    }
  }
  iVar2 = -0xc;
LAB_00101d58:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x648) == local_48) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// ===========================================================
// Function: oplus_snshub_remove at 001020ac
// ===========================================================

undefined8 oplus_snshub_remove(long param_1)

{
  g_snshub = 0;
  sysfs_remove_group(param_1 + 0x10,&oplus_snshub_attr_group);
  mfd_remove_devices(param_1 + 0x10);
  return 0;
}



// ===========================================================
// Function: oplus_snshub_suspend at 001020f4
// ===========================================================

undefined8 oplus_snshub_suspend(long param_1)

{
  byte bVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x98) + 8);
  if (*(uint *)(lVar3 + 0x18) < 0x200) {
    bVar1 = *(byte *)(lVar3 + 0x1c);
    uVar2 = gpio_to_desc();
    gpiod_direction_output_raw(uVar2,bVar1 ^ 1);
  }
  return 0;
}



// ===========================================================
// Function: oplus_snshub_resume at 00102140
// ===========================================================

undefined8 oplus_snshub_resume(long param_1)

{
  undefined1 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x98) + 8);
  if (*(uint *)(lVar3 + 0x18) < 0x200) {
    uVar1 = *(undefined1 *)(lVar3 + 0x1c);
    uVar2 = gpio_to_desc();
    gpiod_direction_output_raw(uVar2,uVar1);
  }
  return 0;
}



// ===========================================================
// Function: oplus_snshub_show_disable_uevent at 00102188
// ===========================================================

long oplus_snshub_show_disable_uevent(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%d",(ulong)*(uint *)(*(long *)(param_1 + 0x98) + 0x130));
  return (long)iVar1;
}



// ===========================================================
// Function: oplus_snshub_store_disable_uevent at 001021c4
// ===========================================================

void oplus_snshub_store_disable_uevent
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x648);
  lVar4 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar2 = kstrtoll(param_3,10,&local_40);
  uVar3 = 0xffffffffffffffea;
  if ((iVar2 == 0) && (local_40 != 0)) {
    lVar1 = lVar4 + 0x138;
    mutex_lock(lVar1);
    *(uint *)(lVar4 + 0x130) = (uint)(local_40 != 0);
    _dev_err(param_1,"disable_uevent %d\n");
    mutex_unlock(lVar1);
    uVar3 = param_4;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x648) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}



// ===========================================================
// Function: oplus_snshub_store_dump_notify at 0010228c
// ===========================================================

void oplus_snshub_store_dump_notify
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x648);
  lVar3 = *(long *)(param_1 + 0x98);
  local_30 = 0;
  iVar1 = kstrtoll(param_3,10,&local_30);
  uVar2 = 0xffffffffffffffea;
  if ((iVar1 == 0) && (local_30 != 0)) {
    lVar3 = lVar3 + 0x100;
    iVar1 = mutex_trylock(lVar3);
    if (iVar1 == 0) {
      mutex_lock(lVar3);
    }
    else {
      uVar2 = gpio_to_desc(0x3f9);
      gpiod_direction_output_raw(uVar2,1);
      msleep(100);
      uVar2 = gpio_to_desc(0x3f9);
      gpiod_direction_output_raw(uVar2,0);
      msleep(1);
    }
    mutex_unlock(lVar3);
    uVar2 = param_4;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x648) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}



// ===========================================================
// Function: oplus_snshub_store_power_mcu at 00102364
// ===========================================================

void oplus_snshub_store_power_mcu
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x648);
  local_30 = 0;
  iVar2 = kstrtoll(param_3,10,&local_30);
  lVar1 = sp_el0;
  if (local_30 == 0 || iVar2 != 0) {
    param_4 = 0xffffffffffffffea;
  }
  if (*(long *)(lVar1 + 0x648) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(param_4);
}



// ===========================================================
// Function: oplus_snshub_store_reset at 001023dc
// ===========================================================

void oplus_snshub_store_reset(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x648);
  uVar4 = *(undefined8 *)(param_1 + 0x98);
  local_40 = 0;
  iVar2 = kstrtoll(param_3,10,&local_40);
  uVar3 = 0xffffffffffffffea;
  if ((iVar2 == 0) && (local_40 != 0)) {
    reset_time = (undefined4)local_40;
    __oplus_snshub_reset(uVar4,0);
    reset_time = 1;
    uVar3 = param_4;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x648) == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}



// ===========================================================
// Function: mcu_states_dump at 00102484
// ===========================================================

void mcu_states_dump(void)

{
  long lVar1;
  char *local_48;
  char *pcStack_40;
  char *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x648);
  _printk(&DAT_001007de);
  __pm_stay_awake(g_snshub + 0x34);
  if (g_snshub == (undefined8 *)0x0) {
    _printk(&DAT_001005b9);
  }
  else {
    oplus_snshub_states_uevent_print_cnt = 0;
    local_48 = "MCU_UEVENT";
    pcStack_40 = "snshub";
    local_38 = "MCU_STATES=dump";
    uStack_30 = 0;
    _printk(&DAT_001007fd);
    kobject_uevent_env(*g_snshub,2,&local_48);
  }
  __pm_relax(g_snshub + 0x34);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x648) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// ===========================================================
// Function: mcu_dump_int_irq_fn at 00102558
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mcu_dump_int_irq_fn(int param_1,long param_2)

{
  int iVar1;
  
  if ((param_2 != 0) && (g_snshub != 0)) {
    gpio_to_desc(*(undefined4 *)(*(long *)(g_snshub + 8) + 0x28));
    iVar1 = gpiod_get_raw_value();
    if ((*(int *)(g_snshub + 0x168) == param_1) && (iVar1 != 0)) {
      queue_work_on(0x20,_system_wq,g_snshub + 0x170);
    }
  }
  return 1;
}



// ===========================================================
// Function: oplus_snshub_wakeup_data_uevent.cfi_jt at 001025c8
// ===========================================================

void oplus_snshub_wakeup_data_uevent_cfi_jt(long param_1)

{
  long lVar1;
  char *pcStack_48;
  long lStack_40;
  char *pcStack_38;
  undefined8 uStack_30;
  long lStack_28;
  
  lVar1 = sp_el0;
  lStack_28 = *(long *)(lVar1 + 0x648);
  if (param_1 == 0) {
    _printk(&DAT_0010087e);
  }
  else {
    _printk(&DAT_001005f4);
    pcStack_48 = "MCU_UEVENT";
    pcStack_38 = "WAKEUP_UEVENT=update";
    uStack_30 = 0;
    lStack_40 = param_1;
    if (g_snshub == (undefined8 *)0x0) {
      _printk(&DAT_001005b9);
    }
    else {
      _printk(&DAT_001007fd,param_1,"WAKEUP_UEVENT=update");
      kobject_uevent_env(*g_snshub,2,&pcStack_48);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x648) == lStack_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// ===========================================================
// Function: oplus_snshub_states_uevent.cfi_jt at 001025cc
// ===========================================================

void oplus_snshub_states_uevent_cfi_jt(uint param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  char *pcStack_48;
  long lStack_40;
  undefined *puStack_38;
  undefined8 uStack_30;
  long lStack_28;
  
  lVar1 = sp_el0;
  lStack_28 = *(long *)(lVar1 + 0x648);
  if ((int)param_1 < 4) {
    if (param_2 == 0) {
      _printk(&DAT_0010087e);
    }
    else if (g_snshub == (undefined8 *)0x0) {
      _printk(&DAT_001005b9);
    }
    else {
      if (param_1 == 2) {
        if (*(int *)(g_snshub + 0x26) != 0) {
          if (((oplus_snshub_states_uevent_print_cnt < 10) ||
              ((oplus_snshub_states_uevent_print_cnt & 0xffffff0f) == 0)) ||
             ((oplus_snshub_states_uevent_print_cnt & 0xff) == 0)) {
            _printk(&DAT_0010066e,"MCU_STATES=crash");
          }
          oplus_snshub_states_uevent_print_cnt = oplus_snshub_states_uevent_print_cnt + 1;
          goto LAB_001014d0;
        }
      }
      else {
        oplus_snshub_states_uevent_print_cnt = 0;
        if (3 < param_1) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101528);
          (*pcVar2)();
        }
      }
      oplus_snshub_states_uevent_print_cnt = 0;
      puStack_38 = (&PTR_s_MCU_STATES_first_00100b28)[param_1];
      pcStack_48 = "MCU_UEVENT";
      uStack_30 = 0;
      lStack_40 = param_2;
      _printk(&DAT_001007fd);
      kobject_uevent_env(*g_snshub,2,&pcStack_48);
    }
  }
  else {
    _printk(&DAT_00100859,(ulong)param_1,4);
  }
LAB_001014d0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x648) != lStack_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// ===========================================================
// Function: oplus_snshub_set_disable_uevent.cfi_jt at 001025d0
// ===========================================================

void oplus_snshub_set_disable_uevent_cfi_jt(int param_1)

{
  mutex_lock(g_snshub + 0x138);
  *(uint *)(g_snshub + 0x130) = (uint)(param_1 != 0);
  _printk(&DAT_0010041d);
  mutex_unlock(g_snshub + 0x138);
  return;
}



// ===========================================================
// Function: oplus_snshub_reset_notifier_unregister.cfi_jt at 001025d4
// ===========================================================

undefined8 oplus_snshub_reset_notifier_unregister_cfi_jt(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = g_snshub;
  if (param_1 != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  }
  if (lVar1 == 0) {
    _printk(&DAT_00100577);
    uVar2 = 0;
  }
  else {
    uVar2 = blocking_notifier_chain_unregister(lVar1 + 0x40);
  }
  return uVar2;
}



// ===========================================================
// Function: oplus_snshub_reset_notifier_register.cfi_jt at 001025d8
// ===========================================================

undefined8 oplus_snshub_reset_notifier_register_cfi_jt(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = g_snshub;
  if (param_1 != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  }
  if (lVar1 == 0) {
    _printk(&DAT_00100577);
    uVar2 = 0;
  }
  else {
    uVar2 = blocking_notifier_chain_register(lVar1 + 0x40);
  }
  return uVar2;
}



// ===========================================================
// Function: oplus_snshub_get_disable_uevent.cfi_jt at 001025dc
// ===========================================================

undefined4 oplus_snshub_get_disable_uevent_cfi_jt(void)

{
  return *(undefined4 *)(g_snshub + 0x130);
}



// ===========================================================
// Function: oplus_snshub_reset.cfi_jt at 001025e0
// ===========================================================

void oplus_snshub_reset_cfi_jt(long param_1)

{
  __oplus_snshub_reset(*(undefined8 *)(*(long *)(param_1 + 0x60) + 0x98),param_1);
  return;
}



// ===========================================================
// Function: oplus_snshub_power_off_once.cfi_jt at 001025e4
// ===========================================================

void oplus_snshub_power_off_once_cfi_jt(long param_1)

{
  long lVar1;
  byte bVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  uint *puVar7;
  long lVar8;
  long lVar9;
  
  lVar9 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  lVar1 = lVar9 + 0x88;
  iVar5 = mutex_trylock(lVar1);
  if (iVar5 == 0) {
    mutex_lock(lVar1);
  }
  else {
    blocking_notifier_call_chain(lVar9 + 0xb8,0,param_1);
    *(undefined4 *)(g_snshub + 0x270) = 1;
    puVar7 = *(uint **)(lVar9 + 8);
    if (puVar7[8] < 0x200) {
      uVar4 = puVar7[9];
      uVar6 = gpio_to_desc();
      gpiod_direction_output_raw(uVar6,(char)uVar4);
      puVar7 = *(uint **)(lVar9 + 8);
    }
    if (*puVar7 < 0x200) {
      uVar4 = puVar7[1];
      uVar6 = gpio_to_desc();
      if ((char)uVar4 == '\x01') {
        gpiod_direction_input();
      }
      else {
        gpiod_direction_output_raw(uVar6,1);
      }
    }
    msleep(10);
    lVar8 = *(long *)(lVar9 + 8);
    if (*(uint *)(lVar8 + 8) < 0x200) {
      bVar2 = *(byte *)(lVar8 + 0xc);
      uVar6 = gpio_to_desc();
      gpiod_direction_output_raw(uVar6,bVar2 ^ 1);
      lVar8 = *(long *)(lVar9 + 8);
    }
    if (*(uint *)(lVar8 + 0x10) < 0x200) {
      bVar2 = *(byte *)(lVar8 + 0x14);
      uVar6 = gpio_to_desc();
      gpiod_direction_output_raw(uVar6,bVar2 ^ 1);
    }
    msleep(200);
    lVar8 = *(long *)(lVar9 + 8);
    if (*(uint *)(lVar8 + 8) < 0x200) {
      uVar3 = *(undefined1 *)(lVar8 + 0xc);
      uVar6 = gpio_to_desc();
      gpiod_direction_output_raw(uVar6,uVar3);
      lVar8 = *(long *)(lVar9 + 8);
    }
    if (*(uint *)(lVar8 + 0x10) < 0x200) {
      uVar3 = *(undefined1 *)(lVar8 + 0x14);
      uVar6 = gpio_to_desc();
      gpiod_direction_output_raw(uVar6,uVar3);
    }
    msleep(10);
    if (**(uint **)(lVar9 + 8) < 0x200) {
      uVar4 = (*(uint **)(lVar9 + 8))[1];
      uVar6 = gpio_to_desc();
      if ((char)uVar4 == '\0') {
        gpiod_direction_input();
      }
      else {
        gpiod_direction_output_raw(uVar6,1);
      }
    }
    if (*(uint *)(*(long *)(lVar9 + 8) + 0x20) < 0x200) {
      bVar2 = *(byte *)(*(long *)(lVar9 + 8) + 0x24);
      uVar6 = gpio_to_desc();
      gpiod_direction_output_raw(uVar6,bVar2 ^ 1);
    }
    msleep(0x32);
    blocking_notifier_call_chain(lVar9 + 0xb8,1,param_1);
    *(undefined4 *)(g_snshub + 0x270) = 0;
  }
  mutex_unlock(lVar1);
  return;
}



// ===========================================================
// Function: oplus_snshub_deassert_reset.cfi_jt at 001025e8
// ===========================================================

void oplus_snshub_deassert_reset_cfi_jt(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (**(uint **)(lVar3 + 8) < 0x200) {
    uVar1 = (*(uint **)(lVar3 + 8))[1];
    uVar2 = gpio_to_desc();
    if ((char)uVar1 == '\0') {
      gpiod_direction_input();
    }
    else {
      gpiod_direction_output_raw(uVar2,1);
    }
  }
  msleep(0x32);
  blocking_notifier_call_chain(lVar3 + 0x40,1,param_1);
  mutex_unlock(lVar3 + 0x10);
  return;
}



// ===========================================================
// Function: oplus_snshub_assert_reset.cfi_jt at 001025ec
// ===========================================================

void oplus_snshub_assert_reset_cfi_jt(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  mutex_lock(lVar3 + 0x10);
  blocking_notifier_call_chain(lVar3 + 0x40,0,param_1);
  if (**(uint **)(lVar3 + 8) < 0x200) {
    uVar1 = (*(uint **)(lVar3 + 8))[1];
    uVar2 = gpio_to_desc();
    if ((char)uVar1 == '\x01') {
      gpiod_direction_input();
    }
    else {
      gpiod_direction_output_raw(uVar2,1);
    }
  }
  msleep(10);
  return;
}



// ===========================================================
// Function: is_mcureseting.cfi_jt at 001025f0
// ===========================================================

bool is_mcureseting_cfi_jt(void)

{
  bool bVar1;
  
  if (g_snshub == 0) {
    _printk(&DAT_001005b9);
    bVar1 = false;
  }
  else {
    bVar1 = *(int *)(g_snshub + 0x270) != 0;
  }
  return bVar1;
}



// ===========================================================
// Function: init_module.cfi_jt at 001025f4
// ===========================================================

void init_module_cfi_jt(void)

{
  __platform_driver_register(&oplus_snshub_driver,&__this_module);
  return;
}



// ===========================================================
// Function: oplus_snshub_probe.cfi_jt at 001025f8
// ===========================================================

int oplus_snshub_probe_cfi_jt(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  ulong uVar5;
  ulong uVar6;
  char *pcVar7;
  long lVar8;
  int *piVar9;
  undefined4 uStack_4c;
  long lStack_48;
  
  lVar8 = sp_el0;
  lVar1 = param_1 + 0x10;
  lStack_48 = *(long *)(lVar8 + 0x648);
  piVar9 = *(int **)(param_1 + 0xa0);
  _dev_err(lVar1,"oplus_snshub_probe()\n");
  if (piVar9 == (int *)0x0) {
    uStack_4c = 0;
    piVar9 = (int *)devm_kmalloc(lVar1,0x30,0xdc0);
    if (piVar9 != (int *)0x0) {
      iVar2 = of_get_named_gpio_flags(*(undefined8 *)(param_1 + 0x300),"reset-gpio",0,&uStack_4c);
      if (iVar2 < 0) {
        _dev_err(lVar1,"Unable to read reset gpio\n");
      }
      uVar3 = *(undefined8 *)(param_1 + 0x300);
      *piVar9 = iVar2;
      *(byte *)(piVar9 + 1) = (byte)uStack_4c & 1;
      iVar2 = of_get_named_gpio_flags(uVar3,"power-gpio",0,&uStack_4c);
      if (iVar2 < 0) {
        _dev_err(lVar1,"Unable to read power gpio\n");
      }
      uVar3 = *(undefined8 *)(param_1 + 0x300);
      piVar9[2] = iVar2;
      *(byte *)(piVar9 + 3) = (byte)uStack_4c & 1;
      iVar2 = of_get_named_gpio_flags(uVar3,"buck-enable-gpio",0,&uStack_4c);
      if (iVar2 < 0) {
        _dev_err(lVar1,"Unable to read buck enable gpio\n");
      }
      uVar3 = *(undefined8 *)(param_1 + 0x300);
      piVar9[4] = iVar2;
      *(byte *)(piVar9 + 5) = (byte)uStack_4c & 1;
      iVar2 = of_get_named_gpio_flags(uVar3,"ap-state-gpio",0,&uStack_4c);
      if (iVar2 < 0) {
        _dev_err(lVar1,"Unable to read ap state gpio \n");
      }
      uVar3 = *(undefined8 *)(param_1 + 0x300);
      piVar9[8] = iVar2;
      *(byte *)(piVar9 + 9) = (byte)uStack_4c & 1;
      iVar2 = of_get_named_gpio_flags(uVar3,"dead-gpio",0,&uStack_4c);
      if (-1 < iVar2) {
        piVar9[10] = iVar2;
        *(byte *)(piVar9 + 0xb) = (byte)uStack_4c & 1;
        goto LAB_00101d40;
      }
      _dev_err(lVar1,"Unable to read mcu dead gpio\n");
    }
  }
  else {
LAB_00101d40:
    plVar4 = (long *)devm_kmalloc(lVar1,0x278,0xdc0);
    if (plVar4 != (long *)0x0) {
      *plVar4 = lVar1;
      plVar4[1] = (long)piVar9;
      __init_rwsem(plVar4 + 8,"&(&snshub->rst_nh)->rwsem",&oplus_snshub_probe___key_28);
      plVar4[0x10] = 0;
      __mutex_init(plVar4 + 2,"&snshub->reset_lock",&oplus_snshub_probe___key_28);
      __init_rwsem(plVar4 + 0x17,"&(&snshub->power_nh)->rwsem",&oplus_snshub_probe___key_28);
      plVar4[0x1f] = 0;
      __mutex_init(plVar4 + 0x11,"&snshub->power_lock",&oplus_snshub_probe___key_28);
      __mutex_init(plVar4 + 0x20,"&snshub->dump_lock",&oplus_snshub_probe___key_28);
      __mutex_init(plVar4 + 0x27,"&snshub->disable_uevent_lock",&oplus_snshub_probe___key_28);
      *(undefined4 *)(plVar4 + 0x4e) = 0;
      uVar5 = devm_pinctrl_get(lVar1);
      if ((uVar5 < 0xfffffffffffff001) &&
         ((uVar6 = pinctrl_lookup_state(uVar5,"default"), 0xfffffffffffff000 < uVar6 ||
          (iVar2 = pinctrl_select_state(uVar5,uVar6), iVar2 < 0)))) {
        devm_pinctrl_put(uVar5);
      }
      iVar2 = mfd_add_devices(lVar1,0,&oplus_snshub_devs,2,0,0,0);
      if (iVar2 == 0) {
        iVar2 = sysfs_create_group(lVar1,&oplus_snshub_attr_group);
        if (iVar2 == 0) {
          plVar4[0x4d] = 0;
          plVar4[0x4c] = 0;
          plVar4[0x4b] = 0;
          plVar4[0x4a] = 0;
          plVar4[0x49] = 0;
          plVar4[0x48] = 0;
          plVar4[0x47] = 0;
          plVar4[0x46] = 0;
          plVar4[0x45] = 0;
          plVar4[0x44] = 0;
          plVar4[0x43] = 0;
          plVar4[0x42] = 0;
          plVar4[0x41] = 0;
          plVar4[0x3f] = 0;
          plVar4[0x40] = 0;
          plVar4[0x3d] = 0;
          plVar4[0x3e] = 0;
          plVar4[0x3b] = 0;
          plVar4[0x3c] = 0;
          plVar4[0x39] = 0;
          plVar4[0x3a] = 0;
          plVar4[0x37] = 0;
          plVar4[0x38] = 0;
          plVar4[0x35] = 0;
          plVar4[0x36] = 0;
          plVar4[0x34] = (long)"mcu_dump_wakesrc";
          wakeup_source_add(plVar4 + 0x34);
          plVar4[0x2e] = 0xfffffffe0;
          plVar4[0x2f] = (long)(plVar4 + 0x2f);
          plVar4[0x30] = (long)(plVar4 + 0x2f);
          plVar4[0x31] = (long)mcu_states_dump_cfi_jt;
          gpio_to_desc(piVar9[10]);
          iVar2 = gpiod_to_irq();
          *(int *)(plVar4 + 0x2d) = iVar2;
          if (iVar2 < 0) {
            _dev_err(lVar1,"gpio(%d) gpio_to_irq failed: %d\n",piVar9[10]);
            iVar2 = -0x16;
          }
          else {
            lVar8 = ((long *)*plVar4)[0xe];
            if (lVar8 == 0) {
              lVar8 = *(long *)*plVar4;
            }
            iVar2 = request_threaded_irq(iVar2,mcu_dump_int_irq_fn_cfi_jt,0,0x2001,lVar8);
            if (iVar2 < 0) {
              _dev_err(lVar1,"Error, could not request irq\n");
              iVar2 = -0x16;
            }
            else {
              iVar2 = irq_set_irq_wake((int)plVar4[0x2d],1);
              if (iVar2 == 0) {
                _dev_info(param_1 + 0x10,"dump: direction(in), gpio(%d), irq(%d)",piVar9[10],
                          (int)plVar4[0x2d]);
                *(long **)(param_1 + 0xa8) = plVar4;
                g_snshub = plVar4;
                _dev_info(param_1 + 0x10,"Oplus SensorHub register successful\n");
                iVar2 = 0;
              }
              else {
                _dev_err(lVar1,"Error, enable_irq_wake(%d)\n",(int)plVar4[0x2d]);
                iVar2 = -0x16;
              }
            }
          }
          goto LAB_00101d58;
        }
        mfd_remove_devices(lVar1);
        pcVar7 = "Failed to create attribute group: %d\n";
      }
      else {
        pcVar7 = "add mfd devices failed: %d\n";
      }
      _dev_err(lVar1,pcVar7,iVar2);
      goto LAB_00101d58;
    }
  }
  iVar2 = -0xc;
LAB_00101d58:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x648) == lStack_48) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// ===========================================================
// Function: oplus_snshub_remove.cfi_jt at 001025fc
// ===========================================================

undefined8 oplus_snshub_remove_cfi_jt(long param_1)

{
  g_snshub = 0;
  sysfs_remove_group(param_1 + 0x10,&oplus_snshub_attr_group);
  mfd_remove_devices(param_1 + 0x10);
  return 0;
}



// ===========================================================
// Function: oplus_snshub_hw_gpio_in.cfi_jt at 00102600
// ===========================================================

undefined8 oplus_snshub_hw_gpio_in_cfi_jt(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (**(uint **)(lVar2 + 8) < 0x200) {
    gpio_to_desc();
    gpiod_direction_input();
    gpio_to_desc(**(undefined4 **)(lVar2 + 8));
    uVar1 = gpiod_get_raw_value();
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// ===========================================================
// Function: oplus_snshub_suspend.cfi_jt at 00102604
// ===========================================================

undefined8 oplus_snshub_suspend_cfi_jt(long param_1)

{
  byte bVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x98) + 8);
  if (*(uint *)(lVar3 + 0x18) < 0x200) {
    bVar1 = *(byte *)(lVar3 + 0x1c);
    uVar2 = gpio_to_desc();
    gpiod_direction_output_raw(uVar2,bVar1 ^ 1);
  }
  return 0;
}



// ===========================================================
// Function: oplus_snshub_resume.cfi_jt at 00102608
// ===========================================================

undefined8 oplus_snshub_resume_cfi_jt(long param_1)

{
  undefined1 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x98) + 8);
  if (*(uint *)(lVar3 + 0x18) < 0x200) {
    uVar1 = *(undefined1 *)(lVar3 + 0x1c);
    uVar2 = gpio_to_desc();
    gpiod_direction_output_raw(uVar2,uVar1);
  }
  return 0;
}



// ===========================================================
// Function: oplus_snshub_show_disable_uevent.cfi_jt at 0010260c
// ===========================================================

long oplus_snshub_show_disable_uevent_cfi_jt(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%d",(ulong)*(uint *)(*(long *)(param_1 + 0x98) + 0x130));
  return (long)iVar1;
}



// ===========================================================
// Function: oplus_snshub_store_disable_uevent.cfi_jt at 00102610
// ===========================================================

void oplus_snshub_store_disable_uevent_cfi_jt
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lStack_40;
  long lStack_38;
  
  lVar4 = sp_el0;
  lStack_38 = *(long *)(lVar4 + 0x648);
  lVar4 = *(long *)(param_1 + 0x98);
  lStack_40 = 0;
  iVar2 = kstrtoll(param_3,10,&lStack_40);
  uVar3 = 0xffffffffffffffea;
  if ((iVar2 == 0) && (lStack_40 != 0)) {
    lVar1 = lVar4 + 0x138;
    mutex_lock(lVar1);
    *(uint *)(lVar4 + 0x130) = (uint)(lStack_40 != 0);
    _dev_err(param_1,"disable_uevent %d\n");
    mutex_unlock(lVar1);
    uVar3 = param_4;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x648) == lStack_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}



// ===========================================================
// Function: oplus_snshub_store_dump_notify.cfi_jt at 00102614
// ===========================================================

void oplus_snshub_store_dump_notify_cfi_jt
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lStack_30;
  long lStack_28;
  
  lVar3 = sp_el0;
  lStack_28 = *(long *)(lVar3 + 0x648);
  lVar3 = *(long *)(param_1 + 0x98);
  lStack_30 = 0;
  iVar1 = kstrtoll(param_3,10,&lStack_30);
  uVar2 = 0xffffffffffffffea;
  if ((iVar1 == 0) && (lStack_30 != 0)) {
    lVar3 = lVar3 + 0x100;
    iVar1 = mutex_trylock(lVar3);
    if (iVar1 == 0) {
      mutex_lock(lVar3);
    }
    else {
      uVar2 = gpio_to_desc(0x3f9);
      gpiod_direction_output_raw(uVar2,1);
      msleep(100);
      uVar2 = gpio_to_desc(0x3f9);
      gpiod_direction_output_raw(uVar2,0);
      msleep(1);
    }
    mutex_unlock(lVar3);
    uVar2 = param_4;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x648) == lStack_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}



// ===========================================================
// Function: oplus_snshub_store_power_mcu.cfi_jt at 00102618
// ===========================================================

void oplus_snshub_store_power_mcu_cfi_jt
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lStack_30;
  long lStack_28;
  
  lVar1 = sp_el0;
  lStack_28 = *(long *)(lVar1 + 0x648);
  lStack_30 = 0;
  iVar2 = kstrtoll(param_3,10,&lStack_30);
  lVar1 = sp_el0;
  if (lStack_30 == 0 || iVar2 != 0) {
    param_4 = 0xffffffffffffffea;
  }
  if (*(long *)(lVar1 + 0x648) == lStack_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(param_4);
}



// ===========================================================
// Function: oplus_snshub_store_reset.cfi_jt at 0010261c
// ===========================================================

void oplus_snshub_store_reset_cfi_jt
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lStack_40;
  long lStack_38;
  
  lVar1 = sp_el0;
  lStack_38 = *(long *)(lVar1 + 0x648);
  uVar4 = *(undefined8 *)(param_1 + 0x98);
  lStack_40 = 0;
  iVar2 = kstrtoll(param_3,10,&lStack_40);
  uVar3 = 0xffffffffffffffea;
  if ((iVar2 == 0) && (lStack_40 != 0)) {
    reset_time = (undefined4)lStack_40;
    __oplus_snshub_reset(uVar4,0);
    reset_time = 1;
    uVar3 = param_4;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x648) == lStack_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}



// ===========================================================
// Function: mcu_states_dump.cfi_jt at 00102620
// ===========================================================

void mcu_states_dump_cfi_jt(void)

{
  long lVar1;
  char *pcStack_48;
  char *pcStack_40;
  char *pcStack_38;
  undefined8 uStack_30;
  long lStack_28;
  
  lVar1 = sp_el0;
  lStack_28 = *(long *)(lVar1 + 0x648);
  _printk(&DAT_001007de);
  __pm_stay_awake(g_snshub + 0x34);
  if (g_snshub == (undefined8 *)0x0) {
    _printk(&DAT_001005b9);
  }
  else {
    oplus_snshub_states_uevent_print_cnt = 0;
    pcStack_48 = "MCU_UEVENT";
    pcStack_40 = "snshub";
    pcStack_38 = "MCU_STATES=dump";
    uStack_30 = 0;
    _printk(&DAT_001007fd);
    kobject_uevent_env(*g_snshub,2,&pcStack_48);
  }
  __pm_relax(g_snshub + 0x34);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x648) == lStack_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// ===========================================================
// Function: mcu_dump_int_irq_fn.cfi_jt at 00102624
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mcu_dump_int_irq_fn_cfi_jt(int param_1,long param_2)

{
  int iVar1;
  
  if ((param_2 != 0) && (g_snshub != 0)) {
    gpio_to_desc(*(undefined4 *)(*(long *)(g_snshub + 8) + 0x28));
    iVar1 = gpiod_get_raw_value();
    if ((*(int *)(g_snshub + 0x168) == param_1) && (iVar1 != 0)) {
      queue_work_on(0x20,_system_wq,g_snshub + 0x170);
    }
  }
  return 1;
}



// ===========================================================
// Function: wait_mcureseting.cfi_jt at 00102628
// ===========================================================

void wait_mcureseting_cfi_jt(void)

{
  int iVar1;
  
  if (g_snshub == 0) {
    _printk(&DAT_001005b9);
  }
  else {
    iVar1 = *(int *)(g_snshub + 0x270);
    while (iVar1 != 0) {
      msleep(0x14);
      iVar1 = *(int *)(g_snshub + 0x270);
    }
  }
  return;
}



// ===========================================================
// Function: cleanup_module.cfi_jt at 0010262c
// ===========================================================

void cleanup_module_cfi_jt(void)

{
  platform_driver_unregister(&oplus_snshub_driver);
  return;
}



// ===========================================================
// Function: init_module at 00102e40
// ===========================================================

void init_module(void)

{
  __platform_driver_register(&oplus_snshub_driver,&__this_module);
  return;
}



// ===========================================================
// Function: cleanup_module at 00102e6c
// ===========================================================

void cleanup_module(void)

{
  platform_driver_unregister(&oplus_snshub_driver);
  return;
}



// ===========================================================
// Function: gpiod_direction_input at 00104000
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_input(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: gpio_to_desc at 00104008
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: _printk at 00104010
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: blocking_notifier_chain_register at 00104018
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: blocking_notifier_chain_unregister at 00104020
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: msleep at 00104028
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: mutex_lock at 00104030
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: mutex_unlock at 00104038
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: gpiod_get_raw_value at 00104040
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: blocking_notifier_call_chain at 00104048
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: gpiod_direction_output_raw at 00104050
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: mutex_trylock at 00104058
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void mutex_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: kobject_uevent_env at 00104060
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent_env(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __platform_driver_register at 00104068
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __platform_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: _dev_err at 00104070
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __init_rwsem at 00104078
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __mutex_init at 00104080
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: mfd_add_devices at 00104088
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void mfd_add_devices(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: sysfs_create_group at 00104090
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: mfd_remove_devices at 00104098
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void mfd_remove_devices(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: wakeup_source_add at 001040a0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: _dev_info at 001040a8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: of_get_named_gpio_flags at 001040b0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: devm_kmalloc at 001040b8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: devm_pinctrl_get at 001040c0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: pinctrl_lookup_state at 001040c8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: devm_pinctrl_put at 001040d0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: pinctrl_select_state at 001040d8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: kstrtoll at 001040e0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void kstrtoll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: snprintf at 001040e8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __pm_stay_awake at 001040f0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __pm_relax at 001040f8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: gpiod_to_irq at 00104100
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: request_threaded_irq at 00104108
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: queue_work_on at 00104110
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: irq_set_irq_wake at 00104118
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: sysfs_remove_group at 00104120
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: platform_driver_unregister at 00104128
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __ubsan_handle_cfi_check_fail_abort at 00104130
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __ubsan_handle_cfi_check_fail_abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __stack_chk_fail at 00104140
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



