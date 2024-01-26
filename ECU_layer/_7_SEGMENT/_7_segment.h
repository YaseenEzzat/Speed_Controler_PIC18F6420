/* 
 * File:   _7_segment.h
 * Author: YaseenEzzat
 *
 * Created on October 27, 2023, 10:30 AM
 */

#ifndef _7_SEGMENT_H
#define	_7_SEGMENT_H

/* Section : Includes*/
#include "../../MCAL_layer/GPIO/hal_GPIO.h"
#include "_7_segment_config.h"

/* Section : Macro Declaration*/

/* Section : Macro Function Declaration*/

/* Section : Data Type Declaration*/
typedef enum {
    COMMON_CATHODE =0,
    COMMON_ANODE
}segment_type_t;


typedef struct {
    pin_config_t pin0;
    pin_config_t pin1;
    pin_config_t pin2;
    pin_config_t pin3;
    segment_type_t segment_type;
 }segment_pins_config_t;

/* Section : Function Declaration*/
 Std_ReturnType ECU_7_SEGMENT_intialization(const segment_pins_config_t *segment_pins);
 Std_ReturnType ECU_7_SEGMENT_write_value(const segment_pins_config_t *segment_pins , uint8 value);


#endif	/* _7_SEGMENT_H */

