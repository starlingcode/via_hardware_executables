/**
 ******************************************************************************
 * File Name          : SDADC.c
 * Description        : This file provides code for the configuration
 *                      of the SDADC instances.
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
#include "sdadc.h"

#include "gpio.h"
#include "dma.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

SDADC_HandleTypeDef hsdadc1;
SDADC_HandleTypeDef hsdadc2;
DMA_HandleTypeDef hdma_sdadc1;
DMA_HandleTypeDef hdma_sdadc2;

/* SDADC1 init function */
void MX_SDADC1_Init(void) {
	SDADC_ConfParamTypeDef ConfParamStruct;

	/**Configure the SDADC low power mode, fast conversion mode,
	 slow clock mode and SDADC1 reference voltage 
	 */
	hsdadc1.Instance = SDADC1;
	hsdadc1.Init.IdleLowPowerMode = SDADC_LOWPOWER_NONE;
	hsdadc1.Init.FastConversionMode = SDADC_FAST_CONV_ENABLE;
	hsdadc1.Init.SlowClockMode = SDADC_SLOW_CLOCK_DISABLE;
	hsdadc1.Init.ReferenceVoltage = SDADC_VREF_EXT;
	if (HAL_SDADC_Init(&hsdadc1) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	/**Configure The Regular Mode 
	 */
	if (HAL_SDADC_SelectRegularTrigger(&hsdadc1, SDADC_SOFTWARE_TRIGGER)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	/**Set parameters for SDADC configuration 0 Register 
	 */
	ConfParamStruct.InputMode = SDADC_INPUT_MODE_SE_ZERO_REFERENCE;
	ConfParamStruct.Gain = SDADC_GAIN_1;
	ConfParamStruct.CommonMode = SDADC_COMMON_MODE_VDDA_2;
	ConfParamStruct.Offset = 1025;
	if (HAL_SDADC_PrepareChannelConfig(&hsdadc1, SDADC_CONF_INDEX_0,
			&ConfParamStruct) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	/**Configure the Regular Channel 
	 */
	if (HAL_SDADC_AssociateChannelConfig(&hsdadc1, SDADC_CHANNEL_7,
			SDADC_CONF_INDEX_0) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	if (HAL_SDADC_ConfigChannel(&hsdadc1, SDADC_CHANNEL_7,
			SDADC_CONTINUOUS_CONV_ON) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}
/* SDADC2 init function */
void MX_SDADC2_Init(void) {
	SDADC_ConfParamTypeDef ConfParamStruct;

	/**Configure the SDADC low power mode, fast conversion mode,
	 slow clock mode and SDADC1 reference voltage 
	 */
	hsdadc2.Instance = SDADC2;
	hsdadc2.Init.IdleLowPowerMode = SDADC_LOWPOWER_NONE;
	hsdadc2.Init.FastConversionMode = SDADC_FAST_CONV_ENABLE;
	hsdadc2.Init.SlowClockMode = SDADC_SLOW_CLOCK_DISABLE;
	hsdadc2.Init.ReferenceVoltage = SDADC_VREF_EXT;
	if (HAL_SDADC_Init(&hsdadc2) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	/**Configure The Regular Mode 
	 */
	if (HAL_SDADC_SelectRegularTrigger(&hsdadc2, SDADC_SOFTWARE_TRIGGER)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	/**Set parameters for SDADC configuration 0 Register 
	 */
	ConfParamStruct.InputMode = SDADC_INPUT_MODE_SE_ZERO_REFERENCE;
	ConfParamStruct.Gain = SDADC_GAIN_1;
	ConfParamStruct.CommonMode = SDADC_COMMON_MODE_VDDA_2;
	ConfParamStruct.Offset = 0;
	if (HAL_SDADC_PrepareChannelConfig(&hsdadc2, SDADC_CONF_INDEX_0,
			&ConfParamStruct) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	/**Configure the Regular Channel 
	 */
	if (HAL_SDADC_AssociateChannelConfig(&hsdadc2, SDADC_CHANNEL_8,
			SDADC_CONF_INDEX_0) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	if (HAL_SDADC_ConfigChannel(&hsdadc2, SDADC_CHANNEL_8,
			SDADC_CONTINUOUS_CONV_ON) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}

void HAL_SDADC_MspInit(SDADC_HandleTypeDef* sdadcHandle) {

	GPIO_InitTypeDef GPIO_InitStruct;
	if (sdadcHandle->Instance == SDADC1) {
		/* USER CODE BEGIN SDADC1_MspInit 0 */

		/* USER CODE END SDADC1_MspInit 0 */
		/* SDADC1 clock enable */
		__HAL_RCC_SDADC1_CLK_ENABLE()
		;

		/**SDADC1 GPIO Configuration    
		 PE9     ------> SDADC1_AIN7P 
		 */
		GPIO_InitStruct.Pin = CV_2_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(CV_2_GPIO_Port, &GPIO_InitStruct);

		/* SDADC1 DMA Init */
		/* SDADC1 Init */
		hdma_sdadc1.Instance = DMA2_Channel3;
		hdma_sdadc1.Init.Direction = DMA_PERIPH_TO_MEMORY;
		hdma_sdadc1.Init.PeriphInc = DMA_PINC_DISABLE;
		hdma_sdadc1.Init.MemInc = DMA_MINC_ENABLE;
		hdma_sdadc1.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
		hdma_sdadc1.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
		hdma_sdadc1.Init.Mode = DMA_CIRCULAR;
		hdma_sdadc1.Init.Priority = DMA_PRIORITY_LOW;
		if (HAL_DMA_Init(&hdma_sdadc1) != HAL_OK) {
			_Error_Handler(__FILE__, __LINE__);
		}

		__HAL_LINKDMA(sdadcHandle, hdma, hdma_sdadc1);

		/* USER CODE BEGIN SDADC1_MspInit 1 */

		/* USER CODE END SDADC1_MspInit 1 */
	} else if (sdadcHandle->Instance == SDADC2) {
		/* USER CODE BEGIN SDADC2_MspInit 0 */

		/* USER CODE END SDADC2_MspInit 0 */
		/* SDADC2 clock enable */
		__HAL_RCC_SDADC2_CLK_ENABLE()
		;

		/**SDADC2 GPIO Configuration    
		 PE8     ------> SDADC2_AIN8P 
		 */
		GPIO_InitStruct.Pin = CV_3_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(CV_3_GPIO_Port, &GPIO_InitStruct);

		/* SDADC2 DMA Init */
		/* SDADC2 Init */
		hdma_sdadc2.Instance = DMA2_Channel4;
		hdma_sdadc2.Init.Direction = DMA_PERIPH_TO_MEMORY;
		hdma_sdadc2.Init.PeriphInc = DMA_PINC_DISABLE;
		hdma_sdadc2.Init.MemInc = DMA_MINC_ENABLE;
		hdma_sdadc2.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
		hdma_sdadc2.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
		hdma_sdadc2.Init.Mode = DMA_CIRCULAR;
		hdma_sdadc2.Init.Priority = DMA_PRIORITY_LOW;
		if (HAL_DMA_Init(&hdma_sdadc2) != HAL_OK) {
			_Error_Handler(__FILE__, __LINE__);
		}

		__HAL_LINKDMA(sdadcHandle, hdma, hdma_sdadc2);

		/* USER CODE BEGIN SDADC2_MspInit 1 */

		/* USER CODE END SDADC2_MspInit 1 */
	}
}

void HAL_SDADC_MspDeInit(SDADC_HandleTypeDef* sdadcHandle) {

	if (sdadcHandle->Instance == SDADC1) {
		/* USER CODE BEGIN SDADC1_MspDeInit 0 */

		/* USER CODE END SDADC1_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_SDADC1_CLK_DISABLE();

		/**SDADC1 GPIO Configuration    
		 PE9     ------> SDADC1_AIN7P 
		 */
		HAL_GPIO_DeInit(CV_2_GPIO_Port, CV_2_Pin);

		/* SDADC1 DMA DeInit */
		HAL_DMA_DeInit(sdadcHandle->hdma);
		/* USER CODE BEGIN SDADC1_MspDeInit 1 */

		/* USER CODE END SDADC1_MspDeInit 1 */
	} else if (sdadcHandle->Instance == SDADC2) {
		/* USER CODE BEGIN SDADC2_MspDeInit 0 */

		/* USER CODE END SDADC2_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_SDADC2_CLK_DISABLE();

		/**SDADC2 GPIO Configuration    
		 PE8     ------> SDADC2_AIN8P 
		 */
		HAL_GPIO_DeInit(CV_3_GPIO_Port, CV_3_Pin);

		/* SDADC2 DMA DeInit */
		HAL_DMA_DeInit(sdadcHandle->hdma);
		/* USER CODE BEGIN SDADC2_MspDeInit 1 */

		/* USER CODE END SDADC2_MspDeInit 1 */
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
