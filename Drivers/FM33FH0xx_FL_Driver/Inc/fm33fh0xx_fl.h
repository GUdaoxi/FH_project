/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl.h
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
#ifndef __FM33FH0XX_FL_H
#define __FM33FH0XX_FL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl_conf.h"
#include "fm33fh0xx_fl_def.h"

/* Macros ---------------------------------------------------------------------------------------------*/
/** @defgroup FL_Exported_Macros FL Driver Library Exported Macros
  * @{
  */

/**
  * @brief FM33FH0xx FL Driver Library version number
  */
#define __FM33FH0xx_FL_VERSION_MAIN   (0x01) /*!< [31:24] main version */
#define __FM33FH0xx_FL_VERSION_SUB1   (0x01) /*!< [23:16] sub1 version */
#define __FM33FH0xx_FL_VERSION_SUB2   (0x00) /*!< [15:0]  sub2 version */
#define __FM33FH0xx_FL_VERSION        ((__FM33FH0xx_FL_VERSION_MAIN  << 24)\
                                       |(__FM33FH0xx_FL_VERSION_SUB1 << 16)\
                                       |(__FM33FH0xx_FL_VERSION_SUB2))

/**
  * @brief Macros used by delay support functions
  */
#define FL_DELAY_US                (SystemCoreClock/1000000)
#define FL_DELAY_MS                (SystemCoreClock/1000)

/**
  * @}
  */

/* Struct Defines -------------------------------------------------------------------------------------*/
/** @defgroup FL_ET_NVIC FL Driver Library NVIC Init Sturcture Defines
  * @{
  */

typedef struct
{
    /** 中断抢占优先级 */
    uint32_t preemptPriority;

} FL_NVIC_ConfigTypeDef;

/**
  * @}
  */

/* Exported Functions ---------------------------------------------------------------------------------*/
/** @defgroup FL_EF_DELAY   FL Driver Library Exported Delay Support Functions
  * @{
  */

void FL_DelayInit(void);
void FL_DelayUs(uint32_t count);
void FL_DelayMs(uint32_t count);
void FL_DelayUsStart(uint32_t count);
void FL_DelayMsStart(uint32_t count);
bool FL_DelayEnd(void);

/**
  * @}
  */

/** @defgroup FL_EF_INIT   FL Driver Library Exported Init Functions
  * @{
  */

void FL_Init(void);

/**
  * @}
  */

/** @defgroup FL_EF_NVIC   FL Driver Library Exported NVIC Configuration Functions
  * @{
  */

void FL_NVIC_Init(FL_NVIC_ConfigTypeDef *configStruct, IRQn_Type irq);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_H */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
