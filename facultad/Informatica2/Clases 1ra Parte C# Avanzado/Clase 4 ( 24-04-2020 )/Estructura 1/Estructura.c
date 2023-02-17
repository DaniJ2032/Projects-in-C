/*Ejemplo de Archivos*/
#include <stdio.h>
#include <stdlib.h>
#define MAXTITL 40  //define maxima cantidad de carcateres
#define MAXAUTL 50  
#define MAXLIB 10000 

typedef struct libro{ //Estructura tipo Libro

	char titulo[MAXTITL];
	char autor[MAXAUTL];
	float precio;

}Lib_t;



int main (int argc, char *argv[]){

Lib_t  p[MAXLIB];
int cuenta = 0; 

	//p = malloc (sizeof(Lib_t));	


	printf("\nIngrese el Titulo del Libro: "); 

		while(cuenta < MAXLIB && fgets(p[cuenta].titulo, MAXTITL, stdin ) != NULL && p[cuenta].titulo[0] != '\n' ){

			printf("Ingrese el Autor del Libro: ");
			fgets(p[cuenta].autor, MAXAUTL, stdin); 
			printf("Ingrese el Precio: ");
			scanf("%f",&p[cuenta++].precio);
			
				while(getchar() != '\n') //para obiar el '\n' que carga el scanf
					continue; //le digo q continue

					if(cuenta < MAXLIB)
						printf("\nIngrese el Siguiente Libro: ");

    }//Fin del while

	if (cuenta > 0){

		printf("****LISTADO DE LIBROS CUARDADOS****\n\n"); //Lista los libros ingresados

			for(int i=0; i < cuenta; i++){
	
				printf("\nLibro: %s ", p[i].titulo);
				printf("Autor: %s ", p[i].autor);
				printf("Cuesta: %.2f\n\n", p[i].precio);

			}//Fin del for();
	}//Fin del if();
	
return 0;
}// Fin del main();









