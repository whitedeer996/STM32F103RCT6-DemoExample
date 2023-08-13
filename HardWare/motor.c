#include "motor.h"


float PWMA=0,PWMB=0,MPU_PWM=0;






/*电机初始化，TB6612使能，同时规定了俩个轮子同时前转*/
void MotorInit(void)
{  
   Motor_En();
	 LMotor_TF(); 
	 RMotor_TF();
//	LMotor_TB();
//	RMotor_TB();
}

/*TB6612使能*/
void Motor_En(void)
{
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);	
}


/*TB6612失能*/
void Motor_Stop(void)
{
   HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
}

/*左电机正转*/
void LMotor_TF(void)
{
   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,GPIO_PIN_RESET);
   HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);
}

/*左电机反转*/
void LMotor_TB(void)
{
   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,GPIO_PIN_SET);
   HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_RESET);
}

/*右电机正转*/
void RMotor_TF(void)
{
   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
   HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_SET);
}

/*右电机反转*/
void RMotor_TB(void)
{
   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
   HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_RESET);
}
