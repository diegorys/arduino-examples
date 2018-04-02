/*
  Boton.h - Librería para el manejo del botón en Arduino.
  
  Created  2013 Apr 7
  Version 0.1
*/

// Incluye el archivo de descripción.
#include "Boton.h"

   
/** CONSTRUCTOR **/

Boton::Boton(int pinIn)
{
  pinMode(pin, INPUT); 
  pin = pinIn;
  estadoPrevio = 0;
  debounce = 50;
  time = 0;
}

/** FUNCIONES **/

/**
 * Lee el estado de un botón teniendo en cuenta el efecto bouncing.
 */
int Boton::leerBoton(){
  if(millis() - time > debounce){
    //Si ha pasado el tiempo suficiente para evitar el efecto bouncing, leemos.
    int pulsado = digitalRead(pin);
    time = millis();
	if(pulsado == estadoCandidato){
		//Si se mantiene el estado no es un rebote.
		estadoPrevio = pulsado;
		return estadoCandidato;
	}else{
		//Si no, puede ser un rebote, esperaremos al siguiente pulso.
		estadoCandidato = pulsado;
		return estadoPrevio;
	}
  }else{
    //Si no, impedimos el cambio de estado.
    return estadoPrevio;
  }
}