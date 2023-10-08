/********************************************************************************/
/**    File Name: UART_PRIV.h                                                    */
/**                                                                             */
/**  Description: Implementation of the UART contain PRIV the module            */
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

#ifndef   UART_PRIV_H
#define   UART_PRIV_H
#include "../../Lib/STD_Types.h"
#include"UART_CFG.h"
typedef struct 
{
    uint32 USART_SR;
    uint32 USART_DR;
    uint32 USART_BRR;
    uint32 USART_CR1;
    uint32 USART_CR2;
    uint32 USART_CR3;
    uint32 USART_GTPR;

} UART_t;

typedef enum {
    EIGHT_BITS,
    NINE_BITS
}LENGTH_DATA_BITS;

typedef enum {
    NO_PARITY,
    WITH_PARITY
}PARITY_ENABLE;

typedef enum {
   EVEN_PARITY ,
   ODD_PARITY
}PARITY_MODE;

typedef enum {
    NO_BREAK,
    WITH_BREAK

}BREAK_MODE;

typedef enum {
    ONE_STOP_BIT,
    HALF_STOP_BIT,
    TWO_STOP_BIT
}STOP_BIT_NUM;

typedef struct {
    UART_t*  UART_USED;
    uint32 BAUD_RATE;
    LENGTH_DATA_BITS LB;
    PARITY_ENABLE PE;
    PARITY_MODE PM;
    BREAK_MODE BM;
    STOP_BIT_NUM  SN;
}UART_CONG_T;
extern UART_CONG_T uart_astruartPinMapping[NUM_UART_USED];

#define UART1_Base_Address   0x40011000
#define UART1 ((volatile UART_t *) UART1_Base_Address)


#define UART6_Base_Address  0x40011400
#define UART6 ((volatile UART_t *) UART6_Base_Address)

#define UART2_Base_Address  0x40004400
#define UART2 ((volatile UART_t *) UART2_Base_Address)




#endif