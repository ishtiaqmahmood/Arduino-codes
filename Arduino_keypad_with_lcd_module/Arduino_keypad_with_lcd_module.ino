#include <Keypad.h>
#include <LCD_I2C.h>
#include <Wire.h>

LCD_I2C lcd(0x3F, 16, 2);

char input_from_user[4];

int data_count = 0;

const char rows = 4;
const char cols = 3;


char row_pins[rows] = { 10, 9, 8, 7 };
char cols_pins[cols] = { 6, 5, 4 };

char key_array[rows][cols] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' }, { '*', '0', '#' } };

Keypad k = Keypad(makeKeymap(key_array), row_pins, cols_pins, rows, cols);


void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);

  lcd.setCursor(5, 0);
  lcd.print("Hello");
}

void loop() {
  // put your main code here, to run repeatedly:
  char key_pressed = k.getKey();
  if (key_pressed) {
    Serial.println(key_pressed);
  }

  if (key_pressed) {
    lcd.setCursor(0, 0);
    lcd.print("Student ID : ");
    delay(200);

    input_from_user[data_count] = key_pressed;
    lcd.setCursor(4 + data_count, 1);
    lcd.print(input_from_user[data_count]);
    data_count++;
    delay(1000);
    if (data_count == 4) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Your ID is : ");
      lcd.setCursor(5, 1);
      for (int i = 0; i < 4; i++) {
        lcd.print(input_from_user[i]);
      }
    }
    
  }
}
