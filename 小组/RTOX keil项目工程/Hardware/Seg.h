#ifndef  Seg_H
#define  Seg_H

#include "reg52.h"
#include "intrins.h"

typedef unsigned int u16;			//u16Ö¸2¸ö×Ö½Ú
typedef unsigned char u8;

#define SMG_A_DP_PORT	P0
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
void delay_10us(u16 ten_us);
void smg_display(u8 gsmg[8]);
#endif





