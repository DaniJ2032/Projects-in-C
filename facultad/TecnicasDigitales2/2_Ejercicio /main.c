#include <stdio.h>
extern void Retardo (unsigned long int a);

int main (void){
	unsigned long int a;
	printf("Ingrese retardo: ");
	scanf ("%lu", &a);
	
	while(1){
		printf("Hola\n");
		Retardo(a);
		
		
		//printf("%d\n", a);
	}

}
