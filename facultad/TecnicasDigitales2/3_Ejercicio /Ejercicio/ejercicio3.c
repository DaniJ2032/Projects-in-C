#include <stdio.h>
#include <termios.h>

#define FD_STDIN 0
#define PASSWORD "holas"
#define longitud 5

int main (void){

	char contraseña_ingresada [longitud+1];
	char caracter;
	int error = 0;
	int indice = 0;
	int count = 1;

	
	struct termios t_old, t_new;
	tcgetattr(FD_STDIN, &t_old); // lee atributos del teclado
	t_new = t_old;
	t_new.c_lflag &= ~(ECHO | ICANON); // anula entrada canónica y eco
	tcsetattr(FD_STDIN,TCSANOW,&t_new); // actualiza con los valores nuevos de la config. TCSANOW = activar la modificación inmediatamente
    caracter = 0;

/////////////////////////////////////////
	do{
		printf("ingrese su password de 5 digitos Intento %d: ", count);
		while (caracter != '\n'){ 
			caracter = getchar();
		
			//printf("*");
			if (caracter == 127 ) {
				if(indice > 0){
					indice --;			
					printf("\b \b"); 
				} 
			}
			else{ 
				contraseña_ingresada[indice] = caracter;
				indice++;
				printf("*");
			}		
		}

		//Comparacion
		for (int i = 0; i < longitud; i++){
			if (PASSWORD[i] != contraseña_ingresada[i]){
				error += 1;			
			}			
		}

		if (error != 0){ 
			printf("\nContraseña Incorrecta \n");
			count++;
			error = 0;
		}	
		else{
				printf("\nContraseña Correcta. Bienvenido al Sistema\n");
				tcsetattr(FD_STDIN, TCSANOW, &t_old);
				break; // actualiza con los valores previos 
		}
		
		}while(count != 4 && error == 0);
		//printf("\nSobrepaso el maximo de intentos permitidos\n");
//		printf("Contraseña correcta \n");

	 tcsetattr(FD_STDIN, TCSANOW, &t_old); // actualiza con los valores previos 

return 0;
}
