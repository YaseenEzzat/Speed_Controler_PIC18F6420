/* 
 * File:   ecu_relay.h
 * Author: YaseenEzzat
 *
 * Created on October 26, 2023, 10:36 AM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* Section : Includes*/
#include "../../MCAL_layer/GPIO/hal_GPIO.h"
#include "ecu_relay_config.h"

/* Section : Macro Declaration*/

/* Section : Macro Function Declaration*/

/* Section : Data Type Declaration*/
typedef enum {
    RELAY_OFF =0,
    RELAY_ON
}relay_status_t;


typedef struct {
    uint8 port          :3;
    uint8 pin_num       :3;
    uint8 logic         :1;
    uint8 reserve_type  :1;
 }relay_config_t;

/* Section : Function Declaration*/
 Std_ReturnType ECU_RELAY_intialization(const relay_config_t *relay_config);
 Std_ReturnType ECU_RELAY_turn_on(const relay_config_t *relay_config);
 Std_ReturnType ECU_RELAY_turn_off(const relay_config_t *relay_config);


#endif	/* ECU_RELAY_H */

