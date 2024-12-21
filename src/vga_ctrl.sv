module vga_ctrl#(
  //1280x1024@60Hz by default
  HSYNC = 1688,
  VSYNC = 1066,
  HDISP = 1280,
  VDISP = 1024,
  HPW = 112,
  VPW = 3,
  HFP = 48,
  VFP = 1
)
(
  input pclk,
  output [$clog2(HDISP):0] x,
  output [$clog2(VDISP):0] y,
  output reg hsync, vsync,
  output active
);

localparam hcntr_bits = $clog2(HSYNC);
localparam vcntr_bits = $clog2(VSYNC);

logic [hcntr_bits:0] hcntr;
logic [vcntr_bits:0] vcntr;

assign active = (hcntr < HDISP) && (vcntr < VDISP);
assign x = ($clog2(HDISP) + 1)'(hcntr);
assign y = ($clog2(VDISP) + 1)'(vcntr);

always @(posedge pclk) begin
  if (hcntr == HSYNC - 1) begin
    hcntr <= 0;
    if (vcntr == VSYNC - 1) begin
      vcntr <= 0;
    end else begin
      vcntr <= vcntr + 1;
    end
  end else begin
    hcntr <= hcntr + 1;
  end
end

always @(posedge pclk) begin
  case (hcntr) inside
    [0: HDISP - 1]: begin
      hsync <= 1;
    end
    [HDISP + HFP - 1 : HDISP + HFP + HPW - 2]: begin
    	hsync <= 0;
    end
    default : begin
      hsync <= 1;
    end
  endcase
  case (vcntr) inside
    [0: VDISP - 1]: begin
      vsync <= 1;
    end
    [VDISP + VFP - 1 : VDISP + VFP + VPW - 2]: begin
    	vsync <= 0;
    end
    default : begin
      vsync <= 1;
  end
  endcase
end
 endmodule
