`timescale 1ns/1ps

module tb2;

logic clk = 0;

always #1 clk = ~clk;

logic ph = 0;
logic [11:0] rgb;
logic enc_en = 1;
logic enc_rst_n = 1;
wire [$clog2(640) - 1:0] enc_ind;
wire [5:0] enc_sind;
// wire [7:0] stream_dbg[9: 0];

qoi_rgb444_encoder enc(.clk(clk), .en(enc_en), .rst_n(enc_rst_n), .rgb(rgb), .ind(enc_ind), .sind(enc_sind));

always @(posedge clk) begin
  ph <= ~ph;
  if (!ph) begin
    enc_en <= 0;
  end else begin
    enc_en <= 1;
  end
end

initial begin
  $dumpfile("waveform.vcd");
  $dumpvars(0, tb2);
  #2 enc_rst_n = 0;
  #2 enc_rst_n = 1;
  #7 rgb = 12'hFFF;
  // #4 rgb = 12'hFF0;
  // #16 rgb = 12'hF0F;
  // #4 rgb = 12'h0FF;
  // #4 rgb = 12'hF0F;
  // #4 rgb = 12'hFF0;
  // #4 rgb = 12'hF0F;

  #3000 $finish();
end

endmodule
