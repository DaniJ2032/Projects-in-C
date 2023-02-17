/*Paso de Array 2D por Referencia*/

#include <stdio.h>
#include <stdlib.h>

void CargaArray2D(float (*D2)[3]); 

int main (int argc, char *argv[]){

float array2D[3][3] = {0};

	printf("\n\nArray2D antes de enstrar a la funcion es: \n\n");

		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
		
				printf("( %.2f )", array2D[i][j]);
			
			}//Fin del 2do for();
			printf("\n");
		}//Fin del 1er for();

	printf("\n\n\n");

	CargaArray2D(array2D);
 

	printf("Array2D despues de enstrar a la funcion es: \n\n");

		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
		
				printf("( %.2f )", array2D[i][j]);
			
			}//Fin del 2do for();
			printf("\n");
		}//Fin del 1er for();

	printf("\n\n\n");

return 0;
}//Fin del main();

void CargaArray2D(float (*D2)[3]){

/********************Cargamos la Matriz********************/
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
		
			printf("Ingrese el valor A[%d][%d]: ", i, j);
			scanf("%f",&D2[i][j]);
				
		}//Fin del 2do for();
		printf("\n");
	}//Fin del 1er for();

}//Fin de la funcion CargarArray2D();



