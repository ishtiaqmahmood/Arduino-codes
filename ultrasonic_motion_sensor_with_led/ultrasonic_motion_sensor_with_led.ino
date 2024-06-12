int blue = 5;
int green = 6;
int red = 7;
int white = 4;

int buzz = 3;

const int echo = 10;
const int trig = 11;

int duration = 0;
int distance = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delay(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2)/28.5;

  if(distance < 40){
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(white, HIGH);
    digitalWrite(buzz, LOW);
  }

  if(distance < 30){
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(white, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(buzz, LOW);
  }

  if(distance < 20){
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(white, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(buzz, LOW);
  }

  if(distance < 10){
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(white, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
  }

  Serial.println(distance);
}
