 /**    
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_svd.h
  * @author  FMSH Application Team
  * @brief   Header file of FL Driver Library
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
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS”
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

/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33FH0XX_FL_SVD_H
#define __FM33FH0XX_FL_SVD_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl_def.h"
/** @addtogroup FM33FH0XX_FL_Driver
  * @{
  */

/** @defgroup SVD SVD
  * @brief SVD FL driver
  * @{
  */

/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup SVD_FL_ES_INIT SVD Exported Init structures
  * @{
  */

/**
  * @brief SVD Init Sturcture definition
  */
typedef struct
{
    /* 工作模式 */
    uint32_t workMode;
  
    /* 功能模式 */
    uint32_t funcMode;
  
    /* 门控 */
    uint32_t gateCtrl;
  
    /* 间歇使能间隔 */
    uint32_t enablePeriod;

    /* 参考电压 */
    uint32_t referenceVoltage;

    /* 报警阈值 */
    uint32_t warningThreshold;

    /* 数字滤波 */
    uint32_t digitalFilter;

    /* SVS通道选择 */
    uint32_t SVSChannel;

} FL_SVD_InitTypeDef;

/**
  * @}
  */

/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup SVD_FL_Exported_Constants SVD Exported Constants
  * @{
  */

#define    SVD_CFGR_LVL_Pos                                       (4U)
#define    SVD_CFGR_LVL_Msk                                       (0xfU << SVD_CFGR_LVL_Pos)
#define    SVD_CFGR_LVL                                           SVD_CFGR_LVL_Msk

#define    SVD_CFGR_DFEN_Pos                                      (3U)
#define    SVD_CFGR_DFEN_Msk                                      (0x1U << SVD_CFGR_DFEN_Pos)
#define    SVD_CFGR_DFEN                                          SVD_CFGR_DFEN_Msk

#define    SVD_CFGR_MOD_Pos                                       (2U)
#define    SVD_CFGR_MOD_Msk                                       (0x1U << SVD_CFGR_MOD_Pos)
#define    SVD_CFGR_MOD                                           SVD_CFGR_MOD_Msk

#define    SVD_CFGR_ITVL_Pos                                      (0U)
#define    SVD_CFGR_ITVL_Msk                                      (0x3U << SVD_CFGR_ITVL_Pos)
#define    SVD_CFGR_ITVL                                          SVD_CFGR_ITVL_Msk

#define    SVD_CR_TE_Pos                                          (8U)
#define    SVD_CR_TE_Msk                                          (0x1U << SVD_CR_TE_Pos)
#define    SVD_CR_TE                                              SVD_CR_TE_Msk

#define    SVD_CR_SVSEN_Pos                                       (2U)
#define    SVD_CR_SVSEN_Msk                                       (0x1U << SVD_CR_SVSEN_Pos)
#define    SVD_CR_SVSEN                                           SVD_CR_SVSEN_Msk

#define    SVD_CR_SVDEN_Pos                                       (0U)
#define    SVD_CR_SVDEN_Msk                                       (0x3U << SVD_CR_SVDEN_Pos)
#define    SVD_CR_SVDEN                                           SVD_CR_SVDEN_Msk

#define    SVD_IER_PFIE_Pos                                       (1U)
#define    SVD_IER_PFIE_Msk                                       (0x1U << SVD_IER_PFIE_Pos)
#define    SVD_IER_PFIE                                           SVD_IER_PFIE_Msk

#define    SVD_IER_PRIE_Pos                                       (0U)
#define    SVD_IER_PRIE_Msk                                       (0x1U << SVD_IER_PRIE_Pos)
#define    SVD_IER_PRIE                                           SVD_IER_PRIE_Msk

#define    SVD_ISR_SVDO_Pos                                       (8U)
#define    SVD_ISR_SVDO_Msk                                       (0x1U << SVD_ISR_SVDO_Pos)
#define    SVD_ISR_SVDO                                           SVD_ISR_SVDO_Msk

#define    SVD_ISR_SVDR_Pos                                       (7U)
#define    SVD_ISR_SVDR_Msk                                       (0x1U << SVD_ISR_SVDR_Pos)
#define    SVD_ISR_SVDR                                           SVD_ISR_SVDR_Msk

#define    SVD_ISR_PFF_Pos                                        (1U)
#define    SVD_ISR_PFF_Msk                                        (0x1U << SVD_ISR_PFF_Pos)
#define    SVD_ISR_PFF                                            SVD_ISR_PFF_Msk

#define    SVD_ISR_PRF_Pos                                        (0U)
#define    SVD_ISR_PRF_Msk                                        (0x1U << SVD_ISR_PRF_Pos)
#define    SVD_ISR_PRF                                             SVD_ISR_PRF_Msk

#define    SVD_VSR_EN_Pos                                         (0U)
#define    SVD_VSR_EN_Msk                                         (0x7U << SVD_VSR_EN_Pos)
#define    SVD_VSR_EN                                             SVD_VSR_EN_Msk



#define    FL_SVD_REFERENCE_1P0V                                  (0x1U << 2U)
#define    FL_SVD_REFERENCE_0P95V                                 (0x1U << 1U)
#define    FL_SVD_REFERENCE_0P9V                                  (0x1U << 0U)



#define    FL_SVD_WARNING_THRESHOLD_GROUP0                        (0x0U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP1                        (0x1U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP2                        (0x2U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP3                        (0x3U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP4                        (0x4U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP5                        (0x5U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP6                        (0x6U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP7                        (0x7U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP8                        (0x8U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP9                        (0x9U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP10                       (0xaU << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP11                       (0xbU << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP12                       (0xcU << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP13                       (0xdU << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP14                       (0xeU << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP15                       (0xfU << SVD_CFGR_LVL_Pos)


#define    FL_SVD_WORK_MODE_CONTINUOUS                            (0x0U << SVD_CFGR_MOD_Pos)
#define    FL_SVD_WORK_MODE_PERIODIC                              (0x1U << SVD_CFGR_MOD_Pos)


#define    FL_SVD_ENABLE_PERIOD_62P5MS                            (0x0U << SVD_CFGR_ITVL_Pos)
#define    FL_SVD_ENABLE_PERIOD_256MS                             (0x1U << SVD_CFGR_ITVL_Pos)
#define    FL_SVD_ENABLE_PERIOD_1000MS                            (0x2U << SVD_CFGR_ITVL_Pos)
#define    FL_SVD_ENABLE_PERIOD_4000MS                            (0x3U << SVD_CFGR_ITVL_Pos)


#define    FL_SVD_Mode_DISABLE                                    (0x0U << SVD_CR_SVDEN_Pos)
#define    FL_SVD_Mode_LOWVOLTAGE_WARNING                         (0x1U << SVD_CR_SVDEN_Pos)
#define    FL_SVD_Mode_UNDERVOLTAGE_RESET                         (0x2U << SVD_CR_SVDEN_Pos)


#define    FL_SVD_CR_DISABLE                                      (0x0U << SVD_CR_SVDEN_Pos)

#define    FL_SVD_POWER_STATUS_FALLING                            (0x0U << SVD_ISR_SVDO_Pos)
#define    FL_SVD_POWER_STATUS_RISING                             (0x1U << SVD_ISR_SVDO_Pos)

#define    FL_SVD_LATCHED_POWER_STATUS_FALLING                    (0x0U << SVD_ISR_SVDR_Pos)
#define    FL_SVD_LATCHED_POWER_STATUS_RISING                     (0x1U << SVD_ISR_SVDR_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup SVD_FL_Exported_Functions SVD Exported Functions
  * @{
  */

/**
  * @brief    Set SVD Threshold Warning Level
  * @rmtoll   CFGR    LVL    FL_SVD_SetWarningThreshold
  * @param    SVDx SVD instance
  * @param    level This parameter can be one of the following values:
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP0
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP1
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP2
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP3
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP4
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP5
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP6
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP7
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP8
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP9
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP10
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP11
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP12
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP13
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP14
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP15
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_SetWarningThreshold(SVD_Type* SVDx, uint32_t level)
{
    MODIFY_REG(SVDx->CFGR, SVD_CFGR_LVL_Msk, level);
}

/**
  * @brief    Get SVD Warning Threshold Level
  * @rmtoll   CFGR    LVL    FL_SVD_GetWarningThreshold
  * @param    SVDx SVD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP0
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP1
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP2
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP3
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP4
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP5
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP6
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP7
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP8
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP9
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP10
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP11
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP12
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP13
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP14
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP15
  */
__STATIC_INLINE uint32_t FL_SVD_GetWarningThreshold(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->CFGR, SVD_CFGR_LVL_Msk));
}

/**
  * @brief    Enable SVD Digital Filter
  * @rmtoll   CFGR    DFEN    FL_SVD_EnableDigitalFilter
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_EnableDigitalFilter(SVD_Type* SVDx)
{
    SET_BIT(SVDx->CFGR, SVD_CFGR_DFEN_Msk);
}

/**
  * @brief    Get SVD Digital Filter Enable Status
  * @rmtoll   CFGR    DFEN    FL_SVD_IsEnabledDigitalFilter
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SVD_IsEnabledDigitalFilter(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->CFGR, SVD_CFGR_DFEN_Msk) == SVD_CFGR_DFEN_Msk);
}

/**
  * @brief    Disable SVD Digital Filter
  * @rmtoll   CFGR    DFEN    FL_SVD_DisableDigitalFilter
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_DisableDigitalFilter(SVD_Type* SVDx)
{
    CLEAR_BIT(SVDx->CFGR, SVD_CFGR_DFEN_Msk);
}

/**
  * @brief    Set SVD Work Mode
  * @rmtoll   CFGR    MOD    FL_SVD_SetWorkMode
  * @param    SVDx SVD instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_SVD_WORK_MODE_CONTINUOUS
  *           @arg @ref FL_SVD_WORK_MODE_PERIODIC
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_SetWorkMode(SVD_Type* SVDx, uint32_t mode)
{
    MODIFY_REG(SVDx->CFGR, SVD_CFGR_MOD_Msk, mode);
}

/**
  * @brief    Get SVD Work Mode
  * @rmtoll   CFGR    MOD    FL_SVD_GetWorkMode
  * @param    SVDx SVD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SVD_WORK_MODE_CONTINUOUS
  *           @arg @ref FL_SVD_WORK_MODE_PERIODIC
  */
__STATIC_INLINE uint32_t FL_SVD_GetWorkMode(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->CFGR, SVD_CFGR_MOD_Msk));
}

/**
  * @brief    Set SVD Enable Period
  * @rmtoll   CFGR    ITVL    FL_SVD_SetEnablePeriod
  * @param    SVDx SVD instance
  * @param    period This parameter can be one of the following values:
  *           @arg @ref FL_SVD_ENABLE_PERIOD_62P5MS
  *           @arg @ref FL_SVD_ENABLE_PERIOD_256MS
  *           @arg @ref FL_SVD_ENABLE_PERIOD_1000MS
  *           @arg @ref FL_SVD_ENABLE_PERIOD_4000MS
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_SetEnablePeriod(SVD_Type* SVDx, uint32_t period)
{
    MODIFY_REG(SVDx->CFGR, SVD_CFGR_ITVL_Msk, period);
}

/**
  * @brief    Get SVD Work Interval
  * @rmtoll   CFGR    ITVL    FL_SVD_GetEnablePeriod
  * @param    SVDx SVD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SVD_ENABLE_PERIOD_62P5MS
  *           @arg @ref FL_SVD_ENABLE_PERIOD_256MS
  *           @arg @ref FL_SVD_ENABLE_PERIOD_1000MS
  *           @arg @ref FL_SVD_ENABLE_PERIOD_4000MS
  */
__STATIC_INLINE uint32_t FL_SVD_GetEnablePeriod(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->CFGR, SVD_CFGR_ITVL_Msk));
}

/**
  * @brief    Enable SVD GATEn
  * @rmtoll   CR    TE    FL_SVD_EnableGATEn
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_EnableGATEn(SVD_Type* SVDx)
{
    SET_BIT(SVDx->CR, SVD_CR_TE_Msk);
}

/**
  * @brief    Get SVD GATEn Enable Status
  * @rmtoll   CR    TE    FL_SVD_IsEnabledGATEn
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SVD_IsEnabledGATEn(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->CR, SVD_CR_TE_Msk) == SVD_CR_TE_Msk);
}

/**
  * @brief    Disable SVD GATEn
  * @rmtoll   CR    TE    FL_SVD_DisableGATEn
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_DisableGATEn(SVD_Type* SVDx)
{
    CLEAR_BIT(SVDx->CR, SVD_CR_TE_Msk);
}

/**
  * @brief    Enable External SVS Channel
  * @rmtoll   CR    SVSEN    FL_SVD_EnableSVSChannel
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_EnableSVSChannel(SVD_Type* SVDx)
{
    SET_BIT(SVDx->CR, SVD_CR_SVSEN_Msk);
}

/**
  * @brief    Get External SVS Channel Enable Status
  * @rmtoll   CR    SVSEN    FL_SVD_IsEnabledSVSChannel
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SVD_IsEnabledSVSChannel(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->CR, SVD_CR_SVSEN_Msk) == SVD_CR_SVSEN_Msk);
}

/**
  * @brief    Disable External SVS Channel
  * @rmtoll   CR    SVSEN    FL_SVD_DisableSVSChannel
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_DisableSVSChannel(SVD_Type* SVDx)
{
    CLEAR_BIT(SVDx->CR, SVD_CR_SVSEN_Msk);
}

/**
  * @brief    Set SVD Mode
  * @rmtoll   CR    SVDEN    FL_SVD_SetMode
  * @param    SVDx SVD instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_SVD_Mode_DISABLE
  *           @arg @ref FL_SVD_Mode_LOWVOLTAGE_WARNING
  *           @arg @ref FL_SVD_Mode_UNDERVOLTAGE_RESET
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_SetMode(SVD_Type* SVDx, uint32_t mode)
{
    MODIFY_REG(SVDx->CR, SVD_CR_SVDEN_Msk, mode);
}

/**
  * @brief    Get SVD Mode
  * @rmtoll   CR    SVDEN    FL_SVD_GetMode
  * @param    SVDx SVD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SVD_Mode_DISABLE
  *           @arg @ref FL_SVD_Mode_LOWVOLTAGE_WARNING
  *           @arg @ref FL_SVD_Mode_UNDERVOLTAGE_RESET
  */
__STATIC_INLINE uint32_t FL_SVD_GetMode(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->CR, SVD_CR_SVDEN_Msk));
}

/**
  * @brief    Disable SVD
  * @rmtoll   CR    SVDEN    FL_SVD_Disable
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_Disable(SVD_Type* SVDx)
{
    MODIFY_REG(SVDx->CR, SVD_CR_SVDEN_Msk, FL_SVD_CR_DISABLE);
}

/**
  * @brief    Enable Power Fall Interrupt
  * @rmtoll   IER    PFIE    FL_SVD_EnableIT_PowerFall
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_EnableIT_PowerFall(SVD_Type* SVDx)
{
    SET_BIT(SVDx->IER, SVD_IER_PFIE_Msk);
}

/**
  * @brief    Get Power Fall Interrupt Status
  * @rmtoll   IER    PFIE    FL_SVD_IsEnabledIT_PowerFall
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SVD_IsEnabledIT_PowerFall(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->IER, SVD_IER_PFIE_Msk) == SVD_IER_PFIE_Msk);
}

/**
  * @brief    Disable Power Fall Interrupt
  * @rmtoll   IER    PFIE    FL_SVD_DisableIT_PowerFall
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_DisableIT_PowerFall(SVD_Type* SVDx)
{
    CLEAR_BIT(SVDx->IER, SVD_IER_PFIE_Msk);
}

/**
  * @brief    Enable Power Rise Interrupt
  * @rmtoll   IER    PRIE    FL_SVD_EnableIT_PowerRise
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_EnableIT_PowerRise(SVD_Type* SVDx)
{
    SET_BIT(SVDx->IER, SVD_IER_PRIE_Msk);
}

/**
  * @brief    Get Power Rise  Interrupt Status
  * @rmtoll   IER    PRIE    FL_SVD_IsEnabledIT_PowerRise
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SVD_IsEnabledIT_PowerRise(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->IER, SVD_IER_PRIE_Msk) == SVD_IER_PRIE_Msk);
}

/**
  * @brief    Disable Power Rise Interrupt
  * @rmtoll   IER    PRIE    FL_SVD_DisableIT_PowerRise
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_DisableIT_PowerRise(SVD_Type* SVDx)
{
    CLEAR_BIT(SVDx->IER, SVD_IER_PRIE_Msk);
}

/**
  * @brief    Get SVD Current Power Status
  * @rmtoll   ISR    SVDO    FL_SVD_GetCurrentPowerStatus
  * @param    SVDx SVD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SVD_POWER_STATUS_FALLING
  *           @arg @ref FL_SVD_POWER_STATUS_RISING
  */
__STATIC_INLINE uint32_t FL_SVD_GetCurrentPowerStatus(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->ISR, SVD_ISR_SVDO_Msk));
}

/**
  * @brief    Get SVD Latched Power Status
  * @rmtoll   ISR    SVDR    FL_SVD_GetLatchedPowerStatus
  * @param    SVDx SVD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SVD_LATCHED_POWER_STATUS_FALLING
  *           @arg @ref FL_SVD_LATCHED_POWER_STATUS_RISING
  */
__STATIC_INLINE uint32_t FL_SVD_GetLatchedPowerStatus(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->ISR, SVD_ISR_SVDR_Msk));
}

/**
  * @brief    Get SVD Power Fall Flag
  * @rmtoll   ISR    PFF    FL_SVD_IsActiveFlag_PowerFall
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SVD_IsActiveFlag_PowerFall(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->ISR, SVD_ISR_PFF_Msk) == (SVD_ISR_PFF_Msk));
}

/**
  * @brief    Clear SVD Power Fall Flag
  * @rmtoll   ISR    PFF    FL_SVD_ClearFlag_PowerFall
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_ClearFlag_PowerFall(SVD_Type* SVDx)
{
    WRITE_REG(SVDx->ISR, SVD_ISR_PFF_Msk);
}

/**
  * @brief    Get SVD Power Rise Flag
  * @rmtoll   SVD_ISR    PRF    FL_SVD_IsActiveFlag_PowerRise
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SVD_IsActiveFlag_PowerRise(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->ISR, SVD_ISR_PRF_Msk) == (SVD_ISR_PRF_Msk));
}

/**
  * @brief    Clear SVD Power Rise Flag
  * @rmtoll   ISR    PRF    FL_SVD_ClearFlag_PowerRise
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_ClearFlag_PowerRise(SVD_Type* SVDx)
{
    WRITE_REG(SVDx->ISR, SVD_ISR_PRF_Msk);
}

/**
  * @brief    Enable SVD Reference
  * @rmtoll   VSR    EN    FL_SVD_EnableReference
  * @param    SVDx SVD instance
  * @param    ref This parameter can be one of the following values:
  *           @arg @ref FL_SVD_REFERENCE_1P0V
  *           @arg @ref FL_SVD_REFERENCE_0P95V
  *           @arg @ref FL_SVD_REFERENCE_0P9V
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_EnableReference(SVD_Type* SVDx, uint32_t ref)
{
    SET_BIT(SVDx->VSR, ((ref & 0x7) << 0x0U));
}

/**
  * @brief    Get SVD Reference Enable Status
  * @rmtoll   VSR    EN    FL_SVD_IsEnabledReference
  * @param    SVDx SVD instance
  * @param    ref This parameter can be one of the following values:
  *           @arg @ref FL_SVD_REFERENCE_1P0V
  *           @arg @ref FL_SVD_REFERENCE_0P95V
  *           @arg @ref FL_SVD_REFERENCE_0P9V
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SVD_IsEnabledReference(SVD_Type* SVDx, uint32_t ref)
{
    return (uint32_t)(READ_BIT(SVDx->VSR, ((ref & 0x7) << 0x0U)) == ((ref & 0x7) << 0x0U));
}

/**
  * @brief    Disable SVD Reference
  * @rmtoll   VSR    EN    FL_SVD_DisableReference
  * @param    SVDx SVD instance
  * @param    ref This parameter can be one of the following values:
  *           @arg @ref FL_SVD_REFERENCE_1P0V
  *           @arg @ref FL_SVD_REFERENCE_0P95V
  *           @arg @ref FL_SVD_REFERENCE_0P9V
  * @retval   None
  */
__STATIC_INLINE void FL_SVD_DisableReference(SVD_Type* SVDx, uint32_t ref)
{
    CLEAR_BIT(SVDx->VSR, ((ref & 0x7) << 0x0U));
}


/**
  * @}
  */

/** @defgroup SVD_FL_EF_Init Initialization and de-initialization functions
  * @{
  */

FL_ErrorStatus FL_SVD_DeInit(SVD_Type *SVDx);
FL_ErrorStatus FL_SVD_Init(SVD_Type *SVDx, FL_SVD_InitTypeDef *initStruct);
void FL_SVD_StructInit(FL_SVD_InitTypeDef *initStruct);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_SVD_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2024-01-03*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
