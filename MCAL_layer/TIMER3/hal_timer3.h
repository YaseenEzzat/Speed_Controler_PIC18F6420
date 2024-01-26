/* 
 * File:   hal_timer3.h
 * Author: YaseenEzzat
 *
 * Created on November 8, 2023, 1:03 PM
 */

#ifndef HAL_TIMER3_H
#define	HAL_TIMER3_H

/* Section : Includes*/

#include "hal_timer3_config.h"
#include "../../../../../Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "../GPIO/hal_GPIO.h"
#include "../INTERRUPT/mcal_internal_interrupt.h"

/* Section : Macro Declaration*/
#define TIMER3_LOW_REGISTER                    TMR3L
#define TIMER3_HIGH_REGISTER                   TMR3H
#define TIMER3_PRESCALER                       T3CONbits.T3CKPS
#define TIMER3_CLK_SOURCE                      T3CONbits.TMR3CS
/* Section : Macro Function Declaration*/
//  enable / disable TIMER3.
#define TIMER3_ENABLE()                              (T3CONbits.TMR3ON = 1)
#define TIMER3_DISABLE()                             (T3CONbits.TMR3ON = 0)
// select TIMER3 clock source.
#define TIMER3_INTERNAL_CLK_SOURCE()                 (T3CONbits.TMR3CS = 0)
#define TIMER3_EXTERNAL_CLK_SOURCE_T13CKI()          (T3CONbits.TMR3CS = 1)
// select TIMER3 read and write BIT mode.
#define TIMER3_ENABLE_8BIT_MODE()                    (T3CONbits.RD16 = 0)
#define TIMER3_ENABLE_16BIT_MODE()                   (T3CONbits.RD16 = 0)
// set TIMER3 Prescale value.
#define TIMER3_PRESCALER_SET_VALUE(PS_VALUE)         (T3CONbits.T3CKPS = PS_VALUE)
// select TIMER3 synchronization mode.
#define TIMER3_EXTERNAL_CLK_SOURCE_SYNCHROINZE()     (T3CONbits.NOT_T3SYNC= 0)
#define TIMER3_EXTERNAL_CLK_SOURCE_ASYNCHROINZE()    (T3CONbits.NOT_T3SYNC= 0)
/* Section : Data Type Declaration*/

typedef enum {
    TIMER1_is_the_capture_clock_source_for_the_CCP,
    TIMER1_is_the_capture_clock_source_for_the_CCP1        
}TIMER3_CCPx_Enable_t;
    
            
typedef enum {
    TIMER3_Prescale_value_1_to_1 = 0,          // 00 = 1:1   Prescale OFF
    TIMER3_Prescale_value_1_to_2,              // 01 = 1:2   Prescale value
    TIMER3_Prescale_value_1_to_4,              // 10 = 1:4   Prescale value
    TIMER3_Prescale_value_1_to_8               // 11 = 1:8   Prescale value
}TIMER3_prescale_vlaue_t;

typedef enum {
    T3CKI_synchronize,
    T3CKI_asynchronize
}T3CKI_synchronization_t;

typedef enum {
    TIMER3_16_BIT_mode,
    TIMER3_8_BIT_mode
}TIMER3_BIT_mode_t;

typedef enum {
    TIMER3_internal_clk_source,
    TIMER3_external_clk_source
}TIMER3_clock_source_t;

typedef struct {
#if INTERRUPT_TIMER3==FEATURE_ENABLED
    void(*TIMER3_interrupt_handler) (void);
    interrupt_priority_LEVEL priority_LEVEL;
#endif
    TIMER3_clock_source_t TIMER3_clock_source;
    TIMER3_BIT_mode_t TIMER3_BIT_mode;
    TIMER3_prescale_vlaue_t TIMER3_prescale_vlaue;
    T3CKI_synchronization_t TIMER3_synchronization;
    uint16 TIMER3_counter_reg_value;       
}TIMER3_config_t;

/* Section : Function Declaration*/

Std_ReturnType TIMER3_initialization (const TIMER3_config_t *TIMER3_obj);
Std_ReturnType TIMER3_denitialization (const TIMER3_config_t *TIMER3_obj);
Std_ReturnType TIMER3_read_counter_reg_vlaue (const TIMER3_config_t *TIMER3_obj , uint16 *value);
Std_ReturnType TIMER3_write_counter_reg_vlaue (const TIMER3_config_t *TIMER3_obj , uint16 value);

#endif	/* HAL_TIMER3_H */

