/* 
 * File:   ecu_push_button.h
 * Author: YaseenEzzat
 *
 * Created on October 26, 2023, 3:30 AM
 */

#ifndef ECU_PUSH_BOTTON_H
#define	ECU_PUSH_BOTTON_H

/* Section : Includes*/
#include"../../MCAL_layer/GPIO/hal_GPIO.h"
#include "ecu_push_button_config.h"

/* Section : Macro Declaration*/

/* Section : Macro Function Declaration*/

/* Section : Data Type Declaration*/
typedef enum {
    RELEASED,
    PRESSED
}button_status_t;

typedef enum {
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_connection_status_t;

typedef struct {
    pin_config_t pin_config;
    button_status_t button_status;
    button_connection_status_t button_connection;
}button_config_t;


/* Section : Function Declaration*/

Std_ReturnType ECU_BUTTON_intialization (const button_config_t *button_config);
Std_ReturnType ECU_BUTTON_read (const button_config_t *button_config ,button_status_t *button_status);

#endif	/* ECU_PUSH_BOTTON_H */

