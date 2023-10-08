/********************************************************************************/
/**    File Name: SYSTICK_CFG.h                                                         */
/**                                                                             */
/**  Description: Implementation of the SYSTICK contain configuration for the module*/
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
/** Rana    Rana Hossny                 ain shams university.               */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 15/08/2023   0.1       Rana Hossny   Initial Creation                        */
/********************************************************************************/

#ifndef   SYSTICK_CFG_H
#define   SYSTICK_CFG_H

#include "SYSTICK_priv.h"
/* 
OPTIONS: 
AHB_DIV_8_CLK_CS
AHB_CLK_CS
*/
# define CLK_SCR  AHB_DIV_8_CLK_CS

#endif



