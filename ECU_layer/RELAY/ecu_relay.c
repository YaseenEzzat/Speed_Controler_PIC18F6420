/* 
 * File:   ecu_relay.c
 * Author: YaseenEzzat
 *
 * Created on October 26, 2023, 10:36 AM
 */
#include "ecu_relay.h"


/**
 * 
 * @param relay_config
 * @return 
 */
Std_ReturnType ECU_RELAY_intialization(const relay_config_t *relay_config){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==relay_config)
        {
            ret = E_NOT_OK;
        }
    else
        {
        pin_config_t pin_config = {relay_config->port ,relay_config->pin_num 
                     ,relay_config->logic ,GPIO_PIN_OUTPUT};
            GPIO_PIN_directoin_intialization (&pin_config);
            
            ret = E_OK;
        }
    return ret;
    
}

/**
 * 
 * @param relay_config
 * @return 
 */
Std_ReturnType ECU_RELAY_turn_on(const relay_config_t *relay_config){
 Std_ReturnType ret = E_NOT_OK;
    if(NULL==relay_config)
        {
            ret = E_NOT_OK;
        }
    else
        {
        pin_config_t pin_config = {relay_config->port ,relay_config->pin_num 
                     ,relay_config->logic ,GPIO_PIN_OUTPUT};
            GPIO_PIN_write_logic (&pin_config ,GPIO_PIN_HIGH);
            
            ret = E_OK;
        }
    return ret;
    
}

/**
 * 
 * @param relay_config
 * @return 
 */
Std_ReturnType ECU_RELAY_turn_off(const relay_config_t *relay_config){
     Std_ReturnType ret = E_NOT_OK;
    if(NULL==relay_config)
        {
            ret = E_NOT_OK;
        }
    else
        {
        pin_config_t pin_config = {relay_config->port ,relay_config->pin_num 
                     ,relay_config->logic ,GPIO_PIN_OUTPUT};
            GPIO_PIN_write_logic (&pin_config ,GPIO_PIN_LOW);
            
            ret = E_OK;
        }
    return ret;
}
