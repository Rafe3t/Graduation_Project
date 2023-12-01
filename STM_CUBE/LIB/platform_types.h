/*=================================================================================*/
/*  File        : platform_types.h                                                  */
/*  Description : This file includes PORT Driver implementations for STM32F407VGT6 */
/*  Author      : Mohamed Maged Mohamed. Embedded SW Engineer                      */
/*  Date        : 25/11/2023                                                       */
/*  Linkedin    : www.linkedin.com/in/mohamed-elsayed-5636ab289                    */
/*  mail        : mhamedmaged169@gmil.com                                          */
/*=================================================================================*/
#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#include"std_types.h"


typedef enum
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;

typedef enum
{
  HAL_UNLOCKED = 0x00U,
  HAL_LOCKED   = 0x01U
} HAL_LockTypeDef;

typedef enum
{
  HAL_TICK_FREQ_10HZ         = 100U,
  HAL_TICK_FREQ_100HZ        = 10U,
  HAL_TICK_FREQ_1KHZ         = 1U,
  HAL_TICK_FREQ_DEFAULT      = HAL_TICK_FREQ_1KHZ
} HAL_TickFreqTypeDef;




/* CPU register type width */

#define CPU_TYPE_8           (8u)
#define CPU_TYPE_16          (16u)
#define CPU_TYPE_32          (32u)

/* Bit order defintion */

#define MSB_FIRST             (0u)
#define LSB_FIRST             (1u)

/* Byte order definition */

#define HIGH_BYTE_FIRST        (0u)
#define LOW_BYTE_FIRST         (1u)

/* Platform Type and order definition (This is the only configurable part of this header file)*/

#define CPU_TYPE                CPU_TYPE_32
#define CPU_BIT_ORDER           LSB_FIRST
#define CPU_BYTE_ORDER          LOW_BYTE_FIRST


/* AUTOSAR integer data types */

#define NULL_PTR    ((void*)0)

typedef unsigned char         uint8_t;          /*           0 .. 255              */
typedef signed char           sint8_t;          /*        -128 .. +127             */
typedef unsigned short        uint16_t;         /*           0 .. 65535            */
typedef signed short          sint16_t;         /*      -32768 .. +32767           */
typedef unsigned long         uint32_t;         /*           0 .. 4294967295       */
typedef signed long           sint32_t;         /* -2147483648 .. +2147483647      */
typedef unsigned long long    uint64_t;         /*       0 .. 18446744073709551615  */
typedef signed long long      sint64_t;         /* -9223372036854775808 .. 9223372036854775807 */
typedef float                 float32_t;
typedef double                float64_t;

/* Boolean Data Type */
typedef unsigned char boolean;



#define IS_TICKFREQ(FREQ) (((FREQ) == HAL_TICK_FREQ_10HZ)  || \
                           ((FREQ) == HAL_TICK_FREQ_100HZ) || \
                           ((FREQ) == HAL_TICK_FREQ_1KHZ))

extern  uint32_t uwTick;
extern  uint32_t uwTickPrio;
extern HAL_TickFreqTypeDef uwTickFreq;


#endif
