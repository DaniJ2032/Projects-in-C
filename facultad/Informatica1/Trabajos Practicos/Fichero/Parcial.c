#include <stdio.h>
#include <stdlib.h>
#define N1 5
#define N2 6
#define N3 4
#define C 2
typedef struct aero_ARG{
	
	int v1[10][C],v2[10][C],v3[10][C];	
	
	
}AR_t;

int carga_V1(AR_t *p){
	
	printf("AVION 1:\n\n");
	printf("Ingrese los DNI:\n");
	for(int i = 0; i <N1; i++){
		for(int j=0; j <C; j++){
			printf("M %d:",i);	
			printf("[%d][%d] = ",i,j);
			scanf("%d",&p->v1[i][j]);	
		}
		printf("\n");
	}
	printf("\n\n");
	return p->v1[N1][C];	
}

int carga_V2(AR_t *p){
	
	printf("AVION 2:\n\n");
	printf("Ingrese los DNI:\n");
	for(int i = 0; i <N2; i++){
		for(int j=0; j <C; j++){
			printf("M %d:",i);	
			printf("[%d][%d] = ",i,j);
			scanf("%d",&p->v2[i][j]);	
		}
		printf("\n");
	}
	printf("\n\n");
	return p->v2[N2][C];	
}

int carga_V3(AR_t *p){
	
	printf("AVION 3:\n\n");
	printf("Ingrese los DNI:\n");
	for(int i = 0; i <N3; i++){
		for(int j=0; j <C; j++){
			printf("M %d:",i);	
			printf("[%d][%d] = ",i,j);
			scanf("%d",&p->v3[i][j]);	
		}
		printf("\n");
	}
	printf("\n\n");
	return p->v3[N3][C];	
}



void verificacion(AR_t *p){
	
	
	int op; 
	char opc;	
	do{
		system ("cls");
		printf("Bienvenido a Registros:)\n");	
		printf("************************\n");	
		printf("Elija un Avion para ver los asientos ocupados y disponibles:\n\n");	
		printf("AVION 1: \n");	
		printf("AVION 2: \n");	
		printf("AVION 3: \n");	
		printf("Elija 4 para ver Ocupacion/promedio/acientos libres: \n");	
		
		do
		{
			scanf("%d",&op);
			if(op>4)
				system ("cls");	
			printf("Opcion Invalida elija entre 1 y 4: ");
		}while(op>4);	
		
		switch(op){
			
		case 1: 
			
			system("cls");
			printf("AVION 1:\n\n");
			for(int i = 0; i < N1; i++){
				for(int j=0; j < C ; j++){
					
					printf("|%d|",p->v1[i][j]);
				}
				printf("\n");
			}
			printf("\n\n");
			break;
			
		case 2:
			
			system("cls");
			printf("AVION 2:\n\n");
			for(int i = 0; i < N2; i++){
				for(int j=0; j < C ; j++){
					
					printf("|%d|",p->v2[i][j]);
				}
				printf("\n");
			}
			printf("\n\n");
			break;
			
		case 3: 
			
			system("cls");
			printf("AVION 3:\n\n");
			for(int i = 0; i < N3; i++){
				for(int j=0; j < C ; j++){
					
					printf("|%d|",p->v3[i][j]);
				}
				printf("\n");
			}
			printf("\n\n");
			break;
			
		default: 	
			
			printf("NADA\n\n");	
			
		}
		printf("Quiere ver otro Avion? s/n:");		
		scanf("%s",&opc);
	} while(opc=='s');	
	/*	if(opc=='n')*/	
}


int main() {
	
	int op;
	char opc;
	
	AR_t p;	
	p.v1[N1][C]={0};
	p.v2[N2][C]={0};
	p.v3[N3][C]={0};
	
	do{
		system ("cls");
		printf("Bienvenido a Aero_ARG. S.A:)\n");	
		printf("************************\n");	
		printf("Elija un Avion de la flota:\n\n");	
		printf("AVION 1: \n");	
		printf("AVION 2: \n");	
		printf("AVION 3: \n");	
		printf("Elija 4 para ver Ocupacion/promedio/acientos libres: \n");	
		
		do
		{
			scanf("%d",&op);
			if(op>4)
				system("cls");
			printf("Opcion Invalida elija entre 1 y 4: ");
		}while(op>4);	
		
		
		switch(op){
			
		case 1: 
			system("cls");
			p.v1[N1][C]=carga_V1(&p);
			break;
			
		case 2:
			system("cls");
			p.v2[N2][C]=carga_V2(&p);
			break;
			
		case 3: 
			system("cls");
			p.v3[N3][C]=carga_V3(&p);
			break;
			
		default: 	
			verificacion(&p);
		}
		
		printf("y elejir otra opcion? s/n:");		
		scanf("%s",&opc);
	} while(opc=='s');	
	if(opc=='n')
		
		return 0;
}



