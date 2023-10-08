/********************************************************************************/
/**    File Name: KEYPAD.h                                                      */
/**                                                                             */
/**  Description: Implementation of the LED contain configuration for the module*/
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
/** Rana          Rana Hossny         ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 22/08/2022   0.1       aaboelno     Initial Creation                        */
/** 22/08/2022   0.2       Rana     Initial Creation_update                     */
/********************************************************************************/
#ifndef KEYPAD_PRIV_H
#define KEYPAD_PRIV_H

extern uint8 * array [KEYPAD_MAX_NUM];


typedef struct{
	uint8 au8InputPins [KEYPAD_u8INPUT_PINS_MAX_NUM];
	uint8 au8OutputPins[KEYPAD_u8OUTPUT_PINS_MAX_NUM];
	uint8 u8InputPinNum;
	uint8 u8OutputPinNum;
    uint8  u8modeconnection;
}tstrKeypadCfg;

#define  ROW_INPUT_COLOUNM_OUTPUT     ((uint8)1)
#define  ROW_OUTPUT_COLOUNM_INPUT     ((uint8)0)


extern tstrKeypadCfg KEYPAD_astrPinCfg [KEYPAD_MAX_NUM];

#endif




