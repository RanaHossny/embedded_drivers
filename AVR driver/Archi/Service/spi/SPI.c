#include "STD_Types.h"
#include "BIT_MATH.h"
#include "spi.h"
#include "spi_cfg.h"
#include "spi_priv.h"

uint8 u8_bus_contention ;
uint8 u8_collision_Flag ;
uint8 u8_read_buffer;
void spi_void_intial(void){

	SET_BIT( SPCR , 6) ;
#if SPI_STATE == MASTER
	SPCR|=DATA_ORDER;
	SPCR|=SPI_STATE;
	SPCR|=SPI_CLK_POLARITY;
	SPCR|= SCK_FREQUENCY;
#if SCK_FREQUENCY==FREQ_DIV_2
	SET_BIT( SPSR , 0) ;
    #elif SCK_FREQUENCY==FREQ_DIV_8
	SET_BIT( SPSR , 0) ;
    #elif SCK_FREQUENCY==FREQ_DIV_32
	SET_BIT( SPSR , 0) ;
   #endif
#endif


}
void spi_void_read_Syc(uint8 * u8_value_cpy){
	while(GET_BIT( SPSR , 7)==0);
	*u8_value_cpy=SPDR;
}
uint8 spi_uint8_read_Asyc(void){
	return u8_read_buffer;
}

void spi_void_write_Syc(uint8 u8_value_cpy){
	SPDR=u8_value_cpy;
}

void spi_void_enable(void){
	SET_BIT( SPCR , 6) ;	
}
void spi_void_disable(void ){
	CLR_BIT( SPCR , 6) ;
}
void spi_void_InterputEnable(void){		
	SET_BIT( SPCR , 7) ;
}
void spi_void_InterputDisable(void ){
	CLR_BIT( SPCR , 7) ;
}
tenuErrorSpiStatus spi_tenuspi_state(void){
	tenuErrorSpiStatus state=E_OK_WRITE_DONE;
	if(u8_bus_contention==1){
		state=E_NOK_BUS_CONTENTION;
		u8_bus_contention=0;
	}
	else if(u8_collision_Flag ==1) {
		state=E_NOK_COLLISION;
		u8_collision_Flag=0;
	}
	else {

	}
}

void __vector_12 (void ) __attribute__((signal,used));
void __vector_12 (void ){

	if((GET_BIT(SPCR , 4)==0)&&(SPI_STATE==MASTER)){
		u8_bus_contention=1;
	}
	else if((GET_BIT(SPSR , 6)==1)){
		u8_collision_Flag =1;
	}
	else{
		u8_read_buffer=SPDR;
	}
	CLR_BIT( SPCR , 7) ;
}
