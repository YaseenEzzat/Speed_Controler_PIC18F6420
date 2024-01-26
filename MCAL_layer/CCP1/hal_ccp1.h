/* 
 * File:   hal_ccp1.h
 * Author: YaseenEzzat
 *
 * Created on November 9, 2023, 11:37 AM
 */

#ifndef HAL_CCP1_H
#define	HAL_CCP1_H

/* Section : Includes*/
#include "hal_ccp1_config.h"
#include "../../../../../Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "../GPIO/hal_GPIO.h"
#include "../INTERRUPT/mcal_internal_interrupt.h"


/* Section : Macro Declaration*/
#define CCP1_HIGH_REG           CCPR1H
#define CCP1_LOW_REG            CCPR1L
/* Section : Macro Function Declaration*/

#define CCP1_SET_MODULE_TIMER_SOURCE_T3CCP1_BIT(BIT1)       (T3CONbits.T3CCP1 = BIT1)
#define CCP1_SET_MODULE_TIMER_SOURCE_T3CCP2_BIT(BIT2)       (T3CONbits.T3CCP2 = BIT2)

/******************************capture mode start******************************/
#if CCP1_CAPTURE_MODE_STATUS==ENABLE
#define CCP1_SET_CAPTURE_MODE(CAPTURE)                      (CCP1CONbits.CCP1M=CAPTURE)
#define CCP1_CAPTURE_MODE_DISABLE()                         (CCP1CONbits.CCP1M = 0)
#endif
/******************************capture mode end********************************/
/******************************compare mode start******************************/
#if CCP1_COPMPARE_MODE_STATUS==ENABLE
#define CCP1_SET_COMPARE_MODE(COPMPARE)                      (CCP1CONbits.CCP1M = COPMPARE)
#define CCP1_COMPARE_MODE_DISABLE()                          (CCP1CONbits.CCP1M = 0) 
#endif
/******************************compare mode end********************************/
/******************************PWM mode start**********************************/
#if CCP1_PWM_MODE_STATUS==ENABLE
#define CCP1_PWM_ENABLE()                                     (CCP1CONbits.CCP1M = 0X0C)
#define CCP1_PWM_DISABLE()                                    (CCP1CONbits.CCP1M = 0X00)
#endif
/******************************PWM mode end************************************/


/* Section : Data Type Declaration*/
/******************************capture mode start******************************/
#if CCP1_CAPTURE_MODE_STATUS==ENABLE
typedef enum {
    capture_mode_disabled = 0x0,        
    capture_mode_every_falling_edge = 0x04,
    capture_mode_every_rising_edge = 0x05,
    capture_mode_every_4th_rising_edge = 0x06,
    capture_mode_every_16th_rising_edge = 0x07,   
}capture_mode_config_t;
#endif
/******************************capture mode end********************************/
/******************************compare mode start******************************/
#if CCP1_COPMPARE_MODE_STATUS==ENABLE
typedef enum {
    Compare_mode_disabled = 0x0,        
    Compare_mode_toggle_output_CCP1_PIN = 0x02,
    Compare_mode_initialize_CCP1_pin_low = 0x08,
    Compare_mode_initialize_CCP1_pin_high = 0x09,
    Compare_mode_generate_software_interrupt = 0x0A,
    Compare_mode_reset_timer_start_ADC = 0x0B,     
}compare_mode_config_t;
#endif
/******************************compare mode end********************************/
/******************************PWM mode start**********************************/
#if CCP1_PWM_MODE_STATUS==ENABLE

#endif
/******************************PWM mode end************************************/
typedef enum {
    timer1,
    timer3
}CCP1_timer_src_t;
typedef struct {
    #if INTERRUPT_CCP1==FEATURE_ENABLED
    void(*CCP1_interrupt_handler) (void);
    interrupt_priority_LEVEL priority_LEVEL;
    #endif
    #if CCP1_CAPTURE_MODE_STATUS==ENABLE
    capture_mode_config_t  capture_config;
    CCP1_timer_src_t capture_timer_src;
    #endif
    #if CCP1_COPMPARE_MODE_STATUS==ENABLE
    compare_mode_config_t  compare_config;
    CCP1_timer_src_t compare_timer_src;
    uint16 preload_value;
    #endif
    #if CCP1_PWM_MODE_STATUS==ENABLE
    uint32 PWM_frequency;
    uint8 defualt_PWM_duty_cycle;
    uint8 Prescale_vlaue :3 ;
    uint8 postscale_vlaue :5 ; 
    #endif
}CCP1_config_t;

/* Section : Function Declaration*/
#if CCP1_CAPTURE_MODE_STATUS==ENABLE
Std_ReturnType CCP1_capture_mode_initialization (const CCP1_config_t *CCP1_cfg );
Std_ReturnType CCP1_capture_mode_deinitialization (const CCP1_config_t *CCP1_cfg );
Std_ReturnType CCP1_capture_read_value(const CCP1_config_t *CCP1_cfg , uint16 *cptured_value);
#endif
#if CCP1_COPMPARE_MODE_STATUS==ENABLE
Std_ReturnType CCP1_compare_mode_initialization (const CCP1_config_t *CCP1_cfg );
Std_ReturnType CCP1_compare_mode_deitialization (const CCP1_config_t *CCP1_cfg );
Std_ReturnType CCP1_compare_mode_set_preload_value (const CCP1_config_t *CCP1_cfg ,uint16 preload_value);
#endif
#if CCP1_PWM_MODE_STATUS==ENABLE
Std_ReturnType CCP1_PWM_mode_initialization (const CCP1_config_t *CCP1_cfg );
Std_ReturnType CCP1_PWM_mode_deinitialization (const CCP1_config_t *CCP1_cfg );
Std_ReturnType CCP1_PWM_START (const CCP1_config_t *CCP1_cfg );
Std_ReturnType CCP1_PWM_STOP (const CCP1_config_t *CCP1_cfg );
Std_ReturnType CCP1_PWM_mode_set_duty_cycle (const CCP1_config_t *CCP1_cfg , uint8 duty_cycle_value );
#endif


#endif	/* HAL_CCP1_H */

