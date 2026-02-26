#include "tsi_object.h"
#include "tsi_processing.h"
#include "tsi_driver.h"
#include "tsi.h"
#include "tsi_plugin.h"

/* Configurations -----------------------------------------------------------*/
/** Plugin version string. */
#define TSI_PLUGIN_VERSION                  "v1.0"

/* USER CONFIGURATION BEGIN */
/** Plugin call priority(0-7). Lower value means higher priority. */
#define TSI_PLUGIN_PRIORITY                 "0"

/** ESD channel filter: fast coefficient. */
#define TSI_ESD_FILTER_COEF_FAST            (100U)

/** ESD channel filter: slow coefficient. */
#define TSI_ESD_FILTER_COEF_SLOW            (15U)

/** ESD channel filter: switch threshold. */
#define TSI_ESD_FILTER_SW_THRESHOLD         (30U)

/**
 *  ESD event detection threshold.
 *
 *  * detConf: Refer widget/sensor detConf.
 */
#define TSI_ESD_EVENT_DETECT_THRESHOLD      ((detConf->activeTh) / 3)
/* USER CONFIGURATION END */
/* Defines ------------------------------------------------------------------*/

/* Function prototypes ------------------------------------------------------*/
static void TSI_ESDFilter_Init(uint32_t *buffer, uint16_t initVal);
static void TSI_ESDFilter_Update(uint32_t *buffer, uint16_t *input);
static void TSI_Widget_MaskOutput(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget);

/* Variables ----------------------------------------------------------------*/
static uint32_t TSI_ESDFilterBuffer[TSI_SENSOR_NUM][2];

/* Function implementations -------------------------------------------------*/
static void TSI_Widget_InitCompletedCallback(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget)
{
    uint16_t realSnsNum;

    /* If it is self-cap parallel widget, we shall only init the first sensor. */
    if(TSI_WIDGET_IS_SELF_CAP(widget) && widget->meta->dedicatedScanGroup != NULL) {
        realSnsNum = 1U;
    }
#if (TSI_WIDGET_SC_TOUCHPAD_USED == 1U)
    else if(widget->meta->type == TSI_WIDGET_SELF_CAP_TOUCHPAD) {
        TSI_MetaWidgetTypeDef *meta = (TSI_MetaWidgetTypeDef *)widget->meta;
        realSnsNum = meta->sensorNum + ((TSI_Meta2DWidgetTypeDef *)meta)->sensorRowNum;
    }
#endif 
    else {
        realSnsNum = widget->meta->sensorNum;
    }

    TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                    realSnsNum) {
        /* ESD detect channnel at #1 user scan. */
        TSI_ESDFilter_Init(TSI_ESDFilterBuffer[pSensor->meta->id],
                           pSensor->rawCount[TSI_SCAN_FREQ_NUM]);
    }
    TSI_FOREACH_END()
}

static void TSI_Widget_ScanCompletedCallback(TSI_LibHandleTypeDef *handle)
{
    uint16_t realSnsNum;

    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        /* If it is self-cap parallel widget, we shall only process first sensor. */
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

        TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, (*ppWidget)->meta->sensors,
                        realSnsNum) {
            /* ESD detect channnel at #1 user scan. */
            uint16_t tmpVal =  pSensor->bslnVar.sensorUserBuffer[0];
            TSI_ESDFilter_Update(TSI_ESDFilterBuffer[pSensor->meta->id],
                                 &tmpVal);
            pSensor->rawCount[TSI_SCAN_FREQ_NUM] = tmpVal;
        }
        TSI_FOREACH_END()
    }
    TSI_FOREACH_END()
}

static void TSI_Widget_StatusUpdatedCallback(TSI_LibHandleTypeDef *handle)
{
    uint16_t realSnsNum;

    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        TSI_DetectConfTypeDef *widgetDetConf = &(*ppWidget)->detConf;
        /* If it is self-cap parallel widget, we shall only process the first sensor. */
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

        TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, (*ppWidget)->meta->sensors,
                        realSnsNum) {
            if(pSensor->status != 0U) {
                int32_t esdDiff, deltaDiff;
                TSI_DetectConfTypeDef *detConf = pSensor->meta->detConf;
                if(detConf == NULL) { detConf = widgetDetConf; }
                TSI_ASSERT(detConf);
                esdDiff = (int32_t)pSensor->rawCount[TSI_SCAN_FREQ_NUM] -
                          (int32_t)pSensor->baseline[TSI_SCAN_FREQ_NUM];
                deltaDiff = pSensor->diffCount - esdDiff;
                if(deltaDiff < TSI_ESD_EVENT_DETECT_THRESHOLD) {
                    /* ESD event detected, mask widget output. */
                    TSI_Widget_MaskOutput(handle, (*ppWidget));
                }
            }
        }
        TSI_FOREACH_END()
    }
    TSI_FOREACH_END()
}

static void TSI_ESDFilter_Init(uint32_t *buffer, uint16_t initVal)
{
    buffer[0] = buffer[1] = (uint32_t) initVal << 7U;
}

static void TSI_ESDFilter_Update(uint32_t *buffer, uint16_t *input)
{
    uint32_t tmpQ7_1;
    uint32_t tmpQ7_2;
    uint32_t delta = 0UL;
    uint32_t inputQ7 = ((uint32_t) * input) << 7U;

    tmpQ7_1 = ((uint64_t)(TSI_ESD_FILTER_COEF_FAST * inputQ7) +
               (uint64_t)((256U - TSI_ESD_FILTER_COEF_FAST) * buffer[0])) >> 8U;
    buffer[0] = tmpQ7_1;
    tmpQ7_2 = ((uint64_t)(TSI_ESD_FILTER_COEF_SLOW * inputQ7) +
               (uint64_t)((256U - TSI_ESD_FILTER_COEF_SLOW) * buffer[1])) >> 8U;
    buffer[1] = tmpQ7_2;

    if(tmpQ7_2 > tmpQ7_1) {
        delta = tmpQ7_2 - tmpQ7_1;
    }
    if(delta > TSI_ESD_FILTER_SW_THRESHOLD) {
        *input = tmpQ7_2 >> 7U;
    }
    else {
        *input = tmpQ7_1 >> 7U;
        buffer[1] = tmpQ7_1;
    }
}

static void TSI_Widget_MaskOutput(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget)
{
    uint16_t realSnsNum;

    TSI_UNUSED(handle)

    /* If it is self-cap parallel widget, we shall only reset the first sensor. */
    if(TSI_WIDGET_IS_SELF_CAP(widget) && widget->meta->dedicatedScanGroup != NULL) {
        realSnsNum = 1U;
    }
#if (TSI_WIDGET_SC_TOUCHPAD_USED == 1U)
    else if(widget->meta->type == TSI_WIDGET_SELF_CAP_TOUCHPAD) {
        TSI_MetaWidgetTypeDef *meta = (TSI_MetaWidgetTypeDef *)widget->meta;
        realSnsNum = meta->sensorNum + ((TSI_Meta2DWidgetTypeDef *)meta)->sensorRowNum;
    }
#endif 
    else {
        realSnsNum = widget->meta->sensorNum;
    }

    TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                    realSnsNum) {
        TSI_DetectConfTypeDef *detConf = pSensor->meta->detConf;
        if(detConf == NULL) { detConf = &widget->detConf; }
        /* Reset sensor status and debounce counter */
        pSensor->status = 0U;
        memset(pSensor->meta->debArray, detConf->onDebounce, pSensor->meta->debArraySize);
    }
    TSI_FOREACH_END()

    /* Mask widget general status. */
    widget->status = 0U;

    /* Mask widget status. */
    switch(widget->meta->type) {
        case TSI_WIDGET_SELF_CAP_BUTTON:
            ((TSI_SelfCapButtonTypeDef *)widget)->buttonStat = 0U;
            break;
        case TSI_WIDGET_SELF_CAP_SLIDER:
            ((TSI_SelfCapSliderTypeDef *)widget)->sliderStat = 0U;
            break;
        case TSI_WIDGET_SELF_CAP_PROXIMITY:
            ((TSI_SelfCapProximityTypeDef *)widget)->proximityStat = 0U;
            break;
        default:
            break;
    }
}

/* Plugin registration ------------------------------------------------------*/
TSI_PLUGIN(ESD, TSI_PLUGIN_PRIORITY)
{
    NULL,                               /* initCompleted */
    NULL,                               /* deInitCompleted */
    NULL,                               /* started */
    NULL,                               /* stopped */
    TSI_Widget_InitCompletedCallback,   /* widgetInitCompleted */
    TSI_Widget_ScanCompletedCallback,   /* widgetScanCompleted */
    NULL,                               /* widgetValueUpdated */
    TSI_Widget_StatusUpdatedCallback,   /* widgetStatusUpdated */
    NULL,                               /* getInitScanBufferAndCount */
    NULL,                               /* processInitScanValue */
};
