/*
 * IR_sensor.h
 *
 *  Created on: Apr 3, 2024
 *      Author: Acer
 */

#ifndef SRC_IR_SENSOR_H_
#define SRC_IR_SENSOR_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#include "main.h"

#define IR_LEFT_PIN GPIO_PIN_11
#define IR_RIGHT_PIN GPIO_PIN_12
#define IR_GPIO_PORT GPIOA

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void IR_sensor_Init(void);


uint32_t IR_sensor_GetLeftSensorValue( void);
uint32_t IR_sensor_GetRightSensorValue( void);



#endif /* SRC_IR_SENSOR_H_ */
