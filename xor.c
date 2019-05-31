#include <mega128.h>
#include <delay.h>

void main()
{
 DDRA=0xFF;
 PORTA=0b11000011;
 
 while(1)
 {
  PORTA^=0xFF;
  delay_ms(100);
 
 }

}