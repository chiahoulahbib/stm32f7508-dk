#ifndef _HAL_GPIO
#define _HAL_GPIO

#include "stm32f7xx.h"                  // Device header


/*
Boolean Val*/
#define LOW		       		                        		((uint32_t) 0x00U)
#define HIGH          			                    		((uint32_t) 0x01U)

/*
* PIN section*/
#define PIN0    																		((uint32_t) 0x0)
#define PIN1         																((uint32_t) 0x1)
#define PIN2         																((uint32_t) 0x2)
#define PIN3         																((uint32_t) 0x3)
#define PIN4                                        ((uint32_t) 0x4)
#define PIN5                                        ((uint32_t) 0x5)
#define PIN6                                        ((uint32_t) 0x6)
#define PIN7                                        ((uint32_t) 0x7)
#define PIN8                                        ((uint32_t) 0x8)
#define PIN9                                        ((uint32_t) 0x9)
#define PIN10                                       ((uint32_t) 0x10)
#define PIN11                                       ((uint32_t) 0x11)
#define PIN12         															((uint32_t) 0x12)
#define PIN13                                       ((uint32_t) 0x13)
#define PIN14                                       ((uint32_t) 0x14)
#define PIN15                                       ((uint32_t) 0x15)

/**
 * @brief Error Flags 
 */
#define E_NOK		       		                    			((uint8_t) 0x00)
#define E_OK         			                    			((uint8_t) 0x01)

/*
Boolean state*/
#define TRUE				                        			  ((uint32_t) 0x00)
#define FALSE				                        			  ((uint32_t) 0x01)

/**
 * @brief Gpio Initialization 
 */
#define INIT_STATE		                        			((uint32_t) 0xFFFFFFFF)

/*
GPIO port mode register (GPIOx_MODER) (x =A to K)*/

#define INPUT_MODE				                    			((uint32_t) 0x00)
#define OUTPUT_MODE				                    			((uint32_t) 0x01)
#define ALTERN_MODE				                    			((uint32_t) 0x02)
#define ANALOG_MODE				                    			((uint32_t) 0x03)


/*
GPIO port output type register (GPIOx_OTYPER) (x = A to K)*/

#define PUSH_PULL				                    				((uint32_t) 0x00)
#define OPEN_DRAIN				                   				((uint32_t) 0x01)


/*
GPIO port output speed register (GPIOx_OSPEEDR)
(x = A to K)*/

#define LOW_SPEED				                   		 			((uint32_t) 0x00)
#define MEDIUM_SPEED			                  		  	((uint32_t) 0x01)
#define HIGH_SPEED				                   			 	((uint32_t) 0x02)
#define VERY_HIGH_SPEED			                    		((uint32_t) 0x03)

/*
GPIO port pull-up/pull-down register (GPIOx_PUPDR)
(x = A to K)*/
#define NO_PULL					                    				((uint32_t) 0x00)
#define PULL_UP					                    				((uint32_t) 0x01)
#define PULL_DOWN				                    				((uint32_t) 0x02)

/*
GPIO alternate function low register (GPIOx_AFRL) and (GPIOx_AFRH) 
(x = A to K)*/
#define AF0_SYS																			((uint32_t) 0x0)
#define AF1_TIM1																		((uint32_t) 0x1)
#define AF1_TIM2																		((uint32_t) 0x1)
#define AF2_TIM3																		((uint32_t) 0x2)
#define AF2_TIM4                                    ((uint32_t) 0x2)
#define AF2_TIM5                                    ((uint32_t) 0x2)
#define AF3_TIM8																		((uint32_t) 0x3)
#define AF3_TIM9                                    ((uint32_t) 0x3)
#define AF3_TIM10                                   ((uint32_t) 0x3)
#define AF3_TIM11                                   ((uint32_t) 0x3)
#define AF3_LPTIM1                                  ((uint32_t) 0x3)
#define AF3_CEC                                     ((uint32_t) 0x3)
#define AF4_I2C1                                    ((uint32_t) 0x4)
#define AF4_I2C2                                    ((uint32_t) 0x4)
#define AF4_I2C3																		((uint32_t) 0x4)
#define AF4_I2C4                                    ((uint32_t) 0x4)
#define AF4_CEC                                     ((uint32_t) 0x4)
#define AF5_SPI1                                    ((uint32_t) 0x5)
#define AF5_SPI2                                    ((uint32_t) 0x5)
#define AF5_SPI3                                    ((uint32_t) 0x5)
#define AF5_SPI4                                    ((uint32_t) 0x5)
#define AF5_SPI5                                    ((uint32_t) 0x5)
#define AF5_SPI6                                    ((uint32_t) 0x5)
#define AF6_SPI3                                    ((uint32_t) 0x6)
#define AF6_SAI1                                    ((uint32_t) 0x6)
#define AF7_SPI2                                    ((uint32_t) 0x7)
#define AF7_SPI3                                    ((uint32_t) 0x7)
#define AF7_USART1                                  ((uint32_t) 0x7)
#define AF7_USART2                                  ((uint32_t) 0x7)
#define AF7_USART3                                  ((uint32_t) 0x7)
#define AF7_USART5                                  ((uint32_t) 0x7)
#define AF7_SPDIFRX                                 ((uint32_t) 0x7)
#define AF8_SAI2                                    ((uint32_t) 0x8)
#define AF8_USART6                                  ((uint32_t) 0x8)
#define AF8_UART4                                   ((uint32_t) 0x8)
#define AF8_UART5                                   ((uint32_t) 0x8)
#define AF8_SPDIFRX                                 ((uint32_t) 0x8)
#define AF9_CAN1                                    ((uint32_t) 0x9)
#define AF9_CAN2                                    ((uint32_t) 0x9)
#define AF9_TIM11                                   ((uint32_t) 0x9)
#define AF9_TIM12                                   ((uint32_t) 0x9)
#define AF9_TIM13                                   ((uint32_t) 0x9)
#define AF9_TIM14                                   ((uint32_t) 0x9)
#define AF9_QUADSPI                                 ((uint32_t) 0x9)
#define AF9_LCD                                     ((uint32_t) 0x9)
#define AF10_SAI2                                   ((uint32_t) 0x10)
#define AF10_QUADSPI                                ((uint32_t) 0x10)
#define AF10_OTG2_HS                                ((uint32_t) 0x10)
#define AF10_OTG1_FS                                ((uint32_t) 0x10)
#define AF11_ETH                                    ((uint32_t) 0x11)
#define AF11_OTG1_FS                                ((uint32_t) 0x11)
#define AF12_FMC                                    ((uint32_t) 0x12)
#define AF12_SDMMSC1                                ((uint32_t) 0x12)
#define AF12_OTG2_FS																((uint32_t) 0x12)
#define AF13_DCMI                                   ((uint32_t) 0x13)
#define AF14_LCD                                    ((uint32_t) 0x14)
#define AF15_SYS                                    ((uint32_t) 0x15)






/*
*State = I_XXXXX : I_ => Information
*        E_XXXXX : E_ => Error*/
typedef enum {
	I_INIT 		= 0U,
	I_RUNNING 	= 1U,
	I_FIN_INIT 	= 2U,
	I_SHUTDOWN 	= 3U,
	}State_t;


typedef struct 
{
    uint8_t  GpioSetMode;
    uint8_t  GpioSetType;
    uint8_t  GpioSetSpeed;
    uint8_t  GpioSetPull;
    uint8_t  GpioSetAltFun;
    uint8_t  ApiState;
}APIs_State_t;



typedef struct {
	GPIO_TypeDef *GPIOx;
  uint32_t GPIOx_Pin;
	uint32_t GPIOx_Mode;
	uint32_t GPIOx_OType;
	uint32_t GPIOx_OSpeed;
	uint32_t GPIOx_Pull;
	uint32_t GPIOx_AlterFunc;
}Gpoi_Conf_t;















/**
 * @brief API function to intialize struct APIs_State and Gpoi_Conf
 * 
 * @param APIs_State 
 * @param Gpoi_Conf 
 * @return uint8_t 
 */
uint8_t HAL_EnvInit(APIs_State_t *APIs_State, Gpoi_Conf_t *Gpoi_Conf);

/**
 * @brief API Function to initialize GPIOx Pin_x
 * @param GpioConf Structure contains Confg for GpioxPinx
 * @return uint8_t State of function E_OK or E_NOK
 */
uint8_t HAL_Gpio_Init(Gpoi_Conf_t *GpioConf,APIs_State_t *APIs_State);

/**
 * @brief  API function to write a value to Pin_x
 * @param Gpiox  GPIOA or GPIOB ...
 * @param GpioPin  Which Pin 
 * @param State  Value ON or OFF
 * @return void 
 */
void HAL_Gpio_WritePin(GPIO_TypeDef *Gpiox,uint32_t GpioPin, uint32_t State);


/**
 * @brief  API to toggle pin state from state_ON to state OFF and vise-versa 
 * @note   
 * @param  *Gpiox: GPIOA or GPIOB ...
 * @param  GpioPin: Which Pin e.g. 15 or 10 ...
 * @retval void 
*/
void HAL_Gpio_TogglePin(GPIO_TypeDef *Gpiox,uint32_t GpioPin);

#endif

