/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_qspi.c
  * @author  FMSH Application Team
  * @brief   Src file of QSPI FL Module
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
  *******************************************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "fm33fh0xx_fl.h"

/** @addtogroup FM33FH0xx_FL_Driver
  * @{
  */

/** @addtogroup QSPI
  * @{
  */

#ifdef FL_QSPI_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup BSTIM16_FL_Private_Macros
  * @{
  */

#define         IS_FL_QSPI_INSTANCE(INSTANCE)                          ((INSTANCE) == QSPI)

#define         IS_FL_QSPI_FIFOTHRESHOLD_INSTANCE(__VALUE__)           (((__VALUE__) == FL_QSPI_FIFOTHR_1)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_2)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_3)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_4)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_5)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_6)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_7)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_8)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_9)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_10)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_11)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_12)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_13)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_14)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_15)||\
                                                                        ((__VALUE__) == FL_QSPI_FIFOTHR_16))

#define         IS_FL_QSPI_CHIPSELECTHIGHTIME_INSTANCE(__VALUE__)      (((__VALUE__) == FL_QSPI_CYCLE_1)||\
                                                                        ((__VALUE__) == FL_QSPI_CYCLE_2)||\
                                                                        ((__VALUE__) == FL_QSPI_CYCLE_3)||\
                                                                        ((__VALUE__) == FL_QSPI_CYCLE_4)||\
                                                                        ((__VALUE__) == FL_QSPI_CYCLE_5)||\
                                                                        ((__VALUE__) == FL_QSPI_CYCLE_6)||\
                                                                        ((__VALUE__) == FL_QSPI_CYCLE_7)||\
                                                                        ((__VALUE__) == FL_QSPI_CYCLE_8))
 
#define         IS_FL_QSPI_CLOCKMODE_INSTANCE(__VALUE__)               (((__VALUE__) == FL_QSPI_CLKMODE_0)||\
                                                                        ((__VALUE__) == FL_QSPI_CLKMODE_3)) 
                                                                                                               
#define         IS_FL_QSPI_INSTRUCTIONMODE_INSTANCE(__VALUE__)         (((__VALUE__) == FL_QSPI_IMODE_NONE)||\
                                                                        ((__VALUE__) == FL_QSPI_IMODE_SINGLE)||\
                                                                        ((__VALUE__) == FL_QSPI_IMODE_DOUBLE)||\
                                                                        ((__VALUE__) == FL_QSPI_IMODE_FOUR))

#define         IS_FL_QSPI_ADDRESSSIZE_INSTANCE(__VALUE__)             (((__VALUE__) == FL_QSPI_AD_SIZE_8bits)||\
                                                                        ((__VALUE__) == FL_QSPI_AD_SIZE_16bits)||\
                                                                        ((__VALUE__) == FL_QSPI_AD_SIZE_24bits)||\
                                                                        ((__VALUE__) == FL_QSPI_AD_SIZE_32bits))

#define         IS_FL_QSPI_ADDRESSMODE_INSTANCE(__VALUE__)             (((__VALUE__) == FL_QSPI_AD_MODE_NONE)||\
                                                                        ((__VALUE__) == FL_QSPI_AD_MODE_SINGLE)||\
                                                                        ((__VALUE__) == FL_QSPI_AD_MODE_DOUBLE)||\
                                                                        ((__VALUE__) == FL_QSPI_AD_MODE_FOUR))

#define         IS_FL_QSPI_ALTERNATESIZE_INSTANCE(__VALUE__)           (((__VALUE__) == FL_QSPI_AB_SIZE_8bits)||\
                                                                        ((__VALUE__) == FL_QSPI_AB_SIZE_16bits)||\
                                                                        ((__VALUE__) == FL_QSPI_AB_SIZE_24bits)||\
                                                                        ((__VALUE__) == FL_QSPI_AB_SIZE_32bits))

#define         IS_FL_QSPI_ALTERNATEMODE_INSTANCE(__VALUE__)           (((__VALUE__) == FL_QSPI_AB_MODE_NONE)||\
                                                                        ((__VALUE__) == FL_QSPI_AB_MODE_SINGLE)||\
                                                                        ((__VALUE__) == FL_QSPI_AB_MODE_DOUBLE)||\
                                                                        ((__VALUE__) == FL_QSPI_AB_MODE_FOUR))

#define         IS_FL_QSPI_DATAMODE_INSTANCE(__VALUE__)                (((__VALUE__) == FL_QSPI_DATA_MODE_NONE)||\
                                                                        ((__VALUE__) == FL_QSPI_DATA_MODE_SINGLE)||\
                                                                        ((__VALUE__) == FL_QSPI_DATA_MODE_DOUBLE)||\
                                                                        ((__VALUE__) == FL_QSPI_DATA_MODE_FOUR))
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup BSTIM16_FL_EF_Init
  * @{
  */

/**
  * @brief  根据QSPI_InitStruct初始化对应外设入口地址的寄存器值
  * @param  QSPIx 外设入口地址
  * @param  QSPI_InitStruct指向 @ref QSPI_InitTypeDef结构体指针
  * @retval 错误状态，可能值：
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_QSPI_Init(QSPI_Type *QSPIx, QSPI_InitTypeDef  *QSPI_InitStruct)
{
    FL_ErrorStatus status = FL_PASS;
    /* 入口参数检查 */
    assert_param(IS_FL_QSPI_INSTANCE(QSPIx));  
    assert_param(IS_FL_QSPI_FIFOTHRESHOLD_INSTANCE(QSPI_InitStruct->FifoThreshold));
    assert_param(IS_FL_QSPI_CHIPSELECTHIGHTIME_INSTANCE(QSPI_InitStruct->ChipSelectHighTime));
    assert_param(IS_FL_QSPI_CLOCKMODE_INSTANCE(QSPI_InitStruct->ClockMode));
    /* 使能总线时钟 */
    FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_QSPI);
    /* 配置QSPI时钟预分频系数 */
    FL_QSPI_WriteClockPrescaler(QSPI, QSPI_InitStruct->ClockPrescaler);
    /* 配置FIFO水位 */
    FL_QSPI_SetFIFOLevel(QSPI, QSPI_InitStruct->FifoThreshold);
    /* 使能延迟采样 */
    if(QSPI_InitStruct->SampleShifting == FL_ENABLE)
    {
        FL_QSPI_EnableDelayedSampling(QSPI);
    }
    else
    {
        FL_QSPI_DisableDelayedSampling(QSPI);
    }
    /* 配置nCS最小高电平时间 */
    FL_QSPI_SetCSHoldTime(QSPI, QSPI_InitStruct->ChipSelectHighTime);
    /* 配置Clock Mode */
    FL_QSPI_SetClockMode(QSPI,QSPI_InitStruct->ClockMode);

    return status;
}

void FL_QSPI_StructInit(QSPI_InitTypeDef  *QSPI_InitStruct)
{
    QSPI_InitStruct->ClockPrescaler     = 2-1;
    QSPI_InitStruct->FifoThreshold      = FL_QSPI_FIFOTHR_8;
    QSPI_InitStruct->SampleShifting     = FL_DISABLE;
    QSPI_InitStruct->ChipSelectHighTime = FL_QSPI_CYCLE_1;
    QSPI_InitStruct->ClockMode          = FL_QSPI_CLKMODE_0;
}

/**
  * @brief  关闭QSPI外设总线时钟
  *
  * @param  QSPIx 外设入口地址
  *
  * @retval 错误状态，可能值：
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_QSPI_DeInit(QSPI_Type *QSPIx)
{
    FL_ErrorStatus status = FL_PASS;
    /* 入口参数检查 */
    assert_param(IS_FL_QSPI_INSTANCE(QSPIx));
    FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_QSPI);

    return status;
}

/**
 * @}
 */

#endif /* FL_QSPI_DRIVER_ENABLED */

/**
 * @}
 */

/**
 * @}
 */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
