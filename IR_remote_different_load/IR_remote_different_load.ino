#include<IRremote.h>

int recv_pin = 9;
IRrecv irrecv(recv_pin);
decode_results results;

int led1 = 7;
int led2 = 8;

int state1 = 1;
int state2 = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}



void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  delay(1000);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);

  if (results.value == 0xFFB04F) {
    digitalWrite(led1, state1);
    state1 = !state1;
  }

  if (results.value == 0xFF30CF) {
    digitalWrite(led2, state2);
    state2 = !state2;
  }
  
}
