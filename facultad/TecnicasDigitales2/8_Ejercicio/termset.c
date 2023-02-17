#include <stdio.h>
#include "termset.h"
int termset ( int fd, int baudrate, struct termios *ttyold, struct termios *ttynew )
{
switch ( baudrate )
{
  case 115200: baudrate = B115200;
    break ;
  case 57600: baudrate = B57600;
    break ;
  case 38400: baudrate = B38400;
    break ;
  case 19200: baudrate = B19200;
    break ;
  case 9600: baudrate = B9600;
    break ;
  default : baudrate = B115200;
    break ;
}
if(tcgetattr(fd, ttyold) != 0)
{
  printf(" ERROR : tcgetattr \n");
  return -1;
}
ttynew = ttyold;
cfsetospeed(ttynew, baudrate);
cfsetispeed(ttynew, baudrate);
ttynew -> c_cflag = ( ttynew -> c_cflag & ~CSIZE ) | CS8 ; // 8 data bits (8)
ttynew -> c_cflag &= ~( PARENB | PARODD ); // no parity (N )
ttynew -> c_cflag &= ~CSTOPB ;// 1 stop bit (1)

ttynew -> c_cflag |= (CLOCAL | CREAD);         // ignore modem status lines , and
                                                // enable reading
ttynew -> c_cflag &= ~CRTSCTS;                 // no flow control

ttynew -> c_iflag &= ~IGNBRK ;                  // disable break processing
ttynew -> c_iflag &= ~( IXON | IXOFF | IXANY ); // shut off xon / xoff ctrl

ttynew -> c_lflag = 0;
ttynew -> c_oflag = 0;
ttynew -> c_cc[VMIN] = 0;
ttynew -> c_cc[VTIME] = 100;
/*
* TCSANOW : Make the change immediately .
* TCSADRAIN : Make the change after all queued output has been written .
* TCSAFLUSH : This is like TCSADRAIN , but also discards any queued input .
*/
if(tcsetattr(fd, TCSANOW, ttynew) != 0)
/*if(tcsetattr(fd, TCSAFLUSH, ttynew) != 0)*/
{
printf(" ERROR : tcsetattr \n" );
return -1;
}
return 0;
}
