#include <string.h>

#ifndef TSI_SIM_DEV
    #include "fm33ht0xxa.h"
#else
    #include "fm33ht0xxa_sim.h"
#endif
#include "tsi_driver.h"
#include "tsi_object.h"

/* Macros -------------------------------------------------------------------*/
#define CAT(A, B, C)                A ## B ## C
#define DMA_REG(REG, ID)            CAT(DMA->CH, ID, REG)

#define TSI_IDAC_DIR_SOURCE         (0U)
#define TSI_IDAC_DIR_SINK           (1U)

/* Constants ----------------------------------------------------------------*/
/** GPIO port list. */
static GPIO_Type *const PORTS[] = {
    GPIOA, GPIOB, GPIOC, GPIOD,
    GPIOE, GPIOF, GPIOG, GPIOH,
};

/** Instance list. */
#define TSI_DEV_INSTANCE_NUM            (1U)
static TSI_Type *const INSTANCES[TSI_DEV_INSTANCE_NUM] = {
    TSI,
};

/* Defines ------------------------------------------------------------------*/
/** Sensor configuration struct. */
typedef struct _TSI_DevSnsConf {
    /** Sensor configuration reg value */
    uint32_t conf[TSI_MAX_SCANGROUP_SENSOR_NUM];

    /**
     * IDAC0 step.
     *
     * * 0 for 37.5nA,
     * * 1 for 75nA,
     * * 2 for 300nA,
     * * 3 for 600nA,
     * * 4 for 1.2uA,
     * * 5 for 2.4uA,
     * * 6 for 4.8uA.
     */
    uint8_t idac1Step[TSI_MAX_SCANGROUP_SENSOR_NUM];

    /**
     * IDAC1 step.
     *
     * * 0 for 37.5nA,
     * * 1 for 75nA,
     * * 2 for 300nA,
     * * 3 for 600nA,
     * * 4 for 1.2uA,
     * * 5 for 2.4uA,
     * * 6 for 4.8uA.
     */
    uint8_t idac2Step[TSI_MAX_SCANGROUP_SENSOR_NUM];

} TSI_DevSnsConfTypeDef;

/** Device driver private data struct. */
typedef struct _TSI_DevPrivate {
    /** Sensor configurations. */
    TSI_DevSnsConfTypeDef sensorConfs[TSI_TOTAL_SCAN_NUM];

    /**
     * In Blocking/IT mode: Current scanning sensor index(in scan group).
     * In DMA mode: Not used.
     */
    uint16_t snsIdx;

    /**
     * Available sensor num in current scan group.
     */
    uint16_t snsNum;

    /** LPM mode flag. */
    uint8_t isLPM;

    /** PLL enable status before entering LPM mode. */
    uint8_t isPLLEnabledBeforeLPM;

    /** Mark enabled sensor ids while scanning self-cap scan group. */
    uint16_t enabledSensors[TSI_MAX_SCANGROUP_SENSOR_NUM];

#if ((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U))
    /** Sensor data. */
    uint32_t sensorData[TSI_TOTAL_SCAN_NUM][TSI_MAX_SCANGROUP_SENSOR_NUM];
#endif

} TSI_DevPrivateTypeDef;

/* Private data -------------------------------------------------------------*/
#if (TSI_DEV_INSTANCE_NUM >= 2)
    #error "Configured instance number is not available on selected device."
#endif

/** Device driver private data instance(s). */
static TSI_DevPrivateTypeDef devPrivateData[TSI_DEV_INSTANCE_NUM];

/* Private function prototypes ----------------------------------------------*/
/* Control */
static void TSI_ResetModule(TSI_Type *instance);
static bool TSI_ConfigSensor(TSI_WidgetTypeDef *widget, TSI_SensorTypeDef *sensor,
                             TSI_DevSnsConfTypeDef *confs, uint16_t idx);
static void TSI_ConfigScanTiming(TSI_DriverTypeDef *drv, TSI_ScanGroupTypeDef *group);
static bool TSI_IsScanning(TSI_Type *instance);
static void TSI_DisableAllChannel(TSI_Type *instance);
static void TSI_EnableChannel(TSI_Type *instance, uint32_t ch);
static void TSI_SetChannelTx(TSI_Type *instance, uint32_t ch);
static void TSI_SetChannelRx(TSI_Type *instance, uint32_t ch);
static void TSI_SetIDAC1Step(TSI_Type *instance, uint8_t step);
static void TSI_SetIDAC2Step(TSI_Type *instance, uint8_t step);
#ifndef TSI_UNIT_TEST
    static void TSI_LoadIDAC1Trim(TSI_Type *instance, uint8_t step, uint8_t dir);
    static void TSI_LoadIDAC2Trim(TSI_Type *instance, uint8_t step, uint8_t dir);
#endif  /* TSI_UNIT_TEST */
static void TSI_EnableIT(TSI_Type *instance);
static void TSI_DisableIT(TSI_Type *instance);
#if ((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U))
    static void TSI_SetupDMA(TSI_Type *instance);
    static void TSI_ResetDMA(TSI_Type *instance);
#endif

/* Data r/w */
static uint32_t TSI_ReadData(TSI_Type *instance);
#ifdef TSI_LIB_USE_ASSERT
    static uint32_t TSI_GetTxChannel(uint32_t reg);
    static uint32_t TSI_GetRxChannel(uint32_t reg);
#endif
#if ((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U))
static void TSI_StartDMA(TSI_Type *instance, uint32_t *config, uint32_t *data,
                         uint16_t size);
static void TSI_StopDMA(TSI_Type *instance);
#endif

/* Miscs */
static void TSI_SetGroundOutput(TSI_DriverTypeDef *driver, TSI_SensorTypeDef *sensor);
static void TSI_ResetGroundOutput(TSI_DriverTypeDef *driver);

/* API implementations ------------------------------------------------------*/
TSI_RetCode TSI_Dev_Init(TSI_DriverTypeDef *drv)
{
    if(drv->instanceId == 0U) {
        uint16_t *pTrim;

        /* Reset TSI and enable bus clock */
        TSI_ResetModule(TSI);
        CMU->PCLKCR1 |= (0x1UL << 7U);
        CMU->PCLKCR2 |= (0x1UL << 11U);

        /* Disable channel pull-down */
        TSI->TEST &= ~(0x1UL << 18U);

        /* Disable CINTA/CINTB pull-up */
        GPIOA->INEN &= ~(0x3UL << 14U);
        GPIOA->PUDEN &= ~(0x3UL << 14U);

        /* Configure INTMUX */
        INTMUX->CR2 &= ~(0x3UL << 6U);
        INTMUX->CR2 |= (0x0UL << 6U);

        /* Setup reference voltage */
        TSI->VREFCR &= ~(0x3UL << 27U);
#if (TSI_DEV_REF_MV == 1500U)
        TSI->VREFCR |= (0x1UL << 27U);
#elif (TSI_DEV_REF_MV == 2000U)
        TSI->VREFCR |= (0x2UL << 27U);
#elif (TSI_DEV_REF_MV == 2500U)
        TSI->VREFCR |= (0x3UL << 27U);
#endif

#ifndef TSI_UNIT_TEST
        /* Load trim value */
        pTrim = (uint16_t *) 0x1FFFFA84UL;
        if(*pTrim != 0xFFFFU) {
            TSI_ASSERT(((*pTrim) ^ (*(pTrim + 2U))) == 0xFFFFU);
            TSI->VREFCR &= ~(0x7FUL << 0U);
            TSI->VREFCR |= (((*pTrim) & 0x7FU) << 0U);
        }
        pTrim = (uint16_t *) 0x1FFFFA88UL;
        if(*pTrim != 0xFFFFU) {
            TSI_ASSERT(((*pTrim) ^ (*(pTrim + 2U))) == 0xFFFFU);
            TSI->VREFCR &= ~(0x7FUL << 16U);
            TSI->VREFCR |= (((*pTrim) & 0x7FU) << 16U);
        }
        pTrim = (uint16_t *) 0x1FFFFA8CUL;
        if(*pTrim != 0xFFFFU) {
            TSI_ASSERT(((*pTrim) ^ (*(pTrim + 2U))) == 0xFFFFU);
            TSI->VREFCR &= ~(0x7FUL << 8U);
            TSI->VREFCR |= (((*pTrim) & 0x7FU) << 8U);
        }
#endif

        /* Enable NVIC */
        NVIC_DisableIRQ(MUX19_IRQn);
        NVIC_ClearPendingIRQ(MUX19_IRQn);
        NVIC_SetPriority(MUX19_IRQn, TSI_IRQ_PRIORITY);
        NVIC_EnableIRQ(MUX19_IRQn);

        /* Enable TSI */
        TSI->CFGR |= (0x1UL << 0U);

#if (TSI_USE_SHIELD == 1U)
        /* When using shield, pull-down must use GPIO GND output. */
        TSI->SHLDGNDCR0 = 0xFFFFFFFFUL;
        TSI->SHLDGNDCR1 = 0xFUL;
#endif

#if ((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U))
        /* Setup DMA */
        TSI_SetupDMA(TSI);
#if (TSI_DMA_IRQ_PRIORITY_BY_USER == 0U)
        NVIC_DisableIRQ(MUX21_IRQn);
        NVIC_SetPriority(MUX21_IRQn, TSI_DMA_IRQ_PRIORITY);
#endif
        NVIC_EnableIRQ(MUX21_IRQn);
#endif

#if (TSI_DEV_VDD_MV >= 4000U)
        /* FM515 U02 TSI compensation */
        RMU->PDRCR |= (0x3UL << 1U);
#endif

        /* Link driver */
        memset(&devPrivateData[0], 0, sizeof(TSI_DevPrivateTypeDef));
        drv->context = &devPrivateData[0];
    }

    return TSI_PASS;
}

TSI_RetCode TSI_Dev_Deinit(TSI_DriverTypeDef *drv)
{
    TSI_Type *instance;

    TSI_ASSERT(drv->instanceId < TSI_DEV_INSTANCE_NUM);
    instance = INSTANCES[drv->instanceId];

    /* Reset TSI and disable TSI bus clock */
    TSI_ResetModule(instance);

    /* Disable channel pull-down */
    TSI->TEST &= ~(0x1UL << 18U);

    /* Disable CINTA/CINTB pull-up */
    GPIOA->INEN &= ~(0x3UL << 14U);
    GPIOA->PUDEN &= ~(0x3UL << 14U);

#if ((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U))
    /* Reset DMA */
    TSI_ResetDMA(instance);
#endif

    /* Disable NVIC */
    NVIC_DisableIRQ(MUX19_IRQn);
    NVIC_ClearPendingIRQ(MUX19_IRQn);

    /* Disable TSI */
    TSI->CFGR &= ~(0x1UL << 0U);

    return TSI_PASS;
}

void TSI_Dev_EnterLPM(TSI_DriverTypeDef *drv)
{
    TSI_Type *instance;
    TSI_DevPrivateTypeDef *devPrivate = (TSI_DevPrivateTypeDef *) drv->context;

    TSI_ASSERT(drv->instanceId < TSI_DEV_INSTANCE_NUM);
    instance = INSTANCES[drv->instanceId];

    if(devPrivate->isLPM != 0U) {
        /* Already in LPM mode */
        return;
    }

    /* Disable TSI module */
    instance->CFGR &= ~(0x1UL);
    /* Store status and disable TSI_PLL */
    if((instance->PLLCR & (0x1UL << 0U)) != 0U) {
        devPrivate->isPLLEnabledBeforeLPM = 1U;
    }
    instance->PLLCR &= ~(0x1UL << 0U);

    /* Set LPM mode flag */
    devPrivate->isLPM = 1U;
}

void TSI_Dev_LeaveLPM(TSI_DriverTypeDef *drv)
{
    TSI_Type *instance;
    TSI_DevPrivateTypeDef *devPrivate = (TSI_DevPrivateTypeDef *) drv->context;

    TSI_ASSERT(drv->instanceId < TSI_DEV_INSTANCE_NUM);
    instance = INSTANCES[drv->instanceId];

    if(devPrivate->isLPM != 1U) {
        /* Already left LPM mode */
        return;
    }

    /* Enable TSI module */
    instance->CFGR |= 0x1UL;
    /* Restore TSI_PLL status */
    if(devPrivate->isPLLEnabledBeforeLPM != 0U) {
        instance->PLLCR |= (0x1UL << 0U);
    }

    /* Clear LPM mode flag */
    devPrivate->isLPM = 0U;
}

TSI_RetCode TSI_Dev_SetupClock(TSI_DriverTypeDef *drv, const TSI_ClockConfTypeDef *clockConf)
{
    TSI_Type *instance;

    TSI_ASSERT(drv->instanceId < TSI_DEV_INSTANCE_NUM);
    instance = INSTANCES[drv->instanceId];

    TSI_ASSERT((clockConf->snsClockSel == 0U) ||
               (clockConf->snsClockSel == 1U) ||
               (clockConf->snsClockSel == 2U));
    TSI_ASSERT((clockConf->sscWidth >= 6U && clockConf->sscWidth <= 13U));
    TSI_ASSERT((clockConf->prsWidth >= 6U && clockConf->prsWidth <= 13U));
    if(clockConf->sscWidth == 6U) {
        TSI_ASSERT((clockConf->sscPoint == 0U) ||
                   (clockConf->sscPoint == 1U));
    }
    else if(clockConf->sscWidth == 7U) {
        TSI_ASSERT((clockConf->sscPoint == 0U) ||
                   (clockConf->sscPoint == 1U) ||
                   (clockConf->sscPoint == 2U));
    }
    TSI_ASSERT((clockConf->pllRefPsc > 0U) && (clockConf->pllRefPsc <= 128U));
    TSI_ASSERT((clockConf->pllMul > 0U) && (clockConf->pllMul <= 80U));

    /* Select and enable operation clock */
    if(clockConf->opClockSel == 0U) {
        /* APBCLK as operation clock */
        CMU->OPCCR2 &= ~(0x1UL << 0U);
    }
    else {
        /* RCHF as operation clock */
        CMU->OPCCR2 |= (0x1UL << 0U);
    }
    CMU->OPCER1 |= (0x1UL << 16U);      /* Enable operation clock */

    /* Configure modulator clock */
    instance->CKCR &= ~(0xFFUL << 8U);
    instance->CKCR |= ((uint32_t)clockConf->modClockPsc - 1UL) << 8U;

    /* Select sensor clock source */
    if(clockConf->snsClockSrc == 0U) {
        /* Modulator clock */
        instance->CKCR &= ~(0x1UL << 0U);
        instance->PLLCR &= ~(0x1UL << 0U);   /* Disable TSI_PLL */
    }
    else {
        /* TSI_PLL VCO clock, need to configure TSI_PLL */
        instance->CKCR |= (0x1UL << 0U);
        instance->PLLCR &= ~(0x1UL << 0U);   /* Disable TSI_PLL */
        instance->PLLCR &= ~(0x7FUL << 1U);
        instance->PLLCR |= (((uint32_t)clockConf->pllRefPsc - 1UL) << 1U);   /* PLL prescaler */
        instance->PLLCR &= ~(0x3FFUL << 16U);
        instance->PLLCR |= (((uint32_t)clockConf->pllMul - 1UL) << 16U);     /* PLL multiplier */
        instance->PLLCR |= (0x1UL << 0U);    /* Enable TSI_PLL */
        /* Wait until TSI_PLL is locked */
        TSI_WAIT_TIMEOUT(((instance->PLLCR & (0x1UL << 8U)) != 0UL),
                         TSI_DEV_PLL_LOCK_TIMEOUT_VALUE) {
            return TSI_TIMEOUT;
        }
        TSI_WAIT_TIMEOUT_END()
    }

    /* Configure sensor clock selection */
    if(clockConf->snsClockSel == 0U) {
        /* Direct clock */
        instance->CKCR &= ~(0x1UL << 2U);    /* Disable divider SSC */
        instance->CCR &= ~(0x1UL << 0U);     /* Disable switch clock PRS */
    }
    else if(clockConf->snsClockSel == 1U) {
        /* PRS-modulated clock */
        instance->CKCR &= ~(0x1UL << 2U);    /* Disable divider SSC */
        instance->CCR &= ~(0x1UL << 0U);     /* Disable switch clock PRS */
        instance->PRSSW &= ~(0xFUL << 16U);
        instance->PRSSW |= ((uint32_t)clockConf->prsWidth << 16U);   /* PRS width */
        instance->PRSSW &= ~(0x1FFFUL << 0U);
        instance->PRSSW |= ((uint32_t)clockConf->prsCoeff << 0U);    /* PRS coefficient */
        instance->CCR |= (0x1UL << 0U);      /* Enable switch clock PRS */
    }
    else if(clockConf->snsClockSel == 2U) {
        /* SSC-modulated clock */
        instance->CKCR &= ~(0x1UL << 2U);    /* Disable divider SSC */
        instance->CCR &= ~(0x1UL << 0U);     /* Disable switch clock PRS */
        instance->CKCR &= ~(0x3UL << 4U);
        instance->CKCR |= ((uint32_t)clockConf->sscPoint << 4U);     /* SSC freq point num */
        instance->PRSSSC |= ((uint32_t)clockConf->sscWidth << 16U);  /* SSC width */
        instance->PRSSSC &= ~(0x1FFFUL << 0U);
        instance->PRSSSC |= ((uint32_t)clockConf->sscCoeff << 0U);   /* SSC coefficient */
        instance->CKCR |= (0x1UL << 2U);     /* Enable divider SSC */
    }

    return TSI_PASS;
}

TSI_RetCode TSI_Dev_ResetClock(TSI_DriverTypeDef *drv)
{
    TSI_Type *instance;

    TSI_ASSERT(drv->instanceId < TSI_DEV_INSTANCE_NUM);
    instance = INSTANCES[drv->instanceId];

    instance->CKCR &= ~(0x1UL << 2U);       /* Disable divider SSC */
    instance->CCR &= ~(0x1UL << 0U);        /* Disable switch clock PRS */
    instance->PLLCR &= ~(0x1UL << 0U);      /* Disable TSI_PLL */
    instance->CKCR &= ~(0xFFUL << 8U);      /* Modulator clock prescaler = 1 */
    instance->CKCR &= ~(0x1UL << 0U);       /* Modulator clock as sensor clock source */
    CMU->OPCCR2 &= ~(0x1UL << 0U);          /* APBCLK as operation clock */

    return TSI_PASS;
}

TSI_RetCode TSI_Dev_SetupPort(TSI_DriverTypeDef *drv, const TSI_IOConfTypeDef *io)
{
    GPIO_Type *port;
    uint32_t portId;
    uint32_t pin;

    TSI_UNUSED(drv)

    /* Get GPIO info */
    portId = io->port;
    pin = io->pin;
    TSI_ASSERT(portId < (sizeof(PORTS) / sizeof(GPIO_Type *)));
    port = PORTS[portId];

    /* Configure GPIO */
    port->FCR |= (0x3UL << (pin * 2U));     /* Analog mode */
    port->PUDEN &= ~(0x10001UL << pin);     /* Disable pull-up and pull down */

    return TSI_PASS;
}

TSI_RetCode TSI_Dev_ResetPort(TSI_DriverTypeDef *drv, const TSI_IOConfTypeDef *io)
{
    GPIO_Type *port;
    uint32_t portId;
    uint32_t pin;

    TSI_UNUSED(drv)

    /* Get GPIO info */
    portId = io->port;
    pin = io->pin;
    TSI_ASSERT(portId < (sizeof(PORTS) / sizeof(GPIO_Type *)));
    port = PORTS[portId];

    /* Set to high impedance */
    port->FCR &= ~(0x3UL << (pin * 2U));
    port->FCR |= (0x1UL << (pin * 2U));     /* Input mode */
    port->INEN &= ~(0x1UL << pin);          /* Disable input */
    port->PUDEN &= ~(0x10001UL << pin);     /* Disable pull-up and pull down */

    return TSI_PASS;
}

#if (TSI_USE_SHIELD == 1U)
TSI_RetCode TSI_Dev_SetupShield(TSI_DriverTypeDef *drv, const TSI_ShieldConfTypeDef *shield)
{
    TSI_Type *instance;
    uint8_t ch = shield->channel;

    TSI_ASSERT(drv->instanceId < TSI_DEV_INSTANCE_NUM);
    instance = INSTANCES[drv->instanceId];

    if(ch < 32U) {
        instance->SHLDCR0 |= (0x1UL << ch);
    }
    else {
        instance->SHLDCR1 |= (0x1UL << (ch - 32U));
    }

    return TSI_PASS;
}

TSI_RetCode TSI_Dev_ResetShield(TSI_DriverTypeDef *drv, const TSI_ShieldConfTypeDef *shield)
{
    TSI_Type *instance;
    uint8_t ch = shield->channel;

    TSI_ASSERT(drv->instanceId < TSI_DEV_INSTANCE_NUM);
    instance = INSTANCES[drv->instanceId];

    if(ch < 32U) {
        instance->SHLDCR0 &= ~(0x1UL << ch);
    }
    else {
        instance->SHLDCR1 &= ~(0x1UL << (ch - 32U));
    }

    return TSI_PASS;
}

TSI_RetCode TSI_Dev_ResetAllShields(TSI_DriverTypeDef *drv)
{
    TSI_Type *instance;
    TSI_ASSERT(drv->instanceId < TSI_DEV_INSTANCE_NUM);
    instance = INSTANCES[drv->instanceId];

    instance->SHLDCR0 = 0x0UL;
    instance->SHLDCR1 = 0x0UL;

    return TSI_PASS;
}

#endif  /* TSI_USE_SHIELD == 1U */

TSI_RetCode TSI_Dev_SetupScanGroup(TSI_DriverTypeDef *drv, TSI_ScanGroupTypeDef *group)
{
    bool res;
    TSI_Type *instance;
    TSI_DevPrivateTypeDef *devPrivate = (TSI_DevPrivateTypeDef *) drv->context;

    TSI_ASSERT(drv->instanceId < TSI_DEV_INSTANCE_NUM);
    instance = INSTANCES[drv->instanceId];

    /* Check scan stat */
    if(TSI_IsScanning(instance)) {
        /* Previous configured scan is running,
           user may call TSI_Dev_StopScan() to stop. */
        return TSI_WAIT;
    }

    /* Setup scan group sensors */
    if(group->type == TSI_SCAN_GROUP_SELF_CAP_PARALLEL) {
        /* Self-cap sensor parallel group: Only set the main sensor. */
        TSI_SensorTypeDef *sensor = TSI_SensorPointers[group->sensors[0]];
        TSI_WidgetTypeDef *widget = sensor->meta->parent;
        res = TSI_ConfigSensor(widget, sensor, devPrivate->sensorConfs, 0U);
        if(!res) {
            return TSI_ERROR;
        }
        /* sensor num is always 1 */
        devPrivate->snsNum = 1U;
    }
    else if(group->type == TSI_SCAN_GROUP_SELF_CAP) {
        uint16_t snsScanIdx = 0U;   /* For addressing self-cap conf index and counting
                                       enabled sensor num */
        TSI_FOREACH_OBJ(uint16_t *, snsId, group->sensors, group->size) {
            TSI_SensorTypeDef *sensor = TSI_SensorPointers[*snsId];
            TSI_WidgetTypeDef *widget = sensor->meta->parent;
            if(widget->enable != 0U) {
                res = TSI_ConfigSensor(widget, sensor, devPrivate->sensorConfs,
                                       snsScanIdx);
                if(!res) {
                    return TSI_ERROR;
                }
                devPrivate->enabledSensors[snsScanIdx] = *snsId;
                snsScanIdx++;
            }
        }
        TSI_FOREACH_END()
        devPrivate->snsNum = snsScanIdx;
    }
    else if(group->type == TSI_SCAN_GROUP_MUTUAL_CAP) {
        TSI_FOREACH_OBJ(uint16_t *, snsId, group->sensors, group->size) {
            TSI_SensorTypeDef *sensor = TSI_SensorPointers[*snsId];
            TSI_WidgetTypeDef *widget = sensor->meta->parent;
            res = TSI_ConfigSensor(widget, sensor, devPrivate->sensorConfs,
                                   (uint16_t)idx);
            if(!res) {
                return TSI_ERROR;
            }
        }
        TSI_FOREACH_END()
        /* sensor num is always equals to group size */
        devPrivate->snsNum = group->size;
    }

    /* Setup scan timing */
    TSI_ConfigScanTiming(drv, group);

    return TSI_PASS;
}

TSI_RetCode TSI_Dev_StartScan(TSI_DriverTypeDef *drv)
{
    TSI_Type *instance;
    TSI_DevPrivateTypeDef *devPrivate = (TSI_DevPrivateTypeDef *) drv->context;
    const TSI_ScanGroupTypeDef *group = &drv->scanGroups[drv->scanGroupIdx];
    TSI_DevSnsConfTypeDef *snsConf;
    uint8_t idac2Dir;

    TSI_ASSERT(drv->instanceId < TSI_DEV_INSTANCE_NUM);
    instance = INSTANCES[drv->instanceId];

    /* Enable sensors */
    TSI_DisableAllChannel(instance);
    TSI_FOREACH_OBJ(uint16_t *, snsId, group->sensors, group->size) {
        const TSI_SensorTypeDef *sensor = TSI_SensorPointers[*snsId];
        TSI_WidgetTypeDef *widget = sensor->meta->parent;
        if(group->type != TSI_SCAN_GROUP_SELF_CAP_PARALLEL) {
            if(widget->enable == 0U) {
                continue;
            }
        }
        else if(idx == 0UL && widget->enable == 0U) {
            /* Self-cap parallel group: Only configure the first sensor. */
            break;
        }
        TSI_EnableChannel(instance, sensor->meta->rxChannel);
        TSI_INFO("TSI_Dev_StartScan - Enable CH%02d", sensor->meta->rxChannel);
        if(TSI_WIDGET_IS_MUTUAL_CAP(widget)) {
            TSI_SetChannelRx(instance, sensor->meta->rxChannel);
            TSI_INFO("TSI_Dev_StartScan - Set as RX");
            TSI_EnableChannel(instance, sensor->meta->txChannel);
            TSI_SetChannelTx(instance, sensor->meta->txChannel);
            TSI_INFO("TSI_Dev_StartScan - Enable CH%02d", sensor->meta->txChannel);
            TSI_INFO("TSI_Dev_StartScan - Set as TX");
        }
    }
    TSI_FOREACH_END()

    if(group->type == TSI_SCAN_GROUP_SELF_CAP ||
            group->type == TSI_SCAN_GROUP_SELF_CAP_PARALLEL) {
        /* Self-cap sensor */
        /* IDAC1 mode = 1, IDAC2 mode = 1 */
        instance->ANACR |= (0x1UL << 16U);
        instance->ANACR |= (0x1UL << 17U);
        idac2Dir = TSI_IDAC_DIR_SOURCE;

#if (TSI_USE_SHIELD == 1U)
        /* Enable shield output */
        instance->ANACR &= ~(0x3UL << 8U);
        instance->ANACR |= (0x1UL << 8U);
        instance->TEST &= ~(0x1UL << 19U);
        instance->CFGR &= ~(0x1UL << 4U);
#endif
    }
    else if(group->type == TSI_SCAN_GROUP_MUTUAL_CAP) {
        /* Mutual-cap sensor */
        /* IDAC1 mode = 1, IDAC2 mode = 0 */
        instance->ANACR |= (0x1UL << 16U);
        instance->ANACR &= ~(0x1UL << 17U);
        idac2Dir = TSI_IDAC_DIR_SINK;
    }
    else {
        /* Cannot be here */
        TSI_ASSERT(0U);
        return TSI_PARAM_ERR;
    }

    if(drv->scanMode != TSI_DRV_SCAN_MODE_DMA) {
        /* Reset sensor index */
        devPrivate->snsIdx = 0U;

        /* Setup configuration for first sensor */
        snsConf = &devPrivate->sensorConfs[drv->freqIdx];
        instance->SPCFGR = snsConf->conf[0];
#ifndef TSI_UNIT_TEST
        TSI_LoadIDAC1Trim(instance, snsConf->idac1Step[0], TSI_IDAC_DIR_SOURCE);
        TSI_LoadIDAC2Trim(instance, snsConf->idac2Step[0], idac2Dir);
#endif  /* TSI_UNIT_TEST */
        TSI_SetIDAC1Step(instance, snsConf->idac1Step[0]);
        TSI_SetIDAC2Step(instance, snsConf->idac2Step[0]);
    }
#if ((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U))
    else {
        /* When using DMA, sensors in one scan group must use
           same IDAC step. We use IDAC step of the first sensor. */
        snsConf = &devPrivate->sensorConfs[drv->freqIdx];
#ifndef TSI_UNIT_TEST
        TSI_LoadIDAC1Trim(instance, snsConf->idac1Step[0], TSI_IDAC_DIR_SOURCE);
        TSI_LoadIDAC2Trim(instance, snsConf->idac2Step[0], idac2Dir);
#endif  /* TSI_UNIT_TEST */
        TSI_SetIDAC1Step(instance, snsConf->idac1Step[0]);
        TSI_SetIDAC2Step(instance, snsConf->idac2Step[0]);
    }
#endif

    if((group->opt & TSI_DEV_OPT_IDLE_CONNECTION_MASK) == TSI_DEV_OPT_IDLE_GROUNDED) {
        TSI_SensorTypeDef *sensor = NULL;
        if(group->type == TSI_SCAN_GROUP_SELF_CAP) {
            sensor = drv->sensors[devPrivate->enabledSensors[0]];
        }
        else if(group->type == TSI_SCAN_GROUP_MUTUAL_CAP) {
            sensor = drv->sensors[group->sensors[0]];
        }
        else {
            /* Do nothing */
        }
        if(sensor != NULL) {
            /* Set other channel output to GND */
            TSI_SetGroundOutput(drv, sensor);
        }
    }
#if (TSI_USE_SHIELD == 1U)
    else if(((group->opt & TSI_DEV_OPT_IDLE_CONNECTION_MASK) == TSI_DEV_OPT_IDLE_SHIELD) &&
            (group->type == TSI_SCAN_GROUP_SELF_CAP || group->type == TSI_SCAN_GROUP_SELF_CAP_PARALLEL)) {
        /* Connect idle channel to shield */
        instance->TEST |= (0x1UL << 19U);
        instance->CFGR |= (0x1UL << 4U);
    }
#endif

    /* Setup scan configurations */
    instance->CFGR &= ~(0xFUL << 28U);          /* No multi sample */
    instance->CFGR &= ~(0x3UL << 22U);          /* Scan mode */
    switch(group->type) {
        case TSI_SCAN_GROUP_SELF_CAP:
            instance->CFGR |= (0x1UL << 22U);
            break;
        case TSI_SCAN_GROUP_SELF_CAP_PARALLEL:
            instance->CFGR |= (0x0UL << 22U);
            break;
        case TSI_SCAN_GROUP_MUTUAL_CAP:
            instance->CFGR |= (0x2UL << 22U);
            break;
        default:
            return TSI_PARAM_ERR;
    }
    instance->CFGR |= (0x1UL << 20U);           /* Enable wait */
    instance->CFGR &= ~(0x1UL << 7U);           /* Disable hw average */
    instance->CFGR &= ~(0x1UL << 5U);           /* Software trigged */

    /* Enable interrupts / DMA */
    if(drv->scanMode == TSI_DRV_SCAN_MODE_BLOCKING ||
            drv->scanMode == TSI_DRV_SCAN_MODE_IT) {
#if ((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U))
        TSI_StopDMA(instance);
#endif
        TSI_EnableIT(instance);
    }
#if ((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U))
    else if(drv->scanMode == TSI_DRV_SCAN_MODE_DMA) {
        TSI_DisableIT(instance);
        TSI_StartDMA(instance,
                     snsConf->conf,
                     devPrivate->sensorData[drv->freqIdx],
                     devPrivate->snsNum);
        TSI_INFO("TSI_Dev_SetupScanGroup() - Start DMA with "
                 "TxAddr 0x%08X, RxAddr 0x%08X, size %d",
                 (uint32_t)snsConf->conf,
                 (uint32_t)devPrivate->sensorData[drv->freqIdx],
                 devPrivate->snsNum);
    }
#endif

    /* Start scan */
    instance->CR |= (0x1UL << 0U);

    return TSI_PASS;
}

TSI_RetCode TSI_Dev_StopScan(TSI_DriverTypeDef *drv)
{
    TSI_Type *instance = INSTANCES[drv->instanceId];

    /* Stop scan */
    instance->CR |= (0x1UL << 2U);

    /* Disable interrupts / DMA */
    if(drv->scanMode == TSI_DRV_SCAN_MODE_BLOCKING ||
            drv->scanMode == TSI_DRV_SCAN_MODE_IT) {
        TSI_DisableIT(instance);
    }
#if ((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U))
    else if(drv->scanMode == TSI_DRV_SCAN_MODE_DMA) {
        TSI_StopDMA(instance);
    }
#endif

    return TSI_PASS;
}

void TSI_Dev_Handler(TSI_DriverTypeDef *drv)
{
    TSI_Type *instance = INSTANCES[drv->instanceId];
    TSI_DevPrivateTypeDef *devPrivate = (TSI_DevPrivateTypeDef *) drv->context;
    const TSI_ScanGroupTypeDef *group = &drv->scanGroups[drv->scanGroupIdx];
    TSI_DevSnsConfTypeDef *snsConf;

    /*-----------------------------------*/
    /* TSI interrupts                    */
    /*-----------------------------------*/
    if((instance->IER & (0x1UL << 1U)) != 0UL &&
            (instance->ISR & (0x1UL << 1U)) != 0UL) {
        instance->ISR = (0x1UL << 1U);
        if(drv->scanMode != TSI_DRV_SCAN_MODE_DMA) {
            /* Save data to sensor struct */
            uint16_t snsIdx = devPrivate->snsIdx;
            uint16_t rawCount;
            TSI_SensorTypeDef *sensor;

            if(snsIdx >= group->size) {
                /* Error: Stop scan and return. */
                (void)TSI_Drv_StopScan(drv);
                TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_ERROR);
                return;
            }

            if(group->type == TSI_SCAN_GROUP_SELF_CAP) {
                sensor = drv->sensors[devPrivate->enabledSensors[snsIdx]];
            }
            else if(group->type == TSI_SCAN_GROUP_SELF_CAP_PARALLEL) {
                if(snsIdx >= 1U) {
                    /* Error: Stop scan and return. */
                    (void)TSI_Drv_StopScan(drv);
                    TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_ERROR);
                    return;
                }
                sensor = drv->sensors[group->sensors[snsIdx]];
            }
            else if(group->type == TSI_SCAN_GROUP_MUTUAL_CAP) {
                sensor = drv->sensors[group->sensors[snsIdx]];
            }
            else {
                /* Cannot be here */
                TSI_ASSERT(0U);
                return;
            }

#ifdef TSI_LIB_USE_ASSERT
            /* Check sensor TX and RX channel */
            TSI_ASSERT(sensor->meta->rxChannel == TSI_GetRxChannel(instance->RAWCNTR));
            if(group->type == TSI_SCAN_GROUP_MUTUAL_CAP) {
                TSI_ASSERT(sensor->meta->txChannel == TSI_GetTxChannel(instance->RAWCNTR));
            }
#endif
            TSI_INFO("IRQ: EOC ------------");
            rawCount = (uint16_t)(TSI_ReadData(instance) & 0xFFFFUL);
            TSI_Drv_HandleSensorData(drv, sensor, rawCount);

            /*
                - Self-cap scan group: Goto next sensor.
                - Self-cap parallel scan group: skip.
                - Mutual-cap scan group: Goto next sensor.
            */
            if(group->type == TSI_SCAN_GROUP_SELF_CAP_PARALLEL) {
                devPrivate->snsIdx = snsIdx + 1U;
                return;
            }
            if(++snsIdx < devPrivate->snsNum) {
                /* Setup next configuration */
                snsConf = &devPrivate->sensorConfs[drv->freqIdx];
                instance->SPCFGR = snsConf->conf[snsIdx];
                TSI_SetIDAC1Step(instance, snsConf->idac1Step[snsIdx]);
                TSI_SetIDAC2Step(instance, snsConf->idac2Step[snsIdx]);
#ifndef TSI_UNIT_TEST
                if(group->type == TSI_SCAN_GROUP_SELF_CAP) {
                    TSI_LoadIDAC1Trim(instance, snsConf->idac1Step[snsIdx], TSI_IDAC_DIR_SOURCE);
                    TSI_LoadIDAC2Trim(instance, snsConf->idac2Step[snsIdx], TSI_IDAC_DIR_SOURCE);
                }
                else if(group->type == TSI_SCAN_GROUP_MUTUAL_CAP) {
                    TSI_LoadIDAC1Trim(instance, snsConf->idac1Step[snsIdx], TSI_IDAC_DIR_SOURCE);
                    TSI_LoadIDAC2Trim(instance, snsConf->idac2Step[snsIdx], TSI_IDAC_DIR_SINK);
                }
                else {
                    /* Cannot be here */
                    TSI_ASSERT(0U);
                }
#endif  /* TSI_UNIT_TEST */

                /* Setup scan group options */
                if((group->opt & TSI_DEV_OPT_IDLE_CONNECTION_MASK) == TSI_DEV_OPT_IDLE_GROUNDED) {
                    TSI_SensorTypeDef *sensor = NULL;
                    if(group->type == TSI_SCAN_GROUP_SELF_CAP) {
                        sensor = drv->sensors[devPrivate->enabledSensors[snsIdx]];
                    }
                    else if(group->type == TSI_SCAN_GROUP_MUTUAL_CAP) {
                        sensor = drv->sensors[group->sensors[snsIdx]];
                    }
                    else {
                        /* Do nothing */
                    }
                    if(sensor != NULL) {
                        /* Set other channel output to GND */
                        TSI_SetGroundOutput(drv, sensor);
                    }
                }

                /* Continue */
                instance->CR |= (0x1UL << 1U);
            }
            /* Update variable value */
            devPrivate->snsIdx = snsIdx;
            TSI_INFO("---------------------");
        }
    }
    else if((instance->IER & (0x1UL << 2U)) != 0UL &&
            (instance->ISR & (0x1UL << 2U)) != 0UL) {
        TSI_INFO("IRQ: EOS ------------");
        instance->ISR = (0x1UL << 2U);
        if(devPrivate->snsIdx < devPrivate->snsNum)  {
            /* Something is error. */
            (void)TSI_Drv_StopScan(drv);
            TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_ERROR);
            return;
        }

        if((group->opt & TSI_DEV_OPT_IDLE_CONNECTION_MASK) == TSI_DEV_OPT_IDLE_GROUNDED) {
            /* Restore all port to default */
            TSI_ResetGroundOutput(drv);
        }

        /* Notify scan completed */
        TSI_Drv_HandleEndOfScan(drv);
        TSI_INFO("---------------------");
    }

#if ((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U))
    /*-----------------------------------*/
    /* DMA interrupts                    */
    /*-----------------------------------*/
    if((DMA_REG(CFGR, TSI_DMA_RD_CHANNEL) & (0x1UL << 2U)) != 0UL &&
            (DMA->ISR & (0x1UL << (8U + TSI_DMA_RD_CHANNEL))) != 0UL) {
        uint16_t snsRealIdx = 0U;   /* for resolving self-cap data index. */
        uint32_t *snsData = devPrivate->sensorData[drv->freqIdx];

        TSI_INFO("IRQ: DMA EOS --------");
        /* Stop DMA and clear flags */
        TSI_StopDMA(instance);

        /* Save data to sensor struct */
        TSI_FOREACH_IDX(uint16_t snsIdx, group->sensors, group->size, 0U) {
            /*
                - Self-cap scan group: scan data will skip disabled sensor.
                - Self-cap parallel scan group: do not care.
                - Mutual-cap scan group: do not care.
            */
            TSI_SensorTypeDef *sensor = drv->sensors[snsIdx];
            if(group->type == TSI_SCAN_GROUP_SELF_CAP) {
                TSI_WidgetTypeDef *widget = sensor->meta->parent;
                if(widget->enable == 0U) { continue; }
            }
#ifdef TSI_LIB_USE_ASSERT
            /* Check sensor TX and RX channel */
            TSI_ASSERT(sensor->meta->rxChannel == TSI_GetRxChannel(snsData[snsRealIdx]));
            if(group->type == TSI_SCAN_GROUP_MUTUAL_CAP) {
                TSI_ASSERT(sensor->meta->txChannel == TSI_GetTxChannel(snsData[snsRealIdx]));
            }
#endif
            TSI_Drv_HandleSensorData(drv, sensor, snsData[snsRealIdx] & 0xFFFFUL);
            snsRealIdx++;
            TSI_DEBUG("sensor(%s #%d, Tx%02d Rx%02d): %5d",
                      (sensor->meta->type == TSI_SENSOR_SELF_CAP) ? "Self" : "Mutual",
                      drv->freqIdx,
                      sensor->meta->txChannel, sensor->meta->rxChannel,
                      sensor->bslnVar.sensorBuffer[drv->freqIdx]);
        }
        TSI_FOREACH_END()

        /* Notify scan completed */
        TSI_Drv_HandleEndOfScan(drv);
        TSI_INFO("---------------------");
    }
#endif
}

uint32_t TSI_Dev_GetModClock(TSI_ClockConfTypeDef *clockConf)
{
    uint32_t tmpClock = TSI_DEV_OP_CLOCK_FREQ;
    tmpClock /= clockConf->modClockPsc;
    return tmpClock;
}

uint32_t TSI_Dev_GetSCSnsInputClock(TSI_ClockConfTypeDef *clockConf)
{
    uint32_t tmpClock;
    if(clockConf->snsClockSrc == 0U) {
        /* Modulator clock */
        tmpClock = TSI_Dev_GetModClock(clockConf);
    }
    else if(clockConf->snsClockSrc == 1U) {
        /* TSI_PLL VCO clock */
        tmpClock = (uint32_t)clockConf->pllMul * 2000000UL;
    }
    else {
        TSI_ASSERT(0U);
        tmpClock = TSI_DATA_INVALID;
    }
    return (tmpClock / 2U);
}

uint32_t TSI_Dev_GetMCSnsInputClock(TSI_ClockConfTypeDef *clockConf)
{
    uint32_t tmpClock;
    if(clockConf->snsClockSrc == 0U) {
        /* Modulator clock */
        tmpClock = TSI_Dev_GetModClock(clockConf);
    }
    else if(clockConf->snsClockSrc == 1U) {
        /* TSI_PLL VCO clock */
        tmpClock = (uint32_t)clockConf->pllMul * 2000000UL;
    }
    else {
        TSI_ASSERT(0U);
        tmpClock = TSI_DATA_INVALID;
    }
    return tmpClock;
}

uint32_t TSI_Dev_GetSCSwitchClock(TSI_ClockConfTypeDef *clockConf, uint32_t snsDiv)
{
    uint32_t tmpClock = TSI_Dev_GetSCSnsInputClock(clockConf);
    if(tmpClock == TSI_DATA_INVALID) {
        return tmpClock;
    }
    if(clockConf->snsClockSel == 0U || clockConf->snsClockSel == 2U) {
        /* Direct clock / SSC clock */
        tmpClock /= snsDiv;
    }
    else if(clockConf->snsClockSel == 1U) {
        /* PRS clock */
        tmpClock /= (snsDiv * 2U);
    }
    else {
        TSI_ASSERT(0U);
        tmpClock = TSI_DATA_INVALID;
    }
    return tmpClock;
}

uint32_t TSI_Dev_GetMCTXClock(TSI_ClockConfTypeDef *clockConf, uint32_t snsDiv)
{
    uint32_t tmpClock = TSI_Dev_GetMCSnsInputClock(clockConf);
    return (tmpClock / snsDiv);
}

void TSI_Dev_SetupDirectClock(TSI_ClockConfTypeDef *clockConf)
{
    clockConf->snsClockSel = 0U;
}

void TSI_Dev_SetupPRSClock(TSI_ClockConfTypeDef *clockConf, uint8_t width, uint16_t coeff)
{
    clockConf->snsClockSel = 1U;
    clockConf->prsWidth = width;
    clockConf->prsCoeff = coeff;
}

void TSI_Dev_SetupSSCClock(TSI_ClockConfTypeDef *clockConf, uint8_t width, uint8_t point, uint16_t coeff)
{
    clockConf->snsClockSel = 2U;
    clockConf->sscWidth = width;
    clockConf->sscPoint = point;
    clockConf->sscCoeff = coeff;
}

uint32_t TSI_Dev_GetSCConvCycleNum(uint32_t resolution)
{
    return (uint32_t)((1UL << resolution) - 1UL);
}

uint32_t TSI_Dev_GetMCConvCycleNum(TSI_ClockConfTypeDef *clockConf, uint32_t resolution, uint32_t snsDiv)
{
    TSI_UNUSED(clockConf)
    TSI_UNUSED(snsDiv)
    return (uint32_t)((1UL << resolution) - 1UL);
}

void TSI_Dev_ClearWDT(void)
{
#if (TSI_SYS_IWDT_USED == 1U)
    /* Clear IWDT */
    IWDT->SERV = 0x12345A5AUL;
#endif
#if (TSI_SYS_WWDT_USED == 1U)
    /* Clear WWDT */
    if((WWDT->CNT & 0x3FFUL) > 512UL) {
        WWDT->CR = 0xACUL;
    }
#endif
}

/* Private function implemenations ------------------------------------------*/
static void TSI_ResetModule(TSI_Type *instance)
{
    if(instance == TSI) {
        RMU->PRSTEN = 0x13579BDFUL;             /* Reset */
        RMU->APBRSTCR1 |= (0x1UL << 5U);
        RMU->APBRSTCR1 &= ~(0x1UL << 5U);
        RMU->PRSTEN = 0x0UL;
        CMU->PCLKCR2 &= ~(0x1UL << 11U);        /* Disable bus clock */
        CMU->OPCER1 &= ~(0x1UL << 16U);         /* Disable operation clock */
    }
}

static bool TSI_ConfigSensor(TSI_WidgetTypeDef *widget, TSI_SensorTypeDef *sensor,
                             TSI_DevSnsConfTypeDef *confs, uint16_t idx)
{
    if(TSI_WIDGET_IS_SELF_CAP(widget)) {
        /* Self-cap widget */
        TSI_SelfCapWidgetTypeDef *scWidget = (TSI_SelfCapWidgetTypeDef *) widget;
        uint8_t freq;

        TSI_ASSERT(scWidget->swClkDiv > 0U && scWidget->swClkDiv <= 0xFFFU);
        TSI_ASSERT(scWidget->idacMod <= 0x7FU);
        TSI_ASSERT(scWidget->resolution >= 8U && scWidget->resolution <= 16U);
        TSI_ASSERT(scWidget->idacStep <= 6U);
#if (TSI_WIDGET_SC_TOUCHPAD_USED == 1U)
        if(widget->meta->type == TSI_WIDGET_SELF_CAP_TOUCHPAD &&
                sensor->meta->type == TSI_SENSOR_SELF_CAP_ROW) {
            TSI_ASSERT(((TSI_SelfCapTouchpadTypeDef *)scWidget)->idacModRow <= 0x7FU);
        }
#endif
#if (TSI_SC_USE_UNIFIED_IDAC_STEP == 0U)
        TSI_ASSERT(scWidget->idacCompStep <= 6U);
#endif

        for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
            uint32_t *pConf = &(confs[freq].conf[idx]);

            TSI_ASSERT(sensor->idac[freq] <= 0x7FU);

            /* Sensor configuration */
            (*pConf) = 0U;
            (*pConf) |= (((uint32_t)scWidget->swClkDiv - 1U) << 20U);
            (*pConf) |= (((uint32_t)scWidget->resolution - 8U) << 16U);
#if (TSI_WIDGET_SC_TOUCHPAD_USED == 1U)
            if(widget->meta->type == TSI_WIDGET_SELF_CAP_TOUCHPAD &&
                    sensor->meta->type == TSI_SENSOR_SELF_CAP_ROW) {
                (*pConf) |= (uint32_t)((TSI_SelfCapTouchpadTypeDef *)scWidget)->idacModRow[freq];
            }
            else
#endif
            {
                (*pConf) |= ((uint32_t)scWidget->idacMod[freq] << 0U);
            }
            if(sensor->idac[freq] != 0U) {
                (*pConf) |= ((uint32_t)sensor->idac[freq] << 8U);
                (*pConf) |= (0x1UL << 15U); /* Enable Compensation IDAC */
            }
            confs[freq].idac1Step[idx] = scWidget->idacStep;
#if (TSI_SC_USE_UNIFIED_IDAC_STEP == 1U)
            confs[freq].idac2Step[idx] = scWidget->idacStep;
#else
            confs[freq].idac2Step[idx] = scWidget->idacCompStep;
#endif
        }
    }
    else if(TSI_WIDGET_IS_MUTUAL_CAP(widget)) {
        /* Mutual-cap widget */
        TSI_MutualCapWidgetTypeDef *mcWidget = (TSI_MutualCapWidgetTypeDef *) widget;
        uint8_t freq;

        /* Assertions */
        TSI_ASSERT(mcWidget->txClkDiv <= 0xFFFU);
        TSI_ASSERT(mcWidget->resolution >= 8U && mcWidget->resolution <= 16U);
        TSI_ASSERT(mcWidget->idacStep <= 6U);

        for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
            uint32_t *pConf = &(confs[freq].conf[idx]);

            /* Assertions */
            TSI_ASSERT(sensor->idac[freq] <= 0x7FU);

            /* Sensor configuration */
            (*pConf) = 0U;
            (*pConf) |= (((uint32_t)mcWidget->txClkDiv - 1U) << 20U);
            (*pConf) |= (((uint32_t)mcWidget->resolution - 8U) << 16U);
            (*pConf) |= ((uint32_t)sensor->idac[freq] << 0U);
            (*pConf) |= ((uint32_t)sensor->idac[freq] << 8U);
            (*pConf) |= (0x1UL << 15U); /* Dual IDAC mode */
            confs[freq].idac1Step[idx] = mcWidget->idacStep;
            confs[freq].idac2Step[idx] = mcWidget->idacStep;
        }
    }
    else {
        /* Cannot be here */
        return false;
    }

    return true;
}

static bool TSI_IsScanning(TSI_Type *instance)
{
    if(instance->CR & (0x1UL << 0U)) {
        return true;
    }
    else {
        return false;
    }
}

static void TSI_ConfigScanTiming(TSI_DriverTypeDef *drv, TSI_ScanGroupTypeDef *group)
{
    uint64_t pclkFreq = TSI_DEV_BUS_CLOCK_FREQ;
    uint32_t tmpCnt;
    TSI_Type *instance;

    TSI_UNUSED(group)

    TSI_ASSERT(drv->instanceId < TSI_DEV_INSTANCE_NUM);
    instance = INSTANCES[drv->instanceId];

    /*
        SCAN_ZERO: Useless, set to default value(0).
        SCAN_IDLE: Recommended >= 80us. N = (8 * pclkFreq) / 3200000.
        SCAN_INTV: Recommended >= 10us. N = (10 * pclkFreq) / 32000000.
        SMPL_WAIT: Internal comparator needs setup time. Recommended >= 4.
    */
    instance->CCR &= ~(0x7FFFFF0EUL);
    /* SCAN_IDLE --------------------*/
    tmpCnt = (uint32_t)(pclkFreq * 8UL / 3200000UL);
    if(tmpCnt > 0x0UL) { tmpCnt -= 0x1UL; }
    if(tmpCnt >= 0x7FUL) { tmpCnt = 0x7FUL; }
    instance->CCR |= (tmpCnt << 16U);
    /* SCAN_INTV --------------------*/
    tmpCnt = (uint32_t)(pclkFreq * 10UL / 32000000UL);
    if(tmpCnt > 0x0UL) { tmpCnt -= 0x1UL; }
    if(tmpCnt >= 0xFFUL) { tmpCnt = 0xFFUL; }
    instance->CCR |= (tmpCnt << 8U);
    /* SMPL_WAIT --------------------*/
    instance->CCR |= (0x4UL << 1U);
}

static void TSI_DisableAllChannel(TSI_Type *instance)
{
    instance->CHCR0 = 0UL;
    instance->CHCR1 = 0UL;
}

static void TSI_EnableChannel(TSI_Type *instance, uint32_t ch)
{
    if(ch < 32U) {
        instance->CHCR0 |= (0x1UL << ch);
    }
    else {
        instance->CHCR1 |= (0x1UL << (ch - 32U));
    }
}

static void TSI_SetChannelTx(TSI_Type *instance, uint32_t ch)
{
    if(ch < 32U) {
        instance->CHCFGR0 |= (0x1UL << ch);
    }
    else {
        instance->CHCFGR1 |= (0x1UL << (ch - 32U));
    }
}

static void TSI_SetChannelRx(TSI_Type *instance, uint32_t ch)
{
    if(ch < 32U) {
        instance->CHCFGR0 &= ~(0x1UL << ch);
    }
    else {
        instance->CHCFGR1 &= ~(0x1UL << (ch - 32U));
    }
}

static void TSI_SetIDAC1Step(TSI_Type *instance, uint8_t step)
{
    instance->ANACR &= ~(0x3UL << 10U);
    switch(step) {
        case TSI_DEV_IDAC_STEP_37P5NA:
            instance->ANACR &= ~(0x1UL << 14U);     /* IDAC1_DOUBLE = 0 */
            instance->ANACR |= (0x0UL << 10U);
            break;

        case TSI_DEV_IDAC_STEP_75NA:
            instance->ANACR |= (0x1UL << 14U);      /* IDAC1_DOUBLE = 1 */
            instance->ANACR |= (0x0UL << 10U);
            break;

        case TSI_DEV_IDAC_STEP_300NA:
            instance->ANACR &= ~(0x1UL << 14U);     /* IDAC1_DOUBLE = 0 */
            instance->ANACR |= (0x1UL << 10U);
            break;

        case TSI_DEV_IDAC_STEP_600NA:
            instance->ANACR |= (0x1UL << 14U);      /* IDAC1_DOUBLE = 1 */
            instance->ANACR |= (0x1UL << 10U);
            break;

        case TSI_DEV_IDAC_STEP_1P2UA:
            instance->ANACR &= ~(0x1UL << 14U);     /* IDAC1_DOUBLE = 0 */
            instance->ANACR |= (0x2UL << 10U);
            break;

        case TSI_DEV_IDAC_STEP_2P4UA:
            instance->ANACR &= ~(0x1UL << 14U);     /* IDAC1_DOUBLE = 0 */
            instance->ANACR |= (0x3UL << 10U);
            break;

        case TSI_DEV_IDAC_STEP_4P8UA:
            instance->ANACR |= (0x1UL << 14U);      /* IDAC1_DOUBLE = 1 */
            instance->ANACR |= (0x3UL << 10U);
            break;

        default:
            /* Param error */
            TSI_ASSERT(0U);
            break;
    }
}

static void TSI_SetIDAC2Step(TSI_Type *instance, uint8_t step)
{
    instance->ANACR &= ~(0x3UL << 12U);
    switch(step) {
        case TSI_DEV_IDAC_STEP_37P5NA:
            instance->ANACR &= ~(0x1UL << 15U);     /* IDAC2_DOUBLE = 0 */
            instance->ANACR |= (0x0UL << 12U);
            break;

        case TSI_DEV_IDAC_STEP_75NA:
            instance->ANACR |= (0x1UL << 15U);      /* IDAC2_DOUBLE = 1 */
            instance->ANACR |= (0x0UL << 12U);
            break;

        case TSI_DEV_IDAC_STEP_300NA:
            instance->ANACR &= ~(0x1UL << 15U);     /* IDAC2_DOUBLE = 0 */
            instance->ANACR |= (0x1UL << 12U);
            break;

        case TSI_DEV_IDAC_STEP_600NA:
            instance->ANACR |= (0x1UL << 15U);      /* IDAC2_DOUBLE = 1 */
            instance->ANACR |= (0x1UL << 12U);
            break;

        case TSI_DEV_IDAC_STEP_1P2UA:
            instance->ANACR &= ~(0x1UL << 15U);     /* IDAC2_DOUBLE = 0 */
            instance->ANACR |= (0x2UL << 12U);
            break;

        case TSI_DEV_IDAC_STEP_2P4UA:
            instance->ANACR &= ~(0x1UL << 15U);     /* IDAC2_DOUBLE = 0 */
            instance->ANACR |= (0x3UL << 12U);
            break;

        case TSI_DEV_IDAC_STEP_4P8UA:
            instance->ANACR |= (0x1UL << 15U);      /* IDAC2_DOUBLE = 1 */
            instance->ANACR |= (0x3UL << 12U);
            break;

        default:
            /* Param error */
            TSI_ASSERT(0U);
            break;
    }
}

#ifndef TSI_UNIT_TEST
static void TSI_LoadIDAC1Trim(TSI_Type *instance, uint8_t step, uint8_t dir)
{
    uint16_t *pTrim;

    /* Get trim value */
    switch(step) {
        case TSI_DEV_IDAC_STEP_37P5NA:
            if(dir == TSI_IDAC_DIR_SOURCE) {
                pTrim = (uint16_t *)0x1FFFFAB0UL;
            }
            else if(dir == TSI_IDAC_DIR_SINK) {
                pTrim = (uint16_t *)0x1FFFFAB8UL;
            }
            else {
                TSI_ASSERT(0U);
                return;
            }
            break;

        case TSI_DEV_IDAC_STEP_75NA:
            if(dir == TSI_IDAC_DIR_SOURCE) {
                pTrim = (uint16_t *)0x1FFFFAC0UL;
            }
            else if(dir == TSI_IDAC_DIR_SINK) {
                pTrim = (uint16_t *)0x1FFFFAC8UL;
            }
            else {
                TSI_ASSERT(0U);
                return;
            }
            break;

        case TSI_DEV_IDAC_STEP_300NA:
            if(dir == TSI_IDAC_DIR_SOURCE) {
                pTrim = (uint16_t *)0x1FFFFAD0UL;
            }
            else if(dir == TSI_IDAC_DIR_SINK) {
                pTrim = (uint16_t *)0x1FFFFAD8UL;
            }
            else {
                TSI_ASSERT(0U);
                return;
            }
            break;

        case TSI_DEV_IDAC_STEP_600NA:
            if(dir == TSI_IDAC_DIR_SOURCE) {
                pTrim = (uint16_t *)0x1FFFFAE8UL;
            }
            else if(dir == TSI_IDAC_DIR_SINK) {
                pTrim = (uint16_t *)0x1FFFFAF8UL;
            }
            else {
                TSI_ASSERT(0U);
                return;
            }
            break;

        case TSI_DEV_IDAC_STEP_1P2UA:
            if(dir == TSI_IDAC_DIR_SOURCE) {
                pTrim = (uint16_t *)0x1FFFFB50UL;
            }
            else if(dir == TSI_IDAC_DIR_SINK) {
                pTrim = (uint16_t *)0x1FFFFB58UL;
            }
            else {
                TSI_ASSERT(0U);
                return;
            }
            break;

        case TSI_DEV_IDAC_STEP_2P4UA:
            if(dir == TSI_IDAC_DIR_SOURCE) {
                pTrim = (uint16_t *)0x1FFFFB70UL;
            }
            else if(dir == TSI_IDAC_DIR_SINK) {
                pTrim = (uint16_t *)0x1FFFFB78UL;
            }
            else {
                TSI_ASSERT(0U);
                return;
            }
            break;

        case TSI_DEV_IDAC_STEP_4P8UA:
            if(dir == TSI_IDAC_DIR_SOURCE) {
                pTrim = (uint16_t *)0x1FFFFB80UL;
            }
            else if(dir == TSI_IDAC_DIR_SINK) {
                pTrim = (uint16_t *)0x1FFFFB88UL;
            }
            else {
                TSI_ASSERT(0U);
                return;
            }
            break;

        default:
            /* Cannot be here */
            TSI_ASSERT(0U);
            return;
    }

    /* Check trim value and set to register */
    if(*pTrim != 0xFFFFU) {
        TSI_ASSERT(((*pTrim) ^ (*(pTrim + 2U))) == 0xFFFFU);
        instance->IDACTR = (instance->IDACTR & ~(0x1FUL)) | (uint32_t)(*pTrim);
    }
    else {
        /* Set to default value */
        instance->IDACTR = (instance->IDACTR & ~(0x1FUL)) | (0x10UL);
    }
}

static void TSI_LoadIDAC2Trim(TSI_Type *instance, uint8_t step, uint8_t dir)
{
    uint16_t *pTrim;

    /* Get trim value */
    switch(step) {
        case TSI_DEV_IDAC_STEP_37P5NA:
            if(dir == TSI_IDAC_DIR_SOURCE) {
                pTrim = (uint16_t *)0x1FFFFAB4UL;
            }
            else if(dir == TSI_IDAC_DIR_SINK) {
                pTrim = (uint16_t *)0x1FFFFABCUL;
            }
            else {
                TSI_ASSERT(0U);
                return;
            }
            break;

        case TSI_DEV_IDAC_STEP_75NA:
            if(dir == TSI_IDAC_DIR_SOURCE) {
                pTrim = (uint16_t *)0x1FFFFAC4UL;
            }
            else if(dir == TSI_IDAC_DIR_SINK) {
                pTrim = (uint16_t *)0x1FFFFACCUL;
            }
            else {
                TSI_ASSERT(0U);
                return;
            }
            break;

        case TSI_DEV_IDAC_STEP_300NA:
            if(dir == TSI_IDAC_DIR_SOURCE) {
                pTrim = (uint16_t *)0x1FFFFAD4UL;
            }
            else if(dir == TSI_IDAC_DIR_SINK) {
                pTrim = (uint16_t *)0x1FFFFADCUL;
            }
            else {
                TSI_ASSERT(0U);
                return;
            }
            break;

        case TSI_DEV_IDAC_STEP_600NA:
            if(dir == TSI_IDAC_DIR_SOURCE) {
                pTrim = (uint16_t *)0x1FFFFAECUL;
            }
            else if(dir == TSI_IDAC_DIR_SINK) {
                pTrim = (uint16_t *)0x1FFFFAFCUL;
            }
            else {
                TSI_ASSERT(0U);
                return;
            }
            break;

        case TSI_DEV_IDAC_STEP_1P2UA:
            if(dir == TSI_IDAC_DIR_SOURCE) {
                pTrim = (uint16_t *)0x1FFFFB54UL;
            }
            else if(dir == TSI_IDAC_DIR_SINK) {
                pTrim = (uint16_t *)0x1FFFFB5CUL;
            }
            else {
                TSI_ASSERT(0U);
                return;
            }
            break;

        case TSI_DEV_IDAC_STEP_2P4UA:
            if(dir == TSI_IDAC_DIR_SOURCE) {
                pTrim = (uint16_t *)0x1FFFFB74UL;
            }
            else if(dir == TSI_IDAC_DIR_SINK) {
                pTrim = (uint16_t *)0x1FFFFB7CUL;
            }
            else {
                TSI_ASSERT(0U);
                return;
            }
            break;

        case TSI_DEV_IDAC_STEP_4P8UA:
            if(dir == TSI_IDAC_DIR_SOURCE) {
                pTrim = (uint16_t *)0x1FFFFB84UL;
            }
            else if(dir == TSI_IDAC_DIR_SINK) {
                pTrim = (uint16_t *)0x1FFFFB8CUL;
            }
            else {
                TSI_ASSERT(0U);
                return;
            }
            break;

        default:
            /* Cannot be here */
            TSI_ASSERT(0U);
            return;
    }

    /* Check trim value and set to register */
    if(*pTrim != 0xFFFFU) {
        TSI_ASSERT(((*pTrim) ^ (*(pTrim + 2U))) == 0xFFFFU);
        instance->IDACTR = (instance->IDACTR & ~(0x1F00UL)) | (uint32_t)((*pTrim) << 8U);
    }
    else {
        /* Set to default value */
        instance->IDACTR = (instance->IDACTR & ~(0x1F00UL)) | (0x10UL << 8U);
    }
}
#endif  /* TSI_UNIT_TEST */

static void TSI_EnableIT(TSI_Type *instance)
{
    /* Enable end of conversion interrupt */
    instance->ISR = (0x1UL << 1U);
    instance->IER |= (0x1UL << 1U);

    /* Enable end of sequence interrupt */
    instance->ISR = (0x1UL << 2U);
    instance->IER |= (0x1UL << 2U);
}

static void TSI_DisableIT(TSI_Type *instance)
{
    /* Disable end of conversion interrupt */
    instance->ISR = (0x1UL << 1U);
    instance->IER &= ~(0x1UL << 1U);

    /* Enable end of sequence interrupt */
    instance->ISR = (0x1UL << 2U);
    instance->IER &= ~(0x1UL << 2U);
}

#if ((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U))

static void TSI_SetupDMA(TSI_Type *instance)
{
    if(instance == TSI) {
        /* Enable DMA clock */
        CMU->PCLKCR2 |= (1UL << 4U);

        /* Configure DMA write channel (Request #107) */
        DMA_REG(CFGR, TSI_DMA_WR_CHANNEL) &= ~(0xFFFFFFFFUL);
        DMA_REG(CFGR, TSI_DMA_WR_CHANNEL) |= (TSI_DMA_WR_PRIORITY << 6U);   /* DMA Priority */
        DMA_REG(CFGR, TSI_DMA_WR_CHANNEL) |= (107UL << 8U);                 /* DMA Request */
        DMA_REG(CFGR, TSI_DMA_WR_CHANNEL) |= (0x2UL << 4U);                 /* 32B */
        DMA_REG(CFGR, TSI_DMA_WR_CHANNEL) |= (0x1UL << 0U);                 /* Mem to Periph */
        DMA_REG(PAR, TSI_DMA_WR_CHANNEL) = (uint32_t)&TSI->SPCFGR;

        /* Configure DMA read channel (Request #108) */
        DMA_REG(CFGR, TSI_DMA_RD_CHANNEL) &= ~(0xFFFFFFFFUL);
        DMA_REG(CFGR, TSI_DMA_RD_CHANNEL) |= (TSI_DMA_RD_PRIORITY << 6U);   /* DMA Priority */
        DMA_REG(CFGR, TSI_DMA_RD_CHANNEL) |= (108UL << 8U);                 /* DMA Request */
        DMA_REG(CFGR, TSI_DMA_RD_CHANNEL) |= (0x2UL << 4U);                 /* 32B */
        DMA_REG(CFGR, TSI_DMA_RD_CHANNEL) |= (0x0UL << 0U);                 /* Periph to Mem */
        DMA_REG(PAR, TSI_DMA_RD_CHANNEL) = (uint32_t)&TSI->RAWCNTR;

        /* Enable DMA Controller */
        DMA->GCR |= (1UL << 0U);
    }
}

static void TSI_ResetDMA(TSI_Type *instance)
{
    if(instance == TSI) {
        /* Disable and reset channel */
        DMA_REG(CFGR, TSI_DMA_WR_CHANNEL) &= ~(0x1UL << 6U);
        DMA_REG(CFGR, TSI_DMA_WR_CHANNEL) &= ~(0xFFFFFFFFUL);
        DMA_REG(CFGR, TSI_DMA_RD_CHANNEL) &= ~(0x1UL << 6U);
        DMA_REG(CFGR, TSI_DMA_RD_CHANNEL) &= ~(0xFFFFFFFFUL);
    }
}

#endif  /* TSI_USE_DMA && TSI_DEV_SUPPORT_DMA */

static uint32_t TSI_ReadData(TSI_Type *instance)
{
    return ((instance->RAWCNTR) & 0xFFFFU);
}

#ifdef TSI_LIB_USE_ASSERT

static uint32_t TSI_GetTxChannel(uint32_t reg)
{
    return ((reg >> 24U) & 0x3FU);
}

static uint32_t TSI_GetRxChannel(uint32_t reg)
{
    return ((reg >> 16U) & 0x3FU);
}

#endif

#if ((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U))

static void TSI_StartDMA(TSI_Type *instance, uint32_t *config, uint32_t *data,
                         uint16_t size)
{
    TSI_ASSERT(size > 0U);
    if(instance == TSI) {
        /* Enable DMA write/read request */
        TSI->DMACR |= 0x3U;

        /* Configure address and size, then start the transmission */
        /* DMA write channel */
        DMA_REG(CFGR, TSI_DMA_WR_CHANNEL) |= (size - 1U) << 16U;
        DMA_REG(MAR0, TSI_DMA_WR_CHANNEL) = (uint32_t) config;
        DMA_REG(CR, TSI_DMA_WR_CHANNEL) |= (0x1UL << 0U);
        /* DMA read channel */
        DMA_REG(CFGR, TSI_DMA_RD_CHANNEL) |= (size - 1U) << 16U;
        DMA_REG(MAR0, TSI_DMA_RD_CHANNEL) = (uint32_t) data;
        DMA->ISR = (1UL << (8U + TSI_DMA_RD_CHANNEL));
        DMA_REG(CFGR, TSI_DMA_RD_CHANNEL) |= (0x1UL << 2U);
        DMA_REG(CR, TSI_DMA_RD_CHANNEL) |= (0x1UL << 0U);
    }
}

static void TSI_StopDMA(TSI_Type *instance)
{
    if(instance == TSI) {
        /* Disable DMA interrupt, write/read request and channel */
        TSI->DMACR &= ~(0x3U);
        DMA->ISR = (1UL << (8U + TSI_DMA_RD_CHANNEL));
        DMA_REG(CFGR, TSI_DMA_RD_CHANNEL) &= ~(0x1UL << 2U);
        DMA_REG(CFGR, TSI_DMA_WR_CHANNEL) &= ~(0x1UL << 6U);
        DMA_REG(CFGR, TSI_DMA_RD_CHANNEL) &= ~(0x1UL << 6U);
    }
}

#endif  /* TSI_USE_DMA && TSI_DEV_SUPPORT_DMA */

void TSI_SetGroundOutput(TSI_DriverTypeDef *driver, TSI_SensorTypeDef *sensor)
{
    GPIO_Type *port;
    uint32_t portId, pin;
    int rxChannel = sensor->meta->rxChannel;
    int txChannel = (sensor->meta->type == TSI_SENSOR_MUTUAL_CAP) ? sensor->meta->txChannel : -1;
    TSI_FOREACH_OBJ(TSI_IOConfTypeDef *, io, driver->ios, driver->ioNum) {
        /* Get GPIO info */
        portId = io->port;
        pin = io->pin;
        TSI_ASSERT(portId < (sizeof(PORTS) / sizeof(GPIO_Type *)));
        port = PORTS[portId];

        if(((txChannel != -1) && (io->channel == txChannel)) ||
                (io->channel == rxChannel)) {
            /* Used. Configure GPIO to analog mode. */
            port->FCR |= (0x3UL << (pin * 2U));     /* Analog mode */
            port->PUDEN &= ~(0x10001UL << pin);     /* Disable pull-up and pull down */
        }
        else {
            /* Unused. Configure GPIO to output mode and set to 0. */
            port->FCR &= ~(0x3UL << (pin * 2U));
            port->FCR |= (0x1UL << (pin * 2U));     /* Output mode */
            port->DRST = (0x1UL << pin);            /* Output 0 */
        }
    }
    TSI_FOREACH_END()
}

void TSI_ResetGroundOutput(TSI_DriverTypeDef *driver)
{
    /* Device IO init */
    TSI_FOREACH(const TSI_IOConfTypeDef * io, driver->ios, driver->ioNum, 0U) {
        TSI_Dev_SetupPort(driver, io);
    }
    TSI_FOREACH_END()
}
