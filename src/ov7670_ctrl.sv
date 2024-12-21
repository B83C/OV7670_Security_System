`timescale 1ns/1ps

`include "defs.svh"

module ov7670_ctrl #(
  parameter I2C_SCL_FREQ = 100_000,
  parameter I2C_CLK_FREQ = 100_000_000
)(
  input clk, clk_25,
  inout sda, scl,
  input reset_n,
  input command_t cmd,
  output reg xclk,
  output reg pwdn, rst,
  output camera_state sys_state
);

logic start_timer;
logic[1:0] timer_counts = 1;
logic timer_done;
timer #(.GRANULARITY(1_000_000), .COUNTS_MAX(2)) delay (.clk(clk), .start(start_timer), .counts(timer_counts), .done(timer_done));

assign pwdn = 0;

typedef struct {
  logic rst_n, start, halt, rw;
  logic [2:0] ind;
  logic [7:0] mosi;
} i2c_subsystem;

i2c_subsystem im;
i2c_state_t state;
data_state_t dstate;
wire [7:0] miso;
wire rw_done;
wire [1:0] ack;

// logic rw_reg;
// logic i2c_op;

i2c_m #(.SCL_FREQ(I2C_SCL_FREQ), .CLK_FREQ(I2C_CLK_FREQ)) i2c_master  (.clk(clk), .reset_n(im.rst_n), .start(im.start), .halt(im.halt), .mosi(im.mosi), .rw(im.rw), .state(state), .miso(miso), .rw_done(rw_done), .ack(ack), .sda(sda), .scl(scl));

logic inc_cmd_indx, rst_n_cmd_indx;
logic [15:0] icmd;
wire [15:0] bcmd;
ov7670_startup_cmds cmds(.clk(clk), .inc(inc_cmd_indx), .rst_n(rst_n_cmd_indx), .cmd(bcmd));

assign xclk = clk_25;

always_ff @(posedge clk) begin
  if (!reset_n) begin
    rst_n_cmd_indx <= 0;
    rst <= 0;
    im.rst_n <= 0;
  end else begin
    im.start <= 0;
    im.rst_n <= 1;
    start_timer <= 0;
    inc_cmd_indx <= 0;
    rst_n_cmd_indx <= 1;
    rst <= 1;
  end
  case (sys_state)
    I2C_IDLE:  begin
      if(bcmd != 16'hFFFF) begin
        if (bcmd == 16'hFFF0) begin
          start_timer <= 1;
          if (timer_done) begin
            inc_cmd_indx <= 1;
            start_timer <= 0;
          end
        end else begin
          inc_cmd_indx <= 1;
          icmd <= bcmd;
          sys_state <= I2C_READY;
        end
      end else if (cmd.send) begin 
        icmd <= cmd.command;
        sys_state <= I2C_READY;
      end else begin
        im.halt <= 1;
      end
    end
    I2C_READY:  begin
      if(state == IDLE) begin
        im.rst_n <= 1;
        im.halt <= 0;

        im.start <= 1;
        im.rw <= 0;
        dstate <= WRITE_DEV_ADDR;
        im.mosi <= {8'h42};
        sys_state <= SEND_COMMANDS;
      end
    end
    SEND_COMMANDS: begin
      case(dstate) 
        WRITE_DEV_ADDR:  begin
          if(rw_done) begin
            im.rw <= 0;
            im.mosi <= icmd[15:8];
            dstate <= WRITE_REG_ADDR;
            im.halt <= 0;
          end
        end
        WRITE_REG_ADDR:  begin
          if(rw_done) begin
            im.halt <= 0;
            im.rw <= 0;
            im.mosi <= icmd[7:0];
            dstate <= WRITE_REG_DATA;
          end
        end
        WRITE_REG_DATA:  begin
          if(rw_done) begin
            im.rw <= 0;
            sys_state <= COMMAND_DONE;
            im.halt <= 1;
          end
        end
        READ_REG_DATA:  begin
          sys_state <= I2C_IDLE; //TODO: Add read feature
        end
      endcase
    end
    COMMAND_DONE: begin
      sys_state <= I2C_IDLE;
    end
    default: begin
      sys_state <= I2C_IDLE;
    end
  endcase
end
endmodule
