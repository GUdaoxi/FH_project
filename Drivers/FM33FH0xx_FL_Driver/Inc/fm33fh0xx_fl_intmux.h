/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_intmux.h
  * @author  FMSH Application Team
  * @brief   Head file of INTMUX FL Module
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
#ifndef __FM33FH0XX_FL_INTMUX_H
#define __FM33FH0XX_FL_INTMUX_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl_def.h"
/** @addtogroup FM33FH0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup CMU_FL_ES_INIT INTMUX Exported Init structures
  * @{
  */


/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup INTMUX_FL_Exported_Constants INTMUX Exported Constants
  * @{
  */


#define    INTMUX_CR2_MUX31SEL_Pos                                 (30U)
#define    INTMUX_CR2_MUX31SEL_Msk                                 (0x3U << INTMUX_CR2_MUX31SEL_Pos)
#define    INTMUX_CR2_MUX31SEL                                     INTMUX_CR2_MUX31SEL_Msk

#define    INTMUX_CR2_MUX30SEL_Pos                                 (28U)
#define    INTMUX_CR2_MUX30SEL_Msk                                 (0x3U << INTMUX_CR2_MUX30SEL_Pos)
#define    INTMUX_CR2_MUX30SEL                                     INTMUX_CR2_MUX30SEL_Msk

#define    INTMUX_CR2_MUX29SEL_Pos                                 (26U)
#define    INTMUX_CR2_MUX29SEL_Msk                                 (0x3U << INTMUX_CR2_MUX29SEL_Pos)
#define    INTMUX_CR2_MUX29SEL                                     INTMUX_CR2_MUX29SEL_Msk

#define    INTMUX_CR2_MUX28SEL_Pos                                 (24U)
#define    INTMUX_CR2_MUX28SEL_Msk                                 (0x3U << INTMUX_CR2_MUX28SEL_Pos)
#define    INTMUX_CR2_MUX28SEL                                     INTMUX_CR2_MUX28SEL_Msk

#define    INTMUX_CR2_MUX27SEL_Pos                                 (22U)
#define    INTMUX_CR2_MUX27SEL_Msk                                 (0x3U << INTMUX_CR2_MUX27SEL_Pos)
#define    INTMUX_CR2_MUX27SEL                                     INTMUX_CR2_MUX27SEL_Msk

#define    INTMUX_CR2_MUX26SEL_Pos                                 (20U)
#define    INTMUX_CR2_MUX26SEL_Msk                                 (0x3U << INTMUX_CR2_MUX26SEL_Pos)
#define    INTMUX_CR2_MUX26SEL                                     INTMUX_CR2_MUX26SEL_Msk

#define    INTMUX_CR2_MUX25SEL_Pos                                  (18U)
#define    INTMUX_CR2_MUX25SEL_Msk                                  (0x3U << INTMUX_CR2_MUX25SEL_Pos)
#define    INTMUX_CR2_MUX25SEL                                      INTMUX_CR2_MUX25SEL_Msk

#define    INTMUX_CR2_MUX24SEL_Pos                                  (16U)
#define    INTMUX_CR2_MUX24SEL_Msk                                  (0x3U << INTMUX_CR2_MUX24SEL_Pos)
#define    INTMUX_CR2_MUX24SEL                                      INTMUX_CR2_MUX24SEL_Msk

#define    INTMUX_CR2_MUX23SEL_Pos                                  (14U)
#define    INTMUX_CR2_MUX23SEL_Msk                                  (0x3U << INTMUX_CR2_MUX23SEL_Pos)
#define    INTMUX_CR2_MUX23SEL                                      INTMUX_CR2_MUX23SEL_Msk

#define    INTMUX_CR2_MUX22SEL_Pos                                  (12U)
#define    INTMUX_CR2_MUX22SEL_Msk                                  (0x3U << INTMUX_CR2_MUX22SEL_Pos)
#define    INTMUX_CR2_MUX22SEL                                      INTMUX_CR2_MUX22SEL_Msk

#define    INTMUX_CR2_MUX21SEL_Pos                                  (10U)
#define    INTMUX_CR2_MUX21SEL_Msk                                  (0x3U << INTMUX_CR2_MUX21SEL_Pos)
#define    INTMUX_CR2_MUX21SEL                                      INTMUX_CR2_MUX21SEL_Msk

#define    INTMUX_CR2_MUX20SEL_Pos                                  (8U)
#define    INTMUX_CR2_MUX20SEL_Msk                                  (0x3U << INTMUX_CR2_MUX20SEL_Pos)
#define    INTMUX_CR2_MUX20SEL                                      INTMUX_CR2_MUX20SEL_Msk

#define    INTMUX_CR2_MUX19SEL_Pos                                  (6U)
#define    INTMUX_CR2_MUX19SEL_Msk                                  (0x3U << INTMUX_CR2_MUX19SEL_Pos)
#define    INTMUX_CR2_MUX19SEL                                      INTMUX_CR2_MUX19SEL_Msk

#define    INTMUX_CR2_MUX18SEL_Pos                                  (4U)
#define    INTMUX_CR2_MUX18SEL_Msk                                  (0x3U << INTMUX_CR2_MUX18SEL_Pos)
#define    INTMUX_CR2_MUX18SEL                                      INTMUX_CR2_MUX18SEL_Msk

#define    INTMUX_CR2_MUX17SEL_Pos                                  (2U)
#define    INTMUX_CR2_MUX17SEL_Msk                                  (0x3U << INTMUX_CR2_MUX17SEL_Pos)
#define    INTMUX_CR2_MUX17SEL                                      INTMUX_CR2_MUX17SEL_Msk

#define    INTMUX_CR2_MUX16SEL_Pos                                  (0U)
#define    INTMUX_CR2_MUX16SEL_Msk                                  (0x3U << INTMUX_CR2_MUX16SEL_Pos)
#define    INTMUX_CR2_MUX16SEL                                      INTMUX_CR2_MUX16SEL_Msk

#define    INTMUX_CR1_MUX15SEL_Pos                                 (30U)
#define    INTMUX_CR1_MUX15SEL_Msk                                 (0x3U << INTMUX_CR1_MUX15SEL_Pos)
#define    INTMUX_CR1_MUX15SEL                                     INTMUX_CR1_MUX15SEL_Msk

#define    INTMUX_CR1_MUX14SEL_Pos                                 (28U)
#define    INTMUX_CR1_MUX14SEL_Msk                                 (0x3U << INTMUX_CR1_MUX14SEL_Pos)
#define    INTMUX_CR1_MUX14SEL                                     INTMUX_CR1_MUX14SEL_Msk

#define    INTMUX_CR1_MUX13SEL_Pos                                 (26U)
#define    INTMUX_CR1_MUX13SEL_Msk                                 (0x3U << INTMUX_CR1_MUX13SEL_Pos)
#define    INTMUX_CR1_MUX13SEL                                     INTMUX_CR1_MUX13SEL_Msk

#define    INTMUX_CR1_MUX12SEL_Pos                                 (24U)
#define    INTMUX_CR1_MUX12SEL_Msk                                 (0x3U << INTMUX_CR1_MUX12SEL_Pos)
#define    INTMUX_CR1_MUX12SEL                                     INTMUX_CR1_MUX12SEL_Msk

#define    INTMUX_CR1_MUX11SEL_Pos                                 (22U)
#define    INTMUX_CR1_MUX11SEL_Msk                                 (0x3U << INTMUX_CR1_MUX11SEL_Pos)
#define    INTMUX_CR1_MUX11SEL                                     INTMUX_CR1_MUX11SEL_Msk

#define    INTMUX_CR1_MUX10SEL_Pos                                 (20U)
#define    INTMUX_CR1_MUX10SEL_Msk                                 (0x3U << INTMUX_CR1_MUX10SEL_Pos)
#define    INTMUX_CR1_MUX10SEL                                     INTMUX_CR1_MUX10SEL_Msk

#define    INTMUX_CR1_MUX9SEL_Pos                                  (18U)
#define    INTMUX_CR1_MUX9SEL_Msk                                  (0x3U << INTMUX_CR1_MUX9SEL_Pos)
#define    INTMUX_CR1_MUX9SEL                                      INTMUX_CR1_MUX9SEL_Msk

#define    INTMUX_CR1_MUX8SEL_Pos                                  (16U)
#define    INTMUX_CR1_MUX8SEL_Msk                                  (0x3U << INTMUX_CR1_MUX8SEL_Pos)
#define    INTMUX_CR1_MUX8SEL                                      INTMUX_CR1_MUX8SEL_Msk

#define    INTMUX_CR1_MUX7SEL_Pos                                  (14U)
#define    INTMUX_CR1_MUX7SEL_Msk                                  (0x3U << INTMUX_CR1_MUX7SEL_Pos)
#define    INTMUX_CR1_MUX7SEL                                      INTMUX_CR1_MUX7SEL_Msk

#define    INTMUX_CR1_MUX6SEL_Pos                                  (12U)
#define    INTMUX_CR1_MUX6SEL_Msk                                  (0x3U << INTMUX_CR1_MUX6SEL_Pos)
#define    INTMUX_CR1_MUX6SEL                                      INTMUX_CR1_MUX6SEL_Msk

#define    INTMUX_CR1_MUX5SEL_Pos                                  (10U)
#define    INTMUX_CR1_MUX5SEL_Msk                                  (0x3U << INTMUX_CR1_MUX5SEL_Pos)
#define    INTMUX_CR1_MUX5SEL                                      INTMUX_CR1_MUX5SEL_Msk

#define    INTMUX_CR1_MUX4SEL_Pos                                  (8U)
#define    INTMUX_CR1_MUX4SEL_Msk                                  (0x3U << INTMUX_CR1_MUX4SEL_Pos)
#define    INTMUX_CR1_MUX4SEL                                      INTMUX_CR1_MUX4SEL_Msk

#define    INTMUX_CR1_MUX3SEL_Pos                                  (6U)
#define    INTMUX_CR1_MUX3SEL_Msk                                  (0x3U << INTMUX_CR1_MUX3SEL_Pos)
#define    INTMUX_CR1_MUX3SEL                                      INTMUX_CR1_MUX3SEL_Msk

#define    INTMUX_CR1_MUX2SEL_Pos                                  (4U)
#define    INTMUX_CR1_MUX2SEL_Msk                                  (0x3U << INTMUX_CR1_MUX2SEL_Pos)
#define    INTMUX_CR1_MUX2SEL                                      INTMUX_CR1_MUX2SEL_Msk

#define    INTMUX_CR1_MUX1SEL_Pos                                  (2U)
#define    INTMUX_CR1_MUX1SEL_Msk                                  (0x3U << INTMUX_CR1_MUX1SEL_Pos)
#define    INTMUX_CR1_MUX1SEL                                      INTMUX_CR1_MUX1SEL_Msk

#define    INTMUX_CR1_MUX0SEL_Pos                                  (0U)
#define    INTMUX_CR1_MUX0SEL_Msk                                  (0x3U << INTMUX_CR1_MUX0SEL_Pos)
#define    INTMUX_CR1_MUX0SEL                                      INTMUX_CR1_MUX0SEL_Msk


#define    FL_INTMUX_MUX31SEL_RAMP_FDET_FLSECC_CLM                (0x0U << INTMUX_CR2_MUX31SEL_Pos)
#define    FL_INTMUX_MUX31SEL_TAU12                               (0x1U << INTMUX_CR2_MUX31SEL_Pos)
#define    FL_INTMUX_MUX31SEL_TAU13                               (0x2U << INTMUX_CR2_MUX31SEL_Pos)
#define    FL_INTMUX_MUX31SEL_TAU17                               (0x3U << INTMUX_CR2_MUX31SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX30SEL_EXTI                                (0x0U << INTMUX_CR2_MUX30SEL_Pos)
#define    FL_INTMUX_MUX30SEL_TAU15                               (0x1U << INTMUX_CR2_MUX30SEL_Pos)
#define    FL_INTMUX_MUX30SEL_TAU17                               (0x2U << INTMUX_CR2_MUX30SEL_Pos)
#define    FL_INTMUX_MUX30SEL_TAU05                               (0x3U << INTMUX_CR2_MUX30SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX29SEL_LPUART                              (0x0U << INTMUX_CR2_MUX29SEL_Pos)
#define    FL_INTMUX_MUX29SEL_TAU07                               (0x1U << INTMUX_CR2_MUX29SEL_Pos)
#define    FL_INTMUX_MUX29SEL_TAU10                               (0x2U << INTMUX_CR2_MUX29SEL_Pos)
#define    FL_INTMUX_MUX29SEL_TAU11                               (0x3U << INTMUX_CR2_MUX29SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX28SEL_ATIM                                (0x0U << INTMUX_CR2_MUX28SEL_Pos)
#define    FL_INTMUX_MUX28SEL_TAU14                               (0x1U << INTMUX_CR2_MUX28SEL_Pos)
#define    FL_INTMUX_MUX28SEL_TAU16                               (0x2U << INTMUX_CR2_MUX28SEL_Pos)
#define    FL_INTMUX_MUX28SEL_UART2                               (0x3U << INTMUX_CR2_MUX28SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX27SEL_NVMIF                               (0x0U << INTMUX_CR2_MUX27SEL_Pos)
#define    FL_INTMUX_MUX27SEL_TAU07                               (0x1U << INTMUX_CR2_MUX27SEL_Pos)
#define    FL_INTMUX_MUX27SEL_TAU10                               (0x2U << INTMUX_CR2_MUX27SEL_Pos)
#define    FL_INTMUX_MUX27SEL_TAU16                               (0x3U << INTMUX_CR2_MUX27SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX26SEL_SENTx                               (0x0U << INTMUX_CR2_MUX26SEL_Pos)
#define    FL_INTMUX_MUX26SEL_TAU03                               (0x1U << INTMUX_CR2_MUX26SEL_Pos)
#define    FL_INTMUX_MUX26SEL_TAU04                               (0x2U << INTMUX_CR2_MUX26SEL_Pos)
#define    FL_INTMUX_MUX26SEL_TAU15                               (0x3U << INTMUX_CR2_MUX26SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX25SEL_COMPx                               (0x0U << INTMUX_CR2_MUX25SEL_Pos)
#define    FL_INTMUX_MUX25SEL_TAU06                               (0x1U << INTMUX_CR2_MUX25SEL_Pos)
#define    FL_INTMUX_MUX25SEL_TAU07                               (0x2U << INTMUX_CR2_MUX25SEL_Pos)
#define    FL_INTMUX_MUX25SEL_TAU14                               (0x3U << INTMUX_CR2_MUX25SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX24SEL_DAC                                 (0x0U << INTMUX_CR2_MUX24SEL_Pos)
#define    FL_INTMUX_MUX24SEL_TAU06                               (0x1U << INTMUX_CR2_MUX24SEL_Pos)
#define    FL_INTMUX_MUX24SEL_TAU07                               (0x2U << INTMUX_CR2_MUX24SEL_Pos)
#define    FL_INTMUX_MUX24SEL_TAU13                               (0x3U << INTMUX_CR2_MUX24SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX23SEL_TAUxx                               (0x0U << INTMUX_CR2_MUX23SEL_Pos)
#define    FL_INTMUX_MUX23SEL_UART0                               (0x1U << INTMUX_CR2_MUX23SEL_Pos)
#define    FL_INTMUX_MUX23SEL_UART2                               (0x2U << INTMUX_CR2_MUX23SEL_Pos)
#define    FL_INTMUX_MUX23SEL_UART4                               (0x3U << INTMUX_CR2_MUX23SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX22SEL_WKUPx                               (0x0U << INTMUX_CR2_MUX22SEL_Pos)
#define    FL_INTMUX_MUX22SEL_TAU15                               (0x1U << INTMUX_CR2_MUX22SEL_Pos)
#define    FL_INTMUX_MUX22SEL_TAU16                               (0x2U << INTMUX_CR2_MUX22SEL_Pos)
#define    FL_INTMUX_MUX22SEL_TAU12                               (0x3U << INTMUX_CR2_MUX22SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX21SEL_DMA                                 (0x0U << INTMUX_CR2_MUX21SEL_Pos)
#define    FL_INTMUX_MUX21SEL_TAU12                               (0x1U << INTMUX_CR2_MUX21SEL_Pos)
#define    FL_INTMUX_MUX21SEL_TAU13                               (0x2U << INTMUX_CR2_MUX21SEL_Pos)
#define    FL_INTMUX_MUX21SEL_TAU11                               (0x3U << INTMUX_CR2_MUX21SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX20SEL_LPTIM                               (0x0U << INTMUX_CR2_MUX20SEL_Pos)
#define    FL_INTMUX_MUX20SEL_TAU13                               (0x1U << INTMUX_CR2_MUX20SEL_Pos)
#define    FL_INTMUX_MUX20SEL_TAU12                               (0x2U << INTMUX_CR2_MUX20SEL_Pos)
#define    FL_INTMUX_MUX20SEL_TAU11                               (0x3U << INTMUX_CR2_MUX20SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX19SEL_TSI                                 (0x0U << INTMUX_CR2_MUX19SEL_Pos)
#define    FL_INTMUX_MUX19SEL_SPI2                                (0x1U << INTMUX_CR2_MUX19SEL_Pos)
#define    FL_INTMUX_MUX19SEL_TAU03                               (0x2U << INTMUX_CR2_MUX19SEL_Pos)
#define    FL_INTMUX_MUX19SEL_TAU00                               (0x3U << INTMUX_CR2_MUX19SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX18SEL_BSTIM                               (0x0U << INTMUX_CR2_MUX18SEL_Pos)
#define    FL_INTMUX_MUX18SEL_TAU10                               (0x1U << INTMUX_CR2_MUX18SEL_Pos)
#define    FL_INTMUX_MUX18SEL_TAU07                               (0x2U << INTMUX_CR2_MUX18SEL_Pos)
#define    FL_INTMUX_MUX18SEL_TAU06                               (0x3U << INTMUX_CR2_MUX18SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX17SEL_UART7                               (0x0U << INTMUX_CR2_MUX17SEL_Pos)
#define    FL_INTMUX_MUX17SEL_TAU10                               (0x1U << INTMUX_CR2_MUX17SEL_Pos)
#define    FL_INTMUX_MUX17SEL_TAU16                               (0x2U << INTMUX_CR2_MUX17SEL_Pos)
#define    FL_INTMUX_MUX17SEL_LPTIM                               (0x3U << INTMUX_CR2_MUX17SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX16SEL_UART6                               (0x0U << INTMUX_CR2_MUX16SEL_Pos)
#define    FL_INTMUX_MUX16SEL_TAU15                               (0x1U << INTMUX_CR2_MUX16SEL_Pos)
#define    FL_INTMUX_MUX16SEL_TAU16                               (0x2U << INTMUX_CR2_MUX16SEL_Pos)
#define    FL_INTMUX_MUX16SEL_TAU03                               (0x3U << INTMUX_CR2_MUX16SEL_Pos)


#define    FL_INTMUX_MUX15SEL_I2C1                                (0x0U << INTMUX_CR1_MUX15SEL_Pos)
#define    FL_INTMUX_MUX15SEL_TAU16                               (0x1U << INTMUX_CR1_MUX15SEL_Pos)
#define    FL_INTMUX_MUX15SEL_TAU17                               (0x2U << INTMUX_CR1_MUX15SEL_Pos)
#define    FL_INTMUX_MUX15SEL_TAU10                               (0x3U << INTMUX_CR1_MUX15SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX14SEL_SPI1                                (0x0U << INTMUX_CR1_MUX14SEL_Pos)
#define    FL_INTMUX_MUX14SEL_TAU16                               (0x1U << INTMUX_CR1_MUX14SEL_Pos)
#define    FL_INTMUX_MUX14SEL_TAU17                               (0x2U << INTMUX_CR1_MUX14SEL_Pos)
#define    FL_INTMUX_MUX14SEL_TAU07                               (0x3U << INTMUX_CR1_MUX14SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX13SEL_SPI0                                (0x0U << INTMUX_CR1_MUX13SEL_Pos)
#define    FL_INTMUX_MUX13SEL_TAU13                               (0x1U << INTMUX_CR1_MUX13SEL_Pos)
#define    FL_INTMUX_MUX13SEL_TAU14                               (0x2U << INTMUX_CR1_MUX13SEL_Pos)
#define    FL_INTMUX_MUX13SEL_TAU06                               (0x3U << INTMUX_CR1_MUX13SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX12SEL_I2C0                                (0x0U << INTMUX_CR1_MUX12SEL_Pos)
#define    FL_INTMUX_MUX12SEL_TAU03                               (0x1U << INTMUX_CR1_MUX12SEL_Pos)
#define    FL_INTMUX_MUX12SEL_TAU04                               (0x2U << INTMUX_CR1_MUX12SEL_Pos)
#define    FL_INTMUX_MUX12SEL_TAU05                               (0x3U << INTMUX_CR1_MUX12SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX11SEL_UART5                               (0x0U << INTMUX_CR1_MUX11SEL_Pos)
#define    FL_INTMUX_MUX11SEL_TAU17                               (0x1U << INTMUX_CR1_MUX11SEL_Pos)
#define    FL_INTMUX_MUX11SEL_TAU02                               (0x2U << INTMUX_CR1_MUX11SEL_Pos)
#define    FL_INTMUX_MUX11SEL_TAU01                               (0x3U << INTMUX_CR1_MUX11SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX10SEL_UART4                               (0x0U << INTMUX_CR1_MUX10SEL_Pos)
#define    FL_INTMUX_MUX10SEL_TAU12                               (0x1U << INTMUX_CR1_MUX10SEL_Pos)
#define    FL_INTMUX_MUX10SEL_TAU13                               (0x2U << INTMUX_CR1_MUX10SEL_Pos)
#define    FL_INTMUX_MUX10SEL_SPI2                                (0x3U << INTMUX_CR1_MUX10SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX9SEL_UART3                                (0x0U << INTMUX_CR1_MUX9SEL_Pos)
#define    FL_INTMUX_MUX9SEL_TAU06                                (0x1U << INTMUX_CR1_MUX9SEL_Pos)
#define    FL_INTMUX_MUX9SEL_TAU07                                (0x2U << INTMUX_CR1_MUX9SEL_Pos)
#define    FL_INTMUX_MUX9SEL_TAU13                                (0x3U << INTMUX_CR1_MUX9SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX8SEL_UART2                                (0x0U << INTMUX_CR1_MUX8SEL_Pos)
#define    FL_INTMUX_MUX8SEL_ATIM                                 (0x1U << INTMUX_CR1_MUX8SEL_Pos)
#define    FL_INTMUX_MUX8SEL_I2C0                                 (0x2U << INTMUX_CR1_MUX8SEL_Pos)
#define    FL_INTMUX_MUX8SEL_QSPI                                 (0x3U << INTMUX_CR1_MUX8SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX7SEL_UART1                                (0x0U << INTMUX_CR1_MUX7SEL_Pos)
#define    FL_INTMUX_MUX7SEL_TAU07                                (0x1U << INTMUX_CR1_MUX7SEL_Pos)
#define    FL_INTMUX_MUX7SEL_TAU10                                (0x2U << INTMUX_CR1_MUX7SEL_Pos)
#define    FL_INTMUX_MUX7SEL_TAU16                                (0x3U << INTMUX_CR1_MUX7SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX6SEL_UART0                                (0x0U << INTMUX_CR1_MUX6SEL_Pos)
#define    FL_INTMUX_MUX6SEL_SENTx                                (0x1U << INTMUX_CR1_MUX6SEL_Pos)
#define    FL_INTMUX_MUX6SEL_LPTIM                                (0x2U << INTMUX_CR1_MUX6SEL_Pos)
#define    FL_INTMUX_MUX6SEL_I2C0                                 (0x3U << INTMUX_CR1_MUX6SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX5SEL_ADC                                  (0x0U << INTMUX_CR1_MUX5SEL_Pos)
#define    FL_INTMUX_MUX5SEL_TAU11                                (0x1U << INTMUX_CR1_MUX5SEL_Pos)
#define    FL_INTMUX_MUX5SEL_TAU10                                (0x2U << INTMUX_CR1_MUX5SEL_Pos)
#define    FL_INTMUX_MUX5SEL_TAU04                                (0x3U << INTMUX_CR1_MUX5SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX4SEL_QSPI                                 (0x0U << INTMUX_CR1_MUX4SEL_Pos)
#define    FL_INTMUX_MUX4SEL_TAU15                                (0x1U << INTMUX_CR1_MUX4SEL_Pos)
#define    FL_INTMUX_MUX4SEL_TAU16                                (0x2U << INTMUX_CR1_MUX4SEL_Pos)
#define    FL_INTMUX_MUX4SEL_TAU03                                (0x3U << INTMUX_CR1_MUX4SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX3SEL_CANFD                                (0x0U << INTMUX_CR1_MUX3SEL_Pos)
#define    FL_INTMUX_MUX3SEL_TAU13                                (0x1U << INTMUX_CR1_MUX3SEL_Pos)
#define    FL_INTMUX_MUX3SEL_TAU14                                (0x2U << INTMUX_CR1_MUX3SEL_Pos)
#define    FL_INTMUX_MUX3SEL_TAU02                                (0x3U << INTMUX_CR1_MUX3SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX2SEL_RTC                                  (0x0U << INTMUX_CR1_MUX2SEL_Pos)
#define    FL_INTMUX_MUX2SEL_TAU02                                (0x1U << INTMUX_CR1_MUX2SEL_Pos)
#define    FL_INTMUX_MUX2SEL_TAU05                                (0x2U << INTMUX_CR1_MUX2SEL_Pos)
#define    FL_INTMUX_MUX2SEL_TAU01                                (0x3U << INTMUX_CR1_MUX2SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX1SEL_SVD                                  (0x0U << INTMUX_CR1_MUX1SEL_Pos)
#define    FL_INTMUX_MUX1SEL_TAU04                                (0x1U << INTMUX_CR1_MUX1SEL_Pos)
#define    FL_INTMUX_MUX1SEL_TAU02                                (0x2U << INTMUX_CR1_MUX1SEL_Pos)
#define    FL_INTMUX_MUX1SEL_TAU01                                (0x3U << INTMUX_CR1_MUX1SEL_Pos)
                                                                                    
                                                                                    
#define    FL_INTMUX_MUX0SEL_WDT                                  (0x0U << INTMUX_CR1_MUX0SEL_Pos)
#define    FL_INTMUX_MUX0SEL_TAU02                                (0x1U << INTMUX_CR1_MUX0SEL_Pos)
#define    FL_INTMUX_MUX0SEL_TAU05                                (0x2U << INTMUX_CR1_MUX0SEL_Pos)
#define    FL_INTMUX_MUX0SEL_TAU00                                (0x3U << INTMUX_CR1_MUX0SEL_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup INTMUX_FL_Exported_Functions INTMUX Exported Functions
  * @{
  */


/**
  * @brief    Set MUX31SEL
  * @rmtoll   CR    MUX31SEL    FL_INTMUX_SetMUX31SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX31SEL_RAMP_FDET_FLSECC_CLM  
  *           @arg @ref FL_INTMUX_MUX31SEL_TAU12                 
  *           @arg @ref FL_INTMUX_MUX31SEL_TAU13                 
  *           @arg @ref FL_INTMUX_MUX31SEL_TAU17                 
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX31SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX31SEL_Msk, intsel);
}

/**
  * @brief    Get MUX31SEL
  * @rmtoll   CR    MUX31SEL    FL_INTMUX_GetMUX31SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX31SEL_RAMP_FDET_FLSECC_CLM  
  *           @arg @ref FL_INTMUX_MUX31SEL_TAU12                 
  *           @arg @ref FL_INTMUX_MUX31SEL_TAU13                 
  *           @arg @ref FL_INTMUX_MUX31SEL_TAU17                 
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX31SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX31SEL_Msk));
}


/**
  * @brief    Set MUX30SEL
  * @rmtoll   CR    MUX30SEL    FL_INTMUX_SetMUX30SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX30SEL_EXTI 
  *           @arg @ref FL_INTMUX_MUX30SEL_TAU15
  *           @arg @ref FL_INTMUX_MUX30SEL_TAU17
  *           @arg @ref FL_INTMUX_MUX30SEL_TAU05
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX30SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX30SEL_Msk, intsel);
}

/**
  * @brief    Get MUX30SEL
  * @rmtoll   CR    MUX30SEL    FL_INTMUX_GetMUX30SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX30SEL_EXTI 
  *           @arg @ref FL_INTMUX_MUX30SEL_TAU15
  *           @arg @ref FL_INTMUX_MUX30SEL_TAU17
  *           @arg @ref FL_INTMUX_MUX30SEL_TAU05
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX30SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX30SEL_Msk));
}


/**
  * @brief    Set MUX29SEL
  * @rmtoll   CR    MUX29SEL    FL_INTMUX_SetMUX29SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX29SEL_LPUART
  *           @arg @ref FL_INTMUX_MUX29SEL_TAU07 
  *           @arg @ref FL_INTMUX_MUX29SEL_TAU10 
  *           @arg @ref FL_INTMUX_MUX29SEL_TAU11 
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX29SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX29SEL_Msk, intsel);
}

/**
  * @brief    Get MUX29SEL
  * @rmtoll   CR    MUX29SEL    FL_INTMUX_GetMUX29SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX29SEL_LPUART
  *           @arg @ref FL_INTMUX_MUX29SEL_TAU07 
  *           @arg @ref FL_INTMUX_MUX29SEL_TAU10 
  *           @arg @ref FL_INTMUX_MUX29SEL_TAU11 
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX29SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX29SEL_Msk));
}


/**
  * @brief    Set MUX28SEL
  * @rmtoll   CR    MUX28SEL    FL_INTMUX_SetMUX28SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX28SEL_ATIM 
  *           @arg @ref FL_INTMUX_MUX28SEL_TAU14
  *           @arg @ref FL_INTMUX_MUX28SEL_TAU16
  *           @arg @ref FL_INTMUX_MUX28SEL_UART2
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX28SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX28SEL_Msk, intsel);
}

/**
  * @brief    Get MUX28SEL
  * @rmtoll   CR    MUX28SEL    FL_INTMUX_GetMUX28SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX28SEL_ATIM 
  *           @arg @ref FL_INTMUX_MUX28SEL_TAU14
  *           @arg @ref FL_INTMUX_MUX28SEL_TAU16
  *           @arg @ref FL_INTMUX_MUX28SEL_UART2
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX28SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX28SEL_Msk));
}


/**
  * @brief    Set MUX27SEL
  * @rmtoll   CR    MUX27SEL    FL_INTMUX_SetMUX27SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX27SEL_NVMIF
  *           @arg @ref FL_INTMUX_MUX27SEL_TAU07
  *           @arg @ref FL_INTMUX_MUX27SEL_TAU10
  *           @arg @ref FL_INTMUX_MUX27SEL_TAU16
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX27SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX27SEL_Msk, intsel);
}

/**
  * @brief    Get MUX27SEL
  * @rmtoll   CR    MUX27SEL    FL_INTMUX_GetMUX27SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX27SEL_NVMIF
  *           @arg @ref FL_INTMUX_MUX27SEL_TAU07
  *           @arg @ref FL_INTMUX_MUX27SEL_TAU10
  *           @arg @ref FL_INTMUX_MUX27SEL_TAU16
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX27SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX27SEL_Msk));
}


/**
  * @brief    Set MUX26SEL
  * @rmtoll   CR    MUX26SEL    FL_INTMUX_SetMUX26SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX26SEL_SENTx
  *           @arg @ref FL_INTMUX_MUX26SEL_TAU03
  *           @arg @ref FL_INTMUX_MUX26SEL_TAU04
  *           @arg @ref FL_INTMUX_MUX26SEL_TAU15
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX26SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX26SEL_Msk, intsel);
}

/**
  * @brief    Get MUX26SEL
  * @rmtoll   CR    MUX26SEL    FL_INTMUX_GetMUX26SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX26SEL_SENTx
  *           @arg @ref FL_INTMUX_MUX26SEL_TAU03
  *           @arg @ref FL_INTMUX_MUX26SEL_TAU04
  *           @arg @ref FL_INTMUX_MUX26SEL_TAU15
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX26SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX26SEL_Msk));
}


/**
  * @brief    Set MUX25SEL
  * @rmtoll   CR    MUX25SEL    FL_INTMUX_SetMUX25SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX25SEL_COMPx
  *           @arg @ref FL_INTMUX_MUX25SEL_TAU06
  *           @arg @ref FL_INTMUX_MUX25SEL_TAU07
  *           @arg @ref FL_INTMUX_MUX25SEL_TAU14
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX25SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX25SEL_Msk, intsel);
}

/**
  * @brief    Get MUX25SEL
  * @rmtoll   CR    MUX25SEL    FL_INTMUX_GetMUX25SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX25SEL_COMPx
  *           @arg @ref FL_INTMUX_MUX25SEL_TAU06
  *           @arg @ref FL_INTMUX_MUX25SEL_TAU07
  *           @arg @ref FL_INTMUX_MUX25SEL_TAU14
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX25SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX25SEL_Msk));
}


/**
  * @brief    Set MUX24SEL
  * @rmtoll   CR    MUX24SEL    FL_INTMUX_SetMUX24SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX24SEL_DAC  
  *           @arg @ref FL_INTMUX_MUX24SEL_TAU06
  *           @arg @ref FL_INTMUX_MUX24SEL_TAU07
  *           @arg @ref FL_INTMUX_MUX24SEL_TAU13
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX24SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX24SEL_Msk, intsel);
}

/**
  * @brief    Get MUX24SEL
  * @rmtoll   CR    MUX24SEL    FL_INTMUX_GetMUX24SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX24SEL_DAC  
  *           @arg @ref FL_INTMUX_MUX24SEL_TAU06
  *           @arg @ref FL_INTMUX_MUX24SEL_TAU07
  *           @arg @ref FL_INTMUX_MUX24SEL_TAU13
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX24SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX24SEL_Msk));
}


/**
  * @brief    Set MUX23SEL
  * @rmtoll   CR    MUX23SEL    FL_INTMUX_SetMUX23SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX23SEL_TAUxx
  *           @arg @ref FL_INTMUX_MUX23SEL_UART0
  *           @arg @ref FL_INTMUX_MUX23SEL_UART2
  *           @arg @ref FL_INTMUX_MUX23SEL_UART4
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX23SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX23SEL_Msk, intsel);
}

/**
  * @brief    Get MUX23SEL
  * @rmtoll   CR    MUX23SEL    FL_INTMUX_GetMUX23SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX23SEL_TAUxx
  *           @arg @ref FL_INTMUX_MUX23SEL_UART0
  *           @arg @ref FL_INTMUX_MUX23SEL_UART2
  *           @arg @ref FL_INTMUX_MUX23SEL_UART4
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX23SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX23SEL_Msk));
}


/**
  * @brief    Set MUX22SEL
  * @rmtoll   CR    MUX22SEL    FL_INTMUX_SetMUX22SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX22SEL_WKUPx
  *           @arg @ref FL_INTMUX_MUX22SEL_TAU15
  *           @arg @ref FL_INTMUX_MUX22SEL_TAU16
  *           @arg @ref FL_INTMUX_MUX22SEL_TAU12
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX22SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX22SEL_Msk, intsel);
}

/**
  * @brief    Get MUX22SEL
  * @rmtoll   CR    MUX22SEL    FL_INTMUX_GetMUX22SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX22SEL_WKUPx
  *           @arg @ref FL_INTMUX_MUX22SEL_TAU15
  *           @arg @ref FL_INTMUX_MUX22SEL_TAU16
  *           @arg @ref FL_INTMUX_MUX22SEL_TAU12
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX22SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX22SEL_Msk));
}


/**
  * @brief    Set MUX21SEL
  * @rmtoll   CR    MUX21SEL    FL_INTMUX_SetMUX21SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX21SEL_DMA  
  *           @arg @ref FL_INTMUX_MUX21SEL_TAU12
  *           @arg @ref FL_INTMUX_MUX21SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX21SEL_TAU11
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX21SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX21SEL_Msk, intsel);
}

/**
  * @brief    Get MUX21SEL
  * @rmtoll   CR    MUX21SEL    FL_INTMUX_GetMUX21SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX21SEL_DMA  
  *           @arg @ref FL_INTMUX_MUX21SEL_TAU12
  *           @arg @ref FL_INTMUX_MUX21SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX21SEL_TAU11
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX21SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX21SEL_Msk));
}


/**
  * @brief    Set MUX20SEL
  * @rmtoll   CR    MUX20SEL    FL_INTMUX_SetMUX20SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX20SEL_LPTIM
  *           @arg @ref FL_INTMUX_MUX20SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX20SEL_TAU12
  *           @arg @ref FL_INTMUX_MUX20SEL_TAU11
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX20SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX20SEL_Msk, intsel);
}

/**
  * @brief    Get MUX20SEL
  * @rmtoll   CR    MUX20SEL    FL_INTMUX_GetMUX20SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX20SEL_LPTIM
  *           @arg @ref FL_INTMUX_MUX20SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX20SEL_TAU12
  *           @arg @ref FL_INTMUX_MUX20SEL_TAU11
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX20SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX20SEL_Msk));
}


/**
  * @brief    Set MUX19SEL
  * @rmtoll   CR    MUX19SEL    FL_INTMUX_SetMUX19SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX19SEL_TSI  
  *           @arg @ref FL_INTMUX_MUX19SEL_SPI2 
  *           @arg @ref FL_INTMUX_MUX19SEL_TAU03
  *           @arg @ref FL_INTMUX_MUX19SEL_TAU00
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX19SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX19SEL_Msk, intsel);
}

/**
  * @brief    Get MUX19SEL
  * @rmtoll   CR    MUX19SEL    FL_INTMUX_GetMUX19SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX19SEL_TSI  
  *           @arg @ref FL_INTMUX_MUX19SEL_SPI2 
  *           @arg @ref FL_INTMUX_MUX19SEL_TAU03
  *           @arg @ref FL_INTMUX_MUX19SEL_TAU00
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX19SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX19SEL_Msk));
}


/**
  * @brief    Set MUX18SEL
  * @rmtoll   CR    MUX18SEL    FL_INTMUX_SetMUX18SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX18SEL_BSTIM
  *           @arg @ref FL_INTMUX_MUX18SEL_TAU10
  *           @arg @ref FL_INTMUX_MUX18SEL_TAU07
  *           @arg @ref FL_INTMUX_MUX18SEL_TAU06
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX18SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX18SEL_Msk, intsel);
}

/**
  * @brief    Get MUX18SEL
  * @rmtoll   CR    MUX18SEL    FL_INTMUX_GetMUX18SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX18SEL_BSTIM
  *           @arg @ref FL_INTMUX_MUX18SEL_TAU10
  *           @arg @ref FL_INTMUX_MUX18SEL_TAU07
  *           @arg @ref FL_INTMUX_MUX18SEL_TAU06
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX18SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX18SEL_Msk));
}


/**
  * @brief    Set MUX17SEL
  * @rmtoll   CR    MUX17SEL    FL_INTMUX_SetMUX17SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX17SEL_UART7
  *           @arg @ref FL_INTMUX_MUX17SEL_TAU10
  *           @arg @ref FL_INTMUX_MUX17SEL_TAU16
  *           @arg @ref FL_INTMUX_MUX17SEL_LPTIM
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX17SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX17SEL_Msk, intsel);
}

/**
  * @brief    Get MUX17SEL
  * @rmtoll   CR    MUX17SEL    FL_INTMUX_GetMUX17SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX17SEL_UART7
  *           @arg @ref FL_INTMUX_MUX17SEL_TAU10
  *           @arg @ref FL_INTMUX_MUX17SEL_TAU16
  *           @arg @ref FL_INTMUX_MUX17SEL_LPTIM
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX17SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX19SEL_Msk));
}


/**
  * @brief    Set MUX16SEL
  * @rmtoll   CR    MUX16SEL    FL_INTMUX_SetMUX16SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX16SEL_UART6
  *           @arg @ref FL_INTMUX_MUX16SEL_TAU15
  *           @arg @ref FL_INTMUX_MUX16SEL_TAU16
  *           @arg @ref FL_INTMUX_MUX16SEL_TAU03
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX16SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR2, INTMUX_CR2_MUX16SEL_Msk, intsel);
}

/**
  * @brief    Get MUX16SEL
  * @rmtoll   CR    MUX16SEL    FL_INTMUX_GetMUX16SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX16SEL_UART6
  *           @arg @ref FL_INTMUX_MUX16SEL_TAU15
  *           @arg @ref FL_INTMUX_MUX16SEL_TAU16
  *           @arg @ref FL_INTMUX_MUX16SEL_TAU03
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX16SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR2, INTMUX_CR2_MUX16SEL_Msk));
}


/**
  * @brief    Set MUX15SEL
  * @rmtoll   CR    MUX15SEL    FL_INTMUX_SetMUX15SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX15SEL_I2C1 
  *           @arg @ref FL_INTMUX_MUX15SEL_TAU16
  *           @arg @ref FL_INTMUX_MUX15SEL_TAU17
  *           @arg @ref FL_INTMUX_MUX15SEL_TAU10
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX15SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX15SEL_Msk, intsel);
}

/**
  * @brief    Get MUX15SEL
  * @rmtoll   CR    MUX15SEL    FL_INTMUX_GetMUX15SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX15SEL_I2C1 
  *           @arg @ref FL_INTMUX_MUX15SEL_TAU16
  *           @arg @ref FL_INTMUX_MUX15SEL_TAU17
  *           @arg @ref FL_INTMUX_MUX15SEL_TAU10
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX15SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX15SEL_Msk));
}


/**
  * @brief    Set MUX14SEL
  * @rmtoll   CR    MUX14SEL    FL_INTMUX_SetMUX14SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX14SEL_SPI1 
  *           @arg @ref FL_INTMUX_MUX14SEL_TAU16
  *           @arg @ref FL_INTMUX_MUX14SEL_TAU17
  *           @arg @ref FL_INTMUX_MUX14SEL_TAU07
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX14SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX14SEL_Msk, intsel);
}

/**
  * @brief    Get MUX14SEL
  * @rmtoll   CR    MUX14SEL    FL_INTMUX_GetMUX14SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX14SEL_SPI1 
  *           @arg @ref FL_INTMUX_MUX14SEL_TAU16
  *           @arg @ref FL_INTMUX_MUX14SEL_TAU17
  *           @arg @ref FL_INTMUX_MUX14SEL_TAU07
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX14SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX14SEL_Msk));
}


/**
  * @brief    Set MUX13SEL
  * @rmtoll   CR    MUX13SEL    FL_INTMUX_SetMUX13SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX13SEL_SPI0 
  *           @arg @ref FL_INTMUX_MUX13SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX13SEL_TAU14
  *           @arg @ref FL_INTMUX_MUX13SEL_TAU06
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX13SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX13SEL_Msk, intsel);
}

/**
  * @brief    Get MUX13SEL
  * @rmtoll   CR    MUX13SEL    FL_INTMUX_GetMUX13SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX13SEL_SPI0 
  *           @arg @ref FL_INTMUX_MUX13SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX13SEL_TAU14
  *           @arg @ref FL_INTMUX_MUX13SEL_TAU06
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX13SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX13SEL_Msk));
}


/**
  * @brief    Set MUX12SEL
  * @rmtoll   CR    MUX12SEL    FL_INTMUX_SetMUX12SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX12SEL_I2C0 
  *           @arg @ref FL_INTMUX_MUX12SEL_TAU03
  *           @arg @ref FL_INTMUX_MUX12SEL_TAU04
  *           @arg @ref FL_INTMUX_MUX12SEL_TAU05
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX12SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX12SEL_Msk, intsel);
}

/**
  * @brief    Get MUX12SEL
  * @rmtoll   CR    MUX12SEL    FL_INTMUX_GetMUX12SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX12SEL_I2C0 
  *           @arg @ref FL_INTMUX_MUX12SEL_TAU03
  *           @arg @ref FL_INTMUX_MUX12SEL_TAU04
  *           @arg @ref FL_INTMUX_MUX12SEL_TAU05
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX12SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX12SEL_Msk));
}


/**
  * @brief    Set MUX11SEL
  * @rmtoll   CR    MUX11SEL    FL_INTMUX_SetMUX11SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX11SEL_UART5
  *           @arg @ref FL_INTMUX_MUX11SEL_TAU17
  *           @arg @ref FL_INTMUX_MUX11SEL_TAU02
  *           @arg @ref FL_INTMUX_MUX11SEL_TAU01
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX11SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX11SEL_Msk, intsel);
}

/**
  * @brief    Get MUX11SEL
  * @rmtoll   CR    MUX11SEL    FL_INTMUX_GetMUX11SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX11SEL_UART5
  *           @arg @ref FL_INTMUX_MUX11SEL_TAU17
  *           @arg @ref FL_INTMUX_MUX11SEL_TAU02
  *           @arg @ref FL_INTMUX_MUX11SEL_TAU01
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX11SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX11SEL_Msk));
}


/**
  * @brief    Set MUX10SEL
  * @rmtoll   CR    MUX10SEL    FL_INTMUX_SetMUX10SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX10SEL_UART4
  *           @arg @ref FL_INTMUX_MUX10SEL_TAU12
  *           @arg @ref FL_INTMUX_MUX10SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX10SEL_SPI2 
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX10SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX10SEL_Msk, intsel);
}

/**
  * @brief    Get MUX10SEL
  * @rmtoll   CR    MUX10SEL    FL_INTMUX_GetMUX10SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX10SEL_UART4
  *           @arg @ref FL_INTMUX_MUX10SEL_TAU12
  *           @arg @ref FL_INTMUX_MUX10SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX10SEL_SPI2 
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX10SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX10SEL_Msk));
}


/**
  * @brief    Set MUX9SEL
  * @rmtoll   CR    MUX9SEL    FL_INTMUX_SetMUX9SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX9SEL_UART3
  *           @arg @ref FL_INTMUX_MUX9SEL_TAU06
  *           @arg @ref FL_INTMUX_MUX9SEL_TAU07
  *           @arg @ref FL_INTMUX_MUX9SEL_TAU13
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX9SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX9SEL_Msk, intsel);
}

/**
  * @brief    Get MUX9SEL
  * @rmtoll   CR    MUX9SEL    FL_INTMUX_GetMUX9SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX9SEL_UART3
  *           @arg @ref FL_INTMUX_MUX9SEL_TAU06
  *           @arg @ref FL_INTMUX_MUX9SEL_TAU07
  *           @arg @ref FL_INTMUX_MUX9SEL_TAU13
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX9SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX9SEL_Msk));
}


/**
  * @brief    Set MUX8SEL
  * @rmtoll   CR    MUX8SEL    FL_INTMUX_SetMUX8SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX8SEL_UART2
  *           @arg @ref FL_INTMUX_MUX8SEL_ATIM 
  *           @arg @ref FL_INTMUX_MUX8SEL_I2C0 
  *           @arg @ref FL_INTMUX_MUX8SEL_QSPI 
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX8SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX8SEL_Msk, intsel);
}

/**
  * @brief    Get MUX8SEL
  * @rmtoll   CR    MUX8SEL    FL_INTMUX_GetMUX8SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX8SEL_UART2
  *           @arg @ref FL_INTMUX_MUX8SEL_ATIM 
  *           @arg @ref FL_INTMUX_MUX8SEL_I2C0 
  *           @arg @ref FL_INTMUX_MUX8SEL_QSPI 
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX8SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX8SEL_Msk));
}


/**
  * @brief    Set MUX7SEL
  * @rmtoll   CR    MUX7SEL    FL_INTMUX_SetMUX7SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX7SEL_UART1
  *           @arg @ref FL_INTMUX_MUX7SEL_TAU07
  *           @arg @ref FL_INTMUX_MUX7SEL_TAU10
  *           @arg @ref FL_INTMUX_MUX7SEL_TAU16
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX7SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX7SEL_Msk, intsel);
}

/**
  * @brief    Get MUX7SEL
  * @rmtoll   CR    MUX7SEL    FL_INTMUX_GetMUX7SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX7SEL_UART1
  *           @arg @ref FL_INTMUX_MUX7SEL_TAU07
  *           @arg @ref FL_INTMUX_MUX7SEL_TAU10
  *           @arg @ref FL_INTMUX_MUX7SEL_TAU16
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX7SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX7SEL_Msk));
}


/**
  * @brief    Set MUX6SEL
  * @rmtoll   CR    MUX6SEL    FL_INTMUX_SetMUX6SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX6SEL_UART0
  *           @arg @ref FL_INTMUX_MUX6SEL_SENTx
  *           @arg @ref FL_INTMUX_MUX6SEL_LPTIM
  *           @arg @ref FL_INTMUX_MUX6SEL_I2C0 
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX6SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX6SEL_Msk, intsel);
}

/**
  * @brief    Get MUX6SEL
  * @rmtoll   CR    MUX6SEL    FL_INTMUX_GetMUX6SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX6SEL_UART0
  *           @arg @ref FL_INTMUX_MUX6SEL_SENTx
  *           @arg @ref FL_INTMUX_MUX6SEL_LPTIM
  *           @arg @ref FL_INTMUX_MUX6SEL_I2C0 
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX6SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX6SEL_Msk));
}


/**
  * @brief    Set MUX5SEL
  * @rmtoll   CR    MUX5SEL    FL_INTMUX_SetMUX5SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX5SEL_ADC  
  *           @arg @ref FL_INTMUX_MUX5SEL_TAU11
  *           @arg @ref FL_INTMUX_MUX5SEL_TAU10
  *           @arg @ref FL_INTMUX_MUX5SEL_TAU04
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX5SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX5SEL_Msk, intsel);
}

/**
  * @brief    Get MUX5SEL
  * @rmtoll   CR    MUX5SEL    FL_INTMUX_GetMUX5SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX5SEL_ADC  
  *           @arg @ref FL_INTMUX_MUX5SEL_TAU11
  *           @arg @ref FL_INTMUX_MUX5SEL_TAU10
  *           @arg @ref FL_INTMUX_MUX5SEL_TAU04
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX5SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX5SEL_Msk));
}


/**
  * @brief    Set MUX4SEL
  * @rmtoll   CR    MUX4SEL    FL_INTMUX_SetMUX4SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX4SEL_QSPI 
  *           @arg @ref FL_INTMUX_MUX4SEL_TAU15
  *           @arg @ref FL_INTMUX_MUX4SEL_TAU16
  *           @arg @ref FL_INTMUX_MUX4SEL_TAU03
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX4SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX4SEL_Msk, intsel);
}

/**
  * @brief    Get MUX4SEL
  * @rmtoll   CR    MUX4SEL    FL_INTMUX_GetMUX4SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX4SEL_QSPI 
  *           @arg @ref FL_INTMUX_MUX4SEL_TAU15
  *           @arg @ref FL_INTMUX_MUX4SEL_TAU16
  *           @arg @ref FL_INTMUX_MUX4SEL_TAU03
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX4SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX4SEL_Msk));
}


/**
  * @brief    Set MUX3SEL
  * @rmtoll   CR    MUX3SEL    FL_INTMUX_SetMUX3SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX3SEL_CANFD
  *           @arg @ref FL_INTMUX_MUX3SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX3SEL_TAU14
  *           @arg @ref FL_INTMUX_MUX3SEL_TAU02
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX3SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX3SEL_Msk, intsel);
}

/**
  * @brief    Get MUX3SEL
  * @rmtoll   CR    MUX3SEL    FL_INTMUX_GetMUX3SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX3SEL_CANFD
  *           @arg @ref FL_INTMUX_MUX3SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX3SEL_TAU14
  *           @arg @ref FL_INTMUX_MUX3SEL_TAU02
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX3SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX3SEL_Msk));
}


/**
  * @brief    Set MUX2SEL
  * @rmtoll   CR    MUX2SEL    FL_INTMUX_SetMUX2SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX2SEL_RTC  
  *           @arg @ref FL_INTMUX_MUX2SEL_TAU02
  *           @arg @ref FL_INTMUX_MUX2SEL_TAU05
  *           @arg @ref FL_INTMUX_MUX2SEL_TAU01
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX2SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX2SEL_Msk, intsel);
}

/**
  * @brief    Get MUX2SEL
  * @rmtoll   CR    MUX2SEL    FL_INTMUX_GetMUX2SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX2SEL_RTC  
  *           @arg @ref FL_INTMUX_MUX2SEL_TAU02
  *           @arg @ref FL_INTMUX_MUX2SEL_TAU05
  *           @arg @ref FL_INTMUX_MUX2SEL_TAU01
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX2SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX2SEL_Msk));
}


/**
  * @brief    Set MUX1SEL
  * @rmtoll   CR    MUX1SEL    FL_INTMUX_SetMUX1SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX1SEL_SVD  
  *           @arg @ref FL_INTMUX_MUX1SEL_TAU04
  *           @arg @ref FL_INTMUX_MUX1SEL_TAU02
  *           @arg @ref FL_INTMUX_MUX1SEL_TAU01
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX1SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX1SEL_Msk, intsel);
}

/**
  * @brief    Get MUX1SEL
  * @rmtoll   CR    MUX1SEL    FL_INTMUX_GetMUX1SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX1SEL_SVD  
  *           @arg @ref FL_INTMUX_MUX1SEL_TAU04
  *           @arg @ref FL_INTMUX_MUX1SEL_TAU02
  *           @arg @ref FL_INTMUX_MUX1SEL_TAU01
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX1SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX1SEL_Msk));
}


/**
  * @brief    Set MUX0SEL
  * @rmtoll   CR    MUX0SEL    FL_INTMUX_SetMUX0SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX0SEL_WDT  
  *           @arg @ref FL_INTMUX_MUX0SEL_TAU02
  *           @arg @ref FL_INTMUX_MUX0SEL_TAU05
  *           @arg @ref FL_INTMUX_MUX0SEL_TAU00
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX0SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR1, INTMUX_CR1_MUX0SEL_Msk, intsel);
}

/**
  * @brief    Get MUX0SEL
  * @rmtoll   CR    MUX0SEL    FL_INTMUX_GetMUX0SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX0SEL_WDT  
  *           @arg @ref FL_INTMUX_MUX0SEL_TAU02
  *           @arg @ref FL_INTMUX_MUX0SEL_TAU05
  *           @arg @ref FL_INTMUX_MUX0SEL_TAU00
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX0SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR1, INTMUX_CR1_MUX0SEL_Msk));
}
/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_INTMUX_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2024-01-04*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
