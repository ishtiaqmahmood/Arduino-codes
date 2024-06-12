int blue = 5;
int green = 6;
int red = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(red, HIGH);
  delay(3000);

  digitalWrite(blue, HIGH);
  delay(1000);

  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);

  digitalWrite(green, HIGH);
  delay(3000);
  digitalWrite(green, LOW);
  delay(500);
  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(green, LOW);
  delay(500);

  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(green, LOW);
  delay(500);

  digitalWrite(green, HIGH);
  delay(500);

  digitalWrite(green, LOW);

}
