/* Ejemplo de cola */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{

	int dato;
	struct node *siguiente;
	
}Nodo;

typedef struct queue{
	
	Nodo *cabeza; //Apunta a dos Nodos
	Nodo *talon;
	
}Cola;

Cola *q; //Puntero Tipo Cola
/* ******PROTOTIPOS DE FUNCIONES****** */
void crearCola (Cola *);                // Crea Cola sin inicializarla
Cola *Agregar (Cola *, int);            // Inserta un Elemento
Cola *RetirarElemento (Cola *);         // Retirar un Elemento
Cola *Despliega (Cola *);               // Muestra los Elementos de la Cola
int peek(Cola *);                       // Muestra la Cabeza de la Cola
/* ********************************** */

int main( int argc, char *argv[] ){
	
	int val, opcion;
	crearCola (q); // Crea una Cola Vacia
	
	do{
		printf("***MENU PRINCIPAL***\n");
		printf("( 1 ) Agregar\n");
		printf("( 2 ) Retirar\n");
		printf("( 3 ) Ojear\n");
		printf("( 4 ) Desplegar\n");
		printf("( 5 ) Salir\n");
		printf("\nIngrese su Opcion: ");
		scanf("%d",&opcion);
		
		switch ( opcion ){
			
			case 1:
				
				printf("\nIngrese un Numero a Agregar en la Cola: ");
				scanf("%d",&val);
				q = Agregar(q, val);
				
			break;

			case 2: 				
				q = RetirarElemento(q);				
			break;			
			
			case 3:
				val = peek(q);
				
				if(val != -1)
					printf("\nEl Valor del Frente de la Cola es: ( %d )", val);
			break;			
			
			case 4: 
				q = Despliega(q);
			break;			
		// Fin del switch()	
		}		
	// Fin del do While();	
	} while(opcion != 5);
		//getchar();
//fin del main	
return 0;	
}

/*Crea la Cola*/
void crearCola(Cola *q){
 	
	q -> talon = NULL; //Inicializa Nodos Vacios
	q -> cabeza = NULL;
//Fin de la funsion crearCola();	
}
	
/*Inserta un Elemento en la Cola*/
Cola *Agregar (Cola *q, int val){
 	
	Nodo *ptr;
	
	ptr = (Nodo *) malloc(sizeof(Nodo));
	ptr -> dato = val;
	
		if( q -> cabeza == NULL){
			
			q -> cabeza = ptr;
			q -> talon = ptr;
			q -> cabeza -> siguiente = q -> talon -> siguiente = NULL;		
		}
		else{
			
			q -> talon -> siguiente = ptr;
			q -> talon = ptr;
			q -> talon -> siguiente = NULL;			
		//fin del if() else	
		}
//Fin de la Funcion Agregar();	
return q;		
}

/*Muestra la Cola Completa*/
Cola *Despliega(Cola *q){
 	
	Nodo *ptr;
	ptr = q -> cabeza;
	
		if( ptr == NULL ){
			printf("Cola Vacia\n\n");
		}
		else{
			printf("\n");
			
				while( ptr != q -> talon ){
					
					printf("( %d )\n", ptr -> dato);
					ptr = ptr -> siguiente;
				// Fin del while();	
				}
				
			printf("( %d )\n", ptr -> dato);			
		//Fin del if() else	
		}
		
return q;		
//Fin de la Cola Despleiga();	
}
	
/*Retira un Elemento de la Cola*/
Cola *RetirarElemento(Cola *q){
	
	Nodo *ptr;
	
	ptr = q -> cabeza;
	
		if( q -> cabeza == NULL ){
			
			printf("\nUnderflow\n");
		}
		else{
			
			q -> cabeza = q -> cabeza -> siguiente;
			printf("\nValor que sera Eliminado es: ( %d )", ptr -> dato);
			free (ptr);
		//Fin del if() else	
		}
		
return q;
//Fin de la funsion RetirarElemento()
}

/*Colocar Valor en al Cabeza*/
int peek(Cola *q){
	 
	if(q -> cabeza == NULL){
		
		printf("\nNo hay Elementos en la Cola\n");
		return -1;		
	}
	else{ 
	   return q -> cabeza -> dato;
	//fin del if()else
	}   
//Fin de la funcion peek();	 
}
