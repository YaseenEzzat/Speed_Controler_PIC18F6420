/* 
 * File:   mcal_interrupt_manger.h
 * Author: YaseenEzzat
 *
 * Created on November 1, 2023, 10:03 AM
 */

#ifndef MCAL_INTERRUPT_MANGER_H
#define	MCAL_INTERRUPT_MANGER_H

/* Section : Includes*/
#include "mcal_interrupt_config.h"
#include "mcal_external_interrupt.h"
/* Section : Macro Declaration*/

/* Section : Macro Function Declaration*/

/* Section : Data Type Declaration*/

/* Section : Function Declaration*/
void __interrupt()Interrupt_Manger_high(void);
void __interrupt(low_priority)Interrupt_Manger_low(void);

void ISR_INT0 (void);
void ISR_INT1 (void);
void ISR_INT2 (void);
void ISR_RB (void);

void ISR_ADC (void);
void ISR_TIMER0 (void);
void ISR_TIMER1 (void);
void ISR_TIMER2 (void);
void ISR_TIMER3 (void);
void ISR_CCP1 (void);
void ISR_USART_Trans (void);
void ISR_USART_Receive (void);
void ISR_SPI (void);

#endif	/* MCAL_INTERRUPT_MANGER_H */

