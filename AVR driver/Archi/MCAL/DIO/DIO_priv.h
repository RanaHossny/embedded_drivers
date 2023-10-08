/********************************************************************************/
/**    File Name: DIO.h                                                         */
/**                                                                             */
/**  Description: Implementation of the DIO contain Private file for the module */
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
/** aaboelno     Ahmed Abo Elnour          ITI.                                 */
/** Rana         Rana Hossny                                                    */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 21/08/2022   0.1      aaboelno     Initial Creation                         */
/** 23/08/2022   0.2      Rana         add ensure code                          */
/********************************************************************************/

#ifndef   DIO_PRIV_H
#define   DIO_PRIV_H


#define DIO_OUTPUT           1     
#define DIO_INPUT            0

#define  DIO_u8PIN_SIZE               ((uint8 )8)
#define  DIO_u8MAX_NUMBER_OF_PINS     ((uint8 ) 32) 

#define ODRA  *((volatile uint8 *)0x3B)
#define ODRB  *((volatile uint8 *)0x38)
#define ODRC  *((volatile uint8 *)0x35)
#define ODRD  *((volatile uint8 *)0x32)

#define DDRA  *((volatile uint8 *)0x3A)
#define DDRB  *((volatile uint8 *)0x37)
#define DDRC  *((volatile uint8 *)0x34)
#define DDRD  *((volatile uint8 *)0x31)

#define IDRA  *((volatile uint8 *)0x39)
#define IDRB  *((volatile uint8 *)0x36)
#define IDRC  *((volatile uint8 *)0x33)
#define IDRD  *((volatile uint8 *)0x30)


#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)          CONC_MARCO(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_MARCO(b7,b6,b5,b4,b3,b2,b1,b0)    0b##b7##b6##b5##b4##b3##b2##b1##b0

#define CONC_ENSURE(DIO_u8DIR_PIN)          CONC_ENSURE_MARCO(DIO_u8DIR_PIN)
#define CONC_ENSURE_MARCO(DIO_u8DIR_PIN)    DIO_u8DIR_PIN##1


/** Secure Configuration file */
#ifdef DIO_u8DIR_PIN_0
#if CONC_ENSURE(DIO_u8DIR_PIN_0) ==1
#define DIO_u8DIR_PIN_0 DIO_INPUT 
#endif 
#endif

#ifndef DIO_u8DIR_PIN_0
#define DIO_u8DIR_PIN_0 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_1
#if CONC_ENSURE(DIO_u8DIR_PIN_1) ==1
#define DIO_u8DIR_PIN_1 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_1
#define DIO_u8DIR_PIN_1 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_2
#if CONC_ENSURE(DIO_u8DIR_PIN_2) ==1
#define DIO_u8DIR_PIN_2 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_2
#define DIO_u8DIR_PIN_2 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_3
#if CONC_ENSURE(DIO_u8DIR_PIN_3) ==1
#define DIO_u8DIR_PIN_3 DIO_INPUT 
#endif 
#endif

 
#ifndef DIO_u8DIR_PIN_3
#define DIO_u8DIR_PIN_3 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_4
#if CONC_ENSURE(DIO_u8DIR_PIN_4) ==1
#define DIO_u8DIR_PIN_4 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_4
#define DIO_u8DIR_PIN_4 DIO_INPUT 
#endif 
 
 #ifdef DIO_u8DIR_PIN_5
#if CONC_ENSURE(DIO_u8DIR_PIN_5) ==1
#define DIO_u8DIR_PIN_5 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_5
#define DIO_u8DIR_PIN_5 DIO_INPUT 
#endif 
 
 #ifdef DIO_u8DIR_PIN_6
#if CONC_ENSURE(DIO_u8DIR_PIN_6) ==1
#define DIO_u8DIR_PIN_6 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_6
#define DIO_u8DIR_PIN_6 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_7
#if CONC_ENSURE(DIO_u8DIR_PIN_7) ==1
#define DIO_u8DIR_PIN_7 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_7
#define DIO_u8DIR_PIN_7 DIO_INPUT 
#endif 
 
 #ifdef DIO_u8DIR_PIN_8
#if CONC_ENSURE(DIO_u8DIR_PIN_8) ==1
#define DIO_u8DIR_PIN_8 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_8
#define DIO_u8DIR_PIN_8 DIO_INPUT 
#endif 
 
 #ifdef DIO_u8DIR_PIN_9
#if CONC_ENSURE(DIO_u8DIR_PIN_9) ==1
#define DIO_u8DIR_PIN_9 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_9
#define DIO_u8DIR_PIN_9 DIO_INPUT 
#endif 
 
#ifdef DIO_u8DIR_PIN_10
#if CONC_ENSURE(DIO_u8DIR_PIN_10) ==1
#define DIO_u8DIR_PIN_10 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_10
#define DIO_u8DIR_PIN_10 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_11
#if CONC_ENSURE(DIO_u8DIR_PIN_11) ==1
#define DIO_u8DIR_PIN_11 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_11
#define DIO_u8DIR_PIN_11 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_12
#if CONC_ENSURE(DIO_u8DIR_PIN_12) ==1
#define DIO_u8DIR_PIN_12 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_12
#define DIO_u8DIR_PIN_12 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_13
#if CONC_ENSURE(DIO_u8DIR_PIN_13) ==1
#define DIO_u8DIR_PIN_13 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_13
#define DIO_u8DIR_PIN_13 DIO_INPUT 
#endif 
 
 #ifdef DIO_u8DIR_PIN_14
#if CONC_ENSURE(DIO_u8DIR_PIN_14) ==1
#define DIO_u8DIR_PIN_14 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_14
#define DIO_u8DIR_PIN_14 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_15
#if CONC_ENSURE(DIO_u8DIR_PIN_15) ==1
#define DIO_u8DIR_PIN_15 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_15
#define DIO_u8DIR_PIN_15 DIO_INPUT 
#endif 
 
 #ifdef DIO_u8DIR_PIN_16
#if CONC_ENSURE(DIO_u8DIR_PIN_16) ==1
#define DIO_u8DIR_PIN_16 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_16
#define DIO_u8DIR_PIN_16 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_17
#if CONC_ENSURE(DIO_u8DIR_PIN_17) ==1
#define DIO_u8DIR_PIN_17 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_17
#define DIO_u8DIR_PIN_17 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_18
#if CONC_ENSURE(DIO_u8DIR_PIN_18) ==1
#define DIO_u8DIR_PIN_18 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_18
#define DIO_u8DIR_PIN_18 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_19
#if CONC_ENSURE(DIO_u8DIR_PIN_19) ==1
#define DIO_u8DIR_PIN_19 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_19
#define DIO_u8DIR_PIN_19 DIO_INPUT 
#endif 
 
#ifdef DIO_u8DIR_PIN_20
#if CONC_ENSURE(DIO_u8DIR_PIN_20) ==1
#define DIO_u8DIR_PIN_20 DIO_INPUT 
#endif 
#endif

#ifndef DIO_u8DIR_PIN_20
#define DIO_u8DIR_PIN_20 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_21
#if CONC_ENSURE(DIO_u8DIR_PIN_21) ==1
#define DIO_u8DIR_PIN_21 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_21
#define DIO_u8DIR_PIN_21 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_22
#if CONC_ENSURE(DIO_u8DIR_PIN_22) ==1
#define DIO_u8DIR_PIN_22 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_22
#define DIO_u8DIR_PIN_22 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_23
#if CONC_ENSURE(DIO_u8DIR_PIN_23) ==1
#define DIO_u8DIR_PIN_23 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_23
#define DIO_u8DIR_PIN_23 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_24
#if CONC_ENSURE(DIO_u8DIR_PIN_24) ==1
#define DIO_u8DIR_PIN_24 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_24
#define DIO_u8DIR_PIN_24 DIO_INPUT 
#endif 
 
 #ifdef DIO_u8DIR_PIN_25
#if CONC_ENSURE(DIO_u8DIR_PIN_25) ==1
#define DIO_u8DIR_PIN_25 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_25
#define DIO_u8DIR_PIN_25 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_26
#if CONC_ENSURE(DIO_u8DIR_PIN_26) ==1
#define DIO_u8DIR_PIN_26 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_26
#define DIO_u8DIR_PIN_26 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_27
#if CONC_ENSURE(DIO_u8DIR_PIN_27) ==1
#define DIO_u8DIR_PIN_27 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_27
#define DIO_u8DIR_PIN_27 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_28
#if CONC_ENSURE(DIO_u8DIR_PIN_28) ==1
#define DIO_u8DIR_PIN_28 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_28
#define DIO_u8DIR_PIN_28 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_29
#if CONC_ENSURE(DIO_u8DIR_PIN_29) ==1
#define DIO_u8DIR_PIN_29 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_29
#define DIO_u8DIR_PIN_29 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_30
#if CONC_ENSURE(DIO_u8DIR_PIN_30) ==1
#define DIO_u8DIR_PIN_30 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_30
#define DIO_u8DIR_PIN_30 DIO_INPUT 
#endif 

#ifdef DIO_u8DIR_PIN_31
#if CONC_ENSURE(DIO_u8DIR_PIN_31) ==1
#define DIO_u8DIR_PIN_31 DIO_INPUT 
#endif 
#endif
 
#ifndef DIO_u8DIR_PIN_31
#define DIO_u8DIR_PIN_31 DIO_INPUT 
#endif 
 

#endif



