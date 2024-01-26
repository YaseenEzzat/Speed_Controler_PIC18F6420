/* 
 * File:   hal_timer2.h
 * Author: YaseenEzzat
 *
 * Created on November 8, 2023, 11:24 AM
 */

#ifndef HAL_TIMER2_H
#define	HAL_TIMER2_H
/* Section : Includes*/

#include "hal_timer2_config.h"
#include "../../../../../Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "../GPIO/hal_GPIO.h"
#include "../INTERRUPT/mcal_internal_interrupt.h"

/* Section : Macro Declaration*/
#define TIMER_R_W_REGISTER                      TMR2
#define TIMER2_PRESCALER                        T2CONbits.T2CKPS
#define TIMER2_POSTSCALER                       T2CONbits.TOUTPS

/* Section : Macro Function Declaration*/
//  enable / disable TIMER2.
#define TIMER2_ENABLE()                              (T2CONbits.TMR2ON= 1)
#define TIMER2_DISABLE()                             (T2CONbits.TMR2ON = 0)
// set TIMER2 Prescale value.
#define TIMER2_PRESCALER_SET_VALUE(PS_VALUE)         (T2CONbits.T2CKPS = PS_VALUE)
// set TIMER2 postscale value.
#define TIMER2_POSTSCALER_SET_VALUE(PS_VALUE)        (T2CONbits.TOUTPS = PS_VALUE)

/* Section : Data Type Declaration*/
typedef enum {
    TIMER2_Prescale_value_1,               // 00 = 1     Prescale OFF
    TIMER2_Prescale_value_4,               // 01 = 4     Prescale value
    TIMER2_Prescale_value_16,              // 10 = 16    Prescale value
}TIMER2_Prescale_vlaue_t;

typedef enum {
    TIMER2_postscale_value_1_to_1 = 0,          // 0000 = 1:1   postscale OFF
    TIMER2_postscale_value_1_to_2,              // 0001 = 1:2   postscale value
    TIMER2_postscale_value_1_to_3,              // 0010 = 1:3   postscale value
    TIMER2_postscale_value_1_to_4,              // 0011 = 1:4   postscale value        
    TIMER2_postscale_value_1_to_5,              // 0100 = 1:5   postscale value        
    TIMER2_postscale_value_1_to_6,              // 0101 = 1:6   postscale value        
    TIMER2_postscale_value_1_to_7,              // 0110 = 1:7   postscale value        
    TIMER2_postscale_value_1_to_8,              // 0111 = 1:8   postscale value        
    TIMER2_postscale_value_1_to_9,              // 1000 = 1:9   postscale value
    TIMER2_postscale_value_1_to_10,             // 1001 = 1:10  postscale value
    TIMER2_postscale_value_1_to_11,             // 1010 = 1:11  postscale value        
    TIMER2_postscale_value_1_to_12,             // 1011 = 1:12  postscale value        
    TIMER2_postscale_value_1_to_13,             // 1100 = 1:13  postscale value        
    TIMER2_postscale_value_1_to_14,             // 1101 = 1:14  postscale value        
    TIMER2_postscale_value_1_to_15,             // 1110 = 1:15  postscale value        
    TIMER2_postscale_value_1_to_16              // 1111 = 1:16  postscale value        
}TIMER2_postscale_vlaue_t;






typedef struct {
#if INTERRUPT_TIMER2==FEATURE_ENABLED
    void(*TIMER2_interrupt_handler) (void);
    interrupt_priority_LEVEL priority_LEVEL;
#endif
    TIMER2_Prescale_vlaue_t TIMER2_prescale_vlaue;
    TIMER2_postscale_vlaue_t TIMER2_postscale_vlaue;
    uint8 TIMER2_counter_reg_value;       
}TIMER2_config_t;

/* Section : Function Declaration*/

Std_ReturnType TIMER2_initialization (const TIMER2_config_t *TIMER2_obj);
Std_ReturnType TIMER2_denitialization (const TIMER2_config_t *TIMER2_obj);
Std_ReturnType TIMER2_read_counter_reg_vlaue (const TIMER2_config_t *TIMER1_obj , uint8 *value);
Std_ReturnType TIMER2_write_counter_reg_vlaue (const TIMER2_config_t *TIMER1_obj , uint8 value);


#endif	/* HAL_TIMER2_H */

