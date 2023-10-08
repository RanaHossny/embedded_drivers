/********************************************************************************/
/**    File Name: EXTINT1.h                                                     */
/**                                                                             */
/**  Description: Implementation of the external interrupt 1                    */
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
#ifndef EXTINT1_H
#define EXTINT1_H


void EXTINT1_voidInit(void);

void EXTINT1_voidEnable(void);

void EXTINT1_voidDisable(void);

void EXTINT1_voidSetCallBack(pf pfCallbackCpy);

void EXTINT1_voidSetSenseValue(uint8 u8SenseValueCpy);


#endif

