/*
 * IR_sensor.c
 *
 *  Created on: Apr 3, 2024
 *      Author: Acer
 */


#include "IR_sensor.h"


void IR_sensor_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin = IR_LEFT_PIN | IR_RIGHT_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(IR_GPIO_PORT, &GPIO_InitStruct);
}

uint32_t IR_sensor_GetLeftSensorValue( void)
{

	HAL_GPIO_ReadPin(IR_GPIO_PORT, IR_LEFT_PIN);
}

uint32_t IR_sensor_GetRightSensorValue( void)
{
	HAL_GPIO_ReadPin(IR_GPIO_PORT, IR_RIGHT_PIN);
}
