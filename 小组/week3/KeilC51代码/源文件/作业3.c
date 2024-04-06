#include <reg52.h>
#include<intrins.h>

typedef unsigned int u16;			//u16指2个字节
typedef unsigned char u8;

#define SMG_A_DP_PORT	P0
u8 gsmg_code[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

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


void main()
{
	uart_init(0xFA);
	while(1)
	{
		
	}
}

void uart() interrupt 4
{
	if(RI==1){
		SMG_A_DP_PORT=gsmg_code[SBUF];//接受为hex数据，不是文本数据
		RI=0;//复位
	}
}


