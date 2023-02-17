
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pregunta(int a, int b)
{
	int resultado;
	printf("Cuanto es: %d por %d?\n",a,b);
	resultado = a*b;
	return resultado;
}

int main(void)
{ 
	printf("Multiplicacion de numeros aleatorios\n");
	int resultado1;
	int respuesta;
	int i;
	int numero1, numero2;
	
	
		
	srand(time(NULL));
	
	i=0;
	while(i<20)
	{
	    numero1=(rand()%9)+1;
		numero2=(rand()%9)+1;
		
		resultado1=pregunta(numero1, numero2);
		scanf("%d",&respuesta);
		while(respuesta!=resultado1)
		{
			printf("NO, INTENTELO DE NUEVO\n");
			scanf("%d", &respuesta);
		}
		if (respuesta==resultado1)
		{
			printf("¡Muy bien!\n");
			i++;
		}
	}
	
	return 0;
}

