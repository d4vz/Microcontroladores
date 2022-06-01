#include "LCD.h"
#include "def_principais.h"
#include <avr/pgmspace.h> // biblioteca para poder gravar dados na memória flash
#define DISPLAY PORTB // define um nome auxiliar para o display
#define BOTAO PC0 // define PB0 com o nome de BOTAO


// variável gravada na memória flash
const unsigned char Tabela[] PROGMEM = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02,
0x78, 0x00, 0x18, 0x08, 0x03, 0x46, 0x21, 0x06, 0x0E};
int main()
{
unsigned char valor = 0; // declara variável local

DDRC = 0b11111110; // PB0 como input, os demais pinos como output
PORTC= 0x01; // habilita o pull-up do PB0

DDRB = 0xFF; // PORTD como saída (display)
PORTB= 0xFF; // desliga o display

DDRD = 0xFF;
PORTD = 0x00;

while(1)
{
if(!tst_bit(PINC,BOTAO)) // se o botão for pressionado executa
{
if(valor==0x0F) // se o valor for igual a 0xF, zera o valor
valor=0;
else // se não o incrementa
valor++;
// decodifica o valor e mostra no display, busca o valor na Tabela.
DISPLAY = pgm_read_byte(&Tabela[valor]);
_delay_ms(200); // atraso para incremento automático do nr.
}
}
}
