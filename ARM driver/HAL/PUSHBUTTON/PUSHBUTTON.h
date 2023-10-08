/********************************************************************************/
/**    File Name: PUSHBUTTON.h                                                         */
/**                                                                             */
/**  Description: Implementation of the PUSHBUTTON contain configuration for the module*/
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
/** 14/08/2023   0.1      Rana     Initial Creation                             */
 
/********************************************************************************/
 /* Gaurd */
#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#define  PUSHBUTTON_PRESSED    ((uint8) 1)
#define  PUSHBUTTON_NOT_PRESSED    ((uint8) 0)

#include "PUSHBUTTON_cfg.h"

tenuErrorStatus pushbutton_intial();

tenuErrorStatus pushbutton_enureadState (uint8 u8PUSHBUTTONNumCpy , uint8 * u8PUSHBUTTONValueCpy);




#endif








