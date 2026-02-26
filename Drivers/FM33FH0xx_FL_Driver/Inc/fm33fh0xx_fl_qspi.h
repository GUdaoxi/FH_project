/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_qspi.h
  * @author  FMSH Application Team
  * @brief   Head file of QSPI FL Module
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
#ifndef __FM33FH0XX_FL_QSPI_H
#define __FM33FH0XX_FL_QSPI_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl_def.h"
/** @addtogroup FM33FH0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup QSPI_FL_ES_INIT QSPI Exported Init structures
  * @{
  */

/**
  * @brief FL QSPI Init Sturcture definition
  */
typedef struct
{
    /* 时钟预分频系数 */
    uint32_t ClockPrescaler;    
    /* FIFO水位 */                          
    uint32_t FifoThreshold;     
    /* 延迟采样功能 */                          
    uint32_t SampleShifting;    
    /* nCS最小高电平时间 */                                                            
    uint32_t ChipSelectHighTime;
    /* Clock Mode */                                                        
    uint32_t ClockMode;

}QSPI_InitTypeDef;

typedef struct
{
    /* instruction phase. */
    uint32_t Instruction;
    uint32_t InstructionMode;
 
    /* addr phase. */
    uint32_t Address;
    uint32_t AddressSize;
    uint32_t AddressMode;
 
    /* alt phase. */
    uint32_t AlternateByte;
    uint32_t AlternateByteSize;
    uint32_t AlternateByteMode;
 
    /* dummy phase. */
    uint32_t DummyCycles;
    
    /* data phase. */
    uint32_t DataMode;
    uint32_t DataLen;

}QSPI_CmdTypeDef;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup QSPI_FL_Exported_Constants QSPI Exported Constants
  * @{
  */

#define    QSPI_CR_PRESCALER_Pos                                  (24U)
#define    QSPI_CR_PRESCALER_Msk                                  (0xffU << QSPI_CR_PRESCALER_Pos)
#define    QSPI_CR_PRESCALER                                      QSPI_CR_PRESCALER_Msk

#define    QSPI_CR_PMM_Pos                                        (23U)
#define    QSPI_CR_PMM_Msk                                        (0x1U << QSPI_CR_PMM_Pos)
#define    QSPI_CR_PMM                                            QSPI_CR_PMM_Msk

#define    QSPI_CR_TOIE_Pos                                       (20U)
#define    QSPI_CR_TOIE_Msk                                       (0x1U << QSPI_CR_TOIE_Pos)
#define    QSPI_CR_TOIE                                           QSPI_CR_TOIE_Msk

#define    QSPI_CR_SMIE_Pos                                       (19U)
#define    QSPI_CR_SMIE_Msk                                       (0x1U << QSPI_CR_SMIE_Pos)
#define    QSPI_CR_SMIE                                           QSPI_CR_SMIE_Msk

#define    QSPI_CR_FTIE_Pos                                       (18U)
#define    QSPI_CR_FTIE_Msk                                       (0x1U << QSPI_CR_FTIE_Pos)
#define    QSPI_CR_FTIE                                           QSPI_CR_FTIE_Msk

#define    QSPI_CR_TCIE_Pos                                       (17U)
#define    QSPI_CR_TCIE_Msk                                       (0x1U << QSPI_CR_TCIE_Pos)
#define    QSPI_CR_TCIE                                           QSPI_CR_TCIE_Msk

#define    QSPI_CR_TEIE_Pos                                       (16U)
#define    QSPI_CR_TEIE_Msk                                       (0x1U << QSPI_CR_TEIE_Pos)
#define    QSPI_CR_TEIE                                           QSPI_CR_TEIE_Msk

#define    QSPI_CR_FIFOTHR_Pos                                    (8U)
#define    QSPI_CR_FIFOTHR_Msk                                    (0xfU << QSPI_CR_FIFOTHR_Pos)
#define    QSPI_CR_FIFOTHR                                        QSPI_CR_FIFOTHR_Msk

#define    QSPI_CR_SSHFT_Pos                                      (4U)
#define    QSPI_CR_SSHFT_Msk                                      (0x1U << QSPI_CR_SSHFT_Pos)
#define    QSPI_CR_SSHFT                                          QSPI_CR_SSHFT_Msk

#define    QSPI_CR_TCEN_Pos                                       (3U)
#define    QSPI_CR_TCEN_Msk                                       (0x1U << QSPI_CR_TCEN_Pos)
#define    QSPI_CR_TCEN                                           QSPI_CR_TCEN_Msk

#define    QSPI_CR_DMAEN_Pos                                      (2U)
#define    QSPI_CR_DMAEN_Msk                                      (0x1U << QSPI_CR_DMAEN_Pos)
#define    QSPI_CR_DMAEN                                          QSPI_CR_DMAEN_Msk

#define    QSPI_CR_ABORT_Pos                                      (1U)
#define    QSPI_CR_ABORT_Msk                                      (0x1U << QSPI_CR_ABORT_Pos)
#define    QSPI_CR_ABORT                                          QSPI_CR_ABORT_Msk

#define    QSPI_CR_EN_Pos                                         (0U)
#define    QSPI_CR_EN_Msk                                         (0x1U << QSPI_CR_EN_Pos)
#define    QSPI_CR_EN                                             QSPI_CR_EN_Msk

#define    QSPI_CFG_CSHT_Pos                                      (8U)
#define    QSPI_CFG_CSHT_Msk                                      (0x7U << QSPI_CFG_CSHT_Pos)
#define    QSPI_CFG_CSHT                                          QSPI_CFG_CSHT_Msk

#define    QSPI_CFG_CKMODE_Pos                                    (0U)
#define    QSPI_CFG_CKMODE_Msk                                    (0x1U << QSPI_CFG_CKMODE_Pos)
#define    QSPI_CFG_CKMODE                                        QSPI_CFG_CKMODE_Msk

#define    QSPI_SR_FIFOLVL_Pos                                    (8U)
#define    QSPI_SR_FIFOLVL_Msk                                    (0x1fU << QSPI_SR_FIFOLVL_Pos)
#define    QSPI_SR_FIFOLVL                                        QSPI_SR_FIFOLVL_Msk

#define    QSPI_SR_BUSY_Pos                                       (5U)
#define    QSPI_SR_BUSY_Msk                                       (0x1U << QSPI_SR_BUSY_Pos)
#define    QSPI_SR_BUSY                                           QSPI_SR_BUSY_Msk

#define    QSPI_SR_TOF_Pos                                        (4U)
#define    QSPI_SR_TOF_Msk                                        (0x1U << QSPI_SR_TOF_Pos)
#define    QSPI_SR_TOF                                            QSPI_SR_TOF_Msk

#define    QSPI_SR_SMF_Pos                                        (3U)
#define    QSPI_SR_SMF_Msk                                        (0x1U << QSPI_SR_SMF_Pos)
#define    QSPI_SR_SMF                                            QSPI_SR_SMF_Msk

#define    QSPI_SR_FTF_Pos                                        (2U)
#define    QSPI_SR_FTF_Msk                                        (0x1U << QSPI_SR_FTF_Pos)
#define    QSPI_SR_FTF                                            QSPI_SR_FTF_Msk

#define    QSPI_SR_TCF_Pos                                        (1U)
#define    QSPI_SR_TCF_Msk                                        (0x1U << QSPI_SR_TCF_Pos)
#define    QSPI_SR_TCF                                            QSPI_SR_TCF_Msk

#define    QSPI_DATALEN_DATALEN_Pos                               (0U)
#define    QSPI_DATALEN_DATALEN_Msk                               (0xffffffffU << QSPI_DATALEN_DATALEN_Pos)
#define    QSPI_DATALEN_DATALEN                                   QSPI_DATALEN_DATALEN_Msk

#define    QSPI_CCR_CRM_Pos                                       (28U)
#define    QSPI_CCR_CRM_Msk                                       (0x1U << QSPI_CCR_CRM_Pos)
#define    QSPI_CCR_CRM                                           QSPI_CCR_CRM_Msk

#define    QSPI_CCR_OPMODE_Pos                                    (26U)
#define    QSPI_CCR_OPMODE_Msk                                    (0x3U << QSPI_CCR_OPMODE_Pos)
#define    QSPI_CCR_OPMODE                                        QSPI_CCR_OPMODE_Msk

#define    QSPI_CCR_DMODE_Pos                                     (24U)
#define    QSPI_CCR_DMODE_Msk                                     (0x3U << QSPI_CCR_DMODE_Pos)
#define    QSPI_CCR_DMODE                                         QSPI_CCR_DMODE_Msk

#define    QSPI_CCR_DUMCYC_Pos                                    (18U)
#define    QSPI_CCR_DUMCYC_Msk                                    (0x1fU << QSPI_CCR_DUMCYC_Pos)
#define    QSPI_CCR_DUMCYC                                        QSPI_CCR_DUMCYC_Msk

#define    QSPI_CCR_ABSIZE_Pos                                    (16U)
#define    QSPI_CCR_ABSIZE_Msk                                    (0x3U << QSPI_CCR_ABSIZE_Pos)
#define    QSPI_CCR_ABSIZE                                        QSPI_CCR_ABSIZE_Msk

#define    QSPI_CCR_ABMODE_Pos                                    (14U)
#define    QSPI_CCR_ABMODE_Msk                                    (0x3U << QSPI_CCR_ABMODE_Pos)
#define    QSPI_CCR_ABMODE                                        QSPI_CCR_ABMODE_Msk

#define    QSPI_CCR_ADSIZE_Pos                                    (12U)
#define    QSPI_CCR_ADSIZE_Msk                                    (0x3U << QSPI_CCR_ADSIZE_Pos)
#define    QSPI_CCR_ADSIZE                                        QSPI_CCR_ADSIZE_Msk

#define    QSPI_CCR_ADMODE_Pos                                    (10U)
#define    QSPI_CCR_ADMODE_Msk                                    (0x3U << QSPI_CCR_ADMODE_Pos)
#define    QSPI_CCR_ADMODE                                        QSPI_CCR_ADMODE_Msk

#define    QSPI_CCR_IMODE_Pos                                     (8U)
#define    QSPI_CCR_IMODE_Msk                                     (0x3U << QSPI_CCR_IMODE_Pos)
#define    QSPI_CCR_IMODE                                         QSPI_CCR_IMODE_Msk

#define    QSPI_CCR_INSTRUCTION_Pos                               (0U)
#define    QSPI_CCR_INSTRUCTION_Msk                               (0xffU << QSPI_CCR_INSTRUCTION_Pos)
#define    QSPI_CCR_INSTRUCTION                                   QSPI_CCR_INSTRUCTION_Msk

#define    QSPI_ADDR_ADDR_Pos                                     (0U)
#define    QSPI_ADDR_ADDR_Msk                                     (0xffffffffU << QSPI_ADDR_ADDR_Pos)
#define    QSPI_ADDR_ADDR                                         QSPI_ADDR_ADDR_Msk

#define    QSPI_ABR_ABR_Pos                                       (0U)
#define    QSPI_ABR_ABR_Msk                                       (0xffffffffU << QSPI_ABR_ABR_Pos)
#define    QSPI_ABR_ABR                                           QSPI_ABR_ABR_Msk

#define    QSPI_DR_DATA_Pos                                       (0U)
#define    QSPI_DR_DATA_Msk                                       (0xffffffffU << QSPI_DR_DATA_Pos)
#define    QSPI_DR_DATA                                            QSPI_DR_DATA_Msk

#define    QSPI_SMSK_SMSK_Pos                                     (0U)
#define    QSPI_SMSK_SMSK_Msk                                     (0xffffffffU << QSPI_SMSK_SMSK_Pos)
#define    QSPI_SMSK_SMSK                                         QSPI_SMSK_SMSK_Msk

#define    QSPI_SMAT_SMAT_Pos                                     (0U)
#define    QSPI_SMAT_SMAT_Msk                                     (0xffffffffU << QSPI_SMAT_SMAT_Pos)
#define    QSPI_SMAT_SMAT                                         QSPI_SMAT_SMAT_Msk

#define    QSPI_PITV_PITV_Pos                                     (0U)
#define    QSPI_PITV_PITV_Msk                                     (0xffffU << QSPI_PITV_PITV_Pos)
#define    QSPI_PITV_PITV                                         QSPI_PITV_PITV_Msk

#define    QSPI_TOR_TO_Pos                                        (0U)
#define    QSPI_TOR_TO_Msk                                        (0xffffU << QSPI_TOR_TO_Pos)
#define    QSPI_TOR_TO                                            QSPI_TOR_TO_Msk


#define    FL_QSPI_MODE_AND                                       (0x0U << QSPI_CR_PMM_Pos)
#define    FL_QSPI_MODE_OR                                        (0x1U << QSPI_CR_PMM_Pos)


#define    FL_QSPI_FIFOTHR_1                                      (0x0U << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_2                                      (0x1U << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_3                                      (0x2U << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_4                                      (0x3U << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_5                                      (0x4U << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_6                                      (0x5U << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_7                                      (0x6U << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_8                                      (0x7U << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_9                                      (0x8U << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_10                                     (0x9U << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_11                                     (0xaU << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_12                                     (0xbU << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_13                                     (0xcU << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_14                                     (0xdU << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_15                                     (0xeU << QSPI_CR_FIFOTHR_Pos)
#define    FL_QSPI_FIFOTHR_16                                     (0xfU << QSPI_CR_FIFOTHR_Pos)


#define    FL_QSPI_CYCLE_1                                        (0x0U << QSPI_CFG_CSHT_Pos)
#define    FL_QSPI_CYCLE_2                                        (0x1U << QSPI_CFG_CSHT_Pos)
#define    FL_QSPI_CYCLE_3                                        (0x2U << QSPI_CFG_CSHT_Pos)
#define    FL_QSPI_CYCLE_4                                        (0x3U << QSPI_CFG_CSHT_Pos)
#define    FL_QSPI_CYCLE_5                                        (0x4U << QSPI_CFG_CSHT_Pos)
#define    FL_QSPI_CYCLE_6                                        (0x5U << QSPI_CFG_CSHT_Pos)
#define    FL_QSPI_CYCLE_7                                        (0x6U << QSPI_CFG_CSHT_Pos)
#define    FL_QSPI_CYCLE_8                                        (0x7U << QSPI_CFG_CSHT_Pos)


#define    FL_QSPI_CLKMODE_0                                      (0x0U << QSPI_CFG_CKMODE_Pos)
#define    FL_QSPI_CLKMODE_3                                      (0x1U << QSPI_CFG_CKMODE_Pos)


#define    FL_QSPI_SEND_COMMAND_EVERYTIME                         (0x0U << QSPI_CCR_CRM_Pos)
#define    FL_QSPI_SEND_COMMAND_ONCE                              (0x1U << QSPI_CCR_CRM_Pos)


#define    FL_QSPI_OPERATION_MODE_WRITE                           (0x0U << QSPI_CCR_OPMODE_Pos)
#define    FL_QSPI_OPERATION_MODE_READ                            (0x1U << QSPI_CCR_OPMODE_Pos)
#define    FL_QSPI_OPERATION_MODE_QUERY                           (0x2U << QSPI_CCR_OPMODE_Pos)
#define    FL_QSPI_OPERATION_MODE_MAP                             (0x3U << QSPI_CCR_OPMODE_Pos)


#define    FL_QSPI_DATA_MODE_NONE                                 (0x0U << QSPI_CCR_DMODE_Pos)
#define    FL_QSPI_DATA_MODE_SINGLE                               (0x1U << QSPI_CCR_DMODE_Pos)
#define    FL_QSPI_DATA_MODE_DOUBLE                               (0x2U << QSPI_CCR_DMODE_Pos)
#define    FL_QSPI_DATA_MODE_FOUR                                 (0x3U << QSPI_CCR_DMODE_Pos)


#define    FL_QSPI_AB_SIZE_8bits                                  (0x0U << QSPI_CCR_ABSIZE_Pos)
#define    FL_QSPI_AB_SIZE_16bits                                 (0x1U << QSPI_CCR_ABSIZE_Pos)
#define    FL_QSPI_AB_SIZE_24bits                                 (0x2U << QSPI_CCR_ABSIZE_Pos)
#define    FL_QSPI_AB_SIZE_32bits                                 (0x3U << QSPI_CCR_ABSIZE_Pos)


#define    FL_QSPI_AB_MODE_NONE                                   (0x0U << QSPI_CCR_ABMODE_Pos)
#define    FL_QSPI_AB_MODE_SINGLE                                 (0x1U << QSPI_CCR_ABMODE_Pos)
#define    FL_QSPI_AB_MODE_DOUBLE                                 (0x2U << QSPI_CCR_ABMODE_Pos)
#define    FL_QSPI_AB_MODE_FOUR                                   (0x3U << QSPI_CCR_ABMODE_Pos)


#define    FL_QSPI_AD_SIZE_8bits                                  (0x0U << QSPI_CCR_ADSIZE_Pos)
#define    FL_QSPI_AD_SIZE_16bits                                 (0x1U << QSPI_CCR_ADSIZE_Pos)
#define    FL_QSPI_AD_SIZE_24bits                                 (0x2U << QSPI_CCR_ADSIZE_Pos)
#define    FL_QSPI_AD_SIZE_32bits                                 (0x3U << QSPI_CCR_ADSIZE_Pos)


#define    FL_QSPI_AD_MODE_NONE                                   (0x0U << QSPI_CCR_ADMODE_Pos)
#define    FL_QSPI_AD_MODE_SINGLE                                 (0x1U << QSPI_CCR_ADMODE_Pos)
#define    FL_QSPI_AD_MODE_DOUBLE                                 (0x2U << QSPI_CCR_ADMODE_Pos)
#define    FL_QSPI_AD_MODE_FOUR                                   (0x3U << QSPI_CCR_ADMODE_Pos)


#define    FL_QSPI_IMODE_NONE                                     (0x0U << QSPI_CCR_IMODE_Pos)
#define    FL_QSPI_IMODE_SINGLE                                   (0x1U << QSPI_CCR_IMODE_Pos)
#define    FL_QSPI_IMODE_DOUBLE                                   (0x2U << QSPI_CCR_IMODE_Pos)
#define    FL_QSPI_IMODE_FOUR                                     (0x3U << QSPI_CCR_IMODE_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup QSPI_FL_Exported_Functions QSPI Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   CR    PRESCALER    FL_QSPI_WriteClockPrescaler
  * @param    QSPIx QSPI instance
  * @param    div 
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_WriteClockPrescaler(QSPI_Type* QSPIx, uint32_t div)
{
    MODIFY_REG(QSPIx->CR, (0xffU << 24U), (div << 24U));
}

/**
  * @brief    
  * @rmtoll   CR    PRESCALER    FL_QSPI_ReadClockPrescaler
  * @param    QSPIx QSPI instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_QSPI_ReadClockPrescaler(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CR, (0xffU << 24U)) >> 24U);
}

/**
  * @brief    
  * @rmtoll   CR    PMM    FL_QSPI_SetPMMmode
  * @param    QSPIx QSPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_QSPI_MODE_AND
  *           @arg @ref FL_QSPI_MODE_OR
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_SetPMMmode(QSPI_Type* QSPIx, uint32_t mode)
{
    MODIFY_REG(QSPIx->CR, QSPI_CR_PMM_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CR    PMM    FL_QSPI_GetPMMmode
  * @param    QSPIx QSPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_QSPI_MODE_AND
  *           @arg @ref FL_QSPI_MODE_OR
  */
__STATIC_INLINE uint32_t FL_QSPI_GetPMMmode(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CR, QSPI_CR_PMM_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    TOIE    FL_QSPI_EnableIT_Timeout
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_EnableIT_Timeout(QSPI_Type* QSPIx)
{
    SET_BIT(QSPIx->CR, QSPI_CR_TOIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    TOIE    FL_QSPI_IsEnabledIT_Timeout
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_QSPI_IsEnabledIT_Timeout(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CR, QSPI_CR_TOIE_Msk) == QSPI_CR_TOIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    TOIE    FL_QSPI_DisableIT_Timeout
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_DisableIT_Timeout(QSPI_Type* QSPIx)
{
    CLEAR_BIT(QSPIx->CR, QSPI_CR_TOIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    SMIE    FL_QSPI_EnableIT_StateMatch
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_EnableIT_StateMatch(QSPI_Type* QSPIx)
{
    SET_BIT(QSPIx->CR, QSPI_CR_SMIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    SMIE    FL_QSPI_IsEnabledIT_StateMatch
  * @param    QSPIx QSPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_QSPI_IsEnabledIT_StateMatch(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CR, QSPI_CR_SMIE_Msk) == QSPI_CR_SMIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    SMIE    FL_QSPI_DisableIT_StateMatch
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_DisableIT_StateMatch(QSPI_Type* QSPIx)
{
    CLEAR_BIT(QSPIx->CR, QSPI_CR_SMIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    FTIE    FL_QSPI_EnableIT_FIFOLevel
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_EnableIT_FIFOLevel(QSPI_Type* QSPIx)
{
    SET_BIT(QSPIx->CR, QSPI_CR_FTIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    FTIE    FL_QSPI_IsEnabledIT_FIFOLevel
  * @param    QSPIx QSPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_QSPI_IsEnabledIT_FIFOLevel(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CR, QSPI_CR_FTIE_Msk) == QSPI_CR_FTIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    FTIE    FL_QSPI_DisableIT_FIFOLevel
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_DisableIT_FIFOLevel(QSPI_Type* QSPIx)
{
    CLEAR_BIT(QSPIx->CR, QSPI_CR_FTIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    TCIE    FL_QSPI_EnableIT_TransferComplete
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_EnableIT_TransferComplete(QSPI_Type* QSPIx)
{
    SET_BIT(QSPIx->CR, QSPI_CR_TCIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    TCIE    FL_QSPI_IsEnabledIT_TransferComplete
  * @param    QSPIx QSPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_QSPI_IsEnabledIT_TransferComplete(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CR, QSPI_CR_TCIE_Msk) == QSPI_CR_TCIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    TCIE    FL_QSPI_DisableIT_TransferComplete
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_DisableIT_TransferComplete(QSPI_Type* QSPIx)
{
    CLEAR_BIT(QSPIx->CR, QSPI_CR_TCIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    TEIE    FL_QSPI_EnableIT_TransferError
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_EnableIT_TransferError(QSPI_Type* QSPIx)
{
    SET_BIT(QSPIx->CR, QSPI_CR_TEIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    TEIE    FL_QSPI_IsEnabledIT_TransferError
  * @param    QSPIx QSPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_QSPI_IsEnabledIT_TransferError(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CR, QSPI_CR_TEIE_Msk) == QSPI_CR_TEIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    TEIE    FL_QSPI_DisableIT_TransferError
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_DisableIT_TransferError(QSPI_Type* QSPIx)
{
    CLEAR_BIT(QSPIx->CR, QSPI_CR_TEIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    FIFOTHR    FL_QSPI_SetFIFOLevel
  * @param    QSPIx QSPI instance
  * @param    level This parameter can be one of the following values:
  *           @arg @ref FL_QSPI_FIFOTHR_1
  *           @arg @ref FL_QSPI_FIFOTHR_2
  *           @arg @ref FL_QSPI_FIFOTHR_3
  *           @arg @ref FL_QSPI_FIFOTHR_4
  *           @arg @ref FL_QSPI_FIFOTHR_5
  *           @arg @ref FL_QSPI_FIFOTHR_6
  *           @arg @ref FL_QSPI_FIFOTHR_7
  *           @arg @ref FL_QSPI_FIFOTHR_8
  *           @arg @ref FL_QSPI_FIFOTHR_9
  *           @arg @ref FL_QSPI_FIFOTHR_10
  *           @arg @ref FL_QSPI_FIFOTHR_11
  *           @arg @ref FL_QSPI_FIFOTHR_12
  *           @arg @ref FL_QSPI_FIFOTHR_13
  *           @arg @ref FL_QSPI_FIFOTHR_14
  *           @arg @ref FL_QSPI_FIFOTHR_15
  *           @arg @ref FL_QSPI_FIFOTHR_16
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_SetFIFOLevel(QSPI_Type* QSPIx, uint32_t level)
{
    MODIFY_REG(QSPIx->CR, QSPI_CR_FIFOTHR_Msk, level);
}

/**
  * @brief    
  * @rmtoll   CR    FIFPTHR    FL_QSPI_GetFIFOLevel
  * @param    QSPIx QSPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_QSPI_FIFOTHR_1
  *           @arg @ref FL_QSPI_FIFOTHR_2
  *           @arg @ref FL_QSPI_FIFOTHR_3
  *           @arg @ref FL_QSPI_FIFOTHR_4
  *           @arg @ref FL_QSPI_FIFOTHR_5
  *           @arg @ref FL_QSPI_FIFOTHR_6
  *           @arg @ref FL_QSPI_FIFOTHR_7
  *           @arg @ref FL_QSPI_FIFOTHR_8
  *           @arg @ref FL_QSPI_FIFOTHR_9
  *           @arg @ref FL_QSPI_FIFOTHR_10
  *           @arg @ref FL_QSPI_FIFOTHR_11
  *           @arg @ref FL_QSPI_FIFOTHR_12
  *           @arg @ref FL_QSPI_FIFOTHR_13
  *           @arg @ref FL_QSPI_FIFOTHR_14
  *           @arg @ref FL_QSPI_FIFOTHR_15
  *           @arg @ref FL_QSPI_FIFOTHR_16
  */
__STATIC_INLINE uint32_t FL_QSPI_GetFIFOLevel(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CR, QSPI_CR_FIFOTHR_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    SSHFT    FL_QSPI_EnableDelayedSampling
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_EnableDelayedSampling(QSPI_Type* QSPIx)
{
    SET_BIT(QSPIx->CR, QSPI_CR_SSHFT_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    SSHFT    FL_QSPI_IsEnabledDelayedSampling
  * @param    QSPIx QSPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_QSPI_IsEnabledDelayedSampling(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CR, QSPI_CR_SSHFT_Msk) == QSPI_CR_SSHFT_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    SSHFT    FL_QSPI_DisableDelayedSampling
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_DisableDelayedSampling(QSPI_Type* QSPIx)
{
    CLEAR_BIT(QSPIx->CR, QSPI_CR_SSHFT_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    TCEN    FL_QSPI_EnableTimeout
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_EnableTimeout(QSPI_Type* QSPIx)
{
    SET_BIT(QSPIx->CR, QSPI_CR_TCEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    TCEN    FL_QSPI_IsEnabledTimeout
  * @param    QSPIx QSPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_QSPI_IsEnabledTimeout(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CR, QSPI_CR_TCEN_Msk) == QSPI_CR_TCEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    TCEN    FL_QSPI_DisableTimeout
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_DisableTimeout(QSPI_Type* QSPIx)
{
    CLEAR_BIT(QSPIx->CR, QSPI_CR_TCEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    DMAEN    FL_QSPI_EnableDMAReq_DMA
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_EnableDMAReq_DMA(QSPI_Type* QSPIx)
{
    SET_BIT(QSPIx->CR, QSPI_CR_DMAEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    DMAEN    FL_QSPI_IsEnabledDMAReq_DMA
  * @param    QSPIx QSPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_QSPI_IsEnabledDMAReq_DMA(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CR, QSPI_CR_DMAEN_Msk) == QSPI_CR_DMAEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    DMAEN    FL_QSPI_DisableDMAReq_DMA
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_DisableDMAReq_DMA(QSPI_Type* QSPIx)
{
    CLEAR_BIT(QSPIx->CR, QSPI_CR_DMAEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    ABORT    FL_QSPI_EnableABORT
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_EnableABORT(QSPI_Type* QSPIx)
{
    SET_BIT(QSPIx->CR, QSPI_CR_ABORT_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    EN    FL_QSPI_Enable
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_Enable(QSPI_Type* QSPIx)
{
    SET_BIT(QSPIx->CR, QSPI_CR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    EN    FL_QSPI_IsEnabled
  * @param    QSPIx QSPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_QSPI_IsEnabled(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CR, QSPI_CR_EN_Msk) == QSPI_CR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    EN    FL_QSPI_Disable
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_Disable(QSPI_Type* QSPIx)
{
    CLEAR_BIT(QSPIx->CR, QSPI_CR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFG    CSHT    FL_QSPI_SetCSHoldTime
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_SetCSHoldTime(QSPI_Type* QSPIx, uint32_t cycle)
{
    MODIFY_REG(QSPIx->CFGR, QSPI_CFG_CSHT_Msk, cycle);
}

/**
  * @brief    
  * @rmtoll   CFG    CSHT    FL_QSPI_GetCSHoldTime
  * @param    QSPIx QSPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_QSPI_CYCLE_1
  *           @arg @ref FL_QSPI_CYCLE_2
  *           @arg @ref FL_QSPI_CYCLE_3
  *           @arg @ref FL_QSPI_CYCLE_4
  *           @arg @ref FL_QSPI_CYCLE_5
  *           @arg @ref FL_QSPI_CYCLE_6
  *           @arg @ref FL_QSPI_CYCLE_7
  *           @arg @ref FL_QSPI_CYCLE_8
  */
__STATIC_INLINE uint32_t FL_QSPI_GetCSHoldTime(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CFGR, QSPI_CFG_CSHT_Msk));
}

/**
  * @brief    
  * @rmtoll   CFG    CKMODE    FL_QSPI_SetClockMode
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_SetClockMode(QSPI_Type* QSPIx, uint32_t mode)
{
    MODIFY_REG(QSPIx->CFGR, QSPI_CFG_CKMODE_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CFG    CKMODE    FL_QSPI_GetClockMode
  * @param    QSPIx QSPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_QSPI_CLKMODE_0
  *           @arg @ref FL_QSPI_CLKMODE_3
  */
__STATIC_INLINE uint32_t FL_QSPI_GetClockMode(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CFGR, QSPI_CFG_CKMODE_Msk));
}

/**
  * @brief    
  * @rmtoll   SR    FIFOLVL    FL_QSPI_ReadFIFOLevel
  * @param    QSPIx QSPI instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_QSPI_ReadFIFOLevel(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->SR, (0x1fU << 8U)) >> 8U);
}

/**
  * @brief    
  * @rmtoll   SR    BUSY    FL_QSPI_IsActiveFlag_Busy
  * @param    QSPIx QSPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_QSPI_IsActiveFlag_Busy(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->SR, QSPI_SR_BUSY_Msk) == (QSPI_SR_BUSY_Msk));
}

/**
  * @brief    
  * @rmtoll   SR    TOF    FL_QSPI_IsActiveFlag_Overtime
  * @param    QSPIx QSPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_QSPI_IsActiveFlag_Overtime(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->SR, QSPI_SR_TOF_Msk) == (QSPI_SR_TOF_Msk));
}

/**
  * @brief    
  * @rmtoll   SR    TOF    FL_QSPI_ClearFlag_Overtime
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_ClearFlag_Overtime(QSPI_Type* QSPIx)
{
    WRITE_REG(QSPIx->SR, QSPI_SR_TOF_Msk);
}

/**
  * @brief    
  * @rmtoll   SR    SMF    FL_QSPI_IsActiveFlag_StatusRegMatchSuccess
  * @param    QSPIx QSPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_QSPI_IsActiveFlag_StatusRegMatchSuccess(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->SR, QSPI_SR_SMF_Msk) == (QSPI_SR_SMF_Msk));
}

/**
  * @brief    
  * @rmtoll   SR    SMF    FL_QSPI_ClearFlag_StatusRegMatchSuccess
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_ClearFlag_StatusRegMatchSuccess(QSPI_Type* QSPIx)
{
    WRITE_REG(QSPIx->SR, QSPI_SR_SMF_Msk);
}

/**
  * @brief    
  * @rmtoll   SR    FTF    FL_QSPI_IsActiveFlag_FIFOthreshold
  * @param    QSPIx QSPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_QSPI_IsActiveFlag_FIFOthreshold(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->SR, QSPI_SR_FTF_Msk) == (QSPI_SR_FTF_Msk));
}

/**
  * @brief    
  * @rmtoll   SR    FTF    FL_QSPI_ClearFlag_FIFOthreshold
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_ClearFlag_FIFOthreshold(QSPI_Type* QSPIx)
{
    WRITE_REG(QSPIx->SR, QSPI_SR_FTF_Msk);
}

/**
  * @brief    
  * @rmtoll   SR    TCF    FL_QSPI_IsActiveFlag_TransferComplete
  * @param    QSPIx QSPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_QSPI_IsActiveFlag_TransferComplete(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->SR, QSPI_SR_TCF_Msk) == (QSPI_SR_TCF_Msk));
}

/**
  * @brief    
  * @rmtoll   SR    TCF    FL_QSPI_ClearFlag_TransferComplete
  * @param    QSPIx QSPI instance
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_ClearFlag_TransferComplete(QSPI_Type* QSPIx)
{
    WRITE_REG(QSPIx->SR, QSPI_SR_TCF_Msk);
}

/**
  * @brief    
  * @rmtoll   DATALEN    DATALEN    FL_QSPI_WriteDataLength
  * @param    QSPIx QSPI instance
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_WriteDataLength(QSPI_Type* QSPIx, uint32_t length)
{
    MODIFY_REG(QSPIx->DATALEN, (0xffffffffU << 0U), (length << 0U));
}

/**
  * @brief    
  * @rmtoll   DATALEN    DATALEN    FL_QSPI_ReadDataLength
  * @param    QSPIx QSPI instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_QSPI_ReadDataLength(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->DATALEN, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    
  * @rmtoll   CCR    CRM    FL_QSPI_SetContinuousReadMode
  * @param    QSPIx QSPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_QSPI_SEND_COMMAND_EVERYTIME
  *           @arg @ref FL_QSPI_SEND_COMMAND_ONCE
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_SetContinuousReadMode(QSPI_Type* QSPIx, uint32_t mode)
{
    MODIFY_REG(QSPIx->CCR, QSPI_CCR_CRM_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CCR    CRM    FL_QSPI_GetContinuousReadMode
  * @param    QSPIx QSPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_QSPI_SEND_COMMAND_EVERYTIME
  *           @arg @ref FL_QSPI_SEND_COMMAND_ONCE
  */
__STATIC_INLINE uint32_t FL_QSPI_GetContinuousReadMode(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CCR, QSPI_CCR_CRM_Msk));
}

/**
  * @brief    
  * @rmtoll   CCR    OPMODE    FL_QSPI_SetOperatingMode
  * @param    QSPIx QSPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_QSPI_OPERATION_MODE_WRITE
  *           @arg @ref FL_QSPI_OPERATION_MODE_READ
  *           @arg @ref FL_QSPI_OPERATION_MODE_QUERY
  *           @arg @ref FL_QSPI_OPERATION_MODE_MAP
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_SetOperatingMode(QSPI_Type* QSPIx, uint32_t mode)
{
    MODIFY_REG(QSPIx->CCR, QSPI_CCR_OPMODE_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CCR    OPMODE    FL_QSPI_GetOperatingMode
  * @param    QSPIx QSPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_QSPI_OPERATION_MODE_WRITE
  *           @arg @ref FL_QSPI_OPERATION_MODE_READ
  *           @arg @ref FL_QSPI_OPERATION_MODE_QUERY
  *           @arg @ref FL_QSPI_OPERATION_MODE_MAP
  */
__STATIC_INLINE uint32_t FL_QSPI_GetOperatingMode(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CCR, QSPI_CCR_OPMODE_Msk));
}

/**
  * @brief    
  * @rmtoll   CCR    DMODE    FL_QSPI_SetDataMode
  * @param    QSPIx QSPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_QSPI_DATAT_MODE_NONE
  *           @arg @ref FL_QSPI_DATAT_MODE_SINGLE
  *           @arg @ref FL_QSPI_DATAT_MODE_DOUBLE
  *           @arg @ref FL_QSPI_DATAT_MODE_FOUR
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_SetDataMode(QSPI_Type* QSPIx, uint32_t mode)
{
    MODIFY_REG(QSPIx->CCR, QSPI_CCR_DMODE_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CCR    DMODE    FL_QSPI_GetDataMode
  * @param    QSPIx QSPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_QSPI_DATA_MODE_NONE
  *           @arg @ref FL_QSPI_DATA_MODE_SINGLE
  *           @arg @ref FL_QSPI_DATA_MODE_DOUBLE
  *           @arg @ref FL_QSPI_DATA_MODE_FOUR
  */
__STATIC_INLINE uint32_t FL_QSPI_GetDataMode(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CCR, QSPI_CCR_DMODE_Msk));
}

/**
  * @brief    
  * @rmtoll   CCR    DUMCYC    FL_QSPI_WriteDummyCycle
  * @param    QSPIx QSPI instance
  * @param    cycle 
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_WriteDummyCycle(QSPI_Type* QSPIx, uint32_t cycle)
{
    MODIFY_REG(QSPIx->CCR, (0x1fU << 18U), (cycle << 18U));
}

/**
  * @brief    
  * @rmtoll   CCR    DUMCYC    FL_QSPI_ReadDummyCycle
  * @param    QSPIx QSPI instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_QSPI_ReadDummyCycle(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CCR, (0x1fU << 18U)) >> 18U);
}

/**
  * @brief    
  * @rmtoll   CCR    ABSIZE    FL_QSPI_SetAlternateBytesSize
  * @param    QSPIx QSPI instance
  * @param    size This parameter can be one of the following values:
  *           @arg @ref FL_QSPI_AB_SIZE_8bits
  *           @arg @ref FL_QSPI_AB_SIZE_16bits
  *           @arg @ref FL_QSPI_AB_SIZE_24bits
  *           @arg @ref FL_QSPI_AB_SIZE_32bits
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_SetAlternateBytesSize(QSPI_Type* QSPIx, uint32_t size)
{
    MODIFY_REG(QSPIx->CCR, QSPI_CCR_ABSIZE_Msk, size);
}

/**
  * @brief    
  * @rmtoll   CCR    ABSIZE    FL_QSPI_GetAlternateBytesSize
  * @param    QSPIx QSPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_QSPI_AB_SIZE_8bits
  *           @arg @ref FL_QSPI_AB_SIZE_16bits
  *           @arg @ref FL_QSPI_AB_SIZE_24bits
  *           @arg @ref FL_QSPI_AB_SIZE_32bits
  */
__STATIC_INLINE uint32_t FL_QSPI_GetAlternateBytesSize(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CCR, QSPI_CCR_ABSIZE_Msk));
}

/**
  * @brief    
  * @rmtoll   CCR    ABMODE    FL_QSPI_SetAlternateBytesMode
  * @param    QSPIx QSPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_QSPI_AB_MODE_NONE
  *           @arg @ref FL_QSPI_AB_MODE_SINGLE
  *           @arg @ref FL_QSPI_AB_MODE_DOUBLE
  *           @arg @ref FL_QSPI_AB_MODE_FOUR
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_SetAlternateBytesMode(QSPI_Type* QSPIx, uint32_t mode)
{
    MODIFY_REG(QSPIx->CCR, QSPI_CCR_ABMODE_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CCR    ABMODE    FL_QSPI_GetAlternateBytesMode
  * @param    QSPIx QSPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_QSPI_AB_MODE_NONE
  *           @arg @ref FL_QSPI_AB_MODE_SINGLE
  *           @arg @ref FL_QSPI_AB_MODE_DOUBLE
  *           @arg @ref FL_QSPI_AB_MODE_FOUR
  */
__STATIC_INLINE uint32_t FL_QSPI_GetAlternateBytesMode(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CCR, QSPI_CCR_ABMODE_Msk));
}

/**
  * @brief    
  * @rmtoll   CCR    ADSIZE    FL_QSPI_SetAddressSize
  * @param    QSPIx QSPI instance
  * @param    size This parameter can be one of the following values:
  *           @arg @ref FL_QSPI_AD_SIZE_8bits
  *           @arg @ref FL_QSPI_AD_SIZE_16bits
  *           @arg @ref FL_QSPI_AD_SIZE_24bits
  *           @arg @ref FL_QSPI_AD_SIZE_32bits
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_SetAddressSize(QSPI_Type* QSPIx, uint32_t size)
{
    MODIFY_REG(QSPIx->CCR, QSPI_CCR_ADSIZE_Msk, size);
}

/**
  * @brief    
  * @rmtoll   CCR    ADSIZE    FL_QSPI_GetAddressSize
  * @param    QSPIx QSPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_QSPI_AD_SIZE_8bits
  *           @arg @ref FL_QSPI_AD_SIZE_16bits
  *           @arg @ref FL_QSPI_AD_SIZE_24bits
  *           @arg @ref FL_QSPI_AD_SIZE_32bits
  */
__STATIC_INLINE uint32_t FL_QSPI_GetAddressSize(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CCR, QSPI_CCR_ADSIZE_Msk));
}

/**
  * @brief    
  * @rmtoll   CCR    ADMODE    FL_QSPI_SetAddressMode
  * @param    QSPIx QSPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_QSPI_AD_MODE_NONE
  *           @arg @ref FL_QSPI_AD_MODE_SINGLE
  *           @arg @ref FL_QSPI_AD_MODE_DOUBLE
  *           @arg @ref FL_QSPI_AD_MODE_FOUR
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_SetAddressMode(QSPI_Type* QSPIx, uint32_t mode)
{
    MODIFY_REG(QSPIx->CCR, QSPI_CCR_ADMODE_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CCR    ADMODE    FL_QSPI_GetAddressMode
  * @param    QSPIx QSPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_QSPI_AD_MODE_NONE
  *           @arg @ref FL_QSPI_AD_MODE_SINGLE
  *           @arg @ref FL_QSPI_AD_MODE_DOUBLE
  *           @arg @ref FL_QSPI_AD_MODE_FOUR
  */
__STATIC_INLINE uint32_t FL_QSPI_GetAddressMode(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CCR, QSPI_CCR_ADMODE_Msk));
}

/**
  * @brief    
  * @rmtoll   CCR    IMODE    FL_QSPI_SetInstructionMode
  * @param    QSPIx QSPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_QSPI_IMODE_NONE
  *           @arg @ref FL_QSPI_IMODE_SINGLE
  *           @arg @ref FL_QSPI_IMODE_DOUBLE
  *           @arg @ref FL_QSPI_IMODE_FOUR
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_SetInstructionMode(QSPI_Type* QSPIx, uint32_t mode)
{
    MODIFY_REG(QSPIx->CCR, QSPI_CCR_IMODE_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CCR    IMODE    FL_QSPI_GetInstructionMode
  * @param    QSPIx QSPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_QSPI_IMODE_NONE
  *           @arg @ref FL_QSPI_IMODE_SINGLE
  *           @arg @ref FL_QSPI_IMODE_DOUBLE
  *           @arg @ref FL_QSPI_IMODE_FOUR
  */
__STATIC_INLINE uint32_t FL_QSPI_GetInstructionMode(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CCR, QSPI_CCR_IMODE_Msk));
}

/**
  * @brief    
  * @rmtoll   CCR    INSTRUCTION    FL_QSPI_WriteInstruction
  * @param    QSPIx QSPI instance
  * @param    instruction 
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_WriteInstruction(QSPI_Type* QSPIx, uint32_t instruction)
{
    MODIFY_REG(QSPIx->CCR, (0xffU << 0U), (instruction << 0U));
}

/**
  * @brief    
  * @rmtoll   CCR    INSTRUCTION    FL_QSPI_ReadInstruction
  * @param    QSPIx QSPI instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_QSPI_ReadInstruction(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->CCR, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    
  * @rmtoll   ADDR    ADDR    FL_QSPI_WriteAddress
  * @param    QSPIx QSPI instance
  * @param    address 
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_WriteAddress(QSPI_Type* QSPIx, uint32_t address)
{
    MODIFY_REG(QSPIx->ADDR, (0xffffffffU << 0U), (address << 0U));
}

/**
  * @brief    
  * @rmtoll   ADDR    ADDR    FL_QSPI_ReadAddress
  * @param    QSPIx QSPI instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_QSPI_ReadAddress(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->ADDR, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    
  * @rmtoll   ABR    ABR    FL_QSPI_WriteAlternateBytes
  * @param    QSPIx QSPI instance
  * @param    alternate 
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_WriteAlternateBytes(QSPI_Type* QSPIx, uint32_t alternate)
{
    MODIFY_REG(QSPIx->ABR, (0xffffffffU << 0U), (alternate << 0U));
}

/**
  * @brief    
  * @rmtoll   ABR    ABR    FL_QSPI_ReadAlternateBytes
  * @param    QSPIx QSPI instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_QSPI_ReadAlternateBytes(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->ABR, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    
  * @rmtoll   DR    DATA    FL_QSPI_WriteData
  * @param    QSPIx QSPI instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_WriteData(QSPI_Type* QSPIx, uint32_t data)
{
    MODIFY_REG(QSPIx->DR, (0xffffffffU << 0U), (data << 0U));
}

/**
  * @brief    
  * @rmtoll   DR    DATA    FL_QSPI_ReadData
  * @param    QSPIx QSPI instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_QSPI_ReadData(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->DR, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    
  * @rmtoll   SMSK    SMSK    FL_QSPI_WriteStatusMask
  * @param    QSPIx QSPI instance
  * @param    mask 
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_WriteStatusMask(QSPI_Type* QSPIx, uint32_t mask)
{
    MODIFY_REG(QSPIx->SMSK, (0xffffffffU << 0U), (mask << 0U));
}

/**
  * @brief    
  * @rmtoll   SMSK    SMSK    FL_QSPI_ReadStatusMask
  * @param    QSPIx QSPI instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_QSPI_ReadStatusMask(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->SMSK, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    
  * @rmtoll   SMAT    SMAT    FL_QSPI_WriteStatusMatch
  * @param    QSPIx QSPI instance
  * @param    match 
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_WriteStatusMatch(QSPI_Type* QSPIx, uint32_t match)
{
    MODIFY_REG(QSPIx->SMAT, (0xffffffffU << 0U), (match << 0U));
}

/**
  * @brief    
  * @rmtoll   SMAT    SMAT    FL_QSPI_ReadStatusMatch
  * @param    QSPIx QSPI instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_QSPI_ReadStatusMatch(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->SMAT, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    
  * @rmtoll   PITV    PITV    FL_QSPI_WritePollingInterval
  * @param    QSPIx QSPI instance
  * @param    interval 
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_WritePollingInterval(QSPI_Type* QSPIx, uint32_t interval)
{
    MODIFY_REG(QSPIx->PITV, (0xffffU << 0U), (interval << 0U));
}

/**
  * @brief    
  * @rmtoll   PITV    PITV    FL_QSPI_ReadPollingInterval
  * @param    QSPIx QSPI instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_QSPI_ReadPollingInterval(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->PITV, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    
  * @rmtoll   TO    TO    FL_QSPI_WriteTimeoutPeriod
  * @param    QSPIx QSPI instance
  * @param    period 
  * @retval   None
  */
__STATIC_INLINE void FL_QSPI_WriteTimeoutPeriod(QSPI_Type* QSPIx, uint32_t period)
{
    MODIFY_REG(QSPIx->TOR, (0xffffU << 0U), (period << 0U));
}

/**
  * @brief    
  * @rmtoll   TO    TO    FL_QSPI_ReadTimeoutPeriod
  * @param    QSPIx QSPI instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_QSPI_ReadTimeoutPeriod(QSPI_Type* QSPIx)
{
    return (uint32_t)(READ_BIT(QSPIx->TOR, (0xffffU << 0U)) >> 0U);
}

/**
  * @}
  */

/** @defgroup QSPI_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_QSPI_Init(QSPI_Type *QSPIx, QSPI_InitTypeDef  *QSPI_InitStruct);
void FL_QSPI_StructInit(QSPI_InitTypeDef  *QSPI_InitStruct);
FL_ErrorStatus FL_QSPI_DeInit(QSPI_Type *QSPIx);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_QSPI_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2024-01-06*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
