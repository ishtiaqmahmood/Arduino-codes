#include <Servo.h>

Servo myservo;

int red = 7;

const int echo = 10;
const int trig = 11;

int duration = 0;
int distance = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delay(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2)/28.5;

  myservo.write(0);
  digitalWrite(red, LOW);

  if(distance <5){
    digitalWrite(red, HIGH);
    myservo.write(70);
  }

    Serial.println(distance);
}
