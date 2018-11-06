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

<<<<<<< HEAD
//% blockId=LCD_Init
//% blockGap=8
//% block="LCD1IN8 Init"
//% shim=LCD1IN8::LCD_Init
//% weight=200
export function LCD_Init(): void {
    return;
}
=======
    //% blockId=LCD_Init
    //% blockGap=8
    //% block="LCD1IN8 Init"
    //% shim=LCD1IN8::LCD_Init
    //% weight=200
    export function LCD_Init(): void{
        return;
    }

 //% blockId=LCD_Clear
    //% blockGap=8
    //% block="Clear screen and cache"
    //% shim=LCD1IN8::LCD_Clear
    //% weight=195
    export function LCD_Clear(): void{
       return;
    }

    //% blockId=LCD_Filling
    //% blockGap=8
    //% block="Filling Color %Color"
    //% shim=LCD1IN8::LCD_Filling
    //% weight=194
    export function LCD_Filling(Color: number): void{
       return;
    }

 //% blockId=LCD_Display
    //% blockGap=8
    //% block="Send display data"
    //% shim=LCD1IN8::LCD_Display
    //% weight=190
    export function LCD_Display(): void{
        return;
    }

    //% blockId=LCD_DisplayWindows
    //% blockGap=8
    //% block="Show Windows display data |Xstart %Xstart|Ystart %Ystart|Xend %Xend|Yend %Yend "
    //% shim=LCD1IN8::LCD_DisplayWindows
    //% Xstart.min=1 Xstart.max=160 Ystart.min=1 Ystart.max=128
    //% Xend.min=1 Xend.max=160 Yend.min=1 Yend.max=128
    //% weight=189
    export function LCD_DisplayWindows(Xstart: number, Ystart: number, Xend: number, Yend: number): void{
        return;
    }

    //% blockId=Get_Color
    //% blockGap=8
    //% block="%Color"
    //% weight=185
    export function Get_Color(Color: LCD_COLOR): number{
        return Color;
    }

 //% blockId=LCD_SetBL
    //% blockGap=8
    //% block="Set back light level %Lev"
 //% Lev.min=0 Lev.max=10
    //% shim=LCD1IN8::LCD_SetBL
    //% weight=180
    export function LCD_SetBL(Lev: number): void{
        return;
    }

    //% blockId=DrawPoint
    //% blockGap=8
    //% block="Draw Point|x %x|y %y|Color %Color|Point Size %Dot"
    //% x.min=1 x.max=160 y.min=1 y.max=128
    //% Color.min=0 Color.max=65535
    //% shim=LCD1IN8::DrawPoint
    //% weight=150
    export function DrawPoint(x: number, y: number, Color: number, Dot: DOT_PIXEL): void{
        return;
    }

 //% blockId=DrawLine
 //% blockGap=8
 //% block="Draw Line|Xstart %Xstart|Ystart %Ystart|Xend %Xend|Yend %Yend|Color %Color|Line width %Line_width|Line Style %Line_Style"
 //% Xstart.min=1 Xstart.max=160 Ystart.min=1 Ystart.max=128
 //% Xend.min=1 Xend.max=160 Yend.min=1 Yend.max=128
 //% Color.min=0 Color.max=65535
 //% weight=140
    export function DrawLine(Xstart: number, Ystart: number, Xend: number, Yend: number, Color: number, Line_width: DOT_PIXEL, Line_Style: LINE_STYLE): void {
        if (Xstart > Xend)
            Swop_AB(Xstart, Xend);
        if (Ystart > Yend)
            Swop_AB(Ystart, Yend);
>>>>>>> 2c9890625b6296f78e88d0bc128c8470a638a65d

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
//% block="Filling Color %Color"
//% shim=LCD1IN8::LCD_Filling
//% weight=194
export function LCD_Filling(Color: number): void {
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
//% block="Show Windows display data |Xstart %Xstart|Ystart %Ystart|Xend %Xend|Yend %Yend "
//% shim=LCD1IN8::LCD_DisplayWindows
//% Xstart.min=1 Xstart.max=160 Ystart.min=1 Ystart.max=128
//% Xend.min=1 Xend.max=160 Yend.min=1 Yend.max=128
//% weight=189
export function LCD_DisplayWindows(Xstart: number, Ystart: number, Xend: number, Yend: number): void {
    return;
}

//% blockId=Get_Color
//% blockGap=8
//% block="%Color"
//% weight=185
export function Get_Color(Color: LCD_COLOR): number {
    return Color;
}

//% blockId=LCD_SetBL
//% blockGap=8
//% block="Set back light level %Lev"
//% Lev.min=0 Lev.max=10
//% shim=LCD1IN8::LCD_SetBL
//% weight=180
export function LCD_SetBL(Lev: number): void {
    return;
}

//% blockId=DrawPoint
//% blockGap=8
//% block="Draw Point|x %x|y %y|Color %Color|Point Size %Dot"
//% x.min=1 x.max=160 y.min=1 y.max=128
//% Color.min=0 Color.max=65535
//% shim=LCD1IN8::DrawPoint
//% weight=150
export function DrawPoint(x: number, y: number, Color: number, Dot: DOT_PIXEL): void {
    return;
}

 //% blockId=DrawLine
 //% blockGap=8
 //% block="Draw Line|Xstart %Xstart|Ystart %Ystart|Xend %Xend|Yend %Yend|Color %Color|Line width %Line_width|Line Style %Line_Style"
 //% Xstart.min=1 Xstart.max=160 Ystart.min=1 Ystart.max=128
 //% Xend.min=1 Xend.max=160 Yend.min=1 Yend.max=128
 //% Color.min=0 Color.max=65535
 //% weight=140
export function DrawLine(
        Xstart: number,
        Ystart: number,
        Xend: number,
        Yend: number,
        Color: number,
        Line_width: DOT_PIXEL,
        Line_Style: LINE_STYLE): void {
    return;
}

//% shim=LCD1IN8::DisChar
function DisChar(Xchar: number, Ychar: number, Char: string, Color: number): void {
    return;
}

//% blockId=DisString
//% blockGap=8
//% block="Show String|X %Xchar|Y %Ychar|char %ch|Color %Color"
//% Xchar.min=1 Xchar.max=160 Ychar.min=1 Ychar.max=128
//% Color.min=0 Color.max=65535
//% weight=100
export function DisString(Xchar: number, Ychar: number, ch: string, Color: number): void {
    let Xpoint = Xchar;
    let Ypoint = Ychar;
    let Font_Height = 8;
    let Font_Width = 8;
    for (let i = 0; i < ch.length; i++) {
        if (Xpoint + Font_Width > 160) {  // newline
            Xpoint = Xchar;
            Ypoint += Font_Height;
        }
        // If the Y direction is full, reposition to(Xstart, Ystart)
        if(Ypoint  + Font_Height > 128) {
            Xpoint = Xchar;
            Ypoint = Ychar;
        }
        DisChar(Xpoint, Ypoint, ch.charCodeAt(i), Color);

        // The next word of the abscissa increases the font of the broadband
        Xpoint += Font_Width;
    }
}

//% blockId=DisNumber
//% blockGap=8
//% block="Show number|X %Xnum|Y %Ynum|number %num|Color %Color"
//% Xnum.min=1 Xnum.max=160 Ynum.min=1 Ynum.max=128
//% Color.min=0 Color.max=65535
//% weight=100
export function DisNumber(Xnum: number, Ynum: number, num: number, Color: number): void{
    let Xpoint = Xnum;
    let Ypoint = Ynum;
    DisString(Xnum, Ynum, num + "", Color);
}

}  // namespace LCD1IN8
