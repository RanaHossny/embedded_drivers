/********************************************************************************/
/**    File Name: USART_CFG.h                                                   */
/**                                                                             */
/**  Description: Implementation of the USART contain configuration for the module*/
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
/** Rana    Rana Hossny         ITI.                                            */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 8/09/2022   0.1      Rana     Initial Creation                              */
 
/********************************************************************************/

#ifndef USART_CFG_H
#define USART_CFG_H
#define USART_MODE                      ASYNCHRONOUS 

#define STOP_BITS_NUM                   ONE_STOP_BIT
#define DATA_BITS_NUM                   EIGHT_DATA_BIT
#define PARITY_MODE                     PARITY_MODE_OFF
/*    THIS CONG FOR ASYN MODE ONLY            */
#define  BAUD                       9600
#define  F_CPU                      1600
/*                                            */
/*    THIS CONG FOR SYN MODE ONLY             */

#define  CLOCK_POLARITY                  FALLING _TRANS_RISING_RECEIV  
/*                                            */



#endif
