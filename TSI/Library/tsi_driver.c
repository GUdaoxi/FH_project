#include "tsi_driver.h"
#include "tsi_object.h"
#include <string.h>

/* Private function prototypes ----------------------------------------------*/
TSI_STATIC void TSI_ScanGroupFirst(TSI_DriverTypeDef *drv);
TSI_STATIC bool TSI_ScanGroupNext(TSI_DriverTypeDef *drv);
TSI_STATIC TSI_RetCode TSI_ClockSetupForCurrFreq(TSI_DriverTypeDef *drv);

/* API implementations ------------------------------------------------------*/
TSI_RetCode TSI_Drv_Init(TSI_DriverTypeDef *drv)
{
    TSI_RetCode ret = TSI_PASS;

    TSI_ASSERT(drv->scanGroups != NULL);
    TSI_ASSERT(drv->clocks != NULL);
    TSI_ASSERT(drv->ios != NULL);

    /* Init driver struct members */
    drv->status = 0U;
    drv->forceReConf = 0U;
    drv->scanGroupIdx = TSI_SCAN_GROUP_NUM;
    drv->oldScanGroupIdx = TSI_SCAN_GROUP_NUM;
    drv->freqIdx = 0U;

    /* Device init */
    ret = TSI_Dev_Init(drv);
    if(ret != TSI_PASS) {
        return ret;
    }

    /* Device IO init */
    TSI_FOREACH(const TSI_IOConfTypeDef * io, drv->ios, drv->ioNum, 0U) {
        ret = TSI_Dev_SetupPort(drv, io);
        if(ret != TSI_PASS) {
            return ret;
        }
    }
    TSI_FOREACH_END()

#if (TSI_USE_SHIELD == 1U)
    /* Shield init */
    TSI_Dev_ResetAllShields(drv);
    TSI_FOREACH(const TSI_ShieldConfTypeDef * shield, drv->shields, drv->shieldNum, 0U) {
        ret = TSI_Dev_SetupShield(drv, shield);
        if(ret != TSI_PASS) {
            return ret;
        }
    }
    TSI_FOREACH_END()
#endif

    return ret;
}

TSI_RetCode TSI_Drv_DeInit(TSI_DriverTypeDef *drv)
{
    TSI_RetCode ret = TSI_PASS;

    if(TSI_DRV_GET_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING) != 0) {
        /* Stop previous configured scan */
        ret = TSI_Drv_StopScan(drv);
        if(ret != TSI_PASS) {
            return ret;
        }
    }

    /* Deinit clock and IOs */
    (void) TSI_Dev_ResetClock(drv);
    TSI_FOREACH(const TSI_IOConfTypeDef * io, drv->ios, drv->ioNum, 0U) {
        (void) TSI_Dev_ResetPort(drv, io);
    }
    TSI_FOREACH_END()

    /* Device deinit */
    (void) TSI_Dev_Deinit(drv);

    /* Reset driver struct members */
    drv->context = NULL;
    drv->scanMode = TSI_DRV_SCAN_MODE_BLOCKING;
    drv->single = 0U;
    drv->forceReConf = 0U;
    drv->scanGroupIdx = 0U;
    drv->oldScanGroupIdx = 0U;
    drv->freqIdx = 0U;
    drv->status = 0U;

    return ret;
}

TSI_RetCode TSI_Drv_EnableWidget(TSI_DriverTypeDef *drv, struct _TSI_Widget *widget)
{
    /* Cannot enable/disable widget while scanning. */
    if(TSI_DRV_GET_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING) != 0U) {
        return TSI_ERROR;
    }

    /* Enable widget and force re-configure (in case there is only one scan group). */
    widget->enable = 1U;
    drv->forceReConf = 1U;

    return TSI_PASS;
}

TSI_RetCode TSI_Drv_DisableWidget(TSI_DriverTypeDef *drv, struct _TSI_Widget *widget)
{
    /* Cannot enable/disable widget while scanning. */
    if(TSI_DRV_GET_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING) != 0U) {
        return TSI_ERROR;
    }

    /* Disable widget and force re-configure (in case there is only one scan group). */
    widget->enable = 0U;
    drv->forceReConf = 1U;

    return TSI_PASS;
}

TSI_RetCode TSI_Drv_StartScan(TSI_DriverTypeDef *drv, TSI_DrvScanMode mode,
                              uint8_t oneShot)
{
    TSI_RetCode res;

    /* Sanity check */
    if(drv == NULL) {
        return TSI_PARAM_ERR;
    }

    /* Param check */
    if((oneShot == 0U) && (mode == TSI_DRV_SCAN_MODE_BLOCKING)) {
        /* Cannot perform a continuous blocking scan */
        return TSI_PARAM_ERR;
    }

#if (TSI_USE_DMA == 0U)
    if(mode == TSI_DRV_SCAN_MODE_DMA) {
        return TSI_PARAM_ERR;
    }
#endif

    if(TSI_DRV_GET_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING) != 0) {
        /* Previous scan is still running */
        return TSI_WAIT;
    }

    TSI_INFO("Start %s scan with mode %d",
             oneShot ? "single" : "continuous", (uint32_t)mode);

    /* Clear previous scan flags */
    drv->status = 0U;

    /* Setup params */
    drv->scanMode = mode;
    drv->single = oneShot;

    /* Index to first valid scan group. */
    TSI_ScanGroupFirst(drv);
    if(TSI_DRV_GET_STAT(drv, TSI_DRV_STAT_SCAN_EMPTY) != 0U) {
        /* Nothing to scan, suspend. */
        return TSI_PASS;
    }

#if (TSI_TOTAL_SCAN_NUM > 1U)
    /* Reset device clock to freq #0 */
    drv->freqIdx = 0U;
    res = TSI_ClockSetupForCurrFreq(drv);
    if(res != TSI_PASS) {
        return res;
    }
#endif  /* if (TSI_TOTAL_SCAN_NUM > 1U) */

    /* Setup scan group, when scan group is changed:
       NOT((old group is valid) AND (current group == old group)) */
    if(((drv->forceReConf != 0U) ||
            !((drv->oldScanGroupIdx < TSI_SCAN_GROUP_NUM) &&
              (drv->scanGroupIdx == drv->oldScanGroupIdx)))) {
        TSI_ScanGroupTypeDef *group = &drv->scanGroups[drv->scanGroupIdx];

#if (TSI_TOTAL_SCAN_NUM == 1U)
        /* Setup device clock when scan group has changed */
        res = TSI_ClockSetupForCurrFreq(drv);
        if(res != TSI_PASS) {
            return res;
        }
#endif  /* if (TSI_TOTAL_SCAN_NUM == 1U) */

        /* Setup device scan */
        res = TSI_Dev_SetupScanGroup(drv, group);
        if(res == TSI_WAIT) {
            return res;
        }
        else if(res != TSI_PASS) {
            /* Set scan error flag */
            TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_ERROR);
            return res;
        }

        drv->forceReConf = 0U;
    }

    /* Set scan running flags */
    TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING);

    /* Start scan */
    res = TSI_Dev_StartScan(drv);
    if(res != TSI_PASS) {
        /* Clear scan running flag and set scan error flag */
        TSI_DRV_CLR_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING);
        TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_ERROR);
        return res;
    }

    if(drv->scanMode == TSI_DRV_SCAN_MODE_BLOCKING) {
        /* Block wait until scan complete */
        TSI_WAIT_TIMEOUT((TSI_DRV_GET_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING) == 0U),
                         TSI_DRV_BLOCKING_TIMEOUT_VALUE) {
            return TSI_TIMEOUT;
        }
        TSI_WAIT_TIMEOUT_END()

        /* Clear flag */
        TSI_DRV_CLR_STAT(drv, TSI_DRV_STAT_SCAN_CPLT);
    }

    return TSI_PASS;
}

TSI_RetCode TSI_Drv_StopScan(TSI_DriverTypeDef *drv)
{
    /* Sanity check */
    if(drv == NULL) {
        return TSI_PARAM_ERR;
    }

    /* Stop scan and clear running flag. */
    if(TSI_DRV_GET_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING) != 0) {
        (void) TSI_Dev_StopScan(drv);
        TSI_DRV_CLR_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING);
    }

    return TSI_PASS;
}

void TSI_Drv_HandleSensorData(TSI_DriverTypeDef *drv, struct _TSI_Sensor *sensor, uint32_t data)
{
    int freqIdx;
    if(sensor->meta->type == TSI_SENSOR_MUTUAL_CAP) {
        /* Invert mutual-cap sensor rawcount */
        TSI_MutualCapWidgetTypeDef *mcWidget =
                        (TSI_MutualCapWidgetTypeDef *)sensor->meta->parent;
        data = (1UL << mcWidget->resolution) - data;
    }
    TSI_DEBUG("sensor(%s #%d, Tx%02d Rx%02d): %5d",
              (sensor->meta->type == TSI_SENSOR_SELF_CAP) ? "Self" : "Mutual",
              drv->freqIdx,
              sensor->meta->txChannel, sensor->meta->rxChannel,
              data);

    /* Write to sensor */
    freqIdx = drv->freqIdx;
    if(freqIdx < TSI_SCAN_FREQ_NUM) {
#if (TSI_NORM_FILTER_EN || TSI_PROX_FILTER_EN)
        sensor->bslnVar.sensorBuffer[freqIdx] = data;
#else
        sensor->rawCount[freqIdx] = data;
#endif  /* TSI_NORM_FILTER_EN || TSI_PROX_FILTER_EN */
    }
#if (TSI_USER_SCAN_FREQ_NUM > 0U)
    else if(freqIdx < TSI_TOTAL_SCAN_NUM) {
        sensor->bslnVar.sensorUserBuffer[freqIdx - TSI_SCAN_FREQ_NUM] = data;
    }
#endif
}

void TSI_Drv_HandleEndOfScan(TSI_DriverTypeDef *drv)
{
    TSI_RetCode res;
    bool hasNext;

#if (TSI_TOTAL_SCAN_NUM > 1U)
    drv->freqIdx++;
    if(drv->freqIdx < TSI_TOTAL_SCAN_NUM) {
        TSI_INFO("TSI_Drv_HandleEvent - Switch to freqIdx %d", drv->freqIdx);
        /* Setup device clock */
        res = TSI_ClockSetupForCurrFreq(drv);
        if(res != TSI_PASS) {
            /* Stop driver scan */
            TSI_DRV_CLR_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING);
            /* Set scan error flag */
            TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_ERROR);
        }
        /* Start scan */
        res = TSI_Dev_StartScan(drv);
        if(res != TSI_PASS) {
            /* Stop driver scan */
            TSI_DRV_CLR_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING);
            /* Set scan error flag */
            TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_ERROR);
        }
    }
    else {
        /* Reset scan freq index */
        drv->freqIdx = 0U;
#endif
        hasNext = TSI_ScanGroupNext(drv);
        if(TSI_DRV_GET_STAT(drv, TSI_DRV_STAT_SCAN_EMPTY) != 0U) {
            /* Nothing to scan, suspend.
            Will check scan empty status again when:
            1. User call TSI_Drv_EnableWidget() to enable any widget.
            2. User call TSI_Drv_StartScan().
            Shall also clear the scan running flag. */
            TSI_DRV_CLR_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING);
            return;
        }
        if(!hasNext) {
            /* Set scan completed flag */
            if(TSI_DRV_GET_STAT(drv, TSI_DRV_STAT_SCAN_CPLT) != 0U) {
                /* If previous value is not acquired by user, set the scan overrun flag. */
                TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_OVERRUN);
            }
            TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_CPLT);
            if(drv->single) {
                /* Single scan: stop running. */
                (void) TSI_Drv_StopScan(drv);
                /* Revert scan group index. */
                drv->scanGroupIdx = drv->oldScanGroupIdx;
                return;
            }
        }
        /* Start next scan */
#if(TSI_TOTAL_SCAN_NUM > 1U)
        /* Reset device clock to freq #0 */
        drv->freqIdx = 0U;
        res = TSI_ClockSetupForCurrFreq(drv);
        if(res != TSI_PASS) {
            /* Stop driver scan */
            TSI_DRV_CLR_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING);
            /* Set scan error flag */
            TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_ERROR);
            return;
        }
#endif  /* if (TSI_TOTAL_SCAN_NUM > 1U) */
        if(drv->scanGroupIdx != drv->oldScanGroupIdx) {
#if(TSI_TOTAL_SCAN_NUM == 1U)
            /* Setup device clock */
            res = TSI_ClockSetupForCurrFreq(drv);
            if(res != TSI_PASS) {
                /* Stop driver scan */
                TSI_DRV_CLR_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING);
                /* Set scan error flag */
                TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_ERROR);
                return;
            }
#endif  /* if (TSI_TOTAL_SCAN_NUM == 1U) */
            /* Setup next group configurations */
            res = TSI_Dev_SetupScanGroup(drv, &drv->scanGroups[drv->scanGroupIdx]);
            if(res != TSI_PASS) {
                /* Stop driver scan */
                TSI_DRV_CLR_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING);
                /* Set scan error flag */
                TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_ERROR);
                return;
            }
        }

        /* Start next group scan */
        res = TSI_Dev_StartScan(drv);
        if(res != TSI_PASS) {
            /* Stop driver scan */
            TSI_DRV_CLR_STAT(drv, TSI_DRV_STAT_SCAN_RUNNING);
            /* Set scan error flag */
            TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_ERROR);
        }
#if (TSI_TOTAL_SCAN_NUM > 1U)
    }
#endif
}

/* Private function implemenations ------------------------------------------*/
TSI_STATIC void TSI_ScanGroupFirst(TSI_DriverTypeDef *drv)
{
    uint8_t oldIdx = drv->scanGroupIdx;
    drv->scanGroupIdx = drv->scanGroupNum;
    TSI_INFO("TSI_ScanGroupFirst - Set old scan group: %d, current scan group: %d",
             drv->oldScanGroupIdx,
             drv->scanGroupIdx);
    (void)TSI_ScanGroupNext(drv);
    drv->oldScanGroupIdx = oldIdx;
}

TSI_STATIC bool TSI_ScanGroupNext(TSI_DriverTypeDef *drv)
{
    uint8_t oldIdx = drv->scanGroupIdx;
    uint8_t currIdx = oldIdx + 1U;
    bool isOldIdxValid = true;
    bool isGroupEnd = false;

    if(oldIdx >= drv->scanGroupNum) {
        isOldIdxValid = false;
        currIdx = 0U;
    }
    else if(currIdx >= drv->scanGroupNum) {
        isGroupEnd = true;
        currIdx = 0U;
    }

    TSI_INFO("TSI_ScanGroupNext - Old scan group %d is %s",
             oldIdx,
             isOldIdxValid ? "Valid" : "Invalid");

    while(1) {
        const TSI_ScanGroupTypeDef *group = &drv->scanGroups[currIdx];
        bool isEnabled = false;

        /* Determine whether the scan group is enabled or not by sensor enable status.
           Sensors are in enable status when their parent widget is in enable status. */
        if(group->type == TSI_SCAN_GROUP_SELF_CAP) {
            /* Self-cap scan group. Become disable only when no sensor is invalid. */
            TSI_FOREACH_OBJ(uint16_t *, snsId, group->sensors, group->size) {
                if(TSI_SensorPointers[*snsId]->meta->parent->enable == 1U) {
                    isEnabled = true;
                    break;
                }
            }
            TSI_FOREACH_END()
        }
        else if(group->type == TSI_SCAN_GROUP_SELF_CAP_PARALLEL) {
            /* Self-cap parallel scan group. Become disable when FIRST sensor (the main sensor)
            is invalid. Other sensors are ignorred. */
            if(TSI_SensorPointers[group->sensors[0]]->meta->parent->enable != 0U) {
                isEnabled = true;
            }
        }
        else if(group->type == TSI_SCAN_GROUP_MUTUAL_CAP) {
            /* Mutual-cap scan group. Become disable when FIRST sensor is invalid because a
               mutual-cap scan group MUST represent all of (or a part of) a single mutual-cap
               widget.
               If users want to disable some TX/RX, they can change the mutual-cap widget
               configurations. */
            if(TSI_SensorPointers[group->sensors[0]]->meta->parent->enable != 0U) {
                isEnabled = true;
            }
        }
        else {
            /* Cannot be here */
            TSI_ASSERT(0U);
        }
        TSI_INFO("TSI_ScanGroupNext - Group %d: %s",
                 currIdx, isEnabled ? "Yes" : "No");
        if(isEnabled) { break; }
        currIdx++;
        if(currIdx == oldIdx) {
            if(currIdx >= drv->scanGroupNum) {
                isGroupEnd = true;
            }
            break;
        }
        else if(currIdx >= drv->scanGroupNum) {
            isGroupEnd = true;
            currIdx = 0U;
        }
    }

    TSI_INFO("TSI_ScanGroupNext - Group end: %s",
             isGroupEnd ? "Yes" : "No");

    if(currIdx == oldIdx) {
        if(!isOldIdxValid) {
            /* No valid scan group. Set the scan empty flag and reset the index. */
            currIdx = drv->scanGroupNum;
            TSI_DRV_SET_STAT(drv, TSI_DRV_STAT_SCAN_EMPTY);
            TSI_DEBUG("TSI_ScanGroupNext - No valid scan group");
        }
    }

    /* Update scan group index */
    drv->oldScanGroupIdx = drv->scanGroupIdx;
    drv->scanGroupIdx = currIdx;
    TSI_INFO("TSI_ScanGroupNext - Change current scan group from %d to %d",
             drv->oldScanGroupIdx, drv->scanGroupIdx);
    return (!isGroupEnd);
}

TSI_STATIC TSI_RetCode TSI_ClockSetupForCurrFreq(TSI_DriverTypeDef *drv)
{
    TSI_ScanGroupTypeDef *group = &drv->scanGroups[drv->scanGroupIdx];
    TSI_RetCode res;

    if(group->type == TSI_SCAN_GROUP_SELF_CAP || group->type == TSI_SCAN_GROUP_SELF_CAP_PARALLEL) {
        res = TSI_Dev_SetupClock(drv, &drv->clocks[TSI_CLOCK_SC_IDX + drv->freqIdx]);
    }
    else if(group->type == TSI_SCAN_GROUP_MUTUAL_CAP) {
        res = TSI_Dev_SetupClock(drv, &drv->clocks[TSI_CLOCK_MC_IDX + drv->freqIdx]);
    }
    else {
        /* Not implemented */
        res = TSI_UNSUPPORTED;
    }

    return res;
}
