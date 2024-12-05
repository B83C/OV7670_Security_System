// %include ips/c
`include "defs.svh"

`timescale 1ns/1ps
module main #(
)
(
    input clk,
    input [7:0] JB,
    output reg [3:0] r, g, b,
    inout reg [7:0] JC,
    output reg [1:0] servo,
    input [4:0] btn,
    output reg [7:0] led,
    // output [7:4] JC,
    output reg hsync, vsync
);
    wire clk_108, clk_25, clk_100;
    command_t cmd = '{send : 0, default:0};
    reg reset_cam_n = 1, capture = 1;

    logic [31:0] clk_cnt;
    
    wire div_clk = clk_cnt[$clog2(1_000_000)];

    logic [4:0] buttons;
    genvar i;
    generate
        for(i = 0; i < 5; i++) begin
            debouncer d0 (div_clk, btn[i], buttons[i]);
        end
    endgenerate

    logic [$clog2(2048) - 1:0] pwm_cntr;
    logic [$clog2(256) - 1:0] div_cntr;
    logic [$clog2(256) - 1:0] servo_deg [1:0];

    always @(posedge clk_25) begin
        div_cntr <= div_cntr + 1;
        if (div_cntr == 250 - 1) begin
            div_cntr <= 0;
            pwm_cntr <= pwm_cntr + 1;
            if (pwm_cntr == 2000 - 1) begin
                pwm_cntr <= 0;
            end
        end
    end

    generate
        for(i = 0; i < 2; i++) begin
            pwm_servo m0 (.clk(clk_25), .en(1), .cntr(pwm_cntr), .deg(servo_deg[i]), .signal(servo[i]));
        end
    endgenerate

    byte test = 0;
    logic ss = 0, nss = 0;
    always @(posedge clk) begin
        clk_cnt <= clk_cnt + 1;
        cmd.send <= 0;
        ss <= nss;
        if (!ss && nss) begin
            cmd.command <= {8'h00, test};
            test <= test + 1;
            cmd.send <= 1;
        end
    end

    always @(posedge div_clk) begin
        nss <= 0;
        if(buttons[0]) begin
            capture <= ~capture;
        end 
        if(buttons[1]) begin
            nss <= 1;
        end
        if(btn[2]) begin
            servo_deg[0] <= servo_deg[0] + 1;
            servo_deg[1] <= servo_deg[1] + 1;
        end
        if(btn[3]) begin
            servo_deg[0] <= servo_deg[0] - 1;
            servo_deg[1] <= servo_deg[1] - 1;
        end
    end

    wire bufclk;

    BUFG clkf_buf
        (.O (clk_100),
        .I (clk));

    clk_mcmm cm(.clk(clk_100), .clk_108(clk_108), .clk_25(clk_25), .reset(1'b0), .locked(1'b0));

    localparam D_OFF_X = 700;
    localparam D_OFF_Y = 20;
    localparam C_W = 8;
    localparam C_H = 8;
    localparam SCALE_X = 2;
    localparam SCALE_Y = 2;

    localparam int HCC = 1280 / (C_W * SCALE_X);
    localparam int VCC = 1024 / (C_H * SCALE_Y);
    localparam int x_bound = HCC * C_W * SCALE_X;
    localparam int y_bound = VCC * C_H * SCALE_Y;

    logic [$clog2(SCALE_X) - 1:0] scale_cntr_x = 0;
    logic [$clog2(SCALE_Y) - 1:0] scale_cntr_y = 0;

    logic [7:0] text_buffer [1024/(C_H*SCALE_Y) - 1: 0][1280/(C_W*SCALE_X) - 1: 0];

    logic [$clog2(C_W) - 1: 0] x_cntr = 0;
    logic [$clog2(C_H) - 1: 0] y_cntr = 0;
    logic [$clog2(HCC) - 1: 0] c_x = 0;
    logic [$clog2(VCC) - 1: 0] c_y = 0;
    logic [$clog2(96)- 1:0] character_addr;
    wire [$clog2(96)- 1:0] ascii_addr;
    assign ascii_addr = character_addr < 32? 0: character_addr - 32; //Address space compression
    wire [C_W*C_H - 1: 0] char_buf;
    wire char_pix [C_H - 1 : 0][C_W - 1 : 0];
    assign char_pix = {>>{char_buf}};
    rom #(.WIDTH(C_W*C_H), .DEPTH(96), .binaryFile("ascii.rom"), .RISING_EDGE(0)) ascii (.addr(ascii_addr), .data(char_buf), .clk(clk_108));


    logic clka /* synthesis syn_isclock = 1 */;
    logic ena = 1;
    logic [0:0]wea = 0;
    logic [16:0]addra = 0;
    logic [11:0]dina = 0;

    logic clkb /* synthesis syn_isclock = 1 */;
    logic enb;
    logic [16:0]addrb = 0;
    logic [11:0]doutb;

    buffer_mem bm (.clka(clk_25), .ena(ena), .wea(wea), .addra(addra), .dina(dina), .clkb(clk_108), .enb(enb), .addrb(addrb), .doutb(doutb));

    // vga vga_u0 (.pclk(clk_108), .r(r), .g(g), .b(b), .hsync(hsync), .vsync(vsync));
    wire [$clog2(1280):0] x;
    wire [$clog2(1024):0] y;
    wire active;
    vga_ctrl vga_c (.pclk(clk_108), .x(x), .y(y), .hsync(hsync), .vsync(vsync), .active(active));

    assign enb = active;
    assign clkb = clk_108;

    always @(posedge clk_108) begin
        {r,g,b} <= 12'b0;
        if (active) begin
            if(x < x_bound && y < y_bound) begin
                scale_cntr_x <= scale_cntr_x + 1;
                if(scale_cntr_x == SCALE_X - 1) begin
                    scale_cntr_x <= 0;
                    x_cntr <= x_cntr + 1;
                    if(x_cntr == C_W - 1) begin
                        x_cntr <= 0;
                        c_x <= c_x + 1;
                        if (c_x == HCC - 1) begin
                            c_x <= 0;
                            scale_cntr_y <= scale_cntr_y + 1;
                            if(scale_cntr_y == SCALE_Y - 1) begin
                                scale_cntr_y <= 0;
                                y_cntr <= y_cntr + 1;
                                if(y_cntr == C_H - 1) begin
                                    y_cntr <= 0;
                                    c_y <= c_y + 1;
                                    if (c_y == VCC - 1) begin
                                        c_y <= 0;
                                        character_addr <= text_buffer[0][0];
                                    end else begin
                                        character_addr <= text_buffer[c_y + 1][0];
                                    end
                                end
                            end else begin
                                character_addr <= text_buffer[c_y][0];
                            end
                        end else begin
                            character_addr <= text_buffer[c_y][c_x + 1];
                        end
                    end 
                end
                {r,g,b} <= {12{char_pix[y_cntr][x_cntr]}};
            end             
            if (x < 640 && y < 480) begin
                if (x[1:0] == 2'b11) begin
                    addrb <= addrb + 1;
                end
                {r,g,b} <= doutb;
            end else if(y >= 480) begin
                addrb <= 0;
            end
        end        
    end

    wire camera_state cam_state;
    wire pclk, href, vref;
    assign href = JC[2];
    assign vref = JC[6];

    wire [7:0] D;

    genvar acc;

    generate 
        for(acc = 0; acc < 8; acc++) begin
            if (acc >= 4) begin
                assign D[2 * acc - 7] = JB[acc];
            end else begin
                assign D[acc * 2] = JB[acc];
            end
        end
    endgenerate

    IBUF ibuf_inst (
        .I(JC[1]),
        .O(pclk)
    );

    ov7670_ctrl cam (.clk(clk_100), .clk_25(clk_25), .sda(JC[3]), .scl(JC[7]), .xclk(JC[5]), .pwdn(JC[0]), .rst(JC[4]), .sys_state(cam_state), .cmd(cmd), .reset_n(reset_cam_n));

    typedef enum {
        WAIT_FRAME_START,
        ROW_CAPTURE,
        STOP
    } state_t;

    state_t state = WAIT_FRAME_START;
    logic pixel_half = 0;
    logic [1:0] counter = 0;

    logic enc_en = 0;
    logic enc_rst_n = 1;
    wire [$clog2(640) - 1:0] enc_ind;
    wire [5:0] enc_sind;

    logic [$clog2(640 * 480) - 1:0] ind_c;
    logic [$clog2(64 * 480) - 1:0] sind_c ;
    logic [$clog2(480) - 1:0] frame_acc_cntr;
    logic [31:0] acc_cntr;
    logic [$clog2(640) - 1:0] ind_avg;
    logic [$clog2(64) - 1:0] sind_avg;

    logic [$clog2(640) : 0] dbg_cntr = 0;

    qoi_rgb444_encoder enc(.clk(pclk), .en(enc_en), .rst_n(enc_rst_n), .rgb(dina), .ind(enc_ind), .sind(enc_sind));

    function byte hex(logic [3:0] in);
        return {4'b0, in} + ((in < 10)?  "0" :  "A" - 10);
    endfunction

    //Clock slower than ram
    always @(posedge pclk) begin
        wea <= 0;
        enc_rst_n <= 1;
        case(state)
            WAIT_FRAME_START: begin
                if(capture) begin
                    state <= (!vref) ? ROW_CAPTURE: WAIT_FRAME_START;
                    addra <= 0;
                    pixel_half <= 0;
                    enc_rst_n <= 0;
                    // frame_acc_cntr <= frame_acc_cntr + 1;
                    text_buffer[3][41+14 +:3] <= { <<8{hex({2'b0, ind_c[9:8]}), hex(ind_c[7:4]), hex(ind_c[3:0])}};
                    text_buffer[4][41+14 +:2] <= { <<8{hex({3'b0, sind_c[4]}), hex(sind_c[3:0])}};
                    // if(frame_acc_cntr == 480 - 1) begin
                        // frame_acc_cntr <= 0;
                        // acc_cntr <= acc_cntr + 1;
                        // if(acc_cntr == 0) begin
                    // ind_avg <= 0;
                    // sind_avg <= 0;
                    // ind_c <= 0;
                    // sind_c <= 0;
                        // end else begin
                        //     ind_avg <=  $clog2(640)'(ind_avg + ((ind_c/480) - ind_avg)/(acc_cntr + 1));
                        //     sind_avg <=  $clog2(64)'( sind_avg + ((sind_c/480) - sind_avg)/(acc_cntr + 1));
                        // end
                    // end                
                end
            end
            ROW_CAPTURE: begin
                state <= (!vref) ? ROW_CAPTURE: WAIT_FRAME_START;
                if(href) begin
                    pixel_half <= ~pixel_half;
                    if (!pixel_half) begin
                        dina[11:4] <= D;
                        counter <= counter + 1;
                        if(counter == 2'b11) begin
                            addra <= addra + 1;
                        end
                        enc_en <= 0;
                    end else begin
                        dina[3:0] <= D[7:4];
                        wea <= 1;
                        enc_en <= 1;
                        dbg_cntr <= dbg_cntr + 1;
                    end
                end else begin
                    counter <= 0;
                    enc_en <= 0;
                    dbg_cntr <= 0;
                    enc_rst_n <= 0;
                    if (dbg_cntr == 640) begin //Test
                        if (enc_ind > ind_c) ind_c <= enc_ind;
                        if (enc_sind > sind_c) sind_c <= enc_sind;
                        // ind_c <= ind_c + enc_ind;
                        // sind_c <= sind_c + enc_sind;
                    end
                end
                if (vref) begin
                    if(buttons[3]) begin
                        ind_c <= 0;
                        sind_c <= 0;
                        // ind_avg <=  ind_c;
                        // sind_avg <=  sind_c;
                        // ind_avg <=  ind_c / 480;
                        // sind_avg <=  sind_c / 480;
                    end                
                end
            end
            STOP: begin
            end
        endcase
    end

    initial begin
        counter = 0;
        text_buffer[1][41+:5] = { <<8{"hello"}};
        text_buffer[2][41+:6] = { <<8{"Servo:"}};
        text_buffer[3][41+:14] = { <<8{"Avg stream sz:"}};
        text_buffer[4][41+:14] = { <<8{"Avg stack cnt:"}};
    end
    // assign JC = {1'b0, 1'b0, hsync, vsync};
endmodule
