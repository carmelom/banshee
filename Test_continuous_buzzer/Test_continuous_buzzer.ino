/*
  keyboard
 
 Plays a pitch that changes based on a changing analog input
 
 circuit:
 * 3 force-sensing resistors from +5V to analog in 0 through 5
 * 3 10K resistors from analog in 0 through 5 to ground
 * 8-ohm speaker on digital pin 8
 
 created 21 Jan 2010
 modified 9 Apr 2012
 by Tom Igoe 

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone3
 
 */

#include "pitches.h"

const int threshold = 10;    // minimum reading of the sensors that generates a note

// notes to play, corresponding to the 3 sensors:
int notes[] = {
  NOTE_A4, NOTE_B4,NOTE_C3 };
float note = 0;  

void setup() {
  Serial.begin(9600);

}
// non funziona un cazzo
void loop() {
  
    // get a sensor reading:
    int sensorReading = analogRead(A0);
   
    note = 220 + ((1760-220)*(sensorReading - 454))/(1015 - 454);
    
    Serial.print(sensorReading);
    Serial.println(note);

    // if the sensor is pressed hard enough:
    if(sensorReading > 460){
      tone(8, sensorReading, 20);
    }
    else{
      digitalWrite(8, HIGH);
    }
    
  
}
