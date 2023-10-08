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
/** Rana          Rana Hossny              ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 22/08/2022   0.1       aaboelno     Initial Creation                        */
/** 22/08/2022   0.1       Rana         modifed keypressed                      */
/********************************************************************************/
#include "STD_Types.h"

#include "DIO.h"

#include "KEYPAD.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_priv.h"
#include<avr/delay.h>


static void KEYPAD_voidWriteSequence(uint8 u8KeyPadNumCpy , uint8 u8SequenceNumCpy);
static void KEYPAD_voidReadSequence(uint8 u8KeyPadNumCpy,uint8 *pu16PressedKeyCpy,uint8 u8Cntrcpy,uint8* count);


void KEYPAD_voidInit(void)
{
	uint8 u8CntrLoc ;
	uint8 u8CntrInputLoc ;
	uint8 u8CntrOutputLoc ;
	for (u8CntrLoc = 0 ; u8CntrLoc < KEYPAD_MAX_NUM; u8CntrLoc++)
	{
		
		for(u8CntrInputLoc = 0 ; u8CntrInputLoc < KEYPAD_astrPinCfg[u8CntrLoc].u8InputPinNum ; u8CntrInputLoc++)
		{
			DIO_enuPullWrite(
			KEYPAD_astrPinCfg[u8CntrLoc].au8InputPins[u8CntrInputLoc] ,
			DIO_u8ACTIVATE);
		}
		
		for(u8CntrOutputLoc = 0 ; u8CntrOutputLoc < KEYPAD_astrPinCfg[u8CntrLoc].u8OutputPinNum ; u8CntrOutputLoc++)
		{
			DIO_enuWritePin(
			KEYPAD_astrPinCfg[u8CntrLoc].au8OutputPins[u8CntrOutputLoc]
			,DIO_u8HIGH);
		}
	}
	
}

tenuErrorStatus KEYPAD_enuGetPressedKey(uint8 u8KeyPadNumCpy , uint8 * pu16PressedKeyCpy, uint8 * size)
{
	tenuErrorStatus enuReturnStateLoc = E_OK ;

	uint8 u8CntrLoc ;
	uint8 u16CntrSwitchLoc =0;
	uint8  u8bufferLoc[100]={0} ;
	uint8 i;
	

	if (pu16PressedKeyCpy != NULL_PTR )
	{
		*pu16PressedKeyCpy = 0 ;
		if (u8KeyPadNumCpy < KEYPAD_MAX_NUM)
		{
			
			for(u8CntrLoc = 0 ; u8CntrLoc < KEYPAD_astrPinCfg[u8KeyPadNumCpy].u8OutputPinNum ;u8CntrLoc++)
			{
	
				KEYPAD_voidWriteSequence(u8KeyPadNumCpy,u8CntrLoc);
				_delay_ms(45);
				KEYPAD_voidReadSequence(u8KeyPadNumCpy,u8bufferLoc+u16CntrSwitchLoc,u8CntrLoc,&u16CntrSwitchLoc);
                
			}

				for(i=0;i<u16CntrSwitchLoc;i++){
					*(pu16PressedKeyCpy+i)=	u8bufferLoc[i];
				}
*size = u16CntrSwitchLoc;
u16CntrSwitchLoc=0;



		}
		else
		{
			enuReturnStateLoc = E_NOK_PARAM_OUT_OF_RANGE ; 
		}
		
	}
	else 
	{
		enuReturnStateLoc = E_NOK_PARAM_NULL_POINTER ;
	}
	
	return enuReturnStateLoc ;
	
}

static void KEYPAD_voidWriteSequence(uint8 u8KeyPadNumCpy , uint8 u8SequenceNumCpy)
{
	uint8 u8CntrLoc ;

	if (u8SequenceNumCpy < KEYPAD_astrPinCfg[u8KeyPadNumCpy].u8OutputPinNum)
	{
		for (u8CntrLoc =0 ;u8CntrLoc< KEYPAD_astrPinCfg[u8KeyPadNumCpy].u8OutputPinNum ; u8CntrLoc++)
		{
			if(u8CntrLoc == u8SequenceNumCpy)
			{
				DIO_enuWritePin(
				KEYPAD_astrPinCfg[u8KeyPadNumCpy].au8OutputPins[u8CntrLoc]
				,DIO_u8LOW);
			}
			else
			{						
				DIO_enuWritePin(
				KEYPAD_astrPinCfg[u8KeyPadNumCpy].au8OutputPins[u8CntrLoc]
				,DIO_u8HIGH);
			}
		
			
		}
		
	}
	else
	{
		
	}
	
	
}

static void KEYPAD_voidReadSequence(uint8 u8KeyPadNumCpy,uint8 *pu16PressedKeyCpy,uint8 u8Cntrcpy,uint8* count)
{
	uint8 u8CntrLoc ;
	uint8 u8BufferLoc = 0 ;
	

	uint8 * ptemp =array[u8KeyPadNumCpy];
	for (u8CntrLoc =0 ;u8CntrLoc< KEYPAD_astrPinCfg[u8KeyPadNumCpy].u8InputPinNum ; u8CntrLoc++)
	{
		DIO_enuReadPin(
		KEYPAD_astrPinCfg[u8KeyPadNumCpy].au8InputPins[u8CntrLoc],&u8BufferLoc);
		if(u8BufferLoc== DIO_u8LOW){
			if(KEYPAD_astrPinCfg[u8KeyPadNumCpy]. u8modeconnection==ROW_INPUT_COLOUNM_OUTPUT){
			*pu16PressedKeyCpy = *(ptemp+((KEYPAD_astrPinCfg[u8KeyPadNumCpy].u8InputPinNum)*u8Cntrcpy+u8CntrLoc));
			}
			else if (KEYPAD_astrPinCfg[u8KeyPadNumCpy]. u8modeconnection==ROW_OUTPUT_COLOUNM_INPUT){
				*pu16PressedKeyCpy = *(ptemp+(u8Cntrcpy+  u8CntrLoc*(KEYPAD_astrPinCfg[u8KeyPadNumCpy].u8OutputPinNum)));
			}
			else{}

			(*count)++;
			
		}
		else{}
		

	}
	
}




















