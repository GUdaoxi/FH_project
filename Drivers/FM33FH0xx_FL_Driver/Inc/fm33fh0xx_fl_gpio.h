/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_gpio.h
  * @author  FMSH Application Team
  * @brief   Head file of GPIO FL Module
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
#ifndef __FM33FH0XX_FL_GPIO_H
#define __FM33FH0XX_FL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl_def.h"
/** @addtogroup FM33FH0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup GPIO_FL_ES_INIT GPIO Exported Init structures
  * @{
  */
/**
  * @brief FL GPIO Init Sturcture definition
  */
typedef struct
{
    /* PIN */
    uint32_t pin;

    /*功能模式*/
    uint32_t mode;

    /*!输出类型  */
    uint32_t outputType;

    /* 驱动强度*/
    uint32_t driveStrength;

    /* 上下拉选择*/
    uint32_t pull;

    /*数字功能重定向*/
    uint32_t remapPin;

} FL_GPIO_InitTypeDef;

/**
  * @brief FL GPIO WKUP Init Sturcture definition
  */
typedef struct
{
    /*触发边沿 */
    uint32_t polarity;

} FL_WKUP_InitTypeDef;


/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup GPIO_FL_Exported_Constants GPIO Exported Constants
  * @{
  */

#define    GPIO_FCR_Pos                                           (0U)
#define    GPIO_FCR_Msk                                           (0x3U << GPIO_FCR_Pos)
#define    GPIO_FCR                                               GPIO_FCR_Msk

#define    GPIO_PUDEN_PDEN_Pos                                    (16U)
#define    GPIO_PUDEN_PDEN_Msk                                    (0x1U << GPIO_PUDEN_PDEN_Pos)
#define    GPIO_PUDEN_PDEN                                         GPIO_PUDEN_PDEN_Msk

#define    GPIO_PUDEN_PUEN_Pos                                    (0U)
#define    GPIO_PUDEN_PUEN_Msk                                    (0x1U << GPIO_PUDEN_PUEN_Pos)
#define    GPIO_PUDEN_PUEN                                          GPIO_PUDEN_PUEN_Msk

#define    GPIO_DFS_Pos                                           (0U)
#define    GPIO_DFS_Msk                                           (0x3U << GPIO_DFS_Pos)
#define    GPIO_DFS                                               GPIO_DFS_Msk

#define    GPIO_DSR_Pos                                           (0U)
#define    GPIO_DSR_Msk                                           (0x3U << GPIO_DSR_Pos)
#define    GPIO_DSR                                               GPIO_DSR_Msk

#define    GPIO_EXTIEDSA_Pos                                      (0U)
#define    GPIO_EXTIEDSA_Msk                                      (0x3U << GPIO_EXTIEDSA_Pos)
#define    GPIO_EXTIEDSA                                          GPIO_EXTIEDSA_Msk

#define    GPIO_EXTIEDSB_Pos                                      (0U)
#define    GPIO_EXTIEDSB_Msk                                      (0x3U << GPIO_EXTIEDSB_Pos)
#define    GPIO_EXTIEDSB                                          GPIO_EXTIEDSB_Msk

#define    GPIO_EXTIEDSC_Pos                                      (0U)
#define    GPIO_EXTIEDSC_Msk                                      (0x3U << GPIO_EXTIEDSC_Pos)
#define    GPIO_EXTIEDSC                                          GPIO_EXTIEDSC_Msk

#define    GPIO_EXTIEDSD_Pos                                      (0U)
#define    GPIO_EXTIEDSD_Msk                                      (0x3U << GPIO_EXTIEDSD_Pos)
#define    GPIO_EXTIEDSD                                          GPIO_EXTIEDSD_Msk

#define    GPIO_EXTIEDSE_Pos                                      (0U)
#define    GPIO_EXTIEDSE_Msk                                      (0x3U << GPIO_EXTIEDSE_Pos)
#define    GPIO_EXTIEDSE                                          GPIO_EXTIEDSE_Msk

#define    GPIO_EXTIEDSF_Pos                                      (0U)
#define    GPIO_EXTIEDSF_Msk                                      (0x3U << GPIO_EXTIEDSF_Pos)
#define    GPIO_EXTIEDSF                                          GPIO_EXTIEDSF_Msk

#define    GPIO_EXTIEDSG_Pos                                      (0U)
#define    GPIO_EXTIEDSG_Msk                                      (0x3U << GPIO_EXTIEDSG_Pos)
#define    GPIO_EXTIEDSG                                          GPIO_EXTIEDSG_Msk

#define    GPIO_EXTIDFAB_DFA_Pos                                  (0U)
#define    GPIO_EXTIDFAB_DFA_Msk                                  (0xffffU << GPIO_EXTIDFAB_DFA_Pos)
#define    GPIO_EXTIDFAB_DFA                                      GPIO_EXTIDFAB_DFA_Msk

#define    GPIO_EXTIDFAB_DFB_Pos                                  (16U)
#define    GPIO_EXTIDFAB_DFB_Msk                                  (0xffffU << GPIO_EXTIDFAB_DFB_Pos)
#define    GPIO_EXTIDFAB_DFB                                      GPIO_EXTIDFAB_DFB_Msk

#define    GPIO_EXTIDFCD_DFC_Pos                                  (0U)
#define    GPIO_EXTIDFCD_DFC_Msk                                  (0xffffU << GPIO_EXTIDFCD_DFC_Pos)
#define    GPIO_EXTIDFCD_DFC                                      GPIO_EXTIDFCD_DFC_Msk

#define    GPIO_EXTIDFCD_DFD_Pos                                  (16U)
#define    GPIO_EXTIDFCD_DFD_Msk                                  (0xffffU << GPIO_EXTIDFCD_DFD_Pos)
#define    GPIO_EXTIDFCD_DFD                                      GPIO_EXTIDFCD_DFD_Msk

#define    GPIO_EXTIDFEF_DFE_Pos                                  (0U)
#define    GPIO_EXTIDFEF_DFE_Msk                                  (0xffffU << GPIO_EXTIDFEF_DFE_Pos)
#define    GPIO_EXTIDFEF_DFE                                      GPIO_EXTIDFEF_DFE_Msk

#define    GPIO_EXTIDFEF_DFF_Pos                                  (16U)
#define    GPIO_EXTIDFEF_DFF_Msk                                  (0xffffU << GPIO_EXTIDFEF_DFF_Pos)
#define    GPIO_EXTIDFEF_DFF                                      GPIO_EXTIDFEF_DFF_Msk

#define    GPIO_EXTIDFGH_DFG_Pos                                  (0U)
#define    GPIO_EXTIDFGH_DFG_Msk                                  (0xffffU << GPIO_EXTIDFGH_DFG_Pos)
#define    GPIO_EXTIDFGH_DFG                                      GPIO_EXTIDFGH_DFG_Msk

#define    GPIO_EXTIDFGH_DFH_Pos                                  (16U)
#define    GPIO_EXTIDFGH_DFH_Msk                                  (0xffffU << GPIO_EXTIDFGH_DFH_Pos)
#define    GPIO_EXTIDFGH_DFH                                      GPIO_EXTIDFGH_DFH_Msk

#define    GPIO_EXTIISRAB_ISRA_Pos                                (0U)
#define    GPIO_EXTIISRAB_ISRA_Msk                                (0xffffU << GPIO_EXTIISRAB_ISRA_Pos)
#define    GPIO_EXTIISRAB_ISRA                                    GPIO_EXTIISRAB_ISRA_Msk

#define    GPIO_EXTIISRAB_ISRB_Pos                                (16U)
#define    GPIO_EXTIISRAB_ISRB_Msk                                (0xffffU << GPIO_EXTIISRAB_ISRB_Pos)
#define    GPIO_EXTIISRAB_ISRB                                    GPIO_EXTIISRAB_ISRB_Msk

#define    GPIO_EXTIISRCD_ISRC_Pos                                (0U)
#define    GPIO_EXTIISRCD_ISRC_Msk                                (0xffffU << GPIO_EXTIISRCD_ISRC_Pos)
#define    GPIO_EXTIISRCD_ISRC                                    GPIO_EXTIISRCD_ISRC_Msk

#define    GPIO_EXTIISRCD_ISRD_Pos                                (16U)
#define    GPIO_EXTIISRCD_ISRD_Msk                                (0xffffU << GPIO_EXTIISRCD_ISRD_Pos)
#define    GPIO_EXTIISRCD_ISRD                                    GPIO_EXTIISRCD_ISRD_Msk

#define    GPIO_EXTIISREF_ISRE_Pos                                (0U)
#define    GPIO_EXTIISREF_ISRE_Msk                                (0xffffU << GPIO_EXTIISREF_ISRE_Pos)
#define    GPIO_EXTIISREF_ISRE                                    GPIO_EXTIISREF_ISRE_Msk

#define    GPIO_EXTIISREF_ISRF_Pos                                (16U)
#define    GPIO_EXTIISREF_ISRF_Msk                                (0xffffU << GPIO_EXTIISREF_ISRF_Pos)
#define    GPIO_EXTIISREF_ISRF                                    GPIO_EXTIISREF_ISRF_Msk

#define    GPIO_EXTIISRGH_ISRG_Pos                                (0U)
#define    GPIO_EXTIISRGH_ISRG_Msk                                (0xffffU << GPIO_EXTIISRGH_ISRG_Pos)
#define    GPIO_EXTIISRGH_ISRG                                    GPIO_EXTIISRGH_ISRG_Msk

#define    GPIO_EXTIISRGH_ISRH_Pos                                (16U)
#define    GPIO_EXTIISRGH_ISRH_Msk                                (0xffffU << GPIO_EXTIISRGH_ISRH_Pos)
#define    GPIO_EXTIISRGH_ISRH                                    GPIO_EXTIISRGH_ISRH_Msk

#define    GPIO_EXTIDIAB_DIA_Pos                                  (0U)
#define    GPIO_EXTIDIAB_DIA_Msk                                  (0xffffU << GPIO_EXTIDIAB_DIA_Pos)
#define    GPIO_EXTIDIAB_DIA                                      GPIO_EXTIDIAB_DIA_Msk

#define    GPIO_EXTIDIAB_DIB_Pos                                  (16U)
#define    GPIO_EXTIDIAB_DIB_Msk                                  (0xffffU << GPIO_EXTIDIAB_DIB_Pos)
#define    GPIO_EXTIDIAB_DIB                                      GPIO_EXTIDIAB_DIB_Msk

#define    GPIO_EXTIDICD_DIC_Pos                                  (0U)
#define    GPIO_EXTIDICD_DIC_Msk                                  (0xffffU << GPIO_EXTIDICD_DIC_Pos)
#define    GPIO_EXTIDICD_DIC                                      GPIO_EXTIDICD_DIC_Msk

#define    GPIO_EXTIDICD_DID_Pos                                  (16U)
#define    GPIO_EXTIDICD_DID_Msk                                  (0xffffU << GPIO_EXTIDICD_DID_Pos)
#define    GPIO_EXTIDICD_DID                                      GPIO_EXTIDICD_DID_Msk

#define    GPIO_EXTIDIEF_DIE_Pos                                  (0U)
#define    GPIO_EXTIDIEF_DIE_Msk                                  (0xffffU << GPIO_EXTIDIEF_DIE_Pos)
#define    GPIO_EXTIDIEF_DIE                                      GPIO_EXTIDIEF_DIE_Msk

#define    GPIO_EXTIDIEF_DIF_Pos                                  (16U)
#define    GPIO_EXTIDIEF_DIF_Msk                                  (0xffffU << GPIO_EXTIDIEF_DIF_Pos)
#define    GPIO_EXTIDIEF_DIF                                      GPIO_EXTIDIEF_DIF_Msk

#define    GPIO_EXTIDIGH_DIG_Pos                                  (0U)
#define    GPIO_EXTIDIGH_DIG_Msk                                  (0xffffU << GPIO_EXTIDIGH_DIG_Pos)
#define    GPIO_EXTIDIGH_DIG                                      GPIO_EXTIDIGH_DIG_Msk

#define    GPIO_EXTIDIGH_DIH_Pos                                  (16U)
#define    GPIO_EXTIDIGH_DIH_Msk                                  (0xffffU << GPIO_EXTIDIGH_DIH_Pos)
#define    GPIO_EXTIDIGH_DIH                                      GPIO_EXTIDIGH_DIH_Msk

#define    GPIO_FOUTSEL_FOUT0_Pos                                 (0U)
#define    GPIO_FOUTSEL_FOUT0_Msk                                 (0xfU << GPIO_FOUTSEL_FOUT0_Pos)
#define    GPIO_FOUTSEL_FOUT0                                     GPIO_FOUTSEL_FOUT0_Msk

#define    GPIO_FOUTSEL_FOUT1_Pos                                 (4U)
#define    GPIO_FOUTSEL_FOUT1_Msk                                 (0xfU << GPIO_FOUTSEL_FOUT1_Pos)
#define    GPIO_FOUTSEL_FOUT1                                     GPIO_FOUTSEL_FOUT1_Msk

#define    GPIO_PINWKEN_EN_Pos                                    (0U)
#define    GPIO_PINWKEN_EN_Msk                                    (0x3ffU << GPIO_PINWKEN_EN_Pos)
#define    GPIO_PINWKEN_EN                                        GPIO_PINWKEN_EN_Msk

#define    GPIO_PINWKEN_SEL_Pos                                   (10U)
#define    GPIO_PINWKEN_SEL_Msk                                   (0x3U << GPIO_PINWKEN_SEL_Pos)
#define    GPIO_PINWKEN_SEL                                       GPIO_PINWKEN_SEL_Msk

#define    GPIO_PINWKEN_WKSEL_Pos                                 (31U)
#define    GPIO_PINWKEN_WKSEL_Msk                                 (0x1U << GPIO_PINWKEN_WKSEL_Pos)
#define    GPIO_PINWKEN_WKSEL                                     GPIO_PINWKEN_WKSEL_Msk



#define    FL_GPIO_PIN_0                                          (0x1U << 0U)
#define    FL_GPIO_PIN_1                                          (0x1U << 1U)
#define    FL_GPIO_PIN_2                                          (0x1U << 2U)
#define    FL_GPIO_PIN_3                                          (0x1U << 3U)
#define    FL_GPIO_PIN_4                                          (0x1U << 4U)
#define    FL_GPIO_PIN_5                                          (0x1U << 5U)
#define    FL_GPIO_PIN_6                                          (0x1U << 6U)
#define    FL_GPIO_PIN_7                                          (0x1U << 7U)
#define    FL_GPIO_PIN_8                                          (0x1U << 8U)
#define    FL_GPIO_PIN_9                                          (0x1U << 9U)
#define    FL_GPIO_PIN_10                                         (0x1U << 10U)
#define    FL_GPIO_PIN_11                                         (0x1U << 11U)
#define    FL_GPIO_PIN_12                                         (0x1U << 12U)
#define    FL_GPIO_PIN_13                                         (0x1U << 13U)
#define    FL_GPIO_PIN_14                                         (0x1U << 14U)
#define    FL_GPIO_PIN_15                                         (0x1U << 15U)
#define    FL_GPIO_PIN_ALL                                        (0xffffU << 0U)
#define    FL_GPIO_PIN_ALL_EXCEPTSWD                              0xFCFFU
#define    FL_GPIO_PIN_ALL_EXCEPTRST                              0xFFFEU
#define    FL_GPIO_EXTI_TRIGGER_EDGE_RISING                       (0x0U << 0U)
#define    FL_GPIO_EXTI_TRIGGER_EDGE_FALLING                      (0x1U << 0U)
#define    FL_GPIO_EXTI_TRIGGER_EDGE_BOTH                         (0x2U << 0U)
#define    FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE                      (0x3U << 0U)
#define    FL_GPIO_WAKEUP_0                                       (0x1U << 0U)
#define    FL_GPIO_WAKEUP_1                                       (0x1U << 1U)
#define    FL_GPIO_WAKEUP_2                                       (0x1U << 2U)
#define    FL_GPIO_WAKEUP_3                                       (0x1U << 3U)
#define    FL_GPIO_WAKEUP_4                                       (0x1U << 4U)
#define    FL_GPIO_WAKEUP_5                                       (0x1U << 5U)
#define    FL_GPIO_WAKEUP_6                                       (0x1U << 6U)
#define    FL_GPIO_WAKEUP_7                                       (0x1U << 7U)
#define    FL_GPIO_WAKEUP_8                                       (0x1U << 8U)
#define    FL_GPIO_WAKEUP_9                                       (0x1U << 9U)
#define    FL_GPIO_OUTPUT_PUSHPULL                                (0x0U << 0U)
#define    FL_GPIO_OUTPUT_OPENDRAIN                               (0x1U << 0U)

#define    FL_GPIO_PULLUP_ENABLE                                  (0x0U << GPIO_PUDEN_PUEN_Pos)
#define    FL_GPIO_PULLDOWN_ENABLE                                (0x1U << GPIO_PUDEN_PDEN_Pos)
#define    FL_GPIO_BOTH_DISABLE                                   0x2U

#define    FL_GPIO_MODE_INPUT                                     (0x0U << GPIO_FCR_Pos)
#define    FL_GPIO_MODE_OUTPUT                                    (0x1U << GPIO_FCR_Pos)
#define    FL_GPIO_MODE_DIGITAL                                   (0x2U << GPIO_FCR_Pos)
#define    FL_GPIO_MODE_ANALOG                                    (0x3U << GPIO_FCR_Pos)


#define    FL_GPIO_PINREMAP_FUNCTON0                              (0x0U << GPIO_DFS_Pos)
#define    FL_GPIO_PINREMAP_FUNCTON1                              (0x1U << GPIO_DFS_Pos)
#define    FL_GPIO_PINREMAP_FUNCTON2                              (0x2U << GPIO_DFS_Pos)
#define    FL_GPIO_PINREMAP_FUNCTON3                              (0x3U << GPIO_DFS_Pos)


#define    FL_GPIO_DRIVESTRENGTH_CLOSE                            (0x0U << GPIO_DSR_Pos)
#define    FL_GPIO_DRIVESTRENGTH_X1                               (0x1U << GPIO_DSR_Pos)
#define    FL_GPIO_DRIVESTRENGTH_X2                               (0x2U << GPIO_DSR_Pos)
#define    FL_GPIO_DRIVESTRENGTH_X3                               (0x3U << GPIO_DSR_Pos)


#define    FL_GPIO_FOUT0_SELECT_XTLF                              (0x0U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_RCLP                              (0x1U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_RCHF_DIV64                        (0x2U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_LSCLK                             (0x3U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_AHBCLK_DIV64                      (0x4U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_RTCTM                             (0x5U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_PLL_DIV64                         (0x6U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_RTCCLK64HZ                        (0x7U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_APBCLK1_DIV64                     (0x8U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_PLL                               (0x9U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_FDCAN_TXCLK                       (0xaU << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_RCHF                              (0xbU << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_XTHF_DIV64                        (0xcU << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_ADC_SOC                           (0xdU << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_CLK8K                             (0xeU << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_ADC_CLK                           (0xfU << GPIO_FOUTSEL_FOUT0_Pos)


#define    FL_GPIO_FOUT1_SELECT_XTLF                              (0x0U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_RCLP                              (0x1U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_ADC_CLK                           (0x2U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_LSCLK                             (0x3U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_ADC_EOC                           (0x4U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_RTCTM                             (0x5U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_PLL_DIV64                         (0x6U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_APBCLK1_DIV64                     (0x8U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_PLL                               (0x9U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_FDCAN_TXCLK                       (0xaU << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_RCHF                              (0xbU << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_XTHF_DIV64                        (0xcU << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_ADCCLK_DIV64                      (0xdU << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_CLK8K                             (0xeU << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_XTHF                              (0xfU << GPIO_FOUTSEL_FOUT1_Pos)


#define    FL_GPIO_WAKEUP_TRIGGER_FALLING                         (0x0U << GPIO_PINWKEN_SEL_Pos)
#define    FL_GPIO_WAKEUP_TRIGGER_RISING                          (0x1U << GPIO_PINWKEN_SEL_Pos)
#define    FL_GPIO_WAKEUP_TRIGGER_BOTH                            (0x2U << GPIO_PINWKEN_SEL_Pos)


#define    FL_GPIO_WAKEUP_INT_ENTRY_NMI                           (0x0U << GPIO_PINWKEN_WKSEL_Pos)
#define    FL_GPIO_WAKEUP_INT_ENTRY_38                            (0x1U << GPIO_PINWKEN_WKSEL_Pos)

#define    GPIO_DSR_Pos                                           (0U)
#define    GPIO_DSR_Msk                                           (0x3U << GPIO_DSR_Pos)
#define    GPIO_DSR                                               GPIO_DSR_Msk

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup GPIO_FL_Exported_Functions GPIO Exported Functions
  * @{
  */

/**
  * @brief    GPIOx input enable
  * @rmtoll   INEN        FL_GPIO_EnablePinInput
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_EnablePinInput(GPIO_Type *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->INEN, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    CPIOx input disable
  * @rmtoll   INEN        FL_GPIO_DisablePinInput
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_DisablePinInput(GPIO_Type *GPIOx, uint32_t pin)
{
    CLEAR_BIT(GPIOx->INEN, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get GPIOx input enable status
  * @rmtoll   INEN        FL_GPIO_IsEnabledPinInput
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_IsEnabledPinInput(GPIO_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->INEN, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    GPIOx Pull-Down enable
  * @rmtoll   PUDEN        FL_GPIO_EnablePinPullDown
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_EnablePinPullDown(GPIO_Type *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->PUDEN, ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    GPIOx Pull-Down disable
  * @rmtoll   PUDEN        FL_GPIO_DisablePinPullDown
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_DisablePinPullDown(GPIO_Type *GPIOx, uint32_t pin)
{
    CLEAR_BIT(GPIOx->PUDEN, ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get GPIOx Pull-Down enable status
  * @rmtoll   PUDEN        FL_GPIO_IsEnabledPinPullDown
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_IsEnabledPinPullDown(GPIO_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->PUDEN, ((pin & 0xffff) << 0x10U)) == ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    GPIOx Pull-Up enable
  * @rmtoll   PUDEN        FL_GPIO_EnablePinPullUp
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_EnablePinPullUp(GPIO_Type *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->PUDEN, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    GPIOx Pull-Up disable
  * @rmtoll   PUDEN        FL_GPIO_DisablePinPullUp
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_DisablePinPullUp(GPIO_Type *GPIOx, uint32_t pin)
{
    CLEAR_BIT(GPIOx->PUDEN, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get GPIOx Pull-Up enable status
  * @rmtoll   PUDEN        FL_GPIO_IsEnabledPinPullUp
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_IsEnabledPinPullUp(GPIO_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->PUDEN, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    GPIOx Open-Drain enable
  * @rmtoll   ODEN        FL_GPIO_EnablePinOpenDrain
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_EnablePinOpenDrain(GPIO_Type *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->ODEN, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Open-Drain disable
  * @rmtoll   ODEN        FL_GPIO_DisablePinOpenDrain
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_DisablePinOpenDrain(GPIO_Type *GPIOx, uint32_t pin)
{
    CLEAR_BIT(GPIOx->ODEN, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get Open-Drain enable status
  * @rmtoll   ODEN        FL_GPIO_IsEnabledPinOpenDrain
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_IsEnabledPinOpenDrain(GPIO_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->ODEN, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Set Portx mode
  * @rmtoll   FCR        FL_GPIO_SetPinMode
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_MODE_INPUT
  *           @arg @ref FL_GPIO_MODE_OUTPUT
  *           @arg @ref FL_GPIO_MODE_DIGITAL
  *           @arg @ref FL_GPIO_MODE_ANALOG
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetPinMode(GPIO_Type *GPIOx, uint32_t pin, uint32_t mode)
{
    MODIFY_REG(GPIOx->FCR, ((pin * pin) * GPIO_FCR), ((pin * pin) * mode));
}

/**
  * @brief    Get Portx mode
  * @rmtoll   FCR        FL_GPIO_GetPinMode
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_GPIO_MODE_INPUT
  *           @arg @ref FL_GPIO_MODE_OUTPUT
  *           @arg @ref FL_GPIO_MODE_DIGITAL
  *           @arg @ref FL_GPIO_MODE_ANALOG
  */
__STATIC_INLINE uint32_t FL_GPIO_GetPinMode(GPIO_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->FCR, ((pin * pin) * GPIO_FCR)) / (pin * pin));
}

/**
  * @brief    Set GPIO output data
  * @rmtoll   DO        FL_GPIO_WriteOutputPort
  * @param    GPIOx GPIO Port
  * @param    output 
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_WriteOutputPort(GPIO_Type *GPIOx, uint32_t output)
{
    MODIFY_REG(GPIOx->DO, (0xffffU << 0U), (output << 0U));
}

/**
  * @brief    Get GPIO output data 
  * @rmtoll   DO        FL_GPIO_ReadOutputPort
  * @param    GPIOx GPIO Port
  * @retval   Output data register value of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadOutputPort(GPIO_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->DO, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get GPIO output pin status 
  * @rmtoll   DO        FL_GPIO_IsEnabledOutputPin
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_IsEnabledOutputPin(GPIO_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->DO, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Toggle output pin
  * @rmtoll   DO        FL_GPIO_ToggleOutputPin
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_ToggleOutputPin(GPIO_Type *GPIOx, uint32_t pin)
{
    if(pin & GPIOx->DO)
    {
        WRITE_REG(GPIOx->DRST, pin);
    }
    else
    {
        WRITE_REG(GPIOx->DSET, pin);
    }
}

/**
  * @brief    Set pin output 1
  * @rmtoll   DSET        FL_GPIO_SetOutputPin
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetOutputPin(GPIO_Type *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->DSET, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Set pin output 0
  * @rmtoll   DRST        FL_GPIO_ResetOutputPin
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_ResetOutputPin(GPIO_Type *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->DRST, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get input data
  * @rmtoll   DIN        FL_GPIO_ReadInputPort
  * @param    GPIOx GPIO Port
  * @retval   Input data register value of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadInputPort(GPIO_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->DIN, (0xffffU << 0U)) >> 0U);
}


/**
  * @brief    Get GPIO input set status
  * @rmtoll   DIN        FL_GPIO_GetInputPin
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_GetInputPin(GPIO_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->DIN, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Set GPIOx digital function 
  * @rmtoll   DFS        FL_GPIO_SetPinRemap
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @param    function This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PINREMAP_FUNCTON0
  *           @arg @ref FL_GPIO_PINREMAP_FUNCTON1
  *           @arg @ref FL_GPIO_PINREMAP_FUNCTON2
  *           @arg @ref FL_GPIO_PINREMAP_FUNCTON3
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetPinRemap(GPIO_Type *GPIOx, uint32_t pin, uint32_t function)
{
    MODIFY_REG(GPIOx->DFS, ((pin * pin) * GPIO_DFS), ((pin * pin) * function));
}

/**
  * @brief    Get GPIOx digital function 
  * @rmtoll   DFS        FL_GPIO_GetPinRemap
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_GPIO_PINREMAP_FUNCTON0
  *           @arg @ref FL_GPIO_PINREMAP_FUNCTON1
  *           @arg @ref FL_GPIO_PINREMAP_FUNCTON2
  *           @arg @ref FL_GPIO_PINREMAP_FUNCTON3
  */
__STATIC_INLINE uint32_t FL_GPIO_GetPinRemap(GPIO_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->DFS, ((pin * pin) * GPIO_DFS)) / (pin * pin));
}

/**
  * @brief    Set Portx driving strength
  * @rmtoll   DSR        FL_GPIO_SetPinDriveStrength
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @param    strength This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_DRIVESTRENGTH_CLOSE
  *           @arg @ref FL_GPIO_DRIVESTRENGTH_X1
  *           @arg @ref FL_GPIO_DRIVESTRENGTH_X2
  *           @arg @ref FL_GPIO_DRIVESTRENGTH_X3
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetPinDriveStrength(GPIO_Type *GPIOx, uint32_t pin, uint32_t strength)
{
    MODIFY_REG(GPIOx->DSR, ((pin * pin) * GPIO_DSR), ((pin * pin) * strength));
}

/**
  * @brief    Get Portx driving strength
  * @rmtoll   DSR        FL_GPIO_GetPinDriveStrength
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_GPIO_DRIVESTRENGTH_CLOSE
  *           @arg @ref FL_GPIO_DRIVESTRENGTH_X1
  *           @arg @ref FL_GPIO_DRIVESTRENGTH_X2
  *           @arg @ref FL_GPIO_DRIVESTRENGTH_X3
  */
__STATIC_INLINE uint32_t FL_GPIO_GetPinDriveStrength(GPIO_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->DSR, ((pin * pin) * GPIO_DSR)) / (pin * pin));
}

/**
  * @brief    EXTI edge select 
  * @rmtoll   EXTIEDSA        FL_GPIO_SetTriggerEdgePA
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_RISING
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_FALLING
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_BOTH
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetTriggerEdgePA(GPIO_COMMON_Type *GPIOx, uint32_t pin, uint32_t edge)
{
    MODIFY_REG(GPIOx->EXTIEDSA, ((pin * pin) * GPIO_EXTIEDSA), ((pin * pin) * edge));
}

/**
  * @brief    Get EXTI edge select
  * @rmtoll   EXTIEDSA        FL_GPIO_GetTriggerEdgePA
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_GetTriggerEdgePA(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIEDSA, ((pin * pin) * GPIO_EXTIEDSA)) / (pin * pin));
}

/**
  * @brief    EXTI edge select 
  * @rmtoll   EXTIEDSB        FL_GPIO_SetTriggerEdgePB
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_RISING
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_FALLING
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_BOTH
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetTriggerEdgePB(GPIO_COMMON_Type *GPIOx, uint32_t pin, uint32_t edge)
{
    MODIFY_REG(GPIOx->EXTIEDSB, ((pin * pin) * GPIO_EXTIEDSB), ((pin * pin) * edge));
}

/**
  * @brief    Get EXTI edge select
  * @rmtoll   EXTIEDSB        FL_GPIO_GetTriggerEdgePB
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_GetTriggerEdgePB(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIEDSB, ((pin * pin) * GPIO_EXTIEDSB)) / (pin * pin));
}

/**
  * @brief    EXTI edge select 
  * @rmtoll   EXTIEDSC        FL_GPIO_SetTriggerEdgePC
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_RISING
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_FALLING
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_BOTH
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetTriggerEdgePC(GPIO_COMMON_Type *GPIOx, uint32_t pin, uint32_t edge)
{
    MODIFY_REG(GPIOx->EXTIEDSC, ((pin * pin) * GPIO_EXTIEDSC), ((pin * pin) * edge));
}

/**
  * @brief    Get EXTI edge select
  * @rmtoll   EXTIEDSC        FL_GPIO_GetTriggerEdgePC
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_GetTriggerEdgePC(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIEDSC, ((pin * pin) * GPIO_EXTIEDSC)) / (pin * pin));
}

/**
  * @brief    EXTI edge select 
  * @rmtoll   EXTIEDSD        FL_GPIO_SetTriggerEdgePD
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_RISING
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_FALLING
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_BOTH
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetTriggerEdgePD(GPIO_COMMON_Type *GPIOx, uint32_t pin, uint32_t edge)
{
    MODIFY_REG(GPIOx->EXTIEDSD, ((pin * pin) * GPIO_EXTIEDSD), ((pin * pin) * edge));
}

/**
  * @brief    Get EXTI edge select
  * @rmtoll   EXTIEDSD        FL_GPIO_GetTriggerEdgePD
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_GetTriggerEdgePD(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIEDSD, ((pin * pin) * GPIO_EXTIEDSD)) / (pin * pin));
}

/**
  * @brief    EXTI edge select 
  * @rmtoll   EXTIEDSE        FL_GPIO_SetTriggerEdgePE
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_RISING
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_FALLING
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_BOTH
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetTriggerEdgePE(GPIO_COMMON_Type *GPIOx, uint32_t pin, uint32_t edge)
{
    MODIFY_REG(GPIOx->EXTIEDSE, ((pin * pin) * GPIO_EXTIEDSE), ((pin * pin) * edge));
}

/**
  * @brief    Get EXTI edge select
  * @rmtoll   EXTIEDSE        FL_GPIO_GetTriggerEdgePE
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_GetTriggerEdgePE(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIEDSE, ((pin * pin) * GPIO_EXTIEDSE)) / (pin * pin));
}

/**
  * @brief    EXTI edge select 
  * @rmtoll   EXTIEDSF        FL_GPIO_SetTriggerEdgePF
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_RISING
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_FALLING
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_BOTH
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetTriggerEdgePF(GPIO_COMMON_Type *GPIOx, uint32_t pin, uint32_t edge)
{
    MODIFY_REG(GPIOx->EXTIEDSF, ((pin * pin) * GPIO_EXTIEDSF), ((pin * pin) * edge));
}

/**
  * @brief    Get EXTI edge select
  * @rmtoll   EXTIEDSF        FL_GPIO_GetTriggerEdgePF
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_GetTriggerEdgePF(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIEDSF, ((pin * pin) * GPIO_EXTIEDSF)) / (pin * pin));
}

/**
  * @brief    EXTI edge select 
  * @rmtoll   EXTIEDSG        FL_GPIO_SetTriggerEdgePG
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_RISING
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_FALLING
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_BOTH
  *           @arg @ref FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetTriggerEdgePG(GPIO_COMMON_Type *GPIOx, uint32_t pin, uint32_t edge)
{
    MODIFY_REG(GPIOx->EXTIEDSG, ((pin * pin) * GPIO_EXTIEDSG), ((pin * pin) * edge));
}

/**
  * @brief    Get EXTI edge select
  * @rmtoll   EXTIEDSG        FL_GPIO_GetTriggerEdgePG
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_GetTriggerEdgePG(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIEDSG, ((pin * pin) * GPIO_EXTIEDSG)) / (pin * pin));
}

/**
  * @brief    PA EXTI digital filter enable
  * @rmtoll   EXTIDFAB    DFA    FL_GPIO_EnableDigitalFilterPA
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_EnableDigitalFilterPA(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->EXTIDFAB, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    PA EXTI digital filter disable
  * @rmtoll   EXTIDFAB    DFA    FL_GPIO_DisableDigitalFilterPA
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_DisableDigitalFilterPA(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    CLEAR_BIT(GPIOx->EXTIDFAB, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PA EXTI digital filter enable status
  * @rmtoll   EXTIDFAB    DFA    FL_GPIO_IsEnabledDigitalFilterPA
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_IsEnabledDigitalFilterPA(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFAB, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get ALL PA EXTI digital filter enable status
  * @rmtoll   EXTIDFAB    DFA    FL_GPIO_ReadDigitalFilterPA
  * @param    GPIOx GPIO Port
  * @retval   EXTI digital filter enable status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadDigitalFilterPA(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFAB, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    PB EXTI digital filter enable
  * @rmtoll   EXTIDFAB    DFB    FL_GPIO_EnableDigitalFilterPB
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_EnableDigitalFilterPB(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->EXTIDFAB, ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    PB EXTI digital filter disable
  * @rmtoll   EXTIDFAB    DFB    FL_GPIO_DisableDigitalFilterPB
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_DisableDigitalFilterPB(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    CLEAR_BIT(GPIOx->EXTIDFAB, ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get PB EXTI digital filter enable status
  * @rmtoll   EXTIDFAB    DFB    FL_GPIO_IsEnabledDigitalFilterPB
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_IsEnabledDigitalFilterPB(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFAB, ((pin & 0xffff) << 0x10U)) == ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get ALL PB EXTI digital filter enable status
  * @rmtoll   EXTIDFAB    DFB    FL_GPIO_ReadDigitalFilterPB
  * @param    GPIOx GPIO Port
  * @retval   EXTI digital filter enable status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadDigitalFilterPB(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFAB, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    PC EXTI digital filter enable
  * @rmtoll   EXTIDFCD    DFC    FL_GPIO_EnableDigitalFilterPC
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_EnableDigitalFilterPC(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->EXTIDFCD, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    PC EXTI digital filter disable
  * @rmtoll   EXTIDFCD    DFC    FL_GPIO_DisableDigitalFilterPC
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_DisableDigitalFilterPC(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    CLEAR_BIT(GPIOx->EXTIDFCD, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PC EXTI digital filter enable status
  * @rmtoll   EXTIDFCD    DFC    FL_GPIO_IsEnabledDigitalFilterPC
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_IsEnabledDigitalFilterPC(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFCD, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get All PC EXTI digital filter enable status
  * @rmtoll   EXTIDFCD    DFC    FL_GPIO_ReadDigitalFilterPC
  * @param    GPIOx GPIO Port
  * @retval   EXTI digital filter enable status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadDigitalFilterPC(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFCD, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    PD EXTI digital filter enable
  * @rmtoll   EXTIDFCD    DFD    FL_GPIO_EnableDigitalFilterPD
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_EnableDigitalFilterPD(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->EXTIDFCD, ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    PD EXTI digital filter disable
  * @rmtoll   EXTIDFCD    DFD    FL_GPIO_DisableDigitalFilterPD
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_DisableDigitalFilterPD(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    CLEAR_BIT(GPIOx->EXTIDFCD, ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get PD EXTI digital filter enable status
  * @rmtoll   EXTIDFCD    DFD    FL_GPIO_IsEnabledDigitalFilterPD
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_IsEnabledDigitalFilterPD(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFCD, ((pin & 0xffff) << 0x10U)) == ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get ALL PD EXTI digital filter enable status
  * @rmtoll   EXTIDFCD    DFD    FL_GPIO_ReadDigitalFilterPD
  * @param    GPIOx GPIO Port
  * @retval   EXTI digital filter enable status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadDigitalFilterPD(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFCD, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    PE EXTI digital filter enable
  * @rmtoll   EXTIDFEF    DFE    FL_GPIO_EnableDigitalFilterPE
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_EnableDigitalFilterPE(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->EXTIDFEF, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    PE EXTI digital filter disable
  * @rmtoll   EXTIDFEF    DFE    FL_GPIO_DisableDigitalFilterPE
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_DisableDigitalFilterPE(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    CLEAR_BIT(GPIOx->EXTIDFEF, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PE EXTI digital filter enable status
  * @rmtoll   EXTIDFEF    DFE    FL_GPIO_IsEnabledDigitalFilterPE
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_IsEnabledDigitalFilterPE(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFEF, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get ALl PE EXTI digital filter enable status
  * @rmtoll   EXTIDFEF    DFE    FL_GPIO_ReadDigitalFilterPE
  * @param    GPIOx GPIO Port
  * @retval   EXTI digital filter enable status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadDigitalFilterPE(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFEF, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    PF EXTI digital filter enable
  * @rmtoll   EXTIDFEF    DFF    FL_GPIO_EnableDigitalFilterPF
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_EnableDigitalFilterPF(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->EXTIDFEF, ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    PF EXTI digital filter disable
  * @rmtoll   EXTIDFEF    DFF    FL_GPIO_DisableDigitalFilterPF
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_DisableDigitalFilterPF(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    CLEAR_BIT(GPIOx->EXTIDFEF, ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get PF EXTI digital filter enable status
  * @rmtoll   EXTIDFEF    DFF    FL_GPIO_IsEnabledDigitalFilterPF
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_IsEnabledDigitalFilterPF(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFEF, ((pin & 0xffff) << 0x10U)) == ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get ALL PF EXTI digital filter enable status
  * @rmtoll   EXTIDFEF    DFF    FL_GPIO_ReadDigitalFilterPF
  * @param    GPIOx GPIO Port
  * @retval   EXTI digital filter enable status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadDigitalFilterPF(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFEF, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    PG EXTI digital filter enable
  * @rmtoll   EXTIDFGH    DFG    FL_GPIO_EnableDigitalFilterPG
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_EnableDigitalFilterPG(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->EXTIDFGH, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    PG EXTI digital filter disable
  * @rmtoll   EXTIDFGH    DFG    FL_GPIO_DisableDigitalFilterPG
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_DisableDigitalFilterPG(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    CLEAR_BIT(GPIOx->EXTIDFGH, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PG EXTI digital filter enable status
  * @rmtoll   EXTIDFGH    DFG    FL_GPIO_IsEnabledDigitalFilterPG
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_IsEnabledDigitalFilterPG(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFGH, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get ALL PG EXTI digital filter enable status
  * @rmtoll   EXTIDFGH    DFG    FL_GPIO_ReadDigitalFilterPG
  * @param    GPIOx GPIO Port
  * @retval   EXTI digital filter enable status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadDigitalFilterPG(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFGH, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    PH EXTI digital filter enable
  * @rmtoll   EXTIDFGH    DFH    FL_GPIO_EnableDigitalFilterPH
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_EnableDigitalFilterPH(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->EXTIDFGH, ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    PH EXTI digital filter disable
  * @rmtoll   EXTIDFGH    DFH    FL_GPIO_DisableDigitalFilterPH
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_DisableDigitalFilterPH(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    CLEAR_BIT(GPIOx->EXTIDFGH, ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get PH EXTI digital filter enable status
  * @rmtoll   EXTIDFGH    DFH    FL_GPIO_IsEnabledDigitalFilterPH
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_IsEnabledDigitalFilterPH(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFGH, ((pin & 0xffff) << 0x10U)) == ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get ALL PH EXTI digital filter enable status
  * @rmtoll   EXTIDFGH    DFH    FL_GPIO_ReadDigitalFilterPH
  * @param    GPIOx GPIO Port
  * @retval   EXTI digital filter enable status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadDigitalFilterPH(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDFGH, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Get PA external interrupt flag status
  * @rmtoll   EXTIISRAB    ISRA    FL_GPIO_ReadEXTI_PA
  * @param    GPIOx GPIO Port
  * @retval   EXTI flag status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTI_PA(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISRAB, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get PA external interrupt flag status
  * @rmtoll   EXTIISRAB    ISRA    FL_GPIO_IsActiveFlag_EXTI_PA
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_IsActiveFlag_EXTI_PA(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISRAB, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Clear PA external interrupt flag 
  * @rmtoll   EXTIISRAB    ISRA    FL_GPIO_ClearFlag_EXTI_PA
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_ClearFlag_EXTI_PA(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    WRITE_REG(GPIOx->EXTIISRAB, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PB external interrupt flag status
  * @rmtoll   EXTIISRAB    ISRB    FL_GPIO_ReadEXTI_PB
  * @param    GPIOx GPIO Port
  * @retval   EXTI flag status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTI_PB(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISRAB, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Get PB external interrupt flag status
  * @rmtoll   EXTIISRAB    ISRB    FL_GPIO_IsActiveFlag_EXTI_PB
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_IsActiveFlag_EXTI_PB(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISRAB, ((pin & 0xffff) << 0x10U)) == ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Clear PB external interrupt flag 
  * @rmtoll   EXTIISRAB    ISRB    FL_GPIO_ClearFlag_EXTI_PB
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_ClearFlag_EXTI_PB(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    WRITE_REG(GPIOx->EXTIISRAB, ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get PC external interrupt flag status
  * @rmtoll   EXTIISRCD    ISRC    FL_GPIO_ReadEXTI_PC
  * @param    GPIOx GPIO Port
  * @retval   EXTI flag status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTI_PC(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISRCD, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get PC external interrupt flag status
  * @rmtoll   EXTIISRCD    ISRC    FL_GPIO_IsActiveFlag_EXTI_PC
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_IsActiveFlag_EXTI_PC(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISRCD, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Clear PC external interrupt flag 
  * @rmtoll   EXTIISRCD    ISRC    FL_GPIO_ClearFlag_EXTI_PC
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_ClearFlag_EXTI_PC(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    WRITE_REG(GPIOx->EXTIISRCD, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PD external interrupt flag status
  * @rmtoll   EXTIISRCD    ISRD    FL_GPIO_ReadEXTI_PD
  * @param    GPIOx GPIO Port
  * @retval   EXTI flag status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTI_PD(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISRCD, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Get PD external interrupt flag status
  * @rmtoll   EXTIISRCD    ISRD    FL_GPIO_IsActiveFlag_EXTI_PD
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_IsActiveFlag_EXTI_PD(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISRCD, ((pin & 0xffff) << 0x10U)) == ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Clear PD external interrupt flag 
  * @rmtoll   EXTIISRCD    ISRD    FL_GPIO_ClearFlag_EXTI_PD
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_ClearFlag_EXTI_PD(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    WRITE_REG(GPIOx->EXTIISRCD, ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get PE external interrupt flag status
  * @rmtoll   EXTIISREF    ISRE    FL_GPIO_ReadEXTI_PE
  * @param    GPIOx GPIO Port
  * @retval   EXTI flag status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTI_PE(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISREF, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get PE external interrupt flag status
  * @rmtoll   EXTIISREF    ISRE    FL_GPIO_IsActiveFlag_EXTI_PE
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_IsActiveFlag_EXTI_PE(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISREF, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Clear PE external interrupt flag 
  * @rmtoll   EXTIISREF    ISRE    FL_GPIO_ClearFlag_EXTI_PE
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_ClearFlag_EXTI_PE(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    WRITE_REG(GPIOx->EXTIISREF, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PF external interrupt flag status
  * @rmtoll   EXTIISREF    ISRF    FL_GPIO_ReadEXTI_PF
  * @param    GPIOx GPIO Port
  * @retval   EXTI flag status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTI_PF(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISREF, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Get PF external interrupt flag status
  * @rmtoll   EXTIISREF    ISRF    FL_GPIO_IsActiveFlag_EXTI_PF
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_IsActiveFlag_EXTI_PF(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISREF, ((pin & 0xffff) << 0x10U)) == ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Clear PF external interrupt flag 
  * @rmtoll   EXTIISREF    ISRF    FL_GPIO_ClearFlag_EXTI_PF
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_ClearFlag_EXTI_PF(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    WRITE_REG(GPIOx->EXTIISREF, ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get PG external interrupt flag status
  * @rmtoll   EXTIISRGH    ISRG    FL_GPIO_ReadEXTI_PG
  * @param    GPIOx GPIO Port
  * @retval   EXTI flag status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTI_PG(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISRGH, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get PG external interrupt flag status
  * @rmtoll   EXTIISRGH    ISRG    FL_GPIO_IsActiveFlag_EXTI_PG
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_IsActiveFlag_EXTI_PG(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISRGH, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Clear PG external interrupt flag 
  * @rmtoll   EXTIISRGH    ISRG    FL_GPIO_ClearFlag_EXTI_PG
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_ClearFlag_EXTI_PG(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    WRITE_REG(GPIOx->EXTIISRGH, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PH external interrupt flag status
  * @rmtoll   EXTIISRGH    ISRH    FL_GPIO_ReadEXTI_PH
  * @param    GPIOx GPIO Port
  * @retval   EXTI flag status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTI_PH(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISRGH, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Get PH external interrupt flag status
  * @rmtoll   EXTIISRGH    ISRH    FL_GPIO_IsActiveFlag_EXTI_PH
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_GPIO_IsActiveFlag_EXTI_PH(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIISRGH, ((pin & 0xffff) << 0x10U)) == ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Clear PH external interrupt flag 
  * @rmtoll   EXTIISRGH    ISRH    FL_GPIO_ClearFlag_EXTI_PH
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  *           @arg @ref FL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_ClearFlag_EXTI_PH(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    WRITE_REG(GPIOx->EXTIISRGH, ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get PA EXTI input set status
  * @rmtoll   EXTIDIAB    DIA    FL_GPIO_GetEXTIInputPinPA
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_GetEXTIInputPinPA(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDIAB, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PA EXTI input status
  * @rmtoll   EXTIDIAB    DIA    FL_GPIO_ReadEXTIInputPA
  * @param    GPIOx GPIO Port
  * @retval   EXTI data register value of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTIInputPA(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDIAB, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get PB EXTI input set status
  * @rmtoll   EXTIDIAB    DIB    FL_GPIO_GetEXTIInputPinPB
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_GetEXTIInputPinPB(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDIAB, ((pin & 0xffff) << 0x10U)) == ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get PB EXTI input status
  * @rmtoll   EXTIDIAB    DIB    FL_GPIO_ReadEXTIInpuPB
  * @param    GPIOx GPIO Port
  * @retval   EXTI data register value of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTIInpuPB(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDIAB, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Get PC EXTI input set status
  * @rmtoll   EXTIDICD    DIC    FL_GPIO_GetEXTIInputPinPC
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_GetEXTIInputPinPC(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDICD, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PC EXTI input status
  * @rmtoll   EXTIDICD    DIC    FL_GPIO_ReadEXTIInputPC
  * @param    GPIOx GPIO Port
  * @retval   EXTI data register value of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTIInputPC(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDICD, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get PD EXTI input set status
  * @rmtoll   EXTIDICD    DID    FL_GPIO_GetEXTIInputPinPD
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_GetEXTIInputPinPD(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDICD, ((pin & 0xffff) << 0x10U)) == ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get PD EXTI input status
  * @rmtoll   EXTIDICD    DID    FL_GPIO_ReadEXTIInputPD
  * @param    GPIOx GPIO Port
  * @retval   EXTI data register value of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTIInputPD(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDICD, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Get PE EXTI input set status
  * @rmtoll   EXTIDIEF    DIE    FL_GPIO_GetEXTIInputPinPE
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_GetEXTIInputPinPE(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDIEF, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PE EXTI input status
  * @rmtoll   EXTIDIEF    DIE    FL_GPIO_ReadEXTIInputPE
  * @param    GPIOx GPIO Port
  * @retval   EXTI data register value of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTIInputPE(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDIEF, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get PF EXTI input set status
  * @rmtoll   EXTIDIEF    DIF    FL_GPIO_GetEXTIInputPinPF
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_GetEXTIInputPinPF(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDIEF, ((pin & 0xffff) << 0x10U)) == ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get PF EXTI input status
  * @rmtoll   EXTIDIEF    DIF    FL_GPIO_ReadEXTIInputPF
  * @param    GPIOx GPIO Port
  * @retval   EXTI data register value of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTIInputPF(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDIEF, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Get PG EXTI input set status
  * @rmtoll   EXTIDIGH    DIG    FL_GPIO_GetEXTIInputPinPG
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_GetEXTIInputPinPG(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDIGH, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PG EXTI input status
  * @rmtoll   EXTIDIGH    DIG    FL_GPIO_ReadEXTIInputPG
  * @param    GPIOx GPIO Port
  * @retval   EXTI data register value of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTIInputPG(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDIGH, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get PH EXTI input set status
  * @rmtoll   EXTIDIGH    DIH    FL_GPIO_GetEXTIInputPinPH
  * @param    GPIOx GPIO Port
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_PIN_0
  *           @arg @ref FL_GPIO_PIN_1
  *           @arg @ref FL_GPIO_PIN_2
  *           @arg @ref FL_GPIO_PIN_3
  *           @arg @ref FL_GPIO_PIN_4
  *           @arg @ref FL_GPIO_PIN_5
  *           @arg @ref FL_GPIO_PIN_6
  *           @arg @ref FL_GPIO_PIN_7
  *           @arg @ref FL_GPIO_PIN_8
  *           @arg @ref FL_GPIO_PIN_9
  *           @arg @ref FL_GPIO_PIN_10
  *           @arg @ref FL_GPIO_PIN_11
  *           @arg @ref FL_GPIO_PIN_12
  *           @arg @ref FL_GPIO_PIN_13
  *           @arg @ref FL_GPIO_PIN_14
  *           @arg @ref FL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_GetEXTIInputPinPH(GPIO_COMMON_Type *GPIOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDIGH, ((pin & 0xffff) << 0x10U)) == ((pin & 0xffff) << 0x10U));
}

/**
  * @brief    Get PH EXTI input status
  * @rmtoll   EXTIDIGH    DIH    FL_GPIO_ReadEXTIInputPH
  * @param    GPIOx GPIO Port
  * @retval   EXTI data register value of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadEXTIInputPH(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->EXTIDIGH, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Set PD11 or PE7 frequency output
  * @rmtoll   FOUTSEL    FOUT0    FL_GPIO_SetFOUT0
  * @param    GPIOx GPIO Port
  * @param    select This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_FOUT0_SELECT_XTLF
  *           @arg @ref FL_GPIO_FOUT0_SELECT_RCLP
  *           @arg @ref FL_GPIO_FOUT0_SELECT_RCHF_DIV64
  *           @arg @ref FL_GPIO_FOUT0_SELECT_LSCLK
  *           @arg @ref FL_GPIO_FOUT0_SELECT_AHBCLK_DIV64
  *           @arg @ref FL_GPIO_FOUT0_SELECT_RTCTM
  *           @arg @ref FL_GPIO_FOUT0_SELECT_PLL_DIV64
  *           @arg @ref FL_GPIO_FOUT0_SELECT_RTCCLK64HZ
  *           @arg @ref FL_GPIO_FOUT0_SELECT_APBCLK1_DIV64
  *           @arg @ref FL_GPIO_FOUT0_SELECT_PLL
  *           @arg @ref FL_GPIO_FOUT0_SELECT_FDCAN_TXCLK
  *           @arg @ref FL_GPIO_FOUT0_SELECT_RCHF
  *           @arg @ref FL_GPIO_FOUT0_SELECT_XTHF_DIV64
  *           @arg @ref FL_GPIO_FOUT0_SELECT_ADC_SOC
  *           @arg @ref FL_GPIO_FOUT0_SELECT_CLK8K
  *           @arg @ref FL_GPIO_FOUT0_SELECT_ADC_CLK
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetFOUT0(GPIO_COMMON_Type *GPIOx, uint32_t select)
{
    MODIFY_REG(GPIOx->FOUTSEL, GPIO_FOUTSEL_FOUT0_Msk, select);
}

/**
  * @brief    Get  PD11 or PE7 frequency output
  * @rmtoll   FOUTSEL    FOUT0    FL_GPIO_GetFOUT0
  * @param    GPIOx GPIO Port
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_GPIO_FOUT0_SELECT_XTLF
  *           @arg @ref FL_GPIO_FOUT0_SELECT_RCLP
  *           @arg @ref FL_GPIO_FOUT0_SELECT_RCHF_DIV64
  *           @arg @ref FL_GPIO_FOUT0_SELECT_LSCLK
  *           @arg @ref FL_GPIO_FOUT0_SELECT_AHBCLK_DIV64
  *           @arg @ref FL_GPIO_FOUT0_SELECT_RTCTM
  *           @arg @ref FL_GPIO_FOUT0_SELECT_PLL_DIV64
  *           @arg @ref FL_GPIO_FOUT0_SELECT_RTCCLK64HZ
  *           @arg @ref FL_GPIO_FOUT0_SELECT_APBCLK1_DIV64
  *           @arg @ref FL_GPIO_FOUT0_SELECT_PLL
  *           @arg @ref FL_GPIO_FOUT0_SELECT_FDCAN_TXCLK
  *           @arg @ref FL_GPIO_FOUT0_SELECT_RCHF
  *           @arg @ref FL_GPIO_FOUT0_SELECT_XTHF_DIV64
  *           @arg @ref FL_GPIO_FOUT0_SELECT_ADC_SOC
  *           @arg @ref FL_GPIO_FOUT0_SELECT_CLK8K
  *           @arg @ref FL_GPIO_FOUT0_SELECT_ADC_CLK
  */
__STATIC_INLINE uint32_t FL_GPIO_GetFOUT0(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->FOUTSEL, GPIO_FOUTSEL_FOUT0_Msk));
}

/**
  * @brief    Set PB12 frequency output
  * @rmtoll   FOUTSEL    FOUT1    FL_GPIO_SetFOUT1
  * @param    GPIOx GPIO Port
  * @param    select This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_FOUT1_SELECT_XTLF
  *           @arg @ref FL_GPIO_FOUT1_SELECT_RCLP
  *           @arg @ref FL_GPIO_FOUT1_SELECT_ADC_CLK
  *           @arg @ref FL_GPIO_FOUT1_SELECT_LSCLK
  *           @arg @ref FL_GPIO_FOUT1_SELECT_ADC_EOC
  *           @arg @ref FL_GPIO_FOUT1_SELECT_RTCTM
  *           @arg @ref FL_GPIO_FOUT1_SELECT_PLL_DIV64
  *           @arg @ref FL_GPIO_FOUT1_SELECT_APBCLK1_DIV64
  *           @arg @ref FL_GPIO_FOUT1_SELECT_PLL
  *           @arg @ref FL_GPIO_FOUT1_SELECT_FDCAN_TXCLK
  *           @arg @ref FL_GPIO_FOUT1_SELECT_RCHF
  *           @arg @ref FL_GPIO_FOUT1_SELECT_XTHF_DIV64
  *           @arg @ref FL_GPIO_FOUT1_SELECT_ADCCLK_DIV64
  *           @arg @ref FL_GPIO_FOUT1_SELECT_CLK8K
  *           @arg @ref FL_GPIO_FOUT1_SELECT_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetFOUT1(GPIO_COMMON_Type *GPIOx, uint32_t select)
{
    MODIFY_REG(GPIOx->FOUTSEL, GPIO_FOUTSEL_FOUT1_Msk, select);
}

/**
  * @brief    Get PB12 frequency output
  * @rmtoll   FOUTSEL    FOUT1    FL_GPIO_GetFOUT1
  * @param    GPIOx GPIO Port
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_GPIO_FOUT1_SELECT_XTLF
  *           @arg @ref FL_GPIO_FOUT1_SELECT_RCLP
  *           @arg @ref FL_GPIO_FOUT1_SELECT_ADC_CLK
  *           @arg @ref FL_GPIO_FOUT1_SELECT_LSCLK
  *           @arg @ref FL_GPIO_FOUT1_SELECT_ADC_EOC
  *           @arg @ref FL_GPIO_FOUT1_SELECT_RTCTM
  *           @arg @ref FL_GPIO_FOUT1_SELECT_PLL_DIV64
  *           @arg @ref FL_GPIO_FOUT1_SELECT_APBCLK1_DIV64
  *           @arg @ref FL_GPIO_FOUT1_SELECT_PLL
  *           @arg @ref FL_GPIO_FOUT1_SELECT_FDCAN_TXCLK
  *           @arg @ref FL_GPIO_FOUT1_SELECT_RCHF
  *           @arg @ref FL_GPIO_FOUT1_SELECT_XTHF_DIV64
  *           @arg @ref FL_GPIO_FOUT1_SELECT_ADCCLK_DIV64
  *           @arg @ref FL_GPIO_FOUT1_SELECT_CLK8K
  *           @arg @ref FL_GPIO_FOUT1_SELECT_XTHF
  */
__STATIC_INLINE uint32_t FL_GPIO_GetFOUT1(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->FOUTSEL, GPIO_FOUTSEL_FOUT1_Msk));
}

/**
  * @brief    Get WKUP enable status
  * @rmtoll   PINWKEN    EN    FL_GPIO_ReadWakeup
  * @param    GPIOx GPIO Port
  * @retval   WKUP enable status of port
  */
__STATIC_INLINE uint32_t FL_GPIO_ReadWakeup(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->PINWKEN, (0x3ffU << 0U)) >> 0U);
}

/**
  * @brief    Get WKUP enable status
  * @rmtoll   PINWKEN    EN    FL_GPIO_IsEnabledWakeup
  * @param    GPIOx GPIO Port
  * @param    wakeup This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_WAKEUP_0
  *           @arg @ref FL_GPIO_WAKEUP_1
  *           @arg @ref FL_GPIO_WAKEUP_2
  *           @arg @ref FL_GPIO_WAKEUP_3
  *           @arg @ref FL_GPIO_WAKEUP_4
  *           @arg @ref FL_GPIO_WAKEUP_5
  *           @arg @ref FL_GPIO_WAKEUP_6
  *           @arg @ref FL_GPIO_WAKEUP_7
  *           @arg @ref FL_GPIO_WAKEUP_8
  *           @arg @ref FL_GPIO_WAKEUP_9
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_GPIO_IsEnabledWakeup(GPIO_COMMON_Type *GPIOx, uint32_t wakeup)
{
    return (uint32_t)(READ_BIT(GPIOx->PINWKEN, ((wakeup & 0x3ff) << 0x0U)) == ((wakeup & 0x3ff) << 0x0U));
}

/**
  * @brief    WKUP enable
  * @rmtoll   PINWKEN    EN    FL_GPIO_EnableWakeup
  * @param    GPIOx GPIO Port
  * @param    wakeup This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_WAKEUP_0
  *           @arg @ref FL_GPIO_WAKEUP_1
  *           @arg @ref FL_GPIO_WAKEUP_2
  *           @arg @ref FL_GPIO_WAKEUP_3
  *           @arg @ref FL_GPIO_WAKEUP_4
  *           @arg @ref FL_GPIO_WAKEUP_5
  *           @arg @ref FL_GPIO_WAKEUP_6
  *           @arg @ref FL_GPIO_WAKEUP_7
  *           @arg @ref FL_GPIO_WAKEUP_8
  *           @arg @ref FL_GPIO_WAKEUP_9
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_EnableWakeup(GPIO_COMMON_Type *GPIOx, uint32_t wakeup)
{
    SET_BIT(GPIOx->PINWKEN, ((wakeup & 0x3ff) << 0x0U));
}

/**
  * @brief    WKUP disable
  * @rmtoll   PINWKEN    EN    FL_GPIO_DisableWakeup
  * @param    GPIOx GPIO Port
  * @param    wakeup This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_WAKEUP_0
  *           @arg @ref FL_GPIO_WAKEUP_1
  *           @arg @ref FL_GPIO_WAKEUP_2
  *           @arg @ref FL_GPIO_WAKEUP_3
  *           @arg @ref FL_GPIO_WAKEUP_4
  *           @arg @ref FL_GPIO_WAKEUP_5
  *           @arg @ref FL_GPIO_WAKEUP_6
  *           @arg @ref FL_GPIO_WAKEUP_7
  *           @arg @ref FL_GPIO_WAKEUP_8
  *           @arg @ref FL_GPIO_WAKEUP_9
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_DisableWakeup(GPIO_COMMON_Type *GPIOx, uint32_t wakeup)
{
    CLEAR_BIT(GPIOx->PINWKEN, ((wakeup & 0x3ff) << 0x0U));
}

/**
  * @brief    Set WKUP edge polarity
  * @rmtoll   PINWKEN    SEL    FL_GPIO_SetWakeupEdge
  * @param    GPIOx GPIO Port
  * @param    wakeup This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_WAKEUP_0
  *           @arg @ref FL_GPIO_WAKEUP_1
  *           @arg @ref FL_GPIO_WAKEUP_2
  *           @arg @ref FL_GPIO_WAKEUP_3
  *           @arg @ref FL_GPIO_WAKEUP_4
  *           @arg @ref FL_GPIO_WAKEUP_5
  *           @arg @ref FL_GPIO_WAKEUP_6
  *           @arg @ref FL_GPIO_WAKEUP_7
  *           @arg @ref FL_GPIO_WAKEUP_8
  *           @arg @ref FL_GPIO_WAKEUP_9
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_WAKEUP_TRIGGER_FALLING
  *           @arg @ref FL_GPIO_WAKEUP_TRIGGER_RISING
  *           @arg @ref FL_GPIO_WAKEUP_TRIGGER_BOTH
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetWakeupEdge(GPIO_COMMON_Type *GPIOx, uint32_t wakeup, uint32_t mode)
{
    MODIFY_REG(GPIOx->PINWKEN, ((wakeup * wakeup) * GPIO_PINWKEN_SEL), ((wakeup * wakeup) * mode));
}

/**
  * @brief    Get WKUP edge polarity
  * @rmtoll   PINWKEN    SEL    FL_GPIO_GetWakeupEdge
  * @param    GPIOx GPIO Port
  * @param    wakeup This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_WAKEUP_0
  *           @arg @ref FL_GPIO_WAKEUP_1
  *           @arg @ref FL_GPIO_WAKEUP_2
  *           @arg @ref FL_GPIO_WAKEUP_3
  *           @arg @ref FL_GPIO_WAKEUP_4
  *           @arg @ref FL_GPIO_WAKEUP_5
  *           @arg @ref FL_GPIO_WAKEUP_6
  *           @arg @ref FL_GPIO_WAKEUP_7
  *           @arg @ref FL_GPIO_WAKEUP_8
  *           @arg @ref FL_GPIO_WAKEUP_9
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_GPIO_WAKEUP_TRIGGER_FALLING
  *           @arg @ref FL_GPIO_WAKEUP_TRIGGER_RISING
  */
__STATIC_INLINE uint32_t FL_GPIO_GetWakeupEdge(GPIO_COMMON_Type *GPIOx, uint32_t wakeup)
{
    return (uint32_t)(READ_BIT(GPIOx->PINWKEN, ((wakeup * wakeup) * GPIO_PINWKEN_SEL)) / (wakeup * wakeup));
}

/**
  * @brief    Get WKUP interrupt entry
  * @rmtoll   PINWKEN    WKSEL    FL_GPIO_GetWakeupInterruptEntry
  * @param    GPIOx GPIO Port
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_GPIO_WAKEUP_INT_ENTRY_NMI
  *           @arg @ref FL_GPIO_WAKEUP_INT_ENTRY_38
  */
__STATIC_INLINE uint32_t FL_GPIO_GetWakeupInterruptEntry(GPIO_COMMON_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->PINWKEN, GPIO_PINWKEN_WKSEL_Msk));
}

/**
  * @brief    Set WKUP interrupt entry
  * @rmtoll   PINWKEN    WKSEL    FL_GPIO_SetWakeupInterruptEntry
  * @param    GPIOx GPIO Port
  * @param    wakeup This parameter can be one of the following values:
  *           @arg @ref FL_GPIO_WAKEUP_INT_ENTRY_NMI
  *           @arg @ref FL_GPIO_WAKEUP_INT_ENTRY_38
  * @retval   None
  */
__STATIC_INLINE void FL_GPIO_SetWakeupInterruptEntry(GPIO_COMMON_Type *GPIOx, uint32_t wakeup)
{
    MODIFY_REG(GPIOx->PINWKEN, GPIO_PINWKEN_WKSEL_Msk, wakeup);
}

/**
  * @}
  */
FL_ErrorStatus FL_GPIO_DeInit(GPIO_Type *GPIOx, uint32_t pin);
FL_ErrorStatus FL_GPIO_Init(GPIO_Type *GPIOx, FL_GPIO_InitTypeDef *initStruct);
void FL_GPIO_StructInit(FL_GPIO_InitTypeDef *initStruct);
FL_ErrorStatus FL_WKUP_Init(FL_WKUP_InitTypeDef *initStruct, uint32_t wakeup);
FL_ErrorStatus FL_WKUP_DeInit(uint32_t wkupx);
void FL_WKUP_StructInit(FL_WKUP_InitTypeDef *initStruct_Wakeup);
void FL_GPIO_ALLPIN_LPM_MODE(void);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_GPIO_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2024-01-04*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
