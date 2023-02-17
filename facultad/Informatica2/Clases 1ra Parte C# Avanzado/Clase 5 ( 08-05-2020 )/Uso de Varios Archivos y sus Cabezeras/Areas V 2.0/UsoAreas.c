/*Programa para calcular las Areas de Figuras Geometricas*/

#include <stdio.h>
#include "AreasFG.h" //Agrego la Libreria que cree, debe estar en la misma carpeta que el el main.c

/*******PROTOTIPOS DE FUNCIONES********/
int Menu( int );
void Operaciones(int, float, float, float);

int main(int argc, char *argv[]){
	
float a = 0, b = 0, c = 0;
int opc;

	Menu ( opc );
	Operaciones (opc, a, b, c );    


	/*areaRectangulo = Rectangulo(b, c);
	areaTriangulo = TrianguloABC(a, b, c);
	areaCirculo = Circulo(c);*/

return 0;
}//FIn de la Funcion main();

int Menu( int opc ){


	//do{
		printf("****MENU PRINCIPAL****\n");
		printf("( 1 ) Area de un Rectangulo \n");
    	printf("( 2 ) Area de un Triangulo con Base y Altura \n");
		printf("( 3 ) Area de un Rectangulo con sus 3 Lados \n");
		printf("( 4 ) Area de un Circulo \n");
		printf("( 5 ) Salir del Programa \n");
		printf("\nIngrese una Opcion: ");
		scanf("%d",&opc);
		
	//}while (opc !=5);

return opc;
} //Fin de la Funsion Menu

void Operaciones(int opc, float a, float b, float c){


		switch ( opc ){

		case 1: 
			printf("\nIngrese el Primer lado del Rectangulo: ");
			scanf("%f",&a);
			printf("\nIngrese el Segundo lado del Rectangulo: ");
			scanf("%f",&b);	
			printf ("\n\nArea del Rectangulo Ingresado es: ( %.2f )\n\n", Rectangulo(a, b));
			a = 0; b = 0;
				
		break;			
		
		case 2: 

			printf("\nIngrese La Base del Trinagulo: ");
			scanf("%f",&a);
			printf("\nIngrese la Altura del Triangulo: ");
			scanf("%f",&b);	
			printf ("\n\nArea del Triangulo Ingresado es: ( %.2f )\n\n", TrianguloBH(a, b));
			a = 0; b = 0;

		break;
	
		/*case 3: 

		break;

		case 4: 

		break;*/

	}//Fin del shitch(); 

}//FIn de la Funsion Operaciones();
