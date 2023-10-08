/********************************************************************************/
/**    File Name: USART.c                                                         */
/**                                                                             */
/**  Description: Implementation of the USART contain configuration for the module*/
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
/** 8/09/2022   0.1      Rana     Initial Creation                             */
 
/********************************************************************************/
#include "STD_Types.h"

#include "DIO.h"

#include "USART.h"
#include "USART_cfg.h"
#include "USART_priv.h"

void usart_init_void(void){
	
	#if USART_MODE == ASYNCHRONOUS
	CLR_BIT(UCSRC , 6);
	CLR_BIT(UCSRC , 7);
	UBRRH = (uint8)(BAUD_RATE>>8);
    UBRRL = (uint8)BAUD_RATE;
	SET_BIT(UCSRC , 7);
	#elif USART_MODE == SYNCHRONOUS
	SET_BIT(UCSRC , 6);
	#if CLOCK_POLARITY == RISING _TRANS_FALLING_RECEIV
	CLR_BIT(UCSRC,0);
	#elif CLOCK_POLARITY == FALLING _TRANS_RISING_RECEIV
	SET_BIT(UCSRC,0);
	#endif
	
	#endif
	/* SET THE SIZE OF DATA */
	#if DATA_BITS_NUM  ==FIVE_DATA_BIT
	 CLR_BIT(UCSRC,1);
	 CLR_BIT(UCSRC,2);
	 CLR_BIT(UCSRB,2);
	 #elif DATA_BITS_NUM  ==SIX_DATA_BIT 
	 SET_BIT(UCSRC,1);
	 CLR_BIT(UCSRC,2);
	 CLR_BIT(UCSRB,2);
	  #elif DATA_BITS_NUM  ==SEVEN_DATA_BIT 
	 CLR_BIT(UCSRC,1);
	 SET_BIT(UCSRC,2);
	 CLR_BIT(UCSRB,2);
	 #elif DATA_BITS_NUM  ==EIGHT_DATA_BIT  
	 SET_BIT(UCSRC,1);
	 SET_BIT(UCSRC,2);
	 CLR_BIT(UCSRB,2);
	 #elif DATA_BITS_NUM  ==NINE_DATA_BIT  
	 SET_BIT(UCSRC,1);
	 SET_BIT(UCSRC,2);
	 SET_BIT(UCSRB,2);
	#endif
	/*                      */
	/*       set the number of stop bits               */
	#if STOP_BITS_NUM == ONE_STOP_BIT
	 CLR_BIT(UCSRC,3);
	#elif STOP_BITS_NUM == TWO_STOP_BIT
	 SET_BIT(UCSRC,3);
	#endif
	/*                                                  */
	#if  PARITY_MODE == PARITY_MODE_OFF
	CLR_BIT(UCSRC,4);
	CLR_BIT(UCSRC,5);
	#elif PARITY_MODE == PARITY_MODE_ON_EVEN
	CLR_BIT(UCSRC,4);
	SET_BIT(UCSRC,5);
	#elif PARITY_MODE == PARITY_MODE_ON_ODD
	SET_BIT(UCSRC,4);
	SET_BIT(UCSRC,5);
	#endif
	
	
}
void uart_read(uint16 * read_in_u16_cpy){
	SET_BIT(UCSRB , 4);
	while(GET_BIT(UCSRA, 7) ==0);
	*read_in_u16_cpy=UDR;
	#if DATA_BITS_NUM == NINE_DATA_BIT
	 *read_in_u16_cpy|=(GET_BIT(UCSRB, 1)<<8);
	#endif
	CLR_BIT(UCSRB , 4);
}

void uart_write(uint16 write_data_u16_cpy){ 
	SET_BIT(UCSRB , 3);
	while(GET_BIT(UCSRA, 5) ==0);
	URD= write_data_u16_cpy & 0x00ff;
	#if DATA_BITS_NUM == NINE_DATA_BIT
	if(((write_data_u16_cpy>>8)&0x01)==0){
		CLR_BIT(UCSRB , 0);
	}
	else{
		SET_BIT(UCSRB , 0);
	}
	#endif
	
	
}

