#ifndef TSI_DRIVER_H
#define TSI_DRIVER_H

#include "tsi_conf.h"
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* Macros -------------------------------------------------------------------*/
#define TSI_SCAN_GROUP_SELF_CAP             (0U)
#define TSI_SCAN_GROUP_SELF_CAP_PARALLEL    (1U)
#define TSI_SCAN_GROUP_MUTUAL_CAP           (2U)

/* Defines ------------------------------------------------------------------*/
/* Forward declarations */
struct _TSI_Widget;
struct _TSI_Sensor;
typedef struct _TSI_IOConf TSI_IOConfTypeDef;
typedef struct _TSI_ClockConf TSI_ClockConfTypeDef;
typedef struct _TSI_ShieldConf TSI_ShieldConfTypeDef;
typedef struct _TSI_ScanGroup TSI_ScanGroupTypeDef;
typedef struct _TSI_Driver TSI_DriverTypeDef;

/** Driver scan mode. */
typedef enum _TSI_DrvScanMode {
    /** Caller will be blocked until the scan completed. Can only be used in single scan. */
    TSI_DRV_SCAN_MODE_BLOCKING,
    /** Scan using interrupt. */
    TSI_DRV_SCAN_MODE_IT,
    /** Scan using DMA. */
    TSI_DRV_SCAN_MODE_DMA,
} TSI_DrvScanMode;

/**
 * A group of sensors which will be scan during one scan process. self-cap sensors
 * usally share one group, while mutual-cap sensors of each widget should have their
 * own group.
 *
 * .. hint:: If several self-cap sensors need to scan in parallel, they shall form an
 *           individual group, and set the type to 1 (self-cap parallel scan group).
 */
struct _TSI_ScanGroup {
    /** Group size. */
    uint16_t size;

    /**
     * Group type.
     *
     * * 0: Self-cap scan group.
     * * 1: Self-cap parallel scan group.
     * * 2: Mutual-cap scan group.
     */
    uint8_t type;

    /**
     * Device-specified scan options. See device header file for available options.
     */
    uint32_t opt;

    /**
     * Sensor id list.
     *
     * .. important:: Sensors MUST be listed in the same order as they are scanned. If
     *                not, sensor rawcounts will be misplaced.
     */
    uint16_t *sensors;
};

/** Abstract hardware driver struct. */
struct _TSI_Driver {
    /** TSI instance. Mapping device peripherals to their drivers. */
    uint32_t instanceId;

    /**
     * Device driver context. Only used by device driver. Set to NULL
     * if useless.
     */
    void *context;

    /* Config -----------------------*/
    /** Clock list. */
    TSI_ClockConfTypeDef *clocks;

    /** IO list. Specified its size using :c:member:`ioNum`. */
    TSI_IOConfTypeDef *ios;

    /** IO list size. */
    uint16_t ioNum;

#if (TSI_USE_SHIELD != 0U)
    /**
     * Shield electrode group list. Selected shield(s) will be enabled
     * during self-cap scan and self-cap paralleld scan. Specified its
     * size using :c:member:`shieldNum`.
     */
    TSI_ShieldConfTypeDef *shields;

    /** Shield electrode list size. */
    uint8_t shieldNum;
#endif

    /** Scan group list. */
    TSI_ScanGroupTypeDef *scanGroups;

    /** Scan group list size. */
    uint8_t scanGroupNum;

    /** Sensor list. */
    struct _TSI_Sensor **sensors;

    /** Sensor list size. */
    uint8_t sensorNum;

    /* Operation state --------------*/
    /** Scan mode. */
    TSI_DrvScanMode scanMode;

    /** Single scan flag (1: true, 0: false). */
    uint8_t single;

    /**
     * Force setup group re-configure flag (1: true, 0: false).
     * Used by driver when it needs to update scan group configurations
     * when scan group remains unchanged, or the driver will never update.
     * This flag is auto-clear.
     */
    uint8_t forceReConf;

    /* Internals --------------------*/
    /** Current scan group index. */
    uint8_t scanGroupIdx;

    /** Last scan group index. */
    uint8_t oldScanGroupIdx;

    /** Current scan freq index. */
    uint8_t freqIdx;

    /**
     * Internal Status flags.
     *
     * * bit 4 is scan empty flag (1: true, nothing to scan, 0: false),
     * * bit 3 is scan error flag (1: true, 0: false),
     * * bit 2 is scan overrun flag (1: true, 0: false),
     * * bit 1 is scan running flag (1: true, 0: false),
     * * bit 0 is scan completed flag (1: true, 0: false).
     */
    volatile uint32_t status;
};

/** Scan empty flag mask. */
#define TSI_DRV_STAT_SCAN_EMPTY                 (0x1UL << 4U)
/** Scan error flag mask. */
#define TSI_DRV_STAT_SCAN_ERROR                 (0x1UL << 3U)
/** Scan overrun flag mask. */
#define TSI_DRV_STAT_SCAN_OVERRUN               (0x1UL << 2U)
/** Scan running flag mask. */
#define TSI_DRV_STAT_SCAN_RUNNING               (0x1UL << 1U)
/** Scan completed flag mask. */
#define TSI_DRV_STAT_SCAN_CPLT                  (0x1UL << 0U)

/** Get driver scan status flag. */
#define TSI_DRV_GET_STAT(DRV, STAT)             ((DRV)->status & (STAT))
/** Set driver scan status flag. */
#define TSI_DRV_SET_STAT(DRV, STAT)             ((DRV)->status |= (STAT))
/** Clear driver scan status flag. */
#define TSI_DRV_CLR_STAT(DRV, STAT)             ((DRV)->status &= ~(STAT))

/* Driver APIs declaration -----------------------------------------------------*/
/* Driver operation APIs */
TSI_RetCode TSI_Drv_Init(TSI_DriverTypeDef *drv);
TSI_RetCode TSI_Drv_DeInit(TSI_DriverTypeDef *drv);
TSI_RetCode TSI_Drv_StartScan(TSI_DriverTypeDef *drv, TSI_DrvScanMode mode, uint8_t oneShot);
TSI_RetCode TSI_Drv_StopScan(TSI_DriverTypeDef *drv);

/* Widget control APIs */
TSI_RetCode TSI_Drv_EnableWidget(TSI_DriverTypeDef *drv, struct _TSI_Widget *widget);
TSI_RetCode TSI_Drv_DisableWidget(TSI_DriverTypeDef *drv, struct _TSI_Widget *widget);

/* TSI driver event handlers */
void TSI_Drv_HandleSensorData(TSI_DriverTypeDef *drv, struct _TSI_Sensor *sensor, uint32_t data);
void TSI_Drv_HandleEndOfScan(TSI_DriverTypeDef *drv);

/* Device driver APIs declaration -------------------------------------------*/
/* Initialzation APIs */
TSI_RetCode TSI_Dev_Init(TSI_DriverTypeDef *drv);
TSI_RetCode TSI_Dev_Deinit(TSI_DriverTypeDef *drv);
#if (TSI_USED_IN_LPM_MODE == 1U)
void TSI_Dev_EnterLPM(TSI_DriverTypeDef *drv);
void TSI_Dev_LeaveLPM(TSI_DriverTypeDef *drv);
#endif  /* TSI_USED_IN_LPM_MODE == 1U */

/* Setup APIs */
TSI_RetCode TSI_Dev_SetupClock(TSI_DriverTypeDef *drv, const TSI_ClockConfTypeDef *clock);
TSI_RetCode TSI_Dev_ResetClock(TSI_DriverTypeDef *drv);
TSI_RetCode TSI_Dev_SetupPort(TSI_DriverTypeDef *drv, const TSI_IOConfTypeDef *io);
TSI_RetCode TSI_Dev_ResetPort(TSI_DriverTypeDef *drv, const TSI_IOConfTypeDef *io);
#if (TSI_USE_SHIELD == 1U)
TSI_RetCode TSI_Dev_SetupShield(TSI_DriverTypeDef *drv, const TSI_ShieldConfTypeDef *shield);
TSI_RetCode TSI_Dev_ResetShield(TSI_DriverTypeDef *drv, const TSI_ShieldConfTypeDef *shield);
TSI_RetCode TSI_Dev_ResetAllShields(TSI_DriverTypeDef *drv);
#endif

/* Control APIs */
TSI_RetCode TSI_Dev_SetupScanGroup(TSI_DriverTypeDef *drv, TSI_ScanGroupTypeDef *group);
TSI_RetCode TSI_Dev_StartScan(TSI_DriverTypeDef *drv);
TSI_RetCode TSI_Dev_StopScan(TSI_DriverTypeDef *drv);

/* Interrupt APIs */
void TSI_Dev_Handler(TSI_DriverTypeDef *drv);

/* Calibration APIs */
uint32_t TSI_Dev_GetModClock(TSI_ClockConfTypeDef *clock);
uint32_t TSI_Dev_GetSCSnsInputClock(TSI_ClockConfTypeDef *clock);
uint32_t TSI_Dev_GetMCSnsInputClock(TSI_ClockConfTypeDef *clock);
uint32_t TSI_Dev_GetSCSwitchClock(TSI_ClockConfTypeDef *clock, uint32_t snsDiv);
uint32_t TSI_Dev_GetMCTXClock(TSI_ClockConfTypeDef *clock, uint32_t snsDiv);
void TSI_Dev_SetupDirectClock(TSI_ClockConfTypeDef *clock);
void TSI_Dev_SetupPRSClock(TSI_ClockConfTypeDef *clock, uint8_t width, uint16_t coeff);
void TSI_Dev_SetupSSCClock(TSI_ClockConfTypeDef *clock, uint8_t width, uint8_t point, uint16_t coeff);

/* Device-specified transform APIs */
uint32_t TSI_Dev_GetSCConvCycleNum(uint32_t resolution);
uint32_t TSI_Dev_GetMCConvCycleNum(TSI_ClockConfTypeDef *clock, uint32_t resolution, uint32_t snsDiv);

/* System APIs */
void TSI_Dev_ClearWDT(void);

/* Device includes ----------------------------------------------------------*/
#ifndef TSI_SIM_DEV
/* Real hardware platform */
#if defined(FM33FH0XX)
#include "Devices/fm33fh0xx_tsi_def.h"
#elif defined(FM33HT0XXA)
#include "Devices/fm33ht0xxa_tsi_def.h"
#else
#error "Device not supported."
#endif
#else
/* Simulation platform. */
#if defined(FM33FH0XX)
#include "fm33fh0xx_sim_tsi_def.h"
#elif defined(FM33HT0XXA)
#include "fm33ht0xxa_sim_tsi_def.h"
#else
#include "general_sim_tsi_def.h"
#endif
#endif

/* Device constants ---------------------------------------------------------*/
/* IDAC current table */
static const uint32_t TSI_Dev_IDACCurrentTable[TSI_DEV_IDAC_STEP_NUM] = \
        TSI_DEV_IDAC_CURRENT_TABLE;

#ifdef __cplusplus
}
#endif

#endif /* TSI_DRIVER_H */
