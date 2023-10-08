/********************************************************************************/
/**    File Name: NVIC_PRIV.h                                                   */
/**                                                                             */
/**  Description: Implementation of the NVIC contain Private file for the module */
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
/** 13/08/2023   0.1       Rana Hossny   Initial Creation                        */
/********************************************************************************/



#ifndef   NVIC_PRIV_H
#define   NVIC_PRIV_H
#include "../../LIB/STD_Types.h"
#define MNVIC_BASE_ADDRESS (0xE000E100)
typedef struct NVIC_PRIV
{   uint32 NVIC_ISER[8];
    uint32 reserved_1[24];
    uint32 NVIC_ICER[8];
    uint32 reserved_2[24];
    uint32 NVIC_ISPR[8];
    uint32 resirved_3[24];
    uint32 NVIC_ICPR[8];
    uint32 reserved_4[24];
    uint32 NVIC_IABR[8];
    uint32 resirved_5[56];
    uint8 NVIC_IPR[240];
    uint32 reserved_6[580];
    uint32 NVIC_STIR;

}NVIC_t;
#define NVIC (( volatile NVIC_t *) MNVIC_BASE_ADDRESS)
#define SCB_AIRCR *(( volatile uint32 *) 0xE000ED0C)
#define MNVIC_VECTKEY  0X05FA0000
#define REGISTER_BITS 32
#define INTERUPPT_ID_NUMS 84
#endif