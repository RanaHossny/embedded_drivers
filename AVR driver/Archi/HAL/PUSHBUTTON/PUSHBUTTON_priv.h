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
/** aaboelno     Rana Hossny         ITI.                                       */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 22/08/2022   0.1      Rana     Initial Creation                             */
 
/********************************************************************************/
#ifndef PUSHBUTTON_PRIV_H
#define PUSHBUTTON_PRIV_H

#define   PULLUP_CONNECTION        ((uint8) 1)
#define   PULLDOWN_CONNECTION       ((uint8) 0)

typedef struct{
	uint8 u8DioPinMap;
	uint8 u8PUSHBUTTIONModeConc;
}tstrPinMappingCfg ;

extern tstrPinMappingCfg PUSHBUTTION_astrPUSHBUTTIONPinMapping[PUSHBUTTON_MAX_NUM];





#endif
