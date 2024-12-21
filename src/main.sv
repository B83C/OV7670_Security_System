`include "defs.svh"

`timescale 1ns/1ps
module main #(
)
(
    input clk,
    input [7:0] JB,
    output reg [3:0] r, g, b,
    inout logic [7:0] JC,
    input analogp[1:0],
    input analogn[1:0],
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

    logic [6:0] drp_addr = 8'h16;
    logic vp_in, vn_in;
    wire [15:0] data;
    logic [7:0] x_data;
    logic [7:0] y_data;
    logic [7:0] x_data_display0, x_data_display1;
    logic [7:0] y_data_display0, y_data_display1;
    logic enable, ready;

    always @(posedge clk_108) begin
        {x_data_display0, y_data_display0} <= {x_data, y_data};
        {x_data_display1, y_data_display1} <= {x_data_display0, y_data_display0};
    end

    always @(negedge clk_25) begin
        if(ready) begin
            if(drp_addr == 8'h16) begin
                drp_addr <=  8'h1e;
                x_data <= data[15:8];
            end else begin
                drp_addr <=  8'h16;
                y_data <= data[15:8];
            end
        	
        end
    end

    joystick_adc adc(
        .daddr_in(drp_addr), 
        .dclk_in(clk_25), 
        .den_in(enable), 
        .di_in(0), 
        .dwe_in(0), 
        .busy_out(),                    
        .vauxp6(analogp[0]),
        .vauxn6(analogn[0]),
        .vauxp14(analogp[1]),
        .vauxn14(analogn[1]),
        .vn_in(vn_in), 
        .vp_in(vp_in), 
        .alarm_out(), 
        .do_out(data), 
        //.reset_in(),
        .eoc_out(enable),
        .channel_out(),
        .drdy_out(ready)
    );

    generate
        for(i = 0; i < 2; i++) begin
            pwm_servo m0 (.clk(clk_25), .en(1), .cntr(pwm_cntr), .deg(servo_deg[i]), .signal(servo[i]));
        end
    endgenerate

    typedef enum {
        NONE = 0,
        NIGHT_MODE,
        FLIP
    } CMD_STATE;

    logic night_mode = 0;
    logic flip = 0;
    CMD_STATE ss = NONE, nss = NONE;
    always @(posedge clk_108) begin
        clk_cnt <= clk_cnt + 1;
        cmd.send <= 0;
        ss <= nss;
        if (ss == NONE && nss != NONE) begin
            case (nss) 
                NIGHT_MODE: begin
                    night_mode <= ~night_mode;
                    cmd.command <= {8'h3b, {{night_mode}, 7'd0}};
                    cmd.send <= 1;
                end
                FLIP: begin
                    flip <= ~flip ;
                    cmd.command <= {8'h1e, {3'd0, {flip}, 4'd0}};
                    cmd.send <= 1;
                end
                default : begin
                	
                end
            endcase
        end
    end

    always @(posedge div_clk) begin
        nss <= NONE;
        if(buttons[0]) begin
            capture <= ~capture;
        end else if(buttons[1]) begin
            nss <= NIGHT_MODE;
        end else if(buttons[2]) begin
            nss <= FLIP;
        end
        if (x_data < 8'h22 && servo_deg[1] >= 3) begin
        	servo_deg[1] <= servo_deg[1] + (x_data / 16) - 2;
        end else if (x_data > 8'h29 && servo_deg[1] < 200) begin
        	servo_deg[1] <= servo_deg[1] + ((x_data - 8'h29) / 64);
        end
        if (y_data < 8'h22 && servo_deg[0] >= 3) begin
        	servo_deg[0] <= servo_deg[0] + (y_data / 16) - 2;
        end else if (y_data > 8'h29 && servo_deg[0] < 200) begin
        	servo_deg[0] <= servo_deg[0] + ((y_data - 8'h29) / 64);
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

    logic [1024/(C_H*SCALE_Y) - 1: 0][1280/(C_W*SCALE_X) - 1: 0][7:0] text_buffer;

    logic [$clog2(C_W) - 1: 0] x_cntr = 0;
    logic [$clog2(C_H) - 1: 0] y_cntr = 0;
    logic [$clog2(HCC) - 1: 0] c_x = 0;
    logic [$clog2(VCC) - 1: 0] c_y = 0;
    logic [$clog2(256)- 1:0] character_addr = text_buffer[0][0];
    wire [$clog2(96)- 1:0] ascii_addr;
    // assign ascii_addr = character_addr[6:0] < 32? 0: (character_addr[6:0] - 32) & (128 - 1); //Address space compression
    wire [C_H - 1 : 0][C_W - 1 : 0] char_buf;
    ram #(.WIDTH(C_W*C_H), .DEPTH(128), .binaryFile("ascii.rom")) ascii (.addr(character_addr[6:0]), .data(char_buf));
    // rom #(.WIDTH(C_W*C_H), .DEPTH(96), .binaryFile("ascii.rom"), .RISING_EDGE(1)) ascii (.addr(ascii_addr), .data(char_buf), .clk(clk_108));

    logic enable_buffer_a;
    logic write_to_buffer = 0;
    logic [0:0]wea = 0;
    logic [$clog2(480) - 1:0] addra = 0;
    logic [320- 1:0][7:0] wcfb;
    logic [64 - 1: 0][11:0] wrgbs;

    logic enb = 0;
    logic [$clog2(480) - 1:0] addrb = 0;
    logic [320- 1:0][7:0] rcfb;
    logic [64 - 1: 0][11:0] rrgbs;

    logic rst_dec = 1;
    logic [12 - 1:0] dec_rgb;
    wire dec_done;

    wire [$clog2(1280):0] x;
    wire [$clog2(1024):0] y;
    wire vga_active;
    logic dec_en;

    wire camera_state cam_state;
    wire pclk, href, vref;
    assign href = JC[2];
    assign vref = JC[6];

    enc_buff fb (.clka(pclk), .ena(enable_buffer_a), .wea(write_to_buffer), .addra(addra), .dina(wcfb), .clkb(clk_108), .enb(enb), .addrb(addrb), .doutb(rcfb));

    rgb_stack rgbstack (.clka(pclk), .ena(enable_buffer_a), .wea(write_to_buffer), .addra(addra), .dina(wrgbs), .clkb(clk_108), .enb(enb), .addrb(addrb), .doutb(rrgbs));

    qoi_rgb444_decoder dd (
        .clk(clk_108),
        .en(dec_en),
        .rst_n(rst_dec),
        .rgbstack(rrgbs),
        .input_stream(rcfb),
        .rgb(dec_rgb),
        .done(dec_done)
    );

    vga_ctrl vga_c (.pclk(clk_108), .x(x), .y(y), .hsync(hsync), .vsync(vsync), .active(vga_active));

    always @(posedge clk_108) begin
        text_buffer[1][41+14 +:1] <= night_mode + "0";
        text_buffer[2][41+14 +:1] <= flip + "0";
        text_buffer[3][41+14 +:2] <= { <<8{hex(x_data_display1[7:4]), hex(x_data_display1[3:0])}};
        text_buffer[4][41+14 +:2] <= { <<8{hex(y_data_display1[7:4]), hex(y_data_display1[3:0])}};
    end

    assign dec_en = vga_active && x < 640 && y < 480;
    // assign character_addr = text_buffer[c_y][c_x];
    always @(posedge clk_108) begin
        {r,g,b} <= 12'b0;
        rst_dec <= 1;
        enb <= 0;
        if (vga_active) begin
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
                if(char_buf[y_cntr][x_cntr]) begin
                    {r,g,b} <= {12{char_buf[y_cntr][x_cntr] ^ character_addr[7]}};
                end
            end             
            if (x < 640 && y < 480) begin
                if (x == 640 - 1) begin
                    addrb <= addrb + 1;
                end
                {r,g,b} <= dec_rgb;
            end else if (x >= 640 && y < 480) begin
                rst_dec <= 0;
                if (x == 640) begin
                    enb <= 1;
                end
            end else if(y >= 480) begin
                addrb <= 0;
            end
        end        
    end


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

    logic [11:0] crgb, p_crgb = 0;
    logic enc_en = 0;
    logic enc_rst_n = 1;

    wire capped;

    qoi_rgb444_encoder enc(.clk(pclk), .en(enc_en), .rst_n(enc_rst_n), .rgb(crgb), .output_stream(wcfb), .rgbstack(wrgbs), .capped(capped));

    function byte hex(logic [3:0] in);
        return {4'b0, in} + ((in < 10)?  "0" :  "A" - 10);
    endfunction

    function logic [7:0] hl(logic [7:0] in);
        return {1'b1, in[6:0]};
    endfunction

    assign enable_buffer_a = 1;

    //Clock slower than ram
    always @(posedge pclk) begin
        wea <= 0;
        write_to_buffer <= 0;
        enc_rst_n <= 1;
        case(state)
            WAIT_FRAME_START: begin
                if(capture) begin
                    state <= (!vref) ? ROW_CAPTURE: WAIT_FRAME_START;
                    addra <= 0;
                    pixel_half <= 0;
                    enc_rst_n <= 0;
                end
            end
            ROW_CAPTURE: begin
                state <= (!vref) ? ROW_CAPTURE: WAIT_FRAME_START;
                if(href) begin
                    pixel_half <= ~pixel_half;
                    if (!pixel_half) begin
                        crgb[11:4] <= D;
                        enc_en <= 0;
                    end else begin
                        crgb[3:0] <= D[7:4];
                        p_crgb <= crgb;
                        wea <= 1;
                        enc_en <= 1;
                    end
                end else begin
                    enc_en <= 0;
                    crgb <= 0;
                    p_crgb <= 0;
                    if (enc_en) begin
                        addra <= addra + 1;
                        write_to_buffer <= 1;
                    end else if (!enc_en && write_to_buffer == 0) begin
                        enc_rst_n <= 0;
                    end
                end
            end
            STOP: begin
            end
        endcase
    end

    initial begin
        counter = 0;
        text_buffer[1][41+:12] = { <<8{"Night Mode:"}};
        text_buffer[2][41+:12] = { <<8{"Image Flip:"}};
        text_buffer[3][41+:12] = { <<8{"Joystick X :"}};
        text_buffer[4][41+:12] = { <<8{"Joystick Y :"}};
    end
endmodule
