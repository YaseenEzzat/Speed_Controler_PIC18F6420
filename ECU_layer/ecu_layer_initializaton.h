/* 
 * File:   ecu_layer_initializaton.h
 * Author: YaseenEzzat
 *
 * Created on October 29, 2023, 1:08 AM
 */

#ifndef ECU_LAYER_INITIALIZATON_H
#define	ECU_LAYER_INITIALIZATON_H

/* Section : Includes*/
#include "LED/ecu_led.h"
#include "PUSH_BUTTON/ecu_push_button.h"
#include "RELAY/ecu_relay.h"
#include "MOTOR/ecu_motor.h"
#include "_7_SEGMENT/_7_segment.h"
#include "KEYPAD/ecu_keypad.h"
#include "CHAR_LCD/ecu_char_lcd.h"

/* Section : Macro Declaration*/

/* Section : Macro Function Declaration*/

/* Section : Data Type Declaration*/

/*
extern pin_config_t pin1;
extern pin_config_t pin2;

extern led_config_t led1;
*/

//extern lcd_8_bit_config_t lcd1 ;
extern lcd_4_bit_config_t lcd2 ;
extern led_config_t led1;
extern led_config_t led2;
//extern led_config_t led3;
extern keypad_pins_config keypad1;
extern motor_pins_config_t motor1;

/* Section : Function Declaration*/

void ecu_layer_intialization (void);

#endif	/* ECU_LAYER_INITIALIZATON_H */

