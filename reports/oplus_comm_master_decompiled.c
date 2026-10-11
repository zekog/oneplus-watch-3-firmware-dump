// ===========================================================
// Function: __cfi_check at 00113000
// ===========================================================

void __cfi_check(long param_1,code *param_2,undefined8 param_3)

{
  code *pcVar1;
  
  if (param_1 < 0x1988e11120acdc5c) {
    if (param_1 < -0x2311c9b71e053a74) {
      if (param_1 < -0x5324bef43a497a1c) {
        if (param_1 == -0x6c33d3356ff62719) {
          pcVar1 = ccch_write_cfi_jt;
          goto LAB_00113318;
        }
        if (param_1 != -0x57be845bca9148ef) goto LAB_001132d4;
        pcVar1 = snshub_suspend_cfi_jt;
      }
      else {
        if (param_1 == -0x5324bef43a497a1c) {
          pcVar1 = log_store_cfi_jt;
LAB_001132e4:
          if (((ulong)((long)param_2 - (long)pcVar1) >> 2 | (long)param_2 << 0x3e) < 5) {
            return;
          }
          goto LAB_001132d4;
        }
        if (param_1 != -0x3987c0e26ee29729) goto LAB_001132d4;
        pcVar1 = s2m_int_irq_fn_cfi_jt;
      }
LAB_0011329c:
      if (((ulong)((long)param_2 - (long)pcVar1) >> 2 | (long)param_2 << 0x3e) < 2) {
        return;
      }
      goto LAB_001132d4;
    }
    if (param_1 < 0x2b3a43e29242445) {
      if (param_1 != -0x2311c9b71e053a74) {
        if (param_1 != -0x8dc801903aca538) goto LAB_001132d4;
        pcVar1 = spidev_open_cfi_jt;
        goto LAB_0011329c;
      }
      pcVar1 = ccch_read_cfi_jt;
    }
    else if (param_1 == 0x2b3a43e29242445) {
      pcVar1 = init_module_cfi_jt;
    }
    else {
      if (param_1 != 0x7ff5a213d37b1a6) goto LAB_001132d4;
      pcVar1 = spidev_read_cfi_jt;
    }
  }
  else if (param_1 < 0x641d19c7be126e92) {
    if (param_1 < 0x321969b888d4949e) {
      if (param_1 == 0x1988e11120acdc5c) {
        pcVar1 = spidev_probe_cfi_jt;
        goto LAB_0011329c;
      }
      if (param_1 != 0x1d7ed092cb04d3f1) goto LAB_001132d4;
      pcVar1 = spidev_write_cfi_jt;
    }
    else {
      if (param_1 != 0x321969b888d4949e) {
        if (param_1 != 0x4a47875dcd644744) goto LAB_001132d4;
        pcVar1 = log_show_cfi_jt;
        goto LAB_001132e4;
      }
      pcVar1 = no_llseek_cfi_jt;
    }
  }
  else if (param_1 < 0x7d617f579d92759b) {
    if (param_1 == 0x641d19c7be126e92) {
      if (((ulong)(param_2 + -0x118164) >> 2 | (long)param_2 << 0x3e) < 4) {
        return;
      }
      goto LAB_001132d4;
    }
    if (param_1 != 0x77b452a0029d4539) goto LAB_001132d4;
    pcVar1 = slave_ready_cb_cfi_jt;
  }
  else if (param_1 == 0x7d617f579d92759b) {
    pcVar1 = ccch_open_cfi_jt;
  }
  else {
    if (param_1 != 0x7e04a0fb7ad8bcd5) goto LAB_001132d4;
    pcVar1 = cleanup_module_cfi_jt;
  }
LAB_00113318:
  if (param_2 == pcVar1) {
    return;
  }
LAB_001132d4:
  __cfi_check_fail(param_3);
  return;
}



// ===========================================================
// Function: __cfi_check_fail at 00113324
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
  pcVar1 = (code *)SoftwareBreakpoint(0x5502,0x113370);
  (*pcVar1)();
}



// ===========================================================
// Function: ccch_write at 00113370
// ===========================================================

undefined4 ccch_write(long param_1,void *param_2,int param_3,uint param_4)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined2 *__s;
  
  if (param_1 == 0) {
    if (DAT_001105a8 != 0) {
      _printk(&DAT_001112d5,"ccch_write",0x5a4);
    }
  }
  else {
    if (*(int *)(param_1 + 0x18) != 0) {
      __s = *(undefined2 **)(param_1 + 0x148);
      mutex_lock(param_1 + 0x118);
      memset(__s,0,0x3ff4);
      uVar1 = *(undefined2 *)(param_1 + 0x1c);
      __s[1] = (short)param_3;
      *__s = uVar1;
      memcpy(__s + 2,param_2,(long)param_3);
      if (DAT_00110618 != 0) {
        _printk(&DAT_00110a82,PTR_s_packet_to_fifo_00110610,param_3,*(undefined8 *)(param_1 + 0x20))
        ;
        print_hex_dump(&DAT_00110c3f,&DAT_00111a43,2,0x10,1,__s + 2,(long)param_3,1);
      }
      uVar2 = wfifo_in(param_1,param_4 & 1);
      mutex_unlock(param_1 + 0x118);
      return uVar2;
    }
    if (DAT_001105a8 != 0) {
      _printk(&DAT_00111f89,"ccch_write",0x5a9,*(undefined8 *)(param_1 + 0x20));
    }
  }
  return 0xffffffea;
}



// ===========================================================
// Function: wfifo_in at 001134d8
// ===========================================================

ulong wfifo_in(long param_1,ulong param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ushort uVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  int iVar8;
  ulong uVar9;
  
  if (param_1 == 0) {
    if (DAT_001105a8 == 0) {
      uVar9 = 0xfffffffffffffff2;
    }
    else {
      _printk(&DAT_001117dd,"wfifo_in",0x575);
      uVar9 = 0xfffffffffffffff2;
    }
  }
  else {
    lVar6 = *(long *)(param_1 + 8);
    lVar7 = *(long *)(param_1 + 0x148);
    lVar3 = param_1 + 0xa0;
    iVar8 = 1;
    uVar4 = *(ushort *)(lVar7 + 2);
    do {
      if (param_1 + 0x88 == 0 || lVar7 == 0) {
        if (DAT_001105a8 != 0) {
          _printk(&DAT_001120a3,"cdev_fifo_in_frame",0x3c8);
        }
        uVar9 = 0xffffffffffffffea;
      }
      else {
        uVar1 = *(ushort *)(lVar7 + 2) + 4;
        mutex_lock(lVar3);
        if (uVar1 < (*(int *)(param_1 + 0x90) - *(int *)(param_1 + 0x88)) + *(int *)(param_1 + 0x8c)
                    + 1U) {
          __kfifo_in(param_1 + 0x88,lVar7,uVar1);
          mutex_unlock(lVar3);
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + 1;
          up(lVar6 + 0x118);
          return (ulong)uVar4;
        }
        mutex_unlock(lVar3);
        uVar9 = 0xfffffffffffffff4;
      }
      iVar2 = *(int *)(param_1 + 600) + 1;
      *(int *)(param_1 + 600) = iVar2;
      if ((iVar8 == 4) && (iVar2 < 10)) {
        if (DAT_001105a8 != 0) {
LAB_001135b8:
          _printk(&DAT_00111245,"wfifo_in",0x591,*(undefined8 *)(param_1 + 0x20),iVar8,iVar2,
                  *(undefined4 *)(param_1 + 0x25c),*(undefined4 *)(param_1 + 0x260));
        }
      }
      else if ((iVar2 * -0x33333333 + 0x19999998U >> 1 | iVar2 * -0x80000000) < 0x19999999 &&
               DAT_001105a8 != 0) goto LAB_001135b8;
      if ((param_2 & 1) != 0) {
        if (DAT_001105d8 == 0) {
          return uVar9;
        }
        _printk(&DAT_00110a02,"wfifo_in",0x595);
        return uVar9;
      }
      uVar5 = 0x1e;
      if (*(short *)(param_1 + 0x1c) != 1) {
        uVar5 = 10;
      }
      msleep(uVar5);
      iVar8 = iVar8 + 1;
    } while (iVar8 != 5);
  }
  return uVar9;
}



// ===========================================================
// Function: ccch_read at 00113700
// ===========================================================

uint ccch_read(long param_1,void *param_2,uint param_3,uint param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  long lVar6;
  
  if (param_2 == (void *)0x0) {
    if (DAT_001105a8 != 0) {
      puVar4 = &DAT_00111d51;
      uVar5 = 0x5f9;
LAB_00113828:
      _printk(puVar4,"ccch_read",uVar5);
      return 0xffffffea;
    }
  }
  else if (param_1 == 0) {
    if (DAT_001105a8 != 0) {
      puVar4 = &DAT_0011154f;
      uVar5 = 0x5fe;
      goto LAB_00113828;
    }
  }
  else {
    if (*(int *)(param_1 + 0x18) != 0) {
      lVar6 = *(long *)(param_1 + 0x150);
      mutex_lock(param_1 + 0xe8);
      uVar3 = rfifo_out(param_1,param_4 & 1);
      if ((int)uVar3 < 1) {
        if (DAT_001105d8 != 0) {
          _printk(&DAT_00110fcb,"ccch_read",0x617,*(undefined8 *)(param_1 + 0x20),uVar3,
                  *(undefined2 *)(lVar6 + 2));
        }
      }
      else {
        uVar1 = *(ushort *)(lVar6 + 2);
        iVar2 = uVar1 - param_3;
        uVar3 = (uint)uVar1;
        if ((iVar2 != 0 && (int)param_3 <= (int)(uint)uVar1) && (uVar3 = param_3, DAT_001105a8 != 0)
           ) {
          _printk(&DAT_00111e69,"ccch_read",0x610,iVar2);
        }
        memcpy(param_2,(void *)(lVar6 + 4),(long)(int)uVar3);
        if (DAT_00110638 != 0) {
          _printk(&DAT_00110890,PTR_s_data_to_user_00110630,*(undefined2 *)(lVar6 + 2),
                  *(undefined8 *)(param_1 + 0x20));
          print_hex_dump(&DAT_00110c3f,&DAT_00111a43,2,0x10,1,(void *)(lVar6 + 4),
                         *(undefined2 *)(lVar6 + 2),1);
        }
      }
      mutex_unlock(param_1 + 0xe8);
      return uVar3;
    }
    if (DAT_001105a8 != 0) {
      _printk(&DAT_00112406,"ccch_read",0x603,*(undefined8 *)(param_1 + 0x20));
      return 0xffffffea;
    }
  }
  return 0xffffffea;
}



// ===========================================================
// Function: rfifo_out at 001138e4
// ===========================================================

undefined8 rfifo_out(long param_1,ulong param_2)

{
  int iVar1;
  undefined8 uVar2;
  void *__s;
  
  if (param_1 == 0) {
    if (DAT_001105a8 != 0) {
      _printk(&DAT_00111800,"rfifo_out",0x5ce);
    }
  }
  else {
    __s = *(void **)(param_1 + 0x150);
    memset(__s,0,0x3ff4);
    iVar1 = down_trylock(param_1 + 0x70);
    if (iVar1 != 0) {
      __pm_relax(param_1 + 0x158);
      if ((param_2 & 1) != 0) {
        if (DAT_001105d8 == 0) {
          return 0;
        }
        _printk(&DAT_00111fae,"rfifo_out",0x5db);
        return 0;
      }
      iVar1 = down_interruptible(param_1 + 0x70);
      if (iVar1 != 0) {
        return 0xfffffffc;
      }
    }
    if (*(int *)(param_1 + 0x18) != 0) {
      uVar2 = cdev_fifo_out_frame(param_1 + 0x28,__s);
      return uVar2;
    }
    if (DAT_001105a8 != 0) {
      _printk(&DAT_00111c93,"rfifo_out",0x5e9,*(undefined8 *)(param_1 + 0x20));
    }
  }
  return 0xfffffff2;
}



// ===========================================================
// Function: cdev_fifo_out_frame at 00113a00
// ===========================================================

int cdev_fifo_out_frame(undefined8 *param_1,long param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_1 == (undefined8 *)0x0) || (param_2 == 0)) {
    if (DAT_001105a8 == 0) {
      iVar2 = -0x16;
    }
    else {
      _printk(&DAT_001120a3,"cdev_fifo_out_frame",0x3df);
      iVar2 = -0x16;
    }
  }
  else {
    mutex_lock(param_1 + 3);
    iVar2 = __kfifo_out(param_1,param_2,4);
    uVar1 = *(ushort *)(param_2 + 2);
    uVar4 = (uint)uVar1;
    if (((iVar2 == 4) && (uVar1 != 0)) &&
       (uVar3 = __kfifo_out(param_1,param_2 + 4,uVar1), uVar3 == uVar4)) {
      iVar2 = 4;
    }
    else {
      if (DAT_001105a8 != 0) {
        _printk(&DAT_001122c1,"cdev_fifo_out_frame",0x3eb,iVar2,uVar4);
        if (DAT_001105a8 != 0) {
          _printk(&DAT_00111822,"cdev_fifo_out_frame",0x3ed);
        }
      }
      *param_1 = 0;
      do {
        iVar2 = down_trylock(param_1 + 9);
      } while (iVar2 == 0);
      uVar4 = 0;
      iVar2 = -0xe;
    }
    mutex_unlock(param_1 + 3);
    iVar2 = iVar2 + uVar4;
  }
  return iVar2;
}



// ===========================================================
// Function: ccch_open at 00113b38
// ===========================================================

long ccch_open(char *param_1)

{
  undefined *puVar1;
  int iVar2;
  size_t sVar3;
  long lVar4;
  
  puVar1 = g_cdev_info_list;
  if (param_1 == (char *)0x0) {
    if (DAT_001105a8 == 0) {
      return 0;
    }
    _printk(&DAT_001116d8,"get_cdev_by_name",0x3a5);
  }
  else {
    sVar3 = strlen(g_cdev_info_list);
    iVar2 = strncmp(param_1,puVar1,sVar3);
    puVar1 = PTR_s_dcc_datah_001104e0;
    if (iVar2 == 0) {
      lVar4 = 0;
    }
    else {
      sVar3 = strlen(PTR_s_dcc_datah_001104e0);
      iVar2 = strncmp(param_1,puVar1,sVar3);
      puVar1 = PTR_s_dcc_data_001104f8;
      if (iVar2 == 0) {
        lVar4 = 1;
      }
      else {
        sVar3 = strlen(PTR_s_dcc_data_001104f8);
        iVar2 = strncmp(param_1,puVar1,sVar3);
        puVar1 = PTR_s_mcu_factory_00110510;
        if (iVar2 == 0) {
          lVar4 = 2;
        }
        else {
          sVar3 = strlen(PTR_s_mcu_factory_00110510);
          iVar2 = strncmp(param_1,puVar1,sVar3);
          puVar1 = PTR_s_gps_data_00110528;
          if (iVar2 == 0) {
            lVar4 = 3;
          }
          else {
            sVar3 = strlen(PTR_s_gps_data_00110528);
            iVar2 = strncmp(param_1,puVar1,sVar3);
            puVar1 = PTR_s_std_sns_00110540;
            if (iVar2 == 0) {
              lVar4 = 4;
            }
            else {
              sVar3 = strlen(PTR_s_std_sns_00110540);
              iVar2 = strncmp(param_1,puVar1,sVar3);
              puVar1 = PTR_DAT_00110558;
              if (iVar2 == 0) {
                lVar4 = 5;
              }
              else {
                sVar3 = strlen(PTR_DAT_00110558);
                iVar2 = strncmp(param_1,puVar1,sVar3);
                puVar1 = PTR_s_haptic_00110570;
                if (iVar2 == 0) {
                  lVar4 = 6;
                }
                else {
                  sVar3 = strlen(PTR_s_haptic_00110570);
                  iVar2 = strncmp(param_1,puVar1,sVar3);
                  puVar1 = PTR_s_audioh_00110588;
                  if (iVar2 == 0) {
                    lVar4 = 7;
                  }
                  else {
                    sVar3 = strlen(PTR_s_audioh_00110588);
                    iVar2 = strncmp(param_1,puVar1,sVar3);
                    if (iVar2 != 0) goto LAB_00113d3c;
                    lVar4 = 8;
                  }
                }
              }
            }
          }
        }
      }
    }
    lVar4 = (&DAT_001104d8)[lVar4 * 3];
    if (lVar4 != 0) {
      iVar2 = *(int *)(lVar4 + 0x18);
      if (iVar2 != 0 && DAT_001105a8 != 0) {
        _printk(&DAT_001113fd,"ccch_open",0x628,param_1);
        iVar2 = *(int *)(lVar4 + 0x18);
      }
      *(int *)(lVar4 + 0x18) = iVar2 + 1;
      return lVar4;
    }
  }
LAB_00113d3c:
  if (DAT_001105a8 != 0) {
    _printk(&DAT_00110986,"ccch_open",0x623);
  }
  return 0;
}



// ===========================================================
// Function: ccch_close at 00113da0
// ===========================================================

undefined8 ccch_close(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    if (DAT_001105a8 == 0) {
      uVar1 = 0xffffffea;
    }
    else {
      _printk(&DAT_001112f7,"ccch_close",0x636);
      uVar1 = 0xffffffea;
    }
  }
  else if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return uVar1;
}



// ===========================================================
// Function: is_kernel_used at 00113e0c
// ===========================================================

bool is_kernel_used(uint param_1)

{
  return (param_1 & 0xfffe) == 0xe;
}



// ===========================================================
// Function: data_cdev_remove at 00113e1c
// ===========================================================

undefined8 data_cdev_remove(void)

{
  ulong *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  uint *puVar5;
  long lVar6;
  
  lVar6 = 0x10;
  do {
    puVar5 = *(uint **)((long)&g_cdev_info_list + lVar6);
    device_destroy(spidev_class,*puVar5);
    uVar2 = *puVar5;
    puVar1 = (ulong *)((long)&minors + (((ulong)uVar2 & 0xfffc0) >> 3));
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 & (1L << ((ulong)uVar2 & 0x3f) ^ 0xffffffffffffffffU);
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    kfree(puVar5);
    *(undefined8 *)((long)&g_cdev_info_list + lVar6) = 0;
    lVar6 = lVar6 + 0x18;
  } while (lVar6 != 0xe8);
  return 0;
}



// ===========================================================
// Function: spidev_probe at 00113ecc
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong spidev_probe(long param_1)

{
  undefined2 uVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  long lVar8;
  undefined8 uVar9;
  uint *puVar10;
  void *__s;
  void *__s_00;
  ulong uVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  ulong uVar14;
  
  _printk(&DAT_00110ae6,"2.1.0.230118_beta");
  if ((param_1 == 0) && (DAT_001105a8 != 0)) {
    _printk(&DAT_0011131e,"spidev_probe",0x926);
  }
  *(uint *)(param_1 + 0x3a8) = *(uint *)(param_1 + 0x3a8) | 1;
  oplus_spi_slave_ready_cb_register(param_1,slave_ready_cb_cfi_jt);
  puVar7 = (undefined4 *)kmem_cache_alloc_trace(_DAT_0011b288,0xdc0,0x3c0);
  spidev = puVar7;
  if (puVar7 != (undefined4 *)0x0) {
    *(long *)(puVar7 + 4) = param_1;
    *puVar7 = 0;
    __mutex_init(puVar7 + 0x1c,"&spidev->write_lock",&comm_master_upload_thread_packet_area);
    __mutex_init(spidev + 0x28,"&spidev->dual_comm_lock",&comm_master_upload_thread_packet_area);
    cpu_latency_qos_add_request(spidev + 6,0xffffffff);
    puVar7 = spidev + 0x12;
    *puVar7 = 8;
    of_property_read_variable_u32_array
              (*(undefined8 *)(param_1 + 0x2f0),"spi_bits_per_word",puVar7,1,0);
    puVar7 = spidev;
    if ((spidev[0x12] != 8) && (spidev[0x12] != 0x20)) {
      if (DAT_001105a8 != 0) {
        _printk(&DAT_00112337,"spidev_probe",0x93d);
      }
      puVar7 = spidev;
      spidev[0x12] = 8;
    }
    *(undefined8 *)(puVar7 + 0x3a) = 0;
    *(undefined4 **)(puVar7 + 0x3c) = puVar7 + 0x3c;
    *(undefined4 **)(puVar7 + 0x3e) = puVar7 + 0x3c;
    *(undefined8 *)(puVar7 + 0x40) = 0;
    *(undefined4 **)(puVar7 + 0x42) = puVar7 + 0x42;
    *(undefined4 **)(puVar7 + 0x44) = puVar7 + 0x42;
    *(undefined8 *)(puVar7 + 0x46) = 0;
    *(undefined4 **)(puVar7 + 0x48) = puVar7 + 0x48;
    *(undefined4 **)(puVar7 + 0x4a) = puVar7 + 0x48;
    lVar8 = kmalloc_order_trace(0x3ffc,0xdc0,2);
    *(long *)(spidev + 0x14) = lVar8;
    if (lVar8 != 0) {
      lVar8 = kmalloc_order_trace(0x3ffc,0xdc0,2);
      *(long *)(spidev + 0x16) = lVar8;
      if (lVar8 != 0) {
        lVar8 = kmalloc_order_trace(0x3ffc,0xdc0,2);
        *(long *)(spidev + 0x18) = lVar8;
        if (lVar8 != 0) {
          lVar8 = kmalloc_order_trace(0x3ffc,0xdc0,2);
          puVar7 = spidev;
          *(long *)(spidev + 0x1a) = lVar8;
          if (lVar8 != 0) {
            *(undefined4 **)(param_1 + 0x98) = puVar7;
            if (puVar7 + 0x52 == (undefined4 *)0x0) {
              if (DAT_001105a8 != 0) {
                _printk(&DAT_00111ac7,"wakeup_source_init",0x12d);
              }
            }
            else {
              *(undefined8 *)(puVar7 + 0x84) = 0;
              *(undefined8 *)(puVar7 + 0x82) = 0;
              *(undefined8 *)(puVar7 + 0x7e) = 0;
              *(undefined8 *)(puVar7 + 0x80) = 0;
              *(undefined8 *)(puVar7 + 0x7a) = 0;
              *(undefined8 *)(puVar7 + 0x7c) = 0;
              *(undefined8 *)(puVar7 + 0x76) = 0;
              *(undefined8 *)(puVar7 + 0x78) = 0;
              *(undefined8 *)(puVar7 + 0x72) = 0;
              *(undefined8 *)(puVar7 + 0x74) = 0;
              *(undefined8 *)(puVar7 + 0x6e) = 0;
              *(undefined8 *)(puVar7 + 0x70) = 0;
              *(undefined8 *)(puVar7 + 0x6a) = 0;
              *(undefined8 *)(puVar7 + 0x6c) = 0;
              *(undefined8 *)(puVar7 + 0x66) = 0;
              *(undefined8 *)(puVar7 + 0x68) = 0;
              *(undefined8 *)(puVar7 + 0x62) = 0;
              *(undefined8 *)(puVar7 + 100) = 0;
              *(undefined8 *)(puVar7 + 0x5e) = 0;
              *(undefined8 *)(puVar7 + 0x60) = 0;
              *(undefined8 *)(puVar7 + 0x5a) = 0;
              *(undefined8 *)(puVar7 + 0x5c) = 0;
              *(undefined8 *)(puVar7 + 0x56) = 0;
              *(undefined8 *)(puVar7 + 0x58) = 0;
              *(char **)(puVar7 + 0x52) = "upload_wakesrc";
              *(undefined8 *)(puVar7 + 0x54) = 0;
              wakeup_source_add(puVar7 + 0x52);
            }
            puVar5 = spidev;
            puVar7 = spidev + 0x86;
            if (puVar7 == (undefined4 *)0x0) {
              if (DAT_001105a8 != 0) {
                _printk(&DAT_00111ac7,"wakeup_source_init",0x12d);
              }
            }
            else {
              *(undefined8 *)(spidev + 0xb8) = 0;
              *(undefined8 *)(puVar5 + 0xb6) = 0;
              *(undefined8 *)(puVar5 + 0xb4) = 0;
              *(undefined8 *)(puVar5 + 0xb2) = 0;
              *(undefined8 *)(puVar5 + 0xb0) = 0;
              *(undefined8 *)(puVar5 + 0xae) = 0;
              *(undefined8 *)(puVar5 + 0xac) = 0;
              *(undefined8 *)(puVar5 + 0xaa) = 0;
              *(undefined8 *)(puVar5 + 0xa8) = 0;
              *(undefined8 *)(puVar5 + 0xa6) = 0;
              *(undefined8 *)(puVar5 + 0xa4) = 0;
              *(undefined8 *)(puVar5 + 0xa2) = 0;
              *(undefined8 *)(puVar5 + 0xa0) = 0;
              *(undefined8 *)(puVar5 + 0x9e) = 0;
              *(undefined8 *)(puVar5 + 0x9c) = 0;
              *(undefined8 *)(puVar5 + 0x9a) = 0;
              *(undefined8 *)(puVar5 + 0x98) = 0;
              *(undefined8 *)(puVar5 + 0x96) = 0;
              *(undefined8 *)(puVar5 + 0x94) = 0;
              *(undefined8 *)(puVar5 + 0x92) = 0;
              *(undefined8 *)(puVar5 + 0x90) = 0;
              *(undefined8 *)(puVar5 + 0x8e) = 0;
              *(undefined8 *)(puVar5 + 0x8c) = 0;
              *(undefined8 *)(puVar5 + 0x8a) = 0;
              *(undefined8 *)(puVar5 + 0x88) = 0;
              *(char **)(puVar5 + 0x86) = "download_wakesrc";
              wakeup_source_add(puVar7);
            }
            puVar5 = spidev;
            puVar7 = spidev + 0xba;
            if (puVar7 == (undefined4 *)0x0) {
              if (DAT_001105a8 != 0) {
                _printk(&DAT_00111ac7,"wakeup_source_init",0x12d);
              }
            }
            else {
              *(undefined8 *)(spidev + 0xec) = 0;
              *(undefined8 *)(puVar5 + 0xea) = 0;
              *(undefined8 *)(puVar5 + 0xe8) = 0;
              *(undefined8 *)(puVar5 + 0xe6) = 0;
              *(undefined8 *)(puVar5 + 0xe4) = 0;
              *(undefined8 *)(puVar5 + 0xe2) = 0;
              *(undefined8 *)(puVar5 + 0xe0) = 0;
              *(undefined8 *)(puVar5 + 0xde) = 0;
              *(undefined8 *)(puVar5 + 0xdc) = 0;
              *(undefined8 *)(puVar5 + 0xda) = 0;
              *(undefined8 *)(puVar5 + 0xd8) = 0;
              *(undefined8 *)(puVar5 + 0xd6) = 0;
              *(undefined8 *)(puVar5 + 0xd4) = 0;
              *(undefined8 *)(puVar5 + 0xd2) = 0;
              *(undefined8 *)(puVar5 + 0xd0) = 0;
              *(undefined8 *)(puVar5 + 0xce) = 0;
              *(undefined8 *)(puVar5 + 0xcc) = 0;
              *(undefined8 *)(puVar5 + 0xca) = 0;
              *(undefined8 *)(puVar5 + 200) = 0;
              *(undefined8 *)(puVar5 + 0xc6) = 0;
              *(undefined8 *)(puVar5 + 0xc4) = 0;
              *(undefined8 *)(puVar5 + 0xc2) = 0;
              *(undefined8 *)(puVar5 + 0xc0) = 0;
              *(undefined8 *)(puVar5 + 0xbe) = 0;
              *(undefined8 *)(puVar5 + 0xbc) = 0;
              *(char **)(puVar5 + 0xba) = "resever_wakesrc";
              wakeup_source_add(puVar7);
            }
            puVar7 = spidev;
            iVar6 = get_gpio_from_devtree
                              (*(undefined8 *)(*(long *)(spidev + 4) + 0x2f0),"s2m_int_gpio");
            puVar7[0x34] = iVar6;
            if (iVar6 < 0) {
LAB_0011428c:
              if (DAT_001105a8 != 0) {
                _printk(&DAT_00110d0f,"spidev_probe",0x962);
              }
            }
            else {
              gpio_to_desc();
              gpiod_direction_input();
              uVar9 = spidev_gpio_request_irq
                                (*(undefined8 *)(puVar7 + 4),puVar7[0x34],4,s2m_int_irq_fn_cfi_jt);
              puVar7[0x38] = (int)uVar9;
              if (((int)uVar9 < 0) || (iVar6 = irq_set_irq_wake(uVar9,1), iVar6 != 0))
              goto LAB_0011428c;
              if (DAT_001105c8 != 0) {
                _printk(&DAT_00111065,"spidev_gpio_init",0x8fe,puVar7[0x34],puVar7[0x38]);
              }
              iVar6 = get_gpio_from_devtree
                                (*(undefined8 *)(*(long *)(puVar7 + 4) + 0x2f0),"m2s_ans_gpio");
              puVar7[0x37] = iVar6;
              if (iVar6 < 0) goto LAB_0011428c;
              uVar9 = gpio_to_desc();
              gpiod_direction_output_raw(uVar9,0);
              if (DAT_001105c8 != 0) {
                _printk(&DAT_00111cd3,"spidev_gpio_init",0x904,puVar7[0x37]);
              }
              iVar6 = get_gpio_from_devtree
                                (*(undefined8 *)(*(long *)(puVar7 + 4) + 0x2f0),"m2s_int_gpio");
              puVar7[0x36] = iVar6;
              if (iVar6 < 0) goto LAB_0011428c;
              uVar9 = gpio_to_desc();
              gpiod_direction_output_raw(uVar9,0);
              if (DAT_001105c8 != 0) {
                _printk(&DAT_0011177b,"spidev_gpio_init",0x90a,puVar7[0x36]);
              }
              iVar6 = get_gpio_from_devtree
                                (*(undefined8 *)(*(long *)(puVar7 + 4) + 0x2f0),"s2m_ans_gpio");
              puVar7[0x35] = iVar6;
              if (iVar6 < 0) goto LAB_0011428c;
              gpio_to_desc();
              gpiod_direction_input();
              iVar6 = spidev_gpio_request_irq
                                (*(undefined8 *)(puVar7 + 4),puVar7[0x35],1,s2m_ans_irq_fn_cfi_jt);
              puVar7[0x39] = iVar6;
              if (iVar6 < 0) goto LAB_0011428c;
              if (DAT_001105c8 != 0) {
                _printk(&DAT_00111afb,"spidev_gpio_init",0x915,puVar7[0x35],iVar6);
              }
            }
            lVar8 = 0;
            do {
              puVar7 = spidev;
              uVar9 = *(undefined8 *)(spidev + 4);
              puVar10 = (uint *)kmem_cache_alloc_trace(_DAT_0011b288,0xdc0,0x270);
              if (puVar10 != (uint *)0x0) {
                __s = (void *)kmalloc_order_trace(0x3ff4,0xdc0,2);
                *(void **)(puVar10 + 0x52) = __s;
                if (__s != (void *)0x0) {
                  memset(__s,0,0x3ff4);
                  __s_00 = (void *)kmalloc_order_trace(0x3ff4,0xdc0,2);
                  *(void **)(puVar10 + 0x54) = __s_00;
                  if (__s_00 != (void *)0x0) {
                    memset(__s_00,0,0x3ff4);
                    uVar1 = *(undefined2 *)((long)&DAT_001104d0 + lVar8);
                    *(undefined4 **)(puVar10 + 2) = puVar7;
                    uVar13 = *(undefined8 *)((long)&g_cdev_info_list + lVar8);
                    *(undefined2 *)(puVar10 + 7) = uVar1;
                    *(undefined8 *)(puVar10 + 8) = uVar13;
                    __mutex_init(puVar10 + 0x3a,"&data_cdev->read_lock",
                                 &comm_master_upload_thread_packet_area);
                    __mutex_init(puVar10 + 0x46,"&data_cdev->write_lock",
                                 &comm_master_upload_thread_packet_area);
                    uVar12 = 0x40000;
                    if (*(short *)((long)&DAT_001104d0 + lVar8) != 1) {
                      uVar12 = 0x4000;
                    }
                    puVar10[0x34] = 0;
                    puVar10[0x35] = 0;
                    *(uint **)(puVar10 + 0x36) = puVar10 + 0x36;
                    *(uint **)(puVar10 + 0x38) = puVar10 + 0x36;
                    __mutex_init(puVar10 + 0x28,"&fifo->lock",&comm_master_upload_thread_packet_area
                                );
                    iVar6 = __kfifo_alloc(puVar10 + 0x22,uVar12,1,0xcc0);
                    if (iVar6 == 0) {
                      puVar10[0x1c] = 0;
                      puVar10[0x1d] = 0;
                      *(uint **)(puVar10 + 0x1e) = puVar10 + 0x1e;
                      *(uint **)(puVar10 + 0x20) = puVar10 + 0x1e;
                      __mutex_init(puVar10 + 0x10,"&fifo->lock",
                                   &comm_master_upload_thread_packet_area);
                      iVar6 = __kfifo_alloc(puVar10 + 10,uVar12,1,0xcc0);
                      if (iVar6 == 0) {
                        if ((*(ushort *)((long)&DAT_001104d0 + lVar8) & 0xfffe) != 0xe) {
                          uVar14 = ~(minors | 0xffffffff00000000);
                          uVar14 = (uVar14 & 0xaaaaaaaaaaaaaaaa) >> 1 |
                                   (uVar14 & 0x5555555555555555) << 1;
                          uVar14 = (uVar14 & 0xcccccccccccccccc) >> 2 |
                                   (uVar14 & 0x3333333333333333) << 2;
                          uVar14 = (uVar14 & 0xf0f0f0f0f0f0f0f0) >> 4 |
                                   (uVar14 & 0xf0f0f0f0f0f0f0f) << 4;
                          uVar14 = (uVar14 & 0xff00ff00ff00ff00) >> 8 |
                                   (uVar14 & 0xff00ff00ff00ff) << 8;
                          uVar11 = (uVar14 & 0xffff0000ffff0000) >> 0x10 |
                                   (uVar14 & 0xffff0000ffff) << 0x10;
                          uVar14 = 0x20;
                          if ((minors | 0xffffffff00000000) != 0xffffffffffffffff) {
                            uVar14 = LZCOUNT(uVar11 >> 0x20 | uVar11 << 0x20);
                          }
                          if (uVar14 < 0x20) {
                            uVar2 = (uint)uVar14 | 0x9900000;
                            uVar13 = *(undefined8 *)((long)&g_cdev_info_list + lVar8);
                            *puVar10 = uVar2;
                            uVar11 = device_create(spidev_class,uVar9,uVar2,puVar10,uVar13);
                            *(ulong *)(puVar10 + 4) = uVar11;
                            if ((uVar11 < 0xfffffffffffff001) || ((uVar11 & 0xffffffff) == 0)) {
                              Hint_Prefetch(0x100280,2,0,1);
                              do {
                                cVar3 = '\x01';
                                bVar4 = (bool)ExclusiveMonitorPass(0x100280,0x10);
                                if (bVar4) {
                                  cVar3 = ExclusiveMonitorsStatus();
                                  minors = minors | 1L << (uVar14 & 0x3f);
                                }
                              } while (cVar3 != '\0');
                            }
                          }
                          else {
                            puVar10[4] = 0;
                            puVar10[5] = 0;
                          }
                        }
                        snprintf((char *)(puVar10 + 0x8a),0x20,"ws_%s",
                                 *(undefined8 *)((long)&g_cdev_info_list + lVar8));
                        puVar10[0x5a] = 0;
                        puVar10[0x5b] = 0;
                        puVar10[0x5c] = 0;
                        puVar10[0x5d] = 0;
                        puVar10[0x5e] = 0;
                        puVar10[0x5f] = 0;
                        puVar10[0x60] = 0;
                        puVar10[0x61] = 0;
                        puVar10[0x62] = 0;
                        puVar10[99] = 0;
                        puVar10[100] = 0;
                        puVar10[0x65] = 0;
                        puVar10[0x66] = 0;
                        puVar10[0x67] = 0;
                        puVar10[0x68] = 0;
                        puVar10[0x69] = 0;
                        puVar10[0x6a] = 0;
                        puVar10[0x6b] = 0;
                        puVar10[0x6c] = 0;
                        puVar10[0x6d] = 0;
                        puVar10[0x6e] = 0;
                        puVar10[0x6f] = 0;
                        puVar10[0x70] = 0;
                        puVar10[0x71] = 0;
                        puVar10[0x72] = 0;
                        puVar10[0x73] = 0;
                        puVar10[0x74] = 0;
                        puVar10[0x75] = 0;
                        puVar10[0x76] = 0;
                        puVar10[0x77] = 0;
                        puVar10[0x78] = 0;
                        puVar10[0x79] = 0;
                        puVar10[0x7a] = 0;
                        puVar10[0x7b] = 0;
                        puVar10[0x7c] = 0;
                        puVar10[0x7d] = 0;
                        puVar10[0x7e] = 0;
                        puVar10[0x7f] = 0;
                        puVar10[0x80] = 0;
                        puVar10[0x81] = 0;
                        puVar10[0x82] = 0;
                        puVar10[0x83] = 0;
                        puVar10[0x84] = 0;
                        puVar10[0x85] = 0;
                        puVar10[0x86] = 0;
                        puVar10[0x87] = 0;
                        puVar10[0x88] = 0;
                        puVar10[0x89] = 0;
                        *(uint **)(puVar10 + 0x56) = puVar10 + 0x8a;
                        puVar10[0x58] = 0;
                        puVar10[0x59] = 0;
                        wakeup_source_add(puVar10 + 0x56);
                        *(uint **)((long)&DAT_001104d8 + lVar8) = puVar10;
                      }
                      else {
                        _printk(&DAT_0011222d,uVar12,iVar6);
                      }
                    }
                    else {
                      _printk(&DAT_0011222d,uVar12,iVar6);
                    }
                    goto LAB_001142bc;
                  }
                  kfree(__s);
                }
                kfree(puVar10);
              }
LAB_001142bc:
              lVar8 = lVar8 + 0x18;
            } while (lVar8 != 0xd8);
            uVar14 = kthread_create_on_node
                               (comm_master_upload_thread_cfi_jt,spidev,0xffffffff,"snshub_up_thd");
            puVar7 = spidev;
            *(ulong *)(spidev + 0x4c) = uVar14;
            if (uVar14 < 0xfffffffffffff001) {
              puVar10 = (uint *)(uVar14 + 0x38);
              Hint_Prefetch(puVar10,2,0,1);
              do {
                uVar2 = *puVar10;
                cVar3 = '\x01';
                bVar4 = (bool)ExclusiveMonitorPass(puVar10,0x10);
                if (bVar4) {
                  *puVar10 = uVar2 + 1;
                  cVar3 = ExclusiveMonitorsStatus();
                }
              } while (cVar3 != '\0');
              if (uVar2 == 0) {
                uVar9 = 2;
LAB_001148a4:
                refcount_warn_saturate(puVar10,uVar9);
              }
              else if ((int)(uVar2 + 1 | uVar2) < 0) {
                uVar9 = 1;
                goto LAB_001148a4;
              }
              wake_up_process(*(undefined8 *)(spidev + 0x4c));
              uVar14 = 0;
              puVar7 = spidev;
            }
            else if (DAT_001105a8 != 0) {
              _printk(&DAT_00110c76,"spidev_probe",0x96a);
              uVar14 = *(ulong *)(spidev + 0x4c);
              puVar7 = spidev;
            }
            uVar11 = kthread_create_on_node
                               (comm_master_download_thread_cfi_jt,puVar7,0xffffffff,
                                "snshub_down_thd");
            *(ulong *)(spidev + 0x4e) = uVar11;
            if (0xfffffffffffff000 < uVar11) {
              if (DAT_001105a8 != 0) {
                _printk(&DAT_0011121a,"spidev_probe",0x974);
                uVar11 = *(ulong *)(spidev + 0x4e);
              }
              uVar14 = uVar11 & 0xffffffff;
              goto LAB_001140d4;
            }
            puVar10 = (uint *)(uVar11 + 0x38);
            Hint_Prefetch(puVar10,2,0,1);
            do {
              uVar2 = *puVar10;
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(puVar10,0x10);
              if (bVar4) {
                *puVar10 = uVar2 + 1;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
            if (uVar2 == 0) {
              uVar9 = 2;
LAB_001148cc:
              refcount_warn_saturate(puVar10,uVar9);
            }
            else if ((int)(uVar2 + 1 | uVar2) < 0) {
              uVar9 = 1;
              goto LAB_001148cc;
            }
            wake_up_process(*(undefined8 *)(spidev + 0x4e));
            goto LAB_001140d4;
          }
        }
      }
    }
  }
  uVar14 = 0xfffffff4;
LAB_001140d4:
  return uVar14 & 0xffffffff;
}



// ===========================================================
// Function: spidev_remove at 001148d8
// ===========================================================

undefined8 spidev_remove(void)

{
  return 0;
}



// ===========================================================
// Function: snshub_suspend at 001148e0
// ===========================================================

undefined8 snshub_suspend(long param_1)

{
  *(undefined4 *)(*(long *)(param_1 + 0x98) + 0x140) = 1;
  return 0;
}



// ===========================================================
// Function: snshub_resume at 001148f4
// ===========================================================

undefined8 snshub_resume(long param_1)

{
  *(undefined4 *)(*(long *)(param_1 + 0x98) + 0x140) = 0;
  return 0;
}



// ===========================================================
// Function: slave_ready_cb at 00114908
// ===========================================================

void slave_ready_cb(undefined8 param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_2 == 0 && param_3 == 0) {
    if (DAT_001105a8 != 0) {
      _printk(&DAT_00111c2c,"slave_ready_cb",0x15e);
    }
  }
  else {
    if (param_2 != 0) {
      uVar1 = gpio_to_desc(*(undefined4 *)(spidev + 0xd8));
      gpiod_direction_output_raw(uVar1,1);
    }
    if (param_3 != 0) {
      uVar1 = gpio_to_desc(*(undefined4 *)(spidev + 0xdc));
      gpiod_direction_output_raw(uVar1,1);
    }
  }
  return;
}



// ===========================================================
// Function: get_gpio_from_devtree at 00114994
// ===========================================================

uint get_gpio_from_devtree(long param_1,undefined8 param_2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x648);
  local_2c = 0;
  if (param_1 != 0) {
    uVar2 = of_get_named_gpio_flags(param_1,param_2,0,&local_2c);
    if (((int)uVar2 < 0) && (uVar2 != 0xfffffdfb)) {
      if (DAT_001105a8 != 0) {
        _printk(&DAT_001110a4,"get_gpio_from_devtree",0x8d1);
      }
    }
    else {
      if ((0x1ff < uVar2) || (iVar3 = gpio_request(uVar2,"s2m_int_gpio"), -1 < iVar3))
      goto LAB_001149e8;
      if (DAT_001105a8 != 0) {
        _printk(&DAT_00111f1f,"get_gpio_from_devtree",0x8d6,uVar2);
      }
    }
  }
  uVar2 = 0xffffffed;
LAB_001149e8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x648) == local_28) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// ===========================================================
// Function: s2m_int_irq_fn at 00114a7c
// ===========================================================

undefined8 s2m_int_irq_fn(int param_1,long param_2)

{
  long lVar1;
  
  disable_irq_nosync();
  lVar1 = spidev;
  if (((param_2 != 0) && (spidev != 0)) && (*(int *)(spidev + 0xe0) == param_1)) {
    if (*(int *)(spidev + 0x140) != 0) {
      *(undefined1 *)(spidev + 0x3bc) = 1;
    }
    pm_wakeup_ws_event(lVar1 + 0x148,1000,0);
    up(spidev + 0xe8);
  }
  return 1;
}



// ===========================================================
// Function: spidev_gpio_request_irq at 00114af4
// ===========================================================

int spidev_gpio_request_irq(long *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  gpio_to_desc(param_2);
  iVar1 = gpiod_to_irq();
  if (iVar1 < 0) {
    if (DAT_001105a8 != 0) {
      _printk(&DAT_00110a51,"spidev_gpio_request_irq",0x8e6,param_2,iVar1);
    }
  }
  else {
    lVar3 = param_1[0xe];
    if (lVar3 == 0) {
      lVar3 = *param_1;
    }
    iVar2 = request_threaded_irq(iVar1,param_4,0,param_3,lVar3,param_1);
    if (-1 < iVar2) {
      return iVar1;
    }
    if (DAT_001105a8 != 0) {
      _printk(&DAT_00111395,"spidev_gpio_request_irq",0x8eb);
    }
  }
  return -0x16;
}



// ===========================================================
// Function: s2m_ans_irq_fn at 00114bd0
// ===========================================================

undefined8 s2m_ans_irq_fn(int param_1,long param_2)

{
  if (((param_2 != 0) && (spidev != 0)) && (*(int *)(spidev + 0xe4) == param_1)) {
    up(spidev + 0x100);
  }
  return 1;
}



// ===========================================================
// Function: comm_master_upload_thread at 00114c10
// ===========================================================

void comm_master_upload_thread(void)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  size_t __n;
  uint uVar7;
  undefined4 uVar8;
  long lVar9;
  ulong uVar10;
  undefined2 *puVar11;
  long lVar12;
  long *plVar13;
  ulong uVar14;
  ushort *puVar15;
  int iVar16;
  ulong uVar17;
  ushort *puVar18;
  sched_param local_68 [2];
  
  local_68[0].__sched_priority = 0x34;
  iVar4 = sched_setscheduler((__pid_t)*(undefined8 *)(spidev + 0x130),1,local_68);
  if (iVar4 != 0 && DAT_001105a8 != 0) {
    _printk(&DAT_00110d38,"comm_master_upload_thread",0x4ec);
  }
  if (DAT_001105d8 != 0) {
    lVar12 = *(long *)(spidev + 0x130);
    _printk(&DAT_00112031,"comm_master_upload_thread",0x4ee,*(undefined4 *)(lVar12 + 0x640),
            *(undefined4 *)(lVar12 + 0x488),*(undefined4 *)(lVar12 + 0x7c));
  }
  gpio_to_desc(*(undefined4 *)(spidev + 0xd0));
  iVar4 = gpiod_get_raw_value();
  if (iVar4 == 1) {
    if (DAT_001105a8 != 0) {
      _printk(&DAT_00112374,"comm_master_upload_thread",0x4f1);
    }
    up(spidev + 0xe8);
  }
  iVar4 = 0;
LAB_00114d24:
  do {
    while (iVar5 = down_trylock(spidev + 0xe8), iVar5 == 0) {
      DAT_001002c0 = DAT_001002c0 + 1;
    }
    gpio_to_desc(*(undefined4 *)(spidev + 0xd0));
    iVar5 = gpiod_get_raw_value();
    if (iVar5 == 0) {
      __pm_relax(spidev + 0x148);
      enable_irq(*(undefined4 *)(spidev + 0xe0));
      down(spidev + 0xe8);
    }
    __pm_stay_awake(spidev + 0x148);
    mutex_lock(spidev + 0xa0);
    lVar12 = spidev;
    memset(*(void **)(spidev + 0x50),0,0x3ffc);
    memset(*(void **)(lVar12 + 0x68),0,0x3ffc);
    iVar5 = spidev_spi_sync(0,*(undefined8 *)(lVar12 + 0x50));
    lVar12 = spidev;
    if (iVar5 == 0) {
      memcpy(*(void **)(spidev + 0x68),*(void **)(spidev + 0x50),0x3ffc);
      puVar18 = *(ushort **)(lVar12 + 0x68);
      if ((char)(*(char *)((long)puVar18 + 1) + (char)*puVar18 +
                 (char)puVar18[1] + *(char *)((long)puVar18 + 3) +
                 (char)puVar18[2] + *(char *)((long)puVar18 + 5) + (char)puVar18[3] +
                *(char *)((long)puVar18 + 7)) != -1) {
LAB_00114f60:
        DAT_001002b0._0_4_ = (int)DAT_001002b0 + 1;
        goto LAB_00114f6c;
      }
      uVar1 = puVar18[3];
      __n = (size_t)uVar1;
      if (0x3ff4 < uVar1) goto LAB_00114f60;
      if (uVar1 < 2) {
        uVar7 = 0;
      }
      else {
        uVar7 = (uint)(uVar1 >> 1);
        if (uVar1 >> 1 < 2) {
          uVar7 = 1;
        }
        uVar10 = (ulong)uVar7;
        if (uVar7 < 2) {
          uVar14 = 0;
          uVar7 = 0;
        }
        else {
          uVar14 = uVar10 & 0x7ffe;
          iVar5 = 0;
          iVar16 = 0;
          puVar15 = puVar18 + 5;
          uVar17 = uVar14;
          do {
            uVar17 = uVar17 - 2;
            iVar5 = iVar5 + (uint)puVar15[-1];
            iVar16 = iVar16 + (uint)*puVar15;
            puVar15 = puVar15 + 2;
          } while (uVar17 != 0);
          uVar7 = iVar16 + iVar5;
          if (uVar14 == uVar10) goto LAB_00114ee8;
        }
        lVar9 = uVar10 - uVar14;
        puVar15 = puVar18 + uVar14 + 4;
        do {
          lVar9 = lVar9 + -1;
          uVar7 = uVar7 + *puVar15;
          puVar15 = puVar15 + 1;
        } while (lVar9 != 0);
      }
LAB_00114ee8:
      puVar15 = puVar18 + 4;
      if ((uVar1 & 1) != 0) {
        uVar7 = uVar7 + *(byte *)((long)puVar15 + (ulong)(uVar1 - 1));
      }
      if ((uint)puVar18[2] != (~(uVar7 + (uVar7 >> 0x10)) & 0xffff)) goto LAB_00114f60;
      if (((puVar18[1] & 1) == 0) && ((is_first_up_frame & 1) != 0)) {
        if (up_selnum - 1 == (uint)*puVar18) {
          memcpy(&comm_master_upload_thread_packet_area,puVar15,__n);
          iVar5 = 3;
          up_selnum = *puVar18 + 1;
        }
        else {
          iVar5 = (uint)*puVar18 - (uint)up_selnum;
          if (iVar5 == 0) goto LAB_00115048;
          if (DAT_001105a8 != 0) {
            _printk(&DAT_00111e39,"check_and_get_data_from_ram",0x2dc,up_selnum,iVar5);
            __n = (size_t)puVar18[3];
          }
          memcpy(&comm_master_upload_thread_packet_area,puVar15,__n);
          iVar5 = 0;
          up_selnum = *puVar18 + 1;
          DAT_001002a8._4_4_ = DAT_001002a8._4_4_ + 1;
        }
      }
      else {
        if (((puVar18[1] & 1) != 0) &&
           (oplus_snshub_states_uevent(0,&DAT_001122f4), DAT_001105c8 != 0)) {
          _printk(&DAT_00111692,"check_and_get_data_from_ram",0x2d6,up_selnum);
        }
LAB_00115048:
        memcpy(&comm_master_upload_thread_packet_area,puVar15,(ulong)puVar18[3]);
        iVar5 = 0;
        up_selnum = *puVar18 + 1;
        is_first_up_frame = 1;
        DAT_001002b0._4_4_ = DAT_001002b0._4_4_ + 1;
      }
      uVar6 = gpio_to_desc(*(undefined4 *)(spidev + 0xdc));
      gpiod_direction_output_raw(uVar6,1);
      __const_udelay(0xa7c6);
    }
    else {
      if (DAT_001105a8 != 0) {
        _printk(&DAT_00112076,"upload_spi_seq",700,iVar5);
      }
      DAT_001002b8._4_4_ = DAT_001002b8._4_4_ + 1;
      lVar12 = spidev;
LAB_00114f6c:
      uVar6 = gpio_to_desc(*(undefined4 *)(lVar12 + 0xdc));
      gpiod_direction_output_raw(uVar6,1);
      msleep(0x96);
      iVar5 = 2;
    }
    uVar6 = gpio_to_desc(*(undefined4 *)(spidev + 0xdc));
    gpiod_direction_output_raw(uVar6,0);
    mutex_unlock(spidev + 0xa0);
    uVar6 = gpio_to_desc(*(undefined4 *)(spidev + 0xdc));
    gpiod_direction_output_raw(uVar6,0);
    while ((close_comm_state >> 1 & 1) != 0) {
      msleep(5000);
    }
    if (iVar5 != 3) {
      if (iVar5 == 0) {
        if (comm_master_upload_thread_packet_area != 0x3b9) {
          if (comm_master_upload_thread_packet_area == 0x3b8) {
            memcpy(&upload_speed_string,&DAT_001084cc,0x200);
            upload_speed_string_ready = 1;
          }
          else {
            if (DAT_001104d0 == comm_master_upload_thread_packet_area) {
              lVar12 = 0;
LAB_00115390:
              plVar13 = &DAT_001104d8 + lVar12 * 3;
            }
            else {
              if (DAT_001104e8 == comm_master_upload_thread_packet_area) {
                lVar12 = 1;
                goto LAB_00115390;
              }
              if (DAT_00110500 == comm_master_upload_thread_packet_area) {
                lVar12 = 2;
                goto LAB_00115390;
              }
              if (DAT_00110518 == comm_master_upload_thread_packet_area) {
                lVar12 = 3;
                goto LAB_00115390;
              }
              if (DAT_00110530 == comm_master_upload_thread_packet_area) {
                lVar12 = 4;
                goto LAB_00115390;
              }
              if (DAT_00110548 == comm_master_upload_thread_packet_area) {
                lVar12 = 5;
                goto LAB_00115390;
              }
              if (DAT_00110560 == comm_master_upload_thread_packet_area) {
                lVar12 = 6;
                goto LAB_00115390;
              }
              if (DAT_00110578 == comm_master_upload_thread_packet_area) {
                lVar12 = 7;
                goto LAB_00115390;
              }
              plVar13 = &DAT_001104d8;
              if (DAT_00110590 == comm_master_upload_thread_packet_area) {
                lVar12 = 8;
                goto LAB_00115390;
              }
            }
            lVar12 = *plVar13;
            if (lVar12 == 0) {
              if (DAT_001105a8 != 0) {
                _printk(&DAT_00110d9a,"distribute_packet_to_data_cdev",0x443);
              }
            }
            else {
              sVar2 = is_sau_filter(*(undefined2 *)(lVar12 + 0x1c));
              if (sVar2 == 0) {
                if (DAT_00110618 != 0) {
                  _printk(&DAT_001123e4,PTR_s_packet_to_fifo_00110610,DAT_001084ca + 4,
                          *(undefined8 *)(lVar12 + 0x20));
                  print_hex_dump(&DAT_00110c3f,&DAT_00111a43,2,0x10,1,
                                 &comm_master_upload_thread_packet_area,(ulong)DAT_001084ca + 4,1);
                }
                if ((*(short *)(lVar12 + 0x1c) == 2) && (DAT_001105a8 != 0)) {
                  _printk(&DAT_001117b2,"distribute_packet_to_data_cdev",0x461,
                          *(undefined8 *)(lVar12 + 0x20),DAT_001084ca,&DAT_001084cc);
                }
                iVar5 = DAT_001105a8;
                if (*(char *)(spidev + 0x3bc) != '\0') {
                  *(undefined1 *)(spidev + 0x3bc) = 0;
                  if (iVar5 != 0) {
                    _printk(&DAT_00111b91,"distribute_packet_to_data_cdev",0x46e,
                            *(undefined8 *)(lVar12 + 0x20),DAT_001084ca);
                  }
                  lVar9 = 0x10;
                  if (DAT_001084ca < 0xd) {
                    lVar9 = (ulong)DAT_001084ca + 4;
                  }
                  print_hex_dump(&DAT_00110c3f,"ocm: ",2,0x10,1,
                                 &comm_master_upload_thread_packet_area,lVar9,0);
                }
                iVar5 = *(int *)(lVar12 + 0x28) - *(int *)(lVar12 + 0x2c);
                if (((distribute_packet_to_data_cdev_sleep_flag & 1) == 0) && (0x14000 < iVar5)) {
                  distribute_packet_to_data_cdev_sleep_flag = 1;
                  if (DAT_001105a8 != 0) {
                    _printk(&DAT_001113c3,"distribute_packet_to_data_cdev",0x47d);
                  }
                  uVar8 = 0x32;
                  if (*(short *)(lVar12 + 0x1c) != 1) {
                    uVar8 = 0;
                  }
                  msleep(uVar8);
                }
                else if (iVar5 < 0xc800) {
                  distribute_packet_to_data_cdev_sleep_flag = 0;
                }
                lVar9 = lVar12 + 0x40;
                uVar7 = DAT_001084ca + 4;
                mutex_lock(lVar9);
                if ((*(int *)(lVar12 + 0x30) - *(int *)(lVar12 + 0x28)) + *(int *)(lVar12 + 0x2c) +
                    1U <= uVar7) {
                  mutex_unlock(lVar9);
                  iVar5 = *(int *)(lVar12 + 0x24c) + 1;
                  *(int *)(lVar12 + 0x24c) = iVar5;
                  if (((iVar5 < 10) ||
                      (((uint)(iVar5 * -0x3d70a3d7) >> 2 | iVar5 * 0x40000000) < 0x28f5c29)) &&
                     (DAT_001105a8 != 0)) {
                    _printk(&DAT_00111f52,"distribute_packet_to_data_cdev",0x490,
                            *(undefined8 *)(lVar12 + 0x20),0,iVar5,*(undefined4 *)(lVar12 + 0x250));
                  }
                  uVar8 = 200;
                  if (*(short *)(lVar12 + 0x1c) != 1) {
                    uVar8 = 0x14;
                  }
                  msleep(uVar8);
                  iVar5 = *(int *)(lVar12 + 0x28) - *(int *)(lVar12 + 0x2c);
                  if (((distribute_packet_to_data_cdev_sleep_flag & 1) == 0) && (0x14000 < iVar5)) {
                    distribute_packet_to_data_cdev_sleep_flag = 1;
                    if (DAT_001105a8 != 0) {
                      _printk(&DAT_001113c3,"distribute_packet_to_data_cdev",0x47d);
                    }
                    uVar8 = 0x32;
                    if (*(short *)(lVar12 + 0x1c) != 1) {
                      uVar8 = 0;
                    }
                    msleep(uVar8);
                  }
                  else if (iVar5 < 0xc800) {
                    distribute_packet_to_data_cdev_sleep_flag = 0;
                  }
                  uVar7 = DAT_001084ca + 4;
                  mutex_lock(lVar9);
                  if ((*(int *)(lVar12 + 0x30) - *(int *)(lVar12 + 0x28)) + *(int *)(lVar12 + 0x2c)
                      + 1U <= uVar7) {
                    mutex_unlock(lVar9);
                    iVar5 = *(int *)(lVar12 + 0x24c) + 1;
                    *(int *)(lVar12 + 0x24c) = iVar5;
                    if (((iVar5 < 10) ||
                        (((uint)(iVar5 * -0x3d70a3d7) >> 2 | iVar5 * 0x40000000) < 0x28f5c29)) &&
                       (DAT_001105a8 != 0)) {
                      _printk(&DAT_00111f52,"distribute_packet_to_data_cdev",0x490,
                              *(undefined8 *)(lVar12 + 0x20),1,iVar5,*(undefined4 *)(lVar12 + 0x250)
                             );
                    }
                    uVar8 = 200;
                    if (*(short *)(lVar12 + 0x1c) != 1) {
                      uVar8 = 0x14;
                    }
                    msleep(uVar8);
                    iVar5 = *(int *)(lVar12 + 0x248);
                    if ((iVar5 == 0) && (DAT_001105a8 != 0)) {
                      _printk(&DAT_00111c4e,"distribute_packet_to_data_cdev",0x498,
                              *(undefined8 *)(lVar12 + 0x20));
                      iVar5 = *(int *)(lVar12 + 0x248);
                    }
                    *(int *)(lVar12 + 0x248) = iVar5 + 1;
                    goto joined_r0x001156f8;
                  }
                }
                __kfifo_in((int *)(lVar12 + 0x28),&comm_master_upload_thread_packet_area,uVar7);
                mutex_unlock(lVar9);
                up(lVar12 + 0x70);
                pm_wakeup_ws_event(lVar12 + 0x158,1000,0);
                *(int *)(lVar12 + 0x250) = *(int *)(lVar12 + 0x250) + 1;
                if (*(int *)(lVar12 + 0x248) != 0) {
                  if ((1 < *(int *)(lVar12 + 0x248)) && (DAT_001105a8 != 0)) {
                    _printk(&DAT_0011094d,"distribute_packet_to_data_cdev",0x49d,
                            *(undefined8 *)(lVar12 + 0x20));
                  }
                  *(undefined4 *)(lVar12 + 0x248) = 0;
                }
              }
              else {
                sVar2 = *(short *)(lVar12 + 0x1c);
                if (distribute_packet_to_data_cdev_last_channel_id != sVar2) {
                  if ((distribute_packet_to_data_cdev_last_channel_id != 0) && (DAT_001105a8 != 0))
                  {
                    uVar3 = get_sau_ch_id();
                    _printk(&DAT_00110dc5,"distribute_packet_to_data_cdev",0x44e,uVar3,
                            distribute_packet_to_data_cdev_last_channel_id,
                            distribute_packet_to_data_cdev_print_cnt);
                    sVar2 = *(short *)(lVar12 + 0x1c);
                  }
                  distribute_packet_to_data_cdev_last_channel_id = sVar2;
                  distribute_packet_to_data_cdev_print_cnt = 0;
                  if (DAT_001105a8 != 0) {
                    uVar3 = get_sau_ch_id();
                    _printk(&DAT_00111970,"distribute_packet_to_data_cdev",0x453,uVar3,
                            *(undefined2 *)(lVar12 + 0x1c));
                  }
                }
                distribute_packet_to_data_cdev_print_cnt =
                     distribute_packet_to_data_cdev_print_cnt + 1;
                if ((((uint)(distribute_packet_to_data_cdev_print_cnt * -0x33333333) >> 1 |
                     distribute_packet_to_data_cdev_print_cnt * -0x80000000) < 0x1999999a) &&
                   (DAT_001105a8 != 0)) {
                  uVar3 = get_sau_ch_id();
                  _printk(&DAT_00110dc5,"distribute_packet_to_data_cdev",0x458,uVar3,
                          distribute_packet_to_data_cdev_last_channel_id,
                          distribute_packet_to_data_cdev_print_cnt);
                }
              }
            }
          }
        }
joined_r0x001156f8:
        if ((iVar4 != 0) && (DAT_001105a8 != 0)) {
          if (DAT_001104d0 == comm_master_upload_thread_packet_area) {
            lVar12 = 0;
LAB_00114cc0:
            plVar13 = &DAT_001104d8 + lVar12 * 3;
          }
          else {
            if (DAT_001104e8 == comm_master_upload_thread_packet_area) {
              lVar12 = 1;
              goto LAB_00114cc0;
            }
            if (DAT_00110500 == comm_master_upload_thread_packet_area) {
              lVar12 = 2;
              goto LAB_00114cc0;
            }
            if (DAT_00110518 == comm_master_upload_thread_packet_area) {
              lVar12 = 3;
              goto LAB_00114cc0;
            }
            if (DAT_00110530 == comm_master_upload_thread_packet_area) {
              lVar12 = 4;
              goto LAB_00114cc0;
            }
            if (DAT_00110548 == comm_master_upload_thread_packet_area) {
              lVar12 = 5;
              goto LAB_00114cc0;
            }
            if (DAT_00110560 == comm_master_upload_thread_packet_area) {
              lVar12 = 6;
              goto LAB_00114cc0;
            }
            if (DAT_00110578 == comm_master_upload_thread_packet_area) {
              lVar12 = 7;
              goto LAB_00114cc0;
            }
            plVar13 = &DAT_001104d8;
            if (DAT_00110590 == comm_master_upload_thread_packet_area) {
              lVar12 = 8;
              goto LAB_00114cc0;
            }
          }
          _printk(&DAT_00111dc2,"comm_master_upload_thread",0x502,DAT_001084ca,
                  *(undefined8 *)(*plVar13 + 0x20));
        }
        pm_wakeup_ws_event(spidev + 0x2e8,300,0);
        iVar4 = 0;
      }
      else {
        if (iVar5 == 2) {
          if (DAT_001105a8 != 0) {
            puVar11 = *(undefined2 **)(spidev + 0x68);
            _printk(&DAT_001124c6,"comm_master_upload_thread",0x50c,*puVar11,puVar11[1],puVar11[2],
                    puVar11[3]);
          }
          if ((comm_master_upload_thread_packet_area == 0x3b9) &&
             (uVar10 = (ulong)DAT_001084ca, DAT_001084ca != 0)) {
            uVar17 = 0;
            iVar5 = DAT_001105a8;
            do {
              if ((&DAT_001084cc)[uVar17] != -0x5b && iVar5 != 0) {
                _printk(&DAT_001121a3,"comm_master_upload_thread",0x511,uVar17 & 0xffffffff);
                uVar10 = (ulong)DAT_001084ca;
                iVar5 = DAT_001105a8;
              }
            } while ((uVar17 < 0x3fef) && (uVar17 = uVar17 + 1, uVar17 < uVar10));
          }
        }
        iVar4 = iVar4 + 1;
        if (0x1e < iVar4) {
          if (((DAT_001105a8 != 0) &&
              (_printk(&DAT_00112249,"comm_master_upload_thread",0x518), close_comm_state != 0)) &&
             (DAT_001105a8 != 0)) {
            _printk(&DAT_001125e9,"comm_master_upload_thread",0x519);
          }
          oplus_snshub_states_uevent(2,&DAT_001122f4);
          iVar4 = 0;
        }
      }
      goto LAB_00114d24;
    }
    if (DAT_001105c8 != 0) {
      _printk(&DAT_00110d77,"comm_master_upload_thread",0x508);
    }
  } while( true );
}



// ===========================================================
// Function: comm_master_download_thread at 00115ab4
// ===========================================================

void comm_master_download_thread(void)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  long lVar5;
  ulong uVar6;
  sched_param local_68 [2];
  
  local_68[0].__sched_priority = 0x36;
  iVar3 = sched_setscheduler((__pid_t)*(undefined8 *)(spidev + 0x138),1,local_68);
  if (iVar3 != 0 && DAT_001105a8 != 0) {
    _printk(&DAT_001110d4,"comm_master_download_thread",0x52d);
  }
  if (DAT_001105d8 != 0) {
    lVar5 = *(long *)(spidev + 0x138);
    _printk(&DAT_00111d0a,"comm_master_download_thread",0x52f,*(undefined4 *)(lVar5 + 0x640),
            *(undefined4 *)(lVar5 + 0x488),*(undefined4 *)(lVar5 + 0x7c));
  }
  do {
    while( true ) {
      __pm_relax(spidev + 0x218);
      down(spidev + 0x118);
      __pm_stay_awake(spidev + 0x218);
      lVar5 = DAT_001104d8;
      if ((((((*(int *)(DAT_001104d8 + 0x88) != *(int *)(DAT_001104d8 + 0x8c)) ||
             (lVar5 = DAT_001104f0, *(int *)(DAT_001104f0 + 0x88) != *(int *)(DAT_001104f0 + 0x8c)))
            || (lVar5 = DAT_00110508, *(int *)(DAT_00110508 + 0x88) != *(int *)(DAT_00110508 + 0x8c)
               )) || ((lVar5 = DAT_00110520,
                      *(int *)(DAT_00110520 + 0x88) != *(int *)(DAT_00110520 + 0x8c) ||
                      (lVar5 = DAT_00110538,
                      *(int *)(DAT_00110538 + 0x88) != *(int *)(DAT_00110538 + 0x8c))))) ||
          ((lVar5 = DAT_00110550, *(int *)(DAT_00110550 + 0x88) != *(int *)(DAT_00110550 + 0x8c) ||
           ((lVar5 = DAT_00110568, *(int *)(DAT_00110568 + 0x88) != *(int *)(DAT_00110568 + 0x8c) ||
            (lVar5 = DAT_00110580, *(int *)(DAT_00110580 + 0x88) != *(int *)(DAT_00110580 + 0x8c))))
           ))) || (lVar5 = DAT_00110598,
                  *(int *)(DAT_00110598 + 0x88) != *(int *)(DAT_00110598 + 0x8c))) break;
      memset(&comm_master_download_thread_packet_area,0,0x3ff4);
LAB_00115c9c:
      if (DAT_001105a8 != 0) {
        _printk(&DAT_00110b2d,"comm_master_download_thread",0x562);
      }
      msleep(10);
    }
    memset(&comm_master_download_thread_packet_area,0,0x3ff4);
    if (lVar5 == 0) goto LAB_00115c9c;
    sVar1 = is_sau_filter(*(undefined2 *)(lVar5 + 0x1c));
    if (sVar1 == 0) {
      memset(*(void **)(spidev + 0x60),0,0x3ffc);
      iVar3 = cdev_fifo_out_frame(lVar5 + 0x88,&comm_master_download_thread_packet_area);
      uVar2 = DAT_0010c4d2;
      if (iVar3 < 0) {
        if (DAT_001105a8 != 0) {
          _printk(&DAT_00110ca0,"comm_master_download_thread",0x545,*(undefined8 *)(lVar5 + 0x20),
                  iVar3);
        }
      }
      else if ((close_comm_state & 1) == 0) {
        mutex_lock(*(long *)(lVar5 + 8) + 0x70);
        iVar3 = comm_master_download(&DAT_0010c4d4,uVar2,comm_master_download_thread_packet_area);
        if (iVar3 == 0) {
          if ((DAT_001105e8 != 0) &&
             ((comm_master_download_thread_packet_area == 7 ||
              (comm_master_download_thread_packet_area == 1)))) {
            if (DAT_0010c4d4 < 0x400) {
              _printk(&DAT_0011104b,&DAT_00110bcb,(ulong)DAT_0010c4d4,DAT_0010c4d6);
            }
            else {
              uVar6 = (ulong)DAT_0010c4d4 & 0xff;
              if ((DAT_0010c4d4 >> 8 == 0x18) && ((int)uVar6 - 1U < 2)) {
                iVar3 = *(int *)(&test_msgid + uVar6 * 4);
                *(int *)(&test_msgid + uVar6 * 4) = iVar3 + 1;
                if (99 < iVar3 + 1) {
                  _printk(&DAT_001111ed,&DAT_00110bcb,uVar6,0x18,DAT_0010c4d6);
                  *(undefined4 *)(&test_msgid + uVar6 * 4) = 0;
                }
              }
              else {
                _printk(&DAT_00112209,&DAT_00110bcb,uVar6,DAT_0010c4d4 >> 8,DAT_0010c4d6);
              }
            }
          }
          piVar4 = (int *)(lVar5 + 0x260);
          *(int *)(lVar5 + 0x264) = *(int *)(lVar5 + 0x264) + 1;
        }
        else {
          piVar4 = (int *)(lVar5 + 0x268);
        }
        *piVar4 = *piVar4 + 1;
        mutex_unlock(*(long *)(lVar5 + 8) + 0x70);
        gpio_to_desc(*(undefined4 *)(spidev + 0xd0));
        iVar3 = gpiod_get_raw_value();
        if (iVar3 == 1) {
          msleep();
        }
      }
      else if (DAT_001105a8 != 0) {
        _printk(&DAT_00110e0c,"comm_master_download_thread",0x54b);
      }
    }
    else if (DAT_001105a8 != 0) {
      uVar2 = get_sau_ch_id();
      _printk(&DAT_00111970,"comm_master_download_thread",0x539,uVar2,*(undefined2 *)(lVar5 + 0x1c))
      ;
    }
  } while( true );
}



// ===========================================================
// Function: comm_master_download at 00115ec0
// ===========================================================

void comm_master_download(void *param_1,ulong param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  undefined1 auVar4 [16];
  ushort uVar5;
  ushort uVar6;
  byte bVar7;
  code *pcVar8;
  bool bVar9;
  short sVar10;
  int iVar11;
  int iVar12;
  undefined8 uVar13;
  undefined *puVar14;
  long lVar15;
  undefined2 *puVar16;
  long *plVar17;
  uint uVar18;
  ulong uVar19;
  ulong uVar20;
  long lVar21;
  ulong uVar22;
  ushort *puVar23;
  int iVar24;
  ulong uVar25;
  ushort *puVar26;
  uint uVar27;
  undefined8 local_88;
  long local_80;
  undefined8 local_78;
  long local_70;
  long local_68;
  
  lVar15 = sp_el0;
  local_68 = *(long *)(lVar15 + 0x648);
  sVar10 = is_sau_filter(param_3);
  uVar13 = 0xffffffea;
  if ((param_2 < 0x3ff1) && (sVar10 == 0)) {
    memset(&DAT_001044c4,0,0x3ff0);
    comm_master_download_packet_area = (undefined2)param_3;
    DAT_001044c2 = (ushort)param_2;
    memcpy(&DAT_001044c4,param_1,param_2);
    if (DAT_00110628 != 0) {
      _printk(&DAT_00111a9d,PTR_s_packet_to_mcu_00110620,(int)param_2 + 4,param_3 & 0xffff);
      print_hex_dump(&DAT_00110c3f,&DAT_00111a43,2,0x10,1,&comm_master_download_packet_area,
                     (ulong)DAT_001044c2 + 4,1);
    }
    iVar24 = 0;
    uVar27 = 1;
LAB_00115f84:
    local_78 = 0;
    local_70 = 0;
    local_88 = 0;
    local_80 = 0;
    uVar25 = (ulong)DAT_001044c2;
    wait_mcureseting();
    mutex_lock(spidev + 0xa0);
    do {
      iVar11 = down_trylock(spidev + 0x100);
    } while (iVar11 == 0);
    gpio_to_desc(*(undefined4 *)(spidev + 0xd8));
    iVar11 = gpiod_get_raw_value();
    if (iVar11 != 0) {
      uVar13 = gpio_to_desc(*(undefined4 *)(spidev + 0xd8));
      gpiod_direction_output_raw(uVar13,0);
      __const_udelay(0x10c7);
    }
    uVar25 = uVar25 + 4;
    iVar11 = 1000;
    do {
      gpio_to_desc(*(undefined4 *)(spidev + 0xd4));
      iVar12 = gpiod_get_raw_value();
      if (iVar12 == 0) goto LAB_001160b4;
      __const_udelay(0x10c7);
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    iVar11 = 500;
    do {
      gpio_to_desc(*(undefined4 *)(spidev + 0xd4));
      iVar12 = gpiod_get_raw_value();
      if (iVar12 == 0) goto LAB_001160b4;
      msleep(1);
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    DAT_00100298._4_4_ = DAT_00100298._4_4_ + 1;
    DAT_001002a0._0_4_ = (int)DAT_001002a0 + 1;
    if (2 < (int)DAT_001002a0) {
      if ((close_comm_state != 0) && (DAT_001105a8 != 0)) {
        _printk(&DAT_001125e9,"comm_master_dl_download",0x2fa);
      }
      oplus_snshub_states_uevent(2,&DAT_001122f4);
    }
    if (DAT_001105a8 != 0) {
      _printk(&DAT_00111163,"comm_master_dl_download",0x2fd,dn_selnum,(int)DAT_001002a0);
    }
    goto LAB_00116544;
  }
LAB_00116964:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x648) == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar13);
LAB_001160b4:
  lVar15 = spidev;
  puVar26 = *(ushort **)(spidev + 0x60);
  DAT_001002a0._0_4_ = 0;
  memset(puVar26 + 4,0,0x3ff4);
  bVar7 = is_first_dl_frame;
  uVar6 = dn_selnum;
  uVar18 = 0;
  puVar26[3] = (ushort)uVar25;
  uVar2 = (bVar7 ^ 0xffffffff) & 1;
  uVar1 = (uint)uVar25 & 0xffff;
  *puVar26 = uVar6;
  uVar5 = (ushort)uVar2;
  puVar26[1] = uVar5;
  if (1 < uVar1) {
    uVar18 = uVar1 >> 1;
    if (uVar18 < 2) {
      uVar18 = 1;
    }
    uVar20 = (ulong)uVar18;
    if (uVar20 - 0x1ffb < 0xffffffffffffe006) goto LAB_00116a34;
    uVar19 = uVar20 - 1;
    if (0x1ff9 < uVar19) {
      uVar19 = 0x1ffa;
    }
    if (uVar19 < 2) {
      uVar22 = 0;
      uVar18 = 0;
    }
    else {
      uVar22 = uVar19 + 1 & 1;
      iVar11 = 0;
      uVar3 = 2;
      if (uVar22 != 0) {
        uVar3 = uVar22;
      }
      iVar12 = 0;
      uVar22 = (uVar19 + 1) - uVar3;
      lVar21 = ~uVar19 + uVar3;
      puVar23 = &DAT_001044c2;
      do {
        lVar21 = lVar21 + 2;
        iVar11 = iVar11 + (uint)puVar23[-1];
        iVar12 = iVar12 + (uint)*puVar23;
        puVar23 = puVar23 + 2;
      } while (lVar21 != 0);
      uVar18 = iVar12 + iVar11;
    }
    uVar19 = 0;
    if (uVar22 < 0x1ffb) {
      uVar19 = 0x1ffa - uVar22;
    }
    lVar21 = uVar22 - uVar20;
    puVar23 = &comm_master_download_packet_area + uVar22;
    do {
      if (uVar19 <= ~uVar22 + uVar20) goto LAB_00116a34;
      bVar9 = lVar21 != -1;
      lVar21 = lVar21 + 1;
      uVar18 = uVar18 + *puVar23;
      puVar23 = puVar23 + 1;
    } while (bVar9);
  }
  if ((uVar25 & 1) != 0) {
    if (0xffc < uVar1 - 1 >> 2) {
LAB_00116a34:
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(1,0x116a38);
      (*pcVar8)();
    }
    uVar18 = uVar18 + *(byte *)((long)&comm_master_download_packet_area + (ulong)(uVar1 - 1));
  }
  uVar18 = ~(uVar18 + (uVar18 >> 0x10));
  puVar26[2] = (ushort)uVar18;
  puVar26[1] = uVar5 | (ushort)(~((int)(uVar25 >> 8) + (uint)uVar25 + (uint)uVar6 +
                                  (uint)(uVar6 >> 8) + uVar2 + uVar18 + (uVar18 >> 8)) << 8);
  memcpy(puVar26 + 4,&comm_master_download_packet_area,uVar25 & 0xffff);
  iVar11 = spidev_spi_sync(*(undefined8 *)(lVar15 + 0x60),0);
  if ((iVar11 != 0) && (DAT_001105a8 != 0)) {
    _printk(&DAT_00112474,"download_spi_seq",0x2ac,iVar11);
  }
  if (iVar11 < 0) {
    DAT_00100298._0_4_ = (int)DAT_00100298 + 1;
    if (0x13 < (int)DAT_00100298) {
      if ((close_comm_state != 0) && (DAT_001105a8 != 0)) {
        _printk(&DAT_001125e9,"comm_master_dl_download",0x30b);
      }
      oplus_snshub_states_uevent(2,&DAT_001122f4);
    }
    bVar9 = false;
    iVar11 = 1;
    if ((((uint)((int)DAT_00100298 * -0x33333333) >> 1 | (int)DAT_00100298 * -0x80000000) <
         0x1999999a || (int)DAT_00100298 < 0xb) && (DAT_001105a8 != 0)) {
      _printk(&DAT_001108be,"comm_master_dl_download",0x311,dn_selnum);
      bVar9 = false;
      if ((9 < (int)DAT_00100298) && (DAT_001105a8 != 0)) {
        uVar13 = 0x313;
LAB_00116490:
        iVar11 = 1;
        _printk(&DAT_001111a1,"comm_master_dl_download",uVar13,dn_selnum);
        bVar9 = false;
      }
    }
  }
  else {
    if ((10 < (int)DAT_00100298) && (DAT_001105c8 != 0)) {
      _printk(&DAT_00111754,"comm_master_dl_download",0x318,dn_selnum);
    }
    DAT_00100298._0_4_ = 0;
    iVar11 = down_timeout(spidev + 0x100,500);
    if (iVar11 < 0) {
      gpio_to_desc(*(undefined4 *)(spidev + 0xd4));
      iVar11 = gpiod_get_raw_value();
      if (iVar11 != 1) {
        dci._0_4_ = (int)dci + 1;
        dci._4_4_ = dci._4_4_ + 1;
        if ((int)dci._4_4_ < 3) {
LAB_00116538:
          if (DAT_001105a8 != 0) {
            _printk(&DAT_0011192b,"comm_master_dl_download",0x32a,dn_selnum);
            iVar11 = 1;
            bVar9 = false;
            if ((9 < (int)dci._4_4_) && (bVar9 = false, DAT_001105a8 != 0)) {
              uVar13 = 0x32c;
              goto LAB_00116490;
            }
            goto LAB_0011654c;
          }
        }
        else {
          if ((close_comm_state != 0) && (DAT_001105a8 != 0)) {
            _printk(&DAT_001125e9,"comm_master_dl_download",0x325);
          }
          oplus_snshub_states_uevent(2,&DAT_001122f4);
          if (((int)dci._4_4_ < 0xb) || (dci._4_4_ % 10 == 0)) goto LAB_00116538;
        }
LAB_00116544:
        iVar11 = 1;
        bVar9 = false;
        goto LAB_0011654c;
      }
      if (DAT_001105a8 != 0) {
        _printk(&DAT_00111feb,"wait_s2m_ans_pullup",0x16f);
      }
    }
    dci._4_4_ = 0;
    ktime_get_real_ts64(&local_88);
    iVar11 = 1000;
    do {
      gpio_to_desc(*(undefined4 *)(spidev + 0xd4));
      iVar12 = gpiod_get_raw_value();
      if (iVar12 == 0) goto LAB_00116340;
      __const_udelay(0x10c7);
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    iVar11 = 500;
    do {
      gpio_to_desc(*(undefined4 *)(spidev + 0xd4));
      iVar12 = gpiod_get_raw_value();
      if (iVar12 == 0) goto LAB_00116340;
      msleep(1);
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    if (DAT_001105a8 != 0) {
      _printk(&DAT_00111299,"comm_master_dl_download",0x334,dn_selnum);
    }
    iVar11 = 1;
    DAT_00100298._4_4_ = DAT_00100298._4_4_ + 1;
    DAT_001002a0._0_4_ = (int)DAT_001002a0 + 1;
    bVar9 = false;
  }
LAB_0011654c:
  uVar13 = gpio_to_desc(*(undefined4 *)(spidev + 0xd8));
  gpiod_direction_output_raw(uVar13,0);
  mutex_unlock(spidev + 0xa0);
  if (((param_3 & 0xffff) == 2) && (DAT_001105a8 != 0)) {
    if (DAT_001104d0 == 2) {
      lVar15 = 0;
LAB_001168b8:
      plVar17 = &DAT_001104d8 + lVar15 * 3;
    }
    else {
      if (DAT_001104e8 == 2) {
        lVar15 = 1;
        goto LAB_001168b8;
      }
      if (DAT_00110500 == 2) {
        lVar15 = 2;
        goto LAB_001168b8;
      }
      if (DAT_00110518 == 2) {
        lVar15 = 3;
        goto LAB_001168b8;
      }
      if (DAT_00110530 == 2) {
        lVar15 = 4;
        goto LAB_001168b8;
      }
      if (DAT_00110548 == 2) {
        lVar15 = 5;
        goto LAB_001168b8;
      }
      if (DAT_00110560 == 2) {
        lVar15 = 6;
        goto LAB_001168b8;
      }
      if (DAT_00110578 == 2) {
        lVar15 = 7;
        goto LAB_001168b8;
      }
      plVar17 = &DAT_001104d8;
      if (DAT_00110590 == 2) {
        lVar15 = 8;
        goto LAB_001168b8;
      }
    }
    _printk(&DAT_00111b49,"comm_master_download",0x4c5,*(undefined8 *)(*plVar17 + 0x20),param_2,
            iVar11,&DAT_001044c4);
    if (bVar9) goto LAB_00116900;
LAB_00116588:
    if ((close_comm_state & 1) == 0) {
      if (iVar11 == 1) {
        if (DAT_001105b8 != 0) {
          _printk(&DAT_00112148,"comm_master_download",0x4d7,uVar27 * 0x32);
        }
        msleep(uVar27 * 0x32);
      }
      else if ((iVar11 == 2) && (iVar24 = iVar24 + 1, iVar24 == 10)) {
        if ((close_comm_state != 0) && (DAT_001105a8 != 0)) {
          _printk(&DAT_001125e9,"comm_master_download",0x4d4);
        }
        oplus_snshub_states_uevent(2,&DAT_001122f4);
        iVar24 = 10;
      }
      if (uVar27 == 10) goto LAB_00116944;
      uVar27 = uVar27 + 1;
      goto LAB_00115f84;
    }
    if (DAT_001105a8 == 0) goto LAB_0011693c;
    puVar14 = &DAT_0011172a;
    uVar13 = 0x4ce;
  }
  else {
    if (!bVar9) goto LAB_00116588;
LAB_00116900:
    uVar13 = 0;
    if ((uVar27 < 2) || (DAT_001105b8 == 0)) goto LAB_00116964;
    puVar14 = &DAT_001118bd;
    uVar13 = 0x4ca;
  }
  _printk(puVar14,"comm_master_download",uVar13,uVar27);
LAB_0011693c:
  uVar13 = 0;
  goto LAB_00116964;
LAB_00116340:
  ktime_get_real_ts64(&local_78);
  auVar4 = SEXT816(local_70 - local_80) * SEXT816(0x20c49ba5e353f7cf);
  if (((int)(auVar4._8_8_ >> 7) - (auVar4._12_4_ >> 0x1f)) +
      ((int)local_78 - (int)local_88) * 1000000 < 50000) {
    iVar11 = 0;
    is_first_dl_frame = 1;
    DAT_001002a0._4_4_ = DAT_001002a0._4_4_ + 1;
    dn_selnum = dn_selnum + 1;
    bVar9 = true;
  }
  else {
    if ((DAT_001105a8 != 0) &&
       (_printk(&DAT_00111507,"comm_master_dl_download",0x343,dn_selnum), DAT_001105a8 != 0)) {
      puVar16 = *(undefined2 **)(spidev + 0x60);
      _printk(&DAT_00111ee2,"comm_master_dl_download",0x345,dn_selnum,*puVar16,puVar16[1],puVar16[3]
              ,puVar16[2]);
    }
    iVar11 = 2;
    DAT_001002a8._0_4_ = (int)DAT_001002a8 + 1;
    bVar9 = false;
  }
  goto LAB_0011654c;
LAB_00116944:
  uVar13 = 0xffffffff;
  if (((int)dci._4_4_ < 10) && (DAT_001105a8 != 0)) {
    _printk(&DAT_001118f9,"comm_master_download",0x4dc,10);
    uVar13 = 0xffffffff;
  }
  goto LAB_00116964;
}



// ===========================================================
// Function: spidev_spi_sync at 00116a3c
// ===========================================================

undefined4 spidev_spi_sync(void)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined8 ***local_c8;
  undefined8 ***pppuStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 ***local_a8;
  undefined8 ***local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 ***local_50;
  undefined8 ***local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x648);
  local_b8 = 0;
  uStack_b0 = 0;
  local_c8 = (undefined8 ****)0x0;
  pppuStack_c0 = (undefined8 ****)0x0;
  cpu_latency_qos_update_request(spidev + 0x18,0);
  while (*(int *)(spidev + 0x140) != 0) {
    msleep(10);
  }
  local_50 = &local_50;
  uStack_40 = 0;
  local_58 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = &local_a8;
  local_a0 = &local_a8;
  local_48 = local_50;
  uVar3 = __list_add_valid(&local_c8,&local_a8,&local_a8);
  if ((uVar3 & 1) != 0) {
    local_c8 = &local_a8;
    pppuStack_c0 = &local_a8;
    local_a8 = &local_c8;
    local_a0 = &local_c8;
  }
  uVar4 = 0xfffffff2;
  if (*(long *)(spidev + 0x10) != 0) {
    iVar2 = spi_sync(*(long *)(spidev + 0x10),&local_a8);
    uVar4 = 0;
    if (iVar2 != 0) {
      uVar4 = 0xfffffff2;
    }
  }
  cpu_latency_qos_update_request(spidev + 0x18,0xffffffff);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x648) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



// ===========================================================
// Function: spidev_read at 00116b80
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long spidev_read(long param_1,ulong param_2,ulong param_3)

{
  ushort *puVar1;
  ulong uVar2;
  int iVar3;
  ushort uVar4;
  undefined8 *puVar5;
  ulong uVar6;
  bool bVar7;
  int iVar8;
  ulong uVar9;
  ulong uVar10;
  void *__s;
  long lVar11;
  
  lVar11 = *(long *)(param_1 + 0xd8);
  __s = *(void **)(lVar11 + 0x150);
  mutex_lock(lVar11 + 0xe8);
  memset(__s,0,0x3ff4);
  iVar8 = rfifo_out(lVar11,*(uint *)(param_1 + 0x40) >> 0xb & 1);
  if (iVar8 < 1) {
    if (DAT_001105d8 != 0) {
      _printk(&DAT_001108fa,"spidev_read",0x669,*(undefined8 *)(lVar11 + 0x20),iVar8,
              *(undefined2 *)((long)__s + 2));
    }
  }
  else {
    uVar9 = (ulong)*(ushort *)((long)__s + 2);
    if (param_3 < uVar9) {
      if (DAT_001105a8 != 0) {
        _printk(&DAT_00111e69,"spidev_read",0x65b,0);
      }
      uVar9 = param_3 & 0xffffffff;
    }
    iVar8 = (int)uVar9;
    puVar1 = (ushort *)((long)__s + 4);
    __check_object_size(puVar1,uVar9,1);
    puVar5 = (undefined8 *)sp_el0;
    uVar6 = (long)(param_2 << 8) >> 8;
    if (((*(byte *)((long)puVar5 + 0x3e) >> 5 & 1) != 0) ||
       (uVar10 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
      uVar10 = param_2 & uVar6;
    }
    bVar7 = CARRY8(uVar10,uVar9);
    uVar10 = uVar10 + uVar9;
    uVar2 = 0;
    if (!bVar7 || uVar10 == 0) {
      uVar2 = 0x7fffffffff;
    }
    if (bVar7) {
      uVar10 = 0xffffffffffffffff;
    }
    if (!CARRY8(uVar10,~uVar2) && !CARRY8(uVar10 + ~uVar2,(ulong)bVar7) || uVar10 == uVar2 + !bVar7)
    {
      if (((uint)_cpu_hwcaps >> 0x1b & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr1_el1 = puVar5[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar5[1];
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
      if ((param_2 & uVar6 & 0xffffff8000000000) != 0) {
        param_2 = 0;
      }
      uVar9 = __arch_copy_to_user(param_2,puVar1,uVar9);
      if (((uint)_cpu_hwcaps >> 0x1b & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar10 = daif;
          daif = uVar10 | 0xc0;
        }
        uVar10 = ttbr1_el1;
        ttbr0_el1 = (uVar10 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar10 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
    }
    if (uVar9 == 0) {
      if (DAT_001105e8 != 0) {
        uVar4 = *puVar1;
        if ((*(short *)(lVar11 + 0x1c) == 7) || (*(short *)(lVar11 + 0x1c) == 1)) {
          if (uVar4 < 0x400) {
            _printk(&DAT_0011104b,&DAT_0011202c,(ulong)uVar4,*(undefined2 *)((long)__s + 6));
          }
          else {
            uVar9 = (ulong)uVar4 & 0xff;
            if ((uVar4 >> 8 == 0x18) && ((int)uVar9 - 1U < 2)) {
              iVar3 = *(int *)(&test_msgid + uVar9 * 4);
              *(int *)(&test_msgid + uVar9 * 4) = iVar3 + 1;
              if (99 < iVar3 + 1) {
                _printk(&DAT_001111ed,&DAT_0011202c,uVar9,0x18,*(undefined2 *)((long)__s + 6));
                *(undefined4 *)(&test_msgid + uVar9 * 4) = 0;
              }
            }
            else {
              _printk(&DAT_00112209,&DAT_0011202c,uVar9,uVar4 >> 8,*(undefined2 *)((long)__s + 6));
            }
          }
        }
      }
      *(int *)(lVar11 + 0x254) = *(int *)(lVar11 + 0x254) + 1;
    }
    else {
      if (DAT_001105a8 != 0) {
        _printk(&DAT_00110e7e,"spidev_read",0x664);
      }
      iVar8 = -0xe;
    }
    if (DAT_00110638 != 0) {
      _printk(&DAT_00110890,PTR_s_data_to_user_00110630,*(undefined2 *)((long)__s + 2),
              *(undefined8 *)(lVar11 + 0x20));
      print_hex_dump(&DAT_00110c3f,&DAT_00111a43,2,0x10,1,puVar1,*(undefined2 *)((long)__s + 2),1);
    }
  }
  mutex_unlock(lVar11 + 0xe8);
  return (long)iVar8;
}



// ===========================================================
// Function: spidev_write at 00116f38
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 spidev_write(long param_1,ulong param_2,ulong param_3)

{
  undefined2 *puVar1;
  ulong uVar2;
  undefined2 uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  bool bVar6;
  short sVar7;
  undefined2 uVar8;
  ulong __n;
  ulong uVar9;
  undefined8 uVar10;
  long lVar11;
  undefined2 *__s;
  
  if (param_3 < 0x3ff1) {
    lVar11 = *(long *)(param_1 + 0xd8);
    __s = *(undefined2 **)(lVar11 + 0x148);
    sVar7 = is_sau_filter(*(undefined2 *)(lVar11 + 0x1c));
    if (sVar7 == 0) {
      mutex_lock(lVar11 + 0x118);
      memset(__s,0,0x3ff4);
      puVar1 = __s + 2;
      uVar3 = *(undefined2 *)(lVar11 + 0x1c);
      __s[1] = (short)param_3;
      *__s = uVar3;
      __check_object_size(puVar1,param_3,0);
      puVar4 = (undefined8 *)sp_el0;
      uVar5 = (long)(param_2 << 8) >> 8;
      if (((*(byte *)((long)puVar4 + 0x3e) >> 5 & 1) != 0) ||
         (uVar9 = param_2, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
        uVar9 = param_2 & uVar5;
      }
      bVar6 = CARRY8(uVar9,param_3);
      uVar9 = uVar9 + param_3;
      uVar2 = 0;
      if (!bVar6 || uVar9 == 0) {
        uVar2 = 0x7fffffffff;
      }
      if (bVar6) {
        uVar9 = 0xffffffffffffffff;
      }
      __n = param_3;
      if (!CARRY8(uVar9,~uVar2) && !CARRY8(uVar9 + ~uVar2,(ulong)bVar6) || uVar9 == uVar2 + !bVar6)
      {
        if (((uint)_cpu_hwcaps >> 0x1b & 1) == 0) {
          uVar9 = daif;
          if ((uVar9 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr1_el1 = puVar4[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar4[1];
          InstructionSynchronizationBarrier();
          daif = uVar9;
        }
        if ((param_2 & uVar5 & 0xffffff8000000000) != 0) {
          param_2 = 0;
        }
        __n = __arch_copy_from_user(puVar1,param_2,param_3);
        if (((uint)_cpu_hwcaps >> 0x1b & 1) == 0) {
          uVar5 = daif;
          if ((uVar5 & 0x80) == 0) {
            uVar9 = daif;
            daif = uVar9 | 0xc0;
          }
          uVar9 = ttbr1_el1;
          ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar9 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar5;
        }
      }
      if (__n != 0) {
        memset((void *)((long)puVar1 + (param_3 - __n)),0,__n);
      }
      if (DAT_00110648 != 0) {
        _printk(&DAT_00110890,PTR_s_data_from_user_00110640,param_3,*(undefined8 *)(lVar11 + 0x20));
        print_hex_dump(&DAT_00110c3f,&DAT_00111a43,2,0x10,1,puVar1,param_3,1);
      }
      if ((__n != 0) && (DAT_001105a8 != 0)) {
        _printk(&DAT_001109af,"spidev_write",0x695);
      }
      uVar10 = wfifo_in(lVar11,*(uint *)(param_1 + 0x40) >> 0xb & 1);
      mutex_unlock(lVar11 + 0x118);
    }
    else {
      if (DAT_001105a8 != 0) {
        uVar3 = *(undefined2 *)(lVar11 + 0x1c);
        uVar8 = get_sau_ch_id();
        _printk(&DAT_00110bd0,"spidev_write",0x687,uVar3,param_3,uVar8);
      }
      msleep(10);
      uVar10 = 0xfffffffffffffff0;
    }
  }
  else if (DAT_001105a8 == 0) {
    uVar10 = 0xffffffffffffffea;
  }
  else {
    _printk(&DAT_00111bdd,"spidev_write",0x680,param_3);
    uVar10 = 0xffffffffffffffea;
  }
  return uVar10;
}



// ===========================================================
// Function: spidev_open at 00117264
// ===========================================================

undefined8 spidev_open(long param_1,long param_2)

{
  undefined8 uVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar2 = *(uint *)(param_1 + 0x4c);
  puVar3 = DAT_001104d8;
  if ((((((*DAT_001104d8 == uVar2) || (puVar3 = DAT_001104f0, *DAT_001104f0 == uVar2)) ||
        (puVar3 = DAT_00110508, *DAT_00110508 == uVar2)) ||
       ((puVar3 = DAT_00110520, *DAT_00110520 == uVar2 ||
        (puVar3 = DAT_00110538, *DAT_00110538 == uVar2)))) ||
      ((puVar3 = DAT_00110550, *DAT_00110550 == uVar2 ||
       ((puVar3 = DAT_00110568, *DAT_00110568 == uVar2 ||
        (puVar3 = DAT_00110580, *DAT_00110580 == uVar2)))))) ||
     (puVar3 = DAT_00110598, *DAT_00110598 == uVar2)) {
    uVar2 = puVar3[6];
    if (uVar2 == 0) {
      if ((short)puVar3[7] == 9) {
        set_sau_ch_id(9);
        uVar2 = puVar3[6];
      }
      else {
        uVar2 = 0;
      }
    }
    puVar3[6] = uVar2 + 1;
    *(uint **)(param_2 + 0xd8) = puVar3;
    nonseekable_open(param_1,param_2);
    uVar1 = 0;
  }
  else if (DAT_001105a8 == 0) {
    uVar1 = 0xfffffffa;
  }
  else {
    _printk(&DAT_00110ab9,"spidev_open",0x6af,uVar2 & 0xfffff);
    uVar1 = 0xfffffffa;
  }
  return uVar1;
}



// ===========================================================
// Function: spidev_release at 001173c8
// ===========================================================

undefined8 spidev_release(undefined8 param_1,long param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_2 + 0xd8);
  if (*(int *)(lVar3 + 0x88) != *(int *)(lVar3 + 0x8c)) {
    iVar2 = -0x13;
    do {
      msleep(5);
      if (*(int *)(lVar3 + 0x88) == *(int *)(lVar3 + 0x8c)) break;
      bVar1 = iVar2 != 0;
      iVar2 = iVar2 + 1;
    } while (bVar1);
  }
  iVar2 = *(int *)(lVar3 + 0x18);
  if (iVar2 == 1) {
    if (*(short *)(lVar3 + 0x1c) != 9) {
      *(undefined4 *)(lVar3 + 0x18) = 0;
      goto LAB_00117448;
    }
    set_sau_ch_id(0);
    iVar2 = *(int *)(lVar3 + 0x18);
  }
  if ((iVar2 != 0) && (*(int *)(lVar3 + 0x18) = iVar2 + -1, iVar2 + -1 != 0)) {
    return 0;
  }
LAB_00117448:
  up(lVar3 + 0x70);
  mutex_lock(lVar3 + 0x40);
  *(undefined8 *)(lVar3 + 0x28) = 0;
  mutex_unlock(lVar3 + 0x40);
  mutex_lock(lVar3 + 0xa0);
  *(undefined8 *)(lVar3 + 0x88) = 0;
  mutex_unlock(lVar3 + 0xa0);
  return 0;
}



// ===========================================================
// Function: log_show at 00117494
// ===========================================================

long log_show(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined *puVar2;
  ulong uVar3;
  long lVar4;
  undefined **ppuVar5;
  
  uVar3 = 0;
  lVar4 = 0;
  ppuVar5 = &log_array;
  do {
    puVar2 = *ppuVar5;
    if (puVar2 != (undefined *)0x0) {
      if (((uint)uVar3 & 0xff) * -0x55555555 < 0x55555556) {
        iVar1 = snprintf((char *)(param_3 + lVar4),0x1000 - lVar4,"\n");
        puVar2 = *ppuVar5;
        lVar4 = lVar4 + iVar1;
      }
      iVar1 = snprintf((char *)(param_3 + lVar4),0x1000 - lVar4,"bit %d, sw %d [%s]\n",
                       uVar3 & 0xffffffff,(ulong)*(uint *)(ppuVar5 + 1),puVar2);
      lVar4 = lVar4 + iVar1;
    }
    uVar3 = uVar3 + 1;
    ppuVar5 = ppuVar5 + 2;
  } while (uVar3 != 0x20);
  iVar1 = snprintf((char *)(param_3 + lVar4),0x1000 - lVar4,
                   "\ninput OCT value to change log level\n");
  return lVar4 + iVar1;
}



// ===========================================================
// Function: log_store at 00117588
// ===========================================================

undefined8 log_store(undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  uint *puVar4;
  long local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x648);
  local_30 = 0;
  uVar1 = simple_strtol(param_3,&local_30,0);
  if (local_30 == param_3) {
    param_4 = 0xffffffffffffffea;
  }
  else {
    lVar3 = 0;
    puVar4 = &DAT_001105a8;
    do {
      uVar2 = (uint)lVar3;
      lVar3 = lVar3 + 1;
      *puVar4 = uVar1 >> (ulong)(uVar2 & 0x1f) & 1;
      puVar4 = puVar4 + 4;
    } while (lVar3 != 0x20);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x648) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



// ===========================================================
// Function: info_show at 0011762c
// ===========================================================

long info_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  
  uVar3 = *(uint *)(spidev + 0xd8);
  gpio_to_desc(uVar3);
  uVar10 = gpiod_get_raw_value();
  uVar4 = *(uint *)(spidev + 0xd4);
  gpio_to_desc(uVar4);
  uVar11 = gpiod_get_raw_value();
  uVar5 = *(undefined4 *)(spidev + 0xd0);
  uVar6 = *(uint *)(spidev + 0xe4);
  gpio_to_desc(uVar5);
  uVar7 = gpiod_get_raw_value();
  uVar1 = *(undefined4 *)(spidev + 0xdc);
  uVar2 = *(undefined4 *)(spidev + 0xe0);
  gpio_to_desc(uVar1);
  uVar8 = gpiod_get_raw_value();
  iVar9 = snprintf(param_3,0x1000,
                   "--gpio info:\n m2s_int: gpio(%d) value(%d) output\n s2m_ans: gpio(%d) value(%d) irq(%d)\n s2m_int: gpio(%d) value(%d) irq(%d)\n m2s_ans: gpio(%d) value(%d) output\n\n"
                   ,(ulong)uVar3,uVar10 & 0xffffffff,(ulong)uVar4,uVar11 & 0xffffffff,(ulong)uVar6,
                   uVar5,uVar7,uVar2,uVar1,uVar8);
  lVar13 = (long)iVar9;
  iVar9 = snprintf(param_3 + lVar13,0x1000 - lVar13,
                   "--download datalink(write) info:\n s2m_ans_pu_timeout: %d\n s2m_ans_pu_con_timeout: %d\n dn_write_seq_fail: %d\n s2m_ans_pd_timeout: %d\n dn_frame_suc: %d\n dn_frame_check_err: %d\n\n"
                   ,(ulong)(uint)dci,(ulong)dci._4_4_,(ulong)(uint)DAT_00100298,
                   (ulong)DAT_00100298._4_4_,(ulong)DAT_001002a0._4_4_,(undefined4)DAT_001002a8);
  lVar13 = lVar13 + iVar9;
  iVar9 = snprintf(param_3 + lVar13,0x1000 - lVar13,
                   "--upload datalink(read) info:\n up_frame_discontinuous: %d\n up_frame_check_err: %d\n up_frame_suc: %d\n up_disturb_signal: %d\n up_read_seq_fail: %d\n s2m_int_down_trylock: %d\n\n"
                   ,(ulong)DAT_001002a8._4_4_,(ulong)(uint)DAT_001002b0,(ulong)DAT_001002b0._4_4_,
                   (ulong)(uint)DAT_001002b8,(ulong)DAT_001002b8._4_4_,DAT_001002c0);
  lVar14 = 0x10;
  lVar13 = lVar13 + iVar9;
  do {
    lVar12 = *(long *)((long)&g_cdev_info_list + lVar14);
    iVar9 = snprintf(param_3 + lVar13,0x1000 - lVar13,
                     "--channel %s info:\n rx_fifo_full: %d\n rx_packet_to_fifo: %d\n rx_packet_to_user: %d\n tx_fifo_full: %d\n tx_packet_to_fifo: %d\n tx_packet_to_mcu: %d\n tx_packet_send_suc: %d\n tx_packet_send_fail: %d\n\n"
                     ,*(undefined8 *)(lVar12 + 0x20),(ulong)*(uint *)(lVar12 + 0x24c),
                     (ulong)*(uint *)(lVar12 + 0x250),(ulong)*(uint *)(lVar12 + 0x254),
                     (ulong)*(uint *)(lVar12 + 600),*(undefined4 *)(lVar12 + 0x25c),
                     *(undefined4 *)(lVar12 + 0x260),*(undefined4 *)(lVar12 + 0x264),
                     *(undefined4 *)(lVar12 + 0x268),uVar8);
    lVar14 = lVar14 + 0x18;
    lVar13 = lVar13 + iVar9;
  } while (lVar14 != 0xe8);
  return lVar13;
}



// ===========================================================
// Function: info_store at 001177e8
// ===========================================================

undefined8 info_store(undefined8 param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  iVar4 = strncmp(param_3,"clean",5);
  lVar2 = DAT_001104f0;
  lVar1 = DAT_001104d8;
  if (iVar4 == 0) {
    DAT_001002c0 = 0;
    DAT_001002b0 = 0;
    DAT_001002b8 = 0;
    DAT_001002a0 = 0;
    DAT_001002a8 = 0;
    dci = 0;
    DAT_00100298 = 0;
    *(undefined8 *)(DAT_001104d8 + 0x248) = 0;
    *(undefined8 *)(lVar1 + 0x250) = 0;
    *(undefined8 *)(lVar1 + 600) = 0;
    *(undefined8 *)(lVar1 + 0x260) = 0;
    *(undefined4 *)(lVar1 + 0x268) = 0;
    lVar1 = DAT_00110508;
    *(undefined8 *)(lVar2 + 0x248) = 0;
    *(undefined8 *)(lVar2 + 0x250) = 0;
    *(undefined8 *)(lVar2 + 600) = 0;
    *(undefined8 *)(lVar2 + 0x260) = 0;
    *(undefined4 *)(lVar2 + 0x268) = 0;
    lVar2 = DAT_00110520;
    *(undefined8 *)(lVar1 + 0x248) = 0;
    *(undefined8 *)(lVar1 + 0x250) = 0;
    *(undefined8 *)(lVar1 + 600) = 0;
    *(undefined8 *)(lVar1 + 0x260) = 0;
    *(undefined4 *)(lVar1 + 0x268) = 0;
    lVar1 = DAT_00110538;
    *(undefined8 *)(lVar2 + 0x248) = 0;
    *(undefined8 *)(lVar2 + 0x250) = 0;
    *(undefined8 *)(lVar2 + 600) = 0;
    *(undefined8 *)(lVar2 + 0x260) = 0;
    *(undefined4 *)(lVar2 + 0x268) = 0;
    lVar2 = DAT_00110550;
    *(undefined8 *)(lVar1 + 0x248) = 0;
    *(undefined8 *)(lVar1 + 0x250) = 0;
    *(undefined8 *)(lVar1 + 600) = 0;
    *(undefined8 *)(lVar1 + 0x260) = 0;
    *(undefined4 *)(lVar1 + 0x268) = 0;
    lVar1 = DAT_00110568;
    *(undefined8 *)(lVar2 + 0x248) = 0;
    *(undefined8 *)(lVar2 + 0x250) = 0;
    *(undefined8 *)(lVar2 + 600) = 0;
    *(undefined8 *)(lVar2 + 0x260) = 0;
    *(undefined4 *)(lVar2 + 0x268) = 0;
    lVar3 = DAT_00110598;
    lVar2 = DAT_00110580;
    *(undefined8 *)(lVar1 + 0x248) = 0;
    *(undefined8 *)(lVar1 + 0x250) = 0;
    *(undefined8 *)(lVar1 + 600) = 0;
    *(undefined8 *)(lVar1 + 0x260) = 0;
    *(undefined4 *)(lVar1 + 0x268) = 0;
    *(undefined8 *)(lVar2 + 0x248) = 0;
    *(undefined8 *)(lVar2 + 0x250) = 0;
    *(undefined8 *)(lVar2 + 600) = 0;
    *(undefined8 *)(lVar2 + 0x260) = 0;
    *(undefined4 *)(lVar2 + 0x268) = 0;
    *(undefined4 *)(lVar3 + 0x268) = 0;
    *(undefined8 *)(lVar3 + 0x260) = 0;
    *(undefined8 *)(lVar3 + 600) = 0;
    *(undefined8 *)(lVar3 + 0x250) = 0;
    *(undefined8 *)(lVar3 + 0x248) = 0;
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  return param_4;
}



// ===========================================================
// Function: commstop_show at 00117928
// ===========================================================

long commstop_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"master comm state(%d)\n",(ulong)close_comm_state);
  return (long)iVar1;
}



// ===========================================================
// Function: commstop_store at 00117960
// ===========================================================

undefined8
commstop_store(undefined8 param_1,undefined8 param_2,undefined1 *param_3,undefined8 param_4)

{
  long lVar1;
  
  if (DAT_001105a8 != 0) {
    _printk(&DAT_001120e0,"commstop_store",0x806);
  }
  if ((*(long *)(spidev + 0x130) == 0) || (*(long *)(spidev + 0x138) == 0)) {
    if (DAT_001105a8 == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      _printk(&DAT_00111a51,"commstop_store",0x808);
      param_4 = 0xffffffffffffffff;
    }
  }
  else {
    switch(*param_3) {
    case 0x30:
      if (DAT_001105a8 == 0) {
        close_comm_state = 0;
        return param_4;
      }
      _printk(&DAT_00110f7e,"commstop_store",0x816);
      close_comm_state = 0;
      break;
    case 0x31:
      if (DAT_001105a8 == 0) {
        close_comm_state = 3;
        return param_4;
      }
      _printk(&DAT_0011102d,"commstop_store",0x80d);
      close_comm_state = 3;
      break;
    case 0x32:
      if (DAT_001105a8 == 0) {
        close_comm_state = 2;
        return param_4;
      }
      _printk(&DAT_001121e3,"commstop_store",0x810);
      close_comm_state = 2;
      break;
    case 0x33:
      if (DAT_001105a8 == 0) {
        close_comm_state = 1;
        return param_4;
      }
      _printk(&DAT_00111eba,"commstop_store",0x813);
      close_comm_state = 1;
      break;
    default:
      if (DAT_001105a8 == 0) {
        return 0xffffffffffffffea;
      }
      _printk(&DAT_00110e5d,"commstop_store",0x819);
      return 0xffffffffffffffea;
    }
    if (DAT_001105a8 != 0) {
      lVar1 = sp_el0;
      _printk(&DAT_00111858,"commstop_store",0x820,lVar1 + 0x810,*(undefined4 *)(lVar1 + 0x640));
    }
  }
  return param_4;
}



// ===========================================================
// Function: auto_reset_mcu_show at 00117b4c
// ===========================================================

long auto_reset_mcu_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%d",(ulong)*(uint *)(spidev + 0x3b8));
  return (long)iVar1;
}



// ===========================================================
// Function: auto_reset_mcu_store at 00117b88
// ===========================================================

undefined8
auto_reset_mcu_store(undefined8 param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_001105a8;
  if (*param_3 == '1') {
    uVar2 = 1;
  }
  else {
    if (*param_3 != '0') {
      return 0xffffffffffffffea;
    }
    uVar2 = 0;
  }
  dci._4_4_ = 0xfffffff6;
  *(undefined4 *)(spidev + 0x3b8) = uVar2;
  if (iVar1 != 0) {
    _printk(&DAT_00111352,"auto_reset_mcu_store",0x775);
  }
  return param_4;
}



// ===========================================================
// Function: speedtest_show at 00117c14
// ===========================================================

void speedtest_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  uint *puVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  undefined8 uVar9;
  ulong local_40;
  ulong local_38;
  char *local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x648);
  local_40 = 0;
  local_38 = 0;
  local_30 = param_3;
  sVar5 = get_sau_ch_id();
  if (sVar5 != 0) {
    uVar6 = get_sau_ch_id();
    iVar7 = snprintf(param_3,0x1000,"ch(%d) stand alone used, not support speedtest\n",
                     (ulong)(uVar6 & 0xffff));
    uVar8 = (ulong)iVar7;
    goto LAB_00117d00;
  }
  speed_test_complt = 0;
  local_40 = kthread_create_on_node(speedtest_thread_cfi_jt,&local_40,0xffffffff,"speed_test_thd");
  if (0xfffffffffffff000 < local_40) {
    uVar8 = local_40;
    if (DAT_001105a8 != 0) {
      _printk(&DAT_001119ae,"speedtest_show",0x7e4);
      uVar8 = local_40;
    }
    goto LAB_00117d00;
  }
  puVar1 = (uint *)(local_40 + 0x38);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar6 = *puVar1;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = uVar6 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  if (uVar6 == 0) {
    uVar9 = 2;
LAB_00117d74:
    refcount_warn_saturate(puVar1,uVar9);
  }
  else if ((int)(uVar6 + 1 | uVar6) < 0) {
    uVar9 = 1;
    goto LAB_00117d74;
  }
  wake_up_process(local_40);
  if ((speed_test_complt & 1) == 0) {
    do {
      msleep(1000);
    } while (speed_test_complt != 1);
  }
  kthread_stop(local_40);
  uVar8 = local_38;
LAB_00117d00:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x648) == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar8);
}



// ===========================================================
// Function: speedtest_store at 00117d7c
// ===========================================================

undefined8 speedtest_store(void)

{
  undefined8 in_x3;
  
  return in_x3;
}



// ===========================================================
// Function: speedtest_thread at 00117d84
// ===========================================================

undefined8 speedtest_thread(long *param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auVar4 [16];
  int iVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  sched_param local_90 [2];
  undefined8 local_88;
  long local_80;
  undefined8 local_78;
  long local_70;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x648);
  local_90[0].__sched_priority = 0x36;
  iVar6 = sched_setscheduler((__pid_t)*param_1,1,local_90);
  if ((iVar6 != 0) && (DAT_001105a8 != 0)) {
    _printk(&DAT_00112106,"speedtest_thread",0x79a);
  }
  if (DAT_001105d8 != 0) {
    lVar7 = *param_1;
    _printk(&DAT_0011242c,"speedtest_thread",0x79c,*(undefined4 *)(lVar7 + 0x640),
            *(undefined4 *)(lVar7 + 0x488),*(undefined4 *)(lVar7 + 0x7c));
  }
  mutex_lock(spidev + 0x70);
  lVar7 = 1;
  do {
    uVar2 = *(uint *)(&UNK_00112a24 + lVar7 * 4);
    uVar8 = (ulong)uVar2;
    if (DAT_001105c8 != 0) {
      _printk(&DAT_00111129,"speedtest_thread",0x7b0,uVar8);
    }
    local_78 = 0;
    local_70 = 0;
    local_88 = 0;
    local_80 = 0;
    memset(&speedtest_send_data_buf,0xa5,0x3ff0);
    ktime_get_real_ts64(&local_88);
    iVar6 = 2000;
    do {
      comm_master_download(&speedtest_send_data_buf,uVar8 & 0xffff,0x3b9);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    ktime_get_real_ts64(&local_78);
    auVar4 = SEXT816(local_70 - local_80) * SEXT816(0x20c49ba5e353f7cf);
    iVar5 = (((int)(auVar4._8_8_ >> 7) - (auVar4._12_4_ >> 0x1f)) +
            ((int)local_78 - (int)local_88) * 1000000) / 100000;
    iVar6 = 0;
    if (iVar5 != 0) {
      iVar6 = ((int)(uVar8 & 0xffff) * 2000) / iVar5;
    }
    uVar3 = 0;
    if (uVar2 != 0) {
      uVar3 = (iVar6 * 10) / (int)uVar2;
    }
    iVar6 = snprintf((char *)(param_1[2] + param_1[1]),0x1000 - param_1[1],
                     "download: packet_size(%d), speed(%dB/s), frequency(%dHz)\n",uVar8,
                     (ulong)(uint)(iVar6 * 10),(ulong)uVar3);
    param_1[1] = param_1[1] + (long)iVar6;
    if (DAT_001105c8 != 0) {
      _printk(&DAT_00110ce0,"speedtest_thread",0x7b5,uVar8);
    }
    lVar7 = lVar7 + 1;
  } while (lVar7 != 5);
  upload_speed_string_ready = 0;
  comm_master_download(&DAT_00110a2c,1,0x3b8);
  if (DAT_001105c8 != 0) {
    _printk(&DAT_001119ee,"speedtest_thread",0x7bc);
  }
  if ((upload_speed_string_ready & 1) == 0) {
    iVar6 = -0x3b;
    do {
      msleep_interruptible(1000);
      if ((upload_speed_string_ready & 1) != 0) break;
      bVar1 = iVar6 != 0;
      iVar6 = iVar6 + 1;
    } while (bVar1);
    if (upload_speed_string_ready == 0) {
      iVar6 = snprintf((char *)(param_1[2] + param_1[1]),0x1000 - param_1[1],
                       "upload: test timeout\n");
      goto LAB_00118004;
    }
  }
  iVar6 = snprintf((char *)(param_1[2] + param_1[1]),0x1000 - param_1[1],"%s",&upload_speed_string);
LAB_00118004:
  param_1[1] = param_1[1] + (long)iVar6;
  if (DAT_001105c8 != 0) {
    _printk(&DAT_00110b92,"speedtest_thread",0x7ca);
  }
  mutex_unlock(spidev + 0x70);
  speed_test_complt = 1;
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x648) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



// ===========================================================
// Function: ccch_write.cfi_jt at 001180fc
// ===========================================================

undefined4 ccch_write_cfi_jt(long param_1,void *param_2,int param_3,uint param_4)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined2 *__s;
  
  if (param_1 == 0) {
    if (DAT_001105a8 != 0) {
      _printk(&DAT_001112d5,"ccch_write",0x5a4);
    }
  }
  else {
    if (*(int *)(param_1 + 0x18) != 0) {
      __s = *(undefined2 **)(param_1 + 0x148);
      mutex_lock(param_1 + 0x118);
      memset(__s,0,0x3ff4);
      uVar1 = *(undefined2 *)(param_1 + 0x1c);
      __s[1] = (short)param_3;
      *__s = uVar1;
      memcpy(__s + 2,param_2,(long)param_3);
      if (DAT_00110618 != 0) {
        _printk(&DAT_00110a82,PTR_s_packet_to_fifo_00110610,param_3,*(undefined8 *)(param_1 + 0x20))
        ;
        print_hex_dump(&DAT_00110c3f,&DAT_00111a43,2,0x10,1,__s + 2,(long)param_3,1);
      }
      uVar2 = wfifo_in(param_1,param_4 & 1);
      mutex_unlock(param_1 + 0x118);
      return uVar2;
    }
    if (DAT_001105a8 != 0) {
      _printk(&DAT_00111f89,"ccch_write",0x5a9,*(undefined8 *)(param_1 + 0x20));
    }
  }
  return 0xffffffea;
}



// ===========================================================
// Function: ccch_read.cfi_jt at 00118100
// ===========================================================

uint ccch_read_cfi_jt(long param_1,void *param_2,uint param_3,uint param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  long lVar6;
  
  if (param_2 == (void *)0x0) {
    if (DAT_001105a8 != 0) {
      puVar4 = &DAT_00111d51;
      uVar5 = 0x5f9;
LAB_00113828:
      _printk(puVar4,"ccch_read",uVar5);
      return 0xffffffea;
    }
  }
  else if (param_1 == 0) {
    if (DAT_001105a8 != 0) {
      puVar4 = &DAT_0011154f;
      uVar5 = 0x5fe;
      goto LAB_00113828;
    }
  }
  else {
    if (*(int *)(param_1 + 0x18) != 0) {
      lVar6 = *(long *)(param_1 + 0x150);
      mutex_lock(param_1 + 0xe8);
      uVar3 = rfifo_out(param_1,param_4 & 1);
      if ((int)uVar3 < 1) {
        if (DAT_001105d8 != 0) {
          _printk(&DAT_00110fcb,"ccch_read",0x617,*(undefined8 *)(param_1 + 0x20),uVar3,
                  *(undefined2 *)(lVar6 + 2));
        }
      }
      else {
        uVar1 = *(ushort *)(lVar6 + 2);
        iVar2 = uVar1 - param_3;
        uVar3 = (uint)uVar1;
        if ((iVar2 != 0 && (int)param_3 <= (int)(uint)uVar1) && (uVar3 = param_3, DAT_001105a8 != 0)
           ) {
          _printk(&DAT_00111e69,"ccch_read",0x610,iVar2);
        }
        memcpy(param_2,(void *)(lVar6 + 4),(long)(int)uVar3);
        if (DAT_00110638 != 0) {
          _printk(&DAT_00110890,PTR_s_data_to_user_00110630,*(undefined2 *)(lVar6 + 2),
                  *(undefined8 *)(param_1 + 0x20));
          print_hex_dump(&DAT_00110c3f,&DAT_00111a43,2,0x10,1,(void *)(lVar6 + 4),
                         *(undefined2 *)(lVar6 + 2),1);
        }
      }
      mutex_unlock(param_1 + 0xe8);
      return uVar3;
    }
    if (DAT_001105a8 != 0) {
      _printk(&DAT_00112406,"ccch_read",0x603,*(undefined8 *)(param_1 + 0x20));
      return 0xffffffea;
    }
  }
  return 0xffffffea;
}



// ===========================================================
// Function: ccch_open.cfi_jt at 00118104
// ===========================================================

long ccch_open_cfi_jt(char *param_1)

{
  undefined *puVar1;
  int iVar2;
  size_t sVar3;
  long lVar4;
  
  puVar1 = g_cdev_info_list;
  if (param_1 == (char *)0x0) {
    if (DAT_001105a8 == 0) {
      return 0;
    }
    _printk(&DAT_001116d8,"get_cdev_by_name",0x3a5);
  }
  else {
    sVar3 = strlen(g_cdev_info_list);
    iVar2 = strncmp(param_1,puVar1,sVar3);
    puVar1 = PTR_s_dcc_datah_001104e0;
    if (iVar2 == 0) {
      lVar4 = 0;
    }
    else {
      sVar3 = strlen(PTR_s_dcc_datah_001104e0);
      iVar2 = strncmp(param_1,puVar1,sVar3);
      puVar1 = PTR_s_dcc_data_001104f8;
      if (iVar2 == 0) {
        lVar4 = 1;
      }
      else {
        sVar3 = strlen(PTR_s_dcc_data_001104f8);
        iVar2 = strncmp(param_1,puVar1,sVar3);
        puVar1 = PTR_s_mcu_factory_00110510;
        if (iVar2 == 0) {
          lVar4 = 2;
        }
        else {
          sVar3 = strlen(PTR_s_mcu_factory_00110510);
          iVar2 = strncmp(param_1,puVar1,sVar3);
          puVar1 = PTR_s_gps_data_00110528;
          if (iVar2 == 0) {
            lVar4 = 3;
          }
          else {
            sVar3 = strlen(PTR_s_gps_data_00110528);
            iVar2 = strncmp(param_1,puVar1,sVar3);
            puVar1 = PTR_s_std_sns_00110540;
            if (iVar2 == 0) {
              lVar4 = 4;
            }
            else {
              sVar3 = strlen(PTR_s_std_sns_00110540);
              iVar2 = strncmp(param_1,puVar1,sVar3);
              puVar1 = PTR_DAT_00110558;
              if (iVar2 == 0) {
                lVar4 = 5;
              }
              else {
                sVar3 = strlen(PTR_DAT_00110558);
                iVar2 = strncmp(param_1,puVar1,sVar3);
                puVar1 = PTR_s_haptic_00110570;
                if (iVar2 == 0) {
                  lVar4 = 6;
                }
                else {
                  sVar3 = strlen(PTR_s_haptic_00110570);
                  iVar2 = strncmp(param_1,puVar1,sVar3);
                  puVar1 = PTR_s_audioh_00110588;
                  if (iVar2 == 0) {
                    lVar4 = 7;
                  }
                  else {
                    sVar3 = strlen(PTR_s_audioh_00110588);
                    iVar2 = strncmp(param_1,puVar1,sVar3);
                    if (iVar2 != 0) goto LAB_00113d3c;
                    lVar4 = 8;
                  }
                }
              }
            }
          }
        }
      }
    }
    lVar4 = (&DAT_001104d8)[lVar4 * 3];
    if (lVar4 != 0) {
      iVar2 = *(int *)(lVar4 + 0x18);
      if (iVar2 != 0 && DAT_001105a8 != 0) {
        _printk(&DAT_001113fd,"ccch_open",0x628,param_1);
        iVar2 = *(int *)(lVar4 + 0x18);
      }
      *(int *)(lVar4 + 0x18) = iVar2 + 1;
      return lVar4;
    }
  }
LAB_00113d3c:
  if (DAT_001105a8 != 0) {
    _printk(&DAT_00110986,"ccch_open",0x623);
  }
  return 0;
}



// ===========================================================
// Function: init_module.cfi_jt at 00118108
// ===========================================================

ulong init_module_cfi_jt(void)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  undefined *puVar4;
  long lVar5;
  
  uVar3 = __class_create(&__this_module,&DAT_001122f4,&spidev);
  spidev_class = uVar3;
  if (uVar3 < 0xfffffffffffff001) {
    lVar5 = 0;
    do {
      iVar1 = class_create_file_ns(spidev_class,(long)&attributes + lVar5,0);
      if (iVar1 != 0) {
        _printk(&DAT_00110c42);
      }
      lVar5 = lVar5 + 0x20;
    } while (lVar5 != 0xa0);
    uVar2 = __register_chrdev(0x99,0,0x100,&DAT_00111671,&spidev_fops);
    if ((int)uVar2 < 0) {
      puVar4 = &DAT_001116f5;
    }
    else {
      uVar2 = __spi_register_driver(&__this_module,&spidev_spi_driver);
      if (-1 < (int)uVar2) {
        uVar3 = 0;
        goto LAB_00118c18;
      }
      puVar4 = &DAT_00111675;
    }
    uVar3 = (ulong)uVar2;
    _printk(puVar4);
  }
  else {
    _printk(&DAT_00110ec4,uVar3 & 0xffffffff);
    spidev_class = 0;
  }
LAB_00118c18:
  return uVar3 & 0xffffffff;
}



// ===========================================================
// Function: spidev_probe.cfi_jt at 0011810c
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong spidev_probe_cfi_jt(long param_1)

{
  undefined2 uVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  long lVar8;
  undefined8 uVar9;
  uint *puVar10;
  void *__s;
  void *__s_00;
  ulong uVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  ulong uVar14;
  
  _printk(&DAT_00110ae6,"2.1.0.230118_beta");
  if ((param_1 == 0) && (DAT_001105a8 != 0)) {
    _printk(&DAT_0011131e,"spidev_probe",0x926);
  }
  *(uint *)(param_1 + 0x3a8) = *(uint *)(param_1 + 0x3a8) | 1;
  oplus_spi_slave_ready_cb_register(param_1,slave_ready_cb_cfi_jt);
  puVar7 = (undefined4 *)kmem_cache_alloc_trace(_DAT_0011b288,0xdc0,0x3c0);
  spidev = puVar7;
  if (puVar7 != (undefined4 *)0x0) {
    *(long *)(puVar7 + 4) = param_1;
    *puVar7 = 0;
    __mutex_init(puVar7 + 0x1c,"&spidev->write_lock",&comm_master_upload_thread_packet_area);
    __mutex_init(spidev + 0x28,"&spidev->dual_comm_lock",&comm_master_upload_thread_packet_area);
    cpu_latency_qos_add_request(spidev + 6,0xffffffff);
    puVar7 = spidev + 0x12;
    *puVar7 = 8;
    of_property_read_variable_u32_array
              (*(undefined8 *)(param_1 + 0x2f0),"spi_bits_per_word",puVar7,1,0);
    puVar7 = spidev;
    if ((spidev[0x12] != 8) && (spidev[0x12] != 0x20)) {
      if (DAT_001105a8 != 0) {
        _printk(&DAT_00112337,"spidev_probe",0x93d);
      }
      puVar7 = spidev;
      spidev[0x12] = 8;
    }
    *(undefined8 *)(puVar7 + 0x3a) = 0;
    *(undefined4 **)(puVar7 + 0x3c) = puVar7 + 0x3c;
    *(undefined4 **)(puVar7 + 0x3e) = puVar7 + 0x3c;
    *(undefined8 *)(puVar7 + 0x40) = 0;
    *(undefined4 **)(puVar7 + 0x42) = puVar7 + 0x42;
    *(undefined4 **)(puVar7 + 0x44) = puVar7 + 0x42;
    *(undefined8 *)(puVar7 + 0x46) = 0;
    *(undefined4 **)(puVar7 + 0x48) = puVar7 + 0x48;
    *(undefined4 **)(puVar7 + 0x4a) = puVar7 + 0x48;
    lVar8 = kmalloc_order_trace(0x3ffc,0xdc0,2);
    *(long *)(spidev + 0x14) = lVar8;
    if (lVar8 != 0) {
      lVar8 = kmalloc_order_trace(0x3ffc,0xdc0,2);
      *(long *)(spidev + 0x16) = lVar8;
      if (lVar8 != 0) {
        lVar8 = kmalloc_order_trace(0x3ffc,0xdc0,2);
        *(long *)(spidev + 0x18) = lVar8;
        if (lVar8 != 0) {
          lVar8 = kmalloc_order_trace(0x3ffc,0xdc0,2);
          puVar7 = spidev;
          *(long *)(spidev + 0x1a) = lVar8;
          if (lVar8 != 0) {
            *(undefined4 **)(param_1 + 0x98) = puVar7;
            if (puVar7 + 0x52 == (undefined4 *)0x0) {
              if (DAT_001105a8 != 0) {
                _printk(&DAT_00111ac7,"wakeup_source_init",0x12d);
              }
            }
            else {
              *(undefined8 *)(puVar7 + 0x84) = 0;
              *(undefined8 *)(puVar7 + 0x82) = 0;
              *(undefined8 *)(puVar7 + 0x7e) = 0;
              *(undefined8 *)(puVar7 + 0x80) = 0;
              *(undefined8 *)(puVar7 + 0x7a) = 0;
              *(undefined8 *)(puVar7 + 0x7c) = 0;
              *(undefined8 *)(puVar7 + 0x76) = 0;
              *(undefined8 *)(puVar7 + 0x78) = 0;
              *(undefined8 *)(puVar7 + 0x72) = 0;
              *(undefined8 *)(puVar7 + 0x74) = 0;
              *(undefined8 *)(puVar7 + 0x6e) = 0;
              *(undefined8 *)(puVar7 + 0x70) = 0;
              *(undefined8 *)(puVar7 + 0x6a) = 0;
              *(undefined8 *)(puVar7 + 0x6c) = 0;
              *(undefined8 *)(puVar7 + 0x66) = 0;
              *(undefined8 *)(puVar7 + 0x68) = 0;
              *(undefined8 *)(puVar7 + 0x62) = 0;
              *(undefined8 *)(puVar7 + 100) = 0;
              *(undefined8 *)(puVar7 + 0x5e) = 0;
              *(undefined8 *)(puVar7 + 0x60) = 0;
              *(undefined8 *)(puVar7 + 0x5a) = 0;
              *(undefined8 *)(puVar7 + 0x5c) = 0;
              *(undefined8 *)(puVar7 + 0x56) = 0;
              *(undefined8 *)(puVar7 + 0x58) = 0;
              *(char **)(puVar7 + 0x52) = "upload_wakesrc";
              *(undefined8 *)(puVar7 + 0x54) = 0;
              wakeup_source_add(puVar7 + 0x52);
            }
            puVar5 = spidev;
            puVar7 = spidev + 0x86;
            if (puVar7 == (undefined4 *)0x0) {
              if (DAT_001105a8 != 0) {
                _printk(&DAT_00111ac7,"wakeup_source_init",0x12d);
              }
            }
            else {
              *(undefined8 *)(spidev + 0xb8) = 0;
              *(undefined8 *)(puVar5 + 0xb6) = 0;
              *(undefined8 *)(puVar5 + 0xb4) = 0;
              *(undefined8 *)(puVar5 + 0xb2) = 0;
              *(undefined8 *)(puVar5 + 0xb0) = 0;
              *(undefined8 *)(puVar5 + 0xae) = 0;
              *(undefined8 *)(puVar5 + 0xac) = 0;
              *(undefined8 *)(puVar5 + 0xaa) = 0;
              *(undefined8 *)(puVar5 + 0xa8) = 0;
              *(undefined8 *)(puVar5 + 0xa6) = 0;
              *(undefined8 *)(puVar5 + 0xa4) = 0;
              *(undefined8 *)(puVar5 + 0xa2) = 0;
              *(undefined8 *)(puVar5 + 0xa0) = 0;
              *(undefined8 *)(puVar5 + 0x9e) = 0;
              *(undefined8 *)(puVar5 + 0x9c) = 0;
              *(undefined8 *)(puVar5 + 0x9a) = 0;
              *(undefined8 *)(puVar5 + 0x98) = 0;
              *(undefined8 *)(puVar5 + 0x96) = 0;
              *(undefined8 *)(puVar5 + 0x94) = 0;
              *(undefined8 *)(puVar5 + 0x92) = 0;
              *(undefined8 *)(puVar5 + 0x90) = 0;
              *(undefined8 *)(puVar5 + 0x8e) = 0;
              *(undefined8 *)(puVar5 + 0x8c) = 0;
              *(undefined8 *)(puVar5 + 0x8a) = 0;
              *(undefined8 *)(puVar5 + 0x88) = 0;
              *(char **)(puVar5 + 0x86) = "download_wakesrc";
              wakeup_source_add(puVar7);
            }
            puVar5 = spidev;
            puVar7 = spidev + 0xba;
            if (puVar7 == (undefined4 *)0x0) {
              if (DAT_001105a8 != 0) {
                _printk(&DAT_00111ac7,"wakeup_source_init",0x12d);
              }
            }
            else {
              *(undefined8 *)(spidev + 0xec) = 0;
              *(undefined8 *)(puVar5 + 0xea) = 0;
              *(undefined8 *)(puVar5 + 0xe8) = 0;
              *(undefined8 *)(puVar5 + 0xe6) = 0;
              *(undefined8 *)(puVar5 + 0xe4) = 0;
              *(undefined8 *)(puVar5 + 0xe2) = 0;
              *(undefined8 *)(puVar5 + 0xe0) = 0;
              *(undefined8 *)(puVar5 + 0xde) = 0;
              *(undefined8 *)(puVar5 + 0xdc) = 0;
              *(undefined8 *)(puVar5 + 0xda) = 0;
              *(undefined8 *)(puVar5 + 0xd8) = 0;
              *(undefined8 *)(puVar5 + 0xd6) = 0;
              *(undefined8 *)(puVar5 + 0xd4) = 0;
              *(undefined8 *)(puVar5 + 0xd2) = 0;
              *(undefined8 *)(puVar5 + 0xd0) = 0;
              *(undefined8 *)(puVar5 + 0xce) = 0;
              *(undefined8 *)(puVar5 + 0xcc) = 0;
              *(undefined8 *)(puVar5 + 0xca) = 0;
              *(undefined8 *)(puVar5 + 200) = 0;
              *(undefined8 *)(puVar5 + 0xc6) = 0;
              *(undefined8 *)(puVar5 + 0xc4) = 0;
              *(undefined8 *)(puVar5 + 0xc2) = 0;
              *(undefined8 *)(puVar5 + 0xc0) = 0;
              *(undefined8 *)(puVar5 + 0xbe) = 0;
              *(undefined8 *)(puVar5 + 0xbc) = 0;
              *(char **)(puVar5 + 0xba) = "resever_wakesrc";
              wakeup_source_add(puVar7);
            }
            puVar7 = spidev;
            iVar6 = get_gpio_from_devtree
                              (*(undefined8 *)(*(long *)(spidev + 4) + 0x2f0),"s2m_int_gpio");
            puVar7[0x34] = iVar6;
            if (iVar6 < 0) {
LAB_0011428c:
              if (DAT_001105a8 != 0) {
                _printk(&DAT_00110d0f,"spidev_probe",0x962);
              }
            }
            else {
              gpio_to_desc();
              gpiod_direction_input();
              uVar9 = spidev_gpio_request_irq
                                (*(undefined8 *)(puVar7 + 4),puVar7[0x34],4,s2m_int_irq_fn_cfi_jt);
              puVar7[0x38] = (int)uVar9;
              if (((int)uVar9 < 0) || (iVar6 = irq_set_irq_wake(uVar9,1), iVar6 != 0))
              goto LAB_0011428c;
              if (DAT_001105c8 != 0) {
                _printk(&DAT_00111065,"spidev_gpio_init",0x8fe,puVar7[0x34],puVar7[0x38]);
              }
              iVar6 = get_gpio_from_devtree
                                (*(undefined8 *)(*(long *)(puVar7 + 4) + 0x2f0),"m2s_ans_gpio");
              puVar7[0x37] = iVar6;
              if (iVar6 < 0) goto LAB_0011428c;
              uVar9 = gpio_to_desc();
              gpiod_direction_output_raw(uVar9,0);
              if (DAT_001105c8 != 0) {
                _printk(&DAT_00111cd3,"spidev_gpio_init",0x904,puVar7[0x37]);
              }
              iVar6 = get_gpio_from_devtree
                                (*(undefined8 *)(*(long *)(puVar7 + 4) + 0x2f0),"m2s_int_gpio");
              puVar7[0x36] = iVar6;
              if (iVar6 < 0) goto LAB_0011428c;
              uVar9 = gpio_to_desc();
              gpiod_direction_output_raw(uVar9,0);
              if (DAT_001105c8 != 0) {
                _printk(&DAT_0011177b,"spidev_gpio_init",0x90a,puVar7[0x36]);
              }
              iVar6 = get_gpio_from_devtree
                                (*(undefined8 *)(*(long *)(puVar7 + 4) + 0x2f0),"s2m_ans_gpio");
              puVar7[0x35] = iVar6;
              if (iVar6 < 0) goto LAB_0011428c;
              gpio_to_desc();
              gpiod_direction_input();
              iVar6 = spidev_gpio_request_irq
                                (*(undefined8 *)(puVar7 + 4),puVar7[0x35],1,s2m_ans_irq_fn_cfi_jt);
              puVar7[0x39] = iVar6;
              if (iVar6 < 0) goto LAB_0011428c;
              if (DAT_001105c8 != 0) {
                _printk(&DAT_00111afb,"spidev_gpio_init",0x915,puVar7[0x35],iVar6);
              }
            }
            lVar8 = 0;
            do {
              puVar7 = spidev;
              uVar9 = *(undefined8 *)(spidev + 4);
              puVar10 = (uint *)kmem_cache_alloc_trace(_DAT_0011b288,0xdc0,0x270);
              if (puVar10 != (uint *)0x0) {
                __s = (void *)kmalloc_order_trace(0x3ff4,0xdc0,2);
                *(void **)(puVar10 + 0x52) = __s;
                if (__s != (void *)0x0) {
                  memset(__s,0,0x3ff4);
                  __s_00 = (void *)kmalloc_order_trace(0x3ff4,0xdc0,2);
                  *(void **)(puVar10 + 0x54) = __s_00;
                  if (__s_00 != (void *)0x0) {
                    memset(__s_00,0,0x3ff4);
                    uVar1 = *(undefined2 *)((long)&DAT_001104d0 + lVar8);
                    *(undefined4 **)(puVar10 + 2) = puVar7;
                    uVar13 = *(undefined8 *)((long)&g_cdev_info_list + lVar8);
                    *(undefined2 *)(puVar10 + 7) = uVar1;
                    *(undefined8 *)(puVar10 + 8) = uVar13;
                    __mutex_init(puVar10 + 0x3a,"&data_cdev->read_lock",
                                 &comm_master_upload_thread_packet_area);
                    __mutex_init(puVar10 + 0x46,"&data_cdev->write_lock",
                                 &comm_master_upload_thread_packet_area);
                    uVar12 = 0x40000;
                    if (*(short *)((long)&DAT_001104d0 + lVar8) != 1) {
                      uVar12 = 0x4000;
                    }
                    puVar10[0x34] = 0;
                    puVar10[0x35] = 0;
                    *(uint **)(puVar10 + 0x36) = puVar10 + 0x36;
                    *(uint **)(puVar10 + 0x38) = puVar10 + 0x36;
                    __mutex_init(puVar10 + 0x28,"&fifo->lock",&comm_master_upload_thread_packet_area
                                );
                    iVar6 = __kfifo_alloc(puVar10 + 0x22,uVar12,1,0xcc0);
                    if (iVar6 == 0) {
                      puVar10[0x1c] = 0;
                      puVar10[0x1d] = 0;
                      *(uint **)(puVar10 + 0x1e) = puVar10 + 0x1e;
                      *(uint **)(puVar10 + 0x20) = puVar10 + 0x1e;
                      __mutex_init(puVar10 + 0x10,"&fifo->lock",
                                   &comm_master_upload_thread_packet_area);
                      iVar6 = __kfifo_alloc(puVar10 + 10,uVar12,1,0xcc0);
                      if (iVar6 == 0) {
                        if ((*(ushort *)((long)&DAT_001104d0 + lVar8) & 0xfffe) != 0xe) {
                          uVar14 = ~(minors | 0xffffffff00000000);
                          uVar14 = (uVar14 & 0xaaaaaaaaaaaaaaaa) >> 1 |
                                   (uVar14 & 0x5555555555555555) << 1;
                          uVar14 = (uVar14 & 0xcccccccccccccccc) >> 2 |
                                   (uVar14 & 0x3333333333333333) << 2;
                          uVar14 = (uVar14 & 0xf0f0f0f0f0f0f0f0) >> 4 |
                                   (uVar14 & 0xf0f0f0f0f0f0f0f) << 4;
                          uVar14 = (uVar14 & 0xff00ff00ff00ff00) >> 8 |
                                   (uVar14 & 0xff00ff00ff00ff) << 8;
                          uVar11 = (uVar14 & 0xffff0000ffff0000) >> 0x10 |
                                   (uVar14 & 0xffff0000ffff) << 0x10;
                          uVar14 = 0x20;
                          if ((minors | 0xffffffff00000000) != 0xffffffffffffffff) {
                            uVar14 = LZCOUNT(uVar11 >> 0x20 | uVar11 << 0x20);
                          }
                          if (uVar14 < 0x20) {
                            uVar2 = (uint)uVar14 | 0x9900000;
                            uVar13 = *(undefined8 *)((long)&g_cdev_info_list + lVar8);
                            *puVar10 = uVar2;
                            uVar11 = device_create(spidev_class,uVar9,uVar2,puVar10,uVar13);
                            *(ulong *)(puVar10 + 4) = uVar11;
                            if ((uVar11 < 0xfffffffffffff001) || ((uVar11 & 0xffffffff) == 0)) {
                              Hint_Prefetch(0x100280,2,0,1);
                              do {
                                cVar3 = '\x01';
                                bVar4 = (bool)ExclusiveMonitorPass(0x100280,0x10);
                                if (bVar4) {
                                  cVar3 = ExclusiveMonitorsStatus();
                                  minors = minors | 1L << (uVar14 & 0x3f);
                                }
                              } while (cVar3 != '\0');
                            }
                          }
                          else {
                            puVar10[4] = 0;
                            puVar10[5] = 0;
                          }
                        }
                        snprintf((char *)(puVar10 + 0x8a),0x20,"ws_%s",
                                 *(undefined8 *)((long)&g_cdev_info_list + lVar8));
                        puVar10[0x5a] = 0;
                        puVar10[0x5b] = 0;
                        puVar10[0x5c] = 0;
                        puVar10[0x5d] = 0;
                        puVar10[0x5e] = 0;
                        puVar10[0x5f] = 0;
                        puVar10[0x60] = 0;
                        puVar10[0x61] = 0;
                        puVar10[0x62] = 0;
                        puVar10[99] = 0;
                        puVar10[100] = 0;
                        puVar10[0x65] = 0;
                        puVar10[0x66] = 0;
                        puVar10[0x67] = 0;
                        puVar10[0x68] = 0;
                        puVar10[0x69] = 0;
                        puVar10[0x6a] = 0;
                        puVar10[0x6b] = 0;
                        puVar10[0x6c] = 0;
                        puVar10[0x6d] = 0;
                        puVar10[0x6e] = 0;
                        puVar10[0x6f] = 0;
                        puVar10[0x70] = 0;
                        puVar10[0x71] = 0;
                        puVar10[0x72] = 0;
                        puVar10[0x73] = 0;
                        puVar10[0x74] = 0;
                        puVar10[0x75] = 0;
                        puVar10[0x76] = 0;
                        puVar10[0x77] = 0;
                        puVar10[0x78] = 0;
                        puVar10[0x79] = 0;
                        puVar10[0x7a] = 0;
                        puVar10[0x7b] = 0;
                        puVar10[0x7c] = 0;
                        puVar10[0x7d] = 0;
                        puVar10[0x7e] = 0;
                        puVar10[0x7f] = 0;
                        puVar10[0x80] = 0;
                        puVar10[0x81] = 0;
                        puVar10[0x82] = 0;
                        puVar10[0x83] = 0;
                        puVar10[0x84] = 0;
                        puVar10[0x85] = 0;
                        puVar10[0x86] = 0;
                        puVar10[0x87] = 0;
                        puVar10[0x88] = 0;
                        puVar10[0x89] = 0;
                        *(uint **)(puVar10 + 0x56) = puVar10 + 0x8a;
                        puVar10[0x58] = 0;
                        puVar10[0x59] = 0;
                        wakeup_source_add(puVar10 + 0x56);
                        *(uint **)((long)&DAT_001104d8 + lVar8) = puVar10;
                      }
                      else {
                        _printk(&DAT_0011222d,uVar12,iVar6);
                      }
                    }
                    else {
                      _printk(&DAT_0011222d,uVar12,iVar6);
                    }
                    goto LAB_001142bc;
                  }
                  kfree(__s);
                }
                kfree(puVar10);
              }
LAB_001142bc:
              lVar8 = lVar8 + 0x18;
            } while (lVar8 != 0xd8);
            uVar14 = kthread_create_on_node
                               (comm_master_upload_thread_cfi_jt,spidev,0xffffffff,"snshub_up_thd");
            puVar7 = spidev;
            *(ulong *)(spidev + 0x4c) = uVar14;
            if (uVar14 < 0xfffffffffffff001) {
              puVar10 = (uint *)(uVar14 + 0x38);
              Hint_Prefetch(puVar10,2,0,1);
              do {
                uVar2 = *puVar10;
                cVar3 = '\x01';
                bVar4 = (bool)ExclusiveMonitorPass(puVar10,0x10);
                if (bVar4) {
                  *puVar10 = uVar2 + 1;
                  cVar3 = ExclusiveMonitorsStatus();
                }
              } while (cVar3 != '\0');
              if (uVar2 == 0) {
                uVar9 = 2;
LAB_001148a4:
                refcount_warn_saturate(puVar10,uVar9);
              }
              else if ((int)(uVar2 + 1 | uVar2) < 0) {
                uVar9 = 1;
                goto LAB_001148a4;
              }
              wake_up_process(*(undefined8 *)(spidev + 0x4c));
              uVar14 = 0;
              puVar7 = spidev;
            }
            else if (DAT_001105a8 != 0) {
              _printk(&DAT_00110c76,"spidev_probe",0x96a);
              uVar14 = *(ulong *)(spidev + 0x4c);
              puVar7 = spidev;
            }
            uVar11 = kthread_create_on_node
                               (comm_master_download_thread_cfi_jt,puVar7,0xffffffff,
                                "snshub_down_thd");
            *(ulong *)(spidev + 0x4e) = uVar11;
            if (0xfffffffffffff000 < uVar11) {
              if (DAT_001105a8 != 0) {
                _printk(&DAT_0011121a,"spidev_probe",0x974);
                uVar11 = *(ulong *)(spidev + 0x4e);
              }
              uVar14 = uVar11 & 0xffffffff;
              goto LAB_001140d4;
            }
            puVar10 = (uint *)(uVar11 + 0x38);
            Hint_Prefetch(puVar10,2,0,1);
            do {
              uVar2 = *puVar10;
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(puVar10,0x10);
              if (bVar4) {
                *puVar10 = uVar2 + 1;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
            if (uVar2 == 0) {
              uVar9 = 2;
LAB_001148cc:
              refcount_warn_saturate(puVar10,uVar9);
            }
            else if ((int)(uVar2 + 1 | uVar2) < 0) {
              uVar9 = 1;
              goto LAB_001148cc;
            }
            wake_up_process(*(undefined8 *)(spidev + 0x4e));
            goto LAB_001140d4;
          }
        }
      }
    }
  }
  uVar14 = 0xfffffff4;
LAB_001140d4:
  return uVar14 & 0xffffffff;
}



// ===========================================================
// Function: spidev_remove.cfi_jt at 00118110
// ===========================================================

undefined8 spidev_remove_cfi_jt(void)

{
  return 0;
}



// ===========================================================
// Function: snshub_suspend.cfi_jt at 00118114
// ===========================================================

undefined8 snshub_suspend_cfi_jt(long param_1)

{
  *(undefined4 *)(*(long *)(param_1 + 0x98) + 0x140) = 1;
  return 0;
}



// ===========================================================
// Function: snshub_resume.cfi_jt at 00118118
// ===========================================================

undefined8 snshub_resume_cfi_jt(long param_1)

{
  *(undefined4 *)(*(long *)(param_1 + 0x98) + 0x140) = 0;
  return 0;
}



// ===========================================================
// Function: slave_ready_cb.cfi_jt at 0011811c
// ===========================================================

void slave_ready_cb_cfi_jt(undefined8 param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_2 == 0 && param_3 == 0) {
    if (DAT_001105a8 != 0) {
      _printk(&DAT_00111c2c,"slave_ready_cb",0x15e);
    }
  }
  else {
    if (param_2 != 0) {
      uVar1 = gpio_to_desc(*(undefined4 *)(spidev + 0xd8));
      gpiod_direction_output_raw(uVar1,1);
    }
    if (param_3 != 0) {
      uVar1 = gpio_to_desc(*(undefined4 *)(spidev + 0xdc));
      gpiod_direction_output_raw(uVar1,1);
    }
  }
  return;
}



// ===========================================================
// Function: s2m_int_irq_fn.cfi_jt at 00118120
// ===========================================================

undefined8 s2m_int_irq_fn_cfi_jt(int param_1,long param_2)

{
  long lVar1;
  
  disable_irq_nosync();
  lVar1 = spidev;
  if (((param_2 != 0) && (spidev != 0)) && (*(int *)(spidev + 0xe0) == param_1)) {
    if (*(int *)(spidev + 0x140) != 0) {
      *(undefined1 *)(spidev + 0x3bc) = 1;
    }
    pm_wakeup_ws_event(lVar1 + 0x148,1000,0);
    up(spidev + 0xe8);
  }
  return 1;
}



// ===========================================================
// Function: s2m_ans_irq_fn.cfi_jt at 00118124
// ===========================================================

undefined8 s2m_ans_irq_fn_cfi_jt(int param_1,long param_2)

{
  if (((param_2 != 0) && (spidev != 0)) && (*(int *)(spidev + 0xe4) == param_1)) {
    up(spidev + 0x100);
  }
  return 1;
}



// ===========================================================
// Function: no_llseek.cfi_jt at 00118128
// ===========================================================

void no_llseek_cfi_jt(void)

{
  no_llseek();
  return;
}



// ===========================================================
// Function: spidev_read.cfi_jt at 0011812c
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long spidev_read_cfi_jt(long param_1,ulong param_2,ulong param_3)

{
  ushort *puVar1;
  ulong uVar2;
  int iVar3;
  ushort uVar4;
  undefined8 *puVar5;
  ulong uVar6;
  bool bVar7;
  int iVar8;
  ulong uVar9;
  ulong uVar10;
  void *__s;
  long lVar11;
  
  lVar11 = *(long *)(param_1 + 0xd8);
  __s = *(void **)(lVar11 + 0x150);
  mutex_lock(lVar11 + 0xe8);
  memset(__s,0,0x3ff4);
  iVar8 = rfifo_out(lVar11,*(uint *)(param_1 + 0x40) >> 0xb & 1);
  if (iVar8 < 1) {
    if (DAT_001105d8 != 0) {
      _printk(&DAT_001108fa,"spidev_read",0x669,*(undefined8 *)(lVar11 + 0x20),iVar8,
              *(undefined2 *)((long)__s + 2));
    }
  }
  else {
    uVar9 = (ulong)*(ushort *)((long)__s + 2);
    if (param_3 < uVar9) {
      if (DAT_001105a8 != 0) {
        _printk(&DAT_00111e69,"spidev_read",0x65b,0);
      }
      uVar9 = param_3 & 0xffffffff;
    }
    iVar8 = (int)uVar9;
    puVar1 = (ushort *)((long)__s + 4);
    __check_object_size(puVar1,uVar9,1);
    puVar5 = (undefined8 *)sp_el0;
    uVar6 = (long)(param_2 << 8) >> 8;
    if (((*(byte *)((long)puVar5 + 0x3e) >> 5 & 1) != 0) ||
       (uVar10 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
      uVar10 = param_2 & uVar6;
    }
    bVar7 = CARRY8(uVar10,uVar9);
    uVar10 = uVar10 + uVar9;
    uVar2 = 0;
    if (!bVar7 || uVar10 == 0) {
      uVar2 = 0x7fffffffff;
    }
    if (bVar7) {
      uVar10 = 0xffffffffffffffff;
    }
    if (!CARRY8(uVar10,~uVar2) && !CARRY8(uVar10 + ~uVar2,(ulong)bVar7) || uVar10 == uVar2 + !bVar7)
    {
      if (((uint)_cpu_hwcaps >> 0x1b & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr1_el1 = puVar5[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar5[1];
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
      if ((param_2 & uVar6 & 0xffffff8000000000) != 0) {
        param_2 = 0;
      }
      uVar9 = __arch_copy_to_user(param_2,puVar1,uVar9);
      if (((uint)_cpu_hwcaps >> 0x1b & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar10 = daif;
          daif = uVar10 | 0xc0;
        }
        uVar10 = ttbr1_el1;
        ttbr0_el1 = (uVar10 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar10 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
    }
    if (uVar9 == 0) {
      if (DAT_001105e8 != 0) {
        uVar4 = *puVar1;
        if ((*(short *)(lVar11 + 0x1c) == 7) || (*(short *)(lVar11 + 0x1c) == 1)) {
          if (uVar4 < 0x400) {
            _printk(&DAT_0011104b,&DAT_0011202c,(ulong)uVar4,*(undefined2 *)((long)__s + 6));
          }
          else {
            uVar9 = (ulong)uVar4 & 0xff;
            if ((uVar4 >> 8 == 0x18) && ((int)uVar9 - 1U < 2)) {
              iVar3 = *(int *)(&test_msgid + uVar9 * 4);
              *(int *)(&test_msgid + uVar9 * 4) = iVar3 + 1;
              if (99 < iVar3 + 1) {
                _printk(&DAT_001111ed,&DAT_0011202c,uVar9,0x18,*(undefined2 *)((long)__s + 6));
                *(undefined4 *)(&test_msgid + uVar9 * 4) = 0;
              }
            }
            else {
              _printk(&DAT_00112209,&DAT_0011202c,uVar9,uVar4 >> 8,*(undefined2 *)((long)__s + 6));
            }
          }
        }
      }
      *(int *)(lVar11 + 0x254) = *(int *)(lVar11 + 0x254) + 1;
    }
    else {
      if (DAT_001105a8 != 0) {
        _printk(&DAT_00110e7e,"spidev_read",0x664);
      }
      iVar8 = -0xe;
    }
    if (DAT_00110638 != 0) {
      _printk(&DAT_00110890,PTR_s_data_to_user_00110630,*(undefined2 *)((long)__s + 2),
              *(undefined8 *)(lVar11 + 0x20));
      print_hex_dump(&DAT_00110c3f,&DAT_00111a43,2,0x10,1,puVar1,*(undefined2 *)((long)__s + 2),1);
    }
  }
  mutex_unlock(lVar11 + 0xe8);
  return (long)iVar8;
}



// ===========================================================
// Function: spidev_write.cfi_jt at 00118130
// ===========================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 spidev_write_cfi_jt(long param_1,ulong param_2,ulong param_3)

{
  undefined2 *puVar1;
  ulong uVar2;
  undefined2 uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  bool bVar6;
  short sVar7;
  undefined2 uVar8;
  ulong __n;
  ulong uVar9;
  undefined8 uVar10;
  long lVar11;
  undefined2 *__s;
  
  if (param_3 < 0x3ff1) {
    lVar11 = *(long *)(param_1 + 0xd8);
    __s = *(undefined2 **)(lVar11 + 0x148);
    sVar7 = is_sau_filter(*(undefined2 *)(lVar11 + 0x1c));
    if (sVar7 == 0) {
      mutex_lock(lVar11 + 0x118);
      memset(__s,0,0x3ff4);
      puVar1 = __s + 2;
      uVar3 = *(undefined2 *)(lVar11 + 0x1c);
      __s[1] = (short)param_3;
      *__s = uVar3;
      __check_object_size(puVar1,param_3,0);
      puVar4 = (undefined8 *)sp_el0;
      uVar5 = (long)(param_2 << 8) >> 8;
      if (((*(byte *)((long)puVar4 + 0x3e) >> 5 & 1) != 0) ||
         (uVar9 = param_2, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
        uVar9 = param_2 & uVar5;
      }
      bVar6 = CARRY8(uVar9,param_3);
      uVar9 = uVar9 + param_3;
      uVar2 = 0;
      if (!bVar6 || uVar9 == 0) {
        uVar2 = 0x7fffffffff;
      }
      if (bVar6) {
        uVar9 = 0xffffffffffffffff;
      }
      __n = param_3;
      if (!CARRY8(uVar9,~uVar2) && !CARRY8(uVar9 + ~uVar2,(ulong)bVar6) || uVar9 == uVar2 + !bVar6)
      {
        if (((uint)_cpu_hwcaps >> 0x1b & 1) == 0) {
          uVar9 = daif;
          if ((uVar9 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr1_el1 = puVar4[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar4[1];
          InstructionSynchronizationBarrier();
          daif = uVar9;
        }
        if ((param_2 & uVar5 & 0xffffff8000000000) != 0) {
          param_2 = 0;
        }
        __n = __arch_copy_from_user(puVar1,param_2,param_3);
        if (((uint)_cpu_hwcaps >> 0x1b & 1) == 0) {
          uVar5 = daif;
          if ((uVar5 & 0x80) == 0) {
            uVar9 = daif;
            daif = uVar9 | 0xc0;
          }
          uVar9 = ttbr1_el1;
          ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar9 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar5;
        }
      }
      if (__n != 0) {
        memset((void *)((long)puVar1 + (param_3 - __n)),0,__n);
      }
      if (DAT_00110648 != 0) {
        _printk(&DAT_00110890,PTR_s_data_from_user_00110640,param_3,*(undefined8 *)(lVar11 + 0x20));
        print_hex_dump(&DAT_00110c3f,&DAT_00111a43,2,0x10,1,puVar1,param_3,1);
      }
      if ((__n != 0) && (DAT_001105a8 != 0)) {
        _printk(&DAT_001109af,"spidev_write",0x695);
      }
      uVar10 = wfifo_in(lVar11,*(uint *)(param_1 + 0x40) >> 0xb & 1);
      mutex_unlock(lVar11 + 0x118);
    }
    else {
      if (DAT_001105a8 != 0) {
        uVar3 = *(undefined2 *)(lVar11 + 0x1c);
        uVar8 = get_sau_ch_id();
        _printk(&DAT_00110bd0,"spidev_write",0x687,uVar3,param_3,uVar8);
      }
      msleep(10);
      uVar10 = 0xfffffffffffffff0;
    }
  }
  else if (DAT_001105a8 == 0) {
    uVar10 = 0xffffffffffffffea;
  }
  else {
    _printk(&DAT_00111bdd,"spidev_write",0x680,param_3);
    uVar10 = 0xffffffffffffffea;
  }
  return uVar10;
}



// ===========================================================
// Function: spidev_open.cfi_jt at 00118134
// ===========================================================

undefined8 spidev_open_cfi_jt(long param_1,long param_2)

{
  undefined8 uVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar2 = *(uint *)(param_1 + 0x4c);
  puVar3 = DAT_001104d8;
  if ((((((*DAT_001104d8 == uVar2) || (puVar3 = DAT_001104f0, *DAT_001104f0 == uVar2)) ||
        (puVar3 = DAT_00110508, *DAT_00110508 == uVar2)) ||
       ((puVar3 = DAT_00110520, *DAT_00110520 == uVar2 ||
        (puVar3 = DAT_00110538, *DAT_00110538 == uVar2)))) ||
      ((puVar3 = DAT_00110550, *DAT_00110550 == uVar2 ||
       ((puVar3 = DAT_00110568, *DAT_00110568 == uVar2 ||
        (puVar3 = DAT_00110580, *DAT_00110580 == uVar2)))))) ||
     (puVar3 = DAT_00110598, *DAT_00110598 == uVar2)) {
    uVar2 = puVar3[6];
    if (uVar2 == 0) {
      if ((short)puVar3[7] == 9) {
        set_sau_ch_id(9);
        uVar2 = puVar3[6];
      }
      else {
        uVar2 = 0;
      }
    }
    puVar3[6] = uVar2 + 1;
    *(uint **)(param_2 + 0xd8) = puVar3;
    nonseekable_open(param_1,param_2);
    uVar1 = 0;
  }
  else if (DAT_001105a8 == 0) {
    uVar1 = 0xfffffffa;
  }
  else {
    _printk(&DAT_00110ab9,"spidev_open",0x6af,uVar2 & 0xfffff);
    uVar1 = 0xfffffffa;
  }
  return uVar1;
}



// ===========================================================
// Function: spidev_release.cfi_jt at 00118138
// ===========================================================

undefined8 spidev_release_cfi_jt(undefined8 param_1,long param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_2 + 0xd8);
  if (*(int *)(lVar3 + 0x88) != *(int *)(lVar3 + 0x8c)) {
    iVar2 = -0x13;
    do {
      msleep(5);
      if (*(int *)(lVar3 + 0x88) == *(int *)(lVar3 + 0x8c)) break;
      bVar1 = iVar2 != 0;
      iVar2 = iVar2 + 1;
    } while (bVar1);
  }
  iVar2 = *(int *)(lVar3 + 0x18);
  if (iVar2 == 1) {
    if (*(short *)(lVar3 + 0x1c) != 9) {
      *(undefined4 *)(lVar3 + 0x18) = 0;
      goto LAB_00117448;
    }
    set_sau_ch_id(0);
    iVar2 = *(int *)(lVar3 + 0x18);
  }
  if ((iVar2 != 0) && (*(int *)(lVar3 + 0x18) = iVar2 + -1, iVar2 + -1 != 0)) {
    return 0;
  }
LAB_00117448:
  up(lVar3 + 0x70);
  mutex_lock(lVar3 + 0x40);
  *(undefined8 *)(lVar3 + 0x28) = 0;
  mutex_unlock(lVar3 + 0x40);
  mutex_lock(lVar3 + 0xa0);
  *(undefined8 *)(lVar3 + 0x88) = 0;
  mutex_unlock(lVar3 + 0xa0);
  return 0;
}



// ===========================================================
// Function: log_show.cfi_jt at 0011813c
// ===========================================================

long log_show_cfi_jt(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined *puVar2;
  ulong uVar3;
  long lVar4;
  undefined **ppuVar5;
  
  uVar3 = 0;
  lVar4 = 0;
  ppuVar5 = &log_array;
  do {
    puVar2 = *ppuVar5;
    if (puVar2 != (undefined *)0x0) {
      if (((uint)uVar3 & 0xff) * -0x55555555 < 0x55555556) {
        iVar1 = snprintf((char *)(param_3 + lVar4),0x1000 - lVar4,"\n");
        puVar2 = *ppuVar5;
        lVar4 = lVar4 + iVar1;
      }
      iVar1 = snprintf((char *)(param_3 + lVar4),0x1000 - lVar4,"bit %d, sw %d [%s]\n",
                       uVar3 & 0xffffffff,(ulong)*(uint *)(ppuVar5 + 1),puVar2);
      lVar4 = lVar4 + iVar1;
    }
    uVar3 = uVar3 + 1;
    ppuVar5 = ppuVar5 + 2;
  } while (uVar3 != 0x20);
  iVar1 = snprintf((char *)(param_3 + lVar4),0x1000 - lVar4,
                   "\ninput OCT value to change log level\n");
  return lVar4 + iVar1;
}



// ===========================================================
// Function: info_show.cfi_jt at 00118140
// ===========================================================

long info_show_cfi_jt(undefined8 param_1,undefined8 param_2,char *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  
  uVar3 = *(uint *)(spidev + 0xd8);
  gpio_to_desc(uVar3);
  uVar10 = gpiod_get_raw_value();
  uVar4 = *(uint *)(spidev + 0xd4);
  gpio_to_desc(uVar4);
  uVar11 = gpiod_get_raw_value();
  uVar5 = *(undefined4 *)(spidev + 0xd0);
  uVar6 = *(uint *)(spidev + 0xe4);
  gpio_to_desc(uVar5);
  uVar7 = gpiod_get_raw_value();
  uVar1 = *(undefined4 *)(spidev + 0xdc);
  uVar2 = *(undefined4 *)(spidev + 0xe0);
  gpio_to_desc(uVar1);
  uVar8 = gpiod_get_raw_value();
  iVar9 = snprintf(param_3,0x1000,
                   "--gpio info:\n m2s_int: gpio(%d) value(%d) output\n s2m_ans: gpio(%d) value(%d) irq(%d)\n s2m_int: gpio(%d) value(%d) irq(%d)\n m2s_ans: gpio(%d) value(%d) output\n\n"
                   ,(ulong)uVar3,uVar10 & 0xffffffff,(ulong)uVar4,uVar11 & 0xffffffff,(ulong)uVar6,
                   uVar5,uVar7,uVar2,uVar1,uVar8);
  lVar13 = (long)iVar9;
  iVar9 = snprintf(param_3 + lVar13,0x1000 - lVar13,
                   "--download datalink(write) info:\n s2m_ans_pu_timeout: %d\n s2m_ans_pu_con_timeout: %d\n dn_write_seq_fail: %d\n s2m_ans_pd_timeout: %d\n dn_frame_suc: %d\n dn_frame_check_err: %d\n\n"
                   ,(ulong)(uint)dci,(ulong)dci._4_4_,(ulong)(uint)DAT_00100298,
                   (ulong)DAT_00100298._4_4_,(ulong)DAT_001002a0._4_4_,(undefined4)DAT_001002a8);
  lVar13 = lVar13 + iVar9;
  iVar9 = snprintf(param_3 + lVar13,0x1000 - lVar13,
                   "--upload datalink(read) info:\n up_frame_discontinuous: %d\n up_frame_check_err: %d\n up_frame_suc: %d\n up_disturb_signal: %d\n up_read_seq_fail: %d\n s2m_int_down_trylock: %d\n\n"
                   ,(ulong)DAT_001002a8._4_4_,(ulong)(uint)DAT_001002b0,(ulong)DAT_001002b0._4_4_,
                   (ulong)(uint)DAT_001002b8,(ulong)DAT_001002b8._4_4_,DAT_001002c0);
  lVar14 = 0x10;
  lVar13 = lVar13 + iVar9;
  do {
    lVar12 = *(long *)((long)&g_cdev_info_list + lVar14);
    iVar9 = snprintf(param_3 + lVar13,0x1000 - lVar13,
                     "--channel %s info:\n rx_fifo_full: %d\n rx_packet_to_fifo: %d\n rx_packet_to_user: %d\n tx_fifo_full: %d\n tx_packet_to_fifo: %d\n tx_packet_to_mcu: %d\n tx_packet_send_suc: %d\n tx_packet_send_fail: %d\n\n"
                     ,*(undefined8 *)(lVar12 + 0x20),(ulong)*(uint *)(lVar12 + 0x24c),
                     (ulong)*(uint *)(lVar12 + 0x250),(ulong)*(uint *)(lVar12 + 0x254),
                     (ulong)*(uint *)(lVar12 + 600),*(undefined4 *)(lVar12 + 0x25c),
                     *(undefined4 *)(lVar12 + 0x260),*(undefined4 *)(lVar12 + 0x264),
                     *(undefined4 *)(lVar12 + 0x268),uVar8);
    lVar14 = lVar14 + 0x18;
    lVar13 = lVar13 + iVar9;
  } while (lVar14 != 0xe8);
  return lVar13;
}



// ===========================================================
// Function: commstop_show.cfi_jt at 00118144
// ===========================================================

long commstop_show_cfi_jt(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"master comm state(%d)\n",(ulong)close_comm_state);
  return (long)iVar1;
}



// ===========================================================
// Function: auto_reset_mcu_show.cfi_jt at 00118148
// ===========================================================

long auto_reset_mcu_show_cfi_jt(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%d",(ulong)*(uint *)(spidev + 0x3b8));
  return (long)iVar1;
}



// ===========================================================
// Function: speedtest_show.cfi_jt at 0011814c
// ===========================================================

void speedtest_show_cfi_jt(undefined8 param_1,undefined8 param_2,char *param_3)

{
  uint *puVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  undefined8 uVar9;
  ulong uStack_40;
  ulong uStack_38;
  char *pcStack_30;
  long lStack_28;
  
  lVar4 = sp_el0;
  lStack_28 = *(long *)(lVar4 + 0x648);
  uStack_40 = 0;
  uStack_38 = 0;
  pcStack_30 = param_3;
  sVar5 = get_sau_ch_id();
  if (sVar5 != 0) {
    uVar6 = get_sau_ch_id();
    iVar7 = snprintf(param_3,0x1000,"ch(%d) stand alone used, not support speedtest\n",
                     (ulong)(uVar6 & 0xffff));
    uVar8 = (ulong)iVar7;
    goto LAB_00117d00;
  }
  speed_test_complt = 0;
  uStack_40 = kthread_create_on_node(speedtest_thread_cfi_jt,&uStack_40,0xffffffff,"speed_test_thd")
  ;
  if (0xfffffffffffff000 < uStack_40) {
    uVar8 = uStack_40;
    if (DAT_001105a8 != 0) {
      _printk(&DAT_001119ae,"speedtest_show",0x7e4);
      uVar8 = uStack_40;
    }
    goto LAB_00117d00;
  }
  puVar1 = (uint *)(uStack_40 + 0x38);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar6 = *puVar1;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = uVar6 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  if (uVar6 == 0) {
    uVar9 = 2;
LAB_00117d74:
    refcount_warn_saturate(puVar1,uVar9);
  }
  else if ((int)(uVar6 + 1 | uVar6) < 0) {
    uVar9 = 1;
    goto LAB_00117d74;
  }
  wake_up_process(uStack_40);
  if ((speed_test_complt & 1) == 0) {
    do {
      msleep(1000);
    } while (speed_test_complt != 1);
  }
  kthread_stop(uStack_40);
  uVar8 = uStack_38;
LAB_00117d00:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x648) == lStack_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar8);
}



// ===========================================================
// Function: log_store.cfi_jt at 00118150
// ===========================================================

undefined8 log_store_cfi_jt(undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  uint *puVar4;
  long lStack_30;
  long lStack_28;
  
  lVar3 = sp_el0;
  lStack_28 = *(long *)(lVar3 + 0x648);
  lStack_30 = 0;
  uVar1 = simple_strtol(param_3,&lStack_30,0);
  if (lStack_30 == param_3) {
    param_4 = 0xffffffffffffffea;
  }
  else {
    lVar3 = 0;
    puVar4 = &DAT_001105a8;
    do {
      uVar2 = (uint)lVar3;
      lVar3 = lVar3 + 1;
      *puVar4 = uVar1 >> (ulong)(uVar2 & 0x1f) & 1;
      puVar4 = puVar4 + 4;
    } while (lVar3 != 0x20);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x648) != lStack_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



// ===========================================================
// Function: info_store.cfi_jt at 00118154
// ===========================================================

undefined8 info_store_cfi_jt(undefined8 param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  iVar4 = strncmp(param_3,"clean",5);
  lVar2 = DAT_001104f0;
  lVar1 = DAT_001104d8;
  if (iVar4 == 0) {
    DAT_001002c0 = 0;
    DAT_001002b0 = 0;
    DAT_001002b8 = 0;
    DAT_001002a0 = 0;
    DAT_001002a8 = 0;
    dci = 0;
    DAT_00100298 = 0;
    *(undefined8 *)(DAT_001104d8 + 0x248) = 0;
    *(undefined8 *)(lVar1 + 0x250) = 0;
    *(undefined8 *)(lVar1 + 600) = 0;
    *(undefined8 *)(lVar1 + 0x260) = 0;
    *(undefined4 *)(lVar1 + 0x268) = 0;
    lVar1 = DAT_00110508;
    *(undefined8 *)(lVar2 + 0x248) = 0;
    *(undefined8 *)(lVar2 + 0x250) = 0;
    *(undefined8 *)(lVar2 + 600) = 0;
    *(undefined8 *)(lVar2 + 0x260) = 0;
    *(undefined4 *)(lVar2 + 0x268) = 0;
    lVar2 = DAT_00110520;
    *(undefined8 *)(lVar1 + 0x248) = 0;
    *(undefined8 *)(lVar1 + 0x250) = 0;
    *(undefined8 *)(lVar1 + 600) = 0;
    *(undefined8 *)(lVar1 + 0x260) = 0;
    *(undefined4 *)(lVar1 + 0x268) = 0;
    lVar1 = DAT_00110538;
    *(undefined8 *)(lVar2 + 0x248) = 0;
    *(undefined8 *)(lVar2 + 0x250) = 0;
    *(undefined8 *)(lVar2 + 600) = 0;
    *(undefined8 *)(lVar2 + 0x260) = 0;
    *(undefined4 *)(lVar2 + 0x268) = 0;
    lVar2 = DAT_00110550;
    *(undefined8 *)(lVar1 + 0x248) = 0;
    *(undefined8 *)(lVar1 + 0x250) = 0;
    *(undefined8 *)(lVar1 + 600) = 0;
    *(undefined8 *)(lVar1 + 0x260) = 0;
    *(undefined4 *)(lVar1 + 0x268) = 0;
    lVar1 = DAT_00110568;
    *(undefined8 *)(lVar2 + 0x248) = 0;
    *(undefined8 *)(lVar2 + 0x250) = 0;
    *(undefined8 *)(lVar2 + 600) = 0;
    *(undefined8 *)(lVar2 + 0x260) = 0;
    *(undefined4 *)(lVar2 + 0x268) = 0;
    lVar3 = DAT_00110598;
    lVar2 = DAT_00110580;
    *(undefined8 *)(lVar1 + 0x248) = 0;
    *(undefined8 *)(lVar1 + 0x250) = 0;
    *(undefined8 *)(lVar1 + 600) = 0;
    *(undefined8 *)(lVar1 + 0x260) = 0;
    *(undefined4 *)(lVar1 + 0x268) = 0;
    *(undefined8 *)(lVar2 + 0x248) = 0;
    *(undefined8 *)(lVar2 + 0x250) = 0;
    *(undefined8 *)(lVar2 + 600) = 0;
    *(undefined8 *)(lVar2 + 0x260) = 0;
    *(undefined4 *)(lVar2 + 0x268) = 0;
    *(undefined4 *)(lVar3 + 0x268) = 0;
    *(undefined8 *)(lVar3 + 0x260) = 0;
    *(undefined8 *)(lVar3 + 600) = 0;
    *(undefined8 *)(lVar3 + 0x250) = 0;
    *(undefined8 *)(lVar3 + 0x248) = 0;
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  return param_4;
}



// ===========================================================
// Function: commstop_store.cfi_jt at 00118158
// ===========================================================

undefined8
commstop_store_cfi_jt(undefined8 param_1,undefined8 param_2,undefined1 *param_3,undefined8 param_4)

{
  long lVar1;
  
  if (DAT_001105a8 != 0) {
    _printk(&DAT_001120e0,"commstop_store",0x806);
  }
  if ((*(long *)(spidev + 0x130) == 0) || (*(long *)(spidev + 0x138) == 0)) {
    if (DAT_001105a8 == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      _printk(&DAT_00111a51,"commstop_store",0x808);
      param_4 = 0xffffffffffffffff;
    }
  }
  else {
    switch(*param_3) {
    case 0x30:
      if (DAT_001105a8 == 0) {
        close_comm_state = 0;
        return param_4;
      }
      _printk(&DAT_00110f7e,"commstop_store",0x816);
      close_comm_state = 0;
      break;
    case 0x31:
      if (DAT_001105a8 == 0) {
        close_comm_state = 3;
        return param_4;
      }
      _printk(&DAT_0011102d,"commstop_store",0x80d);
      close_comm_state = 3;
      break;
    case 0x32:
      if (DAT_001105a8 == 0) {
        close_comm_state = 2;
        return param_4;
      }
      _printk(&DAT_001121e3,"commstop_store",0x810);
      close_comm_state = 2;
      break;
    case 0x33:
      if (DAT_001105a8 == 0) {
        close_comm_state = 1;
        return param_4;
      }
      _printk(&DAT_00111eba,"commstop_store",0x813);
      close_comm_state = 1;
      break;
    default:
      if (DAT_001105a8 == 0) {
        return 0xffffffffffffffea;
      }
      _printk(&DAT_00110e5d,"commstop_store",0x819);
      return 0xffffffffffffffea;
    }
    if (DAT_001105a8 != 0) {
      lVar1 = sp_el0;
      _printk(&DAT_00111858,"commstop_store",0x820,lVar1 + 0x810,*(undefined4 *)(lVar1 + 0x640));
    }
  }
  return param_4;
}



// ===========================================================
// Function: auto_reset_mcu_store.cfi_jt at 0011815c
// ===========================================================

undefined8
auto_reset_mcu_store_cfi_jt(undefined8 param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_001105a8;
  if (*param_3 == '1') {
    uVar2 = 1;
  }
  else {
    if (*param_3 != '0') {
      return 0xffffffffffffffea;
    }
    uVar2 = 0;
  }
  dci._4_4_ = 0xfffffff6;
  *(undefined4 *)(spidev + 0x3b8) = uVar2;
  if (iVar1 != 0) {
    _printk(&DAT_00111352,"auto_reset_mcu_store",0x775);
  }
  return param_4;
}



// ===========================================================
// Function: speedtest_store.cfi_jt at 00118160
// ===========================================================

undefined8 speedtest_store_cfi_jt(void)

{
  undefined8 in_x3;
  
  return in_x3;
}



// ===========================================================
// Function: ccch_close.cfi_jt at 00118164
// ===========================================================

undefined8 ccch_close_cfi_jt(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    if (DAT_001105a8 == 0) {
      uVar1 = 0xffffffea;
    }
    else {
      _printk(&DAT_001112f7,"ccch_close",0x636);
      uVar1 = 0xffffffea;
    }
  }
  else if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return uVar1;
}



// ===========================================================
// Function: comm_master_upload_thread.cfi_jt at 00118168
// ===========================================================

void comm_master_upload_thread_cfi_jt(void)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  size_t __n;
  uint uVar7;
  undefined4 uVar8;
  long lVar9;
  ulong uVar10;
  undefined2 *puVar11;
  long lVar12;
  long *plVar13;
  ulong uVar14;
  ushort *puVar15;
  int iVar16;
  ulong uVar17;
  ushort *puVar18;
  sched_param asStack_68 [2];
  
  asStack_68[0].__sched_priority = 0x34;
  iVar4 = sched_setscheduler((__pid_t)*(undefined8 *)(spidev + 0x130),1,asStack_68);
  if (iVar4 != 0 && DAT_001105a8 != 0) {
    _printk(&DAT_00110d38,"comm_master_upload_thread",0x4ec);
  }
  if (DAT_001105d8 != 0) {
    lVar12 = *(long *)(spidev + 0x130);
    _printk(&DAT_00112031,"comm_master_upload_thread",0x4ee,*(undefined4 *)(lVar12 + 0x640),
            *(undefined4 *)(lVar12 + 0x488),*(undefined4 *)(lVar12 + 0x7c));
  }
  gpio_to_desc(*(undefined4 *)(spidev + 0xd0));
  iVar4 = gpiod_get_raw_value();
  if (iVar4 == 1) {
    if (DAT_001105a8 != 0) {
      _printk(&DAT_00112374,"comm_master_upload_thread",0x4f1);
    }
    up(spidev + 0xe8);
  }
  iVar4 = 0;
LAB_00114d24:
  do {
    while (iVar5 = down_trylock(spidev + 0xe8), iVar5 == 0) {
      DAT_001002c0 = DAT_001002c0 + 1;
    }
    gpio_to_desc(*(undefined4 *)(spidev + 0xd0));
    iVar5 = gpiod_get_raw_value();
    if (iVar5 == 0) {
      __pm_relax(spidev + 0x148);
      enable_irq(*(undefined4 *)(spidev + 0xe0));
      down(spidev + 0xe8);
    }
    __pm_stay_awake(spidev + 0x148);
    mutex_lock(spidev + 0xa0);
    lVar12 = spidev;
    memset(*(void **)(spidev + 0x50),0,0x3ffc);
    memset(*(void **)(lVar12 + 0x68),0,0x3ffc);
    iVar5 = spidev_spi_sync(0,*(undefined8 *)(lVar12 + 0x50));
    lVar12 = spidev;
    if (iVar5 == 0) {
      memcpy(*(void **)(spidev + 0x68),*(void **)(spidev + 0x50),0x3ffc);
      puVar18 = *(ushort **)(lVar12 + 0x68);
      if ((char)(*(char *)((long)puVar18 + 1) + (char)*puVar18 +
                 (char)puVar18[1] + *(char *)((long)puVar18 + 3) +
                 (char)puVar18[2] + *(char *)((long)puVar18 + 5) + (char)puVar18[3] +
                *(char *)((long)puVar18 + 7)) != -1) {
LAB_00114f60:
        DAT_001002b0._0_4_ = (int)DAT_001002b0 + 1;
        goto LAB_00114f6c;
      }
      uVar1 = puVar18[3];
      __n = (size_t)uVar1;
      if (0x3ff4 < uVar1) goto LAB_00114f60;
      if (uVar1 < 2) {
        uVar7 = 0;
      }
      else {
        uVar7 = (uint)(uVar1 >> 1);
        if (uVar1 >> 1 < 2) {
          uVar7 = 1;
        }
        uVar10 = (ulong)uVar7;
        if (uVar7 < 2) {
          uVar14 = 0;
          uVar7 = 0;
        }
        else {
          uVar14 = uVar10 & 0x7ffe;
          iVar5 = 0;
          iVar16 = 0;
          puVar15 = puVar18 + 5;
          uVar17 = uVar14;
          do {
            uVar17 = uVar17 - 2;
            iVar5 = iVar5 + (uint)puVar15[-1];
            iVar16 = iVar16 + (uint)*puVar15;
            puVar15 = puVar15 + 2;
          } while (uVar17 != 0);
          uVar7 = iVar16 + iVar5;
          if (uVar14 == uVar10) goto LAB_00114ee8;
        }
        lVar9 = uVar10 - uVar14;
        puVar15 = puVar18 + uVar14 + 4;
        do {
          lVar9 = lVar9 + -1;
          uVar7 = uVar7 + *puVar15;
          puVar15 = puVar15 + 1;
        } while (lVar9 != 0);
      }
LAB_00114ee8:
      puVar15 = puVar18 + 4;
      if ((uVar1 & 1) != 0) {
        uVar7 = uVar7 + *(byte *)((long)puVar15 + (ulong)(uVar1 - 1));
      }
      if ((uint)puVar18[2] != (~(uVar7 + (uVar7 >> 0x10)) & 0xffff)) goto LAB_00114f60;
      if (((puVar18[1] & 1) == 0) && ((is_first_up_frame & 1) != 0)) {
        if (up_selnum - 1 == (uint)*puVar18) {
          memcpy(&comm_master_upload_thread_packet_area,puVar15,__n);
          iVar5 = 3;
          up_selnum = *puVar18 + 1;
        }
        else {
          iVar5 = (uint)*puVar18 - (uint)up_selnum;
          if (iVar5 == 0) goto LAB_00115048;
          if (DAT_001105a8 != 0) {
            _printk(&DAT_00111e39,"check_and_get_data_from_ram",0x2dc,up_selnum,iVar5);
            __n = (size_t)puVar18[3];
          }
          memcpy(&comm_master_upload_thread_packet_area,puVar15,__n);
          iVar5 = 0;
          up_selnum = *puVar18 + 1;
          DAT_001002a8._4_4_ = DAT_001002a8._4_4_ + 1;
        }
      }
      else {
        if (((puVar18[1] & 1) != 0) &&
           (oplus_snshub_states_uevent(0,&DAT_001122f4), DAT_001105c8 != 0)) {
          _printk(&DAT_00111692,"check_and_get_data_from_ram",0x2d6,up_selnum);
        }
LAB_00115048:
        memcpy(&comm_master_upload_thread_packet_area,puVar15,(ulong)puVar18[3]);
        iVar5 = 0;
        up_selnum = *puVar18 + 1;
        is_first_up_frame = 1;
        DAT_001002b0._4_4_ = DAT_001002b0._4_4_ + 1;
      }
      uVar6 = gpio_to_desc(*(undefined4 *)(spidev + 0xdc));
      gpiod_direction_output_raw(uVar6,1);
      __const_udelay(0xa7c6);
    }
    else {
      if (DAT_001105a8 != 0) {
        _printk(&DAT_00112076,"upload_spi_seq",700,iVar5);
      }
      DAT_001002b8._4_4_ = DAT_001002b8._4_4_ + 1;
      lVar12 = spidev;
LAB_00114f6c:
      uVar6 = gpio_to_desc(*(undefined4 *)(lVar12 + 0xdc));
      gpiod_direction_output_raw(uVar6,1);
      msleep(0x96);
      iVar5 = 2;
    }
    uVar6 = gpio_to_desc(*(undefined4 *)(spidev + 0xdc));
    gpiod_direction_output_raw(uVar6,0);
    mutex_unlock(spidev + 0xa0);
    uVar6 = gpio_to_desc(*(undefined4 *)(spidev + 0xdc));
    gpiod_direction_output_raw(uVar6,0);
    while ((close_comm_state >> 1 & 1) != 0) {
      msleep(5000);
    }
    if (iVar5 != 3) {
      if (iVar5 == 0) {
        if (comm_master_upload_thread_packet_area != 0x3b9) {
          if (comm_master_upload_thread_packet_area == 0x3b8) {
            memcpy(&upload_speed_string,&DAT_001084cc,0x200);
            upload_speed_string_ready = 1;
          }
          else {
            if (DAT_001104d0 == comm_master_upload_thread_packet_area) {
              lVar12 = 0;
LAB_00115390:
              plVar13 = &DAT_001104d8 + lVar12 * 3;
            }
            else {
              if (DAT_001104e8 == comm_master_upload_thread_packet_area) {
                lVar12 = 1;
                goto LAB_00115390;
              }
              if (DAT_00110500 == comm_master_upload_thread_packet_area) {
                lVar12 = 2;
                goto LAB_00115390;
              }
              if (DAT_00110518 == comm_master_upload_thread_packet_area) {
                lVar12 = 3;
                goto LAB_00115390;
              }
              if (DAT_00110530 == comm_master_upload_thread_packet_area) {
                lVar12 = 4;
                goto LAB_00115390;
              }
              if (DAT_00110548 == comm_master_upload_thread_packet_area) {
                lVar12 = 5;
                goto LAB_00115390;
              }
              if (DAT_00110560 == comm_master_upload_thread_packet_area) {
                lVar12 = 6;
                goto LAB_00115390;
              }
              if (DAT_00110578 == comm_master_upload_thread_packet_area) {
                lVar12 = 7;
                goto LAB_00115390;
              }
              plVar13 = &DAT_001104d8;
              if (DAT_00110590 == comm_master_upload_thread_packet_area) {
                lVar12 = 8;
                goto LAB_00115390;
              }
            }
            lVar12 = *plVar13;
            if (lVar12 == 0) {
              if (DAT_001105a8 != 0) {
                _printk(&DAT_00110d9a,"distribute_packet_to_data_cdev",0x443);
              }
            }
            else {
              sVar2 = is_sau_filter(*(undefined2 *)(lVar12 + 0x1c));
              if (sVar2 == 0) {
                if (DAT_00110618 != 0) {
                  _printk(&DAT_001123e4,PTR_s_packet_to_fifo_00110610,DAT_001084ca + 4,
                          *(undefined8 *)(lVar12 + 0x20));
                  print_hex_dump(&DAT_00110c3f,&DAT_00111a43,2,0x10,1,
                                 &comm_master_upload_thread_packet_area,(ulong)DAT_001084ca + 4,1);
                }
                if ((*(short *)(lVar12 + 0x1c) == 2) && (DAT_001105a8 != 0)) {
                  _printk(&DAT_001117b2,"distribute_packet_to_data_cdev",0x461,
                          *(undefined8 *)(lVar12 + 0x20),DAT_001084ca,&DAT_001084cc);
                }
                iVar5 = DAT_001105a8;
                if (*(char *)(spidev + 0x3bc) != '\0') {
                  *(undefined1 *)(spidev + 0x3bc) = 0;
                  if (iVar5 != 0) {
                    _printk(&DAT_00111b91,"distribute_packet_to_data_cdev",0x46e,
                            *(undefined8 *)(lVar12 + 0x20),DAT_001084ca);
                  }
                  lVar9 = 0x10;
                  if (DAT_001084ca < 0xd) {
                    lVar9 = (ulong)DAT_001084ca + 4;
                  }
                  print_hex_dump(&DAT_00110c3f,"ocm: ",2,0x10,1,
                                 &comm_master_upload_thread_packet_area,lVar9,0);
                }
                iVar5 = *(int *)(lVar12 + 0x28) - *(int *)(lVar12 + 0x2c);
                if (((distribute_packet_to_data_cdev_sleep_flag & 1) == 0) && (0x14000 < iVar5)) {
                  distribute_packet_to_data_cdev_sleep_flag = 1;
                  if (DAT_001105a8 != 0) {
                    _printk(&DAT_001113c3,"distribute_packet_to_data_cdev",0x47d);
                  }
                  uVar8 = 0x32;
                  if (*(short *)(lVar12 + 0x1c) != 1) {
                    uVar8 = 0;
                  }
                  msleep(uVar8);
                }
                else if (iVar5 < 0xc800) {
                  distribute_packet_to_data_cdev_sleep_flag = 0;
                }
                lVar9 = lVar12 + 0x40;
                uVar7 = DAT_001084ca + 4;
                mutex_lock(lVar9);
                if ((*(int *)(lVar12 + 0x30) - *(int *)(lVar12 + 0x28)) + *(int *)(lVar12 + 0x2c) +
                    1U <= uVar7) {
                  mutex_unlock(lVar9);
                  iVar5 = *(int *)(lVar12 + 0x24c) + 1;
                  *(int *)(lVar12 + 0x24c) = iVar5;
                  if (((iVar5 < 10) ||
                      (((uint)(iVar5 * -0x3d70a3d7) >> 2 | iVar5 * 0x40000000) < 0x28f5c29)) &&
                     (DAT_001105a8 != 0)) {
                    _printk(&DAT_00111f52,"distribute_packet_to_data_cdev",0x490,
                            *(undefined8 *)(lVar12 + 0x20),0,iVar5,*(undefined4 *)(lVar12 + 0x250));
                  }
                  uVar8 = 200;
                  if (*(short *)(lVar12 + 0x1c) != 1) {
                    uVar8 = 0x14;
                  }
                  msleep(uVar8);
                  iVar5 = *(int *)(lVar12 + 0x28) - *(int *)(lVar12 + 0x2c);
                  if (((distribute_packet_to_data_cdev_sleep_flag & 1) == 0) && (0x14000 < iVar5)) {
                    distribute_packet_to_data_cdev_sleep_flag = 1;
                    if (DAT_001105a8 != 0) {
                      _printk(&DAT_001113c3,"distribute_packet_to_data_cdev",0x47d);
                    }
                    uVar8 = 0x32;
                    if (*(short *)(lVar12 + 0x1c) != 1) {
                      uVar8 = 0;
                    }
                    msleep(uVar8);
                  }
                  else if (iVar5 < 0xc800) {
                    distribute_packet_to_data_cdev_sleep_flag = 0;
                  }
                  uVar7 = DAT_001084ca + 4;
                  mutex_lock(lVar9);
                  if ((*(int *)(lVar12 + 0x30) - *(int *)(lVar12 + 0x28)) + *(int *)(lVar12 + 0x2c)
                      + 1U <= uVar7) {
                    mutex_unlock(lVar9);
                    iVar5 = *(int *)(lVar12 + 0x24c) + 1;
                    *(int *)(lVar12 + 0x24c) = iVar5;
                    if (((iVar5 < 10) ||
                        (((uint)(iVar5 * -0x3d70a3d7) >> 2 | iVar5 * 0x40000000) < 0x28f5c29)) &&
                       (DAT_001105a8 != 0)) {
                      _printk(&DAT_00111f52,"distribute_packet_to_data_cdev",0x490,
                              *(undefined8 *)(lVar12 + 0x20),1,iVar5,*(undefined4 *)(lVar12 + 0x250)
                             );
                    }
                    uVar8 = 200;
                    if (*(short *)(lVar12 + 0x1c) != 1) {
                      uVar8 = 0x14;
                    }
                    msleep(uVar8);
                    iVar5 = *(int *)(lVar12 + 0x248);
                    if ((iVar5 == 0) && (DAT_001105a8 != 0)) {
                      _printk(&DAT_00111c4e,"distribute_packet_to_data_cdev",0x498,
                              *(undefined8 *)(lVar12 + 0x20));
                      iVar5 = *(int *)(lVar12 + 0x248);
                    }
                    *(int *)(lVar12 + 0x248) = iVar5 + 1;
                    goto joined_r0x001156f8;
                  }
                }
                __kfifo_in((int *)(lVar12 + 0x28),&comm_master_upload_thread_packet_area,uVar7);
                mutex_unlock(lVar9);
                up(lVar12 + 0x70);
                pm_wakeup_ws_event(lVar12 + 0x158,1000,0);
                *(int *)(lVar12 + 0x250) = *(int *)(lVar12 + 0x250) + 1;
                if (*(int *)(lVar12 + 0x248) != 0) {
                  if ((1 < *(int *)(lVar12 + 0x248)) && (DAT_001105a8 != 0)) {
                    _printk(&DAT_0011094d,"distribute_packet_to_data_cdev",0x49d,
                            *(undefined8 *)(lVar12 + 0x20));
                  }
                  *(undefined4 *)(lVar12 + 0x248) = 0;
                }
              }
              else {
                sVar2 = *(short *)(lVar12 + 0x1c);
                if (distribute_packet_to_data_cdev_last_channel_id != sVar2) {
                  if ((distribute_packet_to_data_cdev_last_channel_id != 0) && (DAT_001105a8 != 0))
                  {
                    uVar3 = get_sau_ch_id();
                    _printk(&DAT_00110dc5,"distribute_packet_to_data_cdev",0x44e,uVar3,
                            distribute_packet_to_data_cdev_last_channel_id,
                            distribute_packet_to_data_cdev_print_cnt);
                    sVar2 = *(short *)(lVar12 + 0x1c);
                  }
                  distribute_packet_to_data_cdev_last_channel_id = sVar2;
                  distribute_packet_to_data_cdev_print_cnt = 0;
                  if (DAT_001105a8 != 0) {
                    uVar3 = get_sau_ch_id();
                    _printk(&DAT_00111970,"distribute_packet_to_data_cdev",0x453,uVar3,
                            *(undefined2 *)(lVar12 + 0x1c));
                  }
                }
                distribute_packet_to_data_cdev_print_cnt =
                     distribute_packet_to_data_cdev_print_cnt + 1;
                if ((((uint)(distribute_packet_to_data_cdev_print_cnt * -0x33333333) >> 1 |
                     distribute_packet_to_data_cdev_print_cnt * -0x80000000) < 0x1999999a) &&
                   (DAT_001105a8 != 0)) {
                  uVar3 = get_sau_ch_id();
                  _printk(&DAT_00110dc5,"distribute_packet_to_data_cdev",0x458,uVar3,
                          distribute_packet_to_data_cdev_last_channel_id,
                          distribute_packet_to_data_cdev_print_cnt);
                }
              }
            }
          }
        }
joined_r0x001156f8:
        if ((iVar4 != 0) && (DAT_001105a8 != 0)) {
          if (DAT_001104d0 == comm_master_upload_thread_packet_area) {
            lVar12 = 0;
LAB_00114cc0:
            plVar13 = &DAT_001104d8 + lVar12 * 3;
          }
          else {
            if (DAT_001104e8 == comm_master_upload_thread_packet_area) {
              lVar12 = 1;
              goto LAB_00114cc0;
            }
            if (DAT_00110500 == comm_master_upload_thread_packet_area) {
              lVar12 = 2;
              goto LAB_00114cc0;
            }
            if (DAT_00110518 == comm_master_upload_thread_packet_area) {
              lVar12 = 3;
              goto LAB_00114cc0;
            }
            if (DAT_00110530 == comm_master_upload_thread_packet_area) {
              lVar12 = 4;
              goto LAB_00114cc0;
            }
            if (DAT_00110548 == comm_master_upload_thread_packet_area) {
              lVar12 = 5;
              goto LAB_00114cc0;
            }
            if (DAT_00110560 == comm_master_upload_thread_packet_area) {
              lVar12 = 6;
              goto LAB_00114cc0;
            }
            if (DAT_00110578 == comm_master_upload_thread_packet_area) {
              lVar12 = 7;
              goto LAB_00114cc0;
            }
            plVar13 = &DAT_001104d8;
            if (DAT_00110590 == comm_master_upload_thread_packet_area) {
              lVar12 = 8;
              goto LAB_00114cc0;
            }
          }
          _printk(&DAT_00111dc2,"comm_master_upload_thread",0x502,DAT_001084ca,
                  *(undefined8 *)(*plVar13 + 0x20));
        }
        pm_wakeup_ws_event(spidev + 0x2e8,300,0);
        iVar4 = 0;
      }
      else {
        if (iVar5 == 2) {
          if (DAT_001105a8 != 0) {
            puVar11 = *(undefined2 **)(spidev + 0x68);
            _printk(&DAT_001124c6,"comm_master_upload_thread",0x50c,*puVar11,puVar11[1],puVar11[2],
                    puVar11[3]);
          }
          if ((comm_master_upload_thread_packet_area == 0x3b9) &&
             (uVar10 = (ulong)DAT_001084ca, DAT_001084ca != 0)) {
            uVar17 = 0;
            iVar5 = DAT_001105a8;
            do {
              if ((&DAT_001084cc)[uVar17] != -0x5b && iVar5 != 0) {
                _printk(&DAT_001121a3,"comm_master_upload_thread",0x511,uVar17 & 0xffffffff);
                uVar10 = (ulong)DAT_001084ca;
                iVar5 = DAT_001105a8;
              }
            } while ((uVar17 < 0x3fef) && (uVar17 = uVar17 + 1, uVar17 < uVar10));
          }
        }
        iVar4 = iVar4 + 1;
        if (0x1e < iVar4) {
          if (((DAT_001105a8 != 0) &&
              (_printk(&DAT_00112249,"comm_master_upload_thread",0x518), close_comm_state != 0)) &&
             (DAT_001105a8 != 0)) {
            _printk(&DAT_001125e9,"comm_master_upload_thread",0x519);
          }
          oplus_snshub_states_uevent(2,&DAT_001122f4);
          iVar4 = 0;
        }
      }
      goto LAB_00114d24;
    }
    if (DAT_001105c8 != 0) {
      _printk(&DAT_00110d77,"comm_master_upload_thread",0x508);
    }
  } while( true );
}



// ===========================================================
// Function: comm_master_download_thread.cfi_jt at 0011816c
// ===========================================================

void comm_master_download_thread_cfi_jt(void)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  long lVar5;
  ulong uVar6;
  sched_param asStack_68 [2];
  
  asStack_68[0].__sched_priority = 0x36;
  iVar3 = sched_setscheduler((__pid_t)*(undefined8 *)(spidev + 0x138),1,asStack_68);
  if (iVar3 != 0 && DAT_001105a8 != 0) {
    _printk(&DAT_001110d4,"comm_master_download_thread",0x52d);
  }
  if (DAT_001105d8 != 0) {
    lVar5 = *(long *)(spidev + 0x138);
    _printk(&DAT_00111d0a,"comm_master_download_thread",0x52f,*(undefined4 *)(lVar5 + 0x640),
            *(undefined4 *)(lVar5 + 0x488),*(undefined4 *)(lVar5 + 0x7c));
  }
  do {
    while( true ) {
      __pm_relax(spidev + 0x218);
      down(spidev + 0x118);
      __pm_stay_awake(spidev + 0x218);
      lVar5 = DAT_001104d8;
      if ((((((*(int *)(DAT_001104d8 + 0x88) != *(int *)(DAT_001104d8 + 0x8c)) ||
             (lVar5 = DAT_001104f0, *(int *)(DAT_001104f0 + 0x88) != *(int *)(DAT_001104f0 + 0x8c)))
            || (lVar5 = DAT_00110508, *(int *)(DAT_00110508 + 0x88) != *(int *)(DAT_00110508 + 0x8c)
               )) || ((lVar5 = DAT_00110520,
                      *(int *)(DAT_00110520 + 0x88) != *(int *)(DAT_00110520 + 0x8c) ||
                      (lVar5 = DAT_00110538,
                      *(int *)(DAT_00110538 + 0x88) != *(int *)(DAT_00110538 + 0x8c))))) ||
          ((lVar5 = DAT_00110550, *(int *)(DAT_00110550 + 0x88) != *(int *)(DAT_00110550 + 0x8c) ||
           ((lVar5 = DAT_00110568, *(int *)(DAT_00110568 + 0x88) != *(int *)(DAT_00110568 + 0x8c) ||
            (lVar5 = DAT_00110580, *(int *)(DAT_00110580 + 0x88) != *(int *)(DAT_00110580 + 0x8c))))
           ))) || (lVar5 = DAT_00110598,
                  *(int *)(DAT_00110598 + 0x88) != *(int *)(DAT_00110598 + 0x8c))) break;
      memset(&comm_master_download_thread_packet_area,0,0x3ff4);
LAB_00115c9c:
      if (DAT_001105a8 != 0) {
        _printk(&DAT_00110b2d,"comm_master_download_thread",0x562);
      }
      msleep(10);
    }
    memset(&comm_master_download_thread_packet_area,0,0x3ff4);
    if (lVar5 == 0) goto LAB_00115c9c;
    sVar1 = is_sau_filter(*(undefined2 *)(lVar5 + 0x1c));
    if (sVar1 == 0) {
      memset(*(void **)(spidev + 0x60),0,0x3ffc);
      iVar3 = cdev_fifo_out_frame(lVar5 + 0x88,&comm_master_download_thread_packet_area);
      uVar2 = DAT_0010c4d2;
      if (iVar3 < 0) {
        if (DAT_001105a8 != 0) {
          _printk(&DAT_00110ca0,"comm_master_download_thread",0x545,*(undefined8 *)(lVar5 + 0x20),
                  iVar3);
        }
      }
      else if ((close_comm_state & 1) == 0) {
        mutex_lock(*(long *)(lVar5 + 8) + 0x70);
        iVar3 = comm_master_download(&DAT_0010c4d4,uVar2,comm_master_download_thread_packet_area);
        if (iVar3 == 0) {
          if ((DAT_001105e8 != 0) &&
             ((comm_master_download_thread_packet_area == 7 ||
              (comm_master_download_thread_packet_area == 1)))) {
            if (DAT_0010c4d4 < 0x400) {
              _printk(&DAT_0011104b,&DAT_00110bcb,(ulong)DAT_0010c4d4,DAT_0010c4d6);
            }
            else {
              uVar6 = (ulong)DAT_0010c4d4 & 0xff;
              if ((DAT_0010c4d4 >> 8 == 0x18) && ((int)uVar6 - 1U < 2)) {
                iVar3 = *(int *)(&test_msgid + uVar6 * 4);
                *(int *)(&test_msgid + uVar6 * 4) = iVar3 + 1;
                if (99 < iVar3 + 1) {
                  _printk(&DAT_001111ed,&DAT_00110bcb,uVar6,0x18,DAT_0010c4d6);
                  *(undefined4 *)(&test_msgid + uVar6 * 4) = 0;
                }
              }
              else {
                _printk(&DAT_00112209,&DAT_00110bcb,uVar6,DAT_0010c4d4 >> 8,DAT_0010c4d6);
              }
            }
          }
          piVar4 = (int *)(lVar5 + 0x260);
          *(int *)(lVar5 + 0x264) = *(int *)(lVar5 + 0x264) + 1;
        }
        else {
          piVar4 = (int *)(lVar5 + 0x268);
        }
        *piVar4 = *piVar4 + 1;
        mutex_unlock(*(long *)(lVar5 + 8) + 0x70);
        gpio_to_desc(*(undefined4 *)(spidev + 0xd0));
        iVar3 = gpiod_get_raw_value();
        if (iVar3 == 1) {
          msleep();
        }
      }
      else if (DAT_001105a8 != 0) {
        _printk(&DAT_00110e0c,"comm_master_download_thread",0x54b);
      }
    }
    else if (DAT_001105a8 != 0) {
      uVar2 = get_sau_ch_id();
      _printk(&DAT_00111970,"comm_master_download_thread",0x539,uVar2,*(undefined2 *)(lVar5 + 0x1c))
      ;
    }
  } while( true );
}



// ===========================================================
// Function: speedtest_thread.cfi_jt at 00118170
// ===========================================================

undefined8 speedtest_thread_cfi_jt(long *param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auVar4 [16];
  int iVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  sched_param asStack_90 [2];
  undefined8 uStack_88;
  long lStack_80;
  undefined8 uStack_78;
  long lStack_70;
  long lStack_68;
  
  lVar7 = sp_el0;
  lStack_68 = *(long *)(lVar7 + 0x648);
  asStack_90[0].__sched_priority = 0x36;
  iVar6 = sched_setscheduler((__pid_t)*param_1,1,asStack_90);
  if ((iVar6 != 0) && (DAT_001105a8 != 0)) {
    _printk(&DAT_00112106,"speedtest_thread",0x79a);
  }
  if (DAT_001105d8 != 0) {
    lVar7 = *param_1;
    _printk(&DAT_0011242c,"speedtest_thread",0x79c,*(undefined4 *)(lVar7 + 0x640),
            *(undefined4 *)(lVar7 + 0x488),*(undefined4 *)(lVar7 + 0x7c));
  }
  mutex_lock(spidev + 0x70);
  lVar7 = 1;
  do {
    uVar2 = *(uint *)(&UNK_00112a24 + lVar7 * 4);
    uVar8 = (ulong)uVar2;
    if (DAT_001105c8 != 0) {
      _printk(&DAT_00111129,"speedtest_thread",0x7b0,uVar8);
    }
    uStack_78 = 0;
    lStack_70 = 0;
    uStack_88 = 0;
    lStack_80 = 0;
    memset(&speedtest_send_data_buf,0xa5,0x3ff0);
    ktime_get_real_ts64(&uStack_88);
    iVar6 = 2000;
    do {
      comm_master_download(&speedtest_send_data_buf,uVar8 & 0xffff,0x3b9);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    ktime_get_real_ts64(&uStack_78);
    auVar4 = SEXT816(lStack_70 - lStack_80) * SEXT816(0x20c49ba5e353f7cf);
    iVar5 = (((int)(auVar4._8_8_ >> 7) - (auVar4._12_4_ >> 0x1f)) +
            ((int)uStack_78 - (int)uStack_88) * 1000000) / 100000;
    iVar6 = 0;
    if (iVar5 != 0) {
      iVar6 = ((int)(uVar8 & 0xffff) * 2000) / iVar5;
    }
    uVar3 = 0;
    if (uVar2 != 0) {
      uVar3 = (iVar6 * 10) / (int)uVar2;
    }
    iVar6 = snprintf((char *)(param_1[2] + param_1[1]),0x1000 - param_1[1],
                     "download: packet_size(%d), speed(%dB/s), frequency(%dHz)\n",uVar8,
                     (ulong)(uint)(iVar6 * 10),(ulong)uVar3);
    param_1[1] = param_1[1] + (long)iVar6;
    if (DAT_001105c8 != 0) {
      _printk(&DAT_00110ce0,"speedtest_thread",0x7b5,uVar8);
    }
    lVar7 = lVar7 + 1;
  } while (lVar7 != 5);
  upload_speed_string_ready = 0;
  comm_master_download(&DAT_00110a2c,1,0x3b8);
  if (DAT_001105c8 != 0) {
    _printk(&DAT_001119ee,"speedtest_thread",0x7bc);
  }
  if ((upload_speed_string_ready & 1) == 0) {
    iVar6 = -0x3b;
    do {
      msleep_interruptible(1000);
      if ((upload_speed_string_ready & 1) != 0) break;
      bVar1 = iVar6 != 0;
      iVar6 = iVar6 + 1;
    } while (bVar1);
    if (upload_speed_string_ready == 0) {
      iVar6 = snprintf((char *)(param_1[2] + param_1[1]),0x1000 - param_1[1],
                       "upload: test timeout\n");
      goto LAB_00118004;
    }
  }
  iVar6 = snprintf((char *)(param_1[2] + param_1[1]),0x1000 - param_1[1],"%s",&upload_speed_string);
LAB_00118004:
  param_1[1] = param_1[1] + (long)iVar6;
  if (DAT_001105c8 != 0) {
    _printk(&DAT_00110b92,"speedtest_thread",0x7ca);
  }
  mutex_unlock(spidev + 0x70);
  speed_test_complt = 1;
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x648) != lStack_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



// ===========================================================
// Function: cleanup_module.cfi_jt at 00118174
// ===========================================================

void cleanup_module_cfi_jt(void)

{
  return;
}



// ===========================================================
// Function: init_module at 00118b54
// ===========================================================

ulong init_module(void)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  undefined *puVar4;
  long lVar5;
  
  uVar3 = __class_create(&__this_module,&DAT_001122f4,&spidev);
  spidev_class = uVar3;
  if (uVar3 < 0xfffffffffffff001) {
    lVar5 = 0;
    do {
      iVar1 = class_create_file_ns(spidev_class,(long)&attributes + lVar5,0);
      if (iVar1 != 0) {
        _printk(&DAT_00110c42);
      }
      lVar5 = lVar5 + 0x20;
    } while (lVar5 != 0xa0);
    uVar2 = __register_chrdev(0x99,0,0x100,&DAT_00111671,&spidev_fops);
    if ((int)uVar2 < 0) {
      puVar4 = &DAT_001116f5;
    }
    else {
      uVar2 = __spi_register_driver(&__this_module,&spidev_spi_driver);
      if (-1 < (int)uVar2) {
        uVar3 = 0;
        goto LAB_00118c18;
      }
      puVar4 = &DAT_00111675;
    }
    uVar3 = (ulong)uVar2;
    _printk(puVar4);
  }
  else {
    _printk(&DAT_00110ec4,uVar3 & 0xffffffff);
    spidev_class = 0;
  }
LAB_00118c18:
  return uVar3 & 0xffffffff;
}



// ===========================================================
// Function: cleanup_module at 00118c70
// ===========================================================

void cleanup_module(void)

{
  return;
}



// ===========================================================
// Function: _printk at 0011b000
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: mutex_lock at 0011b008
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: print_hex_dump at 0011b010
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void print_hex_dump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: mutex_unlock at 0011b018
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: device_destroy at 0011b020
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: kfree at 0011b028
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: up at 0011b030
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: msleep at 0011b038
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __kfifo_in at 0011b040
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __kfifo_in(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: down_trylock at 0011b048
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void down_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __pm_relax at 0011b050
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: down_interruptible at 0011b058
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void down_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __kfifo_out at 0011b060
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __kfifo_out(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: strncmp at 0011b068
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: strlen at 0011b070
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __class_create at 0011b078
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __spi_register_driver at 0011b080
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __spi_register_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: class_create_file_ns at 0011b088
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void class_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: snprintf at 0011b090
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: simple_strtol at 0011b098
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void simple_strtol(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: gpiod_get_raw_value at 0011b0a0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: gpio_to_desc at 0011b0a8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: get_sau_ch_id at 0011b0b0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void get_sau_ch_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: kthread_create_on_node at 0011b0b8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: wake_up_process at 0011b0c0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: kthread_stop at 0011b0c8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void kthread_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: sched_setscheduler at 0011b0d0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sched_setscheduler(__pid_t __pid,int __policy,sched_param *__param)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: msleep_interruptible at 0011b0d8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void msleep_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: ktime_get_real_ts64 at 0011b0e0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_real_ts64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: is_sau_filter at 0011b0e8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void is_sau_filter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: oplus_snshub_states_uevent at 0011b0f0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void oplus_snshub_states_uevent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: wait_mcureseting at 0011b0f8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void wait_mcureseting(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __const_udelay at 0011b100
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: gpiod_direction_output_raw at 0011b108
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: cpu_latency_qos_update_request at 0011b110
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: spi_sync at 0011b118
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void spi_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __list_add_valid at 0011b120
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: down_timeout at 0011b128
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void down_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: refcount_warn_saturate at 0011b130
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __register_chrdev at 0011b138
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __register_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: no_llseek at 0011b140
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void no_llseek(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __check_object_size at 0011b148
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __arch_copy_to_user at 0011b150
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __arch_copy_from_user at 0011b158
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: set_sau_ch_id at 0011b160
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void set_sau_ch_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: nonseekable_open at 0011b168
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void nonseekable_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: oplus_spi_slave_ready_cb_register at 0011b170
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void oplus_spi_slave_ready_cb_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __mutex_init at 0011b178
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: cpu_latency_qos_add_request at 0011b180
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: kmem_cache_alloc_trace at 0011b188
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void kmem_cache_alloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: kmalloc_order_trace at 0011b190
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_order_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: of_property_read_variable_u32_array at 0011b198
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: wakeup_source_add at 0011b1a0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: of_get_named_gpio_flags at 0011b1a8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: gpio_request at 0011b1b0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void gpio_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: gpiod_direction_input at 0011b1b8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_input(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: gpiod_to_irq at 0011b1c0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: request_threaded_irq at 0011b1c8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: disable_irq_nosync at 0011b1d0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void disable_irq_nosync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: pm_wakeup_ws_event at 0011b1d8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_ws_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: irq_set_irq_wake at 0011b1e0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: device_create at 0011b1e8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __kfifo_alloc at 0011b1f0
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __kfifo_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: enable_irq at 0011b1f8
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: down at 0011b200
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void down(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __pm_stay_awake at 0011b208
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __ubsan_handle_cfi_check_fail_abort at 0011b210
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __ubsan_handle_cfi_check_fail_abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: memset at 0011b240
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: memcpy at 0011b248
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===========================================================
// Function: __stack_chk_fail at 0011b250
// ===========================================================

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



