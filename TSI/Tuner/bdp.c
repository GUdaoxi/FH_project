#include "bdp_def.h"
#include "bdp_conf.h"
#include "bdp.h"

#include <string.h>

/* Private objects */
static BDP_HandleTypeDef BDP_Handle;

/* Private functions */
static void BDP_ResetVariables(void);

/* Callbacks impl */
static void BDP_SetupTokenCallback(BDP_TransferTypeDef *transfer, uint8_t *token);
static void BDP_DataOutCallback(BDP_TransferTypeDef *transfer);
static void BDP_DataInCallback(BDP_TransferTypeDef *transfer);
static void BDP_SetupOutCallback(BDP_TransferTypeDef *transfer);
static void BDP_SetupInCallback(BDP_TransferTypeDef *transfer);

void BDP_Init(const BDP_DevItfTypeDef *itf, const BDP_CallbackTypeDef *cb)
{
    BDP_ASSERT(itf);
    BDP_ASSERT(cb);

    /* Link interface */
    BDP_Handle.itf = itf;

    /* Link callback */
    BDP_Handle.cb = cb;

    /* Init variables */
    BDP_ResetVariables();

    /* Init interface and protocol */
    itf->init();
    cb->init();
}

void BDP_DeInit(void)
{
    /* DeInit interface and protocol */
    BDP_Handle.itf->deinit();
    BDP_Handle.cb->deinit();

    BDP_Handle.itf = NULL;
}

void BDP_Start(void)
{
    BDP_Handle.itf->start();
}

void BDP_Stop(void)
{
    BDP_Handle.itf->stop();
}

void BDP_Handler(void)
{
    BDP_Handle.itf->handler();
}

void BDP_SetValueMapping(BDP_ValueTypeDef *values, uint16_t num)
{
    BDP_Handle.values = values;
    BDP_Handle.valueNum = num;
}

static void BDP_ResetVariables(void)
{
    BDP_Handle.isSelected = 0U;
    BDP_Handle.isMemUnlocked = 0U;
    BDP_Handle.memOpBaseAddr = 0U;
    BDP_Handle.addr = 0U;
    BDP_Handle.dataLen = BDP_MAX_DATA_LEN;
    BDP_Handle.useChecksum = 1U;
}

static void BDP_DataOutCallback(BDP_TransferTypeDef *transfer)
{
    uint8_t errorFlag = 0U;

    BDP_Handle.isSelected = 0U;
    if(transfer->cmd != BDP_CMD_SET_MEM && transfer->cmd != BDP_CMD_SET_MEM_ADDR) {
        /* Lock memory operation */
        BDP_Handle.isMemUnlocked = 0U;
    }

    switch(transfer->cmd) {
        case BDP_CMD_PING:
            /* Do nothing. */
            break;

        case BDP_CMD_SET_REG:
            /*
                DATALEN: (Register number) * 4.
                PARAM: Begin address.
                DATA: (Register number) * (Register data, 32bit).
            */
        {
            uint16_t num = (transfer->dataLen / 4U);
            uint16_t base = (uint16_t)(transfer->cmdParams & 0x0000FFFFUL);
            if(num > 0U) {
                /* Call user handler */
                BDP_ASSERT(BDP_Handle.cb->setRegister);
                if(BDP_Handle.cb->setRegister(base, num, transfer->data) != BDP_PASS) {
                    /* Command execution error */
                    errorFlag = 1U;
                    transfer->ack = BDP_ACK_CMD_EXEC_ERROR;
                    transfer->ackParams = 0x0U;
                    break;
                }
            }
        }
        break;

        case BDP_CMD_SET_MULTI_REG:
            /*
                DATALEN: (Register number) * 6.
                PARAM: Not used.
                DATA: (Register number) * <(Addr, 16bit), (Register data, 32bit)>.
            */
        {
            uint16_t num = (transfer->dataLen / 6U);
            uint16_t addr;
            uint8_t *pData;
            if(num > 0U) {
                /* Call user handler for each register. */
                BDP_ASSERT(BDP_Handle.cb->setRegister);
                pData = transfer->data;
                while(num--) {
                    addr = ((uint16_t)pData[0] << 8U) | pData[1];
                    if(BDP_Handle.cb->setRegister(addr, 1U, &pData[2]) != BDP_PASS) {
                        /* Command execution error */
                        errorFlag = 1U;
                        transfer->ack = BDP_ACK_CMD_EXEC_ERROR;
                        /* Return error address */
                        transfer->ackParams = addr;
                        break;
                    }
                    pData += 6U;
                }
            }
        }
        break;

        case BDP_CMD_SET_VAL:
            /*
                DATALEN: (Value number) * 4.
                PARAM: Begin address.
                DATA: (Value number) * (Value data, 32bit).
            */
        {
            uint16_t num = (transfer->dataLen / 4U);
            uint16_t base = (uint16_t)(transfer->cmdParams & 0x0000FFFFUL);
            if(num > 0U) {
                /* Set value */
                uint16_t addr = base;
                uint8_t *pData = transfer->data;
                BDP_ValueTypeDef *valType;
                uint32_t valueToWrite;
                while(num--) {
                    valType = &BDP_Handle.values[addr];
                    if(addr >= BDP_Handle.valueNum) {
                        /* Command address over maximum address */
                        errorFlag = 1U;
                        transfer->ack = BDP_ACK_CMD_PARAM_ERROR;
                        transfer->ackParams = 0x0U;
                        break;
                    }
                    valueToWrite = ((((uint32_t)pData[0]) << 24U) +
                                    (((uint32_t)pData[1]) << 16U) +
                                    (((uint32_t)pData[2]) << 8U) +
                                    (((uint32_t)pData[3])));
                    switch(valType->type) {
                        case BDP_VALUE_UINT8:
                            *((uint8_t *)valType->addr) = (uint8_t)(valueToWrite & 0xFFUL);
                            break;

                        case BDP_VALUE_UINT16:
                            *((uint16_t *)valType->addr) = (uint16_t)(valueToWrite & 0xFFFFUL);
                            break;

                        case BDP_VALUE_UINT32:
                            *((uint32_t *)valType->addr) = valueToWrite;
                            break;

                        case BDP_VALUE_INT8:
                            *((int8_t *)valType->addr) = (int8_t)(valueToWrite & 0xFFUL);
                            break;

                        case BDP_VALUE_INT16:
                            *((int16_t *)valType->addr) = (int16_t)(valueToWrite & 0xFFFFUL);
                            break;

                        case BDP_VALUE_INT32:
                            *((int32_t *)valType->addr) = (int32_t)valueToWrite;
                            break;

                        case BDP_VALUE_FLOAT: {
                            union {
                                uint32_t v;
                                float r;
                            } conv;
                            conv.v = valueToWrite;
                            *((float *)valType->addr) = conv.r;
                        }
                        break;

                        default:
                            /* Cannot be here. */
                            BDP_ASSERT(0U);
                            break;
                    }

                    /* Goto ext address */
                    addr++;
                    pData += 4U;
                }
            }
        }
        break;

        case BDP_CMD_SET_MULTI_VAL:
            /*
                DATALEN: (Value number) * 6.
                PARAM: Not used.
                DATA: (Value number) * <(Addr, 16bit), (Value data, 32bit)>.
            */
        {
            uint16_t num = (transfer->dataLen / 6U);
            if(num > 0U) {
                uint16_t addr;
                uint8_t *pData = transfer->data;
                BDP_ValueTypeDef *valType;
                uint32_t valueToWrite;
                while(num--) {
                    addr = ((uint16_t)pData[0] << 8U) | pData[1];
                    if(addr >= BDP_Handle.valueNum) {
                        /* Command address over maximum address */
                        errorFlag = 1U;
                        transfer->ack = BDP_ACK_CMD_PARAM_ERROR;
                        /* Return error address */
                        transfer->ackParams = addr;
                        break;
                    }
                    valType = &BDP_Handle.values[addr];
                    valueToWrite = ((((uint32_t)pData[2]) << 24U) +
                                    (((uint32_t)pData[3]) << 16U) +
                                    (((uint32_t)pData[4]) << 8U) +
                                    (((uint32_t)pData[5])));
                    switch(valType->type) {
                        case BDP_VALUE_UINT8:
                            *((uint8_t *)valType->addr) = (uint8_t)(valueToWrite & 0xFFUL);
                            break;

                        case BDP_VALUE_UINT16:
                            *((uint16_t *)valType->addr) = (uint16_t)(valueToWrite & 0xFFFFUL);
                            break;

                        case BDP_VALUE_UINT32:
                            *((uint32_t *)valType->addr) = valueToWrite;
                            break;

                        case BDP_VALUE_INT8:
                            *((int8_t *)valType->addr) = (int8_t)(valueToWrite & 0xFFUL);
                            break;

                        case BDP_VALUE_INT16:
                            *((int16_t *)valType->addr) = (int16_t)(valueToWrite & 0xFFFFUL);
                            break;

                        case BDP_VALUE_INT32:
                            *((int32_t *)valType->addr) = (int32_t)valueToWrite;
                            break;

                        case BDP_VALUE_FLOAT: {
                            union {
                                uint32_t v;
                                float r;
                            } conv;
                            conv.v = valueToWrite;
                            *((float *)valType->addr) = conv.r;
                        }
                        break;

                        default:
                            /* Cannot be here. */
                            BDP_ASSERT(0U);
                            break;
                    }

                    /* Goto next */
                    pData += 6U;
                }
            }
        }
        break;

        case BDP_CMD_SET_MEM_ADDR:
            /*
                DATALEN: 8.
                PARAM: Not used.
                DATA: <(Base addr, 32bit), (Key, 32bit)>
            */
        {
            uint32_t addr, key;
            uint8_t *pData = transfer->data;
            if(transfer->dataLen != 8U) {
                /* Command execution error */
                errorFlag = 1U;
                BDP_Handle.isMemUnlocked = 0U;
                transfer->ack = BDP_ACK_CMD_PARAM_ERROR;
                transfer->ackParams = 0x0U;
                break;
            }
            addr = (((uint32_t)pData[0]) << 24U) +
                   (((uint32_t)pData[1]) << 16U) +
                   (((uint32_t)pData[2]) << 8U) +
                   ((uint32_t)pData[3]);
            key = (((uint32_t)pData[4]) << 24U) +
                  (((uint32_t)pData[5]) << 16U) +
                  (((uint32_t)pData[6]) << 8U) +
                  ((uint32_t)pData[7]);
            if(key != BDP_MEM_OP_UNLOCK_TOKEN) {
                /* Key error */
                errorFlag = 1U;
                BDP_Handle.isMemUnlocked = 0U;
                transfer->ack = BDP_ACK_CMD_PARAM_ERROR;
                transfer->ackParams = 0x1U;
                break;
            }
            BDP_ASSERT(BDP_Handle.cb->isValidMemory);
            if(BDP_Handle.cb->isValidMemory(addr, 1U) != BDP_PASS) {
                /* Address error */
                errorFlag = 1U;
                BDP_Handle.isMemUnlocked = 0U;
                transfer->ack = BDP_ACK_CMD_PARAM_ERROR;
                transfer->ackParams = 0x2U;
                break;
            }
            /* Setup memory operation */
            BDP_Handle.isMemUnlocked = 1U;
            BDP_Handle.memOpBaseAddr = addr;
        }
        break;

        case BDP_CMD_SET_MEM: {
            uint16_t offset = (uint16_t)(transfer->cmdParams & 0x0000FFFFUL);
            if(BDP_Handle.isMemUnlocked == 0U) {
                /* Memory locked */
                errorFlag = 1U;
                transfer->ack = BDP_ACK_CMD_EXEC_ERROR;
                transfer->ackParams = 0x0U;
                break;
            }
            BDP_ASSERT(BDP_Handle.cb->isValidMemory);
            if(BDP_Handle.cb->isValidMemory(BDP_Handle.memOpBaseAddr + offset,
                                            transfer->dataLen) != BDP_PASS) {
                /* Address error */
                errorFlag = 1U;
                transfer->ack = BDP_ACK_CMD_EXEC_ERROR;
                transfer->ackParams = 0x1U;
                break;
            }
            BDP_ASSERT(BDP_Handle.cb->setMemory);
            if(BDP_Handle.cb->setMemory(BDP_Handle.memOpBaseAddr + offset,
                                        transfer->dataLen,
                                        transfer->data) != BDP_PASS) {
                /* Operation error */
                errorFlag = 1U;
                transfer->ack = BDP_ACK_CMD_EXEC_ERROR;
                transfer->ackParams = 0x2U;
                break;
            }
        }
        break;

        default:
            /* Command not supported */
            transfer->ack = BDP_ACK_CMD_NOT_SUPPORTED;
            transfer->ackParams = 0x0U;
            return;
    }

    if(errorFlag == 0U) {
        transfer->ack = BDP_ACK_OK;
        transfer->ackParams = 0x0U;
    }
}

static void BDP_DataInCallback(BDP_TransferTypeDef *transfer)
{
    uint8_t errorFlag = 0U;

    BDP_Handle.isSelected = 0U;
    if(transfer->cmd != BDP_CMD_GET_MEM) {
        /* Lock memory operation */
        BDP_Handle.isMemUnlocked = 0U;
    }

    switch(transfer->cmd) {
        case BDP_CMD_GET_REG:
            /*
                DATALEN: (Register number) * 4.
                PARAM: Begin address.
                DATA: (Register number) * (Register data, 32bit).
            */
        {
            uint16_t num = (transfer->dataLen / 4U);
            uint16_t base = (transfer->cmdParams & 0x0000FFFFUL);
            if(num > 0U) {
                /* Call user handler */
                BDP_ASSERT(BDP_Handle.cb->getRegister);
                if(BDP_Handle.cb->getRegister(base, num, transfer->data) != BDP_PASS) {
                    /* Command execution error */
                    errorFlag = 1U;
                    transfer->ack = BDP_ACK_CMD_EXEC_ERROR;
                    transfer->ackParams = 0x0U;
                }
            }
        }
        break;

        case BDP_CMD_GET_VAL:
            /*
                DATALEN: (Value number) * 4.
                PARAM: Begin address.
                DATA: (Value number) * (Value data, 32bit).
            */
        {
            uint16_t num = (transfer->dataLen / 4U);
            uint16_t base = (uint16_t)(transfer->cmdParams & 0x0000FFFFUL);
            if(num > 0U) {
                uint16_t addr = base;
                uint8_t *pData = transfer->data;
                BDP_ValueTypeDef *valType;
                uint32_t valueToRead;
                while(num--) {
                    valType = &BDP_Handle.values[addr];
                    if(addr >= BDP_Handle.valueNum) {
                        errorFlag = 1U;
                        transfer->ack = BDP_ACK_CMD_EXEC_ERROR;
                        transfer->ackParams = 0x0U;
                        break;
                    }
                    /* Get value */
                    switch(valType->type) {
                        case BDP_VALUE_UINT8:
                            valueToRead = (uint32_t)(*((uint8_t *)valType->addr));
                            break;

                        case BDP_VALUE_UINT16:
                            valueToRead = (uint32_t)(*((uint16_t *)valType->addr));
                            break;

                        case BDP_VALUE_UINT32:
                            valueToRead = (uint32_t)(*((uint32_t *)valType->addr));
                            break;

                        case BDP_VALUE_INT8:
                            valueToRead = (uint32_t)(*((int8_t *)valType->addr));
                            break;

                        case BDP_VALUE_INT16:
                            valueToRead = (uint32_t)(*((int16_t *)valType->addr));
                            break;

                        case BDP_VALUE_INT32:
                            valueToRead = (uint32_t)(*((int32_t *)valType->addr));
                            break;

                        case BDP_VALUE_FLOAT:
                            valueToRead = (uint32_t)(*((float *)valType->addr));
                            break;

                        default:
                            /* Cannot be here. */
                            BDP_ASSERT(0U);
                            break;
                    }
                    /* Copy to buffer */
                    *pData++ = (uint8_t)((valueToRead >> 24U) & 0xFFUL);
                    *pData++ = (uint8_t)((valueToRead >> 16U) & 0xFFUL);
                    *pData++ = (uint8_t)((valueToRead >> 8U) & 0xFFUL);
                    *pData++ = (uint8_t)(valueToRead & 0xFFUL);

                    /* Goto next address */
                    addr++;
                }

            }
        }
        break;

        case BDP_CMD_GET_MEM: {
            uint16_t offset = (uint16_t)(transfer->cmdParams & 0x0000FFFFUL);
            BDP_ASSERT(BDP_Handle.cb->isValidMemory);
            if(BDP_Handle.cb->isValidMemory(BDP_Handle.memOpBaseAddr + offset,
                                            transfer->dataLen) != BDP_PASS) {
                /* Address error */
                errorFlag = 1U;
                transfer->ack = BDP_ACK_CMD_EXEC_ERROR;
                transfer->ackParams = 0x1U;
                break;
            }
            BDP_ASSERT(BDP_Handle.cb->getMemory);
            if(BDP_Handle.cb->getMemory(BDP_Handle.memOpBaseAddr + offset,
                                        transfer->dataLen,
                                        transfer->data) != BDP_PASS) {
                /* Operation error */
                errorFlag = 1U;
                transfer->ack = BDP_ACK_CMD_EXEC_ERROR;
                transfer->ackParams = 0x2U;
                break;
            }
        }
        break;

        default:
            /* Command not supported */
            transfer->ack = BDP_ACK_CMD_NOT_SUPPORTED;
            transfer->ackParams = 0x0U;
            return;
    }

    if(errorFlag == 0U) {
        transfer->ack = BDP_ACK_OK;
        transfer->ackParams = 0x0U;
    }
}

static void BDP_SetupTokenCallback(BDP_TransferTypeDef *transfer, uint8_t *token)
{
    /* Check if is selected, or about to be selected. */
    if(BDP_Handle.isSelected == 0U) {
        if(transfer->cmd == BDP_CMD_SELECT_TARGET) {
            if(transfer->cmdParams == BDP_DEVICE_ID) {
                /* Mark device as selected */
                BDP_Handle.isSelected = 1U;
            }
            else {
                /* Deselected device. */
                BDP_Handle.isSelected = 0U;
                return;
            }
        }
        else {
            return;
        }

    }

    /* Check if is about to be deselected. */
    if(transfer->cmd == BDP_CMD_SELECT_TARGET) {
        if(transfer->cmdParams != BDP_DEVICE_ID) {
            /* Deselected device. */
            BDP_Handle.isSelected = 0U;
            return;
        }
    }

    /* Set data length. */
    if(token[2] == BDP_CMD_RESET_DEVICE) {
        /* BDP_CMD_RESET_DEVICE command has no data. */
        transfer->dataLen = 0U;
        return;
    }
    else {
        /* Standard command has fixed data length. */
        transfer->dataLen = 5U;
    }
}

static void BDP_SetupOutCallback(BDP_TransferTypeDef *transfer)
{
    /* Process command */
    if(transfer->cmd == BDP_CMD_RESET_DEVICE) {
        /* Reset command, abort transfer */
        transfer->abort = 1U;
        /* Reset variables and interface */
        BDP_Handle.itf->reset();
        BDP_ResetVariables();
        return;
    }

    switch(transfer->cmd) {
        case BDP_CMD_SELECT_TARGET:
            /* Already processed. */
            break;

        case BDP_CMD_SET_ADDR: {
            uint8_t addr = (uint8_t)((transfer->cmdParams & 0xFF000000UL) >> 24U);
            if(addr != 0U) {
                BDP_Handle.addr = addr;
            }
            else {
                /* Invalid address */
                transfer->ack = BDP_ACK_CMD_PARAM_ERROR;
                transfer->ackParams = 0x0U;
                return;
            }
        }
        break;

        case BDP_CMD_SET_CONF: {
            uint8_t confId = (uint8_t)((transfer->cmdParams & 0xFF000000U) >> 24U);
            switch(confId) {
                case BDP_CONF_DATA_LEN: {
                    uint16_t len = ((uint16_t)transfer->data[0] << 8U) |
                                   (uint16_t)transfer->data[1];
                    if(len > BDP_MAX_DATA_LEN) {
                        /* Selected length exceed device maximum */
                        transfer->ack = BDP_ACK_CMD_PARAM_ERROR;
                        transfer->ackParams = 0x0U;
                        return;
                    }
                    BDP_Handle.dataLen = len;
                }
                break;

                case BDP_CONF_USE_CHECKSUM: {
                    uint8_t useChkSum = transfer->data[0];
                    if(useChkSum != 0) {
                        BDP_Handle.useChecksum = 1U;
                    }
                    else {
                        BDP_Handle.useChecksum = 0U;
                    }
                }
                break;

                default:
                    /* Command not supported */
                    transfer->ack = BDP_ACK_CMD_NOT_SUPPORTED;
                    transfer->ackParams = 0x0U;
                    return;
            }
        }
        break;

        default:
            /* Command not supported */
            transfer->ack = BDP_ACK_CMD_NOT_SUPPORTED;
            transfer->ackParams = 0x0U;
            return;
    }

    transfer->ack = BDP_ACK_OK;
    transfer->ackParams = 0x0U;
}

static void BDP_SetupInCallback(BDP_TransferTypeDef *transfer)
{
    if(BDP_Handle.isSelected == 0U) {
        /* Not selected, abort transfer */
        transfer->abort = 1U;
        return;
    }

    switch(transfer->cmd) {
        case BDP_CMD_GET_INFO: {
            uint8_t infoId = (uint8_t)((transfer->cmdParams & 0xFF000000U) >> 24U);
            switch(infoId) {
                case BDP_INFO_REV: {
                    transfer->data[0] = BDP_VERSION_MAIN;
                    transfer->data[1] = BDP_VERSION_SUB1;
                    transfer->data[2] = (uint8_t)(((uint16_t)BDP_VERSION_SUB2 & 0xFF00U) >> 8U);
                    transfer->data[3] = (BDP_VERSION_SUB2 & 0xFFU);
                }
                break;

                case BDP_INFO_MAX_DATA_LEN: {
                    transfer->data[0] = (uint8_t)(((uint16_t)BDP_MAX_DATA_LEN & 0xFF00U) >> 8U);
                    transfer->data[1] = (uint8_t)(((uint16_t)BDP_MAX_DATA_LEN & 0xFFU));
                }
                break;

                case BDP_INFO_USE_CHECKSUM: {
                    transfer->data[0] = BDP_Handle.useChecksum;
                }
                break;

                case BDP_INFO_STATUS: {

                }
                break;

                case BDP_INFO_ENDIAN: {
                    transfer->data[0] = BDP_DEVICE_ENDIAN;
                }
                break;

                default:
                    /* Command not supported */
                    transfer->ack = BDP_ACK_CMD_NOT_SUPPORTED;
                    transfer->ackParams = 0x0U;
                    return;
            }
        }
        break;

        default:
            /* Command not supported */
            transfer->ack = BDP_ACK_CMD_NOT_SUPPORTED;
            transfer->ackParams = 0x0U;
            return;
    }

    transfer->ack = BDP_ACK_OK;
    transfer->ackParams = 0x0U;
}

/* Callback instance --------------------------------------------------------*/
const BDP_DevDataCallbackTypeDef BDP_DevDataCallback = {
    &BDP_Handle,
    BDP_DataOutCallback,
    BDP_DataInCallback,
    BDP_SetupTokenCallback,
    BDP_SetupOutCallback,
    BDP_SetupInCallback,
};
