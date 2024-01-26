/* 
 * File:   ecu_motor.h
 * Author: YaseenEzzat
 *
 * Created on October 27, 2023, 12:58 AM
 */

#ifndef ECU_MOTOR_H
#define	ECU_MOTOR_H

/* Section : Includes*/
#include "../../MCAL_layer/GPIO/hal_GPIO.h"
#include "ecu_motor_config.h"

/* Section : Macro Declaration*/

/* Section : Macro Function Declaration*/

/* Section : Data Type Declaration*/
typedef enum {
    MOTOR_OFF =0,
    MOTOR_ON
}motor_status_t;

typedef struct {
    uint8 port          :3;
    uint8 pin_num       :3;
    uint8 logic         :1;
    uint8 reserve_type  :1;
 }motor_config_t;
 
 typedef struct {
     motor_config_t FWD_PIN;
     motor_config_t BKD_PIN;
 }motor_pins_config_t;

/* Section : Function Declaration*/
 Std_ReturnType ECU_MOTOR_intialization(const motor_pins_config_t *motor_config);
 Std_ReturnType ECU_MOTOR_turn_forward(const motor_pins_config_t *motor_config);
 Std_ReturnType ECU_RELAY_turn_backword(const motor_pins_config_t *motor_config);
 Std_ReturnType ECU_RELAY_turn_STOP(const motor_pins_config_t *motor_config);



#endif	/* ECU_MOTOR_H */

