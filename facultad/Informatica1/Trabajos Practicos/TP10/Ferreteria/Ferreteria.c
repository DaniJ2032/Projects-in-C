/*Juarez Daniel Alejandro 
Leg: 79111 
Curso: 1R5 
Año: 2019 
Materia: Informatica_1*/
#include <stdio.h>
#include <stdlib.h>


typedef struct hardware {
	
	int numero;
	char nombre[80];
	int stock;
	float precio;
	
}PAL_t;

void agregar(FILE *); void mostrar(FILE *);
void borrar(FILE *); void crear_txt(FILE *);
void menu (FILE *); int menu_option (void);

int main (void){
	FILE *fp= 0,*F=0;
	
	F = fopen("hardware.dat", "ab"); fclose(F);   	//Creo el Fichero
	
	fp = fopen("hardware.dat", "rb+"); //leo y escribo sobre el fichero con rb+
	menu(fp);                            //para poder posicionarme libremente
    fclose(fp);
	return 0;
}

void menu (FILE *fp){
	
	int op,salir = 0;
	
	do {
		op = menu_option();            //menu hacia las funciones
		switch (op) {
		case 1:
			agregar(fp);              
			break;
		case 2:
			borrar(fp);
			break;
		case 3:
			mostrar(fp);
			break;
		case 4:
			crear_txt(fp);
			break;
		case 5:
			salir = 1;
			break;
			
		default:
			printf("Opcion no Valida Elija una entre ( 1 - 5 )\n");
		}
	} while ( salir == 0 );
}

int menu_option (void)
{
	int op;
	printf("**********************\n");
	printf("FERRETERIA |EL FIERRO|\n");         //Interfaz del menu de opciones
	printf("**********************\n");
	printf("1- Agregar Articulo\n");
	printf("2- Borrar Articulo en Especifico\n");
	printf("3- Mostrar Lista de Articulos\n");
	printf("4- Crea un Archivo .txt para Impresion\n");
	printf("5- Salir del programa\n"); scanf("%d", &op);
	return op;
}

void agregar(FILE *fp){

	PAL_t agr;           //Agrego un articulo nuevo en el registro que desee 
	int num;  
	
	printf("\nIngrese el numero de Articulo del ( 1 - 100 ): ");scanf("%d",&num);
	
	fseek(fp, (num /*-1*/) *sizeof(PAL_t), SEEK_SET); 
	fread (&agr, sizeof (PAL_t), 1, fp);
	
	if(agr.numero!=0){
		
		printf("\nEl Registro ( %d ) esta ocupado, Seleccione Otro\n",num);}
	
	else{
		printf("\nNombre del Articulo: ");   scanf(" %80[^\n]s", agr.nombre);
		printf("Stock del Articulo: ");  fflush (stdin); scanf("%d", &agr.stock);
		printf("Precio del Articulo: ");  fflush (stdin); scanf("%f", &agr.precio);
		
		agr.numero = num;	
		fseek(fp, (agr.numero /*-1*/) *sizeof(PAL_t), SEEK_SET);
		fwrite (&agr, sizeof (PAL_t), 1, fp);
		
		printf("\n\nArticulo Guardado con Exito en el Archivo\n");
		
	}
	}


void mostrar(FILE *fp){
	

	
	char op;                 //Muestra los articulos en los registros llenos
	do{	
		PAL_t lee;
		fseek(fp, 0, SEEK_SET);
		
		printf("\t*********************************\n");
		printf("\tLISTADO DE ARTICULOS DISPONIBLES:\n");
		printf("\t*********************************");
		printf("\nCod\t Nombre\t\t\t\tStock\t\t Precio\t\t\n" );
		printf(" ***\t ******\t\t\t\t*****\t\t ******\t\t\n" );
		
		
		for(int i=0; i<100; i++){
			fread( &lee, sizeof (PAL_t),1,fp );
			if( lee.numero !=0 ){
				printf("%2d %20s %18d %20.2f \n",lee.numero, lee.nombre, 
					   lee.stock , lee.precio);}
		}
		printf("\n\n");	
		printf("Los registros que no figuran en lista estan vacios para Almacenamiento"
			   " de Articulos nuevos\n\n");
		printf("Oprimir ( s ) para volver o ( n ) para salir del Progrma: ");
		scanf("%s",&op);
		
		if(op=='n'){
			exit(1);}
		
	} while(op!='s');
}


void borrar(FILE *fp){
	
	int num;
	PAL_t brr;	                          //Borra un registro en Espesifico
	PAL_t limpio = {0, "", 0, 0.0};
	
	printf("Introduzca una registro del ( 1 - 100 ) para Eliminacion: ");
	scanf("%d",&num);
	
	fseek(fp, (num /*-1*/) *sizeof(PAL_t), SEEK_SET);
	fread (&brr, sizeof (PAL_t), 1, fp);
	
	if( brr.numero == 0){
		
		printf("\nEl registro %d no posee Informacion puede usarse" 
			   " para Almacenar\n\n",num);
	}
	else{
		
		fseek (fp, (num /*-1*/) *sizeof(PAL_t), SEEK_SET); 
		fwrite (&limpio, sizeof (PAL_t), 1, fp);
		
		printf("\nEl Articulo %d fue Eliminado del Registro\n", num);
	}	
}


void crear_txt (FILE*fp){
	

	
	FILE *ff;      //Crea un archivo .txt para Imprecion y lectura del usuario
	PAL_t crea = {0, "", 0, 0.0};
	
	if( (ff = fopen( "El Fierro Articulos.txt", "w")) == NULL ){
		printf("No se Pudo Abrir el Archivo Solicitado\n");}
	
	else{
		rewind(ff);
		fprintf(ff,"\t*********************************\n");
		fprintf(ff,"\tLISTADO DE ARTICULOS DISPONIBLES:\n");
		fprintf(ff,"\t*********************************");
		fprintf(ff,"\nCod\t\t Nombre\t\t\tStock\t\t Precio\t\n" );
		fprintf(ff,"***\t\t ******\t\t\t*****\t\t ******\t\n" );
		
		
		for(int i=0; i<100; i++){
			fread(&crea, sizeof (PAL_t),1,fp);
			if(crea.numero !=0){
				fprintf(ff,"%2d %20s %20d %18.2f \n",crea.numero, crea.nombre, 
						crea.stock , crea.precio);}	
			
			
		}
		fclose(ff);
	}
	printf("Guardando porfavor espere: ");
	printf("|100 Guardado con exito!!!\n\n");
	}

	
