CC = gcc
AS = as
LD = ld

OBJECTS = main.o operacion.o
MAIN    = main.c    
ASM     = operacion.s

CFLAGS = -Wall -g  -c
ASFLAGS = -g 
LDFLAGS = -g 
  
  all:    $(OBJECTS)
          $(CC) $(LDFLAGS) $(OBJECTS) -o $(ASM).elf
          $(ASM).s 
          $(AS) $(ASFLAGS) $(ASM) -o $(ASM).o
          $(MAIN).c
          $(CC) $(CFLAGS) $(MAIN)
          
  clean:
          rm *.o *.elf 