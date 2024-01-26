/* 
 * File:   hal_GPIO.c
 * Author: YaseenEzzat
 *
 * Created on October 22, 2023, 11:03 AM
 */
#include "hal_GPIO.h"

vuint8_t *TRIS_register  [] = {&TRISA ,&TRISB ,&TRISC ,&TRISD ,&TRISE };
vuint8_t *LAT_register   [] = {&LATA  ,&LATB  ,&LATC  ,&LATD  ,&LATE  };
vuint8_t *PORT_register  [] = {&PORTA ,&PORTB ,&PORTC ,&PORTD ,&PORTE };

/**
 * 
 * @param pin_config
 * @return 
 */
#if GPIO_INTRFACE_STATUS==ENABLE
Std_ReturnType GPIO_PIN_directoin_intialization (const pin_config_t *pin_config){
    Std_ReturnType ret=E_OK;
    if(NULL==pin_config || (pin_config->PIN) > (PIN_MAX_SIZE-1))
    {
        ret=E_NOT_OK;
    }
    else
    { 
        if(pin_config->DIRECTOION == GPIO_PIN_OUTPUT)
        {
          CLEAR_BIT(*TRIS_register[pin_config->PORT],pin_config->PIN);
        }
        else if(pin_config->DIRECTOION == GPIO_PIN_INPUT)
        {
           SET_BIT(*TRIS_register[pin_config->PORT],pin_config->PIN);
        }
        else
        {
            ret=E_NOT_OK;
        }
        
    }
    
        return ret;
}
#endif

/**
 * 
 * @param pin_config
 * @param pin_directoin
 * @return 
 */
#if GPIO_INTRFACE_STATUS==ENABLE
Std_ReturnType GPIO_PIN_get_directoin_status (const pin_config_t *pin_config ,pin_directoin_t *pin_directoin ){
    Std_ReturnType ret=E_OK;
    if((NULL==pin_config) || (NULL==pin_directoin) || (pin_config->PIN) > (PIN_MAX_SIZE-1))
    {
        ret=E_NOT_OK;
    }
    else
    {
        *pin_directoin= READ_BIT (*TRIS_register[pin_config->PORT],pin_config->PIN) ;
        
    }
    
        return ret;
}
#endif

/**
 * 
 * @param pin_config
 * @param pin_logic
 * @return 
 */
#if GPIO_INTRFACE_STATUS==ENABLE
Std_ReturnType GPIO_PIN_write_logic (const pin_config_t *pin_config ,pin_logic_t pin_logic ){
    Std_ReturnType ret=E_OK;
    if(NULL==pin_config|| (pin_config->PIN) > (PIN_MAX_SIZE-1))
    {
        ret=E_NOT_OK;
    }
    else
    {
        if(pin_logic == GPIO_PIN_HIGH)
        {
            SET_BIT(*LAT_register[pin_config->PORT],pin_config->PIN);
        }
        else if(pin_logic == GPIO_PIN_LOW)
        {
            CLEAR_BIT(*LAT_register[pin_config->PORT],pin_config->PIN);
        }else
        {
            ret=E_NOT_OK;
        }
     
    }
    
        return ret;
}
#endif
/**
 * 
 * @param pin_config
 * @param pin_logic
 * @return 
 */
#if GPIO_INTRFACE_STATUS==ENABLE
Std_ReturnType GPIO_PIN_read_logic (const pin_config_t *pin_config ,pin_logic_t *pin_logic ){
    Std_ReturnType ret=E_OK;
    if((NULL==pin_config) || (NULL==pin_logic)|| (pin_config->PIN) > (PIN_MAX_SIZE-1))
    {
        ret=E_NOT_OK;
    }
    else
    {
        *pin_logic= READ_BIT (*PORT_register[pin_config->PORT],pin_config->PIN) ;
        
    }
    
        return ret;
}
#endif

/**
 * 
 * @param pin_config
 * @return 
 */
#if GPIO_INTRFACE_STATUS==ENABLE
Std_ReturnType GPIO_PIN_toggle (const pin_config_t *pin_config){
    Std_ReturnType ret=E_OK;
    if(NULL==pin_config)
    {
        ret=E_NOT_OK;
    }
    else
    {
        TOGGLE_BIT(*LAT_register[pin_config->PORT],pin_config->PIN);
    }
    
        return ret;
}
#endif

/**
 * 
 * @param port
 * @param direction
 * @return 
 */
#if GPIO_INTRFACE_STATUS==ENABLE
Std_ReturnType GPIO_PORT_directoin_intialization (port_index_t port , uint8 direction){
    Std_ReturnType ret=E_OK;
    if(port>PORT_MAX_SIZE-1)
    {
        ret=E_NOT_OK;
    }
    else
    {
        *TRIS_register[port]= direction;
        
    }
    
        return ret;
}
#endif

/**
 * 
 * @param port
 * @param port_directoin
 * @return 
 */
#if GPIO_INTRFACE_STATUS==ENABLE
Std_ReturnType GPIO_PORT_get_directoin_status (port_index_t port ,uint8 *port_directoin ){
    Std_ReturnType ret=E_OK;
    if((NULL==port_directoin)||(port>PORT_MAX_SIZE-1))
    {
        ret=E_NOT_OK;
    }
    else
    {
         *port_directoin = *TRIS_register[port];
    }
    
        return ret;
}
#endif

/**
 * 
 * @param port
 * @param logic
 * @return 
 */
#if GPIO_INTRFACE_STATUS==ENABLE
Std_ReturnType GPIO_PORT_write_logic (port_index_t port ,uint8 logic){
    Std_ReturnType ret=E_OK;
    if(port>PORT_MAX_SIZE-1)
    {
        ret=E_NOT_OK;
    }
    else
    {
         *LAT_register[port] = logic;
    }
    
        return ret;
}
#endif


/**
 * 
 * @param port
 * @param logic
 * @return 
 */
#if GPIO_INTRFACE_STATUS==ENABLE
Std_ReturnType GPIO_PORT_read_logic (port_index_t port ,uint8 *logic){
    Std_ReturnType ret=E_OK;
    if((NULL==logic)||(port>PORT_MAX_SIZE-1))
    {
        ret=E_NOT_OK;
    }
    else
    {
        *logic = *PORT_register[port];
    }
    
        return ret;
}
#endif

/**
 * 
 * @param port
 * @return 
 */
#if GPIO_INTRFACE_STATUS==ENABLE
Std_ReturnType GPIO_PORT_toggle (port_index_t port){
    Std_ReturnType ret=E_OK;
    if(port>PORT_MAX_SIZE-1)
    {
        ret=E_NOT_OK;
    }
    else
    {
        *LAT_register[port] ^= PORT_MASK; 
    }
    
        return ret;
}
#endif

/**
 * 
 * @param pin_config
 * @return 
 */
#if GPIO_INTRFACE_STATUS==ENABLE
Std_ReturnType GPIO_PIN_intialization (const pin_config_t *pin_config){
    Std_ReturnType ret=E_OK;
    if(NULL==pin_config)
    {
        ret=E_NOT_OK;
    }
    else
    { 
        GPIO_PIN_directoin_intialization(pin_config);
        GPIO_PIN_write_logic(pin_config , pin_config->LOGIC);
    }
            return ret;

}
#endif
