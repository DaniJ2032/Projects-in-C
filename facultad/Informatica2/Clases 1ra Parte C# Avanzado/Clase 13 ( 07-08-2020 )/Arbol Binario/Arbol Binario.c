/* Arbol binario de bsqueda para la cdra informca 2*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// Estructura
// Estructura
typedef struct nodo{
	
	int dato; // Valor del nodo
	struct nodo *ptrIzq; // Puntero a la rama izquierda
	struct nodo *ptrDer; // Puntero a la rama derecha
	
}Nodo;

Nodo nodoArbol; // estructura nodo
typedef Nodo *ptrNodoArbol; //

/**************************************************************
Declaracie prototipos de funcion
***************************************************************/
int menu();
void insertarNodo(ptrNodoArbol *ptrArbol, int );
void mostrarArbol(ptrNodoArbol ptrArbol, int);
void inOrden(ptrNodoArbol ptrArbol);
void preOrden(ptrNodoArbol ptrArbol);
void postOrden(ptrNodoArbol ptrArbol);
int buscarNodo(ptrNodoArbol ptrArbol, int);
void borrarNodo(ptrNodoArbol *ptrArbol, int );
/****************************************************************

Funcirincipal
*****************************************************************/
int main(){
	int n, opcion, nodoB, encontrarNodo, contador=0;
	char orden;
	Nodo *ptrRaiz = NULL; // Arbol Vac
	
	do
	{
		opcion = menu();
		switch(opcion)
		{
		case 1:
			printf(" Digite el valor del nodo a ingresar:\n");
			scanf("%d", &n);
			insertarNodo(&ptrRaiz, n);
			printf("\n");
			break;
		case 2:
			break;
		case 3:
			mostrarArbol(ptrRaiz, contador);
			break;
		case 4:
			printf("\n\t\t\t Ingrese el orden en que desea ver los datos.");
			printf("\n\t\t\t a. preorden.");
			printf("\n\t\t\t b. inorden.");
			printf("\n\t\t\t c. postorden.");
			printf("\n\n\t\t\t Orden: ");
			scanf("%s", &orden);
			if(orden == 'a')
				preOrden(ptrRaiz);
			else if(orden == 'b')
				inOrden(ptrRaiz);
			else if (orden == 'c')
				postOrden(ptrRaiz);
			else
				printf("\n\t Orden incorrecto.\n");
			break;
		case 5:
			printf("\n\t\t Ingrese el valor del nodo a buscar: ");
			scanf("%d", &nodoB);
			encontrarNodo= buscarNodo(ptrRaiz, nodoB);
			if(encontrarNodo)
				printf("\n\n\t\t Nodo encontrado.");
			else
				printf("\n\n\t\t :-( Nodo inexistente.");
		default: break;
		}
		
	}while(opcion!= 6);
		printf("\nPresione una tecla para finalizar.");
	//getchar();
return 0;	
}

/**************************************************************************************/
int menu(){
	int opcion;
	
	printf("\n\t\t Menu:\n");
	printf(" 1. Ingresar un nuevo nodo.\n");
	printf(" 2. Borrar un nodo.\n");
	printf(" 3. Mostrar arbol.\n");
	printf(" 4. Recorrer arbol.\n");
	printf(" 5. Buscar un nodo.\n");
	printf(" 6. Salir.\n");
	printf("\n Opcion: ");
	scanf("%d", &opcion);
	
return opcion;
}	
	
/***********************************************************
Funciue agrega un nodo.
Comienza verificando que sea el nodo rael cual se debe crear
*************************************************************/
void insertarNodo(ptrNodoArbol *ptrArbol, int n){
	
	if(*ptrArbol == NULL){ // Si el arbol estaccrea el nodo ra
	
		*ptrArbol = malloc(sizeof(nodoArbol)); // reserva memoria para el nodo ra
			
			if (*ptrArbol != NULL){ // si ya se reservmoria para la estructura
			
				(*ptrArbol)->dato = n; // carga la ra
				(*ptrArbol)->ptrIzq = NULL; // Inicialmente no tiene hijos
				(*ptrArbol)->ptrDer = NULL; // Si es una hoja tampoco tendrijos
			}
			else{
				
				printf("\nNo se reservo memoria para el nodo.");
				printf("\nPuede que sea insuficiente la memoria disponible ");
			}
	}
	else{ // El ol ya existe
		
		if( n < (*ptrArbol)->dato ){ // Si el hijo es menor a la rava a la izquierda
			
			insertarNodo(&( (*ptrArbol) -> ptrIzq), n); // Se llama recursivamente hasta encontrar 
		}
		else if ( n > (*ptrArbol)->dato ){ // si el hijo es mayor a la ra
			
			insertarNodo(&((*ptrArbol)->ptrDer), n);// Se llama recursivamente para crear
		}	
		else{
			
			printf("\t :-( El valor ingresado ya existe. :-(\n");
			printf("\t Pruebe ingresando un valor diferente\n\n");
			}
		}
	
}// Fin de la funcion insertarNodo
			
/*************************************************************************************
Funciones que despliegan el ol binario de bsqueda
**************************************************************************************/
void mostrarArbol(ptrNodoArbol ptrArbol, int contador){
				
	int i;
	
	if(ptrArbol == NULL){
	return;
	}
	else{
		mostrarArbol(ptrArbol->ptrDer, contador+1); // recorre el ol en forma recursiva
		
		for(i=0; i<contador; i++){
			printf("\t");
		}

		printf("( %d )\n", ptrArbol->dato);
		mostrarArbol(ptrArbol->ptrIzq, contador+1);
	}
}
	
void inOrden(ptrNodoArbol ptrArbol){
	
		if(ptrArbol != NULL){ // Si existe un arbol
		
			inOrden(ptrArbol->ptrIzq); // recorre primero recursivamente el lado izquierdo
			printf("%3d", ptrArbol->dato); // imprime primero los valores menores a la raiz
			inOrden(ptrArbol->ptrDer); // imprime luego los valores mayores a la raiz
		}
}
	
void preOrden(ptrNodoArbol ptrArbol){
	
	if(ptrArbol != NULL){
		
		printf("%3d", ptrArbol->dato);
		preOrden(ptrArbol->ptrIzq);
		preOrden(ptrArbol->ptrDer);
	}
}
		
void postOrden(ptrNodoArbol ptrArbol){
	
	if(ptrArbol != NULL){
		
		preOrden(ptrArbol->ptrIzq);
		preOrden(ptrArbol->ptrDer);
		printf("%3d", ptrArbol->dato);
	}
	
	printf("\n\t\t LLego a la ultima hoja \n\n");
	
}
	
/***********************************************************************************
Funciue busca un nodo
**********************************************************************************/
int buscarNodo(ptrNodoArbol ptrArbol, int nodoB){
	
	if(ptrArbol == NULL)
		return 0;
	else if(nodoB < (ptrArbol->dato)){
		
		buscarNodo((ptrArbol->ptrIzq), nodoB);
	}
	else if(nodoB > (ptrArbol->dato)){
		
		buscarNodo((ptrArbol->ptrDer), nodoB);
	}
	else
	return 1;
}

	
