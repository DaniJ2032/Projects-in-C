//Nombre: Marcos Gache
//Legajo: 82735
//Curso: 1r5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int suma(int a, int b)
{
	int resultado;
	printf("¿Cuanto es: %d mas %d?\n",a,b);
	resultado = a+b;
	return resultado;
}

int resta(int a, int b)
{
	int resultado;
	printf("¿Cuanto es: %d menos %d?\n",a,b);
	resultado = a-b;
	return resultado;
}

int multiplicacion(int a, int b)
{
	int resultado;
	printf("¿Cuanto es: %d por %d?\n",a,b);
	resultado = a*b;
	return resultado;
}

int main(void)
{ 
	int resultado, respuesta, operacion;
	int i=0;
	float porcentaje;
	int num1, num2;
	float correctas=0;
	float respuestas=0;
	int siguiente=0;
	int nivel;
	int potencia=1;
	
	srand(time(NULL));
	
	while(1)
	{
		printf("Operaciones aritmeticas con numeros aleatorios\n");
		i=0;
		siguiente=0;
		
		printf("Ingrese un nivel de dificultad\n");
		scanf("%d",&nivel);
		
		while(nivel>0){
			potencia=potencia*10;
			nivel--;
		}
		
		while(i<10)
		{
			num1=(rand()%(potencia-1))+1;
			num2=(rand()%(potencia-1))+1;
			
			printf("Elija una operacion aritmetica\n");
			scanf("%d",&operacion);
			if(operacion==4)
			{
				operacion=(rand()%3)+1;
			}
			if(operacion==1)
			{
				resultado=suma(num1, num2);
			}
			if(operacion==2)
			{
				resultado=resta(num1, num2);
			}
			if(operacion==3)
			{
				resultado=multiplicacion(num1, num2);
			}
			
			scanf("%d",&respuesta);
			respuestas++;
			i++;
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
				if(respuestas<10)
				{
					scanf("%d",&respuesta);
					respuestas++;
					i++;
				}
				else
				{
					respuesta=resultado;
					siguiente=1;
				}
			}
			if (respuesta==resultado && siguiente==0)
			{   
				correctas++;
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
		porcentaje=(correctas/respuestas)*100;
		if (porcentaje<75)
		{
			printf("");
			printf("Pidale ayuda adicional a su maestro\n\n\n");
		}
		else
		{
			printf("¡Felicitaciones, esta listo para pasar al siguiente nivel!\n\n\n");
		}
	}	
}
