int s = 7;
int y = 10;
int x = 9;
int z = 8;
int x1;
int x2;
int x3;
int x4;
int buzzer = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(z, INPUT);
  pinMode(s, INPUT);
  pinMode(5, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  x1 = digitalRead(x);
  Serial.println(x1);
  x2 = digitalRead(y);
  Serial.println(x2);
  x3 = digitalRead(z);
  Serial.println(x3);
  x4 = digitalRead(s);
  Serial.println(x4);
  
  if(x4==0){
    digitalWrite(5, LOW);
  } else {
    digitalWrite(5, HIGH);
  }
}
