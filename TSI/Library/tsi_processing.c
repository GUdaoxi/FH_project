#include "tsi_processing.h"
#include "tsi_filter.h"
#include "tsi.h"

/* Private defines ----------------------------------------------------------*/
#define TSI_SENSOR_STATUS_ACTIVE        (uint8_t)(0x1U)
#define TSI_SENSOR_STATUS_PROX          (uint8_t)(0x2U)

#define TSI_BASELINE_MODE_NORMAL        (uint8_t)(0x0U)
#define TSI_BASELINE_MODE_LTA           (uint8_t)(0x1U)

#define TSI_PEAK_POS_IDX                (1U)
#define TSI_PEAK_POS_PREV_IDX           (0U)
#define TSI_PEAK_POS_NEXT_IDX           (2U)

/* Private types ------------------------------------------------------------*/
typedef struct _TSI_Peak1D {
    /** Peak position index. */
    uint8_t idx;

    /** Peak and sibling sensor signals. */
    uint16_t signals[3U];

} TSI_Peak1DTypeDef;

/* Private variables --------------------------------------------------------*/
static TSI_Peak1DTypeDef TSI_Peak1D[TSI_SINGLE_TOUCH_MAX_CENTROID_NUM];
static uint8_t TSI_Peak1DNum;

/* Private function prototypes ----------------------------------------------*/
/* Widget */
TSI_STATIC void TSI_Widget_ProcessDiffAndBaseline(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget);
TSI_STATIC void TSI_Widget_ProcessStatusAndBaseline(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget);
TSI_STATIC void TSI_Widget_ProcessPrivateData(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget);
TSI_STATIC void TSI_Widget_InitSelfCapButton(TSI_SelfCapButtonTypeDef *button);
TSI_STATIC void TSI_Widget_InitSelfCapProximity(TSI_SelfCapProximityTypeDef *proximity);
TSI_STATIC void TSI_Widget_InitSelfCapSlider(TSI_SelfCapSliderTypeDef *slider);
TSI_STATIC void TSI_Widget_InitSelfCapRadialSlider(TSI_SelfCapRadialSliderTypeDef *slider);
TSI_STATIC void TSI_Widget_InitSelfCapTouchpad(TSI_SelfCapTouchpadTypeDef *pad);
TSI_STATIC void TSI_Widget_InitMutualCapButton(TSI_MutualCapButtonTypeDef *button);
TSI_STATIC void TSI_Widget_InitMutualCapSlider(TSI_MutualCapSliderTypeDef *slider);
TSI_STATIC void TSI_Widget_UpdateSelfCapButton(TSI_SelfCapButtonTypeDef *pad);
TSI_STATIC void TSI_Widget_UpdateSelfCapProximity(TSI_SelfCapProximityTypeDef *proximity);
TSI_STATIC void TSI_Widget_UpdateSelfCapSlider(TSI_SelfCapSliderTypeDef *slider);
TSI_STATIC void TSI_Widget_UpdateSelfCapRadialSlider(TSI_SelfCapRadialSliderTypeDef *slider);
TSI_STATIC void TSI_Widget_UpdateSelfCapTouchpad(TSI_SelfCapTouchpadTypeDef *pad);
TSI_STATIC void TSI_Widget_UpdateMutualCapButton(TSI_MutualCapButtonTypeDef *button);
TSI_STATIC void TSI_Widget_UpdateMutualCapSlider(TSI_MutualCapSliderTypeDef *slider);
/* Status */
TSI_STATIC void TSI_Sensor_UpdateStatus(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf,
                                        uint8_t type);
/* Normal baseline */
TSI_STATIC void TSI_NormalBaseline_Init(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf);
TSI_STATIC void TSI_NormalBaseline_Update(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf);
#if((TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U))
    /* LTA baseline */
    TSI_STATIC void TSI_LTABaseline_Init(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf);
    TSI_STATIC void TSI_LTABaseline_Update(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf);
    TSI_STATIC void TSI_Baseline_ModeJudge(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf);
#endif  /* if (TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U) */
/* DiffCount */
TSI_STATIC void TSI_Sensor_UpdateDiffCount(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf);
/* Centroid algorithm */
static uint32_t TSI_FindPeak1D(TSI_SensorTypeDef *sensors, uint32_t num);
static uint32_t TSI_CalcLinearCentroid(uint32_t *centroid, uint32_t snsNum, int32_t mul);
static uint32_t TSI_CalcRadialCentroid(uint32_t *centroid, uint32_t snsNum, int32_t mul);

/* Widget API implementations -----------------------------------------------*/
TSI_RetCode TSI_Widget_InitAll(TSI_LibHandleTypeDef *handle)
{
    TSI_RetCode res;

    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        res = TSI_Widget_Init(handle, *ppWidget);
        if(res != TSI_PASS) { return res; }
    }
    TSI_FOREACH_END()

    return TSI_PASS;
}

TSI_RetCode TSI_Widget_Init(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget)
{
    TSI_DetectConfTypeDef *widgetDetConf = &widget->detConf;
    uint16_t realSnsNum;
    TSI_WidgetType type = widget->meta->type;

    TSI_UNUSED(handle)

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
        TSI_DetectConfTypeDef *detConf = pSensor->meta->detConf;
        if(detConf == NULL) { detConf = widgetDetConf; }
        TSI_ASSERT(detConf);
        TSI_Sensor_Init(pSensor, detConf);
    }
    TSI_FOREACH_END()

    /* Init widget private data */
    if(TSI_WIDGET_IS_SELF_CAP(widget)) {
        switch(type) {
            case TSI_WIDGET_SELF_CAP_BUTTON:
                TSI_Widget_InitSelfCapButton((TSI_SelfCapButtonTypeDef *)widget);
                break;
            case TSI_WIDGET_SELF_CAP_SLIDER:
                TSI_Widget_InitSelfCapSlider((TSI_SelfCapSliderTypeDef *)widget);
                break;
            case TSI_WIDGET_SELF_CAP_RADIAL_SLIDER:
                TSI_Widget_InitSelfCapRadialSlider((TSI_SelfCapRadialSliderTypeDef *)widget);
                break;
            case TSI_WIDGET_SELF_CAP_TOUCHPAD:
                TSI_Widget_InitSelfCapTouchpad((TSI_SelfCapTouchpadTypeDef *)widget);
                break;
            case TSI_WIDGET_SELF_CAP_PROXIMITY:
                TSI_Widget_InitSelfCapProximity((TSI_SelfCapProximityTypeDef *)widget);
                break;
            default:
                break;
        }
    }
    else if(TSI_WIDGET_IS_MUTUAL_CAP(widget)) {
        switch(type) {
            case TSI_WIDGET_MUTUAL_CAP_BUTTON:
                TSI_Widget_InitMutualCapButton((TSI_MutualCapButtonTypeDef *)widget);
                break;
            case TSI_WIDGET_MUTUAL_CAP_SLIDER:
                TSI_Widget_InitMutualCapSlider((TSI_MutualCapSliderTypeDef *)widget);
                break;
            default:
                break;
        }
    }
    else {
        /* Do nothing. */
    }


    /* Call user callback for customized algorithms. */
    if(handle->cb.widgetInitCompleted != NULL) {
        handle->cb.widgetInitCompleted(handle, widget);
    }

    return TSI_PASS;
}

TSI_RetCode TSI_Widget_EnableAll(TSI_LibHandleTypeDef *handle)
{
    TSI_RetCode res;
    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        res = TSI_Widget_Enable(handle, *ppWidget);
        if(res != TSI_PASS) {
            return res;
        }
    }
    TSI_FOREACH_END()
    return TSI_PASS;
}

TSI_RetCode TSI_Widget_Enable(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget)
{
    return TSI_Drv_EnableWidget(handle->driver, widget);
}

TSI_RetCode TSI_Widget_DisableAll(TSI_LibHandleTypeDef *handle)
{
    TSI_RetCode res;
    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        res = TSI_Widget_Disable(handle, *ppWidget);
        if(res != TSI_PASS) {
            return res;
        }
    }
    TSI_FOREACH_END()
    return TSI_PASS;
}

TSI_RetCode TSI_Widget_Disable(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget)
{
    return TSI_Drv_DisableWidget(handle->driver, widget);
}

void TSI_Widget_UpdateAll(TSI_LibHandleTypeDef *handle)
{
    /* Call user callback for customized algorithms. */
    if(handle->cb.widgetScanCompleted != NULL) {
        handle->cb.widgetScanCompleted(handle);
    }

    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        if((*ppWidget)->enable == TSI_WIDGET_ENABLE) {
            /* Update diffcount and baseline */
            TSI_Widget_ProcessDiffAndBaseline(handle, *ppWidget);
        }
    }
    TSI_FOREACH_END()

    /* Call user callback for customized algorithms. */
    if(handle->cb.widgetValueUpdated != NULL) {
        handle->cb.widgetValueUpdated(handle);
    }

    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        if((*ppWidget)->enable == TSI_WIDGET_ENABLE) {
            /* Update sensor status and baseline mode */
            TSI_Widget_ProcessStatusAndBaseline(handle, *ppWidget);
            /* Update widget-specified data */
            TSI_Widget_ProcessPrivateData(handle, *ppWidget);
        }
    }
    TSI_FOREACH_END()

    /* Call user callback for customized algorithms. */
    if(handle->cb.widgetStatusUpdated != NULL) {
        handle->cb.widgetStatusUpdated(handle);
    }
}

/* Sensor APIs implemenations -----------------------------------------------*/
void TSI_Sensor_Init(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf)
{
    /* Init sensor filter buffers */
    TSI_Filter_Init(sensor);

    /* Init sensor baseline */
    TSI_Baseline_Init(sensor, detConf);

    /* Reset sensor status and debounce counter */
    sensor->status = 0U;
    memset(sensor->meta->debArray, detConf->onDebounce, sensor->meta->debArraySize);
}

/* Baseline APIs implemenations ---------------------------------------------*/
void TSI_Baseline_Init(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf)
{
    TSI_NormalBaseline_Init(sensor, detConf);
#if((TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U))
    TSI_LTABaseline_Init(sensor, detConf);
    sensor->bslnVar.bslnMode = TSI_BASELINE_MODE_NORMAL;
#endif  /* if (TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U) */
}

void TSI_Baseline_Update(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf)
{
#if((TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U))
    uint8_t bslnMode = sensor->bslnVar.bslnMode;
#endif  /* if (TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U) */

    /* Update baseline. */
#if((TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U))
    if(bslnMode == TSI_BASELINE_MODE_NORMAL) {
        TSI_NormalBaseline_Update(sensor, detConf);
    }
    TSI_LTABaseline_Update(sensor, detConf);
#else
    /* Update baseline */
    TSI_NormalBaseline_Update(sensor, detConf);
#endif  /* if (TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U) */

    /* Calculate diffCount. */
    TSI_Sensor_UpdateDiffCount(sensor, detConf);
}

/* Private function implemenations ------------------------------------------*/
TSI_STATIC void TSI_Widget_ProcessDiffAndBaseline(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget)
{
    TSI_DetectConfTypeDef *widgetDetConf = &widget->detConf;
    uint16_t realSnsNum;

    /*
        NOTE:
        This function MUST be used with TSI_Widget_ProcessStatusAndBaseline() in pairs,
        or sensor-related values will be incorrected.
    */

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

    /* Update all sensors */
    TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                    realSnsNum) {
        TSI_DetectConfTypeDef *detConf = pSensor->meta->detConf;
        if(detConf == NULL) { detConf = widgetDetConf; }
        TSI_ASSERT(detConf);
#if ((TSI_USED_IN_LPM_MODE == 1U) && (TSI_LPM_BYPASS_FILTERS == 1U))
        if(handle->isLPM != 0U) {
            /* Pass rawCount through filter */
            TSI_Filter_Update(pSensor);
        }
        else {
            /* Bypass filter in LPM mode. */
            TSI_Filter_Bypass(pSensor);
        }
#else
        /* Pass rawCount through filter */
        TSI_Filter_Update(pSensor);
#endif
        /* Update baseline with filtered rawCount */
        TSI_Baseline_Update(pSensor, detConf);
    }
    TSI_FOREACH_END()
}

TSI_STATIC void TSI_Widget_ProcessStatusAndBaseline(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget)
{
    TSI_DetectConfTypeDef *widgetDetConf = &widget->detConf;
    uint8_t sensorActive = 0U;
    uint16_t realSnsNum;

    /*
        NOTE:
        This function MUST be used with TSI_Widget_ProcessDiffAndBaseline() in pairs,
        or sensor-related values will be incorrected.
    */
    TSI_UNUSED(handle)

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

    /* Update all sensors */
    TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                    realSnsNum) {
        TSI_DetectConfTypeDef *detConf = pSensor->meta->detConf;
        if(detConf == NULL) { detConf = widgetDetConf; }
        TSI_ASSERT(detConf);
        /* Update sensor active status */
        TSI_Sensor_UpdateStatus(pSensor, detConf, TSI_SENSOR_STATUS_ACTIVE);
        if(widget->meta->type == TSI_WIDGET_SELF_CAP_PROXIMITY) {
            /* If it's proximity widget sensor, update sensor proxmity status */
            TSI_Sensor_UpdateStatus(pSensor, detConf, TSI_SENSOR_STATUS_PROX);
        }
#if((TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U))
        /* Update baseline mode */
        TSI_Baseline_ModeJudge(pSensor, detConf);
#endif  /* if (TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U) */
        /* If any sensor is activated, mark widget status as active */
        if((pSensor->status & TSI_SENSOR_STATUS_ACTIVE) != 0U) {
            sensorActive = 1U;
        }
    }
    TSI_FOREACH_END()

    /* Update widget general status */
    widget->status = sensorActive;
}

TSI_STATIC void TSI_Widget_ProcessPrivateData(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget)
{
    TSI_UNUSED(handle)

    /* Update widget-specified status */
    if(TSI_WIDGET_IS_SELF_CAP(widget)) {
        switch(widget->meta->type) {
            case TSI_WIDGET_SELF_CAP_BUTTON:
                TSI_Widget_UpdateSelfCapButton((TSI_SelfCapButtonTypeDef *)widget);
                break;

            case TSI_WIDGET_SELF_CAP_PROXIMITY:
                TSI_Widget_UpdateSelfCapProximity((TSI_SelfCapProximityTypeDef *)widget);
                break;

            case TSI_WIDGET_SELF_CAP_SLIDER:
                TSI_Widget_UpdateSelfCapSlider((TSI_SelfCapSliderTypeDef *)widget);
                break;

            case TSI_WIDGET_SELF_CAP_RADIAL_SLIDER:
                TSI_Widget_UpdateSelfCapRadialSlider((TSI_SelfCapRadialSliderTypeDef *)widget);
                break;

            case TSI_WIDGET_SELF_CAP_TOUCHPAD:
                TSI_Widget_UpdateSelfCapTouchpad((TSI_SelfCapTouchpadTypeDef *)widget);
                break;

            default:
                /* Cannot be here */
                TSI_ASSERT(0U);
                break;
        }
    }
    else if(TSI_WIDGET_IS_MUTUAL_CAP(widget)) {
        switch(widget->meta->type) {
            case TSI_WIDGET_MUTUAL_CAP_BUTTON:
                TSI_Widget_UpdateMutualCapButton((TSI_MutualCapButtonTypeDef *)widget);
                break;

            case TSI_WIDGET_MUTUAL_CAP_SLIDER:
                TSI_Widget_UpdateMutualCapSlider((TSI_MutualCapSliderTypeDef *)widget);
                break;

            default:
                /* Cannot be here */
                TSI_ASSERT(0U);
                break;
        }
    }
}

TSI_STATIC void TSI_Widget_InitSelfCapButton(TSI_SelfCapButtonTypeDef *button)
{
    /* Reset widget status. */
    button->buttonStat = 0U;
}

TSI_STATIC void TSI_Widget_InitSelfCapProximity(TSI_SelfCapProximityTypeDef *proximity)
{
    /* Reset widget status. */
    proximity->proximityStat = 0U;
#if (TSI_PROX_FILTER_ADVIIR_EN == 1U)
    /* Reset ADVIIR filter mode. */
    proximity->filterMode = 0U;
#endif  /* TSI_PROX_FILTER_ADVIIR_EN == 1U */
}

TSI_STATIC void TSI_Widget_InitSelfCapSlider(TSI_SelfCapSliderTypeDef *slider)
{
    TSI_MetaWidgetTypeDef *meta = ((TSI_WidgetTypeDef *)slider)->meta;

    /* Set centroid multiplier. */
    slider->centroidMul = (int32_t)((TSI_SLIDER_RESOLUTION * 256U) / (((TSI_WidgetTypeDef *)slider)->meta->sensorNum - 1U));

    /* Reset widget status and debounce counter. */
    slider->sliderStat = 0U;
    memset(meta->debArrayWidget, slider->onDebounceWidget, meta->debArrayWidgetSize);
}

TSI_STATIC void TSI_Widget_InitSelfCapRadialSlider(TSI_SelfCapRadialSliderTypeDef *slider)
{
    TSI_MetaWidgetTypeDef *meta = ((TSI_WidgetTypeDef *)slider)->meta;

    /* Set centroid multiplier. */
    slider->centroidMul = (int32_t)((TSI_SLIDER_RESOLUTION * 256U) / ((TSI_WidgetTypeDef *)slider)->meta->sensorNum);

    /* Reset widget status and debounce counter. */
    slider->sliderStat = 0U;
    memset(meta->debArrayWidget, slider->onDebounceWidget, meta->debArrayWidgetSize);
}

TSI_STATIC void TSI_Widget_InitSelfCapTouchpad(TSI_SelfCapTouchpadTypeDef *pad)
{
    TSI_MetaWidgetTypeDef *meta = ((TSI_WidgetTypeDef *)pad)->meta;

    /* Set centroid multiplier. */
    pad->centroidMulX = (int32_t)((TSI_TOUCHPAD_RESOLUTION * 256U) / (meta->sensorNum - 1U));
    pad->centroidMulY = (int32_t)((TSI_TOUCHPAD_RESOLUTION * 256U) / (((TSI_Meta2DWidgetTypeDef *)meta)->sensorRowNum - 1U));

    /* Reset widget status and debounce counter. */
    pad->padStat = 0U;
    memset(meta->debArrayWidget, pad->onDebounceWidget, meta->debArrayWidgetSize);
}

TSI_STATIC void TSI_Widget_InitMutualCapButton(TSI_MutualCapButtonTypeDef *button)
{
    /* Reset widget status. */
    button->buttonStat = 0U;
}

TSI_STATIC void TSI_Widget_InitMutualCapSlider(TSI_MutualCapSliderTypeDef *slider)
{
    TSI_MetaWidgetTypeDef *meta = ((TSI_WidgetTypeDef *)slider)->meta;

    /* Set centroid multiplier. */
    slider->centroidMul = (int32_t)((TSI_SLIDER_RESOLUTION * 256U) / (((TSI_WidgetTypeDef *)slider)->meta->sensorNum - 1U));

    /* Reset widget status and debounce counter. */
    slider->sliderStat = 0U;
    memset(meta->debArrayWidget, slider->onDebounceWidget, meta->debArrayWidgetSize);
}

TSI_STATIC void TSI_Widget_UpdateSelfCapButton(TSI_SelfCapButtonTypeDef *button)
{
    button->buttonStat = button->base.base.status;
}

TSI_STATIC void TSI_Widget_UpdateSelfCapProximity(TSI_SelfCapProximityTypeDef *proximity)
{
    TSI_MetaWidgetTypeDef *meta = ((TSI_WidgetTypeDef *)proximity)->meta;
#if (TSI_PROX_FILTER_ADVIIR_EN == 1U)
    uint8_t realSnsNum = 0U;
#endif  /* TSI_PROX_FILTER_ADVIIR_EN == 1U */

#if (TSI_PROX_FILTER_ADVIIR_EN == 1U)

    if(meta->dedicatedScanGroup == NULL) {
        realSnsNum = meta->sensorNum;
    }
    else {
        realSnsNum = 1U;
    }

    TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, meta->sensors,
                    realSnsNum) {
        if(proximity->filterMode == 0U && pSensor->diffCount > proximity->filterActiveTh) {
            /* Filter is in active mode if any sensor diffcount is above active threshold. */
            proximity->filterMode = 1U;
            break;
        }
        else if(proximity->filterMode == 1U && pSensor->diffCount < proximity->filterDetectTh) {
            /* Filter is in detection mode if any sensor diffcount is below detect threshold. */
            proximity->filterMode = 0U;
            break;
        }
    }
    TSI_FOREACH_END()
#endif  /* TSI_PROX_FILTER_ADVIIR_EN == 1U */

    if(proximity->base.base.status == 1U) {
        /* Proximity widget is activated when any sensor is activated */
        proximity->proximityStat = 2U;
    }
    else {
        TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, meta->sensors,
                        meta->sensorNum) {
            if((pSensor->status & TSI_SENSOR_STATUS_PROX) != 0U) {
                /* Proximity widget is in proximity status when any sensor is
                   in proximity status */
                proximity->proximityStat = 1U;
                return;
            }
        }
        TSI_FOREACH_END()
        proximity->proximityStat = 0U;
    }
}

TSI_STATIC void TSI_Widget_UpdateSelfCapSlider(TSI_SelfCapSliderTypeDef *slider)
{
    TSI_WidgetTypeDef *sliderBase = (TSI_WidgetTypeDef *)slider;
    TSI_MetaWidgetTypeDef *sliderMeta = sliderBase->meta;
    int i;

    if(slider->onDebounceWidget <= 1U) {
        /* No debounce */
        slider->sliderStat = sliderBase->status;
#if (TSI_WIDGET_POS_FILTER_EN == 1U)
        if(slider->sliderStat == 0U) {
            /* Deinit position filter */
            for(i = 0; i < TSI_SLIDER_FINGER_NUM; i++) {
                TSI_WidgetPosFilter1D_DeInit(&((TSI_WidgetPosFilter1DTypeDef *)sliderMeta->posFilter)[i]);
            }
        }
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */
    }
    else {
        uint8_t *pDebCnt = sliderMeta->debArrayWidget;
        TSI_ASSERT(pDebCnt != NULL);

        /* Add Widget on debounce and update status */
        if(sliderBase->status != 0U) {
            if(*pDebCnt > 0U) {
                (*pDebCnt)--;
            }
            if(*pDebCnt == 0U) {
                /* Update sensor status */
                slider->sliderStat = 1U;
            }
        }
        else {
            /* Reset debounce and status */
            *pDebCnt = slider->onDebounceWidget;
            slider->sliderStat = 0U;
#if (TSI_WIDGET_POS_FILTER_EN == 1U)
            /* Deinit position filter */
            for(i = 0; i < TSI_SLIDER_FINGER_NUM; i++) {
                TSI_WidgetPosFilter1D_DeInit(&((TSI_WidgetPosFilter1DTypeDef *)sliderMeta->posFilter)[i]);
            }
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */
        }
    }

    if(slider->sliderStat == 1U) {
        uint32_t peakNum;

        /* Update centroid */
        peakNum = TSI_FindPeak1D(sliderMeta->sensors, sliderMeta->sensorNum);
        if(peakNum != 0UL) {
            uint32_t peaks[TSI_SINGLE_TOUCH_MAX_CENTROID_NUM];

            (void) TSI_CalcLinearCentroid(peaks, sliderMeta->sensorNum, slider->centroidMul);
            for(i = 0; (i < peakNum) && (i < TSI_SLIDER_FINGER_NUM); i++) {
#if (TSI_WIDGET_POS_FILTER_EN == 1U)
                uint16_t tmp = peaks[i];
                if(TSI_WidgetPosFilter1D_IsInited((TSI_WidgetPosFilter1DTypeDef *)sliderMeta->posFilter) == 0U) {
                    /* Init position filter with the first position data */
                    TSI_WidgetPosFilter1D_Init(&((TSI_WidgetPosFilter1DTypeDef *)sliderMeta->posFilter)[i],
                                               peaks[i]);
                }
                else {
                    /* Filter position data */
                    TSI_WidgetPosFilter1D_Update(&((TSI_WidgetPosFilter1DTypeDef *)sliderMeta->posFilter)[i],
                                                 &sliderMeta->posFilterConf, &tmp);
                }
                slider->pos[i] = tmp;
#else
                slider->pos[i] = peaks[i];
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */
            }
        }
    }
}

TSI_STATIC void TSI_Widget_UpdateSelfCapRadialSlider(TSI_SelfCapRadialSliderTypeDef *slider)
{
    TSI_WidgetTypeDef *sliderBase = (TSI_WidgetTypeDef *)slider;
    TSI_MetaWidgetTypeDef *sliderMeta = sliderBase->meta;
    int i;

    if(slider->onDebounceWidget <= 1U) {
        /* No debounce */
        slider->sliderStat = sliderBase->status;
#if (TSI_WIDGET_POS_FILTER_EN == 1U)
        if(slider->sliderStat == 0U) {
            /* Deinit position filter */
            for(i = 0; i < TSI_SLIDER_FINGER_NUM; i++) {
                TSI_WidgetPosFilter1D_DeInit(&((TSI_WidgetPosFilter1DTypeDef *)sliderMeta->posFilter)[i]);
            }
        }
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */
    }
    else {
        uint8_t *pDebCnt = sliderMeta->debArrayWidget;
        TSI_ASSERT(pDebCnt != NULL);

        /* Add Widget on debounce and update status */
        if(sliderBase->status != 0U) {
            if(*pDebCnt > 0U) {
                (*pDebCnt)--;
            }
            if(*pDebCnt == 0U) {
                /* Update sensor status */
                slider->sliderStat = 1U;
            }
        }
        else {
            /* Reset debounce and status */
            *pDebCnt = slider->onDebounceWidget;
            slider->sliderStat = 0U;
#if (TSI_WIDGET_POS_FILTER_EN == 1U)
            /* Deinit position filter */
            for(i = 0; i < TSI_SLIDER_FINGER_NUM; i++) {
                TSI_WidgetPosFilter1D_DeInit(&((TSI_WidgetPosFilter1DTypeDef *)sliderMeta->posFilter)[i]);
            }
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */
        }
    }

    if(slider->sliderStat == 1U) {
        TSI_MetaWidgetTypeDef *meta = sliderBase->meta;
        uint32_t peakNum;

        /* Update centroid */
        peakNum = TSI_FindPeak1D(meta->sensors, meta->sensorNum);
        if(peakNum != 0UL) {
            uint32_t peaks[TSI_SINGLE_TOUCH_MAX_CENTROID_NUM];
#if (TSI_WIDGET_POS_FILTER_EN == 1U)
            uint16_t maxVal = ((uint16_t)1U << slider->base.resolution);
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */

            (void) TSI_CalcRadialCentroid(peaks, meta->sensorNum, slider->centroidMul);
            for(i = 0; (i < peakNum) && (i < TSI_SLIDER_FINGER_NUM); i++) {
#if (TSI_WIDGET_POS_FILTER_EN == 1U)
                uint16_t tmp = peaks[i];
                if(TSI_WidgetPosFilter1D_IsInited((TSI_WidgetPosFilter1DTypeDef *)meta->posFilter) == 0U) {
                    /* Init position filter with the first position data */
                    TSI_WidgetPosFilter1D_Init(&((TSI_WidgetPosFilter1DTypeDef *)meta->posFilter)[i],
                                               peaks[i]);
                }
                else {
                    /* Filter position data */
                    TSI_WidgetPosFilter1D_UpdateRing(&((TSI_WidgetPosFilter1DTypeDef *)meta->posFilter)[i],
                                                     &meta->posFilterConf, &tmp, maxVal);
                }

                slider->pos[i] = tmp;
#else
                slider->pos[i] = peaks[i];
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */
            }
        }
    }
}

TSI_STATIC void TSI_Widget_UpdateSelfCapTouchpad(TSI_SelfCapTouchpadTypeDef *pad)
{
    TSI_WidgetTypeDef *padBase = (TSI_WidgetTypeDef *)pad;
    TSI_MetaWidgetTypeDef *padMeta = padBase->meta;
    TSI_Meta2DWidgetTypeDef *padMeta2D = (TSI_Meta2DWidgetTypeDef *)padMeta;
    uint32_t tmp;
    uint16_t xTmp, yTmp;
    uint8_t padStateTmpX = 0U, padStateTmpY = 0U;
    int i;

    for(i = 0; i < padMeta->sensorNum; i++) {
        if(padMeta->sensors[i].status == 1U) {
            padStateTmpX = 1U;
            break;
        }
    }
    for(i = 0; i < padMeta2D->sensorRowNum; i++) {
        if(padMeta->sensors[i + padMeta->sensorNum].status == 1U) {
            padStateTmpY = 1U;
            break;
        }
    }
    padBase->status = (padStateTmpX & padStateTmpY);

    if(pad->onDebounceWidget <= 1U) {
        /* No debounce */
        pad->padStat = padBase->status;
#if (TSI_WIDGET_POS_FILTER_EN == 1U)
        if(pad->padStat == 0U) {
            TSI_WidgetPosFilter2D_DeInit((TSI_WidgetPosFilter2DTypeDef *)padMeta->posFilter);
        }
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */
    }
    else {
        uint8_t *pDebCnt = padBase->meta->debArrayWidget;
        TSI_ASSERT(pDebCnt != NULL);

        /* Add Widget on debounce and update status */
        if(padBase->status != 0U) {
            if(*pDebCnt > 0U) {
                (*pDebCnt)--;
            }
            if(*pDebCnt == 0U) {
                /* Update sensor status */
                pad->padStat = 1U;
            }
        }
        else {
            /* Reset debounce and status */
            *pDebCnt = pad->onDebounceWidget;
            pad->padStat = 0U;
#if (TSI_WIDGET_POS_FILTER_EN == 1U)
            /* Deinit position filter */
            TSI_WidgetPosFilter2D_DeInit((TSI_WidgetPosFilter2DTypeDef *)padMeta->posFilter);
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */
        }
    }

    if(pad->padStat != 0U) {
        uint32_t peakNum;

        /* Find X-axis (column) centroid */
        peakNum = TSI_FindPeak1D(padMeta->sensors, padMeta->sensorNum);
        if(peakNum == 1U) {
            (void) TSI_CalcLinearCentroid(&tmp, padMeta->sensorNum, pad->centroidMulX);
            if(tmp > TSI_TOUCHPAD_RESOLUTION) {
                tmp = TSI_TOUCHPAD_RESOLUTION;
            }
            xTmp = tmp;

            /* Find Y-axis (row) centroid */
            peakNum = TSI_FindPeak1D(&padMeta->sensors[padMeta->sensorNum],
                                     ((TSI_Meta2DWidgetTypeDef *)padMeta)->sensorRowNum);

            if(peakNum == 1U) {
                (void) TSI_CalcLinearCentroid(&tmp, padMeta->sensorNum, pad->centroidMulY);
                if(tmp > TSI_TOUCHPAD_RESOLUTION) {
                    tmp = TSI_TOUCHPAD_RESOLUTION;
                }
                yTmp = tmp;

#if (TSI_WIDGET_POS_FILTER_EN == 1U)
                if(TSI_WidgetPosFilter2D_IsInited(
                                        (TSI_WidgetPosFilter2DTypeDef *)padMeta->posFilter) == 0U) {
                    /* Init position filter with the first position data */
                    TSI_WidgetPosFilter2D_Init(
                                    (TSI_WidgetPosFilter2DTypeDef *)padMeta->posFilter,
                                    xTmp, yTmp);
                }
                else {
                    /* Filter position data */
                    TSI_WidgetPosFilter2D_Update(padBase, &xTmp, &yTmp);
                }
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */

                pad->xPos = xTmp;
                pad->yPos = yTmp;
            }
        }
#if (TSI_WIDGET_POS_FILTER_EN == 1U)
        else if(peakNum > 1U) {
            /* Invalid position */
            TSI_WidgetPosFilter2D_DeInit((TSI_WidgetPosFilter2DTypeDef *)padMeta->posFilter);
        }
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */
        else {
            /* Cannot be here. */
            TSI_ASSERT(0U);
        }
    }
}

TSI_STATIC void TSI_Widget_UpdateMutualCapButton(TSI_MutualCapButtonTypeDef *button)
{
    button->buttonStat = button->base.base.status;
}

TSI_STATIC void TSI_Widget_UpdateMutualCapSlider(TSI_MutualCapSliderTypeDef *slider)
{
    TSI_WidgetTypeDef *sliderBase = (TSI_WidgetTypeDef *)slider;
    TSI_MetaWidgetTypeDef *sliderMeta = sliderBase->meta;
    int i;

    if(slider->onDebounceWidget <= 1U) {
        /* No debounce */
        slider->sliderStat = sliderBase->status;
#if (TSI_WIDGET_POS_FILTER_EN == 1U)
        if(slider->sliderStat == 0U) {
            /* Deinit position filter */
            for(i = 0; i < TSI_SLIDER_FINGER_NUM; i++) {
                TSI_WidgetPosFilter1D_DeInit(&((TSI_WidgetPosFilter1DTypeDef *)sliderMeta->posFilter)[i]);
            }
        }
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */
    }
    else {
        uint8_t *pDebCnt = sliderMeta->debArrayWidget;
        TSI_ASSERT(pDebCnt != NULL);

        /* Add Widget on debounce and update status */
        if(sliderBase->status != 0U) {
            if(*pDebCnt > 0U) {
                (*pDebCnt)--;
            }
            if(*pDebCnt == 0U) {
                /* Update sensor status */
                slider->sliderStat = 1U;
            }
        }
        else {
            /* Reset debounce and status */
            *pDebCnt = slider->onDebounceWidget;
            slider->sliderStat = 0U;
#if (TSI_WIDGET_POS_FILTER_EN == 1U)
            /* Deinit position filter */
            for(i = 0; i < TSI_SLIDER_FINGER_NUM; i++) {
                TSI_WidgetPosFilter1D_DeInit(&((TSI_WidgetPosFilter1DTypeDef *)sliderMeta->posFilter)[i]);
            }
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */
        }
    }

    if(slider->sliderStat == 1U) {
        uint32_t peakNum;

        /* Update centroid */
        peakNum = TSI_FindPeak1D(sliderMeta->sensors, sliderMeta->sensorNum);
        if(peakNum != 0UL) {
            uint32_t peaks[TSI_SINGLE_TOUCH_MAX_CENTROID_NUM];

            (void) TSI_CalcLinearCentroid(peaks, sliderMeta->sensorNum, slider->centroidMul);
            for(i = 0; (i < peakNum) && (i < TSI_SLIDER_FINGER_NUM); i++) {
#if (TSI_WIDGET_POS_FILTER_EN == 1U)
                uint16_t tmp = peaks[i];
                if(TSI_WidgetPosFilter1D_IsInited((TSI_WidgetPosFilter1DTypeDef *)sliderMeta->posFilter) == 0U) {
                    /* Init position filter with the first position data */
                    TSI_WidgetPosFilter1D_Init(&((TSI_WidgetPosFilter1DTypeDef *)sliderMeta->posFilter)[i],
                                               peaks[i]);
                }
                else {
                    /* Filter position data */
                    TSI_WidgetPosFilter1D_Update(&((TSI_WidgetPosFilter1DTypeDef *)sliderMeta->posFilter)[i],
                                                 &sliderMeta->posFilterConf, &tmp);
                }

                slider->pos[i] = tmp;
#else
                slider->pos[i] = peaks[i];
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */
            }
        }
    }
}

TSI_STATIC void TSI_Sensor_UpdateStatus(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf,
                                        uint8_t type)
{
    int32_t threshold;
    uint16_t hysteresis;
    uint8_t *pDebCount;
    uint8_t newStatus;
    TSI_WidgetTypeDef *widget = sensor->meta->parent;

    /* Get threshold */
    switch(type) {
        case TSI_SENSOR_STATUS_ACTIVE:
            threshold = detConf->activeTh;
            hysteresis = detConf->activeHys;
            pDebCount = &sensor->meta->debArray[0];
            break;

        case TSI_SENSOR_STATUS_PROX:
            threshold = ((TSI_SelfCapProximityTypeDef *)widget)->proxTh;
            hysteresis = ((TSI_SelfCapProximityTypeDef *)widget)->proxHys;
            pDebCount = &sensor->meta->debArray[1];
            break;

        default:
            /* Type not exists */
            TSI_ASSERT(0U);
            return;
    }

    /* Add hysteresis to threshold */
    threshold = ((sensor->status & type) == 0U) ?
                (threshold + hysteresis) :
                (threshold - hysteresis);

    /* Add debounce and update status */
    newStatus = (sensor->diffCount > threshold) ? type : 0U;
    if((newStatus != (sensor->status & type)) && ((*pDebCount) != 0U)) {
        if(--(*pDebCount) == 0U) {
            sensor->status &= ~type;
            sensor->status |= newStatus;
        }
    }
    else {
#if((TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U))
        if(sensor->bslnVar.bslnMode == TSI_BASELINE_MODE_NORMAL) {
            *pDebCount = ((sensor->status & type) == 0U) ?
                         detConf->onDebounce :
                         detConf->offDebounce;
        }
        else if(sensor->bslnVar.bslnMode == TSI_BASELINE_MODE_LTA) {
            *pDebCount = ((sensor->status & type) == 0U) ?
                         detConf->ltaOnDebounce :
                         detConf->offDebounce;
        }
        else {
            /* Cannot be here */
            TSI_ASSERT(0U);
            return;
        }
#else
        *pDebCount = ((sensor->status & type) == 0U) ?
                     detConf->onDebounce :
                     detConf->offDebounce;
#endif  /* if (TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U) */
    }
}

TSI_STATIC void TSI_NormalBaseline_Init(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf)
{
    uint32_t freq;

    for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
        sensor->baseline[freq] = sensor->rawCount[freq];
        sensor->bslnVar.bslnNegStopCount[freq] = 0U;
        TSI_Filter_IIRInit(&sensor->bslnVar.bslnIIRBuff[freq], sensor->rawCount[freq]);
    }
}

TSI_STATIC void TSI_NormalBaseline_Update(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf)
{
    TSI_WidgetTypeDef *widget = sensor->meta->parent;
    uint32_t freq;

    for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
        int32_t diffCount = (int32_t)sensor->rawCount[freq] - (int32_t)sensor->baseline[freq];
        if(diffCount >= 0) {
            sensor->bslnVar.bslnNegStopCount[freq] = 0U;
        }

        /* Reset baseline when negative stop timeout */
        if(diffCount < -((int32_t)widget->detConf.negNoiseTh)) {
            if(sensor->bslnVar.bslnNegStopCount[freq] >= widget->detConf.bslnNegStopTimeout) {
                TSI_NormalBaseline_Init(sensor, detConf);
            }
            else {
                sensor->bslnVar.bslnNegStopCount[freq]++;
            }
        }
        else {
#if (TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U)
            /*
            When sensor's auto-reset is disabled, baseline only
            updates when diffCount <= noiseTh
            */
            if((diffCount <= (int32_t)detConf->noiseTh) &&
                    diffCount >= -((int32_t)detConf->negNoiseTh)) {
#endif
                uint16_t tmp = sensor->rawCount[freq];
                TSI_Filter_IIRUpdate(&sensor->bslnVar.bslnIIRBuff[freq],
                                     detConf->bslnIIRCoeff, &tmp);
                sensor->baseline[freq] = tmp;
#if (TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U)
            }
#endif
        }
    }
}

#if((TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U))

TSI_STATIC void TSI_LTABaseline_Init(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf)
{
    uint32_t freq;

    TSI_UNUSED(detConf)

    for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
        /* LTA baseline share normal baseline buffer */
        sensor->bslnVar.lta[freq] = sensor->rawCount[freq];
        TSI_Filter_IIRInit(&sensor->bslnVar.ltaIIRBuff[freq], sensor->rawCount[freq]);
    }
    sensor->bslnVar.bslnMode = TSI_BASELINE_MODE_NORMAL;
    sensor->bslnVar.ltaActiveCnt = 0U;
    sensor->bslnVar.ltaBslnStopCnt = 0U;
    sensor->bslnVar.ltaNegErrDebCnt = 0U;
}

TSI_STATIC void TSI_LTABaseline_Update(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf)
{
    uint32_t freq;

    for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
        uint16_t tmp = sensor->rawCount[freq];
        TSI_Filter_IIRUpdate(&sensor->bslnVar.ltaIIRBuff[freq],
                             detConf->bslnIIRCoeff, &tmp);
        sensor->bslnVar.lta[freq] = tmp;
    }
}

TSI_STATIC void TSI_Baseline_ModeJudge(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf)
{
    TSI_BaselineVarTypeDef *bslnVar = &sensor->bslnVar;
    uint32_t freq;

    if(bslnVar->bslnMode == TSI_BASELINE_MODE_NORMAL) {
        /* Sensor active timeout */
        if((sensor->status & TSI_SENSOR_STATUS_ACTIVE) != 0U) {
            bslnVar->ltaActiveCnt++;
        }
        else {
            bslnVar->ltaActiveCnt = 0U;
            /* Normal baseline positive stop timeout */
            if(sensor->diffCount > 0) {
                bslnVar->ltaBslnStopCnt++;
            }
            else {
                bslnVar->ltaBslnStopCnt = 0U;
            }
        }

        /* Update LTA baseline state */
        if((bslnVar->ltaActiveCnt > detConf->ltaActiveTimeout) ||
                (bslnVar->ltaBslnStopCnt > detConf->ltaNormBslnStopTimeout)) {
            /* Sensor active timeout / baseline stop timeout, enter LTA mode */
            bslnVar->bslnMode = TSI_BASELINE_MODE_LTA;
            bslnVar->ltaActiveCnt = 0U;
            bslnVar->ltaBslnStopCnt = 0U;
            memset(sensor->meta->debArray, detConf->onDebounce, sensor->meta->debArraySize);
        }
    }
    else if(bslnVar->bslnMode == TSI_BASELINE_MODE_LTA) {
        if((sensor->status & TSI_SENSOR_STATUS_ACTIVE) != 0U) {
            /* Sensor active: Raise baseline and switch back to normal baseline mode */
            for(freq = 0U; freq < TSI_TOTAL_SCAN_NUM; freq++) {
                sensor->baseline[freq] = sensor->bslnVar.lta[freq];
                sensor->bslnVar.bslnNegStopCount[freq] = 0U;
                TSI_Filter_IIRInit(&sensor->bslnVar.bslnIIRBuff[freq], sensor->bslnVar.lta[freq]);
            }
            bslnVar->bslnMode = TSI_BASELINE_MODE_NORMAL;
        }
        else {
            if(sensor->ltaDiffCount < -(int32_t)detConf->ltaNegErrTh) {
                if(++bslnVar->ltaNegErrDebCnt >= detConf->ltaNegErrorDebounce) {
                    /* LTA reset on negative error */
                    TSI_LTABaseline_Init(sensor, detConf);
                    memset(sensor->meta->debArray, detConf->onDebounce, sensor->meta->debArraySize);
                    bslnVar->ltaNegErrDebCnt = 0U;
                }
            }
            else {
                bslnVar->ltaNegErrDebCnt = 0U;
                if(sensor->diffCount < detConf->noiseTh) {
                    /* Normal baseline recover */
                    bslnVar->bslnMode = TSI_BASELINE_MODE_NORMAL;
                }
            }
        }
    }
    else {
        /* Cannot be here */
        TSI_ASSERT(0U);
        return;
    }
}

#endif  /* if (TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U) */

TSI_STATIC void TSI_Sensor_UpdateDiffCount(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf)
{
    int32_t diffCount;
#if (TSI_SCAN_FREQ_NUM == 3U)
    int32_t diffCountMulti_0, diffCountMulti_2;
#endif  /* if (TSI_SCAN_FREQ_NUM == 3U) */

    /* NOTE: Will not update user-defined scan diffCount. Users should
       process it by themselves. */

    /*---------------------------------------------------#/
        Update normal baseline diffcount.
    #----------------------------------------------------*/
    diffCount = (int32_t)sensor->rawCount[0U] - (int32_t)sensor->baseline[0U];
#if (TSI_SCAN_FREQ_NUM == 3U)
    TSI_DEBUG("sensor(Tx%02d Rx%02d):", sensor->meta->txChannel, sensor->meta->rxChannel);
    TSI_DEBUG("- diff #0: %d", diffCount);
    diffCountMulti_0 = (int32_t)sensor->rawCount[1U] - (int32_t)sensor->baseline[1U];
    diffCountMulti_2 = (int32_t)sensor->rawCount[2U] - (int32_t)sensor->baseline[2U];
    TSI_DEBUG("- diff #1: %d", diffCountMulti_0);
    TSI_DEBUG("- diff #2: %d", diffCountMulti_2);

    /* Take median value as real diffCount */
    if(diffCountMulti_0 < diffCountMulti_2) {
        int32_t swap = diffCountMulti_0;
        diffCountMulti_0 = diffCountMulti_2;
        diffCountMulti_2 = swap;
    }
    if(diffCountMulti_0 > diffCount) {
        if(diffCount < diffCountMulti_2) {
            diffCount = diffCountMulti_2;
        }
    }
    else {
        diffCount = diffCountMulti_0;
    }

    TSI_DEBUG("- select: %d", diffCount);

#endif  /* if (TSI_SCAN_FREQ_NUM == 3U) */

    sensor->diffCount = 0U;
    if(diffCount > (int32_t)detConf->noiseTh) {
        sensor->diffCount = diffCount;
    }

#if((TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U))

    /*---------------------------------------------------#/
        Update LTA baseline diffcount.
    #----------------------------------------------------*/
    diffCount = (int32_t)sensor->rawCount[0U] - (int32_t)sensor->bslnVar.lta[0U];
#if (TSI_SCAN_FREQ_NUM == 3U)
    diffCountMulti_0 = (int32_t)sensor->rawCount[1U] - (int32_t)sensor->bslnVar.lta[1U];
    diffCountMulti_2 = (int32_t)sensor->rawCount[2U] - (int32_t)sensor->bslnVar.lta[2U];

    /* Take median value as real diffCount */
    if(diffCountMulti_0 < diffCountMulti_2) {
        int32_t swap = diffCountMulti_0;
        diffCountMulti_0 = diffCountMulti_2;
        diffCountMulti_2 = swap;
    }
    if(diffCountMulti_0 > diffCount) {
        if(diffCount < diffCountMulti_2) {
            diffCount = diffCountMulti_2;
        }
    }
    else {
        diffCount = diffCountMulti_0;
    }
#endif  /* if (TSI_SCAN_FREQ_NUM == 3U) */
    sensor->ltaDiffCount = diffCount;
#endif  /* if (TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U) */
}

static uint32_t TSI_FindPeak1D(TSI_SensorTypeDef *sensors, uint32_t num)
{
#if (TSI_SINGLE_TOUCH_MAX_CENTROID_NUM == 1U)
    /* Reset variables */
    TSI_Peak1D[0].idx = 0U;
#endif

    TSI_Peak1DNum = 0U;

    /* Sensor num must be greater than 2, or the algorithm will run into fault. */
    if(num >= 2U) {
        TSI_DetectConfTypeDef *widgetDetConf = &sensors[0U].meta->parent->detConf;
        uint16_t widgetTh = widgetDetConf->activeTh - widgetDetConf->activeHys;
        TSI_DetectConfTypeDef *detConf;
        uint16_t threshold;
#if (TSI_SINGLE_TOUCH_MAX_CENTROID_NUM == 1U)
        uint16_t peakSignal = 0U;
#else
        uint32_t idx;
#endif  /* TSI_SINGLE_TOUCH_MAX_CENTROID_NUM == 1U */

#if (TSI_SINGLE_TOUCH_MAX_CENTROID_NUM == 1U)
        /* Find peak value and corresponding sensor */
        TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, sensors, num) {
            /* Get detect configuration */
            detConf = pSensor->meta->detConf;
            if(detConf == NULL) {
                threshold = widgetTh;
            }
            else {
                /* Calclate threshold */
                threshold = detConf->activeTh - detConf->activeHys;
            }

            if(pSensor->diffCount > threshold && pSensor->diffCount > peakSignal) {
                /* Record peak index */
                TSI_Peak1DNum = 1U;
                TSI_Peak1D[0U].idx = idx + 1UL;
                peakSignal = (uint16_t)pSensor->diffCount;
            }
        }
        TSI_FOREACH_END()
#else
        /* Find if first sensor is a peak. */
        detConf = sensors[0U].meta->detConf;
        if(detConf == NULL) {
            threshold = widgetTh;
        }
        else {
            /* Calclate threshold */
            threshold = detConf->activeTh - detConf->activeHys;
        }
        if((sensors[0U].diffCount > threshold) && (sensors[0U].diffCount > sensors[1U].diffCount)) {
            TSI_Peak1D[TSI_Peak1DNum].idx = 1U;
            TSI_Peak1DNum++;
        }
        /* Find if last sensor is a peak. */
        detConf = sensors[num - 1UL].meta->detConf;
        if(detConf == NULL) {
            threshold = widgetTh;
        }
        else {
            /* Calclate threshold */
            threshold = detConf->activeTh - detConf->activeHys;
        }
        if((sensors[num - 1UL].diffCount > threshold) && (sensors[num - 1UL].diffCount >= sensors[num - 2UL].diffCount)) {
            TSI_Peak1D[TSI_Peak1DNum].idx = (uint8_t)(num - 1UL);
            TSI_Peak1DNum++;
        }
        /* Find peaks among sensors. */
        for(idx = 1UL; idx < (num - 1UL) && (TSI_Peak1DNum < TSI_SINGLE_TOUCH_MAX_CENTROID_NUM); idx++) {
            detConf = sensors[idx].meta->detConf;
            if(detConf == NULL) {
                threshold = widgetTh;
            }
            else {
                /* Calclate threshold */
                threshold = detConf->activeTh - detConf->activeHys;
            }
            if((sensors[idx].diffCount > threshold) && (sensors[idx].diffCount >= sensors[idx + 1UL].diffCount) &&
                    (sensors[idx].diffCount > sensors[idx - 1UL].diffCount)) {
                /* Is peak */
                TSI_Peak1D[TSI_Peak1DNum].idx = idx + 1UL;
                TSI_Peak1DNum++;
            }
        }
#endif  /* TSI_SINGLE_TOUCH_MAX_CENTROID_NUM == 1U */

        if(TSI_Peak1DNum != 0U) {
            int i;
            for(i = 0; i < TSI_Peak1DNum; i++) {
                TSI_Peak1DTypeDef *pData = &TSI_Peak1D[i];
                uint8_t peakIndex = TSI_Peak1D[i].idx;
                pData->signals[TSI_PEAK_POS_IDX] = sensors[peakIndex - 1U].diffCount;
                /* Get neighbour sensors signal value */
                if(peakIndex == 1U) {
                    pData->signals[TSI_PEAK_POS_PREV_IDX] = sensors[num - 1U].diffCount;
                    pData->signals[TSI_PEAK_POS_NEXT_IDX] = sensors[peakIndex].diffCount;
                }
                else if(peakIndex == num) {
                    pData->signals[TSI_PEAK_POS_PREV_IDX] = sensors[peakIndex - 2U].diffCount;
                    pData->signals[TSI_PEAK_POS_NEXT_IDX] = sensors[0U].diffCount;
                }
                else {
                    pData->signals[TSI_PEAK_POS_PREV_IDX] = sensors[peakIndex - 2U].diffCount;
                    pData->signals[TSI_PEAK_POS_NEXT_IDX] = sensors[peakIndex].diffCount;
                }
            }
        }

        return (uint32_t)TSI_Peak1DNum;
    }

    return 0UL;
}

static uint32_t TSI_CalcLinearCentroid(uint32_t *centroid, uint32_t snsNum, int32_t mul)
{
    int i;
    int32_t tmp;

    for(i = 0; i < TSI_Peak1DNum; i++) {
        TSI_Peak1DTypeDef *pData = &TSI_Peak1D[i];

        /* No end-to-end connection, clear first and last signal. */
        if(pData->idx == 1U) {
            pData->signals[TSI_PEAK_POS_PREV_IDX] = 0U;
        }
        else if(pData->idx == snsNum) {
            pData->signals[TSI_PEAK_POS_NEXT_IDX] = 0U;
        }
        else {
            /* Do nothing. */
        }

        /* Calculate centroid. */
        tmp = ((int32_t)pData->signals[TSI_PEAK_POS_NEXT_IDX] -
               (int32_t)pData->signals[TSI_PEAK_POS_PREV_IDX]) * mul /
              ((int32_t)pData->signals[0] + (int32_t)pData->signals[1] +
               (int32_t)pData->signals[2]);
        tmp += (pData->idx - 1U) * mul;
        tmp /= (int32_t)256;
        centroid[i] = ((tmp > 0) ? (uint32_t)tmp : 0UL);
    }

    return (uint32_t)TSI_Peak1DNum;
}

static uint32_t TSI_CalcRadialCentroid(uint32_t *centroid, uint32_t snsNum, int32_t mul)
{
    int i;
    int32_t tmp;

    for(i = 0; i < TSI_Peak1DNum; i++) {
        TSI_Peak1DTypeDef *pData = &TSI_Peak1D[i];

        /* Calculate centroid. */
        tmp = ((int32_t)pData->signals[TSI_PEAK_POS_NEXT_IDX] -
               (int32_t)pData->signals[TSI_PEAK_POS_PREV_IDX]) * mul /
              ((int32_t)pData->signals[0] + (int32_t)pData->signals[1] +
               (int32_t)pData->signals[2]);
        tmp += (pData->idx - 1U) * mul;
        if(tmp < 0) {
            tmp += ((int32_t)snsNum * (int32_t) mul);
        }
        tmp /= (int32_t)256;
        centroid[i] = ((tmp > 0) ? (uint32_t)tmp : 0UL);
    }

    return (uint32_t)TSI_Peak1DNum;
}
