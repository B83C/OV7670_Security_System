// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2024.1 (lin64) Build 5076996 Wed May 22 18:36:09 MDT 2024
// Date        : Fri Dec  6 22:38:41 2024
// Host        : t14s running 64-bit Arch Linux
// Command     : write_verilog -force -mode synth_stub /home/b83c/fpga/vga/ips/enc_buff/enc_buff_stub.v
// Design      : enc_buff
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a35tcpg236-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "blk_mem_gen_v8_4_8,Vivado 2024.1" *)
module enc_buff(clka, ena, wea, addra, dina, clkb, enb, addrb, doutb)
/* synthesis syn_black_box black_box_pad_pin="ena,wea[0:0],addra[8:0],dina[2559:0],enb,addrb[8:0],doutb[2559:0]" */
/* synthesis syn_force_seq_prim="clka" */
/* synthesis syn_force_seq_prim="clkb" */;
  input clka /* synthesis syn_isclock = 1 */;
  input ena;
  input [0:0]wea;
  input [8:0]addra;
  input [2559:0]dina;
  input clkb /* synthesis syn_isclock = 1 */;
  input enb;
  input [8:0]addrb;
  output [2559:0]doutb;
endmodule
