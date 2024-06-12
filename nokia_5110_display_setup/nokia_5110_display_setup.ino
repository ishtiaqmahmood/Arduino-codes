#include <Nokia_LCD.h>


Nokia_LCD lcd(6 /* CLK */, 5 /* DIN */, 4 /* DC */, 3 /* CE */, 2/* RST */);

/**
 * Or, if you would like to control the backlight on your own, init the lcd without the last argument
 * Nokia_LCD lcd(13, 12, 11, 10, 9);
*/

void setup() {
  // Initialize the screen
  lcd.begin();
  // Turn on the backlight
  lcd.setBacklight(true);
  // Set the contrast
  lcd.setContrast(45);  // Good values are usualy between 40 and 60
  // Clear the screen by filling it with black pixels
  lcd.clear();
  
  // Set the cursor on the beginning of the 6th row (the last one)
  lcd.setCursor(0, 1);
  // Write something on the specific row with inverted color
  
  lcd.print("Hello world!");
  
  // The cursor is still on the 6th row. Newline characters ('\n') move the
  // cursor to the next line. Since we were on the last row, the cursor goes
  // back to the first line. If you check the return value of `println`
  // it will indicate whether an out-of-bounds error occured. In this case it
  // will be `true`.
}

void loop() {
  // put your main code here, to run repeatedly:
}