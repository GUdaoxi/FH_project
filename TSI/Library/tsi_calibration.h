#ifndef TSI_CALIBRATION_H
#define TSI_CALIBRATION_H

#include "tsi_object.h"

/* Calibration Mode assert --------------------------------------------------*/
#if((TSI_SC_CALIB_METHOD == TSI_SC_CALIB_HW_PARAM) && \
    (TSI_DEV_SUPPORT_SC_CALIB_HW_PARAM == 0U))
#error "Selected self-cap widget calibration method is not supported by this device."
#elif((TSI_SC_CALIB_METHOD == TSI_SC_CALIB_BOTH_IDAC) && \
      (TSI_DEV_SUPPORT_SC_CALIB_BOTH_IDAC == 0U))
#error "Selected self-cap widget calibration method is not supported by this device."
#elif((TSI_SC_CALIB_METHOD == TSI_SC_CALIB_COMP_IDAC) && \
      (TSI_DEV_SUPPORT_SC_CALIB_COMP_IDAC == 0U))
#error "Selected self-cap widget calibration method is not supported by this device."
#endif

#if((TSI_MC_CALIB_METHOD == TSI_MC_CALIB_IDAC) && \
      (TSI_DEV_SUPPORT_MC_CALIB_IDAC == 0U))
#error "Selected self-cap widget calibration method is not supported by this device."
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Calibration APIs declaration ---------------------------------------------*/
TSI_RetCode TSI_CalibrateAllWidgets(TSI_LibHandleTypeDef *handle);
TSI_RetCode TSI_CalibrateWidget(TSI_LibHandleTypeDef *handle, TSI_WidgetTypeDef *widget);
TSI_RetCode TSI_CalibrateSelfCapWidget(TSI_LibHandleTypeDef *handle,
                                       TSI_WidgetTypeDef *widget,
                                       uint8_t method);
TSI_RetCode TSI_CalibrateMutualCapWidget(TSI_LibHandleTypeDef *handle,
        TSI_WidgetTypeDef *widget, uint8_t method);

#ifdef __cplusplus
}
#endif

#endif  /* TSI_CALIBRATION_H */
