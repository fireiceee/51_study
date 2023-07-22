#include <REGX52.H>
void Timer0_Init()
{
		//TMOD=0x1;//0000 0001
		TMOD=TMOD&0xF0;//��TMOD�ĵ�4λ��0������λ����
		TMOD=TMOD|0x01;//��TMOD�����λ��1������λ����
		TF0=0;//��ʱ�������־
		TR0=1;//����ʱ����ʼ����
		//����ʱ����ֵ��Ϊ64535(65535-1000)������1000us��ᴥ����һ���ж�
		TH0=64535/256;
		TL0=64535%256+1;
	
		ET0=1;
		EA=1;
		PT0=0;
}

//��ʱ���жϺ���ģ��
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