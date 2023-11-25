/*=================================================================================*/
/*  File        : GPIO.h                                                           */
/*  Description : This file includes PORT Driver implementations for STM32F407VGT6 */
/*  Author      : Mohamed Maged Mohamed. Embedded SW Engineer                      */
/*  Date        : 25/11/2023                                                       */
/*  Linkedin    : www.linkedin.com/in/mohamed-elsayed-5636ab289                    */
/*  mail        : mhamedmaged169@gmil.com                                          */
/*=================================================================================*/
#include "platform_types.h"
#include "DEF.h"
/* Define to prevent recursive inclusion -----------------------------------*****--*/
#ifndef __GPIO_H
#define __GPIO_H
/************************************Define for STM32407VGT6************************* */
#define GPIO_AF0_RTC_50Hz ((uint8_t)0x00) /* RTC_50Hz Alternate Function mapping                       */
#define GPIO_AF0_MCO ((uint8_t)0x00)      /* MCO (MCO1 and MCO2) Alternate Function mapping            */
#define GPIO_AF0_TAMPER ((uint8_t)0x00)   /* TAMPER (TAMPER_1 and TAMPER_2) Alternate Function mapping */
#define GPIO_AF0_SWJ ((uint8_t)0x00)      /* SWJ (SWD and JTAG) Alternate Function mapping             */
#define GPIO_AF0_TRACE ((uint8_t)0x00)    /* TRACE Alternate Function mapping                          */

/**
 * @brief   AF 1 selection
 */
#define GPIO_AF1_TIM1 ((uint8_t)0x01) /* TIM1 Alternate Function mapping */
#define GPIO_AF1_TIM2 ((uint8_t)0x01) /* TIM2 Alternate Function mapping */

/**
 * @brief   AF 2 selection
 */
#define GPIO_AF2_TIM3 ((uint8_t)0x02) /* TIM3 Alternate Function mapping */
#define GPIO_AF2_TIM4 ((uint8_t)0x02) /* TIM4 Alternate Function mapping */
#define GPIO_AF2_TIM5 ((uint8_t)0x02) /* TIM5 Alternate Function mapping */

/**
 * @brief   AF 3 selection
 */
#define GPIO_AF3_TIM8 ((uint8_t)0x03)  /* TIM8 Alternate Function mapping  */
#define GPIO_AF3_TIM9 ((uint8_t)0x03)  /* TIM9 Alternate Function mapping  */
#define GPIO_AF3_TIM10 ((uint8_t)0x03) /* TIM10 Alternate Function mapping */
#define GPIO_AF3_TIM11 ((uint8_t)0x03) /* TIM11 Alternate Function mapping */

/**
 * @brief   AF 4 selection
 */
#define GPIO_AF4_I2C1 ((uint8_t)0x04) /* I2C1 Alternate Function mapping */
#define GPIO_AF4_I2C2 ((uint8_t)0x04) /* I2C2 Alternate Function mapping */
#define GPIO_AF4_I2C3 ((uint8_t)0x04) /* I2C3 Alternate Function mapping */

/**
 * @brief   AF 5 selection
 */
#define GPIO_AF5_SPI1 ((uint8_t)0x05)    /* SPI1 Alternate Function mapping        */
#define GPIO_AF5_SPI2 ((uint8_t)0x05)    /* SPI2/I2S2 Alternate Function mapping   */
#define GPIO_AF5_I2S3ext ((uint8_t)0x05) /* I2S3ext_SD Alternate Function mapping  */

/**
 * @brief   AF 6 selection
 */
#define GPIO_AF6_SPI3 ((uint8_t)0x06)    /* SPI3/I2S3 Alternate Function mapping  */
#define GPIO_AF6_I2S2ext ((uint8_t)0x06) /* I2S2ext_SD Alternate Function mapping */

/**
 * @brief   AF 7 selection
 */
#define GPIO_AF7_USART1 ((uint8_t)0x07)  /* USART1 Alternate Function mapping     */
#define GPIO_AF7_USART2 ((uint8_t)0x07)  /* USART2 Alternate Function mapping     */
#define GPIO_AF7_USART3 ((uint8_t)0x07)  /* USART3 Alternate Function mapping     */
#define GPIO_AF7_I2S3ext ((uint8_t)0x07) /* I2S3ext_SD Alternate Function mapping */

/**
 * @brief   AF 8 selection
 */
#define GPIO_AF8_UART4 ((uint8_t)0x08)  /* UART4 Alternate Function mapping  */
#define GPIO_AF8_UART5 ((uint8_t)0x08)  /* UART5 Alternate Function mapping  */
#define GPIO_AF8_USART6 ((uint8_t)0x08) /* USART6 Alternate Function mapping */

/**
 * @brief   AF 9 selection
 */
#define GPIO_AF9_CAN1 ((uint8_t)0x09)  /* CAN1 Alternate Function mapping  */
#define GPIO_AF9_CAN2 ((uint8_t)0x09)  /* CAN2 Alternate Function mapping  */
#define GPIO_AF9_TIM12 ((uint8_t)0x09) /* TIM12 Alternate Function mapping */
#define GPIO_AF9_TIM13 ((uint8_t)0x09) /* TIM13 Alternate Function mapping */
#define GPIO_AF9_TIM14 ((uint8_t)0x09) /* TIM14 Alternate Function mapping */

/**
 * @brief   AF 10 selection
 */
#define GPIO_AF10_OTG_FS ((uint8_t)0x0A) /* OTG_FS Alternate Function mapping */
#define GPIO_AF10_OTG_HS ((uint8_t)0x0A) /* OTG_HS Alternate Function mapping */

/**
 * @brief   AF 11 selection
 */
#define GPIO_AF11_ETH ((uint8_t)0x0B) /* ETHERNET Alternate Function mapping */

/**
 * @brief   AF 12 selection
 */
#define GPIO_AF12_FSMC ((uint8_t)0x0C)      /* FSMC Alternate Function mapping                     */
#define GPIO_AF12_OTG_HS_FS ((uint8_t)0x0C) /* OTG HS configured in FS, Alternate Function mapping */
#define GPIO_AF12_SDIO ((uint8_t)0x0C)      /* SDIO Alternate Function mapping                     */

/**
 * @brief   AF 13 selection
 */
#define GPIO_AF13_DCMI ((uint8_t)0x0D) /* DCMI Alternate Function mapping */

/**
 * @brief   AF 15 selection
 */
#define GPIO_AF15_EVENTOUT ((uint8_t)0x0F)
/***************************************************************************************/
#define GPIO_GET_INDEX(__GPIOx__) (uint8_t)(((__GPIOx__) == (GPIOA)) ? 0U : ((__GPIOx__) == (GPIOB)) ? 1U \
                                                                        : ((__GPIOx__) == (GPIOC))   ? 2U \
                                                                        : ((__GPIOx__) == (GPIOD))   ? 3U \
                                                                        : ((__GPIOx__) == (GPIOE))   ? 4U \
                                                                        : ((__GPIOx__) == (GPIOF))   ? 5U \
                                                                        : ((__GPIOx__) == (GPIOG))   ? 6U \
                                                                        : ((__GPIOx__) == (GPIOH))   ? 7U \
                                                                                                     : 8U)
/***************************************************************************************/
#define IS_GPIO_AF(AF) (((AF) == GPIO_AF0_RTC_50Hz) || ((AF) == GPIO_AF9_TIM14) ||  \
                        ((AF) == GPIO_AF0_MCO) || ((AF) == GPIO_AF0_TAMPER) ||      \
                        ((AF) == GPIO_AF0_SWJ) || ((AF) == GPIO_AF0_TRACE) ||       \
                        ((AF) == GPIO_AF1_TIM1) || ((AF) == GPIO_AF1_TIM2) ||       \
                        ((AF) == GPIO_AF2_TIM3) || ((AF) == GPIO_AF2_TIM4) ||       \
                        ((AF) == GPIO_AF2_TIM5) || ((AF) == GPIO_AF3_TIM8) ||       \
                        ((AF) == GPIO_AF4_I2C1) || ((AF) == GPIO_AF4_I2C2) ||       \
                        ((AF) == GPIO_AF4_I2C3) || ((AF) == GPIO_AF5_SPI1) ||       \
                        ((AF) == GPIO_AF5_SPI2) || ((AF) == GPIO_AF9_TIM13) ||      \
                        ((AF) == GPIO_AF6_SPI3) || ((AF) == GPIO_AF9_TIM12) ||      \
                        ((AF) == GPIO_AF7_USART1) || ((AF) == GPIO_AF7_USART2) ||   \
                        ((AF) == GPIO_AF7_USART3) || ((AF) == GPIO_AF8_UART4) ||    \
                        ((AF) == GPIO_AF8_UART5) || ((AF) == GPIO_AF8_USART6) ||    \
                        ((AF) == GPIO_AF9_CAN1) || ((AF) == GPIO_AF9_CAN2) ||       \
                        ((AF) == GPIO_AF10_OTG_FS) || ((AF) == GPIO_AF10_OTG_HS) || \
                        ((AF) == GPIO_AF11_ETH) || ((AF) == GPIO_AF12_OTG_HS_FS) || \
                        ((AF) == GPIO_AF12_SDIO) || ((AF) == GPIO_AF13_DCMI) ||     \
                        ((AF) == GPIO_AF12_FSMC) || ((AF) == GPIO_AF15_EVENTOUT))
/******************************************************************************************/

/**************************************************************************************/

typedef struct
{
  uint32_t Pin; /*!< Specifies the GPIO pins to be configured.
                    This parameter can be any value of @ref GPIO_pins_define */

  uint32_t Mode; /*!< Specifies the operating mode for the selected pins.
                     This parameter can be a value of @ref GPIO_mode_define */

  uint32_t Pull; /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
                     This parameter can be a value of @ref GPIO_pull_define */

  uint32_t Speed; /*!< Specifies the speed for the selected pins.
                      This parameter can be a value of @ref GPIO_speed_define */

  uint32_t Alternate; /*!< Peripheral to be connected to the selected pins.
                          This parameter can be a value of @ref GPIO_Alternate_function_selection */
} GPIO_InitTypeDef;

typedef enum
{
  GPIO_PIN_RESET = 0,
  GPIO_PIN_SET
} GPIO_PinState;
/*************************************************************************************/
typedef struct /*CHECK THAT*/
{
  uint32_t MODER;   /*!< GPIO port mode register,               Address offset: 0x00      */
  uint32_t OTYPER;  /*!< GPIO port output type register,        Address offset: 0x04      */
  uint32_t OSPEEDR; /*!< GPIO port output speed register,       Address offset: 0x08      */
  uint32_t PUPDR;   /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  uint32_t IDR;     /*!< GPIO port input data register,         Address offset: 0x10      */
  uint32_t ODR;     /*!< GPIO port output data register,        Address offset: 0x14      */
  uint32_t BSRR;    /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  uint32_t LCKR;    /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  uint32_t AFR[2];  /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;
/************************************************************************************/

#define GPIO_PIN_0 ((uint16_t)0x0001)   /* Pin 0 selected    */
#define GPIO_PIN_1 ((uint16_t)0x0002)   /* Pin 1 selected    */
#define GPIO_PIN_2 ((uint16_t)0x0004)   /* Pin 2 selected    */
#define GPIO_PIN_3 ((uint16_t)0x0008)   /* Pin 3 selected    */
#define GPIO_PIN_4 ((uint16_t)0x0010)   /* Pin 4 selected    */
#define GPIO_PIN_5 ((uint16_t)0x0020)   /* Pin 5 selected    */
#define GPIO_PIN_6 ((uint16_t)0x0040)   /* Pin 6 selected    */
#define GPIO_PIN_7 ((uint16_t)0x0080)   /* Pin 7 selected    */
#define GPIO_PIN_8 ((uint16_t)0x0100)   /* Pin 8 selected    */
#define GPIO_PIN_9 ((uint16_t)0x0200)   /* Pin 9 selected    */
#define GPIO_PIN_10 ((uint16_t)0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11 ((uint16_t)0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12 ((uint16_t)0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13 ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14 ((uint16_t)0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15 ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_All ((uint16_t)0xFFFF) /* All pins selected */

#define GPIO_PIN_MASK 0x0000FFFFU /* PIN mask for assert test */
/**
 * @}
 */

/** @defgroup GPIO_mode_define GPIO mode define
 * @brief GPIO Configuration Mode
 *        Elements values convention: 0x00WX00YZ
 *           - W  : EXTI trigger detection on 3 bits
 *           - X  : EXTI mode (IT or Event) on 2 bits
 *           - Y  : Output type (Push Pull or Open Drain) on 1 bit
 *           - Z  : GPIO mode (Input, Output, Alternate or Analog) on 2 bits
 * @{
 */
#define GPIO_MODE_INPUT MODE_INPUT                    /*!< Input Floating Mode                   */
#define GPIO_MODE_OUTPUT_PP (MODE_OUTPUT | OUTPUT_PP) /*!< Output Push Pull Mode                 */
#define GPIO_MODE_OUTPUT_OD (MODE_OUTPUT | OUTPUT_OD) /*!< Output Open Drain Mode                */
#define GPIO_MODE_AF_PP (MODE_AF | OUTPUT_PP)         /*!< Alternate Function Push Pull Mode     */
#define GPIO_MODE_AF_OD (MODE_AF | OUTPUT_OD)         /*!< Alternate Function Open Drain Mode    */

#define GPIO_MODE_ANALOG MODE_ANALOG /*!< Analog Mode  */

#define GPIO_MODE_IT_RISING (MODE_INPUT | EXTI_IT | TRIGGER_RISING)                           /*!< External Interrupt Mode with Rising edge trigger detection          */
#define GPIO_MODE_IT_FALLING (MODE_INPUT | EXTI_IT | TRIGGER_FALLING)                         /*!< External Interrupt Mode with Falling edge trigger detection         */
#define GPIO_MODE_IT_RISING_FALLING (MODE_INPUT | EXTI_IT | TRIGGER_RISING | TRIGGER_FALLING) /*!< External Interrupt Mode with Rising/Falling edge trigger detection  */

#define GPIO_MODE_EVT_RISING (MODE_INPUT | EXTI_EVT | TRIGGER_RISING)                           /*!< External Event Mode with Rising edge trigger detection             */
#define GPIO_MODE_EVT_FALLING (MODE_INPUT | EXTI_EVT | TRIGGER_FALLING)                         /*!< External Event Mode with Falling edge trigger detection            */
#define GPIO_MODE_EVT_RISING_FALLING (MODE_INPUT | EXTI_EVT | TRIGGER_RISING | TRIGGER_FALLING) /*!< External Event Mode with Rising/Falling edge trigger detection     */

/** @defgroup GPIO_speed_define  GPIO speed define
 * @brief GPIO Output Maximum frequency
 * @{
 */
#define GPIO_SPEED_FREQ_LOW 0x00000000U       /*!< IO works at 2 MHz, please refer to the product datasheet */
#define GPIO_SPEED_FREQ_MEDIUM 0x00000001U    /*!< range 12,5 MHz to 50 MHz, please refer to the product datasheet */
#define GPIO_SPEED_FREQ_HIGH 0x00000002U      /*!< range 25 MHz to 100 MHz, please refer to the product datasheet  */
#define GPIO_SPEED_FREQ_VERY_HIGH 0x00000003U /*!< range 50 MHz to 200 MHz, please refer to the product datasheet  */

/** @defgroup GPIO_pull_define GPIO pull define
 * @brief GPIO Pull-Up or Pull-Down Activation
 * @{
 */
#define GPIO_NOPULL 0x00000000U   /*!< No Pull-up or Pull-down activation  */
#define GPIO_PULLUP 0x00000001U   /*!< Pull-up activation                  */
#define GPIO_PULLDOWN 0x00000002U /*!< Pull-down activation                */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup GPIO_Exported_Macros GPIO Exported Macros
 * @{
 */

/**
 * @brief  Checks whether the specified EXTI line flag is set or not.
 * @param  __EXTI_LINE__ specifies the EXTI line flag to check.
 *         This parameter can be GPIO_PIN_x where x can be(0..15)
 * @retval The new state of __EXTI_LINE__ (SET or RESET).
 */
#define __HAL_GPIO_EXTI_GET_FLAG(__EXTI_LINE__) (EXTI->PR & (__EXTI_LINE__))

/**
 * @brief  Clears the EXTI's line pending flags.
 * @param  __EXTI_LINE__ specifies the EXTI lines flags to clear.
 *         This parameter can be any combination of GPIO_PIN_x where x can be (0..15)
 * @retval None
 */
#define __HAL_GPIO_EXTI_CLEAR_FLAG(__EXTI_LINE__) (EXTI->PR = (__EXTI_LINE__))

/**
 * @brief  Checks whether the specified EXTI line is asserted or not.
 * @param  __EXTI_LINE__ specifies the EXTI line to check.
 *          This parameter can be GPIO_PIN_x where x can be(0..15)
 * @retval The new state of __EXTI_LINE__ (SET or RESET).
 */
#define __HAL_GPIO_EXTI_GET_IT(__EXTI_LINE__) (EXTI->PR & (__EXTI_LINE__))

/**
 * @brief  Clears the EXTI's line pending bits.
 * @param  __EXTI_LINE__ specifies the EXTI lines to clear.
 *          This parameter can be any combination of GPIO_PIN_x where x can be (0..15)
 * @retval None
 */
#define __HAL_GPIO_EXTI_CLEAR_IT(__EXTI_LINE__) (EXTI->PR = (__EXTI_LINE__))

/**
 * @brief  Generates a Software interrupt on selected EXTI line.
 * @param  __EXTI_LINE__ specifies the EXTI line to check.
 *          This parameter can be GPIO_PIN_x where x can be(0..15)
 * @retval None
 */
#define __HAL_GPIO_EXTI_GENERATE_SWIT(__EXTI_LINE__) (EXTI->SWIER |= (__EXTI_LINE__))
/**
 * @}
 */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup GPIO_Exported_Functions
 * @{
 */

/** @addtogroup GPIO_Exported_Functions_Group1
 * @{
 */
/* Initialization and de-initialization functions *****************************/
void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void HAL_GPIO_DeInit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);
/**
 * @}
 */

/** @addtogroup GPIO_Exported_Functions_Group2
 * @{
 */
/* IO operation functions *****************************************************/
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin, GPIO_PinState PinState);
void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

/**
 * @}
 */

/**
 * @}
 */
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup GPIO_Private_Constants GPIO Private Constants
 * @{
 */
#define GPIO_MODE_Pos 0U
#define GPIO_MODE (0x3UL << GPIO_MODE_Pos)
#define MODE_INPUT (0x0UL << GPIO_MODE_Pos)
#define MODE_OUTPUT (0x1UL << GPIO_MODE_Pos)
#define MODE_AF (0x2UL << GPIO_MODE_Pos)
#define MODE_ANALOG (0x3UL << GPIO_MODE_Pos)
#define OUTPUT_TYPE_Pos 4U
#define OUTPUT_TYPE (0x1UL << OUTPUT_TYPE_Pos)
#define OUTPUT_PP (0x0UL << OUTPUT_TYPE_Pos)
#define OUTPUT_OD (0x1UL << OUTPUT_TYPE_Pos)
#define EXTI_MODE_Pos 16U
#define EXTI_MODE (0x3UL << EXTI_MODE_Pos)
#define EXTI_IT (0x1UL << EXTI_MODE_Pos)
#define EXTI_EVT (0x2UL << EXTI_MODE_Pos)
#define TRIGGER_MODE_Pos 20U
#define TRIGGER_MODE (0x7UL << TRIGGER_MODE_Pos)
#define TRIGGER_RISING (0x1UL << TRIGGER_MODE_Pos)
#define TRIGGER_FALLING (0x2UL << TRIGGER_MODE_Pos)

/**
 * @}
 */

/* Private macros ------------------------------------------------------------*/
/** @defgroup GPIO_Private_Macros GPIO Private Macros
 * @{
 */
#define IS_GPIO_PIN_ACTION(ACTION) (((ACTION) == GPIO_PIN_RESET) || ((ACTION) == GPIO_PIN_SET))
#define IS_GPIO_PIN(PIN) (((((uint32_t _t)PIN) & GPIO_PIN_MASK) != 0x00U) && ((((uint32_t _t)PIN) & ~GPIO_PIN_MASK) == 0x00U))
#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_MODE_INPUT) ||              \
                            ((MODE) == GPIO_MODE_OUTPUT_PP) ||          \
                            ((MODE) == GPIO_MODE_OUTPUT_OD) ||          \
                            ((MODE) == GPIO_MODE_AF_PP) ||              \
                            ((MODE) == GPIO_MODE_AF_OD) ||              \
                            ((MODE) == GPIO_MODE_IT_RISING) ||          \
                            ((MODE) == GPIO_MODE_IT_FALLING) ||         \
                            ((MODE) == GPIO_MODE_IT_RISING_FALLING) ||  \
                            ((MODE) == GPIO_MODE_EVT_RISING) ||         \
                            ((MODE) == GPIO_MODE_EVT_FALLING) ||        \
                            ((MODE) == GPIO_MODE_EVT_RISING_FALLING) || \
                            ((MODE) == GPIO_MODE_ANALOG))
#define IS_GPIO_SPEED(SPEED) (((SPEED) == GPIO_SPEED_FREQ_LOW) || ((SPEED) == GPIO_SPEED_FREQ_MEDIUM) || \
                              ((SPEED) == GPIO_SPEED_FREQ_HIGH) || ((SPEED) == GPIO_SPEED_FREQ_VERY_HIGH))
#define IS_GPIO_PULL(PULL) (((PULL) == GPIO_NOPULL) || ((PULL) == GPIO_PULLUP) || \
                            ((PULL) == GPIO_PULLDOWN))

#endif /* __STM32F4xx_HAL_GPIO_H */
