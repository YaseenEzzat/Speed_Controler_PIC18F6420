/* 
 * File:   _7_segment.c
 * Author: YaseenEzzat
 *
 * Created on October 27, 2023, 10:30 AM
 */


#include "_7_segment.h"

/**
 * 
 * @param segment_pins
 * @return 
 */
Std_ReturnType ECU_7_SEGMENT_intialization(const segment_pins_config_t *segment_pins){
   
    Std_ReturnType ret = E_NOT_OK;
    if (NULL==segment_pins)
    {
        ret = E_NOT_OK;
    }
    else
    {
        GPIO_PIN_directoin_intialization(&(segment_pins->pin0));
        GPIO_PIN_directoin_intialization(&(segment_pins->pin1));
        GPIO_PIN_directoin_intialization(&(segment_pins->pin2));
        GPIO_PIN_directoin_intialization(&(segment_pins->pin3));    
    }
    
    return ret;
}

/**
 * 
 * @param segment_pins
 * @return 
 */
 Std_ReturnType ECU_7_SEGMENT_write_value(const segment_pins_config_t *segment_pins , uint8 value){
    
    Std_ReturnType ret = E_NOT_OK;
    if (NULL==segment_pins)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
        GPIO_PIN_write_logic(&(segment_pins->pin0) ,(value & 0x01));
        GPIO_PIN_write_logic(&(segment_pins->pin1) ,((value>>1)& 0x01));
        GPIO_PIN_write_logic(&(segment_pins->pin2) ,((value>>2)& 0x01));
        GPIO_PIN_write_logic(&(segment_pins->pin3) ,((value>>3)& 0x01));
    }
    
    return ret;
    
}
