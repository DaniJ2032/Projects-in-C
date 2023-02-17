/*Juarez Daniel Alejandro 
Leg: 79111 
Curso: 1R5 
Año: 2019 
Materia: Informatica_1*/
#include <stdio.h>
#include <stdlib.h>
#define N 80
#define A 2019

typedef struct heelthprofile {
	
	char nombre[N], genero[N];
	int nacimiento[3], edad, dni, frecuencia;
	float altura, peso;
	
}HP_t;

void carga(HP_t p[], HP_t *c){
	
	
	printf("Ingrese Su Nombre: "); fgets(c->nombre, 80, stdin);
	
	printf("Ingrese su DNI: "); scanf("%d",&c->dni);
	
	printf("Ingrese su sexo: "); scanf("%s",&c->genero[0]);
	
	printf("Ingrese su Altura: "); scanf("%f",&c->altura);
	
	printf("Ingrese su peso: "); scanf("%f",&c->peso);
	
	printf("Ingrese su fecha de nacimiento: ");
	for(int i=0; i<3; i++){
		scanf("%d",&p[i].nacimiento[i]);
	}
}


int resta (HP_t p[]){	
	return A - (p[2].nacimiento[2]);
}

float indice (HP_t *c){
	return c->peso / (c->altura*c->altura);
}

int frec_max(HP_t *c, HP_t e){
	return 220 - e.edad;
}
int rangomax_frec(HP_t *c, HP_t f){
	return (f.frecuencia)*0.85;
}
int rangomin_frec(HP_t *c, HP_t f){
	return (f.frecuencia)*0.5;
}

int main (void){
	
	HP_t e,f,c,p[3];
	
	carga(p,&c);
	e.edad = resta(p);
	indice(&c);
	f.frecuencia = frec_max(&c,e);
	rangomax_frec(&c,f);
	rangomin_frec(&c,f);
	
	system ("cls");	
	printf("\nNombre y apellido del paciente: %s",c.nombre);
	printf("DNI del paciente: %d\n",c.dni);
	printf("Altura del paciente: %.2f \n",c.altura);
	printf("peso del paciente: %.2f \n",c.peso);
	printf("sexo del paciente: %s \n",c.genero);
	printf("Edad del paciente: %d \n",e.edad);
	printf("Fecha de nacimeinto: ");
	for(int i=0; i<3; i++){
		printf("|%d|",p[i].nacimiento[i]);
	}		
	printf("\nIMC del Paciente: %.2f", indice(&c));
	printf("\nFrecuencia cardiaca Maxima: %d",f.frecuencia);
	printf("\nRango de frecuencia es desde: %d",rangomax_frec(&c,f));
	printf(" Hasta: %d",rangomin_frec(&c,f));
	
	return 0;
}

