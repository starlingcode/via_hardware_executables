/*
 * interrupt_link.cpp
 *
 *  Created on: Sep 15, 2018
 *      Author: willmitchell
 */

#include "interrupt_link.hpp"
#include "calib.hpp"

void linkInterrupts(ViaCalib * voidPointer) {

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

void uiTimerHandler(void * voidPointer) {

	ViaCalib * modulePointer = (ViaCalib *) voidPointer;
	modulePointer->ui_dispatch(TIMEOUT_SIG);

}
void mainRisingEdgeHandler(void * voidPointer) {

	ViaCalib * modulePointer = (ViaCalib *) voidPointer;
	modulePointer->mainRisingEdgeCallback();

}
void mainFallingEdgeHandler(void * voidPointer) {

	ViaCalib * modulePointer = (ViaCalib *) voidPointer;
	modulePointer->mainFallingEdgeCallback();

}
void auxRisingEdgeHandler(void * voidPointer) {

	ViaCalib * modulePointer = (ViaCalib *) voidPointer;
	modulePointer->auxRisingEdgeCallback();

}
void auxFallingEdgeHandler(void * voidPointer) {

	ViaCalib * modulePointer = (ViaCalib *) voidPointer;
	modulePointer->auxFallingEdgeCallback();

}
void buttonPressedHandler(void * voidPointer) {

	ViaCalib * modulePointer = (ViaCalib *) voidPointer;
	modulePointer->buttonPressedCallback();

}
void buttonReleasedHandler(void * voidPointer) {

	ViaCalib * modulePointer = (ViaCalib *) voidPointer;
	modulePointer->buttonReleasedCallback();

}
void adcConversionCompleteHandler(void * voidPointer) {

	ViaCalib * modulePointer = (ViaCalib *) voidPointer;
	modulePointer->slowConversionCallback();

}
void dacHalfTransferHandler(void * voidPointer) {

	ViaCalib * modulePointer = (ViaCalib *) voidPointer;
	modulePointer->halfTransferCallback();

}
void dacTransferCompleteHandler(void * voidPointer) {

	ViaCalib * modulePointer = (ViaCalib *) voidPointer;
	modulePointer->transferCompleteCallback();

}
void dacTimerHandler(void *) {
	;
}
void sdaadcConversionCompleteHandler(void *) {
	;
}

void auxTimer1InterruptHandler(void * voidPointer) {

	ViaCalib * modulePointer = (ViaCalib *) voidPointer;
	modulePointer->auxTimer1InterruptCallback();

}

void auxTimer2InterruptHandler(void * voidPointer) {

	ViaCalib * modulePointer = (ViaCalib *) voidPointer;
	modulePointer->auxTimer2InterruptCallback();

}
