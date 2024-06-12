#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <HMC5883L.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);


// Store our compass as a variable.
HMC5883L compass;
// Record any errors that may occur in the compass.
int error = 0;

MagnetometerScaled valueOffset;

void setup() {

  // put your setup code here, to run once:
  lcd.init();  // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();

  error = compass.setScale(1.3); 
    if(error != 0) // If there is an error, print it out.
    Serial.println(compass.getErrorText(error));
  
  Serial.println("Setting measurement mode to continous.");
  error = compass.setMeasurementMode(MEASUREMENT_CONTINUOUS); // Set the measurement mode to Continuous
  if(error != 0) // If there is an error, print it out.
    Serial.println(compass.getErrorText(error));
}

void loop() {
  // put your main code here, to run repeatedly:
  MagnetometerRaw raw = compass.readRawAxis();
  // Retrived the scaled values from the compass (scaled to the configured scale).
  MagnetometerScaled scaled = compass.readScaledAxis();

  scaled.XAxis -= valueOffset.XAxis;
  scaled.YAxis -= valueOffset.YAxis;
  scaled.ZAxis -= valueOffset.ZAxis;

  // Values are accessed like so:
  int MilliGauss_OnThe_XAxis = scaled.XAxis;  // (or YAxis, or ZAxis)

  // Calculate heading when the magnetometer is level, then correct for signs of axis.
  float yxHeading = atan2(scaled.YAxis, scaled.XAxis);
  float zxHeading = atan2(scaled.ZAxis, scaled.XAxis);

  float heading = yxHeading;

  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Mine is: -2��37' which is -2.617 Degrees, or (which we need) -0.0456752665 radians, I will use -0.0457
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  float declinationAngle = -0.0457;
  heading += declinationAngle;

  // Correct for when signs are reversed.
  if (heading < 0)
    heading += 2 * PI;

  // Check for wrap due to addition of declination.
  if (heading > 2 * PI)
    heading -= 2 * PI;

  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180 / M_PI;

  float yxHeadingDegrees = yxHeading * 180 / M_PI;
  float zxHeadingDegrees = zxHeading * 180 / M_PI;


  lcd.setCursor(0, 0);
  lcd.print("X : ");
  lcd.print(scaled.XAxis);
  lcd.print("Y : ");
  lcd.print(scaled.YAxis);
  lcd.setCursor(0, 1);
  lcd.print("Z : ");
  lcd.print(scaled.ZAxis);


  lcd.setCursor(0, 2);
  lcd.print("Heading (degrees): ");
  lcd.setCursor(6, 3);
  lcd.print(headingDegrees);
}
