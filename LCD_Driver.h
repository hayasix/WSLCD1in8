/*****************************************************************************
* | File        :   LCD1in8_Driver.h
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
#ifndef __LCD_DRIVER_H
#define __LCD_DRIVER_H

// data
#define BYTE    char
#define UBYTE   unsigned char
#define WORD    int
#define UWORD   unsigned int

// Define the full screen height length of the display
#define LCD_WIDTH  160  // LCD width
#define LCD_HEIGHT 128  // LCD height
#define LCD_CHAR_WIDTH 8
#define LCD_CHAR_HEIGHT 8
#define LCD_CHAR_WIDTH_BYTES ((UWORD) (LCD_CHAR_WIDTH / 8))

enum LCD_COLOR {
    WHITE = 0xFFFF,
    BLACK = 0x0000,
    BLUE = 0x001F,
    BRED = 0XF81F,
    GRED = 0XFFE0,
    GBLUE = 0X07FF,
    RED = 0xF800,
    MAGENTA = 0xF81F,
    GREEN = 0x07E0,
    CYAN = 0x7FFF,
    YELLOW = 0xFFE0,
    BROWN = 0XBC40,
    BRRED = 0XFC07,
    GRAY = 0X8430
};

enum DOT_PIXEL {
    DOT_PIXEL_1 = 1,
    DOT_PIXEL_2,
    DOT_PIXEL_3,
    DOT_PIXEL_4
};

enum LINE_STYLE {
    LINE_SOLID = 0,
    LINE_DOTTED,
};

enum DRAW_FILL {
    DRAW_EMPTY = 0,
    DRAW_FULL,
};

class LCD_Driver {
  private:
    void LCD_SPI_initialize(void);
    void LCD_reset(void);
    void LCD_initializeRegister(void);

    void LCD_writeRegister(UBYTE reg);
    void LCD_writeByte(UBYTE data);
    void LCD_writeStream(UWORD data, WORD length);

    void LCD_setWindow(WORD left, WORD top, WORD right, WORD bottom);
    void LCD_setCursor(WORD X, WORD Y);
    void LCD_setColor(UWORD color, WORD x, WORD y);

    void LCD_setPoint(WORD x, WORD y, UWORD color);

  public:
    void LCD_initialize(void);

    void LCD_backlightLevel(WORD level);

    void LCD_clear(UWORD color);
    void LCD_clearBuffer(void);

    void LCD_display(void);
    void LCD_displayWindow(WORD left, WORD top, WORD right, WORD bottom);

    void LCD_drawPoint(WORD x, WORD y, DOT_PIXEL px, UWORD color);
    void LCD_drawLine(WORD left, WORD top, WORD right, WORD bottom, UWORD color, WORD width, WORD style);
    void LCD_drawChar(WORD x, WORD y, UBYTE ch, UWORD Color);
};

static const unsigned char Font_Table[] = {
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x10,  // ...X....
    0x38,  // ..XXX...
    0x38,  // ..XXX...
    0x38,  // ..XXX...
    0x10,  // ...X....
    0x00,  // ........
    0x10,  // ...X....
    0x00,  // ........
    0x6C,  // .XX.XX..
    0x6C,  // .XX.XX..
    0x28,  // ..X.X...
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x28,  // ..X.X...
    0x7C,  // .XXXXX..
    0x28,  // ..X.X...
    0x7C,  // .XXXXX..
    0x28,  // ..X.X...
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x10,  // ...X....
    0x7C,  // .XXXXX..
    0xD0,  // XX.X....
    0x7C,  // .XXXXX..
    0x16,  // ...X.XX.
    0x7C,  // .XXXXX..
    0x10,  // ...X....
    0x00,  // ........
    0xC0,  // XX......
    0xC0,  // XX......
    0x0C,  // ....XX..
    0x30,  // ..XX....
    0xC0,  // XX......
    0x0C,  // ....XX..
    0x0C,  // ....XX..
    0x00,  // ........
    0x78,  // .XXXX...
    0xCC,  // XX..XX..
    0xCC,  // XX..XX..
    0x30,  // ..XX....
    0xD6,  // XX.X.XX.
    0xCC,  // XX..XX..
    0x76,  // .XXX.XX.
    0x00,  // ........
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x10,  // ...X....
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x0C,  // ....XX..
    0x18,  // ...XX...
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x18,  // ...XX...
    0x0C,  // ....XX..
    0x00,  // ........
    0x60,  // .XX.....
    0x30,  // ..XX....
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x30,  // ..XX....
    0x60,  // .XX.....
    0x00,  // ........
    0x00,  // ........
    0x6C,  // .XX.XX..
    0x38,  // ..XXX...
    0xFE,  // XXXXXXX.
    0x38,  // ..XXX...
    0x6C,  // .XX.XX..
    0x00,  // ........
    0x00,  // ........
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x7E,  // .XXXXXX.
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x60,  // .XX.....
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x7E,  // .XXXXXX.
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x00,  // ........
    0x02,  // ......X.
    0x06,  // .....XX.
    0x0C,  // ....XX..
    0x18,  // ...XX...
    0x30,  // ..XX....
    0x60,  // .XX.....
    0x40,  // .X......
    0x00,  // ........
    0x38,  // ..XXX...
    0x4C,  // .X..XX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x64,  // .XX..X..
    0x38,  // ..XXX...
    0x00,  // ........
    0x18,  // ...XX...
    0x38,  // ..XXX...
    0x78,  // .XXXX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0xFE,  // XXXXXXX.
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xC6,  // XX...XX.
    0x06,  // .....XX.
    0x1C,  // ...XXX..
    0x70,  // .XXX....
    0xC0,  // XX......
    0xFE,  // XXXXXXX.
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xC6,  // XX...XX.
    0x06,  // .....XX.
    0x38,  // ..XXX...
    0x06,  // .....XX.
    0xC6,  // XX...XX.
    0x7C,  // .XXXXX..
    0x00,  // ........
    0x3C,  // ..XXXX..
    0x6C,  // .XX.XX..
    0xCC,  // XX..XX..
    0xCC,  // XX..XX..
    0xFE,  // XXXXXXX.
    0x0C,  // ....XX..
    0x0C,  // ....XX..
    0x00,  // ........
    0xFC,  // XXXXXX..
    0xC0,  // XX......
    0xC0,  // XX......
    0xFC,  // XXXXXX..
    0x06,  // .....XX.
    0x06,  // .....XX.
    0xFC,  // XXXXXX..
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xC0,  // XX......
    0xC0,  // XX......
    0xFC,  // XXXXXX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x7C,  // .XXXXX..
    0x00,  // ........
    0xFE,  // XXXXXXX.
    0xC6,  // XX...XX.
    0x0C,  // ....XX..
    0x18,  // ...XX...
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x7C,  // .XXXXX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x7C,  // .XXXXX..
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x7E,  // .XXXXXX.
    0x06,  // .....XX.
    0x06,  // .....XX.
    0x7C,  // .XXXXX..
    0x00,  // ........
    0x00,  // ........
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x00,  // ........
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x00,  // ........
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x60,  // .XX.....
    0x00,  // ........
    0x0C,  // ....XX..
    0x18,  // ...XX...
    0x30,  // ..XX....
    0x60,  // .XX.....
    0x30,  // ..XX....
    0x18,  // ...XX...
    0x0C,  // ....XX..
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x7C,  // .XXXXX..
    0x00,  // ........
    0x7C,  // .XXXXX..
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x60,  // .XX.....
    0x30,  // ..XX....
    0x18,  // ...XX...
    0x0C,  // ....XX..
    0x18,  // ...XX...
    0x30,  // ..XX....
    0x60,  // .XX.....
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xC6,  // XX...XX.
    0x06,  // .....XX.
    0x1C,  // ...XXX..
    0x30,  // ..XX....
    0x00,  // ........
    0x30,  // ..XX....
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xC6,  // XX...XX.
    0xD6,  // XX.X.XX.
    0xD6,  // XX.X.XX.
    0xDE,  // XX.XXXX.
    0xC0,  // XX......
    0x7C,  // .XXXXX..
    0x00,  // ........
    0x38,  // ..XXX...
    0x6C,  // .XX.XX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xFE,  // XXXXXXX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x00,  // ........
    0xFC,  // XXXXXX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xFC,  // XXXXXX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xFC,  // XXXXXX..
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xC6,  // XX...XX.
    0xC0,  // XX......
    0xC0,  // XX......
    0xC0,  // XX......
    0xC6,  // XX...XX.
    0x7C,  // .XXXXX..
    0x00,  // ........
    0xF8,  // XXXXX...
    0xCC,  // XX..XX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xCC,  // XX..XX..
    0xF8,  // XXXXX...
    0x00,  // ........
    0xFE,  // XXXXXXX.
    0xC0,  // XX......
    0xC0,  // XX......
    0xFC,  // XXXXXX..
    0xC0,  // XX......
    0xC0,  // XX......
    0xFE,  // XXXXXXX.
    0x00,  // ........
    0xFE,  // XXXXXXX.
    0xC0,  // XX......
    0xC0,  // XX......
    0xFC,  // XXXXXX..
    0xC0,  // XX......
    0xC0,  // XX......
    0xC0,  // XX......
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xC6,  // XX...XX.
    0xC0,  // XX......
    0xDE,  // XX.XXXX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x7C,  // .XXXXX..
    0x00,  // ........
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xFE,  // XXXXXXX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x00,  // ........
    0x38,  // ..XXX...
    0x38,  // ..XXX...
    0x38,  // ..XXX...
    0x38,  // ..XXX...
    0x38,  // ..XXX...
    0x38,  // ..XXX...
    0x38,  // ..XXX...
    0x00,  // ........
    0x1E,  // ...XXXX.
    0x0C,  // ....XX..
    0x0C,  // ....XX..
    0x0C,  // ....XX..
    0x0C,  // ....XX..
    0xCC,  // XX..XX..
    0x78,  // .XXXX...
    0x00,  // ........
    0xC6,  // XX...XX.
    0xCC,  // XX..XX..
    0xD8,  // XX.XX...
    0xF0,  // XXXX....
    0xD8,  // XX.XX...
    0xCC,  // XX..XX..
    0xC6,  // XX...XX.
    0x00,  // ........
    0xC0,  // XX......
    0xC0,  // XX......
    0xC0,  // XX......
    0xC0,  // XX......
    0xC0,  // XX......
    0xC0,  // XX......
    0xFE,  // XXXXXXX.
    0x00,  // ........
    0xC6,  // XX...XX.
    0xEE,  // XXX.XXX.
    0xFE,  // XXXXXXX.
    0xFE,  // XXXXXXX.
    0xD6,  // XX.X.XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x00,  // ........
    0xC6,  // XX...XX.
    0xE6,  // XXX..XX.
    0xF6,  // XXXX.XX.
    0xFE,  // XXXXXXX.
    0xDE,  // XX.XXXX.
    0xCE,  // XX..XXX.
    0xC6,  // XX...XX.
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x7C,  // .XXXXX..
    0x00,  // ........
    0xFC,  // XXXXXX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xFC,  // XXXXXX..
    0xC0,  // XX......
    0xC0,  // XX......
    0xC0,  // XX......
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xDE,  // XX.XXXX.
    0xCC,  // XX..XX..
    0x76,  // .XXX.XX.
    0x00,  // ........
    0xFC,  // XXXXXX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xFC,  // XXXXXX..
    0xD8,  // XX.XX...
    0xCC,  // XX..XX..
    0xC6,  // XX...XX.
    0x00,  // ........
    0x7E,  // .XXXXXX.
    0xC0,  // XX......
    0xC0,  // XX......
    0x7C,  // .XXXXX..
    0x06,  // .....XX.
    0x06,  // .....XX.
    0xFC,  // XXXXXX..
    0x00,  // ........
    0xFE,  // XXXXXXX.
    0x38,  // ..XXX...
    0x38,  // ..XXX...
    0x38,  // ..XXX...
    0x38,  // ..XXX...
    0x38,  // ..XXX...
    0x38,  // ..XXX...
    0x00,  // ........
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x7C,  // .XXXXX..
    0x00,  // ........
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x6C,  // .XX.XX..
    0x6C,  // .XX.XX..
    0x38,  // ..XXX...
    0x00,  // ........
    0xC6,  // XX...XX.
    0xD6,  // XX.X.XX.
    0xD6,  // XX.X.XX.
    0xD6,  // XX.X.XX.
    0xD6,  // XX.X.XX.
    0xD6,  // XX.X.XX.
    0x6C,  // .XX.XX..
    0x00,  // ........
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x6C,  // .XX.XX..
    0x10,  // ...X....
    0x6C,  // .XX.XX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x00,  // ........
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x6C,  // .XX.XX..
    0x10,  // ...X....
    0x10,  // ...X....
    0x10,  // ...X....
    0x10,  // ...X....
    0x00,  // ........
    0xFE,  // XXXXXXX.
    0x0C,  // ....XX..
    0x18,  // ...XX...
    0x30,  // ..XX....
    0x60,  // .XX.....
    0xC0,  // XX......
    0xFE,  // XXXXXXX.
    0x00,  // ........
    0x3C,  // ..XXXX..
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x3C,  // ..XXXX..
    0x00,  // ........
    0x40,  // .X......
    0x60,  // .XX.....
    0x30,  // ..XX....
    0x18,  // ...XX...
    0x0C,  // ....XX..
    0x06,  // .....XX.
    0x02,  // ......X.
    0x00,  // ........
    0x78,  // .XXXX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x78,  // .XXXX...
    0x00,  // ........
    0x38,  // ..XXX...
    0x6C,  // .XX.XX..
    0x6C,  // .XX.XX..
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0xFE,  // XXXXXXX.
    0x00,  // ........
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x0C,  // ....XX..
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x7C,  // .XXXXX..
    0x06,  // .....XX.
    0x7E,  // .XXXXXX.
    0xC6,  // XX...XX.
    0x7E,  // .XXXXXX.
    0x00,  // ........
    0xC0,  // XX......
    0xC0,  // XX......
    0xFC,  // XXXXXX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xFC,  // XXXXXX..
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x7E,  // .XXXXXX.
    0xC0,  // XX......
    0xC0,  // XX......
    0xC0,  // XX......
    0x7E,  // .XXXXXX.
    0x00,  // ........
    0x06,  // .....XX.
    0x06,  // .....XX.
    0x7E,  // .XXXXXX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x7E,  // .XXXXXX.
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xC6,  // XX...XX.
    0xFC,  // XXXXXX..
    0xC0,  // XX......
    0x7C,  // .XXXXX..
    0x00,  // ........
    0x1C,  // ...XXX..
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x7C,  // .XXXXX..
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xC6,  // XX...XX.
    0x7E,  // .XXXXXX.
    0x06,  // .....XX.
    0x7C,  // .XXXXX..
    0x00,  // ........
    0xC0,  // XX......
    0xC0,  // XX......
    0xFC,  // XXXXXX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x00,  // ........
    0x00,  // ........
    0x18,  // ...XX...
    0x00,  // ........
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x3C,  // ..XXXX..
    0x00,  // ........
    0x00,  // ........
    0x18,  // ...XX...
    0x00,  // ........
    0x38,  // ..XXX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x70,  // .XXX....
    0x00,  // ........
    0xC0,  // XX......
    0xC0,  // XX......
    0xCE,  // XX..XXX.
    0xD8,  // XX.XX...
    0xF0,  // XXXX....
    0xD8,  // XX.XX...
    0xCE,  // XX..XXX.
    0x00,  // ........
    0x38,  // ..XXX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x3C,  // ..XXXX..
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0xFC,  // XXXXXX..
    0xD6,  // XX.X.XX.
    0xD6,  // XX.X.XX.
    0xD6,  // XX.X.XX.
    0xD6,  // XX.X.XX.
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0xFC,  // XXXXXX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x7C,  // .XXXXX..
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0xFC,  // XXXXXX..
    0xC6,  // XX...XX.
    0xFC,  // XXXXXX..
    0xC0,  // XX......
    0xC0,  // XX......
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x7E,  // .XXXXXX.
    0xC6,  // XX...XX.
    0x7E,  // .XXXXXX.
    0x06,  // .....XX.
    0x06,  // .....XX.
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0xDE,  // XX.XXXX.
    0xF0,  // XXXX....
    0xE0,  // XXX.....
    0xC0,  // XX......
    0xC0,  // XX......
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x7C,  // .XXXXX..
    0xE0,  // XXX.....
    0x7C,  // .XXXXX..
    0x0E,  // ....XXX.
    0xFC,  // XXXXXX..
    0x00,  // ........
    0x00,  // ........
    0x30,  // ..XX....
    0x7C,  // .XXXXX..
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x1C,  // ...XXX..
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x7E,  // .XXXXXX.
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x6C,  // .XX.XX..
    0x38,  // ..XXX...
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0xC6,  // XX...XX.
    0xD6,  // XX.X.XX.
    0xD6,  // XX.X.XX.
    0xD6,  // XX.X.XX.
    0x6C,  // .XX.XX..
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0xC6,  // XX...XX.
    0x6C,  // .XX.XX..
    0x38,  // ..XXX...
    0x6C,  // .XX.XX..
    0xC6,  // XX...XX.
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0xC6,  // XX...XX.
    0xC6,  // XX...XX.
    0x7E,  // .XXXXXX.
    0x06,  // .....XX.
    0x78,  // .XXXX...
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0xFE,  // XXXXXXX.
    0x0C,  // ....XX..
    0x30,  // ..XX....
    0x60,  // .XX.....
    0xFE,  // XXXXXXX.
    0x00,  // ........
    0x0C,  // ....XX..
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x60,  // .XX.....
    0x18,  // ...XX...
    0x18,  // ...XX...
    0x0C,  // ....XX..
    0x00,  // ........
    0x10,  // ...X....
    0x10,  // ...X....
    0x10,  // ...X....
    0x10,  // ...X....
    0x10,  // ...X....
    0x10,  // ...X....
    0x10,  // ...X....
    0x00,  // ........
    0x60,  // .XX.....
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x0C,  // ....XX..
    0x30,  // ..XX....
    0x30,  // ..XX....
    0x60,  // .XX.....
    0x00,  // ........
    0x62,  // .XX...X.
    0x92,  // X..X..X.
    0x8C,  // X...XX..
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........
    0x00,  // ........

};

#endif
