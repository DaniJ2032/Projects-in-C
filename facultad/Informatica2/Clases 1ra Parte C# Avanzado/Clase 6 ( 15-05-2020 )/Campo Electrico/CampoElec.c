/*Programa que Obtiene el Campo ELectrico en el Origen debido a Varias Cargas*/
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

#define k 9e9
/*PROTOTIPO DE FUNCIONES*/
void Campo(float *ptrEx, float *ptrEy, int n);
void CalculaCampo(float *ptrEx, float *ptrEy, float q, float x, float y);
/*****************************************************************/

int main(int argc, char* argv[]){

int n; //Para pedir cantidad de Cargas
float Ex, Ey, *ptrEx, *ptrEy;

ptrEx = &Ex;
ptrEy = &Ey;

	printf("\n\nIngrese Canitdad de Cargas para obtener el Campo Electrico: ");
	scanf("%d",&n);
	
	Campo(ptrEx, ptrEy, n);//Paso los valores a la funcion Campo			
printf("\n\nValor de la suma de las componenetes en ( x ) es: [%.2f] ",Ex);
printf("\n\nValor de la suma de las componenetes en ( y ) es: [%.2f] ",Ey);

printf("\n\nModulo de campo Electrico en el Origen es: ( %.2f ) ",sqrt((Ex*Ex)+(Ey*Ey)));

printf("\n\nAngulo del Campo Electrico Respecto a la Horizontal es: ( %.2f ) \n\n",atan(Ey/Ex));


return 0;
}

void Campo(float *ptrEx, float *ptrEy, int n){

float q, x, y, accEx = 0.0, accEy = 0.0;

	while( n>0 ){
	
		printf("\n\nIngrese el valor de la Carga ( q%d ): ",n);
		scanf("%f",&q);	
		printf("\n\nIngrese el valor de la Coordenada [x] de ( q%d ): ",n);
		scanf("%f",&x);
		printf("\n\nIngrese e l valor de la Coordenada [y] de ( q%d ): ",n);
		scanf("%f",&y);

		CalculaCampo(ptrEx, ptrEy, q, x, y);
		accEx += *ptrEx;
		accEy += *ptrEy;
	
		printf("\n\nValor de la Suma de las Componentes en ( x ) es : [%.2f]\n", accEx);		

		printf("\n\nValor de la Suma de las Componentes en ( y ) es : [%.2f]\n", accEy);	

		n--; //A medida que pasa va restando las cargas
	} //Fin del while():;
	
		*ptrEx = accEx;
		*ptrEy = accEy;

}//Fin de la Funcion Campo();

void CalculaCampo(float *ptrEx, float *ptrEy, float q, float x, float y){


float r2 = (x*x)+(y*y);
float modr = sqrt(r2);
float modr3 = pow(modr,3);

	*ptrEx = (k*q/modr3)*x;
	*ptrEy = (k*q/modr3)*y;

}//Fin de la funcion CalculaCampo();
