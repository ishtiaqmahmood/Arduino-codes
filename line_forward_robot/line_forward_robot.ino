#define in1 2
#define in2 3
#define in3 4
#define in4 5
#define enA 6
#define enB 7
//#define r_sensor 11
//#define l_sensor 12



const int echo = 10;
const int trig = 11;
int led = 9;

int duration = 0;
int distance = 0;

int speed = 10;

char sms;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  //pinMode(r_sensor, INPUT);
  //pinMode(l_sensor, INPUT);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() != 0) {
    sms = Serial.read();
  }
  //Serial.println(sms);
  //Serial.print("r_sensor");
  //Serial.println(digitalRead(r_sensor));
  //Serial.print("l_sensor");
  //Serial.println(digitalRead(l_sensor));

  digitalWrite(trig, HIGH);
  delay(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 28.5;

  digitalWrite(led, LOW);

/*
if(distance >10){
    forward();
    delay(1000);
    stop();
    delay(1000);
  }

  Serial.println(distance);

  if(distance < 10){
    stop();
    backward();
    delay(200);
    right();
    delay(200);
    forward();

  }

*/
  



  if (sms == 'F') {
    forward();
  }
  if (sms == 'B') {
    backward();
  }

  if (sms == 'S') {
    stop();
  }

  if (sms == 'R') {
    right();
  }

  if (sms == 'L') {
    left();
  }

  if (sms == 'T') {
    speed = speed + 10;
  }

  if (sms == 'X') {
    speed = speed - 10;
  }

  //if ((digitalRead(r_sensor) == 1) && (digitalRead(l_sensor) == 1)) { forward(); }
  //if((digitalRead(r_sensor) == 0)&&(digitalRead(l_sensor) == 1)){right();}
  //if((digitalRead(r_sensor) == 1)&&(digitalRead(l_sensor) == 0)){left();}

  //if ((digitalRead(r_sensor) == 0) && (digitalRead(l_sensor) == 0)) {
    //stop();
   // delay(200);
   // backward();
   // delay(200);
   // right();
   // delay(200);
   // forward();
  //}
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, speed);
  digitalWrite(enB, speed);
  digitalWrite(led, HIGH);
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enA, speed);
  digitalWrite(enB, speed);
}

void left() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, speed);
  digitalWrite(enB, speed);
  delay(200);
}

void right() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, speed);
  digitalWrite(enB, speed);
  delay(200);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 0);
  digitalWrite(enB, 0);
  delay(200);
}