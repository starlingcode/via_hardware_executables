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

extern void * modulePointer;

extern void (*tscTimerCallback)(void*);
extern void (*uiTimerCallback)(void*);
extern void (*mainRisingEdgeCallback)(void*);
extern void (*mainFallingEdgeCallback)(void*);
extern void (*auxRisingEdgeCallback)(void*);
extern void (*auxFallingEdgeCallback)(void*);
extern void (*buttonPressedCallback)(void*);
extern void (*buttonReleasedCallback)(void*);
extern void (*adcConversionCompleteCallback)(void*);
extern void (*dacHalfTransferCallback)(void*);
extern void (*dacTransferCompleteCallback)(void*);
extern void (*dacTimerCallback)(void*);
extern void (*sdaadcConversionCompleteCallback)(void*);
extern void (*auxTimer1InterruptCallback)(void*);
extern void (*auxTimer2InterruptCallback)(void*);
extern void (*auxTimer3InterruptCallback)(void*);


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
void sdaadcConversionCompleteHandler(void *);
void auxTimer1InterruptHandler(void *);
void auxTimer2InterruptHandler(void *);
void auxTimer3InterruptHandler(void *);



#endif /* INTERRUPT_LINK_HPP_ */
