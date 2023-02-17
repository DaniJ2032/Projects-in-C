//Nombre: Marcos Gache
//Legajo:82735
//Curso: 1R5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pregunta(int a, int b)
{
	int resultado;
	printf("¿Cuanto es: %d por %d?\n",a,b);
	resultado = a*b;
	return resultado;
}

int main(void)
{ 
	printf("Multiplicacion de numeros aleatorios\n");
	
	int resultado;
	int respuesta;
	int num1, num2;
	
	srand(time(NULL));

	while(1)
	{
		num1=(rand()%9)+1;
		num2=(rand()%9)+1;
		
		resultado=pregunta(num1, num2);
		scanf("%d",&respuesta);
		while(respuesta!=resultado)
		{
			int mensaje;
			mensaje=(rand()%4)+1;
			switch(mensaje)
			{
			case 1:
				printf("¡No!\n");
				break;
				
			case 2:
				printf("¡Mal!\n");	
				break;
				
			case 3:
				printf("Intente de nuevo!\n");	
				break;
				
			case 4:
				printf("¡Recapacite el resultado!\n");	
				break;
			}	
			scanf("%d", &respuesta);
		}
		if (respuesta==resultado)
	 	{   
			int msj;
			msj=(rand()%4)+1;
			switch(msj)
			{
			case 1:
				printf("¡Excelente!\n");
				break;
			
			case 2:
				printf("¡Buen trabajo!\n");	
				break;
			
			case 3:
				printf("Siga con el buen trabajo!\n");	
				break;
			
			case 4:
				printf("¡Muy bien!\n");	
				break;
			}
		}
	}	
	return 0;
}
