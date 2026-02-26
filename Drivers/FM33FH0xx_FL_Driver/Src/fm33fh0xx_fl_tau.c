/**
  ****************************************************************************************************
  * @file    fm33fh0xx_fl_tau.c
  * @author  FMSH Application Team
  * @brief   Src file of TAU FL Module
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

/** @addtogroup TAU
  * @{
  */

#ifdef FL_TAU_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup TAU_FL_Private_Macros
  * @{
  */

/** TAU组数 */
#define FL_TAU_GROUP_NUM        (2U)

#define IS_FL_TAU_INSTANCE(__INSTANCE__)            ((__INSTANCE__) == ((TAU_Type*)&FL_TAU00) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU01) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU02) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU03) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU04) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU05) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU06) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU07) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU10) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU11) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU12) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU13) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU14) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU15) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU16) ||\
                                                     (__INSTANCE__) == ((TAU_Type*)&FL_TAU17))

#define IS_FL_TAU_MODE(__VALUE__)                   ((__VALUE__) == (FL_TAU_OPERATION_MODE_NORMAL) ||\
                                                     (__VALUE__) == (FL_TAU_OPERATION_MODE_OC) ||\
                                                     (__VALUE__) == (FL_TAU_OPERATION_MODE_IC_PERIOD) ||\
                                                     (__VALUE__) == (FL_TAU_OPERATION_MODE_IC_WIDTH))

#define IS_FL_TAU_CASCADE_MODE(__VALUE__)           ((__VALUE__) == (FL_TAU_CASCADE_MODE_DISABLE) ||\
                                                     (__VALUE__) == (FL_TAU_CASCADE_MODE_MASTER) ||\
                                                     (__VALUE__) == (FL_TAU_CASCADE_MODE_SLAVE))

#define IS_FL_TAU_SLAVE_MODE(__VALUE__)             ((__VALUE__) == (FL_TAU_SLAVE_MODE_TRIG_CNT) ||\
                                                     (__VALUE__) == (FL_TAU_SLAVE_MODE_TRIG_START))

#define IS_FL_TAU_COUNTER_SOURCE(__VALUE__)         ((__VALUE__) == (FL_TAU_COUNTER_SOURCE_INTERNAL) ||\
                                                     (__VALUE__) == (FL_TAU_COUNTER_SOURCE_EXTERNAL) ||\
                                                     (__VALUE__) == (FL_TAU_COUNTER_SOURCE_CAPTURE_INPUT))

#define IS_FL_TAU_COUNT_EDGE(__VALUE__)             ((__VALUE__) == (FL_TAU_COUNTER_EDGE_BOTH) ||\
                                                     (__VALUE__) == (FL_TAU_COUNTER_EDGE_RISING) ||\
                                                     (__VALUE__) == (FL_TAU_COUNTER_EDGE_FALLING))

#define IS_FL_TAU_PSC(__VALUE__)                    ((__VALUE__) <= 0x000000FFU)

#define IS_FL_TAU_AUTORELOAD(__VALUE__)             ((__VALUE__) <= 0x0000FFFFU)

#define IS_FL_TAU_COMPARE(__VALUE__)                ((__VALUE__) <= 0x0000FFFFU)

#define IS_FL_TAU_OC_POLARITY(__VALUE__)            ((__VALUE__) == (FL_TAU_OC_POLARITY_NORMAL) ||\
                                                     (__VALUE__) == (FL_TAU_OC_POLARITY_INVERT))

#define IS_FL_TAU_IC_MODE(__VALUE__)                ((__VALUE__) == (FL_TAU_IC_MODE_NORMAL) ||\
                                                     (__VALUE__) == (FL_TAU_IC_MODE_RESET))

#define IS_FL_TAU_IC_SOURCE(__VALUE__)              ((__VALUE__) == (FL_TAU_IC_SOURCE_GROUP0) ||\
                                                     (__VALUE__) == (FL_TAU_IC_SOURCE_GROUP1) ||\
                                                     (__VALUE__) == (FL_TAU_IC_SOURCE_GROUP2) ||\
                                                     (__VALUE__) == (FL_TAU_IC_SOURCE_GROUP3) ||\
                                                     (__VALUE__) == (FL_TAU_IC_SOURCE_GROUP4) ||\
                                                     (__VALUE__) == (FL_TAU_IC_SOURCE_GROUP5) ||\
                                                     (__VALUE__) == (FL_TAU_IC_SOURCE_GROUP6) ||\
                                                     (__VALUE__) == (FL_TAU_IC_SOURCE_GROUP7))

#define IS_FL_TAU_TRIG_SOURCE(__VALUE__)            ((__VALUE__) == (FL_TAU_TRGI_GROUP0) ||\
                                                     (__VALUE__) == (FL_TAU_TRGI_GROUP1) ||\
                                                     (__VALUE__) == (FL_TAU_TRGI_GROUP2) ||\
                                                     (__VALUE__) == (FL_TAU_TRGI_GROUP3))

#define IS_FL_TAU_IC_EDGE(__VALUE__)                ((__VALUE__) == (FL_TAU_IC_EDGE_BOTH) ||\
                                                     (__VALUE__) == (FL_TAU_IC_EDGE_RISING) ||\
                                                     (__VALUE__) == (FL_TAU_IC_EDGE_FALLING))

#define IS_FL_TAU_IC_PSC(__VALUE__)                 ((__VALUE__) <= 0x000000FFU)

#define IS_FL_TAU_IC_USE_ONESHOT(__VALUE__)         ((__VALUE__) == (FL_ENABLE) ||\
                                                     (__VALUE__) == (FL_DISABLE))

#define IS_FL_TAU_IC_USE_FILTER(__VALUE__)          ((__VALUE__) == (FL_ENABLE) ||\
                                                     (__VALUE__) == (FL_DISABLE))

/**
  * @}
  */

/* Private consts ------------------------------------------------------------*/
/** @addtogroup TAU_FL_Private_Consts
  * @{
  */



/**
  * @}
  */

/* Private defines -----------------------------------------------------------*/
/** @defgroup TAU_FL_Private_Defines
  * @{
  */

static TAU_Type FL_TAU00 =
{
    FL_TAU_TIMER0,
    &TAU->TAU0CR,
    &TAU0->T0CFGR,
    &TAU0->T0MDR,
    &TAU0->T0ARR,
    &TAU0->T0CCR,
    &TAU0->T0IER,
    &TAU0->T0ISR,
    &TAU0->T0CNTR,
};

static TAU_Type FL_TAU01 =
{
    FL_TAU_TIMER1,
    &TAU->TAU0CR,
    &TAU0->T1CFGR,
    &TAU0->T1MDR,
    &TAU0->T1ARR,
    &TAU0->T1CCR,
    &TAU0->T1IER,
    &TAU0->T1ISR,
    &TAU0->T1CNTR,
};

static TAU_Type FL_TAU02 =
{
    FL_TAU_TIMER2,
    &TAU->TAU0CR,
    &TAU0->T2CFGR,
    &TAU0->T2MDR,
    &TAU0->T2ARR,
    &TAU0->T2CCR,
    &TAU0->T2IER,
    &TAU0->T2ISR,
    &TAU0->T2CNTR,
};

static TAU_Type FL_TAU03 =
{
    FL_TAU_TIMER3,
    &TAU->TAU0CR,
    &TAU0->T3CFGR,
    &TAU0->T3MDR,
    &TAU0->T3ARR,
    &TAU0->T3CCR,
    &TAU0->T3IER,
    &TAU0->T3ISR,
    &TAU0->T3CNTR,
};

static TAU_Type FL_TAU04 =
{
    FL_TAU_TIMER4,
    &TAU->TAU0CR,
    &TAU0->T4CFGR,
    &TAU0->T4MDR,
    &TAU0->T4ARR,
    &TAU0->T4CCR,
    &TAU0->T4IER,
    &TAU0->T4ISR,
    &TAU0->T4CNTR,
};

static TAU_Type FL_TAU05 =
{
    FL_TAU_TIMER5,
    &TAU->TAU0CR,
    &TAU0->T5CFGR,
    &TAU0->T5MDR,
    &TAU0->T5ARR,
    &TAU0->T5CCR,
    &TAU0->T5IER,
    &TAU0->T5ISR,
    &TAU0->T5CNTR,
};

static TAU_Type FL_TAU06 =
{
    FL_TAU_TIMER6,
    &TAU->TAU0CR,
    &TAU0->T6CFGR,
    &TAU0->T6MDR,
    &TAU0->T6ARR,
    &TAU0->T6CCR,
    &TAU0->T6IER,
    &TAU0->T6ISR,
    &TAU0->T6CNTR,
};

static TAU_Type FL_TAU07 =
{
    FL_TAU_TIMER7,
    &TAU->TAU0CR,
    &TAU0->T7CFGR,
    &TAU0->T7MDR,
    &TAU0->T7ARR,
    &TAU0->T7CCR,
    &TAU0->T7IER,
    &TAU0->T7ISR,
    &TAU0->T7CNTR,
};

static TAU_Type FL_TAU10 =
{
    FL_TAU_TIMER0,
    &TAU->TAU1CR,
    &TAU1->T0CFGR,
    &TAU1->T0MDR,
    &TAU1->T0ARR,
    &TAU1->T0CCR,
    &TAU1->T0IER,
    &TAU1->T0ISR,
    &TAU1->T0CNTR,
};

static TAU_Type FL_TAU11 =
{
    FL_TAU_TIMER1,
    &TAU->TAU1CR,
    &TAU1->T1CFGR,
    &TAU1->T1MDR,
    &TAU1->T1ARR,
    &TAU1->T1CCR,
    &TAU1->T1IER,
    &TAU1->T1ISR,
    &TAU1->T1CNTR,
};

static TAU_Type FL_TAU12 =
{
    FL_TAU_TIMER2,
    &TAU->TAU1CR,
    &TAU1->T2CFGR,
    &TAU1->T2MDR,
    &TAU1->T2ARR,
    &TAU1->T2CCR,
    &TAU1->T2IER,
    &TAU1->T2ISR,
    &TAU1->T2CNTR,
};

static TAU_Type FL_TAU13 =
{
    FL_TAU_TIMER3,
    &TAU->TAU1CR,
    &TAU1->T3CFGR,
    &TAU1->T3MDR,
    &TAU1->T3ARR,
    &TAU1->T3CCR,
    &TAU1->T3IER,
    &TAU1->T3ISR,
    &TAU1->T3CNTR,
};

static TAU_Type FL_TAU14 =
{
    FL_TAU_TIMER4,
    &TAU->TAU1CR,
    &TAU1->T4CFGR,
    &TAU1->T4MDR,
    &TAU1->T4ARR,
    &TAU1->T4CCR,
    &TAU1->T4IER,
    &TAU1->T4ISR,
    &TAU1->T4CNTR,
};

static TAU_Type FL_TAU15 =
{
    FL_TAU_TIMER5,
    &TAU->TAU1CR,
    &TAU1->T5CFGR,
    &TAU1->T5MDR,
    &TAU1->T5ARR,
    &TAU1->T5CCR,
    &TAU1->T5IER,
    &TAU1->T5ISR,
    &TAU1->T5CNTR,
};

static TAU_Type FL_TAU16 =
{
    FL_TAU_TIMER6,
    &TAU->TAU1CR,
    &TAU1->T6CFGR,
    &TAU1->T6MDR,
    &TAU1->T6ARR,
    &TAU1->T6CCR,
    &TAU1->T6IER,
    &TAU1->T6ISR,
    &TAU1->T6CNTR,
};

static TAU_Type FL_TAU17 =
{
    FL_TAU_TIMER7,
    &TAU->TAU1CR,
    &TAU1->T7CFGR,
    &TAU1->T7MDR,
    &TAU1->T7ARR,
    &TAU1->T7CCR,
    &TAU1->T7IER,
    &TAU1->T7ISR,
    &TAU1->T7CNTR,
};

static __IO uint32_t *const FL_TAU_CR[FL_TAU_GROUP_NUM] =
{
    &TAU->TAU0CR,
    &TAU->TAU1CR,
};

/**
  * @}
  */

/* Exported consts -----------------------------------------------------------*/
/** @defgroup TAU_FL_Exported_Consts
  * @{
  */

/**
  * @brief FL TAU0 Timer Units
  */
TAU_Type *const TAU00 = &FL_TAU00;
TAU_Type *const TAU01 = &FL_TAU01;
TAU_Type *const TAU02 = &FL_TAU02;
TAU_Type *const TAU03 = &FL_TAU03;
TAU_Type *const TAU04 = &FL_TAU04;
TAU_Type *const TAU05 = &FL_TAU05;
TAU_Type *const TAU06 = &FL_TAU06;
TAU_Type *const TAU07 = &FL_TAU07;


/**
  * @brief FL TAU1 Timer Units
  */
TAU_Type *const TAU10 = &FL_TAU10;
TAU_Type *const TAU11 = &FL_TAU11;
TAU_Type *const TAU12 = &FL_TAU12;
TAU_Type *const TAU13 = &FL_TAU13;
TAU_Type *const TAU14 = &FL_TAU14;
TAU_Type *const TAU15 = &FL_TAU15;
TAU_Type *const TAU16 = &FL_TAU16;
TAU_Type *const TAU17 = &FL_TAU17;

/**
  * @brief FL TAU Timer Unit Enable/Disable Control Registers Defines
  */
__IO uint32_t *const * const TAU_CR = FL_TAU_CR;

/* Private function prototypes -----------------------------------------------*/
static uint32_t FL_TAU_GetTAUGroupId(TAU_Type *TAUxy);

/* Exported functions --------------------------------------------------------*/



/**
  * @brief  根据配置信息初始化对应外设入口地址的寄存器值
  * @param  TAUxy TAU单元实例
  * @param  initStruct 指向一个 @ref FL_TAU_InitTypeDef 结构体，其中包含了配置信息
  * @retval @ref FL_ErrorStatus 执行结果
  */
FL_ErrorStatus FL_TAU_Init(TAU_Type *TAUxy, FL_TAU_InitTypeDef *initStruct)
{
    uint32_t groupId;
    assert_param(IS_FL_TAU_INSTANCE(TAUxy));
    groupId = FL_TAU_GetTAUGroupId(TAUxy);
    assert_param(groupId < FL_TAU_GROUP_NUM && groupId != 0xFFFFFFFFUL);
    assert_param(IS_FL_TAU_MODE(initStruct->mode));
    assert_param(IS_FL_TAU_CASCADE_MODE(initStruct->cascadeMode));
    assert_param(IS_FL_TAU_PSC(initStruct->prescaler));
    assert_param(IS_FL_TAU_AUTORELOAD(initStruct->autoReload));
    /* 打开总线时钟 */
    switch(groupId)
    {
        case 0: /* TAU0 */
            FL_CMU_EnableGroup4BusClock(FL_CMU_GROUP4_BUSCLK_TAU0);
            break;
        case 1: /* TAU1 */
            FL_CMU_EnableGroup4BusClock(FL_CMU_GROUP4_BUSCLK_TAU1);
            break;
        default:
            /* 不应该到此处 */
            break;
    }
    /* 工作模式 */
    FL_TAU_SetOperationMode(TAUxy, initStruct->mode);
    /* 预分频 */
    FL_TAU_WritePrescaler(TAUxy, initStruct->prescaler);
    /* 预装载 */
    FL_TAU_WriteAutoReload(TAUxy, initStruct->autoReload);
    /* 级联模式 */
    if(initStruct->cascadeMode == FL_TAU_CASCADE_MODE_DISABLE)  /* 无级联 */
    {
        assert_param(IS_FL_TAU_COUNTER_SOURCE(initStruct->counterSource));
        assert_param(IS_FL_TAU_COUNT_EDGE(initStruct->countEdge));
        /* 禁止从机 */
        FL_TAU_DisableSlaveMode(TAUxy);
        /* 计数源 */
        FL_TAU_SetCounterSource(TAUxy, initStruct->counterSource);
        /* 计数边沿 */
        FL_TAU_SetCounterEdge(TAUxy, initStruct->countEdge);
    }
    else if(initStruct->cascadeMode == FL_TAU_CASCADE_MODE_MASTER) /* 级联主机 */
    {
        assert_param(IS_FL_TAU_COUNTER_SOURCE(initStruct->counterSource));
        assert_param(IS_FL_TAU_COUNT_EDGE(initStruct->countEdge));
        assert_param(IS_FL_TAU_COMPARE(initStruct->compare));
        /* 计数源 */
        FL_TAU_SetCounterSource(TAUxy, initStruct->counterSource);
        /* 计数边沿 */
        FL_TAU_SetCounterEdge(TAUxy, initStruct->countEdge);
        /* 比较值 */
        FL_TAU_WriteCompare(TAUxy, initStruct->compare);
    }
    else     /* 级联从机 */
    {
        assert_param(IS_FL_TAU_SLAVE_MODE(initStruct->slaveMode));
        assert_param(IS_FL_TAU_TRIG_SOURCE(initStruct->slaveTriggerSource));
        /* 使能从机 */
        FL_TAU_EnableSlaveMode(TAUxy);
        /* 从机模式 */
        FL_TAU_SetSlaveMode(TAUxy, initStruct->slaveMode);
        /* 触发输入源 */
        FL_TAU_SetTriggerSource(TAUxy, initStruct->slaveTriggerSource);
    }
    if(initStruct->mode == FL_TAU_OPERATION_MODE_NORMAL)    /* 普通计数模式 */
    {
        if(initStruct->counterSource == FL_TAU_COUNTER_SOURCE_CAPTURE_INPUT)    /* 捕获计数 */
        {
            assert_param(IS_FL_TAU_IC_SOURCE(initStruct->captureSource));
            assert_param(IS_FL_TAU_IC_USE_FILTER(initStruct->useCaptureFilter));
            /* 捕获源 */
            FL_TAU_IC_SetSource(TAUxy, initStruct->captureSource);
            /* 捕获滤波 */
            if(initStruct->useCaptureFilter == FL_ENABLE)
            {
                FL_TAU_IC_EnableFilter(TAUxy);
            }
            else
            {
                FL_TAU_IC_DisableFilter(TAUxy);
            }
        }
    }
    else if(initStruct->mode == FL_TAU_OPERATION_MODE_OC)   /* 比较输出模式 */
    {
        assert_param(IS_FL_TAU_COMPARE(initStruct->compare));
        assert_param(IS_FL_TAU_OC_POLARITY(initStruct->outputPolarity));
        /* 比较值 */
        FL_TAU_WriteCompare(TAUxy, initStruct->compare);
        /* 极性 */
        FL_TAU_OC_SetPolarity(TAUxy, initStruct->outputPolarity);
    }
    else if((initStruct->mode == FL_TAU_OPERATION_MODE_IC_PERIOD) || /* 周期捕获模式 */
            (initStruct->mode == FL_TAU_OPERATION_MODE_IC_WIDTH))  /* 脉宽捕获模式 */
    {
        assert_param(IS_FL_TAU_IC_MODE(initStruct->captureMode));
        assert_param(IS_FL_TAU_IC_SOURCE(initStruct->captureSource));
        assert_param(IS_FL_TAU_IC_EDGE(initStruct->captureEdge));
        assert_param(IS_FL_TAU_IC_PSC(initStruct->capturePrescaler));
        assert_param(IS_FL_TAU_IC_USE_ONESHOT(initStruct->useOneShotCapture));
        assert_param(IS_FL_TAU_IC_USE_FILTER(initStruct->useCaptureFilter));
        /* 捕获模式 */
        FL_TAU_IC_SetMode(TAUxy, initStruct->captureMode);
        /* 捕获源 */
        FL_TAU_IC_SetSource(TAUxy, initStruct->captureSource);
        /* 捕获边沿 */
        FL_TAU_IC_SetCaptureEdge(TAUxy, initStruct->captureEdge);
        /* 捕获预分频 */
        FL_TAU_IC_WritePrescaler(TAUxy, initStruct->capturePrescaler);
        /* 单次捕获 */
        if(initStruct->useOneShotCapture == FL_ENABLE)
        {
            FL_TAU_IC_EnableOneShot(TAUxy);
        }
        else
        {
            FL_TAU_IC_DisableOneShot(TAUxy);
        }
        /* 捕获滤波 */
        if(initStruct->useCaptureFilter == FL_ENABLE)
        {
            FL_TAU_IC_EnableFilter(TAUxy);
        }
        else
        {
            FL_TAU_IC_DisableFilter(TAUxy);
        }
    }
    else
    {
        /* 不应来到此处 */
    }
    return FL_PASS;
}

/**
  * @brief  复位对应TAU寄存器
  * @param  TAUxy TAU单元实例
  * @retval @ref FL_ErrorStatus 执行结果
  */
FL_ErrorStatus FL_TAU_DeInit(TAU_Type *TAUxy)
{
    assert_param(IS_FL_TAU_INSTANCE(TAUxy));
    /* 关闭TAU */
    FL_TAU_Disable(TAUxy);
    /* 复位寄存器值 */
    *TAUxy->CFGR = 0x0UL;
    *TAUxy->MDR = 0x0UL;
    *TAUxy->ARR = 0x0UL;
    *TAUxy->CCR = 0x0UL;
    *TAUxy->IER = 0x0UL;
    *TAUxy->ISR = 0xFUL;
    return FL_PASS;
}

/**
  * @brief  设置TAU初始化结构体为默认值
  * @param  initStruct 指向需要将值设置为默认配置的结构体 @ref FL_TAU_InitTypeDef 结构体
  */
void FL_TAU_StructInit(FL_TAU_InitTypeDef *initStruct)
{
    if(initStruct != NULL)
    {
        initStruct->mode = FL_TAU_OPERATION_MODE_NORMAL;
        initStruct->cascadeMode = FL_TAU_CASCADE_MODE_DISABLE;
        initStruct->slaveMode = FL_TAU_SLAVE_MODE_TRIG_CNT;
        initStruct->slaveTriggerSource = FL_TAU_TRGI_GROUP0;
        initStruct->counterSource = FL_TAU_COUNTER_SOURCE_INTERNAL;
        initStruct->countEdge = FL_TAU_COUNTER_EDGE_RISING;
        initStruct->prescaler = 0U;
        initStruct->autoReload = 0U;
        initStruct->compare = 0U;
        initStruct->outputPolarity = FL_TAU_OC_POLARITY_NORMAL;
        initStruct->captureMode = FL_TAU_IC_MODE_NORMAL;
        initStruct->captureSource = FL_TAU_IC_SOURCE_GROUP0;
        initStruct->captureEdge = FL_TAU_IC_EDGE_RISING;
        initStruct->capturePrescaler = 0U;
        initStruct->useOneShotCapture = FL_DISABLE;
        initStruct->useCaptureFilter = FL_DISABLE;
    }
}

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup TAU_FL_Private_Functions TAU Private Functions
  * @{
  */

/**
  * @brief  获取TAUxy对应的定时器组
  * @param  TAUxy TAU实例
  * @retval TAU组序号
  */
static uint32_t FL_TAU_GetTAUGroupId(TAU_Type *TAUxy)
{
    uint8_t i;
    for(i = 0; i < FL_TAU_GROUP_NUM; i++)
    {
        /* 使用实例的CR寄存器位置来判断实例所属TAU组 */
        if((uint32_t)TAUxy->CR == (uint32_t)FL_TAU_CR[i])
        {
            return i;
        }
    }
    return 0xFFFFFFFFUL;
}

/**
  * @}
  */

#endif /* FL_TAU_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
