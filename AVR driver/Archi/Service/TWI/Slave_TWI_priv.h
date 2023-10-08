/********************************************************************************/
/**    File Name: SLAVE_TWI_PRIV.h                                                   */
/**                                                                             */
/**  Description: Implementation of the SPI contain configuration for the module*/
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
/** 14/09/2022   0.1      Rana     Initial Creation                             */
 
/********************************************************************************/


#ifndef SLAVE_TWI_PRIV_H
#define SLAVE_TWI_PRIV_H


						    
#define TWEN                 ((uint8)2)
#define TWSTA                ((uint8)5)
#define TWSTO                ((uint8)4)
#define TWEA                 ((uint8)6)
#define TWINT                ((uint8)7)




#define TWCR                 *((volatile uint8 *)0x56)
#define TWDR                 *((volatile uint8 *)0x23)
#define TWAR                 *((volatile uint8 *)0x22)
#define TWSR                 *((volatile uint8 *)0x21)
#define TWBR                 *((volatile uint8 *)0x20)




#endif
