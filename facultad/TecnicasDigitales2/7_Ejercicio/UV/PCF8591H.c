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


#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <pcf8591.h>

#define Address 0x48
#define BASE 64
#define A0 BASE+0
#define A1 BASE+1
#define A2 BASE+2
#define A3 BASE+3

int main(void){
	int val;
	if (wiringPiSetup () == -1) exit (1);	
	pcf8591Setup(BASE, Address);
	while(1)
	{
		val = analogRead(A0);
		printf("A0: %dmv\n",val*3300/255);
		val = analogRead(A1);
		printf("A1: %dmv\n",val*3300/255);
		val = analogRead(A2);
		printf("A2: %dmv\n\n",val*3300/255);
		delay(1000);
	}
return 0;
}
