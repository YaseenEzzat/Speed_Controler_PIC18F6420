/* 
 * File:   hal_eeprom.c
 * Author: YaseenEzzat
 *
 * Created on November 3, 2023, 4:53 AM
 */

#include "hal_eeprom.h"

void EEPROM_write_data_required_sequence (void);

/**
 * 
 * @param address
 * @param data
 * @return 
 */
Std_ReturnType EEPROM_write_1byte_data (const uint16 address , const uint8 data){
    Std_ReturnType ret = E_NOT_OK;
    EEPROM_WRIET_UPPER_BITS_OF_DATA_MEMORY_ADDRESS(address);
    EEPROM_WRIEE_LOWERS_BITS_OF_DATA_MEMORY_ADDRESS(address);
    EEPROM_WRIET_DATAT(data);
    EEPROM_ACCESS_DATAT_MEMORY();
    EEPROM_ACCESS_FLASH_PROGRAM_OR_DATAT_EEPROM_MEMORY();
    EEPROM_WRIET_DATAT_ENABLE();
    EEPROM_write_data_required_sequence();
    EEPROM_WRIET_DATAT_DISABLE();   
    if(EEPROM_WRIET_ERROE_FLAG_BIT == 0){
        ret = E_OK;
    }
    else{ret = E_NOT_OK;}       
    return ret;
}



/**
 * 
 * @param address
 * @param data
 * @return 
 */
Std_ReturnType EEPROM_read_1byte_data (const uint16 address , uint8 *data){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==data)
    {
        ret = E_NOT_OK;
    }
    else
    {
        EEPROM_WRIET_UPPER_BITS_OF_DATA_MEMORY_ADDRESS(address);
        EEPROM_WRIEE_LOWERS_BITS_OF_DATA_MEMORY_ADDRESS(address);
        EEPROM_ACCESS_DATAT_MEMORY();
        EEPROM_ACCESS_FLASH_PROGRAM_OR_DATAT_EEPROM_MEMORY();
        if((EECON1bits.EEPGD !=1)&&(EECON1bits.CFGS != 1))
        {
            EEPROM_READ_INTIALIZATION();
            NOP();
            NOP();
            ret = E_OK;
        }
        else{ret = E_NOT_OK;}
        EEPROM_READ_DATAT(*data);
        while(EEPROM_READ_CONTROL_BIT_STATUSE);
        
        if(EEPROM_READ_CONTROL_BIT_STATUSE == 0){
        ret = E_OK;
        }
        else{ret = E_NOT_OK;}       
        return ret;
    }
    
}

void EEPROM_write_data_required_sequence (void){

    uint8 temp_intr_pir_vlue = RCONbits.IPEN;
    uint8 temp_intr_gl_vlue = INTCONbits.GIE;
    
    RCONbits.IPEN = 0;
    INTCONbits.GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    
    EEPROM_WRIET_INTIALIZATION();
    
    while(EEPROM_WRIET_BIE_STATUSE);
    
    RCONbits.IPEN = temp_intr_pir_vlue;
    INTCONbits.GIE = temp_intr_gl_vlue;
}