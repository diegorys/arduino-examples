/**
  How to connect a Led Matrix 8x8 to an Arduino Board.
 */

#include "LedControlMS.h"

LedControl controller = LedControl(12,11,10,1);
int N = 8;
int M = 8;

void setup() {
  controller.shutdown(0,false);
  controller.clearDisplay(0);
}

void loop() {
  sequence(true);
  sequence(false);
  delay(1000);
  controller.writeString(0,"diegorys.es");
  delay(1000);
}

void sequence(boolean status) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        controller.setLed(0, i, j, status);
        delay(100);
      }
  }
}
