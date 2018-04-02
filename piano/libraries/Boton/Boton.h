/*
  Boton.h - Librer�a para el manejo del bot�n en Arduino.
  
  Created  2013 Apr 7
  Version 0.1
*/

// ensure this library description is only included once
#ifndef Boton_h
#define Boton_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

// Clase bot�n
class Boton {
 
	/** Elementos p�blicos de la interfaz. **/
	public:
	
		// constructors:
		Boton(int pin);
	
		int leerBoton();

	/** Elementos privados de la interfaz. **/
	private:
		//Estado previo al que se puls� para el debouncing.
		int estadoPrevio;

		//Estado candidato a cambiar.
		int estadoCandidato;

		//Tiempo que se deja para evitar el efecto bouncing.
		int debounce;

		//Tiempo desde la �ltima vez que cambi� de estado el pulsador.
		int time;

		//Pin al que est� conectado el pulsador.
		int pin;  
};

#endif
