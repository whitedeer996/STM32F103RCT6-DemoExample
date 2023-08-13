/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MPU6050_CLK_Pin GPIO_PIN_13
#define MPU6050_CLK_GPIO_Port GPIOC
#define MotorEn_Pin GPIO_PIN_1
#define MotorEn_GPIO_Port GPIOC
#define TestKey_Pin GPIO_PIN_0
#define TestKey_GPIO_Port GPIOA
#define OledINT_Pin GPIO_PIN_4
#define OledINT_GPIO_Port GPIOC
#define OledINT_EXTI_IRQn EXTI4_IRQn
#define Bin2_Pin GPIO_PIN_5
#define Bin2_GPIO_Port GPIOC
#define MPU6050_SDA_Pin GPIO_PIN_12
#define MPU6050_SDA_GPIO_Port GPIOB
#define Ain2_Pin GPIO_PIN_9
#define Ain2_GPIO_Port GPIOC
#define Bin1_Pin GPIO_PIN_8
#define Bin1_GPIO_Port GPIOA
#define Ain1_Pin GPIO_PIN_15
#define Ain1_GPIO_Port GPIOA
#define TestLED_Pin GPIO_PIN_2
#define TestLED_GPIO_Port GPIOD
#define PWMA_Pin GPIO_PIN_4
#define PWMA_GPIO_Port GPIOB
#define PWMB_Pin GPIO_PIN_5
#define PWMB_GPIO_Port GPIOB
#define OledClk_Pin GPIO_PIN_8
#define OledClk_GPIO_Port GPIOB
#define OledData_Pin GPIO_PIN_9
#define OledData_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
