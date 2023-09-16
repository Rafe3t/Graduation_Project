 /******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: platform_types.h
 *
 * Description: types for STM32F407VG
 *
 * Author: Ahmed Refaat
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

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

typedef unsigned char         uint8;          /*           0 .. 255              */
typedef signed char           sint8;          /*        -128 .. +127             */
typedef unsigned short        uint16;         /*           0 .. 65535            */
typedef signed short          sint16;         /*      -32768 .. +32767           */
typedef unsigned long         uint32;         /*           0 .. 4294967295       */
typedef signed long           sint32;         /* -2147483648 .. +2147483647      */
typedef unsigned long long    uint64;         /*       0 .. 18446744073709551615  */
typedef signed long long      sint64;         /* -9223372036854775808 .. 9223372036854775807 */
typedef float                 float32;
typedef double                float64;

/* Boolean Data Type */
typedef unsigned char boolean;


#endif
