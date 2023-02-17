#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplicacion();
void respuestas ();
int a,b,c,res,i;
int sms1, sms2; 


int main(void) {
	
	
	
	srand(time(NULL));
	printf("     Bienvenido Usuario¡¡¡¡\n");
	printf("Vamos a Aprender a Multiplicar\n");
	printf("******************************\n\n");
	
	
	for( i=1; i<=10; i++){
		
		multiplicacion();
		
	}
	
	printf("Programa Finalizado\nGracias por Participar :)\n\n");
	
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
			respuestas ();	
			
		}
		
	}while (res != c);
	
	respuestas ();

	
}

void respuestas (){
	
	srand(time(NULL));	
	
	sms1 = 1+(rand()%4);                
	sms2 = 1+(rand()%4);	
	
	
	if(c==res){
		
		
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



