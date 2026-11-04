#include "stm32c0xx_hal_gpio.h"

int connectToBus(void)
{
	// turn the pin on
	// HAL_GPIO_WritePin(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, GPIO_PinState 1);

	// actually read the pin and check
	// return HAL_GPIO_ReadPin(const GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
}

int disconnectFromBus(void)
{
	// turn the pin off
	// HAL_GPIO_WritePin(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, GPIO_PinState 1);

	// actually read the pin and check
	// return HAL_GPIO_ReadPin(const GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
}
