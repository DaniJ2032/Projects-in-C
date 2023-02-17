/*Levantamiento de Datos de una Telerimetria de un BusCan [IEEE754]*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>//Libreria que nos permite manejar num enteros a partir de C99
#include <math.h>  //Libreria de Matematica para los calculos
#include <time.h>  //Libreria para tiempo Unix

#define Archivo "Binario1.bin" //Archivo a leer le definimos un nombre
#define MILLON 1000000

/*****************************PROTOTIPOS DE FUNCIONES****************************/
void distribuirTarea(FILE *, double, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);	
void ObtenerLatitud(FILE *, uint8_t, uint8_t, uint8_t, uint8_t);
void ObtenerLongitud(uint8_t, uint8_t, uint8_t, uint8_t);
void ObtenerTiempo(uint8_t, uint8_t, uint8_t, uint8_t);
/****************************************************************************/

int main (int argc, char* argv[]){

/*VARIABLES DE TIEMPO*/		
uint8_t unbyte, id; //Variable para leer 1 Byte = 8 bits
uint8_t tus1, tus2, ts1, ts2; //Variables para leer los us y seg 2 byte para c/u
uint16_t tus, ts; //Para el tiempo total 2 bytes =  16 bits en seg y useg
double timeStamp;//Para el almacenado del tiempo total [32bits la variable] 
/***************************************************************/

FILE *ptrBin, *tblTime;
int contador = 0, contador2 = 0; //Contador de Lineas de Trama avanzo en el Archivo
uint8_t registro = 0x00;//Usada para detectar la trama de inicio y obviar la basura
uint8_t byteA, byteB, byteC, byteD; //Variables para los datos

	if(( ptrBin = fopen(Archivo, "rb" )) == NULL)//Abrimos el Archivo como Lectura Binaria
		printf("\n\nEL Archivo de Datos no se Puede Abrir\n\n");

	if(( tblTime = fopen("TimeStamp.txt","w")) == NULL)//Guardamos en un .TXT
		printf("\n\nEL Archivo de Datos no se Puede Crear\n\n");	

	while(!feof(ptrBin)){
		
		fread(&unbyte, 1, 1, ptrBin);//Leemos el tamaño de unbyte desde ptrBin un dato y lo guardamos en unbyte 	
		
		if(contador >= 16 ){

			contador = 0;//Vuelva el Contador a cero	
			tus1=tus=ts1=ts2=0;//Reseteo los tiempos tambien
			registro = 0x00;

			}//Fin del if();		
		
/*****************************************************************************/			
		    if( unbyte == 0xFE && contador == 0 )//Coloco a 1 el  Bit 0 de registro
				registro = 0x01;
		
			if( unbyte == 0x08 && registro == 0x01)
				registro = 0x02 | registro;//Coloco en el registro [0b00000011] = [0x03]

//cuando la Variable unbyte comeinza la lectura de la trama en [FE]
//y tengo mi contador de registro en [0] le coloco un  [1] al bit 
//al bit [0] del registro. Cuando avanza unbyte al segundo byte detecta
//[0x08] y el contador lo tengo en [1] al registro le realizo una operacion
//logica de compuerta colocando un OR que es (+) logica entonces sumo 
//[0x01] + [0x02] = [0x03] con estos pasos me aseguro que estoy en inicio de trama
//y cuando se presente la basura no se levantaran esos datos  
/*********************************************************************************/
				if( registro% 0xFC == 3 ){

					if( contador == 5 )
						id = unbyte; //En la posicion 5 tenemos el id 
							//Fin del if();

					else if( contador == 6 )	
						tus1 = unbyte;
							//Fin del primer else if();
							
					else if( contador == 7 ){
								
						tus2 = unbyte;
						tus = (tus2 << 8) + tus1;//Corro Izquierda
//Como la trama esta en Little Endian a los bytes los tenemos que dar vuelta para
//poder mostrarlos en pantalla por ende el [B7] lo corro 8 lugares y lo sumo al [B6]
//quedandonos con el tiempo en useg armado de la manera [B7+B6].
//Cuando se realizan corrimiento de bits al correrse se llenan de ceros los espacios
//que sobran -> ( 15896981B7 << 8 = B700000000 )
//
					}//FIn del segundo else if();		

						else if( contador == 8 )
							ts1 = unbyte;
								else if( contador == 9 ){
									ts2 = unbyte;
									ts = ( ts2 << 8 ) + ts1;
									timeStamp = ts+(float)tus/MILLON;
									printf("El Time Stamp es: ( %f )\n\n",timeStamp);
						            fprintf(tblTime,"\n( %f ) \t [%d]\n",timeStamp, contador2);
								}
						
					//Repetimos la misma operacion para los valores en Segundos
					//tomamos el tiempo total en useg [tus] y total en seg [ts]
					//y los sumamos casteando la variable [tus]para que de con ","
					//y dividiendo por [MILLON] nos queda el Time Stamp 
					//para imprimir.
                         else if( contador == 10 )//cuando recorro el archivo y encuentro los ID
							byteA = unbyte;	//EL 10 esta el dato del byteA
	                     else if( contador == 11 )
							byteB = unbyte; //EL 11 esta el dato del byteB
                         else if( contador == 12 )
							byteC = unbyte; //El 12 esta el dato del byteC         
	                     else if( contador == 13 ){	//EL 13 esta el dato del byteD

							byteD = unbyte;
						    distribuirTarea(tblTime, timeStamp, id, byteA, byteB, byteC, byteD);
                          }	//Le paso a la funcion de distribuirTarea todos los bytes							
                            //Fin de los else if(); anidados										
		 
				}//Fin del primer if();
				contador++;//Incremento el Contador mientras avanzo en la trama	
				contador2++;	
	}//Fin del while();		

return 0;
}	


void distribuirTarea(FILE *tblTime, double timeStamp, uint8_t id, uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD){
	
	switch(id){

		case 20: //Valor de los id en el 20 te da la Latitud
			ObtenerLatitud(tblTime, byteA, byteB, byteC, byteD);					
		break;

		case 21: //id 21 te da la longitud
			ObtenerLongitud(byteA, byteB, byteC, byteD);	
		break;

	    case 23: //id 22 nos da el tiempo Unix de la ejecucion
	    	ObtenerTiempo(byteA, byteB, byteC, byteD);		
		break;
	
	}//Fin del switch();
}//Fin de la Funsion distribuirTarea();	


void ObtenerLatitud(FILE *Lt, uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD){

int signo,exponente, entero, corrimiento; //Determinamos el Signo del Dato
uint32_t aux =(byteD<<24) + (byteC<<16) + (byteB<<8) + byteA; //Dato en crudo dado vuelta y acomodado 
uint8_t aux2;
uint32_t aux3, divisor = 0xFFFFFFFF;
float decimal, latitud;

	if(aux>>31) //Si a mi numero completo lo corro ( 31 ) lugares obtendre el signo
		signo = -1; //Si es un [1] es signo ( - )
	else
		signo = 1;	//De lo contrario es ( + )
	//Fin del if() else
	
    aux2 = aux >> 23; //Corro 23 Lugares y lo igualo
//Tenemos el b31 = [ signo ] desp los ( 8bits ) que son los datos que nesecitamos
//luego nos queda otros ( 23bits )	ents lo que se hace es correr 23 lugares
// a la derecha! el ( b31 + 8bits ) = [ 9bits ] lo igualo a la variable 
// ( aux2 ) y por mas que el dato corrido tenga 9bits ( aux2 ) 
// solo tomara los 8bits que nesecitamos para nuestro exponenete

	exponente = aux2 - 127;//Obtenemos el Exponente
	corrimiento = 23 - exponente; //Obtenemos cuanto nos debemos correr
	aux2 = aux >> corrimiento; //Lo almacenamos en aux2
	aux2 = aux2 << ( 8 - exponente );//Corro para la derecha
	aux2 = aux2 >> ( 8 - exponente );//Vuelvo a la izquierda y completo con ceros   
//Cuando obtenemos el ( exponente ) ese numero nos indica la cantidad
//de bits que debemos tomar, como sabemos que tenemos 23bits
//entonces nos corremos el valor del exponente - los 23 bits
//solo nesecitamos los valores que nos indica el exponente que
//almacenamos en ( aux2 ) lo que hago es correrlo a la derecha
//( 8bits - exponente ) y lo vuelvo a correr a la izquierda para completar
//los demas lugares con cero, con esto me aseguro de obtener el numero 
//limpio para obtener el numero de la parte entera.

	entero = pow(2,exponente) + aux2;//Por fin obtenemos nuestro valor entero.	

/******************CALCULAMOS LA PARTE DECIMAL***********************************/
//Para obtener la parte decimal de nuestro numero tomamos la variable ( aux )y la
//corremos ( 9 lug + exponente ) a la derecha y luego izq para obtener el dato
//limpio.
//el caso del Divisor como no sabemos cuanto tendremos de numero decimal para
//dividi, decllararemos una variable ( divisor ) la cual la llenamos de [F]
//y antes de usarla para dividir corremos a la derecha y a la izquierda 
//agregando los ceros que hagan falta en base a cuanto tengamos en el exponente
//( 9 + exponente ). COn esto obtenmos el decimal y su divisor que corresponde	

	aux3 = aux << ( 9 + exponente );//Me corro a la derecha y almaceno en aux3
	aux3 = aux3 >> ( 9 + exponente );//Vuelvo a la izquierda
	divisor = divisor << ( 9 + exponente );//acomodo el divisor en base al decimal
	divisor = divisor >> ( 9 + exponente );

	decimal = (float) aux3/divisor; //Obtenemos el decimal

	latitud = signo*( entero + decimal );//sumo todo obtengo la latitud
	printf("Valor de la Latitud es ( %.7f )\n\n",latitud);//imprimo latitud
	//getchar(); 
	fprintf( Lt,"\nLatitud [%.7f ]\n",latitud );//Se puede guardar en el texto la latitud
		

}//Fin de funcionn ObtenerLatitud();		


/*Se Obtiene de la misma forma que la Latitud*/
void ObtenerLongitud(uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD){

int signo,exponente, entero, corrimiento; //Determinamos el Signo del Dato
uint32_t aux =(byteD<<24) + (byteC<<16) + (byteB<<8) + byteA; //Dato en crudo dado vuelta y acomodado 
uint8_t aux2;
uint32_t aux3, divisor = 0xFFFFFFFF;
float decimal, longitud;


	if(aux>>31) //Si a mi numero completo lo corro ( 31 ) lugares obtendre el signo
		signo = -1; //Si es un [1] es signo ( - )
	else
		signo = 1;	//De lo contrario es ( + )
	//Fin del if() else
    aux2 = aux >> 23; //Corro 23 Lugares y lo igualo

	exponente = aux2 - 127;//Obtenemos el Exponente
	corrimiento = 23 - exponente; //Obtenemos cuanto nos debemos correr
	aux2 = aux >> corrimiento; //Lo almacenamos en aux2
	aux2 = aux2 << ( 8 - exponente );//Corro para la derecha
	aux2 = aux2 >> ( 8 - exponente );//Vuelvo a la izquierda y completo con ceros   
	entero = pow(2,exponente) + aux2;//Por fin obtenemos nuestro valor entero.	

/******************CALCULAMOS LA PARTE DECIMAL***********************************/
	aux3 = aux << ( 9 + exponente );//Me corro a la derecha y almaceno en aux3
	aux3 = aux3 >> ( 9 + exponente );//Vuelvo a la izquierda
	divisor = divisor << ( 9 + exponente );//acomodo el divisor en base al decimal
	divisor = divisor >> ( 9 + exponente );
	decimal = (float) aux3/divisor; //Obtenemos el decimal

	longitud = signo*( entero + decimal );//sumo todo obtengo la latitud
	printf("\n\nValor de la Longitud es ( %.7f )\n\n",longitud);//imprimo longitud
	//getchar(); //Se deteniete cada vez que me muestra la Longitud

}//FIn de la Funsion ObtenerLongitud();		

/*Buscamos que nos muestre el tiempo Unix de la ejecucion del Archivo*/
void ObtenerTiempo( uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD ){

char *UXtime; //Variable char* para que me devuelva el tiempo como un string
time_t time =(byteD<<24) + (byteC<<16) + (byteB<<8) + byteA; //Dato en crudo para el tiempo

UXtime = ctime(&time);//Convierto el valor numerico del IEEE754 y se lo paso al puntero *time 
	
	printf("\n\nTiempo Unix es: %s", UXtime);//Imprimo el tiempo
//	getchar();

}//Fin de la Funsion ObtenerTiempo();		


