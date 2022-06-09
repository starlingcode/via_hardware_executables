/** \file user_interrupts.c
 * \brief Calibration module implementation.
 *
 *  A module implementing a simple testing/calibration helper program that serves as a template.
 *  See src/main_hardware_init.cpp for details on MCU setup, see src/interrupt_link.cpp, inc/interrupt_link.cpp for callback function implementation.
 *
 */

#include <via-f373-system.hpp>
#include "tsl_user.h"
#include "stm32f3xx_it.h"
#include "interrupt_link.hpp"

//#define PROFILE_ON

int triggerDebounce = 0;
int buttonPressed = 1;

#define EXPAND_LOGIC_HIGH GPIOA->BRR = (uint32_t)GPIO_PIN_12;
#define EXPAND_LOGIC_LOW GPIOA->BSRR = (uint32_t)GPIO_PIN_12;

#ifdef __cplusplus
extern "C" {
#endif

extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim12;
extern TIM_HandleTypeDef htim13;
extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;
extern TIM_HandleTypeDef htim18;


/*
 *
 *  Logic input interrupts
 *
 */

/// Main logic input state change handler. Signal the appropriate rising or falling edge handler according to GPIO state.
void TIM12_IRQHandler(void)
{

	if (TRIGGER_RISING_EDGE) {
#ifdef PROFILE_ON
	LOGICA_HIGH;
#endif
		(*mainRisingEdgeCallback)(modulePointer);
	} else {
#ifdef PROFILE_ON
	LOGICA_LOW;
#endif
		(*mainFallingEdgeCallback)(modulePointer);
	}

	__HAL_TIM_CLEAR_FLAG(&htim12, TIM_FLAG_CC2);

}

/// Aux logic input state change handler. Signal the appropriate rising or falling edge handler according to GPIO state.
void EXTI15_10_IRQHandler(void)
{

	if (EXPANDER_RISING_EDGE) {
		(*auxRisingEdgeCallback)(modulePointer);
	} else {
		(*auxFallingEdgeCallback)(modulePointer);
	}

  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);

}

/// Trigger button input state change handler. Signal the appropriate rising or falling edge handler according to GPIO state and debounce routine.
void EXTI1_IRQHandler(void)
{

	if (!triggerDebounce) {
		triggerDebounce = 1;
		__HAL_TIM_ENABLE(&htim16);
		if (!buttonPressed) {
			(*buttonPressedCallback)(modulePointer);
			buttonPressed = 1;
		} else {
			buttonPressed = 0;
			(*buttonReleasedCallback)(modulePointer);
		}
	}


	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);

}

/*
 *
 * Timer interrputs
 *
 */

/// Trigger button debounce timer interrupt handler. Disable the debounce flag and call the release handler if the button was released during the debounce timeout.
void TIM16_IRQHandler(void)
{

	triggerDebounce = 0;

	if (!buttonPressed && EXPANDER_BUTTON_PRESSED) {
		(*buttonPressedCallback)(modulePointer);
		buttonPressed = 1;
	} else if (buttonPressed && !EXPANDER_BUTTON_PRESSED) {
		buttonPressed = 0;
		(*buttonReleasedCallback)(modulePointer);
	}

	__HAL_TIM_CLEAR_FLAG(&htim16, TIM_FLAG_UPDATE);
	__HAL_TIM_DISABLE(&htim16);

}

/// Aux timer 1 interrupt handler to signal timer update events (overflow).
void TIM17_IRQHandler(void)
{

	(*auxTimer1InterruptCallback)(modulePointer);
	TIM18->CR1 |= TIM_CR1_CEN;

	__HAL_TIM_CLEAR_FLAG(&htim17, TIM_FLAG_UPDATE);
	__HAL_TIM_DISABLE(&htim17);

}

/// Aux timer 2 interrupt handler to signal timer update events (overflow).
void TIM18_DAC2_IRQHandler(void)
{

	(*auxTimer2InterruptCallback)(modulePointer);

	__HAL_TIM_CLEAR_FLAG(&htim18, TIM_FLAG_UPDATE);
	__HAL_TIM_DISABLE(&htim18);

}

/// Touch sense library execution interrupt handler, executes touch sensor state machine on every timer overflow.
void TIM13_IRQHandler(void)
{

	int tsl_status_here;
	// run the state machine from the STM Touch Library
	tsl_status_here = tsl_user_Exec();
	__HAL_TIM_CLEAR_FLAG(&htim13, TIM_FLAG_UPDATE);

}

/// UI timer interrupt handler.
void TIM7_IRQHandler(void)
{

	(*uiTimerCallback)(modulePointer);

	__HAL_TIM_CLEAR_FLAG(&htim7, TIM_FLAG_UPDATE);

}

/*
 *
 * DMA transfer complete interrupts
 *
 */

/// Control rate ADC conversion complete callback. Only transfer complete is handled because this indicates conversion for all 4 inputs.
void DMA1_Channel1_IRQHandler(void)
{

#ifdef PROFILE_ON
	EXPAND_LOGIC_HIGH;
#endif

	// minimal interrupt handler for circular buffer
	if ((DMA1->ISR & (DMA_FLAG_HT1)) != 0) {
		DMA1->IFCR = DMA_FLAG_HT1;
	} else {
		DMA1->IFCR = DMA_FLAG_TC1;
		(*adcConversionCompleteCallback)(modulePointer);
	}

#ifdef PROFILE_ON
	EXPAND_LOGIC_LOW;
#endif

}

/// Dac transfer complete event handler, inspect the DMA control register to determine if half transfer or full transfer.
void DMA1_Channel5_IRQHandler(void)
{

	if ((DMA1->ISR & (DMA_FLAG_HT1 << 16)) != 0) {
		DMA1->IFCR = DMA_FLAG_HT1 << 16;
		(*dacHalfTransferCallback)(modulePointer);
	} else if ((DMA1->ISR & (DMA_FLAG_TC1 << 16)) != 0)  {
		DMA1->IFCR = DMA_FLAG_TC1 << 16;
		(*dacTransferCompleteCallback)(modulePointer);
	}


}

#ifdef __cplusplus
}
#endif




