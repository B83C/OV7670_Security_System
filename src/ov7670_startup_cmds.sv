`timescale 1ns/1ps

module ov7670_startup_cmds
(
  input clk,
  input inc,
  input rst_n,
  output logic [15:0] cmd
);
  logic [7:0]addr = 0;
  initial begin
    cmd = 16'hFFF0;
  end

  always @(posedge clk) begin
    if(inc)
      addr <= addr + 1;
    else if(!rst_n)
      addr <= 0;

    case(addr) 
      0: cmd <= 16'h1280; //reset
      1: cmd <= 16'hFFF0; //delay
      2: cmd <= 16'h1204; // COM7,     set RGB color output
      3: cmd <= 16'h1180; // CLKRC     internal PLL matches input clock
      4: cmd <= 16'h0C00; // COM3,     default settings
      5: cmd <= 16'h3E00; // COM14,    no scaling, normal pclock
      6: cmd <= 16'h0400; // COM1,     disable CCIR656
      // 0: cmd <= 16'h40d0; //COM15,     RGB565, full output range
      7: cmd <= 16'h40d0; // Full range output, RGB444 (RGB565)
      8: cmd <= 16'h8C03; //RGB444, Output: RG Bx 
      9: cmd <= 16'h3a04; //TSLB       set correct output data sequence (magic)
      10: cmd <= 16'h1418; //COM9       MAX AGC value x4
      11: cmd <= 16'h4FB3; //MTX1       all of these are magical matrix coefficients
      12: cmd <= 16'h50B3; //MTX2
      13: cmd <= 16'h5100; //MTX3
      14: cmd <= 16'h523d; //MTX4
      15: cmd <= 16'h53A7; //MTX5
      16: cmd <= 16'h54E4; //MTX6
      17: cmd <= 16'h589E; //MTXS
      18: cmd <= 16'h3DC0; //COM13      sets gamma enable, does not preserve reserved bits, may be wrong?
      19: cmd <= 16'h1714; //HSTART     start high 8 bits
      20: cmd <= 16'h1802; //HSTOP      stop high 8 bits //these kill the odd colored line
      21: cmd <= 16'h3280; //HREF       edge offset
      22: cmd <= 16'h1903; //VSTART     start high 8 bits
      23: cmd <= 16'h1A7B; //VSTOP      stop high 8 bits
      24: cmd <= 16'h030A; //VREF       vsync edge offset
      25: cmd <= 16'h0F41; //COM6       reset timings
      26: cmd <= 16'h1E37; //MVFP       disable mirror / flip //might have magic value of 03
      27: cmd <= 16'h330B; //CHLF       //magic value from the internet
      28: cmd <= 16'h3C78; //COM12      no HREF when VSYNC low
      29: cmd <= 16'h6900; //GFIX       fix gain control
      30: cmd <= 16'h7400; //REG74      Digital gain control
      31: cmd <= 16'hB084; //RSVD       magic value from the internet *required* for good color
      32: cmd <= 16'hB10c; //ABLC1
      33: cmd <= 16'hB20e; //RSVD       more magic internet values
      34: cmd <= 16'hB380; //34: cmd <= 16'hHLST;
      //begin mystery scaling numbers
      35: cmd <= 16'h703a;
      36: cmd <= 16'h7135;
      37: cmd <= 16'h7211;
      38: cmd <= 16'h73f0;
      39: cmd <= 16'ha202;
      //gamma curve values
      40: cmd <= 16'h7a20;
      41: cmd <= 16'h7b10;
      42: cmd <= 16'h7c1e;
      43: cmd <= 16'h7d35;
      44: cmd <= 16'h7e5a;
      45: cmd <= 16'h7f69;
      46: cmd <= 16'h8076;
      47: cmd <= 16'h8180;
      48: cmd <= 16'h8288;
      49: cmd <= 16'h838f;
      50: cmd <= 16'h8496;
      51: cmd <= 16'h85a3;
      52: cmd <= 16'h86af;
      53: cmd <= 16'h87c4;
      54: cmd <= 16'h88d7;
      55: cmd <= 16'h89e8;
      //AGC and AEC
      56: cmd <= 16'h13e0; //COM8, disable AGC / AEC
      57: cmd <= 16'h0000; //set gain reg to 0 for AGC
      58: cmd <= 16'h1000; //set ARCJ reg to 0
      59: cmd <= 16'h0d40; //magic reserved bit for COM4
      60: cmd <= 16'h1418; //COM9, 4x gain + magic bit
      61: cmd <= 16'ha505; // BD50MAX
      62: cmd <= 16'hab07; //DB60MAX
      63: cmd <= 16'h2495; //AGC upper limit
      64: cmd <= 16'h2533; //AGC lower limit
      65: cmd <= 16'h26e3; //AGC/AEC fast mode op region
      66: cmd <= 16'h9f78; //HAECC1
      67: cmd <= 16'ha068; //HAECC2
      68: cmd <= 16'ha103; //magic
      69: cmd <= 16'ha6d8; //HAECC3
      70: cmd <= 16'ha7d8; //HAECC4
      71: cmd <= 16'ha8f0; //HAECC5
      72: cmd <= 16'ha990; //HAECC6
      73: cmd <= 16'haa94; //HAECC7
      74: cmd <= 16'h13e5; //COM8, enable AGC / AEC
      default: cmd <= 16'hFFFF;
    endcase
  end
endmodule
