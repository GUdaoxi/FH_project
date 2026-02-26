#include "Uart.h"
#include "led.h"
/*****************��ֲ�޸�������START************************/


/*****************��ֲ�޸�������START************************/
//uart3 uart5 �ֱ��ж�9 �ж�11
//uart3 pc15 pg7   pin49 pin50
//uart5 pc5 pc6    pin42 pin43


uint8_t rxIndex = 0;
/*****************��ֲ�޸�������START************************/


void Uart3_Init(void)
{
  CMU->PCLKCR1 |= BIT7;                                     //PAD总线
  GPIOC->FCR |= BIT31;  
  GPIOG->FCR |= BIT15;
  GPIOC->DFS |= BIT31;
  GPIOG->DFS |= BIT15;
  CMU->PCLKCR3 |= BIT11;                                     //串口3总线时钟
  CMU->OPCER1|=BIT11;                                          //串口3工作时钟
  UART3->MCR = 0X0;
  
   UART3->CSR &= ~(BIT4|BIT5);                                  /*UART config none parity*/ 
  UART3->CSR &= ~(BIT6|BIT7);                                /*UART config 8 data bits*/   
  UART3->CSR |= BIT6;                                           
  UART3->CSR &= ~BIT8;     
  
  UART3->BGR = Uart3BGR_Value;                               //波特率 
  UART3->ISR = BIT8|BIT1;                                     //TXBE TXBF标致
  UART3->IER |= BIT8|BIT1;                                    //发送接收中断使能
  UART3->CSR |= BIT1;                               //发送 接收使能
    
  NVIC_DisableIRQ(MUX9_IRQn);
  NVIC_SetPriority(MUX9_IRQn, 3);                       //中断优先级配置
  NVIC_EnableIRQ(MUX9_IRQn);
}

void Uart3DisableTransmitter(void)
{
  UART3->IER &= ~BIT1;                                               /*send interrupt disable*/
  UART3->CSR &= ~BIT0;                                                 /*send disable*/  
}

void Uart3EnableTransmitter(void)
{
  UART3->IER |= BIT1;                                                /*send interrupt enable*/
  UART3->CSR |= BIT0;                                                  /*send enable*/     
}

void Uart3DisableReceiver(void)
{
  UART3->IER &= ~BIT8;                                               /*receive interrupt disable*/
  UART3->CSR &= ~BIT1;                                                 /*receive disable*/    
}


void Uart3EnableReceiver(void)
{
  UART3->ISR = BIT8;                                                   /*clear receive flag*/
  UART3->IER |= BIT8;                                                /*receive interrupt enable*/
  UART3->CSR |= BIT1;                                                  /*receive enable*/    
}


void MUX9_IRQHandler(void)
{
   volatile uint32_t IFflag;
  IFflag  = UART3->ISR;
  uint8_t i=0;
  if((UART3->ISR & BIT1) && (IFflag & BIT1))
  {
    //UART3->TXBUF=receivedData[i];
  }
  if((UART3->ISR & BIT8) && (IFflag & BIT8))
  {
       UART3->ISR = BIT8;   
  }

}



void Uart5DisableTransmitter(void)
{
  UART5->IER &= ~BIT1;                                               /*send interrupt disable*/
  UART5->CSR &= ~BIT0;                                                 /*send disable*/  
}

void Uart5EnableTransmitter(void)
{
  UART5->IER |= BIT1;                                                /*send interrupt enable*/
  UART5->CSR |= BIT0;                                                  /*send enable*/     
}

void Uart5DisableReceiver(void)
{
  UART5->IER &= ~BIT8;                                               /*receive interrupt disable*/
  UART5->CSR &= ~BIT1;                                                 /*receive disable*/    
}


void Uart5EnableReceiver(void)
{
  UART5->ISR = BIT8;                                                   /*clear receive flag*/
  UART5->IER |= BIT8;                                                /*receive interrupt enable*/
  UART5->CSR |= BIT1;                                                  /*receive enable*/    
}




