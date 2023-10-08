/********************************************************************************/
/**    File Name: SLAVE_TWI.h                                                       */
/**                                                                             */
/**  Description: Implementation of the TWI contain configuration for the module*/
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
/** 14/09/2022   0.1      Rana     Initial Creation                             */
 
/********************************************************************************/

#ifndef SLAVE_TWI_H
#define SLAVE_TWI_H

void TWI_init_slave(void);
void TWI_write_slave(uint8 data);
uint8 TWI_read_slave(void);
void TWI_match_read_slave(void);
void TWI_match_write_slave(void);



#endif
