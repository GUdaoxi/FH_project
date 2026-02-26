/**
  ****************************************************************************************************
  * @file    fm33fh0xx_fl_gpio.c
  * @author  FMSH Application Team
  * @brief   Src file of GPIO FL Module
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

/** @addtogroup GPIO
  * @{
  */

#ifdef FL_GPIO_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup GPIO_FL_Private_Macros
  * @{
  */

#define         IS_GPIO_ALL_INSTANCE(INSTANCE)             (((INSTANCE) == GPIOA)||\
                                                            ((INSTANCE) == GPIOB)||\
                                                            ((INSTANCE) == GPIOC)||\
                                                            ((INSTANCE) == GPIOD)||\
                                                            ((INSTANCE) == GPIOE)||\
                                                            ((INSTANCE) == GPIOF)||\
                                                            ((INSTANCE) == GPIOG)||\
                                                            ((INSTANCE) == GPIOH))

#define         IS_FL_GPIO_PIN(__VALUE__)                  ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                                            ((__VALUE__) <= (FL_GPIO_PIN_ALL)))

#define         IS_FL_GPIO_MODE(__VALUE__)                  (((__VALUE__) == FL_GPIO_MODE_ANALOG)||\
                                                             ((__VALUE__) == FL_GPIO_MODE_INPUT)||\
                                                             ((__VALUE__) == FL_GPIO_MODE_OUTPUT)||\
                                                             ((__VALUE__) == FL_GPIO_MODE_DIGITAL))

#define         IS_FL_GPIO_OPENDRAIN(__VALUE__)             (((__VALUE__) == FL_GPIO_OUTPUT_OPENDRAIN)||\
                                                             ((__VALUE__) == FL_GPIO_OUTPUT_PUSHPULL))

#define         IS_FL_GPIO_DRIVESTRENGTH(__VALUE__)         (((__VALUE__) == FL_GPIO_DRIVESTRENGTH_CLOSE)||\
                                                             ((__VALUE__) == FL_GPIO_DRIVESTRENGTH_X1)||\
                                                             ((__VALUE__) == FL_GPIO_DRIVESTRENGTH_X2)||\
                                                             ((__VALUE__) == FL_GPIO_DRIVESTRENGTH_X3))
    
#define         IS_FL_GPIO_PULL_UP(__VALUE__)                (((__VALUE__) == FL_GPIO_PULLUP_ENABLE)||\
                                                             ((__VALUE__) == FL_GPIO_PULLDOWN_ENABLE)||\
                                                             ((__VALUE__) == FL_GPIO_BOTH_DISABLE))



 #define        IS_FL_GPIO_REMAPPIN(__VALUE__)              (((__VALUE__) == FL_GPIO_PINREMAP_FUNCTON0)||\
                                                             ((__VALUE__) == FL_GPIO_PINREMAP_FUNCTON1)||\
                                                             ((__VALUE__) == FL_GPIO_PINREMAP_FUNCTON2)||\
                                                             ((__VALUE__) == FL_GPIO_PINREMAP_FUNCTON3))
    
#define         IS_FL_GPIO_WKUP_ENTRY(__VALUE__)            (((__VALUE__) == FL_GPIO_WAKEUP_INT_ENTRY_NMI)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_INT_ENTRY_38))

#define         IS_FL_GPIO_WKUP_EDGE(__VALUE__)             (((__VALUE__) == FL_GPIO_WAKEUP_TRIGGER_RISING)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_TRIGGER_FALLING))


#define         IS_FL_GPIO_WKUP_NUM(__VALUE__)              (((__VALUE__) == FL_GPIO_WAKEUP_0)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_1)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_2)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_3)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_4)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_5)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_6)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_7))
/**
  * @}
  */

/** @addtogroup GPIO_FL_EF_Init
  * @{
  */

/**
  * @brief  复位GPIO外设
  * @param  GPIOx 外设入口地址
  * @param  pin 引脚
  * @retval 错误状态，可能值：
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_GPIO_DeInit(GPIO_Type *GPIOx, uint32_t pin)
{
    uint32_t pinPos     = 0x00000000U;
    uint32_t currentPin = 0x00000000U;
    /* 入口参数检查 */
    assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
    assert_param(IS_FL_GPIO_PIN(pin));
    /* 恢复寄存器值为默认值 */
    while(((pin) >> pinPos) != 0x00000000U)
    {
        /* 获取当前遍历到的Pin脚 */
        currentPin = (pin) & (0x00000001U << pinPos);
        if(currentPin)
        {
            FL_GPIO_SetPinMode(GPIOx, currentPin, FL_GPIO_MODE_INPUT);
            FL_GPIO_DisablePinInput(GPIOx, currentPin);
            FL_GPIO_DisablePinOpenDrain(GPIOx, currentPin);
            FL_GPIO_SetPinDriveStrength(GPIOx, currentPin, FL_GPIO_DRIVESTRENGTH_X3);
            FL_GPIO_DisablePinPullDown(GPIOx, currentPin);
            FL_GPIO_DisablePinPullUp(GPIOx, currentPin);
            FL_GPIO_SetPinRemap(GPIOx, currentPin, FL_GPIO_PINREMAP_FUNCTON0);
        }
        pinPos++;
    }
    return FL_PASS;
}


/* FM33FH0x5和FM33FH0x6有引脚复用，以下是相关处理机制 */
#if defined(FM33FH0x5) && defined(FM33FH0x6)
    #error "You cannot define two models at the same time!"

#elif defined (FM33FH0x5)   /* 仅针对48pin芯片处理 */
/**
* @brief  复用GPIO数据类型,单个元素为一组复用的GPIO
  */
static const struct MultiplexGpioType 
{
    /* 成员元素 */
    const struct 
    {
        GPIO_Type *GPIox;      /* 元素信息: GPIO的Port索引 */
        uint32_t   Pin;        /* 元素信息: GPIO的Pin索引  */
    } MultiplexGpioElement[2]; /* 一组复用关系，无先后顺序 */

} MultiplexGpioTable[] =       /* 复用GPIO的表格清单 */
{
    { {{GPIOA, (uint32_t)FL_GPIO_PIN_7 }/*PA7 */, {GPIOA, (uint32_t)FL_GPIO_PIN_8 }/*PA8 */} },/* 此为一组复用关系 */
    { {{GPIOA, (uint32_t)FL_GPIO_PIN_9 }/*PA9 */, {GPIOA, (uint32_t)FL_GPIO_PIN_12}/*PA12*/} },
    { {{GPIOA, (uint32_t)FL_GPIO_PIN_13}/*PA13*/, {GPIOA, (uint32_t)FL_GPIO_PIN_14}/*PA14*/} },
    { {{GPIOA, (uint32_t)FL_GPIO_PIN_15}/*PA15*/, {GPIOB, (uint32_t)FL_GPIO_PIN_0 }/*PB0 */} },
    { {{GPIOB, (uint32_t)FL_GPIO_PIN_7 }/*PB7 */, {GPIOB, (uint32_t)FL_GPIO_PIN_10}/*PB10*/} },
    { {{GPIOB, (uint32_t)FL_GPIO_PIN_11}/*PB11*/, {GPIOB, (uint32_t)FL_GPIO_PIN_14}/*PB14*/} },
    { {{GPIOC, (uint32_t)FL_GPIO_PIN_0 }/*PC0 */, {GPIOF, (uint32_t)FL_GPIO_PIN_13}/*PF13*/} },
    { {{GPIOC, (uint32_t)FL_GPIO_PIN_9 }/*PC9 */, {GPIOC, (uint32_t)FL_GPIO_PIN_13}/*PC13*/} },
    { {{GPIOE, (uint32_t)FL_GPIO_PIN_4 }/*PE4 */, {GPIOE, (uint32_t)FL_GPIO_PIN_6 }/*PE6 */} }, 
    { {{GPIOE, (uint32_t)FL_GPIO_PIN_7 }/*PE7 */, {GPIOE, (uint32_t)FL_GPIO_PIN_8 }/*PE8 */} },
    { {{GPIOG, (uint32_t)FL_GPIO_PIN_6 }/*PG6 */, {GPIOG, (uint32_t)FL_GPIO_PIN_10}/*PG10*/} }
};

#elif defined (FM33FH0x6)   /* 仅针对64pin芯片处理 */
/**
* @brief  复用GPIO数据类型,单个元素为一组复用的GPIO
  */
static const struct MultiplexGpioType 
{
    /* 成员元素 */
    const struct 
    {
        GPIO_Type *GPIox;      /* 元素信息: GPIO的Port索引 */
        uint32_t   Pin;        /* 元素信息: GPIO的Pin索引  */
    } MultiplexGpioElement[2]; /* 一组复用关系，无先后顺序 */
    
} MultiplexGpioTable[] =       /* 复用GPIO的表格清单 */
{
    { {{GPIOA, (uint32_t)FL_GPIO_PIN_7 }/*PA7 */, {GPIOA, (uint32_t)FL_GPIO_PIN_8 }/*PA8 */} },/* 此为一组复用关系 */
    { {{GPIOA, (uint32_t)FL_GPIO_PIN_9 }/*PA9 */, {GPIOA, (uint32_t)FL_GPIO_PIN_12}/*PA12*/} },
    { {{GPIOA, (uint32_t)FL_GPIO_PIN_13}/*PA13*/, {GPIOA, (uint32_t)FL_GPIO_PIN_14}/*PA14*/} },
    { {{GPIOA, (uint32_t)FL_GPIO_PIN_15}/*PA15*/, {GPIOB, (uint32_t)FL_GPIO_PIN_0 }/*PB0 */} },
    { {{GPIOB, (uint32_t)FL_GPIO_PIN_9 }/*PB9 */, {GPIOB, (uint32_t)FL_GPIO_PIN_10}/*PB10*/} },
    { {{GPIOB, (uint32_t)FL_GPIO_PIN_11}/*PB11*/, {GPIOB, (uint32_t)FL_GPIO_PIN_14}/*PB14*/} },
    { {{GPIOE, (uint32_t)FL_GPIO_PIN_5 }/*PE5 */, {GPIOE, (uint32_t)FL_GPIO_PIN_6 }/*PE6 */} },
    { {{GPIOE, (uint32_t)FL_GPIO_PIN_7 }/*PE7 */, {GPIOE, (uint32_t)FL_GPIO_PIN_8 }/*PE8 */} },
};
#endif /* defined (FM33FH0x6) */
    

#if defined (FM33FH0x5)|| defined(FM33FH0x6)
/**
* @brief  复用GPIO的组数
  */
static const uint32_t u32MultiplexGpioCount =\
    (uint32_t)((sizeof(MultiplexGpioTable)) / (sizeof(MultiplexGpioTable[0])));

/**
* @brief  针对复用GPIO，如有一个GPIO使用，则将另一个GPIO配置为高阻抗，避免相互影响
  * @param  GPIOx 当前使用的GPIO Port索引
  * @param  pin   当前使用的GPIO Pin索引
  * @retval 无
  */
static void FL_GPIO_Multiplex_DeInit(GPIO_Type *GPIOx, uint32_t pin)
{
    /* 指向复用GPIO表格的指针 */
    const struct MultiplexGpioType *pMultiplexGpio = MultiplexGpioTable;
    
    /* 入口参数检查 */
    assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
    assert_param(IS_FL_GPIO_PIN(pin));
    
    for( ; pMultiplexGpio < (MultiplexGpioTable + u32MultiplexGpioCount); pMultiplexGpio++)
    {
        if(   (pMultiplexGpio->MultiplexGpioElement[0].Pin   == pin)\
           && (pMultiplexGpio->MultiplexGpioElement[0].GPIox == GPIOx))
        {
            /* 未使用的GPIO执行高阻抗初始化 */
            FL_GPIO_DeInit(pMultiplexGpio->MultiplexGpioElement[1].GPIox,\
                           pMultiplexGpio->MultiplexGpioElement[1].Pin );
            break;            
        }
        else if(   (pMultiplexGpio->MultiplexGpioElement[1].Pin   == pin)\
                && (pMultiplexGpio->MultiplexGpioElement[1].GPIox == GPIOx))
        {
            /* 未使用的GPIO执行高阻抗初始化 */
            FL_GPIO_DeInit(pMultiplexGpio->MultiplexGpioElement[0].GPIox,\
                           pMultiplexGpio->MultiplexGpioElement[0].Pin );
            break;            
        }    
    }
}
#endif /* #if defined (FM33FH0x5)|| defined(FM33FH0x6) */

/**
  * @brief  根据 GPIO_InitStruct 的配置信息初始化对应外设.
  * @param  GPIOx GPIO Port
  * @param  GPIO_InitStruct 指向一个 @ref FL_GPIO_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @retval 错误状态，可能值：
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置成功
  */
FL_ErrorStatus FL_GPIO_Init(GPIO_Type *GPIOx, FL_GPIO_InitTypeDef *initStruct)
{
    uint32_t pinPos     = 0x00000000U;
    uint32_t currentPin = 0x00000000U;
    FL_ErrorStatus status = FL_FAIL;
    
    if(initStruct != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
        assert_param(IS_FL_GPIO_PIN(initStruct->pin));
        assert_param(IS_FL_GPIO_MODE(initStruct->mode));
        assert_param(IS_FL_GPIO_OPENDRAIN(initStruct->outputType));
        assert_param(IS_FL_GPIO_DRIVESTRENGTH(initStruct->driveStrength));
        assert_param(IS_FL_GPIO_PULL_UP(initStruct->pull));
        assert_param(IS_FL_GPIO_REMAPPIN(initStruct->remapPin));
        /* 使能时钟总线 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_PAD);
        /* 这里考虑到PIN有可能不止一个因此需要遍历 */
        while(((initStruct->pin) >> pinPos) != 0x00000000U)
        {
            /* 获取当前遍历到的Pin脚 */
            currentPin = (initStruct->pin) & (0x00000001U << pinPos);
            if(currentPin)
            {
                /* 仅针对48pin 和 64pin芯片处理 */ 
            #if defined (FM33FH0x5)|| defined(FM33FH0x6)
                /* 检查复用引脚，并做处理 */
                FL_GPIO_Multiplex_DeInit(GPIOx, currentPin);
            #endif /* #if defined (FM33FH0x5)|| defined(FM33FH0x6) */           
          
                /* Pin脚模拟模式设置 */
                if(initStruct->mode == FL_GPIO_MODE_ANALOG)
                {
                    FL_GPIO_DisablePinInput(GPIOx, currentPin);
                    FL_GPIO_DisablePinOpenDrain(GPIOx, currentPin);
                }
                else
                {
                    /* Pin脚输入使能控制 */
                    if(initStruct->mode == FL_GPIO_MODE_INPUT)
                    {
                        FL_GPIO_EnablePinInput(GPIOx, currentPin);
                    }
                    else
                    {
                        FL_GPIO_DisablePinInput(GPIOx, currentPin);
                    }
                    /* Pin脚输出模式设置 */
                    if(initStruct->outputType == FL_GPIO_OUTPUT_PUSHPULL)
                    {
                        FL_GPIO_DisablePinOpenDrain(GPIOx, currentPin);
                    }
                    else
                    {
                        FL_GPIO_EnablePinOpenDrain(GPIOx, currentPin);
                    }
                    /* 输出强度设置 */
                    FL_GPIO_SetPinDriveStrength(GPIOx, currentPin, initStruct->driveStrength);
                }
                /* Pin脚上拉/下拉模式设置 */
                if(initStruct->pull == FL_GPIO_PULLUP_ENABLE)
                {
                    FL_GPIO_DisablePinPullDown(GPIOx, currentPin);
                    FL_GPIO_EnablePinPullUp(GPIOx, currentPin);
                }
                else if(initStruct->pull == FL_GPIO_PULLDOWN_ENABLE)
                {
                    FL_GPIO_DisablePinPullUp(GPIOx, currentPin);
                    FL_GPIO_EnablePinPullDown(GPIOx, currentPin);
                }
                else
                {
                    FL_GPIO_DisablePinPullDown(GPIOx, currentPin);
                    FL_GPIO_DisablePinPullUp(GPIOx, currentPin);
                }
                /* 数字模式复用功能选择 */
                if(initStruct->mode == FL_GPIO_MODE_DIGITAL)
                {
                    /*重定向*/
                    FL_GPIO_SetPinRemap(GPIOx, currentPin, initStruct->remapPin);
                }
                /* Pin脚工作模式设置 */
                FL_GPIO_SetPinMode(GPIOx, currentPin, initStruct->mode);
            }
            pinPos++;
        }
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  将 @ref FL_GPIO_InitTypeDef 结构体初始化为默认配置
  * @param  initStruct 指向 @ref FL_GPIO_InitTypeDef 结构体的指针
  *
  * @retval None
  */
void FL_GPIO_StructInit(FL_GPIO_InitTypeDef *initStruct)
{
    /* 复位配置信息 */
    initStruct->pin           = FL_GPIO_PIN_ALL;
    initStruct->mode          = FL_GPIO_MODE_INPUT;
    initStruct->outputType    = FL_GPIO_OUTPUT_OPENDRAIN;
    initStruct->pull          = FL_GPIO_PULLUP_ENABLE;
    initStruct->remapPin      = FL_GPIO_PINREMAP_FUNCTON0;
    initStruct->driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
}

/**
  * @brief  根据 FL_WKUP_InitTypeDef 配置GPIO唤醒对应外设
  * @param  initStruct 指向一个 @ref FL_WKUP_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @param  wakeup 唤醒入口
  *         FL_GPIO_WAKEUP_0
  *         FL_GPIO_WAKEUP_1
  *         FL_GPIO_WAKEUP_2
  *         FL_GPIO_WAKEUP_3
  *         FL_GPIO_WAKEUP_4
  *         FL_GPIO_WAKEUP_5
  *         FL_GPIO_WAKEUP_6
  *         FL_GPIO_WAKEUP_7
  * @retval 错误状态，可能值：
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置成功
  */
FL_ErrorStatus FL_WKUP_Init(FL_WKUP_InitTypeDef *initStruct, uint32_t wakeup)
{
    FL_ErrorStatus status = FL_FAIL;
    if(initStruct != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FL_GPIO_WKUP_NUM(wakeup));
        assert_param(IS_FL_GPIO_WKUP_EDGE(initStruct->polarity));
        FL_GPIO_SetWakeupEdge(GPIO, wakeup, initStruct->polarity);
        FL_GPIO_EnableWakeup(GPIO, wakeup);
        status = FL_PASS;
    }
    
    return status;
}

/**
  * @brief  去初始化Wakeup配置
  * @param  Wkupx 唤醒入口
  *         FL_GPIO_WKUP_0
  *         FL_GPIO_WKUP_1
  *         FL_GPIO_WKUP_2
  *         FL_GPIO_WKUP_3
  *         FL_GPIO_WKUP_4
  *         FL_GPIO_WKUP_5
  *         FL_GPIO_WKUP_6
  *         FL_GPIO_WKUP_7
  * @retval 错误状态，可能值：
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置成功
  */
FL_ErrorStatus FL_WKUP_DeInit(uint32_t wkupx)
{
    /* 入口参数检查 */
    assert_param(IS_FL_GPIO_WKUP_NUM(wkupx));
    FL_GPIO_DisableWakeup(GPIO, wkupx);
    return FL_PASS;
}

/**
  * @brief  将 @ref FL_WKUP_InitTypeDef 结构体初始化为默认配置
  * @param  initStruct_Wakeup 指向需要将值设置为默认配置的结构体 @ref FL_WKUP_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_WKUP_StructInit(FL_WKUP_InitTypeDef *initStruct_Wakeup)
{
    if(initStruct_Wakeup != NULL)
    {
        /* 复位配置信息 */
        initStruct_Wakeup->polarity = FL_GPIO_WAKEUP_TRIGGER_FALLING;
    }
}

/**
  *@}
  */

/** @addtogroup RNG_FL_EF_Operation
  * @{
  */

/**
* @brief  设置所有GPIO为输入模式、输入使能关闭（高阻态），SWD接口和复位脚除外。
  * @note   PG8和PG9为调试接口
  *         PA0脚为复位引脚
  *
  * @param  None
  *
  * @retval None
  */
void FL_GPIO_ALLPIN_LPM_MODE(void)
{
    FL_GPIO_DeInit(GPIOA, FL_GPIO_PIN_ALL_EXCEPTRST);
    FL_GPIO_DeInit(GPIOB, FL_GPIO_PIN_ALL);
    FL_GPIO_DeInit(GPIOC, FL_GPIO_PIN_ALL);
    FL_GPIO_DeInit(GPIOD, FL_GPIO_PIN_ALL);
    FL_GPIO_DeInit(GPIOE, FL_GPIO_PIN_ALL);
    FL_GPIO_DeInit(GPIOF, FL_GPIO_PIN_ALL);
    FL_GPIO_DeInit(GPIOG, FL_GPIO_PIN_ALL_EXCEPTSWD);
}

/**
  * @}
  */

#endif /* FL_GPIO_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
