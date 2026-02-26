/* Includes -----------------------------------------------------------------*/
#include "tsi_object.h"
#include "tsi_utils.h"
#include <string.h>

/* Helper macros ------------------------------------------------------------*/
/* Scan group define helper. */
#define TSI_SCAN_GROUP(ID, TYPE, SIZE, OPT)                         \
    static const uint16_t TSI_ScanGrpSnsList ## ID[SIZE];           \
    TSI_USED static const TSI_ScanGroupTypeDef TSI_ScanGrp ## ID    \
    TSI_SECTION(TSI_GROUP_SECTION) = {                              \
        SIZE, TYPE, OPT,                                            \
        (uint16_t*) TSI_ScanGrpSnsList ## ID,                       \
    };                                                              \
    static const uint16_t TSI_ScanGrpSnsList ## ID[] =

/* Scan group list head element (NULL). */
TSI_USED static const TSI_ScanGroupTypeDef TSI_ScanGrpHead
TSI_SECTION(TSI_GROUP_BEGIN_SECTION) = {0U, 0U, 0U, NULL};

/* Scan group ref helper. */
#define TSI_SCAN_GROUP_REF(ID)                                      \
    ((TSI_ScanGroupTypeDef*)&TSI_ScanGrp ## ID)

/* Pointer to first element in scan group list. */
#define TSI_SCAN_GROUP_BEGIN    (((TSI_ScanGroupTypeDef *)&TSI_ScanGrpHead) + 1U)

/* Exported object definitions ----------------------------------------------*/
#ifdef TSI_NO_RAM_INIT
    TSI_USED TSI_LibHandleTypeDef TSI_LibHandle TSI_SECTION(TSI_LIB_SECTION);
#endif
TSI_USED TSI_DriverTypeDef TSI_Drv TSI_SECTION(TSI_DRIVER_SECTION);
TSI_ALIGN4 TSI_USED TSI_WidgetListTypeDef TSI_WidgetList TSI_SECTION(TSI_WIDGETS_SECTION);
TSI_ALIGN4 TSI_USED TSI_SensorListTypeDef TSI_SensorList TSI_SECTION(TSI_SENSORS_SECTION);

/* Private object definitions -----------------------------------------------*/
/* Debounce buffers */
TSI_USED static uint8_t TSI_Debounce_Button0[TSI_BUTTON0_SENSOR_NUM] TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED static uint8_t TSI_Debounce_Button1[TSI_BUTTON1_SENSOR_NUM] TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED static uint8_t TSI_Debounce_Button2[TSI_BUTTON2_SENSOR_NUM] TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED static uint8_t TSI_Debounce_Button3[TSI_BUTTON3_SENSOR_NUM] TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED static uint8_t TSI_Debounce_Button4[TSI_BUTTON4_SENSOR_NUM] TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED static uint8_t TSI_Debounce_Button5[TSI_BUTTON5_SENSOR_NUM] TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED static uint8_t TSI_Debounce_Button6[TSI_BUTTON6_SENSOR_NUM] TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED static uint8_t TSI_Debounce_Button7[TSI_BUTTON7_SENSOR_NUM] TSI_SECTION(TSI_MISCS_SECTION);

/* Filter buffers */
TSI_USED static TSI_NormSnsFilterTypeDef TSI_Filter_Button0[TSI_BUTTON0_SENSOR_NUM][TSI_SCAN_FREQ_NUM] TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED static TSI_NormSnsFilterTypeDef TSI_Filter_Button1[TSI_BUTTON1_SENSOR_NUM][TSI_SCAN_FREQ_NUM] TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED static TSI_NormSnsFilterTypeDef TSI_Filter_Button2[TSI_BUTTON2_SENSOR_NUM][TSI_SCAN_FREQ_NUM] TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED static TSI_NormSnsFilterTypeDef TSI_Filter_Button3[TSI_BUTTON3_SENSOR_NUM][TSI_SCAN_FREQ_NUM] TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED static TSI_NormSnsFilterTypeDef TSI_Filter_Button4[TSI_BUTTON4_SENSOR_NUM][TSI_SCAN_FREQ_NUM] TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED static TSI_NormSnsFilterTypeDef TSI_Filter_Button5[TSI_BUTTON5_SENSOR_NUM][TSI_SCAN_FREQ_NUM] TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED static TSI_NormSnsFilterTypeDef TSI_Filter_Button6[TSI_BUTTON6_SENSOR_NUM][TSI_SCAN_FREQ_NUM] TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED static TSI_NormSnsFilterTypeDef TSI_Filter_Button7[TSI_BUTTON7_SENSOR_NUM][TSI_SCAN_FREQ_NUM] TSI_SECTION(TSI_MISCS_SECTION);

#if (TSI_USE_TIMEBASE == 1U)
    /** Library timer handle object. */
    TSI_USED static TSI_TimerContextTypeDef TSI_TimerContext
    TSI_SECTION(TSI_MISCS_SECTION);
    #if (TSI_SCAN_USE_TIMEBASE == 1U)
        /** Library scan interval timer object. */
        TSI_USED static TSI_TimerTypeDef TSI_ScanInvTimer
        TSI_SECTION(TSI_MISCS_SECTION);
    #endif  /* TSI_SCAN_USE_TIMEBASE == 1U */
#endif  /* TSI_USE_TIMEBASE == 1U */

/* Configurations -----------------------------------------------------------*/
/*-----------------------------------*/
/* Clocks                            */
/*-----------------------------------*/
TSI_USED TSI_ClockConfTypeDef TSI_ClockConf[TSI_CLOCK_NUM]
TSI_SECTION(TSI_MISCS_SECTION);
TSI_USED const TSI_ClockConfTypeDef TSI_ClockConfConstInit[TSI_CLOCK_NUM]
TSI_SECTION(TSI_CONST_MISCS_SECTION) = {
    /* Self-cap clocks */
    {
        0U,                 /* opClockSel */
        1U,                 /* snsClockSrc */
        0U,                 /* snsClockSel */
        8U,                 /* prsWidth */
        6U,                 /* sscWidth */
        0U,                 /* sscPoint */
        0U,                 /* reserved */
        1U,                 /* modClockPsc */
        0x8EU,              /* prsCoeff */
        0x21U,              /* sscCoeff */
        0U,                 /* reserved2 */
        16U,                /* pllRefPsc */
        60U,                /* pllMul */
    },
    {
        0U,                 /* opClockSel */
        1U,                 /* snsClockSrc */
        0U,                 /* snsClockSel */
        8U,                 /* prsWidth */
        6U,                 /* sscWidth */
        0U,                 /* sscPoint */
        0U,                 /* reserved */
        1U,                 /* modClockPsc */
        0x8EU,              /* prsCoeff */
        0x21U,              /* sscCoeff */
        0U,                 /* reserved2 */
        16U,                /* pllRefPsc */
        54U,                /* pllMul */
    },
    {
        0U,                 /* opClockSel */
        1U,                 /* snsClockSrc */
        0U,                 /* snsClockSel */
        8U,                 /* prsWidth */
        6U,                 /* sscWidth */
        0U,                 /* sscPoint */
        0U,                 /* reserved */
        1U,                 /* modClockPsc */
        0x8EU,              /* prsCoeff */
        0x21U,              /* sscCoeff */
        0U,                 /* reserved2 */
        16U,                /* pllRefPsc */
        66U,                /* pllMul */
    },
    /* Mutual-cap clocks */
    {
        0U,                 /* opClockSel */
        0U,                 /* snsClockSrc */
        0U,                 /* snsClockSel */
        8U,                 /* prsWidth */
        6U,                 /* sscWidth */
        0U,                 /* sscPoint */
        0U,                 /* reserved */
        1U,                 /* modClockPsc */
        0x8EU,              /* prsCoeff */
        0x21U,              /* sscCoeff */
        0U,                 /* reserved2 */
        16U,                /* pllRefPsc */
        60U,                /* pllMul */
    },
    {
        0U,                 /* opClockSel */
        0U,                 /* snsClockSrc */
        0U,                 /* snsClockSel */
        8U,                 /* prsWidth */
        6U,                 /* sscWidth */
        0U,                 /* sscPoint */
        0U,                 /* reserved */
        1U,                 /* modClockPsc */
        0x8EU,              /* prsCoeff */
        0x21U,              /* sscCoeff */
        0U,                 /* reserved2 */
        16U,                /* pllRefPsc */
        54U,                /* pllMul */
    },
    {
        0U,                 /* opClockSel */
        0U,                 /* snsClockSrc */
        0U,                 /* snsClockSel */
        8U,                 /* prsWidth */
        6U,                 /* sscWidth */
        0U,                 /* sscPoint */
        0U,                 /* reserved */
        1U,                 /* modClockPsc */
        0x8EU,              /* prsCoeff */
        0x21U,              /* sscCoeff */
        0U,                 /* reserved2 */
        16U,                /* pllRefPsc */
        66U,                /* pllMul */
    },
};

/*-----------------------------------*/
/* Ports                             */
/*-----------------------------------*/
TSI_USED static const TSI_IOConfTypeDef TSI_IOConf[TSI_PIN_NUM]
TSI_SECTION(TSI_CONST_MISCS_SECTION) = {
    { 0U, 4U, 1U },         /* PA4 */
    { 0U, 6U, 3U },         /* PA6 */
    { 1U, 6U, 9U },         /* PB6 */
    { 1U, 1U, 6U },         /* PB1 */
    { 1U, 8U, 11U },        /* PB8 */
    { 1U, 5U, 8U },         /* PB5 */
    { 1U, 7U, 10U },        /* PB7 */
    { 1U, 14U, 13U },       /* PB14 */
};
/*-----------------------------------*/
/* Shields                           */
/*-----------------------------------*/
#if (TSI_SHIELD_NUM > 0U)
TSI_USED static const TSI_ShieldConfTypeDef TSI_ShieldConf[TSI_SHIELD_NUM]
TSI_SECTION(TSI_CONST_MISCS_SECTION) = {
    {
        1U,                 /* Channel */
    },
    {
        3U,                 /* Channel */
    },
    {
        9U,                 /* Channel */
    },
    {
        6U,                 /* Channel */
    },
    {
        11U,                /* Channel */
    },
    {
        8U,                 /* Channel */
    },
    {
        10U,                /* Channel */
    },
    {
        13U,                /* Channel */
    },
};
#endif

/*-----------------------------------*/
/* Scan groups                       */
/*-----------------------------------*/
TSI_SCAN_GROUP(0, TSI_SCAN_GROUP_SELF_CAP, 8, TSI_DEV_OPT_IDLE_FLOATING)
{
    0, 1, 3, 5, 2, 6, 4, 7
};

/*-----------------------------------*/
/* Library and driver init data      */
/*-----------------------------------*/
#ifdef TSI_NO_RAM_INIT
TSI_USED TSI_LibHandleTypeDef TSI_LibHandleConstInit
TSI_SECTION(TSI_CONST_LIB_SECTION) = {
#else
TSI_USED TSI_LibHandleTypeDef TSI_LibHandle
TSI_SECTION(TSI_LIB_SECTION) = {
#endif
    { { 0U } },
    { NULL },
    &TSI_Drv,
    (TSI_WidgetTypeDef **) &TSI_WidgetPointers[0],
    TSI_WIDGET_NUM,
    TSI_LIB_RESET,
#if (TSI_USE_TIMEBASE == 1U)
    &TSI_TimerContext,
#if (TSI_SCAN_USE_TIMEBASE == 1U)
    &TSI_ScanInvTimer,
    0U,
#endif
#endif
#if (TSI_USED_IN_LPM_MODE == 1U)
    0U,
#endif
};

TSI_USED const TSI_DriverTypeDef TSI_DrvConstInit
TSI_SECTION(TSI_CONST_DRVIER_SECTION) = {
    0U,
    NULL,
    (TSI_ClockConfTypeDef *) &TSI_ClockConf[0],
    (TSI_IOConfTypeDef *) &TSI_IOConf[0],
    TSI_PIN_NUM,
#if (TSI_SHIELD_NUM > 0U)
    (TSI_ShieldConfTypeDef *) &TSI_ShieldConf[0],
#else
    NULL,
#endif  /* TSI_SHIELD_NUM > 0U */
    TSI_SHIELD_NUM,
    (TSI_ScanGroupTypeDef *) &TSI_SCAN_GROUP_BEGIN[0],
    TSI_SCAN_GROUP_NUM,
    (TSI_SensorTypeDef **) &TSI_SensorPointers[0],
    TSI_SENSOR_NUM,
};

/*-----------------------------------*/
/* Widget info init data             */
/*-----------------------------------*/
TSI_ALIGN4 TSI_USED TSI_WidgetTypeDef *const TSI_WidgetPointers[TSI_WIDGET_NUM]
TSI_SECTION(TSI_CONST_P_WIDGETS_SECTION) = {
    (TSI_WidgetTypeDef *) &TSI_WidgetList.Button0,
    (TSI_WidgetTypeDef *) &TSI_WidgetList.Button1,
    (TSI_WidgetTypeDef *) &TSI_WidgetList.Button2,
    (TSI_WidgetTypeDef *) &TSI_WidgetList.Button3,
    (TSI_WidgetTypeDef *) &TSI_WidgetList.Button4,
    (TSI_WidgetTypeDef *) &TSI_WidgetList.Button5,
    (TSI_WidgetTypeDef *) &TSI_WidgetList.Button6,
    (TSI_WidgetTypeDef *) &TSI_WidgetList.Button7,
};

TSI_ALIGN4 TSI_USED const TSI_MetaWidgetTypeDef TSI_MetaWidgets[TSI_WIDGET_NUM]
TSI_SECTION(TSI_CONST_META_WIDGETS_SECTION) = {
    {   /* Button0 */
        TSI_WIDGET_SELF_CAP_BUTTON,             /* type */
        TSI_SensorList.Button0,                 /* sensors */
        TSI_BUTTON0_SENSOR_NUM,                 /* sensorNum */
        NULL,                                   /* dedicatedScanGroup */
    },
    {   /* Button1 */
        TSI_WIDGET_SELF_CAP_BUTTON,             /* type */
        TSI_SensorList.Button1,                 /* sensors */
        TSI_BUTTON1_SENSOR_NUM,                 /* sensorNum */
        NULL,                                   /* dedicatedScanGroup */
    },
    {   /* Button2 */
        TSI_WIDGET_SELF_CAP_BUTTON,             /* type */
        TSI_SensorList.Button2,                 /* sensors */
        TSI_BUTTON2_SENSOR_NUM,                 /* sensorNum */
        NULL,                                   /* dedicatedScanGroup */
    },
    {   /* Button3 */
        TSI_WIDGET_SELF_CAP_BUTTON,             /* type */
        TSI_SensorList.Button3,                 /* sensors */
        TSI_BUTTON3_SENSOR_NUM,                 /* sensorNum */
        NULL,                                   /* dedicatedScanGroup */
    },
    {   /* Button4 */
        TSI_WIDGET_SELF_CAP_BUTTON,             /* type */
        TSI_SensorList.Button4,                 /* sensors */
        TSI_BUTTON4_SENSOR_NUM,                 /* sensorNum */
        NULL,                                   /* dedicatedScanGroup */
    },
    {   /* Button5 */
        TSI_WIDGET_SELF_CAP_BUTTON,             /* type */
        TSI_SensorList.Button5,                 /* sensors */
        TSI_BUTTON5_SENSOR_NUM,                 /* sensorNum */
        NULL,                                   /* dedicatedScanGroup */
    },
    {   /* Button6 */
        TSI_WIDGET_SELF_CAP_BUTTON,             /* type */
        TSI_SensorList.Button6,                 /* sensors */
        TSI_BUTTON6_SENSOR_NUM,                 /* sensorNum */
        NULL,                                   /* dedicatedScanGroup */
    },
    {   /* Button7 */
        TSI_WIDGET_SELF_CAP_BUTTON,             /* type */
        TSI_SensorList.Button7,                 /* sensors */
        TSI_BUTTON7_SENSOR_NUM,                 /* sensorNum */
        NULL,                                   /* dedicatedScanGroup */
    },
};

TSI_ALIGN4 TSI_USED const TSI_WidgetListTypeDef TSI_WidgetListConstInit
TSI_SECTION(TSI_CONST_WIDGETS_SECTION) = {
    {   /* Button0 */
        {
            {
                /* Meta widget */
                (TSI_MetaWidgetTypeDef *) &TSI_MetaWidgets[0],

                /* Widget enable status */
                TSI_WIDGET_DISABLE,

               /* Basic param */
                {
                    400U,       /* activeTh */
                    50U,        /* activeHys */
                    50U,        /* noiseTh */
                    100U,       /* negNoiseTh */
                    1U,         /* bslnIIRCoeff */
                    3U,         /* onDebounce */
                    1U,         /* offDebounce */
                    50U,        /* bslnNegStopTimeout */
                },
                0U,             /* status */
            },
            100U,               /* sensitivity */
            2U,                 /* idacStep */
            3U,                 /* idacCompStep */
            12U,                /* resolution */
            20U,                /* swClkDiv */
            { 10U, 10U, 10U },   /* idacMod */
        },
        0U,                     /* buttonStat */
    },
    {   /* Button1 */
        {
            {
                /* Meta widget */
                (TSI_MetaWidgetTypeDef *) &TSI_MetaWidgets[1],

                /* Widget enable status */
                TSI_WIDGET_DISABLE,

                /* Basic param */
                {
                    400U,       /* activeTh */
                    50U,        /* activeHys */
                    50U,        /* noiseTh */
                    100U,       /* negNoiseTh */
                    1U,         /* bslnIIRCoeff */
                    3U,         /* onDebounce */
                    1U,         /* offDebounce */
                    50U,        /* bslnNegStopTimeout */
                },
                0U,             /* status */
            },
            100U,               /* sensitivity */
            2U,                 /* idacStep */
            3U,                 /* idacCompStep */
            12U,                /* resolution */
            20U,                /* swClkDiv */
            { 10U, 10U, 10U},   /* idacMod */
        },
        0U,                     /* buttonStat */
    },
    {   /* Button2 */
        {
            {
                /* Meta widget */
                (TSI_MetaWidgetTypeDef *) &TSI_MetaWidgets[2],

                /* Widget enable status */
                TSI_WIDGET_DISABLE,

               /* Basic param */
                {
                    400U,       /* activeTh */
                    50U,        /* activeHys */
                    50U,        /* noiseTh */
                    100U,       /* negNoiseTh */
                    1U,         /* bslnIIRCoeff */
                    3U,         /* onDebounce */
                    1U,         /* offDebounce */
                    50U,        /* bslnNegStopTimeout */
                },
                0U,             /* status */
            },
            100U,               /* sensitivity */
            2U,                 /* idacStep */
            3U,                 /* idacCompStep */
            12U,                /* resolution */
            20U,                /* swClkDiv */
            { 10U, 10U, 10U },   /* idacMod */
        },
        0U,                     /* buttonStat */
    },
    {   /* Button3 */
        {
            {
                /* Meta widget */
                (TSI_MetaWidgetTypeDef *) &TSI_MetaWidgets[3],

                /* Widget enable status */
                TSI_WIDGET_DISABLE,

               /* Basic param */
                {
                    400U,       /* activeTh */
                    50U,        /* activeHys */
                    50U,        /* noiseTh */
                    100U,       /* negNoiseTh */
                    1U,         /* bslnIIRCoeff */
                    3U,         /* onDebounce */
                    1U,         /* offDebounce */
                    50U,        /* bslnNegStopTimeout */
                },
                0U,             /* status */
            },
            100U,               /* sensitivity */
            2U,                 /* idacStep */
            3U,                 /* idacCompStep */
            12U,                /* resolution */
            20U,                /* swClkDiv */
            { 10U, 10U, 10U },   /* idacMod */
        },
        0U,                     /* buttonStat */
    },
    {   /* Button4 */
        {
            {
                /* Meta widget */
                (TSI_MetaWidgetTypeDef *) &TSI_MetaWidgets[4],

                /* Widget enable status */
                TSI_WIDGET_DISABLE,

               /* Basic param */
                {
                    400U,       /* activeTh */
                    50U,        /* activeHys */
                    50U,        /* noiseTh */
                    100U,       /* negNoiseTh */
                    1U,         /* bslnIIRCoeff */
                    3U,         /* onDebounce */
                    1U,         /* offDebounce */
                    50U,        /* bslnNegStopTimeout */
                },
                0U,             /* status */
            },
            100U,               /* sensitivity */
            2U,                 /* idacStep */
            3U,                 /* idacCompStep */
            12U,                /* resolution */
            20U,                /* swClkDiv */
            { 10U, 10U, 10U },   /* idacMod */
        },
        0U,                     /* buttonStat */
    },
    {   /* Button5 */
        {
            {
                /* Meta widget */
                (TSI_MetaWidgetTypeDef *) &TSI_MetaWidgets[5],

                /* Widget enable status */
                TSI_WIDGET_DISABLE,

               /* Basic param */
                {
                    400U,       /* activeTh */
                    50U,        /* activeHys */
                    50U,        /* noiseTh */
                    100U,       /* negNoiseTh */
                    1U,         /* bslnIIRCoeff */
                    3U,         /* onDebounce */
                    1U,         /* offDebounce */
                    50U,        /* bslnNegStopTimeout */
                },
                0U,             /* status */
            },
            100U,               /* sensitivity */
            2U,                 /* idacStep */
            3U,                 /* idacCompStep */
            12U,                /* resolution */
            20U,                /* swClkDiv */
            { 10U, 10U, 10U },   /* idacMod */
        },
        0U,                     /* buttonStat */
    },
    {   /* Button6 */
        {
            {
                /* Meta widget */
                (TSI_MetaWidgetTypeDef *) &TSI_MetaWidgets[6],

                /* Widget enable status */
                TSI_WIDGET_DISABLE,

                /* Basic param */
                {
                    400U,       /* activeTh */
                    50U,        /* activeHys */
                    50U,        /* noiseTh */
                    100U,       /* negNoiseTh */
                    1U,         /* bslnIIRCoeff */
                    3U,         /* onDebounce */
                    1U,         /* offDebounce */
                    50U,        /* bslnNegStopTimeout */
                },
                0U,             /* status */
            },
            100U,               /* sensitivity */
            2U,                 /* idacStep */
            3U,                 /* idacCompStep */
            12U,                /* resolution */
            20U,                /* swClkDiv */
            { 10U, 10U, 10U},   /* idacMod */
        },
        0U,                     /* buttonStat */
    },
    {   /* Button7 */
        {
            {
                /* Meta widget */
                (TSI_MetaWidgetTypeDef *) &TSI_MetaWidgets[7],

                /* Widget enable status */
                TSI_WIDGET_DISABLE,

                /* Basic param */
                {
                    400U,       /* activeTh */
                    50U,        /* activeHys */
                    50U,        /* noiseTh */
                    100U,       /* negNoiseTh */
                    1U,         /* bslnIIRCoeff */
                    3U,         /* onDebounce */
                    1U,         /* offDebounce */
                    50U,        /* bslnNegStopTimeout */
                },
                0U,             /* status */
            },
            100U,               /* sensitivity */
            2U,                 /* idacStep */
            3U,                 /* idacCompStep */
            12U,                /* resolution */
            20U,                /* swClkDiv */
            { 10U, 10U, 10U },   /* idacMod */
        },
        0U,                     /* buttonStat */
    },
};

/*-----------------------------------*/
/* Sensor info init data             */
/*-----------------------------------*/
TSI_ALIGN4 TSI_USED TSI_SensorTypeDef *const TSI_SensorPointers[TSI_SENSOR_NUM]
TSI_SECTION(TSI_CONST_P_SENSORS_SECTION) = {
    (TSI_SensorTypeDef *) &TSI_SensorList.Button0[0],
    (TSI_SensorTypeDef *) &TSI_SensorList.Button1[0],
    (TSI_SensorTypeDef *) &TSI_SensorList.Button2[0],
    (TSI_SensorTypeDef *) &TSI_SensorList.Button3[0],
    (TSI_SensorTypeDef *) &TSI_SensorList.Button4[0],
    (TSI_SensorTypeDef *) &TSI_SensorList.Button5[0],
    (TSI_SensorTypeDef *) &TSI_SensorList.Button6[0],
    (TSI_SensorTypeDef *) &TSI_SensorList.Button7[0],
};

TSI_ALIGN4 TSI_USED const TSI_MetaSensorTypeDef TSI_MetaSensors[TSI_SENSOR_NUM]
TSI_SECTION(TSI_CONST_META_SENSORS_SECTION) = {
    {   /* Button0_Sns0 */
        (TSI_WidgetTypeDef *) &TSI_WidgetList.Button0,/* parent */
        0U,                                     /* id */
        TSI_SENSOR_SELF_CAP,                    /* type */
        0U,                                     /* txChannel */
        1U,                                     /* rxChannel */
        NULL,                                   /* detConf */
        TSI_FILTER_NORMAL,                      /* filterType */
        &TSI_Filter_Button0[0],                 /* filter */
        1U,                                     /* debArraySize */
        &TSI_Debounce_Button0[0],               /* debArray */
        TSI_SCAN_GROUP_REF(0),                  /* dedicatedScanGroup */
    },
    {   /* Button1_Sns0 */
        (TSI_WidgetTypeDef *) &TSI_WidgetList.Button1,/* parent */
        1U,                                     /* id */
        TSI_SENSOR_SELF_CAP,                    /* type */
        0U,                                     /* txChannel */
        3U,                                     /* rxChannel */
        NULL,                                   /* detConf */
        TSI_FILTER_NORMAL,                      /* filterType */
        &TSI_Filter_Button1[0],                 /* filter */
        1U,                                     /* debArraySize */
        &TSI_Debounce_Button1[0],               /* debArray */
        TSI_SCAN_GROUP_REF(0),                  /* dedicatedScanGroup */
    },
    {   /* Button2_Sns0 */
        (TSI_WidgetTypeDef *) &TSI_WidgetList.Button2,/* parent */
        2U,                                     /* id */
        TSI_SENSOR_SELF_CAP,                    /* type */
        0U,                                     /* txChannel */
        9U,                                     /* rxChannel */
        NULL,                                   /* detConf */
        TSI_FILTER_NORMAL,                      /* filterType */
        &TSI_Filter_Button2[0],                 /* filter */
        1U,                                     /* debArraySize */
        &TSI_Debounce_Button2[0],               /* debArray */
        TSI_SCAN_GROUP_REF(0),                  /* dedicatedScanGroup */
    },
    {   /* Button3_Sns0 */
        (TSI_WidgetTypeDef *) &TSI_WidgetList.Button3,/* parent */
        3U,                                     /* id */
        TSI_SENSOR_SELF_CAP,                    /* type */
        0U,                                     /* txChannel */
        6U,                                     /* rxChannel */
        NULL,                                   /* detConf */
        TSI_FILTER_NORMAL,                      /* filterType */
        &TSI_Filter_Button3[0],                 /* filter */
        1U,                                     /* debArraySize */
        &TSI_Debounce_Button3[0],               /* debArray */
        TSI_SCAN_GROUP_REF(0),                  /* dedicatedScanGroup */
    },
    {   /* Button4_Sns0 */
        (TSI_WidgetTypeDef *) &TSI_WidgetList.Button4,/* parent */
        4U,                                     /* id */
        TSI_SENSOR_SELF_CAP,                    /* type */
        0U,                                     /* txChannel */
        11U,                                    /* rxChannel */
        NULL,                                   /* detConf */
        TSI_FILTER_NORMAL,                      /* filterType */
        &TSI_Filter_Button4[0],                 /* filter */
        1U,                                     /* debArraySize */
        &TSI_Debounce_Button4[0],               /* debArray */
        TSI_SCAN_GROUP_REF(0),                  /* dedicatedScanGroup */
    },
    {   /* Button5_Sns0 */
        (TSI_WidgetTypeDef *) &TSI_WidgetList.Button5,/* parent */
        5U,                                     /* id */
        TSI_SENSOR_SELF_CAP,                    /* type */
        0U,                                     /* txChannel */
        8U,                                     /* rxChannel */
        NULL,                                   /* detConf */
        TSI_FILTER_NORMAL,                      /* filterType */
        &TSI_Filter_Button5[0],                 /* filter */
        1U,                                     /* debArraySize */
        &TSI_Debounce_Button5[0],               /* debArray */
        TSI_SCAN_GROUP_REF(0),                  /* dedicatedScanGroup */
    },
    {   /* Button6_Sns0 */
        (TSI_WidgetTypeDef *) &TSI_WidgetList.Button6,/* parent */
        6U,                                     /* id */
        TSI_SENSOR_SELF_CAP,                    /* type */
        0U,                                     /* txChannel */
        10U,                                    /* rxChannel */
        NULL,                                   /* detConf */
        TSI_FILTER_NORMAL,                      /* filterType */
        &TSI_Filter_Button6[0],                 /* filter */
        1U,                                     /* debArraySize */
        &TSI_Debounce_Button6[0],               /* debArray */
        TSI_SCAN_GROUP_REF(0),                  /* dedicatedScanGroup */
    },
    {   /* Button7_Sns0 */
        (TSI_WidgetTypeDef *) &TSI_WidgetList.Button7,/* parent */
        7U,                                     /* id */
        TSI_SENSOR_SELF_CAP,                    /* type */
        0U,                                     /* txChannel */
        13U,                                    /* rxChannel */
        NULL,                                   /* detConf */
        TSI_FILTER_NORMAL,                      /* filterType */
        &TSI_Filter_Button7[0],                 /* filter */
        1U,                                     /* debArraySize */
        &TSI_Debounce_Button7[0],               /* debArray */
        TSI_SCAN_GROUP_REF(0),                  /* dedicatedScanGroup */
    },
};

TSI_ALIGN4 TSI_USED const TSI_SensorListTypeDef TSI_SensorListConstInit
TSI_SECTION(TSI_CONST_SENSORS_SECTION) = {
    {
        {   /* Button0_Sns0 */
            (TSI_MetaSensorTypeDef *) &TSI_MetaSensors[0],
            { 0U, 0U, 0U },     /* idac */
            0U,                 /* rawCount */
            0U,                 /* baseline */
            0U,                 /* diffCount */
            0U,                 /* status */
        },
    },
    {
        {   /* Button1_Sns0 */
            (TSI_MetaSensorTypeDef *) &TSI_MetaSensors[1],
            { 0U, 0U, 0U },     /* idac */
            0U,                 /* rawCount */
            0U,                 /* baseline */
            0U,                 /* diffCount */
            0U,                 /* status */
        },
    },
    {
        {   /* Button2_Sns0 */
            (TSI_MetaSensorTypeDef *) &TSI_MetaSensors[2],
            { 0U, 0U, 0U },     /* idac */
            0U,                 /* rawCount */
            0U,                 /* baseline */
            0U,                 /* diffCount */
            0U,                 /* status */
        },
    },
    {
        {   /* Button3_Sns0 */
            (TSI_MetaSensorTypeDef *) &TSI_MetaSensors[3],
            { 0U, 0U, 0U },     /* idac */
            0U,                 /* rawCount */
            0U,                 /* baseline */
            0U,                 /* diffCount */
            0U,                 /* status */
        },
    },
    {
        {   /* Button4_Sns0 */
            (TSI_MetaSensorTypeDef *) &TSI_MetaSensors[4],
            { 0U, 0U, 0U },     /* idac */
            0U,                 /* rawCount */
            0U,                 /* baseline */
            0U,                 /* diffCount */
            0U,                 /* status */
        },
    },
    {
        {   /* Button5_Sns0 */
            (TSI_MetaSensorTypeDef *) &TSI_MetaSensors[5],
            { 0U, 0U, 0U },     /* idac */
            0U,                 /* rawCount */
            0U,                 /* baseline */
            0U,                 /* diffCount */
            0U,                 /* status */
        },
    },
    {
        {   /* Button6_Sns0 */
            (TSI_MetaSensorTypeDef *) &TSI_MetaSensors[6],
            { 0U, 0U, 0U },     /* idac */
            0U,                 /* rawCount */
            0U,                 /* baseline */
            0U,                 /* diffCount */
            0U,                 /* status */
        },
    },
    {
        {   /* Button7_Sns0 */
            (TSI_MetaSensorTypeDef *) &TSI_MetaSensors[7],
            { 0U, 0U, 0U },     /* idac */
            0U,                 /* rawCount */
            0U,                 /* baseline */
            0U,                 /* diffCount */
            0U,                 /* status */
        },
    },
};

#if (TSI_USE_CONFIG_DESCRIPTOR == 1U)
TSI_USED const uint8_t TSI_ConfDesc[TSI_CONF_DESC_SIZE] TSI_SECTION(TSI_CONF_DESC_SECTION) = {
    0x1EU,                              /* Descriptor type (Configuration) */
    0x0U,                               /* Total length (131) */
    0x83U,                              
    0x01U,                              /* Lib version code (v1.0) */
    0x00U,
    0x09U,                              /* Setting count (9) */
    8U,                                 /* Widget count (8) */

    /* Lib Settings ---------------------------*/
    0xF0U,                              /* Descriptor type (Setting) */
    0x00U,                              /* Id (TSI_SC_CALIB_METHOD) */
    0x01U,                              /* Size (1) */
    TSI_SC_CALIB_METHOD,                /* Value */

    0xF0U,                              /* Descriptor type (Setting) */
    0x01U,                              /* Id (TSI_MC_CALIB_METHOD) */
    0x01U,                              /* Size (1) */
    TSI_MC_CALIB_METHOD,                /* Value */

    0xF0U,                              /* Descriptor type (Setting) */
    0x02U,                              /* Id (TSI_SCAN_FREQ_NUM) */
    0x01U,                              /* Size (1) */
    TSI_SCAN_FREQ_NUM,                  /* Value */

    0xF0U,                              /* Descriptor type (Setting) */
    0x03U,                              /* Id (TSI_SC_USE_UNIFIED_IDAC_STEP) */
    0x01U,                              /* Size (1) */
    TSI_SC_USE_UNIFIED_IDAC_STEP,       /* Value */

    0xF0U,                              /* Descriptor type (Setting) */
    0x04U,                              /* Id (TSI_STATISTIC_SENSOR_CS) */
    0x01U,                              /* Size (1) */
    TSI_STATISTIC_SENSOR_CS,            /* Value */

    0xF0U,                              /* Descriptor type (Setting) */
    0x05U,                              /* Id (TSI_USED_IN_LPM_MODE) */
    0x01U,                              /* Size (1) */
    TSI_USED_IN_LPM_MODE,               /* Value */

    0xF0U,                              /* Descriptor type (Setting) */
    0x06U,                              /* Id (TSI_USE_SHIELD) */
    0x01U,                              /* Size (1) */
    TSI_USE_SHIELD,                     /* Value */

    0xF0U,                              /* Descriptor type (Setting) */
    0x07U,                              /* Id (TSI_SENSOR_BSLN_ALWAYS_UPDATE) */
    0x01U,                              /* Size (1) */
    TSI_SENSOR_BSLN_ALWAYS_UPDATE,      /* Value */

    0xF0U,                              /* Descriptor type (Setting) */
    0x08U,                              /* Id (TSI_SENSOR_BSLN_USE_LTA) */
    0x01U,                              /* Size (1) */
    TSI_SENSOR_BSLN_USE_LTA,            /* Value */

    /* Widgets --------------------------------*/
    /* Button0 */
    0x2D,                               /* Descriptor type (Widget) */
    TSI_WIDGET_SELF_CAP_BUTTON,         /* Widget type (Self-cap button) */
    0x00,                               /* Widget string descriptor index (NULL) */
    0x0U,                               /* Sensor count (1) */
    0x1U,                               

    /* Button0_Sns0 */
    0x3C,                               /* Descriptor type (Sensor) */
    0x0U,                               /* Sensor id(0) */
    0x0U,                               
    TSI_SENSOR_SELF_CAP,                /* Sensor type */
    0U,                                 /* txChannel */
    1U,                                 /* rxChannel */

    /* Button1 */
    0x2D,                               /* Descriptor type (Widget) */
    TSI_WIDGET_SELF_CAP_BUTTON,         /* Widget type (Self-cap button) */
    0x00,                               /* Widget string descriptor index (NULL) */
    0x0U,                               /* Sensor count (1) */
    0x1U,                               

    /* Button1_Sns0 */
    0x3C,                               /* Descriptor type (Sensor) */
    0x0U,                               /* Sensor id(1) */
    0x1U,                               
    TSI_SENSOR_SELF_CAP,                /* Sensor type */
    0U,                                 /* txChannel */
    3U,                                 /* rxChannel */

    /* Button2 */
    0x2D,                               /* Descriptor type (Widget) */
    TSI_WIDGET_SELF_CAP_BUTTON,         /* Widget type (Self-cap button) */
    0x00,                               /* Widget string descriptor index (NULL) */
    0x0U,                               /* Sensor count (1) */
    0x1U,                               

    /* Button2_Sns0 */
    0x3C,                               /* Descriptor type (Sensor) */
    0x0U,                               /* Sensor id(2) */
    0x2U,                               
    TSI_SENSOR_SELF_CAP,                /* Sensor type */
    0U,                                 /* txChannel */
    9U,                                 /* rxChannel */

    /* Button3 */
    0x2D,                               /* Descriptor type (Widget) */
    TSI_WIDGET_SELF_CAP_BUTTON,         /* Widget type (Self-cap button) */
    0x00,                               /* Widget string descriptor index (NULL) */
    0x0U,                               /* Sensor count (1) */
    0x1U,                               

    /* Button3_Sns0 */
    0x3C,                               /* Descriptor type (Sensor) */
    0x0U,                               /* Sensor id(3) */
    0x3U,                               
    TSI_SENSOR_SELF_CAP,                /* Sensor type */
    0U,                                 /* txChannel */
    6U,                                 /* rxChannel */

    /* Button4 */
    0x2D,                               /* Descriptor type (Widget) */
    TSI_WIDGET_SELF_CAP_BUTTON,         /* Widget type (Self-cap button) */
    0x00,                               /* Widget string descriptor index (NULL) */
    0x0U,                               /* Sensor count (1) */
    0x1U,                               

    /* Button4_Sns0 */
    0x3C,                               /* Descriptor type (Sensor) */
    0x0U,                               /* Sensor id(4) */
    0x4U,                               
    TSI_SENSOR_SELF_CAP,                /* Sensor type */
    0U,                                 /* txChannel */
    11U,                                /* rxChannel */

    /* Button5 */
    0x2D,                               /* Descriptor type (Widget) */
    TSI_WIDGET_SELF_CAP_BUTTON,         /* Widget type (Self-cap button) */
    0x00,                               /* Widget string descriptor index (NULL) */
    0x0U,                               /* Sensor count (1) */
    0x1U,                               

    /* Button5_Sns0 */
    0x3C,                               /* Descriptor type (Sensor) */
    0x0U,                               /* Sensor id(5) */
    0x5U,                               
    TSI_SENSOR_SELF_CAP,                /* Sensor type */
    0U,                                 /* txChannel */
    8U,                                 /* rxChannel */

    /* Button6 */
    0x2D,                               /* Descriptor type (Widget) */
    TSI_WIDGET_SELF_CAP_BUTTON,         /* Widget type (Self-cap button) */
    0x00,                               /* Widget string descriptor index (NULL) */
    0x0U,                               /* Sensor count (1) */
    0x1U,                               

    /* Button6_Sns0 */
    0x3C,                               /* Descriptor type (Sensor) */
    0x0U,                               /* Sensor id(6) */
    0x6U,                               
    TSI_SENSOR_SELF_CAP,                /* Sensor type */
    0U,                                 /* txChannel */
    10U,                                /* rxChannel */

    /* Button7 */
    0x2D,                               /* Descriptor type (Widget) */
    TSI_WIDGET_SELF_CAP_BUTTON,         /* Widget type (Self-cap button) */
    0x00,                               /* Widget string descriptor index (NULL) */
    0x0U,                               /* Sensor count (1) */
    0x1U,                               

    /* Button7_Sns0 */
    0x3C,                               /* Descriptor type (Sensor) */
    0x0U,                               /* Sensor id(7) */
    0x7U,                               
    TSI_SENSOR_SELF_CAP,                /* Sensor type */
    0U,                                 /* txChannel */
    13U,                                /* rxChannel */

};
#endif  /* TSI_USE_CONFIG_DESCRIPTOR == 1U */

/* API implementations ------------------------------------------------------*/
void TSI_InitObjects(TSI_LibHandleTypeDef *handle)
{
    if(handle == &TSI_LibHandle) {
        memcpy(&TSI_Drv, &TSI_DrvConstInit, sizeof(TSI_DriverTypeDef));
        memcpy(&TSI_WidgetList, &TSI_WidgetListConstInit, sizeof(TSI_WidgetListTypeDef));
        memcpy(&TSI_SensorList, &TSI_SensorListConstInit, sizeof(TSI_SensorListTypeDef));
        memcpy(&TSI_ClockConf, &TSI_ClockConfConstInit, sizeof(TSI_ClockConfConstInit));
    }
}


