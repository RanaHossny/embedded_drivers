/********************************************************************************/
/**    File Name: EXTI.h                                                         */
/**                                                                             */
/**  Description: Implementation of the EXTI contain interfaces for the module   */
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
/** Rana     Rana Hossny                 ain shams university.               */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 9/08/2023   0.1       Rana Hossny   Initial Creation                        */
/********************************************************************************/

#ifndef   EXTI_H
#define   EXTI_H
#include "../../Lib/STD_Types.h"
typedef enum{
    MEXINT_RE,
    MEXINT_FE,
    MEXINT_ONChange
}Mode;
typedef enum{
    PortA,
    PortB,
    PortC,

}Port;

typedef enum{
    EXINT_RISING_TRIGGER_MODE,
    EXINT_FAILING_TRIGGER_MODE,
    EXINT_ON_CHANGE_MODE,

}Mode;

tenuErrorStatus MEXINT_vInterruptSetEnable(uint8 Copy_u8InterruptLine);
tenuErrorStatus MEXINT_vInterrupt_Software_SetEnable(uint8 Copy_u8InterruptLine);

tenuErrorStatus MEXINT_vInterruptClearEnable(uint8 Copy_u8InterruptLine);
tenuErrorStatus MEXINT_vInterrupt_Event_SetEnable(uint8 Copy_u8InterruptLine);
tenuErrorStatus MEXINT_vInterrupt_Event_ClearEnable(uint8 Copy_u8InterruptLine);
void MEXINTP_VSet_Mode(Mode COPY_Mode, uint8 Copy_u8InterruptLine);
void MEXINTP_vSetSYSCfgEXINT(uint8 copy_u8EXINT_Num ,Port copy_u8Port);
void MEXINT0_vCallBack(void (*ptr)(void));
void MEXINT1_vCallBack(void (*ptr)(void));
void EXIT0_IRQHandler(void);
void EXIT1_IRQHandler(void);

#endif

