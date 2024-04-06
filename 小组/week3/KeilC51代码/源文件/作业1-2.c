#include <reg52.h>
#include<intrins.h>

typedef unsigned int u16;			//u16ָ2���ֽ�
typedef unsigned char u8;


#define LED_Port P2
u16 cnt,timeset;
void UART_SendByte(u8 Data){
	SBUF=Data;
	while(TI==0);
	TI=0;//TI��λ
}

void uart_init(u8 baud)
{
	TMOD|=0x20;
	SCON=0x50;
	PCON=0x80;
	TH1=baud;
	TL1=baud;
	ES=1;
	EA=1;
	TR1=1;		
}

void time0_init()
{
 	TMOD|=0x01; //���ö�ʱ��0�Ĺ�����ʽ���û����㲻���Ŷ�ʱ��1�Ĺ�����ʽ
	TH0=0xFC;  //1ms
	TL0=0x18;
	ET0=1;	 //��ʱ���ж�����
	EA=1;	 //���ж�
	TR0=1;	//�򿪶�ʱ��
}

void main()
{
	uart_init(0xFA);
	time0_init();
	timeset=1000;
	while(1)
	{
		
	}
}

void uart() interrupt 4
{

}

void timer0() interrupt 1
{
	static u8 i=0;
	static cnt=0;
	cnt++;
	TH0=0xFC;  
	TL0=0x18;
	if(cnt>=timeset)
	{
		UART_SendByte('H');
		UART_SendByte('e');
		UART_SendByte('l');
		UART_SendByte('l');
		UART_SendByte('o');
		UART_SendByte(' ');
		UART_SendByte('W');
		UART_SendByte('o');
		UART_SendByte('r');
		UART_SendByte('l');
		UART_SendByte('d');
		cnt=0; 
		if(++i==8) i=0;
		LED_Port=~(0x01<<i);
	}
}
