/* 
 * File:   hal_usart.h
 * Author: YaseenEzzat
 *
 * Created on November 12, 2023, 6:53 PM
 */

#ifndef HAL_USART_H
#define	HAL_USART_H

/* Section : Includes*/
#include "hal_usart_config.h"
#include "../../../../../Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "../GPIO/hal_GPIO.h"
#include "../INTERRUPT/mcal_internal_interrupt.h"
/* Section : Macro Declaration*/
#define USART_TRANS_INTERRUPT_FALG                (PIR1bits.TXIF)
#define USART_RECEIVE_INTERRUPT_FALG              (PIR1bits.RCIF)
// Transmit Shift Register Status
#define EMPTY  1
#define FULL   0
#define TRANSMIT_SHIFT_REGISTER_STATUS      (TXSTAbits.TRMT)

// Transmit using TXD9 
#define WRITE_ON_TXD9                       (TXSTAbits.TX9D)

// Receive Framing Error Status
#define FRAMING_ERROR      1
#define NO_FRAMING_ERROR   0
#define RECEIVE_FRAMING_ERROR_STATUS        (RCSTAbits.FERR)

// Receive Overrun Error Status
#define OVERRUN_ERROR      1
#define NO_OVERRUN_ERROR   0
#define RECEIVE_OVERRUN_ERROR_STATUS        (RCSTAbits.OERR)

// Receive using RXD9 
#define READ_FROM_RXD9                      (RCSTAbits.RX9D)

// Baud Rate low and high Registers
#define EUSART_BUAD_RATE_LOW_REG                   (SPBRG)
#define EUSART_BUAD_RATE_HIGH_REG                  (SPBRGH)              

// Asynchronous transmit and receive Registers
#define EUSART_ASYNCHRONOUS_TRASMIT_REG            (TXREG)
#define EUSART_ASYNCHRONOUS_RECEIVE_REG            (RCREG)

/* Section : Macro Function Declaration*/
// EUSART Mode Select
#define EUSART_ASYNCHRONOUS_ENABLE()                (TXSTAbits.SYNC = 0)
#define EUSART_SYNCHRONOUS_ENABLE()                 (TXSTAbits.SYNC = 1)

// Serial Port Enable
#define EUSART_SERIAL_PORT_ENABLE()                 (RCSTAbits.SPEN = 1)
#define EUSART_SERIAL_PORT_DISABLE()                (RCSTAbits.SPEN = 0)

// Synchronous mode select
#define EUSART_SYNCHRONOUS_MASTER()                 (TXSTAbits.CSRC = 1)
#define EUSART_SYNCHRONOUS_SLAVE()                  (TXSTAbits.CSRC = 0)

// Transmit Enable / Disable
#define EUSART_TRANSMIT_ENABLE()                    (TXSTAbits.TXEN = 1)
#define EUSART_TRANSMIT_DISABLE()                   (TXSTAbits.TXEN = 0)

// select 9-BIT OR 8-BIT  transmission
#define EUSART_ASYNCHRONOUS_TRANSMIT_FORMATE_9BIT() (TXSTAbits.TX9 = 1)
#define EUSART_ASYNCHRONOUS_TRANSMIT_FORMATE_8BIT() (TXSTAbits.TX9 = 0)

// Receive Enable / Disable
#define EUSART_RECEIVE_ENABLE()                     (RCSTAbits.CREN = 1)
#define EUSART_RECEIVE_DISABLE()                    (RCSTAbits.CREN = 0)

// select 9-BIT OR 8-BIT  Receiving
#define EUSART_ASYNCHRONOUS_RECEIVE_FORMATE_9BIT()  (RCSTAbits.RX9 = 1)
#define EUSART_ASYNCHRONOUS_RECEIVE_FORMATE_8BIT()  (RCSTAbits.RX9 = 0)

// select Baud Rate Speed
#define EUSART_ASYNCHRONOUS_HIGH_SPEED()            (TXSTAbits.BRGH = 1)
#define EUSART_ASYNCHRONOUS_LOW_SPEED()             (TXSTAbits.BRGH = 0)

// select 8BIT or 16BIT Baud Rate Register
#define EUSART_ASYNCHRONOUS_8BIT_BAUD_RATE()        (BAUDCONbits.BRG16 = 0)
#define EUSART_ASYNCHRONOUS_16BIT_BAUD_RATE()       (BAUDCONbits.BRG16 = 1)


/* Section : Data Type Declaration*/
typedef enum {
    Asynchronous_mode,
    synchronous_mode
}USART_mode_t;

typedef enum {
    Asynchronous_low_speed_8bit,
    Asynchronous_high_speed_8bit,
    Asynchronous_low_speed_16bit,
    Asynchronous_high_speed_16bit,
    synchronous_16bit,
    synchronous_8bit,        
}buad_rate_mode_t;

typedef enum {
    _9_bit_frame,
    _8_bit_frame        
}Asynchronous_frame_bits_t;

typedef enum {
    Disable,
    Enable        
}Asynchronous_operation_status_t;

typedef struct {
    void(*Transmit_Interrupt_handler) (void);
    interrupt_priority_LEVEL priority_LEVEL;
    Asynchronous_frame_bits_t  transmission_frame_bits;
    Asynchronous_operation_status_t transmission_status;         
}Async_transmission_config_t;

typedef struct {
    void(*Receive_Interrupt_handler) (void);
    interrupt_priority_LEVEL priority_LEVEL;
    Asynchronous_frame_bits_t  receiving_frame_bits;
    Asynchronous_operation_status_t receiving_status;
    void(*Receive_Overrun_Error_handler)  (void);
    void(*Receive_Frame_Error_handler)  (void);
}Async_receiving_config_t;


typedef struct {
    USART_mode_t USART_mode;
    Async_receiving_config_t receiving_config;
    Async_transmission_config_t transmission_config;
    buad_rate_mode_t buad_rate_mode;
    uint16 buad_rate_value;
}USART_config_t;

/* Section : Function Declaration*/
Std_ReturnType USART_Asynchronous_Initialization(const USART_config_t *USART_config );
Std_ReturnType USART_Asynchronous_Deinitialization(const USART_config_t *USART_config );

Std_ReturnType USART_Asynchronous_write_8_bit_data_Blocking(uint8 data );
Std_ReturnType USART_Asynchronous_read_8_bit_data_Blocking(uint8 *data );
Std_ReturnType USART_Asynchronous_write_string_Blocking(char *string );


Std_ReturnType USART_Asynchronous_write_8_bit_data_Non_Blocking(uint8 data );
Std_ReturnType USART_Asynchronous_read_8_bit_data_Non_Blocking(uint8 *data );
Std_ReturnType USART_Asynchronous_write_string_Non_Blocking(char *string );

#endif	/* HAL_USART_H */

   