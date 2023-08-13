#ifndef _MPU6050IIC_H
#define _MPU6050IIC_H

#include <inttypes.h>

#define IIC_WR	0		/* Ð´¿ØÖÆbit */
#define IIC_RD	1		/* ¶Á¿ØÖÆbit */

void MPU6050IIC_Start(void);
void MPU6050IIC_Stop(void);
void MPU6050IIC_Send_Byte(uint8_t _ucByte);
uint8_t MPU6050IIC_Read_Byte(uint8_t ack);
uint8_t MPU6050IIC_Wait_Ack(void);
void MPU6050IIC_Ack(void);
void MPU6050IIC_NAck(void);
uint8_t MPU6050IIC_CheckDevice(uint8_t _Address);
void MPU6050IIC_GPIO_Init(void);

#endif
