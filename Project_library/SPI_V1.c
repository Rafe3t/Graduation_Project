#include "SPI_V1.h"
#include "main.h"

SPI_HandleTypeDef hspi2;


extern uint8_t SPI_Receive_V1(void)
{
  uint8_t rx_data;
  HAL_SPI_Receive(&hspi2, &rx_data, 1, 1000);
  return rx_data;
}
