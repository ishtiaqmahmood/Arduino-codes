#include <MQUnifiedsensor.h>
#include <Nokia_LCD.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

#define BLYNK_TEMPLATE_ID "TMPL6B1i3oDkh"
#define BLYNK_TEMPLATE_NAME "Gas Data"
#define BLYNK_AUTH_TOKEN "QAVmZBpmH4I4g3jeN5OFMwdKQiBJmSR9"
#define BLYNK_PRINT Serial

#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, millis() / 1000);
}

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

Nokia_LCD lcd(21/* CLK */, 19 /* DIN */, 5 /* DC */, 4 /* CE */, 2/* RST */);

BLECharacteristic *pCharacteristic;

#define Board ("ESP 32")
#define Pin (36)  // Analog input pin of your ESP32
#define Type ("MQ-2") // Sensor type
#define Voltage_Resolution (5) // Voltage reference
#define ADC_Bit_Resolution (10) // Bit resolution of the ADC
#define RatioMQ2CleanAir (9.83) // Ratio of RS/R0 in clean air for MQ-2

// Coefficients for exponential regression for each gas
#define CO_A 36974.0
#define CO_B -3.109
#define H2_A 987.99
#define H2_B -2.162
#define LPG_A 574.25
#define LPG_B -2.222
#define ALCOHOL_A 3616.1
#define ALCOHOL_B -2.675
#define PROPANE_A 658.71
#define PROPANE_B -2.168

MQUnifiedsensor MQ2(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);

void setupBLE() {
  BLEDevice::init("Gatling");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_NOTIFY
                                       );
  pCharacteristic->addDescriptor(new BLE2902());
  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
}

void setup() {
  Serial.begin(9600); // Initialize serial communication
  Serial.println("Starting BLE work!");
  setupBLE();

  lcd.begin();
  lcd.setBacklight(true);
  lcd.setContrast(55); 

  MQ2.setRegressionMethod(1); 

  MQ2.setA(CO_A); MQ2.setB(CO_B); // CO
  MQ2.setA(H2_A); MQ2.setB(H2_B); // H2
  MQ2.setA(LPG_A); MQ2.setB(LPG_B); // LPG
  MQ2.setA(ALCOHOL_A); MQ2.setB(ALCOHOL_B); // Alcohol
  MQ2.setA(PROPANE_A); MQ2.setB(PROPANE_B); // Propane

  MQ2.init(); 

  Serial.print("Calibrating please wait.");
  float calcR0 = 0;
  for(int i = 1; i<=10; i ++) {
    MQ2.update(); 
    calcR0 += MQ2.calibrate(RatioMQ2CleanAir); 
    Serial.print(".");
  }
  MQ2.setR0(calcR0/10); 
  Serial.println("  done!.");

  if(isinf(calcR0)) {Serial.println("Warning: Connection issue, R0 is infinite (Open circuit detected) please check your wiring and supply"); while(1);}
  if(calcR0 == 0){Serial.println("Warning: Connection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply"); while(1);}

  MQ2.serialDebug(true); 

  Blynk.begin(BLYNK_AUTH_TOKEN);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop() {
  MQ2.update(); 
  float sensorVoltage = MQ2.getVoltage(); 

  float coConcentrationPPM = pow(sensorVoltage, CO_B) * CO_A;
  float h2ConcentrationPPM = pow(sensorVoltage, H2_B) * H2_A;
  float lpgConcentrationPPM = pow(sensorVoltage, LPG_B) * LPG_A;
  float alcoholConcentrationPPM = pow(sensorVoltage, ALCOHOL_B) * ALCOHOL_A;
  float propaneConcentrationPPM = pow(sensorVoltage, PROPANE_B) * PROPANE_A;

  float coPercentage = coConcentrationPPM / 10000.0;
  float h2Percentage = h2ConcentrationPPM / 10000.0;
  float lpgPercentage = lpgConcentrationPPM / 10000.0;
  float alcoholPercentage = alcoholConcentrationPPM / 10000.0;
  float propanePercentage = propaneConcentrationPPM / 10000.0;

  if (!isinf(coPercentage) && !isinf(h2Percentage) && !isinf(lpgPercentage) && !isinf(alcoholPercentage) && !isinf(propanePercentage)) {
    Serial.print("CO percentage: ");
    Serial.print(coPercentage);
    Serial.println(" %");
    lcd.setCursor(0, 0);
    lcd.print("CO: ");
    lcd.println(coPercentage);
    String coString = "CO: ";
    coString += coPercentage;
    //pCharacteristic->setValue(coString.c_str());

    Serial.print("H2 percentage: ");
    Serial.print(h2Percentage);
    Serial.println(" %");
    lcd.setCursor(0, 1);
    lcd.print("H2: ");
    lcd.println(h2Percentage);
    String h2String = "H2: ";
    h2String += h2Percentage;
    //pCharacteristic->setValue(h2String.c_str());

    Serial.print("LPG percentage: ");
    Serial.print(lpgPercentage);
    Serial.println(" %");
    lcd.setCursor(0, 2);
    lcd.print("LPG: ");
    lcd.println(lpgPercentage);
    String lpgString = "LPG: ";
    lpgString += lpgPercentage;
    //pCharacteristic->setValue(lpgString.c_str());

    Serial.print("Alcohol percentage: ");
    Serial.print(alcoholPercentage);
    Serial.println(" %");
    lcd.setCursor(0, 3);
    lcd.print("Alcohol: ");
    lcd.println(alcoholPercentage);
    String alString = "Alcohol: ";
    alString += alcoholPercentage;
    //pCharacteristic->setValue(alString.c_str());


    Serial.print("Propane percentage: ");
    Serial.print(propanePercentage);
    Serial.println(" %");
    lcd.setCursor(0, 4);
    lcd.print("Propane: ");
    lcd.println(propanePercentage);
    String poString = "Propane: ";
    poString += propanePercentage;
  
   // Update BLE characteristic value with all sensor data
    String sensorData = String(coString) + "," + String(h2String) + "," + String(lpgString) + "," + String(alString) + "," + String(poString);
    pCharacteristic->setValue(sensorData.c_str());

    pCharacteristic->notify();

    Blynk.run();
    timer.run(); // Initiates BlynkTimer
  }

  delay(1000);
}