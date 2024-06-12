#include <Servo.h>
Servo myservo;

int red = 8;
int green = 7;
char sms;
int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  myservo.attach(9);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  if(Serial.available() != 0){
    sms = Serial.read();
    
  }
  if(sms == '1'){
    digitalWrite(red, HIGH);
    Serial.println("RED LED trun on");
    myservo.write(0);
    delay(500);
  }
  if(sms == '2'){
    digitalWrite(red, LOW);
    Serial.println("RED LED trun off");
    myservo.write(90);
    delay(3000);
  }
  if(sms == '3'){
    digitalWrite(green, HIGH);
    Serial.println("GREEN LED trun on");
    myservo.write(180);
    delay(2000);
  }
  if(sms == '4'){
    digitalWrite(green, LOW);
    Serial.println("GREEN LED trun off");
    for(i=180; i>0; i=i-5){
    myservo.write(0);
    delay(200);
  }
  }
}
