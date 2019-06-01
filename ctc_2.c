#include <mega128.h>

int j=0;

interrupt [TIM1_COMPA] void timer1_compa_isr(void)
{

   PORTA^=0xFF;
   
   if(!j)
   {
   OCR1AH=0x99;
   OCR1AL=0x99; 
   j=1;
   }
   else
   { 
   OCR1AH=0x11;
   OCR1AL=0x11;
   j=0;
   }
}


void main()
{

   DDRA=0xFF;
   PORTA=0x00;
    
   TCCR1A=0x00;
   TCCR1B=0b00001101;
   
   TCNT1H=0x00;
   TCNT1L=0x00;
   
   OCR1AH=0x11;
   OCR1AL=0x11;
   
   TIMSK=0x10;
   SREG.7=1;
   
   while(1)
   {
   
   
   }


}