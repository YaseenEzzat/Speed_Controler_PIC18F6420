/* 
 * File:   mcal_internal_interrupt.c
 * Author: YaseenEzzat
 *
 * Created on November 4, 2023, 1:39 AM
 */
#include "mcal_internal_interrupt.h"

/*****************************ADC_INTERRUPT START*********************************/
#if INTERRUPT_ADC==FEATURE_ENABLED
/**
 * 
 * @param priority
 * @return 
 */
Std_ReturnType INTERRUPT_ADC_initialization (interrupt_priority_LEVEL priority){
    Std_ReturnType ret = E_NOT_OK;
    
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_PRIORITY_HIGH_ENABLE();
        INTERRUPT_PRIORITY_LOW_ENABLE();
        #endif

        #if INTERRUPT_GLOBAL==FEATURE_ENABLED
        INTERRUPT_GLOBAL_ENABLE();
        #endif

        #if INTERRUPT_PERIFERALS==FEATURE_ENABLED
        INTERRUPT_PERIFERALS_ENABLE();
        #endif
        ADC_INTERRUPT_DISABLE();
        ADC_INTERRUPT_CLEAR_FALG();
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        if(priority ==  INTERRUPT_PRIORITY_HIGH )
        {
            ADC_INTERRUPT_PRIORITY_HIHG();
            ret = E_OK;
        }
        else if(priority ==  INTERRUPT_PRIORITY_LOW )
        {
            ADC_INTERRUPT_PRIORITY_LOW();
            ret = E_OK;
        }
        else{/*nothing*/}
        #endif

        ADC_INTERRUPT_ENABLE();
        
    return ret;
    
}

/**
 * 
 * @return 
 */
Std_ReturnType INTERRUPT_ADC_deinitialization (void){
        Std_ReturnType ret = E_NOT_OK;
        ADC_INTERRUPT_DISABLE();
        ret = E_OK;
        
        return ret;
}
#endif
/*****************************ADC_INTERRUPT END*********************************/

/*****************************TIMER0_INTERRUPT START*********************************/
#if INTERRUPT_TIMER0==FEATURE_ENABLED
/**
 * 
 * @param priority
 * @return 
 */
Std_ReturnType INTERRUPT_TIMER0_initialization (interrupt_priority_LEVEL priority ){
    Std_ReturnType ret = E_NOT_OK;
    
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_PRIORITY_HIGH_ENABLE();
        INTERRUPT_PRIORITY_LOW_ENABLE();
        #endif

        #if INTERRUPT_GLOBAL==FEATURE_ENABLED
        INTERRUPT_GLOBAL_ENABLE();
        #endif

        #if INTERRUPT_PERIFERALS==FEATURE_ENABLED
        INTERRUPT_PERIFERALS_ENABLE();
        #endif
        TIMER0_INTERRUPT_DISABLE();
        TIMER0_INTERRUPT_CLEAR_FALG();
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        if(priority ==  INTERRUPT_PRIORITY_HIGH )
        {
            TIMER0_INTERRUPT_PRIORITY_HIHG();
            ret = E_OK;
        }
        else if(priority ==  INTERRUPT_PRIORITY_LOW )
        {
            TIMER0_INTERRUPT_PRIORITY_LOW();
            ret = E_OK;
        }
        else{/*nothing*/}
        #endif

        TIMER0_INTERRUPT_ENABLE();
    return ret;        
}



/**
 * 
 * @return 
 */
Std_ReturnType INTERRUPT_TIMER0_deinitialization (void){
    Std_ReturnType ret = E_NOT_OK;
    TIMER0_INTERRUPT_DISABLE();
    ret = E_OK;
    return ret; 
}
#endif
/*****************************TIMER0_INTERRUPT END*********************************/

/*****************************TIMER1_INTERRUPT START*********************************/
#if INTERRUPT_TIMER1==FEATURE_ENABLED
/**
 * 
 * @param priority
 * @return 
 */
Std_ReturnType INTERRUPT_TIMER1_initialization (interrupt_priority_LEVEL priority ){
    Std_ReturnType ret = E_NOT_OK;
    
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_PRIORITY_HIGH_ENABLE();
        INTERRUPT_PRIORITY_LOW_ENABLE();
        #endif

        #if INTERRUPT_GLOBAL==FEATURE_ENABLED
        INTERRUPT_GLOBAL_ENABLE();
        #endif

        #if INTERRUPT_PERIFERALS==FEATURE_ENABLED
        INTERRUPT_PERIFERALS_ENABLE();
        #endif
        TIMER1_INTERRUPT_DISABLE();
        TIMER1_INTERRUPT_CLEAR_FALG();
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        if(priority ==  INTERRUPT_PRIORITY_HIGH )
        {
            TIMER1_INTERRUPT_PRIORITY_HIHG();
            ret = E_OK;
        }
        else if(priority ==  INTERRUPT_PRIORITY_LOW )
        {
            TIMER1_INTERRUPT_PRIORITY_LOW();
            ret = E_OK;
        }
        else{/*nothing*/}
        #endif

        TIMER1_INTERRUPT_ENABLE();
    return ret;        
}



/**
 * 
 * @return 
 */
Std_ReturnType INTERRUPT_TIMER1_deinitialization (void){
    Std_ReturnType ret = E_NOT_OK;
    TIMER1_INTERRUPT_DISABLE();
    ret = E_OK;
    return ret; 
}
#endif
/*****************************TIMER1_INTERRUPT END*********************************/

/*****************************TIMER2_INTERRUPT START*********************************/
#if INTERRUPT_TIMER2==FEATURE_ENABLED
/**
 * 
 * @param priority
 * @return 
 */
Std_ReturnType INTERRUPT_TIMER2_initialization (interrupt_priority_LEVEL priority ){
    Std_ReturnType ret = E_NOT_OK;
    
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_PRIORITY_HIGH_ENABLE();
        INTERRUPT_PRIORITY_LOW_ENABLE();
        #endif

        #if INTERRUPT_GLOBAL==FEATURE_ENABLED
        INTERRUPT_GLOBAL_ENABLE();
        #endif

        #if INTERRUPT_PERIFERALS==FEATURE_ENABLED
        INTERRUPT_PERIFERALS_ENABLE();
        #endif
        TIMER2_INTERRUPT_DISABLE();
        TIMER2_INTERRUPT_CLEAR_FALG();
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        if(priority ==  INTERRUPT_PRIORITY_HIGH )
        {
            TIMER2_INTERRUPT_PRIORITY_HIHG();
            ret = E_OK;
        }
        else if(priority ==  INTERRUPT_PRIORITY_LOW )
        {
            TIMER2_INTERRUPT_PRIORITY_LOW();
            ret = E_OK;
        }
        else{/*nothing*/}
        #endif

        TIMER2_INTERRUPT_ENABLE();
    return ret;        
}



/**
 * 
 * @return 
 */
Std_ReturnType INTERRUPT_TIMER2_deinitialization (void){
    Std_ReturnType ret = E_NOT_OK;
    TIMER2_INTERRUPT_DISABLE();
    ret = E_OK;
    return ret; 
}
#endif
/*****************************TIMER2_INTERRUPT END*********************************/

/*****************************TIMER3_INTERRUPT START*********************************/
#if INTERRUPT_TIMER3==FEATURE_ENABLED
/**
 * 
 * @param priority
 * @return 
 */
Std_ReturnType INTERRUPT_TIMER3_initialization (interrupt_priority_LEVEL priority ){
    Std_ReturnType ret = E_NOT_OK;
    
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_PRIORITY_HIGH_ENABLE();
        INTERRUPT_PRIORITY_LOW_ENABLE();
        #endif

        #if INTERRUPT_GLOBAL==FEATURE_ENABLED
        INTERRUPT_GLOBAL_ENABLE();
        #endif

        #if INTERRUPT_PERIFERALS==FEATURE_ENABLED
        INTERRUPT_PERIFERALS_ENABLE();
        #endif
        TIMER3_INTERRUPT_DISABLE();
        TIMER3_INTERRUPT_CLEAR_FALG();
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        if(priority ==  INTERRUPT_PRIORITY_HIGH )
        {
            TIMER3_INTERRUPT_PRIORITY_HIHG();
            ret = E_OK;
        }
        else if(priority ==  INTERRUPT_PRIORITY_LOW )
        {
            TIMER3_INTERRUPT_PRIORITY_LOW();
            ret = E_OK;
        }
        else{/*nothing*/}
        #endif

        TIMER3_INTERRUPT_ENABLE();
    return ret;        
}



/**
 * 
 * @return 
 */
Std_ReturnType INTERRUPT_TIMER3_deinitialization (void){
    Std_ReturnType ret = E_NOT_OK;
    TIMER3_INTERRUPT_DISABLE();
    ret = E_OK;
    return ret; 
}
#endif
/*****************************TIMER3_INTERRUPT END*********************************/

/*****************************CCP1_INTERRUPT START*********************************/
#if INTERRUPT_CCP1==FEATURE_ENABLED
/**
 * 
 * @param priority
 * @return 
 */
Std_ReturnType INTERRUPT_CCP1_initialization (interrupt_priority_LEVEL priority ){
    Std_ReturnType ret = E_NOT_OK;
    
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_PRIORITY_HIGH_ENABLE();
        INTERRUPT_PRIORITY_LOW_ENABLE();
        #endif

        #if INTERRUPT_GLOBAL==FEATURE_ENABLED
        INTERRUPT_GLOBAL_ENABLE();
        #endif

        #if INTERRUPT_PERIFERALS==FEATURE_ENABLED
        INTERRUPT_PERIFERALS_ENABLE();
        #endif
        CCP1_INTERRUPT_DISABLE();
        CCP1_INTERRUPT_CLEAR_FALG();
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        if(priority ==  INTERRUPT_PRIORITY_HIGH )
        {
            CCP1_INTERRUPT_PRIORITY_HIHG();
            ret = E_OK;
        }
        else if(priority ==  INTERRUPT_PRIORITY_LOW )
        {
            CCP1_INTERRUPT_PRIORITY_LOW();
            ret = E_OK;
        }
        else{/*nothing*/}
        #endif

        CCP1_INTERRUPT_ENABLE();
    return ret;        
}



/**
 * 
 * @return 
 */
Std_ReturnType INTERRUPT_CCP1_deinitialization (void){
    Std_ReturnType ret = E_NOT_OK;
    CCP1_INTERRUPT_DISABLE();
    ret = E_OK;
    return ret; 
}
#endif
/*****************************CCP1_INTERRUPT END*********************************/


/*****************************UASRT TRANSMISSION INTERRUPT START*********************************/
#if INTERRUPT_USART_TRANS==FEATURE_ENABLED
Std_ReturnType INTERRUPT_USART_TRANS_initialization (interrupt_priority_LEVEL priority ){
    
        Std_ReturnType ret = E_NOT_OK;

        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_PRIORITY_HIGH_ENABLE();
        INTERRUPT_PRIORITY_LOW_ENABLE();
        #endif

        #if INTERRUPT_GLOBAL==FEATURE_ENABLED
        INTERRUPT_GLOBAL_ENABLE();
        #endif

        #if INTERRUPT_PERIFERALS==FEATURE_ENABLED
        INTERRUPT_PERIFERALS_ENABLE();
        #endif
        USART_TRANS_INTERRUPT_DISABLE();
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        if(priority ==  INTERRUPT_PRIORITY_HIGH )
        {
            USART_TRANS_INTERRUPT_PRIORITY_HIHG();
            ret = E_OK;
        }
        else if(priority ==  INTERRUPT_PRIORITY_LOW )
        {
            USART_TRANS_INTERRUPT_PRIORITY_LOW();
            ret = E_OK;
        }
        else{/*nothing*/}
        #endif

        USART_TRANS_INTERRUPT_ENABLE();
    return ret;        
}
Std_ReturnType INTERRUPT_USART_TRANS_deinitialization (void){
    Std_ReturnType ret = E_NOT_OK;
    USART_TRANS_INTERRUPT_DISABLE();
    ret = E_OK;
    return ret; 
}
#endif
/*****************************UASRT TRANSMISSION INTERRUPT END*********************************/

/*****************************UASRT RECEIVING INTERRUPT START*********************************/
#if INTERRUPT_USART_RECEIVE==FEATURE_ENABLED
Std_ReturnType INTERRUPT_USART_RECEIVE_initialization (interrupt_priority_LEVEL priority ){
    
        Std_ReturnType ret = E_NOT_OK;

        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_PRIORITY_HIGH_ENABLE();
        INTERRUPT_PRIORITY_LOW_ENABLE();
        #endif

        #if INTERRUPT_GLOBAL==FEATURE_ENABLED
        INTERRUPT_GLOBAL_ENABLE();
        #endif

        #if INTERRUPT_PERIFERALS==FEATURE_ENABLED
        INTERRUPT_PERIFERALS_ENABLE();
        #endif
        USART_RECEIVE_INTERRUPT_DISABLE();
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        if(priority ==  INTERRUPT_PRIORITY_HIGH )
        {
            USART_RECEIVE_INTERRUPT_PRIORITY_HIHG();
            ret = E_OK;
        }
        else if(priority ==  INTERRUPT_PRIORITY_LOW )
        {
            USART_RECEIVE_INTERRUPT_PRIORITY_LOW();
            ret = E_OK;
        }
        else{/*nothing*/}
        #endif

        USART_RECEIVE_INTERRUPT_ENABLE();
    return ret;        
}
Std_ReturnType INTERRUPT_USART_RECEIVE_deinitialization (void){
    Std_ReturnType ret = E_NOT_OK;
    USART_RECEIVE_INTERRUPT_DISABLE();
    ret = E_OK;
    return ret; 
}
#endif
/*****************************UASRT RECEIVING INTERRUPT END*********************************/

/*****************************SPI INTERRUPT START*********************************/
#if INTERRUPT_SPI==FEATURE_ENABLED
Std_ReturnType INTERRUPT_SPI_initialization (interrupt_priority_LEVEL priority ){
    
        Std_ReturnType ret = E_NOT_OK;

        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_PRIORITY_HIGH_ENABLE();
        INTERRUPT_PRIORITY_LOW_ENABLE();
        #endif

        #if INTERRUPT_GLOBAL==FEATURE_ENABLED
        INTERRUPT_GLOBAL_ENABLE();
        #endif

        #if INTERRUPT_PERIFERALS==FEATURE_ENABLED
        INTERRUPT_PERIFERALS_ENABLE();
        #endif
        SPI_INTERRUPT_DISABLE();
        SPI_INTERRUPT_CLEAR_FALG();
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        if(priority ==  INTERRUPT_PRIORITY_HIGH )
        {
            SPI_INTERRUPT_PRIORITY_HIHG();
            ret = E_OK;
        }
        else if(priority ==  INTERRUPT_PRIORITY_LOW )
        {
            SPI_INTERRUPT_PRIORITY_LOW();
            ret = E_OK;
        }
        else{/*nothing*/}
        #endif

        SPI_INTERRUPT_ENABLE();
    return ret;        
}
Std_ReturnType INTERRUPT_SPI_deinitialization (void){
    Std_ReturnType ret = E_NOT_OK;
    SPI_INTERRUPT_DISABLE();
    ret = E_OK;
    return ret; 
}
#endif
/*****************************SPI INTERRUPT END*********************************/