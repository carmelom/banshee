/*
  Cori - by Giovanni Mascellani
 
 circuit: ask Francesco Guatieri
 
 Based on "toneMelody" example.
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe 

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone
 
 */

//#define DEBUG

#include "pitches.h"

// At the moment casinoMode actually controls stroboMode

int *currentDuration = NULL, *currentPitch = NULL;
boolean casinoMode = false;
int currentPos, currentLen;
double currentScale;
double currentTransport;

#include "fiumeArno.h"
#include "santannaMerda.h"
#include "whenJohnny.h"
//#include "sonPerdenti.h"
#include "gladiatore.h"
#include "laTrionfera.h"
#include "marciaImperiale.h"
#include "santanninoPuzza.h"

// To edge-trigger buttons
int buttonState[20];

int bansheeChannels[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int keypadChannels[6] = {A4, A5, A2, A3, A0, A1};  //{A0, A1, A2, A3, A4, A5};
int buttonFeedbackPin = 10;

int clacsonChannels[6] = {0, 1, 2};
int lightChannels[2] = {6, 7};

int casinoDelayMin = 100;
int casinoDelayMax = 500;
int casinoFreqMin = 100;
int casinoFreqMax = 1000;
int casinoStopProb = 0.4;

int casinoState[sizeof(clacsonChannels) / sizeof(clacsonChannels[0])];

const int STROBO_ON_TIMINGS[7] = { 0, 10, 20, 50, 100, 200, 500 };
const int STROBO_OFF_TIMINGS[7] = { 0, 10, 20, 50, 100, 200, 500 };

// --- LIGHT CONTROL ---
// Whether lights are in sync with music or not
boolean syncLights = false;
boolean syncFirst, syncSecond;

void myDelay(unsigned long ms) {
  unsigned long stopMillis = millis() + ms;
  while (millis() < stopMillis) { }
}

void setLights(int first, int second) {
  digitalWrite(bansheeChannels[lightChannels[0]], first);
  digitalWrite(bansheeChannels[lightChannels[1]], second);
}

void setStaticLights(int first, int second) {
  syncLights = false;
  casinoMode = false;
  digitalWrite(bansheeChannels[lightChannels[0]], first);
  digitalWrite(bansheeChannels[lightChannels[1]], second);
}

void setSyncLights(boolean first, boolean second) {
  syncLights = true;
  casinoMode = false;
  syncFirst = first;
  syncSecond = second;
}

static void updateSyncLights() {
  if (syncLights) {
    digitalWrite(bansheeChannels[lightChannels[0]], syncFirst ? HIGH : LOW);
    digitalWrite(bansheeChannels[lightChannels[1]], syncSecond ? HIGH : LOW);
    syncFirst = !syncFirst;
    syncSecond = !syncSecond;
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
  }
}

static void myMultitoneCasino(unsigned duration) {
  const int length = sizeof(casinoState) / sizeof(casinoState[0]);
  unsigned long us_delay[length];
  unsigned long missing[length];
  boolean pinState[length];
  for (int i = 0; i < length; i++) {
    if (casinoState[i] == 0) {
      us_delay[i] = 0;
    } else {
      us_delay[i] = 1000000 / casinoState[i] / 2;
    }
    missing[i] = us_delay[i];
    pinState[i] = true;
    digitalWrite(bansheeChannels[clacsonChannels[i]], HIGH);
  }
  long int millisStop = millis() + duration;
  while (true) {
    unsigned long wait = ((unsigned long) duration) * 1000L;
    for (int i = 0; i < length; i++) {
      if (missing[i] != 0) {
        wait = min(wait, missing[i]);
      }
    }
    delayMicroseconds(wait);
    for (int i = 0; i < length; i++) {
      if (missing[i] == wait) {
        pinState[i] = !pinState[i];
        digitalWrite(bansheeChannels[clacsonChannels[i]], pinState[i] ? HIGH : LOW);
        missing[i] = us_delay[i];
      } else if (missing[i] != 0) {
        missing[i] -= wait;
      }
    }
    if (millis() >= millisStop) {
      break;
    }
  }
  setClacsons(HIGH);
}

void stopPlayback() {
  currentDuration = NULL;
  casinoMode = false;
  setClacsons(HIGH);
  if (syncLights) {
    setLights(HIGH, HIGH);
  }
}

void setCasino() {
  currentDuration = NULL;
  casinoMode = true;
}

void stopCasino() {
  casinoMode = false;
  currentDuration = NULL;
  setStaticLights(HIGH, HIGH);
}

void melodyIteration() {
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
}

// DISABLED
void casinoIterationFalse() {
  updateSyncLights();

  // Flip randomly one casino state
  int idx = random(0, sizeof(casinoState) / sizeof(casinoState[0]));
  if (random(0, 100) < 100 * casinoStopProb) {
    casinoState[idx] = 0;
  } else {
    casinoState[idx] = random(casinoFreqMin, casinoFreqMax);
  }

  // Play casino for a random duration
  int duration = random(casinoDelayMin, casinoDelayMax);
  myMultitoneCasino(duration);
}

int stroboOn, stroboOff;
boolean stroboAlternated;

void casinoIteration() {
  int first = LOW;
  int second = stroboAlternated ? HIGH : LOW;
  setLights(first, second);
  myDelay(stroboOn);
  first = HIGH;
  second = stroboAlternated ? LOW : HIGH;
  setLights(first, second);
  myDelay(stroboOff);
}

// --- INPUT CONTROL ---
void blinkLed(int pin, int ms) {
  digitalWrite(pin, HIGH);
  delay(ms);
  digitalWrite(pin, LOW);
  delay(ms);
}

int inputState[3];
int inputPos = 0;

// Process a high-level input command
void processInput1() {
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
    if (inputState[1] == 1) {
      if (inputState[2] == 1) {
        playFiumeArno();
      } else if (inputState[2] == 2) {
        playGladiatore();
      } else if (inputState[2] == 3) {
        playLaTrionfera();
      } else if (inputState[2] == 4) {
        playMarciaImperiale();
      } else if (inputState[2] == 5) {
        playSantannaMerda();
      } else if (inputState[2] == 6) {
        playSantanninoPuzza();
      }
    } else if (inputState[1] == 2) {
      if (inputState[2] == 1) {
        //playSonPerdenti();
      } else if (inputState[2] == 2) {
        playWhenJohnny();
      }
    } else if (inputState[1] == 6) {
      if (inputState[2] == 6) {
        stopPlayback();
      }
    }
  } else if (inputState[0] == 3) {
    stroboOn = STROBO_ON_TIMINGS[inputState[1]];
    stroboOff = STROBO_OFF_TIMINGS[inputState[2]];
    setCasino();
  } else if (inputState[0] == 4) {
    if (inputState[1] == 6) {
      if (inputState[2] == 6) {
        stopCasino();
      }
    }
  }
}

int queryButton(int number) {
  int res = LOW;
  int state = digitalRead(number);
  // Invert state, because we are using INPUT_PULLUP
  state = (state == HIGH ? LOW : HIGH);
  if ((state == HIGH) && (buttonState[number] == LOW)) {
    res = HIGH;
  }
  buttonState[number] = state;
  return res;
}

// Check input buttons
void queryButtons() {
  const int length = sizeof(keypadChannels) / sizeof(keypadChannels[0]);
  int poll[length];
  for (int i = 0; i < length; i++) {
    poll[i] = queryButton(keypadChannels[i]);
  }
  for (int i = 0; i < length; i++) {
    if (poll[i] == HIGH) {
      inputState[inputPos++] = i + 1;
      blinkLed(buttonFeedbackPin, 100);
      break;
    }
  }
  if (inputPos == (sizeof(inputState) / sizeof(inputState[0]))) {
    blinkLed(buttonFeedbackPin, 200);
    processInput1();
    /*for (int i = 0; i < inputState[0]; i++) {
      blinkLed(buttonFeedbackPin, 300);
    }*/
    inputPos = 0;
  }
}

void setup() {
  for (int i = 0; i < sizeof(bansheeChannels) / sizeof(bansheeChannels[0]); i++) {
    pinMode(bansheeChannels[i], OUTPUT);
    digitalWrite(bansheeChannels[i], HIGH);
  }
  pinMode(buttonFeedbackPin, OUTPUT);
  for (int i = 0; i < sizeof(keypadChannels) / sizeof(keypadChannels[0]); i++) {
    pinMode(keypadChannels[i], INPUT_PULLUP);
  }
  
  initFiumeArno();
  initSantannaMerda();
  initWhenJohnny();
  //initSonPerdenti();
  initGladiatore();
  initLaTrionfera();
  initMarciaImperiale();
  initSantanninoPuzza();
  
  stopPlayback();
  setStaticLights(HIGH, HIGH);
  
  //playFiumeArno();
  
  /*digitalWrite(buttonFeedbackPin, HIGH);
  myDelay(100);
  digitalWrite(buttonFeedbackPin, LOW);
  myDelay(100);*/
}

void loop() {
  if (casinoMode) {
    casinoIteration();
  } else {
    melodyIteration();
  }
  
  queryButtons();
}
