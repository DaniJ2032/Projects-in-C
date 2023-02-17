#include <stdio.h>

typedef struct stock {
	
	int numcta;
	char apellido [15];
	char nombre [15];
	float saldo;	
}S_t;

int intopcion (void);
void archivo_texto(FILE *f);
void actualizar_reg(FILE *f);
void nuevo_reg(FILE *f);
void eliminar_reg(FILE *f);

int main(){
	
	FILE *f;
	int selec;
	
	if((f = fopen( "hardware.dat", "rb+") ) == NULL ) {
		
		printf("No se Pudo Abrir el Archivo Solicitado\n");}
	
	else {
		
		while (( selec = intopcion () ) != 5 ){
			
			switch (selec){
				
			case 1:	
				archivo_texto(f);
				break;
				
			case 2:	
				actualizar_reg(f);
				break;
				
			case 3:
				nuevo_reg(f);
				break;
				
			case 4:
				eliminar_reg(f);
				break;
				
			default:
					printf("Opcion Incorrecta elija una entre 1-4\n");	
				break;
				
			}
			
		}
		fclose(f);
	}
	
	return 0;	
}

void archivo_texto(FILE *f){
	
	FILE *fesc;
	
	S_t cliente = {0, "", "", 0.0};
	
	if( (fesc = fopen( "ferreteria.txt", "w")) == NULL ){
		printf("No se Pudo Abrir el Archivo Solicitado\n");
	}	
	
	else{
		rewind(f);
			fprintf(fesc,"%-6s%-16s%-11s%10s\n","cta" "apellido" "nombre" "saldo");
	
		while (!feof (f)){
			
			fread( &cliente, sizeof (S_t),1,f);
			
			if(cliente.numcta != 0){
			fprintf(fesc, "%-6d %-16s %-11s %10.2f\n",cliente.numcta, cliente.apellido, 
						cliente.nombre, cliente.saldo);
			}
	}
		
		
	}
	
 flcose(fesc);
}

void actualizar_reg(FILE *f){
	
	int cuenta;
	float trans; 
	
	S_t cliente = {0, "", "", 0.0};
	
	printf("Introduzca una cuenta del ( 1 - 100 ) para Actualizacion: ");
	scanf("%d",&cuenta);
	
	fseek(f, (cuenta -1) *sizeof(S_t), SEEK_SET); 
	
	fread (&cliente, sizeof (S_t), 1, f);
	
	if(cliente.numcta ==0){
		
		printf("La cuenta %d no posee informacion\n",cuenta);
	}
	else{
		printf("%-6d %-16s %-11s %10.2f\n\n", cliente.numcta, cliente.apellido, 
			   cliente.nombre, cliente.saldo);	
		printf("Introduzca el cargo ( + ) o el Pago ( - ): ");
		scanf("%f",&trans);
		cliente.saldo += trans; 
		
		printf("%-6d %-16s %-11s %10.2f\n\n", cliente.numcta, cliente.apellido, 
			   cliente.nombre, cliente.saldo);
		
		fseek(f, (cuenta -1) *sizeof(S_t), SEEK_SET);	
		
		fwrite (&cliente, sizeof (S_t), 1, f);	
	}
	
}


void eliminar_reg(FILE *f){
	
	int num;
	
	S_t cliente;	
	S_t cliente_bank = {0, "", "", 0.0};
	
	printf("Introduzca una cuenta del ( 1 - 100 ) para Eliminacion: ");
	scanf("%d",&num);
	
	fseek(f, (num -1) *sizeof(S_t), SEEK_SET);
	fread (&cliente, sizeof (S_t), 1, f);
	
	if(cliente.numcta == 0){
		
		printf("La cuenta %d no posee informacion\n",num);}
	
	else{
		
		fseek(f, (num -1) *sizeof(S_t), SEEK_SET);
		
		fwrite (&cliente_bank, sizeof (S_t), 1, f);
		
	}
}


void nuevo_reg(FILE *f){
	
	
	int num;
	
	S_t cliente= {0, "", "", 0.0};
	
	printf("Introduzca un nuevo numero de cuenta del ( 1 - 100 ): ");
	scanf("%d",&num);
	
	fseek(f, (num -1) *sizeof(S_t), SEEK_SET);	
	
	fread (&cliente, sizeof (S_t), 1, f);
	
	if(cliente.numcta !=0){
		
		printf("La cuenta %d ya posee Informacion\n",cliente.numcta);}
	
	else{
		
		printf("Introduzca el Apellido, Nombre y Saldo: ");
		scanf("%s %s %f",cliente.apellido, cliente.nombre, &cliente.saldo);
		
		cliente.numcta = num;
		
		fseek(f, (cliente.numcta -1) *sizeof(S_t), SEEK_SET);
		fwrite (&cliente, sizeof (S_t), 1, f);
	}	
}


int intopcion (void){
	
	int opc;
	
	printf("Introduzca una Opcion\n"
		   "1 - Almacena un Archivo.txt para impresion\n"
		   "2 - Actualizar una cuenta\n"
		   "3 - Agrega una Cuenta Nueva\n"
		   "4 - Elimina una Cuenta\n"
		   "5 - Salir del Programa\n");
	scanf("%d",&opc);
	
	return opc;
	
}


