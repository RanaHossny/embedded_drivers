/********************************************************************************/
/**    File Name: DC_Motor.c                                                 */
/**                                                                             */
/**  Description: Implementation of the DC_Motor contain configuration for the module*/
/********************************************************************************/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          : STM32F401CCG6                                            */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/* to Rana Hossny */
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
/** 25/08/2023   0.1       Rana     Initial Creation                       */
/********************************************************************************/
#include "../../LIB/STD_Types.h"
#include"../../MCAL//GPIO/GPIO.h"
#include "DC_Motor.h"
#include "DC_Motor_cfg.h"
#include "DC_Motor_priv.h"


tenuErrorStatus Motor_enuStart (uint8 u8MotorNumCpy)
{
	tenuErrorStatus enuReturnStatLoc = E_OK ; 
	
	if (u8MotorNumCpy < DC_Motor_MAX_NUM  )
		
	{ 

		if(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 >=GPIO_PIN_NUM0 &&
		MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 <=GPIO_PIN_NUM15 &&
		MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 >=GPIO_PIN_NUM0 &&
		MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 <=GPIO_PIN_NUM15){
		if(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_0==GPIO_PORTA || MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_0==GPIO_PORTB
		|| MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_0==GPIO_PORTC &&
		(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_1==GPIO_PORTA || MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_1==GPIO_PORTB
		|| MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_1==GPIO_PORTC )){
		switch(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8MotorModeConc)
		{
			case MOTOR_u8NORMAL :
			MGPIO_u8SetPinVal(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_0,MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 , GPIO_HIGH );
			MGPIO_u8SetPinVal(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_1,MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1, GPIO_LOW );

				
			break ;
			case MOTOR_u8REVERSE:
			MGPIO_u8SetPinVal(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_0,MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 , GPIO_LOW );
			MGPIO_u8SetPinVal(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_1,MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1, GPIO_HIGH );
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

		if(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 >=GPIO_PIN_NUM0 &&
		MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 <=GPIO_PIN_NUM15 &&
		MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 >=GPIO_PIN_NUM0 &&
		MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1 <=GPIO_PIN_NUM15){
		if(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_0==GPIO_PORTA || MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_0==GPIO_PORTB
		|| MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_0==GPIO_PORTC &&
		(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_1==GPIO_PORTA || MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_1==GPIO_PORTB
		|| MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_1==GPIO_PORTC )){
		switch(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8MotorModeConc)
		{
			case MOTOR_u8NORMAL :
			MGPIO_u8SetPinVal(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_0,MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap0 , GPIO_LOW );

				
			break ;
			case MOTOR_u8REVERSE:
			MGPIO_u8SetPinVal(MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8Port_Pin_1,MOTOR_astrMotorPinMapping[u8MotorNumCpy].u8DioPinMap1, GPIO_LOW );
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


