#include<LiquidCrystal.h>

LiquidCrystal lcd(5,6,7,8,9,10);

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup() {
  // put your setup code here, to run once:
  lcd.createChar(0, smiley);
  lcd.begin(16,2);
  lcd.write(byte(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  //lcd.setCursor(2,0);
  //lcd.print("Hello Arduino");
  //lcd.setCursor(0, 1);
  //lcd.print("Ishtiaq Mahmood");
  //delay(2000);
  //lcd.autoscroll();
  //lcd.clear();
  lcd.setCursor(2,0);
  lcd.print(smiley[0]);

}
