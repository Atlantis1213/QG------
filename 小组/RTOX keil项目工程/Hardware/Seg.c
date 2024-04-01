#include <Seg.h>

u8 gsmg_code[11]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00};
u8 i=0;
void delay_10us(u16 ten_us)//当传入1时，大约延时10us
{
 	while(ten_us--);
}
void smg_display(u8 gsmg[8]){
	 for (i=0;i<8;i++){
	 switch (i)
	 {
	 case 0 : LSA=1;LSB=1;LSC=1;break;
	 case 1 : LSA=0;LSB=1;LSC=1;break;
	 case 2 : LSA=1;LSB=0;LSC=1;break;
	 case 3 : LSA=0;LSB=0;LSC=1;break;
	 case 4 : LSA=1;LSB=1;LSC=0;break;
	 case 5 : LSA=0;LSB=1;LSC=0;break;
	 case 6 : LSA=1;LSB=0;LSC=0;break;
	 case 7 : LSA=0;LSB=0;LSC=0;break;
	 }
	 SMG_A_DP_PORT=gsmg_code[gsmg[i]];
	 delay_10us(100);
	 SMG_A_DP_PORT=0x00;
	 }



}
