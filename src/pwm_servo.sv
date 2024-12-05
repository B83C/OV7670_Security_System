`timescale 1ns/1ps

module pwm_servo #(
  CNTR_WIDTH = $clog2(2048)
) (
  input en, 
  input clk,
  input [CNTR_WIDTH - 1:0] cntr, 
  input [$clog2(256) - 1:0] deg, 
  output logic signal
); 

  always_ff @(posedge clk) begin
    if (en) begin
      if (cntr == 0) begin
        signal <= 1;
      end else if (cntr == CNTR_WIDTH'(deg) + 50) begin
        signal <= 0;
      end
    end else begin
      signal <= 0;
    end
  end

endmodule
