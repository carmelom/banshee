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

#include "pitches.h"

int *currentDuration = NULL, *currentPitch = NULL;
boolean casinoMode = false;
int currentPos, currentLen;
double currentScale;
double currentTransport;

#include "fiumeArno.h"
#include "santannaMerda.h"
#include "whenJohnny.h"
#include "sonPerdenti.h"
#include "gladiatore.h"
#include "laTrionfera.h"
#include "marciaImperiale.h"
#include "santanninoPuzza.h"

// To edge-trigger buttons
int buttonState[20];

int bansheeChannels[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int keypadChannels[6] = {A0, A1, A2, A3, A4, A5};
int buttonFeedbackPin = 10;

int clacsonChannels[6] = {0, 1, 2, 3, 4, 5};
int lightChannels[2] = {6, 7};

// --- LIGHT CONTROL ---
// Whether lights are in sync with music or not
boolean syncLights = false;
boolean syncFirst, syncSecond;

void setStaticLights(int first, int second) {
  syncLights = false;
  digitalWrite(bansheeChannels[lightChannels[0]], first);
  digitalWrite(bansheeChannels[lightChannels[1]], second);
}

void setSyncLights(boolean first, boolean second) {
  syncLights = true;
  syncFirst = first;
  syncSecond = second;
}

static void updateSyncLights() {
  if (syncLights) {
    digitalWrite(bansheeChannels[lightChannels[0]], syncFirst ? HIGH : LOW);
    digitalWrite(bansheeChannels[lightChannels[1]], syncSecond ? HIGH : LOW);
  }
}

// --- SOUND CONTROL ---
static void setClacsons(int value) {
  for (int i = 0; i < sizeof(clacsonChannels) / sizeof(clacsonChannels[0]); i++) {
    digitalWrite(bansheeChannels[clacsonChannels[i]], value);
  }
}

static void myTone(int pitch, unsigned long duration) {
  unsigned long us_delay = 1000000 / pitch / 2;
  unsigned long reps = duration * 1000 / (2 * us_delay);
  /*Serial.println(pin);
  Serial.println(pitch);
  Serial.println(duration);
  Serial.println(us_delay);
  Serial.println(reps);*/
  for (unsigned long i = 0; i < reps; i++) {
    setClacsons(LOW);
    delayMicroseconds(us_delay);
    setClacsons(HIGH);
    delayMicroseconds(us_delay);
    //queryButtons();
  }
}

void stopPlayback() {
  currentDuration = NULL;
}

// --- INPUT CONTROL ---
void blinkLed(int pin, int ms) {
  digitalWrite(pin, HIGH);
  delay(ms);
  digitalWrite(pin, LOW);
}

static int queryButton(int number) {
  int res = LOW;
  int state = digitalRead(number);
  if (state == HIGH && buttonState[number] == LOW) {
    res = HIGH;
  }
  buttonState[number] = state;
  return res;
}

int inputState[3];
int inputPos = 0;

// Process a high-level input command
void processInput() {
  if (inputState[0] == 1) {
    if (inputState[1] == 1) {
      if (inputState[2] == 1) {
        setStaticLights(LOW, LOW);
      } else if (inputState[2] == 2) {
        setStaticLights(HIGH, HIGH);
      } else if (inputState[2] == 3) {
        setStaticLights(HIGH, LOW);
      } else if (inputState[2] == 4) {
        setStaticLights(LOW, HIGH);
      }
    } else if (inputState[1] == 2) {
      if (inputState[2] == 1) {
        setSyncLights(true, true);
      } else if (inputState[2] == 2) {
        setSyncLights(true, false);
      }
    } else if (inputState[1] == 6) {
      if (inputState[2] == 6) {
        setStaticLights(HIGH, HIGH);
      }
    }
  } else if (inputState[0] == 2) {
    
  } else if (inputState[0] == 3) {
    
  }
}

// Check input buttons
void queryButtons() {
  for (int i = 0; i < sizeof(keypadChannels) / sizeof(keypadChannels[0]); i++) {
    if (queryButton(keypadChannels[i]) == HIGH) {
      inputState[inputPos++] = i + 1;
      if (inputPos == sizeof(inputState) / sizeof(inputState[0])) {
        processInput();
        blinkLed(buttonFeedbackPin, 100);
      } else {
        blinkLed(buttonFeedbackPin, 50);
      }
    }
  }
}

void setup() {
  //Serial.begin(9600);
  for (int i = 0; i < sizeof(bansheeChannels) / sizeof(bansheeChannels[0]); i++) {
    pinMode(bansheeChannels[i], OUTPUT);
  }
  pinMode(buttonFeedbackPin, OUTPUT);
  
  initFiumeArno();
  initSantannaMerda();
  initWhenJohnny();
  initSonPerdenti();
  initGladiatore();
  initLaTrionfera();
  initMarciaImperiale();
  initSantanninoPuzza();
  
  //playFiumeArno();
}

void loop() {
  // Check end of melody
  if (currentDuration != NULL && currentPos == currentLen) {
    stopPlayback();
  }
  
  // If there is a melody, play a note
  if (currentDuration != NULL) {
    updateSyncLights();
#if 0
    tone(outputPin, currentTransport * currentPitch[currentPos], currentScale * currentDuration[currentPos]);
    delay(currentScale * currentDuration[currentPos] * 1.00);
    noTone(outputPin);
    digitalWrite(outputPin, HIGH);
#else
    myTone(currentTransport * currentPitch[currentPos], currentScale * currentDuration[currentPos]);
#endif
    // The original code of toneMelody suggests to wait some more time to make the distinction between notes hearable
    delay(currentScale * currentDuration[currentPos] * 0.30);
    currentPos++;
  }
  queryButtons();
}
