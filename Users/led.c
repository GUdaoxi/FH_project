#include "led.h"

#define SCL_GPIO_1    GPIOC
#define SCL_PIN_1     BIT13
#define SDA_GPIO_1    GPIOC
#define SDA_PIN_1     BIT14

#define SCL_GPIO_2    GPIOC
#define SCL_PIN_2     BIT8
#define SDA_GPIO_2    GPIOC
#define SDA_PIN_2     BIT9

#define DELAY_T_1        1       //时钟延时
#define DELAY_T_2        1       //时钟延时

#define SCL1_IN()                    SCL_GPIO_1->FCR &= ~(SCL_PIN_1*SCL_PIN_1*3)
#define SCL1_OUT()                   SCL_GPIO_1->FCR |= (SCL_PIN_1*SCL_PIN_1)

#define SDA1_IN()                    SDA_GPIO_1->FCR &= ~(SDA_PIN_1*SDA_PIN_1*3)               
#define SDA1_OUT()                   SDA_GPIO_1->FCR |= (SDA_PIN_1*SDA_PIN_1)

#define SCL1_WRITE1                  (SCL_GPIO_1->DSET = SCL_PIN_1)
#define SCL1_WRITE0                  (SCL_GPIO_1->DRST = SCL_PIN_1)
                            
#define SDA1_WRITE1                  (SDA_GPIO_1->DSET = SDA_PIN_1)
#define SDA1_WRITE0                  (SDA_GPIO_1->DRST = SDA_PIN_1)

#define SCL1_READ()                  (SCL_GPIO_1->DIN & SCL_PIN_1) 
#define SDA1_READ()                  (SDA_GPIO_1->DIN & SDA_PIN_1)

/***************************************************************************/ 

#define SCL2_IN()                    SCL_GPIO_2->FCR &= ~(SCL_PIN_2*SCL_PIN_2*3)
#define SCL2_OUT()                   SCL_GPIO_2->FCR |= (SCL_PIN_2*SCL_PIN_2)

#define SDA2_IN()                    SDA_GPIO_2->FCR &= ~(SDA_PIN_2*SDA_PIN_2*3)               
#define SDA2_OUT()                   SDA_GPIO_2->FCR |= (SDA_PIN_2*SDA_PIN_2)

#define SCL2_WRITE1                  (SCL_GPIO_2->DSET = SCL_PIN_2)
#define SCL2_WRITE0                  (SCL_GPIO_2->DRST = SCL_PIN_2)
                            
#define SDA2_WRITE1                  (SDA_GPIO_2->DSET = SDA_PIN_2)
#define SDA2_WRITE0                  (SDA_GPIO_2->DRST = SDA_PIN_2)

#define SCL2_READ()                  (SCL_GPIO_2->DIN & SCL_PIN_2) 
#define SDA2_READ()                  (SDA_GPIO_2->DIN & SDA_PIN_2)
uint8_t Delay_Count;
#define IIC_Delay(time)              for(Delay_Count=0;Delay_Count<time;Delay_Count++)

uint8_t data[80]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
                  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
                  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
                  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
uint8_t data1[80]={0};
uint8_t data2[80]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
                  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
                  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
                  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

void SoftI2C1_Start(void)
{   
    SDA1_WRITE1;
    SCL1_WRITE1;    
    SDA1_OUT(); 
    SCL1_OUT();     
    IIC_Delay(DELAY_T_1);

    SDA1_WRITE0;   //SCL=1时，SDA=1->0,为起始位
    IIC_Delay(DELAY_T_1);

    SCL1_WRITE0;
    IIC_Delay(DELAY_T_1);  
}
//I2C1发送停止位
void SoftI2C1_Stop(void)
{
    SDA1_OUT();
    SDA1_WRITE0;
    IIC_Delay(DELAY_T_1);

    SCL1_WRITE1;
    IIC_Delay(DELAY_T_1);

    SDA1_WRITE1;   //SCL=1时，SDA=0->1，为停止位
    IIC_Delay(DELAY_T_1);

}

//I2C2发送起始位
void SoftI2C2_Start(void)
{   
    SDA2_WRITE1;
    SCL2_WRITE1;    
    SDA2_OUT(); 
    SCL2_OUT();     
    IIC_Delay(DELAY_T_2);

    SDA2_WRITE0;   //SCL=1时，SDA=1->0,为起始位
    IIC_Delay(DELAY_T_2);

    SCL2_WRITE0;
    IIC_Delay(DELAY_T_2);  
}

//I2C2发送停止位
void SoftI2C2_Stop(void)
{
    SDA2_OUT();
    SDA2_WRITE0;
    IIC_Delay(DELAY_T_2);

    SCL2_WRITE1;
    IIC_Delay(DELAY_T_2);

    SDA2_WRITE1;   //SCL=1时，SDA=0->1，为停止位
    IIC_Delay(DELAY_T_2);

}
void Led1DrvI2CWriteByte(uint8_t data)
{
    uint8_t i;
    (data & 0x80) ? SDA1_WRITE1 : SDA1_WRITE0;            //提前判断下一个要发的字节的第一个bit的状态，避免出现不需要的脉冲
    SDA1_OUT();
    
    for(i=0; i<8; i++)
    {
        (data & 0x80) ? SDA1_WRITE1 : SDA1_WRITE0;
        IIC_Delay(DELAY_T_1);
        SCL1_WRITE1;
        IIC_Delay(DELAY_T_1);                
        SCL1_WRITE0;
        IIC_Delay(DELAY_T_1);   
        data <<= 1;
    }
       
}

void Led2DrvI2CWriteByte(uint8_t data)
{
    uint8_t i;
    (data & 0x80) ? SDA2_WRITE1 : SDA2_WRITE0;            //提前判断下一个要发的字节的第一个bit的状态，避免出现不需要的脉冲
    SDA2_OUT();
    
    for(i=0; i<8; i++)
    {
        (data & 0x80) ? SDA2_WRITE1 : SDA2_WRITE0;
        IIC_Delay(DELAY_T_2);
        SCL2_WRITE1;
        IIC_Delay(DELAY_T_2);                
        SCL2_WRITE0;
        IIC_Delay(DELAY_T_2);   
        data <<= 1;
    }
       
}
void Led1DrvWriteCmd(uint8_t cmd)
{
  // int i;
   SoftI2C1_Start();	 
   Led1DrvI2CWriteByte(cmd);
   SoftI2C1_Stop();

}

void Led2DrvWriteCmd(uint8_t cmd)
{
   //int i;
   SoftI2C2_Start();	 
   Led2DrvI2CWriteByte(cmd);
   SoftI2C2_Stop();
}
void Led1DrvWriteRam(uint8_t cmd, uint8_t* data, uint16_t len)
{
   int i;
   SoftI2C1_Start();
	 Led1DrvI2CWriteByte(cmd);
   for(i=0; i<len; i++)
    {
        Led1DrvI2CWriteByte(data[i]);
    }
   SoftI2C1_Stop();

}

void Led2DrvWriteRam(uint8_t cmd , uint8_t* data, uint16_t len)
{
   int i;
   SoftI2C2_Start();
	 Led2DrvI2CWriteByte(cmd);
   for(i=0; i<len; i++)
    {
        Led2DrvI2CWriteByte(data[i]);
    }
   SoftI2C2_Stop();

}

void Led1Init(void)
{

   Led1DrvWriteCmd(0x05);//设置CURRENT
   Led1DrvWriteCmd(0x78);//设置G_N
   Led1DrvWriteRam(0xC0,data,80);//设置显示
   Led1DrvWriteCmd(0xBB);//点亮

}

void Led2Init(void)
{

   Led2DrvWriteCmd(0x05);//设置CURRENT
   Led2DrvWriteCmd(0x78);//设置G_N
   Led2DrvWriteRam(0xC0,data,80);//设置显示
   Led2DrvWriteCmd(0xBB);//点亮

}

