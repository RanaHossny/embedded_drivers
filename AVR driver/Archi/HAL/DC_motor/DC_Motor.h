/********************************************************************************/
/**    File Name: DC_Motor.h                                                    */
/**                                                                             */
/**  Description: Implementation of the DC_Motor contain configuration for the module*/
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
/** Rana         Rana Hossny          ITI.                                      */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 31/08/2022   0.1       Rana     Initial Creation                       */
/********************************************************************************/
#ifndef DC_Motor_H
#define DC_Motor_H

#include "DC_Motor_cfg.h"

tenuErrorStatus Motor_enuStart (uint8 u8MotorNumCpy);
tenuErrorStatus Motor_enuStop (uint8 u8MotorNumCpy);
tenuErrorStatus Motor_enuChangeDir (uint8 u8MotorNumCpy );



#endif









