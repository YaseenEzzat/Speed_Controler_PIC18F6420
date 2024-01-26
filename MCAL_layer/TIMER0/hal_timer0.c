/* 
 * File:   hal_timer0.c
 * Author: YaseenEzzat
 *
 * Created on November 6, 2023, 12:11 PM
 */

#include "hal_timer0.h"
 void(*TIMER0_interrupt_handler) (void) = NULL;
 void ISR_TIMER0 (void);

static Std_ReturnType read_8bit_vlaue ( uint16 *value);
static void write_8bit_vlaue ( uint16 value);
static Std_ReturnType read_16bit_vlaue ( uint16 *value);
static void write_16bit_vlaue ( uint16 value);

static volatile uint16 preload_value = 0;
static volatile uint8  TIMER0_BIT_TYPE = 0;

Std_ReturnType TIMER0_initialization (const TIMER0_config_t *TIMER0_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(TIMER0_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //TIMER0 disable
        TIMER0_DISABLE();
        
        //set clk source
        if(TIMER0_obj->TIMER0_clock_source == TIMER0_internal_clk_source)
        {
            TIMER0_INTERNAL_CLK_SOURCE();
        }
        else if(TIMER0_obj->TIMER0_clock_source == TIMER0_external_clk_source)
        {
            TIMER0_EXTERNAL_CLK_SOURCE_T0CKI();
            //set T0CK counter increment state if counter mode is enable
            if(TIMER0_obj->T0CKI_egde == TIMER0_falling_edge)
            {
            TIMER0_T0CK_INCREMENT_ON_FALLING_EDGE();
            }
            else if(TIMER0_obj->T0CKI_egde == TIMER0_rising_edge)
            {
            TIMER0_T0CK_INCREMENT_ON_RISING_EDGE();
            }
            else {/*nothing*/}
        }
        else {/*nothing*/}
        
        
        //enable or disable prescaler
        if(TIMER0_obj->TIMER0_prescaler_state == TIMER0_prescaler_enable)
        {
            TIMER0_PRESCALER_ENABLE();
            //set prescaler vlue if enable
            TIMER0_PRESCALER_SET_VALUE(TIMER0_obj->TIMER0_prescale_vlaue);
        }
        else if(TIMER0_obj->TIMER0_prescaler_state == TIMER0_prescaler_disable)
        {
            TIMER0_PRESCALER_DISABLE();
        }
        else {/*nothing*/}
        
        
        //set bit mode 
        if(TIMER0_obj->TIMER0_BIT_mode == TIMER0_16_BIT_mode)
        {
            TIMER0_ENABLE_16BIT_MODE();
        }
        else if(TIMER0_obj->TIMER0_BIT_mode == TIMER0_8_BIT_mode)
        {
            TIMER0_ENABLE_8BIT_MODE();
        }
        else {/*nothing*/}
        
        TIMER0_BIT_TYPE = TIMER0_obj->TIMER0_BIT_mode;
        
        //write counter register value
        TIMER0_write_counter_reg_vlaue(TIMER0_obj , TIMER0_obj->TIMER0_counter_reg_value );
        preload_value = TIMER0_obj->TIMER0_counter_reg_value;
        
        //set interrupt configs
        #if INTERRUPT_TIMER0==FEATURE_ENABLED
        ret = INTERRUPT_TIMER0_initialization(TIMER0_obj->priority_LEVEL);
        TIMER0_interrupt_handler = TIMER0_obj->interrupt_handler  ;
        #endif

        //enable TIMER0
        TIMER0_ENABLE();
    }
    return ret;
    
}
Std_ReturnType TIMER0_denitialization (const TIMER0_config_t *TIMER0_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(TIMER0_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //TIMER0 disable
        TIMER0_DISABLE();
        #if INTERRUPT_TIMER0==FEATURE_ENABLED
        ret = INTERRUPT_TIMER0_deinitialization();
        #endif
        ret = E_OK;
    }
    return ret;
    
}
Std_ReturnType TIMER0_read_counter_reg_vlaue (const TIMER0_config_t *TIMER0_obj , uint16 *value){
    Std_ReturnType ret = E_NOT_OK;
    if((TIMER0_obj==NULL)||(value==NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(TIMER0_obj->TIMER0_BIT_mode == TIMER0_16_BIT_mode)
        {
            ret = read_16bit_vlaue(value );
            
        }
        else if(TIMER0_obj->TIMER0_BIT_mode == TIMER0_8_BIT_mode)
        {
            ret = read_8bit_vlaue(value );
            
        }
        
        else{/*nothing*/}
        
    }
    return ret;
    
}
Std_ReturnType TIMER0_write_counter_reg_vlaue (const TIMER0_config_t *TIMER0_obj , uint16 value){
    Std_ReturnType ret = E_NOT_OK;
    if(TIMER0_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(TIMER0_obj->TIMER0_BIT_mode == TIMER0_16_BIT_mode)
        {
            write_16bit_vlaue(value);
            ret = E_OK;
        }
        else if(TIMER0_obj->TIMER0_BIT_mode == TIMER0_8_BIT_mode)
        {
            write_16bit_vlaue(value );
            ret = E_OK;
        }
        
        else{/*nothing*/}
    }
    return ret;
    
}


static Std_ReturnType read_8bit_vlaue ( uint16 *value){
    Std_ReturnType ret = E_NOT_OK;
    if(value==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *value = TIMER0_LOW_REGISTER;
        ret = E_OK;
    }
    return ret;
    
}
static void write_8bit_vlaue ( uint16 value){
        TIMER0_LOW_REGISTER = (uint8)value;
}


static Std_ReturnType read_16bit_vlaue (uint16 *value){
    Std_ReturnType ret = E_NOT_OK;
    uint16 temp_timerL = 0;
    uint16 temp_timerH = 0;
   if(value==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        temp_timerL = TIMER0_LOW_REGISTER;
        temp_timerH = TIMER0_HIGH_REGISTER;
       
        *value = (uint16)((temp_timerH<<8) + temp_timerL);
        
        ret = E_OK;
    }
    return ret;
    
}
static void write_16bit_vlaue ( uint16 value){
    uint16 temp_timerL = 0;
    uint16 temp_timerH = 0;
    
    temp_timerH  = value>>8;
    TIMER0_HIGH_REGISTER = (uint8) temp_timerH;
    TIMER0_LOW_REGISTER =  (uint8) value;

}

 void ISR_TIMER0 (void){
     TIMER0_INTERRUPT_CLEAR_FALG();
     if(TIMER0_BIT_TYPE == TIMER0_8_BIT_mode)
     {
         write_8bit_vlaue(preload_value);
     }
     else if(TIMER0_BIT_TYPE == TIMER0_16_BIT_mode)
     {
         write_16bit_vlaue(preload_value);
     }
     if(TIMER0_interrupt_handler!=NULL)
     {
         TIMER0_interrupt_handler ();
     }
 }