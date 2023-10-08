/********************************************************************************/
/**    File Name:  SYSTICK_priv.h                                                         */
/**                                                                             */
/**  Description: Implementation of the  SYSTICK contain Private file for the module */
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
/** 15/08/2023   0.1       Rana Hossny   Initial Creation                        */
/********************************************************************************/

#ifndef    SYSTICK_PRIV_H
#define    SYSTICK_PRIV_H
#include "../../LIB/STD_Types.h"

typedef struct {
  uint32 STK_CTRL ;
  uint32 STK_LOAD ;
  uint32  STK_VAL;
  uint32 STK_CALIB;
} SYSTICK_T ;
#define  SYSTICK_BASE 0xE000E010
#define  SYSTICK (( SYSTICK_T *)  SYSTICK_BASE)

#define  AHB_DIV_8_CLK_CS   0
#define  AHB_CLK_CS         1 
#endif



