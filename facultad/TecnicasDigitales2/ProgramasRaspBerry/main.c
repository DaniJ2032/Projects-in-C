//    #include <stdio.h>
//    #include <stdlib.h>
//#include "header.h"
//#include "password.h"
//#include "secuencias.h"
    //#include "pwm.h"
    //#include "com.h"
//#include "remote.h"
//#include "setspeed.h"
//#include "updatedspeed.h"
/////////////////////////////////////////////////////////////////
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <wiringPi.h>
#include <pcf8591.h>
#include <errno.h>
#include "EasyPIO.h"
//#include "password.c"
//#include "remote.c"
//#include "setspeed.c"
//#include "updatedspeed.c"
//#include "secuencias.c"
*/ 

#include "header.h"
#include "EasyPIO.h"

struct termios old,new;


int speed; //se le da un valor inicial con el pwm va a ser var global

int led [8] = {26,21,20,16,12,25,24,23};

int main (){
	
	int mode,seq;
	
	
	password();
	
	pioInit();
	
		pinMode(led [0], OUTPUT);
		pinMode(led [1], OUTPUT);
		pinMode(led [2], OUTPUT);
		pinMode(led [3], OUTPUT);
		pinMode(led [4], OUTPUT);
		pinMode(led [5], OUTPUT);
		pinMode(led [6], OUTPUT);
		pinMode(led [7], OUTPUT);
	
	
	
	printf("Seleccione el modo de trabajo \n");
    printf("1-Local \n");
    printf("2-Remoto \n");
	
	
	scanf("%d",&mode);
		if(mode==2){
			remote();
			mode=1;
		system ("clear");
	
			}
	//
	//printf("\n %d \n",mode);
	
	//printf("Configurando velocidad inicial \n");
	pcf8591Setup(64, 0x48);
	setspeed();
	
	
	
	
	do{
	system ("clear");
	printf("Ingreso al modo local\n");
	printf("Seleccione la secuencia y presione ENTER\n");
    printf("1-El Auto Fantastico \n");
    printf("2-El Choque \n");
	printf("3-La Apilada \n");
    printf("4-La Carrera \n");
	printf("5-Sequencia 5 \n");
    printf("6-Sequencia 6 \n");
	printf("7-Sequencia 7 \n");
    printf("8-Sequencia 8 \n");
    printf("9-Seteo de velocidad \n");
	printf("10-Salir del programa \n");
	scanf("%d",&seq);
	
	printf("%d \n",seq);
	
	
	usleep(100000);
	
	switch(seq){
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
				
		case 9: setspeed();
				break;
				 
		case 10: printf("Saliendo del programa\n");
				break;		
	
		default: printf("Seleccion invalida\n");
				break;
			}
	
	
	
}while(seq!=10);
	
	
	return 0;}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
