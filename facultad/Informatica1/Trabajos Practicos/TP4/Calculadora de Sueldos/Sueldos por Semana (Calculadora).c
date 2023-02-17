#include <stdio.h>
#include <stdlib.h>
/*Juarez Daniel Alejandro 
Leg: 79111 
Curso: 1R5 
Año: 2019 
Materia: Informatica_1*/

int main(void) {

int op;
float a,b,c;
char opc;
do
{
system ("cls");	
printf("***********************\n");
printf("CALCULADORA DE SUELDOS\n");                  /*menu de opciones del programa*/
printf("***********************\n\n");
	
printf("Elija una de las Opciones:\n");
printf("____________________________\n");
printf("|1_ Gerentes               | \n");
printf("|2_ Trabajadores por Hora  |\n");
printf("|3_ Trabajadores a Destajo |\n");
printf("|4_ Vendedores por comicion|\n");
printf("|Precione n para salir     |\n\n");

do
{
scanf("%d",&op);	
if(op>4)
system ("cls");	
printf("Opcion Invalida elija entre 1 y 4: ");
}while(op>4);

switch (op)
{
	
case 1 :
system ("cls");	

printf("******************\n");
printf("BIENVENIDO GERENTE\n");
printf("******************\n");
printf("Su Tasa de Sueldo es Fija por Semana\n");             /*el sueldo del gerente es fijo con carga horaria fija*/
printf("VALOR DE LA HS:_______________$350\n");               /*de lunes a viernes dias habiles*/
printf("HS TOTAL HABILES DE L_V:______40HS\n");	
printf("Sueldo Bruto a cobrar:________$%d\n",350*40);	

break;
		

case 2 :
system ("cls");	

printf("******************************\n");
printf("BIENVENIDO TRABAJADOR POR HORA\n");
printf("******************************\n");
printf("VALOR DE SU HS NORMAL: $145\n");                  /*El trabajador por hora tiene un extra del total de una hora*/
printf("VALOR DE SU HS EXTRA:  $218\n\n");                /*multiplicado por 1.5 lo que nos da $218 de ahi el valor propuesto*/
printf("Ingrese total de Hs normales de la semana: ");
scanf("%f",&a);	
printf("Ingrese total de Hs Extras de la semana: ");
scanf("%f",&b);

a*=145;
b*=218;
c=a+b;
printf("Sueldo Bruto a cobrar:________$%.2f\n",c);
	
break;


case 3 :
system ("cls");		
printf("*********************************\n");
printf("BIENVENIDO TRABAJADOR POR DESTAJO\n");         /*Se le paga por pieza producida al trabajaddor*/
printf("*********************************\n");            /*su sueldo varia dependiendo la productividad*/
printf("VALOR DE $ POR PEIZA FABRICADA: $130\n");
printf("Ingrese Total de piezas fabricadas: ");
scanf("%f",&a);	

a*=130;
printf("Sueldo Bruto a cobrar:________$%.2f\n",a);

break;


default:
system ("cls");	

printf("*********************\n");
printf("BIENVENIDO VENDEDORES\n");                   /*se les por venta, sueldo sin pizo y con un 5,7%+ del bruto*/
printf("*********************\n");                     /*total vendido en la semana*/
printf("VALOR DE PIEZA POR VENTA: $250\n");
printf("COMISION DEL BRUTO TOTAL: +5,7%\n");
printf("Ingrese total de ventas de la semana: ");
scanf("%f",&a);	
a*=250;
b=a*0.057;
c=a+b;
printf("Sueldo Bruto a cobrar:________$%.2f\n",c);
	
break;	
}

printf ("\n Desea Realizar otra operacion? s/n: ");
scanf("%s",&opc);
a=0; b=0;

}while(opc=='s');                                      /*parte del menu donde se pregunta is continuar o finalizar programa*/
                              
if(opc=='n')
system ("cls");
	
	return 0;
}
