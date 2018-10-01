/*
 * interrupt_link.cpp
 *
 *  Created on: Sep 15, 2018
 *      Author: willmitchell
 */

#include "interrupt_link.hpp"
#include "sync.hpp"

void linkInterrupts(ViaSync * voidPointer) {

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

}

void uiTimerHandler(void * voidPointer) {

	ViaSync * modulePointer = (ViaSync *) voidPointer;
	modulePointer->ui_dispatch(TIMEOUT_SIG);

}
void mainRisingEdgeHandler(void * voidPointer) {

	ViaSync * modulePointer = (ViaSync *) voidPointer;
	modulePointer->mainRisingEdgeCallback();

}
void mainFallingEdgeHandler(void * voidPointer) {

	ViaSync * modulePointer = (ViaSync *) voidPointer;
	modulePointer->mainFallingEdgeCallback();

}
void auxRisingEdgeHandler(void * voidPointer) {

	ViaSync * modulePointer = (ViaSync *) voidPointer;
	modulePointer->auxRisingEdgeCallback();

}
void auxFallingEdgeHandler(void * voidPointer) {

	ViaSync * modulePointer = (ViaSync *) voidPointer;
	modulePointer->auxFallingEdgeCallback();

}
void buttonPressedHandler(void * voidPointer) {

	ViaSync * modulePointer = (ViaSync *) voidPointer;
	modulePointer->buttonPressedCallback();

}
void buttonReleasedHandler(void * voidPointer) {

	ViaSync * modulePointer = (ViaSync *) voidPointer;
	modulePointer->buttonReleasedCallback();

}
void adcConversionCompleteHandler(void * voidPointer) {

	ViaSync * modulePointer = (ViaSync *) voidPointer;
	modulePointer->slowConversionCallback();

}
void dacHalfTransferHandler(void * voidPointer) {

	ViaSync * modulePointer = (ViaSync *) voidPointer;
	modulePointer->halfTransferCallback();

}
void dacTransferCompleteHandler(void * voidPointer) {

	ViaSync * modulePointer = (ViaSync *) voidPointer;
	modulePointer->transferCompleteCallback();

}
void dacTimerHandler(void *) {
	;
}
void sdaadcConversionCompleteHandler(void *) {
	;
}

