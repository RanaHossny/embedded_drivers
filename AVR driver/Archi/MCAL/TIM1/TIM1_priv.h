/********************************************************************************/
/**    File Name: TIM1_priv.h                                                         */
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



#ifndef TIM1_PRIV_H
#define TIM1_PRIV_H
/* TIMER1 GENERATION WAVE MODE */
#define  TIM1_NORMAL_MODE                        0 
#define  TIM1_PWM_PHASE_CORRECT_8_BIT            1
#define  TIM1_PWM_PHASE_CORRECT_9_BIT            2
#define  TIM1_PWM_PHASE_CORRECT_10_BIT           3
#define  TIM1_CLC_OCR1A_MODE                     4
										         
#define  TIM1_FAST_PWM_8_BIT                     5
#define  TIM1_FAST_PWM_9_BIT                     6
#define  TIM1_FAST_PWM_10_BIT                    7
#define  TIM1_PWM_PHASE_FREQ_CORRECT_ICR1        8 
#define  TIM1_PWM_PHASE_FREQ_CORRECT_OCR1A       9
#define  TIM1_PWM_PHASE_CORRECT_ICR1             10
#define  TIM1_PWM_PHASE_CORRECT_OCR1A            11
#define  TIM1_CLC_ ICR1_MODE                     12 
#define  TIM1_FAST_ICR1_PWM                      14
#define   TIM1_FAST_ OCR1A_PWM                   15
/*                                               */            
/*           clock selection                     */            
#define TIM1_NO_CLK_SRC                           0
#define TIM1_NO_PRESCALLER                        1
#define TIM1_PRESCALLER_8                         2
#define TIM1_PRESCALLER_64                        3
#define TIM1_PRESCALLER_256                       4
#define TIM1_PRESCALLER_1024                      5
#define TIM1_EXT_CLK_SRC_FALLING_EDGE             6
#define TIM1_EXT_CLK_SRC_RISING_EDGE              7
/*                                                */            
/* Output Mode                                    */
#define   NON_PWM_MODE                                             0
#define   FAST_PWM_MODE                                            1 
#define   Phase_CORRECT_AND_PHASE_AND_FREQ_CORRECT_PWM             2

/*          COMPARE_OUTPUT_MODE                    */
#define    OC1A_OR_OC1B_DISCONNECTED                                                                0
#define    TOGGLE_OC1A_OR_OC1B_ON_COMPARE_MATCH                                                     1
#define    CLEAR_OC1A_OR_OC1B_ON_COMPARE_MATCH                                                      2
#define    SET_OC1A_OR_OC1B_ON_COMPARE_MATCH                                                        3
#define    TOGGLE_OC1A_ON_COMPARE_MATCH_OC1B_DISCONNECTED                                           4
#define    CLEAR_OC1A_OR_OC1B_ON_COMPARE_MATCH_SET_OC1A_OR_OC1B_AT_TOP                              5
#define    SET_OC1A_OR_OC1B_ON_COMPARE_MATCH_CLEAR_OC1A_OR_OC1B_AT_TOP                              6
#define    CLEAR_OC1A_OR_OC1B_ON_COMPARE_UPCOUNTING_SET_OC1A_OR_OC1B_ON_COMPARE_MATCH_DOWNCOUNTING  7
#define    SET_OC1A_OR_OC1B_ON_COMPARE_UPCOUNTING_CLEAR_OC1A_OR_OC1B_ON_COMPARE_MATCH_DOWNCOUNTING  8

/*                                                   */



#define  TCCR1A      *((volatile uint8 *) 0x4F )
#define  TCCR1B      *((volatile uint8 *) 0x4E )
#define  TCNT1H      *((volatile uint8 *) 0x4D )
#define  TCNT1L      *((volatile uint8 *) 0x4C )
#define  OCR1AH      *((volatile uint8 *) 0x4B )
#define  OCR1AL      *((volatile uint8 *) 0x4A )
#define  OCR1BH      *((volatile uint8 *) 0x49 )
#define  OCR1BL      *((volatile uint8 *) 0x48 )
#define TIMSK        *((volatile uint8 *) 0x59 )
#define TIFR         *((volatile uint8 *) 0x58 )
#define ICR1L        *((volatile uint8 *) 0x46 )
#define ICR1H        *((volatile uint8 *) 0x47 )

#define CHANNELA          ((uint8)0)
#define CHANNELB          ((uint8)1)



#endif 