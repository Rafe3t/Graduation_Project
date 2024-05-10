/*
 * Acc.c
 *
 *  Created on: May 2, 2024
 *      Author: helal
 */


#include "Acc.h"

char space = DEFULT_RANGE;
char speed ;
enum conditions motor_condition = intial_condition;

char first_time_activate = 0;

char Adabtive_Cruise_control(char space )
{

   while(first_time_activate == 0)
   	   {
	   	   //DcMotor_Move_MainDirection(forward , DEFULT_speed);
	   	   	   speed=DEFULT_speed;
	   	   first_time_activate=1;
   	   	}


        if (space == DEFULT_RANGE)
        {
            if (motor_condition != intial_speed_condition)
            {
            	//DcMotor_Move_MainDirection(forward , DEFULT_speed);
 	   	   	   speed=DEFULT_speed;
                motor_condition = intial_speed_condition;
            }
        }
        else if (space == LOWER_RANGE)
        {
            if (motor_condition != low_speed_condition)
            {
            	//DcMotor_Move_MainDirection(forward , low_speed);
 	   	   	   speed=low_speed;

                motor_condition = low_speed_condition;
            }
        }
        else if (space == HIGHER_RANGE)
        {
            if (motor_condition != stop_condition)
            {
            	//DcMotor_Move_MainDirection(forward , high_speed);
 	   	   	   speed=high_speed;

                motor_condition = high_speed_condition;
            }
        }
        else if (space == stop_range)
        {
            if (motor_condition != high_speed_condition)
            {
            	//DcMotor_Move_MainDirection(stop ,DEFULT_speed );
            	speed=stop_speed;
                motor_condition = stop_condition;
            }
        }

        return speed;
}
