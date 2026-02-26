#ifndef BDP_UART_ITF_IO_H
#define BDP_UART_ITF_IO_H

#include <stdint.h>
#include <stddef.h>

/** UART low-level interface */
typedef struct _BDP_UART_IO {
    /** Init UART */
    void (*init)(void);

    /** DeInit UART */
    void (*deinit)(void);

    /** Start UART */
    void (*start)(void);

    /** Stop UART */
    void (*stop)(void);

    /** Clear buffer */
    void (*clear)(void);

    /** Send data */
    void (*send)(const uint8_t *pBuf, uint16_t length);

    /** Receive data */
    void (*receive)(uint8_t *pBuf, uint16_t length, const uint8_t *seek);

} BDP_UART_IOTypeDef;

/** UART low-level interface implementation */
extern const BDP_UART_IOTypeDef BDP_UartIO;

#endif  /* BDP_UART_ITF_IO_H */
