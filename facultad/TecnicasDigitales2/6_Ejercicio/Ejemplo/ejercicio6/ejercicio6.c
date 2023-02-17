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
    
    int matrix [18][8] = 	
			    {{1, 0, 0, 0, 0, 0, 0, 0},
				 {1, 0, 0, 0, 0, 0, 0, 0},
				 {0, 1, 0, 0, 0, 0, 0, 0},
				 {0, 1, 0, 0, 0, 0, 0, 0},
				 {0, 0, 1, 0, 0, 0, 0, 0},
				 {0, 0, 1, 0, 0, 0, 0, 0},
				 {0, 0, 0, 1, 0, 0, 0, 0},
				 {0, 0, 0, 1, 0, 0, 0, 0},
				 {1, 0, 0, 0, 1, 0, 0, 0},
				 {0, 1, 0, 0, 1, 0, 0, 0},
				 {0, 0, 1, 0, 0, 1, 0, 0},
				 {0, 0, 0, 1, 0, 1, 0, 0},
				 {0, 0, 0, 0, 1, 0, 1, 0},
				 {0, 0, 0, 0, 0, 1, 1, 0},
				 {0, 0, 0, 0, 0, 0, 1, 1},
				 {0, 0, 0, 0, 0, 0, 0, 1},
				};
   
    while(1){
        
        sleep(2);
        for (int k = 0; k < 18; k++){
			sleep(1);
			for (int j = 0; j < 8; j++){
				digitalWrite(vect[j],matrix [k][j] );
				
			}
            
            
            
        }
        
        
        
        
        
        
    }

    
}

