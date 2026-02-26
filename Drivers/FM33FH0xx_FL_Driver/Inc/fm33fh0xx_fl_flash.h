/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_flash.h
  * @author  FMSH Application Team
  * @brief   Head file of FLASH FL Module
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
#ifndef __FM33FH0XX_FL_FLASH_H
#define __FM33FH0XX_FL_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fh0xx_fl_def.h"
/** @addtogroup FM33FH0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup FLASH_FL_ES_INIT FLASH Exported Init structures
  * @{
  */

/**
  * @brief FL FLASH Init Sturcture definition
  */
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup FLASH_FL_Exported_Constants FLASH Exported Constants
  * @{
  */

#define    FLASH_RDCR_DATA_WAIT_Pos                                 (2U)
#define    FLASH_RDCR_DATA_WAIT_Msk                                 (0x7U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FLASH_RDCR_DATA_WAIT                                     FLASH_RDCR_DATA_WAIT_Msk

#define    FLASH_RDCR_CODE_WAIT_Pos                                 (0U)
#define    FLASH_RDCR_CODE_WAIT_Msk                                 (0x3U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FLASH_RDCR_CODE_WAIT                                     FLASH_RDCR_CODE_WAIT_Msk

#define    FLASH_PFCR_EN_Pos                                        (0U)
#define    FLASH_PFCR_EN_Msk                                        (0x1U << FLASH_PFCR_EN_Pos)
#define    FLASH_PFCR_EN                                            FLASH_PFCR_EN_Msk
                                                                                                                                       
#define    FLASH_OPTBR_IWDTSLP_Pos                                  (31U)
#define    FLASH_OPTBR_IWDTSLP_Msk                                  (0x1U << FLASH_OPTBR_IWDTSLP_Pos)
#define    FLASH_OPTBR_IWDTSLP                                      FLASH_OPTBR_IWDTSLP_Msk

#define    FLASH_OPTBR_IWDTEN_Pos                                   (30U)
#define    FLASH_OPTBR_IWDTEN_Msk                                   (0x1U << FLASH_OPTBR_IWDTEN_Pos)
#define    FLASH_OPTBR_IWDTEN                                       FLASH_OPTBR_IWDTEN_Msk

#define    FLASH_OPTBR_DFDBRDPEN_Pos                                (4U)
#define    FLASH_OPTBR_DFDBRDPEN_Msk                                (0x3U << FLASH_OPTBR_DFDBRDPEN_Pos)
#define    FLASH_OPTBR_DFDBRDPEN                                    FLASH_OPTBR_DFDBRDPEN

#define    FLASH_OPTBR_ACLOCKEN_Pos                                 (2U)
#define    FLASH_OPTBR_ACLOCKEN_Msk                                 (0x3U << FLASH_OPTBR_ACLOCKEN_Pos)
#define    FLASH_OPTBR_ACLOCKEN                                     FLASH_OPTBR_ACLOCKEN_Msk

#define    FLASH_OPTBR_CFDBRDPEN_Pos                                (0U)
#define    FLASH_OPTBR_CFDBRDPEN_Msk                                (0x3U << FLASH_OPTBR_CFDBRDPEN_Pos)
#define    FLASH_OPTBR_CFDBRDPEN                                    FLASH_OPTBR_CFDBRDPEN_Msk

#define    FLASH_CEPCR_ERTYPE_Pos                                   (8U)
#define    FLASH_CEPCR_ERTYPE_Msk                                   (0x3U << FLASH_CEPCR_ERTYPE_Pos)
#define    FLASH_CEPCR_ERTYPE                                       FLASH_CEPCR_ERTYPE_Msk

#define    FLASH_CEPCR_PREQ_Pos                                     (1U)
#define    FLASH_CEPCR_PREQ_Msk                                     (0x1U << FLASH_CEPCR_PREQ_Pos)
#define    FLASH_CEPCR_PREQ                                         FLASH_CEPCR_PREQ_Msk

#define    FLASH_CEPCR_EREQ_Pos                                     (0U)
#define    FLASH_CEPCR_EREQ_Msk                                     (0x1U << FLASH_CEPCR_EREQ_Pos)
#define    FLASH_CEPCR_EREQ                                         FLASH_CEPCR_EREQ_Msk

#define    FLASH_CIER_LVIE_Pos                                      (12U)
#define    FLASH_CIER_LVIE_Msk                                      (0x1U << FLASH_CIER_LVIE_Pos)
#define    FLASH_CIER_LVIE                                          FLASH_CIER_LVIE_Msk

#define    FLASH_CIER_OPTIE_Pos                                     (11U)
#define    FLASH_CIER_OPTIE_Msk                                     (0x1U << FLASH_CIER_OPTIE_Pos)
#define    FLASH_CIER_OPTIE                                         FLASH_CIER_OPTIE_Msk

#define    FLASH_CIER_AUTHIE_Pos                                    (10U)
#define    FLASH_CIER_AUTHIE_Msk                                    (0x1U << FLASH_CIER_AUTHIE_Pos)
#define    FLASH_CIER_AUTHIE                                        FLASH_CIER_AUTHIE_Msk

#define    FLASH_CIER_KEYIE_Pos                                     (9U)
#define    FLASH_CIER_KEYIE_Msk                                     (0x1U << FLASH_CIER_KEYIE_Pos)
#define    FLASH_CIER_KEYIE                                         FLASH_CIER_KEYIE_Msk

#define    FLASH_CIER_CKIE_Pos                                      (8U)
#define    FLASH_CIER_CKIE_Msk                                      (0x1U << FLASH_CIER_CKIE_Pos)
#define    FLASH_CIER_CKIE                                          FLASH_CIER_CKIE_Msk

#define    FLASH_CIER_PRDIE_Pos                                     (1U)
#define    FLASH_CIER_PRDIE_Msk                                     (0x1U << FLASH_CIER_PRDIE_Pos)
#define    FLASH_CIER_PRDIE                                         FLASH_CIER_PRDIE_Msk

#define    FLASH_CIER_ERDIE_Pos                                     (0U)
#define    FLASH_CIER_ERDIE_Msk                                     (0x1U << FLASH_CIER_ERDIE_Pos)
#define    FLASH_CIER_ERDIE                                         FLASH_CIER_ERDIE_Msk

#define    FLASH_CISR_CONF_Pos                                      (31U)
#define    FLASH_CISR_CONF_Msk                                      (0x1U << FLASH_CISR_CONF_Pos)
#define    FLASH_CISR_CONF                                          FLASH_CISR_CONF_Msk

#define    FLASH_CISR_KEYSTA_Pos                                    (17U)
#define    FLASH_CISR_KEYSTA_Msk                                    (0x7U << FLASH_CISR_KEYSTA_Pos)
#define    FLASH_CISR_KEYSTA                                        FLASH_CISR_KEYSTA_Msk

#define    FLASH_CISR_LVERR_Pos                                     (12U)
#define    FLASH_CISR_LVERR_Msk                                     (0x1U << FLASH_CISR_LVERR_Pos)
#define    FLASH_CISR_LVERR                                         FLASH_CISR_LVERR_Msk

#define    FLASH_CISR_OPTERR_Pos                                    (11U)
#define    FLASH_CISR_OPTERR_Msk                                    (0x1U << FLASH_CISR_OPTERR_Pos)
#define    FLASH_CISR_OPTERR                                        FLASH_CISR_OPTERR_Msk

#define    FLASH_CISR_AUTHERR_Pos                                   (10U)
#define    FLASH_CISR_AUTHERR_Msk                                   (0x1U << FLASH_CISR_AUTHERR_Pos)
#define    FLASH_CISR_AUTHERR                                       FLASH_CISR_AUTHERR_Msk

#define    FLASH_CISR_KEYERR_Pos                                    (9U)
#define    FLASH_CISR_KEYERR_Msk                                    (0x1U << FLASH_CISR_KEYERR_Pos)
#define    FLASH_CISR_KEYERR                                        FLASH_CISR_KEYERR_Msk

#define    FLASH_CISR_CKERR_Pos                                     (8U)
#define    FLASH_CISR_CKERR_Msk                                     (0x1U << FLASH_CISR_CKERR_Pos)
#define    FLASH_CISR_CKERR                                         FLASH_CISR_CKERR_Msk

#define    FLASH_CISR_PRD_Pos                                       (1U)
#define    FLASH_CISR_PRD_Msk                                       (0x1U << FLASH_CISR_PRD_Pos)
#define    FLASH_CISR_PRD                                           FLASH_CISR_PRD_Msk

#define    FLASH_CISR_ERD_Pos                                       (0U)
#define    FLASH_CISR_ERD_Msk                                       (0x1U << FLASH_CISR_ERD_Pos)
#define    FLASH_CISR_ERD                                           FLASH_CISR_ERD_Msk

#define    FLASH_ECCSR_DD_Pos                                       (31U)
#define    FLASH_ECCSR_DD_Msk                                       (0x1U << FLASH_ECCSR_DD_Pos)
#define    FLASH_ECCSR_DD                                           FLASH_ECCSR_DD_Msk

#define    FLASH_ECCSR_CD_Pos                                       (30U)
#define    FLASH_ECCSR_CD_Msk                                       (0x1U << FLASH_ECCSR_CD_Pos)
#define    FLASH_ECCSR_CD                                           FLASH_ECCSR_CD_Msk

#define    FLASH_ECCSR_DC_Pos                                       (28U)
#define    FLASH_ECCSR_DC_Msk                                       (0x1U << FLASH_ECCSR_DC_Pos)
#define    FLASH_ECCSR_DC                                           FLASH_ECCSR_DC_Msk

#define    FLASH_ECCSR_CC_Pos                                       (28U)
#define    FLASH_ECCSR_CC_Msk                                       (0x1U << FLASH_ECCSR_CC_Pos)
#define    FLASH_ECCSR_CC                                           FLASH_ECCSR_CC_Msk

#define    FLASH_ECCSR_BE_Pos                                       (27U)
#define    FLASH_ECCSR_BE_Msk                                       (0x1U << FLASH_ECCSR_BE_Pos)
#define    FLASH_ECCSR_BE                                            FLASH_ECCSR_BE_Msk

#define    FLASH_ECCIER_DDIE_Pos                                    (3U)
#define    FLASH_ECCIER_DDIE_Msk                                    (0x1U << FLASH_ECCIER_DDIE_Pos)
#define    FLASH_ECCIER_DDIE                                        FLASH_ECCIER_DDIE_Msk

#define    FLASH_ECCIER_CDIE_Pos                                    (2U)
#define    FLASH_ECCIER_CDIE_Msk                                    (0x1U << FLASH_ECCIER_CDIE_Pos)
#define    FLASH_ECCIER_CDIE                                        FLASH_ECCIER_CDIE_Msk

#define    FLASH_ECCIER_DCIE_Pos                                    (1U)
#define    FLASH_ECCIER_DCIE_Msk                                    (0x1U << FLASH_ECCIER_DCIE_Pos)
#define    FLASH_ECCIER_DCIE                                        FLASH_ECCIER_DCIE_Msk

#define    FLASH_ECCIER_CCIE_Pos                                    (0U)
#define    FLASH_ECCIER_CCIE_Msk                                    (0x1U << FLASH_ECCIER_CCIE_Pos)
#define    FLASH_ECCIER_CCIE                                        FLASH_ECCIER_CCIE_Msk

#define    FLASH_ECCEAR_DADDR_Pos                                   (20U)
#define    FLASH_ECCEAR_DADDR_Msk                                   (0xfffU << FLASH_ECCEAR_DADDR_Pos)
#define    FLASH_ECCEAR_DADDR                                       FLASH_ECCEAR_DADDR_Msk

#define    FLASH_ECCEAR_CADDR_Pos                                   (0U)
#define    FLASH_ECCEAR_CADDR_Msk                                   (0xffffU << FLASH_ECCEAR_CADDR_Pos)
#define    FLASH_ECCEAR_CADDR                                       FLASH_ECCEAR_CADDR_Msk

#define    FLASH_ECCCR_CECCR_Pos                                    (8U)
#define    FLASH_ECCCR_CECCR_Msk                                    (0xffU << FLASH_ECCCR_CECCR_Pos)
#define    FLASH_ECCCR_CECCR                                        FLASH_ECCCR_CECCR_Msk

#define    FLASH_ECCCR_DECCR_Pos                                    (0U)
#define    FLASH_ECCCR_DECCR_Msk                                    (0xffU << FLASH_ECCCR_DECCR_Pos)
#define    FLASH_ECCCR_DECCR                                        FLASH_ECCCR_DECCR_Msk

#define    FLASH_DEPCR_ERTYPE_Pos                                   (8U)
#define    FLASH_DEPCR_ERTYPE_Msk                                   (0x3U << FLASH_DEPCR_ERTYPE_Pos)
#define    FLASH_DEPCR_ERTYPE                                       FLASH_DEPCR_ERTYPE_Msk

#define    FLASH_DEPCR_PREQ_Pos                                     (1U)
#define    FLASH_DEPCR_PREQ_Msk                                     (0x1U << FLASH_DEPCR_PREQ_Pos)
#define    FLASH_DEPCR_PREQ                                         FLASH_DEPCR_PREQ_Msk

#define    FLASH_DEPCR_EREQ_Pos                                     (0U)
#define    FLASH_DEPCR_EREQ_Msk                                     (0x1U << FLASH_DEPCR_EREQ_Pos)
#define    FLASH_DEPCR_EREQ                                         FLASH_DEPCR_EREQ_Msk

#define    FLASH_DIER_LVIE_Pos                                      (12U)
#define    FLASH_DIER_LVIE_Msk                                      (0x1U << FLASH_DIER_LVIE_Pos)
#define    FLASH_DIER_LVIE                                          FLASH_DIER_LVIE_Msk

#define    FLASH_DIER_OPTIE_Pos                                     (11U)
#define    FLASH_DIER_OPTIE_Msk                                     (0x1U << FLASH_DIER_OPTIE_Pos)
#define    FLASH_DIER_OPTIE                                         FLASH_DIER_OPTIE_Msk

#define    FLASH_DIER_AUTHIE_Pos                                    (10U)
#define    FLASH_DIER_AUTHIE_Msk                                    (0x1U << FLASH_DIER_AUTHIE_Pos)
#define    FLASH_DIER_AUTHIE                                        FLASH_DIER_AUTHIE_Msk

#define    FLASH_DIER_KEYIE_Pos                                     (9U)
#define    FLASH_DIER_KEYIE_Msk                                     (0x1U << FLASH_DIER_KEYIE_Pos)
#define    FLASH_DIER_KEYIE                                         FLASH_DIER_KEYIE_Msk

#define    FLASH_DIER_CKIE_Pos                                      (8U)
#define    FLASH_DIER_CKIE_Msk                                      (0x1U << FLASH_DIER_CKIE_Pos)
#define    FLASH_DIER_CKIE                                          FLASH_DIER_CKIE_Msk

#define    FLASH_DIER_PRDIE_Pos                                     (1U)
#define    FLASH_DIER_PRDIE_Msk                                     (0x1U << FLASH_DIER_PRDIE_Pos)
#define    FLASH_DIER_PRDIE                                         FLASH_DIER_PRDIE_Msk

#define    FLASH_DIER_ERDIE_Pos                                     (0U)
#define    FLASH_DIER_ERDIE_Msk                                     (0x1U << FLASH_DIER_ERDIE_Pos)
#define    FLASH_DIER_ERDIE                                         FLASH_DIER_ERDIE_Msk

#define    FLASH_DISR_CONF_Pos                                      (31U)
#define    FLASH_DISR_CONF_Msk                                      (0x1U << FLASH_DISR_CONF_Pos)
#define    FLASH_DISR_CONF                                          FLASH_DISR_CONF_Msk

#define    FLASH_DISR_KEYSTA_Pos                                    (17U)
#define    FLASH_DISR_KEYSTA_Msk                                    (0x7U << FLASH_DISR_KEYSTA_Pos)
#define    FLASH_DISR_KEYSTA                                        FLASH_DISR_KEYSTA_Msk

#define    FLASH_DISR_LVERR_Pos                                     (12U)
#define    FLASH_DISR_LVERR_Msk                                     (0x1U << FLASH_DISR_LVERR_Pos)
#define    FLASH_DISR_LVERR                                         FLASH_DISR_LVERR_Msk

#define    FLASH_DISR_AUTHERR_Pos                                   (10U)
#define    FLASH_DISR_AUTHERR_Msk                                   (0x1U << FLASH_DISR_AUTHERR_Pos)
#define    FLASH_DISR_AUTHERR                                       FLASH_DISR_AUTHERR_Msk

#define    FLASH_DISR_KEYERR_Pos                                    (9U)
#define    FLASH_DISR_KEYERR_Msk                                    (0x1U << FLASH_DISR_KEYERR_Pos)
#define    FLASH_DISR_KEYERR                                        FLASH_DISR_KEYERR_Msk

#define    FLASH_DISR_CKERR_Pos                                     (8U)
#define    FLASH_DISR_CKERR_Msk                                     (0x1U << FLASH_DISR_CKERR_Pos)
#define    FLASH_DISR_CKERR                                         FLASH_DISR_CKERR_Msk

#define    FLASH_DISR_PRD_Pos                                       (1U)
#define    FLASH_DISR_PRD_Msk                                       (0x1U << FLASH_DISR_PRD_Pos)
#define    FLASH_DISR_PRD                                           FLASH_DISR_PRD_Msk

#define    FLASH_DISR_ERD_Pos                                       (0U)
#define    FLASH_DISR_ERD_Msk                                       (0x1U << FLASH_DISR_ERD_Pos)
#define    FLASH_DISR_ERD                                           FLASH_DISR_ERD_Msk
  
#define    FL_FLASH_INFORMATION1_REGIN                              (0x1U << 17U)
#define    FL_FLASH_INFORMATION2_REGIN                              (0x1U << 18U)
#define    FL_FLASH_BLOCK_0                                         (0x1U << 0U)
#define    FL_FLASH_BLOCK_1                                         (0x1U << 1U)
#define    FL_FLASH_BLOCK_2                                         (0x1U << 2U)
#define    FL_FLASH_BLOCK_3                                         (0x1U << 3U)
#define    FL_FLASH_BLOCK_4                                         (0x1U << 4U)
#define    FL_FLASH_BLOCK_5                                         (0x1U << 5U)
#define    FL_FLASH_BLOCK_6                                         (0x1U << 6U)
#define    FL_FLASH_BLOCK_7                                         (0x1U << 7U)
#define    FL_FLASH_BLOCK_8                                         (0x1U << 8U)
#define    FL_FLASH_BLOCK_9                                         (0x1U << 9U)
#define    FL_FLASH_BLOCK_10                                        (0x1U << 10U)
#define    FL_FLASH_BLOCK_11                                        (0x1U << 11U)
#define    FL_FLASH_BLOCK_12                                        (0x1U << 12U)
#define    FL_FLASH_BLOCK_13                                        (0x1U << 13U)
#define    FL_FLASH_BLOCK_14                                        (0x1U << 14U)
#define    FL_FLASH_BLOCK_15                                        (0x1U << 15U)
#define    FL_FLASH_LOCK_ALL                                        (0x0U << 0U)
#define    FL_FLASH_LOCK_SOFTWARE                                   (0x2U << 0U)
#define    FL_FLASH_LOCK_NONE                                       (0x3U << 0U)
#define    FL_FLASH_BOOTSWAP_ENABLE                                 (0x2U << 8U)
#define    FL_FLASH_BOOTSWAP_DISABLE                                (0x0U << 8U)
#define    FL_FLASH_APPCODE_LOCK_ENABLE                             (0x2U << 2U)
#define    FL_FLASH_APPCODE_LOCK_DISABLE                            (0x0U << 2U)
#define    FL_FLASH_DEBUG_READ_ENABLE                               (0x2U << 0U)
#define    FL_FLASH_DEBUG_READ_DISABLE                              (0x0U << 0U)


#define    FL_FLASH_ERASE_KEY                                     (0x96969696U)
#define    FL_FLASH_CHIP_ERASE_KEY                                (0x7D7D7D7DU)
#define    FL_FLASH_PGAE_ERASE_KEY                                (0xEAEAEAEAU)
#define    FL_FLASH_SECTOR_ERASE_KEY                              (0x3C3C3C3CU)
#define    FL_FLASH_ERASE_REQUEST                                 (0x1234ABCDU)
#define    FL_FLASH_PROGRAM_KEY1                                  (0xA5A5A5A5U)
#define    FL_FLASH_PROGRAM_KEY2                                  (0xF1F1F1F1U)
/*8M*/                                                            
#define    FL_FLASH_ERASE_TIMEOUT                                 (0x0000FFFFU)
#define    FL_FLASH_HALFWORD_ADDRS_ALIGN                          (0x00000002U)
#define    FL_FLASH_WORD_ADDRS_ALIGN                              (0x00000004U)

#define    FL_FLASH_CODE_MAX_PAGE_NUM                             (0x00000300U)
#define    FL_FLASH_CODE_MAX_SECTOR_NUM                           (0x000000C0U)
#define    FL_FLASH_CODE_SECTOR_SIZE_BYTE                         (0x00000800U)
#define    FL_FLASH_CODE_PGAE_SIZE_BYTE                           (0x00000200U)
#define    FL_FLASH_CODE_ADDR_MAXPROGRAM                          (0x0005FFFFU)

#define    FL_FLASH_INFO_MAX_PAGE_NUM                             (0x00000004U)
#define    FL_FLASH_IFFO_MAX_SECTOR_NUM                           (0x00000001U)
#define    FL_FLASH_INFO_SECTOR_SIZE_BYTE                         (0x00000800U)
#define    FL_FLASH_INFO_PGAE_SIZE_BYTE                           (0x00000200U)
#define    FL_FLASH_INFO_ADDR_MAXPROGRAM                          (0x000807FFU)
#define    FL_FLASH_INFO_ADDR_MINPROGRAM                          (0x00080000U)

#define    FL_FLASH_DATA_MAX_PAGE_NUM                             (0x00000020U)
#define    FL_FLASH_DATA_MAX_SECTOR_NUM                           (0x00000008U)
#define    FL_FLASH_DATA_SECTOR_SIZE_BYTE                         (0x00000800U)
#define    FL_FLASH_DATA_PGAE_SIZE_BYTE                           (0x00000200U)
#define    FL_FLASH_DATA_ADDR_MAXPROGRAM                          (0xA0003FFFU)
#define    FL_FLASH_DATA_ADDR_MINPROGRAM                          (0xA0000000U)


#define    FL_FLASH_DATA_WAIT_0CYCLE                            (0x0U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_DATA_WAIT_1CYCLE                            (0x1U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_DATA_WAIT_2CYCLE                            (0x2U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_DATA_WAIT_3CYCLE                            (0x3U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_DATA_WAIT_4CYCLE                            (0x4U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_DATA_WAIT_5CYCLE                            (0x5U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_DATA_WAIT_6CYCLE                            (0x6U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_DATA_WAIT_7CYCLE                            (0x7U << FLASH_RDCR_DATA_WAIT_Pos)


#define    FL_FLASH_CODE_WAIT_0CYCLE                            (0x0U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_CODE_WAIT_1CYCLE                            (0x1U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_CODE_WAIT_2CYCLE                            (0x2U << FLASH_RDCR_CODE_WAIT_Pos)

#define    FL_FLASH_IWDT_STOP_UNDER_SLEEP                       (0x0U << FLASH_OPTBR_IWDTSLP_Pos)
#define    FL_FLASH_IWDT_WORK_UNDER_SLEEP                       (0x1U << FLASH_OPTBR_IWDTSLP_Pos)

#define    FL_FLASH_IWDT_STOP_AFTERPOWERON                      (0x0U << FLASH_OPTBR_IWDTEN_Pos)
#define    FL_FLASH_IWDT_WORK_AFTERPOWERON                      (0x1U << FLASH_OPTBR_IWDTEN_Pos)

#define    FL_FLASH_FLASH_LOCK_DISABLE                          (0x0U << FLASH_OPTBR_ACLOCKEN_Pos)
#define    FL_FLASH_FLASH_LOCK_ENABLE                           (0x2U << FLASH_OPTBR_ACLOCKEN_Pos)

#define    FL_FLASH_DFLASH_SWDREAD_PEOTECTION_DISABLE           (0x0U << FLASH_OPTBR_DFDBRDPEN_CODE_Pos)
#define    FL_FLASH_DFLASH_SWDREAD_PEOTECTION_ENABLE            (0x2U << FLASH_OPTBR_DFDBRDPEN_CODE_Pos)

#define    FL_FLASH_CFLASH_SWDREAD_PEOTECTION_DISABLE           (0x0U << FLASH_OPTBR_CFDBRDPEN_CODE_Pos)
#define    FL_FLASH_CFLASH_SWDREAD_PEOTECTION_ENABLE            (0x2U << FLASH_OPTBR_CFDBRDPEN_CODE_Pos)

#define    FL_FLASH_ERASE_TYPE_CODEFLASH_PAGE                   (0x0U << FLASH_CEPCR_ERTYPE_Pos)
#define    FL_FLASH_ERASE_TYPE_CODEFLASH_SECTOR                 (0x1U << FLASH_CEPCR_ERTYPE_Pos)


#define    FL_FLASH_KEY_STATUS_CODEFLASH_LOCK                   (0x0U << FLASH_CISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_CODEFLASH_ALL_ERASE              (0x1U << FLASH_CISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_CODEFLASH_PAGE_ERASE             (0x2U << FLASH_CISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_CODEFLASH_PROGRAM                (0x3U << FLASH_CISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_CODEFLASH_ERROR                  (0x4U << FLASH_CISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_CODEFLASH_SECTOR_ERASE           (0x5U << FLASH_CISR_KEYSTA_Pos)
 
#define    FL_FLASH_ERASE_TYPE_DATAFLASH_PAGE                   (0x0U << FLASH_DEPCR_ERTYPE_Pos)
#define    FL_FLASH_ERASE_TYPE_DATAFLASH_SECTOR                 (0x1U << FLASH_DEPCR_ERTYPE_Pos)


#define    FL_FLASH_KEY_STATUS_DATAFLASH_LOCK                   (0x0U << FLASH_DISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_DATAFLASH_ALL_ERASE              (0x1U << FLASH_DISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_DATAFLASH_PAGE_ERASE             (0x2U << FLASH_DISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_DATAFLASH_PROGRAM                (0x3U << FLASH_DISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_DATAFLASH_ERROR                  (0x4U << FLASH_DISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_DATAFLASH_SECTOR_ERASE           (0x5U << FLASH_DISR_KEYSTA_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup FLASH_FL_Exported_Functions FLASH Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   RDCR    DATA_WAIT    FL_FLASH_SetDataReadWait
  * @param    FLASHx FLASH instance
  * @param    wait This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_DATA_WAIT_0CYCLE
  *           @arg @ref FL_FLASH_DATA_WAIT_1CYCLE
  *           @arg @ref FL_FLASH_DATA_WAIT_2CYCLE
  *           @arg @ref FL_FLASH_DATA_WAIT_3CYCLE
  *           @arg @ref FL_FLASH_DATA_WAIT_4CYCLE
  *           @arg @ref FL_FLASH_DATA_WAIT_5CYCLE
  *           @arg @ref FL_FLASH_DATA_WAIT_6CYCLE
  *           @arg @ref FL_FLASH_DATA_WAIT_7CYCLE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetDataReadWait(FLASH_Type* FLASHx, uint32_t wait)
{
    MODIFY_REG(FLASHx->RDCR, FLASH_RDCR_DATA_WAIT_Msk, wait);
}

/**
  * @brief    
  * @rmtoll   RDCR    DATA_WAIT    FL_FLASH_GetDataReadWait
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_DATA_WAIT_0CYCLE
  *           @arg @ref FL_FLASH_DATA_WAIT_1CYCLE
  *           @arg @ref FL_FLASH_DATA_WAIT_2CYCLE
  *           @arg @ref FL_FLASH_DATA_WAIT_3CYCLE
  *           @arg @ref FL_FLASH_DATA_WAIT_4CYCLE
  *           @arg @ref FL_FLASH_DATA_WAIT_5CYCLE
  *           @arg @ref FL_FLASH_DATA_WAIT_6CYCLE
  *           @arg @ref FL_FLASH_DATA_WAIT_7CYCLE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetDataReadWait(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->RDCR, FLASH_RDCR_DATA_WAIT_Msk));
}

/**
  * @brief    
  * @rmtoll   RDCR    WAIT_STATE    FL_FLASH_SetCodeReadWait
  * @param    FLASHx FLASH instance
  * @param    wait This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_CODE_WAIT_0CYCLE
  *           @arg @ref FL_FLASH_CODE_WAIT_1CYCLE
  *           @arg @ref FL_FLASH_CODE_WAIT_2CYCLE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetCodeReadWait(FLASH_Type* FLASHx, uint32_t wait)
{
    MODIFY_REG(FLASHx->RDCR, FLASH_RDCR_CODE_WAIT_Msk, wait);
}

/**
  * @brief    
  * @rmtoll   RDCR    WAIT_STATE    FL_FLASH_GetCodeReadWait
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_CODE_WAIT_0CYCLE
  *           @arg @ref FL_FLASH_CODE_WAIT_1CYCLE
  *           @arg @ref FL_FLASH_CODE_WAIT_2CYCLE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetCodeReadWait(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->RDCR, FLASH_RDCR_CODE_WAIT_Msk));
}

/**
  * @brief    
  * @rmtoll   PFCR    EN    FL_FLASH_EnablePrefetchPhase
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnablePrefetchPhase(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->PFCR, FLASH_PFCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   PFCR    EN    FL_FLASH_DisablePrefetchPhase
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisablePrefetchPhase(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->PFCR, FLASH_PFCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   PFCR    EN    FL_FLASH_IsEnabledPrefetchPhase
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledPrefetchPhase(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->PFCR, FLASH_PFCR_EN_Msk) == FLASH_PFCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   OPTBR    IWDTSLP    FL_FLASH_GetIWDTStateUnderSleep
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_IWDT_STOP_UNDER_SLEEP
  *           @arg @ref FL_FLASH_IWDT_WORK_UNDER_SLEEP
  */
__STATIC_INLINE uint32_t FL_FLASH_GetIWDTStateUnderSleep(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->OPTBR, FLASH_OPTBR_IWDTSLP_Msk));
}

/**
  * @brief    
  * @rmtoll   OPTBR    IWDTEN    FL_FLASH_GetIWDTStateAfterPowerOn
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_IWDT_STOP_AFTERPOWERON
  *           @arg @ref FL_FLASH_IWDT_WORK_AFTERPOWERON
  */
__STATIC_INLINE uint32_t FL_FLASH_GetIWDTStateAfterPowerOn(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->OPTBR, FLASH_OPTBR_IWDTEN_Msk));
}

/**
  * @brief    
  * @rmtoll   OPTBR    ACLOCKEN    FL_FLASH_GetFLASHLockState
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_FLASH_LOCK_DISABLE
  *           @arg @ref FL_FLASH_FLASH_LOCK_ENABLE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetFLASHLockState(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->OPTBR, FLASH_OPTBR_ACLOCKEN_Msk));
}

/**
  * @brief    
  * @rmtoll   OPTBR    DBRDPEN_CODE    FL_FLASH_GetCFLASHSWDReadProtectionState
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_CFLASH_SWDREAD_PEOTECTION_DISABLE
  *           @arg @ref FL_FLASH_CFLASH_SWDREAD_PEOTECTION_ENABLE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetCFLASHSWDReadProtectionState(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->OPTBR, FLASH_OPTBR_CFDBRDPEN_Msk));
}

/**
  * @brief    
  * @rmtoll   ACLOCK1        FL_FLASH_SetFLASHRegion1Lock
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_BLOCK_0
  *           @arg @ref FL_FLASH_BLOCK_1
  *           @arg @ref FL_FLASH_BLOCK_2
  *           @arg @ref FL_FLASH_BLOCK_3
  *           @arg @ref FL_FLASH_BLOCK_4
  *           @arg @ref FL_FLASH_BLOCK_5
  *           @arg @ref FL_FLASH_BLOCK_6
  *           @arg @ref FL_FLASH_BLOCK_7
  *           @arg @ref FL_FLASH_BLOCK_8
  *           @arg @ref FL_FLASH_BLOCK_9
  *           @arg @ref FL_FLASH_BLOCK_10
  *           @arg @ref FL_FLASH_BLOCK_11
  *           @arg @ref FL_FLASH_BLOCK_12
  *           @arg @ref FL_FLASH_BLOCK_13
  *           @arg @ref FL_FLASH_BLOCK_14
  *           @arg @ref FL_FLASH_BLOCK_15
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_LOCK_ALL
  *           @arg @ref FL_FLASH_LOCK_SOFTWARE
  *           @arg @ref FL_FLASH_LOCK_NONE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetFLASHRegion1Lock(FLASH_Type* FLASHx, uint32_t region, uint32_t mode)
{
    CLEAR_BIT(FLASHx->ACLOCK1, ((region * region) * (((mode == 3) ? 0 : (~mode)) & 0x03)));
}

/**
  * @brief    
  * @rmtoll   ACLOCK1        FL_FLASH_GetFLASHRegion1Lock
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_BLOCK_0
  *           @arg @ref FL_FLASH_BLOCK_1
  *           @arg @ref FL_FLASH_BLOCK_2
  *           @arg @ref FL_FLASH_BLOCK_3
  *           @arg @ref FL_FLASH_BLOCK_4
  *           @arg @ref FL_FLASH_BLOCK_5
  *           @arg @ref FL_FLASH_BLOCK_6
  *           @arg @ref FL_FLASH_BLOCK_7
  *           @arg @ref FL_FLASH_BLOCK_8
  *           @arg @ref FL_FLASH_BLOCK_9
  *           @arg @ref FL_FLASH_BLOCK_10
  *           @arg @ref FL_FLASH_BLOCK_11
  *           @arg @ref FL_FLASH_BLOCK_12
  *           @arg @ref FL_FLASH_BLOCK_13
  *           @arg @ref FL_FLASH_BLOCK_14
  *           @arg @ref FL_FLASH_BLOCK_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_FLASH_GetFLASHRegion1Lock(FLASH_Type* FLASHx, uint32_t region)
{
    return (uint32_t)(READ_BIT(FLASHx->ACLOCK1, ((region * region) * 0x03)) / (region * region)); 
}

/**
  * @brief    
  * @rmtoll   ACLOCK2        FL_FLASH_SetFLASHRegion2Lock
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_BLOCK_0
  *           @arg @ref FL_FLASH_BLOCK_1
  *           @arg @ref FL_FLASH_BLOCK_2
  *           @arg @ref FL_FLASH_BLOCK_3
  *           @arg @ref FL_FLASH_BLOCK_4
  *           @arg @ref FL_FLASH_BLOCK_5
  *           @arg @ref FL_FLASH_BLOCK_6
  *           @arg @ref FL_FLASH_BLOCK_7
  *           @arg @ref FL_FLASH_BLOCK_8
  *           @arg @ref FL_FLASH_BLOCK_9
  *           @arg @ref FL_FLASH_BLOCK_10
  *           @arg @ref FL_FLASH_BLOCK_11
  *           @arg @ref FL_FLASH_BLOCK_12
  *           @arg @ref FL_FLASH_BLOCK_13
  *           @arg @ref FL_FLASH_BLOCK_14
  *           @arg @ref FL_FLASH_BLOCK_15
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_LOCK_ALL
  *           @arg @ref FL_FLASH_LOCK_SOFTWARE
  *           @arg @ref FL_FLASH_LOCK_NONE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetFLASHRegion2Lock(FLASH_Type* FLASHx, uint32_t region, uint32_t mode)
{
    CLEAR_BIT(FLASHx->ACLOCK2, ((region * region) * (((mode == 3) ? 0 : (~mode)) & 0x03))); 
}

/**
  * @brief    
  * @rmtoll   ACLOCK2        FL_FLASH_GetFLASHRegion2Lock
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_BLOCK_0
  *           @arg @ref FL_FLASH_BLOCK_1
  *           @arg @ref FL_FLASH_BLOCK_2
  *           @arg @ref FL_FLASH_BLOCK_3
  *           @arg @ref FL_FLASH_BLOCK_4
  *           @arg @ref FL_FLASH_BLOCK_5
  *           @arg @ref FL_FLASH_BLOCK_6
  *           @arg @ref FL_FLASH_BLOCK_7
  *           @arg @ref FL_FLASH_BLOCK_8
  *           @arg @ref FL_FLASH_BLOCK_9
  *           @arg @ref FL_FLASH_BLOCK_10
  *           @arg @ref FL_FLASH_BLOCK_11
  *           @arg @ref FL_FLASH_BLOCK_12
  *           @arg @ref FL_FLASH_BLOCK_13
  *           @arg @ref FL_FLASH_BLOCK_14
  *           @arg @ref FL_FLASH_BLOCK_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_FLASH_GetFLASHRegion2Lock(FLASH_Type* FLASHx, uint32_t region)
{
    return (uint32_t)(READ_BIT(FLASHx->ACLOCK2, ((region * region) * 0x03)) / (region * region));
}

/**
  * @brief    
  * @rmtoll   ACLOCK3        FL_FLASH_SetFLASHRegion3Lock
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_BLOCK_0
  *           @arg @ref FL_FLASH_BLOCK_1
  *           @arg @ref FL_FLASH_BLOCK_2
  *           @arg @ref FL_FLASH_BLOCK_3
  *           @arg @ref FL_FLASH_BLOCK_4
  *           @arg @ref FL_FLASH_BLOCK_5
  *           @arg @ref FL_FLASH_BLOCK_6
  *           @arg @ref FL_FLASH_BLOCK_7
  *           @arg @ref FL_FLASH_BLOCK_8
  *           @arg @ref FL_FLASH_BLOCK_9
  *           @arg @ref FL_FLASH_BLOCK_10
  *           @arg @ref FL_FLASH_BLOCK_11
  *           @arg @ref FL_FLASH_BLOCK_12
  *           @arg @ref FL_FLASH_BLOCK_13
  *           @arg @ref FL_FLASH_BLOCK_14
  *           @arg @ref FL_FLASH_BLOCK_15
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_LOCK_ALL
  *           @arg @ref FL_FLASH_LOCK_SOFTWARE
  *           @arg @ref FL_FLASH_LOCK_NONE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetFLASHRegion3Lock(FLASH_Type* FLASHx, uint32_t region, uint32_t mode)
{
     CLEAR_BIT(FLASHx->ACLOCK3, ((region * region) * (((mode == 3) ? 0 : (~mode)) & 0x03))); 
}

/**
  * @brief    
  * @rmtoll   ACLOCK3        FL_FLASH_GetFLASHRegion3Lock
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_BLOCK_0
  *           @arg @ref FL_FLASH_BLOCK_1
  *           @arg @ref FL_FLASH_BLOCK_2
  *           @arg @ref FL_FLASH_BLOCK_3
  *           @arg @ref FL_FLASH_BLOCK_4
  *           @arg @ref FL_FLASH_BLOCK_5
  *           @arg @ref FL_FLASH_BLOCK_6
  *           @arg @ref FL_FLASH_BLOCK_7
  *           @arg @ref FL_FLASH_BLOCK_8
  *           @arg @ref FL_FLASH_BLOCK_9
  *           @arg @ref FL_FLASH_BLOCK_10
  *           @arg @ref FL_FLASH_BLOCK_11
  *           @arg @ref FL_FLASH_BLOCK_12
  *           @arg @ref FL_FLASH_BLOCK_13
  *           @arg @ref FL_FLASH_BLOCK_14
  *           @arg @ref FL_FLASH_BLOCK_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_FLASH_GetFLASHRegion3Lock(FLASH_Type* FLASHx, uint32_t region)
{
     return (uint32_t)(READ_BIT(FLASHx->ACLOCK3, ((region * region) * 0x03)) / (region * region));
}

/**
  * @brief    
  * @rmtoll   CEPCR    ERTYPE    FL_FLASH_SetCodeFLASHEraseType
  * @param    FLASHx FLASH instance
  * @param    type This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_ERASE_TYPE_PAGE
  *           @arg @ref FL_FLASH_ERASE_TYPE_SECTOR
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetCodeFLASHEraseType(FLASH_Type* FLASHx, uint32_t type)
{
    MODIFY_REG(FLASHx->CEPCR, FLASH_CEPCR_ERTYPE_Msk, type);
}

/**
  * @brief    
  * @rmtoll   CEPCR    ERTYPE    FL_FLASH_GetCodeFLASHEraseType
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_ERASE_TYPE_PAGE
  *           @arg @ref FL_FLASH_ERASE_TYPE_SECTOR
  */
__STATIC_INLINE uint32_t FL_FLASH_GetCodeFLASHEraseType(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CEPCR, FLASH_CEPCR_ERTYPE_Msk));
}

/**
  * @brief    
  * @rmtoll   CEPCR    PREQ    FL_FLASH_EnableProgramInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableProgramInCodeFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CEPCR, FLASH_CEPCR_EREQ_Msk);
    SET_BIT(FLASHx->CEPCR, FLASH_CEPCR_PREQ_Msk);
}

/**
  * @brief    
  * @rmtoll   CEPCR    EREQ    FL_FLASH_EnableEraseInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableEraseInCodeFLASH(FLASH_Type* FLASHx)
{
   CLEAR_BIT(FLASHx->CEPCR, FLASH_CEPCR_PREQ_Msk);
    SET_BIT(FLASHx->CEPCR, FLASH_CEPCR_EREQ_Msk);  
}

/**
  * @brief    
  * @rmtoll   CKEY        FL_FLASH_UnlockCodeFLASH
  * @param    FLASHx FLASH instance
  * @param    key 
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_UnlockCodeFLASH(FLASH_Type* FLASHx, uint32_t key)
{
   WRITE_REG(FLASHx->CKEY, key); 
}

/**
  * @brief    
  * @rmtoll   CKEY        FL_FLASH_LockCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_LockCodeFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CKEY, 0xFFFFFFFF);
}

/**
  * @brief    
  * @rmtoll   CIER    LVIE    FL_FLASH_EnableIT_Voltage detectProgramErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_VoltageDetectProgramErrorInCodeFlash(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->CIER, FLASH_CIER_LVIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    LVIE    FL_FLASH_DisableIT_Voltage detectProgramErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_VoltageDetectProgramErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CIER, FLASH_CIER_LVIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    LVIE    FL_FLASH_IsEnabledIT_Voltage detectProgramErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_VoltageDetectProgramErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CIER, FLASH_CIER_LVIE_Msk) == FLASH_CIER_LVIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    OPTIE    FL_FLASH_EnableIT_OTPProgramErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_OTPProgramErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->CIER, FLASH_CIER_OPTIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    OPTIE    FL_FLASH_DisableIT_OTPProgramErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_OTPProgramErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CIER, FLASH_CIER_OPTIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    OPTIE    FL_FLASH_IsEnabledIT_OTPProgramErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_OTPProgramErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CIER, FLASH_CIER_OPTIE_Msk) == FLASH_CIER_OPTIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    AUTHIE    FL_FLASH_EnableIT_AuthenticationErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_AuthenticationErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->CIER, FLASH_CIER_AUTHIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    AUTHIE    FL_FLASH_DisableIT_AuthenticationErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_AuthenticationErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CIER, FLASH_CIER_AUTHIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    AUTHIE    FL_FLASH_IsEnabledIT_AuthenticationErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_AuthenticationErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CIER, FLASH_CIER_AUTHIE_Msk) == FLASH_CIER_AUTHIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    KEYIE    FL_FLASH_EnableIT_KeyErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_KeyErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->CIER, FLASH_CIER_KEYIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    KEYIE    FL_FLASH_DisableIT_KeyErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_KeyErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CIER, FLASH_CIER_KEYIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    KEYIE    FL_FLASH_IsEnabledIT_KeyErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_KeyErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CIER, FLASH_CIER_KEYIE_Msk) == FLASH_CIER_KEYIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    CKIE    FL_FLASH_EnableIT_ClockErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_ClockErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->CIER, FLASH_CIER_CKIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    CKIE    FL_FLASH_DisableIT_ClockErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_ClockErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CIER, FLASH_CIER_CKIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    CKIE    FL_FLASH_IsEnabledIT_ClockErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_ClockErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CIER, FLASH_CIER_CKIE_Msk) == FLASH_CIER_CKIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    PRDIE    FL_FLASH_EnableIT_ProgramCompleteInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_ProgramCompleteInCodeFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->CIER, FLASH_CIER_PRDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    PRDIE    FL_FLASH_DisableIT_ProgramCompleteInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_ProgramCompleteInCodeFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CIER, FLASH_CIER_PRDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    PRDIE    FL_FLASH_IsEnabledIT_ProgramCompleteInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_ProgramCompleteInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CIER, FLASH_CIER_PRDIE_Msk) == FLASH_CIER_PRDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    ERDIE    FL_FLASH_EnableIT_EraseCompleteInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_EraseCompleteInCodeFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->CIER, FLASH_CIER_ERDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    ERDIE    FL_FLASH_DisableIT_EraseCompleteInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_EraseCompleteInCodeFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CIER, FLASH_CIER_ERDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CIER    ERDIE    FL_FLASH_IsEnabledIT_EraseCompleteInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_EraseCompleteInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CIER, FLASH_CIER_ERDIE_Msk) == FLASH_CIER_ERDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   CISR    CONF    FL_FLASH_IsActiveFlag_TestModeInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_TestModeInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CISR, FLASH_CISR_CONF_Msk) == (FLASH_CISR_CONF_Msk));
}

/**
  * @brief    
  * @rmtoll   CISR    KEYSTA    FL_FLASH_GetFLASHLockStatusInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_KEY_STATUS_LOCK
  *           @arg @ref FL_FLASH_KEY_STATUS_ALL_ERASE
  *           @arg @ref FL_FLASH_KEY_STATUS_PAGE_ERASE
  *           @arg @ref FL_FLASH_KEY_STATUS_PROGRAM
  *           @arg @ref FL_FLASH_KEY_STATUS_ERROR
  *           @arg @ref FL_FLASH_KEY_STATUS_SECTOR_ERASE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetFLASHLockStatusInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CISR, FLASH_CISR_KEYSTA_Msk));
}

/**
  * @brief    
  * @rmtoll   CISR    LVERR    FL_FLASH_IsActiveFlag_SVDVoltagedetectFallingErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_SVDVoltagedetectFallingErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CISR, FLASH_CISR_LVERR_Msk) == (FLASH_CISR_LVERR_Msk));
}

/**
  * @brief    
  * @rmtoll   CISR    LVERR    FL_FLASH_ClearFlag_SVDVoltagedetectFallingErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_SVDVoltagedetectFallingErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CISR, FLASH_CISR_LVERR_Msk);
}

/**
  * @brief    
  * @rmtoll   CISR    OPTERR    FL_FLASH_IsActiveFlag_OPTProgramErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_OPTProgramErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CISR, FLASH_CISR_OPTERR_Msk) == (FLASH_CISR_OPTERR_Msk));
}

/**
  * @brief    
  * @rmtoll   CISR    OPTERR    FL_FLASH_ClearFlag_OPTProgramErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_OPTProgramErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CISR, FLASH_CISR_OPTERR_Msk);
}

/**
  * @brief    
  * @rmtoll   CISR    AUTHERR    FL_FLASH_IsActiveFlag_AuthenticationErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_AuthenticationErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CISR, FLASH_CISR_AUTHERR_Msk) == (FLASH_CISR_AUTHERR_Msk));
}

/**
  * @brief    
  * @rmtoll   CISR    AUTHERR    FL_FLASH_ClearFlag_AuthenticationErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_AuthenticationErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CISR, FLASH_CISR_AUTHERR_Msk);
}

/**
  * @brief    
  * @rmtoll   CISR    KEYERR    FL_FLASH_IsActiveFlag_KeyErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_KeyErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CISR, FLASH_CISR_KEYERR_Msk) == (FLASH_CISR_KEYERR_Msk));
}

/**
  * @brief    
  * @rmtoll   CISR    KEYERR    FL_FLASH_ClearFlag_KeyErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_KeyErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CISR, FLASH_CISR_KEYERR_Msk);
}

/**
  * @brief    
  * @rmtoll   CISR    CKERR    FL_FLASH_IsActiveFlag_ClockErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ClockErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CISR, FLASH_CISR_CKERR_Msk) == (FLASH_CISR_CKERR_Msk));
}

/**
  * @brief    
  * @rmtoll   CISR    CKERR    FL_FLASH_ClearFlag_ClockErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ClockErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CISR, FLASH_CISR_CKERR_Msk);
}

/**
  * @brief    
  * @rmtoll   CISR    PRD    FL_FLASH_IsActiveFlag_ProgramCompleteInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ProgramCompleteInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CISR, FLASH_CISR_PRD_Msk) == (FLASH_CISR_PRD_Msk));
}

/**
  * @brief    
  * @rmtoll   CISR    PRD    FL_FLASH_ClearFlag_ProgramCompleteInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ProgramCompleteInCodeFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CISR, FLASH_CISR_PRD_Msk);
}

/**
  * @brief    
  * @rmtoll   CISR    ERD    FL_FLASH_IsActiveFlag_EraseCompleteInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_EraseCompleteInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CISR, FLASH_CISR_ERD_Msk) == (FLASH_CISR_ERD_Msk));
}

/**
  * @brief    
  * @rmtoll   CISR    ERD    FL_FLASH_ClearFlag_EraseCompleteInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_EraseCompleteInCodeFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CISR, FLASH_CISR_ERD_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCSR    DD    FL_FLASH_IsActiveFlag_ECCDetectionInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCDetectionInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCSR, FLASH_ECCSR_DD_Msk) == (FLASH_ECCSR_DD_Msk));
}

/**
  * @brief    
  * @rmtoll   ECCSR    DD    FL_FLASH_ClearFlag_ECCDetectionInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ECCDetectionInDataFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->ECCSR, FLASH_ECCSR_DD_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCSR    CD    FL_FLASH_IsActiveFlag_ECCCorrectionInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCCorrectionInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCSR, FLASH_ECCSR_CD_Msk) == (FLASH_ECCSR_CD_Msk));
}

/**
  * @brief    
  * @rmtoll   ECCSR    CD    FL_FLASH_ClearFlag_ECCCorrectionInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ECCCorrectionInDataFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->ECCSR, FLASH_ECCSR_CD_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCSR    DC    FL_FLASH_IsActiveFlag_ECCDetectionInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCDetectionInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCSR, FLASH_ECCSR_DC_Msk) == (FLASH_ECCSR_DC_Msk));
}

/**
  * @brief    
  * @rmtoll   ECCSR    DC    FL_FLASH_ClearFlag_ECCDetectionInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ECCDetectionInCodeFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->ECCSR, FLASH_ECCSR_DC_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCSR    CC    FL_FLASH_IsActiveFlag_ECCCorrectionInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCCorrectionInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCSR, FLASH_ECCSR_CC_Msk) == (FLASH_ECCSR_CC_Msk));
}

/**
  * @brief    
  * @rmtoll   ECCSR    CC    FL_FLASH_ClearFlag_ECCCorrectionInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ECCCorrectionInCodeFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->ECCSR, FLASH_ECCSR_CC_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCSR    BE    FL_FLASH_IsActiveFlag_ECCBitErrorInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCBitErrorInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCSR, FLASH_ECCSR_BE_Msk) == (FLASH_ECCSR_BE_Msk));
}

/**
  * @brief    
  * @rmtoll   ECCIER    DDIE    FL_FLASH_EnableIT_ECCDetectionInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_ECCDetectionInDataFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->ECCIER, FLASH_ECCIER_DDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCIER    DDIE    FL_FLASH_DisableIT_ECCDetectionInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_ECCDetectionInDataFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->ECCIER, FLASH_ECCIER_DDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCIER    DDIE    FL_FLASH_IsEnabledIT_ECCDetectionInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_ECCDetectionInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCIER, FLASH_ECCIER_DDIE_Msk) == FLASH_ECCIER_DDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCIER    CDIE    FL_FLASH_EnableIT_ECCCorrectionInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_ECCCorrectionInDataFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->ECCIER, FLASH_ECCIER_CDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCIER    CDIE    FL_FLASH_DisableIT_ECCCorrectionInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_ECCCorrectionInDataFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->ECCIER, FLASH_ECCIER_CDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCIER    CDIE    FL_FLASH_IsEnabledIT_ECCCorrectionInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_ECCCorrectionInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCIER, FLASH_ECCIER_CDIE_Msk) == FLASH_ECCIER_CDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCIER    DCIE    FL_FLASH_EnableIT_ECCDetectionInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_ECCDetectionInCodeFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->ECCIER, FLASH_ECCIER_DCIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCIER    DCIE    FL_FLASH_DisableIT_ECCDetectionInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_ECCDetectionInCodeFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->ECCIER, FLASH_ECCIER_DCIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCIER    DCIE    FL_FLASH_IsEnabledIT_ECCDetectionInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_ECCDetectionInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCIER, FLASH_ECCIER_DCIE_Msk) == FLASH_ECCIER_DCIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCIER    CCIE    FL_FLASH_EnableIT_ECCCorrectionInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_ECCCorrectionInCodeFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->ECCIER, FLASH_ECCIER_CCIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCIER    CCIE    FL_FLASH_DisableIT_ECCCorrectionInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_ECCCorrectionInCodeFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->ECCIER, FLASH_ECCIER_CCIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCIER    CCIE    FL_FLASH_IsEnabledIT_ECCCorrectionInCodeFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_ECCCorrectionInCodeFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCIER, FLASH_ECCIER_CCIE_Msk) == FLASH_ECCIER_CCIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCEAR    ERR_ADDR    FL_FLASH_ReadCodeECCErrorAddress
  * @param    FLASHx FLASH instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_FLASH_ReadCodeECCErrorAddress(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCEAR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    
  * @rmtoll   ECCEAR    ERR_ADDR    FL_FLASH_ReadDataECCErrorAddress
  * @param    FLASHx FLASH instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_FLASH_ReadDataECCErrorAddress(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCEAR, (0xfffU << 0U)) >> 20U);
}

/**
  * @brief    
  * @rmtoll   ECCCR    CECCR    FL_FLASH_EnableCECC
  * @param    FLASHx FLASH instance
  * @param    key 
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableCECC(FLASH_Type* FLASHx)
{
    MODIFY_REG(FLASHx->ECCCR, (0xffU << 8U), (0x00 << 8U));
}

/**
  * @brief    
  * @rmtoll   ECCCR    CECCR    FL_FLASH_DisableCECC
  * @param    FLASHx FLASH instance
  * @retval   
  */
__STATIC_INLINE void FL_FLASH_DisableCECC(FLASH_Type* FLASHx)
{
    MODIFY_REG(FLASHx->ECCCR, (0xffU << 8U), (0xCC << 8U));
}

/**
  * @brief    
  * @rmtoll   ECCCR    CECCR    FL_I2C_Master_IsEnabledTimeout
  * @param    I2Cx I2C instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledCECC(FLASH_Type* FLASHx)
{
    return (uint32_t)READ_BIT(FLASHx->ECCCR, FLASH_ECCCR_CECCR_Msk);
}

/**
  * @brief    
  * @rmtoll   ECCCR    CECCR    FL_FLASH_EnableDECC
  * @param    FLASHx FLASH instance
  * @param    key 
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableDECC(FLASH_Type* FLASHx)
{
    MODIFY_REG(FLASHx->ECCCR, (0xffU << 8U), (0x00 << 0U));
}

/**
  * @brief    
  * @rmtoll   ECCCR    CECCR    FL_FLASH_DisableDECC
  * @param    FLASHx FLASH instance
  * @retval   
  */
__STATIC_INLINE void FL_FLASH_DisableDECC(FLASH_Type* FLASHx)
{
    MODIFY_REG(FLASHx->ECCCR, (0xffU << 8U), (0xCC << 0U));
}

/**
  * @brief    
  * @rmtoll   ECCCR    CECCR    FL_FLASH_IsEnabledDECC
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledDECC(FLASH_Type* FLASHx)
{
    return (uint32_t)READ_BIT(FLASHx->ECCCR, FLASH_ECCCR_DECCR_Msk);
}

/**
  * @brief    
  * @rmtoll   DEPCR    ERTYPE    FL_FLASH_SetDataFLASHEraseType
  * @param    FLASHx FLASH instance
  * @param    type This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_ERASE_TYPE_PAGE
  *           @arg @ref FL_FLASH_ERASE_TYPE_SECTOR
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetDataFLASHEraseType(FLASH_Type* FLASHx, uint32_t type)
{
    MODIFY_REG(FLASHx->DEPCR, FLASH_DEPCR_ERTYPE_Msk, type);
}

/**
  * @brief    
  * @rmtoll   DEPCR    ERTYPE    FL_FLASH_GetDataFLASHEraseType
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_ERASE_TYPE_PAGE
  *           @arg @ref FL_FLASH_ERASE_TYPE_SECTOR
  */
__STATIC_INLINE uint32_t FL_FLASH_GetDataFLASHEraseType(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DEPCR, FLASH_DEPCR_ERTYPE_Msk));
}

/**
  * @brief    
  * @rmtoll   DEPCR    PREQ    FL_FLASH_EnableProgramInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableProgramInDataFLASH(FLASH_Type* FLASHx)
{
   CLEAR_BIT(FLASHx->DEPCR, FLASH_DEPCR_EREQ_Msk);
    SET_BIT(FLASHx->DEPCR, FLASH_DEPCR_PREQ_Msk);
}

/**
  * @brief    
  * @rmtoll   DEPCR    EREQ    FL_FLASH_EnableEraseInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableEraseInDataFLASH(FLASH_Type* FLASHx)
{
   CLEAR_BIT(FLASHx->DEPCR, FLASH_DEPCR_PREQ_Msk);
    SET_BIT(FLASHx->DEPCR, FLASH_DEPCR_EREQ_Msk);
}

/**
  * @brief    
  * @rmtoll   DKEY        FL_FLASH_UnlockDataFLASH
  * @param    FLASHx FLASH instance
  * @param    key 
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_UnlockDataFLASH(FLASH_Type* FLASHx, uint32_t key)
{
    WRITE_REG(FLASHx->DKEY, key); 
}

/**
  * @brief    
  * @rmtoll   DKEY        FL_FLASH_LockDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_LockDataFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DKEY, 0xFFFFFFFF);
}

/**
  * @brief    
  * @rmtoll   DIER    LVIE    FL_FLASH_EnableIT_Voltage detectProgramErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_VoltageDetectProgramErrorInDataFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->DIER, FLASH_DIER_LVIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    LVIE    FL_FLASH_DisableIT_Voltage detectProgramErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_VoltageDetectProgramErrorInDataFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DIER, FLASH_DIER_LVIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    LVIE    FL_FLASH_IsEnabledIT_Voltage detectProgramErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_VoltageDetectProgramErrorInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DIER, FLASH_DIER_LVIE_Msk) == FLASH_DIER_LVIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    OPTIE    FL_FLASH_EnableIT_OTPProgramErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_OTPProgramErrorInDataFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->DIER, FLASH_DIER_OPTIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    OPTIE    FL_FLASH_DisableIT_OTPProgramErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_OTPProgramErrorInDataFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DIER, FLASH_DIER_OPTIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    OPTIE    FL_FLASH_IsEnabledIT_OTPProgramErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_OTPProgramErrorInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DIER, FLASH_DIER_OPTIE_Msk) == FLASH_DIER_OPTIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    AUTHIE    FL_FLASH_EnableIT_AuthenticationErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_AuthenticationErrorInDataFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->DIER, FLASH_DIER_AUTHIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    AUTHIE    FL_FLASH_DisableIT_AuthenticationErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_AuthenticationErrorInDataFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DIER, FLASH_DIER_AUTHIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    AUTHIE    FL_FLASH_IsEnabledIT_AuthenticationErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_AuthenticationErrorInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DIER, FLASH_DIER_AUTHIE_Msk) == FLASH_DIER_AUTHIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    KEYIE    FL_FLASH_EnableIT_KeyErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_KeyErrorInDataFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->DIER, FLASH_DIER_KEYIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    KEYIE    FL_FLASH_DisableIT_KeyErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_KeyErrorInDataFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DIER, FLASH_DIER_KEYIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    KEYIE    FL_FLASH_IsEnabledIT_KeyErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_KeyErrorInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DIER, FLASH_DIER_KEYIE_Msk) == FLASH_DIER_KEYIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CKIE    FL_FLASH_EnableIT_ClockErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_ClockErrorInDataFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->DIER, FLASH_DIER_CKIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CKIE    FL_FLASH_DisableIT_ClockErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_ClockErrorInDataFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DIER, FLASH_DIER_CKIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CKIE    FL_FLASH_IsEnabledIT_ClockErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_ClockErrorInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DIER, FLASH_DIER_CKIE_Msk) == FLASH_DIER_CKIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    PRDIE    FL_FLASH_EnableIT_ProgramCompleteInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_ProgramCompleteInDataFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->DIER, FLASH_DIER_PRDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    PRDIE    FL_FLASH_DisableIT_ProgramCompleteInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_ProgramCompleteInDataFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DIER, FLASH_DIER_PRDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    PRDIE    FL_FLASH_IsEnabledIT_ProgramCompleteInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_ProgramCompleteInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DIER, FLASH_DIER_PRDIE_Msk) == FLASH_DIER_PRDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    ERDIE    FL_FLASH_EnableIT_EraseCompleteInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_EraseCompleteInDataFLASH(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->DIER, FLASH_DIER_ERDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    ERDIE    FL_FLASH_DisableIT_EraseCompleteInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_EraseCompleteInDataFLASH(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DIER, FLASH_DIER_ERDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    ERDIE    FL_FLASH_IsEnabledIT_EraseCompleteInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_EraseCompleteInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DIER, FLASH_DIER_ERDIE_Msk) == FLASH_DIER_ERDIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DISR    CONF    FL_FLASH_IsActiveFlag_TestModeInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_TestModeInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DISR, FLASH_DISR_CONF_Msk) == (FLASH_DISR_CONF_Msk));
}

/**
  * @brief    
  * @rmtoll   DISR    KEYSTA    FL_FLASH_GetFLASHLockStatusInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_KEY_STATUS_LOCK
  *           @arg @ref FL_FLASH_KEY_STATUS_ALL_ERASE
  *           @arg @ref FL_FLASH_KEY_STATUS_PAGE_ERASE
  *           @arg @ref FL_FLASH_KEY_STATUS_PROGRAM
  *           @arg @ref FL_FLASH_KEY_STATUS_ERROR
  *           @arg @ref FL_FLASH_KEY_STATUS_SECTOR_ERASE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetFLASHLockStatusInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DISR, FLASH_DISR_KEYSTA_Msk));
}

/**
  * @brief    
  * @rmtoll   DISR    LVERR    FL_FLASH_IsActiveFlag_SVDVoltagedetectFallingErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_SVDVoltagedetectFallingErrorInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DISR, FLASH_DISR_LVERR_Msk) == (FLASH_DISR_LVERR_Msk));
}

/**
  * @brief    
  * @rmtoll   DISR    LVERR    FL_FLASH_ClearFlag_SVDVoltagedetectFallingErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_SVDVoltagedetectFallingErrorInDataFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DISR, FLASH_DISR_LVERR_Msk);
}

/**
  * @brief    
  * @rmtoll   DISR    AUTHERR    FL_FLASH_IsActiveFlag_AuthenticationErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_AuthenticationErrorInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DISR, FLASH_DISR_AUTHERR_Msk) == (FLASH_DISR_AUTHERR_Msk));
}

/**
  * @brief    
  * @rmtoll   DISR    AUTHERR    FL_FLASH_ClearFlag_AuthenticationErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_AuthenticationErrorInDataFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DISR, FLASH_DISR_AUTHERR_Msk);
}

/**
  * @brief    
  * @rmtoll   DISR    KEYERR    FL_FLASH_IsActiveFlag_KeyErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_KeyErrorInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DISR, FLASH_DISR_KEYERR_Msk) == (FLASH_DISR_KEYERR_Msk));
}

/**
  * @brief    
  * @rmtoll   DISR    KEYERR    FL_FLASH_ClearFlag_KeyErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_KeyErrorInDataFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DISR, FLASH_DISR_KEYERR_Msk);
}

/**
  * @brief    
  * @rmtoll   DISR    CKERR    FL_FLASH_IsActiveFlag_ClockErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ClockErrorInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DISR, FLASH_DISR_CKERR_Msk) == (FLASH_DISR_CKERR_Msk));
}

/**
  * @brief    
  * @rmtoll   DISR    CKERR    FL_FLASH_ClearFlag_ClockErrorInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ClockErrorInDataFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DISR, FLASH_DISR_CKERR_Msk);
}

/**
  * @brief    
  * @rmtoll   DISR    PRD    FL_FLASH_IsActiveFlag_ProgramCompleteInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ProgramCompleteInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DISR, FLASH_DISR_PRD_Msk) == (FLASH_DISR_PRD_Msk));
}

/**
  * @brief    
  * @rmtoll   DISR    PRD    FL_FLASH_ClearFlag_ProgramCompleteInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ProgramCompleteInDataFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DISR, FLASH_DISR_PRD_Msk);
}

/**
  * @brief    
  * @rmtoll   DISR    ERD    FL_FLASH_IsActiveFlag_EraseCompleteInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_EraseCompleteInDataFLASH(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DISR, FLASH_DISR_ERD_Msk) == (FLASH_DISR_ERD_Msk));
}

/**
  * @brief    
  * @rmtoll   DISR    ERD    FL_FLASH_ClearFlag_EraseCompleteInDataFLASH
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_EraseCompleteInDataFLASH(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DISR, FLASH_DISR_ERD_Msk);
}

/**
  * @}
  */

/** @defgroup FLASH_FL_EF_Init Initialization and de-initialization functions
  * @{
  */

/**
  * @}
  */

FL_ErrorStatus FL_FLASH_CodePageErase(FLASH_Type *FLASHx, uint32_t address);
FL_ErrorStatus FL_FLASH_CodeSectorErase(FLASH_Type *FLASHx, uint32_t address);
FL_ErrorStatus FL_FLASH_CodeProgram_Word(FLASH_Type *FLASHx, uint32_t address, uint32_t data);
FL_ErrorStatus FL_FLASH_CodeProgram_Page(FLASH_Type *FLASHx, uint32_t pageNum, uint32_t *data);
FL_ErrorStatus FL_FLASH_CodeProgram_Sector(FLASH_Type *FLASHx, uint32_t sectorNum, uint32_t *data);
FL_ErrorStatus FL_FLASH_DataPageErase(FLASH_Type *FLASHx, uint32_t address);
FL_ErrorStatus FL_FLASH_DataSectorErase(FLASH_Type *FLASHx, uint32_t address);
FL_ErrorStatus FL_FLASH_DataProgram_Word(FLASH_Type *FLASHx, uint32_t address, uint32_t data);
FL_ErrorStatus FL_FLASH_DataProgram_Page(FLASH_Type *FLASHx, uint32_t pageNum, uint32_t *data);
FL_ErrorStatus FL_FLASH_DataProgram_Sector(FLASH_Type *FLASHx, uint32_t sectorNum, uint32_t *data);


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FH0XX_FL_FLASH_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2024-02-22*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
