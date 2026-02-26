 /**   
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_flash.c
  * @author  FMSH Application Team
  * @brief   Source file of FLASH FL Module
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

/* Includes ------------------------------------------------------------------*/
#include "fm33fh0xx_fl.h"

/** @addtogroup FM33FH0xx_FL_Driver
  * @{
  */

/** @addtogroup FLASH
  * @{
  */

#ifdef FL_FLASH_DRIVER_ENABLED
/* Private macros ------------------------------------------------------------*/
/** @addtogroup FLASH_FL_Private_Macros
  * @{
  */

#define    IS_FLASH_ALL_INSTANCE(INTENCE)               ((INTENCE) == FLASH)

#define    IS_FL_FLASH_CODE_MAX_ADDR(__VALUE__)         ((uint32_t)(__VALUE__) <= (FL_FLASH_CODE_ADDR_MAXPROGRAM))
           
#define    IS_FL_FLASH_CODE_MAX_PAGE(__VALUE__)         ((uint32_t)(__VALUE__) < (FL_FLASH_CODE_MAX_PAGE_NUM))
           
#define    IS_FL_FLASH_CODE_MAX_SECTOR(__VALUE__)       ((uint32_t)(__VALUE__) < (FL_FLASH_CODE_MAX_SECTOR_NUM))


#define    IS_FL_FLASH_INFO_MAX_ADDR(__VALUE__)         ((((uint32_t)(FL_FLASH_INFO_ADDR_MINPROGRAM)) <= (__VALUE__)) &&\
                                                         ((__VALUE__) <= (FL_FLASH_INFO_ADDR_MAXPROGRAM)))
           
#define    IS_FL_FLASH_INFO_MAX_PAGE(__VALUE__)         ((uint32_t)(__VALUE__) < (FL_FLASH_INFO_MAX_PAGE_NUM))
           
#define    IS_FL_FLASH_INFO_MAX_SECTOR(__VALUE__)       ((uint32_t)(__VALUE__) < (FL_FLASH_IFFO_MAX_SECTOR_NUM))


#define    IS_FL_FLASH_DATA_MAX_ADDR(__VALUE__)         ((((uint32_t)(FL_FLASH_DATA_ADDR_MINPROGRAM)) <= (__VALUE__)) &&\
                                                         ((__VALUE__) <= (FL_FLASH_DATA_ADDR_MAXPROGRAM)))
                                                         
#define    IS_FL_FLASH_DATA_MAX_PAGE(__VALUE__)         ((__VALUE__) < (FL_FLASH_DATA_MAX_PAGE_NUM))
           
#define    IS_FL_FLASH_DATA_MAX_SECTOR(__VALUE__)       ((__VALUE__) < (FL_FLASH_DATA_MAX_SECTOR_NUM))
                                                     

/**
  * @}
  */


/* Private function prototypes -----------------------------------------------*/
/** @defgroup FLASH_FL_Private_Functions FLASH Private Functions
  * @{
  */



/** @addtogroup FLASH_FL_EF_Init
  * @{
  */

/**
  * @brief  Code Flash 页擦除函数，一个页为512byte.
  * @param  FLASHx FLASH Port
  * @param  address 为需要擦除的页内任意地址，推荐使用页开始的首地址（字对齐）

  *         .
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 擦写发生错误
  *         -FL_PASS 擦写成功
  */
FL_ErrorStatus FL_FLASH_CodePageErase(FLASH_Type *FLASHx, uint32_t address)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus ret = FL_FAIL;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param((IS_FL_FLASH_CODE_MAX_ADDR((uint32_t)address)) ||\
                 (IS_FL_FLASH_INFO_MAX_ADDR((uint32_t)address)));
    /*时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_WORD_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    if(FL_FLASH_IsActiveFlag_KeyErrorInCodeFLASH(FLASHx) == FL_FLASH_KEY_STATUS_CODEFLASH_ERROR)
    {
        /*Code Flash 已经锁定，复位前无法操作*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    /* 擦写时钟使能*/
    FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
    /* 配置擦写类型*/
    FL_FLASH_SetCodeFLASHEraseType(FLASHx, FL_FLASH_ERASE_TYPE_CODEFLASH_PAGE);
    /* 开始擦除页*/
    FL_FLASH_EnableEraseInCodeFLASH(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_UnlockCodeFLASH(FLASHx, FL_FLASH_ERASE_KEY);
    FL_FLASH_UnlockCodeFLASH(FLASHx, FL_FLASH_PGAE_ERASE_KEY);
    
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_ProgramCompleteInCodeFLASH(FLASHx);
    FL_FLASH_ClearFlag_ClockErrorInCodeFLASH(FLASHx);
    FL_FLASH_ClearFlag_KeyErrorInCodeFLASH(FLASHx);
    FL_FLASH_ClearFlag_AuthenticationErrorInCodeFLASH(FLASHx);
    /* 擦请求 */
    *((uint32_t *)address) = FL_FLASH_ERASE_REQUEST;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_ClockErrorInCodeFLASH(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_KeyErrorInCodeFLASH(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationErrorInCodeFLASH(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01UL) || (KeyError == 0X01UL) || (AuthenticationError == 0X01UL))
        {
            /* 超时或出现错误 */
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_EraseCompleteInCodeFLASH(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_EraseCompleteInCodeFLASH(FLASHx);
                ret =  FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_LockCodeFLASH(FLASHx);
    FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    __set_PRIMASK(primask);
    return ret;
}

/**
  * @brief  Code Flash 扇区擦除函数，一个扇区为2k byte.
  * @param  FLASHx FLASH Port
  * @param  address 为需要擦除的扇区内任意地址，推荐使用扇区开始的首地址（字对齐）

  *         .
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 擦写发生错误
  *         -FL_PASS 擦写成功
  */
FL_ErrorStatus FL_FLASH_CodeSectorErase(FLASH_Type *FLASHx, uint32_t address)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus ret = FL_FAIL;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param((IS_FL_FLASH_CODE_MAX_ADDR((uint32_t)address)) ||\
                 (IS_FL_FLASH_INFO_MAX_ADDR((uint32_t)address)));
    /*时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_WORD_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    if(FL_FLASH_IsActiveFlag_KeyErrorInCodeFLASH(FLASHx) == FL_FLASH_KEY_STATUS_CODEFLASH_ERROR)
    {
        /*Code Flash 已经锁定，复位前无法操作*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    /* 擦写时钟使能*/
    FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
    /* 配置擦写类型*/
    FL_FLASH_SetCodeFLASHEraseType(FLASHx, FL_FLASH_ERASE_TYPE_CODEFLASH_SECTOR);
    /* 开始擦除页*/
    FL_FLASH_EnableEraseInCodeFLASH(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_UnlockCodeFLASH(FLASHx, FL_FLASH_ERASE_KEY);
    FL_FLASH_UnlockCodeFLASH(FLASHx, FL_FLASH_SECTOR_ERASE_KEY);
    
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_ProgramCompleteInCodeFLASH(FLASHx);
    FL_FLASH_ClearFlag_ClockErrorInCodeFLASH(FLASHx);
    FL_FLASH_ClearFlag_KeyErrorInCodeFLASH(FLASHx);
    FL_FLASH_ClearFlag_AuthenticationErrorInCodeFLASH(FLASHx);
    /* 擦请求 */
    *((uint32_t *)address) = FL_FLASH_ERASE_REQUEST;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_ClockErrorInCodeFLASH(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_KeyErrorInCodeFLASH(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationErrorInCodeFLASH(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01UL) || (KeyError == 0X01UL) || (AuthenticationError == 0X01UL))
        {
            /* 超时或出现错误 */
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_EraseCompleteInCodeFLASH(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_EraseCompleteInCodeFLASH(FLASHx);
                ret =  FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_LockCodeFLASH(FLASHx);
    FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    __set_PRIMASK(primask);
    return ret;
}

/**
  * @brief  Code Flash 单次字编程函数，编程地址必须对齐到字边界.
  * @param  FLASHx FLASH Port
  * @param  address 为需要编程的已经擦除过的扇区内任意地址，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_CodeProgram_Word(FLASH_Type *FLASHx, uint32_t address, uint32_t data)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus ret = FL_PASS;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param((IS_FL_FLASH_CODE_MAX_ADDR((uint32_t)address)) ||\
                 (IS_FL_FLASH_INFO_MAX_ADDR((uint32_t)address)));
    /*时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_WORD_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
   if(FL_FLASH_IsActiveFlag_KeyErrorInCodeFLASH(FLASHx) == FL_FLASH_KEY_STATUS_CODEFLASH_ERROR)
    {
        /*Code Flash 已经锁定，复位前无法操作*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    /* 擦写时钟使能*/
    FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
    /* 开始编程*/
    FL_FLASH_EnableProgramInCodeFLASH(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_UnlockCodeFLASH(FLASHx, FL_FLASH_PROGRAM_KEY1);
    FL_FLASH_UnlockCodeFLASH(FLASHx, FL_FLASH_PROGRAM_KEY2);
    
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_ProgramCompleteInCodeFLASH(FLASHx);
    FL_FLASH_ClearFlag_ClockErrorInCodeFLASH(FLASHx);
    FL_FLASH_ClearFlag_KeyErrorInCodeFLASH(FLASHx);
    FL_FLASH_ClearFlag_AuthenticationErrorInCodeFLASH(FLASHx);
    /* flash编程 Word*/
    *((uint32_t *)address) = data;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_ClockErrorInCodeFLASH(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_KeyErrorInCodeFLASH(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationErrorInCodeFLASH(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
        {
            /* 超时或出现错误 */
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_ProgramCompleteInCodeFLASH(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_ProgramCompleteInCodeFLASH(FLASHx);
                ret = FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_LockCodeFLASH(FLASHx);
    FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    __set_PRIMASK(primask);
    return ret;
}

/**
  * @brief  Code Flash 页编程函数，编程地址必须对齐到页边界.
  * @param  FLASHx FLASH Port
  * @param  PageNum 为需要编程的已经擦除过的页号，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_CodeProgram_Page(FLASH_Type *FLASHx, uint32_t pageNum, uint32_t *data)
{
    uint32_t count;
    uint32_t primask;
    uint32_t address;
    uint32_t timeout;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus status = FL_FAIL;
    if(data != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
        assert_param(IS_FL_FLASH_CODE_MAX_PAGE((uint32_t)pageNum));
        address = pageNum * FL_FLASH_CODE_PGAE_SIZE_BYTE;
        /* 注意：不包含Information0~3 page */
        assert_param(IS_FL_FLASH_CODE_MAX_ADDR((uint32_t)address));
        /* 时钟使能*/
        FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        /* 页地址对齐检查 */
        if((address % FL_FLASH_CODE_PGAE_SIZE_BYTE) != 0)
        {
            /*地址未对齐*/
            FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
            return FL_FAIL;
        }
        /* 擦写时钟使能*/
        FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
        /* 开始编程*/
        FL_FLASH_EnableProgramInCodeFLASH(FLASHx);
        /* Key 序列*/
        primask = __get_PRIMASK();
        __disable_irq();
        FL_FLASH_UnlockCodeFLASH(FLASHx, FL_FLASH_PROGRAM_KEY1);
        FL_FLASH_UnlockCodeFLASH(FLASHx, FL_FLASH_PROGRAM_KEY2);
        
        /* 清除中断标志*/
        FL_FLASH_ClearFlag_ProgramCompleteInCodeFLASH(FLASHx);
        FL_FLASH_ClearFlag_ClockErrorInCodeFLASH(FLASHx);
        FL_FLASH_ClearFlag_KeyErrorInCodeFLASH(FLASHx);
        FL_FLASH_ClearFlag_AuthenticationErrorInCodeFLASH(FLASHx);
        for(count = 0; count < FL_FLASH_CODE_PGAE_SIZE_BYTE; count += 4)
        {
            timeout = 0;
            FL_FLASH_EnableProgramInCodeFLASH(FLASHx);
            *((uint32_t *)address) = *data;
            address += 4;
            data++;
            while(1)
            {
                timeout++;
                ClockError = FL_FLASH_IsActiveFlag_ClockErrorInCodeFLASH(FLASHx);
                KeyError = FL_FLASH_IsActiveFlag_KeyErrorInCodeFLASH(FLASHx);
                AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationErrorInCodeFLASH(FLASHx);
                if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
                {
                    /* 超时或出现错误 */
                    status = FL_FAIL;
                    break;
                }
                else
                {
                    if(FL_FLASH_IsActiveFlag_ProgramCompleteInCodeFLASH(FLASHx) == 0X01U)
                    {
                        /*编程成功*/
                        FL_FLASH_ClearFlag_ProgramCompleteInCodeFLASH(FLASHx);
                        status = FL_PASS;
                        break;
                    }
                }
            }
        }
        FL_FLASH_LockCodeFLASH(FLASHx);
        FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        __set_PRIMASK(primask);
    }
    return status;
}

/**
  * @brief  Code Flash 扇区编程函数，编程地址必须对齐到扇区边界.
  * @param  FLASHx FLASH Port
  * @param  sectorNum 为需要编程的已经擦除过的扇区号，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_CodeProgram_Sector(FLASH_Type *FLASHx, uint32_t sectorNum, uint32_t *data)
{
    uint32_t count;
    uint32_t primask;
    uint32_t address;
    uint32_t timeout;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus status = FL_FAIL;
    if(data != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
        assert_param(IS_FL_FLASH_CODE_MAX_SECTOR((uint32_t)sectorNum));
        address = sectorNum * FL_FLASH_CODE_SECTOR_SIZE_BYTE;
        /* 注意：不包含Information0~3 page */
        assert_param(IS_FL_FLASH_CODE_MAX_ADDR((uint32_t)address));
        /*时钟使能*/
        FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        /* 地址对齐检查 */
        if((address % FL_FLASH_CODE_SECTOR_SIZE_BYTE) != 0)
        {
            /*地址未对齐*/
            FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
            return FL_FAIL;
        }
        /* 擦写时钟使能*/
        FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
        /* 开始编程*/
        FL_FLASH_EnableProgramInCodeFLASH(FLASHx);
        /* Key 序列*/
        primask = __get_PRIMASK();
        __disable_irq();
        FL_FLASH_UnlockCodeFLASH(FLASHx, FL_FLASH_PROGRAM_KEY1);
        FL_FLASH_UnlockCodeFLASH(FLASHx, FL_FLASH_PROGRAM_KEY2);
        
        /* 清除中断标志*/
        FL_FLASH_ClearFlag_ProgramCompleteInCodeFLASH(FLASHx);
        FL_FLASH_ClearFlag_ClockErrorInCodeFLASH(FLASHx);
        FL_FLASH_ClearFlag_KeyErrorInCodeFLASH(FLASHx);
        FL_FLASH_ClearFlag_AuthenticationErrorInCodeFLASH(FLASHx);
        for(count = 0; count < FL_FLASH_CODE_SECTOR_SIZE_BYTE; count += 4)
        {
            timeout = 0;
            FL_FLASH_EnableProgramInCodeFLASH(FLASHx);
            *((uint32_t *)address) =  *data;
            address += 4;
            data++;
            while(1)
            {
                timeout++;
                ClockError = FL_FLASH_IsActiveFlag_ClockErrorInCodeFLASH(FLASHx);
                KeyError = FL_FLASH_IsActiveFlag_KeyErrorInCodeFLASH(FLASHx);
                AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationErrorInCodeFLASH(FLASHx);
                if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
                {
                    /* 超时或出现错误 */
                    status = FL_FAIL;
                    break;
                }
                else
                {
                    if(FL_FLASH_IsActiveFlag_ProgramCompleteInCodeFLASH(FLASHx) == 0X01U)
                    {
                          /*编程成功*/
                          FL_FLASH_ClearFlag_ProgramCompleteInCodeFLASH(FLASHx);
                          status = FL_PASS;
                          break;
                    }
                }
            }
        }
        FL_FLASH_LockCodeFLASH(FLASHx);
        FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        __set_PRIMASK(primask);
    }
    return status;
}


/**
  * @brief  Date Flash 页擦除函数，一个页为512byte.
  * @param  FLASHx FLASH Port
  * @param  address 为需要擦除的页内任意地址，推荐使用页开始的首地址（字对齐）

  *         .
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 擦写发生错误
  *         -FL_PASS 擦写成功
  */
FL_ErrorStatus FL_FLASH_DataPageErase(FLASH_Type *FLASHx, uint32_t address)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus ret = FL_FAIL;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param(IS_FL_FLASH_DATA_MAX_ADDR((uint32_t)address));
    /*时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_WORD_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    if(FL_FLASH_GetFLASHLockStatusInDataFLASH(FLASHx) == FL_FLASH_KEY_STATUS_DATAFLASH_ERROR)
    {
        /*Data Flash 已经锁定，复位前无法操作*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    /*FLASH擦写时钟使能*/
    FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
    /*配置擦写类型*/
    FL_FLASH_SetDataFLASHEraseType(FLASHx, FL_FLASH_ERASE_TYPE_DATAFLASH_PAGE);
    /* 开始擦除页*/
    FL_FLASH_EnableEraseInDataFLASH(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_UnlockDataFLASH(FLASHx, FL_FLASH_ERASE_KEY);
    FL_FLASH_UnlockDataFLASH(FLASHx, FL_FLASH_PGAE_ERASE_KEY);
    __set_PRIMASK(primask);
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_ProgramCompleteInDataFLASH(FLASHx);
    FL_FLASH_ClearFlag_ClockErrorInDataFLASH(FLASHx);
    FL_FLASH_ClearFlag_KeyErrorInDataFLASH(FLASHx);
    FL_FLASH_ClearFlag_AuthenticationErrorInDataFLASH(FLASHx);
    /* 擦请求 */
    *((uint32_t *)address) = FL_FLASH_ERASE_REQUEST;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_ClockErrorInDataFLASH(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_KeyErrorInDataFLASH(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationErrorInDataFLASH(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
        {
            /* 超时或出现错误 */
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_EraseCompleteInDataFLASH(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_EraseCompleteInDataFLASH(FLASHx);
                ret = FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_LockDataFLASH(FLASHx);
    FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    return ret;
}

/**
  * @brief  Data Flash 扇区擦除函数，一个扇区为2k byte.
  * @param  FLASHx FLASH Port
  * @param  address 为需要擦除的扇区内任意地址，推荐使用扇区开始的首地址（字对齐）

  *         .
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 擦写发生错误
  *         -FL_PASS 擦写成功
  */
FL_ErrorStatus FL_FLASH_DataSectorErase(FLASH_Type *FLASHx, uint32_t address)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus ret = FL_FAIL;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param(IS_FL_FLASH_DATA_MAX_ADDR((uint32_t)address));
    /*时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_WORD_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    if(FL_FLASH_GetFLASHLockStatusInDataFLASH(FLASHx) == FL_FLASH_KEY_STATUS_DATAFLASH_ERROR)
    {
        /*Data Flash 已经锁定，复位前无法操作*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    /*FLASH擦写时钟使能*/
    FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
    /*配置擦写类型*/
    FL_FLASH_SetDataFLASHEraseType(FLASHx, FL_FLASH_ERASE_TYPE_DATAFLASH_SECTOR);
    /* 开始擦除页*/
    FL_FLASH_EnableEraseInDataFLASH(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_UnlockDataFLASH(FLASHx, FL_FLASH_ERASE_KEY);
    FL_FLASH_UnlockDataFLASH(FLASHx, FL_FLASH_SECTOR_ERASE_KEY);
    __set_PRIMASK(primask);
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_ProgramCompleteInDataFLASH(FLASHx);
    FL_FLASH_ClearFlag_ClockErrorInDataFLASH(FLASHx);
    FL_FLASH_ClearFlag_KeyErrorInDataFLASH(FLASHx);
    FL_FLASH_ClearFlag_AuthenticationErrorInDataFLASH(FLASHx);
    /* 擦请求 */
    *((uint32_t *)address) = FL_FLASH_ERASE_REQUEST;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_ClockErrorInDataFLASH(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_KeyErrorInDataFLASH(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationErrorInDataFLASH(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
        {
            /* 超时或出现错误 */
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_EraseCompleteInDataFLASH(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_EraseCompleteInDataFLASH(FLASHx);
                ret = FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_LockDataFLASH(FLASHx);
    FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    return ret;
}

/**
  * @brief  Data Flash 单次字编程函数，编程地址必须对齐到字边界.
  * @param  FLASHx FLASH Port
  * @param  address 为需要编程的已经擦除过的扇区内任意地址，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_DataProgram_Word(FLASH_Type *FLASHx, uint32_t address, uint32_t data)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus ret = FL_PASS;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param(IS_FL_FLASH_DATA_MAX_ADDR((uint32_t)address));
    /*时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_WORD_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    if(FL_FLASH_GetFLASHLockStatusInDataFLASH(FLASHx) == FL_FLASH_KEY_STATUS_DATAFLASH_ERROR)
    {
        /*Data Flash 已经锁定，复位前无法操作*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    /*FLASH擦写时钟使能*/
    FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
    /* 开始编程*/
    FL_FLASH_EnableProgramInDataFLASH(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_UnlockDataFLASH(FLASHx, FL_FLASH_PROGRAM_KEY1);
    FL_FLASH_UnlockDataFLASH(FLASHx, FL_FLASH_PROGRAM_KEY2);
    __set_PRIMASK(primask);
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_ProgramCompleteInDataFLASH(FLASHx);
    FL_FLASH_ClearFlag_ClockErrorInDataFLASH(FLASHx);
    FL_FLASH_ClearFlag_KeyErrorInDataFLASH(FLASHx);
    FL_FLASH_ClearFlag_AuthenticationErrorInDataFLASH(FLASHx);
    /* flash编程 Word*/
    *((uint32_t *)address) = data;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_ClockErrorInDataFLASH(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_KeyErrorInDataFLASH(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationErrorInDataFLASH(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
        {
            /* 超时或出现错误 */
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_ProgramCompleteInDataFLASH(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_ProgramCompleteInDataFLASH(FLASHx);
                ret = FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_LockDataFLASH(FLASHx);
    FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    return ret;
}

/**
  * @brief  Data Flash 页编程函数，编程地址必须对齐到页边界.
  * @param  FLASHx FLASH Port
  * @param  PageNum 为需要编程的已经擦除过的页号，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_DataProgram_Page(FLASH_Type *FLASHx, uint32_t pageNum, uint32_t *data)
{
    uint32_t count;
    uint32_t primask;
    uint32_t address;
    uint32_t timeout;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus status = FL_FAIL;
    if(data != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
        assert_param(IS_FL_FLASH_DATA_MAX_PAGE((uint32_t)pageNum));
        address = pageNum * FL_FLASH_DATA_PGAE_SIZE_BYTE + FL_FLASH_DATA_ADDR_MINPROGRAM;
        assert_param(IS_FL_FLASH_DATA_MAX_ADDR((uint32_t)address));
        /* 时钟使能*/
        FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        /* 页地址对齐检查 */
        if((address % FL_FLASH_DATA_PGAE_SIZE_BYTE) != 0)
        {
            /*地址未对齐*/
            FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
            return FL_FAIL;
        }
        /*FLASH擦写时钟使能*/
        FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
        /* 开始编程*/
        FL_FLASH_EnableProgramInDataFLASH(FLASHx);
        /* Key 序列*/
        primask = __get_PRIMASK();
        __disable_irq();
        FL_FLASH_UnlockDataFLASH(FLASHx, FL_FLASH_PROGRAM_KEY1);
        FL_FLASH_UnlockDataFLASH(FLASHx, FL_FLASH_PROGRAM_KEY2);
        __set_PRIMASK(primask);
        /* 清除中断标志*/
        FL_FLASH_ClearFlag_ProgramCompleteInDataFLASH(FLASHx);
        FL_FLASH_ClearFlag_ClockErrorInDataFLASH(FLASHx);
        FL_FLASH_ClearFlag_KeyErrorInDataFLASH(FLASHx);
        FL_FLASH_ClearFlag_AuthenticationErrorInDataFLASH(FLASHx);
        for(count = 0; count < FL_FLASH_DATA_PGAE_SIZE_BYTE; count += 4)
        {
            timeout = 0;
            FL_FLASH_EnableProgramInDataFLASH(FLASHx);
            *((uint32_t *)address) = *data;
            address += 4;
            data++;
            while(1)
            {
                timeout++;
                ClockError = FL_FLASH_IsActiveFlag_ClockErrorInDataFLASH(FLASHx);
                KeyError = FL_FLASH_IsActiveFlag_KeyErrorInDataFLASH(FLASHx);
                AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationErrorInDataFLASH(FLASHx);
                if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
                {
                    /* 超时或出现错误 */
                    status = FL_FAIL;
                    break;
                }
                else
                {
                    if(FL_FLASH_IsActiveFlag_ProgramCompleteInDataFLASH(FLASHx) == 0X01U)
                    {
                        /*编程成功*/
                        FL_FLASH_ClearFlag_ProgramCompleteInDataFLASH(FLASHx);
                        status = FL_PASS;
                        break;
                    }
                }
            }
        }
        FL_FLASH_LockDataFLASH(FLASHx);
        FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    }
    return status;
}

/**
  * @brief  Data Flash 扇区编程函数，编程地址必须对齐到扇区边界.
  * @param  FLASHx FLASH Port
  * @param  sectorNum 为需要编程的已经擦除过的扇区号，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_DataProgram_Sector(FLASH_Type *FLASHx, uint32_t sectorNum, uint32_t *data)
{
    uint32_t count;
    uint32_t primask;
    uint32_t address;
    uint32_t timeout;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus status = FL_FAIL;
    if(data != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
        assert_param(IS_FL_FLASH_DATA_MAX_SECTOR((uint32_t)sectorNum));
        address = sectorNum * FL_FLASH_DATA_SECTOR_SIZE_BYTE + FL_FLASH_DATA_ADDR_MINPROGRAM;
        assert_param(IS_FL_FLASH_DATA_MAX_ADDR((uint32_t)address));
        /*时钟使能*/
        FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        /* 页地址对齐检查 */
        if((address % FL_FLASH_DATA_SECTOR_SIZE_BYTE) != 0)
        {
            /*地址未对齐*/
            FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
            return FL_FAIL;
        }
        /*FLASH擦写时钟使能*/
        FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
        /* 开始编程*/
        FL_FLASH_EnableProgramInDataFLASH(FLASHx);
        /* Key 序列*/
        primask = __get_PRIMASK();
        __disable_irq();
        FL_FLASH_UnlockDataFLASH(FLASHx, FL_FLASH_PROGRAM_KEY1);
        FL_FLASH_UnlockDataFLASH(FLASHx, FL_FLASH_PROGRAM_KEY2);
        __set_PRIMASK(primask);
        /* 清除中断标志*/
        FL_FLASH_ClearFlag_ProgramCompleteInDataFLASH(FLASHx);
        FL_FLASH_ClearFlag_ClockErrorInDataFLASH(FLASHx);
        FL_FLASH_ClearFlag_KeyErrorInDataFLASH(FLASHx);
        FL_FLASH_ClearFlag_AuthenticationErrorInDataFLASH(FLASHx);
        for(count = 0; count < FL_FLASH_DATA_SECTOR_SIZE_BYTE; count += 4)
        {
            timeout = 0;
            FL_FLASH_EnableProgramInDataFLASH(FLASHx);
            *((uint32_t *)address) = *data;
            address += 4;
            data++;
            while(1)
            {
                timeout++;
                ClockError = FL_FLASH_IsActiveFlag_ClockErrorInDataFLASH(FLASHx);
                KeyError = FL_FLASH_IsActiveFlag_KeyErrorInDataFLASH(FLASHx);
                AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationErrorInDataFLASH(FLASHx);
                if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
                {
                    /* 超时或出现错误 */
                    status = FL_FAIL;
                    break;
                }
                else
                {
                    if(FL_FLASH_IsActiveFlag_ProgramCompleteInDataFLASH(FLASHx) == 0X01U)
                    {
                        /*编程成功*/
                        FL_FLASH_ClearFlag_ProgramCompleteInDataFLASH(FLASHx);
                        status = FL_PASS;
                        break;
                    }
                }
            }
        }
        FL_FLASH_LockDataFLASH(FLASHx);
        FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_FLASH);
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    }
    return status;
}



/**
  * @}
  */

#endif /* FL_FLASH_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
