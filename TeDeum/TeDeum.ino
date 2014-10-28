
#include "pitches.h"

const int threshold = 10;    // minimum reading of the sensors that generates a note

// notes to play, corresponding to the 3 sensors:

void setup() {

}

void loop() {
  
    // get a sensor reading:
    int sensorReading = digitalRead(2);

    // if the sensor is pressed hard enough:
    if (sensorReading == HIGH) {
      // play the note corresponding to this sensor:
      teDeum();
    } 
    else
    {
      digitalWrite(8,HIGH);
    }
  
}
void teDeum(){
tone(8,196,500); delay(510);
tone(8,262,500); delay(510);
tone(8,262,250); delay(255);
tone(8,294,250); delay(255);
tone(8,330,500); delay(510);
tone(8,262,500); delay(510);
tone(8,392,1000);delay(1020); 
tone(8,330,750); delay(775);
tone(8,330,250); delay(255);
tone(8,349,500); delay(510);
tone(8,392,250); delay(255);
tone(8,349,250);delay(255);
tone(8,330,250);delay(255);
tone(8,349,250);delay(255);
tone(8,392,500); delay(510);
tone(8,294,250);delay(255);
tone(8,262,250);delay(255);
tone(8,294,250);delay(255);
tone(8,330,250);delay(255);
tone(8,294,500); delay(510);

tone(8,196,500); delay(510);
tone(8,262,500); delay(510);
tone(8,262,250);delay(255);
tone(8,294,250);delay(255);
tone(8,330,500);delay(510);
tone(8,262,500);delay(510);
tone(8,392,1000);delay(1020);
tone(8,330,750);delay(775);
tone(8,330,250);delay(255);
tone(8,349,250);delay(255);
tone(8,392,250);delay(255);
tone(8,330,250);delay(255);
tone(8,349,250);delay(255);
tone(8,294,750);delay(775);
tone(8,262,250);delay(255);
tone(8,262,1000);delay(1020);
noTone(8);
}

