#include <REGX52.H>
#include"Delay.h"
sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;

/**
* @brief 用74HC595来控制一个字节
*	@para Byte为要控制的一个字节
*/
void _74HC595_WriteByte(unsigned char Byte)
{
		unsigned char i;
		for(i=0;i<8;i++)
		{
			SER=Byte&(0x80>>i);
			SCK=1;
			SCK=0;
		}
		RCK=1;
		RCK=0;
}

/**
* @brief 初始化
*	@para 
*/
void MatrixLed_Init()
{
	SCK=0;
	RCK=0;
}
/**
* @brief 实现一列点阵的控制
*	@para Column为选中的列数，范围0~7
*	@para Data为该行的数据，用来表示亮灭情况,0xFF为全灭，0x00为全亮
*/
void MatrixLed_Column(unsigned char Column,unsigned char Data)
{
    _74HC595_WriteByte(Data);
		P0=~(0x80>>Column);
		Delay(1);
		P0=0xFF;
}