//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc = LedControl(12, 11, 10, 1);

/* we always wait a bit between updates of the display */
unsigned long delaytime = 10;



int Cat[8] = { B10001000, B11111000, B10101000, B01110001, B00100001, B01111001, B01111101, B10111110 };
byte Apple[8] = { B00011000, B00001000, B01110110, B11111111, B11111111, B11111111, B01111010, B00110100 };

byte RA[5] = { B10000000, B01000000, B00100000, B00010000, B00001000,}; // way to address rows individually
byte SMILEFACE[5] = {B01110000, B10001000, B00000000, B01010000, B0101000};
byte SPACE[5] = {B00000000, B00000000, B00000000, B00000000, B00000000};
unsigned char A[] = {B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};
unsigned char B[] = {B01111000,B01001000,B01001000,B01110000,B01001000,B01000100,B01000100,B01111100};
unsigned char C[] = {B00000000,B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110};
unsigned char D[] = {B00000000,B00111000,B00100100,B00100010,B00100010,B00100100,B00111000,B00000000};
unsigned char E[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00111100,B00000000};
unsigned char F[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00100000,B00000000};
unsigned char G[] = {B00000000,B00111110,B00100000,B00100000,B00101110,B00100010,B00111110,B00000000};
unsigned char H[] = {B00000000,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00000000};
unsigned char I[] = {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
unsigned char J[] = {B00000000,B00011100,B00001000,B00001000,B00001000,B00101000,B00111000,B00000000};
unsigned char K[] = {B00000000,B00100100,B00101000,B00110000,B00101000,B00100100,B00100100,B00000000};
unsigned char L[] = {B00000000,B00100000,B00100000,B00100000,B00100000,B00100000,B00111100,B00000000};
unsigned char M[] = {B00000000,B00000000,B01000100,B10101010,B10010010,B10000010,B10000010,B00000000};
unsigned char N[] = {B00000000,B00100010,B00110010,B00101010,B00100110,B00100010,B00000000,B00000000};
unsigned char O[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};
unsigned char P[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100000,B00100000,B00000000};
unsigned char Q[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001};
unsigned char R[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100100,B00100100,B00000000};
unsigned char S[] = {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
unsigned char T[] = {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000};
unsigned char U[] = {B00000000,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000};
unsigned char V[] = {B00000000,B00100010,B00100010,B00100010,B00010100,B00010100,B00001000,B00000000};
unsigned char W[] = {B00000000,B10000010,B10010010,B01010100,B01010100,B00101000,B00000000,B00000000};
unsigned char X[] = {B00000000,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B00000000};
unsigned char Y[] = {B00000000,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00000000};
unsigned char Z[] = {B00000000,B00111100,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};
unsigned char Smile[]={B00000000,B01100110,B01100110,B00000000,B00000000,B01000010,B00111100,B00000000};


void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 8);
  /* and clear the display */
  lc.clearDisplay(0);
}


void loop() {
  for (int i = 0; i < 8; i++) lc.setRow(0, i, I[i]);
  delay(1000);

  for (int i = 0; i < 8; i++) lc.setRow(0, i, L[i]);
  delay(1000);

  for (int i = 0; i < 8; i++) lc.setRow(0, i, O[i]);
  delay(1000);

  for (int i = 0; i < 8; i++) lc.setRow(0, i, V[i]);
  delay(1000);

  for (int i = 0; i < 8; i++) lc.setRow(0, i, E[i]);
  delay(1000);

  for (int i = 0; i < 8; i++) lc.setRow(0, i, A[i]);
  delay(1000);

  for (int i = 0; i < 8; i++) lc.setRow(0, i, R[i]);
  delay(1000);

  for (int i = 0; i < 8; i++) lc.setRow(0, i, D[i]);
  delay(1000);

  for (int i = 0; i < 8; i++) lc.setRow(0, i, U[i]);
  delay(1000);

  for (int i = 0; i < 8; i++) lc.setRow(0, i, I[i]);
  delay(1000);


  for (int i = 0; i < 8; i++) lc.setRow(0, i, N[i]);
  delay(1000);


  for (int i = 0; i < 8; i++) lc.setRow(0, i, O[i]);
  delay(1000);


  //for (int i = 0; i < 8; i++) lc.setRow(0, i, SMILEFACE[i]);
  //delay(2000);

  for (int i = 0; i < 8; i++) lc.setRow(0, i, Smile[i]);
  delay(1000);

  lc.clearDisplay(0);
}