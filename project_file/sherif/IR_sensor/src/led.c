
#include "led.h"

void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // Enable the GPIO clock
    RCC_AHB1PeriphClockCmd(LED_RCC, ENABLE);

    // Configure the GPIO pin as output
    GPIO_InitStructure.GPIO_Pin = LED_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(LED_PORT, &GPIO_InitStructure);
}


void LED_On(void)
{
    // Turn on the LED
    GPIO_SetBits(LED_PORT, LED_PIN);
}

void LED_Off(void)
{
    // Turn off the LED
    GPIO_ResetBits(LED_PORT, LED_PIN);
}


