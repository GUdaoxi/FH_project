#include "tsi_utils.h"
#include "tsi_driver.h"

uint32_t TSI_CalcSelfCapSensorCap(TSI_ClockConfTypeDef *clockConf, TSI_SensorTypeDef *sensor, uint8_t update)
{
    TSI_SelfCapWidgetTypeDef *scWidget;
    uint32_t tmpFsw;
    uint32_t tmpCs;
    uint32_t tmpCntPercent;

    TSI_ASSERT(TSI_WIDGET_IS_SELF_CAP(sensor->meta->parent));

    scWidget = (TSI_SelfCapWidgetTypeDef *) sensor->meta->parent;
    tmpCntPercent = (((uint32_t)sensor->rawCount[0U]) * 1000UL) / ((1UL << scWidget->resolution) - 1UL);
    tmpFsw = TSI_Dev_GetSCSwitchClock(clockConf, scWidget->swClkDiv);
#if (TSI_SC_USE_UNIFIED_IDAC_STEP == 0U)
    tmpCs = (uint32_t)((((uint64_t)scWidget->idacMod[0U] * tmpCntPercent * TSI_Dev_IDACCurrentTable[scWidget->idacStep])
                        + ((uint64_t)sensor->idac[0U] * 1000UL) * TSI_Dev_IDACCurrentTable[scWidget->idacCompStep]) /
                       ((uint64_t)TSI_VREF_MV * tmpFsw / 1000UL));
#else
    tmpCs = (uint32_t)(((uint64_t)(scWidget->idacMod[0U] * tmpCntPercent + ((uint64_t)sensor->idac[0U] * 1000UL))
                        * TSI_Dev_IDACCurrentTable[scWidget->idacStep]) /
                       ((uint64_t)TSI_VREF_MV * tmpFsw / 1000UL));
#endif

#if (TSI_STATISTIC_SENSOR_CS == 1U)
    /* Update sensor cap value if needed */
    if((update != 0U) && (sensor->meta->capVal != NULL)) {
        *sensor->meta->capVal = tmpCs;
    }
#else
    TSI_UNUSED(update)
#endif

    return tmpCs;   /* Unit: fF */
}

uint32_t TSI_CalcMutualCapSensorCap(TSI_ClockConfTypeDef *clockConf, TSI_SensorTypeDef *sensor, uint8_t update)
{
    TSI_MutualCapWidgetTypeDef *mcWidget;
    uint32_t tmpFtx;
    uint32_t tmpCs;
    uint32_t tmpCntPercent;

    TSI_ASSERT(TSI_WIDGET_IS_MUTUAL_CAP(sensor->meta->parent));

    mcWidget = (TSI_MutualCapWidgetTypeDef *) sensor->meta->parent;
    tmpCntPercent = 1000UL - (((uint32_t)sensor->rawCount[0U] * 1000UL)
                              / ((1UL << mcWidget->resolution) - 1UL));
    tmpFtx = TSI_Dev_GetMCTXClock(clockConf, mcWidget->txClkDiv);
    tmpCs = (uint32_t)(((uint64_t)sensor->idac[0U] * tmpCntPercent * TSI_Dev_IDACCurrentTable[mcWidget->idacStep])
                       / ((uint64_t)TSI_DEV_VDD_MV * 2ULL * tmpFtx / 1000UL));

#if (TSI_STATISTIC_SENSOR_CS == 1U)
    /* Update sensor cap value if needed */
    if((update != 0U) && (sensor->meta->capVal != NULL)) {
        *sensor->meta->capVal = tmpCs;
    }
#else
    TSI_UNUSED(update)
#endif

    return tmpCs;   /* Unit: fF */
}

void TSI_InitTimer(TSI_TimerContextTypeDef *context, TSI_TimerTypeDef *timer,
                   uint32_t period, TSI_TimerCallBackFuncTypeDef cb)
{
    TSI_ASSERT(context != NULL);
    TSI_ASSERT(timer != NULL);
    TSI_ASSERT(cb != NULL);

    timer->period = period;
    timer->context = context;
    timer->begin = 0U;
    timer->callback = cb;
    timer->next = NULL;
}

void TSI_StartTimer(TSI_TimerTypeDef *timer)
{
    TSI_ASSERT(timer != NULL);

    if(timer->used != 0U) {
        /* Timer already started. */
        return;
    }
    /* Setup begin time. */
    timer->begin = timer->context->timeBaseTick;

    /* Add timer to the list. */
    timer->next = timer->context->head;
    timer->context->head = timer;
    timer->used = 1U;
}

void TSI_RestartTimer(TSI_TimerTypeDef *timer)
{
    TSI_ASSERT(timer != NULL);

    if(timer->used == 0U) {
        /* Timer not started, call TSI_StartTimer() instead. */
        TSI_StartTimer(timer);
        return;
    }

    /* Reset timeout */
    timer->begin = timer->context->timeBaseTick;
}

void TSI_StopTimer(TSI_TimerTypeDef *timer)
{
    TSI_TimerTypeDef **currTimer;

    TSI_ASSERT(timer != NULL);

    if(timer->used == 0U) {
        /* Timer already stopped. */
        return;
    }
    /* Remove timer from the list. */
    for(currTimer = &timer->context->head; *currTimer != NULL;) {
        TSI_TimerTypeDef *entry = *currTimer;
        if(entry == timer) {
            *currTimer = entry->next;
            timer->used = 0U;
            break;
        }
        currTimer = &entry->next;
    }
}

void TSI_TimerHandler(TSI_TimerContextTypeDef *context)
{
    TSI_TimerTypeDef *timer;
    uint32_t tick = context->timeBaseTick;

    TSI_ASSERT(context != NULL);

    if(tick == 0UL) {
        /* Tick has not advanced. */
        return;
    }
    for(timer = context->head; timer != NULL; timer = timer->next) {
        if(tick - timer->begin >= timer->period) {
            /* Timer timeout, reload */
            timer->begin = tick;
            /* Notify using callback */
            timer->callback(context->context);
        }
    }
}

void TSI_IncTimerTick(TSI_TimerContextTypeDef *context, uint32_t tick)
{
    context->timeBaseTick += tick;
}

uint32_t TSI_GetTimerTick(TSI_TimerContextTypeDef *context)
{
    return context->timeBaseTick;
}
