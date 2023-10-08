/********************************************************************************/
/**    File Name: TIM0.c                                                         */
/**                                                                             */
/**  Description: Implementation of the TIM0 contain configuration for the module*/
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
#include "TIM0.h"
#include "TIM0_cfg.h"
#include "TIM0_priv.h"

void dummy_void(void);
pf TIM0_pfCtcCallback =dummy_void;
pf TIM0_pfOvfCallback =dummy_void ;

static uint8 u8_used ,factor;
static uint32 counter, delay;
void TIM0_voidInit(void)
{
#if   TIM0_MODE == TIM0_NORMAL_MODE
	CLR_BIT(TCCR0 , 6);
	CLR_BIT(TCCR0 , 3);
#elif TIM0_MODE == TIM0_PWM_PHASE_CORRECT_MODE
	SET_BIT(TCCR0 , 6);
	CLR_BIT(TCCR0 , 3);
#elif TIM0_MODE == TIM0_CTC_MODE
	CLR_BIT(TCCR0 , 6);
	SET_BIT(TCCR0 , 3);
#else
	SET_BIT(TCCR0 , 6);
	SET_BIT(TCCR0 , 3);
#endif

	TCCR0 &= (0xF8);/* clear reg 0b1111 1000 */
	TCCR0 |=((0x07)& TIM0_PRESCALLER) ; /* write in reg */
	TCNT0 = 0;
	OCR0  = 0;
	/* Disable Interrupt  OVF CM */
	CLR_BIT(TIMSK , 0) ;
	CLR_BIT(TIMSK , 1) ;
	/* Clear IF flags OVF CM */
	SET_BIT(TIFR  , 0) ;
	SET_BIT(TIFR  , 1) ;

}
void TIM0_voidSetPreloadValue (uint8 u8PreloadValueCpy)
{
	TCNT0 = u8PreloadValueCpy;
}
void TIM0_voidSetOutputCompareValue (uint8 u8LoadValueCpy)
{
	OCR0 = u8LoadValueCpy; 
}
void TIM0_voidEnableOVFIntterrupt(void)
{
	SET_BIT(TIMSK , 0) ;
}
void TIM0_voidDisableOVFIntterrupt(void)
{
	CLR_BIT(TIMSK , 0) ;
}
void TIM0_voidEnableCTCIntterrupt(void)
{
	SET_BIT(TIMSK , 1) ;
}
void TIM0_voidDisableCTCIntterrupt(void)
{

	CLR_BIT(TIMSK , 1) ;
}
void TIM0_voidSetOvfCallback(pf pfOvfCallbackCpy)
{
	TIM0_pfOvfCallback = pfOvfCallbackCpy ;

}
void TIM0_voidSetCtcCallback(pf pfCtcCallbackCpy)
{  
	TIM0_pfCtcCallback = pfCtcCallbackCpy;

}
/*OVF ISR*/
void __vector_11 (void) __attribute__((signal ,used));
void __vector_11 (void)
{  
	TIM0_pfOvfCallback();

}
/*CM ISR*/
void __vector_10 (void) __attribute__((signal ,used));
void __vector_10 (void)
{
	if(u8_used!=0){
		if(counter == delay*factor){
			u8_used=0;
			TIM0_pfCtcCallback();
		}
		counter++;
	}
	else{
		TIM0_pfCtcCallback();
	}

}
void TIM0_voidDelay_ms(uint32 u32DalayTimeCpy)
{  SET_BIT(TIMSK , 1) ;
	OCR0  = 250;
	delay=u32DalayTimeCpy;
	factor=4;
	u8_used=1;
	while(counter<(delay*factor));
	CLR_BIT(TIMSK , 1) ;
	counter=0;


}
void TIM0_voidDelay_Init(void){
  	/* TIM0_MODE == TIM0_CTC_MODE */
	CLR_BIT(TCCR0 , 6);
	SET_BIT(TCCR0 , 3);
	TCCR0 &= (0xF8);/* clear reg 0b1111 1000 */
	TCCR0  |=((0x07)& TIM0_PRESCALLER_8 ) ; /* write in reg */
	TCNT0=0x00;

}
void TIM0_voidDelay_us(uint32 u32DalayTimeCpy)
{  SET_BIT(TIMSK , 1) ;
	OCR0 = 1;
	delay=u32DalayTimeCpy;
	factor=1;
	u8_used=1;
	while(counter<(delay*factor));
	CLR_BIT(TIMSK , 1) ;
	counter=0;
	
}

void dummy_void(void){

}
uint16 TIM0_u16GetCntrValue(void ){
	return TCNT0 ;
}
