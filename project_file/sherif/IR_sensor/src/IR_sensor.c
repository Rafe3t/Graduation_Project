/*
 * IR_sensor.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Acer
 */

#include "IR_sensor.h"

void IR_Sensor_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // Enable the GPIO clock
    RCC_AHB1PeriphClockCmd(IR_SENSOR_RCC, ENABLE);

    // Configure the GPIO pin as input
    GPIO_InitStructure.GPIO_Pin = IR_SENSOR_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    GPIO_Init(IR_SENSOR_PORT, &GPIO_InitStructure);
}

uint8_t IR_Sensor_Read(void)
{
    // Read the digital signal from the IR sensor
    return GPIO_ReadInputDataBit(IR_SENSOR_PORT, IR_SENSOR_PIN);
}
