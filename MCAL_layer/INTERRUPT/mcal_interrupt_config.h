/* 
 * File:   mcal_interrupt_config.h
 * Author: YaseenEzzat
 *
 * Created on November 1, 2023, 10:06 AM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/* Section : Includes*/
#include "../../../../../Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "mcal_interrupt_cnfg.h"
#include "../GPIO/hal_GPIO.h"

/* Section : Macro Declaration*/
#define INTERRUPT_ENABLE                      1
#define INTERRUPT_DISABLE                     0
#define INTERRUPT_FLAG_BIT_HIGH               1
#define INTERRUPT_FLAG_BIT_LOW                0
#define INTERRUPT_OCCURED               INTERRUPT_FLAG_BIT_HIGH
#define INTERRUPT_DID_NOT_OCCURED       INTERRUPT_FLAG_BIT_LOW


/* Section : Macro Function Declaration*/
#if INTERRUPT_PRIORITY==FEATURE_ENABLED

#define INTERRUPT_PRIORITY_ENABLE()                (RCONbits.IPEN=1)
#define INTERRUPT_PRIORITY_DISABLE()               (RCONbits.IPEN=0)

#define INTERRUPT_PRIORITY_HIGH_ENABLE()           (INTCONbits.GIEH=1)
#define INTERRUPT_PRIORITY_HIGH_DISABLED()         (INTCONbits.GIEH=0)

#define INTERRUPT_PRIORITY_LOW_ENABLE()            (INTCONbits.GIEL=1)
#define INTERRUPT_PRIORITY_LOW_DISABLED()          (INTCONbits.GIEL=0)

#endif

#if INTERRUPT_GLOBAL==FEATURE_ENABLED

#define INTERRUPT_GLOBAL_ENABLE()                  (INTCONbits.GIE=1)
#define INTERRUPT_GLOBAL_DISABLED()                (INTCONbits.GIE=0)

#endif

#if INTERRUPT_PERIFERALS==FEATURE_ENABLED
 
#define INTERRUPT_PERIFERALS_ENABLE()              (INTCONbits.PEIE=1)
#define INTERRUPT_PERIFERALS_DISABLED()            (INTCONbits.PEIE=0)

#endif

/* Section : Data Type Declaration*/
typedef enum {
    INTERRUPT_PRIORITY_DISABLED,
    INTERRUPT_PRIORITY_ENABLED
}interrupt_priority;

typedef enum {
    INTERRUPT_PRIORITY_LOW,
    INTERRUPT_PRIORITY_HIGH
}interrupt_priority_LEVEL;

/* Section : Function Declaration*/

#endif	/* MCAL_INTERRUPT_CONFIG_H */

