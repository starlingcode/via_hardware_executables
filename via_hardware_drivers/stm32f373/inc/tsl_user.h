/*
 ******************************************************************************
 * File Name          : tsl_user.h.h
 * Description        : Touch-Sensing user configuration.
 ******************************************************************************
 * This notice applies to any and all portions of this file
 * that are not between comment pairs USER CODE BEGIN and
 * USER CODE END. Other portions of this file, whether 
 * inserted by the user or by software development tools
 * are owned by their respective copyright owners.
 *
 * Copyright (c) 2018 STMicroelectronics International N.V. 
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted, provided that the following conditions are met:
 *
 * 1. Redistribution of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of other 
 *    contributors to this software may be used to endorse or promote products 
 *    derived from this software without specific written permission.
 * 4. This software, including modifications and/or derivative works of this 
 *    software, must execute solely and exclusively on microcontroller or
 *    microprocessor devices manufactured by or for STMicroelectronics.
 * 5. Redistribution and use of this software other than as permitted under 
 *    this license is void and will automatically terminate your rights under 
 *    this license. 
 *
 * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
 * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
 * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
 * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TSL_USER_H
#define __TSL_USER_H

#include "tsl.h"
#include "stm32f3xx_hal.h"

/* Select if you use STMStudio software (0=No, 1=Yes) */
#define USE_STMSTUDIO (0)

#if USE_STMSTUDIO > 0
#include "stmCriticalSection.h"
#define STMSTUDIO_LOCK {enterLock();}
#define STMSTUDIO_UNLOCK {exitLock();}
#else
#define STMSTUDIO_LOCK
#define STMSTUDIO_UNLOCK
#endif

typedef enum {
	TSL_USER_STATUS_BUSY = 0, /**< The bank acquisition is on-going */
	TSL_USER_STATUS_OK_NO_ECS = 1, /**< The bank acquisition is ok, no time for ECS */
	TSL_USER_STATUS_OK_ECS_ON = 2, /**< The bank acquisition is ok, ECS finished */
	TSL_USER_STATUS_OK_ECS_OFF = 3 /**< The bank acquisition is ok, ECS not executed */
} tsl_user_status_t;

/* Channel IOs definition */
#define CHANNEL_0_IO_MSK    (TSC_GROUP5_IO4)
#define CHANNEL_0_GRP_MSK   (TSC_GROUP5)
#define CHANNEL_0_SRC       (TSC_GROUP5_IDX) /* Index in source register (TSC->IOGXCR[]) */
#define CHANNEL_0_DEST      (0) /* Index in destination result array */

#define CHANNEL_1_IO_MSK    (TSC_GROUP5_IO3)
#define CHANNEL_1_GRP_MSK   (TSC_GROUP5)
#define CHANNEL_1_SRC       (TSC_GROUP5_IDX) 
#define CHANNEL_1_DEST      (1) 

#define CHANNEL_2_IO_MSK    (TSC_GROUP5_IO1)
#define CHANNEL_2_GRP_MSK   (TSC_GROUP5)
#define CHANNEL_2_SRC       (TSC_GROUP5_IDX) 
#define CHANNEL_2_DEST      (2) 

#define CHANNEL_3_IO_MSK    (TSC_GROUP4_IO2)
#define CHANNEL_3_GRP_MSK   (TSC_GROUP4)
#define CHANNEL_3_SRC       (TSC_GROUP4_IDX) 
#define CHANNEL_3_DEST      (3) 

#define CHANNEL_4_IO_MSK    (TSC_GROUP6_IO3)
#define CHANNEL_4_GRP_MSK   (TSC_GROUP6)
#define CHANNEL_4_SRC       (TSC_GROUP6_IDX) 
#define CHANNEL_4_DEST      (4) 

#define CHANNEL_5_IO_MSK    (TSC_GROUP6_IO2)
#define CHANNEL_5_GRP_MSK   (TSC_GROUP6)
#define CHANNEL_5_SRC       (TSC_GROUP6_IDX) 
#define CHANNEL_5_DEST      (5) 

/* Shield IOs definition */
#define SHIELD_IO_MSK      (0)

/* Bank(s) definition */
/* TOUCHKEYS bank(s) definition*/
#define BANK_0_NBCHANNELS (1)
#define BANK_0_MSK_CHANNELS   (CHANNEL_0_IO_MSK)
#define BANK_0_MSK_GROUPS     (CHANNEL_0_GRP_MSK)

#define BANK_1_NBCHANNELS (1)
#define BANK_1_MSK_CHANNELS   (CHANNEL_1_IO_MSK)
#define BANK_1_MSK_GROUPS     (CHANNEL_1_GRP_MSK)

#define BANK_2_NBCHANNELS (3)
#define BANK_2_MSK_CHANNELS   (CHANNEL_2_IO_MSK | CHANNEL_3_IO_MSK | CHANNEL_4_IO_MSK)
#define BANK_2_MSK_GROUPS     (CHANNEL_2_GRP_MSK | CHANNEL_3_GRP_MSK | CHANNEL_4_GRP_MSK)

#define BANK_3_NBCHANNELS (1)
#define BANK_3_MSK_CHANNELS   (CHANNEL_5_IO_MSK)
#define BANK_3_MSK_GROUPS     (CHANNEL_5_GRP_MSK)

/* User Parameters */
extern CONST TSL_Bank_T MyBanks[];
extern CONST TSL_TouchKey_T MyTKeys[];
extern CONST TSL_Object_T MyObjects[];
extern TSL_ObjectGroup_T MyObjGroup;

void tsl_user_Init(void);

#ifdef __cplusplus
extern "C" {
#endif

tsl_user_status_t tsl_user_Exec(void);

#ifdef __cplusplus
}
#endif

void tsl_user_SetThresholds(void);

#endif /* __TSL_USER_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
