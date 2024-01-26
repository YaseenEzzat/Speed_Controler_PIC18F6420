/* 
 * File:   mcal_internal_interrupt.h
 * Author: YaseenEzzat
 *
 * Created on November 1, 2023, 10:04 AM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/* Section : Includes*/
#include "mcal_interrupt_config.h"

/* Section : Macro Declaration*/


/* Section : Macro Function Declaration*/
/*****************************ADC_INTERRUPT START*********************************/
#if INTERRUPT_ADC==FEATURE_ENABLED
#define ADC_INTERRUPT_ENABLE()          (PIE1bits.ADIE=1)
#define ADC_INTERRUPT_DISABLE()         (PIE1bits.ADIE=0)

#define ADC_INTERRUPT_CLEAR_FALG()      (PIR1bits.ADIF=0)

//ADC_INTERRUPT_PRIORITY
#if INTERRUPT_PRIORITY==FEATURE_ENABLED
//EXTERNAL_INTERRUPT_ADC
#define ADC_INTERRUPT_PRIORITY_HIHG()     (IPR1bits.ADIP=1)
#define ADC_INTERRUPT_PRIORITY_LOW()      (IPR1bits.ADIP=0)
#endif
#endif

/*****************************ADC_INTERRUPT END*********************************/

/*****************************TIMER0_INTERRUPT START*********************************/
#if INTERRUPT_TIMER0==FEATURE_ENABLED
#define TIMER0_INTERRUPT_ENABLE()          (INTCONbits.TMR0IE = 1)
#define TIMER0_INTERRUPT_DISABLE()         (INTCONbits.TMR0IE = 0)

#define TIMER0_INTERRUPT_CLEAR_FALG()      (INTCONbits.TMR0IF = 0)

//TIMER0_INTERRUPT_PRIORITY
#if INTERRUPT_PRIORITY==FEATURE_ENABLED
//EXTERNAL_INTERRUPT_TIMER0
#define TIMER0_INTERRUPT_PRIORITY_HIHG()     (INTCON2bits.TMR0IP=1)
#define TIMER0_INTERRUPT_PRIORITY_LOW()      (INTCON2bits.TMR0IP=1)
#endif
#endif

/*****************************TIMER0_INTERRUPT END*********************************/

/*****************************TIMER1_INTERRUPT START*********************************/
#if INTERRUPT_TIMER1==FEATURE_ENABLED
#define TIMER1_INTERRUPT_ENABLE()          (PIE1bits.TMR1IE = 1)
#define TIMER1_INTERRUPT_DISABLE()         (PIE1bits.TMR1IE = 0)

#define TIMER1_INTERRUPT_CLEAR_FALG()      (PIR1bits.TMR1IF = 0)

//TIMER1_INTERRUPT_PRIORITY
#if INTERRUPT_PRIORITY==FEATURE_ENABLED
//EXTERNAL_INTERRUPT_TIMER1
#define TIMER1_INTERRUPT_PRIORITY_HIHG()     (IPR1bits.TMR1IP = 1)
#define TIMER1_INTERRUPT_PRIORITY_LOW()      (IPR1bits.TMR1IP = 0)
#endif
#endif

/*****************************TIMER1_INTERRUPT END*********************************/

/*****************************TIMER2_INTERRUPT START*********************************/
#if INTERRUPT_TIMER2==FEATURE_ENABLED
#define TIMER2_INTERRUPT_ENABLE()          (PIE1bits.TMR2IE = 1)
#define TIMER2_INTERRUPT_DISABLE()         (PIE1bits.TMR2IE = 0)

#define TIMER2_INTERRUPT_CLEAR_FALG()      (PIR1bits.TMR2IF = 0)

//TIMER2_INTERRUPT_PRIORITY
#if INTERRUPT_PRIORITY==FEATURE_ENABLED
//EXTERNAL_INTERRUPT_TIMER2
#define TIMER2_INTERRUPT_PRIORITY_HIHG()     (IPR1bits.TMR2IP = 1)
#define TIMER2_INTERRUPT_PRIORITY_LOW()      (IPR1bits.TMR2IP = 0)
#endif
#endif

/*****************************TIMER2_INTERRUPT END*********************************/

/*****************************TIMER3_INTERRUPT START*********************************/
#if INTERRUPT_TIMER3==FEATURE_ENABLED
#define TIMER3_INTERRUPT_ENABLE()          (PIE2bits.TMR3IE = 1)
#define TIMER3_INTERRUPT_DISABLE()         (PIE2bits.TMR3IE = 0)

#define TIMER3_INTERRUPT_CLEAR_FALG()      (PIR2bits.TMR3IF = 0)

//TIMER3_INTERRUPT_PRIORITY
#if INTERRUPT_PRIORITY==FEATURE_ENABLED
//EXTERNAL_INTERRUPT_TIMER3
#define TIMER3_INTERRUPT_PRIORITY_HIHG()     (IPR2bits.TMR3IP = 1)
#define TIMER3_INTERRUPT_PRIORITY_LOW()      (IPR2bits.TMR3IP = 0)
#endif
#endif

/*****************************TIMER3_INTERRUPT END*********************************/

/*****************************CCP1_INTERRUPT START*********************************/
#if INTERRUPT_CCP1==FEATURE_ENABLED
#define CCP1_INTERRUPT_ENABLE()          (PIE1bits.CCP1IE = 1)
#define CCP1_INTERRUPT_DISABLE()         (PIE1bits.CCP1IE = 0)

#define CCP1_INTERRUPT_CLEAR_FALG()      (PIR1bits.CCP1IF = 0)

//TIMER1_INTERRUPT_PRIORITY
#if INTERRUPT_PRIORITY==FEATURE_ENABLED
//EXTERNAL_INTERRUPT_TIMER1
#define CCP1_INTERRUPT_PRIORITY_HIHG()     (IPR1bits.CCP1IP = 1)
#define CCP1_INTERRUPT_PRIORITY_LOW()      (IPR1bits.CCP1IP = 0)
#endif
#endif

/*****************************CCP1_INTERRUPT END*********************************/

/*****************************UASRT TRANSMISSION INTERRUPT START*********************************/
#if INTERRUPT_USART_TRANS==FEATURE_ENABLED
#define USART_TRANS_INTERRUPT_ENABLE()            (PIE1bits.TXIE=1)
#define USART_TRANS_INTERRUPT_DISABLE()           (PIE1bits.TXIE=0)

//USART_TRANS_INTERRUPT_PRIORITY
#if INTERRUPT_PRIORITY==FEATURE_ENABLED
//EXTERNAL_INTERRUPT_USART_TRANS
#define USART_TRANS_INTERRUPT_PRIORITY_HIHG()     (IPR1bits.TXIP=1)
#define USART_TRANS_INTERRUPT_PRIORITY_LOW()      (IPR1bits.TXIP=0)
#endif
#endif

/*****************************UASRT TRANSMISSION INTERRUPT END*********************************/

/*****************************UASRT RECEIVING INTERRUPT START*********************************/
#if INTERRUPT_USART_RECEIVE==FEATURE_ENABLED
#define USART_RECEIVE_INTERRUPT_ENABLE()            (PIE1bits.RCIE=1)
#define USART_RECEIVE_INTERRUPT_DISABLE()           (PIE1bits.RCIE=0)

//USART_RECEIVE_INTERRUPT_PRIORITY
#if INTERRUPT_PRIORITY==FEATURE_ENABLED
//EXTERNAL_INTERRUPT_USART_RECEIVE
#define USART_RECEIVE_INTERRUPT_PRIORITY_HIHG()     (IPR1bits.RCIP=1)
#define USART_RECEIVE_INTERRUPT_PRIORITY_LOW()      (IPR1bits.RCIP=0)
#endif
#endif

/*****************************UASRT RECEIVING INTERRUPT END*********************************/
/*****************************SPI INTERRUPT START*********************************/
#if INTERRUPT_SPI==FEATURE_ENABLED
#define SPI_INTERRUPT_ENABLE()               (PIE1bits.SSPIE=1)
#define SPI_INTERRUPT_DISABLE()              (PIE1bits.SSPIE=0)

#define SPI_INTERRUPT_CLEAR_FALG()           (PIR1bits.SSPIF = 0)

//SPI_INTERRUPT_PRIORITY
#if INTERRUPT_PRIORITY==FEATURE_ENABLED
//EXTERNAL_INTERRUPT_SPI
#define SPI_INTERRUPT_PRIORITY_HIHG()         (IPR1bits.SSPIP=1)
#define SPI_INTERRUPT_PRIORITY_LOW()          (IPR1bits.SSPIP=0)
#endif
#endif

/*****************************SPI INTERRUPT END*********************************/
/* Section : Data Type Declaration*/

/* Section : Function Declaration*/
/*****************************ADC_INTERRUPT START*********************************/
#if INTERRUPT_ADC==FEATURE_ENABLED
Std_ReturnType INTERRUPT_ADC_initialization (interrupt_priority_LEVEL priority );
Std_ReturnType INTERRUPT_ADC_deinitialization (void);
#endif
/*****************************ADC_INTERRUPT END*********************************/

/*****************************TIMER0_INTERRUPT START*********************************/
#if INTERRUPT_TIMER0==FEATURE_ENABLED
Std_ReturnType INTERRUPT_TIMER0_initialization (interrupt_priority_LEVEL priority );
Std_ReturnType INTERRUPT_TIMER0_deinitialization (void);
#endif
/*****************************TIMER0_INTERRUPT END*********************************/

/*****************************TIMER1_INTERRUPT START*********************************/
#if INTERRUPT_TIMER1==FEATURE_ENABLED
Std_ReturnType INTERRUPT_TIMER1_initialization (interrupt_priority_LEVEL priority );
Std_ReturnType INTERRUPT_TIMER1_deinitialization (void);
#endif
/*****************************TIMER1_INTERRUPT END*********************************/

/*****************************TIMER2_INTERRUPT START*********************************/
#if INTERRUPT_TIMER1==FEATURE_ENABLED
Std_ReturnType INTERRUPT_TIMER2_initialization (interrupt_priority_LEVEL priority );
Std_ReturnType INTERRUPT_TIMER2_deinitialization (void);
#endif
/*****************************TIMER2_INTERRUPT END*********************************/

/*****************************TIMER3_INTERRUPT START*********************************/
#if INTERRUPT_TIMER3==FEATURE_ENABLED
Std_ReturnType INTERRUPT_TIMER3_initialization (interrupt_priority_LEVEL priority );
Std_ReturnType INTERRUPT_TIMER3_deinitialization (void);
#endif
/*****************************TIMER3_INTERRUPT END*********************************/

/*****************************CCP1_INTERRUPT START*********************************/
#if INTERRUPT_CCP1==FEATURE_ENABLED
Std_ReturnType INTERRUPT_CCP1_initialization (interrupt_priority_LEVEL priority );
Std_ReturnType INTERRUPT_CCP1_deinitialization (void);
#endif
/*****************************CCP1_INTERRUPT END*********************************/

/*****************************UASRT TRANSMISSION INTERRUPT START*********************************/
#if INTERRUPT_USART_TRANS==FEATURE_ENABLED
Std_ReturnType INTERRUPT_USART_TRANS_initialization (interrupt_priority_LEVEL priority );
Std_ReturnType INTERRUPT_USART_TRANS_deinitialization (void);
#endif
/*****************************UASRT TRANSMISSION INTERRUPT END*********************************/

/*****************************UASRT RECEIVING INTERRUPT START*********************************/
#if INTERRUPT_USART_RECEIVE==FEATURE_ENABLED
Std_ReturnType INTERRUPT_USART_RECEIVE_initialization (interrupt_priority_LEVEL priority );
Std_ReturnType INTERRUPT_USART_RECEIVE_deinitialization (void);
#endif
/*****************************UASRT RECEIVING INTERRUPT END*********************************/


/*****************************UASRT RECEIVING INTERRUPT START*********************************/
#if INTERRUPT_SPI==FEATURE_ENABLED
Std_ReturnType INTERRUPT_SPI_initialization (interrupt_priority_LEVEL priority );
Std_ReturnType INTERRUPT_SPI_deinitialization (void);
#endif
/*****************************UASRT RECEIVING INTERRUPT END*********************************/

#endif	/* MCAL_INTERNAL_INTERRUPT_H */

