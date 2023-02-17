/*Ejemplo de main Recursivo [Recrusion Lineal No FInal]*/
/*End of File en Linux -> Ctrl+c | Windows -> Ctrl+z*/

#include <stdio.h>
#include <stdlib.h>

int main ( ){

int c;

	if(scanf("%d",&c) != EOF){
	
		main();
		printf("( %d )\t",c);	
	}//Fin del if();

return 0;	
}//Fin del void main();




