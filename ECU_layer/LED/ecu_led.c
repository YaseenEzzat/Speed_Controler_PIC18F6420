/* 
 * File:   ecu_led.c
 * Author: YaseenEzzat
 *
 * Created on October 22, 2023, 12:02 PM
 */
#include"ecu_led.h"

/**
 * 
 * @param led_config
 * @return 
 */
 Std_ReturnType ECU_LED_intialization(const led_config_t *led_config){
     Std_ReturnType ret = E_OK;
    if(NULL==led_config)
    {
        ret=E_NOT_OK;
    }
    else
    { pin_config_t led = {
        .PORT = led_config->port,
        .PIN = led_config->pin_num,
        .LOGIC = led_config->logic,
        .DIRECTOION = GPIO_PIN_OUTPUT
        };
        GPIO_PIN_intialization(&led);
    }
     return ret;
 }
 
 
 /**
  * 
  * @param led_config
  * @return 
  */
 Std_ReturnType ECU_LED_turn_on(const led_config_t *led_config){
     Std_ReturnType ret = E_OK;
    if(NULL==led_config)
    {
        ret=E_NOT_OK;
    }
    else
    { pin_config_t led = {
        .PORT = led_config->port,
        .PIN = led_config->pin_num,
        .LOGIC = led_config->logic,
        .DIRECTOION = GPIO_PIN_OUTPUT
        };
        GPIO_PIN_write_logic(&led ,GPIO_PIN_HIGH);
    }
          return ret;

 }
     

 
 /**
  * 
  * @param led_config
  * @return 
  */
 Std_ReturnType ECU_LED_turn_off(const led_config_t *led_config){
     Std_ReturnType ret = E_OK;
    if(NULL==led_config)
    {
        ret=E_NOT_OK;
    }
    else
    { pin_config_t led = {
        .PORT = led_config->port,
        .PIN = led_config->pin_num,
        .LOGIC = led_config->logic,
        .DIRECTOION = GPIO_PIN_OUTPUT
        };
        GPIO_PIN_write_logic(&led ,GPIO_PIN_LOW);
    }
          return ret;
 }
 
 /**
  * 
  * @param led_config
  * @return 
  */
 Std_ReturnType ECU_LED_turn_toggle(const led_config_t *led_config){
     Std_ReturnType ret = E_OK;
    if(NULL==led_config)
    {
        ret=E_NOT_OK;
    }
    else
    { pin_config_t led = {
        .PORT = led_config->port,
        .PIN = led_config->pin_num,
        .LOGIC = led_config->logic,
        .DIRECTOION = GPIO_PIN_OUTPUT
        };
        GPIO_PIN_toggle(&led);
    }
          return ret;
 }
     
 