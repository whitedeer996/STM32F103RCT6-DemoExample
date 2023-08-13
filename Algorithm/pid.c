#include "pid.h"

PID Encoder_pid;//�ٶȱջ�PID
PID MPU6050_pid;//MPU6050PID

void PID_Init()
{

		Encoder_pid.kp = 3; Encoder_pid.ki = 0.0; Encoder_pid.kd = 0.0; Encoder_pid.limit = 7200.0;//����ʽ�󳵳��ٶȱջ�����
////	    Encoder_pid.kp = 20; Encoder_pid.ki = 0.9; Encoder_pid.kd = 0.2; Encoder_pid.limit = 7200.0;//λ��ʽС���ٶȱջ����֡���ɰ桿
//    MPU6050_pid.kp = 10; MPU6050_pid.ki = 0.1; MPU6050_pid.kd = 0.3; MPU6050_pid.limit = 7200.0;//λ��ʽ��������PID����
}


float PID_Increase(float Actual,float Target,PID pid)
{
    static float pwm = 0;
    Encoder_pid.ek = Target - Actual; // ���㵱ǰ���Kp[e��k��-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
    pwm = pid.kp*(pid.ek - pid.ek_1)+ pid.ki*pid.ek + pid.kd*(pid.ek - 2*pid.ek_1 + pid.ek_2);   //����ʽpid������
 
  	pid.ek_2 = pid.ek_1; //��������һ�ε�ƫ��
	  pid.ek_1 = pid.ek;   //������һ��ƫ��    
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
     Encoder_pid.ek = Target - position; // ���㵱ǰ���Kp[e��k��-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
     Bias=Target-position;                                  //����ƫ��
     Integral_bias+=Bias;                                   //���ƫ��Ļ���
     Pwm=pid.kp*Bias+pid.ki*Integral_bias+pid.kd*(Bias-Last_Bias);       //λ��ʽPID������
     Last_Bias=Bias;                                       //������һ��ƫ�� 
     return Pwm;                                           //�������
}


/**************************************************************************
�������ܣ�����ֵ����
��ڲ�����int
����  ֵ��unsigned int
**************************************************************************/
int myabs(int a)
{ 		   
	  int temp;
		if(a<0)  temp=-a;  
	  else temp=a;
	  return temp;
}


