#ifndef FM33FH0XX_TSI_DEF_H
#define FM33FH0XX_TSI_DEF_H

#include <string.h>
#include <stdint.h>
#include <stdbool.h>

/* Device-specified value definitions ---------------------------------------*/
#define TSI_DEV_IDAC_STEP_37P5NA                (0U)
#define TSI_DEV_IDAC_STEP_75NA                  (1U)
#define TSI_DEV_IDAC_STEP_300NA                 (2U)
#define TSI_DEV_IDAC_STEP_600NA                 (3U)
#define TSI_DEV_IDAC_STEP_1P2UA                 (4U)
#define TSI_DEV_IDAC_STEP_2P4UA                 (5U)
#define TSI_DEV_IDAC_STEP_4P8UA                 (6U)

/* Device-specified option definitions --------------------------------------*/
/**
 * Bit[1:0]: Idle channel connection.
 * * TSI_DEV_OPT_IDLE_FLOATING: Idle channels are floating (default).
 * * TSI_DEV_OPT_IDLE_GROUNDED: Idle channels connect to GND.
 * * TSI_DEV_OPT_IDLE_SHIELD: If shield is enabled, idle channels are connected to shield;
 *   Otherwise, they are floating.
 */
#define TSI_DEV_OPT_IDLE_CONNECTION_MASK        (0x3UL << 0U)
#define TSI_DEV_OPT_IDLE_FLOATING               (0x0UL << 0U)
#define TSI_DEV_OPT_IDLE_GROUNDED               (0x1UL << 0U)
#define TSI_DEV_OPT_IDLE_SHIELD                 (0x2UL << 0U)

/* Device resources and capabilities ----------------------------------------*/
#define TSI_DEV_INSTANCE_NUM                    (1U)

/* Device total channel num */
#define TSI_DEV_CHANNEL_NUM                     (36U)

/* Device IDAC step and current info */
#define TSI_DEV_IDAC_STEP_NUM                   (7U)
#define TSI_DEV_IDAC_CURRENT_TABLE              \
{                                               \
    /* <Current(pA)> */                         \
    37500U,     /* TSI_DEV_IDAC_STEP_37P5NA */  \
    75000U,     /* TSI_DEV_IDAC_STEP_75NA */    \
    300000U,    /* TSI_DEV_IDAC_STEP_300NA */   \
    600000U,    /* TSI_DEV_IDAC_STEP_600NA */   \
    1200000U,   /* TSI_DEV_IDAC_STEP_1P2UA */   \
    2400000U,   /* TSI_DEV_IDAC_STEP_2P4UA */   \
    4800000U,   /* TSI_DEV_IDAC_STEP_4P8UA */   \
}

/* Device support DMA */
#define TSI_DEV_SUPPORT_DMA                     (1U)

/* Device support Multi-Freq scan */
#define TSI_DEV_SUPPORT_MULTI_FREQ_SCAN         (1U)

/* Device calibration configuration */
#define TSI_DEV_SUPPORT_SC_CALIB_HW_PARAM       (1U)
#define TSI_DEV_SUPPORT_SC_CALIB_BOTH_IDAC      (1U)
#define TSI_DEV_SUPPORT_SC_CALIB_COMP_IDAC      (1U)
#define TSI_DEV_SUPPORT_MC_CALIB_IDAC           (1U)
#define TSI_DEV_MAX_SNS_CLK_FREQ_HZ             (6000000U)
#define TSI_DEV_MAX_SNS_CLK_DIV                 (4096U)
#define TSI_DEV_MIN_SNS_CLK_DIV                 (2U)
#define TSI_DEV_SC_CALIB_DEFAULT_IDAC_STEP_IDX  (0U)
#define TSI_DEV_IDAC_BITWIDTH                   (7U)

/* Defines ------------------------------------------------------------------*/
/**
 *  Struct for representing FM33FH0xx TSI GPIO configuration.
 */
struct _TSI_IOConf {
    /** GPIO port ID. */
    uint8_t port;

    /** GPIO pin ID. */
    uint8_t pin;

    /** GPIO channel ID. */
    uint8_t channel;
};

/**
 *  Struct for representing FM33FH0xx TSI clock configuration.
 */
struct _TSI_ClockConf {
    /**
     * TSI operation clock selection.
     *
     * * 0: APBCLK.
     * * 1: RCHF.
     */
    uint32_t opClockSel : 1;

    /**
     * Sensor clock source selection.
     *
     * * 0: modulator clock.
     * * 1: PLL_TSI VCO clock.
     */
    uint32_t snsClockSrc : 1;

    /**
     * Sensor clock selection.
     *
     * * 0: direct clock.
     * * 1: PRS-modulated clock (Not available in mutual-cap mode).
     * * 2: SSC-modulated clock.
     */
    uint32_t snsClockSel : 2;

    /** PRS polynomial width. */
    uint32_t prsWidth : 4;

    /** SSC polynomial width. */
    uint32_t sscWidth : 4;

    /**
     * SSC frequency point number.
     *
     * * 0: 32 points.
     * * 1: 64 points.
     * * 2: 128 points.
     * * 3: 256 points.
     */
    uint32_t sscPoint : 2;

    /* Reserved */
    uint32_t reserved : 18;

    /** Modulator clock prescaler. */
    uint16_t modClockPsc;

    /** PRS polynomial coefficient. */
    uint32_t prsCoeff : 12;

    /** SSC polynomial coefficient. */
    uint32_t sscCoeff : 12;

    /* Reserved */
    uint32_t reserved2 : 8;

    /** PLL_TSI reference prescaler. */
    uint8_t pllRefPsc;

    /** PLL_TSI multiplier. */
    uint16_t pllMul;
};

/**
 *  Struct for representing FM33FH0xx shield configuration.
 */
struct _TSI_ShieldConf {
    /** Shield channel. */
    uint8_t channel;
};

#endif  /* FM33FH0XX_TSI_DEF_H */
