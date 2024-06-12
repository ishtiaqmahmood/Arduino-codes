#include<IRremote.h>

int recv_pin = 9;
IRrecv irrecv(recv_pin);
decode_results results;


int enA = 3;
int enB = 6;
int in1 = 2;
int in2 = 4;
int in3 = 5;
int in4 = 7;

int LED = 8;

int state1 = 1;
int state2 = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  
  digitalWrite(LED, LOW);
  digitalWrite(in1, LOW); // stop for 5 s
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 0);
  digitalWrite(enA, 0);
  if (results.value == 0xF7906F){
    // forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, 50);
  digitalWrite(enA, 50);
  digitalWrite(LED, HIGH);
  }
  
  if (results.value == 0xF7A857){
    // backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 50);
  digitalWrite(enA, 50);
  digitalWrite(LED, HIGH);
  }

    if (results.value == 0xF7B04F){
    // stop
  digitalWrite(in1, LOW); // stop for 5 s
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 0);
  digitalWrite(enA, 0);
  digitalWrite(LED, LOW);
  }

  if (results.value == 0xF730CF){
    // left
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, 50);
  digitalWrite(enA, 50);
  digitalWrite(LED, HIGH);
  }

  if (results.value == 0xF7708F){
    // right
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 50);
  digitalWrite(enA, 50);
  digitalWrite(LED, HIGH);
  }

}
