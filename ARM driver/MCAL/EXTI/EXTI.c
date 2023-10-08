/********************************************************************************/
/**    File Name: EXTI.C                                                        */
/**                                                                             */
/**  Description: Implementation of the EXTI  module                            */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  STM32F401CCG6                                           */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2023 by Rana Hossny .       All rights reserved.              */
/**                                                                             */
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
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"


#include  "EXTI_CONFG.h"
#include  "EXTI.h"
#include  "EXTI_PRIV.h"
static void(*Global_Exint_PTR[16])(void)={NULL_PTR};

tenuErrorStatus MEXINT_vInterruptSetEnable(uint8 Copy_u8InterruptLine){
    if(Copy_u8InterruptLine>=0 && Copy_u8InterruptLine<=15){
        SET_BIT(EXINT->EXTI_IMR , Copy_u8InterruptLine);
        return E_OK;
    }
    return E_NOK_CONFIG_PARM_ERROR;
}


tenuErrorStatus MEXINT_vInterruptClearEnable(uint8 Copy_u8InterruptLine){
        if(Copy_u8InterruptLine>=0 && Copy_u8InterruptLine<=15){
        CLK_BIT(EXINT->EXTI_IMR , Copy_u8InterruptLine);
        return E_OK;
    }
    return E_NOK_CONFIG_PARM_ERROR;

}
tenuErrorStatus MEXINT_vInterrupt_Software_SetEnable(uint8 Copy_u8InterruptLine){
        if(Copy_u8InterruptLine>=0 && Copy_u8InterruptLine<=15){
        SET_BIT(EXINT->EXTI_SWIER , Copy_u8InterruptLine);
        return E_OK;
    }
    return E_NOK_CONFIG_PARM_ERROR;

}


tenuErrorStatus MEXINT_vInterrupt_Event_SetEnable(uint8 Copy_u8InterruptLine){
        if(Copy_u8InterruptLine>=0 && Copy_u8InterruptLine<=15){
        SET_BIT(EXINT->EXTI_EMR , Copy_u8InterruptLine);
        return E_OK;
    }
    return E_NOK_CONFIG_PARM_ERROR;
}

tenuErrorStatus MEXINT_vInterrupt_Event_ClearEnable(uint8 Copy_u8InterruptLine){
    if(Copy_u8InterruptLine>=0 && Copy_u8InterruptLine<=15){
        CLK_BIT(EXINT->EXTI_EMR , Copy_u8InterruptLine);
        return E_OK;
    }
    return E_NOK_CONFIG_PARM_ERROR;
}

void MEXINTP_vSetSYSCfgEXINT(uint8 copy_u8EXINT_Num ,Port copy_u8Port){
   SYSEXINT-> SYSCFG_EXTICR[copy_u8EXINT_Num/4]&=~(0b1111 << ((copy_u8EXINT_Num%4)*4));
   SYSEXINT-> SYSCFG_EXTICR[copy_u8EXINT_Num/4]|=(copy_u8Port << ((copy_u8EXINT_Num%4)*4));
}

void MEXINTP_VSet_Mode(Mode COPY_Mode, uint8 Copy_u8InterruptLine) {
    switch (COPY_Mode) {
        case EXINT_RISING_TRIGGER_MODE:
            SET_BIT(EXINT->EXTI_RTSR, Copy_u8InterruptLine);
            CLR_BIT(EXINT->EXTI_FTSR, Copy_u8InterruptLine);
            break;
        case EXINT_FAILING_TRIGGER_MODE:
            SET_BIT(EXINT->EXTI_FTSR, Copy_u8InterruptLine);
            CLR_BIT(EXINT->EXTI_RTSR, Copy_u8InterruptLine);
            break;
        case EXINT_ON_CHANGE_MODE:
            SET_BIT(EXINT->EXTI_RTSR, Copy_u8InterruptLine);
            SET_BIT(EXINT->EXTI_FTSR, Copy_u8InterruptLine);
            break;
        default:
            break;
    }
}

void MEXINT0_vCallBack(void (*ptr)(void)){
Global_Exint_PTR[0]=ptr;
}
void MEXINT1_vCallBack(void (*ptr)(void)){
Global_Exint_PTR[1]=ptr;

}
void EXIT0_IRQHandler(void){
Global_Exint_PTR[0]();
SET_BIT(EXINT->EXTI_PR , 0);
}
void EXIT1_IRQHandler(void){
Global_Exint_PTR[1]();
SET_BIT(EXINT->EXTI_PR , 1);
}