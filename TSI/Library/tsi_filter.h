#ifndef TSI_FILTER_H
#define TSI_FILTER_H

#include "tsi_object.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Filter APIs declaration --------------------------------------------------*/
void TSI_Filter_Init(TSI_SensorTypeDef *sensor);
void TSI_Filter_Bypass(TSI_SensorTypeDef *sensor);
void TSI_Filter_Update(TSI_SensorTypeDef *sensor);

void TSI_Filter_Avg4OrderInit(uint16_t *buffer, uint16_t initVal);
void TSI_Filter_Avg4OrderUpdate(uint16_t *buffer, uint16_t *input);

void TSI_Filter_Avg2OrderInit(uint16_t *buffer, uint16_t initVal);
void TSI_Filter_Avg2OrderUpdate(uint16_t *buffer, uint16_t *input);

void TSI_Filter_Med3OrderInit(uint16_t *buffer, uint16_t initVal);
void TSI_Filter_Med3OrderUpdate(uint16_t *buffer, uint16_t *input);

void TSI_Filter_IIRInit(uint32_t *buffer, uint16_t initVal);
void TSI_Filter_IIRUpdate(uint32_t *buffer, uint8_t coef, uint16_t *input);

void TSI_Filter_FastSlowIIRInit(uint32_t *buffer, uint16_t *switchDebCnt, uint16_t initVal);
void TSI_Filter_FastSlowIIRUpdate(uint32_t *buffer, uint16_t *switchDebCnt, uint16_t *input);

void TSI_Filter_ADVIIRInit(uint32_t *buffer, uint16_t initVal);
void TSI_Filter_ADVIIRUpdate(uint32_t *buffer, uint16_t *input, uint8_t filterMode);

#if (TSI_WIDGET_POS_FILTER_EN == 1U)

/* Widget filter APIs declaration -------------------------------------------*/
/* 1D position filter */
void TSI_WidgetPosFilter1D_Init(TSI_WidgetPosFilter1DTypeDef* filter, uint16_t initVal);
void TSI_WidgetPosFilter1D_DeInit(TSI_WidgetPosFilter1DTypeDef* filter);
uint8_t TSI_WidgetPosFilter1D_IsInited(TSI_WidgetPosFilter1DTypeDef* filter);
void TSI_WidgetPosFilter1D_Update(TSI_WidgetPosFilter1DTypeDef* filter, TSI_WidgetPosFilterConfTypeDef* conf, uint16_t* input);
void TSI_WidgetPosFilter1D_UpdateRing(TSI_WidgetPosFilter1DTypeDef* filter, TSI_WidgetPosFilterConfTypeDef* conf, 
    uint16_t* input, uint16_t maxVal);
/* 2D position filter */
void TSI_WidgetPosFilter2D_Init(TSI_WidgetPosFilter2DTypeDef* filter, uint16_t initValX, uint16_t initValY);
void TSI_WidgetPosFilter2D_DeInit(TSI_WidgetPosFilter2DTypeDef* filter);
uint8_t TSI_WidgetPosFilter2D_IsInited(TSI_WidgetPosFilter2DTypeDef* filter);
void TSI_WidgetPosFilter2D_Update(TSI_WidgetTypeDef* widget, uint16_t* inputX, uint16_t* inputY);

#endif /* TSI_WIDGET_POS_FILTER_EN == 1U */

#ifdef __cplusplus
}
#endif

#endif  /* TSI_FILTER_H */
