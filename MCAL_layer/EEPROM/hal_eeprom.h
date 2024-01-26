/* 
 * File:   hal_eeprom.h
 * Author: YaseenEzzat
 *
 * Created on November 3, 2023, 4:53 AM
 */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H

/* Section : Includes*/

#include "hal_eeprom_config.h"
#include "../../../../../Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "../INTERRUPT/mcal_interrupt_config.h"
#include "../GPIO/hal_GPIO.h"

/* Section : Macro Declaration*/
#define  EEPROM_WRIET_ERROE_FLAG_BIT             EECON1bits.WRERR
#define  EEPROM_WRIET_BIE_STATUSE                EECON1bits.WR
#define  EEPROM_READ_CONTROL_BIT_STATUSE         EECON1bits.RD

/* Section : Macro Function Declaration*/
#define EEPROM_WRIET_UPPER_BITS_OF_DATA_MEMORY_ADDRESS(ADREES)   (EEADRH=((uint8)((ADREES>>8)&0X03)))
#define EEPROM_WRIEE_LOWERS_BITS_OF_DATA_MEMORY_ADDRESS(ADREES)  (EEADR=((uint8)(ADREES&0XFF)))
#define EEPROM_ACCESS_DATAT_MEMORY()                             (EECON1bits.EEPGD=0)
#define EEPROM_ACCESS_FLASH_PROGRAM_OR_DATAT_EEPROM_MEMORY()     (EECON1bits.CFGS=0)

#define EEPROM_WRIET_DATAT(DTAT)                                 (EEDATA = DTAT)
#define EEPROM_READ_DATAT(DTAT)                                  ( DTAT = EEDATA )

#define EEPROM_WRIET_DATAT_ENABLE()                              (EECON1bits.WREN=1)
#define EEPROM_WRIET_DATAT_DISABLE()                             (EECON1bits.WREN=0)

#define EEPROM_RAED_DATAT_ENABLE()                               (EECON1bits.WREN=1)

#define EEPROM_WRIET_INTIALIZATION()                             (EECON1bits.WR=1)
#define EEPROM_READ_INTIALIZATION()                              (EECON1bits.RD=1)

/* Section : Data Type Declaration*/

//EEPROM only read and write 1 byte
Std_ReturnType EEPROM_write_1byte_data (const uint16 address , const uint8 data);
Std_ReturnType EEPROM_read_1byte_data (const uint16 address , uint8 *data);

/* Section : Function Declaration*/


#endif	/* HAL_EEPROM_H */

