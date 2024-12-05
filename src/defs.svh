`ifndef DEFS_H
`define DEFS_H
// package defs;
  typedef enum logic[2:0]
  {
    IDLE,
    START,
    WRITE,
    CHECK_ACK,
    READ,
    SEND_ACK,
    STOP,
    STOP_EXIT
  } i2c_state_t;

  typedef enum logic [1:0] {
    WRITE_DEV_ADDR,
    WRITE_REG_ADDR,
    WRITE_REG_DATA,
    READ_REG_DATA
  } data_state_t;

  typedef enum  logic [1:0]{
    I2C_IDLE,
    I2C_READY,
    SEND_COMMANDS, 
    COMMAND_DONE
  } camera_state;

  typedef struct {
    logic send;
    logic [15:0] command;
  } command_t;

// endpackage
`endif
