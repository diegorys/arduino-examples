/****************************************/
/********** EL COCHE FANTÁSTICO *********/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

#include "Depuracion.h"
#include "ActuadorLuces.h"

/** VARIABLES **/

//Si tenemos un Arduino Mega, utilizamos los registros. Si no, el digitalWrite.
#if not (defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__))
    ActuadorLucesIndirecto luces = ActuadorLucesIndirecto();
#else
    ActuadorLucesDirecto luces = ActuadorLucesDirecto();
#endif
  
/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup(){
   Serial.begin(9600);
  luces.iniciar();
}

/**
 * Bucle infinito de ejecución.
 */
void loop(){
  delay(tiempoDelay);
  startTemporizador();
  luces.secuencia();
  stopTemporizador();
  luces.desplazar();
}
