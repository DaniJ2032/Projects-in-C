/* Ejemplo de lista doblemente Enlazada
   Autor: Daniel Juarez 
   Año: Julio 2020 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{

	struct node *siguiente; // |anterior|<-|Nodo|->|siguiente|
	struct node *anterior;
	int dato;	
}Nodo; //Nombre de nuestra 	Estructura

Nodo *inicio = NULL; //Inicio un puntero de tipo Nodo struct 

/* **********PROTOTIPO DE FUNCIONES********* */
Nodo *creaListaDoble (Nodo* );
Nodo *muestraListaDoble (Nodo* );
Nodo *insertaCabeza (Nodo* );
Nodo *insertaFinal (Nodo* );
Nodo *insertaAntes (Nodo* );
Nodo *insertaDespues (Nodo* );
Nodo *borraCabeza (Nodo* );
Nodo *borraFinal (Nodo* );
Nodo *borraAntes (Nodo* );
Nodo *borraDespues (Nodo* );
Nodo *borraListaDoble (Nodo* );
/* ***************************************** */

int main(int argc, char *argv[]) {
	
int opc; // Variable para las Opciones

	do{ // Inicio del Menu Principal
		
		printf("******************MENU PRINCIPAL******************\n\n");
		printf("( 1 ) Crea una lista Doble Enlazada\n");
		printf("( 2 ) Mostrar la lista Creada\n");
		printf("( 3 ) Agrega un Nodo al Principio\n");
		printf("( 4 ) Agrega un Nodo al Final\n");
		printf("( 5 ) Agregar un Nodo Antes de un Nodo Dado\n");
		printf("( 6 ) Agregar un Nodo Despues de un Nodo Dado\n");
		printf("( 7 ) Borra el Nodo Cabecera\n");
		printf("( 8 ) Borra el Nodo del Final\n");
		printf("( 9 ) Borra un nodo Previo a un Nodo Dado\n");
		printf("( 10 )Borra un Nodo Posterior a un Nodo Dado\n");
		printf("( 11 )Borra la Lista Completa\n");
		printf("( 12 )Salir del Programa\n");
		printf("***************************************************\n");
		printf("Ingrese una Opcion: ");
		scanf("%d",&opc);

		switch (opc){
		
		case 1: 
			inicio = creaListaDoble(inicio);
			printf("\n Lista Doblemente Enlazada Creada con Exito\n\n");
			break;
			
		case 2: 
			inicio = muestraListaDoble (inicio);
			break;
			
		case 3: 
			inicio = insertaCabeza(inicio);
			break;
			
		case 4: 
			inicio = insertaFinal(inicio);
			break;

		case 5: 
			inicio = insertaAntes(inicio);
			break;	
			
		case 6: 
			inicio = insertaDespues(inicio);
			break;	
			
		case 7: 
			inicio = borraCabeza(inicio);
			break;			
			
		case 8: 
			inicio = borraFinal(inicio);
			break;
			
		case 9: 
			inicio = borraAntes(inicio);
			break;
			
		case 10: 
			inicio = borraDespues(inicio);
			break;
			
		case 11: 
			inicio = borraListaDoble(inicio);
			printf("\n***SE ELIMINO LA LISTA DOBLE POR COMPLETO***\n\n");
			break;			
		//fin del switch ()	
		}
			
			
	//fin del do while()		
	}while(opc !=12);
	getchar();
//fin del main () 	
return 0;
}

/*Crea un Puntero a Nodo que tiene Doble enlace*/
Nodo *creaListaDoble (Nodo *inicio){
	
Nodo *nuevoNodo, *ptr;
int num;
    
    printf("Ingrese  ( -1 ) para finalizar la ceracion de la Lista\n");
	printf("Ingrese el Nodo: \n");
	scanf("%d",&num);
	
	while (num != -1){
		
		if (inicio == NULL){
			
			nuevoNodo = (Nodo*) malloc(sizeof(Nodo)); //reserva memoria para el nuevo nodo creado 
			nuevoNodo -> anterior = NULL;
			nuevoNodo -> dato = num;
			nuevoNodo -> siguiente = NULL;
			inicio = nuevoNodo;	
		}
		else{
			
			ptr = inicio; //posiciono el puntero en la cabecera
			nuevoNodo = (Nodo*) malloc(sizeof(Nodo)); //reserva memoria para los Nodos que se van creando
			nuevoNodo -> dato = num; //cargo el dato en el nuevo nodo
				
			while(ptr -> siguiente != NULL) //recorre la lista hasta llegar al ultimo Nodo
				ptr = ptr -> siguiente;
			
			ptr -> siguiente = nuevoNodo; //Inserta el nuevo Nodo al final
			nuevoNodo -> anterior = ptr; //Nuevo nodo apunta a su Predecesor
			nuevoNodo -> siguiente = NULL; //Nuevo nodo esta al final y apunta a NULL
		//fin del if() else	
		}
		
	printf("\n Ingresa un nuevo Dato: "); //si ingresa distinto de ( -1 ) cre aun nuevo Nodo
	scanf("%d",&num);	
	//fin del while 	
	}

	
return inicio; //devuelve la direccion del Nodo puntero	
//fin de la funcion creaListaDoble()	
}

/* Muestra los valores de la Lista Creada */
Nodo *muestraListaDoble (Nodo *inicio){
	
	if (inicio == NULL){
		printf("La Lista se encuentra Vacia\n\n");		
	}
	else{
		
		Nodo *ptr;
		ptr = inicio;	
		
			while(ptr != NULL){
				
				printf("Valor es: ( %d )\n", ptr -> dato);
				ptr = ptr -> siguiente;
			//Fin del While()	
			}
	//fin del if()else 	
	}
	
return inicio; 	
//fin de la funcion meustraListaDoble()	
}

/* Incerta uns Nueva Cabecera */ 
Nodo *insertaCabeza (Nodo *inicio){
	
	Nodo *nuevoNodo;
	int num;
	
	printf("\nIngrese el Nuevo valor de Cabecera: ");
	scanf("%d",&num); //Ingreso el nuevo valor del Nodo 
	
	nuevoNodo = (Nodo *) malloc(sizeof(Nodo));
	nuevoNodo -> dato = num;
	inicio -> anterior = nuevoNodo; //En vez de apuntar a NULL la cabecera actual apunta al nuevo Nodo 
 	nuevoNodo -> siguiente = inicio; //El nuevo Nodo pasa a ser la cabecera y apunta a la vieja cabecera
	nuevoNodo -> anterior = NULL; // El puntero a la posicion anterior de la cabecera apunta a NULL
	inicio = nuevoNodo;
	
return inicio;	
//fin de la funcion insertaCabeza()	
}

/* Inserta un Nodoo al Final */
Nodo *insertaFinal (Nodo *inicio){
	
	Nodo *ptr, *nuevoNodo;
	int num;
	
	printf("\nIngrese el Nuevo Nodo para el Final: ");
	scanf("%d",&num);
	
	nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
	nuevoNodo -> dato = num;
	ptr = inicio;
	
		while(ptr -> siguiente !=NULL) //Busca el Nodo que se posiciona al final
		
			ptr = ptr -> siguiente;
		//fin del while()
		
	ptr -> siguiente = nuevoNodo; //Asigan el neuvo valor al Nodo del final
	nuevoNodo -> anterior = ptr; // Nuevo nodo apunta al su predecesor
	nuevoNodo -> siguiente = NULL; //nuevo nodo lo apunto a NULL
			
return inicio;	
//fin de la funcion insertaFinal()	
}
	
/* Inserta un Nodo antes de un Nodo Contiguo */	
Nodo *insertaAntes (Nodo *inicio){

		Nodo *nuevoNodo, *ptr;
		int num, val;
		
		printf("\nInserte el valor del Nuevo Nodo: ");
		scanf("%d",&num);
		printf("\nAhora inserte el valor del Nodo Posterior: ");
		scanf("%d",&val);
		
		nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
		nuevoNodo -> dato = num;
		ptr = inicio;
		
			while(ptr -> dato != val) //Rrecorre la lista hasta encpontrar el Nodo posterior
				ptr = ptr -> siguiente;
			//Fin del while()
		nuevoNodo -> siguiente = ptr; //El puntero queda acontinuacion del nuevo Nodo	
		nuevoNodo -> anterior = ptr -> anterior; //El enlace previo del nuevo Nodo		
												 //apunta al enlace previo del puntero
		ptr -> anterior -> siguiente = nuevoNodo;//El Nodo anterior al puntero debe poner su puntero siguiente al nuevo Nodo	
		ptr -> anterior = nuevoNodo; //El puntero anterior debe apuntar al nuevo Nodo
		
return inicio;
//fin de la Funcion insertaAntes()
}

/* Inserta un Nodo despues de un Nodo Contiguo */
Nodo *insertaDespues (Nodo *inicio){

	Nodo *nuevoNodo, *ptr;
	int num, val;
	
	printf("\nInserte el valor del nuevo Nodo: ");
	scanf("%d",&num);
	printf("\nInserte el valor del Nodo Contiguo: ");
	scanf("%d",&val);
	
	nuevoNodo = (Nodo *)malloc( sizeof( Nodo ));
	nuevoNodo -> dato = num;
	ptr = inicio;
	
		while(ptr -> dato !=val)
			ptr = ptr -> siguiente;
		//fin del While()
	nuevoNodo -> anterior = ptr;
	nuevoNodo -> siguiente = ptr -> siguiente;
	ptr -> siguiente -> anterior = nuevoNodo;
	ptr -> siguiente = nuevoNodo;
	
return inicio;
//fin de la Funcion insertaDespues()
}	
	
/* Borra el Nodo de la Cabecera */
Nodo *borraCabeza (Nodo *inicio){
	
	Nodo *ptr;
	ptr = inicio;
	
		if( ptr -> siguiente != NULL ){ 
			
			inicio = inicio -> siguiente; //Segundo Nodo pasa a ser la Cabeza
			inicio -> anterior = NULL; //Segundo Nodo pone su puntero a NULL
			free (ptr); //La vieja cabecera queda desligada y se la puede borrar
		}
	    else{
			
			inicio = NULL;
			free(ptr);
		//Fin del if()else	
		}
	
return inicio;
//fin de la Funcion borraCabeza()
}	

/* Borra el Nodo del Final */ 
Nodo *borraFinal (Nodo *inicio){
	
	Nodo *ptr;
	ptr = inicio;
	
		while( ptr -> siguiente != NULL )
			ptr = ptr -> siguiente; //Busco el Nodo final
		//fin del while()
	
	ptr -> anterior -> siguiente = NULL; //Ahora el Nodo anterior apunta a NULL
	free(ptr); //Libero el Ultimo Nodo
	
return inicio;
//fin de la Funcion borraFinal()
}

/* Borra un Nodo antes de un Nodo contiguo dado */ 
Nodo *borraAntes (Nodo *inicio){

	Nodo *ptr, *temp;
	int val;
	
	printf("\n Ingrese el valor posterior al Nodo a ser Eliminado: ");
	scanf("%d",&val);
	ptr = inicio; 
	
		while( ptr -> dato != val)
			ptr = ptr -> siguiente;
		//fin del while()
	
	temp = ptr -> anterior;
		
		if( temp == inicio ) // si es el nodo es el de cabecera
			inicio = borraCabeza(inicio); //paso el valor y lo borro
		
		else{ //si es otro valor que no sea de cabecera
			
			ptr -> anterior = temp -> anterior; //cargo el valor del nodo psoterior a ptr
			temp -> anterior -> siguiente = ptr; //Reacomodo la lista
		//Fin del if()else 	
		}
	
		free( temp ); //livero el Nodo
		
return inicio;
//fin de la Funcion borraAntes()
}

/* Borra un Nodo despues de un Nodo contiguo dado */  
Nodo *borraDespues (Nodo *inicio){
	
	Nodo *ptr, *temp;
	int num;
	
	printf("\nInserte el valor del Nodo contiguo a ser borrado: ");
	scanf("%d",&num);
	ptr = inicio;
		
		while( ptr -> dato != num )
			ptr = ptr -> siguiente;
		//fin del while()
	
	temp = ptr -> siguiente; //cuando encuentro el valor lo almacena en temp
	ptr -> siguiente = temp -> siguiente; //cargo el dato del Nodo Siguiente
	temp -> siguiente -> anterior = ptr; //Reacomodo la lista
	free( temp ); //Livero el Nodo
	
return inicio;
//fin de la Funcion borraDespues()
}

/* Borra la lista Doble Completa */  
Nodo *borraListaDoble (Nodo *inicio){
	
	while( inicio != NULL ) //Hasta que Inicio no sea NULL
		inicio = borraCabeza(inicio); //Se va borrando las cabeceras nuevas que se van cargando
	//Fin del while()
	
return inicio;
//fin de la Funcion borraListaDoble()
}
//Fin del Programa
