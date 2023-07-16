#include <REGX52.H>
#include"Timer0_Init.h"
#include"MatrinKey.h"
#include"Delay.h"	
#include<INTRINS.H>
int LedMode;
void Timer0_Routine() interrupt 1
{
		static unsigned int count;
		TH0=64535/256;
		TL0=64535%256;
		count++;
		if(count>=500)
		{
				count=0;
				if(LedMode==0)
				{
						P2=_crol_(P2,1);
				}
				else
				{
						P2=_cror_(P2,1);
				}
		}
}

unsigned char KeyNum;
void main()
{
		Timer0_Init();
	  P2=0xFE;
		while(1)
		{
				KeyNum=MatrinKey();
				if(KeyNum)
				{
						if(KeyNum==1)
						{
								LedMode=!LedMode;
						}
				}
		}
}