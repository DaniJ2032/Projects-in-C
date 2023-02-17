#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*Juarez Daniel Alejandro 
Leg: 79111 
Curso: 1R5 
Año: 2019 
Materia: Informatica_1*/

int main(int argc, char *argv[]) {
	
	int n,a,b,c,d,t,f;
	
	printf("*************************************\nDESENCRIPTAMIENTO DE UN N DE 4 CIFRAS\n*************************************\n\n");
	printf("Introduce el numero de 4 cifras: ");
	
	do{
		system ("color 4F");	
		scanf("%d",&n);
		printf("\nEl N maximo a introducir es 9999\nVuelva a introducir otro numero: ");	
	}while(n>9999);
	
	system ("cls");
	a=n%10;n=n/10; b=n%10;n=n/10;
	c=n%10;n=n/10; d=n%10; 
	
	t=a; a=c; c=t; 	
	t=b; b=d; d=t;
	
	a=(a+3)%10; c=(c+3)%10;
	b=(b+3)%10; d=(d+3)%10;
	f=d*1000+c*100+b*10+a*1;
	
	printf("Su numero decodificado es: %d\n\n",f);
	
	return 0;
}
