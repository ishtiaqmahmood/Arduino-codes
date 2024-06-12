int led = 13;

void setup() {
  pinMode(13, OUTPUT);
}

void loop(){
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
};