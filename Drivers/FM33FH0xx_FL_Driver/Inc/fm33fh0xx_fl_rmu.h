/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_rmu.h
  * @author  FMSH Application Team
  * @brief   Head file of RMU FL Module
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
#ifndef __FM33FH0XX_FL_RMU_H
#define __FM33FH0XX_FL_RMU_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl_def.h"
/** @addtogroup FM33FH0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup RMU_FL_ES_INIT RMU Exported Init structures
  * @{
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup RMU_FL_Exported_Constants RMU Exported Constants
  * @{
  */

#define    RMU_PDRCR_CFG_Pos                                      (1U)
#define    RMU_PDRCR_CFG_Msk                                      (0x3U << RMU_PDRCR_CFG_Pos)
#define    RMU_PDRCR_CFG                                          RMU_PDRCR_CFG_Msk

#define    RMU_PDRCR_EN_Pos                                       (0U)
#define    RMU_PDRCR_EN_Msk                                       (0x1U << RMU_PDRCR_EN_Pos)
#define    RMU_PDRCR_EN                                           RMU_PDRCR_EN_Msk

#define    RMU_RSTCR_LOLRST_EN_Pos                                (7U)
#define    RMU_RSTCR_LOLRST_EN_Msk                                (0x1U << RMU_RSTCR_LOLRST_EN_Pos)
#define    RMU_RSTCR_LOLRST_EN                                    RMU_RSTCR_LOLRST_EN_Msk

#define    RMU_RSTCR_LOCRST_EN_Pos                                (6U)
#define    RMU_RSTCR_LOCRST_EN_Msk                                (0x1U << RMU_RSTCR_LOCRST_EN_Pos)
#define    RMU_RSTCR_LOCRST_EN                                    RMU_RSTCR_LOCRST_EN_Msk

#define    RMU_RSTCR_LKUPRST_EN_Pos                               (1U)
#define    RMU_RSTCR_LKUPRST_EN_Msk                               (0x1U << RMU_RSTCR_LKUPRST_EN_Pos)
#define    RMU_RSTCR_LKUPRST_EN                                   RMU_RSTCR_LKUPRST_EN_Msk

#define    RMU_RSTFR_CLM2_TOUT_FLAG_Pos                           (24U)
#define    RMU_RSTFR_CLM2_TOUT_FLAG_Msk                           (0x1U << RMU_RSTFR_CLM2_TOUT_FLAG_Pos)
#define    RMU_RSTFR_CLM2_TOUT_FLAG                               RMU_RSTFR_CLM2_TOUT_FLAG_Msk

#define    RMU_RSTFR_CLM2_UDF_FLAG_Pos                            (23U)
#define    RMU_RSTFR_CLM2_UDF_FLAG_Msk                            (0x1U << RMU_RSTFR_CLM2_UDF_FLAG_Pos)
#define    RMU_RSTFR_CLM2_UDF_FLAG                                RMU_RSTFR_CLM2_UDF_FLAG_Msk

#define    RMU_RSTFR_CLM2_OVF_FLAG_Pos                            (22U)
#define    RMU_RSTFR_CLM2_OVF_FLAG_Msk                            (0x1U << RMU_RSTFR_CLM2_OVF_FLAG_Pos)
#define    RMU_RSTFR_CLM2_OVF_FLAG                                RMU_RSTFR_CLM2_OVF_FLAG_Msk

#define    RMU_RSTFR_CLM1_TOUT_FLAG_Pos                           (21U)
#define    RMU_RSTFR_CLM1_TOUT_FLAG_Msk                           (0x1U << RMU_RSTFR_CLM1_TOUT_FLAG_Pos)
#define    RMU_RSTFR_CLM1_TOUT_FLAG                               RMU_RSTFR_CLM1_TOUT_FLAG_Msk

#define    RMU_RSTFR_CLM1_UDF_FLAG_Pos                            (20U)
#define    RMU_RSTFR_CLM1_UDF_FLAG_Msk                            (0x1U << RMU_RSTFR_CLM1_UDF_FLAG_Pos)
#define    RMU_RSTFR_CLM1_UDF_FLAG                                RMU_RSTFR_CLM1_UDF_FLAG_Msk

#define    RMU_RSTFR_CLM1_OVF_FLAG_Pos                            (19U)
#define    RMU_RSTFR_CLM1_OVF_FLAG_Msk                            (0x1U << RMU_RSTFR_CLM1_OVF_FLAG_Pos)
#define    RMU_RSTFR_CLM1_OVF_FLAG                                RMU_RSTFR_CLM1_OVF_FLAG_Msk

#define    RMU_RSTFR_CLM0_TOUT_FLAG_Pos                           (18U)
#define    RMU_RSTFR_CLM0_TOUT_FLAG_Msk                           (0x1U << RMU_RSTFR_CLM0_TOUT_FLAG_Pos)
#define    RMU_RSTFR_CLM0_TOUT_FLAG                               RMU_RSTFR_CLM0_TOUT_FLAG_Msk

#define    RMU_RSTFR_CLM0_UDF_FLAG_Pos                            (17U)
#define    RMU_RSTFR_CLM0_UDF_FLAG_Msk                            (0x1U << RMU_RSTFR_CLM0_UDF_FLAG_Pos)
#define    RMU_RSTFR_CLM0_UDF_FLAG                                RMU_RSTFR_CLM0_UDF_FLAG_Msk

#define    RMU_RSTFR_CLM0_OVF_FLAG_Pos                            (16U)
#define    RMU_RSTFR_CLM0_OVF_FLAG_Msk                            (0x1U << RMU_RSTFR_CLM0_OVF_FLAG_Pos)
#define    RMU_RSTFR_CLM0_OVF_FLAG                                RMU_RSTFR_CLM0_OVF_FLAG_Msk

#define    RMU_RSTFR_TEST_FLAG_Pos                                (15U)
#define    RMU_RSTFR_TEST_FLAG_Msk                                (0x1U << RMU_RSTFR_TEST_FLAG_Pos)
#define    RMU_RSTFR_TEST_FLAG                                    RMU_RSTFR_TEST_FLAG_Msk

#define    RMU_RSTFR_RAMP_FLAG_Pos                                (14U)
#define    RMU_RSTFR_RAMP_FLAG_Msk                                (0x1U << RMU_RSTFR_RAMP_FLAG_Pos)
#define    RMU_RSTFR_RAMP_FLAG                                    RMU_RSTFR_RAMP_FLAG_Msk

#define    RMU_RSTFR_MAP_FLAG_Pos                                 (13U)
#define    RMU_RSTFR_MAP_FLAG_Msk                                 (0x1U << RMU_RSTFR_MAP_FLAG_Pos)
#define    RMU_RSTFR_MAP_FLAG                                     RMU_RSTFR_MAP_FLAG_Msk

#define    RMU_RSTFR_MDF_FLAG_Pos                                 (12U)
#define    RMU_RSTFR_MDF_FLAG_Msk                                 (0x1U << RMU_RSTFR_MDF_FLAG_Pos)
#define    RMU_RSTFR_MDF_FLAG                                     RMU_RSTFR_MDF_FLAG_Msk

#define    RMU_RSTFR_NRST_FLAG_Pos                                (11U)
#define    RMU_RSTFR_NRST_FLAG_Msk                                (0x1U << RMU_RSTFR_NRST_FLAG_Pos)
#define    RMU_RSTFR_NRST_FLAG                                    RMU_RSTFR_NRST_FLAG_Msk

#define    RMU_RSTFR_PODR_FLAG_Pos                                (8U)
#define    RMU_RSTFR_PODR_FLAG_Msk                                (0x1U << RMU_RSTFR_PODR_FLAG_Pos)
#define    RMU_RSTFR_PODR_FLAG                                    RMU_RSTFR_PODR_FLAG_Msk

#define    RMU_RSTFR_LOL_FLAG_Pos                                 (7U)
#define    RMU_RSTFR_LOL_FLAG_Msk                                 (0x1U << RMU_RSTFR_LOL_FLAG_Pos)
#define    RMU_RSTFR_LOL_FLAG                                     RMU_RSTFR_LOL_FLAG_Msk

#define    RMU_RSTFR_LOC_FLAG_Pos                                 (6U)
#define    RMU_RSTFR_LOC_FLAG_Msk                                 (0x1U << RMU_RSTFR_LOC_FLAG_Pos)
#define    RMU_RSTFR_LOC_FLAG                                     RMU_RSTFR_LOC_FLAG_Msk

#define    RMU_RSTFR_SOFT_FLAG_Pos                                (5U)
#define    RMU_RSTFR_SOFT_FLAG_Msk                                (0x1U << RMU_RSTFR_SOFT_FLAG_Pos)
#define    RMU_RSTFR_SOFT_FLAG                                    RMU_RSTFR_SOFT_FLAG_Msk

#define    RMU_RSTFR_IWDT_FLAG_Pos                                (4U)
#define    RMU_RSTFR_IWDT_FLAG_Msk                                (0x1U << RMU_RSTFR_IWDT_FLAG_Pos)
#define    RMU_RSTFR_IWDT_FLAG                                    RMU_RSTFR_IWDT_FLAG_Msk

#define    RMU_RSTFR_SVD_FLAG_Pos                                 (3U)
#define    RMU_RSTFR_SVD_FLAG_Msk                                 (0x1U << RMU_RSTFR_SVD_FLAG_Pos)
#define    RMU_RSTFR_SVD_FLAG                                     RMU_RSTFR_SVD_FLAG_Msk

#define    RMU_RSTFR_WWDT_FLAG_Pos                                (2U)
#define    RMU_RSTFR_WWDT_FLAG_Msk                                (0x1U << RMU_RSTFR_WWDT_FLAG_Pos)
#define    RMU_RSTFR_WWDT_FLAG                                    RMU_RSTFR_WWDT_FLAG_Msk

#define    RMU_RSTFR_LKUP_FLAG_Pos                                (1U)
#define    RMU_RSTFR_LKUP_FLAG_Msk                                (0x1U << RMU_RSTFR_LKUP_FLAG_Pos)
#define    RMU_RSTFR_LKUP_FLAG                                    RMU_RSTFR_LKUP_FLAG_Msk

#define    RMU_RSTFR_NVIC_FLAG_Pos                                (0U)
#define    RMU_RSTFR_NVIC_FLAG_Msk                                (0x1U << RMU_RSTFR_NVIC_FLAG_Pos)
#define    RMU_RSTFR_NVIC_FLAG                                    RMU_RSTFR_NVIC_FLAG_Msk

#define    PERHRSTEN_KEY                                          (0x13579BDFUL)
#define    SOFTWARERESET_KEY                                      (0x5C5CAABBUL)

#define    FL_RMU_RSTAHB_QSPI                                     (0x0U << 0U)
#define    FL_RMU_RSTAHB_DMA                                      (0x1U << 0U)
#define    FL_RMU_RSTAPB_UART5                                    (0x1fU << 0U)
#define    FL_RMU_RSTAPB_UART4                                    (0x1eU << 0U)
#define    FL_RMU_RSTAPB_UART3                                    (0x1dU << 0U)
#define    FL_RMU_RSTAPB_UART2                                    (0x1cU << 0U)
#define    FL_RMU_RSTAPB_UART1                                    (0x1bU << 0U)
#define    FL_RMU_RSTAPB_UART0                                    (0x1aU << 0U)
#define    FL_RMU_RSTAPB_UARTIR                                   (0x19U << 0U)
#define    FL_RMU_RSTAPB_INTMUX                                   (0x17U << 0U)
#define    FL_RMU_RSTAPB_UART7                                    (0x11U << 0U)
#define    FL_RMU_RSTAPB_UART6                                    (0x10U << 0U)
#define    FL_RMU_RSTAPB_SPI2                                     (0xfU << 0U)
#define    FL_RMU_RSTAPB_SPI1                                     (0xeU << 0U)
#define    FL_RMU_RSTAPB_SPI0                                     (0xdU << 0U)
#define    FL_RMU_RSTAPB_I2C1                                     (0xcU << 0U)
#define    FL_RMU_RSTAPB_I2C0                                     (0xbU << 0U)
#define    FL_RMU_RSTAPB_LPUART                                   (0x8U << 0U)
#define    FL_RMU_RSTAPB_TSI                                      (0x5U << 0U)
#define    FL_RMU_RSTAPB_ATIM                                     (0x4U << 0U)
#define    FL_RMU_RSTAPB_TAU1                                     (0x3U << 0U)
#define    FL_RMU_RSTAPB_TAU0                                     (0x2U << 0U)
#define    FL_RMU_RSTAPB_LPTIM16                                  (0x1U << 0U)
#define    FL_RMU_RSTAPB_BSTIM16                                  (0x0U << 0U)
#define    FL_RMU_RSTAPB_DAC                                      (0x39U << 0U)
#define    FL_RMU_RSTAPB_ADCC                                     (0x38U << 0U)
#define    FL_RMU_RSTAPB_ADC                                      (0x37U << 0U)
#define    FL_RMU_RSTAPB_CLM2                                     (0x36U << 0U)
#define    FL_RMU_RSTAPB_CLM1                                     (0x35U << 0U)
#define    FL_RMU_RSTAPB_CLM0                                     (0x34U << 0U)
#define    FL_RMU_RSTAPB_CRC                                      (0x31U << 0U)
#define    FL_RMU_RSTAPB_SENT1                                    (0x2bU << 0U)
#define    FL_RMU_RSTAPB_SENT0                                    (0x2aU << 0U)
#define    FL_RMU_RSTAPB_FDCANR                                   (0x27U << 0U)
#define    FL_RMU_RSTAPB_FDCANP                                   (0x26U << 0U)
#define    FL_RMU_RSTAPB_FDCANC                                   (0x25U << 0U)
#define    FL_RMU_RSTAPB_SVD                                      (0x21U << 0U)
#define    FL_RMU_RSTAPB_COMP                                     (0x20U << 0U)



#define    FL_RMU_PDR_THRESHOLD_1P40V                             (0x0U << RMU_PDRCR_CFG_Pos)
#define    FL_RMU_PDR_THRESHOLD_1P45V                             (0x1U << RMU_PDRCR_CFG_Pos)
#define    FL_RMU_PDR_THRESHOLD_1P50V                             (0x2U << RMU_PDRCR_CFG_Pos)
#define    FL_RMU_PDR_THRESHOLD_1P55V                             (0x3U << RMU_PDRCR_CFG_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup RMU_FL_Exported_Functions RMU Exported Functions
  * @{
  */

/**
  * @brief    Set Power Down Reset Voltage
  * @rmtoll   PDRCR    CFG    FL_RMU_PDR_SetThreshold
  * @param    RMUx RMU instance
  * @param    threshold This parameter can be one of the following values:
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P40V
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P45V
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P50V
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P55V
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_PDR_SetThreshold(RMU_Type* RMUx, uint32_t threshold)
{
    MODIFY_REG(RMUx->PDRCR, RMU_PDRCR_CFG_Msk, threshold);
}

/**
  * @brief    Get Power Down Reset Voltage Setting
  * @rmtoll   PDRCR    CFG    FL_RMU_PDR_GetThreshold
  * @param    RMUx RMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P40V
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P45V
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P50V
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P55V
  */
__STATIC_INLINE uint32_t FL_RMU_PDR_GetThreshold(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->PDRCR, RMU_PDRCR_CFG_Msk));
}

/**
  * @brief    Get Power Down Reset Enable Status
  * @rmtoll   PDRCR    EN    FL_RMU_PDR_IsEnabled
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_PDR_IsEnabled(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->PDRCR, RMU_PDRCR_EN_Msk) == RMU_PDRCR_EN_Msk);
}

/**
  * @brief    Disable Power Down Reset
  * @rmtoll   PDRCR    EN    FL_RMU_PDR_Disable
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_PDR_Disable(RMU_Type* RMUx)
{
    CLEAR_BIT(RMUx->PDRCR, RMU_PDRCR_EN_Msk);
}

/**
  * @brief    Enable Power Down Reset
  * @rmtoll   PDRCR    EN    FL_RMU_PDR_Enable
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_PDR_Enable(RMU_Type* RMUx)
{
    SET_BIT(RMUx->PDRCR, RMU_PDRCR_EN_Msk);
}

/**
  * @brief    Get PLL Lost Lock Reset Enable Status
  * @rmtoll   RSTCR    LOLRST_EN    FL_RMU_IsEnabledPLLLostLockReset
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsEnabledPLLLostLockReset(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTCR, RMU_RSTCR_LOLRST_EN_Msk) == RMU_RSTCR_LOLRST_EN_Msk);
}

/**
  * @brief    Disable  PLL Lost Lock  Reset 
  * @rmtoll   RSTCR    LOLRST_EN    FL_RMU_DisablePLLLostLockReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisablePLLLostLockReset(RMU_Type* RMUx)
{
    CLEAR_BIT(RMUx->RSTCR, RMU_RSTCR_LOLRST_EN_Msk);
}

/**
  * @brief    Enable PLL Lost Lock  Reset
  * @rmtoll   RSTCR    LOLRST_EN    FL_RMU_EnablePLLLostLockReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnablePLLLostLockReset(RMU_Type* RMUx)
{
    SET_BIT(RMUx->RSTCR, RMU_RSTCR_LOLRST_EN_Msk);
}

/**
  * @brief    Get XTHF Stop Reset Enable Status
  * @rmtoll   RSTCR    LOCRST_EN    FL_RMU_IsEnabledXTHFStopReset
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsEnabledXTHFStopReset(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTCR, RMU_RSTCR_LOCRST_EN_Msk) == RMU_RSTCR_LOCRST_EN_Msk);
}

/**
  * @brief    Disable XTHF Stop Reset 
  * @rmtoll   RSTCR    LOCRST_EN    FL_RMU_DisableXTHFStopReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisableXTHFStopReset(RMU_Type* RMUx)
{
    CLEAR_BIT(RMUx->RSTCR, RMU_RSTCR_LOCRST_EN_Msk);
}

/**
  * @brief    Enable XTHF Stop Reset
  * @rmtoll   RSTCR    LOCRST_EN    FL_RMU_EnableXTHFStopReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnableXTHFStopReset(RMU_Type* RMUx)
{
    SET_BIT(RMUx->RSTCR, RMU_RSTCR_LOCRST_EN_Msk);
}

/**
  * @brief    Get LockUp Reset Enable Status
  * @rmtoll   RSTCR    LKUPRST_EN    FL_RMU_IsEnabledLockUpReset
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsEnabledLockUpReset(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTCR, RMU_RSTCR_LKUPRST_EN_Msk) == RMU_RSTCR_LKUPRST_EN_Msk);
}

/**
  * @brief    Disable LockUp Reset 
  * @rmtoll   RSTCR    LKUPRST_EN    FL_RMU_DisableLockUpReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisableLockUpReset(RMU_Type* RMUx)
{
    CLEAR_BIT(RMUx->RSTCR, RMU_RSTCR_LKUPRST_EN_Msk);
}

/**
  * @brief    Enable LockUp Reset
  * @rmtoll   RSTCR    LKUPRST_EN    FL_RMU_EnableLockUpReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnableLockUpReset(RMU_Type* RMUx)
{
    SET_BIT(RMUx->RSTCR, RMU_RSTCR_LKUPRST_EN_Msk);
}

/**
  * @brief    Soft Reset Chip
  * @rmtoll   SOFTRST        FL_RMU_SetSoftReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_SetSoftReset(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->SOFTRST, SOFTWARERESET_KEY);
}

/**
  * @brief    Get CLM2 Time Out Reset Flag
  * @rmtoll   RSTFR    CLM2_TOUT_FLAG    CLM2_TOUT
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM2_TOUT(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM2_TOUT_FLAG_Msk) == (RMU_RSTFR_CLM2_TOUT_FLAG_Msk));
}

/**
  * @brief    Get CLM2 Underflow Reset Flag
  * @rmtoll   RSTFR    CLM2_UDF_FLAG    CLM2_UDF
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM2_UDF(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM2_UDF_FLAG_Msk) == (RMU_RSTFR_CLM2_UDF_FLAG_Msk));
}

/**
  * @brief    Get CLM2 Overflow Reset Flag
  * @rmtoll   RSTFR    CLM2_OVF_FLAG    CLM2_OVF
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM2_OVF(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM2_OVF_FLAG_Msk) == (RMU_RSTFR_CLM2_OVF_FLAG_Msk));
}

/**
  * @brief    Clear CLM2 Time Out   Reset Flag
  * @rmtoll   RSTFR    CLM2_TOUT_FLAG    CLM2_TOUT
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM2_TOUT(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM2_TOUT_FLAG_Msk);
}

/**
  * @brief    Clear CLM2 Underflow Reset Flag
  * @rmtoll   RSTFR    CLM2_UDF_FLAG    CLM2_UDF
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM2_UDF(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM2_UDF_FLAG_Msk);
}

/**
  * @brief    Clear CLM2 Overflow  Reset Flag
  * @rmtoll   RSTFR    CLM2_OVF_FLAG    CLM2_OVF
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM2_OVF(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM2_OVF_FLAG_Msk);
}

/**
  * @brief    Get CLM1 Time Out Reset Flag
  * @rmtoll   RSTFR    CLM1_TOUT_FLAG    CLM1_TOUT
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM1_TOUT(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM1_TOUT_FLAG_Msk) == (RMU_RSTFR_CLM1_TOUT_FLAG_Msk));
}

/**
  * @brief    Get CLM1 Underflow Reset Flag
  * @rmtoll   RSTFR    CLM1_UDF_FLAG    CLM1_UDF
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM1_UDF(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM1_UDF_FLAG_Msk) == (RMU_RSTFR_CLM1_UDF_FLAG_Msk));
}

/**
  * @brief    Get CLM1 Overflow Reset Flag
  * @rmtoll   RSTFR    CLM1_OVF_FLAG    CLM1_OVF
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM1_OVF(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM1_OVF_FLAG_Msk) == (RMU_RSTFR_CLM1_OVF_FLAG_Msk));
}

/**
  * @brief    Clear CLM1 Time Out   Reset Flag
  * @rmtoll   RSTFR    CLM1_TOUT_FLAG    CLM1_TOUT
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM1_TOUT(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM1_TOUT_FLAG_Msk);
}

/**
  * @brief    Clear CLM1 Underflow Reset Flag
  * @rmtoll   RSTFR    CLM1_UDF_FLAG    CLM1_UDF
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM1_UDF(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM1_UDF_FLAG_Msk);
}

/**
  * @brief    Clear CLM1 Overflow  Reset Flag
  * @rmtoll   RSTFR    CLM1_OVF_FLAG    CLM1_OVF
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM1_OVF(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM1_OVF_FLAG_Msk);
}


/**
  * @brief    Get CLM0 Time Out Reset Flag
  * @rmtoll   RSTFR    CLM0_TOUT_FLAG    CLM0_TOUT
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM0_TOUT(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM0_TOUT_FLAG_Msk) == (RMU_RSTFR_CLM0_TOUT_FLAG_Msk));
}

/**
  * @brief    Get CLM0 Underflow Reset Flag
  * @rmtoll   RSTFR    CLM0_UDF_FLAG    CLM0_UDF
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM0_UDF(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM0_UDF_FLAG_Msk) == (RMU_RSTFR_CLM0_UDF_FLAG_Msk));
}

/**
  * @brief    Get CLM0 Overflow Reset Flag
  * @rmtoll   RSTFR    CLM0_OVF_FLAG    CLM0_OVF
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM0_OVF(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM0_OVF_FLAG_Msk) == (RMU_RSTFR_CLM0_OVF_FLAG_Msk));
}

/**
  * @brief    Clear CLM0 Time Out   Reset Flag
  * @rmtoll   RSTFR    CLM0_TOUT_FLAG    CLM0_TOUT
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM0_TOUT(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM0_TOUT_FLAG_Msk);
}

/**
  * @brief    Clear CLM0 Underflow Reset Flag
  * @rmtoll   RSTFR    CLM0_UDF_FLAG    CLM0_UDF
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM0_UDF(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM0_UDF_FLAG_Msk);
}

/**
  * @brief    Clear CLM0 Overflow  Reset Flag
  * @rmtoll   RSTFR    CLM0_OVF_FLAG    CLM0_OVF
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM0_OVF(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM0_OVF_FLAG_Msk);
}

/**
  * @brief    Get TEST Reset Flag
  * @rmtoll   RSTFR    TEST_FLAG    FL_RMU_IsActiveFlag_TEST
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_TEST(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_TEST_FLAG_Msk) == (RMU_RSTFR_TEST_FLAG_Msk));
}

/**
  * @brief    Clear TEST Reset Flag
  * @rmtoll   RSTFR    TEST_FLAG    FL_RMU_ClearFlag_TEST
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_TEST(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_TEST_FLAG_Msk);
}

/**
  * @brief    Get RAMP Error Flag
  * @rmtoll   RSTFR    RAMP_FLAG    FL_RMU_IsActiveFlag_MAP
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_MAP(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_RAMP_FLAG_Msk) == (RMU_RSTFR_RAMP_FLAG_Msk));
}

/**
  * @brief    Clear RAMP Reset Flag
  * @rmtoll   RSTFR    RAMP_FLAG    FL_RMU_ClearFlag_MAP
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_MAP(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_RAMP_FLAG_Msk);
}

/**
  * @brief    Get MDF Reset Flag
  * @rmtoll   RSTFR    MDF_FLAG    FL_RMU_IsActiveFlag_MDF
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_MDF(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_MDF_FLAG_Msk) == (RMU_RSTFR_MDF_FLAG_Msk));
}

/**
  * @brief    Clear MDF Reset Flag
  * @rmtoll   RSTFR    MDF_FLAG    FL_RMU_ClearFlag_MDF
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_MDF(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_MDF_FLAG_Msk);
}

/**
  * @brief    Get NRST Reset Flag
  * @rmtoll   RSTFR    NRST_FLAG    FL_RMU_IsActiveFlag_NRST
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_NRST(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_NRST_FLAG_Msk) == (RMU_RSTFR_NRST_FLAG_Msk));
}

/**
  * @brief    Clear NRST Reset Flag
  * @rmtoll   RSTFR    NRST_FLAG    FL_RMU_ClearFlag_NRST
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_NRST(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_NRST_FLAG_Msk);
}

/**
  * @brief    Get Power On And Down Reset Flag
  * @rmtoll   RSTFR    PODR_FLAG    FL_RMU_IsActiveFlag_PODN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_PODN(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_PODR_FLAG_Msk) == (RMU_RSTFR_PODR_FLAG_Msk));
}

/**
  * @brief    Clear  Power On And Down Reset Flag
  * @rmtoll   RSTFR    PODR_FLAG    FL_RMU_ClearFlag_PODN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_PODN(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_PODR_FLAG_Msk);
}

/**
  * @brief    Get LOL Reset Flag
  * @rmtoll   RSTFR    LOL_FLAG    FL_RMU_IsActiveFlag_LOL
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_LOL(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_LOL_FLAG_Msk) == (RMU_RSTFR_LOL_FLAG_Msk));
}

/**
  * @brief    Clear LOL Reset Flag
  * @rmtoll   RSTFR    LOL_FLAG    FL_RMU_ClearFlag_LOL
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_LOL(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_LOL_FLAG_Msk);
}

/**
  * @brief    Get LOC Reset Flag
  * @rmtoll   RSTFR    LOC_FLAG    FL_RMU_IsActiveFlag_LOC
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_LOC(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_LOC_FLAG_Msk) == (RMU_RSTFR_LOC_FLAG_Msk));
}

/**
  * @brief    Clear LOC Reset Flag
  * @rmtoll   RSTFR    LOC_FLAG    FL_RMU_ClearFlag_LOC
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_LOC(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_LOC_FLAG_Msk);
}

/**
  * @brief    Get Software Reset Flag
  * @rmtoll   RSTFR    SOFT_FLAG    FL_RMU_IsActiveFlag_SOFT
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_SOFT(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_SOFT_FLAG_Msk) == (RMU_RSTFR_SOFT_FLAG_Msk));
}

/**
  * @brief    Clear Software Reset Flag
  * @rmtoll   RSTFR    SOFT_FLAG    FL_RMU_ClearFlag_SOFT
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_SOFT(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_SOFT_FLAG_Msk);
}

/**
  * @brief    Get IWDT Reset Flag
  * @rmtoll   RSTFR    IWDT_FLAG    FL_RMU_IsActiveFlag_IWDT
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_IWDT(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_IWDT_FLAG_Msk) == (RMU_RSTFR_IWDT_FLAG_Msk));
}

/**
  * @brief    Clear IWDT Reset Flag
  * @rmtoll   RSTFR    IWDT_FLAG    FL_RMU_ClearFlag_IWDT
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_IWDT(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_IWDT_FLAG_Msk);
}

/**
  * @brief    Clear SVD Reset Flag
  * @rmtoll   RSTFR    SVD_FLAG    FL_RMU_ClearFlag_SVD
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_SVD(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_SVD_FLAG_Msk);
}

/**
  * @brief    Get SVD Reset Flag
  * @rmtoll   RSTFR    SVD_FLAG    FL_RMU_IsActiveFlag_SVD
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_SVD(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_SVD_FLAG_Msk) == (RMU_RSTFR_SVD_FLAG_Msk));
}

/**
  * @brief    Get WWDT Reset Flag
  * @rmtoll   RSTFR    WWDT_FLAG    FL_RMU_IsActiveFlag_WWDT
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_WWDT(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_WWDT_FLAG_Msk) == (RMU_RSTFR_WWDT_FLAG_Msk));
}

/**
  * @brief    Clear WWDT Reset Flag
  * @rmtoll   RSTFR    WWDT_FLAG    FL_RMU_ClearFlag_WWDT
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_WWDT(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_WWDT_FLAG_Msk);
}

/**
  * @brief    Get LockUp Reset Flag
  * @rmtoll   RSTFR    LKUP_FLAG    FL_RMU_IsActiveFlag_LKUP
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_LKUP(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_LKUP_FLAG_Msk) == (RMU_RSTFR_LKUP_FLAG_Msk));
}

/**
  * @brief    Clear LockUp Reset Flag
  * @rmtoll   RSTFR    LKUP_FLAG    FL_RMU_ClearFlag_LKUP
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_LKUP(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_LKUP_FLAG_Msk);
}

/**
  * @brief    Get NVIC Reset Flag
  * @rmtoll   RSTFR    NVIC_FLAG    FL_RMU_IsActiveFlag_NVIC
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_NVIC(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_NVIC_FLAG_Msk) == (RMU_RSTFR_NVIC_FLAG_Msk));
}

/**
  * @brief    Clear NVIC Reset Flag
  * @rmtoll   RSTFR    NVIC_FLAG    FL_RMU_ClearFlag_NVIC
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_NVIC(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_NVIC_FLAG_Msk);
}

/**
  * @brief    Disable Peripheral Reset
  * @rmtoll   PRSTEN        FL_RMU_DisablePeripheralReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisablePeripheralReset(RMU_Type* RMUx)
{
     WRITE_REG(RMUx->PRSTEN, (~PERHRSTEN_KEY));
}

/**
  * @brief    Enable Peripheral Reset
  * @rmtoll   PRSTEN        FL_RMU_EnablePeripheralReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnablePeripheralReset(RMU_Type* RMUx)
{
     WRITE_REG(RMUx->PRSTEN, PERHRSTEN_KEY); 
}

/**
  * @brief    Enable AHB Peripheral Reset
  * @rmtoll   AHBRSTCR        FL_RMU_EnableResetAHBPeripheral
  * @param    RMUx RMU instance
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_RMU_RSTAHB_QSPI
  *           @arg @ref FL_RMU_RSTAHB_DMA
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnableResetAHBPeripheral(RMU_Type* RMUx, uint32_t peripheral)
{
    SET_BIT(RMUx->AHBRSTCR, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable APB Peripheral Reset1
  * @rmtoll   APBRSTCR        FL_RMU_EnableResetAPBPeripheral
  * @param    RMUx RMU instance
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_RMU_RSTAPB_UART5
  *           @arg @ref FL_RMU_RSTAPB_UART4
  *           @arg @ref FL_RMU_RSTAPB_UART3
  *           @arg @ref FL_RMU_RSTAPB_UART2
  *           @arg @ref FL_RMU_RSTAPB_UART1
  *           @arg @ref FL_RMU_RSTAPB_UART0
  *           @arg @ref FL_RMU_RSTAPB_UARTIR
  *           @arg @ref FL_RMU_RSTAPB_INTMUX
  *           @arg @ref FL_RMU_RSTAPB_UART7
  *           @arg @ref FL_RMU_RSTAPB_UART6
  *           @arg @ref FL_RMU_RSTAPB_SPI2
  *           @arg @ref FL_RMU_RSTAPB_SPI1
  *           @arg @ref FL_RMU_RSTAPB_SPI0
  *           @arg @ref FL_RMU_RSTAPB_I2C1
  *           @arg @ref FL_RMU_RSTAPB_I2C0
  *           @arg @ref FL_RMU_RSTAPB_LPUART
  *           @arg @ref FL_RMU_RSTAPB_TSI
  *           @arg @ref FL_RMU_RSTAPB_ATIM
  *           @arg @ref FL_RMU_RSTAPB_TAU1
  *           @arg @ref FL_RMU_RSTAPB_TAU0
  *           @arg @ref FL_RMU_RSTAPB_LPTIM16
  *           @arg @ref FL_RMU_RSTAPB_BSTIM16
  *           @arg @ref FL_RMU_RSTAPB_DAC
  *           @arg @ref FL_RMU_RSTAPB_ADCC
  *           @arg @ref FL_RMU_RSTAPB_ADC
  *           @arg @ref FL_RMU_RSTAPB_CLM2
  *           @arg @ref FL_RMU_RSTAPB_CLM1
  *           @arg @ref FL_RMU_RSTAPB_CLM0
  *           @arg @ref FL_RMU_RSTAPB_CRC
  *           @arg @ref FL_RMU_RSTAPB_SENT1
  *           @arg @ref FL_RMU_RSTAPB_SENT0
  *           @arg @ref FL_RMU_RSTAPB_FDCANR
  *           @arg @ref FL_RMU_RSTAPB_FDCANP
  *           @arg @ref FL_RMU_RSTAPB_FDCANC
  *           @arg @ref FL_RMU_RSTAPB_SVD
  *           @arg @ref FL_RMU_RSTAPB_COMP
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnableResetAPBPeripheral(RMU_Type* RMUx, uint32_t peripheral)
{
    if(peripheral < FL_RMU_RSTAPB_COMP)
    {
        SET_BIT(RMUx->APBRSTCR1, (0x1U << peripheral));
    }
    else
    {
        SET_BIT(RMUx->APBRSTCR2, (0x1U << (peripheral - 32)));
    }
}

/**
  * @brief    Disable AHB Peripheral Reset
  * @rmtoll   AHBRST        FL_RMU_DisableResetAHBPeripheral
  * @param    RMUx RMU instance
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_RMU_RSTAHB_QSPI
  *           @arg @ref FL_RMU_RSTAHB_DMA
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisableResetAHBPeripheral(RMU_Type* RMUx, uint32_t peripheral)
{
    CLEAR_BIT(RMUx->AHBRSTCR, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable APB Peripheral Reset1
  * @rmtoll   APBRST        FL_RMU_DisableResetAPBPeripheral
  * @param    RMUx RMU instance
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_RMU_RSTAPB_UART5
  *           @arg @ref FL_RMU_RSTAPB_UART4
  *           @arg @ref FL_RMU_RSTAPB_UART3
  *           @arg @ref FL_RMU_RSTAPB_UART2
  *           @arg @ref FL_RMU_RSTAPB_UART1
  *           @arg @ref FL_RMU_RSTAPB_UART0
  *           @arg @ref FL_RMU_RSTAPB_UARTIR
  *           @arg @ref FL_RMU_RSTAPB_INTMUX
  *           @arg @ref FL_RMU_RSTAPB_UART7
  *           @arg @ref FL_RMU_RSTAPB_UART6
  *           @arg @ref FL_RMU_RSTAPB_SPI2
  *           @arg @ref FL_RMU_RSTAPB_SPI1
  *           @arg @ref FL_RMU_RSTAPB_SPI0
  *           @arg @ref FL_RMU_RSTAPB_I2C1
  *           @arg @ref FL_RMU_RSTAPB_I2C0
  *           @arg @ref FL_RMU_RSTAPB_LPUART
  *           @arg @ref FL_RMU_RSTAPB_TSI
  *           @arg @ref FL_RMU_RSTAPB_ATIM
  *           @arg @ref FL_RMU_RSTAPB_TAU1
  *           @arg @ref FL_RMU_RSTAPB_TAU0
  *           @arg @ref FL_RMU_RSTAPB_LPTIM16
  *           @arg @ref FL_RMU_RSTAPB_BSTIM16
  *           @arg @ref FL_RMU_RSTAPB_DAC
  *           @arg @ref FL_RMU_RSTAPB_ADCC
  *           @arg @ref FL_RMU_RSTAPB_ADC
  *           @arg @ref FL_RMU_RSTAPB_CLM2
  *           @arg @ref FL_RMU_RSTAPB_CLM1
  *           @arg @ref FL_RMU_RSTAPB_CLM0
  *           @arg @ref FL_RMU_RSTAPB_CRC
  *           @arg @ref FL_RMU_RSTAPB_SENT1
  *           @arg @ref FL_RMU_RSTAPB_SENT0
  *           @arg @ref FL_RMU_RSTAPB_FDCANR
  *           @arg @ref FL_RMU_RSTAPB_FDCANP
  *           @arg @ref FL_RMU_RSTAPB_FDCANC
  *           @arg @ref FL_RMU_RSTAPB_SVD
  *           @arg @ref FL_RMU_RSTAPB_COMP
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisableResetAPBPeripheral(RMU_Type* RMUx, uint32_t peripheral)
{
   if(peripheral < FL_RMU_RSTAPB_COMP)
    {
        CLEAR_BIT(RMUx->APBRSTCR1, (0x1U << peripheral));
    }
    else
    {
        CLEAR_BIT(RMUx->APBRSTCR2, (0x1U << (peripheral - 32)));
    }
}

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_RMU_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2024-01-04*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
