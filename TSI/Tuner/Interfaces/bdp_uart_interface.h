#ifndef BDP_UART_ITF_H
#define BDP_UART_ITF_H

#include "bdp.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _BDP_UartItfDataCallback BDP_UartItfDataCallbackTypeDef;

struct _BDP_UartItfDataCallback
{
    /** Transmit complete callback */
    void (*sendCplt)(void);

    /** Receive complete callback */
    void (*recvCplt)(void);

    /** Receive error callback */
    void (*recvError)(void);
    
};

/** UART interface instance. */
extern const BDP_DevItfTypeDef BDP_UartItf;

/** UART interface io instance. */
extern const BDP_UartItfDataCallbackTypeDef BDP_UartItfDataCallback;

#ifdef __cplusplus
}
#endif

#endif  /* BDP_UART_ITF_H */
