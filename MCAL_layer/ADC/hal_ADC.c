/* 
 * File:   hal_ADC.c
 * Author: YaseenEzzat
 *
 * Created on November 4, 2023, 1:44 AM
 */
#include "hal_ADC.h"
void (*ADC_INTRRUPT_HANDLER)(void)=NULL;
void ISR_ADC (void);

static Std_ReturnType read_ADC_RESULT_RIGHT_JUSTIFIED (ADC_config_t *ADC_obj  ,uint8 *value);
static Std_ReturnType ADC_Configure_voltage_reference (ADC_config_t *ADC_obj);
static Std_ReturnType ADC_set_channel_pin_direction (ADC_channel_t CHANNEL);



/**
 * 
 * @param ADC_obj
 * @return 
 */
Std_ReturnType ADC_initialization (const ADC_config_t *ADC_obj){
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL==ADC_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Turn off A/D module
        ADC_CONVERTER_MODULE_DISABLE();
        //Configure analog digital I/O  pins
        ADC_PINS_CONFIGERATION(ADC_obj->pins);
        //Configure voltage reference
        ADC_Configure_voltage_reference(ADC_obj);
        //Select A/D input channel
        ADC_CHANNEL_SELECT(ADC_obj->channel);
        //input channel initialization 
        ADC_set_channel_pin_direction(ADC_obj->channel);
        //Select A/D acquisition time
        ADC_CONVERSION_ACQUISITION_TIME_SELECT(ADC_obj->Acquisition_time);
        //Select A/D conversion clock
        ADC_CONVERSION_CLCK_SELECT(ADC_obj->CLCK_SELECT);
        //Select right result justified
        ADC_RESULT_RIGHT_JUSTIFIED();
        //Turn on A/D module
        ADC_CONVERTER_MODULE_ENABLE();
        //Configure A/D interrupt
        #if INTERRUPT_ADC==FEATURE_ENABLED
        ADC_INTRRUPT_HANDLER = ADC_obj->ADC_INTRRUPT_HANDLER;
        INTERRUPT_ADC_initialization(ADC_obj->priority);
        #endif
                                      

    }
    return ret;
}


/**
 * 
 * @param ADC_obj
 * @return 
 */
Std_ReturnType ADC_deinitialization (const ADC_config_t *ADC_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==ADC_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Turn off A/D module
        ADC_CONVERTER_MODULE_DISABLE();
        #if INTERRUPT_ADC==FEATURE_ENABLED
        INTERRUPT_ADC_deinitialization();
        #endif
        ret = E_OK;
    }
    return ret;
}
   


/**
 * 
 * @param ADC_obj
 * @param value
 * @return 
 */
Std_ReturnType ADC_read_converted_value (const ADC_config_t *ADC_obj , uint16 *value){
    Std_ReturnType ret = E_NOT_OK;
    uint16 ADRESH_value = 0;
    uint16 ADRESL_value = 0;
    if((NULL==ADC_obj)||(NULL==value))
    {
        ret = E_NOT_OK;
    }
    else
    {
        if (ADC_obj->result_format == right_result_justified)
        {
            ADRESL_value = ADRESL;
            ADRESH_value = ADRESH;
            
            *value = (ADRESL_value+(256*ADRESH_value)); 
            //OR *value = (ADRESH_value << 8) + ADRESL_value 
        }
        else if (ADC_obj->result_format == left_result_justified)
        {
            ADRESL_value = ADRESL;
            ADRESH_value = ADRESH;
            
            *value = (((ADRESH_value << 8) + ADRESL_value )>>6);
        }
        else
        {
            *value = (ADRESL_value+(256*ADRESH_value)); 
        }
           
            
        
        ret = E_OK;
    }
    return ret;
}


/**
 * 
 * @param ADC_obj
 * @return 
 */
Std_ReturnType ADC_start_conversion (const ADC_config_t *ADC_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==ADC_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Start conversion
        ADC_CONVERSION_START();
        ret = E_OK;
        
    }
    return ret;
    
}


/**
 * 
 * @param ADC_obj
 * @param CHANNEL
 * @return 
 */
Std_ReturnType ADC_SELECT_CHANNEL (const ADC_config_t *ADC_obj , ADC_channel_t CHANNEL){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==ADC_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //select channel
        ADC_CHANNEL_SELECT(CHANNEL);
        ADC_set_channel_pin_direction(CHANNEL);
        ret = E_OK;
        
    }
    return ret;
}


/**
 * 
 * @param ADC_obj
 * @param CHANNEL
 * @param value
 * @return 
 */
Std_ReturnType ADC_select_convert_read_blocking (const ADC_config_t *ADC_obj 
                                                 , ADC_channel_t CHANNEL , uint16 *value){
    Std_ReturnType ret = E_NOT_OK;
    if((NULL==ADC_obj)||(NULL==value))
    {
        ret = E_NOT_OK;
    }
    else
    {
        //select channel
        ADC_SELECT_CHANNEL(ADC_obj,CHANNEL);
        //Start conversion
        ADC_start_conversion(ADC_obj);
        //read conversion blocking
        while(ADC_CONVERSION_STATEUS);
        ADC_read_converted_value(ADC_obj ,value );
        ret = E_OK;
    }
    return ret;
}


/**
 * 
 * @param ADC_obj
 * @param CHANNEL
 * @return 
 */
Std_ReturnType ADC_select_convert_interrupt (const ADC_config_t *ADC_obj , ADC_channel_t CHANNEL ){
    Std_ReturnType ret = E_NOT_OK;
    if((NULL==ADC_obj))
    {
        ret = E_NOT_OK;
    }
    else
    {
        //select channel
        ADC_SELECT_CHANNEL(ADC_obj,CHANNEL);
        //Start conversion
        ADC_start_conversion(ADC_obj);
        ret = E_OK;
    }
    return ret;
}


/**
 * 
 * @param ADC_obj
 * @return 
 */
static Std_ReturnType ADC_Configure_voltage_reference (ADC_config_t *ADC_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==ADC_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(ADC_obj->voltage_reference == voltage_reference_internal )
        {
            ADC_VOLTAGE_REFERENCE_INTERNAL_Vss();
            ADC_VOLTAGE_REFERENCE_INTERNAL_VDD();
            ret = E_OK;
        }
        else if(ADC_obj->voltage_reference == voltage_reference_external )
        {
            ADC_VOLTAGE_REFERENCE_EXTERNAL_AN2();
            ADC_VOLTAGE_REFERENCE_EXTERNAL_AN3();
            ret = E_OK;
        }
        else
        {
            ADC_VOLTAGE_REFERENCE_INTERNAL_Vss();
            ADC_VOLTAGE_REFERENCE_INTERNAL_VDD();
            ret = E_OK;
        }
    }
    return ret;
}


/**
 * 
 * @param ADC_obj
 * @return 
 */
static Std_ReturnType ADC_set_channel_pin_direction (ADC_channel_t CHANNEL){
    Std_ReturnType ret = E_NOT_OK;
    
        switch (CHANNEL){
            case Channel_0   : SET_BIT(TRISA,0); ret = E_NOT_OK; break;
            case Channel_1   : SET_BIT(TRISA,1); ret = E_NOT_OK; break;
            case Channel_2   : SET_BIT(TRISA,2); ret = E_NOT_OK; break;
            case Channel_3   : SET_BIT(TRISA,3); ret = E_NOT_OK; break;
            case Channel_4   : SET_BIT(TRISA,5); ret = E_NOT_OK; break;
            case Channel_5   : SET_BIT(TRISE,0); ret = E_NOT_OK; break;
            case Channel_6   : SET_BIT(TRISE,1); ret = E_NOT_OK; break;
            case Channel_7   : SET_BIT(TRISE,2); ret = E_NOT_OK; break;
            case Channel_8   : SET_BIT(TRISB,2); ret = E_NOT_OK; break;
            case Channel_9   : SET_BIT(TRISB,3); ret = E_NOT_OK; break;
            case Channel_10  : SET_BIT(TRISB,1); ret = E_NOT_OK; break;
            case Channel_11  : SET_BIT(TRISB,4); ret = E_NOT_OK; break;
            case Channel_12  : SET_BIT(TRISB,0); ret = E_NOT_OK; break;
            
                    
        }
    
    
    return ret;
}
void ISR_ADC (void){
    ADC_INTERRUPT_CLEAR_FALG();
    if(NULL!=ADC_INTRRUPT_HANDLER)
        ADC_INTRRUPT_HANDLER();
}