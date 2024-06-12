#include <Nokia_LCD.h>
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

Nokia_LCD lcd(6 /* CLK */, 5 /* DIN */, 4 /* DC */, 3 /* CE */, 2/* RST */);

#define REPORTING_PERIOD_MS     1000

// PulseOximeter is the higher level interface to the sensor
// it offers:
//  * beat detection reporting
//  * heart rate calculation
//  * SpO2 (oxidation level) calculation
PulseOximeter pox;

uint32_t tsLastReport = 0;

// Callback (registered below) fired when a pulse is detected
void onBeatDetected()
{
    Serial.println("Beat!");
}


void setup() {
  // put your setup code here, to run once:
  // Initialize the screen
  lcd.begin();
  // Turn on the backlight
  lcd.setBacklight(true);
  // Set the contrast
  lcd.setContrast(40);  // Good values are usualy between 40 and 60
  
  // Clear the screen by filling it with black pixels
  lcd.clear();
  
  // Set the cursor on the beginning of the 6th row (the last one)
  // Write something on the specific row with inverted color
  
  Serial.begin(115200);

  Serial.print("Initializing - pulse & oximeter..");
  lcd.setCursor(1, 1);
  lcd.print("Initializing - pulse & oximeter.....");

    // Initialize the PulseOximeter instance
    // Failures are generally due to an improper I2C wiring, missing power supply
    // or wrong target chip
  if (!pox.begin()) {
      lcd.clear();
      lcd.setCursor(3, 2);
      lcd.print("FAILED");
      Serial.println("FAILED");
      for(;;);
  } else {
      lcd.clear();
      lcd.setCursor(3, 2);
      lcd.print("SUCCESS");
      Serial.println("SUCCESS");
  }

    // The default current for the IR LED is 50mA and it could be changed
    //   by uncommenting the following line. Check MAX30100_Registers.h for all the
    //   available options.
    // pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);

    // Register a callback for the beat detection
  pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Make sure to call update as fast as possible
  pox.update();

  // Asynchronously dump heart rate and oxidation levels to the serial
  // For both, a value of 0 means "invalid"
  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
    Serial.print("Heart rate:");
    lcd.clear();
    lcd.setCursor(2, 2);
    lcd.print("Heart rate:");
    Serial.print(pox.getHeartRate());
    lcd.print(pox.getHeartRate());
    Serial.print("bpm / SpO2:");
    lcd.setCursor(4, 2);
    lcd.print("bpm / SpO2:");
    Serial.print(pox.getSpO2());
    lcd.print(pox.getSpO2());
    Serial.println("%");
    lcd.setCursor(5, 3);
    lcd.print("%");

    tsLastReport = millis();
  }


}
