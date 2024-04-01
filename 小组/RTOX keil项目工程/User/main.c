/*******************************************************
	task1 : LED0每  1s改变一次状态
	task2 ：LED1每0.7s改变一次状态
	task3 ：LED2每0.4s改变一次状态
	task4 ：LED3每0.2s改变一次状态
*******************************************************/
#include <rtx51tny.h>
#include <reg52.h>
#include <Key.h>
#include <Seg.h>
 
#define LED_Port  P2

sbit BEEP = P2^5;
sbit KEY0 = P3^1;
sbit KEY1 = P3^0;
sbit KEY2 = P3^2;
sbit KEY3 = P3^3;

   
void job0(void) _task_ 0  
{
	
	os_create_task(4); 	//创建任务1
	os_create_task(1);	//创建任务2
 	os_delete_task(0);	//删除自己(task0),使task0退出任务链表
}  
      
void job1(void) _task_ 1  
{  
	
	unsigned char LED,i;
	LED_Port=~0x01;
	LED = 0x01;
	while(1){              
		for(i=0;i<8;i++)	 //将led左移一位
		{								  
			LED_Port = ~(LED<<i);
			os_wait(K_TMO, 20, 0); 	
		}
		  //等待100个时钟滴答(ticks),即1s
    }  
}  


void job2(void) _task_ 2 
{  
	BEEP = 1;
	
	while(1)
	{
			BEEP=!BEEP;//产生一定频率的脉冲信号
			os_wait(K_TMO,1, 0); 	
	}	

}  

void job3(void) _task_ 3  
{  
	u8 gsmg[8]={10,10,10,10,0,0,0,0};
	static i=0;
	static bit flag=1;
	while(1)
	{
			if(0==KEY3&&flag==1){
				delay_10us(1000);
				flag=0;
				if(0==KEY3){
					i++;
				}				
			}
			else if(1==KEY3) flag=1;
			
			gsmg[4]=i/1000;
			gsmg[5]=i%1000/100;
			gsmg[6]=i%100/10;
			gsmg[7]=i%10;
			smg_display(gsmg);
			os_wait(K_TMO,2, 0); 	
	}	

}  
    

 
void job4(void) _task_ 4
{
	bit flag=0;
	unsigned char Key_Val,Key_Down,Key_Old,Key_Up;
	while(1){
		if(0==KEY0)
		{
			os_delete_task(2);
			os_delete_task(3);
			os_create_task(1);
		}
		else if(0==KEY1)
		{
			P2 = 0xff;
			os_delete_task(1);
			os_delete_task(3);
			os_create_task(2);
		}
		else if(0==KEY2)
		{
			P2 = 0xff;
			os_delete_task(1);
			os_delete_task(2);
			os_create_task(3);
		}
		os_wait(K_TMO,20, 0); 	
	}
} 