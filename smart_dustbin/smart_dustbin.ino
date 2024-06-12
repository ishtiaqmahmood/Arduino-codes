#include <Servo.h>

Servo myservo;

const int echo = 10;
const int trig = 11;

int duration = 0;
int distance = 0;

void setup() {
  // put your setup code here, to run once:
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

  myservo.write(60);

  if(distance <50){
    myservo.write(180);
  }

    Serial.println(distance);
}
