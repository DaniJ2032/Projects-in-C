#include "header.h"
//#include "updatedspeed.c"
//#include "EasyPIO.h"


extern int led [8]; //////SECUENCIA PERFECTA, CONTROLAR
extern int speed;

void autof(){
	
	int a = 1;
	
	int map [15] [8] =   
			   {{1, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 0, 0, 0, 0, 1},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 0, 0, 1, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0},
				{1, 0, 0, 0, 0, 0, 0, 0}
			       };

	

	system("clear");
	printf("-------------------------------------\n");
	printf("Ejecutando Auto Fantastico\n");
	printf("Presione ENTER para salir\n");
	printf("-------------------------------------\n");


	while (1)
	{
		for (int x = 0; x< 15; x++)
		{
			

			for (int y = 0; y< 8; y++)
			{
				
				digitalWrite (led [y], map [x][y]);
			}
			a=updatedspeed();
			printf("Speed %d \n",speed);
			
			if(a==0){
				printf("SALIENDO \n");

				for (int i = 0; i < 8; i++)											  
					digitalWrite (led [i], 0);	
				
				return;
				}
			usleep(speed);

		
			
		//getchar(); /// TOMA VALOR DEL TECLADO PARA SALIR INMEDIATAMENTE      ////TODAS LAS SECUENCIAS
			
		//updatedspeed(); // AJUSTA SPEED CON FLECHAS DEL TECLADO			   ////TODAS LAS SECUENCIAS
		//usleep(speed);													   ////TODAS LAS SECUENCIAS
			
			
		}
		
		
	}
	
							   
	

	
}
	
	
	////////////////////////////////////
	
	
	
			
void choque(){
	
	
	int matrix [7] [8] =  
			   {{1, 0, 0, 0, 0, 0, 0, 1},
				{0, 1, 0, 0, 0, 0, 1, 0},
				{0, 0, 1, 0, 0, 1, 0, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 1, 0, 0, 1, 0, 0},
				{0, 1, 0, 0, 0, 0, 1, 0},
				{1, 0, 0, 0, 0, 0, 0, 1}
			       };

	int a = 1;

	system("clear");
	printf("-------------------------------------\n");
	printf("Ejecutando El Choque\n");
	printf("-------------------------------------\n");

	while (1)
	{
		for (int i = 0; i < 7; i++)
		{
			
			for (int k = 0; k < 8; k++)
			{
				digitalWrite (led [k], matrix [i][k]);

			}

			a=updatedspeed();
			printf("Speed %d \n",speed);
			if(a==0){
				printf("SALIENDO \n");
				
				for (int i = 0; i < 8; i++)											  
					digitalWrite (led [i], 0);	
				
				return;
				}
			usleep(speed);
		}

		
	}
}

	
			
			
			
			
	////////////////////////////////////		
			
void apilada(){
	int a = 1;



	system("clear");
	printf("-------------------------------------\n");
	printf("Ejecutando La Apilada\n");
	printf("-------------------------------------\n");

	a=updatedspeed();
	printf("Speed %d \n",speed);
			if(a==0){
				printf("SALIENDO \n");
				
				for (int i = 0; i < 8; i++)											  
					digitalWrite (led [i], 0);	
				
				return;
				}
			usleep(speed);

		while (1){
		int i = 0;
		for (i = 0; i < 8; i++){
			
			
			for (int j = 7; j >= i; j--)
			{
				digitalWrite (led [j], 1);
					
					a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0){
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
				
						return;
							}
						
				usleep(speed);
			
				printf("Apago led\n");
				digitalWrite (led [j], 0);
				
					a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0){
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
				
						return;
						}
						
			    usleep(speed);
			}

			

		digitalWrite (led [i], 1);
					
					a=updatedspeed();
					printf("Speed %d \n",speed);
					if(a==0){
						printf("SALIENDO \n");
				
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
				
						return;
						}
						
			usleep(speed);

		
	}
	
	///////////////// CHEQUEAR SI NO HAY QUE REEMPLAZAR POR EL UPDATED SPEED
	
	
		usleep(1000000);
		for (int i = 0; i < 8; i++)
		digitalWrite (led [i], 0);
		usleep(300000);
		
	///////////////////	
	}
	
	

	
	
}
	
	
	
	
	
	////////////////////////////////////
	
	
		
void carrera(){
	
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

	int a = 1;

	//pioInit ();
	system("clear");
	printf("-------------------------------------\n");
	printf("Ejecutando La Carrera\n");
	printf("-------------------------------------\n");

	while (1)
	{
		for (int i = 0; i < 18; i++)
		{
			

			for (int k = 0; k < 8; k++){
		
				digitalWrite (led [k], matrix [i][k]);
				
							}

			
			a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
			usleep(speed);
		}

		
	}

}






	////////////////////////////////////
	
	
	
	
void seq5(){
	
	
	
	int map [17] [8] =   
			   {{1, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0},
				{1, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 0, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 1},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			       };

	int a = 1;

	system("clear");
	printf("-------------------------------------\n");
	printf("Ejecutando Sequencia 5\n");
	printf("-------------------------------------\n");


	while (1)
	{
		for (int x = 0; x< 17; x++)
		{
			for (int y = 0; y< 8; y++)
			{
				digitalWrite (led [y], map [x][y]);
			}

			a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
			usleep(speed);
		}

	
}
	
	}
	
	
	
	
	
	
	
	////////////////////////////////////
	
	
	
	
void seq6(){
	
	int map [9] [8] =   
			   {{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 1, 0, 0, 1, 0, 0},
				{0, 1, 0, 0, 0, 0, 1, 0},
				{1, 0, 0, 0, 1, 0, 0, 1},
				{1, 0, 0, 1, 0, 0, 0, 1},
				{0, 1, 0, 0, 0, 0, 1, 0},
				{0, 0, 1, 0, 0, 1, 0, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
			       };
	int a = 1;
	

	system("clear");
	printf("-------------------------------------\n");
	printf("Sequencia 6\n");
	printf("-------------------------------------\n");


	while (1)
	{
		for (int x = 0; x< 9; x++)
		{

			for (int y = 0; y< 8; y++)
			{	
				digitalWrite (led [y], map [x][y]);
			
			}
			
			a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
			usleep(speed);
			
		}
		
		
	}
	

	}
	



	////////////////////////////////////
	
void seq7(){
	
	int a = 1;
	
	system("clear");
	printf("-------------------------------------\n");
	printf("Sequencia 7 SOS\n");
	printf("-------------------------------------\n");


	while (1)
	{
		for (int x = 0; x< 3; x++)
		{
			
			for (int y = 0; y< 8; y++)
			{	
				digitalWrite (led [y], 1);
			
			}
			
			//////////////////////////
			//usleep(400000);
			
			///////////////////////
			a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
			usleep(speed); ////400000
			
			for (int y = 0; y< 8; y++)
			{	printf("Ejecutando Sequencia 7\n");
				digitalWrite (led [y], 0);
			
			}
			//////////////////////////
			//usleep(400000);
			
			///////////////////////
			a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
			usleep(speed); ////400000
			
		}
		
		
		for (int x = 0; x< 3; x++)
		{
			
			for (int y = 0; y< 8; y++)
			{	printf("Ejecutando Sequencia 7\n");
				digitalWrite (led [y], 1);
			
			}
			//////////////////////////
			//usleep(1400000);
			
			///////////////////////
			a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
			usleep(speed); ////1400000
			
			for (int y = 0; y< 8; y++)
			{	printf("Ejecutando Sequencia 7\n");
				digitalWrite (led [y], 0);
			
			}
			//////////////////////////
			//usleep(1400000);
			
			///////////////////////
			a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
			usleep(speed); ////1400000
		}
		
		for (int x = 0; x< 3; x++)
		{
			
			for (int y = 0; y< 8; y++)
			{	printf("Ejecutando Sequencia 7\n");
				digitalWrite (led [y], 1);
			
			}
			//////////////////////////
			//usleep(400000);
			
			///////////////////////
			a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
			usleep(speed); ////400000
			for (int y = 0; y< 8; y++)
			{	printf("Ejecutando Sequencia 7\n");
				digitalWrite (led [y], 0);
			
			}
			//////////////////////////
			//usleep(400000);
			
			///////////////////////
			a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
			usleep(speed); ////400000
		}
		
		
		printf("Fin SOS");
		
	}
	
	

	}
	

	////////////////////////////////////
void seq8(){
	
	int a = 1;
	int j=0;
	system("clear");
	printf("-------------------------------------\n");
	printf("Sequencia 8 Piano\n");
	printf("-------------------------------------\n");
	

	while (1)
	{
		
		digitalWrite (led [3], 1);
			//////////////////////////
			//usleep(500000);
			
			///////////////////////
				a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
				usleep(speed); ////500000
			
		digitalWrite (led [5], 1);
			//////////////////////////
			//usleep(500000);
			
			///////////////////////
				a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
				usleep(speed); ////500000
				
		digitalWrite (led [8], 1);
			//////////////////////////
			//usleep(500000);
			
			///////////////////////
				a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
				usleep(speed); ////500000
				
		digitalWrite (led [0], 1);
			//////////////////////////
			//usleep(500000);
			
			///////////////////////
				a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
				usleep(speed); ////500000
				
		digitalWrite (led [6], 1);
			//////////////////////////
			//usleep(500000);
			
			///////////////////////
				a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
				usleep(speed); ////500000
			
	for(int i=0;i<8;i++){
		digitalWrite (led [i],0);
				
				}
			
	for(int i=0;i<8;i++){
		digitalWrite (led [i], 1);
			//////////////////////////
			//usleep(100000);
			
			///////////////////////
				a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
		usleep(speed); ////100000
				}
			
	for(int i=0;i<8;i++){
		digitalWrite (led [i],0);
				// NO LLEVA SLEEP
				}
				
				
				
	for(int i=8;i>-1;i--){
		digitalWrite (led [i],1);
			//////////////////////////
			//usleep(100000);
			
			///////////////////////
				a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
		usleep(speed); ////100000
				}
				
			
	for(int i=0;i<8;i++){
		digitalWrite (led [i],0);
				
				}
			//////////////////////////
			//usleep(100000);
			
			///////////////////////
				a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
		usleep(speed); ////100000
			
		
			
	do{
				
	for(int i=0;i<8;i++){
		digitalWrite (led [i],1);
				
					}
			//////////////////////////
			//usleep(200000);
			
			///////////////////////
				a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
		usleep(speed); ////200000	
		
	for(int i=0;i<8;i++){
		digitalWrite (led [i],0);
					}
					
			//////////////////////////
			//usleep(200000);
			
			///////////////////////
				a=updatedspeed();
					printf("Speed %d \n",speed);
					
					if(a==0) {
						printf("SALIENDO \n");
						for (int i = 0; i < 8; i++)											  
							digitalWrite (led [i], 0);	
							return;
								}
						
		usleep(speed); ////200000	
					
					j++;
				}while(j<3);
			
	}
	
	
	}
	

























