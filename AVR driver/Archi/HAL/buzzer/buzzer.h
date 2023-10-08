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
#ifndef BUZZER_H
#define BUZZER_H

#include "BUZZER_cfg.h"

#define BUZZER_u8ON    ((uint8) 0x01)
#define BUZZER_u8OFF   ((uint8) 0x00)


tenuErrorStatus BUZZER_enuWriteValue (uint8 u8BUZZERNumCpy , uint8 u8BUZZERValueCpy);




#endif

















BUZZER_enuWriteValue(,BUZZER_u8ON);





