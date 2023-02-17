#include <stdio.h>
#include <stdlib.h>


void trystat(void);

int main(int argc, char *argv[]) {
int c = 0;
for(c=1; c<=3; c++){ //Alcance dentro de declaracion de funcion; solo dentro del for
                         // de C99 en adelante; C90 no se la reconoce
 printf("Iteracion # %d\n", c);  
 trystat();}		
		
	return 0;	
}

void trystat (void){

int temp = 1;
static int perm = 1;
printf(" temp = %d \t perm = %d\n", temp++, perm++);
	
}

