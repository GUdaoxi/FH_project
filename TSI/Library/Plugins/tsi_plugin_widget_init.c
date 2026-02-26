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
#define TSI_PLUGIN_PRIORITY                 "0"

/** Init times. */
#define TSI_INIT_TIME                       (10U)

/** Init by maximum value. */
#define TSI_INIT_MAX                        (1U)

/** Init by average value. */
#define TSI_INIT_AVR                        (0U)

/** Init by median value. */
#define TSI_INIT_MED                        (0U)
/* USER CONFIGURATION END */
/* Defines ------------------------------------------------------------------*/

/* Function prototypes ------------------------------------------------------*/
#if TSI_INIT_MED
    static uint16_t getMedian(int *arr, int length);
#endif
/* Variables ----------------------------------------------------------------*/
static uint16_t scanBuffer[TSI_INIT_TIME * TSI_TOTAL_SCAN_NUM];
static uint16_t mutualBuffer[TSI_INIT_TIME * TSI_MAX_SCANGROUP_SENSOR_NUM * TSI_TOTAL_SCAN_NUM];

/* Function implementations -------------------------------------------------*/
static uint32_t TSI_GetInitScanBufferAndCountCallback(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget, TSI_SensorTypeDef *sensor, uint16_t **ppBuffer)
{
    if(TSI_WIDGET_IS_SELF_CAP(widget)) {
        *ppBuffer = scanBuffer;
        return TSI_INIT_TIME;
    }
    else if(TSI_WIDGET_IS_MUTUAL_CAP(widget)) {
        *ppBuffer = mutualBuffer;
        return TSI_INIT_TIME;
    }
    else {
        /* Do nothing. */
    }
    return 0U;
}
static void TSI_ProcessInitScanValueCallback(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget, TSI_SensorTypeDef *sensor, uint16_t *pValueBuffer)
{
#if (TSI_INIT_MAX != 0U)
    int i, freq;
    uint16_t tmp = 0U;
    if(TSI_WIDGET_IS_SELF_CAP(widget)) {
        for(freq = 0; freq < TSI_TOTAL_SCAN_NUM; freq++) {
            tmp = 0U;
            for(i = 0; i < TSI_INIT_TIME; i++) {
                int idx = i * TSI_SCAN_FREQ_NUM + freq;
                if(tmp < scanBuffer[idx]) {
                    pValueBuffer[freq] = scanBuffer[idx];
                    tmp = pValueBuffer[freq];
                }
            }
        }
    }
    else if(TSI_WIDGET_IS_MUTUAL_CAP(widget)) {
        for(freq = 0; freq < TSI_TOTAL_SCAN_NUM; freq++) {
            tmp = 0U;
            for(i = 0; i < TSI_INIT_TIME; i++) {
                int idx = i * TSI_SCAN_FREQ_NUM + freq;
                if(tmp < mutualBuffer[idx]) {
                    pValueBuffer[freq] = mutualBuffer[idx];
                    tmp = pValueBuffer[freq];
                }
            }
        }
    }
    else {
        /* Do nothing. */
    }

#elif (TSI_INIT_AVR != 0U)
    int i, freq;
    uint32_t tmp = 0U;
    if(TSI_WIDGET_IS_SELF_CAP(widget)) {
        for(freq = 0; freq < TSI_TOTAL_SCAN_NUM; freq++) {
            tmp = 0U;
            for(i = 0; i < TSI_INIT_TIME; i++) {
                tmp += scanBuffer[i * TSI_SCAN_FREQ_NUM + freq];
            }
            pValueBuffer[freq] = tmp / TSI_INIT_TIME;
        }
    }
    else if(TSI_WIDGET_IS_MUTUAL_CAP(widget)) {
        for(freq = 0; freq < TSI_TOTAL_SCAN_NUM; freq++) {
            tmp = 0U;
            for(i = 0; i < TSI_INIT_TIME; i++) {
                tmp += mutualBuffer[i * TSI_SCAN_FREQ_NUM + freq];
            }
            pValueBuffer[freq] = tmp / TSI_INIT_TIME;
        }
    }
    else {
        /* Do nothing. */
    }

#elif (TSI_INIT_MED != 0U)
    int i, freq;
    int tmp[TSI_INIT_TIME] = {0};
    if(TSI_WIDGET_IS_SELF_CAP(widget)) {
        for(freq = 0; freq < TSI_TOTAL_SCAN_NUM; freq++) {
            for(i = 0; i < TSI_INIT_TIME; i++) {
                tmp[i] = scanBuffer[i * TSI_SCAN_FREQ_NUM + freq];
            }
            pValueBuffer[freq] = getMedian(tmp, TSI_INIT_TIME);
        }
    }
    else if(TSI_WIDGET_IS_MUTUAL_CAP(widget)) {
        for(freq = 0; freq < TSI_TOTAL_SCAN_NUM; freq++) {
            for(i = 0; i < TSI_INIT_TIME; i++) {
                tmp[i] = mutualBuffer[i * TSI_SCAN_FREQ_NUM + freq];
            }
            pValueBuffer[freq] = getMedian(tmp, TSI_INIT_TIME);
        }
    }
    else {
        /* Do nothing. */
    }
#endif
}

#if TSI_INIT_MED
static uint16_t getMedian(int *arr, int length)
{
    int t;
    for(int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                t = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = t;
            }
        }
    }
    int medianIndex1 = length / 2;
    int medianIndex2 = length / 2 - 1;
    double median;

    if(length % 2 == 0) {
        median = (arr[medianIndex1] + arr[medianIndex2]) / 2.0;
    }
    else {
        median = arr[medianIndex1];
    }
    return median;
}
#endif

/* Plugin registration ------------------------------------------------------*/
TSI_PLUGIN(WidgetInit, TSI_PLUGIN_PRIORITY)
{
    NULL,                                   /* initCompleted */
    NULL,                                   /* deInitCompleted */
    NULL,                                   /* started */
    NULL,                                   /* stopped */
    NULL,                                   /* widgetInitCompleted */
    NULL,                                   /* widgetScanCompleted */
    NULL,                                   /* widgetValueUpdated */
    NULL,                                   /* widgetStatusUpdated */
    TSI_GetInitScanBufferAndCountCallback,  /* getInitScanBufferAndCount */
    TSI_ProcessInitScanValueCallback,       /* processInitScanValue */
};
