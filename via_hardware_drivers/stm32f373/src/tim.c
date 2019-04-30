/**
 ******************************************************************************
 * File Name          : TIM.c
 * Description        : This file provides code for the configuration
 *                      of the TIM instances.
 ******************************************************************************
 * This notice applies to any and all portions of this file
 * that are not between comment pairs USER CODE BEGIN and
 * USER CODE END. Other portions of this file, whether 
 * inserted by the user or by software development tools
 * are owned by their respective copyright owners.
 *
 * Copyright (c) 2018 STMicroelectronics International N.V. 
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted, provided that the following conditions are met:
 *
 * 1. Redistribution of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of other 
 *    contributors to this software may be used to endorse or promote products 
 *    derived from this software without specific written permission.
 * 4. This software, including modifications and/or derivative works of this 
 *    software, must execute solely and exclusively on microcontroller or
 *    microprocessor devices manufactured by or for STMicroelectronics.
 * 5. Redistribution and use of this software other than as permitted under 
 *    this license is void and will automatically terminate your rights under 
 *    this license. 
 *
 * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
 * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
 * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
 * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tim.h"

#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim5;
TIM_HandleTypeDef htim6;
TIM_HandleTypeDef htim7;
TIM_HandleTypeDef htim12;
TIM_HandleTypeDef htim13;
TIM_HandleTypeDef htim16;
TIM_HandleTypeDef htim17;
TIM_HandleTypeDef htim18;

/* TIM2 init function */
void MX_TIM2_Init(void) {

	TIM_MasterConfigTypeDef sMasterConfig;
	TIM_ClockConfigTypeDef sClockSourceConfig;

	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 0;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 4294967295;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim2) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}

/* TIM3 init function */
void MX_TIM3_Init(void) {
	TIM_MasterConfigTypeDef sMasterConfig;
	TIM_OC_InitTypeDef sConfigOC;

	htim3.Instance = TIM3;
	htim3.Init.Prescaler = 1;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = 4095;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_PWM_Init(&htim3) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	HAL_TIM_MspPostInit(&htim3);

}
/* TIM4 init function */
void MX_TIM4_Init(void) {
	TIM_MasterConfigTypeDef sMasterConfig;
	TIM_OC_InitTypeDef sConfigOC;

	htim4.Instance = TIM4;
	htim4.Init.Prescaler = 0;
	htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim4.Init.Period = 4095;
	htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_PWM_Init(&htim4) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_4)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	HAL_TIM_MspPostInit(&htim4);

}
/* TIM5 init function */
void MX_TIM5_Init(void) {
	TIM_MasterConfigTypeDef sMasterConfig;
	TIM_OC_InitTypeDef sConfigOC;

	htim5.Instance = TIM5;
	htim5.Init.Prescaler = 0;
	htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim5.Init.Period = 4095;
	htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim5.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_PWM_Init(&htim5) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim5, &sMasterConfig)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&htim5, &sConfigOC, TIM_CHANNEL_1)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	HAL_TIM_MspPostInit(&htim5);

}

/* TIM5 init function */
void MX_TIM5_Init_Gateseq(void) {
	TIM_MasterConfigTypeDef sMasterConfig;

	htim5.Instance = TIM5;
	htim5.Init.Prescaler = 0;
	htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim5.Init.Period = 4095;
	htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim5.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_PWM_Init(&htim5) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim5, &sMasterConfig)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

//	sConfigOC.OCMode = TIM_OCMODE_PWM1;
//	sConfigOC.Pulse = 0;
//	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
//	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
//	if (HAL_TIM_PWM_ConfigChannel(&htim5, &sConfigOC, TIM_CHANNEL_1)
//			!= HAL_OK) {
//		_Error_Handler(__FILE__, __LINE__);
//	}

	//HAL_TIM_MspPostInit(&htim5);
	// configure the pin as a GPIO
	GPIO_InitTypeDef GPIO_InitStruct;
	/*Configure GPIO pins : PAPin PA12 */
	GPIO_InitStruct.Pin = GPIO_PIN_8;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* TIM6 init function */
void MX_TIM6_Init(void) {
	TIM_MasterConfigTypeDef sMasterConfig;

	htim6.Instance = TIM6;
	htim6.Init.Prescaler = 0;
	htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim6.Init.Period = 1439;
	htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim6) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}
/* TIM7 init function */
void MX_TIM7_Init(void) {
	TIM_MasterConfigTypeDef sMasterConfig;

	htim7.Instance = TIM7;
	htim7.Init.Prescaler = 10000;
	htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim7.Init.Period = 1000;
	htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim7) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}
/* TIM12 init function */
void MX_TIM12_Init(void) {
	TIM_IC_InitTypeDef sConfigIC;

	htim12.Instance = TIM12;
	htim12.Init.Prescaler = 0;
	htim12.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim12.Init.Period = 0;
	htim12.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim12.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_IC_Init(&htim12) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_BOTHEDGE;
	sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
	sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
	sConfigIC.ICFilter = 0;
	if (HAL_TIM_IC_ConfigChannel(&htim12, &sConfigIC, TIM_CHANNEL_2)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}
/* TIM13 init function */
void MX_TIM13_Init(void) {

	htim13.Instance = TIM13;
	htim13.Init.Prescaler = 2;
	htim13.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim13.Init.Period = 36000;
	htim13.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim13.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim13) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}
/* TIM16 init function */
void MX_TIM16_Init(void) {

	htim16.Instance = TIM16;
	htim16.Init.Prescaler = 5000;
	htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim16.Init.Period = 2000;
	htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim16.Init.RepetitionCounter = 0;
	htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim16) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}
/* TIM17 init function */
void MX_TIM17_Init(void) {

	htim17.Instance = TIM17;
	htim17.Init.Prescaler = 1;
	htim17.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim17.Init.Period = 10000;
	htim17.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim17.Init.RepetitionCounter = 0;
	htim17.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim17) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}
/* TIM18 init function */
void MX_TIM18_Init(void) {
	TIM_MasterConfigTypeDef sMasterConfig;

	htim18.Instance = TIM18;
	htim18.Init.Prescaler = 100;
	htim18.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim18.Init.Period = 10000;
	htim18.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim18) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim18, &sMasterConfig)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* tim_pwmHandle) {

	if (tim_pwmHandle->Instance == TIM3) {
		/* USER CODE BEGIN TIM3_MspInit 0 */

		/* USER CODE END TIM3_MspInit 0 */
		/* TIM3 clock enable */
		__HAL_RCC_TIM3_CLK_ENABLE()
		;
		/* USER CODE BEGIN TIM3_MspInit 1 */

		/* USER CODE END TIM3_MspInit 1 */
	} else if (tim_pwmHandle->Instance == TIM4) {
		/* USER CODE BEGIN TIM4_MspInit 0 */

		/* USER CODE END TIM4_MspInit 0 */
		/* TIM4 clock enable */
		__HAL_RCC_TIM4_CLK_ENABLE()
		;
		/* USER CODE BEGIN TIM4_MspInit 1 */

		/* USER CODE END TIM4_MspInit 1 */
	} else if (tim_pwmHandle->Instance == TIM5) {
		/* USER CODE BEGIN TIM5_MspInit 0 */

		/* USER CODE END TIM5_MspInit 0 */
		/* TIM5 clock enable */
		__HAL_RCC_TIM5_CLK_ENABLE()
		;
		/* USER CODE BEGIN TIM5_MspInit 1 */

		/* USER CODE END TIM5_MspInit 1 */
	}
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle) {

	if (tim_baseHandle->Instance == TIM2) {
		/* USER CODE BEGIN TIM2_MspInit 0 */

		/* USER CODE END TIM2_MspInit 0 */
		/* TIM2 clock enable */
		__HAL_RCC_TIM2_CLK_ENABLE()
		;
		/* USER CODE BEGIN TIM2_MspInit 1 */
		/* TIM62 interrupt Init */
		HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);
		HAL_NVIC_EnableIRQ(TIM2_IRQn);

		/* USER CODE END TIM2_MspInit 1 */
	}

	if (tim_baseHandle->Instance == TIM6) {
		/* USER CODE BEGIN TIM6_MspInit 0 */

		/* USER CODE END TIM6_MspInit 0 */
		/* TIM6 clock enable */
		__HAL_RCC_TIM6_CLK_ENABLE()
		;

		/* TIM6 interrupt Init */
		HAL_NVIC_SetPriority(TIM6_DAC1_IRQn, 1, 0);
		HAL_NVIC_EnableIRQ(TIM6_DAC1_IRQn);
		/* USER CODE BEGIN TIM6_MspInit 1 */

		/* USER CODE END TIM6_MspInit 1 */
	} else if (tim_baseHandle->Instance == TIM7) {
		/* USER CODE BEGIN TIM7_MspInit 0 */

		/* USER CODE END TIM7_MspInit 0 */
		/* TIM7 clock enable */
		__HAL_RCC_TIM7_CLK_ENABLE()
		;

		/* TIM7 interrupt Init */
		HAL_NVIC_SetPriority(TIM7_IRQn, 2, 0);
		HAL_NVIC_EnableIRQ(TIM7_IRQn);
		/* USER CODE BEGIN TIM7_MspInit 1 */

		/* USER CODE END TIM7_MspInit 1 */
	} else if (tim_baseHandle->Instance == TIM13) {
		/* USER CODE BEGIN TIM13_MspInit 0 */

		/* USER CODE END TIM13_MspInit 0 */
		/* TIM13 clock enable */
		__HAL_RCC_TIM13_CLK_ENABLE()
		;

		/* TIM13 interrupt Init */
		HAL_NVIC_SetPriority(TIM13_IRQn, 2, 0);
		HAL_NVIC_EnableIRQ(TIM13_IRQn);
		/* USER CODE BEGIN TIM13_MspInit 1 */

		/* USER CODE END TIM13_MspInit 1 */
	} else if (tim_baseHandle->Instance == TIM16) {
		/* USER CODE BEGIN TIM16_MspInit 0 */

		/* USER CODE END TIM16_MspInit 0 */
		/* TIM16 clock enable */
		__HAL_RCC_TIM16_CLK_ENABLE()
		;

		/* TIM16 interrupt Init */
		HAL_NVIC_SetPriority(TIM16_IRQn, 1, 0);
		HAL_NVIC_EnableIRQ(TIM16_IRQn);
		/* USER CODE BEGIN TIM16_MspInit 1 */

		/* USER CODE END TIM16_MspInit 1 */
	} else if (tim_baseHandle->Instance == TIM17) {
		/* USER CODE BEGIN TIM17_MspInit 0 */

		/* USER CODE END TIM17_MspInit 0 */
		/* TIM17 clock enable */
		__HAL_RCC_TIM17_CLK_ENABLE()
		;

		/* TIM17 interrupt Init */
		HAL_NVIC_SetPriority(TIM17_IRQn, 1, 0);
		HAL_NVIC_EnableIRQ(TIM17_IRQn);
		/* USER CODE BEGIN TIM17_MspInit 1 */

		/* USER CODE END TIM17_MspInit 1 */
	} else if (tim_baseHandle->Instance == TIM18) {
		/* USER CODE BEGIN TIM18_MspInit 0 */

		/* USER CODE END TIM18_MspInit 0 */
		/* TIM18 clock enable */
		__HAL_RCC_TIM18_CLK_ENABLE();
		/* USER CODE BEGIN TIM18_MspInit 1 */
	    HAL_NVIC_SetPriority(TIM18_DAC2_IRQn, 2, 0);
	    HAL_NVIC_EnableIRQ(TIM18_DAC2_IRQn);

		/* USER CODE END TIM18_MspInit 1 */
	}
}

void HAL_TIM_IC_MspInit(TIM_HandleTypeDef* tim_icHandle) {

	GPIO_InitTypeDef GPIO_InitStruct;
	if (tim_icHandle->Instance == TIM12) {
		/* USER CODE BEGIN TIM12_MspInit 0 */

		/* USER CODE END TIM12_MspInit 0 */
		/* TIM12 clock enable */
		__HAL_RCC_TIM12_CLK_ENABLE()
		;

		/**TIM12 GPIO Configuration    
		 PA15     ------> TIM12_CH2 
		 */
		GPIO_InitStruct.Pin = GPIO_PIN_15;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF10_TIM12;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		/* TIM12 interrupt Init */
		HAL_NVIC_SetPriority(TIM12_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(TIM12_IRQn);
		/* USER CODE BEGIN TIM12_MspInit 1 */

		/* USER CODE END TIM12_MspInit 1 */
	}
}
void HAL_TIM_MspPostInit(TIM_HandleTypeDef* timHandle) {

	GPIO_InitTypeDef GPIO_InitStruct;
	if (timHandle->Instance == TIM3) {
		/* USER CODE BEGIN TIM3_MspPostInit 0 */

		/* USER CODE END TIM3_MspPostInit 0 */
		/**TIM3 GPIO Configuration    
		 PB5     ------> TIM3_CH2 
		 */
		GPIO_InitStruct.Pin = RED_LED_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
		HAL_GPIO_Init(RED_LED_GPIO_Port, &GPIO_InitStruct);

		/* USER CODE BEGIN TIM3_MspPostInit 1 */

		/* USER CODE END TIM3_MspPostInit 1 */
	} else if (timHandle->Instance == TIM4) {
		/* USER CODE BEGIN TIM4_MspPostInit 0 */

		/* USER CODE END TIM4_MspPostInit 0 */

		/**TIM4 GPIO Configuration    
		 PF6     ------> TIM4_CH4 
		 */
		GPIO_InitStruct.Pin = GREEN_LED_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
		HAL_GPIO_Init(GREEN_LED_GPIO_Port, &GPIO_InitStruct);

		/* USER CODE BEGIN TIM4_MspPostInit 1 */

		/* USER CODE END TIM4_MspPostInit 1 */
	} else if (timHandle->Instance == TIM5) {
		/* USER CODE BEGIN TIM5_MspPostInit 0 */

		/* USER CODE END TIM5_MspPostInit 0 */

		/**TIM5 GPIO Configuration    
		 PA8     ------> TIM5_CH1 
		 */
		GPIO_InitStruct.Pin = BLUE_LED_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF2_TIM5;
		HAL_GPIO_Init(BLUE_LED_GPIO_Port, &GPIO_InitStruct);

		/* USER CODE BEGIN TIM5_MspPostInit 1 */

		/* USER CODE END TIM5_MspPostInit 1 */
	}

}

void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef* tim_pwmHandle) {

	if (tim_pwmHandle->Instance == TIM3) {
		/* USER CODE BEGIN TIM3_MspDeInit 0 */

		/* USER CODE END TIM3_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM3_CLK_DISABLE();
		/* USER CODE BEGIN TIM3_MspDeInit 1 */

		/* USER CODE END TIM3_MspDeInit 1 */
	} else if (tim_pwmHandle->Instance == TIM4) {
		/* USER CODE BEGIN TIM4_MspDeInit 0 */

		/* USER CODE END TIM4_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM4_CLK_DISABLE();
		/* USER CODE BEGIN TIM4_MspDeInit 1 */

		/* USER CODE END TIM4_MspDeInit 1 */
	} else if (tim_pwmHandle->Instance == TIM5) {
		/* USER CODE BEGIN TIM5_MspDeInit 0 */

		/* USER CODE END TIM5_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM5_CLK_DISABLE();
		/* USER CODE BEGIN TIM5_MspDeInit 1 */

		/* USER CODE END TIM5_MspDeInit 1 */
	}
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle) {

	if (tim_baseHandle->Instance == TIM6) {
		/* USER CODE BEGIN TIM6_MspDeInit 0 */

		/* USER CODE END TIM6_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM6_CLK_DISABLE();

		/* TIM6 interrupt Deinit */
		/* USER CODE BEGIN TIM6:TIM6_DAC1_IRQn disable */
		/**
		 * Uncomment the line below to disable the "TIM6_DAC1_IRQn" interrupt
		 * Be aware, disabling shared interrupt may affect other IPs
		 */
		/* HAL_NVIC_DisableIRQ(TIM6_DAC1_IRQn); */
		/* USER CODE END TIM6:TIM6_DAC1_IRQn disable */

		/* USER CODE BEGIN TIM6_MspDeInit 1 */

		/* USER CODE END TIM6_MspDeInit 1 */
	} else if (tim_baseHandle->Instance == TIM7) {
		/* USER CODE BEGIN TIM7_MspDeInit 0 */

		/* USER CODE END TIM7_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM7_CLK_DISABLE();

		/* TIM7 interrupt Deinit */
		HAL_NVIC_DisableIRQ(TIM7_IRQn);
		/* USER CODE BEGIN TIM7_MspDeInit 1 */

		/* USER CODE END TIM7_MspDeInit 1 */
	} else if (tim_baseHandle->Instance == TIM13) {
		/* USER CODE BEGIN TIM13_MspDeInit 0 */

		/* USER CODE END TIM13_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM13_CLK_DISABLE();

		/* TIM13 interrupt Deinit */
		HAL_NVIC_DisableIRQ(TIM13_IRQn);
		/* USER CODE BEGIN TIM13_MspDeInit 1 */

		/* USER CODE END TIM13_MspDeInit 1 */
	} else if (tim_baseHandle->Instance == TIM16) {
		/* USER CODE BEGIN TIM16_MspDeInit 0 */

		/* USER CODE END TIM16_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM16_CLK_DISABLE();

		/* TIM16 interrupt Deinit */
		HAL_NVIC_DisableIRQ(TIM16_IRQn);
		/* USER CODE BEGIN TIM16_MspDeInit 1 */

		/* USER CODE END TIM16_MspDeInit 1 */
	} else if (tim_baseHandle->Instance == TIM17) {
		/* USER CODE BEGIN TIM17_MspDeInit 0 */

		/* USER CODE END TIM17_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM17_CLK_DISABLE();

		/* TIM17 interrupt Deinit */
		HAL_NVIC_DisableIRQ(TIM17_IRQn);
		/* USER CODE BEGIN TIM17_MspDeInit 1 */

		/* USER CODE END TIM17_MspDeInit 1 */
	} else if (tim_baseHandle->Instance == TIM18) {
		/* USER CODE BEGIN TIM18_MspDeInit 0 */

		/* USER CODE END TIM18_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM18_CLK_DISABLE();
		/* USER CODE BEGIN TIM18_MspDeInit 1 */

		/* USER CODE END TIM18_MspDeInit 1 */
	}
}

void HAL_TIM_IC_MspDeInit(TIM_HandleTypeDef* tim_icHandle) {

	if (tim_icHandle->Instance == TIM12) {
		/* USER CODE BEGIN TIM12_MspDeInit 0 */

		/* USER CODE END TIM12_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_TIM12_CLK_DISABLE();

		/**TIM12 GPIO Configuration    
		 PA15     ------> TIM12_CH2 
		 */
		HAL_GPIO_DeInit(GPIOA, GPIO_PIN_15);

		/* TIM12 interrupt Deinit */
		HAL_NVIC_DisableIRQ(TIM12_IRQn);
		/* USER CODE BEGIN TIM12_MspDeInit 1 */

		/* USER CODE END TIM12_MspDeInit 1 */
	}
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
