/* 
 * File:   ecu_led.h
 * Author: YaseenEzzat
 *
 * Created on October 22, 2023, 12:02 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H
/* Section : Includes*/
#include"../../MCAL_layer/GPIO/hal_GPIO.h"
#include"ecu_led_cnfig.h"

/* Section : Macro Declaration*/

/* Section : Macro Function Declaration*/

/* Section : Data Type Declaration*/
typedef enum {
    LED_OFF =0,
    LED_ON
}led_status_t;


typedef struct {
    uint8 port          :3;
    uint8 pin_num       :3;
    uint8 logic         :1;
    uint8 reserve_type  :1;
 }led_config_t;

/* Section : Function Declaration*/
 Std_ReturnType ECU_LED_intialization(const led_config_t *led_config);
 Std_ReturnType ECU_LED_turn_on(const led_config_t *led_config);
 Std_ReturnType ECU_LED_turn_off(const led_config_t *led_config);
 Std_ReturnType ECU_LED_turn_toggle(const led_config_t *led_config);


#endif	/* ECU_LED_H */

