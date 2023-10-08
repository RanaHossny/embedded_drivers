/********************************************************************************/
/**    File Name: RCC.h                                                         */
/**                                                                             */
/**  Description: Implementation of the RCC contain configuration for the module*/
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
/** 9/08/2023   0.1       Rana Hossny   Initial Creation                        */
/********************************************************************************/

#ifndef   RCC_CFG_H
#define   RCC_CFG_H

#include "RCC_priv.h"

/* select type of RCC 
options :  RCC_HSI 
           RCC_HSE
		   RCC_PLL 
           */
#define RCC_SYSCLK   RCC_PLL

/* select one of the HSE MODE
RCC_CYSTAL 
RCC_BYPASS
*/
#define RCC_HSE_MODE RCC_BYPASS

/*  The USB OTG FS requires a 48 MHz clock to work correctly. The SDIO and the 
random number generator need a frequency lower than or equal to 48 MHz to work 
correctly.
USB OTG FS clock frequency = VCO frequency / RCC_PLLQ with 2 RCC_PLLQ ≤15*/
#define RCC_PLLQ 2

/* select one of the RCC_PLL_SRC
RCC_PLL_SRC_HSI
RCC_PLL_SRC_HSE
*/
#define RCC_PLL_SRC RCC_PLL_SRC_HSI

/* PLLM must be between 2 and 63*/
#define   RCC_PLLM	5
/* PLLN must be 192 ≤ PLLN ≤ 432*/
#define RCC_PLLN 	192
/* PLLP must be one of the options 
1- RCC_PLLP_2 
2- RCC_PLLP_4 
3- RCC_PLLP_6 
4- RCC_PLLP_8 */
#define RCC_PLLP  RCC_PLLP_2


#endif



