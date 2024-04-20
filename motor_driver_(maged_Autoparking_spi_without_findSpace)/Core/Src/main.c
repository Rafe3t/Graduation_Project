#include "main.h"
#include "_delay.h"
#include "DC_motor.h"
#include "IR_sensor.h"
/*********************************SPI Config******************************************/
SPI_HandleTypeDef hspi2;

static void MX_GPIO_Init(void);
static void MX_SPI2_Init(void);
uint8_t spi_8_TX[2]= {1,3};
uint8_t spi_8_RX[2]= {12,10};
uint8_t  SPI_Counter= 0;
uint8_t i;
/************************************************************************************/
/*****************************************spi Function*******************************/
void SpiReceiveMAGED(void);

/********************************************************************************/
/*=================================================================================*/
/*  File        : main.c                                                           */
/*  Description : This file includes PORT Driver implementations for TM4C123GH6PM  */
/*  Author      : Mohamed Maged Mohamed. Embedded SW Engineer                      */
/*  Date        : 19/4/2024                                                        */
/*  Linkedin    : www.linkedin.com/in/mohamed-elsayed-5636ab289                    */
/*  mail        : mhamedmaged169@gmil.com                                          */
/*  application : Auto_Parking                                                     */
/*  Version     : Two                                                              */
/*=================================================================================*/
/*every distance in CM*/
/***********************************Auto_Parking_(Maged)************************************************************/
/*
 * Global variable
 */
char Parking_Flag=0;     /*this flag set when this place fits our car*/
char check_time=0;       /*we will change car position for three times
                          then we made sure that this palce doesnot fit our car  */
#define lidar_time_cycle  1500       /* the time cycle of our lidar (ask ref3at)          */
#define X_AXIS_car        11         /*we should put the width of our car (ask yasser)    */
#define Y_AXIS_car        22         /*we should put the length of our car  (ask yasser)  */
#define MAX_Distance_BY_Lidar        120       /*in CM */
#define tim_for_spi_Receive                 30    /*in ms*/

#define tim_every_22_5_degree                 94   /*in ms*/
#define tim_every_45_degree                   188   /*in ms*/
#define tim_every_90_degree                   375   /*in ms*/
#define tim_every_180_degree                  750   /*in ms*/
#define tim_every_270_degree                  1125   /*in ms*/

/*
 * function prototypes
 */
void finding_space (void);
void Parking_Car (void);
/********************************************************************************************/

/******************************************************************************************/
void SystemClock_Config(void);
static void MX_USART1_UART_Init(void);

void LANE_Detection_APP(void);

UART_HandleTypeDef huart1;

uint8_t rx_data='0';


static volatile  uint8_t speed = 100;

static volatile  uint8_t APP_1 = 0;// for lane detection app


static volatile uint32_t ir_right_state;
static volatile uint32_t ir_left_state;


int main(void)
{

/************************************initialization***********************************************/
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
    MX_SPI2_Init();
/**************************************************************************************************/
	IR_sensor_Init();
	MX_USART1_UART_Init();
	DcMotor_Init();

	_delay_ms(1000);



	HAL_UART_Receive_IT(&huart1, &rx_data, 1);





	while (1)
	{
		SpiReceiveMAGED();
		LANE_Detection_APP();




	}
}

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);// led is off

  /*Configure GPIO pin : PB0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}


static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_SLAVE;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_HARD_INPUT;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */












void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Configure the main internal regulator output voltage
	 */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	{
		Error_Handler();
	}
}
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */



static void MX_USART1_UART_Init(void)
{

	/* USER CODE BEGIN USART1_Init 0 */

	/* USER CODE END USART1_Init 0 */

	/* USER CODE BEGIN USART1_Init 1 */

	/* USER CODE END USART1_Init 1 */
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 9600;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart1) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN USART1_Init 2 */

	/* USER CODE END USART1_Init 2 */

}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance==USART1)
	{
		if(rx_data== 'f')
		{


			DcMotor_Move_MainDirection(forward, speed);

		}
		else if(rx_data== 'b')
		{

			DcMotor_Move_MainDirection(backword, speed);

		}
		else if(rx_data== 'r')
		{

			DcMotor_Move_MainDirection(right, speed);

		}
		else if(rx_data== 'l')
		{

			DcMotor_Move_MainDirection(left, speed);

		}
		else if (rx_data== 's')
		{
			DcMotor_Move_MainDirection(stop, 0);

		}
		else if (rx_data== '1')
		{
			DcMotor_Move_MainDirection(stop, 0);
			speed= 50;

		}
		else if (rx_data== '2')
		{
			DcMotor_Move_MainDirection(stop, 0);
			speed= 75 ;

		}
		else if (rx_data== '3')
		{
			DcMotor_Move_MainDirection(stop, 0);
			speed= 100;

		}

		else if(rx_data== 'A')
		{
			APP_1 ^=(1<<0);

		}
		else
		{
			//do nothing
		}

		HAL_UART_Receive_IT(&huart1,&rx_data,1);

	}


}
void SpiReceiveMAGED(void)
{
	 /* USER CODE END WHILE */
		  while( (HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12))  == 0 )
		  	{
		  		  HAL_SPI_Receive(&hspi2, &spi_8_RX[SPI_Counter], 1, 500);
		  		  SPI_Counter++;
		  	}
		  	 SPI_Counter=0;
		  	/* return spi_8_RX[x];*/
}
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
void finding_space (void)
 {
	 int y_space;
	 int x_space;
	 int COUNTER=0,temp;

	 SpiReceiveMAGED();

	 y_space= temp = spi_8_RX[0]; /*Check code arduino*/
	 x_space= spi_8_RX[1];
	 while(y_space == temp)
	 {
		 _delay_ms(tim_every_45_degree);/*every 45 degree*/
		 SpiReceiveMAGED();
		 temp = spi_8_RX[0];
		 x_space= spi_8_RX[1];
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
	SpiReceiveMAGED();
	y_space = spi_8_RX[0];
	x_space = spi_8_RX[1];

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
		    SpiReceiveMAGED();
		Front = spi_8_RX[0];
		if (Front == MAX_Distance_BY_Lidar)
		         {Front=0;}
		_delay_ms(tim_every_90_degree);
	      	SpiReceiveMAGED();
		Right_Side = spi_8_RX[0];
		if (Right_Side == MAX_Distance_BY_Lidar)
				{Right_Side=0;}
		_delay_ms(tim_every_90_degree);
		  SpiReceiveMAGED();
		  Back = spi_8_RX[0];
		 if (Back == MAX_Distance_BY_Lidar)
		 		{  Back=0;}
		_delay_ms(tim_every_90_degree);
		     SpiReceiveMAGED();
	    Left_Side = spi_8_RX[0];
	    if (Left_Side == MAX_Distance_BY_Lidar)
	    	{ Left_Side=0;}
	    if ((Front > Right_Side) && (Front > Back) && ( Front> Left_Side ))
	    {
	    	_delay_ms(tim_every_22_5_degree);
	    	SpiReceiveMAGED();
	    	state = spi_8_RX[0];

	    	while ( state > (Y_AXIS_car+3) )
	    	{
	    	/*move towards Front*/
	    		DcMotor_Move_MainDirection(forward, 50);
	    		_delay_ms(tim_every_22_5_degree);
	    		SpiReceiveMAGED();
	    		state = spi_8_RX[0];
	    	}
	    	/*stop car*/
	    	DcMotor_Move_MainDirection(stop, 0);
	    }
	    else if ((Right_Side > Front) && (Right_Side > Back) && ( Right_Side> Left_Side ))
	     {
	    	_delay_ms(tim_every_22_5_degree);
	    		   SpiReceiveMAGED();
	    		   state = spi_8_RX[0];

	    		    	while ( state > (Y_AXIS_car+3) )
	    		    	{
	    		    	/*move towards Right_Side*/
	    		    		DcMotor_Move_MainDirection(right, 50);
	    		    		_delay_ms(tim_every_22_5_degree);
	    		    			SpiReceiveMAGED();
	    		    			state = spi_8_RX[0];
	    		    	}
	    		    	/*stop car*/
              DcMotor_Move_MainDirection(stop, 0);
	     }

	    else if ((Left_Side > Right_Side) && (Left_Side > Back) && ( Left_Side > Front ))
	     {
	    	_delay_ms(tim_every_22_5_degree);
	    		    		SpiReceiveMAGED();
	    		    		state = spi_8_RX[0];

	    		    	while ( state > (Y_AXIS_car+3) )
	    		    	{
	    		    	/*move towards Left_Side*/
	    		   DcMotor_Move_MainDirection(left, 50);
	    		   _delay_ms(tim_every_22_5_degree);
	    		    	    SpiReceiveMAGED();
	    		    	    state = spi_8_RX[0];
	    		    	}
	    		    	/*stop car*/
	    		    	DcMotor_Move_MainDirection(stop, 0);

	     }
	    else if ((Back > Right_Side) && ( Back > Front) && ( Back> Left_Side ))
	    {
	    	_delay_ms(tim_every_22_5_degree);
	    		SpiReceiveMAGED();
	    		 state = spi_8_RX[0];
	    		    	while ( state > (Y_AXIS_car+3) )
	    		    	{
	    		    	/*move towards Back*/
	    		    	DcMotor_Move_MainDirection(backword, 50);
	    		    	_delay_ms(tim_every_22_5_degree);
	    		    		SpiReceiveMAGED();
	    		    		state = spi_8_RX[0];
	    		    	}
	    		    	/*stop car*/
	    		    	DcMotor_Move_MainDirection(stop, 0);
	    }
}
}



