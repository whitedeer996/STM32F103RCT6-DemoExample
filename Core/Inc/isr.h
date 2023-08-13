#ifndef __ISR_H__
#define __ISR_H__

#include "main.h"

extern uint8_t Motor_Flag10ms;
extern uint8_t MotorPID_Flag50ms;
extern uint8_t left_encoder_pulse_number;
extern uint8_t right_encoder_pulse_number;
extern uint8_t left_encoder_pulse_number_use;
extern uint8_t right_encoder_pulse_number_use;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
#endif 
