`timescale 1ns/1ps
module qoi_rgb444_encoder #(
)(
    input clk,
    input en,
    input rst_n,
    input [11:0] rgb,
    output [320 - 1:0][7:0] output_stream,
    output [63:0][11:0] rgbstack,
    output logic capped
);

logic [320 - 1:0][7:0] stream ;
assign output_stream = stream;

logic [$clog2(320) - 1:0] stream_ind;
    
logic [5:0] hashmap [4096 - 1:0];
logic [63:0][11:0] stack;
logic [5:0] stack_ind;
assign rgbstack = stack;

logic [11:0] last_rgb;

logic [5:0] rcntr;

wire [3:0] r,g,b;
wire [4:0] dr,dg,db;

assign r = rgb[11:8];
assign g = rgb[7:4];
assign b = rgb[3:0];

assign dr = last_rgb[11:8] - rgb[11:8] + 2;
assign dg = last_rgb[7:4] - rgb[7:4] + 2;
assign db = last_rgb[3:0] - rgb[3:0] + 2;

always @(posedge clk) begin
    if (!rst_n) begin
        // hashmap <= '{default:0};
        stream_ind <= 0;
        stream <= '{default:0};
        last_rgb <= 0;
        rcntr <= 1;
        capped <= 0;
    end else 
    if (en && capped == 0) begin
        if (stream_ind == 320 - 1) begin
            capped <= 1;
        end else begin
            stream_ind <= stream_ind + 1;
        end
        last_rgb <= rgb;
        rcntr <= 1;
        if (last_rgb == rgb || (dr + dg + db) <= 1) begin
            last_rgb <= last_rgb;
            if (rcntr > 1) begin
                stream_ind <= stream_ind;
                stream[stream_ind - 1 == 0? 0:stream_ind - 1] <= {2'b11, rcntr};
            end else begin
                stream[stream_ind] <= {2'b11, rcntr};
            end
            if (rcntr != 6'(64 - 1)) begin
                rcntr <= rcntr + 1;
            end        
        end else if (stack[hashmap[rgb]] == rgb) begin
            stream[stream_ind] <= {2'b00, hashmap[rgb]};
        end else if ({dr[4:2], dg[4:2], db[4:2]} == 9'd0) begin
            stream[stream_ind] <= {2'b01, dr[1:0], dg[1:0], db[1:0]};
        end else if (stack[hashmap[rgb]] != rgb && stack_ind < 6'(64 - 1) ) begin
            stream[stream_ind] <= {2'b00, stack_ind};
            stack_ind <= stack_ind + 1;
            stack[stack_ind] <= rgb;
            hashmap[rgb] <= stack_ind;
        end else if (stream_ind != 320 - 1) begin
            stream[stream_ind] <= {2'b10, 2'b0, r};
            stream[stream_ind + 1] <= {g, b};
            stream_ind <= stream_ind + 2;
        end
    end
end

endmodule
