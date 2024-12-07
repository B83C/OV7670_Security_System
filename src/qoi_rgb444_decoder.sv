`timescale 1ns/1ps
module qoi_rgb444_decoder #(
)(
    input clk,
    input en,
    input rst_n,
    input [11:0] rgbstack,
    input [15:0] input_stream, //Reading two bytes at once
    output logic [11:0] rgb,
    output [$clog2(64) - 1:0] stack_ind,
    output logic [$clog2(320) - 1:0] stream_ind,
    output logic done
);

logic [$clog2(64) - 1:0] icntr;
wire [3:0] r,g,b;
wire [3:0] dr,dg,db;
wire [$clog2(64) - 1:0] cntr;


assign r = input_stream[11:8];
assign g = input_stream[7:4];
assign b = input_stream[3:0];

assign dr = {2'b0, input_stream[8+5:8+4]};
assign dg = {2'b0, input_stream[8+3:8+2]};
assign db = {2'b0, input_stream[8+1:8+0]};

assign stack_ind = input_stream[8+5:8+0];
assign cntr = stack_ind;
assign done = stream_ind == 320;

// always @(negedge clk) begin
//     if (!rst_n || done) begin
//         last_rgb <= 0;
//         stream_ind <= 0;
//     end 
// end

always @(posedge clk) begin
    if (!rst_n) begin
        stream_ind <= 0;
        icntr <= 0;
    end else 
    if (en) begin
        case(input_stream[8+7:8+6]) 
            2'b00: begin
                rgb <= rgbstack;
                stream_ind <= stream_ind + 1;
            end
            2'b01: begin
                rgb[11:8] <= rgb[11:8] - dr + 4'd2;
                rgb[7:4] <= rgb[7:4] - dg + 4'd2;
                rgb[3:0] <= rgb[3:0] - db + 4'd2;
                stream_ind <= stream_ind + 1;
            end
            2'b10: begin
                rgb <= {r,g,b};
                stream_ind <= stream_ind + 2;
            end
            2'b11: begin
                if (icntr != 0) begin
                    icntr <= icntr - 1;
                    if (icntr == 1) begin
                        stream_ind <= stream_ind + 1;
                    end
                end else begin
                    icntr <= cntr - 1;
                end
            end
        endcase
    end
end

endmodule
