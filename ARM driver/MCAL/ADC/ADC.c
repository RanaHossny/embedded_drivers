/********************************************************************************/
/**    File Name: adc.c                                                   */
/**                                                                             */
/**  Description: Implementation of the GPIO contain the module */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  STM32F401CCG6                                           */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2023 by Sara Hossny,Rana Hossny .       All rights reserved.              */
/**                                                                             */
/** This software is copyright protected and proprietary                        */
/** to ITI.                                                                     */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Company                              */
/** --------     ---------------------     -------------------------------------*/
/** Sara    Sara Hossny                 ain shams university.               */
/** Rana    Rana Hossny                 ain shams university.               */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 13/08/2023   0.1       Sara Hossny   Initial Creation                        */
/* 13/08/2023    0.2       Rana Hossny   Update creation                         */
/********************************************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "RCC.h"
#include "ADC_PRIV.h"
#include "ADC_CONFG.h"
#include "ADC.h"

void ADC_Init(void) {
    // Enable the ADC peripheral clock
	RCC_VoidEnablePeripheral(RCC_APB2ENR_ADC1 ,RCC_APB2 );
    // Configure the ADC for single conversion mode
    ADC1->ADC_CR1 = 0; // Reset CR1 register
    ADC1->ADC_CR2 = 0; // Reset CR2 register
	// Configure ADC for single conversion mode
    ADC1->ADC_CR2 &= ~(1U << 0); // Disable the ADC (ADON = 0)
    ADC1->ADC_CR2 &= ~(1U << 11); // Set CONT = 0 for single conversion
    ADC1->ADC_CR1 &= ~(0x3U << 24); // Clear RES bits 
	ADC1->ADC_CR1 |= (RES << 24); 
    #if channel_num<10
    ADC1->ADC_SMPR1 &=~ (0x7U << (channel_num*3)); 
	ADC1->ADC_SMPR1 |= (SAMPLE_CYC << (channel_num*3)); 
	#else
	ADC1->ADC_SMPR2 &=~ (0x7U <<  ((channel_num-9)*3));
	ADC1->ADC_SMPR2 |= (SAMPLE_CYC <<  ((channel_num-9)*3));
	#endif 
}

uint16 ADC_ReadChannel(uint32 channel) {
    // Configure the channel
    ADC1->ADC_SQR1= (channel & 0x1F); 

    // Start a conversion
    ADC1-> ADC_CR2 |= (1 << 30); // Set the SWSTART bit

    // Wait for the conversion to complete
    while (!(ADC1->ADC_SR & (1 << 1))); // Check EOC bit in ADC_SR

    // Read and return the ADC conversion result
    return ADC1->ADC_DR;
}



