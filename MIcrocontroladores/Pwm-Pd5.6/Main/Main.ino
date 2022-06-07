#include "LCD.h"
#include "def_principais.h"
#include "LCD.c"


int main(){

  int x;
  DDRD = 0xFF;
  TCCR0A = 0b10100011;
  TCCR0B = 0b00000011;
  
  OCR0A = x;
  OCR0B = x;
  
 } 
