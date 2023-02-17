/*Juarez Daniel Alejandro 
Leg: 79111 
Curso: 1R5 
Año: 2019 
Materia: Informatica_1*/

#include <stdio.h>
#include <wiringPi.h>


int main (){
int valor,j;
valor=wiringPiSetup();
if (valor==-1){
printf("No se puede inicializar el puerto");
}

for(j=0;j=100;j++){

pinMode(4,OUTPUT);

pinMode(5,OUTPUT);

pinMode(6,OUTPUT);


pinMode(27,OUTPUT);

pinMode(28,OUTPUT);

pinMode(29,OUTPUT);

pinMode(25,OUTPUT);

pinMode(21,INPUT);   

int v;

v=digitalRead(21);

if(v==1){

digitalWrite(4,1);
delay(1000);

digitalWrite(4,0);
delay(1000);

digitalWrite(5,1);
delay(1000);

digitalWrite(5,0);
delay(1000);

digitalWrite(6,1);
delay(1000);

digitalWrite(6,0);
delay(1000);

digitalWrite(26,1);
delay(1000);

digitalWrite(26,0);
delay(1000);

digitalWrite(27,1);
delay(1000);

digitalWrite(27,0);
delay(1000);

digitalWrite(28,1);
delay(1000);

digitalWrite(28,0);
delay(1000);

digitalWrite(29,1);
delay(1000);

digitalWrite(29,0);
delay(1000);

digitalWrite(25,1);
delay(1000);

digitalWrite(25,0);
delay(1000);

}

}


return 0;
}

