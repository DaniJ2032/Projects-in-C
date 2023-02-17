#ifndef __header__
#define __header__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <pcf8591.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <wiringPiI2C.h>
#include <fcntl.h> 
#include <unistd.h> 
//#include "EasyPIO.h"
/*
#include "main.c"
#include "password.c"
#include "remote.c"
#include "setspeed.c"
#include "updatedspeed.c"
#include "secuencias.c"
*/


void password();
void remote();
void send();
void receive();
void setspeed();
int updatedspeed(); 
void autof();			
void choque();
void apilada();
void carrera();
void seq5();
void seq6();
void seq7();
void seq8();


//int led [8] = {26,21,20,16,12,25,24,23};
//int speed;


#endif
