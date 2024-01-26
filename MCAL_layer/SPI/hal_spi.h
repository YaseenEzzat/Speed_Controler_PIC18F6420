/* 
 * File:   hal_spi.h
 * Author: YaseenEzzat
 *
 * Created on November 15, 2023, 6:51 AM
 */

#ifndef HAL_SPI_H
#define	HAL_SPI_H

/* Section : Includes*/
#include "hal_spi_config.h"
#include "../../../../../Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "../GPIO/hal_GPIO.h"
#include "../INTERRUPT/mcal_internal_interrupt.h"
/* Section : Macro Declaration*/

//SPI SSPBUF Buffer register (Trans/receive register).
#define SPI_BUFFER_REG                          SSPBUF

//SPI SSPBUF Buffer register state.
#define SPI_BUFFER_REG_FULL_STATUS              SSPSTATbits.BF
#define RECEIVE_COMPLETE_SSPBUF_IS_FULL         1
#define RECEIVE_NOT_COMPLETE_SSPBUF_IS_EMPTY    0

//SPI slave Receive Overflow Indicator
#define SPI_BUFFER_REG_OVERFLOW_STATUS          SSPCON1bits.SSPOV
#define OVERFLOW                                1
#define NO_OVERFLOW                             0  

//SPI Write Collision Detect
#define SPI_BUFFER_REG_COLLISION_STATUS          SSPCON1bits.WCOL
#define COLLISION                                1
#define NO_COLLISION                             0  

/* Section : Macro Function Declaration*/

//SPI Synchronous Serial Port Enable / Desable
#define SPI_SERIAL_PORT_ENABLE()                          (SSPCON1bits.SSPEN = 1)
#define SPI_SERIAL_PORT_DESABLE()                         (SSPCON1bits.SSPEN = 0)

//SPI mode select Master / Salve / OSC
#define SPI_MODE_SELSCT(MODE)                           (SSPCON1bits.SSPM = MODE)

// Clock Polarity Select (Idle state)
#define SPI_CLOCK_IDLE_STATE_HIGH()                       (SSPCON1bits.CKP = 1)
#define SPI_CLOCK_IDLE_STATE_LOW()                        (SSPCON1bits.CKP = 0)

// SPI Transmission phase Clock Select.
#define SPI_TRANSMISSION_FROM_ACTIVE_TO_IDLE()          (SSPSTATbits.CKE = 1)
#define SPI_TRANSMISSION_FROM_IDLE_TO_ACTIVE()          (SSPSTATbits.CKE = 0)

// Input data Sample.
#define SPI_INPUT_DATA_SAMPLED_AT_END()                 (SSPSTATbits.SMP = 1)
#define SPI_INPUT_DATA_SAMPLED_AT_MIDDLE()              (SSPSTATbits.SMP = 0)



//Clear SPI slave mode Receive Overflow Indicator
#define SPI_BUFFER_REG_CLEAR_OVERFLOW()                 (SSPCON1bits.SSPOV = 0)

//Clear SPI Write Collision Detector
#define SPI_BUFFER_REG_CLEAR_COLLISION()                (SSPCON1bits.WCOL = 0)

/* Section : Data Type Declaration*/

typedef enum {
    SPI_Master_mode_FOSC_4 = 0,            //0000 = SPI Master mode, clock = FOSC/4
    SPI_Master_mode_FOSC_16,               //0001 = SPI Master mode, clock = FOSC/16
    SPI_Master_mode_FOSC_64,               //0010 = SPI Master mode, clock = FOSC/64
    SPI_Master_mode_external_clk_2         //0011 = SPI Master mode, clock = TMR2 output/2 
        
}SPI_Master_modes_select_t;
typedef enum {
    SPI_Slave_mode_SS_pin_enabled = 4,         //0100 = SPI Slave mode, clock = SCK pin, SS pin control enabled
    SPI_Slave_mode_SS_pin_disabled = 5         //0101 = SPI Slave mode, clock = SCK pin, SS pin control disabled, SS can be used as I/O pin
        
}SPI_Slave_modes_select_t;

typedef enum {
    SPI_Clock_idel_state_high,
    SPI_Clock_idel_state_low
}SPI_Clk_Polarity_Select_t;

typedef enum {
    SPI_Clock_phase_idel_to_Active,
    SPI_Clock_phase_Active_to_idel
}SPI_Clk_Phase_Select_t;

typedef enum {
    SPI_sample_at_end,
    SPI_sample_at_middle
}SPI_input_data_sample_mode_t;

typedef struct {
    void(*SPI_Master_Interrupt_handler) (void);
    interrupt_priority_LEVEL priority_LEVEL;
    SPI_Master_modes_select_t SPI_Master_mode;
    SPI_Clk_Polarity_Select_t SPI_Clk_Polarity;
    SPI_Clk_Phase_Select_t SPI_Clk_Phase;
    SPI_input_data_sample_mode_t SPI_input_data_sample;
    pin_config_t GPIO_SS_pin;
}SPI_Master_mode_config;
typedef struct {
    void(*SPI_Slave_Interrupt_handler) (void);
    interrupt_priority_LEVEL priority_LEVEL;
    SPI_Slave_modes_select_t SPI_Slave_mode;
    SPI_Clk_Polarity_Select_t SPI_Clk_Polarity;
    SPI_Clk_Phase_Select_t SPI_Clk_Phase;
}SPI_Slave_mode_config;

/* Section : Function Declaration*/
Std_ReturnType SPI_MASTER_Initialization(const SPI_Master_mode_config *Master);
Std_ReturnType SPI_MASTER_Deinitialization(const SPI_Master_mode_config *Master);
Std_ReturnType SPI_SLAVE_Initialization(const SPI_Slave_mode_config *Slave);
Std_ReturnType SPI_SLAVE_Deinitialization(const SPI_Slave_mode_config *Slave);

Std_ReturnType SPI_Master_Write_8_bit_Data_Blocking(const SPI_Master_mode_config *Master ,uint8 data_write );
Std_ReturnType SPI_Master_Write_8_bit_Data_Interrupt(const SPI_Master_mode_config *Master ,uint8 data_write );
Std_ReturnType SPI_Master_Read_8_bit_Data_Blocking(const SPI_Master_mode_config *Master ,uint8 *data_read);
Std_ReturnType SPI_Master_Read_8_bit_Data_Interrupt(const SPI_Master_mode_config *Master ,uint8 *data_read);

Std_ReturnType SPI_Slave_Write_8_bit_Data_Blocking(uint8 data_write );
Std_ReturnType SPI_Slave_Write_8_bit_Data_Interrupt(uint8 data_write);
Std_ReturnType SPI_Slave_Read_8_bit_Data_Blocking(uint8 *data_read);
Std_ReturnType SPI_Slave_Read_8_bit_Data_Interrupt(uint8 *data_read);




#endif	/* HAL_SPI_H */

