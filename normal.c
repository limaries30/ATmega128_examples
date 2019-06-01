#include <mega128.h>

int i=0;
int count=0;

void main()
{
 TCNT0=0x63;
 TCCR0=0x07;    
 DDRA=0xFF;
 PORTA=0x00;
 
 while(1)
 {
   if(TIFR==0x01)
   {
    TIFR=TIFR&0x01;
    TCNT0=0x63;
    count++;
   } 
    
   if(count==200)
   {
    PORTA=1<<i;
    i++;  
    count=0;
   }
   
   if(i==8)
   {
    i=0;
   }
 }



}