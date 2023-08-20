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
#include "stm32g0xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CH1DataDetect_Pin GPIO_PIN_0
#define CH1DataDetect_GPIO_Port GPIOA
#define CH2DataDetect_Pin GPIO_PIN_1
#define CH2DataDetect_GPIO_Port GPIOA
#define CH3DataDetect_Pin GPIO_PIN_2
#define CH3DataDetect_GPIO_Port GPIOA
#define CH3RXEnable_Pin GPIO_PIN_4
#define CH3RXEnable_GPIO_Port GPIOA
#define CH3TXEnable_Pin GPIO_PIN_5
#define CH3TXEnable_GPIO_Port GPIOA
#define CH2RXEnable_Pin GPIO_PIN_6
#define CH2RXEnable_GPIO_Port GPIOA
#define CH2TXEnable_Pin GPIO_PIN_7
#define CH2TXEnable_GPIO_Port GPIOA
#define CH1RXEnable_Pin GPIO_PIN_11
#define CH1RXEnable_GPIO_Port GPIOA
#define CH1TXEnable_Pin GPIO_PIN_12
#define CH1TXEnable_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
