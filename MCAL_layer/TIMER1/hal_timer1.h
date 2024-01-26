/* 
 * File:   hal_timer1.h
 * Author: YaseenEzzat
 *
 * Created on November 8, 2023, 7:41 AM
 */

#ifndef HAL_TIMER1_H
#define	HAL_TIMER1_H

/* Section : Includes*/

#include "hal_timer1_config.h"
#include "../../../../../Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "../GPIO/hal_GPIO.h"
#include "../INTERRUPT/mcal_internal_interrupt.h"

/* Section : Macro Declaration*/
#define SYSTEM_CLK_STATUSE                     T1CONbits.T1RUN
#define TIMER1_LOW_REGISTER                    TMR1L
#define TIMER1_HIGH_REGISTER                   TMR1H
#define TIMER1_PRESCALER                       T1CONbits.T1CKPS
#define TIMER1_CLK_SOURCE                      T1CONbits.TMR1CS
/* Section : Macro Function Declaration*/
//  enable / disable TIMER1.
#define TIMER1_ENABLE()                              (T1CONbits.TMR1ON = 1)
#define TIMER1_DISABLE()                             (T1CONbits.TMR1ON = 0)
// select TIMER1 clock source.
#define TIMER1_INTERNAL_CLK_SOURCE()                 (T1CONbits.TMR1CS = 0)
#define TIMER1_EXTERNAL_CLK_SOURCE_T13CKI()           (T1CONbits.TMR1CS = 1)
// select TIMER1 read and write BIT mode.
#define TIMER1_ENABLE_8BIT_MODE()                    (T1CONbits.RD16 = 0)
#define TIMER1_ENABLE_16BIT_MODE()                   (T1CONbits.RD16 = 1)
// set TIMER1 Prescale value.
#define TIMER1_PRESCALER_SET_VALUE(PS_VALUE)         (T1CONbits.T1CKPS = PS_VALUE)
//  enable / disable TIMER1 OSC.
#define TIMER1_OSC_ENABLE()                          (T1CONbits.T1OSCEN = 1)
#define TIMER1_OSC_DISABLE()                         (T1CONbits.T1OSCEN = 0)
// select TIMER1 synchronization mode.
#define TIMER1_EXTERNAL_CLK_SOURCE_SYNCHROINZE()     (T1CONbits.T1SYNC= 0)
#define TIMER1_EXTERNAL_CLK_SOURCE_ASYNCHROINZE()    (T1CONbits.T1SYNC= 1)
/* Section : Data Type Declaration*/
typedef enum {
    TIMER1_Prescale_value_1_to_1 = 0,          // 00 = 1:1   Prescale OFF
    TIMER1_Prescale_value_1_to_2,              // 01 = 1:2   Prescale value
    TIMER1_Prescale_value_1_to_4,              // 10 = 1:4   Prescale value
    TIMER1_Prescale_value_1_to_8               // 11 = 1:8   Prescale value
}TIMER1_prescale_vlaue_t;

typedef enum {
    T1CKI_synchronize,
    T1CKI_asynchronize
}T1CKI_synchronization_t;

typedef enum {
    TIMER1_16_BIT_mode,
    TIMER1_8_BIT_mode
}TIMER1_BIT_mode_t;

typedef enum {
    TIMER1_OSC_disable,
    TIMER1_OSC_enable
}TIMER1_OSC_enable_t;

typedef enum {
    TIMER1_internal_clk_source,
    TIMER1_external_clk_source
}TIMER1_clock_source_t;

typedef struct {
#if INTERRUPT_TIMER1==FEATURE_ENABLED
    void(*TIMER1_interrupt_handler) (void);
    interrupt_priority_LEVEL priority_LEVEL;
#endif
    TIMER1_clock_source_t TIMER1_clock_source;
    TIMER1_BIT_mode_t TIMER1_BIT_mode;
    TIMER1_prescale_vlaue_t TIMER1_prescale_vlaue;
    TIMER1_OSC_enable_t TIMER1_OSC;
    T1CKI_synchronization_t TIMER1_synchronization;
    uint16 TIMER1_counter_reg_value;       
}TIMER1_config_t;

/* Section : Function Declaration*/

Std_ReturnType TIMER1_initialization (const TIMER1_config_t *TIMER1_obj);
Std_ReturnType TIMER1_denitialization (const TIMER1_config_t *TIMER1_obj);
Std_ReturnType TIMER1_read_counter_reg_vlaue (const TIMER1_config_t *TIMER1_obj , uint16 *value);
Std_ReturnType TIMER1_write_counter_reg_vlaue (const TIMER1_config_t *TIMER1_obj , uint16 value);


#endif	/* HAL_TIMER1_H */

