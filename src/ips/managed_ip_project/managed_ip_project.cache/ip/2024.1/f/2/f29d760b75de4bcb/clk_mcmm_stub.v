// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2024.1 (lin64) Build 5076996 Wed May 22 18:36:09 MDT 2024
// Date        : Thu Nov 21 13:46:38 2024
// Host        : t14s running 64-bit Arch Linux
// Command     : write_verilog -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ clk_mcmm_stub.v
// Design      : clk_mcmm
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a35tcpg236-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix(clk_108, clk_25, reset, locked, clk)
/* synthesis syn_black_box black_box_pad_pin="reset,locked,clk" */
/* synthesis syn_force_seq_prim="clk_108" */
/* synthesis syn_force_seq_prim="clk_25" */;
  output clk_108 /* synthesis syn_isclock = 1 */;
  output clk_25 /* synthesis syn_isclock = 1 */;
  input reset;
  output locked;
  input clk;
endmodule
