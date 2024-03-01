#include "stm32f4xx.h"

#ifndef IR_SENSOR_H_
#define IR_SENSOR_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


#define IR_SENSOR_PIN  GPIO_Pin_7
#define IR_SENSOR_PORT GPIOA
#define IR_SENSOR_RCC  RCC_AHB1Periph_GPIOA


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
uint8_t IR_Sensor_Read(void);

void IR_Sensor_Init(void);

#endif /* IR_SENSOR_H_ */
