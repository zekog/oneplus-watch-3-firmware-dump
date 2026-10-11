// ===========================================================
// Function: rwnx_ipc_init at 0014bbcc
// ===========================================================

undefined8 rwnx_ipc_init(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined8 *__s;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  int iVar6;
  
  if (3 < DAT_0010d5f8) {
    _printk(&DAT_00121924,"rwnx_ipc_init");
  }
  __s = (undefined8 *)kmalloc_order_trace(0x2cc0,0xdc0,2);
  *(undefined8 **)(param_1 + 0x55d8) = __s;
  if (__s == (undefined8 *)0x0) {
    uVar3 = 0xfffffff4;
  }
  else {
    memset(__s,0,0x2cc0);
    __s[6] = 0;
    __s[7] = param_2;
    puVar1 = __s + 0x447;
    puVar4 = __s + 0xa7;
    iVar6 = 1;
    *__s = 0;
    __s[1] = 0;
    __s[2] = 0;
    __s[3] = 0;
    __s[4] = 0;
    __s[5] = 0;
    __s[0x597] = param_1;
    __s[0x447] = puVar1;
    __s[0x448] = puVar1;
    __s[0x449] = __s + 0x449;
    __s[0x44a] = __s + 0x449;
    do {
      *(int *)(puVar4 + 3) = iVar6;
      puVar5 = (undefined8 *)__s[0x448];
      uVar2 = __list_add_valid(puVar4,puVar5,puVar1);
      if ((uVar2 & 1) != 0) {
        __s[0x448] = puVar4;
        *puVar4 = puVar1;
        puVar4[1] = puVar5;
        *puVar5 = puVar4;
      }
      puVar4 = puVar4 + 4;
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0xe9);
    if (3 < DAT_0010d218) {
      _printk(&DAT_00121924,"rwnx_cmd_mgr_init");
    }
    uVar3 = 0;
    *(long *)(param_1 + 0x55f8) = param_1 + 0x55f8;
    *(long *)(param_1 + 0x5600) = param_1 + 0x55f8;
    *(undefined4 *)(param_1 + 22000) = 8;
    *(undefined4 *)(param_1 + 0x55e4) = 0;
    *(code **)(param_1 + 0x5608) = cmd_mgr_queue_cfi_jt;
    *(code **)(param_1 + 0x5620) = cmd_mgr_print_cfi_jt;
    *(code **)(param_1 + 0x5628) = cmd_mgr_drain_cfi_jt;
    *(code **)(param_1 + 0x5610) = cmd_mgr_llind_cfi_jt;
    *(code **)(param_1 + 0x5618) = cmd_mgr_msgind_cfi_jt;
  }
  return uVar3;
}



// ===========================================================
// Function: bes_mspi_plat_power at 00188b24
// ===========================================================

undefined4 bes_mspi_plat_power(long param_1,ulong param_2)

{
  char cVar1;
  undefined4 uVar2;
  code *pcVar3;
  long lVar4;
  
  if ((param_2 & 1) == 0) {
    if (DAT_0010d8d8 < 3) {
      cVar1 = *(char *)(param_1 + 0xcb8);
    }
    else {
      _printk(&DAT_00128d63,"bes_mspi_power_down",*(undefined1 *)(param_1 + 0xcb8));
      cVar1 = *(char *)(param_1 + 0xcb8);
    }
    if (cVar1 == '\0') {
      uVar2 = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0xcb8) = 0;
      driver_unregister(&PTR_s_bes2610_wlan_spi_0011ad88);
      if ((param_1 == 0) || (*(long **)(param_1 + 0xde0) == (long *)0x0)) {
        uVar2 = 0xfffffff2;
      }
      else {
        lVar4 = **(long **)(param_1 + 0xde0);
        if (**(long **)(lVar4 + 0xf8) == 0) {
          uVar2 = 0xffffffa1;
        }
        else {
          mutex_lock(lVar4 + 0x100);
          pcVar3 = (code *)**(undefined8 **)(lVar4 + 0xf8);
          if (pcVar3 != bes_chip_power_gpio_cfi_jt) {
            __cfi_slowpath_diag(0xa2c73fd0698d3355,pcVar3,&DAT_0011b750);
          }
          uVar2 = (*pcVar3)(lVar4,0);
          mutex_unlock(lVar4 + 0x100);
        }
      }
      DAT_0010cb68 = 0;
      DAT_0010cbb2 = 1;
      bes_power_ctrl_system_enabled(0,0);
    }
  }
  else {
    uVar2 = bes_mspi_power_up(param_1);
  }
  return uVar2;
}



// ===========================================================
// Function: bes_mspi_power_up at 00188c6c
// ===========================================================

int bes_mspi_power_up(long param_1)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  code *pcVar4;
  
  if (2 < DAT_0010d8d8) {
    _printk(&DAT_00131797,"bes_mspi_power_up");
  }
  if (((param_1 == 0) || (*(long **)(param_1 + 0xde0) == (long *)0x0)) ||
     (lVar3 = **(long **)(param_1 + 0xde0), **(long **)(lVar3 + 0xf8) == 0)) {
LAB_00188d24:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x188d2c);
    (*pcVar4)();
  }
  mutex_lock(lVar3 + 0x100);
  pcVar4 = (code *)**(undefined8 **)(lVar3 + 0xf8);
  if (pcVar4 != bes_chip_power_gpio_cfi_jt) {
    __cfi_slowpath_diag(0xa2c73fd0698d3355,pcVar4,&DAT_0011b750);
  }
  iVar1 = (*pcVar4)(lVar3,0);
  mutex_unlock(lVar3 + 0x100);
  if (iVar1 != 0) goto LAB_00188d24;
  msleep(10);
  if ((*(long **)(param_1 + 0xde0) == (long *)0x0) ||
     (lVar3 = **(long **)(param_1 + 0xde0), **(long **)(lVar3 + 0xf8) == 0)) {
LAB_00188d90:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x188d94);
    (*pcVar4)();
  }
  mutex_lock(lVar3 + 0x100);
  pcVar4 = (code *)**(undefined8 **)(lVar3 + 0xf8);
  if (pcVar4 != bes_chip_power_gpio_cfi_jt) {
    __cfi_slowpath_diag(0xa2c73fd0698d3355,pcVar4,&DAT_0011b750);
  }
  iVar1 = (*pcVar4)(lVar3,1);
  mutex_unlock(lVar3 + 0x100);
  if (iVar1 != 0) goto LAB_00188d90;
  if (*(char *)(param_1 + 0xcb8) != '\0') {
    return 0;
  }
  *(undefined1 *)(param_1 + 0xcb8) = 1;
  bes_power_ctrl_start_bus_probe();
  iVar1 = __spi_register_driver(&__this_module,&bes_mspi_driver);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined1 *)(param_1 + 0xcb8) = 0;
  if (DAT_00105ef0 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x188ef4);
    (*pcVar4)();
  }
  cancel_delayed_work_sync(*DAT_00105ef0 + 0x20);
  if (DAT_00105ef0 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x188ef8);
    (*pcVar4)();
  }
  lVar3 = *DAT_00105ef0;
  _raw_spin_lock(lVar3 + 0xb8);
  *(undefined4 *)(lVar3 + 0xbc) = 0;
  if (*(char *)(lVar3 + 400) == '\0') {
    if (DAT_0010d618 < 4) goto LAB_00188e64;
    puVar2 = &DAT_001309dc;
  }
  else {
    __pm_relax(*(undefined8 *)(lVar3 + 0x188));
    *(undefined1 *)(lVar3 + 400) = 0;
    if (DAT_0010d618 < 4) goto LAB_00188e64;
    puVar2 = &DAT_00120f23;
  }
  _printk(puVar2,"bes_power_ctrl_pm_relax");
LAB_00188e64:
  _raw_spin_unlock(lVar3 + 0xb8);
  return iVar1;
}



// ===========================================================
// Function: bes_mspi_probe at 00188ef8
// ===========================================================

uint bes_mspi_probe(long param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined *puVar5;
  ulong uVar6;
  long lVar7;
  undefined1 *puVar8;
  
  if (DAT_00105ef0 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x189774);
    (*pcVar1)();
  }
  lVar7 = *DAT_00105ef0;
  _raw_spin_lock(lVar7 + 0xb8);
  *(undefined4 *)(lVar7 + 0xa8) = 2;
  _raw_spin_unlock(lVar7 + 0xb8);
  cancel_delayed_work_sync(lVar7 + 0x20);
  __wake_up(lVar7 + 8,3,1,0);
  device_init_wakeup(param_1,1);
  memset(&DAT_00105f50,0,0x1a8);
  *(undefined4 *)(param_1 + 0x3a8) = 1;
  *(undefined1 *)(param_1 + 0x3a5) = 0x20;
  mspi_tx_ack_completion = 0;
  __init_swait_queue_head(&DAT_00106508,"&x->wait",&init_completion___key_1646);
  oplus_spi_slave_ready_cb_register(param_1,bes_mspi_ready_cfi_jt);
  if (2 < DAT_0010d8d8) {
    _printk(&DAT_00131dc1,param_1,*(undefined1 *)(param_1 + 0x3a4),*(undefined4 *)(param_1 + 0x3a8),
            *(undefined1 *)(param_1 + 0x3a5),*(undefined4 *)(param_1 + 0x3a0));
  }
  DAT_001060a0 = of_get_named_gpio_flags(*(undefined8 *)(param_1 + 0x2f0),"slave-tx-ready-gpio",0,0)
  ;
  if (DAT_001060a0 < 0x200) {
    uVar2 = gpio_request(DAT_001060a0,"slave-tx-ready-gpio");
    if (uVar2 == 0) {
      uVar4 = gpio_to_desc(DAT_001060a0);
      gpiod_direction_output_raw(uVar4,0);
      DAT_001060b0 = of_get_named_gpio_flags
                               (*(undefined8 *)(param_1 + 0x2f0),"slave-rx-ready-gpio",0,0);
      if (DAT_001060b0 < 0x200) {
        uVar2 = gpio_request(DAT_001060b0,"slave-rx-ready-gpio");
        if (uVar2 == 0) {
          uVar4 = gpio_to_desc(DAT_001060b0);
          gpiod_direction_output_raw(uVar4,0);
          DAT_00105f78 = of_get_named_gpio_flags
                                   (*(undefined8 *)(param_1 + 0x2f0),"master-tx-ind-gpio",0,0);
          if (DAT_00105f78 < 0x200) {
            gpio_to_desc(DAT_00105f78);
            DAT_00105f7c = gpiod_to_irq();
            DAT_00106098 = of_get_named_gpio_flags
                                     (*(undefined8 *)(param_1 + 0x2f0),"master-crc-ok-gpio",0,0);
            if (DAT_00106098 < 0x200) {
              gpio_to_desc(DAT_00106098);
              uVar4 = gpiod_to_irq();
              DAT_0010609c = (undefined4)uVar4;
              uVar2 = request_threaded_irq
                                (uVar4,bes_mspi_tx_done_irq_cfi_jt,0,0x2001,"master-crc-ok-gpio",
                                 &DAT_00105f50);
              if (uVar2 == 0) {
                DAT_001060b4 = of_get_named_gpio_flags
                                         (*(undefined8 *)(param_1 + 0x2f0),"slave-crc-ok-gpio",0,0);
                if (DAT_001060b4 < 0x200) {
                  uVar2 = gpio_request(DAT_001060b4,"slave-crc-ok-gpio");
                  if (uVar2 == 0) {
                    uVar4 = gpio_to_desc(DAT_001060b4);
                    gpiod_direction_output_raw(uVar4,0);
                    msleep(1);
                    iVar3 = bes_mspi_irq_poll();
                    if (iVar3 == 0) {
                      if (DAT_00105eb8 == 0) {
                        if (DAT_0010d8d8 < 1) {
                          uVar2 = 0xfffffff4;
                        }
                        else {
                          uVar2 = 0xfffffff4;
                          _printk(&DAT_00128d7f,0xfffffff4);
                        }
                      }
                      else {
                        DAT_00105f58 = 0;
                        DAT_00106080 = DAT_00105eb8 + (ulong)(ushort)bes_mspi_default_blksize;
                        DAT_00106078 = DAT_00105eb8;
                        __init_waitqueue_head(&DAT_00105f60,"&bes_spi->wq",&mspi_rx_error_cnt);
                        DAT_00105f80 = 0;
                        *(long **)(param_1 + 0x98) = &DAT_00105f50;
                        DAT_00105fa8 = 0;
                        DAT_00105fb0 = &DAT_00105fb0;
                        DAT_00105fb8 = &DAT_00105fb0;
                        DAT_001060c8 = &DAT_001060c8;
                        DAT_001060d0 = &DAT_001060c8;
                        DAT_001060d8 = 0;
                        mspi_rx_error_cnt = 0;
                        mspi_rx_crc_err_cnt = 0;
                        DAT_00105f50 = param_1;
                        uVar4 = bes_mspi_cmd_build();
                        iVar3 = bes_mspi_exchange(DAT_00105f50,uVar4);
                        if (2 < DAT_0010d8d8) {
                          _printk(&DAT_0011e16c,"bes_mspi_probe",iVar3);
                        }
                        if (iVar3 != 0) {
                          DAT_001060e0 = DAT_001060e0 + 1;
                        }
                        uVar4 = bes_mspi_cmd_build();
                        uVar2 = bes_mspi_exchange(DAT_00105f50,uVar4);
                        if (uVar2 == 0) {
                          if (3 < DAT_0010d8d8) {
                            _printk(&DAT_00129ecd,DAT_00105f85,DAT_00105f89,DAT_00105f8a,
                                    DAT_00105f8b,DAT_00105f8d,DAT_00105f8f);
                          }
                          if (DAT_00105f84 == '\0') {
                    /* WARNING: Does not return */
                            pcVar1 = (code *)SoftwareBreakpoint(0x800,0x189614);
                            (*pcVar1)();
                          }
                          if (DAT_00105f85 >> 0x10 == 0xbe57) {
                            if (2 < DAT_0010d8d8) {
                              _printk(&DAT_00125cc4);
                            }
                            DAT_0010d004 = (undefined2)DAT_00105f85;
                            uVar2 = bes_mspi_data_mem_init();
                            if (uVar2 == 0) {
                              bes_mspi_init_plat_cfg(param_1);
                              uVar6 = bes_power_ctrl_can_skip_platform_init(&g_rwnx_plat);
                              if ((uVar6 & 1) == 0) {
                                DAT_00105120 = 0;
                                DAT_00105128 = 0;
                                DAT_001051a4 = 0;
                                DAT_001051a8 = 0;
                                DAT_001051f8 = 0;
                                DAT_0010512c = 0;
                                DAT_00105200 = 0;
                                DAT_00105208 = bes_mspi_data_push_cfi_jt;
                                DAT_00105210 = bes_mspi_msg_push_cfi_jt;
                                uVar2 = rwnx_platform_init(&g_rwnx_plat,0);
                                if (uVar2 == 0) goto LAB_001896a8;
                              }
                              else {
LAB_001896a8:
                                uVar2 = bes_power_ctrl_system_enabled(1,0);
                                if (-1 < (int)uVar2) {
                                  return 0;
                                }
                              }
                              del_timer_sync(&DAT_00105130);
                              del_timer_sync(&DAT_00105168);
                              DAT_00105e00 = 0;
                              DAT_001060a8 = 0;
                              DAT_001060f0 = 0;
                            }
                            else if (0 < DAT_0010d8d8) {
                              _printk(&DAT_001243a9,"bes_mspi_probe");
                            }
                          }
                          else if (DAT_0010d8d8 < 1) {
                            uVar2 = 0;
                          }
                          else {
                            _printk(&DAT_0012cb39);
                            uVar2 = 0;
                          }
                        }
                        else if (0 < DAT_0010d8d8) {
                          _printk(&DAT_0011f5ec,uVar2);
                        }
                        DAT_00105f50 = 0;
                        *(undefined8 *)(param_1 + 0x98) = 0;
                        DAT_00106078 = 0;
                        DAT_00106080 = 0;
                      }
                    }
                    else {
                      if (0 < DAT_0010d8d8) {
                        _printk(&DAT_0011d511);
                      }
                      uVar2 = 0;
                    }
                    gpio_free(DAT_001060b4);
                  }
                  else if (0 < DAT_0010d618) {
                    _printk(&DAT_001313a1,uVar2);
                  }
                }
                else {
                  uVar2 = DAT_001060b4;
                  if (0 < DAT_0010d498) {
                    _printk(&DAT_0013136b,"bes_mspi_probe",0);
                    uVar2 = DAT_001060b4;
                  }
                }
                gpio_free(DAT_00106098);
              }
              else if (0 < DAT_0010d8d8) {
                _printk(&DAT_00131e07,"bes_mspi_probe",uVar2);
              }
              free_irq(DAT_0010609c,&DAT_00105f50);
            }
            else {
              uVar2 = DAT_00106098;
              if (0 < DAT_0010d498) {
                _printk(&DAT_0012be80,"bes_mspi_probe",0);
                uVar2 = DAT_00106098;
              }
            }
            gpio_free(DAT_00105f78);
          }
          else {
            uVar2 = DAT_00105f78;
            if (0 < DAT_0010d8d8) {
              _printk(&DAT_00129667,"bes_mspi_probe",0);
              uVar2 = DAT_00105f78;
            }
          }
          gpio_free(DAT_001060b0);
        }
        else if (0 < DAT_0010d618) {
          _printk(&DAT_00131344,uVar2);
        }
      }
      else {
        uVar2 = DAT_001060b0;
        if (0 < DAT_0010d498) {
          _printk(&DAT_00129e9b,"bes_mspi_probe",0);
          uVar2 = DAT_001060b0;
        }
      }
      gpio_free(DAT_001060a0);
    }
    else if (0 < DAT_0010d618) {
      _printk(&DAT_001270c1,uVar2);
    }
  }
  else {
    uVar2 = DAT_001060a0;
    if (0 < DAT_0010d498) {
      _printk(&DAT_00131312,"bes_mspi_probe",0);
      uVar2 = DAT_001060a0;
    }
  }
  if (DAT_00105ef0 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x189778);
    (*pcVar1)();
  }
  lVar7 = *DAT_00105ef0;
  _raw_spin_lock(lVar7 + 0xb8);
  *(undefined4 *)(lVar7 + 0xbc) = 0;
  if (*(char *)(lVar7 + 400) == '\0') {
    if (DAT_0010d618 < 4) goto LAB_001894c8;
    puVar5 = &DAT_001309dc;
  }
  else {
    __pm_relax(*(undefined8 *)(lVar7 + 0x188));
    *(undefined1 *)(lVar7 + 400) = 0;
    if (DAT_0010d618 < 4) goto LAB_001894c8;
    puVar5 = &DAT_00120f23;
  }
  _printk(puVar5,"bes_power_ctrl_pm_relax");
LAB_001894c8:
  _raw_spin_unlock(lVar7 + 0xb8);
  if (DAT_00105ef0 != (long *)0x0) {
    puVar8 = (undefined1 *)*DAT_00105ef0;
    puVar8[5] = 0;
    _raw_spin_lock(puVar8 + 0xb8);
    *puVar8 = 0;
    puVar8[2] = 0;
    puVar8[6] = 1;
    puVar8[4] = 0;
    if (1 < *(uint *)(puVar8 + 0xa8)) {
      *(undefined4 *)(puVar8 + 0xa8) = 0;
    }
    _raw_spin_unlock(puVar8 + 0xb8);
    if (2 < DAT_0010d618) {
      _printk(&DAT_00128478);
    }
    __wake_up(puVar8 + 8,3,1,0);
    device_init_wakeup(param_1,0);
    return uVar2;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x800,0x18977c);
  (*pcVar1)();
}



// ===========================================================
// Function: bes_mspi_ready at 00189af4
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bes_mspi_ready(long param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  uint uVar4;
  code *pcVar5;
  ulong uVar6;
  undefined8 uVar7;
  long *plVar8;
  long lVar9;
  
  lVar9 = *(long *)(param_1 + 0x98);
  lVar1 = lVar9 + 0x58;
  _raw_spin_lock(lVar1);
  plVar8 = *(long **)(lVar9 + 0x60);
  if (*(long **)(*plVar8 + 8) != plVar8) {
    if (3 < DAT_0010d8d8) {
      _printk(&DAT_0011eba6,"bes_mspi_ready",plVar8);
    }
    _raw_spin_unlock(lVar1);
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x189b5c);
    (*pcVar5)();
  }
  uVar6 = __list_del_entry_valid(plVar8);
  if ((uVar6 & 1) != 0) {
    lVar2 = *plVar8;
    plVar3 = (long *)plVar8[1];
    *(long **)(lVar2 + 8) = plVar3;
    *plVar3 = lVar2;
  }
  *plVar8 = (long)plVar8;
  plVar8[1] = (long)plVar8;
  _raw_spin_unlock(lVar1);
  lVar1 = plVar8[3];
  lVar2 = plVar8[4];
  if (3 < DAT_0010d8d8) {
    _printk(&DAT_00122b15,"bes_mspi_ready",plVar8,(char)plVar8[2],lVar1,param_2,lVar2,param_3);
  }
  if ((lVar1 != param_2) || (lVar2 != param_3)) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x189d84);
    (*pcVar5)();
  }
  if ((char)plVar8[2] == '\0') {
    uVar7 = gpio_to_desc(*(undefined4 *)(lVar9 + 0x160));
    gpiod_set_raw_value(uVar7,1);
    uVar4 = state_ctxt;
    uVar6 = (ulong)state_ctxt;
    *(undefined8 *)(lVar9 + 0x168) = _jiffies;
    if ((uVar6 << 4 | 8) < 0x408) {
      (&DAT_00106100)[uVar6 * 4] = 1;
      if ((uVar4 < 0x40) && ((&DAT_00106108)[uVar6 * 2] = _jiffies, (uVar6 << 4 | 0xc) < 0x409)) {
        state_ctxt = uVar4 + 1 & 0x3f;
        (&DAT_00106104)[uVar6 * 8] = 1;
        uVar7 = gpio_to_desc(*(undefined4 *)(lVar9 + 0x164));
        gpiod_set_raw_value(uVar7,0);
        uVar4 = state_ctxt;
        uVar6 = (ulong)state_ctxt;
        if ((uVar6 << 4 | 8) < 0x408) {
          (&DAT_00106100)[uVar6 * 4] = 3;
          if ((uVar4 < 0x40) && ((&DAT_00106108)[uVar6 * 2] = _jiffies, (uVar6 << 4 | 0xc) < 0x409))
          {
            (&DAT_00106104)[uVar6 * 8] = 0;
            goto LAB_00189d18;
          }
        }
      }
    }
  }
  else {
    uVar7 = gpio_to_desc(*(undefined4 *)(lVar9 + 0x150));
    gpiod_set_raw_value(uVar7,1);
    uVar4 = state_ctxt;
    uVar6 = (ulong)state_ctxt;
    if ((uVar6 << 4 | 8) < 0x408) {
      (&DAT_00106100)[uVar6 * 4] = 2;
      if ((uVar4 < 0x40) && ((&DAT_00106108)[uVar6 * 2] = _jiffies, (uVar6 << 4 | 0xc) < 0x409)) {
        (&DAT_00106104)[uVar6 * 8] = 1;
LAB_00189d18:
        state_ctxt = uVar4 + 1 & 0x3f;
        return;
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(1,0x189d88);
  (*pcVar5)();
}



// ===========================================================
// Function: bes_mspi_tx_done_irq at 00189d88
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 bes_mspi_tx_done_irq(void)

{
  uint uVar1;
  code *pcVar2;
  ulong uVar3;
  
  if (3 < DAT_0010d8d8) {
    _printk(&DAT_00131797,"bes_mspi_tx_done_irq");
  }
  uVar1 = state_ctxt;
  uVar3 = (ulong)state_ctxt;
  if ((uVar3 << 4 | 8) < 0x408) {
    (&DAT_00106100)[uVar3 * 4] = 4;
    if ((uVar1 < 0x40) && ((&DAT_00106108)[uVar3 * 2] = _jiffies, (uVar3 << 4 | 0xc) < 0x409)) {
      state_ctxt = uVar1 + 1 & 0x3f;
      (&DAT_00106104)[uVar3 * 8] = 1;
      complete(&mspi_tx_ack_completion);
      return 1;
    }
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x189e44);
  (*pcVar2)();
}



// ===========================================================
// Function: bes_mspi_irq_poll at 00189e44
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int bes_mspi_irq_poll(void)

{
  int iVar1;
  long lVar2;
  
  iVar1 = gpio_request(DAT_00105f78,"irq-gpio");
  if (iVar1 == 0) {
    gpio_to_desc(DAT_00105f78);
    gpiod_direction_input();
    lVar2 = -0xfa - _jiffies;
    do {
      gpio_to_desc(DAT_00105f78);
      iVar1 = gpiod_get_raw_value();
      if (iVar1 == 1) {
        iVar1 = 0;
        goto LAB_00189ee8;
      }
      msleep(4);
    } while (lVar2 + _jiffies < 0);
    iVar1 = -0x10;
LAB_00189ee8:
    gpio_free(DAT_00105f78);
  }
  else if (0 < DAT_0010d8d8) {
    _printk(&DAT_0012b4c1,iVar1);
  }
  return iVar1;
}



// ===========================================================
// Function: bes_mspi_cmd_build at 00189f08
// ===========================================================

undefined8 * bes_mspi_cmd_build(void)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  
  uVar2 = (uint)(ushort)bes_mspi_default_blksize;
  if (DAT_00105f8f != 0) {
    uVar2 = (uint)DAT_00105f8f;
  }
  Hint_Prefetch(0x105fa4,2,0,1);
  do {
    iVar1 = DAT_00105fa4 + 1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(0x105fa4,0x10);
    if (bVar4) {
      cVar3 = ExclusiveMonitorsStatus();
      DAT_00105fa4 = iVar1;
    }
  } while (cVar3 != '\0');
  DataMemoryBarrier(2,3);
  if (iVar1 < 2) {
    DAT_00106060 = 0;
    DAT_00106068 = 0;
    DAT_00106050 = 0;
    DAT_00106058 = 0;
    DAT_00106040 = 0;
    DAT_00106048 = 0;
    DAT_00106030 = 0;
    DAT_00106038 = 0;
    DAT_00106020 = 0;
    DAT_00106028 = 0;
    DAT_00106010 = 0;
    DAT_00106018 = 0;
    DAT_00106000 = 0;
    DAT_00106008 = 0;
    DAT_00105ff0 = 0;
    DAT_00105ff8 = 0;
    DAT_00105fc0 = &DAT_00105fc0;
    DAT_00105fc8 = &DAT_00105fc0;
    DAT_00105fe8 = (ulong)uVar2;
    DAT_00105fd8 = 0;
    DAT_00105fe0 = DAT_00106080;
    memset(DAT_00106080,0x55,(ulong)uVar2);
    if (3 < DAT_0010d8d8) {
      _printk(&DAT_00129f21,"bes_mspi_cmd_build",&DAT_00105fc0,DAT_00105fd8,DAT_00105fe0);
    }
    return &DAT_00105fc0;
  }
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(0x800,0x189f60);
  (*pcVar5)();
}



// ===========================================================
// Function: bes_mspi_exchange at 0018a018
// ===========================================================

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int bes_mspi_exchange(long param_1,long *param_2)

{
  long *******ppppppplVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  int iVar6;
  uint uVar7;
  char cVar8;
  code *pcVar9;
  int iVar10;
  ulong uVar11;
  undefined *puVar12;
  undefined8 uVar13;
  char cVar14;
  long lVar15;
  undefined8 *puVar16;
  int iVar17;
  long *******local_100;
  long *******local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  code *local_e0;
  undefined8 *puStack_d8;
  undefined8 local_d0;
  ulong uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 *******local_a8;
  undefined8 *******local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 *******local_80;
  undefined8 *******pppppppuStack_78;
  long local_70;
  
  lVar15 = sp_el0;
  local_70 = *(long *)(lVar15 + 0x648);
  local_80 = &local_80;
  lVar15 = *(long *)(param_1 + 0x98);
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = (undefined8 *******)0x0;
  uStack_98 = 0;
  local_b0 = 0;
  local_a8 = (undefined8 *******)0x0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = (code *)0x0;
  puStack_d8 = (undefined8 *)0x0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_100 = (long *******)0x0;
  local_f8 = (long *******)0x0;
  pppppppuStack_78 = local_80;
  if (lVar15 == 0) {
                    /* WARNING: Does not return */
    pcVar9 = (code *)SoftwareBreakpoint(0x800,0x18a788);
    (*pcVar9)();
  }
  if (*(char *)(param_1 + 0x3a5) != ' ') {
                    /* WARNING: Does not return */
    pcVar9 = (code *)SoftwareBreakpoint(0x800,0x18a78c);
    (*pcVar9)();
  }
  bes_mspi_lock(lVar15);
  ppppppplVar1 = (long *******)(param_2 + 0x12);
  lVar2 = lVar15 + 0x58;
  lVar3 = lVar15 + 8;
  iVar10 = 0;
LAB_0018a0d0:
  iVar17 = iVar10;
  local_100 = (long *******)&local_100;
  uStack_98 = 0;
  local_b0 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  puStack_d8 = &local_90;
  local_e0 = bes_mspi_exchange_done_cfi_jt;
  local_f8 = local_100;
  local_a8 = &local_a8;
  local_a0 = &local_a8;
  uVar11 = __list_add_valid(ppppppplVar1,&local_100,&local_100);
  if ((uVar11 & 1) != 0) {
    param_2[0x12] = (long)&local_100;
    param_2[0x13] = (long)&local_100;
    local_100 = ppppppplVar1;
    local_f8 = ppppppplVar1;
  }
  _raw_spin_lock(lVar2);
  puVar16 = *(undefined8 **)(lVar15 + 0x68);
  uVar11 = __list_add_valid(param_2,puVar16,lVar15 + 0x60);
  if ((uVar11 & 1) != 0) {
    *(long **)(lVar15 + 0x68) = param_2;
    *param_2 = lVar15 + 0x60;
    param_2[1] = (long)puVar16;
    *puVar16 = param_2;
  }
  _raw_spin_unlock(lVar2);
  if (3 < DAT_0010d8d8) {
    _printk(&DAT_0011bffd,"bes_mspi_exchange",param_2,(int)param_2[5],(char)param_2[2]);
  }
  uVar7 = state_ctxt;
  uVar11 = (ulong)state_ctxt;
  if (((0x407 < (uVar11 << 4 | 8)) || ((&DAT_00106100)[uVar11 * 4] = 5, 0x3f < uVar7)) ||
     ((&DAT_00106108)[uVar11 * 2] = _jiffies, 0x408 < (uVar11 << 4 | 0xc))) {
LAB_0018a77c:
                    /* WARNING: Does not return */
    pcVar9 = (code *)SoftwareBreakpoint(1,0x18a780);
    (*pcVar9)();
  }
  state_ctxt = uVar7 + 1 & 0x3f;
  (&DAT_00106104)[uVar11 * 8] = 0;
  iVar10 = spi_async(param_1,&local_100);
  if (iVar10 == 0) {
    while (iVar10 = wait_for_completion_interruptible_timeout(&local_90,0xfa), uVar7 = state_ctxt,
          iVar10 < 1) {
      if (0 < DAT_0010d8d8) {
        _printk(&DAT_0012aa68,"bes_mspi_exchange");
      }
    }
    uVar11 = (ulong)state_ctxt;
    if (((0x407 < (uVar11 << 4 | 8)) || ((&DAT_00106100)[uVar11 * 4] = 5, 0x3f < uVar7)) ||
       ((&DAT_00106108)[uVar11 * 2] = _jiffies, 0x408 < (uVar11 << 4 | 0xc))) goto LAB_0018a77c;
    state_ctxt = uVar7 + 1 & 0x3f;
    (&DAT_00106104)[uVar11 * 8] = 1;
    if ((char)param_2[2] != '\0') {
      uVar13 = gpio_to_desc(*(undefined4 *)(lVar15 + 0x150));
      gpiod_set_raw_value(uVar13,0);
      uVar7 = state_ctxt;
      uVar11 = (ulong)state_ctxt;
      if (((0x407 < (uVar11 << 4 | 8)) || ((&DAT_00106100)[uVar11 * 4] = 2, 0x3f < uVar7)) ||
         ((&DAT_00106108)[uVar11 * 2] = _jiffies, 0x408 < (uVar11 << 4 | 0xc))) goto LAB_0018a77c;
      state_ctxt = uVar7 + 1 & 0x3f;
      (&DAT_00106104)[uVar11 * 8] = 0;
      iVar10 = wait_for_completion_interruptible_timeout(&mspi_tx_ack_completion,0x19);
      if (0 < iVar10) {
        mspi_tx_ack_completion = 0;
        goto LAB_0018a3e8;
      }
      mspi_tx_ack_completion = 0;
      if (iVar10 == 0) {
        iVar10 = iVar17 + 1;
        if (3 < iVar10) {
          if (0 < DAT_0010d8d8) {
            _printk(&DAT_0011c018);
            iVar10 = -0x6e;
            cVar8 = mspi_rx_error_cnt;
            cVar14 = mspi_rx_crc_err_cnt;
            goto LAB_0018a66c;
          }
          goto LAB_0018a668;
        }
        if (0 < DAT_0010d8d8) {
          _printk(&DAT_00129f6e,iVar10);
        }
        uVar13 = _raw_spin_lock_irqsave(lVar3);
        *(undefined4 *)(lVar15 + 0x30) = 0;
        _raw_spin_unlock_irqrestore(lVar3,uVar13);
        __wake_up(lVar15 + 0x10,3,1,0);
        msleep(1);
        bes_mspi_lock(lVar15);
      }
      else {
        if (0 < DAT_0010d8d8) {
          _printk(&DAT_00122b2d);
        }
        iVar10 = iVar17 + 1;
        if (3 < iVar17 + 1) {
LAB_0018a668:
          iVar10 = -0x6e;
          cVar8 = mspi_rx_error_cnt;
          cVar14 = mspi_rx_crc_err_cnt;
LAB_0018a66c:
          mspi_rx_crc_err_cnt = cVar14;
          mspi_rx_error_cnt = cVar8;
          uVar13 = _raw_spin_lock_irqsave(lVar3);
          *(undefined4 *)(lVar15 + 0x30) = 0;
          _raw_spin_unlock_irqrestore(lVar3,uVar13);
          __wake_up(lVar15 + 0x10,3,1,0);
          if ((long *)(lVar15 + 0x70) == param_2) {
            *(undefined4 *)(lVar15 + 0x54) = 0;
          }
          else {
            if (3 < DAT_0010d8d8) {
              _printk(&DAT_0011ca94,"bes_mspi_free_one_transfer",param_2);
            }
            kfree(param_2);
          }
          lVar15 = sp_el0;
          if (*(long *)(lVar15 + 0x648) != local_70) {
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail();
          }
          return iVar10;
        }
      }
      goto LAB_0018a0d0;
    }
    uVar13 = gpio_to_desc(*(undefined4 *)(lVar15 + 0x160));
    gpiod_set_raw_value(uVar13,0);
    uVar7 = state_ctxt;
    uVar11 = (ulong)state_ctxt;
    if (((0x407 < (uVar11 << 4 | 8)) || ((&DAT_00106100)[uVar11 * 4] = 1, 0x3f < uVar7)) ||
       ((&DAT_00106108)[uVar11 * 2] = _jiffies, 0x408 < (uVar11 << 4 | 0xc))) goto LAB_0018a77c;
    state_ctxt = uVar7 + 1 & 0x3f;
    (&DAT_00106104)[uVar11 * 8] = 0;
LAB_0018a3e8:
    iVar6 = (int)uStack_c8;
    if (3 < DAT_0010d8d8) {
      _printk(&DAT_0012cb59,"bes_mspi_exchange",param_2,local_d0._4_4_,uStack_c8 & 0xffffffff,
              (char)param_2[2]);
      iVar6 = (int)uStack_c8;
    }
    if (((iVar6 == 0) && (local_d0._4_4_ != 0)) && ((int)param_2[5] == local_d0._4_4_)) {
      if ((char)param_2[2] == '\0') {
        mspi_rx_error_cnt = '\0';
      }
      iVar10 = bes_mspi_recv_check(lVar15,param_2);
      cVar8 = mspi_rx_error_cnt;
      cVar14 = mspi_rx_crc_err_cnt;
      if ((char)param_2[2] == '\0') {
        if (iVar10 == 0) {
          mspi_rx_crc_err_cnt = '\0';
          cVar14 = mspi_rx_crc_err_cnt;
        }
        else {
          cVar14 = mspi_rx_crc_err_cnt + '\x01';
          if (0 < DAT_0010d8d8) {
            cVar14 = mspi_rx_crc_err_cnt + '\x01';
            puVar12 = &DAT_00127bd2;
            mspi_rx_crc_err_cnt = mspi_rx_crc_err_cnt + '\x01';
            goto LAB_0018a5c8;
          }
        }
      }
      goto LAB_0018a66c;
    }
    if (DAT_0010d8d8 < 1) {
      cVar8 = (char)param_2[2];
    }
    else {
      _printk(&DAT_0011ebd4,"bes_mspi_exchange",param_2,local_d0._4_4_,iVar6,(char)param_2[2]);
      cVar8 = (char)param_2[2];
    }
    cVar14 = mspi_rx_crc_err_cnt;
    if (cVar8 != '\0') {
      if (3 < iVar17 + 1) {
        iVar10 = -5;
        if (iVar6 != 0) {
          iVar10 = iVar6;
        }
        cVar8 = mspi_rx_error_cnt;
        if (0 < DAT_0010d8d8) {
          puVar12 = &DAT_001217fa;
          goto LAB_0018a5f8;
        }
        goto LAB_0018a66c;
      }
      iVar10 = iVar17 + 1;
      if (0 < DAT_0010d8d8) {
        puVar12 = &DAT_0011d541;
        goto LAB_0018a440;
      }
      goto LAB_0018a0d0;
    }
    iVar10 = -5;
    if (iVar6 != 0) {
      iVar10 = iVar6;
    }
    cVar8 = mspi_rx_error_cnt + '\x01';
    if (DAT_0010d8d8 < 1) goto LAB_0018a66c;
    cVar14 = mspi_rx_error_cnt + '\x01';
    puVar12 = &DAT_00131e37;
    mspi_rx_error_cnt = mspi_rx_error_cnt + '\x01';
  }
  else {
    if (0 < DAT_0010d8d8) {
      _printk(&DAT_0012509f,"bes_mspi_exchange",0x29f,iVar10);
    }
    _raw_spin_lock(lVar2);
    uVar11 = __list_del_entry_valid(param_2);
    if ((uVar11 & 1) != 0) {
      lVar4 = *param_2;
      plVar5 = (long *)param_2[1];
      *(long **)(lVar4 + 8) = plVar5;
      *plVar5 = lVar4;
    }
    *param_2 = (long)param_2;
    param_2[1] = (long)param_2;
    _raw_spin_unlock(lVar2);
    cVar14 = mspi_rx_crc_err_cnt;
    if ((char)param_2[2] != '\0') {
      if (3 < iVar17 + 1) {
        cVar8 = mspi_rx_error_cnt;
        if (0 < DAT_0010d8d8) {
          puVar12 = &DAT_001237a1;
LAB_0018a5f8:
          _printk(puVar12,"bes_mspi_exchange");
          cVar8 = mspi_rx_error_cnt;
          cVar14 = mspi_rx_crc_err_cnt;
        }
        goto LAB_0018a66c;
      }
      iVar10 = iVar17 + 1;
      if (0 < DAT_0010d8d8) {
        puVar12 = &DAT_0012beb7;
LAB_0018a440:
        _printk(puVar12,"bes_mspi_exchange",iVar17 + 1);
        iVar10 = iVar17 + 1;
      }
      goto LAB_0018a0d0;
    }
    cVar8 = mspi_rx_error_cnt + '\x01';
    if (DAT_0010d8d8 < 1) goto LAB_0018a66c;
    cVar14 = mspi_rx_error_cnt + '\x01';
    puVar12 = &DAT_00129f41;
    mspi_rx_error_cnt = mspi_rx_error_cnt + '\x01';
  }
LAB_0018a5c8:
  _printk(puVar12,"bes_mspi_exchange",cVar14);
  cVar8 = mspi_rx_error_cnt;
  cVar14 = mspi_rx_crc_err_cnt;
  goto LAB_0018a66c;
}



// ===========================================================
// Function: bes_mspi_data_push at 0018a988
// ===========================================================

void bes_mspi_data_push(long *param_1)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  
  if ((char)param_1[0xc] != '\x01') {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x18aa8c);
    (*pcVar2)();
  }
  if (*param_1 != param_1[1]) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x18aa90);
    (*pcVar2)();
  }
  if (DAT_0010d8d8 < 4) {
    cVar1 = *(char *)((long)param_1 + 0x62);
  }
  else {
    _printk(&DAT_0012aac2,"bes_mspi_data_push",1,*(undefined1 *)((long)param_1 + 0x61));
    cVar1 = *(char *)((long)param_1 + 0x62);
  }
  if (cVar1 != '\0') {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x18aa78);
    (*pcVar2)();
  }
  iVar3 = bes_mspi_tx_aggr_try_add(param_1,1);
  if (iVar3 != 0) {
    iVar3 = bes_mspi_tx_aggr_finish();
    if (iVar3 != 0) goto LAB_0018a9e4;
    iVar3 = bes_mspi_tx_aggr_try_add(param_1,1);
    if (iVar3 != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x18aa7c);
      (*pcVar2)();
    }
  }
  iVar3 = 0;
  if (((*(char *)((long)param_1 + 0x61) != '\0') || (DAT_00105f8c <= DAT_00106090)) ||
     (DAT_00105f8d <= DAT_00106092)) {
    iVar3 = bes_mspi_tx_aggr_finish();
  }
  if (iVar3 == 0) {
    return;
  }
LAB_0018a9e4:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x800,0x18a9e8);
  (*pcVar2)();
}



// ===========================================================
// Function: bes_mspi_tx_aggr_try_add at 0018ac0c
// ===========================================================

undefined4 bes_mspi_tx_aggr_try_add(long param_1,uint param_2)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  byte bVar4;
  ushort uVar5;
  ushort uVar6;
  code *pcVar7;
  undefined4 uVar8;
  uint uVar9;
  ulong uVar10;
  long lVar11;
  long *plVar12;
  uint uVar13;
  ulong uVar14;
  int iVar15;
  ulong uVar16;
  uint uVar17;
  ulong uVar18;
  long lVar19;
  uint uVar20;
  
  if (DAT_00106090 < DAT_00105f8c) {
    bVar4 = *(byte *)(param_1 + 0x60);
    if (bVar4 == 0) {
      uVar8 = 0xfffffffe;
      if (DAT_00106092 <= DAT_00105f8d) {
        uVar8 = 0;
      }
    }
    else {
      uVar10 = 0;
      uVar9 = 0;
      do {
        if (bVar4 - 8 < 0xfffffff9) goto LAB_0018af30;
        plVar1 = (long *)(param_1 + uVar10 * 0x10);
        for (plVar12 = (long *)*plVar1; plVar12 != plVar1; plVar12 = (long *)*plVar12) {
          uVar9 = uVar9 + *(ushort *)(plVar12 + 3);
        }
        uVar10 = uVar10 + 1;
        uVar9 = uVar9 + 3 & 0xfffffffc;
      } while (uVar10 != bVar4);
      if (DAT_00105f8d < uVar9) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x800,0x18af38);
        (*pcVar7)();
      }
      uVar8 = 0xfffffffe;
      if (uVar9 + DAT_00106092 <= (uint)DAT_00105f8d) {
        uVar10 = 0;
        iVar15 = 0;
        do {
          if (uVar10 == 7) {
LAB_0018af30:
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x18af34);
            (*pcVar7)();
          }
          plVar1 = (long *)(param_1 + uVar10 * 0x10);
          for (plVar12 = (long *)*plVar1; uVar6 = DAT_00105f8d, plVar12 != plVar1;
              plVar12 = (long *)*plVar12) {
            uVar5 = *(ushort *)(plVar12 + 3);
            if (uVar5 == 0) {
              uVar9 = 0;
            }
            else {
              lVar19 = plVar12[2];
              uVar20 = 0;
              uVar9 = 0;
              uVar18 = (ulong)DAT_00106092;
              uVar14 = (ulong)DAT_00105f8f - 8;
              do {
                lVar11 = DAT_001060a8;
                uVar16 = uVar18 & 0xffff;
                uVar13 = (uint)uVar14;
                if (uVar14 <= uVar16) {
                  uVar13 = (uint)uVar6;
                }
                uVar17 = (uint)uVar18;
                lVar3 = 8;
                if (uVar14 <= uVar16) {
                  lVar3 = 0x10;
                }
                uVar13 = uVar13 - uVar17 & 0xffff;
                uVar2 = uVar5 - uVar9 & 0xffff;
                if (uVar13 <= uVar2) {
                  uVar2 = uVar13;
                }
                if (3 < DAT_0010d8d8) {
                  _printk(&DAT_0012bf01,"bes_mspi_aggr_copy",(uint)uVar5,uVar20,uVar17 & 0xffff,
                          uVar13,uVar2);
                }
                memcpy((void *)(lVar11 + uVar16 + lVar3),(void *)(lVar19 + (ulong)uVar20),
                       (ulong)uVar2);
                uVar9 = uVar2 + uVar20;
                uVar18 = (ulong)(uVar2 + uVar17);
                uVar20 = uVar9 & 0xffff;
              } while (uVar20 < uVar5);
              uVar9 = (uint)*(ushort *)(plVar12 + 3);
            }
            iVar15 = iVar15 + uVar9;
          }
          DAT_00106090 = DAT_00106090 + 1;
          uVar9 = (uint)DAT_00106092 + (iVar15 + 3U & 0xfffffffc);
          DAT_00106092 = (ushort)uVar9;
          plVar12 = DAT_00105280;
          if (3 < DAT_0010d8d8) {
            _printk(&DAT_0012b4f6,"bes_mspi_tx_aggr_try_add",uVar10 & 0xffffffff,
                    *(undefined1 *)(param_1 + 0x61),iVar15,DAT_00106090,uVar9 & 0xffff);
            plVar12 = DAT_00105280;
          }
          DAT_00105280 = plVar12;
          if (((param_2 & 1) != 0) && (plVar1 != (long *)*plVar1)) {
            lVar19 = param_1 + uVar10 * 0x10;
            lVar11 = *plVar1;
            DAT_00105280 = *(long **)(lVar19 + 8);
            *(long **)(lVar11 + 8) = plVar12;
            *plVar12 = lVar11;
            *DAT_00105280 = (long)&DAT_00105278;
            *plVar1 = (long)plVar1;
            *(long **)(lVar19 + 8) = plVar1;
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < *(byte *)(param_1 + 0x60));
        uVar8 = 0;
      }
    }
  }
  else {
    uVar8 = 0xffffffff;
  }
  return uVar8;
}



// ===========================================================
// Function: bes_mspi_tx_aggr_finish at 0018af3c
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bes_mspi_tx_aggr_finish(void)

{
  undefined8 *puVar1;
  ushort uVar2;
  uint uVar3;
  long lVar4;
  ushort uVar5;
  undefined1 uVar6;
  ushort uVar7;
  code *pcVar8;
  undefined2 uVar9;
  long lVar10;
  undefined2 *puVar11;
  ulong uVar12;
  ulong uVar13;
  undefined8 *puVar14;
  ulong uVar15;
  
  if (3 < DAT_0010d8d8) {
    _printk(&DAT_0011cadb,"bes_mspi_tx_aggr_finish",DAT_00106090,DAT_00106092);
  }
  uVar5 = DAT_00105f8f;
  uVar13 = (ulong)DAT_00106092;
  uVar15 = (ulong)DAT_00105f8f - 8;
  uVar2 = DAT_00105f8f;
  if (uVar15 < uVar13) {
    uVar2 = DAT_00106092 + 0x10;
  }
  if (3 < DAT_0010d8d8) {
    _printk(&DAT_00122b6b,"bes_mspi_aggr_build",DAT_00106092,uVar2,uVar13 <= uVar15);
  }
  puVar14 = DAT_001060a8;
  lVar10 = kmem_cache_alloc_trace(_cfg80211_get_bss,0xdc0,0xb8);
  if (lVar10 == 0) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x800,0x18aff8);
    (*pcVar8)();
  }
  if (3 < DAT_0010d8d8) {
    _printk(&DAT_0011caa2,"bes_mspi_alloc_one_transfer",lVar10,DAT_00106094,DAT_001060e0,
            DAT_001060ee,uVar2,puVar14,0);
  }
  *(long *)lVar10 = lVar10;
  *(long *)(lVar10 + 8) = lVar10;
  *(uint *)(lVar10 + 0x28) = (uint)uVar2;
  if (puVar14 == (undefined8 *)0x0) {
    puVar14 = *(undefined8 **)(lVar10 + 0x18);
  }
  else {
    *(undefined8 **)(lVar10 + 0x18) = puVar14;
  }
  uVar7 = DAT_00106092;
  uVar6 = DAT_00106090;
  *(undefined1 *)(lVar10 + 0x10) = 1;
  *(undefined1 *)((long)puVar14 + 4) = 1;
  *(undefined1 *)((long)puVar14 + 5) = uVar6;
  *(ushort *)((long)puVar14 + 6) = uVar7;
  puVar11 = (undefined2 *)((long)puVar14 + 2);
  *puVar11 = (short)DAT_00106094;
  uVar3 = state_ctxt;
  uVar12 = (ulong)state_ctxt;
  DAT_00106094 = DAT_00106094 + 1;
  if ((uVar12 << 4 | 8) < 0x408) {
    uVar9 = *puVar11;
    (&DAT_00106100)[uVar12 * 4] = 6;
    if ((uVar3 < 0x40) && ((&DAT_00106108)[uVar12 * 2] = _jiffies, (uVar12 << 4 | 0xc) < 0x409)) {
      state_ctxt = uVar3 + 1 & 0x3f;
      (&DAT_00106104)[uVar12 * 8] = uVar9;
      uVar9 = crc16(0,puVar11,uVar5 - 2);
      *(undefined2 *)puVar14 = uVar9;
      if (uVar13 <= uVar15) {
LAB_0018b180:
        bes_mspi_exchange(DAT_00105f50,lVar10);
        DAT_00106092 = 0;
        DAT_00106090 = 0;
        return;
      }
      uVar3 = (uint)(ushort)bes_mspi_default_blksize;
      if (DAT_00105f8f != 0) {
        uVar3 = (uint)DAT_00105f8f;
      }
      lVar4 = 0x20;
      if (*(char *)(lVar10 + 0x10) != '\0') {
        lVar4 = 0x18;
      }
      puVar1 = (undefined8 *)(*(long *)(lVar10 + lVar4) + (ulong)uVar3);
      *puVar1 = *puVar14;
      puVar11 = (undefined2 *)((long)puVar1 + 2);
      *puVar11 = (short)DAT_00106094;
      uVar3 = state_ctxt;
      uVar13 = (ulong)state_ctxt;
      DAT_00106094 = DAT_00106094 + 1;
      if ((uVar13 << 4 | 8) < 0x408) {
        uVar9 = *puVar11;
        (&DAT_00106100)[uVar13 * 4] = 6;
        if ((uVar3 < 0x40) && ((&DAT_00106108)[uVar13 * 2] = _jiffies, (uVar13 << 4 | 0xc) < 0x409))
        {
          state_ctxt = uVar3 + 1 & 0x3f;
          (&DAT_00106104)[uVar13 * 8] = uVar9;
          uVar9 = crc16(0,puVar11,(uVar2 - uVar5) + -2);
          *(undefined2 *)puVar1 = uVar9;
          goto LAB_0018b180;
        }
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar8 = (code *)SoftwareBreakpoint(1,0x18b24c);
  (*pcVar8)();
}



