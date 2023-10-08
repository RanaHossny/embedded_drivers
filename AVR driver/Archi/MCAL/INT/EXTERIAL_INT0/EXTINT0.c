
#include "STD_Types.h"
#include "BIT_Math.h"

#include "EXTINT0.h"
#include "EXTINT0_cfg.h"
#include "EXTINT0_priv.h"


pf EXTINT0_pfCallback ;

void EXTINT0_voidInit(void)
{

#if EXTINT0_SENSE_MODE == LOW_LEVEL
	CLR_BIT(MCUCR , 0) ;
	CLR_BIT(MCUCR , 1) ;
	
#elif EXTINT0_SENSE_MODE ==IOC 
	SET_BIT(MCUCR , 0) ;
	CLR_BIT(MCUCR , 1) ;
#elif EXTINT0_SENSE_MODE == FALLING_EDGE
	CLR_BIT(MCUCR , 0) ;
	SET_BIT(MCUCR , 1) ;
#else
	SET_BIT(MCUCR , 0) ;
	SET_BIT(MCUCR , 1) ;
#endif 

	CLR_BIT(GICR,6); // Disable External interrupt 0
	SET_BIT(GIFR,6); //Clear External interrupt 0 Flag 

}

void EXTINT0_voidEnable(void)
{
	SET_BIT(GICR,6);
}

void EXTINT0_voidDisable(void)
{
	CLR_BIT(GICR,6);
}

void EXTINT0_voidSetCallBack(pf pfCallbackCpy)
{
	EXTINT0_pfCallback = pfCallbackCpy ;
}

void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	EXTINT0_pfCallback();
}
void EXTINT0_voidSetSenseValue(uint8 u8SenseValueCpy){
	if(u8SenseValueCpy==FALLING_EDGE){
	CLR_BIT(MCUCR , 0) ;
	SET_BIT(MCUCR , 1) ;
		
	}
	if(u8SenseValueCpy==RISING_EDGE){
	SET_BIT(MCUCR , 0) ;
	SET_BIT(MCUCR , 1) ;
	}
	
}


