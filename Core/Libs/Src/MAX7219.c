#include "MAX7219.h"
#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_spi.h"

HAL_StatusTypeDef MAX7219_Init(SPI_HandleTypeDef * hspi){
    
    HAL_StatusTypeDef error = 0x00;

    for (uint8_t i = 0; i < 6; i++){
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
        error |= HAL_SPI_Transmit(hspi, (uint8_t *)INIT_COMMANDS[i],2, 100);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
  }
  return error;
};

HAL_StatusTypeDef MAX7219_Render(SPI_HandleTypeDef * hspi, uint64_t img, uint8_t T_Buff[2]){
    
    HAL_StatusTypeDef error = 0x00;
    
    for (uint8_t i = 0x01; i <= 0x08; i++){
        T_Buff[0] = i;
        T_Buff[1] = img >> (i - 1)*8;
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
        error |= HAL_SPI_Transmit(hspi, T_Buff, 2,10);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
      };
      return error;
};
