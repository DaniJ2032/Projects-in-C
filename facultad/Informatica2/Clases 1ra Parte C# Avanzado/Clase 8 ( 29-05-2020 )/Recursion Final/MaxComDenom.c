/*Calculo del Maximo Comun Denominador con Recursion Final*/

#include <stdio.h>
#include <stdlib.h>

/*PROTOTIPO DE FUNCION*/
long MCD( long, long );


int main (int argc, char *argv []){

long a=4454, b=143052;

printf("\n\nEl Maximo Comun Divisor de [a]=( %ld ) y [b]=( %ld ) es: ( %ld )\n\n", a, b, MCD( a, b ));

return 0;	
}//Fin del main();	

long MCD(long a,long b ){

	if( a == b ) return a;

	else if ( a > b ) return MCD( a-b, b );

	else return MCD( a, b-a );
	//Fin de los if(); else anidados

}//Fin de la funcion long MCD();
