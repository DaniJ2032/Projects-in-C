/*Juarez Daniel Alejandro 
Leg: 79111 
Curso: 1R5 
Año: 2019 
Materia: Informatica_1*/
#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#define N 5
#define M 10
int i,j,k,a,res[N][M],total[5],max,min;
float prom[5];
char op;
const char *p [5] = {"presidentes Deben Estar Mas Cercanos a la Gente ", 
	"Baja del Trafico de Drogas en las Calles ", 
	"Educacion Publica Actualemnte ", 
	"Ambientalemnte como Cree que Estamos ", 
	"Califique los Empleos en el Pais "};
void calificacion();
void imprimir();
void tabla();
void max_min();
void sum();

int main() {
	
	printf("Bien Vendio Ciudadano :)¡¡¡¡\n");
	printf("A continuacion se le mostrara 5 temas de interesa social\n");
	printf("Usted debera calificarlos del 1 al 10, siendo el 1 puntaje bajo y el 10 puntaje alto\n");
	printf("Comenzemos?:) s/n ");
	
	do{
		scanf("%c",&op);
		if(op=='n'){
			return 0;	
		}
	} while(op=='s');
	
	system ("cls");
	
	for(i = 0; i < M; i++){
		system ("cls");
		calificacion();
	}
	imprimir ();
	
	printf("\nMuchisimas gracais por encuestar :)\n");
	printf("no se olvide de tomar nota de los resultados...\n");
	printf("hasta pronto :)...\n\n");
	
	
	return 0;
	
}

void calificacion(){
	
	for(j=0; j < N ; j++){
		system("cls");
		printf("Pregunta N %d:\n",j+1);
		printf("%s: ",p[j]);
		scanf("%d",&res[j][i]);	
		Sleep (200);
		sum();
	}	
	
}

void imprimir (){
	
	system("cls");
	printf("Obteniendo Resultados\nPorfavor Espere...\n\n");
	
	for(char s=0; s<32; s++){
		printf("###");
		Sleep (50);		
	}
	printf("|100 Completado!!!\n\n");
	printf("\nSus resultados son: \n\n");
	
	printf("____________________________\n");
	for(i=0; i<N; i++)
	{
		printf("Total de la pregunta %d: ",i+1);
		printf("|%d|",total[i]);
		printf("\n");
	}
	printf("*****************************\n\n");
	tabla();
	max_min();
	
}	

void tabla(){
	
	printf("N de Encuestados:\n");
	for(i=0; i<M; i++)
	{
		printf("|%d|\t",i+1);
	}
	printf("\n");
	for(char s=0; s<54; s++){
		printf("__");
	}
	printf("\n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			
			printf("|%d|\t",res[i][j]);
		}
		printf("\t|Promedio %d: ",i+1);
		printf("|%.1f|",prom[i]/M);
		printf("\n");
	}
	for(char s=0; s<28; s++){
		printf("****");
	}
	
}
void max_min(){
	
	
	max = total[0];
	min = total[0];
	
	for (i=0; i<N; i++){
		if (total[i]> max){
			max=total[i];
		}
		if (total[i]< min){
			min=total[i];
		}
	}
	printf("\n\n");
	for (i = 0; i < N; i++){
		
		if(total[i]==max){
			
			printf("Pregunta %d Mayor Puntaje\n",i+1);
			printf("____________________________________________________________\n");
			printf("|%s| Puntaje: %d \n",p[i],max);
			printf("************************************************************\n\n");
		}
		
		if(total[i]==min){
			printf("Pregunta %d Menor Puntaje\n",i+1);
			printf("____________________________________________________________\n");
			printf("|%s| Puntaje: %d \n",p[i],min);
			printf("************************************************************\n\n");
		}	
		
	}
	
}
void sum(){
	
	total[j]+=res[j][i]; 
	prom[j]+=res[j][i]; 
}



