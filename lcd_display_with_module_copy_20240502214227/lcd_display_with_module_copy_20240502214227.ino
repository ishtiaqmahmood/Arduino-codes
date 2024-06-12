#include <LCD_I2C.h>

LCD_I2C lcd(0x3F, 16, 2); 

void setup()
{
    lcd.begin();
    lcd.backlight();
}

void loop()
{
    //Autoscroll
    lcd.setCursor(5, 0);
    lcd.print(F("Autoscrolling"));
    lcd.setCursor(10, 1);
    lcd.autoscroll();

    for (int i = 0; i < 10; i++)
    {
        lcd.print(i);
        delay(200);
    }

    lcd.noAutoscroll();
    lcd.clear();

    
}