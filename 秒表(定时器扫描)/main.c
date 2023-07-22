#include <REGX52.H>
#include"Key.h"
#include"Timer0_Init.h"
#include"Nixie.h"
#include"Delay.h"
#include"AT24C02.h"
unsigned char KeyNumber;
unsigned char Temp;
unsigned char MiniSec,Sec,Min;
unsigned char ClockFlag;
void main()
{
	Timer0_Init();
	while(1)
	{
			KeyNumber=Key();
			if(KeyNumber)
			{	
					if(KeyNumber==1)
					{
							Sec=0;
							Min=0;
							MiniSec=0;
					}
					if(KeyNumber==2)
					{	
							ClockFlag=!ClockFlag;
					}
					if(KeyNumber==3)
					{
							AT24C02_WriteByte(0,Min);
							Delay(5);
							AT24C02_WriteByte(1,Sec);
							Delay(5);
							AT24C02_WriteByte(2,MiniSec);
							Delay(5);
					}
					if(KeyNumber==4)
					{
							Min=AT24C02_ReceiveByte(0);
							Sec=AT24C02_ReceiveByte(1);
							MiniSec=AT24C02_ReceiveByte(2);
					}
			}
			Nixie_Show(1,Min/10);
			Nixie_Show(2,Min%10);
			Nixie_Show(3,Sec/10);
			Nixie_Show(4,Sec%10);
			Nixie_Show(5,MiniSec/10);
			Nixie_Show(6,MiniSec%10);
	}
}

void Sec_Loop()
{
		MiniSec++;
		if(MiniSec>=100)
		{
				MiniSec=0;
				Sec++;
				if(Sec>=60)
				{
						Sec=0;
						Min++;
						if(Min>=60)
							Min=0;
				}
		}
}
void Timer0_Routine() interrupt 1
{
		static unsigned int count,count2,count3;
		TH0=64535/256;
		TL0=64535%256;
		count++;
		count2++;
		count3++;
		if(count>=20)
		{
				count=0;
				KeyLoop();
		}
		if(count2>=2)
		{	
				count2=0;
				NixieLoop();
		}
		if(count3>=10)
		{
				count3=0;
				if(ClockFlag==1)
				Sec_Loop();
		}
}