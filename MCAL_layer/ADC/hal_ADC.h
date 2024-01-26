/* 
 * File:   hal_ADC.h
 * Author: YaseenEzzat
 *
 * Created on November 4, 2023, 1:44 AM
 */

#ifndef HAL_ADC_H
#define	HAL_ADC_H
/*
 The following steps should be followed to perform an A/D
conversion:
1. Configure the A/D module:
? Configure analog pins, voltage reference and
digital I/O (ADCON1)
? Select A/D input channel (ADCON0)
? Select A/D acquisition time (ADCON2)
? Select A/D conversion clock (ADCON2)
? Turn on A/D module (ADCON0)
2. Configure A/D interrupt (if desired):
? Clear ADIF bit 
? Set ADIE bit 
? Set GIE bit 
3. Wait the required acquisition time (if required).
4. Start conversion:
? Set GO/DONE bit (ADCON0 register)
 */

/* Section : Includes*/
#include "hal_ADC_confing.h"
#include "../../../../../Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "../GPIO/hal_GPIO.h"
#include "../INTERRUPT/mcal_interrupt_config.h"
#include "../INTERRUPT/mcal_internal_interrupt.h"

/* Section : Macro Declaration*/
#define ADC_CONVERSION_STATEUS                              (ADCON0bits.GODONE)



/* Section : Macro Function Declaration*/
#define ADC_CONVERTER_MODULE_ENABLE()                       (ADCON0bits.ADON=1)
#define ADC_CONVERTER_MODULE_DISABLE()                      (ADCON0bits.ADON=0)

#define ADC_CONVERSION_START()                              (ADCON0bits.GODONE=1)

//Select ADC Channel using ADC_channel_t enum
#define ADC_CHANNEL_SELECT(CHANNEL)                         (ADCON0bits.CHS=CHANNEL)
//Use MCU voltage as voltage reference
#define ADC_VOLTAGE_REFERENCE_INTERNAL_Vss()                (ADCON1bits.VCFG1=0) 
#define ADC_VOLTAGE_REFERENCE_INTERNAL_VDD()                (ADCON1bits.VCFG0=0)                                              
//Use an external voltage source as voltage reference connected to (AN2 - ) (AN2 3 )
#define ADC_VOLTAGE_REFERENCE_EXTERNAL_AN2()                (ADCON1bits.VCFG1=1)
#define ADC_VOLTAGE_REFERENCE_EXTERNAL_AN3()                (ADCON1bits.VCFG0=1)
//Set A/D pins using ADC_pins_config_t enum                    
#define ADC_PINS_CONFIGERATION(CONFIG)                      (ADCON1bits.PCFG = CONFIG)

#define ADC_RESULT_RIGHT_JUSTIFIED()                        (ADCON2bits.ADFM= 1)
#define ADC_RESULT_LEFT_JUSTIFIED()                         (ADCON2bits.ADFM= 0)

//A/D Conversion Clock Select bits using ADC_CLOCK_t enum
#define ADC_CONVERSION_CLCK_SELECT(CLCK)                    (ADCON2bits.ADCS = CLCK)
//A/D Acquisition Time Select bits using ADC_Acquisition_time_t enum
#define ADC_CONVERSION_ACQUISITION_TIME_SELECT(ACQU)        (ADCON2bits.ACQT = ACQU)



/* Section : Data Type Declaration*/
typedef enum {
    Channel_0 = 0X00,    //(AN0)
    Channel_1,           //(AN1)
    Channel_2,           //(AN2)
    Channel_3,           //(AN3)
    Channel_4,           //(AN4)
    Channel_5,           //(AN5)
    Channel_6,           //(AN6)
    Channel_7,           //(AN7)
    Channel_8,           //(AN8)
    Channel_9,           //(AN9)
    Channel_10 = 0x0A,   //(AN10)
    Channel_11 = 0x0B,   //(AN11)
    Channel_12 = 0x0C    //(AN12)
}ADC_channel_t;

typedef enum {
    config_0 = 0X00,    //(AN0 : AN12) A
    config_1,           //(AN0 : AN12) A
    config_2,           //(AN0 : AN12) A
    config_3,           //(AN0 : AN11) A   , (AN12) D
    config_4,           //(AN0 : AN10) A   , (AN11 : AN12) D
    config_5,           //(AN0 : AN9 ) A   , (AN10 : AN12) D
    config_6,           //(AN0 : AN8 ) A   , (AN9  : AN12) D
    config_7,           //(AN0 : AN7 ) A   , (AN8  : AN12) D
    config_8,           //(AN0 : AN6 ) A   , (AN7  : AN12) D
    config_9,           //(AN0 : AN5 ) A   , (AN6  : AN12) D
    config_10 = 0x0A,   //(AN0 : AN4 ) A   , (AN5  : AN12) D
    config_11 = 0x0B,   //(AN0 : AN3 ) A   , (AN4  : AN12) D
    config_12 = 0x0C,   //(AN0 : AN2 ) A   , (AN3  : AN12) D
    config_13 = 0x0D,   //(AN0 : AN1 ) A   , (AN2  : AN12) D
    config_14 = 0x0E,   //(AN0)        A   , (AN1  : AN12) D
    config_15 = 0x0F,   //(AN0 : AN12) D
}ADC_pins_config_t;

typedef enum {
    ADC_Acquisition_TIME_0_TAD  = 0,
    ADC_Acquisition_TIME_2_TAD,
    ADC_Acquisition_TIME_4_TAD,
    ADC_Acquisition_TIME_6_TAD,
    ADC_Acquisition_TIME_8_TAD,
    ADC_Acquisition_TIME_12_TAD,
    ADC_Acquisition_TIME_16_TAD,
    ADC_Acquisition_TIME_20_TAD          
}ADC_Acquisition_time_t;

typedef enum {
    ADC_CLOCK_FRC = 0X7,
    ADC_CLOCK_FOSC_64 = 0X6,
    ADC_CLOCK_FOSC_32 = 0X2,
    ADC_CLOCK_FOSC_16 = 0X5
}ADC_CLOCK_t;
typedef enum {
    left_result_justified,
    right_result_justified
}ADC_result_format_t;

typedef enum {
    voltage_reference_internal,
    voltage_reference_external
}voltage_reference_t;

typedef struct {
    #if INTERRUPT_ADC==FEATURE_ENABLED
    void (*ADC_INTRRUPT_HANDLER)(void);
    interrupt_priority_LEVEL priority;
    #endif
    ADC_channel_t channel;   //default channel
    ADC_pins_config_t pins;
    ADC_CLOCK_t CLCK_SELECT;
    ADC_Acquisition_time_t Acquisition_time;
    voltage_reference_t voltage_reference;
    ADC_result_format_t result_format;
}ADC_config_t;

/* Section : Function Declaration*/
Std_ReturnType ADC_initialization (const ADC_config_t *ADC_obj);
Std_ReturnType ADC_start_conversion (const ADC_config_t *ADC_obj);
Std_ReturnType ADC_deinitialization (const ADC_config_t *ADC_obj);
Std_ReturnType ADC_read_converted_value (const ADC_config_t *ADC_obj , uint16 *value);
Std_ReturnType ADC_SELECT_CHANNEL (const ADC_config_t *ADC_obj , ADC_channel_t CHANNEL);
Std_ReturnType ADC_select_convert_read_blocking (const ADC_config_t *ADC_obj 
                                                 , ADC_channel_t CHANNEL , uint16 *value);
Std_ReturnType ADC_select_convert_interrupt (const ADC_config_t *ADC_obj , ADC_channel_t CHANNEL );



#endif	/* HAL_ADC_H */

