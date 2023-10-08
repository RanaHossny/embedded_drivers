/********************************************************************************/
/**    File Name: NVIC.h                                                   */
/**                                                                             */
/**  Description: Implementation of the NVIC contain header of function the module */
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



#ifndef   NVIC_H
#define   NVIC_H
#include "../../Lib/STD_Types.h"

typedef enum{
    MNVIC_G16_SG0=3,
    MNVIC_G8_SG2,
    MNVIC_G4_SG4,
    MNVIC_G2_SG8,
    MNVIC_G0_SG16
}Group_Mode;

tenuErrorStatus MNVIC_vIntrruptSetEnable(uint8 Copy_u8InterruptID);
tenuErrorStatus MNVIC_vIntrruptClearEnable(uint8 Copy_u8InterruptID);
void MNVICP_VSetGroup_Mode(Group_Mode COPY_Group_Mode);
tenuErrorStatus MNVICP_vSetInterruptPeriority(uint8 copy_u8InterruptID ,uint8 copy_u8GrouptID ,uint8 copy_u8SubGrouptID);
#endif