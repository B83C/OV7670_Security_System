`timescale 1ns/1ps
module qoi_rgb444_decoder #(
)(
    input clk,
    input en,
    input rst_n,
    input [320 - 1:0][7:0] input_stream,
    input [63:0][11:0] rgbstack,
    output logic [11:0] rgb,
    output logic done
);

(* dont_touch = "yes" *) logic [$clog2(64) - 1:0] icntr = 0;
logic [$clog2(320) - 1:0] stream_ind = 0;
// wire [$clog2(64) - 1:0] cntr;
// logic [$clog2(64) - 1:0] stack_ind;

assign done = stream_ind == 320;

(* dont_touch = "yes" *) logic [7:0] current_input;
(* dont_touch = "yes" *) assign current_input = input_stream[stream_ind];

always @(posedge clk, negedge rst_n) begin
    if (!rst_n) begin
        stream_ind <= 0;
        icntr <= 0;
        rgb <= 0;
    end else if (en) begin
        case(input_stream[stream_ind][7:6]) 
            2'b00: begin
                rgb <= rgbstack[input_stream[stream_ind][5:0]];
                stream_ind <= stream_ind + 1;
            end
            2'b01: begin
                rgb[11:8] <= rgb[11:8] - {2'b0, input_stream[stream_ind][5:4]} + 4'd2;
                rgb[7:4] <= rgb[7:4] - {2'b0, input_stream[stream_ind][3:2]} + 4'd2;
                rgb[3:0] <= rgb[3:0] - {2'b0, input_stream[stream_ind][1:0]} + 4'd2;
                stream_ind <= stream_ind + 1;
            end
            2'b10: begin
                rgb <= {input_stream[stream_ind + 0][3:0], input_stream[stream_ind + 1][7:4], input_stream[stream_ind + 1][3:0]};
                stream_ind <= stream_ind + 2;
            end
            2'b11: begin
                icntr <= icntr + 1;
                if (icntr == input_stream[stream_ind][5:0] - 1) begin
                    stream_ind <= stream_ind + 1;
                    icntr <= 0;
                end            
            end
        endcase
    end
end

endmodule
