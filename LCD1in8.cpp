/*****************************************************************************
* | File       :   LCD1in8.cpp
* | Author      :   Waveshare team
* | Function    :   Contorl lcd Show
* | Info        :
*----------------
* | This version:   V1.0
* | Date        :   2018-05-02
* | Info        :   Basic version
*
******************************************************************************/
#include "pxt.h"
#include "LCD_Driver.h"

using namespace pxt;

// % weight=20 color=#436EEE icon="\uf108"
namespace LCD1IN8 {
    LCD_Driver *LCD;

    // %
    void LCD_initialize() {
        LCD->LCD_initialize();
    }

    // %
    void LCD_clear() {
        LCD->LCD_clear(WHITE);
        LCD->LCD_clearBuffer();
    }

    // %
    void LCD_filling(int color) {
        LCD->LCD_clear(color);
    }

    // %
    void LCD_display() {
        LCD->LCD_display();
    }

    // %
    void LCD_displayWindow(int left, int top, int right, int bottom) {
        LCD->LCD_displayWindow(left, top, right, bottom);
    }

    // %
    void LCD_backlightLevel(int level) {
        LCD->LCD_backlightLevel(level);
    }

    // %
    void drawPoint(int x, int y, int color, DOT_PIXEL pix) {
        LCD->LCD_drawPoint(x, y, pix, color);
    }

    // %
    void drawLine(int left, int top, int right, int bottom, int color, DOT_PIXEL pix) {
        LCD->LCD_drawLine(left, top, right, bottom, color, 1, pix);
    }

    // %
    void drawChar(int x, int y, int ch, int color) {
        LCD->LCD_drawChar(x, y, ch, color);
    }
}
