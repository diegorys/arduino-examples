int current = 0;

void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  turnOff();
  digitalWrite(6+current, HIGH);
  current = (current+1) % 8;
  if (current == 0) {
    delay(800);
  }
  delay(200);
}

void turnOff() {
  for (int i = 6; i <= 13; i++) {
    digitalWrite(i, LOW);
  }
}

