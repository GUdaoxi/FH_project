#include "tsi.h"
#include "tsi_driver.h"
#include "tsi_calibration.h"
#include "tsi_utils.h"
#include "tsi_filter.h"
#include "tsi_plugin.h"
#include "fm33fh0xx_fl.h"
#include "main.h"
/* Private function prototypes ----------------------------------------------*/
TSI_STATIC void TSI_HandleCommand(TSI_LibHandleTypeDef *handle);
TSI_STATIC TSI_RetCode TSI_ScanAndInitSelfCapWidget(TSI_LibHandleTypeDef *handle,
        TSI_SelfCapWidgetTypeDef *scWidget);
TSI_STATIC TSI_RetCode TSI_ScanAndInitMutualCapWidget(TSI_LibHandleTypeDef *handle,
        TSI_MutualCapWidgetTypeDef *mcWidget);

/* API implementations ------------------------------------------------------*/
#ifdef TSI_NO_RAM_INIT
void TSI_ResetLibHandle(TSI_LibHandleTypeDef *handle)
{
    memcpy(handle, &TSI_LibHandleConstInit, sizeof(TSI_LibHandleTypeDef));
}
#endif

TSI_RetCode TSI_Init(TSI_LibHandleTypeDef *handle)
{
    TSI_RetCode res;

    /* Lib status check */
    if(handle->status == TSI_LIB_INIT) {
        /* Already initialized */
        return TSI_PASS;
    }

    if(handle->status != TSI_LIB_RESET) {
        /* Deinit before init. No need to call TSI_Plugin_Init() because
           plugin callback dispatcher must have been initialized before entering
           this branch. */
        (void)TSI_DeInit(handle);
    }

    /* Init objects */
    TSI_InitObjects(handle);

#if (TSI_USE_PLUGIN == 1U)
    /* Init plugin callback dispatcher */
    TSI_Plugin_Init(handle);
#endif

    /* Init driver */
    res = TSI_Drv_Init(handle->driver);
    if(res != TSI_PASS) {
        return res;
    }

#if ((TSI_SC_CALIB_METHOD != TSI_SC_CALIB_NONE) ||  \
     (TSI_MC_CALIB_METHOD != TSI_MC_CALIB_NONE))
    /* Calibration (Will also perform an initial scan) */
    res = TSI_CalibrateAllWidgets(handle);
    if(res != TSI_PASS) {
        return res;
    }
#else
    /* Perform an initial scan */
    res = TSI_ScanAndInitAllWidgets(handle);
    if(res != TSI_PASS) {
        return res;
    }
#endif

#if (TSI_USE_TIMEBASE == 1U)
    /* Init timer context */
    handle->timerContext->context = handle;
    handle->timerContext->timeBaseTick = 0UL;
    handle->timerContext->head = NULL;
#if (TSI_SCAN_USE_TIMEBASE == 1U)
    /* Init scan interval timer */
    TSI_InitTimer(handle->timerContext, handle->scanIntvTimer,
                  TSI_SCAN_PERIOD_TICK, TSI_ScanIntvTimeout);
#endif  /* TSI_SCAN_USE_TIMEBASE == 1U */
#endif  /* TSI_USE_TIMEBASE == 1U */

    /* Call user callback */
    if(handle->cb.initCompleted != NULL) {
        handle->cb.initCompleted(handle);
    }

    /* Update status and return */
    handle->status = TSI_LIB_INIT;

    return TSI_PASS;
}

TSI_RetCode TSI_DeInit(TSI_LibHandleTypeDef *handle)
{
    /* Stop the scan */
    (void) TSI_Suspend(handle);

    if(!((handle->command.map.cmdCode == TSI_CMD_INIT) &&
            (handle->command.map.execStat == 2U))) {
        /* Reset command params */
        memset(handle->command.buffer, 0U, sizeof(handle->command));
    }

    /* Deinit driver */
    TSI_Drv_DeInit(handle->driver);

    /* Call user callback */
    if(handle->cb.deInitCompleted != NULL) {
        handle->cb.deInitCompleted(handle);
    }

    return TSI_PASS;
}

TSI_RetCode TSI_Start(TSI_LibHandleTypeDef *handle)
{
    TSI_RetCode res;

    /* Check lib status */
    if(handle->status != TSI_LIB_SUSPEND &&
            handle->status != TSI_LIB_INIT) {
        /* Unsupported operation in current status */
        return TSI_UNSUPPORTED;
    }
    else if(handle->status == TSI_LIB_RUNNING) {
        /* Already started */
        return TSI_PASS;
    }

    /* Start scan */
#if (!((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U)))
    res = TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_IT, 1U);
#else
    res = TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_DMA, 1U);
#endif
    if(res != TSI_PASS) {
        return res;
    }

#if ((TSI_USE_TIMEBASE == 1U) && (TSI_SCAN_USE_TIMEBASE == 1U))
    /* Start scan interval timer */
    TSI_StartTimer(handle->scanIntvTimer);
#endif

    /* Update status */
    handle->status = TSI_LIB_RUNNING;

    /* Call user callback */
    if(handle->cb.started != NULL) {
        handle->cb.started(handle);
    }

    return TSI_PASS;
}

TSI_RetCode TSI_Suspend(TSI_LibHandleTypeDef *handle)
{
    TSI_RetCode res;

    /* Check lib status */
    if(handle->status != TSI_LIB_RUNNING) {
        /* Unsupported operation in current status */
        return TSI_UNSUPPORTED;
    }
    else if(handle->status == TSI_LIB_SUSPEND) {
        /* Already suspended */
        return TSI_PASS;
    }

#if ((TSI_USE_TIMEBASE == 1U) && (TSI_SCAN_USE_TIMEBASE == 1U))
    /* Stop scan interval timer */
    TSI_StopTimer(handle->scanIntvTimer);
#endif

    /* Stop scan */
    res = TSI_Drv_StopScan(handle->driver);
    if(res != TSI_PASS) {
        return res;
    }

    /* Update status */
    handle->status = TSI_LIB_SUSPEND;

    /* Call user callback */
    if(handle->cb.stopped != NULL) {
        handle->cb.stopped(handle);
    }

    return TSI_PASS;
}

TSI_RetCode TSI_Resume(TSI_LibHandleTypeDef *handle)
{
    TSI_RetCode res;

    /* Check lib status */
    if(handle->status != TSI_LIB_SUSPEND) {
        /* Unsupported operation in current status */
        return TSI_UNSUPPORTED;
    }
    else if(handle->status == TSI_LIB_RUNNING) {
        /* Already started */
        return TSI_PASS;
    }

    /* Start scan */
#if (!((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U)))
    res = TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_IT, 1U);
#else
    res = TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_DMA, 1U);
#endif
    if(res != TSI_PASS) {
        return res;
    }

#if ((TSI_USE_TIMEBASE == 1U) && (TSI_SCAN_USE_TIMEBASE == 1U))
    /* Start scan interval timer */
    TSI_StartTimer(handle->scanIntvTimer);
#endif

    /* Update status and return */
    handle->status = TSI_LIB_RUNNING;

    /* Call user callback */
    if(handle->cb.started != NULL) {
        handle->cb.started(handle);
    }

    return TSI_PASS;
}

TSI_RetCode TSI_ScanAndInitWidget(TSI_LibHandleTypeDef *handle,
                                  TSI_WidgetTypeDef *widget)
{
    uint8_t widgetEnable;
    TSI_ScanGroupTypeDef *groupList;
    uint8_t groupNum;
    TSI_RetCode res;

    /* Save driver context */
    groupList = handle->driver->scanGroups;
    groupNum = handle->driver->scanGroupNum;

    /* Save widget context */
    widgetEnable = widget->enable;

    /* Enable widget */
    widget->enable = TSI_WIDGET_ENABLE;

    if(TSI_WIDGET_IS_SELF_CAP(widget)) {
        res = TSI_ScanAndInitSelfCapWidget(handle, (TSI_SelfCapWidgetTypeDef *)widget);
    }
    else if(TSI_WIDGET_IS_MUTUAL_CAP(widget)) {
        res = TSI_ScanAndInitMutualCapWidget(handle, (TSI_MutualCapWidgetTypeDef *)widget);
    }
    else {
        /* Cannot be here */
        TSI_ASSERT(0U);
        return TSI_ERROR;
    }

    /* Restore context, and force device driver to refresh internal data. */
    widget->enable = widgetEnable;
    handle->driver->scanGroups = groupList;
    handle->driver->scanGroupNum = groupNum;
    handle->driver->forceReConf = 1U;

    return res;
}

TSI_RetCode TSI_ScanAndInitAllWidgets(TSI_LibHandleTypeDef *handle)
{
    TSI_RetCode res;
    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        res = TSI_ScanAndInitWidget(handle, *ppWidget);
        if(res != TSI_PASS) {
            return res;
        }
    }
    TSI_FOREACH_END()
    return TSI_PASS;
}

void TSI_Handler(TSI_LibHandleTypeDef *handle)
{
    /* Library should be in running mode. */
    if(handle->status == TSI_LIB_RUNNING) {
#if (TSI_USED_IN_LPM_MODE == 1U)
        if(handle->isLPM != 0U) {
            /* Library is in LPM mode, user shall call TSI_LPMBlockHandler() instead. */
            return;
        }
#endif  /* TSI_USED_IN_LPM_MODE == 1U */
        /* Check if scan is completed */
        if(TSI_DRV_GET_STAT(handle->driver, TSI_DRV_STAT_SCAN_CPLT) != 0U) {
            /* Update widget status */
            TSI_Widget_UpdateAll(handle);
                                                if(TSI_SensorList.Button0->status==1)
						{
							FL_GPIO_ResetOutputPin(GPIOD,FL_GPIO_PIN_9); 
							
						}
						else if(TSI_SensorList.Button1->status==1)
						{
							FL_GPIO_ResetOutputPin(GPIOD,FL_GPIO_PIN_10);
						}
						else if(TSI_SensorList.Button2->status==1)
						{
							FL_GPIO_ResetOutputPin(GPIOG,FL_GPIO_PIN_2);
						}
						else if(TSI_SensorList.Button3->status==1)
						{
							FL_GPIO_ResetOutputPin(GPIOD,FL_GPIO_PIN_9);
						}
						else if(TSI_SensorList.Button4->status==1)
						{
							FL_GPIO_ResetOutputPin(GPIOD,FL_GPIO_PIN_9);
						}
						else if(TSI_SensorList.Button5->status==1)
						{
							FL_GPIO_ResetOutputPin(GPIOD,FL_GPIO_PIN_9);
						}
						else if(TSI_SensorList.Button6->status==1)
						{
							FL_GPIO_ResetOutputPin(GPIOD,FL_GPIO_PIN_9);
						}
						else if(TSI_SensorList.Button7->status==1)
						{
							FL_GPIO_ResetOutputPin(GPIOD,FL_GPIO_PIN_9);
						}
						else
						{
						  FL_GPIO_SetOutputPin(GPIOD,FL_GPIO_PIN_9);
							FL_GPIO_SetOutputPin(GPIOD,FL_GPIO_PIN_10);
							FL_GPIO_SetOutputPin(GPIOG,FL_GPIO_PIN_2);
						}
                                                
            /* End of processing */
            TSI_DRV_CLR_STAT(handle->driver, TSI_DRV_STAT_SCAN_CPLT);

            /* Call user callback */
            TSI_WidgetUpdateCpltCallback(handle);

#if ((TSI_USE_TIMEBASE == 0U) || ((TSI_USE_TIMEBASE == 1U) && (TSI_SCAN_USE_TIMEBASE == 0U)))
            /* Start next scan. If any error occurred, driver will
            stop scan and set error flag(s), which will be
            processed later. */
#if (!((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U)))
            (void) TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_IT, 1U);
#else
            (void) TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_DMA, 1U);
#endif  /* !((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U)) */
#endif  /* (TSI_USE_TIMEBASE == 0U) || ((TSI_USE_TIMEBASE == 1U) && (TSI_SCAN_USE_TIMEBASE == 0U)) */
        }

#if ((TSI_USE_TIMEBASE == 1U) && (TSI_SCAN_USE_TIMEBASE == 1U))
        if(handle->scanIntvFlag != 0U) {
            /* Scan interval reached. */
            handle->scanIntvFlag = 0U;

            /* Start next scan. If any error occurred, driver will
            stop scan and set error flag(s), which will be
            processed later. */
#if (!((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U)))
            (void) TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_IT, 1U);
#else
            (void) TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_DMA, 1U);
#endif  /* !((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U)) */
        }
#endif  /* (TSI_USE_TIMEBASE == 1U) && (TSI_SCAN_USE_TIMEBASE == 1U) */

        if(TSI_DRV_GET_STAT(handle->driver, TSI_DRV_STAT_SCAN_OVERRUN) != 0U) {
            TSI_ScanOverrunCallback(handle);
            TSI_DRV_CLR_STAT(handle->driver, TSI_DRV_STAT_SCAN_OVERRUN);
        }

        if(TSI_DRV_GET_STAT(handle->driver, TSI_DRV_STAT_SCAN_ERROR) != 0U) {
            TSI_ScanErrorCallback(handle);
            TSI_DRV_CLR_STAT(handle->driver, TSI_DRV_STAT_SCAN_ERROR);
        }
    }

#if (TSI_USE_TIMEBASE == 1U)
    /* Handle software timer. */
    TSI_TimerHandler(handle->timerContext);
#endif

    /* Handle command. */
    TSI_HandleCommand(handle);
}

#if (TSI_USE_TIMEBASE == 1U)
void TSI_IncTick(TSI_LibHandleTypeDef *handle, uint32_t tick)
{
    TSI_IncTimerTick(handle->timerContext, tick);
}

uint32_t TSI_GetTick(TSI_LibHandleTypeDef *handle)
{
    return TSI_GetTimerTick(handle->timerContext);
}

#if (TSI_SCAN_USE_TIMEBASE == 1U)
void TSI_ScanIntvTimeout(void *context)
{
    /* Notify the library to start next scan. */
    TSI_LibHandleTypeDef *handle = (TSI_LibHandleTypeDef *) context;
    handle->scanIntvFlag = 1U;
}
#endif  /* TSI_SCAN_USE_TIMEBASE == 1U */
#endif  /* TSI_USE_TIMEBASE == 1U */

#if (TSI_USED_IN_LPM_MODE == 1U)
void TSI_EnterLPM(TSI_LibHandleTypeDef *handle)
{
    if(handle->isLPM == 1U) {
        /* Already in LPM mode. */
        return;
    }

#if ((TSI_USE_TIMEBASE == 1U) && (TSI_SCAN_USE_TIMEBASE == 1U))
    /* Stop scan interval timer */
    TSI_StopTimer(handle->scanIntvTimer);
#endif

    if(handle->status == TSI_LIB_RUNNING) {
        /* Stop scan */
        (void) TSI_Drv_StopScan(handle->driver);
    }

    /* Prepare TSI instance for LPM mode */
    TSI_Dev_EnterLPM(handle->driver);

    /* Set LPM flag. */
    handle->isLPM = 1U;
}

void TSI_LeaveLPM(TSI_LibHandleTypeDef *handle)
{
    if(handle->isLPM == 0U) {
        /* Not in LPM mode. */
        return;
    }

    /* Recover TSI instance from LPM mode */
    TSI_Dev_LeaveLPM(handle->driver);

    if(handle->status == TSI_LIB_RUNNING) {
        /* Start scan */
#if (!((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U)))
        (void) TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_IT, 1U);
#else
        (void) TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_DMA, 1U);
#endif
    }
#if ((TSI_USE_TIMEBASE == 1U) && (TSI_SCAN_USE_TIMEBASE == 1U))
    /* Start scan interval timer */
    TSI_StartTimer(handle->scanIntvTimer);
#endif

    /* Clear LPM flag. */
    handle->isLPM = 0U;
}

void TSI_LPMBlockHandler(TSI_LibHandleTypeDef *handle)
{
    int i;

    /* Library should be in running mode. */
    if(handle->status == TSI_LIB_RUNNING) {
        if(handle->isLPM == 0U) {
            /* Library is not in LPM mode, user shall call TSI_Handler() instead. */
            return;
        }

        /* Device recover from LPM mode */
        TSI_Dev_LeaveLPM(handle->driver);

        /* Perform scan */
        for(i = 0; i < TSI_LPM_SCAN_NUM; i++) {
            if(TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_BLOCKING, 1U) != TSI_PASS) {
                return;
            }
        }

        /* Device enter LPM mode */
        TSI_Dev_EnterLPM(handle->driver);

        /* Update widget status */
        TSI_Widget_UpdateAll(handle);

        /* Call user callback */
        TSI_WidgetUpdateCpltCallback(handle);
    }
}
#endif  /* TSI_USED_IN_LPM_MODE == 1U */

/* Private function implemenations ------------------------------------------*/
TSI_STATIC void TSI_HandleCommand(TSI_LibHandleTypeDef *handle)
{
    uint8_t execStat = handle->command.map.execStat;
    uint8_t cmdCode = handle->command.map.cmdCode;
    uint16_t param0 = ((uint16_t)handle->command.map.param0Hi << 8U) |
                      (handle->command.map.param0Lo);
    uint8_t param1 = handle->command.map.param1;
    uint8_t result = 0U;
    TSI_RetCode retCode;

    if(execStat == 1U) {
        /* New command */
        /* Check command code */
        switch(cmdCode) {
            case TSI_CMD_START:
                result = (uint8_t) TSI_Resume(handle);
                execStat = 0U;
                break;

            case TSI_CMD_STOP:
                result = (uint8_t) TSI_Suspend(handle);
                execStat = 0U;
                break;

            case TSI_CMD_GET_STAT:
                result = handle->status;
                execStat = 0U;
                break;

            case TSI_CMD_INIT:
                execStat = 2U;
                break;

            case TSI_CMD_RECONFIG:
                retCode = TSI_Suspend(handle);
                if(retCode != TSI_PASS) {
                    result = (uint8_t) retCode;
                    execStat = 0U;
                    break;
                }
#if ((TSI_SC_CALIB_METHOD != TSI_SC_CALIB_NONE) ||  \
     (TSI_MC_CALIB_METHOD != TSI_MC_CALIB_NONE))
                /* Calibration (Will also perform an initial scan) */
                retCode = TSI_CalibrateAllWidgets(handle);
                if(retCode != TSI_PASS) {
                    result = (uint8_t) retCode;
                    execStat = 0U;
                    break;
                }
#else
                /* Perform an initial scan */
                retCode = TSI_ScanAndInitAllWidgets(handle);
                if(retCode != TSI_PASS) {
                    result = (uint8_t) retCode;
                    execStat = 0U;
                    break;
                }
#endif
                result = (uint8_t) TSI_Resume(handle);
                execStat = 0U;
                break;

            case TSI_CMD_RECONFIG_NO_CALIB:
                retCode = TSI_Suspend(handle);
                if(retCode != TSI_PASS) {
                    result = (uint8_t) retCode;
                    execStat = 0U;
                    break;
                }
                /* Perform an initial scan */
                retCode = TSI_ScanAndInitAllWidgets(handle);
                if(retCode != TSI_PASS) {
                    result = (uint8_t) retCode;
                    execStat = 0U;
                    break;
                }
                result = (uint8_t) TSI_Resume(handle);
                execStat = 0U;
                break;

            case TSI_CMD_GET_CFG_DESC_ADDR: {
#if (TSI_USE_CONFIG_DESCRIPTOR == 1U)
                uint8_t *pExData = handle->command.map.exData;
                uint32_t tmp = (uint32_t)TSI_ConfDesc;
                result = 1U;
                *pExData++ = (uint8_t)((tmp & 0xFF000000UL) >> 24U);
                *pExData++ = (uint8_t)((tmp & 0x00FF0000UL) >> 16U);
                *pExData++ = (uint8_t)((tmp & 0x0000FF00UL) >> 8U);
                *pExData = (uint8_t)(tmp & 0x000000FFUL);
                execStat = 0U;
#else
                result = 0U;
                execStat = 0U;
#endif  /* TSI_USE_CONFIG_DESCRIPTOR == 1U */
            }
            break;

            case TSI_CMD_GET_WIDGET_LIST_ADDR: {
                uint8_t *pExData = handle->command.map.exData;
                uint32_t tmp = (uint32_t)handle->widgets;
                *pExData++ = (uint8_t)((tmp & 0xFF000000UL) >> 24U);
                *pExData++ = (uint8_t)((tmp & 0x00FF0000UL) >> 16U);
                *pExData++ = (uint8_t)((tmp & 0x0000FF00UL) >> 8U);
                *pExData = (uint8_t)(tmp & 0x000000FFUL);
                execStat = 0U;
            }
            break;

            case TSI_CMD_GET_SENSOR_LIST_ADDR: {
                uint8_t *pExData = handle->command.map.exData;
                uint32_t tmp = (uint32_t)handle->driver->sensors;
                *pExData++ = (uint8_t)((tmp & 0xFF000000UL) >> 24U);
                *pExData++ = (uint8_t)((tmp & 0x00FF0000UL) >> 16U);
                *pExData++ = (uint8_t)((tmp & 0x0000FF00UL) >> 8U);
                *pExData = (uint8_t)(tmp & 0x000000FFUL);
                execStat = 0U;
            }
            break;

            case TSI_CMD_CTRL_SCAN:
                /* Check if library has stopped. */
                if(handle->status == TSI_LIB_RUNNING) {
                    execStat = 3U;
                    break;
                }
                if(param0 == 0U) {
                    /* Blocking scan */
                    result = (uint8_t) TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_BLOCKING, 1U);
                    execStat = 0U;
                }
                else if(param0 == 1U) {
                    /* Non-blocking scan */
#if (!((TSI_USE_DMA == 1U) && (TSI_DEV_SUPPORT_DMA == 1U)))
                    result = (uint8_t) TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_IT, param1);
#else
                    result = (uint8_t) TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_DMA, param1);
#endif
                    /* Wait until completed. */
                    execStat = 2U;
                }
                else if(param0 == 2U) {
                    /* Stop scan */
                    result = (uint8_t) TSI_Drv_StopScan(handle->driver);
                    execStat = 0U;
                }
                break;

            case TSI_CMD_GET_SCAN_STAT:
                result = handle->driver->status;
                execStat = 0U;
                break;

            case TSI_CMD_ENABLE_WIDGET:
                /* Check if library has stopped. */
                if(handle->status == TSI_LIB_RUNNING) {
                    execStat = 3U;
                    break;
                }
                if(param0 >= handle->widgetNum) {
                    /* Invalid index */
                    execStat = 3U;
                    break;
                }
                result = (uint8_t) TSI_Widget_Enable(handle, handle->widgets[param0]);
                execStat = 0U;
                break;

            case TSI_CMD_ENABLE_ALL_WIDGET:
                /* Check if library has stopped. */
                if(handle->status == TSI_LIB_RUNNING) {
                    execStat = 3U;
                    break;
                }
                result = (uint8_t) TSI_Widget_EnableAll(handle);
                execStat = 0U;
                break;

            case TSI_CMD_DISABLE_WIDGET:
                /* Check if library has stopped. */
                if(handle->status == TSI_LIB_RUNNING) {
                    execStat = 3U;
                    break;
                }
                if(param0 >= handle->widgetNum) {
                    /* Invalid index */
                    execStat = 3U;
                    break;
                }
                result = (uint8_t) TSI_Widget_Disable(handle, handle->widgets[param0]);
                execStat = 0U;
                break;

            case TSI_CMD_DISABLE_ALL_WIDGET:
                /* Check if library has stopped. */
                if(handle->status == TSI_LIB_RUNNING) {
                    execStat = 3U;
                    break;
                }
                result = (uint8_t) TSI_Widget_DisableAll(handle);
                execStat = 0U;
                break;

            case TSI_CMD_INIT_WIDGET:
                if(param0 >= handle->widgetNum) {
                    /* Invalid index */
                    execStat = 3U;
                    break;
                }
                result = (uint8_t) TSI_Widget_Init(handle, handle->widgets[param0]);
                execStat = 0U;
                break;

            case TSI_CMD_INIT_ALL_WIDGET:
                result = (uint8_t) TSI_Widget_InitAll(handle);
                execStat = 0U;
                break;

            case TSI_CMD_UPDATE_ALL_WIDGET:
                /* Check if library has stopped. */
                if(handle->status == TSI_LIB_RUNNING) {
                    execStat = 3U;
                    break;
                }
                TSI_Widget_UpdateAll(handle);
                execStat = 0U;
                break;

            case TSI_CMD_CALIB_WIDGET: {
                TSI_WidgetTypeDef *widget;
                /* Check if library has stopped. */
                if(handle->status == TSI_LIB_RUNNING) {
                    execStat = 3U;
                    break;
                }
                if(param0 >= handle->widgetNum) {
                    /* Invalid index */
                    execStat = 3U;
                    break;
                }
                widget = (TSI_WidgetTypeDef *)handle->widgets[param0];
                if(TSI_WIDGET_IS_SELF_CAP(widget)) {
                    uint8_t method = TSI_SC_CALIB_METHOD;
                    if((param1 & 0x0FU) != 0U) { method = param1 & 0x0FU; }
                    result = (uint8_t) TSI_CalibrateSelfCapWidget(handle, widget, method);
                    execStat = 0U;
                }
                else if(TSI_WIDGET_IS_MUTUAL_CAP(widget)) {
                    uint8_t method = TSI_MC_CALIB_METHOD;
                    if(((param1 & 0xF0U) >> 4U) != 0U) { method = ((param1 & 0xF0U) >> 4U); }
                    result = (uint8_t) TSI_CalibrateMutualCapWidget(handle, widget, method);
                    execStat = 0U;
                }
                else {
                    /* Cannot be here. */
                    execStat = 3U;
                }
            }
            break;

            case TSI_CMD_CALIB_ALL_WIDGET: {
                execStat = 0U;
                /* Check if library has stopped. */
                if(handle->status == TSI_LIB_RUNNING) {
                    execStat = 3U;
                    break;
                }

                TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                                handle->widgetNum) {
                    if(TSI_WIDGET_IS_SELF_CAP(*ppWidget)) {
                        uint8_t method = TSI_SC_CALIB_METHOD;
                        if((param0 & 0x0FU) != 0U) { method = param0 & 0x0FU; }
                        result = (uint8_t) TSI_CalibrateSelfCapWidget(handle, *ppWidget, method);
                        if(result != TSI_PASS) {
                            execStat = 3U;
                            break;
                        }
                    }
                    else if(TSI_WIDGET_IS_MUTUAL_CAP(*ppWidget)) {
                        uint8_t method = TSI_MC_CALIB_METHOD;
                        if(((param0 & 0xF0U) >> 4U) != 0U) { method = ((param0 & 0xF0U) >> 4U); }
                        result = (uint8_t) TSI_CalibrateMutualCapWidget(handle, *ppWidget, method);
                        if(result != TSI_PASS) {
                            execStat = 3U;
                            break;
                        }
                    }
                    else {
                        /* Cannot be here. */
                        execStat = 3U;
                        break;
                    }
                }
                TSI_FOREACH_END()
            }
            break;

            case TSI_CMD_CALC_SENSOR_CAP: {
                TSI_SensorTypeDef *sensor;
                uint32_t tmp;
                uint8_t *pExData = handle->command.map.exData;
                if(param0 >= handle->driver->sensorNum) {
                    /* Invalid index */
                    execStat = 3U;
                    break;
                }
                sensor = handle->driver->sensors[param0];
                if(sensor->meta->type == TSI_SENSOR_SELF_CAP) {
                    tmp = TSI_CalcSelfCapSensorCap(&handle->driver->clocks[TSI_CLOCK_SC_IDX],
                                                   sensor, ((param1 != 0U) ? 1U : 0U));
                }
                else if(sensor->meta->type == TSI_SENSOR_MUTUAL_CAP) {
                    tmp = TSI_CalcMutualCapSensorCap(&handle->driver->clocks[TSI_CLOCK_MC_IDX],
                                                     sensor, 1U);
                }
                else {
                    /* Invalid type */
                    execStat = 3U;
                    break;
                }
                *pExData++ = (uint8_t)((tmp & 0xFF000000UL) >> 24U);
                *pExData++ = (uint8_t)((tmp & 0x00FF0000UL) >> 16U);
                *pExData++ = (uint8_t)((tmp & 0x0000FF00UL) >> 8U);
                *pExData = (uint8_t)(tmp & 0x000000FFUL);
                execStat = 0U;
            }
            break;

            case TSI_CMD_CALC_ALL_SENSOR_CAP: {
                /* Backup filtered rawCount */
                TSI_FOREACH_OBJ(TSI_SensorTypeDef **, ppSensor, handle->driver->sensors,
                                TSI_SENSOR_NUM) {
                    if((*ppSensor)->meta->type == TSI_SENSOR_SELF_CAP) {
                        (void)TSI_CalcSelfCapSensorCap(&handle->driver->clocks[TSI_CLOCK_SC_IDX],
                                                       (*ppSensor), 1U);
                    }
                    else if((*ppSensor)->meta->type == TSI_SENSOR_MUTUAL_CAP) {
                        (void)TSI_CalcMutualCapSensorCap(&handle->driver->clocks[TSI_CLOCK_MC_IDX],
                                                         (*ppSensor), 1U);
                    }
                    else {
                        /* Do nothing. */
                    }
                }
                TSI_FOREACH_END()
                execStat = 0U;
            }
            break;

            default:
                /* No such command. */
                execStat = 3U;
                break;
        }
        /* Write back */
        handle->command.map.execStat = execStat;
        handle->command.map.result = result;
    }
    else if(execStat == 2U) {
        /* Command under execution */
        switch(cmdCode) {
            case TSI_CMD_INIT:
                result = (uint8_t) TSI_Init(handle);
                execStat = 0U;
                break;

            case TSI_CMD_CTRL_SCAN:
                if(TSI_DRV_GET_STAT(handle->driver, TSI_DRV_STAT_SCAN_CPLT) != 0U) {
                    /* End of scan. */
                    execStat = 0U;
                }
                break;

            default:
                /* No such command, or command does not have waiting status. */
                execStat = 3U;
                break;
        }
        /* Write back */
        handle->command.map.execStat = execStat;
        handle->command.map.result = result;
    }
}

TSI_STATIC TSI_RetCode TSI_ScanAndInitSelfCapWidget(TSI_LibHandleTypeDef *handle,
        TSI_SelfCapWidgetTypeDef *scWidget)
{
    /*
        NOTE:
        This function will modify widget enable status and driver scanGroups and
        scanGroupNum. Please save these variables before and restore after calling
        this function.
    */
    static uint16_t tmpSCSensorList[1U] = { 0U };
    static TSI_ScanGroupTypeDef tmpSCScanGroup = {
        1U, TSI_SCAN_GROUP_SELF_CAP, 0U,
        (uint16_t *) tmpSCSensorList,
    };
    uint16_t valBuffer[TSI_TOTAL_SCAN_NUM] = { 0 };
    TSI_WidgetTypeDef *widget = (TSI_WidgetTypeDef *) scWidget;
    TSI_ScanGroupTypeDef *dediGroup;
    uint16_t realSnsNum;
    TSI_RetCode res;

    /* Enable widget */
    widget->enable = TSI_WIDGET_ENABLE;

    /* Switch scan group */
    if(widget->meta->dedicatedScanGroup == NULL) {
        /* Normal scan */
        handle->driver->scanGroups = (TSI_ScanGroupTypeDef *)&tmpSCScanGroup;
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
        uint16_t *scanBuffer = NULL;
        uint8_t scanCnt = 1U;
        int i;

        /* Configure scan group */
        tmpSCSensorList[0U] = pSensor->meta->id;
        dediGroup = pSensor->meta->dedicatedScanGroup;
        if(dediGroup != NULL) {
            /* Sensor use dedicated scan group. We should copy its option. */
            tmpSCScanGroup.opt = dediGroup->opt;
        }
        else {
            /* Sensor use default scan group. Clear option. */
            tmpSCScanGroup.opt = 0UL;
        }

        /* Call user handler to get buffer pointer and scan count */
        if(handle->cb.getInitScanBufferAndCount != NULL) {
            scanCnt = handle->cb.getInitScanBufferAndCount(handle, widget, pSensor,
                      &scanBuffer);
            if(scanCnt == 0U || scanBuffer == NULL) {
                /* Invalid scan params. */
                scanCnt = 1U;
            }
        }

        for(i = 0; i < scanCnt; i++) {
            /* Perform a single scan */
            handle->driver->forceReConf = 1U;
            res = TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_BLOCKING, 1U);
            if(res != TSI_PASS) {
                return res;
            }
            /* Bypass filter */
            TSI_Filter_Bypass(pSensor);
            /* Fill buffer */
            if(scanCnt > 1U) {
                int index = i * TSI_TOTAL_SCAN_NUM;
                int j;
                for(j = 0; j < TSI_TOTAL_SCAN_NUM; j++) {
                    scanBuffer[index + j] = pSensor->rawCount[j];
                }
            }
        }

        if(scanCnt > 1U) {
            int j;
            /* Call user handler to process values. If no user handler is
               set, use the last scan value as processed value. */
            if(handle->cb.processInitScanValue != NULL) {
                handle->cb.processInitScanValue(handle, widget, pSensor, valBuffer);
            }
            else {
                int index = (scanCnt - 1U) * TSI_TOTAL_SCAN_NUM;
                for(j = 0; j < TSI_TOTAL_SCAN_NUM; j++) {
                    valBuffer[j] = scanBuffer[index + j];
                }
            }
#if (!(TSI_NORM_FILTER_EN || TSI_PROX_FILTER_EN))
            /* Set valueBuffer to rawCount. */
            for(j = 0; j < TSI_TOTAL_SCAN_NUM; j++) {
                pSensor->rawCount[j] = valBuffer[j];
            }
#else
            /* Set valueBuffer to buffer. */
            for(j = 0; j < TSI_TOTAL_SCAN_NUM; j++) {
                pSensor->bslnVar.sensorBuffer[j] = valBuffer[j];
            }
#endif  /* !(TSI_NORM_FILTER_EN || TSI_PROX_FILTER_EN) */
        }
    }
    TSI_FOREACH_END()

    /* Init widget */
    res = TSI_Widget_Init(handle, widget);
    if(res != TSI_PASS) {
        return res;
    }

    return TSI_PASS;
}

TSI_STATIC TSI_RetCode TSI_ScanAndInitMutualCapWidget(TSI_LibHandleTypeDef *handle,
        TSI_MutualCapWidgetTypeDef *mcWidget)
{
    /*
        NOTE:
        This function will modify widget enable status and driver scanGroups and
        scanGroupNum. Please save these variables before and restore after calling
        this function.
    */
    uint16_t valBuffer[TSI_TOTAL_SCAN_NUM] = { 0 };
    uint16_t *scanBuffer = NULL;
    uint8_t scanCnt = 1U;
    int i;
    TSI_WidgetTypeDef *widget = (TSI_WidgetTypeDef *) mcWidget;
    TSI_RetCode res;

    /* Switch scan group */
    handle->driver->scanGroups = widget->meta->dedicatedScanGroup;
    handle->driver->scanGroupNum = 1U;

    /* Call user handler to get buffer pointer and scan count */
    if(handle->cb.getInitScanBufferAndCount != NULL) {
        scanCnt = handle->cb.getInitScanBufferAndCount(handle, widget, NULL, &scanBuffer);
        if(scanCnt == 0U || scanBuffer == NULL) {
            /* Invalid scan params. */
            scanCnt = 1U;
        }
    }

    for(i = 0; i < scanCnt; i++) {
        int index0 = i * widget->meta->sensorNum * TSI_TOTAL_SCAN_NUM;
        /* Perform a single scan */
        handle->driver->forceReConf = 1U;
        res = TSI_Drv_StartScan(handle->driver, TSI_DRV_SCAN_MODE_BLOCKING, 1U);
        if(res != TSI_PASS) {
            return res;
        }
        TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                        widget->meta->sensorNum) {
            /* Bypass filter */
            TSI_Filter_Bypass(pSensor);
            /* Fill buffer */
            if(scanCnt > 1U) {
                int index = index0 + (idx * TSI_TOTAL_SCAN_NUM);
                int j;
                for(j = 0; j < TSI_TOTAL_SCAN_NUM; j++) {
                    scanBuffer[index + j] = pSensor->rawCount[j];
                }
            }
        }
        TSI_FOREACH_END()
    }

    if(scanCnt > 1U) {
        int index0 = (scanCnt - 1U) * widget->meta->sensorNum * TSI_TOTAL_SCAN_NUM;
        TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                        widget->meta->sensorNum) {
            /* Call user handler to process values. If no user handler is
                set, use the last scan value as processed value. */
            if(handle->cb.processInitScanValue != NULL) {
                handle->cb.processInitScanValue(handle, widget, pSensor, valBuffer);
            }
            else {
                int index = index0 + (idx * TSI_TOTAL_SCAN_NUM);
                for(i = 0; i < TSI_TOTAL_SCAN_NUM; i++) {
                    valBuffer[i] = scanBuffer[index + i];
                }
            }
#if (!(TSI_NORM_FILTER_EN || TSI_PROX_FILTER_EN))
            /* Set valueBuffer to rawCount. */
            for(i = 0; i < TSI_TOTAL_SCAN_NUM; i++) {
                pSensor->rawCount[i] = valBuffer[i];
            }
#else
            /* Set valueBuffer to buffer. */
            for(i = 0; i < TSI_TOTAL_SCAN_NUM; i++) {
                pSensor->bslnVar.sensorBuffer[i] = valBuffer[i];
            }
#endif  /* !(TSI_NORM_FILTER_EN || TSI_PROX_FILTER_EN) */
        }
        TSI_FOREACH_END()
    }

    /* Init widget */
    res = TSI_Widget_Init(handle, widget);
    if(res != TSI_PASS) {
        return res;
    }

    return TSI_PASS;
}

/* TSI library error callbacks (Default implementations) --------------------*/
TSI_WEAK void TSI_AssertFailedCallback(uint8_t *file, uint32_t line)
{
    TSI_UNUSED(file)
    TSI_UNUSED(line)

    /* Default: Block wait. */
    while(1)
    {}
}

TSI_WEAK void TSI_TimeoutCallback(uint8_t *file, uint32_t line)
{
    TSI_UNUSED(file)
    TSI_UNUSED(line)

    /* Default: Block wait. */
    while(1)
    {}
}

TSI_WEAK void TSI_ErrorCallback(uint8_t *file, uint32_t line)
{
    TSI_UNUSED(file)
    TSI_UNUSED(line)

    /* Default: Block wait. */
    while(1)
    {}
}

TSI_WEAK void TSI_WidgetUpdateCpltCallback(TSI_LibHandleTypeDef *handle)
{
    TSI_UNUSED(handle)

    /* User can process widget status here. */
    /* Default: Do nothing. */
}

TSI_WEAK void TSI_ScanOverrunCallback(TSI_LibHandleTypeDef *handle)
{
    TSI_UNUSED(handle)

    /* Default: Do nothing. */
}

TSI_WEAK void TSI_ScanErrorCallback(TSI_LibHandleTypeDef *handle)
{
    TSI_UNUSED(handle)

    /* Enter this callback when we failed to configure a device scan,
       or scan state machine has broken. */
    /* Default: Block wait. */
    while(1)
    {}
}
