# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct /home/danielito/Escritorio/Vivado_proyect/Vitis_proyect/TP7/fpga/platform.tcl
# 
# OR launch xsct and run below command.
# source /home/danielito/Escritorio/Vivado_proyect/Vitis_proyect/TP7/fpga/platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {fpga}\
-hw {/home/danielito/Escritorio/Vivado_proyect/project_8_MIcroBlazerConTrama/fpga.xsa}\
-fsbl-target {psu_cortexa53_0} -out {/home/danielito/Escritorio/Vivado_proyect/Vitis_proyect/TP7}

platform write
domain create -name {standalone_microblaze_0} -display-name {standalone_microblaze_0} -os {standalone} -proc {microblaze_0} -runtime {cpp} -arch {32-bit} -support-app {hello_world}
platform generate -domains 
platform active {fpga}
platform generate -quick
platform generate
platform generate
platform generate
platform generate
platform generate
