#include <mega128.h>
#include <delay.h>

int count=0;
char num[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F};

interrupt [TIM1_COMPA] void timer1_compa_isr(void)
{

    TCNT1H=0x11;
    TCNT1L=0x11;
    count++;
    if(count==100)
    {
    count=0;
    }
}

void main()
{
  SREG.7=1;

  TCNT1H=0x11;
  TCNT1L=0x11;
  
  OCR1AH=0x8A;
  OCR1AL=0x12;
  
  TCCR1A=0x00;     
  TCCR1B=0x0D;
  
  TIMSK=0x10;
  
  DDRG=0x03;
  PORTG=0x00;
             
  DDRC=0xFF;        
  PORTC=0x00;      
  
  while(1)
  {
  PORTG=0x01;
  PORTC=num[count%10];
  delay_ms(10); 
  
  PORTG=0x02;
  PORTC=num[count/10];
  delay_ms(10);
  
  }
  
  

}