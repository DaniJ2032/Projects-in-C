#include <stdio.h>
#include <stdlib.h>


int main (void){

	char contraseña [5] = {'p','e','p','i','t'};
	char contraseña_ingresada [5];
	int error = 0;
	printf("Ingrese su password de 5 digitos: ");
	scanf ("%s", &contraseña_ingresada);
	
	for (int i = 0; i < 5; i++){
		if (contraseña[i] != contraseña_ingresada[i]) error = 1;			
	}
	
	if (error == 1) printf("todo mal loco");

	else printf("todo joia");

}