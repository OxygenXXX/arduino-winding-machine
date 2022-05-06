#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define BUTTON_UP 1
#define BUTTON_DOWN 2

#define BUTTON_LEFT 3
#define BUTTON_RIGHT 4

#define BUTTON_SELECT 5
#define BUTTON_NONE 10

int button_handler() 
{
  int key_analog_value = analogRead(A0);

  if (key_analog_value < 100) 
  {
    return BUTTON_RIGHT;
  } 

  else if (key_analog_value < 200) 
  {
    return BUTTON_UP;
  } 

  else if (key_analog_value < 400) 
  {
    return BUTTON_DOWN;
  } 

  else if (key_analog_value < 600) 
  {
    return BUTTON_LEFT;
  } 

  else if (key_analog_value < 800) 
  {
    return BUTTON_SELECT;
  } 

  else 
  {
    return BUTTON_NONE;
  }
}

void clearLine(int line_number)
{
  lcd.setCursor(0, line_number - 1);
  lcd.print("                ");
}

void printDisplay(String message_text)
{
  Serial.println(message_text);

  lcd.setCursor(0, 1);
  lcd.print(message_text);

  delay(1000);
  clearLine(2);
}

void setup() 
{
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);

  lcd.print("Arduino Master");
}

void loop() 
{  
  int current_button = button_handler();

  switch (current_button) 
  {
    case BUTTON_UP:
      printDisplay("UP"); break;

    case BUTTON_DOWN:
      printDisplay("DOWN"); break;

    case BUTTON_LEFT:
      printDisplay("LEFT"); break;

    case BUTTON_RIGHT:
      printDisplay("RIGHT"); break;

    case BUTTON_SELECT:
      printDisplay("SELECT"); break;

    default: break;
  }
}
