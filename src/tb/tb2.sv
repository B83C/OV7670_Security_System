`timescale 1ns/1ps

module tb2;

logic clk = 0;

always #1 clk = ~clk;

logic ph = 0;
logic [11:0] rgb;
logic enc_en = 1;
logic enc_rst_n = 1;

wire [7:0] output_stream [320 - 1:0];
wire [11:0] rgbstack [63:0];
wire capped;

qoi_rgb444_encoder enc(.clk(clk), .en(enc_en), .rst_n(enc_rst_n), .rgb(rgb), .output_stream(output_stream), .rgbstack(rgbstack), .capped(capped));

always @(posedge clk) begin
  ph <= ~ph;
  if (!ph) begin
    enc_en <= 0;
  end else begin
    enc_en <= 1;
  end
end

initial begin
  $dumpfile("waveform.fst");
  $dumpvars(0, tb2);
  #2 enc_rst_n = 0;
  #2 enc_rst_n = 1;
  #7 rgb = 12'hFFF;
  #4 rgb = 12'hFF0;
  #16 rgb = 12'hF0F;
  #4 rgb = 12'h0FF;
  #4 rgb = 12'hF0F;
  #4 rgb = 12'hFF0;
  #4 rgb = 12'hF0F;
  #4 rgb = 12'hF0E;
  #4 rgb = 12'hE0F;
  #4 rgb = 12'hF0D;
  #4 rgb = 12'hD0F;
  #4 rgb = 12'hF0F;
  #4 rgb = 12'hF1F;
  #4 rgb = 12'hF0F;
  #4 rgb = 12'hFEF;
  #4 rgb = 12'hF0E;
  #4 rgb = 12'hD0F;
  #4 rgb = 12'hDAF;
  #4 rgb = 12'hDBF;
  #4 rgb = 12'h302;
  #4 rgb = 12'h325;
  #4 rgb = 12'h7FF;
  #4 rgb = 12'h56F;
  #4 rgb = 12'hD0D;
  #4 rgb = 12'h80F;
  #4 rgb = 12'h90F;
  #4 rgb = 12'hD8F;
  #4 rgb = 12'hD7F;
  #4 rgb = 12'h60F;
  #4 rgb = 12'hD07;

  #2300 $finish();
end

endmodule
