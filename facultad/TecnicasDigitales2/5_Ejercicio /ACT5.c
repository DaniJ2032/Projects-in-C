#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "EasyPIO.h"

struct termios old,new; 


int led [8] = {26,21,20,16,12,25,24,23}; //pines para los led

void config(){
	tcgetattr(0,&old);
	new=old;
	new.c_lflag &= ~(ECHO | ICANON); //COnfiguracion de la terminal modo no canonico
	new.c_cc[VMIN]=0;
	new.c_cc[VTIME]=0;
}

void autof(){
	
	char aux='0';
	config();
	tcsetattr(0,TCSANOW,&new);

	
	while(1){
		
		system("clear");
		printf("-------------------------------------\n");
		printf("Ejecutando Auto Fantastico\n");
		printf("Presione A para salir\n");
		printf("-------------------------------------\n");
	
		for (int i=0;i<8;i++) {

			digitalWrite(led [i], 1);	//Secuencia de Derecha a izquierda
			usleep(100000);
			digitalWrite(led [i], 0);
				
				read(0,&aux,1);
						
				if(aux=='A'){
					printf("SALIENDO\n");
					for (int i = 0; i < 8; i++)											  
						digitalWrite (led [i], 0);	
				tcsetattr(0,TCSANOW,&old);
				return ;
				}
		}//fin ford(i)

		for (int j=7;j>=0;j--) {

			digitalWrite(led [j], 1);		//Secuencia de izquierda a derecha
			usleep(100000);
			digitalWrite(led [j], 0);
			read(0,&aux,1);
						
				if(aux=='A'){
					printf("SALIENDO\n");
					for (int i = 0; i < 8; i++)											  
						digitalWrite (led [i], 0);	
					tcsetattr(0,TCSANOW,&old);
					return ;
				}					
			} //fin ford(j)
	} //FInd e while(1)

} //fin del void autof()


int main(void) {
      
        pioInit(); //inicializo los pines 
	
		pinMode(led [0], OUTPUT);
		pinMode(led [1], OUTPUT); //definen pines de salida de  los leds
		pinMode(led [2], OUTPUT);
		pinMode(led [3], OUTPUT);
		pinMode(led [4], OUTPUT);
		pinMode(led [5], OUTPUT);
		pinMode(led [6], OUTPUT);
		pinMode(led [7], OUTPUT);

        printf("Bienvenido al programa\n");
        
        usleep(500000);
 
        
        autof();

          tcsetattr(0,TCSANOW,&old); //seteo atributos viejos             
        return 0;
}

