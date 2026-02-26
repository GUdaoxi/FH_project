#ifndef TSI_DEF_H
#define TSI_DEF_H

/* Includes -------------------------------------------------------------------------------------------*/
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Defines --------------------------------------------------------------------------------------------*/
#ifndef TSI_UNIT_TEST

#if defined(__CC_ARM)   /* ARM Compiler 4/5 */
#define TSI_USED                    __attribute__((used))
#define TSI_SECTION(__NAME__)       __attribute__((section(__NAME__)))
#define TSI_ALIGN4                  __attribute__((aligned(4)))
#define TSI_WEAK                    __attribute__((weak))
#define TSI_INLINE                  __inline
#define TSI_STATIC_INLINE           static __inline
#define TSI_NO_RETURN               __declspec(noreturn)

#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) /* ARM Compiler 6 */
#define TSI_USED                    __attribute__((used))
#define TSI_SECTION(__NAME__)       __attribute__((section(__NAME__)))
#define TSI_ALIGN4                  __attribute__((aligned(4)))
#define TSI_WEAK                    __attribute__((weak))
#define TSI_INLINE                  __inline
#define TSI_STATIC_INLINE           static __inline
#define TSI_NO_RETURN               __attribute__((noreturn))

#elif defined(__ICCARM__)  /* IAR */
#define TSI_USED                    __root
#define TSI_SECTION(__NAME__)       @ __NAME__
#define TSI_ALIGN4                  _Pragma("data_alignment=4")
#define TSI_WEAK                    __weak
#define TSI_INLINE                  inline
#define TSI_STATIC_INLINE           static inline
#define TSI_NO_RETURN               __noreturn

#elif defined ( __GNUC__ )                                            /* GNU Compiler */
#define TSI_USED                    __attribute__((used))
#define TSI_SECTION(__NAME__)       __attribute__((section(__NAME__)))
#define TSI_ALIGN4                  __attribute__((aligned(4)))
#define TSI_WEAK                    __attribute__((weak))
#define TSI_INLINE                  inline
#define TSI_STATIC_INLINE           static inline
#define TSI_NO_RETURN               __attribute__((noreturn))

#endif  /* Compiler */

#define TSI_STATIC                  static

#else

/* For unit test: Export internal functions and variables, disable compiler-specified codes. */
#define TSI_USED
#define TSI_SECTION(__NAME__)
#define TSI_ALIGN4
#define TSI_WEAK
#define TSI_INLINE
#define TSI_STATIC_INLINE
#define TSI_NO_RETURN

#define TSI_STATIC

#endif  /* TSI_UNIT_TEST */

/* Memory sections. */
#define TSI_CONST_LIB_SECTION               "tsi.const.00_lib_handle"
#define TSI_CONST_WIDGETS_SECTION           "tsi.const.01_widgets"
#define TSI_CONST_SENSORS_SECTION           "tsi.const.02_sensors"
#define TSI_CONST_P_WIDGETS_SECTION         "tsi.const.03_widget_ptrs"
#define TSI_CONST_P_SENSORS_SECTION         "tsi.const.04_sensor_ptrs"
#define TSI_CONST_META_WIDGETS_SECTION      "tsi.const.05_meta_widgets"
#define TSI_CONST_META_SENSORS_SECTION      "tsi.const.06_meta_sensors"
#define TSI_CONST_DRVIER_SECTION            "tsi.const.07_driver"
#define TSI_CONST_MISCS_SECTION             "tsi.const.08_miscs"
#define TSI_GROUP_BEGIN_SECTION             "tsi.const.09_scangroup.0_begin"
#define TSI_GROUP_SECTION                   "tsi.const.09_scangroup.1_group"
#define TSI_CONF_DESC_SECTION               "tsi.const.10_desc_conf"
#define TSI_PLUGINS_BEGIN_SECTION           "tsi.const.11_plugins.0_begin"
#define TSI_PLUGINS_SECTION                 "tsi.const.11_plugins.1_cb."
#define TSI_PLUGINS_END_SECTION             "tsi.const.11_plugins.2_end"
#define TSI_LIB_SECTION                     "tsi.00_lib_handle"
#define TSI_WIDGETS_SECTION                 "tsi.01_widgets"
#define TSI_SENSORS_SECTION                 "tsi.02_sensors"
#define TSI_DRIVER_SECTION                  "tsi.03_driver"
#define TSI_MISCS_SECTION                   "tsi.04_miscs"
#define TSI_DEBUG_RAWCOUNT_SECTION          "tsi.05_debug_rawcount"

/* Macros -------------------------------------------------------------------*/
/**
 * Shorthand for traversing through array using index. Use together
 * with :c:macro:`TSI_FOREACH_END` to form a closed loop.
 */
#define TSI_FOREACH(TYPE_PTR_NAME, ARRAY, SIZE, FIRST_IDX)                  \
    {                                                                       \
        uint32_t idx;                                                       \
        for(idx = (uint32_t)(FIRST_IDX); idx < (uint32_t)(SIZE); idx++)     \
        {                                                                   \
            TYPE_PTR_NAME = &((ARRAY)[idx]);

/**
 * Shorthand for traversing through array using object. Use together
 * with :c:macro:`TSI_FOREACH_END` to form a closed loop.
 */
#define TSI_FOREACH_IDX(TYPE_NAME, ARRAY, SIZE, FIRST_IDX)                  \
    {                                                                       \
        uint32_t idx;                                                       \
        for(idx = (uint32_t)(FIRST_IDX); idx < (uint32_t)(SIZE); idx++)     \
        {                                                                   \
            TYPE_NAME = (ARRAY)[idx];

/**
 * Shorthand for traversing through array using object pointer. Use together
 * with :c:macro:`TSI_FOREACH_END` to form a closed loop.
 */
#define TSI_FOREACH_OBJ(TYPE_PTR, NAME, ARRAY, SIZE)                        \
    {                                                                       \
        uint32_t idx;                                                       \
        TYPE_PTR NAME = (ARRAY);                                            \
        for(idx = 0UL; idx < (uint32_t)(SIZE); idx++, (NAME)++)             \
        {

/** See :c:macro:`TSI_FOREACH`. */
#define TSI_FOREACH_END()                                                   \
        }                                                                   \
    }

#ifdef TSI_LIB_USE_ASSERT
/** Assertion, will call :c:func:`TSI_AssertFailed` on failure.  */
#define TSI_ASSERT(EXPR)    ((EXPR) ? (void)0 : TSI_AssertFailedCallback((uint8_t *)__FILE__, __LINE__))
/** Callback for assert failure. See also :c:macro:`TSI_ASSERT`. */
void TSI_AssertFailedCallback(uint8_t *file, uint32_t line);
#else
#define TSI_ASSERT(EXPR)
#endif  /* TSI_LIB_USE_ASSERT */

/** Shorthand for waiting with timeout. */
#define TSI_WAIT_TIMEOUT(EXPR, TIME)                                \
{                                                                   \
    uint32_t timeout = TIME;                                        \
    while(timeout--) {                                              \
        if((EXPR)) { break; }                                       \
        TSI_Dev_ClearWDT();                                         \
    }                                                               \
    if(timeout == 0UL) {                                            \
        TSI_TimeoutCallback((uint8_t *)__FILE__, __LINE__);

#define TSI_WAIT_TIMEOUT_END()                                      \
    }                                                               \
}

/** Callback for timeout failure. See also :c:macro:`TSI_TIMEOUT`. */
void TSI_TimeoutCallback(uint8_t *file, uint32_t line);

/** Callback for errors. */
void TSI_ErrorCallback(uint8_t *file, uint32_t line);

/** Unused variables. */
#define TSI_UNUSED(VAR)             (void) (VAR);

/** Invalid data value. */
#define TSI_DATA_INVALID            (0xFFFFFFFFUL)

/* Defines ------------------------------------------------------------------*/
/**
 *  TSI library return codes.
 */
typedef enum _TSI_RetCode {
    /** Everything is ok. */
    TSI_PASS            = 0,
    /** TSI library is still waiting for hardware operation to complete. */
    TSI_WAIT            = 1,

    /* Errors */
    TSI_ERROR           = 128,      /* Dummy(Unknown) error */
    TSI_TIMEOUT         = 129,      /* Operation timeout */
    TSI_PARAM_ERR       = 130,      /* Wrong parameter passed */
    TSI_UNSUPPORTED     = 131,      /* Unsupported operation */
} TSI_RetCode;

/**
 *  TSI library operation states.
 */
typedef enum _TSI_LibStat {
    TSI_LIB_RESET       = 0,
    TSI_LIB_INIT        = 1,
    TSI_LIB_RUNNING     = 2,
    TSI_LIB_SUSPEND     = 3,
} TSI_LibStat;

/**
 *  TSI library commands (0x00-0x3F).
 */
#define TSI_CMD_START                       (0x00U)
#define TSI_CMD_STOP                        (0x01U)
#define TSI_CMD_GET_STAT                    (0x02U)
#define TSI_CMD_INIT                        (0x03U)
#define TSI_CMD_RECONFIG                    (0x04U)
#define TSI_CMD_RECONFIG_NO_CALIB           (0x05U)
#define TSI_CMD_GET_CFG_DESC_ADDR           (0x10U)
#define TSI_CMD_GET_WIDGET_LIST_ADDR        (0x11U)
#define TSI_CMD_GET_SENSOR_LIST_ADDR        (0x12U)
#define TSI_CMD_CTRL_SCAN                   (0x13U)
#define TSI_CMD_GET_SCAN_STAT               (0x14U)
#define TSI_CMD_ENABLE_WIDGET               (0x20U)
#define TSI_CMD_ENABLE_ALL_WIDGET           (0x21U)
#define TSI_CMD_DISABLE_WIDGET              (0x22U)
#define TSI_CMD_DISABLE_ALL_WIDGET          (0x23U)
#define TSI_CMD_INIT_WIDGET                 (0x24U)
#define TSI_CMD_INIT_ALL_WIDGET             (0x25U)
#define TSI_CMD_UPDATE_ALL_WIDGET           (0x26U)
#define TSI_CMD_CALIB_WIDGET                (0x30U)
#define TSI_CMD_CALIB_ALL_WIDGET            (0x31U)
#define TSI_CMD_CALC_SENSOR_CAP             (0x32U)
#define TSI_CMD_CALC_ALL_SENSOR_CAP         (0x33U)

#ifdef __cplusplus
}
#endif

#endif  /* TSI_DEF_H */
