module debouncer
(
  input div_clk,
  input btn,
  output logic btn_latched
);

wire Q0, Q1;
dff d0 (.clk(div_clk), .D(btn), .Q(Q0), .nrst(1));
dff d1 (.clk(div_clk), .D(Q0), .Q(Q1), .nrst(1));

assign btn_latched = Q0 & ~Q1;

endmodule
