
int pin = 2;
int detections = 0;
int seconds = 6;
int delayTime = seconds * 1000;

void setup(){
 Serial.begin(9600); 
 pinMode(pin, INPUT);
 Serial.print("Starting...");
 int detected = digitalRead(pin);
 delay(delayTime);
 Serial.println(" OK");
}


void loop(){
  int detected = digitalRead(pin);

  if(detected == LOW){
    detections += 1;
    Serial.print("ALARMA ON: "); 
    Serial.println(detections);
    delay(delayTime);
    Serial.println("ALARMA OFF"); 
  }

}
