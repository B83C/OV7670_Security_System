onbreak {quit -f}
onerror {quit -f}

vsim  -lib xil_defaultlib enc_buff_opt

set NumericStdNoWarnings 1
set StdArithNoWarnings 1

do {wave.do}

view wave
view structure
view signals

do {enc_buff.udo}

run 1000ns

quit -force
