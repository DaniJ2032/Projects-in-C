/*Ejemplo de Recursion en funciones Updown*/
#include <stdio.h>
#include <stdlib.h>
						
void Up_and_Down( int );

int main (int argc, char *argv[]){

Up_and_Down( 1 );

return 0;
}//Fin del main();

void Up_and_Down( int n ){

printf("\n\nEl Nivel al que ah Ingresado es ( %d ) Ubicacion [ %p ]", n, &n);
printf("\n\n");

	if(n < 4)
		Up_and_Down( n+1 );
	//Fin del if();
	printf("\n\nEl Nivel al que ah Ingresado es ( %d ) Ubicacion [ %p ]", n, &n);

printf("\n\n\n");
}//Fn de la Funsion UpandDown();






