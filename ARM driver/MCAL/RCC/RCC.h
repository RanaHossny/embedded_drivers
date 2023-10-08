/********************************************************************************/
/**    File Name: RCC.h                                                         */
/**                                                                             */
/**  Description: Implementation of the RCC contain interfaces for the module   */
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
/** Rana     Rana Hossny                 ain shams university.               */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 9/08/2023   0.1       Rana Hossny   Initial Creation                        */
/********************************************************************************/

#ifndef   RCC_H
#define   RCC_H
void Init_Rcc(void);

/* select one option of the RCC_BUS From those :
 RCC_AHB1	
 RCC_AHB2	
 RCC_APB1	
 RCC_APB2	
*/



/* select the peripheral to enble clock   RCC_PERIPHERAL :
 RCC_AHB1ENR_GPIOA	
 RCC_AHB1ENR_GPIOB	
 RCC_AHB1ENR_GPIOC	
 RCC_AHB1ENR_GPIOD	
 RCC_AHB1ENR_GPIOE	
 RCC_AHB1ENR_GPIOH	
 RCC_AHB1ENR_CRC		
 RCC_AHB1ENR_DMA1	
 RCC_AHB1ENR_DMA2	
 RCC_AHB1ENR_OTGFSEN	 


 peripheral for RCC_APB1
 RCC_APB1ENR_PWR  
 RCC_APB1ENR_I2C3 
 RCC_APB1ENR_I2C2  
 RCC_APB1ENR_I2C1 
 RCC_APB1ENR_USART2 
 RCC_APB1ENR_SPI3 
 RCC_APB1ENR_SPI2 
 RCC_APB1ENR_WWDG 
 RCC_APB1ENR_TIM5 
 RCC_APB1ENR_TIM4  
 RCC_APB1ENR_TIM3 
 RCC_APB1ENR_TIM2 



peripheral for RCC_APB2

 RCC_APB2ENR_TIM11 
 RCC_APB2ENR_TIM10 
 RCC_APB2ENR_TIM9 
 RCC_APB2ENR_SYSCFG 
 RCC_APB2ENR_SPI4 
 RCC_APB2ENR_SPI1 
 RCC_APB2ENR_SDIO 
 RCC_APB2ENR_ADC1 
 RCC_APB2ENR_USART6 
 RCC_APB2ENR_USART1 
 RCC_APB2ENR_TIM1 
*/
void Enable_peripheral(uint8 RCC_PERIPHERAL, uint8 RCC_BUS );
void disable_peripheral(uint8 RCC_PERIPHERAL, uint8 RCC_BUS);
void reset_peripheral(uint8 RCC_PERIPHERAL, uint8 RCC_BUS);




#endif

