#include <LiquidCrystal.h>

class LiquidScreen
{
    public:

    #define LCD_DISPLAY_WIDTH 16
    #define LCD_DISPLAY_HEIGTH 2

    #define LCD_PIN_REGSELECT 1 // SELECT
    #define LCD_PIN_ENABLED 2 // SELECT

    #define LCD_PIN_DATA1 4 // SELECT
    #define LCD_PIN_DATA2 5 // SELECT
    #define LCD_PIN_DATA3 6 // SELECT
    #define LCD_PIN_DATA4 7 // SELECT

    LiquidCrystal LCD_CONTROLLER
    (
        LCD_PIN_REGSELECT,
        LCD_PIN_ENABLED,

        LCD_PIN_DATA1, LCD_PIN_DATA2,
        LCD_PIN_DATA3, LCD_PIN_DATA4
    );

    LiquidScreen()
    {
        this->LCD_CONTROLLER.noBlink(); // Disable cursor blinking
        this->LCD_CONTROLLER.autoscroll(); // Enable text scrolling
    }
};
