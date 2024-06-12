int enA = 4;
int in1 = 2;
int in2 = 3;
int enB = 7;
int in3 = 5;
int in4 = 6;

void setup(){
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop(){
  digitalWrite(in3, HIGH); // stop for 5 s
  digitalWrite(in4, LOW);

  digitalWrite(enB, 100);
  digitalWrite(in1, HIGH); // stop for 5 s
  digitalWrite(in2, LOW);

  digitalWrite(enA, 100);
}