#include <stdio.h>
#include <stdlib.h>

int medicion = 24;
void respuesta (void);

int main(int argc, char *argv[]) {
	
int numero = medicion;
printf("\n Numero = %d", numero);
respuesta();
respuesta();
printf("\n Numero = %d", numero);	
	
	
	return 0;	
}

void respuesta (void){
	
int otro = medicion;
medicion += 10;
printf("\n Otro = %d", otro);
	
}

