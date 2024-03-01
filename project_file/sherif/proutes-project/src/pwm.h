#include "stm32f4xx.h"
#define PWM_PORT GPIOA
#define PWM_RCC RCC_AHB1Periph_GPIOA

void TIM2_PWM_Init_Pins(void );

void TIM2_PWM_Channel_1_Init(uint8_t dutyCyclePercent);

void TIM2_PWM_Channel_2_Init(uint8_t dutyCyclePercent);
void TIM2_PWM_Channel_3_Init(uint8_t dutyCyclePercent);
void TIM2_PWM_Channel_4_Init(uint8_t dutyCyclePercent);
