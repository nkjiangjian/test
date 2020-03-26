
#ifndef _BLE_H
#define _BLE_H

#include "sys.h"

void BleInit(void);
void Reply_Send(u16 bodylen);
void BlePacket(void);
void SftTmrCallBack_BLEled(void);


#endif
