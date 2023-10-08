#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define LSB_FIRST        0x20
#define MSB_FIRST        0x00
#define MASTER           0x10
#define SLAVE            0x00
#define LEADING_RISING   0x00
#define LEADING_FAILING  0x08
#define LEADING_SAMPLE   0x00
#define LEADING_SETUP    0x04
#define FREQ_DIV_2       0x00
#define FREQ_DIV_4       0x00
#define FREQ_DIV_8       0x01
#define FREQ_DIV_16      0x01
#define FREQ_DIV_32      0x02
#define FREQ_DIV_64      0x02
#define FREQ_DIV_128     0x03
#define SPCR           *((volatile uint8 *) 0x2D )
#define SPSR           *((volatile uint8 *) 0x2E )
#define SPDR           *((volatile uint8 *) 0x2F )
#endif
