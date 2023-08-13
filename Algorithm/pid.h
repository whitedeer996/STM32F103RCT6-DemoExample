#ifndef __PID_H__
#define __PID_H__


typedef struct PID
{ 
  float kp;
  float ki;
  float kd;
  float ek;     //当前误差
  float ek_1;   //上一次误差
  float ek_2;   //上上一次误差
  float limit;  //限幅
}PID;

void PID_Init(void);
float PID_Increase(float Actual,float Target,PID pid);
float PID_Position (float position,float Target,PID pid);
int myabs(int a);


extern PID Encoder_pid;//速度闭环PID
extern PID MPU6050_pid;


#endif 
