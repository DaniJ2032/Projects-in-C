/*Calculo de la serie Fibonacci Recursivo (Recursion Multiple)*/

#include <stdio.h>
#include <stdlib.h>

/*PROTOTIPOS*/
long Fibo( int );

int main( int argc, char* argv[] ){

int n, i;
long coef;

	printf("\n\nIngrese la Cantidad de Terminos de Fibonacci que desea: ");
	scanf("%d",&n);

	printf("Los Coeficientes de la Serie de Fibonacci son: \n");
	
		for(i=0; i<n; i++){

			coef = Fibo(i);
			printf("\n\nCoeficientes ( %d ) Valores de Fibonacci: [%ld]", i, coef);	
				
		}//Fin del for();		
		printf("\n");

return 0;
}//Fin del main();	

long Fibo( int n ){

	if( n > 1 ) return Fibo( n - 1 ) + Fibo( n - 2 );

	else if( n == 0 ) return 0;

	else if( n == 1 ) return 1;

	else return 0;



}//Fin de la Funcion Fibo();		
