#include "esp8266.h"

#define ESP8266_BROM_ADDRESS 0x40000000
#define ESP8266_BROM_SIZE    (0x10000 - 1)

std::unordered_map<rd_address, const char*> ESP8266::m_imports;

bool ESP8266::load(RDContext* ctx, rd_offset offset)
{
    RDDocument* document = RDContext_GetDocument(ctx);
    RDDocument_AddSegment(document, ".brom", 0, ESP8266_BROM_ADDRESS, ESP8266_BROM_SIZE, SegmentFlags_Bss);

    for(const auto& [address, name] : m_imports)
        RDDocument_AddImported(document, address, sizeof(u32), name);

    return ESPCommon::load(ctx, offset);
}

void ESP8266::initImports()
{
    if(!m_imports.empty()) return;

    m_imports[0x400047f0] = "Cache_Read_Disable";
    m_imports[0x40004678] = "Cache_Read_Enable";
    m_imports[0x400035a0] = "FilePacketSendReqMsgProc";
    m_imports[0x4000368c] = "FlashDwnLdParamCfgMsgProc";
    m_imports[0x40003538] = "FlashDwnLdStartMsgProc";
    m_imports[0x40003658] = "FlashDwnLdStopReqMsgProc";
    m_imports[0x40003f4c] = "GetUartDevice";
    m_imports[0x40009900] = "MD5Final";
    m_imports[0x40009818] = "MD5Init";
    m_imports[0x40009834] = "MD5Update";
    m_imports[0x400036c4] = "MemDwnLdStartMsgProc";
    m_imports[0x4000377c] = "MemDwnLdStopReqMsgProc";
    m_imports[0x400036f0] = "MemPacketSendReqMsgProc";
    m_imports[0x40003eac] = "RcvMsg";
    m_imports[0x4000b648] = "SHA1Final";
    m_imports[0x4000b584] = "SHA1Init";
    m_imports[0x4000a364] = "SHA1Transform";
    m_imports[0x4000b5a8] = "SHA1Update";
    m_imports[0x4000448c] = "Wait_SPI_Idle";
    m_imports[0x40004b44] = "SPIEraseArea";
    m_imports[0x400049b4] = "SPIEraseBlock";
    m_imports[0x40004984] = "SPIEraseChip";
    m_imports[0x40004a00] = "SPIEraseSector";
    m_imports[0x400048a8] = "SPILock";
    m_imports[0x40004c2c] = "SPIParamCfg";
    m_imports[0x40004b1c] = "SPIRead";
    m_imports[0x400048ec] = "SPIReadModeCnfig";
    m_imports[0x40004878] = "SPIUnlock";
    m_imports[0x40004a4c] = "SPIWrite";
    m_imports[0x40003f58] = "SelectSpiFunction";
    m_imports[0x40003cf4] = "SendMsg";
    m_imports[0x40003230] = "UartConnCheck";
    m_imports[0x400037a0] = "UartConnectProc";
    m_imports[0x40003368] = "UartDwnLdProc";
    m_imports[0x40003ef4] = "UartGetCmdLn";
    m_imports[0x4000381c] = "UartRegReadProc";
    m_imports[0x400037ac] = "UartRegWriteProc";
    m_imports[0x40003c30] = "UartRxString";
    m_imports[0x40003a14] = "Uart_Init";
    m_imports[0x40000010] = "_DebugExceptionVector";
    m_imports[0x40000070] = "_DoubleExceptionVector";
    m_imports[0x40000030] = "_KernelExceptionVector";
    m_imports[0x40000020] = "_NMIExceptionVector";
    m_imports[0x400000a4] = "_ResetHandler";
    m_imports[0x40000080] = "_ResetVector";
    m_imports[0x40000050] = "_UserExceptionVector";
    m_imports[0x4000c538] = "__adddf3";
    m_imports[0x4000c180] = "__addsf3";
    m_imports[0x4000cb94] = "__divdf3";
    m_imports[0x4000ce60] = "__divdi3";
    m_imports[0x4000dc88] = "__divsi3";
    m_imports[0x4000cdfc] = "__extendsfdf2";
    m_imports[0x4000ccb8] = "__fixdfsi";
    m_imports[0x4000cd00] = "__fixunsdfsi";
    m_imports[0x4000c4c4] = "__fixunssfsi";
    m_imports[0x4000e2f0] = "__floatsidf";
    m_imports[0x4000e2ac] = "__floatsisf";
    m_imports[0x4000e2e8] = "__floatunsidf";
    m_imports[0x4000e2a4] = "__floatunsisf";
    m_imports[0x4000c8f0] = "__muldf3";
    m_imports[0x40000650] = "__muldi3";
    m_imports[0x4000c3dc] = "__mulsf3";
    m_imports[0x4000c688] = "__subdf3";
    m_imports[0x4000c268] = "__subsf3";
    m_imports[0x4000cd5c] = "__truncdfsf2";
    m_imports[0x4000d310] = "__udivdi3";
    m_imports[0x4000e21c] = "__udivsi3";
    m_imports[0x4000d770] = "__umoddi3";
    m_imports[0x4000e268] = "__umodsi3";
    m_imports[0x4000dcf0] = "__umulsidi3";
    m_imports[0x4000e388] = "_rom_store";
    m_imports[0x4000e328] = "_rom_store_table";
    m_imports[0x4000042c] = "_start";
    m_imports[0x4000dbe0] = "_xtos_alloca_handler";
    m_imports[0x40000598] = "_xtos_c_wrapper_handler";
    m_imports[0x40000590] = "_xtos_cause3_handler";
    m_imports[0x4000bda4] = "_xtos_ints_off";
    m_imports[0x4000bd84] = "_xtos_ints_on";
    m_imports[0x4000048c] = "_xtos_l1int_handler";
    m_imports[0x4000dbf8] = "_xtos_p_none";
    m_imports[0x4000056c] = "_xtos_restore_intlevel";
    m_imports[0x4000dc54] = "_xtos_return_from_exc";
    m_imports[0x40000454] = "_xtos_set_exception_handler";
    m_imports[0x4000bd70] = "_xtos_set_interrupt_handler";
    m_imports[0x4000bd28] = "_xtos_set_interrupt_handler_arg";
    m_imports[0x4000dbfc] = "_xtos_set_intlevel";
    m_imports[0x4000dc18] = "_xtos_set_min_intlevel";
    m_imports[0x40000574] = "_xtos_set_vpri";
    m_imports[0x4000dbe4] = "_xtos_syscall_handler";
    m_imports[0x4000dc44] = "_xtos_unhandled_exception";
    m_imports[0x4000dc3c] = "_xtos_unhandled_interrupt";
    m_imports[0x400092d4] = "aes_decrypt";
    m_imports[0x400092e4] = "aes_decrypt_deinit";
    m_imports[0x40008ea4] = "aes_decrypt_init";
    m_imports[0x40009410] = "aes_unwrap";
    m_imports[0x40009648] = "base64_decode";
    m_imports[0x400094fc] = "base64_encode";
    m_imports[0x4000de84] = "bzero";
    m_imports[0x40000814] = "cmd_parse";
    m_imports[0x40000b24] = "conv_str_decimal";
    m_imports[0x40000cb8] = "conv_str_hex";
    m_imports[0x40000a60] = "convert_para_str";
    m_imports[0x400026d0] = "dtm_get_intr_mask";
    m_imports[0x4000269c] = "dtm_params_init";
    m_imports[0x400026c8] = "dtm_set_intr_mask";
    m_imports[0x400026dc] = "dtm_set_params";
    m_imports[0x40001d14] = "eprintf";
    m_imports[0x40001cb8] = "eprintf_init_buf";
    m_imports[0x40001d48] = "eprintf_to_host";
    m_imports[0x40002494] = "est_get_printf_buf_remain_len";
    m_imports[0x4000249c] = "est_reset_printf_buf_len";
    m_imports[0x40002ae8] = "ets_bzero";
    m_imports[0x40002b74] = "ets_char2xdigit";
    m_imports[0x40002ecc] = "ets_delay_us";
    m_imports[0x400027b8] = "ets_enter_sleep";
    m_imports[0x40002578] = "ets_external_printf";
    m_imports[0x40002f0c] = "ets_get_cpu_frequency";
    m_imports[0x40002bcc] = "ets_getc";
    m_imports[0x40002450] = "ets_install_external_printf";
    m_imports[0x4000242c] = "ets_install_putc1";
    m_imports[0x4000248c] = "ets_install_putc2";
    m_imports[0x40002438] = "ets_install_uart_printf";
    m_imports[0x40000f74] = "ets_intr_lock";
    m_imports[0x40000f80] = "ets_intr_unlock";
    m_imports[0x40000f88] = "ets_isr_attach";
    m_imports[0x40000f98] = "ets_isr_mask";
    m_imports[0x40000fa8] = "ets_isr_unmask";
    m_imports[0x400018d4] = "ets_memcmp";
    m_imports[0x400018b4] = "ets_memcpy";
    m_imports[0x400018c4] = "ets_memmove";
    m_imports[0x400018a4] = "ets_memset";
    m_imports[0x40000e24] = "ets_post";
    m_imports[0x400024cc] = "ets_printf";
    m_imports[0x40002be8] = "ets_putc";
    m_imports[0x40002a40] = "ets_rtc_int_register";
    m_imports[0x40000e04] = "ets_run";
    m_imports[0x40000dc0] = "ets_set_idle_cb";
    m_imports[0x40000fbc] = "ets_set_user_start";
    m_imports[0x40002af8] = "ets_str2macaddr";
    m_imports[0x40002aa8] = "ets_strcmp";
    m_imports[0x40002a88] = "ets_strcpy";
    m_imports[0x40002ac8] = "ets_strlen";
    m_imports[0x40002ab8] = "ets_strncmp";
    m_imports[0x40002a98] = "ets_strncpy";
    m_imports[0x40002ad8] = "ets_strstr";
    m_imports[0x40000dd0] = "ets_task";
    m_imports[0x40002cc4] = "ets_timer_arm";
    m_imports[0x40002d40] = "ets_timer_disarm";
    m_imports[0x40002d80] = "ets_timer_done";
    m_imports[0x40002da8] = "ets_timer_handler_isr";
    m_imports[0x40002e68] = "ets_timer_init";
    m_imports[0x40002c48] = "ets_timer_setfn";
    m_imports[0x40002544] = "ets_uart_printf";
    m_imports[0x40002f04] = "ets_update_cpu_frequency";
    m_imports[0x40001f00] = "ets_vprintf";
    m_imports[0x400030f0] = "ets_wdt_disable";
    m_imports[0x40002fa0] = "ets_wdt_enable";
    m_imports[0x40002f34] = "ets_wdt_get_mode";
    m_imports[0x40003170] = "ets_wdt_init";
    m_imports[0x40003158] = "ets_wdt_restore";
    m_imports[0x40001da0] = "ets_write_char";
    m_imports[0x4000091c] = "get_first_seg";
    m_imports[0x40004c50] = "gpio_init";
    m_imports[0x40004cf0] = "gpio_input_get";
    m_imports[0x40004dcc] = "gpio_intr_ack";
    m_imports[0x40004e28] = "gpio_intr_handler_register";
    m_imports[0x40004d88] = "gpio_intr_pending";
    m_imports[0x40004efc] = "gpio_intr_test";
    m_imports[0x40004cd0] = "gpio_output_set";
    m_imports[0x40004d90] = "gpio_pin_intr_state_set";
    m_imports[0x40004ed4] = "gpio_pin_wakeup_disable";
    m_imports[0x40004e90] = "gpio_pin_wakeup_enable";
    m_imports[0x40004d5c] = "gpio_register_get";
    m_imports[0x40004d04] = "gpio_register_set";
    m_imports[0x4000a2cc] = "hmac_md5";
    m_imports[0x4000a160] = "hmac_md5_vector";
    m_imports[0x4000ba28] = "hmac_sha1";
    m_imports[0x4000b8b4] = "hmac_sha1_vector";
    m_imports[0x40004f40] = "lldesc_build_chain";
    m_imports[0x40005050] = "lldesc_num2link";
    m_imports[0x4000507c] = "lldesc_set_owner";
    m_imports[0x40000fec] = "main";
    m_imports[0x400097ac] = "md5_vector";
    m_imports[0x40001c2c] = "mem_calloc";
    m_imports[0x400019e0] = "mem_free";
    m_imports[0x40001998] = "mem_init";
    m_imports[0x40001b40] = "mem_malloc";
    m_imports[0x40001c6c] = "mem_realloc";
    m_imports[0x40001a14] = "mem_trim";
    m_imports[0x40001c58] = "mem_zalloc";
    m_imports[0x4000dea8] = "memcmp";
    m_imports[0x4000df48] = "memcpy";
    m_imports[0x4000e04c] = "memmove";
    m_imports[0x4000e190] = "memset";
    m_imports[0x400031c0] = "multofup";
    m_imports[0x4000b840] = "pbkdf2_sha1";
    m_imports[0x40006b08] = "phy_get_romfuncs";
    m_imports[0x40000600] = "rand";
    m_imports[0x4000dd68] = "rc4_skip";
    m_imports[0x40003d08] = "recv_packet";
    m_imports[0x40000a04] = "remove_head_space";
    m_imports[0x40008dd0] = "rijndaelKeySetupDec";
    m_imports[0x40009300] = "rijndaelKeySetupEnc";
    m_imports[0x400060c0] = "rom_abs_temp";
    m_imports[0x40006b10] = "rom_ana_inf_gating_en";
    m_imports[0x40007a28] = "rom_cal_tos_v50";
    m_imports[0x40006f84] = "rom_chip_50_set_channel";
    m_imports[0x400060d0] = "rom_chip_v5_disable_cca";
    m_imports[0x400060ec] = "rom_chip_v5_enable_cca";
    m_imports[0x4000711c] = "rom_chip_v5_rx_init";
    m_imports[0x4000610c] = "rom_chip_v5_sense_backoff";
    m_imports[0x4000718c] = "rom_chip_v5_tx_init";
    m_imports[0x4000615c] = "rom_dc_iq_est";
    m_imports[0x400061b8] = "rom_en_pwdet";
    m_imports[0x40006238] = "rom_get_bb_atten";
    m_imports[0x40006260] = "rom_get_corr_power";
    m_imports[0x400062dc] = "rom_get_fm_sar_dout";
    m_imports[0x40006394] = "rom_get_noisefloor";
    m_imports[0x400063b0] = "rom_get_power_db";
    m_imports[0x40007268] = "rom_i2c_readReg";
    m_imports[0x4000729c] = "rom_i2c_readReg_Mask";
    m_imports[0x400072d8] = "rom_i2c_writeReg";
    m_imports[0x4000730c] = "rom_i2c_writeReg_Mask";
    m_imports[0x40006400] = "rom_iq_est_disable";
    m_imports[0x40006430] = "rom_iq_est_enable";
    m_imports[0x40006484] = "rom_linear_to_db";
    m_imports[0x400065a4] = "rom_mhz2ieee";
    m_imports[0x40007bf0] = "rom_pbus_dco___SA2";
    m_imports[0x4000737c] = "rom_pbus_debugmode";
    m_imports[0x40007410] = "rom_pbus_enter_debugmode";
    m_imports[0x40007448] = "rom_pbus_exit_debugmode";
    m_imports[0x4000747c] = "rom_pbus_force_test";
    m_imports[0x400074d8] = "rom_pbus_rd";
    m_imports[0x4000754c] = "rom_pbus_set_rxgain";
    m_imports[0x40007610] = "rom_pbus_set_txgain";
    m_imports[0x40007648] = "rom_pbus_workmode";
    m_imports[0x40007688] = "rom_pbus_xpd_rx_off";
    m_imports[0x400076cc] = "rom_pbus_xpd_rx_on";
    m_imports[0x400076fc] = "rom_pbus_xpd_tx_off";
    m_imports[0x40007740] = "rom_pbus_xpd_tx_on";
    m_imports[0x400077a0] = "rom_pbus_xpd_tx_on__low_gain";
    m_imports[0x40007804] = "rom_phy_reset_req";
    m_imports[0x4000781c] = "rom_restart_cal";
    m_imports[0x40007eb4] = "rom_rfcal_pwrctrl";
    m_imports[0x4000804c] = "rom_rfcal_rxiq";
    m_imports[0x40008264] = "rom_rfcal_rxiq_set_reg";
    m_imports[0x40008388] = "rom_rfcal_txcap";
    m_imports[0x40008610] = "rom_rfcal_txiq";
    m_imports[0x400088b8] = "rom_rfcal_txiq_cover";
    m_imports[0x40008a70] = "rom_rfcal_txiq_set_reg";
    m_imports[0x40007868] = "rom_rfpll_reset";
    m_imports[0x40007968] = "rom_rfpll_set_freq";
    m_imports[0x40008b6c] = "rom_rxiq_cover_mg_mp";
    m_imports[0x40006628] = "rom_rxiq_get_mis";
    m_imports[0x40006738] = "rom_sar_init";
    m_imports[0x4000678c] = "rom_set_ana_inf_tx_scale";
    m_imports[0x40006c50] = "rom_set_channel_freq";
    m_imports[0x400067c8] = "rom_set_loopback_gain";
    m_imports[0x40006830] = "rom_set_noise_floor";
    m_imports[0x40006550] = "rom_set_rxclk_en";
    m_imports[0x40008c6c] = "rom_set_txbb_atten";
    m_imports[0x4000650c] = "rom_set_txclk_en";
    m_imports[0x40008d34] = "rom_set_txiq_cal";
    m_imports[0x40006874] = "rom_start_noisefloor";
    m_imports[0x400068b4] = "rom_start_tx_tone";
    m_imports[0x4000698c] = "rom_stop_tx_tone";
    m_imports[0x40006a98] = "rom_tx_mac_disable";
    m_imports[0x40006ad4] = "rom_tx_mac_enable";
    m_imports[0x40006a1c] = "rom_txtone_linear_pwr";
    m_imports[0x400078dc] = "rom_write_rfpll_sdm";
    m_imports[0x400031b4] = "roundup2";
    m_imports[0x40002870] = "rtc_enter_sleep";
    m_imports[0x400025e0] = "rtc_get_reset_reason";
    m_imports[0x400029ec] = "rtc_intr_handler";
    m_imports[0x40002668] = "rtc_set_sleep_mode";
    m_imports[0x400027a4] = "save_rxbcn_mactime";
    m_imports[0x400027ac] = "save_tsf_us";
    m_imports[0x40003c80] = "send_packet";
    m_imports[0x4000ba48] = "sha1_prf";
    m_imports[0x4000a2ec] = "sha1_vector";
    m_imports[0x40005180] = "sip_alloc_to_host_evt";
    m_imports[0x400058a8] = "sip_get_ptr";
    m_imports[0x40005668] = "sip_get_state";
    m_imports[0x4000567c] = "sip_init_attach";
    m_imports[0x4000544c] = "sip_install_rx_ctrl_cb";
    m_imports[0x4000545c] = "sip_install_rx_data_cb";
    m_imports[0x400050fc] = "sip_post";
    m_imports[0x400056c4] = "sip_post_init";
    m_imports[0x4000534c] = "sip_reclaim_from_host_cmd";
    m_imports[0x400052c0] = "sip_reclaim_tx_data_pkt";
    m_imports[0x40005808] = "sip_send";
    m_imports[0x40005864] = "sip_to_host_chain_append";
    m_imports[0x40005234] = "sip_to_host_evt_send_done";
    m_imports[0x400060ac] = "slc_add_credits";
    m_imports[0x40005d90] = "slc_enable";
    m_imports[0x40005f24] = "slc_from_host_chain_fetch";
    m_imports[0x40005e94] = "slc_from_host_chain_recycle";
    m_imports[0x40005c50] = "slc_init_attach";
    m_imports[0x4000608c] = "slc_init_credit";
    m_imports[0x40006014] = "slc_pause_from_host";
    m_imports[0x40005c1c] = "slc_reattach";
    m_imports[0x4000603c] = "slc_resume_from_host";
    m_imports[0x40005dc0] = "slc_select_tohost_gpio";
    m_imports[0x40005db8] = "slc_select_tohost_gpio_mode";
    m_imports[0x40005de4] = "slc_send_to_host_chain";
    m_imports[0x40006068] = "slc_set_host_io_max_window";
    m_imports[0x40005f10] = "slc_to_host_chain_recycle";
    m_imports[0x4000264c] = "software_reset";
    m_imports[0x40004644] = "spi_flash_attach";
    m_imports[0x400005f0] = "srand";
    m_imports[0x4000bdc8] = "strcmp";
    m_imports[0x4000bec8] = "strcpy";
    m_imports[0x4000bf4c] = "strlen";
    m_imports[0x4000bfa8] = "strncmp";
    m_imports[0x4000c0a0] = "strncpy";
    m_imports[0x4000e1e0] = "strstr";
    m_imports[0x40002c64] = "timer_insert";
    m_imports[0x4000383c] = "uartAttach";
    m_imports[0x40003924] = "uart_baudrate_detect";
    m_imports[0x400038a4] = "uart_buff_switch";
    m_imports[0x400039d8] = "uart_div_modify";
    m_imports[0x40003bbc] = "uart_rx_intr_handler";
    m_imports[0x40003b8c] = "uart_rx_one_char";
    m_imports[0x40003b64] = "uart_rx_one_char_block";
    m_imports[0x40003ec8] = "uart_rx_readbuff";
    m_imports[0x40003b30] = "uart_tx_one_char";
    m_imports[0x4000bc40] = "wepkey_128";
    m_imports[0x4000bb3c] = "wepkey_64";
    m_imports[0x40000688] = "xthal_bcopy";
    m_imports[0x4000074c] = "xthal_copy123";
    m_imports[0x4000dd4c] = "xthal_get_ccompare";
    m_imports[0x4000dd38] = "xthal_get_ccount";
    m_imports[0x4000dd58] = "xthal_get_interrupt";
    m_imports[0x4000dd58] = "xthal_get_intread";
    m_imports[0x400006c4] = "xthal_memcpy";
    m_imports[0x4000dd40] = "xthal_set_ccompare";
    m_imports[0x4000dd60] = "xthal_set_intclear";
    m_imports[0x4000e320] = "xthal_spill_registers_into_stack_nw";
    m_imports[0x4000e324] = "xthal_window_spill";
    m_imports[0x4000e320] = "xthal_window_spill_nw";

    m_imports[0x3fffccf0] = "Te0";
    m_imports[0x3fffde10] = "UartDev";
    m_imports[0x3fffc714] = "flashchip";
}
