#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "huva.h"

Nodo *inicio = NULL;

int main (){

int opc;
do{
	opc = Menu_Principal();
   
    switch(opc || opc2){
		
    case 1:

        printf("\n****LISTA DE SURCOS DEL VIÑEDO****\n");
            inicio = LevantoDatos( inicio );
        break;

    case 2:

            CargarNuevoSurco( inicio );
        printf("\n****Nuevo Surco Cargado con Exito****\n");
        break;  

    case 3:
        inicio = EliminaSurco( inicio );
        printf("\n****Surco Eliminado con Exito****\n");
        break;      

    }//Fin del switch();

}while(opc != 0 ); //Hasta que sea igual que 0 volveremos al menu



return 0;
}//FIn del main();  

