/****************************************/
/************ EMISOR INFRARROJOS ***********/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

#include <IRLib.h>
#include <IRLibMatch.h>
#include <IRLibTimer.h>

IRsend emitter;
int count;

void setup() {
  Serial.begin(9600);
  count = 0;
}

void loop() {
  count++;
  emitter.send(NEC, 0xFF00926D, 32);
  Serial.print("SENDING DATA: ");
  Serial.println(count);
  delay(10000);
}
