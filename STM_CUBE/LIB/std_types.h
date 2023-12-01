/*=================================================================================*/
/*  File        : std_types.h                                                  */
/*  Description : This file includes PORT Driver implementations for STM32F407VGT6 */
/*  Author      : Mohamed Maged Mohamed. Embedded SW Engineer                      */
/*  Date        : 25/11/2023                                                       */
/*  Linkedin    : www.linkedin.com/in/mohamed-elsayed-5636ab289                    */
/*  mail        : mhamedmaged169@gmil.com                                          */
/*=================================================================================*/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include "platform_types.h"

typedef struct
{
    uint16_t vendorID;
    uint16_t moduleID;
    uint8_t sw_major_version;
    uint8_t sw_minor_version;
    uint8_t sw_patch_version;
} Std_VersionInfoType;

#define STD_HIGH        (1u)
#define STD_LOW         (0u)

#define STD_ACTIVE      (1u)
#define STD_IDLE        (0u)

#define STD_ON          (1u)
#define STD_OFF         (0u)

/****************************************************************************************/
typedef enum
{
  RESET = 0U,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0U,
  ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum
{
  SUCCESS = 0U,
  ERROR = !SUCCESS
} ErrorStatus;

#endif
