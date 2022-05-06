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

void lcd_print_string(unsigned short line_number, String line_text)
{
    LCD_CONTROLLER.setCursor(0, line_number); // Set cursor to selected line
    
    for(unsigned short counter = 0; counter < LCD_DISPLAY_WIDTH; counter++)
    {
        LCD_CONTROLLER.print((char)(0x20)); // Clear each string symbol
    }

    LCD_CONTROLLER.setCursor(0, line_number); // Set cursor to string begin

    LCD_CONTROLLER.print(line_text); // Print provided text
}

String LCD_MENU_ROOT_CASES =
{
    "1.Coil diameter", // Coil diameter selector

    "2.Coil turns", // Coil turns count selector

    "3.Wire diameter" // Wire diameter selector
};

void LCD_MENU_SECTION_ROOT()
{
    LCD_CONTROLLER.clear(); // Clear display

    LCD_CONTROLLER.setCursor(0, 0); // Set cursor to the start

    LCD_CONTROLLER.print("Winding machine:"); // Print menu logotype

    

}