# Usage with Vitis IDE:
# In Vitis IDE create a Single Application Debug launch configuration,
# change the debug type to 'Attach to running target' and provide this 
# tcl script in 'Execute Script' option.
# Path of this script: /home/danielito/Escritorio/Vivado_proyect/Vitis_proyect/TP7/MicroBlazerConTrama_system/_ide/scripts/systemdebugger_microblazercontrama_system_standalone.tcl
# 
# 
# Usage with xsct:
# In an external shell use the below command and launch symbol server.
# symbol_server -S -s tcp::1534
# To debug using xsct, launch xsct and run below command
# source /home/danielito/Escritorio/Vivado_proyect/Vitis_proyect/TP7/MicroBlazerConTrama_system/_ide/scripts/systemdebugger_microblazercontrama_system_standalone.tcl
# 
connect -path [list tcp::1534 tcp:localhost:3121]
targets -set -filter {jtag_cable_name =~ "Digilent Arty 210319A288D7A" && level==0 && jtag_device_ctx=="jsn-Arty-210319A288D7A-0362d093-0"}
fpga -file /home/danielito/Escritorio/Vivado_proyect/project_8_MIcroBlazerConTrama/project_8_MIcroBlazer.runs/impl_1/fpga.bit
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent Arty 210319A288D7A" && jtag_device_ctx=="jsn-Arty-210319A288D7A-0362d093-0"}
loadhw -hw /home/danielito/Escritorio/Vivado_proyect/Vitis_proyect/TP7/fpga/export/fpga/hw/fpga.xsa -regs
configparams mdm-detect-bscan-mask 2
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent Arty 210319A288D7A" && jtag_device_ctx=="jsn-Arty-210319A288D7A-0362d093-0"}
rst -system
after 3000
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent Arty 210319A288D7A" && jtag_device_ctx=="jsn-Arty-210319A288D7A-0362d093-0"}
dow /home/danielito/Escritorio/Vivado_proyect/Vitis_proyect/TP7/MicroBlazerConTrama/Debug/MicroBlazerConTrama.elf
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent Arty 210319A288D7A" && jtag_device_ctx=="jsn-Arty-210319A288D7A-0362d093-0"}
con
