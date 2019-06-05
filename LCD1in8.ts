/*****************************************************************************
* | File       :   1in8LCD.ts
* | Author      :   Waveshare team
* | Function    :   Contorl 1.8inch lcd Show
* | Info        :
*----------------
* | This version:   V1.0
* | Date        :   2018-05-02
* | Info        :   Basic version
*
******************************************************************************/

let GUI_BACKGROUND_COLOR = LCD_COLOR.WHITE
let FONT_BACKGROUND_COLOR = LCD_COLOR.WHITE
let FONT_FOREGROUND_COLOR = LCD_COLOR.BLACK

//% weight=20 color=#436EEE icon="\uf108"
namespace LCD1IN8 {

    //% blockId=LCD_inititialize
    //% blockGap=8
    //% block="LCD1IN8 initialize"
    //% shim=LCD1IN8::LCD_initialize
    //% weight=200
    export function LCD_initialize(): void {
        return;
    }

    //% blockId=LCD_display
    //% blockGap=8
    //% block="send display data"
    //% shim=LCD1IN8::LCD_display
    //% weight=190
    export function LCD_display(): void {
        return;
    }

    //% blockId=LCD_clear
    //% blockGap=8
    //% block="clear screen and cache"
    //% shim=LCD1IN8::LCD_clear
    //% weight=195
    export function LCD_clear(): void {
        return;
    }

    //% blockId=LCD_filling
    //% blockGap=8
    //% block="filling color %color"
    //% shim=LCD1IN8::LCD_filling
    //% weight=194
    export function LCD_filling(color: number): void {
        return;
    }

    //% blockId=LCD_putDisplayBuffer
    //% blockGap=8
    //% block="Send display buffer data"
    //% shim=LCD1IN8::LCD_putDisplayBuffer
    //% weight=190
    export function LCD_putDisplayBuffer(): void {
        return;
    }

    //% blockId=LCD_displayWindow
    //% blockGap=8
    //% block="show window display data |left %left|top %top|right %right|bottom %bottom "
    //% shim=LCD1IN8::LCD_displayWindow
    //% left.min=1 left.max=160 top.min=1 top.max=128
    //% right.min=1 right.max=160 bottom.min=1 bottom.max=128
    //% weight=189
    export function LCD_displayWindow(left: number, top: number, right: number, bottom: number): void {
        return;
    }

    //% blockId=getColor
    //% blockGap=8
    //% block="%color"
    //% weight=185
    export function getColor(color: LCD_COLOR): number {
        return color;
    }

    //% blockId=LCD_backlightLevel
    //% blockGap=8
    //% block="set backlight level %level"
    //% level.min=0 level.max=10
    //% shim=LCD1IN8::LCD_backlightLevel
    //% weight=180
    export function LCD_backlightLevel(level: number): void {
        return;
    }

    //% blockId=drawPoint
    //% blockGap=8
    //% block="draw point|x %x|y %y|color %color|point-size %pix"
    //% x.min=1 x.max=160 y.min=1 y.max=128
    //% color.min=0 color.max=65535
    //% shim=LCD1IN8::drawPoint
    //% weight=150
    export function drawPoint(x: number, y: number, color: number, pix: DOT_PIXEL): void {
        return;
    }

     //% blockId=drawLine
     //% blockGap=8
     //% block="draw line|left %left|top %top|right %right|bottom %bottom|color %color|line-width %width|line-style %style"
     //% left.min=1 left.max=160 top.min=1 top.max=128
     //% right.min=1 right.max=160 bottom.min=1 bottom.max=128
     //% color.min=0 color.max=65535
     //% weight=140
    export function drawLine(
            left: number,
            top: number,
            right: number,
            bottom: number,
            color: number,
            width: DOT_PIXEL,
            style: LINE_STYLE): void {
        return;
    }

    //% shim=LCD1IN8::drawChar
    function drawChar(x: number, y: number, ch: string, color: number): void {
        return;
    }

    //% blockId=drawString
    //% blockGap=8
    //% block="draw string|x %x|y %y|char %ch|color %color"
    //% x.min=1 x.max=160 y.min=1 y.max=128
    //% color.min=0 color.max=65535
    //% weight=100
    export function drawString(x: number, y: number, s: string, color: number): void {
        let left = x;
        let top = y;
        let height = 8;
        let width = 8;
        for (let i = 0; i < s.length; i++) {
            if (x + width > 160) {  // newline
                x = left;
                y += height;
            }
            // If the Y direction is full, reposition to(x, y)
            if(y  + height > 128) {
                x = left;
                y = top;
            }
            drawChar(x, y, s.charCodeAt(i), color);

            // The next word of the abscissa increases the font of the broadband
            x += width;
        }
    }

    //% blockId=drawNumber
    //% blockGap=8
    //% block="draw number|x %x|y %y|number %num|color %color"
    //% x.min=1 x.max=160 y.min=1 y.max=128
    //% color.min=0 color.max=65535
    //% weight=100
    export function drawNumber(x: number, y: number, num: number, color: number): void {
        drawString(x, y, num + "", color);
    }

}  // namespace LCD1IN8
