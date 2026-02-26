/**************************************************************************//**
 * @file     system_fm33fh0xx.c
 * @brief    CMSIS Cortex-M0 Device Peripheral Access Layer Source File for
 *           Device FM33FH0xx
 * @version  V1.1.0
 * @date     13. June 2025
 *
 * @note
 *
 ******************************************************************************/
/* Copyright (c) 2012 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/

#include "system_fm33fh0xx.h"

/* Clock Variable definitions ------------------------------------------------*/
uint32_t XTLFClock = XTLF_DEFAULT_VALUE;        /*!< External Low-freq Osc Clock Frequency (XTLF) */
uint32_t XTHFClock = XTHF_DEFAULT_VALUE;        /*!< External High-freq Osc Clock Frequency (XTHF) */
uint32_t SystemCoreClock = HCLK_DEFAULT_VALUE;  /*!< System Clock Frequency (Core Clock) */

/* Clock functions -----------------------------------------------------------*/
/**
 *  @brief Retrieve the PLL clock frequency
 * 
 *  @retval PLL clock frequency 
 */
static uint32_t SystemPLLClockUpdate(void)
{
    uint32_t clock = 0;
    
    /* Acquire PLL clock source */
    switch ((CMU->PLLCR >> 1) & 0x1)
    {
        case 0:
            switch ((CMU->RCHFCR >> 16) & 0xFU)
            {
                case 1: /* 16MHz */
                    clock = 16000000;
                    break;
                
                case 2: /* 24MHz */
                    clock = 24000000;
                    break;

                case 3: /* 32MHz */
                    clock = 32000000;
                    break;             
    
                case 0: /* 8MHz */
                default:
                    clock = 8000000;
                    break;
            }
            break;
        
        case 1:
            clock = XTHFClock;
            break;
    }
    
    /* Acquire PLL prescaler */
    switch ((CMU->PLLCR >> 0x4) & 0x7)
    {
        case 0: /* input divided by 1 */
            clock /= 1;
            break;
        
        case 1: /* input divided by 2 */
            clock /= 2; 
            break;
        
        case 2: /* input divided by 4 */
            clock /= 4;
            break;
        
        case 3: /* input divided by 8 */
            clock /= 8;
            break;
        
        case 4: /* input divided by 12 */
            clock /= 12;
            break;
        
        case 5: /* input divided by 16 */
            clock /= 16;
            break;
        
        case 6: /* input divided by 24 */
            clock /= 24;
            break;
        
        case 7: /* input divided by 32 */
            clock /= 32;
            break;
    }
    
    /* Acquire PLL multiplier and calculate PLL frequency */
    clock = clock * (((CMU->PLLCR >> 16) & 0x3FF) + 1);
       
    return clock;
}
 
/**
 *  @brief Update the core clock frequency variable: SystemCoreClock
 *
 */
void SystemCoreClockUpdate(void)
{
    switch ((CMU->SYSCLKCR >> 0) & 0x7)
    {        
        case 1: /* XTHF */
            SystemCoreClock = XTHFClock;
            break;
        
        case 2: /* PLL */
            SystemCoreClock = SystemPLLClockUpdate();
            break;              
        case 5: /* XTLF*/
            SystemCoreClock = 32768;
            break;       
        case 6: /* RCLP */
            SystemCoreClock = 32768;
            break;
        
        default:
            switch ((CMU->RCHFCR >> 16) & 0xf)
            {
                case 1: /* 16MHz */
                    SystemCoreClock = 16000000;
                    break;
                
                case 2: /* 24MHz */
                    SystemCoreClock = 24000000;
                    break;
    
                case 3: /* 32MHz */
                    SystemCoreClock = 32000000;
                    break;
    
                case 0: /* 8MHz */
                default:
                    SystemCoreClock = 8000000;
                    break;
            }
            break;
    }
    
    /* 获取AHB时钟分频 */
    switch ((CMU->SYSCLKCR >> 8) & 0x7)
    { 
        case 0: /* AHB不分频 */
            SystemCoreClock = SystemCoreClock/1;
            break;
    
        case 1: /* AHB不分频 */
            SystemCoreClock = SystemCoreClock/1;
            break;
    
        case 2: /* AHB不分频 */
            SystemCoreClock = SystemCoreClock/1;
            break;

        case 3: /* AHB不分频 */
            SystemCoreClock = SystemCoreClock/1;
            break;

        case 4: /* AHB 2分频 */
            SystemCoreClock = SystemCoreClock/2;
            break;
    
        case 5: /* AHB 4分频 */
            SystemCoreClock = SystemCoreClock/4;
            break;
        
        case 6: /* AHB 8分频 */
            SystemCoreClock = SystemCoreClock/8;
            break;
        
        case 7: /* AHB 16分频 */
            SystemCoreClock = SystemCoreClock/16;
            break;
        
        default:/* AHB不分频 */
            SystemCoreClock = SystemCoreClock/1;
            break;
    }
}

/**
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */
void SystemInit(void)
{
    FLASH->ECCCR=0xAAAA;
    #if !defined(MFANG) && defined(USE_LSCLK_CLOCK_SRC_XTLF)
    uint32_t temp;
    #endif
    
    #if defined(USE_IWDT_ON_STARTUP)
    CMU->PCLKCR1 |= 0x20U;              /* Enable IWDT Operation Clock */
    IWDT->CR = IWDT_OVERFLOW_PERIOD;    /* Configure IWDT overflow period */
    IWDT->SERV = 0x12345A5AU;           /* Enable IWDT */
    #endif
    
    /* Reset PLL & SYSCLK selection */
    CMU->PLLCR = 0x00000000U;
    CMU->SYSCLKCR = 0x0A000000U;
                
    /* PDR  Configuration */
    RMU->PDRCR = 0x07U;
        
    /* Disable IWDT & WWDT, enable other peripherals(e.g. timers) under Debug Mode */
    SCU->DBGCR = 0x3U;
    
    /* Load clock trim value */
    CMU->RCHFTR = RCHF8M_TRIM;
    CMU->RCLPTR = RCLP_TRIM;
    
    /* Enable PAD Operation Clock */
    CMU->PCLKCR1 |= (0x1U << 7);
    
    /* Enable TSI BUS Clock */
    CMU->PCLKCR2 |= (0x1U <<  11);
    /* Enable TSI Operation Clock */
    CMU->OPCER1 |= (0x1U << 16);
    /* Reset TSI_TEST Ch_idle_cfg */
    TSI->TEST &= (~(0x01 << 18));
    /* Disable TSI BUS Clock */
    CMU->PCLKCR2 &= (~(0x1U <<  11));
    /* Disable TSI Operation Clock */
    CMU->OPCER1 &= (~(0x1U << 16));
    
    /* Enable SWD port pull up */
    GPIOG->PUDEN |= (0x3U << 8U);
    GPIOG->PUDEN &= ~(0x3U << 24U);  

    /* Config PA14, PA15 for high resistance state */
    GPIOA->INEN &= ~(0x3U << 14U);
    GPIOA->PUDEN &= ~(0x3U << 14U);   
    
    /* Update System Core Clock */
    SystemCoreClockUpdate();
    
    #if defined(USE_IWDT_ON_STARTUP)
    IWDT->SERV = 0x12345A5AU; /* Feed IWDT */
    #endif
} 



