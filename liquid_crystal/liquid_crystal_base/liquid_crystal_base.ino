#include <LiquidCrystal.h>

#define LCD_PIN_REGSELECT 8 // SELECT
#define LCD_PIN_ENABLED 2 // SELECT

#define LCD_DISPLAY_WIDTH 16 // Display width
#define LCD_DISPLAY_HEIGHT 2 // Display height

#define LCD_PIN_DATA1 7 // SELECT
#define LCD_PIN_DATA2 6 // SELECT
#define LCD_PIN_DATA3 5 // SELECT
#define LCD_PIN_DATA4 4 // SELECT

LiquidCrystal LCD_CONTROLLER
(
    LCD_PIN_REGSELECT,
    LCD_PIN_ENABLED,

    LCD_PIN_DATA1, LCD_PIN_DATA2,
    LCD_PIN_DATA3, LCD_PIN_DATA4
);

#define LCD_SHIELD_BUTTON_PIN A0 // SELECT

#define LCD_SHIELD_BUTTON_RIGTH 1 // Button "Right" keycode
#define LCD_SHIELD_BUTTON_LEFT 2 // Button "Left" keycode
#define LCD_SHIELD_BUTTON_UP 3 // Button "Up" keycode
#define LCD_SHIELD_BUTTON_DOWN 4 // Button "Down" keycode

#define LCD_SHIELD_BUTTON_SELECT 5 // Button "Select" keycode

#define LCD_SHIELD_NO_BUTTON 0 // No-Button status code

void LiquidDisplayInit()
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

unsigned short LCD_BUTTON_INPUT_HANDLER(void)
{
    // Read LCD buttons status pin value

    unsigned short LCD_BUTTON_KEYCODE = analogRead(LCD_SHIELD_BUTTON_PIN);

    if(LCD_BUTTON_KEYCODE < 100)
    {
        // Current pressed button is "Right"

        return LCD_SHIELD_BUTTON_RIGTH;
    }
    
    else if(LCD_BUTTON_KEYCODE < 200)
    {
        // Current pressed button is "Right"

        return LCD_SHIELD_BUTTON_UP;
    }
    
    else if(LCD_BUTTON_KEYCODE < 400)
    {
        // Current pressed button is "Right"

        return LCD_SHIELD_BUTTON_DOWN;
    }

    else if(LCD_BUTTON_KEYCODE < 600)
    {
        // Current pressed button is "Right"

        return LCD_SHIELD_BUTTON_LEFT;
    }

    else if(LCD_BUTTON_KEYCODE < 800)
    {
        // Current pressed button is "Right"

        return LCD_SHIELD_BUTTON_SELECT;
    }
    
    // No active buttons signal found

    return LCD_SHIELD_NO_BUTTON;
}