#include <mega128.h>


char flag=0;

interrupt [TIM1_COMPA] void timer1_compa_isr(void)
{

   flag=PINB&0x20;
   
   if(!flag)
   {
  OCR1AH=0;
  OCR1AL=10;  
  PORTA=0xFF;
   
   } 
   else
   {
  OCR1AH=0;
  OCR1AL=20;   
  PORTA=0x00;
   }


}


void main()
{
  TCCR1A=0b01000000; //OCA
  TCCR1B=0b00001001;   //CTC,Prescaler1024
  
  OCR1AH=0;
  OCR1AL=20;
  
  DDRA=0xFF; //LED
  PORTA=0x00;

  DDRB=0x20; //OC1A
  PORTB=0x00;  
  
  TCNT1H=0x00;
  TCNT1L=0x00;  
        
  
  TIMSK=0x10;
  SREG.7=1;
  
  while(1)
  {
  
  } 


}