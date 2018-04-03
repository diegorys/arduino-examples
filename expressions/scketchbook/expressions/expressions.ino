int stcp = 12;
int shcp = 7;
int ds = 8;

int current = 0;

int p1 = 16;
int p2 = 32;
int p3 = 64;
int p4 = 128;
int p5 = 1;
int p6 = 8;
int p7 = 4;
int p8 = 2;

int HAPPY = 0;
int SAD = 0;
int SORPRISE = 0;
int SERIOUS = 0;
int TEETH = 0;

void setup() {
  pinMode(stcp, OUTPUT);
  pinMode(shcp, OUTPUT);
  pinMode(ds, OUTPUT);
  initExpressions();
}

void initExpressions() {
  SAD = p8 + p4 + p3 + p2 + p1 + p5;
  HAPPY = p1 + p4 + p5 + p6 + p7 + p8;
  SORPRISE = p2 + p3 + p6 + p7;
  SERIOUS = p1 + p2 + p3 + p4;
  TEETH = p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8;
}

void loop() {
  setExpression(HAPPY);
  delay(2000);
  setExpression(SAD);
  delay(2000);
  setExpression(SORPRISE);
  delay(2000);
  setExpression(SERIOUS);
  delay(2000);
  setExpression(TEETH);
  delay(2000);
}

void setExpression(int expression) {
  turnOff();
  turnOn(expression);
}

void turnOn(int x){   
   shiftOut(ds, shcp, MSBFIRST, x);  
   digitalWrite(stcp, HIGH);
}

void turnOff(){
  digitalWrite(stcp, LOW);
}
