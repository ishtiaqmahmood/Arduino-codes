int enA = 3;
int enB = 6;
int in1 = 2;
int in2 = 4;
int in3 = 5;
int in4 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(in1, HIGH); // move forward for 1.5 s
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 100);
  digitalWrite(enA, 100);
  delay(1500);

  digitalWrite(in1, LOW); // stop for 5 s
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 0);
  digitalWrite(enA, 0);
  delay(500);

  digitalWrite(in1, LOW); // move backward for 1.5 s
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, 100);
  digitalWrite(enA, 100);
  delay(1500);

  digitalWrite(in1, LOW); // stop for 5 s
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 0);
  digitalWrite(enA, 0);
  delay(500);
}
