/*Cuerpo de las Funciones de las Librerias*/
#include "AreasFG.h" //Incluyo el encabezado creado

/*Area 	Rectangulo*/
float Rectangulo(float a, float b){

return a * b;
}//Fin de la Funcion Rectangulo();

/*Area de un Triangulo con B y H*/
float TrianguloBH(float a, float b){

return (a*b)/2.0;
}//Fin de la Funcion TrianguloBH();

/*Area para un Triangulo con sus 3 Lados*/
float TrianguloABC(float a, float b, float c){

float s = ((a + b + c) / 2.0);

return sqrt (s*(s-a) * (s-b) * (s-b)); //Formula de Eron 
}//Fin de la Funcion TrianguloABC();

/*Area para un Circulo*/
float Circulo(float a){

return PI * (a * a);
}//Fin de la Funcion Circulo();


