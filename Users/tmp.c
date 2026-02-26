#include "led.h"
#include <stdio.h>

#define SCL_GPIO_1    GPIOC
#define SCL_PIN_1     BIT13
#define SDA_GPIO_1    GPIOC
#define SDA_PIN_1     BIT14

#define DELAY_T_1        1       

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
#define I2C_SENSOR_ADDR 0x80

void IIC_Start(void)
{
    SDA1_OUT();
    SCL1_OUT();
    SDA1_WRITE1;
    SCL1_WRITE1;
    FL_DelayUs(DELAY_T_1);
    SDA1_WRITE0;
    FL_DelayUs(DELAY_T_1);
    SCL1_WRITE0;
}

void IIC_Stop(void)
{
    SDA1_OUT();
    SCL1_WRITE0;
    SDA1_WRITE0;
    FL_DelayUs(DELAY_T_1);
    SCL1_WRITE1;
    FL_DelayUs(DELAY_T_1);
    SDA1_WRITE1;
    FL_DelayUs(DELAY_T_1);
}

// 等待应答信号，返回 0 表示应答成功，1 表示失败
uint8_t IIC_Wait_Ack(void)
{
    uint8_t timeout = 0;
    SDA1_IN();      // SDA 设为输入
    SDA1_WRITE1;    // 拉高
    FL_DelayUs(DELAY_T_1);
    SCL1_WRITE1;
    FL_DelayUs(DELAY_T_1);
    while(SDA1_READ())
    {
        timeout++;
        if(timeout > 250)
        {
            IIC_Stop();
            return 1;
        }
    }
    SCL1_WRITE0;
    return 0;
}

void IIC_Send_Byte(uint8_t byte)
{
    uint8_t i;
    SDA1_OUT();
    for(i = 0; i < 8; i++)
    {
        SCL1_WRITE0;
        if(byte & 0x80)
            SDA1_WRITE1;
        else
            SDA1_WRITE0;
        byte <<= 1;
        FL_DelayUs(DELAY_T_1);
        SCL1_WRITE1;
        FL_DelayUs(DELAY_T_1);
    }
    SCL1_WRITE0;
}

uint8_t IIC_Read_Byte(uint8_t ack)
{
    uint8_t i, receive = 0;
    SDA1_IN(); 
    for(i = 0; i < 8; i++)
    {
        SCL1_WRITE0;
        FL_DelayUs(DELAY_T_1);
        SCL1_WRITE1;
        receive <<= 1;
        if(SDA1_READ())
            receive++;
        FL_DelayUs(DELAY_T_1);
    }
    SCL1_WRITE0;
    SDA1_OUT();
    if(ack)
        SDA1_WRITE0;  // 发送ACK
    else
        SDA1_WRITE1;  // 发送NAK
    SCL1_WRITE1;
    FL_DelayUs(DELAY_T_1);
    SCL1_WRITE0;
    return receive;
}

// 读取 CHT8305E 温湿度数据
uint8_t Read_CHT8305E_temp_humi(void)
{
    unsigned char temp_h, temp_l, humi_h, humi_l;
    unsigned int raw_temp, raw_humi;
    float temperature, humidity;

    // 步骤1：触发温湿度转换（写入寄存器地址 0x00）
    IIC_Start();
    IIC_Send_Byte(I2C_SENSOR_ADDR); // 发送写地址
    if(IIC_Wait_Ack())
        return 0;
    IIC_Send_Byte(0x00);           // 写入寄存器地址 0x00（触发转换）
    IIC_Wait_Ack();
    IIC_Stop();

    FL_DelayMs(20);

    // 读出温湿度数据（温度高、温度低、湿度高、湿度低）
    IIC_Start();
    IIC_Send_Byte(I2C_SENSOR_ADDR | 0x01); // 发送读地址（0x81）
    IIC_Wait_Ack();
    temp_h = IIC_Read_Byte(1);  // 读温度高字节，发送ACK
    temp_l = IIC_Read_Byte(1);  // 读温度低字节，发送ACK
    humi_h = IIC_Read_Byte(1);  // 读湿度高字节，发送ACK
    humi_l = IIC_Read_Byte(0);  // 读湿度低字节，最后一个字节发送NAK
    IIC_Stop();

    raw_temp = ((unsigned int)temp_h << 8) | temp_l;
    raw_humi = ((unsigned int)humi_h << 8) | humi_l;

    // 温度(℃) = 165 * raw_temp / 65535 - 40
    // 湿度(%RH) = 100 * raw_humi / 65535
    temperature = (165.0 * raw_temp) / 65535.0 - 40.0;
    humidity = (100.0 * raw_humi) / 65535.0;

    printf("Current temperature is %.2f°C\n", temperature);
    printf("Current humidity is %.2f%%\n", humidity);

    return 1;
}
