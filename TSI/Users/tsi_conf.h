#ifndef TSI_CONF_H
#define TSI_CONF_H

/* Includes -----------------------------------------------------------------*/
#include <stdint.h>
#include "tsi_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Exported library defines -------------------------------------------------*/
#define TSI_WIDGET_ENABLE                       (1U)
#define TSI_WIDGET_DISABLE                      (0U)

#define TSI_SC_CALIB_NONE                       (0U)
#define TSI_SC_CALIB_HW_PARAM                   (1U)
#define TSI_SC_CALIB_BOTH_IDAC                  (2U)
#define TSI_SC_CALIB_COMP_IDAC                  (3U)

#define TSI_MC_CALIB_NONE                       (0U)
#define TSI_MC_CALIB_IDAC                       (1U)

/*---------------------------------------------------------------------------*/
/* Library configurations                                                    */
/*---------------------------------------------------------------------------*/
/** Library debug log output level. */
#define TSI_DEBUG_LEVEL                         (0U)

/**
 * Use library plugins. This enables dispatching library callback to multiple
 * plugins.
 */
#define TSI_USE_PLUGIN                          (1U)

/** Use configruation descriptor. */
#define TSI_USE_CONFIG_DESCRIPTOR               (1U)

/** Use timebase. */
#define TSI_USE_TIMEBASE                        (1U)

/** Timebase tick time (Unit: us). */
#define TSI_TIMEBASE_US                         (1000U)

#if (TSI_USE_TIMEBASE == 1U)
/** Enables accurate scan interval controlling. */
#define TSI_SCAN_USE_TIMEBASE                   (0U)

/** Scan period (Unit: tick). */
#define TSI_SCAN_PERIOD_TICK                    (20U)
#endif  /* TSI_USE_TIMEBASE == 1U */

/* Driver maximum scan group sensor num */
#define TSI_MAX_SCANGROUP_SENSOR_NUM            (8U)

/**
 * Number of multi-frequency scan's freqency.
 *
 * * 1: single scan.
 * * 3: scan with 3 different frequency.
 */
#define TSI_SCAN_FREQ_NUM                       (3U)

/**
 * Number of user-defined scan.
 * .. important:: Library will not apply filter(s) and update diffCount for
 * user-defined scan. Users should process these steps in `widgetScanCompleted`
 * callback.
 *
 * * 0: no user-defined scan.
 * * 1: single scan.
 */
#define TSI_USER_SCAN_FREQ_NUM                  (0U)

/**
 * Unified Self-cap widget modulation IDAC and compensation IDAC step.
 * * 0: Use seperate step. `TSI_SelfWidgetTypeDef` will have `idacStep` for
 *      modulation IDAC, and `idacCompStep` for compensation IDAC.
 * * 1: Use unified step. `TSI_SelfWidgetTypeDef` will have `idacStep` for both
 *      IDAC.
 */
#define TSI_SC_USE_UNIFIED_IDAC_STEP            (0U)

/* Calibration method */
#define TSI_SC_CALIB_METHOD                     (TSI_SC_CALIB_COMP_IDAC)
#define TSI_MC_CALIB_METHOD                     (TSI_MC_CALIB_NONE)

/* Auto IDAC step switch */
#define TSI_SC_CALIB_AUTO_IDAC_STEP             (1U)

/* Sense clock auto selection */
#define TSI_SC_CALIB_AUTO_SNSCLK_SRC            (0U)
#define TSI_MC_CALIB_AUTO_SNSCLK_SRC            (0U)

/* TSI module features ------------------------------------------------------*/
/* Use shield in self-cap scan (0 - not used, 1 - used) */
#define TSI_USE_SHIELD                          (1U)

/* Use DMA(0 - not used, 1 - used) */
#define TSI_USE_DMA                             (0U)

/* Sensor filter configurations ---------------------------------------------*/
/** Enable/disable normal sensor filters. */
#define TSI_NORM_FILTER_EN                      (1U)

/** Enable/disable normal channel average filter. */
#define TSI_NORM_FILTER_AVERAGE_EN              (1U)

/** Enable/disable normal channel median filter. */
#define TSI_NORM_FILTER_MEDIAN_EN               (1U)

/** Enable/disable normal channel first order IIR filter. */
#define TSI_NORM_FILTER_IIR_EN                  (0U)
#define TSI_NORM_FILTER_IIR_COEF                (64U)

/** Enable/disable normal channel fast-slow IIR filter. */
#define TSI_NORM_FILTER_FSIIR_EN                (0U)
#define TSI_NORM_FILTER_FSIIR_SLOW_COEF         (16U)
#define TSI_NORM_FILTER_FSIIR_FAST_COEF         (64U)
#define TSI_NORM_FILTER_FSIIR_SW_THRESHOLD      (10U)
#define TSI_NORM_FILTER_FSIIR_SW_DEBOUNCE       (5U)

/** Enable/disable proximity channel filters. */
#define TSI_PROX_FILTER_EN                      (0U)

/** Enable/disable proximity channel average filter. */
#define TSI_PROX_FILTER_AVERAGE_EN              (0U)

/** Enable/disable proximity channel median filter. */
#define TSI_PROX_FILTER_MEDIAN_EN               (0U)

/** Enable/disable proximity channel fast-slow IIR filter. */
#define TSI_PROX_FILTER_FSIIR_EN                (0U)
#define TSI_PROX_FILTER_FSIIR_SLOW_COEF         (0U)
#define TSI_PROX_FILTER_FSIIR_FAST_COEF         (0U)
#define TSI_PROX_FILTER_FSIIR_SW_THRESHOLD      (0U)
#define TSI_PROX_FILTER_FSIIR_SW_DEBOUNCE       (0U)

/** Enable/disable proximity channel advanced 2-stage IIR filter. */
#define TSI_PROX_FILTER_ADVIIR_EN               (0U)

/* Widget filter configurations ---------------------------------------------*/
/** Enable/disable widget position filters. */
#define TSI_WIDGET_POS_FILTER_EN                (0U)

/** Enable/disable widget position average filter. */
#define TSI_WIDGET_POS_FILTER_AVERAGE_EN        (0U)

/** Enable/disable widget position median filter. */
#define TSI_WIDGET_POS_FILTER_MEDIAN_EN         (0U)

/** Enable/disable widget position first order IIR filter. */
#define TSI_WIDGET_POS_FILTER_IIR_EN            (0U)

/* TSI widget features ------------------------------------------------------*/
/* Single touch widget maximum centroids number. */
#define TSI_SINGLE_TOUCH_MAX_CENTROID_NUM       (1U)

/* Mutual-cap Touchpad(Multi touch widget) maximum centroids number. */
#define TSI_MUTUAL_TOUCHPAD_MAX_CENTROID_NUM    (1U)

/* Baseline algorithm configurations ----------------------------------------*/
/**
 *  Always update sensor baseline.
 *
 * * 1: Yes, baseline always follows rawCount.
 * * 0: No. baseline stop follows when diffCount is greater than noise threshold.
 */
#define TSI_SENSOR_BSLN_ALWAYS_UPDATE           (0U)

/**
 *  Use LTA algorithm. Available when TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0.
 *
 * * 1: Yes, use LTA algorithm which improves robustness.
 * * 0: No, do not use LTA algorithm.
 */
#define TSI_SENSOR_BSLN_USE_LTA                 (0U)

/* Statistic configurations --------------------------------------------------*/
/* Calculate sensor Cs after library initialization */
#define TSI_STATISTIC_SENSOR_CS                 (0U)

/* LPM support configurations ------------------------------------------------*/
/* TSI used in LPM mode(0 - not used, 1 - used) */
#define TSI_USED_IN_LPM_MODE                    (0U)

#if (TSI_USED_IN_LPM_MODE == 1U)

/** Bypass filters in LPM mode to raise detection speed. */
#define TSI_LPM_BYPASS_FILTERS                  (0U)

/** Number of scan in LPM mode. Library will use the last scan result. */
#define TSI_LPM_SCAN_NUM                        (1U)

#endif  /* TSI_USED_IN_LPM_MODE == 1U */

/* Misc configurations ------------------------------------------------------*/
/* Slider position resolution */
#define TSI_SLIDER_RESOLUTION                   (255U)

/* Slider finger num */
#define TSI_SLIDER_FINGER_NUM                   (1U)

/* Touchpad position resolution */
#define TSI_TOUCHPAD_RESOLUTION                 (255U)

/* Calibration constants ----------------------------------------------------*/
#define TSI_SC_CALIB_INIT_RESOLUTION            (12U)
#define TSI_SC_CALIB_INIT_FREQ_HZ               (1500000U)
#define TSI_SC_CALIB_INIT_IDAC_STEP_IDX         (5U)
#define TSI_SC_CALIB_IDAC_TARGET                (25U)
#define TSI_SC_CALIB_IDAC_MIN                   (20U)

#define TSI_MC_CALIB_IDAC_TARGET                (50U)

#define TSI_SC_MAX_RESOLUTION                   (16U)
#define TSI_SC_MIN_RESOLUTION                   (8U)
#define TSI_SNS_INT_R_OHM                       (100U)
#define TSI_SC_SNS_R_OHM                        (2000U)
#define TSI_VREF_MV                             (1000U)
#define TSI_SERIES_R_OHM                        (2500U)

/* Driver constants ---------------------------------------------------------*/
#define TSI_TOTAL_SCAN_NUM                      (TSI_SCAN_FREQ_NUM + TSI_USER_SCAN_FREQ_NUM)

/* Utilities ----------------------------------------------------------------*/
/*-----------------------------------*/
/* Debug printing                    */
/*-----------------------------------*/
#if (TSI_DEBUG_LEVEL >= 1)
#include <stdio.h>
#endif

#if (TSI_DEBUG_LEVEL >= 1)
#define TSI_ERR(FMT, ...)               printf("[TSI] ERROR: " FMT "\r\n", ##__VA_ARGS__)
#else
#define TSI_ERR(FMT, ...)
#endif

#if (TSI_DEBUG_LEVEL >= 2)
#define TSI_DEBUG(FMT, ...)             printf("[TSI] DEBUG: " FMT "\r\n", ##__VA_ARGS__)
#else
#define TSI_DEBUG(FMT, ...)
#endif

#if (TSI_DEBUG_LEVEL >= 3)
#define TSI_INFO(FMT, ...)              printf("[TSI] INFO: " FMT "\r\n", ##__VA_ARGS__)
#else
#define TSI_INFO(FMT, ...)
#endif

#ifdef __cplusplus
}
#endif

#endif  /* TSI_CONF_H */

