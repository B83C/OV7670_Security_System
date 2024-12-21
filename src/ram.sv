`timescale 1ns/1ps

module ram #(
	WIDTH = 16,
	DEPTH = 8,
	binaryFile = "rom",
	localparam ADDR_BITS= $clog2(DEPTH)
)(
	input [ADDR_BITS - 1:0] addr,
	output logic [WIDTH - 1:0] data
);
	logic [WIDTH-1:0] irom[DEPTH - 1: 0];
	initial begin
		$readmemh(binaryFile, irom);
  end

	assign data = irom[addr];
endmodule
