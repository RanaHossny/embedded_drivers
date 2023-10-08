/********************************************************************************/
/**    File Name: RCC.h                                                         */
/**                                                                             */
/**  Description: Implementation of the RCC  module                             */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  STM32F401CCG6                                           */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2023 by Rana Hossny .       All rights reserved.              */
/**                                                                             */
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
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"


#include  "RCC_cfg.h"
#include  "RCC.h"

void Init_Rcc(void){
 #if RCC_SYSCLK == RCC_HSI
    SET_BIT(RCC->RCC_CR , RCC_HSI);
    while (GET_BIT(RCC->RCC_CR , 1)!=1);
    CLR_BIT(RCC->RCC_CFGR,0);
    CLR_BIT(RCC->RCC_CFGR,1);
    while ((GET_BIT(RCC->RCC_CR , 2)!=0) || (GET_BIT(RCC->RCC_CR , 3)!=0) );
    
 #elif RCC_SYSCLK == RCC_HSE
    SET_BIT(RCC->RCC_CR , RCC_HSE);
    while (GET_BIT(RCC->RCC_CR , 17)!=1);
    			#if (RCC_HSE_MODE==RCC_BYPASS)
				SET_BIT(RCC->RCC_CR , 18);
			#elif (RCC_HSE_MODE==RCC_CYSTAL)
				CLR_BIT(RCC->RCC_CR , 18); 
			#else
				#error "wrong configaration "
			#endif

    SET_BIT(RCC->RCC_CFGR,0);
    CLR_BIT(RCC->RCC_CFGR,1);
    while ((GET_BIT(RCC->RCC_CR , 2)!=1) || (GET_BIT(RCC->RCC_CR , 3)!=0) );

 #elif RCC_SYSCLK == RCC_PLL
		#if RCC_PLL_SCR==RCC_PLL_SRC_HSI
			SET_BIT(RCC->RCC_CR , RCC_HSI);
			while(GET_BIT(RCC->RCC_CR, 1)!=1);
			CLR_BIT(RCC->RCC_PLLCFGR , 22); 
		#elif RCC_PLL_SCR==RCC_PLL_SRC_HSE
			#if (RCC_HSE_MODE==RCC_BYPASS)
				SET_BIT(RCC->RCC_CR , 18);
			#elif (RCC_HSE_MODE==RCC_CYSTAL)
				CLR_BIT(RCC->RCC_CR , 18); 
			#else
				#error "wrong configaration "
			#endif
			SET_BIT(RCC->RCC_CR , RCC_HSE);
			while(GET_BIT(RCC->RCC_CR, 17)!=1);
		#endif
			SET_BIT(RCC->RCC_PLLCFGR , 22); 
			
		EDIT_VALUE(RCC->RCC_PLLCFGR ,(~(RCC_PLLN<<6 |RCC_PLLP|RCC_PLLM)),0xF00037FFF );
		SET_BIT(RCC->RCC_CR , RCC_PLL);
		while(GET_BIT(RCC->RCC_CR, 17)!=1);
		SET_BIT(RCC->RCC_CFGR , 1);
		CLR_BIT(RCC->RCC_CFGR , 0);
		while(RCC->RCC_CFGR&&0x0c != 0x10);	
 #else
  #error " not allowed RCC_SYSCLK"
 #endif
}

void Enable_peripheral(uint8 RCC_PERIPHERAL, uint8 RCC_BUS) {
    switch (RCC_BUS) {  // Fixed to use RCC_BUS instead of RCC_PERIPHERAL
        case RCC_AHB1:
            SET_BIT(RCC->RCC_AHB1ENR, RCC_PERIPHERAL);
            break;
        case RCC_AHB2:
            SET_BIT(RCC->RCC_AHB2ENR, RCC_PERIPHERAL);
            break;
        case RCC_APB1:
            SET_BIT(RCC->RCC_APB1ENR, RCC_PERIPHERAL);
            break;
        case RCC_APB2:
            SET_BIT(RCC->RCC_APB2ENR, RCC_PERIPHERAL);
            break;
        default:
		printf("invaild bus");


            break;
    }
}

void disable_peripheral(uint8 RCC_PERIPHERAL, uint8 RCC_BUS){
       switch (RCC_BUS)
    {
    case RCC_AHB1:
       CLR_BIT(RCC->RCC_AHB1ENR,RCC_PERIPHERAL);
        break;
    case RCC_AHB2:
       CLR_BIT(RCC->RCC_AHB2ENR,RCC_PERIPHERAL);
        break;
    case RCC_APB1:
       CLR_BIT(RCC->RCC_APB1ENR,RCC_PERIPHERAL);
        break;
    case RCC_APB2:
       CLR_BIT(RCC->RCC_APB2ENR,RCC_PERIPHERAL);
        break;

    default:
       printf( "Invaild bus input");
        break;
    }
}

void reset_peripheral(uint8 RCC_PERIPHERAL, uint8 RCC_BUS){
        switch (RCC_BUS)
    {
    case RCC_AHB1:
       SET_BIT(RCC->RCC_AHB1RSTR,RCC_PERIPHERAL);
        break;
    case RCC_AHB2:
       SET_BIT(RCC->RCC_AHB2RSTR,RCC_PERIPHERAL);
        break;
    case RCC_APB1:
       SET_BIT(RCC->RCC_APB1RSTR,RCC_PERIPHERAL);
        break;
    case RCC_APB2:
       SET_BIT(RCC->RCC_APB2RSTR,RCC_PERIPHERAL);
        break;

    default:
      printf( "Invaild bus input");
        break;
    }


}
