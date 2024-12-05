`timescale 1ns/1ps

`include "defs.svh"
// import defs::*;

  // typedef enum logic[2:0]
  // {
  //   IDLE = 0,
  //   START = 1,
  //   WRITE = 2,
  //   CHECK_ACK = 3,
  //   READ = 4,
  //   SEND_ACK = 5,
  //   STOP = 6,
  //   STOP_EXIT = 7
  // } i2c_state_t;

  // typedef enum logic [1:0] {
  //   WRITE_DEV_ADDR = 0,
  //   WRITE_REG_ADDR = 1,
  //   WRITE_REG_DATA = 2,
  //   READ_REG_DATA = 3
  // } data_i2c_state_t;

module i2c_m  #(
  parameter SCL_FREQ = 100_000,
  parameter CLK_FREQ = 100_000_000
) (
  input clk,
  input reset_n,
  input start, halt,

  input rw,
  output reg rw_done,
  output reg [1:0]ack,

  input [7:0] mosi,
  output reg [7:0] miso,

  output i2c_state_t state,

  inout sda,
  inout scl
);

`include "defs.svh"

typedef struct {
  i2c_state_t state;
  reg scl;
  reg sda;
  logic[3:0] ind;
} system_state;

system_state ss, nss;

reg scl_hm, scl_lm;

localparam COUNTER_FULL = CLK_FREQ / (2 * SCL_FREQ);
localparam COUNTER_HALF = COUNTER_FULL / 2;
localparam COUNTER_WIDTH = $clog2(COUNTER_FULL);
reg [COUNTER_WIDTH:0] counter = 0;

// logic [3:0] ind;

assign sda = ss.sda? 1'bz: 0;
assign scl = ss.scl? 1'bz: 0;

assign scl_hm = ss.scl && counter == COUNTER_HALF[COUNTER_WIDTH:0] && scl == 1; //When scl is low then the clock is being stretched
assign scl_lm = ss.scl == 0 && counter == COUNTER_HALF[COUNTER_WIDTH:0];
assign state = ss.state;

always_latch begin
  nss = ss;
  rw_done = 0;
  casez ({ss.state, scl_hm, scl_lm}) 
    {IDLE,2'b??}: begin
      nss.sda = 1;
      if(start) begin
        nss.state = START;
      end
    end
    {START,2'b1?}: begin
      nss.sda = 0;
      nss.ind = 8;
      nss.state = WRITE;
    end
    {WRITE,2'b?1}: begin
      if(ss.ind == 0) begin
        ack = 0;
        nss.sda = 1;
        nss.state = CHECK_ACK;
        rw_done = 1;
      end else begin
        nss.sda = mosi[ss.ind - 1];
        nss.ind = ss.ind - 1;
      end
    end
    {CHECK_ACK, 2'b??}: begin
      if(scl_hm) begin
        ack[1] = 1;
        ack[0] = !sda;
      end else if(scl_lm) begin
        if(!halt) begin
          if(rw) begin
            nss.ind = 7;
            nss.state = READ;
          end else begin
            nss.ind = 8;
            nss.state = WRITE;
          end
        end else begin
          nss.state = STOP;
        end
      end
    end
    {READ, 2'b1?}: begin
      miso[ss.ind[2:0]] = sda;
      nss.ind = ss.ind - 1;
      if(ss.ind == 0) begin
        rw_done = 1;
        nss.state = SEND_ACK;
      end    
    end
    {SEND_ACK, 2'b?1}: begin
      nss.sda = 0;
      if(ss.sda == 0) begin
        if(halt) nss.state = STOP;
        else if(rw) nss.state = READ;
        else nss.state = WRITE;
      end
    end
    {STOP, 2'b?1}: begin
      ack = 2'b0;
      nss.sda = 0;
      nss.state = STOP_EXIT;
    end
    {STOP_EXIT, 2'b1?}: begin
      nss.sda = 1;
      nss.state = IDLE;
    end
    default: begin
    end
  endcase
end 

always_ff @(posedge clk, negedge reset_n) begin
  if (!reset_n) begin
    ss <= '{
      state: IDLE,
      scl: 1,
      sda: 1,
      ind: 0
    };
  end else begin
    ss <= nss;
    if (counter == COUNTER_FULL[COUNTER_WIDTH:0]- 1) begin
      counter <= 0;
      ss.scl <= ~nss.scl;
      if (nss.ind == 8) begin
        ss.scl <= 0;
      end
    end else begin
      counter <= counter + 1;
    end
    if(state == IDLE || state == START) begin
      ss.scl <= 1;
    end
  end
end

endmodule
