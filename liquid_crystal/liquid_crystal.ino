#include <LiquidCrystal.h>

class LiquidCrystalBase
{
    public:

    #define LCD_DISPLAY_WIDTH 16
    #define LCD_DISPLAY_HEIGTH 2

    #define LCD_PIN_REGSELECT // SELECT //
    #define LCD_PIN_ENABLED // SELECT //

    #define LCD_PIN_DATA1 // SELECT //
    #define LCD_PIN_DATA2 // SELECT //
    #define LCD_PIN_DATA3 // SELECT //
    #define LCD_PIN_DATA4 // SELECT //

    LiquidCrystal LCD_CONTROLLER;

    LiquidCrystalBase()
    {
        this->LCD_CONTROLLER = new LiquidCrystal
        (
            LCD_PIN_REGSELECT,
            LCD_PIN_ENABLED,

            LCD_PIN_DATA1, LCD_PIN_DATA2,
            LCD_PIN_DATA3, LCD_PIN_DATA4
        );

        this->LCD_CONTROLLER.noBlink(); // Disable cursor blinking
        this->LCD_CONTROLLER.autoscroll(); // Enable text scrolling
    }
}
