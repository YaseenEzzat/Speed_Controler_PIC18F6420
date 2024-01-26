/* 
 * File:   ecu_push_button.c
 * Author: YaseenEzzat
 *
 * Created on October 26, 2023, 3:30 AM
 */

#include "ecu_push_button.h"

Std_ReturnType ECU_BUTTON_intialization (const button_config_t *button_config){
    Std_ReturnType ret = E_OK;
    if(NULL== button_config)
    {
        ret=E_NOT_OK;
    }
    else
    {
        GPIO_PIN_directoin_intialization (&(button_config->pin_config));
    }
    return ret;

}
Std_ReturnType ECU_BUTTON_read (const button_config_t *button_config ,button_status_t *button_status){
    Std_ReturnType ret = E_OK;
    pin_logic_t pin_logic = GPIO_PIN_LOW ;
    if(NULL== button_config)
    {
        ret=E_NOT_OK;
    }
    else
    {
        GPIO_PIN_read_logic (&(button_config->pin_config) , &pin_logic );
      
        if(button_config->button_connection == BUTTON_ACTIVE_HIGH)
        {
            if (pin_logic == GPIO_PIN_HIGH )
            {
                *button_status = PRESSED;
            }
            else if (pin_logic == GPIO_PIN_LOW )
            {
                *button_status = RELEASED;
            }
            else
            {ret=E_NOT_OK;}
                
        }
        else if(button_config->button_connection == BUTTON_ACTIVE_LOW)
        {
            if (pin_logic == GPIO_PIN_HIGH )
            {
                *button_status = RELEASED;
            }
            else if (pin_logic == GPIO_PIN_LOW )
            {
                *button_status = PRESSED;
            }
            else
            {ret=E_NOT_OK;}
                
        }
    }
    return ret;
    

}

