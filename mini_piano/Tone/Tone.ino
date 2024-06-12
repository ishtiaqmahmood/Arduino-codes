
int NOTE_C = 17; 
int NOTE_D = 74; 
int NOTE_E = 165; 
int NOTE_F = 350; 
int  NOTE_G = 784; 
int  NOTE_A = 1760;
int  NOTE_B = 1975;

int ACTIVATED = LOW;

const int PIEZO = 11;
const int LED = 13;

const int BUTTON_C = 10;
const int BUTTON_D = 9;
const int BUTTON_E = 8;
const int BUTTON_F = 7;
const int BUTTON_G = 6;
const int BUTTON_A = 5;
const int BUTTON_B = 4;



void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(PIEZO, OUTPUT);
  digitalWrite(PIEZO, LOW);
  pinMode(BUTTON_C, INPUT);
  digitalWrite(BUTTON_C,HIGH);
  pinMode(BUTTON_D, INPUT);
  digitalWrite(BUTTON_D,HIGH);
  pinMode(BUTTON_E, INPUT);
  digitalWrite(BUTTON_E,HIGH);
  pinMode(BUTTON_F, INPUT);
  digitalWrite(BUTTON_F,HIGH);
  pinMode(BUTTON_G, INPUT);
  digitalWrite(BUTTON_G,HIGH);
  pinMode(BUTTON_A, INPUT);
  digitalWrite(BUTTON_A,HIGH);
  pinMode(BUTTON_B, INPUT);
  digitalWrite(BUTTON_B,HIGH);
  
  digitalWrite(LED,LOW);
}

void loop()
{ 
  digitalWrite(PIEZO, LOW);
  if(digitalRead(BUTTON_C) == ACTIVATED)
  {
    tone(PIEZO,NOTE_C, 0);
    digitalWrite(LED,HIGH);
  }

  if(digitalRead(BUTTON_D) == ACTIVATED)
  {
    tone(PIEZO,NOTE_D, 0);
    digitalWrite(LED,HIGH);
  }
  
  if(digitalRead(BUTTON_E) == ACTIVATED)
  {
    tone(PIEZO,NOTE_E, 0);
    digitalWrite(LED,HIGH);
  }
  
  if(digitalRead(BUTTON_F) == ACTIVATED)
  {
    tone(PIEZO,NOTE_F, 0);
    digitalWrite(LED,HIGH);
  }
  
  if(digitalRead(BUTTON_G) == ACTIVATED)
  {
    tone(PIEZO,NOTE_G, 0);
    digitalWrite(LED,HIGH);
  }
  
  if(digitalRead(BUTTON_A) == ACTIVATED)
  {
    tone(PIEZO,NOTE_A, 0);
    digitalWrite(LED,HIGH);
  }
  
  if(digitalRead(BUTTON_B) == ACTIVATED)
  {
    tone(PIEZO,NOTE_B, 0);
    digitalWrite(LED,HIGH);
  }
  digitalWrite(PIEZO, LOW);
  noTone(PIEZO);
  digitalWrite(LED,LOW);

}

