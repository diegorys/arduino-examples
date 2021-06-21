int pinRele = 3;
int timeDelay = 4000;

void setup() {
  pinMode(pinRele, OUTPUT);
}

void loop() {
  digitalWrite(pinRele, LOW);
  delay(timeDelay);
  digitalWrite(pinRele, HIGH);
  delay(timeDelay);
}
