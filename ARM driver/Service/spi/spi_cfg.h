/********************************************************************************/
/**    File Name: SPI_cfg.h                                                       */
/**                                                                             */
/**  Description: Implementation of the SPI contain  of config the module */
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
/** 23/08/2023   0.1       Rana Hossny   Initial Creation                        */
/********************************************************************************/
/********************************************************************************/
/**    File Name: SPI_cfg.h                                                        */
/**                                                                             */
/**  Description: Implementation of the SPI contain  of config the module */
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
/** 23/08/2023   0.1       Rana Hossny   Initial Creation                        */
/********************************************************************************/
#ifndef SPI_CFG_H_
#define SPI_CFG_H_


/*  LSB      MSB */
#define DATA_ORDER_First   LSB
/*  MASTER_MODE      SLAVE_MODE       */
#define SPI_MODE    SLAVE_MODE
/* LEADING_RISING  LEADING_FAILING */
#define SPI_POLARITY_CLK  LEADING_FAILING
/* FIRST_CLK   SEC_CLK */
#if SPI_MODE==MASTER_MODE
/* FREQ_DIV_2   FREQ_DIV_4  FREQ_DIV_8  FREQ_DIV_16  FREQ_DIV_32  FREQ_DIV_64  FREQ_DIV_128*/
#define SCK_FREQUENCY  FREQ_DIV_8
#endif
#endif
