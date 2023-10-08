/********************************************************************************/
/**    File Name: DC_Motor_PRIV.h                                                    */
/**                                                                             */
/** Description: Implementation of the DC_Motor contain configuration for the module*/
/********************************************************************************/

/**    File Name: DC_Motor.h                                                    */
/**                                                                             */
/**  Description: Implementation of the DC_Motor contain configuration for the module*/
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          : STM32F401CCG6                                            */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/* to Rana Hossny */
/**-----------------------------------------------------------------------------*/
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
/** 25/08/2023   0.1       Rana     Initial Creation                       */
/********************************************************************************/
#ifndef DC_Motor_PRIV_H
#define DC_Motor_PRIV_H
#include "../../LIB/STD_Types.h"
#include"DC_Motor_cfg.h"

#define MOTOR_u8NORMAL    ((uint8) 0xAA)
#define MOTOR_u8REVERSE   ((uint8) 0x55)

typedef struct{
	uint8 u8Port_Pin_0;
	uint8 u8DioPinMap0;
	uint8 u8Port_Pin_1;
	uint8 u8DioPinMap1;
	uint8 u8MotorModeConc;
}tstrPinMappingMotorCfg ;

extern tstrPinMappingMotorCfg MOTOR_astrMotorPinMapping[DC_Motor_MAX_NUM];



#endif
