/* compilar con queue.c y queue.h*/
#include <stdio.h>
#include <stdlib.h> /* para rand() y srand() */
#include <time.h> /* para time() */
#include "queue.h" /* no olvidar cambiar Item typedef */
#define MIN_POR_HR 60.0
bool nuevoCliente(double x); /* ¿Llego un nuevo cliente? */
Item tiempoCliente(long cuando); /* setea los parametros del cliente */
int main()
{
	Queue line;
	Item temp; /* datos del nuevo cliente */
	int horas; /* horas de simulacion */
	int porhora; /* cantidad promedio de llegadas por hora */
	long ciclo, cicloLimite; /* contador, limite */
	long abandonos = 0; /* abandonos por estar completa la fila */
	long clientes = 0; /* clientes en la cola */
	long atendidos = 0; /* atendidos durante la simulacion */
	long sum_line = 0; /* longitud de la fila*/
	int tiempoEspera = 0; /* tiempo hasta ser atendido */
	double min_por_cliente; /* tiempo promedio entre arribos */
	long lineaEspera = 0; /* tiempo acumulativo en la fila */
	inicializaQueue(&line);
	srand(time(0)); /* inicializacion aleatoria de rand() */
	puts("Caso de estudio: Simulacion de arribo de clientes a una consulta");
	puts("Ingrese las horas de simulacion:");
	scanf("%d", &horas);
	cicloLimite = MIN_POR_HR * horas;
	puts("Ingrese la cantidad promedio de clientes por hora:");
	scanf("%d", &porhora);
	min_por_cliente = MIN_POR_HR / porhora;
	for (ciclo = 0; ciclo < cicloLimite; ciclo++)
	{
		if (nuevoCliente(min_por_cliente))
		{
			if (queueLlena(&line))
				abandonos++;
			else
			{
				clientes++;
				temp = tiempoCliente(ciclo);
				EnQueue(temp, &line);
			}
		}
		if (tiempoEspera <= 0 && !queueVacia(&line))
		{
			DeQueue (&temp, &line);
			tiempoEspera = temp.tiempoConsulta;
			lineaEspera += ciclo - temp.llegada;
			atendidos++;
		}
		if (tiempoEspera > 0)
			tiempoEspera--;
		sum_line += queueCuentaItems(&line);
	}
	if (clientes > 0)
	{
		printf(" clientes aceptados: %ld\n", clientes);
		printf(" clientes atendidos: %ld\n", atendidos);
		printf(" abandonos: %ld\n", abandonos);
		printf(" largo promedio de la cola: %.2f\n", (double) sum_line / cicloLimite);
		printf(" tiempo promedio de espera: %.2f minutes\n", (double) lineaEspera / atendidos);
	}
	else
		puts("Sin clientes!");
	vaciarQueue(&line);
	puts("Fin");
	return 0;
}
/* x = tiempo promedio entre clientes en mintuos*/
/* devuelve un valor true si el cliente llega en estos minutos */
bool nuevoCliente(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}
/* cuando es la hora a la que llega el cliente */
/* la funcion devuelve una estructura Item con el tiempo de llegada*/
/* seteada a cuando y el tiempo de consulta seteado a un valor aleatorio*/
/* entre 1 y 3 */
Item tiempoCliente(long cuando)
{
	Item client;
	client.tiempoConsulta= rand() % 3 + 1;
	client.llegada = cuando;
	return client;
}

