#include <reg52.h>
#include<intrins.h>

typedef unsigned int u16;			//u16指2个字节
typedef unsigned char u8;


#define LED_Port P2
u16 cnt,timeset;
void UART_SendByte(u8 Data){
	SBUF=Data;
	while(TI==0);
	TI=0;//TI复位
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
 	TMOD|=0x01; //设置定时器0的工作方式，用或运算不干扰定时器1的工作方式
	TH0=0xFC;  //1ms
	TL0=0x18;
	ET0=1;	 //定时器中断允许
	EA=1;	 //总中断
	TR0=1;	//打开定时器
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
