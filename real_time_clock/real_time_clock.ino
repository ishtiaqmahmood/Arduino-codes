#include<Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

ThreeWire myWire(12, 11, 13); // DAT, CLK, RST
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {
  // put your setup code here, to run once:

  Rtc.Begin();

  RtcDateTime currentTime = RtcDateTime(__DATE__, __TIME__);
  Rtc.SetDateTime(currentTime);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  RtcDateTime now = Rtc.GetDateTime();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Date: ");
  lcd.print(now.Day());
  lcd.print("/");
  lcd.print(now.Month());
  lcd.print("/");
  lcd.print(now.Year());
  
  lcd.setCursor(0,1);
  lcd.print("Time: ");
  lcd.print(now.Hour());
  lcd.print(":");
  lcd.print(now.Minute());
  lcd.print(":");
  lcd.print(now.Second());

  delay(500);
}
