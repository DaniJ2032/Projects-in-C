#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

float a,b,c,d;

printf("Nombre: Juarez Daniel Alejandro\nCurso: 1R5\nLegajo: 79111\nciclo lectivo: 2019 \n\n");	
printf("       **********************           \n       *CALCULADORA DE IMC!!*           \n       **********************           \n");	
printf("esta calculadora nos permitira calcular el indice\nde masa corporal de tu cuerpo:\n\n");

printf("Introduzca su Peso:"); scanf("%f",&a);

printf("Introduzca su altura:"); scanf("%f",&b);

d=b*b; c=a/d;

printf("\n                   *                   \n                   *                   \n                   *                   \n");
printf("***************************************\n*      TABLA DE INDICE DE IMC         *\n***************************************\n");
printf("*      DESCRIPCION      *      IMC    *\n***************************************\n");
printf("*Desnutricion Severa:   * <16         *\n*Desnutricion Moderada: * 16.1 - 18.4 *\n*Bajo peso:             * 18.5 - 22   *\n*Peso normal:           * 22.1 - 24.9 *\n");	
printf("*sobrepeso:             * 25 - 29.9   *\n*obesidad tipo I:       * 30 - 34.9   *\n*obesidad tipo II:      * 35 - 39.9   *\n*obesidad tipo III:     * >40         *\n");	
printf("***************************************\n                   *                   \n                   *                   \n\n");


printf("El Resultado de su IMC es: ( %.2f )\n\nRevise su resultado y compare su IMC con la tabla\nde esa menra sabra entre que categoria se encuentra.\n\n",c);

	return 0;
}
