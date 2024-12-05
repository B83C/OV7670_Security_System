`timescale 1ns/1ps
module qoi_rgb444_encoder #(
)(
    input clk,
    input en,
    input rst_n,
    input [11:0] rgb,
    //Debug purposes
    output [$clog2(640) - 1:0] ind,
    // output logic [7:0] stream_dbg[9: 0],
    output [5:0] sind
);

logic [7:0] output_stream[640 - 1: 0];
logic [$clog2(640) - 1:0] output_ind;
assign ind = output_ind;
// assign stream_dbg = (output_ind > 10)? output_stream[output_ind +: 10]: output_stream[9:0];

logic [11:0] stack [63:0];
logic [5:0] stack_ind;
assign sind = stack_ind;
logic [11:0] last_rgb;
logic [11:0] drgb;

wire [3:0] r,g,b;

assign r = rgb[11:8];
assign g = rgb[7:4];
assign b = rgb[3:0];

always_latch begin
    if (!rst_n) begin
        stack_ind = 0;
        drgb = 0;
    end else
    if (en) begin
        stack_ind = r * 3 + g * 5 + b * 7;
        drgb[11:8] = last_rgb[11:8] - rgb[11:8] + 2;
        drgb[7:4] = last_rgb[7:4] - rgb[7:4] + 2;
        drgb[3:0] = last_rgb[3:0] - rgb[3:0] + 2;
    end
    else begin
        stack_ind = stack_ind;
        drgb = drgb;
    end 
end

// assign stream_dbg = output_stream[0 +: 10];

always @(posedge clk) begin
    if (!rst_n) begin
        output_stream <= '{default:0};
        output_ind <= 0;

        stack <= '{default:0};
        last_rgb <= 0;
    end else 
    if (en) begin
        output_ind <= output_ind + 1;
        last_rgb <= rgb;
        if (last_rgb == rgb && output_ind != 0) begin
            output_stream[output_ind] <= {2'b11, 6'b1};
            if (output_stream[output_ind - 1][7:6] == 2'b11) begin
                if ( output_stream[output_ind - 1][5:0] != 6'(64 - 1)) begin
                    output_stream[output_ind - 1] <= output_stream[output_ind - 1] + 1; //TODO handle overflow cases
                    output_ind <= output_ind;
                end
            end        
        end else if (stack[stack_ind] == rgb || stack[stack_ind] == 0) begin
            output_stream[output_ind] <= {2'b00, stack_ind};
            stack[stack_ind] <= rgb;
        end else if (stack[stack_ind + 1] == rgb || stack[stack_ind + 1] == 0) begin
            output_stream[output_ind] <= {2'b00, stack_ind + 6'd1};
            stack[stack_ind + 1] <= rgb;
        end else if (stack[stack_ind + 2] == rgb || stack[stack_ind + 2] == 0) begin
            output_stream[output_ind] <= {2'b00, stack_ind + 6'd2};
            stack[stack_ind + 2] <= rgb;
        end else if (drgb[11:10] == 2'b0 && drgb[7:6] == 2'b0 && drgb[3:2] == 2'b0 ) begin
            output_stream[output_ind] <= {2'b01, drgb[9:8], drgb[5:4], drgb[1:0]};
        end else begin
            output_stream[output_ind] <= {2'b10, 2'b0, r};
            output_stream[output_ind + 1] <= {g, b};
            output_ind <= output_ind + 2;
        end
    end
end

endmodule
