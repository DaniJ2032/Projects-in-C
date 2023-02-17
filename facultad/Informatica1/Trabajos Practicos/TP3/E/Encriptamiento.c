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
	
	printf("**********************************\nENCRIPTAMIENTO DE UN N DE 4 CIFRAS\n**********************************\n\n");
	printf("Introduce el numero de 4 cifras: ");
	
	do{
		system ("color 3F");
		scanf("%d",&n);
		if(n>9999)
		printf("\nEl N maximo a introducir es 9999\nVuelva a introducir otro numero: ");	
	}while(n>9999);
	
	system ("cls");
	a=n%10;n=n/10; b=n%10;n=n/10;
	c=n%10;n=n/10; d=n%10; 
	
	t=a; a=c; c=t; 	
	t=b; b=d; d=t;
	
	a=(a+7)%10; c=(c+7)%10;
	b=(b+7)%10; d=(d+7)%10;
	f=d*1000+c*100+b*10+a*1;
	
	printf("Su numero codificado es: %d\n\n",f);
	
	return 0;
}
