/* 
 * File:   mcal_external_interrupt.c
 * Author: YaseenEzzat
 *
 * Created on November 1, 2023, 10:05 AM
 */

#include "mcal_external_interrupt.h"


static Std_ReturnType INTERRUPT_INTx_clear_flag (const interrupt_INTx_config_t *INTx );
static Std_ReturnType INTERRUPT_INTx_set_priority_level (const interrupt_INTx_config_t *INTx );
static Std_ReturnType INTERRUPT_INTx_interrupt_enable (const interrupt_INTx_config_t *INTx );
static Std_ReturnType INTERRUPT_INTx_interrupt_disable (const interrupt_INTx_config_t *INTx );
static Std_ReturnType INTERRUPT_INTx_set_edge (const interrupt_INTx_config_t *INTx );
static Std_ReturnType INTERRUPT_INTx_handler (const interrupt_INTx_config_t *INTx );

void(*External_INT0_interrupt_handler)(void) = NULL;
void(*External_INT1_interrupt_handler)(void) = NULL;
void(*External_INT2_interrupt_handler)(void) = NULL;

void ISR_INT0 (void);
void ISR_INT1 (void);
void ISR_INT2 (void);

/**********************************************************************************************/


static Std_ReturnType INTERRUPT_RB_set_priority_level (const interrupt_RB_config_t *RB );
static Std_ReturnType INTERRUPT_RB_set_PULL_UPS (const interrupt_RB_config_t *RB );
static Std_ReturnType INTERRUPT_RB_handler (const interrupt_RB_config_t *RB );
static Std_ReturnType INTERRUPT_RB_pinx_initialization (const interrupt_RB_config_t *RB );

void(*TEMP_External_RB_interrupt_handler)(void) = NULL;
void ISR_RB (void);
/**********************************************************************************************/
/**
 * 
 * @param INTx
 * @return 
 */
Std_ReturnType INTERRUPT_INTx_initialization (const interrupt_INTx_config_t *INTx ){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==INTx)
    {
        ret = E_NOT_OK;
    }
    else
    {
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_PRIORITY_HIGH_ENABLE();
        INTERRUPT_PRIORITY_LOW_ENABLE();
        #endif

        #if INTERRUPT_GLOBAL==FEATURE_ENABLED
        INTERRUPT_GLOBAL_ENABLE();
        #endif

        #if INTERRUPT_PERIFERALS==FEATURE_ENABLED
        INTERRUPT_PERIFERALS_ENABLE();
        #endif


        ret = INTERRUPT_INTx_interrupt_disable(INTx);
        ret = GPIO_PIN_directoin_intialization(&(INTx->pin));
        ret = INTERRUPT_INTx_clear_flag(INTx);
        ret = INTERRUPT_INTx_set_edge(INTx);
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        ret = INTERRUPT_INTx_set_priority_level(INTx);
        #endif
        ret = INTERRUPT_INTx_handler (INTx);
        ret = INTERRUPT_INTx_interrupt_enable(INTx);
    }
    return ret;
            
    
}

/**
 * 
 * @param INTx
 * @return 
 */
Std_ReturnType INTERRUPT_INTx_deinitialization (const interrupt_INTx_config_t *INTx ){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==INTx)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
    }
    return ret;
}

/**
 * 
 * @param INTx
 * @return 
 */
static Std_ReturnType INTERRUPT_INTx_clear_flag (const interrupt_INTx_config_t *INTx ){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==INTx)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(INTx->INTx_pin){
            case INT0_pin:
                EXTERNAL_INTERRUPT_INT0_CLEAR_FALG();
                ret = E_OK;
                break;
            case INT1_pin:
                EXTERNAL_INTERRUPT_INT1_CLEAR_FALG();
                ret = E_OK;
                break;    
            case INT2_pin:
                EXTERNAL_INTERRUPT_INT2_CLEAR_FALG();
                ret = E_OK;
                break;
            default:
               ret = E_NOT_OK;      
        }
    }
    return ret;
}

/**
 * 
 * @param INTx
 * @return 
 */
#if INTERRUPT_PRIORITY==FEATURE_ENABLED
static Std_ReturnType INTERRUPT_INTx_set_priority_level (const interrupt_INTx_config_t *INTx ){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==INTx)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(INTx->INTx_pin){
            case INT1_pin:
                if(INTx->priority == INTERRUPT_PRIORITY_HIGH)
                {
                    EXTERNAL_INTERRUPT_INT1_PRIORITY_HIHG();
                }
                else if(INTx->priority == INTERRUPT_PRIORITY_LOW)
                EXTERNAL_INTERRUPT_INT1_PRIORITY_LOW();
                else{/*noting*/}
                ret = E_OK;
                break;
            case INT2_pin:
                if(INTx->priority == INTERRUPT_PRIORITY_HIGH)
                {
                    EXTERNAL_INTERRUPT_INT2_PRIORITY_HIHG();
                }
                else if(INTx->priority == INTERRUPT_PRIORITY_LOW)
                EXTERNAL_INTERRUPT_INT2_PRIORITY_LOW();
                else{/*noting*/}
                ret = E_OK;
                break;
            default:
               ret = E_NOT_OK;      
        }
        
        
    }
    return ret;
}
#endif

/**
 * 
 * @param INTx
 * @return 
 */
static Std_ReturnType INTERRUPT_INTx_interrupt_enable (const interrupt_INTx_config_t *INTx ){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==INTx)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(INTx->INTx_pin){
            case INT0_pin:
                EXTERNAL_INTERRUPT_INT0_ENABLE();
                ret = E_OK;
                break;
            case INT1_pin:
                EXTERNAL_INTERRUPT_INT1_ENABLE();
                ret = E_OK;
                break;    
            case INT2_pin:
                EXTERNAL_INTERRUPT_INT2_ENABLE();
                ret = E_OK;
                break;
            default:
               ret = E_NOT_OK;      
        }
        
    }
    return ret;
}
static Std_ReturnType INTERRUPT_INTx_interrupt_disable (const interrupt_INTx_config_t *INTx ){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL==INTx)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(INTx->INTx_pin){
            case INT0_pin:
                EXTERNAL_INTERRUPT_INT0_DISABLE();
                ret = E_OK;
                break;
            case INT1_pin:
                EXTERNAL_INTERRUPT_INT1_DISABLE();
                ret = E_OK;
                break;    
            case INT2_pin:
                EXTERNAL_INTERRUPT_INT2_DISABLE();
                ret = E_OK;
                break;
            default:
               ret = E_NOT_OK;      
        }  
    }
    return ret;
}

static Std_ReturnType INTERRUPT_INTx_set_edge (const interrupt_INTx_config_t *INTx ){
    
Std_ReturnType ret = E_NOT_OK;
    if(NULL==INTx)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(INTx->INTx_pin){
            case INT0_pin:
                if(INTx->interrupt_edge == INTERRUPT_FALLING_EDGE)
                {
                    EXTERNAL_INTERRUPT_INT0_FAlLING_EDGE();
                }
                else if(INTx->interrupt_edge == INTERRUPT_RISING_EDGE)
                EXTERNAL_INTERRUPT_INT0_RISING_EDGE();
                else{/*noting*/}
                ret = E_OK;
                break;
            case INT1_pin:
                if(INTx->interrupt_edge == INTERRUPT_FALLING_EDGE)
                {
                    EXTERNAL_INTERRUPT_INT1_FAlLING_EDGE();
                }
                else if(INTx->interrupt_edge == INTERRUPT_RISING_EDGE)
                EXTERNAL_INTERRUPT_INT1_RISING_EDGE();
                else{/*noting*/}
                ret = E_OK;
                break;
            case INT2_pin:
                if(INTx->interrupt_edge == INTERRUPT_FALLING_EDGE)
                {
                    EXTERNAL_INTERRUPT_INT2_FAlLING_EDGE();
                }
                else if(INTx->interrupt_edge == INTERRUPT_RISING_EDGE)
                EXTERNAL_INTERRUPT_INT2_RISING_EDGE();
                else{/*noting*/}
                ret = E_OK;
                break;
            default:
               ret = E_NOT_OK;      
        }  
    }
    return ret;
}
static Std_ReturnType INTERRUPT_INTx_handler (const interrupt_INTx_config_t *INTx ){
    
Std_ReturnType ret = E_NOT_OK;
    if(NULL==INTx)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(INTx->INTx_pin){
            case INT0_pin:
                if(INTx->External_INTx_interrupt_handler != NULL)
                {
                    External_INT0_interrupt_handler = INTx->External_INTx_interrupt_handler ;
                }
                else{/*noting*/}
                ret = E_OK;
                break;
            case INT1_pin:
                if(INTx->External_INTx_interrupt_handler != NULL)
                {
                    External_INT1_interrupt_handler = INTx->External_INTx_interrupt_handler ;
                }
                else{/*noting*/}
                ret = E_OK;
                break;
            case INT2_pin:
                if(INTx->External_INTx_interrupt_handler != NULL)
                {
                    External_INT2_interrupt_handler = INTx->External_INTx_interrupt_handler ;
                }
                else{/*noting*/}
                ret = E_OK;
                break;
            default:
               ret = E_NOT_OK;      
        }  
    }
    return ret;
}

void ISR_INT0 (void){
   EXTERNAL_INTERRUPT_INT0_CLEAR_FALG();
   if(External_INT0_interrupt_handler)
   {
       External_INT0_interrupt_handler();
       
   }
    
}
void ISR_INT1 (void){
    EXTERNAL_INTERRUPT_INT1_CLEAR_FALG();
    if(External_INT1_interrupt_handler)
   {
       External_INT1_interrupt_handler();
       

   }
}
void ISR_INT2 (void){
    EXTERNAL_INTERRUPT_INT2_CLEAR_FALG();
    if(External_INT2_interrupt_handler)
   {
       External_INT2_interrupt_handler();
       

   }
}

/*********************************************************************************************/
/**
 * 
 * @param INTx
 * @return 
 */
Std_ReturnType INTERRUPT_RB_initialization (const interrupt_RB_config_t *RB ){
  Std_ReturnType ret = E_NOT_OK;
    if(NULL==RB)
    {
        ret = E_NOT_OK;
    }
    else
    {
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        INTERRUPT_PRIORITY_ENABLE();
        INTERRUPT_PRIORITY_HIGH_ENABLE();
        INTERRUPT_PRIORITY_LOW_ENABLE();
        #endif

        #if INTERRUPT_GLOBAL==FEATURE_ENABLED
        INTERRUPT_GLOBAL_ENABLE();
        #endif

        #if INTERRUPT_PERIFERALS==FEATURE_ENABLED
        INTERRUPT_PERIFERALS_ENABLE();
        #endif

        EXTERNAL_INTERRUPT_RB_DISABLE();
        
        EXTERNAL_INTERRUPT_RB_CLEAR_FALG();
        INTERRUPT_RB_pinx_initialization(RB);
        INTERRUPT_RB_set_PULL_UPS(RB);
        #if INTERRUPT_PRIORITY==FEATURE_ENABLED
        INTERRUPT_RB_set_priority_level(RB);
        #endif
        INTERRUPT_RB_handler(RB);
        
        EXTERNAL_INTERRUPT_RB_ENABLE();
    }  
  return ret;
}


/**
 * 
 * @param INTx
 * @return 
 */
Std_ReturnType INTERRUPT_RB_deinitialization (const interrupt_RB_config_t *RB ){  
Std_ReturnType ret = E_NOT_OK;
    if(NULL==RB)
    {
        ret = E_NOT_OK;
    }
    else
    {
        EXTERNAL_INTERRUPT_RB_DISABLE();
        ret = E_OK;
    }  
  return ret;
}






      

/**
 * 
 * @param RB
 * @return 
 */
#if INTERRUPT_PRIORITY==FEATURE_ENABLED
static Std_ReturnType INTERRUPT_RB_set_priority_level (const interrupt_RB_config_t *RB ){   
Std_ReturnType ret = E_NOT_OK;
    if(NULL==RB)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(RB->priority == INTERRUPT_PRIORITY_HIGH )
        {
            EXTERNAL_INTERRUPT_RB_HIGH_PRIORITY();
        }
        else if(RB->priority == INTERRUPT_PRIORITY_LOW)
        {
             EXTERNAL_INTERRUPT_RB_LOW_PRIORITY();        
        }
        else{/*nothing*/}
    }  
  return ret;
}
#endif


/**
 * 
 * @param RB
 * @return 
 */
static Std_ReturnType INTERRUPT_RB_set_PULL_UPS (const interrupt_RB_config_t *RB ){   
Std_ReturnType ret = E_NOT_OK;
    if(NULL==RB)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(RB->PULL_UPS == INTERRUPT_PULL_UPS_ENABLED  )
        {
           EXTERNAL_INTERRUPT_RB_PULL_UPS_ENABLE();
        }
        else if(RB->PULL_UPS == INTERRUPT_PULL_UPS_DISABLED)
        {
             EXTERNAL_INTERRUPT_RB_PULL_UPS_DISABLE();        
        }
        else{/*nothing*/}
        
    }  
  return ret;
}


static Std_ReturnType INTERRUPT_RB_handler (const interrupt_RB_config_t *RB ){
 Std_ReturnType ret = E_NOT_OK;
    if(NULL==RB)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(RB->External_RB_interrupt_handler !=NULL  )
        {
           TEMP_External_RB_interrupt_handler = RB->External_RB_interrupt_handler;
        }
        
        else{/*nothing*/}
        
    }  
  return ret;
}

/**
 * 
 * @param RB
 * @return 
 */
static Std_ReturnType INTERRUPT_RB_pinx_initialization (const interrupt_RB_config_t *RB ){
    Std_ReturnType ret = E_NOT_OK;
    uint8 counter=0;
    if(NULL==RB)
    {
        ret = E_NOT_OK;
    }
    else
    {
     
        ret = GPIO_PIN_directoin_intialization(&(RB->pin));
       
        
        
    }  
  return ret;
}

void ISR_RB (void){
    EXTERNAL_INTERRUPT_RB_CLEAR_FALG();
    if(TEMP_External_RB_interrupt_handler)
    {
        TEMP_External_RB_interrupt_handler();
    }
    
}