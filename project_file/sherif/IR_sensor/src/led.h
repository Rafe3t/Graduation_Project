

#include "stm32f4xx.h"
#ifndef LED_H_
#define LED_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LED_PIN  GPIO_Pin_5
#define LED_PORT GPIOA
#define LED_RCC  RCC_AHB1Periph_GPIOA
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void LED_Init(void);
void LED_On(void);
void LED_Off(void);

#endif /* LED_H_ */
