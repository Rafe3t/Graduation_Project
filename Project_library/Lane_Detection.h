#ifndef LANE_DETECTION_H_
#define LANE_DETECTION_H_
#include "main.h"


extern uint8_t rx_data;

extern volatile  uint8_t speed;

extern volatile  uint8_t APP_1;// for lane detection app


extern volatile uint32_t ir_right_state;
extern volatile uint32_t ir_left_state;


void LANE_Detection_APP(void);

#endif
