/**
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_sent.c
  * @author  FMSH Application Team
  * @brief   Src file of SENT FL Module
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

/* Includes ------------------------------------------------------------------*/
#include "fm33fh0xx_fl.h"
#include <stdlib.h>
/** @addtogroup FM33FH0XX_FL_Driver
  * @{
  */

/** @addtogroup SENT
  * @{
  */

#ifdef FL_SENT_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup SENT_FL_Private_Macros
  * @{
  */
#define    IS_FL_SENT_INSTANCE(INTANCE)                     (((INTANCE) == SENT0)||\
                                                             ((INTANCE) == SENT1))

#define    IS_FL_SENT_CLOCK_SRC(__VALUE__)                  (((__VALUE__) == FL_CMU_PBCCR3_SENT0_PCE_CLK)||\
                                                             ((__VALUE__) == FL_CMU_GROUP3_BUSCLK_SENT1))

#define    IS_FL_SENT_TRANSFER_DIRECTION(__VALUE__)         (((__VALUE__) == FL_SENT_MODE_RX)||\
                                                             ((__VALUE__) == FL_SENT_MODE_TX))

#define    IS_FL_SENT_DIGITAL_FILTER_LENGTH(__VALUE__)      ((__VALUE__) <= 0x000000FF)

#define    IS_FL_SENT_PSC(__VALUE__)                        ((__VALUE__) <= 0x0000FFFF)

#define    IS_FL_SENT_TRANSMIT_MODE(__VALUE__)              (((__VALUE__) == FL_SENT_TXMODE_SOFTWARE)||\
                                                             ((__VALUE__) == FL_SENT_TXMODE_SERIAL))

#define    IS_FL_SENT_NIBBLE_NUMBER(__VALUE__)              (((__VALUE__) == FL_SENT_DATANIBBLES_COUNT_1N)||\
                                                             ((__VALUE__) == FL_SENT_DATANIBBLES_COUNT_2N)||\
                                                             ((__VALUE__) == FL_SENT_DATANIBBLES_COUNT_3N)||\
                                                             ((__VALUE__) == FL_SENT_DATANIBBLES_COUNT_4N)||\
                                                             ((__VALUE__) == FL_SENT_DATANIBBLES_COUNT_5N)||\
                                                             ((__VALUE__) == FL_SENT_DATANIBBLES_COUNT_6N))

#define    IS_FL_SENT_CRCMODE(__VALUE__)                    (((__VALUE__) == FL_SENT_CRCMODE_RECOMMENDED)||\
                                                             ((__VALUE__) == FL_SENT_CRCMODE_LEGACY))

#define    IS_FL_SENT_IDLEPULSE(__VALUE__)                  (((__VALUE__) == FL_SENT_IDLEOUTPUT_HIGH)||\
                                                             ((__VALUE__) == FL_SENT_IDLEOUTPUT_LOW))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup SENT_FL_EF_Init
  * @{
  */

/**
  * @brief  复位SENT 外设
  * @param  外设入口地址
  * @retval 返回错误状态，可能值：
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_SENT_DeInit(SENT_Type *SENTx)
{
    /* 参数检查 */
    assert_param(IS_FL_SENT_INSTANCE(SENTx));
    /* 使能外设复位 */
    FL_RMU_EnablePeripheralReset(RMU);

    if(SENTx == SENT0)
    {
        /* 复位外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_SENT0);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_SENT0);
        /* 关闭外设总线时钟和工作时钟 */
        FL_CMU_DisableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_SENT0);
    }
    else if(SENTx == SENT1)
    {
        /* 复位外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_SENT1);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_SENT1);
        /* 关闭外设总线时钟和工作时钟 */
        FL_CMU_DisableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_SENT1);
    }
    else
    {
        return FL_FAIL;
    }
    /* 锁定外设复位 */
    FL_RMU_DisablePeripheralReset(RMU);
    return FL_PASS;
}


/**
  * @brief  根据需要配置SETN
  *
  * @param  SENTx  外设入口地址
  * @param  initStruct指向一个FL_SENT_InitTypeDef类型的结构体,它包含外设SENT的配置信息
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置成功
  */
FL_ErrorStatus FL_SENT_Init(SENT_Type *SENTx, FL_SENT_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    /* 参数检查 */
    assert_param(IS_FL_SENT_INSTANCE(SENTx));
    assert_param(IS_FL_SENT_TRANSFER_DIRECTION(initStruct->transferDirection));
    assert_param(IS_FL_SENT_DIGITAL_FILTER_LENGTH(initStruct->digitalFilterLength));
    assert_param(IS_FL_SENT_PSC(initStruct->prescaler));
    assert_param(IS_FL_SENT_TRANSMIT_MODE(initStruct->transmitMode));
    assert_param(IS_FL_SENT_NIBBLE_NUMBER(initStruct->dataNibbleNumber));
    assert_param(IS_FL_SENT_CRCMODE(initStruct->CRCMode));
    assert_param(IS_FL_SENT_IDLEPULSE(initStruct->idleoutputpulse));

    if(SENTx == SENT0)
    {
        /*使能工作时钟*/
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_SENT0);
    }
    else if(SENTx == SENT1)
    {
        /*使能工作时钟*/
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_SENT1);
    }
    /*发送配置*/
    if(initStruct->transferDirection == FL_SENT_MODE_TX)
    {
        FL_SENT_SetModeSelect(SENTx, FL_SENT_MODE_TX);

        /*配置发送时钟预分频prescaler
         * Fsent = APBCLK/(prescaler + 1)
         * tick时间 T = 8/Fsent
        */
        FL_SENT_WritePrescaler(SENTx, initStruct->prescaler);

        /*配置发送模式*/
        if(initStruct->transmitMode == FL_SENT_TXMODE_SOFTWARE)
        {
            FL_SENT_SetTXModeSelect(SENTx, FL_SENT_TXMODE_SOFTWARE);
        }
        else if(initStruct->transmitMode == FL_SENT_TXMODE_SERIAL)
        {
            FL_SENT_SetTXModeSelect(SENTx, FL_SENT_TXMODE_SERIAL);
        }

        /*配置帧中Data Nibbles个数*/
        FL_SENT_SetDataNibblesCount(SENTx, initStruct->dataNibbleNumber);

        /*配置硬件CRC使能*/
        if(initStruct->hardwareCRC == FL_ENABLE)
        {
            FL_SENT_EnableCRCHardware(SENTx);
        }
        else if(initStruct->hardwareCRC == FL_DISABLE)
        {
            FL_SENT_DisableCRCHardware(SENTx);
        }
        /*配置CRC模式*/
        FL_SENT_SetCRCModeSelect(SENTx, initStruct->CRCMode);

        /*配置暂停脉冲使能*/
        if(initStruct->pausePulse == FL_ENABLE)
        {
            FL_SENT_EnablePausePulse(SENTx);
            FL_SENT_WriteFrameTimeLength(SENTx, initStruct->frameTime);
        }
        else if(initStruct->pausePulse == FL_DISABLE)
        {
            FL_SENT_DisablePausePulse(SENTx);
        }

        /*配置空闲时TX输出电平*/
        if(initStruct->idleoutputpulse == FL_SENT_IDLEOUTPUT_LOW)
        {
            FL_SENT_SetIdleTXOutputPulse(SENTx, FL_SENT_IDLEOUTPUT_LOW);
        }
        else if(initStruct->idleoutputpulse == FL_SENT_IDLEOUTPUT_HIGH)
        {
            FL_SENT_SetIdleTXOutputPulse(SENTx, FL_SENT_IDLEOUTPUT_HIGH);
        }
    }

    /*接收配置*/
    if(initStruct->transferDirection == FL_SENT_MODE_RX)
    {
        FL_SENT_SetModeSelect(SENTx, FL_SENT_MODE_RX);

        /* 接收数字滤波 */
        FL_SENT_WriteDigitalFilterLength(SENTx, initStruct->digitalFilterLength);
        /* 配置帧长度 */
        FL_SENT_WriteFrameTimeLength(SENTx, initStruct->frameTime);

        /*配置发送时钟预分频prescaler
         * Fsent = APBCLK/(prescaler + 1)
         * tick时间 T = 8/Fsent
        */
        FL_SENT_WritePrescaler(SENTx, initStruct->prescaler);

        /*配置帧中Data Nibbles个数*/
        FL_SENT_SetDataNibblesCount(SENTx, initStruct->dataNibbleNumber);

        /*配置硬件CRC使能*/
        if(initStruct->hardwareCRC == FL_ENABLE)
        {
            FL_SENT_EnableCRCHardware(SENTx);
        }
        else if(initStruct->hardwareCRC == FL_DISABLE)
        {
            FL_SENT_DisableCRCHardware(SENTx);
        }
        /*配置CRC模式*/
        FL_SENT_SetCRCModeSelect(SENTx, initStruct->CRCMode);
        /*配置暂停脉冲使能*/
        if(initStruct->pausePulse == FL_ENABLE)
        {
            FL_SENT_EnablePausePulse(SENTx);
        }
        else if(initStruct->pausePulse == FL_DISABLE)
        {
            FL_SENT_DisablePausePulse(SENTx);
        }

        /*sync长度范围*/
        FL_SENT_WriteSyncMaxLength(SENTx, initStruct->syncPulseMax);
        FL_SENT_WriteSyncMinLength(SENTx, initStruct->syncPulseMin);
    }
    status = FL_PASS;
    return status;
}

/**
  * @brief  SENTx 为默认配置
  * @param  initStruct 指向需要将值设置为默认配置 的结构体@ref FL_SENT_InitTypeDef structure 结构体
  *         结构体
  * @retval None
  */
void FL_SENT_StructInit(FL_SENT_InitTypeDef *initStruct)
{
    if(initStruct != NULL)
    {
        initStruct->transferDirection     = FL_SENT_MODE_RX;
        initStruct->dataNibbleNumber      = FL_SENT_DATANIBBLES_COUNT_6N;
        initStruct->hardwareCRC           = FL_ENABLE;
        initStruct->CRCMode               = FL_SENT_CRCMODE_RECOMMENDED ;
        initStruct->pausePulse            = FL_ENABLE;
    }
}

/**
  * @}
  */

#endif /* FL_SENT_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/



