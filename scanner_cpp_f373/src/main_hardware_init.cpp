
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

	// set the priority and enable an interrupt line to be used by the trigger button input and aux trigger
	HAL_NVIC_SetPriority(EXTI1_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

	// set the dac sample rate and start the dac timer
	TIM6->ARR = 1439;
	HAL_TIM_Base_Start_IT(&htim6);

	 //initialize the timer that is used to detect rising and falling edges at the trigger input
	HAL_TIM_IC_Start_IT(&htim12, TIM_CHANNEL_2);

	//initialize the touch sensor time base
	HAL_TIM_Base_Start_IT(&htim13);
	//	 initialize the timer that is used for touch sensor press timeout
	__HAL_TIM_ENABLE_IT(&htim7, TIM_IT_UPDATE);

	// initialize the shA timer
	__HAL_TIM_ENABLE_IT(&htim16, TIM_IT_UPDATE);
	// initialize the shB timer
	__HAL_TIM_ENABLE_IT(&htim17, TIM_IT_UPDATE);

}

// stores the sdadc reading at ground for offset compensation

void sdadcOffsetCalibration(int16_t * cv2SampleBuffer, int16_t * cv3SampleBuffer) {

	uint16_t bottomHalf = cv2SampleBuffer[0] >> 2;
	uint16_t topHalf = cv3SampleBuffer[0] >> 2;

	FLASH_OBProgramInitTypeDef pOBInit;
	HAL_FLASHEx_OBGetConfig(&pOBInit);
	HAL_StatusTypeDef obStatus;

	pOBInit.OptionType = OPTIONBYTE_WRP;
	pOBInit.WRPState = OB_WRPSTATE_DISABLE;

	HAL_FLASH_Unlock();
	HAL_FLASH_OB_Unlock();
	obStatus = HAL_FLASHEx_OBProgram(&pOBInit);

	pOBInit.OptionType = OPTIONBYTE_DATA;
	pOBInit.DATAAddress = OB_DATA_ADDRESS_DATA0;
	pOBInit.DATAData = bottomHalf;

	obStatus = HAL_FLASHEx_OBProgram(&pOBInit);

	pOBInit.DATAAddress = OB_DATA_ADDRESS_DATA1;
	pOBInit.DATAData = topHalf;

	obStatus = HAL_FLASHEx_OBProgram(&pOBInit);
	HAL_FLASH_OB_Launch();
}
