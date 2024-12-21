// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2024.2 (lin64) Build 5239630 Fri Nov 08 22:34:34 MST 2024
// Date        : Sat Dec 21 14:15:16 2024
// Host        : t14s running 64-bit Arch Linux
// Command     : write_verilog -force -mode synth_stub /home/b83c/fpga/vga/ips/clk_mcmm/clk_mcmm_stub.v
// Design      : clk_mcmm
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a35tcpg236-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* CORE_GENERATION_INFO = "clk_mcmm,clk_wiz_v6_0_15_0_0,{component_name=clk_mcmm,use_phase_alignment=true,use_min_o_jitter=false,use_max_i_jitter=false,use_dyn_phase_shift=false,use_inclk_switchover=false,use_dyn_reconfig=false,enable_axi=0,feedback_source=FDBK_AUTO,PRIMITIVE=MMCM,num_out_clk=2,clkin1_period=10.000,clkin2_period=10.000,use_power_down=false,use_reset=true,use_locked=true,use_inclk_stopped=false,feedback_type=SINGLE,CLOCK_MGR_TYPE=NA,manual_override=false}" *) 
module clk_mcmm(clk_108, clk_25, reset, locked, clk)
/* synthesis syn_black_box black_box_pad_pin="reset,locked,clk" */
/* synthesis syn_force_seq_prim="clk_108" */
/* synthesis syn_force_seq_prim="clk_25" */;
  output clk_108 /* synthesis syn_isclock = 1 */;
  output clk_25 /* synthesis syn_isclock = 1 */;
  input reset;
  output locked;
  input clk;
endmodule
