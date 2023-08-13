#include "pid.h"

PID Encoder_pid;//速度闭环PID
PID MPU6050_pid;//MPU6050PID

void PID_Init()
{

		Encoder_pid.kp = 3; Encoder_pid.ki = 0.0; Encoder_pid.kd = 0.0; Encoder_pid.limit = 7200.0;//增量式大车车速度闭环三轮
////	    Encoder_pid.kp = 20; Encoder_pid.ki = 0.9; Encoder_pid.kd = 0.2; Encoder_pid.limit = 7200.0;//位置式小车速度闭环三轮【完成版】
//    MPU6050_pid.kp = 10; MPU6050_pid.ki = 0.1; MPU6050_pid.kd = 0.3; MPU6050_pid.limit = 7200.0;//位置式大车陀螺仪PID三轮
}


float PID_Increase(float Actual,float Target,PID pid)
{
    static float pwm = 0;
    Encoder_pid.ek = Target - Actual; // 计算当前误差Kp[e（k）-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
    pwm = pid.kp*(pid.ek - pid.ek_1)+ pid.ki*pid.ek + pid.kd*(pid.ek - 2*pid.ek_1 + pid.ek_2);   //增量式pid控制器
 
  	pid.ek_2 = pid.ek_1; //保存上上一次的偏差
	  pid.ek_1 = pid.ek;   //保存上一次偏差    
    if(pwm > pid.limit)
    {
      pwm =  pid.limit;
    }
    else if(pwm < -pid.limit)
    {
      pwm =  -pid.limit;
    }
    return pwm;
}


float PID_Position (float position,float Target,PID pid)
{     
     static float Bias,Integral_bias,Last_Bias,Pwm;	
     Encoder_pid.ek = Target - position; // 计算当前误差Kp[e（k）-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
     Bias=Target-position;                                  //计算偏差
     Integral_bias+=Bias;                                   //求出偏差的积分
     Pwm=pid.kp*Bias+pid.ki*Integral_bias+pid.kd*(Bias-Last_Bias);       //位置式PID控制器
     Last_Bias=Bias;                                       //保存上一次偏差 
     return Pwm;                                           //增量输出
}


/**************************************************************************
函数功能：绝对值函数
入口参数：int
返回  值：unsigned int
**************************************************************************/
int myabs(int a)
{ 		   
	  int temp;
		if(a<0)  temp=-a;  
	  else temp=a;
	  return temp;
}


