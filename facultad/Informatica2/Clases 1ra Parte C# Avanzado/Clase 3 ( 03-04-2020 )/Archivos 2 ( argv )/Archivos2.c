/*Ejemplo de Porcesamiento de archivos*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	
char p1;
char palabras [50];
FILE *ptrarchivo, *ptrSalida; //Puntero FILE para un archivo
 
ptrarchivo = fopen (argv[1], "r"); //Le el archivo en tiempo de ejecucion

	if( ptrarchivo != NULL ){
		
		while (!feof(ptrarchivo) ){ //feof = find end of file
			
			if((p1 = fgetc ( ptrarchivo )) == ';')
				
				printf("\n");
				
			else if(p1 == 'e')

				printf("u");
				
				
			else
				putchar ( p1 );	
	
		}//FIn del while();
	} //Fin del if()

	fclose( ptrarchivo ); //cierro el archivo cuando termino de usarlo
	
	if((ptrSalida = fopen("ArchivoDeTexto.txt", "a")) == NULL )
	
		printf("No se pudo abrir el Archivo de texto\n\n");
	else{
	
		printf("\nIngrese las palabras que desea agregar: \n");
		
			while( (fgets(palabras ,50, stdin)) != NULL && palabras [0] !='\n' ){
			
				fprintf(ptrSalida, "%s", palabras);
				
								
			}//Fin del While();		
		
	}//Fin del if() else
	
	fclose(ptrSalida);	
	printf("\n\n( %d )\n\n", argc);
	
//Fin del main();	
return 0;
}

