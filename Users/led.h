#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "fm33fh0xx_fl.h"

//BIT MAP======================================================
#define BIT0            0x00000001
#define BIT1            0x00000002
#define BIT2            0x00000004
#define BIT3            0x00000008
#define BIT4            0x00000010
#define BIT5            0x00000020
#define BIT6            0x00000040
#define BIT7            0x00000080
#define BIT8            0x00000100
#define BIT9            0x00000200
#define BIT10           0x00000400
#define BIT11           0x00000800
#define BIT12           0x00001000
#define BIT13           0x00002000
#define BIT14           0x00004000
#define BIT15           0x00008000
#define BIT16           0x00010000
#define BIT17           0x00020000
#define BIT18           0x00040000
#define BIT19           0x00080000
#define BIT20           0x00100000
#define BIT21           0x00200000
#define BIT22           0x00400000
#define BIT23           0x00800000
#define BIT24           0x01000000
#define BIT25           0x02000000
#define BIT26           0x04000000
#define BIT27           0x08000000
#define BIT28           0x10000000
#define BIT29           0x20000000
#define BIT30           0x40000000
#define BIT31           0x80000000

void SoftI2C1_Start(void);
void SoftI2C1_Stop(void);
void SoftI2C2_Start(void);
void SoftI2C2_Stop(void);
void SoftI2C3_Start(void);
void SoftI2C3_Stop(void);
void SoftI2C4_Start(void);
void SoftI2C4_Stop(void);
void Led1DrvI2CWriteByte(uint8_t data);
void Led2DrvI2CWriteByte(uint8_t data);
void Led3DrvI2CWriteByte(uint8_t data);
void Led4DrvI2CWriteByte(uint8_t data);
void Led1DrvWriteCmd(uint8_t cmd);
void Led2DrvWriteCmd(uint8_t cmd);
void Led3DrvWriteCmd(uint8_t cmd);
void Led4DrvWriteCmd(uint8_t cmd);
void Led1DrvWriteRam(uint8_t cmd, uint8_t* data, uint16_t len);
void Led2DrvWriteRam(uint8_t cmd , uint8_t* data, uint16_t len);
void Led3DrvWriteRam(uint8_t cmd, uint8_t* data, uint16_t len);
void Led4DrvWriteRam(uint8_t cmd, uint8_t* data, uint16_t len);
void Led1Init(void);
void Led2Init(void);
void Led3Init(void);
void Led4Init(void);
void LedOut(void);

#endif  /* LED_H */
