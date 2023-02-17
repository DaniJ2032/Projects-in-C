#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define N 10

void respuestas();
void porcentaje();
void basico();
void intermedio();
void avanzado();

int a,b,i,num,res,cor=0,incor=0,op;
int sms1, sms2; 
char opc;
float prom;

int main(void) {
	
	srand(time(NULL));
	do{
    system("cls");
	printf("     Bienvenido Usuario¡¡¡¡\n");
	printf("VAMOS A APRENDER A MULTIPLICAR¡¡¡\n");	
	printf("*********************************\n");
	printf("Elija una Dificultad:\n");
	printf("*********************\n");
	printf("______________________\n");
	printf("|Nivel_1|(BASICO)    |\n");
	printf("|Nivel_2|(INTERMEDIO)|\n");
	printf("|Nivel_3|(AVANZADO)  |\n");	
	printf("|--------------------|\n");
	
	do
	{
		scanf("%d",&op);	
		if(op>3)
			system ("cls");	
		printf("Opcion Invalida elija entre 1 y 3: ");
	}while(op>3);	
	
	
	switch(op){
		
		
	case 1: 
		
		for( i=1; i<=N; i++)
			
			basico();
		
		
		break;
	case 2: 
		
		for( i=1; i<=N; i++)
			
			intermedio();
		
		break;	
		
	default: 
		
		for( i=1; i<=N; i++)
			
			avanzado();
		break;	
		
	}
	
	porcentaje ();
	cor =0;
	incor = 0;
	printf("Programa Finalizado\nGracias por Participar :)\n\n");
	printf("Quiere volver a elejir otra dificultad?\n"); 
	printf("s/n:\n");		
	scanf("%s",&opc);
} while(opc=='s');	
	
if(opc=='n')
	return 0;
}

void basico(){
	
	a = rand()%10;                
	b = rand()%10; 
	num = a*b;
	
	system("cls");
	printf("Dificultad Basica Productos de 1 digito:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
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



void intermedio(){
	
	a = 10+rand()%91;                
	b = 10+rand()%91; 
	num = a*b;
	
	system("cls");
	printf("Dificultad Basica Productos de 2 digito:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
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

void avanzado(){
	
	a = 100+rand()%991;                
	b = 100+rand()%991; 
	num = a*b;
	
	system("cls");
	printf("Dificultad Avanzada Productos de 3 digitos:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
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
