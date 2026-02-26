/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_i2c.h
  * @author  FMSH Application Team
  * @brief   Head file of I2C FL Module
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
#ifndef __FM33FH0XX_FL_I2C_H
#define __FM33FH0XX_FL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl_def.h"
/** @addtogroup FM33FH0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup I2C_FL_ES_INIT I2C Exported Init structures
  * @{
  */

/**
  * @brief FL I2C Init Sturcture definition
  */
typedef struct
{
    /** I2C波特率*/
    uint32_t baudRate;

} FL_I2C_MasterMode_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup I2C_FL_Exported_Constants I2C_MASTER Exported Constants
  * @{
  */

#define    I2C_MSPCFGR_MSPEN_Pos                                  (0U)
#define    I2C_MSPCFGR_MSPEN_Msk                                  (0x1U << I2C_MSPCFGR_MSPEN_Pos)
#define    I2C_MSPCFGR_MSPEN                                      I2C_MSPCFGR_MSPEN_Msk

#define    I2C_MSPCFGR_TOEN_Pos                                   (1U)
#define    I2C_MSPCFGR_TOEN_Msk                                   (0x1U << I2C_MSPCFGR_TOEN_Pos)
#define    I2C_MSPCFGR_TOEN                                       I2C_MSPCFGR_TOEN_Msk

#define    I2C_MSPCR_RCEN_Pos                                     (3U)
#define    I2C_MSPCR_RCEN_Msk                                     (0x1U << I2C_MSPCR_RCEN_Pos)
#define    I2C_MSPCR_RCEN                                         I2C_MSPCR_RCEN_Msk

#define    I2C_MSPCR_PEN_Pos                                      (2U)
#define    I2C_MSPCR_PEN_Msk                                      (0x1U << I2C_MSPCR_PEN_Pos)
#define    I2C_MSPCR_PEN                                          I2C_MSPCR_PEN_Msk

#define    I2C_MSPCR_RSEN_Pos                                     (1U)
#define    I2C_MSPCR_RSEN_Msk                                     (0x1U << I2C_MSPCR_RSEN_Pos)
#define    I2C_MSPCR_RSEN                                         I2C_MSPCR_RSEN_Msk

#define    I2C_MSPCR_SEN_Pos                                      (0U)
#define    I2C_MSPCR_SEN_Msk                                      (0x1U << I2C_MSPCR_SEN_Pos)
#define    I2C_MSPCR_SEN                                          I2C_MSPCR_SEN_Msk

#define    I2C_MSPIER_WCOLIE_Pos                                  (6U)
#define    I2C_MSPIER_WCOLIE_Msk                                  (0x1U << I2C_MSPIER_WCOLIE_Pos)
#define    I2C_MSPIER_WCOLIE                                      I2C_MSPIER_WCOLIE_Msk

#define    I2C_MSPIER_TOIE_Pos                                    (5U)
#define    I2C_MSPIER_TOIE_Msk                                    (0x1U << I2C_MSPIER_TOIE_Pos)
#define    I2C_MSPIER_TOIE                                        I2C_MSPIER_TOIE_Msk

#define    I2C_MSPIER_SIE_Pos                                     (4U)
#define    I2C_MSPIER_SIE_Msk                                     (0x1U << I2C_MSPIER_SIE_Pos)
#define    I2C_MSPIER_SIE                                         I2C_MSPIER_SIE_Msk

#define    I2C_MSPIER_PIE_Pos                                     (3U)
#define    I2C_MSPIER_PIE_Msk                                     (0x1U << I2C_MSPIER_PIE_Pos)
#define    I2C_MSPIER_PIE                                         I2C_MSPIER_PIE_Msk

#define    I2C_MSPIER_NACKIE_Pos                                  (2U)
#define    I2C_MSPIER_NACKIE_Msk                                  (0x1U << I2C_MSPIER_NACKIE_Pos)
#define    I2C_MSPIER_NACKIE                                      I2C_MSPIER_NACKIE_Msk

#define    I2C_MSPIER_TXIE_Pos                                    (1U)
#define    I2C_MSPIER_TXIE_Msk                                    (0x1U << I2C_MSPIER_TXIE_Pos)
#define    I2C_MSPIER_TXIE                                        I2C_MSPIER_TXIE_Msk

#define    I2C_MSPIER_RXIE_Pos                                    (0U)
#define    I2C_MSPIER_RXIE_Msk                                    (0x1U << I2C_MSPIER_RXIE_Pos)
#define    I2C_MSPIER_RXIE                                        I2C_MSPIER_RXIE_Msk

#define    I2C_MSPISR_WCOL_Pos                                    (6U)
#define    I2C_MSPISR_WCOL_Msk                                    (0x1U << I2C_MSPISR_WCOL_Pos)
#define    I2C_MSPISR_WCOL                                        I2C_MSPISR_WCOL_Msk

#define    I2C_MSPISR_TO_Pos                                      (5U)
#define    I2C_MSPISR_TO_Msk                                      (0x1U << I2C_MSPISR_TO_Pos)
#define    I2C_MSPISR_TO                                          I2C_MSPISR_TO_Msk

#define    I2C_MSPISR_S_Pos                                       (4U)
#define    I2C_MSPISR_S_Msk                                       (0x1U << I2C_MSPISR_S_Pos)
#define    I2C_MSPISR_S                                           I2C_MSPISR_S_Msk

#define    I2C_MSPISR_P_Pos                                       (3U)
#define    I2C_MSPISR_P_Msk                                       (0x1U << I2C_MSPISR_P_Pos)
#define    I2C_MSPISR_P                                           I2C_MSPISR_P_Msk

#define    I2C_MSPISR_ACKSTA_Pos                                  (2U)
#define    I2C_MSPISR_ACKSTA_Msk                                  (0x1U << I2C_MSPISR_ACKSTA_Pos)
#define    I2C_MSPISR_ACKSTA                                      I2C_MSPISR_ACKSTA_Msk

#define    I2C_MSPISR_TXIF_Pos                                    (1U)
#define    I2C_MSPISR_TXIF_Msk                                    (0x1U << I2C_MSPISR_TXIF_Pos)
#define    I2C_MSPISR_TXIF                                        I2C_MSPISR_TXIF_Msk

#define    I2C_MSPISR_RXIF_Pos                                    (0U)
#define    I2C_MSPISR_RXIF_Msk                                    (0x1U << I2C_MSPISR_RXIF_Pos)
#define    I2C_MSPISR_RXIF                                        I2C_MSPISR_RXIF_Msk

#define    I2C_MSPSR_BUSY_Pos                                     (5U)
#define    I2C_MSPSR_BUSY_Msk                                     (0x1U << I2C_MSPSR_BUSY_Pos)
#define    I2C_MSPSR_BUSY                                         I2C_MSPSR_BUSY_Msk

#define    I2C_MSPSR_RW_Pos                                       (4U)
#define    I2C_MSPSR_RW_Msk                                       (0x1U << I2C_MSPSR_RW_Pos)
#define    I2C_MSPSR_RW                                           I2C_MSPSR_RW_Msk

#define    I2C_MSPSR_BF_Pos                                       (2U)
#define    I2C_MSPSR_BF_Msk                                       (0x1U << I2C_MSPSR_BF_Pos)
#define    I2C_MSPSR_BF                                           I2C_MSPSR_BF_Msk

#define    I2C_MSPSR_ACKMO_Pos                                    (0U)
#define    I2C_MSPSR_ACKMO_Msk                                    (0x1U << I2C_MSPSR_ACKMO_Pos)
#define    I2C_MSPSR_ACKMO                                        I2C_MSPSR_ACKMO_Msk

#define    I2C_MSPBGR_MSPBGRH_Pos                                 (16U)
#define    I2C_MSPBGR_MSPBGRH_Msk                                 (0x1ffU << I2C_MSPBGR_MSPBGRH_Pos)
#define    I2C_MSPBGR_MSPBGRH                                     I2C_MSPBGR_MSPBGRH_Msk

#define    I2C_MSPBGR_MSPBGRL_Pos                                 (0U)
#define    I2C_MSPBGR_MSPBGRL_Msk                                 (0x1ffU << I2C_MSPBGR_MSPBGRL_Pos)
#define    I2C_MSPBGR_MSPBGRL                                     I2C_MSPBGR_MSPBGRL_Msk

#define    I2C_MSPBUF_MSPBUF_Pos                                  (0U)
#define    I2C_MSPBUF_MSPBUF_Msk                                  (0xffU << I2C_MSPBUF_MSPBUF_Pos)
#define    I2C_MSPBUF_MSPBUF                                      I2C_MSPBUF_MSPBUF_Msk

#define    I2C_MSPTCR_SDAHD_Pos                                   (0U)
#define    I2C_MSPTCR_SDAHD_Msk                                   (0x1ffU << I2C_MSPTCR_SDAHD_Pos)
#define    I2C_MSPTCR_SDAHD                                       I2C_MSPTCR_SDAHD_Msk

#define    I2C_MSPTOR_TIMEOUT_Pos                                 (0U)
#define    I2C_MSPTOR_TIMEOUT_Msk                                 (0xfffU << I2C_MSPTOR_TIMEOUT_Pos)
#define    I2C_MSPTOR_TIMEOUT                                     I2C_MSPTOR_TIMEOUT_Msk






#define    FL_I2C_MSP_DATA_DIRECTION_SLAVE_TO_MASTER              (0x0U << I2C_MSPSR_RW_Pos)
#define    FL_I2C_MSP_DATA_DIRECTION_MASTER_TO_SLAVE              (0x1U << I2C_MSPSR_RW_Pos)

#define    FL_I2C_MSP_DATA_BUFF_STATUS_FULL                       (0x0U << I2C_MSPSR_BF_Pos)
#define    FL_I2C_MSP_DATA_BUFF_STATUS_EMPTY                      (0x1U << I2C_MSPSR_BF_Pos)

#define    FL_I2C_MASTER_RESPOND_ACK                              (0x0U << I2C_MSPSR_ACKMO_Pos)
#define    FL_I2C_MASTER_RESPOND_NACK                             (0x1U << I2C_MSPSR_ACKMO_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup I2C_MASTER_FL_Exported_Functions I2C_MASTER Exported Functions
  * @{
  */

/**
  * @brief    I2C master enable
  * @rmtoll   MSPCFGR    MSPEN    FL_I2C_Master_Enable
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_Enable(I2C_Type* I2Cx)
{
    SET_BIT(I2Cx->MSPCFGR, I2C_MSPCFGR_MSPEN_Msk);
}

/**
  * @brief    Get I2C master enable status
  * @rmtoll   MSPCFGR    MSPEN    FL_I2C_Master_IsEnabled
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsEnabled(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPCFGR, I2C_MSPCFGR_MSPEN_Msk) == I2C_MSPCFGR_MSPEN_Msk);
}

/**
  * @brief    I2C master disable
  * @rmtoll   MSPCFGR    MSPEN    FL_I2C_Master_Disable
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_Disable(I2C_Type* I2Cx)
{
    CLEAR_BIT(I2Cx->MSPCFGR, I2C_MSPCFGR_MSPEN_Msk);
}

/**
  * @brief    SCL time out enable
  * @rmtoll   MSPCFGR    TOEN    FL_I2C_Master_EnableTimeout
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_EnableTimeout(I2C_Type* I2Cx)
{
    SET_BIT(I2Cx->MSPCFGR, I2C_MSPCFGR_TOEN_Msk);
}

/**
  * @brief    Get SCL time out enable status
  * @rmtoll   MSPCFGR    TOEN    FL_I2C_Master_IsEnabledTimeout
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsEnabledTimeout(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPCFGR, I2C_MSPCFGR_TOEN_Msk) == I2C_MSPCFGR_TOEN_Msk);
}

/**
  * @brief    SCL time out disable
  * @rmtoll   MSPCFGR    TOEN    FL_I2C_Master_DisableTimeout
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_DisableTimeout(I2C_Type* I2Cx)
{
    CLEAR_BIT(I2Cx->MSPCFGR, I2C_MSPCFGR_TOEN_Msk);
}

/**
  * @brief    Master receive enable
  * @rmtoll   MSPCR    RCEN    FL_I2C_Master_EnableRX
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_EnableRX(I2C_Type* I2Cx)
{
    SET_BIT(I2Cx->MSPCR, I2C_MSPCR_RCEN_Msk);
}

/**
  * @brief    Get master receive enable status
  * @rmtoll   MSPCR    RCEN    FL_I2C_Master_IsEnabledRX
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsEnabledRX(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPCR, I2C_MSPCR_RCEN_Msk) == I2C_MSPCR_RCEN_Msk);
}

/**
  * @brief    Master receive disable
  * @rmtoll   MSPCR    RCEN    FL_I2C_Master_DisableRX
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_DisableRX(I2C_Type* I2Cx)
{
    CLEAR_BIT(I2Cx->MSPCR, I2C_MSPCR_RCEN_Msk);
}

/**
  * @brief    Stop enable
  * @rmtoll   MSPCR    PEN    FL_I2C_Master_EnableI2CStop
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_EnableI2CStop(I2C_Type* I2Cx)
{
    SET_BIT(I2Cx->MSPCR, I2C_MSPCR_PEN_Msk);
}

/**
  * @brief    Repeated START enable
  * @rmtoll   MSPCR    RSEN    FL_I2C_Master_EnableI2CRestart
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_EnableI2CRestart(I2C_Type* I2Cx)
{
    SET_BIT(I2Cx->MSPCR, I2C_MSPCR_RSEN_Msk);
}

/**
  * @brief    START enable
  * @rmtoll   MSPCR    SEN    FL_I2C_Master_EnableI2CStart
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_EnableI2CStart(I2C_Type* I2Cx)
{
    SET_BIT(I2Cx->MSPCR, I2C_MSPCR_SEN_Msk);
}

/**
  * @brief    Write collision interrupt enable
  * @rmtoll   MSPIER    WCOLIE    FL_I2C_Master_EnableIT_WriteConflict
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_EnableIT_WriteConflict(I2C_Type* I2Cx)
{
    SET_BIT(I2Cx->MSPIER, I2C_MSPIER_WCOLIE_Msk);
}

/**
  * @brief    Write collision interrupt enable
  * @rmtoll   MSPIER    WCOLIE    FL_I2C_Master_IsEnabledIT_WriteConflict
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsEnabledIT_WriteConflict(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPIER, I2C_MSPIER_WCOLIE_Msk) == I2C_MSPIER_WCOLIE_Msk);
}

/**
  * @brief    Write collision interrupt disable
  * @rmtoll   MSPIER    WCOLIE    FL_I2C_Master_DisableIT_WriteConflict
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_DisableIT_WriteConflict(I2C_Type* I2Cx)
{
    CLEAR_BIT(I2Cx->MSPIER, I2C_MSPIER_WCOLIE_Msk);
}

/**
  * @brief    SCL overtime enable 
  * @rmtoll   MSPIER    TOIE    FL_I2C_Master_EnableIT_Timeout
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_EnableIT_Timeout(I2C_Type* I2Cx)
{
    SET_BIT(I2Cx->MSPIER, I2C_MSPIER_TOIE_Msk);
}

/**
  * @brief    Get SCL overtime enable 
  * @rmtoll   MSPIER    TOIE    FL_I2C_Master_IsEnabledIT_Timeout
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsEnabledIT_Timeout(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPIER, I2C_MSPIER_TOIE_Msk) == I2C_MSPIER_TOIE_Msk);
}

/**
  * @brief    SCL overtime disable 
  * @rmtoll   MSPIER    TOIE    FL_I2C_Master_DisableIT_Timeout
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_DisableIT_Timeout(I2C_Type* I2Cx)
{
    CLEAR_BIT(I2Cx->MSPIER, I2C_MSPIER_TOIE_Msk);
}

/**
  * @brief    START interrupt enable
  * @rmtoll   MSPIER    SIE    FL_I2C_Master_EnableIT_Start
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_EnableIT_Start(I2C_Type* I2Cx)
{
    SET_BIT(I2Cx->MSPIER, I2C_MSPIER_SIE_Msk);
}

/**
  * @brief    Get START interrupt enable status
  * @rmtoll   MSPIER    SIE    FL_I2C_Master_IsEnabledIT_Start
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsEnabledIT_Start(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPIER, I2C_MSPIER_SIE_Msk) == I2C_MSPIER_SIE_Msk);
}

/**
  * @brief    START interrupt disable
  * @rmtoll   MSPIER    SIE    FL_I2C_Master_DisableIT_Start
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_DisableIT_Start(I2C_Type* I2Cx)
{
    CLEAR_BIT(I2Cx->MSPIER, I2C_MSPIER_SIE_Msk);
}

/**
  * @brief    Stop interrupt enable
  * @rmtoll   MSPIER    PIE    FL_I2C_Master_EnableIT_Stop
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_EnableIT_Stop(I2C_Type* I2Cx)
{
    SET_BIT(I2Cx->MSPIER, I2C_MSPIER_PIE_Msk);
}

/**
  * @brief    Get Stop interrupt enable status
  * @rmtoll   MSPIER    PIE    FL_I2C_Master_IsEnabledIT_Stop
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsEnabledIT_Stop(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPIER, I2C_MSPIER_PIE_Msk) == I2C_MSPIER_PIE_Msk);
}

/**
  * @brief    Stop interrupt disable
  * @rmtoll   MSPIER    PIE    FL_I2C_Master_DisableIT_Stop
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_DisableIT_Stop(I2C_Type* I2Cx)
{
    CLEAR_BIT(I2Cx->MSPIER, I2C_MSPIER_PIE_Msk);
}

/**
  * @brief    Non-ACK interrupt enable
  * @rmtoll   MSPIER    NACKIE    FL_I2C_Master_EnableIT_NACK
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_EnableIT_NACK(I2C_Type* I2Cx)
{
    SET_BIT(I2Cx->MSPIER, I2C_MSPIER_NACKIE_Msk);
}

/**
  * @brief    Get Non-ACK interrupt enable status
  * @rmtoll   MSPIER    NACKIE    FL_I2C_Master_IsEnabledIT_NACK
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsEnabledIT_NACK(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPIER, I2C_MSPIER_NACKIE_Msk) == I2C_MSPIER_NACKIE_Msk);
}

/**
  * @brief    Non-ACK interrupt disable
  * @rmtoll   MSPIER    NACKIE    FL_I2C_Master_DisableIT_NACK
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_DisableIT_NACK(I2C_Type* I2Cx)
{
    CLEAR_BIT(I2Cx->MSPIER, I2C_MSPIER_NACKIE_Msk);
}

/**
  * @brief    Trasnmit done interrupt enable
  * @rmtoll   MSPIER    TXIE    FL_I2C_Master_EnableIT_TXComplete
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_EnableIT_TXComplete(I2C_Type* I2Cx)
{
    SET_BIT(I2Cx->MSPIER, I2C_MSPIER_TXIE_Msk);
}

/**
  * @brief    Get trasnmit done interrupt enable
  * @rmtoll   MSPIER    TXIE    FL_I2C_Master_IsEnabledIT_TXComplete
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsEnabledIT_TXComplete(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPIER, I2C_MSPIER_TXIE_Msk) == I2C_MSPIER_TXIE_Msk);
}

/**
  * @brief    Trasnmit done interrupt disable
  * @rmtoll   MSPIER    TXIE    FL_I2C_Master_DisableIT_TXComplete
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_DisableIT_TXComplete(I2C_Type* I2Cx)
{
    CLEAR_BIT(I2Cx->MSPIER, I2C_MSPIER_TXIE_Msk);
}

/**
  * @brief    Receive done interrupt enable
  * @rmtoll   MSPIER    RXIE    FL_I2C_Master_EnableIT_RXComplete
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_EnableIT_RXComplete(I2C_Type* I2Cx)
{
    SET_BIT(I2Cx->MSPIER, I2C_MSPIER_RXIE_Msk);
}

/**
  * @brief    Get receive done interrupt enable status
  * @rmtoll   MSPIER    RXIE    FL_I2C_Master_IsEnabledIT_RXComplete
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsEnabledIT_RXComplete(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPIER, I2C_MSPIER_RXIE_Msk) == I2C_MSPIER_RXIE_Msk);
}

/**
  * @brief    Receive done interrupt disable
  * @rmtoll   MSPIER    RXIE    FL_I2C_Master_DisableIT_RXComplete
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_DisableIT_RXComplete(I2C_Type* I2Cx)
{
    CLEAR_BIT(I2Cx->MSPIER, I2C_MSPIER_RXIE_Msk);
}

/**
  * @brief    Get write collision interrupt flag
  * @rmtoll   MSPISR    WCOL    FL_I2C_Master_IsActiveFlag_WriteConflict
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsActiveFlag_WriteConflict(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPISR, I2C_MSPISR_WCOL_Msk) == (I2C_MSPISR_WCOL_Msk));
}

/**
  * @brief    Clear write collision interrupt flag
  * @rmtoll   MSPISR    WCOL    FL_I2C_Master_ClearFlag_WriteConflict
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_ClearFlag_WriteConflict(I2C_Type* I2Cx)
{
    WRITE_REG(I2Cx->MSPISR, I2C_MSPISR_WCOL_Msk);
}

/**
  * @brief    Get SCL overtime interrupt flag
  * @rmtoll   MSPISR    TO    FL_I2C_Master_IsActiveFlag_Timeout
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsActiveFlag_Timeout(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPISR, I2C_MSPISR_TO_Msk) == (I2C_MSPISR_TO_Msk));
}

/**
  * @brief    Clear SCL overtime interrupt flag
  * @rmtoll   MSPISR    TO    FL_I2C_Master_ClearFlag_Timeout
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_ClearFlag_Timeout(I2C_Type* I2Cx)
{
    WRITE_REG(I2Cx->MSPISR, I2C_MSPISR_TO_Msk);
}

/**
  * @brief    Get start interrupt flag
  * @rmtoll   MSPISR    S    FL_I2C_Master_IsActiveFlag_Start
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsActiveFlag_Start(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPISR, I2C_MSPISR_S_Msk) == (I2C_MSPISR_S_Msk));
}

/**
  * @brief    Get Stop interrupt flag
  * @rmtoll   MSPISR    P    FL_I2C_Master_IsActiveFlag_Stop
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsActiveFlag_Stop(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPISR, I2C_MSPISR_P_Msk) == (I2C_MSPISR_P_Msk));
}

/**
  * @brief    Get acknowledge status flag
  * @rmtoll   MSPISR    ACKSTA    FL_I2C_Master_IsActiveFlag_NACK
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsActiveFlag_NACK(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPISR, I2C_MSPISR_ACKSTA_Msk) == (I2C_MSPISR_ACKSTA_Msk));
}

/**
  * @brief    Clear acknowledge status flag
  * @rmtoll   MSPISR    ACKSTA    FL_I2C_Master_ClearFlag_NACK
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_ClearFlag_NACK(I2C_Type* I2Cx)
{
    WRITE_REG(I2Cx->MSPISR, I2C_MSPISR_ACKSTA_Msk);
}

/**
  * @brief    Get trasnmit done interrupt flag
  * @rmtoll   MSPISR    TXIF    FL_I2C_Master_IsActiveFlag_TXComplete
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsActiveFlag_TXComplete(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPISR, I2C_MSPISR_TXIF_Msk) == (I2C_MSPISR_TXIF_Msk));
}

/**
  * @brief    Clear trasnmit done interrupt flag
  * @rmtoll   MSPISR    TXIF    FL_I2C_Master_ClearFlag_TXComplete
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_ClearFlag_TXComplete(I2C_Type* I2Cx)
{
    WRITE_REG(I2Cx->MSPISR, I2C_MSPISR_TXIF_Msk);
}

/**
  * @brief    Get receive done interrupt flag
  * @rmtoll   MSPISR    RXIF    FL_I2C_Master_IsActiveFlag_RXComplete
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsActiveFlag_RXComplete(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPISR, I2C_MSPISR_RXIF_Msk) == (I2C_MSPISR_RXIF_Msk));
}

/**
  * @brief    Clear receive done interrupt flag
  * @rmtoll   MSPISR    RXIF    FL_I2C_Master_ClearFlag_RXComplete
  * @param    I2Cx I2C instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_ClearFlag_RXComplete(I2C_Type* I2Cx)
{
    WRITE_REG(I2Cx->MSPISR, I2C_MSPISR_RXIF_Msk);
}

/**
  * @brief    Get I2C busy status
  * @rmtoll   MSPSR    BUSY    FL_I2C_Master_IsActiveFlag_Busy
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2C_Master_IsActiveFlag_Busy(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPSR, I2C_MSPSR_BUSY_Msk) == (I2C_MSPSR_BUSY_Msk));
}

/**
  * @brief    Get I2C transmit direction
  * @rmtoll   MSPSR    RW    FL_I2C_Master_GetDirection
  * @param    I2Cx I2C instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_I2C_MSP_DATA_DIRECTION_SLAVE_TO_MASTER
  *           @arg @ref FL_I2C_MSP_DATA_DIRECTION_MASTER_TO_SLAVE
  */
__STATIC_INLINE uint32_t FL_I2C_Master_GetDirection(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPSR, I2C_MSPSR_RW_Msk));
}

/**
  * @brief    Get buffer full status
  * @rmtoll   MSPSR    BF    FL_I2C_Master_GetBuffStatus
  * @param    I2Cx I2C instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_I2C_MSP_DATA_BUFF_STATUS_FULL
  *           @arg @ref FL_I2C_MSP_DATA_BUFF_STATUS_EMPTY
  */
__STATIC_INLINE uint32_t FL_I2C_Master_GetBuffStatus(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPSR, I2C_MSPSR_BF_Msk));
}

/**
  * @brief    Set ACK master output
  * @rmtoll   MSPSR    ACKMO    FL_I2C_Master_SetRespond
  * @param    I2Cx I2C instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_I2C_MASTER_RESPOND_ACK
  *           @arg @ref FL_I2C_MASTER_RESPOND_NACK
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_SetRespond(I2C_Type* I2Cx, uint32_t mode)
{
    MODIFY_REG(I2Cx->MSPSR, I2C_MSPSR_ACKMO_Msk, mode);
}

/**
  * @brief    Get ACK master output
  * @rmtoll   MSPSR    ACKMO    FL_I2C_Master_GetRespond
  * @param    I2Cx I2C instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_I2C_MASTER_RESPOND_ACK
  *           @arg @ref FL_I2C_MASTER_RESPOND_NACK
  */
__STATIC_INLINE uint32_t FL_I2C_Master_GetRespond(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPSR, I2C_MSPSR_ACKMO_Msk));
}

/**
  * @brief    Set master SCL high level length
  * @rmtoll   MSPBGR    MSPBGRH    FL_I2C_Master_WriteSCLHighWidth
  * @param    I2Cx I2C instance
  * @param    width 
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_WriteSCLHighWidth(I2C_Type* I2Cx, uint32_t width)
{
    MODIFY_REG(I2Cx->MSPBGR, (0x1ffU << 16U), (width << 16U));
}

/**
  * @brief    Get master SCL high level length
  * @rmtoll   MSPBGR    MSPBGRH    FL_I2C_Master_ReadSCLHighWidth
  * @param    I2Cx I2C instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_I2C_Master_ReadSCLHighWidth(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPBGR, (0x1ffU << 16U)) >> 16U);
}

/**
  * @brief    Set master SCL low level length
  * @rmtoll   MSPBGR    MSPBGRL    FL_I2C_Master_WriteSCLLowWidth
  * @param    I2Cx I2C instance
  * @param    width 
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_WriteSCLLowWidth(I2C_Type* I2Cx, uint32_t width)
{
    MODIFY_REG(I2Cx->MSPBGR, (0x1ffU << 0U), (width << 0U));
}

/**
  * @brief    Get master SCL low level length
  * @rmtoll   MSPBGR    MSPBGRL    FL_I2C_Master_ReadSCLLowWidth
  * @param    I2Cx I2C instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_I2C_Master_ReadSCLLowWidth(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPBGR, (0x1ffU << 0U)) >> 0U);
}

/**
  * @brief    Set master data buffer
  * @rmtoll   MSPBUF    MSPBUF    FL_I2C_Master_WriteTXBuff
  * @param    I2Cx I2C instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_WriteTXBuff(I2C_Type* I2Cx, uint32_t data)
{
    MODIFY_REG(I2Cx->MSPBUF, (0xffU << 0U), (data << 0U));
}

/**
  * @brief    Get master data buffer
  * @rmtoll   MSPBUF    MSPBUF    FL_I2C_Master_ReadRXBuff
  * @param    I2Cx I2C instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_I2C_Master_ReadRXBuff(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPBUF, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Set SDA hold time
  * @rmtoll   MSPTCR    SDAHD    FL_I2C_Master_WriteSDAHoldTime
  * @param    I2Cx I2C instance
  * @param    time 
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_WriteSDAHoldTime(I2C_Type* I2Cx, uint32_t time)
{
    MODIFY_REG(I2Cx->MSPTCR, (0x1ffU << 0U), (time << 0U));
}

/**
  * @brief    Get SDA hold time
  * @rmtoll   MSPTCR    SDAHD    FL_I2C_Master_ReadSDAHoldTime
  * @param    I2Cx I2C instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_I2C_Master_ReadSDAHoldTime(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPTCR, (0x1ffU << 0U)) >> 0U);
}

/**
  * @brief    Set SCL stretching time out 
  * @rmtoll   MSPTOR    TIMEOUT    FL_I2C_Master_WriteSlaveSCLTimeout
  * @param    I2Cx I2C instance
  * @param    time 
  * @retval   None
  */
__STATIC_INLINE void FL_I2C_Master_WriteSlaveSCLTimeout(I2C_Type* I2Cx, uint32_t time)
{
    MODIFY_REG(I2Cx->MSPTOR, (0xfffU << 0U), (time << 0U));
}

/**
  * @brief    Get SCL stretching time out 
  * @rmtoll   MSPTOR    TIMEOUT    FL_I2C_Master_ReadSlaveSCLTimeout
  * @param    I2Cx I2C instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_I2C_Master_ReadSlaveSCLTimeout(I2C_Type* I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->MSPTOR, (0xfffU << 0U)) >> 0U);
}

/**
  * @}
  */

/** @defgroup I2C_MASTER_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_I2C_DeInit(I2C_Type *I2Cx);
FL_ErrorStatus FL_I2C_MasterMode_Init(I2C_Type *I2Cx, FL_I2C_MasterMode_InitTypeDef *I2C_InitStruct);
void FL_I2C_MasterMode_StructInit(FL_I2C_MasterMode_InitTypeDef *I2C_InitStruct);
/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_I2C_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2024-01-23*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
