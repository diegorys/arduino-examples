const int sensorPIN = A0;
const int sampleWindow = 50; // Ancho ventana en mS (50 mS = 20Hz)
 
void setup() 
{
   Serial.begin(9600);
}
 
void loop() 
{
   unsigned long startMillis= millis();
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   // Recopilar durante la ventana
   unsigned int sample;
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(sensorPIN);
      if (sample < 1024)
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // Actualizar máximo
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // Actualizar mínimo
         }
      }
   }
   unsigned int peakToPeak = signalMax - signalMin;  // Amplitud del sonido
   double volts = (peakToPeak * 5.0) / 1024;  // Convertir a tensión
   if (volts > 0.05) {
    Serial.println(volts);
   }
}
