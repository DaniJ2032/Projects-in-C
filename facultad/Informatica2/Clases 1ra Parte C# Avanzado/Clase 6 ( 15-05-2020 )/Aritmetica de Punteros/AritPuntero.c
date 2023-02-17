/*Ejemplo de Aritmetica de Punteros*/

#include <stdio.h>



int main (int argc, char * argv[]){

int matrizA[3][3] = {};

/********************Cargamos la Matriz********************/
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
		
			printf("Ingrese el valor A[%d][%d]\n", i, j);
			scanf("%d",&matrizA[i][j]);
				
		}//Fin del 2do for();
		printf("\n");
	}//Fin del 1er for();
/*********************************************************/	

/************Mostramos la MatrizA con sus dos Indicies************/
	for(int i=0; i<3; i++){
	
		printf("\nEsta en la Fila: ( %d )\n", i);
		
		for(int j=0; j<3; j++){
		
			printf("Fila i= ( %d ) Columna j= ( %d )  valor de la Matriz |%d||%d| = ( %d )\n", i,j, i,j, matrizA[i][j]);
			
		}//Fin del 2do for();
	}//Fin del 1er for();
	printf("\n\n\n");
/*********************************************************/	

/*Mostramos la MatrizA como un Puntero de *matrizA[i][j]*/
printf("\n\nNuestra Matriz *(matrizA[i]+j) es: \n\n");

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
		
			printf("( %d )", *(matrizA[i]+j));
			
		}//Fin del 2do for();
		printf("\n");
	}//Fin del 1er for();
/*********************************************************/

/******Leemos la Matriz como *(*(matrizA +i)+j) **********/

printf("\n\nNuestra Matriz *(*(matrizA +i)+j) es: \n\n");

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
		
			printf("( %d )", *(*(matrizA +i)+j));
			
		}//Fin del 2do for();
		printf("\n");
	}//Fin del 1er for();
/*********************************************************/

/******Leemos la Matriz como *(&matrizA[0][0]+(3*i)+j)***********/

printf("\n\nNuestra Matriz *(&matrizA[0][0]+(3*i)+j) es: \n\n");

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
		
			printf("( %d )", *(&matrizA[0][0]+(3*i)+j));
			
		}//Fin del 2do for();
		printf("\n");
	}//Fin del 1er for();
/*********************************************************/
	printf("\n\n\n");	

				
return 0;
} //Fin del main();

