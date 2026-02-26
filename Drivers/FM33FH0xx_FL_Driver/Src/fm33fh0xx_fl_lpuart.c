/**
  ****************************************************************************************************
  * @file    fm33fh0xx_fl_lpuart.c
  * @author  FMSH Application Team
  * @brief   Src file of LPUART FL Module
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

/** @addtogroup FM33FH0xx_FL_Driver
 * @{
 */

/** @addtogroup LPUART
 * @{
 */

#ifdef FL_LPUART_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup LPUART_FL_Private_Macros
  * @{
  */
#define         IS_LPUART_INSTANCE(INSTANCE)               (((INSTANCE) == LPUART))

#define         IS_FL_LPUART_CLKSRC(__VALUE__)             (((__VALUE__) == FL_CMU_LPUART_CLK_SOURCE_XTLF)||\
                                                            ((__VALUE__) == FL_CMU_LPUART_CLK_SOURCE_RCHFPSC)||\
                                                            ((__VALUE__) == FL_CMU_LPUART_CLK_SOURCE_RCLP))

#define         IS_FL_LPUART_BAUDRATE(__VALUE__)            (((__VALUE__) == FL_LPUART_BAUDRATE_300)||\
                                                             ((__VALUE__) == FL_LPUART_BAUDRATE_600)||\
                                                             ((__VALUE__) == FL_LPUART_BAUDRATE_1200)||\
                                                             ((__VALUE__) == FL_LPUART_BAUDRATE_2400)||\
                                                             ((__VALUE__) == FL_LPUART_BAUDRATE_4800)||\
                                                             ((__VALUE__) == FL_LPUART_BAUDRATE_9600))

#define         IS_FL_LPUART_DATAWIDTH(__VALUE__)           (((__VALUE__) == FL_LPUART_DATA_WIDTH_6B)||\
                                                             ((__VALUE__) == FL_LPUART_DATA_WIDTH_7B)||\
                                                             ((__VALUE__) == FL_LPUART_DATA_WIDTH_8B)||\
                                                             ((__VALUE__) == FL_LPUART_DATA_WIDTH_9B))

#define         IS_FL_LPUART_STOPBITS(__VALUE__)            (((__VALUE__) == FL_LPUART_STOP_BIT_WIDTH_1B)||\
                                                             ((__VALUE__) == FL_LPUART_STOP_BIT_WIDTH_2B))

#define         IS_FL_LPUART_PARITY(__VALUE__)              (((__VALUE__) == FL_LPUART_PARITY_NONE)||\
                                                             ((__VALUE__) == FL_LPUART_PARITY_EVEN)||\
                                                             ((__VALUE__) == FL_LPUART_PARITY_ODD))

#define         IS_FL_LPUART_DIRECTION(__VALUE__)           (((__VALUE__) == FL_LPUART_DIRECTION_NONE)||\
                                                             ((__VALUE__) == FL_LPUART_DIRECTION_RX)||\
                                                             ((__VALUE__) == FL_LPUART_DIRECTION_TX)||\
                                                             ((__VALUE__) == FL_LPUART_DIRECTION_TX_RX))

/**
  * @}
  */

/** @addtogroup LPUART_FL_EF_Init
  * @{
  */

/**
  * @brief    复位LPUART 外设
  * @param    外设入口地址
  * @retval    返回错误状态，可能值：
  *           -FL_PASS 外设寄存器值恢复复位值
  *           -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_LPUART_DeInit(LPUART_Type *LPUARTx)
{
    /* 入口参数合法性断言 */
    assert_param(IS_LPUART_INSTANCE(LPUARTx));
    /* 外设复位使能 */
    FL_RMU_EnablePeripheralReset(RMU);
    if(LPUARTx == LPUART)
    {
        /*复位LPUART*/
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_LPUART);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_LPUART);
        /* 外设总线时钟关闭 */
        (void)FL_CMU_IsEnabledGroup3BusClock(FL_CMU_GROUP3_BUSCLK_LPUART);
        /* 外设工作时钟关闭 */
        FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_LPUART);
    }
    else
    {
        return FL_FAIL;
    }
    /* 锁定外设复位功能 */
    FL_RMU_DisablePeripheralReset(RMU);
    return FL_PASS;
}

/**
  * @brief    根据需要功能配置LPUART寄存器
  *
  * @note     波特率调制寄存器中的MCTL值，默认为工作时钟为32768Hz的频率下的调制值，用户如果外设工作时钟不是此前
  *          提则可能需要手动调整这个寄存器的值，以达到更好的通信效果。
  * @param    LPUARTx  外设入口地址
  * @param     initStruct 指向一个 @ref FL_LPUART_InitTypeDef类型的结构体，它包含指定LPUART外设的配置信息
  *
  * @retval    ErrorStatus枚举值
  *            -FL_FAIL 配置过程发生错误
  *            -FL_PASS LPUART配置成功
  */
FL_ErrorStatus FL_LPUART_Init(LPUART_Type *LPUARTx, FL_LPUART_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    uint16_t  MCTLVel;
    if(initStruct != NULL)
    {
        /* 参数合法性检查 */
        assert_param(IS_LPUART_INSTANCE(LPUARTx));
        assert_param(IS_FL_LPUART_CLKSRC(initStruct->clockSrc));
        assert_param(IS_FL_LPUART_BAUDRATE(initStruct->baudRate));
        assert_param(IS_FL_LPUART_DATAWIDTH(initStruct->dataWidth));
        assert_param(IS_FL_LPUART_STOPBITS(initStruct->stopBits));
        assert_param(IS_FL_LPUART_PARITY(initStruct->parity));
        assert_param(IS_FL_LPUART_DIRECTION(initStruct->transferDirection));
        if(LPUARTx == LPUART)
        {
            /*总线时钟使能*/
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_LPUART);
            /*操作时钟使能*/
            FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_LPUART);
            /*时钟源选择*/
            FL_CMU_SetLPUARTClockSource(initStruct->clockSrc << CMU_OPCCR1_LPUARTCKS_Pos);
        }
        FL_LPUART_EnableBaudRateModulation(LPUARTx);
        /*发送接收配置*/
        switch(initStruct->transferDirection)
        {
            case FL_LPUART_DIRECTION_TX:
                FL_LPUART_EnableTX(LPUARTx);
                break;
            case FL_LPUART_DIRECTION_RX:
                FL_LPUART_EnableRX(LPUARTx);
                break;
            case FL_LPUART_DIRECTION_TX_RX:
                FL_LPUART_EnableRX(LPUARTx);
                FL_LPUART_EnableTX(LPUARTx);
                break;
            case FL_LPUART_DIRECTION_NONE:
                FL_LPUART_DisableRX(LPUARTx);
                FL_LPUART_DisableTX(LPUARTx);
                break;
            default:
                FL_LPUART_DisableRX(LPUARTx);
                FL_LPUART_DisableTX(LPUARTx);
                break;
        }
        /*配置波特率*/
        FL_LPUART_SetBaudRate(LPUARTx, initStruct->baudRate);
        /*配置停止位*/
        FL_LPUART_SetStopBitsWidth(LPUARTx, initStruct->stopBits);
        /*配置数据位宽*/
        FL_LPUART_SetDataWidth(LPUARTx, initStruct->dataWidth);
        /*配置波特率*/
        FL_LPUART_SetParity(LPUARTx, initStruct->parity);
        /*根据波特率配置MCTL值*/
        switch(initStruct->baudRate)
        {
            case FL_LPUART_BAUDRATE_9600:
                MCTLVel = 0x0552;
                break;
            case FL_LPUART_BAUDRATE_4800:
                MCTLVel = 0x1EFB;
                break;
            case FL_LPUART_BAUDRATE_2400:
                MCTLVel = 0x16DB;
                break;
            case FL_LPUART_BAUDRATE_1200:
                MCTLVel = 0x0492;
                break;
            case FL_LPUART_BAUDRATE_600:
                MCTLVel = 0x16D6;
                break;
            case FL_LPUART_BAUDRATE_300:
                MCTLVel = 0x0842;
                break;
            default:
                MCTLVel = 0x0552;
                break;
        }
        FL_LPUART_WriteBitModulation(LPUARTx, MCTLVel);
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief    initStruct 为默认配置
  * @param     initStruct 指向需要将值设置为默认配置的结构体 @ref FL_LPUART_InitTypeDef structure
  *         结构体
  * @retval    None
  */

void FL_LPUART_StructInit(FL_LPUART_InitTypeDef *initStruct)
{
    if(initStruct != NULL)
    {
        initStruct->baudRate            = FL_LPUART_BAUDRATE_9600;
        initStruct->dataWidth           = FL_LPUART_DATA_WIDTH_8B;
        initStruct->stopBits            = FL_LPUART_STOP_BIT_WIDTH_1B;
        initStruct->parity              = FL_LPUART_PARITY_NONE ;
        initStruct->transferDirection   = FL_LPUART_DIRECTION_TX_RX;
        initStruct->clockSrc            = FL_CMU_LPUART_CLK_SOURCE_XTLF;
    }
}

/**
 * @}
 */

#endif /* FL_LPUART_DRIVER_ENABLED */

/**
 * @}
 */

/**
 * @}
 */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/

