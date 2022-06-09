 /** \file interrupt_link.cpp
 * \brief Interrupt handler callback implementation.
 *
 * The functions in this file link wraps the methods of the module class in C friendly callbacks.
 * If I recall, this was necessary because the interrupt handler functions called from the system NVIC needed to be defined in C code.
 *
 */

#include "interrupt_link.hpp"
#include "emptyvia.hpp"

#ifdef __cplusplus
extern "C" {
#endif

void * modulePointer;

void (*tscTimerCallback)(void*);
void (*uiTimerCallback)(void*);
void (*mainRisingEdgeCallback)(void*);
void (*mainFallingEdgeCallback)(void*);
void (*auxRisingEdgeCallback)(void*);
void (*auxFallingEdgeCallback)(void*);
void (*buttonPressedCallback)(void*);
void (*buttonReleasedCallback)(void*);
void (*adcConversionCompleteCallback)(void*);
void (*dacHalfTransferCallback)(void*);
void (*dacTransferCompleteCallback)(void*);
void (*dacTimerCallback)(void*);
void (*sdaadcConversionCompleteCallback)(void*);
void (*auxTimer1InterruptCallback)(void*);
void (*auxTimer2InterruptCallback)(void*);
void (*auxTimer3InterruptCallback)(void*);


#ifdef __cplusplus
}
#endif

/// Assign the callback function pointers to the wrapper functions and the pointer to the module class to the void pointer modulePointer.
void linkInterrupts(ViaEmptyvia * voidPointer) {

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

	ViaEmptyvia * modulePointer = (ViaEmptyvia *) voidPointer;
	modulePointer->ui_dispatch(TIMEOUT_SIG);

}
void mainRisingEdgeHandler(void * voidPointer) {

	ViaEmptyvia * modulePointer = (ViaEmptyvia *) voidPointer;
	modulePointer->mainRisingEdgeCallback();

}
void mainFallingEdgeHandler(void * voidPointer) {

	ViaEmptyvia * modulePointer = (ViaEmptyvia *) voidPointer;
	modulePointer->mainFallingEdgeCallback();

}
void auxRisingEdgeHandler(void * voidPointer) {

	ViaEmptyvia * modulePointer = (ViaEmptyvia *) voidPointer;
	modulePointer->auxRisingEdgeCallback();

}
void auxFallingEdgeHandler(void * voidPointer) {

	ViaEmptyvia * modulePointer = (ViaEmptyvia *) voidPointer;
	modulePointer->auxFallingEdgeCallback();

}
void buttonPressedHandler(void * voidPointer) {

	ViaEmptyvia * modulePointer = (ViaEmptyvia *) voidPointer;
	modulePointer->buttonPressedCallback();

}
void buttonReleasedHandler(void * voidPointer) {

	ViaEmptyvia * modulePointer = (ViaEmptyvia *) voidPointer;
	modulePointer->buttonReleasedCallback();

}
void adcConversionCompleteHandler(void * voidPointer) {

	ViaEmptyvia * modulePointer = (ViaEmptyvia *) voidPointer;
	modulePointer->slowConversionCallback();

}
void dacHalfTransferHandler(void * voidPointer) {

	ViaEmptyvia * modulePointer = (ViaEmptyvia *) voidPointer;
	modulePointer->halfTransferCallback();

}
void dacTransferCompleteHandler(void * voidPointer) {

	ViaEmptyvia * modulePointer = (ViaEmptyvia *) voidPointer;
	modulePointer->transferCompleteCallback();

}
void dacTimerHandler(void *) {
	;
}
void sdaadcConversionCompleteHandler(void *) {
	;
}

void auxTimer1InterruptHandler(void * voidPointer) {

	ViaEmptyvia * modulePointer = (ViaEmptyvia *) voidPointer;
	modulePointer->auxTimer1InterruptCallback();

}

void auxTimer2InterruptHandler(void * voidPointer) {

	ViaEmptyvia * modulePointer = (ViaEmptyvia *) voidPointer;
	modulePointer->auxTimer2InterruptCallback();

}
//@}
