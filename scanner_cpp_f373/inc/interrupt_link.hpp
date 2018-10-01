/*
 * interrupt_link.hpp
 *
 *  Created on: Sep 15, 2018
 *      Author: willmitchell
 */

#ifndef INTERRUPT_LINK_HPP_
#define INTERRUPT_LINK_HPP_

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
void (*cv2HalfTransferCallback)(void*);
void (*cv2TransferCompleteCallback)(void*);
void (*cv3HalfTransferCallback)(void*);
void (*cv3TransferCompleteCallback)(void*);

#ifdef __cplusplus
}
#endif

void tscTimerHandler(void *);
void uiTimerHandler(void *);
void mainRisingEdgeHandler(void *);
void mainFallingEdgeHandler(void *);
void auxRisingEdgeHandler(void *);
void auxFallingEdgeHandler(void *);
void buttonPressedHandler(void *);
void buttonReleasedHandler(void *);
void adcConversionCompleteHandler(void*);
void dacHalfTransferHandler(void *);
void dacTransferCompleteHandler(void *);
void dacTimerHandler(void *);
void cv2HalfTransferHandler(void*);
void cv2TransferCompleteHandler(void*);
void cv3HalfTransferHandler(void*);
void cv3TransferCompleteHandler(void*);


#endif /* INTERRUPT_LINK_HPP_ */
