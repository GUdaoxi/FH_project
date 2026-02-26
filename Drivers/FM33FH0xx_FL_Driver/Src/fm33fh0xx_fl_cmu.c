/**
  ****************************************************************************************************
  * @file    fm33fh0xx_fl_cmu.c
  * @author  FMSH Application Team
  * @brief   Src file of CMU FL Module
  * @version  V1.1.0
  * @date     13. June 2025
  ****************************************************************************************************
  * @attention    
  * Copyright 2024 SHANGHAI FUDAN MICROELECTRONICS GROUP CO., LTD.(FUDAN MICRO.)
  *        
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met: 
  *    
  * 1. Redistributions of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  *    
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  *    
  * 3. Neither the name of the copyright holder nor the names of its contributors 
  *    may be used to endorse or promote products derived from this software without
  *    specific prior written permission.
  *    
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS"AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   
  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT   
  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    
  *
  ****************************************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "fm33fh0xx_fl.h"

/** @addtogroup FM33FH0xx_FL_Driver
  * @{
  */

/** @addtogroup CMU
  * @{
  */

#ifdef FL_CMU_DRIVER_ENABLED

/** @addtogroup CMU_FL_EF_Operation
  * @{
  */

/**
  * @brief  获取系统当前工作时钟SYSCLK
  *
  * @note   函数中用到了 @ref XTHF_VALUE 宏，这个宏应该被定义为外部晶振的输入频率值
  *
  * @retval 系统时钟频率(Hz)
  *
  */
uint32_t FL_CMU_GetSystemClockFreq(void)
{
    uint32_t frequency = 0;
    /* 获取系统时钟源 */
    switch(FL_CMU_GetSystemClockSource())
    {
        /* 系统时钟源为内部RCHF */
        case FL_CMU_SYSTEM_CLK_SOURCE_RCHF:
            /* 内部RCHF默认为8MHz ,可以配置为16或24M */
            frequency = FL_CMU_GetRCHFClockFreq();
            break;
        /* 系统时钟源为XTHF */
        case FL_CMU_SYSTEM_CLK_SOURCE_XTHF:
            frequency = XTHFClock;
            break;
        /* 系统时钟源为PLL */
        case FL_CMU_SYSTEM_CLK_SOURCE_PLL:
            frequency = FL_CMU_GetPLLClockFreq();
            break;
        /* 系统时钟源为XTLF */
        case FL_CMU_SYSTEM_CLK_SOURCE_XTLF:          
            frequency = 32768;
            break;
        /* 系统时钟源为RCLP */
        case FL_CMU_SYSTEM_CLK_SOURCE_RCLP:
            frequency = 32768;
            break;
        default:
            frequency = FL_CMU_GetRCHFClockFreq();
            break;
    }
    return frequency;
}
/**
  * @brief  获取AHB总线时钟频率
  *
  * @retval AHB总线时钟频率(Hz)
  *
  */
uint32_t FL_CMU_GetAHBClockFreq(void)
{
    uint32_t frequency = 0;
    /* 获取AHB分频系数，AHB源自系统主时钟 */
    switch(FL_CMU_GetAHBPrescaler())
    {
        case FL_CMU_AHBCLK_PSC_DIV1:
            frequency = FL_CMU_GetSystemClockFreq();
            break;
        case FL_CMU_AHBCLK_PSC_DIV2:
            frequency = FL_CMU_GetSystemClockFreq() / 2;
            break;
        case FL_CMU_AHBCLK_PSC_DIV4:
            frequency = FL_CMU_GetSystemClockFreq() / 4;
            break;
        case FL_CMU_AHBCLK_PSC_DIV8:
            frequency = FL_CMU_GetSystemClockFreq() / 8;
            break;
        case FL_CMU_AHBCLK_PSC_DIV16:
            frequency = FL_CMU_GetSystemClockFreq() / 16;
            break;
        default:
            frequency = FL_CMU_GetSystemClockFreq();
            break;
    }
    return frequency;
}

/**
  * @brief  获取当前系统的APB1总线时钟
  *
  * @retval APB1总线时钟频率(Hz)
  *
  */
uint32_t FL_CMU_GetAPB1ClockFreq(void)
{
    uint32_t frequency = 0;
    /* 获取APB1分频系数，APB源自AHB */
    switch(FL_CMU_GetAPB1Prescaler())
    {
        case FL_CMU_APB1CLK_PSC_DIV1:
            frequency = FL_CMU_GetAHBClockFreq();
            break;
        case FL_CMU_APB1CLK_PSC_DIV2:
            frequency = FL_CMU_GetAHBClockFreq() / 2;
            break;
        case FL_CMU_APB1CLK_PSC_DIV4:
            frequency = FL_CMU_GetAHBClockFreq() / 4;
            break;
        case FL_CMU_APB1CLK_PSC_DIV8:
            frequency = FL_CMU_GetAHBClockFreq() / 8;
            break;
        case FL_CMU_APB1CLK_PSC_DIV16:
            frequency = FL_CMU_GetAHBClockFreq() / 16;
            break;
        default:
            frequency = FL_CMU_GetAHBClockFreq();
            break;
    }
    return frequency;
}

/**
  * @brief  获取当前系统的APB2总线时钟
  *
  * @retval APB2总线时钟频率(Hz)
  *
  */
uint32_t FL_CMU_GetAPB2ClockFreq(void)
{
    uint32_t frequency = 0;
    /* 获取APB1分频系数，APB源自AHB */
    switch(FL_CMU_GetAPB2Prescaler())
    {
        case FL_CMU_APB2CLK_PSC_DIV1:
            frequency = FL_CMU_GetAHBClockFreq();
            break;
        case FL_CMU_APB2CLK_PSC_DIV2:
            frequency = FL_CMU_GetAHBClockFreq() / 2;
            break;
        default:
            frequency = FL_CMU_GetAHBClockFreq();
            break;
    }
    return frequency;
}

/**
  * @brief  获取RCHF输出时钟频率
  *
  * @retval 返回RCHF输出时钟频率(Hz)
  *
  */
uint32_t FL_CMU_GetRCHFClockFreq(void)
{
    uint32_t frequency = 0;
    switch(FL_CMU_RCHF_GetFrequency())
    {
        case FL_CMU_RCHF_FREQUENCY_8MHZ:
            frequency = 8000000;
            break;
        case FL_CMU_RCHF_FREQUENCY_16MHZ:
            frequency = 16000000;
            break;
        case FL_CMU_RCHF_FREQUENCY_24MHZ:
            frequency = 24000000;
            break;
        case FL_CMU_RCHF_FREQUENCY_32MHZ:
            frequency = 32000000;
            break;
        default:
            frequency = 8000000;
            break;
    }
    return frequency;
}
/**
  * @brief  获取PLL输出时钟频率
  *
  * @retval 返回PLL输出时钟频率(Hz)
  *
  */
uint32_t FL_CMU_GetPLLClockFreq(void)
{
    uint32_t frequency = 0;
    uint32_t multiplier = 0;
    /* 获取PLL时钟源 */
    switch(FL_CMU_PLL_GetClockSource())
    {
        case FL_CMU_PLL_CLK_SOURCE_RCHF:
            /* 获取RCHF配置主频 */
            frequency = FL_CMU_GetRCHFClockFreq();
            break;
        case FL_CMU_PLL_CLK_SOURCE_XTHF:
            frequency = XTHFClock;
            break;
        default:
            frequency = FL_CMU_GetRCHFClockFreq();
            break;
    }
    /* 获取PLL时钟分频系数 */
    switch(FL_CMU_PLL_GetPrescaler())
    {
        case FL_CMU_PLL_PSC_DIV1:
            break;
        case FL_CMU_PLL_PSC_DIV2:
            frequency /= 2;
            break;
        case FL_CMU_PLL_PSC_DIV4:
            frequency /= 4;
            break;
        case FL_CMU_PLL_PSC_DIV8:
            frequency /= 8;
            break;
        case FL_CMU_PLL_PSC_DIV12:
            frequency /= 12;
            break;
        case FL_CMU_PLL_PSC_DIV16:
            frequency /= 16;
            break;
        case FL_CMU_PLL_PSC_DIV24:
            frequency /= 24;
            break;
        case FL_CMU_PLL_PSC_DIV32:
            frequency /= 32;
            break;
        default:
            break;
    }
    multiplier = FL_CMU_PLL_ReadMultiplier() + 1;
    frequency *= multiplier;
    return frequency;
}

/**
  * @}
  */

#endif /* FL_CMU_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
