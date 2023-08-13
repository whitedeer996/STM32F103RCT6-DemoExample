#ifndef __PID_H__
#define __PID_H__


typedef struct PID
{ 
  float kp;
  float ki;
  float kd;
  float ek;     //��ǰ���
  float ek_1;   //��һ�����
  float ek_2;   //����һ�����
  float limit;  //�޷�
}PID;

void PID_Init(void);
float PID_Increase(float Actual,float Target,PID pid);
float PID_Position (float position,float Target,PID pid);
int myabs(int a);


extern PID Encoder_pid;//�ٶȱջ�PID
extern PID MPU6050_pid;


#endif 
