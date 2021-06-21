/*
 * Servomotor 180 degree
 *
 * Sample code to control a servo motor 180 degrees.
 */

#include <Servo.h>

int pin = 9;
int pos = 0;

Servo servo;

void setup() {
  Serial.begin (9600);
  servo.attach(pin);
}

void loop() {
  if (pos == 0) {
    delay(1000);
  }
  pos = (pos+1) % 180;
  servo.write(pos);
  Serial.println(pos);
}
