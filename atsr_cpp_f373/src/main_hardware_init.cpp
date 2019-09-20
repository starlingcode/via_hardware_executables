 /** \file main_hardware_init.cpp
 * \brief Hardware initialization function.
 *
 * Set up the peripherals to properly invoke interrupt events and send/receive data from the module class.
 *
 */
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

	/// Initialize RGB led PWM generation timers.
	HAL_TIM_Base_Start(&htim3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_Base_Start(&htim4);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
	HAL_TIM_Base_Start(&htim5);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);

	/// Set the priority and enable an interrupt line to be used by the trigger button input and aux trigger.
	HAL_NVIC_SetPriority(EXTI1_IRQn, 1, 2);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 1);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	HAL_NVIC_SetPriority(TIM12_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(TIM12_IRQn);
	HAL_NVIC_SetPriority(DMA1_Channel5_IRQn, 0, 0);

	/// Initialize the timer that is used to detect rising and falling edges at the trigger input.
	HAL_TIM_IC_Start_IT(&htim12, TIM_CHANNEL_2);

	/// Initialize the touch sensor time base.
	HAL_TIM_Base_Start_IT(&htim13);
	// Initialize the timer that is used for touch sensor press timeout.
	__HAL_TIM_ENABLE_IT(&htim7, TIM_IT_UPDATE);

	TIM16->PSC = 1000;
	TIM16->ARR = 2000;
	/// Initialize the trigger debounce timer.
	__HAL_TIM_ENABLE_IT(&htim16, TIM_IT_UPDATE);
	/// Initialize the aux timers.
	TIM17->PSC = 1000;
	TIM17->ARR = 2000;
	__HAL_TIM_ENABLE_IT(&htim17, TIM_IT_UPDATE);
	TIM18->PSC = 1000;
	TIM18->ARR = 2000;
	__HAL_TIM_ENABLE_IT(&htim18, TIM_IT_UPDATE);

}
