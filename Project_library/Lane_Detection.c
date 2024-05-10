#include"Lane_Detection.h"
#include "DC_motor.h"


extern uint8_t rx_data='0';

extern volatile  uint8_t speed= 100;

extern volatile  uint8_t APP_1= 0;// for lane detection app

void LANE_Detection_APP(void)
{
	if (APP_1 == 1)
	{


		// Read IR sensor states
		ir_left_state = IR_sensor_GetLeftSensorValue();
		ir_right_state = IR_sensor_GetRightSensorValue();

		// Adjust motor control based on sensor readings
		if (ir_left_state == GPIO_PIN_RESET && ir_right_state == GPIO_PIN_RESET)
		{
			// Both sensors detect the line
			DcMotor_Move_MainDirection(forward, 78);
		}
		else if (ir_left_state == GPIO_PIN_RESET)
		{
			// Left sensor detects the line
			DcMotor_Move_MainDirection(left, 50);
		}
		else if (ir_right_state == GPIO_PIN_RESET)
		{
			// Right sensor detects the line
			DcMotor_Move_MainDirection(right, 50);
		}
		else if ((ir_left_state == GPIO_PIN_SET && ir_right_state == GPIO_PIN_SET) )
		{
			// No sensor detects the line
			DcMotor_Move_MainDirection(stop, 0);
		}

		else
		{
			//do nothing
		}

	}
	else if (APP_1 == 0)
	{
		DcMotor_Move_MainDirection(stop, 0);

	}

	else
	{
		//do nothing
	}

	// Add a short delay between iterations
	_delay_ms(3);
}
