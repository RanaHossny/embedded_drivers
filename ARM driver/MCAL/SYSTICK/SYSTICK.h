/********************************************************************************/
/**    File Name: SYSTICK.h                                                         */
/**                                                                             */
/**  Description: Implementation of the SYSTICK contain interfaces for the module   */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  STM32F401CCG6                                           */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2023 by Rana Hossny .       All rights reserved.              */
/**                                                                             */
/** This software is copyright protected and proprietary                        */
/** to ITI.                                                                     */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Company                              */
/** --------     ---------------------     -------------------------------------*/
/** Rana     Rana Hossny                 ain shams university.               */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 15/08/2023   0.1       Rana Hossny   Initial Creation                        */
/********************************************************************************/

#ifndef   SYSTICK_H
#define   SYSTICK_H
#include"../../LIB/STD_Types.h"

void MSTK_voidInit(void);

void MSTK_voidIntState(void);

void MSTK_voidStart(uint32 Copy_u8PreloadValue);

uint8 MSTK_u8ReadFlag(void);

void MSTK_voidDelayUsec(uint32 Copy_u8DelayUsec);

void MSTK_voidDelayMsec(uint32 Copy_u8DelayMsec);
void MSTK_voidDelaysec(uint32 Copy_u8Delaysec)

uint32 MSTK_u32GetElapsedTime(void);


uint32 MSTK_u32GetRemainingTime(void);
void CALLBACKSYS(void(*callback)(void));
void SysTick_Handler(void);



#endif

