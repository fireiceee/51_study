#include <REGX52.H>
#include"Delay.h"
#include"MatrixLed.h"
unsigned char Data[24]={0xF2,0x92,0x92,0x9E,0x00,0x80,0x40,0x3E,0x40,0x80,0x00,0xF2,0x92,0x92,0x9E,0x00,
0xF2,0x92,0x92,0x9E,0x00,0x00,0x00,0x00};
void main()
{
	unsigned char i,Offset=0,Num=0;
	MatrixLed_Init();
	while(1)
	{
		for(i=0;i<8;i++)
		{
				MatrixLed_Column(i,Data[i+Offset]);
		}
		Num++;
		if(Num>=10)
		{
				Num=0;
				Offset++;
			if(Offset>16)
			{
				Offset=0;
			}
		}
	}
}