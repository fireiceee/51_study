#include <REGX52.H>
#include"Timer0_Init.h"
#include"Delay.h"
sbit Buzzer_IO=P2^5;
unsigned int FreqTable[]={63625,63732,63833,63929,64019,64104,64185,64260,64332,64400
,64463,64524,64580,64634,64685,64732,64778,64820,64860,64898,64934,64968,65000,65030,
	65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283};
unsigned int FreNum;
unsigned int MusicSelect;
unsigned int stable[]={23,3,23,3,21,2,23,3,23,3,21,2,
23,3,23,3,21,2,23,4,23,4
};
void Timer0_Routine() interrupt 1
{
		TH0=FreqTable[FreNum]/256;
		TL0=FreqTable[FreNum]%256;
		Buzzer_IO=!Buzzer_IO;
}

void main()
{
		Timer0_Init();
		while(1)
		{
				FreNum=stable[MusicSelect];
				MusicSelect++;
				Delay(150*stable[MusicSelect]);
				MusicSelect++;
				TR0=0;
				Delay(5);
				TR0=1;
		}
}
