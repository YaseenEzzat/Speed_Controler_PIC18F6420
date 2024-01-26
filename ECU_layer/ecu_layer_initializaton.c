/* 
 * File:   ecu_layer_initializaton.c
 * Author: YaseenEzzat
 *
 * Created on October 29, 2023, 1:08 AM
 */
#include "ecu_layer_initializaton.h"

void ecu_layer_intialization (void){
    
    ECU_KEYPAD_intialization (&keypad1);
    //ECU_LCD_8_bit_intialization(&lcd1);
    ECU_LCD_4_bit_intialization(&lcd2);
    ECU_LED_intialization(&led1);
    ECU_LED_intialization(&led2);
    ECU_MOTOR_intialization(&motor1);
    //ECU_LED_intialization(&led3);
    
}


keypad_pins_config keypad1 = {
    .keypad_rows_pins[0].DIRECTOION = GPIO_PIN_OUTPUT,
    .keypad_rows_pins[0].LOGIC =GPIO_PIN_LOW,
    .keypad_rows_pins[0].PORT = portD,
    .keypad_rows_pins[0].PIN = GPIO_PIN0,
    .keypad_rows_pins[1].DIRECTOION = GPIO_PIN_OUTPUT,
    .keypad_rows_pins[1].LOGIC =GPIO_PIN_LOW,
    .keypad_rows_pins[1].PORT = portD,
    .keypad_rows_pins[1].PIN = GPIO_PIN1,
    .keypad_rows_pins[2].DIRECTOION = GPIO_PIN_OUTPUT,
    .keypad_rows_pins[2].LOGIC =GPIO_PIN_LOW,
    .keypad_rows_pins[2].PORT = portD,
    .keypad_rows_pins[2].PIN = GPIO_PIN2,
    .keypad_rows_pins[3].DIRECTOION = GPIO_PIN_OUTPUT,
    .keypad_rows_pins[3].LOGIC =GPIO_PIN_LOW,
    .keypad_rows_pins[3].PORT = portD,
    .keypad_rows_pins[3].PIN = GPIO_PIN3,
    .keypad_columns_pins[0].DIRECTOION = GPIO_PIN_INPUT,
    .keypad_columns_pins[0].LOGIC =GPIO_PIN_LOW,
    .keypad_columns_pins[0].PORT = portD,
    .keypad_columns_pins[0].PIN = GPIO_PIN4,
    .keypad_columns_pins[1].DIRECTOION = GPIO_PIN_INPUT,
    .keypad_columns_pins[1].LOGIC =GPIO_PIN_LOW,
    .keypad_columns_pins[1].PORT = portD,
    .keypad_columns_pins[1].PIN = GPIO_PIN5,
    .keypad_columns_pins[2].DIRECTOION = GPIO_PIN_INPUT,
    .keypad_columns_pins[2].LOGIC =GPIO_PIN_LOW,
    .keypad_columns_pins[2].PORT = portD,
    .keypad_columns_pins[2].PIN = GPIO_PIN6,
    .keypad_columns_pins[3].DIRECTOION = GPIO_PIN_INPUT,
    .keypad_columns_pins[3].LOGIC =GPIO_PIN_LOW,
    .keypad_columns_pins[3].PORT = portD,
    .keypad_columns_pins[3].PIN = GPIO_PIN7

};



/*
lcd_8_bit_config_t lcd1 = {
  .RS_pin.DIRECTOION = GPIO_PIN_OUTPUT,
  .RS_pin.LOGIC = GPIO_PIN_LOW,
  .RS_pin.PORT = portD,
  .RS_pin.PIN = GPIO_PIN0,
  
  .EN_pin.DIRECTOION = GPIO_PIN_OUTPUT,
  .EN_pin.LOGIC = GPIO_PIN_LOW,
  .EN_pin.PORT = portD,
  .EN_pin.PIN = GPIO_PIN1,
  
  .DB_pins[0].DIRECTOION = GPIO_PIN_OUTPUT,
  .DB_pins[0].LOGIC = GPIO_PIN_LOW,
  .DB_pins[0].PORT = portC,
  .DB_pins[0].PIN = GPIO_PIN0,
  
  .DB_pins[1].DIRECTOION = GPIO_PIN_OUTPUT,
  .DB_pins[1].LOGIC = GPIO_PIN_LOW,
  .DB_pins[1].PORT = portC,
  .DB_pins[1].PIN = GPIO_PIN1,
  
  .DB_pins[2].DIRECTOION = GPIO_PIN_OUTPUT,
  .DB_pins[2].LOGIC = GPIO_PIN_LOW,
  .DB_pins[2].PORT = portC,
  .DB_pins[2].PIN = GPIO_PIN2,
  
  .DB_pins[3].DIRECTOION = GPIO_PIN_OUTPUT,
  .DB_pins[3].LOGIC = GPIO_PIN_LOW,
  .DB_pins[3].PORT = portC,
  .DB_pins[3].PIN = GPIO_PIN3,
  
  .DB_pins[4].DIRECTOION = GPIO_PIN_OUTPUT,
  .DB_pins[4].LOGIC = GPIO_PIN_LOW,
  .DB_pins[4].PORT = portC,
  .DB_pins[4].PIN = GPIO_PIN4,
  
  .DB_pins[5].DIRECTOION = GPIO_PIN_OUTPUT,
  .DB_pins[5].LOGIC = GPIO_PIN_LOW,
  .DB_pins[5].PORT = portC,
  .DB_pins[5].PIN = GPIO_PIN5,
  
  .DB_pins[6].DIRECTOION = GPIO_PIN_OUTPUT,
  .DB_pins[6].LOGIC = GPIO_PIN_LOW,
  .DB_pins[6].PORT = portC,
  .DB_pins[6].PIN = GPIO_PIN6,
  
  .DB_pins[7].DIRECTOION = GPIO_PIN_OUTPUT,
  .DB_pins[7].LOGIC = GPIO_PIN_LOW,
  .DB_pins[7].PORT = portC,
  .DB_pins[7].PIN = GPIO_PIN7
       
};
*/

lcd_4_bit_config_t lcd2 = {
  .RS_pin.DIRECTOION = GPIO_PIN_OUTPUT,
  .RS_pin.LOGIC = GPIO_PIN_LOW,
  .RS_pin.PORT = portB,
  .RS_pin.PIN = GPIO_PIN0,
  
  .EN_pin.DIRECTOION = GPIO_PIN_OUTPUT,
  .EN_pin.LOGIC = GPIO_PIN_LOW,
  .EN_pin.PORT = portB,
  .EN_pin.PIN = GPIO_PIN1,
  
  .DB_pins[0].DIRECTOION = GPIO_PIN_OUTPUT,
  .DB_pins[0].LOGIC = GPIO_PIN_LOW,
  .DB_pins[0].PORT = portB,
  .DB_pins[0].PIN = GPIO_PIN2,
  
  .DB_pins[1].DIRECTOION = GPIO_PIN_OUTPUT,
  .DB_pins[1].LOGIC = GPIO_PIN_LOW,
  .DB_pins[1].PORT = portB,
  .DB_pins[1].PIN = GPIO_PIN3,
  
  .DB_pins[2].DIRECTOION = GPIO_PIN_OUTPUT,
  .DB_pins[2].LOGIC = GPIO_PIN_LOW,
  .DB_pins[2].PORT = portB,
  .DB_pins[2].PIN = GPIO_PIN4,
  
  .DB_pins[3].DIRECTOION = GPIO_PIN_OUTPUT,
  .DB_pins[3].LOGIC = GPIO_PIN_LOW,
  .DB_pins[3].PORT = portB,
  .DB_pins[3].PIN = GPIO_PIN5
};


led_config_t led1 = {
  .logic = GPIO_PIN_LOW,
  .pin_num = GPIO_PIN0,
  .port = portC
};

led_config_t led2 = {
  .logic = GPIO_PIN_LOW,
  .pin_num = GPIO_PIN1,
  .port = portC
}; 

/*led_config_t led3 = {
  .logic = GPIO_PIN_LOW,
  .pin_num = GPIO_PIN2,
  .port = portC
}; */

motor_pins_config_t motor1 ={
    .BKD_PIN.logic = GPIO_PIN_LOW,
    .BKD_PIN.pin_num = GPIO_PIN7,
    .BKD_PIN.port = portC,
    .FWD_PIN.logic = GPIO_PIN_LOW,
    .FWD_PIN.pin_num = GPIO_PIN6,
    .FWD_PIN.port = portC,

};