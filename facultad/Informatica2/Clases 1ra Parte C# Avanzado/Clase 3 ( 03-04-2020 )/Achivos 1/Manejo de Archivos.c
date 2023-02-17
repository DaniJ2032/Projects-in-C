/*Ejemplo de Porcesamiento de archivos*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	
char p1;
FILE *ptrarchivo; //Puntero FILE para un archivo
 
ptrarchivo = fopen ("ArchivoDeTexto.txt", "r");

	if( ptrarchivo != NULL ){
		
		while (!feof(ptrarchivo) ){ //feof = find end of file
			p1 = fgetc ( ptrarchivo );
			putchar (p1);
		}
	} //Fin del if()

	fclose (ptrarchivo);
	printf("\n\n");

//Fin del main();	
return 0;
}

