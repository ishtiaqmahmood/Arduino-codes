#include<LiquidCrystal.h>

LiquidCrystal lcd(5,6,7,8,9,10);

int tmp = A0;
float value = 0;
float degree = 0;
float fahr = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);

  pinMode(tmp, INPUT);

  Serial.begin(9600);
}

void loop() {

  value = analogRead(tmp);
  degree = ((5000*value)/1024)/10;
  fahr = degree*(9/5)+32;
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Temperature is : ");
  lcd.setCursor(1, 1);
  lcd.print(degree);
  lcd.print((char)223);
  delay(500);
  lcd.print("C ");
  lcd.print(fahr);
  lcd.print((char)223);
  delay(500);
  lcd.print("F");
  //delay(2000);
  //lcd.autoscroll();
  //lcd.clear();
  Serial.println(value);
}
