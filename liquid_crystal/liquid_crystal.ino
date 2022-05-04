#include <LiquidCrystal.h>

#define LCD_PIN_REGSELECT 1 // SELECT
#define LCD_PIN_ENABLED 2 // SELECT

#define LCD_DISPLAY_WIDTH 16 // Display width
#define LCD_DISPLAY_HEIGHT 2 // Display height

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

struct LiquidDisplayBase
{
    public:
  
    LiquidDisplayBase()
    {
        LCD_CONTROLLER.begin
        (
          LCD_DISPLAY_WIDTH, // Set display width
          LCD_DISPLAY_HEIGHT // Set display height
        );
      
        LCD_CONTROLLER.home(); // Set cursor to home pos

        LCD_CONTROLLER.noAutoscroll(); // Disable text scrolling
        LCD_CONTROLLER.noBlink(); // Disable cursor blinking
    }    
};
