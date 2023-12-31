#include <REGX52.H>
#include"Delay.h"
unsigned char table[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char Nixie_Buf[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
/**
* @brief 用数码管显示数字
* @param Location 要显示的位置 Number要显示的数字
*/
void Nixie(unsigned char Location,unsigned char Number)
{
	  P0=0x00;
    switch (Location)
    {
    case 1:
        P2_4=1;P2_3=1;P2_2=1;break;
    case 2:
        P2_4=1;P2_3=1;P2_2=0;break;    
    case 3:
        P2_4=1;P2_3=0;P2_2=1;break;
    case 4:
        P2_4=1;P2_3=0;P2_2=0;break;
    case 5:
        P2_4=0;P2_3=1;P2_2=1;break;
    case 6:
        P2_4=0;P2_3=1;P2_2=0;break;
    case 7:
        P2_4=0;P2_3=0;P2_2=1;break;
    case 8:
        P2_4=0;P2_3=0;P2_2=0;break;
    default:
        break;
    }
    P0=table[Number];
}


void NixieLoop()
{
		static unsigned char i;
		Nixie(i,Nixie_Buf[i]);
		i++;
		if(i>8)i=1;
}

void Nixie_Show(unsigned char Location,unsigned char Number)
{
		Nixie_Buf[Location]=Number;
}