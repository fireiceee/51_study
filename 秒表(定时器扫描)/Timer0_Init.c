#include <REGX52.H>
void Timer0_Init()
{
		//TMOD=0x1;//0000 0001
		TMOD=TMOD&0xF0;//把TMOD的低4位清0，高四位不变
		TMOD=TMOD|0x01;//把TMOD的最低位置1，高四位不变
		TF0=0;//定时器溢出标志
		TR0=1;//允许定时器开始计数
		//将定时器初值赋为64535(65535-1000)这样在1000us后会触发第一次中断
		TH0=64535/256;
		TL0=64535%256+1;
	
		ET0=1;
		EA=1;
		PT0=0;
}

//定时器中断函数模板
/*void Timer0_Routine() interrupt 1
{
		static unsigned int count;
		TH0=64535/256;
		TL0=64535%256;
		count++;
		if(count>=1000)
		{
				count=0;
		}
}
*/