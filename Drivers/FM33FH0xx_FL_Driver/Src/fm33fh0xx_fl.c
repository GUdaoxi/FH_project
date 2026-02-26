/**
  ****************************************************************************************************
  * @file    fm33fh0xx_fl.c
  * @author  FMSH Application Team
  * @brief   Source file of FL Driver Library
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
  *******************************************************************************************************
  */

/* Includes ----------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl.h"

/** @addtogroup FL_EF_DELAY
  * @{
  */

/**
  * @brief  Initialize the timer(default is Systick) used as delay timer.
  * @note   The function is declared as __WEAK to be overwritten in case of other
  *         implementation in user file.
  * @param  None
  * @retval None
  */
__WEAK void FL_DelayInit(void)
{
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

/**
  * @brief  Provide block delay in microseconds.
  * @note   The function is declared as __WEAK to be overwritten in case of other
  *         implementation in user file.
  * @param  count   specifies the delay count in microseconds.
  * @retval None
  */
__WEAK void FL_DelayUs(uint32_t count)
{
    count = FL_DELAY_US * count;
    count = count > 16777216 ? 16777216 : count;
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    SysTick->LOAD = count - 1;
    SysTick->VAL = 0;
    while(!((SysTick->CTRL >> 16) & 0x1));
}

/**
  * @brief  Provide blocking delay in milliseconds.
  * @note   The function is declared as __WEAK to be overwritten in case of other
  *         implementation in user file.
  * @param  count   specifies the delay count in milliseconds.
  * @retval None
  */
__WEAK void FL_DelayMs(uint32_t count)
{
    while(count--)
    {
        FL_DelayUs(1000);
    }
}

/**
  * @brief  Provide no-blocking delay initialization in microseconds.
  * @note   Should be follow By while(!FL_DelayEnd()){ ** user code ** } immediately.
  *         The function is declared as __WEAK to be overwritten in case of other
  *         implementation in user file.
  * @param  count   specifies the delay count in microseconds.
  * @retval None
  */
__WEAK void FL_DelayUsStart(uint32_t count)
{
    count = FL_DELAY_US * count;
    count = count > 16777216 ? 16777216 : count;
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    SysTick->LOAD = count - 1;
    SysTick->VAL = 0;
}

/**
  * @brief  Provide no-blocking delay initialization in milliseconds.
  * @note   Should be followed By while(!FL_DelayEnd()){ ** user code ** }.
  *         The function is declared as __WEAK to be overwritten in case of other
  *         implementation in user file.
  * @param  count   specifies the delay count in milliseconds.
  * @retval None
  */
__WEAK void FL_DelayMsStart(uint32_t count)
{
    FL_DelayUsStart(1000 * count);
}

/**
  * @brief  Showing if the no-blocking delay has ended.
  * @note   Should be used with FL_DelayMs/UsStart() function.
  *         The function is declared as __WEAK to be overwritten in case of other
  *         implementation in user file.
  * @param  count   specifies the delay count in milliseconds.
  * @retval true  - delay has ended
  *         false - delay is in progress
  */
__WEAK bool FL_DelayEnd(void)
{
    return (((SysTick->CTRL >> 16) & 0x1) == 0x1);
}

/**
  * @}
  */

/** @addtogroup FL_EF_DELAY
  * @{
  */

void FL_Init(void)
{
    /* Init delay support function */
    FL_DelayInit();
}

/**
  * @}
  */

/** @addtogroup FL_EF_NVIC
  * @{
  */

/**
  * @brief  Configure NVIC for specified Interrupt.
  * @param  configStruct    NVIC configuration.
  * @param  irq             Interrupt number.
  * @retval None
  */
void FL_NVIC_Init(FL_NVIC_ConfigTypeDef *configStruct, IRQn_Type irq)
{
    /* Check parameter */
    if(configStruct->preemptPriority > 3)
    {
        configStruct->preemptPriority = 3;
    }

    NVIC_DisableIRQ(irq);
    NVIC_SetPriority(irq, configStruct->preemptPriority);
    NVIC_ClearPendingIRQ(irq);
    NVIC_EnableIRQ(irq);
}

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/



