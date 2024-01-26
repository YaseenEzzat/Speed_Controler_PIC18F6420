/* 
 * File:   hal_usart.c
 * Author: YaseenEzzat
 *
 * Created on November 12, 2023, 6:53 PM
 */
#include "hal_usart.h"

static Std_ReturnType USART_Asynchronous_Baud_rate_clcul(const USART_config_t *USART_config);
static Std_ReturnType USART_Async_trans_config(const USART_config_t *USART_config);
static Std_ReturnType USART_Async_receive_config(const USART_config_t *USART_config);

void(*Receive_Interrupt_handler)(void) = NULL;
void(*Trans_Interrupt_handler)(void) = NULL;

void ISR_USART_Receive(void);
void ISR_USART_Trans(void);


Std_ReturnType USART_Asynchronous_Initialization(const USART_config_t *USART_config ){
    Std_ReturnType ret = E_NOT_OK;
    if(USART_config==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        EUSART_SERIAL_PORT_DISABLE(); 
        TRISCbits.RC7 = 1;
        TRISCbits.RC6 = 1;
        USART_Asynchronous_Baud_rate_clcul(USART_config);
        USART_Async_trans_config(USART_config);
        USART_Async_receive_config(USART_config);
        EUSART_SERIAL_PORT_ENABLE();
        ret = E_OK;
    }
    return ret;
    
}
Std_ReturnType USART_Asynchronous_Deinitialization(const USART_config_t *USART_config ){
    Std_ReturnType ret = E_NOT_OK;
    if(USART_config==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        EUSART_SERIAL_PORT_DISABLE(); 
    }
    return ret;
    
}
Std_ReturnType USART_Asynchronous_write_8_bit_data_Blocking(uint8 data ){
    Std_ReturnType ret = E_OK;
    while (TRANSMIT_SHIFT_REGISTER_STATUS == FULL);
    EUSART_ASYNCHRONOUS_TRASMIT_REG = data;
    #if INTERRUPT_USART_TRANS==FEATURE_ENABLED
    USART_TRANS_INTERRUPT_ENABLE();    
    #endif
    return ret;
    
}
Std_ReturnType USART_Asynchronous_read_8_bit_data_Blocking(uint8 *data ){
    Std_ReturnType ret = E_NOT_OK;
    if(data==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        while (PIR1bits.RCIF == 0);
        *data = EUSART_ASYNCHRONOUS_RECEIVE_REG;
    }
    return ret;
    
}
Std_ReturnType USART_Asynchronous_write_string_Blocking(char *string ){
    Std_ReturnType ret = E_NOT_OK;
    if(string==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
         for (int string_counter = 0 ; string_counter<strlen(string) ; string_counter++ )
         {
             USART_Asynchronous_write_8_bit_data_Blocking (string[string_counter]);
         }
         ret = E_OK;
    }
        
    return ret;
    
}
Std_ReturnType USART_Asynchronous_write_8_bit_data_Non_Blocking(uint8 data ){
    Std_ReturnType ret = E_OK;
    if(USART_TRANS_INTERRUPT_FALG==1)
    {
        EUSART_ASYNCHRONOUS_TRASMIT_REG = data;
        USART_TRANS_INTERRUPT_ENABLE();
        ret = E_OK;
    }
    else {ret = E_NOT_OK;}
    
    return ret;
    
}
Std_ReturnType USART_Asynchronous_read_8_bit_data_Non_Blocking(uint8 *data ){
    Std_ReturnType ret = E_NOT_OK;
    if(data==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if (PIR1bits.RCIF == 1)
        {
            *data = EUSART_ASYNCHRONOUS_RECEIVE_REG;
            ret = E_OK;
        }
        else{ret = E_NOT_OK;} 
    }
    return ret;
    
}
Std_ReturnType USART_Asynchronous_write_string_Non_Blocking(char *string ){
    Std_ReturnType ret = E_NOT_OK;
    int str_counter = 0;
    if(string==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        while (str_counter<strlen(string))
        {
            ret = USART_Asynchronous_write_8_bit_data_Non_Blocking (string[str_counter]);
            if(ret==E_OK)
            {
                str_counter++;
            }
            else{/*nothing*/}
            
            
        }
         ret = E_OK;
        
    }
    return ret;
    
}

static Std_ReturnType USART_Asynchronous_Baud_rate_clcul(const USART_config_t *USART_config){
    Std_ReturnType ret = E_NOT_OK;
    float buad_rate_REG_value = 0;
    if(USART_config==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (USART_config->buad_rate_mode) {
            case Asynchronous_low_speed_8bit:
                EUSART_ASYNCHRONOUS_ENABLE();
                EUSART_ASYNCHRONOUS_8BIT_BAUD_RATE();
                EUSART_ASYNCHRONOUS_LOW_SPEED();
                buad_rate_REG_value = (((_XTAL_FREQ)/(USART_config->buad_rate_value))/64)-1;
                ret = E_OK;
                break;
            case Asynchronous_high_speed_8bit:
                EUSART_ASYNCHRONOUS_ENABLE();
                EUSART_ASYNCHRONOUS_8BIT_BAUD_RATE();
                EUSART_ASYNCHRONOUS_HIGH_SPEED();
                buad_rate_REG_value = (((_XTAL_FREQ)/(USART_config->buad_rate_value))/16)-1;
                ret = E_OK;
                break;
            case Asynchronous_low_speed_16bit:
                EUSART_ASYNCHRONOUS_ENABLE();
                EUSART_ASYNCHRONOUS_16BIT_BAUD_RATE();
                EUSART_ASYNCHRONOUS_LOW_SPEED();
                buad_rate_REG_value = (((_XTAL_FREQ)/(USART_config->buad_rate_value))/16)-1;
                ret = E_OK;
                break;
            case Asynchronous_high_speed_16bit:
                EUSART_ASYNCHRONOUS_ENABLE();
                EUSART_ASYNCHRONOUS_16BIT_BAUD_RATE();
                EUSART_ASYNCHRONOUS_HIGH_SPEED();
                buad_rate_REG_value = (((_XTAL_FREQ)/(USART_config->buad_rate_value))/4)-1;
                ret = E_OK;
                break;
            case synchronous_16bit:
                EUSART_SYNCHRONOUS_ENABLE();
                EUSART_ASYNCHRONOUS_16BIT_BAUD_RATE();
                buad_rate_REG_value = (((_XTAL_FREQ)/(USART_config->buad_rate_value))/4)-1;
                ret = E_OK;
                break;
            case synchronous_8bit:
                EUSART_SYNCHRONOUS_ENABLE();
                EUSART_ASYNCHRONOUS_8BIT_BAUD_RATE();
                buad_rate_REG_value = (((_XTAL_FREQ)/(USART_config->buad_rate_value))/4)-1;
                ret = E_OK;
                break;
            default : ret = E_NOT_OK;    
        }
        
        EUSART_BUAD_RATE_LOW_REG = (uint8)((uint32)buad_rate_REG_value);
        EUSART_BUAD_RATE_HIGH_REG = (uint8)(((uint32)(buad_rate_REG_value))>>8);
    }
    return ret;
    
}

static Std_ReturnType USART_Async_trans_config(const USART_config_t *USART_config){
    Std_ReturnType ret = E_NOT_OK;
    if(USART_config==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    
    {
        if(USART_config->transmission_config.transmission_status == Enable)
        {
            EUSART_TRANSMIT_ENABLE();
            if(USART_config->transmission_config.transmission_frame_bits ==_9_bit_frame )
            {
                EUSART_ASYNCHRONOUS_TRANSMIT_FORMATE_9BIT();
                ret = E_OK;
            }
            else if(USART_config->transmission_config.transmission_frame_bits ==_8_bit_frame )
            {
                EUSART_ASYNCHRONOUS_TRANSMIT_FORMATE_8BIT();
                ret = E_OK;
            }
            else{ret = E_NOT_OK;}
        }
        else if(USART_config->transmission_config.transmission_status == Disable)
        {
            EUSART_TRANSMIT_DISABLE();
            ret = E_OK;
        }
        
        else{ret = E_NOT_OK;}
        
        #if INTERRUPT_USART_TRANS==FEATURE_ENABLED
        ret = INTERRUPT_USART_TRANS_initialization (USART_config->transmission_config.priority_LEVEL);
        Trans_Interrupt_handler = USART_config->transmission_config.Transmit_Interrupt_handler;
        #endif
    }
    return ret;
}
    
static Std_ReturnType USART_Async_receive_config(const USART_config_t *USART_config){
    Std_ReturnType ret = E_NOT_OK;
    if(USART_config==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    
    {
        if(USART_config->receiving_config.receiving_status == Enable)
        {
            EUSART_RECEIVE_ENABLE();
            if(USART_config->receiving_config.receiving_frame_bits ==_9_bit_frame )
            {
                EUSART_ASYNCHRONOUS_RECEIVE_FORMATE_9BIT();
                ret = E_OK;
            }
            else if(USART_config->receiving_config.receiving_frame_bits ==_8_bit_frame )
            {
                EUSART_ASYNCHRONOUS_RECEIVE_FORMATE_8BIT();
                ret = E_OK;
            }
            else{ret = E_NOT_OK;}
        }
        else if(USART_config->receiving_config.receiving_status == Disable)
        {
            EUSART_RECEIVE_DISABLE();
            ret = E_OK;
        }
        else{ret = E_NOT_OK;}
        #if INTERRUPT_USART_RECEIVE==FEATURE_ENABLED
        ret = INTERRUPT_USART_RECEIVE_initialization (USART_config->receiving_config.priority_LEVEL);
        Receive_Interrupt_handler = USART_config->receiving_config.Receive_Interrupt_handler;
        #endif
    }
    return ret;
}

void ISR_USART_Trans(void){
    
    if (Trans_Interrupt_handler != NULL)
    {
        Trans_Interrupt_handler();
    }
    USART_TRANS_INTERRUPT_DISABLE();
}

void ISR_USART_Receive(void){
    
    if (Receive_Interrupt_handler != NULL)
    {
        Receive_Interrupt_handler();
    }
    
}
