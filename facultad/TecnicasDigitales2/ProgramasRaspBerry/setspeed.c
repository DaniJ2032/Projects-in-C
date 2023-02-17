#define Address 0x48
#define BASE 64
#define A3 BASE+3

#include "header.h"
/*

#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

*/

extern int speed;

extern struct termios old,new;   ////////////////////////////

/////////////////////////////////////////////////////////////////////
void config();
/*{
	tcgetattr(0,&old);
	new=old;
	new.c_lflag &= ~(ECHO | ICANON); 
	new.c_cc[VMIN]=0;
	new.c_cc[VTIME]=0;
	
	
	}*/
///////////////////////////////////////////

void setspeed ()
{
	int vel;
	char aux='0'; ////
	config();////
	tcsetattr(0,TCSANOW,&new);/////////////////////
	
	
	//int a=0;
	
		if (wiringPiSetup () == -1){
		 printf("Error de seteo");
		 exit (1);	
				}

	//pcf8591Setup(BASE, Address);
	
	while(1){
	system ("clear");
	printf("Setee la velocidad moviendo el potenciometro (1-10)\n");
	printf("Presione A para salir\n");

	speed = analogRead(A3);
	speed=(speed+26)*3900;
	
	vel=speed/110000;
	printf("Velocidad %d\n",vel+1);
	
	
	
	
	read(0,&aux,1);
				
	if(aux=='A'){
		printf("SALIR\n");
		tcsetattr(0,TCSANOW,&old);
		return;
				}
				
	delay(100);

	
	}
	tcsetattr(0,TCSANOW,&old);
			
}

