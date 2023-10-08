/********************************************************************************/
/**    File Name: LED.h                                                         */
/**                                                                             */
/**  Description: Implementation of the LED contain configuration for the module*/
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  STM32F401CCG6                                           */
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
/** Rana     Rana Hossny         ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 22/08/2023   0.1       Rana     Initial Creation                        */
/********************************************************************************/
#ifndef LED_H
#define LED_H

#include "LED_cfg.h"
#include "../../LIB/STD_Types.h"
/* LED_MODE_Connection : Select one option
LED_u8NORMAL
LED_u8REVERSE
*/
/*
u8_LED_Mode : Select one option 
LED_u8ON
LED_u8OFF
*/
tenuErrorStatus LED_enuWriteValue (uint8 u8_PortId,uint8 u8_PinNo, uint8 LED_MODE_Connection , uint8 u8_LED_Mode);
void LED_enuToggle (uint8 u8_PortId,uint8 u8_PinNo);




#endif









