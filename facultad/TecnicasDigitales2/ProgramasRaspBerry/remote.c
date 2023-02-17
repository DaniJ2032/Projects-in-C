#include "header.h"

/*
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <wiringPiI2C.h>
#include <fcntl.h> 
#include <unistd.h> 
#include "EasyPIO.h"
*/

int serialPort;

void send(){
	
	int seqsend, rts;

	if ((serialPort = serialOpen ("/dev/ttyS0", 9600)) < 0)
	{
		fprintf (stderr, "ERROR: %s\n", strerror (errno));
		delay (1000);
		return;
	}

	if (wiringPiSetup () == -1)
	{
		fprintf (stdout, "ERROR: %s\n", strerror (errno));
		delay (1000);
		return;
	}
	
	
	do{
	system ("clear");
	printf("Seleccione la secuencia a TRANSMITIR y presione ENTER\n");
    printf("1-El Auto Fantastico \n");
    printf("2-El Choque \n");
	printf("3-La Apilada \n");
    printf("4-La Carrera \n");
	printf("5-Sequencia 5 \n");
    printf("6-Sequencia 6 \n");
	printf("7-Sequencia 7 \n");
    printf("8-Sequencia 8 \n");
	printf("9-Salir del programa \n");
	scanf("%d",&seqsend);
	
	printf("%d \n",seqsend);
	
	serialPutchar (serialPort, (char) seqsend);

	
	switch(seqsend){
	/*	case 1: autof();
				break;
				
		case 2: choque();
				break;
	
		case 3: apilada();
				break;
	
		case 4: carrera();
				break;
	
		case 5: seq5();
				break;
	
		case 6: seq6();
				break;
	
		case 7: seq7();
				break;
	
		case 8: seq8();
				break;
	*/			
		case 9: printf("Saliendo del programa\n");
				break;			
	
		default: printf("Seleccion invalida\n");
				break;
			}
	
	
}while(seqsend!=9);
	
	
	}
	
void receive(){
	
	char seqreceive;

	if ((serialPort = serialOpen ("/dev/ttyS0", 9600)) < 0)
	{
		fprintf (stderr, "ERROR: %s\n", strerror (errno));
		delay (1000);
		return;
	}

	if (wiringPiSetup () == -1)
	{
		fprintf (stdout, "ERROR: %s\n", strerror (errno));
		delay (1000);
		return;
	}
	
	
		
	system ("clear");
	printf("Recibiendo secuencia a ejecutar\n");
    printf("*******************************\n");
    printf("*******************************\n");
	
 

	seqreceive = serialGetchar (serialPort);
	
	printf("Ejecutando secuencia\n");
	
	switch(seqreceive){
		case 1: autof();
				break;
				
		case 2: choque();
				break;
	
		case 3: apilada();
				break;
	
		case 4: carrera();
				break;
	
		case 5: seq5();
				break;
	
		case 6: seq6();
				break;
	
		case 7: seq7();
				break;
	
		case 8: seq8();
				break;
				
		case 9: printf("Saliendo del programa");
				break;			
	
		default: printf("Seleccion invalida\n");
				break;
			}
	

	}
	
	
	
	
void remote (){
	
	int com;
	
	system ("clear");
	
	do{
	
	printf("1-Enviar a otro dispositivo\n");
	printf("2-Recibir de otro dispositivo\n");
	printf("3-Volver al modo local\n");
	scanf ("%d", &com);

	switch(com){
		case 1: send();
				break;
				
		case 2: receive();
				break;
	
		case 3: 
				break;
	
		default: printf("Seleccion invalida\n");
				break;
			}
	}while(com!=3);
	
	
	return;

	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
