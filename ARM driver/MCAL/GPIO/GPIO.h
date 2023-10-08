/********************************************************************************/
/**    File Name: GPIO.h                                                   */
/**                                                                             */
/**  Description: Implementation of the GPIO contain header of function the module */
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



#ifndef   GPIO_H
#define   GPIO_H
#include "../../LIB/STD_Types.h"
#include "GPIO_PRIV.h"

typedef enum{
    AF0H_SYSTEM    ,          
  AF1H_TIM1_TIM2   ,        
  AF2H_TIM3_TO_5   ,        
  AF3H_TIM9_TO_11  ,        
  AF4H_L2C1_TO_3   ,        
  AF5H_SPI1_TO_4   ,        
  AF6H_SPI3        ,        
  AF7H_USART1_TO_2 ,        
  AF8H_USART6      ,        
  AF9H_I2C2_TO_3   ,        
  AF10H_OTG_FS     ,       
  AF11H            ,       
  AF12H_SDIO       ,       
  AF13H            ,       
  AF14H            ,       
  AF15H_EVENT_OUT  ,       
 AF0L_SYSTEM       ,      
 AF1L_TIM1_TIM2    ,      
 AF2L_TIM3_TO_5    ,      
 AF3L_TIM9_TO_11   ,      
 AF4L_L2C1_TO_3    ,      
 AF5L_SPI1_TO_4    ,      
 AF6L_SPI3         ,      
 AF7L_USART1_TO_2  ,      
 AF8L_USART6       ,      
 AF9L_I2C2_TO_3    ,      
 AF10L_OTG_FS      ,       
 AF11L             ,       
 AF12L_SDIO        ,       
 AF13L             ,       
 AF14L             ,       
 AF15L_EVENT_OUT  
}Alternative_function;


/* u8_PortId option : select one 
GPIO_PORTA
GPIO_PORTB
GPIO_PORTC
*/
tenuErrorStatus MGPIO_vSetPinMode(uint8 u8_PortId, uint8 u8_PinNo , uint8 u8_PinMode);
/* u8_PinOutputType select one option :
GPIO_OPENDRAIN
GPIO_PUSHPULL
*/
tenuErrorStatus MGPIO_vSetPinOutputType(uint8 u8_PortId, uint8 u8_PinNo , uint8 u8_PinOutputType);
/* u8_PinSpeed select one option :
GPIO_LOW_SPEED
GPIO_MEDIUM_SPEED
GPIO_HIGH_SPEED
GPIO_VERY_HIGH_SPEED
 */
tenuErrorStatus MGPIO_vSetPinOutputSpeed(uint8 u8_PortId, uint8 u8_PinNo , uint8 u8_PinSpeed);
/* u8_PullType : Select one option 
GPIO_NO_PULL
GPIO_PULL_UP
GPIO_PULL_DOWN
*/
tenuErrorStatus MGPIO_vSetPinInputPull(uint8 u8_PortId, uint8 u8_PinNo , uint8 u8_PullType);

uint8 MGPIO_u8GetPinVal(uint8 u8_PortId,uint8 u8_PinNo );
/*u8_Pin_Value : Select one option :
GPIO_HIGH 
GPIO_LOW
 */
void MGPIO_u8SetPinVal(uint8 u8_PortId,uint8 u8_PinNo, uint8 u8_Pin_Value );
tenuErrorStatus MGPIO_u8SetPinValFast(uint8 u8_PortId,uint8 u8_PinNo, uint8 u8_Pin_Value );
uint8 MGPIO_u8TogglePinVal(uint8 u8_PortId,uint8 u8_PinNo);
void MGPIO_vSetAlternativeFunction(uint8 u8_PortId,uint8 u8_PinNo,Alternative_function u8_Alternative_Function);
#endif