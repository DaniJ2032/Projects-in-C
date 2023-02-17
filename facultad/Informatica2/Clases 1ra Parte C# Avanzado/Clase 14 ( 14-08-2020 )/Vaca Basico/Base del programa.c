#include <stdio.h>
#include <stdlib.h>
/*Operacion con lista simple enlasada*/

typedef int Item; //item tipo entero

typedef struct Elemento{

Item valor;          //Variable Item -> entera
struct Elemento *siguiente; //Nodo para enlasar la lista

}Nodo; //Nombre de la estructura

Nodo *inicio=NULL; //Lo apunto a Null  el puntero inicio

/*******************PROTOTIPOS*********************/
Nodo *creaLista(Nodo *);     // Funcion Tipo Nodo que Crea una Lista    
Nodo *mostrarLista (Nodo *); //Funcion que meustra la lista
Nodo *borraNodo(Nodo *); //Funcion Borra cualquier Nodo
//Nodo *borraLista(Nodo *); // Funcion Borra la lista entera
/*****************************************************************/

int main(int argc, char *argv[]) {

int opcion;

do{
printf("\n\n**** MENU PRINCIPAL *****\n");
printf("\n ( 1 ) Crear una Lista.");	
printf("\n ( 2 ) Mostrar una Lista.");	
printf("\n ( 3 ) Borrar Nodo Dado.");	
//printf("\n ( 4 ) Borrar Lista Completa.");	
printf("\n ( 0 ) Salir del Programa.");	
printf("\n\n Ingrese una Opcion: ");	
scanf("%d",&opcion);

switch(opcion){
	
    case 1:
		inicio = creaLista(inicio);
		printf("\nLista Creada\n\n");
		break;
		
    case 2:
    	printf("\n****Listas Creadas****\n");
    	inicio = mostrarLista (inicio);
    	break;    		
	    
	case 3:    
  	    inicio = borraNodo (inicio);
    	printf("\n Nodo Borrado\n\n");
	    break;		    	
	    
	/*case 4:    
  	    inicio = borraLista (inicio);
    	printf("\n LISTA ENLAZADA BORRADA\n\n");
	    break;*/		
			
}//Fin del switch();


}while(opcion != 0 ); //Se repite hasta que sea distinto de 13
	
return 0;	
}//FIn del main();


Nodo *creaLista(Nodo *inicio){ //Funcion de tipo Nodo
	
Nodo *ptr, *nuevoNodo;
int num;

	printf("\nIngrese el Valor del Nodo: ");
	scanf("%d",&num);	
		
	nuevoNodo =(Nodo *) malloc(sizeof(Nodo)); //Le asignamos memoria al Nuevo Nodo
	nuevoNodo->valor = num; // cargamos lo que ingresamos en Num a Nuevo Nodo

		if(inicio == NULL){
			nuevoNodo->siguiente=NULL; //El ultimo nodo lo apuntamos a NULL
		  	inicio=nuevoNodo;	//Iniicio a Nuevo Nodo  
		}
		else{

		 	ptr=inicio;
		 	while(ptr->siguiente != NULL) 
				ptr = ptr->siguiente;//Cunado ya tenemos creado listas se va hasta el final para agrgar una nueva 
			//Fin del while();

		nuevoNodo->siguiente = NULL;
		ptr->siguiente=nuevoNodo; 	

		}//Fin del if() else;
		
return inicio; //Retorno un valor de tipo Nodo	

}//Fin de la Funsion creaLista();


Nodo *mostrarLista( Nodo *inicio ){

Nodo *ptr;
ptr = inicio;

while(ptr != NULL){
	
	printf("\n Valor es: %d", ptr->valor);
	ptr = ptr ->siguiente;
}	
return inicio;	
}
	
Nodo *agregaCabeza (Nodo *inicio){
	
Nodo *nuevoNodo;
int num;

printf("\n Ingrese el Valor del Nodo Cabeza: ");
scanf("%d",&num);

nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
nuevoNodo->valor = num;
nuevoNodo->siguiente = inicio;
inicio = nuevoNodo;

return inicio;	
}


Nodo *borraNodo(Nodo *inicio){
	
Nodo *ptr, *preptr;
int val; 
printf("\nIngrese el valor del Nodo que desea Borrar: ");
scanf("%d",&val); //Ingreso el valor del Nodo que quiero borrar

ptr = inicio; //coloco el puntero al inicio

	if( ptr -> valor == val ){

		inicio = inicio -> siguiente;
		free(ptr);
		return inicio;	
	}
	else{

	  	while (ptr -> valor != val){ //si no es el encabezado lo busca
	  		
	  		preptr = ptr;
	  		ptr = ptr -> siguiente;
	  		//fin del while
		  }	
		
		preptr -> siguiente = ptr -> siguiente; // debe enlazar el dato anterior con el posterior
		free (ptr); //borra el nodo cuando lo encuentra
		return inicio;
	}//Fin del if(); else		
//fin de funcion Nodo borraNodo()	
}

/*Nodo *borraLista(Nodo *inicio){

Nodo *ptr;

	if(inicio != NULL){ //Si la lista no esta vacia
		
		ptr = inicio;
		while (ptr != NULL){
			
		printf("\n ( %d ) Esta por ser Borrado\n", ptr -> valor);//apunta a la cabezera
		inicio = borraCabeza(ptr); //borra la cabezera y desp repite lo msimo con la nueva
			ptr = inicio;			   // y asi borra toda la lista
		//Fin del while	
		}		
	//Fin del if()	
	}
return inicio;
//fin de funcion Nodo borraLista()	
}
*/

