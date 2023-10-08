/********************************************************************************/
/**    File Name: EXTINT2.c                                                     */
/**                                                                             */
/**  Description: Implementation of the external interrupt 2                    */
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
/** Rana    Rana Hossny         ITI.                                       */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 22/08/2022   0.1      Rana     Initial Creation                             */
 
/********************************************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"

#include "EXTINT2.h"
#include "EXTINT2_cfg.h"
#include "EXTINT2_priv.h"


pf EXTINT2_pfCallback ;

void EXTINT2_voidInit(void)
{

#if EXTINT2_SENSE_MODE == FALLING_EDGE
	CLR_BIT( MCUCSR , 6) ;

	
#elif EXTINT2_SENSE_MODE ==RISING_EDGE
	SET_BIT(MCUCSR , 6) ;
	
#endif 

	CLR_BIT(GICR,5); // Disable External interrupt 0
	SET_BIT(GIFR,5); //Clear External interrupt 0 Flag 

}

void EXTINT2_voidEnable(void)
{
	SET_BIT(GICR,5);
}

void EXTINT2_voidDisable(void)
{
	CLR_BIT(GICR,5);
}

void EXTINT2_voidSetCallBack(pf pfCallbackCpy)
{
	EXTINT2_pfCallback = pfCallbackCpy ;
}

void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{
	EXTINT2_pfCallback();
}
void EXTINT2_voidSetSenseValue(uint8 u8SenseValueCpy){
	if(u8SenseValueCpy==FALLING_EDGE){
	CLR_BIT( MCUCSR , 6) ;
		
	}
	if(u8SenseValueCpy==RISING_EDGE){
	SET_BIT(MCUCSR , 6) ;
	}
	
}


