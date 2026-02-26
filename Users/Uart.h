#ifndef __UART_H__
#define __UART_H__

#include "fm33fh0xx_fl.h"
#define UArt3Baudrate     2400
#define UArt5Baudrate     9600
#define SysCLK         16000000
#define Uart3BGR_Value    (SysCLK/UArt3Baudrate-1)
#define Uart5BGR_Value    (SysCLK/UArt5Baudrate-1)
extern void Uart3_Init(void);
extern void Uart5_Init(void);
//extern void Uart3DisableTransmitter(void);
//extern void Uart3EnableTransmitter(void);
//extern void Uart3DisableReceiver(void);
//extern void Uart3EnableReceiver(void);
//extern void Uart5DisableTransmitter(void);
//extern void Uart5EnableTransmitter(void);
//extern void Uart5DisableReceiver(void);
//extern void Uart5EnableReceiver(void);
#endif
