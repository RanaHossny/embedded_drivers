/********************************************************************************/
/**    File Name: SPI.C                                                        */
/**                                                                             */
/**  Description: Implementation of the SPI contain  of function the module */
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
/**    File Name: SPI.h                                                       */
/**                                                                             */
/**  Description: Implementation of the SPI contain  of header functions the module */
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
#ifndef SPI_H_
#define SPI_H_
void spi_void_intial(void);
void spi_void_read_Syc(uint16 * u8_value_cpy);
uint16 spi_uint8_read_Asyc(void);
void spi_void_write_Syc(uint16 u8_value_cpy);
void spi_void_enable(void);
void spi_void_disable(void );
void spi_void_InterputEmptyEnable(void);
void spi_void_InterputEmptyDisable(void );
void spi_void_InterputReciveDisable(void );
void spi_void_InterputReciveEnable(void);
tenuErrorSpiStatus spi_tenuspi_state(void);
#endif
