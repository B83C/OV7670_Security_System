// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2024.1 (lin64) Build 5076996 Wed May 22 18:36:09 MDT 2024
// Date        : Mon Dec  9 16:21:21 2024
// Host        : t14s running 64-bit Arch Linux
// Command     : write_verilog -force -mode synth_stub /home/b83c/fpga/vga/ips/joystick_adc/joystick_adc_stub.v
// Design      : joystick_adc
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a35tcpg236-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
module joystick_adc(daddr_in, dclk_in, den_in, di_in, dwe_in, reset_in, 
  vauxp6, vauxn6, vauxp14, vauxn14, busy_out, channel_out, do_out, drdy_out, eoc_out, eos_out, 
  vccaux_alarm_out, vccint_alarm_out, user_temp_alarm_out, alarm_out, vp_in, vn_in)
/* synthesis syn_black_box black_box_pad_pin="daddr_in[6:0],den_in,di_in[15:0],dwe_in,reset_in,vauxp6,vauxn6,vauxp14,vauxn14,busy_out,channel_out[4:0],do_out[15:0],drdy_out,eoc_out,eos_out,vccaux_alarm_out,vccint_alarm_out,user_temp_alarm_out,alarm_out,vp_in,vn_in" */
/* synthesis syn_force_seq_prim="dclk_in" */;
  input [6:0]daddr_in;
  input dclk_in /* synthesis syn_isclock = 1 */;
  input den_in;
  input [15:0]di_in;
  input dwe_in;
  input reset_in;
  input vauxp6;
  input vauxn6;
  input vauxp14;
  input vauxn14;
  output busy_out;
  output [4:0]channel_out;
  output [15:0]do_out;
  output drdy_out;
  output eoc_out;
  output eos_out;
  output vccaux_alarm_out;
  output vccint_alarm_out;
  output user_temp_alarm_out;
  output alarm_out;
  input vp_in;
  input vn_in;
endmodule
