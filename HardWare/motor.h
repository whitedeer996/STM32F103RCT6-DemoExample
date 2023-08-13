#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "main.h"


extern float PWMA,PWMB,MPU_PWM;


void MotorInit(void);
void Motor_En(void);
void Motor_Stop(void);
void LMotor_TF(void);
void LMotor_TB(void);
void RMotor_TF(void);
void RMotor_TB(void);

#endif 
