/********************************************************************************/
/**    File Name: TIM1.c                                                         */
/**                                                                             */
/**  Description: Implementation of the TIM1 contain configuration for the module*/
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

#include "TIM1.h"
#include "TIM1_cfg.h"
#include "TIM1_priv.h"
void dummy_void(void);
pf TIM1_pfCtcCallback_A =dummy_void ;
pf TIM1_pfCtcCallback_B =dummy_void ;
pf TIM1_pfOvfCallback =dummy_void ;
pf TIM1_pfCptrCallback =dummy_void ;

static uint32 used1=0 , counter1=0 ,delay1 ,factor1 , ic_counter,ovf ;
float32 first_time_read , time_on=0 , total_time,temp;
void TIM1_voidInit(void)
{         
	                                                    
	/* Put the value of wave genertion mode*/               
	TCCR1A &= 0xFC;                                           
	TCCR1A |=(TIM1_MODE_OPERATION &0x03);
	TCCR1B &=0xE7 ;
	TCCR1B |=((TIM1_MODE_OPERATION&0x0C)<<1);
	/*             COMPARE_OUTPUT_MODE              */
	#if CHANNEL_MODE==  CHANNELA
	#if OUTPUT_MODE == NON_PWM_MODE
	#if COMPARE_OUTPUT_MODE ==OC1A_OR_OC1B_DISCONNECTED
	CLR_BIT(TCCR1A , 6) ;
	CLR_BIT(TCCR1A , 7) ;
	#elif COMPARE_OUTPUT_MODE ==TOGGLE_OC1A_OR_OC1B_ON_COMPARE_MATCH
	CLR_BIT(TCCR1A , 6) ;
	SET_BIT(TCCR1A , 7) ;
	#elif COMPARE_OUTPUT_MODE ==CLEAR_OC1A_OR_OC1B_ON_COMPARE_MATCH 
	CLR_BIT(TCCR1A , 7) ;
	SET_BIT(TCCR1A , 6) ;
	#elif COMPARE_OUTPUT_MODE ==SET_OC1A_OR_OC1B_ON_COMPARE_MATCH
	SET_BIT(TCCR1A , 6) ;
	SET_BIT(TCCR1A , 7) ;
	#endif
	
	#elif OUTPUT_MODE ==FAST_PWM_MODE
	#if COMPARE_OUTPUT_MODE ==OC1A_OR_OC1B_DISCONNECTED
	CLR_BIT(TCCR1A , 6) ;
	CLR_BIT(TCCR1A , 7) ;
	#elif COMPARE_OUTPUT_MODE ==TOGGLE_OC1A_ON_COMPARE_MATCH_OC1B_DISCONNECTED
	CLR_BIT(TCCR1A , 6) ;
	SET_BIT(TCCR1A , 7) ;
	#elif COMPARE_OUTPUT_MODE ==CLEAR_OC1A_OR_OC1B_ON_COMPARE_MATCH_SET_OC1A_OR_OC1B_AT_TOP
	CLR_BIT(TCCR1A , 7) ;
	SET_BIT(TCCR1A , 6) ;
	#elif COMPARE_OUTPUT_MODE ==SET_OC1A_OR_OC1B_ON_COMPARE_MATCH_CLEAR_OC1A_OR_OC1B_AT_TOP
	SET_BIT(TCCR1A , 6) ;
	SET_BIT(TCCR1A , 7) ;
	#endif
	
	#elif OUTPUT_MODE == Phase_CORRECT_AND_PHASE_AND_FREQ_CORRECT_PWM
	#if COMPARE_OUTPUT_MODE ==OC1A_OR_OC1B_DISCONNECTED
	CLR_BIT(TCCR1A , 6) ;
	CLR_BIT(TCCR1A , 7) ;
	#elif COMPARE_OUTPUT_MODE ==TOGGLE_OC1A_ON_COMPARE_MATCH_OC1B_DISCONNECTED
	CLR_BIT(TCCR1A , 6) ;
	SET_BIT(TCCR1A , 7) ;
	#elif COMPARE_OUTPUT_MODE ==CLEAR_OC1A_OR_OC1B_ON_COMPARE_UPCOUNTING_SET_OC1A_OR_OC1B_ON_COMPARE_MATCH_DOWNCOUNTING
	CLR_BIT(TCCR1A , 7) ;
	SET_BIT(TCCR1A , 6) ;
	#elif COMPARE_OUTPUT_MODE ==SET_OC1A_OR_OC1B_ON_COMPARE_UPCOUNTING_CLEAR_OC1A_OR_OC1B_ON_COMPARE_MATCH_DOWNCOUNTING
	SET_BIT(TCCR1A , 6) ;
	SET_BIT(TCCR1A , 7) ;
	#endif
	#endif
	#elif CHANNEL_MODE==  CHANNELB
	#elif OUTPUT_MODE ==NON_PWM_MODE
	#if COMPARE_OUTPUT_MODE ==OC1A_OR_OC1B_DISCONNECTED
	CLR_BIT(TCCR1A , 4) ;
	CLR_BIT(TCCR1A , 5) ;
	#elif COMPARE_OUTPUT_MODE ==TOGGLE_OC1A_OR_OC1B_ON_COMPARE_MATCH
	CLR_BIT(TCCR1A , 4) ;
	SET_BIT(TCCR1A ,   5) ;
	#elif COMPARE_OUTPUT_MODE ==CLEAR_OC1A_OR_OC1B_ON_COMPARE_MATCH 
	CLR_BIT(TCCR1A , 5) ;
	SET_BIT(TCCR1A , 4) ;
	#elif COMPARE_OUTPUT_MODE ==SET_OC1A_OR_OC1B_ON_COMPARE_MATCH
	SET_BIT(TCCR1A , 4) ;
	SET_BIT(TCCR1A , 5) ;
	#endif
	#elif OUTPUT_MODE ==FAST_PWM_MODE
	#if COMPARE_OUTPUT_MODE ==OC1A_OR_OC1B_DISCONNECTED
	CLR_BIT(TCCR1A , 4) ;
	CLR_BIT(TCCR1A , 5) ;
	#elif COMPARE_OUTPUT_MODE ==TOGGLE_OC1A_ON_COMPARE_MATCH_OC1B_DISCONNECTED
	CLR_BIT(TCCR1A , 4) ;
	SET_BIT(TCCR1A , 5) ;
	#elif COMPARE_OUTPUT_MODE ==CLEAR_OC1A_OR_OC1B_ON_COMPARE_MATCH_SET_OC1A_OR_OC1B_AT_TOP
	CLR_BIT(TCCR1A , 5) ;
	SET_BIT(TCCR1A , 4) ;
	#elif COMPARE_OUTPUT_MODE ==SET_OC1A_OR_OC1B_ON_COMPARE_MATCH_CLEAR_OC1A_OR_OC1B_AT_TOP
	SET_BIT(TCCR1A , 4) ;
	SET_BIT(TCCR1A , 5) ;
	#endif
	
	#elif OUTPUT_MODE ==Phase_CORRECT_AND_PHASE_AND_FREQ_CORRECT_PWM
	#if COMPARE_OUTPUT_MODE ==OC1A_OR_OC1B_DISCONNECTED
	CLR_BIT(TCCR1A , 4) ;
	CLR_BIT(TCCR1A , 5) ;
	#elif COMPARE_OUTPUT_MODE ==TOGGLE_OC1A_ON_COMPARE_MATCH_OC1B_DISCONNECTED
	CLR_BIT(TCCR1A , 4) ;
	SET_BIT(TCCR1A , 5) ;
	#elif COMPARE_OUTPUT_MODE ==CLEAR_OC1A_OR_OC1B_ON_COMPARE_UPCOUNTING_SET_OC1A_OR_OC1B_ON_COMPARE_MATCH_DOWNCOUNTING
	CLR_BIT(TCCR1A , 5) ;
	SET_BIT(TCCR1A , 4) ;
	#elif COMPARE_OUTPUT_MODE ==SET_OC1A_OR_OC1B_ON_COMPARE_UPCOUNTING_CLEAR_OC1A_OR_OC1B_ON_COMPARE_MATCH_DOWNCOUNTING
	SET_BIT(TCCR1A , 4) ;
	SET_BIT(TCCR1A , 5) ;
	#endif
	#endif
	#endif
  TCCR1B &= (0xF8);   /* clear reg 0b1111 1000 */
  TCCR1B |=((0x03)& TIM1_PRESCALLER) ; /* write in reg */
  TCNT1H =  0;
  TCNT1L =  0;
  OCR1AL  = 0;
  OCR1AH  = 0;
  OCR1BL  = 0;
  OCR1BH  = 0;
 /* Disable Interrupt  OVF CM */
 TIMSK &= 0xC3;
 /* Clear IF flags OVF CM */
 TIFR |=0x3C;
 /*                                       */
}
void TIM1_voidSetPreloadValue (uint16 u16PreloadValueCpy)
{   TCNT1L = u16PreloadValueCpy& 0x00FF;
	TCNT1H =  (u16PreloadValueCpy& 0xFF00)>>8;
  
}
void TIM1_voidSetOutputCompareValue (uint16 u16LoadValueCpy,uint8 u8ChannelSlctCpy)
{  switch(u8ChannelSlctCpy){
	case CHANNELA:
  OCR1AL  = u16LoadValueCpy& 0x00FF;
  OCR1AH  = (u16LoadValueCpy& 0xFF00)>>8;
    break;
	case CHANNELB:
  OCR1BL  = u16LoadValueCpy& 0x00FF;
  OCR1BH  = (u16LoadValueCpy& 0xFF00)>>8;
    break;
	default:
	break;
}
}
void TIM1_voidSetOutputCompare2Value (uint16 u16LoadValue0Cpy,uint16 u16LoadValue1Cpy)
{
  OCR1AL  = u16LoadValue0Cpy& 0x00FF;
  OCR1AH  = (u16LoadValue0Cpy& 0xFF00)>>8;
  OCR1BL  = u16LoadValue1Cpy& 0x00FF;
  OCR1BH  = (u16LoadValue1Cpy& 0xFF00)>>8;
}
void TIM1_voidEnableOVFInterrupt(void)
{
	SET_BIT(TIMSK , 2) ;
}
void TIM1_voidDisableOVFInterrupt(void)
{
	CLR_BIT(TIMSK , 2) ;
}
void TIM1_voidEnableCTC_A_Interrupt(void)
{
		SET_BIT(TIMSK , 4) ;
}
void TIM1_voidDisableCTC_A_Interrupt(void)
{

	CLR_BIT(TIMSK , 4) ;
}
void TIM1_voidEnableCTC_B_Interrupt(void)
{
		SET_BIT(TIMSK , 3) ;
}
void TIM1_voidDisableCTC_B_Interrupt(void)
{

	CLR_BIT(TIMSK , 3) ;
}
void TIM1_voidEnable_Input Capture_Interrupt(void)
{
		SET_BIT(TIMSK , 5) ;
}
void TIM1_voidDisable_Input Capture_Interrupt(void)
{

	CLR_BIT(TIMSK , 5) ;
}
void TIM1_voidSetOvfCallback(pf pfOvfCallbackCpy)
{
	TIM1_pfOvfCallback = pfOvfCallbackCpy ;

}
void TIM1_voidSetCtcCall_A_back(pf pfCtcCallbackCpy)
{  
	TIM1_pfCtcCallback_A = pfCtcCallbackCpy;

}
void TIM1_voidSetCtcCall_B_back(pf pfCtcCallbackCpy)
{  
	TIM1_pfCtcCallback_B = pfCtcCallbackCpy;

}
void TIM1_voidSetCptr_EvntCall__back(pf pfCptrCallbackCpy)
{  
	TIM1_pfCptrCallback = pfCptrCallbackCpy;

}

void __vector_6 (void) __attribute__((signal ,used));
void __vector_6 (void)
{  
	TIM1_pfCptrCallback();
	if(ic_counter==1){
		first_time_read=(ICR1H<<8)|ICR1L;
		ic_counter++;
		ovf = 0 ;
		CLR_BIT(TCCR1B , 6) ;
	}
	else if(ic_counter==2){
		temp=(ICR1H<<8)|ICR1L +ovf*65536-first_time_read;
		ic_counter++;
		SET_BIT(TCCR1B , 6) ;
	}
	else if(ic_counter==3){
		total_time=(ICR1H<<8)|ICR1L +ovf*65536-first_time_read;
		time_on=temp;
		first_time_read=(ICR1H<<8)|ICR1L;
		ovf = 0 ;
		ic_counter=2;
		CLR_BIT(TCCR1B , 6) ;
		
	}
	
}
/*CM ISR*/
void __vector_7 (void) __attribute__((signal ,used));
void __vector_7 (void)
{  

   TIM1_pfCtcCallback_A();
}

void __vector_8 (void) __attribute__((signal ,used));
void __vector_8 (void)
{  
TIM1_pfCtcCallback_B();
}
void __vector_9 (void) __attribute__((signal ,used));
void __vector_9 (void)
{  
       ovf ++;
   TIM1_pfOvfCallback();
}


void dummy_void(void){
	
}

void input_capture_init_void(void){
	SET_BIT(TCCR1B , 6) ;
	ic_counter=1;
}
void ICUM_voidGetFreqDuty(float32 * pf32FreqCpy , float32 *f32DutyCpy)
{
    *pf32FreqCpy	= 
	(float32)1/((TIM1_PRESCALLER/8*1000000)*total_time) ;
    
	*f32DutyCpy  =  time_on/ total_time ;

}

void enable_noise_cancel_void(void){
		SET_BIT(TCCR1B , 7) ;
}
void disable_noise_cancel_void(){
	CLR_BIT(TCCR1B, 7) ;
	
}
uint16 TIM1_u16GetCntrValue(void ){
	uint16 temp = TCNT1H<<8 ||TCNT1L;
	return temp;
}

void TIM1_voidDelay_ms(uint32 u32DalayTimeCpy)
{  SET_BIT(TIMSK , 4) ;
	OCR1AL  = 250;
	OCR1AH=0;
	delay1 =u32DalayTimeCpy;
	factor1=4;
	u8_used1=1;
	while(counter1<(delay1*factor1));
	CLR_BIT(TIMSK , 4) ;
	counter1=0;


}
void TIM1_voidDelay_Init(void){
  	/* TIM0_MODE == TIM0_CTC_MODE */
	CLR_BIT(TCCR1A , 0);
	CLR_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	CLR_BIT(TCCR1B , 4);
	TCCR1B &= (0xF8);   /* clear reg 0b1111 1000 */
    TCCR1B |=((0x03)& TIM1_PRESCALLER_8) ; /* write in reg */
	 TCNT1H =  0;
     TCNT1L =  0;
	
}
void TIM1_voidDelay_us(uint32 u32DalayTimeCpy)
{   SET_BIT(TIMSK , 4) ;
	OCR1AL = 1;
	OCR1AH=0;
	delay1=u32DalayTimeCpy;
	factor1=1;
	u8_used1=1;
	while(counter1<(delay1*factor1));
	CLR_BIT(TIMSK , 4) ;
	counter1=0;
	
}