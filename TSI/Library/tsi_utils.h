#ifndef TSI_UTILS_H
#define TSI_UTILS_H

#include "tsi_object.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Defines ----------------------------------------------------------*/
typedef struct _TSI_Timer TSI_TimerTypeDef;
typedef struct _TSI_TimerContext TSI_TimerContextTypeDef;
typedef void (*TSI_TimerCallBackFuncTypeDef)(void *context);

/** Software timer struct definition. */
struct _TSI_Timer {
    /** Timeout begin tick. */
    uint32_t begin;

    /** Set to 1 if timer is used, which means it has been started. */
    uint32_t used : 1U;

    /** Tick period. */
    uint32_t period : 31U;

    /** Timeout callback. */
    TSI_TimerCallBackFuncTypeDef callback;

    /** Timer context */
    TSI_TimerContextTypeDef *context;

    /** Pointer to next item. */
    TSI_TimerTypeDef *next;
};


/** Software timer context definition. */
struct _TSI_TimerContext {
    /** Timer context. */
    void *context;

    /** Timebase tick counter. */
    volatile uint32_t timeBaseTick;

    /** Timer list head. */
    TSI_TimerTypeDef *head;
};

/* Utility APIs declaration -----------------------------------------*/
/* Sensor capcitance calculation APIs */
uint32_t TSI_CalcSelfCapSensorCap(TSI_ClockConfTypeDef *clock, TSI_SensorTypeDef *sensor, uint8_t update);
uint32_t TSI_CalcMutualCapSensorCap(TSI_ClockConfTypeDef *clock, TSI_SensorTypeDef *sensor, uint8_t update);

/* Software timer APIs */
void TSI_InitTimer(TSI_TimerContextTypeDef *context, TSI_TimerTypeDef *timer,
                   uint32_t period, TSI_TimerCallBackFuncTypeDef cb);
void TSI_StartTimer(TSI_TimerTypeDef *timer);
void TSI_RestartTimer(TSI_TimerTypeDef *timer);
void TSI_StopTimer(TSI_TimerTypeDef *timer);
void TSI_TimerHandler(TSI_TimerContextTypeDef *context);
void TSI_IncTimerTick(TSI_TimerContextTypeDef *context, uint32_t tick);
uint32_t TSI_GetTimerTick(TSI_TimerContextTypeDef *context);

#ifdef __cplusplus
}
#endif

#endif  /* TSI_UTILS_H */
