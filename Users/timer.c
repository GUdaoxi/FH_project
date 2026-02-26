#include "led.h"
#include "fm33fh0xx_fl.h"

void Timer500usInit()
{                   CMU->PCLKCR4|=BIT4;    
                    INTMUX->CR1 |= BIT1|BIT0;                     
                    TAU->TAU0CR&=~BIT0;
                    TAU0->T0CFGR |= 0;                
                    TAU0->T0ARR = 7999;                                          
                    NVIC_DisableIRQ(MUX0_IRQn);                                 
                    NVIC_SetPriority(MUX0_IRQn, 0);                            
                    NVIC_EnableIRQ(MUX0_IRQn);                                  
                    TAU0->T0ISR = BIT0;                                
                    TAU0->T0IER |= BIT0;                                
                    TAU->TAU0CR |= BIT0;                             

}
uint8_t freq;
uint8_t flag=0;
void MUX0_IRQHandler(void)
{
  if(TAU0->T0ISR & BIT0)
  {
      TAU0->T0ISR = BIT0;
     // LED0_TOG();
      freq++;
      if(freq==33)
      {
        TAU->TAU0CR |= BIT3;  
        freq=0;
      }
  }
}


void Timer10usInit()  
              {        
                    CMU->PCLKCR4 |= BIT4;       
                    INTMUX->CR1 |= BIT8|BIT9;                     
                    TAU->TAU0CR &= ~BIT3;                             
                    TAU0->T3CFGR |= 0;                
                    TAU0->T3ARR = 159;                                          
                    NVIC_DisableIRQ(MUX4_IRQn);                                
                    NVIC_SetPriority(MUX4_IRQn, 0);                            
                    NVIC_EnableIRQ(MUX4_IRQn);                                  
                    TAU0->T3ISR = BIT0;                                 
                    TAU0->T3IER |=BIT0;                                
                    TAU->TAU0CR |= BIT3;                               
                }                    
                  

void MUX4_IRQHandler(void)
{
  if(TAU0->T3ISR & BIT0)
  {
      TAU0->T3ISR = BIT0;
     // LED0_TOG();
     // TAU->TAU0CR &= ~BIT3; 
  }
}

void PWMInit()
{
  CMU->PCLKCR1|=BIT7;
  CMU->PCLKCR4|=BIT4;
  GPIOA->FCR|=BIT7;
  GPIOA->DFS|=BIT6;
  TAU->TAU0CR&=~BIT4;
  TAU0->T4CFGR|=BIT16|BIT24;
  TAU0->T4MDR|=BIT0|BIT3;
  
  
}
void PWM_START()
{
  TAU0->T4ARR=3200;
  TAU0->T4CCR=1600;
  TAU->TAU0CR|=BIT4;
}
void PWM_STOP()
{
   TAU->TAU0CR&=~BIT4;
}