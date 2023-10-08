/********************************************************************************/
/**    File Name: LED.c	                                                        */
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
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include"../../MCAL//GPIO/GPIO.h"

#include "LED.h"
#include "LED_cfg.h"
#include "LED_priv.h"


tenuErrorStatus LED_enuWriteValue (uint8 u8_PortId,uint8 u8_PinNo, uint8 LED_MODE_Connection , uint8 u8_LED_Mode)
{
	tenuErrorStatus enuReturnStatLoc = E_OK ; 

		switch(u8_LED_Mode)
		{
			case LED_u8ON :
				if (LED_MODE_Connection == LED_u8NORMAL)
				{
					MGPIO_u8SetPinVal(u8_PortId,u8_PinNo,LED_u8ON );
				}
				else if (LED_MODE_Connection == LED_u8REVERSE)
				{
					MGPIO_u8SetPinVal(u8_PortId,u8_PinNo,LED_u8OFF );			
				}
				else
				{
					enuReturnStatLoc = E_NOK_CONFIG_PARM_ERROR ;
				}
			break ;
			case LED_u8OFF:
			   if (LED_MODE_Connection  == LED_u8NORMAL)
				{
					MGPIO_u8SetPinVal(u8_PortId,u8_PinNo,LED_u8OFF );
				}
				else if (LED_MODE_Connection  == LED_u8REVERSE)
				{
					MGPIO_u8SetPinVal(u8_PortId,u8_PinNo,LED_u8ON );
		
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
	return enuReturnStatLoc ;
	
}

void LED_enuToggle (uint8 u8_PortId,uint8 u8_PinNo)
{	
MGPIO_u8TogglePinVal( u8_PortId, u8_PinNo);
	
}

