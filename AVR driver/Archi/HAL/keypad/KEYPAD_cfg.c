/********************************************************************************/
/**    File Name: LED.h                                                         */
/**                                                                             */
/**  Description: Implementation of the LED contain configuration for the module*/
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
/** Rana          Rana Hossny         ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 22/08/2022   0.1       aaboelno     Initial Creation                        */
/** 28/0/8/2022  0.2       Rana          add more cog                           */
/********************************************************************************/
#include "STD_Types.h"

#include "DIO.h"

#include "KEYPAD_cfg.h"
#include "KEYPAD_priv.h"


tstrKeypadCfg KEYPAD_astrPinCfg [KEYPAD_MAX_NUM]=
{
	/* KEYPAD 0 */
	{
		/* input Pins   */
		{
			DIO_u8PIN_11 , DIO_u8PIN_12 ,
			DIO_u8PIN_13
		}
		,
			/* Output Pins   */
		{
			DIO_u8PIN_14 , DIO_u8PIN_15 ,
			DIO_u8PIN_16 , DIO_u8PIN_17
		}
		,
		KEYPAD0_u8INPUT_PINS_NUM
		,
		KEYPAD0_u8OUTPUT_PINS_NUM,
		ROW_INPUT_COLOUNM_OUTPUT
	}
	,
	/* KEYPAD 1 */
	{
		/* input Pins   */
		{
			DIO_u8PIN_18 , DIO_u8PIN_19 ,
			DIO_u8PIN_20 , DIO_u8PIN_30
		}
		,
			/* Output Pins   */
		{
			  DIO_u8PIN_22 ,DIO_u8PIN_23 , DIO_u8PIN_24 ,
			DIO_u8PIN_25
			
		}
		,
		KEYPAD1_u8INPUT_PINS_NUM
		,
		KEYPAD1_u8OUTPUT_PINS_NUM
		, ROW_OUTPUT_COLOUNM_INPUT
	
	}
};
uint8 arraykaypad0[KEYPAD0_u8INPUT_PINS_NUM*KEYPAD0_u8OUTPUT_PINS_NUM]=   {
		                    '1','2','3'
                           ,'4','5','6'
                   	       ,'7','8','9'
					       ,'*','0','#'};

uint8 arraykaypad1[KEYPAD1_u8INPUT_PINS_NUM*KEYPAD1_u8OUTPUT_PINS_NUM]={
		 '7','8','9','/'
        ,'4','5','6','*'
        ,'1','2','3','-'
	    ,'C','0','=','+'};

uint8 *array [KEYPAD_MAX_NUM]={arraykaypad0 ,arraykaypad1};






