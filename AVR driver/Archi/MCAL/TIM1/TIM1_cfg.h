/********************************************************************************/
/**    File Name: TIM1_cfg.h                                                         */
/**                                                                             */
/**  Description: Implementation of the TIM1 contain configuration for the module*/
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

#ifndef TIM1_CFG_H
#define TIM1_CFG_H

#define TIM1_MODE_OPERATION         TIM1_NORMAL_MODE
#define TIM1_PRESCALLER          TIM1_PRESCALLER_8
#define  CHANNEL_MODE             CHANNELA
#define  COMPARE_OUTPUT_MODE       OC1A_OR_OC1B_DISCONNECTED 
#define  OUTPUT_MODE             NON_PWM_MODE 
  

#endif 