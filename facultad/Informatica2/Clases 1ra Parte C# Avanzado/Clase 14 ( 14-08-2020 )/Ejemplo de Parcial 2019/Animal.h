#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

/************************PROTOTIPOS*********************************/	
typedef struct Animal{


char *duegno;
char *LugaryFecha; 
char *raza;
char *genero; 
//char *lugFaena; 
//char *fchFaena;
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
//Nodo *inicio = NULL;


int Menu_Principal( void );
Nodo *CargaVaca( Nodo* );
void CargaSensores( Nodo* );
void printTime( Nodo* );
Nodo *MostrarGanado( Nodo* );
Nodo *CargarVacaFaeneada( Nodo* );
int GuardarVacas( Nodo* );
int GuardarSensores( Nodo* );
int GuardarFaena( Nodo* );

#endif
