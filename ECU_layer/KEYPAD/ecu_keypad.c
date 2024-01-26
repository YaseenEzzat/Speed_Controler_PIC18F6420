/* 
 * File:   ecu_keypad.c
 * Author: YaseenEzzat
 *
 * Created on October 29, 2023, 1:12 AM
 */

#include "ecu_keypad.h"

static const uint8 keypad_values [KEYPAD_ROWS_MAX_SIZE][KEYPAD_COLUMNS_MAX_SIZE] = {{'7','8','9','/'},
                                                                                    {'4','5','6','*'},
                                                                                    {'1','2','3','-'},
                                                                                    {'c','0','=','+'}
    
};





/**
 * 
 * @param keypad_pins
 * @return 
 */
Std_ReturnType ECU_KEYPAD_intialization (keypad_pins_config *keypad_pins){
    Std_ReturnType ret =E_NOT_OK;
    uint8 rows_counter = 0;
    uint8 columns_counter = 0;
    if(NULL==keypad_pins)
        {
            ret =E_NOT_OK;
        }
    else 
        {
            for(rows_counter = 0 ; rows_counter<KEYPAD_ROWS_MAX_SIZE ; rows_counter++)
            {
                ret = GPIO_PIN_directoin_intialization (&(keypad_pins->keypad_rows_pins[rows_counter]));
            }
            for(columns_counter = 0 ; columns_counter<KEYPAD_COLUMNS_MAX_SIZE ; columns_counter++)
            {
               ret = GPIO_PIN_directoin_intialization (&(keypad_pins->keypad_columns_pins[columns_counter]));
            }
            ret =E_OK;
        }
    return ret;
}

/**
 * 
 * @param keypad_pins
 * @param vlaue
 * @return 
 */
Std_ReturnType ECU_KEYPAD_read_value (keypad_pins_config *keypad_pins , uint8 *vlaue){
    Std_ReturnType ret =E_NOT_OK;
    uint8 rows_counter = 0;
    uint8 columns_counter = 0;
    uint8 init_counter =0;
    pin_logic_t pin_logic = GPIO_PIN_LOW ;
    if(NULL==keypad_pins)
        {
            ret =E_NOT_OK;
        }
    else 
        {
            for(rows_counter = 0 ; rows_counter<KEYPAD_ROWS_MAX_SIZE ; rows_counter++)
            {
                for(init_counter = 0 ; init_counter < KEYPAD_ROWS_MAX_SIZE ;init_counter++)
                {
                    ret = GPIO_PIN_write_logic(&(keypad_pins->keypad_rows_pins[init_counter]),GPIO_PIN_LOW);
                }
                GPIO_PIN_write_logic(&(keypad_pins->keypad_rows_pins[rows_counter]),GPIO_PIN_HIGH);
                for(columns_counter = 0 ; columns_counter<KEYPAD_COLUMNS_MAX_SIZE ; columns_counter++)
                {
                    ret = GPIO_PIN_read_logic (&(keypad_pins->keypad_columns_pins[columns_counter]),&pin_logic );
                    if(pin_logic == GPIO_PIN_HIGH)
                {
                    *vlaue = keypad_values [rows_counter][columns_counter];
                }
                }

            }
            ret =E_OK;
        }
    return ret;
}