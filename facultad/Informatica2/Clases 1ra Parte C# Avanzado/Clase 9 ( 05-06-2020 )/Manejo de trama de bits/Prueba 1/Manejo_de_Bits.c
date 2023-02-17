// Manejo de Trama de Bits con Archivos Binario 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> //Libreria que nos permite manejar numeros enteros sin signo
#include <math.h> //Libreria de operaciones Matematicas

#define archivo "Binario1.bin" //Archivo de prueba bianrio a Leer
#define tiempos "Tabla_Tiempos.txt" //Archivo de prueba bianrio a Leer

////////////////////////////////PROTOTIPOS DE FUNCIONES//////////////////////////////////////
void distribuirTarea(float timeStamp,  uint8_t id, uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD );
void obtenerLatitud(uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD);
void obtenerLongitud(uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD);
//***********************************************************************************************

int main(int argc, char *argv[]) {

/////////////////////VARIABLES uint_t////////////////////////////////////////////	
uint8_t unbyte, id, registro = 0x00; //Archivo de 1 byte a leer/variable registro para saber hasta dodne leer
uint8_t tus1, tus2, ts1, ts2; //Timepos en micros segundos y en segundos
uint8_t byteA, byteB, byteC, byteD; //Variables para los datos

uint16_t tus, ts; //Timepos en micros segundos y en segundos de 16 bits ( 2 bytes )
//*******************************************************************************

double timeStamp; //Variable de 32 Byte para el tiempo total
int contador=0, contador2=0, i =1; //Variable de conteo de lectura
FILE *ptrBin, *tblTiempos; //Puntero tipo FILE para recorrer el archivo


	
	
	if((ptrBin = fopen(archivo, "rb"))==NULL); //Preguntamos con el Bin y lo abrimos como lectura binaria
	printf("\nEl Archivo Binario no se puede abrir. \n");
	
	if((tblTiempos = fopen(tiempos, "w"))==NULL); //Creamos archivo donde almaceno los Tiempos
	printf("\nEl Archivo Binario no se puede crear. \n");
	
	
while(!feof(ptrBin)){ //Leemos todo el archivo
	
	fread(&unbyte, 1, 1, ptrBin); //Vamos leyendo de a 1 Byte 1 a la vez y almacenamos en unbyte
	
	if (contador >=16){
		
		contador = 0; // cuando lee una linea completa se resetea
		tus1 = tus2 = ts1 = ts2 = 0; //reseteo los tiempos de 8 bits
		registro = 0x00;
	} //fin del if
	
	if(unbyte == 0xFE && contador == 0)
	  registro = 0x01; //Coloco en 1 el bit 0 de registro
	// fin del if
	
	if(unbyte == 0x08 && registro == 0x01)
 	  registro = 0x02 | registro; //coloco el registro en 0b00000011 = 0x03  con operador "OR" ( | )
 	// fin del if  
 	  
 	  
 	if(registro % 0xFC == 3){ // devuelvo el resto ( FC = 252 )
 		
 		if(contador == 5)
 		 id = unbyte; // en la posicion 5 del arvhivo tengo el id
 		 
 		else if (contador == 6)
 		 tus1 = unbyte; // en la posicion 6 del arvhivo tengo el tiempo en micros
 		 
 		else if (contador == 7){
 			tus2 = unbyte;
 			tus = (tus2<<8) + tus1; //Lo corro 8 lugares
 			
		} //fin del else if anidado
		  
 		else if (contador ==8) // en la posicion 8 del arvhivo tengo el tiempo en segundos
 		  ts1 = unbyte;
 		
 		else if (contador == 9){ 
 			
 			ts2 = unbyte;
 			ts = (ts2<<8) + ts1; //Lo corro 8 lugares
 			timeStamp = ts + (float)tus/1000000; //tiempo total casteo a float divido por 1 millon
 			
 			//printf("El tiempo TimeStamp es: %f \n", timeStamp); //Imprimo el tiempo total
 			
 			fprintf(tblTiempos, " %d: %f \t %d \n", i++, timeStamp, contador2);
 			
		} //fin del else if anidado
		
		else if (contador == 10)
		 byteA = unbyte; //Lo leido en unbyte lo almacena en byteA
		 
		else if (contador == 11)
		 byteB = unbyte; //Lo leido en unbyte lo almacena en byteB
		
		else if (contador == 12)
		 byteC = unbyte; //Lo leido en unbyte lo almacena en byteC 
		 
		else if (contador == 13){
        byteD = unbyte; //Lo leido en unbyte lo almacena en byteD 
        
        distribuirTarea (timeStamp, id, byteA, byteB, byteC, byteD );
		} //fin de los if else anidados de los datos
		
		
		
		
	 } //fin del "if(registro % 0xFC == 3)"
	    
 	 contador++; //Incremento el contador
	 contador2++; //Incremento el contador2  
	  	  
} //fin del while
	
	return 0;
} //fin de programa

void distribuirTarea (float timeStamp,  uint8_t id, uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD ){
	
	switch (id){
		
		case 20: //Analizo para el caso de valor 20 (latitud)
			
			obtenerLatitud(byteA, byteB, byteC, byteD);
			
		  break;
	
		case 21:
		
		    obtenerLongitud(byteA, byteB, byteC, byteD);
		break;		
		
		case 23:
		  break;		
		
			
	}
	//fin de swhitch

	
	
}
//fin de funcion distribuirTarea

void obtenerLatitud (uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD){
	
int signo, exponente, entero, corrimiento;
uint32_t aux = (byteD <<24)+(byteC<<16)+(byteB<<8)+byteA; //Variable de 32 bytes donde doy vuelta lso valores recibidos porque lo tenemso en litle Endian
uint8_t aux2; //Variable Auxiliar de 8 bytes
uint32_t aux3, divisor = 0xFFFFFFFF; //Variable Auxiliar de 32 bytes y divisor
float decimal, latitud;
	
	if(aux >>31) //corro a la derecha
	   signo = -1; //si vale 1 entonces es -1 el valor 
	else 
	   signo = 1; //de lo contrario vale 1
	//fin del else
	
	aux2 = aux >> 23; //corro 23 lugares en aux2 y lo igualo y tomo 8 lugares 
	exponente = aux2 -127; //para sacar el exponenete en aux2
	corrimiento = 23 - exponente; //tomo la cantidad de bytes dados por el exponente y corro
	aux2 = aux >> corrimiento; //aux2 es igual a aux corrido lo que da corrimiento
	aux2 = aux2 << (8-exponente); //Corro para la derecha lleno de ceros
	aux2 = aux2 >> (8-exponente); //Corro para la Izquierda ya me quedan los ceros
	
	entero = pow(2,exponente)+aux2; //Obtengo la Parte entera
	
	aux3 = aux << (9 + exponente); 
	aux3 = aux3 >> (9 + exponente);
	divisor = divisor << ( 9 + exponente);
	divisor = divisor >> ( 9 + exponente);
	
	decimal = (float) aux3/divisor;
	
	latitud = signo*(entero + decimal); //Armo el valor de latitud
	
	printf("\nValor de la Latitud es: ( %.7f )\n\n", latitud);

	
	
}
//fin de funcion obtenerLatitud

void obtenerLongitud (uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD){
	
int signo, exponente, entero, corrimiento;
uint32_t aux = (byteD <<24)+(byteC<<16)+(byteB<<8)+byteA; //Variable de 32 bytes donde doy vuelta lso valores recibidos porque lo tenemso en litle Endian
uint8_t aux2; //Variable Auxiliar de 8 bytes
uint32_t aux3, divisor = 0xFFFFFFFF; //Variable Auxiliar de 32 bytes y divisor
float decimal, longitud;
	
	if(aux >>31) //corro a la derecha
	   signo = -1; //si vale 1 entonces es -1 el valor 
	else 
	   signo = 1; //de lo contrario vale 1
	//fin del else
	
	aux2 = aux >> 23; //corro 23 lugares en aux2 y lo igualo y tomo 8 lugares 
	exponente = aux2 -127; //para sacar el exponenete en aux2
	corrimiento = 23 - exponente; //tomo la cantidad de bytes dados por el exponente y corro
	aux2 = aux >> corrimiento; //aux2 es igual a aux corrido lo que da corrimiento
	aux2 = aux2 << (8-exponente); //Corro para la derecha lleno de ceros
	aux2 = aux2 >> (8-exponente); //Corro para la Izquierda ya me quedan los ceros
	
	entero = pow(2,exponente)+aux2; //Obtengo la Parte entera
	
	aux3 = aux << (9 + exponente); 
	aux3 = aux3 >> (9 + exponente);
	divisor = divisor << ( 9 + exponente);
	divisor = divisor >> ( 9 + exponente);
	
	decimal = (float) aux3/divisor;
	
	longitud = signo*(entero + decimal); //Armo el valor de latitud
	
	printf("\n\nValor de la Longitud es:(  %.7f )\n", longitud);

	
	
}
//fin de funcion obtenerLatitud*/




