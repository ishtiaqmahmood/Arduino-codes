#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize LCD with address 0x27 and 16x2 dimensions


int sensorPin = A0; // Analog pin for sensor

int red = 2;
int blue = 3;
int green = 4;
int buzzer = 5;

void setup() {
  Serial.begin(9600); // Initialize serial communication

  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2); // Initialize LCD with 16 columns and 2 rows
  lcd.init();
  lcd.backlight();
  lcd.clear();
  

}

void loop() {
  // Read analog sensor value
  int data = analogRead(sensorPin);

  // Print sensor value to serial monitor
  Serial.print("Sensor value: ");
  Serial.println(data);

  // Display sensor value on LCD
  lcd.setCursor(4, 0);
  lcd.print("Level: ");
  lcd.print(data);

  if(data < 100){
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Level: ");
    lcd.print(data);
    lcd.setCursor(4, 1);
    lcd.println("Surface     ");
    delay(100);
    digitalWrite(blue, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(buzzer, LOW);
  }

  else if(data >= 300 && data < 400){
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Level: ");
    lcd.print(data);
    lcd.setCursor(2, 1);
    lcd.println("Shallow Water ");
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(buzzer, LOW);
    delay(100);
  }

  else if(data >= 400 && data < 500){
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Level: ");
    lcd.print(data);
    lcd.setCursor(3, 1);
    lcd.println("Deep Water    ");
    digitalWrite(blue, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(buzzer, LOW);
    delay(100);
  }

  else if(data >= 500){
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Level: ");
    lcd.print(data);
    lcd.setCursor(0, 1);
    lcd.println("Going to bottom ");
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    digitalWrite(buzzer, HIGH);
    delay(100);
  }

}