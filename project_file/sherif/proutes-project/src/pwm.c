
#include "pwm.h"

void TIM2_PWM_Channel_1_Init(uint8_t dutyCyclePercent) {
    // Ensure dutyCyclePercent is within bounds
    dutyCyclePercent = (dutyCyclePercent > 100) ? 100 : dutyCyclePercent;

    // Convert duty cycle percentage to pulse width value
    uint16_t pulseWidth = (dutyCyclePercent * 200) - 1; // Scale to a 0-20000 range


    // Initialize the TIM2 structure
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure = {
        .TIM_Period = 19999,                  // Set the PWM period for 50 Hz
        .TIM_Prescaler = 83,                  // Adjusted for a 1 MHz clock
        .TIM_ClockDivision = 0,               // No clock division
        .TIM_CounterMode = TIM_CounterMode_Up // Upcounting mode
    };
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    // Configure the PWM mode
    TIM_OCInitTypeDef TIM_OCInitStructure = {
        .TIM_OCMode = TIM_OCMode_PWM1,
        .TIM_OutputState = TIM_OutputState_Enable,
        .TIM_Pulse = pulseWidth,             // Set the pulse width
        .TIM_OCPolarity = TIM_OCPolarity_High
    };
    TIM_OC1Init(TIM2, &TIM_OCInitStructure);

    // Enable the TIM2 counter
    TIM_Cmd(TIM2, ENABLE);

    // Enable the TIM2 main output
    TIM_CtrlPWMOutputs(TIM2, ENABLE);
}
void TIM2_PWM_Channel_2_Init(uint8_t dutyCyclePercent) {
    // Ensure dutyCyclePercent is within bounds
    dutyCyclePercent = (dutyCyclePercent > 100) ? 100 : dutyCyclePercent;

    // Convert duty cycle percentage to pulse width value
    uint16_t pulseWidth = (dutyCyclePercent * 200) - 1; // Scale to a 0-20000 range


    // Initialize the TIM2 structure
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure = {
        .TIM_Period = 19999,                  // Set the PWM period for 50 Hz
        .TIM_Prescaler = 83,                  // Adjusted for a 1 MHz clock
        .TIM_ClockDivision = 0,               // No clock division
        .TIM_CounterMode = TIM_CounterMode_Up // Upcounting mode
    };
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    // Configure Channel 2 in PWM mode
    TIM_OCInitTypeDef TIM_OCInitStructure_CH2 = {
        .TIM_OCMode = TIM_OCMode_PWM1,
        .TIM_OutputState = TIM_OutputState_Enable,
        .TIM_Pulse = pulseWidth,             // Set the pulse width
        .TIM_OCPolarity = TIM_OCPolarity_High
    };
    TIM_OC2Init(TIM2, &TIM_OCInitStructure_CH2);

    // Enable the TIM2 counter
    TIM_Cmd(TIM2, ENABLE);

    // Enable the TIM2 main output
    TIM_CtrlPWMOutputs(TIM2, ENABLE);
}

void TIM2_PWM_Channel_3_Init(uint8_t dutyCyclePercent) {
    // Ensure dutyCyclePercent is within bounds
    dutyCyclePercent = (dutyCyclePercent > 100) ? 100 : dutyCyclePercent;

    // Convert duty cycle percentage to pulse width value
    uint16_t pulseWidth = (dutyCyclePercent * 200) - 1; // Scale to a 0-20000 range

    // Initialize the TIM2 structure
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure = {
        .TIM_Period = 19999,                  // Set the PWM period for 50 Hz
        .TIM_Prescaler = 83,                  // Adjusted for a 1 MHz clock
        .TIM_ClockDivision = 0,               // No clock division
        .TIM_CounterMode = TIM_CounterMode_Up // Upcounting mode
    };
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    // Configure Channel 3 in PWM mode
    TIM_OCInitTypeDef TIM_OCInitStructure_CH3 = {
        .TIM_OCMode = TIM_OCMode_PWM1,
        .TIM_OutputState = TIM_OutputState_Enable,
        .TIM_Pulse = pulseWidth,             // Set the pulse width
        .TIM_OCPolarity = TIM_OCPolarity_High
    };
    TIM_OC3Init(TIM2, &TIM_OCInitStructure_CH3);

    // Enable the TIM2 counter
    TIM_Cmd(TIM2, ENABLE);

    // Enable the TIM2 main output
    TIM_CtrlPWMOutputs(TIM2, ENABLE);
}

void TIM2_PWM_Channel_4_Init(uint8_t dutyCyclePercent) {
    // Ensure dutyCyclePercent is within bounds
    dutyCyclePercent = (dutyCyclePercent > 100) ? 100 : dutyCyclePercent;

    // Convert duty cycle percentage to pulse width value
    uint16_t pulseWidth = (dutyCyclePercent * 200) - 1; // Scale to a 0-20000 range


    // Initialize the TIM2 structure
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure = {
        .TIM_Period = 19999,                  // Set the PWM period for 50 Hz
        .TIM_Prescaler = 83,                  // Adjusted for a 1 MHz clock
        .TIM_ClockDivision = 0,               // No clock division
        .TIM_CounterMode = TIM_CounterMode_Up // Upcounting mode
    };
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    // Configure Channel 4 in PWM mode
    TIM_OCInitTypeDef TIM_OCInitStructure_CH4 = {
        .TIM_OCMode = TIM_OCMode_PWM1,
        .TIM_OutputState = TIM_OutputState_Enable,
        .TIM_Pulse = pulseWidth,             // Set the pulse width
        .TIM_OCPolarity = TIM_OCPolarity_High
    };
    TIM_OC4Init(TIM2, &TIM_OCInitStructure_CH4);

    // Enable the TIM2 counter
    TIM_Cmd(TIM2, ENABLE);

    // Enable the TIM2 main output
    TIM_CtrlPWMOutputs(TIM2, ENABLE);
}

void TIM2_PWM_Init_Pins(void )
{
	// Enable the TIM2 peripheral clock
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

		// Enable the PWM_PORT peripheral clock
		RCC_AHB1PeriphClockCmd(PWM_RCC, ENABLE);

		// Configure PA0 (TIM2_CH1),PA1 (TIM2_CH2), PA2 (TIM2_CH3), and PA3 (TIM2_CH4) as alternate function push-pull
		GPIO_InitTypeDef GPIO_InitStructure = {
				.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3,
				.GPIO_Mode = GPIO_Mode_AF,
				.GPIO_Speed = GPIO_Speed_100MHz,
				.GPIO_OType = GPIO_OType_PP,
				.GPIO_PuPd = GPIO_PuPd_NOPULL
		};
		GPIO_Init(PWM_PORT, &GPIO_InitStructure);

		// Connect TIM2 CH1,TIM2 CH2, CH3, and CH4 pins to AF
		GPIO_PinAFConfig(PWM_PORT, GPIO_PinSource0, GPIO_AF_TIM2);
		GPIO_PinAFConfig(PWM_PORT, GPIO_PinSource1, GPIO_AF_TIM2);
		GPIO_PinAFConfig(PWM_PORT, GPIO_PinSource2, GPIO_AF_TIM2);
		GPIO_PinAFConfig(PWM_PORT, GPIO_PinSource3, GPIO_AF_TIM2);
}




