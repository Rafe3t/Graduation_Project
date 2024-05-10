/*
 * DC_motor.c
 *
 *  Created on: Feb 8, 2024
 *      Author: Acer
 */
#include "DC_motor.h"
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
static void DcMotor_stop(void );
static void DcMotor_Forward(char speed);
static void DcMotor_Backward(char speed);
static void DcMotor_right(char speed);
static void DcMotor_left(char speed);

void DcMotor_Init(void)
{
	TIM2_PWM_Init();
}

void DcMotor_Move_MainDirection(DcMotor_MainDirection state , char speed )
{
	switch(state)
	{
	case stop:
		DcMotor_stop( );
		break;
	case forward:
		DcMotor_Forward( speed);
		break;
	case backword :
		DcMotor_Backward( speed);
		break;
	case right :

		DcMotor_right( speed);
		break ;
	case left:
		DcMotor_left( speed);
		break;
	default:
		break;
	}

}
static void DcMotor_stop(void )
{
	TIM2_PWM_Channel_1_dutyCycle(0);
	TIM2_PWM_Channel_2_dutyCycle(0);
	TIM2_PWM_Channel_3_dutyCycle(0);
	TIM2_PWM_Channel_4_dutyCycle(0);
}
static void DcMotor_Forward(char speed)
{
	TIM2_PWM_Channel_1_dutyCycle(speed);
	TIM2_PWM_Channel_2_dutyCycle(0);
	TIM2_PWM_Channel_3_dutyCycle(speed);
	TIM2_PWM_Channel_4_dutyCycle(0);
}

static void DcMotor_Backward(char speed)
{
	TIM2_PWM_Channel_1_dutyCycle(0);
	TIM2_PWM_Channel_2_dutyCycle(speed);
	TIM2_PWM_Channel_3_dutyCycle(0);
	TIM2_PWM_Channel_4_dutyCycle(speed);
}

static void DcMotor_right(char speed)
{
	TIM2_PWM_Channel_1_dutyCycle(0);
	TIM2_PWM_Channel_2_dutyCycle(speed);
	TIM2_PWM_Channel_3_dutyCycle(speed);
	TIM2_PWM_Channel_4_dutyCycle(0);

}
static void DcMotor_left(char speed)
{
	TIM2_PWM_Channel_1_dutyCycle(speed);
	TIM2_PWM_Channel_2_dutyCycle(0);
	TIM2_PWM_Channel_3_dutyCycle(0);
	TIM2_PWM_Channel_4_dutyCycle(speed);

}
