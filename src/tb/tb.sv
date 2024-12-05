`timescale 1ns/1ps

// `include "../defs.svh"

module tb;

    reg clk;
    always #1 clk = ~clk;

    logic [7:0] JB;
    logic [7:0] JC;
    logic start;

    ov7670 #(.I2C_CLK_FREQ(1_000_000_000), .I2C_SCL_FREQ(40_000_000)) cam (.clk(clk), .plk(JC[0]), .D(JB), .vsync(JC[1]), .hsync(JC[2]), .sda(JC[3]), .scl(JC[4]), .xclk(JC[5]), .pwdn(JC[6]), .rst(JC[7]), .start(start));

    always begin
    end

    initial begin
        $dumpfile("waveform.vcd");
        $dumpvars(0, tb);
        clk = 0;
        #20 start = 1;
        #10000 $finish();
    end
endmodule  
