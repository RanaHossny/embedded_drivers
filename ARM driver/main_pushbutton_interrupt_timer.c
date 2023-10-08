#include "LED.h"
#include"PUSHBUTTON.h"
#include"STD_Types.h"


void pushbutton_callback(){
	  LED_enuWriteValue (GPIO_PORTA,5,LED_u8NORMAL,LED_u8ON);
	  LED_enuWriteValue (GPIO_PORTA,6,LED_u8NORMAL,LED_u8ON);
	  LED_enuWriteValue (GPIO_PORTA,7,LED_u8NORMAL,LED_u8ON);
		 MSTK_voidDelaysec(5);
	  LED_enuWriteValue (GPIO_PORTA,5,LED_u8NORMAL,LED_u8OFF);
	  LED_enuWriteValue (GPIO_PORTA,6,LED_u8NORMAL,LED_u8OFF);
	  LED_enuWriteValue (GPIO_PORTA,7,LED_u8NORMAL,LED_u8OFF);
}



int main(){
 Init_Rcc();
 Enable_peripheral(  RCC_AHB1ENR_GPIOA	,RCC_AHB1 );
 Enable_peripheral( RCC_APB2ENR_SYSCFG ,RCC_APB2);
 MSTK_voidInit();
 MSTK_voidIntState();
 MGPIO_vSetPinMode( GPIO_PORTA, 5 , GPIO_MODE_OUTPUT);
 MGPIO_vSetPinMode( GPIO_PORTA, 6 , GPIO_MODE_OUTPUT);
 MGPIO_vSetPinMode( GPIO_PORTA, 7 , GPIO_MODE_OUTPUT);
 MGPIO_vSetPinMode( GPIO_PORTA, 0 , GPIO_MODE_INPUT);
 MNVIC_vIntrruptSetEnable(6);
 MEXINTP_vSetSYSCfgEXINT(0,GPIO_PORTA);
 MEXINTP_VSet_Mode(EXINT_FAILING_TRIGGER_MODE,0);
 MNVICP_VSetGroup_Mode(MNVIC_G16_SG0);
 MNVICP_vSetInterruptPeriority(6,0,0);
   MEXINT0_vCallBack(&pushbutton_callback);
   MEXINT_vInterruptSetEnable(0);
   pushbutton_intial();
   while (1)
     {
     };

 }