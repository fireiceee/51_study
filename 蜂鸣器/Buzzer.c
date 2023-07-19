#include <REGX52.H>
#include<INTRINS.H>

sbit Buzzer_IO=P2^5;
void Delay500us()		
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}

void Buzzer_Time(unsigned char Ms)
{
		unsigned int i;
		for(i=0;i<Ms*2;i++)
		{
				Buzzer_IO=!Buzzer_IO;
				Delay500us();
		}
}