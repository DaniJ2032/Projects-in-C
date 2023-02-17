/*Juarez Daniel Alejandro 
Leg: 79111 
Curso: 1R5 
Año: 2019 
Materia: Informatica_1*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include <windows.h>
#define N 36000
#define M 12

int i,j,v[M]={0};
int d1,d2,sum;
char op,op1,s;

void lanzamiento(){
	srand(time(NULL));	
	
	for(i=0; i<N; i++){	
		d1 = 1+(rand()%6);                
		d2 = 1+(rand()%6); 	
		sum = d1+d2;
		v[sum]++;	
	}

}

void conteo(){
	
	printf("Realizando los tiros porfavor espere...\n\n");
	
	for(s=0; s<32; s++){
	printf("###");
	Sleep (30);		
	}
	printf("|100 Completado!!!\n\n");
	
	
	
	printf("Cantidad de resultados Dados:\n\n");
	printf("\n");	
	for(i=2; i<=M; i++){
		printf("res=%d: %d\n",i ,v[i]);
		v[i]=0;
	}

}

int main() {
	
	do{
		printf("***********************************************\n");
		printf("Programa para Lanzamiento de dados 36000 veces\n");
		printf("***********************************************\n\n");
		
		do{
			printf("Quiere comenzar? s/n: ");	
			scanf("%c",&op);
			if(op=='n'){
				return 0;
			}	
		}while(op=='s');
		system("cls");
		lanzamiento();
		conteo();
		printf("\n\nQuiere volver a tirar? s/n: ");	
		scanf("%c",&op1);
	}while(op1=='s');
	if(op1=='n'){
		return 0;
	}
}

