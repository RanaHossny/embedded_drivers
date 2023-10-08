/********************************************************************************/
/**    File Name: GPIO.c                                                   */
/**                                                                             */
/**  Description: Implementation of the GPIO contain the module */
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
#include"GPIO.h"
#include"GPIO_PRIV.h"
#include"GPIO_CONFG.h"
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"


tenuErrorStatus MGPIO_vSetPinMode(uint8 u8_PortId, uint8 u8_PinNo , uint8 u8_PinMode){
if (u8_PinMode==GPIO_MODE_INPUT ||u8_PinMode==GPIO_MODE_OUTPUT ||u8_PinMode==GPIO_MODE_ALTFUN
|| u8_PinMode==GPIO_MODE_ANALOG )
{
   switch(u8_PortId){
    case GPIO_PORTA :
            GPIOA ->GPIOx_MODER &= ~(0b11<<(u8_PinNo*2));
            GPIOA ->GPIOx_MODER |=(u8_PinMode<<(u8_PinNo*2)); 
            return E_OK; 

       
    case GPIO_PORTB:
            GPIOB ->GPIOx_MODER &= ~(0b11<<(u8_PinNo*2));
            GPIOB ->GPIOx_MODER |=(u8_PinMode<<(u8_PinNo*2));
            return E_OK;
    case GPIO_PORTC:
            GPIOC ->GPIOx_MODER &= ~(0b11<<(u8_PinNo*2));
            GPIOC ->GPIOx_MODER |=(u8_PinMode<<(u8_PinNo*2));
            return E_OK;
 }
}
   return E_NOK_CONFIG_PARM_ERROR;
}

tenuErrorStatus MGPIO_vSetPinOutputType(uint8 u8_PortId, uint8 u8_PinNo , uint8 u8_PinOutputType){

if(u8_PinOutputType== GPIO_OPENDRAIN){
     switch(u8_PortId){
    case GPIO_PORTA :
        SET_BIT(GPIOA->GPIOx_OTYPER,u8_PinNo);
         return E_OK;
    case GPIO_PORTB:
        SET_BIT(GPIOA->GPIOx_OTYPER,u8_PinNo);   
         return E_OK;
    case GPIO_PORTC:
        SET_BIT(GPIOA->GPIOx_OTYPER,u8_PinNo);
         return E_OK;
 }
}
else if (u8_PinOutputType== GPIO_PUSHPULL)
{
      switch(u8_PortId){
    case GPIO_PORTA :
       CLR_BIT(GPIOA->GPIOx_OTYPER,u8_PinNo);
        return E_OK;
    case GPIO_PORTB:
        CLR_BIT(GPIOA->GPIOx_OTYPER,u8_PinNo);   
         return E_OK;
    case GPIO_PORTC:
        CLR_BIT(GPIOA->GPIOx_OTYPER,u8_PinNo);
        return E_OK;
}}
 return E_NOK_CONFIG_PARM_ERROR;
}


tenuErrorStatus MGPIO_vSetPinOutputSpeed(uint8 u8_PortId, uint8 u8_PinNo , uint8 u8_PinSpeed){
if (u8_PinSpeed==GPIO_LOW_SPEED ||u8_PinSpeed==GPIO_MEDIUM_SPEED ||u8_PinSpeed==GPIO_HIGH_SPEED
|| u8_PinSpeed==GPIO_VERY_HIGH_SPEED )
{
   switch(u8_PortId){
    case GPIO_PORTA :
            GPIOA ->GPIOx_OSPEEDR &= ~(0b11<<(u8_PinNo*2));
            GPIOA ->GPIOx_OSPEEDR |=(u8_PinSpeed<<(u8_PinNo*2));  

       return E_OK;
    case GPIO_PORTB:
            GPIOB ->GPIOx_OSPEEDR &= ~(0b11<<(u8_PinNo*2));
            GPIOB ->GPIOx_OSPEEDR |=(u8_PinSpeed<<(u8_PinNo*2));
        return E_OK;
    case GPIO_PORTC:
            GPIOC ->GPIOx_OSPEEDR &= ~(0b11<<(u8_PinNo*2));
            GPIOC ->GPIOx_OSPEEDR |=(u8_PinSpeed<<(u8_PinNo*2));
        return E_OK;
}
}
return E_NOK_CONFIG_PARM_ERROR;

}


tenuErrorStatus MGPIO_vSetPinInputPull(uint8 u8_PortId, uint8 u8_PinNo , uint8 u8_PullType){

if (u8_PullType==GPIO_NO_PULL ||u8_PullType==GPIO_PULL_UP ||u8_PullType==GPIO_PULL_DOWN
 )
{
   switch(u8_PortId){
    case GPIO_PORTA :
            GPIOA ->GPIOx_PUPDR &= ~(0b11<<(u8_PinNo*2));
            GPIOA ->GPIOx_PUPDR |=(u8_PullType<<(u8_PinNo*2));  

        return E_OK;
    case GPIO_PORTB:
            GPIOB ->GPIOx_PUPDR &= ~(0b11<<(u8_PinNo*2));
            GPIOB ->GPIOx_PUPDR |=(u8_PullType<<(u8_PinNo*2));
        return E_OK;
    case GPIO_PORTC:
            GPIOC ->GPIOx_PUPDR &= ~(0b11<<(u8_PinNo*2));
            GPIOC ->GPIOx_PUPDR |=(u8_PullType<<(u8_PinNo*2));
        return E_OK;
 }
}
return E_NOK_CONFIG_PARM_ERROR;
}


uint8 MGPIO_u8GetPinVal(uint8 u8_PortId,uint8 u8_PinNo ){
    uint8 L_u8PinVal=0;
    switch(u8_PortId){
    case GPIO_PORTA :
        L_u8PinVal=GET_BIT(GPIOA->GPIOx_IDR,u8_PinNo)   ;
        break;
    case GPIO_PORTB:
        L_u8PinVal=GET_BIT(GPIOB->GPIOx_IDR,u8_PinNo)   ; 
        break;
    case GPIO_PORTC:
        L_u8PinVal=GET_BIT(GPIOC->GPIOx_IDR,u8_PinNo)   ;   
        break;
 }
return L_u8PinVal;
}


void MGPIO_u8SetPinVal(uint8 u8_PortId,uint8 u8_PinNo, uint8 u8_Pin_Value ){
    if(u8_Pin_Value==GPIO_HIGH){
         switch(u8_PortId){
            case GPIO_PORTA :
                SET_BIT(GPIOA->GPIOx_ODR,u8_PinNo)   ;
                break;
            case GPIO_PORTB:
                SET_BIT(GPIOB->GPIOx_ODR,u8_PinNo)   ; 
                break;
            case GPIO_PORTC:
                SET_BIT(GPIOC->GPIOx_ODR,u8_PinNo)   ;   
                break;
        }
    }
    else{
         switch(u8_PortId){
            case GPIO_PORTA :
                CLR_BIT(GPIOA->GPIOx_ODR,u8_PinNo)   ;
                break;
            case GPIO_PORTB:
                CLR_BIT(GPIOB->GPIOx_ODR,u8_PinNo)   ; 
                break;
            case GPIO_PORTC:
                CLR_BIT(GPIOC->GPIOx_ODR,u8_PinNo)   ;   
                break;
        }

    }
}
uint8 MGPIO_u8TogglePinVal(uint8 u8_PortId,uint8 u8_PinNo){
    uint8 u8_val_loc= MGPIO_u8GetPinVal( u8_PortId, u8_PinNo );
    MGPIO_u8SetPinVal( u8_PortId,u8_PinNo, u8_val_loc);
    
}

void MGPIO_vSetAlternativeFunction(uint8 u8_PortId,uint8 u8_PinNo,Alternative_function u8_Alternative_Function){
if(u8_Alternative_Function>=0 && u8_Alternative_Function<=15 && u8_PinNo<8){
    switch(u8_PortId){
    case GPIO_PORTA :
            GPIOA ->GPIOx_AFRL &= ~(0b1111<<(u8_PinNo*4));
            GPIOA ->GPIOx_AFRL |=(u8_Alternative_Function<<(u8_PinNo*4));

        break;
    case GPIO_PORTB:
            GPIOB ->GPIOx_AFRL &= ~(0b1111<<((u8_PinNo*4)%8));
            GPIOB ->GPIOx_AFRL |=(u8_Alternative_Function<<((u8_PinNo*4)%8));
        break;
    case GPIO_PORTC:
            GPIOC ->GPIOx_AFRL &= ~(0b1111<<((u8_PinNo*4)%8));
            GPIOC ->GPIOx_AFRL |=(u8_Alternative_Function<<((u8_PinNo*4)%8));
        break;
 }

}
else{
      switch(u8_PortId){
    case GPIO_PORTA :
            GPIOA ->GPIOx_AFRH &= ~(0b1111<<((u8_PinNo%8)*4));
            GPIOA ->GPIOx_AFRH |=(((u8_Alternative_Function))<<((u8_PinNo%8)*4));

        break;
    case GPIO_PORTB:
            GPIOB ->GPIOx_AFRH &= ~(0b1111<<((u8_PinNo%8)*4));
            GPIOB ->GPIOx_AFRH |=(((u8_Alternative_Function))<<((u8_PinNo%8)*4));
        break;
    case GPIO_PORTC:
            GPIOC ->GPIOx_AFRH &= ~(0b1111<<((u8_PinNo%8)*4));
            GPIOC ->GPIOx_AFRH |=(((u8_Alternative_Function))<<((u8_PinNo%8)*4));
        break;
 }

}
}

tenuErrorStatus MGPIO_u8SetPinValFast(uint8 u8_PortId,uint8 u8_PinNo, uint8 u8_Pin_Value ){
    if(u8_Pin_Value==GPIO_HIGH){
        switch(u8_PortId){
            case GPIO_PORTA :
                GPIOA->GPIOx_BSRR |= 1<<u8_PinNo  ;
                return E_OK;
              
            case GPIO_PORTB:
                GPIOB->GPIOx_BSRR |= 1<<u8_PinNo  ;
                return E_OK;
            case GPIO_PORTC:
                GPIOC->GPIOx_BSRR |= 1<<u8_PinNo  ;
                return E_OK;
            default:
                return E_NOK_CONFIG_PARM_ERROR;
               
        }

    }
    else if(u8_Pin_Value==GPIO_LOW){
        switch(u8_PortId){
            case GPIO_PORTA :
                GPIOA->GPIOx_BSRR |= 1<<(u8_PinNo+16)  ;
                return E_OK;
                
            case GPIO_PORTB:
                 GPIOB->GPIOx_BSRR |= 1<<(u8_PinNo+16)  ;
                 return E_OK;
                
            case GPIO_PORTC:
                 GPIOC->GPIOx_BSRR |= 1<<(u8_PinNo+16)  ;
                 return E_OK;
            default:
                return E_NOK_CONFIG_PARM_ERROR;

                
        }

    }
    return E_NOK_CONFIG_PARM_ERROR;

    
}