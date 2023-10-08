/****************************************************************************************/
/**    File Name: PUSHBUTTON.h                                                          */
/**                                                                                     */
/**  Description: Implementation of the PUSHBUTTON contain configuration for the module */
/* Author      : rana hossny         													*/
/* Date        : 14/8/2023                  											*/
/* Version     : 0.1V                       											*/
/****************************************************************************************/
 /* Gaurd */
#ifndef PUSHBUTTON_PRIV_H
#define PUSHBUTTON_PRIV_H

#define   PULLUP_CONNECTION        ((uint8) 1)
#define   PULLDOWN_CONNECTION       ((uint8) 0)

typedef struct{
	uint8 u8GPIOPort;
	uint8 u8GPIOPinMap;
	uint8 u8PUSHBUTTIONModeConc;
}tstrPinMappingCfg ;

extern tstrPinMappingCfg PUSHBUTTION_astrPUSHBUTTIONPinMapping[PUSHBUTTON_MAX_NUM];





#endif
