#include <stdio.h>
#include <stdlib.h>

extern int suma(int a, int b);

int main (void){

    int a = 71;
    int b = 29;
    int c;
   
    c = suma(a,b);  //Sub rutina escrita en ensamblador

    printf("Valor del resultado es: %d", c);

return 0;    
} //Fin de main

