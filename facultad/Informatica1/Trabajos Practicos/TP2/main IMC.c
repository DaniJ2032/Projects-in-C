#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

float a,b,c,d;
	
printf("       **********************           \n");	
printf("       *CALCULADORA DE IMC¡¡*           \n");	
printf("       **********************           \n");

printf("esta calculadora nos permitira calcular el indice\nde masa corporal de tu cuerpo:\n\n");

printf("Introduzca su Peso:");
scanf("%f",&a);
printf("Introduzca su altura:");
scanf("%f",&b);
d=b*b;
c=a/d;

printf("\n                   *                   \n");
printf("                   *                   \n");
printf("                   *                   \n");
printf("***************************************\n");	
printf("*      TABLA DE INDICE DE IMC         *\n");	
printf("***************************************\n");
printf("*      DESCRIPCION      *      IMC    *\n");
printf("***************************************\n");
printf("*Desnutricion Severa:   * <16         *\n");
printf("*Desnutricion Moderada: * 16.1 - 18.4 *\n");	
printf("*Bajo peso:             * 18.5 - 22   *\n");
printf("*Peso normal:           * 22.1 - 24.9 *\n");
printf("*sobrepeso:             * 25 - 29.9   *\n");	
printf("*obesidad tipo I:       * 30 - 34.9   *\n");
printf("*obesidad tipo II:      * 35 - 39.9   *\n");
printf("*obesidad tipo III:     * >40         *\n");
printf("***************************************\n");
printf("                   *                   \n");
printf("                   *                   \n\n");

printf("El Resultado de su IMC es: ( %.2f )\n\n",c);
printf("Revise su resultado y compare su IMC con la tabla\nde esa menra sabra entre que categoria se encuentra.\n\n");

	return 0;
}
