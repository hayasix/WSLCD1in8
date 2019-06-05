/*****************************************************************************
* | File        :   SPI_RAM.cpp
* | Author      :   Waveshare team
* | Function    :   23LC1024 DRIVER
* | Info        :
*----------------
* | This version:   V1.0
* | Date        :   2017-12-12
* | Info        :   Basic version
*
******************************************************************************/
#include "SPI_RAM.h"
#include "mbed.h"
#include "MicroBitPin.h"

// SPI
SPI ram_spi(MOSI, MISO, SCK);
#define SPIRAM_SPI_writeByte(value) ram_spi.write(value)
#define SPIRAM_SPI_readByte(value) ram_spi.write(value)

// SPIRAM
DigitalOut SPIRAM_CS(MICROBIT_PIN_P2);
#define SPIRAM_CS_0 SPIRAM_CS = 0
#define SPIRAM_CS_1 SPIRAM_CS = 1


/*********************************************
function:
    Initialization system
*********************************************/
void SPIRAM::SPIRAM_SPI_initialize(void) {
    ram_spi.format(8, 0);
    ram_spi.frequency(9000000);
}


/*******************************************************************************
function:
        // Mode handling
*******************************************************************************/
void SPIRAM::SPIRAM_setMode(UBYTE mode) {
    SPIRAM_CS_0;

    SPIRAM_SPI_writeByte(CMD_WRSR);
    SPIRAM_SPI_writeByte(mode);

    SPIRAM_CS_1;
}

/*******************************************************************************
function:
        // Write and read byte
*******************************************************************************/
UBYTE SPIRAM::SPIRAM_readByte(UWORD addr) {
    UBYTE data;

    SPIRAM_CS_0;
    SPIRAM_SPI_writeByte(CMD_READ);

    SPIRAM_SPI_writeByte(0x00);
    SPIRAM_SPI_writeByte((UBYTE) (addr >> 8));
    SPIRAM_SPI_writeByte((UBYTE) (addr & 0xff));

    data = SPIRAM_SPI_readByte(0x00);
    SPIRAM_CS_1;

    return data;
}

void SPIRAM::SPIRAM_writeByte(UWORD addr, const UBYTE data) {
    // Write Addr,data
    SPIRAM_CS_0;

    SPIRAM_SPI_writeByte(CMD_WRITE);

    SPIRAM_SPI_writeByte(0x00);
    SPIRAM_SPI_writeByte((UBYTE) (addr >> 8));
    SPIRAM_SPI_writeByte((UBYTE) (addr & 0xff));

    SPIRAM_SPI_writeByte(data);
    SPIRAM_CS_1;
}


/*******************************************************************************
function:
        // Page transfer functions. Bound to current page. Passing the boundary
        //  will wrap to the beginning
*******************************************************************************/
void SPIRAM::SPIRAM_readPage(UWORD addr, UBYTE *pagebuf) {
    WORD i;

    // Write Addr, read data
    SPIRAM_CS_0;
    SPIRAM_SPI_writeByte(CMD_READ);

    SPIRAM_SPI_writeByte(0x00);
    SPIRAM_SPI_writeByte((UBYTE) (addr >> 8));
    SPIRAM_SPI_writeByte((UBYTE) (addr & 0xff));

    for (i = 0; i < 32; i++) {
        *pagebuf = SPIRAM_SPI_readByte(0x00);
        pagebuf++;
    }
    SPIRAM_CS_1;
}

void SPIRAM::SPIRAM_writePage(UWORD addr, UBYTE *pagebuf) {
    WORD i;

    // Write Addr, read data
    SPIRAM_CS_0;
    SPIRAM_SPI_writeByte(CMD_WRITE);

    SPIRAM_SPI_writeByte(0x00);
    SPIRAM_SPI_writeByte((UBYTE) (addr >> 8));
    SPIRAM_SPI_writeByte((UBYTE) (addr & 0xff));

    for (i = 0; i < 32; i++) {
        SPIRAM_SPI_writeByte(*pagebuf);
        pagebuf++;
    }
    SPIRAM_CS_1;
}

/*******************************************************************************
function:
        // Write and read Len
*******************************************************************************/
void SPIRAM::SPIRAM_readStream(UWORD addr, UBYTE *pagebuf, UWORD length) {
    WORD i;

    // Write Addr, read data
    SPIRAM_CS_0;
    SPIRAM_SPI_writeByte(CMD_READ);

    SPIRAM_SPI_writeByte(0x00);
    SPIRAM_SPI_writeByte((UBYTE) (addr >> 8));
    SPIRAM_SPI_writeByte((UBYTE) (addr & 0xff));

    for (i = 0; i < length; i++) {
        *pagebuf = SPIRAM_SPI_readByte(0x00);
        pagebuf++;
    }
    SPIRAM_CS_1;
}

void SPIRAM::SPIRAM_writeStream(UWORD addr, UBYTE *pagebuf, UWORD length) {
    WORD i;

    // Write Addr, read data
    SPIRAM_CS_0;
    SPIRAM_SPI_writeByte(CMD_WRITE);

    SPIRAM_SPI_writeByte(0x00);
    SPIRAM_SPI_writeByte((UBYTE) (addr >> 8));
    SPIRAM_SPI_writeByte((UBYTE) (addr & 0xff));

    for (i = 0; i < length; i++) {
        SPIRAM_SPI_writeByte(*pagebuf);
        pagebuf++;
    }
    SPIRAM_CS_1;
}
