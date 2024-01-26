/* 
 * File:   Application.c
 * Author: YaseenEzzat
 *
 * Created on October 22, 2023, 10:26 AM
 */
#include"application.h"
void write_time_on_LCD(void);
void write_status_on_LCD(void);
void LCD_home_screen(void);
void Get_order_from_user(void);
void Temp_control(void);
void motor_init(void);
void control_motor_speed(void);
CCP1_config_t PWM_obj;
uint8 motor_speed = 0;





int main(){
    application_intialization();
    ret = EEPROM_read_1byte_data(0x00 ,&motor_speed );
    if (motor_speed == 0xFF)
    {
        ret = EEPROM_write_1byte_data (0x00 , 50);
    }
    motor_init();

    while (1)
    {
        
       LCD_home_screen();
       Get_order_from_user();
       Temp_control();

    }
    return (EXIT_SUCCESS);
}
  
void application_intialization (void){
    ecu_layer_intialization();
    I2C_Initialize();

}
void write_time_on_LCD(void){
    uint8 hours10 =0;
    uint8 hours01 =0;
    uint8 minetus10 =0;
    uint8 minetus01 =0;
    uint8 secondes10 =0;
    uint8 secondes01 =0;
    hours10 = ((I2C_Read1ByteRegister(0xD0,0x02))>>4);
    hours01 = ((I2C_Read1ByteRegister(0xD0,0x02))&0xF);
    minetus10 = ((I2C_Read1ByteRegister(0xD0,0x01))>>4);
    minetus01 = ((I2C_Read1ByteRegister(0xD0,0x01))&0xF);
    secondes10 = ((I2C_Read1ByteRegister(0xD0,0x00))>>4);
    secondes01 = ((I2C_Read1ByteRegister(0xD0,0x00))&0xF);
    ret = ECU_LCD_4_bit_write_char_data_in_pos(&lcd2 ,':',1,15 );
    ret = ECU_LCD_4_bit_write_char_data_in_pos(&lcd2 ,hours10+'0',1,13 );
    ret = ECU_LCD_4_bit_write_char_data_in_pos(&lcd2 ,hours01+'0',1,14 );
    ret = ECU_LCD_4_bit_write_char_data_in_pos(&lcd2 ,(minetus10+'0'),1,16 );
    ret = ECU_LCD_4_bit_write_char_data_in_pos(&lcd2 ,(minetus01+'0'),1,17 );
    ret = ECU_LCD_4_bit_write_char_data_in_pos(&lcd2 ,':',1,18 );
    ret = ECU_LCD_4_bit_write_char_data_in_pos(&lcd2 ,secondes10+'0',1,19 );
    ret = ECU_LCD_4_bit_write_char_data_in_pos(&lcd2 ,secondes01+'0',1,20 );
    ret = ECU_LCD_4_bit_write_string_data_in_pos(&lcd2 , "MOTOR_1" , 1 , 1);
}
void write_status_on_LCD(void){
    uint8 temp = 0;
    uint8 temp_str[3];
    uint8 Speed_str[3];
    
    ret = ECU_LCD_4_bit_write_string_data_in_pos(&lcd2 , "1- Speed:" , 2 , 1);
    ret = ECU_LCD_4_bit_write_string_data_in_pos(&lcd2 , "2- Temp.:" , 3 , 1);
    temp =I2C_Read1ByteRegister(0x92,0x00);
    ret =convert_uint8_byte_to_string(temp ,temp_str );
    ret = ECU_LCD_4_bit_write_string_data_in_pos(&lcd2 , temp_str , 3 , 10);
    ret = ECU_LCD_4_bit_write_char_data_in_pos(&lcd2 ,'C',3, 13 );
    ret = EEPROM_read_1byte_data(0x00 ,&motor_speed );
    ret =convert_uint8_byte_to_string(motor_speed ,Speed_str );
    ret = ECU_LCD_4_bit_write_string_data_in_pos(&lcd2 , Speed_str , 2 , 10);
    ret = ECU_LCD_4_bit_write_char_data_in_pos(&lcd2 ,'%',2,13 );
} 

void LCD_home_screen(void)
{
    write_time_on_LCD();
    write_status_on_LCD();

}
void Get_order_from_user(void)
{
    uint8 keypad_value=0;
    ret = ECU_KEYPAD_read_value(&keypad1 ,&keypad_value );
    if(keypad_value == '2')
    {
        ret = ECU_LCD_4_bit_send_instruction (&lcd2 , LCD_INSTRUCTION_CLEAR_DISPLAY);
        uint8 temp = 0;
        uint8 temp_str[3];
        temp =I2C_Read1ByteRegister(0x92,0x00);
        ret =convert_uint8_byte_to_string(temp ,temp_str );
        write_time_on_LCD();
        ret = ECU_LCD_4_bit_write_string_data_in_pos(&lcd2 , "Temperature is    C" , 3 , 1);
        ret = ECU_LCD_4_bit_write_string_data_in_pos(&lcd2 , temp_str , 3 , 16);
        __delay_ms(2000);
        ret = ECU_LCD_4_bit_send_instruction (&lcd2 , LCD_INSTRUCTION_CLEAR_DISPLAY);
        LCD_home_screen();
    }
    if(keypad_value == '1')
    {
        uint8 keypad_speed_value='0';
        uint8 speed_value=0;
        uint8 counter = 0;
        ret = ECU_LCD_4_bit_send_instruction (&lcd2 , LCD_INSTRUCTION_CLEAR_DISPLAY);
        write_time_on_LCD();
        ret = ECU_LCD_4_bit_write_string_data_in_pos(&lcd2 , "Enter New Speed:" , 3 , 1);
        __delay_ms(200);
        keypad_speed_value='0';
        while(keypad_speed_value!='=')
        {
            
            while(keypad_speed_value=='0')
            {
                ret = ECU_KEYPAD_read_value(&keypad1 ,&keypad_speed_value );
                __delay_ms(200);
            }
            if(counter==0)
            {
                ret = ECU_LCD_4_bit_write_char_data_in_pos(&lcd2 ,keypad_speed_value , 3 , 17+counter);
                speed_value = (keypad_speed_value-'0')*10;
                keypad_speed_value='0';
                counter++;
            }
            else if(counter==1)
            {
                ret = ECU_LCD_4_bit_write_char_data_in_pos(&lcd2 ,keypad_speed_value , 3 , 17+counter);
                speed_value = (keypad_speed_value-'0')+speed_value;
                keypad_speed_value='0';
                counter++;
            }
            
            ret = EEPROM_write_1byte_data (0x00 , speed_value);
           
        }
        
        ret = ECU_LCD_4_bit_send_instruction (&lcd2 , LCD_INSTRUCTION_CLEAR_DISPLAY);
        LCD_home_screen();
    }
    
}
void Temp_control(void){
    uint8 temp = 0;
    temp =I2C_Read1ByteRegister(0x92,0x00);
    if (temp<50)
    {
        ret = ECU_LED_turn_on(&led1);
        ret = ECU_LED_turn_off(&led2);
        ECU_MOTOR_turn_forward(&motor1);
    }
    if (temp>=50)
    {
        ret = ECU_LED_turn_on(&led2);
        ret = ECU_LED_turn_off(&led1);
        ECU_RELAY_turn_STOP(&motor1);
    }
}


void motor_init(void){
    
 
     PWM_obj.CCP1_interrupt_handler = NULL;
     PWM_obj.priority_LEVEL = INTERRUPT_PRIORITY_HIGH;
     PWM_obj.PWM_frequency = 20000;
     PWM_obj.Prescale_vlaue = 1;
     PWM_obj.postscale_vlaue = 1;
     PWM_obj.defualt_PWM_duty_cycle = 50;


TIMER2_config_t TIMER2_obj ={
  .TIMER2_interrupt_handler = NULL,
  .priority_LEVEL = INTERRUPT_PRIORITY_HIGH,
  .TIMER2_postscale_vlaue = TIMER2_postscale_value_1_to_1,
  .TIMER2_prescale_vlaue = TIMER2_Prescale_value_1,
  .TIMER2_counter_reg_value = 0
};

}

void control_motor_speed(void){
   
   CCP1_PWM_mode_set_duty_cycle(&PWM_obj , motor_speed);
   ret = CCP1_PWM_START(&PWM_obj);
    
}