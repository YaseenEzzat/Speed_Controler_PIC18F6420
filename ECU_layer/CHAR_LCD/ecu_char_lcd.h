/* 
 * File:   ecu_char_lcd.h
 * Author: YaseenEzzat
 *
 * Created on October 30, 2023, 2:26 AM
 */

#ifndef ECU_CHAR_LCD_H
#define	ECU_CHAR_LCD_H

/* Section : Includes*/
#include "ecu_char_lcd_config.h"
#include "../../MCAL_layer/GPIO/hal_GPIO.h"

/* Section : Macro Declaration*/
#define LCD_INSTRUCTION_CLEAR_DISPLAY                       0X01

#define LCD_INSTRUCTION_RETURN_HOME                         0X02

#define LCD_INSTRUCTION_INCREMEMNT_CURSOR_SHIFT_OFF         0X06
#define LCD_INSTRUCTION_DECREMEMNT_CURSOR_SHIFT_OFF         0X04
#define LCD_INSTRUCTION_INCREMEMNT_CURSOR_SHIFT_ON          0X07
#define LCD_INSTRUCTION_DECREMEMNT_CURSOR_SHIFT_ON          0X05

#define LCD_INSTRUCTION_DISPLAY_OFF                                  0X08
#define LCD_INSTRUCTION_DISPLAY_ON_CURSOR_OFF_BLANKING_OFF           0X0C
#define LCD_INSTRUCTION_DISPLAY_ON_CURSOR_ON_BLANKING_OFF            0X0E    .
#define LCD_INSTRUCTION_DISPLAY_ON_CURSOR_OFF_BLANKING_ON            0X0D
#define LCD_INSTRUCTION_DISPLAY_ON_CURSOR_ON_BLANKING_ON             0X0F

#define LCD_INSTRUCTION_DISPLAY_SHIFT_CURSOR_SHIFT_RIGHT             0X1C
#define LCD_INSTRUCTION_DISPLAY_SHIFT_CURSOR_SHIFT_LEFT              0X18
#define LCD_INSTRUCTION_CURSOR_SHIFT_RIGHT                           0X14
#define LCD_INSTRUCTION_CURSOR_SHIFT_LEFT                            0X10


#define LCD_INSTRUCTION_INITIALIZTION_4BIT_2_LINS_5X8                0X28
#define LCD_INSTRUCTION_INITIALIZTION_8BIT_2_LINS_5X8                0X38


#define LCD_DDRAM_FIRST_ADDRESS                                      0X80
#define LCD_GCRAM_FIRST_ADDRESS                                      0X40

#define CGRAM_CUST_CHAR_POS_1                                        0x40
#define CGRAM_CUST_CHAR_POS_2                                        0x48
#define CGRAM_CUST_CHAR_POS_3                                        0x50
#define CGRAM_CUST_CHAR_POS_4                                        0x58
#define CGRAM_CUST_CHAR_POS_5                                        0x60
#define CGRAM_CUST_CHAR_POS_6                                        0x68
#define CGRAM_CUST_CHAR_POS_7                                        0x70
#define CGRAM_CUST_CHAR_POS_8                                        0x80

#define ROW1  1
#define ROW2  2
#define ROW3  3
#define ROW4  4


/* Section : Macro Function Declaration*/

/* Section : Data Type Declaration*/
typedef struct {
    pin_config_t RS_pin;
    pin_config_t EN_pin;
    pin_config_t DB_pins[8];
}lcd_8_bit_config_t;

typedef struct {
    pin_config_t RS_pin;
    pin_config_t EN_pin;
    pin_config_t DB_pins[4];
}lcd_4_bit_config_t;

/* Section : Function Declaration*/
Std_ReturnType ECU_LCD_8_bit_intialization(const lcd_8_bit_config_t *lcd_8_bit );
Std_ReturnType ECU_LCD_8_bit_send_instruction(const lcd_8_bit_config_t *lcd_8_bit , uint8 inst);
Std_ReturnType ECU_LCD_8_bit_write_char_data(const lcd_8_bit_config_t *lcd_8_bit , uint8 data);
Std_ReturnType ECU_LCD_8_bit_write_string_data(const lcd_8_bit_config_t *lcd_8_bit , uint8 *data);
Std_ReturnType ECU_LCD_8_bit_write_char_data_in_pos(const lcd_8_bit_config_t *lcd_8_bit ,
                                                    uint8 data ,uint8 row ,uint8 column );
Std_ReturnType ECU_LCD_8_bit_write_string_data_in_pos(const lcd_8_bit_config_t *lcd_8_bit ,
                                                      uint8 *data ,uint8 row ,uint8 column );
Std_ReturnType ECU_LCD_8_bit_write_custom_char(const lcd_8_bit_config_t *lcd_8_bit ,const uint8 cust_char[],
                                               uint8 CGRAM_POS ,uint8 row ,uint8 column );


Std_ReturnType ECU_LCD_4_bit_intialization(const lcd_4_bit_config_t *lcd_4_bit );
Std_ReturnType ECU_LCD_4_bit_send_instruction(const lcd_4_bit_config_t *lcd_4_bit , uint8 inst);
Std_ReturnType ECU_LCD_4_bit_write_char_data(const lcd_4_bit_config_t *lcd_4_bit , uint8 data);
Std_ReturnType ECU_LCD_4_bit_write_string_data(const lcd_4_bit_config_t *lcd_4_bit , uint8 *data);
Std_ReturnType ECU_LCD_4_bit_write_char_data_in_pos(const lcd_4_bit_config_t *lcd_4_bit ,
                                                    uint8 data ,uint8 row ,uint8 column );
Std_ReturnType ECU_LCD_4_bit_write_string_data_in_pos(const lcd_4_bit_config_t *lcd_4_bit ,
                                                      uint8 *data ,uint8 row ,uint8 column );
Std_ReturnType ECU_LCD_4_bit_write_custom_char(const lcd_4_bit_config_t *lcd_4_bit ,const uint8 cust_char[],
                                               uint8 CGRAM_POS ,uint8 row ,uint8 column );


Std_ReturnType convert_uint8_byte_to_string  (uint8  data  , uint8 *str);
Std_ReturnType convert_uint16_byte_to_string (uint16 data , uint8 *str);
Std_ReturnType convert_uint32_byte_to_string (uint32 data , uint8 *str);


#endif	/* ECU_CHAR_LCD_H */

