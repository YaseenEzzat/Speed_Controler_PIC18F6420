/* 
 * File:   hal_spi.c
 * Author: YaseenEzzat
 *
 * Created on November 15, 2023, 6:51 AM
 */

#include "hal_spi.h"

void(*SPI_INTERRUPT_HANDLER)(void)=NULL;
void ISR_SPI (void);

static Std_ReturnType SPI_Master_config(const SPI_Master_mode_config *Master);
static Std_ReturnType SPI_Slave_config(const SPI_Slave_mode_config *Master);

volatile pin_config_t SS_pin ;
Std_ReturnType SPI_MASTER_Initialization(const SPI_Master_mode_config *Master){
    Std_ReturnType ret = E_NOT_OK;
    if(Master==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        SPI_SERIAL_PORT_DESABLE();
        TRISCbits.RC5=0;
        TRISCbits.RC3=0;
        TRISAbits.RA5=0;
        SPI_MODE_SELSCT(Master->SPI_Master_mode);
        ret = SPI_Master_config(Master);
        ret = GPIO_PIN_write_logic(&(Master->GPIO_SS_pin) , GPIO_PIN_HIGH);
        SS_pin = (Master->GPIO_SS_pin);
        #if INTERRUPT_SPI==FEATURE_ENABLED
        ret = INTERRUPT_SPI_initialization(Master->priority_LEVEL);
        SPI_INTERRUPT_HANDLER = Master->SPI_Master_Interrupt_handler;
        #endif
        SPI_SERIAL_PORT_ENABLE();
    }
    return ret;
}
Std_ReturnType SPI_MASTER_Deinitialization(const SPI_Master_mode_config *Master){
    Std_ReturnType ret = E_NOT_OK;
    if(Master==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        SPI_SERIAL_PORT_DESABLE();
        ret = GPIO_PIN_write_logic(&(Master->GPIO_SS_pin) , GPIO_PIN_LOW); 
        #if INTERRUPT_SPI==FEATURE_ENABLED
        ret = INTERRUPT_SPI_deinitialization();
        #endif
    }
    return ret;
}

Std_ReturnType SPI_SLAVE_Initialization(const SPI_Slave_mode_config *Slave){
    Std_ReturnType ret = E_NOT_OK;
    if(Slave==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        SPI_SERIAL_PORT_DESABLE();
        TRISCbits.RC5=0;
        TRISCbits.RC3=1;
        TRISAbits.RA5=1;
        SPI_MODE_SELSCT(Slave->SPI_Slave_mode);
        ret = SPI_Slave_config(Slave);
        #if INTERRUPT_SPI==FEATURE_ENABLED
        ret = INTERRUPT_SPI_initialization(Slave->priority_LEVEL);
        SPI_INTERRUPT_HANDLER = Slave->SPI_Slave_Interrupt_handler;
        #endif
        SPI_SERIAL_PORT_ENABLE();
    }
    return ret;
}
Std_ReturnType SPI_SLAVE_Deinitialization(const SPI_Slave_mode_config *Slave){
    Std_ReturnType ret = E_NOT_OK;
    if(Slave==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        SPI_SERIAL_PORT_DESABLE();
        #if INTERRUPT_SPI==FEATURE_ENABLED
        ret = INTERRUPT_SPI_deinitialization();
        #endif
    }
    return ret;
}


Std_ReturnType SPI_Master_Write_8_bit_Data_Interrupt(const SPI_Master_mode_config *Master ,uint8 data_write ){
    Std_ReturnType ret = E_NOT_OK;
    if(Master==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
            if(PIR1bits.SSPIF == 0)
            {
                GPIO_PIN_write_logic(&(Master->GPIO_SS_pin) , GPIO_PIN_LOW);
                SPI_BUFFER_REG = data_write;
                ret = E_OK;
            }
            else{ret = E_NOT_OK;}
            
    }
    return ret;
}
Std_ReturnType SPI_Master_Read_8_bit_Data_Interrupt(const SPI_Master_mode_config *Master ,uint8 *data_read){
    Std_ReturnType ret = E_NOT_OK;
    if((Master==NULL)||(data_read==NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        if((PIR1bits.SSPIF == 1)&&(SPI_BUFFER_REG_FULL_STATUS == RECEIVE_COMPLETE_SSPBUF_IS_FULL))
        {
            *data_read = SPI_BUFFER_REG;
            ret = E_OK;
        }
        else{ret = E_NOT_OK;}

    }
    return ret;
}

Std_ReturnType SPI_Slave_Write_8_bit_Data_Interrupt(uint8 data_write){
    Std_ReturnType ret = E_NOT_OK;
            if(PIR1bits.SSPIF == 0)
            {
                SPI_BUFFER_REG = data_write;
                ret = E_OK;
            }
            else{ret = E_NOT_OK;}
    return ret;
}

Std_ReturnType SPI_Slave_Read_8_bit_Data_Interrupt(uint8 *data_read){
    Std_ReturnType ret = E_NOT_OK;
    if(data_read==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if((PIR1bits.SSPIF == 1)&&(SPI_BUFFER_REG_FULL_STATUS == RECEIVE_COMPLETE_SSPBUF_IS_FULL))
        {
            *data_read = SPI_BUFFER_REG;
            ret = E_OK;
        }
        else{ret = E_NOT_OK;}
    }
    return ret;
}

static Std_ReturnType SPI_Master_config(const SPI_Master_mode_config *Master){
    Std_ReturnType ret = E_NOT_OK;
    if(Master==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(Master->SPI_Clk_Polarity == SPI_Clock_idel_state_high)
        {
            SPI_CLOCK_IDLE_STATE_HIGH();
             ret = E_OK;
        }
        else if(Master->SPI_Clk_Polarity == SPI_Clock_idel_state_low)
        {
            SPI_CLOCK_IDLE_STATE_LOW();
             ret = E_OK;
        }
        else{ret = E_NOT_OK;}
        
        if(Master->SPI_Clk_Phase == SPI_Clock_phase_Active_to_idel)
        {
            SPI_TRANSMISSION_FROM_ACTIVE_TO_IDLE();
             ret = E_OK;
        }
        else if(Master->SPI_Clk_Phase == SPI_Clock_phase_idel_to_Active)
        {
            SPI_TRANSMISSION_FROM_IDLE_TO_ACTIVE();
             ret = E_OK;
        }
        else{ret = E_NOT_OK;}
        if(Master->SPI_input_data_sample == SPI_sample_at_end)
        {
            SPI_INPUT_DATA_SAMPLED_AT_END();
             ret = E_OK;
        }
        else if(Master->SPI_input_data_sample == SPI_sample_at_middle)
        {
            SPI_INPUT_DATA_SAMPLED_AT_MIDDLE();
             ret = E_OK;
        }
        else{ret = E_NOT_OK;}
        
        ret = GPIO_PIN_directoin_intialization(&(Master->GPIO_SS_pin));
    }
    return ret;
}

static Std_ReturnType SPI_Slave_config(const SPI_Slave_mode_config *Slave){
    Std_ReturnType ret = E_NOT_OK;
    if(Slave==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(Slave->SPI_Clk_Polarity == SPI_Clock_idel_state_high)
        {
            SPI_CLOCK_IDLE_STATE_HIGH();
             ret = E_OK;
        }
        else if(Slave->SPI_Clk_Polarity == SPI_Clock_idel_state_low)
        {
            SPI_CLOCK_IDLE_STATE_LOW();
             ret = E_OK;
        }
        else{ret = E_NOT_OK;}
        
        if(Slave->SPI_Clk_Phase == SPI_Clock_phase_Active_to_idel)
        {
            SPI_TRANSMISSION_FROM_ACTIVE_TO_IDLE();
             ret = E_OK;
        }
        else if(Slave->SPI_Clk_Phase == SPI_Clock_phase_idel_to_Active)
        {
            SPI_TRANSMISSION_FROM_IDLE_TO_ACTIVE();
             ret = E_OK;
        }
        else{ret = E_NOT_OK;}
        
    }
    return ret;
}

void ISR_SPI (void){
    
    if(SPI_INTERRUPT_HANDLER != NULL)
    {
        SPI_INTERRUPT_HANDLER();
    }
    SPI_INTERRUPT_CLEAR_FALG();
    GPIO_PIN_write_logic(&SS_pin , GPIO_PIN_HIGH);
    
}