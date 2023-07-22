#include <REGX52.H>
#include"LCD1602.h"
#include"MatrinKey.h"
#include"Delay.h"
#include"AT24C02.h"
unsigned char Data;
void main()
{
		LCD_Init();
		LCD_ShowString(1,1,"hello");
		AT24C02_WriteByte(1,66);
		Delay(5);
		Data=AT24C02_ReceiveByte(1);
		LCD_ShowNum(2,1,Data,4);
		while(1)
		{
				
		}
}