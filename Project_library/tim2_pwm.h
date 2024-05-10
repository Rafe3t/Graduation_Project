/*
 * tim2_pwm.h
 *
 *  Created on: Feb 8, 2024
 *      Author: Acer
 */

#ifndef SRC_TIM2_PWM_H_
#define SRC_TIM2_PWM_H_
#include "main.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

void TIM2_PWM_Init(void );

void TIM2_PWM_Channel_1_dutyCycle(uint8_t dutyCyclePercent);
void TIM2_PWM_Channel_2_dutyCycle(uint8_t dutyCyclePercent);
void TIM2_PWM_Channel_3_dutyCycle(uint8_t dutyCyclePercent);
void TIM2_PWM_Channel_4_dutyCycle(uint8_t dutyCyclePercent);

#endif /* SRC_TIM2_PWM_H_ */
