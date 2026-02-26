#include "tsi_calibration.h"
#include "tsi_utils.h"
#include "tsi_filter.h"
#include "tsi.h"

/* Private macros -----------------------------------------------------------*/
#define TSI_CALIB_TARGET(PERCENT, RESOLUTION)   \
    (((uint32_t)(PERCENT) * (RESOLUTION)) / 100UL)

/* Private defines ----------------------------------------------------------*/
/* Self-cap scan configuration */
static uint16_t calibSCSensorList[1U] = { 0U };
static TSI_ScanGroupTypeDef calibSCScanGroup = {
    1U, TSI_SCAN_GROUP_SELF_CAP, 0U,
    (uint16_t *) calibSCSensorList,
};

/* Private function prototypes ----------------------------------------------*/
TSI_STATIC TSI_RetCode TSI_CalibrateSelfCapWidgetIDAC(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget,
        uint8_t target);
TSI_STATIC TSI_RetCode TSI_TuneSelfCapWidgetIDACCode(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget,
        uint8_t target);
TSI_STATIC bool TSI_TuneSelfCapWidgetIDACStep(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget, uint8_t *currStep);
TSI_STATIC void TSI_NormalizeSelfCapWidgetIDACCode(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget, uint8_t target);
TSI_STATIC void TSI_TuneSelfCapWidgetResolution(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget);
TSI_STATIC TSI_RetCode TSI_TuneSelfCapWidgetCompIDACCode(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget,
        uint8_t target);
TSI_STATIC TSI_RetCode TSI_TuneMutualCapWidgetIDACCode(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget,
        uint8_t target);

/* API implementations ------------------------------------------------------*/
#if ((TSI_SC_CALIB_METHOD != TSI_SC_CALIB_NONE) || (TSI_MC_CALIB_METHOD != TSI_MC_CALIB_NONE))
TSI_RetCode TSI_CalibrateAllWidgets(TSI_LibHandleTypeDef *handle)
{
    TSI_RetCode res;

    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        if(TSI_WIDGET_IS_SELF_CAP(*ppWidget)) {
#if (TSI_SC_CALIB_METHOD != TSI_SC_CALIB_NONE)
            res = TSI_CalibrateSelfCapWidget(handle, (*ppWidget), TSI_SC_CALIB_METHOD);
            if(res != TSI_PASS) { return res; }
#else
            /* Re-init widget */
            res = TSI_ScanAndInitWidget(handle, (*ppWidget));
            if(res != TSI_PASS) { return res; }
#endif  /* TSI_SC_CALIB_METHOD != TSI_SC_CALIB_NONE */
        }
        else if(TSI_WIDGET_IS_MUTUAL_CAP(*ppWidget)) {
#if (TSI_MC_CALIB_METHOD != TSI_MC_CALIB_NONE)
            res = TSI_CalibrateMutualCapWidget(handle, (*ppWidget), TSI_MC_CALIB_METHOD);
            if(res != TSI_PASS) { return res; }
#else
            /* Re-init widget */
            res = TSI_ScanAndInitWidget(handle, (*ppWidget));
            if(res != TSI_PASS) { return res; }
#endif  /* TSI_MC_CALIB_METHOD != TSI_MC_CALIB_NONE */
        }
    }
    TSI_FOREACH_END()

    return TSI_PASS;
}

TSI_RetCode TSI_CalibrateWidget(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget)
{
    TSI_RetCode res;

    if(TSI_WIDGET_IS_SELF_CAP(widget)) {
        res = TSI_CalibrateSelfCapWidget(handle, widget, TSI_SC_CALIB_METHOD);
        if(res != TSI_PASS) { return res; }
    }
    else if(TSI_WIDGET_IS_MUTUAL_CAP(widget)) {
        res = TSI_CalibrateMutualCapWidget(handle, widget, TSI_MC_CALIB_METHOD);
        if(res != TSI_PASS) { return res; }
    }

    return TSI_PASS;
}
#endif  /* ((TSI_SC_CALIB_METHOD != TSI_SC_CALIB_NONE) || (TSI_MC_CALIB_METHOD != TSI_MC_CALIB_NONE)) */

TSI_RetCode TSI_CalibrateSelfCapWidget(TSI_LibHandleTypeDef *handle,
                                       TSI_WidgetTypeDef *widget,
                                       uint8_t method)
{
    TSI_SelfCapWidgetTypeDef *scWidget = (TSI_SelfCapWidgetTypeDef *)widget;
    TSI_DriverTypeDef *driver = handle->driver;

    if(method == TSI_SC_CALIB_HW_PARAM) {
        uint32_t inClk;
        uint16_t minSnsDiv, snsDiv;
        uint8_t maxIdacComp;
        uint32_t maxCs;
        uint32_t maxFsw;
        TSI_SensorTypeDef *pMaxSns;
        uint32_t i;
        TSI_RetCode res;

        TSI_DEBUG(">>> TSI_CalibrateSelfCapWidget");

        /* Calculate minimum sensor clock divider */
        inClk = TSI_Dev_GetSCSnsInputClock(&driver->clocks[0U]);
        TSI_DEBUG("Input clock: %d", inClk);
        minSnsDiv = (uint16_t)(inClk / TSI_DEV_MAX_SNS_CLK_FREQ_HZ);
        if(minSnsDiv < TSI_DEV_MIN_SNS_CLK_DIV) {
            minSnsDiv = TSI_DEV_MIN_SNS_CLK_DIV;
        }
        else if((minSnsDiv & 0x1U) != 0U) {
            /* Make divider even */
            minSnsDiv += 1U;
        }
        TSI_DEBUG("Min snsClk divider: %d", minSnsDiv);

        /*---------------------------------------------------#/
            Step 1: Perform IDAC calibration and calculate
            maximum sensor Cs.
        #----------------------------------------------------*/
        /* Setup clock to direct clock to minimize sample noise. */
        for(i = TSI_CLOCK_SC_IDX; i < TSI_CLOCK_SC_NUM; i++) {
            TSI_Dev_SetupDirectClock(&driver->clocks[i]);
        }

        /* Calibrate sensor IDAC using default configuration. */
        scWidget->resolution = TSI_SC_CALIB_INIT_RESOLUTION;
        scWidget->swClkDiv = (uint16_t)(inClk / TSI_SC_CALIB_INIT_FREQ_HZ);
        if(scWidget->swClkDiv < minSnsDiv) {
            scWidget->swClkDiv = minSnsDiv;
        }
        res = TSI_CalibrateSelfCapWidgetIDAC(handle, widget, TSI_SC_CALIB_IDAC_TARGET);
        if(res != TSI_PASS) {
            TSI_DEBUG("<<< TSI_CalibrateSelfCapWidget <!RET=%d>", res);
            return res;
        }

        /* Calculate maximum sensor Cs. */
        maxIdacComp = 0U;
        pMaxSns = &widget->meta->sensors[0U];
        TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                        widget->meta->sensorNum) {
            if(maxIdacComp < pSensor->idac[0U]) {
                maxIdacComp = pSensor->idac[0U];
                pMaxSns = pSensor;
            }
        }
        TSI_FOREACH_END()
        /* Calculate and update sensor cap value. */
        maxCs = TSI_CalcSelfCapSensorCap(&driver->clocks[TSI_CLOCK_SC_IDX], pMaxSns, 0U);
        TSI_DEBUG("Max Cs: %.3fpF", maxCs / 1000.0f);

        /* Set snsClk divider. */
        maxFsw = (uint32_t)((uint64_t)100000000000000ULL / (uint64_t)(TSI_SERIES_R_OHM * maxCs));
        TSI_DEBUG("Max Fsw: %dHz", maxFsw);
        for(snsDiv = 1U; snsDiv < TSI_DEV_MAX_SNS_CLK_DIV; snsDiv <<= 1U) {
            if(maxFsw * snsDiv >= inClk)
            { break; }
        }
        if(snsDiv < minSnsDiv) {
            snsDiv = minSnsDiv;
        }
        scWidget->swClkDiv = snsDiv;
        TSI_DEBUG("snsClk divider: %d", snsDiv);

        /*---------------------------------------------------#/
            Step 2: Perform IDAC calibration with new swClkDiv
            and set widget resolution.
        #----------------------------------------------------*/
        res = TSI_CalibrateSelfCapWidgetIDAC(handle, widget, TSI_SC_CALIB_IDAC_TARGET);
        if(res != TSI_PASS) {
            TSI_DEBUG("<<< TSI_CalibrateSelfCapWidget <!RET=%d>", res);
            return res;
        }
        TSI_TuneSelfCapWidgetResolution(handle, widget);

        /*---------------------------------------------------#/
            Calibration end. Restore clock configuration and init widget.
        #----------------------------------------------------*/
#if (TSI_SC_CALIB_AUTO_SNSCLK_SRC == 1U)
        /* Currently not supported. */
#error "TSI_SC_CALIB_AUTO_SNSCLK_SRC = 1 is currently not supported."
#else
        {
            /* Adjust clock divisor if there is difference between user selected clock
               and calibration used clock (Round to the nearest). Library assumes
               same clock mode for all scan frequencies. */
            uint32_t userClock, calibClock;
            uint16_t oldSwClkDiv = scWidget->swClkDiv;
            userClock = TSI_Dev_GetSCSwitchClock((TSI_ClockConfTypeDef *)&TSI_ClockConfConstInit[TSI_CLOCK_SC_IDX], 2U);
            calibClock = TSI_Dev_GetSCSwitchClock(&TSI_ClockConf[TSI_CLOCK_SC_IDX], 2U);
            scWidget->swClkDiv = (uint16_t)((((uint64_t)userClock * (uint64_t)oldSwClkDiv) * 256ULL /
                                             (uint64_t)calibClock + 128ULL) / 256ULL);
            memcpy(&TSI_ClockConf, &TSI_ClockConfConstInit, sizeof(TSI_ClockConfConstInit));

            if(scWidget->swClkDiv != oldSwClkDiv)
            {
                /* Perform an IDAC calibration if clock changed. */
                res = TSI_CalibrateSelfCapWidgetIDAC(handle, widget, TSI_SC_CALIB_IDAC_TARGET);
                if(res != TSI_PASS) {
                    TSI_DEBUG("<<< TSI_CalibrateSelfCapWidget <!RET=%d>", res);
                    return res;
                }
            }
        }
#endif

        /* Re-init widget */
        TSI_ScanAndInitWidget(handle, widget);

        TSI_DEBUG("<<< TSI_CalibrateSelfCapWidget");
    }
    else if(method == TSI_SC_CALIB_BOTH_IDAC) {
        TSI_RetCode res;

        TSI_DEBUG(">>> TSI_CalibrateSelfCapWidget");

        res = TSI_CalibrateSelfCapWidgetIDAC(handle, widget, TSI_SC_CALIB_IDAC_TARGET);
        if(res != TSI_PASS) {
            TSI_DEBUG("<<< TSI_CalibrateSelfCapWidget <!RET=%d>", res);
            return res;
        }

        /* Re-init widget */
        res = TSI_ScanAndInitWidget(handle, widget);
        if(res != TSI_PASS) {
            TSI_DEBUG("<<< TSI_CalibrateSelfCapWidget <!RET=%d>", res);
            return res;
        }

        TSI_DEBUG("<<< TSI_CalibrateSelfCapWidget");
    }
    else if(method == TSI_SC_CALIB_COMP_IDAC) {
        TSI_RetCode res;

        TSI_DEBUG(">>> TSI_CalibrateSelfCapWidget");

        res = TSI_TuneSelfCapWidgetCompIDACCode(handle, widget, TSI_SC_CALIB_IDAC_TARGET);
        if(res != TSI_PASS) {
            TSI_DEBUG("<<< TSI_CalibrateSelfCapWidget <!RET=%d>", res);
            return res;
        }

        /* Re-init widget */
        res = TSI_ScanAndInitWidget(handle, widget);
        if(res != TSI_PASS) {
            TSI_DEBUG("<<< TSI_CalibrateSelfCapWidget <!RET=%d>", res);
            return res;
        }

        TSI_DEBUG("<<< TSI_CalibrateSelfCapWidget");
    }
    else {
        /* Method not supported. */
        return TSI_UNSUPPORTED;
    }

#if (TSI_STATISTIC_SENSOR_CS == 1U)
    /* Calculate sensor capcitance */
    TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                    widget->meta->sensorNum) {
        (void) TSI_CalcSelfCapSensorCap(&driver->clocks[TSI_CLOCK_SC_IDX], pSensor, 1U);
    }
    TSI_FOREACH_END()
#endif  /* TSI_STATISTIC_SENSOR_CS == 1U */

    return TSI_PASS;
}

TSI_RetCode TSI_CalibrateMutualCapWidget(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget,
        uint8_t method)
{
    TSI_MutualCapWidgetTypeDef *mcWidget = (TSI_MutualCapWidgetTypeDef *) widget;
    TSI_DriverTypeDef *driver = handle->driver;

    TSI_UNUSED(mcWidget)
    TSI_UNUSED(driver)

    if(method == TSI_MC_CALIB_IDAC) {
        TSI_RetCode res;

        TSI_DEBUG(">>> TSI_CalibrateMutualCapWidget");

        res = TSI_TuneMutualCapWidgetIDACCode(handle, widget, TSI_MC_CALIB_IDAC_TARGET);
        if(res != TSI_PASS) {
            TSI_DEBUG("<<< TSI_CalibrateMutualCapWidget <!RET=%d>", res);
            return res;
        }

        /* Re-init widget */
        res = TSI_ScanAndInitWidget(handle, widget);
        if(res != TSI_PASS) {
            TSI_DEBUG("<<< TSI_CalibrateSelfCapWidget <!RET=%d>", res);
            return res;
        }

        TSI_DEBUG("<<< TSI_CalibrateMutualCapWidget");
    }
    else {
        /* Method not supported. */
        return TSI_UNSUPPORTED;
    }

#if (TSI_STATISTIC_SENSOR_CS == 1U)
    /* Calculate sensor capcitance */
    TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                    widget->meta->sensorNum) {
        (void) TSI_CalcMutualCapSensorCap(&driver->clocks[TSI_CLOCK_MC_IDX], pSensor, 1U);
    }
    TSI_FOREACH_END()
#endif  /* TSI_STATISTIC_SENSOR_CS == 1U */

    return TSI_PASS;
}

/* Private function implemenations ------------------------------------------*/
/**
 *  Calibrate IDAC code and step
 */
TSI_STATIC TSI_RetCode TSI_CalibrateSelfCapWidgetIDAC(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget,
        uint8_t target)
{
    TSI_SelfCapWidgetTypeDef *scWidget = (TSI_SelfCapWidgetTypeDef *)widget;
#if (TSI_SC_CALIB_AUTO_IDAC_STEP == 1U)
    uint8_t currStep;
    bool stepSwitchFlag;
#endif

    /* Check lib status -----------------------------------------------------*/
    if(handle->status != TSI_LIB_SUSPEND &&
            handle->status != TSI_LIB_RESET) {
        /* Should stop scan before calibration */
        return TSI_UNSUPPORTED;
    }

    /* Calibrate ------------------------------------------------------------*/
    currStep = TSI_SC_CALIB_INIT_IDAC_STEP_IDX;
    do {
        scWidget->idacStep = currStep;
#if (TSI_SC_USE_UNIFIED_IDAC_STEP == 0U)
        /* Keep IDAC step same for best performance. */
        scWidget->idacCompStep = currStep;
#endif
        TSI_DEBUG("IDAC step: %.1fnA", TSI_Dev_IDACCurrentTable[currStep] / 1000.0f);
        TSI_TuneSelfCapWidgetIDACCode(handle, widget, target);
        stepSwitchFlag = TSI_TuneSelfCapWidgetIDACStep(handle, widget, &currStep);
    } while(stepSwitchFlag);
    TSI_NormalizeSelfCapWidgetIDACCode(handle, widget, target);

    /** @todo Validate result */

    return TSI_PASS;
}

/**
 *  Tune IDAC code
 */
TSI_STATIC TSI_RetCode TSI_TuneSelfCapWidgetIDACCode(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget,
        uint8_t target)
{
    TSI_SelfCapWidgetTypeDef *scWidget = (TSI_SelfCapWidgetTypeDef *)widget;
    uint8_t maxIdacMod[TSI_SCAN_FREQ_NUM];
    uint8_t widgetEnable;
    TSI_ScanGroupTypeDef *groupList;
    uint8_t groupNum;
    TSI_ScanGroupTypeDef *dediGroup;
    uint16_t realSnsNum;
    uint16_t targetVal;
    uint32_t freq;
    TSI_RetCode res = TSI_PASS;

    /* Check lib status -----------------------------------------------------*/
    if(handle->status != TSI_LIB_SUSPEND &&
            handle->status != TSI_LIB_RESET) {
        /* Should stop scan before calibration */
        return TSI_UNSUPPORTED;
    }

    /* Save context ---------------------------------------------------------*/
    widgetEnable = widget->enable;
    groupList = handle->driver->scanGroups;
    groupNum = handle->driver->scanGroupNum;

    /* Calibrate ------------------------------------------------------------*/
    TSI_DEBUG(">>> TSI_TuneSelfCapWidgetIDACCode");

    /* Enable widget */
    widget->enable = TSI_WIDGET_ENABLE;

    /* Init variables */
    for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
        maxIdacMod[freq] = 0U;
    }
    targetVal = (uint16_t)TSI_CALIB_TARGET(target, TSI_Dev_GetSCConvCycleNum(scWidget->resolution));

    /* Switch to calibration scan group */
    if(widget->meta->dedicatedScanGroup == NULL) {
        /* Normal scan */
        handle->driver->scanGroups = (TSI_ScanGroupTypeDef *)&calibSCScanGroup;
        handle->driver->scanGroupNum = 1U;
#if (TSI_WIDGET_SC_TOUCHPAD_USED == 1U)
        if(widget->meta->type == TSI_WIDGET_SELF_CAP_TOUCHPAD) {
            TSI_MetaWidgetTypeDef *meta = (TSI_MetaWidgetTypeDef *)widget->meta;
            realSnsNum = meta->sensorNum + ((TSI_Meta2DWidgetTypeDef *)meta)->sensorRowNum;
        }
        else
#endif
            realSnsNum = widget->meta->sensorNum;
    }
    else {
        /* Parallel scan */
        handle->driver->scanGroups = widget->meta->dedicatedScanGroup;
        handle->driver->scanGroupNum = 1U;
        realSnsNum = 1U;
    }

    TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                    realSnsNum) {
        uint8_t bitMask = 0x1U << (TSI_DEV_IDAC_BITWIDTH - 1U);
        uint8_t *idacMod = &scWidget->idacMod[0U];
        uint8_t *idacComp = &pSensor->idac[0U];

        TSI_DEBUG("Calibrate #%d sensor", idx);

        /* Init variables */
        for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
            idacMod[freq] = 0U;
        }

        /* Configure scan group */
        calibSCSensorList[0U] = pSensor->meta->id;
        dediGroup = pSensor->meta->dedicatedScanGroup;
        if(dediGroup != NULL) {
            /* Sensor use dedicated scan group. We should copy its option. */
            calibSCScanGroup.opt = dediGroup->opt;
        }
        else {
            /* Sensor use default scan group. Clear option. */
            calibSCScanGroup.opt = 0UL;
        }

        /* Successive approach method */
        while(bitMask != 0U) {
            /* Update idacMod and idacComp */
            for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
                idacMod[freq] |= bitMask;
                idacComp[freq] = idacMod[freq];
                TSI_INFO("#%d idacMod: %d, idacComp: %d",
                         freq, idacMod[freq], idacComp[freq]);
            }

            /* Perform a single scan */
            handle->driver->forceReConf = 1U;
            res = TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_BLOCKING, 1U);
            if(res != TSI_PASS) {
                goto RestoreContext;
            }

            /* Bypass filters */
            TSI_Filter_Bypass(pSensor);

            /* Adjust widget idacMod */
            for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
                if(pSensor->rawCount[freq] < targetVal) {
                    idacMod[freq] &= (~bitMask);
                }
            }

            /* Move to next bit */
            bitMask >>= 1U;
            if(bitMask == 0U) {
                /* Sync idacComp to idacMod */
                for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
                    idacComp[freq] = idacMod[freq];
                }
            }
        }

        for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
            /* idacMod cannot be 0, set to 1 */
            if(idacMod[freq] == 0U) {
                idacMod[freq] = 1U;
                idacComp[freq] = idacMod[freq];
            }
            /* Update maximum idacMod */
            if(maxIdacMod[freq] < idacMod[freq]) {
                maxIdacMod[freq] = idacMod[freq];
            }
        }
    }
    TSI_FOREACH_END()

    if(res == TSI_PASS) {
        for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
            /* Unify modulator IDAC code */
            scWidget->idacMod[freq] = maxIdacMod[freq];

#if (TSI_DEBUG_LEVEL >= 2)
            TSI_DEBUG("#%d scan: ", freq);
            TSI_DEBUG("- idacMod: %d", scWidget->idacMod[freq]);
            TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                            widget->meta->sensorNum) {
                TSI_DEBUG("- idacComp[%d]: %d", idx, pSensor->idac[freq]);
            }
            TSI_FOREACH_END()
#endif
        }

        /* Refresh rawcount */
        handle->driver->forceReConf = 1U;
        res = TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_BLOCKING, 1U);
        if(res != TSI_PASS) {
            goto RestoreContext;
        }
        /* Bypass filters */
        TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                        realSnsNum) {
            TSI_Filter_Bypass(pSensor);
        }
        TSI_FOREACH_END()
    }

RestoreContext:
    /* Restore rumtime context ----------------------------------------------*/
    widget->enable = widgetEnable;
    handle->driver->scanGroups = groupList;
    handle->driver->scanGroupNum = groupNum;
    handle->driver->forceReConf = 1U;

    TSI_DEBUG("<<< TSI_TuneSelfCapWidgetIDACCode <ret=%d>", res);

    return res;
}

TSI_STATIC bool TSI_TuneSelfCapWidgetIDACStep(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget, uint8_t *currStep)
{
    TSI_SelfCapWidgetTypeDef *scWidget = (TSI_SelfCapWidgetTypeDef *) widget;
    uint8_t minIdac, maxIdac;
    uint32_t freq;

    TSI_UNUSED(handle)

    maxIdac = 0U;
    minIdac = (0x1U << TSI_DEV_IDAC_BITWIDTH) - 1U;

    for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
        if(maxIdac < scWidget->idacMod[freq]) {
            maxIdac = scWidget->idacMod[freq];
        }
        if(minIdac > scWidget->idacMod[freq]) {
            minIdac = scWidget->idacMod[freq];
        }
    }

    TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                    widget->meta->sensorNum) {
        for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
            /* After code tuning, IDACMod >= IDACComp, so there is no need
               to update maxIdac. */
            if(minIdac > pSensor->idac[freq]) {
                minIdac = pSensor->idac[freq];
            }
        }
    }
    TSI_FOREACH_END()

    if(*currStep != 0U) {
        /* Switch to lower step if current minIdac is too small and
           next step code will not overflow. */
        if(minIdac < TSI_SC_CALIB_IDAC_MIN) {
            uint32_t tmp = TSI_Dev_IDACCurrentTable[*currStep] /
                           TSI_Dev_IDACCurrentTable[*currStep - 1U];
            if((maxIdac * tmp) < ((0x1U << TSI_DEV_IDAC_BITWIDTH) - 1U)) {
                *currStep -= 1U;
                TSI_DEBUG("Switch IDAC step to %d", *currStep);
                return true;
            }
        }
    }

    return false;
}

TSI_STATIC void TSI_NormalizeSelfCapWidgetIDACCode(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget, uint8_t target)
{
    TSI_SelfCapWidgetTypeDef *scWidget = (TSI_SelfCapWidgetTypeDef *) widget;
    uint32_t idacMod;
    uint32_t prevIdacMod;
    uint32_t minIdacComp;
    uint32_t minRawCount;
    uint32_t fullRawCount;
    uint32_t freq;

    TSI_UNUSED(handle)

    if(widget->meta->dedicatedScanGroup != NULL) {
        /* Parallel scan has only one sensor, there is no need to normalize. */
        return;
    }

    /* If a widget has only one sensor, there is no need to normalize. */
    if(widget->meta->sensorNum <= 1U) {
        return;
    }

    /* Calculate rawcount full-range value */
    fullRawCount = TSI_Dev_GetSCConvCycleNum(scWidget->resolution);

    for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
        /* Find sensor with minimum IdacComp value. This sensor has lowest Cs. */
        prevIdacMod = scWidget->idacMod[freq];
        minIdacComp = prevIdacMod;
        minRawCount = 0U;
        TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                        widget->meta->sensorNum) {
            if(idx == 0U) {
                /* Init */
                minRawCount = pSensor->rawCount[freq];
            }
            else if(minIdacComp > pSensor->idac[freq]) {
                minIdacComp = pSensor->idac[freq];
                minRawCount = pSensor->rawCount[freq];
            }
            else {
                /* Do nothing */
            }
        }
        TSI_FOREACH_END()

        /* Normalize this sensor to target using single IDAC mode */
        idacMod = minIdacComp * (((minRawCount * 100UL) / fullRawCount) + 100UL) / target;
        if(idacMod > prevIdacMod) {
            /* Should not decrease sensitivity */
            idacMod = prevIdacMod;
        }
        scWidget->idacMod[freq] = (uint8_t)idacMod;

        TSI_DEBUG("Normalize #%d idacMod: %d", freq, idacMod);

        /* Adjust IdacComp of all sensors */
        TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                        widget->meta->sensorNum) {
            uint32_t tmp = pSensor->idac[freq] *
                           (((pSensor->rawCount[freq] * 100UL) / fullRawCount) + 100UL);
            if(tmp < (idacMod * target)) {
                pSensor->idac[freq] = 0U;
            }
            else {
                /* Round to nearest */
                pSensor->idac[freq] = (uint8_t)(((tmp - (idacMod * target)) + 50UL) / 100UL);
            }

            TSI_DEBUG("Normalize #%d idacComp[%d]: %d", freq, idx, pSensor->idac[freq]);
        }
        TSI_FOREACH_END()
    }
}

TSI_STATIC void TSI_TuneSelfCapWidgetResolution(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget)
{
    TSI_SelfCapWidgetTypeDef *scWidget = (TSI_SelfCapWidgetTypeDef *) widget;
    uint32_t fsw = TSI_Dev_GetSCSwitchClock(&handle->driver->clocks[TSI_CLOCK_SC_IDX],
                                            scWidget->swClkDiv);
    uint32_t idacMod = scWidget->idacMod[0U] * TSI_Dev_IDACCurrentTable[scWidget->idacStep];
    uint32_t target = (uint32_t)(((uint64_t)scWidget->sensitivity * 10U * idacMod * 100UL) /
                                 ((uint64_t)TSI_VREF_MV * fsw / 1000UL) / 100UL);
    uint8_t resolution;

    /* Fit resolution to target */
    for(resolution = TSI_SC_MAX_RESOLUTION;
            resolution > TSI_SC_MIN_RESOLUTION;
            resolution--) {
        if(target >= ((1UL << resolution) - 1UL)) {
            scWidget->resolution = resolution;
            break;
        }
    }

    TSI_DEBUG("Resolution: %d", resolution);
}

/* Tune self-cap widget IDACComp code. Will also tune user-defined scan IDACComp code. */
TSI_STATIC TSI_RetCode TSI_TuneSelfCapWidgetCompIDACCode(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget,
        uint8_t target)
{
    TSI_SelfCapWidgetTypeDef *scWidget = (TSI_SelfCapWidgetTypeDef *)widget;
    uint8_t widgetEnable;
    TSI_ScanGroupTypeDef *groupList;
    uint8_t groupNum;
    TSI_ScanGroupTypeDef *dediGroup;
    uint16_t realSnsNum;
    uint16_t targetVal;
    uint32_t freq;
    TSI_RetCode res = TSI_PASS;

    /* Check lib status -----------------------------------------------------*/
    if(handle->status != TSI_LIB_SUSPEND &&
            handle->status != TSI_LIB_RESET) {
        /* Should stop scan before calibration */
        return TSI_UNSUPPORTED;
    }

    /* Save context ---------------------------------------------------------*/
    widgetEnable = widget->enable;
    groupList = handle->driver->scanGroups;
    groupNum = handle->driver->scanGroupNum;

    /* Calibrate ------------------------------------------------------------*/
    TSI_DEBUG(">>> TSI_TuneSelfCapWidgetCompIDACCode");

    /* Enable widget */
    widget->enable = TSI_WIDGET_ENABLE;

    /* Init variables */
    targetVal = (uint16_t)TSI_CALIB_TARGET(target, TSI_Dev_GetSCConvCycleNum(scWidget->resolution));

    /* Switch to calibration scan group */
    if(widget->meta->dedicatedScanGroup == NULL) {
        /* Normal scan */
        handle->driver->scanGroups = (TSI_ScanGroupTypeDef *)&calibSCScanGroup;
        handle->driver->scanGroupNum = 1U;
#if (TSI_WIDGET_SC_TOUCHPAD_USED == 1U)
        if(widget->meta->type == TSI_WIDGET_SELF_CAP_TOUCHPAD) {
            TSI_MetaWidgetTypeDef *meta = (TSI_MetaWidgetTypeDef *)widget->meta;
            realSnsNum = meta->sensorNum + ((TSI_Meta2DWidgetTypeDef *)meta)->sensorRowNum;
        }
        else
#endif
            realSnsNum = widget->meta->sensorNum;
    }
    else {
        /* Parallel scan */
        handle->driver->scanGroups = widget->meta->dedicatedScanGroup;
        handle->driver->scanGroupNum = 1U;
        realSnsNum = 1U;
    }

    TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                    realSnsNum) {
        uint8_t bitMask = 0x1U << (TSI_DEV_IDAC_BITWIDTH - 1U);
        uint8_t *idacComp = &pSensor->idac[0U];

        TSI_DEBUG("Calibrate #%d sensor", idx);

        /* Init variables */
        for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
            idacComp[freq] = 0U;
        }

        /* Configure scan group */
        calibSCSensorList[0U] = pSensor->meta->id;
        dediGroup = pSensor->meta->dedicatedScanGroup;
        if(dediGroup != NULL) {
            /* Sensor use dedicated scan group. We should copy its option. */
            calibSCScanGroup.opt = dediGroup->opt;
        }
        else {
            /* Sensor use default scan group. Clear option. */
            calibSCScanGroup.opt = 0UL;
        }

        /* Successive approach method */
        while(bitMask != 0U) {
            /* Update idacComp */
            for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
                idacComp[freq] |= bitMask;
                TSI_INFO("#%d idacComp: %d", freq, idacComp[freq]);
            }

            /* Perform a single scan */
            handle->driver->forceReConf = 1U;
            res = TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_BLOCKING, 1U);
            if(res != TSI_PASS) {
                goto RestoreContext;
            }
            /* Bypass filters */
            TSI_Filter_Bypass(pSensor);

            /* Adjust widget idacComp */
            for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
                if(pSensor->rawCount[freq] < targetVal) {
                    idacComp[freq] &= (~bitMask);
                }
            }

            /* Move to next bit */
            bitMask >>= 1U;
        }
    }
    TSI_FOREACH_END()

#if (TSI_DEBUG_LEVEL >= 2)
    for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {

        TSI_DEBUG("#%d scan: ", freq);
        TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                        widget->meta->sensorNum) {
            TSI_DEBUG("- idacComp[%d]: %d", idx, pSensor->idac[freq]);
        }
        TSI_FOREACH_END()
    }
#endif

    /* Refresh rawcount */
    handle->driver->forceReConf = 1U;
    res = TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_BLOCKING, 1U);
    if(res != TSI_PASS) {
        goto RestoreContext;
    }
    /* Bypass filters */
    TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                    realSnsNum) {
        TSI_Filter_Bypass(pSensor);
    }
    TSI_FOREACH_END()

RestoreContext:
    /* Restore rumtime context ----------------------------------------------*/
    widget->enable = widgetEnable;
    handle->driver->scanGroups = groupList;
    handle->driver->scanGroupNum = groupNum;
    handle->driver->forceReConf = 1U;

    TSI_DEBUG("<<< TSI_TuneSelfCapWidgetCompIDACCode <ret=%d>", res);

    return res;
}

TSI_STATIC TSI_RetCode TSI_TuneMutualCapWidgetIDACCode(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget,
        uint8_t target)
{
    TSI_MutualCapWidgetTypeDef *mcWidget = (TSI_MutualCapWidgetTypeDef *) widget;
    TSI_ClockConfTypeDef *mcClock = &handle->driver->clocks[TSI_CLOCK_MC_IDX];
    uint32_t maxRawCount, targetVal;
    uint8_t bitMask = 0x1U << (TSI_DEV_IDAC_BITWIDTH - 1U);
    uint8_t widgetEnable;
    TSI_ScanGroupTypeDef *groupList;
    uint8_t groupNum;
    TSI_RetCode res = TSI_PASS;

    /* Check lib status -----------------------------------------------------*/
    if(handle->status != TSI_LIB_SUSPEND &&
            handle->status != TSI_LIB_RESET) {
        /* Should stop scan before calibration */
        return TSI_UNSUPPORTED;
    }

    /* Save context ---------------------------------------------------------*/
    widgetEnable = widget->enable;
    groupList = handle->driver->scanGroups;
    groupNum = handle->driver->scanGroupNum;

    /* Calibrate ------------------------------------------------------------*/
    TSI_DEBUG(">>> TSI_TuneMutualCapWidgetIDACCode");

    /* Enable widget */
    widget->enable = TSI_WIDGET_ENABLE;

    /* Set target value */
    maxRawCount = TSI_Dev_GetMCConvCycleNum(mcClock, mcWidget->resolution,
                                            mcWidget->txClkDiv);
    targetVal = (maxRawCount * target) / 100UL;
    TSI_INFO("target: %d", targetVal);

    /* Switch to widget's dedicated scan group */
    handle->driver->scanGroups = widget->meta->dedicatedScanGroup;
    handle->driver->scanGroupNum = 1U;
    TSI_ASSERT(handle->driver->scanGroup);

    /* Setup initial idac value */
    TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                    widget->meta->sensorNum) {
        uint32_t freq;
        TSI_INFO("#%d sensor", idx);
        for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
            pSensor->idac[freq] = bitMask;
            TSI_INFO("#%d idac: %d", freq, pSensor->idac[freq]);
    }
    }
    TSI_FOREACH_END()

    /* Successive approach method */
    while(bitMask != 0U) {
        uint8_t nextBitMask = (bitMask >> 1U);

        /* Perform a single scan */
        handle->driver->forceReConf = 1U;
        res = TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_BLOCKING, 1U);
        if(res != TSI_PASS) {
            goto RestoreContext;
        }

        /* Adjust widget idac value */
        TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                        widget->meta->sensorNum) {
            uint32_t freq;
            TSI_INFO("#%d sensor", idx);
            /* Bypass filters */
            TSI_Filter_Bypass(pSensor);
            /* Adjust idac */
            for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
                if(pSensor->rawCount[freq] > targetVal) {
                    pSensor->idac[freq] &= (~bitMask);
            }
                pSensor->idac[freq] |= nextBitMask;
                TSI_INFO("#%d idac: %d", freq, pSensor->idac[freq]);
            }
            }
        TSI_FOREACH_END()

        /* Move to next bit */
        bitMask >>= 1U;
    }

    /* Refresh rawcount */
    handle->driver->forceReConf = 1U;
    res = TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_BLOCKING, 1U);
    if(res != TSI_PASS) {
        goto RestoreContext;
    }
    /* Bypass filters */
    TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                    widget->meta->sensorNum) {
        TSI_Filter_Bypass(pSensor);
    }
    TSI_FOREACH_END()

RestoreContext:
    /* Restore rumtime context ----------------------------------------------*/
    widget->enable = widgetEnable;
    handle->driver->scanGroups = groupList;
    handle->driver->scanGroupNum = groupNum;
    handle->driver->forceReConf = 1U;

    TSI_DEBUG("<<< TSI_TuneMutualCapWidgetIDACCode <ret=%d>", res);

    return res;
}
