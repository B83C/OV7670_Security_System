`timescale 1ns/1ps

module tb3;

logic clk = 0;

always #1 clk = ~clk;

logic ph = 0;
logic [11:0] rgb;
logic enc_en = 1;
logic enc_rst_n = 1;

logic [7:0] input_stream [320 - 1:0] = '{default:0};
logic [11:0] rgbstack [63:0] = '{default:0};

logic [$clog2(64) - 1:0] stack_ind;
logic [$clog2(320) - 1:0] stream_ind;
logic done;

qoi_rgb444_decoder enc(.clk(clk), .en(enc_en), .rst_n(enc_rst_n), .rgb(rgb), .input_stream({input_stream[stream_ind], input_stream[stream_ind + 1]}), .rgbstack(rgbstack[stack_ind]), .done(done), .stack_ind(stack_ind), .stream_ind(stream_ind));

always @(posedge clk) begin
  ph <= ~ph;
  if (!ph) begin
    enc_en <= 0;
  end else begin
    enc_en <= 1;
  end
end

initial begin
  input_stream[0] = 8'hc2;
  input_stream[1] = 8'h00;
  input_stream[2] = 8'h01;
  input_stream[3] = 8'hc3;
  input_stream[4] = 8'h02;
  input_stream[5] = 8'h03;
  input_stream[6] = 8'h02;
  input_stream[7] = 8'h01;
  input_stream[8] = 8'h02;
  input_stream[9] = 8'h6B;
  input_stream[10] = 8'h79;
  input_stream[11] = 8'h04;
  input_stream[12] = 8'h05;
  input_stream[13] = 8'h02;
  input_stream[14] = 8'h66;
  input_stream[15] = 8'h02;
  input_stream[16] = 8'h06;
  input_stream[17] = 8'h07;
  input_stream[18] = 8'h05;
  input_stream[19] = 8'h08;
  input_stream[20] = 8'h66;
  input_stream[21] = 8'h09;
  input_stream[22] = 8'h0A;
  input_stream[23] = 8'h0B;
  input_stream[24] = 8'h0C;
  input_stream[25] = 8'h0D;
  input_stream[26] = 8'h0E;
  input_stream[27] = 8'h5A;
  input_stream[28] = 8'h0F;
  input_stream[29] = 8'h6E;
  input_stream[30] = 8'h10;
  input_stream[31] = 8'h11;
  input_stream[32] = {2'b10, 2'b00, 4'hf};
  input_stream[33] = {4'h7, 4'h2};
  input_stream[34] = 8'h00;

  rgbstack[0] = 12'hFFF;
  rgbstack[1] = 12'hFF0;
  rgbstack[2] = 12'hF0F;
  rgbstack[3] = 12'h0FF;
  rgbstack[4] = 12'hFED;
  rgbstack[5] = 12'hD0F;
  rgbstack[6] = 12'hFEF;
  rgbstack[7] = 12'hF0E;
  rgbstack[8] = 12'hDAF;
  rgbstack[9] = 12'h302;
  rgbstack[10] = 12'h325;
  rgbstack[11] = 12'h7FF;
  rgbstack[12] = 12'h56F;
  rgbstack[13] = 12'hBEB;
  rgbstack[14] = 12'h80F;
  rgbstack[15] = 12'hD8F;
  rgbstack[16] = 12'h60F;
  rgbstack[17] = 12'hBE7;
  // rgbstack[17] = 12'h000;
  $dumpfile("waveform.fst");
  $dumpvars(0, tb2);
  #2 enc_rst_n = 0;
  #2 enc_rst_n = 1;
  // #7 rgb = 12'hFFF;
  // #4 rgb = 12'hFF0;
  // #16 rgb = 12'hF0F;
  // #4 rgb = 12'h0FF;
  // #4 rgb = 12'hF0F;
  // #4 rgb = 12'hFF0;
  // #4 rgb = 12'hF0F;
  // #4 rgb = 12'hF0E;
  // #4 rgb = 12'hE0F;
  // #4 rgb = 12'hF0D;
  // #4 rgb = 12'hD0F;
  // #4 rgb = 12'hF0F;
  // #4 rgb = 12'hF1F;
  // #4 rgb = 12'hF0F;
  // #4 rgb = 12'hFEF;
  // #4 rgb = 12'hF0E;
  // #4 rgb = 12'hD0F;
  // #4 rgb = 12'hDAF;
  // #4 rgb = 12'hDBF;
  // #4 rgb = 12'h302;
  // #4 rgb = 12'h325;
  // #4 rgb = 12'h7FF;
  // #4 rgb = 12'h56F;
  // #4 rgb = 12'hD0D;
  // #4 rgb = 12'h80F;
  // #4 rgb = 12'h90F;
  // #4 rgb = 12'hD8F;
  // #4 rgb = 12'hD7F;
  // #4 rgb = 12'h60F;
  // #4 rgb = 12'hD07;

  #2300 $finish();
end

endmodule
