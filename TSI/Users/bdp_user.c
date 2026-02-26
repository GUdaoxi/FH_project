#include "bdp.h"
#include "bdp_user.h"
#include "fm33fh0xx.h"

/* Definitions --------------------------------------------------------------*/
#define TSI_BDP_REG_LIB_ID      (0UL)
#define TSI_BDP_REG_CMD_CODE    (1UL)
#define TSI_BDP_REG_CMD_STAT    (2UL)
#define TSI_BDP_REG_CMD_RESULT  (3UL)
#define TSI_BDP_REG_CMD_EXDATA  (4UL)
#define TSI_BDP_REG_LIB_STAT    (5UL)
#define TSI_BDP_REG_DRV_STAT    (6UL)
#define TSI_BDP_REG_TSI_BEGIN   (16UL)
#define TSI_BDP_REG_TSI_END     (255UL)

/* Private function definitions --------------------------------------------*/
static BDP_RetCode SetRegister(uint16_t addr, uint32_t *value);
static BDP_RetCode GetRegister(uint16_t addr, uint32_t *value);

/* Variables ----------------------------------------------------------------*/
static TSI_LibHandleTypeDef *pLib;

/* Callback implementations -------------------------------------------------*/
static void BDP_UserInit(void)
{
    pLib = &TSI_LibHandle;
    BDP_SetValueMapping((BDP_ValueTypeDef *)BDP_TSIValueList, BDP_VALUE_NUM);
}

static void BDP_UserDeinit(void)
{
    /* Do nothing. */
}

static BDP_RetCode BDP_UserSetRegister(uint16_t addr, uint16_t num, uint8_t *data)
{
    uint32_t tmp;
    int i;
    for(i = 0; i < num; i++) {
        tmp = (((uint32_t)data[4 * i]) << 24U) +
              (((uint32_t)data[4 * i + 1]) << 16U) +
              (((uint32_t)data[4 * i + 2]) << 8U) +
              ((uint32_t)data[4 * i + 3]);
        if(SetRegister(addr + i, &tmp) != BDP_PASS) {
            return BDP_ERROR;
        }
    }

    return BDP_PASS;
}

static BDP_RetCode BDP_UserGetRegister(uint16_t addr, uint16_t num, uint8_t *data)
{
    int i;
    for(i = 0; i < num; i++) {
        uint32_t tmp = 0UL;
        if(GetRegister(addr + i, &tmp) != BDP_PASS) {
            return BDP_ERROR;
        }
        data[4 * i] = (uint8_t)(tmp >> 24U);
        data[4 * i + 1] = (uint8_t)(tmp >> 16U);
        data[4 * i + 2] = (uint8_t)(tmp >> 8U);
        data[4 * i + 3] = (uint8_t)(tmp);
    }
    return BDP_PASS;
}

static BDP_RetCode BDP_IsValidMemory(uint32_t addr, uint16_t size)
{
    BDP_RetCode res = BDP_ERROR;
    int i;
    for(i = 0; i < BDP_MEM_AREA_NUM; i++) {
        if((addr >= BDP_MemRegionList[i].base) &&
                ((addr + size) <= BDP_MemRegionList[i].base + BDP_MemRegionList[i].size)) {
            res = BDP_PASS;
            break;
        }
    }
    return res;
}

static BDP_RetCode BDP_SetMemory(uint32_t addr, uint16_t size, uint8_t *data)
{
    BDP_RetCode res = BDP_ERROR;
    int i;
    for(i = 0; i < BDP_MEM_AREA_NUM; i++) {
        if((addr >= BDP_MemRegionList[i].base) &&
                ((addr + size) <= BDP_MemRegionList[i].base + BDP_MemRegionList[i].size)) {
            if(BDP_MemRegionList[i].type != BDP_MEMORY_RW) {
                break;
            }
            memcpy((void *)addr, (const void *)data, size);
            res = BDP_PASS;
            break;
        }
    }
    return res;
}

static BDP_RetCode BDP_GetMemory(uint32_t addr, uint16_t size, uint8_t *data)
{
    BDP_RetCode res = BDP_ERROR;
    int i;
    for(i = 0; i < BDP_MEM_AREA_NUM; i++) {
        if((addr >= BDP_MemRegionList[i].base) &&
                ((addr + size) <= BDP_MemRegionList[i].base + BDP_MemRegionList[i].size)) {
            memcpy((void *)data, (const void *)addr, size);
            res = BDP_PASS;
            break;
        }
    }
    return res;
}

static BDP_RetCode SetRegister(uint16_t addr, uint32_t *value)
{
    if(addr >= TSI_BDP_REG_TSI_BEGIN && addr <= TSI_BDP_REG_TSI_END) {
        /* Ensure TSI bus clock is enabled */
        CMU->PCLKCR2 |= (0x1UL << 11U);
        /* TSI Register mapping */
        ((uint32_t *)TSI)[addr - TSI_BDP_REG_TSI_BEGIN] = *value;
    }
    else {

        switch(addr) {
            case TSI_BDP_REG_LIB_ID:
                if(*value != 0U) { return BDP_ERROR; }
                pLib = &TSI_LibHandle;
                break;

            case TSI_BDP_REG_CMD_CODE:
                pLib->command.map.cmdCode = (uint8_t)(((*value) & (0x3FUL << 24U)) >> 24U);
                pLib->command.map.param0Hi = (uint8_t)(((*value) & (0xFFUL << 16U)) >> 16U);
                pLib->command.map.param0Lo = (uint8_t)(((*value) & (0xFFUL << 8U)) >> 8U);
                pLib->command.map.param1 = (uint8_t)((*value) & (0xFFUL));
                break;

            case TSI_BDP_REG_CMD_STAT:
                pLib->command.map.execStat = (uint8_t)((*value) & (0x3UL));
                break;

            default:
                /* Unsupported operation. */
                return BDP_ERROR;
        }
    }

    return BDP_PASS;
}

static BDP_RetCode GetRegister(uint16_t addr, uint32_t *value)
{
    if(addr >= TSI_BDP_REG_TSI_BEGIN && addr <= TSI_BDP_REG_TSI_END) {
        /* Ensure TSI bus clock is enabled */
        CMU->PCLKCR2 |= (0x1UL << 11U);
        /* TSI Register mapping */
        *value = ((uint32_t *)TSI)[addr - TSI_BDP_REG_TSI_BEGIN];
    }
    else {
        switch(addr) {
            case TSI_BDP_REG_LIB_ID:
                /* Only one instance. */
                *value = 0UL;
                break;

            case TSI_BDP_REG_CMD_CODE:
                *value = (((uint32_t)pLib->command.map.cmdCode) << 24U) +
                         (((uint32_t)pLib->command.map.param0Hi) << 16U) +
                         (((uint32_t)pLib->command.map.param0Lo) << 8U) +
                         ((uint32_t)pLib->command.map.param1);
                break;

            case TSI_BDP_REG_CMD_STAT:
                *value = pLib->command.map.execStat;
                break;

            case TSI_BDP_REG_CMD_RESULT:
                *value = pLib->command.map.result;
                break;

            case TSI_BDP_REG_CMD_EXDATA:
                *value = (((uint32_t)pLib->command.map.exData[0]) << 24U) +
                         (((uint32_t)pLib->command.map.exData[1]) << 16U) +
                         (((uint32_t)pLib->command.map.exData[2]) << 8U) +
                         ((uint32_t)pLib->command.map.exData[3]);
                break;

            case TSI_BDP_REG_LIB_STAT:
                *value = pLib->status;
                break;

            case TSI_BDP_REG_DRV_STAT:
                *value = pLib->driver->status;
                break;

            default:
                /* Unsupported operation. */
                return BDP_ERROR;
        }
    }

    return BDP_PASS;
}

/* Callback instance --------------------------------------------------------*/
const BDP_CallbackTypeDef BDP_Callback = {
    BDP_UserInit,
    BDP_UserDeinit,
    BDP_UserSetRegister,
    BDP_UserGetRegister,
    BDP_IsValidMemory,
    BDP_SetMemory,
    BDP_GetMemory,
};

