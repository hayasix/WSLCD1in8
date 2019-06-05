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

    //% blockId=LCD_Init
    //% blockGap=8
    //% block="LCD1IN8 initialize"
    //% shim=LCD1IN8::LCD_Init
    //% weight=200
    export function LCD_Init(): void {
        return;
    }

    //% blockId=LCD_Clear
    //% blockGap=8
    //% block="Clear screen and cache"
    //% shim=LCD1IN8::LCD_Clear
    //% weight=195
    export function LCD_Clear(): void {
       return;
    }

    //% blockId=LCD_Filling
    //% blockGap=8
    //% block="Filling color %color"
    //% shim=LCD1IN8::LCD_Filling
    //% weight=194
    export function LCD_Filling(color: number): void {
       return;
    }

    //% blockId=LCD_Display
    //% blockGap=8
    //% block="Send display data"
    //% shim=LCD1IN8::LCD_Display
    //% weight=190
    export function LCD_Display(): void {
        return;
    }

    //% blockId=LCD_DisplayWindows
    //% blockGap=8
    //% block="Show Windows display data |left %left|top %top|right %right|bottom %bottom "
    //% shim=LCD1IN8::LCD_DisplayWindows
    //% left.min=1 left.max=160 top.min=1 top.max=128
    //% right.min=1 right.max=160 bottom.min=1 bottom.max=128
    //% weight=189
    export function LCD_DisplayWindows(
            left: number,
            top: number,
            right: number,
            bottom: number): void {
        return;
    }

    //% blockId=Get_Color
    //% blockGap=8
    //% block="%color"
    //% weight=185
    export function Get_Color(color: LCD_COLOR): number{
        return color;
    }

    //% blockId=LCD_SetBL
    //% blockGap=8
    //% block="Set back light level %level"
    //% level.min=0 level.max=10
    //% shim=LCD1IN8::LCD_SetBL
    //% weight=180
    export function LCD_SetBL(level: number): void {
        return;
    }

    //% blockId=DrawPoint
    //% blockGap=8
    //% block="Draw Point|x %x|y %y|color %color|point-size %pix"
    //% x.min=1 x.max=160 y.min=1 y.max=128
    //% color.min=0 color.max=65535
    //% shim=LCD1IN8::DrawPoint
    //% weight=150
    export function DrawPoint(x: number, y: number, color: number, pix: DOT_PIXEL): void {
        return;
    }

    //% blockId=DrawLine
    //% blockGap=8
    //% block="Draw Line|left %left|top %top|right %right|bottom %bottom|color %color|line-width %width|line-style %style"
    //% left.min=1 left.max=160 top.min=1 top.max=128
    //% right.min=1 right.max=160 bottom.min=1 bottom.max=128
    //% color.min=0 color.max=65535
    //% weight=140
    export function DrawLine(
            left: number,
            top: number,
            right: number,
            bottom: number,
            color: number,
            width: DOT_PIXEL,
            style: LINE_STYLE): void {
        return;
    }

    //% blockId=LCD_Clear
    //% blockGap=8
    //% block="Clear screen and cache"
    //% shim=LCD1IN8::LCD_Clear
    //% weight=195
    export function LCD_Clear(): void {
        return;
    }

    //% blockId=LCD_Filling
    //% blockGap=8
    //% block="Filling color %color"
    //% shim=LCD1IN8::LCD_Filling
    //% weight=194
    export function LCD_Filling(color: number): void {
        return;
    }

    //% blockId=LCD_Display
    //% blockGap=8
    //% block="Send display data"
    //% shim=LCD1IN8::LCD_Display
    //% weight=190
    export function LCD_Display(): void {
        return;
    }

    //% blockId=LCD_DisplayWindows
    //% blockGap=8
    //% block="Show Windows display data |left %left|top %top|right %right|bottom %bottom "
    //% shim=LCD1IN8::LCD_DisplayWindows
    //% left.min=1 left.max=160 top.min=1 top.max=128
    //% right.min=1 right.max=160 bottom.min=1 bottom.max=128
    //% weight=189
    export function LCD_DisplayWindows(left: number, top: number, right: number, bottom: number): void {
        return;
    }

    //% blockId=Get_Color
    //% blockGap=8
    //% block="%color"
    //% weight=185
    export function Get_Color(color: LCD_COLOR): number {
        return color;
    }

    //% blockId=LCD_SetBL
    //% blockGap=8
    //% block="Set backlight level %level"
    //% level.min=0 level.max=10
    //% shim=LCD1IN8::LCD_SetBL
    //% weight=180
    export function LCD_SetBL(level: number): void {
        return;
    }

    //% blockId=DrawPoint
    //% blockGap=8
    //% block="Draw Point|x %x|y %y|color %color|point-size %Dot"
    //% x.min=1 x.max=160 y.min=1 y.max=128
    //% color.min=0 color.max=65535
    //% shim=LCD1IN8::DrawPoint
    //% weight=150
    export function DrawPoint(x: number, y: number, color: number, pix: DOT_PIXEL): void {
        return;
    }

     //% blockId=DrawLine
     //% blockGap=8
     //% block="Draw Line|left %left|top %top|right %right|bottom %bottom|color %color|line-width %width|line-style %style"
     //% left.min=1 left.max=160 top.min=1 top.max=128
     //% right.min=1 right.max=160 bottom.min=1 bottom.max=128
     //% color.min=0 color.max=65535
     //% weight=140
    export function DrawLine(
            left: number,
            top: number,
            right: number,
            bottom: number,
            Color: number,
            width: DOT_PIXEL,
            style: LINE_STYLE): void {
        return;
    }

    //% shim=LCD1IN8::DisChar
    function DisChar(x: number, y: number, ch: string, color: number): void {
        return;
    }

    //% blockId=DisString
    //% blockGap=8
    //% block="Show String|x %x|y %y|char %ch|color %color"
    //% x.min=1 x.max=160 y.min=1 y.max=128
    //% color.min=0 color.max=65535
    //% weight=100
    export function DisString(x: number, y: number, s: string, color: number): void {
        let left = x;
        let top = y;
        let height = 8;
        let width = 8;
        for (let i = 0; i < s.length; i++) {
            if (x + width > 160) {  // newline
                x = left;
                y += height;
            }
            // If the Y direction is full, reposition to(Xstart, Ystart)
            if(y  + height > 128) {
                x = left;
                y = top;
            }
            DisChar(x, y, s.charCodeAt(i), color);

            // The next word of the abscissa increases the font of the broadband
            x += width;
        }
    }

    //% blockId=DisNumber
    //% blockGap=8
    //% block="Show number|x %x|y %y|number %num|color %color"
    //% x.min=1 x.max=160 y.min=1 y.max=128
    //% color.min=0 color.max=65535
    //% weight=100
    export function DisNumber(x: number, y: number, num: number, color: number): void {
        DisString(x, y, num + "", color);
    }

}  // namespace LCD1IN8
