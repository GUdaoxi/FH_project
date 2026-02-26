/**
  ****************************************************************************************************
  * @file    fm33fh0xx_fl_uart.c
  * @author  FMSH Application Team
  * @brief   Src file of UART FL Module
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

/** @addtogroup UART
  * @{
  */

#ifdef FL_UART_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup UART_FL_Private_Macros
  * @{
  */

#define     IS_UART_INSTANCE(INSTANCE)                     (((INSTANCE) == UART0)||\
                                                            ((INSTANCE) == UART1)||\
                                                            ((INSTANCE) == UART2)||\
                                                            ((INSTANCE) == UART3)||\
                                                            ((INSTANCE) == UART4)||\
                                                            ((INSTANCE) == UART5)||\
                                                            ((INSTANCE) == UART6)||\
                                                            ((INSTANCE) == UART7))
                                                           
#define     IS_FL_UART_CLKSRC(__VALUE__)                   (((__VALUE__) == FL_CMU_UART0_CLK_SOURCE_APBCLK)||\
                                                            ((__VALUE__) == FL_CMU_UART0_CLK_SOURCE_RCHF)||\
                                                            ((__VALUE__) == FL_CMU_UART0_CLK_SOURCE_SYSCLK)||\
                                                            ((__VALUE__) == FL_CMU_UART0_CLK_SOURCE_XTHF)||\
                                                            ((__VALUE__) == FL_CMU_UART1_CLK_SOURCE_APBCLK)||\
                                                            ((__VALUE__) == FL_CMU_UART1_CLK_SOURCE_RCHF)||\
                                                            ((__VALUE__) == FL_CMU_UART1_CLK_SOURCE_SYSCLK)||\
                                                            ((__VALUE__) == FL_CMU_UART1_CLK_SOURCE_XTHF)||\
                                                            ((__VALUE__) == FL_CMU_UART2_CLK_SOURCE_APBCLK)||\
                                                            ((__VALUE__) == FL_CMU_UART2_CLK_SOURCE_RCHF)||\
                                                            ((__VALUE__) == FL_CMU_UART2_CLK_SOURCE_SYSCLK)||\
                                                            ((__VALUE__) == FL_CMU_UART2_CLK_SOURCE_XTHF)||\
                                                            ((__VALUE__) == FL_CMU_UART3_CLK_SOURCE_APBCLK)||\
                                                            ((__VALUE__) == FL_CMU_UART3_CLK_SOURCE_RCHF)||\
                                                            ((__VALUE__) == FL_CMU_UART3_CLK_SOURCE_SYSCLK)||\
                                                            ((__VALUE__) == FL_CMU_UART3_CLK_SOURCE_XTHF)||\
                                                            ((__VALUE__) == FL_CMU_UART4_CLK_SOURCE_APBCLK)||\
                                                            ((__VALUE__) == FL_CMU_UART4_CLK_SOURCE_RCHF)||\
                                                            ((__VALUE__) == FL_CMU_UART4_CLK_SOURCE_SYSCLK)||\
                                                            ((__VALUE__) == FL_CMU_UART4_CLK_SOURCE_XTHF)||\
                                                            ((__VALUE__) == FL_CMU_UART5_CLK_SOURCE_APBCLK)||\
                                                            ((__VALUE__) == FL_CMU_UART5_CLK_SOURCE_RCHF)||\
                                                            ((__VALUE__) == FL_CMU_UART5_CLK_SOURCE_SYSCLK)||\
                                                            ((__VALUE__) == FL_CMU_UART5_CLK_SOURCE_XTHF))
                                                           
                                                           
#define     IS_FL_UART_DATAWIDTH(__VALUE__)                (((__VALUE__) == FL_UART_DATA_WIDTH_6B)||\
                                                            ((__VALUE__) == FL_UART_DATA_WIDTH_7B)||\
                                                            ((__VALUE__) == FL_UART_DATA_WIDTH_8B)||\
                                                            ((__VALUE__) == FL_UART_DATA_WIDTH_9B))
                                                           
#define     IS_FL_UART_STOPBITS(__VALUE__)                 (((__VALUE__) == FL_UART_STOP_BIT_WIDTH_1B)||\
                                                            ((__VALUE__) == FL_UART_STOP_BIT_WIDTH_2B))
                                                           
#define     IS_FL_UART_PARITY(__VALUE__)                   (((__VALUE__) == FL_UART_PARITY_NONE)||\
                                                            ((__VALUE__) == FL_UART_PARITY_EVEN)||\
                                                            ((__VALUE__) == FL_UART_PARITY_ODD))
                                                           
#define     IS_FL_UART_DIRECTION(__VALUE__)                (((__VALUE__) == FL_UART_DIRECTION_NONE)||\
                                                            ((__VALUE__) == FL_UART_DIRECTION_RX)||\
                                                            ((__VALUE__) == FL_UART_DIRECTION_TX)||\
                                                            ((__VALUE__) == FL_UART_DIRECTION_TX_RX))
                                                           
#define     IS_FL_UART_INFRA_MODULATION(__VALUE__)         (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))


#define     IS_FL_UART_INFRARED_POLARITY(__VALUE__)        (((__VALUE__) == FL_UART_INFRARED_POLARITY_NORMAL)||\
                                                            ((__VALUE__) == FL_UART_INFRARED_POLARITY_INVERT))

#define     IS_FL_UART_INFRARED_MODULATION_DUTY(__VALUE__) (((__VALUE__) <= 100))


#define     IS_UART_LIN_INSTANCE(INSTANCE)                 (((INSTANCE) == UART0)||\
                                                            ((INSTANCE) == UART1)||\
                                                            ((INSTANCE) == UART2)||\
                                                            ((INSTANCE) == UART3)||\
                                                            ((INSTANCE) == UART4)||\
                                                            ((INSTANCE) == UART5))

#define     IS_FL_UART_LIN_MODE(__VALUE__)                 (((__VALUE__) == FL_UART_LIN_MODESEL_MASTER)||\
                                                            ((__VALUE__) == FL_UART_LIN_MODESEL_SLAVE))
                                                            
#define     IS_FL_UART_LIN_WAKEUP_LENTH(__VALUE__)         ((__VALUE__) < 16)
                                                            
#define     IS_FL_UART_LIN_FRAME_TIMEOUT_LENTH(__VALUE__)  ((__VALUE__) < 4096) 

#define     IS_FL_UART_LIN_BUS_SEND_CONFL_DET(__VALUE__)   (((__VALUE__) == FL_UART_BER_MODE_NONE)||\
                                                            ((__VALUE__) == FL_UART_BER_MODE_EN_BIT9)||\
                                                            ((__VALUE__) == FL_UART_BER_MODE_EN_BIT13))

#define     IS_FL_UART_INTER_BYTE_SPACE(__VALUE__)         ((__VALUE__) < 4)

#define     IS_FL_UART_RESPONSE_SPACE(__VALUE__)           ((__VALUE__) < 8)

#define     IS_FL_UART_BREAK_DELIMIT_LENTH(__VALUE__)      ((__VALUE__) < 4)

#define     IS_FL_UART_BREAK_LENTH(__VALUE__)              ((__VALUE__) < 16)

#define     IS_FL_UART_FUNSTATE_TYPE(__VALUE__)           (((__VALUE__) == FL_DISABLE)||\
                                                           ((__VALUE__) == FL_ENABLE))

#define     IS_FL_UART_DMA_TRANSMIT_INTERRUPT(__VALUE__)  (((__VALUE__) == FL_UART_TXIF_MODE_ALWAYS)||\
                                                           ((__VALUE__) == FL_UART_TXIF_MODE_AFTER_DMA))
                                                           
#define     IS_FL_UART_DUPLEX(__VALUE__)                  (((__VALUE__) == FL_UART_UART_MODESEL_FULL_DUPLEX)||\
                                                           ((__VALUE__) == FL_UART_UART_MODESEL_HALF_DUPLEX))

#define     IS_FL_UART_OVER_SAMPLING(__VALUE__)           (((__VALUE__) == FL_UART_OVERSAMPLING_16)||\
                                                           ((__VALUE__) == FL_UART_OVERSAMPLING_8))
                                                           
#define     IS_FL_UART_BIT_ORDER(__VALUE__)               (((__VALUE__) == FL_UART_BIT_ORDER_LSB_FIRST)||\
                                                           ((__VALUE__) == FL_UART_BIT_ORDER_MSB_FIRST))

#define     IS_FL_UART_RECEIVE_TIME_OUT_LENTH(__VALUE__)  ((__VALUE__) < 256)

#define     IS_FL_UART_TRANSMIT_DELAY_LENTH(__VALUE__)    ((__VALUE__) < 256)



/**
  * @}
  */

/** @addtogroup UART_FL_EF_Init
  * @{
  */

/**
  * @brief  复位UART 外设寄存器值为复位值
  * @param  外设入口地址
  * @retval 返回错误状态，可能值:
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 复位未成功
  */
FL_ErrorStatus FL_UART_DeInit(UART_Type *UARTx)
{
    FL_ErrorStatus status = FL_PASS;
    /* 参数入口合法性 */
    assert_param(IS_UART_INSTANCE(UARTx));
    /* 模式选择--UART */
    FL_UART_SetMode(UARTx, FL_UART_MODESEL_UART);
    /* 外设复位使能 */
    FL_RMU_EnablePeripheralReset(RMU);
    if(UARTx == UART0)
    {
        /* 复位UART */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART0);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART0);
        /* 外设总线时钟关闭 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART0);
        /* 外设工作时钟关闭 */
        FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_UART0);
    }
    else if(UARTx == UART1)
    {
        /* 复位UART */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART1);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART1);
        /* 外设总线时钟关闭 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART1);
        /* 外设工作时钟关闭 */
        FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_UART1);
    }
    else if(UARTx == UART2)
    {
        /* 复位UART */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART2);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART2);
        /* 关闭总线时钟 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART2);
        /* 外设工作时钟关闭 */
        FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_UART2);
    }
    else if(UARTx == UART3)
    {
        /* 复位UART */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART3);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART3);
        /* 关闭总线时钟 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART3);
        /* 外设工作时钟关闭 */
        FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_UART3);
    }
    else if(UARTx == UART4)
    {
        /* 复位UART */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART4);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART4);
        /* 关闭总线时钟 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART4);
        /* 外设工作时钟关闭 */
        FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_UART4);
    }
    else if(UARTx == UART5)
    {
        /* 复位UART */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART5);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART5);
        /* 关闭总线时钟 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART5);
        /* 外设工作时钟关闭 */
        FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_UART5);
    }
    else if(UARTx == UART6)
    {
        /* 复位UART */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART6);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART6);
        /* 总线、工作时钟关闭 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART6);
    }
    else if(UARTx == UART7)
    {
        /*复位UART*/
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART7);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART7);
        /* 总线（工作）时钟关闭 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART7);
    }
    else
    {
        status = FL_FAIL;
    }
    /* 锁定外设复位功能 */
    FL_RMU_DisablePeripheralReset(RMU);
    return (status);
}

/**
  * @brief  根据需要配置UART
  *
  * @param  UARTx  外设入口地址
  * @param  UART_InitStruct指向一个FL_UART_InitTypeDef类型的结构体,它包含外设UART的配置信息
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS UART配置成功
  */
FL_ErrorStatus FL_UART_Init(UART_Type *UARTx, FL_UART_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    uint32_t Fclk = 0, BaudRate = 0;
    if(initStruct != NULL)
    {
        /* 参数合法性检查 */
        assert_param(IS_UART_INSTANCE(UARTx));
        assert_param(IS_FL_UART_CLKSRC(initStruct->clockSrc));
        assert_param(IS_FL_UART_DATAWIDTH(initStruct->dataWidth));
        assert_param(IS_FL_UART_PARITY(initStruct->parity));
        assert_param(IS_FL_UART_STOPBITS(initStruct->stopBits));
        assert_param(IS_FL_UART_DIRECTION(initStruct->transferDirection));
        
        /* UART0~5 波特率设置 */
        if(UARTx == UART0)
        {
            /* 时钟源选择 */
            FL_CMU_SetUART0ClockSource(initStruct->clockSrc);
            /* 根据不同的时钟源计算baudrate 寄存器值,并配置 */
            switch(initStruct->clockSrc)
            {
                case FL_CMU_UART0_CLK_SOURCE_APBCLK:
                    Fclk = FL_CMU_GetAPB1ClockFreq();
                    break;
                case FL_CMU_UART0_CLK_SOURCE_RCHF:
                    Fclk = FL_CMU_GetRCHFClockFreq();
                    break;
                case FL_CMU_UART0_CLK_SOURCE_SYSCLK:
                    Fclk = FL_CMU_GetSystemClockFreq();
                    break;
                case FL_CMU_UART0_CLK_SOURCE_XTHF:
                    Fclk = XTHFClock;
                    break;
                default:
                    Fclk = FL_CMU_GetAPB1ClockFreq();
                    break;
            }
            BaudRate = Fclk / initStruct->baudRate - 1;
        }
        if(UARTx == UART1)
        {
            /* 时钟源选择 */
            FL_CMU_SetUART1ClockSource(initStruct->clockSrc);
            /* 根据不同的时钟源计算baudrate 寄存器值,并配置 */
            switch(initStruct->clockSrc)
            {
                case FL_CMU_UART1_CLK_SOURCE_APBCLK:
                    Fclk = FL_CMU_GetAPB1ClockFreq();
                    break;
                case FL_CMU_UART1_CLK_SOURCE_RCHF:
                    Fclk = FL_CMU_GetRCHFClockFreq();
                    break;
                case FL_CMU_UART1_CLK_SOURCE_SYSCLK :
                    Fclk = FL_CMU_GetSystemClockFreq();
                    break;
                case FL_CMU_UART1_CLK_SOURCE_XTHF:
                    Fclk = XTHFClock;
                    break;
                default:
                    Fclk = FL_CMU_GetAPB1ClockFreq();
                    break;
            }
            BaudRate = Fclk / initStruct->baudRate - 1;
        }
        if(UARTx == UART2)
        {
            /* 时钟源选择 */
            FL_CMU_SetUART2ClockSource(initStruct->clockSrc);
            /* 根据不同的时钟源计算baudrate 寄存器值,并配置 */
            switch(initStruct->clockSrc)
            {
                case FL_CMU_UART2_CLK_SOURCE_APBCLK:
                    Fclk = FL_CMU_GetAPB1ClockFreq();
                    break;
                case FL_CMU_UART2_CLK_SOURCE_RCHF:
                    Fclk = FL_CMU_GetRCHFClockFreq();
                    break;
                case FL_CMU_UART2_CLK_SOURCE_SYSCLK :
                    Fclk = FL_CMU_GetSystemClockFreq();
                    break;
                case FL_CMU_UART2_CLK_SOURCE_XTHF:
                    Fclk = XTHFClock;
                    break;
                default:
                    Fclk = FL_CMU_GetAPB1ClockFreq();
                    break;
            }
            BaudRate = Fclk / initStruct->baudRate - 1;
        }
        if(UARTx == UART3)
        {
            /* 时钟源选择 */
            FL_CMU_SetUART3ClockSource(initStruct->clockSrc);
            /* 根据不同的时钟源计算baudrate 寄存器值,并配置 */
            switch(initStruct->clockSrc)
            {
                case FL_CMU_UART3_CLK_SOURCE_APBCLK:
                    Fclk = FL_CMU_GetAPB1ClockFreq();
                    break;
                case FL_CMU_UART3_CLK_SOURCE_RCHF:
                    Fclk = FL_CMU_GetRCHFClockFreq();
                    break;
                case FL_CMU_UART3_CLK_SOURCE_SYSCLK :
                    Fclk = FL_CMU_GetSystemClockFreq();
                    break;
                case FL_CMU_UART3_CLK_SOURCE_XTHF:
                    Fclk = XTHFClock;
                    break;
                default:
                    Fclk = FL_CMU_GetAPB1ClockFreq();
                    break;
            }
            BaudRate = Fclk / initStruct->baudRate - 1;
        }        
        if(UARTx == UART4)
        {
            /* 时钟源选择 */
            FL_CMU_SetUART4ClockSource(initStruct->clockSrc);
            /* 根据不同的时钟源计算baudrate 寄存器值,并配置 */
            switch(initStruct->clockSrc)
            {
                case FL_CMU_UART4_CLK_SOURCE_APBCLK:
                    Fclk = FL_CMU_GetAPB1ClockFreq();
                    break;
                case FL_CMU_UART4_CLK_SOURCE_RCHF:
                    Fclk = FL_CMU_GetRCHFClockFreq();
                    break;
                case FL_CMU_UART4_CLK_SOURCE_SYSCLK :
                    Fclk = FL_CMU_GetSystemClockFreq();
                    break;
                case FL_CMU_UART4_CLK_SOURCE_XTHF:
                    Fclk = XTHFClock;
                    break;
                default:
                    Fclk = FL_CMU_GetAPB1ClockFreq();
                    break;
            }
            BaudRate = Fclk / initStruct->baudRate - 1;
        }        
        if(UARTx == UART5)
        {
            /* 时钟源选择 */
            FL_CMU_SetUART5ClockSource(initStruct->clockSrc);
            /* 根据不同的时钟源计算baudrate 寄存器值,并配置 */
            switch(initStruct->clockSrc)
            {
                case FL_CMU_UART5_CLK_SOURCE_APBCLK:
                    Fclk = FL_CMU_GetAPB1ClockFreq();
                    break;
                case FL_CMU_UART5_CLK_SOURCE_RCHF:
                    Fclk = FL_CMU_GetRCHFClockFreq();
                    break;
                case FL_CMU_UART5_CLK_SOURCE_SYSCLK :
                    Fclk = FL_CMU_GetSystemClockFreq();
                    break;
                case FL_CMU_UART5_CLK_SOURCE_XTHF:
                    Fclk = XTHFClock;
                    break;
                default:
                    Fclk = FL_CMU_GetAPB1ClockFreq();
                    break;
            }
            BaudRate = Fclk / initStruct->baudRate - 1;
        }
        
        /* UART0~7 开启总线时钟及操作时钟 */
        if(UARTx == UART0)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART0);
            FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_UART0);
        }
        else if(UARTx == UART1)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART1);
            FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_UART1);
        }
        else if(UARTx == UART2)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART2);
            FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_UART2);
        }
        else if(UARTx == UART3)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART3);
            FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_UART3);
        }
        else if(UARTx == UART4)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART4);
            FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_UART4);
        }
        else if(UARTx == UART5)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART5);
            FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_UART5);
        }
        else if(UARTx == UART6) /* UART6 波特率配置 */
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART6);
            Fclk = FL_CMU_GetAPB1ClockFreq();
            BaudRate = Fclk / initStruct->baudRate - 1;
        }
        else if(UARTx == UART7) /* UART7 波特率配置 */
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART7);
            Fclk = FL_CMU_GetAPB1ClockFreq();
            BaudRate = Fclk / initStruct->baudRate - 1;
        }
        
        /* 模式选择--UART */
        FL_UART_SetMode(UARTx, FL_UART_MODESEL_UART);
        /* 发送接收控制 */
        if((initStruct->transferDirection & FL_UART_DIRECTION_TX) == FL_UART_DIRECTION_TX)
        {
            FL_UART_EnableTX(UARTx);
        }
        if((initStruct->transferDirection & FL_UART_DIRECTION_RX) == FL_UART_DIRECTION_RX)
        {
            FL_UART_EnableRX(UARTx);
        }
        /* 配置波特率 */
        FL_UART_WriteBaudRate(UARTx, BaudRate);
        /* 配置停止位长度 */
        FL_UART_SetStopBitsWidth(UARTx, initStruct->stopBits);
        /* 数据长度 */
        FL_UART_SetDataWidth(UARTx, initStruct->dataWidth);
        /* 配置奇偶校验 */
        FL_UART_SetParity(UARTx, initStruct->parity);
        status = FL_PASS;
    }
    return status;
}
/**
  * @brief  根据需要配置红外调制寄存器
  *
  * @param  UARTx  外设入口地址
  *
  * @param  initStruct指向FL_UART_InfraRed_InitTypeDef类型的结构体,包含UART外设信息
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程出现错误
  *         -FL_PASS UART配置成功
  */
FL_ErrorStatus FL_UART_InfraRed_Init(UART_Type *UARTx, FL_UART_InfraRed_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    uint32_t tempTZBRG = 0, tempTH = 0;
    /* 参数合法性检查 */
    if(initStruct != NULL)
    {
        assert_param(IS_UART_INSTANCE(UARTx));
        assert_param(IS_FL_UART_INFRARED_POLARITY(initStruct->polarity));
        assert_param(IS_FL_UART_INFRARED_MODULATION_DUTY(initStruct->modulationDuty));
        /* 红外发送总线时钟使能 */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UARTIR);
        /* 红外发送使能 */
        FL_UART_EnableIRModulation(UARTx);
        /* 红外调制极性 */
        FL_UART_SetIRPolarity(UARTIR, initStruct->polarity);
        /* 红外调制频率 */
        tempTZBRG = (uint32_t)((FL_CMU_GetAPB1ClockFreq()) / initStruct->modulationFrequency - 1);
        /* 调制占空比 */
        if((tempTZBRG >> 4) != 0)
        {
            tempTH = ((initStruct->modulationDuty / 100) * ((tempTZBRG + 1) / (tempTZBRG >> 4)));
        }
        else
        {
            tempTH = ((initStruct->modulationDuty / 100) * (tempTZBRG + 1));
        }
        /* 占空比和调制频率配置 */
        FL_UART_WriteIRModulationDuty(UARTIR, tempTH);
        FL_UART_WriteIRModulationFrequency(UARTIR, tempTZBRG);
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  UART扩展参数初始化
  *
  * @param  UARTx  外设入口地址
  *
  * @param  initStruct指向FL_UART_ExtendedPrm_InitTypeDef类型的结构体,包含UART外设扩展信息
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程出现错误
  *         -FL_PASS UART配置成功
  */
FL_ErrorStatus FL_UART_ExtendedPrm_Init(UART_Type *UARTx, FL_UART_ExtendedPrm_InitTypeDef *initStruct)
{
    /* 参数合法性检查 */
    assert_param(IS_FL_UART_DMA_TRANSMIT_INTERRUPT(initStruct->DmaTransmitInterrupt));
    assert_param(IS_FL_UART_FUNSTATE_TYPE(initStruct->ReceiveTimeOutEnable));
    assert_param(IS_FL_UART_RECEIVE_TIME_OUT_LENTH(initStruct->ReceiveTimeOutLen));
    assert_param(IS_FL_UART_DUPLEX(initStruct->UartDuplex));
    assert_param(IS_FL_UART_FUNSTATE_TYPE(initStruct->ByteReSynEnable));
    assert_param(IS_FL_UART_OVER_SAMPLING(initStruct->OverSamplingMode));
    assert_param(IS_FL_UART_FUNSTATE_TYPE(initStruct->RxFallWakeUpEnable));
    assert_param(IS_FL_UART_BIT_ORDER(initStruct->BitOrder));
    assert_param(IS_FL_UART_TRANSMIT_DELAY_LENTH(initStruct->TransmitDelayLength));
     
    if(initStruct != NULL)
    {
        if(UARTx == UART0)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART0);
        }
        else if(UARTx == UART1)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART1);
        }
        else if(UARTx == UART2)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART2);
        }
        else if(UARTx == UART3)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART3);
        }
        else if(UARTx == UART4)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART4);
        }
        else if(UARTx == UART5)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART5);
        }
        else if(UARTx == UART6)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART6);
        }
        else if(UARTx == UART7)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART7);
        }
        else
        {
            return FL_FAIL;
        }
        /* 初始化参数 */
        FL_UART_SetTXIFMode(UARTx, initStruct->DmaTransmitInterrupt);
        if (FL_ENABLE == initStruct->ReceiveTimeOutEnable)
        {
            FL_UART_EnableRXTimeout(UARTx); 
        }
        else
        {
            FL_UART_DisableRXTimeout(UARTx);
        }
        FL_UART_WriteRXTimeout(UARTx, initStruct->ReceiveTimeOutLen);
        
        /* 以下参数LIN模式下不支持设置 */
        if (FL_UART_MODESEL_UART == FL_UART_GetMode(UARTx) || (UARTx == UART6) || (UARTx == UART7))
        {
            FL_UART_SetUARTMode(UARTx, initStruct->UartDuplex);
            if (FL_ENABLE == initStruct->ByteReSynEnable)
            {
                FL_UART_EnableResync(UARTx);
            }
            else
            {
                FL_UART_DisableResync(UARTx);
            }
            FL_UART_SetOverSampling(UARTx, initStruct->OverSamplingMode);
            if (FL_ENABLE == initStruct->RxFallWakeUpEnable)
            {
                FL_UART_EnableFallingEdgeWakeup(UARTx);
            }
            else
            {
                FL_UART_DisableFallingEdgeWakeup(UARTx);
            }
            FL_UART_SetBitOrder(UARTx, initStruct->BitOrder);
            FL_UART_WriteTXDelay(UARTx, initStruct->TransmitDelayLength);
        }
        return FL_PASS;
    }
    return FL_FAIL;
}

/**
  * @brief  根据需要配置LIN相关参数
  *
  * @param  UARTx  外设入口地址
  * @param  initStruct指向一个FL_UART_LIN_InitTypeDef类型的结构体,它包含外设UART关于LIN的配置信息
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS UART配置成功
  */
FL_ErrorStatus FL_UART_LIN_Init(UART_Type *UARTx, FL_UART_LIN_InitTypeDef *initStruct)
{
    /* 参数入口合法性 */
    assert_param(IS_UART_LIN_INSTANCE(UARTx));  
    assert_param(IS_FL_UART_LIN_MODE(initStruct->linMode));
    assert_param(IS_FL_UART_LIN_WAKEUP_LENTH(initStruct->wakeupLenth));
    assert_param(IS_FL_UART_FUNSTATE_TYPE(initStruct->slaveSyncenable));
    assert_param(IS_FL_UART_FUNSTATE_TYPE(initStruct->frameTimeoutDetec));
    assert_param(IS_FL_UART_LIN_FRAME_TIMEOUT_LENTH(initStruct->frameTimeoutLenth));
    assert_param(IS_FL_UART_LIN_BUS_SEND_CONFL_DET(initStruct->busSendConflictDetec));
    assert_param(IS_FL_UART_FUNSTATE_TYPE(initStruct->busNoiseDetecEnable));
    assert_param(IS_FL_UART_FUNSTATE_TYPE(initStruct->wakeupDetecEnable));
    assert_param(IS_FL_UART_INTER_BYTE_SPACE(initStruct->interByteSpace));
    assert_param(IS_FL_UART_RESPONSE_SPACE(initStruct->responseSpace));
    assert_param(IS_FL_UART_BREAK_DELIMIT_LENTH(initStruct->breakDelimitLenth));
    assert_param(IS_FL_UART_BREAK_LENTH(initStruct->breakLenth));

    if(NULL != initStruct)
    {
        if(UARTx == UART0)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART0);
        }
        else if(UARTx == UART1)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART1);
        }
        else if(UARTx == UART2)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART2);
        }
        else if(UARTx == UART3)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART3);
        }
        else if(UARTx == UART4)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART4);
        }
        else if(UARTx == UART5)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART5);
        }
        else 
        {
            return FL_FAIL;
        }
        /* 设置LIN模式 */
        FL_UART_SetLINMode(UARTx, initStruct->linMode);
        FL_UART_SetMode(UARTx, FL_UART_MODESEL_NON_UART);
        /* 设置发送唤醒信号长度/接收唤醒信号识别阈值 */
        FL_UART_SetLINWkupLength(UARTx, initStruct->wakeupLenth);
        /* LIN从机Sync段接收使能/禁止 */
        if(initStruct->slaveSyncenable == FL_ENABLE)
        {
            FL_UART_EnableLINSlaveSyncReception(UARTx);
        }
        else
        {
            FL_UART_DisableLINSlaveSyncReception(UARTx);
        }
        /* LIN Frame timeout使能/禁止 */
        if(initStruct->frameTimeoutDetec == FL_ENABLE)
        {
            FL_UART_EnableLINFrameTimeoutDetect(UARTx);
        }
        else
        {
            FL_UART_DisableLINFrameTimeoutDetect(UARTx);
        }
        /* 设置帧超时长度 */
        FL_UART_WriteLINFrameTimeout(UARTx, initStruct->frameTimeoutLenth);
        
        /* LIN总线发送冲突检测配置 */
        FL_UART_SetLINBusErrorMode(UARTx, initStruct->busSendConflictDetec);
        /* LIN总线噪声监测使能/禁止 */
        if(initStruct->busNoiseDetecEnable == FL_ENABLE)
        {
            FL_UART_EnableLINNoiseDetect(UARTx);
        }
        else
        {
            FL_UART_DisableLINNoiseDetect(UARTx);
        }
        /* LIN唤醒信号检测使能/禁止 */
        if(initStruct->wakeupDetecEnable == FL_ENABLE)
        {
            /* 使能LIN工作时钟LSCSK=32768，用于唤醒信号检测 */
            FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_LINCKE);      
            FL_UART_EnableLINWkupDetect(UARTx);
        }
        else
        {
            FL_UART_DisableLINWkupDetect(UARTx);
            FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_LINCKE);
        }
        /* 填充数据发送时数据字节间隔，仅发送时有效  */
        FL_UART_WriteLINInterbyteSpace(UARTx, initStruct->interByteSpace);
        /* 填充header到发送数据respronse之间的间隔，仅发送时有效 */
        FL_UART_WriteLINResponseSpace(UARTx, initStruct->responseSpace);
        /* 填充break界定符长度 */
        FL_UART_WriteLINBreakSpace(UARTx, initStruct->breakDelimitLenth);
        /* 填充 break长度 */
        FL_UART_WriteLINBreakLength(UARTx, initStruct->breakLenth);
        return FL_PASS;
    }
    return FL_FAIL;
}

/**
  * @brief  UART_InfraRed_InitStruct 为默认配置
  * @param  UART_InitStruct 指向需要将值设置为默认配置 的结构体@ref FL_UART_InfraRed_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_UART_InfraRed_StructInit(FL_UART_InfraRed_InitTypeDef *initStruct)
{
    if(initStruct != NULL)
    {
        initStruct->polarity            = FL_UART_INFRARED_POLARITY_NORMAL;
        initStruct->modulationDuty      = 50;
        initStruct->modulationFrequency = 38000;
    }
}

/**
  * @brief  UART_InitStruct 为默认配置
  * @param  UART_InitStruct 指向需要将值设置为默认配置 的结构体@ref FL_UART_InitTypeDef structure 结构体
  *         
  * @retval None
  */
void FL_UART_StructInit(FL_UART_InitTypeDef *initStruct)
{
    if(initStruct != NULL)
    {
        initStruct->baudRate          = 115200;
        initStruct->dataWidth         = FL_UART_DATA_WIDTH_8B;
        initStruct->stopBits          = FL_UART_STOP_BIT_WIDTH_1B;
        initStruct->parity            = FL_UART_PARITY_EVEN ;
        initStruct->transferDirection = FL_UART_DIRECTION_TX_RX;
        initStruct->clockSrc          = 0;
    }
}

/**
  * @brief  UART_ExtendedPrm_InitStruct 为默认配置
  * @param  UART_InitStruct 指向需要将值设置为默认配置 的结构体@ref FL_UART_ExtendedPrm_InitTypeDef structure 结构体
  *         
  * @retval None
  */
void FL_UART_ExtendedPrm_StructInit(FL_UART_ExtendedPrm_InitTypeDef *initStruct)
{
    if(initStruct != NULL)
    {
        initStruct->DmaTransmitInterrupt = FL_UART_TXIF_MODE_ALWAYS;
        initStruct->ReceiveTimeOutEnable = FL_DISABLE;
        initStruct->ReceiveTimeOutLen    = 255;
        /* 以下参数LIN模式下不支持 */  
        initStruct->UartDuplex           = FL_UART_UART_MODESEL_FULL_DUPLEX;
        initStruct->ByteReSynEnable      = FL_DISABLE;
        initStruct->OverSamplingMode     = FL_UART_OVERSAMPLING_16;
        initStruct->RxFallWakeUpEnable   = FL_DISABLE; 
        initStruct->BitOrder             = FL_UART_BIT_ORDER_LSB_FIRST;
        initStruct->TransmitDelayLength  = 0x0;
    }
}

/**
  * @brief  UART_LIN_InitStruct 为默认配置
  * @param  UART_LIN_InitStruct 指向需要将值设置为默认配置 的结构体@ref FL_UART_LIN_InitTypeDef 结构体
  *         
  * @retval None
  */
void FL_UART_LIN_StructInit(FL_UART_LIN_InitTypeDef *initStruct)
{
    if(initStruct != NULL)
    {
        initStruct->linMode              = FL_UART_LIN_MODESEL_SLAVE;
        initStruct->wakeupLenth          = 9 - 1;
        initStruct->slaveSyncenable      = FL_ENABLE;
        initStruct->frameTimeoutDetec    = FL_DISABLE ;
        initStruct->frameTimeoutLenth    = 256 - 1;
        initStruct->busSendConflictDetec = FL_UART_BER_MODE_NONE;
        initStruct->busNoiseDetecEnable  = FL_DISABLE;
        initStruct->wakeupDetecEnable    = FL_DISABLE;
        initStruct->interByteSpace       = 0;
        initStruct->responseSpace        = 0;
        initStruct->breakDelimitLenth    = 0;
        initStruct->breakLenth           = 0;
    }
}

/**
  * @}
  */

#endif /* FL_UART_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/






