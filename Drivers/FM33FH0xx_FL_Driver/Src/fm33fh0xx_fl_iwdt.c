/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_iwdt.c
  * @author  FMSH Application Team
  * @brief   Src file of IWDT FL Module
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

/** @addtogroup IWDT
  * @{
  */

#ifdef FL_IWDT_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup IWDT_FL_Private_Macros
  * @{
  */

#define         IS_IWDT_INSTANCE(INTANCE)                    ((INTANCE) == IWDT)

#define         IS_FL_IWDT_WINDOWSVEL(__VALUE__)                ((__VALUE__) < 0xFFF)

#define         IS_FL_IWDT_OVERFLOWPERIOD(__VALUE__)            (((__VALUE__) == FL_IWDT_PERIOD_125MS)||\
                                                                 ((__VALUE__) == FL_IWDT_PERIOD_250MS)||\
                                                                 ((__VALUE__) == FL_IWDT_PERIOD_500MS)||\
                                                                 ((__VALUE__) == FL_IWDT_PERIOD_1000MS)||\
                                                                 ((__VALUE__) == FL_IWDT_PERIOD_2000MS)||\
                                                                 ((__VALUE__) == FL_IWDT_PERIOD_4000MS)||\
                                                                 ((__VALUE__) == FL_IWDT_PERIOD_8000MS)||\
                                                                 ((__VALUE__) == FL_IWDT_PERIOD_16000MS))


/**
  * @}
  */

/* Private consts ------------------------------------------------------------*/
/** @addtogroup IWDT_FL_Private_Consts
  * @{
  */



/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/



/* Exported functions --------------------------------------------------------*/
/** @addtogroup IWDT_FL_EF_Init
  * @{
  */

/**
  * @brief  复位IWDT外设
  *
  * @note   此函数只能用于配制前复位外设，因为IWDT开启后不可以关闭
  *
  * @param  IWDTx 外设入口地址
  *
  * @retval FL_ErrorStatus枚举值
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_IWDT_DeInit(IWDT_Type *IWDTx)
{
    assert_param(IS_IWDT_INSTANCE(IWDTx));
    return FL_PASS;
}


/**
  * @brief  根据 IWDT_InitStruct 初始化对应外设的寄存器值.
  *
  * @note   IWTD使能后将无法关闭，直到下一次芯片复位
  *
  * @param  IWDTx  外设入口地址
  * @param  IWDT_InitStruct 是 @ref FL_IWDT_InitTypeDef结构体，它包含指定IWDT外设的配置信息
  *
  * @retval ErrorStatus枚举值
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_IWDT_Init(IWDT_Type *IWDTx, FL_IWDT_InitTypeDef *IWDT_InitStruct)
{
    uint32_t i = 0;
    FL_ErrorStatus status = FL_FAIL;
    uint32_t iwdtCounter = 0;
    if(IWDT_InitStruct != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_IWDT_INSTANCE(IWDTx));
        assert_param(IS_FL_IWDT_WINDOWSVEL(IWDT_InitStruct->iwdtWindows));
        assert_param(IS_FL_IWDT_OVERFLOWPERIOD(IWDT_InitStruct->overflowPeriod));
        /* 开启总线时钟 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_IWDT);
        /* 清看门狗 */
        FL_IWDT_ReloadCounter(IWDTx);
        /* 配置独立看门狗溢出周期 */
        FL_IWDT_SetPeriod(IWDTx, IWDT_InitStruct->overflowPeriod);

        iwdtCounter = FL_IWDT_ReadCounter(IWDTx);
        /* 窗口功能延时 */
        if(IWDT_InitStruct->iwdtWindows != 0)
        {
            if(iwdtCounter == 0)
            {
                while((FL_IWDT_ReadCounter(IWDTx) != 1) && (i++ < 500))
                {

                }
            }
            else
            {
                while((FL_IWDT_ReadCounter(IWDTx) != 0) && (i++ < 500))
                {

                }
            }
        }
        /* 配置独立看门狗清狗窗口*/
        FL_IWDT_WriteWindow(IWDTx, IWDT_InitStruct->iwdtWindows);
        status = FL_PASS;
    }
    return status;
}


/**
  * @brief  设置 IWDT_InitStruct 为默认配置
  *
  * @param  IWDT_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_IWDT_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_IWDT_StructInit(FL_IWDT_InitTypeDef *IWDT_InitStruct)
{
    if(IWDT_InitStruct != NULL)
    {
        /* 默认不使用窗口 */
        IWDT_InitStruct->iwdtWindows    = 0;
        /*最长溢出时间*/
        IWDT_InitStruct->overflowPeriod = FL_IWDT_PERIOD_500MS;
    }
}


/**
  * @brief  IWDT清除计数值
  *
  * @param  None
  *
  * @retval  None
  */
void IWDT_Clr(void)
{
    IWDT->SERV = 0x12345A5AU;
}

/**
  * @}
  */

#endif /* FL_IWDT_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
