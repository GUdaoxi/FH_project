#include "tsi_object.h"
#include "tsi_driver.h"
#include "tsi.h"
#include "tsi_plugin.h"

/* Configurations -----------------------------------------------------------*/
/** Plugin version string. */
#define TSI_PLUGIN_VERSION                  "v1.0"

/* USER CONFIGURATION BEGIN */
/** Plugin call priority(0-7). Lower value means higher priority. */
#define TSI_PLUGIN_PRIORITY                 "7"
/* USER CONFIGURATION END */
/* Defines ------------------------------------------------------------------*/

/* Function prototypes ------------------------------------------------------*/

/* Variables ----------------------------------------------------------------*/
static TSI_USED uint16_t TSI_RecordedRawData[TSI_SENSOR_NUM] = { 0U };

/* Function implementations -------------------------------------------------*/
static void TSI_Widget_ScanCompletedCallback(TSI_LibHandleTypeDef *handle)
{
    TSI_FOREACH_IDX(TSI_SensorTypeDef * sensor, handle->driver->sensors,
                    handle->driver->sensorNum, 0U) {
        /* Record sensor raw data (of central freq). */
#if (TSI_NORM_FILTER_EN || TSI_PROX_FILTER_EN)
        TSI_RecordedRawData[sensor->meta->id] = sensor->bslnVar.sensorBuffer[0];
#else
        TSI_RecordedRawData[sensor->meta->id] = sensor->rawCount[0];
#endif
    }
    TSI_FOREACH_END()
}

/* Plugin registration ------------------------------------------------------*/
TSI_PLUGIN(TSITunerRawData, TSI_PLUGIN_PRIORITY)
{
    NULL,                               /* initCompleted */
    NULL,                               /* deInitCompleted */
    NULL,                               /* started */
    NULL,                               /* stopped */
    NULL,                               /* widgetInitCompleted */
    TSI_Widget_ScanCompletedCallback,   /* widgetScanCompleted */
    NULL,                               /* widgetValueUpdated */
    NULL,                               /* widgetStatusUpdated */
    NULL,                               /* getInitScanBufferAndCount */
    NULL,                               /* processInitScanValue */
};
