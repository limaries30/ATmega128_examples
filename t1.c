#include <mega128.h>
#include <delay.h>

void main()
{
	TCNT0 = 0x63;
	TCCR0 = 0x07;

	DDRA = 0xFF;
	PORTA = 0x00;

	int flag= TIFR & 0x01;
	int count = 0;
	int itr = 0;

	while (1)
	{
		if (flag == 1)
		{
			count++;
			TCNT0 = 0x63;
			TIFR = 0x01;

		}
		if (count == 200)
		{
			count == 0;
			PORTA <<= itr;
			itr++;
		}
		if (itr == 8)
			itr = 0;
	}


}