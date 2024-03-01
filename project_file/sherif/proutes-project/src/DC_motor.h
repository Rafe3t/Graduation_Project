/*
 * DC-Motor.h
 *
 *  Created on: May 12, 2023
 *      Author: Acer
 */
#include "pwm.h"
#include "delay.h"
#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


typedef enum
{
	 stop,forward, backword,right , left
} DcMotor_MainDirection ;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void DcMotor_Init(void);


void DcMotor_Move_MainDirection(DcMotor_MainDirection state , char speed );



#endif /* DC_MOTOR_H_ */
