/********************************************************************************/
/**    File Name: GPIO_PRIV.h                                                   */
/**                                                                             */
/**  Description: Implementation of the GPIO contain Private file for the module */
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



#ifndef   GPIO_PRIV_H
#define   GPIO_PRIV_H
#include "../../LIB/STD_Types.h"

typedef struct 
{
    uint32 GPIOx_MODER;
    uint32 GPIOx_OTYPER;
    uint32 GPIOx_OSPEEDR;
    uint32 GPIOx_PUPDR;
    uint32 GPIOx_IDR;
    uint32 GPIOx_ODR;
    uint32 GPIOx_BSRR;
    uint32 GPIOx_LCKR;
    uint32 GPIOx_AFRL;
    uint32 GPIOx_AFRH;

}gpio_t;


#define GPIO_MODE_INPUT  00
#define GPIO_MODE_OUTPUT 01
#define GPIO_MODE_ALTFUN 10
#define GPIO_MODE_ANALOG 11


#define GPIOA_Base_Address  0x40020000
#define GPIOB_Base_Address  0x40020400
#define GPIOC_Base_Address  0x40020000

#define GPIOA ((volatile gpio_t *) GPIOA_Base_Address)
#define GPIOB ((volatile gpio_t *) GPIOB_Base_Address)
#define GPIOC ((volatile gpio_t *) GPIOC_Base_Address)

#define   GPIO_PORTA    0
#define   GPIO_PORTB    1
#define   GPIO_PORTC    2

#define GPIO_OPENDRAIN 1
#define GPIO_PUSHPULL  0


#define GPIO_LOW_SPEED 0x00
#define GPIO_MEDIUM_SPEED  0x1
#define GPIO_HIGH_SPEED 0x2
#define GPIO_VERY_HIGH_SPEED 0x3


#define GPIO_NO_PULL 0x00
#define GPIO_PULL_UP 0x01
#define GPIO_PULL_DOWN 0x10

#define GPIO_HIGH 1
#define GPIO_LOW 0

#define GPIOA_PIN_NUM0   0
#define GPIOA_PIN_NUM1   1
#define GPIOA_PIN_NUM2   2
#define GPIOA_PIN_NUM3   3
#define GPIOA_PIN_NUM4   4
#define GPIOA_PIN_NUM5   5
#define GPIOA_PIN_NUM6   6
#define GPIOA_PIN_NUM7   7
#define GPIOA_PIN_NUM8   8
#define GPIOA_PIN_NUM9   9   
#define GPIOA_PIN_NUM10  10
#define GPIOA_PIN_NUM11  11
#define GPIOA_PIN_NUM12  12
#define GPIOA_PIN_NUM13  13
#define GPIOA_PIN_NUM14  14
#define GPIOA_PIN_NUM15  15

#define GPIOB_PIN_NUM0   16
#define GPIOB_PIN_NUM1   17
#define GPIOB_PIN_NUM2   18
#define GPIOB_PIN_NUM3   19
#define GPIOB_PIN_NUM4   20
#define GPIOB_PIN_NUM5   21
#define GPIOB_PIN_NUM6   22
#define GPIOB_PIN_NUM7   23
#define GPIOB_PIN_NUM8   24
#define GPIOB_PIN_NUM9   25  
#define GPIOB_PIN_NUM10  26
#define GPIOB_PIN_NUM11  27
#define GPIOB_PIN_NUM12  28
#define GPIOB_PIN_NUM13  29
#define GPIOB_PIN_NUM14  30
#define GPIOB_PIN_NUM15  31

#endif