#ifndef TSI_OBJECT_H
#define TSI_OBJECT_H

#include "tsi_driver.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations -----------------------------------------------------*/
/*-----------------------------------*/
/* Algorithm types                   */
/*-----------------------------------*/
typedef struct _TSI_DetectConf TSI_DetectConfTypeDef;
typedef struct _TSI_BaselineVar TSI_BaselineVarTypeDef;
#if (TSI_NORM_FILTER_EN == 1U)
typedef struct _TSI_NormSnsFilter TSI_NormSnsFilterTypeDef;
#endif  /* TSI_NORM_FILTER_EN == 1U */
#if (TSI_PROX_FILTER_EN == 1U)
typedef struct _TSI_ProxSnsFilter TSI_ProxSnsFilterTypeDef;
#endif  /* TSI_PROX_FILTER_EN == 1U */

#if (TSI_WIDGET_POS_FILTER_EN == 1U)
typedef struct _TSI_WidgetPosFilterConf TSI_WidgetPosFilterConfTypeDef;
typedef struct _TSI_WidgetPosFilter1D TSI_WidgetPosFilter1DTypeDef;
typedef struct _TSI_WidgetPosFilter2D TSI_WidgetPosFilter2DTypeDef;
#endif  /* TSI_WIDGET_FILTER_EN == 1U */

/*-----------------------------------*/
/* Software timer types              */
/*-----------------------------------*/
struct _TSI_Timer;
struct _TSI_TimerContext;

/*-----------------------------------*/
/* TSI library handle type           */
/*-----------------------------------*/
typedef struct _TSI_LibCallbacks TSI_LibCallbacksTypeDef;
typedef struct _TSI_LibHandle TSI_LibHandleTypeDef;

/*-----------------------------------*/
/* TSI library user object types     */
/*-----------------------------------*/
typedef struct _TSI_WidgetList TSI_WidgetListTypeDef;
typedef struct _TSI_SensorList TSI_SensorListTypeDef;

/*-----------------------------------*/
/* Widget types                      */
/*-----------------------------------*/
typedef struct _TSI_MetaWidget TSI_MetaWidgetTypeDef;
typedef struct _TSI_Meta2DWidget TSI_Meta2DWidgetTypeDef;
typedef struct _TSI_Widget TSI_WidgetTypeDef;
typedef struct _TSI_SelfCapWidget TSI_SelfCapWidgetTypeDef;
typedef struct _TSI_MutualCapWidget TSI_MutualCapWidgetTypeDef;

/*-----------------------------------*/
/* Self-cap widget types             */
/*-----------------------------------*/
typedef struct _TSI_SelfCapButton TSI_SelfCapButtonTypeDef;
typedef struct _TSI_SelfCapSlider TSI_SelfCapSliderTypeDef;
typedef struct _TSI_SelfCapRadialSlider TSI_SelfCapRadialSliderTypeDef;
typedef struct _TSI_SelfCapProximity TSI_SelfCapProximityTypeDef;
typedef struct _TSI_SelfCapTouchpad TSI_SelfCapTouchpadTypeDef;

/*-----------------------------------*/
/* Mutual-cap widget types           */
/*-----------------------------------*/
typedef struct _TSI_MutualCapButton TSI_MutualCapButtonTypeDef;
typedef struct _TSI_MutualCapSlider TSI_MutualCapSliderTypeDef;
typedef struct _TSI_MutualCapTouchpad TSI_MutualCapTouchpadTypeDef;

/*-----------------------------------*/
/* Widget-related types              */
/*-----------------------------------*/
typedef struct _TSI_MetaSensor TSI_MetaSensorTypeDef;
typedef struct _TSI_Sensor TSI_SensorTypeDef;

/*-----------------------------------*/
/* Touchpad tracking algorithm types */
/*-----------------------------------*/
typedef struct _TSI_TouchPadTrackParam TSI_TouchPadTrackParamTypeDef;
typedef struct _TSI_TouchPadTrackData TSI_TouchPadTrackDataTypeDef;

/* Defines ------------------------------------------------------------------*/
#define TSI_WIDGET_TYPE_SELF_CAP_BEGIN          (0U)
#define TSI_WIDGET_TYPE_MUTUAL_CAP_BEGIN        (16U)

#define TSI_WIDGET_IS_SELF_CAP(WIDGET)      \
    ((uint32_t)((WIDGET)->meta->type) < TSI_WIDGET_TYPE_MUTUAL_CAP_BEGIN)
#define TSI_WIDGET_IS_MUTUAL_CAP(WIDGET)    \
    ((uint32_t)((WIDGET)->meta->type) >= TSI_WIDGET_TYPE_MUTUAL_CAP_BEGIN)

typedef enum {
    TSI_WIDGET_SELF_CAP_BUTTON = TSI_WIDGET_TYPE_SELF_CAP_BEGIN,
    TSI_WIDGET_SELF_CAP_PROXIMITY,
    TSI_WIDGET_SELF_CAP_SLIDER,
    TSI_WIDGET_SELF_CAP_RADIAL_SLIDER,
    TSI_WIDGET_SELF_CAP_TOUCHPAD,

    TSI_WIDGET_MUTUAL_CAP_BUTTON = TSI_WIDGET_TYPE_MUTUAL_CAP_BEGIN,
    TSI_WIDGET_MUTUAL_CAP_SLIDER,
    TSI_WIDGET_MUTUAL_CAP_TOUCHPAD,
} TSI_WidgetType;

typedef enum {
    TSI_SENSOR_SELF_CAP = 0U,
    TSI_SENSOR_SELF_CAP_ROW = 1U,
    TSI_SENSOR_MUTUAL_CAP = 16U,
} TSI_SensorType;

typedef enum {
    TSI_FILTER_NORMAL = 0U,
    TSI_FILTER_PROXMITY = 1U,
} TSI_FilterType;

/* Widget position filter configuration bit-masks. */
/* Bit 0: Use median filter. */
#define TSI_WIDGET_POS_FILTER_USE_MEDIAN_MASK       (0x1UL << 0U)
/* Bit 1: Use average filter. */
#define TSI_WIDGET_POS_FILTER_USE_AVERAGE_MASK      (0x1UL << 1U)
/* Bit 2: Use IIR filter. */
#define TSI_WIDGET_POS_FILTER_USE_IIR_MASK          (0x1UL << 2U)

/* Structs ------------------------------------------------------------------*/
/*-----------------------------------*/
/* Algorithm structs                 */
/*-----------------------------------*/
/** Sensor detection and baseline configurations. */
struct _TSI_DetectConf {
    /* Baseline params --------------*/
    /** Sensor active threshold. */
    uint16_t activeTh;

    /** Sensor active hysteresis. */
    uint16_t activeHys;

    /** Baseline noise threshold. */
    uint16_t noiseTh;

    /** Baseline negative noise threshold. */
    uint16_t negNoiseTh;

    /** Baseline IIR coefficient. */
    uint8_t bslnIIRCoeff;

    /** Sensor on debounce. */
    uint8_t onDebounce;

    /** Sensor off debounce. */
    uint8_t offDebounce;

    /** Baseline negative stop timeout. */
    uint16_t bslnNegStopTimeout;

#if((TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U))
    /* LTA params -------------------*/
    /** LTA negative error threshold. */
    uint16_t ltaNegErrTh;

    /** Sensor on debounce in LTA mode. */
    uint8_t ltaOnDebounce;

    /** Sensor negative error debounce in LTA mode. */
    uint8_t ltaNegErrorDebounce;

    /** LTA mode switch: Sensor active timeout. */
    uint16_t ltaActiveTimeout;

    /** LTA mode switch: Normal baseline stop timeout. */
    uint16_t ltaNormBslnStopTimeout;

#endif  /* if (TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U) */
};

/** Sensor baseline variables and states. */
struct _TSI_BaselineVar {
#if (TSI_NORM_FILTER_EN || TSI_PROX_FILTER_EN)
    /** Sensor processing buffer. */
    uint16_t sensorBuffer[TSI_SCAN_FREQ_NUM];
#endif  /* TSI_NORM_FILTER_EN || TSI_PROX_FILTER_EN */

#if (TSI_USER_SCAN_FREQ_NUM > 0U)
    /** User-defined scan processing buffer. */
    uint16_t sensorUserBuffer[TSI_USER_SCAN_FREQ_NUM];
#endif /* (TSI_USER_SCAN_FREQ_NUM > 0U) */

    /** Baseline IIR buffer. */
    uint32_t bslnIIRBuff[TSI_TOTAL_SCAN_NUM];

    /** Sensor baseline reset counter. */
    uint16_t bslnNegStopCount[TSI_TOTAL_SCAN_NUM];

#if((TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U))
    /**
     * Baseline mode.
     *
     * * 0(TSI_BASELINE_MODE_NORMAL): Normal baseline.
     * * 1(TSI_BASELINE_MODE_LTA): LTA baseline.
     */
    uint8_t bslnMode;

    /** LTA negative error debounce counter. */
    uint8_t ltaNegErrDebCnt;

    /** LTA baseline. */
    uint16_t lta[TSI_TOTAL_SCAN_NUM];

    /** Baseline IIR buffer. */
    uint32_t ltaIIRBuff[TSI_TOTAL_SCAN_NUM];

    /** LTA active counter. */
    uint16_t ltaActiveCnt;

    /** LTA normal baseline stop counter. */
    uint16_t ltaBslnStopCnt;

#endif  /* if (TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U) */
};

#if (TSI_NORM_FILTER_EN == 1U)
/** Normal sensor filter states and buffers. */
struct _TSI_NormSnsFilter {
#if (TSI_NORM_FILTER_AVERAGE_EN == 1U)
    /** Normal sensor average filter buffer. */
    uint16_t avgBuff[3U];
#endif  /* TSI_NORM_FILTER_AVERAGE_EN == 1U */
#if (TSI_NORM_FILTER_MEDIAN_EN == 1U)
    /** Normal sensor median filter buffer. */
    uint16_t medBuff[2U];
#endif  /* TSI_NORM_FILTER_MEDIAN_EN == 1U */
#if (TSI_NORM_FILTER_IIR_EN == 1U)
    /** Normal sensor IIR filter buffer. */
    uint32_t normIIRBuff;
#endif  /* TSI_NORM_FILTER_IIR_EN == 1U */
#if (TSI_NORM_FILTER_FSIIR_EN == 1U)
    /** Normal sensor fast-slow IIR filter buffer. */
    uint32_t fsIIRBuff[2U];

    /** Normal sensor fast-slow IIR switch debounce counter. */
    uint16_t fsIIRDebCnt;
#endif  /* TSI_NORM_FILTER_FSIIR_EN == 1U */

#if ((TSI_NORM_FILTER_AVERAGE_EN == 0U) &&  \
     (TSI_NORM_FILTER_MEDIAN_EN == 0U) &&   \
     (TSI_NORM_FILTER_IIR_EN == 0U) &&      \
     (TSI_NORM_FILTER_FSIIR_EN == 0U) &&    \
     (TSI_NORM_FILTER_FSIIR_EN == 0U))
    /* Dummy member for eliminating compiler errors. */
    uint32_t dummy;
#endif
};
#endif  /* TSI_NORM_FILTER_EN == 1U */

#if (TSI_PROX_FILTER_EN == 1U)
/** Proximity sensor filter states and buffers. */
struct _TSI_ProxSnsFilter {
#if (TSI_PROX_FILTER_AVERAGE_EN == 1U)
    /** Proximity sensor average filter buffer. */
    uint16_t avgBuff[3U];
#endif  /* TSI_PROX_FILTER_AVERAGE_EN == 1U */
#if (TSI_PROX_FILTER_MEDIAN_EN == 1U)
    /** Proximity sensor median filter buffer. */
    uint16_t medBuff[2U];
#endif  /* TSI_PROX_FILTER_MEDIAN_EN == 1U */
#if (TSI_PROX_FILTER_ADVIIR_EN == 1U)
    /** Proximity sensor advanced IIR filter mode. */
    uint8_t advIIRMode;

    /** Proximity sensor advanced IIR filter buffer. */
    uint32_t advIIRBuff[6U];
#endif  /* TSI_PROX_FILTER_IIR_EN == 1U */
#if (TSI_PROX_FILTER_FSIIR_EN == 1U)
    /** Proximity sensor fast-slow IIR filter buffer. */
    uint32_t fsIIRBuff[2U];

    /** Proximity sensor fast-slow IIR switch debounce counter. */
    uint16_t fsIIRDebCnt;
#endif  /* TSI_PROX_FILTER_FSIIR_EN == 1U */

#if ((TSI_PROX_FILTER_AVERAGE_EN == 0U) &&  \
     (TSI_PROX_FILTER_MEDIAN_EN == 0U) &&   \
     (TSI_PROX_FILTER_IIR_EN == 0U) &&      \
     (TSI_PROX_FILTER_FSIIR_EN == 0U) &&    \
     (TSI_PROX_FILTER_FSIIR_EN == 0U))
    /* Dummy member for eliminating compiler errors. */
    uint32_t dummy;
#endif
};
#endif  /* TSI_PROX_FILTER_EN == 1U */

#if (TSI_WIDGET_POS_FILTER_EN == 1U)
/** 1D widget position filter states and buffers. */
struct _TSI_WidgetPosFilter1D {
    /* Initialized flag. */
    uint8_t isInited;

#if (TSI_WIDGET_POS_FILTER_AVERAGE_EN == 1U)
    /** Slider position average filter buffer. */
    uint16_t avgBuff;
#endif  /* TSI_WIDGET_POS_FILTER_AVERAGE_EN == 1U */
#if (TSI_WIDGET_POS_FILTER_MEDIAN_EN == 1U)
    /** Slider position median filter buffer. */
    uint16_t medBuff[2U];
#endif  /* TSI_WIDGET_POS_FILTER_AVERAGE_EN == 1U */
#if (TSI_WIDGET_POS_FILTER_IIR_EN == 1U)
    /** Slider position IIR filter buffer. */
    uint32_t normIIRBuff;
#endif  /* TSI_WIDGET_POS_FILTER_AVERAGE_EN == 1U */
};

/** 2D widget position filter states and buffers. */
struct _TSI_WidgetPosFilter2D {
    /** X-axis filter. */
    TSI_WidgetPosFilter1DTypeDef xFilter;

    /** Y-axis filter. */
    TSI_WidgetPosFilter1DTypeDef yFilter;
};

/* Position filter configuraions. */
struct _TSI_WidgetPosFilterConf {
    /** Bit-wise configurations. */
    uint32_t confBits;

#if (TSI_WIDGET_POS_FILTER_IIR_EN == 1U)
    /** IIR filter coefficient. */
    uint8_t iirCoef;
#endif  /* TSI_WIDGET_POS_FILTER_IIR_EN == 1U */
};

#endif  /* TSI_WIDGET_FILTER_EN == 1U */

/*-----------------------------------*/
/* TSI library handle struct         */
/*-----------------------------------*/
/** Library callbacks struct. */
struct _TSI_LibCallbacks {
    /** Library Init completed callback. */
    void (*initCompleted)(TSI_LibHandleTypeDef *handle);

    /** Library DeInit completed callback. */
    void (*deInitCompleted)(TSI_LibHandleTypeDef *handle);

    /** Library started callback. */
    void (*started)(TSI_LibHandleTypeDef *handle);

    /** Library stopped callback. */
    void (*stopped)(TSI_LibHandleTypeDef *handle);

    /**
     *  Widget initialized callback. User can use this callback to apply
     *  customized algorithms.
     */
    void (*widgetInitCompleted)(TSI_LibHandleTypeDef *handle, struct _TSI_Widget *widget);

    /**
     *  Widget scan completed callback. User can use this callback to apply
     *  customized algorithms.
     */
    void (*widgetScanCompleted)(TSI_LibHandleTypeDef *handle);

    /**
     *  Widget data updated callback. User can use this callback to apply
     *  customized algorithms.
     */
    void (*widgetValueUpdated)(TSI_LibHandleTypeDef *handle);

    /**
     *  Widget status updated callback. User can use this callback to apply
     *  customized algorithms.
     */
    void (*widgetStatusUpdated)(TSI_LibHandleTypeDef *handle);

    /**
     * Used during library sensor initialization. Library use this callback to
     * get sensor init buffer pointer and init scan count. User should keep the
     * ref to the buffer.
     *
     * Note: sensor is NULL when passing a mutual-cap context.
     */
    uint32_t (*getInitScanBufferAndCount)(TSI_LibHandleTypeDef *handle,
                                          struct _TSI_Widget *widget, struct _TSI_Sensor *sensor,
                                          uint16_t **ppBuffer);

    /**
     * Used during library sensor initialization. After filling the buffer get from
     * getInitScanBufferAndCount(), library will pass it to user using this callback.
     * User should set processed value in pValueBuffer.
     */
    void (*processInitScanValue)(TSI_LibHandleTypeDef *handle,
                                 struct _TSI_Widget *widget, struct _TSI_Sensor *sensor,
                                 uint16_t *pValueBuffer);
};

/** TSI Library handle struct. */
struct _TSI_LibHandle {
    /**
     * Command to interact with library. Can start/stop sampling, do calibration and more.
     * It can help users who are using IDE simulation by offering basic debugging method.
     * Available after entering main loop(which calls TSI_Handler() periodically).
     *
     * Note: Bitfield order assumes little-endian machine.
     *
     * Byte0-Bit[5:0]: Command code.
     * Byte0-Bit[7:6]: Command execution status.
     * * 0 - No command or execution has completed.
     * * 1 - Request command execution.
     * * 2 - Command is under execution.
     * * 3 - There is error in command execution.
     * Byte[1:2]: Command param 0.
     * Byte3: Command param 1.
     * Byte4: Command result.
     * Byte[5:8]: Extra data (MSB First).
     */
    union {
        uint8_t buffer[9U];
        struct {
            uint32_t cmdCode : 6U;
            uint32_t execStat : 2U;
            uint32_t param0Hi : 8U;
            uint32_t param0Lo : 8U;
            uint8_t param1;
            uint8_t result;
            uint8_t exData[4U];
        } map;
    } command;

    /** Library callbacks. */
    TSI_LibCallbacksTypeDef cb;

    /** Driver instance. */
    TSI_DriverTypeDef *driver;

    /** Widget list. */
    TSI_WidgetTypeDef **widgets;

    /** Widget list size. */
    uint8_t widgetNum;

    /** Library status. */
    volatile TSI_LibStat status;

#if (TSI_USE_TIMEBASE == 1U)
    /** Library timer context. */
    struct _TSI_TimerContext *timerContext;

#if (TSI_SCAN_USE_TIMEBASE == 1U)
    /** Scan interval timer. */
    struct _TSI_Timer *scanIntvTimer;

    /** Scan interval flag. */
    uint8_t scanIntvFlag;

#endif  /* TSI_SCAN_USE_TIMEBASE == 1U */
#endif  /* TSI_USE_TIMEBASE == 1U */

#if (TSI_USED_IN_LPM_MODE == 1U)
    /** Set this flag if library is in LPM mode. */
    uint8_t isLPM;

#endif  /* TSI_USE_LPM_MODE == 1U */
};

/*-----------------------------------*/
/* Widget-related structs            */
/*-----------------------------------*/
/** Widget meta information struct. */
struct _TSI_MetaWidget {
    /** Widget type. */
    TSI_WidgetType type;

    /** Sensor list. */
    TSI_SensorTypeDef *sensors;

    /** Sensor list size. */
    uint8_t sensorNum;

    /**
     * Widget's self-parrarel/mutual scan group. Set to NULL
     * if widget is a non-parallel self-cap widget, which shares
     * one scan group with other widgets. This value is often used by
     * mutual-cap / self-cap parallel widget calibration.
     */
    TSI_ScanGroupTypeDef *dedicatedScanGroup;

    /** Widget debounce counter size. */
    uint8_t debArrayWidgetSize;

    /** Pointer to widget debounce counter. */
    uint8_t *debArrayWidget;

#if (TSI_WIDGET_POS_FILTER_EN == 1U)
    /** Widget position filter. */
    void *posFilter;

    /** Widget position filter configurations. */
    TSI_WidgetPosFilterConfTypeDef posFilterConf;
#endif  /* TSI_WIDGET_POS_FILTER_EN == 1U */
};

/** 2D widget meta information struct. */
struct _TSI_Meta2DWidget {
    /** Widget meta informations. */
    TSI_MetaWidgetTypeDef base;

    /** Widget row sensor list size. */
    uint8_t sensorRowNum;
};

/** Widget struct. */
struct _TSI_Widget {
    /** Widget meta informations. */
    TSI_MetaWidgetTypeDef *meta;

    /** Widget enable status. */
    uint8_t enable;

    /* Software parameters ----------*/
    TSI_DetectConfTypeDef detConf;

    /* Values -----------------------*/
    /** Widget active status. */
    uint8_t status;
};

/** Self-cap widget struct. */
struct _TSI_SelfCapWidget {
    /** Widget base. */
    TSI_WidgetTypeDef base;

    /* Software parameters ----------*/
    /** Sensitivity, used by hardware params auto-calibration.
        Unit: count/0.1pF */
    uint16_t sensitivity;

    /* Hardware parameters ----------*/
    /**
     * Store both IDAC step if TSI_SC_USE_UNIFIED_IDAC_STEP == 1.
     * Store modulation IDAC step if TSI_SC_USE_UNIFIED_IDAC_STEP == 0.
     */
    uint8_t idacStep;

#if (TSI_SC_USE_UNIFIED_IDAC_STEP == 0U)
    /** Store compensation IDAC step if TSI_SC_USE_UNIFIED_IDAC_STEP == 0. */
    uint8_t idacCompStep;
#endif

    /** Widget scan resolution. */
    uint8_t resolution;

    /** Widget Fsw clock division. */
    uint16_t swClkDiv;

    /** Widget modulation IDAC code. */
    uint8_t idacMod[TSI_TOTAL_SCAN_NUM];
};

/** Mutual-cap widget struct. */
struct _TSI_MutualCapWidget {
    /** Widget base. */
    TSI_WidgetTypeDef base;

    /**
     * IDAC step.
     *
     * * 0 for 37.5nA,
     * * 1 for 75nA,
     * * 2 for 300nA,
     * * 3 for 600nA,
     * * 4 for 1.2uA,
     * * 5 for 2.4uA,
     * * 7 for 4.8uA.
     */
    uint8_t idacStep;

    /** Widget scan resolution. */
    uint16_t resolution;

    /** Widget TX clock division. */
    uint16_t txClkDiv;
};

/** Self-cap button widget struct. */
struct _TSI_SelfCapButton {
    /** Self-cap widget base. */
    TSI_SelfCapWidgetTypeDef base;

    /**
     * Button active status.
     *
     * * 0: inactive.
     * * 2: active.
     */
    uint8_t buttonStat;
};

/** Self-cap slider widget struct. */
struct _TSI_SelfCapSlider {
    /** Self-cap widget base. */
    TSI_SelfCapWidgetTypeDef base;

    /** Widget on debounce. */
    uint8_t onDebounceWidget;

    /* Values -----------------------*/
    /** Slider active status. */
    uint8_t sliderStat;

    /** Slider touch center position (0 - 255). */
    uint8_t pos[TSI_SLIDER_FINGER_NUM];

    /* Internals --------------------*/
    /** Multipier for centroid calculation. */
    int32_t centroidMul;
};

/** Self-cap radial slider widget struct. */
struct _TSI_SelfCapRadialSlider {
    /** Self-cap widget base. */
    TSI_SelfCapWidgetTypeDef base;

    /** Widget on debounce. */
    uint8_t onDebounceWidget;

    /* Values -----------------------*/
    /** Slider active status. */
    uint8_t sliderStat;

    /** Slider touch center position (0 - 255). */
    uint8_t pos[TSI_SLIDER_FINGER_NUM];

    /* Internals --------------------*/
    /** Multipier for centroid calculation. */
    int32_t centroidMul;
};

/** Self-cap proximity widget struct. */
struct _TSI_SelfCapProximity {
    /** Self-cap widget base. */
    TSI_SelfCapWidgetTypeDef base;

    /** Proximity threshold. */
    uint16_t proxTh;

    /** Proximity hysteresis. */
    uint16_t proxHys;

#if (TSI_PROX_FILTER_ADVIIR_EN == 1U)
    /** Threshold when proximity filter enter active mode. */
    uint16_t filterActiveTh;

    /** Threshold when proximity filter enter detect mode (can be negative). */
    int16_t filterDetectTh;
#endif  /* TSI_PROX_FILTER_ADVIIR_EN == 1U */

    /* Values -----------------------*/
    /**
     * Proximity active status.
     *
     * * 0: inactive.
     * * 1: proximity.
     * * 2: active.
     */
    uint8_t proximityStat;

#if (TSI_PROX_FILTER_ADVIIR_EN == 1U)
    /** Proximity ADVIIR filter mode. */
    uint8_t filterMode;
#endif  /* TSI_PROX_FILTER_ADVIIR_EN == 1U */
};

/** Self-cap touchpad widget struct. */
struct _TSI_SelfCapTouchpad {
    /** Self-cap widget base. */
    TSI_SelfCapWidgetTypeDef base;

    /** Widget on debounce. */
    uint8_t onDebounceWidget;

    /** Widget column modulation IDAC code. */
    uint8_t idacModRow[TSI_TOTAL_SCAN_NUM];

    /* Values -----------------------*/
    /** Touchpad touch axis X position (0 - 255). */
    uint8_t xPos;

    /** Touchpad touch axis Y position (0 - 255). */
    uint8_t yPos;

    /**
     * Touchpad active status.
     *
     * * 0: inactive.
     * * 1: active.
     */
    uint8_t padStat;

    /* Internals --------------------*/
    /** Multipier for X-axis centroid calculation. */
    int32_t centroidMulX;

    /** Multipier for Y-axis centroid calculation. */
    int32_t centroidMulY;
};

/** Mutual-cap button widget struct. */
struct _TSI_MutualCapButton {
    /** Mutual-cap widget base. */
    TSI_MutualCapWidgetTypeDef base;

    /**
     * Button active status.
     *
     * * 0: inactive.
     * * 1: active.
     */
    uint8_t buttonStat;
};

struct _TSI_MutualCapSlider {
    /** Mutual-cap widget base. */
    TSI_MutualCapWidgetTypeDef base;

    /** Widget on debounce. */
    uint8_t onDebounceWidget;

    /* Values -----------------------*/
    /** Slider active status. */
    uint8_t sliderStat;

    /** Slider touch center position (0 - 255). */
    uint8_t pos[TSI_SLIDER_FINGER_NUM];

    /* Internals --------------------*/
    /** Multipier for centroid calculation. */
    int32_t centroidMul;
};

/** Mutual-cap touchpad widget struct. */
struct _TSI_MutualCapTouchpad {
    /** Mutual-cap widget base. */
    TSI_MutualCapWidgetTypeDef base;

    /** Widget on debounce. */
    uint8_t onDebounceWidget;

    /** 
     * Touchpad move speed threshold distinguishing seperate finger touches
     * from a fast movement. 
     */
    uint32_t maxSpeed;

    /* Values -----------------------*/


    /**
     * Touchpad active status.
     *
     * * 0: inactive.
     * * 1: active.
     */
    uint8_t padStat;

    /* Internals --------------------*/
    /** Multipier for X-axis centroid calculation. */
    int32_t centroidMulX;

    /** Multipier for Y-axis centroid calculation. */
    int32_t centroidMulY;
};

/*-----------------------------------*/
/* Sensor-related structs            */
/*-----------------------------------*/
/** Sensor meta information struct. */
struct _TSI_MetaSensor {
    /** Pointer to sensor parent widget. */
    TSI_WidgetTypeDef *parent;

    /** Sensor id. */
    uint16_t id;

    /** Sensor type. */
    TSI_SensorType type;

    /** Mutual-cap TX channel. */
    uint8_t txChannel;

    /** Mutual-cap RX channel, or self-cap channel. */
    uint8_t rxChannel;

    /** Pointer to detect configurations. */
    TSI_DetectConfTypeDef *detConf;

    /** Sensor filter type. */
    TSI_FilterType filterType;

    /** Pointer to sensor filter object. */
    void *filter;

    /** Debounce counter array size. */
    uint8_t debArraySize;

    /** Pointer to debounce counter array. */
    uint8_t *debArray;

#if (TSI_STATISTIC_SENSOR_CS == 1U)
    /** Pointer to sensor cap value storage. */
    uint32_t *capVal;
#endif  /* TSI_STATISTIC_SENSOR_CS == 1U */

    /**
     * Sensor's scan group. Must set to corresponding scan group
     * if:
     * * sensor's widget is a non-parallel self-cap widget, and the
     *   scan group has :c:member:`TSI_ScanGroupTypeDef.opt` set to
     *   non-zero value.
     *
     * Otherwise may set to NULL.
     */
    TSI_ScanGroupTypeDef *dedicatedScanGroup;
};

/** Sensor struct. */
struct _TSI_Sensor {
    /** Sensor meta informations. */
    TSI_MetaSensorTypeDef *meta;

    /* Config -----------------------*/
    /** IDAC code. */
    uint8_t idac[TSI_TOTAL_SCAN_NUM];

    /* Value ------------------------*/
    /** Sensor raw reading value. */
    uint16_t rawCount[TSI_TOTAL_SCAN_NUM];

    /** Sensor baseline. */
    uint16_t baseline[TSI_TOTAL_SCAN_NUM];

    /** Sensor actual signal value. */
    int32_t diffCount;

#if((TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U))
    /** Sensor signal value in LTA mode. */
    int32_t ltaDiffCount;
#endif  /* if (TSI_SENSOR_BSLN_ALWAYS_UPDATE == 0U) && (TSI_SENSOR_BSLN_USE_LTA == 1U) */

    /**
     * Sensor active status.
     *
     * * bit[0]: Active flag.
     * * bit[1]: Proximity flag (Proximity widget sensor(s) only).
     */
    uint8_t status;

    /* Internals --------------------*/
    /** Sensor baseline vairables and states. */
    TSI_BaselineVarTypeDef bslnVar;
};

#ifdef __cplusplus
}
#endif

/* User objects definitions */
#include "tsi_user_def.h"

#endif  /* TSI_OBJECT_H */
