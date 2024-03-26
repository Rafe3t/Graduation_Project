
/*=================================================================================*/
/*  File        : main.c                                                           */
/*  Description : This file includes PORT Driver implementations for TM4C123GH6PM  */
/*  Author      : Mohamed Maged Mohamed. Embedded SW Engineer                      */
/*  Date        : 12/5/2023                                                        */
/*  Linkedin    : www.linkedin.com/in/mohamed-elsayed-5636ab289                    */
/*  mail        : mhamedmaged169@gmil.com                                          */
/*  application : Auto_Parking                                                     */
/*  Version     : One                                                              */
/*=================================================================================*/
/*every distance in CM*/

/* Includes */
#include "stm32f4xx.h"
#include "stm32f4xx_i2c.h"
#include "delay.h"
/*global variable*/
I2C_TypeDef *config_i2c; /*pointer to struct type I2C_TypeDef */
char Parking_Flag=0;     /*this flag set when this place fits our car*/
char check_time=0;       /*we will change car position for three times
                          then we made sure that this palce doesnot fit our car  */
/* Private variables */
#define pi                3.14159
//#define lidar_velocity    3.14159  /* the velocity of our lidar pi per sec (ask ref3at) */
#define lidar_time_cycle  2000       /* the time cycle of our lidar (ask ref3at)          */
#define X_AXIS_car        11         /*we should put the width of our car (ask yasser)    */
#define Y_AXIS_car        22         /*we should put the length of our car  (ask yasser)  */
#define MAX_Distance_BY_Lidar       120
/*we should put the MAX_Distance_BY_Lidar of our car  (ask Ref3at)  */
#define tim_every_18_degree           100
#define tim_every_45_degree           250
#define tim_every_90_degree           500
#define tim_every_180_degree          1000

/* Private function prototypes */
void finding_space (void)
 {
	 int y_space;
	 int x_space;
	 int COUNTER=0,temp;

	 y_space= temp = I2C_ReceiveData(config_i2c->DR);
	 while(y_space == temp)
	 {
		 _delay_ms(tim_every_45_degree);/*every 45 degree*/
		 temp = I2C_ReceiveData(config_i2c->DR);
		 counter+=1;
		 if(temp == MAX_Distance_BY_Lidar )
		 {
			break;
		 }
	 }


	 x_space = ((long)((float)(pi*y_space*100)/2000)*(COUNTER*tim_every_45_degree)); /*maged*/

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
	if(check_time == 3)
	{

		/*turn on (LED) Buzzer*/
		_delay_ms(4000);
	}

}
	 }
 }
void Parking_Car (void)
{
	Parking_Flag=0;
	int Front,Right_Side,Left_Side,Back,state;
	Front = 0;
	Right_Side =1,
	Left_Side  =2;
	Back =3;
	state=0;
	/*put car on specific position*/
	while ((Right_Side!= Left_Side) && ( Front!= MAX_Distance_BY_Lidar|| Back != MAX_Distance_BY_Lidar ))
{

		_delay_ms(tim_every_90_degree);
		Front = I2C_ReceiveData(config_i2c->DR);
		if (Front == MAX_Distance_BY_Lidar)
		         {Front=0;}
		_delay_ms(tim_every_90_degree);
		Right_Side = I2C_ReceiveData(config_i2c->DR);
		if (Right_Side == MAX_Distance_BY_Lidar)
				{Right_Side=0;}
		_delay_ms(tim_every_90_degree);
		 Back = I2C_ReceiveData(config_i2c->DR);
		 if (Back == MAX_Distance_BY_Lidar)
		 		{  Back=0;}
		_delay_ms(tim_every_90_degree);
	    Left_Side = I2C_ReceiveData(config_i2c->DR);
	    if (Left_Side == MAX_Distance_BY_Lidar)
	    	{ Left_Side=0;}
	    if ((Front > Right_Side) && (Front > Back) && ( Front> Left_Side ))
	    {
	    	_delay_ms(tim_every_18_degree);
	    	state = I2C_ReceiveData(config_i2c->DR);

	    	while ( state > (Y_AXIS_car+3) )
	    	{
	    	/*move towards Front*/
	    		_delay_ms(tim_every_18_degree);
	    		state = I2C_ReceiveData(config_i2c->DR);
	    	}
	    	/*stop car*/

	    }
	    else if ((Right_Side > Front) && (Right_Side > Back) && ( Right_Side> Left_Side ))
	     {
	    	_delay_ms(tim_every_18_degree);
	    		    	state = I2C_ReceiveData(config_i2c->DR);

	    		    	while ( state > (Y_AXIS_car+3) )
	    		    	{
	    		    	/*move towards Right_Side*/
	    		    		_delay_ms(tim_every_18_degree);
	    		    		state = I2C_ReceiveData(config_i2c->DR);
	    		    	}
	    		    	/*stop car*/

	     }

	    else if ((Left_Side > Right_Side) && (Left_Side > Back) && ( Left_Side > Front ))
	     {
	    	_delay_ms(tim_every_18_degree);
	    		    	state = I2C_ReceiveData(config_i2c->DR);

	    		    	while ( state > (Y_AXIS_car+3) )
	    		    	{
	    		    	/*move towards Left_Side*/
	    		    		_delay_ms(tim_every_18_degree);
	    		    		state = I2C_ReceiveData(config_i2c->DR);
	    		    	}
	    		    	/*stop car*/

	     }
	    else if ((Back > Right_Side) && ( Back > Front) && ( Back> Left_Side ))
	    {
	    	_delay_ms(tim_every_18_degree);
	    		    	state = I2C_ReceiveData(config_i2c->DR);

	    		    	while ( state > (Y_AXIS_car+3) )
	    		    	{
	    		    	/*move towards Back*/
	    		    		_delay_ms(tim_every_18_degree);
	    		    		state = I2C_ReceiveData(config_i2c->DR);
	    		    	}
	    		    	/*stop car*/

	    }
}


}
/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{

  /* Infinite loop */
  while (1)
  {
	  finding_space ();
	  Parking_Car   ();

  }
}
