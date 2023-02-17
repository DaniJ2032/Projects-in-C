#include <stdio.h>
#include <stdlib.h>

extern int operacion(int a, int b, int opc);

int main (void){

    int a = 0;
    int b = 0;
    int c = 0;
    int opc;

    printf("___________Calculadora Ejercicio 1 ____________     \n");
    printf("opcion ( 1 ) Suma                                   \n");
    printf("opcion ( 2 ) Resta                                  \n");
    printf("opcion ( 3 ) Operacion logica AND                   \n");
    printf("opcion ( 4 ) Operacion logica OR                    \n");
    printf("opcion ( 5 ) Salir del programa                     \n");
    printf("****************************************************\n");
    printf("Escoja una de las opciones: ");
    scanf("%d",&opc);    

    while ( opc > 5 ){
        printf("Error al seleccionar una opcion \n"); 
        printf("Ingrese una opcion correcta: ");
        scanf("%d",&opc);
    }

    printf("Ingrese valor del primer operando: ");  //Se toma el valor de los operandos
    scanf("%d",&a);
    
    printf("Ingrese valor del segundo operando: ");
    scanf("%d",&b);

    switch (opc)    //Dependiendo de la opcion es la operacion escogida
    {
    case 1:
        printf("Opcion Suma\n");
        c = operacion(a,b,opc);       //r0,r1,r2
        printf("Resultado es: ( %d )\n", c);
        break;

    case 2:
        printf("Opcion resta\n");
        c = operacion(a,b,opc);               
        printf("Resultado es: ( %d )\n", c);        
        break;

    case 3:
        printf("Operacion logica AND\n");
        c = operacion(a,b,opc);
        printf("Resultado es: ( %d )\n", c);
        break;

    case 4:
        printf("Operacion logica AND OR\n");
        c = operacion(a,b,opc);
        printf("Resultado es: ( %d )\n", c);
        break;

    case 5:
        printf("Hasta luego.... :D\n");
        c = operacion(a,b,opc);
        printf("Resultado es: ( %d )\n", c);        
        return 0;
        break;
    }    

return 0;    
} //Fin de main