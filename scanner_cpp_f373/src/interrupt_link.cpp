/*
 * interrupt_link.cpp
 *
 *  Created on: Sep 15, 2018
 *      Author: willmitchell
 */

#include "interrupt_link.hpp"
#include "scanner.hpp"

void linkInterrupts(ViaScanner * voidPointer) {

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
	cv2HalfTransferCallback = &cv2HalfTransferHandler;
	cv2TransferCompleteCallback = &cv2TransferCompleteHandler;
	cv3HalfTransferCallback = &cv3HalfTransferHandler;
	cv3TransferCompleteCallback = &cv3TransferCompleteHandler;
	adcConversionCompleteCallback = &adcConversionCompleteHandler;

}

void uiTimerHandler(void * voidPointer) {

	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->ui_dispatch(TIMEOUT_SIG);

}
void mainRisingEdgeHandler(void * voidPointer) {

	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->mainRisingEdgeCallback();

}
void mainFallingEdgeHandler(void * voidPointer) {

	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->mainFallingEdgeCallback();

}
void auxRisingEdgeHandler(void * voidPointer) {

	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->auxRisingEdgeCallback();

}
void auxFallingEdgeHandler(void * voidPointer) {

	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->auxFallingEdgeCallback();

}
void buttonPressedHandler(void * voidPointer) {

	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->buttonPressedCallback();

}
void buttonReleasedHandler(void * voidPointer) {

	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->buttonReleasedCallback();

}
void adcConversionCompleteHandler(void * voidPointer) {

	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->slowConversionCallback();

}
void dacHalfTransferHandler(void * voidPointer) {

	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->halfTransferCallback();

}
void dacTransferCompleteHandler(void * voidPointer) {

	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->transferCompleteCallback();

}
void dacTimerHandler(void * voidPointer) {
	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->ioProcessCallback();
}
void cv2HalfTransferHandler(void * voidPointer) {
	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->cv2HalfTransferCallback();
}
void cv2TransferCompleteHandler(void * voidPointer) {
	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->cv2TransferCompleteCallback();
}
void cv3HalfTransferHandler(void * voidPointer) {
	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->cv3HalfTransferCallback();
}
void cv3TransferCompleteHandler(void * voidPointer) {
	ViaScanner * modulePointer = (ViaScanner *) voidPointer;
	modulePointer->cv3TransferCompleteCallback();
}

