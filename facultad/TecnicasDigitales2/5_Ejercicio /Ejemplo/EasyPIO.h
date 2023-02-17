/// INICIALIZANDO 

#ifndef EASY_PIO_H
#define EASY_PIO_H



#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define INPUT  0
#define OUTPUT 1
#define ALT0   4
#define ALT1   5
#define ALT2   6
#define ALT3   7
#define ALT4   3
#define ALT5   2


#define BCM2835_PERI_BASE 0x3F000000
#define GPIO_BASE (BCM2835_PERI_BASE + 0x200000)
#define BLOCK_SIZE (4*1024)

volatile unsigned int *gpio; //Pointer to base of gpio


//#define GPLEV0 (* (volatile unsigned int *) (gpio + 13))



#define GPFSEL ((volatile unsigned int *) (gpio + 0))
#define GPSET ((volatile unsigned int *) (gpio + 7))
#define GPCLR ((volatile unsigned int *) (gpio + 10))
#define GPLEV ((volatile unsigned int *) (gpio + 13))





void pioInit(){
	int mem_fd;
	void *reg_map;

	mem_fd = open("/dev/mem", O_RDWR|O_SYNC);
	reg_map = mmap(
		NULL, // Address at which to start local mapping (null = don't-care)
		BLOCK_SIZE, // 4KB mapped memory block
		PROT_READ|PROT_WRITE, // Enable both reading and writing to the mapped memory
		MAP_SHARED, // Nonexclusive access to this memory
		mem_fd, // Map to /dev/mem
		GPIO_BASE); // Offset to GPIO peripheral
		
		
	gpio = (volatile unsigned *)reg_map;
	close(mem_fd);
}







void pinMode(int pin, int function) {
	int reg = pin/10;
	int offset = (pin%10)*3;
		GPFSEL[reg] &= ~((0b111 & ~function) << offset);
		GPFSEL[reg] |= ((0b111 & function) << offset);
}


void digitalWrite(int pin, int val) {
	int reg = pin / 32;
	int offset = pin % 32;
	
	if (val) GPSET[reg] = 1 << offset;
		else GPCLR[reg] = 1 << offset;
}


int digitalRead(int pin) {
	int reg = pin / 32;
	int offset = pin % 32;

	return (GPLEV[reg] >> offset) & 0x00000001;
}

#endif
