/****************************************/
/************** DEPURACIÓN **************/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

#include <Arduino.h>
#include "Depuracion.h"

/** VARIABLES **/

//Para realizar las mediciones.
unsigned long tiempo1     = 0;
unsigned long tiempo2     = 0;
unsigned long tiempo      = 0;
unsigned char iteracion   = 0;
unsigned char iteraciones = 5;
boolean midiendo          = false;

/** FUNCIONES **/

/**
 * Función que inicaliza el temporizador.
 */
void startTemporizador(){
  if(TEMPORIZADORES && !midiendo){
    tiempo1 = millis();
  }
}

/**
 * Funcíón que detiene el temporizador.
 */
void stopTemporizador(){
  if(TEMPORIZADORES){
    if(iteracion >= iteraciones){
      midiendo = false;
      iteracion = 0;  
      tiempo2 = millis();
      tiempo = tiempo2 - tiempo1 - (tiempoDelay*iteraciones); //El tiempo de los delays no computa.
      Serial.print(tiempo);
      Serial.print(", ");
    }else{
      midiendo = true;
      iteracion++;
    }
  }
}
