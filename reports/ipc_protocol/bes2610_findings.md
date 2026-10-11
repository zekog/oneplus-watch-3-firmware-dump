# Bestechnic BES2610 Wi-Fi / Bluetooth / MCU Driver Analysis (`bes2610.ko`)

**Target Binary:** `/home/zek/Pobrane/opw3 firmware/extracted_images/vendor_dlkm_extracted/lib/modules/bes2610.ko`  
**Architecture:** AArch64 Little-Endian (Linux 5.15 GKI, Android Wear OS / OnePlus Watch 3)  
**Hardware Target:** Bestechnic BES2610 Multi-Core Wireless Coprocessor (Wi-Fi 802.11 b/g/n/ax + BT 5.2 + Sensor Hub/RTOS)  
**Driver Heritage:** Derived from RivieraWaves (CEVA) FullMAC 802.11 architecture with proprietary Bestechnic Multi-SPI (MSPI) interconnect and coex extensions.

---

## 1. Executive Summary & Inventory

### Symbol Table Metrics
- **Total Symbol Count:** 9,163 symbols (in `.symtab`)
- **Total Defined Functions (`T` / `t`):** 5,051 functions
  - **Global / Exported Functions (`T`):** 801 functions
  - **Local Static Functions (`t`):** 4,250 functions
- **Undefined Kernel Imports (`U`):** 287 symbols (including `spi_async`, `gpio_to_desc`, `gpiod_direction_output_raw`, `request_threaded_irq`, `cfg80211_*`, `crc16`)

---

## 2. Targeted Keyword Symbol Search

### A. Keyword `"ipc"` (61 symbols)
Implements the RivieraWaves IPC ring-buffer interface communicating between Host Application Processor (Snapdragon W5 Gen 1) and Embedded LMAC/UMAC on BES2610:
```
Address          Type  Symbol Name
---------------------------------------------------------
0000000000001f68  b    bes_tx_loop_pipe_send.ipc_a2e_msg
0000000000015814  t    __bpf_trace_ipc_msg_template
000000000007eea8  t    __bpf_trace_ipc_msg_template.cfi_jt
00000000000007e0  d    event_class_ipc_msg_template
0000000000030290  T    ipc_host_dbgbuf_push
0000000000030338  T    ipc_host_dbginfo_push
00000000000309a0  T    ipc_host_disable_irq
000000000003098c  T    ipc_host_enable_irq
00000000000308d8  T    ipc_host_get_last_pushed_msg
00000000000309dc  T    ipc_host_get_rawstatus
00000000000309b4  T    ipc_host_get_status
000000000002fff0  T    ipc_host_init
00000000000304f8  T    ipc_host_irq
000000000003023c  T    ipc_host_msgbuf_push
0000000000030808  T    ipc_host_msg_push
00000000000300cc  T    ipc_host_pattern_push
000000000003019c  T    ipc_host_radar_push
00000000000300dc  T    ipc_host_rxbuf_push
0000000000030140  T    ipc_host_rxdesc_push
00000000000302e4  T    ipc_host_txcfm_push
0000000000030348  T    ipc_host_txdesc_push
000000000002ff40  T    ipc_host_tx_flush
000000000002ff24  T    ipc_host_tx_frames_pending
0000000000030440  T    ipc_host_tx_host_id_to_ptr
0000000000030384  T    ipc_host_tx_host_ptr_to_id
00000000000301ec  T    ipc_host_unsuprxvec_push
0000000000013b5c  t    perf_trace_ipc_msg_template
000000000007ee94  t    perf_trace_ipc_msg_template.cfi_jt
0000000000004a10  d    print_fmt_ipc_msg_template
000000000000e228  T    rwnx_ipc_buf_a2e_init
000000000000ddc4  T    rwnx_ipc_buf_e2a_init
000000000000e84c  T    rwnx_ipc_cnt_e2a_buf_get
000000000000e318  T    rwnx_ipc_dbgbuf_alloc
000000000000e82c  T    rwnx_ipc_dbginfo_alloc
000000000000e844  T    rwnx_ipc_dbginfo_push
000000000000e470  T    rwnx_ipc_deinit
000000000000daec  T    rwnx_ipc_e2a_dump_trace
0000000000014bbcc T    rwnx_ipc_init
000000000000e428  T    rwnx_ipc_msgbuf_alloc
000000000000e448  T    rwnx_ipc_msg_push
000000000000e004  T    rwnx_ipc_pattern_alloc
000000000000e290  T    rwnx_ipc_radar_buf_alloc
000000000000df40  T    rwnx_ipc_rxbuf_alloc
000000000000de58  T    rwnx_ipc_rxdesc_init
000000000000ded4  T    rwnx_ipc_rxdesc_repush
000000000000e0d0  T    rwnx_ipc_txbuf_alloc
000000000000e04c  T    rwnx_ipc_txdesc_init
000000000000e16c  T    rwnx_ipc_txdesc_push
000000000000e144  T    rwnx_ipc_unsuprxvec_alloc
00000000000160a0  t    trace_event_raw_event_ipc_msg_template
000000000007eea0  t    trace_event_raw_event_ipc_msg_template.cfi_jt
0000000000000830  d    trace_event_type_funcs_ipc_msg_template
0000000000013b50  t    trace_raw_output_ipc_msg_template
000000000007ee90  t    trace_raw_output_ipc_msg_template.cfi_jt
```

### B. Keyword `"mspi"` (61 symbols)
Implements Bestechnic Multi-SPI framing, flow control, DMA aggregation, and interrupt-driven handshaking:
```
Address          Type  Symbol Name
---------------------------------------------------------
000000000004f278  T    bes_mspi_add_header
000000000004ef2c  t    bes_mspi_check_first_data
000000000004f068  t    bes_mspi_check_second_data
000000000004e24c  t    bes_mspi_clr_int
000000000007f094  t    bes_mspi_clr_int.cfi_jt
000000000004cf08  t    bes_mspi_cmd_build
000000000004e438  t    bes_mspi_data_get
000000000007f098  t    bes_mspi_data_get.cfi_jt
000000000004d78c  t    bes_mspi_data_mem_init
000000000004d988  t    bes_mspi_data_push
000000000007f08c  t    bes_mspi_data_push.cfi_jt
0000000000013594  d    bes_mspi_default_blksize
000000000004c77c  t    bes_mspi_disconnect
000000000007f07c  t    bes_mspi_disconnect.cfi_jt
0000000000013598  d    bes_mspi_driver
000000000004d018  t    bes_mspi_exchange
000000000004e5fc  t    bes_mspi_exchange_done
000000000007f508  t    bes_mspi_exchange_done.cfi_jt
0000000000050578  T    bes_mspi_exit
00000000000502c8  T    bes_mspi_init
000000000004d840  T    bes_mspi_init_plat_cfg
000000000004fee0  t    bes_mspi_irq_handler
000000000007f0b0  t    bes_mspi_irq_handler.cfi_jt
000000000004ce44  t    bes_mspi_irq_poll
000000000004e50c  t    bes_mspi_lock
000000000004da90  t    bes_mspi_msg_push
000000000007f090  t    bes_mspi_msg_push.cfi_jt
000000000004f338  T    bes_mspi_platform_init
000000000004bb24  t    bes_mspi_plat_power
000000000007f070  t    bes_mspi_plat_power.cfi_jt
000000000004bc6c  t    bes_mspi_power_up
000000000007f074  t    bes_mspi_power_up.cfi_jt
000000000004bef8  t    bes_mspi_probe
000000000007f078  t    bes_mspi_probe.cfi_jt
000000000004caf4  t    bes_mspi_ready
000000000007f080  t    bes_mspi_ready.cfi_jt
000000000004e1bc  t    bes_mspi_recv_check
000000000004eb7c  t    bes_mspi_rx_aggr_data_process
000000000004e768  t    bes_mspi_rx_aggr_msg_process
000000000004ccb4  t    bes_mspi_rx_buf_realloc
000000000004e6c4  t    bes_mspi_rx_data_irq
000000000007f0a8  t    bes_mspi_rx_data_irq.cfi_jt
000000000004cd88  t    bes_mspi_tx_done_irq
000000000007f088  t    bes_mspi_tx_done_irq.cfi_jt
000000000004df3c  t    bes_mspi_tx_aggr_finish
000000000004dc0c  t    bes_mspi_tx_aggr_try_add
000000000004fb0c  t    bes_mspi_write
000000000007f0ac  t    bes_mspi_write.cfi_jt
```

### C. Keyword `"cmd"` (81 symbols)
Implements RivieraWaves command manager, Android private Wi-Fi commands, and WPA supplicant commands:
- **Command Management:** `cmd_mgr_queue`, `cmd_mgr_print`, `cmd_mgr_drain`, `cmd_mgr_llind`, `cmd_mgr_msgind`
- **WPA / Supplicant Handlers:** `bes2610_wpa_cmd_btcoex_mode`, `bes2610_wpa_cmd_country_set`, `bes2610_wpa_cmd_p2p_set_noa`, `bes2610_wpa_cmd_p2p_set_ps`, `bes2610_wpa_cmd_rxfilter_*`, `bes2610_wpa_cmd_set_suspendmode`
- **Wireless Extension Commands:** `android_priv_cmd`, `bes_iw_priv_cmd_get_country`, `bes_iw_priv_cmd_get_online_scan`
- **RivieraWaves Protocol Commands:** `rwnx_send_reset`, `rwnx_send_start`, `rwnx_send_me_config_req`, `rwnx_send_country_code_cfg`, `rwnx_send_pta_cfg`

### D. Keyword `"transfer"` (0 symbols)
*Note:* The driver does not use the symbol word `"transfer"` in function identifiers; SPI operations are named `exchange`, `write`, `data_push`, and `aggr_copy`.

---

## 3. MSPI (Multi-SPI) Framing Architecture

### A. Physical SPI Configuration (`bes_mspi_probe` @ `0x00188ef8`)
- **Word Length:** 32 bits (`spi->bits_per_word = 32`)
- **SPI Mode:** Mode 1 (`spi->mode = 1`, `SPI_CPHA`)
- **Chip ID Check:** Validates that `(response >> 16) == 0xbe57` (Bestechnic signature `0xBE57`).
- **Dedicated Handshake GPIOs (requested from Device Tree):**
  1. `slave-tx-ready-gpio` (`DAT_001060a0`): Output, driven low/high to signal slave TX ready.
  2. `slave-rx-ready-gpio` (`DAT_001060b0`): Output, signals slave RX readiness.
  3. `master-tx-ind-gpio` (`DAT_00105f78`): Input IRQ, MCU signals that it has incoming data.
  4. `master-crc-ok-gpio` (`DAT_00106098`): Interrupt `bes_mspi_tx_done_irq` (`IRQF_TRIGGER_RISING | IRQF_ONESHOT`), MCU ACKs frame CRC.
  5. `slave-crc-ok-gpio` (`DAT_001060b4`): Output, Host ACKs valid frame reception to MCU.

### B. Frame Format (`bes_mspi_tx_aggr_finish` @ `0x0018af3c`)
The Multi-SPI packet structure consists of an 8-byte fixed header followed by aggregated sub-packet payloads:

```
+0x00               +0x02               +0x04       +0x05       +0x06               +0x08
+-------------------+-------------------+-----------+-----------+-------------------+----------------------------+
|  CRC-16 (2B)      |  Seq Number (2B)  | Flags(1B) | Count(1B) | Aggr Length (2B)  | Sub-Packet Payloads ...    |
+-------------------+-------------------+-----------+-----------+-------------------+----------------------------+
| CRC16 over [2..N] | Increments per TX | 1 = Data  | Num pkts  | Total payload len | Aligned 4-byte sub-frames  |
+-------------------+-------------------+-----------+-----------+-------------------+----------------------------+
```

1. **`CRC-16` (`uint16_t`):** Calculated using standard kernel `crc16(0, buf + 2, total_len - 2)`.
2. **`Sequence Number` (`uint16_t`):** Monotonically incrementing 16-bit counter (`DAT_00106094++`).
3. **`Flags / Type` (`uint8_t`):** `0x01` indicates standard aggregated data frame.
4. **`Aggregation Count` (`uint8_t`):** Number of concatenated sub-frames (`DAT_00106090`).
5. **`Aggregation Length` (`uint16_t`):** Exact byte count of the aggregated payload data (`DAT_00106092`).
6. **Payload:** Padded to 4-byte boundaries.

### C. Handshake & Exchange Flow (`bes_mspi_exchange` @ `0x0018a018`)
```
Host (Snapdragon W5)                            BES2610 MCU
       |                                             |
       |----- Asserts slave-rx-ready-gpio ---------->|
       |----- Transmits Frame via spi_async() ------>|
       |                                             |
       |<---- Asserts master-crc-ok-gpio (ACK) ------|
       |      (Threaded IRQ wakes tx completion)     |
       |                                             |
       |      [If timeout (25 jiffies): retry 3x]    |
       |                                             |
```

---

## 4. IPC Command Architecture (`rwnx_ipc_init` @ `0x0014bbcc`)

### A. Ring Buffer Allocation
- Allocates `0x2cc0` (11,456) bytes for IPC ring buffers via `kmalloc_order_trace(0x2cc0, GFP_KERNEL, 2)`.
- Instantiates `0xe9` (233) circular buffer descriptors into a linked list.

### B. Command Manager Dispatch Table
`rwnx_ipc_init` binds function pointers at offset `param_1 + 0x5608`:
- `+0x5608`: `cmd_mgr_queue` - Queues outbound command to MCU.
- `+0x5610`: `cmd_mgr_llind` - Low-level transmission confirmation indication.
- `+0x5618`: `cmd_mgr_msgind` - Inbound response message indication handler.
- `+0x5620`: `cmd_mgr_print` - Debug format printer for commands.
- `+0x5628`: `cmd_mgr_drain` - Flushes pending command queues.

---

## 5. MCU Command Inventory (`MCU_*`)

Analysis of binary strings identified **77 unique `MCU_*` commands and indications**:

### 1. Wi-Fi Power & State Control
- `MCU_WIFI_ON_OFF_REQ` / `MCU_WIFI_ON_OFF_CFM` (Power Wi-Fi core on/off)
- `MCU_WIFI_WAKE_CTRL_REQ` / `MCU_WIFI_WAKE_CTRL_CFM` (Host-MCU wake signaling)
- `MCU_HOST_LP_SUSPEND_REQ` / `MCU_HOST_LP_SUSPEND_CFM` (Host Low-Power sleep notice)
- `MCU_HOST_LP_RESUME_REQ` / `MCU_HOST_LP_RESUME_CFM` (Host Low-Power resume notice)
- `MCU_FW_CHANGE_MODE_REQ` / `MCU_FW_CHANGE_MODE_CFM` (Switch mode: STA / AP / P2P / Coex)
- `MCU_FW_REBOOT_REQ` / `MCU_FW_REBOOT_CFM` (Instructs BES2610 MCU reboot)

### 2. Bluetooth Coexistence & Packet Traffic Arbitration (PTA)
- `MCU_GET_BT_STATUS_REQ` / `MCU_GET_BT_STATUS_CFM` (Query BLE/BT audio active state)
- `MCU_BT_STATUS_IND` (Asynchronous notification of BT connection/audio state)

### 3. RF & Calibration
- `MCU_WIFI_CALI_REQ` / `MCU_WIFI_CALI_CFM` (Trigger Wi-Fi RF calibration)
- `MCU_CALI_INVAL_CHAN_REQ` / `MCU_CALI_INVAL_CHAN_CFM` (Invalidate channel cal)
- `MCU_DBAC_CALI_REQ` / `MCU_DBAC_CALI_CFM` (Dual-Band Audio/Coex calibration)
- `MCU_DBAC_TEMP_CALI_IND` (Temperature-triggered calibration event)
- `MCU_TEMP_COMPENSATION_REQ` / `MCU_TEMP_COMPENSATION_CFM` (Thermal compensation)
- `MCU_WIFI_GET_DPD_DATA_REQ` / `MCU_WIFI_GET_DPD_DATA_CFM` (Digital Pre-Distortion data get)
- `MCU_WIFI_SEND_DPD_DATA_REQ` / `MCU_WIFI_SEND_DPD_DATA_CFM` (Send DPD data to MCU)
- `MCU_WIFI_GET_DPD_SIZE_REQ` / `MCU_WIFI_GET_DPD_SIZE_CFM` (Query DPD size)
- `MCU_SET_TX_MAX_POWER_REQ` / `MCU_SET_TX_MAX_POWER_CFM` (Set RF EIRP limit)
- `MCU_VENDOR_RF_CMD_REQ` / `MCU_VENDOR_RF_CMD_CFM` (Vendor custom RF commands)

### 4. Scanning & Connectivity
- `MCU_SCANU_MC_SCAN_REQ` / `MCU_SCANU_MC_SCAN_CFM` (Multi-channel hardware scan)
- `MCU_SEND_COUNTRY_CODE_REQ` / `MCU_SEND_COUNTRY_CODE_CFM` (Regulatory domain / 802.11d)
- `MCU_GET_MAC_ADDR_REQ` / `MCU_GET_MAC_ADDR_CFM` (Fetch factory MAC from MCU)
- `MCU_WIFI_TB_PPDU_DISABLE_REQ` / `MCU_WIFI_TB_PPDU_DISABLE_CFM` (802.11ax Trigger-Based PPDU)
- `MCU_WIFI_IEEE80211B_RATE_REQ` (Force 802.11b rates)
- `MCU_IGNORE_BCN_EDCA_REQ` (Ignore beacon EDCA parameters)

### 5. Diagnostics, Memory, & Register Access
- `MCU_REG_READ_REQ` / `MCU_REG_READ_CFM` (Direct register read on BES2610)
- `MCU_REG_WRITE_REQ` / `MCU_REG_WRITE_CFM` (Direct register write on BES2610)
- `MCU_SYS_STATE_REQ` / `MCU_SYS_STATE_CFM` (System state report)
- `MCU_DEV_STATE_IND` (Device state change event)
- `MCU_GET_PLL_STATE_REQ` / `MCU_GET_PLL_STATE_CFM` (Query RF PLL lock status)
- `MCU_GET_TEMPRTR_REQ` / `MCU_GET_TEMPRTR_CFM` (Internal temperature read)
- `MCU_GET_DELAY_STATS_INFO_REQ` / `MCU_GET_DELAY_STATS_INFO_CFM` (Latency statistics)
- `MCU_BUF_CNT_REQ` / `MCU_BUF_CNT_CFM` (Firmware buffer count)
- `MCU_SYNC_DRV_INFO_REQ` / `MCU_SYNC_DRV_INFO_CFM` (Sync driver version and caps)

### 6. Crash & Firmware Dump Operations
- `MCU_DUMP_FW_LOG_REQ` / `MCU_DUMP_FW_LOG_CFM` / `MCU_DUMP_FW_LOG_IND` (Extract crash log)
- `MCU_DUMP_LTRACE_START_IND` (Start low-level RTOS trace dump)
- `MCU_DUMP_LTRACE_CONT_IND` (Continue trace dump block)
- `MCU_DUMP_LTRACE_SINGLE_IND` (Single-packet trace dump)
- `MCU_DUMP_LTRACE_END_IND` (End of trace dump)
- `MCU_DUMP_LTRACE_FAULT_IND` (Fault condition encountered during dump)
- `MCU_GET_RING_DATA_REQ` / `MCU_GET_RING_DATA_CFM` (Fetch circular debug buffer)
- `MCU_GET_RING_DATA_SAVE_SIZE_REQ` / `MCU_GET_RING_DATA_SAVE_SIZE_CFM` (Query size)

---

## 6. Debug Interfaces Exposed

### A. DebugFS Nodes (`/sys/kernel/debug/rwnx/`)
Registered by `rwnx_dbgfs_register` (`0x00053dcc`), exposing 38 debug attributes:
- **Logging & Tracing:** `log_ctrl`, `lmac_log_ctrl`, `fw_dbg`
- **Link & Performance Stats:** `stats`, `sys_stats`, `vif_stats`, `link_info`, `tx_rate`, `last_rx`, `rc_stats`, `rc_fixed_rate_idx`
- **Coexistence & PTA:** `pta_switch`, `pta_test`, `coex_state`, `pwr_status`
- **Power Savings & 802.11ax:** `twt_request`, `twt_teardown`, `noa`, `oppps`
- **Hardware Calibration:** `pre_cali`
- **Channel / PHY Controls:** `band`, `center1`, `center2`, `prim20`, `type`, `set`, `obss_bw_ru_filter`, `tdd_slice`, `tports`, `transq`, `duration`, `enable`, `flush`, `detected`, `pulses_prim`, `pulses_sec`, `unmatch_dst_mgmt_filter`, `vif_edca`

### B. SysFS Attributes (`bes_sysfs_attr`)
Registered under the sysfs kobject group `rwnx_besphy`:
1. `wifi_power` (RW, permissions `0644`): Powers on/off the BES2610 Wi-Fi subsystem.
2. `online_scan` (RW, permissions `0644`): Enables background Wi-Fi scanning during active links.
3. `fw_type` (RO, permissions `0444`): Returns firmware type string.
4. `fw_log_type` (RW, permissions `0644`): Controls firmware log capture level.
5. `custom_filter` (RW, permissions `0644`): Injects custom RX packet filter rules into firmware.

---

## 7. Key Decompiled Functions

### A. `rwnx_ipc_init` (`0x0014bbcc`)
```c
undefined8 rwnx_ipc_init(long param_1, undefined8 param_2) {
  undefined8 *puVar1;
  undefined8 *__s;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  int iVar6;
  
  if (3 < DAT_0010d5f8) {
    _printk(&DAT_00121924, "rwnx_ipc_init");
  }
  __s = (undefined8 *)kmalloc_order_trace(0x2cc0, 0xdc0, 2);
  *(undefined8 **)(param_1 + 0x55d8) = __s;
  if (__s == (undefined8 *)0x0) {
    uVar3 = 0xfffffff4; // -ENOMEM
  } else {
    memset(__s, 0, 0x2cc0);
    __s[6] = 0;
    __s[7] = param_2;
    puVar1 = __s + 0x447;
    puVar4 = __s + 0xa7;
    iVar6 = 1;
    *__s = 0;
    __s[0x597] = param_1;
    __s[0x447] = puVar1;
    __s[0x448] = puVar1;
    __s[0x449] = __s + 0x449;
    __s[0x44a] = __s + 0x449;
    do {
      *(int *)(puVar4 + 3) = iVar6;
      puVar5 = (undefined8 *)__s[0x448];
      uVar2 = __list_add_valid(puVar4, puVar5, puVar1);
      if ((uVar2 & 1) != 0) {
        __s[0x448] = puVar4;
        *puVar4 = puVar1;
        puVar4[1] = puVar5;
        *puVar5 = puVar4;
      }
      puVar4 = puVar4 + 4;
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0xe9); // 233 ring buffer slots

    *(long *)(param_1 + 0x55f8) = param_1 + 0x55f8;
    *(long *)(param_1 + 0x5600) = param_1 + 0x55f8;
    *(undefined4 *)(param_1 + 22000) = 8;
    *(undefined4 *)(param_1 + 0x55e4) = 0;

    // Command Manager Function Pointers
    *(code **)(param_1 + 0x5608) = cmd_mgr_queue_cfi_jt;
    *(code **)(param_1 + 0x5620) = cmd_mgr_print_cfi_jt;
    *(code **)(param_1 + 0x5628) = cmd_mgr_drain_cfi_jt;
    *(code **)(param_1 + 0x5610) = cmd_mgr_llind_cfi_jt;
    *(code **)(param_1 + 0x5618) = cmd_mgr_msgind_cfi_jt;
    uVar3 = 0;
  }
  return uVar3;
}
```

### B. `bes_mspi_probe` (`0x00188ef8`)
```c
uint bes_mspi_probe(long param_1) {
  // Configures SPI parameters: Mode 1, 32-bit words
  *(undefined4 *)(param_1 + 0x3a8) = 1;    // Mode 1 (SPI_CPHA)
  *(undefined1 *)(param_1 + 0x3a5) = 0x20; // 32 bits per word

  // Obtains handshake GPIOs from Device Tree
  DAT_001060a0 = of_get_named_gpio_flags(*(undefined8 *)(param_1 + 0x2f0), "slave-tx-ready-gpio", 0, 0);
  gpio_request(DAT_001060a0, "slave-tx-ready-gpio");
  gpiod_direction_output_raw(gpio_to_desc(DAT_001060a0), 0);

  DAT_001060b0 = of_get_named_gpio_flags(*(undefined8 *)(param_1 + 0x2f0), "slave-rx-ready-gpio", 0, 0);
  gpio_request(DAT_001060b0, "slave-rx-ready-gpio");
  gpiod_direction_output_raw(gpio_to_desc(DAT_001060b0), 0);

  DAT_00105f78 = of_get_named_gpio_flags(*(undefined8 *)(param_1 + 0x2f0), "master-tx-ind-gpio", 0, 0);
  DAT_00105f7c = gpiod_to_irq(gpio_to_desc(DAT_00105f78));

  DAT_00106098 = of_get_named_gpio_flags(*(undefined8 *)(param_1 + 0x2f0), "master-crc-ok-gpio", 0, 0);
  DAT_0010609c = gpiod_to_irq(gpio_to_desc(DAT_00106098));
  request_threaded_irq(DAT_0010609c, bes_mspi_tx_done_irq_cfi_jt, 0, 0x2001, "master-crc-ok-gpio", &DAT_00105f50);

  DAT_001060b4 = of_get_named_gpio_flags(*(undefined8 *)(param_1 + 0x2f0), "slave-crc-ok-gpio", 0, 0);
  gpio_request(DAT_001060b4, "slave-crc-ok-gpio");
  gpiod_direction_output_raw(gpio_to_desc(DAT_001060b4), 0);

  // Synchronizes and verifies Bestechnic Chip Signature (0xBE57)
  uVar4 = bes_mspi_cmd_build();
  bes_mspi_exchange(param_1, uVar4);
  if (DAT_00105f85 >> 0x10 == 0xbe57) {
    DAT_0010d004 = (undefined2)DAT_00105f85;
    bes_mspi_data_mem_init();
    bes_mspi_init_plat_cfg(param_1);
    rwnx_platform_init(&g_rwnx_plat, 0);
    return 0;
  }
  return -ENODEV;
}
```

### C. `bes_mspi_exchange` (`0x0018a018`)
```c
int bes_mspi_exchange(long param_1, long *param_2) {
  bes_mspi_lock(lVar15);
  // Enqueue SPI transfer and dispatch via spi_async
  spi_async(param_1, &local_100);

  // Wait for SPI bus completion with 250 jiffies timeout
  wait_for_completion_interruptible_timeout(&local_90, 0xfa);

  // If TX frame, wait for MCU hardware CRC confirmation IRQ
  if ((char)param_2[2] != '\0') {
    gpiod_set_raw_value(gpio_to_desc(*(undefined4 *)(lVar15 + 0x150)), 0);
    iVar10 = wait_for_completion_interruptible_timeout(&mspi_tx_ack_completion, 0x19); // 25 jiffies
    if (iVar10 <= 0) {
      // Retry up to 3 times on timeout
      if (retries++ < 3) {
        goto retry;
      }
      return -ETIMEDOUT; // -110 (0x6e)
    }
  }

  // Validate received frame length and CRC
  bes_mspi_recv_check(lVar15, param_2);
  return 0;
}
```
