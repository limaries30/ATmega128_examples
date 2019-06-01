#include <mega128.h>
#include <delay.h>

int count=0;
char num[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F};

interrupt [TIM1_COMPC] void timer1_compa_isr(void)
{
   count++;
   if(count==100)
   {
    count=0;
   }

}


void main()
{
 DDRG=0x03;  
 
 DDRC=0xFF;
 PORTC=0x00; 
 
 DDRB=0x80;
 
 TCCR1A=0b00000100;    //OCC,Prescalerm,Normal
 TCCR1B=0b00000101; 
 
 TCNT1H=0x00;
 TCNT1L=0x00;
 
 OCR1CH=0x7A;
 OCR1CL=0x12; 
 
 ETIMSK=0x01;
 SREG.7=1; 
 
 while(1)
 {
   PORTG=0x02;
   PORTC=num[count/10];
   delay_ms(1);
   PORTG=0x01;
   PORTC=num[count%10];
   delay_ms(1);
 
 }
 


}