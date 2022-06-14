#include "LCD.h"
#include "def_principais.h"
#include "LCD.c"


int main(){

  int x = 0; // 0  até 255
  
  DDRB = 0xFF;
  DDRD = 0x00;
  PORTD = 0xFF;
   
  TCCR1A = (1<<WGM11)|(1<<COM1A1);
  TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS12);
  ICR1 = 1249;
  OCR1A = 63;

 
  
  while(1){
    
     for(x=31;x<=125;x++){
       OCR1A = x;
       _delay_ms(100);
       if(x==125){x=31;}     
       }  
      
    }
  }
