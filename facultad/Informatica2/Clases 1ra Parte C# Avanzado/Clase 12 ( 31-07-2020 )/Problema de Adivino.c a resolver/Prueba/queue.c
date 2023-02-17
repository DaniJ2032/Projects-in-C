/* queue.c Funciones utilizadas-- */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
/* funciones locales*/
static void cargarNodo(Item item, Nodo * pn);
static void cargarItem(Nodo * pn, Item * pi);
void inicializaQueue(Queue * pq)
{
	pq->cabeza = pq->talon = NULL;
	pq->items = 0;
}
bool queueLlena(const Queue * pq)
{
	return pq->items == MAXQUEUE;
}
bool queueVacia(const Queue * pq)
{
	return pq->items == 0;
}
int queueCuentaItems(const Queue * pq)
{
	return pq->items;
}
bool EnQueue(Item item, Queue * pq)
{
	Nodo * pnew;
	if (queueLlena(pq))
		return false;
	pnew = (Nodo *) malloc( sizeof(Nodo));
	if (pnew == NULL)
	{
		fprintf(stderr,"No se pudo reservar memoria! \n");
		exit(1);
	}
	cargarNodo(item, pnew);
	pnew->siguiente = NULL;
	if (queueVacia(pq))
		pq->cabeza = pnew; /* item va a cabeza */
	else
		pq->talon->siguiente = pnew; /* enlace al final de la cola */
	pq->talon = pnew; /* guarda ubicacion del talon */
	pq->items++; /* agregar un item a la cola*/
	return true;
}
bool DeQueue(Item * pitem, Queue * pq)
{
	Nodo * pt;
	if (queueVacia(pq))
		return false;
	cargarItem(pq->cabeza, pitem);
	pt = pq->cabeza;
	pq->cabeza = pq->cabeza->siguiente;
	free(pt);
	pq->items--;
	if (pq->items == 0)
		pq->talon = NULL;
	return true;
}
/* vaciar la cola */
void vaciarQueue(Queue * pq)
{
	Item dummy;
	while (!queueVacia(pq))
		DeQueue(&dummy, pq);
}
/* funciones locales */
static void cargarNodo(Item item, Nodo * pn)
{
	pn->item = item;
}
static void cargarItem(Nodo * pn, Item * pi)
{
	*pi = pn->item;
}
