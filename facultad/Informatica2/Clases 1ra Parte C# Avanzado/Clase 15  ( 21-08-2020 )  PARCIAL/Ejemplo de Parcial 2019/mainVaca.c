#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "Animal.h"

Nodo *inicio = NULL;

int main (){

int opc;
do{
	opc = Menu_Principal();
	
    switch(opc){
		
    case 1:
        inicio = CargaVaca( inicio ); 
        break;

    case 2:
        printf("\n****Vacas Agregadas****\n");
        inicio = MostrarGanado( inicio );
        break;  

    case 3:
        inicio = CargarVacaFaeneada( inicio );
        printf("\n****Vaca Eliminada del Registro con Exito****\n");
        break;      

    }//Fin del switch();

}while(opc != 0 ); //Se repite hasta que sea distinto de 13
return 0;
}//FIn del main();  














































