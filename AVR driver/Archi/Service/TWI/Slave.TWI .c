/********************************************************************************/
/**    File Name: Slave_TWI.c                                                         */
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

#include "Slave_TWI.h"
#include "Slave_priv.h"


void TWI_init_slave(void) // Function to initilaize slave
{
    TWAR=0x20;    // Fill slave address to TWAR
}
void TWI_match_read_slave(void) //Function to match the slave address and slave dirction bit(read)
{
    while((TWSR & 0xF8)!= 0x60)  // Loop till correct acknoledgement have been received
    {
        // Get acknowlegement, Enable TWI, Clear TWI interrupt flag
        TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
        while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
    }
}
uint8 TWI_read_slave(void)
{
    // Clear TWI interrupt flag,Get acknowlegement, Enable TWI
    TWCR= (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));    // Wait for TWINT flag
    while((TWSR & 0xF8)!=0x80);        // Wait for acknowledgement
    return TWDR;                    // Get value from TWDR
                  // send the receive value on PORTB
}
void TWI_match_write_slave(void) //Function to match the slave address and slave dirction bit(write)
{
    while((TWSR & 0xF8)!= 0xA8)    // Loop till correct acknoledgement have been received
    {
        // Get acknowlegement, Enable TWI, Clear TWI interrupt flag
        TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
        while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
    }
}

void TWI_write_slave(uint8 write_data) // Function to write data
{
    TWDR= write_data;              // Fill TWDR register whith the data to be sent
    TWCR= (1<<TWEN)|(1<<TWINT);   // Enable TWI, Clear TWI interrupt flag
    while((TWSR & 0xF8) != 0xC0); // Wait for the acknowledgement
}
