#include "tsi_object.h"
#include "tsi_processing.h"
#include "tsi_driver.h"
#include "tsi.h"
#include "tsi_plugin.h"

/* Configurations -----------------------------------------------------------*/
/** Plugin version string. */
#define TSI_PLUGIN_VERSION                  "v1.1"

/* USER CONFIGURATION BEGIN */
/** Plugin call priority(0-7). Lower value means higher priority. */
#define TSI_PLUGIN_PRIORITY                 "1"

/** Widget active timeout (in tick). */
#define TSI_WIDGET_ACTIVE_TIMEOUT               (15000U)

/** Sensor not active but has diff timeout (in tick). */
#define TSI_SENSOR_NOT_ACTIVE_DIFF_TIMEOUT      (5000U)
/* USER CONFIGURATION END */
/* Defines ------------------------------------------------------------------*/

/* Function prototypes ------------------------------------------------------*/

/* Variables ----------------------------------------------------------------*/
static uint32_t oldTick;
static uint32_t activeTimeoutCounter[TSI_WIDGET_NUM];
static uint32_t diffTimeoutCounter[TSI_SENSOR_NUM];

/* Function implementations -------------------------------------------------*/
static void TSI_InitCompletedCallback(TSI_LibHandleTypeDef *handle)
{
    oldTick = 0U;
    memset(activeTimeoutCounter, 0, TSI_WIDGET_NUM * sizeof(uint32_t));
    memset(diffTimeoutCounter, 0, TSI_SENSOR_NUM * sizeof(uint32_t));
}

static void TSI_Widget_StatusUpdateCallback(TSI_LibHandleTypeDef *handle)
{
    /* Calculate interval */
    uint32_t currTick = TSI_GetTick(handle);
    uint32_t interval = currTick - oldTick;
    oldTick = currTick;

    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        if((*ppWidget)->enable == TSI_WIDGET_ENABLE) {
            uint16_t realSnsNum;
            if(TSI_WIDGET_IS_SELF_CAP((*ppWidget)) && (*ppWidget)->meta->dedicatedScanGroup != NULL) {
                realSnsNum = 1U;
            }
#if (TSI_WIDGET_SC_TOUCHPAD_USED == 1U)
            else if((*ppWidget)->meta->type == TSI_WIDGET_SELF_CAP_TOUCHPAD) {
                TSI_MetaWidgetTypeDef *meta = (TSI_MetaWidgetTypeDef *)(*ppWidget)->meta;
                realSnsNum = meta->sensorNum + ((TSI_Meta2DWidgetTypeDef *)meta)->sensorRowNum;
            }
#endif
            else {
                realSnsNum = (*ppWidget)->meta->sensorNum;
            }

            if((*ppWidget)->status) {
                activeTimeoutCounter[idx] += interval;
                TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, (*ppWidget)->meta->sensors,
                                realSnsNum) {
                    int diffIdx = pSensor->meta->id;
                    diffTimeoutCounter[diffIdx] = 0U;
                }
                TSI_FOREACH_END()
                if(activeTimeoutCounter[idx] >= TSI_WIDGET_ACTIVE_TIMEOUT) {
                    activeTimeoutCounter[idx] = 0U;
                    TSI_Widget_Init(handle, (*ppWidget));
                }
            }
            else {
                TSI_DetectConfTypeDef *widgetDetConf = &(*ppWidget)->detConf;

                /* Clear active timeout. */
                activeTimeoutCounter[idx] = 0U;

                /* Detect sensors which diffCount > 0 but not active. */
                TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, (*ppWidget)->meta->sensors,
                                realSnsNum) {
                    int diffIdx = pSensor->meta->id;
                    if(pSensor->diffCount > 0) {
                        diffTimeoutCounter[diffIdx] += interval;
                        if(diffTimeoutCounter[diffIdx] >= TSI_SENSOR_NOT_ACTIVE_DIFF_TIMEOUT) {
                            TSI_DetectConfTypeDef *detConf;
                            diffTimeoutCounter[diffIdx] = 0U;
                            detConf = pSensor->meta->detConf;
                            if(detConf == NULL) { detConf = widgetDetConf; }
                            TSI_Sensor_Init(pSensor, detConf);
                        }
                    }
                    else {
                        diffTimeoutCounter[diffIdx] = 0U;
                    }
                }
                TSI_FOREACH_END()
            }
        }
    }
    TSI_FOREACH_END()
}

/* Plugin registration ------------------------------------------------------*/
TSI_PLUGIN(WidgetTimeout, TSI_PLUGIN_PRIORITY)
{
    TSI_InitCompletedCallback,          /* initCompleted */
    NULL,                               /* deInitCompleted */
    NULL,                               /* started */
    NULL,                               /* stopped */
    NULL,                               /* widgetInitCompleted */
    NULL,                               /* widgetScanCompleted */
    NULL,                               /* widgetValueUpdated */
    TSI_Widget_StatusUpdateCallback,    /* widgetStatusUpdated */
#if(TSI_USE_CALLBACK_INIT_SCAN != 0U)
    NULL,                               /* getInitScanBufferAndCount */
    NULL,                               /* processInitScanValue */
#endif
};
