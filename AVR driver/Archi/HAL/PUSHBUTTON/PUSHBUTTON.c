/********************************************************************************/
/**    File Name: PUSHBUTTON.h                                                         */
/**                                                                             */
/**  Description: Implementation of the PUSHBUTTON contain configuration for the module*/
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

#include "DIO.h"

#include "PUSHBUTTON.h"
#include "PUSHBUTTON_cfg.h"
#include "PUSHBUTTON_priv.h"


tenuErrorStatus pushbutton_intial(){
	tenuErrorStatus error = E_OK;
	uint8 u8counterloc;
	for(u8counterloc=0;u8counterloc<PUSHBUTTON_MAX_NUM;u8counterloc++ ){
		if(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8counterloc].u8DioPinMap>=DIO_u8PIN_0  ||
				PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8counterloc].u8DioPinMap<=DIO_u8PIN_31){
			
			if(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8counterloc].u8PUSHBUTTIONModeConc==PULLUP_CONNECTION){
				DIO_enuPullWrite(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8counterloc].u8DioPinMap, DIO_u8ACTIVATE );
			}
			else if(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8counterloc].u8PUSHBUTTIONModeConc==PULLDOWN_CONNECTION){
				DIO_enuPullWrite(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8counterloc].u8DioPinMap, DIO_u8DEACTIVATE );
			}
			else{
				error=E_NOK_CONFIG_PARM_ERROR;
			}
			
		}
		else{
			error=E_NOK_PARAM_OUT_OF_RANGE;
		}
	}
	return error;
}

tenuErrorStatus pushbutton_enureadState (uint8 u8PUSHBUTTONNumCpy , uint8 * u8PUSHBUTTONValueCpy){
	tenuErrorStatus error = E_OK;
	
	
	if(u8PUSHBUTTONValueCpy!=NULL_PTR){
		if(u8PUSHBUTTONNumCpy<PUSHBUTTON_MAX_NUM){
		DIO_enuReadPin(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8PUSHBUTTONNumCpy].u8DioPinMap, u8PUSHBUTTONValueCpy );
	if(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8PUSHBUTTONNumCpy].u8PUSHBUTTIONModeConc==PULLUP_CONNECTION){
				if(*u8PUSHBUTTONValueCpy == DIO_u8LOW){
					*u8PUSHBUTTONValueCpy =PUSHBUTTON_PRESSED;
				}
				else{
					*u8PUSHBUTTONValueCpy =PUSHBUTTON_NOT_PRESSED ;
				
				}
			}
			else if(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8PUSHBUTTONNumCpy].u8PUSHBUTTIONModeConc==PULLDOWN_CONNECTION){
				if(*u8PUSHBUTTONValueCpy == DIO_u8HIGH ){
					*u8PUSHBUTTONValueCpy =PUSHBUTTON_PRESSED;
				}
				else{
					*u8PUSHBUTTONValueCpy =PUSHBUTTON_NOT_PRESSED ;
				
				}
				
			}

		else{
			error=E_NOK_PARAM_OUT_OF_RANGE;
		}

		}
		else{
						error=E_NOK_CONFIG_PARM_ERROR;
					}

	}
	else{
		error=E_NOK_PARAM_NULL_POINTER;
	}
	return error;
}

