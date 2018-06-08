/****************************************/
/************ ACTUADOR LUCES ************/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

#include <Arduino.h>
#include "ActuadorLuces.h"

/** CLASE ACTUADOR LUCES **/

/**
 * Constructor.
 */
ActuadorLuces::ActuadorLuces(){
  kit = 0;
}

/**
 * Función que desplaza el valor de kit al siguiente de la secuencia.
 */
void ActuadorLuces::desplazar(){
  //Si ha llegado al límite, cambiará el sentido de giro.
  if(kit == 0 || kit == 7){
    sentido = !sentido;
  }
  //Según el sentido, incrementa o disminuye el pin.
  kit = sentido? kit+1:kit-1;
  if(DEPURAR){
    /*Serial.print("Nuevo kit: ");
    Serial.println(kit);*/
  }
}

/** FIN DE CLASE ACTUADOR LUCES **/

/** CLASE ACTUADOR LUCES DIRECTO **/

/**
 * Inicializa los pines.
 */
void ActuadorLucesDirecto::iniciar(){
  //Inicializamos los pins analógicos de A0 a A7 de la MEGA como output.
  if(DEPURAR) Serial.println("Inicia directo");
  DDRF = 0b11111111;
}

/**
 * Enciende la luz que corresponde a la posición de Kit.
 */
void ActuadorLucesDirecto::secuencia(){
  if(DEPURAR) Serial.println("Secuencia DIRECTO");

  PORTF = (1 << 7-kit) + (1 << kit);
  //PORTF = 1 << kit; //Activamos el pin correspondiente.
}

/** FIN DE CLASE ACTUADOR LUCES DIRECTO **/

/** CLASE ACTUADOR LUCES INDIRECTO **/

/**
 * Constructor
 */
ActuadorLucesIndirecto::ActuadorLucesIndirecto(){
  if(DEPURAR) Serial.println("Creo al indirecto");
  pin[0] = A0;
  pin[1] = A1;
  pin[2] = A2;
  pin[3] = A3;
  pin[4] = A4;
  pin[5] = A5;
  pin[6] = A6;
  pin[7] = A7;
}

/**
 * Inicializa los pines.
 */
void ActuadorLucesIndirecto::iniciar(){
  if(DEPURAR) Serial.println("Inicio al indirecto");
  //Inicializamos los pins analógicos de A0 a A7 de la MEGA como output.
  for(int i = 0; i <= 7; i++){
    pinMode(pin[i], OUTPUT);
  }
}

/**
 * Enciende la luz que corresponde a la posición de Kit.
 */
void ActuadorLucesIndirecto::secuencia(){
  //Activamos el pin correspondiente.
  for(int i = 0; i <= 7; i++){
    //digitalWrite(pin[i], kit == i? HIGH: LOW);
    if(kit == i || kit == 7-i){
      digitalWrite(pin[i], HIGH);
    }else{
      digitalWrite(pin[i], LOW);
    }
  }
}

/** FIN DE CLASE ACTUADOR LUCES INDIRECTO **/
