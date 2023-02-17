    #include <stdio.h>
    #include "EasyPIO.h"
  
    #define GPIOI 17 // INPUT 
    #define GPIOO 23 // OUTPUT

int main(void) {
       
       
       int state;
       
        pioInit();
        

        pinMode(GPIOO, OUTPUT);
        pinMode(GPIOI, INPUT);
        
        //printf("Presione la tecla ENTER para salir");
        
        
        while(1) {
			
			      state=digitalRead(GPIOI);
			
            digitalWrite(GPIOO,state);  
             
           
           
           
        }
        return 0;
}
