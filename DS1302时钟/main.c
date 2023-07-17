#include <REGX52.H>
#include"LCD1602.h"
#include"DS1302.h"
#include"MatrinKey.h"
#include"Timer0_Init"
unsigned char KeyNum,MODE,TimeSelect,TimeFlag;
void Timer0_Routine() interrupt 1
{
		static unsigned int count;
		TH0=64535/256;
		TL0=64535%256+1;
		count++;
		if(count>=500)
		{
				count=0;
				TimeFlag=!TimeFlag;
		}
}
void TimeShow()
{
		DS1302_ReadTime();
		LCD_ShowNum(1,1,DS1302_Time[0],2);
		LCD_ShowNum(1,4,DS1302_Time[1],2);
		LCD_ShowNum(1,7,DS1302_Time[2],2);
		LCD_ShowNum(2,1,DS1302_Time[3],2);
		LCD_ShowNum(2,4,DS1302_Time[4],2);
		LCD_ShowNum(2,7,DS1302_Time[5],2);
}

void TimeSet()
{
		if(KeyNum==2)
		{
				TimeSelect++;
				TimeSelect%=6;
		}
		if(KeyNum==3)
		{
				DS1302_Time[TimeSelect]++;
				if(DS1302_Time[0]>99)DS1302_Time[0]=0;
				if(DS1302_Time[1]>12)DS1302_Time[1]=1;
				if(DS1302_Time[2]>31)DS1302_Time[2]=1;
				if(DS1302_Time[3]>=24)DS1302_Time[3]=0;
				if(DS1302_Time[4]>=60)DS1302_Time[4]=0;
				if(DS1302_Time[5]>=60)DS1302_Time[5]=0;
		}
		if(KeyNum==4)
		{
				DS1302_Time[TimeSelect]--;
				if(DS1302_Time[0]<0)DS1302_Time[0]=99;
				if(DS1302_Time[1]<=0)DS1302_Time[1]=12;
				if(DS1302_Time[2]<=0)DS1302_Time[2]=31;
				if(DS1302_Time[3]<0)DS1302_Time[3]=23;
				if(DS1302_Time[4]<0)DS1302_Time[4]=59;
				if(DS1302_Time[5]<0)DS1302_Time[5]=59;
		}
		if(TimeSelect==0&&TimeFlag==1)LCD_ShowString(1,1,"  ");
		else LCD_ShowNum(1,1,DS1302_Time[0],2);
		if(TimeSelect==1&&TimeFlag==1)LCD_ShowString(1,4,"  ");
		else LCD_ShowNum(1,4,DS1302_Time[1],2);
		if(TimeSelect==2&&TimeFlag==1)LCD_ShowString(1,7,"  ");
		else LCD_ShowNum(1,7,DS1302_Time[2],2);
		if(TimeSelect==3&&TimeFlag==1)LCD_ShowString(2,1,"  ");
		else LCD_ShowNum(2,1,DS1302_Time[3],2);
		if(TimeSelect==4&&TimeFlag==1)LCD_ShowString(2,4,"  ");
		else LCD_ShowNum(2,4,DS1302_Time[4],2);
		if(TimeSelect==5&&TimeFlag==1)LCD_ShowString(2,7,"  ");
		else LCD_ShowNum(2,7,DS1302_Time[5],2);
}

void main()
{
		LCD_Init();
		Timer0_Init();
		DS1302_Init();	
		while(1)
		{
			
				KeyNum=MatrinKey();
				if(KeyNum==1)
				{
						if(MODE==0)
							MODE=1;
						else if(MODE==1)
						{
								DS1302_SetTime();
								MODE=0;
						}
				}
				if(MODE==0)
					TimeShow();
				else
					TimeSet();
		}
}