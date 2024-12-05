module dff(
  input clk, 
  input D,
  input nrst,
  output reg Q
);
  always @(posedge clk, negedge nrst) begin
    if(!nrst) begin
      Q <= 0;
    end else begin
      Q <= D;
    end
  end
endmodule
