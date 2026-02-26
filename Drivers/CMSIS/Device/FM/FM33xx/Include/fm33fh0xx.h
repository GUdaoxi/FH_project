/**
  ****************************************************************************************************//**
  * @file     FM33FH0XX.h
  *
  * @brief    CMSIS M0 Peripheral Access Layer Header File for
  *           FM33FH0XX from .
  *
  * @version  V1.1.0
  * @date     13. June 2025
  *
  * @note     Generated with SVDConv V2.87e 
  *           from CMSIS SVD File 'FM33FH0XX.svd' Version 1.0,
  *******************************************************************************************************
  * @attention    
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


/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup FM33FH0XX
  * @{
  */

#ifndef FM33FH0XX_H
#define FM33FH0XX_H

#ifdef __cplusplus
extern "C" {
#endif


/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum {
/* ---------------------  SC000 Processor Exceptions Numbers  --------------------- */
  Reset_IRQn                    = -15,              /*!<   1  Reset Vector, invoked on Power up and warm reset                 */
  NMI_IRQn                      = -14,              /*!<   2  Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                = -13,              /*!<   3  Hard Fault, all classes of Fault                                 */
  SVCall_IRQn                   =  -5,              /*!<  11  System Service Call via SVC instruction                          */                                               
  PendSV_IRQn                   =  -2,              /*!<  14  Pendable request for system service                              */
  SysTick_IRQn                  =  -1,              /*!<  15  System Tick Timer                                                */
/* --------------------  FM33FH0XX Specific Interrupt Numbers  -------------------- */
  MUX0_IRQn                     =   0,              /*!<   0  MUX0 interrupt                                                   */
  MUX1_IRQn                     =   1,              /*!<   1  MUX1 interrupt                                                   */
  MUX2_IRQn                     =   2,              /*!<   2  MUX2 interrupt                                                   */
  MUX3_IRQn                     =   3,              /*!<   3  MUX3 interrupt                                                   */
  MUX4_IRQn                     =   4,              /*!<   4  MUX4 interrupt                                                   */
  MUX5_IRQn                     =   5,              /*!<   5  MUX5 interrupt                                                   */
  MUX6_IRQn                     =   6,              /*!<   6  MUX6 interrupt                                                   */
  MUX7_IRQn                     =   7,              /*!<   7  MUX7 interrupt                                                   */
  MUX8_IRQn                     =   8,              /*!<   8  MUX8 interrupt                                                   */
  MUX9_IRQn                     =   9,              /*!<   9  MUX9 interrupt                                                   */
  MUX10_IRQn                    =  10,              /*!<  10  MUX10 interrupt                                                  */
  MUX11_IRQn                    =  11,              /*!<  11  MUX11 interrupt                                                  */
  MUX12_IRQn                    =  12,              /*!<  12  MUX12 interrupt                                                  */
  MUX13_IRQn                    =  13,              /*!<  13  MUX13 interrupt                                                  */
  MUX14_IRQn                    =  14,              /*!<  14  MUX14 interrupt                                                  */
  MUX15_IRQn                    =  15,              /*!<  15  MUX15 interrupt                                                  */
  MUX16_IRQn                    =  16,              /*!<  16  MUX16 interrupt                                                  */
  MUX17_IRQn                    =  17,              /*!<  17  MUX17 interrupt                                                  */
  MUX18_IRQn                    =  18,              /*!<  18  MUX18 interrupt                                                  */
  MUX19_IRQn                    =  19,              /*!<  19  MUX19 interrupt                                                  */
  MUX20_IRQn                    =  20,              /*!<  20  MUX20 interrupt                                                  */
  MUX21_IRQn                    =  21,              /*!<  21  MUX21 interrupt                                                  */
  MUX22_IRQn                    =  22,              /*!<  22  MUX22 interrupt                                                  */
  MUX23_IRQn                    =  23,              /*!<  23  MUX23 interrupt                                                  */
  MUX24_IRQn                    =  24,              /*!<  24  MUX24 interrupt                                                  */
  MUX25_IRQn                    =  25,              /*!<  25  MUX25 interrupt                                                  */
  MUX26_IRQn                    =  26,              /*!<  26  MUX26 interrupt                                                  */
  MUX27_IRQn                    =  27,              /*!<  27  MUX27 interrupt                                                  */
  MUX28_IRQn                    =  28,              /*!<  28  MUX28 interrupt                                                  */
  MUX29_IRQn                    =  29,              /*!<  29  MUX29 interrupt                                                  */
  MUX30_IRQn                    =  30,              /*!<  30  MUX30 interrupt                                                  */
  MUX31_IRQn                    =  31               /*!<  31  MUX31 interrupt                                                  */
} IRQn_Type;


/** @addtogroup Configuration_of_CMSIS
  * @{
  */


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the SC000 Processor and Core Peripherals---------------- */
#define __CM0_REV                      0x0100U      /*!< Cortex-M0 Core Revision                                               */
#define __MPU_PRESENT                  0            /*!< MPU present or not                                                    */
#define __VTOR_PRESENT                 1            /*!< VTOR present or not                                                   */
#define __NVIC_PRIO_BITS               2            /*!< Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig         0            /*!< Set to 1 if different SysTick Config is used                          */
/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm0plus.h"                           /*!< Cortex-M0 processor and core peripherals                              */
#include "system_fm33fh0xx.h"                       /*!< FM33FH0XX System                                                      */
#include <stdint.h>   

/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */


/** @addtogroup Device_Peripheral_Registers
  * @{
  */


/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)             
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif



/* ================================================================================ */
/* ================                       ADC                      ================ */
/* ================================================================================ */


/**
  * @brief ADC module information (ADC)
  */

typedef struct {                                    /*!< ADC Structure                                                         */
  __IO uint32_t  ACQ_ISR;                           /*!< ACQ_ISR Register                                                      */
  __IO uint32_t  ACQ_IER;                           /*!< ACQ_IER Register                                                      */
  __IO uint32_t  GISR;                              /*!< GISR Register                                                         */
  __IO uint32_t  GIER;                              /*!< GIER Register                                                         */
  __IO uint32_t  CR1;                               /*!< CR1 Register                                                          */
  __IO uint32_t  CR2;                               /*!< CR2 Register                                                          */
  __I  uint32_t  RESERVED;
  __IO uint32_t  CFGR1;                             /*!< CFGR1 Register                                                        */
  __IO uint32_t  CFGR2;                             /*!< CFGR2 Register                                                        */
  __I  uint32_t  RESERVED1[2];
  __IO uint32_t  OSR;                               /*!< OSR Register                                                          */
  __IO uint32_t  ACQ_SR;                            /*!< ACQ_SR Register                                                       */
  __IO uint32_t  ACQ_SACR;                          /*!< ACQ_SACR Register                                                     */
  __IO uint32_t  HLTR;                              /*!< HLTR Register                                                         */
  __IO uint32_t  AWDCR;                             /*!< AWDCR Register                                                        */
  __IO uint32_t  ACQ0_CR;                           /*!< ACQ0_CR Register                                                      */
  __IO uint32_t  ACQ1_CR;                           /*!< ACQ1_CR Register                                                      */
  __IO uint32_t  ACQ2_CR;                           /*!< ACQ2_CR Register                                                      */
  __IO uint32_t  ACQ3_CR;                           /*!< ACQ3_CR Register                                                      */
  __IO uint32_t  SCANACQ_CR;                        /*!< SCANACQ_CR Register                                                   */
  __I  uint32_t  RESERVED2[11];
  __IO uint32_t  CHISR;                             /*!< CHISR Register                                                        */
  __IO uint32_t  CHDMA_DR;                          /*!< CHDMA_DR Register                                                     */
  __IO uint32_t  CH0DR;                             /*!< CH0DR Register                                                       */
  __IO uint32_t  CH1DR;                             /*!< CH1DR Register                                                       */
  __IO uint32_t  CH2DR;                             /*!< CH2DR Register                                                       */
  __IO uint32_t  CH3DR;                             /*!< CH3DR Register                                                       */
  __IO uint32_t  CH4DR;                             /*!< CH4DR Register                                                       */
  __IO uint32_t  CH5DR;                             /*!< CH5DR Register                                                       */
  __IO uint32_t  CH6DR;                             /*!< CH6DR Register                                                       */
  __IO uint32_t  CH7DR;                             /*!< CH7DR Register                                                       */
  __IO uint32_t  CH8DR;                             /*!< CH8DR Register                                                       */
  __IO uint32_t  CH9DR;                             /*!< CH9DR Register                                                       */
  __IO uint32_t  CH10DR;                            /*!< CH10DR Register                                                      */
  __IO uint32_t  CH11DR;                            /*!< CH11DR Register                                                      */
  __IO uint32_t  CH12DR;                            /*!< CH12DR Register                                                      */
  __IO uint32_t  CH13DR;                            /*!< CH13DR Register                                                      */
  __IO uint32_t  CH14DR;                            /*!< CH14DR Register                                                      */
  __IO uint32_t  CH15DR;                            /*!< CH15DR Register                                                      */
  __IO uint32_t  CH16DR;                            /*!< CH16DR Register                                                      */
  __IO uint32_t  CH17DR;                            /*!< CH17DR Register                                                      */
  __IO uint32_t  CH18DR;                            /*!< CH18DR Register                                                      */
  __IO uint32_t  CH19DR;                            /*!< CH19DR Register                                                      */
  __IO uint32_t  CH20DR;                            /*!< CH20DR Register                                                      */
  __IO uint32_t  CH21DR;                            /*!< CH21DR Register                                                      */
  __IO uint32_t  CH22DR;                            /*!< CH22DR Register                                                      */
  __IO uint32_t  CH23DR;                            /*!< CH23DR Register                                                      */
  __IO uint32_t  CH24DR;                            /*!< CH24DR Register                                                      */
  __IO uint32_t  CH25DR;                            /*!< CH25DR Register                                                      */
  __IO uint32_t  CH26DR;                            /*!< CH26DR Register                                                      */
  __IO uint32_t  CH27DR;                            /*!< CH27DR Register                                                      */
  __IO uint32_t  CH28DR;                            /*!< CH28DR Register                                                      */
  __IO uint32_t  CH29DR;                            /*!< CH29DR Register                                                      */
  __IO uint32_t  CH30DR;                            /*!< CH30DR Register                                                      */
  __IO uint32_t  CH31DR;                            /*!< CH31DR Register                                                      */
} ADC_Type;


/* ================================================================================ */
/* ================                      ATIM                      ================ */
/* ================================================================================ */


/**
  * @brief ATIM module information (ATIM)
  */

typedef struct {                                    /*!< ATIM Structure                                                        */
  __IO uint32_t  CR1;                               /*!< CR1 Register                                                          */
  __IO uint32_t  CR2;                               /*!< CR2 Register                                                          */
  __IO uint32_t  SMCR;                              /*!< SMCR Register                                                         */
  __IO uint32_t  DIER;                              /*!< DIER Register                                                         */
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
  __IO uint32_t  EGR;                               /*!< EGR Register                                                          */
  __IO uint32_t  CCMR1;                             /*!< CCMR1 Register                                                        */
  __IO uint32_t  CCMR2;                             /*!< CCMR2 Register                                                        */
  __IO uint32_t  CCER;                              /*!< CCER Register                                                         */
  __IO uint32_t  CNT;                               /*!< CNT Register                                                          */
  __IO uint32_t  PSC;                               /*!< PSC Register                                                          */
  __IO uint32_t  ARR;                               /*!< ARR Register                                                          */
  __IO uint32_t  RCR;                               /*!< RCR Register                                                          */
  __IO uint32_t  CCR1;                              /*!< CCR1 Register                                                         */
  __IO uint32_t  CCR2;                              /*!< CCR2 Register                                                         */
  __IO uint32_t  CCR3;                              /*!< CCR3 Register                                                         */
  __IO uint32_t  CCR4;                              /*!< CCR4 Register                                                         */
  __IO uint32_t  BDTR;                              /*!< BDTR Register                                                         */
  __IO uint32_t  CCMR3;                             /*!< CCMR3 Register                                                        */
  __IO uint32_t  CCR5;                              /*!< CCR5 Register                                                         */
  __IO uint32_t  CCR6;                              /*!< CCR6 Register                                                         */
  __IO uint32_t  ECR;                               /*!< ECR Register                                                          */
  __IO uint32_t  TISEL;                             /*!< TISEL Register                                                        */
  __IO uint32_t  AFR;                               /*!< AFR Register                                                          */
  __IO uint32_t  BRKFLAG;                           /*!< BRKFLAG Register                                                      */
  __I  uint32_t  RESERVED[37];
  __IO uint32_t  DCR;                               /*!< DCR Register                                                          */
  __IO uint32_t  DMAR;                              /*!< ATIM_DMAR Register                                                    */
} ATIM_Type;


/* ================================================================================ */
/* ================                     BSTIM16                    ================ */
/* ================================================================================ */


/**
  * @brief BSTIM16 module information (BSTIM16)
  */

typedef struct {                                    /*!< BSTIM16 Structure                                                     */
  __IO uint32_t  CR1;                               /*!< CR1 Register                                                          */
  __IO uint32_t  CR2;                               /*!< CR2 Register                                                          */
  __I  uint32_t  RESERVED;
  __IO uint32_t  IER;                               /*!< IER Register                                                         */
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
  __IO uint32_t  EGR;                               /*!< EGR Register                                                          */
  __I  uint32_t  RESERVED1[3];
  __IO uint32_t  CNT;                               /*!< CNT Register                                                          */
  __IO uint32_t  PSC;                               /*!< PSC Register                                                          */
  __IO uint32_t  ARR;                               /*!< ARR Register                                                          */
} BSTIM16_Type;


/* ================================================================================ */
/* ================                      CANFD                     ================ */
/* ================================================================================ */


/**
  * @brief FDCAN module information (CANFD)
  */

typedef struct
{
    __IO uint32_t CFDC0NCFG;               /*!<  Channel 0 Nominal Bitrate Configuration Register                                             Address offset: 0000h                                     */
    __IO uint32_t CFDC0CTR;                /*!<  Channel 0 Control Register                                                                   Address offset: 0004h                                     */
    __IO uint32_t CFDC0STS;                /*!<  Channel 0 Status Register                                                                    Address offset: 0008h                                     */
    __IO uint32_t CFDC0ERFL;               /*!<  Channel 0 Error Flag Register                                                                Address offset: 000Ch                                     */
    __IO  uint32_t CFDGIPV;                /*!<  Global IP Version Register                                                                   Address offset: 0010h                                     */
    __IO uint32_t CFDGCFG;                 /*!<  Global Configuration Register                                                                Address offset: 0014h                                     */
    __IO  uint32_t CFDGCTR;                /*!<  Global Control Register                                                                      Address offset: 0018h                                     */
    __IO uint32_t CFDGSTS;                 /*!<  Global Status Register                                                                       Address offset: 001Ch                                     */
    __IO uint32_t CFDGERFL;                /*!<  Global Error Flag Register                                                                   Address offset: 0020h                                     */
    __IO uint32_t CFDGTSC;                 /*!<  Global Timestamp Counter Register                                                            Address offset: 0024h                                     */
    __IO uint32_t CFDGAFLECTR;             /*!<  Global Acceptance Filter List Entry Control Register                                         Address offset: 0028h                                     */
    __IO uint32_t CFDGAFLCFG;              /*!<  Global Acceptance Filter List Configuration Register                                         Address offset: 002Ch                                     */
    __IO  uint32_t CFDRMNB;                /*!<  RX Message Buffer Number Register                                                            Address offset: 0030h                                     */
    __IO  uint32_t CFDRMND;                /*!<  RX Message Buffer New Data Register                                                          Address offset: 0034h                                     */
    __IO  uint32_t CFDRMIEC;               /*!<  RX Message Buffer Interrupt Enable Configuration Register                                    Address offset: 0038h                                     */
    __IO  uint32_t CFDRFCC[2];             /*!<  RX FIFO Configuration / Control Registers a = [0:1]                                          Address offset: 003Ch + a*0004h                           */
    __IO  uint32_t CFDRFSTS[2];            /*!<  RX FIFO Status Registers a = [0:1]                                                           Address offset: 0044h + a*0004h                           */
    __IO  uint32_t CFDRFPCTR[2];           /*!<  RX FIFO Pointer Control Registers a = [0:1]                                                  Address offset: 004Ch + a*0004h                           */
    __IO  uint32_t CFDCFCC;                /*!<  Common FIFO Configuration / Control Register                                                 Address offset: 0054h                                     */
    __IO  uint32_t CFDCFSTS;               /*!<  Common FIFO Status Register                                                                  Address offset: 0058h                                     */
    __IO  uint32_t CFDCFPCTR;              /*!<  Common FIFO Pointer Control Register                                                         Address offset: 005Ch                                     */
    __IO  uint32_t CFDFESTS;               /*!<  FIFO Empty Status Register                                                                   Address offset: 0060h                                     */
    __IO  uint32_t CFDFFSTS;               /*!<  FIFO Full Status Register                                                                    Address offset: 0064h                                     */
    __IO  uint32_t CFDFMSTS;               /*!<  FIFO Message Lost Status Register                                                            Address offset: 0068h                                     */
    __IO uint32_t CFDRFISTS;               /*!<  RX FIFO Interrupt Flag Status Register                                                       Address offset: 006Ch                                     */
    __IO uint8_t  CFDTMC[4];               /*!<  TX Message Buffer Control Registers I = [0:3]                                                Address offset: 0070h + i*0001h                           */
    __IO uint8_t  CFDTMSTS[4];             /*!<  TX Message Buffer Status Registers j = [0:3]                                                 Address offset: 0074h + j*0001h                           */
    __IO uint32_t CFDTMTRSTS;              /*!<  TX Message Buffer Transmission Request Status Register                                       Address offset: 0078h                                     */
    __IO uint32_t CFDTMTARSTS;             /*!<  TX Message Buffer Transmission Abort Request Status Register                                 Address offset: 007Ch                                     */
    __IO uint32_t CFDTMTCSTS;              /*!<  TX Message Buffer Transmission Completion Status Register                                    Address offset: 0080h                                     */
    __IO uint32_t CFDTMTASTS;              /*!<  TX Message Buffer Transmission Abort Status Register                                         Address offset: 0084h                                     */
    __IO uint32_t CFDTMIEC;                /*!<  TX Message Buffer Interrupt Enable Configuration Register                                    Address offset: 0088h                                     */
    __IO uint32_t CFDTXQCC;                /*!<  TX Queue Configuration / Control Register                                                    Address offset: 008Ch                                     */
    __IO uint32_t CFDTXQSTS;               /*!<  TX Queue Status Register                                                                     Address offset: 0090h                                     */
    __IO uint32_t CFDTXQPCTR;              /*!<  TX Queue Pointer Control Register                                                            Address offset: 0094h                                     */
    __IO uint32_t CFDTHLCC;                /*!<  TX History List Configuration / Control Register                                             Address offset: 0098h                                     */
    __IO uint32_t CFDTHLSTS;               /*!<  TX History List Status Register                                                              Address offset: 009Ch                                     */
    __IO uint32_t CFDTHLPCTR;              /*!<  TX History List Pointer Control Register                                                     Address offset: 00A0h                                     */
    __IO uint32_t CFDGTINTSTS;             /*!<  Global TX Interrupt Status Register                                                          Address offset: 00A4h                                     */
    __IO uint32_t CFDGTSTCFG;              /*!<  Global Test Configuration Register                                                           Address offset: 00A8h                                     */
    __IO uint32_t CFDGTSTCTR;              /*!<  Global Test Control Register                                                                 Address offset: 00ACh                                     */
    __IO uint32_t CFDGFDCFG;               /*!<  Global FD Configuration register                                                             Address offset: 00B0h                                     */
    __IO uint32_t RSVD;                    /*!<  RSVD                                                                                         Address offset: 00B4h                                     */
    __IO uint32_t CFDGLOCKK;               /*!<  Global Lock Key Register                                                                     Address offset: 00B8h                                     */
    __IO uint32_t RSVD1;                   /*!<  RSVD                                                                                         Address offset: 00BCh                                     */
    __IO uint32_t CFDGAFLIGNENT;           /*!<  Global AFL Ignore Entry Register                                                             Address offset: 00C0h                                     */
    __IO uint32_t CFDGAFLIGNCTR;           /*!<  Global AFL Ignore Control Register                                                           Address offset: 00C4h                                     */
    __IO uint32_t CFDCDTCT;                /*!<  DMA Transfer Control Register                                                                Address offset: 00C8h                                     */
    __IO uint32_t CFDCDTSTS;               /*!<  DMA Transfer Status Register                                                                 Address offset: 00CCh                                     */
    __IO uint32_t CFDGPFLECTR;             /*!<  Pretended Network Filter List Entry control Register                                         Address offset: 00D0h                                     */
    __IO uint32_t CFDGPFLCFG;              /*!<  Pretended Network Filter List Entry Configuration Register                                   Address offset: 00D4h                                     */
    __IO uint32_t CFDGRSTC;                /*!<  Global SW reset Register                                                                     Address offset: 00D8h                                     */
    __IO uint32_t RSVD2;                   /*!<  RSVD                                                                                         Address offset: 00DCh                                     */
    __IO uint32_t CFDWKCR;                 /*!<  Global SW reset Register                                                                     Address offset: 00E0h                                     */
    __IO uint32_t CFDWKSR;                 /*!<  Global SW reset Register                                                                     Address offset: 00E4h                                     */
    __IO uint32_t RSVD3[6];                /*!<  RSVD                                                                                         Address offset: 00E8h                                     */
    __IO uint32_t CFDC0DCFG;               /*!<  Channel 0 Data Bitrate Configuration Register                                                Address offset: 0100h                                     */
    __IO uint32_t CFDC0FDCFG;              /*!<  Channel 0 CAN-FD Configuration Register                                                      Address offset: 0104h                                     */
    __IO uint32_t CFDC0FDCTR;              /*!<  Channel 0 CAN-FD Control Register                                                            Address offset: 0108h                                     */
    __IO uint32_t CFDC0FDSTS;              /*!<  Channel 0 CAN-FD Status Register                                                             Address offset: 010Ch                                     */
    __IO uint32_t CFDC0FDCRC;              /*!<  Channel 0 CAN-FD CRC Register                                                                Address offset: 0110h                                     */
    __IO uint32_t RSVD4[3];	               /*!<  RSVD                                                                                         Address offset: 0114h                                     */
    struct
    {
    __IO uint32_t CFDGAFLIDr;              /*!<  Global Acceptance Filter List ID Registers r = [1…10]h                                       Address offset: 0120h + (r-1)*0010h                      */
    __IO uint32_t CFDGAFLMr;               /*!<  Global Acceptance Filter List Mask Registers r = [1…10]h                                     Address offset: 0124h + (r-1)*0010h                      */
    __IO uint32_t CFDGAFLP0r;              /*!<  Global Acceptance Filter List Pointer 0 Registers r = [1…10]h                                Address offset: 0128h + (r-1)*0010h                      */
    __IO uint32_t CFDGAFLP1r;              /*!<  Global Acceptance Filter List Pointer 1 Registers r = [1…10]h                                Address offset: 012Ch + (r-1)*0010h                      */
    }CFDGAFL[16];
    struct
    {
    __IO uint32_t CFDGPFLIDs;              /*!<  Global Pretended Network Filter List ID Registers s = [1…2]h                                 Address offset: 0220h + (s-1) * 0024h                    */
    __IO uint32_t CFDGPFLMs;               /*!<  Global Pretended Network Filter List Mask Registers s = [1…2]h                               Address offset: 0224h + (s-1) * 0024h                    */
    __IO uint32_t CFDGPFLP0s;              /*!<  Global Pretended Network Filter List Pointer 0 Registers s = [1…2]h                          Address offset: 0228h + (s-1) * 0024h                    */
    __IO uint32_t CFDGPFLP1s;              /*!<  Global Pretended Network Filter List Pointer 1 Registers s = [1…2]h                          Address offset: 022Ch + (s-1) * 0024h                    */ 
    __IO uint32_t CFDGPFLPTs;              /*!<  Global Pretended Network Filter List Filter Payload Type Registers s = [1…2]h                Address offset: 0230h + (s-1) * 0024h                    */        
    __IO uint32_t CFDGPFLPD0s;             /*!<  Global Pretended Network Filter List Payload Data 0 Registers s = [1…2]                      Address offset: 0234h + (s-1) * 0024h                    */        
    __IO uint32_t CFDGPFLPM0s;             /*!<  Global Pretended Network Filter List Payload Mask 0 Registers s = [1…2]h                     Address offset: 0238h + (s-1) * 0024h                    */        
    __IO uint32_t CFDGPFLPD1s;             /*!<  Global Pretended Network Filter List Payload Data 1 Registers s = [1…2]h                     Address offset: 023Ch + (s-1) * 0024h                    */        
    __IO uint32_t CFDGPFLPM1s;             /*!<  Global Pretended Network Filter List Payload Mask 1 Registers s = [1…2]h                     Address offset: 0240h + (s-1) * 0024h                    */        
    }CFDGPFL[2];
    __IO uint32_t RSVD5[6];                /*!<  RSVD                                                                                         Address offset: 0268h                                    */
    __IO uint32_t CFDRPGACC[64];           /*!<  RAM Test Page Access Registers k = [0…3F]h                                                   Address offset: 0280h + k * 0004h                        */
}CANFD_COMMON_Type;


/* ================================================================================ */
/* ================                     CANFDx_RX_FIFO             ================ */
/* ================================================================================ */

typedef struct
{
  struct
  {
    __IO uint32_t CFDRFIDb;             /*!<  RX FIFO Access ID Registers b = [0＃1]h,                                         Address offset: 0520h + b * 004Ch             */
    __IO uint32_t CFDRFPTRb;            /*!<  RX FIFO Access Pointer Registers b = [0＃1]h,                                    Address offset: 0524h + b * 004Ch             */
    __IO uint32_t CFDRFFDSTSb;          /*!<  RX FIFO Access CAN-FD Status Registers b = [0＃1]h,                              Address offset: 0528h + b * 004Ch             */
    __IO uint32_t CFDRFDFbp[16];        /*!<  RX FIFO Access Data Field p Registers b = [0＃1]h p = [0＃F]h,                   Address offset: 052Ch + p * 0004h + b * 004Ch */
  }CFDRF[2];
}CANFD_RX_FIFO_Type;

/* ================================================================================ */
/* ================                     CANFDx_Common_FIFO             ================ */
/* ================================================================================ */

typedef struct
{
  __IO uint32_t CFDCFID;                /*!<  Common FIFO Access ID Register,                                                  Address offset: 05B8h                         */
  __IO uint32_t CFDCFPTR;               /*!<  Common FIFO Access Pointer Register,                                             Address offset: 05BCh                         */
  __IO uint32_t CFDCFFDCSTS;            /*!<  Common FIFO Access CAN-FD Control/Status Register,                               Address offset: 05C0h                         */
  __IO uint32_t CFDCFDFp[16];           /*!<  Common FIFO Access Data Field p Registers p = [0＃F]h,                           Address offset: 05C4h + p * 0004h             */
}CANFD_COMMON_FIFO_Type;

/* ================================================================================ */
/* ================                     CANFDx_TX_MESSAGE          ================ */
/* ================================================================================ */

typedef struct
{
   struct
   {
     __IO uint32_t CFDTMIDb;             /*!<  TX Message Buffer ID Registers b = [0＃3]h,                                      Address offset: 0604h + b * 004Ch             */
     __IO uint32_t CFDTMPTRb;            /*!<  TX Message Buffer Pointer Registers b = [0＃3]h,                                 Address offset: 0608h + b * 004Ch             */
     __IO uint32_t CFDTMFDCTRb;          /*!<  TX Message Buffer CAN-FD Control Registers b = [0＃3]h,                          Address offset: 060Ch + b * 004Ch             */
     __IO uint32_t CFDTMDFbp[16];        /*!<  TX Message Buffer Data Field p Registers b = [0＃3]h p = [0＃F]h,                Address offset: 0610h + p * 0004h + b * 004Ch */
   }CFDTM[4];
}CANFD_TX_MESSAGE_Type;

/* ================================================================================ */
/* ================                     CANFDx_TX_HISTORY_LIST          ================ */
/* ================================================================================ */

typedef struct
{
  __IO uint32_t CFDTHLACC0;             /*!<  Channel 0 TX History List Access Registers 0,                                    Address offset: 0740h                         */
  __IO uint32_t CFDTHLACC1;             /*!<  Channel 0 TX History List Access Registers 1,                                    Address offset: 0744h                         */
}CANFD_TX_HISTORY_LIST_Type;


/* ================================================================================ */
/* ================                     CANFDx_RX_MESSAGE          ================ */
/* ================================================================================ */

typedef struct
{
  struct
  {
    __IO uint32_t CFDRMIDb;             /*!<  RX Message Buffer ID Registers b = [0＃7]h,                                      Address offset: 0920h + b * 004Ch             */
    __IO uint32_t CFDRMPTRb;            /*!<  RX Message Buffer Pointer Registers b = [0＃7]h,                                 Address offset: 0924h + b * 004Ch             */
    __IO uint32_t CFDRMFDSTSb;          /*!<  RX Message Buffer CAN-FD Status Registers b = [0＃7]h,                           Address offset: 0928h + b * 004Ch             */
    __IO uint32_t CFDRMDFbp[16];        /*!<  RX Message Buffer Data Field p Registers b = [0＃7]h p = [0＃F]h,                Address offset: 092Ch + p * 0004h + b * 004Ch */
  }CFDRM[8];
}CANFD_RX_MESSAGE_Type;


/* ================================================================================ */
/* ================                       CLM                      ================ */
/* ================================================================================ */


/**
  * @brief CLM0 module information (CLM)
  */

typedef struct {                                    /*!< CLM Structure                                                         */
  __IO uint32_t  CR;                                /*!< CR Register                                                           */
  __IO uint32_t  CFGR;                              /*!< CFGR Register                                                         */
  __IO uint32_t  CNTR;                              /*!< CNTR Register                                                         */
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
  __IO uint32_t  CMPH;                              /*!< CMPH Register                                                         */
  __IO uint32_t  CMPL;                              /*!< CMPL Register                                                         */
  __IO uint32_t  TOCFGR;                            /*!< TOCFGR Register                                                       */
} CLM_Type;


/* ================================================================================ */
/* ================                       CMU                      ================ */
/* ================================================================================ */


/**
  * @brief CMU module information (CMU)
  */

typedef struct {                                    /*!< CMU Structure                                                         */
  __IO uint32_t  SYSCLKCR;                          /*!< SYSCLKSEL Register                                                    */
  __IO uint32_t  RCHFCR;                            /*!< RCHFCR Register                                                       */
  __IO uint32_t  RCHFTR;                            /*!< RCHFTR Register                                                       */
  __IO uint32_t  PLLCR;                             /*!< PLLCR Register                                                        */
  __IO uint32_t  RCLPCR;                            /*!< RCLPCR Register                                                       */
  __IO uint32_t  RCLPTR;                            /*!< RCLPTR Register                                                       */
  __IO uint32_t  XTLFCR;                            /*!< XTLFCR Register                                                       */
  __IO uint32_t  LSCLKSEL;                          /*!< LSCLKSEL Register                                                     */
  __IO uint32_t  XTHFCR;                            /*!< XTHFCR Register                                                       */
  __I  uint32_t  RESERVED[2];
  __IO uint32_t  IER;                               /*!< IER Register                                                          */
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
  __IO uint32_t  PCLKCR1;                           /*!< PCLKCR1 Register                                                      */
  __IO uint32_t  PCLKCR2;                           /*!< PCLKCR2 Register                                                      */
  __IO uint32_t  PCLKCR3;                           /*!< PCLKCR3 Register                                                      */
  __IO uint32_t  PCLKCR4;                           /*!< PCLKCR4 Register                                                      */
  __IO uint32_t  OPCCR1;                            /*!< OPCCR1 Register                                                       */
  __IO uint32_t  OPCCR2;                            /*!< OPCCR2 Register                                                       */
  __IO uint32_t  OPCER1;                            /*!< OPCER1 Register                                                       */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  MPRIL;                             /*!< MPRIL Register                                                        */
  __I  uint32_t  RESERVED2[10];
  __IO uint32_t  CFDCR;                             /*!< CFDCR Register                                                        */
  __IO uint32_t  CFDER;                             /*!< CFDER Register                                                        */
} CMU_Type;


/* ================================================================================ */
/* ================                      COMP                      ================ */
/* ================================================================================ */


/**
  * @brief COMP module information (COMP)
  */

typedef struct {     
  __IO  uint32_t  CR;                               /*!< COMPCR Register                                                      */
} COMP_Type;


typedef struct {                                    /*!< COMP Structure                                                        */
  __IO uint32_t  ICR;                               /*!< ICR Register                                                          */
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
  __IO uint32_t  BUFCR;                             /*!< BUFCR Register                                                        */
} COMP_COMMON_Type;


/* ================================================================================ */
/* ================                       CRC                      ================ */
/* ================================================================================ */


/**
  * @brief CRC module information (CRC)
  */

typedef struct {                                    /*!< CRC Structure                                                         */
  __IO uint32_t  DR;                                /*!< DR Register                                                           */
  __IO uint32_t  CR;                                /*!< CR Register                                                           */
  __IO uint32_t  LFSR;                              /*!< LFSR Register                                                         */
  __IO uint32_t  XOR;                               /*!< XOR Register                                                          */
  __I  uint32_t  RESERVED[3];
  __IO uint32_t  POLY;                              /*!< POLY Register                                                         */
} CRC_Type;


/* ================================================================================ */
/* ================                       DAC                      ================ */
/* ================================================================================ */


/**
  * @brief DAC module information (DAC)
  */

typedef struct {                                    /*!< DAC Structure                                                         */
  __IO uint32_t  CR1;                               /*!< CR1 Register                                                          */
  __IO uint32_t  CR2;                               /*!< CR2 Register                                                          */
  __IO uint32_t  CFGR;                              /*!< CFGR Register                                                         */
  __IO uint32_t  SWTRGR;                            /*!< SWTRGR Register                                                       */
  __IO uint32_t  DHR;                               /*!< DHR Register                                                          */
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
  __IO uint32_t  IER;                               /*!< IER Register                                                          */
  __IO uint32_t  SHTR;                              /*!< SHTR Register                                                         */
} DAC_Type;


/* ================================================================================ */
/* ================                       DMA                      ================ */
/* ================================================================================ */


/**
  * @brief DMA module information (DMA)
  */

typedef struct {                                    /*!< DMA Structure                                                         */
  __IO uint32_t  CH0CR;                             /*!< CH0CR Register                                                        */
  __IO uint32_t  CH0CFGR;                           /*!< CH0CFGR Register                                                      */
  __IO uint32_t  CH0PAR;                            /*!< CH0PAR Register                                                       */
  __IO uint32_t  CH0MAR0;                           /*!< CH0MAR0 Register                                                      */
  __IO uint32_t  CH0MAR1;                           /*!< CH0MAR1 Register                                                      */
  __I  uint32_t  RESERVED[3];
  __IO uint32_t  CH1CR;                             /*!< CH1CR Register                                                        */
  __IO uint32_t  CH1CFGR;                           /*!< CH1CFGR Register                                                      */
  __IO uint32_t  CH1PAR;                            /*!< CH1PAR Register                                                       */
  __IO uint32_t  CH1MAR0;                           /*!< CH1MAR0 Register                                                      */
  __IO uint32_t  CH1MAR1;                           /*!< CH1MAR1 Register                                                      */
  __I  uint32_t  RESERVED1[3];
  __IO uint32_t  CH2CR;                             /*!< CH2CR Register                                                        */
  __IO uint32_t  CH2CFGR;                           /*!< CH2CFGR Register                                                      */
  __IO uint32_t  CH2PAR;                            /*!< CH2PAR Register                                                       */
  __IO uint32_t  CH2MAR0;                           /*!< CH2MAR0 Register                                                      */
  __IO uint32_t  CH2MAR1;                           /*!< CH2MAR1 Register                                                      */
  __I  uint32_t  RESERVED2[3];
  __IO uint32_t  CH3CR;                             /*!< CH3CR Register                                                        */
  __IO uint32_t  CH3CFGR;                           /*!< CH3CFGR Register                                                      */
  __IO uint32_t  CH3PAR;                            /*!< CH3PAR Register                                                       */
  __IO uint32_t  CH3MAR0;                           /*!< CH3MAR0 Register                                                      */
  __IO uint32_t  CH3MAR1;                           /*!< CH3MAR1 Register                                                      */
  __I  uint32_t  RESERVED3[27];
  __IO uint32_t  CH7CR;                             /*!< CH7CR Register                                                        */
  __IO uint32_t  CH7FLSAR;                          /*!< CH7FLSAR Register                                                     */
  __IO uint32_t  CH7RAMAR;                          /*!< CH7RAMAR Register                                                     */
  __I  uint32_t  RESERVED4[69];
  __IO uint32_t  GCR;                               /*!< GCR Register                                                          */
  __IO uint32_t  SWRR;                              /*!< SWRR Register                                                         */
  __I  uint32_t  RESERVED5[62];
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
  __IO uint32_t  CH0TFSADDR;                        /*!< CH0TFSADDR Register                                                   */
  __IO uint32_t  CH1TFSADDR;                        /*!< CH1TFSADDR Register                                                   */
  __IO uint32_t  CH2TFSADDR;                        /*!< CH2TFSADDR Register                                                   */
  __IO uint32_t  CH3TFSADDR;                        /*!< CH3TFSADDR Register                                                   */
} DMA_Type;


/* ================================================================================ */
/* ================                       FLASH                      ================ */
/* ================================================================================ */


/**
  * @brief FLASH module information (FLASH)
  */

typedef struct {                                    /*!< FLS Structure                                                         */
  __IO uint32_t  RDCR;                              /*!< RDCR Register                                                         */
  __IO uint32_t  PFCR;                              /*!< PFCR Register                                                         */
  __IO uint32_t  OPTBR;                             /*!< OPTBR Register                                                        */
  __I  uint32_t  RESERVED[2];
  __IO uint32_t  CEPCR;                             /*!< CEPCR Register                                                        */
  __IO uint32_t  CKEY;                              /*!< CKEY Register                                                         */
  __IO uint32_t  CIER;                              /*!< CIER Register                                                         */
  __IO uint32_t  CISR;                              /*!< CISR Register                                                         */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  ECCSR;                             /*!< ECCSR Register                                                        */                    
  __IO uint32_t  ECCIER;                            /*!< ECCIER Register                                                       */
  __IO uint32_t  ECCEAR;                            /*!< ECCEAR Register                                                       */  
  __I  uint32_t  RESERVED3;
  __IO uint32_t  ECCCR;                             /*!< ECCCR Register                                                        */  
  __I  uint32_t  RESERVED4[9];   
  __IO uint32_t  ACLOCK1;                           /*!< ACLOCK1 Register                                                      */
  __IO uint32_t  ACLOCK2;                           /*!< ACLOCK2 Register                                                      */
  __IO uint32_t  ACLOCK3;                           /*!< ACLOCK3 Register                                                      */
  __I  uint32_t  RESERVED5[9];
  __IO uint32_t  DEPCR;                             /*!< DEPCR Register                                                        */
  __IO uint32_t  DKEY;                              /*!< DKEY Register                                                         */
  __IO uint32_t  DIER;                              /*!< DIER Register                                                         */
  __IO uint32_t  DISR;                              /*!< DISR Register                                                         */
} FLASH_Type;


/* ================================================================================ */
/* ================                   GPIO_COMMON                  ================ */
/* ================================================================================ */


/**
  * @brief GPIO module information (GPIO_COMMON)
  */

typedef struct {                                    /*!< GPIO_COMMON Structure                                                 */
  __IO uint32_t  EXTIEDSA;                          /*!< EXTIEDSA Register                                                     */
  __IO uint32_t  EXTIEDSB;                          /*!< EXTIEDSB Register                                                     */
  __IO uint32_t  EXTIEDSC;                          /*!< EXTIEDSC Register                                                     */
  __IO uint32_t  EXTIEDSD;                          /*!< EXTIEDSD Register                                                     */
  __IO uint32_t  EXTIEDSE;                          /*!< EXTIEDSE Register                                                     */
  __IO uint32_t  EXTIEDSF;                          /*!< EXTIEDSF Register                                                     */
  __IO uint32_t  EXTIEDSG;                          /*!< EXTIEDSG Register                                                     */
  __I  uint32_t  RESERVED[2];
  __IO uint32_t  EXTIDFAB;                          /*!< EXTIDFAB Register                                                     */
  __IO uint32_t  EXTIDFCD;                          /*!< EXTIDFCD Register                                                     */
  __IO uint32_t  EXTIDFEF;                          /*!< EXTIDFEF Register                                                     */
  __IO uint32_t  EXTIDFGH;                          /*!< EXTIDFGH Register                                                     */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  EXTIISRAB;                          /*!< EXTIIFAB Register                                                     */
  __IO uint32_t  EXTIISRCD;                          /*!< EXTIIFCD Register                                                     */
  __IO uint32_t  EXTIISREF;                          /*!< EXTIIFEF Register                                                     */
  __IO uint32_t  EXTIISRGH;                          /*!< EXTIIFGH Register                                                     */
  __I  uint32_t  RESERVED2;
  __IO uint32_t  EXTIDIAB;                         /*!< EXTI_DIAB Register                                                    */
  __IO uint32_t  EXTIDICD;                          /*!< EXTIDICD Register                                                     */
  __IO uint32_t  EXTIDIEF;                          /*!< EXTIDIEF Register                                                     */
  __IO uint32_t  EXTIDIGH;                          /*!< EXTIDIGH Register                                                     */
  __I  uint32_t  RESERVED3[9];
  __IO uint32_t  FOUTSEL;                           /*!< FOUTSEL Register                                                      */
  __I  uint32_t  RESERVED4[22];
  __IO uint32_t  PINWKEN;                           /*!< PINWKEN Register                                                      */
} GPIO_COMMON_Type;


/* ================================================================================ */
/* ================                      GPIO                      ================ */
/* ================================================================================ */


/**
  * @brief GPIOA module information (GPIO)
  */

typedef struct {                                    /*!< GPIO Structure                                                        */
  __IO uint32_t  INEN;                              /*!< INEN Register                                                         */
  __IO uint32_t  PUDEN;                            /*!< PUPDEN Register                                                       */
  __IO uint32_t  ODEN;                              /*!< ODEN Register                                                         */
  __IO uint32_t  FCR;                               /*!< FCR Register                                                          */
  __IO uint32_t  DO;                                /*!< DO Register                                                           */
  __IO uint32_t  DSET;                              /*!< DSET Register                                                         */
  __IO uint32_t  DRST;                              /*!< DRST Register                                                         */
  __IO uint32_t  DIN;                               /*!< DIN Register                                                          */
  __IO uint32_t  DFS;                               /*!< DFS Register                                                          */
  __I  uint32_t  RESERVED[2];
  __IO uint32_t  DSR;                               /*!< DSR Register                                                          */
  __I  uint32_t  RESERVED1[4];
} GPIO_Type;


/* ================================================================================ */
/* ================                       I2C                      ================ */
/* ================================================================================ */


/**
  * @brief I2C0 module information (I2C)
  */

typedef struct {                                    /*!< I2C Structure                                                         */
  __IO uint32_t  MSPCFGR;                           /*!< MSPCFGR Register                                                      */
  __IO uint32_t  MSPCR;                             /*!< MSPCR Register                                                        */
  __IO uint32_t  MSPIER;                            /*!< MSPIER Register                                                       */
  __IO uint32_t  MSPISR;                            /*!< MSPISR Register                                                       */
  __IO uint32_t  MSPSR;                             /*!< MSPSR Register                                                        */
  __IO uint32_t  MSPBGR;                            /*!< MSPBRG Register                                                       */
  __IO uint32_t  MSPBUF;                            /*!< MSPBUF Register                                                       */
  __IO uint32_t  MSPTCR;                            /*!< MSPTCR Register                                                       */
  __IO uint32_t  MSPTOR;                            /*!< MSPTOR Register                                                       */
} I2C_Type;


/* ================================================================================ */
/* ================                     INTMUX                     ================ */
/* ================================================================================ */


/**
  * @brief INTMUX module information (INTMUX)
  */

typedef struct {                                    /*!< INTMUX Structure                                                      */
  __IO uint32_t  CR1;                               /*!< CR1 Register                                                          */
  __IO uint32_t  CR2;                               /*!< CR2 Register                                                          */
} INTMUX_Type;


/* ================================================================================ */
/* ================                      IWDT                      ================ */
/* ================================================================================ */


/**
  * @brief IWDT module information (IWDT)
  */

typedef struct {                                    /*!< IWDT Structure                                                        */
  __IO uint32_t  SERV;                              /*!< SERV Register                                                         */
  __IO uint32_t  CR;                                /*!< CR Register                                                           */
  __IO uint32_t  CNT;                               /*!< CNT Register                                                          */
  __IO uint32_t  WIN;                               /*!< WIN Register                                                          */
  __IO uint32_t  IER;                               /*!< IER Register                                                          */
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
} IWDT_Type;


/* ================================================================================ */
/* ================                     LPTIM16                    ================ */
/* ================================================================================ */


/**
  * @brief LPTIM16 module information (LPTIM16)
  */

typedef struct {                                    /*!< LPTIM16 Structure                                                     */
  __IO uint32_t  CFGR;                              /*!< CFGR Register                                                         */
  __IO uint32_t  CNT;                               /*!< CNT Register                                                          */
  __IO uint32_t  CCSR;                              /*!< CCSR Register                                                         */
  __IO uint32_t  ARR;                               /*!< ARR Register                                                          */
  __IO uint32_t  IER;                               /*!< IER Register                                                          */
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
  __IO uint32_t  CR;                                /*!< CR Register                                                           */
  __I  uint32_t  RESERVED;
  __IO uint32_t  CCR1;                              /*!< CCR1 Register                                                         */
  __IO uint32_t  CCR2;                              /*!< CCR2 Register                                                         */
} LPTIM16_Type;


/* ================================================================================ */
/* ================                     LPUART                     ================ */
/* ================================================================================ */


/**
  * @brief LPUART module information (LPUART)
  */

typedef struct {                                    /*!< LPUART Structure                                                      */
  __IO uint32_t  CSR;                               /*!< CSR Register                                                          */
  __IO uint32_t  IER;                               /*!< IER Register                                                          */
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
  __IO uint32_t  BMR;                               /*!< BMR Register                                                          */
  __IO uint32_t  RXBUF;                             /*!< RXBUF Register                                                        */
  __IO uint32_t  TXBUF;                             /*!< TXBUF Register                                                        */
  __IO uint32_t  DMR;                               /*!< DMR Register                                                          */
} LPUART_Type;


/* ================================================================================ */
/* ================                       PMU                      ================ */
/* ================================================================================ */


/**
  * @brief PMU module information (PMU)
  */

typedef struct {                                    /*!< PMU Structure                                                         */
  __IO uint32_t  CR;                                /*!< CR Register                                                           */
  __IO uint32_t  WKTR;                              /*!< WKTR Register                                                         */
  __IO uint32_t  WKFR;                              /*!< WKFR Register                                                         */
  __IO uint32_t  IER;                               /*!< IER Register                                                          */
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
  __I  uint32_t  RESERVED[10];
  __IO uint32_t  BUFCR;                             /*!< BUFCR Register                                                        */
  __I  uint32_t  RESERVED1[4];
  __IO uint32_t  PTATCR;                            /*!< PTATCR Register                                                       */
} PMU_Type;


/* ================================================================================ */
/* ================                      QSPI                      ================ */
/* ================================================================================ */


/**
  * @brief QSPI module information (QSPI)
  */

typedef struct {                                    /*!< QSPI Structure                                                        */
  __IO uint32_t  CR;                                /*!< CR Register                                                           */
  __IO uint32_t  CFGR;                              /*!< CFGR Register                                                         */
  __IO uint32_t  SR;                                /*!< SR Register                                                           */
  __IO uint32_t  DATALEN;                           /*!< DATALEN Register                                                      */
  __IO uint32_t  CCR;                               /*!< CCR Register                                                          */
  __IO uint32_t  ADDR;                              /*!< ADDR Register                                                         */
  __IO uint32_t  ABR;                               /*!< ABR Register                                                          */
  __IO uint32_t  DR;                                /*!< DR Register                                                         */
  __IO uint32_t  SMSK;                              /*!< SMSK Register                                                         */
  __IO uint32_t  SMAT;                              /*!< SMAT Register                                                         */
  __IO uint32_t  PITV;                              /*!< PITV Register                                                         */
  __IO uint32_t  TOR;                               /*!< TOR Register                                                          */
} QSPI_Type;


/* ================================================================================ */
/* ================                     RAMBIST                    ================ */
/* ================================================================================ */


/**
  * @brief RAMBIST module information (RAMBIST)
  */

typedef struct {                                    /*!< RAMBIST Structure                                                     */
  __IO uint32_t  RAMBISTCR;                         /*!< RAMBISTCR Register                                                    */
  __IO uint32_t  RAMFF;                             /*!< RAMFF Register                                                        */
} RAMBIST_Type;


/* ================================================================================ */
/* ================                       RMU                      ================ */
/* ================================================================================ */


/**
  * @brief RMU module information (RMU)
  */

typedef struct {                                    /*!< RMU Structure                                                         */
  __IO uint32_t  PDRCR;                             /*!< PDRCR Register                                                        */
  __I  uint32_t  RESERVED;
  __IO uint32_t  RSTCR;                             /*!< RSTCR Register                                                        */
  __IO uint32_t  SOFTRST;                           /*!< SOFTRST Register                                                      */
  __IO uint32_t  RSTFR;                             /*!< RSTFR Register                                                        */
  __IO uint32_t  PRSTEN;                            /*!< PRSTEN Register                                                       */
  __IO uint32_t  AHBRSTCR;                          /*!< AHBRSTCR Register                                                     */
  __IO uint32_t  APBRSTCR1;                         /*!< APBRSTCR1 Register                                                    */
  __IO uint32_t  APBRSTCR2;                         /*!< APBRSTCR2 Register                                                    */
} RMU_Type;


/* ================================================================================ */
/* ================                       RTC                      ================ */
/* ================================================================================ */


/**
  * @brief RTC module information (RTC)
  */

typedef struct {                                    /*!< RTC Structure                                                         */
  __IO uint32_t  WER;                               /*!< WER Register                                                          */
  __IO uint32_t  IER;                               /*!< IER Register                                                          */
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
  __IO uint32_t  BCDSEC;                            /*!< BCDSEC Register                                                       */
  __IO uint32_t  BCDMIN;                            /*!< BCDMIN Register                                                       */
  __IO uint32_t  BCDHOUR;                           /*!< BCDHOUR Register                                                      */
  __IO uint32_t  BCDDAY;                            /*!< BCDDAY Register                                                       */
  __IO uint32_t  BCDWEEK;                           /*!< BCDWEEK Register                                                      */
  __IO uint32_t  BCDMONTH;                          /*!< BCDMONTH Register                                                     */
  __IO uint32_t  BCDYEAR;                           /*!< BCDYEAR Register                                                      */
  __IO uint32_t  ALARM;                             /*!< ALARM Register                                                        */
  __IO uint32_t  TMSEL;                             /*!< TMSEL Register                                                        */
  __IO uint32_t  ADJUST;                            /*!< ADJUST Register                                                       */
  __I  uint32_t  RESERVED[2];
  __IO uint32_t  MSECCNT;                           /*!< MSECCNT Register                                                      */
  __IO uint32_t  CR;                                /*!< CR Register                                                      */
} RTC_Type;


/* ================================================================================ */
/* ================                       SCU                      ================ */
/* ================================================================================ */


/**
  * @brief SCU module information (SCU)
  */

typedef struct {                                    /*!< SCU Structure                                                         */
  __IO uint32_t  SYSCFG;                            /*!< SYSCFG Register                                                       */
  __IO uint32_t  DBGCR;                             /*!< DBGCR Register                                                        */
  __IO uint32_t  HDFFLAG;                           /*!< HDFFLAG Register                                                      */
} SCU_Type;


/* ================================================================================ */
/* ================                      SENT                      ================ */
/* ================================================================================ */


/**
  * @brief SENT0 module information (SENT)
  */

typedef struct {                                    /*!< SENT Structure                                                        */
  __IO uint32_t  CR;                                /*!< CR Register                                                           */
  __IO uint32_t  CFGR;                              /*!< CFGR Register                                                         */
  __IO uint32_t  PSR;                               /*!< PSR Register                                                          */
  __IO uint32_t  FTR;                               /*!< FTR Register                                                          */
  __IO uint32_t  SR;                                /*!< SR Register                                                           */
  __IO uint32_t  DR;                                /*!< DR Register                                                           */
  __IO uint32_t  SYNC;                              /*!< SYNC Register                                                         */
  __IO uint32_t  RCAL;                              /*!< RCAL Register                                                         */
} SENT_Type;


/* ================================================================================ */
/* ================                       SFU                      ================ */
/* ================================================================================ */


/**
  * @brief SFU module information (SFU)
  */

typedef struct {                                    /*!< SFU Structure                                                         */
  __IO uint32_t  RAMPCR;                            /*!< RAMPCR Register                                                       */
  __IO uint32_t  RAMPSR;                            /*!< RAMPSR Register                                                       */
  __IO uint32_t  MAPCR;                             /*!< MAPCR Register                                                        */
  __IO uint32_t  MAPISR;                            /*!< MAPISR Register                                                       */
} SFU_Type;


/* ================================================================================ */
/* ================                       SPI                      ================ */
/* ================================================================================ */


/**
  * @brief SPI0 module information (SPI)
  */

typedef struct {                                    /*!< SPI Structure                                                         */
  __IO uint32_t  CR1;                               /*!< CR1 Register                                                          */
  __IO uint32_t  CR2;                               /*!< CR2 Register                                                          */
  __IO uint32_t  CR3;                               /*!< CR3 Register                                                          */
  __IO uint32_t  IER;                               /*!< IER Register                                                          */
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
  __IO uint32_t  TXBUF;                             /*!< TXBUF Register                                                        */
  __IO uint32_t  RXBUF;                             /*!< RXBUF Register                                                        */
  __I  uint32_t  RESERVED;
  __IO uint32_t  I2SCR;                             /*!< I2SCR Register                                                        */
  __IO uint32_t  I2SPR;                             /*!< I2SPR Register                                                        */
} SPI_Type;


/* ================================================================================ */
/* ================                       SVD                      ================ */
/* ================================================================================ */


/**
  * @brief SVD module information (SVD)
  */

typedef struct {                                    /*!< SVD Structure                                                         */
  __IO uint32_t  CFGR;                              /*!< CFGR Register                                                         */
  __IO uint32_t  CR;                                /*!< CR Register                                                           */
  __IO uint32_t  IER;                               /*!< IER Register                                                          */
  __IO uint32_t  ISR;                           /*!< SVD_ISR Register                                                      */
  __IO uint32_t  VSR;                               /*!< VSR Register                                                          */
} SVD_Type;


/* ================================================================================ */
/* ================                      TAU                       ================ */
/* ================================================================================ */


/**
  * @brief TAU module information (TAU)
  */

typedef struct {                                    /*!< TAU Structure                                                         */
  __IO uint32_t TAU0CR;                             /*!< TAU0 Control Register                                                 */
  __IO uint32_t TAU1CR;                             /*!< TAU1 Control Register                                                 */
}TAU_COMMON_Type;



/* ================================================================================ */
/* ================                      TAU0                      ================ */
/* ================================================================================ */


/**
  * @brief TAU0 module information (TAU0)
  */

typedef struct {                                    /*!< TAU0 Structure                                                        */
  __IO uint32_t  T0CFGR;                            /*!< T0CFGR Register                                                       */
  __IO uint32_t  T1CFGR;                            /*!< T1CFGR Register                                                       */
  __IO uint32_t  T2CFGR;                            /*!< T2CFGR Register                                                       */
  __IO uint32_t  T3CFGR;                            /*!< T3CFGR Register                                                       */
  __IO uint32_t  T4CFGR;                            /*!< T4CFGR Register                                                       */
  __IO uint32_t  T5CFGR;                            /*!< T5CFGR Register                                                       */
  __IO uint32_t  T6CFGR;                            /*!< T6CFGR Register                                                       */
  __IO uint32_t  T7CFGR;                            /*!< T7CFGR Register                                                       */
  __IO uint32_t  T0MDR;                             /*!< T0MDR Register                                                        */
  __IO uint32_t  T1MDR;                             /*!< T1MDR Register                                                        */
  __IO uint32_t  T2MDR;                             /*!< T2MDR Register                                                        */
  __IO uint32_t  T3MDR;                             /*!< T3MDR Register                                                        */
  __IO uint32_t  T4MDR;                             /*!< T4MDR Register                                                        */
  __IO uint32_t  T5MDR;                             /*!< T5MDR Register                                                        */
  __IO uint32_t  T6MDR;                             /*!< T6MDR Register                                                        */
  __IO uint32_t  T7MDR;                             /*!< T7MDR Register                                                        */
  __IO uint32_t  T0ARR;                             /*!< T0ARR Register                                                        */
  __IO uint32_t  T1ARR;                             /*!< T1ARR Register                                                        */
  __IO uint32_t  T2ARR;                             /*!< T2ARR Register                                                        */
  __IO uint32_t  T3ARR;                             /*!< T3ARR Register                                                        */
  __IO uint32_t  T4ARR;                             /*!< T4ARR Register                                                        */
  __IO uint32_t  T5ARR;                             /*!< T5ARR Register                                                        */
  __IO uint32_t  T6ARR;                             /*!< T6ARR Register                                                        */
  __IO uint32_t  T7ARR;                             /*!< T7ARR Register                                                        */
  __IO uint32_t  T0CCR;                             /*!< T0CCR Register                                                        */
  __IO uint32_t  T1CCR;                             /*!< T1CCR Register                                                        */
  __IO uint32_t  T2CCR;                             /*!< T2CCR Register                                                        */
  __IO uint32_t  T3CCR;                             /*!< T3CCR Register                                                        */
  __IO uint32_t  T4CCR;                             /*!< T4CCR Register                                                        */
  __IO uint32_t  T5CCR;                             /*!< T5CCR Register                                                        */
  __IO uint32_t  T6CCR;                             /*!< T6CCR Register                                                        */
  __IO uint32_t  T7CCR;                             /*!< T7CCR Register                                                        */
  __IO uint32_t  T0IER;                             /*!< T0IER Register                                                        */
  __IO uint32_t  T1IER;                             /*!< T1IER Register                                                        */
  __IO uint32_t  T2IER;                             /*!< T2IER Register                                                        */
  __IO uint32_t  T3IER;                             /*!< T3IER Register                                                        */
  __IO uint32_t  T4IER;                             /*!< T4IER Register                                                        */
  __IO uint32_t  T5IER;                             /*!< T5IER Register                                                        */
  __IO uint32_t  T6IER;                             /*!< T6IER Register                                                        */
  __IO uint32_t  T7IER;                             /*!< T7IER Register                                                        */
  __IO uint32_t  T0ISR;                             /*!< T0ISR Register                                                        */
  __IO uint32_t  T1ISR;                             /*!< T1ISR Register                                                        */
  __IO uint32_t  T2ISR;                             /*!< T2ISR Register                                                        */
  __IO uint32_t  T3ISR;                             /*!< T3ISR Register                                                        */
  __IO uint32_t  T4ISR;                             /*!< T4ISR Register                                                        */
  __IO uint32_t  T5ISR;                             /*!< T5ISR Register                                                        */
  __IO uint32_t  T6ISR;                             /*!< T6ISR Register                                                        */
  __IO uint32_t  T7ISR;                             /*!< T7ISR Register                                                        */
  __IO uint32_t  T0CNTR;                            /*!< T0CNT Register                                                        */
  __IO uint32_t  T1CNTR;                            /*!< T1CNT Register                                                        */
  __IO uint32_t  T2CNTR;                            /*!< T2CNT Register                                                        */
  __IO uint32_t  T3CNTR;                            /*!< T3CNT Register                                                        */
  __IO uint32_t  T4CNTR;                            /*!< T4CNT Register                                                        */
  __IO uint32_t  T5CNTR;                            /*!< T5CNT Register                                                        */
  __IO uint32_t  T6CNTR;                            /*!< T6CNT Register                                                        */
  __IO uint32_t  T7CNTR;                            /*!< T7CNT Register                                                        */
} TAU0_Type;



/* ================================================================================ */
/* ================                      TAU1                      ================ */
/* ================================================================================ */


/**
  * @brief TAU1 module information (TAU1)
  */

typedef struct {                                    /*!< TAU1 Structure                                                        */
  __IO uint32_t  T0CFGR;                            /*!< T0CFGR Register                                                       */
  __IO uint32_t  T1CFGR;                            /*!< T1CFGR Register                                                       */
  __IO uint32_t  T2CFGR;                            /*!< T2CFGR Register                                                       */
  __IO uint32_t  T3CFGR;                            /*!< T3CFGR Register                                                       */
  __IO uint32_t  T4CFGR;                            /*!< T4CFGR Register                                                       */
  __IO uint32_t  T5CFGR;                            /*!< T5CFGR Register                                                       */
  __IO uint32_t  T6CFGR;                            /*!< T6CFGR Register                                                       */
  __IO uint32_t  T7CFGR;                            /*!< T7CFGR Register                                                       */
  __IO uint32_t  T0MDR;                             /*!< T0MDR Register                                                        */
  __IO uint32_t  T1MDR;                             /*!< T1MDR Register                                                        */
  __IO uint32_t  T2MDR;                             /*!< T2MDR Register                                                        */
  __IO uint32_t  T3MDR;                             /*!< T3MDR Register                                                        */
  __IO uint32_t  T4MDR;                             /*!< T4MDR Register                                                        */
  __IO uint32_t  T5MDR;                             /*!< T5MDR Register                                                        */
  __IO uint32_t  T6MDR;                             /*!< T6MDR Register                                                        */
  __IO uint32_t  T7MDR;                             /*!< T7MDR Register                                                        */
  __IO uint32_t  T0ARR;                             /*!< T0ARR Register                                                        */
  __IO uint32_t  T1ARR;                             /*!< T1ARR Register                                                        */
  __IO uint32_t  T2ARR;                             /*!< T2ARR Register                                                        */
  __IO uint32_t  T3ARR;                             /*!< T3ARR Register                                                        */
  __IO uint32_t  T4ARR;                             /*!< T4ARR Register                                                        */
  __IO uint32_t  T5ARR;                             /*!< T5ARR Register                                                        */
  __IO uint32_t  T6ARR;                             /*!< T6ARR Register                                                        */
  __IO uint32_t  T7ARR;                             /*!< T7ARR Register                                                        */
  __IO uint32_t  T0CCR;                             /*!< T0CCR Register                                                        */
  __IO uint32_t  T1CCR;                             /*!< T1CCR Register                                                        */
  __IO uint32_t  T2CCR;                             /*!< T2CCR Register                                                        */
  __IO uint32_t  T3CCR;                             /*!< T3CCR Register                                                        */
  __IO uint32_t  T4CCR;                             /*!< T4CCR Register                                                        */
  __IO uint32_t  T5CCR;                             /*!< T5CCR Register                                                        */
  __IO uint32_t  T6CCR;                             /*!< T6CCR Register                                                        */
  __IO uint32_t  T7CCR;                             /*!< T7CCR Register                                                        */
  __IO uint32_t  T0IER;                             /*!< T0IER Register                                                        */
  __IO uint32_t  T1IER;                             /*!< T1IER Register                                                        */
  __IO uint32_t  T2IER;                             /*!< T2IER Register                                                        */
  __IO uint32_t  T3IER;                             /*!< T3IER Register                                                        */
  __IO uint32_t  T4IER;                             /*!< T4IER Register                                                        */
  __IO uint32_t  T5IER;                             /*!< T5IER Register                                                        */
  __IO uint32_t  T6IER;                             /*!< T6IER Register                                                        */
  __IO uint32_t  T7IER;                             /*!< T7IER Register                                                        */
  __IO uint32_t  T0ISR;                             /*!< T0ISR Register                                                        */
  __IO uint32_t  T1ISR;                             /*!< T1ISR Register                                                        */
  __IO uint32_t  T2ISR;                             /*!< T2ISR Register                                                        */
  __IO uint32_t  T3ISR;                             /*!< T3ISR Register                                                        */
  __IO uint32_t  T4ISR;                             /*!< T4ISR Register                                                        */
  __IO uint32_t  T5ISR;                             /*!< T5ISR Register                                                        */
  __IO uint32_t  T6ISR;                             /*!< T6ISR Register                                                        */
  __IO uint32_t  T7ISR;                             /*!< T7ISR Register                                                        */
  __IO uint32_t  T0CNTR;                            /*!< T0CNT Register                                                        */
  __IO uint32_t  T1CNTR;                            /*!< T1CNT Register                                                        */
  __IO uint32_t  T2CNTR;                            /*!< T2CNT Register                                                        */
  __IO uint32_t  T3CNTR;                            /*!< T3CNT Register                                                        */
  __IO uint32_t  T4CNTR;                            /*!< T4CNT Register                                                        */
  __IO uint32_t  T5CNTR;                            /*!< T5CNT Register                                                        */
  __IO uint32_t  T6CNTR;                            /*!< T6CNT Register                                                        */
  __IO uint32_t  T7CNTR;                            /*!< T7CNT Register                                                        */
} TAU1_Type;


/* ================================================================================ */
/* ================                       TSI                      ================ */
/* ================================================================================ */


/**
  * @brief TSI module information (TSI)
  */

typedef struct {                                    /*!< TSI Structure                                                         */
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
  __IO uint32_t  IER;                               /*!< IER Register                                                          */
  __IO uint32_t  RXSR;                              /*!< RXSR Register                                                         */
  __IO uint32_t  TXSR;                              /*!< TXSR Register                                                         */
  __IO uint32_t  CFGR;                              /*!< CFGR Register                                                         */
  __IO uint32_t  CR;                                /*!< CR Register                                                           */
  __IO uint32_t  CHCR0;                             /*!< CHCR0 Register                                                        */
  __IO uint32_t  CHCR1;                             /*!< CHCR1 Register                                                        */
  __IO uint32_t  CHCFGR0;                           /*!< CHCFGR0 Register                                                      */
  __IO uint32_t  CHCFGR1;                           /*!< CHCFGR1 Register                                                      */
  __IO uint32_t  RAWCNTR;                           /*!< RAWCNTR Register                                                      */
  __IO uint32_t  CCR;                               /*!< CCR Register                                                          */
  __IO uint32_t  DMACR;                             /*!< DMACR Register                                                        */
  __IO uint32_t  SPCFGR;                            /*!< SPCFGR Register                                                       */
  __IO uint32_t  IDACTR;                            /*!< IDACTR Register                                                       */
  __IO uint32_t  ANACR;                             /*!< ANACR Register                                                        */
  __IO uint32_t  TEST;                              /*!< TEST Register                                                         */
  __IO uint32_t  TESTRING0;                         /*!< TESTRING0 Register                                                    */
  __IO uint32_t  TESTRING1;                         /*!< TESTRING1 Register                                                    */
  __IO uint32_t  ANATEST;                           /*!< ANATEST Register                                                      */
  __IO uint32_t  VREFCR;                            /*!< VREFCR Register                                                       */
  __I  uint32_t  RESERVED;
  __IO uint32_t  SHLDGNDCR0;                        /*!< SHLDGNDCR0 Register                                                   */
  __IO uint32_t  SHLDGNDCR1;                        /*!< SHLDGNDCR1 Register                                                   */
  __IO uint32_t  EMICR0;                            /*!< EMICR0 Register                                                       */
  __IO uint32_t  EMICR1;                            /*!< EMICR1 Register                                                       */
  __IO uint32_t  SHLDCR0;                           /*!< SHLDCR0 Register                                                      */
  __IO uint32_t  SHLDCR1;                           /*!< SHLDCR1 Register                                                      */
  __IO uint32_t  CKCR;                              /*!< CKCR Register                                                         */
  __IO uint32_t  PRSSW;                             /*!< PRSSW Register                                                        */
  __IO uint32_t  PLLCR;                             /*!< PLLCR Register                                                        */
  __IO uint32_t  PRSSSC;                            /*!< PRSSSC Register                                                       */
} TSI_Type;


/* ================================================================================ */
/* ================                   UART_COMMON                  ================ */
/* ================================================================================ */


/**
  * @brief UART_COMMON module information (UART_COMMON)
  */

typedef struct {                                    /*!< UART_COMMON Structure                                                 */
  __IO uint32_t IRCR;                               /*!< Infrared modulation Control Register                                  */
}UART_COMMON_Type;



/* ================================================================================ */
/* ================                      UART                      ================ */
/* ================================================================================ */


/**
  * @brief UART module information (UART)
  */

typedef struct {                                    /*!< UART Structure                                                        */
  __IO uint32_t CSR;                                /*!< UART Control Status Register                                          */
  __IO uint32_t IER;                                /*!< UART Interrupt Enable Register                                        */
  __IO uint32_t ISR;                                /*!< UART Interrupt Status Register                                        */
  __IO uint32_t TODR;                               /*!< UART Time-Out and Delay Register                                      */
  __I  uint32_t RXBUF;                              /*!< UART Receive Buffer                                                   */
  __O  uint32_t TXBUF;                              /*!< UART Transmit Buffer                                                  */
  __IO uint32_t BGR;                                /*!< UART Baud rate Generator Register                                     */
  __IO uint32_t RESERVED;
  __IO uint32_t MCR;                                /*!< UART Mode Control Register                                            */
  __IO uint32_t LINCR;                              /*!< UART LIN Control Register                                             */
  __I  uint32_t LINBSR;                             /*!< UART LIN Baud Sync Register                                           */
  __IO uint32_t LINFTR;                             /*!< UART LIN Frame Timeout Register                                       */
  __IO uint32_t LINTTR;                             /*!< UART LIN Transmit Timing Register                                     */
  __I  uint32_t LINPSR;                             /*!< UARTLINPre-sync baud register                                         */
  __I  uint32_t LINBKR;                             /*!< UARTLINBreak counter register                                         */
  __IO uint32_t RESERVED1;
  __IO uint32_t SCISR;                              /*!< USART Smart Card Interrupt Status Register                            */
  __IO uint32_t SCIER;                              /*!< USART Smart Card Interrupt Enable Register                            */
  __IO uint32_t FFCR;                               /*!< USART Smart Card Frame Format Control Register                        */
  __IO uint32_t EGTR;                               /*!< USART Smart Card Extra Guard Time Register                            */
  __IO uint32_t CODR;                               /*!< USART Smart Card Clock Output Register                                */
  __IO uint32_t SCCR;                               /*!< USART Smart Card Abort Waiting For Retransmit                         */
  __IO uint32_t RESERVED2[10];                                                                                      
  __IO uint32_t LINSSCR;                            /*!< LIN Self-test Switch Control Register                                 */
}UART_Type;


/* ================================================================================ */
/* ================                      WWDT                      ================ */
/* ================================================================================ */


/**
  * @brief WWDT module information (WWDT)
  */

typedef struct {                                    /*!< WWDT Structure                                                        */
  __IO uint32_t  CR;                                /*!< CR Register                                                           */
  __IO uint32_t  CFGR;                              /*!< CFGR Register                                                         */
  __IO uint32_t  CNT;                               /*!< CNT Register                                                          */
  __IO uint32_t  IER;                               /*!< IER Register                                                          */
  __IO uint32_t  ISR;                               /*!< ISR Register                                                          */
  __IO uint32_t  PSC;                               /*!< PSC Register                                                          */
} WWDT_Type;


/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif




/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

#define ADC_BASE                        0x4001AC00UL
#define ATIM_BASE                       0x4001B000UL
#define BSTIM16_BASE                    0x4001B400UL
#define CLM0_BASE                       0x4001C000UL
#define CLM1_BASE                       0x4001C400UL
#define CLM2_BASE                       0x4001C800UL
#define CMU_BASE                        0x40002400UL
#define COMP1_BASE                      0x40019C00UL
#define COMP2_BASE                      0x40019C04UL
#define COMP_COMMON_BASE                0x40019C10UL
#define CRC_BASE                        0x40018000UL
#define DAC_BASE                        0x40012C00UL
#define DMA_BASE                        0x40000400UL
#define CANFD_BASE                      0x40020000UL
#define CANFD_RX_FIFO_BASE              0x40020520UL
#define CANFD_COMMON_FIFO_BASE          0x400205B8UL
#define CANFD_TX_MESSAGE_BASE           0x40020604UL
#define CANFD_TX_HISTORY_LIST_BASE      0x40020740UL
#define CANFD_RX_MESSAGE0_BASE          0x40020920UL
#define CANFD_RX_MESSAGE1_BASE          0x40020D20UL
#define CANFD_RX_MESSAGE2_BASE          0x40021120UL
#define CANFD_RX_MESSAGE3_BASE          0x40021520UL
#define FLASH_BASE                      0x40001000UL
#define GPIO_BASE                       0x40000E40UL
#define GPIOA_BASE                      0x40000C00UL
#define GPIOB_BASE                      0x40000C40UL
#define GPIOC_BASE                      0x40000C80UL
#define GPIOD_BASE                      0x40000CC0UL
#define GPIOE_BASE                      0x40000D00UL
#define GPIOF_BASE                      0x40000D40UL
#define GPIOG_BASE                      0x40000D80UL
#define GPIOH_BASE                      0x40000DC0UL
#define I2C0_BASE                       0x40015000UL
#define I2C1_BASE                       0x40015400UL
#define INTMUX_BASE                     0x40016000UL
#define IWDT_BASE                       0x40011400UL
#define LPTIM16_BASE                    0x40013400UL
#define LPUART_BASE                     0x40010400UL
#define PMU_BASE                        0x40002000UL
#define QSPI_BASE                       0x40000800UL
#define RAMBIST_BASE                    0x4000FC00UL
#define RMU_BASE                        0x40002800UL
#define RTC_BASE                        0x40011000UL
#define SCU_BASE                        0x40000000UL
#define SENT0_BASE                      0x40014800UL
#define SENT1_BASE                      0x40014C00UL
#define SFU_BASE                        0x40002C00UL
#define SPI0_BASE                       0x40019000UL
#define SPI1_BASE                       0x40018C00UL
#define SPI2_BASE                       0x40010800UL
#define SVD_BASE                        0x4001A800UL
#define TAU_COMMON_BASE                 0x40013C00UL
#define TAU0_BASE                       0x40013C10UL
#define TAU1_BASE                       0x40013CF0UL
#define TSI_BASE                        0x40010000UL
#define UART0_BASE                      0x40011C00UL
#define UART1_BASE                      0x40012000UL
#define UART2_BASE                      0x40017400UL
#define UART3_BASE                      0x40017800UL
#define UART4_BASE                      0x4001A000UL
#define UART5_BASE                      0x4001A400UL
#define UART6_BASE                      0x4001B800UL
#define UART7_BASE                      0x4001BC00UL
#define UARTIR_BASE                     0x40017C00UL
#define WWDT_BASE                       0x40011800UL


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define ADC                             ((ADC_Type                *) ADC_BASE)
#define ATIM                            ((ATIM_Type               *) ATIM_BASE)
#define BSTIM16                         ((BSTIM16_Type            *) BSTIM16_BASE)
#define CLM0                            ((CLM_Type                *) CLM0_BASE)
#define CLM1                            ((CLM_Type                *) CLM1_BASE)
#define CLM2                            ((CLM_Type                *) CLM2_BASE)
#define CMU                             ((CMU_Type                *) CMU_BASE)
#define COMP1                           ((COMP_Type               *) COMP1_BASE)
#define COMP2                           ((COMP_Type               *) COMP2_BASE)
#define COMP                            ((COMP_COMMON_Type        *) COMP_COMMON_BASE)
#define CRC                             ((CRC_Type                *) CRC_BASE)
#define DAC                             ((DAC_Type                *) DAC_BASE)
#define DMA                             ((DMA_Type                *) DMA_BASE)
#define CANFD                           ((CANFD_COMMON_Type          *) CANFD_BASE                 )
#define CANFD_RX_FIFO                   ((CANFD_RX_FIFO_Type         *) CANFD_RX_FIFO_BASE         )
#define CANFD_COMMON_FIFO               ((CANFD_COMMON_FIFO_Type     *) CANFD_COMMON_FIFO_BASE     )
#define CANFD_TX_MESSAGE                ((CANFD_TX_MESSAGE_Type      *) CANFD_TX_MESSAGE_BASE      )
#define CANFD_TX_HISTORY_LIST           ((CANFD_TX_HISTORY_LIST_Type *) CANFD_TX_HISTORY_LIST_BASE )
#define CANFD_RX_MESSAGE0               ((CANFD_RX_MESSAGE_Type      *) CANFD_RX_MESSAGE0_BASE     )
#define CANFD_RX_MESSAGE1               ((CANFD_RX_MESSAGE_Type      *) CANFD_RX_MESSAGE1_BASE     )
#define CANFD_RX_MESSAGE2               ((CANFD_RX_MESSAGE_Type      *) CANFD_RX_MESSAGE2_BASE     )
#define CANFD_RX_MESSAGE3               ((CANFD_RX_MESSAGE_Type      *) CANFD_RX_MESSAGE3_BASE     )
#define FLASH                           ((FLASH_Type                *) FLASH_BASE)
#define GPIO                            ((GPIO_COMMON_Type        *) GPIO_BASE)
#define GPIOA                           ((GPIO_Type               *) GPIOA_BASE)
#define GPIOB                           ((GPIO_Type               *) GPIOB_BASE)
#define GPIOC                           ((GPIO_Type               *) GPIOC_BASE)
#define GPIOD                           ((GPIO_Type               *) GPIOD_BASE)
#define GPIOE                           ((GPIO_Type               *) GPIOE_BASE)
#define GPIOF                           ((GPIO_Type               *) GPIOF_BASE)
#define GPIOG                           ((GPIO_Type               *) GPIOG_BASE)
#define GPIOH                           ((GPIO_Type               *) GPIOH_BASE)
#define I2C0                            ((I2C_Type                *) I2C0_BASE)
#define I2C1                            ((I2C_Type                *) I2C1_BASE)
#define INTMUX                          ((INTMUX_Type             *) INTMUX_BASE)
#define IWDT                            ((IWDT_Type               *) IWDT_BASE)
#define LPTIM16                         ((LPTIM16_Type            *) LPTIM16_BASE)
#define LPUART                          ((LPUART_Type             *) LPUART_BASE)
#define PMU                             ((PMU_Type                *) PMU_BASE)
#define QSPI                            ((QSPI_Type               *) QSPI_BASE)
#define RAMBIST                         ((RAMBIST_Type            *) RAMBIST_BASE)
#define RMU                             ((RMU_Type                *) RMU_BASE)
#define RTC                             ((RTC_Type                *) RTC_BASE)
#define SCU                             ((SCU_Type                *) SCU_BASE)
#define SENT0                           ((SENT_Type               *) SENT0_BASE)
#define SENT1                           ((SENT_Type               *) SENT1_BASE)
#define SFU                             ((SFU_Type                *) SFU_BASE)
#define SPI0                            ((SPI_Type                *) SPI0_BASE)
#define SPI1                            ((SPI_Type                *) SPI1_BASE)
#define SPI2                            ((SPI_Type                *) SPI2_BASE)
#define SVD                             ((SVD_Type                *) SVD_BASE)
#define TAU                             ((TAU_COMMON_Type         *) TAU_COMMON_BASE)
#define TAU0                            ((TAU0_Type               *) TAU0_BASE)
#define TAU1                            ((TAU1_Type               *) TAU1_BASE)
#define TSI                             ((TSI_Type                *) TSI_BASE)
#define UART0                           ((UART_Type               *) UART0_BASE)
#define UART1                           ((UART_Type               *) UART1_BASE)
#define UART2                           ((UART_Type               *) UART2_BASE)
#define UART3                           ((UART_Type               *) UART3_BASE)
#define UART4                           ((UART_Type               *) UART4_BASE)
#define UART5                           ((UART_Type               *) UART5_BASE)
#define UART6                           ((UART_Type               *) UART6_BASE)
#define UART7                           ((UART_Type               *) UART7_BASE)
#define UARTIR                          ((UART_COMMON_Type        *) UARTIR_BASE)
#define WWDT                            ((WWDT_Type               *) WWDT_BASE)


/** @} */ /* End of group Device_Peripheral_Registers */
/** @} */ /* End of group FM33FH0XX */
/** @} */ /* End of group (null) */

#ifdef __cplusplus
}
#endif


#endif  /* FM33FH0XX_H */

