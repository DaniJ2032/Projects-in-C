CC = gcc
AS = as
LD = ld

OBJECTS = main.o suma.o

CFLAGS = -Wall -g  -c
ASFLAGS = -g 
LDFLAGS = -g 
  
  suma.elf: $(OBJECTS)
          $(CC) $(LDFLAGS) $(OBJECTS) -o suma.elf
  
  suma.o: suma.s 
          $(AS) $(ASFLAGS) suma.s -o suma.o
  
  main.o: main.c
          $(CC) $(CFLAGS) main.c
  
  clean:
          rm *.o *.elf 