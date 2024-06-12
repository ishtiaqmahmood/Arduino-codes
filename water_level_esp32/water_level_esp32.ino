#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Define custom SDA and SCL pins
#define CUSTOM_SDA_PIN 4
#define CUSTOM_SCL_PIN 5

// Initialize Wire with custom pins
void setupWire() {
  Wire.begin(CUSTOM_SDA_PIN, CUSTOM_SCL_PIN);
}

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize LCD with address 0x27 and 16x2 dimensions

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

int sensorPin = 36; // Analog pin for sensor
int data = 0;

BLECharacteristic *pCharacteristic;

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
  setupWire(); // Setup Wire with custom pins
  Serial.println("Starting BLE work!");
  setupBLE();

  lcd.begin(16, 2); // Initialize LCD with 16 columns and 2 rows
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Sensor value:");

}

void loop() {
  // Read analog sensor value
  data = analogRead(sensorPin);

  // Print sensor value to serial monitor
  Serial.print("Sensor value: ");
  Serial.println(data);

  // Display sensor value on LCD
  lcd.setCursor(0, 1);
  lcd.print("            "); // Clear previous value
  lcd.setCursor(0, 1);
  lcd.print(data);

  delay(1000);
}