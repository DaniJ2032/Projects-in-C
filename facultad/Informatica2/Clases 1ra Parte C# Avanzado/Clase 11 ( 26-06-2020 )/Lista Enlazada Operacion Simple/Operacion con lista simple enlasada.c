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
Nodo *agregaCabeza (Nodo *); //Funcion Crear un Nodo de Cabezera
Nodo *insertarCola (Nodo *); //Funcion Crear un Nodo de Cola
Nodo *insertaAntes (Nodo *); //Funcion Incerta un Nodo Antes
Nodo *insertaDespues (Nodo *); //Funcion Incerta un Nodo Despues
Nodo *borraCabeza (Nodo *); //Funcion Borra Nodo de Cabezera
Nodo *borraCola(Nodo *); //Funcion Borra el Nodo de la Cola
Nodo *borraNodo(Nodo *); //Funcion Borra cualquier Nodo
Nodo *borraDespues(Nodo *); // Funcion Borra el Nodo siguiente
Nodo *borraLista(Nodo *); // Funcion Borra la lista entera
Nodo *ordenaLista(Nodo *); // Funvcion que ordena la lista entera

int main(int argc, char *argv[]) {

int opcion;

do{
printf("\n\n**** MENU PRINCIPAL *****\n");
printf("\n 1: Crear una Lista.");	
printf("\n 2: Mostrar una Lista.");	
printf("\n 3: Agrega Nodo Cabecera.");	
printf("\n 4: Agrega Nodo Cola.");	
printf("\n 5: Agrega Nodo Antes de un Nodo Dado.");	
printf("\n 6: Agrega Nodo Despues de un Nodo Dado.");	
printf("\n 7: Borrar Nodo Cabecera.");	
printf("\n 8: Borrar Nodo Cola.");	
printf("\n 9: Borrar Nodo Dado.");	
printf("\n10: Borrar Nodo Contiguo a uno Dado.");	
printf("\n11: Borrar Lista Completa.");	
printf("\n12: Ordenar la Lista.");	
printf("\n13: Salir del Programa.");	
printf("\n\n\t\t Ingrese una Opcion: ");	
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
    	inicio = agregaCabeza (inicio);
    	printf("\nCabecera Agregada\n\n");
	    break;
	    
	case 4:
    	inicio = insertarCola (inicio);
    	printf("\n Cola Incertada\n\n");
	    break;
	
	case 5:
    	inicio = insertaAntes (inicio);
    	printf("\n Nodo Incertado Antes\n\n");
	    break;	
	
	case 6:
    	inicio = insertaDespues (inicio);
    	printf("\n Nodo Incertado Despues\n\n");
	    break;	
	    
	case 7:
    	inicio = borraCabeza (inicio);
    	printf("\n Nodo de Cabezera Borrado\n\n");
	    break;	
		    
	case 8:    
  	    inicio = borraCola (inicio);
    	printf("\n Nodo de Cola Borrado\n\n");
	    break;	
	    
	case 9:    
  	    inicio = borraNodo (inicio);
    	printf("\n Nodo Borrado\n\n");
	    break;	
	    
	case 10:    
  	    inicio = borraDespues (inicio);
    	printf("\n Nodo Contiguo Borrado\n\n");
	    break;	
	    
	case 11:    
  	    inicio = borraLista (inicio);
    	printf("\n LISTA ENLAZADA BORRADA\n\n");
	    break;	
	    
	case 12:    
  	    inicio = ordenaLista (inicio);
    	printf("\n ***LISTA ORDENADA***\n\n");
	    break;	
			
}


}while(opcion != 13 ); //Se repite hasta que sea distinto de 13
	
return 0;	
}

Nodo *creaLista(Nodo *inicio){ //Funcion de tipo Nodo
	
Nodo *ptr, *nuevoNodo;
int num;
printf("\n Ingrese -1 para Terminar. ");
printf("\n Ingrese el Valor del Nodo: ");
scanf("%d",&num);
	
	while(num != -1){
		
		nuevoNodo =(Nodo *) malloc(sizeof(Nodo)); //Le asignamos memoria al Nuevo Nodo
		nuevoNodo->valor = num; // cargamos lo que ingresamos en Num a Nuevo Nodo
		if(inicio == NULL){
		  nuevoNodo->siguiente=NULL; //El ultimo nodo lo apuntamos a NULL
		  inicio=nuevoNodo;	//Iniicio a Nuevo Nodo
		  
		}else{
		 ptr=inicio;
		 while(ptr->siguiente != NULL) 
		 ptr = ptr->siguiente; //Cunado yta tenemos creado listas se va hasta el final para agrgar una nueva 
		//fin del While
		
		nuevoNodo->siguiente = NULL;
		ptr->siguiente=nuevoNodo; 	
		}
		printf("\n Ingrese el Valor del Nodo: ");
		scanf("%d",&num); //Seguira cargando hasta que num valga  ( -1 )	
	}
    //Fin del While
 return inicio; //Retorno un valor de tipo Nodo	
}

Nodo *mostrarLista(Nodo *inicio){

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

Nodo *insertarCola (Nodo *inicio){
	 
  Nodo *ptr, *nuevoNodo;	
  int num;	
  
  printf("\n Ingrese el Valor del Nodo: ");
  scanf("%d",&num);
  nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
  
  nuevoNodo->valor = num;
  nuevoNodo->siguiente = NULL;
  ptr = inicio;
  
  while(ptr-> siguiente != 	NULL)
    ptr = ptr -> siguiente;
    //fin del while
ptr->siguiente = nuevoNodo;

return inicio;	
}

Nodo *insertaAntes (Nodo *inicio){

Nodo *ptr, *preptr, *nuevoNodo; 
int num, val;
	
 printf("\nIngrese el Valor del Nodo: ");
 scanf("%d",&num);
 
 nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
 nuevoNodo->valor = num;
 
 printf("\nIngrese el Valor del Nodo que Busca qeu sea posterior al Ingresado: "); 
 scanf("%d",&val);
 
 ptr = inicio;
 
 while(ptr->valor != val){
 	
 	preptr = ptr;
 	ptr = ptr->siguiente;
 }
 preptr->siguiente = nuevoNodo;
 nuevoNodo->siguiente = ptr;
	
return inicio;	
}

Nodo *insertaDespues (Nodo *inicio){

Nodo *ptr, *preptr, *nuevoNodo; 
int num, val;
	
 printf("\nIngrese el Valor del Nodo: ");
 scanf("%d",&num);
 
 nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
 nuevoNodo->valor = num;
 
 printf("\nIngrese el Valor del Nodo que Busca que sea Anterior al Ingresado: "); 
 scanf("%d",&val);
 
 ptr = inicio;
 
 while(preptr->valor != val){
 	
 	preptr = ptr;
 	ptr = ptr->siguiente;
 }
 preptr->siguiente = nuevoNodo;
 nuevoNodo->siguiente = ptr;
	
return inicio;	
}

Nodo *borraCabeza (Nodo *inicio){

Nodo *ptr; 
ptr = inicio;

inicio = inicio->siguiente;
free(ptr); //liberamos el nodo del inicio osea lo borramos 
	
return inicio;	
}

Nodo *borraCola(Nodo *inicio){
	
Nodo *ptr, *preptr;
ptr = inicio;

while (ptr -> siguiente != NULL){ // mientras ptr sea indistinto de NULL avanza
	
	preptr = ptr; //almaceno el valor de ptr en preptr
	ptr = ptr -> siguiente; //avanzo hasta el ultimo valor
	//fin del while
    }	

preptr -> siguiente = NULL; //Penultimo puntero lo apunto a Null para cerrar la lista
free(ptr); //Livero el puntero
return inicio;		
//fin de funcion Nodo borraCola()	
}

Nodo *borraNodo(Nodo *inicio){
	
Nodo *ptr, *preptr;
int val; 
printf("\nIngrese el valor del Nodo que desea Borrar: ");
scanf("%d",&val); //Ingreso el valor del Nodo que quiero borrar

ptr = inicio; //coloco el puntero al inicio

	if (ptr -> valor == val){ //si el valor ingresado es igual al dato
		
		inicio = borraCabeza(inicio); //verifica si es el encabezado ents lo borra
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
	//fin del if()else	
	}		
//fin de funcion Nodo borraNodo()	
}

Nodo *borraDespues(Nodo *inicio){
	
Nodo *ptr, *preptr;
int val;
ptr = inicio;

	printf("\nIngrese el Valor del Nodo anterior al que va a eliminar: ");
	scanf("%d",&val);

	
	while (preptr -> valor != val){	
		preptr = ptr;
		ptr = ptr -> siguiente;
	//fin de while ()	
	}
	
	preptr -> siguiente = ptr -> siguiente;	//ptr carga la direcicon del nodo a borrar
	free (ptr); //Borro el Nodo
	return inicio;
//fin de funcion Nodo borraDespues()	
}

Nodo *borraLista(Nodo *inicio){

Nodo *ptr;

	if(inicio != NULL){ //Si la lista no esta vacia
		
		ptr = inicio;
		while (ptr != NULL){
			
			printf("\n ( %d ) Esta por se Borrado\n", ptr -> valor); //apunta ala cabezera
			inicio = borraCabeza(ptr); //borra la cabezera y desp repite lo msimo con la nueva
			ptr = inicio;			   // y asi borra toda la lista
		//Fin del while	
		}		
	//Fin del if()	
	}
return inicio;
//fin de funcion Nodo borraLista()	
}

Nodo *ordenaLista(Nodo *inicio){

Nodo *ptr1, *ptr2;
int temp;

ptr1 = inicio;

	while(ptr1 -> siguiente != NULL){ 	 //Ordenamiento de tipo Burbuja		
		
		ptr2 = ptr1 -> siguiente;
		
		while ( ptr2 !=NULL){
			
			if( ptr1 -> valor > ptr2 -> valor){
				
				temp = ptr1 -> valor;
				ptr1 -> valor = ptr2 -> valor;
				ptr2 -> valor = temp;
			//fin del if ()	
			}
			
		ptr2 = ptr2 -> siguiente;	
		//fin del segundo while ()		
		} 
	 
	 ptr1 = ptr1 -> siguiente;
	 //fin del primer while ()
     }

return inicio; 
//fin de funcion Nodo ordenaLista()	
}



