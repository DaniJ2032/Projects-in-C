#include <stdio.h>
#include <stdlib.h>
/*Ejemplo de Variable Externa Firkin*/

int unidad = 0; //Variable Externa
void critica (void);


int main(int argc, char *argv[]) {

extern int unidad;

printf("Cuantos Kilogramos equivale un Firkin de Manteca? \n");
scanf("%d",&unidad);

if(unidad ==25){ printf("Valor Correcto Campirano :) \n");}

while (unidad !=25)
critica(); 	
return 0;	
}

void critica (void){
	printf("\n valor Erroneo \n");		
}


