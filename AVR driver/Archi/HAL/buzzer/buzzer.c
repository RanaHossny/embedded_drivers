/********************************************************************************/
/**    File Name: BUZZER.C                                                        */
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

#include "BUZZER.h"
#include "BUZZER_cfg.h"
#include "BUZZER_priv.h"


tenuErrorStatus BUZZER_enuWriteValue (uint8 u8BUZZERNumCpy , uint8 u8BUZZERValueCpy  )
{
	tenuErrorStatus enuReturnStatLoc = E_OK ; 
	if (u8BUZZERNumCpy < BUZZER_MAX_NUM )
		
	{
		switch(u8BUZZERValueCpy)
		{
			case BUZZER_u8ON :
				if (BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8BUZZERModeConc == BR_u8NORMAL_1PIN )
				{
					enuReturnStatLoc = DIO_enuWritePin(BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8DioPinMap[0] , DIO_u8HIGH ) ;
				}
				else if (BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8BUZZERModeConc == BR_u8REVERSE_1PIN)
				{
					enuReturnStatLoc = DIO_enuWritePin(BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8DioPinMap[0] , DIO_u8LOW ) ;			
				}
				else if (BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8BUZZERModeConc == BR_u8NORMAL_2PIN )
				{
					enuReturnStatLoc = DIO_enuWritePin(BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8DioPinMap[0] , DIO_u8HIGH ) ;
					enuReturnStatLoc = DIO_enuWritePin(BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8DioPinMap[1] , DIO_u8LOW ) ;			
				}
				else if (BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8BUZZERModeConc == BR_u8REVERSE_2PIN)
				{
					enuReturnStatLoc = DIO_enuWritePin(BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8DioPinMap[0] , DIO_u8LOW ) ;
                    enuReturnStatLoc = DIO_enuWritePin(BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8DioPinMap[0] , DIO_u8HIGH ) ;					
				}
				else
				{
					enuReturnStatLoc = E_NOK_CONFIG_PARM_ERROR ;
				}
			break ;
			case BUZZER_u8OFF:
			  if (BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8BUZZERModeConc == BR_u8NORMAL_1PIN ||
			  BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8BUZZERModeConc == BR_u8NORMAL_2PIN )
				{
					enuReturnStatLoc = DIO_enuWritePin(BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8DioPinMap[0] , DIO_u8LOW ) ;
				}
				else if (BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8BUZZERModeConc == BR_u8REVERSE_1PIN||
				BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8BUZZERModeConc == BR_u8REVERSE_2PIN)
				
				{
					enuReturnStatLoc = DIO_enuWritePin(BUZZER_astrBUZZERPinMapping[u8BUZZERNumCpy].u8DioPinMap[0] , DIO_u8HIGH ) ;			
				}

				else
				{
					enuReturnStatLoc = E_NOK_CONFIG_PARM_ERROR ;
				}			
			break ;
			default :
				enuReturnStatLoc =E_NOK_PARAM_OUT_OF_RANGE ;
            break ;				
		}
	}
	else
	{
		enuReturnStatLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}
	return enuReturnStatLoc ;
	
}
