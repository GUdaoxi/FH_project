#ifndef TSI_H
#define TSI_H

#include "tsi_object.h"
#include "tsi_processing.h"

/** TSI Library version number. */
#define TSI_VERSION_MAIN            (0x01U)     /*!< [31:24] main version */
#define TSI_VERSION_SUB1            (0x00U)     /*!< [23:16] sub1 version */
#define TSI_VERSION_SUB2            (0x02U)     /*!< [15:0]  sub2 version */
#define TSI_VERSION                 ((TSI_VERSION_MAIN  << 24U)\
                                         |(TSI_VERSION_SUB1 << 16U)\
                                         |(TSI_VERSION_SUB2))

#ifdef __cplusplus
extern "C" {
#endif

/* Library APIs declaration -------------------------------------------------*/
/* Control APIs */
void TSI_ResetLibHandle(TSI_LibHandleTypeDef *handle);
TSI_RetCode TSI_Init(TSI_LibHandleTypeDef *handle);
TSI_RetCode TSI_DeInit(TSI_LibHandleTypeDef *handle);
TSI_RetCode TSI_Start(TSI_LibHandleTypeDef *handle);
TSI_RetCode TSI_Suspend(TSI_LibHandleTypeDef *handle);
TSI_RetCode TSI_Resume(TSI_LibHandleTypeDef *handle);
TSI_RetCode TSI_ScanAndInitWidget(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget);
TSI_RetCode TSI_ScanAndInitAllWidgets(TSI_LibHandleTypeDef *handle);

/* Processing APIs */
void TSI_Handler(TSI_LibHandleTypeDef *handle);

#if (TSI_USE_TIMEBASE == 1U)
/* Timebase APIs */
void TSI_IncTick(TSI_LibHandleTypeDef *handle, uint32_t tick);
uint32_t TSI_GetTick(TSI_LibHandleTypeDef *handle);
#if (TSI_SCAN_USE_TIMEBASE == 1U)
void TSI_ScanIntvTimeout(void *context);
#endif  /* TSI_SCAN_USE_TIMEBASE == 1U */
#endif  /* TSI_USE_TIMEBASE == 1U */

#if (TSI_USED_IN_LPM_MODE == 1U)
/* Low-power mode(LPM) APIs */
void TSI_EnterLPM(TSI_LibHandleTypeDef *handle);
void TSI_LeaveLPM(TSI_LibHandleTypeDef *handle);
void TSI_LPMBlockHandler(TSI_LibHandleTypeDef *handle);
#endif  /* TSI_USED_IN_LPM_MODE == 1U */

/* TSI library callbacks declarations ---------------------------------------*/
void TSI_WidgetUpdateCpltCallback(TSI_LibHandleTypeDef *handle);
void TSI_ScanOverrunCallback(TSI_LibHandleTypeDef *handle);
void TSI_ScanErrorCallback(TSI_LibHandleTypeDef *handle);

#ifdef __cplusplus
}
#endif

#endif  /* TSI_H */
