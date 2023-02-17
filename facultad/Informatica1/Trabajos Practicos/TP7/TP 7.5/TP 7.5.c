#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

int a,b,i,num,res,cor=0,incor=0,op,random;
int sms1, sms2; 
char opc;
float prom;

void respuestas();
void porcentaje();
void suma();
void resta();
void multiplicacion();
void mezclado();
void basico_sum();
void intermedio_sum();
void avanzado_sum();
void basico_res();
void intermedio_res();
void avanzado_res();
void basico_mul();
void intermedio_mul();
void avanzado_mul();
void basico_mes();
void intermedio_mes();
void avanzado_mes();

int main(void) {
	
	
	do{

		printf("Bienvenido Alumno!!! :)\n");	
		printf("************************\n");	
		printf("Elija una de las siguientes opciones:\n\n");
		
		printf("Opcion_1 (Sumas)\n");	
		printf("Opcion_2 (Restas)\n");	
		printf("Opcion_3 (Multiplicacion)\n");	
		printf("Opcion_4 (Mezcla de Operaciones)\n");	
		
		do
		{
			scanf("%d",&op);	
			if(op>4)

			printf("Opcion Invalida elija entre 1 y 4: ");
		}while(op>4);	
		
		
		switch(op){
			
		case 1: 
			suma();
			break;
			
		case 2:
			resta();
			break;
			
		case 3: 
			multiplicacion();
			break;
			
		default: 	
			mezclado();
		}
		
		printf("\nQuiere volver al menu preincipal\n"); 
		printf("y elejir otra opcion? s/n:");		
		scanf("%s",&opc);
		
	} while(opc=='s');	
	if(opc=='n')
		
		return 0;
}


void suma(){
	
	do{

		printf("A ELEJIDO LA OPCION DE OPERACIONES DE SUMA¡¡¡ ;)\n");	
		printf("************************************************\n\n");
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

			printf("Opcion Invalida elija entre 1 y 3: ");
			
		}while(op>3);
		
		switch(op){
			
			
		case 1: 
			
			for( i=0; i<=N; i++){
				
				basico_sum();
			}
			break;
		case 2: 
			
			for( i=0; i<=N; i++){
				
				intermedio_sum();
			}
			break;	
			
		default: 
			
			for( i=0; i<=N; i++){
				
				avanzado_sum();
			}
			break;	
			
		}
		porcentaje ();
		cor =0;
		incor = 0;
		printf("\nQuiere elejir otro nivel? s/n: ");	
		scanf("%s",&opc);
		
	}while(opc=='s');	
	if(opc=='n');

	
	
	
}


void basico_sum(){
	
	a = rand()%10;                
	b = rand()%10; 
	num = a+b;
	

	printf("Dificultad Basica sumas de 1 digito:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
	printf("Pregunta Nº %d: ",i);
	printf("¿cuanto es?: %d+%d = ",a,b);
	
	scanf("%d",&res);
	
	if(res != num){	
		incor++;
		respuestas();

	}else{
		cor++;
		respuestas();

	}
	
}

void intermedio_sum(){
	
	a = 10+rand()%91;                
	b = 10+rand()%91; 
	num = a+b;
	

	printf("Dificultad Basica sumas de 2 digito:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
	printf("Pregunta Nº %d: ",i);
	printf("¿cuanto es?: %d+%d = ",a,b);
	
	scanf("%d",&res);
	
	if(res != num){	
		incor++;
		respuestas();

	}else{
		cor++;
		respuestas();
	
	}		
	
	
	
}
void avanzado_sum(){
	
	a = 100+rand()%991;                
	b = 100+rand()%991; 
	num = a+b;

	printf("Dificultad Avanzada sumas de 3 digitos:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
	printf("Pregunta Nº %d: ",i);
	printf("¿cuanto es?: %d+%d = ",a,b);
	
	scanf("%d",&res);
	
	if(res != num){	
		incor++;
		respuestas ();

	}else{
		cor++;
		respuestas ();

		
	}
}

void resta(){
	
	do{
	
		printf("A ELEJIDO LA OPCION DE OPERACIONES DE RESTA¡¡¡ ;)\n");	
		printf("*************************************************\n\n");
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
			
			printf("Opcion Invalida elija entre 1 y 3: ");
			
		}while(op>3);
		
		switch(op){
			
			
		case 1: 
			
			for( i=0; i<=N; i++){
				
				basico_res();
			}
			break;
		case 2: 
			
			for( i=0; i<=N; i++){
				
				intermedio_res();
			}
			break;	
			
		default: 
			
			for( i=0; i<=N; i++){
				
				avanzado_res();
			}
			break;	
			
		}
		porcentaje ();
		cor =0;
		incor = 0;
		printf("\nQuiere elejir otro nivel? s/n: ");	
		scanf("%s",&opc);
		
	}while(opc=='s');	
	if(opc=='n');

	
	
}

void basico_res(){
	
	a = rand()%10;                
	b = rand()%10; 
	num = a-b;
	
	
	printf("Dificultad Basica restas de 1 digito:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
	printf("Pregunta Nº %d: ",i);
	printf("¿cuanto es?: %d-%d = ",a,b);
	
	scanf("%d",&res);
	
	if(res != num){	
		incor++;
		respuestas();
	
	}else{
		cor++;
		respuestas();
	
	}
	
}

void intermedio_res(){
	
	a = 10+rand()%91;                
	b = 10+rand()%91; 
	num = a-b;

	printf("Dificultad intermedia restas de 2 digito:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
	printf("Pregunta Nº %d: ",i);
	printf("¿cuanto es?: %d-%d = ",a,b);
	
	scanf("%d",&res);
	
	if(res != num){	
		incor++;
		respuestas();

	}else{
		cor++;
		respuestas();
	
	}		
	
	
	
}
void avanzado_res(){
	
	a = 100+rand()%991;                
	b = 100+rand()%991; 
	num = a-b;
	

	printf("Dificultad Avanzada restas de 3 digitos:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
	printf("Pregunta Nº %d: ",i);
	printf("¿cuanto es?: %d-%d = ",a,b);
	
	scanf("%d",&res);
	
	if(res != num){	
		incor++;
		respuestas ();

	}else{
		cor++;
		respuestas ();

		
	}
	
}































void multiplicacion(){
	
	do{
		system ("cls");	
		printf("A ELEJIDO LA OPCION DE OPERACIONES DE MULTIPLICACION¡¡¡ ;)\n");	
		printf("**********************************************************\n\n");
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
			
			for( i=0; i<=N; i++){
				
				basico_mul();
			}
			break;
		case 2: 
			
			for( i=0; i<=N; i++){
				
				intermedio_mul();
			}
			break;	
			
		default: 
			
			for( i=0; i<=N; i++){
				
				avanzado_mul();
			}
			break;	
			
		}
		porcentaje ();
		cor =0;
		incor = 0;
		printf("\nQuiere elejir otro nivel? s/n: ");	
		scanf("%s",&opc);
		
	}while(opc=='s');	
	if(opc=='n');

	
}

void basico_mul(){
	
	a = rand()%10;                
	b = rand()%10; 
	num = a*b;

	printf("Dificultad Basica Productos de 1 digito:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
	printf("Pregunta Nº %d: ",i);
	printf("¿cuanto es?: %d*%d = ",a,b);
	
	scanf("%d",&res);
	
	if(res != num){	
		incor++;
		respuestas();
	

	}else{
		cor++;
		respuestas();

	}
	
}

void intermedio_mul(){
	
	a = 10+rand()%91;                
	b = 10+rand()%91; 
	num = a*b;
	

	printf("Dificultad Intermedia productos de 2 digito:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
	printf("Pregunta Nº %d: ",i);
	printf("¿cuanto es?: %d*%d = ",a,b);
	
	scanf("%d",&res);
	
	if(res != num){	
		incor++;
		respuestas();

	}else{
		cor++;
		respuestas();

	
	}		
	
	
	
}
void avanzado_mul(){
	
	a = 100+rand()%991;                
	b = 100+rand()%991; 
	num = a*b;
	

	printf("Dificultad Avanzada productos de 3 digitos:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
	printf("Pregunta Nº %d: ",i);
	printf("¿cuanto es?: %d*%d = ",a,b);
	
	scanf("%d",&res);
	
	if(res != num){	
		incor++;
		respuestas ();

	}else{
		cor++;
		respuestas ();

	}		
	
}


void mezclado(){
	
	do{
	
		printf("A ELEJIDO LA OPCION DE OPERACIONES MEZCLADAS¡¡¡ ;)\n");	
		printf("***********************************************\n\n");
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
		
			printf("Opcion Invalida elija entre 1 y 3: ");
			
		}while(op>3);
		
		switch(op){
			
			
		case 1: 
			
			for( i=0; i<=N; i++){
				
				basico_mes();
			}
			break;
		case 2: 
			
			for( i=0; i<=N; i++){
				
				intermedio_mes();
			}
			break;	
			
		default: 
			
			for( i=0; i<=N; i++){
				
				avanzado_mes();
			}
			break;	
			
		}
		
		
		porcentaje ();
		cor =0;
		incor = 0;
		printf("\nQuiere elejir otro nivel? s/n: ");	
		scanf("%s",&opc);
		
	}while(opc=='s');	
	if(opc=='n');

	
	
}



void basico_mes(){
	
	a = rand()%10;                
	b = rand()%10; 
	random = 1+rand()%3;
	

	printf("Dificultad Basica OP. Mezcladas de 1 digito:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
	
	printf("Pregunta Nº %d: ",i);
	
	
	switch (random){
		
	case 1:
		num = a+b;
		printf("¿cuanto es?: %d+%d = ",a,b);
		scanf("%d",&res);
		
		break;	
		
	case 2:
		num = a-b;	
		printf("¿cuanto es?: %d-%d = ",a,b);
		scanf("%d",&res);	
		
		break;	
		
	default:
		num = a*b;
		printf("¿cuanto es?: %d*%d = ",a,b);
		scanf("%d",&res);	
		
		
	}
	if(res != num){	
		incor++;
		respuestas();

	}else{
		cor++;
		respuestas();
	
	}
	
}

void intermedio_mes(){
	
	a = 10+rand()%91;                
	b = 10+rand()%91; 
	random = 1+rand()%3;

	printf("Dificultad Intermedia OP. Mezcladas de 2 digito:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
	
	printf("Pregunta Nº %d: ",i);
	
	
	switch (random){
		
	case 1:
		num = a+b;
		printf("¿cuanto es?: %d+%d = ",a,b);
		scanf("%d",&res);
		
		break;	
		
	case 2:
		num = a-b;	
		printf("¿cuanto es?: %d-%d = ",a,b);
		scanf("%d",&res);	
		
		break;	
		
	default:
		num = a*b;
		printf("¿cuanto es?: %d*%d = ",a,b);
		scanf("%d",&res);	
		
		
	}
	if(res != num){	
		incor++;
		respuestas();
	

	}else{
		cor++;
		respuestas();

	}
	
	
	
}
void avanzado_mes(){
	
	a = 100+rand()%991;                
	b = 100+rand()%991; 
	random = 1+rand()%3;
	
	
	printf("Dificultad Avanzada OP. Mezcladas de 3 digitos:\n");
	printf("Comenzemos¡¡¡¡:\n\n");
	printf("Pregunta Nº %d: ",i);
	
	
	switch (random){
		
	case 1:
		num = a+b;
		printf("¿cuanto es?: %d+%d = ",a,b);
		scanf("%d",&res);
		
		break;	
		
	case 2:
		num = a-b;	
		printf("¿cuanto es?: %d-%d = ",a,b);
		scanf("%d",&res);	
		
		break;	
		
	default:
		num = a*b;
		printf("¿cuanto es?: %d*%d = ",a,b);
		scanf("%d",&res);	
		
		
	}
	if(res != num){	
		incor++;
		respuestas();

	}else{
		cor++;
		respuestas();

	}
}
void respuestas(){
	
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
	

	
	prom =(cor*100)/N;
	
	if(prom>75){
		
		printf("El Promedio es: %.1f \nPromedio superior del 75 porciento\n",prom);
		printf("¡Felicitaciones, está listo para pasar al siguiente nivel!\n\n");
		
	}else{
		printf("El Promedio es: %.1f\nPromedio por debajo del 75 porciento\n",prom);   
		printf("¡Pídale ayuda adicional a su maestro!\n\n");	
	}	
}






