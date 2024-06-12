#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#define BMP280_ADDRESS 0x76
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 


Adafruit_BMP280 bmp;  // use I2C interface


void setup() {
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  Serial.begin(9600);          // initialize serial communication with baud rate of 9600
  while (!Serial) delay(100);  // wait for native usb
  Serial.println(F("BMP280 test"));

  unsigned status;
  status = bmp.begin(BMP280_ADDRESS);
  if (!status) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                     "try a different address!"));
    while (1) delay(10);  // Stop code execution if the sensor is not found.
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  
  
}

void loop() {
lcd.setCursor(5, 0);
  lcd.print("BMP 280");
  // Read and print temperature in degrees Celsius.
  Serial.print(F("Temperature = "));
  Serial.print(bmp.readTemperature());
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(bmp.readTemperature());
  lcd.print(" C");
  Serial.println(" °C");

  //Read and print atmospheric pressure in hectopascals (hPa).
  Serial.print(F("Pressure = "));
  Serial.print(bmp.readPressure());
  lcd.setCursor(0, 2);
  lcd.print("Pres: ");
  lcd.print(bmp.readPressure());
  lcd.print(" hPa");
  Serial.println(" hPa");

  //Read and print approximate altitude based on standard pressure (1013.25 hPa).
  Serial.print(F("Approx altitude = "));
  Serial.print(bmp.readAltitude());
  lcd.setCursor(0, 3);
  lcd.print("Altitude: ");
  lcd.print(bmp.readAltitude());
  lcd.print(" m");
  Serial.println(" m");
  Serial.println();  // Print a blank line to separate readings.  
  delay(2000);       // Wait for 2 seconds before taking the next set of readings.
}
