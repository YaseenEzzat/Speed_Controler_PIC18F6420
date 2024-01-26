/* 
 * File:   mcal_interrupt_cnfg.h
 * Author: YaseenEzzat
 *
 * Created on November 2, 2023, 1:57 AM
 */

#ifndef MCAL_INTERRUPT_CNFG_H
#define	MCAL_INTERRUPT_CNFG_H

/* Section : Includes*/

/* Section : Macro Declaration*/
#define FEATURE_ENABLED             1
#define FEATURE_DISABLED            0

#define INTERRUPT_PRIORITY                   FEATURE_ENABLED
#if INTERRUPT_PRIORITY==FEATURE_DISABLED
#define INTERRUPT_GLOBAL                     FEATURE_ENABLED
#define INTERRUPT_PERIFERALS                 FEATURE_ENABLED
#endif
#define INTERRUPT_EXTERNAL_INTx              FEATURE_ENABLED
#define INTERRUPT_EXTERNAL_ON_CHANGE         FEATURE_ENABLED
#define INTERRUPT_ADC                        FEATURE_ENABLED
#define INTERRUPT_TIMER0                     FEATURE_ENABLED
#define INTERRUPT_TIMER1                     FEATURE_ENABLED
#define INTERRUPT_TIMER2                     FEATURE_ENABLED
#define INTERRUPT_TIMER3                     FEATURE_ENABLED
#define INTERRUPT_CCP1                       FEATURE_ENABLED
#define INTERRUPT_USART_TRANS                FEATURE_ENABLED
#define INTERRUPT_USART_RECEIVE              FEATURE_ENABLED
#define INTERRUPT_SPI                        FEATURE_ENABLED


/* Section : Macro Function Declaration*/

/* Section : Data Type Declaration*/

/* Section : Function Declaration*/

#endif	/* MCAL_INTERRUPT_CNFG_H */

