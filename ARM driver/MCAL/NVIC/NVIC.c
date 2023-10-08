/********************************************************************************/
/**    File Name: NVIC.c                                                   */
/**                                                                             */
/**  Description: Implementation of the NVIC contain the module */
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
#include"NVIC.h"
#include"NVIC_PRIV.h"
#include"NVIC_CONFG.h"
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
uint32 Global_u32_group_cfg;
tenuErrorStatus MNVIC_vIntrruptSetEnable(uint8 Copy_u8InterruptID){
    if(Copy_u8InterruptID<=INTERUPPT_ID_NUMS){
    uint8 u8_reg_loc= Copy_u8InterruptID/REGISTER_BITS;
    uint8 u8_bit_num_loc=Copy_u8InterruptID%REGISTER_BITS;
    NVIC->NVIC_ISER[u8_reg_loc] |=(1<<u8_bit_num_loc);
    return E_OK;
    }
    else{
	return E_NOK_CONFIG_PARM_ERROR;
    }

}
tenuErrorStatus MNVIC_vIntrruptClearEnable(uint8 Copy_u8InterruptID){
    if(Copy_u8InterruptID<=INTERUPPT_ID_NUMS){
    uint8 u8_reg_loc= Copy_u8InterruptID/REGISTER_BITS;
    uint8 u8_bit_num_loc=Copy_u8InterruptID%REGISTER_BITS;
    NVIC->NVIC_ISER[u8_reg_loc] &=(~(1<<u8_bit_num_loc));
    return E_OK;
    }
    else{
    return E_NOK_CONFIG_PARM_ERROR;
    }
}
void MNVICP_VSetGroup_Mode(Group_Mode COPY_Group_Mode){

	Global_u32_group_cfg=COPY_Group_Mode;
	SCB_AIRCR= MNVIC_VECTKEY |(COPY_Group_Mode<<8);
}
tenuErrorStatus MNVICP_vSetInterruptPeriority(uint8 copy_u8InterruptID, uint8 copy_u8GrouptID, uint8 copy_u8SubGrouptID) {
    switch (Global_u32_group_cfg) {
        case MNVIC_G16_SG0:
            NVIC->NVIC_IPR[copy_u8InterruptID] = copy_u8GrouptID << 4;
            return E_OK;
            break;
        case MNVIC_G8_SG2:
            NVIC->NVIC_IPR[copy_u8InterruptID] = (copy_u8GrouptID << 5 | copy_u8SubGrouptID << 4);
            return E_OK;
            break;
        case MNVIC_G4_SG4:
            NVIC->NVIC_IPR[copy_u8InterruptID] = (copy_u8GrouptID << 6 | copy_u8SubGrouptID << 4);
            return E_OK;
            break;
        case MNVIC_G2_SG8:
            NVIC->NVIC_IPR[copy_u8InterruptID] = (copy_u8GrouptID << 7 | copy_u8SubGrouptID << 4);
            return E_OK;
            break;
        case MNVIC_G0_SG16:
            NVIC->NVIC_IPR[copy_u8InterruptID] = copy_u8SubGrouptID << 4;
            return E_OK;
            break;
        default:
        	 return E_NOK_CONFIG_PARM_ERROR;
            break;
    }
}