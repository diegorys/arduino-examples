#include <math.h>

int ntc = A1;

float Vin = 5.0;     // [V]       Tensión alimentación del divisor
float Rfija = 2200;  // [ohm]     Resistencia fija del divisor
float R25 = 4700;    // [ohm]     Valor de NTC a 25ºC
float Beta = 3900.0; // [K]       Parámetro Beta de NTC
float T0 = 293.15;   // [K]       Temperatura de referencia en Kelvin
 
float Vout = 0.0;    // [V]       Variable para almacenar Vout
float Rntc = 0.0;    // [ohm]     Variable para NTC en ohmnios
 
float TempK = 0.0;   // [K]       Temperatura salida en Kelvin
float TempC = 0.0;   // [ºC]      Temperatura salida en Celsius

void setup() {                
  Serial.begin(9600);    
}

void loop() {

  //Primero la Vout del divisor
  Vout=(Vin/1024)*(analogRead(ntc));
 
  //Ahora la resistencia de la NTC
  Rntc=(Vout*Rfija)/(Vin-Vout);
 
  //Y por último la temperatura en Kelvin
  TempK = Beta/(log(Rntc/R25)+(Beta/T0));
 
  //Y ahora la pasamos a celsius
  TempC = TempK-273.15;
  
  delay(1000);
  Serial.print("Temp. ");
  Serial.print(TempC);
  Serial.println(" C");
}
