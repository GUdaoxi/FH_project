#ifndef BDP_DEF_H
#define BDP_DEF_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* Includes -------------------------------------------------------------------------------------------*/
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Defines --------------------------------------------------------------------------------------------*/
#ifndef BDP_UNIT_TEST

#if defined(__CC_ARM)   /* ARM Compiler 4/5 */
#define BDP_USED                    __attribute__((used))
#define BDP_SECTION(__NAME__)       __attribute__((section(__NAME__)))
#define BDP_ALIGN4                  __attribute__((aligned(4)))
#define BDP_WEAK                    __attribute__((weak))
#define BDP_INLINE                  __inline
#define BDP_STATIC_INLINE           static __inline
#define BDP_NO_RETURN               __declspec(noreturn)

#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) /* ARM Compiler 6 */
#define BDP_USED                    __attribute__((used))
#define BDP_SECTION(__NAME__)       __attribute__((section(__NAME__)))
#define BDP_ALIGN4                  __attribute__((aligned(4)))
#define BDP_WEAK                    __attribute__((weak))
#define BDP_INLINE                  __inline
#define BDP_STATIC_INLINE           static __inline
#define BDP_NO_RETURN               __attribute__((noreturn))

#elif defined(__ICCARM__)  /* IAR */
#define BDP_USED                    __root
#define BDP_SECTION(__NAME__)       @ __NAME__
#define BDP_ALIGN4                  _Pragma("data_alignment=4")
#define BDP_WEAK                    __weak
#define BDP_INLINE                  inline
#define BDP_STATIC_INLINE           static inline
#define BDP_NO_RETURN               __noreturn

#elif defined ( __GNUC__ )                                            /* GNU Compiler */
#define BDP_USED                    __attribute__((used))
#define BDP_SECTION(__NAME__)       __attribute__((section(__NAME__)))
#define BDP_ALIGN4                  __attribute__((aligned(4)))
#define BDP_WEAK                    __attribute__((weak))
#define BDP_INLINE                  inline
#define BDP_STATIC_INLINE           static inline
#define BDP_NO_RETURN               __attribute__((noreturn))

#endif  /* Compiler */

#define BDP_STATIC                  static

#else

/* For unit test: Export internal functions and variables, disable compiler-specified codes. */
#define BDP_USED
#define BDP_SECTION(__NAME__)
#define BDP_ALIGN4
#define BDP_WEAK
#define BDP_INLINE
#define BDP_STATIC_INLINE
#define BDP_NO_RETURN

#define BDP_STATIC

#endif  /* BDP_UNIT_TEST */

/* Macros -------------------------------------------------------------------*/
#ifdef BDP_LIB_USE_ASSERT
/** Assertion, will call :c:func:`BDP_AssertFailed` on failure.  */
#define BDP_ASSERT(EXPR)    ((EXPR) ? (void)0 : BDP_AssertFailedCallback((uint8_t *)__FILE__, __LINE__))
/** Callback for assert failure. See also :c:macro:`BDP_ASSERT`. */
void BDP_AssertFailedCallback(uint8_t *file, uint32_t line);
#else
#define BDP_ASSERT(EXPR)
#endif  /* BDP_LIB_USE_ASSERT */

/** Shorthand for waiting with timeout. */
#define BDP_WAIT_TIMEOUT(EXPR, TIME)                                \
{                                                                   \
    uint32_t timeout = TIME;                                        \
    while(timeout--) {                                              \
        if((EXPR)) break;                                           \
    }                                                               \
    if(!(EXPR)) {                                                   \
        BDP_TimeoutCallback((uint8_t *)__FILE__, __LINE__);         \

#define BDP_WAIT_TIMEOUT_END()                                      \
    }                                                               \
}

/** Callback for timeout failure. See also :c:macro:`BDP_TIMEOUT`. */
void BDP_TimeoutCallback(uint8_t *file, uint32_t line);

#define BDP_UNUSED(VAR)             (void) (VAR);

/* Defines ------------------------------------------------------------------*/
/**
 *  BladeDP library return codes.
 */
typedef enum _BDP_RetCode {
    /** Everything is ok. */
    BDP_PASS            = 0,

    /* Errors */
    BDP_ERROR           = 128,      /* Dummy(Unknown) error */
    BDP_TIMEOUT         = 129,      /* Operation timeout */
    BDP_PARAM_ERR       = 130,      /* Wrong parameter passed */
    BDP_UNSUPPORTED     = 131,      /* Unsupported operation */
} BDP_RetCode;

/**
 *  BladeDP PIDs.
 */
#define BDP_PID_IN_CHK              (0x0FU)
#define BDP_PID_IRQ_IN_CHK          (0x1EU)
#define BDP_PID_ACK_CHK             (0x2DU)
#define BDP_PID_OUT_CHK             (0x3CU)
#define BDP_PID_DATA_CHK            (0x4BU)
#define BDP_PID_IN_NCHK             (0x87U)
#define BDP_PID_IRQ_IN_NCHK         (0x96U)
#define BDP_PID_ACK_NCHK            (0xA5U)
#define BDP_PID_OUT_NCHK            (0xB4U)
#define BDP_PID_DATA_NCHK           (0xC3U)

/**
 *  BladeDP ACK codes.
 */
#define BDP_ACK_OK                  (0x00U)
#define BDP_ACK_CMD_ERROR           (0x01U)
#define BDP_ACK_CMD_NOT_SUPPORTED   (0x02U)
#define BDP_ACK_CMD_PARAM_ERROR     (0x03U)
#define BDP_ACK_DATA_ERROR          (0x04U)
#define BDP_ACK_CMD_EXEC_ERROR      (0x05U)
#define BDP_ACK_UNKNOWN_ERROR       (0xFFU)

/**
 * BladeDP commands.
 */
/* Setup commands */
#define BDP_CMD_RESET_DEVICE        (0x00U)
#define BDP_CMD_SELECT_TARGET       (0x01U)
#define BDP_CMD_SET_ADDR            (0x02U)
#define BDP_CMD_GET_INFO            (0x03U)
#define BDP_CMD_SET_CONF            (0x04U)
/* Control commands */
#define BDP_CMD_PING                (0x20U)
#define BDP_CMD_SET_REG             (0x21U)
#define BDP_CMD_GET_REG             (0x22U)
#define BDP_CMD_SET_MULTI_REG       (0x23U)
#define BDP_CMD_SET_VAL             (0x24U)
#define BDP_CMD_GET_VAL             (0x25U)
#define BDP_CMD_SET_MULTI_VAL       (0x26U)
#define BDP_CMD_SET_MEM_ADDR        (0x27U)
#define BDP_CMD_SET_MEM             (0x28U)
#define BDP_CMD_GET_MEM             (0x29U)

/**
 * BladeDP info id.
 */
#define BDP_INFO_REV                (0x00U)
#define BDP_INFO_MAX_DATA_LEN       (0x01U)
#define BDP_INFO_USE_CHECKSUM       (0x02U)
#define BDP_INFO_STATUS             (0x03U)
#define BDP_INFO_ENDIAN             (0x04U)

/**
 * BladeDP conf id.
 */
#define BDP_CONF_DATA_LEN           (0x00U)
#define BDP_CONF_USE_CHECKSUM       (0x01U)

/**
 * BladeDP constants.
 */
#define BDP_TOKEN_PACKET_SIZE       (8U)
#define BDP_PID_SIZE                (1U)
#define BDP_DATA_CHECKSUM_SIZE      (2U)
#define BDP_MEM_OP_UNLOCK_TOKEN     (0x1357FDB9UL)

#ifdef __cplusplus
}
#endif

#endif  /* BDP_DEF_H */
