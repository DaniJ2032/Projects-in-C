/****Archivo de Encabezado****/
//#ifndef QUEUE_H_INCLUDED
//#define QUEUE_H_INCLUDED

#include <stdbool.h>
#define MAXQUEUE 10

/* Ingrese el tipo de dato aqui*/
/* por ejemplo, */
typedef struct item{

long llegada; 		/* hora a la que el cliente se une a la cola */
int tiempoConsulta; /* cantidad de minutos que desea para la consulta */

} Item;//FIn de struct item

/* O typedef struct item {int gumption; int charisma;} Item; */

typedef struct node{

Item item;
struct node * siguiente;

}Nodo;//Fin de struct node

typedef struct queues{

Nodo * cabeza; /* puntero a la cabeza de la cola */
Nodo * talon; /* puntero al talon de la cola */
int items; /* cantidad de elementos en la cola */

}Queue;//Fin de struct queue


/* operacion: inicializar la cola */
/* precondicion: pq apunta a cola(queue) */
/* postcondicion: queue es inicializada para estar vacia */
void inicializaQueue(Queue * pq);


/* operacion: comprubea si queue esta llena */
/* precondicion: pq apunta a la cola previamente inicializada */
/* postcondicion: devuelve True si queue esta llena, else False */
bool queueLlena(const Queue * pq); /* OJO, estandar C99*/


/* operacion: comprueba si queue esta vacia */
/* precondicion: pq apunta a la cola previamente inicializada */
/* postcondition: devuelve True si queue esta vacia, else False */
bool queueVacia(const Queue *pq); /* OJO, estandar C99*/


/* operacion: determina cantidad de items en queue */
/* precondicion: pq apunta a la cola previamente inicializada*/
/* postcondicion: devuelve la cantidad de items en queue */
int queueCuentaItems(const Queue * pq);


/* operacion: agrega un item al talon de queue */
/* precondicion: pq apunta a la cola previamente inicializada */
/* item ser´a colocado en el talon de la cola */
/* postcondicion: si la cola no esta vacia, el item es colocado */
/* en el talon de la cola y la funcion devuelve True */
/* de lo contrario la cola no cambia y la funcion devuelve False */
bool EnQueue(Item item, Queue * pq);


/* operacion: quita elemento de la cabeza de la cola */
/* precondicion: pq apunta a la cola previamente inicializada */
/* postcondicion: si queue no esta vacia, el item en la cabeza de la */
/* cola es copiado a *pitem y luego eliminado, la funcion devuelveTrue;*/
/* si la operacion vacia la cola, entonces es reseteada a vacia*/
/* Si la cola ya esta vac´ýa, entonces no cambia y devuelve False */
bool DeQueue(Item *pitem, Queue * pq);


/* operacion: vac´ýa la cola */
/* precondicion: pq apunta a una cola previamente inicializada */
/* postcondicions: la cola fue vaciada */
void vaciarQueue(Queue * pq);

//#endif
