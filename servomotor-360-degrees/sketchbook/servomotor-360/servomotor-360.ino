/*
 * Servomotor 360 degree
 *
 * Sample code to control a servo motor 360 degrees.
 */

#include <Servo.h>

int pin = 9;
int stop_position = 95;
int velocity = 20;

Servo servo;

void setup() {
  servo.attach(pin);
}

void loop() {
  servo.write(stop_position - velocity);
  delay(500);
  servo.write(stop_position + velocity);
  delay(500);
}
