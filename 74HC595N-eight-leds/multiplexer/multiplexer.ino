int stcp = 12;
int shcp = 7;
int ds = 8;

int current = 0;

void setup() {
  pinMode(stcp, OUTPUT);
  pinMode(shcp, OUTPUT);
  pinMode(ds, OUTPUT);
  turnOff();
}

void loop() {
  turnOff();
  int x = 0.5 + pow(2, current);
  turnOn(x);
  current = (current+1) % 8;
  if (current == 0) {
    delay(800);
  }
  delay(200);
}

void turnOn(int x){   
   shiftOut(ds, shcp, MSBFIRST, x);  
   digitalWrite(stcp, HIGH);
}

void turnOff(){
  digitalWrite(stcp, LOW);
}
