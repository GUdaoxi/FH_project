 /**   
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_canfd.h
  * @author  FMSH Application Team
  * @brief   Head file of CANFD FL Module
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
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS”
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
#ifndef __FM33FH0XX_FL_CANFD_H
#define __FM33FH0XX_FL_CANFD_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl_def.h"
/** @addtogroup FM33FH0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup CANFD_FL_ES_INIT CANFD Exported Init structures
  * @{
  */

/**
  * @brief FL CANFD Init Sturcture definition
  */
    
extern const uint8_t RXMB_INDEX_START[4];
    
#define RXMB_NUM(x)     ((x) >> 3)
#define RXMB_INDEX(x)   ((x) - RXMB_INDEX_START[RXMB_NUM(x)])

typedef struct
{
    CANFD_RX_FIFO_Type         * RX_FIFO;
    CANFD_COMMON_FIFO_Type     * COMMON_FIFO;
    CANFD_TX_MESSAGE_Type      * TX_MESSAGE;
    CANFD_TX_HISTORY_LIST_Type * TX_HISTORY_LIST;
    CANFD_RX_MESSAGE_Type      * RX_MESSAGE[4];
}CANFD_BUFFER_TYPE;

extern const CANFD_BUFFER_TYPE CANFD_BUFFER[];

/*Buffer宏定义*/
#define THL(x)        (CANFD_BUFFER[0].TX_HISTORY_LIST)
#define CF(x)         (CANFD_BUFFER[0].COMMON_FIFO)
#define RM(x, num)    (CANFD_BUFFER[0].RX_MESSAGE[RXMB_NUM(num)]->CFDRM[RXMB_INDEX(num)])
#define RF(x, num)    (CANFD_BUFFER[0].RX_FIFO->CFDRF[num])
#define TM(x, num)    (CANFD_BUFFER[0].TX_MESSAGE->CFDTM[num])

/*RxMB配置*/
typedef struct
{
    /*RxMB负载大小配置*/
    uint32_t payloadDataSize;    
    /*RxMB数目*/
    uint32_t rxmbNum;    
}FL_CANFD_RxMB_CfgTypeDef;

/*RxFIFO配置*/
typedef struct
{
    /*中断产生水位*/
    uint32_t intGenCounterValue;
    /*中断模式*/
    uint32_t intMode;
    /*FIFO深度*/
    uint32_t fifoDepth;    
    /*负载大小配置*/
    uint32_t payloadDataSize;
    /*中断使能*/
    FL_FunState intEnable;
    /*CommonFIFO是否使能*/
    FL_FunState Enable;    
}FL_CANFD_RxFIFO_CfgTypeDef;

/*CommonFIFO配置*/
typedef struct
{
    /*发送间隔*/
    uint32_t txInterval;
    /*FIFO深度*/
    uint32_t fifoDepth;
    /*发送用TxMB链接*/
    uint32_t txmbLink;
    /*中断产生水位*/
    uint32_t intGenCounterValue;
    /*中断模式*/
    uint32_t intMode;
    /*内部定时器分辨率*/
    uint32_t intervalTimerResolution;
    /*内部定时器源*/
    uint32_t intervalTimerSource;
    /*FIFO模式*/
    uint32_t fifoMode;
    /*负载大小配置*/
    uint32_t payloadDataSize;
    /*中断使能*/
    FL_FunState intEnable;
    /*CommonFIFO是否使能*/
    FL_FunState Enable;   
}FL_CANFD_CommonFIFO_CfgTypeDef;

/*TxQueue配置*/
typedef struct
{
    /*队列深度*/
    uint32_t queueDepth;
    /*中断模式*/
    uint32_t intMode;
    /*中断使能*/
    FL_FunState intEnable;
    /*TxQueue是否使能*/
    FL_FunState Enable;   
}FL_CANFD_TxQueue_CfgTypeDef;

/*TxHistoryList配置*/
typedef struct
{
    /*TxHistoryList专用Tx是否使能*/
    FL_FunState dedicatedTxEnable;    
    /*中断模式*/
    uint32_t intMode;
    /*中断使能*/
    FL_FunState intEnable;
    /*TxHistoryList是否使能*/
    FL_FunState Enable;   
}FL_CANFD_TxHistoryList_CfgTypeDef;

/**
  * @brief  CANFD Acceptance filter config structure definition
  */
typedef struct
{
    /*IDE*/
    uint32_t filterIDE;
    /*RTR*/
    uint32_t filterRTR;
    /*ID*/
    uint32_t filterID;
    
    /*IDEM*/
    uint32_t filterIDEMask;
    /*RTRM*/
    uint32_t filterRTRMask;
    /*IDM*/
    uint32_t filterIDMask;
    
    /*RxMB配置*/
    /*RxMB有效使能*/
    uint32_t rxmbValid;    
    /*接收用RxMB编号*/
    uint32_t rxmbNum;
    /*接收长度*/
    uint32_t dlc;
    
    /*CommonFIFO和RxFIFO接收使能*/
    /*CommonFIFO接收使能*/
    FL_FunState commonfifoRecvEnable;
    /*RxFIFO接收使能*/
    FL_FunState rxfifo0RecvEnable;
    FL_FunState rxfifo1RecvEnable;

    /*滤波器使能*/
    FL_FunState  filterEnable;
} FL_CANFD_AcceptanceFilter_CfgTypeDef;

/**
  * @brief FL CANFD Init Sturcture definition
  */
typedef struct
{
    /*全局模式*/
    uint32_t globalMode;
    /*通道模式*/
    uint32_t channelMode;
    
    /*标称位速率同步段长度*/
    uint32_t NB_SJW;
    /*标称位速率时间段1*/
    uint32_t NB_TS1;
    /*标称位速率时间段2*/
    uint32_t NB_TS2;
    /*标称位速率波特率预分频*/
    uint32_t NB_BRP;
    /*数据位速率同步段长度*/
    uint32_t DB_SJW;
    /*数据位速率时间段1*/
    uint32_t DB_TS1;
    /*数据位速率时间段2*/
    uint32_t DB_TS2;
    /*数据位速率波特率预分频*/
    uint32_t DB_BRP;
      
    /*通信时钟源选择*/
    uint32_t clockSource;
    /*RAM时钟源选择*/
    uint32_t clockSourceRAM;
    
    /*接收和发送Buffer配置*/
    FL_CANFD_RxMB_CfgTypeDef   rxmbCfg;
    FL_CANFD_RxFIFO_CfgTypeDef rxfifoCfg[2];
    FL_CANFD_CommonFIFO_CfgTypeDef commonfifoCfg;
    FL_CANFD_TxQueue_CfgTypeDef  txqueueCfg;    
    FL_CANFD_TxHistoryList_CfgTypeDef txHistoryCfg;
    
    /*接收滤波器配置*/
    /*接收滤波器规则数目*/
    uint32_t acceptanceFilterRuleNum;
    FL_CANFD_AcceptanceFilter_CfgTypeDef acceptanceFilterCfg[32];
    
    /*特殊参数配置*/
    /*发送优先级选择*/
    uint32_t txPriority;
    /*ESI配置*/
    uint32_t esiCfg;
    /*发送延迟补偿偏置*/
    uint32_t tdco;
    /*发送延迟补偿配置*/
    uint32_t tdcoCfg;    
    /*发送延迟补偿使能*/
    FL_FunState tdcoEnable;
    
    /*RES位协议异常检测使能 */
    FL_FunState respedEnable;
    /*DLC检查使能*/
    FL_FunState dlcCheckEnable;
    /*DLC替换使能 */
    FL_FunState dlcReplacementEnable;
    /*消息过载拒接接收使能*/
    FL_FunState messageIsRejected;
} FL_CANFD_InitTypeDef;
    
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup CANFD_FL_Exported_Constants CANFD Exported Constants
  * @{
  */

#define    CANFD_CFDC0NCFG_NTSEG2_Pos                             (25U)
#define    CANFD_CFDC0NCFG_NTSEG2_Msk                             (0x7fU << CANFD_CFDC0NCFG_NTSEG2_Pos)
#define    CANFD_CFDC0NCFG_NTSEG2                                 CANFD_CFDC0NCFG_NTSEG2_Msk

#define    CANFD_CFDC0NCFG_NTSEG1_Pos                             (17U)
#define    CANFD_CFDC0NCFG_NTSEG1_Msk                             (0xffU << CANFD_CFDC0NCFG_NTSEG1_Pos)
#define    CANFD_CFDC0NCFG_NTSEG1                                 CANFD_CFDC0NCFG_NTSEG1_Msk

#define    CANFD_CFDC0NCFG_NSJW_Pos                               (10U)
#define    CANFD_CFDC0NCFG_NSJW_Msk                               (0x7fU << CANFD_CFDC0NCFG_NSJW_Pos)
#define    CANFD_CFDC0NCFG_NSJW                                   CANFD_CFDC0NCFG_NSJW_Msk

#define    CANFD_CFDC0NCFG_NBRP_Pos                               (0U)
#define    CANFD_CFDC0NCFG_NBRP_Msk                               (0x3ffU << CANFD_CFDC0NCFG_NBRP_Pos)
#define    CANFD_CFDC0NCFG_NBRP                                   CANFD_CFDC0NCFG_NBRP_Msk

#define    CANFD_CFDC0CTR_ROM_Pos                                 (31U)
#define    CANFD_CFDC0CTR_ROM_Msk                                 (0x1U << CANFD_CFDC0CTR_ROM_Pos)
#define    CANFD_CFDC0CTR_ROM                                     CANFD_CFDC0CTR_ROM_Msk

#define    CANFD_CFDC0CTR_BFT_Pos                                 (30U)
#define    CANFD_CFDC0CTR_BFT_Msk                                 (0x1U << CANFD_CFDC0CTR_BFT_Pos)
#define    CANFD_CFDC0CTR_BFT                                     CANFD_CFDC0CTR_BFT_Msk

#define    CANFD_CFDC0CTR_CTMS_Pos                                (25U)
#define    CANFD_CFDC0CTR_CTMS_Msk                                (0x3U << CANFD_CFDC0CTR_CTMS_Pos)
#define    CANFD_CFDC0CTR_CTMS                                    CANFD_CFDC0CTR_CTMS_Msk

#define    CANFD_CFDC0CTR_CTME_Pos                                (24U)
#define    CANFD_CFDC0CTR_CTME_Msk                                (0x1U << CANFD_CFDC0CTR_CTME_Pos)
#define    CANFD_CFDC0CTR_CTME                                    CANFD_CFDC0CTR_CTME_Msk

#define    CANFD_CFDC0CTR_ERRD_Pos                                (23U)
#define    CANFD_CFDC0CTR_ERRD_Msk                                (0x1U << CANFD_CFDC0CTR_ERRD_Pos)
#define    CANFD_CFDC0CTR_ERRD                                    CANFD_CFDC0CTR_ERRD_Msk

#define    CANFD_CFDC0CTR_BOM_Pos                                 (21U)
#define    CANFD_CFDC0CTR_BOM_Msk                                 (0x3U << CANFD_CFDC0CTR_BOM_Pos)
#define    CANFD_CFDC0CTR_BOM                                     CANFD_CFDC0CTR_BOM_Msk

#define    CANFD_CFDC0CTR_TDCVFIE_Pos                             (19U)
#define    CANFD_CFDC0CTR_TDCVFIE_Msk                             (0x1U << CANFD_CFDC0CTR_TDCVFIE_Pos)
#define    CANFD_CFDC0CTR_TDCVFIE                                 CANFD_CFDC0CTR_TDCVFIE_Msk

#define    CANFD_CFDC0CTR_SOCOIE_Pos                              (18U)
#define    CANFD_CFDC0CTR_SOCOIE_Msk                              (0x1U << CANFD_CFDC0CTR_SOCOIE_Pos)
#define    CANFD_CFDC0CTR_SOCOIE                                  CANFD_CFDC0CTR_SOCOIE_Msk

#define    CANFD_CFDC0CTR_EOCOIE_Pos                              (17U)
#define    CANFD_CFDC0CTR_EOCOIE_Msk                              (0x1U << CANFD_CFDC0CTR_EOCOIE_Pos)
#define    CANFD_CFDC0CTR_EOCOIE                                  CANFD_CFDC0CTR_EOCOIE_Msk

#define    CANFD_CFDC0CTR_TAIE_Pos                                (16U)
#define    CANFD_CFDC0CTR_TAIE_Msk                                (0x1U << CANFD_CFDC0CTR_TAIE_Pos)
#define    CANFD_CFDC0CTR_TAIE                                    CANFD_CFDC0CTR_TAIE_Msk

#define    CANFD_CFDC0CTR_ALIE_Pos                                (15U)
#define    CANFD_CFDC0CTR_ALIE_Msk                                (0x1U << CANFD_CFDC0CTR_ALIE_Pos)
#define    CANFD_CFDC0CTR_ALIE                                    CANFD_CFDC0CTR_ALIE_Msk

#define    CANFD_CFDC0CTR_BLIE_Pos                                (14U)
#define    CANFD_CFDC0CTR_BLIE_Msk                                (0x1U << CANFD_CFDC0CTR_BLIE_Pos)
#define    CANFD_CFDC0CTR_BLIE                                    CANFD_CFDC0CTR_BLIE_Msk

#define    CANFD_CFDC0CTR_OLIE_Pos                                (13U)
#define    CANFD_CFDC0CTR_OLIE_Msk                                (0x1U << CANFD_CFDC0CTR_OLIE_Pos)
#define    CANFD_CFDC0CTR_OLIE                                    CANFD_CFDC0CTR_OLIE_Msk

#define    CANFD_CFDC0CTR_BORIE_Pos                               (12U)
#define    CANFD_CFDC0CTR_BORIE_Msk                               (0x1U << CANFD_CFDC0CTR_BORIE_Pos)
#define    CANFD_CFDC0CTR_BORIE                                   CANFD_CFDC0CTR_BORIE_Msk

#define    CANFD_CFDC0CTR_BOEIE_Pos                               (11U)
#define    CANFD_CFDC0CTR_BOEIE_Msk                               (0x1U << CANFD_CFDC0CTR_BOEIE_Pos)
#define    CANFD_CFDC0CTR_BOEIE                                   CANFD_CFDC0CTR_BOEIE_Msk

#define    CANFD_CFDC0CTR_EPIE_Pos                                (10U)
#define    CANFD_CFDC0CTR_EPIE_Msk                                (0x1U << CANFD_CFDC0CTR_EPIE_Pos)
#define    CANFD_CFDC0CTR_EPIE                                    CANFD_CFDC0CTR_EPIE_Msk

#define    CANFD_CFDC0CTR_EWIE_Pos                                (9U)
#define    CANFD_CFDC0CTR_EWIE_Msk                                (0x1U << CANFD_CFDC0CTR_EWIE_Pos)
#define    CANFD_CFDC0CTR_EWIE                                    CANFD_CFDC0CTR_EWIE_Msk

#define    CANFD_CFDC0CTR_BEIE_Pos                                (8U)
#define    CANFD_CFDC0CTR_BEIE_Msk                                (0x1U << CANFD_CFDC0CTR_BEIE_Pos)
#define    CANFD_CFDC0CTR_BEIE                                    CANFD_CFDC0CTR_BEIE_Msk

#define    CANFD_CFDC0CTR_RTBO_Pos                                (3U)
#define    CANFD_CFDC0CTR_RTBO_Msk                                (0x1U << CANFD_CFDC0CTR_RTBO_Pos)
#define    CANFD_CFDC0CTR_RTBO                                    CANFD_CFDC0CTR_RTBO_Msk

#define    CANFD_CFDC0CTR_CSLPR_Pos                               (2U)
#define    CANFD_CFDC0CTR_CSLPR_Msk                               (0x1U << CANFD_CFDC0CTR_CSLPR_Pos)
#define    CANFD_CFDC0CTR_CSLPR                                   CANFD_CFDC0CTR_CSLPR_Msk

#define    CANFD_CFDC0CTR_CHMDC_Pos                               (0U)
#define    CANFD_CFDC0CTR_CHMDC_Msk                               (0x3U << CANFD_CFDC0CTR_CHMDC_Pos)
#define    CANFD_CFDC0CTR_CHMDC                                   CANFD_CFDC0CTR_CHMDC_Msk

#define    CANFD_CFDC0STS_TEC_Pos                                 (24U)
#define    CANFD_CFDC0STS_TEC_Msk                                 (0xffU << CANFD_CFDC0STS_TEC_Pos)
#define    CANFD_CFDC0STS_TEC                                     CANFD_CFDC0STS_TEC_Msk

#define    CANFD_CFDC0STS_REC_Pos                                 (16U)
#define    CANFD_CFDC0STS_REC_Msk                                 (0xffU << CANFD_CFDC0STS_REC_Pos)
#define    CANFD_CFDC0STS_REC                                     CANFD_CFDC0STS_REC_Msk

#define    CANFD_CFDC0STS_ESIF_Pos                                (8U)
#define    CANFD_CFDC0STS_ESIF_Msk                                (0x1U << CANFD_CFDC0STS_ESIF_Pos)
#define    CANFD_CFDC0STS_ESIF                                    CANFD_CFDC0STS_ESIF_Msk

#define    CANFD_CFDC0STS_COMSTS_Pos                              (7U)
#define    CANFD_CFDC0STS_COMSTS_Msk                              (0x1U << CANFD_CFDC0STS_COMSTS_Pos)
#define    CANFD_CFDC0STS_COMSTS                                  CANFD_CFDC0STS_COMSTS_Msk

#define    CANFD_CFDC0STS_RECSTS_Pos                              (6U)
#define    CANFD_CFDC0STS_RECSTS_Msk                              (0x1U << CANFD_CFDC0STS_RECSTS_Pos)
#define    CANFD_CFDC0STS_RECSTS                                  CANFD_CFDC0STS_RECSTS_Msk

#define    CANFD_CFDC0STS_TRMSTS_Pos                              (5U)
#define    CANFD_CFDC0STS_TRMSTS_Msk                              (0x1U << CANFD_CFDC0STS_TRMSTS_Pos)
#define    CANFD_CFDC0STS_TRMSTS                                  CANFD_CFDC0STS_TRMSTS_Msk

#define    CANFD_CFDC0STS_BOSTS_Pos                               (4U)
#define    CANFD_CFDC0STS_BOSTS_Msk                               (0x1U << CANFD_CFDC0STS_BOSTS_Pos)
#define    CANFD_CFDC0STS_BOSTS                                   CANFD_CFDC0STS_BOSTS_Msk

#define    CANFD_CFDC0STS_EPSTS_Pos                               (3U)
#define    CANFD_CFDC0STS_EPSTS_Msk                               (0x1U << CANFD_CFDC0STS_EPSTS_Pos)
#define    CANFD_CFDC0STS_EPSTS                                   CANFD_CFDC0STS_EPSTS_Msk

#define    CANFD_CFDC0STS_CSLPSTS_Pos                             (2U)
#define    CANFD_CFDC0STS_CSLPSTS_Msk                             (0x1U << CANFD_CFDC0STS_CSLPSTS_Pos)
#define    CANFD_CFDC0STS_CSLPSTS                                 CANFD_CFDC0STS_CSLPSTS_Msk

#define    CANFD_CFDC0STS_CHLTSTS_Pos                             (1U)
#define    CANFD_CFDC0STS_CHLTSTS_Msk                             (0x1U << CANFD_CFDC0STS_CHLTSTS_Pos)
#define    CANFD_CFDC0STS_CHLTSTS                                 CANFD_CFDC0STS_CHLTSTS_Msk

#define    CANFD_CFDC0STS_CRSTSTS_Pos                             (0U)
#define    CANFD_CFDC0STS_CRSTSTS_Msk                             (0x1U << CANFD_CFDC0STS_CRSTSTS_Pos)
#define    CANFD_CFDC0STS_CRSTSTS                                 CANFD_CFDC0STS_CRSTSTS_Msk

#define    CANFD_CFDC0ERFL_CRCREG_Pos                             (16U)
#define    CANFD_CFDC0ERFL_CRCREG_Msk                             (0x7fffU << CANFD_CFDC0ERFL_CRCREG_Pos)
#define    CANFD_CFDC0ERFL_CRCREG                                 CANFD_CFDC0ERFL_CRCREG_Msk

#define    CANFD_CFDC0ERFL_ADERR_Pos                              (14U)
#define    CANFD_CFDC0ERFL_ADERR_Msk                              (0x1U << CANFD_CFDC0ERFL_ADERR_Pos)
#define    CANFD_CFDC0ERFL_ADERR                                  CANFD_CFDC0ERFL_ADERR_Msk

#define    CANFD_CFDC0ERFL_B0ERR_Pos                              (13U)
#define    CANFD_CFDC0ERFL_B0ERR_Msk                              (0x1U << CANFD_CFDC0ERFL_B0ERR_Pos)
#define    CANFD_CFDC0ERFL_B0ERR                                  CANFD_CFDC0ERFL_B0ERR_Msk

#define    CANFD_CFDC0ERFL_B1ERR_Pos                              (12U)
#define    CANFD_CFDC0ERFL_B1ERR_Msk                              (0x1U << CANFD_CFDC0ERFL_B1ERR_Pos)
#define    CANFD_CFDC0ERFL_B1ERR                                  CANFD_CFDC0ERFL_B1ERR_Msk

#define    CANFD_CFDC0ERFL_CERR_Pos                               (11U)
#define    CANFD_CFDC0ERFL_CERR_Msk                               (0x1U << CANFD_CFDC0ERFL_CERR_Pos)
#define    CANFD_CFDC0ERFL_CERR                                   CANFD_CFDC0ERFL_CERR_Msk

#define    CANFD_CFDC0ERFL_AERR_Pos                               (10U)
#define    CANFD_CFDC0ERFL_AERR_Msk                               (0x1U << CANFD_CFDC0ERFL_AERR_Pos)
#define    CANFD_CFDC0ERFL_AERR                                   CANFD_CFDC0ERFL_AERR_Msk

#define    CANFD_CFDC0ERFL_FERR_Pos                               (9U)
#define    CANFD_CFDC0ERFL_FERR_Msk                               (0x1U << CANFD_CFDC0ERFL_FERR_Pos)
#define    CANFD_CFDC0ERFL_FERR                                   CANFD_CFDC0ERFL_FERR_Msk

#define    CANFD_CFDC0ERFL_SERR_Pos                               (8U)
#define    CANFD_CFDC0ERFL_SERR_Msk                               (0x1U << CANFD_CFDC0ERFL_SERR_Pos)
#define    CANFD_CFDC0ERFL_SERR                                   CANFD_CFDC0ERFL_SERR_Msk

#define    CANFD_CFDC0ERFL_ALF_Pos                                (7U)
#define    CANFD_CFDC0ERFL_ALF_Msk                                (0x1U << CANFD_CFDC0ERFL_ALF_Pos)
#define    CANFD_CFDC0ERFL_ALF                                    CANFD_CFDC0ERFL_ALF_Msk

#define    CANFD_CFDC0ERFL_BLF_Pos                                (6U)
#define    CANFD_CFDC0ERFL_BLF_Msk                                (0x1U << CANFD_CFDC0ERFL_BLF_Pos)
#define    CANFD_CFDC0ERFL_BLF                                    CANFD_CFDC0ERFL_BLF_Msk

#define    CANFD_CFDC0ERFL_OVLF_Pos                               (5U)
#define    CANFD_CFDC0ERFL_OVLF_Msk                               (0x1U << CANFD_CFDC0ERFL_OVLF_Pos)
#define    CANFD_CFDC0ERFL_OVLF                                   CANFD_CFDC0ERFL_OVLF_Msk

#define    CANFD_CFDC0ERFL_BORF_Pos                               (4U)
#define    CANFD_CFDC0ERFL_BORF_Msk                               (0x1U << CANFD_CFDC0ERFL_BORF_Pos)
#define    CANFD_CFDC0ERFL_BORF                                   CANFD_CFDC0ERFL_BORF_Msk

#define    CANFD_CFDC0ERFL_BOEF_Pos                               (3U)
#define    CANFD_CFDC0ERFL_BOEF_Msk                               (0x1U << CANFD_CFDC0ERFL_BOEF_Pos)
#define    CANFD_CFDC0ERFL_BOEF                                   CANFD_CFDC0ERFL_BOEF_Msk

#define    CANFD_CFDC0ERFL_EPF_Pos                                (2U)
#define    CANFD_CFDC0ERFL_EPF_Msk                                (0x1U << CANFD_CFDC0ERFL_EPF_Pos)
#define    CANFD_CFDC0ERFL_EPF                                    CANFD_CFDC0ERFL_EPF_Msk

#define    CANFD_CFDC0ERFL_EWF_Pos                                (1U)
#define    CANFD_CFDC0ERFL_EWF_Msk                                (0x1U << CANFD_CFDC0ERFL_EWF_Pos)
#define    CANFD_CFDC0ERFL_EWF                                    CANFD_CFDC0ERFL_EWF_Msk

#define    CANFD_CFDC0ERFL_BEF_Pos                                (0U)
#define    CANFD_CFDC0ERFL_BEF_Msk                                (0x1U << CANFD_CFDC0ERFL_BEF_Pos)
#define    CANFD_CFDC0ERFL_BEF                                    CANFD_CFDC0ERFL_BEF_Msk

#define    CANFD_CFDC0DCFG_DSJW_Pos                               (24U)
#define    CANFD_CFDC0DCFG_DSJW_Msk                               (0xfU << CANFD_CFDC0DCFG_DSJW_Pos)
#define    CANFD_CFDC0DCFG_DSJW                                   CANFD_CFDC0DCFG_DSJW_Msk

#define    CANFD_CFDC0DCFG_DTSEG2_Pos                             (16U)
#define    CANFD_CFDC0DCFG_DTSEG2_Msk                             (0xfU << CANFD_CFDC0DCFG_DTSEG2_Pos)
#define    CANFD_CFDC0DCFG_DTSEG2                                 CANFD_CFDC0DCFG_DTSEG2_Msk

#define    CANFD_CFDC0DCFG_DTSEG1_Pos                             (8U)
#define    CANFD_CFDC0DCFG_DTSEG1_Msk                             (0x1fU << CANFD_CFDC0DCFG_DTSEG1_Pos)
#define    CANFD_CFDC0DCFG_DTSEG1                                 CANFD_CFDC0DCFG_DTSEG1_Msk

#define    CANFD_CFDC0DCFG_DBRP_Pos                               (0U)
#define    CANFD_CFDC0DCFG_DBRP_Msk                               (0xffU << CANFD_CFDC0DCFG_DBRP_Pos)
#define    CANFD_CFDC0DCFG_DBRP                                   CANFD_CFDC0DCFG_DBRP_Msk

#define    CANFD_CFDC0FDCFG_CLOE_Pos                              (30U)
#define    CANFD_CFDC0FDCFG_CLOE_Msk                              (0x1U << CANFD_CFDC0FDCFG_CLOE_Pos)
#define    CANFD_CFDC0FDCFG_CLOE                                  CANFD_CFDC0FDCFG_CLOE_Msk

#define    CANFD_CFDC0FDCFG_REFE_Pos                              (29U)
#define    CANFD_CFDC0FDCFG_REFE_Msk                              (0x1U << CANFD_CFDC0FDCFG_REFE_Pos)
#define    CANFD_CFDC0FDCFG_REFE                                  CANFD_CFDC0FDCFG_REFE_Msk

#define    CANFD_CFDC0FDCFG_FDOE_Pos                              (28U)
#define    CANFD_CFDC0FDCFG_FDOE_Msk                              (0x1U << CANFD_CFDC0FDCFG_FDOE_Pos)
#define    CANFD_CFDC0FDCFG_FDOE                                  CANFD_CFDC0FDCFG_FDOE_Msk

#define    CANFD_CFDC0FDCFG_TDCO_Pos                              (16U)
#define    CANFD_CFDC0FDCFG_TDCO_Msk                              (0xffU << CANFD_CFDC0FDCFG_TDCO_Pos)
#define    CANFD_CFDC0FDCFG_TDCO                                  CANFD_CFDC0FDCFG_TDCO_Msk

#define    CANFD_CFDC0FDCFG_RPNMD_Pos                             (12U)
#define    CANFD_CFDC0FDCFG_RPNMD_Msk                             (0x3U << CANFD_CFDC0FDCFG_RPNMD_Pos)
#define    CANFD_CFDC0FDCFG_RPNMD                                 CANFD_CFDC0FDCFG_RPNMD_Msk

#define    CANFD_CFDC0FDCFG_ESIC_Pos                              (10U)
#define    CANFD_CFDC0FDCFG_ESIC_Msk                              (0x1U << CANFD_CFDC0FDCFG_ESIC_Pos)
#define    CANFD_CFDC0FDCFG_ESIC                                  CANFD_CFDC0FDCFG_ESIC_Msk

#define    CANFD_CFDC0FDCFG_TDCE_Pos                              (9U)
#define    CANFD_CFDC0FDCFG_TDCE_Msk                              (0x1U << CANFD_CFDC0FDCFG_TDCE_Pos)
#define    CANFD_CFDC0FDCFG_TDCE                                  CANFD_CFDC0FDCFG_TDCE_Msk

#define    CANFD_CFDC0FDCFG_TDCOC_Pos                             (8U)
#define    CANFD_CFDC0FDCFG_TDCOC_Msk                             (0x1U << CANFD_CFDC0FDCFG_TDCOC_Pos)
#define    CANFD_CFDC0FDCFG_TDCOC                                 CANFD_CFDC0FDCFG_TDCOC_Msk

#define    CANFD_CFDC0FDCFG_EOCCFG_Pos                            (0U)
#define    CANFD_CFDC0FDCFG_EOCCFG_Msk                            (0x7U << CANFD_CFDC0FDCFG_EOCCFG_Pos)
#define    CANFD_CFDC0FDCFG_EOCCFG                                CANFD_CFDC0FDCFG_EOCCFG_Msk

#define    CANFD_CFDC0FDCTR_KEY_Pos                               (24U)
#define    CANFD_CFDC0FDCTR_KEY_Msk                               (0xffU << CANFD_CFDC0FDCTR_KEY_Pos)
#define    CANFD_CFDC0FDCTR_KEY                                   CANFD_CFDC0FDCTR_KEY_Msk

#define    CANFD_CFDC0FDCTR_PNMDC_Pos                             (16U)
#define    CANFD_CFDC0FDCTR_PNMDC_Msk                             (0x3U << CANFD_CFDC0FDCTR_PNMDC_Pos)
#define    CANFD_CFDC0FDCTR_PNMDC                                 CANFD_CFDC0FDCTR_PNMDC_Msk

#define    CANFD_CFDC0FDCTR_SOCCLR_Pos                            (1U)
#define    CANFD_CFDC0FDCTR_SOCCLR_Msk                            (0x1U << CANFD_CFDC0FDCTR_SOCCLR_Pos)
#define    CANFD_CFDC0FDCTR_SOCCLR                                CANFD_CFDC0FDCTR_SOCCLR_Msk

#define    CANFD_CFDC0FDCTR_EOCCLR_Pos                            (0U)
#define    CANFD_CFDC0FDCTR_EOCCLR_Msk                            (0x1U << CANFD_CFDC0FDCTR_EOCCLR_Pos)
#define    CANFD_CFDC0FDCTR_EOCCLR                                CANFD_CFDC0FDCTR_EOCCLR_Msk

#define    CANFD_CFDC0FDSTS_SOC_Pos                               (24U)
#define    CANFD_CFDC0FDSTS_SOC_Msk                               (0xffU << CANFD_CFDC0FDSTS_SOC_Pos)
#define    CANFD_CFDC0FDSTS_SOC                                   CANFD_CFDC0FDSTS_SOC_Msk

#define    CANFD_CFDC0FDSTS_EOC_Pos                               (16U)
#define    CANFD_CFDC0FDSTS_EOC_Msk                               (0xffU << CANFD_CFDC0FDSTS_EOC_Pos)
#define    CANFD_CFDC0FDSTS_EOC                                   CANFD_CFDC0FDSTS_EOC_Msk

#define    CANFD_CFDC0FDSTS_TDCVF_Pos                             (15U)
#define    CANFD_CFDC0FDSTS_TDCVF_Msk                             (0x1U << CANFD_CFDC0FDSTS_TDCVF_Pos)
#define    CANFD_CFDC0FDSTS_TDCVF                                 CANFD_CFDC0FDSTS_TDCVF_Msk

#define    CANFD_CFDC0FDSTS_PNSTS_Pos                             (12U)
#define    CANFD_CFDC0FDSTS_PNSTS_Msk                             (0x3U << CANFD_CFDC0FDSTS_PNSTS_Pos)
#define    CANFD_CFDC0FDSTS_PNSTS                                 CANFD_CFDC0FDSTS_PNSTS_Msk

#define    CANFD_CFDC0FDSTS_SOCO_Pos                              (9U)
#define    CANFD_CFDC0FDSTS_SOCO_Msk                              (0x1U << CANFD_CFDC0FDSTS_SOCO_Pos)
#define    CANFD_CFDC0FDSTS_SOCO                                  CANFD_CFDC0FDSTS_SOCO_Msk

#define    CANFD_CFDC0FDSTS_EOCO_Pos                              (8U)
#define    CANFD_CFDC0FDSTS_EOCO_Msk                              (0x1U << CANFD_CFDC0FDSTS_EOCO_Pos)
#define    CANFD_CFDC0FDSTS_EOCO                                  CANFD_CFDC0FDSTS_EOCO_Msk

#define    CANFD_CFDC0FDSTS_TDCR_Pos                              (0U)
#define    CANFD_CFDC0FDSTS_TDCR_Msk                              (0xffU << CANFD_CFDC0FDSTS_TDCR_Pos)
#define    CANFD_CFDC0FDSTS_TDCR                                  CANFD_CFDC0FDSTS_TDCR_Msk

#define    CANFD_CFDC0FDCRC_SCNT_Pos                              (24U)
#define    CANFD_CFDC0FDCRC_SCNT_Msk                              (0xfU << CANFD_CFDC0FDCRC_SCNT_Pos)
#define    CANFD_CFDC0FDCRC_SCNT                                  CANFD_CFDC0FDCRC_SCNT_Msk

#define    CANFD_CFDC0FDCRC_CRCREG_Pos                            (0U)
#define    CANFD_CFDC0FDCRC_CRCREG_Msk                            (0x1fffffU << CANFD_CFDC0FDCRC_CRCREG_Pos)
#define    CANFD_CFDC0FDCRC_CRCREG                                CANFD_CFDC0FDCRC_CRCREG_Msk

#define    CANFD_CFDGIPV_PSI_Pos                                  (16U)
#define    CANFD_CFDGIPV_PSI_Msk                                  (0xffffU << CANFD_CFDGIPV_PSI_Pos)
#define    CANFD_CFDGIPV_PSI                                      CANFD_CFDGIPV_PSI_Msk

#define    CANFD_CFDGIPV_CPUBUS_Pos                               (15U)
#define    CANFD_CFDGIPV_CPUBUS_Msk                               (0x1U << CANFD_CFDGIPV_CPUBUS_Pos)
#define    CANFD_CFDGIPV_CPUBUS                                   CANFD_CFDGIPV_CPUBUS_Msk

#define    CANFD_CFDGIPV_IPT_Pos                                  (8U)
#define    CANFD_CFDGIPV_IPT_Msk                                  (0x3U << CANFD_CFDGIPV_IPT_Pos)
#define    CANFD_CFDGIPV_IPT                                      CANFD_CFDGIPV_IPT_Msk

#define    CANFD_CFDGIPV_IPV_Pos                                  (0U)
#define    CANFD_CFDGIPV_IPV_Msk                                  (0xffU << CANFD_CFDGIPV_IPV_Pos)
#define    CANFD_CFDGIPV_IPV                                      CANFD_CFDGIPV_IPV_Msk

#define    CANFD_CFDGCFG_ITRCP_Pos                                (16U)
#define    CANFD_CFDGCFG_ITRCP_Msk                                (0xffffU << CANFD_CFDGCFG_ITRCP_Pos)
#define    CANFD_CFDGCFG_ITRCP                                    CANFD_CFDGCFG_ITRCP_Msk

#define    CANFD_CFDGCFG_TSSS_Pos                                 (12U)
#define    CANFD_CFDGCFG_TSSS_Msk                                 (0x1U << CANFD_CFDGCFG_TSSS_Pos)
#define    CANFD_CFDGCFG_TSSS                                     CANFD_CFDGCFG_TSSS_Msk

#define    CANFD_CFDGCFG_TSP_Pos                                  (8U)
#define    CANFD_CFDGCFG_TSP_Msk                                  (0xfU << CANFD_CFDGCFG_TSP_Pos)
#define    CANFD_CFDGCFG_TSP                                      CANFD_CFDGCFG_TSP_Msk

#define    CANFD_CFDGCFG_CMPOC_Pos                                (5U)
#define    CANFD_CFDGCFG_CMPOC_Msk                                (0x1U << CANFD_CFDGCFG_CMPOC_Pos)
#define    CANFD_CFDGCFG_CMPOC                                    CANFD_CFDGCFG_CMPOC_Msk

#define    CANFD_CFDGCFG_DCS_Pos                                  (4U)
#define    CANFD_CFDGCFG_DCS_Msk                                  (0x1U << CANFD_CFDGCFG_DCS_Pos)
#define    CANFD_CFDGCFG_DCS                                      CANFD_CFDGCFG_DCS_Msk

#define    CANFD_CFDGCFG_MME_Pos                                  (3U)
#define    CANFD_CFDGCFG_MME_Msk                                  (0x1U << CANFD_CFDGCFG_MME_Pos)
#define    CANFD_CFDGCFG_MME                                      CANFD_CFDGCFG_MME_Msk

#define    CANFD_CFDGCFG_DRE_Pos                                  (2U)
#define    CANFD_CFDGCFG_DRE_Msk                                  (0x1U << CANFD_CFDGCFG_DRE_Pos)
#define    CANFD_CFDGCFG_DRE                                      CANFD_CFDGCFG_DRE_Msk

#define    CANFD_CFDGCFG_DCE_Pos                                  (1U)
#define    CANFD_CFDGCFG_DCE_Msk                                  (0x1U << CANFD_CFDGCFG_DCE_Pos)
#define    CANFD_CFDGCFG_DCE                                      CANFD_CFDGCFG_DCE_Msk

#define    CANFD_CFDGCFG_TPRI_Pos                                 (0U)
#define    CANFD_CFDGCFG_TPRI_Msk                                 (0x1U << CANFD_CFDGCFG_TPRI_Pos)
#define    CANFD_CFDGCFG_TPRI                                     CANFD_CFDGCFG_TPRI_Msk

#define    CANFD_CFDGCTR_TSRST_Pos                                (16U)
#define    CANFD_CFDGCTR_TSRST_Msk                                (0x1U << CANFD_CFDGCTR_TSRST_Pos)
#define    CANFD_CFDGCTR_TSRST                                    CANFD_CFDGCTR_TSRST_Msk

#define    CANFD_CFDGCTR_CMPOFIE_Pos                              (11U)
#define    CANFD_CFDGCTR_CMPOFIE_Msk                              (0x1U << CANFD_CFDGCTR_CMPOFIE_Pos)
#define    CANFD_CFDGCTR_CMPOFIE                                  CANFD_CFDGCTR_CMPOFIE_Msk

#define    CANFD_CFDGCTR_THLEIE_Pos                               (10U)
#define    CANFD_CFDGCTR_THLEIE_Msk                               (0x1U << CANFD_CFDGCTR_THLEIE_Pos)
#define    CANFD_CFDGCTR_THLEIE                                   CANFD_CFDGCTR_THLEIE_Msk

#define    CANFD_CFDGCTR_MEIE_Pos                                 (9U)
#define    CANFD_CFDGCTR_MEIE_Msk                                 (0x1U << CANFD_CFDGCTR_MEIE_Pos)
#define    CANFD_CFDGCTR_MEIE                                     CANFD_CFDGCTR_MEIE_Msk

#define    CANFD_CFDGCTR_DEIE_Pos                                 (8U)
#define    CANFD_CFDGCTR_DEIE_Msk                                 (0x1U << CANFD_CFDGCTR_DEIE_Pos)
#define    CANFD_CFDGCTR_DEIE                                     CANFD_CFDGCTR_DEIE_Msk

#define    CANFD_CFDGCTR_GSLPR_Pos                                (2U)
#define    CANFD_CFDGCTR_GSLPR_Msk                                (0x1U << CANFD_CFDGCTR_GSLPR_Pos)
#define    CANFD_CFDGCTR_GSLPR                                    CANFD_CFDGCTR_GSLPR_Msk

#define    CANFD_CFDGCTR_GMDC_Pos                                 (0U)
#define    CANFD_CFDGCTR_GMDC_Msk                                 (0x3U << CANFD_CFDGCTR_GMDC_Pos)
#define    CANFD_CFDGCTR_GMDC                                     CANFD_CFDGCTR_GMDC_Msk

#define    CANFD_CFDGSTS_GRAMINIT_Pos                             (3U)
#define    CANFD_CFDGSTS_GRAMINIT_Msk                             (0x1U << CANFD_CFDGSTS_GRAMINIT_Pos)
#define    CANFD_CFDGSTS_GRAMINIT                                 CANFD_CFDGSTS_GRAMINIT_Msk

#define    CANFD_CFDGSTS_GSLPSTS_Pos                              (2U)
#define    CANFD_CFDGSTS_GSLPSTS_Msk                              (0x1U << CANFD_CFDGSTS_GSLPSTS_Pos)
#define    CANFD_CFDGSTS_GSLPSTS                                  CANFD_CFDGSTS_GSLPSTS_Msk

#define    CANFD_CFDGSTS_GHLTSTS_Pos                              (1U)
#define    CANFD_CFDGSTS_GHLTSTS_Msk                              (0x1U << CANFD_CFDGSTS_GHLTSTS_Pos)
#define    CANFD_CFDGSTS_GHLTSTS                                  CANFD_CFDGSTS_GHLTSTS_Msk

#define    CANFD_CFDGSTS_GRSTSTS_Pos                              (0U)
#define    CANFD_CFDGSTS_GRSTSTS_Msk                              (0x1U << CANFD_CFDGSTS_GRSTSTS_Pos)
#define    CANFD_CFDGSTS_GRSTSTS                                  CANFD_CFDGSTS_GRSTSTS_Msk

#define    CANFD_CFDGERFL_EEF_Pos                                 (16U)
#define    CANFD_CFDGERFL_EEF_Msk                                 (0x1U << CANFD_CFDGERFL_EEF_Pos)
#define    CANFD_CFDGERFL_EEF                                     CANFD_CFDGERFL_EEF_Msk

#define    CANFD_CFDGERFL_CMPOF_Pos                               (3U)
#define    CANFD_CFDGERFL_CMPOF_Msk                               (0x1U << CANFD_CFDGERFL_CMPOF_Pos)
#define    CANFD_CFDGERFL_CMPOF                                   CANFD_CFDGERFL_CMPOF_Msk

#define    CANFD_CFDGERFL_THLES_Pos                               (2U)
#define    CANFD_CFDGERFL_THLES_Msk                               (0x1U << CANFD_CFDGERFL_THLES_Pos)
#define    CANFD_CFDGERFL_THLES                                   CANFD_CFDGERFL_THLES_Msk

#define    CANFD_CFDGERFL_MES_Pos                                 (1U)
#define    CANFD_CFDGERFL_MES_Msk                                 (0x1U << CANFD_CFDGERFL_MES_Pos)
#define    CANFD_CFDGERFL_MES                                     CANFD_CFDGERFL_MES_Msk

#define    CANFD_CFDGERFL_DEF_Pos                                 (0U)
#define    CANFD_CFDGERFL_DEF_Msk                                 (0x1U << CANFD_CFDGERFL_DEF_Pos)
#define    CANFD_CFDGERFL_DEF                                     CANFD_CFDGERFL_DEF_Msk

#define    CANFD_CFDGTINTSTS_THIF_Pos                             (4U)
#define    CANFD_CFDGTINTSTS_THIF_Msk                             (0x1U << CANFD_CFDGTINTSTS_THIF_Pos)
#define    CANFD_CFDGTINTSTS_THIF                                 CANFD_CFDGTINTSTS_THIF_Msk

#define    CANFD_CFDGTINTSTS_CFTIF_Pos                            (3U)
#define    CANFD_CFDGTINTSTS_CFTIF_Msk                            (0x1U << CANFD_CFDGTINTSTS_CFTIF_Pos)
#define    CANFD_CFDGTINTSTS_CFTIF                                CANFD_CFDGTINTSTS_CFTIF_Msk

#define    CANFD_CFDGTINTSTS_TQIF_Pos                             (2U)
#define    CANFD_CFDGTINTSTS_TQIF_Msk                             (0x1U << CANFD_CFDGTINTSTS_TQIF_Pos)
#define    CANFD_CFDGTINTSTS_TQIF                                 CANFD_CFDGTINTSTS_TQIF_Msk

#define    CANFD_CFDGTINTSTS_TAIF_Pos                             (1U)
#define    CANFD_CFDGTINTSTS_TAIF_Msk                             (0x1U << CANFD_CFDGTINTSTS_TAIF_Pos)
#define    CANFD_CFDGTINTSTS_TAIF                                 CANFD_CFDGTINTSTS_TAIF_Msk

#define    CANFD_CFDGTINTSTS_TSIF_Pos                             (0U)
#define    CANFD_CFDGTINTSTS_TSIF_Msk                             (0x1U << CANFD_CFDGTINTSTS_TSIF_Pos)
#define    CANFD_CFDGTINTSTS_TSIF                                 CANFD_CFDGTINTSTS_TSIF_Msk

#define    CANFD_CFDGTSC_TS_Pos                                   (0U)
#define    CANFD_CFDGTSC_TS_Msk                                   (0xffffU << CANFD_CFDGTSC_TS_Pos)
#define    CANFD_CFDGTSC_TS                                       CANFD_CFDGTSC_TS_Msk

#define    CANFD_CFDGAFLECTR_AFLDAE_Pos                           (8U)
#define    CANFD_CFDGAFLECTR_AFLDAE_Msk                           (0x1U << CANFD_CFDGAFLECTR_AFLDAE_Pos)
#define    CANFD_CFDGAFLECTR_AFLDAE                               CANFD_CFDGAFLECTR_AFLDAE_Msk

#define    CANFD_CFDGAFLECTR_AFLPN_Pos                            (0U)
#define    CANFD_CFDGAFLECTR_AFLPN_Msk                            (0x1U << CANFD_CFDGAFLECTR_AFLPN_Pos)
#define    CANFD_CFDGAFLECTR_AFLPN                                CANFD_CFDGAFLECTR_AFLPN_Msk

#define    CANFD_CFDGAFLCFG_RNC_Pos                               (16U)
#define    CANFD_CFDGAFLCFG_RNC_Msk                               (0x3fU << CANFD_CFDGAFLCFG_RNC_Pos)
#define    CANFD_CFDGAFLCFG_RNC                                   CANFD_CFDGAFLCFG_RNC_Msk

#define    CANFD_CFDGAFLIDr_GAFLIDE_Pos                           (31U)
#define    CANFD_CFDGAFLIDr_GAFLIDE_Msk                           (0x1U << CANFD_CFDGAFLIDr_GAFLIDE_Pos)
#define    CANFD_CFDGAFLIDr_GAFLIDE                               CANFD_CFDGAFLIDr_GAFLIDE_Msk

#define    CANFD_CFDGAFLIDr_GAFLRTR_Pos                           (30U)
#define    CANFD_CFDGAFLIDr_GAFLRTR_Msk                           (0x1U << CANFD_CFDGAFLIDr_GAFLRTR_Pos)
#define    CANFD_CFDGAFLIDr_GAFLRTR                               CANFD_CFDGAFLIDr_GAFLRTR_Msk

#define    CANFD_CFDGAFLIDr_GAFLLB_Pos                            (29U)
#define    CANFD_CFDGAFLIDr_GAFLLB_Msk                            (0x1U << CANFD_CFDGAFLIDr_GAFLLB_Pos)
#define    CANFD_CFDGAFLIDr_GAFLLB                                CANFD_CFDGAFLIDr_GAFLLB_Msk

#define    CANFD_CFDGAFLIDr_GAFLID_Pos                            (0U)
#define    CANFD_CFDGAFLIDr_GAFLID_Msk                            (0x1fffffffU << CANFD_CFDGAFLIDr_GAFLID_Pos)
#define    CANFD_CFDGAFLIDr_GAFLID                                CANFD_CFDGAFLIDr_GAFLID_Msk

#define    CANFD_CFDGAFLMr_GAFLIDEM_Pos                           (31U)
#define    CANFD_CFDGAFLMr_GAFLIDEM_Msk                           (0x1U << CANFD_CFDGAFLMr_GAFLIDEM_Pos)
#define    CANFD_CFDGAFLMr_GAFLIDEM                               CANFD_CFDGAFLMr_GAFLIDEM_Msk

#define    CANFD_CFDGAFLMr_GAFLRTRM_Pos                           (30U)
#define    CANFD_CFDGAFLMr_GAFLRTRM_Msk                           (0x1U << CANFD_CFDGAFLMr_GAFLRTRM_Pos)
#define    CANFD_CFDGAFLMr_GAFLRTRM                               CANFD_CFDGAFLMr_GAFLRTRM_Msk

#define    CANFD_CFDGAFLMr_GAFLIFL1_Pos                           (29U)
#define    CANFD_CFDGAFLMr_GAFLIFL1_Msk                           (0x1U << CANFD_CFDGAFLMr_GAFLIFL1_Pos)
#define    CANFD_CFDGAFLMr_GAFLIFL1                               CANFD_CFDGAFLMr_GAFLIFL1_Msk

#define    CANFD_CFDGAFLMr_GAFLIDM_Pos                            (0U)
#define    CANFD_CFDGAFLMr_GAFLIDM_Msk                            (0x1fffffffU << CANFD_CFDGAFLMr_GAFLIDM_Pos)
#define    CANFD_CFDGAFLMr_GAFLIDM                                CANFD_CFDGAFLMr_GAFLIDM_Msk

#define    CANFD_CFDGAFLP0r_GAFLPTR_Pos                           (16U)
#define    CANFD_CFDGAFLP0r_GAFLPTR_Msk                           (0xffffU << CANFD_CFDGAFLP0r_GAFLPTR_Pos)
#define    CANFD_CFDGAFLP0r_GAFLPTR                               CANFD_CFDGAFLP0r_GAFLPTR_Msk

#define    CANFD_CFDGAFLP0r_GAFLRMV_Pos                           (15U)
#define    CANFD_CFDGAFLP0r_GAFLRMV_Msk                           (0x1U << CANFD_CFDGAFLP0r_GAFLRMV_Pos)
#define    CANFD_CFDGAFLP0r_GAFLRMV                               CANFD_CFDGAFLP0r_GAFLRMV_Msk

#define    CANFD_CFDGAFLP0r_GAFLRMDP_Pos                          (8U)
#define    CANFD_CFDGAFLP0r_GAFLRMDP_Msk                          (0x1fU << CANFD_CFDGAFLP0r_GAFLRMDP_Pos)
#define    CANFD_CFDGAFLP0r_GAFLRMDP                              CANFD_CFDGAFLP0r_GAFLRMDP_Msk

#define    CANFD_CFDGAFLP0r_GAFLIFL0_Pos                          (7U)
#define    CANFD_CFDGAFLP0r_GAFLIFL0_Msk                          (0x1U << CANFD_CFDGAFLP0r_GAFLIFL0_Pos)
#define    CANFD_CFDGAFLP0r_GAFLIFL0                              CANFD_CFDGAFLP0r_GAFLIFL0_Msk

#define    CANFD_CFDGAFLP0r_GAFLDLC_Pos                           (0U)
#define    CANFD_CFDGAFLP0r_GAFLDLC_Msk                           (0xfU << CANFD_CFDGAFLP0r_GAFLDLC_Pos)
#define    CANFD_CFDGAFLP0r_GAFLDLC                               CANFD_CFDGAFLP0r_GAFLDLC_Msk

#define    CANFD_CFDGAFLP1r_GAFLFDPH_Pos                          (8U)
#define    CANFD_CFDGAFLP1r_GAFLFDPH_Msk                          (0x1U << CANFD_CFDGAFLP1r_GAFLFDPH_Pos)
#define    CANFD_CFDGAFLP1r_GAFLFDPH                              CANFD_CFDGAFLP1r_GAFLFDPH_Msk

#define    CANFD_CFDGAFLP1r_GAFLFDPL_Pos                          (0U)
#define    CANFD_CFDGAFLP1r_GAFLFDPL_Msk                          (0x1U << CANFD_CFDGAFLP1r_GAFLFDPL_Pos)
#define    CANFD_CFDGAFLP1r_GAFLFDPL                              CANFD_CFDGAFLP1r_GAFLFDPL_Msk

#define    CANFD_CFDRMNB_RMPLS_Pos                                (8U)
#define    CANFD_CFDRMNB_RMPLS_Msk                                (0x7U << CANFD_CFDRMNB_RMPLS_Pos)
#define    CANFD_CFDRMNB_RMPLS                                    CANFD_CFDRMNB_RMPLS_Msk

#define    CANFD_CFDRMNB_NRXMB_Pos                                (0U)
#define    CANFD_CFDRMNB_NRXMB_Msk                                (0x3fU << CANFD_CFDRMNB_NRXMB_Pos)
#define    CANFD_CFDRMNB_NRXMB                                    CANFD_CFDRMNB_NRXMB_Msk

#define    CANFD_CFDRMND_RMNSu_Pos                                (0U)
#define    CANFD_CFDRMND_RMNSu_Msk                                (0x1U << CANFD_CFDRMND_RMNSu_Pos)
#define    CANFD_CFDRMND_RMNSu                                    CANFD_CFDRMND_RMNSu_Msk

#define    CANFD_CFDRFCCa_RFIGCV_Pos                              (13U)
#define    CANFD_CFDRFCCa_RFIGCV_Msk                              (0x7U << CANFD_CFDRFCCa_RFIGCV_Pos)
#define    CANFD_CFDRFCCa_RFIGCV                                  CANFD_CFDRFCCa_RFIGCV_Msk

#define    CANFD_CFDRFCCa_RFIM_Pos                                (12U)
#define    CANFD_CFDRFCCa_RFIM_Msk                                (0x1U << CANFD_CFDRFCCa_RFIM_Pos)
#define    CANFD_CFDRFCCa_RFIM                                    CANFD_CFDRFCCa_RFIM_Msk

#define    CANFD_CFDRFCCa_RFDC_Pos                                (8U)
#define    CANFD_CFDRFCCa_RFDC_Msk                                (0x7U << CANFD_CFDRFCCa_RFDC_Pos)
#define    CANFD_CFDRFCCa_RFDC                                    CANFD_CFDRFCCa_RFDC_Msk

#define    CANFD_CFDRFCCa_RFPLS_Pos                               (4U)
#define    CANFD_CFDRFCCa_RFPLS_Msk                               (0x7U << CANFD_CFDRFCCa_RFPLS_Pos)
#define    CANFD_CFDRFCCa_RFPLS                                   CANFD_CFDRFCCa_RFPLS_Msk

#define    CANFD_CFDRFCCa_RFIE_Pos                                (1U)
#define    CANFD_CFDRFCCa_RFIE_Msk                                (0x1U << CANFD_CFDRFCCa_RFIE_Pos)
#define    CANFD_CFDRFCCa_RFIE                                    CANFD_CFDRFCCa_RFIE_Msk

#define    CANFD_CFDRFCCa_RFE_Pos                                 (0U)
#define    CANFD_CFDRFCCa_RFE_Msk                                 (0x1U << CANFD_CFDRFCCa_RFE_Pos)
#define    CANFD_CFDRFCCa_RFE                                     CANFD_CFDRFCCa_RFE_Msk

#define    CANFD_CFDRFSTSa_RFMC_Pos                               (8U)
#define    CANFD_CFDRFSTSa_RFMC_Msk                               (0x3fU << CANFD_CFDRFSTSa_RFMC_Pos)
#define    CANFD_CFDRFSTSa_RFMC                                   CANFD_CFDRFSTSa_RFMC_Msk

#define    CANFD_CFDRFSTSa_RFIF_Pos                               (3U)
#define    CANFD_CFDRFSTSa_RFIF_Msk                               (0x1U << CANFD_CFDRFSTSa_RFIF_Pos)
#define    CANFD_CFDRFSTSa_RFIF                                   CANFD_CFDRFSTSa_RFIF_Msk

#define    CANFD_CFDRFSTSa_RFMLT_Pos                              (2U)
#define    CANFD_CFDRFSTSa_RFMLT_Msk                              (0x1U << CANFD_CFDRFSTSa_RFMLT_Pos)
#define    CANFD_CFDRFSTSa_RFMLT                                  CANFD_CFDRFSTSa_RFMLT_Msk

#define    CANFD_CFDRFSTSa_RFFLL_Pos                              (1U)
#define    CANFD_CFDRFSTSa_RFFLL_Msk                              (0x1U << CANFD_CFDRFSTSa_RFFLL_Pos)
#define    CANFD_CFDRFSTSa_RFFLL                                  CANFD_CFDRFSTSa_RFFLL_Msk

#define    CANFD_CFDRFSTSa_RFEMP_Pos                              (0U)
#define    CANFD_CFDRFSTSa_RFEMP_Msk                              (0x1U << CANFD_CFDRFSTSa_RFEMP_Pos)
#define    CANFD_CFDRFSTSa_RFEMP                                  CANFD_CFDRFSTSa_RFEMP_Msk

#define    CANFD_CFDRFPCTRa_RFPC_Pos                              (0U)
#define    CANFD_CFDRFPCTRa_RFPC_Msk                              (0xffU << CANFD_CFDRFPCTRa_RFPC_Pos)
#define    CANFD_CFDRFPCTRa_RFPC                                  CANFD_CFDRFPCTRa_RFPC_Msk

#define    CANFD_CFDCFCC_CFITT_Pos                                (24U)
#define    CANFD_CFDCFCC_CFITT_Msk                                (0xffU << CANFD_CFDCFCC_CFITT_Pos)
#define    CANFD_CFDCFCC_CFITT                                    CANFD_CFDCFCC_CFITT_Msk

#define    CANFD_CFDCFCC_CFDC_Pos                                 (21U)
#define    CANFD_CFDCFCC_CFDC_Msk                                 (0x7U << CANFD_CFDCFCC_CFDC_Pos)
#define    CANFD_CFDCFCC_CFDC                                     CANFD_CFDCFCC_CFDC_Msk

#define    CANFD_CFDCFCC_CFTML_Pos                                (16U)
#define    CANFD_CFDCFCC_CFTML_Msk                                (0x3U << CANFD_CFDCFCC_CFTML_Pos)
#define    CANFD_CFDCFCC_CFTML                                    CANFD_CFDCFCC_CFTML_Msk

#define    CANFD_CFDCFCC_CFIGCV_Pos                               (13U)
#define    CANFD_CFDCFCC_CFIGCV_Msk                               (0x7U << CANFD_CFDCFCC_CFIGCV_Pos)
#define    CANFD_CFDCFCC_CFIGCV                                   CANFD_CFDCFCC_CFIGCV_Msk

#define    CANFD_CFDCFCC_CFIM_Pos                                 (12U)
#define    CANFD_CFDCFCC_CFIM_Msk                                 (0x1U << CANFD_CFDCFCC_CFIM_Pos)
#define    CANFD_CFDCFCC_CFIM                                     CANFD_CFDCFCC_CFIM_Msk

#define    CANFD_CFDCFCC_CFITR_Pos                                (11U)
#define    CANFD_CFDCFCC_CFITR_Msk                                (0x1U << CANFD_CFDCFCC_CFITR_Pos)
#define    CANFD_CFDCFCC_CFITR                                    CANFD_CFDCFCC_CFITR_Msk

#define    CANFD_CFDCFCC_CFITSS_Pos                               (10U)
#define    CANFD_CFDCFCC_CFITSS_Msk                               (0x1U << CANFD_CFDCFCC_CFITSS_Pos)
#define    CANFD_CFDCFCC_CFITSS                                   CANFD_CFDCFCC_CFITSS_Msk

#define    CANFD_CFDCFCC_CFM_Pos                                  (8U)
#define    CANFD_CFDCFCC_CFM_Msk                                  (0x1U << CANFD_CFDCFCC_CFM_Pos)
#define    CANFD_CFDCFCC_CFM                                      CANFD_CFDCFCC_CFM_Msk

#define    CANFD_CFDCFCC_CFPLS_Pos                                (4U)
#define    CANFD_CFDCFCC_CFPLS_Msk                                (0x7U << CANFD_CFDCFCC_CFPLS_Pos)
#define    CANFD_CFDCFCC_CFPLS                                    CANFD_CFDCFCC_CFPLS_Msk

#define    CANFD_CFDCFCC_CFTXIE_Pos                               (2U)
#define    CANFD_CFDCFCC_CFTXIE_Msk                               (0x1U << CANFD_CFDCFCC_CFTXIE_Pos)
#define    CANFD_CFDCFCC_CFTXIE                                   CANFD_CFDCFCC_CFTXIE_Msk

#define    CANFD_CFDCFCC_CFRXIE_Pos                               (1U)
#define    CANFD_CFDCFCC_CFRXIE_Msk                               (0x1U << CANFD_CFDCFCC_CFRXIE_Pos)
#define    CANFD_CFDCFCC_CFRXIE                                   CANFD_CFDCFCC_CFRXIE_Msk

#define    CANFD_CFDCFCC_CFE_Pos                                  (0U)
#define    CANFD_CFDCFCC_CFE_Msk                                  (0x1U << CANFD_CFDCFCC_CFE_Pos)
#define    CANFD_CFDCFCC_CFE                                      CANFD_CFDCFCC_CFE_Msk

#define    CANFD_CFDCFSTS_CFMC_Pos                                (8U)
#define    CANFD_CFDCFSTS_CFMC_Msk                                (0x3fU << CANFD_CFDCFSTS_CFMC_Pos)
#define    CANFD_CFDCFSTS_CFMC                                    CANFD_CFDCFSTS_CFMC_Msk

#define    CANFD_CFDCFSTS_CFTXIF_Pos                              (4U)
#define    CANFD_CFDCFSTS_CFTXIF_Msk                              (0x1U << CANFD_CFDCFSTS_CFTXIF_Pos)
#define    CANFD_CFDCFSTS_CFTXIF                                  CANFD_CFDCFSTS_CFTXIF_Msk

#define    CANFD_CFDCFSTS_CFRXIF_Pos                              (3U)
#define    CANFD_CFDCFSTS_CFRXIF_Msk                              (0x1U << CANFD_CFDCFSTS_CFRXIF_Pos)
#define    CANFD_CFDCFSTS_CFRXIF                                  CANFD_CFDCFSTS_CFRXIF_Msk

#define    CANFD_CFDCFSTS_CFMLT_Pos                               (2U)
#define    CANFD_CFDCFSTS_CFMLT_Msk                               (0x1U << CANFD_CFDCFSTS_CFMLT_Pos)
#define    CANFD_CFDCFSTS_CFMLT                                   CANFD_CFDCFSTS_CFMLT_Msk

#define    CANFD_CFDCFSTS_CFFLL_Pos                               (1U)
#define    CANFD_CFDCFSTS_CFFLL_Msk                               (0x1U << CANFD_CFDCFSTS_CFFLL_Pos)
#define    CANFD_CFDCFSTS_CFFLL                                   CANFD_CFDCFSTS_CFFLL_Msk

#define    CANFD_CFDCFSTS_CFEMP_Pos                               (0U)
#define    CANFD_CFDCFSTS_CFEMP_Msk                               (0x1U << CANFD_CFDCFSTS_CFEMP_Pos)
#define    CANFD_CFDCFSTS_CFEMP                                   CANFD_CFDCFSTS_CFEMP_Msk

#define    CANFD_CFDCFPCTR_CFPC_Pos                               (0U)
#define    CANFD_CFDCFPCTR_CFPC_Msk                               (0xffU << CANFD_CFDCFPCTR_CFPC_Pos)
#define    CANFD_CFDCFPCTR_CFPC                                   CANFD_CFDCFPCTR_CFPC_Msk

#define    CANFD_CFDFESTS_CFEMP_Pos                               (8U)
#define    CANFD_CFDFESTS_CFEMP_Msk                               (0x1U << CANFD_CFDFESTS_CFEMP_Pos)
#define    CANFD_CFDFESTS_CFEMP                                   CANFD_CFDFESTS_CFEMP_Msk

#define    CANFD_CFDFESTS_RFxEMP_Pos                              (0U)
#define    CANFD_CFDFESTS_RFxEMP_Msk                              (0x1U << CANFD_CFDFESTS_RFxEMP_Pos)
#define    CANFD_CFDFESTS_RFxEMP                                  CANFD_CFDFESTS_RFxEMP_Msk

#define    CANFD_CFDFFSTS_CFFLL_Pos                               (8U)
#define    CANFD_CFDFFSTS_CFFLL_Msk                               (0x1U << CANFD_CFDFFSTS_CFFLL_Pos)
#define    CANFD_CFDFFSTS_CFFLL                                   CANFD_CFDFFSTS_CFFLL_Msk

#define    CANFD_CFDFFSTS_RFxFLL_Pos                              (0U)
#define    CANFD_CFDFFSTS_RFxFLL_Msk                              (0x1U << CANFD_CFDFFSTS_RFxFLL_Pos)
#define    CANFD_CFDFFSTS_RFxFLL                                  CANFD_CFDFFSTS_RFxFLL_Msk

#define    CANFD_CFDFMSTS_CFMLT_Pos                               (8U)
#define    CANFD_CFDFMSTS_CFMLT_Msk                               (0x1U << CANFD_CFDFMSTS_CFMLT_Pos)
#define    CANFD_CFDFMSTS_CFMLT                                   CANFD_CFDFMSTS_CFMLT_Msk

#define    CANFD_CFDFMSTS_RFxMLT_Pos                              (0U)
#define    CANFD_CFDFMSTS_RFxMLT_Msk                              (0x1U << CANFD_CFDFMSTS_RFxMLT_Pos)
#define    CANFD_CFDFMSTS_RFxMLT                                  CANFD_CFDFMSTS_RFxMLT_Msk

#define    CANFD_CFDRFISTS_RFxIF_Pos                              (0U)
#define    CANFD_CFDRFISTS_RFxIF_Msk                              (0x1U << CANFD_CFDRFISTS_RFxIF_Pos)
#define    CANFD_CFDRFISTS_RFxIF                                  CANFD_CFDRFISTS_RFxIF_Msk

#define    CANFD_CFDTMCi_TMOM_Pos                                 (2U)
#define    CANFD_CFDTMCi_TMOM_Msk                                 (0x1U << CANFD_CFDTMCi_TMOM_Pos)
#define    CANFD_CFDTMCi_TMOM                                     CANFD_CFDTMCi_TMOM_Msk

#define    CANFD_CFDTMCi_TMTAR_Pos                                (1U)
#define    CANFD_CFDTMCi_TMTAR_Msk                                (0x1U << CANFD_CFDTMCi_TMTAR_Pos)
#define    CANFD_CFDTMCi_TMTAR                                    CANFD_CFDTMCi_TMTAR_Msk

#define    CANFD_CFDTMCi_TMTR_Pos                                 (0U)
#define    CANFD_CFDTMCi_TMTR_Msk                                 (0x1U << CANFD_CFDTMCi_TMTR_Pos)
#define    CANFD_CFDTMCi_TMTR                                     CANFD_CFDTMCi_TMTR_Msk

#define    CANFD_CFDTMSTSj_TMTARM_Pos                             (4U)
#define    CANFD_CFDTMSTSj_TMTARM_Msk                             (0x1U << CANFD_CFDTMSTSj_TMTARM_Pos)
#define    CANFD_CFDTMSTSj_TMTARM                                 CANFD_CFDTMSTSj_TMTARM_Msk

#define    CANFD_CFDTMSTSj_TMTRM_Pos                              (3U)
#define    CANFD_CFDTMSTSj_TMTRM_Msk                              (0x1U << CANFD_CFDTMSTSj_TMTRM_Pos)
#define    CANFD_CFDTMSTSj_TMTRM                                  CANFD_CFDTMSTSj_TMTRM_Msk

#define    CANFD_CFDTMSTSj_TMTRF_Pos                              (1U)
#define    CANFD_CFDTMSTSj_TMTRF_Msk                              (0x3U << CANFD_CFDTMSTSj_TMTRF_Pos)
#define    CANFD_CFDTMSTSj_TMTRF                                  CANFD_CFDTMSTSj_TMTRF_Msk

#define    CANFD_CFDTMSTSj_TMTSTS_Pos                             (0U)
#define    CANFD_CFDTMSTSj_TMTSTS_Msk                             (0x1U << CANFD_CFDTMSTSj_TMTSTS_Pos)
#define    CANFD_CFDTMSTSj_TMTSTS                                 CANFD_CFDTMSTSj_TMTSTS_Msk

#define    CANFD_CFDTMTRSTS_CFDTMTRSTSg_Pos                       (0U)
#define    CANFD_CFDTMTRSTS_CFDTMTRSTSg_Msk                       (0x1U << CANFD_CFDTMTRSTS_CFDTMTRSTSg_Pos)
#define    CANFD_CFDTMTRSTS_CFDTMTRSTSg                           CANFD_CFDTMTRSTS_CFDTMTRSTSg_Msk

#define    CANFD_CFDTMTARSTS_CFDTMTARSTSg_Pos                     (0U)
#define    CANFD_CFDTMTARSTS_CFDTMTARSTSg_Msk                     (0x1U << CANFD_CFDTMTARSTS_CFDTMTARSTSg_Pos)
#define    CANFD_CFDTMTARSTS_CFDTMTARSTSg                         CANFD_CFDTMTARSTS_CFDTMTARSTSg_Msk

#define    CANFD_CFDTMTCSTS_CFDTMTCSTSg_Pos                       (0U)
#define    CANFD_CFDTMTCSTS_CFDTMTCSTSg_Msk                       (0x1U << CANFD_CFDTMTCSTS_CFDTMTCSTSg_Pos)
#define    CANFD_CFDTMTCSTS_CFDTMTCSTSg                           CANFD_CFDTMTCSTS_CFDTMTCSTSg_Msk

#define    CANFD_CFDTMTASTS_CFDTMTASTSg_Pos                       (0U)
#define    CANFD_CFDTMTASTS_CFDTMTASTSg_Msk                       (0x1U << CANFD_CFDTMTASTS_CFDTMTASTSg_Pos)
#define    CANFD_CFDTMTASTS_CFDTMTASTSg                           CANFD_CFDTMTASTS_CFDTMTASTSg_Msk

#define    CANFD_CFDTMIEC_TMIEg_Pos                               (0U)
#define    CANFD_CFDTMIEC_TMIEg_Msk                               (0x1U << CANFD_CFDTMIEC_TMIEg_Pos)
#define    CANFD_CFDTMIEC_TMIEg                                   CANFD_CFDTMIEC_TMIEg_Msk

#define    CANFD_CFDTXQCC_TXQDC_Pos                               (8U)
#define    CANFD_CFDTXQCC_TXQDC_Msk                               (0x3U << CANFD_CFDTXQCC_TXQDC_Pos)
#define    CANFD_CFDTXQCC_TXQDC                                   CANFD_CFDTXQCC_TXQDC_Msk

#define    CANFD_CFDTXQCC_TXQIM_Pos                               (7U)
#define    CANFD_CFDTXQCC_TXQIM_Msk                               (0x1U << CANFD_CFDTXQCC_TXQIM_Pos)
#define    CANFD_CFDTXQCC_TXQIM                                   CANFD_CFDTXQCC_TXQIM_Msk

#define    CANFD_CFDTXQCC_TXQTXIE_Pos                             (5U)
#define    CANFD_CFDTXQCC_TXQTXIE_Msk                             (0x1U << CANFD_CFDTXQCC_TXQTXIE_Pos)
#define    CANFD_CFDTXQCC_TXQTXIE                                 CANFD_CFDTXQCC_TXQTXIE_Msk

#define    CANFD_CFDTXQCC_TXQE_Pos                                (0U)
#define    CANFD_CFDTXQCC_TXQE_Msk                                (0x1U << CANFD_CFDTXQCC_TXQE_Pos)
#define    CANFD_CFDTXQCC_TXQE                                    CANFD_CFDTXQCC_TXQE_Msk

#define    CANFD_CFDTXQSTS_TXQMC_Pos                              (8U)
#define    CANFD_CFDTXQSTS_TXQMC_Msk                              (0x7U << CANFD_CFDTXQSTS_TXQMC_Pos)
#define    CANFD_CFDTXQSTS_TXQMC                                  CANFD_CFDTXQSTS_TXQMC_Msk

#define    CANFD_CFDTXQSTS_TXQTXIF_Pos                            (2U)
#define    CANFD_CFDTXQSTS_TXQTXIF_Msk                            (0x1U << CANFD_CFDTXQSTS_TXQTXIF_Pos)
#define    CANFD_CFDTXQSTS_TXQTXIF                                CANFD_CFDTXQSTS_TXQTXIF_Msk

#define    CANFD_CFDTXQSTS_TXQFLL_Pos                             (1U)
#define    CANFD_CFDTXQSTS_TXQFLL_Msk                             (0x1U << CANFD_CFDTXQSTS_TXQFLL_Pos)
#define    CANFD_CFDTXQSTS_TXQFLL                                 CANFD_CFDTXQSTS_TXQFLL_Msk

#define    CANFD_CFDTXQSTS_TXQEMP_Pos                             (0U)
#define    CANFD_CFDTXQSTS_TXQEMP_Msk                             (0x1U << CANFD_CFDTXQSTS_TXQEMP_Pos)
#define    CANFD_CFDTXQSTS_TXQEMP                                 CANFD_CFDTXQSTS_TXQEMP_Msk

#define    CANFD_CFDTXQPCTR_TXQPC_Pos                             (0U)
#define    CANFD_CFDTXQPCTR_TXQPC_Msk                             (0xffU << CANFD_CFDTXQPCTR_TXQPC_Pos)
#define    CANFD_CFDTXQPCTR_TXQPC                                 CANFD_CFDTXQPCTR_TXQPC_Msk

#define    CANFD_CFDTHLCC_THLDTE_Pos                              (10U)
#define    CANFD_CFDTHLCC_THLDTE_Msk                              (0x1U << CANFD_CFDTHLCC_THLDTE_Pos)
#define    CANFD_CFDTHLCC_THLDTE                                  CANFD_CFDTHLCC_THLDTE_Msk

#define    CANFD_CFDTHLCC_THLIM_Pos                               (9U)
#define    CANFD_CFDTHLCC_THLIM_Msk                               (0x1U << CANFD_CFDTHLCC_THLIM_Pos)
#define    CANFD_CFDTHLCC_THLIM                                   CANFD_CFDTHLCC_THLIM_Msk

#define    CANFD_CFDTHLCC_THLIE_Pos                               (8U)
#define    CANFD_CFDTHLCC_THLIE_Msk                               (0x1U << CANFD_CFDTHLCC_THLIE_Pos)
#define    CANFD_CFDTHLCC_THLIE                                   CANFD_CFDTHLCC_THLIE_Msk

#define    CANFD_CFDTHLCC_THLE_Pos                                (0U)
#define    CANFD_CFDTHLCC_THLE_Msk                                (0x1U << CANFD_CFDTHLCC_THLE_Pos)
#define    CANFD_CFDTHLCC_THLE                                    CANFD_CFDTHLCC_THLE_Msk

#define    CANFD_CFDTHLSTS_THLMC_Pos                              (8U)
#define    CANFD_CFDTHLSTS_THLMC_Msk                              (0xfU << CANFD_CFDTHLSTS_THLMC_Pos)
#define    CANFD_CFDTHLSTS_THLMC                                  CANFD_CFDTHLSTS_THLMC_Msk

#define    CANFD_CFDTHLSTS_THLIF_Pos                              (3U)
#define    CANFD_CFDTHLSTS_THLIF_Msk                              (0x1U << CANFD_CFDTHLSTS_THLIF_Pos)
#define    CANFD_CFDTHLSTS_THLIF                                  CANFD_CFDTHLSTS_THLIF_Msk

#define    CANFD_CFDTHLSTS_THLELT_Pos                             (2U)
#define    CANFD_CFDTHLSTS_THLELT_Msk                             (0x1U << CANFD_CFDTHLSTS_THLELT_Pos)
#define    CANFD_CFDTHLSTS_THLELT                                 CANFD_CFDTHLSTS_THLELT_Msk

#define    CANFD_CFDTHLSTS_THLFLL_Pos                             (1U)
#define    CANFD_CFDTHLSTS_THLFLL_Msk                             (0x1U << CANFD_CFDTHLSTS_THLFLL_Pos)
#define    CANFD_CFDTHLSTS_THLFLL                                 CANFD_CFDTHLSTS_THLFLL_Msk

#define    CANFD_CFDTHLSTS_THLEMP_Pos                             (0U)
#define    CANFD_CFDTHLSTS_THLEMP_Msk                             (0x1U << CANFD_CFDTHLSTS_THLEMP_Pos)
#define    CANFD_CFDTHLSTS_THLEMP                                 CANFD_CFDTHLSTS_THLEMP_Msk

#define    CANFD_CFDTHLACC0_TMTS_Pos                              (16U)
#define    CANFD_CFDTHLACC0_TMTS_Msk                              (0xffffU << CANFD_CFDTHLACC0_TMTS_Pos)
#define    CANFD_CFDTHLACC0_TMTS                                  CANFD_CFDTHLACC0_TMTS_Msk

#define    CANFD_CFDTHLACC0_BN_Pos                                (3U)
#define    CANFD_CFDTHLACC0_BN_Msk                                (0x3U << CANFD_CFDTHLACC0_BN_Pos)
#define    CANFD_CFDTHLACC0_BN                                    CANFD_CFDTHLACC0_BN_Msk

#define    CANFD_CFDTHLACC0_BT_Pos                                (0U)
#define    CANFD_CFDTHLACC0_BT_Msk                                (0x7U << CANFD_CFDTHLACC0_BT_Pos)
#define    CANFD_CFDTHLACC0_BT                                    CANFD_CFDTHLACC0_BT_Msk

#define    CANFD_CFDTHLACC1_TIFL_Pos                              (16U)
#define    CANFD_CFDTHLACC1_TIFL_Msk                              (0x3U << CANFD_CFDTHLACC1_TIFL_Pos)
#define    CANFD_CFDTHLACC1_TIFL                                  CANFD_CFDTHLACC1_TIFL_Msk

#define    CANFD_CFDTHLACC1_TID_Pos                               (0U)
#define    CANFD_CFDTHLACC1_TID_Msk                               (0xffffU << CANFD_CFDTHLACC1_TID_Pos)
#define    CANFD_CFDTHLACC1_TID                                   CANFD_CFDTHLACC1_TID_Msk

#define    CANFD_CFDTHLPCTR_THLPC_Pos                             (0U)
#define    CANFD_CFDTHLPCTR_THLPC_Msk                             (0xffU << CANFD_CFDTHLPCTR_THLPC_Pos)
#define    CANFD_CFDTHLPCTR_THLPC                                 CANFD_CFDTHLPCTR_THLPC_Msk

#define    CANFD_CFDGRSTC_KEY_Pos                                 (8U)
#define    CANFD_CFDGRSTC_KEY_Msk                                 (0xffU << CANFD_CFDGRSTC_KEY_Pos)
#define    CANFD_CFDGRSTC_KEY                                     CANFD_CFDGRSTC_KEY_Msk

#define    CANFD_CFDGRSTC_SRST_Pos                                (0U)
#define    CANFD_CFDGRSTC_SRST_Msk                                (0x1U << CANFD_CFDGRSTC_SRST_Pos)
#define    CANFD_CFDGRSTC_SRST                                    CANFD_CFDGRSTC_SRST_Msk

#define    CANFD_CFDWKCR_CFD0WKIE_Pos                             (8U)
#define    CANFD_CFDWKCR_CFD0WKIE_Msk                             (0x1U << CANFD_CFDWKCR_CFD0WKIE_Pos)
#define    CANFD_CFDWKCR_CFD0WKIE                                 CANFD_CFDWKCR_CFD0WKIE_Msk

#define    CANFD_CFDWKCR_CFD0WKEN_Pos                             (0U)
#define    CANFD_CFDWKCR_CFD0WKEN_Msk                             (0x1U << CANFD_CFDWKCR_CFD0WKEN_Pos)
#define    CANFD_CFDWKCR_CFD0WKEN                                 CANFD_CFDWKCR_CFD0WKEN_Msk

#define    CANFD_CFDWKSR_CFD0WKIF_Pos                             (0U)
#define    CANFD_CFDWKSR_CFD0WKIF_Msk                             (0x1U << CANFD_CFDWKSR_CFD0WKIF_Pos)
#define    CANFD_CFDWKSR_CFD0WKIF                                 CANFD_CFDWKSR_CFD0WKIF_Msk

#define    CANFD_CFDGTSTCFG_RTMPS_Pos                             (16U)
#define    CANFD_CFDGTSTCFG_RTMPS_Msk                             (0xfU << CANFD_CFDGTSTCFG_RTMPS_Pos)
#define    CANFD_CFDGTSTCFG_RTMPS                                 CANFD_CFDGTSTCFG_RTMPS_Msk

#define    CANFD_CFDGTSTCTR_RTME_Pos                              (2U)
#define    CANFD_CFDGTSTCTR_RTME_Msk                              (0x1U << CANFD_CFDGTSTCTR_RTME_Pos)
#define    CANFD_CFDGTSTCTR_RTME                                  CANFD_CFDGTSTCTR_RTME_Msk

#define    CANFD_CFDGFDCFG_TSCCFG_Pos                             (8U)
#define    CANFD_CFDGFDCFG_TSCCFG_Msk                             (0x3U << CANFD_CFDGFDCFG_TSCCFG_Pos)
#define    CANFD_CFDGFDCFG_TSCCFG                                 CANFD_CFDGFDCFG_TSCCFG_Msk

#define    CANFD_CFDGFDCFG_RPED_Pos                               (0U)
#define    CANFD_CFDGFDCFG_RPED_Msk                               (0x1U << CANFD_CFDGFDCFG_RPED_Pos)
#define    CANFD_CFDGFDCFG_RPED                                   CANFD_CFDGFDCFG_RPED_Msk

#define    CANFD_CFDGLOCKK_LOCK_Pos                               (0U)
#define    CANFD_CFDGLOCKK_LOCK_Msk                               (0xffffU << CANFD_CFDGLOCKK_LOCK_Pos)
#define    CANFD_CFDGLOCKK_LOCK                                   CANFD_CFDGLOCKK_LOCK_Msk

#define    CANFD_CFDRPGACCk_RDTA_Pos                              (0U)
#define    CANFD_CFDRPGACCk_RDTA_Msk                              (0xffffffffU << CANFD_CFDRPGACCk_RDTA_Pos)
#define    CANFD_CFDRPGACCk_RDTA                                  CANFD_CFDRPGACCk_RDTA_Msk

#define    CANFD_CFDGPFLECTR_PFLDAE_Pos                           (8U)
#define    CANFD_CFDGPFLECTR_PFLDAE_Msk                           (0x1U << CANFD_CFDGPFLECTR_PFLDAE_Pos)
#define    CANFD_CFDGPFLECTR_PFLDAE                               CANFD_CFDGPFLECTR_PFLDAE_Msk

#define    CANFD_CFDGPFLCFG_RNC_Pos                               (24U)
#define    CANFD_CFDGPFLCFG_RNC_Msk                               (0x3U << CANFD_CFDGPFLCFG_RNC_Pos)
#define    CANFD_CFDGPFLCFG_RNC                                   CANFD_CFDGPFLCFG_RNC_Msk

#define    CANFD_CFDGPFLIDs_GPFLIDE_Pos                           (31U)
#define    CANFD_CFDGPFLIDs_GPFLIDE_Msk                           (0x1U << CANFD_CFDGPFLIDs_GPFLIDE_Pos)
#define    CANFD_CFDGPFLIDs_GPFLIDE                               CANFD_CFDGPFLIDs_GPFLIDE_Msk

#define    CANFD_CFDGPFLIDs_GPFLRTR_Pos                           (30U)
#define    CANFD_CFDGPFLIDs_GPFLRTR_Msk                           (0x1U << CANFD_CFDGPFLIDs_GPFLRTR_Pos)
#define    CANFD_CFDGPFLIDs_GPFLRTR                               CANFD_CFDGPFLIDs_GPFLRTR_Msk

#define    CANFD_CFDGPFLIDs_GPFLLB_Pos                            (29U)
#define    CANFD_CFDGPFLIDs_GPFLLB_Msk                            (0x1U << CANFD_CFDGPFLIDs_GPFLLB_Pos)
#define    CANFD_CFDGPFLIDs_GPFLLB                                CANFD_CFDGPFLIDs_GPFLLB_Msk

#define    CANFD_CFDGPFLIDs_GPFLID_Pos                            (0U)
#define    CANFD_CFDGPFLIDs_GPFLID_Msk                            (0x1fffffffU << CANFD_CFDGPFLIDs_GPFLID_Pos)
#define    CANFD_CFDGPFLIDs_GPFLID                                CANFD_CFDGPFLIDs_GPFLID_Msk

#define    CANFD_CFDGPFLMs_GPFLIDEM_Pos                           (31U)
#define    CANFD_CFDGPFLMs_GPFLIDEM_Msk                           (0x1U << CANFD_CFDGPFLMs_GPFLIDEM_Pos)
#define    CANFD_CFDGPFLMs_GPFLIDEM                               CANFD_CFDGPFLMs_GPFLIDEM_Msk

#define    CANFD_CFDGPFLMs_GPFLRTRM_Pos                           (30U)
#define    CANFD_CFDGPFLMs_GPFLRTRM_Msk                           (0x1U << CANFD_CFDGPFLMs_GPFLRTRM_Pos)
#define    CANFD_CFDGPFLMs_GPFLRTRM                               CANFD_CFDGPFLMs_GPFLRTRM_Msk

#define    CANFD_CFDGPFLMs_GPFLIFL1_Pos                           (29U)
#define    CANFD_CFDGPFLMs_GPFLIFL1_Msk                           (0x1U << CANFD_CFDGPFLMs_GPFLIFL1_Pos)
#define    CANFD_CFDGPFLMs_GPFLIFL1                               CANFD_CFDGPFLMs_GPFLIFL1_Msk

#define    CANFD_CFDGPFLMs_GPFLIDM_Pos                            (0U)
#define    CANFD_CFDGPFLMs_GPFLIDM_Msk                            (0x1fffffffU << CANFD_CFDGPFLMs_GPFLIDM_Pos)
#define    CANFD_CFDGPFLMs_GPFLIDM                                CANFD_CFDGPFLMs_GPFLIDM_Msk

#define    CANFD_CFDGPFLP0s_GPFLPTR_Pos                           (16U)
#define    CANFD_CFDGPFLP0s_GPFLPTR_Msk                           (0xffffU << CANFD_CFDGPFLP0s_GPFLPTR_Pos)
#define    CANFD_CFDGPFLP0s_GPFLPTR                               CANFD_CFDGPFLP0s_GPFLPTR_Msk

#define    CANFD_CFDGPFLP0s_GPFLRMV_Pos                           (15U)
#define    CANFD_CFDGPFLP0s_GPFLRMV_Msk                           (0x1U << CANFD_CFDGPFLP0s_GPFLRMV_Pos)
#define    CANFD_CFDGPFLP0s_GPFLRMV                               CANFD_CFDGPFLP0s_GPFLRMV_Msk

#define    CANFD_CFDGPFLP0s_GPFLRMDP_Pos                          (8U)
#define    CANFD_CFDGPFLP0s_GPFLRMDP_Msk                          (0x1fU << CANFD_CFDGPFLP0s_GPFLRMDP_Pos)
#define    CANFD_CFDGPFLP0s_GPFLRMDP                              CANFD_CFDGPFLP0s_GPFLRMDP_Msk

#define    CANFD_CFDGPFLP0s_GPFLIFL0_Pos                          (7U)
#define    CANFD_CFDGPFLP0s_GPFLIFL0_Msk                          (0x1U << CANFD_CFDGPFLP0s_GPFLIFL0_Pos)
#define    CANFD_CFDGPFLP0s_GPFLIFL0                              CANFD_CFDGPFLP0s_GPFLIFL0_Msk

#define    CANFD_CFDGPFLP0s_GPFLDLC_Pos                           (0U)
#define    CANFD_CFDGPFLP0s_GPFLDLC_Msk                           (0xfU << CANFD_CFDGPFLP0s_GPFLDLC_Pos)
#define    CANFD_CFDGPFLP0s_GPFLDLC                               CANFD_CFDGPFLP0s_GPFLDLC_Msk

#define    CANFD_CFDGPFLP1s_GPFLFDPH_Pos                          (8U)
#define    CANFD_CFDGPFLP1s_GPFLFDPH_Msk                          (0x1U << CANFD_CFDGPFLP1s_GPFLFDPH_Pos)
#define    CANFD_CFDGPFLP1s_GPFLFDPH                              CANFD_CFDGPFLP1s_GPFLFDPH_Msk

#define    CANFD_CFDGPFLP1s_GPFLFDPL_Pos                          (0U)
#define    CANFD_CFDGPFLP1s_GPFLFDPL_Msk                          (0x1U << CANFD_CFDGPFLP1s_GPFLFDPL_Pos)
#define    CANFD_CFDGPFLP1s_GPFLFDPL                              CANFD_CFDGPFLP1s_GPFLFDPL_Msk

#define    CANFD_CFDGPFLPTs_GPFLANDOR_Pos                         (31U)
#define    CANFD_CFDGPFLPTs_GPFLANDOR_Msk                         (0x1U << CANFD_CFDGPFLPTs_GPFLANDOR_Pos)
#define    CANFD_CFDGPFLPTs_GPFLANDOR                             CANFD_CFDGPFLPTs_GPFLANDOR_Msk

#define    CANFD_CFDGPFLPTs_GPFLRANG0_Pos                         (30U)
#define    CANFD_CFDGPFLPTs_GPFLRANG0_Msk                         (0x1U << CANFD_CFDGPFLPTs_GPFLRANG0_Pos)
#define    CANFD_CFDGPFLPTs_GPFLRANG0                             CANFD_CFDGPFLPTs_GPFLRANG0_Msk

#define    CANFD_CFDGPFLPTs_GPFLOUT0_Pos                          (29U)
#define    CANFD_CFDGPFLPTs_GPFLOUT0_Msk                          (0x1U << CANFD_CFDGPFLPTs_GPFLOUT0_Pos)
#define    CANFD_CFDGPFLPTs_GPFLOUT0                              CANFD_CFDGPFLPTs_GPFLOUT0_Msk

#define    CANFD_CFDGPFLPTs_GPFLOFFSET0_Pos                       (16U)
#define    CANFD_CFDGPFLPTs_GPFLOFFSET0_Msk                       (0xfU << CANFD_CFDGPFLPTs_GPFLOFFSET0_Pos)
#define    CANFD_CFDGPFLPTs_GPFLOFFSET0                           CANFD_CFDGPFLPTs_GPFLOFFSET0_Msk

#define    CANFD_CFDGPFLPTs_GPFLRANG1_Pos                         (14U)
#define    CANFD_CFDGPFLPTs_GPFLRANG1_Msk                         (0x1U << CANFD_CFDGPFLPTs_GPFLRANG1_Pos)
#define    CANFD_CFDGPFLPTs_GPFLRANG1                             CANFD_CFDGPFLPTs_GPFLRANG1_Msk

#define    CANFD_CFDGPFLPTs_GPFLOUT1_Pos                          (13U)
#define    CANFD_CFDGPFLPTs_GPFLOUT1_Msk                          (0x1U << CANFD_CFDGPFLPTs_GPFLOUT1_Pos)
#define    CANFD_CFDGPFLPTs_GPFLOUT1                              CANFD_CFDGPFLPTs_GPFLOUT1_Msk

#define    CANFD_CFDGPFLPTs_GPFLOFFSET1_Pos                       (0U)
#define    CANFD_CFDGPFLPTs_GPFLOFFSET1_Msk                       (0xfU << CANFD_CFDGPFLPTs_GPFLOFFSET1_Pos)
#define    CANFD_CFDGPFLPTs_GPFLOFFSET1                           CANFD_CFDGPFLPTs_GPFLOFFSET1_Msk

#define    CANFD_CFDGPFLPD0s_FDATA_Pos                            (0U)
#define    CANFD_CFDGPFLPD0s_FDATA_Msk                            (0xffffffffU << CANFD_CFDGPFLPD0s_FDATA_Pos)
#define    CANFD_CFDGPFLPD0s_FDATA                                CANFD_CFDGPFLPD0s_FDATA_Msk

#define    CANFD_CFDGPFLPD1s_FDATA_Pos                            (0U)
#define    CANFD_CFDGPFLPD1s_FDATA_Msk                            (0xffffffffU << CANFD_CFDGPFLPD1s_FDATA_Pos)
#define    CANFD_CFDGPFLPD1s_FDATA                                CANFD_CFDGPFLPD1s_FDATA_Msk

#define    CANFD_CFDGPFLPM0s_FMASK_Pos                            (0U)
#define    CANFD_CFDGPFLPM0s_FMASK_Msk                            (0xffffffffU << CANFD_CFDGPFLPM0s_FMASK_Pos)
#define    CANFD_CFDGPFLPM0s_FMASK                                CANFD_CFDGPFLPM0s_FMASK_Msk

#define    CANFD_CFDGPFLPM1s_FMASK_Pos                            (0U)
#define    CANFD_CFDGPFLPM1s_FMASK_Msk                            (0xffffffffU << CANFD_CFDGPFLPM1s_FMASK_Pos)
#define    CANFD_CFDGPFLPM1s_FMASK                                CANFD_CFDGPFLPM1s_FMASK_Msk

#define    CANFD_CFDGAFLIGNENT_IRN_Pos                            (0U)
#define    CANFD_CFDGAFLIGNENT_IRN_Msk                            (0x1fU << CANFD_CFDGAFLIGNENT_IRN_Pos)
#define    CANFD_CFDGAFLIGNENT_IRN                                CANFD_CFDGAFLIGNENT_IRN_Msk

#define    CANFD_CFDGAFLIGNCTR_KEY_Pos                            (8U)
#define    CANFD_CFDGAFLIGNCTR_KEY_Msk                            (0xffU << CANFD_CFDGAFLIGNCTR_KEY_Pos)
#define    CANFD_CFDGAFLIGNCTR_KEY                                CANFD_CFDGAFLIGNCTR_KEY_Msk

#define    CANFD_CFDGAFLIGNCTR_IREN_Pos                           (0U)
#define    CANFD_CFDGAFLIGNCTR_IREN_Msk                           (0x1U << CANFD_CFDGAFLIGNCTR_IREN_Pos)
#define    CANFD_CFDGAFLIGNCTR_IREN                               CANFD_CFDGAFLIGNCTR_IREN_Msk

#define    CANFD_CFDRMIEC_RMIEg_Pos                               (0U)
#define    CANFD_CFDRMIEC_RMIEg_Msk                               (0x1U << CANFD_CFDRMIEC_RMIEg_Pos)
#define    CANFD_CFDRMIEC_RMIEg                                   CANFD_CFDRMIEC_RMIEg_Msk

#define    CANFD_CFDRMID_RMIDE_Pos                                (31U)
#define    CANFD_CFDRMID_RMIDE_Msk                                (0x1U << CANFD_CFDRMID_RMIDE_Pos)
#define    CANFD_CFDRMID_RMIDE                                    CANFD_CFDRMID_RMIDE_Msk

#define    CANFD_CFDRMID_RMRTR_Pos                                (30U)
#define    CANFD_CFDRMID_RMRTR_Msk                                (0x1U << CANFD_CFDRMID_RMRTR_Pos)
#define    CANFD_CFDRMID_RMRTR                                    CANFD_CFDRMID_RMRTR_Msk

#define    CANFD_CFDRMID_RMID_Pos                                 (0U)
#define    CANFD_CFDRMID_RMID_Msk                                 (0x1fffffffU << CANFD_CFDRMID_RMID_Pos)
#define    CANFD_CFDRMID_RMID                                     CANFD_CFDRMID_RMID_Msk

#define    CANFD_CFDRMPTR_RMDLC_Pos                               (28U)
#define    CANFD_CFDRMPTR_RMDLC_Msk                               (0xfU << CANFD_CFDRMPTR_RMDLC_Pos)
#define    CANFD_CFDRMPTR_RMDLC                                   CANFD_CFDRMPTR_RMDLC_Msk

#define    CANFD_CFDRMPTR_RMTS_Pos                                (0U)
#define    CANFD_CFDRMPTR_RMTS_Msk                                (0xffffU << CANFD_CFDRMPTR_RMTS_Pos)
#define    CANFD_CFDRMPTR_RMTS                                    CANFD_CFDRMPTR_RMTS_Msk

#define    CANFD_CFDRMFDSTS_RMPTR_Pos                             (16U)
#define    CANFD_CFDRMFDSTS_RMPTR_Msk                             (0xffffU << CANFD_CFDRMFDSTS_RMPTR_Pos)
#define    CANFD_CFDRMFDSTS_RMPTR                                 CANFD_CFDRMFDSTS_RMPTR_Msk

#define    CANFD_CFDRMFDSTS_RMIFL_Pos                             (8U)
#define    CANFD_CFDRMFDSTS_RMIFL_Msk                             (0x3U << CANFD_CFDRMFDSTS_RMIFL_Pos)
#define    CANFD_CFDRMFDSTS_RMIFL                                 CANFD_CFDRMFDSTS_RMIFL_Msk

#define    CANFD_CFDRMFDSTS_RMFDF_Pos                             (2U)
#define    CANFD_CFDRMFDSTS_RMFDF_Msk                             (0x1U << CANFD_CFDRMFDSTS_RMFDF_Pos)
#define    CANFD_CFDRMFDSTS_RMFDF                                 CANFD_CFDRMFDSTS_RMFDF_Msk

#define    CANFD_CFDRMFDSTS_RMBRS_Pos                             (1U)
#define    CANFD_CFDRMFDSTS_RMBRS_Msk                             (0x1U << CANFD_CFDRMFDSTS_RMBRS_Pos)
#define    CANFD_CFDRMFDSTS_RMBRS                                 CANFD_CFDRMFDSTS_RMBRS_Msk

#define    CANFD_CFDRMFDSTS_RMESI_Pos                             (0U)
#define    CANFD_CFDRMFDSTS_RMESI_Msk                             (0x1U << CANFD_CFDRMFDSTS_RMESI_Pos)
#define    CANFD_CFDRMFDSTS_RMESI                                 CANFD_CFDRMFDSTS_RMESI_Msk

#define    CANFD_CFDRMDFp_RMDB_Pos                                (0U)
#define    CANFD_CFDRMDFp_RMDB_Msk                                (0xffffffffU << CANFD_CFDRMDFp_RMDB_Pos)
#define    CANFD_CFDRMDFp_RMDB                                    CANFD_CFDRMDFp_RMDB_Msk

#define    CANFD_CFDRFID_RFIDE_Pos                                (31U)
#define    CANFD_CFDRFID_RFIDE_Msk                                (0x1U << CANFD_CFDRFID_RFIDE_Pos)
#define    CANFD_CFDRFID_RFIDE                                    CANFD_CFDRFID_RFIDE_Msk

#define    CANFD_CFDRFID_RFRTR_Pos                                (30U)
#define    CANFD_CFDRFID_RFRTR_Msk                                (0x1U << CANFD_CFDRFID_RFRTR_Pos)
#define    CANFD_CFDRFID_RFRTR                                    CANFD_CFDRFID_RFRTR_Msk

#define    CANFD_CFDRFID_RFID_Pos                                 (0U)
#define    CANFD_CFDRFID_RFID_Msk                                 (0x1fffffffU << CANFD_CFDRFID_RFID_Pos)
#define    CANFD_CFDRFID_RFID                                     CANFD_CFDRFID_RFID_Msk

#define    CANFD_CFDRFPTR_RFDLC_Pos                               (28U)
#define    CANFD_CFDRFPTR_RFDLC_Msk                               (0xfU << CANFD_CFDRFPTR_RFDLC_Pos)
#define    CANFD_CFDRFPTR_RFDLC                                   CANFD_CFDRFPTR_RFDLC_Msk

#define    CANFD_CFDRFPTR_RFTS_Pos                                (0U)
#define    CANFD_CFDRFPTR_RFTS_Msk                                (0xffffU << CANFD_CFDRFPTR_RFTS_Pos)
#define    CANFD_CFDRFPTR_RFTS                                    CANFD_CFDRFPTR_RFTS_Msk

#define    CANFD_CFDRFFDSTS_CFDRFPTR_Pos                          (16U)
#define    CANFD_CFDRFFDSTS_CFDRFPTR_Msk                          (0xffffU << CANFD_CFDRFFDSTS_CFDRFPTR_Pos)
#define    CANFD_CFDRFFDSTS_CFDRFPTR                              CANFD_CFDRFFDSTS_CFDRFPTR_Msk

#define    CANFD_CFDRFFDSTS_RFIFL_Pos                             (8U)
#define    CANFD_CFDRFFDSTS_RFIFL_Msk                             (0x3U << CANFD_CFDRFFDSTS_RFIFL_Pos)
#define    CANFD_CFDRFFDSTS_RFIFL                                 CANFD_CFDRFFDSTS_RFIFL_Msk

#define    CANFD_CFDRFFDSTS_RFFDF_Pos                             (2U)
#define    CANFD_CFDRFFDSTS_RFFDF_Msk                             (0x1U << CANFD_CFDRFFDSTS_RFFDF_Pos)
#define    CANFD_CFDRFFDSTS_RFFDF                                 CANFD_CFDRFFDSTS_RFFDF_Msk

#define    CANFD_CFDRFFDSTS_RFBRS_Pos                             (1U)
#define    CANFD_CFDRFFDSTS_RFBRS_Msk                             (0x1U << CANFD_CFDRFFDSTS_RFBRS_Pos)
#define    CANFD_CFDRFFDSTS_RFBRS                                 CANFD_CFDRFFDSTS_RFBRS_Msk

#define    CANFD_CFDRFFDSTS_RFESI_Pos                             (0U)
#define    CANFD_CFDRFFDSTS_RFESI_Msk                             (0x1U << CANFD_CFDRFFDSTS_RFESI_Pos)
#define    CANFD_CFDRFFDSTS_RFESI                                 CANFD_CFDRFFDSTS_RFESI_Msk

#define    CANFD_CFDRFDFp_RFDB_Pos                                (0U)
#define    CANFD_CFDRFDFp_RFDB_Msk                                (0xffffffffU << CANFD_CFDRFDFp_RFDB_Pos)
#define    CANFD_CFDRFDFp_RFDB                                    CANFD_CFDRFDFp_RFDB_Msk

#define    CANFD_CFDCFID_CFIDE_Pos                                (31U)
#define    CANFD_CFDCFID_CFIDE_Msk                                (0x1U << CANFD_CFDCFID_CFIDE_Pos)
#define    CANFD_CFDCFID_CFIDE                                    CANFD_CFDCFID_CFIDE_Msk

#define    CANFD_CFDCFID_CFRTR_Pos                                (30U)
#define    CANFD_CFDCFID_CFRTR_Msk                                (0x1U << CANFD_CFDCFID_CFRTR_Pos)
#define    CANFD_CFDCFID_CFRTR                                    CANFD_CFDCFID_CFRTR_Msk

#define    CANFD_CFDCFID_THLEN_Pos                                (29U)
#define    CANFD_CFDCFID_THLEN_Msk                                (0x1U << CANFD_CFDCFID_THLEN_Pos)
#define    CANFD_CFDCFID_THLEN                                    CANFD_CFDCFID_THLEN_Msk

#define    CANFD_CFDCFID_CFID_Pos                                 (0U)
#define    CANFD_CFDCFID_CFID_Msk                                 (0x1fffffffU << CANFD_CFDCFID_CFID_Pos)
#define    CANFD_CFDCFID_CFID                                     CANFD_CFDCFID_CFID_Msk

#define    CANFD_CFDCFPTR_CFDLC_Pos                               (28U)
#define    CANFD_CFDCFPTR_CFDLC_Msk                               (0xfU << CANFD_CFDCFPTR_CFDLC_Pos)
#define    CANFD_CFDCFPTR_CFDLC                                   CANFD_CFDCFPTR_CFDLC_Msk

#define    CANFD_CFDCFPTR_CFTS_Pos                                (0U)
#define    CANFD_CFDCFPTR_CFTS_Msk                                (0xffffU << CANFD_CFDCFPTR_CFTS_Pos)
#define    CANFD_CFDCFPTR_CFTS                                    CANFD_CFDCFPTR_CFTS_Msk

#define    CANFD_CFDCFFDCSTS_CFPTR_Pos                            (16U)
#define    CANFD_CFDCFFDCSTS_CFPTR_Msk                            (0xffffU << CANFD_CFDCFFDCSTS_CFPTR_Pos)
#define    CANFD_CFDCFFDCSTS_CFPTR                                CANFD_CFDCFFDCSTS_CFPTR_Msk

#define    CANFD_CFDCFFDCSTS_CFIFL_Pos                            (8U)
#define    CANFD_CFDCFFDCSTS_CFIFL_Msk                            (0x3U << CANFD_CFDCFFDCSTS_CFIFL_Pos)
#define    CANFD_CFDCFFDCSTS_CFIFL                                CANFD_CFDCFFDCSTS_CFIFL_Msk

#define    CANFD_CFDCFFDCSTS_CFFDF_Pos                            (2U)
#define    CANFD_CFDCFFDCSTS_CFFDF_Msk                            (0x1U << CANFD_CFDCFFDCSTS_CFFDF_Pos)
#define    CANFD_CFDCFFDCSTS_CFFDF                                CANFD_CFDCFFDCSTS_CFFDF_Msk

#define    CANFD_CFDCFFDCSTS_CFBRS_Pos                            (1U)
#define    CANFD_CFDCFFDCSTS_CFBRS_Msk                            (0x1U << CANFD_CFDCFFDCSTS_CFBRS_Pos)
#define    CANFD_CFDCFFDCSTS_CFBRS                                CANFD_CFDCFFDCSTS_CFBRS_Msk

#define    CANFD_CFDCFFDCSTS_CFESI_Pos                            (0U)
#define    CANFD_CFDCFFDCSTS_CFESI_Msk                            (0x1U << CANFD_CFDCFFDCSTS_CFESI_Pos)
#define    CANFD_CFDCFFDCSTS_CFESI                                CANFD_CFDCFFDCSTS_CFESI_Msk

#define    CANFD_CFDCFDFp_CFDB_Pos                                (0U)
#define    CANFD_CFDCFDFp_CFDB_Msk                                (0xffffffffU << CANFD_CFDCFDFp_CFDB_Pos)
#define    CANFD_CFDCFDFp_CFDB                                    CANFD_CFDCFDFp_CFDB_Msk

#define    CANFD_CFDTMID_TMIDE_Pos                                (31U)
#define    CANFD_CFDTMID_TMIDE_Msk                                (0x1U << CANFD_CFDTMID_TMIDE_Pos)
#define    CANFD_CFDTMID_TMIDE                                    CANFD_CFDTMID_TMIDE_Msk

#define    CANFD_CFDTMID_TMRTR_Pos                                (30U)
#define    CANFD_CFDTMID_TMRTR_Msk                                (0x1U << CANFD_CFDTMID_TMRTR_Pos)
#define    CANFD_CFDTMID_TMRTR                                    CANFD_CFDTMID_TMRTR_Msk

#define    CANFD_CFDTMID_THLEN_Pos                                (29U)
#define    CANFD_CFDTMID_THLEN_Msk                                (0x1U << CANFD_CFDTMID_THLEN_Pos)
#define    CANFD_CFDTMID_THLEN                                    CANFD_CFDTMID_THLEN_Msk

#define    CANFD_CFDTMID_TMID_Pos                                 (0U)
#define    CANFD_CFDTMID_TMID_Msk                                 (0x1fffffffU << CANFD_CFDTMID_TMID_Pos)
#define    CANFD_CFDTMID_TMID                                     CANFD_CFDTMID_TMID_Msk

#define    CANFD_CFDTMPTR_TMDLC_Pos                               (28U)
#define    CANFD_CFDTMPTR_TMDLC_Msk                               (0xfU << CANFD_CFDTMPTR_TMDLC_Pos)
#define    CANFD_CFDTMPTR_TMDLC                                   CANFD_CFDTMPTR_TMDLC_Msk

#define    CANFD_CFDTMFDCTR_TMPTR_Pos                             (16U)
#define    CANFD_CFDTMFDCTR_TMPTR_Msk                             (0xffffU << CANFD_CFDTMFDCTR_TMPTR_Pos)
#define    CANFD_CFDTMFDCTR_TMPTR                                 CANFD_CFDTMFDCTR_TMPTR_Msk

#define    CANFD_CFDTMFDCTR_TMIFL_Pos                             (8U)
#define    CANFD_CFDTMFDCTR_TMIFL_Msk                             (0x3U << CANFD_CFDTMFDCTR_TMIFL_Pos)
#define    CANFD_CFDTMFDCTR_TMIFL                                 CANFD_CFDTMFDCTR_TMIFL_Msk

#define    CANFD_CFDTMFDCTR_TMFDF_Pos                             (2U)
#define    CANFD_CFDTMFDCTR_TMFDF_Msk                             (0x1U << CANFD_CFDTMFDCTR_TMFDF_Pos)
#define    CANFD_CFDTMFDCTR_TMFDF                                 CANFD_CFDTMFDCTR_TMFDF_Msk

#define    CANFD_CFDTMFDCTR_TMBRS_Pos                             (1U)
#define    CANFD_CFDTMFDCTR_TMBRS_Msk                             (0x1U << CANFD_CFDTMFDCTR_TMBRS_Pos)
#define    CANFD_CFDTMFDCTR_TMBRS                                 CANFD_CFDTMFDCTR_TMBRS_Msk

#define    CANFD_CFDTMFDCTR_TMESI_Pos                             (0U)
#define    CANFD_CFDTMFDCTR_TMESI_Msk                             (0x1U << CANFD_CFDTMFDCTR_TMESI_Pos)
#define    CANFD_CFDTMFDCTR_TMESI                                 CANFD_CFDTMFDCTR_TMESI_Msk

#define    CANFD_CFDTMDFp_TMDB_Pos                                (0U)
#define    CANFD_CFDTMDFp_TMDB_Msk                                (0xffffffffU << CANFD_CFDTMDFp_TMDB_Pos)
#define    CANFD_CFDTMDFp_TMDB                                    CANFD_CFDTMDFp_TMDB_Msk



#define    FL_CANFD_AFL_FILTER0                                   0x0U
#define    FL_CANFD_AFL_FILTER1                                   0x1U
#define    FL_CANFD_AFL_FILTER2                                   0x2U
#define    FL_CANFD_AFL_FILTER3                                   0x3U
#define    FL_CANFD_AFL_FILTER4                                   0x4U
#define    FL_CANFD_AFL_FILTER5                                   0x5U
#define    FL_CANFD_AFL_FILTER6                                   0x6U
#define    FL_CANFD_AFL_FILTER7                                   0x7U
#define    FL_CANFD_AFL_FILTER8                                   0x8U
#define    FL_CANFD_AFL_FILTER9                                   0x9U
#define    FL_CANFD_AFL_FILTER10                                  0xAU
#define    FL_CANFD_AFL_FILTER11                                  0xBU
#define    FL_CANFD_AFL_FILTER12                                  0xCU
#define    FL_CANFD_AFL_FILTER13                                  0xDU
#define    FL_CANFD_AFL_FILTER14                                  0xEU
#define    FL_CANFD_AFL_FILTER15                                  0xFU
#define    FL_CANFD_AFL_FILTER_MAX                                0x10U
#define    FL_CANFD_RXFIFO0                                       0x0U
#define    FL_CANFD_RXFIFO1                                       0x1U
#define    FL_CANFD_RXFIFO_MAX                                    0x2U
#define    FL_CANFD_RXMB0                                         0x0U
#define    FL_CANFD_RXMB1                                         0x1U
#define    FL_CANFD_RXMB2                                         0x2U
#define    FL_CANFD_RXMB3                                         0x3U
#define    FL_CANFD_RXMB4                                         0x4U
#define    FL_CANFD_RXMB5                                         0x5U
#define    FL_CANFD_RXMB6                                         0x6U
#define    FL_CANFD_RXMB7                                         0x7U
#define    FL_CANFD_RXMB8                                         0x8U
#define    FL_CANFD_RXMB9                                         0x9U
#define    FL_CANFD_RXMB10                                        0xAU
#define    FL_CANFD_RXMB11                                        0xBU
#define    FL_CANFD_RXMB12                                        0xCU
#define    FL_CANFD_RXMB13                                        0xDU
#define    FL_CANFD_RXMB14                                        0xEU
#define    FL_CANFD_RXMB15                                        0xFU
#define    FL_CANFD_RXMB16                                        0x10U
#define    FL_CANFD_RXMB17                                        0x11U
#define    FL_CANFD_RXMB18                                        0x12U
#define    FL_CANFD_RXMB19                                        0x13U
#define    FL_CANFD_RXMB20                                        0x14U
#define    FL_CANFD_RXMB21                                        0x15U
#define    FL_CANFD_RXMB22                                        0x16U
#define    FL_CANFD_RXMB23                                        0x17U
#define    FL_CANFD_RXMB24                                        0x18U
#define    FL_CANFD_RXMB25                                        0x19U
#define    FL_CANFD_RXMB26                                        0x1AU
#define    FL_CANFD_RXMB27                                        0x1BU
#define    FL_CANFD_RXMB28                                        0x1CU
#define    FL_CANFD_RXMB29                                        0x1DU
#define    FL_CANFD_RXMB30                                        0x1EU
#define    FL_CANFD_RXMB31                                        0x1FU
#define    FL_CANFD_RXMB_MAX                                      0x20U
#define    FL_CANFD_TXMB0                                         0x0U
#define    FL_CANFD_TXMB1                                         0x1U
#define    FL_CANFD_TXMB2                                         0x2U
#define    FL_CANFD_TXMB3                                         0x3U
#define    FL_CANFD_TXMB_MAX                                      0x4U
#define    FL_CANFD_PFL_FILTER0                                   0x0U
#define    FL_CANFD_PFL_FILTER1                                   0x1U
#define    FL_CANFD_PFL_FILTER_MAX                                0x2U
#define    FL_CANFD_DATA0                                         0x0U
#define    FL_CANFD_DATA1                                         0x1U
#define    FL_CANFD_DATA2                                         0x2U
#define    FL_CANFD_DATA3                                         0x3U
#define    FL_CANFD_DATA4                                         0x4U
#define    FL_CANFD_DATA5                                         0x5U
#define    FL_CANFD_DATA6                                         0x6U
#define    FL_CANFD_DATA7                                         0x7U
#define    FL_CANFD_DATA8                                         0x8U
#define    FL_CANFD_DATA9                                         0x9U
#define    FL_CANFD_DATA10                                        0xAU
#define    FL_CANFD_DATA11                                        0xBU
#define    FL_CANFD_DATA12                                        0xCU
#define    FL_CANFD_DATA13                                        0xDU
#define    FL_CANFD_DATA14                                        0xEU
#define    FL_CANFD_DATA15                                        0xFU
#define    FL_CANFD_DATA_MAX                                      0x10U



#define    FL_CANFD_CHANNEL_TEST_MODE_BASIC                       (0x0U << CANFD_CFDC0CTR_CTMS_Pos)
#define    FL_CANFD_CHANNEL_TEST_MODE_LISTEN                      (0x1U << CANFD_CFDC0CTR_CTMS_Pos)
#define    FL_CANFD_CHANNEL_TEST_MODE_SELFTEST0                   (0x2U << CANFD_CFDC0CTR_CTMS_Pos)
#define    FL_CANFD_CHANNEL_TEST_MODE_SELFTEST1                   (0x3U << CANFD_CFDC0CTR_CTMS_Pos)


#define    FL_CANFD_CHANNEL_ERROR_DISPLAY_TYPE_FIRST_GROUP        (0x0U << CANFD_CFDC0CTR_ERRD_Pos)
#define    FL_CANFD_CHANNEL_ERROR_DISPLAY_TYPE_CUMULATIVE         (0x1U << CANFD_CFDC0CTR_ERRD_Pos)


#define    FL_CANFD_CHANNEL_BUSOFF_MODE_NORMAL                    (0x0U << CANFD_CFDC0CTR_BOM_Pos)
#define    FL_CANFD_CHANNEL_BUSOFF_MODE_HALT_AT_BUSOFF_SATRT      (0x1U << CANFD_CFDC0CTR_BOM_Pos)
#define    FL_CANFD_CHANNEL_BUSOFF_MODE_HALT_AT_BUSOFF_END        (0x2U << CANFD_CFDC0CTR_BOM_Pos)
#define    FL_CANFD_CHANNEL_BUSOFF_MODE_HALT_BY_SW                (0x3U << CANFD_CFDC0CTR_BOM_Pos)


#define    FL_CANFD_CHANNEL_MODE_OPERATION                        (0x0U << CANFD_CFDC0CTR_CHMDC_Pos)
#define    FL_CANFD_CHANNEL_MODE_RESET                            (0x1U << CANFD_CFDC0CTR_CHMDC_Pos)
#define    FL_CANFD_CHANNEL_MODE_HALT                             (0x2U << CANFD_CFDC0CTR_CHMDC_Pos)
#define    FL_CANFD_CHANNEL_MODE_KEEP_CURRENT                     (0x3U << CANFD_CFDC0CTR_CHMDC_Pos)


#define    FL_CANFD_RETURN_PNF_MODE_AF                            (0x0U << CANFD_CFDC0FDCFG_RPNMD_Pos)
#define    FL_CANFD_RETURN_PNF_MODE_PNFID_AF                      (0x1U << CANFD_CFDC0FDCFG_RPNMD_Pos)
#define    FL_CANFD_RETURN_PNF_MODE_PNF_AF                        (0x2U << CANFD_CFDC0FDCFG_RPNMD_Pos)
#define    FL_CANFD_RETURN_PNF_MODE_PNF                           (0x3U << CANFD_CFDC0FDCFG_RPNMD_Pos)


#define    FL_CANFD_ESI_CONFIGURATION_NODE_STATE                  (0x0U << CANFD_CFDC0FDCFG_ESIC_Pos)
#define    FL_CANFD_ESI_CONFIGURATION_SOFTWARE                    (0x1U << CANFD_CFDC0FDCFG_ESIC_Pos)


#define    FL_CANFD_TDCO_CONFIGURATION_MEASURED_WITH_OFFSET       (0x0U << CANFD_CFDC0FDCFG_TDCOC_Pos)
#define    FL_CANFD_TDCO_CONFIGURATION_OFFSET                     (0x1U << CANFD_CFDC0FDCFG_TDCOC_Pos)


#define    FL_CANFD_EOC_CONFIGURATION_ALL                         (0x0U << CANFD_CFDC0FDCFG_EOCCFG_Pos)
#define    FL_CANFD_EOC_CONFIGURATION_TRANSMITTER                 (0x1U << CANFD_CFDC0FDCFG_EOCCFG_Pos)
#define    FL_CANFD_EOC_CONFIGURATION_RECEIVER                    (0x2U << CANFD_CFDC0FDCFG_EOCCFG_Pos)
#define    FL_CANFD_EOC_CONFIGURATION_ALL_FD_DATAPHASE            (0x4U << CANFD_CFDC0FDCFG_EOCCFG_Pos)
#define    FL_CANFD_EOC_CONFIGURATION_TRANSMITTER_FD_DATAPHASE    (0x5U << CANFD_CFDC0FDCFG_EOCCFG_Pos)
#define    FL_CANFD_EOC_CONFIGURATION_RECEIVER_FD_DATAPHASE       (0x6U << CANFD_CFDC0FDCFG_EOCCFG_Pos)


#define    FL_CANFD_PNF_MODE_AF                                   (0x0U << CANFD_CFDC0FDCTR_PNMDC_Pos)
#define    FL_CANFD_PNF_MODE_PNFID_AF                             (0x1U << CANFD_CFDC0FDCTR_PNMDC_Pos)
#define    FL_CANFD_PNF_MODE_PNF_AF                               (0x2U << CANFD_CFDC0FDCTR_PNMDC_Pos)
#define    FL_CANFD_PNF_MODE_PNF                                  (0x3U << CANFD_CFDC0FDCTR_PNMDC_Pos)


#define    FL_CANFD_PNF_STATE_AF                                  (0x0U << CANFD_CFDC0FDSTS_PNSTS_Pos)
#define    FL_CANFD_PNF_STATE_PNFID_AF                            (0x1U << CANFD_CFDC0FDSTS_PNSTS_Pos)
#define    FL_CANFD_PNF_STATE_PNF_AF                              (0x2U << CANFD_CFDC0FDSTS_PNSTS_Pos)
#define    FL_CANFD_PNF_STATE_PNF                                 (0x3U << CANFD_CFDC0FDSTS_PNSTS_Pos)

#define    FL_CANFD_TSSS_CLOCK_PERIPHERAL                         (0x0U << CANFD_CFDGCFG_TSSS_Pos)
#define    FL_CANFD_TSSS_CLOCK_BIT_TIME                           (0x1U << CANFD_CFDGCFG_TSSS_Pos)


#define    FL_CANFD_TSP_PSC_1                                     (0x0U << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_2                                     (0x1U << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_4                                     (0x2U << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_8                                     (0x3U << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_16                                    (0x4U << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_32                                    (0x5U << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_64                                    (0x6U << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_128                                   (0x7U << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_256                                   (0x8U << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_512                                   (0x9U << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_1024                                  (0xaU << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_2048                                  (0xbU << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_4096                                  (0xcU << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_8192                                  (0xdU << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_16384                                 (0xeU << CANFD_CFDGCFG_TSP_Pos)
#define    FL_CANFD_TSP_PSC_32768                                 (0xfU << CANFD_CFDGCFG_TSP_Pos)


#define    FL_CANFD_CMPOC_CONFIGURATION_REJECTED                  (0x0U << CANFD_CFDGCFG_CMPOC_Pos)
#define    FL_CANFD_CMPOC_CONFIGURATION_CUTOFF                    (0x1U << CANFD_CFDGCFG_CMPOC_Pos)


#define    FL_CANFD_DCS_CLOCK_INTERNAL                            (0x0U << CANFD_CFDGCFG_DCS_Pos)
#define    FL_CANFD_DCS_CLOCK_EXTRENAL                            (0x1U << CANFD_CFDGCFG_DCS_Pos)


#define    FL_CANFD_TX_PRIORITY_ID                                (0x0U << CANFD_CFDGCFG_TPRI_Pos)
#define    FL_CANFD_TX_PRIORITY_BUFFER                            (0x1U << CANFD_CFDGCFG_TPRI_Pos)


#define    FL_CANFD_TS_RST_NO_RESET                               (0x0U << CANFD_CFDGCTR_TSRST_Pos)
#define    FL_CANFD_TS_RST_RESET                                  (0x1U << CANFD_CFDGCTR_TSRST_Pos)


#define    FL_CANFD_GLOBAL_MODE_OPERATION                         (0x0U << CANFD_CFDGCTR_GMDC_Pos)
#define    FL_CANFD_GLOBAL_MODE_RESET                             (0x1U << CANFD_CFDGCTR_GMDC_Pos)
#define    FL_CANFD_GLOBAL_MODE_HALT                              (0x2U << CANFD_CFDGCTR_GMDC_Pos)
#define    FL_CANFD_GLOBAL_MODE_KEEP_CURRENT                      (0x3U << CANFD_CFDGCTR_GMDC_Pos)


#define    FL_CANFD_GAFL_PAGE_NUMBER_FIRST                        (0x0U << CANFD_CFDGAFLECTR_AFLPN_Pos)
#define    FL_CANFD_GAFL_PAGE_NUMBER_SECOND                       (0x1U << CANFD_CFDGAFLECTR_AFLPN_Pos)


#define    FL_CANFD_GAFL_IDE_STANDARD                             (0x0U << CANFD_CFDGAFLIDr_GAFLIDE_Pos)
#define    FL_CANFD_GAFL_IDE_EXTENDED                             (0x1U << CANFD_CFDGAFLIDr_GAFLIDE_Pos)


#define    FL_CANFD_GAFL_RTR_DATA_FRAME                           (0x0U << CANFD_CFDGAFLIDr_GAFLRTR_Pos)
#define    FL_CANFD_GAFL_RTR_REMOTE_FRAME                         (0x1U << CANFD_CFDGAFLIDr_GAFLRTR_Pos)


#define    FL_CANFD_GAFL_LB_RX                                    (0x0U << CANFD_CFDGAFLIDr_GAFLLB_Pos)
#define    FL_CANFD_GAFL_LB_TX                                    (0x1U << CANFD_CFDGAFLIDr_GAFLLB_Pos)


#define    FL_CANFD_GAFL_IDEM_NOT_CONSIDERED                      (0x0U << CANFD_CFDGAFLMr_GAFLIDEM_Pos)
#define    FL_CANFD_GAFL_IDEM_CONSIDERED                          (0x1U << CANFD_CFDGAFLMr_GAFLIDEM_Pos)


#define    FL_CANFD_GAFL_RTRM_NOT_CONSIDERED                      (0x0U << CANFD_CFDGAFLMr_GAFLRTRM_Pos)
#define    FL_CANFD_GAFL_RTRM_CONSIDERED                          (0x1U << CANFD_CFDGAFLMr_GAFLRTRM_Pos)


#define    FL_CANFD_GAFL_INFO_LABEL1_0                            (0x0U << CANFD_CFDGAFLMr_GAFLIFL1_Pos)
#define    FL_CANFD_GAFL_INFO_LABEL1_1                            (0x1U << CANFD_CFDGAFLMr_GAFLIFL1_Pos)


#define    FL_CANFD_GAFL_SINGLE_RXMB_INVALID                      (0x0U << CANFD_CFDGAFLP0r_GAFLRMV_Pos)
#define    FL_CANFD_GAFL_SINGLE_RXMB_VALID                        (0x1U << CANFD_CFDGAFLP0r_GAFLRMV_Pos)


#define    FL_CANFD_GAFL_INFO_LABEL0_0                            (0x0U << CANFD_CFDGAFLP0r_GAFLIFL0_Pos)
#define    FL_CANFD_GAFL_INFO_LABEL0_1                            (0x1U << CANFD_CFDGAFLP0r_GAFLIFL0_Pos)


#define    FL_CANFD_RMPLS_SIZE_8                                  (0x0U << CANFD_CFDRMNB_RMPLS_Pos)
#define    FL_CANFD_RMPLS_SIZE_12                                 (0x1U << CANFD_CFDRMNB_RMPLS_Pos)
#define    FL_CANFD_RMPLS_SIZE_16                                 (0x2U << CANFD_CFDRMNB_RMPLS_Pos)
#define    FL_CANFD_RMPLS_SIZE_20                                 (0x3U << CANFD_CFDRMNB_RMPLS_Pos)
#define    FL_CANFD_RMPLS_SIZE_24                                 (0x4U << CANFD_CFDRMNB_RMPLS_Pos)
#define    FL_CANFD_RMPLS_SIZE_32                                 (0x5U << CANFD_CFDRMNB_RMPLS_Pos)
#define    FL_CANFD_RMPLS_SIZE_48                                 (0x6U << CANFD_CFDRMNB_RMPLS_Pos)
#define    FL_CANFD_RMPLS_SIZE_64                                 (0x7U << CANFD_CFDRMNB_RMPLS_Pos)


#define    FL_CANFD_RFIGCV_1P8_FULL                               (0x0U << CANFD_CFDRFCCa_RFIGCV_Pos)
#define    FL_CANFD_RFIGCV_1P4_FULL                               (0x1U << CANFD_CFDRFCCa_RFIGCV_Pos)
#define    FL_CANFD_RFIGCV_3P8_FULL                               (0x2U << CANFD_CFDRFCCa_RFIGCV_Pos)
#define    FL_CANFD_RFIGCV_1P2_FULL                               (0x3U << CANFD_CFDRFCCa_RFIGCV_Pos)
#define    FL_CANFD_RFIGCV_5P8_FULL                               (0x4U << CANFD_CFDRFCCa_RFIGCV_Pos)
#define    FL_CANFD_RFIGCV_3P4_FULL                               (0x5U << CANFD_CFDRFCCa_RFIGCV_Pos)
#define    FL_CANFD_RFIGCV_7P8_FULL                               (0x6U << CANFD_CFDRFCCa_RFIGCV_Pos)
#define    FL_CANFD_RFIGCV_FULL                                   (0x7U << CANFD_CFDRFCCa_RFIGCV_Pos)


#define    FL_CANFD_RFIM_REACH_RFIGCV                             (0x0U << CANFD_CFDRFCCa_RFIM_Pos)
#define    FL_CANFD_RFIM_EVERY_MESSAGE                            (0x1U << CANFD_CFDRFCCa_RFIM_Pos)


#define    FL_CANFD_RFDC_DEPTH_0                                  (0x0U << CANFD_CFDRFCCa_RFDC_Pos)
#define    FL_CANFD_RFDC_DEPTH_4                                  (0x1U << CANFD_CFDRFCCa_RFDC_Pos)
#define    FL_CANFD_RFDC_DEPTH_8                                  (0x2U << CANFD_CFDRFCCa_RFDC_Pos)
#define    FL_CANFD_RFDC_DEPTH_16                                 (0x3U << CANFD_CFDRFCCa_RFDC_Pos)
#define    FL_CANFD_RFDC_DEPTH_32                                 (0x4U << CANFD_CFDRFCCa_RFDC_Pos)
#define    FL_CANFD_RFDC_DEPTH_48                                 (0x5U << CANFD_CFDRFCCa_RFDC_Pos)


#define    FL_CANFD_RFPLS_SIZE_8                                  (0x0U << CANFD_CFDRFCCa_RFPLS_Pos)
#define    FL_CANFD_RFPLS_SIZE_12                                 (0x1U << CANFD_CFDRFCCa_RFPLS_Pos)
#define    FL_CANFD_RFPLS_SIZE_16                                 (0x2U << CANFD_CFDRFCCa_RFPLS_Pos)
#define    FL_CANFD_RFPLS_SIZE_20                                 (0x3U << CANFD_CFDRFCCa_RFPLS_Pos)
#define    FL_CANFD_RFPLS_SIZE_24                                 (0x4U << CANFD_CFDRFCCa_RFPLS_Pos)
#define    FL_CANFD_RFPLS_SIZE_32                                 (0x5U << CANFD_CFDRFCCa_RFPLS_Pos)
#define    FL_CANFD_RFPLS_SIZE_48                                 (0x6U << CANFD_CFDRFCCa_RFPLS_Pos)
#define    FL_CANFD_RFPLS_SIZE_64                                 (0x7U << CANFD_CFDRFCCa_RFPLS_Pos)


#define    FL_CANFD_CFDC_DEPTH_0                                  (0x0U << CANFD_CFDCFCC_CFDC_Pos)
#define    FL_CANFD_CFDC_DEPTH_4                                  (0x1U << CANFD_CFDCFCC_CFDC_Pos)
#define    FL_CANFD_CFDC_DEPTH_8                                  (0x2U << CANFD_CFDCFCC_CFDC_Pos)
#define    FL_CANFD_CFDC_DEPTH_16                                 (0x3U << CANFD_CFDCFCC_CFDC_Pos)
#define    FL_CANFD_CFDC_DEPTH_32                                 (0x4U << CANFD_CFDCFCC_CFDC_Pos)
#define    FL_CANFD_CFDC_DEPTH_48                                 (0x5U << CANFD_CFDCFCC_CFDC_Pos)


#define    FL_CANFD_CFTML_TXMB0                                   (0x0U << CANFD_CFDCFCC_CFTML_Pos)
#define    FL_CANFD_CFTML_TXMB1                                   (0x1U << CANFD_CFDCFCC_CFTML_Pos)
#define    FL_CANFD_CFTML_TXMB2                                   (0x2U << CANFD_CFDCFCC_CFTML_Pos)
#define    FL_CANFD_CFTML_TXMB3                                   (0x3U << CANFD_CFDCFCC_CFTML_Pos)


#define    FL_CANFD_CFIGCV_1P8_FULL                               (0x0U << CANFD_CFDCFCC_CFIGCV_Pos)
#define    FL_CANFD_CFIGCV_1P4_FULL                               (0x1U << CANFD_CFDCFCC_CFIGCV_Pos)
#define    FL_CANFD_CFIGCV_3P8_FULL                               (0x2U << CANFD_CFDCFCC_CFIGCV_Pos)
#define    FL_CANFD_CFIGCV_1P2_FULL                               (0x3U << CANFD_CFDCFCC_CFIGCV_Pos)
#define    FL_CANFD_CFIGCV_5P8_FULL                               (0x4U << CANFD_CFDCFCC_CFIGCV_Pos)
#define    FL_CANFD_CFIGCV_3P4_FULL                               (0x5U << CANFD_CFDCFCC_CFIGCV_Pos)
#define    FL_CANFD_CFIGCV_7P8_FULL                               (0x6U << CANFD_CFDCFCC_CFIGCV_Pos)
#define    FL_CANFD_CFIGCV_FULL                                   (0x7U << CANFD_CFDCFCC_CFIGCV_Pos)


#define    FL_CANFD_CFIM_REACH_RFIGCV                             (0x0U << CANFD_CFDCFCC_CFIM_Pos)
#define    FL_CANFD_CFIM_EVERY_MESSAGE                            (0x1U << CANFD_CFDCFCC_CFIM_Pos)


#define    FL_CANFD_CFITR_REF_CLOCK_MUL_1                         (0x0U << CANFD_CFDCFCC_CFITR_Pos)
#define    FL_CANFD_CFITR_REF_CLOCK_MUL_10                        (0x1U << CANFD_CFDCFCC_CFITR_Pos)


#define    FL_CANFD_CFITSS_REF_CLOCK                              (0x0U << CANFD_CFDCFCC_CFITSS_Pos)
#define    FL_CANFD_CFITSS_BIT_CLOCK                              (0x1U << CANFD_CFDCFCC_CFITSS_Pos)


#define    FL_CANFD_CFM_RX_FIFO                                   (0x0U << CANFD_CFDCFCC_CFM_Pos)
#define    FL_CANFD_CFM_TX_FIFO                                   (0x1U << CANFD_CFDCFCC_CFM_Pos)


#define    FL_CANFD_CFPLS_SIZE_8                                  (0x0U << CANFD_CFDCFCC_CFPLS_Pos)
#define    FL_CANFD_CFPLS_SIZE_12                                 (0x1U << CANFD_CFDCFCC_CFPLS_Pos)
#define    FL_CANFD_CFPLS_SIZE_16                                 (0x2U << CANFD_CFDCFCC_CFPLS_Pos)
#define    FL_CANFD_CFPLS_SIZE_20                                 (0x3U << CANFD_CFDCFCC_CFPLS_Pos)
#define    FL_CANFD_CFPLS_SIZE_24                                 (0x4U << CANFD_CFDCFCC_CFPLS_Pos)
#define    FL_CANFD_CFPLS_SIZE_32                                 (0x5U << CANFD_CFDCFCC_CFPLS_Pos)
#define    FL_CANFD_CFPLS_SIZE_48                                 (0x6U << CANFD_CFDCFCC_CFPLS_Pos)
#define    FL_CANFD_CFPLS_SIZE_64                                 (0x7U << CANFD_CFDCFCC_CFPLS_Pos)


#define    FL_CANFD_TXMODE_CONTINUOUS                             (0x0U << CANFD_CFDTMCi_TMOM_Pos)
#define    FL_CANFD_TXMODE_ONE_SHOT                               (0x1U << CANFD_CFDTMCi_TMOM_Pos)


#define    FL_CANFD_TMTRF_NO_RESULT                               (0x0U << CANFD_CFDTMSTSj_TMTRF_Pos)
#define    FL_CANFD_TMTRF_TX_ABORTED                              (0x1U << CANFD_CFDTMSTSj_TMTRF_Pos)
#define    FL_CANFD_TMTRF_TX_SUCCESSFUL_WITHOUT_ABORT_REQUESTED   (0x2U << CANFD_CFDTMSTSj_TMTRF_Pos)
#define    FL_CANFD_TMTRF_TX_SUCCESSFUL_WITH_ABORT_REQUESTED      (0x3U << CANFD_CFDTMSTSj_TMTRF_Pos)

#define    FL_CANFD_TXQDC_DEPTH_0                                 (0x0U << CANFD_CFDTXQCC_TXQDC_Pos)
#define    FL_CANFD_TXQDC_DEPTH_3                                 (0x2U << CANFD_CFDTXQCC_TXQDC_Pos)
#define    FL_CANFD_TXQDC_DEPTH_4                                 (0x3U << CANFD_CFDTXQCC_TXQDC_Pos)


#define    FL_CANFD_TXQIM_LAST_MESSAGE_TRANSMITTED                (0x0U << CANFD_CFDTXQCC_TXQIM_Pos)
#define    FL_CANFD_TXQIM_EVERY_TRANSMISSION                      (0x1U << CANFD_CFDTXQCC_TXQIM_Pos)


#define    FL_CANFD_THLIM_REACH_3P4_DEPTH                         (0x0U << CANFD_CFDTHLCC_THLIM_Pos)
#define    FL_CANFD_THLIM_EVERY_TRANSMISSION                      (0x1U << CANFD_CFDTHLCC_THLIM_Pos)


#define    FL_CANFD_BT_TX_MB                                      (0x1U << CANFD_CFDTHLACC0_BT_Pos)
#define    FL_CANFD_BT_TX_FIFO                                    (0x2U << CANFD_CFDTHLACC0_BT_Pos)
#define    FL_CANFD_BT_TX_QUEUE                                   (0x4U << CANFD_CFDTHLACC0_BT_Pos)

#define    FL_CANFD_SRST_NO_RESET                                 (0x0U << CANFD_CFDGRSTC_SRST_Pos)
#define    FL_CANFD_SRST_RESET                                    (0x1U << CANFD_CFDGRSTC_SRST_Pos)


#define    FL_CANFD_TSCCFG_SOF                                    (0x0U << CANFD_CFDGFDCFG_TSCCFG_Pos)
#define    FL_CANFD_TSCCFG_FRAME_VALID_INDICATION                 (0x1U << CANFD_CFDGFDCFG_TSCCFG_Pos)
#define    FL_CANFD_TSCCFG_RES                                    (0x2U << CANFD_CFDGFDCFG_TSCCFG_Pos)


#define    FL_CANFD_GPFL_IDE_STANDARD                             (0x0U << CANFD_CFDGPFLIDs_GPFLIDE_Pos)
#define    FL_CANFD_GPFL_IDE_EXTENDED                             (0x1U << CANFD_CFDGPFLIDs_GPFLIDE_Pos)


#define    FL_CANFD_GPFL_RTR_DATA_FRAME                           (0x0U << CANFD_CFDGPFLIDs_GPFLRTR_Pos)
#define    FL_CANFD_GPFL_RTR_REMOTE_FRAME                         (0x1U << CANFD_CFDGPFLIDs_GPFLRTR_Pos)


#define    FL_CANFD_GPFL_LB_RX                                    (0x0U << CANFD_CFDGPFLIDs_GPFLLB_Pos)
#define    FL_CANFD_GPFL_LB_TX                                    (0x1U << CANFD_CFDGPFLIDs_GPFLLB_Pos)


#define    FL_CANFD_GPFL_IDEM_NOT_CONSIDERED                      (0x0U << CANFD_CFDGPFLMs_GPFLIDEM_Pos)
#define    FL_CANFD_GPFL_IDEM_CONSIDERED                          (0x1U << CANFD_CFDGPFLMs_GPFLIDEM_Pos)


#define    FL_CANFD_GPFL_RTRM_NOT_CONSIDERED                      (0x0U << CANFD_CFDGPFLMs_GPFLRTRM_Pos)
#define    FL_CANFD_GPFL_RTRM_CONSIDERED                          (0x1U << CANFD_CFDGPFLMs_GPFLRTRM_Pos)


#define    FL_CANFD_GPFL_INFO_LABEL1_0                            (0x0U << CANFD_CFDGPFLMs_GPFLIFL1_Pos)
#define    FL_CANFD_GPFL_INFO_LABEL1_1                            (0x1U << CANFD_CFDGPFLMs_GPFLIFL1_Pos)


#define    FL_CANFD_GPFL_SINGLE_RXMB_INVALID                      (0x0U << CANFD_CFDGPFLP0s_GPFLRMV_Pos)
#define    FL_CANFD_GPFL_SINGLE_RXMB_VALID                        (0x1U << CANFD_CFDGPFLP0s_GPFLRMV_Pos)


#define    FL_CANFD_GPFL_INFO_LABEL0_0                            (0x0U << CANFD_CFDGPFLP0s_GPFLIFL0_Pos)
#define    FL_CANFD_GPFL_INFO_LABEL0_1                            (0x1U << CANFD_CFDGPFLP0s_GPFLIFL0_Pos)


#define    FL_CANFD_GPFLANDOR_AND                                 (0x0U << CANFD_CFDGPFLPTs_GPFLANDOR_Pos)
#define    FL_CANFD_GPFLANDOR_OR                                  (0x1U << CANFD_CFDGPFLPTs_GPFLANDOR_Pos)


#define    FL_CANFD_GPFLRANG0_MATCH                               (0x0U << CANFD_CFDGPFLPTs_GPFLRANG0_Pos)
#define    FL_CANFD_GPFLRANG0_RANGE                               (0x1U << CANFD_CFDGPFLPTs_GPFLRANG0_Pos)


#define    FL_CANFD_GPFLOUT0_WITHIN                               (0x0U << CANFD_CFDGPFLPTs_GPFLOUT0_Pos)
#define    FL_CANFD_GPFLOUT0_OUTSIDE                              (0x1U << CANFD_CFDGPFLPTs_GPFLOUT0_Pos)


#define    FL_CANFD_GPFLRANG1_MATCH                               (0x0U << CANFD_CFDGPFLPTs_GPFLRANG1_Pos)
#define    FL_CANFD_GPFLRANG1_RANGE                               (0x1U << CANFD_CFDGPFLPTs_GPFLRANG1_Pos)


#define    FL_CANFD_GPFLOUT1_WITHIN                               (0x0U << CANFD_CFDGPFLPTs_GPFLOUT1_Pos)
#define    FL_CANFD_GPFLOUT1_OUTSIDE                              (0x1U << CANFD_CFDGPFLPTs_GPFLOUT1_Pos)


#define    FL_CANFD_RM_IDE_STANDARD                               (0x0U << CANFD_CFDRMID_RMIDE_Pos)
#define    FL_CANFD_RM_IDE_EXTENDED                               (0x1U << CANFD_CFDRMID_RMIDE_Pos)

#define    FL_CANFD_RM_RTR_DATA_FRAME                             (0x0U << CANFD_CFDRMID_RMRTR_Pos)
#define    FL_CANFD_RM_RTR_REMOTE_FRAME                           (0x1U << CANFD_CFDRMID_RMRTR_Pos)

#define    FL_CANFD_RF_IDE_STANDARD                               (0x0U << CANFD_CFDRFID_RFIDE_Pos)
#define    FL_CANFD_RF_IDE_EXTENDED                               (0x1U << CANFD_CFDRFID_RFIDE_Pos)

#define    FL_CANFD_RF_RTR_DATA_FRAME                             (0x0U << CANFD_CFDRFID_RFRTR_Pos)
#define    FL_CANFD_RF_RTR_REMOTE_FRAME                           (0x1U << CANFD_CFDRFID_RFRTR_Pos)

#define    FL_CANFD_CF_IDE_STANDARD                               (0x0U << CANFD_CFDCFID_CFIDE_Pos)
#define    FL_CANFD_CF_IDE_EXTENDED                               (0x1U << CANFD_CFDCFID_CFIDE_Pos)


#define    FL_CANFD_CF_RTR_DATA_FRAME                             (0x0U << CANFD_CFDCFID_CFRTR_Pos)
#define    FL_CANFD_CF_RTR_REMOTE_FRAME                           (0x1U << CANFD_CFDCFID_CFRTR_Pos)


#define    FL_CANFD_CF_FDF_DISABLE                                (0x0U << CANFD_CFDCFFDCSTS_CFFDF_Pos)
#define    FL_CANFD_CF_FDF_ENABLE                                 (0x1U << CANFD_CFDCFFDCSTS_CFFDF_Pos)


#define    FL_CANFD_CF_BRS_DISABLE                                (0x0U << CANFD_CFDCFFDCSTS_CFBRS_Pos)
#define    FL_CANFD_CF_BRS_ENABLE                                 (0x1U << CANFD_CFDCFFDCSTS_CFBRS_Pos)


#define    FL_CANFD_CF_ESI_DISABLE                                (0x0U << CANFD_CFDCFFDCSTS_CFESI_Pos)
#define    FL_CANFD_CF_ESI_ENABLE                                 (0x1U << CANFD_CFDCFFDCSTS_CFESI_Pos)


#define    FL_CANFD_TM_IDE_STANDARD                               (0x0U << CANFD_CFDTMID_TMIDE_Pos)
#define    FL_CANFD_TM_IDE_EXTENDED                               (0x1U << CANFD_CFDTMID_TMIDE_Pos)


#define    FL_CANFD_TM_RTR_DATA_FRAME                             (0x0U << CANFD_CFDTMID_TMRTR_Pos)
#define    FL_CANFD_TM_RTR_REMOTE_FRAME                           (0x1U << CANFD_CFDTMID_TMRTR_Pos)


#define    FL_CANFD_TM_FDF_DISABLE                                (0x0U << CANFD_CFDTMFDCTR_TMFDF_Pos)
#define    FL_CANFD_TM_FDF_ENABLE                                 (0x1U << CANFD_CFDTMFDCTR_TMFDF_Pos)


#define    FL_CANFD_TM_BRS_DISABLE                                (0x0U << CANFD_CFDTMFDCTR_TMBRS_Pos)
#define    FL_CANFD_TM_BRS_ENABLE                                 (0x1U << CANFD_CFDTMFDCTR_TMBRS_Pos)


#define    FL_CANFD_TM_ESI_DISABLE                                (0x0U << CANFD_CFDTMFDCTR_TMESI_Pos)
#define    FL_CANFD_TM_ESI_ENABLE                                 (0x1U << CANFD_CFDTMFDCTR_TMESI_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup CANFD_FL_Exported_Functions CANFD Exported Functions
  * @{
  */

/**
  * @brief    Set Channel 0 Nominal Bitrate Timing segment 2
  * @rmtoll   CFDC0NCFG    NTSEG2    FL_CANFD_CH0_WriteNominalBitrateTimeSegment2Length
  * @param    CANFDx CANFD instance
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_WriteNominalBitrateTimeSegment2Length(CANFD_COMMON_Type* CANFDx, uint32_t length)
{
    MODIFY_REG(CANFDx->CFDC0NCFG, (0x7fU << 25U), (length << 25U));
}

/**
  * @brief    Get Channel 0 Nominal Bitrate Timing segment 2
  * @rmtoll   CFDC0NCFG    NTSEG2    FL_CANFD_CH0_ReadNominalBitrateTimeSegment2Length
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_ReadNominalBitrateTimeSegment2Length(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0NCFG, (0x7fU << 25U)) >> 25U);
}

/**
  * @brief    Set Channel 0 Nominal Bitrate Timing segment 1
  * @rmtoll   CFDC0NCFG    NTSEG1    FL_CANFD_CH0_WriteNominalBitrateTimeSegment1Length
  * @param    CANFDx CANFD instance
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_WriteNominalBitrateTimeSegment1Length(CANFD_COMMON_Type* CANFDx, uint32_t length)
{
    MODIFY_REG(CANFDx->CFDC0NCFG, (0xffU << 17U), (length << 17U));
}

/**
  * @brief    Get Channel 0 Nominal Bitrate Timing segment 1
  * @rmtoll   CFDC0NCFG    NTSEG1    FL_CANFD_CH0_ReadNominalBitrateTimeSegment1Length
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_ReadNominalBitrateTimeSegment1Length(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0NCFG, (0xffU << 17U)) >> 17U);
}

/**
  * @brief    Set Channel 0 Nominal Bitrate Resynchronization jump width
  * @rmtoll   CFDC0NCFG    NSJW    FL_CANFD_CH0_WriteNominalBitrateSyncJumpWidth
  * @param    CANFDx CANFD instance
  * @param    width 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_WriteNominalBitrateSyncJumpWidth(CANFD_COMMON_Type* CANFDx, uint32_t width)
{
    MODIFY_REG(CANFDx->CFDC0NCFG, (0x7fU << 10U), (width << 10U));
}

/**
  * @brief    Get Channel 0 Nominal Bitrate Resynchronization jump width
  * @rmtoll   CFDC0NCFG    NSJW    FL_CANFD_CH0_ReadNominalBitrateSyncJumpWidth
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_ReadNominalBitrateSyncJumpWidth(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0NCFG, (0x7fU << 10U)) >> 10U);
}

/**
  * @brief    Set Channel 0 Nominal Bitrate prescaler
  * @rmtoll   CFDC0NCFG    NBRP    FL_CANFD_CH0_WriteNominalBitratePrescaler
  * @param    CANFDx CANFD instance
  * @param    psc 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_WriteNominalBitratePrescaler(CANFD_COMMON_Type* CANFDx, uint32_t psc)
{
    MODIFY_REG(CANFDx->CFDC0NCFG, (0x3ffU << 0U), (psc << 0U));
}

/**
  * @brief    Get Channel 0 Nominal Bitrate prescaler
  * @rmtoll   CFDC0NCFG    NBRP    FL_CANFD_CH0_ReadNominalBitratePrescaler
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_ReadNominalBitratePrescaler(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0NCFG, (0x3ffU << 0U)) >> 0U);
}

/**
  * @brief    Channel 0 Restricted operation mode enable
  * @rmtoll   CFDC0CTR    ROM    FL_CANFD_CH0_EnableRestrictedOperationMode
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableRestrictedOperationMode(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_ROM_Msk);
}

/**
  * @brief    Channel 0 Restricted operation mode disable
  * @rmtoll   CFDC0CTR    ROM    FL_CANFD_CH0_DisableRestrictedOperationMode
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableRestrictedOperationMode(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_ROM_Msk);
}

/**
  * @brief    Get Channel 0 Restricted operation mode enable status
  * @rmtoll   CFDC0CTR    ROM    FL_CANFD_CH0_IsEnabledRestrictedOperationMode
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledRestrictedOperationMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_ROM_Msk) == CANFD_CFDC0CTR_ROM_Msk);
}

/**
  * @brief    Channel 0 Bit flip test enable
  * @rmtoll   CFDC0CTR    BFT    FL_CANFD_CH0_EnableBitFlipTest
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableBitFlipTest(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BFT_Msk);
}

/**
  * @brief    Channel 0 Bit flip test disable
  * @rmtoll   CFDC0CTR    BFT    FL_CANFD_CH0_DisableBitFlipTest
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableBitFlipTest(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BFT_Msk);
}

/**
  * @brief    Get Channel 0 Bit flip test enable status
  * @rmtoll   CFDC0CTR    BFT    FL_CANFD_CH0_IsEnabledBitFlipTest
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledBitFlipTest(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BFT_Msk) == CANFD_CFDC0CTR_BFT_Msk);
}

/**
  * @brief    Set Channel 0 Channel test mode
  * @rmtoll   CFDC0CTR    CTMS    FL_CANFD_CH0_SetChannelTestMode
  * @param    CANFDx CANFD instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CHANNEL_TEST_MODE_BASIC
  *           @arg @ref FL_CANFD_CHANNEL_TEST_MODE_LISTEN
  *           @arg @ref FL_CANFD_CHANNEL_TEST_MODE_SELFTEST0
  *           @arg @ref FL_CANFD_CHANNEL_TEST_MODE_SELFTEST1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_SetChannelTestMode(CANFD_COMMON_Type* CANFDx, uint32_t mode)
{
    MODIFY_REG(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_CTMS_Msk, mode);
}

/**
  * @brief    Get Channel 0 Channel test mode
  * @rmtoll   CFDC0CTR    CTMS    FL_CANFD_CH0_GetChannelTestMode
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CHANNEL_TEST_MODE_BASIC
  *           @arg @ref FL_CANFD_CHANNEL_TEST_MODE_LISTEN
  *           @arg @ref FL_CANFD_CHANNEL_TEST_MODE_SELFTEST0
  *           @arg @ref FL_CANFD_CHANNEL_TEST_MODE_SELFTEST1
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_GetChannelTestMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_CTMS_Msk));
}

/**
  * @brief    Channel 0 Channel test mode enable
  * @rmtoll   CFDC0CTR    CTME    FL_CANFD_CH0_EnableChannelTestMode
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableChannelTestMode(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_CTME_Msk);
}

/**
  * @brief    Channel 0 Channel test mode disable
  * @rmtoll   CFDC0CTR    CTME    FL_CANFD_CH0_DisableChannelTestMode
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableChannelTestMode(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_CTME_Msk);
}

/**
  * @brief    Get Channel 0 Channel test mode enable status
  * @rmtoll   CFDC0CTR    CTME    FL_CANFD_CH0_IsEnabledChannelTestMode
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledChannelTestMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_CTME_Msk) == CANFD_CFDC0CTR_CTME_Msk);
}

/**
  * @brief    Set Channel 0 Channel error display type
  * @rmtoll   CFDC0CTR    ERRD    FL_CANFD_CH0_SetChannelErrorDisplayType
  * @param    CANFDx CANFD instance
  * @param    type This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CHANNEL_ERROR_DISPLAY_TYPE_FIRST_GROUP
  *           @arg @ref FL_CANFD_CHANNEL_ERROR_DISPLAY_TYPE_CUMULATIVE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_SetChannelErrorDisplayType(CANFD_COMMON_Type* CANFDx, uint32_t type)
{
    MODIFY_REG(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_ERRD_Msk, type);
}

/**
  * @brief    Get Channel 0 Channel error display type
  * @rmtoll   CFDC0CTR    ERRD    FL_CANFD_CH0_GetChannelErrorDisplayType
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CHANNEL_ERROR_DISPLAY_TYPE_FIRST_GROUP
  *           @arg @ref FL_CANFD_CHANNEL_ERROR_DISPLAY_TYPE_CUMULATIVE
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_GetChannelErrorDisplayType(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_ERRD_Msk));
}

/**
  * @brief    Set Channel 0 Channel Bus-Off Mode
  * @rmtoll   CFDC0CTR    BOM    FL_CANFD_CH0_SetChannelBusOffMode
  * @param    CANFDx CANFD instance
  * @param    type This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CHANNEL_BUSOFF_MODE_NORMAL
  *           @arg @ref FL_CANFD_CHANNEL_BUSOFF_MODE_HALT_AT_BUSOFF_SATRT
  *           @arg @ref FL_CANFD_CHANNEL_BUSOFF_MODE_HALT_AT_BUSOFF_END
  *           @arg @ref FL_CANFD_CHANNEL_BUSOFF_MODE_HALT_BY_SW
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_SetChannelBusOffMode(CANFD_COMMON_Type* CANFDx, uint32_t type)
{
    MODIFY_REG(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BOM_Msk, type);
}

/**
  * @brief    Get Channel 0 Channel Bus-Off Mode
  * @rmtoll   CFDC0CTR    BOM    FL_CANFD_CH0_GetChannelBusOffMode
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CHANNEL_BUSOFF_MODE_NORMAL
  *           @arg @ref FL_CANFD_CHANNEL_BUSOFF_MODE_HALT_AT_BUSOFF_SATRT
  *           @arg @ref FL_CANFD_CHANNEL_BUSOFF_MODE_HALT_AT_BUSOFF_END
  *           @arg @ref FL_CANFD_CHANNEL_BUSOFF_MODE_HALT_BY_SW
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_GetChannelBusOffMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BOM_Msk));
}

/**
  * @brief    Channel 0 Transceiver Delay Compensation Violation interrupt enable 
  * @rmtoll   CFDC0CTR    TDCVFIE    FL_CANFD_CH0_EnableIT_TransceiverDelayCompensationViolation
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableIT_TransceiverDelayCompensationViolation(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_TDCVFIE_Msk);
}

/**
  * @brief    Channel 0 Transceiver Delay Compensation Violation interrupt enable status 
  * @rmtoll   CFDC0CTR    TDCVFIE    FL_CANFD_CH0_IsEnabledIT_TransceiverDelayCompensationViolation
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledIT_TransceiverDelayCompensationViolation(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_TDCVFIE_Msk) == CANFD_CFDC0CTR_TDCVFIE_Msk);
}

/**
  * @brief    Channel 0 Transceiver Delay Compensation Violation  interrupt disable 
  * @rmtoll   CFDC0CTR    TDCVFIE    FL_CANFD_CH0_DisableIT_TransceiverDelayCompensationViolation
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableIT_TransceiverDelayCompensationViolation(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_TDCVFIE_Msk);
}

/**
  * @brief    Channel 0 Successful occurrence counter overflow interrupt enable 
  * @rmtoll   CFDC0CTR    SOCOIE    FL_CANFD_CH0_EnableIT_SuccessfulOccurrenceCounterOverflow
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableIT_SuccessfulOccurrenceCounterOverflow(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_SOCOIE_Msk);
}

/**
  * @brief    Channel 0 Successful occurrence counter overflow interrupt enable status 
  * @rmtoll   CFDC0CTR    SOCOIE    FL_CANFD_CH0_IsEnabledIT_SuccessfulOccurrenceCounterOverflow
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledIT_SuccessfulOccurrenceCounterOverflow(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_SOCOIE_Msk) == CANFD_CFDC0CTR_SOCOIE_Msk);
}

/**
  * @brief    Channel 0 Successful occurrence counter overflow  interrupt disable 
  * @rmtoll   CFDC0CTR    SOCOIE    FL_CANFD_CH0_DisableIT_SuccessfulOccurrenceCounterOverflow
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableIT_SuccessfulOccurrenceCounterOverflow(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_SOCOIE_Msk);
}

/**
  * @brief    Channel 0 Error occurrence counter overflow interrupt enable 
  * @rmtoll   CFDC0CTR    EOCOIE    FL_CANFD_CH0_EnableIT_ErrorOccurrenceCounterOverflow
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableIT_ErrorOccurrenceCounterOverflow(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_EOCOIE_Msk);
}

/**
  * @brief    Channel 0 Error occurrence counter overflow interrupt enable status 
  * @rmtoll   CFDC0CTR    EOCOIE    FL_CANFD_CH0_IsEnabledIT_ErrorOccurrenceCounterOverflow
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledIT_ErrorOccurrenceCounterOverflow(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_EOCOIE_Msk) == CANFD_CFDC0CTR_EOCOIE_Msk);
}

/**
  * @brief    Channel 0 Error occurrence counter overflow  interrupt disable 
  * @rmtoll   CFDC0CTR    EOCOIE    FL_CANFD_CH0_DisableIT_ErrorOccurrenceCounterOverflow
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableIT_ErrorOccurrenceCounterOverflow(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_EOCOIE_Msk);
}

/**
  * @brief    Channel 0 Transmission abort interrupt enable 
  * @rmtoll   CFDC0CTR    TAIE    FL_CANFD_CH0_EnableIT_TxAbort
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableIT_TxAbort(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_TAIE_Msk);
}

/**
  * @brief    Channel 0 Transmission abort interrupt enable status 
  * @rmtoll   CFDC0CTR    TAIE    FL_CANFD_CH0_IsEnabledIT_TxAbort
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledIT_TxAbort(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_TAIE_Msk) == CANFD_CFDC0CTR_TAIE_Msk);
}

/**
  * @brief    Channel 0 Transmission abort  interrupt disable 
  * @rmtoll   CFDC0CTR    TAIE    FL_CANFD_CH0_DisableIT_TxAbort
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableIT_TxAbort(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_TAIE_Msk);
}

/**
  * @brief    Channel 0 Arbitration Lost  interrupt enable 
  * @rmtoll   CFDC0CTR    ALIE    FL_CANFD_CH0_EnableIT_ArbitrationLost
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableIT_ArbitrationLost(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_ALIE_Msk);
}

/**
  * @brief    Channel 0 Arbitration Lost  interrupt enable status 
  * @rmtoll   CFDC0CTR    ALIE    FL_CANFD_CH0_IsEnabledIT_ArbitrationLost
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledIT_ArbitrationLost(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_ALIE_Msk) == CANFD_CFDC0CTR_ALIE_Msk);
}

/**
  * @brief    Channel 0 Arbitration Lost   interrupt disable 
  * @rmtoll   CFDC0CTR    ALIE    FL_CANFD_CH0_DisableIT_ArbitrationLost
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableIT_ArbitrationLost(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_ALIE_Msk);
}

/**
  * @brief    Channel 0 Bus Lock interrupt enable 
  * @rmtoll   CFDC0CTR    BLIE    FL_CANFD_CH0_EnableIT_BusLock
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableIT_BusLock(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BLIE_Msk);
}

/**
  * @brief    Channel 0 Bus Lock interrupt enable status 
  * @rmtoll   CFDC0CTR    BLIE    FL_CANFD_CH0_IsEnabledIT_BusLock
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledIT_BusLock(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BLIE_Msk) == CANFD_CFDC0CTR_BLIE_Msk);
}

/**
  * @brief    Channel 0 Bus Lock interrupt disable 
  * @rmtoll   CFDC0CTR    BLIE    FL_CANFD_CH0_DisableIT_BusLock
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableIT_BusLock(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BLIE_Msk);
}

/**
  * @brief    Channel 0 Overload interrupt enable 
  * @rmtoll   CFDC0CTR    OLIE    FL_CANFD_CH0_EnableIT_Overload
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableIT_Overload(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_OLIE_Msk);
}

/**
  * @brief    Channel 0 Overload interrupt enable status 
  * @rmtoll   CFDC0CTR    OLIE    FL_CANFD_CH0_IsEnabledIT_Overload
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledIT_Overload(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_OLIE_Msk) == CANFD_CFDC0CTR_OLIE_Msk);
}

/**
  * @brief    Channel 0 Overload interrupt disable 
  * @rmtoll   CFDC0CTR    OLIE    FL_CANFD_CH0_DisableIT_Overload
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableIT_Overload(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_OLIE_Msk);
}

/**
  * @brief    Channel 0 Bus-Off Recovery interrupt enable 
  * @rmtoll   CFDC0CTR    BORIE    FL_CANFD_CH0_EnableIT_BusOffRecovery
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableIT_BusOffRecovery(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BORIE_Msk);
}

/**
  * @brief    Channel 0 Bus-Off Recovery interrupt enable status 
  * @rmtoll   CFDC0CTR    BORIE    FL_CANFD_CH0_IsEnabledIT_BusOffRecovery
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledIT_BusOffRecovery(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BORIE_Msk) == CANFD_CFDC0CTR_BORIE_Msk);
}

/**
  * @brief    Channel 0 Bus-Off Recovery interrupt disable 
  * @rmtoll   CFDC0CTR    BORIE    FL_CANFD_CH0_DisableIT_BusOffRecovery
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableIT_BusOffRecovery(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BORIE_Msk);
}

/**
  * @brief    Channel 0 Bus-Off Entry interrupt enable 
  * @rmtoll   CFDC0CTR    BOEIE    FL_CANFD_CH0_EnableIT_BusOff
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableIT_BusOff(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BOEIE_Msk);
}

/**
  * @brief    Channel 0 Bus-Off Entry interrupt enable status 
  * @rmtoll   CFDC0CTR    BOEIE    FL_CANFD_CH0_IsEnabledIT_BusOff
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledIT_BusOff(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BOEIE_Msk) == CANFD_CFDC0CTR_BOEIE_Msk);
}

/**
  * @brief    Channel 0 Bus-Off Entry interrupt disable 
  * @rmtoll   CFDC0CTR    BOEIE    FL_CANFD_CH0_DisableIT_BusOff
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableIT_BusOff(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BOEIE_Msk);
}

/**
  * @brief    Channel 0 Error Passive interrupt enable 
  * @rmtoll   CFDC0CTR    EPIE    FL_CANFD_CH0_EnableIT_ErrorPassive
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableIT_ErrorPassive(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_EPIE_Msk);
}

/**
  * @brief    Channel 0 Error Passive interrupt enable status 
  * @rmtoll   CFDC0CTR    EPIE    FL_CANFD_CH0_IsEnabledIT_ErrorPassive
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledIT_ErrorPassive(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_EPIE_Msk) == CANFD_CFDC0CTR_EPIE_Msk);
}

/**
  * @brief    Channel 0 Error Passive interrupt disable 
  * @rmtoll   CFDC0CTR    EPIE    FL_CANFD_CH0_DisableIT_ErrorPassive
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableIT_ErrorPassive(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_EPIE_Msk);
}

/**
  * @brief    Channel 0 Error Warning interrupt enable 
  * @rmtoll   CFDC0CTR    EWIE    FL_CANFD_CH0_EnableIT_ErrorWarning
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableIT_ErrorWarning(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_EWIE_Msk);
}

/**
  * @brief    Channel 0 Error Warning interrupt enable status 
  * @rmtoll   CFDC0CTR    EWIE    FL_CANFD_CH0_IsEnabledIT_ErrorWarning
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledIT_ErrorWarning(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_EWIE_Msk) == CANFD_CFDC0CTR_EWIE_Msk);
}

/**
  * @brief    Channel 0 Error Warning interrupt disable 
  * @rmtoll   CFDC0CTR    EWIE    FL_CANFD_CH0_DisableIT_ErrorWarning
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableIT_ErrorWarning(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_EWIE_Msk);
}

/**
  * @brief    Channel 0 Bus Error interrupt enable 
  * @rmtoll   CFDC0CTR    BEIE    FL_CANFD_CH0_EnableIT_BusError
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_EnableIT_BusError(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BEIE_Msk);
}

/**
  * @brief    Channel 0 Bus Error interrupt enable status 
  * @rmtoll   CFDC0CTR    BEIE    FL_CANFD_CH0_IsEnabledIT_BusError
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabledIT_BusError(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BEIE_Msk) == CANFD_CFDC0CTR_BEIE_Msk);
}

/**
  * @brief    Channel 0 Bus Error interrupt disable 
  * @rmtoll   CFDC0CTR    BEIE    FL_CANFD_CH0_DisableIT_BusError
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_DisableIT_BusError(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_BEIE_Msk);
}

/**
  * @brief    Channel 0 Software Return from Bus-Off enable 
  * @rmtoll   CFDC0CTR    RTBO    FL_CANFD_CH0_Enable_ReturnFromBusOff
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_Enable_ReturnFromBusOff(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_RTBO_Msk);
}

/**
  * @brief    Channel 0 Software Return from Bus-Off disable 
  * @rmtoll   CFDC0CTR    RTBO    FL_CANFD_CH0_Disable_ReturnFromBusOff
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_Disable_ReturnFromBusOff(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_RTBO_Msk);
}

/**
  * @brief    Channel 0 Software Return from Bus-Off enable status
  * @rmtoll   CFDC0CTR    RTBO    FL_CANFD_CH0_IsEnabled_ReturnFromBusOff
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabled_ReturnFromBusOff(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_RTBO_Msk) == CANFD_CFDC0CTR_RTBO_Msk);
}

/**
  * @brief    Channel 0 Channel Sleep Request enable 
  * @rmtoll   CFDC0CTR    CSLPR    FL_CANFD_CH0_Enable_Sleep
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_Enable_Sleep(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_CSLPR_Msk);
}

/**
  * @brief    Channel 0 Channel Sleep Request disable 
  * @rmtoll   CFDC0CTR    CSLPR    FL_CANFD_CH0_Disable_Sleep
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_Disable_Sleep(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_CSLPR_Msk);
}

/**
  * @brief    Channel 0 Channel Sleep Request enable status
  * @rmtoll   CFDC0CTR    CSLPR    FL_CANFD_CH0_IsEnabled_Sleep
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsEnabled_Sleep(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_CSLPR_Msk) == CANFD_CFDC0CTR_CSLPR_Msk);
}

/**
  * @brief    Set Channel 0 Channel Mode
  * @rmtoll   CFDC0CTR    CHMDC    FL_CANFD_CH0_SetChannelMode
  * @param    CANFDx CANFD instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CHANNEL_MODE_OPERATION
  *           @arg @ref FL_CANFD_CHANNEL_MODE_RESET
  *           @arg @ref FL_CANFD_CHANNEL_MODE_HALT
  *           @arg @ref FL_CANFD_CHANNEL_MODE_KEEP_CURRENT
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_SetChannelMode(CANFD_COMMON_Type* CANFDx, uint32_t mode)
{
    MODIFY_REG(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_CHMDC_Msk, mode);
}

/**
  * @brief    Get Channel 0 Channel Mode
  * @rmtoll   CFDC0CTR    CHMDC    FL_CANFD_CH0_GetChannelMode
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CHANNEL_MODE_OPERATION
  *           @arg @ref FL_CANFD_CHANNEL_MODE_RESET
  *           @arg @ref FL_CANFD_CHANNEL_MODE_HALT
  *           @arg @ref FL_CANFD_CHANNEL_MODE_KEEP_CURRENT
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_GetChannelMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0CTR, CANFD_CFDC0CTR_CHMDC_Msk));
}

/**
  * @brief    Get Channel 0 Transmission Error Count
  * @rmtoll   CFDC0STS    TEC    FL_CANFD_CH0_ReadTxErrorCount
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_ReadTxErrorCount(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0STS, (0xffU << 24U)) >> 24U);
}

/**
  * @brief    Get Channel 0 Reception Error Count 
  * @rmtoll   CFDC0STS    REC    FL_CANFD_CH0_ReadRxErrorCount
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_ReadRxErrorCount(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0STS, (0xffU << 16U)) >> 16U);
}

/**
  * @brief    Get Channel 0 Error State Indication Flag
  * @rmtoll   CFDC0STS    ESIF    FL_CANFD_CH0_IsActiveFlag_ErrorStateIndication
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_ErrorStateIndication(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0STS, CANFD_CFDC0STS_ESIF_Msk) == (CANFD_CFDC0STS_ESIF_Msk));
}

/**
  * @brief    Clear Channel 0 Error State Indication Flag
  * @rmtoll   CFDC0STS    ESIF    FL_CANFD_CH0_ClearFlag_ErrorStateIndication
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_ErrorStateIndication(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0STS, CANFD_CFDC0STS_ESIF_Msk);
}

/**
  * @brief    Get Channel 0 Channel Communication Status
  * @rmtoll   CFDC0STS    COMSTS    FL_CANFD_CH0_IsActiveFlag_CommStatus
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_CommStatus(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0STS, CANFD_CFDC0STS_COMSTS_Msk) == (CANFD_CFDC0STS_COMSTS_Msk));
}

/**
  * @brief    Get Channel 0 Channel Receive Status
  * @rmtoll   CFDC0STS    RECSTS    FL_CANFD_CH0_IsActiveFlag_RxStatus
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_RxStatus(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0STS, CANFD_CFDC0STS_RECSTS_Msk) == (CANFD_CFDC0STS_RECSTS_Msk));
}

/**
  * @brief    Get Channel 0 Channel Transmit Status
  * @rmtoll   CFDC0STS    TRMSTS    FL_CANFD_CH0_IsActiveFlag_TxStatus
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_TxStatus(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0STS, CANFD_CFDC0STS_TRMSTS_Msk) == (CANFD_CFDC0STS_TRMSTS_Msk));
}

/**
  * @brief    Get Channel 0 Channel Bus-Off Status
  * @rmtoll   CFDC0STS    BOSTS    FL_CANFD_CH0_IsActiveFlag_BusOffStatus
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_BusOffStatus(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0STS, CANFD_CFDC0STS_BOSTS_Msk) == (CANFD_CFDC0STS_BOSTS_Msk));
}

/**
  * @brief    Get Channel 0 Channel Error Passive Status
  * @rmtoll   CFDC0STS    EPSTS    FL_CANFD_CH0_IsActiveFlag_ErrorPassiveStatus
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_ErrorPassiveStatus(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0STS, CANFD_CFDC0STS_EPSTS_Msk) == (CANFD_CFDC0STS_EPSTS_Msk));
}

/**
  * @brief    Get Channel 0 Channel SLEEP Status
  * @rmtoll   CFDC0STS    CSLPSTS    FL_CANFD_CH0_IsActiveFlag_SleepStatus
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_SleepStatus(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0STS, CANFD_CFDC0STS_CSLPSTS_Msk) == (CANFD_CFDC0STS_CSLPSTS_Msk));
}

/**
  * @brief    Get Channel 0 Channel HALT Status
  * @rmtoll   CFDC0STS    CHLTSTS    FL_CANFD_CH0_IsActiveFlag_HaltStatus
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_HaltStatus(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0STS, CANFD_CFDC0STS_CHLTSTS_Msk) == (CANFD_CFDC0STS_CHLTSTS_Msk));
}

/**
  * @brief    Get Channel 0 Channel RESET Status
  * @rmtoll   CFDC0STS    CRSTSTS    FL_CANFD_CH0_IsActiveFlag_ResetStatus
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_ResetStatus(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0STS, CANFD_CFDC0STS_CRSTSTS_Msk) == (CANFD_CFDC0STS_CRSTSTS_Msk));
}

/**
  * @brief    Get Channel 0 CRC Register value
  * @rmtoll   CFDC0ERFL    CRCREG    FL_CANFD_CH0_ReadCRCREG
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_ReadCRCREG(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, (0x7fffU << 16U)) >> 16U);
}

/**
  * @brief    Get Channel 0 Acknowledge Delimiter Error
  * @rmtoll   CFDC0ERFL    ADERR    FL_CANFD_CH0_IsActiveFlag_AckDelimiterError
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_AckDelimiterError(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_ADERR_Msk) == (CANFD_CFDC0ERFL_ADERR_Msk));
}

/**
  * @brief    Clear Channel 0 Acknowledge Delimiter Error
  * @rmtoll   CFDC0ERFL    ADERR    FL_CANFD_CH0_ClearFlag_AckDelimiterError
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_AckDelimiterError(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_ADERR_Msk);
}

/**
  * @brief    Get Channel 0 Bit 0 Error
  * @rmtoll   CFDC0ERFL    B0ERR    FL_CANFD_CH0_IsActiveFlag_Bit0Error
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_Bit0Error(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_B0ERR_Msk) == (CANFD_CFDC0ERFL_B0ERR_Msk));
}

/**
  * @brief    Clear Channel 0 Bit 0 Error
  * @rmtoll   CFDC0ERFL    B0ERR    FL_CANFD_CH0_ClearFlag_Bit0Error
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_Bit0Error(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_B0ERR_Msk);
}

/**
  * @brief    Get Channel 0 Bit 1 Error
  * @rmtoll   CFDC0ERFL    B1ERR    FL_CANFD_CH0_IsActiveFlag_Bit1Error
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_Bit1Error(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_B1ERR_Msk) == (CANFD_CFDC0ERFL_B1ERR_Msk));
}

/**
  * @brief    Clear Channel 0 Bit 1 Error
  * @rmtoll   CFDC0ERFL    B1ERR    FL_CANFD_CH0_ClearFlag_Bit1Error
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_Bit1Error(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_B1ERR_Msk);
}

/**
  * @brief    Get Channel 0 CRC Error
  * @rmtoll   CFDC0ERFL    CERR    FL_CANFD_CH0_IsActiveFlag_CRCError
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_CRCError(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_CERR_Msk) == (CANFD_CFDC0ERFL_CERR_Msk));
}

/**
  * @brief    Clear Channel 0 CRC Error
  * @rmtoll   CFDC0ERFL    CERR    FL_CANFD_CH0_ClearFlag_CRCError
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_CRCError(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_CERR_Msk);
}

/**
  * @brief    Get Channel 0 Acknowledge Error
  * @rmtoll   CFDC0ERFL    AERR    FL_CANFD_CH0_IsActiveFlag_AckError
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_AckError(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_AERR_Msk) == (CANFD_CFDC0ERFL_AERR_Msk));
}

/**
  * @brief    Clear Channel 0 Acknowledge Error
  * @rmtoll   CFDC0ERFL    AERR    FL_CANFD_CH0_ClearFlag_AckError
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_AckError(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_AERR_Msk);
}

/**
  * @brief    Get Channel 0 Form Error
  * @rmtoll   CFDC0ERFL    FERR    FL_CANFD_CH0_IsActiveFlag_FormError
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_FormError(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_FERR_Msk) == (CANFD_CFDC0ERFL_FERR_Msk));
}

/**
  * @brief    Clear Channel 0 Form Error
  * @rmtoll   CFDC0ERFL    FERR    FL_CANFD_CH0_ClearFlag_FormError
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_FormError(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_FERR_Msk);
}

/**
  * @brief    Get Channel 0 Stuff Error
  * @rmtoll   CFDC0ERFL    SERR    FL_CANFD_CH0_IsActiveFlag_StuffError
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_StuffError(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_SERR_Msk) == (CANFD_CFDC0ERFL_SERR_Msk));
}

/**
  * @brief    Clear Channel 0 Stuff Error
  * @rmtoll   CFDC0ERFL    SERR    FL_CANFD_CH0_ClearFlag_StuffError
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_StuffError(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_SERR_Msk);
}

/**
  * @brief    Get Channel 0 Arbitration Lost Flag
  * @rmtoll   CFDC0ERFL    ALF    FL_CANFD_CH0_IsActiveFlag_ArbitrationLost
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_ArbitrationLost(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_ALF_Msk) == (CANFD_CFDC0ERFL_ALF_Msk));
}

/**
  * @brief    Clear Channel 0 Arbitration Lost Flag
  * @rmtoll   CFDC0ERFL    ALF    FL_CANFD_CH0_ClearFlag_ArbitrationLost
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_ArbitrationLost(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_ALF_Msk);
}

/**
  * @brief    Get Channel 0 Bus Lock Flag
  * @rmtoll   CFDC0ERFL    BLF    FL_CANFD_CH0_IsActiveFlag_BusLock
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_BusLock(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_BLF_Msk) == (CANFD_CFDC0ERFL_BLF_Msk));
}

/**
  * @brief    Clear Channel 0 Bus Lock Flag
  * @rmtoll   CFDC0ERFL    BLF    FL_CANFD_CH0_ClearFlag_BusLock
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_BusLock(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_BLF_Msk);
}

/**
  * @brief    Get Channel 0 Overload Flag
  * @rmtoll   CFDC0ERFL    OVLF    FL_CANFD_CH0_IsActiveFlag_OverLoad
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_OverLoad(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_OVLF_Msk) == (CANFD_CFDC0ERFL_OVLF_Msk));
}

/**
  * @brief    Clear Channel 0 Overload Flag
  * @rmtoll   CFDC0ERFL    OVLF    FL_CANFD_CH0_ClearFlag_OverLoad
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_OverLoad(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_OVLF_Msk);
}

/**
  * @brief    Get Channel 0 Bus-Off Recovery Flag
  * @rmtoll   CFDC0ERFL    BORF    FL_CANFD_CH0_IsActiveFlag_BusOffRecovery
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_BusOffRecovery(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_BORF_Msk) == (CANFD_CFDC0ERFL_BORF_Msk));
}

/**
  * @brief    Clear Channel 0 Bus-Off Recovery Flag
  * @rmtoll   CFDC0ERFL    BORF    FL_CANFD_CH0_ClearFlag_BusOffRecovery
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_BusOffRecovery(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_BORF_Msk);
}

/**
  * @brief    Get Channel 0 Bus-Off Entry Flag
  * @rmtoll   CFDC0ERFL    BOEF    FL_CANFD_CH0_IsActiveFlag_BusOff
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_BusOff(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_BOEF_Msk) == (CANFD_CFDC0ERFL_BOEF_Msk));
}

/**
  * @brief    Clear Channel 0 Bus-Off Entry Flag
  * @rmtoll   CFDC0ERFL    BOEF    FL_CANFD_CH0_ClearFlag_BusOff
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_BusOff(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_BOEF_Msk);
}

/**
  * @brief    Get Channel 0 Error Passive Flag
  * @rmtoll   CFDC0ERFL    EPF    FL_CANFD_CH0_IsActiveFlag_ErrorPassive
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_ErrorPassive(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_EPF_Msk) == (CANFD_CFDC0ERFL_EPF_Msk));
}

/**
  * @brief    Clear Channel 0 Error Passive Flag
  * @rmtoll   CFDC0ERFL    EPF    FL_CANFD_CH0_ClearFlag_ErrorPassive
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_ErrorPassive(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_EPF_Msk);
}

/**
  * @brief    Get Channel 0 Error Warning Flag
  * @rmtoll   CFDC0ERFL    EWF    FL_CANFD_CH0_IsActiveFlag_ErrorWarning
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_ErrorWarning(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_EWF_Msk) == (CANFD_CFDC0ERFL_EWF_Msk));
}

/**
  * @brief    Clear Channel 0 Error Warning Flag
  * @rmtoll   CFDC0ERFL    EWF    FL_CANFD_CH0_ClearFlag_ErrorWarning
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_ErrorWarning(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_EWF_Msk);
}

/**
  * @brief    Get Channel 0 Bus Error Flag
  * @rmtoll   CFDC0ERFL    BEF    FL_CANFD_CH0_IsActiveFlag_BusError
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_IsActiveFlag_BusError(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_BEF_Msk) == (CANFD_CFDC0ERFL_BEF_Msk));
}

/**
  * @brief    Clear Channel 0 Bus Error Flag
  * @rmtoll   CFDC0ERFL    BEF    FL_CANFD_CH0_ClearFlag_BusError
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_ClearFlag_BusError(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0ERFL, CANFD_CFDC0ERFL_BEF_Msk);
}

/**
  * @brief    Set Channel 0 Data Bitrate Resynchronization jump width
  * @rmtoll   CFDC0DCFG    DSJW    FL_CANFD_CH0_WriteDataBitrateSyncJumpWidth
  * @param    CANFDx CANFD instance
  * @param    width 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_WriteDataBitrateSyncJumpWidth(CANFD_COMMON_Type* CANFDx, uint32_t width)
{
    MODIFY_REG(CANFDx->CFDC0DCFG, (0xfU << 24U), (width << 24U));
}

/**
  * @brief    Get Channel 0 Data Bitrate Resynchronization jump width
  * @rmtoll   CFDC0DCFG    DSJW    FL_CANFD_CH0_ReadDataBitrateSyncJumpWidth
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_ReadDataBitrateSyncJumpWidth(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0DCFG, (0xfU << 24U)) >> 24U);
}

/**
  * @brief    Set Channel 0 Data Bitrate Timing segment 2
  * @rmtoll   CFDC0DCFG    DTSEG2    FL_CANFD_CH0_WriteDataBitrateTimeSegment2Length
  * @param    CANFDx CANFD instance
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_WriteDataBitrateTimeSegment2Length(CANFD_COMMON_Type* CANFDx, uint32_t length)
{
    MODIFY_REG(CANFDx->CFDC0DCFG, (0xfU << 16U), (length << 16U));
}

/**
  * @brief    Get Channel 0 Data Bitrate Timing segment 2
  * @rmtoll   CFDC0DCFG    DTSEG2    FL_CANFD_CH0_ReadDataBitrateTimeSegment2Length
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_ReadDataBitrateTimeSegment2Length(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0DCFG, (0xfU << 16U)) >> 16U);
}

/**
  * @brief    Set Channel 0 Data Bitrate Timing segment 1
  * @rmtoll   CFDC0DCFG    DTSEG1    FL_CANFD_CH0_WriteDataBitrateTimeSegment1Length
  * @param    CANFDx CANFD instance
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_WriteDataBitrateTimeSegment1Length(CANFD_COMMON_Type* CANFDx, uint32_t length)
{
    MODIFY_REG(CANFDx->CFDC0DCFG, (0x1fU << 8U), (length << 8U));
}

/**
  * @brief    Get Channel 0 Data Bitrate Timing segment 1
  * @rmtoll   CFDC0DCFG    DTSEG1    FL_CANFD_CH0_ReadDataBitrateTimeSegment1Length
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_ReadDataBitrateTimeSegment1Length(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0DCFG, (0x1fU << 8U)) >> 8U);
}

/**
  * @brief    Set Channel 0 Data Bitrate prescaler
  * @rmtoll   CFDC0DCFG    DBRP    FL_CANFD_CH0_WriteDataBitratePrescaler
  * @param    CANFDx CANFD instance
  * @param    psc 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_WriteDataBitratePrescaler(CANFD_COMMON_Type* CANFDx, uint32_t psc)
{
    MODIFY_REG(CANFDx->CFDC0DCFG, (0xffU << 0U), (psc << 0U));
}

/**
  * @brief    Get Channel 0 Data Bitrate prescaler
  * @rmtoll   CFDC0DCFG    DBRP    FL_CANFD_CH0_ReadDataBitratePrescaler
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_ReadDataBitratePrescaler(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0DCFG, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Channel 0 Classical CAN only enable
  * @rmtoll   CFDC0FDCFG    CLOE    FL_CANFD_CH0_FD_Enable_ClassicalCANOnly
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_Enable_ClassicalCANOnly(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_CLOE_Msk);
}

/**
  * @brief    Channel 0 Classical CAN only disable 
  * @rmtoll   CFDC0FDCFG    CLOE    FL_CANFD_CH0_FD_Disable_ClassicalCANOnly
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_Disable_ClassicalCANOnly(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_CLOE_Msk);
}

/**
  * @brief    Channel 0 Get Classical CAN only enable status
  * @rmtoll   CFDC0FDCFG    CLOE    FL_CANFD_CH0_FD_IsEnabled_ClassicalCANOnly
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_IsEnabled_ClassicalCANOnly(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_CLOE_Msk) == CANFD_CFDC0FDCFG_CLOE_Msk);
}

/**
  * @brief    Channel 0 RX edge filter enable
  * @rmtoll   CFDC0FDCFG    REFE    FL_CANFD_CH0_FD_Enable_RxEdgeFilter
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_Enable_RxEdgeFilter(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_REFE_Msk);
}

/**
  * @brief    Channel 0 RX edge filter disable 
  * @rmtoll   CFDC0FDCFG    REFE    FL_CANFD_CH0_FD_Disable_RxEdgeFilter
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_Disable_RxEdgeFilter(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_REFE_Msk);
}

/**
  * @brief    Channel 0 Get RX edge filter enable status
  * @rmtoll   CFDC0FDCFG    REFE    FL_CANFD_CH0_FD_IsEnabled_RxEdgeFilter
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_IsEnabled_RxEdgeFilter(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_REFE_Msk) == CANFD_CFDC0FDCFG_REFE_Msk);
}

/**
  * @brief    Channel 0 FD only enable
  * @rmtoll   CFDC0FDCFG    FDOE    FL_CANFD_CH0_FD_Enable_FDOnly
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_Enable_FDOnly(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_FDOE_Msk);
}

/**
  * @brief    Channel 0 FD only disable 
  * @rmtoll   CFDC0FDCFG    FDOE    FL_CANFD_CH0_FD_Disable_FDOnly
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_Disable_FDOnly(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_FDOE_Msk);
}

/**
  * @brief    Channel 0 FD only enable status
  * @rmtoll   CFDC0FDCFG    FDOE    FL_CANFD_CH0_FD_IsEnabled_FDOnly
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_IsEnabled_FDOnly(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_FDOE_Msk) == CANFD_CFDC0FDCFG_FDOE_Msk);
}

/**
  * @brief    Set Channel 0 Transceiver Delay Compensation Offset
  * @rmtoll   CFDC0FDCFG    TDCO    FL_CANFD_CH0_FD_Write_TransceiverDelayCompensationOffset
  * @param    CANFDx CANFD instance
  * @param    width 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_Write_TransceiverDelayCompensationOffset(CANFD_COMMON_Type* CANFDx, uint32_t width)
{
    MODIFY_REG(CANFDx->CFDC0FDCFG, (0xffU << 16U), (width << 16U));
}

/**
  * @brief    Get Channel 0 Transceiver Delay Compensation Offset
  * @rmtoll   CFDC0FDCFG    TDCO    FL_CANFD_CH0_FD_Read_TransceiverDelayCompensationOffset
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_Read_TransceiverDelayCompensationOffset(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDCFG, (0xffU << 16U)) >> 16U);
}

/**
  * @brief    Set Channel 0 Return Pretended Network Filter Mode
  * @rmtoll   CFDC0FDCFG    RPNMD    FL_CANFD_CH0_FD_SetReturnPNFMode
  * @param    CANFDx CANFD instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RETURN_PNF_MODE_AF
  *           @arg @ref FL_CANFD_RETURN_PNF_MODE_PNFID_AF
  *           @arg @ref FL_CANFD_RETURN_PNF_MODE_PNF_AF
  *           @arg @ref FL_CANFD_RETURN_PNF_MODE_PNF
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_SetReturnPNFMode(CANFD_COMMON_Type* CANFDx, uint32_t mode)
{
    MODIFY_REG(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_RPNMD_Msk, mode);
}

/**
  * @brief    Get Channel 0 Return Pretended Network Filter Mode
  * @rmtoll   CFDC0FDCFG    RPNMD    FL_CANFD_CH0_FD_GetReturnPNFMode
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_RETURN_PNF_MODE_AF
  *           @arg @ref FL_CANFD_RETURN_PNF_MODE_PNFID_AF
  *           @arg @ref FL_CANFD_RETURN_PNF_MODE_PNF_AF
  *           @arg @ref FL_CANFD_RETURN_PNF_MODE_PNF
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_GetReturnPNFMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_RPNMD_Msk));
}

/**
  * @brief    Set Channel 0 Error State Indication Configuration
  * @rmtoll   CFDC0FDCFG    ESIC    FL_CANFD_CH0_FD_SetErrorStateIndicationConfiguration
  * @param    CANFDx CANFD instance
  * @param    configuration This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_ESI_CONFIGURATION_NODE_STATE
  *           @arg @ref FL_CANFD_ESI_CONFIGURATION_SOFTWARE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_SetErrorStateIndicationConfiguration(CANFD_COMMON_Type* CANFDx, uint32_t configuration)
{
    MODIFY_REG(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_ESIC_Msk, configuration);
}

/**
  * @brief    Get Channel 0 Error State Indication Configuration
  * @rmtoll   CFDC0FDCFG    ESIC    FL_CANFD_CH0_FD_GetErrorStateIndicationConfiguration
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_ESI_CONFIGURATION_NODE_STATE
  *           @arg @ref FL_CANFD_ESI_CONFIGURATION_SOFTWARE
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_GetErrorStateIndicationConfiguration(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_ESIC_Msk));
}

/**
  * @brief    Channel 0 Transceiver Delay Compensation Enable
  * @rmtoll   CFDC0FDCFG    TDCE    FL_CANFD_CH0_FD_Enable_TransceiverDelayCompensation
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_Enable_TransceiverDelayCompensation(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_TDCE_Msk);
}

/**
  * @brief    Channel 0 Transceiver Delay Compensation disable 
  * @rmtoll   CFDC0FDCFG    TDCE    FL_CANFD_CH0_FD_Disable_TransceiverDelayCompensation
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_Disable_TransceiverDelayCompensation(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_TDCE_Msk);
}

/**
  * @brief    Channel 0 Transceiver Delay Compensation enable status
  * @rmtoll   CFDC0FDCFG    TDCE    FL_CANFD_CH0_FD_IsEnabled_TransceiverDelayCompensation
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_IsEnabled_TransceiverDelayCompensation(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_TDCE_Msk) == CANFD_CFDC0FDCFG_TDCE_Msk);
}

/**
  * @brief    Set Channel 0 Transceiver Delay Compensation Offset Configuration
  * @rmtoll   CFDC0FDCFG    TDCOC    FL_CANFD_CH0_FD_SetTransceiverDelayCompensationOffsetConfiguration
  * @param    CANFDx CANFD instance
  * @param    configuration This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TDCO_CONFIGURATION_MEASURED_WITH_OFFSET
  *           @arg @ref FL_CANFD_TDCO_CONFIGURATION_OFFSET
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_SetTransceiverDelayCompensationOffsetConfiguration(CANFD_COMMON_Type* CANFDx, uint32_t configuration)
{
    MODIFY_REG(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_TDCOC_Msk, configuration);
}

/**
  * @brief    Get Channel 0 Transceiver Delay Compensation Offset Configuration
  * @rmtoll   CFDC0FDCFG    TDCOC    FL_CANFD_CH0_FD_GetTransceiverDelayCompensationOffsetConfiguration
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TDCO_CONFIGURATION_MEASURED_WITH_OFFSET
  *           @arg @ref FL_CANFD_TDCO_CONFIGURATION_OFFSET
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_GetTransceiverDelayCompensationOffsetConfiguration(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_TDCOC_Msk));
}

/**
  * @brief    Set Channel 0 Error Occurrence Counter Configuration
  * @rmtoll   CFDC0FDCFG    EOCCFG    FL_CANFD_CH0_FD_SetErrorOccurrenceCounterConfiguration
  * @param    CANFDx CANFD instance
  * @param    configuration This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_EOC_CONFIGURATION_ALL
  *           @arg @ref FL_CANFD_EOC_CONFIGURATION_TRANSMITTER
  *           @arg @ref FL_CANFD_EOC_CONFIGURATION_RECEIVER
  *           @arg @ref FL_CANFD_EOC_CONFIGURATION_ALL_FD_DATAPHASE
  *           @arg @ref FL_CANFD_EOC_CONFIGURATION_TRANSMITTER_FD_DATAPHASE
  *           @arg @ref FL_CANFD_EOC_CONFIGURATION_RECEIVER_FD_DATAPHASE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_SetErrorOccurrenceCounterConfiguration(CANFD_COMMON_Type* CANFDx, uint32_t configuration)
{
    MODIFY_REG(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_EOCCFG_Msk, configuration);
}

/**
  * @brief    Get Channel 0 Error Occurrence Counter Configuration
  * @rmtoll   CFDC0FDCFG    EOCCFG    FL_CANFD_CH0_FD_GetErrorOccurrenceCounterConfiguration
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_EOC_CONFIGURATION_ALL
  *           @arg @ref FL_CANFD_EOC_CONFIGURATION_TRANSMITTER
  *           @arg @ref FL_CANFD_EOC_CONFIGURATION_RECEIVER
  *           @arg @ref FL_CANFD_EOC_CONFIGURATION_ALL_FD_DATAPHASE
  *           @arg @ref FL_CANFD_EOC_CONFIGURATION_TRANSMITTER_FD_DATAPHASE
  *           @arg @ref FL_CANFD_EOC_CONFIGURATION_RECEIVER_FD_DATAPHASE
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_GetErrorOccurrenceCounterConfiguration(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDCFG, CANFD_CFDC0FDCFG_EOCCFG_Msk));
}

/**
  * @brief    Set Channel 0 Key to rewrite PNMDC bit
  * @rmtoll   CFDC0FDCTR    KEY    FL_CANFD_CH0_FD_WriteKeyOfPNMDC
  * @param    CANFDx CANFD instance
  * @param    key 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_WriteKeyOfPNMDC(CANFD_COMMON_Type* CANFDx, uint32_t key)
{
    MODIFY_REG(CANFDx->CFDC0FDCTR, (0xffU << 24U), (key << 24U));
}

/**
  * @brief    Get Channel 0 Key to rewrite PNMDC bit
  * @rmtoll   CFDC0FDCTR    KEY    FL_CANFD_CH0_FD_ReadKeyOfPNMDC
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_ReadKeyOfPNMDC(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDCTR, (0xffU << 24U)) >> 24U);
}

/**
  * @brief    Set Channel 0 Pretended Network Filter Mode
  * @rmtoll   CFDC0FDCTR    PNMDC    FL_CANFD_CH0_FD_SetPNFMode
  * @param    CANFDx CANFD instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PNF_MODE_AF
  *           @arg @ref FL_CANFD_PNF_MODE_PNFID_AF
  *           @arg @ref FL_CANFD_PNF_MODE_PNF_AF
  *           @arg @ref FL_CANFD_PNF_MODE_PNF
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_SetPNFMode(CANFD_COMMON_Type* CANFDx, uint32_t mode)
{
    MODIFY_REG(CANFDx->CFDC0FDCTR, CANFD_CFDC0FDCTR_PNMDC_Msk, mode);
}

/**
  * @brief    Get Channel 0 Pretended Network Filter Mode
  * @rmtoll   CFDC0FDCTR    PNMDC    FL_CANFD_CH0_FD_GetPNFMode
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_PNF_MODE_AF
  *           @arg @ref FL_CANFD_PNF_MODE_PNFID_AF
  *           @arg @ref FL_CANFD_PNF_MODE_PNF_AF
  *           @arg @ref FL_CANFD_PNF_MODE_PNF
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_GetPNFMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDCTR, CANFD_CFDC0FDCTR_PNMDC_Msk));
}

/**
  * @brief    Channel 0 Successful Occurrence Counter Clear enable
  * @rmtoll   CFDC0FDCTR    SOCCLR    FL_CANFD_CH0_FD_Enable_SuccessfulOccurrenceCounterClear
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_Enable_SuccessfulOccurrenceCounterClear(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0FDCTR, CANFD_CFDC0FDCTR_SOCCLR_Msk);
}

/**
  * @brief    Channel 0 Error Occurrence Counter Clear enable
  * @rmtoll   CFDC0FDCTR    EOCCLR    FL_CANFD_CH0_FD_Enable_ErrorOccurrenceCounterClear
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_Enable_ErrorOccurrenceCounterClear(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDC0FDCTR, CANFD_CFDC0FDCTR_EOCCLR_Msk);
}

/**
  * @brief    Get Channel 0 Successful occurrence counter
  * @rmtoll   CFDC0FDSTS    SOC    FL_CANFD_CH0_FD_ReadSuccessfulOccurrenceCounter
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_ReadSuccessfulOccurrenceCounter(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDSTS, (0xffU << 24U)) >> 24U);
}

/**
  * @brief    Get Channel 0 Error occurrence counter
  * @rmtoll   CFDC0FDSTS    EOC    FL_CANFD_CH0_FD_ReadErrorOccurrenceCounter
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_ReadErrorOccurrenceCounter(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDSTS, (0xffU << 16U)) >> 16U);
}

/**
  * @brief    Get Channel 0 Transceiver Delay Compensation Violation Flag
  * @rmtoll   CFDC0FDSTS    TDCVF    FL_CANFD_CH0_FD_IsActiveFlag_TransceiverDelayCompensationViolation
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_IsActiveFlag_TransceiverDelayCompensationViolation(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDSTS, CANFD_CFDC0FDSTS_TDCVF_Msk) == (CANFD_CFDC0FDSTS_TDCVF_Msk));
}

/**
  * @brief    Clear Channel 0 Transceiver Delay Compensation Violation Flag
  * @rmtoll   CFDC0FDSTS    TDCVF    FL_CANFD_CH0_FD_ClearFlag_TransceiverDelayCompensationViolation
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_ClearFlag_TransceiverDelayCompensationViolation(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0FDSTS, CANFD_CFDC0FDSTS_TDCVF_Msk);
}

/**
  * @brief    Get Channel 0 Pretended Network Filter State
  * @rmtoll   CFDC0FDSTS    PNSTS    FL_CANFD_CH0_FD_GetPNFState
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_PNF_STATE_AF
  *           @arg @ref FL_CANFD_PNF_STATE_PNFID_AF
  *           @arg @ref FL_CANFD_PNF_STATE_PNF_AF
  *           @arg @ref FL_CANFD_PNF_STATE_PNF
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_GetPNFState(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDSTS, CANFD_CFDC0FDSTS_PNSTS_Msk));
}

/**
  * @brief    Get Channel 0 Successful occurrence counter overflow flag
  * @rmtoll   CFDC0FDSTS    SOCO    FL_CANFD_CH0_FD_IsActiveFlag_SuccessfulOccurrenceCounterOverflow
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_IsActiveFlag_SuccessfulOccurrenceCounterOverflow(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDSTS, CANFD_CFDC0FDSTS_SOCO_Msk) == (CANFD_CFDC0FDSTS_SOCO_Msk));
}

/**
  * @brief    Clear Channel 0 Successful occurrence counter overflow flag
  * @rmtoll   CFDC0FDSTS    SOCO    FL_CANFD_CH0_FD_ClearFlag_SuccessfulOccurrenceCounterOverflow
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_ClearFlag_SuccessfulOccurrenceCounterOverflow(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0FDSTS, CANFD_CFDC0FDSTS_SOCO_Msk);
}

/**
  * @brief    Get Channel 0 Error occurrence counter overflow flag
  * @rmtoll   CFDC0FDSTS    EOCO    FL_CANFD_CH0_FD_IsActiveFlag_ErrorOccurrenceCounterOverflow
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_IsActiveFlag_ErrorOccurrenceCounterOverflow(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDSTS, CANFD_CFDC0FDSTS_EOCO_Msk) == (CANFD_CFDC0FDSTS_EOCO_Msk));
}

/**
  * @brief    Clear Channel 0 Error occurrence counter overflow flag
  * @rmtoll   CFDC0FDSTS    EOCO    FL_CANFD_CH0_FD_ClearFlag_ErrorOccurrenceCounterOverflow
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_CH0_FD_ClearFlag_ErrorOccurrenceCounterOverflow(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDC0FDSTS, CANFD_CFDC0FDSTS_EOCO_Msk);
}

/**
  * @brief    Get Channel 0 Transceiver Delay Compensation Result
  * @rmtoll   CFDC0FDSTS    TDCR    FL_CANFD_CH0_FD_ReadTransceiverDelayCompensationResult
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_ReadTransceiverDelayCompensationResult(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDSTS, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Get Channel 0 CAN-FD Frame Stuff bit count
  * @rmtoll   CFDC0FDCRC    SCNT    FL_CANFD_CH0_FD_ReadStuffBitCount
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_ReadStuffBitCount(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDCRC, (0xfU << 24U)) >> 24U);
}

/**
  * @brief    Get Channel 0 CAN-FD Frame CRC Register value
  * @rmtoll   CFDC0FDCRC    CRCREG    FL_CANFD_CH0_FD_ReadCRC
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_CH0_FD_ReadCRC(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDC0FDCRC, (0x1fffffU << 0U)) >> 0U);
}

/**
  * @brief    Get Global Parameter Status Information
  * @rmtoll   CFDGIPV    PSI    FL_CANFD_Global_FD_ReadParameterStatusInformation
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_FD_ReadParameterStatusInformation(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGIPV, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Get Global CPU bus information
  * @rmtoll   CFDGIPV    CPUBUS    FL_CANFD_Global_FD_GetCPUBusInformation
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_FD_GetCPUBusInformation(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGIPV, CANFD_CFDGIPV_CPUBUS_Msk));
}

/**
  * @brief    Get Global IP Type Release Number
  * @rmtoll   CFDGIPV    IPT    FL_CANFD_Global_FD_ReadIPTypeReleaseNumber
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_FD_ReadIPTypeReleaseNumber(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGIPV, (0x3U << 8U)) >> 8U);
}

/**
  * @brief    Get Global IP Version Release Number
  * @rmtoll   CFDGIPV    IPV    FL_CANFD_Global_FD_ReadIPVersionReleaseNumber
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_FD_ReadIPVersionReleaseNumber(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGIPV, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Get Global Interval Timer Reference Clock Prescaler
  * @rmtoll   CFDGCFG    ITRCP    FL_CANFD_Global_ReadIntervalTimerReferenceClockPrescaler
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadIntervalTimerReferenceClockPrescaler(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCFG, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Set Global Interval Timer Reference Clock Prescaler
  * @rmtoll   CFDGCFG    ITRCP    FL_CANFD_Global_WriteIntervalTimerReferenceClockPrescaler
  * @param    CANFDx CANFD instance
  * @param    psc 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteIntervalTimerReferenceClockPrescaler(CANFD_COMMON_Type* CANFDx, uint32_t psc)
{
    MODIFY_REG(CANFDx->CFDGCFG, (0xffffU << 16U), (psc << 16U));
}

/**
  * @brief    Set Global Timestamp Source
  * @rmtoll   CFDGCFG    TSSS    FL_CANFD_Global_SetTimestampSource
  * @param    CANFDx CANFD instance
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TSSS_CLOCK_PERIPHERAL
  *           @arg @ref FL_CANFD_TSSS_CLOCK_BIT_TIME
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetTimestampSource(CANFD_COMMON_Type* CANFDx, uint32_t clock)
{
    MODIFY_REG(CANFDx->CFDGCFG, CANFD_CFDGCFG_TSSS_Msk, clock);
}

/**
  * @brief    Get Global Timestamp Source
  * @rmtoll   CFDGCFG    TSSS    FL_CANFD_Global_GetTimestampSource
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TSSS_CLOCK_PERIPHERAL
  *           @arg @ref FL_CANFD_TSSS_CLOCK_BIT_TIME
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTimestampSource(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCFG, CANFD_CFDGCFG_TSSS_Msk));
}

/**
  * @brief    Set Global Timestamp Prescaler
  * @rmtoll   CFDGCFG    TSP    FL_CANFD_Global_SetTimestampPrescaler
  * @param    CANFDx CANFD instance
  * @param    psc This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TSP_PSC_1
  *           @arg @ref FL_CANFD_TSP_PSC_2
  *           @arg @ref FL_CANFD_TSP_PSC_4
  *           @arg @ref FL_CANFD_TSP_PSC_8
  *           @arg @ref FL_CANFD_TSP_PSC_16
  *           @arg @ref FL_CANFD_TSP_PSC_32
  *           @arg @ref FL_CANFD_TSP_PSC_64
  *           @arg @ref FL_CANFD_TSP_PSC_128
  *           @arg @ref FL_CANFD_TSP_PSC_256
  *           @arg @ref FL_CANFD_TSP_PSC_512
  *           @arg @ref FL_CANFD_TSP_PSC_1024
  *           @arg @ref FL_CANFD_TSP_PSC_2048
  *           @arg @ref FL_CANFD_TSP_PSC_4096
  *           @arg @ref FL_CANFD_TSP_PSC_8192
  *           @arg @ref FL_CANFD_TSP_PSC_16384
  *           @arg @ref FL_CANFD_TSP_PSC_32768
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetTimestampPrescaler(CANFD_COMMON_Type* CANFDx, uint32_t psc)
{
    MODIFY_REG(CANFDx->CFDGCFG, CANFD_CFDGCFG_TSP_Msk, psc);
}

/**
  * @brief    Get Global Timestamp Prescaler
  * @rmtoll   CFDGCFG    TSP    FL_CANFD_Global_GetTimestampPrescaler
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TSP_PSC_1
  *           @arg @ref FL_CANFD_TSP_PSC_2
  *           @arg @ref FL_CANFD_TSP_PSC_4
  *           @arg @ref FL_CANFD_TSP_PSC_8
  *           @arg @ref FL_CANFD_TSP_PSC_16
  *           @arg @ref FL_CANFD_TSP_PSC_32
  *           @arg @ref FL_CANFD_TSP_PSC_64
  *           @arg @ref FL_CANFD_TSP_PSC_128
  *           @arg @ref FL_CANFD_TSP_PSC_256
  *           @arg @ref FL_CANFD_TSP_PSC_512
  *           @arg @ref FL_CANFD_TSP_PSC_1024
  *           @arg @ref FL_CANFD_TSP_PSC_2048
  *           @arg @ref FL_CANFD_TSP_PSC_4096
  *           @arg @ref FL_CANFD_TSP_PSC_8192
  *           @arg @ref FL_CANFD_TSP_PSC_16384
  *           @arg @ref FL_CANFD_TSP_PSC_32768
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTimestampPrescaler(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCFG, CANFD_CFDGCFG_TSP_Msk));
}

/**
  * @brief    Set Global CAN-FD message Payload overflow configuration
  * @rmtoll   CFDGCFG    CMPOC    FL_CANFD_Global_SetCANFDMessagePayloadOverflowConfiguration
  * @param    CANFDx CANFD instance
  * @param    configuration This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CMPOC_CONFIGURATION_REJECTED
  *           @arg @ref FL_CANFD_CMPOC_CONFIGURATION_CUTOFF
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetCANFDMessagePayloadOverflowConfiguration(CANFD_COMMON_Type* CANFDx, uint32_t configuration)
{
    MODIFY_REG(CANFDx->CFDGCFG, CANFD_CFDGCFG_CMPOC_Msk, configuration);
}

/**
  * @brief    Get Global CAN-FD message Payload overflow configuration
  * @rmtoll   CFDGCFG    CMPOC    FL_CANFD_Global_GetCANFDMessagePayloadOverflowConfiguration
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CMPOC_CONFIGURATION_REJECTED
  *           @arg @ref FL_CANFD_CMPOC_CONFIGURATION_CUTOFF
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetCANFDMessagePayloadOverflowConfiguration(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCFG, CANFD_CFDGCFG_CMPOC_Msk));
}

/**
  * @brief    Set Global Data Link Controller Clock Select
  * @rmtoll   CFDGCFG    DCS    FL_CANFD_Global_SetDataLinkControllerClock
  * @param    CANFDx CANFD instance
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_DCS_CLOCK_INTERNAL
  *           @arg @ref FL_CANFD_DCS_CLOCK_EXTRENAL
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetDataLinkControllerClock(CANFD_COMMON_Type* CANFDx, uint32_t clock)
{
    MODIFY_REG(CANFDx->CFDGCFG, CANFD_CFDGCFG_DCS_Msk, clock);
}

/**
  * @brief    Get Global Data Link Controller Clock Select
  * @rmtoll   CFDGCFG    DCS    FL_CANFD_Global_GetDataLinkControllerClock
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_DCS_CLOCK_INTERNAL
  *           @arg @ref FL_CANFD_DCS_CLOCK_EXTRENAL
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetDataLinkControllerClock(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCFG, CANFD_CFDGCFG_DCS_Msk));
}

/**
  * @brief    Global Mirror Mode Enable
  * @rmtoll   CFDGCFG    MME    FL_CANFD_Global_Enable_MirrorMode
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_MirrorMode(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDGCFG, CANFD_CFDGCFG_MME_Msk);
}

/**
  * @brief    Global Mirror Mode disable 
  * @rmtoll   CFDGCFG    MME    FL_CANFD_Global_Disable_MirrorMode
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_MirrorMode(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGCFG, CANFD_CFDGCFG_MME_Msk);
}

/**
  * @brief    Global Mirror Mode enable status
  * @rmtoll   CFDGCFG    MME    FL_CANFD_Global_IsEnabled_MirrorMode
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_MirrorMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCFG, CANFD_CFDGCFG_MME_Msk) == CANFD_CFDGCFG_MME_Msk);
}

/**
  * @brief    Global DLC Replacement Enable
  * @rmtoll   CFDGCFG    DRE    FL_CANFD_Global_Enable_DLCReplacement
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_DLCReplacement(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDGCFG, CANFD_CFDGCFG_DRE_Msk);
}

/**
  * @brief    Global DLC Replacement disable 
  * @rmtoll   CFDGCFG    DRE    FL_CANFD_Global_Disable_DLCReplacement
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_DLCReplacement(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGCFG, CANFD_CFDGCFG_DRE_Msk);
}

/**
  * @brief    Global DLC Replacement enable status
  * @rmtoll   CFDGCFG    DRE    FL_CANFD_Global_IsEnabled_DLCReplacement
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_DLCReplacement(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCFG, CANFD_CFDGCFG_DRE_Msk) == CANFD_CFDGCFG_DRE_Msk);
}

/**
  * @brief    Global DLC Check Enable
  * @rmtoll   CFDGCFG    DCE    FL_CANFD_Global_Enable_DLCCheck
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_DLCCheck(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDGCFG, CANFD_CFDGCFG_DCE_Msk);
}

/**
  * @brief    Global DLC Check disable 
  * @rmtoll   CFDGCFG    DCE    FL_CANFD_Global_Disable_DLCCheck
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_DLCCheck(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGCFG, CANFD_CFDGCFG_DCE_Msk);
}

/**
  * @brief    Global DLC Check enable status
  * @rmtoll   CFDGCFG    DCE    FL_CANFD_Global_IsEnabled_DLCCheck
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_DLCCheck(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCFG, CANFD_CFDGCFG_DCE_Msk) == CANFD_CFDGCFG_DCE_Msk);
}

/**
  * @brief    Set Global Transmission Priority
  * @rmtoll   CFDGCFG    TPRI    FL_CANFD_Global_SetTxPriority
  * @param    CANFDx CANFD instance
  * @param    priority This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TX_PRIORITY_ID
  *           @arg @ref FL_CANFD_TX_PRIORITY_BUFFER
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetTxPriority(CANFD_COMMON_Type* CANFDx, uint32_t priority)
{
    MODIFY_REG(CANFDx->CFDGCFG, CANFD_CFDGCFG_TPRI_Msk, priority);
}

/**
  * @brief    Get Global Transmission Priority
  * @rmtoll   CFDGCFG    TPRI    FL_CANFD_Global_GetTxPriority
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TX_PRIORITY_ID
  *           @arg @ref FL_CANFD_TX_PRIORITY_BUFFER
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTxPriority(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCFG, CANFD_CFDGCFG_TPRI_Msk));
}

/**
  * @brief    Set Global Timestamp Reset
  * @rmtoll   CFDGCTR    TSRST    FL_CANFD_Global_SetTimestampReset
  * @param    CANFDx CANFD instance
  * @param    reset This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TS_RST_NO_RESET
  *           @arg @ref FL_CANFD_TS_RST_RESET
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetTimestampReset(CANFD_COMMON_Type* CANFDx, uint32_t reset)
{
    MODIFY_REG(CANFDx->CFDGCTR, CANFD_CFDGCTR_TSRST_Msk, reset);
}

/**
  * @brief    Get Global Timestamp Reset
  * @rmtoll   CFDGCTR    TSRST    FL_CANFD_Global_GetTimestampReset
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TS_RST_NO_RESET
  *           @arg @ref FL_CANFD_TS_RST_RESET
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTimestampReset(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_TSRST_Msk));
}

/**
  * @brief    Global CAN-FD message payload overflow Flag Interrupt enable 
  * @rmtoll   CFDGCTR    CMPOFIE    FL_CANFD_Global_EnableIT_CANFDMessagePayloadOverflow
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_EnableIT_CANFDMessagePayloadOverflow(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_CMPOFIE_Msk);
}

/**
  * @brief    Global CAN-FD message payload overflow Flag Interrupt enable status 
  * @rmtoll   CFDGCTR    CMPOFIE    FL_CANFD_Global_IsEnabledIT_CANFDMessagePayloadOverflow
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabledIT_CANFDMessagePayloadOverflow(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_CMPOFIE_Msk) == CANFD_CFDGCTR_CMPOFIE_Msk);
}

/**
  * @brief    Global CAN-FD message payload overflow Flag Interrupt disable 
  * @rmtoll   CFDGCTR    CMPOFIE    FL_CANFD_Global_DisableIT_CANFDMessagePayloadOverflow
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_DisableIT_CANFDMessagePayloadOverflow(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_CMPOFIE_Msk);
}

/**
  * @brief    Global TX History List Entry Lost  Interrupt enable 
  * @rmtoll   CFDGCTR    THLEIE    FL_CANFD_Global_EnableIT_TxHistoryListEntryLost
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_EnableIT_TxHistoryListEntryLost(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_THLEIE_Msk);
}

/**
  * @brief    Global TX History List Entry Lost Interrupt enable status 
  * @rmtoll   CFDGCTR    THLEIE    FL_CANFD_Global_IsEnabledIT_TxHistoryListEntryLost
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabledIT_TxHistoryListEntryLost(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_THLEIE_Msk) == CANFD_CFDGCTR_THLEIE_Msk);
}

/**
  * @brief    Global TX History List Entry Lost Interrupt disable 
  * @rmtoll   CFDGCTR    THLEIE    FL_CANFD_Global_DisableIT_TxHistoryListEntryLost
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_DisableIT_TxHistoryListEntryLost(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_THLEIE_Msk);
}

/**
  * @brief    Global Message lost Error  Interrupt enable 
  * @rmtoll   CFDGCTR    MEIE    FL_CANFD_Global_EnableIT_MessageLostError
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_EnableIT_MessageLostError(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_MEIE_Msk);
}

/**
  * @brief    Global Message lost Error  Interrupt enable status 
  * @rmtoll   CFDGCTR    MEIE    FL_CANFD_Global_IsEnabledIT_MessageLostError
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabledIT_MessageLostError(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_MEIE_Msk) == CANFD_CFDGCTR_MEIE_Msk);
}

/**
  * @brief    Global Message lost Error  Interrupt disable 
  * @rmtoll   CFDGCTR    MEIE    FL_CANFD_Global_DisableIT_MessageLostError
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_DisableIT_MessageLostError(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_MEIE_Msk);
}

/**
  * @brief    Global DLC check  Interrupt enable 
  * @rmtoll   CFDGCTR    DEIE    FL_CANFD_Global_EnableIT_DLCCheck
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_EnableIT_DLCCheck(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_DEIE_Msk);
}

/**
  * @brief    Global DLC check  Interrupt enable status 
  * @rmtoll   CFDGCTR    DEIE    FL_CANFD_Global_IsEnabledIT_DLCCheck
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabledIT_DLCCheck(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_DEIE_Msk) == CANFD_CFDGCTR_DEIE_Msk);
}

/**
  * @brief    Global DLC check  Interrupt disable 
  * @rmtoll   CFDGCTR    DEIE    FL_CANFD_Global_DisableIT_DLCCheck
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_DisableIT_DLCCheck(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_DEIE_Msk);
}

/**
  * @brief    Global Sleep enable 
  * @rmtoll   CFDGCTR    GSLPR    FL_CANFD_Global_Enable_Sleep
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_Sleep(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_GSLPR_Msk);
}

/**
  * @brief    Global Sleep enable status 
  * @rmtoll   CFDGCTR    GSLPR    FL_CANFD_Global_IsEnabled_Sleep
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_Sleep(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_GSLPR_Msk) == CANFD_CFDGCTR_GSLPR_Msk);
}

/**
  * @brief    Global Sleep disable 
  * @rmtoll   CFDGCTR    GSLPR    FL_CANFD_Global_Disable_Sleep
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_Sleep(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_GSLPR_Msk);
}

/**
  * @brief    Set Global Mode
  * @rmtoll   CFDGCTR    GMDC    FL_CANFD_Global_SetGlobalMode
  * @param    CANFDx CANFD instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GLOBAL_MODE_OPERATION
  *           @arg @ref FL_CANFD_GLOBAL_MODE_RESET
  *           @arg @ref FL_CANFD_GLOBAL_MODE_HALT
  *           @arg @ref FL_CANFD_GLOBAL_MODE_KEEP_CURRENT
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGlobalMode(CANFD_COMMON_Type* CANFDx, uint32_t mode)
{
    MODIFY_REG(CANFDx->CFDGCTR, CANFD_CFDGCTR_GMDC_Msk, mode);
}

/**
  * @brief    Get Global Mode
  * @rmtoll   CFDGCTR    GMDC    FL_CANFD_Global_GetGlobalMode
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GLOBAL_MODE_OPERATION
  *           @arg @ref FL_CANFD_GLOBAL_MODE_RESET
  *           @arg @ref FL_CANFD_GLOBAL_MODE_HALT
  *           @arg @ref FL_CANFD_GLOBAL_MODE_KEEP_CURRENT
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGlobalMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGCTR, CANFD_CFDGCTR_GMDC_Msk));
}

/**
  * @brief    Get Global RAM Initialisation
  * @rmtoll   CFDGSTS    GRAMINIT    FL_CANFD_Global_IsActiveFlag_GlobalRAMInitialisation
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_GlobalRAMInitialisation(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGSTS, CANFD_CFDGSTS_GRAMINIT_Msk) == (CANFD_CFDGSTS_GRAMINIT_Msk));
}

/**
  * @brief    Get Global SLEEP Status
  * @rmtoll   CFDGSTS    GSLPSTS    FL_CANFD_Global_IsActiveFlag_GlobalSleepStatus
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_GlobalSleepStatus(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGSTS, CANFD_CFDGSTS_GSLPSTS_Msk) == (CANFD_CFDGSTS_GSLPSTS_Msk));
}

/**
  * @brief    Get Global HALT Status
  * @rmtoll   CFDGSTS    GHLTSTS    FL_CANFD_Global_IsActiveFlag_GlobalHaltStatus
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_GlobalHaltStatus(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGSTS, CANFD_CFDGSTS_GHLTSTS_Msk) == (CANFD_CFDGSTS_GHLTSTS_Msk));
}

/**
  * @brief    Get Global RESET Status
  * @rmtoll   CFDGSTS    GRSTSTS    FL_CANFD_Global_IsActiveFlag_GlobalResetStatus
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_GlobalResetStatus(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGSTS, CANFD_CFDGSTS_GRSTSTS_Msk) == (CANFD_CFDGSTS_GRSTSTS_Msk));
}

/**
  * @brief    Get Global ECC Error Flag
  * @rmtoll   CFDGERFL    EEF    FL_CANFD_Global_IsActiveFlag_ECCError
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_ECCError(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGERFL, CANFD_CFDGERFL_EEF_Msk) == (CANFD_CFDGERFL_EEF_Msk));
}

/**
  * @brief    Clear Global ECC Error Flag
  * @rmtoll   CFDGERFL    EEF    FL_CANFD_Global_ClearFlag_ECCError
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_ClearFlag_ECCError(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGERFL, CANFD_CFDGERFL_EEF_Msk);
}

/**
  * @brief    Get Global CAN-FD message payload overflow Flag
  * @rmtoll   CFDGERFL    CMPOF    FL_CANFD_Global_IsActiveFlag_CANFDMessagePayloadOverflow
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_CANFDMessagePayloadOverflow(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGERFL, CANFD_CFDGERFL_CMPOF_Msk) == (CANFD_CFDGERFL_CMPOF_Msk));
}

/**
  * @brief    Clear Global CAN-FD message payload overflow Flag
  * @rmtoll   CFDGERFL    CMPOF    FL_CANFD_Global_ClearFlag_CANFDMessagePayloadOverflow
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_ClearFlag_CANFDMessagePayloadOverflow(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGERFL, CANFD_CFDGERFL_CMPOF_Msk);
}

/**
  * @brief    Get Global TX History List Entry Lost Error Status Flag
  * @rmtoll   CFDGERFL    THLES    FL_CANFD_Global_IsActiveFlag_TxHistoryListEntryLostErrorStatus
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TxHistoryListEntryLostErrorStatus(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGERFL, CANFD_CFDGERFL_THLES_Msk) == (CANFD_CFDGERFL_THLES_Msk));
}

/**
  * @brief    Get Global Message Lost Error Status
  * @rmtoll   CFDGERFL    MES    FL_CANFD_Global_IsActiveFlag_MessageLostErrorStatus
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_MessageLostErrorStatus(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGERFL, CANFD_CFDGERFL_MES_Msk) == (CANFD_CFDGERFL_MES_Msk));
}

/**
  * @brief    Get Global DLC Error Flag
  * @rmtoll   CFDGERFL    DEF    FL_CANFD_Global_IsActiveFlag_DLCError
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_DLCError(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGERFL, CANFD_CFDGERFL_DEF_Msk) == (CANFD_CFDGERFL_DEF_Msk));
}

/**
  * @brief    Clear Global DLC Error Flag
  * @rmtoll   CFDGERFL    DEF    FL_CANFD_Global_ClearFlag_DLCError
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_ClearFlag_DLCError(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGERFL, CANFD_CFDGERFL_DEF_Msk);
}

/**
  * @brief    Get Global TX History List Interrupt Flag
  * @rmtoll   CFDGTINTSTS    THIF    FL_CANFD_Global_IsActiveFlag_TxHistoryList
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TxHistoryList(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGTINTSTS, CANFD_CFDGTINTSTS_THIF_Msk) == (CANFD_CFDGTINTSTS_THIF_Msk));
}

/**
  * @brief    Get Global Common FIFO TX Mode Interrupt Flag
  * @rmtoll   CFDGTINTSTS    CFTIF    FL_CANFD_Global_IsActiveFlag_CommonFIFOTxMode
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_CommonFIFOTxMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGTINTSTS, CANFD_CFDGTINTSTS_CFTIF_Msk) == (CANFD_CFDGTINTSTS_CFTIF_Msk));
}

/**
  * @brief    Get Global TX Queue Interrupt Flag
  * @rmtoll   CFDGTINTSTS    TQIF    FL_CANFD_Global_IsActiveFlag_TxQueue
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TxQueue(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGTINTSTS, CANFD_CFDGTINTSTS_TQIF_Msk) == (CANFD_CFDGTINTSTS_TQIF_Msk));
}

/**
  * @brief    Get Global TX Abort Interrupt Flag
  * @rmtoll   CFDGTINTSTS    TAIF    FL_CANFD_Global_IsActiveFlag_TxAbort
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TxAbort(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGTINTSTS, CANFD_CFDGTINTSTS_TAIF_Msk) == (CANFD_CFDGTINTSTS_TAIF_Msk));
}

/**
  * @brief    Get Global TX Successful Interrupt Flag
  * @rmtoll   CFDGTINTSTS    TSIF    FL_CANFD_Global_IsActiveFlag_TxSuccessful
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TxSuccessful(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGTINTSTS, CANFD_CFDGTINTSTS_TSIF_Msk) == (CANFD_CFDGTINTSTS_TSIF_Msk));
}

/**
  * @brief    Get Global Timestamp Value
  * @rmtoll   CFDGTSC    TS    FL_CANFD_Global_FD_ReadTimestampValue
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_FD_ReadTimestampValue(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGTSC, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Global Acceptance Filter List Data Access enable 
  * @rmtoll   CFDGAFLECTR    AFLDAE    FL_CANFD_Global_Enable_GAFLDataAccess
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_GAFLDataAccess(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDGAFLECTR, CANFD_CFDGAFLECTR_AFLDAE_Msk);
}

/**
  * @brief    Global Acceptance Filter List Data Access enable status 
  * @rmtoll   CFDGAFLECTR    AFLDAE    FL_CANFD_Global_IsEnabled_GAFLDataAccess
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_GAFLDataAccess(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFLECTR, CANFD_CFDGAFLECTR_AFLDAE_Msk) == CANFD_CFDGAFLECTR_AFLDAE_Msk);
}

/**
  * @brief    Global Acceptance Filter List Data Access disable 
  * @rmtoll   CFDGAFLECTR    AFLDAE    FL_CANFD_Global_Disable_GAFLDataAccess
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_GAFLDataAccess(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGAFLECTR, CANFD_CFDGAFLECTR_AFLDAE_Msk);
}

/**
  * @brief    Set Global Acceptance Filter List Page Number
  * @rmtoll   CFDGAFLECTR    AFLPN    FL_CANFD_Global_SetGAFLPageNumber
  * @param    CANFDx CANFD instance
  * @param    page This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_PAGE_NUMBER_FIRST
  *           @arg @ref FL_CANFD_GAFL_PAGE_NUMBER_SECOND
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGAFLPageNumber(CANFD_COMMON_Type* CANFDx, uint32_t page)
{
    MODIFY_REG(CANFDx->CFDGAFLECTR, CANFD_CFDGAFLECTR_AFLPN_Msk, page);
}

/**
  * @brief    Get Global Acceptance Filter List Page Number
  * @rmtoll   CFDGAFLECTR    AFLPN    FL_CANFD_Global_GetGAFLPageNumber
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_PAGE_NUMBER_FIRST
  *           @arg @ref FL_CANFD_GAFL_PAGE_NUMBER_SECOND
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGAFLPageNumber(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFLECTR, CANFD_CFDGAFLECTR_AFLPN_Msk));
}

/**
  * @brief    Set Global Acceptance Filter List Rule Number
  * @rmtoll   CFDGAFLCFG    RNC    FL_CANFD_Global_WriteGAFLRuleNumber
  * @param    CANFDx CANFD instance
  * @param    number 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGAFLRuleNumber(CANFD_COMMON_Type* CANFDx, uint32_t number)
{
    MODIFY_REG(CANFDx->CFDGAFLCFG, (0x3fU << 16U), (number << 16U));
}

/**
  * @brief    Get Global Acceptance Filter List Rule Number
  * @rmtoll   CFDGAFLCFG    RNC    FL_CANFD_Global_ReadGAFLRuleNumber
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGAFLRuleNumber(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFLCFG, (0x3fU << 16U)) >> 16U);
}

/**
  * @brief    Set Global Acceptance Filter List Entry IDE Field
  * @rmtoll   CFDGAFLIDr    GAFLIDE    FL_CANFD_Global_SetGAFLIDE
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    ide This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_IDE_STANDARD
  *           @arg @ref FL_CANFD_GAFL_IDE_EXTENDED
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGAFLIDE(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t ide)
{
    MODIFY_REG(CANFDx->CFDGAFL[filterX].CFDGAFLIDr, CANFD_CFDGAFLIDr_GAFLIDE_Msk, ide);
}

/**
  * @brief    Get Global Acceptance Filter List Entry IDE Field
  * @rmtoll   CFDGAFLIDr    GAFLIDE    FL_CANFD_Global_GetGAFLIDE
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_IDE_STANDARD
  *           @arg @ref FL_CANFD_GAFL_IDE_EXTENDED
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGAFLIDE(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLIDr, CANFD_CFDGAFLIDr_GAFLIDE_Msk));
}

/**
  * @brief    Set Global Acceptance Filter List Entry RTR Field
  * @rmtoll   CFDGAFLIDr    GAFLRTR    FL_CANFD_Global_SetGAFLRTR
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    rtr This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_RTR_DATA_FRAME
  *           @arg @ref FL_CANFD_GAFL_RTR_REMOTE_FRAME
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGAFLRTR(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t rtr)
{
    MODIFY_REG(CANFDx->CFDGAFL[filterX].CFDGAFLIDr, CANFD_CFDGAFLIDr_GAFLRTR_Msk, rtr);
}

/**
  * @brief    Get Global Acceptance Filter List Entry RTR Field
  * @rmtoll   CFDGAFLIDr    GAFLRTR    FL_CANFD_Global_GetGAFLRTR
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_RTR_DATA_FRAME
  *           @arg @ref FL_CANFD_GAFL_RTR_REMOTE_FRAME
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGAFLRTR(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLIDr, CANFD_CFDGAFLIDr_GAFLRTR_Msk));
}

/**
  * @brief    Set Global Acceptance Filter List Entry Loopback Configuration
  * @rmtoll   CFDGAFLIDr    GAFLLB    FL_CANFD_Global_SetGAFLoopback
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    loopback This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_LB_RX
  *           @arg @ref FL_CANFD_GAFL_LB_TX
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGAFLoopback(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t loopback)
{
    MODIFY_REG(CANFDx->CFDGAFL[filterX].CFDGAFLIDr, CANFD_CFDGAFLIDr_GAFLLB_Msk, loopback);
}

/**
  * @brief    Get Global Acceptance Filter List Entry Loopback Configuration
  * @rmtoll   CFDGAFLIDr    GAFLLB    FL_CANFD_Global_GetGAFLoopback
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_LB_RX
  *           @arg @ref FL_CANFD_GAFL_LB_TX
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGAFLoopback(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLIDr, CANFD_CFDGAFLIDr_GAFLLB_Msk));
}

/**
  * @brief    Set Global Acceptance Filter List Entry ID Field
  * @rmtoll   CFDGAFLIDr    GAFLID    FL_CANFD_Global_WriteGAFLID
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    id 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGAFLID(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t id)
{
    MODIFY_REG(CANFDx->CFDGAFL[filterX].CFDGAFLIDr, (0x1fffffffU << 0U), (id << 0U));
}

/**
  * @brief    Get Global Acceptance Filter List Entry ID Field
  * @rmtoll   CFDGAFLIDr    GAFLID    FL_CANFD_Global_ReadGAFLID
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGAFLID(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLIDr, (0x1fffffffU << 0U)) >> 0U);
}

/**
  * @brief    Set Global Acceptance Filter List Entry IDE Mask
  * @rmtoll   CFDGAFLMr    GAFLIDEM    FL_CANFD_Global_SetGAFLIDEMask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    idem This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_IDEM_NOT_CONSIDERED
  *           @arg @ref FL_CANFD_GAFL_IDEM_CONSIDERED
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGAFLIDEMask(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t idem)
{
    MODIFY_REG(CANFDx->CFDGAFL[filterX].CFDGAFLMr, CANFD_CFDGAFLMr_GAFLIDEM_Msk, idem);
}

/**
  * @brief    Get Global Acceptance Filter List Entry IDE Mask
  * @rmtoll   CFDGAFLMr    GAFLIDEM    FL_CANFD_Global_GetGAFLIDEMask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_IDEM_NOT_CONSIDERED
  *           @arg @ref FL_CANFD_GAFL_IDEM_CONSIDERED
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGAFLIDEMask(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLMr, CANFD_CFDGAFLMr_GAFLIDEM_Msk));
}

/**
  * @brief    Set Global Acceptance Filter List Entry RTR Mask
  * @rmtoll   CFDGAFLMr    GAFLRTRM    FL_CANFD_Global_SetGAFLRTRMask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    rtrm This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_RTRM_NOT_CONSIDERED
  *           @arg @ref FL_CANFD_GAFL_RTRM_CONSIDERED
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGAFLRTRMask(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t rtrm)
{
    MODIFY_REG(CANFDx->CFDGAFL[filterX].CFDGAFLMr, CANFD_CFDGAFLMr_GAFLRTRM_Msk, rtrm);
}

/**
  * @brief    Get Global Acceptance Filter List Entry RTR Mask
  * @rmtoll   CFDGAFLMr    GAFLRTRM    FL_CANFD_Global_GetGAFLRTRMask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_RTRM_NOT_CONSIDERED
  *           @arg @ref FL_CANFD_GAFL_RTRM_CONSIDERED
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGAFLRTRMask(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLMr, CANFD_CFDGAFLMr_GAFLRTRM_Msk));
}

/**
  * @brief    Set Global Acceptance Filter List Information Label 1
  * @rmtoll   CFDGAFLMr    GAFLIFL1    FL_CANFD_Global_SetGAFLInfoLabel1
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    label This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_INFO_LABEL1_0
  *           @arg @ref FL_CANFD_GAFL_INFO_LABEL1_1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGAFLInfoLabel1(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t label)
{
    MODIFY_REG(CANFDx->CFDGAFL[filterX].CFDGAFLMr, CANFD_CFDGAFLMr_GAFLIFL1_Msk, label);
}

/**
  * @brief    Get Global Acceptance Filter List Information Label 1
  * @rmtoll   CFDGAFLMr    GAFLIFL1    FL_CANFD_Global_GetGAFLInfoLabel1
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_INFO_LABEL1_0
  *           @arg @ref FL_CANFD_GAFL_INFO_LABEL1_1
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGAFLInfoLabel1(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLMr, CANFD_CFDGAFLMr_GAFLIFL1_Msk));
}

/**
  * @brief    Set Global Acceptance Filter List Entry ID Mask Field
  * @rmtoll   CFDGAFLMr    GAFLIDM    FL_CANFD_Global_WriteGAFLIDMask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    idm 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGAFLIDMask(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t idm)
{
    MODIFY_REG(CANFDx->CFDGAFL[filterX].CFDGAFLMr, (0x1fffffffU << 0U), (idm << 0U));
}

/**
  * @brief    Get Global Acceptance Filter List Entry ID Mask Field
  * @rmtoll   CFDGAFLMr    GAFLIDM    FL_CANFD_Global_ReadGAFLIDMask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGAFLIDMask(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLMr, (0x1fffffffU << 0U)) >> 0U);
}

/**
  * @brief    Set Global Acceptance Filter List Pointer Field
  * @rmtoll   CFDGAFLP0r    GAFLPTR    FL_CANFD_Global_WriteGAFLPointer
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    ptr 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGAFLPointer(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t ptr)
{
    MODIFY_REG(CANFDx->CFDGAFL[filterX].CFDGAFLP0r, (0xffffU << 16U), (ptr << 16U));
}

/**
  * @brief    Get Global Acceptance Filter List Pointer Field
  * @rmtoll   CFDGAFLP0r    GAFLPTR    FL_CANFD_Global_ReadGAFLPointer
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGAFLPointer(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLP0r, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Set Global Acceptance Filter List RX Message Buffer Valid
  * @rmtoll   CFDGAFLP0r    GAFLRMV    FL_CANFD_Global_SetGAFLRxMBValid
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    valid This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_SINGLE_RXMB_INVALID
  *           @arg @ref FL_CANFD_GAFL_SINGLE_RXMB_VALID
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGAFLRxMBValid(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t valid)
{
    MODIFY_REG(CANFDx->CFDGAFL[filterX].CFDGAFLP0r, CANFD_CFDGAFLP0r_GAFLRMV_Msk, valid);
}

/**
  * @brief    Get Global Acceptance Filter List RX Message Buffer Valid
  * @rmtoll   CFDGAFLP0r    GAFLRMV    FL_CANFD_Global_GetGAFLRxMBValid
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_SINGLE_RXMB_INVALID
  *           @arg @ref FL_CANFD_GAFL_SINGLE_RXMB_VALID
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGAFLRxMBValid(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLP0r, CANFD_CFDGAFLP0r_GAFLRMV_Msk));
}

/**
  * @brief    Set Global Acceptance Filter List RX Message Buffer Direction Pointer
  * @rmtoll   CFDGAFLP0r    GAFLRMDP    FL_CANFD_Global_WriteGAFLRxMBDirectionPointer
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    number 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGAFLRxMBDirectionPointer(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t number)
{
    MODIFY_REG(CANFDx->CFDGAFL[filterX].CFDGAFLP0r, (0x1fU << 8U), (number << 8U));
}

/**
  * @brief    Get Global Acceptance Filter List RX Message Buffer Direction Pointer
  * @rmtoll   CFDGAFLP0r    GAFLRMDP    FL_CANFD_Global_ReadGAFLRxMBDirectionPointer
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGAFLRxMBDirectionPointer(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLP0r, (0x1fU << 8U)) >> 8U);
}

/**
  * @brief    Set Global Acceptance Filter List Information Label 0
  * @rmtoll   CFDGAFLP0r    GAFLIFL0    FL_CANFD_Global_SetGAFLInfoLabel0
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    label This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_INFO_LABEL0_0
  *           @arg @ref FL_CANFD_GAFL_INFO_LABEL0_1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGAFLInfoLabel0(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t label)
{
    MODIFY_REG(CANFDx->CFDGAFL[filterX].CFDGAFLP0r, CANFD_CFDGAFLP0r_GAFLIFL0_Msk, label);
}

/**
  * @brief    Get Global Acceptance Filter List Information Label 0
  * @rmtoll   CFDGAFLP0r    GAFLIFL0    FL_CANFD_Global_GetGAFLInfoLabel0
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GAFL_INFO_LABEL0_0
  *           @arg @ref FL_CANFD_GAFL_INFO_LABEL0_1
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGAFLInfoLabel0(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLP0r, CANFD_CFDGAFLP0r_GAFLIFL0_Msk));
}

/**
  * @brief    Set Global Acceptance Filter List DLC Field
  * @rmtoll   CFDGAFLP0r    GAFLDLC    FL_CANFD_Global_WriteGAFLDLC
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGAFLDLC(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t length)
{
    MODIFY_REG(CANFDx->CFDGAFL[filterX].CFDGAFLP0r, (0xfU << 0U), (length << 0U));
}

/**
  * @brief    Get Global Acceptance Filter List DLC Field
  * @rmtoll   CFDGAFLP0r    GAFLDLC    FL_CANFD_Global_ReadGAFLDLC
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGAFLDLC(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLP0r, (0xfU << 0U)) >> 0U);
}

/**
  * @brief    Global Acceptance Filter List Common FIFO Reception enable 
  * @rmtoll   CFDGAFLP1r    GAFLFDPH    FL_CANFD_Global_Enable_GAFLCommonFIFOReception
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_GAFLCommonFIFOReception(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    SET_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLP1r, CANFD_CFDGAFLP1r_GAFLFDPH_Msk);
}

/**
  * @brief    Global Acceptance Filter List Common FIFO Reception enable status 
  * @rmtoll   CFDGAFLP1r    GAFLFDPH    FL_CANFD_Global_IsEnabled_GAFLCommonFIFOReception
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_GAFLCommonFIFOReception(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLP1r, CANFD_CFDGAFLP1r_GAFLFDPH_Msk) == CANFD_CFDGAFLP1r_GAFLFDPH_Msk);
}

/**
  * @brief    Global Acceptance Filter List Common FIFO Reception disable 
  * @rmtoll   CFDGAFLP1r    GAFLFDPH    FL_CANFD_Global_Disable_GAFLCommonFIFOReception
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_GAFLCommonFIFOReception(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    CLEAR_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLP1r, CANFD_CFDGAFLP1r_GAFLFDPH_Msk);
}

/**
  * @brief    Global Acceptance Filter List RxFIFO Reception enable 
  * @rmtoll   CFDGAFLP1r    GAFLFDPL    FL_CANFD_Global_Enable_GAFLRxFIFOReception
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_GAFLRxFIFOReception(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t rxfifoX)
{
    SET_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLP1r, (CANFD_CFDGAFLP1r_GAFLFDPL_Msk << rxfifoX));
}

/**
  * @brief    Global Acceptance Filter List RxFIFO Reception enable status 
  * @rmtoll   CFDGAFLP1r    GAFLFDPL    FL_CANFD_Global_IsEnabled_GAFLRxFIFOReception
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_GAFLRxFIFOReception(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLP1r, (CANFD_CFDGAFLP1r_GAFLFDPL_Msk << rxfifoX)) == (CANFD_CFDGAFLP1r_GAFLFDPL_Msk << rxfifoX));
}

/**
  * @brief    Global Acceptance Filter List RxFIFO Reception disable 
  * @rmtoll   CFDGAFLP1r    GAFLFDPL    FL_CANFD_Global_Disable_GAFLRxFIFOReception
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_AFL_FILTER0
  *           @arg @ref FL_CANFD_AFL_FILTER1
  *           @arg @ref FL_CANFD_AFL_FILTER2
  *           @arg @ref FL_CANFD_AFL_FILTER3
  *           @arg @ref FL_CANFD_AFL_FILTER4
  *           @arg @ref FL_CANFD_AFL_FILTER5
  *           @arg @ref FL_CANFD_AFL_FILTER6
  *           @arg @ref FL_CANFD_AFL_FILTER7
  *           @arg @ref FL_CANFD_AFL_FILTER8
  *           @arg @ref FL_CANFD_AFL_FILTER9
  *           @arg @ref FL_CANFD_AFL_FILTER10
  *           @arg @ref FL_CANFD_AFL_FILTER11
  *           @arg @ref FL_CANFD_AFL_FILTER12
  *           @arg @ref FL_CANFD_AFL_FILTER13
  *           @arg @ref FL_CANFD_AFL_FILTER14
  *           @arg @ref FL_CANFD_AFL_FILTER15
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_GAFLRxFIFOReception(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t rxfifoX)
{
    CLEAR_BIT(CANFDx->CFDGAFL[filterX].CFDGAFLP1r, (CANFD_CFDGAFLP1r_GAFLFDPL_Msk << rxfifoX));
}

/**
  * @brief    Set Global Reception Message Buffer Payload Data Size
  * @rmtoll   CFDRMNB    RMPLS    FL_CANFD_Global_SetRxMBPayloadDataSize
  * @param    CANFDx CANFD instance
  * @param    size This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RMPLS_SIZE_8
  *           @arg @ref FL_CANFD_RMPLS_SIZE_12
  *           @arg @ref FL_CANFD_RMPLS_SIZE_16
  *           @arg @ref FL_CANFD_RMPLS_SIZE_20
  *           @arg @ref FL_CANFD_RMPLS_SIZE_24
  *           @arg @ref FL_CANFD_RMPLS_SIZE_32
  *           @arg @ref FL_CANFD_RMPLS_SIZE_48
  *           @arg @ref FL_CANFD_RMPLS_SIZE_64
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetRxMBPayloadDataSize(CANFD_COMMON_Type* CANFDx, uint32_t size)
{
    MODIFY_REG(CANFDx->CFDRMNB, CANFD_CFDRMNB_RMPLS_Msk, size);
}

/**
  * @brief    Get Global Reception Message Buffer Payload Data Size
  * @rmtoll   CFDRMNB    RMPLS    FL_CANFD_Global_GetRxMBPayloadDataSize
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_RMPLS_SIZE_8
  *           @arg @ref FL_CANFD_RMPLS_SIZE_12
  *           @arg @ref FL_CANFD_RMPLS_SIZE_16
  *           @arg @ref FL_CANFD_RMPLS_SIZE_20
  *           @arg @ref FL_CANFD_RMPLS_SIZE_24
  *           @arg @ref FL_CANFD_RMPLS_SIZE_32
  *           @arg @ref FL_CANFD_RMPLS_SIZE_48
  *           @arg @ref FL_CANFD_RMPLS_SIZE_64
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetRxMBPayloadDataSize(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRMNB, CANFD_CFDRMNB_RMPLS_Msk));
}

/**
  * @brief    Set Global Number of RX Message Buffers
  * @rmtoll   CFDRMNB    NRXMB    FL_CANFD_Global_WriteNumberOfRxMB
  * @param    CANFDx CANFD instance
  * @param    number 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteNumberOfRxMB(CANFD_COMMON_Type* CANFDx, uint32_t number)
{
    MODIFY_REG(CANFDx->CFDRMNB, (0x3fU << 0U), (number << 0U));
}

/**
  * @brief    Get Global Number of RX Message Buffers
  * @rmtoll   CFDRMNB    NRXMB    FL_CANFD_Global_ReadNumberOfRxMB
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadNumberOfRxMB(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRMNB, (0x3fU << 0U)) >> 0U);
}

/**
  * @brief    Get Global RX Message Buffer New Data Status
  * @rmtoll   CFDRMND    RMNSu    FL_CANFD_Global_IsActiveFlag_RxMBNewData
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_RxMBNewData(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRMND, (CANFD_CFDRMND_RMNSu_Msk << rxmbX)) == (CANFD_CFDRMND_RMNSu_Msk << rxmbX));
}

/**
  * @brief    Clear Global RX Message Buffer New Data Status
  * @rmtoll   CFDRMND    RMNSu    FL_CANFD_Global_ClearFlag_RxMBNewData
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_ClearFlag_RxMBNewData(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    CLEAR_BIT(CANFDx->CFDRMND, (CANFD_CFDRMND_RMNSu_Msk << rxmbX));
}

/**
  * @brief    Set Global RX FIFO Interrupt Generation Counter Value
  * @rmtoll   CFDRFCCa    RFIGCV    FL_CANFD_Global_SetRxFIFOInterruptGenerationCounterValue
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @param    value This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RFIGCV_1P8_FULL
  *           @arg @ref FL_CANFD_RFIGCV_1P4_FULL
  *           @arg @ref FL_CANFD_RFIGCV_3P8_FULL
  *           @arg @ref FL_CANFD_RFIGCV_1P2_FULL
  *           @arg @ref FL_CANFD_RFIGCV_5P8_FULL
  *           @arg @ref FL_CANFD_RFIGCV_3P4_FULL
  *           @arg @ref FL_CANFD_RFIGCV_7P8_FULL
  *           @arg @ref FL_CANFD_RFIGCV_FULL
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetRxFIFOInterruptGenerationCounterValue(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX, uint32_t value)
{
    MODIFY_REG(CANFDx->CFDRFCC[rxfifoX], CANFD_CFDRFCCa_RFIGCV_Msk, value);
}

/**
  * @brief    Get Global RX FIFO Interrupt Generation Counter Value
  * @rmtoll   CFDRFCCa    RFIGCV    FL_CANFD_Global_GetRxFIFOInterruptGenerationCounterValue
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_RFIGCV_1P8_FULL
  *           @arg @ref FL_CANFD_RFIGCV_1P4_FULL
  *           @arg @ref FL_CANFD_RFIGCV_3P8_FULL
  *           @arg @ref FL_CANFD_RFIGCV_1P2_FULL
  *           @arg @ref FL_CANFD_RFIGCV_5P8_FULL
  *           @arg @ref FL_CANFD_RFIGCV_3P4_FULL
  *           @arg @ref FL_CANFD_RFIGCV_7P8_FULL
  *           @arg @ref FL_CANFD_RFIGCV_FULL
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetRxFIFOInterruptGenerationCounterValue(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRFCC[rxfifoX], CANFD_CFDRFCCa_RFIGCV_Msk));
}

/**
  * @brief    Set Global RX FIFO Interrupt Mode
  * @rmtoll   CFDRFCCa    RFIM    FL_CANFD_Global_SetRxFIFOInterruptMode
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RFIM_REACH_RFIGCV
  *           @arg @ref FL_CANFD_RFIM_EVERY_MESSAGE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetRxFIFOInterruptMode(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX, uint32_t mode)
{
    MODIFY_REG(CANFDx->CFDRFCC[rxfifoX], CANFD_CFDRFCCa_RFIM_Msk, mode);
}

/**
  * @brief    Get Global RX FIFO Interrupt Mode
  * @rmtoll   CFDRFCCa    RFIM    FL_CANFD_Global_GetRxFIFOInterruptMode
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_RFIM_REACH_RFIGCV
  *           @arg @ref FL_CANFD_RFIM_EVERY_MESSAGE
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetRxFIFOInterruptMode(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRFCC[rxfifoX], CANFD_CFDRFCCa_RFIM_Msk));
}

/**
  * @brief    Set Global RX FIFO Depth Configuration
  * @rmtoll   CFDRFCCa    RFDC    FL_CANFD_Global_SetRxFIFODepth
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @param    depth This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RFDC_DEPTH_0
  *           @arg @ref FL_CANFD_RFDC_DEPTH_4
  *           @arg @ref FL_CANFD_RFDC_DEPTH_8
  *           @arg @ref FL_CANFD_RFDC_DEPTH_16
  *           @arg @ref FL_CANFD_RFDC_DEPTH_32
  *           @arg @ref FL_CANFD_RFDC_DEPTH_48
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetRxFIFODepth(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX, uint32_t depth)
{
    MODIFY_REG(CANFDx->CFDRFCC[rxfifoX], CANFD_CFDRFCCa_RFDC_Msk, depth);
}

/**
  * @brief    Get Global RX FIFO Depth Configuration
  * @rmtoll   CFDRFCCa    RFDC    FL_CANFD_Global_GetRxFIFODepth
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_RFDC_DEPTH_0
  *           @arg @ref FL_CANFD_RFDC_DEPTH_4
  *           @arg @ref FL_CANFD_RFDC_DEPTH_8
  *           @arg @ref FL_CANFD_RFDC_DEPTH_16
  *           @arg @ref FL_CANFD_RFDC_DEPTH_32
  *           @arg @ref FL_CANFD_RFDC_DEPTH_48
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetRxFIFODepth(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRFCC[rxfifoX], CANFD_CFDRFCCa_RFDC_Msk));
}

/**
  * @brief    Set Global Rx FIFO Payload Data Size configuration
  * @rmtoll   CFDRFCCa    RFPLS    FL_CANFD_Global_SetRxFIFOPayloadDataSize
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @param    size This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RFPLS_SIZE_8
  *           @arg @ref FL_CANFD_RFPLS_SIZE_12
  *           @arg @ref FL_CANFD_RFPLS_SIZE_16
  *           @arg @ref FL_CANFD_RFPLS_SIZE_20
  *           @arg @ref FL_CANFD_RFPLS_SIZE_24
  *           @arg @ref FL_CANFD_RFPLS_SIZE_32
  *           @arg @ref FL_CANFD_RFPLS_SIZE_48
  *           @arg @ref FL_CANFD_RFPLS_SIZE_64
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetRxFIFOPayloadDataSize(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX, uint32_t size)
{
    MODIFY_REG(CANFDx->CFDRFCC[rxfifoX], CANFD_CFDRFCCa_RFPLS_Msk, size);
}

/**
  * @brief    Get Global Rx FIFO Payload Data Size configuration
  * @rmtoll   CFDRFCCa    RFPLS    FL_CANFD_Global_GetRxFIFOPayloadDataSize
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_RFPLS_SIZE_8
  *           @arg @ref FL_CANFD_RFPLS_SIZE_12
  *           @arg @ref FL_CANFD_RFPLS_SIZE_16
  *           @arg @ref FL_CANFD_RFPLS_SIZE_20
  *           @arg @ref FL_CANFD_RFPLS_SIZE_24
  *           @arg @ref FL_CANFD_RFPLS_SIZE_32
  *           @arg @ref FL_CANFD_RFPLS_SIZE_48
  *           @arg @ref FL_CANFD_RFPLS_SIZE_64
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetRxFIFOPayloadDataSize(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRFCC[rxfifoX], CANFD_CFDRFCCa_RFPLS_Msk));
}

/**
  * @brief    Global RX FIFO Interrupt enable 
  * @rmtoll   CFDRFCCa    RFIE    FL_CANFD_Global_EnableIT_RxFIFO
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_EnableIT_RxFIFO(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    SET_BIT(CANFDx->CFDRFCC[rxfifoX], CANFD_CFDRFCCa_RFIE_Msk);
}

/**
  * @brief    Global RX FIFO Interrupt enable status 
  * @rmtoll   CFDRFCCa    RFIE    FL_CANFD_Global_IsEnabledIT_RxFIFO
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabledIT_RxFIFO(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRFCC[rxfifoX], CANFD_CFDRFCCa_RFIE_Msk) == CANFD_CFDRFCCa_RFIE_Msk);
}

/**
  * @brief    Global RX FIFO Interrupt disable 
  * @rmtoll   CFDRFCCa    RFIE    FL_CANFD_Global_DisableIT_RxFIFO
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_DisableIT_RxFIFO(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    CLEAR_BIT(CANFDx->CFDRFCC[rxfifoX], CANFD_CFDRFCCa_RFIE_Msk);
}

/**
  * @brief    Global RX FIFO enable 
  * @rmtoll   CFDRFCCa    RFE    FL_CANFD_Global_Enable_RxFIFO
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_RxFIFO(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    SET_BIT(CANFDx->CFDRFCC[rxfifoX], CANFD_CFDRFCCa_RFE_Msk);
}

/**
  * @brief    Global RX FIFO enable status 
  * @rmtoll   CFDRFCCa    RFE    FL_CANFD_Global_IsEnabled_RxFIFO
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_RxFIFO(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRFCC[rxfifoX], CANFD_CFDRFCCa_RFE_Msk) == CANFD_CFDRFCCa_RFE_Msk);
}

/**
  * @brief    Global RX FIFO disable 
  * @rmtoll   CFDRFCCa    RFE    FL_CANFD_Global_Disable_RxFIFO
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_RxFIFO(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    CLEAR_BIT(CANFDx->CFDRFCC[rxfifoX], CANFD_CFDRFCCa_RFE_Msk);
}

/**
  * @brief    Get Global RX FIFO Message Count
  * @rmtoll   CFDRFSTSa    RFMC    FL_CANFD_Global_ReadRxFIFOMessageCount
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRxFIFOMessageCount(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRFSTS[rxfifoX], (0x3fU << 8U)) >> 8U);
}

/**
  * @brief    Get Global RX FIFO Interrupt Flag
  * @rmtoll   CFDRFSTSa    RFIF    FL_CANFD_Global_IsActiveFlag_RxFIFO
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_RxFIFO(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRFSTS[rxfifoX], CANFD_CFDRFSTSa_RFIF_Msk) == (CANFD_CFDRFSTSa_RFIF_Msk));
}

/**
  * @brief    Clear Global RX FIFO Interrupt Flag
  * @rmtoll   CFDRFSTSa    RFIF    FL_CANFD_Global_ClearFlag_RxFIFO
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_ClearFlag_RxFIFO(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    CLEAR_BIT(CANFDx->CFDRFSTS[rxfifoX], CANFD_CFDRFSTSa_RFIF_Msk);
}

/**
  * @brief    Get Global RX FIFO Message Lost Flag
  * @rmtoll   CFDRFSTSa    RFMLT    FL_CANFD_Global_IsActiveFlag_RxFIFOMessageLost
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_RxFIFOMessageLost(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRFSTS[rxfifoX], CANFD_CFDRFSTSa_RFMLT_Msk) == (CANFD_CFDRFSTSa_RFMLT_Msk));
}

/**
  * @brief    Clear Global RX FIFO Message Lost Flag
  * @rmtoll   CFDRFSTSa    RFMLT    FL_CANFD_Global_ClearFlag_RxFIFOMessageLost
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_ClearFlag_RxFIFOMessageLost(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    CLEAR_BIT(CANFDx->CFDRFSTS[rxfifoX], CANFD_CFDRFSTSa_RFMLT_Msk);
}

/**
  * @brief    Get Global RX FIFO Full
  * @rmtoll   CFDRFSTSa    RFFLL    FL_CANFD_Global_IsActiveFlag_RxFIFOFull
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_RxFIFOFull(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRFSTS[rxfifoX], CANFD_CFDRFSTSa_RFFLL_Msk) == (CANFD_CFDRFSTSa_RFFLL_Msk));
}

/**
  * @brief    Get Global RX FIFO Empty
  * @rmtoll   CFDRFSTSa    RFEMP    FL_CANFD_Global_IsActiveFlag_RxFIFOEmpty
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_RxFIFOEmpty(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRFSTS[rxfifoX], CANFD_CFDRFSTSa_RFEMP_Msk) == (CANFD_CFDRFSTSa_RFEMP_Msk));
}

/**
  * @brief    Set Global RX FIFO Pointer
  * @rmtoll   CFDRFPCTRa    RFPC    FL_CANFD_Global_WriteRxFIFOPointer
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @param    pointer 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteRxFIFOPointer(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX, uint32_t pointer)
{
    MODIFY_REG(CANFDx->CFDRFPCTR[rxfifoX], (0xffU << 0U), (pointer << 0U));
}

/**
  * @brief    Set Global Common FIFO Interval Transmission Time
  * @rmtoll   CFDCFCC    CFITT    FL_CANFD_Global_WriteCommonFIFOIntervalTransmissionTime
  * @param    CANFDx CANFD instance
  * @param    time 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteCommonFIFOIntervalTransmissionTime(CANFD_COMMON_Type* CANFDx, uint32_t time)
{
    MODIFY_REG(CANFDx->CFDCFCC, (0xffU << 24U), (time << 24U));
}

/**
  * @brief    Get Global Common FIFO Interval Transmission Time
  * @rmtoll   CFDCFCC    CFITT    FL_CANFD_Global_ReadCommonFIFOIntervalTransmissionTime
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadCommonFIFOIntervalTransmissionTime(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFCC, (0xffU << 24U)) >> 24U);
}

/**
  * @brief    Set Global Common FIFO Depth Configuration
  * @rmtoll   CFDCFCC    CFDC    FL_CANFD_Global_SetCommonFIFODepth
  * @param    CANFDx CANFD instance
  * @param    depth This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CFDC_DEPTH_0
  *           @arg @ref FL_CANFD_CFDC_DEPTH_4
  *           @arg @ref FL_CANFD_CFDC_DEPTH_8
  *           @arg @ref FL_CANFD_CFDC_DEPTH_16
  *           @arg @ref FL_CANFD_CFDC_DEPTH_32
  *           @arg @ref FL_CANFD_CFDC_DEPTH_48
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetCommonFIFODepth(CANFD_COMMON_Type* CANFDx, uint32_t depth)
{
    MODIFY_REG(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFDC_Msk, depth);
}

/**
  * @brief    Get Global Common FIFO Depth Configuration
  * @rmtoll   CFDCFCC    CFDC    FL_CANFD_Global_GetCommonFIFODepth
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CFDC_DEPTH_0
  *           @arg @ref FL_CANFD_CFDC_DEPTH_4
  *           @arg @ref FL_CANFD_CFDC_DEPTH_8
  *           @arg @ref FL_CANFD_CFDC_DEPTH_16
  *           @arg @ref FL_CANFD_CFDC_DEPTH_32
  *           @arg @ref FL_CANFD_CFDC_DEPTH_48
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetCommonFIFODepth(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFDC_Msk));
}

/**
  * @brief    Set Global Common FIFO TX Message Buffer Link
  * @rmtoll   CFDCFCC    CFTML    FL_CANFD_Global_SetCommonFIFOTxMBLink
  * @param    CANFDx CANFD instance
  * @param    number This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CFTML_TXMB0
  *           @arg @ref FL_CANFD_CFTML_TXMB1
  *           @arg @ref FL_CANFD_CFTML_TXMB2
  *           @arg @ref FL_CANFD_CFTML_TXMB3
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetCommonFIFOTxMBLink(CANFD_COMMON_Type* CANFDx, uint32_t number)
{
    MODIFY_REG(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFTML_Msk, number);
}

/**
  * @brief    Get Global Common FIFO TX Message Buffer Link
  * @rmtoll   CFDCFCC    CFTML    FL_CANFD_Global_GetCommonFIFOTxMBLink
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CFTML_TXMB0
  *           @arg @ref FL_CANFD_CFTML_TXMB1
  *           @arg @ref FL_CANFD_CFTML_TXMB2
  *           @arg @ref FL_CANFD_CFTML_TXMB3
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetCommonFIFOTxMBLink(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFTML_Msk));
}

/**
  * @brief    Set Global Common FIFO Interrupt Generation Counter Value
  * @rmtoll   CFDCFCC    CFIGCV    FL_CANFD_Global_SetCommonFIFOInterruptGenerationCounterValue
  * @param    CANFDx CANFD instance
  * @param    value This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CFIGCV_1P8_FULL
  *           @arg @ref FL_CANFD_CFIGCV_1P4_FULL
  *           @arg @ref FL_CANFD_CFIGCV_3P8_FULL
  *           @arg @ref FL_CANFD_CFIGCV_1P2_FULL
  *           @arg @ref FL_CANFD_CFIGCV_5P8_FULL
  *           @arg @ref FL_CANFD_CFIGCV_3P4_FULL
  *           @arg @ref FL_CANFD_CFIGCV_7P8_FULL
  *           @arg @ref FL_CANFD_CFIGCV_FULL
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetCommonFIFOInterruptGenerationCounterValue(CANFD_COMMON_Type* CANFDx, uint32_t value)
{
    MODIFY_REG(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFIGCV_Msk, value);
}

/**
  * @brief    Get Global Common FIFO Interrupt Generation Counter Value
  * @rmtoll   CFDCFCC    CFIGCV    FL_CANFD_Global_GetCommonFIFOInterruptGenerationCounterValue
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CFIGCV_1P8_FULL
  *           @arg @ref FL_CANFD_CFIGCV_1P4_FULL
  *           @arg @ref FL_CANFD_CFIGCV_3P8_FULL
  *           @arg @ref FL_CANFD_CFIGCV_1P2_FULL
  *           @arg @ref FL_CANFD_CFIGCV_5P8_FULL
  *           @arg @ref FL_CANFD_CFIGCV_3P4_FULL
  *           @arg @ref FL_CANFD_CFIGCV_7P8_FULL
  *           @arg @ref FL_CANFD_CFIGCV_FULL
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetCommonFIFOInterruptGenerationCounterValue(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFIGCV_Msk));
}

/**
  * @brief    Set Global Common FIFO Interrupt Mode
  * @rmtoll   CFDCFCC    CFIM    FL_CANFD_Global_SetCommonFIFOInterruptMode
  * @param    CANFDx CANFD instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CFIM_REACH_RFIGCV
  *           @arg @ref FL_CANFD_CFIM_EVERY_MESSAGE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetCommonFIFOInterruptMode(CANFD_COMMON_Type* CANFDx, uint32_t mode)
{
    MODIFY_REG(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFIM_Msk, mode);
}

/**
  * @brief    Get Global Common FIFO Interrupt Mode
  * @rmtoll   CFDCFCC    CFIM    FL_CANFD_Global_GetCommonFIFOInterruptMode
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CFIM_REACH_RFIGCV
  *           @arg @ref FL_CANFD_CFIM_EVERY_MESSAGE
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetCommonFIFOInterruptMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFIM_Msk));
}

/**
  * @brief    Set Global Common FIFO Interval Timer Resolution
  * @rmtoll   CFDCFCC    CFITR    FL_CANFD_Global_SetCommonFIFOIntervalTimerResolution
  * @param    CANFDx CANFD instance
  * @param    resolution This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CFITR_REF_CLOCK_MUL_1
  *           @arg @ref FL_CANFD_CFITR_REF_CLOCK_MUL_10
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetCommonFIFOIntervalTimerResolution(CANFD_COMMON_Type* CANFDx, uint32_t resolution)
{
    MODIFY_REG(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFITR_Msk, resolution);
}

/**
  * @brief    Get Global Common FIFO Interval Timer Resolution
  * @rmtoll   CFDCFCC    CFITR    FL_CANFD_Global_GetCommonFIFOIntervalTimerResolution
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CFITR_REF_CLOCK_MUL_1
  *           @arg @ref FL_CANFD_CFITR_REF_CLOCK_MUL_10
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetCommonFIFOIntervalTimerResolution(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFITR_Msk));
}

/**
  * @brief    Set Global Common FIFO Interval Timer Source Select
  * @rmtoll   CFDCFCC    CFITSS    FL_CANFD_Global_SetCommonFIFOIntervalTimerSource
  * @param    CANFDx CANFD instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CFITSS_REF_CLOCK
  *           @arg @ref FL_CANFD_CFITSS_BIT_CLOCK
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetCommonFIFOIntervalTimerSource(CANFD_COMMON_Type* CANFDx, uint32_t source)
{
    MODIFY_REG(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFITSS_Msk, source);
}

/**
  * @brief    Get Global Common FIFO Interval Timer Source Select
  * @rmtoll   CFDCFCC    CFITSS    FL_CANFD_Global_GetCommonFIFOIntervalTimerSource
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CFITSS_REF_CLOCK
  *           @arg @ref FL_CANFD_CFITSS_BIT_CLOCK
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetCommonFIFOIntervalTimerSource(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFITSS_Msk));
}

/**
  * @brief    Set Global Common FIFO Mode
  * @rmtoll   CFDCFCC    CFM    FL_CANFD_Global_SetCommonFIFOMode
  * @param    CANFDx CANFD instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CFM_RX_FIFO
  *           @arg @ref FL_CANFD_CFM_TX_FIFO
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetCommonFIFOMode(CANFD_COMMON_Type* CANFDx, uint32_t mode)
{
    MODIFY_REG(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFM_Msk, mode);
}

/**
  * @brief    Get Global Common FIFO Mode
  * @rmtoll   CFDCFCC    CFM    FL_CANFD_Global_GetCommonFIFOMode
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CFM_RX_FIFO
  *           @arg @ref FL_CANFD_CFM_TX_FIFO
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetCommonFIFOMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFM_Msk));
}

/**
  * @brief    Set Global Common FIFO Payload Data Size configuration
  * @rmtoll   CFDCFCC    CFPLS    FL_CANFD_Global_SetCommonFIFOPayloadDataSize
  * @param    CANFDx CANFD instance
  * @param    size This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CFPLS_SIZE_8
  *           @arg @ref FL_CANFD_CFPLS_SIZE_12
  *           @arg @ref FL_CANFD_CFPLS_SIZE_16
  *           @arg @ref FL_CANFD_CFPLS_SIZE_20
  *           @arg @ref FL_CANFD_CFPLS_SIZE_24
  *           @arg @ref FL_CANFD_CFPLS_SIZE_32
  *           @arg @ref FL_CANFD_CFPLS_SIZE_48
  *           @arg @ref FL_CANFD_CFPLS_SIZE_64
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetCommonFIFOPayloadDataSize(CANFD_COMMON_Type* CANFDx, uint32_t size)
{
    MODIFY_REG(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFPLS_Msk, size);
}

/**
  * @brief    Get Global Common FIFO Payload Data Size configuration
  * @rmtoll   CFDCFCC    CFPLS    FL_CANFD_Global_GetCommonFIFOPayloadDataSize
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CFPLS_SIZE_8
  *           @arg @ref FL_CANFD_CFPLS_SIZE_12
  *           @arg @ref FL_CANFD_CFPLS_SIZE_16
  *           @arg @ref FL_CANFD_CFPLS_SIZE_20
  *           @arg @ref FL_CANFD_CFPLS_SIZE_24
  *           @arg @ref FL_CANFD_CFPLS_SIZE_32
  *           @arg @ref FL_CANFD_CFPLS_SIZE_48
  *           @arg @ref FL_CANFD_CFPLS_SIZE_64
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetCommonFIFOPayloadDataSize(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFPLS_Msk));
}

/**
  * @brief    Global Common FIFO TX Interrupt enable 
  * @rmtoll   CFDCFCC    CFTXIE    FL_CANFD_Global_EnableIT_CommonFIFOTx
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_EnableIT_CommonFIFOTx(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFTXIE_Msk);
}

/**
  * @brief    Global Common FIFO TX Interrupt enable status 
  * @rmtoll   CFDCFCC    CFTXIE    FL_CANFD_Global_IsEnabledIT_CommonFIFOTx
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabledIT_CommonFIFOTx(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFTXIE_Msk) == CANFD_CFDCFCC_CFTXIE_Msk);
}

/**
  * @brief    Global Common FIFO TX Interrupt disable 
  * @rmtoll   CFDCFCC    CFTXIE    FL_CANFD_Global_DisableIT_CommonFIFOTx
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_DisableIT_CommonFIFOTx(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFTXIE_Msk);
}

/**
  * @brief    Global Common FIFO RX Interrupt enable 
  * @rmtoll   CFDCFCC    CFRXIE    FL_CANFD_Global_EnableIT_CommonFIFORx
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_EnableIT_CommonFIFORx(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFRXIE_Msk);
}

/**
  * @brief    Global Common FIFO RX Interrupt enable status 
  * @rmtoll   CFDCFCC    CFRXIE    FL_CANFD_Global_IsEnabledIT_CommonFIFORx
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabledIT_CommonFIFORx(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFRXIE_Msk) == CANFD_CFDCFCC_CFRXIE_Msk);
}

/**
  * @brief    Global Common FIFO RX Interrupt disable 
  * @rmtoll   CFDCFCC    CFRXIE    FL_CANFD_Global_DisableIT_CommonFIFORx
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_DisableIT_CommonFIFORx(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFRXIE_Msk);
}

/**
  * @brief    Global Common FIFO enable 
  * @rmtoll   CFDCFCC    CFE    FL_CANFD_Global_Enable_CommonFIFO
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_CommonFIFO(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFE_Msk);
}

/**
  * @brief    Global Common FIFO enable status 
  * @rmtoll   CFDCFCC    CFE    FL_CANFD_Global_IsEnabled_CommonFIFO
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_CommonFIFO(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFE_Msk) == CANFD_CFDCFCC_CFE_Msk);
}

/**
  * @brief    Global Common FIFO disable 
  * @rmtoll   CFDCFCC    CFE    FL_CANFD_Global_Disable_CommonFIFO
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_CommonFIFO(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDCFCC, CANFD_CFDCFCC_CFE_Msk);
}

/**
  * @brief    Get Global Common FIFO Message Count
  * @rmtoll   CFDCFSTS    CFMC    FL_CANFD_Global_ReadCommonFIFOMessageCount
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadCommonFIFOMessageCount(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFSTS, (0x3fU << 8U)) >> 8U);
}

/**
  * @brief    Get Global Common  FIFO TX Interrupt Flag
  * @rmtoll   CFDCFSTS    CFTXIF    FL_CANFD_Global_IsActiveFlag_CommonFIFOTx
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_CommonFIFOTx(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFSTS, CANFD_CFDCFSTS_CFTXIF_Msk) == (CANFD_CFDCFSTS_CFTXIF_Msk));
}

/**
  * @brief    Clear Global Common FIFO TX Interrupt Flag
  * @rmtoll   CFDCFSTS    CFTXIF    FL_CANFD_Global_ClearFlag_CommonFIFOTx
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_ClearFlag_CommonFIFOTx(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDCFSTS, CANFD_CFDCFSTS_CFTXIF_Msk);
}

/**
  * @brief    Get Global Common  FIFO RX Interrupt Flag
  * @rmtoll   CFDCFSTS    CFRXIF    FL_CANFD_Global_IsActiveFlag_CommonFIFORx
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_CommonFIFORx(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFSTS, CANFD_CFDCFSTS_CFRXIF_Msk) == (CANFD_CFDCFSTS_CFRXIF_Msk));
}

/**
  * @brief    Clear Global Common FIFO RX Interrupt Flag
  * @rmtoll   CFDCFSTS    CFRXIF    FL_CANFD_Global_ClearFlag_CommonFIFORx
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_ClearFlag_CommonFIFORx(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDCFSTS, CANFD_CFDCFSTS_CFRXIF_Msk);
}

/**
  * @brief    Get Global Common FIFO Message Lost Flag
  * @rmtoll   CFDCFSTS    CFMLT    FL_CANFD_Global_IsActiveFlag_CommonFIFOMessageLoast
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_CommonFIFOMessageLoast(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFSTS, CANFD_CFDCFSTS_CFMLT_Msk) == (CANFD_CFDCFSTS_CFMLT_Msk));
}

/**
  * @brief    Clear Global Common FIFO Message Lost Flag
  * @rmtoll   CFDCFSTS    CFMLT    FL_CANFD_Global_ClearFlag_CommonFIFOMessageLoast
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_ClearFlag_CommonFIFOMessageLoast(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDCFSTS, CANFD_CFDCFSTS_CFMLT_Msk);
}

/**
  * @brief    Get Global Common FIFO Full
  * @rmtoll   CFDCFSTS    CFFLL    FL_CANFD_Global_IsActiveFlag_CommonFIFOFull
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_CommonFIFOFull(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFSTS, CANFD_CFDCFSTS_CFFLL_Msk) == (CANFD_CFDCFSTS_CFFLL_Msk));
}

/**
  * @brief    Get Global Common FIFO Empty
  * @rmtoll   CFDCFSTS    CFEMP    FL_CANFD_Global_IsActiveFlag_CommonFIFOEmpty
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_CommonFIFOEmpty(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDCFSTS, CANFD_CFDCFSTS_CFEMP_Msk) == (CANFD_CFDCFSTS_CFEMP_Msk));
}

/**
  * @brief    Set Global Common FIFO Pointer
  * @rmtoll   CFDCFPCTR    CFPC    FL_CANFD_Global_WriteCommonFIFOPointer
  * @param    CANFDx CANFD instance
  * @param    pointer 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteCommonFIFOPointer(CANFD_COMMON_Type* CANFDx, uint32_t pointer)
{
    MODIFY_REG(CANFDx->CFDCFPCTR, (0xffU << 0U), (pointer << 0U));
}

/**
  * @brief    Get Global Total Common FIFO Empty Status
  * @rmtoll   CFDFESTS    CFEMP    FL_CANFD_Global_IsActiveFlag_TotalCommonFIFOEmpty
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TotalCommonFIFOEmpty(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDFESTS, CANFD_CFDFESTS_CFEMP_Msk) == (CANFD_CFDFESTS_CFEMP_Msk));
}

/**
  * @brief    Get Global Total RX FIF0 Empty Status
  * @rmtoll   CFDFESTS    RFxEMP    FL_CANFD_Global_IsActiveFlag_TotalRxFIFOEmpty
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TotalRxFIFOEmpty(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDFESTS, (CANFD_CFDFESTS_RFxEMP_Msk << rxfifoX)) == (CANFD_CFDFESTS_RFxEMP_Msk << rxfifoX));
}

/**
  * @brief    Get Global Total Common FIFO Full Status
  * @rmtoll   CFDFFSTS    CFFLL    FL_CANFD_Global_IsActiveFlag_TotalCommonFIFOFull
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TotalCommonFIFOFull(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDFFSTS, CANFD_CFDFFSTS_CFFLL_Msk) == (CANFD_CFDFFSTS_CFFLL_Msk));
}

/**
  * @brief    Get Global Total RX FIF0 Full Status
  * @rmtoll   CFDFFSTS    RFxFLL    FL_CANFD_Global_IsActiveFlag_TotalRxFIFOFull
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TotalRxFIFOFull(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDFFSTS, (CANFD_CFDFFSTS_RFxFLL_Msk << rxfifoX)) == ((CANFD_CFDFFSTS_RFxFLL_Msk << rxfifoX)));
}

/**
  * @brief    Get Global Total Common FIFO Msg Lost Status
  * @rmtoll   CFDFMSTS    CFMLT    FL_CANFD_Global_IsActiveFlag_TotalCommonFIFOMessageLost
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TotalCommonFIFOMessageLost(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDFMSTS, CANFD_CFDFMSTS_CFMLT_Msk) == (CANFD_CFDFMSTS_CFMLT_Msk));
}

/**
  * @brief    Get Global Total RX FIF0 Msg Lost Status
  * @rmtoll   CFDFMSTS    RFxMLT    FL_CANFD_Global_IsActiveFlag_TotalRxFIFOMessageLost
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TotalRxFIFOMessageLost(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDFMSTS, (CANFD_CFDFMSTS_RFxMLT_Msk  << rxfifoX)) == ((CANFD_CFDFMSTS_RFxMLT_Msk  << rxfifoX)));
}

/**
  * @brief    Get Global Total RX FIF0 Interrupt Flag Status
  * @rmtoll   CFDRFISTS    RFxIF    FL_CANFD_Global_IsActiveFlag_TotalRxFIFO
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TotalRxFIFO(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRFISTS, (CANFD_CFDRFISTS_RFxIF_Msk << rxfifoX)) == ((CANFD_CFDRFISTS_RFxIF_Msk << rxfifoX)));
}

/**
  * @brief    Get Global TX Message Buffer Oneshot Mode
  * @rmtoll   CFDTMCi    TMOM    FL_CANFD_Global_GetTxMBOneshotMode
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TXMODE_CONTINUOUS
  *           @arg @ref FL_CANFD_TXMODE_ONE_SHOT
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTxMBOneshotMode(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTMC[txmbX], CANFD_CFDTMCi_TMOM_Msk));
}

/**
  * @brief    Set Global TX Message Buffer Oneshot Mode
  * @rmtoll   CFDTMCi    TMOM    FL_CANFD_Global_SetTxMBOneshotMode
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMODE_CONTINUOUS
  *           @arg @ref FL_CANFD_TXMODE_ONE_SHOT
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetTxMBOneshotMode(CANFD_COMMON_Type* CANFDx, uint32_t txmbX, uint32_t mode)
{
    MODIFY_REG(CANFDx->CFDTMC[txmbX], CANFD_CFDTMCi_TMOM_Msk, mode);
}

/**
  * @brief    Global TX Message Buffer Transmission abort Request enable 
  * @rmtoll   CFDTMCi    TMTAR    FL_CANFD_Global_Enable_TxMBTxAbortRequest
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_TxMBTxAbortRequest(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    SET_BIT(CANFDx->CFDTMC[txmbX], CANFD_CFDTMCi_TMTAR_Msk);
}

/**
  * @brief    Global TX Message Buffer Transmission abort Request enable status 
  * @rmtoll   CFDTMCi    TMTAR    FL_CANFD_Global_IsEnabled_TxMBTxAbortRequest
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_TxMBTxAbortRequest(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTMC[txmbX], CANFD_CFDTMCi_TMTAR_Msk) == CANFD_CFDTMCi_TMTAR_Msk);
}

/**
  * @brief    Global TX Message Buffer Transmission abort Request disable 
  * @rmtoll   CFDTMCi    TMTAR    FL_CANFD_Global_Disable_TxMBTxAbortRequest
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_TxMBTxAbortRequest(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    CLEAR_BIT(CANFDx->CFDTMC[txmbX], CANFD_CFDTMCi_TMTAR_Msk);
}

/**
  * @brief    Global TX Message Buffer Transmission Request enable 
  * @rmtoll   CFDTMCi    TMTR    FL_CANFD_Global_Enable_TxMBTxRequest
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_TxMBTxRequest(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    SET_BIT(CANFDx->CFDTMC[txmbX], CANFD_CFDTMCi_TMTR_Msk);
}

/**
  * @brief    Global TX Message Buffer Transmission Request enable status 
  * @rmtoll   CFDTMCi    TMTR    FL_CANFD_Global_IsEnabled_TxMBTxRequest
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_TxMBTxRequest(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTMC[txmbX], CANFD_CFDTMCi_TMTR_Msk) == CANFD_CFDTMCi_TMTR_Msk);
}

/**
  * @brief    Global TX Message Buffer Transmission Request disable 
  * @rmtoll   CFDTMCi    TMTR    FL_CANFD_Global_Disable_TxMBTxRequest
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_TxMBTxRequest(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    CLEAR_BIT(CANFDx->CFDTMC[txmbX], CANFD_CFDTMCi_TMTR_Msk);
}

/**
  * @brief    Get Global TX Message Buffer Transmission abort Request Mirrored
  * @rmtoll   CFDTMSTSj    TMTARM    FL_CANFD_Global_IsActiveFlag_TxMBTxAbortRequestMirrored
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TxMBTxAbortRequestMirrored(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTMSTS[txmbX], CANFD_CFDTMSTSj_TMTARM_Msk) == (CANFD_CFDTMSTSj_TMTARM_Msk));
}

/**
  * @brief    Get Global TX Message Buffer Transmission Request Mirrored
  * @rmtoll   CFDTMSTSj    TMTRM    FL_CANFD_Global_IsActiveFlag_TxMBTxRequestMirrored
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TxMBTxRequestMirrored(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTMSTS[txmbX], CANFD_CFDTMSTSj_TMTRM_Msk) == (CANFD_CFDTMSTSj_TMTRM_Msk));
}

/**
  * @brief    Get Global TX Message Buffer Transmission Result Flag
  * @rmtoll   CFDTMSTSj    TMTRF    FL_CANFD_Global_GetTxMBTxResult
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TMTRF_NO_RESULT
  *           @arg @ref FL_CANFD_TMTRF_TX_ABORTED
  *           @arg @ref FL_CANFD_TMTRF_TX_SUCCESSFUL_WITHOUT_ABORT_REQUESTED
  *           @arg @ref FL_CANFD_TMTRF_TX_SUCCESSFUL_WITH_ABORT_REQUESTED
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTxMBTxResult(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTMSTS[txmbX], CANFD_CFDTMSTSj_TMTRF_Msk));
}

/**
  * @brief    Clear Global TX Message Buffer Transmission Result Flag
  * @rmtoll   CFDTMSTSj    TMTRF    FL_CANFD_Global_ClearFlag_TxMBTxResult
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_ClearFlag_TxMBTxResult(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    CLEAR_BIT(CANFDx->CFDTMSTS[txmbX], CANFD_CFDTMSTSj_TMTRF_Msk);
}

/**
  * @brief    Get Global TX Message Buffer Transmission Status
  * @rmtoll   CFDTMSTSj    TMTSTS    FL_CANFD_Global_IsActiveFlag_TxMBTxStatus
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TxMBTxStatus(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTMSTS[txmbX], CANFD_CFDTMSTSj_TMTSTS_Msk) == (CANFD_CFDTMSTSj_TMTSTS_Msk));
}

/**
  * @brief    Get Global TX Message Buffer Transmission Request Status
  * @rmtoll   CFDTMTRSTS    CFDTMTRSTSg    FL_CANFD_Global_IsActiveFlag_TotalTxMBTxRequestStatus
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TotalTxMBTxRequestStatus(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTMTRSTS, (CANFD_CFDTMTRSTS_CFDTMTRSTSg_Msk << txmbX)) == (CANFD_CFDTMTRSTS_CFDTMTRSTSg_Msk << txmbX));
}

/**
  * @brief    Get Global TX Message Buffer Transmission abort Request Status
  * @rmtoll   CFDTMTARSTS    CFDTMTARSTSg    FL_CANFD_Global_IsActiveFlag_TotalTxMBTxAbortRequestStatus
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TotalTxMBTxAbortRequestStatus(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTMTARSTS, (CANFD_CFDTMTARSTS_CFDTMTARSTSg_Msk << txmbX)) == (CANFD_CFDTMTARSTS_CFDTMTARSTSg_Msk << txmbX));
}

/**
  * @brief    Get Global TX Message Buffer Transmission Completion Status
  * @rmtoll   CFDTMTCSTS    CFDTMTCSTSg    FL_CANFD_Global_IsActiveFlag_TotalTxMBTxCompletionStatus
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TotalTxMBTxCompletionStatus(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTMTCSTS, (CANFD_CFDTMTCSTS_CFDTMTCSTSg_Msk << txmbX)) == ((CANFD_CFDTMTCSTS_CFDTMTCSTSg_Msk << txmbX)));
}

/**
  * @brief    Get Global TX Message Buffer Transmission abort Status
  * @rmtoll   CFDTMTASTS    CFDTMTASTSg    FL_CANFD_Global_IsActiveFlag_TotalTxMBTxAbortStatus
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TotalTxMBTxAbortStatus(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTMTASTS, (CANFD_CFDTMTASTS_CFDTMTASTSg_Msk << txmbX)) == ((CANFD_CFDTMTASTS_CFDTMTASTSg_Msk << txmbX)));
}

/**
  * @brief    Global TX Message Buffer Interrupt Enable
  * @rmtoll   CFDTMIEC    TMIEg    FL_CANFD_Global_EnableIT_TxMB
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_EnableIT_TxMB(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    SET_BIT(CANFDx->CFDTMIEC, (CANFD_CFDTMIEC_TMIEg_Msk << txmbX));
}

/**
  * @brief    Global TX Message Buffer Interrupt  enable status 
  * @rmtoll   CFDTMIEC    TMIEg    FL_CANFD_Global_IsEnabledIT_TxMB
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabledIT_TxMB(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTMIEC, (CANFD_CFDTMIEC_TMIEg_Msk << txmbX)) == (CANFD_CFDTMIEC_TMIEg_Msk << txmbX));
}

/**
  * @brief    Global TX Message Buffer Interrupt disable 
  * @rmtoll   CFDTMIEC    TMIEg    FL_CANFD_Global_DisableIT_TxMB
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_DisableIT_TxMB(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    CLEAR_BIT(CANFDx->CFDTMIEC, (CANFD_CFDTMIEC_TMIEg_Msk << txmbX));
}

/**
  * @brief    Set Global TX Queue Depth Configuration
  * @rmtoll   CFDTXQCC    TXQDC    FL_CANFD_Global_SetTxQueueDepth
  * @param    CANFDx CANFD instance
  * @param    depth This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXQDC_DEPTH_0
  *           @arg @ref FL_CANFD_TXQDC_DEPTH_3
  *           @arg @ref FL_CANFD_TXQDC_DEPTH_4
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetTxQueueDepth(CANFD_COMMON_Type* CANFDx, uint32_t depth)
{
    MODIFY_REG(CANFDx->CFDTXQCC, CANFD_CFDTXQCC_TXQDC_Msk, depth);
}

/**
  * @brief    Get Global TX Queue Depth Configuration
  * @rmtoll   CFDTXQCC    TXQDC    FL_CANFD_Global_GetTxQueueDepth
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TXQDC_DEPTH_0
  *           @arg @ref FL_CANFD_TXQDC_DEPTH_3
  *           @arg @ref FL_CANFD_TXQDC_DEPTH_4
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTxQueueDepth(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTXQCC, CANFD_CFDTXQCC_TXQDC_Msk));
}

/**
  * @brief    Set Global TX Queue Interrupt Mode
  * @rmtoll   CFDTXQCC    TXQIM    FL_CANFD_Global_SetTxQueueInterruptMode
  * @param    CANFDx CANFD instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXQIM_LAST_MESSAGE_TRANSMITTED
  *           @arg @ref FL_CANFD_TXQIM_EVERY_TRANSMISSION
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetTxQueueInterruptMode(CANFD_COMMON_Type* CANFDx, uint32_t mode)
{
    MODIFY_REG(CANFDx->CFDTXQCC, CANFD_CFDTXQCC_TXQIM_Msk, mode);
}

/**
  * @brief    Get Global TX Queue Interrupt Mode
  * @rmtoll   CFDTXQCC    TXQIM    FL_CANFD_Global_GetTxQueueInterruptMode
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TXQIM_LAST_MESSAGE_TRANSMITTED
  *           @arg @ref FL_CANFD_TXQIM_EVERY_TRANSMISSION
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTxQueueInterruptMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTXQCC, CANFD_CFDTXQCC_TXQIM_Msk));
}

/**
  * @brief    Global TX Queue TX Interrupt Enable
  * @rmtoll   CFDTXQCC    TXQTXIE    FL_CANFD_Global_EnableIT_TxQueueTx
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_EnableIT_TxQueueTx(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDTXQCC, CANFD_CFDTXQCC_TXQTXIE_Msk);
}

/**
  * @brief    Global TX Queue TX Interrupt enable status 
  * @rmtoll   CFDTXQCC    TXQTXIE    FL_CANFD_Global_IsEnabledIT_TxQueueTx
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabledIT_TxQueueTx(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTXQCC, CANFD_CFDTXQCC_TXQTXIE_Msk) == CANFD_CFDTXQCC_TXQTXIE_Msk);
}

/**
  * @brief    Global TX Queue TX Interrupt disable 
  * @rmtoll   CFDTXQCC    TXQTXIE    FL_CANFD_Global_DisableIT_TxQueueTx
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_DisableIT_TxQueueTx(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDTXQCC, CANFD_CFDTXQCC_TXQTXIE_Msk);
}

/**
  * @brief    Global TX Queue Enable
  * @rmtoll   CFDTXQCC    TXQE    FL_CANFD_Global_Enable_TxQueue
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_TxQueue(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDTXQCC, CANFD_CFDTXQCC_TXQE_Msk);
}

/**
  * @brief    Global TX Queue Enable status 
  * @rmtoll   CFDTXQCC    TXQE    FL_CANFD_Global_IsEnabled_TxQueue
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_TxQueue(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTXQCC, CANFD_CFDTXQCC_TXQE_Msk) == CANFD_CFDTXQCC_TXQE_Msk);
}

/**
  * @brief    Global TX Queue disable 
  * @rmtoll   CFDTXQCC    TXQE    FL_CANFD_Global_Disable_TxQueue
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_TxQueue(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDTXQCC, CANFD_CFDTXQCC_TXQE_Msk);
}

/**
  * @brief    Get Global TX Queue Message Count
  * @rmtoll   CFDTXQSTS    TXQMC    FL_CANFD_Global_ReadTxQueueMessageCount
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadTxQueueMessageCount(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTXQSTS, (0x7U << 8U)) >> 8U);
}

/**
  * @brief    Get Global TX Queue TX Interrupt Flag
  * @rmtoll   CFDTXQSTS    TXQTXIF    FL_CANFD_Global_IsActiveFlag_TxQueueTx
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TxQueueTx(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTXQSTS, CANFD_CFDTXQSTS_TXQTXIF_Msk) == (CANFD_CFDTXQSTS_TXQTXIF_Msk));
}

/**
  * @brief    Clear Global TX Queue TX Interrupt Flag
  * @rmtoll   CFDTXQSTS    TXQTXIF    FL_CANFD_Global_ClearFlag_TxQueueTx
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_ClearFlag_TxQueueTx(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDTXQSTS, CANFD_CFDTXQSTS_TXQTXIF_Msk);
}

/**
  * @brief    Get Global TX Queue Full
  * @rmtoll   CFDTXQSTS    TXQFLL    FL_CANFD_Global_IsActiveFlag_TxQueueFull
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TxQueueFull(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTXQSTS, CANFD_CFDTXQSTS_TXQFLL_Msk) == (CANFD_CFDTXQSTS_TXQFLL_Msk));
}

/**
  * @brief    Get Global TX Queue Empty
  * @rmtoll   CFDTXQSTS    TXQEMP    FL_CANFD_Global_IsActiveFlag_TxQueueEmpty
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TxQueueEmpty(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTXQSTS, CANFD_CFDTXQSTS_TXQEMP_Msk) == (CANFD_CFDTXQSTS_TXQEMP_Msk));
}

/**
  * @brief    Set Global TX Queue Pointer
  * @rmtoll   CFDTXQPCTR    TXQPC    FL_CANFD_Global_WriteTxQueuePointer
  * @param    CANFDx CANFD instance
  * @param    pointer 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteTxQueuePointer(CANFD_COMMON_Type* CANFDx, uint32_t pointer)
{
    MODIFY_REG(CANFDx->CFDTXQPCTR, (0xffU << 0U), (pointer << 0U));
}

/**
  * @brief    Global TX History List Dedicated TX Enable
  * @rmtoll   CFDTHLCC    THLDTE    FL_CANFD_Global_Enable_TxHistoryListDedicatedTx
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_TxHistoryListDedicatedTx(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDTHLCC, CANFD_CFDTHLCC_THLDTE_Msk);
}

/**
  * @brief    Global TX History List Dedicated TX Enable status 
  * @rmtoll   CFDTHLCC    THLDTE    FL_CANFD_Global_IsEnabled_TxHistoryListDedicatedTx
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_TxHistoryListDedicatedTx(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTHLCC, CANFD_CFDTHLCC_THLDTE_Msk) == CANFD_CFDTHLCC_THLDTE_Msk);
}

/**
  * @brief    Global TX History List Dedicated TX disable 
  * @rmtoll   CFDTHLCC    THLDTE    FL_CANFD_Global_Disable_TxHistoryListDedicatedTx
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_TxHistoryListDedicatedTx(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDTHLCC, CANFD_CFDTHLCC_THLDTE_Msk);
}

/**
  * @brief    Set Global TX History List Interrupt Mode
  * @rmtoll   CFDTHLCC    THLIM    FL_CANFD_Global_SetTxHistoryListInterruptMode
  * @param    CANFDx CANFD instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_THLIM_REACH_3P4_DEPTH
  *           @arg @ref FL_CANFD_THLIM_EVERY_TRANSMISSION
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetTxHistoryListInterruptMode(CANFD_COMMON_Type* CANFDx, uint32_t mode)
{
    MODIFY_REG(CANFDx->CFDTHLCC, CANFD_CFDTHLCC_THLIM_Msk, mode);
}

/**
  * @brief    Get Global TX History List Interrupt Mode
  * @rmtoll   CFDTHLCC    THLIM    FL_CANFD_Global_GetTxHistoryListInterruptMode
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_THLIM_REACH_3P4_DEPTH
  *           @arg @ref FL_CANFD_THLIM_EVERY_TRANSMISSION
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTxHistoryListInterruptMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTHLCC, CANFD_CFDTHLCC_THLIM_Msk));
}

/**
  * @brief    Global TX History List Interrupt Enable
  * @rmtoll   CFDTHLCC    THLIE    FL_CANFD_Global_EnableIT_TxHistoryList
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_EnableIT_TxHistoryList(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDTHLCC, CANFD_CFDTHLCC_THLIE_Msk);
}

/**
  * @brief    Global TX History List Interrupt enable status 
  * @rmtoll   CFDTHLCC    THLIE    FL_CANFD_Global_IsEnabledIT_TxHistoryList
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabledIT_TxHistoryList(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTHLCC, CANFD_CFDTHLCC_THLIE_Msk) == CANFD_CFDTHLCC_THLIE_Msk);
}

/**
  * @brief    Global TX History List Interrupt disable 
  * @rmtoll   CFDTHLCC    THLIE    FL_CANFD_Global_DisableIT_TxHistoryList
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_DisableIT_TxHistoryList(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDTHLCC, CANFD_CFDTHLCC_THLIE_Msk);
}

/**
  * @brief    Global TX History List Enable
  * @rmtoll   CFDTHLCC    THLE    FL_CANFD_Global_Enable_TxHistoryList
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_TxHistoryList(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDTHLCC, CANFD_CFDTHLCC_THLE_Msk);
}

/**
  * @brief    Global TX History List Enable Status 
  * @rmtoll   CFDTHLCC    THLE    FL_CANFD_Global_IsEnabled_TxHistoryList
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_TxHistoryList(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTHLCC, CANFD_CFDTHLCC_THLE_Msk) == CANFD_CFDTHLCC_THLE_Msk);
}

/**
  * @brief    Global TX History List disable 
  * @rmtoll   CFDTHLCC    THLE    FL_CANFD_Global_Disable_TxHistoryList
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_TxHistoryList(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDTHLCC, CANFD_CFDTHLCC_THLE_Msk);
}

/**
  * @brief    Get Global TX History List Message Count
  * @rmtoll   CFDTHLSTS    THLMC    FL_CANFD_Global_ReadTxHistoryListMessageCount
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadTxHistoryListMessageCount(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTHLSTS, (0xfU << 8U)) >> 8U);
}

/**
  * @brief    Clear Global TX History List Interrupt Flag
  * @rmtoll   CFDTHLSTS    THLIF    FL_CANFD_Global_ClearFlag_TxHistoryList
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_ClearFlag_TxHistoryList(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDTHLSTS, CANFD_CFDTHLSTS_THLIF_Msk);
}

/**
  * @brief    Get Global TX History List Entry Lost Flag
  * @rmtoll   CFDTHLSTS    THLELT    FL_CANFD_Global_IsActiveFlag_TxHistoryListEntryLost
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TxHistoryListEntryLost(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTHLSTS, CANFD_CFDTHLSTS_THLELT_Msk) == (CANFD_CFDTHLSTS_THLELT_Msk));
}

/**
  * @brief    Clear Global TX History List Entry Lost Flag
  * @rmtoll   CFDTHLSTS    THLELT    FL_CANFD_Global_ClearFlag_TxHistoryListEntryLost
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_ClearFlag_TxHistoryListEntryLost(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDTHLSTS, CANFD_CFDTHLSTS_THLELT_Msk);
}

/**
  * @brief    Get Global TX History List Full
  * @rmtoll   CFDTHLSTS    THLFLL    FL_CANFD_Global_IsActiveFlag_TxHistoryListFull
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TxHistoryListFull(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTHLSTS, CANFD_CFDTHLSTS_THLFLL_Msk) == (CANFD_CFDTHLSTS_THLFLL_Msk));
}

/**
  * @brief    Get Global TX History List Empty
  * @rmtoll   CFDTHLSTS    THLEMP    FL_CANFD_Global_IsActiveFlag_TxHistoryListEmpty
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_TxHistoryListEmpty(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDTHLSTS, CANFD_CFDTHLSTS_THLEMP_Msk) == (CANFD_CFDTHLSTS_THLEMP_Msk));
}

/**
  * @brief    Get Global TX History List Transmit Timestamp
  * @rmtoll   CFDTHLACC0    TMTS    FL_CANFD_Global_ReadTxHistoryListTransmitTimestamp
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadTxHistoryListTransmitTimestamp(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFD_BUFFER[0].TX_HISTORY_LIST->CFDTHLACC0, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Get Global TX History List Buffer Number
  * @rmtoll   CFDTHLACC0    BN    FL_CANFD_Global_ReadTxHistoryListBufferNumber
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadTxHistoryListBufferNumber(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFD_BUFFER[0].TX_HISTORY_LIST->CFDTHLACC0, (0x3U << 3U)) >> 3U);
}

/**
  * @brief    Get Global TX History List Buffer Type
  * @rmtoll   CFDTHLACC0    BT    FL_CANFD_Global_GetTxHistoryListBufferType
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_BT_TX_MB
  *           @arg @ref FL_CANFD_BT_TX_FIFO
  *           @arg @ref FL_CANFD_BT_TX_QUEUE
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTxHistoryListBufferType(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFD_BUFFER[0].TX_HISTORY_LIST->CFDTHLACC0, CANFD_CFDTHLACC0_BT_Msk));
}

/**
  * @brief    Get Global TX History List Transmit Information Label
  * @rmtoll   CFDTHLACC1    TIFL    FL_CANFD_Global_ReadTxHistoryListTransmitInformationLabel
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadTxHistoryListTransmitInformationLabel(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFD_BUFFER[0].TX_HISTORY_LIST->CFDTHLACC1, (0x3U << 16U)) >> 16U);
}

/**
  * @brief    Get Global TX History List Transmit ID
  * @rmtoll   CFDTHLACC1    TID    FL_CANFD_Global_ReadTxHistoryListTransmitID
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadTxHistoryListTransmitID(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFD_BUFFER[0].TX_HISTORY_LIST->CFDTHLACC1, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Set Global TX History List Pointer
  * @rmtoll   CFDTHLPCTR    THLPC    FL_CANFD_Global_WriteTxHistoryListPointer
  * @param    CANFDx CANFD instance
  * @param    pointer 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteTxHistoryListPointer(CANFD_COMMON_Type* CANFDx, uint32_t pointer)
{
    MODIFY_REG(CANFDx->CFDTHLPCTR, (0xffU << 0U), (pointer << 0U));
}

/**
  * @brief    Set Global Reset Control Key
  * @rmtoll   CFDGRSTC    KEY    FL_CANFD_Global_WriteKeyOfReset
  * @param    CANFDx CANFD instance
  * @param    key 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteKeyOfReset(CANFD_COMMON_Type* CANFDx, uint32_t key)
{
    MODIFY_REG(CANFDx->CFDGRSTC, (0xffU << 8U), (key << 8U));
}

/**
  * @brief    Set Global Reset Control software reset 
  * @rmtoll   CFDGRSTC    SRST    FL_CANFD_Global_SetSoftwareReset
  * @param    CANx CAN instance
  * @param    reset This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_SRST_NO_RESET
  *           @arg @ref FL_CANFD_SRST_RESET
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetSoftwareReset(CANFD_COMMON_Type* CANx, uint32_t reset)
{
    MODIFY_REG(CANx->CFDGRSTC, CANFD_CFDGRSTC_SRST_Msk, reset);
}

/**
  * @brief    Get Global Reset Control software reset 
  * @rmtoll   CFDGRSTC    SRST    FL_CANFD_Global_GetSoftwareReset
  * @param    CANx CAN instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_SRST_NO_RESET
  *           @arg @ref FL_CANFD_SRST_RESET
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetSoftwareReset(CANFD_COMMON_Type* CANx)
{
    return (uint32_t)(READ_BIT(CANx->CFDGRSTC, CANFD_CFDGRSTC_SRST_Msk));
}

/**
  * @brief    CANFD Asycnchronous WakeUp Interrupt Enable
  * @rmtoll   CFDWKCR    CFD0WKIE    FL_CANFD_Global_Enable_CANFDWakeUpInterrupt
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_CANFDWakeUpInterrupt(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDWKCR, CANFD_CFDWKCR_CFD0WKIE_Msk);
}

/**
  * @brief    Get CANFD Asycnchronous WakeUp Interrupt Enable status
  * @rmtoll   CFDWKCR    CFD0WKIE    FL_CANFD_Global_IsEnabled_CANFDWakeUpInterrupt
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_CANFDWakeUpInterrupt(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDWKCR, CANFD_CFDWKCR_CFD0WKIE_Msk) == CANFD_CFDWKCR_CFD0WKIE_Msk);
}

/**
  * @brief    CANFD Asycnchronous WakeUp Interrupt Disable
  * @rmtoll   CFDWKCR    CFD0WKIE    FL_CANFD_Global_Disable_CANFDWakeUpInterrupt
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_CANFDWakeUpInterrupt(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDWKCR, CANFD_CFDWKCR_CFD0WKIE_Msk);
}

/**
  * @brief    CANFD Asycnchronous WakeUp Enable
  * @rmtoll   CFDWKCR    CFD0WKEN    FL_CANFD_Global_Enable_CANFDWakeUp
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_CANFDWakeUp(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDWKCR, CANFD_CFDWKCR_CFD0WKEN_Msk);
}

/**
  * @brief    Get CANFD Asycnchronous WakeUp Enable status
  * @rmtoll   CFDWKCR    CFD0WKEN    FL_CANFD_Global_IsEnabled_CANFDWakeUp
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_CANFDWakeUp(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDWKCR, CANFD_CFDWKCR_CFD0WKEN_Msk) == CANFD_CFDWKCR_CFD0WKEN_Msk);
}

/**
  * @brief    CANFD Asycnchronous WakeUp Disable
  * @rmtoll   CFDWKCR    CFD0WKEN    FL_CANFD_Global_Disable_CANFDWakeUp
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_CANFDWakeUp(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDWKCR, CANFD_CFDWKCR_CFD0WKEN_Msk);
}

/**
  * @brief    Get CANFD Asycnchronous WakeUp Interrupt Flag
  * @rmtoll   CFDWKSR    CFD0WKIF    FL_CANFD_IsActiveFlag_CANFDWakeUpInterrupt
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_IsActiveFlag_CANFDWakeUpInterrupt(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDWKSR, CANFD_CFDWKSR_CFD0WKIF_Msk) == (CANFD_CFDWKSR_CFD0WKIF_Msk));
}

/**
  * @brief    Clear CANFD Asycnchronous WakeUp Interrupt Flag
  * @rmtoll   CFDWKSR    CFD0WKIF    FL_CANFD_ClearFlag_CANFDWakeUpInterrupt
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_ClearFlag_CANFDWakeUpInterrupt(CANFD_COMMON_Type* CANFDx)
{
    WRITE_REG(CANFDx->CFDWKSR, CANFD_CFDWKSR_CFD0WKIF_Msk);
}

/**
  * @brief    Set Global RAM Test Mode Page Select
  * @rmtoll   CFDGTSTCFG    RTMPS    FL_CANFD_Global_WriteRAMTestModePageSelect
  * @param    CANFDx CANFD instance
  * @param    page 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteRAMTestModePageSelect(CANFD_COMMON_Type* CANFDx, uint32_t page)
{
    MODIFY_REG(CANFDx->CFDGTSTCFG, (0xfU << 16U), (page << 16U));
}

/**
  * @brief    Get Global RAM Test Mode Page Select
  * @rmtoll   CFDGTSTCFG    RTMPS    FL_CANFD_Global_ReadRAMTestModePageSelect
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRAMTestModePageSelect(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGTSTCFG, (0xfU << 16U)) >> 16U);
}

/**
  * @brief    Global RAM Test Mode Enable
  * @rmtoll   CFDGTSTCTR    RTME    FL_CANFD_Global_Enable_RAMTestMode
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_RAMTestMode(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDGTSTCTR, CANFD_CFDGTSTCTR_RTME_Msk);
}

/**
  * @brief    Global RAM Test Mode Enable status 
  * @rmtoll   CFDGTSTCTR    RTME    FL_CANFD_Global_IsEnabled_RAMTestMode
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_RAMTestMode(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGTSTCTR, CANFD_CFDGTSTCTR_RTME_Msk) == CANFD_CFDGTSTCTR_RTME_Msk);
}

/**
  * @brief    Global RAM Test Mode disable 
  * @rmtoll   CFDGTSTCTR    RTME    FL_CANFD_Global_Disable_RAMTestMode
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_RAMTestMode(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGTSTCTR, CANFD_CFDGTSTCTR_RTME_Msk);
}

/**
  * @brief    Set Global Timestamp capture configuration
  * @rmtoll   CFDGFDCFG    TSCCFG    FL_CANFD_Global_SetTimestampCaptureConfiguration
  * @param    CANFDx CANFD instance
  * @param    location This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TSCCFG_SOF
  *           @arg @ref FL_CANFD_TSCCFG_FRAME_VALID_INDICATION
  *           @arg @ref FL_CANFD_TSCCFG_RES
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetTimestampCaptureConfiguration(CANFD_COMMON_Type* CANFDx, uint32_t location)
{
    MODIFY_REG(CANFDx->CFDGFDCFG, CANFD_CFDGFDCFG_TSCCFG_Msk, location);
}

/**
  * @brief    Get Global Timestamp capture configuration
  * @rmtoll   CFDGFDCFG    TSCCFG    FL_CANFD_Global_GetTimestampCaptureConfiguration
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TSCCFG_SOF
  *           @arg @ref FL_CANFD_TSCCFG_FRAME_VALID_INDICATION
  *           @arg @ref FL_CANFD_TSCCFG_RES
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTimestampCaptureConfiguration(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGFDCFG, CANFD_CFDGFDCFG_TSCCFG_Msk));
}

/**
  * @brief    Global RES bit Protocol exception disable Configuration Enable
  * @rmtoll   CFDGFDCFG    RPED    FL_CANFD_Global_Enable_RESProtocolExceptionDisabled
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_RESProtocolExceptionDisabled(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDGFDCFG, CANFD_CFDGFDCFG_RPED_Msk);
}

/**
  * @brief    Global RES bit Protocol exception disable Configuration Enable status 
  * @rmtoll   CFDGFDCFG    RPED    FL_CANFD_Global_IsEnabled_RESProtocolExceptionDisabled
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_RESProtocolExceptionDisabled(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGFDCFG, CANFD_CFDGFDCFG_RPED_Msk) == CANFD_CFDGFDCFG_RPED_Msk);
}

/**
  * @brief    Global RES bit Protocol exception disable Configuration disable 
  * @rmtoll   CFDGFDCFG    RPED    FL_CANFD_Global_Disable_RESProtocolExceptionDisabled
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_RESProtocolExceptionDisabled(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGFDCFG, CANFD_CFDGFDCFG_RPED_Msk);
}

/**
  * @brief    Set Global Lock Key
  * @rmtoll   CFDGLOCKK    LOCK    FL_CANFD_Global_WriteLockKeyOfRAMTestMode
  * @param    CANFDx CANFD instance
  * @param    key 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteLockKeyOfRAMTestMode(CANFD_COMMON_Type* CANFDx, uint32_t key)
{
    MODIFY_REG(CANFDx->CFDGLOCKK, (0xffffU << 0U), (key << 0U));
}

/**
  * @brief    Set Global RAM Data Test Access
  * @rmtoll   CFDRPGACCk    RDTA    FL_CANFD_Global_WriteRAMDataTestAccess
  * @param    CANFDx CANFD instance
  * @param    dataX 
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteRAMDataTestAccess(CANFD_COMMON_Type* CANFDx, uint32_t dataX, uint32_t data)
{
    MODIFY_REG(CANFDx->CFDRPGACC[dataX], (0xffffffffU << 0U), (data << 0U));
}

/**
  * @brief    Get Global RAM Data Test Access
  * @rmtoll   CFDRPGACCk    RDTA    FL_CANFD_Global_ReadRAMDataTestAccess
  * @param    CANFDx CANFD instance
  * @param    dataX This parameter can be one of the following values:
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRAMDataTestAccess(CANFD_COMMON_Type* CANFDx, uint32_t dataX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRPGACC[dataX], (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Global Pretended Network Filter List Data Access Enable
  * @rmtoll   CFDGPFLECTR    PFLDAE    FL_CANFD_Global_Enable_GPFLDataAccess
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_GPFLDataAccess(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDGPFLECTR, CANFD_CFDGPFLECTR_PFLDAE_Msk);
}

/**
  * @brief    Global Pretended Network Filter List Data Access Enable status 
  * @rmtoll   CFDGPFLECTR    PFLDAE    FL_CANFD_Global_IsEnabled_GPFLDataAccess
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_GPFLDataAccess(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFLECTR, CANFD_CFDGPFLECTR_PFLDAE_Msk) == CANFD_CFDGPFLECTR_PFLDAE_Msk);
}

/**
  * @brief    Global Pretended Network Filter List Data Access disable 
  * @rmtoll   CFDGPFLECTR    PFLDAE    FL_CANFD_Global_Disable_GPFLDataAccess
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_GPFLDataAccess(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGPFLECTR, CANFD_CFDGPFLECTR_PFLDAE_Msk);
}

/**
  * @brief    Set Global Pretended Network Filter List Rule Number
  * @rmtoll   CFDGPFLCFG    RNC    FL_CANFD_Global_WriteGPFLRuleNumber
  * @param    CANFDx CANFD instance
  * @param    number 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGPFLRuleNumber(CANFD_COMMON_Type* CANFDx, uint32_t number)
{
    MODIFY_REG(CANFDx->CFDGPFLCFG, (0x3U << 24U), (number << 24U));
}

/**
  * @brief    Get Global Pretended Network Filter List Rule Number
  * @rmtoll   CFDGPFLCFG    RNC    FL_CANFD_Global_ReadGPFLRuleNumber
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGPFLRuleNumber(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFLCFG, (0x3U << 24U)) >> 24U);
}

/**
  * @brief    Set Global Pretended Network Filter List Entry IDE Field
  * @rmtoll   CFDGPFLIDs    GPFLIDE    FL_CANFD_Global_SetGPFLIDE
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    ide This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_IDE_STANDARD
  *           @arg @ref FL_CANFD_GPFL_IDE_EXTENDED
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGPFLIDE(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t ide)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLIDs, CANFD_CFDGPFLIDs_GPFLIDE_Msk, ide);
}

/**
  * @brief    Get Global Pretended Network Filter List Entry IDE Field
  * @rmtoll   CFDGPFLIDs    GPFLIDE    FL_CANFD_Global_GetGPFLIDE
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_IDE_STANDARD
  *           @arg @ref FL_CANFD_GPFL_IDE_EXTENDED
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGPFLIDE(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLIDs, CANFD_CFDGPFLIDs_GPFLIDE_Msk));
}

/**
  * @brief    Set Global Pretended Network Filter List Entry RTR Field
  * @rmtoll   CFDGPFLIDs    GPFLRTR    FL_CANFD_Global_SetGPFLRTR
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    rtr This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_RTR_DATA_FRAME
  *           @arg @ref FL_CANFD_GPFL_RTR_REMOTE_FRAME
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGPFLRTR(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t rtr)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLIDs, CANFD_CFDGPFLIDs_GPFLRTR_Msk, rtr);
}

/**
  * @brief    Get Global Pretended Network Filter List Entry RTR Field
  * @rmtoll   CFDGPFLIDs    GPFLRTR    FL_CANFD_Global_GetGPFLRTR
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_RTR_DATA_FRAME
  *           @arg @ref FL_CANFD_GPFL_RTR_REMOTE_FRAME
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGPFLRTR(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLIDs, CANFD_CFDGPFLIDs_GPFLRTR_Msk));
}

/**
  * @brief    Set Global Pretended Network Filter List Entry Loopback Configuration
  * @rmtoll   CFDGPFLIDs    GPFLLB    FL_CANFD_Global_SetGPFLLoopback
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    loopback This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_LB_RX
  *           @arg @ref FL_CANFD_GPFL_LB_TX
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGPFLLoopback(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t loopback)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLIDs, CANFD_CFDGPFLIDs_GPFLLB_Msk, loopback);
}

/**
  * @brief    Get Global Pretended Network Filter List Entry Loopback Configuration
  * @rmtoll   CFDGPFLIDs    GPFLLB    FL_CANFD_Global_GetGPFLLoopback
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_LB_RX
  *           @arg @ref FL_CANFD_GPFL_LB_TX
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGPFLLoopback(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLIDs, CANFD_CFDGPFLIDs_GPFLLB_Msk));
}

/**
  * @brief    Set Global Pretended Network Filter List Entry ID Field
  * @rmtoll   CFDGPFLIDs    GPFLID    FL_CANFD_Global_WriteGPFLID
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    id 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGPFLID(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t id)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLIDs, (0x1fffffffU << 0U), (id << 0U));
}

/**
  * @brief    Get Global Pretended Network Filter List Entry ID Field
  * @rmtoll   CFDGPFLIDs    GPFLID    FL_CANFD_Global_ReadGPFLID
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGPFLID(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLIDs, (0x1fffffffU << 0U)) >> 0U);
}

/**
  * @brief    Set Global Pretended Network Filter List IDE Mask 
  * @rmtoll   CFDGPFLMs    GPFLIDEM    FL_CANFD_Global_SetGPFLIDEMask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    idem This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_IDEM_NOT_CONSIDERED
  *           @arg @ref FL_CANFD_GPFL_IDEM_CONSIDERED
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGPFLIDEMask(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t idem)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLMs, CANFD_CFDGPFLMs_GPFLIDEM_Msk, idem);
}

/**
  * @brief    Get Global Pretended Network Filter List IDE Mask 
  * @rmtoll   CFDGPFLMs    GPFLIDEM    FL_CANFD_Global_GetGPFLIDEMask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_IDEM_NOT_CONSIDERED
  *           @arg @ref FL_CANFD_GPFL_IDEM_CONSIDERED
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGPFLIDEMask(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLMs, CANFD_CFDGPFLMs_GPFLIDEM_Msk));
}

/**
  * @brief    Set Global Pretended Network Filter List Entry RTR Mask
  * @rmtoll   CFDGPFLMs    GPFLRTRM    FL_CANFD_Global_SetGPFLRTRMask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    rtrm This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_RTRM_NOT_CONSIDERED
  *           @arg @ref FL_CANFD_GPFL_RTRM_CONSIDERED
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGPFLRTRMask(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t rtrm)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLMs, CANFD_CFDGPFLMs_GPFLRTRM_Msk, rtrm);
}

/**
  * @brief    Get Global Pretended Network Filter List Entry RTR Mask
  * @rmtoll   CFDGPFLMs    GPFLRTRM    FL_CANFD_Global_GetGPFLRTRMask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_RTRM_NOT_CONSIDERED
  *           @arg @ref FL_CANFD_GPFL_RTRM_CONSIDERED
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGPFLRTRMask(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLMs, CANFD_CFDGPFLMs_GPFLRTRM_Msk));
}

/**
  * @brief    Set Global Pretended Network Filter List Information Label 1
  * @rmtoll   CFDGPFLMs    GPFLIFL1    FL_CANFD_Global_SetGPFLInfoLabel1
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    label This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_INFO_LABEL1_0
  *           @arg @ref FL_CANFD_GPFL_INFO_LABEL1_1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGPFLInfoLabel1(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t label)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLMs, CANFD_CFDGPFLMs_GPFLIFL1_Msk, label);
}

/**
  * @brief    Get Global Pretended Network Filter List Information Label 1
  * @rmtoll   CFDGPFLMs    GPFLIFL1    FL_CANFD_Global_GetGPFLInfoLabel1
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_INFO_LABEL1_0
  *           @arg @ref FL_CANFD_GPFL_INFO_LABEL1_1
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGPFLInfoLabel1(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLMs, CANFD_CFDGPFLMs_GPFLIFL1_Msk));
}

/**
  * @brief    Set Global Pretended Network Filter List ID Mask Field
  * @rmtoll   CFDGPFLMs    GPFLIDM    FL_CANFD_Global_WriteGPFLIDMask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    idm 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGPFLIDMask(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t idm)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLMs, (0x1fffffffU << 0U), (idm << 0U));
}

/**
  * @brief    Get Global Pretended Network Filter List ID Mask Field
  * @rmtoll   CFDGPFLMs    GPFLIDM    FL_CANFD_Global_ReadGPFLIDMask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGPFLIDMask(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLMs, (0x1fffffffU << 0U)) >> 0U);
}

/**
  * @brief    Set Global Pretended Network Filter List Pointer Field
  * @rmtoll   CFDGPFLP0s    GPFLPTR    FL_CANFD_Global_WriteGPFLPointer
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    ptr 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGPFLPointer(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t ptr)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLP0s, (0xffffU << 16U), (ptr << 16U));
}

/**
  * @brief    Get Global Pretended Network Filter List Pointer Field
  * @rmtoll   CFDGPFLP0s    GPFLPTR    FL_CANFD_Global_ReadGPFLPointer
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGPFLPointer(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLP0s, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Set Global Pretended Network Filter List RX Message Buffer Valid
  * @rmtoll   CFDGPFLP0s    GPFLRMV    FL_CANFD_Global_SetGPFLRxMBValid
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    valid This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_SINGLE_RXMB_INVALID
  *           @arg @ref FL_CANFD_GPFL_SINGLE_RXMB_VALID
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGPFLRxMBValid(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t valid)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLP0s, CANFD_CFDGPFLP0s_GPFLRMV_Msk, valid);
}

/**
  * @brief    Get Global Pretended Network Filter List RX Message Buffer Valid
  * @rmtoll   CFDGPFLP0s    GPFLRMV    FL_CANFD_Global_GetGPFLRxMBValid
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_SINGLE_RXMB_INVALID
  *           @arg @ref FL_CANFD_GPFL_SINGLE_RXMB_VALID
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGPFLRxMBValid(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLP0s, CANFD_CFDGPFLP0s_GPFLRMV_Msk));
}

/**
  * @brief    Set Global Pretended Network Filter List RX Message Buffer Direction Pointer
  * @rmtoll   CFDGPFLP0s    GPFLRMDP    FL_CANFD_Global_WriteGPFLRxMBDirectionPointer
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    number 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGPFLRxMBDirectionPointer(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t number)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLP0s, (0x1fU << 8U), (number << 8U));
}

/**
  * @brief    Get Global Pretended Network Filter List RX Message Buffer Direction Pointer
  * @rmtoll   CFDGPFLP0s    GPFLRMDP    FL_CANFD_Global_ReadGPFLRxMBDirectionPointer
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGPFLRxMBDirectionPointer(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLP0s, (0x1fU << 8U)) >> 8U);
}

/**
  * @brief    Set Global Pretended Network Filter List Information Label 0
  * @rmtoll   CFDGPFLP0s    GPFLIFL0    FL_CANFD_Global_SetGPFLInfoLabel0
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    label This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_INFO_LABEL0_0
  *           @arg @ref FL_CANFD_GPFL_INFO_LABEL0_1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGPFLInfoLabel0(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t label)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLP0s, CANFD_CFDGPFLP0s_GPFLIFL0_Msk, label);
}

/**
  * @brief    Get Global Pretended Network Filter List Information Label 0
  * @rmtoll   CFDGPFLP0s    GPFLIFL0    FL_CANFD_Global_GetGPFLInfoLabel0
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GPFL_INFO_LABEL0_0
  *           @arg @ref FL_CANFD_GPFL_INFO_LABEL0_1
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGPFLInfoLabel0(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLP0s, CANFD_CFDGPFLP0s_GPFLIFL0_Msk));
}

/**
  * @brief    Set Global Pretended Network Filter List DLC Field
  * @rmtoll   CFDGPFLP0s    GPFLDLC    FL_CANFD_Global_WriteGPFLDLC
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGPFLDLC(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t length)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLP0s, (0xfU << 0U), (length << 0U));
}

/**
  * @brief    Get Global Pretended Network Filter List DLC Field
  * @rmtoll   CFDGPFLP0s    GPFLDLC    FL_CANFD_Global_ReadGPFLDLC
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGPFLDLC(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLP0s, (0xfU << 0U)) >> 0U);
}

/**
  * @brief    Global Pretended Network Filter List Common FIFO Reception enable 
  * @rmtoll   CFDGPFLP1s    GPFLFDPH    FL_CANFD_Global_Enable_GPFLCommonFIFOReception
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_GPFLCommonFIFOReception(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    SET_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLP1s, CANFD_CFDGPFLP1s_GPFLFDPH_Msk);
}

/**
  * @brief    Global Pretended Network Filter List Common FIFO Reception enable status 
  * @rmtoll   CFDGPFLP1s    GPFLFDPH    FL_CANFD_Global_IsEnabled_GPFLCommonFIFOReception
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_GPFLCommonFIFOReception(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLP1s, CANFD_CFDGPFLP1s_GPFLFDPH_Msk) == CANFD_CFDGPFLP1s_GPFLFDPH_Msk);
}

/**
  * @brief    Global Pretended Network Filter List Common FIFO Reception disable 
  * @rmtoll   CFDGPFLP1s    GPFLFDPH    FL_CANFD_Global_Disable_GPFLCommonFIFOReception
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_GPFLCommonFIFOReception(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    CLEAR_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLP1s, CANFD_CFDGPFLP1s_GPFLFDPH_Msk);
}

/**
  * @brief    Global Pretended Network Filter List RxFIFO Reception enable 
  * @rmtoll   CFDGPFLP1s    GPFLFDPL    FL_CANFD_Global_Enable_GPFLRxFIFOReception
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_GPFLRxFIFOReception(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t rxfifoX)
{
    SET_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLP1s, (CANFD_CFDGPFLP1s_GPFLFDPL_Msk << rxfifoX));
}

/**
  * @brief    Global Pretended Network Filter List RxFIFO Reception enable status 
  * @rmtoll   CFDGPFLP1s    GPFLFDPL    FL_CANFD_Global_IsEnabled_GPFLRxFIFOReception
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_GPFLRxFIFOReception(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLP1s, (CANFD_CFDGPFLP1s_GPFLFDPL_Msk << rxfifoX)) == (CANFD_CFDGPFLP1s_GPFLFDPL_Msk << rxfifoX));
}

/**
  * @brief    Global Pretended Network Filter List RxFIFO Reception disable 
  * @rmtoll   CFDGPFLP1s    GPFLFDPL    FL_CANFD_Global_Disable_GPFLRxFIFOReception
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_GPFLRxFIFOReception(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t rxfifoX)
{
    CLEAR_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLP1s, (CANFD_CFDGPFLP1s_GPFLFDPL_Msk << rxfifoX));
}

/**
  * @brief    Set Global Pretended Network filter conditions of the filters 0 and 1
  * @rmtoll   CFDGPFLPTs    GPFLANDOR    FL_CANFD_Global_SetGPFLConditionsOfFilters
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    condition This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GPFLANDOR_AND
  *           @arg @ref FL_CANFD_GPFLANDOR_OR
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGPFLConditionsOfFilters(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t condition)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLPTs, CANFD_CFDGPFLPTs_GPFLANDOR_Msk, condition);
}

/**
  * @brief    Get Global Pretended Network filter conditions of the filters 0 and 1
  * @rmtoll   CFDGPFLPTs    GPFLANDOR    FL_CANFD_Global_GetGPFLConditionsOfFilters
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GPFLANDOR_AND
  *           @arg @ref FL_CANFD_GPFLANDOR_OR
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGPFLConditionsOfFilters(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLPTs, CANFD_CFDGPFLPTs_GPFLANDOR_Msk));
}

/**
  * @brief    Set Global Pretended Network filter comparison conditions of the filter0
  * @rmtoll   CFDGPFLPTs    GPFLRANG0    FL_CANFD_Global_SetGPFLComparisonConditionsOfFilter0
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    range This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GPFLRANG0_MATCH
  *           @arg @ref FL_CANFD_GPFLRANG0_RANGE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGPFLComparisonConditionsOfFilter0(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t range)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLPTs, CANFD_CFDGPFLPTs_GPFLRANG0_Msk, range);
}

/**
  * @brief    Get Global Pretended Network filter comparison conditions of the filter0
  * @rmtoll   CFDGPFLPTs    GPFLRANG0    FL_CANFD_Global_GetGPFLComparisonConditionsOfFilter0
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GPFLRANG0_MATCH
  *           @arg @ref FL_CANFD_GPFLRANG0_RANGE
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGPFLComparisonConditionsOfFilter0(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLPTs, CANFD_CFDGPFLPTs_GPFLRANG0_Msk));
}

/**
  * @brief    Set Global Pretended Network filter conditions of upper/lower filter of the filter0
  * @rmtoll   CFDGPFLPTs    GPFLOUT0    FL_CANFD_Global_SetGPFLLimitConditionsOfFilter0
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    condition This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GPFLOUT0_WITHIN
  *           @arg @ref FL_CANFD_GPFLOUT0_OUTSIDE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGPFLLimitConditionsOfFilter0(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t condition)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLPTs, CANFD_CFDGPFLPTs_GPFLOUT0_Msk, condition);
}

/**
  * @brief    Get Global Pretended Network filter conditions of upper/lower filter of the filter0
  * @rmtoll   CFDGPFLPTs    GPFLOUT0    FL_CANFD_Global_GetGPFLLimitConditionsOfFilter0
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GPFLOUT0_WITHIN
  *           @arg @ref FL_CANFD_GPFLOUT0_OUTSIDE
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGPFLLimitConditionsOfFilter0(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLPTs, CANFD_CFDGPFLPTs_GPFLOUT0_Msk));
}

/**
  * @brief    Set Global Pretended Network filter offset value of the filter0
  * @rmtoll   CFDGPFLPTs    GPFLOFFSET0    FL_CANFD_Global_WriteGPFLOffsetOfFilter0
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    offset 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGPFLOffsetOfFilter0(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t offset)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLPTs, (0xfU << 16U), (offset << 16U));
}

/**
  * @brief    Get Global Pretended Network filter offset value of the filter0
  * @rmtoll   CFDGPFLPTs    GPFLOFFSET0    FL_CANFD_Global_ReadGPFLOffsetOfFilter0
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGPFLOffsetOfFilter0(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLPTs, (0xfU << 16U)) >> 16U);
}

/**
  * @brief    Set Global Pretended Network filter comparison conditions of the filter1
  * @rmtoll   CFDGPFLPTs    GPFLRANG1    FL_CANFD_Global_SetGPFLComparisonConditionsOfFilter1
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    range This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GPFLRANG1_MATCH
  *           @arg @ref FL_CANFD_GPFLRANG1_RANGE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGPFLComparisonConditionsOfFilter1(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t range)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLPTs, CANFD_CFDGPFLPTs_GPFLRANG1_Msk, range);
}

/**
  * @brief    Get Global Pretended Network filter comparison conditions of the filter1
  * @rmtoll   CFDGPFLPTs    GPFLRANG1    FL_CANFD_Global_GetGPFLComparisonConditionsOfFilter1
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GPFLRANG1_MATCH
  *           @arg @ref FL_CANFD_GPFLRANG1_RANGE
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGPFLComparisonConditionsOfFilter1(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLPTs, CANFD_CFDGPFLPTs_GPFLRANG1_Msk));
}

/**
  * @brief    Set Global Pretended Network filter conditions of upper/lower filter of the filter1
  * @rmtoll   CFDGPFLPTs    GPFLOUT1    FL_CANFD_Global_SetGPFLLimitConditionsOfFilter1
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    condition This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_GPFLOUT1_WITHIN
  *           @arg @ref FL_CANFD_GPFLOUT1_OUTSIDE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetGPFLLimitConditionsOfFilter1(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t condition)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLPTs, CANFD_CFDGPFLPTs_GPFLOUT1_Msk, condition);
}

/**
  * @brief    Get Global Pretended Network filter conditions of upper/lower filter of the filter1
  * @rmtoll   CFDGPFLPTs    GPFLOUT1    FL_CANFD_Global_GetGPFLLimitConditionsOfFilter1
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_GPFLOUT1_WITHIN
  *           @arg @ref FL_CANFD_GPFLOUT1_OUTSIDE
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetGPFLLimitConditionsOfFilter1(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLPTs, CANFD_CFDGPFLPTs_GPFLOUT1_Msk));
}

/**
  * @brief    Set Global Pretended Network filter offset value of the filter1
  * @rmtoll   CFDGPFLPTs    GPFLOFFSET1    FL_CANFD_Global_WriteGPFLOffsetOfFilter1
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    offset 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGPFLOffsetOfFilter1(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t offset)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLPTs, (0xfU << 0U), (offset << 0U));
}

/**
  * @brief    Get Global Pretended Network filter offset value of the filter1
  * @rmtoll   CFDGPFLPTs    GPFLOFFSET1    FL_CANFD_Global_ReadGPFLOffsetOfFilter1
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGPFLOffsetOfFilter1(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLPTs, (0xfU << 0U)) >> 0U);
}

/**
  * @brief    Set Global Pretended Network Filter List Filter data 0
  * @rmtoll   CFDGPFLPD0s    FDATA    FL_CANFD_Global_WriteGPFLFilterData0
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGPFLFilterData0(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t data)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLPD0s, (0xffffffffU << 0U), (data << 0U));
}

/**
  * @brief    Get Global Pretended Network Filter List Filter data 0
  * @rmtoll   CFDGPFLPD0s    FDATA    FL_CANFD_Global_ReadGPFLFilterData0
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGPFLFilterData0(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLPD0s, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Set Global Pretended Network Filter List Filter data 1
  * @rmtoll   CFDGPFLPD1s    FDATA    FL_CANFD_Global_WriteGPFLFilterData1
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGPFLFilterData1(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t data)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLPD1s, (0xffffffffU << 0U), (data << 0U));
}

/**
  * @brief    Get Global Pretended Network Filter List Filter data 1
  * @rmtoll   CFDGPFLPD1s    FDATA    FL_CANFD_Global_ReadGPFLFilterData1
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGPFLFilterData1(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLPD1s, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Set Global Pretended Network Filter List Filter data 0 mask field
  * @rmtoll   CFDGPFLPM0s    FMASK    FL_CANFD_Global_WriteGPFLFilterData0Mask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    mask 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGPFLFilterData0Mask(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t mask)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLPM0s, (0xffffffffU << 0U), (mask << 0U));
}

/**
  * @brief    Get Global Pretended Network Filter List Filter data 0 mask field
  * @rmtoll   CFDGPFLPM0s    FMASK    FL_CANFD_Global_ReadGPFLFilterData0Mask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGPFLFilterData0Mask(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLPM0s, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Set Global Pretended Network Filter List Filter data 1 mask field
  * @rmtoll   CFDGPFLPM1s    FMASK    FL_CANFD_Global_WriteGPFLFilterData1Mask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @param    mask 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGPFLFilterData1Mask(CANFD_COMMON_Type* CANFDx, uint32_t filterX, uint32_t mask)
{
    MODIFY_REG(CANFDx->CFDGPFL[filterX].CFDGPFLPM1s, (0xffffffffU << 0U), (mask << 0U));
}

/**
  * @brief    Get Global Pretended Network Filter List Filter data 1 mask field
  * @rmtoll   CFDGPFLPM1s    FMASK    FL_CANFD_Global_ReadGPFLFilterData1Mask
  * @param    CANFDx CANFD instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_PFL_FILTER0
  *           @arg @ref FL_CANFD_PFL_FILTER1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGPFLFilterData1Mask(CANFD_COMMON_Type* CANFDx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGPFL[filterX].CFDGPFLPM1s, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Set Global AFL Ignore Rule Number
  * @rmtoll   CFDGAFLIGNENT    IRN    FL_CANFD_Global_WriteGAFLIgnoreRuleNumber
  * @param    CANFDx CANFD instance
  * @param    number 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGAFLIgnoreRuleNumber(CANFD_COMMON_Type* CANFDx, uint32_t number)
{
    MODIFY_REG(CANFDx->CFDGAFLIGNENT, (0x1fU << 0U), (number << 0U));
}

/**
  * @brief    Get Global AFL Ignore Rule Number
  * @rmtoll   CFDGAFLIGNENT    IRN    FL_CANFD_Global_ReadGAFLIgnoreRuleNumber
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadGAFLIgnoreRuleNumber(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFLIGNENT, (0x1fU << 0U)) >> 0U);
}

/**
  * @brief    Set Global AFL Ignore Rule Enable Key
  * @rmtoll   CFDGAFLIGNCTR    KEY    FL_CANFD_Global_WriteGAFLKeyOfIgnoreRuleEnable
  * @param    CANFDx CANFD instance
  * @param    key 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteGAFLKeyOfIgnoreRuleEnable(CANFD_COMMON_Type* CANFDx, uint32_t key)
{
    MODIFY_REG(CANFDx->CFDGAFLIGNCTR, (0xffU << 8U), (key << 8U));
}

/**
  * @brief    Global AFL Ignore Rule enable 
  * @rmtoll   CFDGAFLIGNCTR    IREN    FL_CANFD_Global_Enable_GAFLIgnoreRule
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_GAFLIgnoreRule(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CANFDx->CFDGAFLIGNCTR, CANFD_CFDGAFLIGNCTR_IREN_Msk);
}

/**
  * @brief    Global AFL Ignore Rule enable status 
  * @rmtoll   CFDGAFLIGNCTR    IREN    FL_CANFD_Global_IsEnabled_GAFLIgnoreRule
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_GAFLIgnoreRule(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDGAFLIGNCTR, CANFD_CFDGAFLIGNCTR_IREN_Msk) == CANFD_CFDGAFLIGNCTR_IREN_Msk);
}

/**
  * @brief    Global AFL Ignore Rule disable 
  * @rmtoll   CFDGAFLIGNCTR    IREN    FL_CANFD_Global_Disable_GAFLIgnoreRule
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_GAFLIgnoreRule(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CANFDx->CFDGAFLIGNCTR, CANFD_CFDGAFLIGNCTR_IREN_Msk);
}

/**
  * @brief    Global RX Message Buffer Interrupt Enable
  * @rmtoll   CFDRMIEC    RMIEg    FL_CANFD_Global_EnableIT_RxMB
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_EnableIT_RxMB(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    SET_BIT(CANFDx->CFDRMIEC, (CANFD_CFDRMIEC_RMIEg_Msk << rxmbX));
}

/**
  * @brief    Global RX Message Buffer Interrupt  enable status 
  * @rmtoll   CFDRMIEC    RMIEg    FL_CANFD_Global_IsEnabledIT_RxMB
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabledIT_RxMB(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    return (uint32_t)(READ_BIT(CANFDx->CFDRMIEC, (CANFD_CFDRMIEC_RMIEg_Msk << rxmbX)) == (CANFD_CFDRMIEC_RMIEg_Msk << rxmbX));
}

/**
  * @brief    Global RX Message Buffer Interrupt disable 
  * @rmtoll   CFDRMIEC    RMIEg    FL_CANFD_Global_DisableIT_RxMB
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_DisableIT_RxMB(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    CLEAR_BIT(CANFDx->CFDRMIEC, (CANFD_CFDRMIEC_RMIEg_Msk << rxmbX));
}

/**
  * @brief    Get Global RX Message Buffer IDE Bit 
  * @rmtoll   CFDRMID    RMIDE    FL_CANFD_Global_GetRxMBIDE
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_RM_IDE_STANDARD
  *           @arg @ref FL_CANFD_RM_IDE_EXTENDED
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetRxMBIDE(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    return (uint32_t)(READ_BIT(RM(CANFDx, rxmbX).CFDRMIDb, CANFD_CFDRMID_RMIDE_Msk));
}

/**
  * @brief    Get Global RX Message Buffer RTR Bit 
  * @rmtoll   CFDRMID    RMRTR    FL_CANFD_Global_GetRxMBRTR
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_RM_RTR_DATA_FRAME
  *           @arg @ref FL_CANFD_RM_RTR_REMOTE_FRAME
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetRxMBRTR(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    return (uint32_t)(READ_BIT(RM(CANFDx, rxmbX).CFDRMIDb, CANFD_CFDRMID_RMRTR_Msk));
}

/**
  * @brief    Get Global RX Message Buffer ID Field 
  * @rmtoll   CFDRMID    RMID    FL_CANFD_Global_ReadRxMBID
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRxMBID(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    return (uint32_t)(READ_BIT(RM(CANFDx, rxmbX).CFDRMIDb, (0x1fffffffU << 0U)) >> 0U);
}

/**
  * @brief    Get Global RX Message Buffer DLC Field 
  * @rmtoll   CFDRMPTR    RMDLC    FL_CANFD_Global_ReadRxMBDLC
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRxMBDLC(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    return (uint32_t)(READ_BIT(RM(CANFDx, rxmbX).CFDRMPTRb, (0xfU << 28U)) >> 28U);
}

/**
  * @brief    Get Global RX Message Buffer Timestamp Field 
  * @rmtoll   CFDRMPTR    RMTS    FL_CANFD_Global_ReadRxMBTimestamp
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRxMBTimestamp(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    return (uint32_t)(READ_BIT(RM(CANFDx, rxmbX).CFDRMPTRb, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get Global RX Message Buffer Pointer Field 
  * @rmtoll   CFDRMFDSTS    RMPTR    FL_CANFD_Global_ReadRxMBPointer
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRxMBPointer(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    return (uint32_t)(READ_BIT(RM(CANFDx, rxmbX).CFDRMFDSTSb, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Get Global RX Message Buffer Information label  Field 
  * @rmtoll   CFDRMFDSTS    RMIFL    FL_CANFD_Global_ReadRxMBInfoLabel
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRxMBInfoLabel(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    return (uint32_t)(READ_BIT(RM(CANFDx, rxmbX).CFDRMFDSTSb, (0x3U << 8U)) >> 8U);
}

/**
  * @brief    Get Global RX Message Buffer CAN FD Format bit
  * @rmtoll   CFDRMFDSTS    RMFDF    FL_CANFD_Global_IsActiveFlag_RxMBFDFormat
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_RxMBFDFormat(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    return (uint32_t)(READ_BIT(RM(CANFDx, rxmbX).CFDRMFDSTSb, CANFD_CFDRMFDSTS_RMFDF_Msk) == (CANFD_CFDRMFDSTS_RMFDF_Msk));
}

/**
  * @brief    Get Global RX Message Buffer Bit Rate Switch bit
  * @rmtoll   CFDRMFDSTS    RMBRS    FL_CANFD_Global_IsActiveFlag_RxMBBitRateSwitch
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_RxMBBitRateSwitch(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    return (uint32_t)(READ_BIT(RM(CANFDx, rxmbX).CFDRMFDSTSb, CANFD_CFDRMFDSTS_RMBRS_Msk) == (CANFD_CFDRMFDSTS_RMBRS_Msk));
}

/**
  * @brief    Get Global RX Message Buffer Error State Indicator bit
  * @rmtoll   CFDRMFDSTS    RMESI    FL_CANFD_Global_IsActiveFlag_RxMBErrorStateIndicator
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_RxMBErrorStateIndicator(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX)
{
    return (uint32_t)(READ_BIT(RM(CANFDx, rxmbX).CFDRMFDSTSb, CANFD_CFDRMFDSTS_RMESI_Msk) == (CANFD_CFDRMFDSTS_RMESI_Msk));
}

/**
  * @brief    Get Global RX Message Buffer Data Field
  * @rmtoll   CFDRMDFp    RMDB    FL_CANFD_Global_ReadRxMBData
  * @param    CANFDx CANFD instance
  * @param    rxmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXMB0
  *           @arg @ref FL_CANFD_RXMB1
  *           @arg @ref FL_CANFD_RXMB2
  *           @arg @ref FL_CANFD_RXMB3
  *           @arg @ref FL_CANFD_RXMB4
  *           @arg @ref FL_CANFD_RXMB5
  *           @arg @ref FL_CANFD_RXMB6
  *           @arg @ref FL_CANFD_RXMB7
  *           @arg @ref FL_CANFD_RXMB8
  *           @arg @ref FL_CANFD_RXMB9
  *           @arg @ref FL_CANFD_RXMB10
  *           @arg @ref FL_CANFD_RXMB11
  *           @arg @ref FL_CANFD_RXMB12
  *           @arg @ref FL_CANFD_RXMB13
  *           @arg @ref FL_CANFD_RXMB14
  *           @arg @ref FL_CANFD_RXMB15
  *           @arg @ref FL_CANFD_RXMB16
  *           @arg @ref FL_CANFD_RXMB17
  *           @arg @ref FL_CANFD_RXMB18
  *           @arg @ref FL_CANFD_RXMB19
  *           @arg @ref FL_CANFD_RXMB20
  *           @arg @ref FL_CANFD_RXMB21
  *           @arg @ref FL_CANFD_RXMB22
  *           @arg @ref FL_CANFD_RXMB23
  *           @arg @ref FL_CANFD_RXMB24
  *           @arg @ref FL_CANFD_RXMB25
  *           @arg @ref FL_CANFD_RXMB26
  *           @arg @ref FL_CANFD_RXMB27
  *           @arg @ref FL_CANFD_RXMB28
  *           @arg @ref FL_CANFD_RXMB29
  *           @arg @ref FL_CANFD_RXMB30
  *           @arg @ref FL_CANFD_RXMB31
  * @param    dataX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_DATA0
  *           @arg @ref FL_CANFD_DATA1
  *           @arg @ref FL_CANFD_DATA2
  *           @arg @ref FL_CANFD_DATA3
  *           @arg @ref FL_CANFD_DATA4
  *           @arg @ref FL_CANFD_DATA5
  *           @arg @ref FL_CANFD_DATA6
  *           @arg @ref FL_CANFD_DATA7
  *           @arg @ref FL_CANFD_DATA8
  *           @arg @ref FL_CANFD_DATA9
  *           @arg @ref FL_CANFD_DATA10
  *           @arg @ref FL_CANFD_DATA11
  *           @arg @ref FL_CANFD_DATA12
  *           @arg @ref FL_CANFD_DATA13
  *           @arg @ref FL_CANFD_DATA14
  *           @arg @ref FL_CANFD_DATA15
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRxMBData(CANFD_COMMON_Type* CANFDx, uint32_t rxmbX, uint32_t dataX)
{
    return (uint32_t)(READ_BIT(RM(CANFDx, rxmbX).CFDRMDFbp[dataX], (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Get Global RX FIFO Buffer IDE Bit 
  * @rmtoll   CFDRFID    RFIDE    FL_CANFD_Global_GetRxFIFOIDE
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_RF_IDE_STANDARD
  *           @arg @ref FL_CANFD_RF_IDE_EXTENDED
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetRxFIFOIDE(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(RF(CANFDx, rxfifoX).CFDRFIDb, CANFD_CFDRFID_RFIDE_Msk));
}

/**
  * @brief    Get Global RX FIFO Buffer RTR Bit 
  * @rmtoll   CFDRFID    RFRTR    FL_CANFD_Global_GetRxFIFORTR
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_RF_RTR_DATA_FRAME
  *           @arg @ref FL_CANFD_RF_RTR_REMOTE_FRAME
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetRxFIFORTR(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(RF(CANFDx, rxfifoX).CFDRFIDb, CANFD_CFDRFID_RFRTR_Msk));
}

/**
  * @brief    Get Global RX FIFO Buffer ID Field 
  * @rmtoll   CFDRFID    RFID    FL_CANFD_Global_ReadRxFIFOID
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRxFIFOID(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(RF(CANFDx, rxfifoX).CFDRFIDb, (0x1fffffffU << 0U)) >> 0U);
}

/**
  * @brief    Get Global RX FIFO Buffer DLC Field 
  * @rmtoll   CFDRFPTR    RFDLC    FL_CANFD_Global_ReadRxFIFODLC
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRxFIFODLC(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(RF(CANFDx, rxfifoX).CFDRFPTRb, (0xfU << 28U)) >> 28U);
}

/**
  * @brief    Get Global RX FIFO Buffer Timestamp Field 
  * @rmtoll   CFDRFPTR    RFTS    FL_CANFD_Global_ReadRxFIFOTimestamp
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRxFIFOTimestamp(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(RF(CANFDx, rxfifoX).CFDRFPTRb, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get Global RX FIFO Buffer Pointer Field 
  * @rmtoll   CFDRFFDSTS    CFDRFPTR    FL_CANFD_Global_ReadRxFIFOPointer
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRxFIFOPointer(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(RF(CANFDx, rxfifoX).CFDRFFDSTSb, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Get Global RX FIFO Buffer Information label  Field 
  * @rmtoll   CFDRFFDSTS    RFIFL    FL_CANFD_Global_ReadRxFIFOInfoLabel
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRxFIFOInfoLabel(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(RF(CANFDx, rxfifoX).CFDRFFDSTSb, (0x3U << 8U)) >> 8U);
}

/**
  * @brief    Get Global RX FIFO Buffer CAN FD Format bit
  * @rmtoll   CFDRFFDSTS    RFFDF    FL_CANFD_Global_IsActiveFlag_RxFIFOFDFormat
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_RxFIFOFDFormat(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(RF(CANFDx, rxfifoX).CFDRFFDSTSb, CANFD_CFDRFFDSTS_RFFDF_Msk) == (CANFD_CFDRFFDSTS_RFFDF_Msk));
}

/**
  * @brief    Get Global RX FIFO Buffer Bit Rate Switch bit
  * @rmtoll   CFDRFFDSTS    RFBRS    FL_CANFD_Global_IsActiveFlag_RxFIFOBitRateSwitch
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_RxFIFOBitRateSwitch(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(RF(CANFDx, rxfifoX).CFDRFFDSTSb, CANFD_CFDRFFDSTS_RFBRS_Msk) == (CANFD_CFDRFFDSTS_RFBRS_Msk));
}

/**
  * @brief    Get Global RX FIFO Buffer Error State Indicator bit
  * @rmtoll   CFDRFFDSTS    RFESI    FL_CANFD_Global_IsActiveFlag_RxFIFOErrorStateIndicator
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsActiveFlag_RxFIFOErrorStateIndicator(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX)
{
    return (uint32_t)(READ_BIT(RF(CANFDx, rxfifoX).CFDRFFDSTSb, CANFD_CFDRFFDSTS_RFESI_Msk) == (CANFD_CFDRFFDSTS_RFESI_Msk));
}

/**
  * @brief    Get Global RX FIFO Buffer Data Field
  * @rmtoll   CFDRFDFp    RFDB    FL_CANFD_Global_ReadRxFIFOData
  * @param    CANFDx CANFD instance
  * @param    rxfifoX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_RXFIFO0
  *           @arg @ref FL_CANFD_RXFIFO1
  * @param    dataX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_DATA0
  *           @arg @ref FL_CANFD_DATA1
  *           @arg @ref FL_CANFD_DATA2
  *           @arg @ref FL_CANFD_DATA3
  *           @arg @ref FL_CANFD_DATA4
  *           @arg @ref FL_CANFD_DATA5
  *           @arg @ref FL_CANFD_DATA6
  *           @arg @ref FL_CANFD_DATA7
  *           @arg @ref FL_CANFD_DATA8
  *           @arg @ref FL_CANFD_DATA9
  *           @arg @ref FL_CANFD_DATA10
  *           @arg @ref FL_CANFD_DATA11
  *           @arg @ref FL_CANFD_DATA12
  *           @arg @ref FL_CANFD_DATA13
  *           @arg @ref FL_CANFD_DATA14
  *           @arg @ref FL_CANFD_DATA15
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadRxFIFOData(CANFD_COMMON_Type* CANFDx, uint32_t rxfifoX, uint32_t dataX)
{
    return (uint32_t)(READ_BIT(RF(CANFDx, rxfifoX).CFDRFDFbp[dataX], (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Set Global Common FIFO Buffer IDE Bit
  * @rmtoll   CFDCFID    CFIDE    FL_CANFD_Global_SetCommonFIFOIDE
  * @param    CANFDx CANFD instance
  * @param    ide This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CF_IDE_STANDARD
  *           @arg @ref FL_CANFD_CF_IDE_EXTENDED
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetCommonFIFOIDE(CANFD_COMMON_Type* CANFDx, uint32_t ide)
{
    MODIFY_REG(CF(CANFDx)->CFDCFID, CANFD_CFDCFID_CFIDE_Msk, ide);
}

/**
  * @brief    Get Global Common FIFO Buffer IDE Bit
  * @rmtoll   CFDCFID    CFIDE    FL_CANFD_Global_GetCommonFIFOIDE
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CF_IDE_STANDARD
  *           @arg @ref FL_CANFD_CF_IDE_EXTENDED
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetCommonFIFOIDE(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CF(CANFDx)->CFDCFID, CANFD_CFDCFID_CFIDE_Msk));
}

/**
  * @brief    Set Global Common FIFO Buffer RTR Bit
  * @rmtoll   CFDCFID    CFRTR    FL_CANFD_Global_SetCommonFIFORTR
  * @param    CANFDx CANFD instance
  * @param    rtr This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CF_RTR_DATA_FRAME
  *           @arg @ref FL_CANFD_CF_RTR_REMOTE_FRAME
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetCommonFIFORTR(CANFD_COMMON_Type* CANFDx, uint32_t rtr)
{
    MODIFY_REG(CF(CANFDx)->CFDCFID, CANFD_CFDCFID_CFRTR_Msk, rtr);
}

/**
  * @brief    Get Global Common FIFO Buffer RTR Bit
  * @rmtoll   CFDCFID    CFRTR    FL_CANFD_Global_GetCommonFIFORTR
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CF_RTR_DATA_FRAME
  *           @arg @ref FL_CANFD_CF_RTR_REMOTE_FRAME
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetCommonFIFORTR(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CF(CANFDx)->CFDCFID, CANFD_CFDCFID_CFRTR_Msk));
}

/**
  * @brief    Global Common FIFO THL Entry enable 
  * @rmtoll   CFDCFID    THLEN    FL_CANFD_Global_Enable_CommonFIFOTxHistoryListEntry
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_CommonFIFOTxHistoryListEntry(CANFD_COMMON_Type* CANFDx)
{
    SET_BIT(CF(CANFDx)->CFDCFID, CANFD_CFDCFID_THLEN_Msk);
}

/**
  * @brief    Global Common FIFO THL Entry enable status 
  * @rmtoll   CFDCFID    THLEN    FL_CANFD_Global_IsEnabled_CommonFIFOTxHistoryListEntry
  * @param    CANFDx CANFD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_CommonFIFOTxHistoryListEntry(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CF(CANFDx)->CFDCFID, CANFD_CFDCFID_THLEN_Msk) == CANFD_CFDCFID_THLEN_Msk);
}

/**
  * @brief    Global Common FIFO THL Entry disable 
  * @rmtoll   CFDCFID    THLEN    FL_CANFD_Global_Disable_CommonFIFOTxHistoryListEntry
  * @param    CANFDx CANFD instance
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_CommonFIFOTxHistoryListEntry(CANFD_COMMON_Type* CANFDx)
{
    CLEAR_BIT(CF(CANFDx)->CFDCFID, CANFD_CFDCFID_THLEN_Msk);
}

/**
  * @brief    Set Global Common FIFO Buffer ID Field
  * @rmtoll   CFDCFID    CFID    FL_CANFD_Global_WriteCommonFIFOID
  * @param    CANFDx CANFD instance
  * @param    id 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteCommonFIFOID(CANFD_COMMON_Type* CANFDx, uint32_t id)
{
    MODIFY_REG(CF(CANFDx)->CFDCFID, (0x1fffffffU << 0U), (id << 0U));
}

/**
  * @brief    Get Global Common FIFO Buffer ID Field
  * @rmtoll   CFDCFID    CFID    FL_CANFD_Global_ReadCommonFIFOID
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadCommonFIFOID(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CF(CANFDx)->CFDCFID, (0x1fffffffU << 0U)) >> 0U);
}

/**
  * @brief    Set Global Common FIFO Buffer DLC Field
  * @rmtoll   CFDCFPTR    CFDLC    FL_CANFD_Global_WriteCommonFIFODLC
  * @param    CANFDx CANFD instance
  * @param    dlc 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteCommonFIFODLC(CANFD_COMMON_Type* CANFDx, uint32_t dlc)
{
    MODIFY_REG(CF(CANFDx)->CFDCFPTR, (0xfU << 28U), (dlc << 28U));
}

/**
  * @brief    Get Global Common FIFO Buffer DLC Field
  * @rmtoll   CFDCFPTR    CFDLC    FL_CANFD_Global_ReadCommonFIFODLC
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadCommonFIFODLC(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CF(CANFDx)->CFDCFPTR, (0xfU << 28U)) >> 28U);
}

/**
  * @brief    Set Global Common FIFO Timestamp Value
  * @rmtoll   CFDCFPTR    CFTS    FL_CANFD_Global_WriteCommonFIFOTimestamp
  * @param    CANFDx CANFD instance
  * @param    time 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteCommonFIFOTimestamp(CANFD_COMMON_Type* CANFDx, uint32_t time)
{
    MODIFY_REG(CF(CANFDx)->CFDCFPTR, (0xffffU << 0U), (time << 0U));
}

/**
  * @brief    Get Global Common FIFO Timestamp Value
  * @rmtoll   CFDCFPTR    CFTS    FL_CANFD_Global_ReadCommonFIFOTimestamp
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadCommonFIFOTimestamp(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CF(CANFDx)->CFDCFPTR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get Global Common FIFO Buffer Pointer Field 
  * @rmtoll   CFDCFFDCSTS    CFPTR    FL_CANFD_Global_ReadCommonFIFOPointer
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadCommonFIFOPointer(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CF(CANFDx)->CFDCFFDCSTS, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Set Global Common FIFO Buffer Information label  Field 
  * @rmtoll   CFDCFFDCSTS    CFIFL    FL_CANFD_Global_WriteCommonFIFOInfoLabel
  * @param    CANFDx CANFD instance
  * @param    label 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteCommonFIFOInfoLabel(CANFD_COMMON_Type* CANFDx, uint32_t label)
{
    MODIFY_REG(CF(CANFDx)->CFDCFFDCSTS, (0x3U << 8U), (label << 8U));
}

/**
  * @brief    Get Global Common FIFO Buffer Information label  Field 
  * @rmtoll   CFDCFFDCSTS    CFIFL    FL_CANFD_Global_ReadCommonFIFOInfoLabel
  * @param    CANFDx CANFD instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadCommonFIFOInfoLabel(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CF(CANFDx)->CFDCFFDCSTS, (0x3U << 8U)) >> 8U);
}

/**
  * @brief    Set Global Common FIFO Buffer CAN FD Format bit
  * @rmtoll   CFDCFFDCSTS    CFFDF    FL_CANFD_Global_SetCommonFIFOFDFormat
  * @param    CANFDx CANFD instance
  * @param    fdf This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CF_FDF_DISABLE
  *           @arg @ref FL_CANFD_CF_FDF_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetCommonFIFOFDFormat(CANFD_COMMON_Type* CANFDx, uint32_t fdf)
{
    MODIFY_REG(CF(CANFDx)->CFDCFFDCSTS, CANFD_CFDCFFDCSTS_CFFDF_Msk, fdf);
}

/**
  * @brief    Get Global Common FIFO Buffer CAN FD Format bit
  * @rmtoll   CFDCFFDCSTS    CFFDF    FL_CANFD_Global_GetCommonFIFOFDFormat
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CF_FDF_DISABLE
  *           @arg @ref FL_CANFD_CF_FDF_ENABLE
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetCommonFIFOFDFormat(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CF(CANFDx)->CFDCFFDCSTS, CANFD_CFDCFFDCSTS_CFFDF_Msk));
}

/**
  * @brief    Set Global Common FIFO Buffer Bit Rate Switch bit
  * @rmtoll   CFDCFFDCSTS    CFBRS    FL_CANFD_Global_SetCommonFIFOBitRateSwitch
  * @param    CANFDx CANFD instance
  * @param    brs This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CF_BRS_DISABLE
  *           @arg @ref FL_CANFD_CF_BRS_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetCommonFIFOBitRateSwitch(CANFD_COMMON_Type* CANFDx, uint32_t brs)
{
    MODIFY_REG(CF(CANFDx)->CFDCFFDCSTS, CANFD_CFDCFFDCSTS_CFBRS_Msk, brs);
}

/**
  * @brief    Get Global Common FIFO Buffer Bit Rate Switch bit
  * @rmtoll   CFDCFFDCSTS    CFBRS    FL_CANFD_Global_GetCommonFIFOBitRateSwitch
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CF_BRS_DISABLE
  *           @arg @ref FL_CANFD_CF_BRS_ENABLE
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetCommonFIFOBitRateSwitch(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CF(CANFDx)->CFDCFFDCSTS, CANFD_CFDCFFDCSTS_CFBRS_Msk));
}

/**
  * @brief    Set Global Common FIFO Buffer Error State Indicator bit 
  * @rmtoll   CFDCFFDCSTS    CFESI    FL_CANFD_Global_SetCommonFIFOErrorStateIndicator
  * @param    CANFDx CANFD instance
  * @param    esi This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_CF_ESI_DISABLE
  *           @arg @ref FL_CANFD_CF_ESI_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetCommonFIFOErrorStateIndicator(CANFD_COMMON_Type* CANFDx, uint32_t esi)
{
    MODIFY_REG(CF(CANFDx)->CFDCFFDCSTS, CANFD_CFDCFFDCSTS_CFESI_Msk, esi);
}

/**
  * @brief    Get Global Common FIFO Buffer Error State Indicator bit 
  * @rmtoll   CFDCFFDCSTS    CFESI    FL_CANFD_Global_GetCommonFIFOErrorStateIndicator
  * @param    CANFDx CANFD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_CF_ESI_DISABLE
  *           @arg @ref FL_CANFD_CF_ESI_ENABLE
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetCommonFIFOErrorStateIndicator(CANFD_COMMON_Type* CANFDx)
{
    return (uint32_t)(READ_BIT(CF(CANFDx)->CFDCFFDCSTS, CANFD_CFDCFFDCSTS_CFESI_Msk));
}

/**
  * @brief    Set Global Common FIFO Buffer Data  Field 
  * @rmtoll   CFDCFDFp    CFDB    FL_CANFD_Global_WriteCommonFIFOData
  * @param    CANFDx CANFD instance
  * @param    dataX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_DATA0
  *           @arg @ref FL_CANFD_DATA1
  *           @arg @ref FL_CANFD_DATA2
  *           @arg @ref FL_CANFD_DATA3
  *           @arg @ref FL_CANFD_DATA4
  *           @arg @ref FL_CANFD_DATA5
  *           @arg @ref FL_CANFD_DATA6
  *           @arg @ref FL_CANFD_DATA7
  *           @arg @ref FL_CANFD_DATA8
  *           @arg @ref FL_CANFD_DATA9
  *           @arg @ref FL_CANFD_DATA10
  *           @arg @ref FL_CANFD_DATA11
  *           @arg @ref FL_CANFD_DATA12
  *           @arg @ref FL_CANFD_DATA13
  *           @arg @ref FL_CANFD_DATA14
  *           @arg @ref FL_CANFD_DATA15
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteCommonFIFOData(CANFD_COMMON_Type* CANFDx, uint32_t dataX, uint32_t data)
{
    MODIFY_REG(CF(CANFDx)->CFDCFDFp[dataX], (0xffffffffU << 0U), (data << 0U));
}

/**
  * @brief    Get Global Common FIFO Buffer Data  Field 
  * @rmtoll   CFDCFDFp    CFDB    FL_CANFD_Global_ReadCommonFIFOData
  * @param    CANFDx CANFD instance
  * @param    dataX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_DATA0
  *           @arg @ref FL_CANFD_DATA1
  *           @arg @ref FL_CANFD_DATA2
  *           @arg @ref FL_CANFD_DATA3
  *           @arg @ref FL_CANFD_DATA4
  *           @arg @ref FL_CANFD_DATA5
  *           @arg @ref FL_CANFD_DATA6
  *           @arg @ref FL_CANFD_DATA7
  *           @arg @ref FL_CANFD_DATA8
  *           @arg @ref FL_CANFD_DATA9
  *           @arg @ref FL_CANFD_DATA10
  *           @arg @ref FL_CANFD_DATA11
  *           @arg @ref FL_CANFD_DATA12
  *           @arg @ref FL_CANFD_DATA13
  *           @arg @ref FL_CANFD_DATA14
  *           @arg @ref FL_CANFD_DATA15
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadCommonFIFOData(CANFD_COMMON_Type* CANFDx, uint32_t dataX)
{
    return (uint32_t)(READ_BIT(CF(CANFDx)->CFDCFDFp[dataX], (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Set Global TX Message Buffer IDE Bit
  * @rmtoll   CFDTMID    TMIDE    FL_CANFD_Global_SetTxMBIDE
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @param    ide This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TM_IDE_STANDARD
  *           @arg @ref FL_CANFD_TM_IDE_EXTENDED
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetTxMBIDE(CANFD_COMMON_Type* CANFDx, uint32_t txmbX, uint32_t ide)
{
    MODIFY_REG(TM(CANFDx, txmbX).CFDTMIDb, CANFD_CFDTMID_TMIDE_Msk, ide);
}

/**
  * @brief    Get Global TX Message Buffer IDE Bit
  * @rmtoll   CFDTMID    TMIDE    FL_CANFD_Global_GetTxMBIDE
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TM_IDE_STANDARD
  *           @arg @ref FL_CANFD_TM_IDE_EXTENDED
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTxMBIDE(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(TM(CANFDx, txmbX).CFDTMIDb, CANFD_CFDTMID_TMIDE_Msk));
}

/**
  * @brief    Set Global TX Message Buffer RTR Bit
  * @rmtoll   CFDTMID    TMRTR    FL_CANFD_Global_SetTxMBRTR
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @param    rtr This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TM_RTR_DATA_FRAME
  *           @arg @ref FL_CANFD_TM_RTR_REMOTE_FRAME
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetTxMBRTR(CANFD_COMMON_Type* CANFDx, uint32_t txmbX, uint32_t rtr)
{
    MODIFY_REG(TM(CANFDx, txmbX).CFDTMIDb, CANFD_CFDTMID_TMRTR_Msk, rtr);
}

/**
  * @brief    Get Global TX Message Buffer RTR Bit
  * @rmtoll   CFDTMID    TMRTR    FL_CANFD_Global_GetTxMBRTR
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TM_RTR_DATA_FRAME
  *           @arg @ref FL_CANFD_TM_RTR_REMOTE_FRAME
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTxMBRTR(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(TM(CANFDx, txmbX).CFDTMIDb, CANFD_CFDTMID_TMRTR_Msk));
}

/**
  * @brief    Global TX Message THL Entry enable 
  * @rmtoll   CFDTMID    THLEN    FL_CANFD_Global_Enable_TxMBTxHistoryListEntry
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Enable_TxMBTxHistoryListEntry(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    SET_BIT(TM(CANFDx, txmbX).CFDTMIDb, CANFD_CFDTMID_THLEN_Msk);
}

/**
  * @brief    Global TX Message THL Entry enable status 
  * @rmtoll   CFDTMID    THLEN    FL_CANFD_Global_IsEnabled_TxMBTxHistoryListEntry
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_IsEnabled_TxMBTxHistoryListEntry(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(TM(CANFDx, txmbX).CFDTMIDb, CANFD_CFDTMID_THLEN_Msk) == CANFD_CFDTMID_THLEN_Msk);
}

/**
  * @brief    Global TX Message THL Entry disable 
  * @rmtoll   CFDTMID    THLEN    FL_CANFD_Global_Disable_TxMBTxHistoryListEntry
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_Disable_TxMBTxHistoryListEntry(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    CLEAR_BIT(TM(CANFDx, txmbX).CFDTMIDb, CANFD_CFDTMID_THLEN_Msk);
}

/**
  * @brief    Set Global TX Message Buffer ID Field
  * @rmtoll   CFDTMID    TMID    FL_CANFD_Global_WriteTxMBID
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @param    id 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteTxMBID(CANFD_COMMON_Type* CANFDx, uint32_t txmbX, uint32_t id)
{
    MODIFY_REG(TM(CANFDx, txmbX).CFDTMIDb, (0x1fffffffU << 0U), (id << 0U));
}

/**
  * @brief    Get Global TX Message Buffer ID Field
  * @rmtoll   CFDTMID    TMID    FL_CANFD_Global_ReadTxMBID
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadTxMBID(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(TM(CANFDx, txmbX).CFDTMIDb, (0x1fffffffU << 0U)) >> 0U);
}

/**
  * @brief    Set Global TX Message Buffer DLC Field
  * @rmtoll   CFDTMPTR    TMDLC    FL_CANFD_Global_WriteTxMBDLC
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @param    dlc 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteTxMBDLC(CANFD_COMMON_Type* CANFDx, uint32_t txmbX, uint32_t dlc)
{
    MODIFY_REG(TM(CANFDx, txmbX).CFDTMPTRb, (0xfU << 28U), (dlc << 28U));
}

/**
  * @brief    Get Global TX Message Buffer DLC Field
  * @rmtoll   CFDTMPTR    TMDLC    FL_CANFD_Global_ReadTxMBDLC
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadTxMBDLC(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(TM(CANFDx, txmbX).CFDTMPTRb, (0xfU << 28U)) >> 28U);
}

/**
  * @brief    Set Global TX Message Buffer Pointer Field 
  * @rmtoll   CFDTMFDCTR    TMPTR    FL_CANFD_Global_WriteTxMBPointer
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @param    pointer 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteTxMBPointer(CANFD_COMMON_Type* CANFDx, uint32_t txmbX, uint32_t pointer)
{
    MODIFY_REG(TM(CANFDx, txmbX).CFDTMFDCTRb, (0xffffU << 16U), (pointer << 16U));
}

/**
  * @brief    Get Global TX Message Buffer Pointer Field 
  * @rmtoll   CFDTMFDCTR    TMPTR    FL_CANFD_Global_ReadTxMBPointer
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadTxMBPointer(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(TM(CANFDx, txmbX).CFDTMFDCTRb, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Set Global TX Message Buffer Information label  Field 
  * @rmtoll   CFDTMFDCTR    TMIFL    FL_CANFD_Global_WriteTxMBInfoLabel
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @param    label 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteTxMBInfoLabel(CANFD_COMMON_Type* CANFDx, uint32_t txmbX, uint32_t label)
{
    MODIFY_REG(TM(CANFDx, txmbX).CFDTMFDCTRb, (0x3U << 8U), (label << 8U));
}

/**
  * @brief    Get Global TX Message Buffer Information label  Field 
  * @rmtoll   CFDTMFDCTR    TMIFL    FL_CANFD_Global_ReadTxMBInfoLabel
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadTxMBInfoLabel(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(TM(CANFDx, txmbX).CFDTMFDCTRb, (0x3U << 8U)) >> 8U);
}

/**
  * @brief    Set Global TX Message Buffer CAN FD Format bit
  * @rmtoll   CFDTMFDCTR    TMFDF    FL_CANFD_Global_SetTxMBFDFormat
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @param    fdf This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TM_FDF_DISABLE
  *           @arg @ref FL_CANFD_TM_FDF_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetTxMBFDFormat(CANFD_COMMON_Type* CANFDx, uint32_t txmbX, uint32_t fdf)
{
    MODIFY_REG(TM(CANFDx, txmbX).CFDTMFDCTRb, CANFD_CFDTMFDCTR_TMFDF_Msk, fdf);
}

/**
  * @brief    Get Global TX Message Buffer CAN FD Format bit
  * @rmtoll   CFDTMFDCTR    TMFDF    FL_CANFD_Global_GetTxMBFDFormat
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TM_FDF_DISABLE
  *           @arg @ref FL_CANFD_TM_FDF_ENABLE
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTxMBFDFormat(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(TM(CANFDx, txmbX).CFDTMFDCTRb, CANFD_CFDTMFDCTR_TMFDF_Msk));
}

/**
  * @brief    Set Global TX Message Buffer Bit Rate Switch bit
  * @rmtoll   CFDTMFDCTR    TMBRS    FL_CANFD_Global_SetTxMBBitRateSwitch
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @param    brs This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TM_BRS_DISABLE
  *           @arg @ref FL_CANFD_TM_BRS_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetTxMBBitRateSwitch(CANFD_COMMON_Type* CANFDx, uint32_t txmbX, uint32_t brs)
{
    MODIFY_REG(TM(CANFDx, txmbX).CFDTMFDCTRb, CANFD_CFDTMFDCTR_TMBRS_Msk, brs);
}

/**
  * @brief    Get Global TX Message Buffer Bit Rate Switch bit
  * @rmtoll   CFDTMFDCTR    TMBRS    FL_CANFD_Global_GetTxMBBitRateSwitch
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TM_BRS_DISABLE
  *           @arg @ref FL_CANFD_TM_BRS_ENABLE
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTxMBBitRateSwitch(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(TM(CANFDx, txmbX).CFDTMFDCTRb, CANFD_CFDTMFDCTR_TMBRS_Msk));
}

/**
  * @brief    Set Global TX Message Buffer Error State Indicator bit 
  * @rmtoll   CFDTMFDCTR    TMESI    FL_CANFD_Global_SetTxMBErrorStateIndicator
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @param    esi This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TM_ESI_DISABLE
  *           @arg @ref FL_CANFD_TM_ESI_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_SetTxMBErrorStateIndicator(CANFD_COMMON_Type* CANFDx, uint32_t txmbX, uint32_t esi)
{
    MODIFY_REG(TM(CANFDx, txmbX).CFDTMFDCTRb, CANFD_CFDTMFDCTR_TMESI_Msk, esi);
}

/**
  * @brief    Get Global TX Message Buffer Error State Indicator bit 
  * @rmtoll   CFDTMFDCTR    TMESI    FL_CANFD_Global_GetTxMBErrorStateIndicator
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CANFD_TM_ESI_DISABLE
  *           @arg @ref FL_CANFD_TM_ESI_ENABLE
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_GetTxMBErrorStateIndicator(CANFD_COMMON_Type* CANFDx, uint32_t txmbX)
{
    return (uint32_t)(READ_BIT(TM(CANFDx, txmbX).CFDTMFDCTRb, CANFD_CFDTMFDCTR_TMESI_Msk));
}

/**
  * @brief    Set Global TX Message Buffer Data  Field 
  * @rmtoll   CFDTMDFp    TMDB    FL_CANFD_Global_WriteTxMBData
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @param    dataX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_DATA0
  *           @arg @ref FL_CANFD_DATA1
  *           @arg @ref FL_CANFD_DATA2
  *           @arg @ref FL_CANFD_DATA3
  *           @arg @ref FL_CANFD_DATA4
  *           @arg @ref FL_CANFD_DATA5
  *           @arg @ref FL_CANFD_DATA6
  *           @arg @ref FL_CANFD_DATA7
  *           @arg @ref FL_CANFD_DATA8
  *           @arg @ref FL_CANFD_DATA9
  *           @arg @ref FL_CANFD_DATA10
  *           @arg @ref FL_CANFD_DATA11
  *           @arg @ref FL_CANFD_DATA12
  *           @arg @ref FL_CANFD_DATA13
  *           @arg @ref FL_CANFD_DATA14
  *           @arg @ref FL_CANFD_DATA15
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_CANFD_Global_WriteTxMBData(CANFD_COMMON_Type* CANFDx, uint32_t txmbX, uint32_t dataX, uint32_t data)
{
    MODIFY_REG(TM(CANFDx, txmbX).CFDTMDFbp[dataX], (0xffffffffU << 0U), (data << 0U));
}

/**
  * @brief    Get Global TX Message Buffer Data  Field 
  * @rmtoll   CFDTMDFp    TMDB    FL_CANFD_Global_ReadTxMBData
  * @param    CANFDx CANFD instance
  * @param    txmbX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_TXMB0
  *           @arg @ref FL_CANFD_TXMB1
  *           @arg @ref FL_CANFD_TXMB2
  *           @arg @ref FL_CANFD_TXMB3
  * @param    dataX This parameter can be one of the following values:
  *           @arg @ref FL_CANFD_DATA0
  *           @arg @ref FL_CANFD_DATA1
  *           @arg @ref FL_CANFD_DATA2
  *           @arg @ref FL_CANFD_DATA3
  *           @arg @ref FL_CANFD_DATA4
  *           @arg @ref FL_CANFD_DATA5
  *           @arg @ref FL_CANFD_DATA6
  *           @arg @ref FL_CANFD_DATA7
  *           @arg @ref FL_CANFD_DATA8
  *           @arg @ref FL_CANFD_DATA9
  *           @arg @ref FL_CANFD_DATA10
  *           @arg @ref FL_CANFD_DATA11
  *           @arg @ref FL_CANFD_DATA12
  *           @arg @ref FL_CANFD_DATA13
  *           @arg @ref FL_CANFD_DATA14
  *           @arg @ref FL_CANFD_DATA15
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CANFD_Global_ReadTxMBData(CANFD_COMMON_Type* CANFDx, uint32_t txmbX, uint32_t dataX)
{
    return (uint32_t)(READ_BIT(TM(CANFDx, txmbX).CFDTMDFbp[dataX], (0xffffffffU << 0U)) >> 0U);
}

/**
  * @}
  */

/** @defgroup CANFD_FL_EF_Init Initialization and de-initialization functions
  * @{
  */

FL_ErrorStatus FL_CANFD_Init(CANFD_COMMON_Type *CANFDx, FL_CANFD_InitTypeDef *CANFD_InitStruct);
void FL_CANFD_StructInit(CANFD_COMMON_Type *CANFDx, FL_CANFD_InitTypeDef *CANFD_InitStruct);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_CANFD_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-08-08*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
