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
#include "STD_Types.h"

#include "DIO.h"

#include "BUZZER_cfg.h"
#include "BUZZER_priv.h"

tstrPinMappingCfg BUZZER_astrBUZZERPinMapping[BUZZER_MAX_NUM]={
	
	{{DIO_u8PIN_0}  , BR_u8NORMAL_1PIN },
	{{DIO_u8PIN_1}  ,BR_u8NORMAL_1PIN },
	{{DIO_u8PIN_2,DIO_u8PIN_3} , BR_u8NORMAL_2PIN },
	{{DIO_u8PIN_4} , BR_u8NORMAL_1PIN }
	
	
};





