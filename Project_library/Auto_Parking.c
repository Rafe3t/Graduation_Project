#include "Auto_Parking.h"
#include "_delay.h"
#include "DC_motor.h"
#include "SPI_V1.h"
#include "main.h"


char Parking_Flag=0;     /*this flag set when this place fits our car*/
char check_time;       /*we will change car position for three times*/

void finding_space (void)
{
	uint8_t  y_space;
	uint8_t x_space;
	uint8_t COUNTER=0;
	uint8_t temp;



	y_space= temp = SPI_Receive_V1(); /*Check code arduino*/

	x_space= SPI_Receive_V1();
	while(y_space == temp)
	{
		_delay_ms(tim_every_45_degree);/*every 45 degree*/

		temp = SPI_Receive_V1();
		x_space= SPI_Receive_V1();
		COUNTER+=1;
		if(temp == MAX_Distance_BY_Lidar )
		{
			break;
		}
		else
		{
			y_space= temp;
		}
	}

	while(check_time < 3 )
	{
		if(x_space > X_AXIS_car && y_space > Y_AXIS_car )
		{

			Parking_Flag=1;
			check_time=3;
		}
		else
		{
			check_time++;
			/*Change the car's position*/
			y_space = SPI_Receive_V1();
			x_space = SPI_Receive_V1();

			if(check_time == 3)
			{

				/*turn on (LED) Buzzer*/
				_delay_ms(4000);
			}

		}
	}
}

void Parking_Car(void)
{

	uint8_t Front,Right_Side,Left_Side,Back,state;
	Front = 0;
	Right_Side =1,
	Left_Side  =2;
	Back =3;
	state=0;
	/*put car on specific position*/
	while ((Right_Side!= Left_Side) && ( Front!= MAX_Distance_BY_Lidar|| Back != MAX_Distance_BY_Lidar ))
	{
		_delay_ms(tim_every_90_degree);

		Front = SPI_Receive_V1();
		if (Front == MAX_Distance_BY_Lidar)
		{Front=0;}
		_delay_ms(tim_every_90_degree);

		Right_Side = SPI_Receive_V1();
		if (Right_Side == MAX_Distance_BY_Lidar)
		{Right_Side=0;}
		_delay_ms(tim_every_90_degree);

		Back = SPI_Receive_V1();
		if (Back == MAX_Distance_BY_Lidar)
		{  Back=0;}
		_delay_ms(tim_every_90_degree);

		Left_Side = SPI_Receive_V1();
		if (Left_Side == MAX_Distance_BY_Lidar)
		{ Left_Side=0;}
		if ((Front > Right_Side) && (Front > Back) && ( Front> Left_Side ))
		{
			_delay_ms(tim_every_18_degree);

			state = SPI_Receive_V1();

			while ( state > (Y_AXIS_car+3) )
			{
				/*move towards Front*/
				DcMotor_Move_MainDirection(forward, 50);
				_delay_ms(tim_every_18_degree);

				state = SPI_Receive_V1();
			}
			/*stop car*/
			DcMotor_Move_MainDirection(stop, 0);
		}
		else if ((Right_Side > Front) && (Right_Side > Back) && ( Right_Side> Left_Side ))
		{
			_delay_ms(tim_every_18_degree);

			state = SPI_Receive_V1();

			while ( state > (Y_AXIS_car+3) )
			{
				/*move towards Right_Side*/
				DcMotor_Move_MainDirection(right, 50);
				_delay_ms(tim_every_18_degree);

				state = SPI_Receive_V1();
			}
			/*stop car*/
			DcMotor_Move_MainDirection(stop, 0);
		}

		else if ((Left_Side > Right_Side) && (Left_Side > Back) && ( Left_Side > Front ))
		{
			_delay_ms(tim_every_18_degree);

			state = SPI_Receive_V1();

			while ( state > (Y_AXIS_car+3) )
			{
				/*move towards Left_Side*/
				DcMotor_Move_MainDirection(left, 50);
				_delay_ms(tim_every_18_degree);

				state = SPI_Receive_V1();
			}
			/*stop car*/
			DcMotor_Move_MainDirection(stop, 0);

		}
		else if ((Back > Right_Side) && ( Back > Front) && ( Back> Left_Side ))
		{
			_delay_ms(tim_every_18_degree);

			state = SPI_Receive_V1();
			while ( state > (Y_AXIS_car+3) )
			{
				/*move towards Back*/
				DcMotor_Move_MainDirection(backword, 50);
				_delay_ms(tim_every_18_degree);

				state = SPI_Receive_V1();
			}
			/*stop car*/
			DcMotor_Move_MainDirection(stop, 0);
		}
	}
}

