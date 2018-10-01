/*
 * interrupt_link.cpp
 *
 *  Created on: Sep 15, 2018
 *      Author: willmitchell
 */

#include "interrupt_link.hpp"
#include "trigseq.hpp"

void linkInterrupts(ViaTrigseq * voidPointer) {

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

}

void uiTimerHandler(void * voidPointer) {

	ViaTrigseq * thisModule = (ViaTrigseq *) voidPointer;
	thisModule->ui_dispatch(TIMEOUT_SIG);

}
void mainRisingEdgeHandler(void * voidPointer) {

	ViaTrigseq * modulePointer = (ViaTrigseq *) voidPointer;
	modulePointer->mainRisingEdgeCallback();

}
void mainFallingEdgeHandler(void * voidPointer) {

	ViaTrigseq * modulePointer = (ViaTrigseq *) voidPointer;
	modulePointer->mainFallingEdgeCallback();

}
void auxRisingEdgeHandler(void * voidPointer) {

	ViaTrigseq * modulePointer = (ViaTrigseq *) voidPointer;
	modulePointer->auxRisingEdgeCallback();

}
void auxFallingEdgeHandler(void * voidPointer) {

	ViaTrigseq * modulePointer = (ViaTrigseq *) voidPointer;
	modulePointer->auxFallingEdgeCallback();

}
void buttonPressedHandler(void * voidPointer) {

	ViaTrigseq * modulePointer = (ViaTrigseq *) voidPointer;
	modulePointer->buttonPressedCallback();

}
void buttonReleasedHandler(void * voidPointer) {

	ViaTrigseq * modulePointer = (ViaTrigseq *) voidPointer;
	modulePointer->buttonReleasedCallback();

}
void adcConversionCompleteHandler(void * voidPointer) {

	ViaTrigseq * modulePointer = (ViaTrigseq *) voidPointer;
	modulePointer->slowConversionCallback();

}
void dacHalfTransferHandler(void * voidPointer) {

	ViaTrigseq * modulePointer = (ViaTrigseq *) voidPointer;
	modulePointer->halfTransferCallback();

}
void dacTransferCompleteHandler(void * voidPointer) {

	ViaTrigseq * modulePointer = (ViaTrigseq *) voidPointer;
	modulePointer->transferCompleteCallback();

}
void dacTimerHandler(void *) {
	;
}
void sdaadcConversionCompleteHandler(void *) {
	;
}

