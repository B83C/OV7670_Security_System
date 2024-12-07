vivado := "/home/b83c/tools/Xilinx/Vivado/2024.1/bin/vivado"

sim testbench="tb3" show_wave="y":
    mkdir -p sim
    @echo "Compiling Verilog file..."
    cd sim; verilator --binary -j 16  --build {{testbench}}.sv --trace-fst -I../src/ -I../src/tb/ --timing --trace-max-array 700 --Mdir obj_{{testbench}}
    @echo "Running simulation..."
    cd sim; ./obj_{{testbench}}/V{{testbench}}
    @echo "Simulation complete. Run 'just wave' to view the waveform."
    if {{ if show_wave == "y" { "true" } else { "false" } }}; then \
        echo "Opening GTKWave..." \
        cd sim && gtkwave sim/waveform.fst ; \
    fi
# wave: sim

build:
     {{ vivado }} -nolog -nojournal -mode batch -source  build.tcl 

cmd:
     {{ vivado }} -nolog -nojournal -mode tcl -source  init.tcl 

update_ip:
     {{ vivado }} -nolog -nojournal -mode tcl -source  update_ip.tcl 

# /home/b83c/tools/Xilinx/Vivado/2024.1/bin/vivado -nolog -nojournal -mode batch -notrace -quiet -source  build.tcl 

upload: 
    openFPGALoader -b basys3 ./target/out/BASYS3.bit
    
