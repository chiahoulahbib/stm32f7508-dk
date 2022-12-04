
#ifndef _HAL_RCC
#define _HAL_RCC

#include "stm32f7xx.h"                  // Device header
#include <stdint.h>

#define RCC_ENABLE_GPIOA()			    														(RCC->AHB1ENR |= ((uint32_t) 0x01 << 0U))
#define RCC_ENABLE_GPIOB()   																		(RCC->AHB1ENR |= ((uint32_t) 0x01 << 1U))
#define RCC_ENABLE_GPIOC()   																		(RCC->AHB1ENR |= ((uint32_t) 0x01 << 2U))
#define RCC_ENABLE_GPIOD()   																		(RCC->AHB1ENR |= ((uint32_t) 0x01 << 3U))
#define RCC_ENABLE_GPIOE()   																		(RCC->AHB1ENR |= ((uint32_t) 0x01 << 4U))
#define RCC_ENABLE_GPIOF()   																		(RCC->AHB1ENR |= ((uint32_t) 0x01 << 5U))
#define RCC_ENABLE_GPIOG()   																		(RCC->AHB1ENR |= ((uint32_t) 0x01 << 6U))
#define RCC_ENABLE_GPIOH()   																		(RCC->AHB1ENR |= ((uint32_t) 0x01 << 7U))
#define RCC_ENABLE_GPIOI()   																		(RCC->AHB1ENR |= ((uint32_t) 0x01 << 8U))
#define RCC_ENABLE_GPIOJ()   																		(RCC->AHB1ENR |= ((uint32_t) 0x01 << 9U))
#define RCC_ENABLE_GPIOK()   																		(RCC->AHB1ENR |= ((uint32_t) 0x01 << 10U))





#endif /*_HAL_RCC*/


