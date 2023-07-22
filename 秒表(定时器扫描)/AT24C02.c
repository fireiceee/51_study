#include <REGX52.H>
#include"I2C.h"

#define AT24C02_ADDRESS 0xA0

/**
*@breif AT24C02写入一个字节
*@param WordAddress:要写入的地址 Data:要写入的字节
*/
void AT24C02_WriteByte(unsigned char WordAddress,unsigned char Data)
{
			I2C_Start();
			I2C_SendByte(AT24C02_ADDRESS);
			I2C_ReceiveACK();
			I2C_SendByte(WordAddress);
			I2C_ReceiveACK();
			I2C_SendByte(Data);
			I2C_ReceiveACK();
			I2C_Stop();
}

/**
*@breif AT24C02读取一个字节
*@param 要写入的地址
*@revtal  读取的字节
*/
unsigned char AT24C02_ReceiveByte(unsigned char WordAddress)
{
			unsigned char Data;
			I2C_Start();
			I2C_SendByte(AT24C02_ADDRESS);
			I2C_ReceiveACK();
			I2C_SendByte(WordAddress);
			I2C_ReceiveACK();
			I2C_Start();
			I2C_SendByte(AT24C02_ADDRESS|0x01);
			I2C_ReceiveACK();
			Data=I2C_ReceiveByte();
			I2C_SendACK(1);
			I2C_Stop();
			return Data;
}