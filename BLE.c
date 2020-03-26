
#include <string.h>
#include "BLE.h"
#include "usart.h"
#include "Protocol.h"
#include "aes.h"
#include "user.h"
#include "led.h"

void BleInit(void)
{
	Uart6_init(84,115200);
}


void Reply_Send(u16 bodylen)
{

	Reply.Body[bodylen]=0x0d;
	Reply.Body[bodylen+1]=0x0a;
	Uart6_Tx(Reply.Media,72+bodylen);   
	
}

//À¶ÑÀÖ´ÐÐÐ­Òé
void BlePacket(void)
{
	u8 CMD_Err=0;

	if(memcmp(USART6_RX_BUF,Reply.Media,4)!=0)CMD_Err++;
	if(memcmp(USART6_RX_BUF+4,Reply.DTUID,8)!=0)CMD_Err++;
	
	if(CMD_Err==0)
	{
		memcpy(Reply.UUID,USART6_RX_BUF+12,32);
		u16 cmd=(USART6_RX_BUF[53]-48)*1000+(USART6_RX_BUF[54]-48)*100+\
			(USART6_RX_BUF[55]-48)*10+(USART6_RX_BUF[56]-48);
		switch(USART6_RX_BUF[52])
		{
			case 'S':{
				switch(cmd)
				{
					case 1:{
						Reply_Send(S0001());
					}break;
					case 2:{
						Reply_Send(S0002());
					}break;
					case 3:{
						Reply_Send(S0003());
					}break;
					case 4:{
						Reply_Send(S0004());
					}break;
					case 5:{
						Reply_Send(S0005());
					}break;
					case 6:{
						Reply_Send(S0006());
					}break;
					case 7:{
						Reply_Send(S0007());
					}break;
					case 8:{
						Reply_Send(S0008());
					}break;
					case 9:{
						Reply_Send(S0009());
					}break;
					case 10:{
						Reply_Send(S0010());
					}break;
					case 11:{
						Reply_Send(S0011());
					}break;
					case 12:{
						Reply_Send(S0012());
					}break;
					case 13:{
						Reply_Send(S0013());
					}break;
					case 14:{
						Reply_Send(S0014());
					}break;
					case 15:{
						Reply_Send(S0015());
					}break;
					case 16:{
						Reply_Send(S0016());
					}break;
					case 17:{
						Reply_Send(S0017());
					}break;
					case 18:{
						Reply_Send(S0018());
					}break;
					case 19:{
						Reply_Send(S0019());
					}break;
                                        case 20:{
						Reply_Send(S0020());
					}break;
                                        case 21:{
						Reply_Send(S0021());
					}break;
                                        case 22:{
						Reply_Send(S0022());
					}break;
					case 23:{
						Reply_Send(S0023());
					}break;
					default :{
					}break;
				}
			}break;
			case 'L':{
				switch(cmd)
				{
					case 0:{
						Reply_Send(L0000());
					}break;
					case 1:{
						Reply_Send(L0001());
					}break;
					case 2:{
						Reply_Send(L0002());
					}break;
					case 3:{
						Reply_Send(L0003());
					}break;
					case 4:{
						Reply_Send(L0004());
					}break;
					case 5:{
						Reply_Send(L0005());
					}break;
					case 6:{
						Reply_Send(L0006());
					}break;
					case 7:{
						Reply_Send(L0007());
					}break;
					case 8:{
						Reply_Send(L0008());
					}break;
					case 9:{
						Reply_Send(L0009());
					}break;
					default :{
					}break;
				}
			}break;
			case 'T':{
				switch(cmd)
				{
					case 0:{
						Reply_Send(T0000());
					}break;
					case 1:{
						Reply_Send(T0001());
					}break;
					case 2:{
					}break;
					case 3:{
						Reply_Send(T0003());
					}break;
					default :{
					}break;
				}
			}break;
			case 'D':{
				switch(cmd)
				{
					case 0:{
						Reply_Send(D0000());
					}break;
					case 1:{
						Reply_Send(D0001());
					}break;
					case 2:{
						Reply_Send(D0002());
					}break;
					case 3:{
						Reply_Send(D0003());
					}break;
					case 4:{
						Reply_Send(D0004());
					}break;
					case 5:{
						Reply_Send(D0005());
					}break;
					case 6:{
						Reply_Send(D0006());
					}break;
					case 7:{
						Reply_Send(D0007());
					}break;
					case 8:{
						Reply_Send(D0008());
					}break;
					case 9:{
						Reply_Send(D0009());
					}break;
					case 10:{
						Reply_Send(D0010());
					}break;
					case 11:{
						Reply_Send(D0011());
					}break;
					case 12:{
						Reply_Send(D0012());
					}break;
					case 13:{
						Reply_Send(D0013());
					}break;
					case 14:{
						Reply_Send(D0014());
					}break;
					case 15:{
						Reply_Send(D0015());
					}break;
					case 16:{
						Reply_Send(D0016());
					}break;
					case 17:{
						Reply_Send(D0017());
					}break;
					case 18:{
						Reply_Send(D0018());
					}break;
					case 19:{
						Reply_Send(D0019());
					}break;
					case 20:{
						Reply_Send(D0020());
					}break;
					case 21:{
						Reply_Send(D0021());
					}break;
					default :{
					}break;
				}
			}break;
			default :{
			}break;
		}
	}
}








/*void SftTmrCallBack_BLEled(void)       //60s  BLE ×´Ì¬µÆ 
{
    LED1=1;
}*/
