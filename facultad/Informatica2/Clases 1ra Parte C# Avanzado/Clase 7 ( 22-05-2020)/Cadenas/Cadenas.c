/*Manipulacion de Cadenas de Caracteres*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Libreria de Manejo de cadenas

int main ( int argc , char* argv[]){

char Apellidos[100 ];
char Nombres[100];
char Legajo[7];

	printf("\n\nIngrese su Nombre: "); 
	fgets(Nombres, 32, stdin); 

	printf("\nIngrese su o sus Apellidos: "); 
	fgets(Apellidos, 32, stdin);

	printf("\nIngrese el Legajo: "); fgets(Legajo, 7, stdin);  
 
	/*//memcpy(NOmbres, Nombres, strlen(Nombres)-1);
	//strncpy(Nombres, Nombres, strlen(Nombres)-3);*/
	
  		for(int i = 0; i < strlen(Nombres); i++ ){
			
			//if(Nombres[i] == '\n')
				//Nombres[i] = '\t';
				if(Nombres[i]!= '\n')
					Nombres[i] = Nombres[i];
				else
					Nombres[i] = '\0';

		}//Fin del for();	
	printf("\n\n");

		/*for(int i=0; i<strlen(Nombres)-1; i++)
			putchar(Nombres[i]);
			printf(" ");
		for(int i=0; i<strlen(Apellidos)-1; i++)
			putchar(Apellidos[i]);	
	//printf("\n\n[%s]\t[%s]", Nombres, Apellidos);
	printf("\n( %s )\n", Legajo);*/

 /*Verifica el tamaño de la Cadena*/
printf("\n\nLa cadena Nombres tiene el Tamaño de: ( %i )", strlen(Nombres));

/*int i=0;
	while(Nombres[i]!='\n')
		i++;
		printf("\n\n( i )= [%i]\n\n",i);*/


	printf("El Legajo es: ( %s )", Legajo);
	printf("El Legajo +1 es: ( %d )\n\n", atoi(Legajo)+1);
/*******************************************************************/

/*CONCANETACION DE CADENAS*/
 
printf("El Nombre Completo es: [ %s ]\n\n\n", strcat(Nombres,  Apellidos));	 
/*************************************************************/

/*Compiado de Cadenas*/





return 0;
}//Fin de la Funsion main();





