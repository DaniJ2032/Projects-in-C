/*Habilitar el puerto I2C:
 * 
 * El puerto I2C debe habilitarse en Raspbian antes de poder ser utilizado
 * $ sudo raspi-config
 * ...
 * Ir a Interfacing Options
 * ...
 * Seleccionar I2C Enable/Dis...
 * ...
 * Habilitar I2C y salir del menu
 *
 *
 *Instalar las herramientas I2C, usadas para debuggear los dispositivos I2C por linea de comandos:
 *
 * $sudo apt-get install i2c-tools
 * $sudo apt-get update
 *
 *Detecando los dispositivos conectados al bus I2C (ID de los dispositivos):
 *
 * $i2cdetect -y 0
 * $i2cdetect -y 1
 *
 *Instalar wiringPi: 
 * 
 * $ cd
 * $ git clone git://git.drogon.net/wiringPi
 *
 * $ cd ~/wirinPi
 * $ ./build
 *
 *
 *Compilar con wiringPi:
 * 
 * $gcc -o ejemplo ejemplo.c -lwiringPi
 *
 *Run:
 * 
 * sudo ./ejemplo
 *
 * */


#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

const char PCF8591 = 0x48; // direccion base

int fd, adcVal;	//declaracion de variables para acceder al adc

int main()   {

if (wiringPiSetup () == -1) exit (1);	//

fd = wiringPiI2CSetup(PCF8591);		// configuracion del bus I2C, inicializa el sistema I2C con el ID del dispositivo.

while (1)   {
	//read ADC0
	wiringPiI2CReadReg8(fd, PCF8591 + 0) ; //primer lectura 
	adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 0) ;//segunda lectura valida
	printf("Pot value = %d \n", adcVal);
	//read ADC1
	wiringPiI2CReadReg8(fd, PCF8591 + 1) ; 
	adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 1) ;
	printf("Photocell = %d \n", adcVal);
	//read ADC2
	wiringPiI2CReadReg8(fd, PCF8591 + 2) ; 
	adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 2) ;
	printf("Termister = %d \n\n", adcVal);
			  
	delay(500);
			  
     }
			  
return 0;
			  
}

