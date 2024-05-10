/*
 * Acc.h
 *
 *  Created on: May 2, 2024
 *      Author: helal
 */

#ifndef SRC_ACC_H_
#define SRC_ACC_H_


#include "DC_motor.h"




#define DEFULT_RANGE 20
#define LOWER_RANGE 10
#define HIGHER_RANGE 30
#define stop_range 5

#define high_speed 90
#define DEFULT_speed 60
#define low_speed 40
#define stop_speed 0

enum conditions
{
    intial_condition,
    intial_speed_condition,
    high_speed_condition,
    low_speed_condition,
    stop_condition

};






char Adabtive_Cruise_control(char space );





#endif /* SRC_ACC_H_ */
