#define Address 0x48	// ID del ADC gringo salame 
#define BASE 64			// Direccion de partida de la direccion de memoria de los pines analogicos			

#define A0 BASE+0		
#define A1 BASE+1		//Entradas analogicas del ADC
//#define A2 BASE+2
#define A3 BASE+3

#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>
#include <stdlib.h>
#include "EasyPIO.h" //ta rancio esto 


int main(void){
	int adc;
	
	if (wiringPiSetup () == -1){
		 printf("Error de seteo");
		 exit (1);	
				}

		pcf8591Setup(BASE, Address);	//NO OLVIDAR 
		
	while(1)
	{	
		system ("clear");
		printf("Setee el valor variando la iluminacion (0-255)\n");
		adc = analogRead(A0);
		printf("%d\n",adc);
		
		printf("Setee el valor variando la temperatura (0-255)\n");
		adc = analogRead(A1);
		printf("%d\n",adc);
		
		printf("Setee el valor variando el potenciometro (0-255)\n");
		adc = analogRead(A3);
		printf("%d\n",adc);

		usleep(100000);
	}
	
return 0;
}
