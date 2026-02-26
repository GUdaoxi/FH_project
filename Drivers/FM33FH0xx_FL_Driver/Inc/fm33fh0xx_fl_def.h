/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_def.h
  * @author  FMSH Application Team
  * @brief   Header file of FL Driver Library Defines
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
#ifndef __FM33FH0XX_FL_DEF_H
#define __FM33FH0XX_FL_DEF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx.h"
#include "fm33_assert.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/* Macros ---------------------------------------------------------------------------------------------*/
/** @defgroup FL_Exported_Macros FL Driver Library Private Macros
  * @{
  */

/**
  * @brief Bit-wise operation macros used by FL driver library functions
  */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)    ((REG) & (BIT))
#define CLEAR_REG(REG)        ((REG) = (0x0))
#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/**
  * @}
  */

/* Types ----------------------------------------------------------------------------------------------*/
/** @defgroup FL_PT_Return FL Driver Library Private Return Type Defines
  * @{
  */

typedef enum
{
    FL_RESET = 0U,
    FL_SET = !FL_RESET
} FL_FlagStatus, FL_ITStatus;

typedef enum
{
    FL_DISABLE = 0U,
    FL_ENABLE = !FL_DISABLE
} FL_FunState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == FL_DISABLE) || ((STATE) == FL_ENABLE))

typedef enum
{
    FL_FAIL = 0U,
    FL_PASS = !FL_FAIL
} FL_ErrorStatus;

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_DEF_H */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
