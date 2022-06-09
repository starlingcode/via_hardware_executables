/*
 * interrupt_link.cpp
 *
 *  Created on: Sep 15, 2018
 *      Author: willmitchell
 */

#include "interrupt_link.hpp"
#include "gateseq.hpp"

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

void linkInterrupts(ViaGateseq * voidPointer) {

	modulePointer = (void *) voidPointer;

	uiTimerCallback = &uiTimerHandler;
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
	auxTimer3InterruptCallback = &auxTimer3InterruptHandler;

}

void uiTimerHandler(void * voidPointer) {

	ViaGateseq * thisModule = (ViaGateseq *) voidPointer;
	thisModule->ui_dispatch(TIMEOUT_SIG);

}
void mainRisingEdgeHandler(void * voidPointer) {

	ViaGateseq * modulePointer = (ViaGateseq *) voidPointer;
	modulePointer->mainRisingEdgeCallback();

}
void mainFallingEdgeHandler(void * voidPointer) {

	ViaGateseq * modulePointer = (ViaGateseq *) voidPointer;
	modulePointer->mainFallingEdgeCallback();

}
void auxRisingEdgeHandler(void * voidPointer) {

	ViaGateseq * modulePointer = (ViaGateseq *) voidPointer;
	modulePointer->auxRisingEdgeCallback();

}
void auxFallingEdgeHandler(void * voidPointer) {

	ViaGateseq * modulePointer = (ViaGateseq *) voidPointer;
	modulePointer->auxFallingEdgeCallback();

}
void buttonPressedHandler(void * voidPointer) {

	ViaGateseq * modulePointer = (ViaGateseq *) voidPointer;
	modulePointer->buttonPressedCallback();

}
void buttonReleasedHandler(void * voidPointer) {

	ViaGateseq * modulePointer = (ViaGateseq *) voidPointer;
	modulePointer->buttonReleasedCallback();

}
void adcConversionCompleteHandler(void * voidPointer) {

	ViaGateseq * modulePointer = (ViaGateseq *) voidPointer;
	modulePointer->slowConversionCallback();

}
void dacHalfTransferHandler(void * voidPointer) {

	ViaGateseq * modulePointer = (ViaGateseq *) voidPointer;
	modulePointer->halfTransferCallback();

}
void dacTransferCompleteHandler(void * voidPointer) {

	ViaGateseq * modulePointer = (ViaGateseq *) voidPointer;
	modulePointer->transferCompleteCallback();

}
void dacTimerHandler(void *) {
	;
}
void sdaadcConversionCompleteHandler(void *) {
	;
}
void auxTimer1InterruptHandler(void * voidPointer) {

	ViaGateseq * modulePointer = (ViaGateseq *) voidPointer;
	modulePointer->auxTimer1InterruptCallback();

}
void auxTimer2InterruptHandler(void * voidPointer) {

	ViaGateseq * modulePointer = (ViaGateseq *) voidPointer;
	modulePointer->auxTimer2InterruptCallback();

}
void auxTimer3InterruptHandler(void * voidPointer) {

	ViaGateseq * modulePointer = (ViaGateseq *) voidPointer;
	modulePointer->auxTimer3InterruptCallback();

}

