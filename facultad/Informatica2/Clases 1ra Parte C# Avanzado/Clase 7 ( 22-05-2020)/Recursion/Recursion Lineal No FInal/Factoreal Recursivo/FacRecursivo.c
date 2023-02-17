/*Factoreal de un numero en Forma Recursiva*/

#include <stdio.h>
#include <stdlib.h>

long factorial( int );//Devuelve el factorial de un numero 
	//Se usa long porq el recursivo devuelto es largo y con int se desvorda (OverFLow)
	
int main ( int argc, char *argv[]){

int n;

	printf("\nIntroduzco el Numero que desea obteter el Factorial: ");
	scanf("%d",&n);
	printf("Factorial de ( %d ) es: ( %ld )\n\n", n, factorial(n));

return 0;
}//Fin del main();	

long factorial ( int numero ){

	if( numero > 1 )
		return (numero * factorial(numero -1));
	else
		return 1;
	//Fin del if(); esle	

}//Fin de la funcion factorial();	
