/*Cabecera huva.h para el archivo huva.c*/

#ifndef HUVA_H_INCLUDED
#define HUVA_H_INCLUDED
#define HUMMAX 30.00
#define HUMMIN 5.00larma
#define Archivo "MedicionVignedo.bin" //Archivo a leer le definimos un nombre
/******************************ESTRUCTURAS**********************************/
typedef struct Ambiental{

float TempAmb; //Temp Ambiente
float HumAmb; //Humedad Hambiente
float RadSol; //Radiacion Solar

}AMB_t;

typedef struct Suelo{

float TempSue; //Temp del Suelo
float HumSue; //Humedad del Suelo

}SUELO_t;


typedef struct NuevSurco{

int ID;
int Surco;
char* Zona;
char* VardUva; //Variedad de Uva
int HumMaxAdmi; //Hum Maxima Admisible
int HumMinAdmi; //Hum Minima Admisible
char *FechCosh; //Fecha de la Cosecha del surco
char *UXTime;
}NUEVOSURC_t;

typedef struct nodo{ //Para enlazar nuevos nodos de la lista
		
AMB_t ambiente; 
SUELO_t suelo;     //Enlace a las demas estructuras
NUEVOSURC_t surco;
struct nodo* sig; //Variable struct nodo para Enlazar

}Nodo;
/******************************************************************************/

/*************************PROTOTIPOS DE FUNSIONES*****************************/


/*Recibe un int opc y pregunta que opcion escojer
RETORNA: un calor entero de la opcdion para el menu principal*/
int Menu_Principal(void);

/*Encargadod e leer el archivo binario de los sensores y en base a los datos leidos se mueve a mutiples funciones
Retorna: el valor del incio*/
Nodo *LevantaDatos( Nodo* );

/*Cargo los datos levantados del archivo Binario como el ID, Zona, Nro de surco y evaluo que mensaje me llego en base al ID
RETORNA: valor del inicio*/
Nodo *CargoDatos( Nodo*, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t );

/*Menu de seleccion automatidco de mensajes en vase al vlor del ID es el mensaje recibido de los datos
RETORNA: Nada*/
void CargoMensaje( Nodo*, uint8_t, uint8_t, uint8_t );

/*Cargo los datos ambientales de los archivos temp ambiente, humedad y Radiacion Solar*/
void DatosAmbiental(Nodo*, uint8_t, uint8_t, uint8_t  );

/*Cargo los datos del suelo temperatura y la humedead*/
void DatosSuelo( Nodo* nuevo, uint8_t, uint8_t, uint8_t  );

/*Si en mi trama no se encontro una ID entonces se almacenara un nuevo nodo con los datos que se le pide*/
void DatoNuevoSurco( Nodo* nuevo, uint8_t, uint8_t, uint8_t );

/*Obtengo el tiempo, paso valores en formato little Endian los dopy vuelta e imprimo el tiempo como cadena de texto y almaceno*/
void Tiempo( Nodo* uint8_t, uint8_t, uint8_t, uint8_t );

/*Pregunto si no existe la ID que cargo entonces ashi se carga el nuevo nodo*/
uint8_t CargarNuevoSurco( void );

/*Elimino un surcoq ue ya no esta*/
Nodo *EliminaSurco(Nodo* );
/*Veo las alarma de los sensores de humedead si falta o esta en ecxeso y despues lo almaceno en un archivo*/
AlarmaHum( uint8_t, uint8_t, Nodo* );
/*Una vez los datos levantados se almacena todo lo recopilado en un .txt para archivo historico de lectura ys e ira actualizando*/
int AlmacenoArchivoVignedo( Nodo* );
/*Almaceno las alarmas una vez que las evaluo*/
int AlmacenoAlarma(uint8_t Alarma, Nodo* nuevo);



















#endif //Fin de Definicion de Cabecera
