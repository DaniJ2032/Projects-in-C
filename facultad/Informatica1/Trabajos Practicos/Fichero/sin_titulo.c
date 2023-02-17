#include <stdio.h>
#include <stdlib.h>

int main() {
	
	char aux2[100];
	FILE *f;	
	f = fopen("prueba.txt","r");
	
	if(f == NULL){
		
		printf("No se peude Leer el Documento Solicitado\n");	
		exit(1);
	}	
	
	while (!feof(f)){
		fgets(aux2,100,f);
		printf("%s",aux2);	
	}	
	printf("\n\n");
	
	fclose(f);
	
	
	return 0;
}

