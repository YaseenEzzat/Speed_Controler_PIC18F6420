/* 
 * File:   application.h
 * Author: YaseenEzzat
 *
 * Created on October 22, 2023, 12:08 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H


/* Section : Includes*/
#include "ECU_layer/ecu_layer_initializaton.h"
#include "MCAL_layer/INTERRUPT/mcal_external_interrupt.h"
#include "MCAL_layer/EEPROM/hal_eeprom.h"
#include "MCAL_layer/ADC/hal_ADC.h"
#include "MCAL_layer/TIMER0/hal_timer0.h"
#include "MCAL_layer/TIMER1/hal_timer1.h"
#include "MCAL_layer/TIMER2/hal_timer2.h"
#include "MCAL_layer/TIMER3/hal_timer3.h"
#include "MCAL_layer/CCP1/hal_ccp1.h"
#include "MCAL_layer/USART/hal_usart.h"
#include "MCAL_layer/SPI/hal_spi.h"
#include "MCAL_layer/I2C/i2c_master_example.h"
/* Section : Macro Declaration*/


/* Section : Macro Function Declaration*/

/* Section : Data Type Declaration*/
Std_ReturnType ret = E_NOT_OK;
/* Section : Function Declaration*/
void application_intialization (void);


#endif	/* APPLICATION_H */

