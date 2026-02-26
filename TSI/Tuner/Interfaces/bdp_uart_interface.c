#include "bdp_uart_interface.h"
#include "bdp_uart_interface_io.h"
#include "bdp.h"

#include <string.h>

/* Macros -------------------------------------------------------------------*/
/* Device mode states */
#define BDP_STAT_WAIT_TOKEN         (0U)
#define BDP_STAT_OUT_DEV_RDY_ACK    (1U)
#define BDP_STAT_OUT_RECV           (2U)
#define BDP_STAT_OUT_DEV_CPLT_ACK   (3U)
#define BDP_STAT_IN_SEND            (4U)
#define BDP_STAT_IN_DEV_ACK         (5U)
#define BDP_STAT_PROCESSING         (6U)

/* Tranfer type */
#define BDP_OUT_TRANSFER            (1U)
#define BDP_IN_TRANSFER             (2U)

/* Unexpected data error handling */
#define BDP_MAX_ERR_CNT             (3U)

/* Defines ------------------------------------------------------------------*/
/* Device buffer */
static uint8_t tokenBuffer[BDP_TOKEN_PACKET_SIZE];
static uint8_t ackBuffer[BDP_TOKEN_PACKET_SIZE];
static uint8_t dataBuffer[BDP_MAX_DATA_LEN +
                          BDP_PID_SIZE +
                          BDP_DATA_CHECKSUM_SIZE];

/* Device variables */
static uint8_t stat;
static uint8_t transferType;
static BDP_TransferTypeDef transfer;
static uint8_t errCnt;

/* CRC8 table */
static const uint8_t crc8Table[256] = {
    0x00U, 0x07U, 0x0EU, 0x09U, 0x1CU, 0x1BU, 0x12U, 0x15U, 0x38U, 0x3FU,
    0x36U, 0x31U, 0x24U, 0x23U, 0x2AU, 0x2DU, 0x70U, 0x77U, 0x7EU, 0x79U,
    0x6CU, 0x6BU, 0x62U, 0x65U, 0x48U, 0x4FU, 0x46U, 0x41U, 0x54U, 0x53U,
    0x5AU, 0x5DU, 0xE0U, 0xE7U, 0xEEU, 0xE9U, 0xFCU, 0xFBU, 0xF2U, 0xF5U,
    0xD8U, 0xDFU, 0xD6U, 0xD1U, 0xC4U, 0xC3U, 0xCAU, 0xCDU, 0x90U, 0x97U,
    0x9EU, 0x99U, 0x8CU, 0x8BU, 0x82U, 0x85U, 0xA8U, 0xAFU, 0xA6U, 0xA1U,
    0xB4U, 0xB3U, 0xBAU, 0xBDU, 0xC7U, 0xC0U, 0xC9U, 0xCEU, 0xDBU, 0xDCU,
    0xD5U, 0xD2U, 0xFFU, 0xF8U, 0xF1U, 0xF6U, 0xE3U, 0xE4U, 0xEDU, 0xEAU,
    0xB7U, 0xB0U, 0xB9U, 0xBEU, 0xABU, 0xACU, 0xA5U, 0xA2U, 0x8FU, 0x88U,
    0x81U, 0x86U, 0x93U, 0x94U, 0x9DU, 0x9AU, 0x27U, 0x20U, 0x29U, 0x2EU,
    0x3BU, 0x3CU, 0x35U, 0x32U, 0x1FU, 0x18U, 0x11U, 0x16U, 0x03U, 0x04U,
    0x0DU, 0x0AU, 0x57U, 0x50U, 0x59U, 0x5EU, 0x4BU, 0x4CU, 0x45U, 0x42U,
    0x6FU, 0x68U, 0x61U, 0x66U, 0x73U, 0x74U, 0x7DU, 0x7AU, 0x89U, 0x8EU,
    0x87U, 0x80U, 0x95U, 0x92U, 0x9BU, 0x9CU, 0xB1U, 0xB6U, 0xBFU, 0xB8U,
    0xADU, 0xAAU, 0xA3U, 0xA4U, 0xF9U, 0xFEU, 0xF7U, 0xF0U, 0xE5U, 0xE2U,
    0xEBU, 0xECU, 0xC1U, 0xC6U, 0xCFU, 0xC8U, 0xDDU, 0xDAU, 0xD3U, 0xD4U,
    0x69U, 0x6EU, 0x67U, 0x60U, 0x75U, 0x72U, 0x7BU, 0x7CU, 0x51U, 0x56U,
    0x5FU, 0x58U, 0x4DU, 0x4AU, 0x43U, 0x44U, 0x19U, 0x1EU, 0x17U, 0x10U,
    0x05U, 0x02U, 0x0BU, 0x0CU, 0x21U, 0x26U, 0x2FU, 0x28U, 0x3DU, 0x3AU,
    0x33U, 0x34U, 0x4EU, 0x49U, 0x40U, 0x47U, 0x52U, 0x55U, 0x5CU, 0x5BU,
    0x76U, 0x71U, 0x78U, 0x7FU, 0x6AU, 0x6DU, 0x64U, 0x63U, 0x3EU, 0x39U,
    0x30U, 0x37U, 0x22U, 0x25U, 0x2CU, 0x2BU, 0x06U, 0x01U, 0x08U, 0x0FU,
    0x1AU, 0x1DU, 0x14U, 0x13U, 0xAEU, 0xA9U, 0xA0U, 0xA7U, 0xB2U, 0xB5U,
    0xBCU, 0xBBU, 0x96U, 0x91U, 0x98U, 0x9FU, 0x8AU, 0x8DU, 0x84U, 0x83U,
    0xDEU, 0xD9U, 0xD0U, 0xD7U, 0xC2U, 0xC5U, 0xCCU, 0xCBU, 0xE6U, 0xE1U,
    0xE8U, 0xEFU, 0xFAU, 0xFDU, 0xF4U, 0xF3U,
};

/* CRC16 high table */
static const uint8_t crc16HiTable[] = {
    0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U, 0x80U, 0x41U, 0x01U, 0xC0U,
    0x80U, 0x41U, 0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U, 0x80U, 0x41U,
    0x00U, 0xC1U, 0x81U, 0x40U, 0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U,
    0x80U, 0x41U, 0x01U, 0xC0U, 0x80U, 0x41U, 0x00U, 0xC1U, 0x81U, 0x40U,
    0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U, 0x80U, 0x41U, 0x00U, 0xC1U,
    0x81U, 0x40U, 0x01U, 0xC0U, 0x80U, 0x41U, 0x01U, 0xC0U, 0x80U, 0x41U,
    0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U, 0x80U, 0x41U, 0x00U, 0xC1U,
    0x81U, 0x40U, 0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U, 0x80U, 0x41U,
    0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U, 0x80U, 0x41U, 0x01U, 0xC0U,
    0x80U, 0x41U, 0x00U, 0xC1U, 0x81U, 0x40U, 0x00U, 0xC1U, 0x81U, 0x40U,
    0x01U, 0xC0U, 0x80U, 0x41U, 0x01U, 0xC0U, 0x80U, 0x41U, 0x00U, 0xC1U,
    0x81U, 0x40U, 0x01U, 0xC0U, 0x80U, 0x41U, 0x00U, 0xC1U, 0x81U, 0x40U,
    0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U, 0x80U, 0x41U, 0x01U, 0xC0U,
    0x80U, 0x41U, 0x00U, 0xC1U, 0x81U, 0x40U, 0x00U, 0xC1U, 0x81U, 0x40U,
    0x01U, 0xC0U, 0x80U, 0x41U, 0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U,
    0x80U, 0x41U, 0x01U, 0xC0U, 0x80U, 0x41U, 0x00U, 0xC1U, 0x81U, 0x40U,
    0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U, 0x80U, 0x41U, 0x01U, 0xC0U,
    0x80U, 0x41U, 0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U, 0x80U, 0x41U,
    0x00U, 0xC1U, 0x81U, 0x40U, 0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U,
    0x80U, 0x41U, 0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U, 0x80U, 0x41U,
    0x01U, 0xC0U, 0x80U, 0x41U, 0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U,
    0x80U, 0x41U, 0x00U, 0xC1U, 0x81U, 0x40U, 0x00U, 0xC1U, 0x81U, 0x40U,
    0x01U, 0xC0U, 0x80U, 0x41U, 0x01U, 0xC0U, 0x80U, 0x41U, 0x00U, 0xC1U,
    0x81U, 0x40U, 0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U, 0x80U, 0x41U,
    0x00U, 0xC1U, 0x81U, 0x40U, 0x01U, 0xC0U, 0x80U, 0x41U, 0x01U, 0xC0U,
    0x80U, 0x41U, 0x00U, 0xC1U, 0x81U, 0x40U,
};

/* CRC16 low table */
static const uint8_t crc16LoTable[] = {
    0x00U, 0xC0U, 0xC1U, 0x01U, 0xC3U, 0x03U, 0x02U, 0xC2U, 0xC6U, 0x06U,
    0x07U, 0xC7U, 0x05U, 0xC5U, 0xC4U, 0x04U, 0xCCU, 0x0CU, 0x0DU, 0xCDU,
    0x0FU, 0xCFU, 0xCEU, 0x0EU, 0x0AU, 0xCAU, 0xCBU, 0x0BU, 0xC9U, 0x09U,
    0x08U, 0xC8U, 0xD8U, 0x18U, 0x19U, 0xD9U, 0x1BU, 0xDBU, 0xDAU, 0x1AU,
    0x1EU, 0xDEU, 0xDFU, 0x1FU, 0xDDU, 0x1DU, 0x1CU, 0xDCU, 0x14U, 0xD4U,
    0xD5U, 0x15U, 0xD7U, 0x17U, 0x16U, 0xD6U, 0xD2U, 0x12U, 0x13U, 0xD3U,
    0x11U, 0xD1U, 0xD0U, 0x10U, 0xF0U, 0x30U, 0x31U, 0xF1U, 0x33U, 0xF3U,
    0xF2U, 0x32U, 0x36U, 0xF6U, 0xF7U, 0x37U, 0xF5U, 0x35U, 0x34U, 0xF4U,
    0x3CU, 0xFCU, 0xFDU, 0x3DU, 0xFFU, 0x3FU, 0x3EU, 0xFEU, 0xFAU, 0x3AU,
    0x3BU, 0xFBU, 0x39U, 0xF9U, 0xF8U, 0x38U, 0x28U, 0xE8U, 0xE9U, 0x29U,
    0xEBU, 0x2BU, 0x2AU, 0xEAU, 0xEEU, 0x2EU, 0x2FU, 0xEFU, 0x2DU, 0xEDU,
    0xECU, 0x2CU, 0xE4U, 0x24U, 0x25U, 0xE5U, 0x27U, 0xE7U, 0xE6U, 0x26U,
    0x22U, 0xE2U, 0xE3U, 0x23U, 0xE1U, 0x21U, 0x20U, 0xE0U, 0xA0U, 0x60U,
    0x61U, 0xA1U, 0x63U, 0xA3U, 0xA2U, 0x62U, 0x66U, 0xA6U, 0xA7U, 0x67U,
    0xA5U, 0x65U, 0x64U, 0xA4U, 0x6CU, 0xACU, 0xADU, 0x6DU, 0xAFU, 0x6FU,
    0x6EU, 0xAEU, 0xAAU, 0x6AU, 0x6BU, 0xABU, 0x69U, 0xA9U, 0xA8U, 0x68U,
    0x78U, 0xB8U, 0xB9U, 0x79U, 0xBBU, 0x7BU, 0x7AU, 0xBAU, 0xBEU, 0x7EU,
    0x7FU, 0xBFU, 0x7DU, 0xBDU, 0xBCU, 0x7CU, 0xB4U, 0x74U, 0x75U, 0xB5U,
    0x77U, 0xB7U, 0xB6U, 0x76U, 0x72U, 0xB2U, 0xB3U, 0x73U, 0xB1U, 0x71U,
    0x70U, 0xB0U, 0x50U, 0x90U, 0x91U, 0x51U, 0x93U, 0x53U, 0x52U, 0x92U,
    0x96U, 0x56U, 0x57U, 0x97U, 0x55U, 0x95U, 0x94U, 0x54U, 0x9CU, 0x5CU,
    0x5DU, 0x9DU, 0x5FU, 0x9FU, 0x9EU, 0x5EU, 0x5AU, 0x9AU, 0x9BU, 0x5BU,
    0x99U, 0x59U, 0x58U, 0x98U, 0x88U, 0x48U, 0x49U, 0x89U, 0x4BU, 0x8BU,
    0x8AU, 0x4AU, 0x4EU, 0x8EU, 0x8FU, 0x4FU, 0x8DU, 0x4DU, 0x4CU, 0x8CU,
    0x44U, 0x84U, 0x85U, 0x45U, 0x87U, 0x47U, 0x46U, 0x86U, 0x82U, 0x42U,
    0x43U, 0x83U, 0x41U, 0x81U, 0x80U, 0x40U,
};

/* Token packet match bytes */
static const uint8_t tokenMatchBytes[] = {
    0x04U,
    BDP_PID_IN_CHK,
    BDP_PID_IN_NCHK,
    BDP_PID_OUT_CHK,
    BDP_PID_OUT_NCHK,
};

/* Private function prototypes ----------------------------------------------*/
/* Interface implementations */
static void UART_ITF_Init(void);
static void UART_ITF_DeInit(void);
static void UART_ITF_Start(void);
static void UART_ITF_Stop(void);
static void UART_ITF_Handler(void);

/* Device callbacks */
static void UART_SendCplt_Callback(void);
static void UART_RecvCplt_Callback(void);
static void UART_RecvError_Callback(void);

/* CRC utils */
static uint8_t CRC8(uint8_t *data, uint16_t len);
static uint16_t CRC16(uint8_t *data, uint16_t len);

/* helpers */
static void RecvTokenPacket(void);
static bool ValidateTokenPacket(void);
static void SendAckPacket(uint8_t ack, uint16_t param);
static void RecvDataPacket(uint16_t len);
static void SendDataPacket(uint16_t len);
static bool ValidateDataPacket(void);

/* Private function implemenations ------------------------------------------*/
static void UART_ITF_Init(void)
{
    /* Init variables */
    stat = BDP_STAT_WAIT_TOKEN;
    errCnt = 0U;
    memset(tokenBuffer, 0, BDP_TOKEN_PACKET_SIZE);
    memset(ackBuffer, 0, BDP_TOKEN_PACKET_SIZE);
    memset(dataBuffer, 0, BDP_MAX_DATA_LEN +
           BDP_PID_SIZE +
           BDP_DATA_CHECKSUM_SIZE);

    /* Setup and init device */
    BDP_UartIO.init();
}

static void UART_ITF_DeInit(void)
{

}

static void UART_ITF_Start(void)
{
    /* Init variables */
    stat = BDP_STAT_WAIT_TOKEN;
    memset(tokenBuffer, 0, BDP_TOKEN_PACKET_SIZE);
    memset(ackBuffer, 0, BDP_TOKEN_PACKET_SIZE);
    memset(dataBuffer, 0, BDP_MAX_DATA_LEN);

    /* Begin receiving token */
    BDP_UartIO.start();
    RecvTokenPacket();
}

static void UART_ITF_Stop(void)
{
    BDP_UartIO.stop();
    errCnt = 0U;
}

static void UART_ITF_Reset(void)
{
    BDP_UartIO.clear();
    errCnt = 0U;

    /* Begin receiving token */
    stat = BDP_STAT_WAIT_TOKEN;
    RecvTokenPacket();
}

static void UART_ITF_Handler(void)
{
    if(stat == BDP_STAT_PROCESSING) {
        if(transferType == BDP_OUT_TRANSFER) {
            if(transfer.addr == 0U) {
                /* SETUP command and data(can be 0 length) received */
                BDP_DevDataCallback.setupOutCallback(&transfer);
            }
            else {
                /* OUT command and data(can be 0 length) received */
                BDP_DevDataCallback.dataOutCallback(&transfer);
            }
            if(transfer.abort != 0U) {
                /* Abort current transfer */
                BDP_UartIO.clear();
                stat = BDP_STAT_WAIT_TOKEN;
                RecvTokenPacket();
            }
            else {
                /* Send ACK */
                stat = BDP_STAT_OUT_DEV_CPLT_ACK;
                SendAckPacket(transfer.ack, transfer.ackParams);
            }
        }
        else if(transferType == BDP_IN_TRANSFER) {
            if(transfer.addr == 0U) {
                /* SETUP data requested */
                BDP_DevDataCallback.setupInCallback(&transfer);
            }
            else {
                /* OUT data requested */
                BDP_DevDataCallback.dataInCallback(&transfer);
            }
            if(transfer.ack == 0U) {
                /* Construct data packet */
                if(BDP_DevDataCallback.handle->useChecksum == 1U || transfer.addr == 0U) {
                    uint16_t calcVal;
                    dataBuffer[0] = BDP_PID_DATA_CHK;
                    calcVal = CRC16(dataBuffer, transfer.dataLen + BDP_PID_SIZE);
                    dataBuffer[transfer.xferLen - 2U] = (uint8_t)((calcVal & 0xFF00U) >> 8U);
                    dataBuffer[transfer.xferLen - 1U] = (uint8_t)((calcVal & 0xFFU));
                }
                else {
                    dataBuffer[0] = BDP_PID_DATA_NCHK;
                }
                /* Transmit data and ready to receive host ack */
                stat = BDP_STAT_IN_SEND;
                SendDataPacket(transfer.xferLen);
            }
            else {
                /* Send ACK */
                stat = BDP_STAT_IN_DEV_ACK;
                SendAckPacket(transfer.ack, transfer.ackParams);
            }
        }
        else {
            /* Do nothing. */
        }
    }
}

static void UART_SendCplt_Callback(void)
{
    if(stat == BDP_STAT_WAIT_TOKEN) {
        errCnt++;
        if(errCnt >= BDP_MAX_ERR_CNT) {
            UART_ITF_Reset();
            errCnt = 0U;
        }
        return;
    }
    /* OUT transfer ---------------------------*/
    if(transferType == BDP_OUT_TRANSFER) {
        if(stat == BDP_STAT_OUT_DEV_RDY_ACK) {  /* OUT device ready ack sent */
            /* Change to receive stat */
            stat = BDP_STAT_OUT_RECV;
        }
        else if(stat == BDP_STAT_OUT_DEV_CPLT_ACK) {     /* OUT device cplt ack sent */
            /* Setup for next transfer */
            stat = BDP_STAT_WAIT_TOKEN;
            RecvTokenPacket();
        }
        else {
            /* Do nothing. */
        }
    }
    /* IN transfer ---------------------------*/
    else if(transferType == BDP_IN_TRANSFER) {
        if(stat == BDP_STAT_IN_SEND ||
                stat == BDP_STAT_IN_DEV_ACK) {  /* IN data sent / IN device error ack sent */
            /* Setup for next transfer */
            stat = BDP_STAT_WAIT_TOKEN;
            RecvTokenPacket();
        }
    }
    else {
        errCnt++;
        if(errCnt >= BDP_MAX_ERR_CNT) {
            UART_ITF_Reset();
            errCnt = 0U;
        }
    }
}

static void UART_RecvCplt_Callback(void)
{
    if(stat == BDP_STAT_WAIT_TOKEN) {   /* Token received */
        uint8_t setupFlag = 0U;
        /* Validate token */
        if(!ValidateTokenPacket()) {
            /* UART interface can connect only one target, so it is ok to ack. */
            RecvTokenPacket();
            SendAckPacket(BDP_ACK_CMD_ERROR, 0U);
            return;
        }

        /* Check if setup transfer */
        if(tokenBuffer[1] == 0U) {
            setupFlag = 1U;
        }

        /* Get transfer information */
        memset(&transfer, 0, sizeof(BDP_TransferTypeDef));
        transfer.addr = tokenBuffer[1];
        transfer.cmd = tokenBuffer[2];
        transfer.cmdParams = (((uint16_t)tokenBuffer[5] << 8U) | tokenBuffer[6]);
        if(setupFlag == 0U) {
            /* Calc and check data length */
            transfer.dataLen = (((uint16_t)tokenBuffer[3] << 8U) | tokenBuffer[4]);
            if(transfer.dataLen > BDP_MAX_DATA_LEN) {
                /* Too much data, abort and restart */
                SendAckPacket(BDP_ACK_CMD_ERROR, 1U);
                RecvTokenPacket();
                return;
            }
        }
        else {
            /* Setup token has 4-bytes param */
            transfer.cmdParams |= (((uint32_t)tokenBuffer[3] << 24U) | (uint32_t)tokenBuffer[4] << 16U);
            /* Call protocol to manipulate transfer params */
            BDP_DevDataCallback.setupTokenCallback(&transfer, tokenBuffer);
        }

        /* Check and set transfer direction */
        if(tokenBuffer[0] == BDP_PID_IN_CHK ||
                tokenBuffer[0] == BDP_PID_IN_NCHK) {
            /* IN transfer cannot have 0 length */
            if(transfer.dataLen == 0U) {
                /* Invalid IN length, abort and restart */
                SendAckPacket(BDP_ACK_CMD_ERROR, 2U);
                RecvTokenPacket();
                return;
            }
            transferType = BDP_IN_TRANSFER;
        }
        else if(tokenBuffer[0] == BDP_PID_OUT_CHK ||
                tokenBuffer[0] == BDP_PID_OUT_NCHK) {
            transferType = BDP_OUT_TRANSFER;
        }
        else {
            /* Error token */
            RecvTokenPacket();
            return;
        }

        /* Check transfer target */
        if(((setupFlag == 0U) && transfer.addr != BDP_DevDataCallback.handle->addr) ||
                ((setupFlag == 1U) && BDP_DevDataCallback.handle->isSelected == 0U)) {
            /* UART interface can connect only one target, so there is no need
               to skip non-target transfer. */
            RecvTokenPacket();
            return;
        }

        /* Prepare data buffer */
        if(transfer.dataLen > 0U) {
            transfer.xferLen = transfer.dataLen + BDP_PID_SIZE + BDP_DATA_CHECKSUM_SIZE;
            transfer.data = &dataBuffer[1];
            memset(dataBuffer, 0, transfer.xferLen);
        }

        if(transferType == BDP_OUT_TRANSFER && transfer.dataLen > 0U) {
            /* Perpare to receive data */
            RecvDataPacket(transfer.xferLen);
            /* Tell host that device is ready */
            stat = BDP_STAT_OUT_DEV_RDY_ACK;
            SendAckPacket(BDP_ACK_OK, 0U);
        }
        else {
            /*
              Enter here if:
              1. OUT transfer and len == 0;
              2. IN transfer and len > 0;
              Anyway we should request application processing.
            */
            stat = BDP_STAT_PROCESSING;
        }
    }
    /* OUT transfer ---------------------------*/
    else if(stat == BDP_STAT_OUT_RECV) {    /* OUT Data received */
        /* Validate data */
        if(!ValidateDataPacket()) {
            /* Invalid data, abort and restart */
            SendAckPacket(BDP_ACK_DATA_ERROR, 0U);
            stat = BDP_STAT_WAIT_TOKEN;
            RecvTokenPacket();
            return;
        }
        /* Wait command processing */
        stat = BDP_STAT_PROCESSING;
    }
    else {
        errCnt++;
        if(errCnt >= BDP_MAX_ERR_CNT) {
            UART_ITF_Reset();
            errCnt = 0U;
        }
    }
}

static void UART_RecvError_Callback(void)
{
    BDP_UartIO.clear();
    stat = BDP_STAT_WAIT_TOKEN;
    RecvTokenPacket();
}

static uint8_t CRC8(uint8_t *data, uint16_t len)
{
    uint8_t crc8 = 0U;

    while(len--) {
        crc8 = crc8 ^ (*data++);
        crc8 = crc8Table[crc8];
    }

    return crc8;
}

static uint16_t CRC16(uint8_t *data, uint16_t len)
{
    uint8_t crcHi = 0xFFU;
    uint8_t crcLo = 0xFFU;
    uint8_t i;

    while(len--) {
        i = crcHi ^ (*data++);
        crcHi = crcLo ^ crc16HiTable[i];
        crcLo = crc16LoTable[i];
    }

    return ((uint16_t)crcHi << 8U | (uint16_t)crcLo);
}

static void RecvTokenPacket(void)
{
    /* In order to keep sync, we should seek token packet header */
    BDP_UartIO.receive(tokenBuffer, BDP_TOKEN_PACKET_SIZE, tokenMatchBytes);
}

static bool ValidateTokenPacket(void)
{
    bool flag = false;

    if(tokenBuffer[1] != 0U) {
        /* IN / OUT */
        if(BDP_DevDataCallback.handle->useChecksum == 1U &&
                (tokenBuffer[0] == BDP_PID_IN_CHK ||
                 tokenBuffer[0] == BDP_PID_OUT_CHK)) {
            flag = true;
        }
        else if(BDP_DevDataCallback.handle->useChecksum == 0U &&
                (tokenBuffer[0] == BDP_PID_IN_NCHK ||
                 tokenBuffer[0] == BDP_PID_OUT_NCHK)) {
            flag = true;
        }
        else {
            /* Do nothing. */
        }
    }
    else {
        /* SETUP */
        if(tokenBuffer[0] == BDP_PID_IN_CHK ||
                tokenBuffer[0] == BDP_PID_OUT_CHK) {
            flag = true;
        }
    }

    /* Check result */
    if(flag == false) {
        return false;
    }

    /* Validate CRC */
    if(BDP_DevDataCallback.handle->useChecksum == 1U || tokenBuffer[1] == 0U) {
        uint8_t calcVal = CRC8(tokenBuffer, BDP_TOKEN_PACKET_SIZE - 1U);
        if(calcVal != tokenBuffer[BDP_TOKEN_PACKET_SIZE - 1U]) {
            return false;
        }
    }

    return true;
}

static void SendAckPacket(uint8_t ack, uint16_t param)
{
    ackBuffer[0] = BDP_PID_ACK_CHK;
    ackBuffer[1] = ack;
    ackBuffer[2] = 0U;
    ackBuffer[3] = 0U;
    ackBuffer[4] = 0U;
    ackBuffer[5] = (uint8_t)((param & 0xFF00UL) >> 8U);
    ackBuffer[6] = (uint8_t)((param & 0x00FFUL) >> 0U);
    ackBuffer[7] = CRC8(ackBuffer, 7U);
    BDP_UartIO.send(ackBuffer, BDP_TOKEN_PACKET_SIZE);
}

static void RecvDataPacket(uint16_t len)
{
    BDP_UartIO.receive(dataBuffer, len, NULL);
}

static void SendDataPacket(uint16_t len)
{
    BDP_UartIO.send(dataBuffer, len);
}

static bool ValidateDataPacket(void)
{
    bool flag = false;

    if(transfer.addr != 0U) {
        if(BDP_DevDataCallback.handle->useChecksum == 1U &&
                dataBuffer[0] == BDP_PID_DATA_CHK) {
            flag = true;
        }
        else if(BDP_DevDataCallback.handle->useChecksum == 0U &&
                dataBuffer[0] == BDP_PID_DATA_NCHK) {
            flag = true;
        }
        else {
            /* Do nothing. */
        }
    }
    else {
        /* Setup data packet must have checksum */
        if(dataBuffer[0] == BDP_PID_DATA_CHK) {
            flag = true;
        }
    }

    /* Check result */
    if(flag == false) {
        return false;
    }

    /* Validate CRC */
    if(BDP_DevDataCallback.handle->useChecksum == 1U || transfer.addr == 0U) {
        uint16_t calcVal = CRC16(dataBuffer, transfer.dataLen + BDP_PID_SIZE);
        uint16_t checkVal = ((uint16_t)dataBuffer[transfer.xferLen - 2U] << 8U |
                             (uint16_t)dataBuffer[transfer.xferLen - 1U]);
        if(calcVal != checkVal) {
            return false;
        }
    }
    return true;
}

/* Instances ----------------------------------------------------------------*/
const BDP_DevItfTypeDef BDP_UartItf = {
    UART_ITF_Init,
    UART_ITF_DeInit,
    UART_ITF_Reset,
    UART_ITF_Start,
    UART_ITF_Stop,
    UART_ITF_Handler,
};

const BDP_UartItfDataCallbackTypeDef BDP_UartItfDataCallback = {
    UART_SendCplt_Callback,
    UART_RecvCplt_Callback,
    UART_RecvError_Callback,
};
