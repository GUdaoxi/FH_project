#ifndef BDP_H
#define BDP_H

#include "bdp_def.h"
#include "bdp_conf.h"

/** BDP Library version number. */
#define BDP_VERSION_MAIN            (0x01U)     /*!< [31:24] main version */
#define BDP_VERSION_SUB1            (0x00U)     /*!< [23:16] sub1 version */
#define BDP_VERSION_SUB2            (0x00U)     /*!< [15:0]  sub2 version */
#define BDP_VERSION                 ((BDP_VERSION_MAIN  << 24U)\
                                         |(BDP_VERSION_SUB1 << 16U)\
                                         |(BDP_VERSION_SUB2))

#ifdef __cplusplus
extern "C" {
#endif

/* Defines ------------------------------------------------------------------*/
typedef enum _BDP_ValueType {
    BDP_VALUE_UINT8,
    BDP_VALUE_UINT16,
    BDP_VALUE_UINT32,
    BDP_VALUE_INT8,
    BDP_VALUE_INT16,
    BDP_VALUE_INT32,
    BDP_VALUE_FLOAT,

} BDP_ValueTypeEnum;

typedef enum _BDP_MemRegionType {
    BDP_MEMORY_RO,
    BDP_MEMORY_RW,

} BDP_MemRegionTypeEnum;

typedef struct _BDP_Handle BDP_HandleTypeDef;
typedef struct _BDP_Callback BDP_CallbackTypeDef;
typedef struct _BDP_DevItf BDP_DevItfTypeDef;
typedef struct _BDP_DevDataCallback BDP_DevDataCallbackTypeDef;
typedef struct _BDP_Transfer BDP_TransferTypeDef;
typedef struct _BDP_Value BDP_ValueTypeDef;
typedef struct _BDP_MemRegion BDP_MemRegionTypeDef;

struct _BDP_Handle {
    /* Objects ----------------------*/
    /** Device mode interface */
    const BDP_DevItfTypeDef *itf;

    /** User callback */
    const BDP_CallbackTypeDef *cb;

    /** User values */
    BDP_ValueTypeDef *values;

    /** User value num. */
    uint16_t valueNum;

    /* Variables --------------------*/
    /* Device address */
    uint8_t addr;

    /* Is device selected by host in setup transfer */
    uint8_t isSelected;

    /* Is device memory operation unlocked. */
    uint8_t isMemUnlocked;

    /* Memory operation base address. */
    uint32_t memOpBaseAddr;

    /* Device data length */
    uint16_t dataLen;

    /* Transfer need checksum */
    uint8_t useChecksum;

};

struct _BDP_Callback {
    void (*init)(void);
    void (*deinit)(void);
    BDP_RetCode(*setRegister)(uint16_t addr, uint16_t num, uint8_t *data);
    BDP_RetCode(*getRegister)(uint16_t addr, uint16_t num, uint8_t *data);
    BDP_RetCode(*isValidMemory)(uint32_t addr, uint16_t size);
    BDP_RetCode(*setMemory)(uint32_t addr, uint16_t size, uint8_t *data);
    BDP_RetCode(*getMemory)(uint32_t addr, uint16_t size, uint8_t *data);
};

struct _BDP_DevItf {
    /** Init BladeDP device mode interface. */
    void (*init)(void);

    /** DeInit BladeDP device mode interface. */
    void (*deinit)(void);

    /** Reset BladeDP device mode interface. */
    void (*reset)(void);

    /** Start BladeDP device mode interface. */
    void (*start)(void);

    /** Stop BladeDP device mode interface. */
    void (*stop)(void);

    /** Device mode interface handler. */
    void (*handler)(void);
};

struct _BDP_DevDataCallback {
    /** Context */
    BDP_HandleTypeDef *handle;
    
    /** Host out data processing callback */
    void (*dataOutCallback)(BDP_TransferTypeDef *transfer);

    /** Host in data processing callback */
    void (*dataInCallback)(BDP_TransferTypeDef *transfer);

    /** Host out setup token processing callback */
    void (*setupTokenCallback)(BDP_TransferTypeDef *transfer, uint8_t *token);

    /** Host out setup processing callback */
    void (*setupOutCallback)(BDP_TransferTypeDef *transfer);

    /** Host in setup processing callback */
    void (*setupInCallback)(BDP_TransferTypeDef *transfer);
};

struct _BDP_Transfer {
    /** Device address */
    uint8_t addr;

    /** Command */
    uint8_t cmd;

    /** Command params */
    uint32_t cmdParams;

    /** Data */
    uint8_t *data;

    /** Data length */
    uint16_t dataLen;

    /** Total data packet length */
    uint16_t xferLen;

    /** ACK */
    uint8_t ack;

    /** ACK params */
    uint16_t ackParams;

    /** Interface abort flag. If set, interface
     *  will abort current transfer. Only applicable
     *  to Setup IN / IN transfer. */
    uint8_t abort;

    /** Interface skip flag. If set, interface
     *  will skip current transfer. */
    uint8_t skip;

};

struct _BDP_Value {
    /** Value storage address */
    void *addr;

    /** Value type */
    BDP_ValueTypeEnum type;
};

struct _BDP_MemRegion {
    /** Memory region address */
    uint32_t base;

    /** Memory region size */
    uint32_t size;

    /** Memory region rule */
    BDP_MemRegionTypeEnum type;
};

/* Exported objects ---------------------------------------------------------*/
extern const BDP_DevDataCallbackTypeDef BDP_DevDataCallback;
extern const BDP_CallbackTypeDef BDP_Callback;

/* Defines ------------------------------------------------------------------*/
void BDP_Init(const BDP_DevItfTypeDef *itf, const BDP_CallbackTypeDef *cb);
void BDP_DeInit(void);
void BDP_Start(void);
void BDP_Stop(void);
void BDP_Handler(void);
void BDP_SetValueMapping(BDP_ValueTypeDef *values, uint16_t num);

#ifdef __cplusplus
}
#endif

#endif  /* BDP_H */
