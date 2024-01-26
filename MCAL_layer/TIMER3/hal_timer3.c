/* 
 * File:   hal_timer3.c
 * Author: YaseenEzzat
 *
 * Created on November 8, 2023, 1:03 PM
 */
#include "hal_timer3.h"

 void(*TIMER3_interrupt_handler) (void) = NULL;
 void ISR_TIMER3 (void);

static Std_ReturnType read_8bit_vlaue ( uint16 *value);
static void write_8bit_vlaue ( uint16 value);
static Std_ReturnType read_16bit_vlaue ( uint16 *value);
static void write_16bit_vlaue ( uint16 value);

static volatile uint16 preload_value = 0;
static volatile uint8  TIMER3_BIT_TYPE = 0;

Std_ReturnType TIMER3_initialization (const TIMER3_config_t *TIMER3_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(TIMER3_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //TIMER3 disable
        TIMER3_DISABLE();
        
        //set clk source
        if(TIMER3_obj->TIMER3_clock_source == TIMER3_internal_clk_source)
        {
            TIMER3_INTERNAL_CLK_SOURCE();
        }
        else if(TIMER3_obj->TIMER3_clock_source == TIMER3_external_clk_source)
        {
            TIMER3_EXTERNAL_CLK_SOURCE_T13CKI();
            //set T3CK counter synchronization mode if external source is enable
            if(TIMER3_obj->TIMER3_synchronization == T3CKI_synchronize )
            {
            TIMER3_EXTERNAL_CLK_SOURCE_SYNCHROINZE();
            }
            else if(TIMER3_obj->TIMER3_synchronization == T3CKI_asynchronize )
            {
            TIMER3_EXTERNAL_CLK_SOURCE_ASYNCHROINZE();
            }
            else {/*nothing*/}
        }
        else {/*nothing*/}
        
        //set prescaler value
        TIMER3_PRESCALER_SET_VALUE(TIMER3_obj->TIMER3_prescale_vlaue);
        
        //set read and write bit mode 
        if(TIMER3_obj->TIMER3_BIT_mode == TIMER3_16_BIT_mode)
        {
            TIMER3_ENABLE_16BIT_MODE();
        }
        else if(TIMER3_obj->TIMER3_BIT_mode == TIMER3_8_BIT_mode)
        {
            TIMER3_ENABLE_8BIT_MODE();
        }
        else {/*nothing*/}
        
        TIMER3_BIT_TYPE = TIMER3_obj->TIMER3_BIT_mode;
        
        //write counter register value
        TIMER3_write_counter_reg_vlaue(TIMER3_obj , TIMER3_obj->TIMER3_counter_reg_value );
        preload_value = TIMER3_obj->TIMER3_counter_reg_value;
        
        //set interrupt configs
        #if INTERRUPT_TIMER3==FEATURE_ENABLED
        ret = INTERRUPT_TIMER3_initialization(TIMER3_obj->priority_LEVEL);
        TIMER3_interrupt_handler = TIMER3_obj->TIMER3_interrupt_handler  ;
        #endif

        //enable TIMER3
        TIMER3_ENABLE();
    }
    return ret;
    
}
Std_ReturnType TIMER3_denitialization (const TIMER3_config_t *TIMER3_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(TIMER3_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //TIMER3 disable
        TIMER3_DISABLE();
        #if INTERRUPT_TIMER3==FEATURE_ENABLED
        ret = INTERRUPT_TIMER3_deinitialization();
        #endif
        ret = E_OK;
    }
    return ret;
    
}
Std_ReturnType TIMER3_read_counter_reg_vlaue (const TIMER3_config_t *TIMER3_obj , uint16 *value){
    Std_ReturnType ret = E_NOT_OK;
    if((TIMER3_obj==NULL)||(value==NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(TIMER3_obj->TIMER3_BIT_mode == TIMER3_16_BIT_mode)
        {
            ret = read_16bit_vlaue(value );
            
        }
        else if(TIMER3_obj->TIMER3_BIT_mode == TIMER3_8_BIT_mode)
        {
            ret = read_8bit_vlaue(value );
            
        }
        
        else{/*nothing*/}
        
    }
    return ret;
    
}
Std_ReturnType TIMER3_write_counter_reg_vlaue (const TIMER3_config_t *TIMER3_obj , uint16 value){
    Std_ReturnType ret = E_NOT_OK;
    if(TIMER3_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(TIMER3_obj->TIMER3_BIT_mode == TIMER3_16_BIT_mode)
        {
            write_16bit_vlaue(value);
            ret = E_OK;
        }
        else if(TIMER3_obj->TIMER3_BIT_mode == TIMER3_8_BIT_mode)
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
        *value = TIMER3_LOW_REGISTER;
        ret = E_OK;
    }
    return ret;
    
}
static void write_8bit_vlaue ( uint16 value){
        TIMER3_LOW_REGISTER = (uint8)value;
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
        temp_timerL = TIMER3_LOW_REGISTER;
        temp_timerH = TIMER3_HIGH_REGISTER;
       
        *value = (uint16)((temp_timerH<<8) + temp_timerL);
        
        ret = E_OK;
    }
    return ret;
    
}
static void write_16bit_vlaue ( uint16 value){
    uint16 temp_timerL = 0;
    uint16 temp_timerH = 0;
    
    temp_timerH  = value>>8;
    TIMER3_HIGH_REGISTER = (uint8) temp_timerH;
    TIMER3_LOW_REGISTER =  (uint8) value;

}

 void ISR_TIMER3 (void){
     TIMER3_INTERRUPT_CLEAR_FALG();
     if(TIMER3_BIT_TYPE == TIMER3_8_BIT_mode)
     {
         write_8bit_vlaue(preload_value);
     }
     else if(TIMER3_BIT_TYPE == TIMER3_16_BIT_mode)
     {
         write_16bit_vlaue(preload_value);
     }
     if(TIMER3_interrupt_handler!=NULL)
     {
         TIMER3_interrupt_handler ();
     }
 }

