/* 
 * File:   hal_ccp1.C
 * Author: YaseenEzzat
 *
 * Created on November 9, 2023, 11:37 AM
 */

#include "hal_ccp1.h"


void ISR_CCP1 (void);

void (*CCP1_interrupt_handler) (void) = NULL;

#if CCP1_CAPTURE_MODE_STATUS==ENABLE
Std_ReturnType CCP1_capture_mode_initialization (const CCP1_config_t *CCP1_cfg ){
    Std_ReturnType ret = E_NOT_OK;
    pin_config_t ccp1_pin ={
      .DIRECTOION = GPIO_PIN_INPUT,
      .LOGIC = GPIO_PIN_LOW,
      .PORT = portC,
      .PIN = GPIO_PIN2
    };
    if(NULL==CCP1_cfg)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Disable capture mode
        CCP1_CAPTURE_MODE_DISABLE();
        //config capture interrupt
        #if INTERRUPT_CCP1==FEATURE_ENABLED
        ret = INTERRUPT_CCP1_initialization(CCP1_cfg->priority_LEVEL);
        CCP1_interrupt_handler = CCP1_cfg->CCP1_interrupt_handler ;
        #endif
        //set CCP1 PIN input
        ret = GPIO_PIN_directoin_intialization(&ccp1_pin);
        //set source timer
        if (CCP1_cfg->capture_timer_src == timer1)
        {
             CCP1_SET_MODULE_TIMER_SOURCE_T3CCP1_BIT (0);
             CCP1_SET_MODULE_TIMER_SOURCE_T3CCP2_BIT (0);
        }
        else if (CCP1_cfg->capture_timer_src == timer3)
        {
            CCP1_SET_MODULE_TIMER_SOURCE_T3CCP1_BIT (1);
            CCP1_SET_MODULE_TIMER_SOURCE_T3CCP2_BIT (1);
        }
        else{/*nothing*/}
        //set capture mode
        CCP1_SET_CAPTURE_MODE(CCP1_cfg->capture_config);
    
    }
    return ret;
}
Std_ReturnType CCP1_capture_mode_deinitialization (const CCP1_config_t *CCP1_cfg ){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==CCP1_cfg)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Disable capture mode
        CCP1_CAPTURE_MODE_DISABLE();
        #if INTERRUPT_CCP1==FEATURE_ENABLED
        ret = INTERRUPT_CCP1_deinitialization();
        #endif
        
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType CCP1_capture_read_value(const CCP1_config_t *CCP1_cfg , uint16 *cptured_value){
    Std_ReturnType ret = E_NOT_OK;
    uint16 temp_CCP1H = CCP1_HIGH_REG;
    uint16 temp_CCP1L = CCP1_LOW_REG;
    if((NULL==CCP1_cfg)||(NULL==cptured_value))
    {
        ret = E_NOT_OK;
    }
    else
    {
       
            *cptured_value = (temp_CCP1H<<8)+temp_CCP1L;
            ret = E_OK;
    }
    return ret;
}

#endif
#if CCP1_COPMPARE_MODE_STATUS==ENABLE
Std_ReturnType CCP1_compare_mode_initialization (const CCP1_config_t *CCP1_cfg ){
    Std_ReturnType ret = E_NOT_OK;
     pin_config_t ccp1_pin ={
      .DIRECTOION = GPIO_PIN_OUTPUT,
      .LOGIC = GPIO_PIN_LOW,
      .PORT = portC,
      .PIN = GPIO_PIN2
    };
    if(NULL==CCP1_cfg)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Disable compare mode
        CCP1_COMPARE_MODE_DISABLE();
        //config compare interrupt
        #if INTERRUPT_CCP1==FEATURE_ENABLED
        ret = INTERRUPT_CCP1_initialization(CCP1_cfg->priority_LEVEL);
        CCP1_interrupt_handler = CCP1_cfg->CCP1_interrupt_handler ;
        #endif
        //set CCP1 PIN output
        ret = GPIO_PIN_directoin_intialization(&ccp1_pin);
        //set source timer
        if (CCP1_cfg->compare_timer_src == timer1)
        {
             CCP1_SET_MODULE_TIMER_SOURCE_T3CCP1_BIT (0);
             CCP1_SET_MODULE_TIMER_SOURCE_T3CCP2_BIT (0);
        }
        else if (CCP1_cfg->compare_timer_src == timer3)
        {
            CCP1_SET_MODULE_TIMER_SOURCE_T3CCP1_BIT (1);
            CCP1_SET_MODULE_TIMER_SOURCE_T3CCP2_BIT (1);
        }
        else{/*nothing*/}
        //set preload compare value
        ret = CCP1_compare_mode_set_preload_value(&CCP1_cfg,CCP1_cfg->preload_value);
        //set capture mode
        CCP1_SET_COMPARE_MODE(CCP1_cfg->compare_config);

    }
    return ret;
}
Std_ReturnType CCP1_compare_mode_deitialization (const CCP1_config_t *CCP1_cfg ){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==CCP1_cfg)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Disable compare mode
        CCP1_COMPARE_MODE_DISABLE();
        #if INTERRUPT_CCP1==FEATURE_ENABLED
        ret = INTERRUPT_CCP1_deinitialization();
        #endif
        
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType CCP1_compare_mode_set_preload_value (const CCP1_config_t *CCP1_cfg ,uint16 preload_value){
    Std_ReturnType ret = E_NOT_OK;
    uint16 temp_CCP1H = 0;
    if(NULL==CCP1_cfg)
    {
        ret = E_NOT_OK;
    }
    else
    {
      
        temp_CCP1H  = preload_value>>8;
        CCP1_HIGH_REG = (uint8) temp_CCP1H;
        CCP1_LOW_REG = (uint8) preload_value;
        
        ret = E_OK;
    }
    return ret;
}
#endif
#if CCP1_PWM_MODE_STATUS==ENABLE
Std_ReturnType CCP1_PWM_mode_initialization (const CCP1_config_t *CCP1_cfg ){
    Std_ReturnType ret = E_NOT_OK;
     pin_config_t ccp1_pin ={
      .DIRECTOION = GPIO_PIN_OUTPUT,
      .LOGIC = GPIO_PIN_LOW,
      .PORT = portC,
      .PIN = GPIO_PIN2
    };
    if(NULL==CCP1_cfg)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Disable PWM mode
        CCP1_PWM_DISABLE();
        //config PWM interrupt
        #if INTERRUPT_CCP1==FEATURE_ENABLED
        ret = INTERRUPT_CCP1_initialization(CCP1_cfg->priority_LEVEL);
        CCP1_interrupt_handler = CCP1_cfg->CCP1_interrupt_handler ;
        #endif
        //set CCP1 PIN output
        ret = GPIO_PIN_directoin_intialization(&ccp1_pin);
        //set PR2 with PWM period
        PR2 = (uint8)((_XTAL_FREQ)/((CCP1_cfg->PWM_frequency)*4*
                 (CCP1_cfg->postscale_vlaue)*(CCP1_cfg->Prescale_vlaue)))-1;
        //set duty cycle value
        ret = CCP1_PWM_mode_set_duty_cycle(&CCP1_cfg,CCP1_cfg->defualt_PWM_duty_cycle);

    }
    return ret;
    }
Std_ReturnType CCP1_PWM_mode_deinitialization (const CCP1_config_t *CCP1_cfg ){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==CCP1_cfg)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Disable PWM mode
        CCP1_PWM_DISABLE();
        #if INTERRUPT_CCP1==FEATURE_ENABLED
        ret = INTERRUPT_CCP1_deinitialization();
        #endif
        
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType CCP1_PWM_mode_set_duty_cycle (const CCP1_config_t *CCP1_cfg , uint8 duty_cycle_value ){
    Std_ReturnType ret = E_NOT_OK;
    uint16 _10bit_reg = 0;
    if(NULL==CCP1_cfg)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
        _10bit_reg = (uint16)((PR2+1)*(duty_cycle_value)*4)/100;
        CCP1CONbits.DC1B = (uint8)(_10bit_reg & 0x03);
        CCP1_LOW_REG = (uint8)(_10bit_reg>>2);
        ret = E_OK;
    }
    return ret;
}


Std_ReturnType CCP1_PWM_START (const CCP1_config_t *CCP1_cfg ){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==CCP1_cfg)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //ENABLE PWM mode
        CCP1_PWM_ENABLE();
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType CCP1_PWM_STOP (const CCP1_config_t *CCP1_cfg ){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==CCP1_cfg)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Disable PWM mode
        CCP1_PWM_DISABLE();        
        ret = E_OK;
    }
    return ret;
}
#endif

void ISR_CCP1 (void){
    CCP1_INTERRUPT_CLEAR_FALG();

    if (CCP1_interrupt_handler!=NULL)
    {
        CCP1_interrupt_handler();
    }
}