/********************************************/
/* Description : ADC */
/* Author      : sara hossny        		*/
/* Date        : 9/9/2023                   */
/* Version     : 0.1V                       */
/********************************************/
#ifndef   ADC_PRIV_H
#define   ADC_PRIV_H
#include "STD_Types.h"

typedef struct
{
    uint32 ADC_SR;
    uint32 ADC_CR1;
    uint32 ADC_CR2;
    uint32 ADC_SMPR1;
    uint32 ADC_SMPR2;
	uint32 ADC_JOFR1;
    uint32 ADC_JOFR2;
    uint32 ADC_JOFR3;
	uint32 ADC_JOFR4;
    uint32 ADC_HTR;
    uint32 ADC_LTR;
	uint32 ADC_SQR1;
    uint32 ADC_SQR2;
    uint32 ADC_SQR3;
	uint32 ADC_JSQR;
    uint32 ADC_JDR1;
    uint32 ADC_JDR2;
	uint32 ADC_JDR3;
    uint32 ADC_JDR4;
    uint32 ADC_DR;
    uint32 ADC_CCR;


}ADC_t;




#define ADC1_Base_Address  0x40012000 

#define ADC1 ((volatile ADC_t *) ADC1_Base_Address)
/*resolution */
#define TWELVE_BIT   0
#define ELEVEN_BIT	 1
#define EGHIT_BIT	 2
#define SIX_BIT		 3

/*sampling time */

#define CYCLE3   	 0
#define CYCLE15	     1
#define CYCLE28	     2
#define CYCLE56		 3
#define CYCLE84      4
#define CYCLE112	 5
#define CYCLE144	 6
#define CYCLE480	 7



#endif
