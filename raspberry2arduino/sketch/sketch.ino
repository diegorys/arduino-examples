
int led = 13; //Led connected to pin 13
int data = 0;

void setup()
{
  while (!Serial) {
    ; // Wait for serial port to connect. Needed for native USB port only
  }
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0) {
    data = Serial.parseInt();
    if(data == 1){
      digitalWrite(led, HIGH);
     Serial.println("Turn on the other board");
    } else {
      digitalWrite(led, LOW);
      Serial.println("Turn off the other board");
    }    
  }
}
