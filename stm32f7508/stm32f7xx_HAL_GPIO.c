#include "stm32f7xx_HAL_GPIO.h"
#include <stdint.h>
#include <assert.h>
#include <stdio.h>








/*
***                                             Local Functions Declaration*/
static void LCL_EnvVarStateInit(APIs_State_t *APIs_State);
static void LCL_EnvVarGpoiConf(Gpoi_Conf_t *Gpoi_Conf);

static void LCL_GpioSetMode(GPIO_TypeDef *Gpiox, uint32_t Pin, uint32_t Mode, APIs_State_t *Apis_State);
static void LCL_GpioSetType(GPIO_TypeDef *Gpiox, uint32_t Pin, uint32_t Type, APIs_State_t *Apis_State);
static void LCL_GpioSetSpeed(GPIO_TypeDef *Gpiox, uint32_t Pin, uint32_t Speed, APIs_State_t *Apis_State);
static void LCL_GpioSetPull(GPIO_TypeDef *Gpiox, uint32_t Pin, uint32_t Pull, APIs_State_t *Apis_State);
static void LCL_GpioSetAltFun(GPIO_TypeDef *Gpiox, uint32_t Pin, uint32_t Alternate_function, APIs_State_t *Apis_State);

static void LCL_CheckApiStatus(APIs_State_t *APIs_State);





uint8_t HAL_EnvInit(APIs_State_t *APIs_State, Gpoi_Conf_t *Gpoi_Conf)
{
    //assert( APIs_State != NULL &&
            //Gpoi_Conf  != NULL );
    LCL_EnvVarStateInit(APIs_State);
    LCL_EnvVarGpoiConf(Gpoi_Conf);
	return E_OK;
	
}





/**
 * @brief API Function to initialize GPIOx Pin_x
 * @param GpioConf Structure contains Confg for GpioxPinx
 * @return uint8_t State of function E_OK or E_NOK
 */

uint8_t HAL_Gpio_Init(Gpoi_Conf_t *GpioConf, APIs_State_t *Api_State)
{


    State_t Drive_State = I_INIT;
    /**
     * @brief  Call APIs to configure Gpiox  
     * 
     */
    assert(GpioConf != NULL);
		assert(GpioConf->GPIOx_Pin >=0 && GpioConf->GPIOx_Pin <16);

    LCL_GpioSetMode(GpioConf->GPIOx   ,GpioConf->GPIOx_Pin, GpioConf->GPIOx_Mode, Api_State);
    LCL_GpioSetType(GpioConf->GPIOx   ,GpioConf->GPIOx_Pin, GpioConf->GPIOx_OType, Api_State);
    LCL_GpioSetSpeed(GpioConf->GPIOx  ,GpioConf->GPIOx_Pin, GpioConf->GPIOx_OSpeed, Api_State);
    LCL_GpioSetPull(GpioConf->GPIOx   ,GpioConf->GPIOx_Pin, GpioConf->GPIOx_Pull, Api_State);
    LCL_GpioSetAltFun(GpioConf->GPIOx ,GpioConf->GPIOx_Pin, GpioConf->GPIOx_AlterFunc, Api_State);


    if (Api_State->ApiState == E_OK) /*If all APi return E_OK processed Further else return E_NOK
            *Check with an API that all function return E_OK */
    {
        Drive_State = E_OK;
    }
    else
    {
        Drive_State = E_NOK;
    }
   return Drive_State;
}


/**
 * @brief  API function to write a value to Pin_x
 * @param Gpiox  GPIOA or GPIOB ...
 * @param GpioPin  Which Pin 
 * @param State  Value ON or OFF
 * @return void 
 */
void HAL_Gpio_WritePin(GPIO_TypeDef *Gpiox,uint32_t GpioPin, uint32_t State)
{
	//assert(State >=0U && State < 2U );
    if (State)
    {
        Gpiox->BSRR |= (State << GpioPin);
    }
    else
    {
         Gpiox->BSRR |= (State << (GpioPin + 16U));
    }  
     
}


/**
 * @brief  API to toggle pin state from state_ON to state OFF and vise-versa 
 * @note   
 * @param  *Gpiox: GPIOA or GPIOB ...
 * @param  GpioPin: Which Pin e.g. 15 or 10 ...
 * @retval void 
*/
void HAL_Gpio_TogglePin(GPIO_TypeDef *Gpiox,uint32_t GpioPin)
{
    Gpiox->BSRR ^= (1U << GpioPin);
}




/******************************************************************************
***                                 *Local Functions Implementations***********
******************************************************************************/

/**
 * @brief LCL_EnvVarStateInit API to initialize APIs_State struct
 * 
 * @param APIs_State 
 * @return uint8_t 
 */
void LCL_EnvVarStateInit(APIs_State_t *APIs_State)
{
    APIs_State->GpioSetMode = E_NOK ;
    APIs_State->GpioSetType = E_NOK ;
    APIs_State->GpioSetSpeed = E_NOK ;
    APIs_State->GpioSetPull = E_NOK ;
    APIs_State->GpioSetAltFun = E_NOK ;
    APIs_State->ApiState = E_NOK;
}

/**
 * @brief LCL_EnvVarGpoiConf API to initialize Gpoi_Conf struct
 * @param Gpoi_Conf 
 * @return uint8_t 
 */

    void LCL_EnvVarGpoiConf(Gpoi_Conf_t *Gpoi_Conf)
    {
        Gpoi_Conf->GPIOx_Pin    &= ~INIT_STATE;
        Gpoi_Conf->GPIOx_Mode   &= ~INIT_STATE;
        Gpoi_Conf->GPIOx_OType  &= ~INIT_STATE;
        Gpoi_Conf->GPIOx_OSpeed &= ~INIT_STATE;
        Gpoi_Conf->GPIOx_Pull   &= ~INIT_STATE;
        Gpoi_Conf->GPIOx_AlterFunc &= ~INIT_STATE;
    }


/**
 * @brief 
 * 
 * @param APIs_State 
 */
void LCL_CheckApiStatus(APIs_State_t *APIs_State)
{
    if( APIs_State->GpioSetMode == E_OK &&
        APIs_State->GpioSetType == E_OK &&
        APIs_State->GpioSetSpeed == E_OK &&
        APIs_State->GpioSetPull == E_OK &&
        APIs_State->GpioSetAltFun == E_OK)
    {
        APIs_State->ApiState = E_OK;
    }else{
        APIs_State->ApiState = E_NOK;
    }

}




/**
 * @brief LCL_GpioSetMode API to configure the I/O mode.
 * @param Gpiox 
 * @param Pin 
 * @param Mode 
 * @return uint8_t 
 */
static void LCL_GpioSetMode(GPIO_TypeDef *Gpiox, uint32_t Pin, uint32_t Mode, APIs_State_t *Apis_State)
{
     //assert(Mode >=0U && Mode < 3U );
    /**
     * @brief Clear Mode Register 
    */
    Gpiox->MODER &=~ ((uint32_t) (0xFFFF << 0U));

     /**
     * @brief Update Register with value Mode
    */
    Gpiox->MODER |= (Mode << Pin);
    
    Apis_State->GpioSetMode = E_OK;
	
}

/**
 * @brief LCL_GpioSetType API to configure the I/O output type
 * 
 * @param Gpiox 
 * @param Pin 
 * @param Type 
 * @return uint8_t 
 */
static void LCL_GpioSetType(GPIO_TypeDef *Gpiox, uint32_t Pin, uint32_t Type, APIs_State_t *Apis_State)
{

    //assert(Type >=0U && Type < 2U );
    /**
     * @brief Clear Mode Register 
    */
    Gpiox->OTYPER &=~ ((uint32_t) (0xFFFF << 0U));

     /**
     * @brief Update Register with value Mode
    */
    Gpiox->OTYPER |= (Type << Pin);

    Apis_State->GpioSetType = E_OK;
}

/**
 * @brief LCL_GpioSetSpeed API to configure the I/O output speed.
 * 
 * @param Gpiox 
 * @param Pin 
 * @param Speed 
 * @return uint8_t 
 */
static void LCL_GpioSetSpeed(GPIO_TypeDef *Gpiox, uint32_t Pin, uint32_t Speed, APIs_State_t *Apis_State)
{
    
    //assert(Speed >=0U && Speed < 5U );
    /**
     * @brief Clear Mode Register 
    */
    Gpiox->OSPEEDR &=~ ((uint32_t) (0xFFFF << 0U));

     /**
     * @brief Update Register with value Mode
    */
    Gpiox->OSPEEDR |= (Speed << Pin);

    Apis_State->GpioSetSpeed = E_OK;
}

/**
 * @brief LCL_GpioSetPull API to configure the I/O pull-up or pull-down
 * 
 * @param Gpiox 
 * @param Pin 
 * @param Pull 
 * @return uint8_t 
 */
static void LCL_GpioSetPull(GPIO_TypeDef *Gpiox, uint32_t Pin, uint32_t Pull, APIs_State_t *Apis_State)
{

    //assert(Pull >=0U && Pull < 4U );
    /**
     * @brief Clear Mode Register 
    */
    Gpiox->PUPDR &=~ ((uint32_t) (0xFFFF << 0U));

     /**
     * @brief Update Register with value Mode
    */
    Gpiox->PUPDR |= (Pull << Pin);

      Apis_State->GpioSetPull = E_OK;
}

/**
 * @brief LCL_GpioSetAltFun API to configure alternate function I/Os.
 * 
 * @param Gpiox 
 * @param Pin 
 * @param Alternate_function 
 * @return uint8_t 
 */
static void LCL_GpioSetAltFun(GPIO_TypeDef *Gpiox, uint32_t Pin, uint32_t Alternate_function, APIs_State_t *Apis_State)
{
		/**
     * @brief Pos shift for AFRH register
     * 
     */
    uint32_t pos = 0U;
	
    //assert(Alternate_function >=0U && Alternate_function < 17U );
    
    

    pos = (Pin % 8U);
    /**
      * @brief Update Register with value Mode
      */
    if(Pin<8U)
        {
            Gpiox->AFR[0] |= (uint32_t)(Alternate_function << (Pin*4));
        }
    else
        {
            Gpiox->AFR[1] |= (uint32_t)(Alternate_function << pos);
        }   

    Apis_State->GpioSetAltFun = E_OK;
				
}

