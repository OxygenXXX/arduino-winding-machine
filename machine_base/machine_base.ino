#include <LiquidCrystal.h>
#include <MenuSystem.h>

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

#define LCD_SHIELD_BUTTON_RIGTH 0
#define LCD_SHIELD_BUTTON_LEFT 0
#define LCD_SHIELD_BUTTON_UP 0
#define LCD_SHIELD_BUTTON_DOWN 0

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

  LCD_CONTROLLER.print("Menu Main");
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

unsigned short BUTTON_INPUT_HANDLER()
{
  
}

void setup(void)
{
    LCD_CONTROLLER.begin(16,2);

    Serial.begin(9600);

    LCD_MENU_SECTION_MAIN();
}

void loop(void)
{
  unsigned short BUTTON_CODE = analogRead(LCD_SHIELD_BUTTON);

  Serial.print(BUTTON_CODE);

  if(BUTTON_CODE < 100)
  {
    LCD_MENU_SECTION2();
  }
  
  else if(BUTTON_CODE < 400)
  {
    LCD_MENU_SECTION1();
  }
}
