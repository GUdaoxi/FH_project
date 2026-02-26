#include "tsi_object.h"
#include "tsi_processing.h"
#include "tsi_driver.h"
#include "tsi_plugin.h"

/* Configurations -----------------------------------------------------------*/
/** Plugin version string. */
#define TSI_PLUGIN_VERSION                  "v1.1"

/* USER CONFIGURATION BEGIN */
/** Plugin call priority(0-7). Lower value means higher priority. */
#define TSI_PLUGIN_PRIORITY                 "0"

/** Negative commnoise reset debounce count. */
#define TSI_NEG_COMMNOISE_DEBOUNCE          (5U)
/* USER CONFIGURATION END */
/* Defines ------------------------------------------------------------------*/

/* Function prototypes ------------------------------------------------------*/
static void TSI_Widget_ValueUpdateCallback(TSI_LibHandleTypeDef *handle);
static void TSI_Widget_BaselineInit(TSI_LibHandleTypeDef *handle);
static uint8_t TSI_Widget_isComNoise(TSI_LibHandleTypeDef *handle);

/* Variables ----------------------------------------------------------------*/
static uint8_t negCommNoiseTimeCnt = 0U;
static uint8_t selfCapWidgetEnableNum = 0U;

/* Function implementations -------------------------------------------------*/
static void TSI_Widget_ValueUpdateCallback(TSI_LibHandleTypeDef *handle)
{
    uint16_t realSnsNum;
    uint8_t tmpPosComFlag = 0U, tmpNegComFlag = 0U, tmpComFlag = 0U;

    selfCapWidgetEnableNum = 0U;
    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        if((*ppWidget)->enable == TSI_WIDGET_ENABLE && TSI_WIDGET_IS_SELF_CAP(*ppWidget)) {
            selfCapWidgetEnableNum++;
            if(selfCapWidgetEnableNum > 1U) {
                break;
            }
        }
        /** @todo Mutual Cap implementation. */
    }
    TSI_FOREACH_END()

    if(selfCapWidgetEnableNum <= 1U) {
        /* Algorithm is meaningless when there is less than 2 widgets. */
        return;
    }

    /* Postive ComNoise Detect */
    tmpComFlag = TSI_Widget_isComNoise(handle);
    tmpPosComFlag = tmpComFlag & 0x01U;
    tmpNegComFlag = (tmpComFlag >> 4U) & 0x01U;

    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        if(TSI_WIDGET_IS_SELF_CAP(*ppWidget)) {
            if((*ppWidget)->meta->dedicatedScanGroup != NULL) {
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
            TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, (*ppWidget)->meta->sensors,
                            realSnsNum) {
                int32_t activeTh, diff;
                TSI_DetectConfTypeDef *detConf = pSensor->meta->detConf;
                if(detConf == NULL) { detConf = &(*ppWidget)->detConf; }
                activeTh = (int32_t)detConf->activeTh + (int32_t)detConf->activeHys;
                diff = (int32_t)pSensor->rawCount[0U] - (int32_t)pSensor->baseline[0U];
                if(diff > activeTh && tmpPosComFlag) {
                    TSI_Widget_BaselineInit(handle);
                    break;
                }
            }
            TSI_FOREACH_END()
        }
        /** @todo Mutual Cap implementation. */
    }
    TSI_FOREACH_END()

    /* Negative ComNoise Detect */
    if(tmpNegComFlag) {
        if(++negCommNoiseTimeCnt > TSI_NEG_COMMNOISE_DEBOUNCE) {
            TSI_Widget_BaselineInit(handle);
            negCommNoiseTimeCnt = 0U;
        }
    }
    else {
        negCommNoiseTimeCnt = 0U;
    }
}

static void TSI_Widget_BaselineInit(TSI_LibHandleTypeDef *handle)
{
    uint16_t realSnsNum;

    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        if(TSI_WIDGET_IS_SELF_CAP(*ppWidget) && (*ppWidget)->meta->dedicatedScanGroup != NULL) {
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
        if(TSI_WIDGET_IS_SELF_CAP(*ppWidget)) {
            TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, (*ppWidget)->meta->sensors,
                            realSnsNum) {
                TSI_DetectConfTypeDef *detConf = pSensor->meta->detConf;
                if(detConf == NULL) { detConf = &(*ppWidget)->detConf; }
                TSI_Baseline_Init(pSensor, detConf);
                pSensor->diffCount = 0U;
#if((TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U))
                pSensor->ltaDiffCount = 0U;
#endif
            }
            TSI_FOREACH_END()
        }

        /** @todo Mutual Cap implementation. */
    }
    TSI_FOREACH_END()
}

static uint8_t TSI_Widget_isComNoise(TSI_LibHandleTypeDef *handle)
{
    uint8_t isPosComNoise = 1U;
    uint8_t isNegComNoise = 1U;
    uint8_t isComNoise;
    uint16_t realSnsNum;

    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        if(TSI_WIDGET_IS_SELF_CAP(*ppWidget) && (*ppWidget)->meta->dedicatedScanGroup != NULL) {
            realSnsNum = 1U;
        }
        else {
            realSnsNum = (*ppWidget)->meta->sensorNum;
        }
        if(TSI_WIDGET_IS_SELF_CAP(*ppWidget)) {
            TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, (*ppWidget)->meta->sensors,
                            realSnsNum) {
                int32_t diff = (int32_t)pSensor->rawCount[0U] - (int32_t)pSensor->baseline[0U];
                TSI_DetectConfTypeDef *detConf = pSensor->meta->detConf;
                if(detConf == NULL) { detConf = &(*ppWidget)->detConf; }
                if(diff < ((int32_t)(detConf->noiseTh))) {
                    isPosComNoise &= ~(0x01U);
                }
                if(diff > -((int32_t)(detConf->negNoiseTh))) {
                    isNegComNoise &= ~(0x01U);
                }
            }
            TSI_FOREACH_END()
        }
        /** @todo Mutual Cap implementation. */
    }
    TSI_FOREACH_END()

    isComNoise = (isPosComNoise | (isNegComNoise << 4U));
    return isComNoise;
}

/* Plugin registration ------------------------------------------------------*/
TSI_PLUGIN(CommNoise, TSI_PLUGIN_PRIORITY)
{
    NULL,                               /* initCompleted */
    NULL,                               /* deInitCompleted */
    NULL,                               /* started */
    NULL,                               /* stopped */
    NULL,                               /* widgetInitCompleted */
    NULL,                               /* widgetScanCompleted */
    TSI_Widget_ValueUpdateCallback,     /* widgetValueUpdated */
    NULL,                               /* widgetStatusUpdated */
    NULL,                               /* getInitScanBufferAndCount */
    NULL,                               /* processInitScanValue */
};
