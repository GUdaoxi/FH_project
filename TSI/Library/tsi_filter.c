#include "tsi_filter.h"

/* Macros -------------------------------------------------------------------*/
#define DELTA(X, Y)         (((X) > (Y)) ? ((X) - (Y)) : ((Y) - (X)))

/* Defines ------------------------------------------------------------------*/
static const uint32_t ADVIIR_COEFF_PERF_QP = 30U;
static const int32_t ADVIIR_COEFF_PERF[2][4] = {
    {16761928, 33523857, 16761928, 0},
    {1073741824, -1735991514, 729297403, 0},
};

static const uint32_t ADVIIR_COEFF_FAST_QP = 30U;
static const int32_t ADVIIR_COEFF_FAST[2][4] = {
    {171812690, 515438070, 515438070, 171812690},
    {1073741824, -53043456, 358606952, -4824679},
};

/* API implementations ------------------------------------------------------*/
void TSI_Filter_Init(TSI_SensorTypeDef *sensor)
{
#if ((TSI_NORM_FILTER_EN == 1U) || (TSI_PROX_FILTER_EN == 1U))
    const TSI_MetaSensorTypeDef *metaSensor = sensor->meta;
    uint32_t freq;

    for(freq = 0U; freq < TSI_SCAN_FREQ_NUM; freq++) {
        uint16_t tmpVal = sensor->bslnVar.sensorBuffer[freq];
        if(metaSensor->filterType == TSI_FILTER_NORMAL) {
#if (TSI_NORM_FILTER_EN == 1U)
            TSI_NormSnsFilterTypeDef *filter = &((TSI_NormSnsFilterTypeDef *)metaSensor->filter)[freq];
#if (TSI_NORM_FILTER_MEDIAN_EN == 1U)
            TSI_Filter_Med3OrderInit(filter->medBuff, tmpVal);
#endif  /* TSI_REGULAR_FILTER_MEDIAN_EN == 1U */
#if (TSI_NORM_FILTER_IIR_EN == 1U)
            TSI_Filter_IIRInit(&filter->normIIRBuff, tmpVal);
#endif  /* TSI_REGULAR_FILTER_IIR_EN == 1U */
#if (TSI_NORM_FILTER_FSIIR_EN == 1U)
            TSI_Filter_FastSlowIIRInit(filter->fsIIRBuff, &filter->fsIIRDebCnt, tmpVal);
#endif  /* TSI_NORM_FILTER_FSIIR_EN == 1U */
#if (TSI_NORM_FILTER_AVERAGE_EN == 1U)
            TSI_Filter_Avg4OrderInit(filter->avgBuff, tmpVal);
#endif  /* TSI_REGULAR_FILTER_AVERAGE_EN == 1U */

#if ((TSI_NORM_FILTER_AVERAGE_EN == 0U) &&  \
     (TSI_NORM_FILTER_MEDIAN_EN == 0U) &&   \
     (TSI_NORM_FILTER_IIR_EN == 0U) &&      \
     (TSI_NORM_FILTER_FSIIR_EN == 0U) &&    \
     (TSI_NORM_FILTER_FSIIR_EN == 0U))
            /* Avoid compiler warnings. */
            TSI_UNUSED(filter)
#endif
#endif  /* TSI_NORM_FILTER_EN == 1U */
        }
        else if(metaSensor->filterType == TSI_FILTER_PROXMITY) {
#if (TSI_PROX_FILTER_EN == 1U)
            TSI_ProxSnsFilterTypeDef *filter = &((TSI_ProxSnsFilterTypeDef *)metaSensor->filter)[freq];
#if (TSI_PROX_FILTER_MEDIAN_EN == 1U)
            TSI_Filter_Med3OrderInit(filter->medBuff, tmpVal);
#endif  /* TSI_PROX_FILTER_MEDIAN_EN == 1U */
#if (TSI_PROX_FILTER_ADVIIR_EN == 1U)
            TSI_Filter_ADVIIRInit(filter->advIIRBuff, tmpVal);
#endif  /* TSI_PROX_FILTER_IIR_EN == 1U */
#if (TSI_PROX_FILTER_FSIIR_EN == 1U)
            TSI_Filter_FastSlowIIRInit(filter->fsIIRBuff, &filter->fsIIRDebCnt, tmpVal);
#endif  /* TSI_PROX_FILTER_FSIIR_EN == 1U */
#if (TSI_PROX_FILTER_AVERAGE_EN == 1U)
            TSI_Filter_Avg4OrderInit(filter->avgBuff, tmpVal);
#endif  /* TSI_PROX_FILTER_AVERAGE_EN == 1U */
#if ((TSI_PROX_FILTER_AVERAGE_EN == 0U) &&  \
     (TSI_PROX_FILTER_MEDIAN_EN == 0U) &&   \
     (TSI_PROX_FILTER_IIR_EN == 0U) &&      \
     (TSI_PROX_FILTER_FSIIR_EN == 0U) &&    \
     (TSI_PROX_FILTER_FSIIR_EN == 0U))
            /* Avoid compiler warnings. */
            TSI_UNUSED(filter)
#endif
#endif  /* TSI_PROX_FILTER_EN == 1U */
        }
        else {
            /* Do nothing */
            TSI_ASSERT(0U);
        }

        /* Init sensor rawCount. */
        sensor->rawCount[freq] = tmpVal;
    }
#endif  /* (TSI_NORM_FILTER_EN == 1U) || (TSI_PROX_FILTER_EN == 1U) */

#if (TSI_USER_SCAN_FREQ_NUM > 0U)
    {
        uint32_t freq;
        for(freq = 0U; freq < TSI_USER_SCAN_FREQ_NUM; freq++) {
            /* Init sensor rawCount. */
            sensor->rawCount[TSI_SCAN_FREQ_NUM + freq] = sensor->bslnVar.sensorUserBuffer[freq];
        }
    }
#endif  /* (TSI_USER_SCAN_FREQ_NUM > 0U) */
}

void TSI_Filter_Bypass(TSI_SensorTypeDef *sensor)
{
#if ((TSI_NORM_FILTER_EN == 1U) || (TSI_PROX_FILTER_EN == 1U))
    {
        uint32_t freq;
        for(freq = 0U; freq < TSI_SCAN_FREQ_NUM; freq++)
        {
            /* Load buffer to rawCount, bypassing filters. */
            sensor->rawCount[freq] = sensor->bslnVar.sensorBuffer[freq];
        }
    }
#endif  /* (TSI_NORM_FILTER_EN == 1U) || (TSI_PROX_FILTER_EN == 1U) */

#if (TSI_USER_SCAN_FREQ_NUM > 0U)
    {
        uint32_t freq;
        for(freq = 0U; freq < TSI_USER_SCAN_FREQ_NUM; freq++)
        {
            /* Load buffer to rawCount, bypassing filters. */
            sensor->rawCount[TSI_SCAN_FREQ_NUM + freq] = sensor->bslnVar.sensorUserBuffer[freq];
        }
    }
#endif  /* (TSI_USER_SCAN_FREQ_NUM > 0U) */
}

void TSI_Filter_Update(TSI_SensorTypeDef *sensor)
{
#if ((TSI_NORM_FILTER_EN == 1U) || (TSI_PROX_FILTER_EN == 1U))
    const TSI_MetaSensorTypeDef *metaSensor = sensor->meta;
    uint32_t freq;

    for(freq = 0U; freq < TSI_SCAN_FREQ_NUM; freq++) {
        uint16_t tmpVal = sensor->bslnVar.sensorBuffer[freq];
        if(metaSensor->filterType == TSI_FILTER_NORMAL) {
#if (TSI_NORM_FILTER_EN == 1U)
            TSI_NormSnsFilterTypeDef *filter = &((TSI_NormSnsFilterTypeDef *)metaSensor->filter)[freq];
#if (TSI_NORM_FILTER_MEDIAN_EN == 1U)
            TSI_Filter_Med3OrderUpdate(filter->medBuff, &tmpVal);
#endif  /* TSI_NORM_FILTER_MEDIAN_EN == 1U */
#if (TSI_NORM_FILTER_IIR_EN == 1U)
            TSI_Filter_IIRUpdate(&filter->normIIRBuff, TSI_NORM_FILTER_IIR_COEF, &tmpVal);
#endif  /* TSI_NORM_FILTER_IIR_EN == 1U */
#if (TSI_NORM_FILTER_FSIIR_EN == 1U)
            TSI_Filter_FastSlowIIRUpdate(filter->fsIIRBuff, &filter->fsIIRDebCnt, &tmpVal);
#endif  /* TSI_NORM_FILTER_FSIIR_EN == 1U */
#if (TSI_NORM_FILTER_AVERAGE_EN == 1U)
            TSI_Filter_Avg4OrderUpdate(filter->avgBuff, &tmpVal);
#endif  /* TSI_NORM_FILTER_AVERAGE_EN == 1U */

#if ((TSI_NORM_FILTER_AVERAGE_EN == 0U) &&  \
     (TSI_NORM_FILTER_MEDIAN_EN == 0U) &&   \
     (TSI_NORM_FILTER_IIR_EN == 0U) &&      \
     (TSI_NORM_FILTER_FSIIR_EN == 0U) &&    \
     (TSI_NORM_FILTER_FSIIR_EN == 0U))
            /* Avoid compiler warnings. */
            TSI_UNUSED(filter)
#endif
#endif  /* TSI_NORM_FILTER_EN == 1U */
        }
        else if(metaSensor->filterType == TSI_FILTER_PROXMITY) {
#if (TSI_PROX_FILTER_EN == 1U)
            TSI_ProxSnsFilterTypeDef *filter = &((TSI_ProxSnsFilterTypeDef *)metaSensor->filter)[freq];
#if (TSI_PROX_FILTER_MEDIAN_EN == 1U)
            TSI_Filter_Med3OrderUpdate(filter->medBuff, &tmpVal);
#endif  /* TSI_PROX_FILTER_MEDIAN_EN == 1U */
#if (TSI_PROX_FILTER_ADVIIR_EN == 1U)
            TSI_Filter_ADVIIRUpdate(filter->advIIRBuff, &tmpVal, filter->advIIRMode);
#endif  /* TSI_PROX_FILTER_IIR_EN == 1U */
#if (TSI_PROX_FILTER_FSIIR_EN == 1U)
            TSI_Filter_FastSlowIIRUpdate(filter->fsIIRBuff, &filter->fsIIRDebCnt, &tmpVal);
#endif  /* TSI_PROX_FILTER_FSIIR_EN == 1U */
#if (TSI_PROX_FILTER_AVERAGE_EN == 1U)
            TSI_Filter_Avg4OrderUpdate(filter->avgBuff, &tmpVal);
#endif  /* TSI_PROX_FILTER_AVERAGE_EN == 1U */

#if ((TSI_PROX_FILTER_AVERAGE_EN == 0U) &&  \
     (TSI_PROX_FILTER_MEDIAN_EN == 0U) &&   \
     (TSI_PROX_FILTER_IIR_EN == 0U) &&      \
     (TSI_PROX_FILTER_FSIIR_EN == 0U) &&    \
     (TSI_PROX_FILTER_FSIIR_EN == 0U))
            /* Avoid compiler warnings. */
            TSI_UNUSED(filter)
#endif
#endif  /* TSI_PROX_FILTER_EN == 1U */
        }
        else {
            /* Do nothing */
            TSI_ASSERT(0U);
        }
        /* Update sensor rawCount with filtered value. */
        sensor->rawCount[freq] = tmpVal;
    }
#endif /*(TSI_NORM_FILTER_EN == 1U) || (TSI_PROX_FILTER_EN == 1U) */
}

void TSI_Filter_Avg4OrderInit(uint16_t *buffer, uint16_t initVal)
{
    buffer[0] = buffer[1] = buffer[2] = initVal;
}

void TSI_Filter_Avg4OrderUpdate(uint16_t *buffer, uint16_t *input)
{
    uint32_t result = ((uint32_t)buffer[0] + (uint32_t)buffer[1] +
                       (uint32_t)buffer[2] + (uint32_t) * input) >> 2U;
    buffer[0] = buffer[1];
    buffer[1] = buffer[2];
    buffer[2] = *input;
    *input = (uint16_t)(result & 0xFFFFU);
}

void TSI_Filter_Avg2OrderInit(uint16_t *buffer, uint16_t initVal)
{
    buffer[0] = initVal;
}

void TSI_Filter_Avg2OrderUpdate(uint16_t *buffer, uint16_t *input)
{
    uint32_t result = ((uint32_t)buffer[0] + (uint32_t) * input) >> 1U;
    buffer[0] = *input;
    *input = (uint16_t)(result & 0xFFFFU);
}

void TSI_Filter_Med3OrderInit(uint16_t *buffer, uint16_t initVal)
{
    buffer[0] = buffer[1] = initVal;
}

void TSI_Filter_Med3OrderUpdate(uint16_t *buffer, uint16_t *input)
{
    uint16_t tmpA, tmpB;

    tmpA = buffer[0];
    tmpB = buffer[1];
    if(tmpA < tmpB) {
        tmpA = buffer[1];
        tmpB = buffer[0];
    }
    if(tmpA > *input) {
        tmpA = *input > tmpB ? *input : tmpB;
    }

    buffer[0] = buffer[1];
    buffer[1] = *input;
    *input = (uint16_t)(tmpA & 0xFFFFU);
}

void TSI_Filter_IIRInit(uint32_t *buffer, uint16_t initVal)
{
    buffer[0] = (uint32_t)initVal << 7U;
}

void TSI_Filter_IIRUpdate(uint32_t *buffer, uint8_t coef, uint16_t *input)
{
    uint32_t tmpQ7;
    uint32_t inputQ7 = ((uint32_t) * input) << 7U;

    /*
        buffer[0]: Y(N-1) ==> Fix-Point Number(Q7)
        y(N) = (coef * x(N) + (256 - coef) * y(N-1)) / K, K = 256
    */
    tmpQ7 = ((uint64_t)coef * inputQ7 + (uint64_t)(256U - coef) * buffer[0]) >> 8U;
    buffer[0] = tmpQ7;
    *input = tmpQ7 >> 7U;
}

/* 快慢IIR */
void TSI_Filter_FastSlowIIRInit(uint32_t *buffer, uint16_t *switchDebCnt, uint16_t initVal)
{
    buffer[0] = buffer[1] = (uint32_t) initVal << 7U;
    *switchDebCnt = 0U;
}

void TSI_Filter_FastSlowIIRUpdate(uint32_t *buffer, uint16_t *switchDebCnt, uint16_t *input)
{
    uint32_t tmpQ7Slow, tmpQ7Fast;
    uint32_t inputQ7 = ((uint32_t) * input) << 7U;

    tmpQ7Fast = ((uint64_t)(TSI_NORM_FILTER_FSIIR_FAST_COEF * inputQ7) +
                 (uint64_t)((256U - TSI_NORM_FILTER_FSIIR_FAST_COEF) * buffer[0])) >> 8U;
    buffer[0] = tmpQ7Fast;
    tmpQ7Slow = ((uint64_t)(TSI_NORM_FILTER_FSIIR_SLOW_COEF * inputQ7) +
                 (uint64_t)((256U - TSI_NORM_FILTER_FSIIR_SLOW_COEF) * buffer[1])) >> 8U;
    buffer[1] = tmpQ7Slow;

    if(DELTA((tmpQ7Fast >> 7U), (tmpQ7Slow >> 7U)) < TSI_NORM_FILTER_FSIIR_SW_THRESHOLD) {
        *switchDebCnt = 0U;
        *input = tmpQ7Slow >> 7U;
    }
    else {
        (*switchDebCnt)++;
        if((*switchDebCnt) > TSI_NORM_FILTER_FSIIR_SW_DEBOUNCE) {
            buffer[1] = tmpQ7Fast;
            *input = tmpQ7Fast >> 7U;
        }
        else {
            *input = tmpQ7Slow >> 7U;
        }
    }
}

void TSI_Filter_ADVIIRInit(uint32_t *buffer, uint16_t initVal)
{
    int i;
    int32_t *filterBuf = (int32_t *)buffer;

    for(i = 0; i < 6; i++) {
        filterBuf[i] = ((int32_t)initVal) << 15U;
    }
}

void TSI_Filter_ADVIIRUpdate(uint32_t *buffer, uint16_t *input, uint8_t filterMode)
{
    int32_t tmpQ15;
    int32_t inputQ15 = ((int32_t) * input) << 15U;
    int32_t *filterBuf = (int32_t *)buffer;

    /*
        buffer[6]: X(N-1), X(N-2), X(N-3), Y(N-1), Y(N-2), Y(N-3)
        coef[0]: b[4]
        coef[1]: a[4]
    */
    if(filterMode == 0) {
        tmpQ15 = - (((int64_t)ADVIIR_COEFF_PERF[1][1] * (int64_t)filterBuf[3]) >> ADVIIR_COEFF_PERF_QP)
                 - (((int64_t)ADVIIR_COEFF_PERF[1][2] * (int64_t)filterBuf[4]) >> ADVIIR_COEFF_PERF_QP)
                 - (((int64_t)ADVIIR_COEFF_PERF[1][3] * (int64_t)filterBuf[5]) >> ADVIIR_COEFF_PERF_QP)
                 + (((int64_t)ADVIIR_COEFF_PERF[0][0] * (int64_t)inputQ15) >> ADVIIR_COEFF_PERF_QP)
                 + (((int64_t)ADVIIR_COEFF_PERF[0][1] * (int64_t)filterBuf[0]) >> ADVIIR_COEFF_PERF_QP)
                 + (((int64_t)ADVIIR_COEFF_PERF[0][2] * (int64_t)filterBuf[1]) >> ADVIIR_COEFF_PERF_QP)
                 + (((int64_t)ADVIIR_COEFF_PERF[0][3] * (int64_t)filterBuf[2]) >> ADVIIR_COEFF_PERF_QP);
    }
    else {
        tmpQ15 = - (((int64_t)ADVIIR_COEFF_FAST[1][1] * (int64_t)filterBuf[3]) >> ADVIIR_COEFF_FAST_QP)
                 - (((int64_t)ADVIIR_COEFF_FAST[1][2] * (int64_t)filterBuf[4]) >> ADVIIR_COEFF_FAST_QP)
                 - (((int64_t)ADVIIR_COEFF_FAST[1][3] * (int64_t)filterBuf[5]) >> ADVIIR_COEFF_FAST_QP)
                 + (((int64_t)ADVIIR_COEFF_FAST[0][0] * (int64_t)inputQ15) >> ADVIIR_COEFF_FAST_QP)
                 + (((int64_t)ADVIIR_COEFF_FAST[0][1] * (int64_t)filterBuf[0]) >> ADVIIR_COEFF_FAST_QP)
                 + (((int64_t)ADVIIR_COEFF_FAST[0][2] * (int64_t)filterBuf[1]) >> ADVIIR_COEFF_FAST_QP)
                 + (((int64_t)ADVIIR_COEFF_FAST[0][3] * (int64_t)filterBuf[2]) >> ADVIIR_COEFF_FAST_QP);
    }

    filterBuf[2] = filterBuf[1];
    filterBuf[1] = filterBuf[0];
    filterBuf[0] = inputQ15;
    filterBuf[5] = filterBuf[4];
    filterBuf[4] = filterBuf[3];
    filterBuf[3] = tmpQ15;

    *input = (uint16_t)(tmpQ15 >> 15U);
}

#if (TSI_WIDGET_POS_FILTER_EN == 1U)

void TSI_WidgetPosFilter1D_Init(TSI_WidgetPosFilter1DTypeDef *filter, uint16_t initVal)
{
#if (TSI_WIDGET_POS_FILTER_MEDIAN_EN == 1U)
    TSI_Filter_Med3OrderInit(filter->medBuff, initVal);
#endif  /* TSI_WIDGET_POS_FILTER_MEDIAN_EN == 1U */
#if (TSI_WIDGET_POS_FILTER_AVERAGE_EN == 1U)
    TSI_Filter_Avg2OrderInit(&filter->avgBuff, initVal);
#endif  /* TSI_WIDGET_POS_FILTER_AVERAGE_EN == 1U */
#if (TSI_WIDGET_POS_FILTER_IIR_EN == 1U)
    TSI_Filter_IIRInit(&filter->normIIRBuff, initVal);
#endif  /* TSI_WIDGET_POS_FILTER_IIR_EN == 1U */

#if ((TSI_WIDGET_POS_FILTER_MEDIAN_EN == 0U) &&     \
     (TSI_WIDGET_POS_FILTER_AVERAGE_EN == 0U) &&    \
     (TSI_WIDGET_POS_FILTER_IIR_EN == 0U))
    /* Avoid compiler errors. */
    TSI_UNUSED(filter)
    TSI_UNUSED(initVal)
#endif

    filter->isInited = 1U;
}

void TSI_WidgetPosFilter1D_DeInit(TSI_WidgetPosFilter1DTypeDef *filter)
{
    filter->isInited = 0U;
}

uint8_t TSI_WidgetPosFilter1D_IsInited(TSI_WidgetPosFilter1DTypeDef *filter)
{
    return filter->isInited;
}

void TSI_WidgetPosFilter1D_Update(TSI_WidgetPosFilter1DTypeDef *filter, TSI_WidgetPosFilterConfTypeDef *conf,
                                  uint16_t *input)
{
#if (TSI_WIDGET_POS_FILTER_MEDIAN_EN == 1U)
    if(conf->confBits & TSI_WIDGET_POS_FILTER_USE_MEDIAN_MASK) {
        TSI_Filter_Med3OrderUpdate(filter->medBuff, input);
    }
#endif  /* TSI_WIDGET_POS_FILTER_MEDIAN_EN == 1U */
#if (TSI_WIDGET_POS_FILTER_IIR_EN == 1U)
    if(conf->confBits & TSI_WIDGET_POS_FILTER_USE_IIR_MASK) {
        TSI_Filter_IIRUpdate(&filter->normIIRBuff, conf->iirCoef, input);
    }
#endif  /* TSI_WIDGET_POS_FILTER_IIR_EN == 1U */
#if (TSI_WIDGET_POS_FILTER_AVERAGE_EN == 1U)
    if(conf->confBits & TSI_WIDGET_POS_FILTER_USE_AVERAGE_MASK) {
        TSI_Filter_Avg2OrderUpdate(&filter->avgBuff, input);
    }
#endif  /* TSI_WIDGET_POS_FILTER_AVERAGE_EN == 1U */

#if ((TSI_WIDGET_POS_FILTER_MEDIAN_EN == 0U) &&     \
     (TSI_WIDGET_POS_FILTER_AVERAGE_EN == 0U) &&    \
     (TSI_WIDGET_POS_FILTER_IIR_EN == 0U))
    /* Avoid compiler errors. */
    TSI_UNUSED(filter)
    TSI_UNUSED(input)
#endif
}

void TSI_WidgetPosFilter1D_UpdateRing(TSI_WidgetPosFilter1DTypeDef *filter, TSI_WidgetPosFilterConfTypeDef *conf,
                                      uint16_t *input, uint16_t maxVal)
{
    uint16_t halfMaxVal = (maxVal >> 1U);
    uint16_t xn = *input;   /* x(n) */

#if (TSI_WIDGET_POS_FILTER_MEDIAN_EN == 1U)
    if(conf->confBits & TSI_WIDGET_POS_FILTER_USE_MEDIAN_MASK) {
        uint16_t xn1 = filter->medBuff[0];      /* x(n-1) */
        uint16_t xn2 = filter->medBuff[1];      /* x(n-2) */
        int32_t deltaXnXn1 = (int32_t)xn - (int32_t)xn1;
        int32_t deltaXn1Xn2 = (int32_t)xn1 - (int32_t)xn2;

        if(deltaXnXn1 < -halfMaxVal) {
            xn += maxVal;
        }
        if(deltaXnXn1 > halfMaxVal) {
            filter->medBuff[0] += maxVal;
            filter->medBuff[1] += maxVal;
        }
        if(deltaXn1Xn2 < -halfMaxVal) {
            xn += maxVal;
            filter->medBuff[1] += maxVal;
        }
        if(deltaXn1Xn2 > halfMaxVal) {
            filter->medBuff[0] += maxVal;
        }

        TSI_Filter_Med3OrderUpdate(filter->medBuff, &xn);

        if(xn > maxVal) {
            xn -= maxVal;
        }
        filter->medBuff[0] = xn2;
        filter->medBuff[1] = *input;
    }
#endif  /* TSI_WIDGET_POS_FILTER_MEDIAN_EN == 1U */
#if (TSI_WIDGET_POS_FILTER_IIR_EN == 1U)
    if(conf->confBits & TSI_WIDGET_POS_FILTER_USE_IIR_MASK) {
        uint32_t halfMaxValQ7 = (halfMaxVal << 7U);
        if(filter->normIIRBuff > (xn + halfMaxValQ7)) {
            xn += halfMaxValQ7;
        }
        if(xn > (filter->normIIRBuff + halfMaxValQ7)) {
            filter->normIIRBuff += halfMaxValQ7;
        }

        TSI_Filter_IIRUpdate(&filter->normIIRBuff, conf->iirCoef, &xn);

        if(xn > maxVal) {
            xn -= maxVal;
            filter->normIIRBuff -= (maxVal << 7U);
        }
    }
#endif  /* TSI_WIDGET_POS_FILTER_IIR_EN == 1U */
#if (TSI_WIDGET_POS_FILTER_AVERAGE_EN == 1U)
    if(conf->confBits & TSI_WIDGET_POS_FILTER_USE_AVERAGE_MASK) {
        uint16_t tmp = xn;
        int32_t deltaXnXn1 = (int32_t)xn - (int32_t)filter->avgBuff;
        if(deltaXnXn1 < -halfMaxVal) {
            xn += maxVal;
        }
        if(deltaXnXn1 > halfMaxVal) {
            filter->avgBuff += maxVal;
        }

        TSI_Filter_Avg2OrderUpdate(&filter->avgBuff, &xn);

        if(xn > maxVal) {
            xn -= maxVal;
        }
        filter->avgBuff = tmp;
    }
#endif  /* TSI_WIDGET_POS_FILTER_AVERAGE_EN == 1U */

#if ((TSI_WIDGET_POS_FILTER_MEDIAN_EN == 0U) &&     \
     (TSI_WIDGET_POS_FILTER_AVERAGE_EN == 0U) &&    \
     (TSI_WIDGET_POS_FILTER_IIR_EN == 0U))
    /* Avoid compiler errors. */
    TSI_UNUSED(filter)
    TSI_UNUSED(input)
#endif

    *input = xn;
}

void TSI_WidgetPosFilter2D_Init(TSI_WidgetPosFilter2DTypeDef *filter, uint16_t initValX, uint16_t initValY)
{
    TSI_WidgetPosFilter1D_Init(&filter->xFilter, initValX);
    TSI_WidgetPosFilter1D_Init(&filter->yFilter, initValY);
}

void TSI_WidgetPosFilter2D_DeInit(TSI_WidgetPosFilter2DTypeDef *filter)
{
    filter->xFilter.isInited = 0U;
}

uint8_t TSI_WidgetPosFilter2D_IsInited(TSI_WidgetPosFilter2DTypeDef *filter)
{
    return filter->xFilter.isInited;
}

void TSI_WidgetPosFilter2D_Update(TSI_WidgetTypeDef *widget, uint16_t *inputX, uint16_t *inputY)
{
    TSI_WidgetPosFilter1DTypeDef *xFilter = &((TSI_WidgetPosFilter2DTypeDef *)widget->meta->posFilter)->xFilter;
    TSI_WidgetPosFilter1DTypeDef *yFilter = &((TSI_WidgetPosFilter2DTypeDef *)widget->meta->posFilter)->yFilter;
    TSI_WidgetPosFilterConfTypeDef *conf = (TSI_WidgetPosFilterConfTypeDef *)&widget->meta->posFilterConf;

#if (TSI_WIDGET_POS_FILTER_MEDIAN_EN == 1U)
    if(conf->confBits & TSI_WIDGET_POS_FILTER_USE_MEDIAN_MASK) {
        TSI_Filter_Med3OrderUpdate(xFilter->medBuff, inputX);
        TSI_Filter_Med3OrderUpdate(yFilter->medBuff, inputY);
    }
#endif  /* TSI_WIDGET_POS_FILTER_MEDIAN_EN == 1U */
#if (TSI_WIDGET_POS_FILTER_AVERAGE_EN == 1U)
    if(conf->confBits & TSI_WIDGET_POS_FILTER_USE_AVERAGE_MASK) {
        TSI_Filter_Avg2OrderUpdate(&xFilter->avgBuff, inputX);
        TSI_Filter_Avg2OrderUpdate(&yFilter->avgBuff, inputY);
    }
#endif  /* TSI_WIDGET_POS_FILTER_AVERAGE_EN == 1U */
#if (TSI_WIDGET_POS_FILTER_IIR_EN == 1U)
    if(conf->confBits & TSI_WIDGET_POS_FILTER_USE_IIR_MASK) {
        TSI_Filter_IIRUpdate(&xFilter->normIIRBuff, conf->iirCoef, inputX);
        TSI_Filter_IIRUpdate(&yFilter->normIIRBuff, conf->iirCoef, inputY);
    }
#endif  /* TSI_WIDGET_POS_FILTER_IIR_EN == 1U */

#if ((TSI_WIDGET_POS_FILTER_MEDIAN_EN == 0U) &&     \
     (TSI_WIDGET_POS_FILTER_AVERAGE_EN == 0U) &&    \
     (TSI_WIDGET_POS_FILTER_IIR_EN == 0U))
    /* Avoid compiler errors. */
    TSI_UNUSED(widget)
#endif
}

#endif /* TSI_WIDGET_POS_FILTER_EN == 1U */
