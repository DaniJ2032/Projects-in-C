/*Ejemplo de Puntero a Array*/

#include <stdio.h>

void CambiaLetra( char *c);

int main (int argc, char * argv[]){

char c[] = { 'm', 'e', 's', 'a' };

	printf("El Valor de ( c ) antes de Lamar a la Funcion es: ");
		
		for (int i=0; i<4; i++)
			printf("%c", c[i]);
		//Fin del for();	

	CambiaLetra (c);
	printf("\n\nEl Valor de ( c ) despues de Lamar a la Funcion es: ");
		
		for (int i=0; i<4; i++)
			printf("%c", c[i]);
		//Fin del for();

	printf("\n\n");
					
return 0;
} //Fin del main();

void CambiaLetra( char *c){

	c[1] = 'a';
}//Find e funcion CambiaLetra();
