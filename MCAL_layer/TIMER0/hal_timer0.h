/* 
 * File:   hal_timer0.h
 * Author: YaseenEzzat
 *
 * Created on November 6, 2023, 12:11 PM
 */

#ifndef HAL_TIMER0_H
#define	HAL_TIMER0_H

/* Section : Includes*/

#include "hal_timer0_config.h"
#include "../../../../../Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "../GPIO/hal_GPIO.h"
#include "../INTERRUPT/mcal_internal_interrupt.h"

/* Section : Macro Declaration*/
#define TIMER0_LOW_REGISTER                    TMR0L
#define TIMER0_HIGH_REGISTER                   TMR0H
#define TIMER0_PRESCALER                       T0CONbits.PSA
#define TIMER0_CLK_SOURCE                      T0CONbits.T0CS
/* Section : Macro Function Declaration*/
//  enable / disable TIMER0.
#define TIMER0_ENABLE()                              (T0CONbits.TMR0ON = 1)
#define TIMER0_DISABLE()                             (T0CONbits.TMR0ON = 0)
// select TIMER0 clock source.
#define TIMER0_INTERNAL_CLK_SOURCE()                 (T0CONbits.T0CS = 0)
#define TIMER0_EXTERNAL_CLK_SOURCE_T0CKI()           (T0CONbits.T0CS = 1)
// select TIMER0 BIT mode.
#define TIMER0_ENABLE_8BIT_MODE()                    (T0CONbits.T08BIT = 1)
#define TIMER0_ENABLE_16BIT_MODE()                   (T0CONbits.T08BIT = 0)
// select TIMER0(counter) EDGE mode.
#define TIMER0_T0CK_INCREMENT_ON_RISING_EDGE()       (T0CONbits.T0SE = 1)
#define TIMER0_T0CK_INCREMENT_ON_FALLING_EDGE()      (T0CONbits.T0SE = 0)
//  enable / disable TIMER0 PRESCALER
#define TIMER0_PRESCALER_ENABLE()                    (T0CONbits.PSA = 0)
#define TIMER0_PRESCALER_DISABLE()                   (T0CONbits.PSA = 1)
// set TIMER0 Prescale value.
#define TIMER0_PRESCALER_SET_VALUE(PS_VALUE)         (T0CONbits.T0PS = PS_VALUE)

/* Section : Data Type Declaration*/
typedef enum {
    TIMER0_Prescale_value_1_to_2 = 0,          //000 = 1:2   Prescale value
    TIMER0_Prescale_value_1_to_4,              //001 = 1:4   Prescale value
    TIMER0_Prescale_value_1_to_8,              //010 = 1:8   Prescale value
    TIMER0_Prescale_value_1_to_16,             //011 = 1:16  Prescale value
    TIMER0_Prescale_value_1_to_32,             //100 = 1:32  Prescale value
    TIMER0_Prescale_value_1_to_64,             //101 = 1:64  Prescale value
    TIMER0_Prescale_value_1_to_128,            //110 = 1:128 Prescale value
    TIMER0_Prescale_value_1_to_265             //111 = 1:256 Prescale value
}TIMER0_prescale_vlaue_t;

typedef enum {
    TIMER0_falling_edge,
    TIMER0_rising_edge
}T0CKI_egde_t;

typedef enum {
    TIMER0_16_BIT_mode,
    TIMER0_8_BIT_mode
}TIMER0_BIT_mode_t;

typedef enum {
    TIMER0_prescaler_enable,
    TIMER0_prescaler_disable
}TIMER0_prescaler_enable_t;

typedef enum {
    TIMER0_internal_clk_source,
    TIMER0_external_clk_source
}TIMER0_clock_source_t;

typedef struct {
#if INTERRUPT_TIMER0==FEATURE_ENABLED
    void(*interrupt_handler) (void);
    interrupt_priority_LEVEL priority_LEVEL;
#endif
    TIMER0_clock_source_t TIMER0_clock_source;
    TIMER0_BIT_mode_t TIMER0_BIT_mode;
    TIMER0_prescaler_enable_t TIMER0_prescaler_state;
    TIMER0_prescale_vlaue_t TIMER0_prescale_vlaue;
    T0CKI_egde_t T0CKI_egde;
    uint16 TIMER0_counter_reg_value;
    
}TIMER0_config_t;

/* Section : Function Declaration*/

Std_ReturnType TIMER0_initialization (const TIMER0_config_t *TIMER0_obj);
Std_ReturnType TIMER0_denitialization (const TIMER0_config_t *TIMER0_obj);
Std_ReturnType TIMER0_read_counter_reg_vlaue (const TIMER0_config_t *TIMER0_obj , uint16 *value);
Std_ReturnType TIMER0_write_counter_reg_vlaue (const TIMER0_config_t *TIMER0_obj , uint16 value);

#endif	/* HAL_TIMER0_H */

