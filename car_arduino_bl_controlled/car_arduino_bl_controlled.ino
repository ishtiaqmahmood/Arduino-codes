char sms;


int enA = 3;
int enB = 6;
int in1 = 2;
int in2 = 4;
int in3 = 5;
int in4 = 7;

int LED = 8;

int speed = 50;

int state1 = 1;
int state2 = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
  if(Serial.available() != 0){
    sms = Serial.read();
  }
  
  digitalWrite(LED, LOW);
  digitalWrite(in1, LOW); // stop for 5 s
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 0);
  digitalWrite(enA, 0);

  if (sms == 'T'){
    // speed up
    speed++;
  }

  if (sms == 'X'){
    // speed up
    speed--;
  }

  if (sms == 'F'){
    // forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, speed);
  digitalWrite(enA, speed);
  digitalWrite(LED, HIGH);
  }
  
  if (sms == 'B'){
    // backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enA, speed);
  digitalWrite(enA, speed);
  digitalWrite(LED, HIGH);
  }

    if (sms == 'S'){
    // stop
  digitalWrite(in1, LOW); // stop for 5 s
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 0);
  digitalWrite(enA, 0);
  digitalWrite(LED, LOW);
  }

  if (sms == 'R'){
    // left
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, speed);
  digitalWrite(enA, speed);
  digitalWrite(LED, HIGH);
  }

  if (sms == 'L'){
    // right
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enA, speed);
  digitalWrite(enA, speed);
  digitalWrite(LED, HIGH);
  }
  
  //Serial.println(sms);
}
