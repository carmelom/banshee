/*
  Cori - by Giovanni Mascellani
 
 circuit:
 * 8-ohm speaker on digital pin 8
 
 Based on "toneMelody" example.
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe 

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone
 
 */

#include <Keypad.h>

#include "pitches.h"

int *currentDuration = NULL, *currentPitch = NULL;
int currentPos, currentLen;
double currentScale;
double currentTransport;

#include "fiumeArno.h"
#include "santannaMerda.h"
#include "whenJohnny.h"

// To detect double sampling of the same button press
int buttons[14];

int outputPin = 12;
int stopButton = 2;

// For some mysterious reason, pin 3 and 11 have strange behaviors; do not use them
int fiumeArnoButton = 3;
int santannaMerdaButton = 4;
int whenJohnnyButton = 5;

const byte rows = 6;
const byte cols = 6;
char keys[rows][cols] = {
  {0, 1, 2, 3, 4, 5},
  {6, 7, 8, 9, 10, 11},
  {12, 13, 14, 15, 16, 17},
  {18, 19, 20, 21, 22, 23},
  {24, 25, 26, 27, 28, 29},
  {30, 31, 32, 33, 34, 35}
};
byte rowPins[rows] = {6, 7, 8, 9, 10, 11};
byte colPins[cols] = {A0, A1, A2, A3, A4, A5};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

static int queryButton(int number) {
  int res = LOW;
  int state = digitalRead(number);
  if (state == HIGH && buttons[number] == LOW) {
    res = HIGH;
  }
  buttons[number] = state;
  return res;
}
  
// Check input buttons
void queryButtons() {
  if (queryButton(fiumeArnoButton) == HIGH) {
    playFiumeArno();
  }
  if (queryButton(santannaMerdaButton) == HIGH) {
    playSantannaMerda();
  }
  if (queryButton(whenJohnnyButton) == HIGH) {
    playWhenJohnny();
  }
  if (queryButton(stopButton) == HIGH) {
    stopPlayback();
  }
}

static void myTone(int pin, int pitch, unsigned long duration) {
  unsigned long us_delay = 1000000 / pitch / 2;
  unsigned long reps = duration * 1000 / (2 * us_delay);
  /*Serial.println(pin);
  Serial.println(pitch);
  Serial.println(duration);
  Serial.println(us_delay);
  Serial.println(reps);*/
  for (unsigned long i = 0; i < reps; i++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(us_delay);
    digitalWrite(pin, LOW);
    delayMicroseconds(us_delay);
    //queryButtons();
  }
}

void stopPlayback() {
  currentDuration = NULL;
}

void setup() {
  //Serial.begin(9600);
  pinMode(outputPin, OUTPUT);
  
  initFiumeArno();
  initSantannaMerda();
  initWhenJohnny();
  //playFiumeArno();
}

void loop() {
  // Check end of melody
  if (currentDuration != NULL && currentPos == currentLen) {
    stopPlayback();
  }
  
  // If there is a melody, play a note
  if (currentDuration != NULL) {
#if 0
    tone(outputPin, currentTransport * currentPitch[currentPos], currentScale * currentDuration[currentPos]);
    delay(currentScale * currentDuration[currentPos] * 1.00);
    noTone(outputPin);
#else
    myTone(outputPin, currentTransport * currentPitch[currentPos], currentScale * currentDuration[currentPos]);
#endif
    digitalWrite(outputPin, HIGH);
    // The original code of toneMelody suggests to wait some more time to make the distinction between notes hearable
    delay(currentScale * currentDuration[currentPos] * 0.30);
    currentPos++;
  }
  queryButtons();
}
