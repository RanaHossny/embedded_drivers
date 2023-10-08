/********************************************************************************/
/**    File Name: SERVO.c                                                         */
/**                                                                             */
/**  Description: Implementation of the SERVO contain configuration for the module*/
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
/** 7/09/2022   0.1      Rana     Initial Creation                             */
 
/********************************************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "TIM0.h"
#include "PWM.h"
#include "servo.h"
#include "servo_confg.h"
#include "servo_priv.h"
void servo_start(void){
	static uint8 u8countloc=0;
pwm_start_void();
 while(u8countloc<3){
	if(u8countloc==0){
  pwm_stop_void();
	}
	else{
		pwm_increase_dutycycle(ICREASE_IN_DUTY_CYCLE*u8countloc);
		pwm_start_void();
		TIM0_voidDelay_ms(22);
		pwm_stop_void();
	}
	u8countloc++;
}
 u8countloc=0;
}
void servo_stop(void){
	pwm_stop_void();
	
}
