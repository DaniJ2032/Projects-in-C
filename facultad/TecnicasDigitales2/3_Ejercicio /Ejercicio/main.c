#include <stdio.h>
#include <termios.h>

#define FD_STDIN 0

int main(void){

    char tec;
    struct termios t_old, t_new;
    tcgetattr(FD_STDIN, &t_old); // lee atributos del teclado
    t_new = t_old;
    t_new.c_lflag &= ~(ECHO | ICANON); // anula entrada canónica y eco
    tcsetattr(FD_STDIN,TCSANOW,&t_new); // actualiza con los valores nuevos de la config. TCSANOW = activar la modificación inmediatamente
    tec = 0;
    while (tec!=10){ // Ingresar hasta oprimir enter
        tec=getchar();
        printf("%c - %d\n",tec,tec);
     }
     tcsetattr(FD_STDIN, TCSANOW, &t_old); // actualiza con los valores previos

return 0;
}