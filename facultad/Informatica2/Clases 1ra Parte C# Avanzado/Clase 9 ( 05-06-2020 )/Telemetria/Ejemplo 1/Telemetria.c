#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#define archivo "archivo1.bin"

float norma(uint8_t ,uint8_t ,uint8_t ,uint8_t );
long int tiempounix (uint8_t ,uint8_t ,uint8_t ,uint8_t );

int main (int argc, char* argv []){
		/*Estrategia: Recorremos toda la secuencia, hasta el final del archivo, leyendo
		 de a un byte y contando su posición, para poder tomar registro de los datos que
		 vamos obteniendo.

				1)RELEVAR EL TIMESTAMP-> es importante primero tomar el momento
				en que se toma el dato antes de convertir nada.(criterio)
				2)Relevar los datos que se quieran derivando a funcioes.
		*/
		uint8_t auxbyte,id,registro= 0x00;
		uint8_t tus1,tus2,ts1,ts2;	//4 bytes para el tiempo, arman abajo
		uint16_t tus,ts;
		uint8_t datoA,datoB,datoC,datoD;
		float timestamp;
		int contador_byte=0;
		int contador=0;
		long int tiempo_unix;// TIEMPO UNIX

	FILE* TSptr=fopen("TimeStamp.txt","w"); //Guardaremos el timestamp en un archivo aparte
	//Ponemos el puntero en el archivo
	FILE* fptr;
	//abrimos, si null , entonces no lo encontro sino seguimos
	if((fptr=fopen(archivo , "rb"))==NULL){
	printf("Error al abrir el archivo.");
	}else{		
		//While para recorrer todo el archivo
		/*FREAD: 1)a donde(PUNTERO)? 2)Tamaño en bytes? 3)Cuantos elementos? 4) De donde?
			Con fread leemos de a un solo byte y vamos guardandolo en auxbyte, que tiene
			respectivamente el tamaño de un byte o 8 bits. 
		*/

		while(!feof(fptr)){
			fread(&auxbyte, sizeof(uint8_t), 1, fptr);/*DIRECCION de auxbyte, porque fread
						necesita un puntero si o si, no maneja la
						variable*/
		/*A continuacion, deberemos identificar el inicio de trama primero que nada .
		Para ello, resetearemos primero el contador y los datos del tiempo a 0 una vez nos 
		pasemos de 16 bytes.
		*/
			if(contador_byte>=16){
				contador_byte=0;
				id=0;
				tus1=tus2=ts1=ts2=0;
				registro=0x00;
			}
		/*Procedemos a identificar el comienzo de trama,*/
			switch(auxbyte){
				case 0xFE: if(contador_byte==0){
						registro = 0x01;
						}break;
				case 0x08: if(contador_byte==1){
						registro = registro | 0x02;	//Registro en 0x03
						}break;
			}//end of switch
		//Si registro es igual a 3, osea identificamos FE 08 (inicio)
			if((registro%0xFC)==3){

				/*"""""""""RELEVAMIENTO DE DATOS""""""""
				En este punto ya podemos empezar a decodificar.
				Para ello utilizaremos el contador de bytes para
				posicionarnos en el dato que queremos obtener.
				*/

					switch(contador_byte){
						case 5: id=auxbyte;break;
						case 6: tus1=auxbyte;break;
						case 7: tus2=auxbyte;
							tus=(tus2<<8)+tus1;	/*Obtenemos el uS total 
											(ver cuaderno)
									*/
							break;
						case 8: ts1=auxbyte;break;
						case 9: ts2=auxbyte;
							ts=(ts2<<8)+ts1;	/*Obtenemos los S total 
										(ver cuaderno)
									*/
							break;
					//Obteniendo los datos del flujo (total, no solo el que deseamos)

						case 10: datoA=auxbyte;break;
						case 11: datoB=auxbyte;break;
						case 12: datoC=auxbyte;break;
						case 13: datoD=auxbyte;break;

						default: break;
					}//end of switch
					timestamp= ts + (float)tus/1000000;

					//PANTALLA DE PRUEBA DE TIEMPOS
					if(id==20 || id==21 || id==23){ //MOSTRAMOS EL TIMESTAMP Y EL DATO CUANDO LEAMOS LATITUD, LONGITUD O TIEMPO UNIX
						printf("\nDato #%d\tTimestamp: %f",contador, timestamp);
						//ESCRIBIENDO EN EL ARCHIVO "TIMESTAMP.TXT"
						fprintf(TSptr, "Dato: %d\t Timestamp: %f\n" , contador, timestamp);
					}

				//LECTURA DE LOS BYTES DE DATOS
				switch(id){
					case 20:printf("\t Latitud: %f ", norma(datoA,datoB,datoC,datoD));
						break;
					case 21:printf("\t Longitud: %f ",norma(datoA,datoB,datoC,datoD) );
						break;
					case 23:tiempo_unix=tiempounix(datoA,datoB,datoC,datoD);
					//	printf("El tiempo #UNIX es: %ld", tiempo_unix);
						break;
					default: break;
				}//end of switch
				
			}//end of if
		contador_byte++;
		contador++;
		}//end of while
	}//end of else

fclose (fptr);
fclose (TSptr);

	return 0;
}
//VER NORMA IEEE 754
float norma(uint8_t datoA, uint8_t datoB, uint8_t datoC, uint8_t datoD ){

	uint32_t num_crudo=(datoD<<24)+(datoC<<16)+(datoB<<8)+datoA;//little endian+ colocacion de los 32b
	int signo;
		if(num_crudo>>31)signo=-1;else signo=1;//If funciona al true o false
	uint8_t pre_exponente= num_crudo>>23;
	int exponente= pre_exponente-127;
	uint32_t corrimiento= 23-exponente;
	uint32_t despl_exp = num_crudo<<9>>9>>corrimiento;//corrimiento para dejar solo el numero
	int parte_ent= pow(2,exponente)+despl_exp;
	uint32_t mantisa=num_crudo<<(9+exponente)>>(9+exponente);
	uint32_t max_num= 0xFFFFFFFF;

	max_num=(max_num<<(9+exponente))>>(9+exponente);
	
	float parte_dec=((float)mantisa/(float)max_num);
	float numero=signo*((float)parte_ent+parte_dec);
	
	return numero;
}
long int tiempounix (uint8_t datoA, uint8_t datoB, uint8_t datoC, uint8_t datoD ){
		char* time;
		time_t tiempo=((datoD<<24)+(datoC<<16)+(datoB<<8)+datoA);
		
		time= ctime(&tiempo);
		
		printf("\t Tiempo Unix: %s", time);
		
	return tiempo;
	
}
