/**
  ****************************************************************************************************
  * @file    fm33fh0xx_fl_wwdt.c
  * @author  FMSH Application Team
  * @brief   Src file of GPIO FL Module
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

/** @addtogroup WWDT
  * @{
  */

#ifdef FL_WWDT_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup WWDT_FL_Private_Macros
  * @{
  */

#define         IS_WWDT_INSTANCE(INTANCE)                ((INTANCE) == WWDT)

#define         IS_FL_WWDT_OVERFLOWPERIOD(__VALUE__)            (((__VALUE__) == FL_WWDT_PERIOD_1CNT)||\
                                                                 ((__VALUE__) == FL_WWDT_PERIOD_4CNT)||\
                                                                 ((__VALUE__) == FL_WWDT_PERIOD_16CNT)||\
                                                                 ((__VALUE__) == FL_WWDT_PERIOD_64CNT)||\
                                                                 ((__VALUE__) == FL_WWDT_PERIOD_128CNT)||\
                                                                 ((__VALUE__) == FL_WWDT_PERIOD_256CNT)||\
                                                                 ((__VALUE__) == FL_WWDT_PERIOD_512CNT)||\
                                                                 ((__VALUE__) == FL_WWDT_PERIOD_1024CNT))

/**
  * @}
  */

/* Private consts ------------------------------------------------------------*/
/** @addtogroup WWDT_FL_Private_Consts
  * @{
  */



/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/



/* Exported functions --------------------------------------------------------*/
/** @addtogroup WWDT_FL_EF_Init
  * @{
  */
/**
  * @brief  关闭WWDT外设总线时钟
  *
  * @note   WWDT开启不能再关闭，直到下一次复位。低功耗休眠模式下 WWDT 停止运行
  *
  * @param  WWDTx 外设入口地址
  *
  * @retval FL_ErrorStatus枚举值
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_WWDT_DeInit(WWDT_Type *WWDTx)
{
    assert_param(IS_WWDT_INSTANCE(WWDTx));
    return FL_PASS;
}
/**
  * @brief  根据 WWDT_InitStruct初始化对应外设入口地址的寄存器值.
  *
  * @note   WWTD使能后将无法关闭，直到下一次芯片复位
  *
  * @param  WWDTx 外设入口地址
  *
  * @param  WWDT_InitStruct 指向 @ref FL_WWDT_InitTypeDef 结构体的指针
  *
  * @retval ErrorStatus枚举值
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_WWDT_Init(WWDT_Type *WWDTx, FL_WWDT_InitTypeDef *WWDT_InitStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    if(WWDT_InitStruct != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_WWDT_INSTANCE(WWDTx));
        assert_param(IS_FL_WWDT_OVERFLOWPERIOD(WWDT_InitStruct->overflowPeriod));
        /* 开启总线时钟 */
        FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_WWDT);     /* WWDT时钟为RCLP */
        /* 配置独立看门狗溢出周期 */
        FL_WWDT_SetPeriod(WWDTx, WWDT_InitStruct->overflowPeriod);
        /* 启动看门狗 */
        FL_WWDT_Enable(WWDTx);
        status = FL_PASS;
    }
    return status;
}
/**
  * @brief  设置 WWDT_InitStruct 为默认配置
  *
  * @param  WWDT_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_WWDT_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_WWDT_StructInit(FL_WWDT_InitTypeDef *WWDT_InitStruct)
{
    if(WWDT_InitStruct != NULL)
    {
        /* 默认最长溢出周期 */
        WWDT_InitStruct->overflowPeriod = FL_WWDT_PERIOD_1024CNT;
    }
}

/**
  * @}
  */

#endif /* FL_WWDT_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
