/*
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <stdlib.h>
*/

#include "header.h"

#define FD_STDIN 0
    
int compare (char *passw, char *inp)
{
	for (int i = 0; i < 5; i++)
		if (*(passw + i) != *(inp+ i))
			return 1;

	return 0;
}


void password()
     {
       char tec;
       int a=0,pass,tries=3;
	   char str1[5]="holas";
	   char str2[5]={0};
		
      struct termios t_old, t_new;
      tcgetattr(FD_STDIN, &t_old); 
      t_new = t_old;
      t_new.c_lflag &= ~(ECHO | ICANON); 
      tcsetattr(FD_STDIN,TCSANOW,&t_new); 
      tec = 0;
      
      
      printf("Ingrese su password de 5 digitos\n");
      printf("\nPulse ENTER para salir\n");
      while (tec!=10){ 
         tec=getchar();
         if(tec!=10)
         printf("*");
      
         str2[a]=tec;
         a++;
      

	    pass=compare(str1,str2);


         if(a==5 && pass==0){
			 printf("\nBIENVENIDO AL SISTEMA\n");
			 tcsetattr(FD_STDIN, TCSANOW, &t_old);
			 //tec=10;
			 return;
			 }
			 
	 if(a==5 && pass!=0){
			 tries--;
		
	   
			 
	    printf("\nPassword incorrecta,le quedan %d intento/s \n",tries);

	    a=0;
	    
	    if (tries==0){
		printf("\nSaliendo del programa \n");
		tec=10;
		 
		 }
			 
			 }	 
	 
      }
      tcsetattr(FD_STDIN, TCSANOW, &t_old);
      //fflush(stdin);
      exit (0);
   }
