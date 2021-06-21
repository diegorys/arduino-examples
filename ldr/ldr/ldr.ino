#define pin A5

void setup() {
  Serial.begin (9600);
  pinMode(pin, INPUT);
}

void loop() {
  int light = analogRead(pin);
  Serial.println(light);
  delay(500);
}
