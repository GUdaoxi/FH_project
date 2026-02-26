/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : svd.h
  * @brief          : Header for svd.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
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
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SVD_H
#define __SVD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "fm33fh0xx_fl.h"
#include "stdbool.h"

/* SVD监测电源 */
typedef enum
{
    SVD_MONTIOR_VDD = 0U,  /* 内部电源VDD */
    SVD_MONTIOR_SVS = 1U   /* 外部电源SVS */
}SVD_MONTIOR_POWER;

/* SVD监测结果 */
typedef enum
{
    SVD_BELOW_THRESHOLD  = 0U,                    /* 电源电压低于SVD当前阈值 */    
    SVD_HIGHER_THRESHOLD = !SVD_BELOW_THRESHOLD   /* 电源电压高于SVD当前阈值 */
}SVD_RESULT;


#define SVD_SVS_GPIO  (GPIOF)
#define SVD_SVS_PIN   (FL_GPIO_PIN_11)


extern FL_ErrorStatus SVD_Init(SVD_MONTIOR_POWER eSVD_MonitroPower, uint32_t u32WarnThreshold, uint32_t u32RevVoltage, uint32_t FunMode);

#ifdef __cplusplus
}
#endif

#endif /* __SVD_H__ */

/************************ (C) COPYRIGHT FMSH *****END OF FILE****/
