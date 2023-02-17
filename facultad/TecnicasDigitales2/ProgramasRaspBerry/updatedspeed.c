//#include <termios.h>
#include "header.h"   

extern int speed;
extern struct termios old,new;   ////////////////////////////

/////////////////////////////////////////////////////////////////////
void config(){
	tcgetattr(0,&old);
	new=old;
	new.c_lflag &= ~(ECHO | ICANON); 
	new.c_cc[VMIN]=0;
	new.c_cc[VTIME]=0;
	
	
	}
///////////////////////////////////////////

int updatedspeed ()
{
	char aux[3]={0,0,0}; ////
	
	config();////
	tcsetattr(0,TCSANOW,&new);/////////////////////
	
	
	
	//if(getbuffer==flechaarriba)
	//flechaarriba=flechaarriba*101400; //flechaarriba vale 1 por cada vez que tocas la tecla
		//speed=speed+flechaarriba;
	read(0,&aux,3);
	
	/*
	if (serialDataAvail (serialPort))
			data = serialGetchar (serialPort);
			
			if (data == '3')
		{
			shutDown ();
			return 1;
		}

		if (data == '2' && i < 1)
		{
			counter += 25000;
			i++;
		}

		if (data == '1' && j < 1 && counter > 45000)
		{
			counter -= 25000;
			j++;
		} 
	
	*/
	
	
	
	////////////////////// IDEA SERIA
	
	/*
	
	 
	 if (serialDataAvail (serialPort)){
	 for(int i=0;i<2;i++) 
			aux[i] = serialGetchar (serialPort);
	 
	 
 }
	 
	 
	*/
				
	if(aux[0]=='A'){
		printf("SALIR\n");
		aux[2]='0';
		tcsetattr(0,TCSANOW,&old);
		return 0;
				}
				
	if(aux[2]=='A'){
		printf("SUBIR VELOCIDAD\n");
		aux[0]='0';
		speed=speed-101400;
				}	
				
	if(aux[2]=='B'){
		printf("BAJAR VELOCIDAD\n");
		aux[0]='0';
		speed=speed+101400;
				}	
	
	
	//if(getbuffer==flechaabajo)
	//flechaabajo=flechaabajo*101400;
		//speed=speed-flechaabajo;
	
	if(speed>1095900){
		speed=1095900;	}
	if(speed<101400){
		speed=101400;	}


tcsetattr(0,TCSANOW,&old); ///////////////
//printf("Fin\n");
return 1;


}


	
