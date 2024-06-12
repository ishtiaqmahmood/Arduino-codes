#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);



void setup() {
  // put your setup code here, to run once:
  lcd.init();  // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
}

void loop() {
  lcd.setCursor(7, 1);
  // put your main code here, to run repeatedly:
  int light = analogRead(A0);
  if(light < 10){
    lcd.clear();
    lcd.setCursor(7, 1);
    lcd.print("Very Bright");
  }
  else if(light < 200){
    lcd.clear();
    lcd.setCursor(7, 1);
    lcd.print("Bright");
  }
  else if(light < 500){
    lcd.clear();
    lcd.setCursor(7, 1);
    lcd.print("Light");
  }
  else if(light < 800){
    lcd.clear();
    lcd.setCursor(7, 1);
    lcd.print("Dim");
  } 
  else {
    lcd.clear();
    lcd.setCursor(7, 1);
    lcd.print("Dark");
  }
  delay(500);
}
