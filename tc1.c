//Use Timer/Counter to move turned on LED by left direction 1 secs not using Overflow
//Use Timer0
//Clock Cycle 1ms and use Prescaler 64
//16MHz->0.0625 us
//Prescaler 64 -> 4us
//To make 1ms needs 250 ticks
//255 -250+1=6
//1000*1ms=1s


#include <mega128.h>
#include <delay.h>void main(){
	DDRA = 0xFF;	PORTA = 0x00;		TCNT0 = 0x06;	TCCR0 = 0x04; //Normal Mode & Prescaler 64	TIFR = 0x00;	int count;	int loc=1;	int flag = TIFR & 0x01;	while (1)	{		PORTA =1<< loc;		if (flag == 1)		{			count++;			TIFR = 0x00;			TCNT0 = 0x06;		}		if (count == 1000)		{			loc++;		}		if (loc == 7)		{			loc = 0;		}	}	}