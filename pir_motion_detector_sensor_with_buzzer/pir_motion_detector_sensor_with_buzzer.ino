int led1 = 2;
int led2 = 3;
int led3 = 4;

int pir = 6;
int buzz = 8;
int state;

void setup() {
  // put your setup code here, to run once:
  pinMode(pir, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(pir);
  digitalWrite(buzz, state);

  if(state == 1){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  
  Serial.println(state);
}
