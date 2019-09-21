 /** \file interrupt_link.cpp
 * \brief Interrupt handler callback implementation.
 *
 * The functions in this file link wraps the methods of the module class in C friendly callbacks.
 * If I recall, this was necessary because the interrupt handler functions called from the system NVIC needed to be defined in C code.
 *
 */

#include <osc.hpp>
#include "interrupt_link.hpp"

/// Assign the callback function pointers to the wrapper functions and the pointer to the module class to the void pointer modulePointer.
void linkInterrupts(ViaOsc * voidPointer) {

	modulePointer = (void *) voidPointer;

	uiTimerCallback = *uiTimerHandler;
	mainRisingEdgeCallback = &mainRisingEdgeHandler;
	mainFallingEdgeCallback = &mainFallingEdgeHandler;
	auxRisingEdgeCallback = &auxRisingEdgeHandler;
	auxFallingEdgeCallback = &auxFallingEdgeHandler;
	buttonPressedCallback = &buttonPressedHandler;
	buttonReleasedCallback = &buttonReleasedHandler;
	dacHalfTransferCallback = &dacHalfTransferHandler;
	dacTransferCompleteCallback = &dacTransferCompleteHandler;
	dacTimerCallback = &dacTimerHandler;
	sdaadcConversionCompleteCallback = &sdaadcConversionCompleteHandler;
	adcConversionCompleteCallback = &adcConversionCompleteHandler;
	auxTimer1InterruptCallback = &auxTimer1InterruptHandler;
	auxTimer2InterruptCallback = &auxTimer2InterruptHandler;

}

//@{
/// Cast the void pointer to used to reference the module class to an actual pointer to the class. Use that to call the appropriate handler method.
void uiTimerHandler(void * voidPointer) {

	ViaOsc * modulePointer = (ViaOsc *) voidPointer;
	modulePointer->ui_dispatch(TIMEOUT_SIG);

}
void mainRisingEdgeHandler(void * voidPointer) {

	ViaOsc * modulePointer = (ViaOsc *) voidPointer;
	modulePointer->mainRisingEdgeCallback();

}
void mainFallingEdgeHandler(void * voidPointer) {

	ViaOsc * modulePointer = (ViaOsc *) voidPointer;
	modulePointer->mainFallingEdgeCallback();

}
void auxRisingEdgeHandler(void * voidPointer) {

	ViaOsc * modulePointer = (ViaOsc *) voidPointer;
	modulePointer->auxRisingEdgeCallback();

}
void auxFallingEdgeHandler(void * voidPointer) {

	ViaOsc * modulePointer = (ViaOsc *) voidPointer;
	modulePointer->auxFallingEdgeCallback();

}
void buttonPressedHandler(void * voidPointer) {

	ViaOsc * modulePointer = (ViaOsc *) voidPointer;
	modulePointer->buttonPressedCallback();

}
void buttonReleasedHandler(void * voidPointer) {

	ViaOsc * modulePointer = (ViaOsc *) voidPointer;
	modulePointer->buttonReleasedCallback();

}
void adcConversionCompleteHandler(void * voidPointer) {

	ViaOsc * modulePointer = (ViaOsc *) voidPointer;
	modulePointer->slowConversionCallback();

}
void dacHalfTransferHandler(void * voidPointer) {

	ViaOsc * modulePointer = (ViaOsc *) voidPointer;
	modulePointer->halfTransferCallback();

}
void dacTransferCompleteHandler(void * voidPointer) {

	ViaOsc * modulePointer = (ViaOsc *) voidPointer;
	modulePointer->transferCompleteCallback();

}
void dacTimerHandler(void *) {
	;
}
void sdaadcConversionCompleteHandler(void *) {
	;
}

void auxTimer1InterruptHandler(void * voidPointer) {

	ViaOsc * modulePointer = (ViaOsc *) voidPointer;
	modulePointer->auxTimer1InterruptCallback();

}

void auxTimer2InterruptHandler(void * voidPointer) {

	ViaOsc * modulePointer = (ViaOsc *) voidPointer;
	modulePointer->auxTimer2InterruptCallback();

}
//@}
