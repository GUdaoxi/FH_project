 /** 
  *******************************************************************************************************
  * @file    fm33fh0xx_fl_exti.c
  * @author  FMSH Application Team
  * @brief   Source file of EXTI FL Module 
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

/** @addtogroup EXTI
  * @{
  */

#ifdef FL_EXTI_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup EXTI_FL_Private_Macros
  * @{
  */
#define IS_EXTI_ALL_INSTANCE(INTENCE)       (((INTENCE) == GPIOA)||\
                                             ((INTENCE) == GPIOB)||\
                                             ((INTENCE) == GPIOC)||\
                                             ((INTENCE) == GPIOD)||\
                                             ((INTENCE) == GPIOE)||\
                                             ((INTENCE) == GPIOF)||\
                                             ((INTENCE) == GPIOG))
                                             
#define IS_EXTI_PIN_MULTIPLE(__VALUE__)     ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                             ((__VALUE__) <= (FL_GPIO_PIN_ALL)))

#define IS_EXTI_PIN_SINGLE(__VALUE__)       (((__VALUE__) == FL_GPIO_PIN_0)||\
                                             ((__VALUE__) == FL_GPIO_PIN_1)||\
                                             ((__VALUE__) == FL_GPIO_PIN_2)||\
                                             ((__VALUE__) == FL_GPIO_PIN_3)||\
                                             ((__VALUE__) == FL_GPIO_PIN_4)||\
                                             ((__VALUE__) == FL_GPIO_PIN_5)||\
                                             ((__VALUE__) == FL_GPIO_PIN_6)||\
                                             ((__VALUE__) == FL_GPIO_PIN_7)||\
                                             ((__VALUE__) == FL_GPIO_PIN_8)||\
                                             ((__VALUE__) == FL_GPIO_PIN_9)||\
                                             ((__VALUE__) == FL_GPIO_PIN_10)||\
                                             ((__VALUE__) == FL_GPIO_PIN_11)||\
                                             ((__VALUE__) == FL_GPIO_PIN_12)||\
                                             ((__VALUE__) == FL_GPIO_PIN_13)||\
                                             ((__VALUE__) == FL_GPIO_PIN_14)||\
                                             ((__VALUE__) == FL_GPIO_PIN_15))

#define IS_EXTI_CLK_SOURCE(__VALUE__)       (((__VALUE__) == FL_CMU_EXTI_CLK_SOURCE_HCLK)||\
                                             ((__VALUE__) == FL_CMU_EXTI_CLK_SOURCE_LSCLK))
                                          
#define IS_EXTI_CLK_EXTIONSLEEP(__VALUE__)  (((__VALUE__) == FL_DISABLE)||\
                                             ((__VALUE__) == FL_ENABLE))
                                         
#define IS_EXTI_TRIG_EDGE(__VALUE__)        (((__VALUE__) == FL_GPIO_EXTI_TRIGGER_EDGE_RISING)||\
                                             ((__VALUE__) == FL_GPIO_EXTI_TRIGGER_EDGE_FALLING)||\
                                             ((__VALUE__) == FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE)||\
                                             ((__VALUE__) == FL_GPIO_EXTI_TRIGGER_EDGE_BOTH))
                                         
#define IS_EXTI_FILTER(__VALUE__)           (((__VALUE__) == FL_DISABLE)||\
                                             ((__VALUE__) == FL_ENABLE))

/**
  * @}
  */

/* Private consts ------------------------------------------------------------*/
/** @addtogroup EXTI_FL_Private_Consts
  * @{
  */
typedef struct {
    /* EXTI Port */
    GPIO_Type *GPIOx;
    /* 设置EXTI边沿触发模式 */
    void (*pSetTrigEdgeFunc)(GPIO_COMMON_Type *GPIOx, uint32_t pin, uint32_t edge);
    /* 读取EXTI边沿触发模式 */
    uint32_t (*pGetTrigEdgeFunc)(GPIO_COMMON_Type *GPIOx, uint32_t pin);
    
    /* 使能EXTI数字滤波 */
    void (*pEnableDigitalFilterFunc)(GPIO_COMMON_Type *GPIOx, uint32_t pin);
    /* 禁止EXTI数字滤波 */
    void (*pDisableDigitalFilterFunc)(GPIO_COMMON_Type *GPIOx, uint32_t pin);
    /* 读取EXTI数字滤波使能状态 */
    uint32_t (*pIsEnabledDigitalFilterFunc)(GPIO_COMMON_Type *GPIOx, uint32_t pin);
    
    /* 读取EXTI中断标志 */
    uint32_t (*pIsActiveFlagFunc)(GPIO_COMMON_Type *GPIOx, uint32_t pin);
    /* 清除EXTI中断标志*/
    void (*pClearFlagFunc)(GPIO_COMMON_Type *GPIOx, uint32_t pin);
    
    /* 读取EXTI引脚输入电平 */
    uint32_t (*pGetInputPinFunc)(GPIO_COMMON_Type *GPIOx, uint32_t pin);
}EXTI_INFO_TYPE;


/* EXTI信息表 */
static const EXTI_INFO_TYPE ExtiInfo[]= {
    {GPIOA, FL_GPIO_SetTriggerEdgePA,      FL_GPIO_GetTriggerEdgePA,\
            FL_GPIO_EnableDigitalFilterPA, FL_GPIO_DisableDigitalFilterPA, FL_GPIO_IsEnabledDigitalFilterPA,\
            FL_GPIO_IsActiveFlag_EXTI_PA,  FL_GPIO_ClearFlag_EXTI_PA,\
            FL_GPIO_GetEXTIInputPinPA},\
    
    {GPIOB, FL_GPIO_SetTriggerEdgePB,      FL_GPIO_GetTriggerEdgePB,\
            FL_GPIO_EnableDigitalFilterPB, FL_GPIO_DisableDigitalFilterPB, FL_GPIO_IsEnabledDigitalFilterPB,\
            FL_GPIO_IsActiveFlag_EXTI_PB,  FL_GPIO_ClearFlag_EXTI_PB,\
            FL_GPIO_GetEXTIInputPinPB},\

    {GPIOC, FL_GPIO_SetTriggerEdgePC,      FL_GPIO_GetTriggerEdgePC,\
            FL_GPIO_EnableDigitalFilterPC, FL_GPIO_DisableDigitalFilterPC, FL_GPIO_IsEnabledDigitalFilterPC,\
            FL_GPIO_IsActiveFlag_EXTI_PC,  FL_GPIO_ClearFlag_EXTI_PC,\
            FL_GPIO_GetEXTIInputPinPC},\
    
    {GPIOD, FL_GPIO_SetTriggerEdgePD,      FL_GPIO_GetTriggerEdgePD,\
            FL_GPIO_EnableDigitalFilterPD, FL_GPIO_DisableDigitalFilterPD, FL_GPIO_IsEnabledDigitalFilterPD,\
            FL_GPIO_IsActiveFlag_EXTI_PD,  FL_GPIO_ClearFlag_EXTI_PD,\
            FL_GPIO_GetEXTIInputPinPD},\

    {GPIOE, FL_GPIO_SetTriggerEdgePE,      FL_GPIO_GetTriggerEdgePE,\
            FL_GPIO_EnableDigitalFilterPE, FL_GPIO_DisableDigitalFilterPE, FL_GPIO_IsEnabledDigitalFilterPE,\
            FL_GPIO_IsActiveFlag_EXTI_PE,  FL_GPIO_ClearFlag_EXTI_PE,\
            FL_GPIO_GetEXTIInputPinPE},\
    
    {GPIOF, FL_GPIO_SetTriggerEdgePF,      FL_GPIO_GetTriggerEdgePF,\
            FL_GPIO_EnableDigitalFilterPF, FL_GPIO_DisableDigitalFilterPF, FL_GPIO_IsEnabledDigitalFilterPF,\
            FL_GPIO_IsActiveFlag_EXTI_PF,  FL_GPIO_ClearFlag_EXTI_PF,\
            FL_GPIO_GetEXTIInputPinPF},\
            
    {GPIOG, FL_GPIO_SetTriggerEdgePG,      FL_GPIO_GetTriggerEdgePG,\
            FL_GPIO_EnableDigitalFilterPG, FL_GPIO_DisableDigitalFilterPG, FL_GPIO_IsEnabledDigitalFilterPG,\
            FL_GPIO_IsActiveFlag_EXTI_PG,  FL_GPIO_ClearFlag_EXTI_PG,\
            FL_GPIO_GetEXTIInputPinPG},\
            
};
static const uint8_t ExtiInfoNums = (sizeof(ExtiInfo) / sizeof(ExtiInfo[0])); 

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/


/* Exported functions --------------------------------------------------------*/
/** @addtogroup EXTI_FL_EF_Init
  * @{
  */
/** @addtogroup EXTI_FL_EF_Init
  * @{
  */

/**
  * @brief  EXTI通用配置设置
  *
  * @param  EXTI_CommonInitStruct 指向 @ref FL_EXTI_CommonInitTypeDef 类型的结构体，它包含EXTI外设通用配置信息
  *         clockSource:
  *             @arg @ref FL_CMU_EXTI_CLK_SOURCE_LSCLK
  *             @arg @ref FL_CMU_EXTI_CLK_SOURCE_HCLK
  *         EXTIOnSleep:
  *             @arg @ref FL_DISABLE
  *             @arg @ref FL_ENABLE
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS EXTI配置成功
  */
FL_ErrorStatus FL_EXTI_CommonInit(FL_EXTI_CommonInitTypeDef *EXTI_CommonInitStruct)
{
    if (EXTI_CommonInitStruct != NULL)
    {
        assert_param(IS_EXTI_CLK_SOURCE(EXTI_CommonInitStruct->clockSource));
        assert_param(IS_EXTI_CLK_EXTIONSLEEP(EXTI_CommonInitStruct->EXTIOnSleep));
        assert_param(!((EXTI_CommonInitStruct->clockSource == FL_CMU_EXTI_CLK_SOURCE_HCLK) &&\
                       (EXTI_CommonInitStruct->EXTIOnSleep == FL_ENABLE)) );
        /* 使能IO时钟寄存器总线时钟 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_PAD);
        /* 使能并配置外部中断时钟源 */
        FL_CMU_EnableOperationClock(FL_CMU_GROUP1_OPCLKEN_EXTI);
        FL_CMU_SetEXTIClockSource(EXTI_CommonInitStruct->clockSource);
        /* 使能或禁止Sleep/DeepSleep模式下的EXTI功能 */
        if (FL_DISABLE == EXTI_CommonInitStruct->EXTIOnSleep)
        {
            FL_CMU_DisableEXTIOnSleep();
        }
        else
        {
            FL_CMU_EnableEXTIOnSleep();
        }
        return FL_PASS;
    }
    return FL_FAIL;
}

/**
  * @brief  复位EXTI通用配置设置
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 发生错误
  *         -FL_PASS EXTI通用设置复位成功
  */
FL_ErrorStatus FL_EXTI_CommonDeinit(void)
{
    /*  关闭外部中断时钟源 */
    FL_CMU_DisableOperationClock(FL_CMU_GROUP1_OPCLKEN_EXTI);
    return FL_PASS;
}

/**
  * @brief  设置 EXTI_CommonInitStruct 为默认配置
  * @param  EXTI_CommonInitStruct 指向需要将值设置为默认配置的结构体 @ref FL_EXTI_CommonInitTypeDef 结构体
  *         clockSource:
  *             @arg @ref FL_CMU_EXTI_CLK_SOURCE_LSCLK
  *             @arg @ref FL_CMU_EXTI_CLK_SOURCE_HCLK
  *         EXTIOnSleep:
  *             @arg @ref FL_DISABLE
  *             @arg @ref FL_ENABLE
  *
  * @retval None
  */
void FL_EXTI_CommonStructInit(FL_EXTI_CommonInitTypeDef *EXTI_CommonInitStruct)
{
    if (EXTI_CommonInitStruct != NULL)
    {
        EXTI_CommonInitStruct->clockSource = FL_CMU_EXTI_CLK_SOURCE_LSCLK;
        EXTI_CommonInitStruct->EXTIOnSleep = FL_ENABLE;
    }
}


/**
  * @brief  EXTI配置设置
  *
  * @param  GPIOx: GPIO组
  * @param  EXTI_InitStruct 指向 @ref FL_EXTI_InitTypeDef 类型的结构体，它包含EXTI外设配置信息
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS EXTI配置成功
  */
FL_ErrorStatus FL_EXTI_Init(GPIO_Type *GPIOx, FL_EXTI_InitTypeDef *EXTI_InitStruct)
{
    uint32_t group, extiPinPos = 0, extiCurrentPin = 0;
    volatile uint32_t j;
    /*  通过内核时钟计算200us延时的计数个数 */
    uint32_t temp = (SystemCoreClock / 1000000) * 200;
    FL_ErrorStatus status = FL_FAIL;
    
    if (NULL != EXTI_InitStruct)
    {   /* 检查参数合法性 */
        assert_param(IS_EXTI_ALL_INSTANCE(GPIOx));
        assert_param(IS_EXTI_PIN_MULTIPLE(EXTI_InitStruct->extiPinX));
        assert_param(IS_EXTI_TRIG_EDGE(EXTI_InitStruct->triggerEdge));
        assert_param(IS_EXTI_FILTER(EXTI_InitStruct->filter));
        
        /* 获取Group */
        group = GPIOx - GPIOA;
        if ((GPIOA <= GPIOx) && (GPIOG >= GPIOx) && (ExtiInfoNums > group) && (ExtiInfo[group].GPIOx == GPIOx))
        {
            /* 使能时钟总线 */
            FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_PAD);
            /* 这里考虑到PIN有可能不止一个因此需要遍历 */
            while (((EXTI_InitStruct->extiPinX) >> extiPinPos) != 0x00000000U)
            {
                /* 获取当前遍历到的Exit Pin脚 */
                extiCurrentPin = (EXTI_InitStruct->extiPinX) & (0x1UL << extiPinPos);
                if (extiCurrentPin != 0X0U)
                {   /*  设置数字滤波 */
                    if (FL_ENABLE == EXTI_InitStruct->filter)
                    {
                        ExtiInfo[group].pEnableDigitalFilterFunc(GPIO, extiCurrentPin);
                    }
                    else
                    {
                        ExtiInfo[group].pDisableDigitalFilterFunc(GPIO, extiCurrentPin);
                    }
                    /* 设置中断线触发边沿 */
                    ExtiInfo[group].pSetTrigEdgeFunc(GPIO, extiCurrentPin, EXTI_InitStruct->triggerEdge);
                    /*  等待至少周期6个LSCLK周期，约200us */
                    for (j = 0; j < temp; j++)
                    {
                        __NOP();
                    }
                    /*  清除外部中断标志 */
                    ExtiInfo[group].pClearFlagFunc(GPIO, extiCurrentPin);
                    /*  清除中断挂起 */
                    NVIC_ClearPendingIRQ(MUX30_IRQn);
                    status = FL_PASS;
                }
                extiPinPos++;
            }
        }
    }
    return status;
}

/**
  * @brief  复位EXTI配置设置
  *
  * @param  GPIOx：GPIO组
  * @param  extiPinX：EXTI引脚
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 发生错误
  *         -FL_PASS EXTI设置复位成功
  */
FL_ErrorStatus FL_EXTI_DeInit(GPIO_Type *GPIOx, uint32_t extiPinX)
{
    uint32_t group, extiPinPos = 0, extiCurrentPin = 0;
    FL_ErrorStatus status = FL_FAIL;
    
    /*  检查参数合法性 */
    assert_param(IS_EXTI_ALL_INSTANCE(GPIOx));
    assert_param(IS_EXTI_PIN_MULTIPLE(extiPinX));
    /* 获取Group */
    group = GPIOx - GPIOA;
    if ((GPIOA <= GPIOx) && (GPIOG >= GPIOx) && (ExtiInfoNums > group) && (ExtiInfo[group].GPIOx == GPIOx))
    {
        /* 使能时钟总线 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_PAD);
        /* 这里考虑到PIN有可能不止一个因此需要遍历 */
        while ((extiPinX >> extiPinPos) != 0x00000000U)
        {
             /* 获取当前遍历到的Exit Pin脚 */
             extiCurrentPin = extiPinX & (0x1UL << extiPinPos);
             if (extiCurrentPin != 0X0U)
             {   /* 中断线触发边沿禁止 */
                 ExtiInfo[group].pSetTrigEdgeFunc(GPIO, extiCurrentPin, FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE);
                 /* 禁止数字滤波 */
                 ExtiInfo[group].pDisableDigitalFilterFunc(GPIO, extiCurrentPin);
                 /* 清除外部中断标志 */
                 ExtiInfo[group].pClearFlagFunc(GPIO, extiCurrentPin);
                 /* 清除中断挂起 */
                 NVIC_ClearPendingIRQ(MUX30_IRQn);
                 status = FL_PASS;
             }
             extiPinPos++;
        }
    }
    return status;
}

/**
  * @brief  读取EXTI边缘触发模式
  *
  * @param  GPIOx：GPIO组
  * @param  extiPinX：EXTI引脚
  *
  * @retval 边缘触发模式
  *         -FL_GPIO_EXTI_TRIGGER_EDGE_RISING
  *         -FL_GPIO_EXTI_TRIGGER_EDGE_FALLING
  *         -FL_GPIO_EXTI_TRIGGER_EDGE_BOTH
  *         -FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE
  */
uint32_t FL_EXTI_GetTrigEdge(GPIO_Type *GPIOx, uint32_t extiPinX)
{
    uint32_t group, Edge = FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE; 
    
    /* 检查参数合法性 */
    assert_param(IS_EXTI_ALL_INSTANCE(GPIOx));
    assert_param(IS_EXTI_PIN_SINGLE(extiPinX));
    /* 获取Group */
    group = GPIOx - GPIOA;
    if ((GPIOA <= GPIOx) && (GPIOG >= GPIOx) && (ExtiInfoNums > group) && (ExtiInfo[group].GPIOx == GPIOx))
    {   /* 读取EXTI边缘触发方式 */
        Edge = ExtiInfo[group].pGetTrigEdgeFunc(GPIO, extiPinX);
    }
    return Edge;
}

/**
  * @brief  读取EXTI数字滤波状态
  *
  * @param  GPIOx：GPIO组
  * @param  extiPinX：EXTI引脚
  *
  * @retval 数字滤波状态
  *         -0 关闭EXTI数字滤波
  *         -1 使能EXTI数字滤波
  */
uint32_t FL_EXTI_IsEnabledDigitalFilter(GPIO_Type *GPIOx, uint32_t extiPinX)
{
    uint32_t group, DigitalFilter = 0x0;
    
    /* 检查参数合法性 */
    assert_param(IS_EXTI_ALL_INSTANCE(GPIOx));
    assert_param(IS_EXTI_PIN_SINGLE(extiPinX));
    /* 获取Group */
    group = GPIOx - GPIOA;
    if ((GPIOA <= GPIOx) && (GPIOG >= GPIOx) && (ExtiInfoNums > group) && (ExtiInfo[group].GPIOx == GPIOx))
    {   /* 读取EXTI数字滤波状态 */
        DigitalFilter = ExtiInfo[group].pIsEnabledDigitalFilterFunc(GPIO, extiPinX);
    }
    return DigitalFilter;
}

/**
  * @brief  读取EXTI中断标志
  *
  * @param  GPIOx：GPIO组
  * @param  extiPinX：EXTI引脚
  *
  * @retval 中断标志
  *         -0 EXTI ISR中断标志为0
  *         -1 EXTI ISR中断标志为1
  */
uint32_t FL_EXTI_IsActiveFlag(GPIO_Type *GPIOx, uint32_t extiPinX)
{
    uint32_t group, ITFlag = 0x0;
    
    /*  检查参数合法性 */
    assert_param(IS_EXTI_ALL_INSTANCE(GPIOx));
    assert_param(IS_EXTI_PIN_SINGLE(extiPinX));
    /* 获取Group */
    group = GPIOx - GPIOA;
    if ((GPIOA <= GPIOx) && (GPIOG >= GPIOx) && (ExtiInfoNums > group) && (ExtiInfo[group].GPIOx == GPIOx))
    {   /* 读取中断标志 */
        ITFlag = ExtiInfo[group].pIsActiveFlagFunc(GPIO, extiPinX);
    }
    return ITFlag;
}

/**
  * @brief  清除EXTI中断标志
  *
  * @param  GPIOx：GPIO组
  * @param  extiPinX：EXTI引脚
  *
  * @retval None
  */
void FL_EXTI_ClearFlag(GPIO_Type *GPIOx, uint32_t extiPinX)
{
    uint32_t group;
    
    /* 检查参数合法性 */
    assert_param(IS_EXTI_ALL_INSTANCE(GPIOx));
    assert_param(IS_EXTI_PIN_MULTIPLE(extiPinX));
    /* 获取Group */
    group = GPIOx - GPIOA;
    if ((GPIOA <= GPIOx) && (GPIOG >= GPIOx) && (ExtiInfoNums > group) && (ExtiInfo[group].GPIOx == GPIOx))
    {   /* 清除中断标识 */
        ExtiInfo[group].pClearFlagFunc(GPIO, extiPinX);
    }
}

/**
  * @brief  读取EXTI引脚的输入电平状态
  *
  * @param  GPIOx：GPIO组
  * @param  extiPinX：EXTI引脚
  *
  * @retval 电平状态
  *         -0 低电平
  *         -1 高电平
  */
uint32_t FL_EXTI_GetInputPin(GPIO_Type *GPIOx, uint32_t extiPinX)
{
    uint32_t group, InputPin = 0x1;
    
    /* 检查参数合法性 */
    assert_param(IS_EXTI_ALL_INSTANCE(GPIOx));
    assert_param(IS_EXTI_PIN_SINGLE(extiPinX));
    /* 获取Group */
    group = GPIOx - GPIOA;
    if ((GPIOA <= GPIOx) && (GPIOG >= GPIOx) && (ExtiInfoNums > group) && (ExtiInfo[group].GPIOx == GPIOx))
    {   /* 读取EXTI引脚的输入电平状态 */
        InputPin = ExtiInfo[group].pGetInputPinFunc(GPIO, extiPinX);
    }
    return InputPin;
}


/**
  * @brief  设置 EXTI_InitStruct 为默认配置
  * @param  EXTI_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_EXTI_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_EXTI_StructInit(FL_EXTI_InitTypeDef *EXTI_InitStruct)
{
    if (EXTI_InitStruct != NULL)
    {
        EXTI_InitStruct->extiPinX    = FL_GPIO_PIN_0;
        EXTI_InitStruct->triggerEdge = FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE;
        EXTI_InitStruct->filter      = FL_DISABLE;
    }
}



/**
  * @}
  */

#endif /* FL_EXTI_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
