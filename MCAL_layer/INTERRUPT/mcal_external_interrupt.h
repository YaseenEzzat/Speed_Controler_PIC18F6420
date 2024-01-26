/* 
 * File:   mcal_external_interrupt.h
 * Author: YaseenEzzat
 *
 * Created on November 1, 2023, 10:05 AM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* Section : Includes*/
#include "mcal_interrupt_config.h"
/* Section : Macro Declaration*/

/* Section : Macro Function Declaration*/

//EXTERNAL_INTERRUPT_INTx
#if INTERRUPT_EXTERNAL_INTx==FEATURE_ENABLED

//EXTERNAL_INTERRUPT_INT0
#define EXTERNAL_INTERRUPT_INT0_ENABLE()          (INTCONbits.INT0E=1)
#define EXTERNAL_INTERRUPT_INT0_DISABLE()         (INTCONbits.INT0E=0)

#define EXTERNAL_INTERRUPT_INT0_CLEAR_FALG()      (INTCONbits.INT0F=0)

#define EXTERNAL_INTERRUPT_INT0_RISING_EDGE()     (INTCON2bits.INTEDG0=1)
#define EXTERNAL_INTERRUPT_INT0_FAlLING_EDGE()    (INTCON2bits.INTEDG0=0)

//EXTERNAL_INTERRUPT_INT1
#define EXTERNAL_INTERRUPT_INT1_ENABLE()          (INTCON3bits.INT1E=1)
#define EXTERNAL_INTERRUPT_INT1_DISABLE()         (INTCON3bits.INT1E=0)

#define EXTERNAL_INTERRUPT_INT1_CLEAR_FALG()      (INTCON3bits.INT1F=0)

#define EXTERNAL_INTERRUPT_INT1_RISING_EDGE()     (INTCON2bits.INTEDG1=1)
#define EXTERNAL_INTERRUPT_INT1_FAlLING_EDGE()    (INTCON2bits.INTEDG1=0)

//EXTERNAL_INTERRUPT_INT2
#define EXTERNAL_INTERRUPT_INT2_ENABLE()          (INTCON3bits.INT2E=1)
#define EXTERNAL_INTERRUPT_INT2_DISABLE()         (INTCON3bits.INT2E=0)

#define EXTERNAL_INTERRUPT_INT2_CLEAR_FALG()      (INTCON3bits.INT2F=0)

#define EXTERNAL_INTERRUPT_INT2_RISING_EDGE()     (INTCON2bits.INTEDG2=1)
#define EXTERNAL_INTERRUPT_INT2_FAlLING_EDGE()    (INTCON2bits.INTEDG2=0)


//EXTERNAL_INTERRUPT_INTx_PRIORITY
#if INTERRUPT_PRIORITY==FEATURE_ENABLED
//EXTERNAL_INTERRUPT_INT1
#define EXTERNAL_INTERRUPT_INT1_PRIORITY_HIHG()     (INTCON3bits.INT1IP=1)
#define EXTERNAL_INTERRUPT_INT1_PRIORITY_LOW()      (INTCON3bits.INT1IP=0)

//EXTERNAL_INTERRUPT_INT2
#define EXTERNAL_INTERRUPT_INT2_PRIORITY_HIHG()     (INTCON3bits.INT2IP=1)
#define EXTERNAL_INTERRUPT_INT2_PRIORITY_LOW()      (INTCON3bits.INT2IP=0)
#endif
#endif
/*****************************************************************************/

//EXTERNALI_NTERRUPT_ON_CHANGE
#if INTERRUPT_EXTERNAL_ON_CHANGE==FEATURE_ENABLED

//EXTERNALI_NTERRUPT_ON_CHANGE_RB
#define EXTERNAL_INTERRUPT_RB_ENABLE()              (INTCONbits.RBIE = 1)
#define EXTERNAL_INTERRUPT_RB_DISABLE()             (INTCONbits.RBIE = 0)

#define EXTERNAL_INTERRUPT_RB_CLEAR_FALG()          (INTCONbits.RBIF = 0)

#define EXTERNAL_INTERRUPT_RB_PULL_UPS_ENABLE()    (INTCON2bits.RBPU = 0)
#define EXTERNAL_INTERRUPT_RB_PULL_UPS_DISABLE()    (INTCON2bits.RBPU = 1)

#define EXTERNAL_INTERRUPT_RB_DISABLE()             (INTCONbits.RBIE = 0)

#if INTERRUPT_PRIORITY==FEATURE_ENABLED
#define EXTERNAL_INTERRUPT_RB_HIGH_PRIORITY()       (INTCON2bits.RBIP = 1)
#define EXTERNAL_INTERRUPT_RB_LOW_PRIORITY()        (INTCON2bits.RBIP = 0)
#endif
#endif


/* Section : Data Type Declaration*/
typedef enum {
    INTERRUPT_FALLING_EDGE,
    INTERRUPT_RISING_EDGE
}interrupt_edge;

typedef enum {
    INT0_pin,
    INT1_pin,
    INT2_pin
}interrupt_INTx_pin;

typedef enum {
    INTERRUPT_PULL_UPS_ENABLED,
    INTERRUPT_PULL_UPS_DISABLED
}interrupt_RB_PULL_UPS_STATE;

typedef struct {
    void(*External_INTx_interrupt_handler)(void);
    interrupt_INTx_pin INTx_pin;
    interrupt_priority_LEVEL priority;
    interrupt_edge interrupt_edge;
    pin_config_t pin;
    
}interrupt_INTx_config_t;

typedef struct {
    void(*External_RB_interrupt_handler)(void);
    interrupt_priority_LEVEL priority;
    pin_config_t pin;
    interrupt_RB_PULL_UPS_STATE PULL_UPS;
    
}interrupt_RB_config_t;
/* Section : Function Declaration*/
Std_ReturnType INTERRUPT_INTx_initialization (const interrupt_INTx_config_t *INTx );
Std_ReturnType INTERRUPT_INTx_deinitialization (const interrupt_INTx_config_t *INTx );
 
Std_ReturnType INTERRUPT_RB_initialization (const interrupt_RB_config_t *RB );
Std_ReturnType INTERRUPT_RB_deinitialization (const interrupt_RB_config_t *RB );


#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

