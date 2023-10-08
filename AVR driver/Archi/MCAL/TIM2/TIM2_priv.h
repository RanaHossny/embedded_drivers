/********************************************************************************/
/**    File Name: TIM2_priv.h                                                         */
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
#ifndef TIM2_PRIV_H
#define TIM2_PRIV_H

#define  TIM2_NORMAL_MODE                0 
#define  TIM2_PWM_PHASE_CORRECT_MODE     1
#define  TIM2_CTC_MODE                   2
#define  TIM2_FAST_PWM_MODE              3

#define TIM2_NO_CLK_SRC                  0
#define TIM2_NO_PRESCALLER               1
#define TIM2_PRESCALLER_8                2
#define TIM2_PRESCALLER_64               3
#define TIM2_PRESCALLER_256              4
#define TIM2_PRESCALLER_1024             5
#define TIM2_EXT_CLK_SRC_FALLING_EDGE    6
#define TIM2_EXT_CLK_SRC_RISING_EDGE     7

#define TCNT2     *((volatile uint8 *) 0x )
#define OCR2      *((volatile uint8 *) 0x )
#define TCCR2     *((volatile uint8 *) 0x )
#define TIMSK     *((volatile uint8 *) 0x59 )
#define TIFR      *((volatile uint8 *) 0x58 )

#endif 