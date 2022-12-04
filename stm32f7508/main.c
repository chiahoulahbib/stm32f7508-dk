#include "stm32f7xx.h"                
#include "stm32f7xx_HAL_GPIO.h"
#include "stm32f7xx_HAL_RCC.h"
#include <stdio.h>
#include <assert.h>


/* Contents of your source file */
//HAL_EnvInit(&APIs_State,&Gpoi_Conf);

 

int main()
{
	/**
	 * @brief Declare global variablr of API state and Gpio configuration
	 * 
	 */
		Gpoi_Conf_t Gpoi_Conf;
		APIs_State_t Apis_State ;

		SystemCoreClockUpdate();
		RCC_ENABLE_GPIOI();

	 
 
		//uint8_t enviInit = E_NOK;
	 
	 
	
	//enviInit = HAL_EnvInit(&Apis_State,&Gpoi_Conf);
	//assert(enviInit == E_OK);
	
	
	
	Gpoi_Conf.GPIOx = GPIOI;
	Gpoi_Conf.GPIOx_Pin	   = 1;
	Gpoi_Conf.GPIOx_Mode      = OUTPUT_MODE;
	Gpoi_Conf.GPIOx_OType     = PUSH_PULL;
	Gpoi_Conf.GPIOx_OSpeed    = LOW_SPEED;
	Gpoi_Conf.GPIOx_Pull      = NO_PULL;

	HAL_Gpio_Init(&Gpoi_Conf,&Apis_State);

	while(1)
	{
		GPIOI->BSRR |= ((uint32_t)0x01u << 1u);
	}

	return 0;
	
	
	
}




