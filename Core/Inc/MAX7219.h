/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : max7219.h
  * @brief          : Header for max7219.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#ifndef __MAX7219_H
#define __MAX7219_H

#endif
#include "stm32f3xx_hal_spi.h"
#include "stm32f3xx_hal.h"

#define DECODE_MODE_REG
#define INTENSITY_REG
#define SCAN_LIM_REG
#define SHUTDOWN_REG
#define DSIPLAY_REST_REG
uint8_t INIT_COMMANDS[6][2] = {
    {0x09,0x00},
    {0x0A,0x07},
    {0x0B,0x07},
    {0x0C,0x00},
    {0x0C,0x01},
    {0x0F,0x00}
  };

HAL_StatusTypeDef MAX7219_Init(SPI_HandleTypeDef * hspi);
HAL_StatusTypeDef MAX7219_Render(SPI_HandleTypeDef * hspi, uint64_t img, uint8_t T_Buff[2]);



