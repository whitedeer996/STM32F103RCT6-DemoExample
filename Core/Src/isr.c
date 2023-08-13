#include "isr.h"
#include "math.h"
#include "tim.h"
#include "pid.h"
#include "motor.h"
#include "mpu6050.h"

uint8_t Target_Speed = 90;      //目标速度
uint8_t EncoderINT_Count = 0;   //编码器中断计数
uint8_t MPU6050INT_Count = 0;   //dmp解算MPU6050，在中断里计时积分

uint8_t left_encoder_pulse_number= 0;       //外部中断编码器计数
uint8_t right_encoder_pulse_number = 0;     //外部中断编码器计数
uint8_t left_encoder_pulse_number_use= 0;   //外部中断编码器计数
uint8_t right_encoder_pulse_number_use = 0; //外部中断编码器计数



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

		
	if(htim->Instance == TIM7)
	{
		EncoderINT_Count++;
    MPU6050INT_Count++;
		
//		Encoder_pid.kp = 0.5; Encoder_pid.ki = 0.3; Encoder_pid.kd = 0.15;
		
		if(EncoderINT_Count == 50)//50ms
	  {
				EncoderINT_Count=0;		
				HAL_GPIO_TogglePin(TestLED_GPIO_Port,TestLED_Pin);
						
//				left_encoder_pulse_number_use = left_encoder_pulse_number;
//				right_encoder_pulse_number_use = right_encoder_pulse_number;
//				printf("%d,%d \r\n",left_encoder_pulse_number_use,right_encoder_pulse_number_use);
//				left_encoder_pulse_number=0;
//				right_encoder_pulse_number=0;

//				PWMA += PID_Increase(left_encoder_pulse_number_use,60,Encoder_pid);			
//				PWMB += PID_Increase(right_encoder_pulse_number_use,60,Encoder_pid);
//				if(myabs(PWMA) >7199) PWMA =7199;
//				if(myabs(PWMB) >7199) PWMB =7199;			
////				printf("%f\r\n",PWMA);
//				__HAL_TIM_SetCompare (&htim3 ,TIM_CHANNEL_1 ,(uint32_t)PWMA);	
//				__HAL_TIM_SetCompare (&htim3 ,TIM_CHANNEL_2 ,(uint32_t)PWMB);				
		}			
    
		if(MPU6050INT_Count == 2)//2ms
		{
		   MPU6050INT_Count = 0;

//				if((yaw-90) <= 0 )
//				{
//					 RMotor_TF();
//					 LMotor_TB();
//				}else if((yaw-90) > 0)
//				{
//					 LMotor_TF();
//					 RMotor_TF();			
//				}			
//			 if(yaw>=0)
//				{
//						yaw_error[0]=yaw;
//				}
//				if(yaw<0)
//				{
//					 yaw_error[0]=-yaw;
//				}
//				if(yaw_error[1]==0)
//				{
//						yaw_error[1]=yaw_error[0];
//				}
//				yaw_error[2]=yaw_error[2]+fabs(yaw_error[0]-yaw_error[1]);
//				yaw_error[1]=yaw_error[0];			
//				if(yaw_error[2] <= 85)
//				{
//						__HAL_TIM_SetCompare (&htim3 ,TIM_CHANNEL_1 ,(uint32_t)1000);	
//						__HAL_TIM_SetCompare (&htim3 ,TIM_CHANNEL_2 ,(uint32_t)1000);		
//				}
//        else
//				{   
//				    Motor_Stop();
//				}					
//		 

//			if(fabs(yaw-90) >= 1.0)	
//			{		
//					if((yaw-90) <= 0 )
//					{
//						 RMotor_TF();
//						 LMotor_TB();
//					}else if((yaw-90) > 0)
//					{
//						 Motor_Stop();
//						 LMotor_TF();
//						 RMotor_TB();			
//					}				
//					 MPU_PWM = PID_Position(yaw,90.0,MPU6050_pid);
//						__HAL_TIM_SetCompare (&htim3 ,TIM_CHANNEL_1 ,(uint32_t)MPU_PWM);	
//						__HAL_TIM_SetCompare (&htim3 ,TIM_CHANNEL_2 ,(uint32_t)MPU_PWM);
//			}				
		}
		


	}//htim->Instance == TIM7
	
}//TIM_Callback

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == GPIO_PIN_7)
  {
		right_encoder_pulse_number++;
  }
	if (GPIO_Pin == GPIO_PIN_6)
  {
		left_encoder_pulse_number++;
  }
  
//	if(GPIO_Pin == OledINT_Pin)
//	{
//			OledKeyFlag = 1;
//  		HAL_GPIO_TogglePin(TestLed_GPIO_Port,TestLed_Pin); 		
//	}

}//GPIO_EXTI_Callback
