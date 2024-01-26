/* 
 * File:   ecu_char_lcd.c
 * Author: YaseenEzzat
 *
 * Created on October 30, 2023, 2:26 AM
 */

#include "ecu_char_lcd.h"
static Std_ReturnType _8_bit_to_4_bit_converter (const lcd_4_bit_config_t *lcd_4_bit , uint8 inst );


/**
 * 
 * @param lcd_8_bit
 * @return 
 */
Std_ReturnType ECU_LCD_8_bit_intialization(const lcd_8_bit_config_t *lcd_8_bit ){
    Std_ReturnType ret = E_NOT_OK;
    uint8 counter = 0;
    if(NULL==lcd_8_bit)
    {
        ret = E_NOT_OK;
    }
    else
    {
        for (counter = 0 ; counter<8 ; counter++)
        {
            GPIO_PIN_directoin_intialization (&(lcd_8_bit->DB_pins[counter]));
        }
        GPIO_PIN_directoin_intialization (&(lcd_8_bit->EN_pin));
        GPIO_PIN_directoin_intialization (&(lcd_8_bit->RS_pin));
        __delay_ms(15);
        ECU_LCD_8_bit_send_instruction(lcd_8_bit , 0x30);
        __delay_ms(5);
        ECU_LCD_8_bit_send_instruction(lcd_8_bit , 0x30);
        __delay_us(100);
        ECU_LCD_8_bit_send_instruction(lcd_8_bit , 0x30);
        ECU_LCD_8_bit_send_instruction(lcd_8_bit , LCD_INSTRUCTION_CLEAR_DISPLAY);
        ECU_LCD_8_bit_send_instruction(lcd_8_bit , LCD_INSTRUCTION_RETURN_HOME);
        ECU_LCD_8_bit_send_instruction(lcd_8_bit , LCD_INSTRUCTION_INCREMEMNT_CURSOR_SHIFT_OFF);
        ECU_LCD_8_bit_send_instruction(lcd_8_bit , LCD_INSTRUCTION_DISPLAY_ON_CURSOR_OFF_BLANKING_OFF);
        ECU_LCD_8_bit_send_instruction(lcd_8_bit , LCD_INSTRUCTION_INITIALIZTION_8BIT_2_LINS_5X8);
        ECU_LCD_8_bit_send_instruction(lcd_8_bit , 0x80);

    }
    
    return ret;
}

/**
 * 
 * @param lcd_8_bit
 * @param inst
 * @return 
 */
Std_ReturnType ECU_LCD_8_bit_send_instruction(const lcd_8_bit_config_t *lcd_8_bit , uint8 inst){
    Std_ReturnType ret = E_NOT_OK;
    uint8 counter = 0;
    if(NULL==lcd_8_bit)
    {
        ret = E_NOT_OK;
    }
    else
    {
        // R/W pin is always enabled as it connected to the ground
        
        //write logic 0 on the RS pin to send instruction
        ret = GPIO_PIN_write_logic(&(lcd_8_bit->RS_pin),GPIO_PIN_LOW);
        //writing the instruction throw the DB 8 pins
        for (counter = 0 ; counter<8 ; counter++)
        {
            ret = GPIO_PIN_write_logic(&(lcd_8_bit->DB_pins[counter]),(inst>>counter)&0x01);
        }
        //Enabling the EN pin by write logic 1 on it then write logic 0 after 5us
        ret = GPIO_PIN_write_logic(&(lcd_8_bit->EN_pin),GPIO_PIN_HIGH);
        __delay_us(5);
        ret = GPIO_PIN_write_logic(&(lcd_8_bit->EN_pin),GPIO_PIN_LOW);
    }
    
    return ret;
}

/**
 * 
 * @param lcd_8_bit
 * @param data
 * @return 
 */
Std_ReturnType ECU_LCD_8_bit_write_char_data(const lcd_8_bit_config_t *lcd_8_bit , uint8 data){
    Std_ReturnType ret = E_NOT_OK;
    uint8 counter = 0;
    if(NULL==lcd_8_bit)
    {
        ret = E_NOT_OK;
    }
    else
    {
        // R/W pin is always enabled as it connected to the ground
        
        //write logic 1 on the RS pin to send data
        ret = GPIO_PIN_write_logic(&(lcd_8_bit->RS_pin),GPIO_PIN_HIGH);
        //writing the data throw the DB 8 pins
        for (counter = 0 ; counter<8 ; counter++)
        {
            ret = GPIO_PIN_write_logic(&(lcd_8_bit->DB_pins[counter]),(data>>counter)&0x01);
        }
        //Enabling the EN pin by write logic 1 on it
        ret = GPIO_PIN_write_logic(&(lcd_8_bit->EN_pin),GPIO_PIN_HIGH);
        __delay_us(5);
        ret = GPIO_PIN_write_logic(&(lcd_8_bit->EN_pin),GPIO_PIN_LOW);
         
    }
    
    return ret;
}

/**
 * 
 * @param lcd_8_bit
 * @param data
 * @return 
 */
Std_ReturnType ECU_LCD_8_bit_write_string_data(const lcd_8_bit_config_t *lcd_8_bit , uint8 *data){
    Std_ReturnType ret = E_NOT_OK;
    uint8 counter1=0;
    uint8 counter2=0;
    if(NULL==lcd_8_bit)
    {
        ret = E_NOT_OK;
    }
    else
    {
       // R/W pin is always enabled as it connected to the ground
        
        //write logic 1 on the RS pin to send data
        ret = GPIO_PIN_write_logic(&(lcd_8_bit->RS_pin),GPIO_PIN_HIGH);
        //writing the data throw the DB 8 pins
        for(counter1 = 0 ; counter1<strlen(data); counter1++)
        {
            for (counter2 = 0 ; counter2<8 ; counter2++)
            {
                ret = GPIO_PIN_write_logic(&(lcd_8_bit->DB_pins[counter2]),(*(data+counter1)>>counter2)&0x01);
            }
            //Enabling the EN pin by write logic 1 on it
            ret = GPIO_PIN_write_logic(&(lcd_8_bit->EN_pin),GPIO_PIN_HIGH);
             __delay_us(5);
            ret = GPIO_PIN_write_logic(&(lcd_8_bit->EN_pin),GPIO_PIN_LOW);
        }
        
         
    }
    
    return ret;
}

/**
 * 
 * @param lcd_8_bit
 * @param data
 * @param row
 * @param column
 * @return 
 */
Std_ReturnType ECU_LCD_8_bit_write_char_data_in_pos(const lcd_8_bit_config_t *lcd_8_bit ,
                                                    uint8 data ,uint8 row ,uint8 column ){
    Std_ReturnType ret = E_NOT_OK;
    uint8 temp_column = column-1;
    uint8 counter = 0;
    if(NULL==lcd_8_bit)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
        // R/W pin is always enabled as it connected to the ground
        
        
        if (row == ROW1)
        {
            ret = ECU_LCD_8_bit_send_instruction(lcd_8_bit ,(0x80+temp_column) );
        }
        else if (row == ROW2)
        {
            ret = ECU_LCD_8_bit_send_instruction(lcd_8_bit ,(0xc0+temp_column) );
        }
        else if (row == ROW3)
        {
            ret = ECU_LCD_8_bit_send_instruction(lcd_8_bit ,(0x94+temp_column) );
        }
        else if (row == ROW4)
        {
            ret = ECU_LCD_8_bit_send_instruction(lcd_8_bit ,(0xd4+temp_column) );
        }
        else {ret = E_NOT_OK;}
        
        //write logic 1 on the RS pin to send data
        ret = GPIO_PIN_write_logic(&(lcd_8_bit->RS_pin),GPIO_PIN_HIGH);
        //writing the data throw the DB 8 pins
        for (counter = 0 ; counter<8 ; counter++)
        {
            ret = GPIO_PIN_write_logic(&(lcd_8_bit->DB_pins[counter]),(data>>counter)&0x01);
        }
        //Enabling the EN pin by write logic 1 on it
        ret = GPIO_PIN_write_logic(&(lcd_8_bit->EN_pin),GPIO_PIN_HIGH);
        __delay_us(5);
        ret = GPIO_PIN_write_logic(&(lcd_8_bit->EN_pin),GPIO_PIN_LOW);
         
    }
    
    return ret;
}

/**
 * 
 * @param lcd_8_bit
 * @param data
 * @param row
 * @param column
 * @return 
 */
Std_ReturnType ECU_LCD_8_bit_write_string_data_in_pos(const lcd_8_bit_config_t *lcd_8_bit ,
                                                      uint8 *data ,uint8 row ,uint8 column ){
    Std_ReturnType ret = E_NOT_OK;
    uint8 temp_column = column-1;
    uint8 counter1=0;
    uint8 counter2=0;
    if(NULL==lcd_8_bit)
    {
        ret = E_NOT_OK;
    }
    else
    {
        // R/W pin is always enabled as it connected to the ground
        
        //write logic 1 on the RS pin to send data
        if (row == ROW1)
        {
            ret = ECU_LCD_8_bit_send_instruction(lcd_8_bit ,(0x80+temp_column) );
        }
        else if (row == ROW2)
        {
            ret = ECU_LCD_8_bit_send_instruction(lcd_8_bit ,(0xc0+temp_column) );
        }
        else if (row == ROW3)
        {
            ret = ECU_LCD_8_bit_send_instruction(lcd_8_bit ,(0x94+temp_column) );
        }
        else if (row == ROW4)
        {
            ret = ECU_LCD_8_bit_send_instruction(lcd_8_bit ,(0xd4+temp_column) );
        }
        else {ret = E_NOT_OK;}
        //write logic 1 on the RS pin to send data
        ret = GPIO_PIN_write_logic(&(lcd_8_bit->RS_pin),GPIO_PIN_HIGH);
        //writing the data throw the DB 8 pins
        for(counter1 = 0 ; counter1<strlen(data); counter1++)
        {
            for (counter2 = 0 ; counter2<8 ; counter2++)
            {
                ret = GPIO_PIN_write_logic(&(lcd_8_bit->DB_pins[counter2]),(*(data+counter1)>>counter2)&0x01);
            }
            //Enabling the EN pin by write logic 1 on it
            ret = GPIO_PIN_write_logic(&(lcd_8_bit->EN_pin),GPIO_PIN_HIGH);
             __delay_us(5);
            ret = GPIO_PIN_write_logic(&(lcd_8_bit->EN_pin),GPIO_PIN_LOW);
        }
    }
    
    return ret;
}


/**
 * 
 * @param lcd_8_bit
 * @param cust_char
 * @param CGRAM_POS
 * @param row
 * @param column
 * @return 
 */
Std_ReturnType ECU_LCD_8_bit_write_custom_char(const lcd_8_bit_config_t *lcd_8_bit ,const uint8 cust_char[],
                                               uint8 CGRAM_POS ,uint8 row ,uint8 column ){
    Std_ReturnType ret = E_NOT_OK;
    uint8 counter = 0;
    if(NULL==lcd_8_bit)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ECU_LCD_8_bit_send_instruction(lcd_8_bit ,CGRAM_POS );
        for(counter = 0 ; counter<8 ;counter++){
            ECU_LCD_8_bit_write_char_data(lcd_8_bit,cust_char[counter]);
        }
        ECU_LCD_8_bit_write_char_data_in_pos(lcd_8_bit ,(CGRAM_POS - LCD_GCRAM_FIRST_ADDRESS ),row,column );
    }
    return ret;
}


/**
 * 
 * @param lcd_4_bit
 * @return 
 */
Std_ReturnType ECU_LCD_4_bit_intialization(const lcd_4_bit_config_t *lcd_4_bit ){
    Std_ReturnType ret = E_NOT_OK;
    uint8 counter = 0;
    if(NULL==lcd_4_bit)
    {
        ret = E_NOT_OK;
    }
    else
    {
        for (counter = 0 ; counter<4 ; counter++)
        {
            GPIO_PIN_directoin_intialization (&(lcd_4_bit->DB_pins[counter]));
        }
        GPIO_PIN_directoin_intialization (&(lcd_4_bit->EN_pin));
        GPIO_PIN_directoin_intialization (&(lcd_4_bit->RS_pin));
        __delay_ms(20);
        ECU_LCD_4_bit_send_instruction(lcd_4_bit , 0x30);
        __delay_ms(5);
        ECU_LCD_4_bit_send_instruction(lcd_4_bit , 0x30);
        __delay_us(150);
        ECU_LCD_4_bit_send_instruction(lcd_4_bit , 0x30);
        ECU_LCD_4_bit_send_instruction(lcd_4_bit , LCD_INSTRUCTION_CLEAR_DISPLAY);
        ECU_LCD_4_bit_send_instruction(lcd_4_bit , LCD_INSTRUCTION_RETURN_HOME);
        ECU_LCD_4_bit_send_instruction(lcd_4_bit , LCD_INSTRUCTION_INCREMEMNT_CURSOR_SHIFT_OFF);
        ECU_LCD_4_bit_send_instruction(lcd_4_bit , LCD_INSTRUCTION_DISPLAY_ON_CURSOR_OFF_BLANKING_OFF);
        ECU_LCD_4_bit_send_instruction(lcd_4_bit , LCD_INSTRUCTION_INITIALIZTION_4BIT_2_LINS_5X8);
        ECU_LCD_4_bit_send_instruction(lcd_4_bit , 0x80);
       
    }
    
    return ret;
}

/**
 * 
 * @param lcd_4_bit
 * @param inst
 * @return 
 */
Std_ReturnType ECU_LCD_4_bit_send_instruction(const lcd_4_bit_config_t *lcd_4_bit , uint8 inst){
    Std_ReturnType ret = E_NOT_OK;
    uint8 counter = 0;
    if(NULL==lcd_4_bit)
    {
        ret = E_NOT_OK;
    }
    else
    {
         // R/W pin is always enabled as it connected to the ground
        
        //write logic 0 on the RS pin to send instruction
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->RS_pin),GPIO_PIN_LOW);
        //writing the instruction throw the DB 4 pins
        for (counter = 0 ; counter<4 ; counter++)
        {
            ret = GPIO_PIN_write_logic(&(lcd_4_bit->DB_pins[counter]),((inst>>(4+counter))&0x01));
        }
        //Enabling the EN pin by write logic 1 on it then write logic 0 after 5us
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_HIGH);
        __delay_us(5);
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_LOW);
        
        
        for (counter = 0 ; counter<4 ; counter++)
        {
            ret = GPIO_PIN_write_logic(&(lcd_4_bit->DB_pins[counter]),(inst>>counter)&0x01);
        }
        //Enabling the EN pin by write logic 1 on it then write logic 0 after 5us
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_HIGH);
        __delay_us(5);
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_LOW);
        

    }
    
    return ret;
}

/**
 * 
 * @param lcd_4_bit
 * @param data
 * @return 
 */
Std_ReturnType ECU_LCD_4_bit_write_char_data(const lcd_4_bit_config_t *lcd_4_bit , uint8 data){
    Std_ReturnType ret = E_NOT_OK;
    uint8 counter = 0;
    if(NULL==lcd_4_bit)
    {
        ret = E_NOT_OK;
    }
    else
    {
        // R/W pin is always enabled as it connected to the ground
        
        //write logic 1 on the RS pin to send data
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->RS_pin),GPIO_PIN_HIGH);
        //writing the the high nibble instruction throw the DB 4 pins
        for (counter = 0 ; counter<4 ; counter++)
        {
            ret = GPIO_PIN_write_logic(&(lcd_4_bit->DB_pins[counter]),((data>>(4+counter))&0x01));
        }
        //Enabling the EN pin by write logic 1 on it then write logic 0 after 5us
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_HIGH);
        __delay_us(5);
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_LOW);
        
        //writing the the low nibble instruction throw the DB 4 pins
        for (counter = 0 ; counter<4 ; counter++)
        {
            ret = GPIO_PIN_write_logic(&(lcd_4_bit->DB_pins[counter]),(data>>counter)&0x01);
        }
        //Enabling the EN pin by write logic 1 on it then write logic 0 after 5us
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_HIGH);
        __delay_us(5);
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_LOW);
       
         
    }
    
    return ret;
}

/**
 * 
 * @param lcd_4_bit
 * @param data
 * @return 
 */
Std_ReturnType ECU_LCD_4_bit_write_string_data(const lcd_4_bit_config_t *lcd_4_bit , uint8 *data){
    Std_ReturnType ret = E_NOT_OK;
    uint8 counter = 0 ;
    uint8 counter1 = 0 ; 
    uint8 counter2 = 0;
    if(NULL==lcd_4_bit)
    {
        ret = E_NOT_OK;
    }
    else
    {
        // R/W pin is always enabled as it connected to the ground
        
        //write logic 1 on the RS pin to send data
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->RS_pin),GPIO_PIN_HIGH);
        //writing the the high nibble instruction throw the DB 4 pins
        for(counter1 = 0 ; counter1<strlen(data); counter1++)
        {
            for (counter2 = 0 ; counter2<4 ; counter2++)
            {
                ret = GPIO_PIN_write_logic(&(lcd_4_bit->DB_pins[counter2]),(*(data+counter1)>>(4+counter2)&0x01));
            }
            //Enabling the EN pin by write logic 1 on it then write logic 0 after 5us
            ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_HIGH);
            __delay_us(5);
            ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_LOW);
            
            for (counter2 = 0 ; counter2<4 ; counter2++)
            {
                ret = GPIO_PIN_write_logic(&(lcd_4_bit->DB_pins[counter2]),(*(data+counter1)>>(counter2)&0x01));
            }
            //Enabling the EN pin by write logic 1 on it then write logic 0 after 5us
            ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_HIGH);
            __delay_us(5);
            ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_LOW);
        }
        
        
    }
    return ret;
}

/**
 * 
 * @param lcd_4_bit
 * @param data
 * @param row
 * @param column
 * @return 
 */
Std_ReturnType ECU_LCD_4_bit_write_char_data_in_pos(const lcd_4_bit_config_t *lcd_4_bit ,
                                                    uint8 data ,uint8 row ,uint8 column ){
    Std_ReturnType ret = E_NOT_OK;
    uint8 counter = 0 ;
    uint8 temp_column = column-1;
    if(NULL==lcd_4_bit)
    {
        ret = E_NOT_OK;
    }
    else
    {
        // R/W pin is always enabled as it connected to the ground
        if (row == ROW1)
        {
            ret = ECU_LCD_4_bit_send_instruction(lcd_4_bit ,(0x80+temp_column) );
        }
        else if (row == ROW2)
        {
            ret = ECU_LCD_4_bit_send_instruction(lcd_4_bit ,(0xc0+temp_column) );
        }
        else if (row == ROW3)
        {
            ret = ECU_LCD_4_bit_send_instruction(lcd_4_bit ,(0x94+temp_column) );
        }
        else if (row == ROW4)
        {
            ret = ECU_LCD_4_bit_send_instruction(lcd_4_bit ,(0xd4+temp_column) );
        }
        else {ret = E_NOT_OK;}
        //write logic 1 on the RS pin to send data
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->RS_pin),GPIO_PIN_HIGH);
        //writing the the high nibble instruction throw the DB 4 pins
        for (counter = 0 ; counter<4 ; counter++)
        {
            ret = GPIO_PIN_write_logic(&(lcd_4_bit->DB_pins[counter]),((data>>(4+counter))&0x01));
        }
        //Enabling the EN pin by write logic 1 on it then write logic 0 after 5us
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_HIGH);
        __delay_us(5);
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_LOW);
        
        //writing the the low nibble instruction throw the DB 4 pins
        for (counter = 0 ; counter<4 ; counter++)
        {
            ret = GPIO_PIN_write_logic(&(lcd_4_bit->DB_pins[counter]),(data>>counter)&0x01);
        }
        //Enabling the EN pin by write logic 1 on it then write logic 0 after 5us
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_HIGH);
        __delay_us(5);
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_LOW);
         
    }
    
    return ret;
}


/**
 * 
 * @param lcd_4_bit
 * @param data
 * @param row
 * @param column
 * @return 
 */
Std_ReturnType ECU_LCD_4_bit_write_string_data_in_pos(const lcd_4_bit_config_t *lcd_4_bit ,
                                                      uint8 *data ,uint8 row ,uint8 column ){
    Std_ReturnType ret = E_NOT_OK;
    uint8 counter = 0 ;
    uint8 counter1 = 0 ;
    uint8 counter2 = 0 ;
    uint8 temp_column = column-1;
    if(NULL==lcd_4_bit)
    {
        ret = E_NOT_OK;
    }
    else
    {
        // R/W pin is always enabled as it connected to the ground
        if (row == ROW1)
        {
            ret = ECU_LCD_4_bit_send_instruction(lcd_4_bit ,(0x80+temp_column) );
        }
        else if (row == ROW2)
        {
            ret = ECU_LCD_4_bit_send_instruction(lcd_4_bit ,(0xc0+temp_column) );
        }
        else if (row == ROW3)
        {
            ret = ECU_LCD_4_bit_send_instruction(lcd_4_bit ,(0x94+temp_column) );
        }
        else if (row == ROW4)
        {
            ret = ECU_LCD_4_bit_send_instruction(lcd_4_bit ,(0xd4+temp_column) );
        }
        else {ret = E_NOT_OK;}
        
        //write logic 1 on the RS pin to send data
        ret = GPIO_PIN_write_logic(&(lcd_4_bit->RS_pin),GPIO_PIN_HIGH);
        //writing the the high nibble instruction throw the DB 4 pins
        for(counter1 = 0 ; counter1<strlen(data); counter1++)
        {
            for (counter2 = 0 ; counter2<4 ; counter2++)
            {
                ret = GPIO_PIN_write_logic(&(lcd_4_bit->DB_pins[counter2]),(*(data+counter1)>>(4+counter2)&0x01));
            }
            //Enabling the EN pin by write logic 1 on it then write logic 0 after 5us
            ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_HIGH);
            __delay_us(5);
            ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_LOW);
            
            for (counter2 = 0 ; counter2<4 ; counter2++)
            {
                ret = GPIO_PIN_write_logic(&(lcd_4_bit->DB_pins[counter2]),(*(data+counter1)>>(counter2)&0x01));
            }
            //Enabling the EN pin by write logic 1 on it then write logic 0 after 5us
            ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_HIGH);
            __delay_us(5);
            ret = GPIO_PIN_write_logic(&(lcd_4_bit->EN_pin),GPIO_PIN_LOW);
        }
         
    }
    
    return ret;
}


/**
 * 
 * @param lcd_4_bit
 * @param cust_chr
 * @param CGRAM_POS
 * @param row
 * @param column
 * @return 
 */
Std_ReturnType ECU_LCD_4_bit_write_custom_char(const lcd_4_bit_config_t *lcd_4_bit ,const uint8 cust_char[],
                                               uint8 CGRAM_POS ,uint8 row ,uint8 column ){
    Std_ReturnType ret = E_NOT_OK;
    uint8 counter = 0;
    if(NULL==lcd_4_bit)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ECU_LCD_4_bit_send_instruction(lcd_4_bit ,CGRAM_POS );
        for(counter = 0 ; counter<8 ;counter++){
            ECU_LCD_4_bit_write_char_data(lcd_4_bit,cust_char[counter]);
        }
        ECU_LCD_4_bit_write_char_data_in_pos(lcd_4_bit ,(CGRAM_POS - LCD_GCRAM_FIRST_ADDRESS ),row,column );
    }
    return ret;
    
}

static Std_ReturnType _8_bit_to_4_bit_converter (const lcd_4_bit_config_t *lcd_4_bit , uint8 inst ){
     Std_ReturnType ret = E_NOT_OK;
     
    ret = GPIO_PIN_write_logic(&(lcd_4_bit->DB_pins[0]),(inst>>0) &0x01);
    ret = GPIO_PIN_write_logic(&(lcd_4_bit->DB_pins[1]),(inst>>1) &0x01);
    ret = GPIO_PIN_write_logic(&(lcd_4_bit->DB_pins[2]),(inst>>2) &0x01);
    ret = GPIO_PIN_write_logic(&(lcd_4_bit->DB_pins[3]),(inst>>3) &0x01);
    
    return ret;
}


/**
 * 
 * @param data
 * @param str
 * @return 
 */
Std_ReturnType convert_uint8_byte_to_string  (uint8  data  , uint8 *str){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==str)
    {
        ret = E_NOT_OK;
    }
    else
    {
        memset(str ,'\0',4 );
        sprintf(str , "%i" , data );
        memset(str+(strlen(str)) ,' ',(3-(strlen(str))) );
    }
    return ret;
}

/**
 * 
 * @param data
 * @param str
 * @return 
 */
Std_ReturnType convert_uint16_byte_to_string (uint16 data , uint8 *str){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==str)
    {
        ret = E_NOT_OK;
    }
    else
    {
        memset(str ,'\0',6 );
        sprintf(str , "%i" , data );
        memset(str+(strlen(str)) ,' ',(5-(strlen(str))) );
    }
    return ret;
}

/**
 * 
 * @param data
 * @param str
 * @return 
 */
Std_ReturnType convert_uint32_byte_to_string (uint32 data , uint8 *str){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==str)
    {
        ret = E_NOT_OK;
    }
    else
    {
        memset(str ,'\0',11 );
        sprintf(str , "%i" , data );
        memset(str+(strlen(str)) ,' ',(10-(strlen(str))) );
    }
    return ret;
}