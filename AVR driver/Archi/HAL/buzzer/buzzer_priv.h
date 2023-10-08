/********************************************************************************/
/**    File Name: BUZZER.h                                                         */
/**                                                                             */
/**  Description: Implementation of the buzzer contain configuration for the module*/
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
/** SaraH    Sara Hossny Hassan         ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 22/08/2022   0.1       SaraH     Initial Creation                        */
/********************************************************************************/
#ifndef BUZZER_PRIV_H
#define BUZZER_PRIV_H
#define BR_u8NORMAL_1PIN            ((uint8) 0x0)
#define BR_u8NORMAL_2PIN            ((uint8) 0x1)
#define BR_u8REVERSE_1PIN           ((uint8) 0x2)
#define BR_u8REVERSE_2PIN           ((uint8) 0x3)

typedef struct{
	uint8 u8DioPinMap[];
	uint8 u8BUZZERModeConc;
}tstrPinMappingCfg ;

extern tstrPinMappingCfg BUZZER_astrBUZZERPinMapping[BUZZER_MAX_NUM];



