/**
  ****************************************************************************************************
  * @file    fm33fh0xx_fl_svd.c
  * @author  FMSH Application Team
  * @brief   Src file of SVD FL Module
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

/** @addtogroup FM33LF0XX_FL_Driver
  * @{
  */

/** @addtogroup SVD
  * @{
  */

#ifdef FL_SVD_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup SVD_FL_Private_Macros
  * @{
  */
#define         IS_SVD_INSTANCE(INSTANCE)                  (((INSTANCE) == SVD))

#define         IS_FL_SVD_WARNING_THRESHOLD_LEVEL(__VALUE__)        (((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP0)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP1)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP2)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP3)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP4)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP5)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP6)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP7)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP8)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP9)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP10)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP11)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP12)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP13)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP14)||\
                                                                     ((__VALUE__) == FL_SVD_WARNING_THRESHOLD_GROUP15))

#define         IS_FL_SVD_SVSCONFIG(__VALUE__)             (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))

#define         IS_FL_SVD_REFERENCE_VOLTAGE(__VALUE__)     (((__VALUE__) == FL_SVD_REFERENCE_1P0V)||\
                                                            ((__VALUE__) == FL_SVD_REFERENCE_0P95V)||\
                                                            ((__VALUE__) == FL_SVD_REFERENCE_0P9V))

#define         IS_FL_SVD_DIGITAL_FILTER(__VALUE__)        (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))

#define         IS_FL_SVD_WORK_MODE(__VALUE__)             (((__VALUE__) == FL_SVD_WORK_MODE_CONTINUOUS)||\
                                                            ((__VALUE__) == FL_SVD_WORK_MODE_PERIODIC))

#define         IS_FL_SVD_ENABLE_PERIOD(__VALUE__)         (((__VALUE__) == FL_SVD_ENABLE_PERIOD_62P5MS)||\
                                                            ((__VALUE__) == FL_SVD_ENABLE_PERIOD_256MS)||\
                                                            ((__VALUE__) == FL_SVD_ENABLE_PERIOD_1000MS)||\
                                                            ((__VALUE__) == FL_SVD_ENABLE_PERIOD_4000MS))
                                                            

#define         IS_FL_SVD_FUNC_MODE(__VALUE__)             (((__VALUE__) == FL_SVD_Mode_DISABLE)||\
                                                            ((__VALUE__) == FL_SVD_Mode_UNDERVOLTAGE_RESET)||\
                                                            ((__VALUE__) == FL_SVD_Mode_LOWVOLTAGE_WARNING))    

#define         IS_FL_SVD_GATE_CTRL(__VALUE__)             (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))
/**
  *@}
  */

/** @addtogroup SVD_FL_EF_Init
  * @{
  */

/**
  * @brief  复位SVD外设
  * @param  SVDx 外设入口地址
  * @retval 错误状态，可能值：
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_SVD_DeInit(SVD_Type *SVDx)
{
    FL_ErrorStatus status = FL_PASS;
    /* 入口参数合法性断言 */
    assert_param(IS_SVD_INSTANCE(SVDx));
    SVDx->CFGR  = 0x00000008U;
    SVDx->CR    = 0x00000000U;
    SVDx->IER   = 0x00000000U;
    SVDx->VSR   = 0x00000004U;
    return (status);
}

/**
  * @brief  配置SVD
  * @param  SVDx  外设入口地址
  * @param  initStruct 指向 @ref FL_SVD_InitTypeDef 结构体的指针
  *
  * @retval 错误状态，可能值：
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_SVD_Init(SVD_Type *SVDx, FL_SVD_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    /* 参数合法性检查 */
    assert_param(IS_SVD_INSTANCE(SVDx));
    assert_param(IS_FL_SVD_WARNING_THRESHOLD_LEVEL(initStruct->warningThreshold));
    assert_param(IS_FL_SVD_SVSCONFIG(initStruct->SVSChannel));
    assert_param(IS_FL_SVD_REFERENCE_VOLTAGE(initStruct->referenceVoltage));
    assert_param(IS_FL_SVD_DIGITAL_FILTER(initStruct->digitalFilter));
    assert_param(IS_FL_SVD_WORK_MODE(initStruct->workMode));
    assert_param(IS_FL_SVD_ENABLE_PERIOD(initStruct->enablePeriod));
    assert_param(IS_FL_SVD_FUNC_MODE(initStruct->funcMode));
    assert_param(IS_FL_SVD_GATE_CTRL(initStruct->gateCtrl));
    /* 使能工作时钟 */
    FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_SVD);
    /* 检测阈值 */
    FL_SVD_SetWarningThreshold(SVDx, initStruct->warningThreshold);
    /* 参考电压通道选择 */
    FL_SVD_EnableReference(SVD, initStruct->referenceVoltage);
    /* 外部通道配置 */
    if(initStruct->SVSChannel == FL_ENABLE)
    {
        FL_SVD_EnableSVSChannel(SVDx);
    }
    else
    {
        FL_SVD_DisableSVSChannel(SVDx);
    }
    /* 工作模式选择 */
    FL_SVD_SetWorkMode(SVD, initStruct->workMode);
    if(initStruct->workMode == FL_SVD_WORK_MODE_PERIODIC)
    {
        /* 间歇使能下，忽略配置强制打开数字滤波 */
        FL_SVD_EnableDigitalFilter(SVDx);
        /* 间歇使能间隔配置 */
        FL_SVD_SetEnablePeriod(SVD, initStruct->enablePeriod);
    }
    else
    {
        /* 数字滤波配置 */
        if(initStruct->digitalFilter == FL_ENABLE)
        {
            FL_SVD_EnableDigitalFilter(SVDx);
        }
        else
        {
            FL_SVD_DisableDigitalFilter(SVDx);
        }
    } 
    /* 功能模式配置 */
    if(initStruct->funcMode == FL_SVD_Mode_LOWVOLTAGE_WARNING)
    {
        FL_SVD_SetMode(SVDx, FL_SVD_Mode_LOWVOLTAGE_WARNING);
    }
    else if(initStruct->funcMode == FL_SVD_Mode_UNDERVOLTAGE_RESET)
    {
        FL_SVD_SetMode(SVDx, FL_SVD_Mode_UNDERVOLTAGE_RESET);
    }
    else
    {
        FL_SVD_SetMode(SVDx, FL_SVD_Mode_DISABLE);
    }
    /* 门控配置 */
    if(initStruct->gateCtrl == FL_ENABLE)
    {
         FL_SVD_EnableGATEn(SVDx);
    }
    else
    {
         FL_SVD_DisableGATEn(SVDx);
    }
    status = FL_PASS;
    return status;
}

/**
  * @brief  将 @ref FL_SVD_InitTypeDef 结构体初始化为默认配置
  * @param  initStruct 指向 @ref FL_SVD_InitTypeDef 结构体的指针
  *
  * @retval None
  */
void FL_SVD_StructInit(FL_SVD_InitTypeDef *initStruct)
{
    initStruct->SVSChannel          = FL_DISABLE;
    initStruct->digitalFilter       = FL_ENABLE;
    initStruct->referenceVoltage    = FL_SVD_REFERENCE_1P0V;
    initStruct->warningThreshold    = FL_SVD_WARNING_THRESHOLD_GROUP0;
    initStruct->workMode            = FL_SVD_WORK_MODE_CONTINUOUS;
    initStruct->enablePeriod        = FL_SVD_ENABLE_PERIOD_1000MS;
}

/**
  * @}
  */

#endif /* FL_SVD_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/

