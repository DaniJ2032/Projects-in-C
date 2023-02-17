/*Diseñe un programa que implemente una pila enlazada y sus operaciones
PUSH: Empuja o guarda datos
POP: Sacar Datos
PEEK: Ver el Dato Tope o Cabecera
DESPLEGAR: Ver el contenido de la Pila
Variables Externas:
Variables Utilizadas:
Entradas:
Salidas:
Etc,
*/ 
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{ //Defino la Estructura	
	int dato;
	struct stack *siguiente; //Variable de enlaze para la Pila
}Pila;

Pila *top = NULL; //puntero a top incio en NULL
/* *****************************PROTOTIPOS************************** */
Pila *push (Pila *, int); //Prototipo de la funcion de tipo Pila inserto
Pila *pop ( Pila *); //Saco Datos
Pila *muestraPILA ( Pila *); //Muestro lo que tiene la Pila
int peek (Pila *); //Veo datos topes
/* **************************************************************** */

int main(int argc, char *argv[]) {
	
int val, opcion;
		
	do{
    	printf("*************MENU PRINCIPAL*****************\n"); //Menu del Programa
    	printf("( 1 ) PUSH\n");
    	printf("( 2 ) POP\n");
    	printf("( 3 ) PEEK\n");
    	printf("( 4 ) Desplegar Valores\n"); // Opciones del Programa
    	printf("( 5 ) Salir\n");
    	printf("\t\t\t Ingrese uan Opcion: ");
		scanf("%d",&opcion); //Elijo opcion

	switch (opcion){
			
	case 1: 
		printf("\nIngrese el Numero a introducir a la Pila: ");
		scanf("%d",&val); // numero para la Pila
		top = push (top, val); // paso los valores
		break;
		
	case 2:
		top = pop(top); //la funcion devuelve un dato que apunte a un valor tipo Pila
		break;
		
	case 3:
		val = peek(top);
		if(val != -1)
			printf("\n El Valor en el Tope de la Pila es ( %d )\n\n", val);
		else
			printf("\n La pila se Encuentra vacia");
		break;
	
	case 4:	
		top = muestraPILA (top);
		break;
	default:
		printf("El valor ingresado no esta dentro de las Opciones.\n\n");
		
	}//fin del switch  	
	
	} while(opcion != 5); //fin del do While ()
	
// fin del Main	
	return 0;
}

/* Funcion:  Pila *push();
   Argumentos: -> Pila = Estructura definida por el Usuario
              -> val = Dato entero que identifica al Nodo
   Salida: Puntero a top, que es el encabezado de la pila 
   Esta funcion Ingresa un dato en la Pila */
Pila *push(Pila *top, int val){
	
	Pila *ptr; //variable puntero tipo Pila *
	ptr = (Pila *) malloc(sizeof(Pila)); //casteo de variable porque Malloc devuelve puntero a NULL
	ptr -> dato = val; // ptr apunta al dato que es igual a val
	
	if (top == NULL){ 	
		ptr -> siguiente = NULL;  // recorro la pila hasta el final
		top = ptr;  	
	}
	else
		ptr -> siguiente = top;
	    top = ptr;
		
	return top; 
//fin de funcion Pila *push();
}

/* Funcion: Pila *Pop(); 
   Argumentos: -> Pila = Estructura definida por el Usuario 
   Salida: Puntero a Top, actualiza el encabezado en main()
   Extrae el elemento que encabeza la Pila, y lo sustituye por el elemento
   que sigue en el orden de la misma */	
Pila *pop(Pila *top){
	
	Pila *ptr; //Defino un puntero
	ptr = top;
	
	if (top == NULL)//si el top apunta a NULL...
		printf("UnderFlow de la Pila, tenga cuidado!!!\n"); //UnderFlow: Desbordameinto de datos por valores menores a uno
	else{
	  top = top -> siguiente;
 	  printf("\n El Valor a ser retirado es: ( %d )\n\n", ptr->dato);
	  free(ptr);
	}
	return top;
	//fin de funcion Pila *pop();	
}

/* Funcion:  Pila *peek();
   Arguemnto: -> Pila = ......	
   Salida: Devuelve el valor de top
   Esta funcion meustra el valor guardado en top */	 
int peek(Pila *top){
	
if (top == NULL)	
	return -1;
else
    return top ->dato;

	//fin de funcion Pila *peek();	
}
	 
/* Funcion:  Pila *muestraPila();
Arguemnto: -> Pila =  .......
Salida: Devuelvo Puntero a estructura Top
Esta funcion meustralos valores de la Pila */	 
Pila *muestraPILA(Pila *top){
	
	Pila *ptr;
	ptr = top;
	if (top == NULL)
		printf(" La Pila se encuentra Vacia\n"); //meustro mensaje de pila vacia
	else
		while (ptr != NULL){
			
		printf("( %d )\n", ptr->dato); //Voy mostrando los valores guardados en la pila        
		ptr = ptr -> siguiente;	//avanzo entre las pilas enlazadas		
		}
		printf("\n\n");
    return top; 
	//fin de funcion Pila *muestraPila();		
}
	
	
	
	
	
	
	
	
