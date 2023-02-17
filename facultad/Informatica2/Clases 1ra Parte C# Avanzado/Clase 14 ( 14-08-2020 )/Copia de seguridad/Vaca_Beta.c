#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

typedef struct Animal{


char *duegno;
char *LugaryFecha; 
char *raza;
char *genero; 
char *lugFaena; 
char *fchFaena;
}VACA_t;

typedef struct Medicion{

int ID;
float latitud; 
float longitud;
float temp;
float humedad;
float tempCorp;
float ritCard;
char *UXtime;
	
}SENSOR_t;

typedef struct nodo{
		
SENSOR_t sensor;
VACA_t vaca;
struct nodo* sig;

}Nodo;
Nodo *inicio = NULL;

/************************PROTOTIPOS*********************************/	

int Menu_Principal( void );
Nodo *CargaVaca( Nodo* );
void CargaSensores( Nodo* );
Nodo *MostrarGanado( Nodo* );
int guardarVacas( Nodo* );
int GuardarSensores( Nodo* );

int main (){

int opc;
do{
	opc = Menu_Principal();
	
    switch(opc){
		
    case 1:
        inicio = CargaVaca( inicio ); 
        break;

    case 2:
        printf("\n****Vacas Agregadas****\n");
        inicio = MostrarGanado( inicio );
        break;        

    }//Fin del switch();

}while(opc != 0 ); //Se repite hasta que sea distinto de 13
return 0;
}//FIn del main();  

Nodo *CargaVaca( Nodo* inicio ){
	
Nodo *nuevo, *ptr;	
char  opc, Nomb[50], LugyFech[200], Raza[30], Genero[20]/*LugFae[50], FechFae[15]*/;
	
nuevo = (Nodo*)malloc (sizeof(Nodo));


    printf("ID de la Vaca: "); scanf("%d",&nuevo->sensor.ID);
	printf("Nombre del Propietario: "); scanf(" %50[^\n]s",Nomb);
	printf("Lugar y Fecha de Nacimiento: "); scanf(" %200[^\n]s",LugyFech);
	printf("Raza: "); scanf(" %30[^\n]s",Raza);
	printf("Genero: "); scanf(" %20[^\n]s",Genero);
	//printf("Lugar de Faena: "); scanf(" %50[^\n]s",LugFae);
	//printf("Fecha de Faena: "); scanf(" %15[^\n]s",FechFae);
    nuevo->vaca.duegno = (char*)malloc((strlen(Nomb)+1)*sizeof(char));
	nuevo->vaca.LugaryFecha = (char*)malloc((strlen(LugyFech)+1)*sizeof(char));
	nuevo->vaca.raza = (char*)malloc((strlen(Raza)+1)*sizeof(char));
	nuevo->vaca.genero = (char*)malloc((strlen(Genero)+1)*sizeof(char));

	strcpy( nuevo -> vaca.duegno, Nomb);
	strcpy( nuevo -> vaca.LugaryFecha, LugyFech);
	strcpy( nuevo -> vaca.raza, Raza);
	strcpy( nuevo -> vaca.genero, Genero);

    printf("Quieres Cargar los datos de los Sensores? precione [Y]: ");
    scanf("%s",&opc);
        if('y' == opc || 'Y' == opc)    
            CargaSensores (nuevo);


    guardarVacas( nuevo );	
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

	//nuevo->vaca.lugFaena = (char*)malloc((strlen(LugFae)+1)*sizeof(char));
	//nuevo->vaca.fchFaena = (char*)malloc((strlen(FechFae)+1)*sizeof(char));
	//strcpy( nuevo -> vaca.lugFaena, LugFae);
	//strcpy( nuevo -> vaca.fchFaena, FechFae);
		
return inicio;

}//Fin de la Funsion CargaVaca;

void CargaSensores(Nodo* nuevo){

    printf("\nGPS: \n");
    printf("Latitud: "); scanf("%f",&nuevo->sensor.latitud );
	printf("Longitud: "); scanf("%f",&nuevo->sensor.longitud );

	printf("\nAMBIENTE: \n");
	printf("Temperatura Ambiente: "); scanf("%f",&nuevo->sensor.temp );
	printf("Humedad: "); scanf("%f",&nuevo->sensor.humedad) ;
	printf("\nANIMAL: \n");
	printf("Temperatura Corporal: "); scanf("%f",&nuevo->sensor.tempCorp );
	printf("Ritmo Cardiaco: "); scanf("%f",&nuevo->sensor.ritCard );   
   
    GuardarSensores( nuevo );
}//Fin de Funsion CargaSensores


Nodo *MostrarGanado(Nodo* inicio){
	
Nodo *ptr;
ptr = inicio;
		
		
while(ptr != NULL){
			
	printf("\n******************DATOS DE LA VACA********************\n\n");
	printf("Nombre del Propietario: ( %s )\n", ptr -> vaca.duegno);
	printf("Lugar y Fecha de Nacimiento: ( %s )\n", ptr -> vaca.LugaryFecha);
	printf("Raza: ( %s )\n", ptr -> vaca.raza);
	printf("Genero: ( %s )\n", ptr -> vaca.genero);
	//printf("Lugar de Faena: ( %s )\n", ptr -> vaca.lugFaena);
	//printf("Fecha de la Faena: ( %s )\n", ptr -> vaca.fchFaena);
	printf("\n******************************************************\n\n");
		
	printf("\n*********************SENSORES*************************\n\n");
	printf("ID de la Vaca: [ %d ]\n", ptr -> sensor.ID );
	printf("Latitud: [ %.2f ]\n", ptr -> sensor.latitud ); 
	printf("Longitud: [ %.2f ]\n", ptr -> sensor.longitud ); 
	printf("Temperatura Ambiente: [ %.2f ]\n", ptr -> sensor.temp );
	printf("Humedad: [ %.2f ]\n", ptr -> sensor.humedad ); 
	printf("Temperatura Corporal: [ %.2f ]\n", ptr -> sensor.tempCorp );
	printf("Ritmo Cardiaco: [ %.2f ]\n", ptr -> sensor.ritCard );
	printf("\n******************************************************\n\n");
	ptr = ptr ->sig;		
	}//Fin del while();

return inicio;	
}

	
int Menu_Principal(void){
		
int opc;
		
	printf("\n\n**** MENU PRINCIPAL *****\n");
	printf("\n ( 1 ) Cargar una Vaca");  
	printf("\n ( 2 ) Mostrar Lista del Ganado Vacuno");
	printf("\n ( 0 ) Salir del Programa."); 
	printf("\n\n Ingrese una Opcion: ");    
	scanf("%d",&opc);
		
return opc;	
}//Fin de la Funsion Menu_Principal();
		


int guardarVacas( Nodo* archVaca ){
	
FILE* ff = NULL;
int Ident = ( archVaca -> sensor.ID );

char fileName[9999];

    
    snprintf(fileName, sizeof(fileName),"Vaquita %d.txt",Ident);

	
	if((ff = fopen( fileName,"w")) == NULL ){
		printf("No se Pudo Abrir el Archivo Solicitado\n");
        return -1;
    }

    fprintf(ff,"Nombre del Dueño: %s\n", archVaca -> vaca.duegno);	 
    fprintf(ff,"Lugar y Fecha de Nacimiento: %s\n", archVaca -> vaca.LugaryFecha);	
    fprintf(ff,"Raza del ANimal: %s\n", archVaca -> vaca.raza);	
    fprintf(ff,"Sexo del ANimal: %s\n", archVaca -> vaca.genero);	                            
	fclose(ff);

return 0;
}

int GuardarSensores( Nodo* archDat ){
	
FILE* ff = NULL;
int Ident = ( archDat -> sensor.ID );
char fileName[9999];

   
    snprintf(fileName, sizeof(fileName),"SenVaca %d.txt",Ident);

	
	if((ff = fopen( fileName,"w")) == NULL ){
		printf("No se Pudo Abrir el Archivo Solicitado\n");
        return -1;
    }
    fputs("GPS: \n",ff);
    fprintf(ff,"Latitud: %f\n", archDat -> sensor.latitud);	 
    fprintf(ff,"Longitud: %f\n", archDat -> sensor.longitud);

    fputs("\nAmbiente: \n",ff);                                            	
    fprintf(ff,"Temperatura Ambiente: %f\n", archDat -> sensor.temp);	    
    fprintf(ff,"Humedad: %f\n", archDat -> sensor.humedad);
	
    fputs("\nANIMAL: \n",ff);                              
    fprintf(ff,"Temperatura del Animal: %f\n", archDat -> sensor.tempCorp);	    
    fprintf(ff,"Ritmo Cardiaco: %f\n", archDat -> sensor.ritCard);

	fclose(ff);

return 0;
}












































