# LCD1in8

waveshare electronics

![Waveshare_logo.png](Waveshare_logo.png)

# Package product
https://www.waveshare.com/1.8inch-lcd-for-micro-bit.htm

# test
Test can refer to test.ts

# user
For reference, please refer to our user manual.
Chinese wiki: http://www.waveshare.net/wiki/1.8inch_LCD_for_micro:bit
English wiki: https://www.waveshare.com/wiki/1.8inch_LCD_for_micro:bit

If you find that there are many places to change, 
such as the function name changed you can find the answer here,
Or contact us

1.Initiation: 
You need to initial LCD module first.

block: LCD1IN8 Init.
javascript: LCD_initialize()

2.Clear the screen:
Clear the screen to white. Create an buffer on RAM with the resolution size 160*128 and initial it to white.

block: Clear Clear screen and cache.
javascript: LCD_initialize()

3.Set the backlight:

block: Set back light level.
javascript: LCD_backlightLevel()

4.Send display data:
With this block, it will send one frame of buffer to the LCD and display. 
Note: it is always following drawing operation.

block: Send display data.
javascript: LCD_display()

5.Send widows display data:
Sometimes it is not necessary to refresh the entire screen data, 
only need to display part of the window data.

block: Send widows display data.
javascript: LCD_displayWindow()

6.Clear screen and cache:

block: Clear screen and cache.
javascript: LCD_clear()

7.Fill the full screen color:
block: Filling Color.
javascript: LCD_filling()

8.Draw point:
Place the block before send display data. 
You can choose the position, color and size. 
For the screen, (1,1) is on top-left, and (160,128) is on bottom-right
There are tow way to set the color, 
the one is use the color block as above, 
another is to set the value (RGB565) by drag the slider.

block: Draw Point.
javascript: drawPoint()

9.Draw line:
You can choose the the line's position, color, size and its sytle.

block: Draw Line.
javascript: drawLine()

10.Draw rectange:

block: Draw Rectange.
javascript: drawRectangle()

11.Draw Circle:

block: Draw Circle.
javascript: drawCircle()

12.Show String:

block: Show String.
javascript: drawString()

13.Show number:

block: Show number.
javascript: drawNumber()

#More parameters can be found in test.ts for a detailed understanding.

## License

MIT

## Supported targets

* for PXT/microbit
(The metadata above is needed for package search.)

