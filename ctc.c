#include <mega128.h>


/*interrupt [TIM1_COMPA] void timer1_compa_isr(void)
{

   flag=PINB&0x20;
   if(!flag)
   {
  OCR1AH=0xFF;
  OCR1AL=0xCC;  
  PORTA=0xFF;
   
   } 
   else
   {
  OCR1AH=0x00;
  OCR1AL=0xCC;   
  PORTA=0x00;
   }


}
    */

void main()
{
  TCCR1A=0b01000000; //OCA
  TCCR1B=0b00001101;   //CTC,Prescaler1024
  
  OCR1AH=0x00;
  OCR1AL=0xFF;
  
  DDRA=0xFF; //LED
  PORTA=0x00;

  DDRB=0x20; //OC1A
  PORTB=0x00;  
  
  TCNT1H=0x00;
  TCNT1L=0x00;  
      
  while(1)
  {
   if(PINB&0x20)
   {
   PORTA=0xFF;
   }          
   else
   {
   PORTA=0x00;
   }
  
  } 


}