`timescale 1ns/1ps
module tb1;

logic clk = 0;

always #1 clk <= ~clk;

localparam C_W = 8;
localparam C_H = 8;
localparam SCALE = 4;

localparam int HCC = 1280/(C_W * SCALE);
localparam int VCC = 1024/(C_H * SCALE);
localparam int x_bound = HCC * C_W * SCALE;
localparam int y_bound = VCC * C_H * SCALE;

logic [$clog2(SCALE) - 1:0] scale_cntr_x = 0, scale_cntr_y = 0;

logic [7 - 1:0] text_buffer [1280/(C_W*SCALE) - 1: 0][1024/(C_H*SCALE) - 1: 0];

logic [$clog2(C_W) - 1: 0] x_cntr = 0;
logic [$clog2(C_H) - 1: 0] y_cntr = 0;
logic [$clog2(HCC) - 1: 0] c_x = 0;
logic [$clog2(VCC) - 1: 0] c_y = 0;
logic [$clog2(128)- 1:0] character_addr;
logic [C_W*C_H - 1: 0] char_buf;
logic char_pix [C_H - 1 : 0][C_W - 1 : 0];
// assign char_pix = {>>{char_buf}};

logic [$clog2(1688):0] x;
logic [$clog2(1066):0] y;

logic [3:0] r,g,b;

//   localparam D_OFF_X = 700;
//   localparam D_OFF_Y = 20;
//   localparam C_W = 8;
//   localparam C_H = 8;
//   localparam STR_LEN = 5;
//   localparam SCALE = 4;
// logic [$clog2(128) - 1:0] character_addr;
// wire [C_W*C_H - 1:0] char_buf;
// rom #(.WIDTH(C_W*C_H), .DEPTH(128), .binaryFile("./ascii.rom")) ascii (.addr(character_addr), .data(char_buf), .clk(clk));

always @(posedge clk) begin
	
  if(x < 1280 && y < 1024) begin
      scale_cntr_x <= scale_cntr_x + 1;
      if(scale_cntr_x == $clog2(SCALE)'(SCALE - 1)) begin
          scale_cntr_x <= 0;
          x_cntr <= x_cntr + 1;
          if(x_cntr == $clog2(C_W)'(C_W - 1)) begin
              x_cntr <= 0;
              c_x <= c_x + 1;
              if (c_x == $clog2(HCC)'(HCC - 1)) begin
                  c_x <= 0;
                  scale_cntr_y <= scale_cntr_y + 1;
                  if(scale_cntr_y == $clog2(SCALE)'(SCALE - 1)) begin
                      scale_cntr_y <= 0;
                      y_cntr <= y_cntr + 1;
                      if(y_cntr == $clog2(C_H)'(C_H - 1)) begin
                          y_cntr <= 0;
                          c_y <= c_y + 1;
                          if (c_y == $clog2(VCC)'(VCC - 1)) begin
                              c_y <= 0;
                              character_addr <= text_buffer[0][0];
                          end else begin
                              character_addr <= text_buffer[0][c_y + 1];
                          end
                      end
                  end else begin
                      character_addr <= text_buffer[0][c_y];
                  end
              end else begin
                  character_addr <= text_buffer[c_x + 1][c_y];
              end
          end 
      end
      if(x_cntr == 0) begin
          {r,g,b} <= {3{4'b1101}};
      end
      if(y_cntr == 0) begin
          {r,g,b} <= {3{4'b0010}};
      end
    end
end

always @(posedge clk) begin
  x <= x + 1;
  if (x == 1688- 1) begin
    x <= 0;
    y <= y + 1;
    if (y == 1066 - 1) begin
      y <= 0;
    end
  end 
end

initial begin
  $dumpfile("waveform.vcd");
  $dumpvars(0, tb1);
  x = 0;
  y = 0;
  character_addr = 7'("H") ;
  #10000 $finish();
end
endmodule
