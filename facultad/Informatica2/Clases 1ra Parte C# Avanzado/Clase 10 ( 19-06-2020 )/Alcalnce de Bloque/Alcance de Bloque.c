#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
int numero = 1;
printf("El valor del numero es: %d\n\n", numero);

for(numero =1; numero < 9; numero ++){
	
int valor = numero*numero;	
printf("El valor del numero es: %d\n\n", numero);	
printf("El valor del valor es: %d\n\n", valor);
}
printf("El valor del numero es: %d y valor no existe\n\n", numero);	
	
	return 0;
}
