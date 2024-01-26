/* 
 * File:   mcal_std_types.h
 * Author: YaseenEzzat
 *
 * Created on October 22, 2023, 11:45 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* Section : Includes*/
#include <stdbool.h>
#include <stdint.h>
#include"std_libraries.h"
#include"compiler.h"

/* Section : Macro Declaration*/
#ifndef _Bool
#define _Bool unsigned char
#endif

#ifndef FALSE
#define FALSE		(boolean)false
#endif
#ifndef TRUE
#define TRUE		(boolean)true
#endif

#ifndef False
#define False		(boolean)false
#endif
#ifndef True
#define True		(boolean)true
#endif

#define STD_ON              0X01
#define STD_OFF             0X00

#define STD_ACTIVE          0X01
#define STD_IDEL            0X00

#define E_OK                (Std_ReturnType)0x01
#define E_NOT_OK            (Std_ReturnType)0x00

/* Section : Macro Function Declaration*/


/* Section : Data Type Declaration*/
typedef _Bool      			boolean;
typedef int8_t         		sint8;
typedef uint8_t       		uint8;
typedef char				char_t;
typedef int16_t        		sint16;
typedef uint16_t      		uint16;
typedef int32_t         	sint32;
typedef uint32_t       		uint32;
typedef int64_t  			sint64;
typedef uint64_t  			uint64;
typedef uint_least8_t       uint8_least;
typedef uint_least16_t      uint16_least;
typedef uint_least32_t      uint32_least;
typedef int_least8_t        sint8_least;
typedef int_least16_t       sint16_least;
typedef int_least32_t       sint32_least;
typedef float               float32;
typedef double              float64;


typedef volatile int8_t vint8_t;
typedef volatile uint8_t vuint8_t;

typedef volatile int16_t vint16_t;
typedef volatile uint16_t vuint16_t;

typedef volatile int32_t vint32_t;
typedef volatile uint32_t vuint32_t;

typedef volatile int64_t vint64_t;
typedef volatile uint64_t vuint64_t;

typedef uint8 Std_ReturnType;

/* Section : Function Declaration*/



#endif	/* MCAL_STD_TYPES_H */

