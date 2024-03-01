#include "IR_sensor.h"

#include "led.h"

int main(void) {

	SystemInit();

	LED_Init();
	IR_Sensor_Init();
	uint8_t sensorValue;
	while (1)
	{
		// Read the value from the IR sensor
		sensorValue = IR_Sensor_Read();


		if (sensorValue == SET)
		{
			// IR sensor detected an object
			LED_On();
		}
		else
		{
			// No object detected
			LED_Off();
		}
	}
}
