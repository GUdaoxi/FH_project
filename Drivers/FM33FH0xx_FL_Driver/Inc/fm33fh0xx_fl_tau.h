/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_tau.h
  * @author  FMSH Application Team
  * @brief   Head file of TAU FL Module
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


/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33FH0XX_FL_TAU_H
#define __FM33FH0XX_FL_TAU_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl_def.h"
/** @addtogroup FM33FH0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup TAU_FL_ES_INIT TAU Exported Init structures
  * @{
  */

/**
  * @brief FL TAU Timer Unit Sturcture definition
  */
typedef const struct
{
    uint32_t timerId;
    __IO uint32_t * CR;
    __IO uint32_t * CFGR;
    __IO uint32_t * MDR;
    __IO uint32_t * ARR;
    __IO uint32_t * CCR;
    __IO uint32_t * IER;
    __IO uint32_t * ISR;
    __I  uint32_t * CNTR;

} TAU_Type;

/**
  * @brief FL TAU Init Sturcture definition
  */

typedef struct
{
    /** 工作模式 */
    uint32_t mode;

    /** 级联模式 */
    uint32_t cascadeMode;

    /** 级联从机工作模式 */
    uint32_t slaveMode;

    /** 级联从机触发输入源 */
    uint32_t slaveTriggerSource;

    /** 计数源 */
    uint32_t counterSource;

    /** 计数边沿 */
    uint32_t countEdge;

    /** 预分频 */
    uint32_t prescaler;

    /** 预装载 */
    uint32_t autoReload;

    /** 比较值 */
    uint32_t compare;

    /** 输出比较极性 */
    uint32_t outputPolarity;

    /** 输入捕获模式 */
    uint32_t captureMode;

    /** 输入捕获源 */
    uint32_t captureSource;

    /** 输入捕获边沿 */
    uint32_t captureEdge;

    /** 输入捕获预分频 */
    uint32_t capturePrescaler;

    /** 是否使用单次捕捉 */
    FL_FunState useOneShotCapture;

    /** 是否使用滤波器 */
    FL_FunState useCaptureFilter;

} FL_TAU_InitTypeDef;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup TAU_FL_Exported_Constants TAU Exported Constants
  * @{
  */


/**
  * @brief FL TAU0 Timer Units
  */
extern TAU_Type *const TAU00;
extern TAU_Type *const TAU01;
extern TAU_Type *const TAU02;
extern TAU_Type *const TAU03;
extern TAU_Type *const TAU04;
extern TAU_Type *const TAU05;
extern TAU_Type *const TAU06;
extern TAU_Type *const TAU07; 


/**
  * @brief FL TAU1 Timer Units
  */
extern TAU_Type *const TAU10;
extern TAU_Type *const TAU11;
extern TAU_Type *const TAU12;
extern TAU_Type *const TAU13;
extern TAU_Type *const TAU14;
extern TAU_Type *const TAU15;
extern TAU_Type *const TAU16;
extern TAU_Type *const TAU17;


/**
  * @brief FL TAU Timer Unit Enable/Disable Control Registers Defines
  */
extern __IO uint32_t *const * const TAU_CR;


#define    TAU_CR_EN_Pos                                          (0U)
#define    TAU_CR_EN_Msk                                          (0xffU << TAU_CR_EN_Pos)
#define    TAU_CR_EN                                              TAU_CR_EN_Msk

#define    TAU_CFGR_CAPCLR_Pos                                    (30U)
#define    TAU_CFGR_CAPCLR_Msk                                    (0x1U << TAU_CFGR_CAPCLR_Pos)
#define    TAU_CFGR_CAPCLR                                        TAU_CFGR_CAPCLR_Msk

#define    TAU_CFGR_CAPONCE_Pos                                   (29U)
#define    TAU_CFGR_CAPONCE_Msk                                   (0x1U << TAU_CFGR_CAPONCE_Pos)
#define    TAU_CFGR_CAPONCE                                       TAU_CFGR_CAPONCE_Msk

#define    TAU_CFGR_NF_Pos                                        (28U)
#define    TAU_CFGR_NF_Msk                                        (0x1U << TAU_CFGR_NF_Pos)
#define    TAU_CFGR_NF                                            TAU_CFGR_NF_Msk

#define    TAU_CFGR_CAPEDGE_Pos                                   (26U)
#define    TAU_CFGR_CAPEDGE_Msk                                   (0x3U << TAU_CFGR_CAPEDGE_Pos)
#define    TAU_CFGR_CAPEDGE                                       TAU_CFGR_CAPEDGE_Msk

#define    TAU_CFGR_CNTEDGE_Pos                                   (24U)
#define    TAU_CFGR_CNTEDGE_Msk                                   (0x3U << TAU_CFGR_CNTEDGE_Pos)
#define    TAU_CFGR_CNTEDGE                                       TAU_CFGR_CNTEDGE_Msk

#define    TAU_CFGR_PRESCALE1_Pos                                 (16U)
#define    TAU_CFGR_PRESCALE1_Msk                                 (0xffU << TAU_CFGR_PRESCALE1_Pos)
#define    TAU_CFGR_PRESCALE1                                     TAU_CFGR_PRESCALE1_Msk

#define    TAU_CFGR_PRESCALE2_Pos                                 (8U)
#define    TAU_CFGR_PRESCALE2_Msk                                 (0xffU << TAU_CFGR_PRESCALE2_Pos)
#define    TAU_CFGR_PRESCALE2                                     TAU_CFGR_PRESCALE2_Msk

#define    TAU_CFGR_OPOL_Pos                                      (7U)
#define    TAU_CFGR_OPOL_Msk                                      (0x1U << TAU_CFGR_OPOL_Pos)
#define    TAU_CFGR_OPOL                                          TAU_CFGR_OPOL_Msk

#define    TAU_CFGR_TS_Pos                                        (5U)
#define    TAU_CFGR_TS_Msk                                        (0x3U << TAU_CFGR_TS_Pos)
#define    TAU_CFGR_TS                                            TAU_CFGR_TS_Msk

#define    TAU_CFGR_CAPSEL_Pos                                    (2U)
#define    TAU_CFGR_CAPSEL_Msk                                    (0x7U << TAU_CFGR_CAPSEL_Pos)
#define    TAU_CFGR_CAPSEL                                        TAU_CFGR_CAPSEL_Msk

#define    TAU_CFGR_CNTSEL_Pos                                    (0U)
#define    TAU_CFGR_CNTSEL_Msk                                    (0x3U << TAU_CFGR_CNTSEL_Pos)
#define    TAU_CFGR_CNTSEL                                        TAU_CFGR_CNTSEL_Msk

#define    TAU_MDR_SLVMD_Pos                                      (4U)
#define    TAU_MDR_SLVMD_Msk                                      (0x1U << TAU_MDR_SLVMD_Pos)
#define    TAU_MDR_SLVMD                                          TAU_MDR_SLVMD_Msk

#define    TAU_MDR_TOEN_Pos                                       (3U)
#define    TAU_MDR_TOEN_Msk                                       (0x1U << TAU_MDR_TOEN_Pos)
#define    TAU_MDR_TOEN                                           TAU_MDR_TOEN_Msk

#define    TAU_MDR_SLV_Pos                                        (2U)
#define    TAU_MDR_SLV_Msk                                        (0x1U << TAU_MDR_SLV_Pos)
#define    TAU_MDR_SLV                                            TAU_MDR_SLV_Msk

#define    TAU_MDR_MD_Pos                                         (0U)
#define    TAU_MDR_MD_Msk                                         (0x3U << TAU_MDR_MD_Pos)
#define    TAU_MDR_MD                                             TAU_MDR_MD_Msk

#define    TAU_IER_CMPIE_Pos                                      (2U)
#define    TAU_IER_CMPIE_Msk                                      (0x1U << TAU_IER_CMPIE_Pos)
#define    TAU_IER_CMPIE                                          TAU_IER_CMPIE_Msk

#define    TAU_IER_CAPIE_Pos                                      (1U)
#define    TAU_IER_CAPIE_Msk                                      (0x1U << TAU_IER_CAPIE_Pos)
#define    TAU_IER_CAPIE                                          TAU_IER_CAPIE_Msk

#define    TAU_IER_OVIE_Pos                                       (0U)
#define    TAU_IER_OVIE_Msk                                       (0x1U << TAU_IER_OVIE_Pos)
#define    TAU_IER_OVIE                                           TAU_IER_OVIE_Msk

#define    TAU_ISR_EDGESTA_Pos                                    (3U)
#define    TAU_ISR_EDGESTA_Msk                                    (0x1U << TAU_ISR_EDGESTA_Pos)
#define    TAU_ISR_EDGESTA                                        TAU_ISR_EDGESTA_Msk

#define    TAU_ISR_CMPIF_Pos                                      (2U)
#define    TAU_ISR_CMPIF_Msk                                      (0x1U << TAU_ISR_CMPIF_Pos)
#define    TAU_ISR_CMPIF                                          TAU_ISR_CMPIF_Msk

#define    TAU_ISR_CAPIF_Pos                                      (1U)
#define    TAU_ISR_CAPIF_Msk                                      (0x1U << TAU_ISR_CAPIF_Pos)
#define    TAU_ISR_CAPIF                                          TAU_ISR_CAPIF_Msk

#define    TAU_ISR_OVIF_Pos                                       (0U)
#define    TAU_ISR_OVIF_Msk                                       (0x1U << TAU_ISR_OVIF_Pos)
#define    TAU_ISR_OVIF                                           TAU_ISR_OVIF_Msk



#define    FL_TAU_TIMER0                                          (0x1U << 0U)
#define    FL_TAU_TIMER1                                          (0x1U << 1U)
#define    FL_TAU_TIMER2                                          (0x1U << 2U)
#define    FL_TAU_TIMER3                                          (0x1U << 3U)
#define    FL_TAU_TIMER4                                          (0x1U << 4U)
#define    FL_TAU_TIMER5                                          (0x1U << 5U)
#define    FL_TAU_TIMER6                                          (0x1U << 6U)
#define    FL_TAU_TIMER7                                          (0x1U << 7U)

#define    FL_TAU_GROUP0                                          0x0U
#define    FL_TAU_GROUP1                                          0x1U

#define    FL_TAU_CASCADE_MODE_DISABLE                            (0x0U << 0U)
#define    FL_TAU_CASCADE_MODE_MASTER                             (0x1U << 0U)
#define    FL_TAU_CASCADE_MODE_SLAVE                              (0x2U << 0U)



#define    FL_TAU_IC_MODE_NORMAL                                  (0x0U << TAU_CFGR_CAPCLR_Pos)
#define    FL_TAU_IC_MODE_RESET                                   (0x1U << TAU_CFGR_CAPCLR_Pos)


#define    FL_TAU_IC_EDGE_BOTH                                    (0x0U << TAU_CFGR_CAPEDGE_Pos)
#define    FL_TAU_IC_EDGE_RISING                                  (0x1U << TAU_CFGR_CAPEDGE_Pos)
#define    FL_TAU_IC_EDGE_FALLING                                 (0x2U << TAU_CFGR_CAPEDGE_Pos)


#define    FL_TAU_COUNTER_EDGE_BOTH                               (0x0U << TAU_CFGR_CNTEDGE_Pos)
#define    FL_TAU_COUNTER_EDGE_RISING                             (0x1U << TAU_CFGR_CNTEDGE_Pos)
#define    FL_TAU_COUNTER_EDGE_FALLING                            (0x2U << TAU_CFGR_CNTEDGE_Pos)


#define    FL_TAU_OC_POLARITY_NORMAL                              (0x0U << TAU_CFGR_OPOL_Pos)
#define    FL_TAU_OC_POLARITY_INVERT                              (0x1U << TAU_CFGR_OPOL_Pos)


#define    FL_TAU_TRGI_GROUP0                                     (0x0U << TAU_CFGR_TS_Pos)
#define    FL_TAU_TRGI_GROUP1                                     (0x1U << TAU_CFGR_TS_Pos)
#define    FL_TAU_TRGI_GROUP2                                     (0x2U << TAU_CFGR_TS_Pos)
#define    FL_TAU_TRGI_GROUP3                                     (0x3U << TAU_CFGR_TS_Pos)


#define    FL_TAU_IC_SOURCE_GROUP0                                (0x0U << TAU_CFGR_CAPSEL_Pos)
#define    FL_TAU_IC_SOURCE_GROUP1                                (0x1U << TAU_CFGR_CAPSEL_Pos)
#define    FL_TAU_IC_SOURCE_GROUP2                                (0x2U << TAU_CFGR_CAPSEL_Pos)
#define    FL_TAU_IC_SOURCE_GROUP3                                (0x3U << TAU_CFGR_CAPSEL_Pos)
#define    FL_TAU_IC_SOURCE_GROUP4                                (0x4U << TAU_CFGR_CAPSEL_Pos)
#define    FL_TAU_IC_SOURCE_GROUP5                                (0x5U << TAU_CFGR_CAPSEL_Pos)
#define    FL_TAU_IC_SOURCE_GROUP6                                (0x6U << TAU_CFGR_CAPSEL_Pos)
#define    FL_TAU_IC_SOURCE_GROUP7                                (0x7U << TAU_CFGR_CAPSEL_Pos)


#define    FL_TAU_COUNTER_SOURCE_INTERNAL                         (0x0U << TAU_CFGR_CNTSEL_Pos)
#define    FL_TAU_COUNTER_SOURCE_EXTERNAL                         (0x1U << TAU_CFGR_CNTSEL_Pos)
#define    FL_TAU_COUNTER_SOURCE_CAPTURE_INPUT                    (0x2U << TAU_CFGR_CNTSEL_Pos)


#define    FL_TAU_SLAVE_MODE_TRIG_CNT                             (0x0U << TAU_MDR_SLVMD_Pos)
#define    FL_TAU_SLAVE_MODE_TRIG_START                           (0x1U << TAU_MDR_SLVMD_Pos)


#define    FL_TAU_OPERATION_MODE_NORMAL                           (0x0U << TAU_MDR_MD_Pos)
#define    FL_TAU_OPERATION_MODE_OC                               (0x1U << TAU_MDR_MD_Pos)
#define    FL_TAU_OPERATION_MODE_IC_PERIOD                        (0x2U << TAU_MDR_MD_Pos)
#define    FL_TAU_OPERATION_MODE_IC_WIDTH                         (0x3U << TAU_MDR_MD_Pos)


#define    FL_TAU_IC_CAPTURED_EDGE_RISING                         (0x0U << TAU_ISR_EDGESTA_Pos)
#define    FL_TAU_IC_CAPTURED_EDGE_FALLING                        (0x1U << TAU_ISR_EDGESTA_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup TAU_FL_Exported_Functions TAU Exported Functions
  * @{
  */

/**
  * @brief    Enable TAU Module
  * @rmtoll   CR    EN    FL_TAU_Enable
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_Enable(TAU_Type* TAUxy)
{
    SET_BIT(*TAUxy->CR, TAUxy->timerId); 
}

/**
  * @brief    Get TAU Module Enable Status
  * @rmtoll   CR    EN    FL_TAU_IsEnabled
  * @param    TAUxy TAUy instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_TAU_IsEnabled(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->CR, TAUxy->timerId) == TAUxy->timerId); 
}

/**
  * @brief    Disabled TAU Module
  * @rmtoll   CR    EN    FL_TAU_Disable
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_Disable(TAU_Type* TAUxy)
{
    CLEAR_BIT(*TAUxy->CR, TAUxy->timerId); 
}

/**
  * @brief    Enable TAU Module by ID
  * @rmtoll   CR    EN    FL_TAU_EnableById
  * @param    groupId This parameter can be one of the following values:
  *           @arg @ref FL_TAU_GROUP0
  *           @arg @ref FL_TAU_GROUP1
  * @param    timerId This parameter can be one of the following values:
  *           @arg @ref FL_TAU_TIMER0
  *           @arg @ref FL_TAU_TIMER1
  *           @arg @ref FL_TAU_TIMER2
  *           @arg @ref FL_TAU_TIMER3
  *           @arg @ref FL_TAU_TIMER4
  *           @arg @ref FL_TAU_TIMER5
  *           @arg @ref FL_TAU_TIMER6
  *           @arg @ref FL_TAU_TIMER7
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_EnableById(uint32_t groupId, uint32_t timerId)
{
    SET_BIT(*TAU_CR[groupId], timerId); 
}

/**
  * @brief    Disable TAU Module by ID
  * @rmtoll   CR    EN    FL_TAU_DisableById
  * @param    groupId This parameter can be one of the following values:
  *           @arg @ref FL_TAU_GROUP0
  *           @arg @ref FL_TAU_GROUP1
  * @param    timerId This parameter can be one of the following values:
  *           @arg @ref FL_TAU_TIMER0
  *           @arg @ref FL_TAU_TIMER1
  *           @arg @ref FL_TAU_TIMER2
  *           @arg @ref FL_TAU_TIMER3
  *           @arg @ref FL_TAU_TIMER4
  *           @arg @ref FL_TAU_TIMER5
  *           @arg @ref FL_TAU_TIMER6
  *           @arg @ref FL_TAU_TIMER7
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_DisableById(uint32_t groupId, uint32_t timerId)
{
    CLEAR_BIT(*TAU_CR[groupId], timerId); 
}

/**
  * @brief    Set Input Capture Mode - Free or Reset
  * @rmtoll   CFGR    CAPCLR    FL_TAU_IC_SetMode
  * @param    TAUxy TAUy instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_TAU_IC_MODE_NORMAL
  *           @arg @ref FL_TAU_IC_MODE_RESET
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_IC_SetMode(TAU_Type* TAUxy, uint32_t mode)
{
    MODIFY_REG(*TAUxy->CFGR, TAU_CFGR_CAPCLR_Msk, mode);
}

/**
  * @brief    Get Input Capture Mode - Free or Reset
  * @rmtoll   CFGR    CAPCLR    FL_TAU_IC_GetMode
  * @param    TAUxy TAUy instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_TAU_IC_MODE_NORMAL
  *           @arg @ref FL_TAU_IC_MODE_RESET
  */
__STATIC_INLINE uint32_t FL_TAU_IC_GetMode(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->CFGR, TAU_CFGR_CAPCLR_Msk));
}

/**
  * @brief    Enable Input Capture One-Shot Mode
  * @rmtoll   CFGR    CAPONCE    FL_TAU_IC_EnableOneShot
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_IC_EnableOneShot(TAU_Type* TAUxy)
{
    SET_BIT(*TAUxy->CFGR, TAU_CFGR_CAPONCE_Msk);
}

/**
  * @brief    Get  Input Capture One-Shot Mode Enable State
  * @rmtoll   CFGR    CAPONCE    FL_TAU_IC_IsEnabledOneShot
  * @param    TAUxy TAUy instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_TAU_IC_IsEnabledOneShot(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->CFGR, TAU_CFGR_CAPONCE_Msk) == TAU_CFGR_CAPONCE_Msk);
}

/**
  * @brief    Disable Input Capture One-Shot Mode
  * @note     Defaults to Continuous Mode when One-Shot Mode is turned off
  * @rmtoll   CFGR    CAPONCE    FL_TAU_IC_DisableOneShot
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_IC_DisableOneShot(TAU_Type* TAUxy)
{
    CLEAR_BIT(*TAUxy->CFGR, TAU_CFGR_CAPONCE_Msk);
}

/**
  * @brief    Enable Input Capture Digital Filtering
  * @rmtoll   CFGR    NF    FL_TAU_IC_EnableFilter
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_IC_EnableFilter(TAU_Type* TAUxy)
{
    SET_BIT(*TAUxy->CFGR, TAU_CFGR_NF_Msk);
}

/**
  * @brief    Get Input Capture Digital Filter Enable State
  * @rmtoll   CFGR    NF    FL_TAU_IC_IsEnabledFilter
  * @param    TAUxy TAUy instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_TAU_IC_IsEnabledFilter(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->CFGR, TAU_CFGR_NF_Msk) == TAU_CFGR_NF_Msk);
}

/**
  * @brief    Disable Input Capture Digital Filtering
  * @rmtoll   CFGR    NF    FL_TAU_IC_DisableFilter
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_IC_DisableFilter(TAU_Type* TAUxy)
{
    CLEAR_BIT(*TAUxy->CFGR, TAU_CFGR_NF_Msk);
}

/**
  * @brief    Set the Trigger Edge of Input Capture Source
  * @rmtoll   CFGR    CAPEDGE    FL_TAU_IC_SetCaptureEdge
  * @param    TAUxy TAUy instance
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref FL_TAU_IC_EDGE_BOTH
  *           @arg @ref FL_TAU_IC_EDGE_RISING
  *           @arg @ref FL_TAU_IC_EDGE_FALLING
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_IC_SetCaptureEdge(TAU_Type* TAUxy, uint32_t edge)
{
    MODIFY_REG(*TAUxy->CFGR, TAU_CFGR_CAPEDGE_Msk, edge);
}

/**
  * @brief    Get the Trigger Edge Setting of Input Capture Source
  * @rmtoll   CFGR    CAPEDGE    FL_TAU_IC_GetCaptureEdge
  * @param    TAUxy TAUy instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_TAU_IC_EDGE_BOTH
  *           @arg @ref FL_TAU_IC_EDGE_RISING
  *           @arg @ref FL_TAU_IC_EDGE_FALLING
  */
__STATIC_INLINE uint32_t FL_TAU_IC_GetCaptureEdge(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->CFGR, TAU_CFGR_CAPEDGE_Msk));
}

/**
  * @brief    Set the Trigger Edge of Count Source
  * @rmtoll   CFGR    CNTEDGE    FL_TAU_SetCounterEdge
  * @param    TAUxy TAUy instance
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref FL_TAU_COUNTER_EDGE_BOTH
  *           @arg @ref FL_TAU_COUNTER_EDGE_RISING
  *           @arg @ref FL_TAU_COUNTER_EDGE_FALLING
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_SetCounterEdge(TAU_Type* TAUxy, uint32_t edge)
{
    MODIFY_REG(*TAUxy->CFGR, TAU_CFGR_CNTEDGE_Msk, edge);
}

/**
  * @brief    Get the Trigger Edge Setting of Count Source
  * @rmtoll   CFGR    CNTEDGE    FL_TAU_GetCounterEdge
  * @param    TAUxy TAUy instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_TAU_COUNTER_EDGE_BOTH
  *           @arg @ref FL_TAU_COUNTER_EDGE_RISING
  *           @arg @ref FL_TAU_COUNTER_EDGE_FALLING
  */
__STATIC_INLINE uint32_t FL_TAU_GetCounterEdge(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->CFGR, TAU_CFGR_CNTEDGE_Msk));
}

/**
  * @brief    Write the Prescaler Value of the Count Source
  * @note     PSC1 = PRESCALE1 + 1
  * @rmtoll   CFGR    PRESCALE1    FL_TAU_WritePrescaler
  * @param    TAUxy TAUy instance
  * @param    psc 
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_WritePrescaler(TAU_Type* TAUxy, uint32_t psc)
{
    MODIFY_REG(*TAUxy->CFGR, (0xffU << 16U), (psc << 16U));
}

/**
  * @brief    Read the Prescaler Value of the Count Source
  * @note     PSC1 = PRESCALE1 + 1
  * @rmtoll   CFGR    PRESCALE1    FL_TAU_ReadPrescaler
  * @param    TAUxy TAUy instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_TAU_ReadPrescaler(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->CFGR, (0xffU << 16U)) >> 16U);
}

/**
  * @brief    Write the Prescaler Value of the Input Capture Source
  * @note     PSC2 = PRESCALE2 + 1
  * @rmtoll   CFGR    PRESCALE2    FL_TAU_IC_WritePrescaler
  * @param    TAUxy TAUy instance
  * @param    psc 
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_IC_WritePrescaler(TAU_Type* TAUxy, uint32_t psc)
{
    MODIFY_REG(*TAUxy->CFGR, (0xffU << 8U), (psc << 8U));
}

/**
  * @brief    Read the Prescaler Value of the Input Capture Source
  * @note     PSC2 = PRESCALE2 + 1
  * @rmtoll   CFGR    PRESCALE2    FL_TAU_IC_ReadPrescaler
  * @param    TAUxy TAUy instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_TAU_IC_ReadPrescaler(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->CFGR, (0xffU << 8U)) >> 8U);
}

/**
  * @brief    Set the Polarity of Output Compare
  * @rmtoll   CFGR    OPOL    FL_TAU_OC_SetPolarity
  * @param    TAUxy TAUy instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_TAU_OC_POLARITY_NORMAL
  *           @arg @ref FL_TAU_OC_POLARITY_INVERT
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_OC_SetPolarity(TAU_Type* TAUxy, uint32_t polarity)
{
    MODIFY_REG(*TAUxy->CFGR, TAU_CFGR_OPOL_Msk, polarity);
}

/**
  * @brief    Get the Polarity Setting  of Output Compare
  * @rmtoll   CFGR    OPOL    FL_TAU_OC_GetPolarity
  * @param    TAUxy TAUy instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_TAU_OC_POLARITY_NORMAL
  *           @arg @ref FL_TAU_OC_POLARITY_INVERT
  */
__STATIC_INLINE uint32_t FL_TAU_OC_GetPolarity(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->CFGR, TAU_CFGR_OPOL_Msk));
}

/**
  * @brief    Set the Trigger Source of Slave
  * @rmtoll   CFGR    TS    FL_TAU_SetTriggerSource
  * @param    TAUxy TAUy instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_TAU_TRGI_GROUP0
  *           @arg @ref FL_TAU_TRGI_GROUP1
  *           @arg @ref FL_TAU_TRGI_GROUP2
  *           @arg @ref FL_TAU_TRGI_GROUP3
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_SetTriggerSource(TAU_Type* TAUxy, uint32_t source)
{
    MODIFY_REG(*TAUxy->CFGR, TAU_CFGR_TS_Msk, source);
}

/**
  * @brief    Get the Trigger Source Setting of Slave
  * @rmtoll   CFGR    TS    FL_TAU_GetTriggerSource
  * @param    TAUxy TAUy instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_TAU_TRGI_GROUP0
  *           @arg @ref FL_TAU_TRGI_GROUP1
  *           @arg @ref FL_TAU_TRGI_GROUP2
  *           @arg @ref FL_TAU_TRGI_GROUP3
  */
__STATIC_INLINE uint32_t FL_TAU_GetTriggerSource(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->CFGR, TAU_CFGR_TS_Msk));
}

/**
  * @brief    Set the Signal Source of Input Capture
  * @rmtoll   CFGR    CAPSEL    FL_TAU_IC_SetSource
  * @param    TAUxy TAUy instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP0
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP1
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP2
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP3
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP4
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP5
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP6
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP7
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_IC_SetSource(TAU_Type* TAUxy, uint32_t source)
{
    MODIFY_REG(*TAUxy->CFGR, TAU_CFGR_CAPSEL_Msk, source);
}

/**
  * @brief    Get the Signal Source Setting of Input Capture 
  * @rmtoll   CFGR    CAPSEL    FL_TAU_IC_GetSource
  * @param    TAUxy TAUy instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP0
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP1
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP2
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP3
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP4
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP5
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP6
  *           @arg @ref FL_TAU_IC_SOURCE_GROUP7
  */
__STATIC_INLINE uint32_t FL_TAU_IC_GetSource(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->CFGR, TAU_CFGR_CAPSEL_Msk));
}

/**
  * @brief    Set the Signal Source of Count
  * @rmtoll   CFGR    CNTSEL    FL_TAU_SetCounterSource
  * @param    TAUxy TAUy instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_TAU_COUNTER_SOURCE_INTERNAL
  *           @arg @ref FL_TAU_COUNTER_SOURCE_EXTERNAL
  *           @arg @ref FL_TAU_COUNTER_SOURCE_CAPTURE_INPUT
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_SetCounterSource(TAU_Type* TAUxy, uint32_t source)
{
    MODIFY_REG(*TAUxy->CFGR, TAU_CFGR_CNTSEL_Msk, source);
}

/**
  * @brief    Get the Signal Source Setting of Count
  * @rmtoll   CFGR    CNTSEL    FL_TAU_GetCounterSource
  * @param    TAUxy TAUy instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_TAU_COUNTER_SOURCE_INTERNAL
  *           @arg @ref FL_TAU_COUNTER_SOURCE_EXTERNAL
  *           @arg @ref FL_TAU_COUNTER_SOURCE_CAPTURE_INPUT
  */
__STATIC_INLINE uint32_t FL_TAU_GetCounterSource(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->CFGR, TAU_CFGR_CNTSEL_Msk));
}

/**
  * @brief    Set the Mode of Slave
  * @rmtoll   MDR    SLVMD    FL_TAU_SetSlaveMode
  * @param    TAUxy TAUy instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_TAU_SLAVE_MODE_TRIG_CNT
  *           @arg @ref FL_TAU_SLAVE_MODE_TRIG_START
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_SetSlaveMode(TAU_Type* TAUxy, uint32_t mode)
{
    MODIFY_REG(*TAUxy->MDR, TAU_MDR_SLVMD_Msk, mode);
}

/**
  * @brief    Get the Mode Setting of Slave
  * @rmtoll   MDR    SLVMD    FL_TAU_GetSlaveMode
  * @param    TAUxy TAUy instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_TAU_SLAVE_MODE_TRIG_CNT
  *           @arg @ref FL_TAU_SLAVE_MODE_TRIG_START
  */
__STATIC_INLINE uint32_t FL_TAU_GetSlaveMode(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->MDR, TAU_MDR_SLVMD_Msk));
}

/**
  * @brief    Enable Compare Output
  * @rmtoll   MDR    TOEN    FL_TAU_EnableOutput
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_EnableOutput(TAU_Type* TAUxy)
{
    SET_BIT(*TAUxy->MDR, TAU_MDR_TOEN_Msk);
}

/**
  * @brief    Get Compare Output Enable Status
  * @rmtoll   MDR    TOEN    FL_TAU_IsEnabledOutput
  * @param    TAUxy TAUy instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_TAU_IsEnabledOutput(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->MDR, TAU_MDR_TOEN_Msk) == TAU_MDR_TOEN_Msk);
}

/**
  * @brief    Disable Compare Output
  * @rmtoll   MDR    TOEN    FL_TAU_DisableOutput
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_DisableOutput(TAU_Type* TAUxy)
{
    CLEAR_BIT(*TAUxy->MDR, TAU_MDR_TOEN_Msk);
}

/**
  * @brief    Enable Slave Mode
  * @rmtoll   MDR    SLV    FL_TAU_EnableSlaveMode
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_EnableSlaveMode(TAU_Type* TAUxy)
{
    SET_BIT(*TAUxy->MDR, TAU_MDR_SLV_Msk);
}

/**
  * @brief    Get Slave Mode Enable Status
  * @rmtoll   MDR    SLV    FL_TAU_IsEnabledSlaveMode
  * @param    TAUxy TAUy instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_TAU_IsEnabledSlaveMode(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->MDR, TAU_MDR_SLV_Msk) == TAU_MDR_SLV_Msk);
}

/**
  * @brief    Disable Slave Mode
  * @note     Defaults to MasterMode when SlaveMode is turned off
  * @rmtoll   MDR    SLV    FL_TAU_DisableSlaveMode
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_DisableSlaveMode(TAU_Type* TAUxy)
{
    CLEAR_BIT(*TAUxy->MDR, TAU_MDR_SLV_Msk);
}

/**
  * @brief    Set Operation Mode
  * @note     The NormalMode is the CountingMode
  * @rmtoll   MDR    MD    FL_TAU_SetOperationMode
  * @param    TAUxy TAUy instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_TAU_OPERATION_MODE_NORMAL
  *           @arg @ref FL_TAU_OPERATION_MODE_OC
  *           @arg @ref FL_TAU_OPERATION_MODE_IC_PERIOD
  *           @arg @ref FL_TAU_OPERATION_MODE_IC_WIDTH
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_SetOperationMode(TAU_Type* TAUxy, uint32_t mode)
{
    MODIFY_REG(*TAUxy->MDR, TAU_MDR_MD_Msk, mode);
}

/**
  * @brief    Get Operation Mode Setting
  * @note     The NormalMode is the Counting mode
  * @rmtoll   MDR    MD    FL_TAU_GetOperationMode
  * @param    TAUxy TAUy instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_TAU_OPERATION_MODE_NORMAL
  *           @arg @ref FL_TAU_OPERATION_MODE_OC
  *           @arg @ref FL_TAU_OPERATION_MODE_IC_PERIOD
  *           @arg @ref FL_TAU_OPERATION_MODE_IC_WIDTH
  */
__STATIC_INLINE uint32_t FL_TAU_GetOperationMode(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->MDR, TAU_MDR_MD_Msk));
}

/**
  * @brief    Enable Compare Interrupt
  * @rmtoll   IER    CMPIE    FL_TAU_EnableIT_OC
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_EnableIT_OC(TAU_Type* TAUxy)
{
    SET_BIT(*TAUxy->IER, TAU_IER_CMPIE_Msk);
}

/**
  * @brief    Get Compare Interrupt Enable Status
  * @rmtoll   IER    CMPIE    FL_TAU_IsEnabledIT_OC
  * @param    TAUxy TAUy instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_TAU_IsEnabledIT_OC(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->IER, TAU_IER_CMPIE_Msk) == TAU_IER_CMPIE_Msk);
}

/**
  * @brief    Disable Compare Interrupt
  * @rmtoll   IER    CMPIE    FL_TAU_DisableIT_OC
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_DisableIT_OC(TAU_Type* TAUxy)
{
    CLEAR_BIT(*TAUxy->IER, TAU_IER_CMPIE_Msk);
}

/**
  * @brief    Enable Input Capture Interrupt
  * @rmtoll   IER    CAPIE    FL_TAU_EnableIT_IC
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_EnableIT_IC(TAU_Type* TAUxy)
{
    SET_BIT(*TAUxy->IER, TAU_IER_CAPIE_Msk);
}

/**
  * @brief    Get Input Capture Interrupt Enable Status
  * @rmtoll   IER    CAPIE    FL_TAU_IsEnabledIT_IC
  * @param    TAUxy TAUy instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_TAU_IsEnabledIT_IC(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->IER, TAU_IER_CAPIE_Msk) == TAU_IER_CAPIE_Msk);
}

/**
  * @brief    Disable Input Capture Interrupt
  * @rmtoll   IER    CAPIE    FL_TAU_DisableIT_IC
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_DisableIT_IC(TAU_Type* TAUxy)
{
    CLEAR_BIT(*TAUxy->IER, TAU_IER_CAPIE_Msk);
}

/**
  * @brief    Enable Overflow Interrupt
  * @rmtoll   IER    OVIE    FL_TAU_EnableIT_Update
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_EnableIT_Update(TAU_Type* TAUxy)
{
    SET_BIT(*TAUxy->IER, TAU_IER_OVIE_Msk);
}

/**
  * @brief    Get Overflow Interrupt Enable Status
  * @rmtoll   IER    OVIE    FL_TAU_IsEnabledIT_Update
  * @param    TAUxy TAUy instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_TAU_IsEnabledIT_Update(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->IER, TAU_IER_OVIE_Msk) == TAU_IER_OVIE_Msk);
}

/**
  * @brief    Disable Overflow Interrupt
  * @rmtoll   IER    OVIE    FL_TAU_DisableIT_Update
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_DisableIT_Update(TAU_Type* TAUxy)
{
    CLEAR_BIT(*TAUxy->IER, TAU_IER_OVIE_Msk);
}

/**
  * @brief    Get the Edge Status of Input Capture
  * @rmtoll   ISR    EDGESTA    FL_TAU_IC_GetCapturedEdge
  * @param    TAUxy TAUy instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_TAU_IC_CAPTURED_EDGE_RISING
  *           @arg @ref FL_TAU_IC_CAPTURED_EDGE_FALLING
  */
__STATIC_INLINE uint32_t FL_TAU_IC_GetCapturedEdge(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->ISR, TAU_ISR_EDGESTA_Msk));
}

/**
  * @brief    Clear the Edge Status of Input Capture
  * @rmtoll   ISR    EDGESTA    FL_TAU_IC_ClearFlag_CapturedEdge
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_IC_ClearFlag_CapturedEdge(TAU_Type* TAUxy)
{
    WRITE_REG(*TAUxy->ISR, TAU_ISR_EDGESTA_Msk);
}

/**
  * @brief    Get the Compare Interrupt Flag
  * @rmtoll   ISR    CMPIF    FL_TAU_IsActiveFlag_OC
  * @param    TAUxy TAUy instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_TAU_IsActiveFlag_OC(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->ISR, TAU_ISR_CMPIF_Msk) == (TAU_ISR_CMPIF_Msk));
}

/**
  * @brief    Clear the Compare Interrupt Flag
  * @rmtoll   ISR    CMPIF    FL_TAU_ClearFlag_OC
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_ClearFlag_OC(TAU_Type* TAUxy)
{
    WRITE_REG(*TAUxy->ISR, TAU_ISR_CMPIF_Msk);
}

/**
  * @brief    Get the Input Capture Interrupt Flag
  * @rmtoll   ISR    CAPIF    FL_TAU_IsActiveFlag_IC
  * @param    TAUxy TAUy instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_TAU_IsActiveFlag_IC(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->ISR, TAU_ISR_CAPIF_Msk) == (TAU_ISR_CAPIF_Msk));
}

/**
  * @brief    Clear the Input Capture Interrupt Flag
  * @rmtoll   ISR    CAPIF    FL_TAU_ClearFlag_IC
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_ClearFlag_IC(TAU_Type* TAUxy)
{
    WRITE_REG(*TAUxy->ISR, TAU_ISR_CAPIF_Msk);
}

/**
  * @brief    Get the Overflow Interrupt Flag
  * @rmtoll   ISR    OVIF    FL_TAU_IsActiveFlag_Update
  * @param    TAUxy TAUy instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_TAU_IsActiveFlag_Update(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->ISR, TAU_ISR_OVIF_Msk) == (TAU_ISR_OVIF_Msk));
}

/**
  * @brief    Clear the Overflow Interrupt Flag
  * @rmtoll   ISR    OVIF    FL_TAU_ClearFlag_Update
  * @param    TAUxy TAUy instance
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_ClearFlag_Update(TAU_Type* TAUxy)
{
    WRITE_REG(*TAUxy->ISR, TAU_ISR_OVIF_Msk);
}

/**
  * @brief    Read CNT Register Value
  * @rmtoll   CNTR        FL_TAU_ReadCounter
  * @param    TAUxy TAUy instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_TAU_ReadCounter(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->CNTR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Write Auto-Overload Value
  * @rmtoll   ARR        FL_TAU_WriteAutoReload
  * @param    TAUxy TAUy instance
  * @param    autoReload 
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_WriteAutoReload(TAU_Type* TAUxy, uint32_t autoReload)
{
    MODIFY_REG(*TAUxy->ARR, (0xffffU << 0U), (autoReload << 0U));
}

/**
  * @brief    Read Auto-Overload Value
  * @rmtoll   ARR        FL_TAU_ReadAutoReload
  * @param    TAUxy TAUy instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_TAU_ReadAutoReload(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->ARR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Write Compare Value
  * @rmtoll   CCR        FL_TAU_WriteCompare
  * @param    TAUxy TAUy instance
  * @param    compare 
  * @retval   None
  */
__STATIC_INLINE void FL_TAU_WriteCompare(TAU_Type* TAUxy, uint32_t compare)
{
    MODIFY_REG(*TAUxy->CCR, (0xffffU << 0U), (compare << 0U));
}

/**
  * @brief    Read Compare Value
  * @rmtoll   CCR        FL_TAU_ReadCompare
  * @param    TAUxy TAUy instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_TAU_ReadCompare(TAU_Type* TAUxy)
{
    return (uint32_t)(READ_BIT(*TAUxy->CCR, (0xffffU << 0U)) >> 0U);
}

/**
  * @}
  */

/** @defgroup TAU_FL_EF_Init Initialization and de-initialization functions
  * @{
  */

FL_ErrorStatus FL_TAU_Init(TAU_Type *TAUxy, FL_TAU_InitTypeDef *initStruct);
FL_ErrorStatus FL_TAU_DeInit(TAU_Type *TAUxy);
void FL_TAU_StructInit(FL_TAU_InitTypeDef *initStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_TAU_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2024-01-15*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
