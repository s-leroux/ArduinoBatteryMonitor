/*
  ArduinoBatteryMonitor
  Based on Arduino example AnalogInOutSerial by Tom Igoe
 
  This example code is in the public domain.
 */

#include <stdlib.h>

// Constants
const int analogInPin  = A0;      // Analog pin the voltage divider is attached to
const float Vcc        = 5;       // µC Vcc (V)
const float R1         = 27000;   // Voltage divider R1 (Ohm)
const float R2         = 10000;   // Voltage divider R2 (Ohm)

const int pause        = 60*1000;    // delay between samples (ms)


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  int sensorValue = analogRead(analogInPin);    

  // Serial.println(sensorValue);  // for debug / calibration
  float v_pin = Vcc*sensorValue/1023.;
  float v_bat = v_pin/(R2/(R1+R2));

  // Convert to string using the format ddd.dd
  char buffer[21];
  dtostrf(v_bat, 6, 2, buffer);
  buffer[6] = 0;

  // Display result
  Serial.println(buffer);

  // wait before the next loop
  delay(pause);                     
}
