/********************************************************************************/
/**    File Name: UART.C                                                        */
/**                                                                             */
/**  Description: Implementation of the UART contain  of function the module */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  STM32F401CCG6                                           */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2023 by Rana Hossny .       All rights reserved.              */
/**                                                                             */
/** This software is copyright protected and proprietary                        */
/** to ITI.                                                                     */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Company                              */
/** --------     ---------------------     -------------------------------------*/
/** Rana    Rana Hossny                 ain shams university.               */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 23/08/2023   0.1       Rana Hossny   Initial Creation                        */
/********************************************************************************/
#include "../../Lib/STD_Types.h"
#include "../../Lib/BIT_Math.h"
#include "UART.h"
#include "UART_PRIV.h"
#include "UART_CFG.h"
void vUART_Init(){
    int i=0;
    for(int i=0;i<NUM_UART_USED;i++){
        SET_BIT(uart_astruartPinMapping[i].UART_USED->USART_CR1,13);
           uart_astruartPinMapping[i].UART_USED->USART_BRR=uart_astruartPinMapping[i].BAUD_RATE;
    if (uart_astruartPinMapping[i].LB== NINE_BITS)
    {
        SET_BIT(uart_astruartPinMapping[i].UART_USED->USART_CR1,12);
       
    }
    else{
        CLR_BIT(uart_astruartPinMapping[i].UART_USED->USART_CR1,12);
    }
    if(uart_astruartPinMapping[i].PM==ODD_PARITY){
            SET_BIT(uart_astruartPinMapping[i].UART_USED->USART_CR1,9);
        }
     else{
            CLR_BIT(uart_astruartPinMapping[i].UART_USED->USART_CR1,9);
        }
    if(uart_astruartPinMapping[i].PE==WITH_PARITY){
        SET_BIT(uart_astruartPinMapping[i].UART_USED->USART_CR1,10);
    }
    else{
        CLR_BIT(uart_astruartPinMapping[i].UART_USED->USART_CR1,10);
    }

     SET_BIT(uart_astruartPinMapping[i].UART_USED->USART_CR1,3);
     SET_BIT(uart_astruartPinMapping[i].UART_USED->USART_CR1,2);
    if(uart_astruartPinMapping[i].BM==WITH_BREAK){ 
        SET_BIT(uart_astruartPinMapping[i].UART_USED->USART_CR1,0);
    }
    else{
        CLR_BIT(uart_astruartPinMapping[i].UART_USED->USART_CR1,0);
    }
    uart_astruartPinMapping[i].UART_USED->USART_CR2&=~(0b11<<12);
    uart_astruartPinMapping[i].UART_USED->USART_CR2|= uart_astruartPinMapping[i].SN<<12;

    }

}
void v_Send_byte(uint16 data, uint8 uart_indx){

	    uart_astruartPinMapping[uart_indx].UART_USED->USART_DR=data;
	    while ( !GET_BIT(uart_astruartPinMapping[uart_indx].UART_USED->USART_SR,6));


}


uint16 u16_receive_data( uint8 uart_indx){

while ( !GET_BIT(uart_astruartPinMapping[uart_indx].UART_USED->USART_SR,5));
  if (uart_astruartPinMapping[uart_indx].LB== NINE_BITS)
   {
	return  uart_astruartPinMapping[uart_indx].UART_USED->USART_DR & 0x01ff;

   }
   else{
		return  uart_astruartPinMapping[uart_indx].UART_USED->USART_DR & 0x0ff;

   }
}
