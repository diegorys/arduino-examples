#include <SoftwareSerial.h>

int led = 13; //Led connected to pin 13
int data = 0; //Serial Data
int data2 = 0; //RX TX Data

SoftwareSerial mySerial(11, 12); // RX, TX

void setup()
{
  while (!Serial) {
    ; // Wait for serial port to connect. Needed for native USB port only
  }
  Serial.begin(9600);
  mySerial.begin(4800);
  pinMode(led, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0) {
    data = Serial.parseInt();
    if(data == 1){
      mySerial.write(1);
     Serial.println("Turn on the other board");
    } else {
      mySerial.write(2);
      Serial.println("Turn off the other board");
    }    
  }

  if (mySerial.available() > 0) {
    data2 = mySerial.read();
    if (data2 == 1) {
      digitalWrite(led, HIGH);
      Serial.println("Turned on by other board");
    } else {
      digitalWrite(led, LOW);
      Serial.println("Turned off by other board");
    }
  }
}
