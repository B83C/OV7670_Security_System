module timer #(
  GRANULARITY=1_000_000, //10ms
  COUNTS_MAX=1024,
  localparam COUNTS_LENGTH=$clog2(COUNTS_MAX)
) (
  input clk,
  input start,
  input [COUNTS_LENGTH:0] counts,
  output logic done
);

typedef enum {
  IDLE,
  COUNTING
} state_t;

logic [COUNTS_LENGTH:0] counts_internal = counts;
logic [$clog2(GRANULARITY): 0] counter = GRANULARITY;

state_t state;

always @(posedge clk) begin
  done <= 0;
  case(state) 
    IDLE: begin
      if(start) begin
        state <= COUNTING;
      end
    end
    COUNTING: begin
      counter <= counter - 1;
      if (counter == 0) begin
        counter <= GRANULARITY;
        counts_internal <= counts_internal - 1;
        if (counts_internal == 0) begin
          counts_internal <= counts;
          done <= 1;
          state <= IDLE;
        end
      end
    end
  endcase
end

endmodule
