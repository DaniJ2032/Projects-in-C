/*Ecabezado de biblioteca para calculo de Area de Figuras Geometricas*/

#ifndef AREASFG_H_INCLUDED //si noe srta definida el nombre de cabezera
#define AREASFG_H_INCLUDED //lo Defino

#include <math.h> //para compilar usar al final de la compilacion -lm para esta libreria
#define PI 3.141592654 //Defino Constante para el PI

/**********************PROTOTIPOS DE FUNCIONES************************/
float Rectangulo (float a, float b); //Area Rectangulo
float TrianguloBH (float a, float b); //Area Triangulo
float TrianguloABC (float a, float b, float c); //Area Triangulo
float Circulo (float a); //Area circulo
/********************************************************************/
#endif //Fin de AREASFG_H_INCLUDED  
