/*****************************************************************************
* | File        :   SPI_RAM.h
* | Author      :   Waveshare team
* | Function    :   FM25V05 DRIVER
* | Info        :
*----------------
* | This version:   V1.0
* | Date        :   2017-12-12
* | Info        :   Basic version
*
******************************************************************************/
#ifndef __SPI_RAM_H_
#define __SPI_RAM_H_

// data
#define BYTE   unsigned char
#define WORD   unsigned short

// SRAM opcodes
#define CMD_WREN  0x06
#define CMD_WRDI  0x04
#define CMD_RDSR  0x05
#define CMD_WRSR  0x01
#define CMD_READ  0x03
#define CMD_WRITE 0x02

// SRAM modes
#define BYTE_MODE   0x00
#define PAGE_MODE   0x80
#define STREAM_MODE 0x40


class SPIRAM {
  public:
    void SPIRAM_SPI_Init(void);

    void SPIRAM_Set_Mode(UBYTE mode);

    UBYTE SPIRAM_RD_Byte(UWORD addr);
    void SPIRAM_WR_Byte(UWORD addr, const UBYTE data);
    void SPIRAM_RD_Page(UWORD addr, UBYTE *pagebuf);
    void SPIRAM_WR_Page(UWORD addr, UBYTE *pagebuf);
    void SPIRAM_RD_Stream(UWORD addr, UBYTE *pagebuf, UWORD length);
    void SPIRAM_WR_Stream(UWORD addr, UBYTE *pagebuf, UWORD length);
};
#endif
