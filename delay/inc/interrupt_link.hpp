 /** \file interrupt_link.hpp
 * \brief Interrupt handler callback declarations.
 *
 * Declare the anonymous callback function pointers and functions that will be assigned to them.
 *
 */

#ifndef INTERRUPT_LINK_HPP_
#define INTERRUPT_LINK_HPP_

#ifdef __cplusplus
extern "C" {
#endif

/// This is used as an anonymous pointer to the main module class instance so it can be referenced in C code.
void * modulePointer;

//@{
/// A callback function to allow C code to call methods of the main module class by passing in the modulePointer void pointer.
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
//@}



#ifdef __cplusplus
}
#endif

//@{
/// A function implementation to be assigned to the appropriate callback.
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
//@}




#endif /* INTERRUPT_LINK_HPP_ */
