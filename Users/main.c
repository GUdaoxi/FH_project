/* Private includes ---------------------------------------------------------*/
/* FL driver library include */
#include "fm33fh0xx_fl.h"

/* Library includes */
#include "tsi.h"
#include "led.h"
#include "Uart.h"
/* Library debug interface includes */
#include "bdp.h"
#include "bdp_mem_interface.h"

/* USER PRIVATE INCLUDES BEGIN */
#include "svd.h"

uint32_t mm_isqrt_u32(uint32_t x)
{
    uint32_t res = 0;
    uint32_t bit = 1uL << 30;  /* The second-to-top bit (1<<30) */

    /* "bit" starts at the highest power of four <= x */
    while (bit > x) {
        bit >>= 2;
    }

    while (bit != 0) {
        if (x >= res + bit) {
            x   -= res + bit;
            res  = (res >> 1) + bit;
        } else {
            res >>= 1;
        }
        bit >>= 2;
    }
    return res;
}

/* sqrt for Q16.16 fixed-point: y = sqrt(x), both in Q16.16
 *
 * 方法：sqrt(x_q16_16) = isqrt(x_q16_16 << 16)
 * 因为：x_q16_16 = X * 2^16
 * sqrt(x_q16_16) = sqrt(X)*2^8
 * 但我们想要 Q16.16 输出 => sqrt(X)*2^16
 * => sqrt(x_q16_16 << 16)
 *
 * 注意：x_q16_16<<16 可能溢出 32 位，所以用 64 位中间变量。
 */
uint32_t mm_sqrt_q16_16(uint32_t x_q16_16)
{
    uint64_t v = ((uint64_t)x_q16_16) << 16; /* up-scale */
    /* 对 64 位做 isqrt（这里给一个简单 64-bit 版本） */
    uint64_t res = 0;
    uint64_t bit = 1ull << 62; /* second-to-top bit */

    while (bit > v) {
        bit >>= 2;
    }

    while (bit != 0) {
        if (v >= res + bit) {
            v   -= res + bit;
            res  = (res >> 1) + bit;
        } else {
            res >>= 1;
        }
        bit >>= 2;
    }

    /* res 现在是 sqrt(x_q16_16<<16)，它本身就是 Q16.16 的结果 */
    if (res > 0xFFFFFFFFull) return 0xFFFFFFFFu;
    return (uint32_t)res;
}
static void SystemClockInit(void);
uint32_t miaoflag_5[20]={0};
/* USER PRIVATE FUNCTION PROTOTYPES BEGIN */

/* USER PRIVATE FUNCTION PROTOTYPES END */
uint32_t static data=0x00030000;
uint16_t unit=128;
uint32_t BSP_ROUND(uint32_t value32, uint16_t value16) {
 
    uint32_t result = (value32 + value16 - 1) / value16;
    return result;
}
uint8_t receivedData[1]; // 用于存储接收到的 10 个字节
void io_init(void)
{
	CMU->PCLKCR1 |= BIT7;                                     //打开PAD总线时钟
  GPIOD->FCR |= BIT9*BIT9;     //配置为输出功能
  GPIOD->DSET |= BIT9;                //配置默认态为高电平
	 GPIOD->FCR |= BIT10*BIT10;     //配置为输出功能
  GPIOD->DSET |= BIT10;                //配置默认态为高电平
	 GPIOG->FCR |= BIT2*BIT2;     //配置为输出功能
  GPIOG->DSET |= BIT2;                //配置默认态为高电平
}
void Uart5_Init(void) //PC5 PC6 
{
  CMU->PCLKCR1 |= BIT7; 
  GPIOC->FCR |= 0xA<<10; 

  CMU->OPCER1 |=BIT14;
  CMU->PCLKCR3 |= BIT13;
  
  UART5->MCR = 0X0;
  UART5->CSR &= ~(BIT4|BIT5);                                  /*UART config none parity*/ 
  UART5->CSR &= ~(BIT6|BIT7);                                /*UART config 8 data bits*/   
  UART5->CSR |= BIT6;                                           
  UART5->CSR &= ~BIT8;     
  
  UART5->BGR = Uart5BGR_Value; 
  UART5->ISR = BIT8;
  UART5->ISR = BIT1;
  UART5->IER |=BIT1;
  UART5->IER |= BIT8;
  UART5->CSR |= BIT1|BIT0;                               
   
  NVIC_DisableIRQ(MUX11_IRQn);
  NVIC_SetPriority(MUX11_IRQn, 1);                       
  NVIC_EnableIRQ(MUX11_IRQn);
}

#define PROTO_HEAD  (0xB2u)
volatile uint8_t  g_rx_active = 0;     // 是否正在接收/等待后续
volatile uint8_t  g_rx_to_cnt = 0;     // 20ms tick 计数（0~5）
volatile uint8_t  g_rx_timeout = 0;    // 超时标志：1=100ms无新数据

static volatile uint8_t  g_tx_buf[16];
static volatile uint8_t  g_tx_len = 0;
static volatile uint8_t  g_tx_idx = 0;
static volatile uint8_t  g_tx_busy = 0;

static volatile uint8_t  g_rx_buf[64];
static volatile uint8_t  g_rx_idx = 0;

#define PROTO_MAX_PAYLOAD   (32u)   // 你按需要设，<= g_rx_buf大小也行

typedef enum {
    RX_WAIT_HEAD = 0,
    RX_WAIT_ID,
    RX_WAIT_LEN,
    RX_WAIT_PAYLOAD,
    RX_WAIT_CRC_H,
    RX_WAIT_CRC_L
} rx_state_t;

static volatile rx_state_t g_rx_state = RX_WAIT_HEAD;

static volatile uint8_t  g_rx_id = 0;
static volatile uint8_t  g_rx_len = 0;
static volatile uint8_t  g_rx_pl_idx = 0;

static uint8_t  g_rx_payload[PROTO_MAX_PAYLOAD];

static volatile uint8_t  g_rx_crc_h = 0;
static volatile uint8_t  g_rx_crc_l = 0;

volatile uint16_t g_rx_ok_cnt = 0;
volatile uint16_t g_rx_crc_fail_cnt = 0;
volatile uint16_t g_rx_len_err_cnt = 0;


static const uint8_t g_poll_id_list[] = {
    0x00,
    0x01,
    0x02,
    0x03,
    0x04,
};
#define POLL_ID_NUM   (sizeof(g_poll_id_list) / sizeof(g_poll_id_list[0]))

static uint8_t g_poll_idx = 0;

/* ---------------- CRC8 ---------------- */
static uint16_t CRC8_07_FF(const uint8_t *buf, uint16_t len)
{
    uint16_t crc = 0xFFFF;
    for(uint16_t i=0; i<len; i++)
    {
      //g_rx_buf[i]=buf[i];
        crc ^= buf[i];
        for(uint8_t b=0; b<8; b++)
        {
           if (crc & 0x0001)
             {
                 // 右移1位后与多项式 0x1021 异或
                 crc = (crc >> 1) ^ 0x1021;
             }
             else
             {
                 // 最低位为0，直接右移1位
                 crc = crc >> 1;
             }
        }
    }
    return crc;
}

static uint8_t Proto_SendFrame(uint8_t id, const uint8_t *payload, uint8_t plen)
{
    if (g_tx_busy) return 0;
    if (plen > (uint8_t)(sizeof(g_tx_buf) - 4u)) return 0;

    g_tx_buf[0] = PROTO_HEAD;
    g_tx_buf[1] = id;
    g_tx_buf[2] = plen;

    for (uint8_t i = 0; i < plen; i++)
        g_tx_buf[3u + i] = payload[i];
      uint16_t crc = CRC8_07_FF((const uint8_t*)&g_tx_buf[1], (uint16_t)(2u + plen));
    g_tx_buf[3u + plen] = crc>>8;
    g_tx_buf[4u + plen]=crc;
    g_tx_len  = (uint8_t)(5u + plen);
    g_tx_idx  = 0;
    g_tx_busy = 1;
UART5->IER &= ~BIT8;      // 关 RX 中断
    
    UART5->ISR = BIT8;        // 清 RX 标志
    UART5->IER |= BIT1;
    UART5->TXBUF = g_tx_buf[g_tx_idx++];
    return 1;
}
uint8_t App_Send(uint8_t id, const uint8_t *data, uint8_t len)
{
    return Proto_SendFrame(id, data, len);
}

uint8_t App_SendRGB(uint8_t r, uint8_t g, uint8_t b)
{
    uint8_t p[4];
    p[0] = 0x11;
    p[1] = r;
    p[2] = g;
    p[3] = b;
    return App_Send(0x01, p, 4);
}
/* 颜色循环：红->绿->蓝->白 (每次调用切一次) */
static uint8_t App_SendRGB_Cycle_R_G_B_W(void)
{
    static uint8_t step = 0;   // 0:R 1:G 2:B 3:W
    uint8_t r = 0, g = 0, b = 0;

    switch (step)
    {
        case 0: r = 0xFF; g = 0x00; b = 0x00; break; // Red
        case 1: r = 0x00; g = 0xFF; b = 0x00; break; // Green
        case 2: r = 0x00; g = 0x00; b = 0xFF; break; // Blue
        default:r = 0xFF; g = 0xFF; b = 0xFF; break; // White
    }

    step++;
    if (step >= 4) step = 0;

    return App_SendRGB(r, g, b);
}
uint8_t App_SendStatus(void)
{
    uint8_t p[6];
    uint8_t idx = 0;

    extern uint8_t system_state;
    extern uint8_t error_code;
    extern uint8_t voltage;
    extern uint8_t current;
    extern uint8_t temperature;

    p[idx++] = 0x30;          
    p[idx++] = 0;
    p[idx++] = 0;
    p[idx++] = 0;
    p[idx++] = 0;
    p[idx++] = 0;

    return App_Send(0x03, p, idx);
}
void Master_UART5_SendOnce_100ms(void)
{
    uint8_t id;

    if (g_tx_busy) return;

    id = g_poll_id_list[g_poll_idx];

    switch (id)
    {
        case 0x01:
            //(void)App_SendRGB(0x00, 0xFF, 0x00);
           (void)App_SendRGB_Cycle_R_G_B_W();
            break;

        case 0x02:
        {
            uint8_t p[1] = { 0x01 };
            (void)App_Send(0x02, p, 1);
            break;
        }

        case 0x03:
            (void)App_SendStatus();
            break;

        case 0x04:
        {
            uint8_t p[6] = { 0x21, 0x01, 0x02, 0x03, 0x04, 0x05 };
            (void)App_Send(0x04, p, 6);
            break;
        }

        default:
        {
            uint8_t p[1] = { 0x00 };
            (void)App_Send(id, p, 1);
            break;
        }
    }

    g_poll_idx++;
    if (g_poll_idx >= POLL_ID_NUM)
        g_poll_idx = 0;
}


void MUX11_IRQHandler(void)
{
    volatile uint32_t IFflag;
    IFflag = UART5->ISR;
    if((IFflag & BIT1) && (UART5->IER & BIT1))
    {
        if(g_tx_busy)
        {
            if(g_tx_idx < g_tx_len)
            {
                UART5->TXBUF = g_tx_buf[g_tx_idx++];
            }
            else
            {
                
                UART5->IER &= ~BIT1;
                g_tx_busy = 0;
                g_tx_len  = 0;
                g_tx_idx  = 0;
                 UART5->ISR = BIT8;        // 清 RX 标志
                UART5->IER |= BIT8;       // 打开 RX 中断
            }
        }
        else
        {
            UART5->IER &= ~BIT1;
        }
    }
    if((IFflag & BIT8) && (UART5->IER & BIT8))
    {
        uint8_t ch = (uint8_t)UART5->RXBUF;
        g_rx_buf[g_rx_idx++] = ch;
        if(g_rx_idx >= sizeof(g_rx_buf)) g_rx_idx = 0;
         g_rx_active  = 1;
         g_rx_to_cnt  = 0;     
         g_rx_timeout = 0;     
         UART5->ISR = BIT8;
    }
}

void Timer20msInit()
{
    CMU->PCLKCR4|=BIT4;    
    INTMUX->CR1 |= BIT4;                     
    TAU->TAU0CR&=~BIT2;
    TAU0->T2CFGR |= (15<<16);                
    TAU0->T2ARR = 20000;                                          
    NVIC_DisableIRQ(MUX2_IRQn);                                 
    NVIC_SetPriority(MUX2_IRQn, 0);                            
    NVIC_EnableIRQ(MUX2_IRQn);                                  
    TAU0->T2ISR = BIT0;                                
    TAU0->T2IER |= BIT0;                                
    TAU->TAU0CR |= BIT2; 
}

volatile uint8_t flag_send_100ms = 0;

void MUX2_IRQHandler(void)
{
    static uint8_t cnt_20ms = 0;

    if(TAU0->T2ISR & BIT0)
    {
        TAU0->T2ISR = BIT0; 

        cnt_20ms++;
        if(cnt_20ms >= 50) 
        {
            cnt_20ms = 0;
            flag_send_100ms = 1;
        }
         if(g_rx_active)               
        {
            if(g_rx_to_cnt < 5) g_rx_to_cnt++;
            if(g_rx_to_cnt >= 5)                
            {
                g_rx_active  = 0;
                g_rx_timeout = 1;                
                g_rx_to_cnt  = 0;
            }
        }
    }
}

int main(void)
{
    /* Init system clock */
    SystemClockInit();

    FL_Init();
    CMU->PCLKCR4 |= (0x1 << 4);
    TAU0->T1CFGR = ((32 - 1) << 16);
    TAU0->T1ARR = (2000 - 1);
    TAU0->T1ISR = 0x1;
    TAU0->T1IER = 0x1;
    TAU->TAU0CR|=0x1<<1U;
    INTMUX->CR1 |= (0x3 << 2);
    NVIC_EnableIRQ(MUX1_IRQn);
    /* USER CODES AREA 2 BEGIN */
    Led1Init();
    Led2Init();
    /* USER CODES AREA 2 END */
    /* Init TSI library */
    TSI_Init(&TSI_LibHandle);

    /* Init BladeDP protocol */
    BDP_Init(&BDP_MemItf, &BDP_Callback);
    BDP_Start();

    /* Feed watchdog */
    FL_IWDT_ReloadCounter(IWDT);

    /* Enable all widget and start scan */
    TSI_Widget_EnableAll(&TSI_LibHandle);
    TSI_Start(&TSI_LibHandle);
    BSP_ROUND(data,unit);
    io_init();
    Uart5_Init();
    Timer20msInit();
    while(1)
    {   
        /* Feed watchdog */
        FL_IWDT_ReloadCounter(IWDT);

        /* Handle library and debug operation */
        TSI_Handler(&TSI_LibHandle);
        BDP_Handler();
        //SaveTSI_RawCount();
         if(flag_send_100ms)
    {
        flag_send_100ms = 0;
        Master_UART5_SendOnce_100ms();
    }

        /* USER CODES AREA 5 BEGIN */

        /* USER CODES AREA 5 END */
    }
}

/* USER CODES AREA 6 BEGIN */
void TSI_WidgetUpdateCpltCallback(TSI_LibHandleTypeDef* handle)
{
    /* User can process widget status here. */
}
/* USER CODES AREA 6 END */

/* Private functions --------------------------------------------------------*/
/**
 * @brief Init system clock.
 *
 */
void SystemClockInit(void)
{
    /* USER PRE SYSTEM CLOCK INIT BEGIN */

    /* USER PRE SYSTEM CLOCK INIT END */

    /* Enable RCHF 8MHz */
    FL_CMU_RCHF_WriteTrimValue(RCHF8M_TRIM);
    FL_CMU_RCHF_SetFrequency(FL_CMU_RCHF_FREQUENCY_8MHZ);

    /* Config PLL */
    FL_CMU_PLL_Disable();
    FL_CMU_PLL_SetClockSource(FL_CMU_PLL_CLK_SOURCE_RCHF);
    FL_CMU_PLL_SetPrescaler(FL_CMU_PLL_PSC_DIV8);
    FL_CMU_PLL_WriteMultiplier(32 - 1);
    FL_CMU_PLL_Enable();

    /* Wait for the PLL lock flag */
    uint32_t timeout = 0xFFFFFFFFUL;
    do
    {
        if(FL_CMU_IsActiveFlag_PLLReady() == 0x1U)
        {
            break;
        }

        /* Clear watchdog */
        FL_IWDT_ReloadCounter(IWDT);

    } while (--timeout > 0);

    /* Set flash read wait */
    FL_FLASH_SetCodeReadWait(FLASH, FL_FLASH_CODE_WAIT_0CYCLE);

    /* Set system clock source and bus prescaler */
    FL_CMU_SetAHBPrescaler(FL_CMU_AHBCLK_PSC_DIV2);
    FL_CMU_SetAPB1Prescaler(FL_CMU_APB1CLK_PSC_DIV1);
    FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_PLL);

    /* Update system core clock */
    SystemCoreClock = 16000000;

    /* USER SYSTEM CLOCK INIT BEGIN */

    /* USER SYSTEM CLOCK INIT END */
}

/* TSI interrupt handler */
void MUX19_IRQHandler(void)
{
    TSI_Dev_Handler(TSI_LibHandle.driver);
}
/* USER PRIVATE FUNCTION BEGIN */
void MUX1_IRQHandler(void)
{
    uint8_t i;
    if(TAU0->T1ISR & 0x1)
    {
        TAU0->T1ISR = 0x1;
        for(i=0;i<20;i++)
        {
          miaoflag_5[i]++;
        }
    }
 
}
/* USER PRIVATE FUNCTION END */


