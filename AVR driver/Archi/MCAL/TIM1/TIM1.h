/********************************************************************************/
/**    File Name: TIM1.h                                                         */
/**                                                                             */
/**  Description: Implementation of the TIM1 contain configuration for the module*/
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

#ifndef TIM1_H
#define TIM1_H

void TIM1_voidInit(void);
void TIM1_voidSetPreloadValue (uint16 u16PreloadValueCpy);
void TIM1_voidSetOutputCompareValue (uint16 u16LoadValueCpy,uint8 u8ChannelSlctCpy);
void TIM1_voidSetOutputCompare2Value (uint16 u16LoadValue0Cpy,uint16 u16LoadValue1Cpy);
void TIM1_voidEnableOVFInterrupt(void);
void TIM1_voidDisableOVFInterrupt(void);
void TIM1_voidEnableCTC_A_Interrupt(void);
void TIM1_voidEnableCTC_B_Interrupt(void);
void TIM1_voidDisableCTC_A_Interrupt(void);
void TIM1_voidDisableCTC_B_Interrupt(void);
void TIM1_voidEnable_Input Capture_Interrupt(void);
void TIM1_voidDisable_Input Capture_Interrupt(void);
void TIM1_voidSetOvfCallback(pf pfOvfCallbackCpy);
void TIM1_voidSetCtcCall_A_back(pf pfCtcCallbackCpy);
void TIM1_voidSetCtcCall_B_back(pf pfCtcCallbackCpy);
void TIM1_voidSetCptr_EvntCall__back(pf pfCptrCallbackCpy);
uint16 TIM1_u16GetCntrValue(void );
void enable_noise_cancel_void(void);
void disable_noise_cancel_void();
void ICUM_voidGetFreqDuty(float32 * pf32FreqCpy , float32 *f32DutyCpy);
void input_capture_init_void(void);
void TIM1_voidDelay_us(uint32 u32DalayTimeCpy);
void TIM1_voidDelay_Init(void);
void TIM1_voidDelay_ms(uint32 u32DalayTimeCpy);

#endif