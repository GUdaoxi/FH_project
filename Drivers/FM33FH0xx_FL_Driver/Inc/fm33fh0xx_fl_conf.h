/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_conf.h
  * @author  FMSH Application Team
  * @brief   Header file of FL Driver Library Configurations
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


/* Define to prevent recursive inclusion --------------------------------------------------------------*/
#ifndef __FM33FH0XX_FL_CONF_H
#define __FM33FH0XX_FL_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Defines --------------------------------------------------------------------------------------------*/

/**
  * @brief List of drivers to be used.
  *
  * @note Uncomment following lines to disable specified driver.
  */
#define FL_ADC_DRIVER_ENABLED
#define FL_ATIM_DRIVER_ENABLED
#define FL_BSTIM16_DRIVER_ENABLED
#define FL_CANFD_DRIVER_ENABLED
#define FL_CLM_DRIVER_ENABLED
#define FL_CMU_DRIVER_ENABLED
#define FL_COMP_DRIVER_ENABLED
#define FL_CRC_DRIVER_ENABLED
#define FL_DAC_DRIVER_ENABLED
#define FL_DMA_DRIVER_ENABLED
#define FL_EXTI_DRIVER_ENABLED
#define FL_FLASH_DRIVER_ENABLED
#define FL_GPIO_DRIVER_ENABLED
#define FL_I2C_DRIVER_ENABLED
#define FL_INTMUX_DRIVER_ENABLED
#define FL_IWDT_DRIVER_ENABLED
#define FL_LPTIM16_DRIVER_ENABLED
#define FL_LPUART_DRIVER_ENABLED
#define FL_PMU_DRIVER_ENABLED
#define FL_QSPI_DRIVER_ENABLED
#define FL_RMU_DRIVER_ENABLED
#define FL_RTC_DRIVER_ENABLED
#define FL_SENT_DRIVER_ENABLED
#define FL_SPI_DRIVER_ENABLED
#define FL_SVD_DRIVER_ENABLED
#define FL_TAU_DRIVER_ENABLED
#define FL_UART_DRIVER_ENABLED
#define FL_WWDT_DRIVER_ENABLED

/* Device Includes ------------------------------------------------------------------------------------*/
/**
  * @brief Include peripheral's header file
  */

#if defined(FL_ADC_DRIVER_ENABLED)
#include "fm33fh0xx_fl_adc.h"
#endif /* FL_ADC_DRIVER_ENABLED */

#if defined(FL_ATIM_DRIVER_ENABLED)
#include "fm33fh0xx_fl_atim.h"
#endif /* FL_ATIM_DRIVER_ENABLED */

#if defined(FL_BSTIM16_DRIVER_ENABLED)
#include "fm33fh0xx_fl_bstim16.h"
#endif /* FL_BSTIM32_DRIVER_ENABLED */

#if defined(FL_CANFD_DRIVER_ENABLED)
#include "fm33fh0xx_fl_canfd.h"
#endif /* FL_CANFD_DRIVER_ENABLED */

#if defined(FL_CLM_DRIVER_ENABLED)
#include "fm33fh0xx_fl_clm.h"
#endif /* FL_CLM_DRIVER_ENABLED */

#if defined(FL_CMU_DRIVER_ENABLED)
#include "fm33fh0xx_fl_cmu.h"
#endif /* FL_CMU_DRIVER_ENABLED */

#if defined(FL_COMP_DRIVER_ENABLED)
#include "fm33fh0xx_fl_comp.h"
#endif /* FL_COMP_DRIVER_ENABLED */

#if defined(FL_CRC_DRIVER_ENABLED)
#include "fm33fh0xx_fl_crc.h"
#endif /* FL_CRC_DRIVER_ENABLED */

#if defined(FL_DAC_DRIVER_ENABLED)
#include "fm33fh0xx_fl_dac.h"
#endif /* FL_DAC_DRIVER_ENABLED */

#if defined(FL_DMA_DRIVER_ENABLED)
#include "fm33fh0xx_fl_dma.h"
#endif /* FL_DMA_DRIVER_ENABLED */

#if defined(FL_EXTI_DRIVER_ENABLED)
#include "fm33fh0xx_fl_exti.h"
#endif /* FL_EXTI_DRIVER_ENABLED */

#if defined(FL_FLASH_DRIVER_ENABLED)
#include "fm33fh0xx_fl_flash.h"
#endif /* FL_FLASH_DRIVER_ENABLED */

#if defined(FL_GPIO_DRIVER_ENABLED)
#include "fm33fh0xx_fl_gpio.h"
#endif /* FL_GPIO_DRIVER_ENABLED */

#if defined(FL_I2C_DRIVER_ENABLED)
#include "fm33fh0xx_fl_i2c.h"
#endif /* FL_I2C_DRIVER_ENABLED */

#if defined(FL_INTMUX_DRIVER_ENABLED)
#include "fm33fh0xx_fl_intmux.h"
#endif /* FL_INTMUX_DRIVER_ENABLED */

#if defined(FL_IWDT_DRIVER_ENABLED)
#include "fm33fh0xx_fl_iwdt.h"
#endif /* FL_IWDT_DRIVER_ENABLED */

#if defined(FL_LPTIM16_DRIVER_ENABLED)
#include "fm33fh0xx_fl_lptim16.h"
#endif /* FL_LPTIM16_DRIVER_ENABLED */

#if defined(FL_LPUART_DRIVER_ENABLED)
#include "fm33fh0xx_fl_lpuart.h"
#endif /* FL_LPUART_DRIVER_ENABLED */

#if defined(FL_PMU_DRIVER_ENABLED)
#include "fm33fh0xx_fl_pmu.h"
#endif /* FL_PMU_DRIVER_ENABLED */

#if defined(FL_QSPI_DRIVER_ENABLED)
#include "fm33fh0xx_fl_qspi.h"
#endif /* FL_QSPI_DRIVER_ENABLED */

#if defined(FL_RMU_DRIVER_ENABLED)
#include "fm33fh0xx_fl_rmu.h"
#endif /* FL_RMU_DRIVER_ENABLED */

#if defined(FL_RTC_DRIVER_ENABLED)
#include "fm33fh0xx_fl_rtc.h"
#endif /* FL_RTC_DRIVER_ENABLED */

#if defined(FL_SENT_DRIVER_ENABLED)
#include "fm33fh0xx_fl_sent.h"
#endif /* FL_SENT_DRIVER_ENABLED */

#if defined(FL_SPI_DRIVER_ENABLED)
#include "fm33fh0xx_fl_spi.h"
#endif /* FL_SPI_DRIVER_ENABLED */

#if defined(FL_SVD_DRIVER_ENABLED)
#include "fm33fh0xx_fl_svd.h"
#endif /* FL_SVD_DRIVER_ENABLED */

#if defined(FL_TAU_DRIVER_ENABLED)
#include "fm33fh0xx_fl_tau.h"
#endif /* FL_TAU_DRIVER_ENABLED */

#if defined(FL_UART_DRIVER_ENABLED)
#include "fm33fh0xx_fl_uart.h"
#endif /* FL_UART_DRIVER_ENABLED */

#if defined(FL_WWDT_DRIVER_ENABLED)
#include "fm33fh0xx_fl_wwdt.h"
#endif /* FL_WWDT_DRIVER_ENABLED */


#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0xx_FL_CONF_H */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
