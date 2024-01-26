/* 
 * File:   ecu_keypad.h
 * Author: YaseenEzzat
 *
 * Created on October 29, 2023, 1:12 AM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/* Section : Includes*/
#include "ecu_keypad_config.h"
#include "../../MCAL_layer/GPIO/hal_GPIO.h"

/* Section : Macro Declaration*/
#define KEYPAD_ROWS_MAX_SIZE       4
#define KEYPAD_COLUMNS_MAX_SIZE       4

/* Section : Macro Function Declaration*/

/* Section : Data Type Declaration*/
typedef struct {
    pin_config_t keypad_rows_pins    [KEYPAD_ROWS_MAX_SIZE];
    pin_config_t keypad_columns_pins [KEYPAD_COLUMNS_MAX_SIZE];
}keypad_pins_config;

/* Section : Function Declaration*/
Std_ReturnType ECU_KEYPAD_intialization (keypad_pins_config *keypad_pins);
Std_ReturnType ECU_KEYPAD_read_value (keypad_pins_config *keypad_pins , uint8 *vlaue);




#endif	/* ECU_KEYPAD_H */

