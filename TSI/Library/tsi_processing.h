#ifndef TSI_PROCESSING_H
#define TSI_PROCESSING_H

#include "tsi_object.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Widget APIs declaration --------------------------------------------------*/
TSI_RetCode TSI_Widget_InitAll(TSI_LibHandleTypeDef *handle);
TSI_RetCode TSI_Widget_Init(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget);
TSI_RetCode TSI_Widget_EnableAll(TSI_LibHandleTypeDef *handle);
TSI_RetCode TSI_Widget_Enable(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget);
TSI_RetCode TSI_Widget_DisableAll(TSI_LibHandleTypeDef *handle);
TSI_RetCode TSI_Widget_Disable(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget);
void TSI_Widget_UpdateAll(TSI_LibHandleTypeDef *handle);

/* Sensor APIs declaration --------------------------------------------------*/
void TSI_Sensor_Init(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf);

/* Baseline APIs declaration ------------------------------------------------*/
void TSI_Baseline_Init(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf);
void TSI_Baseline_Update(TSI_SensorTypeDef *sensor, TSI_DetectConfTypeDef *detConf);

#ifdef __cplusplus
}
#endif

#endif  /* TSI_PROCESSING_H */
