#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "huva.h"

/*Funcion del Menu Principal */
int Menu_Principal(void){
		
int opc;
		
	printf("\n\n*********** MENU PRINCIPAL **********\n");
	printf("\n ( 1 ) Enlistar Viñedos");  
	printf("\n ( 2 ) Cargar Nuevo Surco");
	printf("\n ( 3 ) Elimina Surco Cosechado");
	printf("\n ( 0 ) Salir del Programa."); 
	printf("\n\nIngrese una Opcion: ");  
	scanf("%d",&opc);
    printf("\n*************************************\n\n"); 

		
return opc;	
}//Fin de la Funsion Menu_Principal();

uint8_t CargarNuevoSurco( inicio ){

File *ffb;       
uint8_t unbyte, IDNew, registro = 0x00;
int contador = 0;


printf("Ingrese una ID nueva para el surco: \n"); scanf("%d",&num);


	if(( ffb = fopen(Archivo, "rb" )) == NULL)//Abrimos el Archivo como Lectura Binaria
		printf("\n\nEL Archivo de Datos no se Puede Abrir\n\n");	

	while(!feof(ffb)){
		fread(&unbyte, 1, 1, ffb);//Leemos el tamaño de unbyte desde ffb un dato y lo guardamos en unbyte 
	
		if(contador >= 10 ){
			contador = 0;//Vuelva el Contador a cero	
			registro = 0x00;
			}//Fin del if();	
		
		    if( unbyte == 0xFE && contador == 0 )//Coloco a 1 el  Bit 0 de registro
				registro = 0x01;
            		    
                if(contador == 3 && unbyte == 0x41 || contador == 3 && unbyte == 0x42 ){
                    if( unbyte == 0x41 && registro == 0x01 || unbyte == 0x42 && registro == 0x01 )//Pasamos al segundo byte
				        registro = 0x02 | registro; //Coloco un 0x03 en el registro con esto me aseguro de 
                }                                   //leer bien el inicio e identificar el establecimiento;                              
                                      
				if( registro% 0xFC == 3 ){
                    if (contador == 6 && unbyte != IdNew) 
                        return opc = 0x04;        //Si no encontro la ID ents se puede almacenar el nuevo Nodo
                }//Fin del if()

    }//Fin del while  
fclose(fptr);//Cierro el puntero de archivo
      
return 0;   
}//Fin de la funcion CargarNuevoSurco();

Nodo *LevantoDatos( Nodo* inicio, int opc ){ //Levantamos los datos de nuestro Archivo .bin

FILE *ffb;
int contador = 0;//Contador de Lineas de Trama avanzo en el Archivo	
uint8_t Establ, surco;	
uint8_t unbyte, ID;//Variable para leer 1 Byte = 8 bits y Dectectar el ID
uint8_t registro = 0x00;//Usada para detectar la trama de inicio y obviar la basura
uint8_t byteA, byteB, byteC, byteD; //Variables para los datos y el tiempo Unix

nuevo = (Nodo*)malloc (sizeof(Nodo));

	if(( ffb = fopen(Archivo, "rb" )) == NULL)//Abrimos el Archivo como Lectura Binaria
		printf("\n\nEL Archivo de Datos no se Puede Abrir\n\n");	

	while(!feof(ffb)){
		fread(&unbyte, 1, 1, ffb);//Leemos el tamaño de unbyte desde ffb un dato y lo guardamos en unbyte 
	
		if(contador >= 10 ){
			contador = 0;//Vuelva el Contador a cero	
			registro = 0x00;
			}//Fin del if();	
/*****************************************************************************/			
		    if( unbyte == 0xFE && contador == 0 )//Coloco a 1 el  Bit 0 de registro
				registro = 0x01;
            		    
                if(contador == 3 && unbyte == 0x41 || contador == 3 && unbyte == 0x42 ){
                    if(unbyte == 0x41)          
                       Establ = unbyte; //Almaceno el valor en Establecimiento       
                    if(unbyte == 0x42)          
                       Establ = unbyte;                                     
			        if( unbyte == 0x41 && registro == 0x01 || unbyte == 0x42 && registro == 0x01 )//Pasamos al segundo byte
				        registro = 0x02 | registro; //Coloco un 0x03 en el registro con esto me aseguro de 
                }                                   //leer bien el inicio e identificar el establecimiento;                              
                                      
				if( registro% 0xFC == 3 ){
                            
                  	if( contador == 4 )
					    surco = unbyte; //En la posicion 4 tenemos el N de surco 
					//Fin del if()                    
                    else if (contador == 6 )
                        ID = unbyte;        //En la posicion 6 tenemos el ID
                    else if( contador == 8 )
						byteA = unbyte;	//EL 8 esta el dato del byteA (Mensaje)
	                else if( contador == 10 )
					    byteB = unbyte; //EL 10 esta el dato del byteB (Mensaje)
                    else if( contador == 12 ){
						byteC = unbyte; //El 12 esta el dato del byteC (Mensaje)       
                        CargoDatos( nuevo, Estable, surco, ID, byteA, byteB, byteC);  
                        CargoNUevoSurco( byteA, byteB, byteC);          
                    }//Fin de los else if anidados

                    else if (contador == 14 )
                        TbyteA = unbyte;        
                    else if( contador == 16 )
						TbyteB = unbyte;	     //Almaceno el tiempo en cada Tbytex       
	                else if( contador == 18 )
					    TbyteC = unbyte; 
                    else if( contador == 20 ){
						TbyteD = unbyte; 
                                
                        Tiempo(nuevo, TbyteA, TbyteB, TbyteC, TbyteD); //Busco la Hora Unix            
                    }//Fin de los else if anidados

                }//Fin del if ( registro% 0xFC == 3 )
                contador++; //Incremento el contador para avanzar en la trama
}//fin del while();
    fclose(ffb);

return inicio;
}//Fin de la funcion LevantoDatos

/*Una vez levantados cargamos los datos a la lista*/

Nodo *CargoDatos(Nodo *nuevo, uint8_t Estable, uint8_t surco, uint8_t ID, uint8_t byteA, uint8_t byteB, uint8_t byteC ){

Nodo *ptr;  


        if ( Estable == 0x041 ){
            char nomb["Cafayate"];

                nuevo -> surco.ID =(int) (surco+Estable)-1+100; //Almaceno el ID del surco
                nuevo -> surco.Zona = (char*)malloc((strlen(nomb)+1)*sizeof(char)); //Reservo memoria dinamica a mi string dinamico en mi estructura
                strcpy( nuevo -> surco.Zona, Nomb); //Copio la cadena

        /*Repito el mismo paso*/
        }else if ( Estable == 0x042 ){
            char nomb2["Valle de UCO"];

                nuevo -> surco.ID =(int) (surco+Estable)-2+100; //Almaceno el ID del surco
                nuevo -> surco.Zona = (char*)malloc((strlen(nomb2)+1)*sizeof(char));
                strcpy( nuevo -> surco.Zona, Nomb);  
              
        }//Fin del los if() else anidados

        CargoMensaje (nuevo, ID, byteA, byteB, byteC );

        AlmacenoArchivoVignedo(nuevo);
        
        	if( inicio == NULL){

		    nuevo -> sig = NULL;
	    	inicio = nuevo
	    }else{
	    	ptr = inicio;
       
	        	while( ptr -> sig !=NULL )
	        		ptr = ptr -> sig;
                //Fin del while
	    	nuevo -> sig = NULL;
	    	ptr -> sig = nuevo;
	    }//Fin del if() else 

return inicio;
}//Fin de la Funsion CargoDatos();


void CargoMensaje(Nodo* nuevo, uint8_t ID, uint8_t byteA, uint8_t byteB, uint8_t byteC ){

    ID = CargarNuevoSurco(); //Si devuelve un 0x04 ents almaceno nuevo nodo

    switch(ID){
    
        case 1: DatosAmbiental(nuevo, byteA, byteB, byteC ); break;

        case 2: DatosSuelo( nuevo, byteA, byteB, byteC ); break;

        case 4:  DatoNuevoSurco( nuevo, byteA, byteB, byteC ); break;

    }//Fin del switch()


}//Fin de la funsion CargoMensaje

/*Si entramos al case 1: son Datos Ambientales*/
void DatosAmbiental(Nodo* nuevo, uint8_t byteA, uint8_t byteB, uint8_t byteC ){

nuevo -> ambiente.TempAmb = (float) byteA; //Convierto la variable a float y almaceno     
nuevo -> ambiente.HumAmb = (float) byteB; //Convierto la variable a float y almaceno 
nuevo -> ambiente.RadSol = (float) byteC; //Convierto la variable a float y almaceno 
nuevo -> sig = NULL;
}//Fin de Funcion DatosAmbiental


/*case 2: Datos del Suelo*/
void DatosSuelo( Nodo* nuevo, uint8_t byteA, uint8_t byteB, uint8_t byteC ){

nuevo -> suelo.TempSue = (float) byteB; //Convierto la variable a float y almaceno     
nuevo -> suelo.HumSue = (float) byteC; //Convierto la variable a float y almaceno 
//byteA se lo ignora
nuevo -> sig = NULL;
}//Fin de Funcion DatosSuelo



/*case 4: Datos del Nuevo Surco*/
void DatoNuevoSurco( Nodo* nuevo, uint8_t byteA, uint8_t byteB, uint8_t byteC ){

Nodo *ptr;

char lug;
int num;

printf("Escoja Establecimiento:\n"); printf("( A ): Cafayate. \n"); printf("( B ): Valle de Uco\n"); scanf("%c",&lug);
printf("Nro de Surco: \n"); scanf("%d",&num);

        if ( lug =='A' || lug == 'a'){
            char nomb["Cafayate"];

                nuevo -> surco.Zona = (char*)malloc((strlen(nomb)+1)*sizeof(char)); 
                strcpy( nuevo -> surco.Zona, Nomb);
        /*Repito el mismo paso*/
        }else if ( lug =='B' || lug == 'b' ){
            char nomb2["Valle de UCO"];
                nuevo -> surco.Zona = (char*)malloc((strlen(nomb2)+1)*sizeof(char));
                strcpy( nuevo -> surco.Zona, Nomb);  
           
        }//Fin del los if() else anidados

    nuevo -> surco.Surco = num;
    
    if( byteA == 0x01 ){
        char nomb["Malbec"];
            nuevo -> surco.VardUva = (char*)malloc((strlen(nomb)+1)*sizeof(char)); 
            strcpy( nuevo -> surco.VardUva, Nomb);    
      
    }else if( byteA == 0x02 ){
        char nomb["Merlot"];
            nuevo -> surco.VardUva = (char*)malloc((strlen(nomb)+1)*sizeof(char)); 
            strcpy( nuevo -> surco.VardUva, Nomb);  
  
    }else if( byteA == 0x04 ){
        char nomb["Cabernet Sauvignon"];
            nuevo -> surco.VardUva = (char*)malloc((strlen(nomb)+1)*sizeof(char)); 
            strcpy( nuevo -> surco.VardUva, Nomb);   
 
    }else if( byteA == 0x08 ){
        char nomb["Pinot Negro"];
            nuevo -> surco.VardUva = (char*)malloc((strlen(nomb)+1)*sizeof(char)); 
            strcpy( nuevo -> surco.VardUva, Nomb);    
    }//Fin de los if else anidados

    nuevo -> surco.HumMaxAdmi = (float) byteB; //Almaceno la HUmedad Maxima Admisible
    nuevo -> surco.HumMinAdmi = (float) byteC; //Almaceno la HUmedad Minima Admisible 
    AlarmaHum (byteB , byteC, nuevo);
          
    nuevo -> sig = NULL;

	    if(inicio == NULL){
		    nuevo -> sig = NULL;
	    	inicio = nuevo;
		
	    }else{
	    	ptr = inicio;
       
	        	while( ptr -> sig !=NULL )
	        		ptr = ptr -> sig;
                //Fin del while
	    	nuevo -> sig = NULL;
	    	ptr -> sig = nuevo;
	    }//Fin del if() else    

}//Fin de la Funcion DatoNuevoSurco

void AlarmaHum( uint8_t byteB, uint8_t biteC, Nodo* nuevo ){

uint8_t Alarma = 0x00;


    if(nuevo -> surco.HumMaxAdmi > HUMMAX){    
        Alarma = 0x01;
        AlmacenoAlarma (nuevo, Alarma);

    }else if(nuevo -> surco.HumMinAdmi > HUMMIN)    
        Alarma = 0x00;
        AlmacenoAlarma(nuevo, Alarma);
    }
}//FInd e la Funcion AlarmaHum();


void Tiempo(Nodo *nuevo uint8_t TbyteA, uint8_t TbyteB, uint8_t TbyteC, uint8_t TbyteD ){

char *UXtime; //Variable char* para que me devuelva el tiempo como un string

time_t time =(byteD<<24) + (byteC<<16) + (byteB<<8) + byteA; //Dato en crudo para el tiempo

UXtime = ctime(&time);//Convierto el valor numerico del IEEE754 y se lo paso al puntero *time 
	
	printf("\n\nTiempo Unix es: %s", UXtime);//Imprimo el tiempo
    nuevo -> surco.UXtime = UXtime;//ALmaceno el tiempo Unix de los sensores
 nuevo -> sig = NULL;   
}//Fin de la Funsion ObtenerTiempo();	



/*Elimino un surco que ya no esta*/
Nodo *EliminaSurco(Nodo *inicio){

Nodo *ptr, *preptr;
int val; 
ptr = inicio; //coloco el puntero al inicio

    printf("\nIngrese el ID del Surco a Eliminar: "); scanf("%d",&val);

	if (ptr -> surco.ID == val){ //si el valor ingresado es igual al dato
		
        inicio = inicio -> sig;
        free(ptr);

		return inicio;
	}
	else{
	  	while (ptr -> surco.ID != val){ //si no es el encabezado lo busca
	  		
	  		preptr = ptr;
	  		ptr = ptr -> sig;
		  }//fin del while	

		preptr -> sig = ptr -> sig; // debe enlazar el dato anterior con el posterior
		free (ptr); //borra el nodo cuando lo encuentra
        return inicio;
	}//fin del if()else		

}//fin de funcion CargarVacaFaeneada();	

/*GUardo todo en un archvio de texto para leerlo despues*/
int AlmacenoArchivoVignedo( Nodo* VinArch ){


FILE* ff = NULL;

	if((ff = fopen( "ViñedoRegistro.txt","w")) == NULL ){
		printf("No se Pudo Abrir el Archivo Solicitado\n");
        return -1;
    }

    fputs("ID DEL SURCO: \n",ff);
    fprintf(ff,"( %d )\n", VinArch -> surco.ID);

    fputs("ESTABLECIMIENTO: \n",ff);
    fprintf(ff,"Nombre: ( %s )\n", VinArch -> surco.Zona);	
 
    fputs("Nro de Surco: \n",ff);	
    fprintf(ff,"( %d )\n", VinArch -> surco.Surco);	

    fputs("VARIEDAD: \n",ff);
    fprintf(ff,"[ %s ]\n", VinArch -> surco.VardUva);	
    
    fputs("Fecha y Hora: \n",ff);
    fprintf(ff,"[ %s ]\n", VinArch -> surco.UXTime);	

    fputs("HUMEDAD DEL SURCO \n",ff);
    fprintf(ff,"[ %.5f ]\n", VinArch -> suelo.HumSUe);
    
    fputs("TEMPERATURA DEL SURCO: \n",ff);
    fprintf(ff,"[ %.5f ]\n", VinArch -> suelo.TempSue);

    fputs("HUMEDAD AMBIENTE: \n",ff);
    fprintf(ff,"[ %.5f ]\n", VinArch -> ambiente.HumAmb);

    fputs("TEMPERATURA AMBIENTE: \n",ff);
    fprintf(ff,"[ %.5f ]\n", VinArch -> ambiente.TempAmb);

    fputs("RADCIACION SOLAR: \n",ff);
    fprintf(ff,"[ %.5f ]\n", VinArch -> ambiente.RadSolar);

	fclose(ff);

return 0;

}//Fin de la Funcion AlmacenoArchivoVignedo(); 

/*Se almacena el registro de la Alarma*/
int AlmacenoAlarma(uint8_t Alarma, Nodo* nuevo){

FILE *ff = NULL;

    if((ff = fopen( "ViñedoRegistro.txt","a")) == NULL ){
		printf("No se Pudo Abrir el Archivo Solicitado\n");
        return -1;
    }
    
    fprintf(ff,"Alarma: ( %n )\n", Alarma);	 
    fclose ( ff );

return 0;
}//Fin de la Funcion AlmacenoAlarma();









