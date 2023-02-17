/*Pasos por Referencia y Valor*/


void discValor(float a, float b, float c, float D); //Paso pro Valor
void discRef(float* a, float* b, float* c, float* D); //Paso por Referencia

#include <stdio.h>

int main(int argc, char *argv[]) {

float a = 1, b = 1, c = 1, D = 0;

	printf("\n\nEl Valor de ( D ) Antes de entrar a discValor(); es: ( %.2f ) \n\n", D);
	discValor( a, b, c, D);	
	printf("El Valor de ( D ) al Slair de discValor(); es: ( %.2f ) \n\n", D); //Pierde el valor porque fue pasado por valor
	discRef( &a, &b, &c, &D);
	printf("El Valor de ( D ) al Slair de discRef(); es: ( %.2f ) \n\n", D); //El valor se modifico	
	getchar();

return 0;
} //Fin del main();

void discValor(float a, float b, float c, float D){ //D adqueire un valor dentro de esta funcion

	D = (b*b)-(4*a*c);
	printf("El Valor de ( D ) dentro de discValor();  y antes de Entrar a discRef(); es: ( %.2f ) \n\n", D);

}//Fin de la Funcion discValor();

void discRef(float* a, float* b, float* c, float* D){

	*D = ((*b) * (*b))-(4 * (*a) * (*c));  // -> el "*" de Multiplicar tambien es un operadpor de indireccion por ende los separamos entre () para no confundir, ya que estamos pasando la direccion de los valores de a,b,c,D
	printf("El Valor de ( D ) dentro de discRef(); es: ( %.2f )\n\n", *D);

}//Fin de la funcion discValor();
