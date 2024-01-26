/* 
 * File:   hal_timer2.c
 * Author: YaseenEzzat
 *
 * Created on November 8, 2023, 11:24 AM
 */
#include "hal_timer2.h"

 void(*TIMER2_interrupt_handler) (void) = NULL;
 void ISR_TIMER2 (void);


static volatile uint8 preload_value = 0;

Std_ReturnType TIMER2_initialization (const TIMER2_config_t *TIMER2_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(TIMER2_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //TIMER2 disable
        TIMER2_DISABLE();
               
        //set prescaler value
        TIMER2_PRESCALER_SET_VALUE(TIMER2_obj->TIMER2_prescale_vlaue);
        //set postscaler value
        TIMER2_POSTSCALER_SET_VALUE(TIMER2_obj->TIMER2_postscale_vlaue);
        
        //write counter register value
        TIMER2_write_counter_reg_vlaue(TIMER2_obj , TIMER2_obj->TIMER2_counter_reg_value );
        preload_value = TIMER2_obj->TIMER2_counter_reg_value;
        
        //set interrupt configs
        #if INTERRUPT_TIMER1==FEATURE_ENABLED
        ret = INTERRUPT_TIMER2_initialization(TIMER2_obj->priority_LEVEL);
        TIMER2_interrupt_handler = TIMER2_obj->TIMER2_interrupt_handler  ;
        #endif

        //enable TIMER0
        TIMER2_ENABLE();
    }
    return ret;
    
}
Std_ReturnType TIMER2_denitialization (const TIMER2_config_t *TIMER2_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(TIMER2_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //TIMER2 disable
        TIMER2_DISABLE();
        #if INTERRUPT_TIMER2==FEATURE_ENABLED
        ret = INTERRUPT_TIMER2_deinitialization();
        #endif
        ret = E_OK;
    }
    return ret;
    
}
Std_ReturnType TIMER2_read_counter_reg_vlaue (const TIMER2_config_t *TIMER2_obj , uint8 *value){
    Std_ReturnType ret = E_NOT_OK;
    if((TIMER2_obj==NULL)||(value==NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *value = TIMER_R_W_REGISTER;
        ret = E_OK;
    }
    return ret;
    
}
Std_ReturnType TIMER2_write_counter_reg_vlaue (const TIMER2_config_t *TIMER2_obj , uint8 value){
    Std_ReturnType ret = E_NOT_OK;
    if(TIMER2_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
       
        TIMER_R_W_REGISTER = value;
        ret = E_OK;
    }
    return ret;
    
}


 void ISR_TIMER2 (void){
     TIMER2_INTERRUPT_CLEAR_FALG();
     TIMER_R_W_REGISTER = preload_value;
     if(TIMER2_interrupt_handler!=NULL)
     {
         TIMER2_interrupt_handler ();
     }
 }