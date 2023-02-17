#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define N 10
void multiplicacion();
void respuestas ();
void porcentaje ();

int a,b,i,num,res,cor=0,incor=0;
int sms1, sms2; 
float prom;

int main(void) {
	
	
	
	srand(time(NULL));
	printf("     Bienvenido Usuario¡¡¡¡\n");
	printf("Vamos a Aprender a Multiplicar\n");
	printf("******************************\n\n");
	
	
	for( i=1; i<=N; i++){
		
		multiplicacion();
		
	}
	porcentaje ();
	printf("Programa Finalizado\nGracias por Participar :)\n\n");
	system("pause");
	return 0;
}

void multiplicacion(){
	
	a = rand()%10;                
	b = rand()%10; 
	num = a*b;
	
	
	
	printf("Pregunta Nº %d: ",i);
	printf("¿cuanto es?: %d*%d = ",a,b);
	
	scanf("%d",&res);
	
	if(res != num){	
		incor++;
		respuestas ();
		Sleep(800);
		system("cls");
	}else{
		cor++;
		respuestas ();
		Sleep(800);
		system("cls");	
	}
	
}

void respuestas (){
	
	srand(time(NULL));	
	
	sms1 = rand()%5;                
	sms2 = rand()%5;	
	
	
	if(num==res){
		
		
		switch(sms1){
			
			
		case 1: 
			printf("\nExcelente Alumno¡¡¡¡\n");
			break;
			
		case 2:
			printf("\nSigue asi¡¡¡¡\n");
			break;
			
		case 3: 
			printf("\nCorrecto¡¡¡¡\n");
			break;
			
		default: 	
			printf("\nVas Muy Bien¡¡¡¡\n");
		}
		
	}else{
		
		switch(sms2){
			
		case 1: 
			printf("\nIncorrecta Intentelo de Nuevo¡¡¡¡\n\n");
			break;
			
		case 2:
			printf("\nSigue Intentando¡¡¡\n\n");
			break;
			
		case 3: 
			printf("\nRespuesta Erronea¡¡¡\n\n");
			break;
			
		default: 	
			printf("\nIncorrecto¡¡¡\n\n");
		}
		
	}
	
	
}

void porcentaje(){
	
	system("cls");
	
	prom= (cor*100)/N;
	
	if(prom>75){
		
		printf("El Promedio es: %.1f\nPromedio superior del 75 porciento\n",prom);
		printf("¡Felicitaciones, está listo para pasar al siguiente nivel!\n\n");
		
	}else{
		printf("El Promedio es: %.1f\nPromedio por debajo del 75 porciento\n",prom);   
		printf("¡Pídale ayuda adicional a su maestro!\n\n");	
	}	
}
