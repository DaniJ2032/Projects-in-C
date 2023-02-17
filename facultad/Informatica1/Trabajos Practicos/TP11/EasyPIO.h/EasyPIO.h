/ * EasyPIO.h
	* Creado: 8 de octubre de 2013
	* Sarah_Lichtman@hmc.edu y Joshua_Vasquez@hmc.edu
	* Última modificación: 5 de abril de 2014
	* Sarah_Lichtman@hmc.edu y Joshua_Vasquez@hmc.edu
	* 15 de agosto de 2014
	* David_Harris@hmc.edu (simplificar pinMode)
	* *						
	* Biblioteca para simplificar el acceso a la memoria en Raspberry Pi (Broadcom BCM2835). 
	* Debe ejecutarse con permisos de root usando sudo.
	* /
	
#ifndef EASY_PIO_H
#define EASY_PIO_H
	
	// Incluir declaraciones
#include <sys / mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
	// constantes
	//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
	
	// Tipos GPIO FSEL
#definir ENTRADA 0
#definir SALIDA 1
#define ALT0 4
#define ALT1 5
#define ALT2 6
#define ALT3 7
#define ALT4 3
#define ALT5 2
	
	// Desplazamientos de Bitfield de Clock Manager:
#define PWM_CLK_PASSWORD 0x5a000000
#define PWM_MASH 9
#define PWM_KILL 5
#define PWM_ENAB 4
#define PWM_SRC 0
	
	// Constantes PWM
#define PLL_FREQUENCY 500000000 // el valor PLLD predeterminado es 500 [MHz]
#define CM_FREQUENCY 25000000 // max pwm clk es 25 [MHz]
#define PLL_CLOCK_DIVISOR (PLL_FREQUENCY / CM_FREQUENCY)
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
	// Mapa de memoria
	//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
	
	// Estos #define valores son específicos del BCM2835, tomado de "BCM2835 ARM Peripherals"
	// # define BCM2835_PERI_BASE 0x20000000
	// Actualizado a BCM2836 para Raspberry Pi 2.0 Fall 2015 dmh
#define BCM2835_PERI_BASE 0x3F000000
	
#define GPIO_BASE (BCM2835_PERI_BASE + 0x200000)
#define UART_BASE (BCM2835_PERI_BASE + 0x201000)
#define SPI0_BASE (BCM2835_PERI_BASE + 0x204000)
#define PWM_BASE (BCM2835_PERI_BASE + 0x20c000)
	
#define SYS_TIMER_BASE (BCM2835_PERI_BASE + 0x3000) 
#define ARM_TIMER_BASE (BCM2835_PERI_BASE + 0xB000)
	
#define CM_PWM_BASE (BCM2835_PERI_BASE + 0x101000)
	
#define BLOCK_SIZE (4 * 1024)
	
	// Punteros que serán mapeados en memoria cuando se llama a pioInit ()
	volátil sin signo int * gpio; // puntero a la base de gpio
volátil sin signo int * spi; // puntero a la base de registros spi
volátil sin signo int * pwm;

volátil sin signo int * sys_timer;
volátil sin signo int * arm_timer; // puntero a la base de los registros del temporizador de brazo

volátil sin signo int * uart;
volátil sin signo int * cm_pwm;

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Registros GPIO
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

// Seleccionar función
#define GPFSEL ((volátil sin signo int *) (gpio + 0))
estructura typedef
{
	sin firmar FSEL0: 3;
	sin firmar FSEL1: 3;
	sin firmar FSEL2: 3;
	sin firmar FSEL3: 3;
	sin firmar FSEL4: 3;
	sin firmar FSEL5: 3;
	sin firmar FSEL6: 3;
	sin firmar FSEL7: 3;
	sin firmar FSEL8: 3;
	sin firmar FSEL9: 3;
	sin firmar: 2;
} gpfsel0bits;
#define GPFSEL0bits (* (gpfsel0bits * volátil) (gpio + 0))   
#define GPFSEL0 (* (volátil sin signo int *) (gpio + 0))

estructura typedef
{
	sin firmar FSEL10: 3;
	sin firmar FSEL11: 3;
	sin firmar FSEL12: 3;
	sin firmar FSEL13: 3;
	sin firmar FSEL14: 3;
	sin firmar FSEL15: 3;
	sin firmar FSEL16: 3;
	sin firmar FSEL17: 3;
	sin firmar FSEL18: 3;
	sin firmar FSEL19: 3;
	sin firmar: 2;
} gpfsel1bits;
#define GPFSEL1bits (* (gpfsel1bits * volátil) (gpio + 1))   
#define GPFSEL1 (* (volátil sin signo int *) (gpio + 1))

estructura typedef
{
	sin firmar FSEL20: 3;
	sin firmar FSEL21: 3;
	sin firmar FSEL22: 3;
	sin firmar FSEL23: 3;
	sin firmar FSEL24: 3;
	sin firmar FSEL25: 3;
	sin firmar FSEL26: 3;
	sin firmar FSEL27: 3;
	sin firmar FSEL28: 3;
	sin firmar FSEL29: 3;
	sin firmar: 2;
} gpfsel2bits;
#define GPFSEL2bits (* (gpfsel2bits * volátil) (gpio + 2))   
#define GPFSEL2 (* (volátil sin signo int *) (gpio + 2))                        

estructura typedef
{
	sin firmar FSEL30: 3;
	sin firmar FSEL31: 3;
	sin firmar FSEL32: 3;
	sin firmar FSEL33: 3;
	sin firmar FSEL34: 3;
	sin firmar FSEL35: 3;
	sin firmar FSEL36: 3;
	sin firmar FSEL37: 3;
	sin firmar FSEL38: 3;
	sin firmar FSEL39: 3;
	sin firmar: 2;
} gpfsel3bits;
#define GPFSEL3bits (* (gpfsel3bits * volátil) (gpio + 3))   
#define GPFSEL3 (* (volátil sin signo int *) (gpio + 3))                        


estructura typedef
{
	sin firmar FSEL40: 3;
	sin firmar FSEL41: 3;
	sin firmar FSEL42: 3;
	sin firmar FSEL43: 3;
	sin firmar FSEL44: 3;
	sin firmar FSEL45: 3;
	sin firmar FSEL46: 3;
	sin firmar FSEL47: 3;
	sin firmar FSEL48: 3;
	sin firmar FSEL49: 3;
	sin firmar: 2;
} gpfsel4bits;
#define GPFSEL4bits (* (gpfsel4bits * volátil) (gpio + 4))   
#define GPFSEL4 (* (volátil sin signo int *) (gpio + 4))                        

estructura typedef
{
	sin firmar FSEL50: 3;
	sin firmar FSEL51: 3;
	sin firmar FSEL52: 3;
	sin firmar FSEL53: 3;
	sin firmar: 20;
} gpfsel5bits;
#define GPFSEL5bits (* (gpfsel5bits * volátil) (gpio + 5))   
#define GPFSEL5 (* (volátil sin signo int *) (gpio + 5))                        

// Selección de salida de pin
#define GPSET ((volátil sin signo int *) (gpio + 7))
estructura typedef
{
	SET0 sin signo: 1;
	SET1: 1 sin signo;
	SET2 sin firmar: 1;
	SET3 sin firmar: 1;
	SET4 sin firmar: 1;
	SET5 sin firmar: 1;
	SET6 sin firmar: 1;
	SET7 sin firmar: 1;
	SET8 sin firmar: 1;
	sin firmar SET9: 1;
	SET10 sin firmar: 1;
	SET11: 1 sin signo;
	SET12 sin firmar: 1;
	SET13: 1 sin signo;
	SET14 sin firmar: 1;
	SET15: 1 sin signo;
	SET16 sin firmar: 1;
	SET17: 1 sin signo;
	SET18: 1 sin signo;
	SET19 sin firmar: 1;
	SET20: 1 sin signo;
	SET21 sin firmar: 1;
	SET22 sin firmar: 1;
	sin firmar SET23: 1;
	SET24: 1 sin signo;
	SET25 sin firmar: 1;
	SET26: 1 sin signo;
	SET27 sin firmar: 1;
	SET28: 1 sin signo;
	SET29: 1 sin signo;
	SET30 sin firmar: 1;
	SET31: 1 sin signo;
} gpset0bits;
#define GPSET0bits (* (gpset0bits * volátil) (gpio + 7))   
#define GPSET0 (* (volátil sin signo int *) (gpio + 7)) 

estructura typedef
{
	SET32: 1 sin signo;
	SET33 sin firmar: 1;
	SET34: 1 sin signo;
	SET35: 1 sin signo;
	SET36 sin firmar: 1;
	SET37 sin firmar: 1;
	SET38: 1 sin signo;
	SET39 sin firmar: 1;
	SET40 sin firmar: 1;
	SET41 sin firmar: 1;
	SET42 sin firmar: 1;
	SET43 sin firmar: 1;
	SET44 sin firmar: 1;
	SET45 sin firmar: 1;
	SET46 sin firmar: 1;
	SET47 sin firmar: 1;
	SET48 sin firmar: 1;
	SET49 sin firmar: 1;
	SET50 sin firmar: 1;
	SET51 sin firmar: 1;
	SET52 sin firmar: 1;
	SET53 sin firmar: 1;
	sin firmar: 10;
} gpset1bits;
#define GPSET1bits (* (gpset1bits volátil *) (gpio + 8))   
#define GPSET1 (* (volátil sin signo int *) (gpio + 8)) 

// Salida de clavija clara
#define GPCLR ((volátil sin signo int *) (gpio + 10))
estructura typedef
{
	sin firmar CLR0: 1;
	sin firmar CLR1: 1;
	sin firmar CLR2: 1;
	sin firmar CLR3: 1;
	sin firmar CLR4: 1;
	sin firmar CLR5: 1;
	sin firmar CLR6: 1;
	sin firmar CLR7: 1;
	sin firmar CLR8: 1;
	sin firmar CLR9: 1;
	sin firmar CLR10: 1;
	sin firmar CLR11: 1;
	sin firmar CLR12: 1;
	sin firmar CLR13: 1;
	sin firmar CLR14: 1;
	sin firmar CLR15: 1;
	sin firmar CLR16: 1;
	sin firmar CLR17: 1;
	sin firmar CLR18: 1;
	sin firmar CLR19: 1;
	sin firmar CLR20: 1;
	sin firmar CLR21: 1;
	sin firmar CLR22: 1;
	sin firmar CLR23: 1;
	sin firmar CLR24: 1;
	sin firmar CLR25: 1;
	sin firmar CLR26: 1;
	sin firmar CLR27: 1;
	sin firmar CLR28: 1;
	sin firmar CLR29: 1;
	sin firmar CLR30: 1;
	sin firmar CLR31: 1;
} gpclr0bits;
#define GPCLR0bits (* (gpclr0bits volátil *) (gpio + 10))   
#define GPCLR0 (* (volátil sin signo int *) (gpio + 10)) 

estructura typedef
{
	sin firmar CLR32: 1;
	sin firmar CLR33: 1;
	sin firmar CLR34: 1;
	sin firmar CLR35: 1;
	sin firmar CLR36: 1;
	sin firmar CLR37: 1;
	sin firmar CLR38: 1;
	sin firmar CLR39: 1;
	sin firmar CLR40: 1;
	sin firmar CLR41: 1;
	sin firmar CLR42: 1;
	sin firmar CLR43: 1;
	sin firmar CLR44: 1;
	sin firmar CLR45: 1;
	sin firmar CLR46: 1;
	sin firmar CLR47: 1;
	sin firmar CLR48: 1;
	sin firmar CLR49: 1;
	sin firmar CLR50: 1;
	sin firmar CLR51: 1;
	sin firmar CLR52: 1;
	sin firmar CLR53: 1;
	sin firmar: 10;
} gpclr1bits;
#define GPCLR1bits (* (gpclr1bits volátil *) (gpio + 11))   
#define GPCLR1 (* (volátil sin signo int *) (gpio + 11)) 

// Nivel de pin
#define GPLEV ((volátil sin signo int *) (gpio + 13))
estructura typedef
{
	sin firmar LEV0: 1;
	sin firmar LEV1: 1;
	LEV2 sin signo: 1;
	LEV3 sin firmar: 1;
	LEV4 sin signo: 1;
	sin firmar LEV5: 1;
	sin firmar LEV6: 1;
	sin firmar LEV7: 1;
	sin firmar LEV8: 1;
	sin firmar LEV9: 1;
	sin firmar LEV10: 1;
	sin firmar LEV11: 1;
	sin firmar LEV12: 1;
	sin firmar LEV13: 1;
	sin firmar LEV14: 1;
	sin firmar LEV15: 1;
	sin firmar LEV16: 1;
	sin firmar LEV17: 1;
	sin firmar LEV18: 1;
	sin firmar LEV19: 1;
	LEV20 sin firmar: 1;
	sin firmar LEV21: 1;
	sin firmar LEV22: 1;
	sin firmar LEV23: 1;
	sin firmar LEV24: 1;
	sin firmar LEV25: 1;
	sin firmar LEV26: 1;
	sin firmar LEV27: 1;
	sin firmar LEV28: 1;
	sin firmar LEV29: 1;
	sin firmar LEV30: 1;
	sin firmar LEV31: 1;
} gplev0bits;
#define GPLEV0bits (* (gplev0bits volátil *) (gpio + 13))   
#define GPLEV0 (* (volátil sin signo int *) (gpio + 13)) 


estructura typedef
{
	sin firmar LEV32: 1;
	sin firmar LEV33: 1;
	sin firmar LEV34: 1;
	sin firmar LEV35: 1;
	sin firmar LEV36: 1;
	sin firmar LEV37: 1;
	sin firmar LEV38: 1;
	sin firmar LEV39: 1;
	sin firmar LEV40: 1;
	sin firmar LEV41: 1;
	sin firmar LEV42: 1;
	sin firmar LEV43: 1;
	sin firmar LEV44: 1;
	sin firmar LEV45: 1;
	sin firmar LEV46: 1;
	sin firmar LEV47: 1;
	sin firmar LEV48: 1;
	sin firmar LEV49: 1;
	LEV50 sin firmar: 1;
	sin firmar LEV51: 1;
	sin firmar LEV52: 1;
	sin firmar LEV53: 1;
	sin firmar: 10;
} gplev1bits;
#define GPLEV1bits (* (gplev1bits volátil *) (gpio + 14))   
#define GPLEV1 (* (volátil sin signo int *) (gpio + 14)) 

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Registros SPI
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

estructura typedef
{
	CS sin firmar: 2;
	CPHA sin firmar: 1;
	CPOL sin firmar: 1;
	sin firmar BORRAR: 2;
	CSPOL sin firmar: 1;
	TA sin firmar: 1;
	DMAEN sin firmar: 1;
	INTD sin firmar: 1;
	INTR sin firmar: 1;
	ADCS sin firmar: 1;
	REN sin firmar: 1;
	LEN sin firmar: 1;
	sin firmar LMONO: 1;
	sin firmar TE_EN: 1;
	sin firmar HECHO: 1;
	RXD sin firmar: 1;
	TXD sin firmar: 1;
	RXR sin signo: 1;
	RXF sin firmar: 1;
	CSPOL0 sin firmar: 1;
	CSPOL1 sin firmar: 1;
	CSPOL2 sin firmar: 1;
	sin firmar DMA_LEN: 1;
	sin firmar LEN_LONG: 1;
	sin firmar: 6;
} spi0csbits;
#define SPI0CSbits (* (spi0csbits volátiles *) (spi + 0))   
#define SPI0CS (* (volátil sin signo int *) (spi + 0))

#define SPI0FIFO (* (volátil sin signo int *) (spi + 1))
#define SPI0CLK (* (volátil sin signo int *) (spi + 2))
#define SPI0DLEN (* (volátil sin signo int *) (spi + 3))

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Registros del temporizador del sistema
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

estructura typedef
{
	sin signo M0: 1;
	sin firmar M1: 1;
	M2 sin firmar: 1;
	M3 sin firmar: 1;
	sin firmar: 28;
} sys_timer_csbits;
#define SYS_TIMER_CSbits (* (volátil sys_timer_csbits *) (sys_timer + 0))
#define SYS_TIMER_CS (* (volátil sin signo int *) (sys_timer + 0))

#define SYS_TIMER_CLO (* (volátil sin signo int *) (sys_timer + 1))
#define SYS_TIMER_CHI (* (volátil sin signo int *) (sys_timer + 2))
#define SYS_TIMER_C0 (* (volátil sin signo int *) (sys_timer + 3))
#define SYS_TIMER_C1 (* (volátil sin signo int *) (sys_timer + 4))
#define SYS_TIMER_C2 (* (volátil sin signo int *) (sys_timer + 5))
#define SYS_TIMER_C3 (* (volátil sin signo int *) (sys_timer + 6))

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Registros de interrupción ARM
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

#define IRQ_PENDING_BASIC (* (volátil sin signo int *) (arm_timer + 128))
#define IRQ_PENDING1 (* (voltile unsigned int *) (arm_timer + 129))
#define IRQ_PENDING2 (* (volátil sin signo int *) (arm_timer + 130))

#define IRQ_ENABLE1 (* (volátil sin signo int *) (arm_timer + 132))
#define IRQ_ENABLE2 (* (volátil sin signo int *) (arm_timer + 133))
#define IRQ_ENABLE_BASIC (* (volátil sin signo int *) (arm_timer + 134))
#define IRQ_DISABLE1 (* (volátil sin signo int *) (arm_timer + 135))
#define IRQ_DISABLE2 (* (volátil sin signo int *) (arm_timer + 136))
#define IRQ_DISABLE_BASIC (* (volátil sin signo int *) (arm_timer + 137))

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Registros de temporizador ARM
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

#define ARM_TIMER_LOAD (* (volátil sin signo int *) (arm_timer + 256))
// TODO: crea la estructura de control del temporizador
#define ARM_TIMER_CONTROL (* (volátil sin signo int *) (arm_timer + 258))
#define ARM_TIMER_IRQCLR (* (volátil sin signo int *) (arm_timer + 259))
#define ARM_TIMER_RAWIRQ (* (volátil sin signo int *) (arm_timer + 260))
#define ARM_TIMER_RELOAD (* (volátil sin signo int *) (arm_timer + 262))
#define ARM_TIMER_DIV (* (volátil sin signo int *) (arm_timer + 263))

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Registros UART
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

estructura typedef
{
	DATOS sin firmar: 8;
	FE sin firmar: 1;
	PE sin firmar: 1;
	BE sin firmar: 1;
	OE sin firmar: 1;
	sin firmar: 20;  
} uart_drbits;
#define UART_DRbits (* (uart_drbits volátiles *) (uart + 0))   
#define UART_DR (* (volátil sin signo int *) (uart + 0))

estructura typedef
{
	unsigned int CTS: 1;
	unsigned int DSR: 1;
	unsigned int DCD: 1;
	unsigned int OCUPADO: 1;
	unsigned int RXFE: 1;
	unsigned int TXFF: 1;
	unsigned int RXFF: 1;
	unsigned int TXFE: 1;
	unsigned int RI: 1;
	unsigned int: 24;
} uart_frbits;
#define UART_FRbits (* (uart_frbits volátiles *) (uart + 6))  
#define UART_FR (* (volátil sin signo int *) (uart + 6))

estructura typedef
{
	unsigned int BIRF: 16;
	unsigned int: 16;
} uart_ibrdbits;
#define UART_IBRDbits (* (uart_ibrdbits volátiles *) (uart + 9))  
#define UART_IBRD (* (volátil sin signo int *) (uart + 9))

estructura typedef
{
	unsigned int FBRD: 6;
	unsigned int: 26;
} uart_fbrdbits;
#define UART_FBRDbits (* (uart_fbrdbits volátiles *) (uart + 10)) 
#define UART_FBRD (* (volátil sin signo int *) (uart + 10))

estructura typedef
{
	unsigned int BRK: 1;
	unsigned int PEN: 1;
	unsigned int EPS: 1;
	unsigned int STP2: 1;
	unsigned int FEN: 1;
	unsigned int WLEN: 2;
	unsigned int SPS: 1;
	unsigned int: 24;
} uart_lcrhbits;
#define UART_LCRHbits (* (uart_lcrhbits volátiles *) (uart + 11)) 
#define UART_LCRH (* (volátil sin signo int *) (uart + 11))

estructura typedef
{
	unsigned int UARTEN: 1;
	unsigned int SIREN: 1;
	unsigned int SIRLP: 1;
	unsigned int: 4;
	unsigned int LBE: 1;
	unsigned int TXE: 1;
	unsigned int RXE: 1;
	unsigned int DTR: 1;
	unsigned int RTS: 1;
	unsigned int OUT1: 1;
	unsigned int OUT2: 1;
	unsigned int RTSEN: 1;
	unsigned int CTSEN: 1;
	unsigned int: 16;
} uart_crbits;
#define UART_CRbits (* (uart_crbits volátiles *) (uart + 12))
#define UART_CR (* (volátil sin signo int *) (uart + 12))


estructura typedef
{
	unsigned int RIRMIS: 1;
	unsigned int CTSRMIS: 1;
	unsigned int DCDRMIS: 1;
	unsigned int DSRRMIS: 1;
	unsigned int RXRIS: 1;
	unsigned int TXRIS: 1;
	unsigned int RTRIS: 1;
	unsigned int FERIS: 1;
	unsigned int PERIS: 1;
	unsigned int BERIS: 1;
	unsigned int OERIS: 1;
	unsigned int: 21;
} uart_risbits;
#define UART_RISbits (* (uart_risbits volátiles *) (uart + 15))
#define UART_RIS (* (volátil sin signo int *) (uart + 15))

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Registros PWM
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

estructura typedef
{
	sin firmar PWEN1: 1;
	MODO sin firmar1: 1;
	RPTL1 sin firmar: 1;
	SBIT1 sin firmar: 1;
	POLA1 sin firmar: 1;
	USEF1 sin firmar: 1;
	sin firmar CLRF1: 1;
	MSEN1 sin firmar: 1;
	PWEN2 sin firmar: 1;
	MODO 2 sin signo: 1;
	RPTL2 sin firmar: 1;
	SBIT2 sin firmar: 1;
	POLA2 sin firmar: 1;
	USEF2 sin firmar: 1;
	sin firmar: 1;
	MSEN2 sin firmar: 1;
	sin firmar: 16;
} pwm_ctlbits;
#define PWM_CTLbits (* (volátil pwm_ctlbits *) (pwm + 0))
#define PWM_CTL (* (volátil sin signo int *) (pwm + 0))

#define PWM_RNG1 (* (volátil sin signo int *) (pwm + 4))
#define PWM_DAT1 (* (volátil sin signo int *) (pwm + 5))

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Registros de Clock Manager
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

estructura typedef
{
	SRC sin firmar: 4;
	ENAB sin firmar: 1;
	MATAR sin firmar: 1;
	sin firmar: 1;
	sin firmar OCUPADO: 1;
	FLIP sin firmar: 1;
	MASH sin firmar: 2;
	sin firmar: 13;
	PASSWD sin firmar: 8;
} cm_pwmctl_bits;
#define CM_PWMCTLbits (* (cm_pwmctl_bits * volátiles) (cm_pwm + 40))
#define CM_PWMCTL (* (volátil sin signo int *) (cm_pwm + 40))

estructura typedef
{
	DIVF sin firmar: 12;
	DIVI sin firmar: 12;
	PASSWD sin firmar: 8;
} cm_pwmdivbits;
#define CM_PWMDIVbits (* (cm_pwmdivbits * volátiles) (cm_pwm + 41))
#define CM_PWMDIV (* (volátil sin signo int *) (cm_pwm + 41)) 

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Funciones generales
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

// TODO: devuelve el código de error en lugar de imprimir (mem_fd, reg_map)
nulo pioInit () {
	int mem_fd;
	void * reg_map;
	
	// / dev / mem es un controlador psuedo para acceder a la memoria en el sistema de archivos Linux
	if ((mem_fd = abierto ("/ dev / mem", O_RDWR | O_SYNC)) <0) {
		printf ("no se puede abrir / dev / mem \ n");
		salida (-1);
	}
	
	reg_map = mmap (
					NULL, // Dirección en la que comenzar la asignación local (nulo significa que no importa)
					BLOCK_SIZE, // Tamaño del bloque de memoria mapeado
					PROT_READ | PROT_WRITE, // Habilita tanto la lectura como la escritura en la memoria asignada
					MAP_SHARED, // Este programa no tiene acceso exclusivo a esta memoria
					mem_fd, // Mapa de / dev / mem
					GPIO_BASE); // Desplazamiento a periférico GPIO
	
	if (reg_map == MAP_FAILED) {
		printf ("error de gpio mmap% d \ n", (int) reg_map);
		cerrar (mem_fd);
		salida (-1);
	}
	
	gpio = (volátil sin signo *) reg_map;
	
	reg_map = mmap (
					NULL, // Dirección en la que comenzar la asignación local (nulo significa que no importa)
					BLOCK_SIZE, // Tamaño del bloque de memoria mapeado
					PROT_READ | PROT_WRITE, // Habilita tanto la lectura como la escritura en la memoria asignada
					MAP_SHARED, // Este programa no tiene acceso exclusivo a esta memoria
					mem_fd, // Mapa de / dev / mem
					SPI0_BASE); // Desplazamiento a periférico SPI
	
	if (reg_map == MAP_FAILED) {
		printf ("error de spi mmap% d \ n", (int) reg_map);
		cerrar (mem_fd);
		salida (-1);
	}
	
	spi = (volátil sin signo *) reg_map;
	
	reg_map = mmap (
					NULL, // Dirección en la que comenzar la asignación local (nulo significa que no importa)
					BLOCK_SIZE, // Tamaño del bloque de memoria mapeado
					PROT_READ | PROT_WRITE, // Habilita tanto la lectura como la escritura en la memoria asignada
					MAP_SHARED, // Este programa no tiene acceso exclusivo a esta memoria
					mem_fd, // Mapa de / dev / mem
					PWM_BASE); // Desplazamiento a periférico PWM
	
	if (reg_map == MAP_FAILED) {
		printf ("error de pwm mmap% d \ n", (int) reg_map);
		cerrar (mem_fd);
		salida (-1);
	}
	
	pwm = (volátil sin signo *) reg_map;
	
	reg_map = mmap (
					NULL, // Dirección en la que comenzar la asignación local (nulo significa que no importa)
					BLOCK_SIZE, // Tamaño del bloque de memoria mapeado
					PROT_READ | PROT_WRITE, // Habilita tanto la lectura como la escritura en la memoria asignada
					MAP_SHARED, // Este programa no tiene acceso exclusivo a esta memoria
					mem_fd, // Mapa de / dev / mem
					SYS_TIMER_BASE); // Desplazamiento al periférico del temporizador
	
	if (reg_map == MAP_FAILED) {
		printf ("sys timer mmap error% d \ n", (int) reg_map);
		cerrar (mem_fd);
		salida (-1);
	}
	
	sys_timer = (volátil sin signo *) reg_map;
	
	reg_map = mmap (
					NULL, // Dirección en la que comenzar la asignación local (nulo significa que no importa)
					BLOCK_SIZE, // Tamaño del bloque de memoria mapeado
					PROT_READ | PROT_WRITE, // Habilita tanto la lectura como la escritura en la memoria asignada
					MAP_SHARED, // Este programa no tiene acceso exclusivo a esta memoria
					mem_fd, // Mapa de / dev / mem
					ARM_TIMER_BASE); // Desplazamiento a interrupciones
	
	
	if (reg_map == MAP_FAILED) {
		printf ("error de mmap del temporizador de armado% d \ n", (int) reg_map);
		cerrar (mem_fd);
		salida (-1);
	}
	
	arm_timer = (volátil sin signo *) reg_map;
	
	reg_map = mmap (
					NULL, // Dirección en la que comenzar la asignación local (nulo significa que no importa)
					BLOCK_SIZE, // Tamaño del bloque de memoria mapeado
					PROT_READ | PROT_WRITE, // Habilita tanto la lectura como la escritura en la memoria asignada
					MAP_SHARED, // Este programa no tiene acceso exclusivo a esta memoria
					mem_fd, // Mapa de / dev / mem
					UART_BASE); // Desplazado a periférico UART
	
	if (reg_map == MAP_FAILED) {
		printf ("error de uart mmap% d \ n", (int) reg_map);
		cerrar (mem_fd);
		salida (-1);
	}
	
	uart = (volátil sin signo *) reg_map;
	
	reg_map = mmap (
					NULL, // Dirección en la que comenzar la asignación local (nulo significa que no importa)
					BLOCK_SIZE, // Tamaño del bloque de memoria mapeado
					PROT_READ | PROT_WRITE, // Habilita tanto la lectura como la escritura en la memoria asignada
					MAP_SHARED, // Este programa no tiene acceso exclusivo a esta memoria
					mem_fd, // Mapa de / dev / mem
					CM_PWM_BASE); // Desplazamiento al periférico del temporizador ARM
	
	if (reg_map == MAP_FAILED) {
		printf ("cm_pwm mmap error% d \ n", (int) reg_map);
		cerrar (mem_fd);
		salida (-1);
	}
	
	cm_pwm = (volátil sin signo *) reg_map;
	cerrar (mem_fd);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Funciones de interrupción
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

int irq1, irq2, irqbasic;

nulo no Interrupts (nulo) {
	// guardar interrupciones actuales
	irq1 = IRQ_ENABLE1;
	irq2 = IRQ_ENABLE2;
	irqbasic = IRQ_ENABLE_BASIC;
	
	// deshabilitar interrupciones
	IRQ_DISABLE1 = irq1;
	IRQ_DISABLE2 = irq2;
	IRQ_DISABLE_BASIC = irqbasic; 
}

interrupciones nulas (nulas) {
	if (IRQ_ENABLE1 == 0) {// si las interrupciones están deshabilitadas
		// restaurar interrupciones
		IRQ_ENABLE1 = irq1;
		IRQ_ENABLE2 = irq2;
		IRQ_ENABLE_BASIC = irqbasic;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Funciones GPIO
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

void pinMode (int pin, int function) {
	int reg = pin / 10;
	int offset = (pin% 10) * 3;
	GPFSEL [reg] & = ~ ((función 0b111 & ~) << desplazamiento);
	GPFSEL [reg] | = ((0b111 y función) << desplazamiento);
}

void digitalWrite (int pin, int val) {
	int reg = pin / 32;
	int offset = pin% 32;
	
	if (val) GPSET [reg] = 1 << desplazamiento;
	sino GPCLR [reg] = 1 << desplazamiento;
}

int digitalRead (pin int) {
	int reg = pin / 32;
	int offset = pin% 32;
	
	return (GPLEV [reg] >> desplazamiento) & 0x00000001;
}

void pinsMode (int pins [], int numPins, int fxn) {
	int i;
	para (i = 0; i <numPins; ++ i) {
		pinMode (pines [i], fxn);
	}
}

void digitalWrites (int pines [], int numPins, int val) {
	int i;
	para (i = 0; i <numPins; i ++) {
		digitalWrite (pines [i], (val & 0x00000001));
		val = val >> 1;
	}
}

int digitalReads (int pins [], int numPins) {
	int i, val = digitalRead (pines [0]);
	
	para (i = 1; i <numPins; i ++) {
		val | = (digitalRead (pines [i]) << i);
	}
	retorno val;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Funciones del temporizador
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

// El reloj periférico del temporizador RPi es de 1MHz.
// La GPU usa M0 y M3, por lo que debemos usar M1 o M2

vacío delayMicros (int micros) {
	SYS_TIMER_C1 = SYS_TIMER_CLO + micros; // establece el registro de comparación
	// 1000 relojes por milisegundo
	SYS_TIMER_CSbits.M1 = 1; // restablecer el indicador de coincidencia a 0
	while (SYS_TIMER_CSbits.M1 == 0); // espera hasta que se establezca la bandera
}

nulo delayMillis (int millis) {
	delayMicros (millis * 1000); // 1000 microsegundos por milisegundo
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Funciones SPI
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

void spiInit (int freq, int settings) {
	// establece GPIO 8 (CE), 9 (MISO), 10 (MOSI), 11 (SCLK) alt fxn 0 (SPI0)
	pinMode (8, ALT0);
	pinMode (9, ALT0);
	pinMode (10, ALT0);
	pinMode (11, ALT0);
	
	// Nota: el divisor del reloj se redondeará a la potencia más cercana de 2
	SPI0CLK = 250000000 / frecuencia; // configura el reloj SPI a 250MHz / frecuencia
	SPI0CS = configuración;          
	SPI0CSbits.TA = 1; // activa SPI con el bit "transferencia activa"
}

char spiSendReceive (envío de caracteres) {
	SPI0FIFO = enviar; // enviar datos al esclavo
	while (! SPI0CSbits.DONE); // espera hasta que se complete la transmisión SPI
	volver SPI0FIFO; // devolver los datos recibidos
}

short spiSendReceive16 (envío corto) {
	rec corta
		SPI0CSbits.TA = 1; // activa SPI con el bit "transferencia activa"
	rec = spiSendReceive ((enviar & 0xFF00) >> 8); // enviar datos MSB primero
	rec = (rec << 8) | spiSendReceive (enviar & 0xFF);
	SPI0CSbits.TA = 0; // apague SPI
	volver rec;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Funciones UART
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

vacío uartInit (int baudios) {
	uint fb = 12000000 / baudios; // reloj UART de 3 MHz
	
	pinMode (14, ALT0);
	pinMode (15, ALT0);
	UART_IBRD = fb >> 6; // 6 fracturas, 16 bits internos de BRD
	UART_FBRD = fb & 63;
	UART_LCRHbits.WLEN = 3; // 8 datos, 1 parada, 0 paridad, sin FIFO, sin flujo
	UART_CRbits.UARTEN = 1; // Habilitar uart.
}

char getCharSerial (nulo) {
	while (UART_FRbits.RXFE); // Espere hasta que los datos estén disponibles.
	return UART_DRbits.DATA; // Devuelve char desde el puerto serie.
}


void putCharSerial (char c) {
	while (! UART_FRbits.TXFE);
	UART_DRbits.DATA = c;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////
// Funciones de modulación de ancho de pulso
//////////////////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////

void pwmInit () {
	pinMode (18, ALT5);
	
	// Configure el administrador de reloj para generar un reloj PWM de 25 MHz.
	// Falta la documentación sobre el administrador de reloj en la hoja de datos
	// pero encontrado en "BCM2835 Audio and PWM Clocks" de GJ van Loo 6 de febrero de 2013.
	// La frecuencia máxima de funcionamiento del reloj PWM es de 25 MHz.
	// Las escrituras en los registros del administrador de reloj requieren escritura simultánea
	// una "contraseña" de 5A a los bits superiores para reducir el riesgo de escrituras accidentales.
	
	CM_PWMCTL = 0; // Apague PWM antes de cambiar
	CM_PWMCTL = PWM_CLK_PASSWORD | 0x20; // Apaga el generador de reloj
	while (CM_PWMCTLbits.BUSY); // Espera a que el generador se detenga
	CM_PWMCTL = PWM_CLK_PASSWORD | 0x206; // Src = CLKD sin filtro de 500 MHz
	CM_PWMDIV = PWM_CLK_PASSWORD | (PLL_CLOCK_DIVISOR << 12); // PWM Freq = 25 MHz
	CM_PWMCTL = CM_PWMCTL | PWM_CLK_PASSWORD | 0x10; // Habilitar reloj PWM
	while (! CM_PWMCTLbits.BUSY); // Espera a que el generador arranque    
	PWM_CTLbits.MSEN1 = 1; // Canal 1 en modo marca / espacio
	PWM_CTLbits.PWEN1 = 1; // Habilitar pwm
}

/ **
	* dut es un valor entre 0 y 1 
	* freq es frecuencia pwm en Hz
	* /
	void setPWM (float freq, float dut) {
	PWM_RNG1 = (int) (CM_FREQUENCY / freq);
	PWM_DAT1 = (int) (dut * (CM_FREQUENCY / freq));
}

anular analogWrite (int val) {
	setPWM (78125, val / 255.0);
}

#terminara si
