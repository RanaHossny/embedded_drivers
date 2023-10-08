/********************************************************************************/
/**    File Name: DC_Motor.c                                                 */
/**                                                                             */
/**  Description: Implementation of the DC_Motor contain configuration for the module*/
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
/** Rana         Rana Hossny          ITI.                                      */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 31/08/2022   0.1       Rana     Initial Creation                            */
/********************************************************************************/
#include "STD_Types.h"

#include "DIO.h"

#include "DC_Motor.h"
#include "DC_Motor_cfg.h"
#include "DC_Motor_priv.h"


tenuErrorStatus Motor_enuStart (uint8 u8MotorNumCpy)
{
	tenuErrorStatus enuReturnStatLoc = E_OK ; 
	
	if (u8MotorNumCpy < DC_Motor_MAX_NUM  )
		
	{ 

		if(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 >=DIO_u8PIN_0 &&
		MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 <=DIO_u8PIN_31 &&
		MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 >=DIO_u8PIN_0 &&
		MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 <=DIO_u8PIN_31){
		switch(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8MotorModeConc)
		{
			case MOTOR_u8NORMAL :
			enuReturnStatLoc = DIO_enuWritePin(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 , DIO_u8HIGH ) ;
			enuReturnStatLoc = DIO_enuWritePin(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 , DIO_u8LOW ) ;
				
			break ;
			case MOTOR_u8REVERSE:
		    enuReturnStatLoc = DIO_enuWritePin(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 , DIO_u8LOW ) ;
			enuReturnStatLoc = DIO_enuWritePin(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 , DIO_u8HIGH ) ;
            break ;	
            default:
			enuReturnStatLoc =E_NOK_CONFIG_PARM_ERROR;;
            break;			

	}
		}
	else{
		enuReturnStatLoc =E_NOK_CONFIG_PARM_ERROR;
		
	}

	}
	else
	{
		enuReturnStatLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}
	return enuReturnStatLoc ;
	
}

tenuErrorStatus Motor_enuStop (uint8 u8MotorNumCpy)
{
	tenuErrorStatus enuReturnStatLoc = E_OK ; 
	
	if (u8MotorNumCpy < DC_Motor_MAX_NUM  )
		
	{ 

		if(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 >=DIO_u8PIN_0 &&
		MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 <=DIO_u8PIN_31 &&
		MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 >=DIO_u8PIN_0 &&
		MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 <=DIO_u8PIN_31){
		switch(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8MotorModeConc)
		{
			case MOTOR_u8NORMAL :
			enuReturnStatLoc = DIO_enuWritePin(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 , DIO_u8LOW ) ;

				
			break ;
			case MOTOR_u8REVERSE:
			enuReturnStatLoc = DIO_enuWritePin(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 , DIO_u8LOW ) ;
            break ;	
            default:
			enuReturnStatLoc =E_NOK_CONFIG_PARM_ERROR;;
            break;			

	}
		}
	else{
		enuReturnStatLoc =E_NOK_CONFIG_PARM_ERROR;
		
	}

	}
	else
	{
		enuReturnStatLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}
	return enuReturnStatLoc ;
	
}







tenuErrorStatus Motor_enuChangeDir (uint8 u8MotorNumCpy )
{
	tenuErrorStatus enuReturnStatLoc = E_OK ; 
	if(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 >=DIO_u8PIN_0 &&
			MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 <=DIO_u8PIN_31 &&
			MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 >=DIO_u8PIN_0 &&
			MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 <=DIO_u8PIN_31){
			switch(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8MotorModeConc)
			{
				case MOTOR_u8NORMAL :
					enuReturnStatLoc = DIO_enuWritePin(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 , DIO_u8LOW ) ;
					enuReturnStatLoc = DIO_enuWritePin(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 , DIO_u8HIGH ) ;
				break ;
				case MOTOR_u8REVERSE:
					enuReturnStatLoc = DIO_enuWritePin(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 , DIO_u8HIGH ) ;
					enuReturnStatLoc = DIO_enuWritePin(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 , DIO_u8LOW ) ;
	            break ;
	            default:
				enuReturnStatLoc =E_NOK_CONFIG_PARM_ERROR;;
	            break;

		}
			}
	else
	{
		enuReturnStatLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}
	return enuReturnStatLoc ;
}

