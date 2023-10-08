/********************************************************************************/
/**    File Name: EEPROM.C                                                        */
/**                                                                             */
/**  Description: Implementation of the EEPROM contain configuration for the module*/
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
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "EEPROM.h"
#include"Master_TWi.h"

void EEPROM_Write(uint8 u8_address_device_cpy,uint8 u8_address_data_cpy ,uint8 data_cpy){
	    TWI_start(); 
		TWI_write_address(u8_address_device_cpy);
		TWI_write_address(u8_address_data_cpy);
		TWI_write_data(data_cpy); // Function to write data in slave
		TWI_stop(); 
}

uint8 EEPROM_Read(uint8 u8_address_device_cpy,uint8 u8_address_data_cpy ){
uint8 x;
		TWI_start();
		TWI_write_address(u8_address_device_cpy);
		TWI_write_address(u8_address_data_cpy);
		TWI_repeated_start();
	    TWI_read_address(u8_address_device_cpy+1); // Function to write address and data direction bit(read) on SDA
        x=TWI_read_data();
        TWI_stop();
	return x;
}
