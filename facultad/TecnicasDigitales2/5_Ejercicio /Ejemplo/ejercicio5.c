#include "EasyPIO.h"
#include <stdio.h>

void main (void){
    int vect[8] = {23,24,25,12,16,20,21,26};

    pioInit();
    pinMode(23, OUTPUT);
    pinMode(24, OUTPUT);
    pinMode(25, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(16, OUTPUT);
    pinMode(20, OUTPUT);
    pinMode(21, OUTPUT);
    pinMode(26, OUTPUT);
    
    //printf("Ahora vuelve");
   
    while(1){
        
        
        for (int j = 0; j < 8; j++){
            digitalWrite(vect[j],1);
            sleep(1);
            digitalWrite(vect[j],0);
            printf("%d \n",j);
        }
        printf("LLego a la derecha \n");
        
        for (int k = 6; k > 0; k--){
            digitalWrite(vect[k],1);
            sleep(1);
            digitalWrite(vect[k],0);
            printf("%d \n",k);
        }
        
        printf("LLego a la izquierda \n");
        
    }

    
}
