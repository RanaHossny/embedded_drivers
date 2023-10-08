/********************************************************************************/
/**    File Name:  SYSTICK.h                                                         */
/**                                                                             */
/**  Description: Implementation of the  SYSTICK  module                             */
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
/** 15/08/2023   0.1       Rana Hossny   Initial Creation                        */
/********************************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include  "SYSTICK_priv.h"
#include  "SYSTICK.h"
#include  "SYSTICK_cfgh"

static void(*Global_Systick_PTR)(void)=NULL_PTR;

void MSTK_voidInit(void){
    if (CLK_SCR== AHB_DIV_8_CLK_CS){
        CLR_BIT(SYSTICK->STK_CTRL,2); //0.5 Ms
    }
    else{
        SET_BIT(SYSTICK->STK_CTRL,2); //0.0625Ms
    }
    
}

void MSTK_voidIntState(void){
SET_BIT(SYSTICK->STK_CTRL,1);
}

void MSTK_voidStart(uint32 Copy_u8PreloadValue){
    SYSTICK->STK_LOAD= Copy_u8PreloadValue;
    SYSTICK->STK_VAL=0;
    SET_BIT(SYSTICK->STK_CTRL,0);


}

uint8 MSTK_u8ReadFlag(void){
    return GET_BIT(SYSTICK->STK_CTRL,16);
}

void MSTK_voidDelayUsec(uint32 Copy_u8DelayUsec){
    uint32 temp_loc=SYSTICK->STK_CTRL;
    CLR_BIT(SYSTICK->STK_CTRL,1);
    if (CLK_SCR== AHB_DIV_8_CLK_CS){
         MSTK_voidStart(Copy_u8DelayUsec*2);
         while (MSTK_u8ReadFlag()==0);
    }
    else{
         MSTK_voidStart(Copy_u8DelayUsec*16);
         while (MSTK_u8ReadFlag()==0);
    }
    if( GET_BIT(temp_loc,1)==1){
        MSTK_voidIntState();
    }
}

void MSTK_voidDelayMsec(uint32 Copy_u8DelayMsec){
    uint32 temp_loc=SYSTICK->STK_CTRL;
    CLR_BIT(SYSTICK->STK_CTRL,1);
    if (CLK_SCR== AHB_DIV_8_CLK_CS){
         MSTK_voidStart(Copy_u8DelayMsec*2000);
         while (MSTK_u8ReadFlag()==0);
    }
    else{
         MSTK_voidStart(Copy_u8DelayMsec*16000);
         while (MSTK_u8ReadFlag()==0);
    }
    if( GET_BIT(temp_loc,1)==1){
        MSTK_voidIntState();
    }

}

void MSTK_voidDelaysec(uint32 Copy_u8Delaysec){

    uint32 temp_loc=SYSTICK->STK_CTRL;
    CLR_BIT(SYSTICK->STK_CTRL,1);
    if (CLK_SCR== AHB_DIV_8_CLK_CS){
         MSTK_voidStart(Copy_u8Delaysec*2000*1000);
         while (MSTK_u8ReadFlag()==0);
    }
    else{
         MSTK_voidStart(Copy_u8Delaysec*16000*1000);
         while (MSTK_u8ReadFlag()==0);
    }
    if( GET_BIT(temp_loc,1)==1){
        MSTK_voidIntState();
    }
}


uint32 MSTK_u32GetElapsedTime(void){
 return (SYSTICK->STK_LOAD)- (SYSTICK->STK_VAL);
}

uint32 MSTK_u32GetRemainingTime(void){
    return (SYSTICK->STK_VAL);
}
void CALLBACKSYS(void(*callback)(void)){
  Global_Systick_PTR= callback;
}

void SysTick_Handler(void){
    Global_Systick_PTR();
    
}
