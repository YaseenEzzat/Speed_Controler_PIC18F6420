/* 
 * File:   hal_timer1.c
 * Author: YaseenEzzat
 *
 * Created on November 8, 2023, 7:41 AM
 */


#include "hal_timer1.h"

 void(*TIMER1_interrupt_handler) (void) = NULL;
 void ISR_TIMER1 (void);

static Std_ReturnType read_8bit_vlaue ( uint16 *value);
static void write_8bit_vlaue ( uint16 value);
static Std_ReturnType read_16bit_vlaue ( uint16 *value);
static void write_16bit_vlaue ( uint16 value);

static volatile uint16 preload_value = 0;
static volatile uint8  TIMER1_BIT_TYPE = 0;

Std_ReturnType TIMER1_initialization (const TIMER1_config_t *TIMER1_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(TIMER1_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //TIMER1 disable
        TIMER1_DISABLE();
        
        //set clk source
        if(TIMER1_obj->TIMER1_clock_source == TIMER1_internal_clk_source)
        {
            TIMER1_INTERNAL_CLK_SOURCE();
        }
        else if(TIMER1_obj->TIMER1_clock_source == TIMER1_external_clk_source)
        {
            TIMER1_EXTERNAL_CLK_SOURCE_T13CKI();
            //set T1CK counter synchronization mode if external source is enable
            if(TIMER1_obj->TIMER1_synchronization == T1CKI_synchronize )
            {
            TIMER1_EXTERNAL_CLK_SOURCE_SYNCHROINZE();
            }
            else if(TIMER1_obj->TIMER1_synchronization == T1CKI_asynchronize )
            {
            TIMER1_EXTERNAL_CLK_SOURCE_ASYNCHROINZE();
            }
            else {/*nothing*/}
        }
        else {/*nothing*/}
        
        //TIMER1 enable/disable Oscillator
        if(TIMER1_obj->TIMER1_OSC == TIMER1_OSC_enable)
        {
           TIMER1_OSC_ENABLE();
        }
        else if(TIMER1_obj->TIMER1_OSC == TIMER1_OSC_disable)
        {
            TIMER1_OSC_DISABLE();
        }
        else {/*nothing*/}
        
        //set prescaler value
        TIMER1_PRESCALER_SET_VALUE(TIMER1_obj->TIMER1_prescale_vlaue);
        
        //set read and write bit mode 
        if(TIMER1_obj->TIMER1_BIT_mode == TIMER1_16_BIT_mode)
        {
            TIMER1_ENABLE_16BIT_MODE();
        }
        else if(TIMER1_obj->TIMER1_BIT_mode == TIMER1_8_BIT_mode)
        {
            TIMER1_ENABLE_8BIT_MODE();
        }
        else {/*nothing*/}
        
        TIMER1_BIT_TYPE = TIMER1_obj->TIMER1_BIT_mode;
        
        //write counter register value
        TIMER1_write_counter_reg_vlaue(TIMER1_obj , TIMER1_obj->TIMER1_counter_reg_value );
        preload_value = TIMER1_obj->TIMER1_counter_reg_value;
        
        //set interrupt configs
        #if INTERRUPT_TIMER1==FEATURE_ENABLED
        ret = INTERRUPT_TIMER1_initialization(TIMER1_obj->priority_LEVEL);
        TIMER1_interrupt_handler = TIMER1_obj->TIMER1_interrupt_handler  ;
        #endif

        //enable TIMER1
        TIMER1_ENABLE();
    }
    return ret;
    
}
Std_ReturnType TIMER1_denitialization (const TIMER1_config_t *TIMER1_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(TIMER1_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //TIMER1 disable
        TIMER1_DISABLE();
        #if INTERRUPT_TIMER1==FEATURE_ENABLED
        ret = INTERRUPT_TIMER1_deinitialization();
        #endif
        ret = E_OK;
    }
    return ret;
    
}
Std_ReturnType TIMER1_read_counter_reg_vlaue (const TIMER1_config_t *TIMER1_obj , uint16 *value){
    Std_ReturnType ret = E_NOT_OK;
    if((TIMER1_obj==NULL)||(value==NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(TIMER1_obj->TIMER1_BIT_mode == TIMER1_16_BIT_mode)
        {
            ret = read_16bit_vlaue(value );
            
        }
        else if(TIMER1_obj->TIMER1_BIT_mode == TIMER1_8_BIT_mode)
        {
            ret = read_8bit_vlaue(value );
            
        }
        
        else{/*nothing*/}
        
    }
    return ret;
    
}
Std_ReturnType TIMER1_write_counter_reg_vlaue (const TIMER1_config_t *TIMER1_obj , uint16 value){
    Std_ReturnType ret = E_NOT_OK;
    if(TIMER1_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(TIMER1_obj->TIMER1_BIT_mode == TIMER1_16_BIT_mode)
        {
            write_16bit_vlaue(value);
            ret = E_OK;
        }
        else if(TIMER1_obj->TIMER1_BIT_mode == TIMER1_8_BIT_mode)
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
        *value = TIMER1_LOW_REGISTER;
        ret = E_OK;
    }
    return ret;
    
}
static void write_8bit_vlaue ( uint16 value){
        TIMER1_LOW_REGISTER = (uint8)value;
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
        temp_timerL = TIMER1_LOW_REGISTER;
        temp_timerH = TIMER1_HIGH_REGISTER;
       
        *value = (uint16)((temp_timerH<<8) + temp_timerL);
        
        ret = E_OK;
    }
    return ret;
    
}
static void write_16bit_vlaue ( uint16 value){
    uint16 temp_timerL = 0;
    uint16 temp_timerH = 0;
    
    temp_timerH  = value>>8;
    TIMER1_HIGH_REGISTER = (uint8) temp_timerH;
    TIMER1_LOW_REGISTER =  (uint8) value;

}

 void ISR_TIMER1 (void){
     TIMER1_INTERRUPT_CLEAR_FALG();
     if(TIMER1_BIT_TYPE == TIMER1_8_BIT_mode)
     {
         write_8bit_vlaue(preload_value);
     }
     else if(TIMER1_BIT_TYPE == TIMER1_16_BIT_mode)
     {
         write_16bit_vlaue(preload_value);
     }
     if(TIMER1_interrupt_handler!=NULL)
     {
         TIMER1_interrupt_handler ();
     }
 }