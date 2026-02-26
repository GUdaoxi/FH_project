/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_adc.h
  * @author  FMSH Application Team
  * @brief   Head file of ADC FL Module
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
#ifndef __FM33FH0XX_FL_ADC_H
#define __FM33FH0XX_FL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl_def.h"
/** @addtogroup FM33FH0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_ES_INIT ADC Exported Init structures
  * @{
  */
#define ADC_VREF    (*((uint16_t *)(0x1FFFFB0C)))    /*  vref1P0电压值（*10000） */
#define ADC_TS      (*((uint16_t *)(0x1FFFFB10)))    /*  PTAT电压值（*10000） */
/**
  * @brief FL ADC Init Sturcture definition
  */
/**
  * @brief FL ADC Init Sturcture definition
  */
typedef struct
{
    /**ADC时钟分频系数配置**/
    uint32_t clockPrescaler;
     /**ADC参考源选择**/
    uint32_t referenceSource;

} FL_ADC_CommonInitTypeDef;

typedef struct
{
    /** 连续转换模式配置 */
    FL_FunState scanacq_continuousMode;
    /** 单次自动转换模式配置 */
    uint32_t scanacq_autoMode;
    /** 通道扫描顺序配置 */
    uint32_t scanacq_Direction;       
    /** 触发源选择 */
    uint32_t triggerSource;
    /** 通道采样时间配置 */
    uint32_t scanACQFastChannelTime;  
    uint32_t scanACQLowChannelTime;
    uint32_t ACQchannelTime;    
    /** 等待模式配置 */
    FL_FunState waitMode;
    /** 覆盖模式配置 */
    FL_FunState overrunMode;
    /** 过采样使能配置 */
    FL_FunState oversamplingMode;
    /** 过采样率配置 */
    uint32_t overSampingMultiplier;
    /** 过采样移位配置 */
    uint32_t oversamplingShift;
    
    
} FL_ADC_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_Exported_Constants ADC Exported Constants
  * @{
  */

#define    ADC_ACQ_ISR_OVR_ID_Pos                                 (17U)
#define    ADC_ACQ_ISR_OVR_ID_Msk                                 (0x1fU << ADC_ACQ_ISR_OVR_ID_Pos)
#define    ADC_ACQ_ISR_OVR_ID                                     ADC_ACQ_ISR_OVR_ID_Msk

#define    ADC_ACQ_ISR_OVR_IF_Pos                                 (16U)
#define    ADC_ACQ_ISR_OVR_IF_Msk                                 (0x1U << ADC_ACQ_ISR_OVR_IF_Pos)
#define    ADC_ACQ_ISR_OVR_IF                                     ADC_ACQ_ISR_OVR_IF_Msk

#define    ADC_ACQ_ISR_SOCIF_Pos                                  (8U)
#define    ADC_ACQ_ISR_SOCIF_Msk                                  (0x1fU << ADC_ACQ_ISR_SOCIF_Pos)
#define    ADC_ACQ_ISR_SOCIF                                      ADC_ACQ_ISR_SOCIF_Msk

#define    ADC_ACQ_ISR_EOCIF_Pos                                  (0U)
#define    ADC_ACQ_ISR_EOCIF_Msk                                  (0x1fU << ADC_ACQ_ISR_EOCIF_Pos)
#define    ADC_ACQ_ISR_EOCIF                                      ADC_ACQ_ISR_EOCIF_Msk

#define    ADC_ACQ_IER_OVRIE_Pos                                  (16U)
#define    ADC_ACQ_IER_OVRIE_Msk                                  (0x1U << ADC_ACQ_IER_OVRIE_Pos)
#define    ADC_ACQ_IER_OVRIE                                      ADC_ACQ_IER_OVRIE_Msk

#define    ADC_ACQ_IER_SOCIE_Pos                                  (8U)
#define    ADC_ACQ_IER_SOCIE_Msk                                  (0x1fU << ADC_ACQ_IER_SOCIE_Pos)
#define    ADC_ACQ_IER_SOCIE                                      ADC_ACQ_IER_SOCIE_Msk

#define    ADC_ACQ_IER_EOCIE_Pos                                  (0U)
#define    ADC_ACQ_IER_EOCIE_Msk                                  (0x1fU << ADC_ACQ_IER_EOCIE_Pos)
#define    ADC_ACQ_IER_EOCIE                                      ADC_ACQ_IER_EOCIE_Msk

#define    ADC_GISR_SCAN_CH_Pos                                   (16U)
#define    ADC_GISR_SCAN_CH_Msk                                   (0x3fU << ADC_GISR_SCAN_CH_Pos)
#define    ADC_GISR_SCAN_CH                                       ADC_GISR_SCAN_CH_Msk

#define    ADC_GISR_ACQ_ID_Pos                                    (8U)
#define    ADC_GISR_ACQ_ID_Msk                                    (0x1fU << ADC_GISR_ACQ_ID_Pos)
#define    ADC_GISR_ACQ_ID                                        ADC_GISR_ACQ_ID_Msk

#define    ADC_GISR_AWD_AH_Pos                                    (6U)
#define    ADC_GISR_AWD_AH_Msk                                    (0x1U << ADC_GISR_AWD_AH_Pos)
#define    ADC_GISR_AWD_AH                                        ADC_GISR_AWD_AH_Msk

#define    ADC_GISR_AWD_UL_Pos                                    (5U)
#define    ADC_GISR_AWD_UL_Msk                                    (0x1U << ADC_GISR_AWD_UL_Pos)
#define    ADC_GISR_AWD_UL                                        ADC_GISR_AWD_UL_Msk

#define    ADC_GISR_ADEN_Pos                                      (4U)
#define    ADC_GISR_ADEN_Msk                                      (0x1U << ADC_GISR_ADEN_Pos)
#define    ADC_GISR_ADEN                                          ADC_GISR_ADEN_Msk

#define    ADC_GISR_BUSY_Pos                                      (3U)
#define    ADC_GISR_BUSY_Msk                                      (0x1U << ADC_GISR_BUSY_Pos)
#define    ADC_GISR_BUSY                                          ADC_GISR_BUSY_Msk

#define    ADC_GISR_EOCNT_Pos                                     (2U)
#define    ADC_GISR_EOCNT_Msk                                     (0x1U << ADC_GISR_EOCNT_Pos)
#define    ADC_GISR_EOCNT                                         ADC_GISR_EOCNT_Msk

#define    ADC_GISR_EOS_Pos                                       (1U)
#define    ADC_GISR_EOS_Msk                                       (0x1U << ADC_GISR_EOS_Pos)
#define    ADC_GISR_EOS                                           ADC_GISR_EOS_Msk

#define    ADC_GIER_AWD_AHIE_Pos                                  (6U)
#define    ADC_GIER_AWD_AHIE_Msk                                  (0x1U << ADC_GIER_AWD_AHIE_Pos)
#define    ADC_GIER_AWD_AHIE                                      ADC_GIER_AWD_AHIE_Msk

#define    ADC_GIER_AWD_ULIE_Pos                                  (5U)
#define    ADC_GIER_AWD_ULIE_Msk                                  (0x1U << ADC_GIER_AWD_ULIE_Pos)
#define    ADC_GIER_AWD_ULIE                                      ADC_GIER_AWD_ULIE_Msk

#define    ADC_GIER_EOCNTIE_Pos                                   (2U)
#define    ADC_GIER_EOCNTIE_Msk                                   (0x1U << ADC_GIER_EOCNTIE_Pos)
#define    ADC_GIER_EOCNTIE                                       ADC_GIER_EOCNTIE_Msk

#define    ADC_GIER_EOSIE_Pos                                     (1U)
#define    ADC_GIER_EOSIE_Msk                                     (0x1U << ADC_GIER_EOSIE_Pos)
#define    ADC_GIER_EOSIE                                         ADC_GIER_EOSIE_Msk

#define    ADC_CR1_ACQEN_Pos                                      (16U)
#define    ADC_CR1_ACQEN_Msk                                      (0x1fU << ADC_CR1_ACQEN_Pos)
#define    ADC_CR1_ACQEN                                          ADC_CR1_ACQEN_Msk

#define    ADC_CR1_SCH_SWRST_Pos                                  (2U)
#define    ADC_CR1_SCH_SWRST_Msk                                  (0x1U << ADC_CR1_SCH_SWRST_Pos)
#define    ADC_CR1_SCH_SWRST                                      ADC_CR1_SCH_SWRST_Msk

#define    ADC_CR1_RR_SWRST_Pos                                   (1U)
#define    ADC_CR1_RR_SWRST_Msk                                   (0x1U << ADC_CR1_RR_SWRST_Pos)
#define    ADC_CR1_RR_SWRST                                       ADC_CR1_RR_SWRST_Msk

#define    ADC_CR1_ADEN_Pos                                       (0U)
#define    ADC_CR1_ADEN_Msk                                       (0x1U << ADC_CR1_ADEN_Pos)
#define    ADC_CR1_ADEN                                           ADC_CR1_ADEN_Msk

#define    ADC_CR2_SWTRIG_Pos                                     (0U)
#define    ADC_CR2_SWTRIG_Msk                                     (0x1fU << ADC_CR2_SWTRIG_Pos)
#define    ADC_CR2_SWTRIG                                         ADC_CR2_SWTRIG_Msk

#define    ADC_CFGR1_RPTLEN_Pos                                   (16U)
#define    ADC_CFGR1_RPTLEN_Msk                                   (0xffffU << ADC_CFGR1_RPTLEN_Pos)
#define    ADC_CFGR1_RPTLEN                                       ADC_CFGR1_RPTLEN_Msk

#define    ADC_CFGR1_CTRL_BOOST_Pos                               (9U)
#define    ADC_CFGR1_CTRL_BOOST_Msk                               (0x1U << ADC_CFGR1_CTRL_BOOST_Pos)
#define    ADC_CFGR1_CTRL_BOOST                                   ADC_CFGR1_CTRL_BOOST_Msk

#define    ADC_CFGR1_SOCIF_CFG_Pos                                (8U)
#define    ADC_CFGR1_SOCIF_CFG_Msk                                (0x1U << ADC_CFGR1_SOCIF_CFG_Pos)
#define    ADC_CFGR1_SOCIF_CFG                                    ADC_CFGR1_SOCIF_CFG_Msk

#define    ADC_CFGR1_PCLK_PSC_Pos                                 (5U)
#define    ADC_CFGR1_PCLK_PSC_Msk                                 (0x7U << ADC_CFGR1_PCLK_PSC_Pos)
#define    ADC_CFGR1_PCLK_PSC                                     ADC_CFGR1_PCLK_PSC_Msk

#define    ADC_CFGR1_VCM_CTRL_Pos                                 (4U)
#define    ADC_CFGR1_VCM_CTRL_Msk                                 (0x1U << ADC_CFGR1_VCM_CTRL_Pos)
#define    ADC_CFGR1_VCM_CTRL                                     ADC_CFGR1_VCM_CTRL_Msk

#define    ADC_CFGR1_INJ_MODE_Pos                                 (3U)
#define    ADC_CFGR1_INJ_MODE_Msk                                 (0x1U << ADC_CFGR1_INJ_MODE_Pos)
#define    ADC_CFGR1_INJ_MODE                                     ADC_CFGR1_INJ_MODE_Msk

#define    ADC_CFGR1_REFNSEL_Pos                                  (2U)
#define    ADC_CFGR1_REFNSEL_Msk                                  (0x1U << ADC_CFGR1_REFNSEL_Pos)
#define    ADC_CFGR1_REFNSEL                                      ADC_CFGR1_REFNSEL_Msk

#define    ADC_CFGR1_PEFSEL_Pos                                   (0U)
#define    ADC_CFGR1_PEFSEL_Msk                                   (0x1U << ADC_CFGR1_PEFSEL_Pos)
#define    ADC_CFGR1_PEFSEL                                       ADC_CFGR1_PEFSEL_Msk

#define    ADC_CFGR2_AVGR_OVSS_Pos                                (21U)
#define    ADC_CFGR2_AVGR_OVSS_Msk                                (0xfU << ADC_CFGR2_AVGR_OVSS_Pos)
#define    ADC_CFGR2_AVGR_OVSS                                    ADC_CFGR2_AVGR_OVSS_Msk

#define    ADC_CFGR2_AVGR_OVSR_Pos                                (18U)
#define    ADC_CFGR2_AVGR_OVSR_Msk                                (0x7U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    ADC_CFGR2_AVGR_OVSR                                    ADC_CFGR2_AVGR_OVSR_Msk

#define    ADC_CFGR2_AVGEN_Pos                                    (16U)
#define    ADC_CFGR2_AVGEN_Msk                                    (0x3U << ADC_CFGR2_AVGEN_Pos)
#define    ADC_CFGR2_AVGEN                                        ADC_CFGR2_AVGEN_Msk

#define    ADC_CFGR2_WAIT_F_Pos                                   (11U)
#define    ADC_CFGR2_WAIT_F_Msk                                   (0x1U << ADC_CFGR2_WAIT_F_Pos)
#define    ADC_CFGR2_WAIT_F                                       ADC_CFGR2_WAIT_F_Msk

#define    ADC_CFGR2_AUTO_SCAN_Pos                                (10U)
#define    ADC_CFGR2_AUTO_SCAN_Msk                                (0x1U << ADC_CFGR2_AUTO_SCAN_Pos)
#define    ADC_CFGR2_AUTO_SCAN                                    ADC_CFGR2_AUTO_SCAN_Msk

#define    ADC_CFGR2_CONT_MOD_Pos                                 (9U)
#define    ADC_CFGR2_CONT_MOD_Msk                                 (0x1U << ADC_CFGR2_CONT_MOD_Pos)
#define    ADC_CFGR2_CONT_MOD                                     ADC_CFGR2_CONT_MOD_Msk

#define    ADC_CFGR2_OVRM_Pos                                     (8U)
#define    ADC_CFGR2_OVRM_Msk                                     (0x1U << ADC_CFGR2_OVRM_Pos)
#define    ADC_CFGR2_OVRM                                         ADC_CFGR2_OVRM_Msk

#define    ADC_CFGR2_SCANDIR_Pos                                  (2U)
#define    ADC_CFGR2_SCANDIR_Msk                                  (0x1U << ADC_CFGR2_SCANDIR_Pos)
#define    ADC_CFGR2_SCANDIR                                      ADC_CFGR2_SCANDIR_Msk

#define    ADC_CFGR2_DMAEN_Pos                                    (0U)
#define    ADC_CFGR2_DMAEN_Msk                                    (0x1U << ADC_CFGR2_DMAEN_Pos)
#define    ADC_CFGR2_DMAEN                                        ADC_CFGR2_DMAEN_Msk

#define    ADC_OSR_CALEN_Pos                                      (31U)
#define    ADC_OSR_CALEN_Msk                                      (0x1U << ADC_OSR_CALEN_Pos)
#define    ADC_OSR_CALEN                                          ADC_OSR_CALEN_Msk

#define    ADC_OSR_OS_CALI_SLOW_Pos                               (16U)
#define    ADC_OSR_OS_CALI_SLOW_Msk                               (0x1fffU << ADC_OSR_OS_CALI_SLOW_Pos)
#define    ADC_OSR_OS_CALI_SLOW                                   ADC_OSR_OS_CALI_SLOW_Msk

#define    ADC_OSR_OS_CALI_Fast_Pos                               (0U)
#define    ADC_OSR_OS_CALI_Fast_Msk                               (0x1fffU << ADC_OSR_OS_CALI_Fast_Pos)
#define    ADC_OSR_OS_CALI_Fast                                   ADC_OSR_OS_CALI_Fast_Msk

#define    ADC_ACQ_SR_REQ_Pos                                     (0U)
#define    ADC_ACQ_SR_REQ_Msk                                     (0x1fU << ADC_ACQ_SR_REQ_Pos)
#define    ADC_ACQ_SR_REQ                                         ADC_ACQ_SR_REQ_Msk

#define    ADC_ACQ_SACR_CHEN_Pos                                  (0U)
#define    ADC_ACQ_SACR_CHEN_Msk                                  (0xffffffffU << ADC_ACQ_SACR_CHEN_Pos)
#define    ADC_ACQ_SACR_CHEN                                      ADC_ACQ_SACR_CHEN_Msk

#define    ADC_HLTR_AWD_HT_Pos                                    (16U)
#define    ADC_HLTR_AWD_HT_Msk                                    (0xffffU << ADC_HLTR_AWD_HT_Pos)
#define    ADC_HLTR_AWD_HT                                        ADC_HLTR_AWD_HT_Msk

#define    ADC_HLTR_AWD_LT_Pos                                    (0U)
#define    ADC_HLTR_AWD_LT_Msk                                    (0xffffU << ADC_HLTR_AWD_LT_Pos)
#define    ADC_HLTR_AWD_LT                                        ADC_HLTR_AWD_LT_Msk

#define    ADC_AWDCR_CHEN_Pos                                     (0U)
#define    ADC_AWDCR_CHEN_Msk                                     (0xffffffffU << ADC_AWDCR_CHEN_Pos)
#define    ADC_AWDCR_CHEN                                         ADC_AWDCR_CHEN_Msk

#define    ADC_ACQ0_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ0_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ0_CR_CHSEL_Pos)
#define    ADC_ACQ0_CR_CHSEL                                      ADC_ACQ0_CR_CHSEL_Msk

#define    ADC_ACQ0_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ0_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    ADC_ACQ0_CR_TRIGSEL                                    ADC_ACQ0_CR_TRIGSEL_Msk

#define    ADC_ACQ0_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ0_CR_SMTS_Msk                                   (0xfU << ADC_ACQ0_CR_SMTS_Pos)
#define    ADC_ACQ0_CR_SMTS                                       ADC_ACQ0_CR_SMTS_Msk

#define    ADC_ACQ1_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ1_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ1_CR_CHSEL_Pos)
#define    ADC_ACQ1_CR_CHSEL                                      ADC_ACQ1_CR_CHSEL_Msk

#define    ADC_ACQ1_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ1_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    ADC_ACQ1_CR_TRIGSEL                                    ADC_ACQ1_CR_TRIGSEL_Msk

#define    ADC_ACQ1_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ1_CR_SMTS_Msk                                   (0xfU << ADC_ACQ1_CR_SMTS_Pos)
#define    ADC_ACQ1_CR_SMTS                                       ADC_ACQ1_CR_SMTS_Msk

#define    ADC_ACQ2_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ2_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ2_CR_CHSEL_Pos)
#define    ADC_ACQ2_CR_CHSEL                                      ADC_ACQ2_CR_CHSEL_Msk

#define    ADC_ACQ2_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ2_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    ADC_ACQ2_CR_TRIGSEL                                    ADC_ACQ2_CR_TRIGSEL_Msk

#define    ADC_ACQ2_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ2_CR_SMTS_Msk                                   (0xfU << ADC_ACQ2_CR_SMTS_Pos)
#define    ADC_ACQ2_CR_SMTS                                       ADC_ACQ2_CR_SMTS_Msk

#define    ADC_ACQ3_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ3_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ3_CR_CHSEL_Pos)
#define    ADC_ACQ3_CR_CHSEL                                      ADC_ACQ3_CR_CHSEL_Msk

#define    ADC_ACQ3_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ3_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    ADC_ACQ3_CR_TRIGSEL                                    ADC_ACQ3_CR_TRIGSEL_Msk

#define    ADC_ACQ3_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ3_CR_SMTS_Msk                                   (0xfU << ADC_ACQ3_CR_SMTS_Pos)
#define    ADC_ACQ3_CR_SMTS                                       ADC_ACQ3_CR_SMTS_Msk

#define    ADC_SCANACQ_CR_SMTS_FAST_Pos                           (16U)
#define    ADC_SCANACQ_CR_SMTS_FAST_Msk                           (0xfU << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    ADC_SCANACQ_CR_SMTS_FAST                               ADC_SCANACQ_CR_SMTS_FAST_Msk

#define    ADC_SCANACQ_CR_TRIGSEL_Pos                             (4U)
#define    ADC_SCANACQ_CR_TRIGSEL_Msk                             (0x1fU << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    ADC_SCANACQ_CR_TRIGSEL                                 ADC_SCANACQ_CR_TRIGSEL_Msk

#define    ADC_SCANACQ_CR_SMTS_SLOW_Pos                           (0U)
#define    ADC_SCANACQ_CR_SMTS_SLOW_Msk                           (0xfU << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    ADC_SCANACQ_CR_SMTS_SLOW                               ADC_SCANACQ_CR_SMTS_SLOW_Msk

#define    ADC_CHISR_IF_Pos                                       (0U)
#define    ADC_CHISR_IF_Msk                                       (0xffffffffU << ADC_CHISR_IF_Pos)
#define    ADC_CHISR_IF                                           ADC_CHISR_IF_Msk

#define    ADC_CHDMA_DR_CHID_Pos                                  (16U)
#define    ADC_CHDMA_DR_CHID_Msk                                  (0x1fU << ADC_CHDMA_DR_CHID_Pos)
#define    ADC_CHDMA_DR_CHID                                      ADC_CHDMA_DR_CHID_Msk

#define    ADC_CHDMA_DR_RESULT_Pos                                (0U)
#define    ADC_CHDMA_DR_RESULT_Msk                                (0xffffU << ADC_CHDMA_DR_RESULT_Pos)
#define    ADC_CHDMA_DR_RESULT                                    ADC_CHDMA_DR_RESULT_Msk

#define    ADC_CH0DR_RESULT_Pos                                   (0U)
#define    ADC_CH0DR_RESULT_Msk                                   (0xffffU << ADC_CH0DR_RESULT_Pos)
#define    ADC_CH0DR_RESULT                                       ADC_CH0DR_RESULT_Msk

#define    ADC_CH1DR_RESULT_Pos                                   (0U)
#define    ADC_CH1DR_RESULT_Msk                                   (0xffffU << ADC_CH1DR_RESULT_Pos)
#define    ADC_CH1DR_RESULT                                       ADC_CH1DR_RESULT_Msk

#define    ADC_CH2DR_RESULT_Pos                                   (0U)
#define    ADC_CH2DR_RESULT_Msk                                   (0xffffU << ADC_CH2DR_RESULT_Pos)
#define    ADC_CH2DR_RESULT                                       ADC_CH2DR_RESULT_Msk

#define    ADC_CH3DR_RESULT_Pos                                   (0U)
#define    ADC_CH3DR_RESULT_Msk                                   (0xffffU << ADC_CH3DR_RESULT_Pos)
#define    ADC_CH3DR_RESULT                                       ADC_CH3DR_RESULT_Msk

#define    ADC_CH4DR_RESULT_Pos                                   (0U)
#define    ADC_CH4DR_RESULT_Msk                                   (0xffffU << ADC_CH4DR_RESULT_Pos)
#define    ADC_CH4DR_RESULT                                       ADC_CH4DR_RESULT_Msk

#define    ADC_CH5DR_RESULT_Pos                                   (0U)
#define    ADC_CH5DR_RESULT_Msk                                   (0xffffU << ADC_CH5DR_RESULT_Pos)
#define    ADC_CH5DR_RESULT                                       ADC_CH5DR_RESULT_Msk

#define    ADC_CH6DR_RESULT_Pos                                   (0U)
#define    ADC_CH6DR_RESULT_Msk                                   (0xffffU << ADC_CH6DR_RESULT_Pos)
#define    ADC_CH6DR_RESULT                                       ADC_CH6DR_RESULT_Msk

#define    ADC_CH7DR_RESULT_Pos                                   (0U)
#define    ADC_CH7DR_RESULT_Msk                                   (0xffffU << ADC_CH7DR_RESULT_Pos)
#define    ADC_CH7DR_RESULT                                       ADC_CH7DR_RESULT_Msk

#define    ADC_CH8DR_RESULT_Pos                                   (0U)
#define    ADC_CH8DR_RESULT_Msk                                   (0xffffU << ADC_CH8DR_RESULT_Pos)
#define    ADC_CH8DR_RESULT                                       ADC_CH8DR_RESULT_Msk

#define    ADC_CH9DR_RESULT_Pos                                   (0U)
#define    ADC_CH9DR_RESULT_Msk                                   (0xffffU << ADC_CH9DR_RESULT_Pos)
#define    ADC_CH9DR_RESULT                                       ADC_CH9DR_RESULT_Msk

#define    ADC_CH10DR_RESULT_Pos                                  (0U)
#define    ADC_CH10DR_RESULT_Msk                                  (0xffffU << ADC_CH10DR_RESULT_Pos)
#define    ADC_CH10DR_RESULT                                      ADC_CH10DR_RESULT_Msk

#define    ADC_CH11DR_RESULT_Pos                                  (0U)
#define    ADC_CH11DR_RESULT_Msk                                  (0xffffU << ADC_CH11DR_RESULT_Pos)
#define    ADC_CH11DR_RESULT                                      ADC_CH11DR_RESULT_Msk

#define    ADC_CH12DR_RESULT_Pos                                  (0U)
#define    ADC_CH12DR_RESULT_Msk                                  (0xffffU << ADC_CH12DR_RESULT_Pos)
#define    ADC_CH12DR_RESULT                                      ADC_CH12DR_RESULT_Msk

#define    ADC_CH13DR_RESULT_Pos                                  (0U)
#define    ADC_CH13DR_RESULT_Msk                                  (0xffffU << ADC_CH13DR_RESULT_Pos)
#define    ADC_CH13DR_RESULT                                      ADC_CH13DR_RESULT_Msk

#define    ADC_CH14DR_RESULT_Pos                                  (0U)
#define    ADC_CH14DR_RESULT_Msk                                  (0xffffU << ADC_CH14DR_RESULT_Pos)
#define    ADC_CH14DR_RESULT                                      ADC_CH14DR_RESULT_Msk

#define    ADC_CH15DR_RESULT_Pos                                  (0U)
#define    ADC_CH15DR_RESULT_Msk                                  (0xffffU << ADC_CH15DR_RESULT_Pos)
#define    ADC_CH15DR_RESULT                                      ADC_CH15DR_RESULT_Msk

#define    ADC_CH16DR_RESULT_Pos                                  (0U)
#define    ADC_CH16DR_RESULT_Msk                                  (0xffffU << ADC_CH16DR_RESULT_Pos)
#define    ADC_CH16DR_RESULT                                      ADC_CH16DR_RESULT_Msk

#define    ADC_CH17DR_RESULT_Pos                                  (0U)
#define    ADC_CH17DR_RESULT_Msk                                  (0xffffU << ADC_CH17DR_RESULT_Pos)
#define    ADC_CH17DR_RESULT                                      ADC_CH17DR_RESULT_Msk

#define    ADC_CH18DR_RESULT_Pos                                  (0U)
#define    ADC_CH18DR_RESULT_Msk                                  (0xffffU << ADC_CH18DR_RESULT_Pos)
#define    ADC_CH18DR_RESULT                                      ADC_CH18DR_RESULT_Msk

#define    ADC_CH19DR_RESULT_Pos                                  (0U)
#define    ADC_CH19DR_RESULT_Msk                                  (0xffffU << ADC_CH19DR_RESULT_Pos)
#define    ADC_CH19DR_RESULT                                      ADC_CH19DR_RESULT_Msk

#define    ADC_CH20DR_RESULT_Pos                                  (0U)
#define    ADC_CH20DR_RESULT_Msk                                  (0xffffU << ADC_CH20DR_RESULT_Pos)
#define    ADC_CH20DR_RESULT                                      ADC_CH20DR_RESULT_Msk

#define    ADC_CH21DR_RESULT_Pos                                  (0U)
#define    ADC_CH21DR_RESULT_Msk                                  (0xffffU << ADC_CH21DR_RESULT_Pos)
#define    ADC_CH21DR_RESULT                                      ADC_CH21DR_RESULT_Msk

#define    ADC_CH22DR_RESULT_Pos                                  (0U)
#define    ADC_CH22DR_RESULT_Msk                                  (0xffffU << ADC_CH22DR_RESULT_Pos)
#define    ADC_CH22DR_RESULT                                      ADC_CH22DR_RESULT_Msk

#define    ADC_CH23DR_RESULT_Pos                                  (0U)
#define    ADC_CH23DR_RESULT_Msk                                  (0xffffU << ADC_CH23DR_RESULT_Pos)
#define    ADC_CH23DR_RESULT                                      ADC_CH23DR_RESULT_Msk

#define    ADC_CH24DR_RESULT_Pos                                  (0U)
#define    ADC_CH24DR_RESULT_Msk                                  (0xffffU << ADC_CH24DR_RESULT_Pos)
#define    ADC_CH24DR_RESULT                                      ADC_CH24DR_RESULT_Msk

#define    ADC_CH25DR_RESULT_Pos                                  (0U)
#define    ADC_CH25DR_RESULT_Msk                                  (0xffffU << ADC_CH25DR_RESULT_Pos)
#define    ADC_CH25DR_RESULT                                      ADC_CH25DR_RESULT_Msk

#define    ADC_CH26DR_RESULT_Pos                                  (0U)
#define    ADC_CH26DR_RESULT_Msk                                  (0xffffU << ADC_CH26DR_RESULT_Pos)
#define    ADC_CH26DR_RESULT                                      ADC_CH26DR_RESULT_Msk

#define    ADC_CH27DR_RESULT_Pos                                  (0U)
#define    ADC_CH27DR_RESULT_Msk                                  (0xffffU << ADC_CH27DR_RESULT_Pos)
#define    ADC_CH27DR_RESULT                                      ADC_CH27DR_RESULT_Msk

#define    ADC_CH29DR_RESULT_Pos                                  (0U)
#define    ADC_CH29DR_RESULT_Msk                                  (0xffffU << ADC_CH29DR_RESULT_Pos)
#define    ADC_CH29DR_RESULT                                      ADC_CH29DR_RESULT_Msk

#define    ADC_CH30DR_RESULT_Pos                                  (0U)
#define    ADC_CH30DR_RESULT_Msk                                  (0xffffU << ADC_CH30DR_RESULT_Pos)
#define    ADC_CH30DR_RESULT                                      ADC_CH30DR_RESULT_Msk

#define    ADC_CH31DR_RESULT_Pos                                  (0U)
#define    ADC_CH31DR_RESULT_Msk                                  (0xffffU << ADC_CH31DR_RESULT_Pos)
#define    ADC_CH31DR_RESULT                                      ADC_CH31DR_RESULT_Msk



#define    FL_ADC_ACQ0                                            (0x1U << 0U)
#define    FL_ADC_ACQ1                                            (0x1U << 1U)
#define    FL_ADC_ACQ2                                            (0x1U << 2U)
#define    FL_ADC_ACQ3                                            (0x1U << 3U)
#define    FL_ADC_SCAN_ACQ                                        (0x1U << 4U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0                 (0x0U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1                 (0x1U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2                 (0x2U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3                 (0x3U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4                 (0x4U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5                 (0x5U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6                 (0x6U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7                 (0x7U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8                 (0x8U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9                 (0x9U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10                (0xaU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11                (0xbU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH12                (0xcU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH13                (0xdU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH14                (0xeU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH15                (0xfU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH16                (0x10U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH17                (0x11U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH18                (0x12U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH19                (0x13U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH20                (0x14U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH21                (0x15U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH22                (0x16U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH23                (0x17U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS                  (0x18U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF               (0x19U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_DAC                 (0x1aU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TSICAP              (0x1bU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP               (0x1dU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_FAST          (0x1eU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_SLOW          (0x1fU << 9U)

#define    FL_ADC_SCANACQ_EXTERNAL_CH0                            (0x1U << 0U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH1                            (0x1U << 1U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH2                            (0x1U << 2U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH3                            (0x1U << 3U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH4                            (0x1U << 4U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH5                            (0x1U << 5U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH6                            (0x1U << 6U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH7                            (0x1U << 7U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH8                            (0x1U << 8U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH9                            (0x1U << 9U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH10                           (0x1U << 10U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH11                           (0x1U << 11U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH12                           (0x1U << 12U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH13                           (0x1U << 13U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH14                           (0x1U << 14U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH15                           (0x1U << 15U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH16                           (0x1U << 16U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH17                           (0x1U << 17U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH18                           (0x1U << 18U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH19                           (0x1U << 19U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH20                           (0x1U << 20U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH21                           (0x1U << 21U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH22                           (0x1U << 22U)
#define    FL_ADC_SCANACQ_EXTERNAL_CH23                           (0x1U << 23U)
#define    FL_ADC_SCANACQ_INTERNAL_TS                             (0x1U << 24U)
#define    FL_ADC_SCANACQ_INTERNAL_AVREF                          (0x1U << 25U)
#define    FL_ADC_SCANACQ_INTERNAL_DAC                            (0x1U << 26U)
#define    FL_ADC_SCANACQ_INTERNAL_TSICAP                         (0x1U << 27U)
#define    FL_ADC_SCANACQ_INTERNAL_VREFP                          (0x1U << 29U)
#define    FL_ADC_SCANACQ_INTERNAL_VREFN_FAST                     (0x1U << 30U)
#define    FL_ADC_SCANACQ_INTERNAL_VREFN_SLOW                     (0x1U << 31U)
#define    FL_ADC_ALL_CHANNEL                                     (0xffffffffU << 0U)
#define    FL_ADC_ACQ_TRGI_SOFE_TRGO                              (0x0U << 4U)
#define    FL_ADC_ACQ_TRGI_ATIM_TRGO                              (0x1U << 4U)
#define    FL_ADC_ACQ_TRGI_ATIM_TRGO2                             (0x2U << 4U)
#define    FL_ADC_ACQ_TRGI_BSTIM_TRGO                             (0x3U << 4U)
#define    FL_ADC_ACQ_TRGI_LPTIM_TRGO                             (0x4U << 4U)
#define    FL_ADC_ACQ_TRGI_RTC_TRGO                               (0x5U << 4U)
#define    FL_ADC_ACQ_TRGI_COMP1_TRGO                             (0x6U << 4U)
#define    FL_ADC_ACQ_TRGI_COMP2_TRGO                             (0x7U << 4U)
#define    FL_ADC_ACQ_TRGI_TAU00_TRGO                             (0x8U << 4U)
#define    FL_ADC_ACQ_TRGI_TAU01_TRGO                             (0x9U << 4U)
#define    FL_ADC_ACQ_TRGI_TAU02_TRGO                             (0xaU << 4U)
#define    FL_ADC_ACQ_TRGI_TAU03_TRGO                             (0xbU << 4U)
#define    FL_ADC_ACQ_TRGI_TAU04_TRGO                             (0xcU << 4U)
#define    FL_ADC_ACQ_TRGI_TAU05_TRGO                             (0xdU << 4U)
#define    FL_ADC_ACQ_TRGI_TAU06_TRGO                             (0xeU << 4U)
#define    FL_ADC_ACQ_TRGI_TAU07_TRGO                             (0xfU << 4U)
#define    FL_ADC_ACQ_TRGI_TAU10_TRGO                             (0x10U << 4U)
#define    FL_ADC_ACQ_TRGI_TAU11_TRGO                             (0x11U << 4U)
#define    FL_ADC_ACQ_TRGI_TAU12_TRGO                             (0x12U << 4U)
#define    FL_ADC_ACQ_TRGI_TAU13_TRGO                             (0x13U << 4U)
#define    FL_ADC_ACQ_TRGI_TAU14_TRGO                             (0x14U << 4U)
#define    FL_ADC_ACQ_TRGI_TAU15_TRGO                             (0x15U << 4U)
#define    FL_ADC_ACQ_TRGI_TAU16_TRGO                             (0x16U << 4U)
#define    FL_ADC_ACQ_TRGI_TAU17_TRGO                             (0x17U << 4U)
#define    FL_ADC_ACQ_SAMPLING_TIME_1_ADCCLK                      (0x0U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK                      (0x1U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK                      (0x2U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK                      (0x3U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK                     (0x4U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK                     (0x5U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK                     (0x6U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK                     (0x7U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK                     (0x8U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK                     (0x9U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK                    (0xaU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK                    (0xbU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK                    (0xcU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK                    (0xdU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK                    (0xeU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK                    (0xfU << 0U)
#define    FL_ADC_EXTERNAL_CH0                                    (0x1U << 0U)
#define    FL_ADC_EXTERNAL_CH1                                    (0x1U << 1U)
#define    FL_ADC_EXTERNAL_CH2                                    (0x1U << 2U)
#define    FL_ADC_EXTERNAL_CH3                                    (0x1U << 3U)
#define    FL_ADC_EXTERNAL_CH4                                    (0x1U << 4U)
#define    FL_ADC_EXTERNAL_CH5                                    (0x1U << 5U)
#define    FL_ADC_EXTERNAL_CH6                                    (0x1U << 6U)
#define    FL_ADC_EXTERNAL_CH7                                    (0x1U << 7U)
#define    FL_ADC_EXTERNAL_CH8                                    (0x1U << 8U)
#define    FL_ADC_EXTERNAL_CH9                                    (0x1U << 9U)
#define    FL_ADC_EXTERNAL_CH10                                   (0x1U << 10U)
#define    FL_ADC_EXTERNAL_CH11                                   (0x1U << 11U)
#define    FL_ADC_EXTERNAL_CH12                                   (0x1U << 12U)
#define    FL_ADC_EXTERNAL_CH13                                   (0x1U << 13U)
#define    FL_ADC_EXTERNAL_CH14                                   (0x1U << 14U)
#define    FL_ADC_EXTERNAL_CH15                                   (0x1U << 15U)
#define    FL_ADC_EXTERNAL_CH16                                   (0x1U << 16U)
#define    FL_ADC_EXTERNAL_CH17                                   (0x1U << 17U)
#define    FL_ADC_EXTERNAL_CH18                                   (0x1U << 18U)
#define    FL_ADC_EXTERNAL_CH19                                   (0x1U << 19U)
#define    FL_ADC_EXTERNAL_CH20                                   (0x1U << 20U)
#define    FL_ADC_EXTERNAL_CH21                                   (0x1U << 21U)
#define    FL_ADC_EXTERNAL_CH22                                   (0x1U << 22U)
#define    FL_ADC_EXTERNAL_CH23                                   (0x1U << 23U)
#define    FL_ADC_INTERNAL_TS                                     (0x1U << 24U)
#define    FL_ADC_INTERNAL_AVREF                                  (0x1U << 25U)
#define    FL_ADC_INTERNAL_DAC                                    (0x1U << 26U)
#define    FL_ADC_INTERNAL_TSICAP                                 (0x1U << 27U)
#define    FL_ADC_INTERNAL_VREFP                                  (0x1U << 29U)
#define    FL_ADC_INTERNAL_VREFN_FAST                             (0x1U << 30U)
#define    FL_ADC_INTERNAL_VREFN_SLOW                             (0x1U << 31U)



#define    FL_ADC_BOOTSTRAP_Voltage_VDDA                          (0x0U << ADC_CFGR1_CTRL_BOOST_Pos)
#define    FL_ADC_BOOTSTRAP_Voltage_2P5V                          (0x1U << ADC_CFGR1_CTRL_BOOST_Pos)


#define    FL_ADC_SOC_EDGE_MODE_RISE                              (0x0U << ADC_CFGR1_SOCIF_CFG_Pos)
#define    FL_ADC_SOC_EDGE_MODE_FALL                              (0x1U << ADC_CFGR1_SOCIF_CFG_Pos)


#define    FL_ADC_APBCLK_PSC_DIV1                                 (0x1U << ADC_CFGR1_PCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV2                                 (0x2U << ADC_CFGR1_PCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV3                                 (0x3U << ADC_CFGR1_PCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV4                                 (0x4U << ADC_CFGR1_PCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV5                                 (0x5U << ADC_CFGR1_PCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV6                                 (0x6U << ADC_CFGR1_PCLK_PSC_Pos)


#define    FL_ADC_VCM_MODE_PERIODIC                               (0x0U << ADC_CFGR1_VCM_CTRL_Pos)
#define    FL_ADC_VCM_MODE_CONTINUOUS                             (0x1U << ADC_CFGR1_VCM_CTRL_Pos)


#define    FL_ADC_INJ_MODE_DELAY                                  (0x0U << ADC_CFGR1_INJ_MODE_Pos)
#define    FL_ADC_INJ_MODE_IMMEDIA                                (0x1U << ADC_CFGR1_INJ_MODE_Pos)


#define    FL_ADC_Negative_Peference_VSSA                         (0x0U << ADC_CFGR1_REFNSEL_Pos)
#define    FL_ADC_Negative_Peference_VREFN                        (0x1U << ADC_CFGR1_REFNSEL_Pos)


#define    FL_ADC_REF_SOURCE_VDDA                                 (0x0U << ADC_CFGR1_PEFSEL_Pos)
#define    FL_ADC_REF_SOURCE_VREFP                                (0x1U << ADC_CFGR1_PEFSEL_Pos)


#define    FL_ADC_OVERSAMPLING_SHIFT_0B                           (0x0U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_1B                           (0x1U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_2B                           (0x2U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_3B                           (0x3U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_4B                           (0x4U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_5B                           (0x5U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_6B                           (0x6U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_7B                           (0x7U << ADC_CFGR2_AVGR_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_8B                           (0x8U << ADC_CFGR2_AVGR_OVSS_Pos)


#define    FL_ADC_OVERSAMPLING_MUL_2X                             (0x0U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_4X                             (0x1U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_8X                             (0x2U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_16X                            (0x3U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_32X                            (0x4U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_64X                            (0x5U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_128X                           (0x6U << ADC_CFGR2_AVGR_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_256X                           (0x7U << ADC_CFGR2_AVGR_OVSR_Pos)


#define    FL_ADC_OVERSAMPLING_MODE_DISABLE                       (0x0U << ADC_CFGR2_AVGEN_Pos)
#define    FL_ADC_OVERSAMPLING_MODE_ENABLE_AVERAGE                (0x1U << ADC_CFGR2_AVGEN_Pos)
#define    FL_ADC_OVERSAMPLING_MODE_ENABLE_RESERVE                (0x2U << ADC_CFGR2_AVGEN_Pos)


#define    FL_ADC_SCANACQ_CONV_MODE_SEMIAUTO                      (0x0U << ADC_CFGR2_AUTO_SCAN_Pos)
#define    FL_ADC_SCANACQ_CONV_MODE_AUTO                          (0x1U << ADC_CFGR2_AUTO_SCAN_Pos)


#define    FL_ADC_SCANACQ_SCAN_DIR_BACKWARD                       (0x0U << ADC_CFGR2_SCANDIR_Pos)
#define    FL_ADC_SCANACQ_SCAN_DIR_FORWARD                        (0x1U << ADC_CFGR2_SCANDIR_Pos)


#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_1_ADCCLK             (0x0U << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_2_ADCCLK             (0x1U << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_4_ADCCLK             (0x2U << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_8_ADCCLK             (0x3U << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_12_ADCCLK            (0x4U << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_16_ADCCLK            (0x5U << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_32_ADCCLK            (0x6U << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_64_ADCCLK            (0x7U << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_80_ADCCLK            (0x8U << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_96_ADCCLK            (0x9U << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_128_ADCCLK           (0xaU << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_160_ADCCLK           (0xbU << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_192_ADCCLK           (0xcU << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_256_ADCCLK           (0xdU << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_320_ADCCLK           (0xeU << ADC_SCANACQ_CR_SMTS_FAST_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_FAST_TIME_512_ADCCLK           (0xfU << ADC_SCANACQ_CR_SMTS_FAST_Pos)


#define    FL_ADC_SCANACQ_TRGI_SOFE_TRGO                          (0x0U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_ATIM_TRGO                          (0x1U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_ATIM_TRGO2                         (0x2U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_BSTIM_TRGO                         (0x3U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_LPTIM_TRGO                         (0x4U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_RTC_TRGO                           (0x5U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_COMP1_TRGO                         (0x6U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_COMP2_TRGO                         (0x7U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG0_0                        (0x8U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG0_1                        (0x9U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG0_2                        (0xaU << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG0_3                        (0xbU << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG0_4                        (0xcU << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG0_5                        (0xdU << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG0_6                        (0xeU << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG0_7                        (0xfU << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG1_0                        (0x10U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG1_1                        (0x11U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG1_2                        (0x12U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG1_3                        (0x13U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG1_4                        (0x14U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG1_5                        (0x15U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG1_6                        (0x16U << ADC_SCANACQ_CR_TRIGSEL_Pos)
#define    FL_ADC_SCANACQ_TRGI_TAU0_TRG1_7                        (0x17U << ADC_SCANACQ_CR_TRIGSEL_Pos)


#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_1_ADCCLK              (0x0U << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_2_ADCCLK              (0x1U << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_4_ADCCLK              (0x2U << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_8_ADCCLK              (0x3U << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_12_ADCCLK             (0x4U << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_16_ADCCLK             (0x5U << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_32_ADCCLK             (0x6U << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_64_ADCCLK             (0x7U << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_80_ADCCLK             (0x8U << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_96_ADCCLK             (0x9U << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_128_ADCCLK            (0xaU << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_160_ADCCLK            (0xbU << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_192_ADCCLK            (0xcU << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_256_ADCCLK            (0xdU << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_320_ADCCLK            (0xeU << ADC_SCANACQ_CR_SMTS_SLOW_Pos)
#define    FL_ADC_SCANACQ_SAMPLING_LOW_TIME_512_ADCCLK            (0xfU << ADC_SCANACQ_CR_SMTS_SLOW_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_Exported_Functions ADC Exported Functions
  * @{
  */

/**
  * @brief    Get ADC Data Overrun Channel ID
  * @rmtoll   ACQ_ISR    OVR_ID    FL_ADC_ReadOverrunChannelID
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadOverrunChannelID(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_ISR, (0x1fU << 17U)) >> 17U);
}

/**
  * @brief    Get ADC Data Overrun Flag
  * @rmtoll   ACQ_ISR    OVR_IF    FL_ADC_IsActiveFlag_Overrun
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_Overrun(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_ISR, ADC_ACQ_ISR_OVR_IF_Msk) == (ADC_ACQ_ISR_OVR_IF_Msk));
}

/**
  * @brief    Clear ADC  Data Overrun Flag
  * @rmtoll   ACQ_ISR    OVR_IF    FL_ADC_ClearFlag_Overrun
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_Overrun(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ACQ_ISR, ADC_ACQ_ISR_OVR_IF_Msk);
}

/**
  * @brief    Get ADC Start Of Conversion Flag
  * @rmtoll   ACQ_ISR    SOCIF    FL_ADC_IsActiveFlag_ACQStartOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_soc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_ACQStartOfConversion(ADC_Type *ADCx, uint32_t acqx_soc)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_ISR, ((acqx_soc & 0x1f) << 0x8U)) == ((acqx_soc & 0x1f) << 0x8U));
}

/**
  * @brief    Clear Start Of Conversion Flag
  * @rmtoll   ACQ_ISR    SOCIF    FL_ADC_ClearFlag_ACQStartOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_soc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_ACQStartOfConversion(ADC_Type *ADCx, uint32_t acqx_soc)
{
    WRITE_REG(ADCx->ACQ_ISR, ((acqx_soc & 0x1f) << 0x8U));
}

/**
  * @brief    Get ADC End Of Conversion Flag
  * @rmtoll   ACQ_ISR    EOCIF    FL_ADC_IsActiveFlag_ACQEndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_ACQEndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_ISR, ((acqx_eoc & 0x1f) << 0x0U)) == ((acqx_eoc & 0x1f) << 0x0U));
}

/**
  * @brief    Clear ADC End Of Conversion Flag
  * @rmtoll   ACQ_ISR    EOCIF    FL_ADC_ClearFlag_ACQEndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_ACQEndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    WRITE_REG(ADCx->ACQ_ISR, ((acqx_eoc & 0x1f) << 0x0U));
}

/**
  * @brief    Enable ADC Data Overrun interrupt
  * @rmtoll   ACQ_IER    OVRIE    FL_ADC_EnableIT_Overrun
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_Overrun(ADC_Type *ADCx)
{
    SET_BIT(ADCx->ACQ_IER, ADC_ACQ_IER_OVRIE_Msk);
}

/**
  * @brief    Disable ADC Data Overrun interrupt
  * @rmtoll   ACQ_IER    OVRIE    FL_ADC_DisableIT_Overrun
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_Overrun(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->ACQ_IER, ADC_ACQ_IER_OVRIE_Msk);
}

/**
  * @brief    Get ADC Data Overrun interrupt Enable Status
  * @rmtoll   ACQ_IER    OVRIE    FL_ADC_IsEnabledIT_Overrun
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_Overrun(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_IER, ADC_ACQ_IER_OVRIE_Msk) == ADC_ACQ_IER_OVRIE_Msk);
}

/**
  * @brief    Enable ADC Start 0f Conversion interrupt
  * @rmtoll   ACQ_IER    SOCIE    FL_ADC_EnableIT_ACQStartOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_soc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_ACQStartOfConversion(ADC_Type *ADCx, uint32_t acqx_soc)
{
    SET_BIT(ADCx->ACQ_IER, ((acqx_soc & 0x1f) << 0x8U));
}

/**
  * @brief    Disable ADC Start 0f Conversion interrupt
  * @rmtoll   ACQ_IER    SOCIE    FL_ADC_DisableIT_ACQStartOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_soc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_ACQStartOfConversion(ADC_Type *ADCx, uint32_t acqx_soc)
{
    CLEAR_BIT(ADCx->ACQ_IER, ((acqx_soc & 0x1f) << 0x8U));
}

/**
  * @brief    Get ADC Start 0f Conversion interrupt Enable Status
  * @rmtoll   ACQ_IER    SOCIE    FL_ADC_IsEnabledIT_ACQStartOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_soc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_ACQStartOfConversion(ADC_Type *ADCx, uint32_t acqx_soc)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_IER, ((acqx_soc & 0x1f) << 0x8U)) == ((acqx_soc & 0x1f) << 0x8U));
}

/**
  * @brief    Enable ADC End 0f Conversion interrupt
  * @rmtoll   ACQ_IER    EOCIE    FL_ADC_EnableIT_ACQEndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_ACQEndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    SET_BIT(ADCx->ACQ_IER, ((acqx_eoc & 0x1f) << 0x0U));
}

/**
  * @brief    Disable ADC End 0f Conversion interrupt
  * @rmtoll   ACQ_IER    EOCIE    FL_ADC_DisableIT_ACQEndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_ACQEndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    CLEAR_BIT(ADCx->ACQ_IER, ((acqx_eoc & 0x1f) << 0x0U));
}

/**
  * @brief    Get ADC End 0f Conversion interrupt Enable Status
  * @rmtoll   ACQ_IER    EOCIE    FL_ADC_IsEnabledIT_ACQEndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_ACQEndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_IER, ((acqx_eoc & 0x1f) << 0x0U)) == ((acqx_eoc & 0x1f) << 0x0U));
}

/**
  * @brief    Get Scan ACQx ChannelID
  * @rmtoll   GISR    SCAN_CH    FL_ADC_ReadScanACQ_ChannelID
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadScanACQ_ChannelID(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, (0x3fU << 16U)) >> 16U);
}

/**
  * @brief    Get Working ACQx ID
  * @rmtoll   GISR    ACQ_ID    FL_ADC_ReadWorkingACQID
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadWorkingACQID(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, (0x1fU << 8U)) >> 8U);
}

/**
  * @brief    Get ADC Analog Watchdog Above High
  * @rmtoll   GISR    AWD_AH    FL_ADC_IsActiveFlag_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, ADC_GISR_AWD_AH_Msk) == (ADC_GISR_AWD_AH_Msk));
}

/**
  * @brief    Clear ADC Analog Watchdog Above High
  * @rmtoll   GISR    AWD_AH    FL_ADC_ClearFlag_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->GISR, ADC_GISR_AWD_AH_Msk);
}

/**
  * @brief    Get ADC Analog Watchdog Under Low
  * @rmtoll   GISR    AWD_UL    FL_ADC_IsActiveFlag_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, ADC_GISR_AWD_UL_Msk) == (ADC_GISR_AWD_UL_Msk));
}

/**
  * @brief    Clear ADC Analog Watchdog Under Low
  * @rmtoll   GISR    AWD_UL    FL_ADC_ClearFlag_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->GISR, ADC_GISR_AWD_UL_Msk);
}

/**
  * @brief    Get ADC Enable Flag
  * @rmtoll   GISR    ADEN    FL_ADC_IsActiveFlag_Enabled
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_Enabled(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, ADC_GISR_ADEN_Msk) == (ADC_GISR_ADEN_Msk));
}

/**
  * @brief    Get ADC Busy Flag
  * @rmtoll   GISR    BUSY    FL_ADC_IsActiveFlag_Busy
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_Busy(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, ADC_GISR_BUSY_Msk) == (ADC_GISR_BUSY_Msk));
}

/**
  * @brief    Clear ADC Continuous Mode Complete Flag
  * @rmtoll   GISR    EOCNT    FL_ADC_ClearFlag_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_ContinuousModeComplete(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->GISR, ADC_GISR_EOCNT_Msk);
}

/**
  * @brief    Get ADC Continuous Mode Complete Flag
  * @rmtoll   GISR    EOCNT    FL_ADC_IsActiveFlag_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_ContinuousModeComplete(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, ADC_GISR_EOCNT_Msk) == (ADC_GISR_EOCNT_Msk));
}

/**
  * @brief    Get ADC End Of Sequence Flag
  * @rmtoll   GISR    EOS    FL_ADC_IsActiveFlag_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_EndOfSequence(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, ADC_GISR_EOS_Msk) == (ADC_GISR_EOS_Msk));
}

/**
  * @brief    Clear ADC End Of Sequence Flag
  * @rmtoll   GISR    EOS    FL_ADC_ClearFlag_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_EndOfSequence(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->GISR, ADC_GISR_EOS_Msk);
}

/**
  * @brief    Enable ADC Analog Watchdog Above High interrupt
  * @rmtoll   GIER    AWD_AHIE    FL_ADC_EnableIT_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    SET_BIT(ADCx->GIER, ADC_GIER_AWD_AHIE_Msk);
}

/**
  * @brief    Disable ADC Analog Watchdog Above High interrupt
  * @rmtoll   GIER    AWD_AHIE    FL_ADC_DisableIT_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->GIER, ADC_GIER_AWD_AHIE_Msk);
}

/**
  * @brief    Get ADC Analog Watchdog Above High interrupt Enable Status
  * @rmtoll   GIER    AWD_AHIE    FL_ADC_IsEnabledIT_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GIER, ADC_GIER_AWD_AHIE_Msk) == ADC_GIER_AWD_AHIE_Msk);
}

/**
  * @brief    Enable ADC Analog Watchdog Under Low interrupt
  * @rmtoll   GIER    AWD_ULIE    FL_ADC_EnableIT_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    SET_BIT(ADCx->GIER, ADC_GIER_AWD_ULIE_Msk);
}

/**
  * @brief    Disable ADC Analog Watchdog Under Low interrupt
  * @rmtoll   GIER    AWD_ULIE    FL_ADC_DisableIT_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->GIER, ADC_GIER_AWD_ULIE_Msk);
}

/**
  * @brief    Get ADC Analog Watchdog Under Low interrupt Enable Status
  * @rmtoll   GIER    AWD_ULIE    FL_ADC_IsEnabledIT_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GIER, ADC_GIER_AWD_ULIE_Msk) == ADC_GIER_AWD_ULIE_Msk);
}

/**
  * @brief    Enable ADC Continuous Mode Complete interrupt
  * @rmtoll   GIER    EOCNTIE    FL_ADC_EnableIT_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_ContinuousModeComplete(ADC_Type *ADCx)
{
    SET_BIT(ADCx->GIER, ADC_GIER_EOCNTIE_Msk);
}

/**
  * @brief    Disable ADC Continuous Mode Complete interrupt
  * @rmtoll   GIER    EOCNTIE    FL_ADC_DisableIT_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_ContinuousModeComplete(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->GIER, ADC_GIER_EOCNTIE_Msk);
}

/**
  * @brief    Get ADC Continuous Mode Complete interrupt Enable Status
  * @rmtoll   GIER    EOCNTIE    FL_ADC_IsEnabledIT_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_ContinuousModeComplete(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GIER, ADC_GIER_EOCNTIE_Msk) == ADC_GIER_EOCNTIE_Msk);
}

/**
  * @brief    Enable ADC End Of Sequence interrupt
  * @rmtoll   GIER    EOSIE    FL_ADC_EnableIT_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_EndOfSequence(ADC_Type *ADCx)
{
    SET_BIT(ADCx->GIER, ADC_GIER_EOSIE_Msk);
}

/**
  * @brief    Disable ADC End Of Sequence interrupt
  * @rmtoll   GIER    EOSIE    FL_ADC_DisableIT_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_EndOfSequence(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->GIER, ADC_GIER_EOSIE_Msk);
}

/**
  * @brief    Get ADC End Of Sequence interrupt Enable Status
  * @rmtoll   GIER    EOSIE    FL_ADC_IsEnabledIT_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_EndOfSequence(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GIER, ADC_GIER_EOSIE_Msk) == ADC_GIER_EOSIE_Msk);
}

/**
  * @brief    Enable ACQ
  * @rmtoll   CR1    ACQEN    FL_ADC_EnableACQ
  * @param    ADCx ADC instance
  * @param    acqx_en This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableACQ(ADC_Type *ADCx, uint32_t acqx_en)
{
    SET_BIT(ADCx->CR1, ((acqx_en & 0x1f) << 0x10U));
}

/**
  * @brief    Disable ADC
  * @rmtoll   CR1    ACQEN    FL_ADC_DisableACQ
  * @param    ADCx ADC instance
  * @param    acqx_en This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableACQ(ADC_Type *ADCx, uint32_t acqx_en)
{
    CLEAR_BIT(ADCx->CR1, ((acqx_en & 0x1f) << 0x10U));
}

/**
  * @brief    Get ADC Enable Status
  * @rmtoll   CR1    ACQEN    FL_ADC_IsEnabledACQ
  * @param    ADCx ADC instance
  * @param    acqx_en This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledACQ(ADC_Type *ADCx, uint32_t acqx_en)
{
    return (uint32_t)(READ_BIT(ADCx->CR1, ((acqx_en & 0x1f) << 0x10U)) == ((acqx_en & 0x1f) << 0x10U));
}

/**
  * @brief    Enable Scan_ACQ Channel Reset
  * @rmtoll   CR1    SCH_SWRST    FL_ADC_EnableScanACQChannelReset
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableScanACQChannelReset(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR1, ADC_CR1_SCH_SWRST_Msk);
}

/**
  * @brief    Enable Round Robin Reset
  * @rmtoll   CR1    RR_SWRST    FL_ADC_EnableRoundRobinReset
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableRoundRobinReset(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR1, ADC_CR1_RR_SWRST_Msk);
}

/**
  * @brief    Enable ADC
  * @rmtoll   CR1    ADEN    FL_ADC_Enable
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Enable(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk);
}

/**
  * @brief    Disable ADC
  * @rmtoll   CR1    ADEN    FL_ADC_Disable
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Disable(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk);
}

/**
  * @brief    Get ADC Enable Status
  * @rmtoll   CR1    ADEN    FL_ADC_IsEnabled
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabled(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk) == ADC_CR1_ADEN_Msk);
}

/**
  * @brief    Enable ACQx Sofeware Triggered Conversion
  * @rmtoll   CR2    SWTRIG    FL_ADC_EnableACQSWConversion
  * @param    ADCx ADC instance
  * @param    acqx_sw This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableACQSWConversion(ADC_Type *ADCx, uint32_t acqx_sw)
{
    SET_BIT(ADCx->CR2, ((acqx_sw & 0x1f) << 0x0U));
}

/**
  * @brief    Set ADC Repeat Length for Continuous Mode
  * @rmtoll   CFGR1    RPTLEN    FL_ADC_WriteRepeatLength
  * @param    ADCx ADC instance
  * @param    count 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_WriteRepeatLength(ADC_Type *ADCx, uint32_t count)
{
    MODIFY_REG(ADCx->CFGR1, (0xffffU << 16U), (count << 16U));
}

/**
  * @brief    Read ADC Repeat Length for Continuous Mode
  * @rmtoll   CFGR1    RPTLEN    FL_ADC_ReadRepeatLength
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadRepeatLength(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Set bootstrap Vlotage
  * @rmtoll   CFGR1    CTRL_BOOST    FL_ADC_SetBootstrapVlotageSelect
  * @param    ADCx ADC instance
  * @param    voltage This parameter can be one of the following values:
  *           @arg @ref FL_ADC_BOOTSTRAP_Voltage_VDDA
  *           @arg @ref FL_ADC_BOOTSTRAP_Voltage_2P5V
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetBootstrapVlotageSelect(ADC_Type *ADCx, uint32_t voltage)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_CTRL_BOOST_Msk, voltage);
}

/**
  * @brief    Read bootstrap Vlotage
  * @rmtoll   CFGR1    CTRL_BOOST    FL_ADC_GetBootstrapVlotageSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_BOOTSTRAP_Voltage_VDDA
  *           @arg @ref FL_ADC_BOOTSTRAP_Voltage_2P5V
  */
__STATIC_INLINE uint32_t FL_ADC_GetBootstrapVlotageSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_CTRL_BOOST_Msk));
}

/**
  * @brief    Set ADC SOC Edge Mode
  * @rmtoll   CFGR1    SOCIF_CFG    FL_ADC_SetSOCEdgeMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SOC_EDGE_MODE_RISE
  *           @arg @ref FL_ADC_SOC_EDGE_MODE_FALL
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetSOCEdgeMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_SOCIF_CFG_Msk, mode);
}

/**
  * @brief    Read ADC SOC Edge Mode
  * @rmtoll   CFGR1    SOCIF_CFG    FL_ADC_GetSOCEdgeMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SOC_EDGE_MODE_RISE
  *           @arg @ref FL_ADC_SOC_EDGE_MODE_FALL
  */
__STATIC_INLINE uint32_t FL_ADC_GetSOCEdgeMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_SOCIF_CFG_Msk));
}

/**
  * @brief    Set ADC APBCLK Prescaler 
  * @rmtoll   CFGR1    PCLK_PSC    FL_ADC_SetAPBPrescaler
  * @param    ADCx ADC instance
  * @param    psc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV1
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV2
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV3
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV4
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV5
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV6
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetAPBPrescaler(ADC_Type *ADCx, uint32_t psc)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_PCLK_PSC_Msk, psc);
}

/**
  * @brief    Read ADC APBCLK Prescaler
  * @rmtoll   CFGR1    PCLK_PSC    FL_ADC_GetAPBPrescaler
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV1
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV2
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV3
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV4
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV5
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV6
  */
__STATIC_INLINE uint32_t FL_ADC_GetAPBPrescaler(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_PCLK_PSC_Msk));
}

/**
  * @brief    Set ADC VCM Mode
  * @rmtoll   CFGR1    VCM_CTRL    FL_ADC_SetVCMMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_VCM_MODE_PERIODIC
  *           @arg @ref FL_ADC_VCM_MODE_CONTINUOUS
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetVCMMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_VCM_CTRL_Msk, mode);
}

/**
  * @brief    Get ADC VCM Mode
  * @rmtoll   CFGR1    VCM_CTRL    FL_ADC_GetVCMMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_VCM_MODE_PERIODIC
  *           @arg @ref FL_ADC_VCM_MODE_CONTINUOUS
  */
__STATIC_INLINE uint32_t FL_ADC_GetVCMMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_VCM_CTRL_Msk));
}

/**
  * @brief    Set ADC Injection Mode
  * @rmtoll   CFGR1    INJ_MODE    FL_ADC_SetInjectionMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_INJ_MODE_DELAY
  *           @arg @ref FL_ADC_INJ_MODE_IMMEDIA
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_INJ_MODE_Msk, mode);
}

/**
  * @brief    Get ADC Injection Mode
  * @rmtoll   CFGR1    INJ_MODE    FL_ADC_GetInjectionMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_INJ_MODE_DELAY
  *           @arg @ref FL_ADC_INJ_MODE_IMMEDIA
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_INJ_MODE_Msk));
}

/**
  * @brief    Set ADC Negative Peference
  * @rmtoll   CFGR1    REFNSEL    FL_ADC_SetNegativePeference
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_Negative_Peference_VSSA
  *           @arg @ref FL_ADC_Negative_Peference_VREFN
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetNegativePeference(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_REFNSEL_Msk, mode);
}

/**
  * @brief    Read ADC Negative Peference 
  * @rmtoll   CFGR1    REFNSEL    FL_ADC_GetNegativePeference
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_Negative_Peference_VSSA
  *           @arg @ref FL_ADC_Negative_Peference_VREFN
  */
__STATIC_INLINE uint32_t FL_ADC_GetNegativePeference(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_REFNSEL_Msk));
}

/**
  * @brief    Set ADC Reference Source
  * @rmtoll   CFGR1    PEFSEL    FL_ADC_SetReferenceSource
  * @param    ADCx ADC instance
  * @param    ref This parameter can be one of the following values:
  *           @arg @ref FL_ADC_REF_SOURCE_VDDA
  *           @arg @ref FL_ADC_REF_SOURCE_VREFP
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetReferenceSource(ADC_Type *ADCx, uint32_t ref)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_PEFSEL_Msk, ref);
}

/**
  * @brief    Read ADC Reference Source
  * @rmtoll   CFGR1    PEFSEL    FL_ADC_GetReferenceSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_REF_SOURCE_VDDA
  *           @arg @ref FL_ADC_REF_SOURCE_VREFP
  */
__STATIC_INLINE uint32_t FL_ADC_GetReferenceSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_PEFSEL_Msk));
}

/**
  * @brief    Set ADC OverSampling Shift
  * @rmtoll   CFGR2    AVGR_OVSS    FL_ADC_SetOverSamplingShift
  * @param    ADCx ADC instance
  * @param    shift This parameter can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_0B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_1B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_2B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_3B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_4B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_5B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_6B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_7B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_8B
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetOverSamplingShift(ADC_Type *ADCx, uint32_t shift)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_AVGR_OVSS_Msk, shift);
}

/**
  * @brief    Read ADC OverSampling Shift
  * @rmtoll   CFGR2    AVGR_OVSS    FL_ADC_GetOverSamplingShift
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_0B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_1B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_2B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_3B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_4B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_5B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_6B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_7B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_8B
  */
__STATIC_INLINE uint32_t FL_ADC_GetOverSamplingShift(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_AVGR_OVSS_Msk));
}

/**
  * @brief    Set ADC OverSampling Multiplier
  * @rmtoll   CFGR2    AVGR_OVSR    FL_ADC_SetOverSamplingMultiplier
  * @param    ADCx ADC instance
  * @param    mul This parameter can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_16X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_32X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_64X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_128X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_256X
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetOverSamplingMultiplier(ADC_Type *ADCx, uint32_t mul)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_AVGR_OVSR_Msk, mul);
}

/**
  * @brief    Read ADC OverSampling Multiplier
  * @rmtoll   CFGR2    AVGR_OVSR    FL_ADC_GetOverSamplingMultiplier
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_16X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_32X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_64X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_128X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_256X
  */
__STATIC_INLINE uint32_t FL_ADC_GetOverSamplingMultiplier(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_AVGR_OVSR_Msk));
}

/**
  * @brief    Set ADC OverSampling Mode
  * @rmtoll   CFGR2    AVGEN    FL_ADC_SetOverSamplingMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MODE_DISABLE
  *           @arg @ref FL_ADC_OVERSAMPLING_MODE_ENABLE_AVERAGE
  *           @arg @ref FL_ADC_OVERSAMPLING_MODE_ENABLE_RESERVE
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetOverSamplingMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_AVGEN_Msk, mode);
}

/**
  * @brief    Read ADC OverSampling Mode
  * @rmtoll   CFGR2    AVGEN    FL_ADC_GetOverSamplingMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MODE_DISABLE
  *           @arg @ref FL_ADC_OVERSAMPLING_MODE_ENABLE_AVERAGE
  *           @arg @ref FL_ADC_OVERSAMPLING_MODE_ENABLE_RESERVE
  */
__STATIC_INLINE uint32_t FL_ADC_GetOverSamplingMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_AVGEN_Msk));
}

/**
  * @brief    Enable ADC Wait Mode
  * @rmtoll   CFGR2    WAIT_F    FL_ADC_EnableWaitMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableWaitMode(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_F_Msk);
}

/**
  * @brief    Disable ADC Wait Mode
  * @rmtoll   CFGR2    WAIT_F    FL_ADC_DisableWaitMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableWaitMode(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_F_Msk);
}

/**
  * @brief    Get ADC Wait Mode Enable Status
  * @rmtoll   CFGR2    WAIT_F    FL_ADC_IsEnabledWaitMode
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledWaitMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_F_Msk) == ADC_CFGR2_WAIT_F_Msk);
}

/**
  * @brief    Set ADC ScanACQ Conversion Mode
  * @rmtoll   CFGR2    AUTO_SCAN    FL_ADC_SetScanACQConversionAutoMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_CONV_MODE_SEMIAUTO
  *           @arg @ref FL_ADC_SCANACQ_CONV_MODE_AUTO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetScanACQConversionAutoMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_AUTO_SCAN_Msk, mode);
}

/**
  * @brief    Get ADC ScanACQ Conversion Mode
  * @rmtoll   CFGR2    AUTO_SCAN    FL_ADC_GetScanACQConversionAutoMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_CONV_MODE_SEMIAUTO
  *           @arg @ref FL_ADC_SCANACQ_CONV_MODE_AUTO
  */
__STATIC_INLINE uint32_t FL_ADC_GetScanACQConversionAutoMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_AUTO_SCAN_Msk));
}

/**
  * @brief    Enable ADC Overrun Mode
  * @rmtoll   CFGR2    CONT_MOD    FL_ADC_EnableContinuousMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableContinuousMode(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_CONT_MOD_Msk);
}

/**
  * @brief    Disable ADC Overrun Mode
  * @rmtoll   CFGR2    CONT_MOD    FL_ADC_DisableContinuousMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableContinuousMode(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_CONT_MOD_Msk);
}

/**
  * @brief    Get ADC Overrun Mode Enable Status
  * @rmtoll   CFGR2    CONT_MOD    FL_ADC_IsEnabledContinuousMode
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledContinuousMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_CONT_MOD_Msk) == ADC_CFGR2_CONT_MOD_Msk);
}

/**
  * @brief    Enable ADC Overrun Mode
  * @rmtoll   CFGR2    OVRM    FL_ADC_EnableOverrunMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableOverrunMode(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    Disable ADC Overrun Mode
  * @rmtoll   CFGR2    OVRM    FL_ADC_DisableOverrunMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableOverrunMode(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    Get ADC Overrun Mode Enable Status
  * @rmtoll   CFGR2    OVRM    FL_ADC_IsEnabledOverrunMode
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledOverrunMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk) == ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    Set ADC Channel Scan Direction
  * @rmtoll   CFGR2    SCANDIR    FL_ADC_SetSequenceScanDirection
  * @param    ADCx ADC instance
  * @param    dir This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_SCAN_DIR_BACKWARD
  *           @arg @ref FL_ADC_SCANACQ_SCAN_DIR_FORWARD
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetSequenceScanDirection(ADC_Type *ADCx, uint32_t dir)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_SCANDIR_Msk, dir);
}

/**
  * @brief    Get ADC Channel Scan Direction
  * @rmtoll   CFGR2    SCANDIR    FL_ADC_GetSequenceScanDirection
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_SCAN_DIR_BACKWARD
  *           @arg @ref FL_ADC_SCANACQ_SCAN_DIR_FORWARD
  */
__STATIC_INLINE uint32_t FL_ADC_GetSequenceScanDirection(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_SCANDIR_Msk));
}

/**
  * @brief    Enable ADC DMA
  * @rmtoll   CFGR2    DMAEN    FL_ADC_EnableDMAReq
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableDMAReq(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    Disable ADC DMA
  * @rmtoll   CFGR2    DMAEN    FL_ADC_DisableDMAReq
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableDMAReq(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    Get ADC DMA Enable Status
  * @rmtoll   CFGR2    DMAEN    FL_ADC_IsEnabledDMAReq
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledDMAReq(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk) == ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    Enable ADC Calibration
  * @rmtoll   OSR    CALEN    FL_ADC_EnableCalibration
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableCalibration(ADC_Type *ADCx)
{
    SET_BIT(ADCx->OSR, ADC_OSR_CALEN_Msk);
}

/**
  * @brief    Disable ADC Calibration
  * @rmtoll   OSR    CALEN    FL_ADC_DisableCalibration
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableCalibration(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->OSR, ADC_OSR_CALEN_Msk);
}

/**
  * @brief    Get ADC Calibration Enable Status
  * @rmtoll   OSR    CALEN    FL_ADC_IsEnabledCalibration
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledCalibration(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->OSR, ADC_OSR_CALEN_Msk) == ADC_OSR_CALEN_Msk);
}

/**
  * @brief    Write Slow Channel Calibration Value
  * @rmtoll   OSR    OS_CALI_SLOW    FL_ADC_WriteSlowChannelCalibration
  * @param    ADCx ADC instance
  * @param    calibration 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_WriteSlowChannelCalibration(ADC_Type *ADCx, uint32_t calibration)
{
    MODIFY_REG(ADCx->OSR, (0x1fffU << 16U), (calibration << 16U));
}

/**
  * @brief    Get Slow Channel Calibration Value
  * @rmtoll   OSR    OS_CALI_SLOW    FL_ADC_ReadSlowChannelCalibration
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadSlowChannelCalibration(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->OSR, (0x1fffU << 16U)) >> 16U);
}

/**
  * @brief    Write Fast Channel Calibration Value
  * @rmtoll   OSR    OS_CALI_Fast    FL_ADC_WriteFastChannelCalibration
  * @param    ADCx ADC instance
  * @param    calibration 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_WriteFastChannelCalibration(ADC_Type *ADCx, uint32_t calibration)
{
    MODIFY_REG(ADCx->OSR, (0x1fffU << 0U), (calibration << 0U));
}

/**
  * @brief    Get Fast Channel Calibration Value
  * @rmtoll   OSR    OS_CALI_Fast    FL_ADC_ReadFastChannelCalibration
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadFastChannelCalibration(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->OSR, (0x1fffU << 0U)) >> 0U);
}

/**
  * @brief    Read ACQx Pending Flag
  * @rmtoll   ACQ_SR    REQ    FL_ADC_IsEnabledACQxPending
  * @param    ADCx ADC instance
  * @param    acqx_pending This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_SCAN_ACQ
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledACQxPending(ADC_Type *ADCx, uint32_t acqx_pending)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_SR, ((acqx_pending & 0x1f) << 0x0U)) == ((acqx_pending & 0x1f) << 0x0U));
}

/**
  * @brief    Enable ADC SCAN Channel
  * @rmtoll   ACQ_SACR    CHEN    FL_ADC_EnableSCANACQ_SequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH0
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH1
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH2
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH3
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH4
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH5
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH6
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH7
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH8
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH9
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH10
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH11
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH12
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH13
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH14
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH15
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH16
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH17
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH18
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH19
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH20
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH21
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH22
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH23
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TS
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_AVREF
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_DAC
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN_SLOW
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableSCANACQ_SequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    SET_BIT(ADCx->ACQ_SACR, ((channel & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable ADC SCAN Channel
  * @rmtoll   ACQ_SACR    CHEN    FL_ADC_DisableSCANACQ_SequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH0
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH1
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH2
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH3
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH4
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH5
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH6
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH7
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH8
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH9
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH10
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH11
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH12
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH13
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH14
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH15
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH16
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH17
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH18
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH19
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH20
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH21
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH22
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH23
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TS
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_AVREF
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_DAC
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN_SLOW
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableSCANACQ_SequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    CLEAR_BIT(ADCx->ACQ_SACR, ((channel & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get ADC SCAN Channel Enable Status
  * @rmtoll   ACQ_SACR    CHEN    FL_ADC_IsEnabledSCANACQ_SequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH0
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH1
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH2
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH3
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH4
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH5
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH6
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH7
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH8
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH9
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH10
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH11
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH12
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH13
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH14
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH15
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH16
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH17
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH18
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH19
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH20
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH21
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH22
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH23
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TS
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_AVREF
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_DAC
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN_SLOW
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledSCANACQ_SequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_SACR, ((channel & 0xffffffff) << 0x0U)) == ((channel & 0xffffffff) << 0x0U));
}

/**
  * @brief    Write ADC Analog Watchdog Above High
  * @rmtoll   HLTR    AWD_HT    FL_ADC_WriteAnalogWDGHighThreshold
  * @param    ADCx ADC instance
  * @param    threshold 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_WriteAnalogWDGHighThreshold(ADC_Type *ADCx, uint32_t threshold)
{
    MODIFY_REG(ADCx->HLTR, (0xffffU << 16U), (threshold << 16U));
}

/**
  * @brief    Read ADC Analog Watchdog Above High
  * @rmtoll   HLTR    AWD_HT    FL_ADC_ReadAnalogWDGHighThreshold
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadAnalogWDGHighThreshold(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->HLTR, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Write ADC Analog Watchdog Under Low
  * @rmtoll   HLTR    AWD_LT    FL_ADC_WriteAnalogWDGLowThreshold
  * @param    ADCx ADC instance
  * @param    threshold 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_WriteAnalogWDGLowThreshold(ADC_Type *ADCx, uint32_t threshold)
{
    MODIFY_REG(ADCx->HLTR, (0xffffU << 0U), (threshold << 0U));
}

/**
  * @brief    Read ADC Analog Watchdog Under Low
  * @rmtoll   HLTR    AWD_LT    FL_ADC_ReadAnalogWDGLowThreshold
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadAnalogWDGLowThreshold(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->HLTR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Enable ADC Analog Watchdog Channel
  * @rmtoll   AWDCR    CHEN    FL_ADC_EnableAnalogWDGSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH0
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH1
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH2
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH3
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH4
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH5
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH6
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH7
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH8
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH9
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH10
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH11
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH12
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH13
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH14
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH15
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH16
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH17
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH18
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH19
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH20
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH21
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH22
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH23
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TS
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_AVREF
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_DAC
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN_SLOW
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableAnalogWDGSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    SET_BIT(ADCx->AWDCR, ((channel & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable ADC Analog Watchdog Channel
  * @rmtoll   AWDCR    CHEN    FL_ADC_DisableAnalogWDGSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH0
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH1
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH2
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH3
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH4
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH5
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH6
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH7
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH8
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH9
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH10
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH11
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH12
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH13
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH14
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH15
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH16
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH17
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH18
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH19
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH20
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH21
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH22
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH23
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TS
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_AVREF
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_DAC
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN_SLOW
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableAnalogWDGSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    CLEAR_BIT(ADCx->AWDCR, ((channel & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get ADC Analog Watchdog Channel Enable Status
  * @rmtoll   AWDCR    CHEN    FL_ADC_IsEnabledAnalogWDGSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH0
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH1
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH2
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH3
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH4
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH5
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH6
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH7
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH8
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH9
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH10
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH11
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH12
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH13
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH14
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH15
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH16
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH17
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH18
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH19
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH20
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH21
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH22
  *           @arg @ref FL_ADC_SCANACQ_EXTERNAL_CH23
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TS
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_AVREF
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_DAC
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFP
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_SCANACQ_INTERNAL_VREFN_SLOW
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledAnalogWDGSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(ADCx->AWDCR, ((channel & 0xffffffff) << 0x0U)) == ((channel & 0xffffffff) << 0x0U));
}

/**
  * @brief    Set ACQ0 Channel
  * @rmtoll   ACQ0_CR    CHSEL    FL_ADC_SetACQ0ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH12
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH13
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH14
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH15
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH16
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH17
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH18
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH19
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH20
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH21
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH22
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH23
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_DAC
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_SLOW
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ0ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ0_CR, ADC_ACQ0_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ0 Channel
  * @rmtoll   ACQ0_CR    CHSEL    FL_ADC_GetACQ0ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH12
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH13
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH14
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH15
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH16
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH17
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH18
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH19
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH20
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH21
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH22
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH23
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_DAC
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_SLOW
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ0ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ0_CR, ADC_ACQ0_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ0 Trigger Source
  * @rmtoll   ACQ0_CR    TRIGSEL    FL_ADC_SetACQ0TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_RTC_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU00_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU01_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU02_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU03_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU04_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU05_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU06_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU07_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU10_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU11_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU12_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU13_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU14_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU15_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU16_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU17_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ0TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ0_CR, ADC_ACQ0_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ0 Trigger Source
  * @rmtoll   ACQ0_CR    TRIGSEL    FL_ADC_GetACQ0TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_RTC_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU00_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU01_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU02_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU03_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU04_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU05_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU06_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU07_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU10_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU11_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU12_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU13_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU14_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU15_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU16_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU17_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ0TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ0_CR, ADC_ACQ0_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ0 Sampling Time
  * @rmtoll   ACQ0_CR    SMTS    FL_ADC_SetACQ0SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ0SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ0_CR, ADC_ACQ0_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ0 Sampling Time
  * @rmtoll   ACQ0_CR    SMTS    FL_ADC_GeACQ0SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ0SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ0_CR, ADC_ACQ0_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ1 Channel
  * @rmtoll   ACQ1_CR    CHSEL    FL_ADC_SetACQ1ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH12
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH13
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH14
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH15
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH16
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH17
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH18
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH19
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH20
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH21
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH22
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH23
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_DAC
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_SLOW
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ1ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ1_CR, ADC_ACQ1_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ1 Channel
  * @rmtoll   ACQ1_CR    CHSEL    FL_ADC_GetACQ1ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH12
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH13
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH14
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH15
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH16
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH17
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH18
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH19
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH20
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH21
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH22
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH23
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_DAC
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_SLOW
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ1ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ1_CR, ADC_ACQ1_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ1 Trigger Source
  * @rmtoll   ACQ1_CR    TRIGSEL    FL_ADC_SetACQ1TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_RTC_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU00_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU01_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU02_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU03_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU04_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU05_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU06_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU07_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU10_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU11_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU12_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU13_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU14_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU15_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU16_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU17_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ1TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ1_CR, ADC_ACQ1_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ1 Trigger Source
  * @rmtoll   ACQ1_CR    TRIGSEL    FL_ADC_GetACQ1TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_RTC_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU00_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU01_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU02_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU03_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU04_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU05_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU06_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU07_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU10_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU11_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU12_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU13_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU14_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU15_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU16_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU17_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ1TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ1_CR, ADC_ACQ1_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ1 Sampling Time
  * @rmtoll   ACQ1_CR    SMTS    FL_ADC_SetACQ1SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ1SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ1_CR, ADC_ACQ1_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ1 Sampling Time
  * @rmtoll   ACQ1_CR    SMTS    FL_ADC_GeACQ1SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ1SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ1_CR, ADC_ACQ1_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ2 Channel
  * @rmtoll   ACQ2_CR    CHSEL    FL_ADC_SetACQ2ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH12
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH13
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH14
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH15
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH16
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH17
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH18
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH19
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH20
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH21
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH22
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH23
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_DAC
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_SLOW
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ2ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ2_CR, ADC_ACQ2_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ2 Channel
  * @rmtoll   ACQ2_CR    CHSEL    FL_ADC_GetACQ2ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH12
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH13
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH14
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH15
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH16
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH17
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH18
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH19
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH20
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH21
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH22
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH23
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_DAC
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_SLOW
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ2ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ2_CR, ADC_ACQ2_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ2 Trigger Source
  * @rmtoll   ACQ2_CR    TRIGSEL    FL_ADC_SetACQ2TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_RTC_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU00_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU01_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU02_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU03_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU04_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU05_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU06_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU07_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU10_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU11_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU12_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU13_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU14_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU15_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU16_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU17_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ2TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ2_CR, ADC_ACQ2_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ2 Trigger Source
  * @rmtoll   ACQ2_CR    TRIGSEL    FL_ADC_GetACQ2TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_RTC_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU00_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU01_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU02_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU03_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU04_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU05_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU06_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU07_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU10_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU11_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU12_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU13_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU14_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU15_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU16_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU17_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ2TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ2_CR, ADC_ACQ2_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ2 Sampling Time
  * @rmtoll   ACQ2_CR    SMTS    FL_ADC_SetACQ2SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ2SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ2_CR, ADC_ACQ2_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ2 Sampling Time
  * @rmtoll   ACQ2_CR    SMTS    FL_ADC_GeACQ2SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ2SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ2_CR, ADC_ACQ2_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ3 Channel
  * @rmtoll   ACQ3_CR    CHSEL    FL_ADC_SetACQ3ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH12
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH13
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH14
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH15
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH16
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH17
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH18
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH19
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH20
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH21
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH22
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH23
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_DAC
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_SLOW
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ3ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ3_CR, ADC_ACQ3_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ3 Channel
  * @rmtoll   ACQ3_CR    CHSEL    FL_ADC_GetACQ3ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH0
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH1
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH2
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH3
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH4
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH5
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH6
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH7
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH8
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH9
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH10
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH11
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH12
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH13
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH14
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH15
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH16
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH17
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH18
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH19
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH20
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH21
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH22
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_EXTERNAL_CH23
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TS
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_AVREF
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_DAC
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFP
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_ACQ_SELECT_CHANNEL_INTERNAL_VREFN_SLOW
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ3ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ3_CR, ADC_ACQ3_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ3 Trigger Source
  * @rmtoll   ACQ3_CR    TRIGSEL    FL_ADC_SetACQ3TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_RTC_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU00_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU01_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU02_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU03_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU04_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU05_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU06_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU07_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU10_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU11_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU12_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU13_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU14_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU15_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU16_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU17_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ3TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ3_CR, ADC_ACQ3_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ3 Trigger Source
  * @rmtoll   ACQ3_CR    TRIGSEL    FL_ADC_GetACQ3TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_ACQ_TRGI_BSTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_RTC_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU00_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU01_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU02_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU03_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU04_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU05_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU06_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU07_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU10_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU11_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU12_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU13_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU14_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU15_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU16_TRGO
  *           @arg @ref FL_ADC_ACQ_TRGI_TAU17_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ3TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ3_CR, ADC_ACQ3_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ3 Sampling Time
  * @rmtoll   ACQ3_CR    SMTS    FL_ADC_SetACQ3SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ3SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ3_CR, ADC_ACQ3_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ3 Sampling Time
  * @rmtoll   ACQ3_CR    SMTS    FL_ADC_GetACQ3SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ3SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ3_CR, ADC_ACQ3_CR_SMTS_Msk));
}

/**
  * @brief    Set Fast Channel Sample time
  * @rmtoll   SCANACQ_CR    SMTS_FAST    FL_ADC_SetSCANACQFastChannelSamplingTime
  * @param    ADCx ADC instance
  * @param    fasttime This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetSCANACQFastChannelSamplingTime(ADC_Type *ADCx, uint32_t fasttime)
{
    MODIFY_REG(ADCx->SCANACQ_CR, ADC_SCANACQ_CR_SMTS_FAST_Msk, fasttime);
}

/**
  * @brief    Read Fast Channel Sample time
  * @rmtoll   SCANACQ_CR    SMTS_FAST    FL_ADC_GetSCANACQFastChannelSamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_FAST_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GetSCANACQFastChannelSamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->SCANACQ_CR, ADC_SCANACQ_CR_SMTS_FAST_Msk));
}

/**
  * @brief    Set SCAN ACQ Trigger Source
  * @rmtoll   SCANACQ_CR    TRIGSEL    FL_ADC_SetSCANACQTriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_SCANACQ_TRGI_BSTIM_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_RTC_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_0
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_1
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_2
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_3
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_4
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_5
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_6
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_7
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_0
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_1
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_2
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_3
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_4
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_5
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_6
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_7
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetSCANACQTriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->SCANACQ_CR, ADC_SCANACQ_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get SCAN ACQ Trigger Source
  * @rmtoll   SCANACQ_CR    TRIGSEL    FL_ADC_GetSCANACQTriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_TRGI_SOFE_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_ATIM_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_ATIM_TRGO2
  *           @arg @ref FL_ADC_SCANACQ_TRGI_BSTIM_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_LPTIM_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_RTC_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_0
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_1
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_2
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_3
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_4
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_5
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_6
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG0_7
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_0
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_1
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_2
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_3
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_4
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_5
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_6
  *           @arg @ref FL_ADC_SCANACQ_TRGI_TAU0_TRG1_7
  */
__STATIC_INLINE uint32_t FL_ADC_GetSCANACQTriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->SCANACQ_CR, ADC_SCANACQ_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set Slow Channel Sample time
  * @rmtoll   SCANACQ_CR    SMTS_SLOW    FL_ADC_SetSCANACQSlowChannelSamplingTime
  * @param    ADCx ADC instance
  * @param    lowtime This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetSCANACQSlowChannelSamplingTime(ADC_Type *ADCx, uint32_t lowtime)
{
    MODIFY_REG(ADCx->SCANACQ_CR, ADC_SCANACQ_CR_SMTS_SLOW_Msk, lowtime);
}

/**
  * @brief    Read Slow Channel Sample time
  * @rmtoll   SCANACQ_CR    SMTS_SLOW    FL_ADC_GetSCANACQSlowChannelSamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_SCANACQ_SAMPLING_LOW_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GetSCANACQSlowChannelSamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->SCANACQ_CR, ADC_SCANACQ_CR_SMTS_SLOW_Msk));
}

/**
  * @brief    Get ADC End of Conversion Flag
  * @rmtoll   CHISR    IF    FL_ADC_IsActiveFlag_ChannelEndOfConversion
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_EXTERNAL_CH0
  *           @arg @ref FL_ADC_EXTERNAL_CH1
  *           @arg @ref FL_ADC_EXTERNAL_CH2
  *           @arg @ref FL_ADC_EXTERNAL_CH3
  *           @arg @ref FL_ADC_EXTERNAL_CH4
  *           @arg @ref FL_ADC_EXTERNAL_CH5
  *           @arg @ref FL_ADC_EXTERNAL_CH6
  *           @arg @ref FL_ADC_EXTERNAL_CH7
  *           @arg @ref FL_ADC_EXTERNAL_CH8
  *           @arg @ref FL_ADC_EXTERNAL_CH9
  *           @arg @ref FL_ADC_EXTERNAL_CH10
  *           @arg @ref FL_ADC_EXTERNAL_CH11
  *           @arg @ref FL_ADC_EXTERNAL_CH12
  *           @arg @ref FL_ADC_EXTERNAL_CH13
  *           @arg @ref FL_ADC_EXTERNAL_CH14
  *           @arg @ref FL_ADC_EXTERNAL_CH15
  *           @arg @ref FL_ADC_EXTERNAL_CH16
  *           @arg @ref FL_ADC_EXTERNAL_CH17
  *           @arg @ref FL_ADC_EXTERNAL_CH18
  *           @arg @ref FL_ADC_EXTERNAL_CH19
  *           @arg @ref FL_ADC_EXTERNAL_CH20
  *           @arg @ref FL_ADC_EXTERNAL_CH21
  *           @arg @ref FL_ADC_EXTERNAL_CH22
  *           @arg @ref FL_ADC_EXTERNAL_CH23
  *           @arg @ref FL_ADC_INTERNAL_TS
  *           @arg @ref FL_ADC_INTERNAL_AVREF
  *           @arg @ref FL_ADC_INTERNAL_DAC
  *           @arg @ref FL_ADC_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_INTERNAL_VREFP
  *           @arg @ref FL_ADC_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_INTERNAL_VREFN_SLOW
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_ChannelEndOfConversion(ADC_Type *ADCx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(ADCx->CHISR, ((channel & 0xffffffff) << 0x0U)) == ((channel & 0xffffffff) << 0x0U));
}

/**
  * @brief    Clear ADC End Of Conversion Flag
  * @rmtoll   CHISR    IF    FL_ADC_ClearFlag_ChannelEndOfConversion
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_EXTERNAL_CH0
  *           @arg @ref FL_ADC_EXTERNAL_CH1
  *           @arg @ref FL_ADC_EXTERNAL_CH2
  *           @arg @ref FL_ADC_EXTERNAL_CH3
  *           @arg @ref FL_ADC_EXTERNAL_CH4
  *           @arg @ref FL_ADC_EXTERNAL_CH5
  *           @arg @ref FL_ADC_EXTERNAL_CH6
  *           @arg @ref FL_ADC_EXTERNAL_CH7
  *           @arg @ref FL_ADC_EXTERNAL_CH8
  *           @arg @ref FL_ADC_EXTERNAL_CH9
  *           @arg @ref FL_ADC_EXTERNAL_CH10
  *           @arg @ref FL_ADC_EXTERNAL_CH11
  *           @arg @ref FL_ADC_EXTERNAL_CH12
  *           @arg @ref FL_ADC_EXTERNAL_CH13
  *           @arg @ref FL_ADC_EXTERNAL_CH14
  *           @arg @ref FL_ADC_EXTERNAL_CH15
  *           @arg @ref FL_ADC_EXTERNAL_CH16
  *           @arg @ref FL_ADC_EXTERNAL_CH17
  *           @arg @ref FL_ADC_EXTERNAL_CH18
  *           @arg @ref FL_ADC_EXTERNAL_CH19
  *           @arg @ref FL_ADC_EXTERNAL_CH20
  *           @arg @ref FL_ADC_EXTERNAL_CH21
  *           @arg @ref FL_ADC_EXTERNAL_CH22
  *           @arg @ref FL_ADC_EXTERNAL_CH23
  *           @arg @ref FL_ADC_INTERNAL_TS
  *           @arg @ref FL_ADC_INTERNAL_AVREF
  *           @arg @ref FL_ADC_INTERNAL_DAC
  *           @arg @ref FL_ADC_INTERNAL_TSICAP
  *           @arg @ref FL_ADC_INTERNAL_VREFP
  *           @arg @ref FL_ADC_INTERNAL_VREFN_FAST
  *           @arg @ref FL_ADC_INTERNAL_VREFN_SLOW
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_ChannelEndOfConversion(ADC_Type *ADCx, uint32_t channel)
{
    SET_BIT(ADCx->CHISR, ((channel & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Channel ID of Conversion Result
  * @rmtoll   CHDMA_DR    CHID    FL_ADC_GetConversionChannelID
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_ADC_GetConversionChannelID(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CHDMA_DR, ADC_CHDMA_DR_CHID_Msk));
}

/**
  * @brief    Get ADC Conversion Result
  * @rmtoll   CHDMA_DR    RESULT    FL_ADC_GetConversionResult
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_ADC_GetConversionResult(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CHDMA_DR, ADC_CHDMA_DR_RESULT_Msk));
}

/**
  * @brief    Get EXTERNAL_CH0 Conversion Data
  * @rmtoll   CH0DR    RESULT    FL_ADC_ReadExternalCH0_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH0_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH0DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH1 Conversion Data
  * @rmtoll   CH1DR    RESULT    FL_ADC_ReadExternalCH1_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH1_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH1DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH2 Conversion Data
  * @rmtoll   CH2DR    RESULT    FL_ADC_ReadExternalCH2_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH2_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH2DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH3 Conversion Data
  * @rmtoll   CH3DR    RESULT    FL_ADC_ReadExternalCH3_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH3_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH3DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH4 Conversion Data
  * @rmtoll   CH4DR    RESULT    FL_ADC_ReadExternalCH4_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH4_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH4DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH5 Conversion Data
  * @rmtoll   CH5DR    RESULT    FL_ADC_ReadExternalCH5_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH5_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH5DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH6 Conversion Data
  * @rmtoll   CH6DR    RESULT    FL_ADC_ReadExternalCH6_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH6_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH6DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH7  Conversion Data
  * @rmtoll   CH7DR    RESULT    FL_ADC_ReadExternalCH7_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH7_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH7DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH8  Conversion Data
  * @rmtoll   CH8DR    RESULT    FL_ADC_ReadExternalCH8_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH8_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH8DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH9  Conversion Data
  * @rmtoll   CH9DR    RESULT    FL_ADC_ReadExternalCH9_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH9_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH9DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH10  Conversion Data
  * @rmtoll   CH10DR    RESULT    FL_ADC_ReadExternalCH10_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH10_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH10DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH11  Conversion Data
  * @rmtoll   CH11DR    RESULT    FL_ADC_ReadExternalCH11_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH11_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH11DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH12  Conversion Data
  * @rmtoll   CH12DR    RESULT    FL_ADC_ReadExternalCH12_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH12_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH12DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH13  Conversion Data
  * @rmtoll   CH13DR    RESULT    FL_ADC_ReadExternalCH13_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH13_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH13DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH14  Conversion Data
  * @rmtoll   CH14DR    RESULT    FL_ADC_ReadExternalCH14_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH14_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH14DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH15  Conversion Data
  * @rmtoll   CH15DR    RESULT    FL_ADC_ReadExternalCH15_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH15_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH15DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH16  Conversion Data
  * @rmtoll   CH16DR    RESULT    FL_ADC_ReadExternalCH16_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH16_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH16DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH17  Conversion Data
  * @rmtoll   CH17DR    RESULT    FL_ADC_ReadExternalCH17_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH17_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH17DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH18  Conversion Data
  * @rmtoll   CH18DR    RESULT    FL_ADC_ReadExternalCH18_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH18_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH18DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH19  Conversion Data
  * @rmtoll   CH19DR    RESULT    FL_ADC_ReadExternalCH19_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH19_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH19DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH20  Conversion Data
  * @rmtoll   CH20DR    RESULT    FL_ADC_ReadExternalCH20_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH20_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH20DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH21  Conversion Data
  * @rmtoll   CH21DR    RESULT    FL_ADC_ReadExternalCH21_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH21_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH21DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH22  Conversion Data
  * @rmtoll   CH22DR    RESULT    FL_ADC_ReadExternalCH22_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH22_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH22DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get EXTERNAL_CH23  Conversion Data
  * @rmtoll   CH23DR    RESULT    FL_ADC_ReadExternalCH23_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadExternalCH23_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH23DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get INTERNAL_TS Conversion Data
  * @rmtoll   CH24DR    RESULT    FL_ADC_ReadInternalTS_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadInternalTS_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH24DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get INTERNAL_AVREF Conversion Data
  * @rmtoll   CH25DR    RESULT    FL_ADC_ReadInternalAVREF_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadInternalAVREF_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH25DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get INTERNAL_DAC Conversion Data
  * @rmtoll   CH26DR    RESULT    FL_ADC_ReadInternalDAC_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadInternalDAC_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH26DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get INTERNAL_TSICAP Conversion Data
  * @rmtoll   CH27DR    RESULT    FL_ADC_ReadInternalTSICAP_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadInternalTSICAP_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH27DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get INTERNAL_VREFP Conversion Data
  * @rmtoll   CH29DR    RESULT    FL_ADC_ReadInternalVREFP_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadInternalVREFP_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH29DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get INTERNAL_VREFN_FAST Conversion Data
  * @rmtoll   CH30DR    RESULT    FL_ADC_ReadInternalVREFNFAST_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadInternalVREFNFAST_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH30DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get INTERNAL_VREFN_SLOW Conversion Data
  * @rmtoll   CH31DR    RESULT    FL_ADC_ReadInternalVREFNLOW_ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadInternalVREFNLOW_ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CH31DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @}
  */

/** @defgroup ADC_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_ADC_CommonDeInit(void);
FL_ErrorStatus FL_ADC_CommonInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);
void FL_ADC_CommonStructInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);
FL_ErrorStatus  FL_ADC_DeInit(ADC_Type *ADCx);
FL_ErrorStatus FL_ADC_Init(ADC_Type *ADCx, FL_ADC_InitTypeDef  *ADC_InitStruct,uint32_t ACQx_ID);
void FL_ADC_StructInit(FL_ADC_InitTypeDef *ADC_InitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_ADC_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2024-01-22*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
