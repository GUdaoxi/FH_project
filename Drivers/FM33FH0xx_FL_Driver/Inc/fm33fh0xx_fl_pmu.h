/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_pmu.h
  * @author  FMSH Application Team
  * @brief   Head file of PMU FL Module
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


/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33FH0XX_FL_PMU_H
#define __FM33FH0XX_FL_PMU_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl_def.h"
/** @addtogroup FM33FH0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup PMU_FL_ES_INIT PMU Exported Init structures
  * @{
  */

/**
  * @brief FL PMU Init Sturcture definition
  */
typedef struct
{
    /* 低功耗模式配置 */
    uint32_t powerMode;

    /* 睡眠模式配置 */
    uint32_t deepSleep;

    /* 唤醒后的系统频率，仅对RCHF */
    uint32_t wakeupFrequency;

    /* 唤醒后Stop释放控制 */
    uint32_t stopReleaseMode;
    
    /* 额外唤醒延迟 T2B */
    uint32_t wakeupDelayT2b;

    /* 额外唤醒延迟 T2A*/
    uint32_t wakeupDelayT2a;    
    
    /* 额外唤醒延迟 */
    uint32_t wakeupDelayT1a;

} FL_PMU_SleepInitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup PMU_FL_Exported_Constants PMU Exported Constants
  * @{
  */

#define    PMU_CR_AVREF_SH_Pos                                    (24U)
#define    PMU_CR_AVREF_SH_Msk                                    (0x3U << PMU_CR_AVREF_SH_Pos)
#define    PMU_CR_AVREF_SH                                        PMU_CR_AVREF_SH_Msk

#define    PMU_CR_WKFSEL_Pos                                      (10U)
#define    PMU_CR_WKFSEL_Msk                                      (0x3U << PMU_CR_WKFSEL_Pos)
#define    PMU_CR_WKFSEL                                          PMU_CR_WKFSEL_Msk

#define    PMU_CR_SLPDP_Pos                                       (9U)
#define    PMU_CR_SLPDP_Msk                                       (0x1U << PMU_CR_SLPDP_Pos)
#define    PMU_CR_SLPDP                                           PMU_CR_SLPDP_Msk

#define    PMU_CR_PMOD_Pos                                        (0U)
#define    PMU_CR_PMOD_Msk                                        (0x3U << PMU_CR_PMOD_Pos)
#define    PMU_CR_PMOD                                            PMU_CR_PMOD_Msk

#define    PMU_WKTR_T2B_Pos                                       (6U)
#define    PMU_WKTR_T2B_Msk                                       (0x3U << PMU_WKTR_T2B_Pos)
#define    PMU_WKTR_T2B                                           PMU_WKTR_T2B_Msk

#define    PMU_WKTR_T2A_Pos                                       (4U)
#define    PMU_WKTR_T2A_Msk                                       (0x3U << PMU_WKTR_T2A_Pos)
#define    PMU_WKTR_T2A                                           PMU_WKTR_T2A_Msk

#define    PMU_WKTR_STPCLR_Pos                                    (2U)
#define    PMU_WKTR_STPCLR_Msk                                    (0x1U << PMU_WKTR_STPCLR_Pos)
#define    PMU_WKTR_STPCLR                                        PMU_WKTR_STPCLR_Msk

#define    PMU_WKTR_T1A_Pos                                       (0U)
#define    PMU_WKTR_T1A_Msk                                       (0x3U << PMU_WKTR_T1A_Pos)
#define    PMU_WKTR_T1A                                           PMU_WKTR_T1A_Msk

#define    PMU_WKFR_UART2WKF_Pos                                  (31U)
#define    PMU_WKFR_UART2WKF_Msk                                  (0x1U << PMU_WKFR_UART2WKF_Pos)
#define    PMU_WKFR_UART2WKF                                      PMU_WKFR_UART2WKF_Msk

#define    PMU_WKFR_UART1WKF_Pos                                  (30U)
#define    PMU_WKFR_UART1WKF_Msk                                  (0x1U << PMU_WKFR_UART1WKF_Pos)
#define    PMU_WKFR_UART1WKF                                      PMU_WKFR_UART1WKF_Msk

#define    PMU_WKFR_UART0WKF_Pos                                  (29U)
#define    PMU_WKFR_UART0WKF_Msk                                  (0x1U << PMU_WKFR_UART0WKF_Pos)
#define    PMU_WKFR_UART0WKF                                      PMU_WKFR_UART0WKF_Msk

#define    PMU_WKFR_RTCWKF_Pos                                    (28U)
#define    PMU_WKFR_RTCWKF_Msk                                    (0x1U << PMU_WKFR_RTCWKF_Pos)
#define    PMU_WKFR_RTCWKF                                        PMU_WKFR_RTCWKF_Msk

#define    PMU_WKFR_SVDWKF_Pos                                    (27U)
#define    PMU_WKFR_SVDWKF_Msk                                    (0x1U << PMU_WKFR_SVDWKF_Pos)
#define    PMU_WKFR_SVDWKF                                        PMU_WKFR_SVDWKF_Msk

#define    PMU_WKFR_LFDETWKF_Pos                                  (26U)
#define    PMU_WKFR_LFDETWKF_Msk                                  (0x1U << PMU_WKFR_LFDETWKF_Pos)
#define    PMU_WKFR_LFDETWKF                                      PMU_WKFR_LFDETWKF_Msk

#define    PMU_WKFR_UART3WKF_Pos                                  (25U)
#define    PMU_WKFR_UART3WKF_Msk                                  (0x1U << PMU_WKFR_UART3WKF_Pos)
#define    PMU_WKFR_UART3WKF                                      PMU_WKFR_UART3WKF_Msk

#define    PMU_WKFR_IOWKF_Pos                                     (24U)
#define    PMU_WKFR_IOWKF_Msk                                     (0x1U << PMU_WKFR_IOWKF_Pos)
#define    PMU_WKFR_IOWKF                                         PMU_WKFR_IOWKF_Msk

#define    PMU_WKFR_IIC1WKF_Pos                                   (23U)
#define    PMU_WKFR_IIC1WKF_Msk                                   (0x1U << PMU_WKFR_IIC1WKF_Pos)
#define    PMU_WKFR_IIC1WKF                                       PMU_WKFR_IIC1WKF_Msk

#define    PMU_WKFR_IIC0WKF_Pos                                   (22U)
#define    PMU_WKFR_IIC0WKF_Msk                                   (0x1U << PMU_WKFR_IIC0WKF_Pos)
#define    PMU_WKFR_IIC0WKF                                       PMU_WKFR_IIC0WKF_Msk

#define    PMU_WKFR_UART5WKF_Pos                                  (21U)
#define    PMU_WKFR_UART5WKF_Msk                                  (0x1U << PMU_WKFR_UART5WKF_Pos)
#define    PMU_WKFR_UART5WKF                                      PMU_WKFR_UART5WKF_Msk

#define    PMU_WKFR_UART4WKF_Pos                                  (20U)
#define    PMU_WKFR_UART4WKF_Msk                                  (0x1U << PMU_WKFR_UART4WKF_Pos)
#define    PMU_WKFR_UART4WKF                                      PMU_WKFR_UART4WKF_Msk

#define    PMU_WKFR_LPU0WKF_Pos                                   (19U)
#define    PMU_WKFR_LPU0WKF_Msk                                   (0x1U << PMU_WKFR_LPU0WKF_Pos)
#define    PMU_WKFR_LPU0WKF                                       PMU_WKFR_LPU0WKF_Msk

#define    PMU_WKFR_UART7WKF_Pos                                  (18U)
#define    PMU_WKFR_UART7WKF_Msk                                  (0x1U << PMU_WKFR_UART7WKF_Pos)
#define    PMU_WKFR_UART7WKF                                      PMU_WKFR_UART7WKF_Msk

#define    PMU_WKFR_COMPWKF_Pos                                   (16U)
#define    PMU_WKFR_COMPWKF_Msk                                   (0x1U << PMU_WKFR_COMPWKF_Pos)
#define    PMU_WKFR_COMPWKF                                       PMU_WKFR_COMPWKF_Msk

#define    PMU_WKFR_UART6WKF_Pos                                  (15U)
#define    PMU_WKFR_UART6WKF_Msk                                  (0x1U << PMU_WKFR_UART6WKF_Pos)
#define    PMU_WKFR_UART6WKF                                      PMU_WKFR_UART6WKF_Msk

#define    PMU_WKFR_FDCANWKF_Pos                                  (14U)
#define    PMU_WKFR_FDCANWKF_Msk                                  (0x1U << PMU_WKFR_FDCANWKF_Pos)
#define    PMU_WKFR_FDCANWKF                                      PMU_WKFR_FDCANWKF_Msk

#define    PMU_WKFR_LPT16WKF_Pos                                  (12U)
#define    PMU_WKFR_LPT16WKF_Msk                                  (0x1U << PMU_WKFR_LPT16WKF_Pos)
#define    PMU_WKFR_LPT16WKF                                      PMU_WKFR_LPT16WKF_Msk

#define    PMU_WKFR_BST16WKF_Pos                                  (10U)
#define    PMU_WKFR_BST16WKF_Msk                                  (0x1U << PMU_WKFR_BST16WKF_Pos)
#define    PMU_WKFR_BST16WKF                                      PMU_WKFR_BST16WKF_Msk

#define    PMU_WKFR_DBGWKF_Pos                                    (9U)
#define    PMU_WKFR_DBGWKF_Msk                                    (0x1U << PMU_WKFR_DBGWKF_Pos)
#define    PMU_WKFR_DBGWKF                                        PMU_WKFR_DBGWKF_Msk

#define    PMU_WKFR_WKPXF_Pos                                     (0U)
#define    PMU_WKFR_WKPXF_Msk                                     (0xffU << PMU_WKFR_WKPXF_Pos)
#define    PMU_WKFR_WKPXF                                         PMU_WKFR_WKPXF_Msk

#define    PMU_IER_LPREIE_Pos                                     (0U)
#define    PMU_IER_LPREIE_Msk                                     (0x1U << PMU_IER_LPREIE_Pos)
#define    PMU_IER_LPREIE                                         PMU_IER_LPREIE_Msk

#define    PMU_ISR_LPREIF_Pos                                     (0U)
#define    PMU_ISR_LPREIF_Msk                                     (0x1U << PMU_ISR_LPREIF_Pos)
#define    PMU_ISR_LPREIF                                         PMU_ISR_LPREIF_Msk

#define    PMU_BUFCR_AVREFBUF_OUTEN_Pos                           (5U)
#define    PMU_BUFCR_AVREFBUF_OUTEN_Msk                           (0x1U << PMU_BUFCR_AVREFBUF_OUTEN_Pos)
#define    PMU_BUFCR_AVREFBUF_OUTEN                               PMU_BUFCR_AVREFBUF_OUTEN_Msk

#define    PMU_BUFCR_AVREFBUF_EN_Pos                              (4U)
#define    PMU_BUFCR_AVREFBUF_EN_Msk                              (0x1U << PMU_BUFCR_AVREFBUF_EN_Pos)
#define    PMU_BUFCR_AVREFBUF_EN                                  PMU_BUFCR_AVREFBUF_EN_Msk

#define    PMU_BUFCR_VPTATBUFFER_OUTEN_Pos                        (3U)
#define    PMU_BUFCR_VPTATBUFFER_OUTEN_Msk                        (0x1U << PMU_BUFCR_VPTATBUFFER_OUTEN_Pos)
#define    PMU_BUFCR_VPTATBUFFER_OUTEN                            PMU_BUFCR_VPTATBUFFER_OUTEN_Msk

#define    PMU_BUFCR_VPTATBUFFER_EN_Pos                           (2U)
#define    PMU_BUFCR_VPTATBUFFER_EN_Msk                           (0x1U << PMU_BUFCR_VPTATBUFFER_EN_Pos)
#define    PMU_BUFCR_VPTATBUFFER_EN                               PMU_BUFCR_VPTATBUFFER_EN_Msk

#define    PMU_PTATCR_PTAT_EN_Pos                                 (0U)
#define    PMU_PTATCR_PTAT_EN_Msk                                 (0x1U << PMU_PTATCR_PTAT_EN_Pos)
#define    PMU_PTATCR_PTAT_EN                                     PMU_PTATCR_PTAT_EN_Msk



#define    FL_PMU_WAKEUP0_PIN                                     (0x1U << 0U)
#define    FL_PMU_WAKEUP1_PIN                                     (0x1U << 1U)
#define    FL_PMU_WAKEUP2_PIN                                     (0x1U << 2U)
#define    FL_PMU_WAKEUP3_PIN                                     (0x1U << 3U)
#define    FL_PMU_WAKEUP4_PIN                                     (0x1U << 4U)
#define    FL_PMU_WAKEUP5_PIN                                     (0x1U << 5U)
#define    FL_PMU_WAKEUP6_PIN                                     (0x1U << 6U)
#define    FL_PMU_WAKEUP7_PIN                                     (0x1U << 7U)



#define    FL_PMU_AVERF_SAMPLE_HOLD_2MS                           (0x0U << PMU_CR_AVREF_SH_Pos)
#define    FL_PMU_AVERF_SAMPLE_HOLD_4MS                           (0x1U << PMU_CR_AVREF_SH_Pos)
#define    FL_PMU_AVERF_SAMPLE_HOLD_8MS                           (0x2U << PMU_CR_AVREF_SH_Pos)
#define    FL_PMU_AVERF_SAMPLE_HOLD_16MS                          (0x3U << PMU_CR_AVREF_SH_Pos)


#define    FL_PMU_RCHF_WAKEUP_FREQ_8MHZ                           (0x0U << PMU_CR_WKFSEL_Pos)
#define    FL_PMU_RCHF_WAKEUP_FREQ_16MHZ                          (0x1U << PMU_CR_WKFSEL_Pos)
#define    FL_PMU_RCHF_WAKEUP_FREQ_24MHZ                          (0x2U << PMU_CR_WKFSEL_Pos)


#define    FL_PMU_SLEEP_MODE_DEEP                                 (0x1U << PMU_CR_SLPDP_Pos)
#define    FL_PMU_SLEEP_MODE_NORMAL                               (0x0U << PMU_CR_SLPDP_Pos)


#define    FL_PMU_POWER_MODE_ACTIVE_OR_LPACTIVE                   (0x0U << PMU_CR_PMOD_Pos)
#define    FL_PMU_POWER_MODE_LPRUN_ONLY                           (0x1U << PMU_CR_PMOD_Pos)
#define    FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP                   (0x2U << PMU_CR_PMOD_Pos)

#define    FL_PMU_WAKEUP_DELAY_T2B_48US                           (0x0U << PMU_WKTR_T2B_Pos)
#define    FL_PMU_WAKEUP_DELAY_T2B_64US                           (0x1U << PMU_WKTR_T2B_Pos)
#define    FL_PMU_WAKEUP_DELAY_T2B_80US                           (0x2U << PMU_WKTR_T2B_Pos)
#define    FL_PMU_WAKEUP_DELAY_T2B_96US                           (0x3U << PMU_WKTR_T2B_Pos)


#define    FL_PMU_WAKEUP_DELAY_T2A_48US                           (0x0U << PMU_WKTR_T2A_Pos)
#define    FL_PMU_WAKEUP_DELAY_T2A_64US                           (0x1U << PMU_WKTR_T2A_Pos)
#define    FL_PMU_WAKEUP_DELAY_T2A_80US                           (0x2U << PMU_WKTR_T2A_Pos)
#define    FL_PMU_WAKEUP_DELAY_T2A_96US                           (0x3U << PMU_WKTR_T2A_Pos)


#define    FL_PMU_STOP_RELEASE_SYNC                               (0x0U << PMU_WKTR_STPCLR_Pos)
#define    FL_PMU_STOP_RELEASE_ASYNC                              (0x1U << PMU_WKTR_STPCLR_Pos)


#define    FL_PMU_WAKEUP_DELAY_T1A_48US                           (0x0U << PMU_WKTR_T1A_Pos)
#define    FL_PMU_WAKEUP_DELAY_T1A_64US                           (0x1U << PMU_WKTR_T1A_Pos)
#define    FL_PMU_WAKEUP_DELAY_T1A_80US                           (0x2U << PMU_WKTR_T1A_Pos)
#define    FL_PMU_WAKEUP_DELAY_T1A_96US                           (0x3U << PMU_WKTR_T1A_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup PMU_FL_Exported_Functions PMU Exported Functions
  * @{
  */

/**
  * @brief    Set AVREF Sample-Hold Period
  * @rmtoll   CR    AVREF_SH    FL_PMU_SetSampleHoldPeriod
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_AVERF_SAMPLE_HOLD_2MS
  *           @arg @ref FL_PMU_AVERF_SAMPLE_HOLD_4MS
  *           @arg @ref FL_PMU_AVERF_SAMPLE_HOLD_8MS
  *           @arg @ref FL_PMU_AVERF_SAMPLE_HOLD_16MS
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetSampleHoldPeriod(PMU_Type* PMUx, uint32_t mode)
{
    MODIFY_REG(PMUx->CR, PMU_CR_AVREF_SH_Msk, mode);
}

/**
  * @brief    Get AVREF Sample-Hold Period
  * @rmtoll   CR    AVREF_SH    FL_PMU_GetSampleHoldPeriod
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_AVERF_SAMPLE_HOLD_2MS
  *           @arg @ref FL_PMU_AVERF_SAMPLE_HOLD_4MS
  *           @arg @ref FL_PMU_AVERF_SAMPLE_HOLD_8MS
  *           @arg @ref FL_PMU_AVERF_SAMPLE_HOLD_16MS
  */
__STATIC_INLINE uint32_t FL_PMU_GetSampleHoldPeriod(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CR, PMU_CR_AVREF_SH_Msk));
}

/**
  * @brief    Set RCHF Frequency After Wakeup
  * @rmtoll   CR    WKFSEL    FL_PMU_SetRCHFWakeupFrequency
  * @param    PMUx PMU instance
  * @param    Freq This parameter can be one of the following values:
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_8MHZ
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_16MHZ
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_24MHZ
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetRCHFWakeupFrequency(PMU_Type* PMUx, uint32_t Freq)
{
    MODIFY_REG(PMUx->CR, PMU_CR_WKFSEL_Msk, Freq);
}

/**
  * @brief    Get RCHF Frequency After Wakeup Setting
  * @rmtoll   CR    WKFSEL    FL_PMU_GetRCHFWakeupFrequency
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_8MHZ
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_16MHZ
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_24MHZ
  */
__STATIC_INLINE uint32_t FL_PMU_GetRCHFWakeupFrequency(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CR, PMU_CR_WKFSEL_Msk));
}

/**
  * @brief    Set Sleep Mode
  * @rmtoll   CR    SLPDP    FL_PMU_SetSleepMode
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_SLEEP_MODE_DEEP
  *           @arg @ref FL_PMU_SLEEP_MODE_NORMAL
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetSleepMode(PMU_Type* PMUx, uint32_t mode)
{
    MODIFY_REG(PMUx->CR, PMU_CR_SLPDP_Msk, mode);
}

/**
  * @brief    Get Sleep Mode Setting
  * @rmtoll   CR    SLPDP    FL_PMU_GetSleepMode
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_SLEEP_MODE_DEEP
  *           @arg @ref FL_PMU_SLEEP_MODE_NORMAL
  */
__STATIC_INLINE uint32_t FL_PMU_GetSleepMode(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CR, PMU_CR_SLPDP_Msk));
}

/**
  * @brief    Set Low Power Mode
  * @rmtoll   CR    PMOD    FL_PMU_SetLowPowerMode
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_POWER_MODE_ACTIVE_OR_LPACTIVE
  *           @arg @ref FL_PMU_POWER_MODE_LPRUN_ONLY
  *           @arg @ref FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetLowPowerMode(PMU_Type* PMUx, uint32_t mode)
{
    MODIFY_REG(PMUx->CR, PMU_CR_PMOD_Msk, mode);
}

/**
  * @brief    Get Low Power Mode Setting
  * @rmtoll   CR    PMOD    FL_PMU_GetLowPowerMode
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_PMU_GetLowPowerMode(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CR, PMU_CR_PMOD_Msk));
}

/**
  * @brief    Set Extra T2B Wakeup Delay Under DeepSleep Mode
  * @rmtoll   WKTR    T2B    FL_PMU_SetT2BWakeupDelay
  * @param    PMUx PMU instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2B_48US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2B_64US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2B_80US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2B_96US
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetT2BWakeupDelay(PMU_Type* PMUx, uint32_t time)
{
    MODIFY_REG(PMUx->WKTR, PMU_WKTR_T2B_Msk, time);
}

/**
  * @brief    Get Extra  T2B Wakeup Delay Under DeepSleep Mode 
  * @rmtoll   WKTR    T2B    FL_PMU_GetT2BWakeupDelay
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2B_48US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2B_64US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2B_80US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2B_96US
  */
__STATIC_INLINE uint32_t FL_PMU_GetT2BWakeupDelay(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKTR, PMU_WKTR_T2B_Msk));
}

/**
  * @brief    Set Extra T2A Wakeup Delay Under DeepSleep Mode
  * @rmtoll   WKTR    T2A    FL_PMU_SetT2AWakeupDelay
  * @param    PMUx PMU instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2A_48US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2A_64US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2A_80US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2A_96US
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetT2AWakeupDelay(PMU_Type* PMUx, uint32_t time)
{
    MODIFY_REG(PMUx->WKTR, PMU_WKTR_T2A_Msk, time);
}

/**
  * @brief    Get Extra T2A Wakeup Delay Under DeepSleep Mode 
  * @rmtoll   WKTR    T2A    FL_PMU_GetT2AWakeupDelay
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2A_48US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2A_64US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2A_80US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T2A_96US
  */
__STATIC_INLINE uint32_t FL_PMU_GetT2AWakeupDelay(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKTR, PMU_WKTR_T2A_Msk));
}

/**
  * @brief    Set Stop Release Mode After Sleep
  * @rmtoll   WKTR    STPCLR    FL_PMU_SetStopReleaseMode
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_STOP_RELEASE_SYNC
  *           @arg @ref FL_PMU_STOP_RELEASE_ASYNC
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetStopReleaseMode(PMU_Type* PMUx, uint32_t mode)
{
    MODIFY_REG(PMUx->WKTR, PMU_WKTR_STPCLR_Msk, mode);
}

/**
  * @brief    Get Stop Release Mode After Sleep
  * @rmtoll   WKTR    STPCLR    FL_PMU_GetStopReleaseMode
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_STOP_RELEASE_SYNC
  *           @arg @ref FL_PMU_STOP_RELEASE_ASYNC
  */
__STATIC_INLINE uint32_t FL_PMU_GetStopReleaseMode(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKTR, PMU_WKTR_STPCLR_Msk));
}

/**
  * @brief    Set Extra Wakeup Delay Under Sleep/DeepSleep Mode
  * @rmtoll   WKTR    T1A    FL_PMU_SetT1AWakeupDelay
  * @param    PMUx PMU instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T1A_48US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T1A_64US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T1A_80US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T1A_96US
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetT1AWakeupDelay(PMU_Type* PMUx, uint32_t time)
{
    MODIFY_REG(PMUx->WKTR, PMU_WKTR_T1A_Msk, time);
}

/**
  * @brief    Get Extra Wakeup Delay Under Sleep/DeepSleep Mode Setting
  * @rmtoll   WKTR    T1A    FL_PMU_GetT1AWakeupDelay
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T1A_48US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T1A_64US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T1A_80US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_T1A_96US
  */
__STATIC_INLINE uint32_t FL_PMU_GetT1AWakeupDelay(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKTR, PMU_WKTR_T1A_Msk));
}

/**
  * @brief    Get UART2 interrupt wakeup flag
  * @rmtoll   WKFR    UART2WKF    FL_PMU_IsActiveFlag_WakeupUART2
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART2(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_UART2WKF_Msk) == (PMU_WKFR_UART2WKF_Msk));
}

/**
  * @brief    Get UART1 interrupt wakeup flag
  * @rmtoll   WKFR    UART1WKF    FL_PMU_IsActiveFlag_WakeupUART1
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART1(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_UART1WKF_Msk) == (PMU_WKFR_UART1WKF_Msk));
}

/**
  * @brief    Get UART0 interrupt wakeup flag
  * @rmtoll   WKFR    UART0WKF    FL_PMU_IsActiveFlag_WakeupUART0
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART0(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_UART0WKF_Msk) == (PMU_WKFR_UART0WKF_Msk));
}

/**
  * @brief    Get RTC interrupt wakeup flag
  * @rmtoll   WKFR    RTCWKF    FL_PMU_IsActiveFlag_WakeupRTC
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupRTC(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_RTCWKF_Msk) == (PMU_WKFR_RTCWKF_Msk));
}

/**
  * @brief    Get SVD interrupt wakeup flag
  * @rmtoll   WKFR    SVDWKF    FL_PMU_IsActiveFlag_WakeupSVD
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupSVD(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_SVDWKF_Msk) == (PMU_WKFR_SVDWKF_Msk));
}

/**
  * @brief    Get LFDET interrupt wakeup flag
  * @rmtoll   WKFR    LFDETWKF    FL_PMU_IsActiveFlag_WakeupLFDET
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupLFDET(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_LFDETWKF_Msk) == (PMU_WKFR_LFDETWKF_Msk));
}

/**
  * @brief    Get UART3 interrupt wakeup flag
  * @rmtoll   WKFR    UART3WKF    FL_PMU_IsActiveFlag_WakeupUART3
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART3(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_UART3WKF_Msk) == (PMU_WKFR_UART3WKF_Msk));
}

/**
  * @brief    Get IO interrupt wakeup flag
  * @rmtoll   WKFR    IOWKF    FL_PMU_IsActiveFlag_WakeupEXTI
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupEXTI(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_IOWKF_Msk) == (PMU_WKFR_IOWKF_Msk));
}

/**
  * @brief    Get I2C1 interrupt wakeup flag
  * @rmtoll   WKFR    IIC1WKF    FL_PMU_IsActiveFlag_WakeupI2C1
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupI2C1(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_IIC1WKF_Msk) == (PMU_WKFR_IIC1WKF_Msk));
}

/**
  * @brief    Get I2C0 interrupt wakeup flag
  * @rmtoll   WKFR    IIC0WKF    FL_PMU_IsActiveFlag_WakeupI2C0
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupI2C0(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_IIC0WKF_Msk) == (PMU_WKFR_IIC0WKF_Msk));
}

/**
  * @brief    Get UART5 interrupt wakeup flag
  * @rmtoll   WKFR    UART5WKF    FL_PMU_IsActiveFlag_WakeupUART5
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART5(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_UART5WKF_Msk) == (PMU_WKFR_UART5WKF_Msk));
}

/**
  * @brief    Get UART4 interrupt wakeup flag
  * @rmtoll   WKFR    UART4WKF    FL_PMU_IsActiveFlag_WakeupUART4
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART4(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_UART4WKF_Msk) == (PMU_WKFR_UART4WKF_Msk));
}

/**
  * @brief    Get LPUART0 interrupt wakeup flag
  * @rmtoll   WKFR    LPU0WKF    FL_PMU_IsActiveFlag_WakeupLPUART0
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupLPUART0(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_LPU0WKF_Msk) == (PMU_WKFR_LPU0WKF_Msk));
}

/**
  * @brief    Get UART7 interrupt wakeup flag
  * @rmtoll   WKFR    UART7WKF    FL_PMU_IsActiveFlag_WakeupUART7
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART7(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_UART7WKF_Msk) == (PMU_WKFR_UART7WKF_Msk));
}

/**
  * @brief    Get COMP interrrupt wakeup flag
  * @rmtoll   WKFR    COMPWKF    FL_PMU_IsActiveFlag_WakeupCOMP
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupCOMP(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_COMPWKF_Msk) == (PMU_WKFR_COMPWKF_Msk));
}

/**
  * @brief    Get UART6 interrupt wakeup flag
  * @rmtoll   WKFR    UART6WKF    FL_PMU_IsActiveFlag_WakeupUART6
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART6(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_UART6WKF_Msk) == (PMU_WKFR_UART6WKF_Msk));
}

/**
  * @brief    Get LPTIM16 interrupt wakeup flag
  * @rmtoll   WKFR    LPT16WKF    FL_PMU_IsActiveFlag_WakeupLPTIM16
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupLPTIM16(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_LPT16WKF_Msk) == (PMU_WKFR_LPT16WKF_Msk));
}

/**
  * @brief    Get BSTIM16 interrupt wakeup flag
  * @rmtoll   WKFR    BST16WKF    FL_PMU_IsActiveFlag_WakeupBSTIM16
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupBSTIM16(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_BST16WKF_Msk) == (PMU_WKFR_BST16WKF_Msk));
}

/**
  * @brief    Get CPU Debugger wakeup flag
  * @rmtoll   WKFR    DBGWKF    FL_PMU_IsActiveFlag_WakeupDBG
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupDBG(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_DBGWKF_Msk) == (PMU_WKFR_DBGWKF_Msk));
}

/**
  * @brief    Clear CPU Debugger wakeup flag
  * @rmtoll   WKFR    DBGWKF    FL_PMU_ClearFlag_WakeupDBG
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_ClearFlag_WakeupDBG(PMU_Type* PMUx)
{
    WRITE_REG(PMUx->WKFR, PMU_WKFR_DBGWKF_Msk);
}

/**
  * @brief    Get pinx wakeup flag
  * @rmtoll   WKFR    WKPXF    FL_PMU_IsActiveFlag_WakeupPIN
  * @param    PMUx PMU instance
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP0_PIN
  *           @arg @ref FL_PMU_WAKEUP1_PIN
  *           @arg @ref FL_PMU_WAKEUP2_PIN
  *           @arg @ref FL_PMU_WAKEUP3_PIN
  *           @arg @ref FL_PMU_WAKEUP4_PIN
  *           @arg @ref FL_PMU_WAKEUP5_PIN
  *           @arg @ref FL_PMU_WAKEUP6_PIN
  *           @arg @ref FL_PMU_WAKEUP7_PIN
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupPIN(PMU_Type* PMUx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, ((Pin & 0xff) << 0x0U)) == ((Pin & 0xff) << 0x0U));
}

/**
  * @brief    Clear pinx wakeup flag
  * @rmtoll   WKFR    WKPXF    FL_PMU_ClearFlag_WakeupPIN
  * @param    PMUx PMU instance
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP0_PIN
  *           @arg @ref FL_PMU_WAKEUP1_PIN
  *           @arg @ref FL_PMU_WAKEUP2_PIN
  *           @arg @ref FL_PMU_WAKEUP3_PIN
  *           @arg @ref FL_PMU_WAKEUP4_PIN
  *           @arg @ref FL_PMU_WAKEUP5_PIN
  *           @arg @ref FL_PMU_WAKEUP6_PIN
  *           @arg @ref FL_PMU_WAKEUP7_PIN
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_ClearFlag_WakeupPIN(PMU_Type* PMUx, uint32_t Pin)
{
    WRITE_REG(PMUx->WKFR, ((Pin & 0xff) << 0x0U));
}

/**
  * @brief    LPREIE error interrupt enable
  * @rmtoll   IER    LPREIE    FL_PMU_EnableIT_LPRunError
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableIT_LPRunError(PMU_Type* PMUx)
{
    SET_BIT(PMUx->IER, PMU_IER_LPREIE_Msk);
}

/**
  * @brief    Get LPREIE error interrupt enable status
  * @rmtoll   IER    LPREIE    FL_PMU_IsEnabledIT_LPRunError
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledIT_LPRunError(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->IER, PMU_IER_LPREIE_Msk) == PMU_IER_LPREIE_Msk);
}

/**
  * @brief    LPREIE error interrupt disable
  * @rmtoll   IER    LPREIE    FL_PMU_DisableIT_LPRunError
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableIT_LPRunError(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->IER, PMU_IER_LPREIE_Msk);
}

/**
  * @brief    Get LPRUN error interrupt flag
  * @rmtoll   ISR    LPREIF    FL_PMU_IsActiveFlag_LPRunError
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_LPRunError(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->ISR, PMU_ISR_LPREIF_Msk) == (PMU_ISR_LPREIF_Msk));
}

/**
  * @brief    Clear LPRUN error interrupt flag
  * @rmtoll   ISR    LPREIF    FL_PMU_ClearFlag_LPRunError
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_ClearFlag_LPRunError(PMU_Type* PMUx)
{
    WRITE_REG(PMUx->ISR, PMU_ISR_LPREIF_Msk);
}

/**
  * @brief    Enable AVREF Buffer Output
  * @rmtoll   BUFCR    AVREFBUF_OUTEN    FL_PMU_EnableAVREFBufferOutput
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableAVREFBufferOutput(PMU_Type* PMUx)
{
    SET_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_OUTEN_Msk);
}

/**
  * @brief    Get AVREF Buffer Output Enable Status
  * @rmtoll   BUFCR    AVREFBUF_OUTEN    FL_PMU_IsEnabledAVREFBufferOutput
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledAVREFBufferOutput(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_OUTEN_Msk) == PMU_BUFCR_AVREFBUF_OUTEN_Msk);
}

/**
  * @brief    Disable AVREF Buffer Output
  * @rmtoll   BUFCR    AVREFBUF_OUTEN    FL_PMU_DisableAVREFBufferOutput
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableAVREFBufferOutput(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_OUTEN_Msk);
}

/**
  * @brief    Enable AVREF Buffer
  * @rmtoll   BUFCR    AVREFBUF_EN    FL_PMU_EnableAVREFBuffer
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableAVREFBuffer(PMU_Type* PMUx)
{
    SET_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_EN_Msk);
}

/**
  * @brief    Get AVREF Buffer Enable Status
  * @rmtoll   BUFCR    AVREFBUF_EN    FL_PMU_IsEnabledAVREFBuffer
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledAVREFBuffer(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_EN_Msk) == PMU_BUFCR_AVREFBUF_EN_Msk);
}

/**
  * @brief    Disable AVREF Buffer 
  * @rmtoll   BUFCR    AVREFBUF_EN    FL_PMU_DisableAVREFBuffer
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableAVREFBuffer(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_EN_Msk);
}

/**
  * @brief    Enable VPTAT Buffer Output
  * @rmtoll   BUFCR    VPTATBUFFER_OUTEN    FL_PMU_EnableVPTATBufferOutput
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableVPTATBufferOutput(PMU_Type* PMUx)
{
    SET_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_OUTEN_Msk);
}

/**
  * @brief    Get VPTAT Buffer Output Enable Status
  * @rmtoll   BUFCR    VPTATBUFFER_OUTEN    FL_PMU_IsEnabledVPTATBufferOutput
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledVPTATBufferOutput(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_OUTEN_Msk) == PMU_BUFCR_VPTATBUFFER_OUTEN_Msk);
}

/**
  * @brief    Disable VPTAT Buffer Output
  * @rmtoll   BUFCR    VPTATBUFFER_OUTEN    FL_PMU_DisableVPTATBufferOutput
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableVPTATBufferOutput(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_OUTEN_Msk);
}

/**
  * @brief    Enable VPTAT Buffer
  * @rmtoll   BUFCR    VPTATBUFFER_EN    FL_PMU_EnableVPTATBuffer
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableVPTATBuffer(PMU_Type* PMUx)
{
    SET_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_EN_Msk);
}

/**
  * @brief    Get VPTAT Buffer Enable Status
  * @rmtoll   BUFCR    VPTATBUFFER_EN    FL_PMU_IsEnabledVPTATBuffer
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledVPTATBuffer(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_EN_Msk) == PMU_BUFCR_VPTATBUFFER_EN_Msk);
}

/**
  * @brief    Disable VPTAT Buffer 
  * @rmtoll   BUFCR    VPTATBUFFER_EN    FL_PMU_DisableVPTATBuffer
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableVPTATBuffer(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_EN_Msk);
}

/**
  * @brief    Enable Temperatue Sensor
  * @rmtoll   PTATCR    PTAT_EN    FL_PMU_EnableTemperatureSensor
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableTemperatureSensor(PMU_Type* PMUx)
{
    SET_BIT(PMUx->PTATCR, PMU_PTATCR_PTAT_EN_Msk);
}

/**
  * @brief    Get Temperatue Sensor Enable Status
  * @rmtoll   PTATCR    PTAT_EN    FL_PMU_IsEnabledTemperatureSensor
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledTemperatureSensor(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->PTATCR, PMU_PTATCR_PTAT_EN_Msk) == PMU_PTATCR_PTAT_EN_Msk);
}

/**
  * @brief    Disable Temperatue Sensor
  * @rmtoll   PTATCR    PTAT_EN    FL_PMU_DisableTemperatureSensor
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableTemperatureSensor(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->PTATCR, PMU_PTATCR_PTAT_EN_Msk);
}

/**
  * @}
  */

/** @defgroup PMU_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_PMU_Sleep_DeInit(PMU_Type *PMUx);
FL_ErrorStatus FL_PMU_Sleep_Init(PMU_Type *PMUx, FL_PMU_SleepInitTypeDef *LPM_InitStruct);
void FL_PMU_StructInit(FL_PMU_SleepInitTypeDef *LPM_InitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_PMU_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2024-01-15*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
