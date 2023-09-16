 /******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: std_types.h
 *
 * Description: types for STM32F407VG
 *
 * Author: Ahmed Refaat
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include "platform_types.h"

typedef struct
{
    uint16 vendorID;
    uint16 moduleID;
    uint8 sw_major_version;
    uint8 sw_minor_version;
    uint8 sw_patch_version;
} Std_VersionInfoType;

#define STD_HIGH        (1u)
#define STD_LOW         (0u)

#define STD_ACTIVE      (1u)
#define STD_IDLE        (0u)

#define STD_ON          (1u)
#define STD_OFF         (0u)

#endif
