#ifndef __AT24C02_H__
#define __AT24C02_H__
void AT24C02_WriteByte(unsigned char WordAddress,unsigned char Data);
unsigned char AT24C02_ReceiveByte(unsigned char WordAddress);
#endif