/*
  suona La (A4) premendo il bottone
 
 */

#include "pitches.h"

const int threshold = 10;    // minimum reading of the sensors that generates a note

// notes to play, corresponding to the 3 sensors:
int notes[] = {
  NOTE_A4, NOTE_B4,NOTE_C3 };

void setup() {

}

void loop() {
  
    // get a sensor reading:
    int sensorReading = digitalRead(2);

    // if the sensor is pressed hard enough:
    if (sensorReading == HIGH) {
      // play the note corresponding to this sensor:
      tone(8, 500, 20);
    } 
    else
    {
      digitalWrite(8,HIGH);
    }
  
}
