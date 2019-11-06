
/* USER CODE BEGIN Includes */

#include <via_platform_binding.hpp>
#include "main.h"
#include "stm32f3xx_hal.h"
#include "adc.h"
#include "dac.h"
#include "dma.h"
#include "sdadc.h"
#include "tim.h"
#include "touchsensing.h"
#include "tsc.h"
#include "gpio.h"

extern void mainHardwareInit(void);

void mainHardwareInit(void) {

/* Start Calibration in polling mode */

	// initialize RGB led
	HAL_TIM_Base_Start(&htim3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_Base_Start(&htim4);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
	HAL_TIM_Base_Start(&htim5);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);

	/// Set the priority and enable an interrupt line to be used by the trigger button input and aux trigger.
	HAL_NVIC_SetPriority(SysTick_IRQn, 3, 3);
	HAL_NVIC_SetPriority(EXTI1_IRQn, 3, 0);
	HAL_NVIC_SetPriority(TIM7_IRQn, 2, 2);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 2);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	HAL_NVIC_SetPriority(TIM12_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(TIM12_IRQn);
	HAL_NVIC_SetPriority(DMA1_Channel5_IRQn, 1, 0);
	HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 2, 1);


	// set the dac sample rate and start the dac timer
	TIM6->ARR = 179;
	HAL_TIM_Base_Start(&htim6);

	 //initialize the timer that is used to detect rising and falling edges at the trigger input
	HAL_TIM_IC_Start_IT(&htim12, TIM_CHANNEL_2);
	TIM2->CR1 |= TIM_CR1_CEN;

	//initialize the touch sensor time base
	HAL_TIM_Base_Start_IT(&htim13);
	//	 initialize the timer that is used for touch sensor press timeout
	__HAL_TIM_ENABLE_IT(&htim7, TIM_IT_UPDATE);

	// initialize the shA timer
	__HAL_TIM_ENABLE_IT(&htim16, TIM_IT_UPDATE);
	// initialize the shB timer
	TIM17->PSC = 1000;
	TIM17->ARR = 2000;
	__HAL_TIM_ENABLE_IT(&htim17, TIM_IT_UPDATE);
	// initialize the shB timer
	TIM18->PSC = 50;
	TIM18->ARR = 1439;
	__HAL_TIM_ENABLE_IT(&htim18, TIM_IT_UPDATE);

}
