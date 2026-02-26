/* Includes -----------------------------------------------------------------*/
#include "tsi_object.h"
#include "tsi_processing.h"
#include "tsi_calibration.h"
#include "tsi_plugin.h"
#include "tsi.h"
#include <stdbool.h>

/* Configurations -----------------------------------------------------------*/
/** Plugin version string. */
#define TSI_PLUGIN_VERSION                  "v1.0"

/* USER CONFIGURATION BEGIN */
/** Plugin call priority(0-7). Lower value means higher priority. */
#define TSI_PLUGIN_PRIORITY                 "1"

/**
 *  Widget high margin.
 *
 *  * maxValue: Refer maximum rawcount.
 *  * widget: Refer widget object.
 */
#define TSI_WIDGET_HIGH_MARGIN              (maxValue - (3UL * (widget->detConf.activeTh)))

/**
 *  Widget low margin.
 *
 *  * maxValue: Refer maximum rawcount.
 *  * widget: Refer widget object.
 */
#define TSI_WIDGET_LOW_MARGIN               (maxValue / 20U)
/* USER CONFIGURATION END */
/* Defines ------------------------------------------------------------------*/

/* Function prototypes ------------------------------------------------------*/
static bool TSI_Widget_IsBaselineAtMargin(TSI_WidgetTypeDef *widget);

/* Variables ----------------------------------------------------------------*/

/* Function implementations -------------------------------------------------*/
static void TSI_Widget_StatusUpdateCallback(TSI_LibHandleTypeDef *handle)
{
    TSI_FOREACH_OBJ(TSI_WidgetTypeDef **, ppWidget, handle->widgets,
                    handle->widgetNum) {
        if((*ppWidget)->enable == TSI_WIDGET_ENABLE) {
            if(TSI_Widget_IsBaselineAtMargin(*ppWidget)) {
                /* Re-calibrate widget IDAC */
                TSI_Suspend(handle);
                if(TSI_WIDGET_IS_SELF_CAP(*ppWidget)) {
                    TSI_CalibrateSelfCapWidget(handle, *ppWidget, TSI_SC_CALIB_COMP_IDAC);
                }
                else {
                    /* Do nothing. */
                }
                TSI_Resume(handle);
            }
        }
    }
    TSI_FOREACH_END()
}

static bool TSI_Widget_IsBaselineAtMargin(TSI_WidgetTypeDef *widget)
{
    uint16_t realSnsNum;
    uint32_t limitHi, limitLo;
    uint32_t maxValue;

    /* Calculate baseline margin limit */
    if(TSI_WIDGET_IS_SELF_CAP(widget)) {
        maxValue = (0x1UL << ((TSI_SelfCapWidgetTypeDef *)widget)->resolution);
    }
    else {
        /* Not supported */
        return false;
    }
    limitHi = TSI_WIDGET_HIGH_MARGIN;
    limitLo = TSI_WIDGET_LOW_MARGIN;

    if(widget->meta->dedicatedScanGroup != NULL) {
        realSnsNum = 1U;
    }
    else {
        realSnsNum = widget->meta->sensorNum;
    }

    /* If one sensor is over margin limit, calibrate all sensors. */
    TSI_FOREACH_OBJ(TSI_SensorTypeDef *, pSensor, widget->meta->sensors,
                    realSnsNum) {
        if((pSensor->baseline[0] > limitHi) || (pSensor->baseline[0] < limitLo)) {
            return true;
        }
    }
    TSI_FOREACH_END()

    return false;
}

/* Plugin registration ------------------------------------------------------*/
TSI_PLUGIN(SCMarginCalibration, TSI_PLUGIN_PRIORITY)
{
    NULL,                               /* initCompleted */
    NULL,                               /* deInitCompleted */
    NULL,                               /* started */
    NULL,                               /* stopped */
    NULL,                               /* widgetInitCompleted */
    NULL,                               /* widgetValueUpdated */
    NULL,                               /* widgetScanCompleted */
    TSI_Widget_StatusUpdateCallback,    /* widgetStatusUpdated */
    NULL,                               /* getInitScanBufferAndCount */
    NULL,                               /* processInitScanValue */
};
