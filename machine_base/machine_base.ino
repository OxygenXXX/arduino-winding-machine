#include <LiquidCrystal.h>

#define LCD_PIN_REGSELECT 8 // SELECT
#define LCD_PIN_ENABLED 9 // SELECT

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

#define LCD_SHIELD_BUTTON A0

#define LCD_SHIELD_BUTTON_RIGTH 1
#define LCD_SHIELD_BUTTON_LEFT 2
#define LCD_SHIELD_BUTTON_UP 3
#define LCD_SHIELD_BUTTON_DOWN 4

#define LCD_SHIELD_NO_BUTTON 0

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

void LCD_MENU_SECTION_MAIN()
{
    LCD_CONTROLLER.clear();
    LCD_CONTROLLER.setCursor(0, 0);
  
    LCD_CONTROLLER.print("Winding Machine:");

    LCD_CONTROLLER.setCursor(0, 1);

    
    
}

void LCD_MENU_SECTION1()
{
    LCD_CONTROLLER.clear();
    LCD_CONTROLLER.setCursor(0, 0);
  
    LCD_CONTROLLER.print("Menu Sec 1");
  
    delay(1500);
}

void LCD_MENU_SECTION2()
{
    LCD_CONTROLLER.clear();
    LCD_CONTROLLER.setCursor(0, 0);
  
    LCD_CONTROLLER.print("Menu Sec 2");
  
    delay(1500);
}

unsigned short BUTTON_INPUT_HANDLER(unsigned short BUTTON_CODE)
{
    if(BUTTON_CODE < 100)
    {
        return LCD_SHIELD_BUTTON_RIGTH;
    }
    
    else if(BUTTON_CODE < 200)
    {
        return LCD_SHIELD_BUTTON_RIGTH;
    }
    
    else if(BUTTON_CODE < 400)
    {
        return LCD_SHIELD_BUTTON_RIGTH;
    }

    else if(BUTTON_CODE < 600)
    {
        return LCD_SHIELD_BUTTON_RIGTH;
    }

    else if(BUTTON_CODE < 800)
    {
        return LCD_SHIELD_BUTTON_RIGTH;
    }

    else
    {
        return LCD_SHIELD_NO_BUTTON;
    }
}

void setup(void)
{
    Serial.begin(9600);
  
    LiquidDisplayInit();
}

void loop(void)
{
  unsigned short SHIELD_BUTTON_CODE = analogRead(LCD_SHIELD_BUTTON);

  
}
