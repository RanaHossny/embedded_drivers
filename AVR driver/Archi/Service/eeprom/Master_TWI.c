/********************************************************************************/
/**    File Name: Mater_TWI.c                                                         */
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
#include "STD_Types.h"
#include "BIT_Math.h"


#include "Master_TWI.h"
#include "Master_priv.h"


void TWI_init_master(void) // Function to initialize master
{

    TWBR=0xCF;    // Bit rate
   // TWSR=0x00;    // Setting prescalar bits
    // SCL freq= F_CPU/(16+2(TWBR).4^TWPS)
}

void TWI_start(void)
{
    // Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
    TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while(!(TWCR & (1<<TWINT))); // Wait till start condition is transmitted
    while((TWSR & 0xF8)!= 0x08); // Check for the acknowledgement
}
void TWI_read_address(unsigned char data)
{
    TWDR=data;    // Address and read instruction
    TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
    while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte received
  //  while((TWSR & 0xF8)!= 0x40);  // Check for the acknoledgement
}
void TWI_write_data(unsigned char data)
{
    TWDR=data;    // put data in TWDR
    TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
    while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
    //while((TWSR & 0xF8) != 0x28); // Check for the acknoledgement
}
void TWI_stop(void)
{
    // Clear TWI interrupt flag, Put stop condition on SDA, Enable TWI
    TWCR= (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
  //  while(!(TWCR & (1<<TWSTO)));  // Wait till stop condition is transmitted
}
uint8 TWI_read_data(void)
{
    TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
    while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
    //while((TWSR & 0xF8) != 0x58); // Check for the acknoledgement
  return TWDR;

}
void TWI_write_address(unsigned char data)
{
TWDR=data; // Address and write instruction
TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
//while((TWSR & 0xF8)!= 0x18);  // Check for the acknoledgement
}
