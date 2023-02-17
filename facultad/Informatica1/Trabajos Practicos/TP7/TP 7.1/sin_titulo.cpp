#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void multiplicacion();
int a,b,c,res,i;

int main(void) {
	
	
	
	srand(time(NULL));
	printf("    Bien venido Usuario¡¡¡¡\n");
	printf("Vamos a Aprender a Multiplicar\n");
	printf("******************************\n\n");
	
	
	for( i=1; i<=10; i++){
		
		multiplicacion();
		
	}
	
	printf("Programa Finalizado\nGracias por Participar :)\n\n");
	
	system("pause");
	return 0;
}

void multiplicacion(){
	
	a = rand()%10;                
	b = rand()%10; 
	c = a*b;
	
	do{
		
		printf("Pregunta Nº %d: ",i);
		printf("¿cuanto es?: %d*%d = ",a,b);
		
		scanf("%d",&res);
		
		if(res != c){
			system("cls");
			printf("\nRespuesta Incorrecta Intentelo de Nuevo¡¡¡¡ \n\n");	
			
		}
		
	}while (res != c);
	printf("\nMuy Bien Hecho¡¡¡¡\n");
	Sleep(800);
	system("cls");	
	
}

