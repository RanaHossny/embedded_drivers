#ifndef SPI_H_
#define SPI_H_
void spi_void_intial(void);
void spi_void_read_Syc(uint8 * u8_value_cpy);
uint8 spi_uint8_read_Asyc(void);
void spi_void_write_Syc(uint8 u8_value_cpy);
void spi_void_enable(void);
void spi_void_disable(void );
void spi_void_InterputEnable(void);
void spi_void_InterputDisable(void );
tenuErrorSpiStatus spi_tenuspi_state(void);
#endif
