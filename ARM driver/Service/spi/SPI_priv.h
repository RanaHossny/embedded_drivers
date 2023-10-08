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
/**    File Name: SPI_priv.h                                                      */
/**                                                                             */
/**  Description: Implementation of the SPI contain  of private  the module */
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
#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define LSB              0x80
#define MSB              0x00
#define MASTER_MODE           0x04
#define SLAVE_MODE            0x00
#define LEADING_RISING   0x02
#define LEADING_FAILING  0x00
#define FREQ_DIV_2       0x00
#define FREQ_DIV_4       0x08
#define FREQ_DIV_8       0x10
#define FREQ_DIV_16      0x18
#define FREQ_DIV_32      0x20
#define FREQ_DIV_64      0x28
#define FREQ_DIV_128     0x30
#define FREQ_DIV_256     0x38
typedef struct SPI_PRIV
{   uint32 SPI_CR1;
    uint32 SPI_CR2;
    uint32 SPI_SR;
    uint32 SPI_DR;


}SPI_st;
#define SPI1_BASE_ADDRESS (0x40013000)
#define SPI1 (( volatile SPI_st *) SPI1_BASE_ADDRESS)
#define SPI2_BASE_ADDRESS (0x40003800)
#define SPI2 (( volatile SPI_st *) SPI2_BASE_ADDRESS)
#define SPI3_BASE_ADDRESS (0x40003C00)
#define SPI3 (( volatile SPI_st *) SPI3_BASE_ADDRESS)
#define SPI4_BASE_ADDRESS (0x40013400)
#define SPI4 (( volatile SPI_st *) SPI4_BASE_ADDRESS)

#endif
