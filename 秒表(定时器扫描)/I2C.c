#include <REGX52.H>

sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;

/**
*@brief ��ʼ����ʱ��ṹ:SCLΪ�ߵ�ƽ�ڼ䣬SDA�Ӹߵ�ƽת�����͵�ƽ
*/
void I2C_Start()
{
		I2C_SDA=1;
		I2C_SCL=1;
		I2C_SDA=0;
		I2C_SCL=0;
}

/**
*@brief ��ֹ����ʱ��ṹ:SCLΪ�ߵ�ƽ�ڼ䣬SDA�ӵ͵�ƽת�����ߵ�ƽ
*/
void I2C_Stop()
{
		I2C_SDA=0;
		I2C_SCL=1;
		I2C_SDA=1;
		//I2C_SCL=0;
}

/**
*@brief I2C����һ���ֽ�
*@param ���͵��ֽ�
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
*@brief I2C�����ֽ�
*@retval ���ܵ��ֽ�
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
*@brief I2C����Ӧ��
*@param Ӧ��λ,0Ϊ�յ�
*/
void I2C_SendACK(unsigned char AckBit)
{		
		I2C_SDA=AckBit;
		I2C_SCL=1;
		I2C_SCL=0;
}

/**
*@brief I2C����Ӧ��
*@retval Ӧ��λ 
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