/* Configuración y uso de termios para acceder al puerto serie de PC en GNU/Linux */
/* Envia caracter por puerto serie */
/* Compila: gcc -Wall writechar.c termset.c -o writechar */
/* Ejecuta: ./writechar */  

# include <stdio.h>  /* Standard input / output definitions */
# include <fcntl.h>  /* File control definitions */
# include <unistd.h> /* UNIX standard function definitions */
# include "termset.h"


int main ( void )
{
  int fd ; /* Descriptor de archivo del puerto serie*/
  struct termios oldtty , newtty ; 
  char dato;

  fd = open ("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY );
  if ( fd == -1)
  {
  printf ("ERROR : no se pudo abrir el dispositivo.\n");
  return -1;
  }
  if (termset(fd , 9600, &oldtty, &newtty) == -1)
  {
  printf (" ERROR : no se pudo configurar el TTY \n" );
  return -1;
  }
  tcflush(fd, TCIOFLUSH);
  printf("ingrese un caracter: ");
  scanf("%c",&dato);
  printf("enviando dato...\n");
  write(fd , &dato , 1);
  tcdrain(fd);
  write(fd , "\n" , 1);
  tcdrain(fd);
  sleep (1);
close (fd);
return 0;
}
