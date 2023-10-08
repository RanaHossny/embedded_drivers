/********************************************************************************/
/**    File Name: DIO.h                                                         */
/**                                                                             */
/**  Description: Implementation of the DIO  module                             */
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
/** aaboelno     Ahmed Abo Elnour          ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 21/08/2022   0.1      aaboelno     Initial Creation                         */
/** 23/08/2022   0.2       Rana         toggle function                         */
/********************************************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"


#include  "DIO.h"
#include  "DIO_cfg.h"
#include  "DIO_priv.h"

/* Description: function init is used  to scan the configuration from the user    */

void DIO_voidInit(void)
{
	
	DDRA = CONC(DIO_u8DIR_PIN_7,DIO_u8DIR_PIN_6,DIO_u8DIR_PIN_5,DIO_u8DIR_PIN_4,DIO_u8DIR_PIN_3,DIO_u8DIR_PIN_2,DIO_u8DIR_PIN_1,DIO_u8DIR_PIN_0);
	DDRB = CONC(DIO_u8DIR_PIN_15,DIO_u8DIR_PIN_14,DIO_u8DIR_PIN_13,DIO_u8DIR_PIN_12,DIO_u8DIR_PIN_11,DIO_u8DIR_PIN_10,DIO_u8DIR_PIN_9,DIO_u8DIR_PIN_8);
	DDRC = CONC(DIO_u8DIR_PIN_23,DIO_u8DIR_PIN_22,DIO_u8DIR_PIN_21,DIO_u8DIR_PIN_20,DIO_u8DIR_PIN_19,DIO_u8DIR_PIN_18,DIO_u8DIR_PIN_17,DIO_u8DIR_PIN_16);
	DDRD = CONC(DIO_u8DIR_PIN_31,DIO_u8DIR_PIN_30,DIO_u8DIR_PIN_29,DIO_u8DIR_PIN_28,DIO_u8DIR_PIN_27,DIO_u8DIR_PIN_26,DIO_u8DIR_PIN_25,DIO_u8DIR_PIN_24);
	
}

/* Description : function write DIO_u8HIGH or DIO_u8LOW on Pin start 0 to 31       */
tenuErrorStatus DIO_enuWritePin(uint8 u8PinNumCpy , uint8 u8PinValueCpy)
{
	tenuErrorStatus  enuReturnStatusLoc = E_OK ;
	
	switch (u8PinValueCpy)
		{
			case DIO_u8HIGH :
				if (u8PinNumCpy >= DIO_u8PIN_0  && u8PinNumCpy <= DIO_u8PIN_7 )
				{
					SET_BIT(ODRA , u8PinNumCpy ) ;	
				}
				else if (u8PinNumCpy >= DIO_u8PIN_8  && u8PinNumCpy <= DIO_u8PIN_15 )
				{
					SET_BIT(ODRB , u8PinNumCpy % DIO_u8PIN_SIZE  ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_16  && u8PinNumCpy <= DIO_u8PIN_23 )
				{
					SET_BIT(ODRC , u8PinNumCpy % DIO_u8PIN_SIZE ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_24  && u8PinNumCpy <= DIO_u8PIN_31 )
				{
					SET_BIT(ODRD , u8PinNumCpy % DIO_u8PIN_SIZE ) ;
				}
				else
				{
					enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
				}
			break ;
			case DIO_u8LOW :
				if (u8PinNumCpy >= DIO_u8PIN_0  && u8PinNumCpy <= DIO_u8PIN_7 )
				{		
					CLR_BIT(ODRA , u8PinNumCpy ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_8  && u8PinNumCpy <= DIO_u8PIN_15 )
				{
					CLR_BIT(ODRB , u8PinNumCpy % DIO_u8PIN_SIZE ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_16  && u8PinNumCpy <= DIO_u8PIN_23 )
				{
					CLR_BIT(ODRC , u8PinNumCpy % DIO_u8PIN_SIZE ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_24  && u8PinNumCpy <= DIO_u8PIN_31 )
				{
					CLR_BIT(ODRD , u8PinNumCpy % DIO_u8PIN_SIZE ) ;
				}
				else
				{
					enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
				}
			
			break ;
			default :
			enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
			break ;
			
		}
	
	return enuReturnStatusLoc ;
	
}

/* Description : function read the values  on Pin  0 to 31  and return the error state     */
tenuErrorStatus DIO_enuReadPin(uint8 u8PinNumCpy , uint8 * pu8PinValueCpy)
{
	tenuErrorStatus enuReturnStatusLoc = E_OK ;
	
	if (pu8PinValueCpy != NULL_PTR)
	{
		     if (u8PinNumCpy >= DIO_u8PIN_0  && u8PinNumCpy <= DIO_u8PIN_7 )
				{
					*pu8PinValueCpy = GET_BIT(IDRA , u8PinNumCpy ) ;	
				}
				else if (u8PinNumCpy >= DIO_u8PIN_8  && u8PinNumCpy <= DIO_u8PIN_15 )
				{
					*pu8PinValueCpy = GET_BIT(IDRB , u8PinNumCpy % DIO_u8PIN_SIZE  ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_16  && u8PinNumCpy <= DIO_u8PIN_23 )
				{
					*pu8PinValueCpy = GET_BIT(IDRC , u8PinNumCpy % DIO_u8PIN_SIZE ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_24  && u8PinNumCpy <= DIO_u8PIN_31 )
				{
					*pu8PinValueCpy = GET_BIT(IDRD , u8PinNumCpy % DIO_u8PIN_SIZE ) ;
				}
				else
				{
					enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
				}
	}
	else
	{
		enuReturnStatusLoc = E_NOK_PARAM_NULL_POINTER ;
	}
	
	return enuReturnStatusLoc ;
	
}
/* Description : function pullwrite ask to write a value of DIO_u8HIGH OR DIO_u8LOW in pin from 0 to 31            */
/* and return the error state                                                                                      */

tenuErrorStatus DIO_enuPullWrite(uint8 u8PinNumCpy , uint8 u8PinStateCpy)
{
	return DIO_enuWritePin(u8PinNumCpy , u8PinStateCpy );
}

/* Description : function writebus used to write a value of DIO_u8HIGH OR DIO_u8LOW in many  pins from 0 to 31     */
/* and return the error state                                                                                      */

tenuErrorStatus DIO_enuWriteBus(tstrPinMapping * pastrPinMappingCpy , uint8 u8SizeCpy )
{
	tenuErrorStatus enuReturnStatusLoc = E_OK ;
	uint8 u8CntrLoc ;
	if(pastrPinMappingCpy !=NULL_PTR)
	{
		if (u8SizeCpy <= DIO_u8MAX_NUMBER_OF_PINS )
		{
			for (u8CntrLoc = 0 ; u8CntrLoc < u8SizeCpy ; u8CntrLoc++)
			{
				pastrPinMappingCpy[u8CntrLoc]. enuStatus  = DIO_enuWritePin(pastrPinMappingCpy[u8CntrLoc].u8PinNum , pastrPinMappingCpy[u8CntrLoc].u8PinValue );
			}
		}
		else
		{
			enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
		}
		
	}
	else
	{
		enuReturnStatusLoc = E_NOK_PARAM_NULL_POINTER ;
	}
	return enuReturnStatusLoc ;
	
}
/* Description : function readbus used to read a value of DIO_u8HIGH OR DIO_u8LOW in many  pins from 0 to 31       */
/* and return the error state                                                                                      */

tenuErrorStatus DIO_enuReadBus(tstrPinMapping * pastrPinMappingCpy , uint8 u8SizeCpy )
{
	tenuErrorStatus enuReturnStatusLoc = E_OK ;
	uint8 u8CntrLoc ;
	
	if(pastrPinMappingCpy != NULL_PTR )
	{
		if (u8SizeCpy <= DIO_u8MAX_NUMBER_OF_PINS)
		{
			for (u8CntrLoc = 0 ; u8CntrLoc < u8SizeCpy ; u8CntrLoc++)
			{
				pastrPinMappingCpy[u8CntrLoc]. enuStatus  = DIO_enuReadPin(pastrPinMappingCpy[u8CntrLoc].u8PinNum , &(pastrPinMappingCpy[u8CntrLoc].u8PinValue) );
			}
		}
		else
		{
			enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
		}
		
	}
	else
	{
		enuReturnStatusLoc = E_NOK_PARAM_NULL_POINTER ;
	}
	return enuReturnStatusLoc ;
	
}

/* Description : function writePinDir to used to select dir from DIO_u8OUTPUT and DIO_u8INPUT at pin from 0 to 31  */
/* and return the error state                                                                                      */

tenuErrorStatus DIO_enuWritePinDir(uint8 u8PinNumCpy , uint8 u8PinDirCpy)
{
	tenuErrorStatus  enuReturnStatusLoc = E_OK ;
	
	switch (u8PinDirCpy)
		{
			case DIO_u8OUTPUT :
			     if (u8PinNumCpy >= DIO_u8PIN_0  && u8PinNumCpy <= DIO_u8PIN_7 )
				{
					SET_BIT(DDRA , u8PinNumCpy ) ;	
				}
				else if (u8PinNumCpy >= DIO_u8PIN_8  && u8PinNumCpy <= DIO_u8PIN_15 )
				{
					SET_BIT(DDRB , u8PinNumCpy % DIO_u8PIN_SIZE  ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_16  && u8PinNumCpy <= DIO_u8PIN_23 )
				{
					SET_BIT(DDRC , u8PinNumCpy % DIO_u8PIN_SIZE ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_24  && u8PinNumCpy <= DIO_u8PIN_31 )
				{
					SET_BIT(DDRD , u8PinNumCpy % DIO_u8PIN_SIZE ) ;
				}
				else
				{
					enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
				}
			
			break ;
			case DIO_u8INPUT :
			   if (u8PinNumCpy >= DIO_u8PIN_0  && u8PinNumCpy <= DIO_u8PIN_7 )
				{		
					CLR_BIT(DDRA , u8PinNumCpy ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_8  && u8PinNumCpy <= DIO_u8PIN_15 )
				{
					CLR_BIT(DDRB , u8PinNumCpy % DIO_u8PIN_SIZE ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_16  && u8PinNumCpy <= DIO_u8PIN_23 )
				{
					CLR_BIT(DDRC , u8PinNumCpy % DIO_u8PIN_SIZE ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_24  && u8PinNumCpy <= DIO_u8PIN_31 )
				{
					CLR_BIT(DDRD , u8PinNumCpy % DIO_u8PIN_SIZE ) ;
				}
				else
				{
					enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
				}
			break ;
			default :
			enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
			break ;
			
		}
	
	return enuReturnStatusLoc ;
	
	
}
/* Description : function togglePin to used to toggle pin from 0 and 31                                     */
/* and return the error state                                                                               */

tenuErrorStatus DIO_enuTogglePin(uint8 u8PinNumCpy)
{ tenuErrorStatus enuReturnStatusLoc = E_OK ;
uint8 temp;
DIO_enuReadPin(u8PinNumCpy,&temp);
  if(u8PinNumCpy>=DIO_u8PIN_0 && u8PinNumCpy<= DIO_u8PIN_0){
	if(temp==DIO_u8HIGH){
		enuReturnStatusLoc=DIO_enuWritePin(u8PinNumCpy,DIO_u8LOW);
	}
	else if(temp==DIO_u8LOW){
		enuReturnStatusLoc= DIO_enuWritePin(u8PinNumCpy,DIO_u8HIGH);
	}
	else{
		enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}

}
else{
enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;	
}
	
	return enuReturnStatusLoc ;
}


