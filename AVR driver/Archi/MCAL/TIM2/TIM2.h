/********************************************************************************/
/**    File Name: TIM2.h                                                         */
/**                                                                             */
/**  Description: Implementation of the TIM2 contain configuration for the module*/
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  Atmega 32                                               */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2022 by ITI .       All rights reserved.                      */
/**                                                                             */
/** This software is copyright protected and proprietary                        */
/** to ITI.                                                                     */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Company                              */
/** --------     ---------------------     -------------------------------------*/
/** Rana    Rana Hossny         ITI.                                       */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 22/08/2022   0.1      Rana     Initial Creation                             */
 
/********************************************************************************/
#ifndef TIM2_H
#define TIM2_H

void TIM2_voidInit(void);
void TIM2_voidSetPreloadValue (uint8 u8PreloadValueCpy);
void TIM2_voidSetOutputCompareValue (uint8 u8LoadValueCpy);
void TIM2_voidEnableOVFIntterrupt(void);
void TIM2_voidDisableOVFIntterrupt(void);
void TIM2_voidEnableCTCIntterrupt(void);
void TIM2_voidDisableCTCIntterrupt(void);
void TIM2_voidSetOvfCallback(pf pfOvfCallbackCpy);
void TIM2_voidSetCtcCallback(pf pfCtcCallbackCpy);
uint16 TIM2_u16GetCntrValue(void );
void TIM2_voidDelay_us(uint32 u32DalayTimeCpy);
void TIM0_voidDelay_Init(void);
void TIM2_voidDelay_ms(uint32 u32DalayTimeCpy);

#endif