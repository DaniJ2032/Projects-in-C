/*Determina si un Numero es Par o Impar Recursivamente (Recurcion Mutua)*/

#include<stdio.h>
#include<stdlib.h>

int Par( int );
int Impar( int );


int main( int argc, char* argv[] ){

int n = 31;

	if(Par(n))
		printf("\n\nEl Numeor es Par\n");
	else
		printf("\n\nEl Numero es Impar ( %d )\n",n);
	//Fin del if(); else	

return 0;
}//Fin del main();	

int Par( int n ){

	if( n==0 ) return 1;
	else return Impar( n - 1 );	

}//Fin de la Funsion Par();

int Impar ( int n ){

	if( n==0 ) return 0;
	else return Par( n - 1 );

}//Fin de la Funsion Impar();		
