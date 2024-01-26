
/* 
 * File:   ecu_motor.c
 * Author: YaseenEzzat
 *
 * Created on October 27, 2023, 12:58 AM
 */
#include "ecu_motor.h"

/**
 * 
 * @param relay_config
 * @return 
 */
 Std_ReturnType ECU_MOTOR_intialization(const motor_pins_config_t *motor_config){
    Std_ReturnType ret = E_NOT_OK;
    pin_config_t pin1;
    pin_config_t pin2;
   if(NULL==motor_config)
   {
       ret = E_NOT_OK;
   }
   else
   {
       pin1.DIRECTOION = GPIO_PIN_OUTPUT;
       pin1.LOGIC = motor_config->FWD_PIN.logic;
       pin1.PIN = motor_config->FWD_PIN.pin_num;
       pin1.PORT = motor_config->FWD_PIN.port;
       pin2.DIRECTOION = GPIO_PIN_OUTPUT;
       pin2.LOGIC = motor_config->BKD_PIN.logic;
       pin2.PIN = motor_config->BKD_PIN.pin_num;
       pin2.PORT = motor_config->BKD_PIN.port;
       
       GPIO_PIN_directoin_intialization(&pin1);
       GPIO_PIN_directoin_intialization(&pin2);         
   }
   return ret;
 }
 
 /**
  * 
  * @param relay_config
  * @return 
  */
 Std_ReturnType ECU_MOTOR_turn_forward(const motor_pins_config_t *motor_config){
   Std_ReturnType ret = E_NOT_OK;
    pin_config_t pin1;
    pin_config_t pin2;
   if(NULL==motor_config)
   {
       ret = E_NOT_OK;
   }
   else
   {
       pin1.DIRECTOION = GPIO_PIN_OUTPUT;
       pin1.LOGIC = motor_config->FWD_PIN.logic;
       pin1.PIN = motor_config->FWD_PIN.pin_num;
       pin1.PORT = motor_config->FWD_PIN.port;
       pin2.DIRECTOION = GPIO_PIN_OUTPUT;
       pin2.LOGIC = motor_config->BKD_PIN.logic;
       pin2.PIN = motor_config->BKD_PIN.pin_num;
       pin2.PORT = motor_config->BKD_PIN.port;
       
       GPIO_PIN_write_logic(&pin1 , GPIO_PIN_HIGH);
       GPIO_PIN_write_logic(&pin2 , GPIO_PIN_LOW);
   }
   return ret;
 }
 
 /**
  * 
  * @param relay_config
  * @return 
  */
 Std_ReturnType ECU_RELAY_turn_backword(const motor_pins_config_t *motor_config){
    Std_ReturnType ret = E_NOT_OK;
    pin_config_t pin1;
    pin_config_t pin2;
   if(NULL==motor_config)
   {
       ret = E_NOT_OK;
   }
   else
   {
       pin1.DIRECTOION = GPIO_PIN_OUTPUT;
       pin1.LOGIC = motor_config->FWD_PIN.logic;
       pin1.PIN = motor_config->FWD_PIN.pin_num;
       pin1.PORT = motor_config->FWD_PIN.port;
       pin2.DIRECTOION = GPIO_PIN_OUTPUT;
       pin2.LOGIC = motor_config->BKD_PIN.logic;
       pin2.PIN = motor_config->BKD_PIN.pin_num;
       pin2.PORT = motor_config->BKD_PIN.port;
       
       GPIO_PIN_write_logic(&pin1 , GPIO_PIN_LOW);
       GPIO_PIN_write_logic(&pin2 , GPIO_PIN_HIGH);
       
   }
   return ret;
 }
 
 /**
  * 
  * @param relay_config
  * @return 
  */
 Std_ReturnType ECU_RELAY_turn_STOP(const motor_pins_config_t *motor_config){
    Std_ReturnType ret = E_NOT_OK;
    pin_config_t pin1;
    pin_config_t pin2;
   if(NULL==motor_config)
   {
       ret = E_NOT_OK;
   }
   else
   {
       pin1.DIRECTOION = GPIO_PIN_OUTPUT;
       pin1.LOGIC = motor_config->FWD_PIN.logic;
       pin1.PIN = motor_config->FWD_PIN.pin_num;
       pin1.PORT = motor_config->FWD_PIN.port;
       pin2.DIRECTOION = GPIO_PIN_OUTPUT;
       pin2.LOGIC = motor_config->BKD_PIN.logic;
       pin2.PIN = motor_config->BKD_PIN.pin_num;
       pin2.PORT = motor_config->BKD_PIN.port;
       
       GPIO_PIN_write_logic(&pin1 , GPIO_PIN_LOW);
       GPIO_PIN_write_logic(&pin2 , GPIO_PIN_LOW);
   }
   return ret; 
 }
