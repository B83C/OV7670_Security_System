set shell := ["/sbin/nu", "-c"]

vivado := "/home/b83c/tools/Xilinx/Vivado/2024.2/bin/vivado"

sim testbench="tb" show_wave="n":
    mkdir sim
    @echo "Compiling Verilog file..."
    cd sim; verilator --binary -j 16  --build {{testbench}}.sv --trace-fst  -I../src/tb/ -I../src/ --timing --trace-max-array 700 --Mdir ./obj_{{testbench}}
    @echo "Running simulation..."
    cd sim; ./obj_{{testbench}}/V{{testbench}}
    @echo "Simulation complete. Run 'just wave' to view the waveform."
    if {{ if show_wave == "y" { "true" } else { "false" } }}  {  \
        if (ps | where { $in.name | str contains gtkwave } | is-empty) { cd sim; gtkwave waveform.fst; } \
    }

build:
     {{ vivado }} -nolog -nojournal -mode batch -source  build.tcl 

cmd:
     {{ vivado }} -nolog -nojournal -mode tcl -source  init.tcl 

update_ip:
     {{ vivado }} -nolog -nojournal -mode tcl -source  update_ip.tcl 

zig:
    zig build

# /home/b83c/tools/Xilinx/Vivado/2024.1/bin/vivado -nolog -nojournal -mode batch -notrace -quiet -source  build.tcl 

upload: 
    openFPGALoader -b basys3 ./target/out/BASYS3.bit
    
