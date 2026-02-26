/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_clm.c
  * @author  FMSH Application Team
  * @brief   Src file of CLM FL Module
  * @version  V1.1.0
  * @date     13. June 2025
  *******************************************************************************************************
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

/** @addtogroup FM33FH0XXXX_FL_Driver
  * @{
  */
#define         IS_FL_CLM_INSTANCE(INSTANCE)                (((INSTANCE) == CLM0) || \
                                                             ((INSTANCE) == CLM1) || \
                                                             ((INSTANCE) == CLM2))

#define         IS_FL_CLM_MODE_INSTANCE(__VALUE__)          (((__VALUE__) == FL_CLM_WORKMODE_INTERRUPT) || \
                                                             ((__VALUE__) == FL_CLM_WORKMODE_RESET))

 /** @defgroup CLM CLM
  * @brief CLM FL driver
  * @{
  */

#ifdef FL_CLM_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup CLM_FL_Private_Macros
  * @{
  */
/**
  * @brief  根据CLM_InitStruct初始化对应外设入口地址的寄存器值
  * @param  CLMx 外设入口地址
  * @param  CLM_InitStruct 指向 @ref FL_CLM_InitTypeDef 结构体指针
  * @retval 错误状态，可能值：
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_CLM_Init(CLM_Type *CLMx, FL_CLM_InitTypeDef  *CLM_InitStruct)
{
    FL_ErrorStatus status = FL_PASS;
    /* 入口参数检查 */
    assert_param(IS_FL_CLM_INSTANCE(CLMx));  
    assert_param(IS_FL_CLM_MODE_INSTANCE(CLM_InitStruct->mode));
    if(CLMx == CLM0)
    {   /* 使能CLM0总线时钟 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM0);
        /* 配置CLMx监控时钟源 */
        FL_CLM_SetMonitorClock(CLM0,FL_CLM_MONCLK_RCHF);
    }
    else if(CLMx == CLM1)
    {   /* 使能CLM1总线时钟 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM1);
        /* 配置CLMx监控时钟源 */
        FL_CLM_SetMonitorClock(CLM0,FL_CLM_MONCLK_XTHF);
    }
    else
    {   /* 使能CLM2总线时钟 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM2);
        /* 配置CLMx监控时钟源 */
        FL_CLM_SetMonitorClock(CLM0,FL_CLM_MONCLK_PLL);
    }
    /* 配置CLMx工作模式 */
    FL_CLM_SetWorkingMode(CLMx,CLM_InitStruct->mode);
    /* 使能CLMx超时复位输出 */
    if(CLM_InitStruct->timeoutReset == FL_ENABLE)
    {
        FL_CLM_EnableTimeOutReset(CLMx);
    }
    else
    {
        FL_CLM_DisableTimeOutReset(CLMx);
    }
    /* 配置CLMx参考时钟周期 */
    FL_CLM_WriteReferenceClockCycle(CLMx,CLM_InitStruct->referenceclockCycle);
    /* 配置CLMx时钟监控比较值高阈值 */
    FL_CLM_WriteCompareHighThreshold(CLMx,CLM_InitStruct->CompareHighThreshold);
    /* 配置CLMx时钟监控比较值低阈值 */
    FL_CLM_WriteCompareLowThreshold(CLMx,CLM_InitStruct->CompareLowThreshold);
    return status;
}


/**
  * @brief  CLM 去初始化
  * @param  CLMx 外设入口地址
  * @retval 错误状态，可能值：
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_CLM_DeInit(CLM_Type *CLMx)
{
    FL_ErrorStatus status = FL_PASS;
    /* 参数入口检查 */
    assert_param(IS_FL_CLM_INSTANCE(CLMx));
    if(CLMx == CLM0)
    {
        /* CLM0 复位设置 */
        FL_RMU_EnablePeripheralReset(RMU);
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_CLM0);
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_CLM0);
        FL_RMU_DisablePeripheralReset(RMU);
        FL_CMU_DisableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM0);
    }
    else if(CLMx == CLM1)
    {
        /* CLM1 复位设置 */
        FL_RMU_EnablePeripheralReset(RMU);
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_CLM1);
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_CLM1);
        FL_RMU_DisablePeripheralReset(RMU);
        FL_CMU_DisableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM1);
    }
    else
    {
        /* CLM2 复位设置 */
        FL_RMU_EnablePeripheralReset(RMU);
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_CLM2);
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_CLM2);
        FL_RMU_DisablePeripheralReset(RMU);
        FL_CMU_DisableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM2);
    }
    return status;
}


#endif

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
