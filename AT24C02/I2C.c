#include <REGX52.H>

sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;

/**
*@brief 起始条件时序结构:SCL为高电平期间，SDA从高电平转换到低电平
*/
void I2C_Start()
{
		I2C_SDA=1;
		I2C_SCL=1;
		I2C_SDA=0;
		I2C_SCL=0;
}

/**
*@brief 终止条件时序结构:SCL为高电平期间，SDA从低电平转换到高电平
*/
void I2C_Stop()
{
		I2C_SDA=0;
		I2C_SCL=1;
		I2C_SDA=1;
		//I2C_SCL=0;
}

/**
*@brief I2C发送一个字节
*@param 发送的字节
*/
void I2C_SendByte(unsigned char Byte)
{
		unsigned char i=0;
		for(i=0;i<8;i++)
		{
				I2C_SDA=Byte&(0x80>>i);
				I2C_SCL=1;
				I2C_SCL=0;
		}
}
/**
*@brief I2C接受字节
*@retval 接受的字节
*/
unsigned char I2C_ReceiveByte()
{
		unsigned char i;
		unsigned char Byte=0x00;
		I2C_SDA=1;
		for(i=0;i<8;i++)
		{
				I2C_SCL=1;
				if(I2C_SDA)Byte|=(0x80>>i);
				I2C_SCL=0;
		}
		return Byte;
}
/**
*@brief I2C发送应答
*@param 应答位,0为收到
*/
void I2C_SendACK(unsigned char AckBit)
{		
		I2C_SDA=AckBit;
		I2C_SCL=1;
		I2C_SCL=0;
}

/**
*@brief I2C接受应答
*@retval 应答位 
*/
unsigned char I2C_ReceiveACK()
{
		unsigned char AckBit;
		I2C_SDA=1;
		I2C_SCL=1;
		AckBit=I2C_SDA;
		I2C_SCL=0;
		return AckBit;
}