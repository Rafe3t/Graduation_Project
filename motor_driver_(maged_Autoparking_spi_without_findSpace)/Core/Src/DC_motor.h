/*
 * DC_motor.h
 *
 *  Created on: Feb 8, 2024
 *      Author: Acer
 */

#ifndef SRC_DC_MOTOR_H_
#define SRC_DC_MOTOR_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#include "main.h"

#include "tim2_pwm.h"
typedef enum
{
	 stop,forward, backword,right , left
} DcMotor_MainDirection ;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void DcMotor_Init(void);


void DcMotor_Move_MainDirection(DcMotor_MainDirection state , char speed );


#endif /* SRC_DC_MOTOR_H_ */
