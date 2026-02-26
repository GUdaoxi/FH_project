/**
 *******************************************************************************************************
 * @file    fm33fh0xx_fl_spi.h
 * @author  FMSH Application Team
 * @brief   Head file of SPI FL Module
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
#ifndef __FM33FH0XX_FL_SPI_H
#define __FM33FH0XX_FL_SPI_H

#ifdef __cplusplus
extern "C"
{
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl_def.h"
  /** @addtogroup FM33FH0XX_FL_Driver
   * @{
   */
  /* Exported types -------------------------------------------------------------------------------------*/
  /** @defgroup SPI_FL_ES_INIT SPI Exported Init structures
   * @{
   */

  /**
   * @brief FL SPI Init Sturcture definition
   */
  typedef struct
  {
    /*! 传输模式 单双工 */
    uint32_t transferMode;
    /*! 主从模式 */
    uint32_t mode;
    /*! 数据位宽 */
    uint32_t dataWidth;
    /*! 时钟极性 */
    uint32_t clockPolarity;
    /*! 时钟相位 */
    uint32_t clockPhase;
    /*! NSS 脚使能软件控制 */
    uint32_t softControl;
    /*! 通讯速率 */
    uint32_t baudRate;
    /*! Bit方向 */
    uint32_t bitOrder;

  } FL_SPI_InitTypeDef;

  typedef struct
  {
    /*! I2S主从机模式 */
    uint32_t mode;
    /*! I2S标准选择*/
    uint32_t standard;
    /*! I2S通信长度*/
    uint32_t dataFormat;
    /*! I2S_MCLK输出使能*/
    FL_FunState mclkOutput;
    /*! I2S_音频采样频率*/
    uint32_t audioFreq;
    /*! I2S空闲时钟极性*/
    uint32_t clockPolarity;

  } FL_I2S_InitTypeDef;

#define FL_I2S_DATAFORMAT_16B 0x00000000U
#define FL_I2S_DATAFORMAT_16B_EXTENDED (FL_I2S_VOCAL_TRACT_LENGTH_32BITS)
#define FL_I2S_DATAFORMAT_24B (FL_I2S_VOCAL_TRACT_LENGTH_32BITS | FL_I2S_DATA_LENGTH_24BITS)
#define FL_I2S_DATAFORMAT_32B (FL_I2S_VOCAL_TRACT_LENGTH_32BITS | FL_I2S_DATA_LENGTH_32BITS)

#define FL_I2S_AUDIOFREQ_192K 192000U
#define FL_I2S_AUDIOFREQ_96K 96000U
#define FL_I2S_AUDIOFREQ_48K 48000U
#define FL_I2S_AUDIOFREQ_44K 44100U
#define FL_I2S_AUDIOFREQ_32K 32000U
#define FL_I2S_AUDIOFREQ_22K 22050U
#define FL_I2S_AUDIOFREQ_16K 16000U
#define FL_I2S_AUDIOFREQ_11K 11025U
#define FL_I2S_AUDIOFREQ_8K 8000U

#define FL_I2S_STANDARD_PHILIPS FL_I2S_STANDARD_MODE_PHILIPS
#define FL_I2S_STANDARD_MSB FL_I2S_STANDARD_MODE_MSB_JUSTIFIED
#define FL_I2S_STANDARD_LSB FL_I2S_STANDARD_MODE_LSB_JUSTIFIED
#define FL_I2S_STANDARD_PCM_SHORT (FL_I2S_STANDARD_MODE_PCM)
#define FL_I2S_STANDARD_PCM_LONG (FL_I2S_STANDARD_MODE_PCM | FL_I2S_FRAME_SYNCHRONIZATION_LONG)

  /**
   * @}
   */
  /* Exported constants ---------------------------------------------------------------------------------*/
  /** @defgroup SPI_FL_Exported_Constants SPI Exported Constants
   * @{
   */

#define SPI_CR1_IOSWAP_Pos (11U)
#define SPI_CR1_IOSWAP_Msk (0x1U << SPI_CR1_IOSWAP_Pos)
#define SPI_CR1_IOSWAP SPI_CR1_IOSWAP_Msk

#define SPI_CR1_MSPA_Pos (10U)
#define SPI_CR1_MSPA_Msk (0x1U << SPI_CR1_MSPA_Pos)
#define SPI_CR1_MSPA SPI_CR1_MSPA_Msk

#define SPI_CR1_SSPA_Pos (9U)
#define SPI_CR1_SSPA_Msk (0x1U << SPI_CR1_SSPA_Pos)
#define SPI_CR1_SSPA SPI_CR1_SSPA_Msk

#define SPI_CR1_MM_Pos (8U)
#define SPI_CR1_MM_Msk (0x1U << SPI_CR1_MM_Pos)
#define SPI_CR1_MM SPI_CR1_MM_Msk

#define SPI_CR1_WAIT_Pos (6U)
#define SPI_CR1_WAIT_Msk (0x3U << SPI_CR1_WAIT_Pos)
#define SPI_CR1_WAIT SPI_CR1_WAIT_Msk

#define SPI_CR1_BAUD_Pos (3U)
#define SPI_CR1_BAUD_Msk (0x7U << SPI_CR1_BAUD_Pos)
#define SPI_CR1_BAUD SPI_CR1_BAUD_Msk

#define SPI_CR1_LSBF_Pos (2U)
#define SPI_CR1_LSBF_Msk (0x1U << SPI_CR1_LSBF_Pos)
#define SPI_CR1_LSBF SPI_CR1_LSBF_Msk

#define SPI_CR1_CPOL_Pos (1U)
#define SPI_CR1_CPOL_Msk (0x1U << SPI_CR1_CPOL_Pos)
#define SPI_CR1_CPOL SPI_CR1_CPOL_Msk

#define SPI_CR1_CPHA_Pos (0U)
#define SPI_CR1_CPHA_Msk (0x1U << SPI_CR1_CPHA_Pos)
#define SPI_CR1_CPHA SPI_CR1_CPHA_Msk

#define SPI_CR2_DUMMY_EN_Pos (15U)
#define SPI_CR2_DUMMY_EN_Msk (0x1U << SPI_CR2_DUMMY_EN_Pos)
#define SPI_CR2_DUMMY_EN SPI_CR2_DUMMY_EN_Msk

#define SPI_CR2_DLEN2_Pos (12U)
#define SPI_CR2_DLEN2_Msk (0x7U << SPI_CR2_DLEN2_Pos)
#define SPI_CR2_DLEN2 SPI_CR2_DLEN2_Msk

#define SPI_CR2_DLEN_Pos (9U)
#define SPI_CR2_DLEN_Msk (0x3U << SPI_CR2_DLEN_Pos)
#define SPI_CR2_DLEN SPI_CR2_DLEN_Msk

#define SPI_CR2_RXO_Pos (11U)
#define SPI_CR2_RXO_Msk (0x1U << SPI_CR2_RXO_Pos)
#define SPI_CR2_RXO SPI_CR2_RXO_Msk

#define SPI_CR2_HALFDUPLEX_Pos (8U)
#define SPI_CR2_HALFDUPLEX_Msk (0x1U << SPI_CR2_HALFDUPLEX_Pos)
#define SPI_CR2_HALFDUPLEX SPI_CR2_HALFDUPLEX_Msk

#define SPI_CR2_HD_RW_Pos (7U)
#define SPI_CR2_HD_RW_Msk (0x1U << SPI_CR2_HD_RW_Pos)
#define SPI_CR2_HD_RW SPI_CR2_HD_RW_Msk

#define SPI_CR2_CMD8B_Pos (6U)
#define SPI_CR2_CMD8B_Msk (0x1U << SPI_CR2_CMD8B_Pos)
#define SPI_CR2_CMD8B SPI_CR2_CMD8B_Msk

#define SPI_CR2_SSNM_Pos (5U)
#define SPI_CR2_SSNM_Msk (0x1U << SPI_CR2_SSNM_Pos)
#define SPI_CR2_SSNM SPI_CR2_SSNM_Msk

#define SPI_CR2_TXO_AC_Pos (4U)
#define SPI_CR2_TXO_AC_Msk (0x1U << SPI_CR2_TXO_AC_Pos)
#define SPI_CR2_TXO_AC SPI_CR2_TXO_AC_Msk

#define SPI_CR2_TXO_Pos (3U)
#define SPI_CR2_TXO_Msk (0x1U << SPI_CR2_TXO_Pos)
#define SPI_CR2_TXO SPI_CR2_TXO_Msk

#define SPI_CR2_SSN_Pos (2U)
#define SPI_CR2_SSN_Msk (0x1U << SPI_CR2_SSN_Pos)
#define SPI_CR2_SSN SPI_CR2_SSN_Msk

#define SPI_CR2_SSNSEN_Pos (1U)
#define SPI_CR2_SSNSEN_Msk (0x1U << SPI_CR2_SSNSEN_Pos)
#define SPI_CR2_SSNSEN SPI_CR2_SSNSEN_Msk

#define SPI_CR2_SPIEN_Pos (0U)
#define SPI_CR2_SPIEN_Msk (0x1U << SPI_CR2_SPIEN_Pos)
#define SPI_CR2_SPIEN SPI_CR2_SPIEN_Msk

#define SPI_CR3_TXBFC_Pos (3U)
#define SPI_CR3_TXBFC_Msk (0x1U << SPI_CR3_TXBFC_Pos)
#define SPI_CR3_TXBFC SPI_CR3_TXBFC_Msk

#define SPI_CR3_RXBFC_Pos (2U)
#define SPI_CR3_RXBFC_Msk (0x1U << SPI_CR3_RXBFC_Pos)
#define SPI_CR3_RXBFC SPI_CR3_RXBFC_Msk

#define SPI_CR3_MERRC_Pos (1U)
#define SPI_CR3_MERRC_Msk (0x1U << SPI_CR3_MERRC_Pos)
#define SPI_CR3_MERRC SPI_CR3_MERRC_Msk

#define SPI_CR3_SERRC_Pos (0U)
#define SPI_CR3_SERRC_Msk (0x1U << SPI_CR3_SERRC_Pos)
#define SPI_CR3_SERRC SPI_CR3_SERRC_Msk

#define SPI_IER_SSNRIE_Pos (5U)
#define SPI_IER_SSNRIE_Msk (0x1U << SPI_IER_SSNRIE_Pos)
#define SPI_IER_SSNRIE SPI_IER_SSNRIE_Msk

#define SPI_IER_SSNFIE_Pos (4U)
#define SPI_IER_SSNFIE_Msk (0x1U << SPI_IER_SSNFIE_Pos)
#define SPI_IER_SSNFIE SPI_IER_SSNFIE_Msk

#define SPI_IER_TXSEIE_Pos (3U)
#define SPI_IER_TXSEIE_Msk (0x1U << SPI_IER_TXSEIE_Pos)
#define SPI_IER_TXSEIE SPI_IER_TXSEIE_Msk

#define SPI_IER_ERRIE_Pos (2U)
#define SPI_IER_ERRIE_Msk (0x1U << SPI_IER_ERRIE_Pos)
#define SPI_IER_ERRIE SPI_IER_ERRIE_Msk

#define SPI_IER_TXBEIE_Pos (1U)
#define SPI_IER_TXBEIE_Msk (0x1U << SPI_IER_TXBEIE_Pos)
#define SPI_IER_TXBEIE SPI_IER_TXBEIE_Msk

#define SPI_IER_RXIE_Pos (0U)
#define SPI_IER_RXIE_Msk (0x1U << SPI_IER_RXIE_Pos)
#define SPI_IER_RXIE SPI_IER_RXIE_Msk

#define SPI_ISR_DCN_TX_Pos (12U)
#define SPI_ISR_DCN_TX_Msk (0x1U << SPI_ISR_DCN_TX_Pos)
#define SPI_ISR_DCN_TX SPI_ISR_DCN_TX_Msk

#define SPI_ISR_RXCOL_Pos (10U)
#define SPI_ISR_RXCOL_Msk (0x1U << SPI_ISR_RXCOL_Pos)
#define SPI_ISR_RXCOL SPI_ISR_RXCOL_Msk

#define SPI_ISR_TXCOL_Pos (9U)
#define SPI_ISR_TXCOL_Msk (0x1U << SPI_ISR_TXCOL_Pos)
#define SPI_ISR_TXCOL SPI_ISR_TXCOL_Msk

#define SPI_ISR_BUSY_Pos (8U)
#define SPI_ISR_BUSY_Msk (0x1U << SPI_ISR_BUSY_Pos)
#define SPI_ISR_BUSY SPI_ISR_BUSY_Msk

#define SPI_ISR_CHSIDE_Pos (7U)
#define SPI_ISR_CHSIDE_Msk (0x1U << SPI_ISR_CHSIDE_Pos)
#define SPI_ISR_CHSIDE SPI_ISR_CHSIDE_Msk

#define SPI_ISR_MERR_Pos (6U)
#define SPI_ISR_MERR_Msk (0x1U << SPI_ISR_MERR_Pos)
#define SPI_ISR_MERR SPI_ISR_MERR_Msk

#define SPI_ISR_SERR_Pos (5U)
#define SPI_ISR_SERR_Msk (0x1U << SPI_ISR_SERR_Pos)
#define SPI_ISR_SERR SPI_ISR_SERR_Msk

#define SPI_ISR_SSNR_Pos (4U)
#define SPI_ISR_SSNR_Msk (0x1U << SPI_ISR_SSNR_Pos)
#define SPI_ISR_SSNR SPI_ISR_SSNR_Msk

#define SPI_ISR_SSNF_Pos (3U)
#define SPI_ISR_SSNF_Msk (0x1U << SPI_ISR_SSNF_Pos)
#define SPI_ISR_SSNF SPI_ISR_SSNF_Msk

#define SPI_ISR_TXSE_Pos (2U)
#define SPI_ISR_TXSE_Msk (0x1U << SPI_ISR_TXSE_Pos)
#define SPI_ISR_TXSE SPI_ISR_TXSE_Msk

#define SPI_ISR_TXBE_Pos (1U)
#define SPI_ISR_TXBE_Msk (0x1U << SPI_ISR_TXBE_Pos)
#define SPI_ISR_TXBE SPI_ISR_TXBE_Msk

#define SPI_ISR_RXBF_Pos (0U)
#define SPI_ISR_RXBF_Msk (0x1U << SPI_ISR_RXBF_Pos)
#define SPI_ISR_RXBF SPI_ISR_RXBF_Msk

#define FL_SPI_MASTER_SAMPLING_NORMAL (0x0U << SPI_CR1_MSPA_Pos)
#define FL_SPI_MASTER_SAMPLING_DELAY_HALFCLK (0x1U << SPI_CR1_MSPA_Pos)

#define FL_SPI_SLAVE_SAMPLING_NORMAL (0x0U << SPI_CR1_SSPA_Pos)
#define FL_SPI_SLAVE_SAMPLING_ADVANCE_HALFCLK (0x1U << SPI_CR1_SSPA_Pos)

#define FL_SPI_WORK_MODE_SLAVE (0x0U << SPI_CR1_MM_Pos)
#define FL_SPI_WORK_MODE_MASTER (0x1U << SPI_CR1_MM_Pos)

#define FL_SPI_SEND_WAIT_0 (0x0U << SPI_CR1_WAIT_Pos)
#define FL_SPI_SEND_WAIT_1 (0x1U << SPI_CR1_WAIT_Pos)
#define FL_SPI_SEND_WAIT_2 (0x2U << SPI_CR1_WAIT_Pos)
#define FL_SPI_SEND_WAIT_3 (0x3U << SPI_CR1_WAIT_Pos)

#define FL_SPI_CLK_DIV2 (0x0U << SPI_CR1_BAUD_Pos)
#define FL_SPI_CLK_DIV4 (0x1U << SPI_CR1_BAUD_Pos)
#define FL_SPI_CLK_DIV8 (0x2U << SPI_CR1_BAUD_Pos)
#define FL_SPI_CLK_DIV16 (0x3U << SPI_CR1_BAUD_Pos)
#define FL_SPI_CLK_DIV32 (0x4U << SPI_CR1_BAUD_Pos)
#define FL_SPI_CLK_DIV64 (0x5U << SPI_CR1_BAUD_Pos)
#define FL_SPI_CLK_DIV128 (0x6U << SPI_CR1_BAUD_Pos)
#define FL_SPI_CLK_DIV256 (0x7U << SPI_CR1_BAUD_Pos)

#define FL_SPI_BAUDRATE_DIV2 (0x0U << SPI_CR1_BAUD_Pos)
#define FL_SPI_BAUDRATE_DIV4 (0x1U << SPI_CR1_BAUD_Pos)
#define FL_SPI_BAUDRATE_DIV8 (0x2U << SPI_CR1_BAUD_Pos)
#define FL_SPI_BAUDRATE_DIV16 (0x3U << SPI_CR1_BAUD_Pos)
#define FL_SPI_BAUDRATE_DIV32 (0x4U << SPI_CR1_BAUD_Pos)
#define FL_SPI_BAUDRATE_DIV64 (0x5U << SPI_CR1_BAUD_Pos)
#define FL_SPI_BAUDRATE_DIV128 (0x6U << SPI_CR1_BAUD_Pos)
#define FL_SPI_BAUDRATE_DIV256 (0x7U << SPI_CR1_BAUD_Pos)

#define FL_SPI_BIT_ORDER_MSB_FIRST (0x0U << SPI_CR1_LSBF_Pos)
#define FL_SPI_BIT_ORDER_LSB_FIRST (0x1U << SPI_CR1_LSBF_Pos)

#define FL_SPI_POLARITY_NORMAL (0x0U << SPI_CR1_CPOL_Pos)
#define FL_SPI_POLARITY_INVERT (0x1U << SPI_CR1_CPOL_Pos)

#define FL_SPI_PHASE_EDGE1 (0x0U << SPI_CR1_CPHA_Pos)
#define FL_SPI_PHASE_EDGE2 (0x1U << SPI_CR1_CPHA_Pos)

#define FL_SPI_DATAH_WIDTH0 (0x0U << SPI_CR2_DLEN2_Pos)
#define FL_SPI_DATAH_WIDTH1 (0x1U << SPI_CR2_DLEN2_Pos)
#define FL_SPI_DATAH_WIDTH2 (0x2U << SPI_CR2_DLEN2_Pos)
#define FL_SPI_DATAH_WIDTH3 (0x3U << SPI_CR2_DLEN2_Pos)
#define FL_SPI_DATAH_WIDTH4 (0x4U << SPI_CR2_DLEN2_Pos)
#define FL_SPI_DATAH_WIDTH5 (0x5U << SPI_CR2_DLEN2_Pos)
#define FL_SPI_DATAH_WIDTH6 (0x6U << SPI_CR2_DLEN2_Pos)
#define FL_SPI_DATAH_WIDTH7 (0x7U << SPI_CR2_DLEN2_Pos)

#define FL_SPI_DATAL_WIDTH0 (0x0U << SPI_CR2_DLEN_Pos)
#define FL_SPI_DATAL_WIDTH1 (0x1U << SPI_CR2_DLEN_Pos)
#define FL_SPI_DATAL_WIDTH2 (0x2U << SPI_CR2_DLEN_Pos)
#define FL_SPI_DATAL_WIDTH3 (0x3U << SPI_CR2_DLEN_Pos)

#define FL_SPI_TRANSFER_MODE_FULL_DUPLEX (0x0U << SPI_CR2_HALFDUPLEX_Pos)
#define FL_SPI_TRANSFER_MODE_HALF_DUPLEX (0x1U << SPI_CR2_HALFDUPLEX_Pos)

#define FL_SPI_HALF_DUPLEX_TX (0x0U << SPI_CR2_HD_RW_Pos)
#define FL_SPI_HALF_DUPLEX_RX (0x1U << SPI_CR2_HD_RW_Pos)

#define FL_SPI_HALF_DUPLEX_CMDLEN_DLEN (0x0U << SPI_CR2_CMD8B_Pos)
#define FL_SPI_HALF_DUPLEX_CMDLEN_8B (0x1U << SPI_CR2_CMD8B_Pos)

#define FL_SPI_HALFDUPLEX_CMDLEN_DLEN (0x0U << SPI_CR2_CMD8B_Pos)
#define FL_SPI_HALFDUPLEX_CMDLEN_8B (0x1U << SPI_CR2_CMD8B_Pos)

#define FL_SPI_HARDWARE_SSN_KEEP_LOW (0x0U << SPI_CR2_SSNM_Pos)
#define FL_SPI_HARDWARE_SSN_AUTO_HIGH (0x1U << SPI_CR2_SSNM_Pos)

#define FL_SPI_SSN_LOW (0x0U << SPI_CR2_SSN_Pos)
#define FL_SPI_SSN_HIGH (0x1U << SPI_CR2_SSN_Pos)

#define FL_SPI_FRAME_MODE_CMD (0x0U << SPI_ISR_DCN_TX_Pos)
#define FL_SPI_FRAME_MODE_DATA (0x1U << SPI_ISR_DCN_TX_Pos)

#define FL_SPI_VOCAL_TRACT_LEFT (0x0U << SPI_ISR_CHSIDE_Pos)
#define FL_SPI_VOCAL_TRACT_RIGHT (0x1U << SPI_ISR_CHSIDE_Pos)

#define I2S_IER_SSNRFIE_Pos (5U)
#define I2S_IER_SSNRIE_Msk (0x1U << I2S_IER_SSNRFIE_Pos)
#define I2S_IER_SSNRFIE I2S_IER_SSNRIE_Msk

#define I2S_IER_SSNFIE_Pos (4U)
#define I2S_IER_SSNFIE_Msk (0x1U << I2S_IER_SSNFIE_Pos)
#define I2S_IER_SSNFIE I2S_IER_SSNFIE_Msk

#define I2S_IER_TXSEIE_Pos (3U)
#define I2S_IER_TXSEIE_Msk (0x1U << I2S_IER_TXSEIE_Pos)
#define I2S_IER_TXSEIE I2S_IER_TXSEIE_Msk

#define I2S_IER_ERRIE_Pos (2U)
#define I2S_IER_ERRIE_Msk (0x1U << I2S_IER_ERRIE_Pos)
#define I2S_IER_ERRIE I2S_IER_ERRIE_Msk

#define I2S_IER_TXBEIE_Pos (1U)
#define I2S_IER_TXBEIE_Msk (0x1U << I2S_IER_TXBEIE_Pos)
#define I2S_IER_TXBEIE I2S_IER_TXBEIE_Msk

#define I2S_IER_RXIE_Pos (0U)
#define I2S_IER_RXIE_Msk (0x1U << I2S_IER_RXIE_Pos)
#define I2S_IER_RXIE I2S_IER_RXIE_Msk

#define I2S_ISR_DCN_TX_Pos (12U)
#define I2S_ISR_DCN_TX_Msk (0x1U << I2S_ISR_DCN_TX_Pos)
#define I2S_ISR_DCN_TX I2S_ISR_DCN_TX_Msk

#define I2S_ISR_RXCOL_Pos (10U)
#define I2S_ISR_RXCOL_Msk (0x1U << I2S_ISR_RXCOL_Pos)
#define I2S_ISR_RXCOL I2S_ISR_RXCOL_Msk

#define I2S_ISR_TXCOL_Pos (9U)
#define I2S_ISR_TXCOL_Msk (0x1U << I2S_ISR_TXCOL_Pos)
#define I2S_ISR_TXCOL I2S_ISR_TXCOL_Msk

#define I2S_ISR_BUSY_Pos (8U)
#define I2S_ISR_BUSY_Msk (0x1U << I2S_ISR_BUSY_Pos)
#define I2S_ISR_BUSY I2S_ISR_BUSY_Msk

#define I2S_ISR_CHSIDE_Pos (7U)
#define I2S_ISR_CHSIDE_Msk (0x1U << I2S_ISR_CHSIDE_Pos)
#define I2S_ISR_CHSIDE I2S_ISR_CHSIDE_Msk

#define I2S_ISR_MERR_Pos (6U)
#define I2S_ISR_MERR_Msk (0x1U << I2S_ISR_MERR_Pos)
#define I2S_ISR_MERR I2S_ISR_MERR_Msk

#define I2S_ISR_SERR_Pos (5U)
#define I2S_ISR_SERR_Msk (0x1U << I2S_ISR_SERR_Pos)
#define I2S_ISR_SERR I2S_ISR_SERR_Msk

#define I2S_ISR_SSNR_Pos (4U)
#define I2S_ISR_SSNR_Msk (0x1U << I2S_ISR_SSNR_Pos)
#define I2S_ISR_SSNR I2S_ISR_SSNR_Msk

#define I2S_ISR_SSNF_Pos (3U)
#define I2S_ISR_SSNF_Msk (0x1U << I2S_ISR_SSNF_Pos)
#define I2S_ISR_SSNF I2S_ISR_SSNF_Msk

#define I2S_ISR_TXSE_Pos (2U)
#define I2S_ISR_TXSE_Msk (0x1U << I2S_ISR_TXSE_Pos)
#define I2S_ISR_TXSE I2S_ISR_TXSE_Msk

#define I2S_ISR_TXBE_Pos (1U)
#define I2S_ISR_TXBE_Msk (0x1U << I2S_ISR_TXBE_Pos)
#define I2S_ISR_TXBE I2S_ISR_TXBE_Msk

#define I2S_ISR_RXBF_Pos (0U)
#define I2S_ISR_RXBF_Msk (0x1U << I2S_ISR_RXBF_Pos)
#define I2S_ISR_RXBF I2S_ISR_RXBF_Msk

#define I2S_TXBUF_Pos (0U)
#define I2S_TXBUF_Msk (0xffffffffU << I2S_TXBUF_Pos)
#define I2S_TXBUF I2S_TXBUF_Msk

#define I2S_RXBUF_Pos (0U)
#define I2S_RXBUF_Msk (0xffffffffU << I2S_RXBUF_Pos)
#define I2S_RXBUF I2S_RXBUF_Msk

#define I2SCR_RXOPT_Pos (12U)
#define I2SCR_RXOTP_Msk (0x1U << I2SCR_RXOPT_Pos)
#define I2SCR_RXOTP I2SCR_RXOTP_Msk

#define I2SCR_I2SSTD_Pos (10U)
#define I2SCR_I2SSTD_Msk (0x3U << I2SCR_I2SSTD_Pos)
#define I2SCR_I2SSTD I2SCR_I2SSTD_Msk

#define I2SCR_CHLEN_Pos (9U)
#define I2SCR_CHLEN_Msk (0x1U << I2SCR_CHLEN_Pos)
#define I2SCR_CHLEN I2SCR_CHLEN_Msk

#define I2SCR_CKPOL_Pos (8U)
#define I2SCR_CKPOL_Msk (0x1U << I2SCR_CKPOL_Pos)
#define I2SCR_CKPOL I2SCR_CKPOL_Msk

#define I2SCR_DLEN_Pos (6U)
#define I2SCR_DLEN_Msk (0x3U << I2SCR_DLEN_Pos)
#define I2SCR_DLEN I2SCR_DLEN_Msk

#define I2SCR_PCMSYNC_Pos (5U)
#define I2SCR_PCMSYNC_Msk (0x1U << I2SCR_PCMSYNC_Pos)
#define I2SCR_PCMSYNC I2SCR_PCMSYNC_Msk

#define I2SCR_I2SMM_Pos (3U)
#define I2SCR_I2SMM_Msk (0x3U << I2SCR_I2SMM_Pos)
#define I2SCR_I2SMM I2SCR_I2SMM_Msk

#define I2SCR_DLYEN_Pos (2U)
#define I2SCR_DLYEN_Msk (0x1U << I2SCR_DLYEN_Pos)
#define I2SCR_DLYEN I2SCR_DLYEN_Msk

#define I2SCR_I2SMOD_Pos (1U)
#define I2SCR_I2SMOD_Msk (0x1U << I2SCR_I2SMOD_Pos)
#define I2SCR_I2SMOD I2SCR_I2SMOD_Msk

#define I2SCR_I2SEN_Pos (0U)
#define I2SCR_I2SEN_Msk (0x1U << I2SCR_I2SEN_Pos)
#define I2SCR_I2SEN I2SCR_I2SEN_Msk

#define I2SPR_MCKOE_Pos (9U)
#define I2SPR_MCKOE_Msk (0x1U << I2SPR_MCKOE_Pos)
#define I2SPR_MCKOE I2SPR_MCKOE_Msk

#define I2SPR_ODD_Pos (8U)
#define I2SPR_ODD_Msk (0x1U << I2SPR_ODD_Pos)
#define I2SPR_ODD I2SPR_ODD_Msk

#define I2SPR_CLKDIV_Pos (0U)
#define I2SPR_CLKDIV_Msk (0xffU << I2SPR_CLKDIV_Pos)
#define I2SPR_CLKDIV I2SPR_CLKDIV_Msk

#define FL_I2S_FRAME_MODE_CMD (0x0U << I2S_ISR_DCN_TX_Pos)
#define FL_I2S_FRAME_MODE_DATA (0x1U << I2S_ISR_DCN_TX_Pos)

#define FL_I2S_VOCAL_TRACT_LEFT (0x0U << I2S_ISR_CHSIDE_Pos)
#define FL_I2S_VOCAL_TRACT_RIGHT (0x1U << I2S_ISR_CHSIDE_Pos)

#define FL_I2S_STANDARD_MODE_PHILIPS (0x0U << I2SCR_I2SSTD_Pos)
#define FL_I2S_STANDARD_MODE_MSB_JUSTIFIED (0x1U << I2SCR_I2SSTD_Pos)
#define FL_I2S_STANDARD_MODE_LSB_JUSTIFIED (0x2U << I2SCR_I2SSTD_Pos)
#define FL_I2S_STANDARD_MODE_PCM (0x3U << I2SCR_I2SSTD_Pos)

#define FL_I2S_VOCAL_TRACT_LENGTH_16BITS (0x0U << I2SCR_CHLEN_Pos)
#define FL_I2S_VOCAL_TRACT_LENGTH_32BITS (0x1U << I2SCR_CHLEN_Pos)

#define FL_I2S_IDLE_POLARITY_LOW (0x0U << I2SCR_CKPOL_Pos)
#define FL_I2S_IDLE_POLARITY_HIGHT (0x1U << I2SCR_CKPOL_Pos)

#define FL_I2S_DATA_LENGTH_16BITS (0x0U << I2SCR_DLEN_Pos)
#define FL_I2S_DATA_LENGTH_24BITS (0x1U << I2SCR_DLEN_Pos)
#define FL_I2S_DATA_LENGTH_32BITS (0x2U << I2SCR_DLEN_Pos)

#define FL_I2S_FRAME_SYNCHRONIZATION_SHORT (0x0U << I2SCR_PCMSYNC_Pos)
#define FL_I2S_FRAME_SYNCHRONIZATION_LONG (0x1U << I2SCR_PCMSYNC_Pos)

#define FL_I2S_MODE_SLAVE_RX (0x0U << I2SCR_I2SMM_Pos)
#define FL_I2S_MODE_SLAVE_TX (0x1U << I2SCR_I2SMM_Pos)
#define FL_I2S_MODE_MASTER_RX (0x2U << I2SCR_I2SMM_Pos)
#define FL_I2S_MODE_MASTER_TX (0x3U << I2SCR_I2SMM_Pos)

#define FL_I2S_PERIPHRAL_MODE_SPI (0x0U << I2SCR_I2SMOD_Pos)
#define FL_I2S_PERIPHRAL_MODE_I2S (0x1U << I2SCR_I2SMOD_Pos)

#define FL_I2S_PRESCALER_PARITY_EVEN (0x0U << I2SPR_ODD_Pos)
#define FL_I2S_PRESCALER_PARITY_ODD (0x1U << I2SPR_ODD_Pos)

  /**
   * @}
   */
  /* Exported functions ---------------------------------------------------------------------------------*/
  /** @defgroup SPI_FL_Exported_Functions SPI Exported Functions
   * @{
   */

  /**
   * @brief    Enable SPI IO Pin Swap
   * @rmtoll   CR1    IOSWAP    FL_SPI_EnablePinSwap
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_EnablePinSwap(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->CR1, SPI_CR1_IOSWAP_Msk);
  }

  /**
   * @brief    Get SPI IO Pin Swap State
   * @rmtoll   CR1    IOSWAP    FL_SPI_IsEnabledPinSwap
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsEnabledPinSwap(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_IOSWAP_Msk) == SPI_CR1_IOSWAP_Msk);
  }

  /**
   * @brief    Disable SPI IO Pin Swap
   * @rmtoll   CR1    IOSWAP    FL_SPI_DisablePinSwap
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_DisablePinSwap(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->CR1, SPI_CR1_IOSWAP_Msk);
  }

  /**
   * @brief    Set Master Sampling Position Adjustment
   * @rmtoll   CR1    MSPA    FL_SPI_SetMasterSamplingAdjust
   * @param    SPIx SPI instance
   * @param    adjust This parameter can be one of the following values:
   *           @arg @ref FL_SPI_MASTER_SAMPLING_NORMAL
   *           @arg @ref FL_SPI_MASTER_SAMPLING_DELAY_HALFCLK
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetMasterSamplingAdjust(SPI_Type *SPIx, uint32_t adjust)
  {
    MODIFY_REG(SPIx->CR1, SPI_CR1_MSPA_Msk, adjust);
  }

  /**
   * @brief    Get Master Sampling Position Adjustment
   * @rmtoll   CR1    MSPA    FL_SPI_GetMasterSamplingAdjust
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_MASTER_SAMPLING_NORMAL
   *           @arg @ref FL_SPI_MASTER_SAMPLING_DELAY_HALFCLK
   */
  __STATIC_INLINE uint32_t FL_SPI_GetMasterSamplingAdjust(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_MSPA_Msk));
  }

  /**
   * @brief    Set Slave Sending Position Adjustment
   * @rmtoll   CR1    SSPA    FL_SPI_SetSlaveSamplingAdjust
   * @param    SPIx SPI instance
   * @param    adjust This parameter can be one of the following values:
   *           @arg @ref FL_SPI_SLAVE_SAMPLING_NORMAL
   *           @arg @ref FL_SPI_SLAVE_SAMPLING_ADVANCE_HALFCLK
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetSlaveSamplingAdjust(SPI_Type *SPIx, uint32_t adjust)
  {
    MODIFY_REG(SPIx->CR1, SPI_CR1_SSPA_Msk, adjust);
  }

  /**
   * @brief    Get Slave Sending Position Adjustment
   * @rmtoll   CR1    SSPA    FL_SPI_GetSlaveSamplingAdjust
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_SLAVE_SAMPLING_NORMAL
   *           @arg @ref FL_SPI_SLAVE_SAMPLING_ADVANCE_HALFCLK
   */
  __STATIC_INLINE uint32_t FL_SPI_GetSlaveSamplingAdjust(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_SSPA_Msk));
  }

  /**
   * @brief    Set SPI Working Mode
   * @rmtoll   CR1    MM    FL_SPI_SetWorkMode
   * @param    SPIx SPI instance
   * @param    mode This parameter can be one of the following values:
   *           @arg @ref FL_SPI_WORK_MODE_SLAVE
   *           @arg @ref FL_SPI_WORK_MODE_MASTER
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetWorkMode(SPI_Type *SPIx, uint32_t mode)
  {
    MODIFY_REG(SPIx->CR1, SPI_CR1_MM_Msk, mode);
  }

  /**
   * @brief    Get SPI Working Mode
   * @rmtoll   CR1    MM    FL_SPI_GetWorkMode
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_WORK_MODE_SLAVE
   *           @arg @ref FL_SPI_WORK_MODE_MASTER
   */
  __STATIC_INLINE uint32_t FL_SPI_GetWorkMode(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_MM_Msk));
  }

  /**
   * @brief    Set SPI Send Wait Cycle Length in Master Mode
   * @rmtoll   CR1    WAIT    FL_SPI_SetSendWait
   * @param    SPIx SPI instance
   * @param    wait This parameter can be one of the following values:
   *           @arg @ref FL_SPI_SEND_WAIT_0
   *           @arg @ref FL_SPI_SEND_WAIT_1
   *           @arg @ref FL_SPI_SEND_WAIT_2
   *           @arg @ref FL_SPI_SEND_WAIT_3
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetSendWait(SPI_Type *SPIx, uint32_t wait)
  {
    MODIFY_REG(SPIx->CR1, SPI_CR1_WAIT_Msk, wait);
  }

  /**
   * @brief    Get SPI Send Wait Cycle Length in Master Mode
   * @rmtoll   CR1    WAIT    FL_SPI_GetSendWait
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   */
  __STATIC_INLINE uint32_t FL_SPI_GetSendWait(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_WAIT_Msk));
  }

  /**
   * @brief    Set SPI Baudrate in Master Mode
   * @rmtoll   CR1    BAUD    FL_SPI_SetClockDivision
   * @param    SPIx SPI instance
   * @param    clock This parameter can be one of the following values:
   *           @arg @ref FL_SPI_CLK_DIV2
   *           @arg @ref FL_SPI_CLK_DIV4
   *           @arg @ref FL_SPI_CLK_DIV8
   *           @arg @ref FL_SPI_CLK_DIV16
   *           @arg @ref FL_SPI_CLK_DIV32
   *           @arg @ref FL_SPI_CLK_DIV64
   *           @arg @ref FL_SPI_CLK_DIV128
   *           @arg @ref FL_SPI_CLK_DIV256
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetClockDivision(SPI_Type *SPIx, uint32_t clock)
  {
    MODIFY_REG(SPIx->CR1, SPI_CR1_BAUD_Msk, clock);
  }

  /**
   * @brief    Get SPI Baudrate in Master Mode
   * @rmtoll   CR1    BAUD    FL_SPI_GetClockDivision
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_CLK_DIV2
   *           @arg @ref FL_SPI_CLK_DIV4
   *           @arg @ref FL_SPI_CLK_DIV8
   *           @arg @ref FL_SPI_CLK_DIV16
   *           @arg @ref FL_SPI_CLK_DIV32
   *           @arg @ref FL_SPI_CLK_DIV64
   *           @arg @ref FL_SPI_CLK_DIV128
   *           @arg @ref FL_SPI_CLK_DIV256
   */
  __STATIC_INLINE uint32_t FL_SPI_GetClockDivision(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_BAUD_Msk));
  }

  /**
   * @brief    Set SPI Bit Order
   * @rmtoll   CR1    LSBF    FL_SPI_SetBitOrder
   * @param    SPIx SPI instance
   * @param    bitOrder This parameter can be one of the following values:
   *           @arg @ref FL_SPI_BIT_ORDER_MSB_FIRST
   *           @arg @ref FL_SPI_BIT_ORDER_LSB_FIRST
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetBitOrder(SPI_Type *SPIx, uint32_t bitOrder)
  {
    MODIFY_REG(SPIx->CR1, SPI_CR1_LSBF_Msk, bitOrder);
  }

  /**
   * @brief    Get SPI Bit Order
   * @rmtoll   CR1    LSBF    FL_SPI_GetBitOrder
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_BIT_ORDER_MSB_FIRST
   *           @arg @ref FL_SPI_BIT_ORDER_LSB_FIRST
   */
  __STATIC_INLINE uint32_t FL_SPI_GetBitOrder(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_LSBF_Msk));
  }

  /**
   * @brief    Set SPI Clock Polarity
   * @rmtoll   CR1    CPOL    FL_SPI_SetClockPolarity
   * @param    SPIx SPI instance
   * @param    polarity This parameter can be one of the following values:
   *           @arg @ref FL_SPI_POLARITY_NORMAL
   *           @arg @ref FL_SPI_POLARITY_INVERT
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetClockPolarity(SPI_Type *SPIx, uint32_t polarity)
  {
    MODIFY_REG(SPIx->CR1, SPI_CR1_CPOL_Msk, polarity);
  }

  /**
   * @brief    Get SPI Clock Polarity
   * @rmtoll   CR1    CPOL    FL_SPI_GetClockPolarity
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_POLARITY_NORMAL
   *           @arg @ref FL_SPI_POLARITY_INVERT
   */
  __STATIC_INLINE uint32_t FL_SPI_GetClockPolarity(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_CPOL_Msk));
  }

  /**
   * @brief    Set SPI Clock Phase
   * @rmtoll   CR1    CPHA    FL_SPI_SetClockPhase
   * @param    SPIx SPI instance
   * @param    phase This parameter can be one of the following values:
   *           @arg @ref FL_SPI_PHASE_EDGE1
   *           @arg @ref FL_SPI_PHASE_EDGE2
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetClockPhase(SPI_Type *SPIx, uint32_t phase)
  {
    MODIFY_REG(SPIx->CR1, SPI_CR1_CPHA_Msk, phase);
  }

  /**
   * @brief    Get SPI Clock Phase
   * @rmtoll   CR1    CPHA    FL_SPI_GetClockPhase
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_PHASE_EDGE1
   *           @arg @ref FL_SPI_PHASE_EDGE2
   */
  __STATIC_INLINE uint32_t FL_SPI_GetClockPhase(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_CPHA_Msk));
  }

  /**
   * @brief    Enable SPI Dummy Cycle Setting Under 4-lines Half Duplex Mode
   * @rmtoll   CR2    DUMMY_EN    FL_SPI_EnableDummyCycle
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_EnableDummyCycle(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->CR2, SPI_CR2_DUMMY_EN_Msk);
  }

  /**
   * @brief    Disable SPI Dummy Cycle Setting Under 4-lines Half Duplex Mode
   * @rmtoll   CR2    DUMMY_EN    FL_SPI_DisableDummyCycle
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_DisableDummyCycle(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->CR2, SPI_CR2_DUMMY_EN_Msk);
  }

  /**
   * @brief    Get SPI Dummy Cycle Mode Setting
   * @rmtoll   CR2    DUMMY_EN    FL_SPI_IsEnabledDummyCycle
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsEnabledDummyCycle(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_DUMMY_EN_Msk) == SPI_CR2_DUMMY_EN_Msk);
  }

  /**
   * @brief    Set SPI Data LENGTH 2-4bit
   * @rmtoll   CR2    DLEN2    FL_SPI_SetLengthDataH
   * @param    SPIx SPI instance
   * @param    length This parameter can be one of the following values:
   *           @arg @ref FL_SPI_DATAH_WIDTH0
   *           @arg @ref FL_SPI_DATAH_WIDTH1
   *           @arg @ref FL_SPI_DATAH_WIDTH2
   *           @arg @ref FL_SPI_DATAH_WIDTH3
   *           @arg @ref FL_SPI_DATAH_WIDTH4
   *           @arg @ref FL_SPI_DATAH_WIDTH5
   *           @arg @ref FL_SPI_DATAH_WIDTH6
   *           @arg @ref FL_SPI_DATAH_WIDTH7
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetWidthDataH(SPI_Type *SPIx, uint32_t width)
  {
    MODIFY_REG(SPIx->CR2, SPI_CR2_DLEN2_Msk, width);
  }

  /**
   * @brief    Get SPI Data width 2-4bit
   * @rmtoll   CR2    DLEN2    FL_SPI_GetLengtDataH
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_DATAH_WIDTH0
   *           @arg @ref FL_SPI_DATAH_WIDTH1
   *           @arg @ref FL_SPI_DATAH_WIDTH2
   *           @arg @ref FL_SPI_DATAH_WIDTH3
   *           @arg @ref FL_SPI_DATAH_WIDTH4
   *           @arg @ref FL_SPI_DATAH_WIDTH5
   *           @arg @ref FL_SPI_DATAH_WIDTH6
   *           @arg @ref FL_SPI_DATAH_WIDTH7
   */
  __STATIC_INLINE uint32_t FL_SPI_GetWidthDataH(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_DLEN2_Msk));
  }

  /**
   * @brief    Set SPI Data width 0-1bit
   * @rmtoll   CR2    DLEN    FL_SPI_SetLengtDataL
   * @param    SPIx SPI instance
   * @param    width This parameter can be one of the following values:
   *           @arg @ref FL_SPI_DATAL_WIDTH0
   *           @arg @ref FL_SPI_DATAL_WIDTH1
   *           @arg @ref FL_SPI_DATAL_WIDTH2
   *           @arg @ref FL_SPI_DATAL_WIDTH3
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetWidthDataL(SPI_Type *SPIx, uint32_t width)
  {
    MODIFY_REG(SPIx->CR2, SPI_CR2_DLEN_Msk, width);
  }

  /**
   * @brief    Get SPI Data width 0-1bit
   * @rmtoll   CR2    DLEN    FL_SPI_GetLengtDataL
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_DATAL_WIDTH0
   *           @arg @ref FL_SPI_DATAL_WIDTH1
   *           @arg @ref FL_SPI_DATAL_WIDTH2
   *           @arg @ref FL_SPI_DATAL_WIDTH3
   */
  __STATIC_INLINE uint32_t FL_SPI_GetWidthDataL(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_DLEN_Msk));
  }

  /**
   * @brief    Set SPI Data width
   * @rmtoll   CR2    {DLEN2,DLEN}    FL_SPI_GetLengtData
   * @param    SPIx SPI instance
   * @param    cr2_den:
   *           @arg @ref FL_SPI_DATAL_WIDTH0
   *           @arg @ref FL_SPI_DATAL_WIDTH1
   *           @arg @ref FL_SPI_DATAL_WIDTH2
   *           @arg @ref FL_SPI_DATAL_WIDTH3
   * @param    cr2_den2:
   *           @arg @ref FL_SPI_DATAH_WIDTH0
   *           @arg @ref FL_SPI_DATAH_WIDTH1
   *           @arg @ref FL_SPI_DATAH_WIDTH2
   *           @arg @ref FL_SPI_DATAH_WIDTH3
   *           @arg @ref FL_SPI_DATAH_WIDTH4
   *           @arg @ref FL_SPI_DATAH_WIDTH5
   *           @arg @ref FL_SPI_DATAH_WIDTH6
   *           @arg @ref FL_SPI_DATAH_WIDTH7
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetDataWidth(SPI_Type *SPIx, uint32_t cr2_den, uint32_t cr2_den2)
  {
    FL_SPI_SetWidthDataL(SPIx, cr2_den);
    FL_SPI_SetWidthDataH(SPIx, cr2_den2);
  }

  /**
   * @brief    Get SPI Data width
   * @rmtoll   CR2    {DLEN2,DLEN}    FL_SPI_GetLengtData
   * @param    SPIx SPI instance
   * @param    cr2_den:
   *           @arg @ref FL_SPI_DATAL_WIDTH0
   *           @arg @ref FL_SPI_DATAL_WIDTH1
   *           @arg @ref FL_SPI_DATAL_WIDTH2
   *           @arg @ref FL_SPI_DATAL_WIDTH3
   * @param    cr2_den2:
   *           @arg @ref FL_SPI_DATAH_WIDTH0
   *           @arg @ref FL_SPI_DATAH_WIDTH1
   *           @arg @ref FL_SPI_DATAH_WIDTH2
   *           @arg @ref FL_SPI_DATAH_WIDTH3
   *           @arg @ref FL_SPI_DATAH_WIDTH4
   *           @arg @ref FL_SPI_DATAH_WIDTH5
   *           @arg @ref FL_SPI_DATAH_WIDTH6
   *           @arg @ref FL_SPI_DATAH_WIDTH7
   * @retval   None
   */
  __STATIC_INLINE uint32_t FL_SPI_GetDataWidth(SPI_Type *SPIx)
  {
    uint32_t datawith_l = 0;
    uint32_t datawith_h = 0;
    uint32_t datawith = 0;

    datawith_l = (SPIx->CR2 >> 9) & 0x3;
    datawith_h = (SPIx->CR2 >> 12) & 0x7;
    datawith = (datawith_l + 1) * 8 - datawith_h;

    return datawith;
  }

  /**
   * @brief    Enable SPI Receive Only Mode
   * @rmtoll   CR2    RXO    FL_SPI_EnableRXOnlyMode
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_EnableRXOnlyMode(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->CR2, SPI_CR2_RXO_Msk);
  }

  /**
   * @brief    Disable SPI Receive Only Mode Setting
   * @rmtoll   CR2    RXO    FL_SPI_DisableRXOnlyMode
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_DisableRXOnlyMode(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->CR2, SPI_CR2_RXO_Msk);
  }

  /**
   * @brief    Get SPI Receive Only Mode state
   * @rmtoll   CR2    RXO    FL_SPI_IsEnabledRXOnlyMode
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsEnabledRXOnlyMode(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_RXO_Msk) == SPI_CR2_RXO_Msk);
  }

  /**
   * @brief    Set SPI Transfer Mode
   * @rmtoll   CR2    HALFDUPLEX    FL_SPI_SetTransferMode
   * @param    SPIx SPI instance
   * @param    mode This parameter can be one of the following values:
   *           @arg @ref FL_SPI_TRANSFER_MODE_FULL_DUPLEX
   *           @arg @ref FL_SPI_TRANSFER_MODE_HALF_DUPLEX
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetTransferMode(SPI_Type *SPIx, uint32_t mode)
  {
    MODIFY_REG(SPIx->CR2, SPI_CR2_HALFDUPLEX_Msk, mode);
  }

  /**
   * @brief    Get SPI Transfer Mode
   * @rmtoll   CR2    HALFDUPLEX    FL_SPI_GetTransferMode
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_TRANSFER_MODE_FULL_DUPLEX
   *           @arg @ref FL_SPI_TRANSFER_MODE_HALF_DUPLEX
   */
  __STATIC_INLINE uint32_t FL_SPI_GetTransferMode(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_HALFDUPLEX_Msk));
  }

  /**
   * @brief    Set SPI Transfer Direction Under Half-Duplex Mode
   * @rmtoll   CR2    HD_RW    FL_SPI_SetTransferDirection
   * @param    SPIx SPI instance
   * @param    direction This parameter can be one of the following values:
   *           @arg @ref FL_SPI_HALF_DUPLEX_TX
   *           @arg @ref FL_SPI_HALF_DUPLEX_RX
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetTransferDirection(SPI_Type *SPIx, uint32_t direction)
  {
    MODIFY_REG(SPIx->CR2, SPI_CR2_HD_RW_Msk, direction);
  }

  /**
   * @brief    Get SPI Transfer Direction Under Half-Duplex Mode
   * @rmtoll   CR2    HD_RW    FL_SPI_GetTransferDirection
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_HALF_DUPLEX_TX
   *           @arg @ref FL_SPI_HALF_DUPLEX_RX
   */
  __STATIC_INLINE uint32_t FL_SPI_GetTransferDirection(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_HD_RW_Msk));
  }

  /**
   * @brief    Set Command Frame Length Under Half-Duplex Mode
   * @rmtoll   CR2    CMD8B    FL_SPI_SetHalfDuplexCommandLength
   * @param    SPIx SPI instance
   * @param    mode This parameter can be one of the following values:
   *           @arg @ref FL_SPI_HALF_DUPLEX_CMDLEN_DLEN
   *           @arg @ref FL_SPI_HALF_DUPLEX_CMDLEN_8B
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetHalfDuplexCommandLength(SPI_Type *SPIx, uint32_t mode)
  {
    MODIFY_REG(SPIx->CR2, SPI_CR2_CMD8B_Msk, mode);
  }

  /**
   * @brief    Get Command Frame Length Under Half-Duplex Mode
   * @rmtoll   CR2    CMD8B    FL_SPI_GetHalfDuplexCommandLength
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_HALFDUPLEX_CMDLEN_DLEN
   *           @arg @ref FL_SPI_HALFDUPLEX_CMDLEN_8B
   */
  __STATIC_INLINE uint32_t FL_SPI_GetHalfDuplexCommandLength(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_CMD8B_Msk));
  }

  /**
   * @brief    Set SPI SSN Hard Pin Mode
   * @rmtoll   CR2    SSNM    FL_SPI_SetHardwareSSNMode
   * @param    SPIx SPI instance
   * @param    mode This parameter can be one of the following values:
   *           @arg @ref FL_SPI_HARDWARE_SSN_KEEP_LOW
   *           @arg @ref FL_SPI_HARDWARE_SSN_AUTO_HIGH
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetHardwareSSNMode(SPI_Type *SPIx, uint32_t mode)
  {
    MODIFY_REG(SPIx->CR2, SPI_CR2_SSNM_Msk, mode);
  }

  /**
   * @brief    Get SPI SSN Hard Pin Mode
   * @rmtoll   CR2    SSNM    FL_SPI_GetHardwareSSNMode
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_HARDWARE_SSN_KEEP_LOW
   *           @arg @ref FL_SPI_HARDWARE_SSN_AUTO_HIGH
   */
  __STATIC_INLINE uint32_t FL_SPI_GetHardwareSSNMode(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_SSNM_Msk));
  }

  /**
   * @brief    Enabel TX Only Mode Auto Clear
   * @rmtoll   CR2    TXO_AC    FL_SPI_EnableTXOnlyModeAutoClear
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_EnableTXOnlyModeAutoClear(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->CR2, SPI_CR2_TXO_AC_Msk);
  }

  /**
   * @brief    Disable TX Only Mode Auto Clear
   * @rmtoll   CR2    TXO_AC    FL_SPI_DisableTXOnlyModeAutoClear
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_DisableTXOnlyModeAutoClear(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->CR2, SPI_CR2_TXO_AC_Msk);
  }

  /**
   * @brief    Get TX Only Mode Auto Clear Setting
   * @rmtoll   CR2    TXO_AC    FL_SPI_IsEnabledTXOnlyModeAutoClear
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsEnabledTXOnlyModeAutoClear(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_TXO_AC_Msk) == SPI_CR2_TXO_AC_Msk);
  }

  /**
   * @brief    EnableSPI TX Only Mode
   * @rmtoll   CR2    TXO    FL_SPI_EnableTXOnlyMode
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_EnableTXOnlyMode(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->CR2, SPI_CR2_TXO_Msk);
  }

  /**
   * @brief    DisableSPI TX Only Mode
   * @rmtoll   CR2    TXO    FL_SPI_DisableTXOnlyMode
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_DisableTXOnlyMode(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->CR2, SPI_CR2_TXO_Msk);
  }

  /**
   * @brief    Get SPI TX Only Mode Setting State
   * @rmtoll   CR2    TXO    FL_SPI_IsEnabledTXOnlyMode
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsEnabledTXOnlyMode(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_TXO_Msk) == SPI_CR2_TXO_Msk);
  }

  /**
   * @brief    Set SSN Pin
   * @rmtoll   CR2    SSN    FL_SPI_SetSSNPin
   * @param    SPIx SPI instance
   * @param    state This parameter can be one of the following values:
   *           @arg @ref FL_SPI_SSN_LOW
   *           @arg @ref FL_SPI_SSN_HIGH
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetSSNPin(SPI_Type *SPIx, uint32_t state)
  {
    MODIFY_REG(SPIx->CR2, SPI_CR2_SSN_Msk, state);
  }

  /**
   * @brief    Reset SSN Pin
   * @rmtoll   CR2    SSN    FL_SPI_GetSSNPin
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_SSN_LOW
   *           @arg @ref FL_SPI_SSN_HIGH
   */
  __STATIC_INLINE uint32_t FL_SPI_GetSSNPin(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_SSN_Msk));
  }

  /**
   * @brief    Enable SNN Sofe Control Under Master Mode
   * @rmtoll   CR2    SSNSEN    FL_SPI_EnableSSNSoftControl
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_EnableSSNSoftControl(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->CR2, SPI_CR2_SSNSEN_Msk);
  }

  /**
   * @brief    Get SNN Sofe Control State Under Master Mode
   * @rmtoll   CR2    SSNSEN    FL_SPI_IsEnabledSSNSoftControl
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsEnabledSSNSoftControl(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_SSNSEN_Msk) == SPI_CR2_SSNSEN_Msk);
  }

  /**
   * @brief    Disable SNN Sofe Control Under Master Mode
   * @rmtoll   CR2    SSNSEN    FL_SPI_DisableSSNSoftControl
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_DisableSSNSoftControl(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->CR2, SPI_CR2_SSNSEN_Msk);
  }

  /**
   * @brief    Enable SPI
   * @rmtoll   CR2    SPIEN    FL_SPI_Enable
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_Enable(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->CR2, SPI_CR2_SPIEN_Msk);
  }

  /**
   * @brief    Get SPI Enable Status
   * @rmtoll   CR2    SPIEN    FL_SPI_IsEnabled
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsEnabled(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_SPIEN_Msk) == SPI_CR2_SPIEN_Msk);
  }

  /**
   * @brief    Disable SPI
   * @rmtoll   CR2    SPIEN    FL_SPI_Disable
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_Disable(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->CR2, SPI_CR2_SPIEN_Msk);
  }

  /**
   * @brief    Read SPI TX Buffer
   * @rmtoll   CR3    TXBFC    FL_SPI_GetTXBuffState
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   */
  __STATIC_INLINE uint32_t FL_SPI_GetTXBuffState(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR3, SPI_CR3_TXBFC_Msk));
  }

  /**
   * @brief    Clear SPI TX Buffer
   * @rmtoll   CR3    TXBFC    FL_SPI_ClearTXBuff
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_ClearTXBuff(SPI_Type *SPIx)
  {
    WRITE_REG(SPIx->CR3, SPI_CR3_TXBFC_Msk);
  }

  /**
   * @brief    Read SPI RX Buffer
   * @rmtoll   CR3    RXBFC    FL_SPI_GetRXBuffState
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   */
  __STATIC_INLINE uint32_t FL_SPI_GetRXBuffState(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR3, SPI_CR3_RXBFC_Msk));
  }

  /**
   * @brief    Clear SPI RX Buffer
   * @rmtoll   CR3    RXBFC    FL_SPI_ClearRXBuff
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_ClearRXBuff(SPI_Type *SPIx)
  {
    WRITE_REG(SPIx->CR3, SPI_CR3_RXBFC_Msk);
  }

  /**
   * @brief    Read SPI Master Error Flag
   * @rmtoll   CR3    MERRC    FL_SPI_GetMasterError
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   */
  __STATIC_INLINE uint32_t FL_SPI_GetMasterError(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR3, SPI_CR3_MERRC_Msk));
  }

  /**
   * @brief    Clear SPI Master Error Flag
   * @rmtoll   CR3    MERRC    FL_SPI_ClearFlag_MasterError
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_ClearFlag_MasterError(SPI_Type *SPIx)
  {
    WRITE_REG(SPIx->CR3, SPI_CR3_MERRC_Msk);
  }

  /**
   * @brief    Read SPI Slave Error Flag
   * @rmtoll   CR3    SERRC    FL_SPI_GetSlaveError
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   */
  __STATIC_INLINE uint32_t FL_SPI_GetSlaveError(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->CR3, SPI_CR3_SERRC_Msk));
  }

  /**
   * @brief    Clear SPI Slave Error Flag
   * @rmtoll   CR3    SERRC    FL_SPI_ClearFlag_SlaveError
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_ClearFlag_SlaveError(SPI_Type *SPIx)
  {
    WRITE_REG(SPIx->CR3, SPI_CR3_SERRC_Msk);
  }

  /**
   * @brief    Disable SPI Slave SSN Rise Interrupt
   * @rmtoll   IER    SSNRIE    FL_SPI_DisableIT_SlaveSSNRise
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_DisableIT_SlaveSSNRise(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->IER, SPI_IER_SSNRIE_Msk);
  }

  /**
   * @brief    Enable SPI Slave SSN Rise Interrupt
   * @rmtoll   IER    SSNRIE    FL_SPI_EnableIT_SlaveSSNRise
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_EnableIT_SlaveSSNRise(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->IER, SPI_IER_SSNRIE_Msk);
  }

  /**
   * @brief    Get SPI Slave SSN Rise Interrupt Enable Status
   * @rmtoll   IER    SSNRIE    FL_SPI_IsEnabledIT_SlaveSSNRise
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsEnabledIT_SlaveSSNRise(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->IER, SPI_IER_SSNRIE_Msk) == SPI_IER_SSNRIE_Msk);
  }

  /**
   * @brief    Disable SPI Slave SSN Fall Interrupt
   * @rmtoll   IER    SSNFIE    FL_SPI_DisableIT_SlaveSSNFall
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_DisableIT_SlaveSSNFall(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->IER, SPI_IER_SSNFIE_Msk);
  }

  /**
   * @brief    Enable SPI Slave SSN Fall Interrupt
   * @rmtoll   IER    SSNFIE    FL_SPI_EnableIT_SlaveSSNFall
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_EnableIT_SlaveSSNFall(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->IER, SPI_IER_SSNFIE_Msk);
  }

  /**
   * @brief    Get SPI Slave SSN Fall Interrupt Enable Status
   * @rmtoll   IER    SSNFIE    FL_SPI_IsEnabledIT_SlaveSSNFall
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsEnabledIT_SlaveSSNFall(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->IER, SPI_IER_SSNFIE_Msk) == SPI_IER_SSNFIE_Msk);
  }

  /**
   * @brief    Disable SPI Transmit Shift Empty Interrupt
   * @rmtoll   IER    TXSEIE    FL_SPI_DisableIT_TXShiftEmptyComplete
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_DisableIT_TXShiftEmptyComplete(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->IER, SPI_IER_TXSEIE_Msk);
  }

  /**
   * @brief    Enable SPI Transmit Shift Empty Interrupt
   * @rmtoll   IER    TXSEIE    FL_SPI_EnableIT_TXShiftEmptyComplete
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_EnableIT_TXShiftEmptyComplete(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->IER, SPI_IER_TXSEIE_Msk);
  }

  /**
   * @brief    Get SPI Transmit Shift Empty Interrupt Enable Status
   * @rmtoll   IER    TXSEIE    FL_SPI_IsEnabledIT_TXShiftEmptyComplete
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsEnabledIT_TXShiftEmptyComplete(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->IER, SPI_IER_TXSEIE_Msk) == SPI_IER_TXSEIE_Msk);
  }

  /**
   * @brief    Disable SPI Error Interrupt
   * @rmtoll   IER    ERRIE    FL_SPI_DisableIT_Error
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_DisableIT_Error(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->IER, SPI_IER_ERRIE_Msk);
  }

  /**
   * @brief    Enable SPI Error Interrupt
   * @rmtoll   IER    ERRIE    FL_SPI_EnableIT_Error
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_EnableIT_Error(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->IER, SPI_IER_ERRIE_Msk);
  }

  /**
   * @brief    Get SPI Error Interrupt Enable Status
   * @rmtoll   IER    ERRIE    FL_SPI_IsEnabledIT_Error
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsEnabledIT_Error(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->IER, SPI_IER_ERRIE_Msk) == SPI_IER_ERRIE_Msk);
  }

  /**
   * @brief    Disable SPI Transmit Buffer Empty Interrupt
   * @rmtoll   IER    TXBEIE    FL_SPI_DisableIT_TXBufferEmptyComplete
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_DisableIT_TXBufferEmptyComplete(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->IER, SPI_IER_TXBEIE_Msk);
  }

  /**
   * @brief    Enable SPI Transmit Buffer Empty Interrupt
   * @rmtoll   IER    TXBEIE    FL_SPI_EnableIT_TXBufferEmptyComplete
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_EnableIT_TXBufferEmptyComplete(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->IER, SPI_IER_TXBEIE_Msk);
  }

  /**
   * @brief    Get SPI Transmit Buffer Empty Interrupt Enable Status
   * @rmtoll   IER    TXBEIE    FL_SPI_IsEnabledIT_TXBufferEmptyComplete
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsEnabledIT_TXBufferEmptyComplete(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->IER, SPI_IER_TXBEIE_Msk) == SPI_IER_TXBEIE_Msk);
  }

  /**
   * @brief    Disable SPI Receive Complete Interrupt
   * @rmtoll   IER    RXIE    FL_SPI_DisableIT_RXComplete
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_DisableIT_RXComplete(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->IER, SPI_IER_RXIE_Msk);
  }

  /**
   * @brief    Enable SPI Receive Complete Interrupt
   * @rmtoll   IER    RXIE    FL_SPI_EnableIT_RXComplete
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_EnableIT_RXComplete(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->IER, SPI_IER_RXIE_Msk);
  }

  /**
   * @brief    Get SPI Receive Complete Interrupt Enable Status
   * @rmtoll   IER    RXIE    FL_SPI_IsEnabledIT_RXComplete
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsEnabledIT_RXComplete(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->IER, SPI_IER_RXIE_Msk) == SPI_IER_RXIE_Msk);
  }

  /**
   * @brief    Set SPI Output Data/Command Under Half-Duplex Mode
   * @rmtoll   ISR    DCN_TX    FL_SPI_SetFrameMode
   * @param    SPIx SPI instance
   * @param    mode This parameter can be one of the following values:
   *           @arg @ref FL_SPI_FRAME_MODE_CMD
   *           @arg @ref FL_SPI_FRAME_MODE_DATA
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_SetFrameMode(SPI_Type *SPIx, uint32_t mode)
  {
    MODIFY_REG(SPIx->ISR, SPI_ISR_DCN_TX_Msk, mode);
  }

  /**
   * @brief    Get SPI Output Data/Command Under Half-Duplex Mode Setting
   * @rmtoll   ISR    DCN_TX    FL_SPI_GetFrameMode
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_FRAME_MODE_CMD
   *           @arg @ref FL_SPI_FRAME_MODE_DATA
   */
  __STATIC_INLINE uint32_t FL_SPI_GetFrameMode(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_DCN_TX_Msk));
  }

  /**
   * @brief    Get SPI Receive Collision Flag
   * @rmtoll   ISR    RXCOL    FL_SPI_IsActiveFlag_RXBuffOverflow
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsActiveFlag_RXBuffOverflow(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_RXCOL_Msk) == (SPI_ISR_RXCOL_Msk));
  }

  /**
   * @brief    Clear SPI Receive Collision Flag
   * @rmtoll   ISR    RXCOL    FL_SPI_ClearFlag_RXBuffOverflow
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_ClearFlag_RXBuffOverflow(SPI_Type *SPIx)
  {
    WRITE_REG(SPIx->ISR, SPI_ISR_RXCOL_Msk);
  }

  /**
   * @brief    Get SPI Transmit Collision Flag
   * @rmtoll   ISR    TXCOL    FL_SPI_IsActiveFlag_TXBuffOverflow
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsActiveFlag_TXBuffOverflow(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_TXCOL_Msk) == (SPI_ISR_TXCOL_Msk));
  }

  /**
   * @brief    Clear SPI Transmit Collision Flag
   * @rmtoll   ISR    TXCOL    FL_SPI_ClearFlag_TXBuffOverflow
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_ClearFlag_TXBuffOverflow(SPI_Type *SPIx)
  {
    WRITE_REG(SPIx->ISR, SPI_ISR_TXCOL_Msk);
  }

  /**
   * @brief    Get SPI Busy Flag
   * @rmtoll   ISR    BUSY    FL_SPI_IsActiveFlag_Busy
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsActiveFlag_Busy(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_BUSY_Msk) == (SPI_ISR_BUSY_Msk));
  }

  /**
   * @brief    Get SPI Vocal Tract Flag
   * @rmtoll   ISR    CHSIDE    FL_I2S_GetVocalTract
   * @param    SPIx SPI instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_SPI_VOCAL_TRACT_LEFT
   *           @arg @ref FL_SPI_VOCAL_TRACT_RIGHT
   */
  __STATIC_INLINE uint32_t FL_SPI_GetVocalTract(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_CHSIDE_Msk));
  }

  /**
   * @brief    Get SPI Master Error Flag
   * @rmtoll   ISR    MERR    FL_SPI_IsActiveFlag_MasterError
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsActiveFlag_MasterError(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_MERR_Msk) == (SPI_ISR_MERR_Msk));
  }

  /**
   * @brief    Get SPI Slave Error Flag
   * @rmtoll   ISR    SERR    FL_SPI_IsActiveFlag_SlaveError
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsActiveFlag_SlaveError(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_SERR_Msk) == (SPI_ISR_SERR_Msk));
  }

  /**
   * @brief    Get SPI Slave SSN Rise Flag
   * @rmtoll   ISR    SSNR    FL_SPI_IsActiveFlag_SlaveSSNRise
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsActiveFlag_SlaveSSNRise(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_SSNR_Msk) == (SPI_ISR_SSNR_Msk));
  }

  /**
   * @brief    Clear SPI Slave SSN Rise Flag
   * @rmtoll   ISR    SSNR    FL_SPI_ClearFlag_SlaveSSNRise
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_ClearFlag_SlaveSSNRise(SPI_Type *SPIx)
  {
    WRITE_REG(SPIx->ISR, SPI_ISR_SSNR_Msk);
  }

  /**
   * @brief    Get SPI Slave SSN Fall Flag
   * @rmtoll   ISR    SSNF    FL_SPI_IsActiveFlag_SlaveSSNFall
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsActiveFlag_SlaveSSNFall(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_SSNF_Msk) == (SPI_ISR_SSNF_Msk));
  }

  /**
   * @brief    Clear SPI Slave SSN Fall Flag
   * @rmtoll   ISR    SSNF    FL_SPI_ClearFlag_SlaveSSNFall
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_ClearFlag_SlaveSSNFall(SPI_Type *SPIx)
  {
    WRITE_REG(SPIx->ISR, SPI_ISR_SSNF_Msk);
  }

  /**
   * @brief    Get SPI TX Shift Empty Flag
   * @rmtoll   ISR    TXSE    FL_SPI_IsActiveFlag_TXShiftEmpty
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsActiveFlag_TXShiftEmpty(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_TXSE_Msk) == (SPI_ISR_TXSE_Msk));
  }

  /**
   * @brief    Clear TX Shift Empty Flag
   * @rmtoll   ISR    TXSE    FL_SPI_ClearFlag_TXShiftEmpty
   * @param    SPIx SPI instance
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_ClearFlag_TXShiftEmpty(SPI_Type *SPIx)
  {
    WRITE_REG(SPIx->ISR, SPI_ISR_TXSE_Msk);
  }

  /**
   * @brief    Get SPI TX Buffer Empty Flag
   * @rmtoll   ISR    TXBE    FL_SPI_IsActiveFlag_TXBuffEmpty
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsActiveFlag_TXBuffEmpty(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_TXBE_Msk) == (SPI_ISR_TXBE_Msk));
  }

  /**
   * @brief    Get SPI RX Buffer Full Flag
   * @rmtoll   ISR    RXBF    FL_SPI_IsActiveFlag_RXBuffFull
   * @param    SPIx SPI instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_SPI_IsActiveFlag_RXBuffFull(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_RXBF_Msk) == (SPI_ISR_RXBF_Msk));
  }

  /**
   * @brief    Write SPI TX Buffer
   * @rmtoll   TXBUF        FL_SPI_WriteTXBuff
   * @param    SPIx SPI instance
   * @param    data
   * @retval   None
   */
  __STATIC_INLINE void FL_SPI_WriteTXBuff(SPI_Type *SPIx, uint32_t data)
  {
    MODIFY_REG(SPIx->TXBUF, (0xffffffffU << 0U), (data << 0U));
  }

  /**
   * @brief    Read SPI TX Buffer
   * @rmtoll   RXBUF        FL_SPI_ReadRXBuff
   * @param    SPIx SPI instance
   * @retval
   */
  __STATIC_INLINE uint32_t FL_SPI_ReadRXBuff(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->RXBUF, (0xffffffffU << 0U)) >> 0U);
  }

  /**
   * @brief    Disable I2S Slave SSN Rise Interrupt
   * @rmtoll   IER    SSNRIE    FL_I2S_DisableIT_SlaveSSNRise
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_DisableIT_SlaveSSNRise(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->IER, I2S_IER_SSNRIE_Msk);
  }

  /**
   * @brief    Enable I2S Slave SSN Rise Interrupt
   * @rmtoll   IER    SSNRIE    FL_I2S_EnableIT_SlaveSSNRise
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_EnableIT_SlaveSSNRise(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->IER, I2S_IER_SSNRIE_Msk);
  }

  /**
   * @brief    Get I2S Slave SSN Rise Interrupt Enable Status
   * @rmtoll   IER    SSNRIE    FL_I2S_IsEnabledIT_SlaveSSNRise
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsEnabledIT_SlaveSSNRise(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->IER, I2S_IER_SSNRIE_Msk) == I2S_IER_SSNRIE_Msk);
  }

  /**
   * @brief    Disable I2S Slave SSN Fall Interrupt
   * @rmtoll   IER    SSNFIE    FL_I2S_DisableIT_SlaveSSNFall
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_DisableIT_SlaveSSNFall(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->IER, I2S_IER_SSNFIE_Msk);
  }

  /**
   * @brief    Enable I2S Slave SSN Fall Interrupt
   * @rmtoll   IER    SSNFIE    FL_I2S_EnableIT_SlaveSSNFall
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_EnableIT_SlaveSSNFall(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->IER, I2S_IER_SSNFIE_Msk);
  }

  /**
   * @brief    Get I2S Slave SSN Fall Interrupt Enable Status
   * @rmtoll   IER    SSNFIE    FL_I2S_IsEnabledIT_SlaveSSNFall
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsEnabledIT_SlaveSSNFall(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->IER, I2S_IER_SSNFIE_Msk) == I2S_IER_SSNFIE_Msk);
  }

  /**
   * @brief    Disable I2S Transmit Shift Empty Interrupt
   * @rmtoll   IER    TXSEIE    FL_I2S_DisableIT_TXShiftEmptyComplete
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_DisableIT_TXShiftEmptyComplete(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->IER, I2S_IER_TXSEIE_Msk);
  }

  /**
   * @brief    Enable I2S Transmit Shift Empty Interrupt
   * @rmtoll   IER    TXSEIE    FL_I2S_EnableIT_TXShiftEmptyComplete
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_EnableIT_TXShiftEmptyComplete(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->IER, I2S_IER_TXSEIE_Msk);
  }

  /**
   * @brief    Get I2S Transmit Shift Empty Interrupt Enable Status
   * @rmtoll   IER    TXSEIE    FL_I2S_IsEnabledIT_TXShiftEmptyComplete
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsEnabledIT_TXShiftEmptyComplete(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->IER, I2S_IER_TXSEIE_Msk) == I2S_IER_TXSEIE_Msk);
  }

  /**
   * @brief    Disable I2S Error Interrupt
   * @rmtoll   IER    ERRIE    FL_I2S_DisableIT_Error
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_DisableIT_Error(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->IER, I2S_IER_ERRIE_Msk);
  }

  /**
   * @brief    Enable I2S Error Interrupt
   * @rmtoll   IER    ERRIE    FL_I2S_EnableIT_Error
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_EnableIT_Error(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->IER, I2S_IER_ERRIE_Msk);
  }

  /**
   * @brief    Get I2S Error Interrupt Enable Status
   * @rmtoll   IER    ERRIE    FL_I2S_IsEnabledIT_Error
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsEnabledIT_Error(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->IER, I2S_IER_ERRIE_Msk) == I2S_IER_ERRIE_Msk);
  }

  /**
   * @brief    Disable I2S Transmit Buffer Empty Interrupt
   * @rmtoll   IER    TXBEIE    FL_I2S_DisableIT_TXBufferEmptyComplete
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_DisableIT_TXBufferEmptyComplete(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->IER, I2S_IER_TXBEIE_Msk);
  }

  /**
   * @brief    Enable I2S Transmit Buffer Empty Interrupt
   * @rmtoll   IER    TXBEIE    FL_I2S_EnableIT_TXBufferEmptyComplete
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_EnableIT_TXBufferEmptyComplete(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->IER, I2S_IER_TXBEIE_Msk);
  }

  /**
   * @brief    Get I2S Transmit Buffer Empty Interrupt Enable Status
   * @rmtoll   IER    TXBEIE    FL_I2S_IsEnabledIT_TXBufferEmptyComplete
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsEnabledIT_TXBufferEmptyComplete(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->IER, I2S_IER_TXBEIE_Msk) == I2S_IER_TXBEIE_Msk);
  }

  /**
   * @brief    Disable I2S Receive Complete Interrupt
   * @rmtoll   IER    RXIE    FL_I2S_DisableIT_RXComplete
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_DisableIT_RXComplete(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->IER, I2S_IER_RXIE_Msk);
  }

  /**
   * @brief    Enable I2S Receive Complete Interrupt
   * @rmtoll   IER    RXIE    FL_I2S_EnableIT_RXComplete
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_EnableIT_RXComplete(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->IER, I2S_IER_RXIE_Msk);
  }

  /**
   * @brief    Get I2S Receive Complete Interrupt Enable Status
   * @rmtoll   IER    RXIE    FL_I2S_IsEnabledIT_RXComplete
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsEnabledIT_RXComplete(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->IER, I2S_IER_RXIE_Msk) == I2S_IER_RXIE_Msk);
  }

  /**
   * @brief    Set I2S Output Data/Command Under Half-Duplex Mode
   * @rmtoll   ISR    DCN_TX    FL_I2S_SetFrameMode
   * @param    I2Sx I2S instance
   * @param    mode This parameter can be one of the following values:
   *           @arg @ref FL_I2S_FRAME_MODE_CMD
   *           @arg @ref FL_I2S_FRAME_MODE_DATA
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_SetFrameMode(SPI_Type *SPIx, uint32_t mode)
  {
    MODIFY_REG(SPIx->ISR, I2S_ISR_DCN_TX_Msk, mode);
  }

  /**
   * @brief    Get I2S Output Data/Command Under Half-Duplex Mode Setting
   * @rmtoll   ISR    DCN_TX    FL_I2S_GetFrameMode
   * @param    I2Sx I2S instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_I2S_FRAME_MODE_CMD
   *           @arg @ref FL_I2S_FRAME_MODE_DATA
   */
  __STATIC_INLINE uint32_t FL_I2S_GetFrameMode(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, I2S_ISR_DCN_TX_Msk));
  }

  /**
   * @brief    Get I2S Receive Collision Flag
   * @rmtoll   ISR    RXCOL    FL_I2S_IsActiveFlag_RXBuffOverflow
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsActiveFlag_RXBuffOverflow(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, I2S_ISR_RXCOL_Msk) == (I2S_ISR_RXCOL_Msk));
  }

  /**
   * @brief    Clear I2S Receive Collision Flag
   * @rmtoll   ISR    RXCOL    FL_I2S_ClearFlag_RXBuffOverflow
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_ClearFlag_RXBuffOverflow(SPI_Type *SPIx)
  {
    WRITE_REG(SPIx->ISR, I2S_ISR_RXCOL_Msk);
  }

  /**
   * @brief    Get I2S Transmit Collision Flag
   * @rmtoll   ISR    TXCOL    FL_I2S_IsActiveFlag_TXBuffOverflow
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsActiveFlag_TXBuffOverflow(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, I2S_ISR_TXCOL_Msk) == (I2S_ISR_TXCOL_Msk));
  }

  /**
   * @brief    Clear I2S Transmit Collision Flag
   * @rmtoll   ISR    TXCOL    FL_I2S_ClearFlag_TXBuffOverflow
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_ClearFlag_TXBuffOverflow(SPI_Type *SPIx)
  {
    WRITE_REG(SPIx->ISR, I2S_ISR_TXCOL_Msk);
  }

  /**
   * @brief    Get I2S Busy Flag
   * @rmtoll   ISR    BUSY    FL_I2S_IsActiveFlag_Busy
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsActiveFlag_Busy(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, I2S_ISR_BUSY_Msk) == (I2S_ISR_BUSY_Msk));
  }

  /**
   * @brief    Get I2S Vocal Tract Flag
   * @rmtoll   ISR    CHSIDE    FL_I2S_GetVocalTract
   * @param    I2Sx I2S instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_I2S_VOCAL_TRACT_LEFT
   *           @arg @ref FL_I2S_VOCAL_TRACT_RIGHT
   */
  __STATIC_INLINE uint32_t FL_I2S_GetVocalTract(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, I2S_ISR_CHSIDE_Msk) == (I2S_ISR_CHSIDE_Msk));
  }

  /**
   * @brief    Get I2S Master Error Flag
   * @rmtoll   ISR    MERR    FL_I2S_IsActiveFlag_MasterError
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsActiveFlag_MasterError(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, I2S_ISR_MERR_Msk) == (I2S_ISR_MERR_Msk));
  }

  /**
   * @brief    Get I2S Slave Error Flag
   * @rmtoll   ISR    SERR    FL_I2S_IsActiveFlag_SlaveError
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsActiveFlag_SlaveError(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, I2S_ISR_SERR_Msk) == (I2S_ISR_SERR_Msk));
  }

  /**
   * @brief    Get I2S Slave SSN Rise Flag
   * @rmtoll   ISR    SSNR    FL_I2S_IsActiveFlag_SlaveSSNRise
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsActiveFlag_SlaveSSNRise(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, I2S_ISR_SSNR_Msk) == (I2S_ISR_SSNR_Msk));
  }

  /**
   * @brief    Clear I2S Slave SSN Rise Flag
   * @rmtoll   ISR    SSNR    FL_I2S_ClearFlag_SlaveSSNRise
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_ClearFlag_SlaveSSNRise(SPI_Type *SPIx)
  {
    WRITE_REG(SPIx->ISR, I2S_ISR_SSNR_Msk);
  }

  /**
   * @brief    Get I2S Slave SSN Fall Flag
   * @rmtoll   ISR    SSNF    FL_I2S_IsActiveFlag_SlaveSSNFall
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsActiveFlag_SlaveSSNFall(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, I2S_ISR_SSNF_Msk) == (I2S_ISR_SSNF_Msk));
  }

  /**
   * @brief    Clear I2S Slave SSN Fall Flag
   * @rmtoll   ISR    SSNF    FL_I2S_ClearFlag_SlaveSSNFall
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_ClearFlag_SlaveSSNFall(SPI_Type *SPIx)
  {
    WRITE_REG(SPIx->ISR, I2S_ISR_SSNF_Msk);
  }

  /**
   * @brief    Get I2S TX Shift Empty Flag
   * @rmtoll   ISR    TXSE    FL_I2S_IsActiveFlag_TXShiftEmpty
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsActiveFlag_TXShiftEmpty(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, I2S_ISR_TXSE_Msk) == (I2S_ISR_TXSE_Msk));
  }

  /**
   * @brief    Clear TX Shift Empty Flag
   * @rmtoll   ISR    TXSE    FL_I2S_ClearFlag_TXShiftEmpty
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_ClearFlag_TXShiftEmpty(SPI_Type *SPIx)
  {
    WRITE_REG(SPIx->ISR, I2S_ISR_TXSE_Msk);
  }

  /**
   * @brief    Get I2S TX Buffer Empty Flag
   * @rmtoll   ISR    TXBE    FL_I2S_IsActiveFlag_TXBuffEmpty
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsActiveFlag_TXBuffEmpty(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, I2S_ISR_TXBE_Msk) == (I2S_ISR_TXBE_Msk));
  }

  /**
   * @brief    Get I2S RX Buffer Full Flag
   * @rmtoll   ISR    RXBF    FL_I2S_IsActiveFlag_RXBuffFull
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsActiveFlag_RXBuffFull(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->ISR, I2S_ISR_RXBF_Msk) == (I2S_ISR_RXBF_Msk));
  }

  /**
   * @brief    Write I2S TX Buffer
   * @rmtoll   TXBUF        FL_I2S_WriteTXBuff
   * @param    I2Sx I2S instance
   * @param    data
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_WriteTXBuff(SPI_Type *SPIx, uint32_t data)
  {
    MODIFY_REG(SPIx->TXBUF, (0xffffffffU << 0U), (data << 0U));
  }

  /**
   * @brief    Read I2S TX Buffer
   * @rmtoll   RXBUF        FL_I2S_ReadRXBuff
   * @param    I2Sx I2S instance
   * @retval
   */
  __STATIC_INLINE uint32_t FL_I2S_ReadRXBuff(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->RXBUF, (0xffffffffU << 0U)) >> 0U);
  }

  /**
   * @brief    Set I2S Standard
   * @rmtoll   I2SCR    I2SSTD    FL_I2S_SetStandardMode
   * @param    I2Sx I2S instance
   * @param    standard This parameter can be one of the following values:
   *           @arg @ref FL_I2S_STANDARD_MODE_PHILIPS
   *           @arg @ref FL_I2S_STANDARD_MODE_MSB_JUSTIFIED
   *           @arg @ref FL_I2S_STANDARD_MODE_LSB_JUSTIFIED
   *           @arg @ref FL_I2S_STANDARD_MODE_PCM
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_SetStandardMode(SPI_Type *SPIx, uint32_t standard)
  {
    MODIFY_REG(SPIx->I2SCR, I2SCR_I2SSTD_Msk, standard);
  }

  /**
   * @brief    Get I2S Standard
   * @rmtoll   I2SCR    I2SSTD    FL_I2S_GetStandardMode
   * @param    I2Sx I2S instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_I2S_STANDARD_MODE_PHILIPS
   *           @arg @ref FL_I2S_STANDARD_MODE_MSB_JUSTIFIED
   *           @arg @ref FL_I2S_STANDARD_MODE_LSB_JUSTIFIED
   *           @arg @ref FL_I2S_STANDARD_MODE_PCM
   */
  __STATIC_INLINE uint32_t FL_I2S_GetStandardMode(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->I2SCR, I2SCR_I2SSTD_Msk));
  }

  /**
   * @brief    Set I2S Vocal Tract Length
   * @rmtoll   I2SCR    CHLEN    FL_I2S_SetVocalTractLength
   * @param    I2Sx I2S instance
   * @param    length This parameter can be one of the following values:
   *           @arg @ref FL_I2S_VOCAL_TRACT_LENGTH_16BITS
   *           @arg @ref FL_I2S_VOCAL_TRACT_LENGTH_32BITS
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_SetVocalTractLength(SPI_Type *SPIx, uint32_t length)
  {
    MODIFY_REG(SPIx->I2SCR, I2SCR_CHLEN_Msk, length);
  }

  /**
   * @brief    Get I2S Vocal Tract Length
   * @rmtoll   I2SCR    CHLEN    FL_I2S_GetVocalTractLength
   * @param    I2Sx I2S instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_I2S_VOCAL_TRACT_LENGTH_16BITS
   *           @arg @ref FL_I2S_VOCAL_TRACT_LENGTH_32BITS
   */
  __STATIC_INLINE uint32_t FL_I2S_GetVocalTractLength(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->I2SCR, I2SCR_CHLEN_Msk));
  }

  /**
   * @brief    Set I2S Idle Clock Polarity
   * @rmtoll   I2SCR    CKPOL    FL_I2S_SetIdleClockPolarity
   * @param    I2Sx I2S instance
   * @param    polarity This parameter can be one of the following values:
   *           @arg @ref FL_I2S_IDLE_POLARITY_LOW
   *           @arg @ref FL_I2S_IDLE_POLARITY_HIGHT
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_SetIdleClockPolarity(SPI_Type *SPIx, uint32_t polarity)
  {
    MODIFY_REG(SPIx->I2SCR, I2SCR_CKPOL_Msk, polarity);
  }

  /**
   * @brief    Get I2S Idle Clock Polarity
   * @rmtoll   I2SCR    CKPOL    FL_I2S_GetIdleClockPolarity
   * @param    I2Sx I2S instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_I2S_IDLE_POLARITY_LOW
   *           @arg @ref FL_I2S_IDLE_POLARITY_HIGHT
   */
  __STATIC_INLINE uint32_t FL_I2S_GetIdleClockPolarity(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->I2SCR, I2SCR_CKPOL_Msk));
  }

  /**
   * @brief    Set I2S Data Length
   * @rmtoll   I2SCR    DLEN    FL_I2S_SetDataLength
   * @param    I2Sx I2S instance
   * @param    length This parameter can be one of the following values:
   *           @arg @ref FL_I2S_DATA_LENGTH_16BITS
   *           @arg @ref FL_I2S_DATA_LENGTH_24BITS
   *           @arg @ref FL_I2S_DATA_LENGTH_32BITS
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_SetDataLength(SPI_Type *SPIx, uint32_t length)
  {
    MODIFY_REG(SPIx->I2SCR, I2SCR_DLEN_Msk, length);
  }

  /**
   * @brief    Get I2S Data Length
   * @rmtoll   I2SCR    DLEN    FL_I2S_GetDataLength
   * @param    I2Sx I2S instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_I2S_DATA_LENGTH_16BITS
   *           @arg @ref FL_I2S_DATA_LENGTH_24BITS
   *           @arg @ref FL_I2S_DATA_LENGTH_32BITS
   */
  __STATIC_INLINE uint32_t FL_I2S_GetDataLength(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->I2SCR, I2SCR_DLEN_Msk));
  }

  /**
   * @brief    Set I2S PCM Frame Synchronization
   * @rmtoll   I2SCR    PCMSYNC    FL_I2S_SetPCMFrameSynchronization
   * @param    I2Sx I2S instance
   * @param    Synchronization This parameter can be one of the following values:
   *           @arg @ref FL_I2S_FRAME_SYNCHRONIZATION_SHORT
   *           @arg @ref FL_I2S_FRAME_SYNCHRONIZATION_LONG
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_SetPCMFrameSynchronization(SPI_Type *SPIx, uint32_t Synchronization)
  {
    MODIFY_REG(SPIx->I2SCR, I2SCR_PCMSYNC_Msk, Synchronization);
  }

  /**
   * @brief    Get II2S PCM Frame Synchronization
   * @rmtoll   I2SCR    PCMSYNC    FL_I2S_GetIPCMFrameSynchronization
   * @param    I2Sx I2S instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_I2S_FRAME_SYNCHRONIZATION_SHORT
   *           @arg @ref FL_I2S_FRAME_SYNCHRONIZATION_LONG
   */
  __STATIC_INLINE uint32_t FL_I2S_GetIPCMFrameSynchronization(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->I2SCR, I2SCR_PCMSYNC_Msk));
  }

  /**
   * @brief    Set I2S Master Mode
   * @rmtoll   I2SCR    I2SMM    FL_I2S_SetTransferMode
   * @param    I2Sx I2S instance
   * @param    mode This parameter can be one of the following values:
   *           @arg @ref FL_I2S_MODE_SLAVE_RX
   *           @arg @ref FL_I2S_MODE_SLAVE_TX
   *           @arg @ref FL_I2S_MODE_MASTER_RX
   *           @arg @ref FL_I2S_MODE_MASTER_TX
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_SetTransferMode(SPI_Type *SPIx, uint32_t mode)
  {
    MODIFY_REG(SPIx->I2SCR, I2SCR_I2SMM_Msk, mode);
  }

  /**
   * @brief    Get I2S Data LengthMaster Mode
   * @rmtoll   I2SCR    I2SMM    FL_I2S_GetTransferMode
   * @param    I2Sx I2S instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_I2S_MODE_SLAVE_RX
   *           @arg @ref FL_I2S_MODE_SLAVE_TX
   *           @arg @ref FL_I2S_MODE_MASTER_RX
   *           @arg @ref FL_I2S_MODE_MASTER_TX
   */
  __STATIC_INLINE uint32_t FL_I2S_GetTransferMode(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->I2SCR, I2SCR_I2SMM_Msk));
  }

  /**
   * @brief    Enable I2S Data Delay
   * @rmtoll   I2SCR    DLYEN    FL_I2S_EnableDataDelay
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_EnableDataDelay(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->I2SCR, I2SCR_DLYEN_Msk);
  }

  /**
   * @brief    Get I2S Data Delay Status
   * @rmtoll   I2SCR    DLYEN    FL_I2S_IsEnabledDataDelay
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsEnabledDataDelay(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->I2SCR, I2SCR_DLYEN_Msk) == I2SCR_DLYEN_Msk);
  }

  /**
   * @brief    Disable I2S Data Delay
   * @rmtoll   I2SCR    DLYEN    FL_I2S_DisableDataDelay
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_DisableDataDelay(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->I2SCR, I2SCR_DLYEN_Msk);
  }

  /**
   * @brief    Set PeripheralMode
   * @rmtoll   I2SCR    I2SMOD    FL_I2S_SetPeriphralMode
   * @param    I2Sx I2S instance
   * @param    mode This parameter can be one of the following values:
   *           @arg @ref FL_I2S_PERIPHRAL_MODE_SPI
   *           @arg @ref FL_I2S_PERIPHRAL_MODE_I2S
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_SetPeriphralMode(SPI_Type *SPIx, uint32_t mode)
  {
    MODIFY_REG(SPIx->I2SCR, I2SCR_I2SMOD_Msk, mode);
  }

  /**
   * @brief    Get PeripheralMode
   * @rmtoll   I2SCR    I2SMOD    FL_I2S_GetPeriphralMode
   * @param    I2Sx I2S instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_I2S_PERIPHRAL_MODE_SPI
   *           @arg @ref FL_I2S_PERIPHRAL_MODE_I2S
   */
  __STATIC_INLINE uint32_t FL_I2S_GetPeriphralMode(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->I2SCR, I2SCR_I2SMOD_Msk));
  }

  /**
   * @brief    Enable I2S
   * @rmtoll   I2SCR    I2SEN    FL_I2S_Enable
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_Enable(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->I2SCR, I2SCR_I2SEN_Msk);
  }

  /**
   * @brief    Get I2S Enable Status
   * @rmtoll   I2SCR    I2SEN    FL_I2S_IsEnabled
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsEnabled(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->I2SCR, I2SCR_I2SEN_Msk) == I2SCR_I2SEN_Msk);
  }

  /**
   * @brief    Disable I2S
   * @rmtoll   I2SCR    I2SEN    FL_I2S_Disable
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_Disable(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->I2SCR, I2SCR_I2SEN_Msk);
  }

  /**
   * @brief    Enable I2S Master Clock Output
   * @rmtoll   I2SPR    MCKOE    FL_I2S_EnableMasterClockOutput
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_EnableMasterClockOutput(SPI_Type *SPIx)
  {
    SET_BIT(SPIx->I2SPR, I2SPR_MCKOE_Msk);
  }

  /**
   * @brief    Get I2S Master Clock Output
   * @rmtoll   I2SPR    MCKOE    FL_I2S_IsEnabledMasterClockOutput
   * @param    I2Sx I2S instance
   * @retval   State of bit (1 or 0).
   */
  __STATIC_INLINE uint32_t FL_I2S_IsEnabledMasterClockOutput(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->I2SPR, I2SPR_MCKOE_Msk) == I2SPR_MCKOE_Msk);
  }

  /**
   * @brief    Disable I2S Master Clock Output
   * @rmtoll   I2SPR    MCKOE    FL_I2S_DisableMasterClockOutput
   * @param    I2Sx I2S instance
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_DisableMasterClockOutput(SPI_Type *SPIx)
  {
    CLEAR_BIT(SPIx->I2SPR, I2SPR_MCKOE_Msk);
  }

  /**
   * @brief    Set I2S BaudRate Prescale Fractional
   * @rmtoll   I2SPR    ODD    FL_I2S_SetPrescalerParity
   * @param    I2Sx I2S instance
   * @param    prescalerParity This parameter can be one of the following values:
   *           @arg @ref FL_I2S_PRESCALER_PARITY_EVEN
   *           @arg @ref FL_I2S_PRESCALER_PARITY_ODD
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_SetPrescalerParity(SPI_Type *SPIx, uint32_t prescalerParity)
  {
    MODIFY_REG(SPIx->I2SPR, I2SPR_ODD_Msk, prescalerParity);
  }

  /**
   * @brief    Get I2S BaudRate Prescale Fractiona
   * @rmtoll   I2SPR    ODD    FL_I2S_GetPrescalerParity
   * @param    I2Sx I2S instance
   * @retval   Returned value can be one of the following values:
   *           @arg @ref FL_I2S_PRESCALER_PARITY_EVEN
   *           @arg @ref FL_I2S_PRESCALER_PARITY_ODD
   */
  __STATIC_INLINE uint32_t FL_I2S_GetPrescalerParity(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->I2SPR, I2SPR_ODD_Msk));
  }

  /**
   * @brief    Write I2S BaudRate Prescale
   * @rmtoll   I2SPR    CLKDIV    FL_I2S_WritePrescalerLinear
   * @param    I2Sx I2S instance
   * @param    data
   * @retval   None
   */
  __STATIC_INLINE void FL_I2S_WritePrescalerLinear(SPI_Type *SPIx, uint32_t data)
  {
    MODIFY_REG(SPIx->I2SPR, (0xffU << 0U), (data << 0U));
  }

  /**
   * @brief    Read I2S BaudRate Prescale
   * @rmtoll   I2SPR    CLKDIV    FL_I2S_ReadPrescalerLinear
   * @param    I2Sx I2S instance
   * @retval
   */
  __STATIC_INLINE uint32_t FL_I2S_ReadPrescalerLinear(SPI_Type *SPIx)
  {
    return (uint32_t)(READ_BIT(SPIx->I2SPR, (0xffU << 0U)) >> 0U);
  }

  /**
   * @}
   */

  /** @defgroup SPI_FL_EF_Init Initialization and de-initialization functions
   * @{
   */
  FL_ErrorStatus FL_SPI_DeInit(SPI_Type *SPIx);
  FL_ErrorStatus FL_SPI_Init(SPI_Type *SPIx, FL_SPI_InitTypeDef *initStruct);
  void FL_SPI_StructInit(FL_SPI_InitTypeDef *initStruct);
  FL_ErrorStatus FL_I2S_Init(SPI_Type *SPIx, FL_I2S_InitTypeDef *initStruct);
  void FL_I2S_StructInit(FL_I2S_InitTypeDef *initStruct);

  /**
   * @}
   */

  /**
   * @}
   */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_SPI_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-03-27*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
