#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "EasyPIO.h"

struct termios old,new; 


int led [8] = {26,21,20,16,12,25,24,23};

void config(){
	tcgetattr(0,&old);
	new=old;
	new.c_lflag &= ~(ECHO | ICANON); 
	new.c_cc[VMIN]=0;
	new.c_cc[VTIME]=0;
	}

void lacarrera(){
	
	char aux='0';
	config();
	tcsetattr(0,TCSANOW,&new);

	int matrix [18][8] =	
				{{1, 0, 0, 0, 0, 0, 0, 0},
				 {1, 0, 0, 0, 0, 0, 0, 0},
				 {0, 1, 0, 0, 0, 0, 0, 0},
				 {0, 1, 0, 0, 0, 0, 0, 0},
				 {0, 0, 1, 0, 0, 0, 0, 0},
				 {0, 0, 1, 0, 0, 0, 0, 0},
				 {0, 0, 0, 1, 0, 0, 0, 0},
				 {0, 0, 0, 1, 0, 0, 0, 0},
				 {1, 0, 0, 0, 1, 0, 0, 0},
				 {0, 1, 0, 0, 1, 0, 0, 0},
				 {0, 0, 1, 0, 0, 1, 0, 0},
				 {0, 0, 0, 1, 0, 1, 0, 0},
				 {0, 0, 0, 0, 1, 0, 1, 0},
				 {0, 0, 0, 0, 0, 1, 1, 0},
				 {0, 0, 0, 0, 0, 0, 1, 1},
				 {0, 0, 0, 0, 0, 0, 0, 1},
				 {0, 0, 0, 0, 0, 0, 0, 0},
				 {0, 0, 0, 0, 0, 0, 0, 0}
				};

	

	pioInit ();
	system("clear");
	printf("-------------------------------------\n");
	printf("Ejecutando La Carrera\n");
	printf("Presione A para salir\n");
	printf("-------------------------------------\n");

	while (1)
	{
		for (int i = 0; i < 18; i++)
		{

			for (int k = 0; k < 8; k++){

				digitalWrite (led [k], matrix [i][k]);	
			}
			
					read(0,&aux,1);
				
					if(aux=='A'){
						printf("SALIENDO\n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	

						tcsetattr(0,TCSANOW,&old);
						return ;
					}

			usleep(100000);
		}

	}
}	


int main(void) {
   
        pioInit();
	
		pinMode(led [0], OUTPUT);
		pinMode(led [1], OUTPUT);
		pinMode(led [2], OUTPUT);
		pinMode(led [3], OUTPUT);
		pinMode(led [4], OUTPUT);
		pinMode(led [5], OUTPUT);
		pinMode(led [6], OUTPUT);
		pinMode(led [7], OUTPUT);

        printf("Bienvenido al programa\n");
        
        usleep(500000);
 
        
        lacarrera();

        tcsetattr(0,TCSANOW,&old);             
        return 0;
}

