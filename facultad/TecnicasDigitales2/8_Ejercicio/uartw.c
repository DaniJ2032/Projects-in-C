/* comunicacion UART en Raspberry Pi usando C (Libreria WiringPi)
*/
/* uso: imprime caracter recibido desde el puerto serie*/
/* Compila: gcc -o uartw uartw.c -lwiringPi*/
/* Ejecuta: sudo ./uartw */
/* Salir: Ctrl+c */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int main ()
{
  int serial_port ;
  char dat;
  if ((serial_port = serialOpen ("/dev/serial0", 9600)) < 0)			/* abrir el puerto serie */
  //if ((serial_port = serialOpen ("/dev/ttyAMA0", 9600)) < 0)			/* abrir el puerto serie */
  {
    fprintf (stderr, "No pudo abrirse el dispositivo serie: %s\n", strerror (errno)) ;
    return 1 ;
  }

  if (wiringPiSetup () == -1)							/* inicializa la configuracion de wiringPi */
  {
    fprintf (stdout, "No pudo comenzar wiringPi: %s\n", strerror (errno)) ;
    return 1 ;
  }

  printf (" -------Comunicacion serie----\n") ;
  while(1){
	  
	if(serialDataAvail(serial_port)) 		/* retorna el numero de caracteres disponibles para leer o -1*/
	{
	  dat = serialGetchar(serial_port);		/* retorna el siguiente caracter disponible en el dispositivo serial */	
	  printf ("%c", dat);
	  //serialPutchar(serial_port, dat);		/* envia un unico byte por el puerto serie indicado*/
	}

  }
}
