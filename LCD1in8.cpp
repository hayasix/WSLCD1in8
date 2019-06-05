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
    void LCD_Init() {
        LCD->LCD_Init();
    }

    // %
    void LCD_Clear() {
        LCD->LCD_Clear(WHITE);
  LCD->LCD_ClearBuf();
    }

    // %
    void LCD_Filling(int Color) {
        LCD->LCD_Clear(Color);
    }

    // %
    void LCD_Display() {
        LCD->LCD_Display();
    }

    // %
    void LCD_DisplayWindows(int left, int top, int right, int bottom) {
        LCD->LCD_DisplayWindows(left, top, right, bottom);
    }

    // %
    void LCD_SetBL(int level) {
        LCD->LCD_SetBL(level);
    }

    // %
    void DrawPoint(int x, int y, int color, DOT_PIXEL pix) {
        LCD->LCD_DrawPoint(x, y, pix, color);
    }

    // %
    void DrawLine(int left, int top, int right, int bottom, int color, DOT_PIXEL pix) {
        LCD->LCD_DrawPoint(left, top, right, bottom, color, 1, pix);
    }

    // %
    void DisChar(int x, int y, int ch, int color) {
        LCD->LCD_DisChar(x, y, ch, color);
    }
}
