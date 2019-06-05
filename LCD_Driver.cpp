/*****************************************************************************
* | File        :   LCD_Driver.c
* | Author      :   Waveshare team
* | Function    :   ILI9486 Drive function
* | Info        :
*   Image scanning
*      Please use progressive scanning to generate images or fonts
*----------------
* | This version:   V1.0
* | Date        :   2018-01-11
* | Info        :   Basic version
*
******************************************************************************/
#include "MicroBitPin.h"
#include "mbed.h"
#include "LCD_Driver.h"
#include "SPI_RAM.h"

// spi
SPI lcd_spi(MOSI, MISO, SCK);
#define LCD_SPI_writeByte(value) lcd_spi.write(value)

// LCD
DigitalOut LCD_RST(MICROBIT_PIN_P8);
DigitalOut LCD_DC(MICROBIT_PIN_P12);
DigitalOut LCD_CS(MICROBIT_PIN_P16);
PwmOut LCD_BL(MICROBIT_PIN_P1);

#define LCD_RST_0 LCD_RST = 0
#define LCD_RST_1 LCD_RST = 1
#define LCD_DC_0 LCD_DC = 0
#define LCD_DC_1 LCD_DC = 1
#define LCD_CS_0 LCD_CS = 0
#define LCD_CS_1 LCD_CS = 1

// delay
#define Driver_Delay_ms(xms) wait_ms(xms)

// SPI Ram
SPIRAM *spiram;

/*********************************************
function:
    Initialization system
*********************************************/
void LCD_Driver::LCD_SPI_initialize() {
    lcd_spi.format(8,0);
    lcd_spi.frequency(9000000);
}

/*******************************************************************************
function:
    Hardware reset
*******************************************************************************/
void LCD_Driver::LCD_reset() {
    LCD_RST_1;
    Driver_Delay_ms(100);
    LCD_RST_0;
    Driver_Delay_ms(100);
    LCD_RST_1;
    Driver_Delay_ms(100);
}

/*******************************************************************************
function:
    Write register address and data
*******************************************************************************/
void LCD_Driver::LCD_writeRegister(UBYTE reg) {
    LCD_DC_0;
    LCD_CS_0;
    LCD_SPI_writeByte(reg);
    LCD_CS_1;
}

void LCD_Driver::LCD_writeByte(UBYTE data) {
    LCD_DC_1;
    LCD_CS_0;
    LCD_SPI_writeByte(data);
    LCD_CS_1;
}

void LCD_Driver::LCD_writeStream(UWORD data, WORD length) {
    WORD i;
    LCD_DC_1;
    LCD_CS_0;
    for (i = 0; i < length; i++) {
        LCD_SPI_writeByte((UBYTE) (data >> 8));
        LCD_SPI_writeByte((UBYTE) (data & 0xFF));
    }
    LCD_CS_1;
}
/*******************************************************************************
function:
    Common register initialization
*******************************************************************************/
void LCD_Driver::LCD_initializeRegister() {
    // ST7735R Frame Rate
    LCD_writeRegister(0xB1);
    LCD_writeByte(0x01);
    LCD_writeByte(0x2C);
    LCD_writeByte(0x2D);

    LCD_writeRegister(0xB2);
    LCD_writeByte(0x01);
    LCD_writeByte(0x2C);
    LCD_writeByte(0x2D);

    LCD_writeRegister(0xB3);
    LCD_writeByte(0x01);
    LCD_writeByte(0x2C);
    LCD_writeByte(0x2D);
    LCD_writeByte(0x01);
    LCD_writeByte(0x2C);
    LCD_writeByte(0x2D);

    LCD_writeRegister(0xB4);  // Column inversion
    LCD_writeByte(0x07);

    // ST7735R Power Sequence
    LCD_writeRegister(0xC0);
    LCD_writeByte(0xA2);
    LCD_writeByte(0x02);
    LCD_writeByte(0x84);
    LCD_writeRegister(0xC1);
    LCD_writeByte(0xC5);

    LCD_writeRegister(0xC2);
    LCD_writeByte(0x0A);
    LCD_writeByte(0x00);

    LCD_writeRegister(0xC3);
    LCD_writeByte(0x8A);
    LCD_writeByte(0x2A);
    LCD_writeRegister(0xC4);
    LCD_writeByte(0x8A);
    LCD_writeByte(0xEE);

    LCD_writeRegister(0xC5);  // VCOM
    LCD_writeByte(0x0E);

    // ST7735R Gamma Sequence
    LCD_writeRegister(0xe0);
    LCD_writeByte(0x0f);
    LCD_writeByte(0x1a);
    LCD_writeByte(0x0f);
    LCD_writeByte(0x18);
    LCD_writeByte(0x2f);
    LCD_writeByte(0x28);
    LCD_writeByte(0x20);
    LCD_writeByte(0x22);
    LCD_writeByte(0x1f);
    LCD_writeByte(0x1b);
    LCD_writeByte(0x23);
    LCD_writeByte(0x37);
    LCD_writeByte(0x00);
    LCD_writeByte(0x07);
    LCD_writeByte(0x02);
    LCD_writeByte(0x10);

    LCD_writeRegister(0xe1);
    LCD_writeByte(0x0f);
    LCD_writeByte(0x1b);
    LCD_writeByte(0x0f);
    LCD_writeByte(0x17);
    LCD_writeByte(0x33);
    LCD_writeByte(0x2c);
    LCD_writeByte(0x29);
    LCD_writeByte(0x2e);
    LCD_writeByte(0x30);
    LCD_writeByte(0x30);
    LCD_writeByte(0x39);
    LCD_writeByte(0x3f);
    LCD_writeByte(0x00);
    LCD_writeByte(0x07);
    LCD_writeByte(0x03);
    LCD_writeByte(0x10);

    LCD_writeRegister(0xF0);  // Enable test command
    LCD_writeByte(0x01);

    LCD_writeRegister(0xF6);  // Disable ram power save mode
    LCD_writeByte(0x00);

    LCD_writeRegister(0x3A);  // 65k mode
    LCD_writeByte(0x05);

    LCD_writeRegister(0x36);  // MX, MY, RGB mode
    LCD_writeByte(0xF7 & 0xA0);  // RGB color filter panel
}

/********************************************************************************
function:   Sets the start position and size of the display area
parameter:
    left    :   X direction Start coordinates
    top     :   Y direction Start coordinates
    right   :   X direction end coordinates
    bottom  :   Y direction end coordinates
********************************************************************************/
void LCD_Driver::LCD_setWindow(WORD left, WORD top, WORD right, WORD bottom) {
    // set the X coordinates
    LCD_writeRegister(0x2A);
    LCD_writeByte(0x00);
    LCD_writeByte((left & 0xFF) + 1);
    LCD_writeByte(0x00);
    LCD_writeByte(((right - 1) & 0xFF) + 1);

    // set the Y coordinates
    LCD_writeRegister(0x2B);
    LCD_writeByte(0x00);
    LCD_writeByte((top & 0xFF) + 2);
    LCD_writeByte(0x00);
    LCD_writeByte(((bottom - 1) & 0xFF)+ 2);

    LCD_writeRegister(0x2C);
}

/********************************************************************************
function:
    Set the display point (x, y)
********************************************************************************/
void LCD_Driver::LCD_setCursor(WORD x, WORD y) {
    if (0 <= x && x < LCD_WIDTH && 0 <= y && y < LCD_HEIGHT) {
        LCD_setWindow(x, y, x, y);
    }
}

/********************************************************************************
function:
    Set show color
********************************************************************************/
void LCD_Driver::LCD_setColor(UWORD color, WORD x, WORD y) {
    LCD_writeStream(color, x * y);
}

/********************************************************************************
function:
    initialization
********************************************************************************/
void LCD_Driver::LCD_initialize() {
    LCD_SPI_initialize();

    spiram->SPIRAM_SPI_initialize();
    spiram->SPIRAM_setMode(BYTE_MODE);

    // back light
    LCD_BL.period(0.02);
    LCD_BL.write(0.50f);

    // Hardware reset
    LCD_reset();

    // Set the initialization register
    LCD_initializeRegister();

    // sleep out
    LCD_writeRegister(0x11);
    Driver_Delay_ms(120);

    // Turn on the LCD display
    LCD_writeRegister(0x29);
}

void LCD_Driver::LCD_backlightLevel(WORD level) {
    LCD_BL.write((float) level / 10);
}

/********************************************************************************
function:
    Clear screen
********************************************************************************/
void LCD_Driver::LCD_clear(UWORD color) {
    LCD_setWindow(0, 0, LCD_WIDTH, LCD_HEIGHT);
    LCD_setColor(color, LCD_WIDTH + 2, LCD_HEIGHT + 2);
}

void LCD_Driver::LCD_clearBuffer() {
    UWORD addr;
    UWORD color = 0xFFFF;
    UBYTE hi = (UBYTE) (color >> 8);
    UBYTE lo = (UBYTE) (color & 0xFF);
    for (addr = 0; addr < LCD_WIDTH * LCD_HEIGHT * 2; ) {
        spiram->SPIRAM_writeByte(addr++, hi);
        spiram->SPIRAM_writeByte(addr++, lo);
    }
}

void LCD_Driver::LCD_setPoint(WORD x, WORD y, UWORD color) {
    if (0 <= x && x < LCD_WIDTH && 0 <= y && y < LCD_HEIGHT) {
        UWORD addr = (x + y * LCD_WIDTH) * 2;
        spiram->SPIRAM_writeByte(addr++, (UBYTE) (color >> 8));
        spiram->SPIRAM_writeByte(addr, (UBYTE) (color & 0xFF));
    }
}

void LCD_Driver::LCD_display() {
    WORD x, y;
    UBYTE pagebuf[LCD_WIDTH * 2 * 2];  // read tow lines
    memset(pagebuf, 0xFF, sizeof(pagebuf));

    spiram->SPIRAM_setMode(STREAM_MODE);
    LCD_setWindow(0, 0, LCD_WIDTH, LCD_HEIGHT);
    for (y = 0; y < LCD_HEIGHT / 2; y++) {  // line
        spiram->SPIRAM_readStream(y * LCD_WIDTH * 2 * 2, pagebuf, LCD_WIDTH * 2 * 2);

        LCD_DC_1;
        LCD_CS_0;
        for (x = 0; x < LCD_WIDTH * 2; x++) {
            LCD_SPI_writeByte((UBYTE) *pagebuf++);
            LCD_SPI_writeByte((UBYTE) *pagebuf++);
        }
        LCD_CS_1;
    }
}

void LCD_Driver::LCD_displayWindow(WORD left, WORD top, WORD right, WORD bottom) {
    WORD x, y;
    UBYTE pagebuf[(right - left + 1) * 2];
    memset(pagebuf, 0xFF, sizeof(pagebuf));

    spiram->SPIRAM_setMode(STREAM_MODE);
    LCD_setWindow(left, top, right, bottom);
    for (y = top; y < bottom; y++) {  // line
        spiram->SPIRAM_readStream((y * LCD_WIDTH + left) * 2, pagebuf, sizeof(pagebuf));

        LCD_DC_1;
        LCD_CS_0;
        for (x = left; x < right; x++) {
            LCD_SPI_writeByte((UBYTE) *pagebuf++);
            LCD_SPI_writeByte((UBYTE) *pagebuf++);
        }
        LCD_CS_1;
    }
}

void LCD_Driver::LCD_drawPoint(WORD x, WORD y, DOT_PIXEL px, UWORD color) {
    WORD dx ,dy;
    for (dx = 0; dx < px; dx++) {
        for (dy = 0; dy < px; dy++) {
            LCD_setPoint(x + dx - px, y + dy - px, color);
        }
    }
}

void LCD_Driver::LCD_drawLine(WORD left, WORD top, WORD right, WORD bottom, UWORD color, WORD width, WORD style) {
    WORD x, y, dx, dy, e, pcnt;

    if (left > right) {  // Swap left and right
        right = left - right;
        left -= right;
        right += left;
    }
    if (top > bottom) {  // Swap top and bottom
        bottom = top - bottom;
        top -= bottom;
        bottom += top;
    }

    x = left;
    y = top;
    dx = right - left;
    dy = bottom - top;

    // Cumulative error
    e = dx + dy;
    // Counter for dotted line
    pcnt = 0;

    for (;;) {
        // Draw dotted line, 2 point is really virtual
        if (style == LINE_STYLE.LINE_DOTTED) {
            if (pcnt++ == 0) LCD_drawPoint(x, y, width, color);
            if (3 <= pcnt) pcnt = 0;
        } else {
            LCD_drawPoint(x, y, width, color);
        }
        if (2 * e >= dy) {
            if (x >= right) break;
            e += dy;
            x++;
        }
        if (2 * e <= dx) {
            if (y >= bottom) break;
            e += dx;
            y++;
        }
    }
}

void LCD_Driver::LCD_drawChar(WORD x, WORD y, UBYTE ch, UWORD color) {
    WORD fontline = 0, fontcolumn = 0;
    UBYTE *p;
    UBYTE d;

    if (ch < 0x20 || 0x7F <= ch) return;
    ch -= 0x20;
    p = Font_Table + ch * LCD_CHAR_WIDTH_BYTES * LCD_CHAR_HEIGHT;

    for (fontline = 0; fontline < LCD_CHAR_HEIGHT; fontline++) {
        d = *p;
        for (fontcolumn = 0; fontcolumn < LCD_CHAR_WIDTH; fontcolumn++) {
            if (d & 0x80) LCD_setPoint(x + fontcolumn, y + fontline, color);
            if (fontcolumn % 8 == 7) {
                d = *++p;
            } else {
                d <<= 1;
            }
        }
    }
}
