/********************************************************************************/
/**    File Name: USART_PRIV.h                                                   */
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
/** Rana    Rana Hossny         ITI.                                       */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 8/09/2022   0.1      Rana     Initial Creation                             */
 
/********************************************************************************/


#ifndef USART_PRIV_H
#define USART_PRIV_H
/* THE VALUES OF NUM STOP BITS      */
#define ONE_STOP_BIT       0
#define TWO_STOP_BIT       1
/*                                  */

/* THE VALUES OF NUM DATA BITS      */
#define FIVE_DATA_BIT        0
#define SIX_DATA_BIT         1
#define SEVEN_DATA_BIT       2
#define EIGHT_DATA_BIT       3
#define NINE_DATA_BIT        4
/*                                   */

/*        USART_MODE                 */
#define ASYNCHRONOUS         0
#define SYNCHRONOUS          1
/*                                   */
/*        PARITY_MODE                 */
#define PARITY_MODE_OFF           0
#define PARITY_MODE_ON_EVEN       1
#define PARITY_MODE_ON_ODD        2
/*                                   */

/*        CLOCK_POLARITY             */
#define RISING _TRANS_FALLING_RECEIV     0
#define FALLING _TRANS_RISING_RECEIV     1
/*                                   */

#define BAUD_RATE ((F_CPU)/(BAUD*16)-1)

#define UCSRA  *((volatile uint8 *)0x2B)
#define UCSRB  *((volatile uint8 *)0x2A)
#define UCSRC  *((volatile uint8 *)0x40)
#define URD  *((volatile uint8 *)0x2C)



#endif