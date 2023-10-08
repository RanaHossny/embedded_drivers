/********************************************************************************/
/**    File Name: EXTINT1.c                                                     */
/**                                                                             */
/**  Description: Implementation of the external interrupt 1                    */
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

#include "EXTINT1.h"
#include "EXTINT1_cfg.h"
#include "EXTINT1_priv.h"


pf EXTINT1_pfCallback ;

void EXTINT1_voidInit(void)
{

#if EXTINT1_SENSE_MODE == LOW_LEVEL
	CLR_BIT(MCUCR , 2) ;
	CLR_BIT(MCUCR , 3) ;
	
#elif EXTINT1_SENSE_MODE ==IOC 
	SET_BIT(MCUCR , 2) ;
	CLR_BIT(MCUCR , 3) ;
#elif EXTINT1_SENSE_MODE == FALLING_EDGE
	CLR_BIT(MCUCR , 2) ;
	SET_BIT(MCUCR , 3) ;
#else
	SET_BIT(MCUCR , 2) ;
	SET_BIT(MCUCR , 3) ;
#endif 

	CLR_BIT(GICR,7); // Disable External interrupt 0
	SET_BIT(GIFR,7); //Clear External interrupt 0 Flag 

}

void EXTINT1_voidEnable(void)
{
	SET_BIT(GICR,7);
}

void EXTINT1_voidDisable(void)
{
	CLR_BIT(GICR,7);
}

void EXTINT1_voidSetCallBack(pf pfCallbackCpy)
{
	EXTINT1_pfCallback = pfCallbackCpy ;
}

void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{
	EXTINT1_pfCallback();
}
void EXTINT1_voidSetSenseValue(uint8 u8SenseValueCpy){
	if(u8SenseValueCpy==FALLING_EDGE){
    CLR_BIT(MCUCR , 2) ;
	SET_BIT(MCUCR , 3) ;
		
	}
	if(u8SenseValueCpy==RISING_EDGE){
	SET_BIT(MCUCR , 2) ;
	SET_BIT(MCUCR , 3) ;
	}
	
}

