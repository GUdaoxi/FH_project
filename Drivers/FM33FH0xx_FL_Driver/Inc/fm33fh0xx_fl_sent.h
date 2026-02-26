/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_sent.h
  * @author  FMSH Application Team
  * @brief   Head file of SENT FL Module 
  * @version  V1.1.0
  * @date     13. June 2025
  ****************************************************************************************************
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
  ****************************************************************************************************
  */


/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33FH0XX_FL_SENT_H
#define __FM33FH0XX_FL_SENT_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl_def.h"
/** @addtogroup FM33FH0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup SENT_FL_ES_INIT SENT Exported Init structures
  * @{
  */

/**
  * @brief FL SENT Init Sturcture definition
  */
typedef struct
{
    /*配置接收发送*/
    uint32_t transferDirection;
    /*时钟预分频*/
    uint32_t prescaler;
    /*发送模式*/
    uint32_t transmitMode;
    /*接收数字滤波*/
    uint32_t digitalFilterLength;
    /*数据Nibble个数*/
    uint32_t dataNibbleNumber;
    /*硬件CRC*/
    uint32_t hardwareCRC;
    /*CRC模式*/
    uint32_t CRCMode;
    /*暂停脉冲*/
    uint32_t pausePulse;
    /*发送帧长度*/
    uint32_t frameTime;
    /*空闲时输出电平*/
    uint32_t idleoutputpulse;
    /*sync长度范围最大值*/
    uint32_t syncPulseMax;
    /*sync长度范围最小值*/
    uint32_t syncPulseMin;
} FL_SENT_InitTypeDef;


/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup SENT_FL_Exported_Constants SENT Exported Constants
  * @{
  */

#define    SENT_CR_RXEN_Pos                                       (1U)
#define    SENT_CR_RXEN_Msk                                       (0x1U << SENT_CR_RXEN_Pos)
#define    SENT_CR_RXEN                                           SENT_CR_RXEN_Msk

#define    SENT_CR_TXEN_Pos                                       (0U)
#define    SENT_CR_TXEN_Msk                                       (0x1U << SENT_CR_TXEN_Pos)
#define    SENT_CR_TXEN                                           SENT_CR_TXEN_Msk

#define    SENT_CFGR_DFLEN_Pos                                    (24U)
#define    SENT_CFGR_DFLEN_Msk                                    (0xffU << SENT_CFGR_DFLEN_Pos)
#define    SENT_CFGR_DFLEN                                        SENT_CFGR_DFLEN_Msk

#define    SENT_CFGR_FTXIE_Pos                                    (21U)
#define    SENT_CFGR_FTXIE_Msk                                    (0x1U << SENT_CFGR_FTXIE_Pos)
#define    SENT_CFGR_FTXIE                                        SENT_CFGR_FTXIE_Msk

#define    SENT_CFGR_NTXIE_Pos                                    (20U)
#define    SENT_CFGR_NTXIE_Msk                                    (0x1U << SENT_CFGR_NTXIE_Pos)
#define    SENT_CFGR_NTXIE                                        SENT_CFGR_NTXIE_Msk

#define    SENT_CFGR_SYNCIE_Pos                                   (19U)
#define    SENT_CFGR_SYNCIE_Msk                                   (0x1U << SENT_CFGR_SYNCIE_Pos)
#define    SENT_CFGR_SYNCIE                                       SENT_CFGR_SYNCIE_Msk

#define    SENT_CFGR_ERRIE_Pos                                    (18U)
#define    SENT_CFGR_ERRIE_Msk                                    (0x1U << SENT_CFGR_ERRIE_Pos)
#define    SENT_CFGR_ERRIE                                        SENT_CFGR_ERRIE_Msk

#define    SENT_CFGR_FRXIE_Pos                                    (17U)
#define    SENT_CFGR_FRXIE_Msk                                    (0x1U << SENT_CFGR_FRXIE_Pos)
#define    SENT_CFGR_FRXIE                                        SENT_CFGR_FRXIE_Msk

#define    SENT_CFGR_NRXIE_Pos                                    (16U)
#define    SENT_CFGR_NRXIE_Msk                                    (0x1U << SENT_CFGR_NRXIE_Pos)
#define    SENT_CFGR_NRXIE                                        SENT_CFGR_NRXIE_Msk

#define    SENT_CFGR_NIBCNT_Pos                                   (8U)
#define    SENT_CFGR_NIBCNT_Msk                                   (0x7U << SENT_CFGR_NIBCNT_Pos)
#define    SENT_CFGR_NIBCNT                                       SENT_CFGR_NIBCNT_Msk

#define    SENT_CFGR_CRCM_Pos                                     (5U)
#define    SENT_CFGR_CRCM_Msk                                     (0x1U << SENT_CFGR_CRCM_Pos)
#define    SENT_CFGR_CRCM                                         SENT_CFGR_CRCM_Msk

#define    SENT_CFGR_PPEN_Pos                                     (4U)
#define    SENT_CFGR_PPEN_Msk                                     (0x1U << SENT_CFGR_PPEN_Pos)
#define    SENT_CFGR_PPEN                                         SENT_CFGR_PPEN_Msk

#define    SENT_CFGR_CRCEN_Pos                                    (3U)
#define    SENT_CFGR_CRCEN_Msk                                    (0x1U << SENT_CFGR_CRCEN_Pos)
#define    SENT_CFGR_CRCEN                                        SENT_CFGR_CRCEN_Msk

#define    SENT_CFGR_TXPOL_Pos                                    (2U)
#define    SENT_CFGR_TXPOL_Msk                                    (0x1U << SENT_CFGR_TXPOL_Pos)
#define    SENT_CFGR_TXPOL                                        SENT_CFGR_TXPOL_Msk

#define    SENT_CFGR_TXM_Pos                                      (1U)
#define    SENT_CFGR_TXM_Msk                                      (0x1U << SENT_CFGR_TXM_Pos)
#define    SENT_CFGR_TXM                                          SENT_CFGR_TXM_Msk

#define    SENT_CFGR_MOD_Pos                                      (0U)
#define    SENT_CFGR_MOD_Msk                                      (0x1U << SENT_CFGR_MOD_Pos)
#define    SENT_CFGR_MOD                                          SENT_CFGR_MOD_Msk

#define    SENT_PSR_PSC_Pos                                       (0U)
#define    SENT_PSR_PSC_Msk                                       (0xffffU << SENT_PSR_PSC_Pos)
#define    SENT_PSR_PSC                                           SENT_PSR_PSC_Msk

#define    SENT_FTR_LEN_Pos                                       (0U)
#define    SENT_FTR_LEN_Msk                                       (0xfffU << SENT_FTR_LEN_Pos)
#define    SENT_FTR_LEN                                           SENT_FTR_LEN_Msk

#define    SENT_SR_NIB_Pos                                        (19U)
#define    SENT_SR_NIB_Msk                                        (0x7U << SENT_SR_NIB_Pos)
#define    SENT_SR_NIB                                            SENT_SR_NIB_Msk

#define    SENT_SR_RXIDLE_Pos                                     (18U)
#define    SENT_SR_RXIDLE_Msk                                     (0x1U << SENT_SR_RXIDLE_Pos)
#define    SENT_SR_RXIDLE                                         SENT_SR_RXIDLE_Msk

#define    SENT_SR_PAUSE_Pos                                      (17U)
#define    SENT_SR_PAUSE_Msk                                      (0x1U << SENT_SR_PAUSE_Pos)
#define    SENT_SR_PAUSE                                          SENT_SR_PAUSE_Msk

#define    SENT_SR_SYNC_Pos                                       (16U)
#define    SENT_SR_SYNC_Msk                                       (0x1U << SENT_SR_SYNC_Pos)
#define    SENT_SR_SYNC                                           SENT_SR_SYNC_Msk

#define    SENT_SR_SSERR_Pos                                      (12U)
#define    SENT_SR_SSERR_Msk                                      (0x1U << SENT_SR_SSERR_Pos)
#define    SENT_SR_SSERR                                          SENT_SR_SSERR_Msk

#define    SENT_SR_NBERR_Pos                                      (11U)
#define    SENT_SR_NBERR_Msk                                      (0x1U << SENT_SR_NBERR_Pos)
#define    SENT_SR_NBERR                                          SENT_SR_NBERR_Msk

#define    SENT_SR_CRCERR_Pos                                     (10U)
#define    SENT_SR_CRCERR_Msk                                     (0x1U << SENT_SR_CRCERR_Pos)
#define    SENT_SR_CRCERR                                         SENT_SR_CRCERR_Msk

#define    SENT_SR_NCNTERR_Pos                                    (9U)
#define    SENT_SR_NCNTERR_Msk                                    (0x1U << SENT_SR_NCNTERR_Pos)
#define    SENT_SR_NCNTERR                                        SENT_SR_NCNTERR_Msk

#define    SENT_SR_SYNCERR_Pos                                    (8U)
#define    SENT_SR_SYNCERR_Msk                                    (0x1U << SENT_SR_SYNCERR_Pos)
#define    SENT_SR_SYNCERR                                        SENT_SR_SYNCERR_Msk

#define    SENT_SR_FTXF_Pos                                       (5U)
#define    SENT_SR_FTXF_Msk                                       (0x1U << SENT_SR_FTXF_Pos)
#define    SENT_SR_FTXF                                           SENT_SR_FTXF_Msk

#define    SENT_SR_NTXF_Pos                                       (4U)
#define    SENT_SR_NTXF_Msk                                       (0x1U << SENT_SR_NTXF_Pos)
#define    SENT_SR_NTXF                                           SENT_SR_NTXF_Msk

#define    SENT_SR_SYNCF_Pos                                      (3U)
#define    SENT_SR_SYNCF_Msk                                      (0x1U << SENT_SR_SYNCF_Pos)
#define    SENT_SR_SYNCF                                          SENT_SR_SYNCF_Msk

#define    SENT_SR_FRXF_Pos                                       (1U)
#define    SENT_SR_FRXF_Msk                                       (0x1U << SENT_SR_FRXF_Pos)
#define    SENT_SR_FRXF                                           SENT_SR_FRXF_Msk

#define    SENT_SR_NRXF_Pos                                       (0U)
#define    SENT_SR_NRXF_Msk                                       (0x1U << SENT_SR_NRXF_Pos)
#define    SENT_SR_NRXF                                           SENT_SR_NRXF_Msk

#define    SENT_DR_CRC_Pos                                        (28U)
#define    SENT_DR_CRC_Msk                                        (0xfU << SENT_DR_CRC_Pos)
#define    SENT_DR_CRC                                            SENT_DR_CRC_Msk

#define    SENT_DR_DATA6_Pos                                      (24U)
#define    SENT_DR_DATA6_Msk                                      (0xfU << SENT_DR_DATA6_Pos)
#define    SENT_DR_DATA6                                          SENT_DR_DATA6_Msk

#define    SENT_DR_DATA5_Pos                                      (20U)
#define    SENT_DR_DATA5_Msk                                      (0xfU << SENT_DR_DATA5_Pos)
#define    SENT_DR_DATA5                                          SENT_DR_DATA5_Msk

#define    SENT_DR_DATA4_Pos                                      (16U)
#define    SENT_DR_DATA4_Msk                                      (0xfU << SENT_DR_DATA4_Pos)
#define    SENT_DR_DATA4                                          SENT_DR_DATA4_Msk

#define    SENT_DR_DATA3_Pos                                      (12U)
#define    SENT_DR_DATA3_Msk                                      (0xfU << SENT_DR_DATA3_Pos)
#define    SENT_DR_DATA3                                          SENT_DR_DATA3_Msk

#define    SENT_DR_DATA2_Pos                                      (8U)
#define    SENT_DR_DATA2_Msk                                      (0xfU << SENT_DR_DATA2_Pos)
#define    SENT_DR_DATA2                                          SENT_DR_DATA2_Msk

#define    SENT_DR_DATA1_Pos                                      (4U)
#define    SENT_DR_DATA1_Msk                                      (0xfU << SENT_DR_DATA1_Pos)
#define    SENT_DR_DATA1                                          SENT_DR_DATA1_Msk

#define    SENT_DR_STATUS_Pos                                     (0U)
#define    SENT_DR_STATUS_Msk                                     (0xfU << SENT_DR_STATUS_Pos)
#define    SENT_DR_STATUS                                         SENT_DR_STATUS_Msk

#define    SENT_DR_DRREG_Pos                                      (0U)
#define    SENT_DR_DRREG_Msk                                      (0xffffffffU << SENT_DR_DRREG_Pos)
#define    SENT_DR_DRREG                                          SENT_DR_DRREG_Msk

#define    SENT_SYNC_SYNCMAX_Pos                                  (16U)
#define    SENT_SYNC_SYNCMAX_Msk                                  (0xfffU << SENT_SYNC_SYNCMAX_Pos)
#define    SENT_SYNC_SYNCMAX                                      SENT_SYNC_SYNCMAX_Msk

#define    SENT_SYNC_SYNCMIN_Pos                                  (0U)
#define    SENT_SYNC_SYNCMIN_Msk                                  (0xfffU << SENT_SYNC_SYNCMIN_Pos)
#define    SENT_SYNC_SYNCMIN                                      SENT_SYNC_SYNCMIN_Msk

#define    SENT_RCAL_BASECNT_Pos                                  (16U)
#define    SENT_RCAL_BASECNT_Msk                                  (0x3fU << SENT_RCAL_BASECNT_Pos)
#define    SENT_RCAL_BASECNT                                      SENT_RCAL_BASECNT_Msk

#define    SENT_RCAL_RCAL_Pos                                     (0U)
#define    SENT_RCAL_RCAL_Msk                                     (0xfffU << SENT_RCAL_RCAL_Pos)
#define    SENT_RCAL_RCAL                                         SENT_RCAL_RCAL_Msk






#define    FL_SENT_DATANIBBLES_COUNT_1N                           (0x1U << SENT_CFGR_NIBCNT_Pos)
#define    FL_SENT_DATANIBBLES_COUNT_2N                           (0x2U << SENT_CFGR_NIBCNT_Pos)
#define    FL_SENT_DATANIBBLES_COUNT_3N                           (0x3U << SENT_CFGR_NIBCNT_Pos)
#define    FL_SENT_DATANIBBLES_COUNT_4N                           (0x4U << SENT_CFGR_NIBCNT_Pos)
#define    FL_SENT_DATANIBBLES_COUNT_5N                           (0x5U << SENT_CFGR_NIBCNT_Pos)
#define    FL_SENT_DATANIBBLES_COUNT_6N                           (0x6U << SENT_CFGR_NIBCNT_Pos)


#define    FL_SENT_CRCMODE_RECOMMENDED                            (0x0U << SENT_CFGR_CRCM_Pos)
#define    FL_SENT_CRCMODE_LEGACY                                 (0x1U << SENT_CFGR_CRCM_Pos)


#define    FL_SENT_IDLEOUTPUT_HIGH                                (0x0U << SENT_CFGR_TXPOL_Pos)
#define    FL_SENT_IDLEOUTPUT_LOW                                 (0x1U << SENT_CFGR_TXPOL_Pos)


#define    FL_SENT_TXMODE_SOFTWARE                                (0x0U << SENT_CFGR_TXM_Pos)
#define    FL_SENT_TXMODE_SERIAL                                  (0x1U << SENT_CFGR_TXM_Pos)


#define    FL_SENT_MODE_RX                                        (0x0U << SENT_CFGR_MOD_Pos)
#define    FL_SENT_MODE_TX                                        (0x1U << SENT_CFGR_MOD_Pos)


#define    FL_SENT_NIBBLE_STATUS                                  (0x0U << SENT_SR_NIB_Pos)
#define    FL_SENT_NIBBLE_DATA_1ST                                (0x1U << SENT_SR_NIB_Pos)
#define    FL_SENT_NIBBLE_DATA_2ST                                (0x2U << SENT_SR_NIB_Pos)
#define    FL_SENT_NIBBLE_DATA_3ST                                (0x3U << SENT_SR_NIB_Pos)
#define    FL_SENT_NIBBLE_DATA_4ST                                (0x4U << SENT_SR_NIB_Pos)
#define    FL_SENT_NIBBLE_DATA_5ST                                (0x5U << SENT_SR_NIB_Pos)
#define    FL_SENT_NIBBLE_DATA_6ST                                (0x6U << SENT_SR_NIB_Pos)
#define    FL_SENT_NIBBLE_CRC                                     (0x7U << SENT_SR_NIB_Pos)

#define    FL_SENT_PAUSESTATUS_TXANDRX                            (0x1U << SENT_SR_PAUSE_Pos)
#define    FL_SENT_PAUSESTATUS_NO_TXANDRX                         (0x0U << SENT_SR_PAUSE_Pos)

#define    FL_SENT_SYNCSTATUS_TXANDRX                             (0x1U << SENT_SR_SYNC_Pos)
#define    FL_SENT_SYNCSTATUS_NO_TXANDRX                          (0x0U << SENT_SR_SYNC_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup SENT_FL_Exported_Functions SENT Exported Functions
  * @{
  */

/**
  * @brief    SENT receive enable  
  * @rmtoll   CR    RXEN    FL_SENT_EnableRX
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableRX(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CR, SENT_CR_RXEN_Msk);
}

/**
  * @brief    SENT receive disable  
  * @rmtoll   CR    RXEN    FL_SENT_DisableRX
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableRX(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CR, SENT_CR_RXEN_Msk);
}

/**
  * @brief    Get SENT receive enable status
  * @rmtoll   CR    RXEN    FL_SENT_IsEnableRX
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnableRX(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CR, SENT_CR_RXEN_Msk) == SENT_CR_RXEN_Msk);
}

/**
  * @brief    SENT transmit enable  
  * @rmtoll   CR    TXEN    FL_SENT_EnableTX
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableTX(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CR, SENT_CR_TXEN_Msk);
}

/**
  * @brief    SENT transmit disable  
  * @rmtoll   CR    TXEN    FL_SENT_DisableTX
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableTX(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CR, SENT_CR_TXEN_Msk);
}

/**
  * @brief    Get SENT receive enable status  
  * @rmtoll   CR    TXEN    FL_SENT_IsEnableTX
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnableTX(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CR, SENT_CR_TXEN_Msk) == SENT_CR_TXEN_Msk);
}

/**
  * @brief    Set the APBCLK sampling digital filter length
  * @rmtoll   CFGR    DFLEN    FL_SENT_WriteDigitalFilterLength
  * @param    SENTx SENT instance
  * @param    dflength 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteDigitalFilterLength(SENT_Type* SENTx, uint32_t dflength)
{
    MODIFY_REG(SENTx->CFGR, (0xffU << 24U), (dflength << 24U));
}

/**
  * @brief    Get the APBCLK sampling digital filter length
  * @rmtoll   CFGR    DFLEN    FL_SENT_ReadDigitalFilterLength
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadDigitalFilterLength(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, (0xffU << 24U)) >> 24U);
}

/**
  * @brief    Enable frame transmit complete interrupt
  * @rmtoll   CFGR    FTXIE    FL_SENT_EnableIT_FrameTransmitComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableIT_FrameTransmitComplete(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_FTXIE_Msk);
}

/**
  * @brief    Disable frame transmit complete interrupt
  * @rmtoll   CFGR    FTXIE    FL_SENT_DisableIT_FrameTransmitComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableIT_FrameTransmitComplete(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_FTXIE_Msk);
}

/**
  * @brief    Get frame transmit complete interrupt status
  * @rmtoll   CFGR    FTXIE    FL_SENT_IsEnabledIT_FrameTransmitComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledIT_FrameTransmitComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_FTXIE_Msk) == SENT_CFGR_FTXIE_Msk);
}

/**
  * @brief    Enable nibble transmit complete interrupt
  * @rmtoll   CFGR    NTXIE    FL_SENT_EnableIT_NibbleTransmitComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableIT_NibbleTransmitComplete(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_NTXIE_Msk);
}

/**
  * @brief    Disable nibble transmit complete interrupt
  * @rmtoll   CFGR    NTXIE    FL_SENT_DisableIT_NibbleTransmitComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableIT_NibbleTransmitComplete(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_NTXIE_Msk);
}

/**
  * @brief    Get nibble transmit complete interrupt status
  * @rmtoll   CFGR    NTXIE    FL_SENT_IsEnabledIT_NibbleTransmitComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledIT_NibbleTransmitComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_NTXIE_Msk) == SENT_CFGR_NTXIE_Msk);
}

/**
  * @brief    Enable Sync pulse transmit complete interrupt
  * @rmtoll   CFGR    SYNCIE    FL_SENT_EnableIT_SyncPulseReceiveCorrectly
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableIT_SyncPulseReceiveCorrectly(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_SYNCIE_Msk);
}

/**
  * @brief    Disable Sync pulse transmit complete interrupt
  * @rmtoll   CFGR    SYNCIE    FL_SENT_DisableIT_SyncPulseReceiveCorrectly
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableIT_SyncPulseReceiveCorrectly(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_SYNCIE_Msk);
}

/**
  * @brief    Get Sync pulse transmit complete interrupt status
  * @rmtoll   CFGR    SYNCIE    FL_SENT_IsEnabledIT_SyncPulseReceiveCorrectly
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledIT_SyncPulseReceiveCorrectly(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_SYNCIE_Msk) == SENT_CFGR_SYNCIE_Msk);
}

/**
  * @brief    Enable ErrEvent transmit complete interrupt
  * @rmtoll   CFGR    ERRIE    FL_SENT_EnableIT_ErrEventsOccurred
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableIT_ErrEventsOccurred(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_ERRIE_Msk);
}

/**
  * @brief    Disable ErrEvent transmit complete interrupt
  * @rmtoll   CFGR    ERRIE    FL_SENT_DisableIT_ErrEventsOccurred
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableIT_ErrEventsOccurred(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_ERRIE_Msk);
}

/**
  * @brief    Get ErrEvent transmit complete interrupt status
  * @rmtoll   CFGR    ERRIE    FL_SENT_IsEnabledIT_ErrEventsOccurred
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledIT_ErrEventsOccurred(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_ERRIE_Msk) == SENT_CFGR_ERRIE_Msk);
}

/**
  * @brief    Enable frame receive complete interrupt
  * @rmtoll   CFGR    FRXIE    FL_SENT_EnableIT_FrameReceiveComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableIT_FrameReceiveComplete(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_FRXIE_Msk);
}

/**
  * @brief    Disable frame receive complete interrupt
  * @rmtoll   CFGR    FRXIE    FL_SENT_DisableIT_FrameReceiveComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableIT_FrameReceiveComplete(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_FRXIE_Msk);
}

/**
  * @brief    Get frame receive complete interrupt status
  * @rmtoll   CFGR    FRXIE    FL_SENT_IsEnabledIT_FrameReceiveComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledIT_FrameReceiveComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_FRXIE_Msk) == SENT_CFGR_FRXIE_Msk);
}

/**
  * @brief    Enable nibble receive complete interrupt
  * @rmtoll   CFGR    NRXIE    FL_SENT_EnableIT_NibbleReceiveComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableIT_NibbleReceiveComplete(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_NRXIE_Msk);
}

/**
  * @brief    Disable nibble receive complete interrupt
  * @rmtoll   CFGR    NRXIE    FL_SENT_DisableIT_NibbleReceiveComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableIT_NibbleReceiveComplete(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_NRXIE_Msk);
}

/**
  * @brief    Get nibble receive complete interrupt status
  * @rmtoll   CFGR    NRXIE    FL_SENT_IsEnabledIT_NibbleReceiveComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledIT_NibbleReceiveComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_NRXIE_Msk) == SENT_CFGR_NRXIE_Msk);
}

/**
  * @brief    Set data nibbles count
  * @rmtoll   CFGR    NIBCNT    FL_SENT_SetDataNibblesCount
  * @param    SENTx SENT instance
  * @param    nibblecount This parameter can be one of the following values:
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_1N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_2N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_3N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_4N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_5N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_6N
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_SetDataNibblesCount(SENT_Type* SENTx, uint32_t nibblecount)
{
    MODIFY_REG(SENTx->CFGR, SENT_CFGR_NIBCNT_Msk, nibblecount);
}

/**
  * @brief    Get data nibbles count
  * @rmtoll   CFGR    NIBCNT    FL_SENT_GetDataNibblesCount
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_1N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_2N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_3N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_4N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_5N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_6N
  */
__STATIC_INLINE uint32_t FL_SENT_GetDataNibblesCount(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_NIBCNT_Msk) >> SENT_CFGR_NIBCNT_Pos);
}

/**
  * @brief    Set CRC mode
  * @rmtoll   CFGR    CRCM    FL_SENT_SetCRCModeSelect
  * @param    SENTx SENT instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_SENT_CRCMODE_RECOMMENDED
  *           @arg @ref FL_SENT_CRCMODE_LEGACY
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_SetCRCModeSelect(SENT_Type* SENTx, uint32_t mode)
{
    MODIFY_REG(SENTx->CFGR, SENT_CFGR_CRCM_Msk, mode);
}

/**
  * @brief    Get CRC mode
  * @rmtoll   CFGR    CRCM    FL_SENT_GetCRCModeSelect
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_CRCMODE_RECOMMENDED
  *           @arg @ref FL_SENT_CRCMODE_LEGACY
  */
__STATIC_INLINE uint32_t FL_SENT_GetCRCModeSelect(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_CRCM_Msk));
}

/**
  * @brief    Enable pause pulse
  * @rmtoll   CFGR    PPEN    FL_SENT_EnablePausePulse
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnablePausePulse(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_PPEN_Msk);
}

/**
  * @brief    Disable pause pulse
  * @rmtoll   CFGR    PPEN    FL_SENT_DisablePausePulse
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisablePausePulse(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_PPEN_Msk);
}

/**
  * @brief    Get pause pulse status
  * @rmtoll   CFGR    PPEN    FL_SENT_IsEnabledPausePulse
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledPausePulse(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_PPEN_Msk) == SENT_CFGR_PPEN_Msk);
}

/**
  * @brief    Enable hardware CRC
  * @rmtoll   CFGR    CRCEN    FL_SENT_EnableCRCHardware
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableCRCHardware(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_CRCEN_Msk);
}

/**
  * @brief    Disable hardware CRC
  * @rmtoll   CFGR    CRCEN    FL_SENT_DisableCRCHardware
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableCRCHardware(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_CRCEN_Msk);
}

/**
  * @brief    Get hardware CRC status
  * @rmtoll   CFGR    CRCEN    FL_SENT_IsEnabledCRCHardware
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledCRCHardware(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_CRCEN_Msk) == SENT_CFGR_CRCEN_Msk);
}

/**
  * @brief    Set idle transmit output pulse
  * @rmtoll   CFGR    TXPOL    FL_SENT_SetIdleTXOutputPulse
  * @param    SENTx SENT instance
  * @param    pulse This parameter can be one of the following values:
  *           @arg @ref FL_SENT_IDLEOUTPUT_HIGH
  *           @arg @ref FL_SENT_IDLEOUTPUT_LOW
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_SetIdleTXOutputPulse(SENT_Type* SENTx, uint32_t pulse)
{
    MODIFY_REG(SENTx->CFGR, SENT_CFGR_TXPOL_Msk, pulse);
}

/**
  * @brief    Get idle transmit output pulse status
  * @rmtoll   CFGR    TXPOL    FL_SENT_GetIdleTXOutputPulse
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_IDLEOUTPUT_HIGH
  *           @arg @ref FL_SENT_IDLEOUTPUT_LOW
  */
__STATIC_INLINE uint32_t FL_SENT_GetIdleTXOutputPulse(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_TXPOL_Msk));
}

/**
  * @brief    Set transmit mode
  * @rmtoll   CFGR    TXM    FL_SENT_SetTXModeSelect
  * @param    SENTx SENT instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_SENT_TXMODE_SOFTWARE
  *           @arg @ref FL_SENT_TXMODE_SERIAL
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_SetTXModeSelect(SENT_Type* SENTx, uint32_t mode)
{
    MODIFY_REG(SENTx->CFGR, SENT_CFGR_TXM_Msk, mode);
}

/**
  * @brief    Get transmit mode
  * @rmtoll   CFGR    TXM    FL_SENT_GetTXModeSelect
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_TXMODE_SOFTWARE
  *           @arg @ref FL_SENT_TXMODE_SERIAL
  */
__STATIC_INLINE uint32_t FL_SENT_GetTXModeSelect(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_TXM_Msk));
}

/**
  * @brief    Set receive mode
  * @rmtoll   CFGR    MOD    FL_SENT_SetModeSelect
  * @param    SENTx SENT instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_SENT_MODE_RX
  *           @arg @ref FL_SENT_MODE_TX
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_SetModeSelect(SENT_Type* SENTx, uint32_t mode)
{
    MODIFY_REG(SENTx->CFGR, SENT_CFGR_MOD_Msk, mode);
}

/**
  * @brief    Get receive mode
  * @rmtoll   CFGR    MOD    FL_SENT_GetModeSelect
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_MODE_RX
  *           @arg @ref FL_SENT_MODE_TX
  */
__STATIC_INLINE uint32_t FL_SENT_GetModeSelect(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_MOD_Msk));
}

/**
  * @brief    Write sent time prescaler
  * @rmtoll   PSR    PSC    FL_SENT_WritePrescaler
  * @param    SENTx SENT instance
  * @param    psc 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WritePrescaler(SENT_Type* SENTx, uint32_t psc)
{
    MODIFY_REG(SENTx->PSR, (0xffffU << 0U), (psc << 0U));
}

/**
  * @brief    Read sent time prescaler
  * @rmtoll   PSR    PSC    FL_SENT_ReadPrescaler
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadPrescaler(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->PSR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Write receive frame length
  * @rmtoll   FTR    LEN    FL_SENT_WriteFrameTimeLength
  * @param    SENTx SENT instance
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteFrameTimeLength(SENT_Type* SENTx, uint32_t length)
{
    MODIFY_REG(SENTx->FTR, (0xfffU << 0U), (length << 0U));
}

/**
  * @brief    Read transmit frame length
  * @rmtoll   FTR    LEN    FL_SENT_ReadFrameTimeLength
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadFrameTimeLength(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->FTR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get nibble transmit and receive status
  * @rmtoll   SR    NIB    FL_SENT_GetTransmitAndReceiveNibbleStatus
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_NIBBLE_STATUS
  *           @arg @ref FL_SENT_NIBBLE_DATA_1ST
  *           @arg @ref FL_SENT_NIBBLE_DATA_2ST
  *           @arg @ref FL_SENT_NIBBLE_DATA_3ST
  *           @arg @ref FL_SENT_NIBBLE_DATA_4ST
  *           @arg @ref FL_SENT_NIBBLE_DATA_5ST
  *           @arg @ref FL_SENT_NIBBLE_DATA_6ST
  *           @arg @ref FL_SENT_NIBBLE_CRC
  */
__STATIC_INLINE uint32_t FL_SENT_GetTransmitAndReceiveNibbleStatus(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_NIB_Msk));
}

/**
  * @brief    Get idle receive status
  * @rmtoll   SR    RXIDLE    FL_SENT_GetRxdleStatus
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_SENT_GetRxdleStatus(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_RXIDLE_Msk) == SENT_SR_RXIDLE_Msk);
}

/**
  * @brief    Get pause transmit and receive status
  * @rmtoll   SR    PAUSE    FL_SENT_GetTransmitAndReceivePauseStatus
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_PAUSESTATUS_TXANDRX
  *           @arg @ref FL_SENT_PAUSESTATUS_NO_TXANDRX
  */
__STATIC_INLINE uint32_t FL_SENT_GetTransmitAndReceivePauseStatus(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_PAUSE_Msk));
}

/**
  * @brief    Get sync status
  * @rmtoll   SR    SYNC    FL_SENT_GetTransmitAndReceiveSyncStatus
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_SYNCSTATUS_TXANDRX
  *           @arg @ref FL_SENT_SYNCSTATUS_NO_TXANDRX
  */
__STATIC_INLINE uint32_t FL_SENT_GetTransmitAndReceiveSyncStatus(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_SYNC_Msk) == SENT_SR_SYNC_Msk);
}

/**
  * @brief    Get successive sync error
  * @rmtoll   SR    SSERR    FL_SENT_IsActiveFlag_SuccessiveSyncErr
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_SuccessiveSyncErr(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_SSERR_Msk) == (SENT_SR_SSERR_Msk));
}

/**
  * @brief    Clear flag :successive sync error
  * @rmtoll   SR    SSERR    FL_SENT_ClearFlag_SuccessiveSyncErr
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_SuccessiveSyncErr(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_SSERR_Msk);
}

/**
  * @brief    Get nibble ticks count error
  * @rmtoll   SR    NBERR    FL_SENT_IsActiveFlag_NibbleTicksCountErr
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_NibbleTicksCountErr(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_NBERR_Msk) == (SENT_SR_NBERR_Msk));
}

/**
  * @brief    Clear flag :nibble ticks count error
  * @rmtoll   SR    NBERR    FL_SENT_ClearFlag_NibbleTicksCountErr
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_NibbleTicksCountErr(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_NBERR_Msk);
}

/**
  * @brief    Get CRC check error
  * @rmtoll   SR    CRCERR    FL_SENT_IsActiveFlag_CRCCheckErr
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_CRCCheckErr(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_CRCERR_Msk) == (SENT_SR_CRCERR_Msk));
}

/**
  * @brief    Clear flag :CRC check error
  * @rmtoll   SR    CRCERR    FL_SENT_ClearFlag_CRCCheckErr
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_CRCCheckErr(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_CRCERR_Msk);
}

/**
  * @brief    Get nibbles count error
  * @rmtoll   SR    NCNTERR    FL_SENT_IsActiveFlag_NibblesCountErr
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_NibblesCountErr(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_NCNTERR_Msk) == (SENT_SR_NCNTERR_Msk));
}

/**
  * @brief    Clear flag : nibbles count error
  * @rmtoll   SR    NCNTERR    FL_SENT_ClearFlag_NibblesCountErr
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_NibblesCountErr(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_NCNTERR_Msk);
}

/**
  * @brief    Get sync pusle width error
  * @rmtoll   SR    SYNCERR    FL_SENT_IsActiveFlag_SyncPusleWidthErr
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_SyncPusleWidthErr(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_SYNCERR_Msk) == (SENT_SR_SYNCERR_Msk));
}

/**
  * @brief    Clear flag :sync pusle width error
  * @rmtoll   SR    SYNCERR    FL_SENT_ClearFlag_SyncPusleWidthErr
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_SyncPusleWidthErr(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_SYNCERR_Msk);
}

/**
  * @brief    Get frame transmit complete flag
  * @rmtoll   SR    FTXF    FL_SENT_IsActiveFlag_FrameTransmitComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_FrameTransmitComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_FTXF_Msk) == (SENT_SR_FTXF_Msk));
}

/**
  * @brief    Clear flag :frame transmit complete flag
  * @rmtoll   SR    FTXF    FL_SENT_ClearFlag_FrameTransmitComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_FrameTransmitComplete(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_FTXF_Msk);
}

/**
  * @brief    Get nibble transmit complete flag
  * @rmtoll   SR    NTXF    FL_SENT_IsActiveFlag_NibblesTransmitComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_NibblesTransmitComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_NTXF_Msk) == (SENT_SR_NTXF_Msk));
}

/**
  * @brief    Clear flag :nibble transmit complete flag
  * @rmtoll   SR    NTXF    FL_SENT_ClearFlag_NibblesTransmitComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_NibblesTransmitComplete(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_NTXF_Msk);
}

/**
  * @brief    Get sync receive complete flag
  * @rmtoll   SR    SYNCF    FL_SENT_IsActiveFlag_SyncReceiveComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_SyncReceiveComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_SYNCF_Msk) == (SENT_SR_SYNCF_Msk));
}

/**
  * @brief    Clear flag :sync receive complete flag
  * @rmtoll   SR    SYNCF    FL_SENT_ClearFlag_SyncReceiveComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_SyncReceiveComplete(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_SYNCF_Msk);
}

/**
  * @brief    Get frame receive complete flag
  * @rmtoll   SR    FRXF    FL_SENT_IsActiveFlag_FrameReceiveComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_FrameReceiveComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_FRXF_Msk) == (SENT_SR_FRXF_Msk));
}

/**
  * @brief    Clear flag :frame receive complete flag
  * @rmtoll   SR    FRXF    FL_SENT_ClearFlag_FrameReceiveComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_FrameReceiveComplete(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_FRXF_Msk);
}

/**
  * @brief    Get nibble receive complete flag
  * @rmtoll   SR    NRXF    FL_SENT_IsActiveFlag_NibblesReceiveComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_NibblesReceiveComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_NRXF_Msk) == (SENT_SR_NRXF_Msk));
}

/**
  * @brief    Clear flag :nibble receive complete flag
  * @rmtoll   SR    NRXF    FL_SENT_ClearFlag_NibblesReceiveComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_NibblesReceiveComplete(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_NRXF_Msk);
}

/**
  * @brief    Write nibble data CRC
  * @rmtoll   DR    CRC    FL_SENT_WriteNibbleData_CRC
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_CRC(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 28U), (nibble << 28U));
}

/**
  * @brief    Read nibble data CRC
  * @rmtoll   DR    CRC    FL_SENT_ReadNibbleData_CRC
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_CRC(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 28U)) >> 28U);
}

/**
  * @brief    Write nibble data DATA6
  * @rmtoll   DR    DATA6    FL_SENT_WriteNibbleData_DATA6
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_DATA6(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 24U), (nibble << 24U));
}

/**
  * @brief    Read nibble data DATA6
  * @rmtoll   DR    DATA6    FL_SENT_ReadNibbleData_DATA6
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_DATA6(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 24U)) >> 24U);
}

/**
  * @brief    Write nibble data DATA5
  * @rmtoll   DR    DATA5    FL_SENT_WriteNibbleData_DATA5
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_DATA5(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 20U), (nibble << 20U));
}

/**
  * @brief    Read nibble data DATA5
  * @rmtoll   DR    DATA5    FL_SENT_ReadNibbleData_DATA5
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_DATA5(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 20U)) >> 20U);
}

/**
  * @brief    Write nibble data DATA4
  * @rmtoll   DR    DATA4    FL_SENT_WriteNibbleData_DATA4
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_DATA4(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 16U), (nibble << 16U));
}

/**
  * @brief    Read nibble data DATA4
  * @rmtoll   DR    DATA4    FL_SENT_ReadNibbleData_DATA4
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_DATA4(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 16U)) >> 16U);
}

/**
  * @brief    Write nibble data DATA3
  * @rmtoll   DR    DATA3    FL_SENT_WriteNibbleData_DATA3
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_DATA3(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 12U), (nibble << 12U));
}

/**
  * @brief    Read nibble data DATA3
  * @rmtoll   DR    DATA3    FL_SENT_ReadNibbleData_DATA3
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_DATA3(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 12U)) >> 12U);
}

/**
  * @brief    Write nibble data DATA2
  * @rmtoll   DR    DATA2    FL_SENT_WriteNibbleData_DATA2
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_DATA2(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 8U), (nibble << 8U));
}

/**
  * @brief    Read nibble data DATA2
  * @rmtoll   DR    DATA2    FL_SENT_ReadNibbleData_DATA2
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_DATA2(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 8U)) >> 8U);
}

/**
  * @brief    Write nibble data DATA1
  * @rmtoll   DR    DATA1    FL_SENT_WriteNibbleData_DATA1
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_DATA1(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 4U), (nibble << 4U));
}

/**
  * @brief    Read nibble data DATA1
  * @rmtoll   DR    DATA1    FL_SENT_ReadNibbleData_DATA1
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_DATA1(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 4U)) >> 4U);
}

/**
  * @brief    Write nibble data STATUS
  * @rmtoll   DR    STATUS    FL_SENT_WriteNibbleData_STATUS
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_STATUS(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 0U), (nibble << 0U));
}

/**
  * @brief    Read nibble data STATUS
  * @rmtoll   DR    STATUS    FL_SENT_ReadNibbleData_STATUS
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_STATUS(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 0U)) >> 0U);
}

/**
  * @brief    Write DR Register data
  * @rmtoll   DR    DRREG    FL_SENT_WriteDataRegister
  * @param    SENTx SENT instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteDataRegister(SENT_Type* SENTx, uint32_t data)
{
    MODIFY_REG(SENTx->DR, (0xffffffffU << 0U), (data << 0U));
}

/**
  * @brief    Read DR Register data
  * @rmtoll   DR    DRREG    FL_SENT_ReadDataRegister
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadDataRegister(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Write sync max length
  * @rmtoll   SYNC    SYNCMAX    FL_SENT_WriteSyncMaxLength
  * @param    SENTx SENT instance
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteSyncMaxLength(SENT_Type* SENTx, uint32_t length)
{
    MODIFY_REG(SENTx->SYNC, (0xfffU << 16U), (length << 16U));
}

/**
  * @brief    Read sync max length
  * @rmtoll   SYNC    SYNCMAX    FL_SENT_ReadSyncMaxLength
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadSyncMaxLength(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SYNC, (0xfffU << 16U)) >> 16U);
}

/**
  * @brief    Write sync min length
  * @rmtoll   SYNC    SYNCMIN    FL_SENT_WriteSyncMinLength
  * @param    SENTx SENT instance
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteSyncMinLength(SENT_Type* SENTx, uint32_t length)
{
    MODIFY_REG(SENTx->SYNC, (0xfffU << 0U), (length << 0U));
}

/**
  * @brief    Read sync min length
  * @rmtoll   SYNC    SYNCMIN    FL_SENT_ReadSyncMinLength
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadSyncMinLength(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SYNC, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Read sync base tick time
  * @rmtoll   RCAL    BASECNT    FL_SENT_ReadSyncBaseTickTime
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadSyncBaseTickTime(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->RCAL, (0x3fU << 16U)) >> 16U);
}

/**
  * @brief    Read sync calibration pulse
  * @rmtoll   RCAL    RCAL    FL_SENT_ReadSyncCalibrationPulse
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadSyncCalibrationPulse(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->RCAL, (0xfffU << 0U)) >> 0U);
}

/**
  * @}
  */

/** @defgroup SENT_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_SENT_DeInit(SENT_Type *SENTx);
FL_ErrorStatus FL_SENT_Init(SENT_Type *SENTx, FL_SENT_InitTypeDef *initStruct);
void FL_SENT_StructInit(FL_SENT_InitTypeDef *initStruct);
uint32_t FL_SENT_RxSyncCalibration(SENT_Type *SENTx);
/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_SENT_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2024-01-11*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
