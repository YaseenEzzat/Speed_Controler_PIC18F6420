/* 
 * File:   hal_GPIO.h
 * Author: YaseenEzzat
 *
 * Created on October 22, 2023, 11:03 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* Section : Includes*/
#include "../../../../../Microchip/xc8/v2.30/pic/include/proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include"hal_gpoi_config.h"

/* Section : Macro Declaration*/
#define PIN_MAX_SIZE    8
#define PORT_MAX_SIZE   5
#define BIT_MASK        1
#define PORT_MASK       0xFF

/* Section : Macro Function Declaration*/
#define HWREG8(_x)                      (*((vuint8_t *)(_x)))
#define portc_LATc                      (HWREG8(0xF8B))
#define portc_TRISc                     (HWREG8(0xF94))

#define SET_BIT(REG,BIT_NUM)          (REG|=(BIT_MASK<<BIT_NUM))
#define CLEAR_BIT(REG,BIT_NUM)        (REG&=~(BIT_MASK<<BIT_NUM))
#define TOGGLE_BIT(REG,BIT_NUM)       (REG^=(BIT_MASK<<BIT_NUM))
#define READ_BIT(REG,BIT_NUM)         ((REG>>BIT_NUM)&BIT_MASK)



/* Section : Data Type Declaration*/
typedef enum {
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7  
}pin_num_t;

typedef enum {
    portA=0,
    portB,
    portC,
    portD,
    portE    
}port_index_t;

typedef enum { 
    GPIO_PIN_LOW=0,
    GPIO_PIN_HIGH
}pin_logic_t;

typedef enum { 
    GPIO_PIN_OUTPUT=0,
    GPIO_PIN_INPUT
}pin_directoin_t;

typedef struct {
    uint8 PORT          :3;     //@ref port_index_t
    uint8 PIN           :3;     //@ref pin_num_t
    uint8 LOGIC         :1;     //@ref pin_logic_t
    uint8 DIRECTOION    :1;     //@ref pin_directoin_t
}pin_config_t;

/* Section : Function Declaration*/

Std_ReturnType GPIO_PIN_directoin_intialization (const pin_config_t *pin_config);
Std_ReturnType GPIO_PIN_get_directoin_status (const pin_config_t *pin_config ,pin_directoin_t *pin_directoin );
Std_ReturnType GPIO_PIN_write_logic (const pin_config_t *pin_config ,pin_logic_t pin_logic );
Std_ReturnType GPIO_PIN_read_logic (const pin_config_t *pin_config ,pin_logic_t *pin_logic );
Std_ReturnType GPIO_PIN_toggle (const pin_config_t *pin_config);
Std_ReturnType GPIO_PIN_intialization (const pin_config_t *pin_config);

Std_ReturnType GPIO_PORT_directoin_intialization (port_index_t port , uint8 direction);
Std_ReturnType GPIO_PORT_get_directoin_status (port_index_t port ,uint8 *port_directoin );
Std_ReturnType GPIO_PORT_write_logic (port_index_t port ,uint8 logic);
Std_ReturnType GPIO_PORT_read_logic (port_index_t port ,uint8 *logic);
Std_ReturnType GPIO_PORT_toggle (port_index_t port);


#endif	/* HAL_GPIO_H */

