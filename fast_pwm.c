#include <mega128.h>

void main()
{
 TCCR1A=0b00100011;
 TCCR1B=0b00001001;
 
 OCR1BH=0x0F;
 OCR1BL=0xCD;
 
 TCNT1H=0x00;
 TCNT1L=0x00;
         
 DDRA=0xFF;
 PORTA=0x00;    
 
 DDRB=0x40;
 PORTB=0x00;
 
 while(1)
 {
  if(PINB&0x40)
  {
  PORTA=0xFF;
  }          
  else
  {
   PORTA=0x00;
  }
 }

}